#!/usr/bin/env python3
"""Per-function matching workflow.

    tools/match.py asm ADDR            the retail asm of the function at ADDR
                                       (paste into decomp.me or m2c)
    tools/match.py diff FILE.c [-k]    compile FILE.c with the game's compiler and
                                       diff every func_XXXXXXXX it defines against
                                       the retail bytes at XXXXXXXX

The compiler follows the address, as tools/compile_c.sh does by path: a function
inside one of the three ee-gcc modules (0x1D3A90-0x1D7EC0, 0x1DC328-0x1DC900,
0x1E1E08-0x1E5E80) is
compiled with ee-gcc 2.96 -O2 -G 8 -fno-strict-aliasing, anything else with
mwccps2 3.0b52 -O4,p. MWCC and GAME_CFLAGS override CodeWarrior as for
compile_c.sh. Words that carry a relocation are compared on their opcode bits
only. -k keeps going after the first difference of each function.
"""
import os
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

import rabbitizer
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
sys.path.insert(0, str(Path(__file__).resolve().parent))
from names import func_name  # noqa: E402


ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "baserom/jp/sta.rom"
BASE = 0x00100000
EE = [(0x001D3A90, 0x001D7EC0), (0x001DC328, 0x001DC900), (0x001E1E08, 0x001E5E80)]
MASK = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000}
GP = 0x00209B70
TEXT_END = 0x001EDE80                         # .text end (config/sta.jp.yaml)


def is_jump(w: int) -> bool:
    """jr/jalr, j/jal, or a branch: an instruction with a delay slot."""
    op = w >> 26
    if op == 0:
        return (w & 0x3F) in (0x08, 0x09)
    if op == 1:
        return ((w >> 16) & 0x1F) in (0x00, 0x01, 0x02, 0x03, 0x10, 0x11, 0x12, 0x13)
    if op == 0x11 or op == 0x12:                  # bc1x / bc2x
        return ((w >> 21) & 0x1F) == 0x08
    return op in (0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17)


def code_end(data: bytes, base: int, a: int, b: int) -> int:
    """b less the zero fill after the function, keeping a nop that sits in
    the delay slot of its last jump."""
    while b > a and struct.unpack_from("<I", data, b - 4 - base)[0] == 0:
        if b - 8 >= a and is_jump(struct.unpack_from("<I", data, b - 8 - base)[0]):
            break
        b -= 4
    return b


def dis(w: int, vram: int) -> str:
    return rabbitizer.Instruction(w, vram=vram, category=rabbitizer.InstrCategory.R5900).disassemble()


def func_bounds(addr: int) -> tuple[int, int]:
    """From splat's asm: the function starting at addr and where the next starts."""
    starts = []
    for f in (ROOT / "asm").rglob("*.s"):
        starts += [int(a, 16) for a in re.findall(
            r"^glabel \S+\n(?:nonmatching.*\n|\s*\n)*\s*/\* [0-9A-F]+ ([0-9A-F]{8})", f.read_text(), re.M)]
    starts = sorted(set(starts))
    if addr not in starts:
        sys.exit(f"{addr:#x} is not the start of a function splat found")
    nxt = next((s for s in starts if s > addr), TEXT_END)
    return addr, nxt


def cmd_asm(addr: int) -> None:
    rom = ROM.read_bytes()
    a, b = func_bounds(addr)
    b = code_end(rom, BASE, a, b)
    print(f"glabel func_{a:08X}")
    for k in range(a, b, 4):
        w = struct.unpack_from("<I", rom, k - BASE)[0]
        print(f"    /* {k:08X} {w:08X} */  {dis(w, k)}")


def unit_cflags(src: Path) -> str:
    """CodeWarrior flags for a game unit: config/game_cflags.txt, else -O4,p."""
    rel = str(src.resolve().relative_to(ROOT)) if src.resolve().is_relative_to(ROOT) else str(src)
    for line in (ROOT / "config/game_cflags.txt").read_text().splitlines():
        path, _, flags = line.partition(" ")
        if path == rel and not path.startswith("#"):
            return flags.strip()
    return "-O4,p"


def compile_c(src: Path, ee: bool, out: Path) -> None:
    cc = ROOT / "tools/cc"
    incs = [f"-I{ROOT / 'include'}", f"-I{ROOT / 'src/game'}"]
    if ee:
        d = cc / "ee-gcc2.96"
        s = out.with_suffix(".s")
        run([str(ROOT / "tools/period_env.sh"), str(d / "bin/gcc"), "-B", f"{d}/gcc-lib/ee/2.96-ee-001003-1/",
             "-S", "-O2", "-G", "8", "-fno-strict-aliasing", "-mips3", "-EL", "-nostdinc", *incs,
             "-o", str(s), str(src)])
        run([str(ROOT / "tools/period_env.sh"), str(d / "bin/as"), "-EL", "-mcpu=5900", "-mabi=eabi",
             "-G", "8", "-o", str(out), str(s)])
    else:
        unit = unit_cflags(src).split()
        build = next((f[5:] for f in unit if f.startswith("mwcc=")), "mwcps2-3.0b52-030722")
        mw = cc / os.environ.get("MWCC", build) / "mwccps2.exe"
        flags = [f for f in unit if not f.startswith("mwcc=")]
        flags = os.environ["GAME_CFLAGS"].split() if "GAME_CFLAGS" in os.environ else flags
        run([str(cc / "wibo"), str(mw), "-c", "-nostdinc", *flags, *incs, "-o", str(out), str(src)],
            env={**os.environ, "MWCIncludes": str(ROOT / "include")})


def run(cmd, env=None):
    r = subprocess.run(cmd, capture_output=True, text=True, env=env)
    if r.returncode:
        sys.stderr.write(r.stdout + r.stderr)
        sys.exit(f"compile failed: {' '.join(cmd[:2])}")


def sext16(v: int) -> int:
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def check_relocs(rels, data: bytes, off: int, size: int, rom: bytes, ra: int) -> int:
    """Masked words hide the addends: check that every relocation of a symbol
    implies the same address for it in retail (a %lo pairs with the latest %hi
    loaded into its base register), and that a name made from an address
    (D_XXXXXXXX, func_XXXXXXXX) implies that address. Returns the number of
    symbols that disagree, and prints them."""
    implied = {}
    hi = {}
    for o, typ, name in sorted(r for r in rels if off <= r[0] < off + size):
        ow = struct.unpack_from("<I", data, o)[0]
        rw = struct.unpack_from("<I", rom, ra + (o - off) - BASE)[0]
        if typ == 4:        # R_MIPS_26
            a = (((rw & 0x3FFFFFF) - (ow & 0x3FFFFFF)) << 2) | ((ra + o - off) & 0xF0000000)
        elif typ == 5:      # R_MIPS_HI16
            hi[(name, (ow >> 16) & 31)] = (ow, rw)
            continue
        elif typ == 6:      # R_MIPS_LO16
            pair = hi.get((name, (ow >> 21) & 31))
            if pair is None:
                continue
            how, hrw = pair
            a = ((hrw & 0xFFFF) << 16) + sext16(rw) - (((how & 0xFFFF) << 16) + sext16(ow))
        elif typ == 7:      # R_MIPS_GPREL16
            a = GP + sext16(rw) - sext16(ow)
        else:
            continue
        implied.setdefault(name, set()).add(a & 0xFFFFFFFF)
    bad = 0
    for name, addrs in sorted(implied.items()):
        m = re.fullmatch(r"(?:D|func|g[A-Z][A-Za-z0-9]*)_([0-9A-F]{8})", name)
        if len(addrs) > 1 or (m and int(m.group(1), 16) not in addrs):
            want = f", the name says {int(m.group(1), 16):#x}" if m else ""
            print(f"  relocations disagree: {name} at {', '.join(hex(x) for x in sorted(addrs))}{want}")
            bad += 1
    return bad


def cmd_diff(src: Path, keep: bool) -> int:
    text = src.read_text()
    # a definition starts in column 0 and is not a prototype (ending in ");")
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    addrs = sorted({int(m.group(1), 16) for l in text.splitlines()
                    if re.match(r"[A-Za-z]", l) and not l.rstrip().endswith(");")
                    for m in [re.search(r"\b(?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8})\s*\(", l)] if m})
    if not addrs:
        sys.exit(f"{src}: defines no func_XXXXXXXX")
    ee = any(lo <= addrs[0] < hi for lo, hi in EE)
    rom = ROM.read_bytes()
    bad_total = 0
    with tempfile.TemporaryDirectory() as tmp:
        obj = Path(tmp) / "out.o"
        compile_c(src, ee, obj)
        e = ELFFile(open(obj, "rb"))
        secs = list(e.iter_sections())
        masks = {}
        relocs = {}     # text section index -> [(offset, type, symbol name)]
        symlist = list(e.get_section_by_name(".symtab").iter_symbols())
        for s in secs:
            if isinstance(s, RelocationSection):
                for r in s.iter_relocations():
                    masks[(s["sh_info"], r["r_offset"] & ~3)] = MASK.get(r["r_info_type"], 0)
                    relocs.setdefault(s["sh_info"], []).append(
                        (r["r_offset"], r["r_info_type"], symlist[r["r_info_sym"]].name))
        syms = {s.name: s for s in e.get_section_by_name(".symtab").iter_symbols()
                if s["st_info"]["type"] == "STT_FUNC"}
        for a in addrs:
            name = func_name(a)
            sym = syms.get(name)
            if sym is None:
                print(f"{name}: not in the object (inlined or static?)")
                bad_total += 1
                continue
            si = sym["st_shndx"]
            data = secs[si].data()
            off, size = sym["st_value"], sym["st_size"] or len(secs[si].data()) - sym["st_value"]
            ra, rb = func_bounds(a)
            rb = code_end(rom, BASE, ra, rb)
            n_obj, n_rom = size // 4, (rb - ra) // 4
            rows, bad = [], 0
            for k in range(max(n_obj, n_rom)):
                w = struct.unpack_from("<I", data, off + 4 * k)[0] if k < n_obj else None
                rw = struct.unpack_from("<I", rom, ra + 4 * k - BASE)[0] if k < n_rom else None
                m = masks.get((si, off + 4 * k), 0xFFFFFFFF)
                same = w is not None and rw is not None and (w ^ rw) & m == 0
                bad += not same
                rows.append((same, w, rw, ra + 4 * k))
            if n_obj == n_rom:
                bad += check_relocs(relocs.get(si, []), data, off, size, rom, ra)
            status = "MATCH" if bad == 0 else f"{bad} of {max(n_obj, n_rom)} words differ"
            print(f"{name} ({'ee-gcc 2.96' if ee else 'mwccps2'}): {status}"
                  + ("" if n_obj == n_rom else f" (built {n_obj} words, retail {n_rom})"))
            if bad:
                shown = 0
                for same, w, rw, vram in rows:
                    l = dis(w, vram) if w is not None else ""
                    r = dis(rw, vram) if rw is not None else ""
                    print(f"  {'  ' if same else '>>'} {l:44s} {r}")
                    shown += not same
                    if not keep and shown and not same and shown > 12:
                        print("  ...")
                        break
            bad_total += bad
    return 1 if bad_total else 0


def main() -> None:
    if len(sys.argv) >= 3 and sys.argv[1] == "asm":
        cmd_asm(int(sys.argv[2], 16))
    elif len(sys.argv) >= 3 and sys.argv[1] == "diff":
        sys.exit(cmd_diff(Path(sys.argv[2]), "-k" in sys.argv))
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
