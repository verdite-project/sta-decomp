# Matching notes

From KiskarFisk's [shadow-tower-abyss](https://github.com/KiskarFisk/shadow-tower-abyss), merged
with its history. The `tools/` named here are in that repository, not this one.


Code-shape tricks that made MWCC 3.0b52 (`-O4,p`) reproduce the original, collected while matching.
Function names point at examples in `src/`.

## General

- **First, look for a matched sibling.** grep `src/` for the same callees / GS register numbers / globals; many functions are near-copies (rotate-around-centre family 00184040/00184DF0/00185510/00186440, GS setup in 00156CE0, Node helpers in 001AC4A0/001AF150). Copying and adjusting offsets/constants matched first try 5 times in one round.
- Saved regs assigned in declaration order from the top (first local -> highest s-reg); declaration order also sets temp regs. Try permutations of local order first.
- Stack locals laid out in reverse declaration order (last declared = lowest address). Buffer sizes set frame size (`addiu sp,-N`).
- `T x = {0};` gives the compiler's clear loop (no pad nop); hand loops get padded. Can go inside a case block.
- -O4,p pads branch targets with nop; a ternary instead of if/else avoids the pad (`h = c ? &A : &B;`, `return c ? x : z;`).
- u128 unions + struct assignment for lq/sq copies; `__attribute__((aligned(16)))` on vars (extern and local) for lq/ld copies.
- volatile (read once into a local) for reloads after stores.
- Bitfield typedefs for bit set/test (`|= 8` -> `.b3 = 1`); include/actor.h has Flags8 and the Actor struct.
- `x > N-1` / `v <= 311` style to get slti $at; `!f() == 0` for sltu/xori.
- for-loops may unroll; do-while over pointers avoids it. Plain `for(i=0;i<n;i++)` gives slt+beqz entry.
- Return the value to keep it in v0. u8 return type/var gives `daddiu v0,zero,1`.
- Index struct byte arrays (`a0->arr[i & 0xFF]`) to fix addu operand order.
- Typed struct instead of M2C_FIELD stops address-reuse CSE; `(s32)p + off` stops offset folding.
- One-case `switch` produces branch-into-body-then-jump shape. Switch cases tested in reverse source order.
- `static inline` helpers reproduce inlined lookup patterns (see src/ siblings 001B16E0, 0017E940).
- s32 locals passed to s16 params get re-sign-extended; explicit (s16) casts cost a saved reg.
- Last-resort scheduling barrier: a no-op `if (q && q) {}` (permuter-found), comment it.
- Permuter: `tools/perm_setup.py`; put the directory with the `cpp` shim (see README) first on PATH.

## More specific

- Float branch to a later "true" block (bc1t L; li r,2 in delay; ... L: li r,1): write `if (!(x < K)) return 2; return 1;` — ternaries and if/return-1-first give bc1f.
- `n = (n <= 0) ? 1 : n;` / `n = (n < 5) ? 5 : n;` reproduce s16 clamp via int temp (dsll/dsra re-truncate) with the right branch sense; plain if gives direct li to the s-reg.
- Bitfield value of an assignment is reused: `o->f88 = o->b1 = 0;` gives the dsll/dsrl extract + unsigned->float conversion of the stored byte.
- Order of pointer computations from the same base (t, e, s) decides temp registers; try permuting statement order before locals.
- Re-using an existing local (e.g. `b = idx;` then `b & 0xFFFF`) can shift register allocation in the right direction (permuter-found).
- Unrolled loops that come out in reverse index order: index with `[7 - i]` in an ascending for-loop (Status_DrawStats_0_0019E090).
- A condition var read into a local BEFORE an earlier struct copy (`on = p->x8; t = D; if (on)`) gets the load hoisted into the copy sequence (OptionProc_DrawKeyAssign_1_001907D0).
- Accessing a global array directly by index (`D[idx] = i + 1`) instead of through a `u16 *cur = &D[idx]` pointer changed which temps got a2/a3 (Light_Add_0_0015B980).
- `0 > x` gives `slt at,x,zero`; `x < 0` gives bltz and `x <= -1` gives `slti at,x,0`.
- Float add operand order ignores source order; put the product in a temp first (`t = a*b; r = t + c;`) to get `add.s d,t,c`.
- A 4-byte colour copied with lwc1/swc1 needs a 4-aligned type: `union { u32 w; struct { u8 r,g,b,a; } c; }` (a plain u8 struct copies bytewise and shifts register allocation).
- To hoist byte loads above byte stores that may alias, read the fields into u8 locals first (declaration order = load order); s32 locals get folded back into the uses.
- A `b` to the very next instruction (delay slot filled) right before a join = early `return` inside an inlined static helper; a helper that also loads its own base pointer can fix register swaps.
- MWCC evaluates call arguments/operands right-to-left in one expression: `R2() + x * (R1() - 0.5f)` calls R1 first; splitting into statements changes float add operand order.
- Self-recursive function with 2-3 levels of call bodies duplicated inline = hand-written `static inline` copies (g2 -> g1 -> f); `inline` on the function itself doesn't do it.
- Statement order of independent global stores decides scheduling; brute-force permutations (5 stmts = 120 builds) are cheap.
- `x > 0xFF` (not `>= 0x100`) gives slti $at+bnez for early-return range checks; `*++s` keeps separate addiu+lhu 0 instead of folded offsets.
- Constants with bit31 set built as `ori; dsll 16; ori` (zero-extended) mean the parameter is 64-bit (u64/s64), not u32.
- Each loop with its own s-reg assignment wants its own counter/pointer variables (declared in the order of the regs, highest first); reusing one set across loops shares regs.
- Shared-struct globals: splat names each field address (gOptionBss_004A1058...), but one struct extern at the base matches too; table accesses folded as `lbu 0x18(base+idx*4)` reveal the base.
- A bitfield's assigned value is reused without reloading when written as an expression: `o->x = (f32)(u32)(o->b1 = 0);` (separate statements reload the byte).
- When all s-regs are used, params spill to the stack at entry: a u8 param spills with sb, an int with sw; the callee's prototype param types (u8) decide lbu reloads at the call instead of hoisted andi.
- if/else assigning two constants to a local union becomes movz (select); storing via `*(u32 *)&col = K;` in each branch keeps the branches and separate sw.
- `if (cond && !inl(x) != 0)` keeps an inline bool materialized (xori/sltiu/xori + beqz) instead of folded into branches. Brute-forcing the declaration order of 5 locals (120 files, about 3 min) cut one diff from 87 lines to 35.
- u16->float showing the unsigned-convert pattern (bltz/srl/or/cvt/add.s): `static inline f32 u2f(u32 x) { return x; }`; the inline also stops MWCC sinking a nearby if/else past it.
- Keep an "empty" then-block (bc1f else; b join) with a self-assign: `if (a < b) { b = b; } else { b = a; }`.
- Commutative operand order stuck (mult/addu)? Update in place: `n *= 2; sz = n * esz;` instead of `sz = n * 2 * esz;`; fold offsets into the index: `p->tbl[k + 0x20]` instead of `*(s32 *)((s8 *)&p->tbl[k] + 0x80)`.
- Arg setup order (where mov.s f12 lands) depends on where the f32 params sit in the callee prototype; try moving them earlier, e.g. (s8 *, f32, u32, f32).
- 64-bit dsll + final dsll32/dsra32 on a GS PRIM value = PS2 SDK GS_SET_PRIM-style macro with (u64) casts on every field: `(u64)6 | ((u64)b0 << 3) | ... | ((u64)1 << 8)`.
- Extra `b epilogue` + pad nop at the very end of an else path = an explicit `return;` there (padded epilogue label).
- u16 global passed to several s16 params: hold it in an `s32` local; a `u16` local lets MWCC CSE the sign-extension into a saved reg (extra s-reg, bigger frame).
- `s16 += (s32)(float expr)` adds a redundant sext of the converted value; `+= (s16)(float expr)` matches.
- Operand order of `call() + x*y`: store the call result in an s16 temp first (`r = f(); if (r + x*y > 99)`).
- Globals addressed as one base + offsets (base symbol D_X used with large offsets) = one struct extern at D_X containing the arrays.
- Direct lq from a stack union (lq x,0x60(sp)) comes from copying the u128 member (p[i].q = q.q); whole-union assignment (p[i] = q) materializes &q in a register first.
- Chained float 'first nonzero difference' compares: an inline helper with early returns and a final ternary (return d != 0 ? d : 0.0f) gives the bc1t/b chain with mov.s from the zero reg.
- Consecutive loops: reusing one counter variable vs separate i/j changes saved-register assignment; try both along with declaration order.
- Conditional pointer bumps (`if (bit) p += N;`) get a pad nop on the skipped target; `p = bit ? p + N : p;` doesn't.
- Float args: putting the f32 first in the callee prototype moves its mov.s earlier (into the preceding branch delay slot); trailing f32 stays next to the jal.
- Values passed to u8/u16 params from int locals get andi masks; load them into s32 locals (not u8) to reproduce `lbu` + `andi 0xFF`.
- A for-loop walking `(&a0->arr)[i]` from the object base becomes an IV on a0 itself: write `((T **)a0)[i + OFF/4]` to get `lw X, OFF(s1)` with s1 = a0 + 4i.
- `if (a0 != 0 && ...) { body }` (single return path) avoids the bnez/b early-exit shape that `if (...) return;` gives.
- Unrolled xyz stores: `for (k = 0; k < 3; k++) { pos[k] = (&e->x)[k]; ... }` unrolls with direct sp offsets; written out by hand, MWCC routes non-zero stack offsets through an address register (Map_SpawnSfx_0_001B5CA0).
- Shared angle-wrap `(ang + π)`: repeat the expression inline (macro-style) instead of a temp; the temp flips `add.s` operand order. Likewise `u = 200.0f; lo = p - u; hi = p + u;` fixes operand order.
- Float-arg prototype position also moves float-constant `lui` loads: if a `lui` (e.g. 1.0f) lands before/after the wrong instruction, try the f32 param first, middle, or last (MenuProc_Set_1_0018B150 takes it last).
- `if ((u8)(x == 0))` gives the `xor`/`sltiu` + `beqz` shape.
- A second `= {0}` clear in its own nested block (`{ Vec E = {0}; ... }`) gets its own stack slot; an unexplained stack gap often means an array local (`Vec C[2]`).
- `*(s32 *)w = 0; *w = 0.0f;` lets MWCC drop a store; assign `0.0f` twice to keep both.
- `do`-while loops with an explicit `if (i < n)` guard; duplicated loops only match with block-scoped locals per copy.
- One-case `switch` on a magic number gives the beq / `b end` shape.
- Table entries stored as unions: whole-union assignment (`D[x][0] = t;`) vs member copy (`t.q`) differ; try both.

Near-miss round (CodeWarrior unless marked gcc):
- **Hidden extra call argument**: an unexplained param copy at entry, or an a3/t0 set up but never used, is an extra argument of the next call. Copy the matched callee's exact prototype from src/game first; fake extra args share constant regs.
- **Float arg loaded before an int stack arg** (`lwc1 f12` before `lw a2`): read the float through `((volatile T *)p)->f` at that call. Swapped float temp regs in `const * field`: read the field via `*(volatile f32 *)&o->f`.
- **Stuck `addu` operand order** on `ptr + idx*size`: `(T *)((u8 *)(idx * sizeof(T)) + (s32)ptr)`; or a local pointer of a padded struct type with an element array (`tb->e[i].f`); or `&((T (*)[sizeof(E)/sizeof(T)])&tbl->field)[i][0]`; or put `byte*20` in its own temp. `(T *)((s32)q + 0x40 + n * 16)` keeps `q+0x40` in its own reg.
- **Param stored to its home and reloaded, plus a 16-aligned temp for `*arg`**: move the body into an inline taking `&param` and `*arg`.
- **Args set up in the wrong order**: change a pointer param in the callee prototype to s32 and cast the args. An f32-params-first prototype reorders only some call sites; try it anyway.
- **All regs shifted by one**: reorder independent pointer setups at the top. Two loops with counter/cursor swapped: walk the second with a dead variable and a fresh counter.
- **Inner `if (X) c = 1;` turning into `sltu`**: add `else { c = c; }`. Subtraction in a `bc1f` delay slot: make it the first statement of the then-block.
- **Bitfield tested unmasked, `andi 0xFF` inside the if**: s32 temp, test it, assign to the u8 inside. u8 call result masked too early: fresh `s32 jj = j;` right before first use.
- **u16 `x += f(x) * k` with a reload before `addu`**: `x += (u16)(expr)`.
- **Pointer bump** `p = (G += K) - K;` orders temps differently from `p = G; G = p + K;`. Loop-hoisted loads scheduled oddly: the stored global may be a field of the same struct as the loaded ones; fold them into one struct.
- **Constant-store blocks / inline load order**: brute-force statement order with perm.py.
- gcc: a hand-unrolled first iteration of a binary search is gcc loop copying; write a plain `for (;;)`. Float temps from a returned struct follow the later store order, not load order.
- Library functions must be called by their real name (`memset`, `fabsf`), not `func_<addr>`, or carve/splat hit a duplicate symbol.
- Generate variants with python `str.replace`, not sed/bash substitution (`*(volatile` in BRE and `&` in `${s/pat/rep}` silently corrupt the C).
- **A masked value in an odd arg reg (a2/a3) that nothing uses** is an extra argument of a later call; some callees are called with more args than their definition takes.
- **Field shared (CSE'd) with another address**: pass it twice as separate args to an inline (`upd5(&b[k], t->x20, t->x20)`).
- **Param spill into a 16-aligned temp slot**: an inline with a `**` out-param plus a fresh local copy of the pointer.
- **Two pointers to the same address, temp in the wrong reg**: read the field through the other pointer.
- **Unsigned compare that should be `sltu $at` + `bnez`**: `if (y <= x)`, not `x >= y`; a v0/v1 swap that won't move can be the signedness of the extern the value is loaded from.
- **Counter cleared in a loop guard's `beqz` delay slot**: set the counter before `if (j < n)`, the other loop variable inside it, then `do {} while`.
- Grep `asm/matchings/game` for the exact instruction pair you need, then read that function's C.
- gcc: a struct built from a returned struct's fields with floats out of order: compound literal `r = (R){ t.x, t.y, t.w, t.h };`. A v0/v1 swap right after a call whose result is unused: declare the callee `void`.
- Name every library function by its symbol_addrs.txt name, including the sceVu0* helpers (func_001029D0 = sceVu0AddVector, ...): an address name in a game unit makes carve.py write a duplicate name that breaks the next carve run (sce units go unplaced).
- **Length differs from retail**: score perm variants by difflib alignment on opcodes; chk's positional count stays flat.
- **Loop guard jumping to a setup block placed after the loop**: write it with gotos (`if (c) goto setup; return; loop: do {...} while (...); return; setup: init; goto loop;`).
- **const x const folded where retail multiplies at runtime**: a redundant `(f32)` cast stops the folding (`2.0f * (f32)r`).
- **Index register set only after a call**: `e = &f()[id = u];`.
- **16-aligned param home slots**: declare the param as `typedef f32 FV[4] __attribute__((aligned(16)))`.
- **Twin functions**: grep for a matched function with the same shape that differs only in its callee and copy it.
- b38 also fixes an 8x-unrolled `*p++` copy loop that b52 bumps every 2 copies.

## Floats, sqrt, switches, inline asm

- `c1 0x...4` / `c1 0x...84` in the disassembly is a misdecoded `sqrt.s`. Declare `f32 sqrtf(f32);` (no math.h) and call it: it inlines to `sqrt.s` (with `mula.s/madd.s` when fed `x*x + z*z`). The result is dropped if unused, but a call feeding it stays (dot-product calls with no visible use, Combat_CalcHitAngle_0_00133D00). Fx_RandomInSphere_0_00163A10 matches when `sqrtf` takes the squared length saved by the rejection-sampling loop.
- Double math goes through the game's own helpers; plain `double` makes MWCC call `fptodp`/`dpadd`, which don't exist. Call `func_0011F8C0` (f32->double), `func_0011DB78` (pow), `func_0011FCF8` (add), `func_00120478` (double->f32) explicitly. Nested helper calls in one expression are evaluated left to right; use a temp to force the order.
- Float temp/constant order: pre-subtract into locals (`ox = fx - 735.0f; oz = fz - 129.0f; d = sqrtf(ox*ox + oz*oz);`) after loading fields into locals; or move the math into an inline helper with its own locals (Menu_DrawRingA_0_00184040, Menu_DrawRingD_0_00185510). `aa = a*a; ... while (d > aa + 0.01f)` beat ~90 permutations (ScreenFx_DrawDistort_0_00156CE0).
- `d = call(); d += k; if (d < 0.0f) return 0.0f;` keeps the operand order and returns the zero reg; folded `d = call() + k` flips both (Light_CalcIntensity_0_0015B720). `r = s / sqrtf(...)` (own local) puts `div.s` in a fresh reg.
- Float abs/clamp with no pad nop: ternary (`y = y < 0.0f ? -y : y;`); an `if` adds the pad. float->u16 with `andi 0xFFFF`: `q = (z < 30000.0f) ? (u16)(u32)z : 30000;`.
- Constants a target keeps in registers after storing them to a local struct: use the literal again in later math instead of reading the struct back (DbChar_DrawRing_0_00196070). `3.141592f` = 0x40490FD8, `3.1415925f` = 0x40490FDA.
- Two float variables sharing one register in the target: reuse one variable (`dy = ang + f;`).
- Switch jump tables (`jtbl_` in the asm): `batch.py` links the table and compares it. A table spanning 0..N-1 needs every missing case written as an empty `case X: break;`, or MWCC emits a compare chain (Player_SpawnStepSfx_0_001BE510). Fallthrough state machines need an explicit `case N:` label for every state (SndBank_LoadStep_1_0012ED60).
- Inline asm works: GCC-style `asm("..." : outs : ins)` and MW-style `asm { sync; L: nop; bc0f L; nop }` (labels are function-scoped, unique per site). VU0 `lqc2/vmul/sqc2` in a `static inline` must be non-volatile with no `"memory"` clobber, or scheduling and saved regs change (Map_RaycastSegment_0_00145A80).
- Fields loaded in strict source order against normal scheduling = a `volatile` struct pointer parameter (MapCmd_FadeLight_0_0017C6F0). u8 params reloaded from their home slot (`lbu` from sp): `*(volatile u8 *)&param`.
- Linear search with lazily reloaded key and a `bne` + `b found` shape = `static inline` helper taking `(s32 *it, K *k)`; declare the iterator in the caller (MapCmd_FadeLight_0_0017C6F0).
- 4-byte stack struct copied with `lw/sw`: copy the union's `u32` member; whole-union copy gives `lwc1/swc1`. 12-byte `ld`+`lwc1` copy: 8-aligned struct, whole-struct assignment (Game_InitSaveIcon_1_00128D10). Whole-struct copy from a global materializes both addresses (`lq 0(a1)/sq 0(a0)`); member copy folds the address.
- Float globals that overflow small data at link ("small-data section too large"): `extern f32 D_X[];` and use `D_X[0]`.
- Callee-saved reg used where a temp is expected: the value may be a compiler temp from right-to-left evaluation of one big expression; writing it with an explicit local gives a t-reg instead.
- A callee whose `a3` is never set before the call has a 3-arg prototype; a 4th param makes MWCC hoist a bogus `move a3`.
- `goto cond; body: ...; cond: if (x > K) goto body;` gives the `b cond` loop entry with constants hoisted ahead; `do { f(o); j++; } while (j < (o = **q)->n);` reuses the loop-bottom load as the next call arg.
- `return a || b;` with `a` read into a local earlier gives `sltu/bnez/sltu` without padding; pointer select without padding: `p = &h[0]; if (c) p = &h[1];`.
- Long runs of independent bitfield writes: random-search the statement order (keep each byte's writes in sequence), then local swaps from the best; 1500 orders took ~2 min (Game_Boot_2_0012BC80).
- Checker gotcha: the function name is taken from the first `func_X(` line without `;`, so a `#define` calling `func_X()` confuses it; write `(func_X)()`.

- Unrolled `mula.s/madd.s` runs at constant offsets: write each statement out (`d[i] = p[i]*u + q[i]*t`); a for-loop isn't unrolled (MapCmd_SpawnSfxOnObject_0_0017BD70). `neg.s`+`add.s` = literal `(-j + k)`; `k - j` gives `sub.s` (Mtx_BuildProjection_2_001294A0).
- Float products: name each product temp (`xy = x*y`) and write `t * xy` inline; temps already containing `t` don't match. Declare the product temps before x/y/z (Mtx_AxisAngle_2_0015EBB0).
- gp-relative globals: declare with a size (`extern u8 D_X[4];`) or as a scalar indexed via `((T *)&D_X)[i]`; `extern T D_X[];` gives lui/absolute addressing. Many globals near one base that overflow small data: one big struct extern (ScreenFx_Init_1_00159A60).
- `andi rN,zero,1` + shifted copies for several bitfield stores = separate `bf = 0;` statements (or one `z = 0` local), not a chained assignment (ItemObj_SpawnThrown_0_001AEC00, Frame_RenderLoading_0_0012B600).
- `daddiu v0,zero,K` returns without a u8 variable: body in `static inline u8 inner()`, real function `return inner(...);` (Enemy_FindWaypointDir_0_001432F0).
- Stack-struct stores scheduled around float math: interleave the constant stores between the float->int stores in source (Frame_RenderLoading_0_0012B600). Bitfield runs that need a saved reg: try natural per-element order before random search (ScreenFx_Init_1_00159A60).
- `dsll` for a shift feeding an s64 param needs `(u64)` on the operand; `(a.b5 ? 2 : 0) | (a.b6 ? 1 : 0)` gives sltu+or (Mdl_SetBlendMode_1_0016F280).

- `addi` (not `addiu`) marked "handwritten instruction" at a switch range check: `static inline s32 cls(s32 x) { s32 t; asm("addi %0, %1, -7" : "=r"(t) : "r"(x)); switch ((u32)t) {...} }` (Player_UpdateEquipModel_0_001CE7D0; same `addi` in Inventory_HasItem_0_001CBC20, Player_ApplyEquipVisualB_0_001CE4B0, ItemType_IsWeapon_0_001D1D50).
- Compare result kept in v0 (`slti v0` + `bnez v0`): `if (!(x < K)) return NULL;` instead of `x > K-1` (ItemObj_SpawnFromMap_0_001AEE80). Branch with the failure store in the delay slot: write the failure case first, `if (x <= 0) { fail } else { ok }` (MapCmd_WaitEvent_0_0017C2A0).
- Early null-check returns followed by an `andi 0xFF` later = an `s32` param copied into a `u8` local after the checks (MapColl_RayVsObjects_0_001B2180). u8 param masked again at each use: plain param in the first use, `(u8)p` cast in later ones (Combat_UpdateAttack_0_00139330).
- `sd` of -1 built with `pcpyld` = `u64` field. Pointer sum stuck on `addu` order: integer sum with `* 16` instead of `<< 4` (MapColl_RayCastAll_0_001B2F30). Byte pair to u16: inline `u16 mk(u16 lo, u16 hi) { return (u8)lo | ((u8)hi << 8); }` (EnemyScr_Event2024GetMove_1_001409A0).
- Float accumulator that should end in f0: `sum *= g; return sum;`, not `return sum * g;` (Noise_Fbm_1_0015F040). u16 arg `base + expr` in the wrong temp: `base += expr; f(base);` (Player_StartSwitchMotion_1_001C6D40).
- Saved regs can follow statement order rather than declaration order: move the statement that first computes the value (Combat_UpdateAttack_0_00139330).

- Jump table contents (cases that share code): read the table from the exe, file offset = vaddr - 0xFFF80 (`xxd -s $((0x1FDB60-0xFFF80)) -l 32 -e SLPS_252.17`).
- Static inlines nest only one level; an inline called from an inline is emitted out of line (FxProc_PullTowardEnemy_0_0014BA10).
- Stack layout: aggregates of <= 8 bytes and scalars always go at the top of the frame; an aggregate at the bottom is > 8 bytes (Coll_SweepSegmentsInit_1_00151E50).
- `c ? 1 : 0` always becomes sltu; `li 1; movz` only appears for other constants. `daddiu r,zero,K` for a constant = assignment to a `u16` variable; s32/u32 give `li`.
- Call result in a u8 compare without an `andi` after the jal: s32 callee/inline, cast at the compare `(u8)f() != 3` (Map_StreamStart_0_001B0450).
- A param store before a `= {0}` clear: thin wrapper doing the store, then a `static inline` holding the body (C89 has no mixed declarations).
- `0 < x` gives `slt at,zero,x` + `beqz`; `x > 0` gives `blez` (Attack_HandleSfxEvent_1_001D3810). `(base - K)[idx]` instead of `base[idx - K]` fixes addu order (Enemy_AttachEffect_1_0013C0D0).
- Max of two floats with `bc1t`: `if (!(a <= b)) x = a; else x = b;` (Coll_SweepCapsules_0_00151900). FOURCC from bytes: `D[0] | D[1]<<8 | D[2]<<16 | D[3]<<24` with `extern s8 D[]`.
- WRAP-style macros repeat their argument: put a call result in a temp first (Hud_AddMarker_0_001BC320).
- Copy float params into locals declared in the target's register order to fix float regalloc (Proj_FindBestTarget_0_001472A0).

- Stack slots overlapping a live matrix: the original passed its rows (`(Vec *)m.m[2]`); separate locals never share space (Camera_Update_1_001C8F90). A static inline used twice gets one stack local per copy; pass a caller-declared scratch pointer to share it (Player_CheckLadder_0_001BE050).
- Unexplained 16-byte gap next to a Vec: `Vec c[2]`. Pointer out-params in 16-byte slots: `T *p[4]` (top of frame) or a struct typedef with `aligned(16)` (bottom of frame).
- Two locals holding copies of one value with swapped saved regs: make one `u32`, the other `s32` (Option_ScreenSetting_1_0018EDA0). When all s-regs are used, declaration order decides which local spills (Script_OpCompare_1_00165DF0).
- Global reloaded after a store through a pointer: `*(volatile T *)&D_X` at that one use (TitleMenu_Select_1_001A40A0). Element pointer whose fields reload: `volatile B *b` (Sfx_DrawAll_1_00168A40).
- u32->float of a call result that must come first: wrap call+conversion in a `static inline f32` (a temp gets copy-propagated) (Player_OnHitEnemy_0_001C73C0).
- `u8 = (s32)(float expr)` gives cvt.w + sb; a plain assignment adds the unsigned 0x4F000000 path (Menu_LerpLayout_0_0018C140).

## Game headers

`include/game/<subsystem>.h` holds what `src/game/<subsystem>/` owns: hand-written
types at the top, then a block `tools/headers.py` generates from the units' own
declarations (extern objects and prototypes every unit spells the same way, or
that merge_tu.py's `unify` reconciles for a function with no C definition yet).
`tools/headers.py report` writes build/headers_report.txt (agree / unify /
conflict / local-type / single); `tools/headers.py hoist` moves the hoistable
ones and keeps a unit's change only if its object stays byte-identical, so rerun
it after matching new code. A declaration that is a matching knob (a prototype
that differs per caller) shows up as a conflict and stays local.

A struct spelled the same in several units goes into a header once; the unit
keeps its local name as `typedef Canon Local;` (e.g. `ResNode`, `Bits8`, `UiArg`).

## Struct candidates

Globals accessed at many offsets across unmatched code, worth a shared header in `include/` (like `actor.h`):

- Done: `gPlayerData_00201DC0` is `PlayerData *` (include/game/save.h); `gMcState_004B63B8` is `McState`, `gGsText_00201E5C` `GsTextState *`, `gGsTextStyle_00201E60` `GsTextStyle *` (include/game/ee.h); `gZeroVec_003139A0` is `Vec`. Units still on their own view: `tools/struct_views.py show GLOBAL`; move them with `tools/struct_views.py migrate GLOBAL TYPE`.
- Done: `gItemObjectSpawnBss_004AC630`, `gItemObjectBss_004AC970`, `gItemObjectBss_004AE370` (0xD0-byte objects) are `Obj3D` in `include/obj3d.h`. Several matched files still carry local partial copies; migrate them when touched.
- `gSoundBankLoadBss_0022CBC0`: 63 elements of 0x80 bytes.
- `gSfxSystemBss_003407E0`: elements of 0xED0 bytes.
- `gSoundBankLoadBss_0022F080`: struct `{ off, state, n, left, buf }` (SndBank_IopTransferB_0_0012F0F0 near-miss).
- `Actor->unk518`: sub-object; +0x180, +0x190 used.

## Compiler builds

3.0.1b44, b51 and b74 don't pad `bc1t` targets the way 3.0b52 does, but 3.0.1b44 fails 27 of 51 sampled
matched files, so they are not the game's compiler. Padding differences are fixed in the source instead
(ternaries, `= {0}`).

### More tricks (round W, 0x360-0x420 functions)

- **Reuse one loop counter** across consecutive loops before brute-forcing declaration order; it fixed IV/counter s-reg swaps several times. (The opposite, a separate counter per pointer chain, fixed an a2/a3 swap once, so try both.)
- **Spill slots follow declaration order**: the first-declared local spills highest; compiler temps (hoisted addresses) come after all locals.
- **Loop whose saved regs are reversed**: reverse the declaration order of that loop's own variables.
- **Param copies after the loop guard**: `if (i < n) { o = a2; ...; do {...} while (i < n); }`.
- **Chained assignment `a = b = K` stores right to left**; reverse it to flip the store order.
- **Callee args hidden in `li`/`move` right before a jal** (or a0 left over from a delay-slot `addiu a0,sp,X`) are real arguments; check before every call.
- **`*(u32 *)&reg |= bit`** gives lw/ori/sw; a u64 bitfield gives lbu/sb.
- **A small param `sw`'d at entry but read with `lbu` + bit extracts** is a 4-byte struct passed by value.
- **`&Vec` kept in a saved register across calls** (`addiu s0,sp,X` reused): it's `Vec S[2]` and `&S[1]`. Two struct locals that cost an extra s-reg/frame: try `Obj m[2]`.
- **Multiply/add operand order ignores source order**; put a sub-expression in a named temp (`y = ry + rz; y * dt`) or use an inline `mu(u32 x, f32 k) { f32 f = x; return f * k; }`.
- **Float clamp** with zero branch later: `d > b ? d - b : 0.0f`. **Unsigned clamp without pad nop**: inline `umin(a,b) { return a > b ? b : a; }`.
- **`!(x != 0)`** gives `sltu`+`xori`; `x == 0` gives `xor`/`sltiu`. **u8 flag `andi; bnez`** needs `if (done == 0)`, not `if (!done)`. Bare `a ? ... : 0.0f` and `a != 0.0f` give different `c.eq.s` operand order.
- **strcat via memcpy**: compute `n = strlen(s);` first; args evaluate left to right.
- **Struct-array indexing stops address-sum CSE** (`m[idx].x130`); `off + m` vs `m + off` does not. `(Mtx *)((s32)na + off + 0x100)` also stops reuse of `na + off`.
- **Array/global used as `s32` pins its address in an s-reg**; declaring the callee param as a pointer gets `lui/addiu` at each use.
- **Force a reload without volatile**: read through a pointer local (`s32 *z = &D[k]; (f32)*z` twice). Angle-wrap that reloads x: use a different lvalue (or `*(volatile f32 *)&x`) inside the `< 0` ternary.
- **`rsqrt.s`**: inline asm helper `rsqrt.s %0, %1, %2`. 0x3EFAE147 is 0.48999998f (0.7f*0.7f).
- **12/20-byte local initialised from rodata (`ld`/`lq` + `lwc1`)**: struct copy from an extern with `aligned(8/16)` after the typedef name; a literal initializer goes to .data, which batch.py discards.
- **FOURCC built from `&D[1..3]` in s-regs with `D[0]` via `lui; lb`** means a string literal; batch.py can't link literals (see wip/ItemObj_BindCaps_1_001ADD30.c).
- **Relocation against a symbol at address 0** not in the ELF: `(u32)(D_4A0 - 0x4A0)` gives the same bytes (Gfx_UploadVu1Program_0_00155460).
- **`if (flag) {...}` whose `beqz` lands on `b end`**: write `if (!flag) return;`.
- **Brute-force permutations** of declaration lines or statement groups (`perm.py` in the agent kit): 720 variants take ~1-3 minutes and fixed several functions.

### More tricks (round X, 0x4A0-0x5D0 functions)

- **A call that reuses a0/t0 or other temps across a jal** means the callee is a `static` function defined earlier in the same file (MWCC tracks the registers it preserves). batch.py can't check that layout yet (wip/Enemy_UpdateMotion_1_0013CBC0.c, Lz_DecompressB_1_001797E0.c).
- **Non-static functions defined earlier in the same file are auto-inlined at -O4**; code that looks like a known function's body is a static inline copy.
- **Trailing `move v0,zero` plus v0/v1 swaps mid-function**: the function returns `s32 0`, not void.
- **Unexplained s-reg swap around `&local.field`**: add an explicit pointer local for it. Gp-relative `&D_X` in an s-reg: `extern T *D_X[2];` and index past the end.
- **Stuck `addu` operand order on `base + idx*K`**: repeat the expression that computes `base` inside the index expression, or load the table value into an `s32` temp first (`t = D.v[i]; x += t;`).
- **Switch case blocks follow source case order**; reorder cases to match the target layout. `switch ((s32)u16field)` swaps value/constant registers.
- **Block layout first**: when diffs start with delay slots/nops, try gotos so an else-path's setup sits after the return (File_Read_2_0015A470).
- **Shared final `return 0;`** gives `beq ... ret0`; inline `return 0` gives `b end; move v0,zero`.
- **Self-recursive function with arg setup out of order**: permute where the f32 params sit in its own signature.
- **`while (!(x <= k))` materialises a bool**; `while (x > k)` gives the clean c.le.s loop. Float loop guard: `if (x < 0) do {...} while (x < 0);`.
- **Globals at lui addresses reloaded after an indexed array store** are one struct containing the array. A large constant via `lui; ori; addu` is pointer arithmetic (`(u128 *)p + 0x1982`).
- **Unrolled 8x fill loop**: hoist the count into a local. Stack slot order wrong between two aggregates: pad one (`f32[3]` to `f32[4]`) before reordering.
- **A u32 4th param read as `andi 0xFFFF` / `srl 16`** is split into two s16 halves; a struct param spills to the stack instead.
- **An unexplained nop before a loop head** can be alignment padding; it goes away when the code before it has the right length.
- **Statement-order permutation** (perm.py) fixes scheduling diffs that declaration order doesn't.

### More tricks (rounds Y/Z: big functions and m2c leftovers)

- **Start small functions from the m2c draft** (`tools/m2cgen.py`): agents matched 90% of 0x100-0x140 functions this way.
- **FOURCC tags without a string literal**: `extern const s8 D_X[];` with `D_X[0] | ((const s8 *)D_X)[1] << 8 | ...`, or pointer locals `s8 *c1 = &D_X[1];` etc. Both reproduce the hoisted `&D[1..3]` s-regs. Worth retrying the literal near-misses in wip/.
- **Float saved regs are coloured in reverse declaration order**: declare float locals in the target's f-reg order.
- **Param still live in a0** (switch value loaded into a1, or a jal with no a0 setup): the callee takes the param. Likewise a float loaded into f12 before a compare is the next call's float argument.
- **4-byte union `sw` before a call and `lw` before a later one**: pass it by value in the callee prototype.
- **`x * 1.0f` / `x - 0.0f` kept in the target**: pass the constant through a local or an inline param; literals get folded.
- **Two identical calls in if/else get merged**: make one argument opaque (`on - on`).
- **Multi-table switch functions**: MWCC emits one .rodata per switch in code order; some originals have them reversed (wip/Shop_Update_0_001A1C80.c, code bytes match).
- **Static callee earlier in the same file** (temps kept live across the jal): see wip/Text_MeasureWidth_2_001889E0.c (pair with Font_FindGlyph_2_00188910); batch.py can't check it yet.

### More tricks (round 2 of the merged repo: 0x100-0x200 functions, 76 of 83 matched)

MWCC:
- **Pointer advanced by repeated `addiu +0x10`** (GS/DMA packet builders): every qword goes through a `static inline Q *put(Q *p, ...)` that writes `p[0]` and returns `p + 1`. A `u64 v` split as `w0 = v & 0xFFFFFFFF; w1 = v >> 32;` gives the `and`/`dsrl32`, `dsll32`/`dsra32` + two `sw` stores.
- **`(u32)p & 0x0FFFFFFF` gives `dsll32 4; dsrl32 4`** with no sign extension, and `| 0x20000000` then works as an uncached pointer. u64 forms give `pcpyld`/`and` or `dsra32`. A u32 param passed on to a u32 callee param keeps the same shape.
- **Range compares**: `(u32)(r-3) < 2` gives `sltiu v1`; `r == 3 || r == 4`, `<= 1` or `x > 0x4000` (not `>= 0x4001`) give `sltiu $at`.
- **Args loaded in the wrong order before a jal**: change a callee param's signedness (u32 to s32), or write the last arg as `(&e->addr)[1]`.
- **jalr through `lui/addiu` addresses**: function-pointer locals assigned right where the target builds them; assignment order picks the s-reg.
- **Keep a `mult` in a loop** (no strength reduction): `static inline u8 *get(u32 i)` called with an s32 counter.
- **Only the source pointer strength-reduced in a copy loop**: declare it `void *` and copy `dst[i] = ((u8 *)src)[i]`. An 8x unrolled byte copy behind a `beqz` on the source is `if (D_X) for (...) d[i] = D_X[i];`.
- **IV pointer at base+0x80 with fields at +0x50/+0x60**: index the array directly (`D[idx].e[i].f`); an `e++` pointer folds the offsets.
- **Separate `%lo` relocations per field**: an explicit `off = i << 6` local and `*(f32 *)((u8 *)&D[0].x + off)`.
- **Immovable `sw $zero` scheduling**: try f32 fields assigned `0.0f`.
- **`sltu`/`xori`**: an inline helper `return !(x != 0);`.
- **Float globals**: operate on the global itself (`D -= 8.0f; if (D > 128.0f)`); temps change the code.
- **A global reloaded after a store**: declare it volatile.
- **Busy-wait loops**: `while (!f() != 0) {}`. **The gp value stored in a field** (`addiu rX,$gp,0`): `extern s32 _gp; x = &_gp;`.
- **Variadic functions** (no stdarg header): `__builtin_args_info(2)` is the count of named int-register args (the unfolded `li 3; slti 8`; args 0 and 1 crash the compiler). va_start: `ap = (char *)__builtin_next_arg(last) - ((__builtin_args_info(2) >= 8) ? 0 : (8 - __builtin_args_info(2)) * 8)`; va_arg: `(ap += 8, *(T *)(ap - 8))`. See src/game/SndDrv_CallArgs_2_001D8680.c.
- **The last switch case falls into the epilogue without a `b`**: end it with `break`, not `return`.

ee-gcc 2.96:
- **Loads hoisted ahead of a switch's jump**: read those fields into locals before the `switch`.
- **Loops**: a list walk starting with `b cond` is a `goto check;` loop; a test-at-top loop is `for (;;) { if (!(i < n)) {...; return;} ... }`. `while`/`for` get rotated.
- **Switch layout follows source order.** A `case 0:` sharing the default body moves the decision-tree pivot from 2 to 1.
- **Dead constant in a `bnel` delay slot**: an else-if chain where two branches assign the same value (`if (r == -2) v = 3; else if (r == -4) v = 100; else v = 100;`).
- **Constant in the delay slot of the first `beqz`**: the local is initialised at its declaration (`s32 n = 5;`).
- **`movn v0,a0,a0` with v0 preset**: `s = K; if (r) s = r; return s;`. **`bnel v0; sw $0`**: `if (!call()) x = 1; else x = 0;`.
- **Early `return -1` in v0**: one combined `&&` condition; nested ifs pick another register.
- **Stuck saved-register swap**: change control flow (split `if (!(a || (b && c)))` into nested ifs with duplicated fail code); declaration order rarely helps.
- **Extra `daddu sN,vX` copy of a loop pointer**: strength-reduced `&base[i]` with its own counter.
- **Separately kept `%hi` register + `addiu r,sHI,%lo` rebuild**: some paths use the global directly while the rest go through `T *t = &D_X`.
- **`ldl/ldr/sdl/sdr`**: assignment of a byte-aligned `struct { u8 b[8]; }`. A u32 stored as 4 `sb` (srl 8/16/24) is explicit byte stores into a `u8[4]`. A loop with a fixed ldl source and moving destination fills an array of those structs.
- **Float register pairing**: `x = y = 0.0f;` gives the `mtc1 zero` + `mov.s` pair. Chained assignments store right to left.

Tools:
- **Jump tables in build/m2c/*.s can be cut short**; read the full table from the exe (file offset = vaddr - 0xFFF80).
- **An asm function that addresses data through a biased symbol** inside a newly matched C unit's .rodata breaks the link: add the symbol to config/linker_syms.txt.

### More tricks (round 3 of the merged repo: every fresh function above 0x200, 38 of 52 matched)

MWCC:
- **A register in t0/a3 that nothing sets before a jal** is a hidden extra call argument (e.g. a 5th `sprintf` argument).
- **A call argument or global the target loads earlier than you do**: read it into a local through `*(volatile s32 *)&G` first. A global load in a `beqz` delay slot at the top of an inlined helper: read it into a local before the `if`.
- **Globals reloaded after every store through a pointer read from them**: declare them as one struct extern (volatile gets the load order wrong). A store through a global pointer followed by a reload of that pointer: `T *volatile D[]`.
- **Argument load order differs between calls to the same callee**: move the f32 params first in the prototype (same registers under EABI), or make a param u32 so a stack argument (t0) loads first.
- **Params get saved registers before locals**: declare params `void *`, copy them into typed locals, permute the copies.
- **Loop pointer that should be in a saved register**: an out-param inline (`get(&e, j)`) instead of `e = get(j)`. In `a = b = -1;` the rightmost variable gets the first register.
- **`bne` operands the wrong way round whatever the `==` order**: put one side in a block-local temp. A fresh local for a comparison result fixes a0/a1 swaps.
- **`beq; beq; b default` for `x == 5 || x == 6`**: `switch (x) { case 5: case 6: ... }`. `||` becomes a range check; separate `if (...) return;` statements keep separate `beq`s.
- **Clamp with a padded `bnez`**: the ternary `n = (n > K) ? K : n;`. Other clamps only match as two ifs; try both.
- **8x unrolled byte copy plus 1-byte remainder loop** (`sltiu 0x18` / `sltiu 0x20`): inline `cpy(void *d, void *s, u32 n)` with an `s32 i` counter.
- **`lui; ori; addu rd,rs,$at`** for a large constant added late is pointer arithmetic (`u8 *p = ...; p + size`). `(s32)o->data + i*sz` hoists the invariant part; `o->data + i*sz` merges it.
- **Address mask `dsll32 4; dsrl32 4` then a separate `and -16`**: compute `ad = src & 0x0FFFFFFF;` into its own local before an inline that masks `~0xF`.
- **`addiu v0,sp,X; swc1 f0,0(v0)`** is a whole-struct copy: make both sides `struct { f32 f; }`.
- **Commutative `mul.s` order for u32->float * float**: inline `mu(u32 x, f32 k) { f32 t = x; return t * k; }`.
- **`%` operands loaded first but stored last**: write the modulo statement first. `D.a = D.a + D.b` loads in source order; `+=` loads the right-hand side first.
- **Frame layout**: spilled named locals get 4-byte slots in a 16-byte area at the top of the frame with the param homes; copy-propagated and loop-invariant temps get 16-aligned slots below. An unexplained 16-byte slot means the original variable was a temp; making it an inline parameter makes it one.
- **A switch range check using `addi` (not `addiu`)**: the unit was built with mwccps2 3.0b38. Write a plain `switch (x)` with the real case values and add `src/game/func_X.c -O4,p mwcc=mwcps2-3.0b38-030307` to config/game_cflags.txt (try it with `MWCC=mwcps2-3.0b38-030307 tools/match.py diff ...`). b38 is not the default because it reverses some 4-float struct copies (Combat_CalcDamage_1_00132DB0, MapCmd_TranslateNode_0_0017D810, MapCmd_TranslateNodeRel_0_0017D960).
- **`sync; ei` and inlined VU0 `lqc2/vmula*/sqc2`**: asm-only, skip (Movie_DisplayHandler_0_001E8CB0, Mdl_Animate_2_00171BB0; see issue #2).

ee-gcc 2.96:
- **Struct address rebuilt in every case** (`%hi` kept in an s-reg, `addiu rX,sHI,%lo` per use): use `D_X.field` or `#define t (&D_X)`; a `T *t = &D_X` local pins the full address.
- **Shared `jal` plus result check jumped to from several cases** is cross-jumping: write the call and check in full in every case.
- **Register swaps across a big switch**: give each case its own fresh locals; reusing a long-lived variable shifts allocation function-wide. The callee's return type (`void *` vs `void`) changes tail merging.
- **movz/movn**: `c == 0 ? A : B` vs `c ? B : A` flips them; `k = 2; if (c) k = 0;` gives a `movn` feeding a compare. `n = 0xC; if (!(f & BIT)) n = 0xD;` fixes constant-pair order. Independent constant stores come out in reverse source order.
- **`(x + K) * 16` is distributed**; write `(x + K) << 4`.
- **8-byte struct copied via a stack temp with `swc1/swc1/ld/sd`**: `typedef struct { f32 x, y; s32 z[0]; } __attribute__((aligned(8))) V2;`, initialised `{ a, b, {} }`.
- **Invariant load after the loop guard**: `if (i >= 0) { f = G; do {...} while (...); }`.
- **Field reloaded where gcc would reuse a load**: read the first use through `*(volatile u64 *)&s->f` and extract with shifts. An unfolded extern array base re-read after a store: `extern volatile s32 D[]`.
- **Value passed to a short param without extension**: declare the local `s16`.
- **`andi 0xFF` after a byte store**: read the field again after storing it. Adjacent byte tests `a == 2 && (b & 4)` get merged into one `lw`; nest them for two `lbu`.
- **Unsolved**: retail switch trees that test ranges with no code behind them (Pad_UpdateAll_3_001D7350); gcc drops empty cases.

Tools:
- When the instruction count differs, align your build against retail with difflib on normalized opcodes; chk's positional word count is useless then.
- chk.sh is not parallel-safe within one agent dir.

### More tricks (round 4: game-match3)

- **A call that skips an argument reload is a static callee in the same file**
  (MWCC). Merge the callee and its callers into one TU and make the callee
  `static`. A global definition is not enough (Enemy_StartIdleMotion_1_0013C740, Enemy_UpdateMotion_1_0013CBC0).
- **ee-gcc register swaps next to a call**: try the callee's return type.
  `void` -> `u64` fixed Gs_DrawSpriteDirect_0_001E52D0.
- **ee-gcc: a `T **p = &G.f` local vs `*(&G.f)`** gives different
  allocation (Credits_Load_1_001E3B48).

### Data-only units (src/game/data/, tools/data_to_c.py)

How CodeWarrior lays out data, which is what lets one C unit reproduce a
stretch of splat's data:
- Each object gets a section of its own. Initialised objects come out in
  definition order, uninitialised ones in reverse (a `.bss` unit is written
  from the top down).
- An object is aligned by its size: 4 up to 4 bytes, 8 up to 15, 16 beyond.
  `__attribute__((aligned(N)))` lowers that, down to 1, for objects retail
  packs tighter.
- Objects of 8 bytes or less go to `.sdata`/`.sbss`; `-sdatathreshold 0`
  (added by compile_c.sh for src/game/data/) keeps them in `.data`/`.bss`.
- An all-zero initialiser goes to `.bss`; `#pragma explicit_zero_data on`
  keeps it in `.data`.
- Defining a table in the unit that reads it can change that unit's code
  (CodeWarrior folds values it can see), so tables nothing owns live in a
  data-only unit and their readers keep an `extern`.

A `.bss` label at an address CodeWarrior could not start an object of its
size at is a field of the object before it: data_to_c.py folds it in and
gives ld its name in config/data_aliases.txt (`D_field = D_object + off`).
tools/fake_pointers.py first drops the labels splat made from data words
that only look like pointers.

Also:
- `.sdata` and `.sbss` are each one data-only unit (`sdata_00201B80.c`,
  `sbss_00201E80.c`, built with `-sdatathreshold 32767` so every object
  stays small data); carve.py writes their subsegments.
- A jump table of a function that is still asm is written as
  `(s32)((u8 *)func + off)` (the target's `.L` entries are rewritten the
  same way by gen_ninja.py). Move it into the function's unit once the
  function is C.
- The end of `.bss` is libc's `errno` (a small common of sbrkr.c) and the
  0x80 alignment of `_end`; the linker script lays them out.
- The data-only units are part of what makes the image shiftable; see
  "Shiftable build" in docs/ROADMAP.md and run `ninja shift` after changing
  them.

### Moving data into its code (tools/move_data.py)

`tools/move_data.py [--section bss|data|rodata]` lists the data-only
objects exactly one CodeWarrior unit uses that can move into it; `--apply`
moves them. An object stays in src/game/data/ when:
- it is 8 bytes or less (a game unit would put it in .sdata/.sbss and reach
  it through $gp, which changes the code);
- the code that uses it is asm or ee-gcc (it waits for that code);
- the owner declares a type the data cannot be written in (a struct local
  to the file, a 2-D array, a scalar for an array);
- defining it in the owner changes the owner's code (CodeWarrior folds
  initialised values it can see: most .rodata and .data);
- it breaks the link order: a unit's data is one stretch per section, and
  units come in the same order in every section.

The last is common. Retail's data is not in the order of the one-function
files: the tables of Option_DrawFrame_0_0018E980..LoadMenu_DrawSlot_1_00193AF0 sit in reverse function
order, so that run is one translation unit (with an asm function,
text_00192110, inside). Its data moves when the unit is merged.

`tools/data_users.py` notes in each data-only unit which code uses it.

### Translation units with asm functions (INCLUDE_ASM)

An asm function inside a translation unit does not wait for its match:
`INCLUDE_ASM(func_X);` (include/include_asm.h) puts splat's chunk whose
first label is func_X at that point of the unit's .text. It is no inline
asm (game code is plain C): it defines an empty marker function, and
tools/include_asm.py (run by compile_c.sh) renames the marker's section
`.text.iastub` (discarded) and the sections after the Nth marker
`.text.iaN`, so gen_ninja.py links `unit(.text) chunk(.text)
unit(.text.ia1) ...`. The unit's data is one object, in retail order. The
chunk stays in the link order (and in sta.jp.yaml, with the unit's c
subsegment resuming after it under the unit's name) and stays its own
objdiff unit; objdiff_base.py folds the .text.iaN back into .text.

`tools/merge_tu.py` writes the markers for asm chunks in a candidate
(`tools/infer_tus.py --files` lists them), then rm -rf asm and ./build.sh.
To match the function later, replace the marker by its C and drop the
chunk from the link order and sta.jp.yaml.

### Shared constants as translation-unit evidence

CodeWarrior pools a unit's string literals and float constants (one copy per
unit) and mwldps2 never merges two units' copies, so an unnamed `.rodata`
constant that several functions use puts them in one unit.
`tools/infer_tus.py` takes such objects as ties next to the backward steps:
a C string (zero filled to its size), or a 4- or 8-byte value that reads as
a plausible float or double and not as a pointer, used by more than one unit
within `--limit` bytes of code. A named `const` global shared across units
would tie them wrongly; the merged unit's match and the ROM check are the
test.

Padding does not show where a unit ends. CodeWarrior writes each data
object to a section of its own, and ld 2.10 places every input section at
its own alignment only; that link reproduces retail byte for byte, so
mwldps2 added no padding between objects either. Measured on the known
multi-function units: in .rodata, a 4-byte gap to a 16-byte boundary is the
commonest non-zero gap both inside a unit (11 of 39 section pairs) and
between units (12 of 34), and zero gaps occur in both. The only evidence is
order (backward steps) and pooling (shared constants).

### A data-only unit inside a merged unit

A data-only unit between the parts, with the unit's data on both sides, is
the unit's own; `tools/merge_tu.py` takes it in instead of refusing:

- .bss (`tools/absorb_bss.py`): the parts' and the data unit's objects
  become one block at the top of the unit, highest address first
  (CodeWarrior writes uninitialised objects in reverse, so the source
  defined them at the top). An object of 8 bytes or less would be .sbss in a
  game unit, so in retail it was part of a larger one: a run of them longer
  than 8 bytes is one object, a shorter one the trailing fields of the
  object before it (records like `u8 buf[0x204]; s32 a, b, c; s32 d[16];`
  repeat in bss_0049F8A0). The names inside become fields for ld
  (config/data_aliases.txt) and symbol_addrs.carve.txt gets the sizes. The
  block is each name's first declaration; a part that declares one
  otherwise keeps its view through an alias. The parts use $gp, so the
  unit had small data: the grouping, not a threshold, explains it.
- .rodata/.data: the data unit is one more part, at its place among the
  functions (initialised data is emitted in source order with the literal
  pools), and every other part keeps its names extern through aliases, as
  alone, so no visible const is folded.

tools/carve.py handles INCLUDE_ASM units: lib_layout.py joins their
.text.iaN and leaves each chunk a masked gap; carve writes the chunk as its
own asm subsegment (named as any gap) with the unit's c subsegment resuming
after it, links the chunk right after its unit, and skips the merge aliases
(`__as_`) and the markers. Its output on a tree merge_tu.py wrote is the same
but for more `ignored_` constants (the merged units' lui-built numbers).

`tools/infer_tus.py --hints` lists functions that only units within
`--limit` call (from the objects' jal relocations): likely statics of their
callers' file. They are not evidence on their own (a global with near
callers is common); use them to choose where to look for pooled constants
or data order.

`--hinted` (ties of any distance, inside a span a hint covers) was tried
and gives nothing trustworthy: at `--limit` 0x8000 and 0x10000 every
candidate rested on one long data step, one of them across an ee-gcc module
(no CodeWarrior unit can hold that), and with two ties required none is
left; at 0x20000 the ties chain 1,367 files into one. Long-distance order
is link noise here too. Objects a merged unit defines count as that unit's
users (`with_definers()`): users() sees references only, so a merged unit's
own data used by one far unit looked owned by it.

Float ties were audited (per function, inside every merged unit): of the
.rodata literals the game code references, 193 are strings (11 shared by
several functions) and 2 floats, each used by one function. CodeWarrior
reaches most float constants through small data or builds them with lui,
so no merged unit rests on a float tie; the shared-constant evidence is
strings.

`tools/tidy_tu.py` tidies a merged unit: per-part types that read the same
once their own types are one become one type, a lone per-part name goes
back to its base name, and each `NAME__as_<part>` alias is dropped where the
unit still matches without it (all at once, then by halves). On the 36
merged units: 60 types unified, 400 aliases dropped, 244 kept (the parts'
declarations that really differ). Grouped .bss objects keep their separate
names until the code indexes them: Menu_ResetTimers_0_00188F80's six 0x250-byte records
(0x0049F8E0) are noted in its source.

### Merging by function name

With no data ties left (`tools/infer_tus.py` finds 0 candidates), adjacent
units whose functions share a name prefix (`Pool_*`, `Snd_*`, `MapCmd_*`,
...) were merged with `tools/merge_tu.py`, one run at a time, extending the
unit pairwise where a whole run would not merge, and skipping INCLUDE_ASM
units. This is naming evidence, not data evidence: every merged unit
matches and the ROM checks, but a boundary between two prefixes is not
proven. Ten same-prefix boundaries stay split because adding the next part
changes earlier parts' code or clashes on a declaration: before
Enemy_GetPartFlagS_0_0013EC80, Enemy_GetMotionId_0_0013ED20,
Arc_LoadFileTo_1_0015A080, MapCmd_GetItemName_0_0017ECD0,
MapCmd_GetObjectName_0_0017ED20, MapObj_Find_1_001B19A0,
MapObj_CheckActivate_0_001B1A20, PlayerProc_Update_0_001BEFA0,
Player_UpdateStatusEffects_0_001C9FF0 and Se_UploadBankB_1_001DB510.
merge_tu.py now makes per-part renames unique when a part is itself a
merged unit, and renames duplicated non-static `inline` helpers like
statics.

A looser pass then merged (repeated until nothing changed, ROM checked):
adjacent units of one prefix family (leading CamelCase word: `Snd`,
`SndCh`, `SndBank`, `SndEmit`; `Menu`/`MenuProc`; `DbMap`/`DbMapProc`),
whose names alternate in .text as no two files would; and sandwiches A·X·A,
a unit of another name between two of one family (`Combat` inside `Enemy`,
`Seg_Init` inside `Coll`, `Mtx_ToQuat` inside `Quat`), except when X is a
generic helper (`Vec`, `Mtx2`, `Pad`, `Font`, `Msg`, `Model`). 86 merges,
574 game units to 467. Failed: the ten boundaries above, plus
MenuProc_Set_1_0018B150 | MenuProc_DrawItemList_0_0018B860 and
Player_Warp_0_001C92C0 | Player_PlayLevelUpSe_0_001C9FB0 (earlier parts'
code changes).
