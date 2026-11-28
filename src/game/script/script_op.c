#include "m2c.h"
#include "game/script.h"
typedef struct { s32 type; union { s32 i; f32 f; } v; } Val;
typedef struct { u8 pad[8]; u32 *pc; } Ctx;
typedef struct { s32 op; Val args[16]; u8 m[16]; u8 pad[0x1C]; } Cmd;
typedef struct { s32 a; s32 b; u16 c; u16 d; } Ent;
typedef struct {
    s32 f0; s32 f4; s32 f8; u16 fC; u16 fE; s32 f10; s32 f14;
    Ent ent[16];
} Slot;
typedef struct { s32 h0; u32 count; s32 *base; } Mgr;
typedef void (*Fn)(Cmd *);
extern Fn gScriptOpData_001F2400[];
extern Fn gScriptOpData_001F1CD0[];
#ifndef NONMATCHING
extern Fn gScriptOpBss_0033F540[];
#else
/* data twins (src/game/data/vibration_bss_0033F540.c): gScriptOpBss_0033F540 */
static Fn gScriptOpBss_0033F540[0x190 / sizeof(Fn)];
#endif
extern Fn gMatrixFromData_001F21B0[];
void Script_OpCompare_1_00165DF0(void *o, Ctx *s);
s8 Script_Exec_2_00166170(Mgr *o, Slot *s);
void Script_FetchOperand_2_00165940(void *, Ctx *, u32 *, Val *);
void Script_OpArith_1_00165A30(Mgr *, Slot *);
void memset(void *, s32, s32);

/* Script_OpCompare_1_00165DF0 */
void Script_OpCompare_1_00165DF0(void *o, Ctx *s) {
    u8 res[32];
    Val a;
    Val b;
    u16 i;
    u32 w;
    s32 skip;
    s32 n;
    u8 mode;
    u8 op;
    u8 r;
    f32 fa;
    f32 fb;

    w = *s->pc;
    s->pc++;
    mode = w & 0xFF;
    skip = *s->pc;
    s->pc++;
    n = (u8)((w & 0xFF00) >> 8);
    for (i = 0; i < n; i++) {
        Script_FetchOperand_2_00165940(o, s, s->pc, &a);
        s->pc += 2;
        op = *(u8 *)s->pc;
        s->pc++;
        Script_FetchOperand_2_00165940(o, s, s->pc, &b);
        s->pc += 2;
        if (a.type == 6 || b.type == 6) {
            fa = a.v.f;
            fb = b.v.f;
            switch (op) {
            case 0: res[i] = fa == fb; break;
            case 1: res[i] = fa != fb; break;
            case 2: res[i] = fa > fb; break;
            case 3: res[i] = fa < fb; break;
            case 4: res[i] = fa >= fb; break;
            case 5: res[i] = fa <= fb; break;
            }
        } else {
            switch (op) {
            case 0: res[i] = a.v.i == b.v.i; break;
            case 1: res[i] = a.v.i != b.v.i; break;
            case 2: res[i] = a.v.i > b.v.i; break;
            case 3: res[i] = a.v.i < b.v.i; break;
            case 4: res[i] = a.v.i >= b.v.i; break;
            case 5: res[i] = a.v.i <= b.v.i; break;
            }
        }
    }
    if (n == 1) {
        r = res[0];
    } else {
        r = res[0];
        if (mode == 0) {
        for (i = 1; i < n; i++) {
            r = r || res[i];
        }
    } else {
        for (i = 1; i < n; i++) {
            r = r && res[i];
        }
    }
    }
    if (!r) {
        s->pc += skip;
    }
}

/* Script_Exec_2_00166170 */
#define Script_FetchOperand_2_00165940 Script_FetchOperand_2_00165940__as_Script_Exec_2_00166170
void Script_FetchOperand_2_00165940__as_Script_Exec_2_00166170(void *, Slot *, s32, Val *);
#define Script_OpCompare_1_00165DF0 Script_OpCompare_1_00165DF0__as_Script_Exec_2_00166170
void Script_OpCompare_1_00165DF0__as_Script_Exec_2_00166170(Mgr *, Slot *);
static inline s8 pop(Mgr *o, Slot *s) {
    if (s->f14 == 0) return -1;
    s->f14--;
    s->f8 = *o->base + s->ent[s->f14].b;
    s->f4 = s->ent[s->f14].a;
    s->fC = s->ent[s->f14].c;
    s->fE = s->ent[s->f14].d;
    return s->f14;
}
static inline void push(Mgr *o, Slot *s) {
    if (s->f14 != 16) {
        s->ent[s->f14].b = s->f8 - *o->base;
        s->ent[s->f14].a = s->f4;
        s->ent[s->f14].c = s->fC;
        s->ent[s->f14].d = s->fE;
        s->f14++;
        s->f8 = 0;
    }
}
static inline void jmp(Slot *s, u16 n) {
    s->f8 += 4;
    s->f8 += (s16)n * 4;
}
static inline void getArgs(Mgr *o, Slot *s, Cmd *c, u16 op, u16 n) {
    u16 i;
    c->op = op;
    s->f8 += 4;
    for (i = 0; i < n; i++) {
        Script_FetchOperand_2_00165940(o, s, s->f8, &c->args[i]);
        s->f8 += 8;
    }
    memset(c->m, 0, 0x10);
}

s8 Script_Exec_2_00166170(Mgr *o, Slot *s) {
    s8 ret;
    u16 run;
    u32 w;
    u32 op;
    u32 arg;
    s32 p;
    s32 i;

    run = 1;
    ret = 0;
    if (pop(o, s) == -1) {
        ret = 0;
        run = 0;
    }
    while (run) {
        p = s->f8;
        w = *(u32 *)p;
        op = (w & 0xFFFF0000) >> 16;
        arg = w & 0xFFFF;
        switch (op) {
        case 0x190:
            s->f8 += 4;
            break;
        case 0x191:
            if (pop(o, s) == -1) {
                ret = 0;
                run = 0;
            }
            break;
        case 0x194:
            s->f8 += 4;
            break;
        case 0x195:
            s->f8 += 4;
            ret = 1;
            s->f10 = 0;
            run = 0;
            push(o, s);
            break;
        case 0x192:
            Script_OpCompare_1_00165DF0(o, s);
            break;
        case 0x197:
            jmp(s, arg);
            break;
        case 0x196:
            Script_OpArith_1_00165A30(o, s);
            break;
        case 0x19D:
            p += 8;
            for (i = 0; i < (s32)arg; i++) {
                p += 4;
            }
            s->f8 = p;
            break;
        case 1: {
            Cmd c;
            getArgs(o, s, &c, op, arg);
            s->f10 = c.args[0].v.i;
            ret = 1;
            run = 0;
            push(o, s);
            break;
        }
        case 2: {
            Cmd c;
            getArgs(o, s, &c, op, arg);
            push(o, s);
            s->f4 = Script_FindLabel_1_00166970(o, *(u16 *)&c.args[0].v);
            if (s->f4 == -1) return 0;
            s->f8 = *o->base + s->f4;
            s->fC += s->fE;
            s->fE = 0;
            break;
        }
        case 7:
            ret = 0;
            run = 0;
            break;
        default: {
            Cmd c;
            getArgs(o, s, &c, op, arg);
            if (c.op != 0 && !(c.op & 0x8000)) {
                if (c.op >= 300) {
                    gScriptOpData_001F2400[c.op - 300](&c);
                } else if (c.op >= 200) {
                    gScriptOpData_001F1CD0[c.op - 200](&c);
                } else if (c.op >= 100) {
                    gScriptOpBss_0033F540[c.op - 100](&c);
                } else {
                    gMatrixFromData_001F21B0[c.op](&c);
                }
            }
            break;
        }
        }
    }
    return ret;
}
#undef Script_FetchOperand_2_00165940
#undef Script_OpCompare_1_00165DF0

#ifdef NONMATCHING
#pragma explicit_zero_data on
void EnemyCmd_AddHp_2_00145190(void);
void EnemyCmd_AddPartValue_0_001451E0(void);
void EnemyCmd_BreakPart_1_00144E10(void);
void EnemyCmd_BroadcastFrame_1_00144D80(void);
void EnemyCmd_BroadcastMotion_1_001442F0(void);
void EnemyCmd_ClampHpFromFlag_1_00144420(void);
void EnemyCmd_FindSpawnPoint_0_001444F0(void);
void EnemyCmd_Get5B0b0_1_001451A0(void);
void EnemyCmd_Get608_1_00143B20(void);
void EnemyCmd_GetFlag_0_001438B0(void);
void EnemyCmd_GetGlobal_0_001438F0(void);
void EnemyCmd_GetHpPercent_2_00145250(void);
void EnemyCmd_GetModelPos_0_00145410(void);
void EnemyCmd_GetMotionFrame_1_00143C30(void);
void EnemyCmd_GetParamIdx_1_00144F60(void);
void EnemyCmd_GetPlayerValue_0_00143B60(void);
void EnemyCmd_GetPosition_2_00144970(void);
void EnemyCmd_GetRelativePos_0_00143960(void);
void EnemyCmd_GetTargetPos_0_001441B0(void);
void EnemyCmd_GetType_1_00145140(void);
void EnemyCmd_GetVec660_0_00143D60(void);
void EnemyCmd_HealPercent_1_00144E40(void);
void EnemyCmd_InitPart_1_00143E10(void);
void EnemyCmd_KillNow_1_001450F0(void);
void EnemyCmd_Kill_1_00144360(void);
void EnemyCmd_LoadPart_1_00143E00(void);
void EnemyCmd_Nop_1_00143890(void);
void EnemyCmd_PlaySe_1_001453A0(void);
void EnemyCmd_Random_2_00145100(void);
void EnemyCmd_RegisterKill_0_00144FC0(void);
void EnemyCmd_RegisterSeen_0_00145010(void);
void EnemyCmd_ResetState_1_00144D50(void);
void EnemyCmd_ResetVectors_1_00145610(void);
void EnemyCmd_ResolveHit_0_00143C70(void);
void EnemyCmd_ReturnToTitle_1_001443D0(void);
void EnemyCmd_SelectMotionB_1_001452A0(void);
void EnemyCmd_SelectMotion_1_00143B90(void);
void EnemyCmd_Set5A1b5_1_00143BB0(void);
void EnemyCmd_Set5B0b0_1_00144E30(void);
void EnemyCmd_Set5B0b1_1_00145180(void);
void EnemyCmd_Set5B0b2_1_00144410(void);
void EnemyCmd_Set5B0b7_1_001450E0(void);
void EnemyCmd_Set5B1b0_1_00145060(void);
void EnemyCmd_Set5B1b1_1_00144FA0(void);
void EnemyCmd_Set5B1b2Notify_0_00144F00(void);
void EnemyCmd_Set5B1b3_1_00144EF0(void);
void EnemyCmd_Set5B1b4_1_001444E0(void);
void EnemyCmd_Set5B1b5_1_00144EE0(void);
void EnemyCmd_Set5B1b6_1_00144E00(void);
void EnemyCmd_Set5B1b7_1_00144DF0(void);
void EnemyCmd_Set5B2b0_1_00144D70(void);
void EnemyCmd_Set5B2b1_1_00144400(void);
void EnemyCmd_Set5B2b2_1_001443F0(void);
void EnemyCmd_Set5B2b4_1_00144960(void);
void EnemyCmd_Set5B2b6w2_1_001443E0(void);
void EnemyCmd_Set5B3b3_1_00144D60(void);
void EnemyCmd_Set5B4b4_1_00143BC0(void);
void EnemyCmd_Set5B4b5_1_00143930(void);
void EnemyCmd_Set5B4b6_1_00143920(void);
void EnemyCmd_Set5B5b7_1_001438A0(void);
void EnemyCmd_Set5B8_1_00143940(void);
void EnemyCmd_Set609_1_001452C0(void);
void EnemyCmd_Set60B_1_00143950(void);
void EnemyCmd_SetDead_1_001450D0(void);
void EnemyCmd_SetGameFlag_2_00145070(void);
void EnemyCmd_SetHiddenFlags_0_00144370(void);
void EnemyCmd_SetMapObjFlag_0_001452E0(void);
void EnemyCmd_SetMode_1_00145290(void);
void EnemyCmd_SetPartValue_1_00143D10(void);
void EnemyCmd_ShakeCamera_0_001455B0(void);
void EnemyCmd_SpawnEffectB_0_00144BE0(void);
void EnemyCmd_SpawnEffect_0_00144A00(void);
void EnemyCmd_SpawnItem_0_001454E0(void);
void EnemyCmd_StartTimer_0_00143BD0(void);
void EnemyCmd_StopEffect_0_00144B80(void);
void EnemyCmd_StoreHpToFlag_1_00144490(void);
void EnemyCmd_TestGameFlag_2_00145080(void);
void EnemyCmd_UpdateParamFlags_1_00144FB0(void);
void EnemyCmd_UpdatePartStat_1_00143DF0(void);
/* data group (src/game/data/fx_proc_data.c): D_001F1CD0__grp: gScriptOpData_001F1CD0@0x0 */
s32 D_001F1CD0__grp[0x64] __attribute__((aligned(16))) = { (s32)EnemyCmd_ResetVectors_1_00145610, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_ShakeCamera_0_001455B0, (s32)EnemyCmd_SpawnItem_0_001454E0, (s32)EnemyCmd_GetModelPos_0_00145410, (s32)EnemyCmd_PlaySe_1_001453A0, (s32)EnemyCmd_SetMapObjFlag_0_001452E0, (s32)EnemyCmd_Set609_1_001452C0, (s32)EnemyCmd_SelectMotionB_1_001452A0, (s32)EnemyCmd_SetMode_1_00145290, (s32)EnemyCmd_GetHpPercent_2_00145250, (s32)EnemyCmd_AddPartValue_0_001451E0, (s32)EnemyCmd_Get5B0b0_1_001451A0, (s32)EnemyCmd_AddHp_2_00145190, (s32)EnemyCmd_Set5B0b1_1_00145180, (s32)EnemyCmd_GetType_1_00145140, (s32)EnemyCmd_Random_2_00145100, (s32)EnemyCmd_KillNow_1_001450F0, (s32)EnemyCmd_Set5B0b7_1_001450E0, (s32)EnemyCmd_SetDead_1_001450D0, (s32)EnemyCmd_TestGameFlag_2_00145080, (s32)EnemyCmd_SetGameFlag_2_00145070, (s32)EnemyCmd_Set5B1b0_1_00145060, (s32)EnemyCmd_RegisterSeen_0_00145010, (s32)EnemyCmd_RegisterKill_0_00144FC0, (s32)EnemyCmd_UpdateParamFlags_1_00144FB0, (s32)EnemyCmd_Set5B1b1_1_00144FA0, (s32)EnemyCmd_GetParamIdx_1_00144F60, (s32)EnemyCmd_Set5B1b2Notify_0_00144F00, (s32)EnemyCmd_Set5B1b3_1_00144EF0, (s32)EnemyCmd_Set5B1b5_1_00144EE0, (s32)EnemyCmd_HealPercent_1_00144E40, (s32)EnemyCmd_Set5B0b0_1_00144E30, (s32)EnemyCmd_BreakPart_1_00144E10, (s32)EnemyCmd_Set5B1b6_1_00144E00, (s32)EnemyCmd_Set5B1b7_1_00144DF0, (s32)EnemyCmd_BroadcastFrame_1_00144D80, (s32)EnemyCmd_Set5B2b0_1_00144D70, (s32)EnemyCmd_Set5B3b3_1_00144D60, (s32)EnemyCmd_ResetState_1_00144D50, (s32)EnemyCmd_SpawnEffectB_0_00144BE0, (s32)EnemyCmd_StopEffect_0_00144B80, (s32)EnemyCmd_SpawnEffect_0_00144A00, (s32)EnemyCmd_GetPosition_2_00144970, (s32)EnemyCmd_Set5B2b4_1_00144960, (s32)EnemyCmd_FindSpawnPoint_0_001444F0, (s32)EnemyCmd_Set5B1b4_1_001444E0, (s32)EnemyCmd_StoreHpToFlag_1_00144490, (s32)EnemyCmd_ClampHpFromFlag_1_00144420, (s32)EnemyCmd_Set5B0b2_1_00144410, (s32)EnemyCmd_Set5B2b1_1_00144400, (s32)EnemyCmd_Set5B2b2_1_001443F0, (s32)EnemyCmd_Set5B2b6w2_1_001443E0, (s32)EnemyCmd_ReturnToTitle_1_001443D0, (s32)EnemyCmd_SetHiddenFlags_0_00144370, (s32)EnemyCmd_Kill_1_00144360, (s32)EnemyCmd_BroadcastMotion_1_001442F0, (s32)EnemyCmd_GetTargetPos_0_001441B0, (s32)EnemyCmd_InitPart_1_00143E10, (s32)EnemyCmd_LoadPart_1_00143E00, (s32)EnemyCmd_UpdatePartStat_1_00143DF0, (s32)EnemyCmd_GetVec660_0_00143D60, (s32)EnemyCmd_SetPartValue_1_00143D10, (s32)EnemyCmd_ResolveHit_0_00143C70, (s32)EnemyCmd_GetMotionFrame_1_00143C30, (s32)EnemyCmd_StartTimer_0_00143BD0, (s32)EnemyCmd_Set5B4b4_1_00143BC0, (s32)EnemyCmd_Set5A1b5_1_00143BB0, (s32)EnemyCmd_SelectMotion_1_00143B90, (s32)EnemyCmd_GetPlayerValue_0_00143B60, (s32)EnemyCmd_Get608_1_00143B20, (s32)EnemyCmd_GetRelativePos_0_00143960, (s32)EnemyCmd_Set60B_1_00143950, (s32)EnemyCmd_Set5B8_1_00143940, (s32)EnemyCmd_Set5B4b5_1_00143930, (s32)EnemyCmd_Set5B4b6_1_00143920, (s32)EnemyCmd_GetGlobal_0_001438F0, (s32)EnemyCmd_GetFlag_0_001438B0, (s32)EnemyCmd_Set5B5b7_1_001438A0, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890, (s32)EnemyCmd_Nop_1_00143890 };
void MapCmd_AddItem_0_0017CE70(void);
void MapCmd_CopyVar_0_0017D1C0(void);
void MapCmd_FadeLight_0_0017C6F0(void);
void MapCmd_FadeTo_1_0017A650(void);
void MapCmd_GetCameraState_0_0017C4B0(void);
void MapCmd_GetDistToObject_0_0017D000(void);
void MapCmd_GetDoorState_0_0017B730(void);
void MapCmd_GetEffectState_0_0017D170(void);
void MapCmd_GetEnemyPosition_1_0017C620(void);
void MapCmd_GetEnemyRotation_1_0017C540(void);
void MapCmd_GetEquip_0_0017D130(void);
void MapCmd_GetFlagWord_0_0017A890(void);
void MapCmd_GetGlobal_0_0017D930(void);
void MapCmd_GetGlow_0_0017AF20(void);
void MapCmd_GetItemName_0_0017ECD0(void);
void MapCmd_GetLight_0_0017ABD0(void);
void MapCmd_GetNodePos_0_0017DA60(void);
void MapCmd_GetObjectAnim_0_0017DEC0(void);
void MapCmd_GetObjectFlag_0_0017DD90(void);
void MapCmd_GetObjectName_0_0017ED20(void);
void MapCmd_GetObjectState_0_0017B5A0(void);
void MapCmd_GetObjectVarB_0_0017DCD0(void);
void MapCmd_GetObjectVar_0_0017DC70(void);
void MapCmd_GetPlayerFlag_0_0017D0E0(void);
void MapCmd_GetPlayerPosB_0_0017D350(void);
void MapCmd_GetPlayerPos_1_0017CE80(void);
void MapCmd_GetPlayerRot_1_0017D240(void);
void MapCmd_GetPlayerStat2_0_0017CD10(void);
void MapCmd_GetPlayerStat_0_0017AA40(void);
void MapCmd_GetPlayerVarB_0_0017D300(void);
void MapCmd_GetPlayerVar_0_0017CC90(void);
void MapCmd_GetSfxParamA_0_0017E760(void);
void MapCmd_GetSfxParamB_0_0017EAF0(void);
void MapCmd_GetSfxState_0_0017E260(void);
void MapCmd_GetTimer_0_0017C270(void);
void MapCmd_GetValue_0_0017B7A0(void);
void MapCmd_GetWeather_0_0017CBA0(void);
void MapCmd_HideObject_0_0017B8A0(void);
void MapCmd_IsBusy_0_0017CA10(void);
void MapCmd_MoveObject_0_0017B0F0(void);
void MapCmd_NopA_2_0017ABB0(void);
void MapCmd_NopB_2_0017ABC0(void);
void MapCmd_NopC_2_0017EDB0(void);
void MapCmd_NotifyEnemies_0_0017A790(void);
void MapCmd_PlayBgm_0_0017E050(void);
void MapCmd_PlayObjectAnim_0_0017DE40(void);
void MapCmd_PlaySeAtXYZ_1_0017BC00(void);
void MapCmd_PlaySeAt_1_0017BA50(void);
void MapCmd_PlaySeOnObjectB_0_0017BC50(void);
void MapCmd_PlaySeOnObject_0_0017BAC0(void);
void MapCmd_QueryEnemies_0_0017E220(void);
void MapCmd_Random_2_0017CB50(void);
void MapCmd_RemoveItem_0_0017CE60(void);
void MapCmd_RequestEvent_0_0017C890(void);
void MapCmd_ResetObjects_0_0017C930(void);
void MapCmd_RotateNodeRel_0_0017D6E0(void);
void MapCmd_RotateNode_0_0017D5B0(void);
void MapCmd_RotateObject_0_0017B410(void);
void MapCmd_SetCameraPath_0_0017C490(void);
void MapCmd_SetCameraTarget_0_0017DB40(void);
void MapCmd_SetDoor_0_0017B780(void);
void MapCmd_SetEffectPos_0_0017CAC0(void);
void MapCmd_SetFlag2034_0_0017A640(void);
void MapCmd_SetFlagBits_0_0017A920(void);
void MapCmd_SetFloat_0_0017CA60(void);
void MapCmd_SetGlow_0_0017B060(void);
void MapCmd_SetItemFlag_0_0017CC80(void);
void MapCmd_SetLightPos_0_0017DC00(void);
void MapCmd_SetLight_0_0017ADE0(void);
void MapCmd_SetMapVar_0_0017A850(void);
void MapCmd_SetObjParam_0_0017C6D0(void);
void MapCmd_SetObjectAlpha_0_0017D3D0(void);
void MapCmd_SetObjectAnimB_0_0017DEA0(void);
void MapCmd_SetObjectAnimC_0_0017DEB0(void);
void MapCmd_SetObjectAnim_0_0017C150(void);
void MapCmd_SetObjectFlag_0_0017DD10(void);
void MapCmd_SetObjectNode_0_0017B9E0(void);
void MapCmd_SetObjectsAlpha_0_0017D480(void);
void MapCmd_SetPlayerFlags_0_0017CD50(void);
void MapCmd_SetPlayerPosVec_0_0017CFB0(void);
void MapCmd_SetPlayerPos_1_0017CF40(void);
void MapCmd_SetPlayerVar3_0_0017CD00(void);
void MapCmd_SetPlayerVar4_0_0017CCE0(void);
void MapCmd_SetSfxParamA_0_0017E5B0(void);
void MapCmd_SetSfxParamB_0_0017E940(void);
void MapCmd_SetSfxTransform_0_0017E390(void);
void MapCmd_SetSfx_0_0017E370(void);
void MapCmd_SetTexScroll_1_0017CAA0(void);
void MapCmd_ShowObject_0_0017B800(void);
void MapCmd_SpawnItem_0_0017DF20(void);
void MapCmd_SpawnSfxOnObjectB_0_0017BF50(void);
void MapCmd_SpawnSfxOnObject_0_0017BD70(void);
void MapCmd_StartStream_0_0017BA30(void);
void MapCmd_StopObject_0_0017B4D0(void);
void MapCmd_StopSe_1_0017BA40(void);
void MapCmd_TranslateNodeRel_0_0017D960(void);
void MapCmd_TranslateNode_0_0017D810(void);
void MapCmd_Vibrate_1_0017DB60(void);
void MapCmd_WaitEvent_0_0017C2A0(void);
void MapCmd_WarpPlayer_0_0017CE20(void);
/* data group (src/game/data/screen_fx_flash_data_001F2340.c): D_001F2400__grp: gScriptOpData_001F2400@0x0 */
s32 D_001F2400__grp[0x64] __attribute__((aligned(16))) = { (s32)MapCmd_GetObjectName_0_0017ED20, (s32)MapCmd_GetItemName_0_0017ECD0, (s32)MapCmd_GetSfxParamB_0_0017EAF0, (s32)MapCmd_SetSfxParamB_0_0017E940, (s32)MapCmd_SetSfxParamA_0_0017E5B0, (s32)MapCmd_SetSfxTransform_0_0017E390, (s32)MapCmd_GetSfxState_0_0017E260, (s32)MapCmd_SetSfx_0_0017E370, (s32)MapCmd_GetSfxParamA_0_0017E760, (s32)MapCmd_QueryEnemies_0_0017E220, (s32)MapCmd_PlayBgm_0_0017E050, (s32)MapCmd_GetObjectAnim_0_0017DEC0, (s32)MapCmd_SetObjectAnimC_0_0017DEB0, (s32)MapCmd_SetObjectAnimB_0_0017DEA0, (s32)MapCmd_PlayObjectAnim_0_0017DE40, (s32)MapCmd_GetObjectFlag_0_0017DD90, (s32)MapCmd_SetObjectFlag_0_0017DD10, (s32)MapCmd_GetObjectVarB_0_0017DCD0, (s32)MapCmd_GetObjectVar_0_0017DC70, (s32)MapCmd_SetLightPos_0_0017DC00, (s32)MapCmd_Vibrate_1_0017DB60, (s32)MapCmd_SetCameraTarget_0_0017DB40, (s32)MapCmd_GetNodePos_0_0017DA60, (s32)MapCmd_TranslateNodeRel_0_0017D960, (s32)MapCmd_GetGlobal_0_0017D930, (s32)MapCmd_TranslateNode_0_0017D810, (s32)MapCmd_RotateNodeRel_0_0017D6E0, (s32)MapCmd_RotateNode_0_0017D5B0, (s32)MapCmd_SetObjectsAlpha_0_0017D480, (s32)MapCmd_SetObjectAlpha_0_0017D3D0, (s32)MapCmd_GetPlayerPosB_0_0017D350, (s32)MapCmd_GetPlayerVarB_0_0017D300, (s32)MapCmd_GetPlayerRot_1_0017D240, (s32)MapCmd_CopyVar_0_0017D1C0, (s32)MapCmd_GetEffectState_0_0017D170, (s32)MapCmd_GetEquip_0_0017D130, (s32)MapCmd_GetPlayerFlag_0_0017D0E0, (s32)MapCmd_GetDistToObject_0_0017D000, (s32)MapCmd_SetPlayerPosVec_0_0017CFB0, (s32)MapCmd_SetPlayerPos_1_0017CF40, (s32)MapCmd_NopC_2_0017EDB0, (s32)MapCmd_GetPlayerPos_1_0017CE80, (s32)MapCmd_AddItem_0_0017CE70, (s32)MapCmd_RemoveItem_0_0017CE60, (s32)MapCmd_WarpPlayer_0_0017CE20, (s32)MapCmd_SetPlayerFlags_0_0017CD50, (s32)MapCmd_GetPlayerStat2_0_0017CD10, (s32)MapCmd_SetPlayerVar3_0_0017CD00, (s32)MapCmd_SetPlayerVar4_0_0017CCE0, (s32)MapCmd_GetPlayerVar_0_0017CC90, (s32)MapCmd_SetItemFlag_0_0017CC80, (s32)MapCmd_GetWeather_0_0017CBA0, (s32)MapCmd_Random_2_0017CB50, (s32)MapCmd_SetEffectPos_0_0017CAC0, (s32)MapCmd_SetTexScroll_1_0017CAA0, (s32)MapCmd_SetFloat_0_0017CA60, (s32)MapCmd_IsBusy_0_0017CA10, (s32)MapCmd_ResetObjects_0_0017C930, (s32)MapCmd_RequestEvent_0_0017C890, (s32)MapCmd_FadeLight_0_0017C6F0, (s32)MapCmd_SetObjParam_0_0017C6D0, (s32)MapCmd_GetEnemyPosition_1_0017C620, (s32)MapCmd_GetEnemyRotation_1_0017C540, (s32)MapCmd_GetCameraState_0_0017C4B0, (s32)MapCmd_SetCameraPath_0_0017C490, (s32)MapCmd_WaitEvent_0_0017C2A0, (s32)MapCmd_GetTimer_0_0017C270, (s32)MapCmd_SetObjectAnim_0_0017C150, (s32)MapCmd_SpawnSfxOnObjectB_0_0017BF50, (s32)MapCmd_SpawnSfxOnObject_0_0017BD70, (s32)MapCmd_PlaySeOnObjectB_0_0017BC50, (s32)MapCmd_PlaySeAtXYZ_1_0017BC00, (s32)MapCmd_PlaySeOnObject_0_0017BAC0, (s32)MapCmd_PlaySeAt_1_0017BA50, (s32)MapCmd_StopSe_1_0017BA40, (s32)MapCmd_StartStream_0_0017BA30, (s32)MapCmd_SetObjectNode_0_0017B9E0, (s32)MapCmd_HideObject_0_0017B8A0, (s32)MapCmd_ShowObject_0_0017B800, (s32)MapCmd_GetValue_0_0017B7A0, (s32)MapCmd_SetDoor_0_0017B780, (s32)MapCmd_GetDoorState_0_0017B730, (s32)MapCmd_RotateObject_0_0017B410, (s32)MapCmd_MoveObject_0_0017B0F0, (s32)MapCmd_SetGlow_0_0017B060, (s32)MapCmd_GetGlow_0_0017AF20, (s32)MapCmd_SetLight_0_0017ADE0, (s32)MapCmd_GetLight_0_0017ABD0, (s32)MapCmd_NopB_2_0017ABC0, (s32)MapCmd_NopA_2_0017ABB0, (s32)MapCmd_GetObjectState_0_0017B5A0, (s32)MapCmd_StopObject_0_0017B4D0, (s32)MapCmd_GetPlayerStat_0_0017AA40, (s32)MapCmd_SpawnItem_0_0017DF20, (s32)MapCmd_SetFlagBits_0_0017A920, (s32)MapCmd_GetFlagWord_0_0017A890, (s32)MapCmd_SetMapVar_0_0017A850, (s32)MapCmd_NotifyEnemies_0_0017A790, (s32)MapCmd_FadeTo_1_0017A650, (s32)MapCmd_SetFlag2034_0_0017A640 };
#endif
