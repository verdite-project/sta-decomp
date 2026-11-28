/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Sfx_DrawBillboard_0_00168480.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: 67 of 368 words differ (was 75). Change: a1 -= a0 moved into the then-block.
   Remaining: (1) retail does sub.s f0,f20,f21 (fresh temp) in the bc1f delay slot of if (0.0f < f) and the else (g = 1.0f) gets its own lui + pad nop;
   (2) if (fl) f = 200.0f: retail has no pad nop before the swc1 at the skip target, and the following tag constant setup is scheduled differently
   (a ternary fixes the following schedule but adds b + extra mtc1, 370 words). */
#include "actor.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct {
    u32 t:3; u32 b3:1; u32 A:2; u32 B:2; u32 C:2; u32 D:2; u32 fix:8; u32 b20:1; u32 r:11;
    u8 e0:5; u8 e5:1; u8 e6:1; u8 e7:1;
} S;
typedef struct { u8 pad[7]; u8 g0:7; u8 g7:1; u8 pad8[2]; u8 a0:1; u8 a1:7; u8 padB[0x39]; f32 x44; } M;
typedef struct { u8 pad[8]; u16 x8; u8 padA[6]; s8 *x10; } Sub;
typedef struct { u8 pad[0x8C]; f32 x8C; } X210;
typedef struct { u8 pad[0x17C]; f32 x17C; u8 pad180[8]; u8 g0:2; u8 g2:1; u8 g3:5; u8 pad189[0x87]; X210 *x210; } E;
typedef struct { u8 pad[0x4C]; f32 x4C; u8 pad50[0x120 - 0x50]; } B;
typedef struct { f32 x, y, z; u8 pad[0x2B - 12]; u8 a; u8 pad2[4]; } C;
typedef struct { C c[2]; } CC;
typedef struct { u16 prev; u16 next; u16 x4; } L;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; f32 x28; f32 x2C; } R;
extern s32 gSfxAllSbss_00201F2C;
extern s32 gSfxDrawBillboardSbss_00201F40;
extern B *gSfxSystemSbss_00201FC0;
extern CC *gSfxAllSbss_00201FD0;
extern L *gSfxSystemSbss_00201FD4;
extern f32 gMatrixFromData_001F2160[];
extern Q *GsPkt_Alloc_3_00154A80(s32);
extern void GsPkt_SetReg_3_001543E0(s32, u64);
extern void GsPkt_EndAD_3_00154420(void);
extern void GsPkt_Flush_1_001544C0(void);
extern void GsPkt_BeginAD_3_001545D0(void);
extern void GsPkt_CloseChain_1_001549D0(void);
extern void Tex_Bind_1_00176B10(s8 *);
extern void Gfx_ResetBlendState_0_00145790(void);
extern R *Map_GetDefaultLight_0_001B72F0(void);
extern f32 Vec_Distance_3_00146940(void *, Vec *);
static inline f32 u2f(u32 x) { return x; }
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

void Sfx_DrawBillboard_0_00168480(E *e, Sub *sub, M *m, S *s) {
    Vec t;
    Q tag;
    u64 tes;
    u64 tst;
    u8 ca;
    u8 b;
    s32 alt;
    u8 d;
    u8 cc;
    u8 fix;
    u8 th;
    u8 ab;
    u16 idx;
    B *bp;
    CC *cp;
    C *c;
    u8 *pa;
    R *r;
    f32 lo;
    f32 hi;
    f32 a0;
    f32 a1;
    f32 f;
    f32 g;
    void *ap;
    s32 ok;
    s32 fl;
    s32 ofs;

    if (s->t == 1 && sub->x10) {
        Tex_Bind_1_00176B10(sub->x10);
        GsPkt_CloseChain_1_001549D0();
    }
    alt = 0;
    if (m->x44 == 0.0f && !(e->g2 != 0) != 0) {
        alt = 1;
    }
    ab = s->e5 ? 1 : 3;
    tes = ((u64)ab << 17) | 0x11011;
    tst = ((u64)s->e6 << 32) | 0x3A000118;
    ca = s->A;
    b = s->B;
    cc = s->C;
    d = s->D;
    fix = s->fix;
    th = s->b20;
    if (alt) {
        cc = 2;
        fix = 0;
    }
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4E, tst);
    GsPkt_SetReg_3_001543E0(0x47, tes);
    GsPkt_SetReg_3_001543E0(0x42, (u64)ca | ((u64)b << 2) | ((u64)cc << 4) | ((u64)d << 6) | ((u64)fix << 32));
    GsPkt_SetReg_3_001543E0(0x49, th);
    GsPkt_Flush_1_001544C0();
    for (idx = sub->x8; idx != 0xFFFF; idx = gSfxSystemSbss_00201FD4[idx].x4) {
        bp = &gSfxSystemSbss_00201FC0[idx];
        cp = &gSfxAllSbss_00201FD0[idx];
        if (!m->a0) {
            pa = &cp->c[gSfxAllSbss_00201F2C].a;
            t.x = cp->c[gSfxAllSbss_00201F2C].x;
            t.y = cp->c[gSfxAllSbss_00201F2C].y;
            t.z = cp->c[gSfxAllSbss_00201F2C].z;
            t.w = 1.0f;
            r = Map_GetDefaultLight_0_001B72F0();
            lo = r->x20;
            hi = r->x24;
            a0 = r->x28;
            a1 = r->x2C;
            ok = 0;
            if (gPlayerSbss_002022E4 && gPlayerSbss_002022E4->unk518) ok = 1;
            if (ok) {
                ap = gPlayerSbss_002022E4->unk518 + 0x1C0;
            } else {
                ap = gMatrixFromData_001F2160;
            }
            f = (Vec_Distance_3_00146940(ap, &t) - lo) / (hi - lo);
            if (1.0f < f) f = 1.0f;
            if (0.0f < f) {
                a1 -= a0;
                g = 1.0f - (a0 + f * a1);
            } else {
                g = 1.0f;
            }
            if (g < 0.05f) g = 0.05f;
            *pa = e->x17C * (bp->x4C * e->x210->x8C);
            *pa = mu(*pa, g);
        }
        fl = m->g7;
        ofs = gSfxDrawBillboardSbss_00201F40;
        c = &cp->c[gSfxAllSbss_00201F2C];
        {
            Q *q = GsPkt_Alloc_3_00154A80(6);
            tag.q = 0;
            tag.w[0] = 0x10000001;
            tag.w[3] = 0x6C018000;
            q[0] = tag;
            tag.w[0] = 0;
            tag.w[1] = 0;
            f = 0.0f;
            if (fl) f = 200.0f;
            *(f32 *)&tag.w[2] = f;
            tag.w[3] = 0;
            q[1] = tag;
            tag.q = 0;
            tag.w[0] = 0x10000001;
            tag.w[3] = 0x6C01C001;
            q[2] = tag;
            tag.q = 0;
            tag.d[0] = ((u64)0xA0000000 << 32) | 0x8001;
            tag.d[1] = ((u64)0x43 << 32) | 0x434343E0;
            q[3] = tag;
            tag.q = 0;
            tag.w[0] = 0x30000003;
            tag.w[1] = (u32)c;
            tag.w[3] = 0x6C03C002;
            q[4] = tag;
            tag.q = 0;
            tag.w[0] = 0x10000000;
            tag.w[2] = ofs | 0x15000000;
            tag.w[3] = 0x11000000;
            q[5] = tag;
        }
        GsPkt_CloseChain_1_001549D0();
    }
    Gfx_ResetBlendState_0_00145790();
}
#else
INCLUDE_ASM(Sfx_DrawBillboard_0_00168480);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gSfxDrawBillboardSbss_00201F40 */
s32 gSfxDrawBillboardSbss_00201F40;
#endif
