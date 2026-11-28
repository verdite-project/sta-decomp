#include "common.h"

/* bss_003139E0: the game's .bss from 0x003139E0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: fx, lightning, map_collision, map_command, menu, message,
   noise_eval, noise_fbm, pad, player, player_se, text_0015F540.s,
   text_0015FC60.s, vibration */

u8 D_003174F0[0x27010];
u8 D_003174E0[0x10];
u8 D_003172E0[0x200];
u8 D_00317274[0x6c] __attribute__((aligned(4))); /* also D_00317278 */
f32 D_00317270[0x1];
f32 D_0031726C[0x1];
u8 D_00317254[0x18] __attribute__((aligned(4))); /* also D_00317258 */
f32 D_00317250[0x1];
f32 D_0031724C[0x1];
f32 D_00317248[0x1];
f32 D_00317244[0x1];
f32 D_00317240[0x1];
f32 D_0031723C[0x1];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/script/map_command.c */
u8 D_00317238[0x4]; /* also D_0031723A */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu.c */
u16 D_00317230[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/math/noise_fbm.c */
s32 D_00316A20[0x204];
u8 D_00315200[0x1820];
u8 D_003141F0[0x1010];
f32 D_003139E0[0x204];
#endif
