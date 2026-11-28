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
    if t in data_to_c.ESZ:
        n = data_to_c.ESZ[t]
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


def struct_init(n, base, dims, quals, items, text, need):
    """A brace-elided initialiser for a struct type from splat's bytes, or None."""
    defs = struct_defs(headers_text())
    defs.update(struct_defs(text))
    lo = layout(base, defs)
    if lo is None or lo[0] == 0:
        return None
    size, _, flat = lo
    data, syms = data_to_c.obj_bytes(items, False)
    if dims:
        if len(data) % size:
            return None
        count = len(data) // size
    elif len(data) == size:
        count = 1
    else:
        return None
    vals = []
    for k in range(count):
        for o, st, sp in flat:
            a = k * size + o
            es = 4 if sp else data_to_c.ESZ[st]
            sub = {0: syms[a]} if a in syms else {}
            if any(x in syms for x in range(a + 1, a + es)):
                return None
            v = data_to_c.values(st, sp, data[a:a + es], sub, need)
            if v is None:
                return None
            vals.append(v[0])
    q = f"{quals} " if quals else ""
    dim = f"[{count:#x}]" if dims else ""
    return f"{q}{base} {n}{dim} = {{ {', '.join(vals)} }};"


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
        r = subprocess.run([str(ROOT / "tools/compile_c.sh"), str(probe.relative_to(ROOT)), str(out)],
                           cwd=ROOT, capture_output=True, text=True, env=env)
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
            st = re.compile(rf"#ifndef NONMATCHING\n(?P<ext>[^\n]*\n)#else\n/\* data twins \({re.escape(u)}\): {n} \*/\n"
                            rf"(?:[^\n]*\n)*?static [^\n]*\b{n}\b[^\n]*\n#endif\n")
            m = st.search(text)
            if m:
                text = text[:m.start()] + m.group("ext") + text[m.end():]
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


def main():
    inv = json.loads((ROOT / "build/data_owners.json").read_text())
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


if __name__ == "__main__":
    main()
