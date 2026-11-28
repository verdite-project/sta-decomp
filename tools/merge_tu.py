#!/usr/bin/env python3
"""Merge a run of one-function game files into one translation unit.

    tools/merge_tu.py src/game/func_A.c ... src/game/func_B.c   [--keep]

The files (in .text order, as tools/infer_tus.py --files lists a candidate)
become the first one: their #includes once, every typedef hoisted to the top
(a name parts spell differently, or one an included header defines
differently, renamed per part as NAME_<part>, repeated until nothing new
differs), one prototype per function (its definition's, else the parts'
unified one), then each part in turn with its own macros #undef'd after it.

A part that declares a function or extern object differently from the
merged file, or calls one it never declared (implicit int f()), keeps its
own view as NAME__as_<part>, #define'd over NAME for the part: ld gets
NAME__as_<part> = NAME (tools/rel_syms.py) and objdiff sees NAME
(tools/objdiff_base.py), so each part compiles as it did alone.

Then every function of the merged file must match (tools/match.py diff),
under the parts' config/game_cflags.txt flags (one unit, one compiler: parts
with different flags are not merged), and the link order must allow it: a
data-only unit between the parts goes before the merged unit or after it,
by whether earlier parts have data in its section, and one with the unit's
data on both sides blocks the merge (tools/move_data.py first). On success
the other files are deleted (git rm) and config/link_order.jp.txt,
game_cflags.txt and sta.jp.yaml updated (then rm -rf asm, ./build.sh); on
failure everything is put back and the reason printed, unless --keep.
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
class _Typedefs:
    """Top-level typedefs, braces balanced to any depth: finditer() gives
    match-like objects (group(0) the declaration with its newline, group(1)
    the name), sub("", text) removes them."""

    class M:
        def __init__(self, text, a, b, name):
            self.string, self._a, self._b, self._name = text, a, b, name

        def group(self, i=0):
            return self.string[self._a:self._b] if i == 0 else self._name

        def start(self, i=0):
            return self._a

    def __init__(self, fptr):
        self.fptr = fptr

    def finditer(self, text):
        for m in re.finditer(r"^typedef\b", text, re.M):
            i, depth = m.start(), 0
            while i < len(text):
                c = text[i]
                if c == "{":
                    depth += 1
                elif c == "}":
                    depth -= 1
                elif c == ";" and depth == 0:
                    break
                i += 1
            decl = text[m.start():i]
            fp = re.search(r"\(\s*\*\s*(\w+)\s*\)\s*\([^{}]*\)\s*$", decl)
            if bool(fp) != self.fptr:
                continue
            if fp:
                name = fp.group(1)
            else:
                tail = re.sub(r"__attribute__\(\((?:[^()]|\([^()]*\))*\)\)", "", decl[decl.rfind("}") + 1:] if "}" in decl else decl)
                ids = re.findall(r"\b(\w+)\b\s*(?:\[[^\]]*\]\s*)*$", tail.strip())
                if not ids:
                    continue
                name = ids[-1]
            end = i + 1
            nl = re.match(r"[ \t]*\n", text[end:])
            if nl:
                end += nl.end()
            yield self.M(text, m.start(), end, name)

    def sub(self, repl, text):
        out, last = [], 0
        for m in self.finditer(text):
            out.append(text[last:m.start()])
            out.append(repl)
            last = m._b
        out.append(text[last:])
        return "".join(out)


TYPEDEF = _Typedefs(False)
STATIC = re.compile(r"^(?:static|inline)\b[^;{=(]*?\b(\w+)\s*[\[(=;]", re.M)
FPTYPEDEF = _Typedefs(True)
INCLUDE = re.compile(r'^#include\s+["<][^">]+[">][ \t]*\n', re.M)


def expand_renames(body):
    """An earlier merge's `#define NAME NAME_<part>` ... `#undef NAME` span
    (a type renamed for one part), written out: the typedefs are hoisted
    out of the span now."""
    while True:
        m = re.search(r"^#define[ \t]+(\w+)[ \t]+(\1_\w+)[ \t]*\n", body, re.M)
        if not m:
            return body
        n, v = m.group(1), m.group(2)
        u = re.compile(rf"^#undef[ \t]+{n}[ \t]*\n", re.M).search(body, m.end())
        end = u.start() if u else len(body)
        span = re.sub(rf"\b{n}\b", v, body[m.end():end])
        body = body[:m.start()] + span + (body[u.end():] if u else "")


MULTI = re.compile(r"^extern[ \t]+([A-Za-z_][\w \t]*?)[ \t]+((?:\**[ \t]*\w+[ \t]*(?:\[[^\]\n]*\][ \t]*)*,[ \t]*)+"
                   r"\**[ \t]*\w+[ \t]*(?:\[[^\]\n]*\][ \t]*)*);[ \t]*\n", re.M)


def split_externs(body):
    """`extern T a[], *b;` -> one declaration per name (and one per line)."""
    while True:
        b2 = re.sub(r"^(extern\b[^\n;{}]*;)[ \t]*(?=extern\b)", r"\1\n", body, flags=re.M)
        if b2 == body:
            break
        body = b2
    return MULTI.sub(lambda m: "".join(f"extern {m.group(1)} {d.strip()};\n" for d in m.group(2).split(",")), body)


def parts(paths):
    out = []
    for p in paths:
        text = (ROOT / p).read_text()
        if p.endswith(".s"):
            # an asm chunk: its retail asm at this point (include/include_asm.h)
            m = re.search(r"^\s*glabel (\w+)", text, re.M)
            out.append((p, ['#include "include_asm.h"\n'], f"INCLUDE_ASM({m.group(1)});\n", {}, set()))
            continue
        incs = INCLUDE.findall(text)
        body = INCLUDE.sub("", text).strip("\n") + "\n"
        if p.startswith("src/game/data/") and re.search(r"^#pragma explicit_zero_data on", body, re.M):
            body += "#pragma explicit_zero_data reset\n"     # the data part's own setting
        body = expand_renames(body)
        body = split_externs(body)
        body = re.sub(r";[ \t]*/\*[^*\n]*\*/[ \t]*\n", ";\n", body)   # m2c's /* extern */
        tds = {m.group(1): m.group(0) for m in TYPEDEF.finditer(body)}
        tds.update({m.group(1): m.group(0) for m in FPTYPEDEF.finditer(body)})
        sts = set(STATIC.findall(body))
        out.append((p, incs, body, tds, sts))
    return out


# top-level only: a declaration starts at column 0 with a type word
PROTO = re.compile(r"^(?!typedef\b|static\b|return\b|else\b|if\b)(?:extern[ \t]+)?([A-Za-z_][\w \t\*]*?)[ \t\*]*\b(\w+)[ \t]*\(((?:[^;{}()]|\([^;{}()]*\))*)\)[ \t]*;[ \t]*\n", re.M)
DEFN = re.compile(r"^(?!static\b)([A-Za-z_][\w \t\*]*?)[ \t\*]*\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8})[ \t]*\(([^;{}()]*)\)\s*\{", re.M)


# char is not signed char to CodeWarrior (char * and s8 * do not convert)
ALIAS_T = {"float": "f32", "double": "f64", "int": "s32", "unsigned int": "u32"}


def norm(t):
    t = re.sub(r"\s+", " ", t.strip()).replace(" *", "*").replace("* ", "*")
    return ALIAS_T.get(t, t)


def param_list(params):
    """Parameter types, names dropped."""
    out = []
    for x in params.split(",") if params.strip() and params.strip() != "void" else []:
        x = norm(x)
        m = re.fullmatch(r"(.*?[\w\*])\s*\b([a-z_]\w*)", x)
        if m and m.group(2) not in ALIAS_T and not re.fullmatch(r"[su](8|16|32|64)|f(32|64)|void|const|volatile|unsigned|signed", m.group(2)) \
                and " " in x.replace("*", "* ").strip():
            x = norm(m.group(1))
        out.append(ALIAS_T.get(x, x))
    return out


def unify(sigs):
    """One prototype for several (ret, params) spellings, or None: the same
    but for what pointer parameters point at (those become void *)."""
    rets = {norm(r) for r, _ in sigs}
    lists = [param_list(p) for _, p in sigs]
    if len(rets) == 2 and "void" in rets:
        rets.discard("void")        # a part that ignores the result declared it void
    if len(rets) != 1 and all(r in ("s32", "u32") for r in rets):
        rets = {"s32"}
    if len(rets) != 1 or len({len(l) for l in lists}) != 1:
        return None
    out = []
    for col in zip(*lists):
        if len(set(col)) == 1:
            out.append(col[0])
        elif all(c.endswith("*") for c in col):
            out.append("void *")
        elif set(col) <= {"s32", "u32", "int", "unsigned int"} or set(col) <= {"s16", "u16"} \
                or set(col) <= {"s8", "u8", "char"}:
            out.append(col[0])      # the same register either way
        else:
            return None
    return rets.pop(), out


HEADER_TYPES = None


def visible_types():
    """Type names the headers give (and the basic ones)."""
    global HEADER_TYPES
    if HEADER_TYPES is None:
        text = "".join(p.read_text() for p in list((ROOT / "include").glob("*.h")) + list((ROOT / "src/game").glob("*.h")))
        HEADER_TYPES = set(re.findall(r"\}\s*(\w+)\s*(?:__attribute__\(\([^;]*\)\))?\s*;", text)) \
            | set(re.findall(r"typedef\s+[\w\s\*]+?\b(\w+)\s*;", text)) \
            | {"void", "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "char", "int",
               "short", "long", "float", "double", "unsigned", "signed", "const", "volatile", "struct"}
    return HEADER_TYPES


def from_definition(name):
    """The signature of a C function defined in its own file, with any type
    local to that file written as void * (pointers) -- or None."""
    p = ROOT / "src/game" / f"{name}.c"
    if not p.exists():
        return None
    m = re.search(rf"^(?!static\b)([A-Za-z_][\w \t\*]*?)[ \t\*]*\b{name}[ \t]*\(([^;{{}}()]*)\)\s*\{{",
                  p.read_text(), re.M)
    if not m:
        return None
    # the return type: a pointer star may sit with the name
    whole = m.group(0)
    ret = norm(whole[:whole.index(name)])
    ok = visible_types()

    def fix(t):
        words = set(re.findall(r"[A-Za-z_]\w*", t))
        if words <= ok:
            return t
        return "void *" if t.endswith("*") else None
    r = fix(ret)
    ps = [fix(x) for x in param_list(m.group(2))]
    if r is None or None in ps:
        return None
    return r, ps


class _Externs:
    """Top-level extern object declarations (not functions), braces
    balanced: `extern struct {...} D;`, `extern s32 (*D[])(T *);`. Match
    objects give group(0) (with its newline), group(3) the name, start(3)
    where it is, and key(): the declaration with the name taken out and the
    first array bound dropped (an incomplete array is compatible)."""

    class M:
        def __init__(self, text, a, b, name, at, owner):
            self.string, self._a, self._b, self._name, self._at, self.re = text, a, b, name, at, owner

        def group(self, i=0):
            return self.string[self._a:self._b] if i == 0 else self._name

        def start(self, i=0):
            return self._at if i == 3 else self._a

        def key(self):
            d = self.string[self._a:self._at] + "@" + self.string[self._at + len(self._name):self._b]
            d = re.sub(r"\s+", " ", d.strip()).replace(" *", "*").replace("* ", "*")
            d = re.sub(r"@\s*\[[^\]]*\]", "@[]", d)
            for k, v in ALIAS_T.items():
                d = re.sub(rf"\b{k}\b", v, d)
            return d

    def finditer(self, text):
        for m in re.finditer(r"^extern\b", text, re.M):
            i, depth = m.start(), 0
            while i < len(text):
                c = text[i]
                if c == "{":
                    depth += 1
                elif c == "}":
                    depth -= 1
                elif c == ";" and depth == 0:
                    break
                i += 1
            decl = text[m.start():i]
            flat = re.sub(r"\{.*\}", "{}", decl, flags=re.S)
            flat = re.sub(r"__attribute__\(\((?:[^()]|\([^()]*\))*\)\)", "", flat)
            fp = re.search(r"\(\s*\*+\s*(\w+)", flat)
            if fp:
                name = fp.group(1)
            elif re.search(r"\w\s*\(", flat):
                continue                # a function
            else:
                ids = re.findall(r"\b(\w+)\s*(?:\[[^\]]*\]\s*)*$", flat.strip())
                if not ids:
                    continue
                name = ids[-1]
            # the name's position: its whole-word occurrence outside braces
            close = decl.rfind("}")
            pos = [x.start() for x in re.finditer(rf"\b{name}\b", decl) if x.start() > close]
            if not pos:
                continue
            at = m.start() + (pos[0] if fp else pos[-1])
            end = i + 1
            nl = re.match(r"[ \t]*\n", text[end:])
            if nl:
                end += nl.end()
            yield self.M(text, m.start(), end, name, at, self)

    def sub(self, fn, text):
        out, last = [], 0
        for m in list(self.finditer(text)):
            out.append(text[last:m.start()])
            out.append(fn(m))
            last = m._b
        out.append(text[last:])
        return "".join(out)


EXTERN = _Externs()
DEFN_ANY = re.compile(r"^(?!static\b|typedef\b)([A-Za-z_][\w \t\*]*?)[ \t\*]*\b(\w+)[ \t]*\(((?:[^;{}()]|\([^;{}()]*\))*)\)\s*\{", re.M)
CONTROL = {"if", "while", "for", "switch", "return", "else", "do", "sizeof"}


def sig_key(ret, params):
    return norm(ret), tuple(param_list(params))


def decl_text(ret, name, params):
    ret = norm(ret)
    return f"{ret} {name}({params.strip()});\n"



def header_decls(includes):
    """What the included headers (include/, and theirs) declare: typedef
    names -> spelling, extern objects and prototypes."""
    out = {"types": {}, "externs": {}, "protos": {}}
    todo = [re.search(r'["<]([^">]+)[">]', i).group(1) for i in includes]
    seen = set()
    while todo:
        h = todo.pop()
        if h in seen or not (ROOT / "include" / h).exists():
            continue
        seen.add(h)
        text = (ROOT / "include" / h).read_text()
        todo += re.findall(r'^#include\s+["<]([^">]+)[">]', text, re.M)
        for m in list(TYPEDEF.finditer(text)) + list(FPTYPEDEF.finditer(text)):
            out["types"][m.group(1)] = re.sub(r"\s+", " ", m.group(0).strip())
        for m in EXTERN.finditer(text):
            out["externs"][m.group(3)] = m
        for m in PROTO.finditer(text):
            if not m.group(0).startswith("extern"):
                out["protos"][m.group(2)] = (m.group(0)[:m.start(2) - m.start()], m.group(3))
    return out


def merge(paths, bss=None):
    """Typedefs (renamed per part where parts spell one differently) go to
    the top, then one prototype per function: its definition's, else the
    unified or first declaration. A part that declares a function or an
    extern object differently keeps its own view under NAME__as_<part>
    (#define'd over NAME for the part): ld gets NAME__as_<part> = NAME
    (tools/rel_syms.py) and objdiff sees NAME (tools/objdiff_base.py), so
    each part compiles exactly as it did alone."""
    ps = parts(paths)
    static_count = {}
    for _, _, _, _, sts in ps:
        for n in sts:
            static_count[n] = static_count.get(n, 0) + 1
    # a typedef spelled differently in two parts is renamed in each; renaming
    # one can make another that names it differ (List of a renamed Elem), so
    # until nothing changes
    hdr = header_decls([i for _, incs, *_ in ps for i in incs])
    # a part's own typedef of a name an included header defines: dropped when
    # spelled the same, else renamed for the part
    rename = []
    for k, (p, incs, body, tds, sts) in enumerate(ps):
        ren = set(n for n in sts if static_count[n] > 1)
        for n, t in tds.items():
            if n in hdr["types"]:
                if re.sub(r"\s+", " ", t.strip()) == hdr["types"][n]:
                    body = body.replace(t, "", 1)
                else:
                    ren.add(n)
        tds = {n: t for n, t in tds.items() if n in ren or n not in hdr["types"]}
        ps[k] = (p, incs, body, tds, sts)
        rename.append(ren)
    while True:
        bodies, spellings, tags = [], {}, []
        for (p, _, body, tds, _), ren in zip(ps, rename):
            tag = Path(p).stem
            # an already merged part may hold NAME_<tag> from its own merge
            while any(re.search(rf"\b{n}_{tag}\b", b) for n in ren for _, _, b, _, _ in ps):
                tag += "_"
            tags.append(tag)
            for n in ren:
                body = re.sub(rf"\b{n}\b", f"{n}_{tag}", body)
            bodies.append(body)
            for n, t in tds.items():
                if n in ren:
                    continue
                t2 = next((x.group(0) for x in list(TYPEDEF.finditer(body)) + list(FPTYPEDEF.finditer(body))
                           if x.group(1) == n), t)
                spellings.setdefault(n, set()).add(re.sub(r"\s+", " ", t2.strip()))
        grew = False
        for (_, _, _, tds, _), ren in zip(ps, rename):
            for n in tds:
                if n not in ren and len(spellings.get(n, ())) > 1:
                    ren.add(n)
                    grew = True
        if not grew:
            break
    # hoist typedefs in order, once each
    hoisted, seen = [], set()
    for k, body in enumerate(bodies):
        for m in sorted(list(TYPEDEF.finditer(body)) + list(FPTYPEDEF.finditer(body)), key=lambda m: m.start()):
            t = m.group(0)
            key = re.sub(r"\s+", " ", t.strip())
            if key not in seen:
                seen.add(key)
                hoisted.append(t)
        bodies[k] = FPTYPEDEF.sub("", TYPEDEF.sub("", body))
    # functions
    defs = {}
    for body in bodies:
        for m in DEFN_ANY.finditer(body):
            if m.group(2) in CONTROL:
                continue
            whole = m.group(0)
            defs[m.group(2)] = (whole[:m.start(2) - m.start()], m.group(3))
    decls = {}
    for body in bodies:
        for m in PROTO.finditer(body):
            decls.setdefault(m.group(2), []).append((m.group(0)[:m.start(2) - m.start()].replace("extern", ""),
                                                       m.group(3)))
    canon = dict(hdr["protos"])
    for name, (r, pa) in defs.items():
        canon[name] = (r, pa)
    for name, sigs in decls.items():
        if name in canon:
            continue
        sigs = [x for x in sigs if x[1].strip()] or sigs
        keys = {sig_key(r, pa) for r, pa in sigs}
        if len(keys) == 1:
            canon[name] = sigs[0]
            continue
        u = unify([(r, pa) for r, pa in sigs])
        canon[name] = (u[0], ", ".join(u[1])) if u else sigs[0]
    protos = [decl_text(r, n, pa) for n, (r, pa) in canon.items()
              if not (n in defs and re.match(r"\s*static\b", r))]
    # extern objects: the first declaration is the one; a different one
    # elsewhere becomes a cast of it
    ext_first = dict(hdr["externs"])
    # the unit's .bss block (tools/absorb_bss.py): the first declaration of
    # each name it defines; the parts' own definitions leave their bodies
    block, defined = "", set()
    if bss:
        block, removed, _ = bss
        for line in removed:
            for k, body in enumerate(bodies):
                if line + "\n" in body:
                    bodies[k] = body.replace(line + "\n", "", 1)
                    break
            else:
                raise SystemExit(f"no part defines {line!r}")
        for line in block.split("\n"):
            if re.match(r"[A-Za-z_]", line):
                plain = re.sub(r"\s*__attribute__\(\((?:[^()]|\([^()]*\))*\)\)", "", line.split(";")[0])
                for m in EXTERN.finditer(f"extern {plain};\n"):
                    ext_first[m.group(3)] = m
                    defined.add(m.group(3))
    # initialised data a data-only part defines (tools/data_to_c.py): every
    # other part keeps it extern, as alone (a visible const would be folded)
    data_defined = set()
    for (p, *_), body in zip(ps, bodies):
        if p.startswith("src/game/data/"):
            data_defined |= {m.group(1) for m in re.finditer(r"^(?:static\s+)?const\b[^;=\n]*?\b((?:D|g[A-Z][A-Za-z0-9]*)_[0-9A-F]{8})\b", body, re.M)}
    for body in bodies:
        for m in EXTERN.finditer(body):
            ext_first.setdefault(m.group(3), m)
    ext_decls = []
    for n, m in ext_first.items():
        if n in hdr["externs"] or n in defined or n in data_defined:
            continue
        ext_decls.append(m.group(0))

    def ext_key(m):
        return m.key()

    out = []
    for k, ((p, _, orig, _, _), body) in enumerate(zip(ps, bodies)):
        tag = Path(p).stem
        while f"__as_{tag}" in body:      # an already merged part has its own
            tag += "_"
        undef = []

        def alias(m, name):
            first = name not in undef
            undef.append(name)
            k = m.start(3 if m.re is EXTERN else 2) - m.start()
            decl = m.group(0)[:k] + f"{name}__as_{tag}" + m.group(0)[k + len(name):]
            return (f"#define {name} {name}__as_{tag}\n" if first else "") + decl

        def fproto(m):
            name = m.group(2)
            r = m.group(0)[:m.start(2) - m.start()].replace("extern", "")
            if sig_key(r, m.group(3)) == sig_key(*canon[name]):
                return ""
            if not m.group(3).strip():
                # unprototyped: only a function defined in the unit has a
                # prototype the part did not see (calls before it unchecked)
                if name not in defs or not canon[name][1].strip():
                    return ""
            return alias(m, name)
        body = PROTO.sub(fproto, body)
        # a part defining a name it aliased: the definition is the real name
        for name in [n for n in dict.fromkeys(undef) if n in defs]:
            dm = re.search(rf"^(?!static\b)[A-Za-z_][\w \t\*]*?\b{name}[ \t]*\([^;{{}}]*\)\s*\{{", body, re.M)
            if dm:
                body = body[:dm.start()] + f"#undef {name}\n" + body[dm.start():]

        def fext(m):
            n = m.group(3)
            if n in data_defined:
                return alias(m, n)
            if ext_key(m) == ext_key(ext_first[n]):
                return ""
            return alias(m, n)
        body = EXTERN.sub(fext, body)
        # a call with no declaration in the part: alone it was implicit (int
        # f()); declared now by another part, it keeps that view
        own = {m.group(2) for m in PROTO.finditer(orig)} | {m.group(2) for m in DEFN_ANY.finditer(orig)} \
            | {m.group(3) for m in EXTERN.finditer(orig)} | set(hdr["protos"])
        own |= {f"{n}_{tags[k]}" for n in rename[k] if n in own}   # renamed statics/inlines
        implicit = []
        for name in sorted(set(re.findall(r"\b((?:func|[A-Za-z]\w*?_[0-5])_[0-9A-F]{8}|\w+)\s*\(", body)) & set(canon) - own):
            if name not in undef:
                implicit.append(name)
                undef.append(name)
        head = "".join(f"#define {n} {n}__as_{tag}\nint {n}__as_{tag}();\n" for n in implicit)
        body = head + body
        # the part's own macros end with it; one over an aliased name expands
        # to the alias itself
        for m in list(re.finditer(r"^#define[ \t]+(\w+)\b(?!\()[ \t]*(.*)$", body, re.M)):
            n, val = m.group(1), m.group(2)
            if val == f"{n}__as_{tag}":
                continue
            if "__as_" not in val and f"#define {n} {n}__as_{tag}\n" in body:
                body = body.replace(f"#define {n} {n}__as_{tag}\n", "", 1)
                body = re.sub(rf"^#define[ \t]+{n}\b[ \t]*{re.escape(val)}$",
                              f"#define {n} " + re.sub(rf"\b{n}\b", f"{n}__as_{tag}", val).replace("\\", "\\\\"),
                              body, count=1, flags=re.M)
            undef.append(n)
        tail = "".join(f"#undef {n}\n" for n in dict.fromkeys(undef))
        out.append(f"/* {tag} */\n" + body.strip("\n") + "\n" + tail)
    includes = []
    for _, incs, *_ in ps:
        for i in incs:
            if i not in includes:
                includes.append(i)
    return ("".join(includes) + "".join(hoisted) + "".join(ext_decls) + "".join(protos)
            + "\n" + block + "\n".join(out))


LINK_ORDER = ROOT / "config/link_order.jp.txt"


def data_sections(path, text=None):
    """The data sections a part (its source, or TEXT) has bytes in, compiled
    afresh: a stale object may already be a merged unit."""
    import tempfile
    from elftools.elf.elffile import ELFFile
    src = ROOT / path
    tmp_src = None
    if text is not None:
        tmp_src = src.with_name("zz_relink_" + src.name)
        tmp_src.write_text(text)
        src = tmp_src
    with tempfile.TemporaryDirectory() as d:
        o = Path(d) / "part.o"
        r = subprocess.run(["tools/compile_c.sh", str(src.relative_to(ROOT)), str(o)], cwd=ROOT,
                           capture_output=True)
        if tmp_src:
            tmp_src.unlink()
        if r.returncode:
            return set()
        with open(o, "rb") as f:
            return {s.name for s in ELFFile(f).iter_sections()
                    if s.name in (".rodata", ".data", ".bss", ".sdata", ".sbss") and s["sh_size"]}


def head(paths):
    """The merged unit's file: the first C part (a unit may start with an
    INCLUDE_ASM'd chunk)."""
    return next(p for p in paths if p.endswith(".c"))


def inside_data(paths, secs):
    """[(data-only unit, section)] between the parts with the unit's data on
    both sides: the unit's own data."""
    lines = LINK_ORDER.read_text().split("\n")
    idx = [lines.index(p) for p in paths]
    lo, hi = min(idx), max(idx)
    out = []
    for k in range(lo, hi + 1):
        line = lines[k]
        if line in paths or not line.startswith("src/game/data/"):
            continue
        sec = "." + Path(line).name.split("_")[0]
        if any(sec in secs.get(p, ()) for p in lines[lo:k] if p in paths) \
                and any(sec in secs.get(p, ()) for p in lines[k + 1:hi + 1] if p in paths):
            out.append((line, sec))
    return out


def relink(paths, secs):
    """config/link_order.jp.txt: the parts become the first one. A data-only
    unit that sat between parts goes before the merged unit when no part
    before it has data in its section, else after it (a unit's data is one
    stretch); None when parts on both sides do (the data is the unit's own:
    tools/move_data.py first)."""
    lines = LINK_ORDER.read_text().split("\n")
    idx = [lines.index(p) for p in paths]
    lo, hi = min(idx), max(idx)
    before, after = [], []
    for k in range(lo, hi + 1):
        line = lines[k]
        if line in paths:
            continue
        sec = "." + Path(line).name.split("_")[0]
        early = any(sec in secs.get(p, ()) for p in lines[lo:k] if p in paths)
        late = any(sec in secs.get(p, ()) for p in lines[k + 1:hi + 1] if p in paths)
        if early and late:
            return f"{line} lies inside the unit's {sec}"
        (after if early else before).append(line)
    chunks = [p for p in paths if p.endswith(".s")]     # INCLUDE_ASM'd: still linked
    LINK_ORDER.write_text("\n".join(lines[:lo] + before + [head(paths)] + chunks + after + lines[hi + 1:]))
    return None


YAML = ROOT / "config/sta.jp.yaml"


def resplit(paths):
    """config/sta.jp.yaml: the parts' c subsegments go (the first one's spans
    the unit), their data subsegments take the first one's name, and runs of
    one name collapse. Then rm -rf asm and ./build.sh."""
    names = {p[len("src/"):-len(".c")] for p in paths if p.endswith(".c") and p != head(paths)}
    first = head(paths)[len("src/"):-len(".c")]
    chunks = {Path(p).stem for p in paths if p.endswith(".s")}
    out, prev = [], None
    for l in YAML.read_text().split("\n"):
        # `- [0xADDR, type, name]` and `- { start: ..., type: .bss, ..., name: name }`
        r = re.match(r"(\s*- \[0x[0-9A-F]+, )(\S+), (\S+)\]$", l)
        d = None if r else re.match(r"(\s*- \{.*\btype: )(\S+)(, .*\bname: )(\S+)( \})$", l)
        typ, name = (r.group(2), r.group(3)) if r else (d.group(2), d.group(4)) if d else (None, None)
        if name in names:
            # a C part's code goes into the first part's subsegment, except
            # right after one of the unit's INCLUDE_ASM'd chunks: the unit
            # resumes there under its own name (splat writes both ranges'
            # functions to its asm/matchings directory)
            if typ == "c" and not (prev and prev[0] == "asm" and prev[1] in chunks):
                continue
            l = f"{r.group(1)}{typ}, {first}]" if r else f"{d.group(1)}{typ}{d.group(3)}{first}{d.group(5)}"
        key = (typ, first if name in names else name) if typ else None
        if key and key == prev and key[0] != "c":
            continue
        out.append(l)
        prev = key
    YAML.write_text("\n".join(out))


CFLAGS = ROOT / "config/game_cflags.txt"


def cflags(paths):
    """config/game_cflags.txt: the parts' flags become the merged unit's (one
    unit, one compiler). None when the parts have different ones; else the
    file's old text, to put back."""
    text = CFLAGS.read_text()
    lines = text.split("\n")
    have = {l.split(None, 1)[0]: l.split(None, 1)[1] for l in lines
            if l.strip() and not l.startswith("#") and len(l.split(None, 1)) == 2}
    flags = {have.get(p) for p in paths if p.endswith(".c")} - {None}
    if len(flags) > 1:
        return None
    if not flags:
        return text
    f = flags.pop()
    out, done = [], False
    for l in lines:
        if l.split(None, 1)[:1] and l.split(None, 1)[0] in paths:
            if not done:
                out.append(f"{head(paths)} {f}")
                done = True
            continue
        out.append(l)
    CFLAGS.write_text("\n".join(out))
    return text


def check(path):
    r = subprocess.run([str(ROOT / ".venv/bin/python"), "tools/match.py", "diff", str(path)],
                       capture_output=True, text=True, cwd=ROOT)
    text = r.stdout + r.stderr
    bad = [l for l in text.splitlines() if re.search(r"differ|rror|failed", l)]
    return (not bad and "MATCH" in text), text


def main():
    paths = [a for a in sys.argv[1:] if a.startswith(("src/", "asm/"))]
    keep = "--keep" in sys.argv
    saved = {p: (ROOT / p).read_text() for p in paths}
    secs = {p: data_sections(p) for p in paths if p.endswith(".c")}
    try:
        merged = merge(paths)
    except SystemExit as e:
        print(f"{paths[0]}..{Path(paths[-1]).name}: not merged ({e})")
        return 1
    # a .bss data-only unit inside the unit is the unit's own
    # (tools/absorb_bss.py: defined in it, small runs grouped)
    inside = inside_data(paths, secs)
    absorbed, groups = [], []
    if inside and all(sec in (".rodata", ".data") for _, sec in inside):
        # initialised data inside the unit: a part of it, at its place
        order = LINK_ORDER.read_text().split("\n")
        paths = sorted(paths + [u for u, _ in inside], key=order.index)
        saved.update({u: (ROOT / u).read_text() for u, _ in inside})
        secs.update({u: data_sections(u) for u, _ in inside})
        merged = merge(paths)
        inside = []
    if inside and all(sec == ".bss" for _, sec in inside):
        import absorb_bss
        try:
            bss = absorb_bss.absorb(merged, [u for u, _ in inside])
            merged, groups = merge(paths, bss), bss[2]
            absorbed = [u for u, _ in inside]
        except SystemExit as e:
            print(f"{paths[0]}..{Path(paths[-1]).name}: not merged (.bss: {e})")
            return 1
    first = ROOT / head(paths)
    first.write_text(merged)
    for p in paths:
        if p.endswith(".c") and p != head(paths):
            (ROOT / p).unlink()
    old_cflags = cflags(paths)
    if old_cflags is None:
        ok, text = False, "the parts' config/game_cflags.txt flags differ"
    else:
        ok, text = check(first)
    if (ok or keep) and absorbed:
        lines = [l for l in LINK_ORDER.read_text().split("\n") if l not in absorbed]
        LINK_ORDER.write_text("\n".join(lines))
        y = YAML.read_text()
        for u in absorbed:
            y = y.replace(f"name: {u[len('src/'):-len('.c')]} }}", f"name: {head(paths)[len('src/'):-len('.c')]} }}")
            subprocess.run(["git", "rm", "-q", u], cwd=ROOT)
        YAML.write_text(y)
        absorb_bss.record(groups)
    why = relink(paths, secs) if ok or keep else None
    if why:
        ok, keep, text = False, False, f"link order: {why}"
    if ok or keep:
        resplit(paths)
        for p in paths:
            if p.endswith(".c") and p != head(paths):
                subprocess.run(["git", "rm", "-q", "--cached", p], cwd=ROOT)
        # the link script's .text order follows the INCLUDE_ASM markers
        subprocess.run([str(ROOT / ".venv/bin/python"), "tools/gen_ninja.py"], cwd=ROOT,
                       capture_output=True)
        print(f"{head(paths)}: merged {len(paths)} files" + ("" if ok else " (kept, does not match)"))
        if not ok:
            print(text)
        return 0
    for p, t in saved.items():
        if p.endswith(".c"):
            (ROOT / p).write_text(t)
    if old_cflags is not None:
        CFLAGS.write_text(old_cflags)
    print(f"{paths[0]}..{Path(paths[-1]).name}: not merged\n" +
          "\n".join(l for l in text.splitlines() if re.search(r"differ|rror|Error|failed|link order|flags|#", l))[:2000])
    return 1


if __name__ == "__main__":
    sys.exit(main())
