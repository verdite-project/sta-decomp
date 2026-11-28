#include "common.h"

/* rodata_001FD648: the game's data at 0x001FD648..., one object per label. */
/* used by: game_over_reset, pause_menu_entry */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/pause_menu_entry.c */
const u8 D_001FD648[0x7] = "OPTION\000";
const char D_001FD650[0x10] __attribute__((aligned(8))) = { -0x7e, 0x6f, -0x7e, 0x60, -0x7e, 0x74, -0x7e, 0x72, -0x7e, 0x64, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/game_over_reset.c */
const char D_001FD660[0x20] __attribute__((aligned(8))) = { -0x7e, 0x66, -0x7e, 0x60, -0x7e, 0x6c, -0x7e, 0x64, -0x7f, 0x40, -0x7e, 0x6e, -0x7e, 0x75, -0x7e, 0x64, -0x7e, 0x71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
