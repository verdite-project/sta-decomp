#include "m2c.h"
#include "game/gfx.h"
extern s32 gGlowInitBss_0030D180[];
extern s16 gGlowInitBss_0030D588[];
extern s16 D_0030D60A[];
extern s16 D_0030D68C[];
extern s16 D_0030D70E[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s16 D_0030D790[0x108];
extern s16 D_0030D812[];
extern s16 D_0030D894[];
extern s16 D_0030D916[];

void Glow_Init_0_0015DD90(void) {
    s32 i;
    gGlowInitBss_0030D180[0] = 0;
    D_0030D916[0] = 0;
    gGlowInitBss_0030D184[0] = 0x100;
    D_0030D894[0] = 0;
    D_0030D812[0] = 0;
    D_0030D790[0] = 0;
    D_0030D70E[0] = 0;
    D_0030D68C[0] = 0;
    D_0030D60A[0] = 0;
    gGlowInitBss_0030D588[0] = 0;
    for (i = 0; i < 0x100; i++) {
        M2C_FIELD(&gGlowInitBss_0030D180[0xFF - i], s32 *, 8) = i;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/point_light_bss.c): gGlowInitBss_0030D0E0__grp: gGlowInitBss_0030D0E0@0x0, gGlowInitBss_0030D0E4@0x4, gGlowInitBss_0030D0E8@0x8, gGlowInitBss_0030D170@0x90, gGlowInitBss_0030D180@0xa0, gGlowInitBss_0030D184@0xa4, gGlowInitBss_0030D588@0x4a8 */
unsigned char gGlowInitBss_0030D0E0__grp[0x6b0] __attribute__((aligned(16)));
#endif
