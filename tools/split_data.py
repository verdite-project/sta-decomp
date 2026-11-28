#!/usr/bin/env python3
"""Give data objects to their owners in the NONMATCHING build.

    tools/split_data.py [--unit src/game/data/X.c ...] [--limit N]           plan
    tools/split_data.py [--unit ...] [--limit N] --apply

The matching build needs each data-only unit (src/game/data/) whole, at the
retail address; where tools/move_data.py cannot move an object into its
owner for both builds, this gives the owner a twin of it under
`#ifdef NONMATCHING` and puts the data unit's definition under
`#ifndef NONMATCHING`. The matching build compiles the same code as before;
tools/check_data_twins.py checks that the two definitions give the same
bytes (this script checks each twin the same way before it writes it).

Owner (tools/data_owners.py's inventory, build/data_owners.json, made from
a NONMATCHING build): the one C unit that uses the object; for several, the
one named like the data unit, else the one naming it most often. Objects
only data or a still-linked asm chunk uses, and objects nothing uses, stay.

The twin is written in the owner's declared type (the owner's `extern`, or
the subsystem header's): a .bss object as that type, an unsized array
`[size / sizeof(element)]`; an initialised one rebuilt from splat's bytes
(tools/data_to_c.py's define(), as move_data.py does). A twin whose
compiled bytes, size or relocations differ from the data unit's stays out.
A twin is `static` when only its owner names it (no other unit, data, asm
chunk or field alias) and the owner's own one-name `extern` declares it:
that `extern` then goes under `#ifndef NONMATCHING` and the twin stands in
its place. Every other twin is a global at the end of the owner, after a
`/* data twins (UNIT): NAMES */` line that data_owners.py and
check_data_twins.py read.
"""
import collections
import json
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import check_data_twins as ct  # noqa: E402
import data_to_c  # noqa: E402
import move_data  # noqa: E402
from names import is_func  # noqa: E402

UNINIT = {"bss", "sbss"}
ALIGNED = re.compile(r"\s*__attribute__\(\(aligned\((\d+)\)\)\)")
EXT_STMT = re.compile(r"^[ \t]*extern\s+((?:[^;(){}]|__attribute__\(\(\w+(?:\([^()]*\))?\)\))*?);[^\n]*\n?", re.M)
ATTR = re.compile(r"\s*__attribute__\(\(\w+(?:\([^()]*\))?\)\)")
FIRST = re.compile(r"^(?P<spec>(?:\w+\s+)*?\w+)\s*(?P<ptr>\**)\s*(?P<name>\w+)\s*(?P<dims>(?:\[[^\]]*\]\s*)*)"
                   r"(?P<attr>__attribute__\(\(.*\)\))?\s*$")
REST = re.compile(r"^\s*(?P<ptr>\**)\s*(?P<name>\w+)\s*(?P<dims>(?:\[[^\]]*\]\s*)*)(?P<attr>__attribute__\(\(.*\)\))?\s*$")


def externs(text):
    """name -> dict(spec, ptr, dims [str], single, start, end, stmt)."""
    out = {}
    for m in EXT_STMT.finditer(text):
        parts = ATTR.sub("", m.group(1)).split(",")
        f = FIRST.match(parts[0].strip())
        if not f:
            continue
        decls = [f] + [REST.match(p) for p in parts[1:]]
        if any(d is None for d in decls):
            continue
        for d in decls:
            out.setdefault(d.group("name"), []).append(dict(
                spec=f.group("spec"), ptr=d.group("ptr"),
                dims=[x.strip()[1:-1].strip() for x in re.findall(r"\[[^\]]*\]", d.group("dims"))],
                single=len(decls) == 1, start=m.start(), end=m.end(), stmt=m.group(0)))
    return out


def headers_text():
    return "".join(p.read_text() for p in sorted((ROOT / "include").rglob("*.h")))


def def_line(text, name):
    """The data unit's one-line definition of name: (start, end, line)."""
    for m in re.finditer(rf"^(?!\s*(?:extern|#|/\*|typedef))[^\n;(]*\b{re.escape(name)}\b\s*(?:\[[^\]]*\])*"
                         rf"[^\n;]*;[^\n]*$", text, re.M):
        return m.start(), m.end(), m.group(0)
    return None


def labels_of(unit, kind):
    asm = ROOT / "asm/data/game/data" / f"{Path(unit).stem}.{kind}.s"
    if not asm.exists():
        return {}
    return {lab[0]: lab for lab in data_to_c.parse(asm)}


def twin(rec, own_ext, hdr_ext, labels, local, owner_text):
    """((definition, extra declarations), where) or (None, reason)."""
    n = rec["name"]
    for where, ex in (("owner", own_ext), ("header", hdr_ext)):
        if n in ex:
            if len(ex[n]) > 1:
                return None, "several externs"
            e = ex[n][0]
            break
    else:
        return None, "no extern"
    spec, ptr, dims = e["spec"], e["ptr"], e["dims"]
    words = spec.split()
    base = words[-1]
    if base in ("struct", "union", "enum"):
        return None, "tagged type"
    size = rec["size"]
    u = def_line((ROOT / rec["unit"]).read_text(), n)
    attr = ALIGNED.search(u[2]) if u else None
    attr = f" __attribute__((aligned({attr.group(1)})))" if attr else ""
    if any(d == "" for d in dims[1:]):
        return None, "unsized inner dimension"
    es0 = move_data.type_size(base, ptr, owner_text) if not dims else None
    if not dims and es0 is not None and size != es0:
        # a scalar on an object carve sized to the next label: the rest is
        # padding when it is zero and no code reaches into it
        if size < es0:
            return None, "view: smaller than its type"
        if rec.get("reach", 0) >= es0:
            return None, "code reaches past its type"
    if rec["section"] in UNINIT:
        if dims and dims[0] == "":
            rest = "".join(f"[{d}]" for d in dims[1:])
            es = move_data.type_size(base, ptr, owner_text) if not rest else None
            if es and size % es == 0:
                ds = f"[{size // es:#x}]"
            else:
                ds = f"[{size:#x} / sizeof({spec}{' ' + ptr if ptr else ''}{rest})]" + rest
        else:
            ds = "".join(f"[{d}]" for d in dims)
        return (f"{spec} {ptr}{n}{ds}{attr};", []), where
    if len(dims) > 1:
        return None, "initialised, several dimensions"
    lab = labels.get(n)
    if lab is None:
        return None, "no splat label"
    need = set()
    items = lab[2]
    es = move_data.type_size(base, ptr, owner_text)
    num = lambda v: re.fullmatch(r"-?(0x[0-9A-Fa-f]+|\d+)", v)
    if not dims and es and es % 4 == 0 and all(i[0] == "word" for i in items) \
            and 4 * len(items) > es and all(num(i[1]) and int(i[1], 0) == 0 for i in items[es // 4:]):
        items = items[:es // 4]
    elif not dims and es:
        # cut the items at the type's size, if that falls on an item and the rest is zero
        width = {"word": 4, "short": 2, "byte": 1}
        acc, cut = 0, None
        for k, i in enumerate(items):
            if acc == es:
                cut = k
                break
            acc += width.get(i[0], 10 ** 6)
        if cut is not None and all(i[0] in width and num(i[1]) and int(i[1], 0) == 0 for i in items[cut:]):
            items = items[:cut]
    cache = data_to_c.struct_scalar.__defaults__[0]
    data_to_c.struct_scalar("")
    added = {k: v for k, v in local.items() if k not in cache}
    cache.update(added)
    try:
        d = data_to_c.define(n, items, {n: {(base, ptr, bool(dims))}}, False, need, lab[3])
    finally:
        for k in added:
            cache.pop(k, None)
    shape = re.match(rf"{re.escape(base)}\s*{re.escape(ptr)}\s*{re.escape(n)}\s*(\[)?", d) if d else None
    quals = " ".join(words[:-1])
    if shape is None or bool(shape.group(1)) != bool(dims):
        d = None if ptr else struct_init(n, base, dims, quals, items, owner_text, need)
        if d is None:
            return None, "type does not fit"
    elif quals:
        d = f"{quals} {d}"
    if attr:
        d = d.replace(" = ", f"{attr} = ", 1)
    ext = [f"void {s}(void);" if is_func(s) else f"extern u8 {s}[];"
           for s in sorted(need) if not re.search(rf"\b{s}\b", owner_text)]
    return (d, ext), where


TYPEDEF_STRUCT = re.compile(r"typedef\s+struct\s*\w*\s*\{(?P<body>[^{}]*)\}\s*(?P<name>\w+)\s*"
                            r"(?:__attribute__\(\(\w+(?:\([^()]*\))?\)\)\s*)?;")
MEMBER = re.compile(r"^(?P<type>(?:(?:unsigned|signed|const|volatile)\s+)*\w+)\s+(?P<decls>[^;]+)$")


def struct_defs(text):
    return {m.group("name"): m.group("body") for m in TYPEDEF_STRUCT.finditer(text)}


def layout(t, defs, depth=0):
    """(size, align, [(offset, scalar type, ptr)]) of a type, or None for one
    this cannot lay out (bitfields, unions, nested anonymous structs)."""
    if t in data_to_c.ESZ or t in ("u64", "s64"):
        n = data_to_c.ESZ.get(t, 8)
        return n, n, [(0, t, "")]
    if t not in defs or depth > 8:
        return None
    off, align, flat = 0, 1, []
    for d in defs[t].split(";"):
        d = " ".join(d.split())
        if not d:
            continue
        m = MEMBER.match(d)
        if not m or ":" in d or "(" in d:
            return None
        mt = m.group("type").split()[-1]
        for v in m.group("decls").split(","):
            v = v.strip()
            vm = re.fullmatch(r"(\**)\s*\w+\s*((?:\[[^\]]+\]\s*)*)", v)
            if not vm:
                return None
            k = 1
            for dim in re.findall(r"\[([^\]]+)\]", vm.group(2)):
                try:
                    k *= int(dim, 0)
                except ValueError:
                    return None
            if vm.group(1):
                es, ea, ef = 4, 4, [(0, mt, "*")]
            else:
                lo = layout(mt, defs, depth + 1)
                if lo is None:
                    return None
                es, ea, ef = lo
            off = (off + ea - 1) // ea * ea
            align = max(align, ea)
            for i in range(k):
                flat += [(off + i * es + o, st, sp) for o, st, sp in ef]
            off += es * k
    size = (off + align - 1) // align * align
    return size, align, flat


TYPEDEF_UNION = re.compile(r"typedef\s+union\s*\w*\s*\{(?P<body>[^{}]*)\}\s*(?P<name>\w+)\s*;")


def union_member(base, text, defs):
    """(member name, its layout) of a typedef'd union: the first member that
    covers the whole union with plain scalars (a u128 has no C literal; a
    designated initialiser `.member` picks another view of the same bytes)."""
    bodies = {m.group("name"): m.group("body") for m in TYPEDEF_UNION.finditer(headers_text() + text)}
    if base not in bodies:
        return None
    members = []
    for d in bodies[base].split(";"):
        d = " ".join(d.split())
        if not d:
            continue
        m = MEMBER.match(d)
        if not m or ":" in d:
            return None
        for v in m.group("decls").split(","):
            vm = re.fullmatch(r"(\w+)\s*((?:\[[^\]]+\]\s*)*)", v.strip())
            if not vm:
                return None
            k = 1
            for dim in re.findall(r"\[([^\]]+)\]", vm.group(2)):
                k *= int(dim, 0)
            lo = layout(m.group("type").split()[-1], defs)
            members.append((vm.group(1), (lo[0] * k, lo[1], [(o + i * lo[0], st, sp) for i in range(k) for o, st, sp in lo[2]]) if lo else None))
    size = max((lo[0] for _, lo in members if lo), default=0)
    for name, lo in members:
        if lo and lo[0] == size and all(st != "u128" for _, st, _ in lo[2]):
            return name, lo
    return None


def struct_init(n, base, dims, quals, items, text, need):
    """A brace-elided initialiser for a struct type from splat's bytes, or None."""
    defs = struct_defs(headers_text())
    defs.update(struct_defs(text))
    um = union_member(base, text, defs)
    lo = um[1] if um else layout(base, defs)
    if lo is None or lo[0] == 0:
        return None
    size, _, flat = lo
    data, syms = data_to_c.obj_bytes(items, False)
    if dims:
        if len(data) % size:
            # zero padding to the object's alignment after the last element
            cut = len(data) // size * size
            if not cut or any(data[cut:]) or any(a >= cut for a in syms):
                return None
            data = data[:cut]
        count = len(data) // size
    elif len(data) == size or (len(data) > size and not any(data[size:])
                               and all(a < size for a in syms)):
        count = 1           # (zero padding to the object's alignment after it)
        data = data[:size]
    else:
        return None
    vals, per = [], []
    for k in range(count):
        one = []
        for o, st, sp in flat:
            a = k * size + o
            es = 4 if sp else data_to_c.ESZ.get(st, 8)
            sub = {0: syms[a]} if a in syms else {}
            if any(x in syms for x in range(a + 1, a + es)):
                return None
            if st in ("u64", "s64"):
                if sub:
                    return None
                one.append(f"{int.from_bytes(data[a:a + 8], 'little'):#x}")
                continue
            v = data_to_c.values(st, sp, data[a:a + es], sub, need)
            if v is None:
                return None
            one.append(v[0])
        per.append(one)
    if um:
        # a union: each element as its plain-scalar member
        vals = [f"{{ .{um[0]} = {{ {', '.join(one)} }} }}" for one in per]
    else:
        vals = [v for one in per for v in one]
    q = f"{quals} " if quals else ""
    dim = f"[{count:#x}]" if dims else ""
    body = ", ".join(vals)
    if um and not dims:
        body = vals[0][2:-2]                # one union: { .w = { ... } }
    return f"{q}{base} {n}{dim} = {{ {body} }};"


def pick_owner(rec):
    us = [u for u in rec["users"] if u.endswith(".c")]
    if not us:
        return None
    if len(us) == 1:
        return us[0]
    stem = re.sub(r"_(bss|data|rodata\d?|sdata|sbss)(_[0-9A-F]{8})?$", "", Path(rec["unit"]).stem)
    named = [u for u in us if Path(u).stem == stem]
    if named:
        return named[0]
    count = lambda u: len(re.findall(rf"\b{rec['name']}\b", (ROOT / u).read_text()))
    return max(us, key=lambda u: (count(u), -us.index(u)))


def owner_edit(owner, recs, hdr_ext, labels, statics_ok):
    """(new text or None, [(rec, static)], {name: reason})."""
    text = (ROOT / owner).read_text()
    own_ext = externs(text)
    local = move_data.local_structs(text)
    statics, globals_, exts, took, why = [], [], [], [], {}
    for rec in recs:
        r, where = twin(rec, own_ext, hdr_ext, labels[rec["unit"]], local, text)
        if r is None:
            why[rec["name"]] = where
            continue
        d, ext = r
        exts += [e for e in ext if e not in exts]
        st = (statics_ok and where == "owner" and own_ext[rec["name"]][0]["single"]
              and rec["name"] not in hdr_ext and rec["users"] == [owner]
              and not rec["asm"] and not rec["data"] and not rec["alias"])
        (statics if st else globals_).append((rec, d))
        took.append((rec, st))
    if not took:
        return None, took, why
    # statics stand where the owner's extern was, from the bottom up
    for rec, d in sorted(statics, key=lambda x: -own_ext[x[0]["name"]][0]["start"]):
        e = own_ext[rec["name"]][0]
        rep = ("#ifndef NONMATCHING\n" + e["stmt"].rstrip("\n") + "\n#else\n"
               + f"/* data twins ({rec['unit']}): {rec['name']} */\n" + "static " + d + "\n#endif\n")
        text = text[:e["start"]] + rep + text[e["end"]:]
    if globals_ or exts:
        by_unit = collections.defaultdict(list)
        for rec, d in globals_:
            by_unit[rec["unit"]].append((rec, d))
        block = ["", "#ifdef NONMATCHING", "#pragma explicit_zero_data on"] + exts
        for u, items in by_unit.items():
            block.append(f"/* data twins ({u}): {', '.join(r['name'] for r, _ in items)} */")
            block += [d for _, d in items]
        block.append("#endif")
        text = text.rstrip("\n") + "\n" + "\n".join(block) + "\n"
        if exts and statics:
            # declarations a static's initialiser needs come before it
            text = re.sub(r"^#ifndef NONMATCHING\n", "#ifdef NONMATCHING\n" + "\n".join(exts) + "\n#endif\n"
                          "#ifndef NONMATCHING\n", text, count=1, flags=re.M)
    return text, took, why


def compile_to(src_text, owner, out, nonmatching):
    src = ROOT / owner
    probe = src.with_name(f".split_probe_{src.name}")
    probe.write_text(src_text)
    try:
        env = {**os.environ, "CDEFS": "-DNONMATCHING" if nonmatching else ""}
        # compile_c.sh writes ee-gcc's .s beside the object, at a path from the root
        r = subprocess.run([str(ROOT / "tools/compile_c.sh"), str(probe.relative_to(ROOT)),
                            str(Path(out).resolve().relative_to(ROOT))],
                           cwd=ROOT, capture_output=True, text=True, env=env)
        if r.returncode and os.environ.get("SPLIT_DEBUG"):
            print(f"--- {owner}\n{r.stdout}{r.stderr}"[:1500], file=sys.stderr)
        return r.returncode == 0
    finally:
        probe.unlink()


def unit_edit(unit, names_owner):
    """The data unit with each twinned definition under #ifndef NONMATCHING
    (one block per run of consecutive lines with one owner)."""
    text = (ROOT / unit).read_text()
    lines = text.split("\n")
    idx = {}
    for n, own in names_owner.items():
        d = def_line(text, n)
        idx[text[:d[0]].count("\n")] = own
    out, i = [], 0
    while i < len(lines):
        if i in idx:
            own = idx[i]
            j = i
            while j + 1 in idx and idx[j + 1] == own:
                j += 1
            out.append(f"#ifndef NONMATCHING /* the NONMATCHING build defines these in {own} */")
            out += lines[i:j + 1]
            out.append("#endif")
            i = j + 1
        else:
            out.append(lines[i])
            i += 1
    return "\n".join(out)


def unsplit(names_owner, unit_of):
    """Take the twins of names back: the owner's twin goes (a static one's
    `extern` comes back out of its #ifndef), the data unit's definition
    leaves its #ifndef block where it stands."""
    by_owner = collections.defaultdict(list)
    for n, own in names_owner.items():
        by_owner[own].append(n)
    for own, names in by_owner.items():
        text = (ROOT / own).read_text()
        for n in names:
            u = unit_of[n]
            # a static twin: its extern leaves the #ifndef part (it stands
            # before the block), its marker and twin leave the #else part
            blk = re.compile(r"#ifndef NONMATCHING\n((?:extern[^\n]*\n)+)#else\n((?:(?!#endif\n)[^\n]*\n)+?)#endif\n")
            done_static = False
            for m in blk.finditer(text):
                if f"/* data twins ({u}): {n} */" not in m.group(2):
                    continue
                exts = m.group(1).splitlines(keepends=True)
                mine = [e for e in exts if re.search(rf"\b{n}\b", e)]
                rest_e = [e for e in exts if e not in mine]
                body = m.group(2)
                body = re.sub(rf"/\* data twins \({re.escape(u)}\): {n} \*/\n(?:(?:extern|void)[^\n]*\n)*static [^\n]*\b{n}\b[^\n]*\n",
                              "", body)
                new_blk = "".join(mine)
                if rest_e and body.strip():
                    new_blk += "#ifndef NONMATCHING\n" + "".join(rest_e) + "#else\n" + body + "#endif\n"
                text = text[:m.start()] + new_blk + text[m.end():]
                done_static = True
                break
            if done_static:
                continue
            def fix_block(bm):
                blk = bm.group(0)
                if f"data twins ({u})" not in blk:
                    return blk
                def drop(mm):
                    rest = [x.strip() for x in mm.group(2).split(",") if x.strip() != n]
                    return f"/* data twins ({mm.group(1)}): {', '.join(rest)} */\n" if rest else ""
                blk = re.sub(rf"/\* data twins \(({re.escape(u)})\): ([\w, ]*\b{n}\b[\w, ]*) \*/\n", drop, blk)
                # the definition: a type, then the name (never a statement)
                blk = re.sub(rf"^(?:(?:const|volatile|unsigned|signed|struct)\s+)*\w+\s*\**\s*{n}\b[^\n]*;\n",
                             "", blk, count=1, flags=re.M)
                return blk
            text = re.sub(r"^#ifdef NONMATCHING\n(?:(?!#endif)[^\n]*\n)*?#endif\n", fix_block, text, flags=re.M)
        (ROOT / own).write_text(text)
    by_unit = collections.defaultdict(set)
    for n in names_owner:
        by_unit[unit_of[n]].add(n)
    for u, names in by_unit.items():
        lines = (ROOT / u).read_text().split("\n")
        out, block = [], None          # block: the #ifndef header line while inside one
        for line in lines:
            if line.startswith("#ifndef NONMATCHING /* the NONMATCHING build defines these in"):
                block = line
                out.append(line)
                continue
            if block is not None and line == "#endif":
                block = None
                out.append(line)
                continue
            d = re.search(r"\b(\w+)\s*(?:\[[^\]]*\])*\s*(?:__attribute__\(\(\w+(?:\([^()]*\))?\)\)\s*)?(?:=|;)", line)
            if block is not None and d and d.group(1) in names:
                # close the block before it, reopen it after
                out += ["#endif", line, block]
                continue
            out.append(line)
        text = "\n".join(out)
        # empty blocks left behind
        text = re.sub(r"^#ifndef NONMATCHING /\* the NONMATCHING build defines these in [\w/.]+ \*/\n#endif\n", "",
                      text, flags=re.M)
        (ROOT / u).write_text(text)


GROUP_MARK = re.compile(r"/\* data group \(([\w/.]+)\): (\w+): ([\w@, ]+) \*/")
GROUPS_TXT = ROOT / "config/data_groups.txt"


def write_group_syms():
    """config/data_groups.txt from the owners' group markers: each member
    NAME = BLOB + 0xOFF (tools/rel_syms.py writes a line only when no object
    defines NAME and an object defines BLOB, so the matching build, whose
    data units define the members, has none of them)."""
    out = ["/* NONMATCHING data groups (tools/split_data.py writes this from the",
           "   owners' `data group` lines): members as offsets into their blob. */"]
    for p in sorted((ROOT / "src/game").rglob("*.c")):
        for m in GROUP_MARK.finditer(p.read_text()):
            for item in m.group(3).split(","):
                n, off = item.strip().split("@")
                out.append(f"{n} = {m.group(2)} + {off};")
    GROUPS_TXT.write_text("\n".join(out) + "\n")


def group_plan(inv):
    """{root: (unit, section, [(name, addr, size)])} for the pinned groups
    (tools/data_owners.py) whose members are all still in their data unit."""
    sz = move_data.sizes()
    g = collections.defaultdict(list)
    for r in inv:
        if r.get("group") and r["class"] == "pinned" and not r.get("owner") and r["name"] in sz:
            g[r["group"]].append(r)
    out = {}
    for root, rs in g.items():
        if len({r["unit"] for r in rs}) != 1:
            continue
        ms = sorted((sz[r["name"]][0], sz[r["name"]][1], r["name"]) for r in rs)
        if any(a + s != b for (a, s, _), (b, _, _) in zip(ms, ms[1:])) or ms[0][2] != root:
            continue
        users = collections.Counter(u for r in rs for u in r["users"] if u.endswith(".c"))
        if not users:
            continue
        own = max(users, key=lambda u: (users[u], u))
        out[root] = (own, rs[0]["unit"], rs[0]["section"], [(n, a, s) for a, s, n in ms])
    return out


def group_text(own, unit, kind, members, labels):
    """(the owner's new text, blob name) or (None, reason)."""
    root, start = members[0][0], members[0][1]
    total = members[-1][1] + members[-1][2] - start
    blob = f"{root}__grp"
    text = (ROOT / own).read_text()
    # a small-data group stays in small data (the gp range) whatever its size
    sec = f" __attribute__((section(\".{kind}\")))" if kind in ("sbss", "sdata") else ""
    if kind in UNINIT:
        d = f"unsigned char {blob}[{total:#x}]{sec} __attribute__((aligned({min(16, start & -start)})));"
        ext = []
    else:
        items = []
        for n, _, _ in members:
            lab = labels.get(n)
            if lab is None:
                return None, "no splat label"
            items += lab[2]
        need = set()
        # the last string ends at its NUL when carve's size does (the
        # padding after it is the next object's alignment)
        trim = len(data_to_c.obj_bytes(items, False)[0]) != total
        d = data_to_c.define(blob, items, {}, False, need, trim)
        if d is None or len(data_to_c.obj_bytes(items, trim)[0]) != total:
            return None, "bytes"
        d = d.replace(" = ", f"{sec} __attribute__((aligned({min(16, start & -start)}))) = ", 1)
        # built-in types only: an owner need not have the game's typedefs
        builtin = {"s32": "int", "u32": "unsigned int", "u16": "unsigned short", "s16": "short",
                   "u8": "unsigned char", "s8": "signed char", "f32": "float", "char": "char"}
        head = d.split()[0]
        if head == "f32":
            # floats as their bits: ee-gcc 2.96 rounds some decimals a unit
            # off from CodeWarrior (0.3333333f), the bits are the bytes
            import struct as _st
            data = data_to_c.obj_bytes(items, trim)[0]
            words = ", ".join(f"{w:#x}" for (w,) in _st.iter_unpack("<I", data))
            d = (f"unsigned int {blob}[{len(data) // 4:#x}]{sec} "
                 f"__attribute__((aligned({min(16, start & -start)}))) = {{ {words} }};")
            head = None
        if head in builtin:
            d = builtin[head] + d[len(head):]
            d = re.sub(r"\((s32|u32|u16|s16|u8|s8|f32)( \*)?\)", lambda m: f"({builtin[m.group(1)]}{m.group(2) or ''})", d)
        ext = [f"void {x}(void);" if is_func(x) else f"extern unsigned char {x}[];"
               for x in sorted(need) if not re.search(rf"\b{x}\b", text)]
    mark = f"/* data group ({unit}): {blob}: " + ", ".join(f"{n}@{a - start:#x}" for n, a, _ in members) + " */"
    block = ["", "#ifdef NONMATCHING", "#pragma explicit_zero_data on"] + ext + [mark, d, "#endif"]
    return text.rstrip("\n") + "\n" + "\n".join(block) + "\n", blob


def group_compare(obj, blob, members, unit_obj):
    """'' if every member's slice of the blob is the data unit's object."""
    b = obj.blob(blob)
    if b is None:
        return "blob not defined"
    start = members[0][1]
    for n, a, size in members:
        u = unit_obj.blob(n)
        if u is None:
            return f"{n} not in the data unit"
        o = a - start
        rels = [(x - o, t, tg) for x, t, tg in b[3] if o <= x < o + size]
        part = (b[0], size, b[2][o:o + size] if b[0] != "bss" else b"", rels)
        why = ct.compare(part, u)
        if why:
            return f"{n}: {why}"
    return ""


def ungroup(blobs):
    """Take groups back: the owner's blob block goes, the data unit's
    members leave their #ifndef blocks where they stand."""
    names = {}
    for p in sorted((ROOT / "src/game").rglob("*.c")):
        t = p.read_text()
        changed = False
        for m in list(GROUP_MARK.finditer(t)):
            if m.group(2) not in blobs:
                continue
            for item in m.group(3).split(","):
                names[item.strip().split("@")[0]] = (str(p.relative_to(ROOT)), m.group(1))
            blk = re.compile(r"\n#ifdef NONMATCHING\n(?:#pragma[^\n]*\n|extern[^\n]*\n|void [^\n]*\n)*"
                             + re.escape(m.group(0)) + r"\n[^\n]*\n#endif\n")
            t, k = blk.subn("\n", t)
            changed |= bool(k)
        if changed:
            p.write_text(t)
    if names:
        # the data units: the members' definitions leave their #ifndef blocks
        unsplit_units({n: u for n, (_, u) in names.items()})
    return names


def unsplit_units(unit_of):
    by_unit = collections.defaultdict(set)
    for n, u in unit_of.items():
        by_unit[u].add(n)
    for u, names in by_unit.items():
        lines = (ROOT / u).read_text().split("\n")
        out, block = [], None
        for line in lines:
            if line.startswith("#ifndef NONMATCHING /* the NONMATCHING build defines these in"):
                block = line
                out.append(line)
                continue
            if block is not None and line == "#endif":
                block = None
                out.append(line)
                continue
            d = re.search(r"\b(\w+)\s*(?:\[[^\]]*\])*\s*(?:__attribute__\(\(\w+(?:\([^()]*\))?\)\)\s*)?(?:=|;)", line)
            if block is not None and d and d.group(1) in names:
                out += ["#endif", line, block]
                continue
            out.append(line)
        text = "\n".join(out)
        text = re.sub(r"^#ifndef NONMATCHING /\* the NONMATCHING build defines these in [\w/.]+ \*/\n#endif\n", "",
                      text, flags=re.M)
        (ROOT / u).write_text(text)


def stale_groups(inv):
    """The blobs whose member list is not the inventory's group any more
    (a bigger extent, a new root): they go back and are made again."""
    want = collections.defaultdict(set)
    for r in inv:
        if r.get("group"):
            want[r["group"]].add(r["name"])
    out = set()
    for p in sorted((ROOT / "src/game").rglob("*.c")):
        for m in GROUP_MARK.finditer(p.read_text()):
            have = {x.strip().split("@")[0] for x in m.group(3).split(",")}
            root = m.group(2)[:-len("__grp")]
            if len(have) == 1 and root not in want:
                continue                    # a one-object group (no root)
            if have != want.get(root, set()):
                out.add(m.group(2))
    return out


def main():
    inv = json.loads((ROOT / "build/data_owners.json").read_text())
    stale = stale_groups(inv)
    if stale:
        print(f"{len(stale)} groups changed and go back: {', '.join(sorted(stale)[:6])}", file=sys.stderr)
        if "--apply" in sys.argv:
            ungroup(stale)
            write_group_syms()
            print("rerun tools/data_owners.py and this to make them again", file=sys.stderr)
            return
    back = {r["name"]: r["owner"] for r in inv if r["class"] == "pinned" and r.get("owner")}
    if back:
        print(f"{len(back)} pinned twins go back: {', '.join(sorted(back)[:8])}{', ...' if len(back) > 8 else ''}",
              file=sys.stderr)
        if "--apply" in sys.argv:
            unsplit(back, {r["name"]: r["unit"] for r in inv})
    units = [sys.argv[i + 1] for i, a in enumerate(sys.argv) if a == "--unit"]
    recs = [r for r in inv if r["class"] in ("single", "multi") and (not units or r["unit"] in units)]
    hdr_ext = externs(headers_text())
    labels = collections.defaultdict(dict)
    for r in recs:
        if r["section"] not in UNINIT and r["unit"] not in labels:
            labels[r["unit"]] = labels_of(r["unit"], r["section"])
    by_owner = collections.defaultdict(list)
    for r in recs:
        o = pick_owner(r)
        if o:
            by_owner[o].append(r)
    owners = sorted(by_owner)
    if "--limit" in sys.argv:
        owners = owners[:int(sys.argv[sys.argv.index("--limit") + 1])]
    tmp = Path(tempfile.mkdtemp(dir=ROOT / "build"))
    unit_objs = {}

    def unit_obj(u):
        if u not in unit_objs:
            o = tmp / (Path(u).stem + ".unit.o")
            if not compile_to((ROOT / u).read_text(), u, o, False):
                raise SystemExit(f"{u} does not compile")
            unit_objs[u] = ct.Obj(o)
        return unit_objs[u]

    reasons = collections.Counter()
    done, texts = {}, {}
    for own in owners:
        cand = by_owner[own]
        statics_ok = True
        for attempt in range(4):
            text, took, why = owner_edit(own, cand, hdr_ext, labels, statics_ok)
            if text is None:
                break
            o = tmp / (Path(own).stem + f".{attempt}.o")
            if not compile_to(text, own, o, True):
                if statics_ok:
                    statics_ok = False       # retry with globals only
                    continue
                reasons["owner does not compile"] += len(took)
                text = None
                break
            obj = ct.Obj(o)
            bad = [rec for rec, _ in took if ct.compare(obj.blob(rec["name"]), unit_obj(rec["unit"]).blob(rec["name"]))]
            if not bad:
                break
            reasons["bytes differ"] += len(bad)
            names = {r["name"] for r in bad}
            cand = [r for r in cand if r["name"] not in names]
        else:
            text = None
        reasons.update(why.values())
        if text is None or not took:
            continue
        texts[own] = text
        for rec, st in took:
            done[rec["name"]] = own
        ns = sum(st for _, st in took)
        print(f"{own}: {len(took)} ({ns} static)")
    print(f"{len(done)} of {len(recs)} objects get a twin in {len(texts)} owners; left: "
          + ", ".join(f"{k} {v}" for k, v in reasons.most_common()), file=sys.stderr)
    # groups: a pinned table with a known extent moves whole, as one blob
    gdone, greasons = {}, collections.Counter()
    for root, (own, unit, kind, members) in sorted(group_plan(inv).items()):
        if own in texts:
            base_text = texts[own]
        else:
            base_text = None
        if unit not in labels and kind not in UNINIT:
            labels[unit] = labels_of(unit, kind)
        saved = (ROOT / own).read_text()
        if base_text is not None:
            (ROOT / own).write_text(base_text)
        try:
            t, blob = group_text(own, unit, kind, members, labels[unit])
        finally:
            (ROOT / own).write_text(saved)
        if t is None:
            greasons[blob] += 1
            continue
        o = tmp / (Path(own).stem + f".g.{root}.o")
        if not compile_to(t, own, o, True):
            greasons["owner does not compile"] += 1
            continue
        why = group_compare(ct.Obj(o), blob, members, unit_obj(unit))
        if why:
            greasons[why.split(":")[-1].strip()[:30]] += 1
            continue
        texts[own] = t
        for n, _, _ in members:
            gdone[n] = own
        print(f"{own}: group {root} ({len(members)} objects)")
    # what the twin writer could not write: a one-object group (its bytes as
    # a blob, its name an offset into it), so no C type has to fit; a small
    # data object only while the blob stays small (8 bytes, the gp range)
    sz = move_data.sizes()
    for x in inv:
        # carve lists no size for some labels (pads, jump tables): the name
        # has the address, the inventory the size
        if x["name"] not in sz and re.search(r"_([0-9A-F]{8})$", x["name"]):
            sz[x["name"]] = (int(x["name"][-8:], 16), x["size"])
    owner_of = {x["name"]: x.get("owner") for x in inv}
    # an object asm still names may move too when C uses it: a group member
    # is a global, which is all the asm needs
    recs += [x for x in inv if x["class"] == "asm" and any(u.endswith(".c") for u in x["users"])]
    for r in [x for x in inv if x["class"] == "data"]:
        # only other data points at it: it goes where what points at it went
        for u in r["data"]:
            t = (ROOT / u).read_text()
            for m in re.finditer(rf"^[^\n]*?\b(\w+)\s*(?:\[[^\]]*\])*\s*(?:__attribute__\(\(\w+(?:\([^()]*\))?\)\)\s*)?="
                                 rf"[^\n]*\b{r['name']}\b", t, re.M):
                if owner_of.get(m.group(1)):
                    r = dict(r, users=[owner_of[m.group(1)]])
                    break
            if r["users"]:
                break
        if r["users"]:
            recs.append(r)
    # nothing in C names it (unused, or only a still-linked asm chunk): it
    # goes to the owner of its neighbour in the data unit, its bytes in a blob
    # (a global, all the asm needs; an unused object cannot change what runs)
    by_unit = collections.defaultdict(list)
    for x in inv:
        if x["name"] in sz:
            by_unit[x["unit"]].append((sz[x["name"]][0], x))
    # the C that stands in for an asm chunk in the NONMATCHING build
    import gen_ninja
    first = {}
    for c in Path(ROOT / "asm").glob("text*.s"):
        m = re.search(r"^\s*glabel (\w+)", c.read_text(), re.M)
        if m:
            first[m.group(1)] = c
    replacer = {}
    gen_ninja.NONMATCHING = True
    for p in sorted((ROOT / "src/game").rglob("*.c")):
        for nm in gen_ninja.asm_markers(p.read_text())[1]:
            if nm in first:
                c = first[nm]
                own = next((q for q in sorted(p.parent.glob("*.c")) if f"{nm}" in q.read_text()
                            and "#ifdef NONMATCHING" in q.read_text() and q != p), p)
                replacer[c] = str(own.relative_to(ROOT))
    for u, lst in by_unit.items():
        lst.sort(key=lambda t: t[0])
        for k, (a, x) in enumerate(lst):
            if x["class"] not in ("orphan", "asm") or x.get("owner") or any(v.endswith(".c") for v in x["users"]):
                continue
            # an asm chunk the NONMATCHING build replaces used it: its C owns it
            by_asm = [replacer[c] for c in replacer if re.search(rf"\b{x['name']}\b", c.read_text())]
            near = [y for _, y in lst[k - 1::-1] if y.get("owner")][:1] + [y for _, y in lst[k + 1:] if y.get("owner")][:1]
            owner = by_asm[0] if by_asm else (near[0]["owner"] if near else None)
            if owner is None:
                # the units the data unit was carved for (its `used by` note)
                note = re.search(r"/\* used by: ([^*]*)\*/", (ROOT / u).read_text())
                for stem in (note.group(1).replace("\n", " ").split(",") if note else []):
                    hit = sorted((ROOT / "src/game").rglob(f"{stem.strip()}.c"))
                    if hit and "/data/" not in str(hit[0]):
                        owner = str(hit[0].relative_to(ROOT))
                        break
            if owner is None:
                # the C unit retail put it after (the one before it in link order)
                order = [l.strip() for l in (ROOT / "config/link_order.jp.txt").read_text().splitlines()]
                if u in order:
                    owner = next((q for q in order[order.index(u)::-1]
                                  if q.startswith("src/game/") and q.endswith(".c") and "/data/" not in q), None)
            if owner:
                recs.append(dict(x, users=[owner]))
    for r in recs:
        n = r["name"]
        if n in done or n in gdone or n not in sz:
            continue
        own = pick_owner(r)
        if own is None:
            continue

        if r["unit"] not in labels and r["section"] not in UNINIT:
            labels[r["unit"]] = labels_of(r["unit"], r["section"])
        members = [(n, sz[n][0], r["size"])]
        saved = (ROOT / own).read_text()
        if own in texts:
            (ROOT / own).write_text(texts[own])
        try:
            t, blob = group_text(own, r["unit"], r["section"], members, labels[r["unit"]])
            if t is None and blob == "no splat label":
                # no label of its own (carve cut it out of a word): its bytes
                # from the data unit's object, if nothing in it is relocated
                ub = unit_obj(r["unit"]).blob(n)
                if ub is not None and ub[0] != "bss" and not ub[3]:
                    blob = f"{n}__grp"
                    sec = f" __attribute__((section(\".{r['section']}\")))" if r["section"] in ("sbss", "sdata") else ""
                    a = sz[n][0]
                    vals = ", ".join(f"{b:#x}" for b in ub[2])
                    d = f"unsigned char {blob}[{len(ub[2]):#x}]{sec} __attribute__((aligned({min(16, a & -a)}))) = {{ {vals} }};"
                    mark = f"/* data group ({r['unit']}): {blob}: {n}@0x0 */"
                    base = (ROOT / own).read_text()
                    t = base.rstrip("\n") + "\n" + "\n".join(["", "#ifdef NONMATCHING", mark, d, "#endif"]) + "\n"
        finally:
            (ROOT / own).write_text(saved)
        if t is None:
            greasons["single: " + blob] += 1
            continue
        o = tmp / (Path(own).stem + f".s.{n}.o")
        if not compile_to(t, own, o, True):
            greasons["single: owner does not compile"] += 1
            continue
        why = group_compare(ct.Obj(o), blob, members, unit_obj(r["unit"]))
        if why:
            greasons["single: " + why.split(":")[-1].strip()[:30]] += 1
            continue
        texts[own] = t
        gdone[n] = own
    print(f"{len(gdone)} objects in {len({gdone[n] for n in gdone})} owners move as groups; left: "
          + ", ".join(f"{k} {v}" for k, v in greasons.most_common()), file=sys.stderr)
    done.update(gdone)
    if "--apply" not in sys.argv:
        return
    for own, text in texts.items():
        (ROOT / own).write_text(text)
    unit_of = {r["name"]: r["unit"] for r in inv}
    by_unit = collections.defaultdict(dict)
    for n, own in done.items():
        by_unit[unit_of[n]][n] = own
    for u, m in by_unit.items():
        (ROOT / u).write_text(unit_edit(u, m))
    write_group_syms()
    import merge_ifdefs
    merge_ifdefs.main()


if __name__ == "__main__":
    main()
