#include "common.h"

/* data_001F3850: the game's data at 0x001F3850..., one object per label. */
/* used by: map_area_load, player */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/map/map_area_load.c */
f32 D_001F3850[0x4] = { 0.0f, 0.0f, 0.0f, 100.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
f32 D_001F3860[0x4] = { 1000.0f, 15000.0f, 0.0f, 1.0f };
f32 D_001F3870[0x4] = { 1.0f, 0.1f, 0.0f, 0.0f };
s32 D_001F3880[0x10] = { 0x708, 0x96, 0xe10, 0x708, 0xa8c, 0x708, 0, 0, 0xa8c, 0x1c2, 0x1518, 0xa8c, 0xe10, 0xa8c, 0, 0 };
#endif
