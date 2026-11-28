#include "common.h"

/* rodata_001FDC08: the game's data at 0x001FDC08..., one object per label. */
/* used by: player */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
const char D_001FDC08[0x8] = "RIFLE01\000";
const char D_001FDC10[0x8] = "JYO\000\000\000\000\000";
const char D_001FDC18[0x6] = "DM_09\000";
const char D_001FDC20[0x6] = "DM_10\000";
const char D_001FDC28[0x5] = "TEN\000\000";
#endif
const u8 pad_001FDC2D[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
