/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Mdl_DrawMeshes_1_0016C7E0.c. The matching build takes it from the assembly of
 * Mdl_ClipFrustum_0_0016BD00. */
#ifdef NONMATCHING
#include "common.h"
typedef struct {
    u16 b0:1; u16 b1:1; u16 b2:1; u16 b3:1; u16 b4:1; u16 b5:1; u16 b6:1; u16 k:4; u16 c3:1; u16 c4:1; u16 c5:3;
    u8 d0:1; u8 d1:1; u8 d2:1; u8 d3:1; u8 d4:1; u8 d5:1; u8 d6:2;
    u8 e;
} F;
typedef struct {
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:7;
    u8 pad[2];
} G;
typedef struct { u16 x0; u8 p2[8]; u16 xA; u8 pC[3]; u8 xF; u8 p10[0xC]; f32 x1C; } Ent;
typedef struct { s32 x0; s32 x4; u8 p8[8]; } E16;
typedef struct {
    u8 p0[0xC]; f32 xC; s32 *x10; u16 x14; u16 x16; u8 p18[0xC]; s32 x24; u8 p28[0x14]; Flags8 x3C; u8 p3D[3];
    E16 e[1];
} Obj;
typedef struct { u8 p0[0x24]; Flags8_6x2 x24; } Oth;
typedef struct { u8 pad[0x134]; f32 x134; } M;
extern Flags8 D_00222A50[];
extern s32 gModelDrawSbss_00201F48;
extern s32 gModelEmitSbss_00201F4C;
extern s32 gModelEmitSbss_00202008;
void sceVu0CopyVector(Vec *, void *);
void sceVu0ApplyMatrix(Vec *, M *, Vec *);
s32 Gfx_SphereInFrustum_1_00153FA0(Vec *);
void Mdl_SetBlendMode_1_0016F280(F);
void Mdl_EmitStrip_1_0016DED0(Ent *, Oth *, u8 *, F);
void Mdl_BindTexture_0_0016F440(Obj *, Oth *, u8 *, s32, G *);
void Mdl_EmitPolys_1_0016EF70(Ent *, u8 *, u8 *, u32, s32, G);
void Mdl_EmitMeshVu1B_1_0016EB70(Ent *, u8 *, u8 *, u32, M *, s32, s32, G);
void Mdl_EmitMeshVu1_1_0016E760(Ent *, u8 *, u8 *, u32, M *, s32, s32, u8 *, Obj *, Oth *, G);

void Mdl_DrawMeshes_1_0016C7E0(Obj *o, Oth *oth, u8 *ctx, F f) {
    u8 *verts;
    u32 i;
    s32 r;
    Ent *ent;
    u8 *arr;
    u8 ii;
    s32 nb;
    s32 base;
    E16 *pes;
    u8 *tex;
    M *mt;
    s32 m;
    u32 n;
    u8 *e;
    F g;
    G h;
    F t;
    E16 *pe;
    G hc;
    s32 z;
    Vec V;

    base = *o->x10;
    nb = o->x10[1] - base;
    tex = (u8 *)(base + o->x24);
    pes = o->e;
    mt = (M *)(ctx + 0xC0);
    g = f;
    *(s32 *)&h = 0;
    z = 0;
    h.b0 = 1;
    h.c0 = f.d5;
    h.b1 = z;
    h.b2 = z;
    h.b3 = z;
    h.b4 = 1;
    h.b5 = z;
    h.b6 = z;
    h.b7 = z;
    m = 2;
    if (oth->x24.f.b6) return;
    t = f;
    gModelEmitSbss_00202008 = gModelEmitSbss_00201F4C;
    if (!D_00222A50[0].f.b1) {
        if ((t.k | t.c3 | t.c4) == 0 && o->x3C.f.b6) {
            gModelEmitSbss_00202008 = gModelDrawSbss_00201F48;
        }
    }
    if (!oth->x24.f.b1) return;
    if (o->x16 == 0) {
        if (D_00222A50[0].f.b3) {
            m = 2;
        } else {
            sceVu0CopyVector(&V, o);
            V.w = 1.0f;
            sceVu0ApplyMatrix(&V, mt, &V);
            V.w = o->xC * (mt)->x134;
            m = Gfx_SphereInFrustum_1_00153FA0(&V);
        }
        if (m < 0) return;
    }
    for (i = 0; i < o->x14; i++) {
        if (i == 1) {
            f.b6 = 1;
            Mdl_SetBlendMode_1_0016F280(f);
        } else {
            f = g;
            Mdl_SetBlendMode_1_0016F280(g);
        }
        ii = i;
        r = m;
        pe = &pes[ii];
        e = ctx + (ii + 1) * 0x140;
        ent = (Ent *)(base + pe->x0);
        verts = (u8 *)(base + pe->x4);
        n = ent->x0;
        if (((Flags8 *)(e + 0x1F8))->f.b3) continue;
        if (((Flags8 *)(e + 0x1F8))->f.b5) continue;
        arr = (u8 *)ent + 0x10;
        if (ent->xF & 1) {
            if (r == 2) {
                if (D_00222A50[0].f.b3) {
                    r = 2;
                } else {
                    Vec V2;
                    sceVu0CopyVector(&V2, arr);
                    V2.w = 1.0f;
                    sceVu0ApplyMatrix(&V2, (M *)(e + 0xC0), &V2);
                    V2.w = ent->x1C * ((M *)(e + 0xC0))->x134;
                    r = Gfx_SphereInFrustum_1_00153FA0(&V2);
                }
                if (r < 0) continue;
            }
            arr += 0x10;
        }
        Mdl_EmitStrip_1_0016DED0(ent, oth, ctx, f);
        if (ent->xA == 0xFFFF && oth->x24.f.b3) {
            Mdl_EmitMeshVu1_1_0016E760(ent, arr, verts, n, (M *)(ctx + 0xC0 + ii * 0x140 + 0x140), r, nb, tex, o, oth, h);
        } else {
            Mdl_BindTexture_0_0016F440(o, oth, tex + ent->xA * 64, nb, &h);
            hc = h;
            if (r < 2 && !hc.b5) {
                Mdl_EmitPolys_1_0016EF70(ent, arr, verts, n, nb, hc);
            } else {
                Mdl_EmitMeshVu1B_1_0016EB70(ent, arr, verts, n, (M *)(ctx + 0xC0 + ii * 0x140 + 0x140), r, nb, hc);
            }
        }
    }
}
#endif
