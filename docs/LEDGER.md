# Matching ledger

Breakthroughs and tricks worth reusing, and functions given up on (with why).
Game functions are matched smallest first.

## Tricks

- **Function names carry a certainty.** Every game function is
  `<Name>_<certainty>_<ADDR>` (0 = a guess from shape and callees, 5 =
  confirmed, e.g. a KFIV/holyland match of 1.000). The names live in
  `config/game_func_names.txt`; edit a name or certainty there and run
  `tools/apply_names.py` (it rewrites sources, file names, yaml, link order and
  symbol_addrs.txt), then rebuild. `tools/name_dossier.py START END` prints
  each function's strings, callees and C for (re)naming. Tools match function
  symbols with `tools/names.py` (`FUNC`, `func_name`), not `func_XXXXXXXX`.
- **m2c batch first.** `tools/m2c_batch.py --max-size N --accept` runs m2c on
  every unmatched game function and keeps whatever compiles to the retail
  bytes unchanged. On functions up to 0x80 bytes, 279 of 915 matched with no
  hand edits.
- **%hi/%lo means "bigger than 8 bytes".** CodeWarrior (like gcc -G 8) reaches
  objects of 8 bytes or less through $gp. A global the retail code reaches
  with lui/%lo is an array or struct: declare it `extern T D_X[];`.
- **Feed m2c the prototypes.** Without context m2c drops arguments set
  before a tail call (`j func` with `$a0` in the delay slot). A context of
  the signatures m2c infers for every function fixes most of these.
- **128-bit moves.** `lq`/`sq` copies come from `__int128` under CodeWarrior
  (`s128`/`u128` in include/common.h); under ee-gcc from `mode(TI)` ints.
- **Gap units start at the 16-byte boundary.** Zero fill after a C unit
  is the next function's alignment; carve.py no longer turns it into a fake
  `nop; nop` function.
- **Split audit.** `tools/check_split.py` checks every game function's
  bounds (alignment, terminating jump, fill, branch/call targets, stack frame,
  unreachable code). It found one merge, the VU0 helper at 0x1DC8D0 (now
  split in symbol_addrs.txt). CodeWarrior often branches to just past a copy
  of the branch's delay slot, leaving one unreachable word: not a split error.
- **Callee parameter types steer scheduling.** Passing a byte load to a
  `u8` parameter (not `s32`) makes CodeWarrior load the arguments in the
  retail order (the 0x154 getter wrappers around 0x143920).
- **Near-duplicates.** `tools/dupes.py` groups functions that differ only in
  symbols and immediates, rewrites a matched one's C for each unmatched
  member and keeps what matches. Families it cannot rewrite (bitfield
  setters: the immediates are bit positions) are quicker to generate from
  the asm with a short script.
- **m2c misses returns.** A value left in $v0 at `jr $ra` may be the
  return value: `return D++;` matched where `D++;` did not.
- **`ldl`/`ldr` pairs on a global = an 8-byte struct passed by value.**
  `typedef struct { s32 a, b; } Pair;` passed as an argument loads into one
  64-bit register unaligned (PlayTime_DiffNow_2_001DF910).
- **`daddu` argument copies / dsll32-dsra32 extensions point at 64-bit or
  narrow parameter types.** `tools/typeperm.py` tries every type assignment
  for @T0@.. slots on all cores; a wrapper's callee prototype usually falls
  out in under a second.
- **Small gp arrays.** A global indexed off `addiu $r, $gp, X` is an array
  of 8 bytes or less (`s32 D[2]`).
- **SndDrv_CallArgs_2_001D8680 is variadic** `(s32, s32, s32, ...)`: its wrappers pass
  u16 values zero-extended and the rest as is.
- **Load order against hardware registers**: a global read after a
  `*(volatile s32 *)0x10000000` (T0_COUNT) is itself volatile
  (Timer_GetTicks_3_001787A0).
- **A byte-pair copy loop counting down from N is a struct assignment**
  (`*p = D` of an 8-byte, byte-aligned struct: PlayTime_CopyClock_1_001DF930).
- **Stack frame size tells the local's size**: a local struct handed to a
  callee may be bigger than the part read back (Actor_GetDir_1_001465C0, 0x60 frame).
- **m2c_rules.py** (applied by m2c_batch.py, kept only when it scores
  better): callee prototypes from argument casts, typed array indexing for
  m2c's byte-scaled pointer arithmetic, base-first indexing.
- **Branch on the argument register, copy in the delay slot**: the
  parameter is `void *`, copied to a typed local, and the `if` tests the
  parameter (`Obj *o = a; if (a && p) o->v = ...`: Sfx_SetOwner_1_00167600,
  Sfx_GetMatrix_1_001676E0).
- **`slti $at` vs `slti $v0`**: CodeWarrior compares into $at for `x > N`
  and into a temp for `x >= N+1` (bounds checks 0x195420 family).
- **Field offset in the load, not the relocation**: when retail keeps the
  array base symbol and puts the field offset in the load/store, take a
  pointer to the element first (`E *e = &D[i]; e->v = v;`); indexing
  straight to the field folds the offset into %lo (both compilers).
- **`sqrt.s`** shows as `c1 0x140004` in the disassembly: `sqrtf()`.
- **The second ee-gcc module ends at 0x1E5E80**, not 0x1E5E40: its last
  function (Sjis_IsLead_1_001E5E40, a Shift-JIS lead-byte test) is gcc code.
- **Unused-looking `$a0` at an indirect call**: the caller passes its own
  argument through (`fp(a)`, MenuProc_CheckReady_0_0018B2E0); m2c drops it.
- **Locals are laid out in reverse declaration order** on the stack
  (EnemyType_LoadTable_0_001A83A0); load-all-then-store sequences come from loading into
  locals first (MapCmd_WarpPlayer_0_0017CE20).
- **`slt $at, x, $zero` + `bnez`** is `0 > x`; `x < 0` gives `bltz`
  (Inventory_GetSlot_1_001A97D0).
- **Operand order of a pointer sum** follows the C: `(u8 *)(i * 64) +
  (s32)base + 16` put the index first (EnemyType_Get_0_001A8360).
- **A small struct passed by value** shows as the argument stored to the
  stack and its bits read back from there (ItemObj_FilterOpaque_0_001ACFE0, ItemObj_FilterTranslucent_0_001AD030).
- **CodeWarrior unrolls simple loops by 8** at -O4,p (GlowFx_Init_0_001E1200: a
  16-entry fill written as a plain `for`).
- **Branch layout follows the return style**: a single result variable
  (`r = ...; else r = ...; return r;`) vs early returns decides where the
  `b` to the epilogue lands (Enemy_GetTargetHandle_0_0013EDE0, Hud_IsHidden_0_0019A790).
- **`bne`/`beq` operand order is the C operand order** (`id == e->id` vs
  `e->id == id`: DbMap_GetKillRate_0_001959E0).
- **Division by a constant** shows as a `multu`/`mfhi` magic sequence;
  the divisor is 2^(32+shift)/magic (Sfx_GetFreeSlots_1_0016B230: /1728).
- **A 4-byte value spilled to the stack and passed in a register** is a
  4-byte struct (an RGBA colour) passed by value (Pause_DrawText_2_0019E7C0).
- **ee-gcc: a value used after a call that the asm takes from $v0** is the
  call's return assigned back (`p = f(p, 16)`, Credits_Alloc_1_001E4030 area).
- **movz vs movn is the ternary's sense**: `x ? A : B` vs `!x ? B : A`
  (MapObj_SendEvent_1_001B0A80); m2c_rules.ternary_sense tries the flip.
- **Function-pointer tables** of 12-byte records are indexed straight to the
  field (`D[i].b(v)`), which folds the field into the symbol's %lo
  (FxTable_CallA_0_0014D8E0 family).
- **ee-gcc stores constants in reverse source order** when several are
  materialised together (Mc_StartCheck_1_001D6BB8: write `state = 9` before `x98 = 0x33`
  to get retail's order).
- **`sltu` loop compares on a u16 count mean an unsigned index** (`u32 i`,
  Map_InitObjects_0_001B6130).
- **Range-checked returns**: whether retail branches to the value or to the
  zero first follows `if (in range) return v; return 0;` vs
  `if (out of range) return 0; return v;` (Item_GetMotionId_0_001CC390, Inventory_GetEntry_1_001CC3F0).
- **A global pointer reloaded before every store is `T *volatile`**
  (Snd_PlaySeAt_2_001315A0).
- **The player-record getter** (gPlayerSbss_002022E4 -> +0x518 -> +0x180, NULL at
  each step) is inlined everywhere: write it as m2c's nested if/else into a
  local, then `if (t == NULL) return 0; return t->...;` (Player_GetPosB_0_001C9490,
  Player_GetHpS16_0_001C99C0, Player_IsCrouching_0_001C9A20, Player_IsMoving_0_001C9A80).
- **`T t = { 0 };` is CodeWarrior's byte-clearing loop** on a stack struct
  (EnemyCmd_ShakeCamera_0_001455B0).
- **Stack slots size the locals**: m2c types a vector temp as `s32 spXX`;
  a 16-byte `f32 v[4]` gives retail's offsets (Enemy_PickWaypointDir_1_00143290).
- **A value stored then passed on**: retail passes the register when the
  C uses a temp (`h = f(); o->x = h; g(h);`) and reloads the field when the
  C passes `o->x` (Res_Open_0_0014DC70).
- **A sign-extension of a call's result** in the caller means the callee
  returns `s32` and the caller casts (`while ((s8)f(...))`, EnemyScr_Event2022_1_00140DE0);
  declaring the callee `s8` drops the extension.
- **ee-gcc state setters (0x1D6910 family)**: `tools/stmtperm.py` found the
  order in 1.4 s over 3,024 candidates: constant fields first (`state`, the
  zeroed ones), then the parameters, and the second constant last.
- **`beq x, K, body; b end` is a one-case `switch`** (Bgm_RpcCallback_0_001D9DC0); an
  `if (x == K)` gives `bne x, K, end`.
- **Declaration order of locals also picks registers** (Msg_GetText_2_00195B10:
  declaring `i`, `e` before `t` moved `t` from $a3 to $a1), besides the
  reverse stack layout.
- **Make m2c's output compile before tuning rules**: `void *` -> `u8 *`
  (m2c relies on GNU byte arithmetic) and casts on assignments to pointer
  temps cut compile failures from 1,029 to 690 and matched 12 functions
  with no hand edits.
- **A `relaxed-match` from m2c_batch** compiles to the retail bytes only
  with -relax_pointers: give the calls real prototypes (SIF RPC setup,
  SndDrv_RpcServerThread_1_001D8BE0) and it matches strictly.
- **`daddiu $r, $0, K` vs `addiu`**: CodeWarrior loads a constant into a
  u8/s8 variable with daddiu and into an int with addiu (MapCmd_GetObjectName_0_0017ED20:
  the result variable is s32, not u8).
- **Float compare operand order is the C order**: `c.eq.s $f0(zero), $fX`
  comes from `0.0f != x` (FxProc_FollowPlayer_0_0014AAF0, Vec2_Angle_1_00187460).
- **A switch's compare chain runs in reverse source order**: retail testing
  19, 18, ... 2 (ItemType_GetCategory_0_001D1CB0) or 2, 1, 0 (Option_MapKeyTypeA_0_001905E0 family) comes from
  cases written ascending.
- **`D_X + 0x8` in a gp-relative splat operand is a separate small global**
  (gMapSbss_00201E88, Map_FreeAll_1_001B5940); declaring one struct makes CodeWarrior
  address it with lui/%lo.
- **`fptodp` ... `dptofp` around a call is double arithmetic**: CodeWarrior
  does doubles in software (dpmul at 0x120040): `x = -1.0 * (s * s);`
  with a float `s` (Glow_OffsetAll_0_0015D5A0).
- **`if (!(p = f()))`** tests the call's $v0 directly; `p = f(); if (!p)`
  copies it to $a0 first (MapCmd_GetEnemyPosition_1_0017C620).

- **String literals in .rodata.** CodeWarrior puts literals in .data by
  default; `#pragma readonly_strings on` moves them to .rodata
  (ItemObj_BindCaps_1_001ADD30's "CAPS" FOURCC).
- **Jump table rotated by one entry** (entry 0 points at the last body):
  case 0 shares the default body, written after the other cases
  (Shop_Update_0_001A1C80's second switch).
- **Address-ordered global stores.** A run of constant stores to separate
  globals matched in address order although the retail schedule interleaves
  them (ScreenFx_SetFlashParams_0_00159340).
- **ee-gcc `andi 0xFF` on a compare with a stored byte**: declare the u8
  local it is compared with as `s32` (Pad_Read_4_001D7110).

- **A call that skips an argument reload = a static callee in the same file.**
  CodeWarrior tracks which registers a static function defined earlier in the
  translation unit leaves alone, and its callers stop reloading them.
  Enemy_StartIdleMotion_1_0013C740/Enemy_UpdateMotion_1_0013CBC0 (no `$a0` reload after Enemy_SetMotion_2_0013C360) matched
  once Enemy_SetMotion_2_0013C360 through Enemy_UpdateMotion_1_0013CBC0 became one file with
  Enemy_SetMotion_2_0013C360 static (src/game/Enemy_SetMotion_2_0013C360.c); a global definition in the
  same file is not enough.

- **ee-gcc: a callee's return type moves registers around it.** Declaring
  `sceGsSyncPath` as `u64` instead of `void` freed `$v0`/`$v1` for the
  following hardware-register stores, so they came out in retail's
  registers (Gs_DrawSpriteDirect_0_001E52D0, found by the permuter).
- **ee-gcc: `*(&G.f)` instead of a pointer local.** `u8 **pd = &G.data;
  *pd + b` was the near-miss; `*(&gCreditsLoadBss_004BC2F0.data) + b` matched
  (Credits_Load_1_001E3B48, found by the permuter).

## Aborted

- Vu0_CopyQword_3_001DC328, Vu0_CopyQwordB_3_001DC338 (lq/sq through $a2), Vu0_LoadVf12Vf13_2_001DC388 (lqc2
  only): VU0 helper module; the code is libvu0's inline asm (sceVu0CopyVector
  shape). Deferred until it is settled which SDK macros are allowed.
- MapSe_GetState_0_001E1D20 (ee-gcc): retail loads a >8-byte global as `lui $at` (gas
  macro expansion); gcc 2.96 emits explicit %hi/%lo through $v1 for arrays
  and structs, and $gp for scalars. Unknown declaration.
- Loading_Nop_0_0018E440: `lw $a0,0($a0); addiu $v1,$0,0x16; jr $ra` with nothing used;
  CodeWarrior drops such dead code from every form tried.
- DegToRad_3_00161030: deg-to-rad; one word off: retail `c.eq.s $f12,$f0`, every
  form tried gives `c.eq.s $f0,$f12`.
- VU0 distance helpers Vec_DistSqXZ_2_0015DEB0, Vec_DistXZ_2_0015DEE0, Vec_DistSq_3_0015DF20,
  Vec_DistB_3_0015DF50, Vec_Distance_3_00146940 (lqc2/vsub/vmul/vsqrt) and Timer_IntrHandler_2_001787C0
  (`sync`, `ei`): need SDK macros/headers in game code; deferred.
- FxTable_GetEntry_0_0014D8A0, GsPkt_AddRegData_1_001541F0, GsPkt_SetReg_3_001543E0, Gfx_EndScene_0_001741D0: a local written directly, then read back
  through `addiu $r, $sp, X` + load; every local/union/cast/volatile form
  folds the address into the load.
- Script_SetArgF32_1_00164FF0, Script_SetArgS8_1_00165030, Script_SetArgU8_1_00165070, Script_SetArgU16_1_001650F0: two stores
  into o->e[i][j] (0x36C/0x370, rows of 0x258); retail adds the row, then
  the column, and keeps 0x36C in the store; no form tried does both.
- Mdl_AnimateCur_0_00171AF0, Mdl_AnimateSel_0_00171B30, Mdl_AnimateWrap_0_00171B70: wrappers of Mdl_Animate_2_00171BB0
  computing o+0x40 + n*(o->h6*0x140+0x200); evaluation order differs.- Player_PlayLevelUpSe_0_001C9FB0: `if (on) f(0x140, 0x7F) else f(0x13C, 0x7F)`; retail puts
  the epilogue's `ld $ra` in the branch delay slot, no form tried does.
- GsText_SetVertex_0_001E3758 (ee-gcc): four float stores into p[i] plus a word; gcc 2.96
  computes three separate element addresses in retail.- FxProc_StopLight_0_0014A860: `i = (s32)o->fb0; if (i != -1) f(i, o->f68)`; retail keeps
  i in $a1 and o in $a0, CodeWarrior swaps them in every form tried.
- GsPkt_AllocDirect_1_001543A0, GsPkt_Alloc_3_00154A80: lazy init of a gp-less pointer then += n*16; $v0/$v1
  allocation differs in every form tried.- Proj_ReleaseEffect_0_001476D0, FxProc_ReleaseChild_0_0014B170: o->a8 goes through a stack slot and is
  reloaded straight into $a0 for the test and the call; volatile locals and
  4-byte struct copies reload differently.- Se_IsVoiceActive_1_001DA4F0, Se_FindFreeBank_0_001DAC30 (bounded table scans) and MapSe_Request_0_001E1D30
  (ee-gcc, three globals): branch layout differs; not yet retried.- Option_MapKeyTypeA_0_001905E0, Option_MapKeyTypeB_0_00190630, Option_MapKeyTypeC_0_00190680: small switches on 0/1/2;
  retail tests 2, 1, 0 in that order, CodeWarrior's switch and if chains
  tried test in another order.
- Waypoint_Get_0_00143840: returns &o->e[i] unless its float <= 0; retail recomputes
  the field address with a second `lui $at`, forms tried fold it.
- ItemType_IsWeapon_0_001D1D50: SOLVED, the `addi` range check comes from mwccps2 3.0b38
  (b50/b52 emit `addiu`); now built with it via config/game_cflags.txt.
- GsText_PackColor_0_001E1EE0 (ee-gcc): compares a u8 with -6 and -1, which gcc 2.96
  folds away for every declaration tried.- Sfx_ReleaseOwned_0_00167580: `if (D[i].v == v) D[i].v = 0` over 256 records; `bne`
  operand order stays reversed with both operand orders.
- Pad_RequestAnalog_3_001D7DE8, Credits_Alloc_1_001E4030, Credits_BindCallbacks_1_001E4080 (ee-gcc): register allocation
  ($v0/$v1, saved-register order) differs; logic matches.- SndCh_IsPlaying_1_00131060, SndCh_SetPitch_1_00131130, SndCh_GetPosition_1_00131180, SndCh_Stop_2_00131440: lookups through a bounds-checked record
  getter that retail has inlined (result in $v0, then tested); a `static`
  getter is folded away and an explicit if/else is laid out differently.
- Script_ResetSlot_1_00164F10 (empty u8 loop), MapCmd_SetObjectNode_0_0017B9E0, MapCmd_GetItemName_0_0017ECD0,
  Ui_IsImageLoading_0_00183FF0: register or branch layout differs after two tries each.- Attack_GetParams_0_001D2C60 (address sum of three byte-scaled indices), Se_FindFreeSlot_0_001DB6B0
  (free-slot scan, result branch), SaveSys_GetCardKind_0_001E60C0 (movz/movn select; also SaveSys_IsCardReady_0_001E6110): operand
  or branch order differs after two tries each.- Sfx_Spawn_2_00169B50 (7-argument wrapper), TexAnim_GetFrame_0_00175850 (4-record search;
  CodeWarrior unrolls the loop retail keeps): not matched in one try.- Inventory_FindItem_0_001AA650 (nested 42x16 count), Pad_IsAnalog_1_001D7E38 (ee-gcc, two bitfield tests merged into one 64-bit
  mask compare): not matched in one or two tries.
- Combat_ResolveHit_1_00135E30: a two-case switch on a u8 argument; retail copies the
  argument to $t2 first.
- GameFlag_GetHalf_0_0013D560: two calls in an if/else returning the high or low half.
- EnemyCmd_StopEffect_0_00144B80: clamp of a table byte to 0x80 into a slot; branch layout
  differs.
- Mdl_GetMotionLength_0_00173F70 (offset-table float read), DbTable_FindA_0_001957E0, DbTable_FindB_0_00195840,
  DbChar_FindEntry_0_00195900, DbChar_GetName_0_00195970, DbMap_GetName_0_00195A30 (tagged-entry search, the last
  three through an inlined handle getter; a static inline `find` got to 7
  words, registers differ), Map_UpdateBones_0_001B4AF0: not matched
  in two tries.
- Strm_SetVolume_2_001303D0 (clamp to 0x7FFF + store + call), Enemy_StartIdleMotion_1_0013C740,
  MapSe_Flush_0_001E1CC0 (ee-gcc store order): not matched in one try.
- OptionProc_Back_0_00191C40: not matched in one try.
- Pad_Init_3_001D7290: SOLVED, an ascending `for (i = 0; i < 8; i++)` (gcc turns
  it into the count-down loop with the right registers; the count-down
  source swaps them). MapSe_Flush_0_001E1CC0, Credits_BindCallbacks_1_001E4080 failed tools/stmtperm.py.
- Lz_StreamDone_0_00178FD0, Event_CheckTalk_0_00179F10 (stack struct init: order of the stores),
  MapCmd_SetLightPos_0_0017DC00 (two stack vectors): not matched in one try; candidates for
  tools/stmtperm.py.
- GameFlag_SetBit_2_0013D5C0 (bit set through two calls), EnemyCmd_ClampHpFromFlag_1_00144420 (u16 compare
  of two call results): register order differs.
- SndBank_RegisterSet_0_0012E640, Enemy_GetCollider_0_0013FB90, Bgm_Poll_0_001D95E0: not matched in one try.
- PlayerData_GetStatusTimer_0_001CE200: guarded read of a top byte; branch layout differs.
- Item_LoadTableB_0_001AFFA0 (resource header check + aligned pointer): not matched in one try.
- Enemy_GetMotionFrame_0_0013ECA0 (an inlined record getter evaluated twice; a static
  function is CSE'd to one call), MapCmd_CopyVar_0_0017D1C0: not matched.
- MapState_IsVisited_1_001AA440, MapState_SetVisited_0_001AA4C0, MapState_SetWord_1_001AA5D0 (index search over
  D_001F37B0 inlined before a record access), Tex_FindAnim_0_0016FF80: not matched.
- Player_IsHitTarget_0_001C7320: one word: `bne` operand order in a u16 search; both C
  orders and a hoisted value give the reverse.
- Trap_Attack_0_001BAA10 (two-case switch to callees), Mc_SetErrorStatus_4_001D3DA8 (ee-gcc
  error-code switch), Bgm_Update_0_001D9680/Bgm_Stop_0_001D9710 (SIF DMA status; the
  status byte is read through its own symbol, the struct through $s0):
  not matched in one try.
- MapCmd_SetEffectPos_0_0017CAC0 (three stack vectors to one call; store schedule), and
  MapCmd_SetLightPos_0_0017DC00 like it: not matched.
- Vec_YawAngle_2_0013FC10 (heading wrap after atan2), MapSe_Init_0_001E1D70 (ee-gcc store
  order, like MapSe_Flush_0_001E1CC0): not matched.
