#!/usr/bin/env python3
"""Who owns each object of the game's data-only units (src/game/data/).

    tools/data_owners.py [--report] [--json build/data_owners.json]

An object's users are the units of the NONMATCHING link (tools/gen_ninja.py:
the C that stands in for an asm chunk, the asm chunks that are left) that
name it, directly or through a field alias of config/data_aliases.txt, and
the data units whose initialisers point at it. The build's objects must be
current for the NONMATCHING build (`./build.sh`); the data units are
compiled here once more without -DNONMATCHING, so an object whose
definition is already split (tools/split_data.py) is still listed.

Classes:
  split     defined in its owner under #ifdef NONMATCHING already
  pinned    the code may reach past it into its neighbours (an address cast,
            an offset past its end, or after such an object in its run): the
            NONMATCHING build keeps it where its data unit has it
  single    one C unit uses it
  multi     several C units use it
  asm       an asm chunk that is still linked uses it (it stays global)
  data      only other data points at it
  orphan    nothing names it (it stays in its data unit)

--report prints the counts per class and section and per data unit;
--json writes every object's record (unit, section, size, users, class).
"""
import collections
import glob
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import gen_ninja  # noqa: E402

DATA_SECS = {".data": "data", ".rodata": "rodata", ".sdata": "sdata", ".sbss": "sbss", ".bss": "bss"}
SPLIT_DEF = re.compile(r"^#ifdef NONMATCHING\b")


def aliases():
    out = {}
    for m in re.finditer(r"^(\w+) = (\w+) \+ 0x([0-9A-F]+);",
                         (ROOT / "config/data_aliases.txt").read_text(), re.M):
        out[m.group(1)] = m.group(2)
    return out


def data_unit_paths():
    return sorted(str(Path(p).relative_to(ROOT)) for p in glob.glob(str(ROOT / "src/game/data/*.c")))


def compile_matching(src, out):
    """src compiled as the matching build has it (no CDEFS)."""
    r = subprocess.run([str(ROOT / "tools/compile_c.sh"), src, str(out)], cwd=ROOT,
                       capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f"{src}: {r.stdout}{r.stderr}")


def symbols(obj):
    """(defined globals {name: (section kind, size)}, undefined names)."""
    defs, undef = {}, set()
    with open(obj, "rb") as f:
        e = ELFFile(f)
        secs = [s.name for s in e.iter_sections()]
        for s in e.get_section_by_name(".symtab").iter_symbols():
            if not s.name:
                continue
            if s["st_shndx"] == "SHN_UNDEF":
                undef.add(s.name)
            elif s["st_info"]["bind"] == "STB_GLOBAL" and s["st_info"]["type"] in ("STT_OBJECT", "STT_NOTYPE"):
                if s["st_shndx"] == "SHN_COMMON":
                    defs[s.name] = ("bss", s["st_size"])
                elif isinstance(s["st_shndx"], int):
                    k = DATA_SECS.get(secs[s["st_shndx"]])
                    if k:
                        defs[s.name] = (k, s["st_size"])
    return defs, undef


def nonmatching_link():
    """The sources of the NONMATCHING link, data units left out."""
    srcs = gen_ninja.link_order()
    gen_ninja.NONMATCHING = True
    gone = gen_ninja.replaced_chunks(srcs)
    return [s for s in srcs if s not in gone and not s.startswith("src/game/data/")]


def split_names():
    """Names a game unit defines under #ifdef NONMATCHING (tools/split_data.py
    marks each block with `/* data twins: ... */`)."""
    out = {}
    for p in glob.glob(str(ROOT / "src/game/**/*.c"), recursive=True):
        if "/src/game/data/" in p:
            continue
        for m in re.finditer(r"/\* data twins \(([\w/.]+)\): ([\w, ]+) \*/", Path(p).read_text()):
            for n in m.group(2).split(","):
                out[n.strip()] = str(Path(p).relative_to(ROOT))
    return out


def inventory():
    alias = aliases()
    objs = {}                     # name -> record
    data_refs = collections.defaultdict(set)
    tmp = Path(tempfile.mkdtemp(dir=ROOT / "build"))
    for u in data_unit_paths():
        o = tmp / (Path(u).stem + ".o")
        compile_matching(u, o)
        defs, undef = symbols(o)
        for n, (k, size) in defs.items():
            objs[n] = {"name": n, "unit": u, "section": k, "size": size}
        # every relocation of the unit's data, the unit's own objects included
        import check_data_twins
        ob = check_data_twins.Obj(o)
        for rels in ob.rels.values():
            for _, _, tsym, add in rels:
                if tsym.name and tsym["st_info"]["type"] != "STT_SECTION":
                    data_refs[alias.get(tsym.name, tsym.name)].add(u)
    users = collections.defaultdict(set)
    asm_users = collections.defaultdict(set)
    via_alias = set()
    for s in nonmatching_link():
        o = ROOT / gen_ninja.obj_for(s)
        if not o.exists() or s.startswith("src/sce/") or gen_ninja.asm_category(s) == "sce" and s.startswith("asm/"):
            continue
        _, undef = symbols(o)
        for n in undef:
            t = alias.get(n, n)
            if "__as_" in t:          # a merged unit's part's name for it (tools/merge_tu.py)
                t = t.split("__as_")[0]
            if t not in objs:
                continue
            if t != n:
                via_alias.add(t)
            (asm_users if s.startswith("asm/") else users)[t].add(s)
    # owners of the link's own symbol assignments (tools/rel_syms.py writes
    # NAME = OWNER + 0xOFF for config/'s addresses): they must stay global
    rel = ROOT / "build/rel_syms.ld"
    rel_owners = set(re.findall(r"=\s*(\w+)\s*[+;]", rel.read_text())) if rel.exists() else set()
    pin(objs, nonmatching_link())
    split = split_names()
    for n, r in objs.items():
        r["users"] = sorted(users[n])
        r["asm"] = sorted(asm_users[n])
        r["data"] = sorted(data_refs[n])
        r["alias"] = n in via_alias or n in rel_owners
        if r["pinned"] and n not in split:
            r["class"] = "pinned"
        elif n in split:
            r["class"], r["owner"] = "split", split[n]
        elif r["asm"]:
            r["class"] = "asm"
        elif len(r["users"]) == 1:
            r["class"] = "single"
        elif r["users"]:
            r["class"] = "multi"
        elif r["data"]:
            r["class"] = "data"
        else:
            r["class"] = "orphan"
    return objs


def externs_of(text):
    import split_data
    return split_data.externs(text)


def is_string(rec, cache={}):
    t = cache.setdefault(rec["unit"], (ROOT / rec["unit"]).read_text())
    m = re.search(rf"^[^\n]*\b{re.escape(rec['name'])}\b\s*(?:\[[^\]]*\])*\s*(?:__attribute__\(\(\w+(?:\([^()]*\))?\)\)\s*)?=\s*\"",
                  t, re.M)
    return bool(m)


CAST = r"\(\s*(?:(?:unsigned|signed|const|volatile|struct)\s+)*\w+\s*\**\s*\)\s*(&\s*)?\b{n}\b(?!\s*[\[.])"


def escape_roots(objs):
    """Objects whose address a game unit casts (to an integer or another
    pointer type): how far the code reaches from there is unknown. A string
    (its extent ends at its NUL) is no root."""
    out = {}
    srcs = {}
    for p in glob.glob(str(ROOT / "src/game/**/*.c"), recursive=True):
        if "/src/game/data/" not in p:
            srcs[p] = Path(p).read_text()
    for n, r in objs.items():
        if is_string(r):
            continue
        for p, t in srcs.items():
            if n not in t:
                continue
            ex = externs_of(t).get(n)
            arr = bool(ex and ex[0]["dims"])
            def reaches(m):
                if not (m.group(1) or arr):
                    return False            # a value cast
                before = t[:m.start()].rstrip()
                after = t[m.end():].lstrip()
                deref = before.endswith("*") and not before.endswith("**")
                if (deref or before.endswith("(") and after.startswith(")[0]")) \
                        and not after.startswith(("[", "+", "-")):
                    return False            # *(T *)&X: the object itself
                return True
            m = next((m for m in re.finditer(CAST.format(n=re.escape(n)), t) if reaches(m)), None)
            if m:
                out[n] = f"address cast in {Path(p).relative_to(ROOT)}: {m.group(0)}"
                break
    return out


def over_reach(objs, link):
    """Objects code reaches at a constant offset past their end (a %hi/%lo
    pair or a gp-relative access whose addend is outside [0, size])."""
    from elftools.elf.relocation import RelocationSection
    out = {}
    alias = aliases()
    for s in link:
        o = ROOT / gen_ninja.obj_for(s)
        if not o.exists():
            continue
        with open(o, "rb") as f:
            e = ELFFile(f)
            syms = list(e.get_section_by_name(".symtab").iter_symbols())
            for rs in e.iter_sections():
                if not isinstance(rs, RelocationSection) or not rs.name.startswith(".rel.text"):
                    continue
                text = e.get_section(rs["sh_info"]).data()
                hi = None
                for r in rs.iter_relocations():
                    sym = syms[r["r_info_sym"]].name
                    typ = r["r_info_type"]
                    w = int.from_bytes(text[r["r_offset"]:r["r_offset"] + 4], "little")
                    if typ == 5:                    # R_MIPS_HI16
                        hi = (sym, (w & 0xFFFF) << 16)
                        continue
                    if typ == 6 and hi and hi[0] == sym:
                        add = hi[1] + ((w & 0xFFFF) ^ 0x8000) - 0x8000
                    elif typ == 7:                  # R_MIPS_GPREL16
                        add = ((w & 0xFFFF) ^ 0x8000) - 0x8000
                    else:
                        continue
                    n = alias.get(sym, sym)
                    if n != sym or n not in objs:
                        continue                    # a field alias is its own object
                    objs[n]["reach"] = max(objs[n].get("reach", 0), add)
                    if not 0 <= add <= objs[n]["size"]:
                        out.setdefault(n, f"{Path(s).name} reaches {n}{add:+#x} (size {objs[n]['size']:#x})")
    return out


def pin(objs, link):
    """r['pinned']: why the NONMATCHING build must keep an object where the
    data unit has it, None if it may move. An object a root's code may reach
    past keeps its gap-free run after it too (the root's extent is unknown)."""
    sys.path.insert(0, str(ROOT / "tools"))
    import move_data
    sz = move_data.sizes()
    roots = escape_roots(objs)
    reach = over_reach(objs, link)
    for r in objs.values():
        r["pinned"] = reach.get(r["name"])
    by_unit = collections.defaultdict(list)
    for n, r in objs.items():
        if n in sz:
            by_unit[r["unit"]].append((sz[n][0], sz[n][1], n))
    extent = {}
    for line in (ROOT / "config/data_extents.txt").read_text().splitlines():
        f = line.split("#", 1)[0].split()
        if len(f) == 2:
            extent[f[0]] = None if f[1] == "self" else int(f[1], 0)
    for u, lst in by_unit.items():
        lst.sort()
        root, end = None, None          # end: where a root with a known extent stops
        for k, (a, size, n) in enumerate(lst):
            if k and lst[k - 1][0] + lst[k - 1][1] != a:
                root = None                         # a gap ends the run
            if root is not None and end is not None and a >= end:
                root = None
            if root is None and n in roots:
                if n in extent and (extent[n] is None or extent[n] <= size):
                    continue                        # it reaches only itself
                root = n
                end = a + extent[n] if n in extent else None
                objs[n]["pinned"] = objs[n]["pinned"] or roots[n]
            elif root is not None:
                objs[n]["pinned"] = objs[n]["pinned"] or f"after {root} in its run ({roots[root]})"


def owned_in_code():
    """Named data objects code units already define (both builds): counted
    from the matching-build objects of the game's non-data C units."""
    n = 0
    for s in gen_ninja.link_order():
        if s.startswith("src/game/") and s.endswith(".c") and not s.startswith("src/game/data/"):
            o = ROOT / gen_ninja.obj_for(s)
            if o.exists():
                n += sum(1 for k in symbols(o)[0] if not k.startswith("__include_asm_"))
    return n


def report(objs):
    cls = collections.Counter((r["class"], r["section"]) for r in objs.values())
    secs = sorted({s for _, s in cls})
    classes = ["split", "single", "multi", "pinned", "asm", "data", "orphan"]
    print(f"{'':8}" + "".join(f"{s:>8}" for s in secs) + f"{'all':>8}")
    for c in classes:
        print(f"{c:8}" + "".join(f"{cls[(c, s)]:>8}" for s in secs) + f"{sum(cls[(c, s)] for s in secs):>8}")
    print(f"{'total':8}" + "".join(f"{sum(cls[(c, s)] for c in classes):>8}" for s in secs) + f"{len(objs):>8}")
    print()
    by_unit = collections.defaultdict(collections.Counter)
    for r in objs.values():
        by_unit[r["unit"]][r["class"]] += 1
    for u, c in sorted(by_unit.items()):
        print(f"{u:52} " + " ".join(f"{k}={c[k]}" for k in classes if c[k]))


def main():
    ninja = ROOT / "build.ninja"
    if not ninja.exists() or "# NONMATCHING: on" not in ninja.read_text():
        raise SystemExit("data_owners.py: needs the NONMATCHING build's objects (run ./build.sh first)")
    objs = inventory()
    if "--json" in sys.argv:
        out = ROOT / sys.argv[sys.argv.index("--json") + 1]
        out.write_text(json.dumps(sorted(objs.values(), key=lambda r: r["name"]), indent=1) + "\n")
    if "--report" in sys.argv or "--json" not in sys.argv:
        report(objs)


if __name__ == "__main__":
    main()
