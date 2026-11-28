#!/usr/bin/env python3
"""objdiff's base object for a CodeWarrior game unit.

    tools/objdiff_base.py BASE.o TARGET.o OUT.o

CodeWarrior puts each jump table, string and constant in a .rodata (or .data,
.sdata, ...) section of its own, under a compiler-local name (@123). The
target object (build/target/) has one section per kind, as retail lays the
unit out, with splat's names (jtbl_/D_ + address). objdiff pairs data by
symbol name within a section, so none of it pairs.

OUT is BASE relinked with `ld -r`, which merges the same-named sections in
file order (as the final link lays them out), and with each @-local data
symbol renamed to the target symbol at the same section offset. The linked
object (BASE) is untouched; OUT is only for objdiff.

CodeWarrior's data relocations name the symbol (the function a jump table
entry is in, the object a pointer points at), where the target's labels in
the same file assemble to relocations against the section symbol; OUT's are
moved to the section symbol (the function's offset added
to the stored word, as the relocations are REL), so they pair.
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
LD = ROOT / "tools/cc/binutils-2.10-ee/bin/ld"
DATA = (".rodata", ".data", ".sdata", ".sbss", ".bss")


def data_syms(path: Path) -> dict:
    """(section name, offset) -> name, for the defined symbols in data sections."""
    out = {}
    with open(path, "rb") as f:
        elf = ELFFile(f)
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            ndx = sym["st_shndx"]
            if not isinstance(ndx, int) or sym["st_info"]["type"] in ("STT_SECTION", "STT_FILE"):
                continue
            sec = elf.get_section(ndx).name
            if sec in DATA and sym.name:
                out.setdefault((sec, sym["st_value"]), sym.name)
    return out


def all_syms(path: Path) -> set:
    with open(path, "rb") as f:
        return {s.name for s in ELFFile(f).get_section_by_name(".symtab").iter_symbols() if s.name}


def rename(path: Path, names: dict) -> None:
    """Rename symbols in place: a new .strtab is appended to the file."""
    data = bytearray(path.read_bytes())
    with open(path, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        strtab_idx = symtab["sh_link"]
        old = elf.get_section(strtab_idx).data()
        sh_off, sh_size = elf["e_shoff"], elf["e_shentsize"]
        sym_off, sym_size = symtab["sh_offset"], symtab["sh_entsize"]
        count = symtab.num_symbols()
    new = bytearray(old)
    for i in range(count):
        o = sym_off + i * sym_size
        st_name = struct.unpack_from("<I", data, o)[0]
        cur = old[st_name:old.index(b"\0", st_name)].decode()
        if cur in names:
            struct.pack_into("<I", data, o, len(new))
            new += names[cur].encode() + b"\0"
    # point the string table's section header at the appended copy
    hdr = sh_off + strtab_idx * sh_size
    struct.pack_into("<II", data, hdr + 16, len(data), len(new))  # sh_offset, sh_size
    data += new
    path.write_bytes(data)


def section_relative(path: Path) -> None:
    """Data relocations against a symbol the object defines -> against that
    section's symbol (the symbol's value added to the stored word): the
    target's labels in the same file assemble to section relocations."""
    data = bytearray(path.read_bytes())
    with open(path, "rb") as f:
        elf = ELFFile(f)
        syms = list(elf.get_section_by_name(".symtab").iter_symbols())
        secsym = {s["st_shndx"]: i for i, s in enumerate(syms)
                  if s["st_info"]["type"] == "STT_SECTION" and isinstance(s["st_shndx"], int)}
        for rel in elf.iter_sections():
            if rel["sh_type"] != "SHT_REL":
                continue
            target = elf.get_section(rel["sh_info"])
            if target.name not in DATA:
                continue
            for i, r in enumerate(rel.iter_relocations()):
                s = syms[r["r_info_sym"]]
                shndx = s["st_shndx"]
                if r["r_info_type"] != 2 or not isinstance(shndx, int) or shndx not in secsym \
                        or s["st_info"]["type"] == "STT_SECTION":
                    continue    # R_MIPS_32 against a defined, non-section symbol only
                o = rel["sh_offset"] + i * rel["sh_entsize"]
                struct.pack_into("<I", data, o + 4, (secsym[shndx] << 8) | 2)
                w = target["sh_offset"] + r["r_offset"]
                v = struct.unpack_from("<I", data, w)[0]
                struct.pack_into("<I", data, w, (v + s["st_value"]) & 0xFFFFFFFF)
            # CodeWarrior writes relocations in descending address order;
            # objdiff looks them up as if they were ascending
            n, es, base = rel.num_relocations(), rel["sh_entsize"], rel["sh_offset"]
            ents = sorted((bytes(data[base + i * es:base + (i + 1) * es]) for i in range(n)),
                          key=lambda e: struct.unpack_from("<I", e)[0])
            data[base:base + n * es] = b"".join(ents)
    path.write_bytes(data)


def widen(path: Path, target: Path) -> None:
    """A data symbol the target's label makes bigger than the C object (the
    label runs over the zero fill to the next object's alignment) gets the
    target's size, when what it takes in is zero and holds no other symbol."""
    sizes = {}
    with open(target, "rb") as f:
        elf = ELFFile(f)
        for s in elf.get_section_by_name(".symtab").iter_symbols():
            if isinstance(s["st_shndx"], int) and s.name and s["st_info"]["type"] not in ("STT_SECTION", "STT_FILE"):
                sec = elf.get_section(s["st_shndx"]).name
                if sec in DATA:
                    sizes[(sec, s["st_value"], s.name)] = s["st_size"]
    data = bytearray(path.read_bytes())
    with open(path, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols())
        starts = {}
        for s in syms:
            if isinstance(s["st_shndx"], int) and s.name:
                starts.setdefault(s["st_shndx"], set()).add(s["st_value"])
        for i, s in enumerate(syms):
            if not isinstance(s["st_shndx"], int) or not s.name:
                continue
            sec = elf.get_section(s["st_shndx"])
            want = sizes.get((sec.name, s["st_value"], s.name))
            have = s["st_size"]
            if not want or want <= have or s["st_value"] + want > sec["sh_size"]:
                continue
            lo, hi = s["st_value"] + have, s["st_value"] + want
            if any(lo <= a < hi for a in starts.get(s["st_shndx"], ())):
                continue
            if sec["sh_type"] != "SHT_NOBITS" and any(sec.data()[lo:hi]):
                continue
            struct.pack_into("<I", data, symtab["sh_offset"] + i * symtab["sh_entsize"] + 8, want)   # st_size
    path.write_bytes(data)


def unsplit_needed(path: Path) -> bool:
    with open(path, "rb") as f:
        return any(s.name.startswith(".text.ia") for s in ELFFile(f).iter_sections())


def unsplit(path: Path) -> None:
    """.text.iaN -> .text; .text.iastub -> a non-allocated .iastub."""
    data = bytearray(path.read_bytes())
    with open(path, "rb") as f:
        elf = ELFFile(f)
        shoff, es = elf["e_shoff"], elf["e_shentsize"]
        names = [(i, s.name) for i, s in enumerate(elf.iter_sections())]
        text_name = next((s["sh_name"] for s in elf.iter_sections() if s.name == ".text"), None)
        old = elf.get_section(elf["e_shstrndx"]).data()
        str_hdr = shoff + elf["e_shstrndx"] * es
    table = bytearray(old)
    if text_name is None:           # the unit starts with an INCLUDE_ASM'd chunk
        text_name = len(table)
        table += b".text\0"
    stub = len(table)
    table += b".iastub\0"
    for i, name in names:
        hdr = shoff + i * es
        if name == ".text.iastub":
            struct.pack_into("<I", data, hdr, stub)
            struct.pack_into("<I", data, hdr + 8, 0)        # sh_flags: not allocated, not code
        elif name.startswith(".text.ia"):
            struct.pack_into("<I", data, hdr, text_name)
    struct.pack_into("<II", data, str_hdr + 16, len(data), len(table))
    data += table
    path.write_bytes(data)


def main() -> None:
    base, target, out = map(Path, sys.argv[1:4])
    out.parent.mkdir(parents=True, exist_ok=True)
    if unsplit_needed(base):
        # an INCLUDE_ASM unit (tools/include_asm.py): its .text.iaN are .text
        # again and the marker is no code, so objdiff sees the C functions
        tmp = out.with_suffix(".unsplit.o")
        tmp.write_bytes(base.read_bytes())
        unsplit(tmp)
        base = tmp
    subprocess.run([str(LD), "-r", "-o", str(out), str(base)], check=True)
    want = data_syms(target)
    names = {}
    for key, name in data_syms(out).items():
        if name.startswith("@") and key in want:
            names[name] = want[key]
    # a merged unit's per-part alias (NAME__as_PART, tools/merge_tu.py) is
    # NAME to the target
    for name in all_syms(out):
        m = re.match(r"^(\w+?)__as_\w+$", name)
        if m:
            names[name] = m.group(1)
    if names:
        rename(out, names)
    section_relative(out)
    widen(out, target)


if __name__ == "__main__":
    main()
