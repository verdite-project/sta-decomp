#include "common.h"
#include "game/collision.h"
#include "game/data.h"
typedef struct { u8 p0[0xC]; f32 r; Vec dir; } Ray;
typedef struct { s32 off[4]; s32 x10[8]; s32 x30[8]; } Hdr;
typedef struct { u16 n; u16 pad; s32 off; u8 p8[0x18]; } Item;
typedef struct { Vec v; u8 p10[0x20]; } Tri;
typedef struct { Vec a; Vec b; u8 p20[0x20]; } Res;
typedef struct { Vec a; Vec b; s32 x20; u16 *x24; Item *x28; Tri *x2C; s32 x30; s32 x34; s32 x38; } Out_Coll_RayVsMesh_1_0014DDE0;
typedef struct { u8 b[0x20]; } Box;
typedef struct { Vec v0; Vec v10; u8 pad20[4]; s32 x24; s8 *x28; s8 *x2C; u8 pad30[4]; s32 x34; s32 x38; } Out_Coll_CapsuleVsMesh_1_0014E230;
typedef f32 FV[4] __attribute__((aligned(16)));
s32 Coll_RayVsMesh_1_0014DDE0(Out_Coll_RayVsMesh_1_0014DDE0 *out, Hdr *h, s32 base, Ray *ray, Mtx *m, u8 mask, u8 flag);
s32 Coll_CapsuleVsMesh_1_0014E230(Out_Coll_CapsuleVsMesh_1_0014E230 *out, s32 *lst, s32 base, FV o1, FV o2, Mtx *m, u8 mask, u8 flag);
void sceVu0CopyVector(void *, void*);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0InversMatrix(Mtx *, Mtx *);
void sceVu0ApplyMatrix(Vec*, Mtx*, void *);
s32 Coll_RayVsAabb_1_0014F0C0(Vec *, Vec *, f32, void *);
s32 Coll_TestTriangle_1_00152D90(Res *, Ray *, Vec *, Tri *, Mtx *, s32, s32);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0Normalize(Vec *, Vec *);
s32 Coll_SweptVsTriangle_1_0014F520(Vec *, Vec *, Vec *, Vec *, Vec *, s32, s32, s32 *);

/* Coll_RayVsMesh_1_0014DDE0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Coll_RayVsMesh_1_0014DDE0
void sceVu0CopyVector__as_Coll_RayVsMesh_1_0014DDE0(Vec *, void *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Coll_RayVsMesh_1_0014DDE0
void sceVu0ApplyMatrix__as_Coll_RayVsMesh_1_0014DDE0(Vec *, Mtx *, Vec *);

s32 Coll_RayVsMesh_1_0014DDE0(Out_Coll_RayVsMesh_1_0014DDE0 *out, Hdr *h, s32 base, Ray *ray, Mtx *m, u8 mask, u8 flag) {
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
    f32 best;
    Mtx M;
    Vec D;
    Vec C;
    Vec S[2];
    Res res;
    Vec tri[3];
    Vec *v;

    ret = 0;
    if (h->off[0] == 0) return 0;
    if (h->off[2] == 0) return 0;
    q0 = (u16 *)(base + h->off[0]);
    q8 = (Box *)(base + h->off[2]);
    q4 = (u8 *)(base + h->off[1]);
    sceVu0CopyVector(&S[0], ray);
    S[0].w = 1.0f;
        sceVu0ScaleVector(&S[1], &ray->dir, ray->dir.w);
    sceVu0AddVector(&S[1], &S[1], &S[0]);
    S[1].w = 1.0f;
    sceVu0InversMatrix(&M, m);
    sceVu0ApplyMatrix(&C, &M, &S[0]);
    sceVu0ApplyMatrix(&D, &M, &S[1]);
    best = 1.0f;
    if (!(ray->dir.w <= 0.0f)) best += ray->r / ray->dir.w;
    cnt = q0;
    for (k = 0; k < 8; h = (Hdr *)&h->off[1], q8++, k++) {
        if (!((1 << k) & mask)) continue;
        if (!h->x10[0]) continue;
        if (!h->x30[0]) continue;
        if (flag && !Coll_RayVsAabb_1_0014F0C0(&C, &D, ray->r, &q8[1])) continue;
        it = (Item *)(base + h->x10[0]);
        bx = (Box *)(base + h->x30[0]);
        for (j = 0; j < cnt[k]; j++, it++, bx++) {
            c0 = 0;
            if (D_00222A18[0] != -1 && j != D_00222A18[0]) continue;
            if (flag && !Coll_RayVsAabb_1_0014F0C0(&C, &D, ray->r, bx)) continue;
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
                if (Coll_TestTriangle_1_00152D90(&res, ray, tri, t, m, i, c0) && res.a.w < best) {
                    best = res.a.w;
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
    return ret;
}
#undef sceVu0CopyVector
#undef sceVu0ApplyMatrix

/* Coll_CapsuleVsMesh_1_0014E230 */
#define Coll_RayVsAabb_1_0014F0C0 Coll_RayVsAabb_1_0014F0C0__as_Coll_CapsuleVsMesh_1_0014E230
s32 Coll_RayVsAabb_1_0014F0C0__as_Coll_CapsuleVsMesh_1_0014E230(f32, Vec *, Vec *, s8 *);

s32 Coll_CapsuleVsMesh_1_0014E230(Out_Coll_CapsuleVsMesh_1_0014E230 *out, s32 *lst, s32 base, FV o1, FV o2, Mtx *m, u8 mask, u8 flag) {
    Mtx m250;
    Mtx m210;
    Vec CD[2];
    Vec S[2];
    Vec hit[4];
    Vec t[3];
    Vec v150;
    s32 x29C;
    u16 *cnt;
    s8 *s4;
    s8 *s6;
    s32 j;
    s8 *s2;
    s32 k;
    Vec *s0;
    s32 h;
    s8 *q;
    u32 i;
    s32 r;
    s32 ret;
    s32 f2;
    s32 msk;

    ret = 0;
    if (lst[0] == 0) return 0;
    if (lst[2] == 0) return 0;
    h = base + lst[0];
    q = (s8 *)(base + lst[2]);
    r = base + lst[1];
    sceVu0CopyVector(&S[0], o1);
    S[0].w = 1.0f;
    sceVu0CopyVector(&S[1], o2);
    S[1].w = 1.0f;
    sceVu0InversMatrix(&m250, m);
    sceVu0ApplyMatrix(&CD[0], &m250, &S[0]);
    sceVu0ApplyMatrix(&CD[1], &m250, &S[1]);
    sceVu0CopyMatrix(&m210, m);
    sceVu0CopyVector(&m210.m[3], &gZeroVec_003139A0);
    cnt = (u16 *)h;
    msk = mask;
    for (i = 0; i < 8; i++) {
        if (((1 << i) & msk) && lst[4] != 0 && lst[12] != 0) {
            if (!flag || Coll_RayVsAabb_1_0014F0C0(0.0f, &CD[0], &CD[1], q + 0x20)) {
                s4 = (s8 *)(base + lst[4]);
                s6 = (s8 *)(base + lst[12]);
                for (j = 0; j < *cnt; j++) {
                    f2 = 0;
                    if (D_00222A18[0] == -1 || j == D_00222A18[0]) {
                        if (!flag || Coll_RayVsAabb_1_0014F0C0(0.0f, &CD[0], &CD[1], s6)) {
                            s0 = (Vec *)(r + *(s32 *)(s4 + 4));
                            s2 = (s8 *)s0 + 0x20;
                            if (*((u8 *)s0 + 0xC) & 1) f2 = 1;
                            sceVu0CopyVector(&t[0], s0);
                            t[0].w = 1.0f;
                            sceVu0CopyVector(&t[1], (s8 *)s0 + 0x10);
                            t[1].w = 1.0f;
                            sceVu0ApplyMatrix(&t[0], m, &t[0]);
                            sceVu0ApplyMatrix(&t[1], m, &t[1]);
                            for (k = 0; k < *(u16 *)s4 - 2; k++) {
                                s0 = &t[(k + 2) % 3];
                                sceVu0CopyVector(s0, s2);
                                s0->w = 1.0f;
                                sceVu0ApplyMatrix(s0, m, s0);
                                if (D_00222A16[0] == -1 || k == D_00222A16[0]) {
                                    sceVu0ApplyMatrix(&v150, &m210, s2 + 0x10);
                                    sceVu0Normalize(&v150, &v150);
                                    v150.w = 0.0f;
                                    if (Coll_SweptVsTriangle_1_0014F520(&hit[0], &S[0], &S[1], t, &v150, k, f2, &x29C)) {
                                        sceVu0CopyVector(&S[1], &hit[0]);
                                        S[1].w = 1.0f;
                                        sceVu0CopyVector(&out->v0, &hit[0]);
                                        sceVu0CopyVector(&out->v10, &hit[1]);
                                        out->x24 = h;
                                        ret = 1;
                                        out->x28 = s4;
                                        out->x2C = s2;
                                        out->x38 = 0;
                                        out->x34 = 0;
                                    }
                                }
                                s2 += 0x30;
                            }
                        }
                    }
                    s4 += 0x20;
                    s6 += 0x20;
                }
            }
        }
        lst++;
        q += 0x20;
        cnt++;
    }
    sceVu0CopyVector(o1, &S[0]);
    sceVu0CopyVector(o2, &S[1]);
    return ret;
}
#undef Coll_RayVsAabb_1_0014F0C0
