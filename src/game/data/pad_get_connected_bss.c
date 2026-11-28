#include "common.h"

/* bss_004A5A60: the game's .bss from 0x004A5A60, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: item_object, item_object_spawn, text_001AE510.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
u8 gItemObjectSpawnBss_004AC5A0[0x4]; /* also D_004AC5A2 */
u8 gMapStateBss_004AA440[0x2160];
u8 gSaveByteBss_004A5A60[0x49e0];
#endif
