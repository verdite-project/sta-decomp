#include "common.h"

/* data_001F2DE0: the game's data at 0x001F2DE0..., one object per label. */
/* used by: databook, load_menu */
#pragma explicit_zero_data on

extern s32 D_001F2E00[];

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/load_menu.c */
f32 D_001F2DE0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook.c */
s32 D_001F2E00[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook.c */
s32 D_001F2E40[0x8] = { 0, 5, 0, (s32)D_001F2E00, 7, -0x3fc00000, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook.c */
s32 D_001F2E60[0x4] = { 0, 1, 2, 0 };
#endif
