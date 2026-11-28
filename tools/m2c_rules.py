"""Rewrite rules for m2c output, learned from how hand-matched C differed from m2c output.

tools/m2c_batch.py compiles m2c's output both as is and after apply() and
keeps the variant with fewer differing words, so a rule only has to help on
average. Each rule records where it came from.
"""
import re

SIZE = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4,
        "s64": 8, "u64": 8, "f64": 8, "s128": 16, "u128": 16}
TYPE = r"(?:[su](?:8|16|32|64|128)|f32|f64)"


def balanced(s, i):
    """Index just past the parenthesised group that opens at s[i]."""
    depth = 0
    for k in range(i, len(s)):
        if s[k] == "(":
            depth += 1
        elif s[k] == ")":
            depth -= 1
            if depth == 0:
                return k + 1
    return -1


def split_args(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def arg_type(a):
    """(type, expression without the cast) of a call argument."""
    m = re.match(r"^\((%s|void \*|[\w ]+\*+)\) (.*)$" % TYPE, a)
    if m and balanced("(" + m.group(2) + ")", 0) == len(m.group(2)) + 2:
        inner = m.group(2)
        fm = re.match(r"^M2C_FIELD\(.*, (%s) \*, [^,]+\)$" % TYPE, inner)
        # (s32) of a narrow field load: the callee takes the narrow type
        if fm and SIZE.get(m.group(1), 0) > SIZE.get(fm.group(1), 0) and "s64" not in m.group(1):
            return fm.group(1), inner
        return m.group(1), inner
    fm = re.match(r"^M2C_FIELD\(.*, (%s) \*, [^,]+\)$" % TYPE, a)
    if fm:
        return fm.group(1), a
    if re.match(r"^-?(0x)?[0-9A-Fa-f]+U?$", a) or a == "NULL":
        return "s32", a
    return None, a


def callee_prototypes(c):
    """callers pass narrow loads and casts to narrow parameters
    (u8 getters around 0x143920, s16/s8 wrappers, s64 at 0x17DEA0). Declare
    each called func_ with the argument types and drop the casts."""
    defined = set(re.findall(r"^[^\s].*\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\(.*\) \{$", c, re.M))
    declared = set(re.findall(r"^[^\s].*\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\(.*\);", c, re.M))
    protos, narrowed = {}, {}
    out, i = [], 0
    for m in re.finditer(r"\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\(", c):
        name = m.group(1)
        if name in defined or name in declared or m.start() < i:
            continue
        line_start = c.rfind("\n", 0, m.start()) + 1
        if not c[line_start:m.start()].startswith(" "):
            continue
        end = balanced(c, m.end() - 1)
        if end < 0:
            continue
        args = split_args(c[m.end():end - 1])
        if any("M2C_ERROR" in a for a in args):
            continue
        types, exprs = zip(*(arg_type(a) for a in args)) if args else ((), ())
        for a, t, e in zip(args, types, exprs):
            if re.fullmatch(r"arg\d", e) and a != e and t and SIZE.get(t, 4) < 4:
                narrowed[e] = t
        # m2c_rules_eval: declaring every callee costs more than it gains;
        # only calls that pass a cast or narrow value get a prototype
        if not any(t and t not in ("s32", "void *") or a != e for t, a, e in zip(types, args, exprs)):
            out.append(c[i:end])
            i = end
            continue
        types = [t or "s32" for t in types]
        protos.setdefault(name, types)
        out.append(c[i:m.end()] + ", ".join(exprs) + ")")
        i = end
    out.append(c[i:])
    c = "".join(out)
    # a cast of one of our own arguments: take that argument narrow
    for a, t in narrowed.items():
        c = re.sub(r"(\b(?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8}\([^)]*?)\bs32 %s\b" % a, lambda m: m.group(1) + f"{t} {a}", c, count=1)
    if protos:
        lines = [f"s32 {n}({', '.join(t) if t else 'void'});" for n, t in protos.items()]
        # keep the return type m2c used if the call's value is unused
        for n in protos:
            if not re.search(r"(=|return|\(|,)\s*%s\(" % n, c):
                lines = [l.replace(f"s32 {n}(", f"void {n}(") for l in lines]
        c = re.sub(r'^(#include "common.h"\n)', lambda m: m.group(1) + "\n".join(lines) + "\n", c)
    return c


def typed_indexing(c):
    """m2c scales pointer arithmetic by bytes on typed symbols
    (*(D_0033F6D0 + (i * 4)) for D_0033F6D0[i]); C scales again."""
    decls = dict((m.group(2), m.group(1)) for m in
                 re.finditer(r"^extern (%s) \*?((?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8})(?:\[\])?;" % TYPE, c, re.M))

    def fix(m):
        sym, idx, n = m.group(1), m.group(2), int(m.group(3), 0)
        t = decls.get(sym)
        if not t or n % SIZE[t]:
            return m.group(0)
        k = n // SIZE[t]
        return f"{sym}[{idx}]" if k == 1 else f"{sym}[{idx} * {k}]"
    return re.sub(r"\*\((?:\(\*)?((?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8})\)? \+ \((\w+(?: & 0x\w+)?|\(\w+ & 0x\w+\)) \* (\w+)\)\)", fix, c)


def base_first_index(c):
    """CodeWarrior adds index to base in the order of the C
    `s->v[i]` (0x13DCA0, 0x13E3F0): rewrite m2c's ((i * n) + base)."""
    def fix(m):
        idx, n, base, t, off = m.group(1), int(m.group(2), 0), m.group(3), m.group(4), m.group(5)
        if SIZE.get(t) != n:
            return m.group(0)
        return f"(({t} *)((u8 *){base} + {off}))[{idx}]"
    return re.sub(r"M2C_FIELD\(\(\(\(([^()]+)\) \* (\w+)\) \+ (\w+)\), (%s) \*, (\w+)\)" % TYPE, fix, c)


def bitfields(c):
    """the most common hand fix. m2c writes a byte bitfield store
    as (x & ~M) | ((v & 1) << k) and a load as (u64)((s64)x << a) >> b;
    CodeWarrior only emits these shapes for real bitfields."""
    decls = []

    def bf_type(off, pos, width, unit="unsigned char"):
        name = f"BF_{off:X}_{pos}_{width}"
        if name not in (d[0] for d in decls):
            pad = f"char pad[0x{off:X}]; " if off else ""
            gap = f"{unit} : {pos}; " if pos else ""
            decls.append((name, f"typedef struct {{ {pad}{gap}{unit} f : {width}; }} {name};"))
        return name

    def store(m):
        base, off, mask, val = m.group(1), int(m.group(2), 0), int(m.group(4), 0), m.group(5)
        if m.group(3) != m.group(2):
            return m.group(0)
        if mask == 0 or (mask >> (mask & -mask).bit_length() - 1) & ((mask >> (mask & -mask).bit_length() - 1) + 1):
            return m.group(0)
        pos = (mask & -mask).bit_length() - 1
        width = bin(mask).count("1")
        v = val.strip()
        mm = re.fullmatch(r"\(\((.+) & (0x\w+|\d+)\) (?:\* (0x\w+|\d+)|<< (0x\w+|\d+))\)", v) or \
            re.fullmatch(r"\((.+) & (0x\w+|\d+)\)", v)
        if mm:
            v = mm.group(1)
        else:
            mm = re.fullmatch(r"\(\((.+)\) (?:\* (0x\w+|\d+)|<< (0x\w+|\d+))\)", v)
            if mm:
                v = mm.group(1)
            elif re.fullmatch(r"0x\w+|\d+", v):
                v = str(int(v, 0) >> pos)
            else:
                return m.group(0)
        t = bf_type(off, pos, width)
        return f"(({t} *){base})->f = {v};"
    c = re.sub(r"M2C_FIELD\((\w+), u8 \*, (\w+)\) = \(u8\) \(\(M2C_FIELD\(\1, u8 \*, (\w+)\) & ~(\w+)\) \| (.+)\);",
               store, c)

    def load(m):
        base, off, a, b = m.group(1), int(m.group(2), 0), int(m.group(3), 0), int(m.group(4), 0)
        width = 64 - b
        pos = 64 - a - width
        if not 0 <= pos < 8 or pos + width > 8:
            return m.group(0)
        t = bf_type(off, pos, width, "unsigned int")
        return f"(({t} *){base})->f"
    c = re.sub(r"\(\(u64\) \(\(s64\) M2C_FIELD\((\w+), u8 \*, (\w+)\) << (\w+)\) >> (\w+)\)", load, c)
    c = re.sub(r"\(u64\) \(\(s64\) M2C_FIELD\((\w+), u8 \*, (\w+)\) << (\w+)\) >> (\w+)", load, c)
    if decls:
        c = re.sub(r'^(#include "common.h"\n)', lambda m: m.group(1) + "\n".join(d for _, d in decls) + "\n",
                   c, count=1)
    return c


def at_compares(c, body):
    """LEDGER: CodeWarrior compares into $at for `x > N` / `x <= N` and into a
    temp for `x >= N+1` / `x < N+1`; m2c writes the latter for both."""
    for n in sorted({int(x, 0) for x in re.findall(r"\bslti\s+\$1, \$\w+, (-?0x[0-9A-Fa-f]+|-?\d+)", body)}):
        lits = {str(n), hex(n), f"0x{n:X}"}
        for lit in lits:
            c = re.sub(r">= %s\b" % re.escape(lit), f"> {n - 1}", c)
            c = re.sub(r"(?<![<<])< %s\b" % re.escape(lit), f"<= {n - 1}", c)
    # LEDGER: `slt $at, x, $zero` is `0 > x` (`x < 0` gives bltz)
    if re.search(r"\bslt\s+\$1, \$\w+, \$0\b", body):
        c = re.sub(r"\b([A-Za-z_]\w*) < 0\b", r"0 > \1", c)
    # LEDGER: `sltu $at, $zero, x` is an unsigned `x > 0` (`x != 0` gives a
    # plain branch: func_00164F10)
    if re.search(r"\bsltu\s+\$1, \$0, \$\w+", body):
        c = re.sub(r" != 0(U)?\b", r" > 0\1", c)
    return c


def stack_order(c):
    """LEDGER: CodeWarrior lays locals out in reverse declaration order
    (func_001A83A0): declare m2c's spXX locals from the highest offset down."""
    def fix(m):
        lines = m.group(0).splitlines(keepends=True)
        sp = [l for l in lines if re.match(r"^    [\w ]+?\*?sp([0-9A-F]+)(\[\w+\])?;$", l)]
        if len(sp) < 2:
            return m.group(0)
        key = lambda l: int(re.search(r"sp([0-9A-F]+)(?:\[\w+\])?;$", l).group(1), 16)
        ordered = iter(sorted(sp, key=key, reverse=True))
        return "".join(next(ordered) if l in sp else l for l in lines)
    return re.sub(r"(?<=\{\n)(?:    [^\n]*;\n)+", fix, c)


def ternary_sense(c):
    """LEDGER: `c ? a : b` and `!c ? b : a` pick movn vs movz (func_001B0A80);
    m2c writes the `== 0` form."""
    return re.sub(r"\(([^()?:]+) == 0\) \? ([^:;]+?) : ([^;)]+)", r"(\1 != 0) ? \3 : \2", c)


def unsigned_counters(c, body):
    """LEDGER: a loop compare done with `sltu $r, $i, $n` has an unsigned
    counter (func_001B6130); m2c declares its var_N locals s32."""
    if not re.search(r"\bsltu\s+\$\w+, \$(?!0\b)\w+, \$\w+", body):
        return c
    return re.sub(r"^(    )s32 (var_\w+);", r"\1u32 \2;", c, flags=re.M)


def flip_return(c):
    """LEDGER: which value retail branches to first follows the order of the
    two returns (func_001C9A20, func_001CC390): swap a final
    `if (c) { return a; } return b;` into `if (!(c)) { return b; } return a;`."""
    return re.sub(r"^(    )if \((.+)\) \{\n\1    return ([^;]+);\n\1\}\n\1return ([^;]+);\n",
                  r"\1if (!(\2)) {\n\1    return \4;\n\1}\n\1return \3;\n", c, flags=re.M)


def vector_locals(c):
    """LEDGER: a stack temp handed to a sceVu0* call is a 16-byte vector;
    m2c's `s32 spXX` gives the wrong frame (func_00143290)."""
    names = set(re.findall(r"sceVu0\w+\([^;]*?&(sp[0-9A-F]+)\b", c))
    for n in names:
        c = re.sub(r"^(    )[\w ]+?\b%s;" % n, r"\1f32 %s[4];" % n, c, flags=re.M)
        c = re.sub(r"&%s\b" % n, n, c)
    return c


def cast_returns(c):
    """LEDGER: a caller that narrows a call's result (`(u8) f()`, an extension
    after the jal) calls a function returning s32 (func_00140DE0,
    func_001442F0); declare those callees so."""
    names = sorted(set(re.findall(r"\((?:u8|s8|u16|s16)\) ((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})\(", c)))
    names = [n for n in names if not re.search(r"^[^\s].*\b%s\(" % n, c, re.M)]
    if not names:
        return c
    decl = "".join(f"s32 {n}();\n" for n in names)
    return re.sub(r'^(#include "common.h"\n)', lambda m: m.group(1) + decl, c, count=1)


def one_case_switch(c, body):
    """LEDGER: `beq x, K, body; b end` is a one-case switch (func_001D9DC0);
    rewrite `if (x == K) { ... }` (no else) when the asm has that shape."""
    if not re.search(r"\bbeq\s+\$\w+, \$\w+, \.L\w+\n(?:.*\n)?.*\bb\s+\.L", body):
        return c
    def fix(m):
        ind, x, k, blk = m.group(1), m.group(2), m.group(3), m.group(4)
        blk = blk.replace("\n" + ind + "    ", "\n" + ind + "        ")
        return f"{ind}switch ({x}) {{\n{ind}case {k}:{blk}\n{ind}        break;\n{ind}}}\n"
    return re.sub(r"^( +)if \((.+?) == (-?(?:0x)?[0-9A-Fa-f]+U?)\) \{((?:\n\1    .*)+)\n\1\}\n(?!\1 *else)",
                  fix, c, count=1, flags=re.M)


def reverse_locals(c):
    """LEDGER: the order locals are declared in picks their registers
    (func_00195B10) as well as their stack slots; try the reverse order."""
    def fix(m):
        lines = m.group(0).splitlines(keepends=True)
        return "".join(reversed(lines)) if len(lines) > 1 else m.group(0)
    return re.sub(r"(?<=\{\n)(?:    (?!return)[\w ]+?[\s*]+\w+(?:\[\w+\])?;\n)+", fix, c)


def byte_offsets(c):
    """LEDGER: m2c adds byte offsets to typed pointers (`arg0 + 4` for a
    `s32 *arg0` meant 4 bytes, func_00174620; `var_4 += 4` on a `u8 ***`
    stepped one element, func_001A55E0); make the scaling explicit."""
    ptrs = {}
    for m in re.finditer(r"\b((?:s16|u16|s32|u32|f32|s64|u64|u8|s8)\s*(\*+))\s*(\w+)\b(?=[,;)])", c):
        t, stars, v = m.group(1), m.group(2), m.group(3)
        if t.startswith(("u8", "s8")) and len(stars) == 1:
            continue
        ptrs[v] = t.replace(" ", "")
    for v, t in ptrs.items():
        c = re.sub(r"(?<![*\w])%s \+ (0x[0-9A-Fa-f]+|\d+)\b" % v,
                   lambda m: f"({t})((u8 *){v} + {m.group(1)})", c)
        c = re.sub(r"\b%s \+= (0x[0-9A-Fa-f]+|\d+);" % v,
                   lambda m: f"{v} = ({t})((u8 *){v} + {m.group(1)});", c)
    return c


def symbol_byte_offsets(c):
    """LEDGER: the same byte offsets on typed global arrays
    (`D_003172E0 + (i << 5)`, func_0015FD90)."""
    decls = dict((m.group(2), m.group(1)) for m in
                 re.finditer(r"^extern ((?:s16|u16|s32|u32|f32|s64|u64)) ((?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8})\[\];", c, re.M))
    for sym, t in decls.items():
        out, i = [], 0
        for m in re.finditer(r"\b%s \+ \(" % sym, c):
            if m.start() < i:
                continue
            end = balanced(c, m.end() - 1)
            if end < 0:
                continue
            out.append(c[i:m.start()] + f"({t} *)((u8 *){sym} + {c[m.end() - 1:end]})")
            i = end
        out.append(c[i:])
        c = "".join(out)
    return c


def ascending_cases(c):
    """LEDGER: CodeWarrior's switch compare chain runs in reverse source order
    (func_001D1CB0); write each run of case labels ascending."""
    def key(l):
        v = re.search(r"case (-?(?:0x[0-9A-Fa-f]+|\d+))", l).group(1)
        return int(v, 0)

    def fix(m):
        lines = m.group(0).splitlines(keepends=True)
        labels = [l for l in lines if re.match(r"^\s*case -?(?:0x[0-9A-Fa-f]+|\d+):", l)]
        if len(labels) != len(lines):
            return m.group(0)
        return "".join(sorted(lines, key=key))
    c = re.sub(r"^\s*/\* fallthrough \*/\n", "", c, flags=re.M)
    return re.sub(r"(?:^\s*case -?(?:0x[0-9A-Fa-f]+|\d+):[^\n]*\n){2,}", fix, c, flags=re.M)


def compound_assign(c):
    """LEDGER: `x += k` and m2c's `x = (T) (x + k)` order the operands
    differently (func_001C9410)."""
    def fix(m):
        lhs, op, rhs = m.group(2), m.group(3), m.group(4)
        return f"{m.group(1)}{lhs} {op}= {rhs};"
    return re.sub(r"^(\s+)(.+?) = (?:\([\w ]+\) )?\(\2 ([-+*/|&^]) (.+)\);$", fix, c, flags=re.M)


RULES = [callee_prototypes, typed_indexing, base_first_index, bitfields, stack_order, ternary_sense, flip_return,
         vector_locals, cast_returns, reverse_locals, byte_offsets, compound_assign, symbol_byte_offsets,
         ascending_cases]
def float_zero_first(c, body):
    """LEDGER: `c.eq.s $zero_reg, $x` comes from `0.0f == x` (func_0014AAF0);
    m2c writes `x == 0.0f`."""
    zeros = set(re.findall(r"mtc1\s+\$0, (\$f\d+)", body))
    if not any(re.search(r"c\.eq\.s\s+\%s," % z, body) for z in zeros):
        return c
    return re.sub(r"\(([^()]+?) (==|!=) 0\.0f\)", r"(0.0f \2 \1)", c)


BODY_RULES = [at_compares, unsigned_counters, one_case_switch, float_zero_first]


def apply(c, body=""):
    for r in RULES:
        try:
            c = r(c)
        except Exception:
            pass
    for r in BODY_RULES:
        try:
            c = r(c, body)
        except Exception:
            pass
    return c


def each(c, body=""):
    """The output of every rule applied alone."""
    out = []
    for r in RULES:
        try:
            out.append(r(c))
        except Exception:
            pass
    for r in BODY_RULES:
        try:
            out.append(r(c, body))
        except Exception:
            pass
    return out


def all_but_prototypes(c, body=""):
    """Every rule except callee_prototypes (net harmful on its own per
    tools/m2c_rules_eval.py, though it wins on some functions)."""
    for r in RULES:
        if r is not callee_prototypes:
            try:
                c = r(c)
            except Exception:
                pass
    for r in BODY_RULES:
        try:
            c = r(c, body)
        except Exception:
            pass
    return c
