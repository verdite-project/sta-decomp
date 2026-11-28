#include "common.h"
extern s32 gScreenFxBeginSbss_00201EF0;
extern s32 gScreenFxDrawSbss_00201EF4;
#ifndef NONMATCHING
extern s32 gScreenFxBeginSbss_00201EEC;
extern u32 gScreenFxBeginSbss_00201EF8;
extern u32 gScreenFxBeginSbss_00201EFC;
#else
/* data twins (src/game/data/sbss.c): gScreenFxBeginSbss_00201EEC */
static s32 gScreenFxBeginSbss_00201EEC;
/* data twins (src/game/data/sbss.c): gScreenFxBeginSbss_00201EF8 */
static u32 gScreenFxBeginSbss_00201EF8;
/* data twins (src/game/data/sbss.c): gScreenFxBeginSbss_00201EFC */
static u32 gScreenFxBeginSbss_00201EFC;
#endif
extern u32 gScreenFxDrawSbss_00201F00;
extern u32 gScreenFxBeginSbss_00201F04;
extern u32 gScreenFxBeginSbss_00201F08;
extern u8 gScreenFxBeginSbss_00201F0C;
void ScreenFx_DrawCopy_0_00132190(s32 w, s32 h);

void ScreenFx_Begin_0_001329D0(s32 n, s32 w, s32 h) {
    if (!gScreenFxBeginSbss_00201F0C) {
        u32 width = (u16)w;

        gScreenFxBeginSbss_00201EF0 = n << 5;
        gScreenFxDrawSbss_00201EF4 = n;
        gScreenFxBeginSbss_00201EEC = n << 13;
        gScreenFxBeginSbss_00201F04 = width;
        gScreenFxBeginSbss_00201F08 = (u16)h;
        gScreenFxBeginSbss_00201EF8 = gScreenFxBeginSbss_00201EEC + (width * (u16)h * 2);
        gScreenFxBeginSbss_00201EF8 = (gScreenFxBeginSbss_00201EF8 + 0x1FFF) & ~0x1FFF;
        gScreenFxBeginSbss_00201F0C = 1;
        gScreenFxBeginSbss_00201EFC = gScreenFxBeginSbss_00201EF8 >> 8;
        gScreenFxDrawSbss_00201F00 = gScreenFxBeginSbss_00201EF8 >> 13;
        ScreenFx_DrawCopy_0_00132190(w, h);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gScreenFxBeginSbss_00201EF0, gScreenFxBeginSbss_00201F04, gScreenFxBeginSbss_00201F08, gScreenFxBeginSbss_00201F0C */
s32 gScreenFxBeginSbss_00201EF0;
u32 gScreenFxBeginSbss_00201F04;
u32 gScreenFxBeginSbss_00201F08;
u8 gScreenFxBeginSbss_00201F0C;
#endif
