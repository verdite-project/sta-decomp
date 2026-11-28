#include "common.h"
#include "game/data.h"
void memset(s32 *, s32, s32);        /* extern */
extern s8 gMovieBss_004BD310[];
extern s8 D_004BD311[];
extern s8 D_004BD312[];
extern s8 D_004BD313[];
extern s32 gMovieParamsBss_004BD31C[];

void Movie_SetParams_0_001ED5D0(s8 arg0, s8 arg1, s8 arg2, s32 arg3) {
    (*gMovieBss_004BD314) = arg3;
    (*gMovieBss_004BD310) = arg0;
    (*D_004BD311) = arg1;
    (*D_004BD312) = arg2;
    (*D_004BD313) = 0;
    (*gMovieBss_004BD318) = 0;
    memset(gMovieParamsBss_004BD31C, 0, 0x28);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_system_start_bss_004BCBC0.c): gMovieParamsBss_004BD31C__grp: gMovieParamsBss_004BD31C@0x0, gMovieParamsBss_004BD320@0x4 */
unsigned char gMovieParamsBss_004BD31C__grp[0x64] __attribute__((aligned(4)));
#endif
