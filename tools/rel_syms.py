#!/usr/bin/env python3
"""The symbols ld gets from config/, written relative to what they lie in.

    tools/rel_syms.py OUT OBJ...

splat lists the addresses the asm refers to that no unit defines a symbol
at (config/undefined_syms_auto.txt, undefined_funcs_auto.txt): mostly
interior addresses, a byte of a string or a field of an array. Given to ld
as `NAME = 0xADDR;` they pin that data to its retail address. This writes
each in-image one as `NAME = OWNER + 0xOFF;`, OWNER being the global the
address lies in, so it moves with OWNER when the image shifts. The same goes
for the hand-written config/linker_syms.txt and config/data_aliases.txt
(already relative). Addresses outside the image (hardware, scratchpad, the
stack) stay absolute.

A name NAME__as_PART (a merged unit's part that declared NAME its own way,
tools/merge_tu.py) is written as NAME.

Owners: the sized globals tools/carve.py lists (config/symbol_addrs.carve.txt)
and the labels of splat's asm (asm/**/*.s, a label running to the next one).
Statics are not owners: ld cannot see them. A name an object defines is
dropped (an assignment would override the object's symbol); an owner must be
one an object defines. An in-image address with no owner is reported and
left absolute.
"""
import bisect
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
IMAGE = (0x00100000, 0x004BE180)
# link constants that are sizes, not addresses
NUMBERS = {"_stack_size", "_heap_size"}
# what config/sta.jp.ld.in itself defines
SCRIPT = {"_gp", "_end", "_fbss"}
GROUPS = "config/data_groups.txt"      # NONMATCHING data groups (tools/split_data.py)
SOURCES = [GROUPS, "config/linker_syms.txt", "config/data_aliases.txt",
           "config/undefined_syms_auto.txt", "config/undefined_funcs_auto.txt"]
ALIAS = re.compile(r"^(\w+?)__as_\w+$")
ASSIGN = re.compile(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+|\d+)\s*;", re.M)
LABEL = re.compile(r"^(?:glabel|dlabel|jlabel) (\w+)\n(?:.*\n){0,3}?.*?/\* (?:[0-9A-F]+ )?([0-9A-F]{8})\b", re.M)


def owners():
    """[(start, end, name)] sorted: the globals an address can be written against."""
    out = {}
    carve = (ROOT / "config/symbol_addrs.carve.txt").read_text()
    for line in carve.splitlines():
        m = re.match(r"(\w+)\s*=\s*0x([0-9A-Fa-f]+);.*size:0x([0-9A-Fa-f]+)", line)
        if m and "allow_duplicated" not in line and "ignore:True" not in line:
            a, n = int(m.group(2), 16), int(m.group(3), 16)
            if n:
                out[(a, m.group(1))] = a + n
    labels = []
    for p in (ROOT / "asm").rglob("*.s"):
        if "matchings" in p.parts:      # C units' functions: carve lists them
            continue
        for m in LABEL.finditer(p.read_text()):
            if not m.group(1).startswith(".L"):
                labels.append((int(m.group(2), 16), m.group(1)))
    allstarts = sorted({a for a, _ in labels} | {a for a, _ in out})
    for a, name in labels:
        i = bisect.bisect_right(allstarts, a)
        out.setdefault((a, name), allstarts[i] if i < len(allstarts) else IMAGE[1])
    return sorted((a, e, n) for (a, n), e in out.items())


def symbols(objs):
    """(globals the objects define, names they reference undefined)."""
    from elftools.elf.elffile import ELFFile
    have, want = set(), set()
    for o in objs:
        with open(o, "rb") as f:
            st = ELFFile(f).get_section_by_name(".symtab")
            for s in st.iter_symbols():
                if s["st_shndx"] == "SHN_UNDEF":
                    if s.name:
                        want.add(s.name)
                elif s["st_info"]["bind"] in ("STB_GLOBAL", "STB_WEAK"):
                    have.add(s.name)
    return have, want


def main() -> None:
    have, want = symbols(sys.argv[2:])
    grouped = set()
    want |= {"_gp", "_end", "_fbss", "_stack", "_stack_size", "_heap_size"}
    # a merged unit's part that declared a name its own way refers to it as
    # NAME__as_<part> (tools/merge_tu.py): the same address
    aliases = sorted(n for n in want if ALIAS.match(n))
    want |= {ALIAS.match(n).group(1) for n in aliases}
    # a data group's members (config/data_groups.txt) are owners too where
    # their blob is linked: ld gets them as assignments
    g = ROOT / GROUPS
    if g.exists():
        for e in re.finditer(r"^\s*(\w+)\s*=\s*(\w+)", g.read_text(), re.M):
            if e.group(1) not in have and e.group(2) in have:
                have.add(e.group(1))
                grouped.add(e.group(1))
    table = [t for t in owners() if t[2] in have]
    starts = [t[0] for t in table]

    def owner(addr):
        i = bisect.bisect_right(starts, addr) - 1
        while i >= 0:
            a, e, n = table[i]
            if a <= addr < e:
                return n, addr - a
            if a < addr - 0x100000:
                break
            i -= 1
        return None

    lines, missing = [], []
    for src in SOURCES:
        p = ROOT / src
        if not p.exists():
            continue
        lines.append(f"/* {src} */")
        text = p.read_text()
        for m in re.finditer(r"^[^\n]*$", text, re.M):
            line = m.group(0)
            a = ASSIGN.match(line)
            if not a:
                e = re.match(r"\s*(\w+)\s*=\s*(\w+)", line)
                if e and src == GROUPS and (e.group(1) not in grouped):
                    continue        # a data group's member: only where its blob is linked
                if e:
                    lines.append(line)      # already an expression
                continue
            name, addr = a.group(1), int(a.group(2), 0)
            if name in have or name not in want or name in SCRIPT:
                continue            # an object defines it, or none uses it
            # sizes, addresses outside the image, and the load address stay
            if name in NUMBERS or not IMAGE[0] < addr < IMAGE[1]:
                lines.append(f"{name} = 0x{addr:X};")
                continue
            o = owner(addr)
            if o is None:
                missing.append(f"{src}: {name} = 0x{addr:08X}")
                lines.append(f"{name} = 0x{addr:X};")
                continue
            lines.append(f"{name} = {o[0]} + 0x{o[1]:X};")
    if aliases:
        lines.append("/* tools/merge_tu.py aliases */")
        lines += [f"{n} = {ALIAS.match(n).group(1)};" for n in aliases]
    if missing:
        print("tools/rel_syms.py: in-image addresses with no owner (left absolute):\n  "
              + "\n  ".join(missing), file=sys.stderr)
    Path(sys.argv[1]).write_text("\n".join(lines) + "\n")


if __name__ == "__main__":
    main()
