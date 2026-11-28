#!/usr/bin/env python3
"""Write build.ninja from config/link_order.us.txt, and objdiff.json beside it.

Every path in the build is relative to the repository root (ninja runs
there): the checkout may live under a directory with spaces in its name.

NONMATCHING (the default; `--matching` turns it off): every C compile gets
-DNONMATCHING, so a function written as

    #ifdef NONMATCHING
    ...best-effort C...
    #else
    INCLUDE_ASM(name);
    #endif

builds from its C and its asm chunk leaves the link. That image is not
retail's, so its default target is build/sta.elf; `--matching` builds the
asm and checks the ROM SHA-1 (the progress report wants that build).

Each C unit also gets a target object, build/target/src/<path>.o, assembled
from splat's per-function files and data files (asm/matchings, asm/data), so
objdiff can compare it with the compiled base object.
"""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
VER = "jp"

# SCE ee-as 2.10: unlike ee-as 2.9 it does not pad R5900 short loops with nops
EE_AS = "tools/cc/ee-gcc2.96/bin/as"
LD = "tools/cc/binutils-2.10-ee/bin/ld"
OBJDIFF = "tools/cc/objdiff-cli"

OBJDIFF_SCHEMA = "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json"
# the instruction comment of splat's function files: /* ROMOFF VRAM BYTES */
INSN = re.compile(r"/\* [0-9A-Fa-f]+ ([0-9A-Fa-f]{8}) ")
TARGET_HEAD = ('.include "macro.inc"\n\n.set noat\n.set noreorder\n\n'
               '.section .text, "ax"\n.align 3\n\n')


def link_order() -> list[str]:
    lines = (ROOT / f"config/link_order.{VER}.txt").read_text().splitlines()
    return [l.strip() for l in lines if l.strip() and not l.lstrip().startswith("#")]


def obj_for(src: str) -> str:
    return f"build/{src}.o"


def stem(src: str) -> str:
    return src.rsplit(".", 1)[0]


def c_parts(src: str) -> tuple[list[Path], list[Path]]:
    """The function files and data files splat wrote for a C unit."""
    name = src[len("src/"):-len(".c")]
    mdir = ROOT / "asm/matchings" / name
    funcs = sorted(mdir.glob("*.s")) if mdir.is_dir() else []
    datas = [ROOT / f"asm/data/{name}.{sec}.s" for sec in ("data", "rodata", "sdata", "sbss", "bss")]
    return funcs, [d for d in datas if d.exists()]


def vram_of(path: Path) -> int:
    m = INSN.search(path.read_text())
    if not m:
        raise SystemExit(f"{path}: no instruction comment")
    return int(m.group(1), 16)


def trimmed(path: Path) -> str:
    """A splat function file up to its endlabel: the bytes after it are splat's
    padding to the next symbol's alignment, which the C object does not have. A
    file with no endlabel is kept whole."""
    lines = path.read_text().splitlines(keepends=True)
    ends = [i for i, l in enumerate(lines) if l.startswith("endlabel")]
    if ends:
        lines = lines[:ends[0] + 1]
    return "".join(lines)


def zero_bytes(body: str) -> int | None:
    """The bytes a data directive holds, if they are all zero; else None."""
    d, _, arg = body.partition(" ")
    if d == ".asciz" and arg.strip() == '""':
        return 1
    if d not in (".word", ".byte", ".space"):
        return None
    try:
        n = int(arg, 0)
    except ValueError:      # a symbol, or a label
        return None
    if d == ".space":
        return n
    return (4 if d == ".word" else 1) if n == 0 else None


def jtbl_fill(text: str) -> str:
    """Drop the zero words at the end of a jump table (jtbl_ + 8 hex).

    Splat sizes a table up to the next symbol, and the zero words before it are
    the alignment fill, not table entries (the entries are .L labels)."""
    out, block = [], None
    for l in text.splitlines(keepends=True):
        if l.startswith("dlabel jtbl_"):
            block = []
        if block is not None:
            if l.startswith("enddlabel"):
                while block and block[-1].split("*/")[-1].strip() == ".word 0x00000000":
                    block.pop()
                out += block
                block = None
            else:
                block.append(l)
                continue
        out.append(l)
    return "".join(out)


def trailing_fill(text: str) -> str:
    """The data after the last symbol's content is not the C object's.

    Splat pads each symbol with .align up to the next one, and gives the
    alignment fill before the next unit a symbol of its own. After the last
    symbol's enddlabel (or after its body, when it has none), the .align lines
    and zero words are dropped; then so is that last symbol if it is an
    auto-named one (D_ + 8 hex) that holds only zeros and is under 16 bytes.
    The bss tail splat names _end is the same fill, whatever its size."""
    lines = text.splitlines(keepends=True)
    dl = [i for i, l in enumerate(lines) if l.startswith("dlabel ")]
    if not dl:
        return text
    start = dl[-1]
    el = next((i for i in range(start, len(lines)) if lines[i].startswith("enddlabel ")), None)
    body = lambda l: l.split("*/")[-1].strip()
    floor = el + 1 if el is not None else len(lines)
    stop = len(lines)
    while stop > floor:
        b = body(lines[stop - 1])
        if b and not b.startswith(".align") and zero_bytes(b) is None:
            break
        stop -= 1
    del lines[stop:]
    end = el if el is not None else len(lines)
    while end > start + 1 and body(lines[end - 1]).startswith(".align"):
        del lines[end - 1]
        end -= 1
    name, size, zero = lines[start].split()[1], 0, True
    for l in lines[start + 1:end]:
        b = body(l)
        if not b or b.startswith(".align"):
            continue
        n = zero_bytes(b)
        if n is None:
            zero = False
            break
        size += n
    # splat marks a symbol nothing references as a pad; fill before a
    # 64-aligned unit (the SIF DMA buffers) runs up to 63 bytes
    pad = start and "unreferenced pad" in lines[start - 1]
    if zero and (name == "_end" or (re.fullmatch(r"D_[0-9A-F]{8}", name)
                                    and size < (64 if pad else 16))):
        if pad:
            start -= 1
        if start and lines[start - 1].strip() == "":
            start -= 1
        if start and lines[start - 1].startswith("nonmatching "):
            start -= 1
        return "".join(lines[:start])
    return "".join(lines)


def target_src(out: str) -> str:
    """The C unit whose target source is build/target/src/<path>.s."""
    return "src/" + out[len("build/target/src/"):-len(".s")] + ".c"


def target_text(src: str) -> str:
    """One assembly file for a C unit: its functions in address order, then its data."""
    funcs, datas = c_parts(src)
    funcs = sorted(funcs, key=vram_of)
    if src.startswith("src/sce/"):
        # ee-gcc 8-aligns every function, so the fill between them is the C
        # object's too; only the fill after the last one is not
        text = TARGET_HEAD + "".join(f.read_text() for f in funcs[:-1])
        text += "".join(trimmed(f) for f in funcs[-1:])
    else:
        # a unit of several functions keeps the fill between them (each
        # function is a section of its own, at its alignment); only the fill
        # after the last one is not the C object's
        text = TARGET_HEAD + "".join(f.read_text() for f in funcs[:-1])
        text += "".join(trimmed(f) for f in funcs[-1:])
    mwcc = not src.startswith(("src/sce/", "src/game/ee/"))
    for d in datas:
        raw = d.read_text()
        # ee-gcc keeps the alignment word after a jump table in its .rodata
        # (the strings after it are 8-aligned); CodeWarrior does not
        if src.startswith("src/game/data/"):
            # a data-only unit (tools/data_to_c.py) defines splat's file
            # byte for byte, its trailing zeros included, up to the commons
            # ld lays out after it (libc's errno ends the game's .bss)
            body = re.split(r"^nonmatching errno\b.*$", raw, maxsplit=1, flags=re.M)[0]
            # a jump table of an asm function: entries as function + offset,
            # as the C has them (the .L labels are that function's)
            body = JT_ENTRY.sub(lambda m: jt_entry(int(m.group(1), 16)) or m.group(0), body)
        else:
            body = trailing_fill(raw if src.startswith("src/sce/") else jtbl_fill(raw))
        body = body.splitlines(keepends=True)
        text += "".join(l for l in body if l.strip() != '.include "macro.inc"')
    for a, b in TARGET_FIXUPS.get(src, []):
        assert a in text, f"{src}: no {a!r} to fix"
        text = text.replace(a, b)
    if not mwcc:
        text = unlabel(text)
    else:
        # jlabel makes each jump table target a global symbol, so objdiff
        # resolves a target table entry to it and not to the function, as it
        # does for CodeWarrior's (relocated against the function)
        text = re.sub(r"^(\s*)jlabel (\.L\w+)\s*$", r"\1\2:", text, flags=re.M)
    return text if text.endswith("\n") else text + "\n"


JT_ENTRY = re.compile(r"\.word \.L([0-9A-F]{8})\b")
_FUNC_STARTS: list[tuple[int, str]] = []


def jt_entry(addr: int) -> str | None:
    """`.word FUNC + 0xOFF` for an address inside one of splat's functions."""
    import bisect
    if not _FUNC_STARTS:
        for p in (ROOT / "asm").rglob("*.s"):
            if "data" in p.parts:
                continue
            for m in re.finditer(r"^glabel (\w+)\n(?:.*\n)*?.*?/\* [0-9A-F]+ ([0-9A-F]{8}) ",
                                 p.read_text(), re.M):
                _FUNC_STARTS.append((int(m.group(2), 16), m.group(1)))
        _FUNC_STARTS.sort()
    i = bisect.bisect_right(_FUNC_STARTS, (addr, "\xff")) - 1
    if i < 0:
        return None
    start, name = _FUNC_STARTS[i]
    return f".word {name} + 0x{addr - start:X}"


# Words splat cannot render as the C object has them, per unit: a pointer
# into the middle of a function (splat has no symbol there) and a TLB
# physical address that happens to equal the entry point's.
TARGET_FIXUPS = {
    "src/sce/libkernl/tlbfunc.c": [
        ("*/ .word 0x00114440", "*/ .word _kTLBTrap + 0x140"),
        ("*/ .word func_00100000", "*/ .word 0x00100000"),
    ],
}

AUTO_DLABEL = re.compile(r"^dlabel ((?:D|jtbl)_[0-9A-F]{8})\b", re.M)


def unlabel(text: str) -> str:
    """Turn splat's invented data names (D_XXXXXXXX, jtbl_XXXXXXXX) into
    assembler-local .L labels. ee-gcc emits its string literals, constants and
    jump tables as unnamed .LC/.L data reached through section-relative
    relocations, so the base object has no symbols there; objdiff pairs data
    by symbol, and a named target symbol has nothing to pair with."""
    names = set(AUTO_DLABEL.findall(text))
    if not names:
        return text
    alt = "|".join(sorted(names))
    text = re.sub(rf"^(?:enddlabel|nonmatching) (?:{alt})\b.*\n", "", text, flags=re.M)
    text = re.sub(rf"^dlabel ({alt})\b.*$", r".L\1:", text, flags=re.M)
    return re.sub(rf"(?<![\w.])({alt})\b", r".L\1", text)


def write_if_changed(path: Path, text: str) -> None:
    """Rewrite only on a content change, so ninja does not rebuild needlessly."""
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists() and path.read_text() == text:
        return
    path.write_text(text)


# GAME_START: where the game begins in each section (tools/lib_layout.py)
sys.path.insert(0, str(ROOT / "tools"))
from lib_layout import GAME_START  # noqa: E402

UNIT_SECTION = {"text": ".text", "data": ".data", "rodata": ".rodata", "bss": ".bss"}


def asm_category(src: str) -> str:
    """An asm unit is sce when it starts before the game start of its section
    (the stretches tools/carve.py leaves between library units), else game:
    splat's base-named units (text, data, ...) and the stretches between game
    C units."""
    m = re.match(r"(text|data|rodata|bss)_([0-9A-F]{8})\.", Path(src).name)
    if not m:
        return "game"
    return "sce" if int(m.group(2), 16) < GAME_START[UNIT_SECTION[m.group(1)]] else "game"


def category(src: str) -> str:
    if src.startswith("asm/"):
        return asm_category(src)
    return "sce" if src.startswith("src/sce/") else "game"


def is_mwcc(src: str) -> bool:
    return src.startswith("src/game/") and not src.startswith("src/game/ee/")


def objdiff_base(src: str) -> str:
    """The object objdiff diffs for a C unit (tools/objdiff_base.py for
    CodeWarrior units: data sections merged and paired by name)."""
    return f"build/objdiff/{stem(src)}.o" if is_mwcc(src) else obj_for(src)


def objdiff_config(srcs: list[str]) -> dict:
    units = []
    for s in srcs:
        cat = category(s)
        unit = {"name": s.split("/", 1)[1].rsplit(".", 1)[0],
                "metadata": {"progress_categories": [cat]}}
        if s.startswith("asm/"):
            unit["target_path"] = obj_for(s)
        elif s.startswith("src/") and s.endswith(".c"):
            unit["target_path"] = f"build/target/{stem(s)}.o"
            unit["base_path"] = objdiff_base(s)
            unit["metadata"]["source_path"] = s
        else:
            # hand-written asm: the same object is both target and base
            unit["target_path"] = unit["base_path"] = obj_for(s)
            unit["metadata"]["source_path"] = s
            unit["metadata"]["complete"] = True
        units.append(unit)
    watch = [f"{root}/**/*.{ext}" for root in ("src", "include")
             for ext in ("c", "h", "s", "inc")]
    return {
        "$schema": OBJDIFF_SCHEMA,
        "custom_make": "ninja",
        "build_base": True,
        "build_target": False,
        "watch_patterns": watch,
        "progress_categories": [{"id": "game", "name": "Game"},
                                {"id": "sce", "name": "SDK and runtime libraries"}],
        "units": units,
    }


USES_ASM = re.compile(r"^\s*INCLUDE_ASM\(\s*(\w+)\s*\)\s*;", re.M)
NONMATCHING = True     # main() sets it from --matching


def asm_markers(text: str) -> tuple[list[str], list[str]]:
    """The INCLUDE_ASM names a source compiles to, in order, and those it
    drops: a marker in the #else of `#ifdef NONMATCHING` (or the body of
    `#ifndef NONMATCHING`) is dropped in a NONMATCHING build, whose C
    stands in for it."""
    used, dropped, stack = [], [], []      # stack: is this branch dropped?
    for line in text.splitlines():
        d = re.match(r"\s*#\s*(ifdef|ifndef|if|else|elif|endif)\b\s*(\w*)", line)
        if d:
            kw, arg = d.groups()
            if kw in ("ifdef", "ifndef", "if"):
                nm = arg == "NONMATCHING" and kw != "if"
                # (is a NONMATCHING branch, branch dropped)
                stack.append((nm, nm and NONMATCHING == (kw == "ifndef")))
            elif kw in ("else", "elif") and stack:
                nm, dr = stack[-1]
                stack[-1] = (nm, nm and not dr)
            elif kw == "endif" and stack:
                stack.pop()
            continue
        m = USES_ASM.match(line)
        if m:
            (dropped if any(dr for _, dr in stack) else used).append(m.group(1))
    return used, dropped


def include_asm_units(srcs: list[str]) -> dict[str, list[str]]:
    """C unit -> the asm chunks its INCLUDE_ASM markers name, in order
    (include/include_asm.h): the chunk in the link order whose first label
    is the name."""
    first_label = {}
    for s in srcs:
        if s.startswith("asm/") and s.endswith(".s") and (ROOT / s).exists():
            m = re.search(r"^\s*glabel (\w+)", (ROOT / s).read_text(), re.M)
            if m:
                first_label[m.group(1)] = s
    out = {}
    for s in srcs:
        if s.startswith("src/game/") and s.endswith(".c") and (ROOT / s).exists():
            names = asm_markers((ROOT / s).read_text())[0]
            if names:
                missing = [n for n in names if n not in first_label]
                if missing:
                    raise SystemExit(f"{s}: INCLUDE_ASM of no asm chunk's first label: {', '.join(missing)}")
                out[s] = [first_label[n] for n in names]
    return out


def include_asm_text(srcs: list[str], objs: list[str]) -> list[str]:
    """The .text inputs in link order, an INCLUDE_ASM unit's asm chunks
    between its sections (unit(.text), chunk(.text), unit(.text.ia1), ...)."""
    uses = include_asm_units(srcs)
    taken = {c for cs in uses.values() for c in cs}
    out = []
    for s, o in zip(srcs, objs):
        if s in taken:
            continue
        out.append(f"{o}(.text)")
        for k, c in enumerate(uses.get(s, []), 1):
            out += [f"{obj_for(c)}(.text)", f"{o}(.text.ia{k})"]
    return out


def data_twin_sources() -> tuple[list[str], list[str]]:
    """The game units with NONMATCHING data twins and the data units whose
    definitions they twin (tools/split_data.py)."""
    owners, units = [], []
    for p in sorted((ROOT / "src/game").rglob("*.c")):
        t = p.read_text()
        rel = str(p.relative_to(ROOT))
        if rel.startswith("src/game/data/"):
            if "#ifndef NONMATCHING /* the NONMATCHING build defines these in" in t:
                units.append(rel)
        elif "/* data twins (" in t:
            owners.append(rel)
    return owners, units


def replaced_chunks(srcs: list[str]) -> set[str]:
    """The asm chunks a NONMATCHING build leaves out: their C stands in."""
    first_label = {}
    for s in srcs:
        if s.startswith("asm/") and s.endswith(".s") and (ROOT / s).exists():
            m = re.search(r"^\s*glabel (\w+)", (ROOT / s).read_text(), re.M)
            if m:
                first_label[m.group(1)] = s
    out = set()
    for s in srcs:
        if s.startswith("src/game/") and s.endswith(".c") and (ROOT / s).exists():
            for n in asm_markers((ROOT / s).read_text())[1]:
                if n not in first_label:
                    raise SystemExit(f"{s}: INCLUDE_ASM of no asm chunk's first label: {n}")
                out.add(first_label[n])
    return out


def main() -> None:
    global NONMATCHING
    NONMATCHING = "--matching" not in sys.argv[1:]
    if sys.argv[1:2] == ["--target"]:
        # the target_src rule (restat): rewrites one target source, and only on
        # a content change
        out = sys.argv[2]
        write_if_changed(ROOT / out, target_text(target_src(out)))
        return
    srcs = link_order()
    # NONMATCHING: a chunk whose function is C leaves the link (the objdiff
    # units, written below from the whole link order, stay as they are)
    all_srcs = srcs
    if NONMATCHING:
        gone = replaced_chunks(srcs)
        srcs = [s for s in srcs if s not in gone]
    objs = [obj_for(s) for s in srcs]
    build = ROOT / "build"
    build.mkdir(exist_ok=True)
    script = (ROOT / f"config/sta.{VER}.ld.in").read_text()
    text_inputs = include_asm_text(srcs, objs)
    script = re.sub(r"@INPUTS:(\w+)@",
                    lambda m: "\n        ".join(text_inputs if m.group(1) == "text" else
                                                [f"{o}(.{m.group(1)})" for o in objs]), script)
    (build / "sta.ld").write_text(script)
    # the shift test (tools/shift_check.py): the same link with a pad
    # inserted, so every pointer must move with what it points at
    first_game = next(o for s, o in zip(srcs, objs) if s.startswith("src/game/"))
    shifts = {
        "data_100": (".data    ALIGN(0x80) : {", ".data    ALIGN(0x80) : {\n        . += 0x100;"),
        "data_4": (".data    ALIGN(0x80) : {", ".data    ALIGN(0x80) : {\n        . += 0x4;"),
        "bss_40": (".bss     ALIGN(0x80) (NOLOAD) : {", ".bss     ALIGN(0x80) (NOLOAD) : { . += 0x40;"),
        "text_100": (f"{first_game}(.text)", f". += 0x100;\n        {first_game}(.text)"),
    }
    (build / "shift").mkdir(exist_ok=True)
    for name, (a, b) in shifts.items():
        assert a in script, name
        (build / "shift" / f"{name}.ld").write_text(script.replace(a, b, 1))

    c_units = [s for s in srcs if s.startswith("src/") and s.endswith(".c")]
    # one objdiff unit per link-order entry
    (ROOT / "objdiff.json").write_text(json.dumps(objdiff_config(all_srcs), indent=2) + "\n")

    n = []
    n.append("# Generated by tools/gen_ninja.py; do not edit.\n")
    n.append("rule as\n"
             f"  command = tools/period_env.sh {EE_AS} -EL -mcpu=5900 -mabi=eabi -G 8 -Iinclude -o $out $in\n"
             "  description = AS $in\n")
    n.append(f"# NONMATCHING: {'on' if NONMATCHING else 'off (--matching)'}\n")
    n.append("rule cc\n"
             f"  command = {'CDEFS=-DNONMATCHING ' if NONMATCHING else ''}tools/compile_c.sh $in $out\n"
             "  description = CC $in\n")
    n.append("rule ld\n"
             f"  command = {LD} -T build/sta.ld -Map build/sta.map -o $out $in $syms\n"
             "  description = LD $out\n")
    n.append("rule rom\n"
             "  command = .venv/bin/python tools/check.py rom $in $out\n"
             "  description = ROM $out\n")
    n.append("rule check\n"
             "  command = .venv/bin/python tools/check.py verify $in && touch $out\n"
             "  description = CHECK $in\n")
    n.append("rule target_src\n"
             "  command = .venv/bin/python tools/gen_ninja.py --target $out\n"
             "  restat = 1\n"
             "  description = TARGET $out\n")
    # no depfiles: every C unit depends on every header, so a header edit rebuilds them
    hdrs = " ".join(sorted(str(h.relative_to(ROOT)) for h in (ROOT / "include").rglob("*.h")))
    for s, o in zip(srcs, objs):
        # src/ holds C and hand-written asm (assembled per origin by
        # compile_c.sh); asm/ is splat's output
        rule = "cc" if s.startswith("src/") else "as"
        # a change to how units are compiled rebuilds them
        dep = " | include/macro.inc" if rule == "as" else " | tools/compile_c.sh tools/mwfix.py config/game_cflags.txt " + hdrs
        n.append(f"build {o}: {rule} {s}" + dep)
    for s in c_units:
        # the .s is rewritten only when its content changes (restat), so the
        # object is not rebuilt needlessly
        t = f"build/target/{stem(s)}.s"
        funcs, datas = c_parts(s)
        deps = " ".join(["tools/gen_ninja.py"] + [str(p.relative_to(ROOT)) for p in funcs + datas])
        n.append(f"build {t}: target_src | {deps}")
        n.append(f"build build/target/{stem(s)}.o: as {t} | include/macro.inc")
    n.append("rule objdiff_base\n"
             "  command = .venv/bin/python tools/objdiff_base.py $in $out\n"
             "  description = OBJDIFF $out\n")
    for s in c_units:
        if is_mwcc(s):
            n.append(f"build {objdiff_base(s)}: objdiff_base {obj_for(s)} build/target/{stem(s)}.o"
                     " | tools/objdiff_base.py")
    # splat's lists of addresses referenced but not defined yet, given to ld
    # as implicit linker scripts
    # (tools/rel_syms.py writes them relative to the objects they lie in, so
    # they follow when the image shifts)
    syms = "config/linker_syms.txt config/data_aliases.txt config/undefined_syms_auto.txt config/undefined_funcs_auto.txt"
    n.append("rule rel_syms\n"
             "  command = .venv/bin/python tools/rel_syms.py $out $objs\n"
             "  description = SYMS $out")
    n.append(f"build build/rel_syms.ld: rel_syms | {' '.join(objs)} {syms} tools/rel_syms.py\n"
             f"  objs = {' '.join(objs)}")
    n.append(f"build build/sta.elf: ld {' '.join(objs)} | build/sta.ld build/rel_syms.ld\n"
             f"  syms = build/rel_syms.ld")
    n.append("rule ld_shift\n"
             f"  command = {LD} -T $script -o $out $in $syms\n"
             "  description = LD $out")
    for name in shifts:
        n.append(f"build build/shift/{name}.elf: ld_shift {' '.join(objs)} | build/shift/{name}.ld build/rel_syms.ld\n"
                 f"  script = build/shift/{name}.ld\n"
                 f"  syms = build/rel_syms.ld")
    n.append("rule shift_check\n"
             "  command = .venv/bin/python tools/shift_check.py $in\n"
             "  description = SHIFT CHECK\n"
             "  pool = console")
    n.append(f"build shift: shift_check build/sta.elf {' '.join(f'build/shift/{k}.elf' for k in shifts)}"
             " | tools/shift_check.py")
    n.append("build build/sta.rom: rom build/sta.elf")
    n.append("build build/sta.ok: check build/sta.rom")
    # NONMATCHING data twins (tools/split_data.py): the side of each pair the
    # current build does not compile goes to build/twins/, and
    # tools/check_data_twins.py compares the two (part of the default)
    owners, units = data_twin_sources()
    other = units if NONMATCHING else owners
    n.append("rule cc_other\n"
             f"  command = {'' if NONMATCHING else 'CDEFS=-DNONMATCHING '}tools/compile_c.sh $in $out\n"
             "  description = CC (other build) $in\n")
    twin_objs = []
    for s in other:
        o = f"build/twins/{s}.o"
        twin_objs.append(o)
        n.append(f"build {o}: cc_other {s} | tools/compile_c.sh tools/mwfix.py config/game_cflags.txt " + hdrs)
    mine = [obj_for(s) for s in (owners if NONMATCHING else units)]
    n.append("rule check_twins\n"
             "  command = .venv/bin/python tools/check_data_twins.py --stamp $out\n"
             "  description = CHECK data twins\n")
    n.append(f"build build/twins.ok: check_twins {' '.join(twin_objs + mine)} | tools/check_data_twins.py")
    n.append("build nonmatching: phony build/sta.elf")
    n.append("rule regen\n"
             f"  command = .venv/bin/python tools/gen_ninja.py{'' if NONMATCHING else ' --matching'}\n"
             "  generator = 1\n"
             "  description = REGEN build.ninja\n")
    # a unit with INCLUDE_ASM markers lays out the .text (a marker added to
    # another unit: tools/merge_tu.py reruns this)
    regen_in = ["tools/gen_ninja.py", f"config/link_order.{VER}.txt",
                f"config/sta.{VER}.ld.in"] + sorted(include_asm_units(srcs)) \
        + sum(data_twin_sources(), [])
    n.append(f"build build.ninja build/sta.ld objdiff.json: regen | {' '.join(regen_in)}")
    # objdiff's progress report over every object of the link
    all_objs = objs + [f"build/target/{stem(s)}.o" for s in c_units] \
        + [objdiff_base(s) for s in c_units if is_mwcc(s)]
    n.append("rule report\n"
             f"  command = {OBJDIFF} report generate -o $out\n"
             "  description = REPORT $out\n")
    n.append(f"build build/report.json: report {' '.join(all_objs)} | objdiff.json {OBJDIFF}")
    # `progress` writes no file, so ninja runs it on every call and the
    # summary always prints (console pool: the output is not captured)
    n.append("rule progress\n"
             "  command = .venv/bin/python tools/progress.py --html build/progress.html\n"
             "  description = PROGRESS\n"
             "  pool = console\n")
    n.append("build progress: progress build/report.json | tools/progress.py")
    n.append(f"default {'build/sta.elf' if NONMATCHING else 'build/sta.ok'} build/twins.ok")
    (ROOT / "build.ninja").write_text("\n".join(n) + "\n")
    mode = f"NONMATCHING ({len(all_srcs) - len(srcs)} asm chunks replaced by C)" if NONMATCHING else "matching"
    print(f"build.ninja: {len(srcs)} units, {len(c_units)} target objects, {mode}")


if __name__ == "__main__":
    main()
