# Near-misses

Best attempts at functions that don't match yet. Each compiles; what still differs is noted below.
Check one with `tools/match.py diff wip/func_X.c`.
Most of these also build in the NONMATCHING build (the default, see the top README):
a copy of each one that was checked to do what the retail code does is in `src/game/`
under `#ifdef NONMATCHING`. The inline-assembly matches that are plain
vector math have FPU versions there; the VU0 register helpers, the interrupt handlers and
the DMA waits (Dma_SprClear/Dma_SprInit, so also Dma_SprCopy) stay asm in both builds. (These notes come from KiskarFisk's
shadow-tower-abyss; `tools/order_search.py` there can help with
register and scheduling differences.

| Function | What still differs |
|---|---|
| GsPkt_Flush_1_001544C0 | register choice only (orig p=a0, c=a1, div/n=v1). volatile globals give the reloads |
| MapObj_FindCollider_0_001B1D00 | one `addu` operand order (orig `addu a2,a1,a0`) |
| ScreenFx_DrawModelOverlay_0_00132A70 | orig moves the loop setup after the loop and branches back into it; ours keeps invariants in s-regs (frame 0x70 vs 0xA0) |
| MapObj_GetSfxMatrix_0_001B1050 | t1/t2 swapped between the two slot pointers (inline helpers from MapObj_SetNodeFlag_0_001B16E0) |
| MapCmd_SetSfxParamA_0_0017E5B0 | regalloc of inlined find-object temps; likely same fix as MapObj_GetSfxMatrix_0_001B1050 |
| MapObj_SetSfxMatrix_0_001B0EB0 | regalloc in inlined `find` (orig slots t1/t2, result a3); same family as MapObj_GetSfxMatrix_0_001B1050 |
| TitleMenu_Open_1_001A4420 | store of `a.n` lands 2 slots late; all 24 store orders tried |
| Sfx_BuildNodeTree_0_0016A9D0 | one `addu` operand order (orig `addu v0,a0,v0`) |
| Glow_Add_0_0015DBF0 | ~18 instrs: v70[3] store order, table-update regs, a0/a1 swap |
| Enemy_UpdateTimers_0_0013D8A0 | else-branch: `negu` scheduled before the `andi`/`sw` of `*q` (Actor accessor block) |
| ItemObj_Free_1_001AF4A0 | case-1 list remove: orig reloads count each pass and puts the shift loop's setup after the function |
| MapObj_Hit_0_001B85B0 | ours keeps idx*0x30 in s4 across calls (extra s-reg, frame +0x10) |
| MapObj_SetAnimFrame_0_001B87C0 | first block regs: load from 0x180 to t1 (ours a2) |
| Sfx_AimMatrix_0_00167310 | `b` delay slot left empty (orig fills with next `lwc1 f21`); `move s0,a0` before null check |
| Mdl_RunMotionEvents_0_001717A0 | 4 words, regs only: orig tbl=a1 and keeps q+0x40 in a2 |
| FxProc_RandomJitter_0_0014C890 | &v should be s1 below the loop pointers; multiply operand order |
| Proj_Update_0_00147E90 | last flag: orig writes `c = 0` in a branch delay slot; ours gets an else branch or `sltu` |
| SndBank_IopTransferB_0_0012F0F0 | arg setup of the `Se_SetBankSlot_0_001DAC70` call in state 1: orig loads `ch` first and `off` before `addr[arg1]` |
| Fx_UpdateChildren_1_00162700 | shared inline count helper: orig has 2 nops before `div` in the `rate < fp` branch, `(f32)period` in $f1 (ours $f2) |
| Fx_UpdateChildrenEx_1_001629E0 | same inline helper as Fx_UpdateChildren_1_00162700; fixing one should fix both |
| Proj_FindTarget_0_00146C70 | 4 words, regs only: loaded entry `e` (`lw 0x4B4(s0)`) lands in a1, orig a3 |
| Hud_DrawQuad_1_001BC610 | 23 words, scheduling: orig computes the `b1` bitfield value (`andi t0,zero,1`) before the `f&1` andi |
| FxProc_TrackEnemyBone_0_0014BC90 | final float block: orig computes `2.0f * 0.05f` at runtime; MWCC folds it to 0.1f in every form tried |
| PlayerProc_Attack_0_001C55A0 | arg copies land one temp reg higher in orig (a2→t5, a1→t6, a3→t4, t0→t3, t1→t2) |
| Ui_DrawElem_1_00182C10 | float load/mul order for pos[0..3]; `lq` vs `ld`/`sd` on a 24-byte copy; loop init not in `beqz` delay slot |
| Dma_SprCopy_1_001789E0 | tail copy: orig keeps dead pointer updates `a1/a0 += a2<<4` that MWCC removes (pragmas didn't help) |
| Ui_BeginSprites_1_00181420 | orig uses the loop induction pointer as the final `sq` dest; ours copies it (`move t2,v0`) |
| Enemy_IsOnScreen_0_0013FCC0 | `f32 sz[2]` kept in memory needs `&sz`, which hoists the address into s0; orig uses sp offsets |
| MapColl_CapsuleCastAll_1_001B3240 | saved-reg allocation (orig spills d/cb/b0/off at 0xD0..0xA0) and 0xEE/0xEF home-slot swap of the u8 args |
| Coll_SweepSegmentsInit_1_00151E50 | 1 word: late clear loop count `li v0,16` vs orig 8; the C slot only lands at 0x40 with a 16-byte struct |
| Quat_Slerp_2_0015DFA0 | quaternion slerp; saved regs only: orig `out` in s6, ours s0 (permuter candidate) |
| Mdl_EmitStripD_0_0016DC70 | GIF packet; saved regs rotated (orig gives p and &q.w[1]/[3] the high s-regs) (permuter candidate) |
| MapObj_PlayAnimImpl_1_001B8350 | first block regs shifted by one; orig `li v1,1; movz v1,zero,a2` for `a2 ? 1 : 0` (MWCC gives sltu) |
| Actor_BuildLookMatrix_0_00136DB0 | inlined axis-angle rotation (as Mtx_AxisAngle_2_0015EBB0 times a vector): float scheduling/regs only |
| MapCmd_GetSfxParamB_0_0017EAF0 | adapted MapCmd_SetSfxParamB_0_0017E940 inlines; shape identical, temp regs only (slot pointer v1 vs a2) |
| Mdl_EmitPolys_1_0016EF70 | right size/branches, loop regalloc differs (orig spills a0, i in t9); far (155 words) |
| Tex_Resident_0_001777C0 | ~50 words, regs only (size calc reuses a0; Vram_AllocForTex_0_00176BF0 result in a1; TEX0 bitfield temps t0/v0 vs ours t1/t0) |
| Vram_AllocBlock_1_00176FB0 | 159 words; saved-reg swap (orig: sign-extended idx/return in s2, raw param s1) shifts all temps |
| Hud_DrawCompass_0_001BBCC0 | 8 words; one `mult1` dest v1 vs a0 (2800 statement orders tried) |
| Tex_Lookup_1_00177BB0 | 88 words; free-list unlink/insert regalloc (idx in a3 vs v1, idx*48 reused) |
| Actor_ResolveGround_0_0013A720 | 2 words; `addu` operand order in `p->x2C + p->x18->xB5*0x140 + 0x234` |
| Enemy_ScatterPart_0_001A8700 | 45 words; saved-reg assignment / setup scheduling |
| ItemObj_BindCaps_1_001ADD30 | uses string literal `"CAPS"` (non-small-data); code matches but batch.py can't link literals |
| Mdl_DrawMeshesD_1_0016D830 | 6 words; byte from `m[idx].x130` in a3 vs a1 |
| FxProc_OrientToVelocity_0_00148120 | 8 words; float temps of the early constant multiplies |
| MenuProc_DrawItemList_0_0018B860 | 3 words; `move s0,zero` vs loop-entry `sltu/beqz` order |
| Player_StartAttackMotion_1_001C6590 | 6 words; case 8 temp v1/v0 for 30.0f, final-call arg order |
| Menu_LoadLayout_0_00189740 | 57 words; unrolled 2nd loop wants `p+0x10` in t1 |
| Enemy_UpdateMovement_1_00134960 | 2 words; masked `Enemy_PickNearestWaypointToward_1_001435D0` result in a0 vs a2 |
| GsPkt_ResetFrame_1_00153770 | 6 words; t1/t2 swap in last 3 GS pushes |
| Script_OpArith_1_00165A30 | 5 words; orig has empty then-branch `bnez isf -> load; b join` |
| Enemy_BreakPart_0_0013F210 | 16 words; v0/v1 swap in the two clamps of the `flag` branch |
| ItemMenuProc_DrawInfo_0_0019CEF0 | 3 words; `a3*9` temp a0 vs a2 in case 400 |
| Coll_CapsuleVsMesh_1_0014E230 | 65 words, stack offsets only: orig spills pointer params o1/o2 to 16-aligned slots (frame 0x2A0) |
| MenuProc_DrawHpMp_1_00185740 | 40 words; orig reloads `o->x38` after `o->x38 += 4.0f` |
| Map_LoadArea_1_001B51F0 | 56 words; prologue moves a2 to s3, saved regs for n/cur/&PP(n) rotated |
| Enemy_UpdateMotion_1_0013CBC0 | code identical when Enemy_SetMotion_2_0013C360 is a `static` definition earlier in the same file (MWCC then knows a0/t0 survive the call); needs file regrouping |
| Actor_CollideCapsulesB_0_00137E60 | 16 words; f22/f23 swap for t/dd, `out` param spill slot 0xC0 vs 0xC4 |
| Lz_DecompressB_1_001797E0 | 118 words; needs static Bits_Read_2_00179720 earlier in file (included); r/n v1/a0 swap in inlined bit reads |
| Coll_SphereVsMesh_1_0014E680 | 60 words; frame 0x10 bigger in orig (unknown 8-byte slots), one mov.s swap |
| Mdl_DrawMeshesC_1_0016D380 | 126 words; `flag & 1` kept in s5 from prologue, spills differ |
| DbItemProc_DrawInfo_0_001973F0 | 169 words; saved-reg order only (orig sel=s4,n=s3,k=s2,id=s1,o=s0) |
| Player_FireWeapon_0_001C0020 | 1 word; `addu a1,a0,s2` operand order |
| Input_Update_2_0015F540 | 177 words; s-reg choice only (p/q/converted value) |
| Mdl_DrawMeshes_1_0016C7E0 | far: 16 bytes short, ctx spill not reproduced |
| Attack_Ricochet_0_001D31E0 | 48 words; innermost `h + n4*20` operand order, pointer table regs |
| Actor_CollideCapsules_0_00137870 | far; orig spills outer counter i and count na, keeps inner k in s3 |
| Mdl_ClipFrustum_0_0016BD00 | far; right size, float temp allocation off throughout |
| MenuProc_DrawWeight_0_00185D70 | 2 words; temp reg of the 24-byte `buf = gMenuProcDrawWeightData_001F26B0` lq/sq copy (a2 vs a0) |
| FxProc_ChaseEnemy_0_00148D00 | angle-wrap `PI + a` sum shared (orig recomputes), bitfield `++` reuses reg |
| Coll_RayVsModel_1_0014FA30 | one extra spill slot, frame 16 bytes bigger |
| Map_FindChunk_0_001B6190 | uses string literals "STMI"/"STEM"/"STOI" (>8 bytes padded); batch.py can't link literals |
| DbCharProc_DrawInfo_0_00196330 | 3 words; `Item_GetTable_1_001AFC90()[a3]` index temp a0 vs a2 (same as ItemMenuProc_DrawInfo_0_0019CEF0) |
| EnemyMgr_Update_0_001A4990 | ~50 instrs; 11-entry loops start with `addu sN,v1,zero` + pad nop |
| Sfx_DrawBillboard_0_00168480 | 73 words; GS setup regalloc, missing pad nop after clamp |
| Mdl_DrawMeshesB_1_0016CD80 | 29 words; hdr/q swapped (orig keeps q in reg, hdr on stack) |
| Lightning_BuildStrip_0_00164440 | 3 words; param a2 spills to 0xDC instead of 0xD0 |
| MenuProc_DrawItemStats_0_00184280 | 3 words; `id*9` temp a0 vs a2 in case 0x261 (same pattern as ItemMenuProc_DrawInfo_0_0019CEF0/00196330) |
| Attack_SpawnHitEffect_1_001D2CB0 | 45 words; i/mask a0/a2 swap in loop 1, two addu orders, byte-load order at end |
| Inventory_Sort_0_0019FD00 | 61 words; case 1 s16 truncation late, case 6 regalloc |
| Pool_Init_2_00128A60 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Snd_LoadBank_1_0012E3C0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| SndBank_UploadIndexed_0_0012E810 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Combat_UpdateProjectile_0_001395A0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Enemy_UpdatePartStat_0_0013F0C0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Pool_FreeChunk_0_001531A0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Gfx_BuildViewMatrices_0_00155090 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Weather_Draw_0_00157630 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Weather_RespawnParticle_0_00157FE0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| PointLight_Init_0_0015C8D0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Quat_ToMatrix_2_0015E180 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Input_Init_2_0015FC60 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Fx_HashKey_1_00164A60 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Script_FetchOperand_2_00165940 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Script_FindLabel_1_00166970 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Sfx_SortByDepth_0_001679E0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Sfx_DrawMesh_0_00167C90 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Sfx_Create_2_00169F40 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Sfx_LoadSystemStam_1_0016AE30 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Mdl_SetLayerForMesh_0_0016B360 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Dma_SprClear_1_00178C00 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| MapCmd_PlaySeOnObject_0_0017BAC0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| MapCmd_ResetObjects_0_0017C930 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Text_Render_2_00188010 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Text_MeasureWidth_2_001889E0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Shop_Update_0_001A1C80 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| EnemyMgr_ReleaseData_0_001A51E0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Enemy_Draw_1_001A5DE0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| EnemyData_Alloc_0_001A7D90 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Enemy_InitPartState_1_001A8510 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| ItemObj_TestVisible_0_001ACD90 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| ItemObj_SpawnProjectile_0_001AD2C0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| ItemObj_SaveState_1_001AE510 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| MapObj_GetCount_0_001B17E0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Map_UpdateEnemySpawns_0_001B43A0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| MapObj_UpdateAll_0_001BAB70 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Player_UseItem_1_001CAEF0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Player_CalcAttack_1_001CEBF0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Attack_TriggerSfxEvent_0_001D21E0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Attack_TestActor_0_001D2890 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Attack_GetHitMask_0_001D2A80 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Mc_StepGetInfo_3_001D3BF0 | round Y/Z near-miss (agent's best attempt; see comments in file) |
| Credits_Load_1_001E3B48 | round 2 near-miss: ee-gcc, s1/s2 swap, switch store merging, &g->data in own register |
| Task_Init_1_001E03C0 | round 2 near-miss: 8 words: li constants scheduled between the two lw of the loop-2 preheader |
| GsText_FindGlyph_1_001E3058 | round 2 near-miss: ee-gcc, 5 words: lo+hi in a2 instead of v0, one slt in v1 |
| Credits_EvalRect_1_001E4A18 | round 2 near-miss: ee-gcc, 4 words: first two float loads have f3/f0 swapped |
| SndDrv_RpcServerFunc_1_001D8AB0 | round 2 near-miss: ~2 insns: missing addu a1,v1,$zero before the unrolled copy, plus a nop |
| Mc_StepWriteChecked_3_001D4170 | round 3 near-miss: ee-gcc memcard save machine, 2 words short; cases 1/2/5/19 differ |
| ShopProc_DrawItemStats_0_001DE2D0 | round 3 near-miss: 6 words: lw a2 (Col stack arg) vs lwc1 f12 order before Text_Draw_2_001875C0, 3 sites |
| Se_TransferBank_0_001DB020 | round 3 near-miss: 5 words: register swap in case 0's gSeBss_004BAA28 update |
| Mc_StepReadChecked_3_001D4A78 | round 3 near-miss: ee-gcc, ~24 lines after alignment: case 1 fail path, case 14 scheduling |
| Pad_UpdateAll_3_001D7350 | round 3 near-miss: ee-gcc, 23 words short: retail keeps empty switch cases [2,3] and 0x100 in the tree |
| ShopProc_DrawItemInfo_0_001DDA20 | round 3 near-miss: 3 words: 1 handwritten addi at the switch range check (asm-only), 2 lwc1/lw order |
| Se_UpdateStatus_0_001D9FC0 | round 3 near-miss: 15 words: temp register numbers in the 8x32 loop |
| Gs_UploadTim_1_001E54E8 | round 3 near-miss: ee-gcc, 22 words: saved-register choice for k/w/h/h2 |
| Gs_DrawSpriteDirect_0_001E52D0 | round 3 near-miss: ee-gcc, 6 words: D2_QWC/D2_MADR constants in v0/v1 swapped |
| GsText_EmitGlyph_1_001E3178 | round 3 near-miss: ee-gcc, ~70 insns after alignment, 3 short |
