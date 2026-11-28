/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/MapObj_SetAnimFrame_0_001B87C0.c.
 * The matching build takes it from the assembly of MapObj_PlayAnimImpl_1_001B8350. */
#ifdef NONMATCHING
// NEAR 4/165: still t1/a2 swap on lw 0x180 base + sll/addu (retail: base t1, off a2, addu a1,a1,a2). Tried stmt/decl perms, struct p, inline getters, E80 index, b38, idx via E30* temp (fixes addu order but 6 words).
#include "m2c.h"
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { s8 pad[0x18]; u16 x18; s8 pad1A[0x16]; } E30;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } F8;
typedef struct { s8 pad0[0xC]; f32 xC; f32 x10; s8 pad14[0xC]; f32 x20; } Obj;
void Mdl_SetBoneRotation_0_001710D0(Obj *obj, s16 a1, f32 a, f32 b, f32 c);
f32 Mdl_GetMotionLength_0_00173F70(s8 *, u16);

void MapObj_SetAnimFrame_0_001B87C0(s8 *p, u32 a1, s32 a2, s32 a3, f32 f, f32 g) {
    s8 *e;
    Obj *ob;
    s8 **q;
    Obj **pp;
    u16 k;
    u16 idx;
    s8 *tbl;
    s8 *t;
    s8 *s;
    f32 r;

    if (p == NULL || a1 >= *(u16 *)(p + 0x6E)) {
        return;
    }
    e = *(s8 **)(p + 0x180) + (a1 << 7);
    idx = (*(E30 **)(p + 0x138))[a1].x18;
    tbl = *(s8 **)(p + 0x170);
    t = tbl + (idx << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF3 *)(t + 0x12))->v) {
        k = *(u16 *)(tbl + (*(u16 *)(t + 6) << 6));
        pp = *(Obj ***)(e + 0x44);
    } else {
        pp = *(Obj ***)(e + 0x40);
        k = idx;
    }
    ob = *pp;
    q = *(s8 ***)ob;
    s = *(s8 **)(p + 0x194) + k * 0x10;
    if (q == NULL || *q == NULL) {
        return;
    }
    if (*(u16 *)(*q + 0x16) <= 0) {
        return;
    }
    if (a2 < 0 || (u32)a2 >= *(u32 *)(s + 4)) {
        return;
    }
    a2 = (*(u8 **)(s + 8))[a2];
    if (a2 == 0xFF) {
        return;
    }
    Mdl_SetBoneRotation_0_001710D0(ob, a2, g, 0.0f, 0.0f);
    ((F8 *)(e + 0x50))->b2 = 1;
    ((F8 *)(e + 0x50))->b4 = 0;
    r = Mdl_GetMotionLength_0_00173F70(*q, a2);
    if (a3 & 0x80) {
        ((F8 *)(e + 0x50))->b3 = 1;
    } else {
        ((F8 *)(e + 0x50))->b3 = 0;
    }
    if (a3 & 0x40) {
        ((F8 *)(e + 0x50))->b5 = 1;
    } else {
        ((F8 *)(e + 0x50))->b5 = 0;
    }
    if (!(a3 & 1)) {
        ob->xC = f;
        ob->x10 = f;
        ob->x20 = ob->xC;
    } else {
        ob->xC = r - f;
        if (ob->xC < 0.0f) {
            ob->xC = 0.0f;
        }
        ob->x10 = ob->xC;
        ob->x20 = ob->xC;
    }
}
#endif
