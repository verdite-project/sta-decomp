/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Trap_Update_0_001BA3F0.c.
 * The matching build takes it from the assembly of MapObj_SnapToGround_0_001B9F10. */
#ifdef NONMATCHING
/* NEAR 1 of 162 words (unchanged): final mul.s f12,f1,f0 vs retail f12,f0,f1 (u2f(t+0xE) first, evaluated after the select).
   MWCC puts the plain variable b first whatever the source order; making u2f evaluate first hoists it above the select (50 diffs).
   Tried: swapped order, mu/inline helpers, temps, volatile reads, ternary/fmax inline selects, -(-b), b in array, b38, s32 proto. */
#include "m2c.h"
typedef struct { u8 p:2; u8 v:1; } BF2;
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 p:4; u8 v:1; } BF4;
typedef struct { u8 p:6; u8 v:1; } BF6;
typedef struct { u8 p:2; u8 v:2; } BF2_2;
s8 *Mdl_GetFrameData_0_001715B0(s32);
s32 MapObj_IsActorNear_0_001B9E00(s8 *, s32, f32);
void MapObj_SetAnimFrame_0_001B87C0(s8 *, u32, s32, s32, f32, f32);
void Trap_UpdateIdle_1_001BA680(s8 *, u32, f32, f32);
void Trap_SetState_0_001BA850(s8 *, f32, u32, f32);

static inline f32 u2f(u32 x) {
    return x;
}

void Trap_Update_0_001BA3F0(s8 *p, u32 i, f32 dt, f32 x) {
    s8 *e30;
    s8 *e;
    s8 *t;
    s8 *r;
    f32 a;
    f32 b;

    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    e = *(s8 **)(p + 0x180) + (i << 7);
    t = *(s8 **)(p + 0x170) + (*(u16 *)(e30 + 0x18) << 6);
    r = Mdl_GetFrameData_0_001715B0(*(s32 *)(e + 0x40));
    if (((BF2 *)(e + 0x53))->v) {
        Trap_UpdateIdle_1_001BA680(p, i, dt, x);
        return;
    }
    a = 0.00024414062f * u2f(*(u16 *)(e30 + 0x12));
    b = 0.00024414062f * u2f(*(u16 *)(e30 + 0x16));
    if (a < b) {
        b = b;
    } else {
        b = a;
    }
    if (MapObj_IsActorNear_0_001B9E00(r + 0x230, ((BF3 *)(t + 0x13))->v, b * u2f(*(u16 *)(t + 0xE)))) {
        if (!((BF6 *)(e + 0x52))->v) {
            ((BF6 *)(e + 0x52))->v = 1;
            MapObj_SetAnimFrame_0_001B87C0(p, i, 0xB, 0, 0.0f, 1.0f);
            return;
        }
    } else {
        ((BF6 *)(e + 0x52))->v = 0;
    }
    if ((*(u8 *)(t + 0x12) & 1) && ((BF2_2 *)(e30 + 0x24))->v == 1 && ((BF4 *)(e + 0x50))->v) {
        MapObj_SetAnimFrame_0_001B87C0(p, i, 0, 0x80, 0.0f, 1.0f);
        return;
    }
    Trap_SetState_0_001BA850(p, dt, i, x);
}
#endif
