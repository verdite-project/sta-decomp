#include "common.h"

/* bss_0033F540: the game's .bss from 0x0033F540, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: script_op, sfx, sfx_all, sfx_system, text_00169F40.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
u8 gSfxSystemBss_003407E0[0xec130];
u8 gSfxSystemBss_003406E0[0x100];
u8 gSfxBss_003406D0[0x10];
s32 gSfxAllBss_0033F6D0[0x400];
u8 gScriptOpBss_0033F540[0x190];
#endif
