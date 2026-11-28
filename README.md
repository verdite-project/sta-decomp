# sta-decomp

A matching decompilation of **Shadow Tower Abyss** (FromSoftware, 2003) for the
PlayStation 2. The target is the Japanese retail boot ELF, `SLPS_252.17`
(SLPS-25217). The goal is C source that the original toolchain compiles back
into the identical executable.

**Status:** the build reproduces the retail ROM image (all bytes the console
loads) **byte for byte**. 71 SDK, libc, libm and libgcc units build from C
and hand-written asm (`src/sce/`, about 26 KB of `.text`); the rest of the
libraries and the whole game are still splat-disassembled assembly. See
[`docs/ROADMAP.md`](docs/ROADMAP.md).

> No disc data is in this repository. You supply your own disc image; the
> build extracts the ELF from it and checks its SHA-1.

## Quickstart

```sh
mkdir -p baserom
ln -s "/path/to/Shadow Tower Abyss (Japan).iso" baserom/sta_jp.iso
./build.sh
```

`build.sh` runs whatever is missing:

1. `tools/setup.sh` creates `.venv`, fetches the compilers and wibo into
   `tools/cc/`, builds GNU ld 2.10 and dvp-as from source, and fetches
   objdiff-cli.
2. `tools/extract_elf.py` writes `baserom/jp/SLPS_252.17` and
   `baserom/jp/sta.rom` (the ELF's load segment) and checks both SHA-1s.
3. `tools/split.py` runs splat and writes `asm/`.
4. `tools/gen_ninja.py` and `ninja` assemble, compile and link with ld 2.10;
   a `--matching` build then checks the ROM SHA-1.

### Matching and NONMATCHING builds

`./build.sh` makes a **NONMATCHING** build by default: every C compile gets
`-DNONMATCHING`, and each function that has best-effort C builds from it in
place of its retail asm. The image, `build/sta.elf`, is not retail's (the
code differs, so everything after it moves), but each such function was
checked to do what the retail code does. `./build.sh --matching` (or
`tools/gen_ninja.py --matching`) builds the asm instead and checks the ROM
SHA-1. The progress report (`ninja progress`) measures the matching build in
either mode: a NONMATCHING build also compiles each C unit without
`-DNONMATCHING` into `build/matching/` for objdiff.

A function with best-effort C looks like

```c
#ifdef NONMATCHING
/* best-effort C: foo.c */
#else
INCLUDE_ASM(Foo_0_00123450);
#endif
```

and its C sits in a file of its own under `#ifdef NONMATCHING` (empty in a
matching build), so it keeps the declarations it was written with. The
matching attempts stay in `wip/`.

Data follows the same split: where an object cannot move into the unit that
uses it for the matching build, the owner defines a twin of it under
`#ifdef NONMATCHING` and its data unit keeps the retail definition under
`#ifndef NONMATCHING`; `tools/check_data_twins.py` (part of every build)
checks the two agree. See "Data owners" in `docs/ROADMAP.md`.

Host requirements: 64-bit Linux with 32-bit glibc (the ee-gcc tools are i386
binaries), a host gcc with `-m32` support, flex, bison, curl, git and Python 3.
Arch: `sudo pacman -S lib32-glibc lib32-gcc-libs flex bison`.

| file | SHA-1 |
| --- | --- |
| `SLPS_252.17` | `453dec1fb7f64de7cc6b08cc15719b1266231d59` |
| `sta.rom` (non-empty PT_LOAD bytes, i.e. `objcopy -O binary`) | `e2742b309441802b4a6809a346760a2dfcc6fd4d` |

## Progress

`ninja build/report.json` runs objdiff-cli over every unit (`objdiff.json`,
written by `tools/gen_ninja.py`, one unit per link-order entry in the
categories `game` and `sce`); C units get a target object assembled from
splat's per-function asm of the retail code, so the objdiff GUI also works on
this checkout. `ninja progress` prints the summary and writes
`build/progress.html`, a local per-function page (not committed).
`tools/progress.py --write` refreshes `docs/progress/` (a summary without
per-function data, shields badges and a static page) and the table below;
commit those with each batch of work. The disc is needed to build, so CI
cannot produce the report.

<!-- progress:start -->
| | code | functions | units complete |
| --- | ---: | ---: | ---: |
| overall | 90.49% | 2969 / 3091 | 15 / 2404 |
| game | 88.55% | 2102 / 2224 | 0 / 2215 |
| sce | 100.00% | 867 / 867 | 15 / 189 |
<!-- progress:end -->

## Function names

Every game function is named `<Name>_<certainty>_<ADDR>`, for example
`Snd_PlaySe_3_00131600`; `.c` units named after a function follow the same
scheme. The certainty (0-5) says how sure the name is accurate and
representative:

| certainty | meaning |
| ---: | --- |
| 5 | confirmed (e.g. a 1.000 match against KFIV/holyland's named code) |
| 4 | strong outside evidence (a close KFIV match) |
| 3 | clear evidence in the function itself (file-path strings, SDK calls, an unambiguous body) |
| 2 | well supported by its callees and callers |
| 1 | subsystem clear, exact role guessed; or a purely mechanical name (`Enemy_Get5B4b5`) |
| 0 | best guess from shape and callees |

Anything below 5 is up for review, and a certainty can change at any time.
Names live in `config/game_func_names.txt` (address, name, certainty); after
editing it, run `tools/apply_names.py` and rebuild. `tools/name_dossier.py
START END` prints each function's strings, callees and C to help with naming.

## Data names

Game data keeps splat's `D_<ADDR>` until what it is is settled; then it is
named `g<Name>_<ADDR>` (no certainty digit, so it never reads as a
function), for example `gMcState_004B63B8`. An object whose owner is known
but not its purpose is named after the owner unit and its section
(`gGsPacketBss_002F1194`); rename it once its purpose is settled. `config/game_data_names.txt`
lists the names and `tools/apply_data_names.py` applies them to the tree
(sources, config, both copies of a data twin); rerun the split afterwards
(`rm -rf asm; ./build.sh --matching`) so `asm/` has them too.

## Adding library units

Put the source under `src/sce/<lib>/` and run `tools/carve.py --check`: it
compiles every unit, places it in the retail ELF (`tools/lib_layout.py`) and
stops on anything that does not match as a whole. `tools/carve.py` then
rewrites the splat subsegments in `config/sta.jp.yaml`,
`config/link_order.jp.txt` and `config/symbol_addrs.carve.txt`; delete `asm/`
and run `./build.sh --matching` to re-split and check the ROM.

## Toolchain

Unlike King's Field IV (ee-gcc 2.9), the game is built with **Metrowerks
CodeWarrior for PS2** and linked with `mwldps2`, which wrote the ELF as one
PROGBITS blob with no section table. Three of the game's modules were built
with ee-gcc instead, and the Sony libraries are Sony's own ee-gcc builds.
`tools/probe_compiler.py` checks these choices against the retail code.

| tool | role |
| --- | --- |
| mwccps2 3.0b52-030722 `-O4,p` (or 3.0b38/b50: they match the same) | compiles the game |
| ee-gcc 2.96-ee-001003-1 `-O2 -G 8 -fno-strict-aliasing` | compiled the game's three gcc modules (`src/game/ee/`) |
| ee-gcc 2.9-ee-991111-01 | compiled Sony's SDK 2.5 libraries |
| ee-gcc 2.96-ee-001003-1 | compiled libc, libm and libgcc |
| SCE ee-as 2.10-ee-001003-1 (from ee-gcc 2.96) | assembles splat's asm and the ee-gcc output |
| GNU ld 2.10 + R5900/DVP patches | links (the ROM image does not depend on mwldps2) |
| wibo | runs the Win32 CodeWarrior tools |

SDK library versions in the binary: libkernl, libcdvd, libmc, libpad, libipu,
libgraph, libdma and libsdr, all 2.5.0.0. More than 540 library functions
compiled from ICO's reconstructed sources (SDK 2.2.x) are **byte-identical**
to code in this ELF and are named in `config/symbol_addrs.txt`.

## Layout

```
config/    splat yaml, symbol_addrs.txt (+ .carve.txt, generated),
           link_order.jp.txt (generated), linker-script template,
           linker_syms.txt, sha1sums.txt
include/   macro.inc (splat asm macros for the period assembler)
src/       C sources as they are decompiled (src/sce/ for SDK libraries)
tools/     setup, extraction, split, build generation and check scripts
wip/       near-misses and inline-asm matches, kept out of the build
docs/      roadmap and notes
asm/  baserom/  build/  tools/cc/  .venv/    generated or local, gitignored
```

## Credits and licence

About 780 of the game's matched functions, the shared game types in
`include/` and `docs/MATCHING.md` come from KiskarFisk's
[shadow-tower-abyss](https://github.com/KiskarFisk/shadow-tower-abyss)
(made on the English-patched ELF, whose code is the same as retail), merged
with its history.

The binutils patches, the obstack shim (`tools/period_obstack.c`) and the
toolchain recipe come from the ico decompilation (MIT, © the ico
decompilation contributors; notice in [`tools/LICENSE.ico`](tools/LICENSE.ico)),
by way of kfiv-decomp. This project has no affiliation with FromSoftware or
Sony Interactive Entertainment.
