#include "common.h"
typedef struct { s32 off[4]; s32 x10[8]; s32 x30[8]; } Hdr;
typedef struct { u16 n; u16 pad; s32 off; u8 p8[0x18]; } Item;
typedef struct { Vec v; u8 p10[0x20]; } Tri;
typedef struct { Vec a; Vec b; u8 p20[0x20]; } Res;
typedef struct { Vec a; Vec b; s32 x20; u16 *x24; Item *x28; Tri *x2C; s32 x30; s32 x34; s32 x38; } Out;
typedef struct { Vec mn; Vec mx; } Box;
extern s16 D_00222A18[];
extern s16 D_00222A16[];
extern Vec gZeroVec_003139A0;
void sceVu0CopyVector(Vec *, void *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0InversMatrix(Mtx *, Mtx *);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
s32 Coll_SphereVsTriangle_1_0014F210(Res *, Vec *, Vec *, Vec *, s32, s32, f32 *);

static inline s32 ov(Vec *p, Box *b, f32 r) {
    if (p->x + r < b->mn.x || !(p->x - r <= b->mx.x)) return 0;
    if ((&p->x)[1] + r < b->mn.y || !((&p->x)[1] - r <= b->mx.y)) return 0;
    if ((&p->x)[2] + r < b->mn.z || !((&p->x)[2] - r <= b->mx.z)) return 0;
    return 1;
}

s32 Coll_SphereVsMesh_1_0014E680(Out *out, Hdr *h, s32 base, Vec *sph, Mtx *m, u8 mask, u8 flag) {
    u16 *cnt;
    Box *bx;
    Item *it;
    s32 j;
    Tri *t;
    s32 i;
    u8 *e;
    u16 *q0;
    Box *q8;
    u32 k;
    u8 *q4;
    s32 ret;
    s32 c0;
    f32 r;
    f32 dist;
    Mtx M;
    Mtx R;
    Vec C;
    Vec P;
    Res res;
    Vec tri[3];
    Vec N;
    Vec S;
    Vec *v;

    ret = 0;
    if (h->off[0] == 0) return 0;
    if (h->off[2] == 0) return 0;
    q0 = (u16 *)(base + h->off[0]);
    q8 = (Box *)(base + h->off[2]);
    q4 = (u8 *)(base + h->off[1]);
    r = sph->w;
    sceVu0CopyVector(&P, sph);
    sceVu0CopyVector(&C, sph);
    C.w = 1.0f;
    sceVu0InversMatrix(&M, m);
    sceVu0ApplyMatrix(&C, &M, &C);
    sceVu0CopyMatrix(&R, m);
    sceVu0CopyVector((Vec *)&R.m[3], &gZeroVec_003139A0);
    cnt = q0;
    for (k = 0; k < 8; h = (Hdr *)&h->off[1], q8++, k++, cnt++) {
        if (!((1 << k) & mask)) continue;
        if (!h->x10[0]) continue;
        if (!h->x30[0]) continue;
        if (flag && !ov(&C, &q8[1], r)) continue;
        it = (Item *)(base + h->x10[0]);
        bx = (Box *)(base + h->x30[0]);
        for (j = 0; j < *cnt; j++, it++, bx++) {
            c0 = 0;
            if (D_00222A18[0] != -1 && j != D_00222A18[0]) continue;
            if (flag && !ov(&C, bx, r)) continue;
            e = q4 + it->off;
            t = (Tri *)(e + 0x20);
            if (e[0xC] & 1) c0 = 1;
            sceVu0CopyVector(&tri[0], e);
            tri[0].w = 1.0f;
            sceVu0CopyVector(&tri[1], e + 0x10);
            tri[1].w = 1.0f;
            sceVu0ApplyMatrix(&tri[0], m, &tri[0]);
            sceVu0ApplyMatrix(&tri[1], m, &tri[1]);
            for (i = 0; i < it->n - 2; i++, t++) {
                v = &tri[(i + 2) % 3];
                sceVu0CopyVector(v, t);
                v->w = 1.0f;
                sceVu0ApplyMatrix(v, m, v);
                if (D_00222A16[0] != -1 && i != D_00222A16[0]) continue;
                sceVu0ApplyMatrix(&N, &R, &t->v + 1);
                sceVu0Normalize(&N, &N);
                N.w = 0.0f;
                if (Coll_SphereVsTriangle_1_0014F210(&res, &P, tri, &N, i, c0, &dist)) {
                    sceVu0ScaleVector(&S, &res.b, r);
                    sceVu0AddVector(&P, &S, &res.a);
                    P.w = r;
                    sceVu0CopyVector(&out->a, &res.a);
                    sceVu0CopyVector(&out->b, &res.b);
                    out->x24 = q0;
                    ret = 1;
                    out->x28 = it;
                    out->x2C = t;
                    out->x38 = 0;
                    out->x34 = 0;
                }
            }
        }
    }
    sceVu0CopyVector(sph, &P);
    sph->w = r;
    return ret;
}
