"""Print a compact naming dossier for game functions (address order).

    tools/name_dossier.py START END      functions with START <= addr < END

Per function: size, caller count, strings it references, callees (by their
current names in config/game_func_names.txt or symbol_addrs.txt), then its C
body from src/game (or wip/) when there is one, else an asm summary.
"""
import re, sys, glob, json, collections
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
rom = (ROOT / "baserom/jp/sta.rom").read_bytes(); B = 0x100000

def cstr(a):
    if not (0x1EDE80 <= a < 0x201E80): return None
    j = a - B; k = j
    while k < len(rom) and rom[k] and k - j < 60: k += 1
    if k - j < 2 or rom[k]: return None
    try: s = rom[j:k].decode("shift_jis")
    except UnicodeDecodeError: return None
    return s if all(c.isprintable() or c in "\n\t" for c in s) else None

names = {}
for l in open(ROOT / "config/symbol_addrs.txt"):
    m = re.match(r"(\w+)\s*=\s*0x([0-9A-Fa-f]+);.*type:func", l)
    if m: names[int(m.group(2), 16)] = m.group(1)
nf = ROOT / "config/game_func_names.txt"
if nf.exists():
    for l in open(nf):
        p = l.split()
        if len(p) >= 2 and not l.startswith("#"): names[int(p[0], 16)] = p[1]

ADDR = re.compile(r"\b(?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8})\b")
def nm(s):
    m = re.fullmatch(r"(?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8})", s)
    return names.get(int(m.group(1), 16), s) if m else s

F = {}
for p in glob.glob(str(ROOT / "asm/**/*.s"), recursive=True):
    cur = None
    for l in open(p, errors="replace"):
        m = re.match(r"glabel (\w+)", l)
        if m:
            mm = ADDR.fullmatch(m.group(1))
            cur = int(mm.group(1), 16) if mm else None
            if cur is not None and not (0x128210 <= cur < 0x1EDE80): cur = None
            if cur is not None: F.setdefault(cur, [])
            continue
        if l.startswith("endlabel"): cur = None; continue
        if cur is not None and "/*" in l: F[cur].append(re.sub(r"/\*.*?\*/", "", l).strip())

callers = collections.Counter()
for a, ins in F.items():
    for l in ins:
        m = re.match(r"jal\s+(\w+)", l)
        if m:
            mm = ADDR.fullmatch(m.group(1))
            if mm: callers[int(mm.group(1), 16)] += 1

bodies = {}
for p in list((ROOT / "src/game").rglob("*.c")) + list((ROOT / "wip").rglob("*.c")):
    t = p.read_text(errors="replace")
    for m in re.finditer(r"^[A-Za-z][^\n;{}]*?\b((?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8}))\s*\([^;{}]*\)\s*\{", t, re.M):
        a = int(m.group(2), 16)
        e = t.find("\n}", m.end())
        if a not in bodies or "wip" not in str(p): bodies.setdefault(a, t[m.start():e + 2])

def summary(ins):
    offs = collections.Counter(); fl = vu = br = 0; consts = set()
    for l in ins:
        op = l.split()[0] if l else ""
        if op.endswith(".s") or op in ("mtc1", "mfc1", "lwc1", "swc1"): fl += 1
        if op.startswith("v") or op in ("qmtc2", "qmfc2", "lqc2", "sqc2"): vu += 1
        if op.startswith("b"): br += 1
        for o in re.findall(r"(-?0x[0-9A-F]+)\(\$(?:[4-9]|1[0-9]|2[0-3])\)", l): offs[o] += 1
        m = re.match(r"(?:addiu|ori|daddiu)\s+\$\d+, \$0, (-?0x[0-9A-F]+)", l)
        if m: consts.add(m.group(1))
    return f"  asm: fl={fl} vu={vu} br={br} offs={','.join(o for o,_ in offs.most_common(8))} consts={','.join(sorted(consts)[:10])}"

def main():
    lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
    maxl = int(sys.argv[3]) if len(sys.argv) > 3 else 30
    for a in sorted(F):
        if not lo <= a < hi: continue
        ins = F[a]
        calls = []; strs = []
        for l in ins:
            m = re.match(r"jal\s+(\w+)", l)
            if m: calls.append(nm(m.group(1)))
            for d in re.findall(r"%(?:hi|lo|gp_rel)\((?:D|g[A-Z][A-Za-z0-9]*)_([0-9A-F]{8})\)", l):
                s = cstr(int(d, 16))
                if s and s not in strs: strs.append(s)
        cur = names.get(a, "")
        print(f"=== {a:08X} {len(ins)*4:#x} callers={callers[a]} {cur}")
        if strs: print("  strs:", strs)
        if calls:
            u = list(dict.fromkeys(calls))
            print("  calls:", ", ".join(u[:14]) + (f" +{len(u)-14}" if len(u) > 14 else ""))
        b = bodies.get(a)
        if b and "INCLUDE_ASM" not in b:
            b = ADDR.sub(lambda m: names.get(int(m.group(1), 16), m.group(0)), b)
            lines = [x.rstrip() for x in b.splitlines() if x.strip()]
            if len(lines) > maxl: lines = lines[:maxl] + [f"  ... ({len(lines)} lines)"]
            print("\n".join("  " + x for x in lines))
        elif len(ins) <= 24:
            print("  " + " | ".join(nm(x) if False else ADDR.sub(lambda m: names.get(int(m.group(1), 16), m.group(0)), x) for x in ins))
        else:
            print(summary(ins))

if __name__ == "__main__":
    main()
