#include "common.h"

/* bss_004BCBC0: the game's .bss from 0x004BCBC0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: movie, movie_params, save_system_step, save_system_update,
   text_001E8C50.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
u8 gMovieParamsBss_004BD320[0x60];
s32 gMovieParamsBss_004BD31C[0x1];
s32 gMovieBss_004BD318[0x1];
s32 gMovieBss_004BD314[0x1];
u8 gMovieBss_004BD310[0x4]; /* also D_004BD311, D_004BD312, D_004BD313 */
u8 gSaveSystemStepBss_004BCF40[0x3d0];
u8 gSaveSystemStepBss_004BCBC0[0x380];
#endif
