#!/usr/bin/env python3
"""Write a splat data file of the game as a data-only C unit.

    tools/data_to_c.py asm/data/data_XXXXXXXX.data.s [--write]

Every label of the file becomes one object of src/game/data/<name>.c, in
address order, with the retail bytes as its initialiser. Without --write the
C goes to stdout.

CodeWarrior gives each object a section of its own (16-aligned from 16 bytes,
8-aligned from 5, 4-aligned below) and writes initialised objects in
definition order; an object retail packs tighter than that gets
__attribute__((aligned(N))) from its address, so every object lands where
splat's label is. The unit is built with `-sdatathreshold 0`
(tools/compile_c.sh does that for src/game/data/; small objects stay in
.data, as retail has them) and
`#pragma explicit_zero_data on` (an all-zero initialiser stays in .data, not
.bss). A .rodata file gives const objects.

Types: the one the game's C code declares for the label (an `extern` with a
scalar type, a pointer or a struct whose members share one scalar type);
otherwise words that read as plain floats are f32, halfwords u16, a string
char[], anything else s32 (a word splat wrote as a symbol becomes `(s32)SYM`).
"""
import glob
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from names import is_func, data_name  # noqa: E402


ROOT = Path(__file__).resolve().parent.parent
LINE = re.compile(r"/\* \w+ ([0-9A-F]{8})(?: ([0-9A-F]+))? \*/\s+\.(word|short|byte)\s+(.*)$")
STR = re.compile(r"/\* \w+ ([0-9A-F]{8}) \*/\s+\.asciz\s+(.*)$")
RAW = re.compile(r"^\s*/\* ([0-9A-F]+) \*/\s*$")
ESZ = {"s8": 1, "u8": 1, "char": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "int": 4,
       "f32": 4, "float": 4}
DECL = re.compile(r"^\s*extern\s+(?:volatile\s+|const\s+)*(\w+)\s*(\*?)\s*(\w+)\s*(\[[^\]]*\])?\s*;", re.M)
TYPEDEF = re.compile(r"typedef\s+struct\s*\w*\s*\{([^{}]*)\}\s*(\w+)\s*;")


def parse(path):
    """[(name, addr, [(kind, value, rawhex)], closed)] in file order; closed:
    the label's enddlabel comes before the padding that follows it."""
    labels = []
    aligned = False      # an .align since the label's last item
    for line in Path(path).read_text().splitlines():
        m = re.match(r"dlabel (\S+)", line)
        if m:
            labels.append([m.group(1), None, []])
            aligned = False
            continue
        if line.strip().startswith(".align"):
            aligned = True
            continue
        if line.startswith("enddlabel"):
            if labels and len(labels[-1]) == 3:
                labels[-1].append(not aligned)
            continue
        if line.strip() and not line.strip().startswith(("nonmatching", ".")):
            aligned = False
        m = STR.search(line)
        if m and labels and len(labels[-1]) == 3:
            # a string: "/* ROM VRAM */ .asciz ..." and its bytes (padding
            # included) on the next comment line
            if labels[-1][1] is None:
                labels[-1][1] = int(m.group(1), 16)
            labels[-1][2].append(("asciz", m.group(2), None))
            continue
        m = RAW.match(line)
        if m and labels and len(labels[-1]) == 3 and labels[-1][2] and labels[-1][2][-1][2] is None:
            k, v, _ = labels[-1][2][-1]
            labels[-1][2][-1] = (k, v, m.group(1))
            continue
        m = LINE.search(line)
        if m and labels and len(labels[-1]) == 3:
            if labels[-1][1] is None:
                labels[-1][1] = int(m.group(1), 16)
            labels[-1][2].append((m.group(3), m.group(4).strip(), m.group(2)))
    return [(n, a, items, bool(rest and rest[0])) for n, a, items, *rest in labels if a is not None]


def declared_types():
    """name -> set of (type, ptr, has_dim) the game's C code declares."""
    out = defaultdict(set)
    for p in glob.glob(str(ROOT / "src/game/**/*.c"), recursive=True):
        if "/src/game/data/" in p:
            continue
        for m in DECL.finditer(Path(p).read_text()):
            out[m.group(3)].add((m.group(1), m.group(2), m.group(4) is not None))
    return out


def struct_scalar(name, cache={}):
    """A struct typedef whose members share one scalar type -> (type, count)."""
    if not cache:
        text = "".join(Path(p).read_text() for p in glob.glob(str(ROOT / "include/*.h"))
                       + glob.glob(str(ROOT / "src/game/*.h")))
        for m in TYPEDEF.finditer(text):
            ts, n = set(), 0
            for d in m.group(1).split(";"):
                d = d.strip()
                if not d:
                    continue
                mm = re.fullmatch(r"(\w+)\s+([\w\s,\[\]]+)", d)
                if not mm or mm.group(1) not in ESZ:
                    ts = None
                    break
                ts.add(mm.group(1))
                for v in mm.group(2).split(","):
                    k = 1
                    for dim in re.findall(r"\[([^\]]+)\]", v):
                        k *= int(dim, 0)
                    n += k
            if ts and len(ts) == 1:
                cache[m.group(2)] = (ts.pop(), n)
        cache.setdefault("", None)
    return cache.get(name)


def to_bytes(items):
    """The label's bytes and {offset: symbol text} for words splat wrote as symbols."""
    out, syms = bytearray(), {}
    for kind, val, raw in items:
        if kind == "word" and not re.fullmatch(r"-?(0x[0-9A-Fa-f]+|\d+)", val):
            syms[len(out)] = val
        if raw:
            out += bytes.fromhex(raw)
        else:
            size = {"word": 4, "short": 2, "byte": 1}[kind]
            out += (int(val, 0) & ((1 << 8 * size) - 1)).to_bytes(size, "little")
    return bytes(out), syms


def obj_bytes(items, trim=False):
    """to_bytes, less the padding after the label's last string when splat's
    label ends before it (`trim`): it is not the object's own, and the next
    object's alignment puts it back."""
    data, syms = to_bytes(items)
    if trim and items and items[-1][0] == "asciz" and items[-1][2]:
        last = bytes.fromhex(items[-1][2])
        data = data[:len(data) - len(last) + last.index(b"\0") + 1]
    return data, syms


def f32_text(b):
    v = struct.unpack("<f", b)[0]
    if v != v or abs(v) == float("inf"):
        return None
    for p in range(1, 10):
        s = "%.*g" % (p, v)
        if struct.pack("<f", float(s)) == b:
            break
    if "e" in s:
        for p2 in range(1, 8):
            t = "%.*f" % (p2, v)
            if struct.pack("<f", float(t)) == b:
                s = t
                break
    if "e" not in s and "." not in s:
        s += ".0"
    return s + "f"


def plain_float(b):
    """A word that reads as an ordinary float: zero, or 1e-6 < |v| < 1e7 with a
    short decimal form."""
    w = struct.unpack("<I", b)[0]
    if w == 0:
        return True
    v = struct.unpack("<f", b)[0]
    t = f32_text(b)
    return t is not None and 1e-6 < abs(v) < 1e7 and len(t.rstrip("f").lstrip("-")) <= 10


_FUNCS = []


def func_of(addr):
    """(name, start) of the function an address is in, from splat's asm."""
    import bisect
    if not _FUNCS:
        for p in glob.glob(str(ROOT / "asm/**/*.s"), recursive=True):
            if "/asm/data/" in p:
                continue
            for m in re.finditer(r"^glabel (\w+)\n(?:.*\n)*?.*?/\* [0-9A-F]+ ([0-9A-F]{8}) ",
                                 Path(p).read_text(), re.M):
                _FUNCS.append((int(m.group(2), 16), m.group(1)))
        _FUNCS.sort()
    i = bisect.bisect_right(_FUNCS, (addr, "\xff")) - 1
    return (_FUNCS[i][1], _FUNCS[i][0]) if i >= 0 else (None, None)


def values(etype, ptr, data, syms, need):
    es = 4 if ptr else ESZ[etype]
    if len(data) % es or (syms and es != 4):
        return None
    out = []
    for i in range(0, len(data), es):
        if i in syms and re.fullmatch(r"\.L[0-9A-F]{8}", syms[i]):
            # a jump table entry of an asm function: the function plus the offset
            a = int(syms[i][2:], 16)
            f, start = func_of(a)
            if f is None or es != 4:
                return None
            need.add(f)
            out.append(f"({etype})((u8 *){f} + 0x{a - start:X})")
            continue
        if i in syms:
            m = re.fullmatch(r"(\w+)(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?", syms[i])
            if not m:
                return None
            need.add(m.group(1))
            ref = m.group(1) if not m.group(2) else f"(u8 *){m.group(1)} + {m.group(2)}"
            cast = f"({etype} *)" if ptr else f"({etype})"
            out.append(f"{cast}({ref})" if m.group(2) else f"{cast}{ref}")
            continue
        b = data[i:i + es]
        if ptr:
            if any(b):
                return None
            out.append("0")
        elif etype in ("f32", "float"):
            t = f32_text(b)
            if t is None:
                return None
            out.append(t)
        else:
            signed = etype in ("s8", "s16", "s32", "int", "char")
            v = int.from_bytes(b, "little", signed=signed)
            out.append(str(v) if -10 < v < 10 else (hex(v) if v > 0 else "-" + hex(-v)))
    return out


def define(name, items, decls, const, need, trim=False):
    data, syms = obj_bytes(items, trim)
    kinds = {k for k, *_ in items}
    q = "const " if const else ""
    ds1 = decls.get(name, set())
    ctype = next(iter(ds1))[0] if len(ds1) == 1 and next(iter(ds1))[0] in ("u8", "s8", "char") \
        and not next(iter(ds1))[1] else "char"
    if "asciz" in kinds and not syms:
        # the string(s) and their padding, byte for byte
        def esc(c):
            if c == 0x5C: return "\\\\"
            if c == 0x22: return '\\"'
            if 32 <= c < 127: return chr(c)
            return "\\%03o" % c
        body = "".join(esc(c) for c in data)
        return f'{q}{ctype} {name}[{len(data):#x}] = "{body}";'
    # the type the game's code declares
    ds = decls.get(name, set())
    if len(ds) == 1:
        etype, ptr, has_dim = next(iter(ds))
        count = None
        if not ptr and etype not in ESZ:
            sc = struct_scalar(etype)
            if sc and len(data) % (ESZ[sc[0]] * sc[1]) == 0:
                vals = values(sc[0], "", data, syms, need)
                n = len(data) // (ESZ[sc[0]] * sc[1])
                if vals is not None and (has_dim or n == 1):
                    body = ", ".join(vals)
                    return (f"{q}{etype} {name}[{n:#x}] = {{ {body} }};" if has_dim
                            else f"{q}{etype} {name} = {{ {body} }};")
        elif ptr or etype in ESZ:
            es = 4 if ptr else ESZ[etype]
            vals = values(etype, ptr, data, syms, need)
            if vals is not None and (has_dim or len(data) == es):
                if not has_dim:
                    return f"{q}{etype} {ptr}{name} = {vals[0]};"
                return f"{q}{etype} {ptr}{name}[{len(data) // es:#x}] = {{ {', '.join(vals)} }};"
    # from the bytes
    if kinds == {"short"}:
        etype = "u16"
    elif len(data) % 4 == 0 and not syms and all(plain_float(data[i:i + 4]) for i in range(0, len(data), 4)) \
            and any(data):
        etype = "f32"
    elif len(data) % 4 == 0:
        etype = "s32"
    elif not syms:
        etype = "u8"
    else:
        return None
    vals = values(etype, "", data, syms, need)
    if vals is None:
        return None
    return f"{q}{etype} {name}[{len(data) // ESZ[etype]:#x}] = {{ {', '.join(vals)} }};"


SPACE = re.compile(r"/\* ([0-9A-F]{8}) \*/\s+\.space\s+(0x[0-9A-Fa-f]+|\d+)")
NOT_GAME = {"errno"}     # libc's, at the end of the game's .bss stretch


def bss_unit(src):
    """The C text of a .bss file: uninitialised objects. A label CodeWarrior
    could not have started an object at (its address is not aligned as an
    object of its size would be) is a field of the object before it, which
    takes its bytes; code still reaches it by its address (the linker's
    undefined-symbol list names it). CodeWarrior writes uninitialised objects
    in reverse definition order, so they are defined from the top down."""
    labels = []
    for line in Path(src).read_text().splitlines():
        m = re.match(r"dlabel (\S+)", line)
        if m:
            labels.append([m.group(1), None, 0])
            continue
        m = SPACE.search(line)
        if m and labels and labels[-1][1] is None:
            labels[-1][1], labels[-1][2] = int(m.group(1), 16), int(m.group(2), 0)
    labels = [l for l in labels if l[1] is not None]
    # fields folded in by an earlier run are aliases now, not splat labels:
    # read them back (config/data_aliases.txt), so a rerun folds them again
    stem0 = f"{'sbss' if '.sbss.' in src else 'bss'}_{labels[0][1]:08X}"
    at = {l[0]: l[1] for l in labels}
    if ALIASES.exists():
        m = re.search(rf"/\* {stem0} \*/\n((?:[^/\n][^\n]*\n)*)", ALIASES.read_text())
        for a in re.finditer(r"^(\w+) = (\w+) \+ 0x([0-9A-F]+);", m.group(1) if m else "", re.M):
            if a.group(2) in at and a.group(1) not in at:
                labels.append([a.group(1), at[a.group(2)] + int(a.group(3), 16), 0])
        labels.sort(key=lambda l: l[1])
        for i, l in enumerate(labels):      # sizes run to the next label
            nxt = labels[i + 1][1] if i + 1 < len(labels) else None
            if nxt is not None and (l[2] == 0 or l[1] + l[2] > nxt):
                l[2] = nxt - l[1]
    # _gp is the linker script's (the small data base), not an object's name
    for l in labels:
        if l[0] == "_gp":
            l[0] = data_name(l[1])
    cut = next((i for i, l in enumerate(labels) if l[0] in NOT_GAME), len(labels))
    labels = labels[:cut]
    natural = lambda n: 4 if n <= 4 else 8 if n < 16 else 16
    objs = []       # [name, addr, size, merged (name, addr)]
    for name, addr, size in labels:
        if objs and addr % natural(size):
            objs[-1][2] += size
            objs[-1][3].append((name, addr))
        else:
            objs.append([name, addr, size, []])
    decls = declared_types()
    start = objs[0][1]
    natural_of = lambda n: 4 if n <= 4 else 8 if n < 16 else 16
    wants = [min(natural_of(sz), a & -a, start & -start) for _, a, sz, _ in objs]
    # a rigid unit: the first object carries the largest alignment (see
    # unit_text)
    wants[0] = max(wants)
    defs = []
    for (name, addr, size, merged), want in zip(objs, wants):
        d = None
        ds = decls.get(name, set())
        if not merged and len(ds) == 1:
            etype, ptr, has_dim = next(iter(ds))
            if ptr and etype not in ESZ and not struct_scalar(etype):
                etype = "void"     # a type local to another file
            es = 4 if ptr else ESZ.get(etype) or (lambda sc: sc and ESZ[sc[0]] * sc[1])(struct_scalar(etype))
            if es and size % es == 0 and (has_dim or size == es):
                d = f"{etype} {ptr}{name}[{size // es:#x}]" if has_dim else f"{etype} {ptr}{name}"
        if d is None:
            d = f"u8 {name}[{size:#x}]"
        if want != natural(size):
            d += f" __attribute__((aligned({want})))"
        note = f" /* also {', '.join(n for n, _ in merged)} */" if merged else ""
        defs.append(d + ";" + note)
    aliases = [f"{n} = {name} + 0x{a - addr:X};" for name, addr, _, merged in objs for n, a in merged]
    stem = f"{'sbss' if '.sbss.' in src else 'bss'}_{start:08X}"
    out = ['#include "common.h"', "",
           f"/* {stem}: the game's {'.sbss' if '.sbss.' in src else '.bss'} from 0x{start:08X}, defined from the top down",
           "   (CodeWarrior writes uninitialised objects in reverse order). */", ""]
    return stem, "\n".join(out + defs[::-1]) + "\n", aliases


ALIASES = ROOT / "config/data_aliases.txt"


def write_aliases(stem, aliases):
    """config/data_aliases.txt: the names code uses inside an object (a field
    splat labelled), for ld; one block per unit."""
    head = ("/* Names code uses inside a data object, for ld: written by\n"
            "   tools/data_to_c.py, one block per unit. */\n")
    text = ALIASES.read_text() if ALIASES.exists() else head
    text = re.sub(rf"/\* {stem} \*/\n(?:[^/\n][^\n]*\n)*", "", text)
    if aliases:
        text = text.rstrip("\n") + f"\n/* {stem} */\n" + "\n".join(aliases) + "\n"
    ALIASES.write_text(text)


def unit_text(src, labels):
    """(stem, C text) of one data-only unit for a run of labels."""
    const = ".rodata." in src
    decls = declared_types()
    need, defs = set(), []
    for k, (name, addr, items, closed) in enumerate(labels):
        trim = closed
        d = define(name, items, decls, const, need, trim)
        if d is None:
            sys.exit(f"{src}: {name}: no type fits")
        # CodeWarrior aligns an object by its size (4 up to 4 bytes, 8 up to
        # 15, 16 beyond); retail packs some tighter, which aligned(N) gives
        # (capped at the alignment of the unit's start, so that the unit's
        # sections join as tools/lib_layout.py and ld agree on)
        size = len(obj_bytes(items, trim)[0])
        natural = 4 if size <= 4 else 8 if size < 16 else 16
        start = labels[0][1]
        want = min(natural, addr & -addr, start & -start)
        defs.append([d, natural, want])
        if trim and k == len(labels) - 1:
            # the unit's stretch ends after the padding, which is no object's:
            # a static of its own keeps it in the unit
            pad = len(to_bytes(items)[0]) - size
            if pad > 0:
                at = addr + size
                defs.append(f"static {'const ' if const else ''}u8 pad_{at:08X}[{pad:#x}]"
                            f" __attribute__((aligned({min(at & -at, 4)}))) = {{ 0 }};")
    # a rigid unit: its first object carries the largest alignment of any,
    # so ld starts the unit there and its offsets inside do not depend on
    # where the unit lands when the image shifts
    objs = [x for x in defs if isinstance(x, list)]
    objs[0][2] = max(o[2] for o in objs)
    for i, x in enumerate(defs):
        if isinstance(x, list):
            d, natural, want = x
            if want != natural:
                d = d.replace(" = ", f" __attribute__((aligned({want}))) = ", 1)
            defs[i] = d
    own = {n for n, *_ in labels}
    stem = f"{Path(src).name.split('.')[1]}_{labels[0][1]:08X}"
    out = ['#include "common.h"', "",
           f"/* {stem}: the game's data at 0x{labels[0][1]:08X}..., one object per label. */",
           "#pragma explicit_zero_data on", ""]
    ext = []
    for s in sorted(need):
        if is_func(s):
            ext.append(f"void {s}(void);")
        elif s not in own:
            ext.append(f"extern u8 {s}[];")
    fwd = [re.sub(r"\s*(__attribute__.*)?=.*$", ";", re.sub(r"\[[^\]]*\]", "[]", d)) for d in defs
           if d.split("=")[0].split()[-1].split("[")[0] in need]
    out += ext + ["extern " + f for f in fwd] + ([""] if ext or fwd else []) + defs
    return stem, "\n".join(out) + "\n"

def main():
    src = sys.argv[1]
    if ".bss." in src or ".sbss." in src:
        stem, text, aliases = bss_unit(src)
        if "--write" in sys.argv:
            dst = ROOT / "src/game/data" / f"{stem}.c"
            dst.write_text(text)
            print(dst.relative_to(ROOT))
            write_aliases(stem, aliases)
        else:
            sys.stdout.write(text)
        return
    labels = parse(src)
    # a jump table of an asm function is the function plus offsets (its
    # labels are local to that function's asm); it moves into the function's
    # unit once that is C
    runs = [labels]
    for run in runs:
        stem, text = unit_text(src, run)
        if "--write" in sys.argv:
            dst = ROOT / "src/game/data" / f"{stem}.c"
            dst.parent.mkdir(parents=True, exist_ok=True)
            dst.write_text(text)
            print(dst.relative_to(ROOT))
        else:
            sys.stdout.write(text)


if __name__ == "__main__":
    main()
