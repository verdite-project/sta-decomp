/* Best-effort C for the NONMATCHING build; the matching attempt is
 * Mdl_DrawWithOverlay_0_0016C350.c (an inline-assembly match in wip/), whose rsqrt.s is
 * a divide by sqrtf here. The matching build takes it from the assembly of
 * Mdl_ClipFrustum_0_0016BD00. */
#ifdef NONMATCHING
#include "common.h"
typedef struct { s32 x0; u8 p4[0xB]; u8 xF; } Ent;
typedef struct { s32 x0; u8 p4[0xC]; } E16;
typedef struct {
    u8 p0[0xC]; f32 xC; s32 *x10; u16 x14; u16 x16; u16 x18; u16 x1A; u16 x1C; u16 x1E; u8 p20[0x20];
    E16 e[1];
} Obj;
typedef struct { u8 p0[0x24]; Flags8 x24; } Oth;
typedef struct { f32 x110; f32 x114; f32 x118; f32 x11C; f32 x120; f32 x124; f32 x128; f32 x12C; } Fr;
typedef struct { Obj *o; Oth *p; s32 i; u8 *e; Vec v; f32 a; f32 b; s32 n; s32 pad; } Rec;
typedef struct { s32 x; } Z;
extern Flags8 D_00222A50[];
extern f32 D_00222A40[];
extern Mtx gMdlDrawWithOverlayBss_002F15C0;
extern f32 gGameMainSdata_00201C18;
extern f32 gGameMainSdata_00201C1C;
void sceVu0Normalize(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 tanf(f32);
s8 Mdl_ClipFrustum_0_0016BD00(u8 *, void *, Vec *, f32 *, Fr *);
void ScreenFx_DrawRestore_0_001327B0(void);
void ScreenFx_DrawLetterbox_0_001325F0(void);
void Mdl_EmitStrip_1_0016DED0(Ent *, Oth *, u8 *, Z);
void Tex_FlushAll_1_00176AE0(void);
void ScreenFx_DrawModelOverlay_0_00132A70(Rec *);
f32 sqrtf(f32);
/* rsqrt.s: n / sqrt(d) */
static inline f32 rsq(f32 n, f32 d) { return n / sqrtf(d); }

void Mdl_DrawWithOverlay_0_0016C350(Obj *obj, Oth *oth, u8 *ctx, Vec *src) {
    u32 n;
    s32 j;
    s32 *base;
    u32 i;
    s8 m;
    Ent *t;
    E16 *pe;
    s32 *pp;
    u8 *e;
    s8 r;
    f32 a;
    f32 b;
    f32 k;
    f32 k2;
    f32 s;
    f32 s2;
    Z z;
    Vec u;
    Fr fr;
    Vec v;
    Rec rec;

    if (D_00222A50[0].f.b6) return;
    if (!oth->x24.f.b1) return;
    if (!obj->x1E) return;
    v.x = src->x;
    v.y = src->y;
    v.z = src->z;
    v.w = 0.0f;
    sceVu0Normalize(&v, &v);
    u.x = gMdlDrawWithOverlayBss_002F15C0.m[0].x * v.x + gMdlDrawWithOverlayBss_002F15C0.m[1].x * v.y + gMdlDrawWithOverlayBss_002F15C0.m[2].x * v.z;
    u.y = gMdlDrawWithOverlayBss_002F15C0.m[0].y * v.x + gMdlDrawWithOverlayBss_002F15C0.m[1].y * v.y + gMdlDrawWithOverlayBss_002F15C0.m[2].y * v.z;
    u.z = gMdlDrawWithOverlayBss_002F15C0.m[0].z * v.x + gMdlDrawWithOverlayBss_002F15C0.m[1].z * v.y + gMdlDrawWithOverlayBss_002F15C0.m[2].z * v.z;
    sceVu0Normalize(&u, &u);
    u.w = 2.0f * (D_00222A50[0].f.b3 ? 500.0f : obj->xC);
    s = tanf(1.5f * (3.1415927f * D_00222A40[0]) / 360.0f);
    k = 1.0f / s;
    k2 = k * k;
    s2 = 0.48999998f;
    s2 = rsq(1.0f, k2 + s2);
    s = rsq(1.0f, 1.0f + k2);
    fr.x120 = k * s;
    fr.x128 = k * s2;
    fr.x118 = gGameMainSdata_00201C18;
    fr.x124 = s;
    fr.x12C = 0.7f * s2;
    fr.x11C = gGameMainSdata_00201C1C;
    if (D_00222A50[0].f.b3) {
        m = 2;
    } else {
        m = Mdl_ClipFrustum_0_0016BD00(ctx + 0x200, obj, &u, (f32 *)((u8 *)&fr + 0x10), &fr);
        if (m < 0) return;
        u.w = u.w * (fr.x110 + fr.x114);
    }
    ScreenFx_DrawRestore_0_001327B0();
    base = (s32 *)*obj->x10;
    pe = obj->e;
    n = obj->x14;
    i = 0;
    pp = (s32 *)((u8 *)&pe[n] + obj->x16 * 8 + obj->x18 * 4 + obj->x1C * 0x50);
    for (; i < n; i++, pe++, pp++) {
        b = u.w;
        a = 0.0f;
        e = ctx + (i + 1) * 0x140;
        if (((Flags8 *)(e + 0x1F8))->f.b3) continue;
        if (((Flags8 *)(e + 0x1F8))->f.b5) continue;
        {
            t = (Ent *)((u8 *)base + pe->x0);
            if ((t->xF & 1) && m == 2) {
                r = Mdl_ClipFrustum_0_0016BD00(e + 0xC0, (u8 *)t + 0x10, &u, (f32 *)((u8 *)&fr + 0x10), &fr);
                if (r < 0) continue;
                a = u.w * fr.x110;
                b = u.w * fr.x114;
            }
            z.x = 0;
            Mdl_EmitStrip_1_0016DED0(t, oth, ctx, z);
            Tex_FlushAll_1_00176AE0();
            rec.o = obj;
            rec.p = oth;
            rec.i = i;
            rec.e = (u8 *)base + *pp;
            v.w = u.w;
            sceVu0CopyVector(&rec.v, &v);
            rec.a = a;
            rec.b = b;
            rec.n = obj->x10[1] - obj->x10[0];
            ScreenFx_DrawModelOverlay_0_00132A70(&rec);
        }
    }
    ScreenFx_DrawLetterbox_0_001325F0();
}
/* data group (src/game/data/gs_packet_bss.c): gMdlDrawWithOverlayBss_002F15C0__grp: gMdlDrawWithOverlayBss_002F15C0@0x0, gMdlDrawWithOverlayBss_002F15C4@0x4, gMdlDrawWithOverlayBss_002F15C8@0x8, gMdlDrawWithOverlayBss_002F15D0@0x10, gMdlDrawWithOverlayBss_002F15D4@0x14, gMdlDrawWithOverlayBss_002F15D8@0x18, gMdlDrawWithOverlayBss_002F15E0@0x20, gMdlDrawWithOverlayBss_002F15E4@0x24 */
unsigned char gMdlDrawWithOverlayBss_002F15C0__grp[0x40] __attribute__((aligned(16)));
#endif
