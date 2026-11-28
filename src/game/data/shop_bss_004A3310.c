#include "common.h"

/* bss_004A3310: the game's .bss from 0x004A3310, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: hud_draw, notify, shop, shop_draw, storage_draw,
   text_0019FD00.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/shop_draw.c */
u8 D_004A4340[0x10];
f32 D_004A433C[0x1];
u8 D_004A4330[0xc]; /* also D_004A4334 */
s32 D_004A3330[0x400];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/shop.c */
u8 D_004A332C[0x4];
u8 D_004A3328[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/notify.c */
s32 D_004A3324[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/shop_draw.c */
s32 D_004A3320[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/shop.c */
u8 D_004A331C[0x4];
s32 D_004A3318[0x1];
u8 D_004A3310[0x8] __attribute__((aligned(16))); /* also D_004A3312 */
#endif
