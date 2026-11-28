/* Keys: switch case order 0/default,1,2,3 + volatile gCreditsLoadSdata_00201B88/8C, t[2][3] 2D array,
   p via gCreditsLoadBss_004BC2F0.data, q via *(&gCreditsLoadBss_004BC2F0.data) (permuter find). */
/* round 2 near-miss: ee-gcc, s1/s2 swap, switch store merging, &g->data in own register */
#include "common.h"
#include "game/ee.h"
typedef struct { u8 pad[4]; f32 rate; u8 *data; u8 pad0C[8]; s32 size; u8 pad18[4]; u8 *t[2][3]; u8 pad34[0x4C]; } G;
extern G gCreditsLoadBss_004BC2F0;
extern volatile f32 gCreditsLoadSdata_00201B88;
extern volatile f32 gCreditsLoadSdata_00201B8C;
void *memset(void *, s32, u32);
void Credits_Setup_0_001E3DD8(void);
s32 Credits_Run_1_001E3EC0(void);

s32 Credits_Load_1_001E3B48(u8 *data, s32 size) {
    G *g;
    s32 i;
    u32 *h;
    u32 a, b;
    memset(&gCreditsLoadBss_004BC2F0, 0, 0x80);
    if (data != NULL && size != 0) {
        gCreditsLoadBss_004BC2F0.size = size;
        gCreditsLoadBss_004BC2F0.data = data;
        switch (data[0xB]) {
        case 0: default: gCreditsLoadBss_004BC2F0.rate = gCreditsLoadSdata_00201B88; break;
        case 1: gCreditsLoadBss_004BC2F0.rate = 20.0f; break;
        case 2: gCreditsLoadBss_004BC2F0.rate = gCreditsLoadSdata_00201B8C; break;
        case 3: gCreditsLoadBss_004BC2F0.rate = 40.0f; break;
        }
        g = &gCreditsLoadBss_004BC2F0;
        if (*(u32 *)(g->data + 0xC) != 0) {
            h = (u32 *)(g->data + *(u32 *)(g->data + 0xC));
            for (i = 0; i < 3; i++) {
                if ((a = h[i + 4]) != 0 && (b = h[i]) != 0) {
                    u8 *p = gCreditsLoadBss_004BC2F0.data + a; u8 *q = *(&gCreditsLoadBss_004BC2F0.data) + b;
                    g->t[0][i] = p; g->t[1][i] = q;
                }
            }
            Credits_Setup_0_001E3DD8();
        }
        Credits_SetSpeed_0_001E3DB8(0);
        return Credits_Run_1_001E3EC0();
    }
    return -1;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_system_start_bss.c): D_004BC2F0__grp: gCreditsLoadBss_004BC2F0@0x0 */
u8 D_004BC2F0__grp[0x70] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sdata.c): D_00201B88__grp: gCreditsLoadSdata_00201B88@0x0 */
unsigned int D_00201B88__grp[0x1] __attribute__((section(".sdata"))) __attribute__((aligned(8))) = { 0x41855555 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sdata.c): D_00201B8C__grp: gCreditsLoadSdata_00201B8C@0x0 */
unsigned int D_00201B8C__grp[0x1] __attribute__((section(".sdata"))) __attribute__((aligned(4))) = { 0x42055555 };
#endif
