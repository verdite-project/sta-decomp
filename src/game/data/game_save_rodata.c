#include "common.h"

/* rodata_001FAAE8: the game's data at 0x001FAAE8..., one object per label. */
/* used by: game_save */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
const s8 gGameSaveRodata_001FAAE8[0xe] = "sta_abyss.ico\000";
const s8 gGameSaveRodata_001FAAF8[0x5] = "PS2D\000";
const s8 gGameSaveRodata_001FAB00[0x20] __attribute__((aligned(8))) = { -0x7d, 0x56, -0x7d, -0x7d, -0x7d, 0x68, -0x7d, 0x45, -0x7d, 0x5e, -0x7d, -0x71, -0x7f, 0x5b, -0x7d, 0x41, -0x7d, 0x72, -0x7d, 0x58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
