/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Attack_Ricochet_0_001D31E0.c.
 * The matching build takes it from the assembly of Attack_SpawnHitEffect_1_001D2CB0. */
#ifdef NONMATCHING
/* Attack_Ricochet_0_001D31E0 NEAR: 35 of 393 words differ (was 48). Fixed getB/getE addu order with (u32)((u8 *)(n4*20) + (s32)h)
   and the run-loop add tree (bit*16 + n4*20 + n5*4 + n6*12 + h). Still differs: loop getH addu base/idx order (1 word),
   and in both run() copies the constant 4 of (b1?4:0) is hoisted to the top in a3 (retail: li v0,4 after the getH load,
   h lands in t0); pi/pb load order in the run copies. */
#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { u8 pad[4]; u8 n4; u8 n5; u8 n6; B8 f7; } H;
typedef struct { u8 b[20]; } T20; typedef struct { u8 b[4]; } T4; typedef struct { u8 b[12]; } T12; typedef struct { u8 b[16]; } T16;
typedef struct { f32 x0; f32 x4; u8 pad8[4]; union { s32 w; struct { B8 c; B8 d; } b; } xC; } B;
typedef struct { u16 x0; u16 x2; u8 pad[0x24]; } E;
typedef struct { u8 pad[0xD]; u8 xD; u8 padE[2]; f32 x10; f32 x14; f32 x18; } T;
typedef struct { u8 pad[0x10]; Vec x10; u8 pad20[0xC]; T *x2C; } A1;
void Fx_GetWorldMatrix_1_00163C80(s8 *, Mtx *);
void sceVu0CopyVector(Vec *, void *);
void Attack_HandleSfxEvent_1_001D3810(s8 *, s32, E *, Mtx *, s32, A1 *, s32);
s32 Rand_Next_3_0015ED20(void);
static inline f32 u2f(u32 x) { return x; }
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(void *, Vec *, void *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void Vec_Reflect_2_00145ED0(Vec *, Vec *, Vec *);
f32 sqrtf(f32);

static inline H *getH(s8 **pb, u16 *pi) {
    return ((H **)(*pb + 0x210))[*pi];
}
static inline H *getHR(s8 **pb, u16 *pi) {
    return *(H **)(*pi * 4 + *pb + 0x210);
}
static inline B *getB(H *h) {
    return (B *)(h->n6 * 12 + (h->n5 * 4 + (u32)((u8 *)(h->n4 * 20) + (s32)h)) + 0x108);
}
static inline E *getE(H *h) {
    return (E *)((h->f7.b1 ? 4 : 0) * 16 + (h->n6 * 12 + (h->n5 * 4 + (u32)((u8 *)(h->n4 * 20) + (s32)h))) + 0x108);
}

static inline E *getE2(H *h) {
    return (E *)((h->f7.b1 ? 4 : 0) * 16 + h->n4 * 20 + h->n5 * 4 + h->n6 * 12 + (u32)h + 0x108);
}
static inline void run(s8 *a0, A1 *a1, s8 **pb, u16 *pi, s32 id, s32 i) {
    s32 j;
    E *e;
    Mtx M;
    e = getE2(getHR(pb, pi));
    for (j = 0; j < 4; j++, e++) {
        if (e->x2 == i) {
            Fx_GetWorldMatrix_1_00163C80(a0, &M);
            sceVu0CopyVector(&M.m[3], a1);
            M.m[3].w = 1.0f;
            Attack_HandleSfxEvent_1_001D3810(a0, id, e, &M, 0, a1, 0);
        }
    }
}

s32 Attack_Ricochet_0_001D31E0(s8 *a0, A1 *a1) {
    Vec U;
    Vec X;
    Vec W;
    Vec Y;
    Mtx M1;
    s32 i;
    s32 r;
    B *b;
    s32 j;
    E *e;
    u8 m;
    f32 k;
    f32 d;
    s8 **pb;
    u16 *pi;

    pi = (u16 *)(a0 + 0x94);
    pb = (s8 **)(a0 + 0x90);
    r = 0;
    b = getB(getH(pb, pi));
    for (i = 0; i < 4; i++, b++) {
        if (b->xC.w == 0) continue;
        m = 0;
        if (b->xC.b.c.b4) m |= 2;
        if (b->xC.b.c.b5) m |= 4;
        if (b->xC.b.c.b6) m |= 8;
        if (b->xC.b.c.b7) m |= 0x10;
        if (b->xC.b.d.b0) m |= 0x20;
        if (b->xC.b.d.b1) m |= 0x40;
        if (b->xC.b.d.b2) m |= 0x80;
        if (!((1 << (a1->x2C->xD & 7)) & m)) continue;
        e = getE(getH(pb, pi));
        for (j = 0; j < 4; j++, e++) {
            if (e->x2 == i) {
                Fx_GetWorldMatrix_1_00163C80(a0, &M1);
                sceVu0CopyVector(&M1.m[3], a1);
                M1.m[3].w = 1.0f;
                Attack_HandleSfxEvent_1_001D3810(a0, 4, e, &M1, 0, a1, 0);
            }
        }
        if (b->x0 != 0.0f) {
            if (!(b->x0 < 100.0f)) {
                r = 1;
            } else if (!(b->x0 <= 100.0f * (1.5259022e-05f * (f32)(u32)(u16)Rand_Next_3_0015ED20()))) {
                r = 1;
            }
            if (r) break;
        }
        if (0.0f < b->x4) {
            k = 0.01f * b->x4;
            sceVu0ScaleVector(&U, &a1->x10, a1->x10.w * (1.0f + k));
            U.w = 0.0f;
            sceVu0AddVector(a0, &U, a0);
            *(f32 *)(a0 + 0xC) = 1.0f;
            d = sqrtf(sceVu0InnerProduct((Vec *)(a0 + 0x10), (Vec *)(a0 + 0x10)));
            sceVu0ScaleVector(&W, (Vec *)(a0 + 0x10), -1.0f);
            sceVu0Normalize(&W, &W);
            X.x = a1->x2C->x10;
            X.y = a1->x2C->x14;
            X.z = a1->x2C->x18;
            X.w = 0.0f;
            Vec_Reflect_2_00145ED0(&X, &W, &Y);
            sceVu0ScaleVector((Vec *)(a0 + 0x10), &Y, d * k);
        }
    }
    if (r) {
        run(a0, a1, pb, pi, 5, i);
    } else {
        run(a0, a1, pb, pi, 6, i);
    }
    return r;
}
#endif
