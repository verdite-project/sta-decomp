#include "common.h"
#include "game/gfx.h"
#include "game/data.h"
typedef struct { Vec a; f32 x10; f32 x14; f32 x18; u8 b1C; u8 b1D; u8 b1E; u8 b1F; u16 h20; u8 b22; } Ent_PointLight_CalcIntensity_0_0015BDE0;
typedef struct { u8 pad[0x23]; u8 on; u8 pad2[0xC]; } E_PointLight_Update_0_0015C0C0;
typedef struct {
    f32 f[6];
    u8 pad[0xB0 - 0x18];
    E_PointLight_Update_0_0015C0C0 e[2][32];
    u8 padCB0[4];
    u16 n[2];
} S;
typedef struct { u8 b[4]; u16 h; u8 c; } C;
typedef struct { u8 b[0x600]; } E_PointLightGroup_Clear_0_0015C6D0;
typedef struct { Vec a; f32 x10; f32 x14; f32 x18; u8 b1C; u8 b1D; u8 b1E; u8 b1F; u16 h20; u8 b22; u8 used; u8 pad[0xC]; } Ent_PointLight_Update_0_0015C0C0;
typedef struct { u8 pad[0xB0]; Ent_PointLight_Update_0_0015C0C0 ents[2][32]; } W;
typedef struct {
    Vec v;
    f32 x10, x14, x18;
    u8 x1C, x1D, x1E, x1F;
    u16 x20;
    u8 x22, x23;
    u8 pad[0xC];
} __attribute__((aligned(16))) S30;
typedef struct {
    u8 pad[0x20];
    S30 a;
    S30 b;
    S30 c;
    u8 pad2[0xCC0 - 0xB0];
} Big;
extern f32 gPointLightBss_0030C420[];
#ifndef NONMATCHING
extern f32 gPointLightBss_0030C424[];
#else
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): gPointLightBss_0030C424 */
static f32 gPointLightBss_0030C424[0x1];
#endif
#ifndef NONMATCHING
extern f32 gPointLightBss_0030C428[];
#else
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): gPointLightBss_0030C428 */
static f32 gPointLightBss_0030C428[0x1];
#endif
#ifndef NONMATCHING
extern f32 gPointLightBss_0030C42C[];
#else
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): gPointLightBss_0030C42C */
static f32 gPointLightBss_0030C42C[0x1];
#endif
extern f32 D_0030C434[];
extern Vec gPointLightBss_0030C3E0;
extern Vec gMatrixFromData_001F2150;
extern C gPointLightBss_0030C48C[];
extern u16 D_0030D0D4[];
extern u8 gPointLightBss_0030C420__as_PointLight_OffsetAll_0_0015C620[];
extern E_PointLightGroup_Clear_0_0015C6D0 gPointLightBss_0030C420__as_PointLightGroup_Clear_0_0015C6D0[];
extern W gPointLightBss_0030C420__as_PointLight_Add_0_0015C730;
extern Big gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0;
f32 PointLight_CalcIntensity_0_0015BDE0(Ent_PointLight_CalcIntensity_0_0015BDE0 *e);
void PointLight_OffsetAll_0_0015C620(void *arg0);
s32 PointLight_Add_0_0015C730(s32 idx, Vec *v, u8 c0, u8 c1, u8 c2, u8 c3, u16 h, u8 c4, f32 f0, f32 f1, f32 f2, f32 f3);
void sceVu0CopyVector(void *, void *);
void sceVu0ApplyMatrix(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 powf(f32, f32);
f32 sqrtf(f32);
void sceVu0CopyMatrix(Vec *, void *);
void ScreenFx_SetFlashParams_0_00159340(u8, u8, u8, u8, u16, u8);
void sceVu0AddVector(void *, void *, void *);
void* memset(void*, s32, u32);
void sceVu0CopyVector__as_PointLight_Add_0_0015C730(Vec *, Vec *);
void memset__as_PointLight_Init_0_0015C8D0(void *, s32, s32);

/* PointLight_CalcIntensity_0_0015BDE0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_0030C430[0x4];
#define sceVu0CopyVector sceVu0CopyVector__as_PointLight_CalcIntensity_0_0015BDE0
void sceVu0CopyVector__as_PointLight_CalcIntensity_0_0015BDE0(Vec *, Vec *);

f32 PointLight_CalcIntensity_0_0015BDE0(Ent_PointLight_CalcIntensity_0_0015BDE0 *e) {
    Vec v;
    Vec n;
    f32 k = 0.01f * e->x10;
    f32 s = e->x18;
    f32 d;
    f32 r;

    sceVu0CopyVector(&v, &e->a);
    v.w = 1.0f;
    sceVu0ApplyMatrix(&v, &gPointLightBss_0030C3E0, &v);
    sceVu0Normalize(&n, &v);
    d = sceVu0InnerProduct(&n, &gMatrixFromData_001F2150);
    d += s;
    if (d < 0.0f) return 0.0f;
    k *= d / (1.0f + s);
    r = sqrtf(sceVu0InnerProduct(&v, &v));
    if (e->a.w < r) return 0.0f;
    k *= powf(1.0f - r / e->a.w, e->x14);
    gPointLightBss_0030C420[0] += e->b1C * k;
    gPointLightBss_0030C424[0] += e->b1D * k;
    gPointLightBss_0030C428[0] += e->b1E * k;
    gPointLightBss_0030C42C[0] += e->b1F * k;
    D_0030C430[0] += e->h20 * k;
    D_0030C434[0] += e->b22 * k;
    return k;
}
#undef sceVu0CopyVector

/* PointLight_Update_0_0015C0C0 */
#define gPointLightBss_0030C420 gPointLightBss_0030C420__as_PointLight_Update_0_0015C0C0
extern S gPointLightBss_0030C420__as_PointLight_Update_0_0015C0C0[];
#define gPointLightBss_0030C3E0 gPointLightBss_0030C3E0__as_PointLight_Update_0_0015C0C0
extern Vec gPointLightBss_0030C3E0__as_PointLight_Update_0_0015C0C0[];
#define PointLight_CalcIntensity_0_0015BDE0 PointLight_CalcIntensity_0_0015BDE0__as_PointLight_Update_0_0015C0C0
f32 PointLight_CalcIntensity_0_0015BDE0__as_PointLight_Update_0_0015C0C0(E_PointLight_Update_0_0015C0C0 *);

/* PointLight_Update_0_0015C0C0 */
/* PointLight_Update_0_0015C0C0 */
void PointLight_Update_0_0015C0C0(void *arg0) {
    s32 i;
    s32 j;
    s32 cnt;
    f32 sum;
    f32 inv;

    cnt = 0;
    sum = 0.0f;
    gPointLightBss_0030C420[0].f[0] = 0.0f;
    gPointLightBss_0030C420[0].f[1] = 0.0f;
    gPointLightBss_0030C420[0].f[2] = 0.0f;
    gPointLightBss_0030C420[0].f[3] = 0.0f;
    gPointLightBss_0030C420[0].f[4] = 0.0f;
    gPointLightBss_0030C420[0].f[5] = 0.0f;
    sceVu0CopyMatrix(gPointLightBss_0030C3E0, arg0);
    for (i = 0; i < 2; i++) {
        if (gPointLightBss_0030C420[0].n[i]) {
            for (j = 0; j < 32; j++) {
                if (gPointLightBss_0030C420[0].e[i][j].on) {
                    sum += PointLight_CalcIntensity_0_0015BDE0(&gPointLightBss_0030C420[0].e[i][j]);
                    cnt++;
                }
            }
        }
    }
    if (cnt) {
        inv = 1.0f / sum;
        gPointLightBss_0030C48C[0].b[0] = gPointLightBss_0030C420[0].f[0] * inv;
        gPointLightBss_0030C48C[0].b[1] = gPointLightBss_0030C420[0].f[1] * inv;
        gPointLightBss_0030C48C[0].b[2] = gPointLightBss_0030C420[0].f[2] * inv;
        gPointLightBss_0030C48C[0].b[3] = gPointLightBss_0030C420[0].f[3] * inv;
        gPointLightBss_0030C48C[0].h = gPointLightBss_0030C420[0].f[4] * inv;
        gPointLightBss_0030C48C[0].c = gPointLightBss_0030C420[0].f[5] * inv;
    } else {
        inv = 1.0f;
        gPointLightBss_0030C48C[0].b[0] = gPointLightBss_0030C420[0].f[0] * inv;
        gPointLightBss_0030C48C[0].b[1] = gPointLightBss_0030C420[0].f[1] * inv;
        gPointLightBss_0030C48C[0].b[2] = gPointLightBss_0030C420[0].f[2] * inv;
        gPointLightBss_0030C48C[0].b[3] = gPointLightBss_0030C420[0].f[3] * inv;
        gPointLightBss_0030C48C[0].h = gPointLightBss_0030C420[0].f[4] * inv;
        gPointLightBss_0030C48C[0].c = gPointLightBss_0030C420[0].f[5] * inv;
    }
    ScreenFx_SetFlashParams_0_00159340(gPointLightBss_0030C48C[0].b[0], gPointLightBss_0030C48C[0].b[1], gPointLightBss_0030C48C[0].b[2], gPointLightBss_0030C48C[0].b[3], gPointLightBss_0030C48C[0].h, gPointLightBss_0030C48C[0].c);
}

/* PointLight_OffsetAll_0_0015C620 */
void PointLight_OffsetAll_0_0015C620(void *arg0) {
    s32 i;
    s32 j;
    u8 *p;
    u8 *q;
    u8 *r;
    i = 0;
    p = gPointLightBss_0030C420__as_PointLight_OffsetAll_0_0015C620;
    q = gPointLightBss_0030C420__as_PointLight_OffsetAll_0_0015C620;
    do {
        j = 0;
        if (*(u16 *)(p + 0xCB4) != 0) {
            r = q;
            do {
                if (r[0xD3] != 0) {
                    sceVu0AddVector(r + 0xB0, r + 0xB0, arg0);
                }
                j++;
                r += 0x30;
            } while (j < 0x20);
        }
        i++;
        p += 2;
        q += 0x600;
    } while (i < 2);
}

/* PointLightGroup_Clear_0_0015C6D0 */

void PointLightGroup_Clear_0_0015C6D0(s32 i)
{
    memset(gPointLightBss_0030C420__as_PointLightGroup_Clear_0_0015C6D0[i].b + 0xB0, 0, 0x600);
    D_0030D0D4[i] = 0;
}

/* PointLight_Add_0_0015C730 */

s32 PointLight_Add_0_0015C730(s32 idx, Vec *v, u8 c0, u8 c1, u8 c2, u8 c3, u16 h, u8 c4, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 i;
    s32 id;
    Ent_PointLight_Update_0_0015C0C0 *e;

    for (i = 0; i < 32; i++) {
        if (gPointLightBss_0030C420__as_PointLight_Add_0_0015C730.ents[idx & 1][i].used == 0) {
            id = i + (idx & 1) * 32;
            goto found;
        }
    }
    id = -1;
found:
    if (id == -1) {
        return id;
    }
    e = &gPointLightBss_0030C420__as_PointLight_Add_0_0015C730.ents[(u32)id >> 5][id & 31];
    sceVu0CopyVector(&e->a, v);
    e->a.w = f0;
    e->x10 = f2;
    e->x14 = f3;
    e->x18 = f1;
    e->used = 1;
    e->b1C = c0;
    e->b1D = c1;
    e->b1E = c2;
    e->b1F = c3;
    e->h20 = h;
    e->b22 = c4;
    D_0030D0D4[idx]++;
    return id;
}

/* PointLight_Init_0_0015C8D0 */

void PointLight_Init_0_0015C8D0(void) {
    memset(&gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0, 0, 0xCC0);
    sceVu0CopyVector(&gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.v, &gZeroVec_003139A0);
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.v.w = 40000.0f;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x18 = 100.0f;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x10 = 1.0f;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x14 = 0.1f;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x23 = 1;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x1C = 0x18;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x1D = 8;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x1E = 8;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x1F = 8;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x20 = 0x40;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c.x22 = 0x78;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.a = gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c;
    gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.b = gPointLightBss_0030C420__as_PointLight_Init_0_0015C8D0.c;
}
#undef PointLight_CalcIntensity_0_0015BDE0
#undef gPointLightBss_0030C420
#undef gPointLightBss_0030C3E0

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): gPointLightBss_0030C3E0, gPointLightBss_0030C420 */
Vec gPointLightBss_0030C3E0;
f32 gPointLightBss_0030C420[0x1];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/point_light_bss.c): D_0030C48C__grp: gPointLightBss_0030C48C@0x0, gPointLightBss_0030C490@0x4 */
u8 D_0030C48C__grp[0x14] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/point_light_bss.c): D_0030C4C0__grp: gPointLightBss_0030C4C0@0x0 */
u8 D_0030C4C0__grp[0xc20] __attribute__((aligned(16)));
#endif
