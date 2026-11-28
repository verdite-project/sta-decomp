#include "common.h"

/* bss_004A32C8: the game's .bss from 0x004A32C8, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: item_menu_reset, pause_menu_entry, pause_menu_open, shop,
   status */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/shop.c */
void *D_004A32EC[0x1];
s32 D_004A32E8[0x1];
s32 D_004A32E4[0x1];
s32 D_004A32E0[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/pause_menu_entry.c */
u8 D_004A32C8[0x18] __attribute__((aligned(8))); /* also D_004A32CC */
#endif
