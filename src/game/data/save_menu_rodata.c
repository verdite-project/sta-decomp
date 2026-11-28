#include "common.h"

/* rodata_001FCDC8: the game's data at 0x001FCDC8..., one object per label. */
/* used by: save_menu */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu.c */
const s8 gSaveMenuRodata_001FCDC8[0x8] = "SLOT %d\000";
#endif
