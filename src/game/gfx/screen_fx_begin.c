/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/ScreenFx_Begin_0_001329D0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: logic matches; retail reloads gScreenFxBeginSbss_00201EEC before the gScreenFxBeginSbss_00201F08/F04 stores and
 * keeps the product in $t0. stmtperm over the store order (210) found nothing. */
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
    if (gScreenFxBeginSbss_00201F0C == 0) {
        gScreenFxBeginSbss_00201EF0 = n << 5;
        gScreenFxDrawSbss_00201EF4 = n;
        gScreenFxBeginSbss_00201EEC = n << 13;
        gScreenFxBeginSbss_00201F08 = (u16)h;
        gScreenFxBeginSbss_00201F04 = (u16)w;
        gScreenFxBeginSbss_00201F0C = 1;
        gScreenFxBeginSbss_00201EF8 = gScreenFxBeginSbss_00201EEC + gScreenFxBeginSbss_00201F04 * gScreenFxBeginSbss_00201F08 * 2;
        gScreenFxBeginSbss_00201EF8 = (gScreenFxBeginSbss_00201EF8 + 0x1FFF) & ~0x1FFF;
        gScreenFxBeginSbss_00201EFC = gScreenFxBeginSbss_00201EF8 >> 8;
        gScreenFxDrawSbss_00201F00 = gScreenFxBeginSbss_00201EF8 >> 13;
        ScreenFx_DrawCopy_0_00132190(w, h);
    }
}
#else
INCLUDE_ASM(ScreenFx_Begin_0_001329D0);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gScreenFxBeginSbss_00201EF0, gScreenFxBeginSbss_00201F04, gScreenFxBeginSbss_00201F08, gScreenFxBeginSbss_00201F0C */
s32 gScreenFxBeginSbss_00201EF0;
u32 gScreenFxBeginSbss_00201F04;
u32 gScreenFxBeginSbss_00201F08;
u8 gScreenFxBeginSbss_00201F0C;
#endif
