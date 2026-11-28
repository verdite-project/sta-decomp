#include "m2c.h"
#include "common.h"
#include "actor.h"
typedef struct { u8 pad[0x613]; u8 b613; f32 f614; u8 pad2[0xA9]; u8 b6C1; } Obj613;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:3; u8 b6:1; u8 b7:1; } F0;
typedef Bits8 F1;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:2; } F2;
typedef struct { u8 b0:2; u8 b2:1; u8 b3:1; u8 b4:2; u8 b6:1; u8 b7:1; } F3;
typedef struct { u8 b0:4; u8 b4:2; u8 b6:1; u8 b7:1; } F5;
typedef struct {
    union { struct { s32 w0; s32 w4; } w; struct { F0 a; F1 b; F2 c; F3 d; F1 e; F5 f; F1 g; F1 h; } f; } u;
    f32 x8[9];
    f32 x2C;
    s32 x30[7];
    s32 x4C;
    u8 pad50[4];
    s16 x54;
    u8 pad56[2];
    s8 x58, x59, x5A, x5B;
    u8 pad5C[4];
    u8 x60, x61, x62, x63;
    s32 x64;
    u8 pad68[8];
    Vec x70[8];
    s32 xF0, xF4, xF8, xFC;
    u16 x100, x102;
    s16 x104, x106;
    u8 x108, x109;
    s16 x10A;
    s32 x10C;
    u8 x110, x111;
    u8 pad112[0xE];
    s16 x120, x122;
    u8 x124, x125, x126;
    u8 pad127[9];
    Vec x130[3];
} S;
typedef struct { u8 pad[0x1C]; u8 x1C:2; } R;
#ifndef NONMATCHING
extern u8 D_00201F10;
#else
/* data twins (src/game/data/sbss.c): D_00201F10 */
static u8 D_00201F10;
#endif
void Enemy_UpdateAI_1_00136400(Obj613 *a, f32 dt);
void Enemy_InitState_1_00136700(Actor *a0);
u32 Enemy_Get5B4b5_1_0013E4D0(Obj613 *);
s32 Enemy_IsDead_1_0013EEE0(Obj613 *);
s32 Enemy_IsOnScreen_0_0013FCC0(Obj613 *, s32);
s32 Enemy_SelectAttack_1_00135490(Obj613 *, f32 *, f32 *, f32 *);
void EnemyScr_Event200F_1_00141E10(Obj613 *, u8, f32, f32, f32, f32);
f32 Combat_CalcHitAngle_0_00133D00(Obj613 *, f32 *, f32 *, f32 *);
u32 Enemy_Get5B6b4_1_0013EAA0(Obj613 *);
u8 EnemyScr_Event2026_1_00140480(Obj613 *, u8, u32, f32, f32, f32, f32);
u32 Enemy_Get5B0b7_1_0013EB60(Obj613 *);
void Enemy_ExecMoveCmd_1_00134D70(Obj613 *, s32);
void Enemy_ExecMoveCmdInt_1_00135240(Obj613 *, s32);
void Enemy_CopyVec660_1_00140350(Obj613 *, s8 *);
void Enemy_CopyVec670_1_00140330(Obj613 *, s8 *);
u8 Enemy_UpdateMovement_1_00134960(Obj613 *);
s32 Enemy_TurnTowardTarget_1_00134180(Obj613 *, f32);
void memset(void *, s32, s32);
void Enemy_UpdateModelMatrix_0_001A7E60(Actor *);
R* Enemy_GetParamPtr290_1_0013DE50(Actor *);
f32* Enemy_GetPositionPtr_2_00140460(Actor *);
void Enemy_CopyPosition_2_00140470(Actor *, Vec *);
void Enemy_CopyRotation_2_00140440(Actor *, Vec *);
u16* Enemy_GetParamPtr10_1_0013E070(Actor *);
u16 Enemy_GetMaxHp_2_0013F700(Actor *);
u8 Enemy_GetParamByte6_1_0013E080(Actor *);
s32 Rand_Range_3_0013D500(u8);
void Enemy_AddHp_2_0013F710(Actor *, s32);
void Enemy_Set5B1b3IfUnlocked_1_0013E9D0(Actor *, s32);
void Enemy_Set5B4b3_1_0013E620(Actor *, s32);
void Enemy_Set5C8_1_0013E450(Actor *, f32);
void Enemy_Set5C0_1_0013E470(Actor *, f32);
void EnemyScr_EventInit_1_001428C0(Actor *);

/* Enemy_UpdateAI_1_00136400 */
#define B613(a) ((a)->b613)
#define F614(a) ((a)->f614)
static inline f32 u2f(u32 x) { return x; }
static inline void g(Obj613 *a, s32 k) {
    if (Enemy_Get5B0b7_1_0013EB60(a)) {
        Enemy_ExecMoveCmd_1_00134D70(a, k);
    } else {
        Enemy_ExecMoveCmdInt_1_00135240(a, k);
    }
    Enemy_UpdateMovement_1_00134960(a);
    F614(a) = u2f(B613(a)) / 10.0f;
}

void Enemy_UpdateAI_1_00136400(Obj613 *a, f32 dt) {
    f32 x0, y0, z0;
    f32 x1, y1, z1;
    f32 r;
    s32 busy;
    u8 m;

    if (Enemy_Get5B4b5_1_0013E4D0(a) && Enemy_IsDead_1_0013EEE0(a)) {
        return;
    }
    busy = (u8)Enemy_IsOnScreen_0_0013FCC0(a, 0);
    EnemyScr_Event200F_1_00141E10(a, Enemy_SelectAttack_1_00135490(a, &x0, &y0, &z0), x0, y0, z0, dt);
    r = Combat_CalcHitAngle_0_00133D00(a, &x1, &y1, &z1);
    a->b6C1 = EnemyScr_Event2026_1_00140480(a, a->b6C1, Enemy_Get5B6b4_1_0013EAA0(a), r, x1, y1, z1);
    F614(a) -= dt;
    if (F614(a) <= 0.0f) {
        if (Enemy_Get5B0b7_1_0013EB60(a)) {
            Enemy_ExecMoveCmd_1_00134D70(a, 0);
        } else {
            Enemy_ExecMoveCmdInt_1_00135240(a, 0);
        }
        if (!Enemy_IsDead_1_0013EEE0(a) && !(u8)busy) {
            Enemy_CopyVec660_1_00140350(a, (s8 *)a + 0x620);
            Enemy_CopyVec670_1_00140330(a, (s8 *)a + 0x630);
            B613(a) = 0xFA;
        }
        Enemy_UpdateMovement_1_00134960(a);
        F614(a) = u2f(B613(a)) / 10.0f;
    }
    if ((u8)Enemy_TurnTowardTarget_1_00134180(a, dt)) {
        m = Enemy_UpdateMovement_1_00134960(a);
        if (m == 1) {
            g(a, 1);
        } else if (m == 2) {
            g(a, 2);
        }
    }
}

/* Enemy_InitState_1_00136700 */
void Enemy_InitState_1_00136700(Actor *a0) {
    S *p;
    u16 *r;
    u32 m;
    u32 n;
    u32 k;

    p = (S *)&a0->flags5B0;
    memset(p, 0, 0x160);
    Enemy_UpdateModelMatrix_0_001A7E60(a0);
    p->u.w.w0 = 0;
    p->u.w.w4 = 0;
    p->u.f.a.b0 = 0;
    p->u.f.a.b1 = 0;
    p->u.f.a.b2 = 0;
    p->u.f.a.b3 = 0;
    p->u.f.a.b7 = 0;
    p->u.f.b.b0 = 0;
    p->u.f.b.b1 = 0;
    p->u.f.b.b2 = 0;
    p->u.f.b.b3 = 0;
    p->u.f.b.b4 = 0;
    p->u.f.b.b5 = 0;
    p->u.f.b.b6 = 0;
    p->u.f.b.b7 = 0;
    p->u.f.c.b0 = 0;
    p->u.f.c.b1 = 0;
    p->u.f.c.b2 = 0;
    p->u.f.c.b3 = 0;
    p->u.f.c.b4 = 0;
    p->u.f.c.b6 = (Enemy_GetParamPtr290_1_0013DE50(a0)->x1C == 2) ? 3 : 0;
    p->u.f.d.b0 = 0;
    p->u.f.d.b2 = 0;
    p->u.f.d.b3 = 0;
    p->u.f.d.b4 = 0;
    p->u.f.d.b6 = 0;
    p->u.f.d.b7 = 0;
    p->u.f.e.b0 = 0;
    p->u.f.e.b1 = 0;
    p->u.f.e.b2 = 0;
    p->u.f.e.b3 = 0;
    p->u.f.e.b4 = 0;
    p->u.f.e.b5 = 1;
    p->u.f.e.b6 = 0;
    p->u.f.e.b7 = 0;
    p->u.f.f.b0 = 0;
    p->u.f.f.b4 = 0;
    p->u.f.f.b6 = 0;
    p->u.f.f.b7 = 0;
    p->u.f.g.b0 = 0;
    p->u.f.g.b1 = 0;
    p->u.f.g.b2 = 0;
    p->u.f.g.b3 = 0;
    p->u.f.g.b4 = 0;
    p->u.f.g.b5 = 0;
    p->u.f.h.b2 = 0;
    p->u.f.h.b3 = 0;
    p->u.f.h.b4 = 0;
    p->u.f.h.b5 = 0;
    p->u.f.h.b6 = 0;
    p->u.f.h.b7 = 0;
    p->x8[0] = 1.0f;
    p->x8[1] = 1.0f;
    p->x8[2] = 1.0f;
    p->x8[3] = 0.0f;
    p->x8[4] = 1.0f;
    p->x8[5] = 0.0f;
    p->x8[6] = 0.0f;
    p->x8[7] = 1.0f;
    p->x8[8] = 0.0f;
    p->x2C = Enemy_GetPositionPtr_2_00140460(a0)[1];
    p->x30[0] = 0; ((u8 *)&p->x4C)[0] = 0;
    p->x30[1] = 0; ((u8 *)&p->x4C)[1] = 0;
    p->x30[2] = 0; ((u8 *)&p->x4C)[2] = 0;
    p->x30[3] = 0; ((u8 *)&p->x4C)[3] = 0;
    p->x30[4] = 0; ((u8 *)&p->x4C)[4] = 0;
    p->x30[5] = 0; ((u8 *)&p->x4C)[5] = 0;
    p->x30[6] = 0; ((u8 *)&p->x4C)[6] = 0;
    p->x4C = 0; ((u8 *)&p->x4C)[7] = 0;
    p->x54 = 0;
    p->x58 = -1;
    p->x59 = -1;
    p->x5A = -1;
    p->x5B = 0;
    p->x60 = 0;
    p->x61 = 0;
    p->x62 = 2;
    p->x63 = 10;
    p->x64 = 0;
    Enemy_CopyPosition_2_00140470(a0, &p->x70[0]);
    Enemy_CopyRotation_2_00140440(a0, &p->x70[1]);
    Enemy_CopyPosition_2_00140470(a0, &p->x70[2]);
    Enemy_CopyRotation_2_00140440(a0, &p->x70[3]);
    Enemy_CopyPosition_2_00140470(a0, &p->x70[4]);
    Enemy_CopyRotation_2_00140440(a0, &p->x70[5]);
    Enemy_CopyPosition_2_00140470(a0, &p->x70[6]);
    Enemy_CopyRotation_2_00140440(a0, &p->x70[7]);
    p->xF0 = 0;
    p->xF4 = 0;
    p->xF8 = 0;
    p->xFC = 0;
    r = Enemy_GetParamPtr10_1_0013E070(a0);
    p->x100 = r[0xFA];
    p->x102 = r[0xFB];
    p->x104 = 0;
    p->x106 = 0;
    p->x108 = 0;
    p->x109 = 0;
    p->x10A = 0;
    p->x10C = 0;
    p->x110 = 0xFF;
    p->x111 = 0;
    p->x120 = -1;
    p->x122 = -1;
    p->x124 = 0;
    p->x125 = 0;
    p->x126 = 0;
    Enemy_CopyPosition_2_00140470(a0, &p->x130[0]);
    Enemy_CopyPosition_2_00140470(a0, &p->x130[1]);
    Enemy_CopyPosition_2_00140470(a0, &p->x130[2]);
    m = Enemy_GetMaxHp_2_0013F700(a0);
    m *= Enemy_GetParamByte6_1_0013E080(a0);
    k = Rand_Range_3_0013D500(100);
    n = k * m;
    Enemy_AddHp_2_0013F710(a0, -(n / 10000));
    Enemy_Set5B1b3IfUnlocked_1_0013E9D0(a0, 1);
    Enemy_Set5B4b3_1_0013E620(a0, 1);
    Enemy_Set5C8_1_0013E450(a0, 0.5f);
    Enemy_Set5C0_1_0013E470(a0, 0.0f);
    if (a0->unk4A8 == 0) {
        a0->unk710 = D_00201F10;
        D_00201F10++;
    }
    EnemyScr_EventInit_1_001428C0(a0);
}
