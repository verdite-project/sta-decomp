#include "common.h"
#include "m2c.h"
#include "game/collision.h"
#include "game/data.h"
#include "game/gfx.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_Mdl_EmitStrip_1_0016DED0;
typedef union { u32 w; f32 f; struct { u16 p0:7; u16 a:4; u16 b11:1; u16 b12:1; u16 p1:3; u16 hi; } s; } P4;
typedef struct { u8 lo:3; u8 mid:3; u8 hi:2; } BF_Mdl_EmitStrip_1_0016DED0;
typedef struct { u8 pad[5]; u8 idx; u8 list[8]; BF_Mdl_EmitStrip_1_0016DED0 f; } A0_Mdl_EmitStrip_1_0016DED0;
typedef struct { u8 pad[0x24]; Flags8 f; } A1_Mdl_EmitStrip_1_0016DED0;
typedef struct { u8 pad[0x100]; u8 m[0x10]; u8 x110[0x28]; Flags8 x138; u8 pad2[7]; } E_Mdl_EmitStrip_1_0016DED0;
typedef struct { u8 pad[0xB0]; u32 base; u8 pad2[0x200 - 0xB4]; E_Mdl_EmitStrip_1_0016DED0 e[1]; } A2_Mdl_EmitStrip_1_0016DED0;
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_Mdl_EmitMeshVu1_1_0016E760;
typedef Bits8 F_Mdl_EmitMeshVu1_1_0016E760;
typedef struct { u16 x0, x2, x4, x6, x8; u8 padA[6]; } E_Mdl_EmitMeshVu1_1_0016E760;
typedef struct { E_Mdl_EmitMeshVu1_1_0016E760 e; Vec v; } E2;
typedef struct { u8 pad[0xF]; u8 b0:1; u8 b1:1; } H_Mdl_EmitMeshVu1_1_0016E760;
typedef struct { u8 pad[0x134]; f32 x134; } M_Mdl_EmitMeshVu1_1_0016E760;
typedef union { u128 q; u32 w[4]; } Q_Mdl_EmitMeshVu1B_1_0016EB70;
typedef union { u64 d[2]; u128 q; } T_Mdl_EmitMeshVu1B_1_0016EB70;
typedef struct { u8 pad0[2]; u16 x2; u16 x4; u8 pad6[2]; u16 x8; u8 padA[6]; } H_Mdl_EmitMeshVu1B_1_0016EB70;
typedef struct { H_Mdl_EmitMeshVu1B_1_0016EB70 h; Vec x10; } E32_Mdl_EmitMeshVu1B_1_0016EB70;
typedef struct { u8 pad0[0xF]; Flags8 xF; } P;
typedef struct { u8 pad0[0x134]; f32 x134; } M_Mdl_EmitMeshVu1B_1_0016EB70;
typedef struct { Flags8 f; u8 pad[3]; } F4;
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q_Mdl_EmitPolys_1_0016EF70;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; u8 pad[3]; } F_Mdl_EmitPolys_1_0016EF70;
typedef struct { u8 pad[0xF]; F_Mdl_EmitPolys_1_0016EF70 f; } Obj_Mdl_EmitPolys_1_0016EF70;
typedef struct { u16 x0; u16 x2; u16 x4; u16 x6; u16 x8; u16 xA; u16 xC; u16 xE; } E16;
typedef struct { E16 e; u8 pad[0x10]; } E32_Mdl_EmitPolys_1_0016EF70;
typedef struct { u8 pad[0x20]; } T_Mdl_EmitPolys_1_0016EF70;
typedef struct {
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 pad1;
    u8 c0:1; u8 c1:2; u8 c3:5;
    u8 pad3;
} Arg;
typedef struct { char pad[0x2C]; s32 v; char p2[0xC]; unsigned char : 3; unsigned char f : 1; } Obj_Mdl_SetDrawFlag_0_0016F410;
typedef union { u128 q; u32 w[4]; } Q_Mdl_BindTexture_0_0016F440;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; u8 c0:1; u8 c1:7; } F_Mdl_BindTexture_0_0016F440;
typedef struct { u8 pad[0x28]; u8 t:3; u8 r:5; } Tex;
typedef struct {
    u8 pad[0x18]; s16 x, y, z; u8 pad1E[6];
    u32 g0:1; u32 g1:1; u32 g2:1; u32 g3:1; u32 A:2; u32 B:2; u32 C:2; u32 D:2; u32 fix:8; u32 rest:12;
    u64 x28; u64 x30; Tex *x38;
} A2_Mdl_BindTexture_0_0016F440;
typedef struct { u8 pad[0x24]; u8 g0:4; u8 g4:1; u8 g5:3; } A1_Mdl_BindTexture_0_0016F440;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x18]; s32 x2C; u8 pad30[0xC]; u8 g0:4; u8 g4:1; u8 g5:3; } A0_Mdl_BindTexture_0_0016F440;
typedef Bits8 BF_Mdl_BindTexture_0_0016F440;
extern Flags8 D_00222A50[];
extern Flags8 D_00222A51[];
extern u8 D_001F2110[];
extern Q_Mdl_EmitMeshVu1_1_0016E760 D_0042DDC0[][2];
extern Q_Mdl_EmitMeshVu1_1_0016E760 D_0042D8C0[][2];
extern u32 D_00201F4C;
extern u32 D_00202008;
#ifndef NONMATCHING
extern u8 D_00201CBC[4];
#else
/* data twins (src/game/data/sdata.c): D_00201CBC */
static u8 D_00201CBC[0x4] = { 0, 0x10, 0x20, 0x40 };
#endif
extern A2_Mdl_BindTexture_0_0016F440 D_00222790[];
extern s8 D_001FB8F8[];
void Mdl_EmitStrip_1_0016DED0(A0_Mdl_EmitStrip_1_0016DED0 *a0, A1_Mdl_EmitStrip_1_0016DED0 *a1, A2_Mdl_EmitStrip_1_0016DED0 *a2, P4 a3);
void Mdl_EmitMeshVu1_1_0016E760(H_Mdl_EmitMeshVu1_1_0016E760 *h, E2 *arr, u8 *verts, u32 n, M_Mdl_EmitMeshVu1_1_0016E760 *mtx, s32 mode, s32 off, u8 *tex, s32 a8, s32 a9, F_Mdl_EmitMeshVu1_1_0016E760 f);
void Mdl_EmitMeshVu1B_1_0016EB70(P *pp, s8 *a1, Vec *fp, u32 n, M_Mdl_EmitMeshVu1B_1_0016EB70 *mt, s32 mode, s32 off, F4 f);
void Mdl_EmitPolys_1_0016EF70(Obj_Mdl_EmitPolys_1_0016EF70 *a0, E16 *a1, u8 *a2, u32 cnt, s32 off, F_Mdl_EmitPolys_1_0016EF70 f);
void Mdl_SetBlendMode_1_0016F280(Arg a);
void Mdl_SetDrawFlag_0_0016F410(Obj_Mdl_SetDrawFlag_0_0016F410 *o, s32 v, int f);
void Mdl_BindTexture_0_0016F440(A0_Mdl_BindTexture_0_0016F440 *a0, A1_Mdl_BindTexture_0_0016F440 *a1, A2_Mdl_BindTexture_0_0016F440 *a2, s32 a3, F_Mdl_BindTexture_0_0016F440 *f);
Q_Mdl_EmitStrip_1_0016DED0* GsPkt_Alloc_3_00154A80(s32);
void sceVu0CopyVector(void *, void *);
s32 Gfx_SphereInFrustum_1_00153FA0(Vec *);
void sceVu0ApplyMatrix(Vec*, void *, Vec*);
void GsPkt_SetReg_3_001543E0(s32, s64);
Tex* Tex_Find_1_00177AF0(u64, s32);
Tex* Tex_FindByHash_1_00177B20(u64);
void Tex_Bind_1_00176B10(Tex *);
s32 Fx_DrawSprites_0_00163FF0(u32, s32, Vec *);

/* Mdl_EmitStrip_1_0016DED0 */
void Mdl_EmitStrip_1_0016DED0(A0_Mdl_EmitStrip_1_0016DED0 *a0, A1_Mdl_EmitStrip_1_0016DED0 *a1, A2_Mdl_EmitStrip_1_0016DED0 *a2, P4 a3) {
    Q_Mdl_EmitStrip_1_0016DED0 q;
    Q_Mdl_EmitStrip_1_0016DED0 r;
    P4 s;
    u32 n;
    u32 p;
    u32 i;
    u32 t;
    u8 c;

    n = a0->f.hi;
    if (!a1->f.f.b5) n = 0;
    p = (u32)GsPkt_Alloc_3_00154A80(n + 5 + (a0->f.lo != 0));
    q.q = 0;
    q.w[0] = 0x30000004;
    q.w[1] = (u32)&a2->e[a0->idx] + a2->base;
    q.w[3] = (0 * 4 + 0x18) | 0x6C040000;
    *(u128 *)p = q.q;
    p += 16;
    if (a2->e[a0->idx].x138.f.b6) {
        for (i = 0; i < n; i++) {
            q.w[0] = 0x30000004;
            q.w[1] = (u32)&a2->e[a0->idx] + a2->base;
            q.w[3] = ((i + 1) * 4 + 0x18) | 0x6C040000;
            *(u128 *)p = q.q;
            p += 16;
        }
    } else {
        for (i = 0; i < n; i++) {
            q.w[0] = 0x30000004;
            q.w[1] = (u32)&a2->e[a0->list[i]] + a2->base;
            q.w[3] = ((i + 1) * 4 + 0x18) | 0x6C040000;
            *(u128 *)p = q.q;
            p += 16;
        }
    }
    if ((c = a0->f.lo) != 0) {
        q.w[0] = ((c >> 2) + 1) | 0x30000000;
        q.w[1] = (u32)a2->e[a0->idx].x110 + a2->base;
        q.w[3] = (((a0->f.lo >> 2) + 1) << 16) | 0x6C000038;
        *(u128 *)p = q.q;
        p += 16;
    }
    q.q = 0;
    q.w[0] = 0x10000001;
    q.w[3] = 0x6C010028;
    s = a3;
    t = s.s.a & 3;
    if (t == 0) {
        t = s.s.b11 ? 0x100 : (s.s.b12 ? 0x200 : 0);
    }
    t |= ((s.s.a >> 2) & 3) << 4;
    r.w[0] = t;
    r.w[1] = a0->f.lo;
    r.w[2] = a0->f.mid;
    r.w[3] = n | (D_00222A51[0].f.b3 ? 0 : 4) | (D_00222A50[0].f.b1 ? 8 : 0);
    ((u128 *)p)[0] = q.q;
    ((u128 *)p)[1] = r.q;
    sceVu0CopyVector(a2->e[a0->idx].m, D_001F2110);
    q.q = 0;
    q.w[0] = 0x30000001;
    q.w[1] = (u32)a2->e[a0->idx].m + a2->base;
    q.w[3] = 0x6C010029;
    ((u128 *)p)[2] = q.q;
    q.q = 0;
    q.w[0] = 0x10000000;
    q.w[3] = D_00201F54 | 0x15000000;
    ((u128 *)p)[3] = q.q;
    GsPkt_Commit_1_00154A70();
}

/* Mdl_EmitMeshVu1_1_0016E760 */
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_Mdl_EmitMeshVu1_1_0016E760
extern Q_Mdl_EmitMeshVu1_1_0016E760 *GsPkt_Alloc_3_00154A80__as_Mdl_EmitMeshVu1_1_0016E760(s32);
#define sceVu0CopyVector sceVu0CopyVector__as_Mdl_EmitMeshVu1_1_0016E760
void sceVu0CopyVector__as_Mdl_EmitMeshVu1_1_0016E760(Vec *, Vec *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Mdl_EmitMeshVu1_1_0016E760
void sceVu0ApplyMatrix__as_Mdl_EmitMeshVu1_1_0016E760(Vec *, M_Mdl_EmitMeshVu1_1_0016E760 *, Vec *);
#define Mdl_BindTexture_0_0016F440 Mdl_BindTexture_0_0016F440__as_Mdl_EmitMeshVu1_1_0016E760
void Mdl_BindTexture_0_0016F440__as_Mdl_EmitMeshVu1_1_0016E760(s32, s32, u8 *, s32, F_Mdl_EmitMeshVu1_1_0016E760 *);

void Mdl_EmitMeshVu1_1_0016E760(H_Mdl_EmitMeshVu1_1_0016E760 *h, E2 *arr, u8 *verts, u32 n, M_Mdl_EmitMeshVu1_1_0016E760 *mtx, s32 mode, s32 off, u8 *tex, s32 a8, s32 a9, F_Mdl_EmitMeshVu1_1_0016E760 f) {
    E_Mdl_EmitMeshVu1_1_0016E760 *e;
    s32 m;
    u32 i;
    u8 *vp;
    Q_Mdl_EmitMeshVu1_1_0016E760 *p;
    Q_Mdl_EmitMeshVu1_1_0016E760 q;
    Vec v;

    m = mode;
    for (i = 0; i < n; i++) {
        if (D_00222A18[0] != -1 && D_00222A18[0] != i) continue;
        if (h->b1) {
            m = mode;
            e = &arr[i].e;
            if (m == 2) {
                if (D_00222A50[0].f.b3) {
                    m = 2;
                } else {
                    sceVu0CopyVector(&v, &arr[i].v);
                    v.w = 1.0f;
                    sceVu0ApplyMatrix(&v, mtx, &v);
                    v.w = ((E2 *)e)->v.w * mtx->x134;
                    m = Gfx_SphereInFrustum_1_00153FA0(&v);
                }
                if (m < 0) continue;
            }
        } else {
            e = &((E_Mdl_EmitMeshVu1_1_0016E760 *)arr)[i];
        }
        vp = verts + e->x4 * 16;
        if (e->x0 != 0xFFFF) {
            Mdl_BindTexture_0_0016F440(a8, a9, tex + e->x0 * 64, off, &f);
        }
        if (f.b5) {
            p = GsPkt_Alloc_3_00154A80(4);
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042DDC0[(e->x2 << 5) | (f.b0 << 4) | (f.b1 << 3) | (f.b4 << 2) | (f.b2 << 1) | f.b6];
            q.w[3] = 0x6C028000;
            p[0].q = q.q;
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042D8C0[e->x2];
            q.w[3] = 0x6C0200A6;
            p[1].q = q.q;
            q.q = 0;
            q.w[0] = e->x8 | 0x30000000;
            q.w[1] = (u32)(vp + off);
            p[2].q = q.q;
            q.q = 0;
            q.w[0] = 0x10000000;
            q.w[3] = 0x10000000;
            q.w[2] = D_00201F50 | 0x15000000;
            p[3].q = q.q;
            GsPkt_Commit_1_00154A70();
        } else {
            p = GsPkt_Alloc_3_00154A80(3);
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042DDC0[(e->x2 << 5) | (f.b0 << 4) | (f.b1 << 3) | (f.b4 << 2) | (f.b2 << 1) | f.b6];
            q.w[3] = 0x6C028000;
            p[0].q = q.q;
            q.q = 0;
            q.w[0] = e->x8 | 0x30000000;
            q.w[1] = (u32)(vp + off);
            p[1].q = q.q;
            q.q = 0;
            q.w[0] = 0x10000000;
            if (m < 2) {
                q.w[3] = 0x10000000;
                q.w[2] = D_00202008 | 0x15000000;
            } else {
                q.w[3] = 0x10000000;
                q.w[2] = D_00201F4C | 0x15000000;
            }
            p[2].q = q.q;
            GsPkt_Commit_1_00154A70();
        }
    }
}
#undef GsPkt_Alloc_3_00154A80
#undef sceVu0CopyVector
#undef sceVu0ApplyMatrix
#undef Mdl_BindTexture_0_0016F440

/* Mdl_EmitMeshVu1B_1_0016EB70 */
#define D_00201F4C D_00201F4C__as_Mdl_EmitMeshVu1B_1_0016EB70
extern s32 D_00201F4C__as_Mdl_EmitMeshVu1B_1_0016EB70;
#define D_00201F50 D_00201F50__as_Mdl_EmitMeshVu1B_1_0016EB70
extern s32 D_00201F50__as_Mdl_EmitMeshVu1B_1_0016EB70;
#define D_00202008 D_00202008__as_Mdl_EmitMeshVu1B_1_0016EB70
extern s32 D_00202008__as_Mdl_EmitMeshVu1B_1_0016EB70;
#define D_0042D8C0 D_0042D8C0__as_Mdl_EmitMeshVu1B_1_0016EB70
extern T_Mdl_EmitMeshVu1B_1_0016EB70 D_0042D8C0__as_Mdl_EmitMeshVu1B_1_0016EB70[][2];
#define D_0042DDC0 D_0042DDC0__as_Mdl_EmitMeshVu1B_1_0016EB70
extern T_Mdl_EmitMeshVu1B_1_0016EB70 D_0042DDC0__as_Mdl_EmitMeshVu1B_1_0016EB70[][2];
#define sceVu0CopyVector sceVu0CopyVector__as_Mdl_EmitMeshVu1B_1_0016EB70
void sceVu0CopyVector__as_Mdl_EmitMeshVu1B_1_0016EB70(Vec *, Vec *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Mdl_EmitMeshVu1B_1_0016EB70
void sceVu0ApplyMatrix__as_Mdl_EmitMeshVu1B_1_0016EB70(Vec *, M_Mdl_EmitMeshVu1B_1_0016EB70 *, Vec *);
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_Mdl_EmitMeshVu1B_1_0016EB70
Q_Mdl_EmitMeshVu1B_1_0016EB70 *GsPkt_Alloc_3_00154A80__as_Mdl_EmitMeshVu1B_1_0016EB70(s32);

void Mdl_EmitMeshVu1B_1_0016EB70(P *pp, s8 *a1, Vec *fp, u32 n, M_Mdl_EmitMeshVu1B_1_0016EB70 *mt, s32 mode, s32 off, F4 f) {
    Q_Mdl_EmitMeshVu1B_1_0016EB70 tag;
    Vec v;
    f32 t;
    H_Mdl_EmitMeshVu1B_1_0016EB70 *e;
    s32 cur;
    u32 k;
    Q_Mdl_EmitMeshVu1B_1_0016EB70 *q;

    cur = mode;
    for (k = 0; k < n; k++) {
        if (D_00222A18[0] != -1 && D_00222A18[0] != k) continue;
        if (pp->xF.f.b1) {
            e = &((E32_Mdl_EmitMeshVu1B_1_0016EB70 *)a1)[k].h;
            cur = mode;
            if (mode == 2) {
                if (D_00222A50[0].f.b3) {
                    cur = 2;
                } else {
                    sceVu0CopyVector(&v, &((E32_Mdl_EmitMeshVu1B_1_0016EB70 *)a1)[k].x10);
                    v.w = 1.0f;
                    sceVu0ApplyMatrix(&v, mt, &v);
                    t = ((E32_Mdl_EmitMeshVu1B_1_0016EB70 *)a1)[k].x10.w;
                    v.w = t * mt->x134;
                    cur = Gfx_SphereInFrustum_1_00153FA0(&v);
                }
                if (cur < 0) continue;
            }
        } else {
            e = &((H_Mdl_EmitMeshVu1B_1_0016EB70 *)a1)[k];
        }
        if (f.f.f.b5) {
            s8 *base = (s8 *)&fp[e->x4];
            q = GsPkt_Alloc_3_00154A80(4);
            tag.q = 0;
            tag.w[0] = 0x30000002;
            tag.w[1] = (u32)D_0042DDC0[(e->x2 << 5) | (f.f.f.b0 << 4) | (f.f.f.b1 << 3) | (f.f.f.b4 << 2) | (f.f.f.b2 << 1) | f.f.f.b6];
            tag.w[3] = 0x6C028000;
            q[0].q = tag.q;
            tag.q = 0;
            tag.w[0] = 0x30000002;
            tag.w[1] = (u32)D_0042D8C0[e->x2];
            tag.w[3] = 0x6C0200A6;
            q[1].q = tag.q;
            tag.q = 0;
            tag.w[0] = e->x8 | 0x30000000;
            tag.w[1] = (u32)(base + off);
            q[2].q = tag.q;
            tag.q = 0;
            tag.w[0] = 0x10000000;
            tag.w[3] = 0x10000000;
            tag.w[2] = D_00201F50 | 0x15000000;
            q[3].q = tag.q;
            GsPkt_Commit_1_00154A70();
        } else {
            s8 *base = (s8 *)&fp[e->x4];
            q = GsPkt_Alloc_3_00154A80(3);
            tag.q = 0;
            tag.w[0] = 0x30000002;
            tag.w[1] = (u32)D_0042DDC0[(e->x2 << 5) | (f.f.f.b0 << 4) | (f.f.f.b1 << 3) | (f.f.f.b4 << 2) | (f.f.f.b2 << 1) | f.f.f.b6];
            tag.w[3] = 0x6C028000;
            q[0].q = tag.q;
            tag.q = 0;
            tag.w[0] = e->x8 | 0x30000000;
            tag.w[1] = (u32)(base + off);
            q[1].q = tag.q;
            tag.q = 0;
            tag.w[0] = 0x10000000;
            if (cur < 2) {
                tag.w[3] = 0x10000000;
                tag.w[2] = D_00202008 | 0x15000000;
            } else {
                tag.w[3] = 0x10000000;
                tag.w[2] = D_00201F4C | 0x15000000;
            }
            q[2].q = tag.q;
            GsPkt_Commit_1_00154A70();
        }
    }
}
#undef sceVu0CopyVector
#undef sceVu0ApplyMatrix
#undef GsPkt_Alloc_3_00154A80
#undef D_00201F4C
#undef D_00201F50
#undef D_00202008
#undef D_0042D8C0
#undef D_0042DDC0

/* Mdl_EmitPolys_1_0016EF70 */
#define D_00202008 D_00202008__as_Mdl_EmitPolys_1_0016EF70
extern s32 D_00202008__as_Mdl_EmitPolys_1_0016EF70;
#define D_0042DDC0 D_0042DDC0__as_Mdl_EmitPolys_1_0016EF70
extern T_Mdl_EmitPolys_1_0016EF70 D_0042DDC0__as_Mdl_EmitPolys_1_0016EF70[];
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_Mdl_EmitPolys_1_0016EF70
Q_Mdl_EmitPolys_1_0016EF70 *GsPkt_Alloc_3_00154A80__as_Mdl_EmitPolys_1_0016EF70(s32);

void Mdl_EmitPolys_1_0016EF70(Obj_Mdl_EmitPolys_1_0016EF70 *a0, E16 *a1, u8 *a2, u32 cnt, s32 off, F_Mdl_EmitPolys_1_0016EF70 f) {
    E16 *e;
    u32 i;
    u8 *ad;
    Q_Mdl_EmitPolys_1_0016EF70 *p;
    Q_Mdl_EmitPolys_1_0016EF70 q;
    s32 idx = D_00222A18[0];
    if (idx == -1) {
        p = GsPkt_Alloc_3_00154A80(cnt * 2 + 1);
        for (i = 0; i < cnt; i++) {
            if ((*(Obj_Mdl_EmitPolys_1_0016EF70 *volatile *)&a0)->f.b1) e = (E16 *)&((E32_Mdl_EmitPolys_1_0016EF70 *)a1)[i]; else e = &a1[i];
            ad = a2 + e->x4 * 16;
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042DDC0[e->x2 << 5 | f.b0 << 4 | f.b1 << 3 | f.b4 << 2 | f.b2 << 1 | f.b6];
            if (i != 0) {
                q.w[2] = D_00202008 | 0x15000000;
            }
            q.w[3] = 0x6C028000;
            p[0].q = q.q;
            q.q = 0;
            q.w[0] = e->x8 | 0x30000000;
            q.w[1] = (u32)(ad + off);
            p[1].q = q.q;
            p += 2;
            if (i == cnt - 1) {
                q.q = 0;
                q.w[0] = 0x10000000;
                q.w[3] = 0x10000000;
                q.w[2] = D_00202008 | 0x15000000;
                p[0].q = q.q;
                p++;
            }
        }
        GsPkt_Commit_1_00154A70();
    } else if (idx < (s32)cnt) {
        e = a0->f.b1 ? (E16 *)&((E32_Mdl_EmitPolys_1_0016EF70 *)a1)[idx] : &a1[idx];
        p = GsPkt_Alloc_3_00154A80(3);
        ad = a2 + e->x4 * 16;
        q.q = 0;
        q.w[0] = 0x30000002;
        q.w[1] = (u32)&D_0042DDC0[e->x2 << 5 | f.b0 << 4 | f.b1 << 3 | f.b4 << 2 | f.b2 << 1 | f.b6];
        q.w[3] = 0x6C028000;
        p[0].q = q.q;
        q.q = 0;
        q.w[0] = e->x8 | 0x30000000;
        q.w[1] = (u32)(ad + off);
        p[1].q = q.q;
        q.q = 0;
        q.w[0] = 0x10000000;
        q.w[3] = 0x10000000;
        q.w[2] = D_00202008 | 0x15000000;
        p[2].q = q.q;
        GsPkt_Commit_1_00154A70();
    }
}
#undef GsPkt_Alloc_3_00154A80
#undef D_00202008
#undef D_0042DDC0

/* Mdl_SetBlendMode_1_0016F280 */
void Mdl_SetBlendMode_1_0016F280(Arg a) {
    switch ((a.b5 ? 2 : 0) | (a.b6 ? 1 : 0)) {
    case 0:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, ((u64)D_00201CBC[a.c1] << 4) | 0x5000D);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    case 1:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, 0x51001);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    case 2:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, ((u64)D_00201CBC[a.c1] << 4) | 0x3000D);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    case 3:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, 0x31001);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    }
}

/* Mdl_SetDrawFlag_0_0016F410 */
void Mdl_SetDrawFlag_0_0016F410(Obj_Mdl_SetDrawFlag_0_0016F410 *o, s32 v, int f)
{
    o->v = v;
    o->f = f;
}

/* Mdl_BindTexture_0_0016F440 */
#define D_00222A50 D_00222A50__as_Mdl_BindTexture_0_0016F440
extern BF_Mdl_BindTexture_0_0016F440 D_00222A50__as_Mdl_BindTexture_0_0016F440[];
#define D_00222A51 D_00222A51__as_Mdl_BindTexture_0_0016F440
extern BF_Mdl_BindTexture_0_0016F440 D_00222A51__as_Mdl_BindTexture_0_0016F440[];
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_Mdl_BindTexture_0_0016F440
extern Q_Mdl_BindTexture_0_0016F440 *GsPkt_Alloc_3_00154A80__as_Mdl_BindTexture_0_0016F440(s32);
#define GsPkt_SetReg_3_001543E0 GsPkt_SetReg_3_001543E0__as_Mdl_BindTexture_0_0016F440
extern void GsPkt_SetReg_3_001543E0__as_Mdl_BindTexture_0_0016F440(s32, u64);

void Mdl_BindTexture_0_0016F440(A0_Mdl_BindTexture_0_0016F440 *a0, A1_Mdl_BindTexture_0_0016F440 *a1, A2_Mdl_BindTexture_0_0016F440 *a2, s32 a3, F_Mdl_BindTexture_0_0016F440 *f) {
    Q_Mdl_BindTexture_0_0016F440 tag1;
    Vec p;
    Q_Mdl_BindTexture_0_0016F440 tag2;
    union { u64 d; u32 w[2]; u8 b[8]; } n;
    union { u32 w; u8 b[4]; } m;
    Q_Mdl_BindTexture_0_0016F440 *q;

    if (D_00222A51[0].b6) {
        a2 = D_00222790;
    }
    if (f->b7) {
        f->b2 = 1;
        f->b3 = 0;
        f->b6 = 0;
    }
    if (!D_00222A50[0].b2) {
        q = GsPkt_Alloc_3_00154A80(1);
        tag1.q = 0;
        tag1.w[1] = (u32)((s8 *)a2 + a3);
        tag1.w[0] = 0x30000002;
        tag1.w[3] = 0x6D040054;
        q->q = tag1.q;
        GsPkt_Commit_1_00154A70();
    } else {
        q = GsPkt_Alloc_3_00154A80(1);
        tag2.q = 0;
        tag2.w[1] = (u32)((s8 *)a2 + a3);
        tag2.w[0] = 0x30000001;
        tag2.w[3] = 0x6D020054;
        q->q = tag2.q;
        GsPkt_Commit_1_00154A70();
    }
    f->b1 = 0;
    f->b0 = a2->g1;
    if (f->b7) {
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x44);
        GsPkt_EndAD_3_00154420();
    } else {
        f->b2 = a2->g2;
        if (f->b2) {
            GsPkt_BeginAD_3_001545D0();
            GsPkt_SetReg_3_001543E0(0x42, (u64)a2->A | ((u64)a2->B << 2) | ((u64)a2->C << 4) | ((u64)a2->D << 6) | ((u64)a2->fix << 32));
            GsPkt_EndAD_3_00154420();
        }
    }
    if (f->b6) {
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x44);
        GsPkt_EndAD_3_00154420();
    }
    if (a1->g4) {
        f->b5 = 0;
        if (a2->x28 != (u64)-1) {
            if (a2->x38 == 0) {
                if (a0->x2C) {
                    a2->x38 = Tex_Find_1_00177AF0(a2->x28, a0->x2C);
                }
                if (a2->x38 == 0 && a0->g4) {
                    a2->x38 = Tex_Find_1_00177AF0(a2->x28, a0->x10);
                }
                if (a2->x38 == 0) {
                    a2->x38 = Tex_FindByHash_1_00177B20(a2->x28);
                }
            }
            if (a2->x38) {
                Tex_Bind_1_00176B10(a2->x38);
                if (a2->x38->t == 3) {
                    a2->x38 = 0;
                }
                f->b1 = 1;
            }
        }
        if (!f->c0) {
            if (a2->x30 != (u64)-1) {
                n.d = a2->x30;
                if (n.w[0] == (D_001FB8F8[0] | (D_001FB8F8[1] << 8) | (D_001FB8F8[2] << 16) | (D_001FB8F8[3] << 24))) {
                    p.x = 0.000244140625f * a2->x;
                    p.y = 0.000244140625f * a2->y;
                    p.z = 0.000244140625f * a2->z;
                    p.w = 0.0f;
                    m.b[3] = n.b[4] - '0';
                    m.b[2] = n.b[5] - '0';
                    m.b[1] = n.b[6] - '0';
                    m.b[0] = n.b[7] - '0';
                    if (Fx_DrawSprites_0_00163FF0(m.w, D_00201FF0, &p)) {
                        f->b5 = 1;
                    }
                }
            }
        }
    }
    if (f->b3 != a2->g3) {
        f->b3 = a2->g3;
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x49, f->b3);
        GsPkt_EndAD_3_00154420();
    }
}
#undef GsPkt_Alloc_3_00154A80
#undef GsPkt_SetReg_3_001543E0
#undef D_00222A50
#undef D_00222A51

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F4C, D_00201F50, D_00202008 */
u32 D_00201F4C;
u32 D_00201F50;
u32 D_00202008;
/* data twins (src/game/data/texture_bss.c): D_0042D8C0, D_0042DDC0 */
Q_Mdl_EmitMeshVu1_1_0016E760 D_0042D8C0[0x500 / sizeof(Q_Mdl_EmitMeshVu1_1_0016E760[2])][2];
Q_Mdl_EmitMeshVu1_1_0016E760 D_0042DDC0[0xa000 / sizeof(Q_Mdl_EmitMeshVu1_1_0016E760[2])][2];
#endif
