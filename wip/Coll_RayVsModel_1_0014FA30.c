// NEAR: 10 of 378 words differ (was 79). Only the head scheduling differs: retail loads g->x14, computes g+0x40, loads D_00201F2C and h, h+0x40, then reloads g (spilled) for x16/x18/x10; ours loads x16/x18 right after x14. Fixes so far: Z -> M1.m[3] (stack overlap), (s32)g->data/(s32)h->data hoists, split hd into 2 statements (fixes final addu order), decl perm of e/n/v/it/t, statement perm of cnt/bx/q4/it/q8.

#include "common.h"
typedef struct { s32 off[4]; s32 x10[8]; s32 x30[8]; } Hdr;
typedef struct { u16 n; u16 pad; s32 off; u8 p8[0x18]; } Item;
typedef struct { Vec v; Vec n; u8 p20[0x10]; } Tri;
typedef struct { u8 b[0x20]; } Box;
typedef struct { Vec a; Vec b; u8 p20[0x2C]; f32 d; } Res;
typedef struct { Vec a; Vec b; void *x20; u16 *x24; Item *x28; Tri *x2C; u8 p30[0xC]; s32 x3C; } Out;
typedef struct { u8 pad[0x10]; s32 *x10; u16 x14, x16, x18; u8 pad1A[2]; u16 x1C; u8 pad1E[0x22]; u8 data[1]; } G;
typedef struct { G **g; u8 pad4[2]; u16 x6; u8 pad8[0x38]; u8 data[1]; } H;
typedef struct { u8 pad[0x140]; } Ent;
typedef struct { u8 pad[0x178]; u8 *x178; } F;
typedef struct { u8 p[4]; Flags8 f; u8 p5[3]; } FE;
extern s16 D_00222A18[];
extern s16 D_00222A16[];
extern s32 D_00201F2C;
extern Vec gZeroVec_003139A0;
void sceVu0CopyVector(Vec *, void *);
void sceVu0CopyMatrix(Mtx *, void *);
void sceVu0ApplyMatrix(Vec *, Mtx *, void *);
void sceVu0Normalize(Vec *, Vec *);
s32 Coll_BoxOverlap_0_0014F8C0(Vec *, Vec *, Box *, Mtx *);
s32 Coll_SweptVsTriangle_1_0014F520(Res *, Vec *, Vec *, Vec *, Vec *, s32, s32, f32 *);

s32 Coll_RayVsModel_1_0014FA30(Out *out, H *h, Vec *ray, u8 mask, F *flag, s32 first) {
    u8 *base190;
    G *g;
    Hdr *hd;
    s32 b160;
    u32 k;
    s32 ret;
    u16 *cnt;
    u8 *q4;
    s32 j;
    u32 c;
    Box *bx;
    u8 *e;
    s32 i;
    s32 n;
    Item *it;
    s32 c0;
    Tri *t;
    Box *q8;
    Vec *v;
    Res res;
    Vec S0;
    Vec S1;
    Mtx M2;
    Mtx M1;
    Vec tri[3];
    Vec N;

    ret = 0;
    if (h == 0) return 0;
    if (h->g == 0) return 0;
    if ((g = *h->g) == 0) return 0;
    hd = (Hdr *)((s32)g->data + g->x14 * 16 + g->x16 * 8);
    hd = (Hdr *)((s32)hd + g->x18 * 4);
    b160 = *g->x10;
    base190 = (u8 *)((s32)h->data + D_00201F2C * (h->x6 * 320 + 0x200));
    if (g->x1C == 0) return 0;
    sceVu0CopyVector(&S0, ray);
    S0.w = 1.0f;
    sceVu0CopyVector(&S1, &ray[1]);
    S1.w = 1.0f;
    for (k = 0; k < 8; k++) {
        if (!((1 << k) & mask)) continue;
        for (j = first != 0; j < h->x6; j++) {
            Hdr *hh;
            if (flag) {
                FE *fe = &((FE *)flag->x178)[j];
                if (!fe->f.f.b0 || fe->f.f.b1) continue;
            }
            c = ((u8 *)&((Ent *)base190)[j])[0x332];
            if (c == 0xFF) continue;
            if (c >= g->x1C) continue;
            sceVu0CopyMatrix(&M2, (u8 *)&((Ent *)base190)[j + 1] + 0xC0);
            sceVu0CopyMatrix(&M1, (u8 *)&((Ent *)base190)[j + 1] + 0xC0);
            sceVu0CopyVector(&M1.m[3], &gZeroVec_003139A0);
            hh = &hd[c];
            if (!hh->off[0]) continue;
            if (!hh->off[2]) continue;
            if (!hh->x10[k]) continue;
            if (!hh->x30[k]) continue;
            cnt = (u16 *)(b160 + hh->off[0]);
            bx = (Box *)(b160 + hh->x30[k]);
            q4 = (u8 *)(b160 + hh->off[1]);
            it = (Item *)(b160 + hh->x10[k]);
            q8 = (Box *)(b160 + hh->off[2]);
            if (flag && !Coll_BoxOverlap_0_0014F8C0(&S0, &S1, (Box *)((u8 *)&q8[k] + 0x20), &M2)) continue;
            for (i = 0; i < cnt[k]; i++, it++, bx++) {
                c0 = 0;
                if (flag && !Coll_BoxOverlap_0_0014F8C0(&S0, &S1, bx, &M2)) continue;
                if (D_00222A18[0] != -1 && i != D_00222A18[0]) continue;
                e = q4 + it->off;
                t = (Tri *)(e + 0x20);
                if (e[0xC] & 1) c0 = 1;
                sceVu0CopyVector(&tri[0], e);
                tri[0].w = 1.0f;
                sceVu0CopyVector(&tri[1], e + 0x10);
                tri[1].w = 1.0f;
                sceVu0ApplyMatrix(&tri[0], &M2, &tri[0]);
                sceVu0ApplyMatrix(&tri[1], &M2, &tri[1]);
                for (n = 0; n < it->n - 2; n++, t++) {
                    v = &tri[(n + 2) % 3];
                    sceVu0CopyVector(v, t);
                    v->w = 1.0f;
                    sceVu0ApplyMatrix(v, &M2, v);
                    sceVu0ApplyMatrix(&N, &M1, &t->n);
                    sceVu0Normalize(&N, &N);
                    N.w = 0.0f;
                    if (D_00222A16[0] != -1 && n != D_00222A16[0]) continue;
                    if (Coll_SweptVsTriangle_1_0014F520(&res, &S0, &S1, tri, &N, n, c0, &res.d)) {
                        sceVu0CopyVector(&S1, &res.a);
                        S1.w = 1.0f;
                        sceVu0CopyVector(&out->a, &res.a);
                        sceVu0CopyVector(&out->b, &res.b);
                        out->x20 = g;
                        ret = 1;
                        out->x24 = cnt;
                        out->x28 = it;
                        out->x2C = t;
                        out->x3C = j;
                    }
                }
            }
        }
    }
    return ret;
}
