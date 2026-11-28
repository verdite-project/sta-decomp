#!/usr/bin/env python3
"""Merge the NONMATCHING blocks tools/split_data.py leaves back to back.

    tools/merge_ifdefs.py

- A data unit's `#ifndef NONMATCHING` blocks that follow each other (one per
  owner, as split_data.py writes them) become one; its header no longer names
  an owner (each twin's `/* data twins (UNIT): ... */` or `/* data group */`
  line in its owner says where it went).
- An owner's `#ifdef NONMATCHING` blocks that follow each other become one
  (one per split_data.py run, appended at the end).

Only the preprocessor lines change, so both builds compile what they did.
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
UNIT_HEAD = "#ifndef NONMATCHING /* the NONMATCHING build defines these in"
MERGED = "#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */"


def merge_unit(t: str) -> str:
    t = re.sub(r"^#ifndef NONMATCHING /\* the NONMATCHING build defines these in [^*]*\*/$", MERGED, t, flags=re.M)
    # #endif then (blank lines) the next #ifndef: one block
    return re.sub(r"^#endif\n(?:\n)*" + re.escape(MERGED) + r"\n", "", t, flags=re.M)


def merge_owner(t: str) -> str:
    """Join an `#ifdef NONMATCHING` block with the one right after it, when
    neither has an #else (an INCLUDE_ASM block's #else branch is the matching
    build's: what follows its #endif must stay out of it) or a nested #if."""
    lines = t.split("\n")
    # (start, end) of each top-level #ifdef NONMATCHING block, and whether it
    # is plain (no #else/#elif at its level, no nested #if)
    blocks, i = [], 0
    while i < len(lines):
        if lines[i] == "#ifdef NONMATCHING":
            depth, plain, j = 0, True, i + 1
            while j < len(lines):
                l = lines[j]
                if re.match(r"\s*#\s*if", l):
                    depth += 1
                    plain = False
                elif re.match(r"\s*#\s*endif", l):
                    if depth == 0:
                        break
                    depth -= 1
                elif re.match(r"\s*#\s*(else|elif)", l) and depth == 0:
                    plain = False
                j += 1
            blocks.append((i, j, plain))
            i = j + 1
        else:
            i += 1
    drop = set()
    for (s1, e1, p1), (s2, e2, p2) in zip(blocks, blocks[1:]):
        if p1 and p2 and all(not lines[k].strip() for k in range(e1 + 1, s2)):
            drop |= set(range(e1, s2 + 1))       # the #endif, the gap, the #ifdef
            if s2 + 1 < len(lines) and lines[s2 + 1] == "#pragma explicit_zero_data on":
                drop.add(s2 + 1)
    return "\n".join(l for k, l in enumerate(lines) if k not in drop)


STATIC = re.compile(r"#ifndef NONMATCHING\n((?:extern[^\n]*\n)+)#else\n((?:(?!#endif\n)[^\n]*\n)+?)#endif\n")


def merge_statics(t: str) -> str:
    """Join static twins' blocks that follow each other (`#ifndef NONMATCHING`
    extern(s) `#else` twin(s) `#endif`): the externs in one #ifndef part,
    the twins (each after its `/* data twins */` line) in one #else part."""
    # plain one-line externs between two such blocks move up above the first
    # (the order of declarations does not matter), so the blocks meet
    while True:
        m = re.search(r"(" + STATIC.pattern + r")((?:extern [^\n;]*;[^\n]*\n)*)(" + STATIC.pattern + r")", t)
        if not m:
            return t
        a, b = STATIC.match(m.group(1)), STATIC.match(m.group(5))
        t = t[:m.start()] + (m.group(4) + "#ifndef NONMATCHING\n" + a.group(1) + b.group(1) + "#else\n"
                             + a.group(2) + b.group(2) + "#endif\n") + t[m.end():]


def main() -> None:
    n = 0
    for p in sorted((ROOT / "src/game").rglob("*.c")):
        t = p.read_text()
        u = merge_unit(t) if "/src/game/data/" in str(p) else merge_statics(merge_owner(t))
        if u != t:
            p.write_text(u)
            n += 1
    print(f"merge_ifdefs: {n} files")


if __name__ == "__main__":
    main()
