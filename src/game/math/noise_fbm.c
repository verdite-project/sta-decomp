#include "m2c.h"
#include "game/data.h"
#include "game/math.h"
#ifndef NONMATCHING
extern s32 D_00201C94;
#else
/* data twins (src/game/data/sdata.c): D_00201C94 */
static s32 D_00201C94 = 1;
#endif
#ifndef NONMATCHING
extern f32 D_00201C8C;
#else
/* data twins (src/game/data/sdata.c): D_00201C8C */
static f32 D_00201C8C = -1000.0f;
#endif
#ifndef NONMATCHING
extern f32 D_00201C90;
#else
/* data twins (src/game/data/sdata.c): D_00201C90 */
static f32 D_00201C90 = 1.0f;
#endif
#ifndef NONMATCHING
extern f32 D_003141F0[][2];
#else
/* data twins (src/game/data/vibration_bss.c): D_003141F0 */
static f32 D_003141F0[0x1010 / sizeof(f32[2])][2];
#endif
#ifndef NONMATCHING
extern f32 D_00315200[][3];
#else
/* data twins (src/game/data/vibration_bss.c): D_00315200 */
static f32 D_00315200[0x1820 / sizeof(f32[3])][3];
#endif
void Noise_Init_2_0015F250(void);
f32 powf(f32, f32);
void srand(s32);
s32 rand(void);
f32 sqrtf(f32);

/* Noise_Fbm_1_0015F040 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_003139B0[0xc];

f32 Noise_Fbm_1_0015F040(f32 x, f32 p, f32 lac, f32 oct) {
    f32 freq;
    s32 i;
    f32 *w;
    f32 sum;
    s32 j;
    f32 *q;

    if (D_00201C94 != 0 || p != D_00201C8C) {
        D_00201C90 = 0.0f;
        freq = 1.0f;
        D_00201C8C = p;
        for (i = 0; i <= oct; i++) {
            D_003139B0[i] = powf(freq, -p);
            D_00201C90 += D_003139B0[i];
            freq *= lac;
        }
        D_00201C94 = 0;
        D_00201C90 = 1.0f / powf(D_00201C90, 0.83f);
    }
    sum = 0.0f;
    for (i = 0; i < oct; i++) {
        f32 wt = D_003139B0[i];
        f32 v = 4096.0f + x;
        s32 k = (s32)v;
        u8 a = k;
        f32 f = v - (f32)k;
        f32 g0 = f * D_003139E0[D_00316A20[a]];
        f32 d = (f - 1.0f) * D_003139E0[D_00316A20[(u8)(a + 1)]] - g0;
        f32 s = (3.0f - 2.0f * f) * (f * f);
        f32 r = g0 + s * d;
        sum += wt * r;
        x *= lac;
    }
    sum *= D_00201C90;
    return sum;
}

/* Noise_Init_2_0015F250 */
void Noise_Init_2_0015F250(void) {
    s32 i, j, k;
    f32 s;
    srand(0);
    for (i = 0; i < 256; i++) {
        D_00316A20[i] = i;
        D_003139E0[i] = (f32)((rand() % 512) - 256) / 256.0f;
        for (j = 0; j < 2; j++)
            D_003141F0[i][j] = (f32)((rand() % 512) - 256) / 256.0f;
        s = 1.0f / sqrtf(D_003141F0[i][0] * D_003141F0[i][0] + D_003141F0[i][1] * D_003141F0[i][1]);
        D_003141F0[i][0] = D_003141F0[i][0] * s;
        D_003141F0[i][1] = D_003141F0[i][1] * s;
        for (j = 0; j < 3; j++)
            D_00315200[i][j] = (f32)((rand() % 512) - 256) / 256.0f;
        s = 1.0f / sqrtf(D_00315200[i][0] * D_00315200[i][0] + D_00315200[i][1] * D_00315200[i][1] + D_00315200[i][2] * D_00315200[i][2]);
        D_00315200[i][0] = D_00315200[i][0] * s;
        D_00315200[i][1] = D_00315200[i][1] * s;
        D_00315200[i][2] = D_00315200[i][2] * s;
    }
    while (--i) {
        k = D_00316A20[i];
        D_00316A20[i] = D_00316A20[j = rand() % 256];
        D_00316A20[j] = k;
    }
    for (i = 0; i < 258; i++) {
        D_00316A20[256 + i] = D_00316A20[i];
        D_003139E0[256 + i] = D_003139E0[i];
        for (j = 0; j < 2; j++)
            D_003141F0[256 + i][1 - j] = D_003141F0[i][1 - j];
        for (j = 0; j < 3; j++)
            D_00315200[256 + i][2 - j] = D_00315200[i][2 - j];
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/vibration_bss.c): D_003139E0, D_00316A20 */
f32 D_003139E0[0x204];
s32 D_00316A20[0x204];
#endif
