#!/usr/bin/env python3
"""Decompile unmatched game functions with m2c and try each output as is.

    tools/m2c_batch.py [-j JOBS] [--max-size BYTES] [--min-size BYTES] [ADDR ...]

Every game function still in asm/ (address >= the game start, smallest first,
or just the ADDRs given) is cut out of its splat file with the jump tables it
uses, run through m2c (-t mipsee-mwcc-c, or mipsee-gcc-c inside the ee-gcc
modules) and compiled by tools/match.py diff against the retail bytes. Work
goes to build/m2c/<func>.{s,c,txt}; build/m2c/results.tsv lists
address, size, and MATCH / the differing-word count / the compile error.
--accept copies every MATCH into src/game/ (src/game/ee/ for the ee-gcc
modules); run tools/carve.py --check, tools/carve.py and ./build.sh after.

Before compiling, the m2c output is adjusted mechanically: its unknown types
become s32 (sized ones s8..s64), a symbol the asm reaches with %hi/%lo is
declared as an array (CodeWarrior and gcc -G 8 address anything of 8 bytes or
less through $gp), and m2c gets a context of the prototypes it inferred for
every game function so calls keep their arguments.
"""
import argparse
import concurrent.futures as cf
import os
import re
import subprocess
import sys

sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parent))
import m2c_rules  # noqa: E402
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "build/m2c"
GAME = 0x00128210
EE = [(0x001D3A90, 0x001D7EC0), (0x001DC328, 0x001DC900), (0x001E1E08, 0x001E5E80)]

HEADER = '#include "common.h"\n'


def functions():
    """name -> (addr, size, asm text) for the game functions left in asm/."""
    out = {}
    for f in sorted((ROOT / "asm").glob("text*.s")):
        text = f.read_text()
        for m in re.finditer(r"^nonmatching ((?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8})|\w+), (0x[0-9A-F]+)\n(.*?)(?=^nonmatching |\Z)",
                             text, re.M | re.S):
            body = m.group(4)
            a = re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ", body)
            if not a:
                continue
            addr = int(a.group(1), 16)
            if addr >= GAME:
                out[m.group(1)] = (addr, int(m.group(3), 16), body)
    return out


def jump_tables():
    tabs = {}
    for f in (ROOT / "asm/data").glob("*rodata*.s"):
        for m in re.finditer(r"^dlabel (jtbl_\w+)\n.*?^enddlabel \1\n", f.read_text(), re.M | re.S):
            tabs[m.group(1)] = m.group(0)
    return tabs


TAIL = re.compile(r"^(\s*/\*.*?\*/\s+)j(\s+)(?!\.L)(\S+)\n(\s*/\*.*?\*/\s+)(?!nop\b)(.*)\n", re.M)


def hoist_tail_slots(body):
    """m2c loses the delay slot of a tail call (`j func`): move the slot
    instruction in front of the jump, which means the same."""
    return TAIL.sub(lambda m: f"{m.group(4)}{m.group(5)}\n{m.group(1)}j{m.group(2)}{m.group(3)}\n"
                              f"{m.group(4)}nop\n", body)


def m2c_input(body, tabs):
    s = ".set noat\n.set noreorder\n\n.section .text\n" + hoist_tail_slots(body)
    used = sorted(set(re.findall(r"\b(jtbl_\w+)", body)))
    if used:
        s += "\n.section .rodata\n" + "".join(tabs[t] for t in used if t in tabs)
    return s


def clean(c, body=""):
    c = re.sub(r"^(Warning: .*)$", r"/* \1 */", c, flags=re.M)
    # CodeWarrior (and gcc -G 8) address an object of 8 bytes or less through
    # $gp; one reached with %hi/%lo is bigger, so declare it as an array
    for sym in sorted(set(re.findall(r"%hi\(((?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8})\)", body))):
        d = re.search(r"^extern ([^;\n]*?)\b%s;" % sym, c, re.M)
        if not d or "[" in d.group(0):
            continue
        rest = c[d.end():]
        rest = re.sub(r"(&)?\b%s\b(?!\s*\[)" % sym, lambda m: sym if m.group(1) else "(*%s)" % sym, rest)
        c = c[:d.start()] + "extern %s%s[];" % (d.group(1), sym) + rest
    # m2c's unknown types: ? and ?8/?16/?32/?64
    # (not the ternary operator: " ? " with a " : " later on the line)
    def unk(m):
        line_rest = c[m.end():c.find("\n", m.end())]
        if m.group(1) is None and c[m.start() - 1:m.start()] == " " and " : " in line_rest:
            return m.group(0)
        return "s" + (m.group(1) or "32")
    c = re.sub(r"(?<![\w?\"'])\?(8|16|32|64)?(?![\w?])", unk, c)
    c = re.sub(r"^M2C_UNK (\w+\()", r"void \1", c, flags=re.M)
    c = re.sub(r"\bM2C_UNK(8|16|32|64)?\b", lambda m: "s" + (m.group(1) or "32"), c)
    c = c.replace("*(void *)", "*(s32 *)")
    # m2c's unknown pointers do byte arithmetic (a GNU extension on void *);
    # CodeWarrior rejects it, so make them byte pointers
    c = re.sub(r"\bvoid \*", "u8 *", c)
    # m2c assigns integer arithmetic to pointer temps; CodeWarrior wants a cast
    ptrs = dict((m.group(2), m.group(1).strip()) for m in
                re.finditer(r"^    ((?:[su](?:8|16|32|64)|f32|u8|\w+) \*+)(\w+);$", c, re.M))
    def cast(m):
        t = ptrs.get(m.group(2))
        if not t or m.group(3).startswith("(" + t + ")"):
            return m.group(0)
        return f"{m.group(1)}{m.group(2)} = ({t}) ({m.group(3)});"
    c = re.sub(r"^(\s+)(\w+) = (.+);$", cast, c, flags=re.M)
    # a parameter m2c types s32 but dereferences is a pointer
    m = re.search(r"^[^\s#].*\b(?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8}\(([^)]*)\) \{$", c, re.M)
    if m:
        params = m.group(1)
        for a in re.findall(r"\bs32 (arg\d)\b", params):
            if re.search(r"(?<![\w)\]])\*%s\b|\b%s\[" % (a, a), c[m.end():]):
                params = re.sub(r"\bs32 %s\b" % a, f"s32 *{a}", params)
        c = c[:m.start(1)] + params + c[m.end(1):]
    # functions used as values (callbacks) need a declaration
    known = set(re.findall(r"\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\(", c))
    values = sorted(set(re.findall(r"\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\b(?!\s*\()", c)) - known)
    if values:
        c = "".join(f"void {n}();\n" for n in values) + c
    sig = re.search(r"^((?:[su](?:8|16|32|64)|u8|f32) \*+)(?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8}\(", c, re.M)
    if sig:
        t = sig.group(1).strip()
        c = re.sub(r"^(\s+)return (?!NULL|0;)(.+);$", lambda m: f"{m.group(1)}return ({t}) ({m.group(2)});", c, flags=re.M)
    return c


UNSET = re.compile(r"M2C_ERROR\(/\* Read from unset register \$(a[0-7]|t[0-3]|f1[2-9]) \*/\)")
AREG = {"a0": 0, "a1": 1, "a2": 2, "a3": 3, "a4": 4, "a5": 5, "a6": 6, "a7": 7,
        "t0": 4, "t1": 5, "t2": 6, "t3": 7}


def own_args(c):
    """A read of an argument register m2c thought unset means the function
    takes that argument (it passes it on): add the parameters."""
    found = UNSET.findall(c)
    m = SIG.search(c)
    if not found or not m:
        return c
    params = [] if m.group(3).strip() in ("", "void") else [p.strip() for p in m.group(3).split(",")]
    ints = [p for p in params if not p.startswith(("f32", "f64"))]
    floats = [p for p in params if p.startswith(("f32", "f64"))]
    need = max([AREG[r] + 1 for r in found if r in AREG] + [0])
    fneed = max([int(r[1:]) - 11 for r in found if r.startswith("f")] + [0])
    if len(ints) < need and len(floats) == 0:
        params += [f"s32 arg{k}" for k in range(len(ints), need)]
    elif len(ints) < need:
        return c
    params += [f"f32 farg{k}" for k in range(len(floats), fneed)]
    c = c[:m.start(3)] + ", ".join(params) + c[m.end(3):]
    return UNSET.sub(lambda r: f"farg{int(r.group(1)[1:]) - 12}" if r.group(1).startswith("f")
                     else f"arg{AREG[r.group(1)]}", c)


def m2c(name, addr, body, tabs, ctx=None):
    ee = any(lo <= addr < hi for lo, hi in EE)
    s = OUT / f"{name}.s"
    s.write_text(m2c_input(body, tabs))
    cmd = ["m2c", "-t", "mipsee-gcc-c" if ee else "mipsee-mwcc-c", "--valid-syntax"]
    if ctx:
        cmd += ["--context", str(ctx)]
    r = subprocess.run(cmd + [str(s)], capture_output=True, text=True)
    return r.returncode, (own_args(r.stdout) if r.returncode == 0 else r.stdout + r.stderr)


SIG = re.compile(r"^((?:static )?[A-Za-z_][\w ]*?[\s*]+)((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\((.*)\) \{$", re.M)


def signatures(outputs):
    """A context file of the prototypes m2c gave each function."""
    lines = []
    for text in outputs:
        m = SIG.search(text)
        if m:
            ret = clean(m.group(1)).replace("static ", "").strip()
            args = clean(m.group(3))
            lines.append(f"{ret} {m.group(2)}({args});")
    return lines


def write_context(outs):
    ctx = OUT / "context.h"
    types = "".join(l + "\n" for h in ("types.h", "common.h")
                    for l in (ROOT / "include" / h).read_text().splitlines()
                    if l.startswith("typedef") and l.endswith(";") and "__int128" not in l and "mode(TI)" not in l)
    types += "typedef long long s128;\ntypedef unsigned long long u128;\n"
    ctx.write_text(types + "\n".join(signatures(outs)) + "\n")
    return ctx


def score(c, t):
    """Compile c (a path) against retail: (differing words, status); a
    compile error scores worst."""
    def diff(flags):
        return subprocess.run([sys.executable, str(ROOT / "tools/match.py"), "diff", str(c)],
                              capture_output=True, text=True, cwd=ROOT, env={**os.environ, "GAME_CFLAGS": flags})
    # -relax_pointers only loosens type checks, so m2c's loose types compile
    r = diff("-O4,p -relax_pointers")
    t.write_text(r.stdout + r.stderr)
    if r.returncode == 0:
        return 0, ("MATCH" if diff("-O4,p").returncode == 0 else "relaxed-match")
    m = re.search(r": (\d+) of (\d+) words differ", r.stdout)
    if m:
        return int(m.group(1)), f"diff {m.group(1)}/{m.group(2)}"
    return 10 ** 6, "cc-error"


def one(name, addr, size, body, tabs, ctx=None):
    """Decompile, then compile m2c's output as is and with tools/m2c_rules.py
    applied; build/m2c/<func>.c keeps the better one (ties: as is), and the
    status says "+rules" when the rules won."""
    c, t = (OUT / f"{name}.{x}" for x in ("c", "txt"))
    rc, out = m2c(name, addr, body, tabs, ctx)
    if rc:
        c.write_text(out)
        return name, addr, size, "m2c-failed"
    raw = HEADER + clean(out, body)
    c.write_text(raw)
    (OUT / f"{name}.raw.c").write_text(raw)       # for tools/m2c_rules_eval.py
    best = score(c, t) + (raw,)
    if best[0]:
        # all rules, and each rule alone (tools/m2c_rules_eval.py: one rule
        # that hurts can hide another that helps)
        tried = set()
        for ruled in [m2c_rules.apply(raw, body), m2c_rules.all_but_prototypes(raw, body)] + m2c_rules.each(raw, body):
            if ruled == raw or ruled in tried:
                continue
            tried.add(ruled)
            rc_, rt = OUT / f"{name}.rules.c", OUT / f"{name}.rules.txt"
            # compile under the function's own name so match.py finds it
            rc_.write_text(ruled)
            sc = score(rc_, rt)
            if sc[0] < best[0]:
                best = (sc[0], sc[1] + " +rules", ruled)
                c.write_text(ruled)
                t.write_text(rt.read_text())
            if best[0] == 0:
                break
        # greedy hill-climb: apply each rule in turn to the best text so far
        # and keep it only when the score improves (repeat while it helps)
        if best[0]:
            text, sc_best = best[2], best[0]
            improved = True
            passes = 0
            while improved and sc_best and passes < 3:
                passes += 1
                improved = False
                for r in m2c_rules.RULES + m2c_rules.BODY_RULES:
                    try:
                        cand = r(text) if r in m2c_rules.RULES else r(text, body)
                    except Exception:
                        continue
                    if cand == text or cand in tried:
                        continue
                    tried.add(cand)
                    rc_, rt = OUT / f"{name}.rules.c", OUT / f"{name}.rules.txt"
                    rc_.write_text(cand)
                    sc = score(rc_, rt)
                    if sc[0] < sc_best:
                        text, sc_best = cand, sc[0]
                        best = (sc[0], sc[1] + " +rules", cand)
                        c.write_text(cand)
                        t.write_text(rt.read_text())
                        improved = True
                        if sc_best == 0:
                            break
        # near misses: every order of the local declarations (they pick the
        # registers and stack slots: LEDGER)
        if 0 < best[0] <= 10:
            import itertools
            text = best[2]
            m = re.search(r"(?<=\{\n)((?:    (?!return)[\w ]+?[\s*]+\w+(?:\[\w+\])?;\n){2,4})", text)
            if m:
                lines = m.group(1).splitlines(keepends=True)
                for perm in itertools.permutations(lines):
                    cand = text[:m.start(1)] + "".join(perm) + text[m.end(1):]
                    if cand in tried or cand == text:
                        continue
                    tried.add(cand)
                    rc_, rt = OUT / f"{name}.rules.c", OUT / f"{name}.rules.txt"
                    rc_.write_text(cand)
                    sc = score(rc_, rt)
                    if sc[0] < best[0]:
                        best = (sc[0], sc[1] + " +rules", cand)
                        c.write_text(cand)
                        t.write_text(rt.read_text())
                        if sc[0] == 0:
                            break
    return name, addr, size, best[1]


PERM_TYPES = ["s32", "u8", "s16", "u16", "s8", "s64", "u32", "f32"]


def permute(name, addr, size, limit=400):
    """Near-miss: try every type for the parameters of the function and of
    the prototypes it declares (most frequent types first),
    keeping the first combination that matches."""
    import itertools
    c = OUT / f"{name}.c"
    text = c.read_text()
    slots = []

    def mark(m):
        params = [p.strip() for p in m.group(2).split(",")]
        if params == ["void"] or not params[0]:
            return m.group(0)
        new = []
        for p in params:
            pm = re.match(r"^(%s)( \w+)?$" % m2c_rules.TYPE, p)
            if pm:
                slots.append(pm.group(1))
                new.append(f"@T{len(slots) - 1}@" + (pm.group(2) or ""))
            else:
                new.append(p)
        return m.group(1) + ", ".join(new) + m.group(3)
    templ = re.sub(r"^((?:\w+ )+\*?(?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8}\()([^()]*)(\)(?: \{|;))", mark, text, flags=re.M)
    if not slots or len(slots) > 8:
        return None
    choices = [[t] + [x for x in PERM_TYPES if x != t][:4] for t in slots]
    tmp = OUT / "perm" / name
    tmp.mkdir(parents=True, exist_ok=True)
    for k, combo in enumerate(itertools.islice(itertools.product(*choices), limit)):
        v = templ
        for i, ty in enumerate(combo):
            v = v.replace(f"@T{i}@", ty)
        p = tmp / f"{name}.c"
        p.write_text(v)
        r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), "diff", str(p)],
                           capture_output=True, text=True, cwd=ROOT)
        if r.returncode == 0:
            c.write_text(v)
            return "MATCH +perm"
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=os.cpu_count())
    ap.add_argument("--max-size", type=lambda x: int(x, 0), default=1 << 30)
    ap.add_argument("--min-size", type=lambda x: int(x, 0), default=0)
    ap.add_argument("--accept", action="store_true", help="copy each MATCH to src/game/ (src/game/ee/)")
    ap.add_argument("--perm", type=lambda x: int(x, 0), default=0,
                    help="permute parameter types of near misses up to this size")
    ap.add_argument("addrs", nargs="*")
    a = ap.parse_args()
    OUT.mkdir(parents=True, exist_ok=True)
    funcs = functions()
    want = {int(x, 16) for x in a.addrs}
    todo = sorted(((v[1], v[0], k, v[2]) for k, v in funcs.items()
                   if (not want or v[0] in want) and a.min_size <= v[1] <= a.max_size))
    tabs = jump_tables()
    rows = []
    with cf.ThreadPoolExecutor(a.j) as ex:
        # pass 1: every function, for the prototypes of the callees
        everything = [(k, v[0], v[2]) for k, v in funcs.items()]
        ctx = None
        for _ in range(2):
            outs = [o for rc, o in ex.map(lambda x: m2c(x[0], x[1], x[2], tabs, ctx), everything) if rc == 0]
            ctx = write_context(outs)
        for r in ex.map(lambda x: one(x[2], x[1], x[0], x[3], tabs, ctx), todo):
            rows.append(r)
    if a.perm:
        near = [r for r in rows if r[3].startswith("diff") and r[2] <= a.perm]
        with cf.ThreadPoolExecutor(a.j) as ex:
            for r, st in zip(near, ex.map(lambda r: permute(r[0], r[1], r[2]), near)):
                if st:
                    rows[rows.index(r)] = (r[0], r[1], r[2], st)
    rows.sort(key=lambda r: (r[2], r[1]))
    (OUT / "results.tsv").write_text("".join(f"{r[1]:08X}\t{r[2]:#x}\t{r[0]}\t{r[3]}\n" for r in rows))
    if a.accept:
        for name, addr, size, st in rows:
            if st.startswith("MATCH"):
                ee = any(lo <= addr < hi for lo, hi in EE)
                dst = ROOT / "src/game" / ("ee" if ee else "") / f"{name}.c"
                if not dst.exists():
                    dst.write_text((OUT / f"{name}.c").read_text())
    n = len(rows)
    for st in ("MATCH", "diff", "cc-error", "m2c-failed"):
        print(f"{st:10s} {sum(1 for r in rows if r[3].startswith(st)):5d} / {n}")
    print(f"perm matched {sum(1 for r in rows if r[3].endswith('+perm'))}")
    print(f"rules won on {sum(1 for r in rows if r[3].endswith('+rules'))}")


if __name__ == "__main__":
    main()
