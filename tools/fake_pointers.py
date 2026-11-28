#!/usr/bin/env python3
"""Find the data words splat took for pointers that are not.

    tools/fake_pointers.py            report
    tools/fake_pointers.py --write    append ignore entries to config/symbol_addrs.txt

splat names every data word whose value falls in the image as a pointer
(.word D_XXXXXXXX) and puts a label at the address it gives. In packed data
(the command blobs of data_001F38F0, strings such as "---" or "OFF") those
labels are false: they cut the real objects at the address, mostly in .bss,
into pieces.

A target is false when no code refers to it (no %hi/%lo in a splat function,
no mention in src/ or include/) and either it is not 4-aligned, or it comes
from a data file where most such targets are not 4-aligned (packed data, in
which an aligned look-alike is chance). Each one gets an
`ignored_XXXXXXXX = 0x...; // ignore:True` entry, which makes splat write the
word as a number and drop the label. Targets code refers to stay: they are
real symbols, whatever data word happens to equal them.

splat also labels .bss addresses that bytes elsewhere spell (it reads
strings as words while it looks for pointers, then writes them as strings):
a .bss label nothing at all refers to is dropped the same way. Re-split (rm -rf asm;
./build.sh) after --write, and run it again until it finds nothing.
"""
import collections
import glob
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SYMS = ROOT / "config/symbol_addrs.txt"
WORD = re.compile(r"/\* \w+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+\.word ((?:D|g[A-Z][A-Za-z0-9]*)_([0-9A-F]{8}))\s*$")
NAME = re.compile(r"\b((?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8})\b")


def main() -> None:
    code = set()
    for p in glob.glob(str(ROOT / "asm/**/*.s"), recursive=True):
        if "/asm/data/" not in p:
            code |= set(NAME.findall(Path(p).read_text()))
    for pat in ("src/**/*.c", "src/**/*.h", "src/**/*.s", "include/**/*.h"):
        for p in glob.glob(str(ROOT / pat), recursive=True):
            code |= set(NAME.findall(Path(p).read_text()))
    per_file = collections.defaultdict(set)
    for p in sorted(glob.glob(str(ROOT / "asm/data/*.s"))):
        for line in Path(p).read_text().splitlines():
            m = WORD.search(line)
            if m and m.group(2) not in code:
                per_file[Path(p).name].add(int(m.group(3), 16))
    fake = set()
    for name, targets in per_file.items():
        unaligned = {t for t in targets if t % 4}
        packed = len(unaligned) * 2 >= len(targets)
        picked = targets if packed else unaligned
        for t in sorted(picked):
            print(f"{name}: D_{t:08X}{' (packed data)' if packed and not t % 4 else ''}")
        fake |= picked
    # .bss labels nothing refers to (no data word, no code)
    refs = set(code)
    for p in glob.glob(str(ROOT / "asm/data/*.s")):
        if not p.endswith("/bss.bss.s"):
            refs |= set(NAME.findall(Path(p).read_text()))
    bss = ROOT / "asm/data/bss.bss.s"
    for n in re.findall(r"^dlabel ((?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8})\b", bss.read_text(), re.M):
        if n not in refs:
            print(f"bss.bss.s: {n} (unreferenced)")
            fake.add(int(n[2:], 16))
    have = set(re.findall(r"^ignored_([0-9A-F]{8})\b", SYMS.read_text(), re.M))
    new = sorted(t for t in fake if f"{t:08X}" not in have)
    print(f"{len(fake)} false pointer targets, {len(new)} new", file=sys.stderr)
    if "--write" in sys.argv and new:
        with open(SYMS, "a") as f:
            f.write("// data words splat took for pointers (tools/fake_pointers.py)\n")
            for t in new:
                f.write(f"ignored_{t:08X} = 0x{t:08X}; // ignore:True\n")


if __name__ == "__main__":
    main()
