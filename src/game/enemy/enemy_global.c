#include "common.h"
#include "m2c.h"
typedef struct { u8 b0 : 3; u8 b3 : 1; u8 b4 : 4; } F;
typedef struct { char p[0x290]; f32 x290; } Q;
typedef struct { char p[0x4B0]; Q *q; char p2[0x5BC - 0x4B4]; f32 x5BC; f32 x5C0; char p3[0x10]; f32 x5D4; } A;
typedef struct { u8 pad[0x294]; f32 x294; } Sub;
typedef struct {
    u8 pad[0x4B0]; Sub *x4B0; u8 p4B4[0x100]; Flags8 f5B4; u8 p5B5[0x1F]; f32 x5D4; f32 x5D8;
} O;
extern s8 gEnemyGlobalSbss_00201F1C;
extern s8 gEnemyGlobalSbss_00201F18;
extern F D_00222A53[];
void Enemy_SetGlobalFlagF1C_0_0013D680(s8 arg0);
u8 Enemy_GetGlobalFlagF1C_0_0013D690(void);
void Enemy_SetAiDisabled_0_0013D6A0(s8 arg0);
u8 Enemy_IsAiDisabled_0_0013D6B0(void);
f32 Enemy_CalcSpeedScale_0_0013D6C0(A *a);
void Enemy_UpdateFade_0_0013D760(O *o, f32 dt);
s32 EnemyScr_Event2020_1_00140EF0(O *);

/* Enemy_SetGlobalFlagF1C_0_0013D680 */
void Enemy_SetGlobalFlagF1C_0_0013D680(s8 arg0) {
    gEnemyGlobalSbss_00201F1C = arg0;
}

/* Enemy_GetGlobalFlagF1C_0_0013D690 */
#define gEnemyGlobalSbss_00201F1C gEnemyGlobalSbss_00201F1C__as_Enemy_GetGlobalFlagF1C_0_0013D690
extern u8 gEnemyGlobalSbss_00201F1C__as_Enemy_GetGlobalFlagF1C_0_0013D690;

u8 Enemy_GetGlobalFlagF1C_0_0013D690(void) {
    return gEnemyGlobalSbss_00201F1C;
}
#undef gEnemyGlobalSbss_00201F1C

/* Enemy_SetAiDisabled_0_0013D6A0 */
void Enemy_SetAiDisabled_0_0013D6A0(s8 arg0) {
    gEnemyGlobalSbss_00201F18 = arg0;
}

/* Enemy_IsAiDisabled_0_0013D6B0 */
#define gEnemyGlobalSbss_00201F18 gEnemyGlobalSbss_00201F18__as_Enemy_IsAiDisabled_0_0013D6B0
extern u8 gEnemyGlobalSbss_00201F18__as_Enemy_IsAiDisabled_0_0013D6B0;

u8 Enemy_IsAiDisabled_0_0013D6B0(void) {
    return gEnemyGlobalSbss_00201F18;
}
#undef gEnemyGlobalSbss_00201F18

/* Enemy_CalcSpeedScale_0_0013D6C0 */
f32 Enemy_CalcSpeedScale_0_0013D6C0(A *a) {
    f32 r;
    if (D_00222A53[0].b3) {
        r = (1.0f - (1.0f - a->q->x290) * (1.0f - a->x5D4)) * (a->x5BC * a->x5C0);
    } else {
        r = a->x5BC * a->x5C0;
    }
    if (r > 1.0f) r = 1.0f;
    if (r < 0.0f) r = 0.0f;
    return r;
}

/* Enemy_UpdateFade_0_0013D760 */
void Enemy_UpdateFade_0_0013D760(O *o, f32 dt) {
    f32 v;
    f32 t;
    f32 d;

    t = o->x5D8;
    v = o->x5D4;
    if (t > dt) t -= dt; else t = 0.0f;
    o->x5D8 = t;
    if (t > 0.0f) {
        v = 1.0f;
    } else if (o->f5B4.f.b6 || o->f5B4.f.b7 || !(u8)EnemyScr_Event2020_1_00140EF0(o)) {
        v += dt / 1.5f;
        if (v > 1.0f) v = 1.0f;
    } else {
        d = o->x4B0->x294;
        if (d == 0.0f) {
            v = 0.0f;
        } else {
            v -= dt / d;
            if (v < 0.0f) v = 0.0f;
        }
    }
    o->x5D4 = v;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gEnemyGlobalSbss_00201F18, gEnemyGlobalSbss_00201F1C */
s8 gEnemyGlobalSbss_00201F18;
s8 gEnemyGlobalSbss_00201F1C;
#endif
