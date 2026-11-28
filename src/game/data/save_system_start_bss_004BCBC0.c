#include "common.h"

/* bss_004BCBC0: the game's .bss from 0x004BCBC0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: movie, movie_params, save_system_step, save_system_update,
   text_001E8C50.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie_params.c */
u8 D_004BD320[0x60];
s32 D_004BD31C[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
s32 D_004BD318[0x1];
s32 D_004BD314[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
u8 D_004BD310[0x4]; /* also D_004BD311, D_004BD312, D_004BD313 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_step.c */
u8 D_004BCF40[0x3d0];
u8 D_004BCBC0[0x380];
#endif
