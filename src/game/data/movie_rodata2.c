#include "common.h"
#include "game/core.h"

/* rodata_00201A50: the game's data at 0x00201A50..., one object per label. */
/* used by: ending_draw, movie */
#pragma explicit_zero_data on


#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/movie.c */
const char gStrCanTOpenFileS_00201A50[0x20] = "Can't Open file %s\012\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ending_draw.c */
const s32 D_00201A70[0x44] = { 0x5241545c, 0x5c544547, 0x5f415453, 0x412e4f47, 0x5844, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (s32)func_00100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
