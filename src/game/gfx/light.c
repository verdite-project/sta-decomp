#include "common.h"
#include "m2c.h"
#include "game/gfx.h"
#include "game/data.h"
typedef struct { u8 d[0x40]; } E;
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct { u8 b0:1; } B_Light_UpdateModel_0_0015B360;
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; B_Light_UpdateModel_0_0015B360 fl; u8 pad[7]; } Ent_Light_UpdateModel_0_0015B360;
typedef struct { Ent_Light_UpdateModel_0_0015B360 sp[4]; Ent_Light_UpdateModel_0_0015B360 ents[2][64]; u16 x2100[2]; u16 cnt[2]; } W_Light_UpdateModel_0_0015B360;
typedef struct { u8 b[0x1000]; } E_LightGroup_Clear_0_0015B890;
typedef struct { u8 b[0x40]; } E_LightGroup_Get_0_0015B900;
typedef struct { char pad[0x100]; E_LightGroup_Get_0_0015B900 e[0x3C]; } B_LightGroup_Clear_0_0015B890;
typedef struct { u8 b0:1; } B;
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; B fl; u8 pad[7]; } Ent_Light_Add_0_0015B980;
typedef struct { Ent_Light_Add_0_0015B980 sp[4]; Ent_Light_Add_0_0015B980 ents[2][64]; } W_Light_Add_0_0015B980;
typedef struct { u128 q[4]; } M;
extern s32 D_0030A2D0[];
#ifndef NONMATCHING
extern Vec D_0030A290;
#else
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): D_0030A290 */
static Vec D_0030A290;
#endif
#ifndef NONMATCHING
extern Vec D_0030A320;
#else
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): D_0030A320 */
static Vec D_0030A320;
#endif
extern Vec D_0030A330;
extern Vec D_0030A350;
extern Vec D_0030A360;
extern Vec D_0030A370;
extern Vec D_0030A390;
extern Vec D_001F2150;
extern u16 D_0030C3D0[];
extern u16 D_0030C3D4[];
extern char D_0030A310[];
extern B_LightGroup_Clear_0_0015B890 D_0030A2D0__as_LightGroup_Get_0_0015B900[];
extern E_LightGroup_Clear_0_0015B890 D_0030A2D0__as_LightGroup_Clear_0_0015B890[];
extern char D_0030A390__as_LightGroup_Clear_0_0015B890[];
extern f32 D_0030A39C[];
extern Vec D_0030A3A0[];
extern f32 D_0030A3AC[];
extern Vec D_0030A3B0[];
extern f32 D_0030A3B4[];
extern f32 D_0030A3B8[];
extern f32 D_0030A3BC[];
#ifndef NONMATCHING
extern f32 D_0030A3C0[];
#else
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): D_0030A3C0 */
static f32 D_0030A3C0[0x1];
#endif
extern f32 D_0030A3C4[];
extern B D_0030A3C8[];
extern s8 D_0030A2D0__as_Light_Init_1_0015BCA0[];
extern W_Light_Add_0_0015B980 D_0030A2D0__as_Light_Add_0_0015B980;
extern Vec D_0030A390__as_Light_Add_0_0015B980[];
extern Vec gZeroVec_003139A0__as_Light_Add_0_0015B980[];
extern M D_0030A310__as_Light_Add_0_0015B980;
extern M D_0030A350__as_Light_Add_0_0015B980;
void Light_OffsetAll_0_0015B110(s32 arg0);
void Fog_SetReg_0_0015B1C0(Q *src, f32 *c);
void Light_CopyColor_0_0015B6B0(void *arg0, void *arg1);
f32 Light_CalcIntensity_0_0015B720(void *a0, u8 *a1);
void* LightGroup_Get_0_0015B900(s32 i);
void Light_SetAmbient_0_0015BB40(Vec *a, Vec *b, f32 f);
void sceVu0AddVector(u8 *, u8 *, s32);
Q* GsPkt_Alloc_3_00154A80(s32);
void GsPkt_SetReg_3_001543E0(s32, u64);
u64 __fixunssfdi(f32);
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(Vec *, void *);
void sceVu0InterVector(f32, Vec *, Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec*, void *, f32);
f32 powf(f32, f32);
f32 sqrtf(float);
void sceVu0CopyVector__as_Light_UpdateModel_0_0015B360(Vec *, void *);
f32 Light_CalcIntensity_0_0015B720__as_Light_UpdateModel_0_0015B360(void *, void *);
void* memset(void*, s32, u32);
void sceVu0CopyVector__as_Light_Add_0_0015B980(Vec *, Vec *);
void sceVu0ScaleVector__as_Light_Add_0_0015B980(Vec *, Vec *, f32);
void memset__as_Light_Add_0_0015B980(void *, s32, s32);

/* Light_OffsetAll_0_0015B110 */
void Light_OffsetAll_0_0015B110(s32 arg0) {
    s32 j;
    s32 i;
    u8 *h;
    u8 *b;
    E *e;
    j = 0;
    h = (u8 *)D_0030A2D0;
    b = (u8 *)D_0030A2D0;
    do {
        i = 0;
        if (*(u16 *)(h + 0x2104) != 0) {
            e = (E *)b;
            do {
                if (e[4].d[0x38] & 1) {
                    sceVu0AddVector(e[4].d, e[4].d, arg0);
                }
                i++;
                e++;
            } while (i < 0x40);
        }
        j++;
        h += 2;
        b += 0x1000;
    } while (j < 2);
}

/* Fog_SetReg_0_0015B1C0 */
#define D_0030A2D0 D_0030A2D0__as_Fog_SetReg_0_0015B1C0
extern u8 D_0030A2D0__as_Fog_SetReg_0_0015B1C0[];

/* Fog_SetReg_0_0015B1C0 */
void Fog_SetReg_0_0015B1C0(Q *src, f32 *c) {
    Q q;
    Q *p;
    q.q = 0;
    p = GsPkt_Alloc_3_00154A80(2);
    q.w[0] = 0x10000001;
    q.w[3] = 0x6C010059;
    p[0].q = q.q;
    p[1].q = src->q;
    GsPkt_Commit_1_00154A70();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x3D, __fixunssfdi(c[0]) | __fixunssfdi(c[1]) << 8 | __fixunssfdi(c[2]) << 16);
    GsPkt_EndAD_3_00154420();
}

/* Fog_ApplyDefault_0_0015B270 */
void Fog_ApplyDefault_0_0015B270(void) {
    Vec c;
    Q q;
    Q *p;
    u64 r;
    u64 g;
    u64 b;
    q.q = 0;
    p = GsPkt_Alloc_3_00154A80(1);
    q.w[0] = 0x30000001;
    q.w[1] = (u32)(D_0030A2D0 + D_00201F2C * 32);
    q.w[3] = 0x6C010059;
    p->q = q.q;
    GsPkt_Commit_1_00154A70();
    sceVu0CopyVector(&c, D_0030A2D0 + D_00201F2C * 32 + 0x10);
    GsPkt_BeginAD_3_001545D0();
    r = __fixunssfdi(255.0f * c.x);
    g = __fixunssfdi(255.0f * c.y);
    r |= g << 8;
    b = __fixunssfdi(255.0f * c.z);
    GsPkt_SetReg_3_001543E0(0x3D, (b << 16) | r);
    GsPkt_EndAD_3_00154420();
}
#undef D_0030A2D0

/* Light_UpdateModel_0_0015B360_ */
#define D_0030A2D0 D_0030A2D0__as_Light_UpdateModel_0_0015B360_
extern W_Light_UpdateModel_0_0015B360 D_0030A2D0__as_Light_UpdateModel_0_0015B360_;
#define sceVu0AddVector sceVu0AddVector__as_Light_UpdateModel_0_0015B360_
void sceVu0AddVector__as_Light_UpdateModel_0_0015B360_(Vec *, Vec *, Vec *);

/* Light_UpdateModel_0_0015B360_ */
/* Light_UpdateModel_0_0015B360_ */
/* Light_UpdateModel_0_0015B360 */

void Light_UpdateModel_0_0015B360(void *a0, s32 mask) {
    Vec *h;
    Vec *h2;
    s32 i;
    s32 j;
    f32 sum;
    f32 inv;
    Vec d;
    Vec c;

    h = (Vec *)((u8 *)&D_0030A2D0 + D_00201F2C * 32);
    h2 = h + 1;
    sceVu0CopyVector__as_Light_UpdateModel_0_0015B360(&D_0030A360, &gZeroVec_003139A0);
    sceVu0CopyVector__as_Light_UpdateModel_0_0015B360(&D_0030A370, &gZeroVec_003139A0);
    sceVu0CopyMatrix(&D_0030A290, a0);
    sum = Light_CalcIntensity_0_0015B720__as_Light_UpdateModel_0_0015B360(&D_0030A350, &D_0030A390);
    for (i = 0; i < 2; i++) {
        if ((mask & (1 << i)) && D_0030A2D0.cnt[i]) {
            for (j = 0; j < 64; j++) {
                if (D_0030A2D0.ents[i][j].fl.b0) {
                    sum += Light_CalcIntensity_0_0015B720__as_Light_UpdateModel_0_0015B360(&D_0030A350, &D_0030A2D0.ents[i][j]);
                }
            }
        }
    }
    inv = 1.0f / sum;
    d.x = D_0030A360.x * inv;
    d.y = D_0030A360.y * inv;
    d.z = D_0030A360.z * inv;
    d.w = 0.0f;
    c.x = D_0030A370.x * inv;
    c.y = D_0030A370.y * inv;
    c.z = D_0030A370.z * inv;
    c.w = D_0030A370.w * inv;
    sceVu0InterVector(0.85f, &D_0030A320, &D_0030A320, &d);
    sceVu0InterVector(0.85f, &D_0030A330, &D_0030A330, &c);
    if (h && &D_0030A330) {
        h->x = D_0030A330.x;
        h->y = D_0030A330.y;
        h->z = 0.5f * (0.999999f - D_0030A330.z);
        h->w = 0.5f * (1.0f - D_0030A330.w);
    }
    sceVu0CopyVector__as_Light_UpdateModel_0_0015B360(h2, &D_0030A320);
    if (!(h2->x <= 1.0f)) h2->x = 1.0f;
    if (h2->x < 0.0f) h2->x = 0.0f;
    if (!(h2->y <= 1.0f)) h2->y = 1.0f;
    if (h2->y < 0.0f) h2->y = 0.0f;
    if (!(h2->z <= 1.0f)) h2->z = 1.0f;
    if (h2->z < 0.0f) h2->z = 0.0f;
}

/* Light_CopyColor_0_0015B6B0 */
void Light_CopyColor_0_0015B6B0(void *arg0, void *arg1) {
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return;
    }
    M2C_FIELD(arg0, f32 *, 0) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (0.5f * (0.999999f - M2C_FIELD(arg1, f32 *, 8)));
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) (0.5f * (1.0f - M2C_FIELD(arg1, f32 *, 0xC)));
}

/* Light_CalcIntensity_0_0015B720 */
f32 Light_CalcIntensity_0_0015B720(void *a0, u8 *a1) {
    Vec v60;
    Vec v50;
    Vec v40;
    Vec v30;
    f32 r = 0.01f * *(f32 *)(a1 + 0x30);
    f32 k = *(f32 *)(a1 + 0x1C);
    f32 d;
    f32 s;
    sceVu0CopyVector(&v60, a1);
    v60.w = 1.0f;
    sceVu0ApplyMatrix(&v60, &D_0030A290, &v60);
    sceVu0Normalize(&v50, &v60);
    d = sceVu0InnerProduct(&v50, &D_001F2150);
    d += k;
    if (d < 0.0f) {
        return 0.0f;
    }
    r *= d / (1.0f + k);
    s = sqrtf(sceVu0InnerProduct(&v60, &v60));
    if (*(f32 *)(a1 + 0xC) < s) {
        return 0.0f;
    }
    r *= powf(1.0f - s / *(f32 *)(a1 + 0xC), *(f32 *)(a1 + 0x34));
    sceVu0ScaleVector(&v40, a1 + 0x10, r);
    sceVu0AddVector(&D_0030A360, &v40, &D_0030A360);
    sceVu0ScaleVector(&v30, a1 + 0x20, r);
    sceVu0AddVector(&D_0030A370, &v30, &D_0030A370);
    return r;
}

/* LightGroup_Clear_0_0015B890 */

/* LightGroup_Clear_0_0015B890 */
void LightGroup_Clear_0_0015B890(s32 i)
{
    memset(D_0030A2D0__as_LightGroup_Clear_0_0015B890[i].b + 0x100, 0, 0x1000);
    D_0030C3D0[i] = 0;
    D_0030C3D4[i] = 0;
}

/* LightGroup_Get_0_0015B900 */

void *LightGroup_Get_0_0015B900(s32 i)
{
    if (i < 0) {
        if (i == -1)
            return D_0030A310;
        return D_0030A390__as_LightGroup_Clear_0_0015B890;
    }
    return &D_0030A2D0__as_LightGroup_Get_0_0015B900[i / 64].e[i % 64];
}

/* Light_Add_0_0015B980 */

/* Light_Add_0_0015B980 */
static inline Ent_Light_Add_0_0015B980 *getEnt(s32 id) {
    if (id < 0) {
        if (id == -1) {
            return &D_0030A2D0__as_Light_Add_0_0015B980.sp[1];
        }
        return &D_0030A2D0__as_Light_Add_0_0015B980.sp[3];
    }
    return &D_0030A2D0__as_Light_Add_0_0015B980.ents[id / 64][id % 64];
}

s32 Light_Add_0_0015B980(s32 idx, Vec *a, Vec *b, Vec *c, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 i;
    s32 id;
    Ent_Light_Add_0_0015B980 *e;

    i = D_0030C3D0[idx];

    for (;;) {
        if (!D_0030A2D0__as_Light_Add_0_0015B980.ents[idx][i].fl.b0) {
            D_0030C3D0[idx] = i + 1;
            id = i + idx * 64;
            break;
        }
        i++;
        if (i == 64) {
            i = 0;
        }
    }
    e = getEnt(id);
    sceVu0CopyVector__as_Light_Add_0_0015B980(&e->a, a);
    sceVu0ScaleVector__as_Light_Add_0_0015B980(&e->b, b, 1.0f / 255.0f);
    e->a.w = f0;
    e->b.w = f1;
    sceVu0CopyVector__as_Light_Add_0_0015B980(&e->c, c);
    e->x30 = f2;
    e->x34 = f3;
    e->fl.b0 = 1;
    D_0030C3D4[idx]++;
    return id;
}

/* Light_SetAmbient_0_0015BB40 */
void Light_SetAmbient_0_0015BB40(Vec *a, Vec *b, f32 f) {
    sceVu0CopyVector__as_Light_Add_0_0015B980(D_0030A390__as_Light_Add_0_0015B980, gZeroVec_003139A0__as_Light_Add_0_0015B980);
    D_0030A39C[0] = 30000.0f;
    if (b != NULL) {
        sceVu0ScaleVector__as_Light_Add_0_0015B980(D_0030A3A0, b, 1.0f / 255.0f);
    } else {
        sceVu0CopyVector__as_Light_Add_0_0015B980(D_0030A3A0, gZeroVec_003139A0__as_Light_Add_0_0015B980);
        D_0030A3A0[0].x = 0.0f;
    }
    D_0030A3AC[0] = 100.0f;
    if (a != NULL) {
        sceVu0CopyVector__as_Light_Add_0_0015B980(D_0030A3B0, a);
    } else {
        D_0030A3B8[0] = 0.0f;
        D_0030A3B0[0].x = 1000.0f;
        D_0030A3B4[0] = 15000.0f;
        D_0030A3BC[0] = 1.0f;
    }
    if (f < 0.0f) {
        D_0030A3C0[0] = 1.0f;
    } else {
        D_0030A3C0[0] = f;
    }
    D_0030A3C4[0] = 0.1f;
    D_0030A3C8[0].b0 = 1;
}

/* Light_Init_1_0015BCA0 */

void Light_Init_1_0015BCA0(void) {
    memset__as_Light_Add_0_0015B980(D_0030A2D0__as_Light_Init_1_0015BCA0, 0, 0x2110);
    sceVu0CopyVector__as_Light_Add_0_0015B980(D_0030A390__as_Light_Add_0_0015B980, gZeroVec_003139A0__as_Light_Add_0_0015B980);
    D_0030A39C[0] = 30000.0f;
    sceVu0CopyVector__as_Light_Add_0_0015B980(D_0030A3A0, gZeroVec_003139A0__as_Light_Add_0_0015B980);
    D_0030A3A0[0].x = 0.0f;
    D_0030A3AC[0] = 100.0f;
    D_0030A3B0[0].x = 1000.0f;
    D_0030A3B8[0] = 0.0f;
    D_0030A3B4[0] = 15000.0f;
    D_0030A3BC[0] = 1.0f;
    D_0030A3C0[0] = 1.0f;
    D_0030A3C4[0] = 0.1f;
    D_0030A3C8[0].b0 = 1;
    D_0030A350__as_Light_Add_0_0015B980 = *(M *)D_0030A390__as_Light_Add_0_0015B980;
    D_0030A310__as_Light_Add_0_0015B980 = *(M *)D_0030A390__as_Light_Add_0_0015B980;
}
#undef sceVu0AddVector
#undef D_0030A2D0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): D_0030A2D0, D_0030A310 */
s32 D_0030A2D0[0x10];
char D_0030A310[0x10];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): D_0030A350 */
Vec D_0030A350;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): D_0030A3C4, D_0030C3D0 */
f32 D_0030A3C4[0x803] __attribute__((aligned(4)));
u16 D_0030C3D0[0x8];
#endif
