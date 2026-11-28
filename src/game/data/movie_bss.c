#include "common.h"

/* bss_004BDF34: the game's .bss from 0x004BDF34, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: map_sheet, movie, text_001E8C50.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/map_sheet.c */
u8 gMapSheetBss_004BE11C[0x4]; /* also D_004BE11F */
u8 gMapSheetBss_004BE110[0xc] __attribute__((aligned(4)));
u8 gMapSheetBss_004BE10C[0x4];
u8 gMapSheetBss_004BE0F4[0x18] __attribute__((aligned(4))); /* also D_004BE0F8 */
u8 gMapSheetBss_004BE0E0[0x14] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
s16 gMovieBss_004BE0D8[0x4] __attribute__((aligned(4)));
u8 gMovieBss_004BE0D4[0x4]; /* also D_004BE0D6 */
u8 gMovieBss_004BE0D0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
u8 gMovieBss_004BE0A8[0x28] __attribute__((aligned(4))); /* also D_004BE0AC */
u8 gMovieBss_004BE090[0x18] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
u8 gMovieBss_004BE080[0x10] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
s32 gMovieBss_004BE07C[0x1];
s32 gMovieBss_004BE078[0x1];
u8 gMovieBss_004BE040[0x38] __attribute__((aligned(4))); /* also D_004BE044, D_004BE04C */
u8 gMovieBss_004BE038[0x8] __attribute__((aligned(4)));
s32 gMovieBss_004BE034[0x1];
s32 gMovieBss_004BE030[0x1];
u8 gMovieBss_004BE02C[0x4];
s32 gMovieBss_004BE028[0x1];
s32 gMovieBss_004BE024[0x1];
s32 gMovieBss_004BE020[0x1];
s32 gMovieBss_004BE01C[0x1];
s32 gMovieBss_004BE018[0x1];
s32 gMovieBss_004BE014[0x1];
s32 gMovieBss_004BE010[0x1];
u32 gMovieBss_004BE008[0x2] __attribute__((aligned(4)));
u32 gMovieBss_004BE004[0x1];
u32 gMovieBss_004BE000[0x1];
u8 gMovieBss_004BDFF0[0x10] __attribute__((aligned(4))); /* also D_004BDFF4 */
s32 gMovieBss_004BDFE8[0x2] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
u8 gMovieBss_004BDFE4[0x4];
u8 gMovieBss_004BDFE0[0x4];
u8 gMovieBss_004BDFDC[0x4];
u8 gMovieBss_004BDFD8[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
u8 gMovieBss_004BDFD0[0x8] __attribute__((aligned(4)));
s32 gMovieBss_004BDFC8[0x2] __attribute__((aligned(4)));
u8 gMovieBss_004BDF40[0x88] __attribute__((aligned(4))); /* also D_004BDF88, D_004BDF9C */
s32 gMovieBss_004BDF38[0x2] __attribute__((aligned(4)));
s32 gMovieBss_004BDF34[0x1];
#endif
