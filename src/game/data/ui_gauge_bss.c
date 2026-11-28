#include "common.h"

/* bss_0048D170: the game's .bss from 0x0048D170, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: font_load, menu, menu_draw, text_00188010.s, ui_gauge */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu.c */
s32 D_00497B60[0x8];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/equip_draw.c */
u8 D_00496B60[0x1000];
u8 D_00495B60[0x1000];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_draw.c */
u8 D_0048DB60[0x8000];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/text_render.c */
u8 D_0048D360[0x800];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/font_load.c */
s32 D_0048D358[0x2];
s32 D_0048D354[0x1];
s32 D_0048D350[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_gauge.c */
u8 D_0048D170[0x1e0];
#endif
