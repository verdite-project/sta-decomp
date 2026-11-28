#include "common.h"

/* bss_00209B70: the game's .bss from 0x00209B70, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: game_main */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
s32 gGameMainBss_00222748[0x2];
s32 gGameMainBss_00222744[0x1];
s32 gGameMainBss_00222740[0x1];
s32 gGameMainBss_0022273C[0x1];
s32 gGameMainBss_00222738[0x1];
s32 gGameMainBss_00222734[0x1];
s32 gGameMainBss_00222730[0x1];
u8 gGameMainBss_00222700[0x30];
u8 gGameMainBss_00209B70[0x18b90];
#endif
