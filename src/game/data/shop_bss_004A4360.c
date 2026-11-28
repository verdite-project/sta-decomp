#include "common.h"

/* bss_004A4360: the game's .bss from 0x004A4360, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: title */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
f32 gTitleBss_004A4370[0x1];
s32 gTitleBss_004A436C[0x1];
void *gTitleBss_004A4368[0x1];
s32 gTitleBss_004A4364[0x1];
s32 gTitleBss_004A4360[0x1];
#endif
