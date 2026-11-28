#include "common.h"

/* bss_002704D0: the game's .bss from 0x002704D0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: no code by name (reached through other data) */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/entity/actor.c */
u8 gActorBss_002704D0[0x80];
#endif
