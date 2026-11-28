#include "common.h"

/* data_001F2A10: the game's data at 0x001F2A10..., one object per label. */
/* used by: loading_draw, option, save_menu, save_menu_slot */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu_slot.c */
f32 D_001F2A10[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu_slot.c */
s32 D_001F2A30[0x8] = { -1, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu.c */
f32 D_001F2A50[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/loading_draw.c */
f32 D_001F2A70[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
f32 D_001F2A90[0xc] = { -2.0f, 5.605e-42f, -1.0f, 5.607e-42f, 0.0f, 5.608e-42f, 1.0f, 5.61e-42f, 2.0f, 5.611e-42f, 0.0f, 0.0f };
f32 D_001F2AC0[0x10] = { -4.0f, 5.605e-42f, -3.0f, 5.607e-42f, -2.0f, 5.608e-42f, -1.0f, 5.61e-42f, 0.0f, 5.611e-42f, 1.0f, 5.612e-42f, 1.5f, 5.614e-42f, 2.0f, 5.615e-42f };
f32 D_001F2B00[0x8] = { 0.0f, 5.745e-42f, 0.33f, 5.747e-42f, 0.67f, 5.748e-42f, 1.0f, 5.75e-42f };
f32 D_001F2B20[0x8] = { 1.0f, 5.745e-42f, 1.33f, 5.747e-42f, 1.67f, 5.748e-42f, 2.0f, 5.75e-42f };
#endif
