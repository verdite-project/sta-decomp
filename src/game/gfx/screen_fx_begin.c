/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/ScreenFx_Begin_0_001329D0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: logic matches; retail reloads D_00201EEC before the D_00201F08/F04 stores and
 * keeps the product in $t0. stmtperm over the store order (210) found nothing. */
#include "common.h"
extern s32 D_00201EEC;
extern s32 D_00201EF0;
extern s32 D_00201EF4;
extern u32 D_00201EF8;
extern u32 D_00201EFC;
extern u32 D_00201F00;
extern u32 D_00201F04;
extern u32 D_00201F08;
extern u8 D_00201F0C;
void ScreenFx_DrawCopy_0_00132190(s32 w, s32 h);

void ScreenFx_Begin_0_001329D0(s32 n, s32 w, s32 h) {
    if (D_00201F0C == 0) {
        D_00201EF0 = n << 5;
        D_00201EF4 = n;
        D_00201EEC = n << 13;
        D_00201F08 = (u16)h;
        D_00201F04 = (u16)w;
        D_00201F0C = 1;
        D_00201EF8 = D_00201EEC + D_00201F04 * D_00201F08 * 2;
        D_00201EF8 = (D_00201EF8 + 0x1FFF) & ~0x1FFF;
        D_00201EFC = D_00201EF8 >> 8;
        D_00201F00 = D_00201EF8 >> 13;
        ScreenFx_DrawCopy_0_00132190(w, h);
    }
}
#else
INCLUDE_ASM(ScreenFx_Begin_0_001329D0);
#endif
