#!/usr/bin/env python3
"""Apply config/game_data_names.txt to the tree.

    tools/apply_data_names.py [--dry-run]

Every data symbol of a named address (splat's D_ADDR, or an earlier
gName_ADDR) becomes <name>_<ADDR> (tools/names.py) in the tracked and new
text files under src/, wip/, include/, config/ and docs/: whole identifiers,
and the parts of NAME__as_PART aliases (tools/merge_tu.py). Identifiers that
only end in the name (a type named after its object) follow too.
config/symbol_addrs.carve.txt, the names splat writes into asm/, is one of
those files, so rerun tools/split.py afterwards (rm -rf asm; ./build.sh).
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from apply_names import tracked  # noqa: E402
from names import ROOT, DATA_NAMES, load_data  # noqa: E402

WORD = re.compile(r"\b[A-Za-z_]\w*[0-9A-F]{8}\w*\b")


def main() -> None:
    dry = "--dry-run" in sys.argv
    names = load_data()
    want = {a: f"{n}_{a:08X}" for a, n in names.items()}

    def one(ident: str) -> str:
        m = re.search(r"(?:^|_)((?:D|g[A-Z][A-Za-z0-9]*)_([0-9A-F]{8}))$", ident)
        if not m:
            return ident
        a = int(m.group(2), 16)
        if a not in want:
            return ident
        old = m.group(1)
        return ident[:len(ident) - len(old)] + want[a]

    def sub(m: re.Match) -> str:
        return "__as_".join(one(x) for x in m.group(0).split("__as_"))

    changed = 0
    for p in tracked():
        if p == DATA_NAMES:
            continue
        try:
            t = p.read_text()
        except UnicodeDecodeError:
            continue
        u = WORD.sub(sub, t)
        if u != t:
            changed += 1
            if not dry:
                p.write_text(u)
    print(f"{changed} files rewritten, {len(want)} data names")


if __name__ == "__main__":
    main()
