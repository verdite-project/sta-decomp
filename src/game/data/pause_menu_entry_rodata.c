#include "common.h"

/* rodata_001FD610: the game's data at 0x001FD610..., one object per label. */
/* used by: pause_menu_entry */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
const u8 gPauseMenuEntryRodata_001FD610[0x5] = "ITEM\000";
#endif
static const u8 pad_001FD615[0x3] __attribute__((aligned(1))) = { 0 };
