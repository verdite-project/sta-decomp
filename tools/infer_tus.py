#!/usr/bin/env python3
"""Infer the game's translation units from the order of their data.

    tools/infer_tus.py [--limit 0x4000] [--hinted] [--all | --files | --hints]

mwldps2 laid out each section unit by unit in link order, so every unit's
data is one stretch, and the stretches come in .text order. Today's game
sources are one function per file. When an object used only by function A
sits before an object used only by an earlier function B (a backward step),
A and B cannot be separate units: they are one translation unit, which then
holds every function between them in .text. Overlapping ranges join.

Only objects with one user count (a shared global ties nothing), only
.data, .bss and small data (.rodata follows the .text order), and only steps
within --limit bytes of code (a longer one is link noise: commons, a
library's data; taking them all chains the game into one unit).

Each candidate is printed with its function files, the steps that tie it,
and whether it can be merged now: every file CodeWarrior C or an asm chunk
(merged as INCLUDE_ASM, include/include_asm.h), none ee-gcc (src/game/ee/).
A blocked candidate is split at its ee-gcc functions into runs, each listed
as a candidate of its own. An INCLUDE_ASM'd chunk counts as its unit's.
--all prints the blocked ones too; --hints prints call-graph hints (a
function only near units call: likely a static of their file), which are
not evidence on their own. --hinted takes ties of any distance, but only
inside a span such hints cover (a function and its only callers).
"""
import bisect
import collections
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import move_data as M     # noqa: E402

ROOT = M.ROOT
SECTIONS = {".data": (0x001EDE80, 0x001F8880), ".sdata": (0x00201B80, 0x00201E80),
            ".sbss": (0x00201E80, 0x00202480), ".bss": (0x00202480, 0x004BE180)}
GAME_TEXT = 0x00128210


def taddr(path):
    m = re.search(r"(?:func|text)_([0-9A-F]{8})", path)
    return int(m.group(1), 16) if m else None


def included():
    """asm chunk -> the C unit that INCLUDE_ASMs it (include/include_asm.h):
    the chunk is part of that unit."""
    import gen_ninja
    order = [l.strip() for l in (ROOT / "config/link_order.jp.txt").read_text().splitlines() if l.strip()]
    return {c: u for u, cs in gen_ninja.include_asm_units(order).items() for c in cs}


INCLUDED = None


def unit_of(path):
    global INCLUDED
    if INCLUDED is None:
        INCLUDED = included()
    return INCLUDED.get(path, path)


def text_units():
    """[(address, unit path)] of the game's .text units in link order (an
    INCLUDE_ASM'd chunk is its unit's)."""
    out = []
    for line in (ROOT / "config/link_order.jp.txt").read_text().splitlines():
        line = line.strip()
        if line.startswith(("src/game/", "asm/text")) and not line.startswith("src/game/data/") \
                and unit_of(line) == line:
            a = taddr(line)
            if a is None and line.startswith("asm/") and out:
                a = out[-1][0] + 1      # an asm chunk named by no address: right after
            if a is not None and a >= GAME_TEXT:
                out.append((a, line))
    return sorted(out)


RODATA = (0x001F8880, 0x00201B80)
ROM = ROOT / "baserom/jp/sta.rom"
BASE = 0x00100000


def literal(blob):
    """The bytes of an object CodeWarrior pools per unit: a C string (zero
    filled to its size) or a float or double constant."""
    if len(blob) in (4, 8) and any(blob):
        import math
        import struct
        w = struct.unpack_from("<I", blob)[0]
        if 0x00100000 <= w < 0x004C0000:
            return False                # a pointer: a named table
        f = struct.unpack("<f" if len(blob) == 4 else "<d", blob)[0]
        return math.isfinite(f) and (f == 0 or 1e-6 < abs(f) < 1e7)
    text = blob.rstrip(b"\0")
    if not text or len(blob) - len(text) < 1:
        return False
    # ASCII and Shift-JIS text (control bytes but tab and newline excluded)
    return all(b >= 0x20 or b in (9, 10, 13) for b in text)


def rodata_ties(sz, alias, limit):
    """A string or float constant in .rodata used by several units: the
    compiler pools them per unit and the linker never merges units', so its
    users are one unit. As steps (lo, hi, ".rodata", object, users)."""
    rom = ROM.read_bytes()
    names = [n for n, (a, s) in sz.items() if re.match(r"(?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8}$", n) and RODATA[0] <= a < RODATA[1] and s]
    us = with_definers(M.users(set(names), alias))
    out = []
    for n in names:
        units = {unit_of(u) for u in us[n]}
        ts = sorted(t for t in (taddr(u) for u in units) if t is not None and t >= GAME_TEXT)
        if len(units) < 2 or len(ts) != len(units) or ts[-1] - ts[0] > limit:
            continue
        a, size = sz[n]
        if not literal(rom[a - BASE:a - BASE + size]):
            continue
        out.append((ts[0], ts[-1], ".rodata", n, "shared by " + ", ".join(sorted(Path(u).stem for u in units))))
    return out


def hinted_spans(limit):
    """[(lo, hi)] text address spans each covering a call-graph hint (a
    function and the near units that alone call it), overlapping ones
    joined."""
    sp = []
    for fn, u, callers in hints(limit):
        ts = [taddr(x) for x in [u] + callers]
        sp.append((min(ts), max(ts)))
    sp.sort()
    out = []
    for lo, hi in sp:
        if out and lo <= out[-1][1]:
            out[-1][1] = max(out[-1][1], hi)
        else:
            out.append([lo, hi])
    return out


def with_definers(us):
    """users() counts references only; an object a code unit defines (a
    merged unit's own data) is that unit's too."""
    from elftools.elf.elffile import ELFFile
    import glob
    for o in glob.glob(str(ROOT / "build/src/game/*.c.o")):
        src = str(Path(o).relative_to(ROOT / "build"))[:-2]
        if not (ROOT / src).exists():
            continue
        with open(o, "rb") as f:
            for sy in ELFFile(f).get_section_by_name(".symtab").iter_symbols():
                if sy.name in us and isinstance(sy["st_shndx"], int) and sy["st_info"]["bind"] == "STB_GLOBAL":
                    us[sy.name].add(src)
    return us


def candidates(limit, spans=None):
    """Candidates from ties within `limit`; with `spans` (hinted_spans()),
    ties of any distance that lie inside one span."""
    if spans is not None:
        within = lambda lo, hi: any(a <= lo and hi <= b for a, b in spans)
        limit_ = 1 << 30
    else:
        within, limit_ = (lambda lo, hi: True), limit
    limit = limit_
    sz = M.sizes()
    alias = M.aliases()
    names = [n for n, (a, s) in sz.items() if re.match(r"(?:D|jtbl|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8}$", n)
             and any(lo <= a < hi for lo, hi in SECTIONS.values())]
    us = with_definers(M.users(set(names), alias))
    units = text_units()
    starts = [a for a, _ in units]
    steps = []      # (lo, hi, section, object before, object after)
    for sec, (lo, hi) in SECTIONS.items():
        seq = []
        for a, n in sorted((sz[n][0], n) for n in names if lo <= sz[n][0] < hi):
            if len(us[n]) == 1:
                t = taddr(unit_of(next(iter(us[n]))))
                if t is not None and t >= GAME_TEXT:
                    seq.append((t, n))
        for (x, nx), (y, ny) in zip(seq, seq[1:]):
            if y < x and x - y <= limit:
                steps.append((y, x, sec, nx, ny))
    steps += rodata_ties(sz, alias, limit)
    steps = [st for st in steps if within(st[0], st[1])]
    steps.sort()
    merged = []
    for lo, hi, *ev in steps:
        if merged and lo <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], hi)
            merged[-1][2].append(ev)
        else:
            merged.append([lo, hi, [ev]])
    out = []
    for lo, hi, ev in merged:
        if spans is not None and len(ev) < 2:
            continue    # one long tie is no evidence: they chain across ee-gcc modules
        i, j = bisect.bisect_left(starts, lo), bisect.bisect_right(starts, hi)
        files = [u for _, u in units[i:j]]
        out.append((files, ev))
    return out


def hints(limit):
    """Call-graph hints: a function every caller of which is a unit within
    `limit` bytes of code (and not itself) was likely a static of their
    file. Only reported: CodeWarrior does not make a function static on its
    own, and a global with near callers is common, so this is no proof."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    units = text_units()
    defined, calls = {}, collections.defaultdict(set)   # function -> unit; function -> calling units
    for _, u in units:
        o = ROOT / "build" / (u + ".o")
        if not o.exists():
            continue
        with open(o, "rb") as f:
            e = ELFFile(f)
            syms = list(e.get_section_by_name(".symtab").iter_symbols())
            for sy in syms:
                if sy["st_info"]["type"] == "STT_FUNC" and isinstance(sy["st_shndx"], int):
                    defined[sy.name] = u
            for sec in e.iter_sections():
                if isinstance(sec, RelocationSection) and e.get_section(sec["sh_info"]).name.startswith(".text"):
                    for r in sec.iter_relocations():
                        if r["r_info_type"] == 4:       # R_MIPS_26: jal
                            calls[syms[r["r_info_sym"]].name].add(u)
    out = []
    for fn, u in sorted(defined.items(), key=lambda x: taddr(x[1]) or 0):
        callers = {unit_of(c) for c in calls.get(fn, ())} - {u}
        t = taddr(u)
        if not callers or t is None or t < GAME_TEXT:
            continue
        ts = [taddr(c) for c in callers]
        if all(x is not None and abs(x - t) <= limit for x in ts):
            out.append((fn, u, sorted(callers)))
    return out


def blocked(f):
    """An ee-gcc function cannot share a CodeWarrior unit; an asm chunk can
    (INCLUDE_ASM, include/include_asm.h)."""
    return f.startswith("src/game/ee/") or not f.endswith((".c", ".s"))


def main():
    limit = int(sys.argv[sys.argv.index("--limit") + 1], 0) if "--limit" in sys.argv else 0x4000
    show_all = "--all" in sys.argv
    if "--hints" in sys.argv:
        for fn, u, callers in hints(limit):
            print(f"{fn} ({Path(u).stem}): called only from {', '.join(Path(c).stem for c in callers)}")
        return
    ready, waiting = [], []
    spans = hinted_spans(limit) if "--hinted" in sys.argv else None
    for files, ev in candidates(limit, spans):
        if not any(blocked(f) for f in files):
            ready.append((files, ev, None))
            continue
        waiting.append((files, ev))
        run = []
        for f in files + [None]:
            if f is None or blocked(f):
                if len(run) > 1:
                    ready.append((run, ev, files))
                run = []
            else:
                run.append(f)
    ready.sort(key=lambda r: len(r[0]))
    if "--files" in sys.argv:
        for files, ev, parent in ready:
            print(" ".join(files))
        return
    for files, ev, parent in ready:
        tag = f"  (C run of a unit with {sum(blocked(f) for f in parent)} asm/ee function(s))" if parent else ""
        print(f"{Path(files[0]).stem}..{Path(files[-1]).stem}: {len(files)} files{tag}")
        for sec, a, b in ev[:4]:
            print(f"    {sec}: {a} {b}" if sec == ".rodata" else f"    {sec}: {a} before {b}")
    print(f"{len(ready)} mergeable candidates, {sum(len(r[0]) for r in ready)} files;"
          f" {len(waiting)} units wait on asm/ee functions", file=sys.stderr)
    if show_all:
        for files, ev in waiting:
            bl = [Path(f).name for f in files if blocked(f)]
            print(f"WAIT {Path(files[0]).stem}..{Path(files[-1]).stem}: {len(files)} files, on {', '.join(bl)}")


if __name__ == "__main__":
    main()
