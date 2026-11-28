/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/GsText_EmitGlyph_1_001E3178.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* round 3 near-miss: ee-gcc, ~70 insns after alignment, 3 short */
#include "common.h"
typedef struct { f32 x0, y0, x1, y1; } __attribute__((aligned(8))) R;
typedef struct { s64 d[4]; } Vt;
typedef struct { Vt v[4]; s32 tag; s32 clip; s32 pad[2]; } Pkt;
typedef struct { s32 x0; s32 p4; u16 x8; } F;
typedef struct { u8 p0[8]; s32 x8; u8 pC[0xC]; u32 x18; Pkt *x1C; u32 x20; s32 x24; F *x28; u16 x2C; } A;
typedef struct { u8 p0[0x10]; Vec x10; Vec x20; f32 x30; f32 x34; u8 p38[8]; f32 x40; f32 x44; u8 p48[8]; s32 x50; s32 x54; s32 x58; s32 p5C; f32 x60; u8 p64[0xC]; f32 x70; f32 x74; f32 x78; f32 x7C; } S;
typedef struct { f32 x0, x4, x8, xC; s16 x10, x12, x14, x16; } G;
extern A *D_00201E5C;
extern S *D_00201E60;
extern const f32 D_00201B84;
void memset(void *, s32, s32);
void Vu0_CopyQword_3_001DC328(void *, void *);
void GsText_SetVertex_0_001E3758(Pkt *, s32, f32, f32, f32, f32);
void GsText_EmitQuad_1_001E3790(Pkt *);

static inline s32 outside(R r) {
    S *s = D_00201E60;
    if (s->x78 < r.x0 || r.x1 < s->x70 || s->x7C < r.y0 || r.y1 < s->x74) return 1;
    return 0;
}

static inline R mkr(f32 x0, f32 y0, f32 x1, f32 y1) { R t; t.x0 = x0; t.y0 = y0; t.x1 = x1; t.y1 = y1; return t; }
static inline s32 outs2(R q) {
    if (D_00201E60->x78 < q.x0 || q.x1 < D_00201E60->x70 || D_00201E60->x7C < q.y0 || q.y1 < D_00201E60->x74) return 1;
    return 0;
}
static inline void clip(Pkt *k, R q) {
    if (D_00201E60->x78 < q.x0 || q.x1 < D_00201E60->x70 || D_00201E60->x7C < q.y0 || q.y1 < D_00201E60->x74) k->clip = 1; else k->clip = 0;
}
s32 GsText_EmitGlyph_1_001E3178(G *g) {
    Vec save;
    Vec uv0;
    Vec uv1;
    Vec a;
    Vec b;
    Pkt pkt;
    f32 o;
    s32 n;
    Pkt *p;
    Pkt **pp;

    memset(&a, 0, 0x10);
    a.w = 1.0f;
    memset(&b, 0, 0x10);
    b.w = 1.0f;
    o = 0.0f;
    if (D_00201E5C->x28->x0 == 0x200 && g->x16 != D_00201E5C->x2C) {
        D_00201E5C->x2C = g->x16;
    }
    if (D_00201E60->x50 != 0) {
        Vu0_CopyQword_3_001DC328(&save, &D_00201E60->x10);
        D_00201E60->x50 = 0;
        GsText_EmitGlyph_1_001E3178(g);
        D_00201E60->x50 = 1;
        Vu0_CopyQword_3_001DC328(&D_00201E60->x10, &save);
        if (D_00201E60->x58 != 0) {
            D_00201E60->x20.x += D_00201E60->x30 * D_00201E60->x40;
        } else {
            D_00201E60->x10.x += D_00201E60->x30;
        }
    }
    uv0.x = g->x0;
    uv0.y = g->x4;
    uv1.x = g->x8;
    uv1.y = g->xC;
    if (D_00201E60->x58 != 0) {
        n = g->x10 < 0 ? 0 : g->x10;
        D_00201E60->x20.x += (f32)n * D_00201E60->x30 * D_00201E60->x40;
        a.x = D_00201E60->x20.x - D_00201B84;
        b.x = (f32)g->x12 * D_00201E60->x30 * D_00201E60->x40 + (D_00201E60->x20.x - D_00201B84);
        a.y = D_00201E60->x20.y - D_00201B84;
        b.y = (D_00201E60->x20.y - D_00201B84) + (f32)D_00201E5C->x28->x8 * D_00201E60->x34 * D_00201E60->x44;
        D_00201E60->x20.x += (f32)g->x14 * D_00201E60->x30 * D_00201E60->x40;
    } else {
        D_00201E60->x20.x = D_00201E60->x10.x;
        D_00201E60->x20.y = D_00201E60->x10.y - (f32)D_00201E5C->x28->x8 * D_00201E60->x34 * D_00201E60->x44;
        n = g->x10 < 0 ? 0 : g->x10;
        D_00201E60->x10.x += (f32)n * D_00201E60->x30;
        a.x = D_00201E60->x10.x - D_00201B84;
        b.x = (f32)g->x12 * D_00201E60->x30 + (D_00201E60->x10.x - D_00201B84);
        a.y = D_00201E60->x10.y - D_00201B84;
        b.y = (D_00201E60->x10.y - D_00201B84) + (f32)D_00201E5C->x28->x8 * D_00201E60->x34;
        D_00201E60->x10.x += (f32)g->x14 * D_00201E60->x30;
    }
    clip(&pkt, mkr(a.x + o, a.y, b.x + o, b.y));
    if (pkt.clip == 1) {
        return 0;
    }
    o = (f32)D_00201E60->x54 * D_00201E60->x60 * D_00201E60->x30;
    GsText_SetVertex_0_001E3758(&pkt, 0, a.x + o, a.y, uv0.x, uv0.y);
    GsText_SetVertex_0_001E3758(&pkt, 1, b.x + o, a.y, uv1.x, uv0.y);
    GsText_SetVertex_0_001E3758(&pkt, 2, a.x, b.y, uv0.x, uv1.y);
    GsText_SetVertex_0_001E3758(&pkt, 3, b.x, b.y, uv1.x, uv1.y);
    pkt.tag = D_00201E5C->x2C;
    if (D_00201E5C->x8 != 0) {
        GsText_EmitQuad_1_001E3790(&pkt);
    }
    pp = &D_00201E5C->x1C;
    p = *pp;
    if (p != 0) {
        *p = pkt;
        *pp = p + 1;
        D_00201E5C->x24++;
        if ((u32)D_00201E5C->x1C >= D_00201E5C->x18 + D_00201E5C->x20) {
            D_00201E5C->x1C = 0;
        }
    }
    return 1;
}
#else
INCLUDE_ASM(GsText_EmitGlyph_1_001E3178);
#endif
