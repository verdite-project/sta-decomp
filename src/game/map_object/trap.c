#include "m2c.h"
#include "common.h"
typedef struct { u8 st:2; u8 b2:1; } F50;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F52;
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 p:7; u8 v:1; } BF7;
typedef struct { u8 p:2; u8 v:1; } BF2;
typedef struct { u8 p:2; u8 v:2; } BF2_2;
typedef struct { u8 pad[8]; u16 h8; } Key;
extern u8 *gMapObjectAllSbss_002022D4;
void Trap_UpdateIdle_1_001BA680(s8 *p, u32 i, f32 dt);
void Trap_SetState_0_001BA850(s8 *p, u32 i, f32 dt);
void Trap_Attack_0_001BAA10(s32 a0, s32 a1, s32 a2, Key *a3, s32 t0, s32 t1);
void MapObj_SetAnimFrame_0_001B87C0(s8 *, u32, s32, s32, f32, f32);
u32 Rand_Next_3_0015ED20(void);
void Attack_PlaySe_0_001D1E80(s32, s32, Key *, s32, s32);
void Attack_SpawnSfx_0_001D1F20(s32, u8 *, s32, s32, Key *, s32, s32);

/* Trap_UpdateIdle_1_001BA680 */
static inline s8 *getT(s8 *p, s8 *e30, s8 *e) {
    s8 *base = *(s8 **)(p + 0x170);
    s8 *t = base + (*(u16 *)(e30 + 0x18) << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF3 *)(t + 0x12))->v) {
        return base + (*(u16 *)(t + 6) << 6);
    }
    return t;
}

void Trap_UpdateIdle_1_001BA680(s8 *p, u32 i, f32 dt) {
    s8 *e30;
    s8 *e;
    s8 *t;
    s32 st;

    e = *(s8 **)(p + 0x180) + (i << 7);
    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    t = getT(p, e30, e);
    st = *(u8 *)(e + 0x50) & 3;
    switch ((u8)st) {
    case 0:
        Trap_SetState_0_001BA850(p, i, dt);
        break;
    case 1:
        if (((F50 *)(e + 0x50))->b2) {
            break;
        }
        if (((BF7 *)(t + 0x12))->v) {
            ((F50 *)(e + 0x50))->st = 2;
            *(f32 *)(e + 0x5C) = 1.0f;
            break;
        }
        ((F50 *)(e + 0x50))->st = 3;
        ((F52 *)(e + 0x52))->b4 = 1;
        break;
    case 2:
        *(f32 *)(e + 0x5C) -= dt;
        if (*(f32 *)(e + 0x5C) < 0.0f) {
            ((F50 *)(e + 0x50))->st = 3;
            ((F52 *)(e + 0x52))->b3 = 0;
            ((F52 *)(e + 0x52))->b4 = 1;
            break;
        }
        *(f32 *)(e + 0x58) = *(f32 *)(e + 0x5C);
        break;
    case 3:
        ((F52 *)(e + 0x52))->b4 = 1;
        break;
    }
}

/* Trap_SetState_0_001BA850 */
void Trap_SetState_0_001BA850(s8 *p, u32 i, f32 dt) {
    s8 *e30;
    s8 *e;
    s8 *t;
    s8 ****pp;

    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    e = *(s8 **)(p + 0x180) + (i << 7);
    t = *(s8 **)(p + 0x170) + (*(u16 *)(e30 + 0x18) << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF3 *)(t + 0x12))->v) {
        pp = *(s8 *****)(e + 0x44);
    } else {
        pp = *(s8 *****)(e + 0x40);
    }
    if (pp == NULL || *pp == NULL) {
        return;
    }
    if (**pp == NULL || ***pp == NULL || *(u16 *)(***pp + 0x16) <= 0) {
        return;
    }
    if (!((BF7 *)(e + 0x52))->v || ((BF2_2 *)(e30 + 0x24))->v != 2) {
        return;
    }
    if (((BF2 *)(e + 0x50))->v) {
        return;
    }
    *(f32 *)(e + 0x5C) -= dt;
    if (*(f32 *)(e + 0x5C) <= 0.0f) {
        MapObj_SetAnimFrame_0_001B87C0(p, i, 0, 0, 0.0f, 1.0f);
        *(f32 *)(e + 0x5C) = 1.0f + 2.0f * (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF));
    }
}

/* Trap_Attack_0_001BAA10 */
void Trap_Attack_0_001BAA10(s32 a0, s32 a1, s32 a2, Key *a3, s32 t0, s32 t1) {
    if (t1 != 0) {
        switch (a3->h8) {
        case 0:
            Attack_PlaySe_0_001D1E80(a0, a2, a3, t0, t1);
            break;
        case 1:
            Attack_SpawnSfx_0_001D1F20(a0, gMapObjectAllSbss_002022D4 + 0xB4, a1, a2, a3, t0, t1);
            break;
        }
    }
}
