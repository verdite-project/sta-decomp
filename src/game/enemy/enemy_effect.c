#include "actor.h"
#include "m2c.h"
#include "common.h"
#include "game/data.h"
typedef struct { u8 id; u8 spd; u16 x : 5; u16 y : 5; } Rec;
typedef struct { u8 pad[8]; u32 id; f32 f; u8 pad10[0xC]; f32 x1C; } Mdl;
typedef struct {
    u8 pad[0xC];
    s32 *pC;
    u8 pad10[8];
    s8 *p18;
    u8 pad1C[4];
    Rec *p20;
    u8 pad24[4];
    Mdl *p28;
} Sub;
typedef struct { u8 pad[0x140]; s16 id; u8 p142[2]; f32 f144; f32 f148; u8 p14C[4]; f32 f150; } Ent;
typedef struct { u8 p[0x5B5]; Flags8_4x2 f5B5; u8 q[0x6D2 - 0x5B6]; s16 x6D2; s8 x6D4; s8 x6D5; s8 x6D6; } A360;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 n:3; u8 r:2; } F_0013C420;
typedef struct {
    u8 pad[0x5B0];
    F_0013C420 f5B0;
    u8 pad2[0x6B4 - 0x5B1];
    u16 x6B4[2];
} A_0013C420;
typedef struct { u8 pad[0x5B0]; u8 x5B0; } O_0013C740;
typedef struct { char pad[0x5B0]; unsigned int f : 1; char p[2]; unsigned int : 4; unsigned int m : 2; } Obj_0013C7B0;
typedef struct {
    u8 pad0[0x7C];
    u32 x7C;
    u8 pad80[0x4B0 - 0x80];
    s8 *unk4B0;
    u8 pad4B4[0x518 - 0x4B4];
    s8 *unk518;
    u8 pad51C[0x5B0 - 0x51C];
    Flags8 flags5B0;
    u8 pad5B1[5];
    Flags8 flags5B6;
    u8 pad5B7[0x6D0 - 0x5B7];
    s16 x6D0;
    s16 x6D2;
    s8 x6D4;
    s8 x6D5;
    u8 x6D6;
} Actor_0013CBC0;
typedef struct { u8 pad0[0x140]; u16 x140; u8 pad142[2]; f32 x144; f32 x148; u8 pad14C[4]; f32 x150; } Ent_0013CBC0;
typedef struct { u8 pad0[0xC]; f32 xC; f32 x10; f32 x14; } Q_0013CBC0;
typedef struct { u8 pad0[0x40]; Vec v40; Vec v50; } P_0013CBC0;
typedef struct { char pad[0x5B7]; unsigned char : 7; unsigned char f : 1; } Obj_Enemy_Clear5B7b7_1_0013D1C0;
typedef struct { char pad[0x198]; f32 *v; } B;
typedef struct { char pad[0x518]; B *q; char p[0x660 - 0x51C]; f32 a[4]; f32 b[4]; } Obj_Enemy_ResetVectors_0_0013D1F0;
typedef struct { u128 a, b; } V2;
typedef struct { u8 p[0x6E]; u16 n; } O;
typedef struct { u8 p[0x24]; s32 x24; } Out;
typedef struct { u128 a, b; } Ray_Enemy_RaycastMapB_0_0013D320;
typedef struct { u8 pad[0x24]; s32 hit; } Res_Enemy_RaycastMapB_0_0013D320;
typedef struct { u8 pad[0x6E]; u16 n; } Obj_Enemy_RaycastMapB_0_0013D320;
typedef struct { u128 a; u128 b; } Ray_Enemy_RaycastMapC_0_0013D430;
typedef struct { s32 w[16]; } Res_Enemy_RaycastMapC_0_0013D430;
void Enemy_AttachEffect_1_0013C0D0(Actor *a, u8 slot, s16 id, s8 dx, s8 dy, u8 flags);
void Enemy_SelectMotion_0_0013C420(A_0013C420 *a, u8 kind, s16 v, s32 a3);
s32 Enemy_StartIdleMotion_1_0013C740(O_0013C740 *o);
u8 Enemy_TryStartMoveMotion_1_0013C7B0(Obj_0013C7B0 *o);
u8 Enemy_TryStartTurnMotion_1_0013C850(Actor *a);
u8 Enemy_TryStartAttackMotion_1_0013C950(Actor *a, u8 b, u8 c);
u8 Enemy_TryStartReactMotion_1_0013CA40(Actor *a, u8 b);
void Enemy_UpdateMotion_1_0013CBC0(Actor_0013CBC0 *a, f32 dt);
void Enemy_Clear5B7b7_1_0013D1C0(Obj_Enemy_Clear5B7b7_1_0013D1C0 *o);
u64 Enemy_Get5B7b7_1_0013D1E0(void *arg0);
void Enemy_ResetVectors_0_0013D1F0(Obj_Enemy_ResetVectors_0_0013D1F0 *o);
s32 Enemy_RaycastMapA_0_0013D250(O *o, Out *out, V2 *v, u8 m2, u8 m1);
s32 Enemy_RaycastMapB_0_0013D320(Obj_Enemy_RaycastMapB_0_0013D320 *o, Res_Enemy_RaycastMapB_0_0013D320 *res, Ray_Enemy_RaycastMapB_0_0013D320 *ray, s32 a3, u8 f);
s32 Enemy_RaycastMapC_0_0013D430(s8 *o, Res_Enemy_RaycastMapC_0_0013D430 *res, Ray_Enemy_RaycastMapC_0_0013D430 *src, s32 mode, u8 fl);
u32 Enemy_Get5B5mF_1_0013E5E0(Actor *);
Ent* Enemy_GetPart_1_0013DC70(Actor *, u8);
f32 Mdl_GetMotionLength_0_00173F70(s32, u8);
void Mdl_SetBoneRotation_0_001710D0(Mdl *, s16, f32, f32, f32);
void sceVu0CopyVector(void *, void *);
u32 Enemy_Get5B2b6w2_1_0013E750(void *);
void Enemy_Set5B1b5_1_0013E920(void *, u8);
u32 Rand_Next_3_0015ED20(void);
u32 Enemy_Get5B1b5_1_0013E940(O_0013C740 *);
s32 EnemyScr_Event2009Move_1_00142470(Obj_0013C7B0 *o, s16 k);
u8 EnemyScr_Event2005Turn_1_00142530(Actor *, s16);
s16 Enemy_GetPartAngle_1_0013E0C0(Actor *, u8);
u8 EnemyScr_Event2004Attack_1_001425F0(Actor *, u8, s32);
u8 EnemyScr_Event2003React_1_001426C0(Actor *, s16);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
s32 Enemy_Get5B2b5_1_0013E780(Actor_0013CBC0 *);
void Enemy_Set5B2b6w2_1_0013E730(Actor_0013CBC0 *, s32);
s32 Enemy_IsDead_1_0013EEE0(Actor_0013CBC0 *);
s32 Enemy_Get5B5b7_1_0013E970(Actor_0013CBC0 *);
s32 Enemy_Get5B1b3_1_0013EA10(Actor_0013CBC0 *);
s32 Enemy_Get5B1b4_1_0013E9C0(Actor_0013CBC0 *);
void Enemy_Set5B5b7_1_0013E950(Actor_0013CBC0 *, s32);
void Enemy_Set5B1b3IfUnlocked_1_0013E9D0(Actor_0013CBC0 *, s32);
void Enemy_Set5B1b4IfUnlocked_0_0013E980(Actor_0013CBC0 *, s32);
s32 Enemy_GetModelField8_0_0013E0B0(Actor_0013CBC0 *);
f32 Enemy_PlayModelAnim_0_0013E090(Actor_0013CBC0 *, s32);
void Enemy_Set5B3b7_1_0013E6D0(Actor_0013CBC0 *, s32);
u32 EnemyScr_Event2002_1_00142780(Actor_0013CBC0 *);
u32 EnemyScr_Event2016_1_001412E0(Actor_0013CBC0 *);
void Enemy_Set5B2b0_1_0013E890(Actor_0013CBC0 *, s32);
void Enemy_SetStateResetTimer_1_0013E7E0(Actor_0013CBC0 *, s32);
s32 MapColl_SphereCastAll_0_001B34B0(O *o, Out *out, V2 *p, u8 f1, u8 f2);
s32 MapColl_SphereCast_0_001B2B90(O *o, Out *out, V2 *p, u16 idx, u8 f1, u8 f2);
s32 MapColl_CapsuleCastAll_1_001B3240(void *, void *, void *, s32, s32);
s32 MapColl_CapsuleCast_1_001B2800(void *, void *, void *, u16, s32, s32);

/* Enemy_AttachEffect_1_0013C0D0 */
static inline f32 u2f_Enemy_AttachEffect_1_0013C0D0(u32 x) { return x; }
#define sceVu0CopyVector sceVu0CopyVector__as_Enemy_AttachEffect_1_0013C0D0
void sceVu0CopyVector__as_Enemy_AttachEffect_1_0013C0D0(s8 *, s8 *);

void Enemy_AttachEffect_1_0013C0D0(Actor *a, u8 slot, s16 id, s8 dx, s8 dy, u8 flags) {
    f32 scale;
    f32 x;
    f32 y;
    Sub *s;
    Mdl *m;
    Ent *e;
    Rec *r;
    u32 i;

    scale = 1.0f;
    if ((u8)Enemy_Get5B5mF_1_0013E5E0(a) & 4) {
        scale = 0.75f;
    }
    if (id == -1) {
        return;
    }
    if (id >= 1000 && slot != 0xFF) {
        e = Enemy_GetPart_1_0013DC70(a, slot);
        e->f150 = 1.0f;
        e->id = (*(u8 **)((s8 *)a + 0x514))[id * 4 - 4000];
        e->f148 = scale * (u2f_Enemy_AttachEffect_1_0013C0D0((*(u8 **)((s8 *)a + 0x514))[id * 4 - 3999]) * 0.0078125f);
        e->f144 = 0;
        return;
    }
    i = (u16)id;
    s = (Sub *)(a->unk518 + 0x180);
    r = &s->p20[i];
    x = 0.033333335f * (f32)(dx + r->x);
    y = 0.033333335f * (f32)(dy + r->y);
    if (flags & 2) {
        x = 0.0f;
        s->p28->x1C = 0;
    } else if (flags & 1) {
        m = s->p28;
        if (m->id == r->id && !(m->f < Mdl_GetMotionLength_0_00173F70(*s->pC, r->id))) {
            x = 0.0f;
            m->x1C = 0;
        }
    }
    Mdl_SetBoneRotation_0_001710D0(s->p28, s->p20[i].id, scale * (u2f_Enemy_AttachEffect_1_0013C0D0(s->p20[i].spd) * 0.0078125f), x, y);
    sceVu0CopyVector(s->p18 + 0xA0, &gZeroVec_003139A0);
}
#undef sceVu0CopyVector

/* Enemy_SetMotion_2_0013C360 */
/* Enemy_SetMotion_2_0013C360 through Enemy_UpdateMotion_1_0013CBC0: one translation unit. Enemy_SetMotion_2_0013C360
   is static here, so CodeWarrior knows which registers it keeps and its
   callers do not reload them (Enemy_StartIdleMotion_1_0013C740, Enemy_UpdateMotion_1_0013CBC0). */

static void Enemy_SetMotion_2_0013C360(void *p, s16 v, s8 b, s8 c, s32 d) {
    A360 *a = p;
    a->x6D2 = v;
    a->x6D4 = b;
    a->x6D5 = c;
    a->x6D6 = d;
    if ((v >= 8 && v < 12) || (v >= 16 && v < 19) || (v >= 40 && v < 44) || (v >= 48 && v < 51)) a->f5B5.f.b6 = 1;
    else a->f5B5.f.b6 = 0;
}


void Enemy_SelectMotion_0_0013C420(A_0013C420 *a, u8 kind, s16 v, s32 a3) {
    s16 id = -1;

    switch (kind) {
    case 0:
        if (v == 0 && (a->x6B4[a->f5B0.b0] & 0x400)) {
            v = !((Rand_Next_3_0015ED20() & 3) != 0);
        }
        id = (a->f5B0.b0 << 5) + (v | a->f5B0.b2);
        break;
    case 1:
        id = (a->f5B0.b0 << 5) + 2;
        break;
    case 2:
        id = (a->f5B0.b0 << 5) + 3;
        break;
    case 3:
        id = v + ((a->f5B0.b0 << 5) + 4) + a->f5B0.b1 * 2;
        break;
    case 4:
        if (a->f5B0.n < 4) {
            id = a->f5B0.n + ((a->f5B0.b0 << 5) + 8);
        } else {
            id = (a->f5B0.n - 4) + ((a->f5B0.b0 << 5) + 0x10);
        }
        break;
    case 7:
        id = (a->f5B0.b0 << 5) + 0x14;
        break;
    case 8:
        id = (a->f5B0.b0 << 5) + 0x15;
        break;
    case 9:
        id = (a->f5B0.b0 << 5) + 0x16;
        break;
    case 13:
        id = (a->f5B0.b0 << 5) + 0x1A;
        break;
    case 14:
        id = (a->f5B0.b0 << 5) + 0x1B;
        break;
    case 15:
        id = (a->f5B0.b0 << 5) + 0x1C;
        break;
    case 16:
        id = (a->f5B0.b0 + 0xA0) + v * 2;
        break;
    case 0xFF:
        id = v;
        break;
    }
    if (id != -1) Enemy_SetMotion_2_0013C360(a, id, 5, 0, a3);
}



s32 Enemy_StartIdleMotion_1_0013C740(O_0013C740 *o) {
    if (Enemy_Get5B1b5_1_0013E940(o) == 0) {
        Enemy_SetMotion_2_0013C360(o, (o->x5B0 & 1) * 32 + 0x13, 0, 0, 2);
        Enemy_Set5B1b5_1_0013E920(o, 1);
    }
    return 0;
}



u8 Enemy_TryStartMoveMotion_1_0013C7B0(Obj_0013C7B0 *o)
{
    u8 r;
    s16 k = (o->m & 3) + (o->f * 32 + 12);
    r = EnemyScr_Event2009Move_1_00142470(o, k);
    if (!r)
        Enemy_SetMotion_2_0013C360(o, k, 0, 0, 2);
    Enemy_Set5B1b5_1_0013E920(o, 1);
    return r;
}



u8 Enemy_TryStartTurnMotion_1_0013C850(Actor *a) {
    u8 r;
    s16 v;
    v = (a->flags5B0.f.b0 << 5) + 0x19;
    if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 2) {
        v = (a->flags5B0.f.b0 << 5) + 0x17;
        a->flags5B6.f.b0 = 1;
    } else if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 1) {
        v = (a->flags5B0.f.b0 << 5) + 0x17;
    }
    r = EnemyScr_Event2005Turn_1_00142530(a, v);
    if (r == 0) {
        Enemy_SetMotion_2_0013C360(a, v, 0, 0, 2);
    }
    Enemy_Set5B1b5_1_0013E920(a, 1);
    return r;
}

u8 Enemy_TryStartAttackMotion_1_0013C950(Actor *a, u8 b, u8 c) {
    u8 r;
    s16 v;
    if (b == 0xFF) {
        v = (a->flags5B0.f.b0 << 5) + 0x18;
    } else {
        v = Enemy_GetPartAngle_1_0013E0C0(a, b);
        v += (s16)(a->flags5B0.f.b0 + 2 + c * 2);
    }
    r = EnemyScr_Event2004Attack_1_001425F0(a, v, (u8)b);
    if (r == 0) {
        Enemy_SetMotion_2_0013C360(a, v, 0, 0, 2);
    }
    Enemy_Set5B1b5_1_0013E920(a, 1);
    return r;
}



u8 Enemy_TryStartReactMotion_1_0013CA40(Actor *a, u8 b) {
    s16 v;
    u8 r;
    if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 2) {
        v = a->flags5B0.f.b0 * 32 + 0x17;
    } else if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 1) {
        v = a->flags5B0.f.b0 * 32 + 0x17;
    } else if (b == 0xFF) {
        v = a->flags5B0.f.b0 * 32 + 0x18;
    } else {
        v = Enemy_GetPartAngle_1_0013E0C0(a, b);
        v += a->flags5B0.b & 1;
    }
    r = EnemyScr_Event2003React_1_001426C0(a, v);
    if (r == 0) {
        Enemy_SetMotion_2_0013C360(a, v, 0, 0, 2);
    }
    Enemy_Set5B1b5_1_0013E920(a, 1);
    if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 2) {
        a->flags5B6.f.b0 = 1;
    }
    return r;
}


#define Enemy_AttachEffect_1_0013C0D0 Enemy_AttachEffect_1_0013C0D0__as_Enemy_SetMotion_2_0013C360
void Enemy_AttachEffect_1_0013C0D0__as_Enemy_SetMotion_2_0013C360(Actor_0013CBC0 *a, u8 slot, s16 id, s8 dx, s8 dy, u8 flags);
#define Enemy_GetPart_1_0013DC70 Enemy_GetPart_1_0013DC70__as_Enemy_SetMotion_2_0013C360
Ent_0013CBC0 *Enemy_GetPart_1_0013DC70__as_Enemy_SetMotion_2_0013C360(Actor_0013CBC0 *, u8);
#define Mdl_GetMotionLength_0_00173F70 Mdl_GetMotionLength_0_00173F70__as_Enemy_SetMotion_2_0013C360
f32 Mdl_GetMotionLength_0_00173F70__as_Enemy_SetMotion_2_0013C360(s32, u16);



static inline f32 u2f_Enemy_SetMotion_2_0013C360(u32 x) { return x; }

static inline void jump(Actor_0013CBC0 *a, f32 dt) {
    Vec t;
    P_0013CBC0 *p = (P_0013CBC0 *)(a->unk518 + 0x180);
    p->v50.y = 333.2f * (u2f_Enemy_SetMotion_2_0013C360(*(u16 *)(a->unk4B0 + 0x246)) / 4096.0f);
    sceVu0ScaleVector(&t, &p->v50, dt);
    sceVu0AddVector(&p->v40, &t, &p->v40);
    Enemy_Set5B2b6w2_1_0013E730(a, 1);
}

void Enemy_UpdateMotion_1_0013CBC0(Actor_0013CBC0 *a, f32 dt) {
    u8 i;
    u32 j;
    Ent_0013CBC0 *e;
    f32 rem;
    f32 over;
    f32 lim;
    f32 t;
    Q_0013CBC0 **s;
    f32 *pc;

    rem = dt;
    if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 2) {
        if (a->flags5B6.f.b0) {
            jump(a, dt);
            a->flags5B6.f.b0 = 0;
        }
    } else {
        a->flags5B6.f.b0 = 0;
    }
    if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 1 && Enemy_Get5B2b5_1_0013E780(a)) {
        Enemy_Set5B2b6w2_1_0013E730(a, 0);
        Enemy_SetMotion_2_0013C360(a, Enemy_IsDead_1_0013EEE0(a) ? (s16)((a->flags5B0.f.b0 << 5) + 0x1F) : (s16)((a->flags5B0.f.b0 << 5) + 0x1E), 5, 0, 2);
        Enemy_Set5B1b5_1_0013E920(a, 1);
    }
    for (i = 0; (rem > 0.0f) && i < 4; i++) {
        if (a->x6D2 >= 0) {
            if (a->x6D0 < 0) {
                a->x6D6 = 2;
            }
            Enemy_AttachEffect_1_0013C0D0(a, 0xFF, a->x6D2, a->x6D4, a->x6D5, a->x6D6);
            a->x6D0 = a->x6D2;
            a->x6D2 = -1;
        }
        if (Enemy_Get5B5b7_1_0013E970(a)) {
            Enemy_Set5B5b7_1_0013E950(a, 0);
            Enemy_Set5B1b3IfUnlocked_1_0013E9D0(a, 0);
            Enemy_Set5B1b4IfUnlocked_0_0013E980(a, 0);
        } else if (Enemy_Get5B1b3_1_0013EA10(a)) {
            Enemy_Set5B5b7_1_0013E950(a, 0);
            Enemy_Set5B1b3IfUnlocked_1_0013E9D0(a, 0);
            Enemy_Set5B1b4IfUnlocked_0_0013E980(a, 0);
        } else if (Enemy_Get5B1b4_1_0013E9C0(a) && !a->flags5B0.f.b7) {
            Enemy_Set5B5b7_1_0013E950(a, 0);
            Enemy_Set5B1b3IfUnlocked_1_0013E9D0(a, 0);
            Enemy_Set5B1b4IfUnlocked_0_0013E980(a, 0);
        } else {
            over = 0.0f;
            lim = Enemy_PlayModelAnim_0_0013E090(a, Enemy_GetModelField8_0_0013E0B0(a));
            s = (Q_0013CBC0 **)(a->unk518 + 0x1A8);
            (*s)->x10 = (*s)->xC;
            (*s)->xC = (*s)->xC + rem * (*s)->x14;
            pc = &(*s)->xC;
            if (!((*s)->xC <= lim)) {
                over = (*s)->xC - lim;
                (*s)->xC = lim;
            }
            rem = over;
            Enemy_Set5B5b7_1_0013E950(a, 0);
            Enemy_Set5B1b3IfUnlocked_1_0013E9D0(a, 0);
            Enemy_Set5B1b4IfUnlocked_0_0013E980(a, 0);
        }
        if (!(rem <= 0.0f)) {
            Enemy_Set5B1b5_1_0013E920(a, 0);
            Enemy_Set5B3b7_1_0013E6D0(a, 0);
            if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 2) {
                jump(a, dt);
            }
            if ((u8)Enemy_Get5B2b6w2_1_0013E750(a) == 1) {
                Enemy_SetMotion_2_0013C360(a, (a->flags5B0.f.b0 << 5) + 0x1D, 5, 0, 1);
                Enemy_Set5B1b5_1_0013E920(a, 1);
            } else if (!a->flags5B0.f.b7) {
                if (!Enemy_IsDead_1_0013EEE0(a) && !(u8)EnemyScr_Event2002_1_00142780(a)) {
                    rem = 0.0f;
                }
            } else {
                if (!(u8)EnemyScr_Event2016_1_001412E0(a)) {
                    rem = 0.0f;
                }
            }
        }
    }
    if (!a->flags5B0.f.b7 && !(rem <= 0.0f) && Enemy_IsDead_1_0013EEE0(a)) {
        Enemy_Set5B2b0_1_0013E890(a, 1);
        Enemy_SetStateResetTimer_1_0013E7E0(a, 1);
    }
    for (j = 0; j < a->x7C; j++) {
        e = Enemy_GetPart_1_0013DC70(a, j);
        if (e->x150 != 0.0f) {
            lim = Mdl_GetMotionLength_0_00173F70(**(s32 **)(a->unk518 + 0x18C), e->x140);
            t = e->x144;
            t += dt * e->x148;
            if (!(t <= lim)) {
                t -= lim;
            }
            e->x144 = t;
        }
    }
}
#undef Enemy_AttachEffect_1_0013C0D0
#undef Enemy_GetPart_1_0013DC70
#undef Mdl_GetMotionLength_0_00173F70

/* Enemy_Clear5B7b7_1_0013D1C0 */
void Enemy_Clear5B7b7_1_0013D1C0(Obj_Enemy_Clear5B7b7_1_0013D1C0 *o) { int v = 0; o->f = v; }

/* Enemy_Get5B7b7_1_0013D1E0 */
u64 Enemy_Get5B7b7_1_0013D1E0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B7) << 0x38) >> 0x3F;
}

/* Enemy_ResetVectors_0_0013D1F0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Enemy_ResetVectors_0_0013D1F0
void sceVu0CopyVector__as_Enemy_ResetVectors_0_0013D1F0(f32 *v0, f32 *v1);

void Enemy_ResetVectors_0_0013D1F0(Obj_Enemy_ResetVectors_0_0013D1F0 *o)
{
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    sceVu0CopyVector(a, o->a);
    sceVu0CopyVector(b, o->b);
    sceVu0CopyVector(c, o->q->v);
    sceVu0CopyVector(d, o->q->v + 8);
}
#undef sceVu0CopyVector

/* Enemy_RaycastMapA_0_0013D250 */
s32 Enemy_RaycastMapA_0_0013D250(O *o, Out *out, V2 *v, u8 m2, u8 m1) {
    V2 c;
    u16 i;
    c = *v;
    if (m1 & 1) {
        MapColl_SphereCastAll_0_001B34B0(o, out, &c, m2, 0);
    }
    if ((m1 & 2) && o != 0) {
        for (i = 0; i < o->n; i++) {
            MapColl_SphereCast_0_001B2B90(o, out, &c, i, m2, 0);
        }
    }
    return out->x24;
}

/* Enemy_RaycastMapB_0_0013D320 */
#define MapColl_CapsuleCastAll_1_001B3240 MapColl_CapsuleCastAll_1_001B3240__as_Enemy_RaycastMapB_0_0013D320
s32 MapColl_CapsuleCastAll_1_001B3240__as_Enemy_RaycastMapB_0_0013D320(Obj_Enemy_RaycastMapB_0_0013D320 *, Res_Enemy_RaycastMapB_0_0013D320 *, Ray_Enemy_RaycastMapB_0_0013D320 *, s32, s32);
#define MapColl_CapsuleCast_1_001B2800 MapColl_CapsuleCast_1_001B2800__as_Enemy_RaycastMapB_0_0013D320
s32 MapColl_CapsuleCast_1_001B2800__as_Enemy_RaycastMapB_0_0013D320(Obj_Enemy_RaycastMapB_0_0013D320 *, Res_Enemy_RaycastMapB_0_0013D320 *, Ray_Enemy_RaycastMapB_0_0013D320 *, u16, s32, s32);

s32 Enemy_RaycastMapB_0_0013D320(Obj_Enemy_RaycastMapB_0_0013D320 *o, Res_Enemy_RaycastMapB_0_0013D320 *res, Ray_Enemy_RaycastMapB_0_0013D320 *ray, s32 a3, u8 f) {
    Ray_Enemy_RaycastMapB_0_0013D320 r;
    u16 j;
    r = *ray;
    if (f & 1) {
        MapColl_CapsuleCastAll_1_001B3240(o, res, &r, a3, 1);
        if (res->hit) return res->hit;
    }
    if ((f & 2) && o) {
        for (j = 0; j < o->n; j++) {
            MapColl_CapsuleCast_1_001B2800(o, res, &r, j, a3, 1);
            if (!(res->hit != 0) == 0) return res->hit;
        }
    }
    return res->hit;
}
#undef MapColl_CapsuleCastAll_1_001B3240
#undef MapColl_CapsuleCast_1_001B2800

/* Enemy_RaycastMapC_0_0013D430 */
#define MapColl_CapsuleCast_1_001B2800 MapColl_CapsuleCast_1_001B2800__as_Enemy_RaycastMapC_0_0013D430
s32 MapColl_CapsuleCast_1_001B2800__as_Enemy_RaycastMapC_0_0013D430(s8 *, Res_Enemy_RaycastMapC_0_0013D430 *, Ray_Enemy_RaycastMapC_0_0013D430 *, u16, s32, s32);
#define MapColl_CapsuleCastAll_1_001B3240 MapColl_CapsuleCastAll_1_001B3240__as_Enemy_RaycastMapC_0_0013D430
s32 MapColl_CapsuleCastAll_1_001B3240__as_Enemy_RaycastMapC_0_0013D430(s8 *, Res_Enemy_RaycastMapC_0_0013D430 *, Ray_Enemy_RaycastMapC_0_0013D430 *, s32, s32);

s32 Enemy_RaycastMapC_0_0013D430(s8 *o, Res_Enemy_RaycastMapC_0_0013D430 *res, Ray_Enemy_RaycastMapC_0_0013D430 *src, s32 mode, u8 fl) {
    Ray_Enemy_RaycastMapC_0_0013D430 ray;
    u16 i;

    ray = *src;
    if (fl & 1) {
        MapColl_CapsuleCastAll_1_001B3240(o, res, &ray, mode, 0);
    }
    if ((fl & 2) && o != NULL) {
        for (i = 0; i < *(u16 *)(o + 0x6E); i++) {
            MapColl_CapsuleCast_1_001B2800(o, res, &ray, i, mode, 0);
        }
    }
    return res->w[9];
}
#undef MapColl_CapsuleCast_1_001B2800
#undef MapColl_CapsuleCastAll_1_001B3240
