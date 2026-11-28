#include "common.h"

/* rodata_001FD5B0: the game's data at 0x001FD5B0..., one object per label. */
/* used by: item_menu_draw, text_0019CEF0.s */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/item_menu_draw.c */
const s8 gItemMenuDrawRodata_001FD5B0[0x8] = "+%d\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/item_menu_proc_draw_info.c */
const s32 gItemMenuProcDrawInfoRodata_001FD5B8[0x2] = { 0x643325, 0 };
const char gStrD_001FD5C0[0x6] = "(+%d)\000";
const char gStr31f_001FD5C8[0x6] = "%3.1f\000";
#endif
static const u8 pad_001FD5CE[0x2] __attribute__((aligned(2))) = { 0 };
