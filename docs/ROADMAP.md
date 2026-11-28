# Roadmap

## Where things stand (2026-11-24)

- [x] Disc extraction with SHA-1 checks
- [x] Compilers identified (`tools/probe_compiler.py`): mwccps2 3.0b38/b50/b52
      `-O4,p` for the game; ee-gcc 2.96 `-O2 -G 8 -fno-strict-aliasing` for
      three game modules; Sony's SDK 2.5 libraries built with ee-gcc
      2.9-991111-01; libc/libm/libgcc built with ee-gcc 2.96
- [x] Library/game boundary in every section
- [x] Section boundaries recovered (the retail ELF has no section table)
- [x] splat split (one asm unit for `.text`, one per data section)
- [x] All-asm build with SCE ee-as 2.10 and ld 2.10 → **ROM SHA-1 matches**
- [x] 542 SDK/libc/libm/libgcc functions named by compiling ICO's library
      sources and scanning `.text` (`tools/find_lib_matches.py`)
- [x] `tools/compile_c.sh`: mwccps2 (under wibo) for the game, ee-gcc for
      the libraries
- [x] objdiff progress reports (`ninja build/report.json`, `ninja progress`)
      and the committed summary in `docs/progress/` (`tools/progress.py --write`)
- [x] 71 library units carved (`tools/carve.py`): they build from ICO's
      C and hand-written asm in `src/sce/`, with their data, and the ROM
      still matches
- [ ] The other library members (SDK 2.5 changes, see step 1)
- [ ] Split the game's `.text` into translation units
- [ ] First game function matched in the build (14 already match as probes)
- [ ] Whole-ELF match (mwldps2 output: one PROGBITS blob, `.mwcats`,
      `.comment`, `.reginfo`, the empty second PT_LOAD)

## Memory map (retail ELF)

`mwldps2` merged every loadable section into one unnamed PROGBITS section
(0x00100000–0x00201E80), so these boundaries come from the code and from
where the library units' sections were placed.

| section | VMA | size | how it was found |
| --- | --- | --- | --- |
| .text | 0x00100000 | 0xEDE80 | the last game function ends at 0x1EDE58, nop fill to 0x1EDE80 |
| .data | 0x001EDE80 | 0xAA00 | starts with libgraph's `PsIIlibgraph2500` string; every unit's .data in link order |
| .rodata | 0x001F8880 | 0x9300 | in the same output range as .data; starts with libgraph's `rom0:ROMVER` |
| .sdata | 0x00201B80 | 0x300 | `_gp` − 0x7FF0, the lowest gp-relative address |
| .sbss | 0x00201E80 | 0x600 | `_fbss`, which crt0 clears from; gp-relative code reaches 0x202420 |
| .bss | 0x00202480 | 0x2BBD00 | starts with crt0's .bss (crt0 reads 0x202480); to 0x4BE180 |

`_gp` = 0x00209B70 (`.reginfo`). The data between 0x1EF7A8 and 0x1EF7F0
that looks like code is most likely libkernl's kernel patch (copied to
0x8007xxxx at run time), and sits in .data. splat finds about 3,090 functions.

### Where the libraries are

Unlike KFIV, the libraries come **first** in every section, right after
crt0, and the game last:

| range | contents |
| --- | --- |
| 0x100000 | crt0 (`_start` = 0x100008) |
| 0x1003A0–0x11A000 | libgraph, libdma, libdev, libvu0, libmpeg, libipu, libkernl, libpad, libcdvd, libmc |
| 0x11C470–0x128204 | libm, libgcc, libc (newlib, members in archive order; `__swsetup` is last) |
| 0x128210–0x1EDE58 | the game |

### Library/game boundary

Library code and game code do not reference each other's data across these
lines, and the code on each side is the other compiler's (CodeWarrior saves
callee-saved registers with `sq`/`lq`, ee-gcc with `sd`/`ld`):

| section | library up to | game from | evidence |
| --- | --- | --- | --- |
| .text | 0x128204 (`__swsetup`, then nop fill) | 0x128210 | first `sq`/`lq` function |
| .data | 0x1F1AF0 (libc's malloc lock variables) | 0x1F1AF0 | first address game code references |
| .rodata | 0x1FAAE4 (vfprintf's table, then fill) | 0x1FAAE8 | `sta_abyss.ico` |
| .sdata, .sbss | (the libraries are `-G 0`) | all | |
| .bss | 0x209700 (last library object at 0x2096C0, 0x40 bytes) | 0x209700 | first address game code references |

`GAME_START` in `tools/carve.py` holds these. The game's asm units (`text`,
`data`, `rodata`, `bss`) start there; the stretch between the last placed
library unit and the game start is a library (`sce`) asm unit.

Inside the game, three runs of code are ee-gcc output, not CodeWarrior:
0x1D3A90–0x1D7EC0 (memory card, pad and file wrappers over sceMc*, scePad*
and sceRead/sceLseek, and tables of 0x1C0-byte records), 0x1DC328–0x1DC900
(VU0 macro helpers) and 0x1E1E08–0x1E5E80 (GS packet and image upload
helpers, `se/m%3.03ds.mse`). ee-gcc aligns functions to 8 and CodeWarrior to
16, which is how the third was found and the second's end fixed: 0x1E6040,
0x1E6060 and 0x1E6080 match under CodeWarrior, not ee-gcc.
They are FromSoftware's, linked among the game objects (the `sceSifGetSreg`
bytes at 0x1D6FF0 are one of their functions). The edges are function
granular: leaf functions with no saved registers on either side still have to
be assigned.

## Next steps, in order

### 1. The rest of the library units

`tools/carve.py` (kfiv-decomp's, adapted) carved the 71 of kfiv-decomp's
183 library units that place whole: 34 libc, 12 libdev, 9 libgraph, 7
libkernl, 3 libcdvd, 3 libm, 2 libgcc, libipu and libmpeg. The other 112
were left out of `src/sce/` and are still asm (kfiv-decomp has the sources):

- **SDK 2.5 changes.** ICO's sources are SDK 2.2.x. Most of a member matches
  and a few functions changed: in libvu0 `sceVu0Normalize` is 8 bytes longer;
  in libpad `_send_to_iop`, `scePadPortOpen` and `scePadSetActDirect` differ.
  libkernl (10 members), libgraph (12), libmpeg (7), libcdvd (3), libsdr,
  libmc and libdma are in this state.
- **The 2.96 libc/libm/libgcc.** 34 libm, 18 libc and 9 libgcc members do
  not match as built. The libc here is not quite ICO's: `__malloc_lock` is
  thread-safe (GetThreadId/WaitSema), not newlib's empty stub.
- **crt0.s** differs from ICO's.
- graph022 (`sceGsSetHalfOffset2`, byte-identical to graph021's
  `sceGsSetHalfOffset`) and libkernl `memclr` were dropped: the retail ELF
  has one copy of the HalfOffset code, and `memclr`'s bytes appear at two
  addresses, neither in libkernl.

Done since (2026-11-26): klib.s, libvu0, libmc, eeloadfile, iopheap and
ipuinit. What SDK 2.5 changed in them: every `PsIIlib*` stamp reads `2500`;
libvu0's `sceVu0Normalize` has two `vnop`s before the `vdiv`; libmc calls
`scePrintf` (not `printf`) and adds `sceMcEnd` and `sceMcUdCheckNewCard`;
eeloadfile adds `sceSifStopModule`, `sceSifUnloadModule` and
`sceSifSearchModuleBy{Name,Address}` (RPC 7 to 10); iopheap shares one
argument block and adds `sceSifAllocSysMemory`, `sceSifFreeSysMemory` and the
five `sceSifQuery*` calls. A unit whose functions all match but whose `.text`
does not place usually calls a libc function that symbol_addrs.txt has not
named yet (`memcpy`, `strncpy` were `func_` names); game code calling such a
function by its `func_` name has to be renamed with it.

Also done (2026-11-26, second pass): crt0, glue, kprintf, filestub,
iopreset, intr (split: SDK 2.5 moves Copy/kCopy/GetEntryAddress to
tlbfunc.o and keeps kfiv's InitAlarm in its own member), the new SDK 2.5
libkernl members initsys, osd, exec, alarm, tlbfunc and tlbtrap.s, libdma
(rewritten around static wait helpers), libpad, cdvd000, sceCdReadClock,
graph001/008/012/015/017, nine new libdev VIF0/VU0 members, libmpeg bit.c
and libipu (which owns setD3_CHCR/setD4_CHCR). Recurring SDK 2.5 changes:
`intr = DIntr(); ... if (intr) EIntr();`, `scePrintf` for `printf`, `2500`
stamps. Not linked in this game: graph016/018/023/024/025, sceCdSeek,
sceCdBreak, most of kfiv's libdev. Still open: graph003 (register
allocation in sceGsSetDefDispEnv), libsdr (sceSdRemote's shared call),
libmpeg (SDK 2.5 passes a decoder context to every internal function),
and libc/libm/libgcc, whose soft-double code (no delay-slot fill on dp*
libcalls or a double return move) looks like another ee-gcc 2.96 build.
tools/lib_layout.py now pairs %lo with the %hi whose register it reads.

For each: start from kfiv-decomp's source, update it to the SDK 2.5 / 2.96
behaviour and run `tools/carve.py --check`. Data the tool cannot place
(sections nothing references, or ambiguous byte matches) is listed by
`tools/lib_layout.py build/carve`.

### 2. The compilers (settled)

`tools/probe_compiler.py` compiles `tools/probes/*.c` (game functions written
in C) under every candidate and compares them with the retail bytes:

| compiler | game probes (8) | gcc-module probes (6) |
| --- | ---: | ---: |
| mwccps2 3.0b38, 3.0b50, 3.0b52 `-O4,p` | **8** | |
| mwccps2 3.0 / 3.0.1 / 3.0.3 `-O4,p` | 6 | |
| mwccps2 3.0.1b44 to b75 `-O4,p` | 4 | |
| mwccps2 2.3.3, 2.4 `-O4,p` | 4 | |
| any build at `-O4,s` / `-O3` / `-O2` | ≤ 6 / ≤ 6 / 0 | |
| ee-gcc 2.96 `-O2 -G 8 -fno-strict-aliasing` | | **6** |
| ee-gcc 2.96 `-O2 -G 8` | | 3 |
| ee-gcc 2.9 `-O2 -G 8` | | 1 |

What separates them: 2.x fills a delay slot differently (Enemy_GetModelData_1_0013DCE0);
3.0.1b44 and later schedule loads and stores differently (PlayTime_Resume_1_001DF960);
3.0 to 3.0.3 allocate registers differently (MapCmd_GetObjectVar_0_0017DC70); only `-O4,p`
unrolls TexAnim_Init_0_00175C80's loop that way. The gcc modules reload a global
pointer after every store through it (GsText_SetScaleVec_0_001E2A48), which only
`-fno-strict-aliasing` gives.

b38, b50 and b52 are not told apart. On 46 objects of kfiv-decomp's C, b50
and b52 emit identical code, and b38 differs only on runs of `*p++` stores:
b50/b52 bump the pointer every two stores, b38 folds the run into fixed
offsets. Neither shape is in the game's code. `compile_c.sh` defaults to
b52; `MWCC=mwcps2-3.0b38-030307` switches if a function ever needs it. Small
data uses the default threshold (`-sdatathreshold 8`): 8-byte variables are
gp-relative in retail and in the probes.

CodeWarrior gives every function its own `.text` section, so mwldps2 could
dead-strip unreferenced functions; ld 2.10 places them in object order.

### 3. KFIV code in Shadow Tower Abyss (tools/engine_match.py)

`tools/engine_match.py` ranks sta functions against the KFIV functions
kfiv-decomp (holyland) has in C, on normalised instruction sequences
(operands, prologue/epilogue saves and nops dropped; SDK calls kept by name).
`tools/match.py` then compiles a candidate C file and checks it word by word,
addends included.

How well that works, measured (2026-11-24):

- **Calibration.** holyland's C compiled with sta's CodeWarrior and scored
  against KFIV's own retail code for the same function: median 0.72 / 0.68 /
  0.62 / 0.51 for functions of 6-15 / 16-39 / 40-99 / 100+ tokens. The best
  *other* KFIV function scores 0.60 / 0.52 / 0.42 / 0.31, and the true pair
  beats it in 110 of 139 cases. So the score does tell same source from
  look-alikes, but below ~16 tokens it is mostly shape.
- **Game logic is not shared.** sta's best KFIV matches score 0.51 / 0.40 /
  0.30 / 0.21 at the median, below the look-alike level at every size, and
  no game string is common to both binaries (all 130 shared strings are SDK).
  Top hits among small functions repeat one KFIV function for five or six
  sta functions: generic shape.
- **Some modules are shared.** The memory-card module (holyland
  `src/game/save/mc.c`, KFIV 0x218188-0x21B4xx, linked after the SDK) is sta's
  first ee-gcc module, 0x1D3A90-0x1D7EC0: scores 0.84-1.00 on functions of
  0x120-0x904 bytes, and **13 of its 22 paired functions compile from
  holyland's C unchanged** under ee-gcc 2.96 (Mc_StepWrite, Mc_StepCopyFile,
  Mc_StepRead, Mc_StepCheck, Mc_StepGetDir, Mc_Update, ...); the other nine
  differ in a few lines. Also shared: the VU0 distance/transform routines
  (inline asm in holyland, so they stay asm here), Display_BuildProjection
  (Display_BuildProjection_4_00178870, now in C, one operation changed), and fragments of KFIV's
  VU1 microprograms in sta's game data.

So the method is worth running per subsystem, not per function: a large
function above the calibration median is a real lead; a small one is not.
Next: bring mc.c in as the unit for 0x1D3A90-0x1D7EC0 (its statics and .bss
have to be placed), then look for further shared modules among the high
scorers of 100+ tokens.

### 4. Find the game's translation-unit boundaries, then match

- `__FILE__` strings (`fslibmpg.c` survives) and assert messages.
- Function alignment padding, file-static data used by one run of functions.
- Per function: m2c for a first draft → decomp.me (a "PS2 mwccps2" preset)
  or objdiff → drop into `src/`.

## Data owners

Every data object should be defined by the code unit that uses it. The
matching build needs each data-only unit (`src/game/data/`) whole at its
retail address, so an object moves there for both builds only when
`tools/move_data.py` can place the owner's section where retail has it
(d95e8d6 moved 23; the 28 candidates left either fold into the owner's code
or do not fit its declared type). For the rest the NONMATCHING build gets
the object from its owner instead:

- `tools/data_owners.py --report` (after `./build.sh`, the NONMATCHING
  objects): every object of the data units, its users in the NONMATCHING
  link, and a class.
- `tools/split_data.py --apply`: the owner gets a twin under `#ifdef
  NONMATCHING` (written in the owner's declared type, `static` when nothing
  else names it), the data unit's definition goes under `#ifndef
  NONMATCHING`. The matching build compiles what it did before.
- `tools/check_data_twins.py` (ninja, part of the default target in both
  modes; `build/twins/` holds the other build's side): each twin has the
  data unit's bytes, size and relocations.
- **Pinned** objects stay where the data unit has them in both builds: the
  code can reach past them into their neighbours, so the neighbours must not
  move. That is an object whose address is cast (to an integer or another
  pointer type) and everything after it in its gap-free run, unless
  `config/data_extents.txt` says how far the code reaches from it (read off
  the code); a "view" (smaller than the element its users declare) and its
  run after it the same way; and an object a `%hi/%lo` or gp-relative
  access reaches past the end of.

<!-- data-owners:start -->
| objects (2026-11-28) | bss | data | rodata | sbss | sdata | all |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| NONMATCHING twin in its owner | 300 | 36 | 225 | 312 | 111 | 984 |
| one user, not split yet | 25 | 70 | 14 | 2 | 10 | 121 |
| several users, not split yet | 7 | 4 | 0 | 0 | 2 | 13 |
| pinned | 402 | 54 | 75 | 3 | 0 | 534 |
| used by asm only / by data only / unused | 66 | 16 | 76 | 7 | 1 | 166 |
| total | 800 | 180 | 390 | 324 | 124 | 1818 |
<!-- data-owners:end -->

Next, in order of yield:

1. **Extents of the roots** (`config/data_extents.txt`): 577 objects are
   pinned, most of them after a root whose reach is unknown: an address cast,
   or a "view" (a column of a struct array behind a label smaller than the
   struct, walked with the struct's stride; it reaches every label of the
   array). A view every user declares as one struct or a sized array gets
   its extent from that type; `tools/data_owners.py --json` names the root
   of every other pinned object: read how far the code goes from it and add
   a line. The biggest left: `D_00486990` (UI anim table), `D_00222B20` (the
   pool), `D_001FCF20`, `D_0043F080`, `D_001FB8F0`.
2. **Initialisers the tool cannot write** ("type does not fit"): structs with
   bitfields, unions or anonymous members (`split_data.py`'s layout() takes
   scalars, pointers, arrays and nested typedef'd structs).
3. **No extern**: owners that reach an object only through a macro or a
   cast of another symbol; give them an `extern` first.
4. **Data used only by data or asm**: they go with their user once that is C.
5. **Real moves**: rerun `tools/move_data.py` as units match; an object it
   moves loses both twins. As of now it moves nothing: 15 candidates fold
   into their owner's code, 2 would leave link order, and 13 are 128-bit
   qword unions no C initialiser writes byte for byte (it now also tries
   split_data.py's struct initialisers).
6. **Names**: `config/game_data_names.txt` + `tools/apply_data_names.py`
   (README, "Data names"); the five objects the headers type are named
   (`gMcState`, `gGsText`, `gGsTextStyle`, `gPlayerData`, `gZeroVec`). Name
   more as their owners show what they are; the checker keeps both copies
   of a twin in step.

`tools/split_data.py --apply` also takes back the twin of any object a
later inventory pins (a new root, a new extent), so rerun it after changing
`config/data_extents.txt` or the code: `./build.sh`, `tools/data_owners.py
--json build/data_owners.json`, `tools/split_data.py --apply`, `./build.sh`,
`ninja shift`, `./build.sh --matching`.

## Shiftable build

The goal is that the image can move: a function that grows, a table that
gets longer, an object inserted. The link then still produces a working
program, because every pointer follows what it points at. What makes that
true now:

- **Sections follow each other.** `config/sta.jp.ld.in` fixes only
  `.text`'s load address (0x100000); `.data`, `.sdata`, `.sbss` and `.bss`
  each start 0x80-aligned after the previous one, `_gp` is
  `ADDR(.sdata) + 0x7FF0` and `_fbss` is `ADDR(.sbss)`.
- **No absolute in-image symbols.** `tools/rel_syms.py` (build step,
  `build/rel_syms.ld`) gives ld splat's undefined symbols, `linker_syms.txt`
  and `data_aliases.txt` as `OWNER + offset`. It drops what an object
  defines or nothing uses, and keeps sizes, out-of-image addresses and the
  load address absolute. Biased bases are written by hand in
  `linker_syms.txt` (`D_001FE918 = D_001FE994 - 0x7C`).
- **Data is C.** Pointers in `src/game/data/` are relocated `(s32)SYM`
  initialisers, jump tables of asm functions are function + offset, and
  folded `.bss` fields are aliases of their object. Each data-only unit is
  rigid: its first object carries the unit's largest alignment, so its
  inside does not change with where it lands.
- **Words that only look like pointers** (packed data, ASCII) are numbers:
  `tools/fake_pointers.py` lists them as `ignored_` in
  `config/symbol_addrs.txt`.

`ninja shift` checks it. It links four shifted variants (0x100 and 4 at the
start of `.data`, 0x40 at the start of `.bss`, 0x100 before the game's
first `.text`) and `tools/shift_check.py` checks every data word, `jal`
target and `%hi/%lo` pair that names an image address. Each must name the
moved address; one that stays put is an error if it comes from asm or a
relocated word, and is counted as a constant if it is an unrelocated number
in C source. Run it after changing data or the link. All four variants
report nothing today.

Not covered yet: the asm that is still asm can hold an address written as
a number that the check cannot pair (a computed address, a table walked
with a hand-built base). It shrinks as functions become C, and is the next
thing to check by hand (or by booting a shifted image).

## Build notes and gotchas

- splat's asm is assembled with **SCE ee-as 2.10**, not ee-as 2.9: ee-as 2.9
  inserts nops into R5900 short loops (the first one is at 0x1081F0), which
  CodeWarrior's assembler never did, and it has no option to stop. ee-as
  2.10 leaves `.set noreorder` code alone.
- splat writes its own linker script; it goes to `build/splat.ld` and is
  unused. `gen_ninja.py` expands `config/sta.jp.ld.in` into `build/sta.ld`
  (ld 2.10 has no `INCLUDE` inside an output section).
- ld 2.10 rejects an empty implicit linker script, so `split.py` writes a
  comment into an empty `config/undefined_*_auto.txt`.
- The checkout path must not contain spaces (binutils' autoconf trees and
  `LD_PRELOAD` in `tools/period_env.sh` both break on them).
- The ROM view is the one non-empty PT_LOAD; the retail ELF has a second,
  empty PT_LOAD at the end of `.bss`.
- `tools/split.py` writes `addiu $r, $28, 0` for `%gp_rel(_gp)` (CodeWarrior
  copies `$gp` into a new thread's setup); `la $r, _gp` would be two
  instructions.
- Asm can refer to an address inside a C unit's section that the C object
  gives no symbol (mprec's `_pow5mult` forms `p05 - 4`, the last word of
  mktime.o's .rodata). splat assumes the C object defines it; such addresses
  are defined in `config/linker_syms.txt`.
- `tools/carve.py` leaves a library static unnamed when asm code or data
  outside the placed units points into it (`_DAYS_BEFORE_MONTH` is read by
  asm after mktime.o): asm cannot link to a static.
- The libc r5900 string routines are `.align 3` here (KFIV's are word-aligned):
  memchr sits 8-aligned right after mbtowc_r.o's 0x34 bytes.
