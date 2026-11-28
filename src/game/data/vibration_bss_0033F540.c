#include "common.h"

/* bss_0033F540: the game's .bss from 0x0033F540, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: script_op, sfx, sfx_all, sfx_system, text_00169F40.s */

u8 D_003407E0[0xec130];
u8 D_003406E0[0x100];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx.c */
u8 D_003406D0[0x10];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
s32 D_0033F6D0[0x400];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/script/script_op.c */
u8 D_0033F540[0x190];
#endif
