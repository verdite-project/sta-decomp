#include "common.h"

/* rodata_001FD208: the game's data at 0x001FD208..., one object per label. */
/* used by: load_menu */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/load_menu.c */
const s8 gLoadMenuRodata_001FD208[0x8] = "SLOT %d\000";
#endif
