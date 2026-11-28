#!/usr/bin/env python3
"""Check that every NONMATCHING data twin matches its data unit's definition.

    tools/check_data_twins.py [--stamp OUT]

tools/split_data.py gives an owner unit a twin, under #ifdef NONMATCHING,
of an object a data-only unit (src/game/data/) defines for the matching
build under #ifndef NONMATCHING. This compares the two compiled objects:
the owner as the NONMATCHING build compiles it and the data unit as the
matching build does, from build/twins/ (tools/gen_ninja.py builds the side
the current build does not). For each twin: the same section kind
(initialised or not), the same size, the same bytes, and relocations
against the same symbols at the same offsets (bytes under a relocation are
compared only when it is against a named symbol; a section-relative one
must point into the same named object). A twin with no definition on
either side, or a #ifndef block whose names no owner twins, fails.

--stamp touches OUT when everything matches (the ninja rule's output).
"""
import collections
import glob
import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parent.parent
TWINS = re.compile(r"/\* data twins \(([\w/.]+)\): ([\w, ]+) \*/")
UNIT_BLOCK = re.compile(r"^#ifndef NONMATCHING /\* the NONMATCHING build defines these in ([\w/.]+) \*/\n(.*?)^#endif",
                        re.M | re.S)
INIT = {".data", ".rodata", ".sdata"}


def twins():
    """[(owner, unit, name)] from the owners' `/* data twins */` lines."""
    out = []
    for p in sorted(glob.glob(str(ROOT / "src/game/**/*.c"), recursive=True)):
        if "/src/game/data/" in p:
            continue
        for m in TWINS.finditer(Path(p).read_text()):
            for n in m.group(2).split(","):
                out.append((str(Path(p).relative_to(ROOT)), m.group(1), n.strip()))
    return out


def unit_blocks():
    """{(unit, owner): set of names} the data units put under #ifndef."""
    out = collections.defaultdict(set)
    for p in sorted(glob.glob(str(ROOT / "src/game/data/*.c"))):
        t = Path(p).read_text()
        for m in UNIT_BLOCK.finditer(t):
            for line in m.group(2).splitlines():
                d = re.search(r"\b(\w+)\s*(?:\[[^\]]*\])*\s*(?:__attribute__\(\(\w+(?:\([^()]*\))?\)\)\s*)?(?:=|;)", line)
                if d:
                    out[(str(Path(p).relative_to(ROOT)), m.group(1))].add(d.group(1))
    return out


class Obj:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.e = ELFFile(self.f)
        self.secs = list(self.e.iter_sections())
        self.syms = list(self.e.get_section_by_name(".symtab").iter_symbols())
        self.byname = {s.name: s for s in self.syms if s.name and s["st_shndx"] != "SHN_UNDEF"}
        self.rels = collections.defaultdict(list)       # section index -> [(offset, type, sym)]
        for s in self.secs:
            if isinstance(s, RelocationSection):
                for r in s.iter_relocations():
                    self.rels[s["sh_info"]].append((r["r_offset"], r["r_info_type"], self.syms[r["r_info_sym"]],
                                                    r.entry.get("r_addend")))

    def blob(self, name):
        """(kind, size, bytes, [(offset, type, target)]) of a defined object, or None."""
        s = self.byname.get(name)
        if s is None:
            return None
        size = s["st_size"]
        if s["st_shndx"] == "SHN_COMMON":
            return ("bss", size, b"", [])
        sec = self.secs[s["st_shndx"]]
        kind = "init" if sec.name in INIT else "bss"
        if kind == "bss":
            return (kind, size, b"", [])
        data = bytearray(sec.data()[s["st_value"]:s["st_value"] + size])
        rels = []
        for off, typ, tsym, add in self.rels[s["st_shndx"]]:
            o = off - s["st_value"]
            if not 0 <= o < size:
                continue
            if tsym["st_info"]["type"] == "STT_SECTION" or not tsym.name:
                # section-relative: name the object it points into
                a = (add if add is not None else struct.unpack_from("<I", data, o)[0])
                target = self.object_at(tsym["st_shndx"], a)
                if add is None:
                    data[o:o + 4] = b"\0\0\0\0"
            else:
                target = (tsym.name, 0)
                if add is None:
                    target = (tsym.name, struct.unpack_from("<i", data, o)[0])
                    data[o:o + 4] = b"\0\0\0\0"
            rels.append((o, typ, target))
        return (kind, size, bytes(data), sorted(rels, key=lambda r: r[0]))

    def object_at(self, shndx, addr):
        best = None
        for s in self.syms:
            if s["st_shndx"] == shndx and s.name and s["st_info"]["type"] in ("STT_OBJECT", "STT_NOTYPE", "STT_FUNC") \
                    and s["st_value"] <= addr < s["st_value"] + max(s["st_size"], 1):
                best = (s.name, addr - s["st_value"])
        if best is None:
            # past every symbol's end (a jump table into a function the C made
            # shorter): the nearest symbol before it
            cands = [s for s in self.syms if s["st_shndx"] == shndx and s.name and "." not in s.name
                     and s["st_value"] <= addr
                     and s["st_info"]["type"] in ("STT_OBJECT", "STT_NOTYPE", "STT_FUNC")]
            if cands:
                s = max(cands, key=lambda s: (s["st_value"], s["st_info"]["type"] == "STT_FUNC",
                                              not s.name.startswith("__gnu")))
                best = (s.name, addr - s["st_value"])
        return best or (f"?{shndx}", addr)


def side(src, nonmatching):
    """The object of src as the given build compiles it: the current build's
    if that is the build (build.ninja's NONMATCHING line), else build/twins/'s."""
    ninja = (ROOT / "build.ninja").read_text() if (ROOT / "build.ninja").exists() else ""
    current_nm = "# NONMATCHING: on" in ninja
    if current_nm == nonmatching:
        return ROOT / "build" / (src + ".o")
    return ROOT / "build/twins" / (src + ".o")


def compare(a, b):
    """'' if two blobs agree, else what differs."""
    if a is None or b is None:
        return "not defined" + (" in the owner" if a is None else " in the data unit")
    if a[0] != b[0]:
        # zeros are zeros, initialised or not
        z = lambda x: x[0] == "bss" or (not any(x[2]) and not x[3])
        if not (z(a) and z(b) and a[1] == b[1]):
            return f"section {a[0]} vs {b[0]}"
        return ""
    if a[1] < b[1] and (b[0] == "bss" or (not any(b[2][a[1]:]) and all(o < a[1] for o, _, _ in b[3]))):
        # the twin has the owner's type; the data unit's object also held
        # the zero padding up to the next label (tools/split_data.py makes
        # sure no code reaches into it)
        b = (b[0], a[1], b[2][:a[1]], b[3])
    if a[1] != b[1]:
        return f"size {a[1]:#x} vs {b[1]:#x}"
    if a[2] != b[2]:
        i = next(i for i in range(len(a[2])) if a[2][i] != b[2][i])
        return f"bytes differ at +{i:#x}"
    if [(o, t) for o, t, _ in a[3]] != [(o, t) for o, t, _ in b[3]]:
        return "relocation offsets differ"
    for (o, _, x), (_, _, y) in zip(a[3], b[3]):
        if x != y:
            return f"+{o:#x} points at {x[0]}+{x[1]:#x} vs {y[0]}+{y[1]:#x}"
    return ""


GROUP = re.compile(r"/\* data group \(([\w/.]+)\): (\w+): ([\w@, ]+) \*/")


def groups():
    """[(owner, unit, blob, [(name, offset)])] from the owners' `data group` lines."""
    out = []
    for p in sorted(glob.glob(str(ROOT / "src/game/**/*.c"), recursive=True)):
        if "/src/game/data/" in p:
            continue
        for m in GROUP.finditer(Path(p).read_text()):
            ms = [(x.strip().split("@")[0], int(x.strip().split("@")[1], 0)) for x in m.group(3).split(",")]
            out.append((str(Path(p).relative_to(ROOT)), m.group(1), m.group(2), ms))
    return out


def check():
    bad = []
    tw = twins()
    gs = groups()
    pairs = collections.defaultdict(set)
    for owner, unit, n in tw:
        pairs[(unit, owner)].add(n)
    for owner, unit, blob, ms in gs:
        pairs[(unit, owner)] |= {n for n, _ in ms}
    blocks = unit_blocks()
    for key in set(blocks) | set(pairs):
        if blocks.get(key, set()) != pairs.get(key, set()):
            extra = blocks.get(key, set()) ^ pairs.get(key, set())
            bad.append(f"{key[0]} / {key[1]}: unpaired {', '.join(sorted(extra))}")
    objs = {}
    get = lambda p: objs.setdefault(p, Obj(p))
    for owner, unit, n in tw:
        try:
            a, b = get(side(owner, True)).blob(n), get(side(unit, False)).blob(n)
        except FileNotFoundError as e:
            bad.append(f"{n}: {e.filename} missing")
            continue
        why = compare(a, b)
        if why:
            bad.append(f"{n} ({owner} vs {unit}): {why}")
    # a group's members: their slices of the blob
    for owner, unit, blob, ms in gs:
        try:
            ob, uo = get(side(owner, True)), get(side(unit, False))
        except FileNotFoundError as e:
            bad.append(f"{blob}: {e.filename} missing")
            continue
        b = ob.blob(blob)
        if b is None:
            bad.append(f"{blob} ({owner}): not defined")
            continue
        for n, off in ms:
            u = uo.blob(n)
            if u is None:
                bad.append(f"{n} ({unit}): not defined in the data unit")
                continue
            size = u[1]
            rels = [(x - off, t, tg) for x, t, tg in b[3] if off <= x < off + size]
            part = (b[0], size, b[2][off:off + size] if b[0] != "bss" else b"", rels)
            why = compare(part, u)
            if why:
                bad.append(f"{n} (group {blob} in {owner} vs {unit}): {why}")
        tw = tw + [(owner, unit, n) for n, _ in ms]
    return tw, bad


def main():
    tw, bad = check()
    for b in bad:
        print(f"check_data_twins: {b}", file=sys.stderr)
    if bad:
        sys.exit(1)
    if "--stamp" in sys.argv:
        out = ROOT / sys.argv[sys.argv.index("--stamp") + 1]
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(f"{len(tw)} twins\n")
    print(f"check_data_twins: {len(tw)} twins match")


if __name__ == "__main__":
    main()
