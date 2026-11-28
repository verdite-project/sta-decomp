#include "actor.h"
#include "game/enemy.h"
#include "game/core.h"
typedef struct { u8 lo:2; u8 rest:6; } B2;
typedef struct { u8 pad[0x5B3]; B2 f; } A5;
s32 Game_GetBusy_0_0012C020(void);
Actor *ActorList_Next_2_001A5460(s32 *);
void ActorList_SetCount_1_001A5440(Actor *);
void Enemy_UpdateModelMatrix_0_001A7E60(Actor *);
s32 Enemy_Get5B1b2_1_0013EA40(Actor *);
void EnemyScr_Event2018_1_001411F0(Actor *);
void Enemy_SetGlobalFlagF1C_0_0013D680(s32);
s32 Enemy_GetGlobalFlagF1C_0_0013D690(void);
void Enemy_SetAiDisabled_0_0013D6A0(s32);
s32 Enemy_Ptr700_1_0013FF90(Actor *);
void Camera_SetPosition_0_001C8EA0(s32, f32);
u64 Player_IsActionLocked_0_001C9AE0(void);
s32 Ent_IsNull0_1_0013EE30(Actor *);
void Enemy_UpdateTimers_0_0013D8A0(Actor *, f32);
void Enemy_UpdateFade_0_0013D760(Actor *, f32);
void Enemy_UpdateLerp_0_0013DA90(Actor *, f32);
void Enemy_Set5B4b2_1_0013E640(Actor *, s32);
s32 Enemy_CheckReachable_0_0013F8E0(Actor *);
void Enemy_Set5B6b5_1_0013F8C0(Actor *, s32);
u8 Enemy_Get5B6b5_1_0013F8B0(Actor *);
void Actor_UpdateTransform_0_0013B4F0(Actor *, f32, s32);
void Actor_UpdateCollision_0_0013B220(Actor *, f32, s32);
void Mdl_ResetBones_0_00171610(s32);
void sceVu0CopyVector(s32, s8 *);
#ifndef NONMATCHING
extern u8 D_00201F14;
#else
/* data twins (src/game/data/sbss.c): D_00201F14 */
static u8 D_00201F14;
#endif

void Actors_UpdateAll_1_0013BBC0(f32 dt) {
    s32 it1;
    s32 it3;
    s32 it4;
    s32 it5;
    s32 it6;
    s32 it7;
    s32 it2;
    Actor *sel;
    u8 flag;
    Actor *o;
    u8 cnt;

    flag = Game_GetBusy_0_0012C020();
    it1 = 0;
    o = ActorList_Next_2_001A5460(&it1);
    if (o != NULL) {
        do {
            ActorList_SetCount_1_001A5440(o);
            Enemy_UpdateModelMatrix_0_001A7E60(o);
            o = ActorList_Next_2_001A5460(&it1);
        } while (o != NULL);
    }
    it2 = 0;
    sel = NULL;
    o = ActorList_Next_2_001A5460(&it2);
    if (o != NULL) {
        do {
            ActorList_SetCount_1_001A5440(o);
            if (!Enemy_Get5B1b2_1_0013EA40(o) == 0) {
                EnemyScr_Event2018_1_001411F0(o);
                sel = o;
                break;
            }
            o = ActorList_Next_2_001A5460(&it2);
        } while (o != NULL);
    }
    if (sel != NULL) {
        Enemy_SetGlobalFlagF1C_0_0013D680(1);
        flag = 1;
        Game_SetBusy_1_0012C030(1);
        Camera_SetPosition_0_001C8EA0(Enemy_Ptr700_1_0013FF90(sel), 0.9f);
    } else if (Enemy_GetGlobalFlagF1C_0_0013D690()) {
        flag = 0;
        Game_SetBusy_1_0012C030(0);
        Enemy_SetGlobalFlagF1C_0_0013D680(0);
    }
    if (flag || Player_IsActionLocked_0_001C9AE0()) {
        Enemy_SetAiDisabled_0_0013D6A0(1);
    } else {
        Enemy_SetAiDisabled_0_0013D6A0(0);
    }
    if (sel != NULL || (!flag && !Player_IsActionLocked_0_001C9AE0())) {
        it3 = 0;
        cnt = 0;
        o = ActorList_Next_2_001A5460(&it3);
        if (sel != NULL) o = sel;
        while (o != NULL) {
            ActorList_SetCount_1_001A5440(o);
            if (!Ent_IsNull0_1_0013EE30(o)) {
                Enemy_UpdateDeath_0_0013DB80(o, dt);
                Enemy_UpdateTimer5C0_0_0013DB10(o, dt);
                Enemy_UpdateBlend5CC_0_0013DA20(o, dt);
                Enemy_UpdateTimers_0_0013D8A0(o, dt);
                Enemy_UpdateFade_0_0013D760(o, dt);
                Enemy_UpdateLerp_0_0013DA90(o, dt);
                if (D_00201F14 == cnt % 8) {
                    Enemy_Set5B4b2_1_0013E640(o, 1);
                } else {
                    Enemy_Set5B4b2_1_0013E640(o, 0);
                }
                Enemy_Set5B6b5_1_0013F8C0(o, Enemy_CheckReachable_0_0013F8E0(o));
            }
            cnt++;
            o = ActorList_Next_2_001A5460(&it3);
            if (sel != NULL) break;
        }
        D_00201F14++;
        if (D_00201F14 >= 8) {
            D_00201F14 = 0;
        }
    }
    if (flag || Player_IsActionLocked_0_001C9AE0()) {
        it4 = 0;
        o = ActorList_Next_2_001A5460(&it4);
        if (o != NULL) {
            do {
                ActorList_SetCount_1_001A5440(o);
                if (Ent_IsNull0_1_0013EE30(o) || o == sel) {
                    Actor_UpdateTransform_0_0013B4F0(o, dt, 0);
                } else if (!Ent_IsNull0_1_0013EE30(o)) {
                    Mdl_ResetBones_0_00171610(*(s32 *)(o->unk518 + 0x1A4));
                }
                o = ActorList_Next_2_001A5460(&it4);
            } while (o != NULL);
        }
    } else {
        Actor *p;
        s32 k;
        it5 = 0;
        p = ActorList_Next_2_001A5460(&it5);
        if (p != NULL) {
            do {
                k = Enemy_Get5B6b5_1_0013F8B0(p);
                ActorList_SetCount_1_001A5440(p);
                Actor_UpdateTransform_0_0013B4F0(p, dt, k);
                p = ActorList_Next_2_001A5460(&it5);
            } while (p != NULL);
        }
    }
    if (flag || Player_IsActionLocked_0_001C9AE0()) {
        it6 = 0;
        o = ActorList_Next_2_001A5460(&it6);
        if (o != NULL) {
            do {
                ActorList_SetCount_1_001A5440(o);
                if (Ent_IsNull0_1_0013EE30(o) || o == sel) {
                    Actor_UpdateCollision_0_0013B220(o, dt, 0);
                } else {
                    s8 *s = o->unk518 + 0x180;
                    if (!Ent_IsNull0_1_0013EE30(o)) {
                        sceVu0CopyVector(*(s32 *)(s + 0x18), s + 0x40);
                        sceVu0CopyVector(*(s32 *)(s + 0x18) + 0x40, s + 0x50);
                    }
                }
                o = ActorList_Next_2_001A5460(&it6);
            } while (o != NULL);
        }
    } else {
        s32 k;
        it7 = 0;
        o = ActorList_Next_2_001A5460(&it7);
        if (o != NULL) {
            do {
                k = Enemy_Get5B6b5_1_0013F8B0(o);
                ActorList_SetCount_1_001A5440(o);
                Actor_UpdateCollision_0_0013B220(o, dt, k);
                if ((u8)k == 0) {
                    { A5 *a = (A5 *)o; if (a->f.lo < 3) a->f.lo = a->f.lo + 1; }
                }
                o = ActorList_Next_2_001A5460(&it7);
            } while (o != NULL);
        }
    }
}
