#include "common.h"

/* data_001F3160: the game's data at 0x001F3160..., one object per label. */
/* used by: game_over_reset, notify, pause_menu_open, shop_draw */
#pragma explicit_zero_data on

extern s32 gPauseMenuOpenData_001F3180[];
extern s32 gPauseMenuOpenData_001F3220[];

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/pause_menu_open.c */
s32 gPauseMenuOpenData_001F3160[0x8] = { 0, 1, 2, 3, 4, 0, 0, 0 };
s32 gPauseMenuOpenData_001F3180[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 gPauseMenuOpenData_001F31C0[0x8] = { 0, 5, 0, (s32)gPauseMenuOpenData_001F3180, 7, -0x3fc00000, 0, 0 };
f32 gPauseMenuOpenData_001F31E0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gPauseMenuOpenData_001F3200[0x4] = { 0.0f, 0.0f, 640.0f, 448.0f };
f32 gPauseMenuOpenData_001F3210[0x4] = { 0.0f, 0.0f, 128.0f, 128.0f };
s32 gPauseMenuOpenData_001F3220[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 gPauseMenuOpenData_001F3260[0x8] = { 0, 5, 0, (s32)gPauseMenuOpenData_001F3220, 7, -0x3fc00000, 0, 0 };
#endif
