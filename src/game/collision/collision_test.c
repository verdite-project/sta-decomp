#include "common.h"
#include "game/collision.h"
#include "game/data.h"
typedef struct { u8 b0:1; u8 b1:1; } B2;
typedef struct { u8 pad[4]; B2 f; u8 pad5[3]; } Sel;
typedef struct { u8 pad[0x178]; Sel *sel; } Ctx;
typedef struct { u8 pad[0x10]; s32 *x10; u16 x14; u16 x16; u16 x18; u16 x1A; u16 x1C; u8 pad1E[0x22]; u8 x40[1]; } H_Coll_QueryMapCells_0_001520E0;
typedef struct { H_Coll_QueryMapCells_0_001520E0 *m; } O;
typedef struct { O *o; u8 pad4[2]; u16 x6; u8 pad8[0x38]; s8 x40[1]; } A0;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10[8]; u8 pad30[0x20]; } G;
typedef struct { u16 n[8]; u8 pad10[0x10]; Vec sph[8]; } Q;
typedef struct { u16 n; u16 pad; s32 off; u8 p8[8]; Vec sph; } Item;
typedef struct { u8 p0[0xC]; f32 r; u8 p10[0xC]; f32 w; } Ray;
typedef struct { u8 pad[0xE]; s16 hE; Vec v10; Vec v20; } S1;
typedef struct { Vec v0; Vec v10; s32 x20; s32 x24; s32 x28; S1 *x2C; u8 pad30[0xC]; s32 x3C; } H_Coll_TestCellTriangles_1_00152700;
typedef struct { f32 v[3]; } F3 __attribute__((aligned(8)));
extern s32 gGameMainSbss_00201E94;
void Coll_QueryMapCells_0_001520E0(Vec *o, A0 *a, Ray *ray, u8 mask, s32 mode, s32 *pcnt, s32 x6, s32 x7, Ctx *ctx, s32 skip);
s32 Coll_TestCellTriangles_1_00152700(H_Coll_TestCellTriangles_1_00152700 *h, s32 **pp, Vec *s3, s32 a3, s32 *cnt, s32 max, H_Coll_TestCellTriangles_1_00152700 **cur, Vec *out, Vec *out1, Vec *tri,
                  s32 x24, s32 x28, S1 *s1, Mtx *m, f32 *best, s32 idx, s32 flag, s32 x3C);
s32 Coll_TestTriangle_1_00152D90(Vec *out, Vec *s3, Vec *tri, S1 *s1, Mtx *m, s32 idx, s32 flag);
void memset(void *, s32, s32);
void sceVu0CopyMatrix(Mtx *, void *);
void sceVu0CopyVector(Vec*, void *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
void sceVu0SubVector(Vec*, void *, Vec*);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0Normalize(Vec *, Vec *);
s32 Coll_SphereVsPlane_1_00150C00(Vec *, Vec *, Vec *, Vec *, f32 *, f32 *);
void Coll_CapsuleVsRay_1_001511C0(Vec *, Vec *, Vec *, Vec *, Vec *, f32 *);
f32 sqrtf(f32);

/* Coll_QueryMapCells_0_001520E0 */
#define sceVu0SubVector sceVu0SubVector__as_Coll_QueryMapCells_0_001520E0
void sceVu0SubVector__as_Coll_QueryMapCells_0_001520E0(Vec *, Ray *, Vec *);
#define Coll_TestCellTriangles_1_00152700 Coll_TestCellTriangles_1_00152700__as_Coll_QueryMapCells_0_001520E0
s32 Coll_TestCellTriangles_1_00152700__as_Coll_QueryMapCells_0_001520E0(Vec *, A0 *, Ray *, s32, s32 *, s32, s32 *, Vec *, Vec *, Vec *, Q *, Item *, u8 *, Mtx *, f32 *, s32, s32, s32);
static inline s32 inr(Vec *c, f32 r) { r *= r; return sceVu0InnerProduct(c, c) <= r; }

void Coll_QueryMapCells_0_001520E0(Vec *o, A0 *a, Ray *ray, u8 mask, s32 mode, s32 *pcnt, s32 x6, s32 x7, Ctx *ctx, s32 skip) {
    Vec X;
    Vec Y;
    Mtx M;
    Vec T[3];
    Vec C;
    Vec B;
    f32 best;
    H_Coll_QueryMapCells_0_001520E0 *h;
    s32 base;
    u32 k;
    u8 *tbl;
    Q *q;
    u8 *base2;
    s32 j;
    u8 *s;
    Sel *sl;
    u32 idx;
    G *g;
    s32 i;
    u8 *e;
    s32 c0;
    s32 t;
    Item *it;
    u8 *tp;
    Vec *v;
    f32 lim;
    s32 ok;
    f32 r;

    h = a->o->m;
    if (pcnt) *pcnt = 0;
    best = r = 1.0f + ray->r / ray->w;
    memset(o, 0, 0x40);
    base = *h->x10;
    tbl = (u8 *)((s32)h + 0x40) + h->x14 * 16 + h->x16 * 8 + h->x18 * 4;
    for (k = 0; k < 8; k++) {
        if (!((1 << k) & mask)) continue;
        for (j = skip != 0; j < a->x6; j++) {
            s = (u8 *)((s32)a + 0x40) + gSfxAllSbss_00201F2C * (a->x6 * 0x140 + 0x200);
            if (ctx) {
                sl = &ctx->sel[j];
                if (!sl->f.b0) continue;
                if (sl->f.b1) continue;
            }
            idx = s[j * 0x140 + 0x332];
            if (idx == 0xFF) continue;
            if (idx >= h->x1C) continue;
            sceVu0CopyMatrix(&M, s + (j + 1) * 0x140 + 0xC0);
            g = (G *)(tbl + idx * 0x50);
            if (!g->x0) continue;
            if (!g->x10[k]) continue;
            q = (Q *)(base + g->x0);
            it = (Item *)(base + g->x10[k]);
            base2 = (u8 *)(base + g->x4);
            sceVu0CopyVector(&C, (u8 *)q + k * 16 + 0x20);
            C.w = 1.0f;
            sceVu0ApplyMatrix(&C, &M, &C);
            sceVu0SubVector(&C, ray, &C);
            if ((ok = inr(&C, q->sph[k].w + (ray->w + ray->r))) == 0) continue;
            for (i = 0; i < q->n[k]; i++, it++) {
                c0 = 0;
                sceVu0CopyVector(&B, &it->sph);
                B.w = 1.0f;
                sceVu0ApplyMatrix(&B, &M, &B);
                sceVu0SubVector(&B, ray, &B);
                if ((ok = inr(&B, it->sph.w + (ray->w + ray->r))) == 0) continue;
                if (D_00222A18[0] != -1 && i != D_00222A18[0]) continue;
                e = base2 + it->off;
                if (e[0xC] & 1) c0 = 1;
                tp = e + 0x20;
                sceVu0CopyVector(&T[0], e);
                T[0].w = 1.0f;
                sceVu0CopyVector(&T[1], e + 0x10);
                T[1].w = 1.0f;
                sceVu0ApplyMatrix(&T[0], &M, &T[0]);
                sceVu0ApplyMatrix(&T[1], &M, &T[1]);
                for (t = 0; t < it->n - 2; t++, tp += 0x30) {
                    v = &T[(t + 2) % 3];
                    sceVu0CopyVector(v, tp);
                    v->w = 1.0f;
                    sceVu0ApplyMatrix(v, &M, v);
                    if (D_00222A16[0] != -1 && t != D_00222A16[0]) continue;
                    if (Coll_TestCellTriangles_1_00152700(o, a, ray, mode, pcnt, x6, &x7, &X, &Y, T, q, it, tp, &M, &best, t, c0, j) == 1) goto out;
                }
            }
        }
        if (mode == 1 && best < 1.0f) goto out;
    }
out:
    if (best < r) {
        sceVu0CopyVector(o, &X);
        sceVu0CopyVector(o + 1, &Y);
    }
}
#undef sceVu0SubVector
#undef Coll_TestCellTriangles_1_00152700

/* Coll_TestCellTriangles_1_00152700 */
/* Coll_TestCellTriangles_1_00152700 */
#pragma explicit_zero_data on
F3 D_001F2020 = { 2.0f, 2.0f, 2.0f };
F3 D_001F2030 = { 2.0f, 2.0f, 2.0f };
#define sceVu0CopyVector sceVu0CopyVector__as_Coll_TestCellTriangles_1_00152700
void sceVu0CopyVector__as_Coll_TestCellTriangles_1_00152700(Vec *, Vec *);
#define sceVu0SubVector sceVu0SubVector__as_Coll_TestCellTriangles_1_00152700
void sceVu0SubVector__as_Coll_TestCellTriangles_1_00152700(Vec *, Vec *, Vec *);

s32 Coll_TestCellTriangles_1_00152700(H_Coll_TestCellTriangles_1_00152700 *h, s32 **pp, Vec *s3, s32 a3, s32 *cnt, s32 max, H_Coll_TestCellTriangles_1_00152700 **cur, Vec *out, Vec *out1, Vec *tri,
                  s32 x24, s32 x28, S1 *s1, Mtx *m, f32 *best, s32 idx, s32 flag, s32 x3C) {
    Vec P;
    Vec D;
    Vec Q;
    Vec E[3];
    Vec G[3];
    Vec R[3];
    Vec S[3];
    F3 d;
    f32 tA;
    f32 tB;
    f32 sum;
    f32 r;
    s32 k;
    Vec *b;
    Vec *c;
    Vec *a;

    sum = 0.0f;
    tA = 0.0f;
    a = &tri[idx % 3];
    b = &tri[(idx + 1) % 3];
    sceVu0SubVector(&E[0], b, a);
    c = &tri[(idx + 2) % 3];
    sceVu0SubVector(&E[1], c, b);
    sceVu0SubVector(&E[2], a, c);
    sceVu0CopyVector(&P, &s1->v20);
    P.w = 1.0f;
    sceVu0ApplyMatrix(&P, m, &P);
    P.w = s1->v20.w;
    sceVu0CopyVector(&D, &s1->v10);
    D.w = 0.0f;
    sceVu0ApplyMatrix(&D, m, &D);
    if (flag && !(sceVu0InnerProduct(&D, &s3[1]) <= sum)) {
        sceVu0ScaleVector(&D, &D, -1.0f);
    }
    D.w = s1->v10.w;
    if (!Coll_SphereVsPlane_1_00150C00(s3, &P, &D, &Q, &tA, &tB)) return 0;
    sceVu0SubVector(&G[0], &tri[0], &Q);
    sceVu0SubVector(&G[2], &tri[1], &Q);
    sceVu0SubVector(&G[1], &tri[2], &Q);
    G[0].w = 0.0f;
    G[1].w = 0.0f;
    G[2].w = 0.0f;
    sceVu0Normalize(&G[0], &G[0]);
    sceVu0Normalize(&G[1], &G[1]);
    sceVu0Normalize(&G[2], &G[2]);
    sum += sceVu0InnerProduct(&G[0], &G[1]);
    sum += sceVu0InnerProduct(&G[1], &G[2]);
    sum += sceVu0InnerProduct(&G[2], &G[0]);
    if (sum < -1.0f) {
        if (tA < *best) *best = tA;
        sceVu0CopyVector(out, &Q);
        sceVu0CopyVector(out1, &D);
        out->w = tA;
        out1->w = tB;
        h->x20 = **pp;
        h->x24 = x24;
        h->x28 = x28;
        h->x2C = s1;
        h->x3C = x3C;
        s1->hE = gGameMainSbss_00201E94 - 1;
        if (a3 < -1 && *cur && *cnt < max) {
            (*cnt)++;
            (*cur)->x20 = **pp;
            sceVu0CopyVector(&(*cur)->v0, out);
            sceVu0CopyVector(&(*cur)->v10, out1);
            (*cur)->x24 = x24;
            (*cur)->x28 = x28;
            (*cur)->x2C = s1;
            (*cur)->x3C = x3C;
            (*cur)++;
        }
        if (a3 == 0 && *best < 1.0f) return 1;
    } else {
    d = D_001F2030;
    sum = 2.0f;
    k = -1;
    Coll_CapsuleVsRay_1_001511C0(s3, a, &E[0], &R[0], &S[0], &d.v[0]);
    Coll_CapsuleVsRay_1_001511C0(s3, b, &E[1], &R[1], &S[1], &d.v[1]);
    Coll_CapsuleVsRay_1_001511C0(s3, c, &E[2], &R[2], &S[2], &d.v[2]);
    if (d.v[0] < 2.0f) { sum = d.v[0]; k = 0; }
    if (d.v[1] < sum) { sum = d.v[1]; k = 1; }
    if (d.v[2] < sum) { sum = d.v[2]; k = 2; }
    if (k != -1) {
    if (!(a3 < -1) && !(sum <= *best)) return 0;
    *best = sum;
    sceVu0CopyVector(out, &R[k]);
    sceVu0CopyVector(out1, &S[k]);
    r = s3->w - sqrtf(sceVu0InnerProduct(out1, out1));
    if (r < 0.0f) r = 0.0f;
    sceVu0Normalize(out1, out1);
    out->w = sum;
    out1->w = r;
    h->x20 = **pp;
    h->x24 = x24;
    h->x28 = x28;
    h->x2C = s1;
    h->x3C = x3C;
    s1->hE = gGameMainSbss_00201E94 - 1;
    if (a3 < -1 && *cur && *cnt < max) {
        (*cnt)++;
        sceVu0CopyVector(&(*cur)->v0, out);
        sceVu0CopyVector(&(*cur)->v10, out1);
        (*cur)->x20 = **pp;
        (*cur)->x24 = x24;
        (*cur)->x28 = x28;
        (*cur)->x2C = s1;
        (*cur)->x3C = x3C;
        (*cur)++;
    }
    if (a3 == 0 && *best < 1.0f) return 1;
    }
    }
    return 0;
}

/* Coll_TestTriangle_1_00152D90 */
void sceVu0CopyVector__as_Coll_TestCellTriangles_1_00152700(Vec *, Vec *);
void sceVu0SubVector__as_Coll_TestCellTriangles_1_00152700(Vec *, Vec *, Vec *);

s32 Coll_TestTriangle_1_00152D90(Vec *out, Vec *s3, Vec *tri, S1 *s1, Mtx *m, s32 idx, s32 flag) {
    Vec P;
    Vec D;
    Vec Q;
    Vec E[3];
    Vec R[3];
    Vec S[3];
    F3 d;
    f32 tA;
    f32 tB;
    f32 best;
    s32 k;
    Vec *b;
    Vec *a;
    Vec *c;

    tA = 0.0f;
    sceVu0CopyVector(&P, &s1->v20);
    P.w = 1.0f;
    sceVu0ApplyMatrix(&P, m, &P);
    P.w = s1->v20.w;
    sceVu0CopyVector(&D, &s1->v10);
    D.w = 0.0f;
    sceVu0ApplyMatrix(&D, m, &D);
    if (flag && !(sceVu0InnerProduct(&D, &s3[1]) <= 0.0f)) {
        sceVu0ScaleVector(&D, &D, -1.0f);
    }
    D.w = s1->v10.w;
    if (!Coll_SphereVsPlane_1_00150C00(s3, &P, &D, &Q, &tA, &tB)) return 0;
    sceVu0SubVector(&E[0], &tri[0], &Q);
    sceVu0SubVector(&E[2], &tri[1], &Q);
    sceVu0SubVector(&E[1], &tri[2], &Q);
    E[0].w = 0.0f;
    E[1].w = 0.0f;
    E[2].w = 0.0f;
    sceVu0Normalize(&E[0], &E[0]);
    sceVu0Normalize(&E[1], &E[1]);
    sceVu0Normalize(&E[2], &E[2]);
    best = sceVu0InnerProduct(&E[0], &E[1]);
    best += sceVu0InnerProduct(&E[1], &E[2]);
    best += sceVu0InnerProduct(&E[2], &E[0]);
    if (best < -1.0f) {
        sceVu0CopyVector(out, &Q);
        out->w = tA;
        sceVu0CopyVector(&out[1], &D);
        out[1].w = tB;
        s1->hE = gGameMainSbss_00201E94 - 1;
        return 1;
    }
    d = D_001F2020;
    k = -1;
    best = 2.0f;
    a = &tri[idx % 3];
    b = &tri[(idx + 1) % 3];
    sceVu0SubVector(&E[0], b, a);
    c = &tri[(idx + 2) % 3];
    sceVu0SubVector(&E[1], c, b);
    sceVu0SubVector(&E[2], a, c);
    Coll_CapsuleVsRay_1_001511C0(s3, a, &E[0], &R[0], &S[0], &d.v[0]);
    Coll_CapsuleVsRay_1_001511C0(s3, b, &E[1], &R[1], &S[1], &d.v[1]);
    Coll_CapsuleVsRay_1_001511C0(s3, c, &E[2], &R[2], &S[2], &d.v[2]);
    if (d.v[0] < 2.0f) { best = d.v[0]; k = 0; }
    if (d.v[1] < best) { best = d.v[1]; k = 1; }
    if (d.v[2] < best) { best = d.v[2]; k = 2; }
    if (k == -1) return 0;
    sceVu0CopyVector(out, &R[k]);
    out->w = best;
    sceVu0CopyVector(&out[1], &S[k]);
    best = s3->w - sqrtf(sceVu0InnerProduct(&out[1], &out[1]));
    if (best < 0.0f) best = 0.0f;
    sceVu0Normalize(&out[1], &out[1]);
    out[1].w = best;
    s1->hE = gGameMainSbss_00201E94 - 1;
    return 1;
}
#undef sceVu0CopyVector
#undef sceVu0SubVector
