#include "common.h"

/* data_001F25B0: the game's data at 0x001F25B0..., one object per label. */
/* used by: font_draw, text_00184280.s, text_00185D70.s, ui_anim, ui_gauge */
#pragma explicit_zero_data on

extern u8 D_001FC980[];
extern u8 D_001FC988[];
extern u8 D_001FC998[];
extern u8 D_001FC9A8[];
extern u8 D_001FC9B0[];
extern u8 D_001FC9B8[];

f32 D_001F25B0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F25D0[0x4] = { 40.0f, 83.0f, 52.0f, 157.0f };
f32 D_001F25E0[0x4] = { 40.0f, 180.0f, 52.0f, 254.0f };
s32 D_001F25F0[0x10] = { -0x80000000, -0x7fefeff0, -0x7fdfdfe0, -0x7fcfcfd0, -0x7fbfbfc0, -0x7fafafb0, -0x7f9f9fa0, -0x7f8f8f90, -0x7f000001, -0x7f000001, -0x7f000001, -0x7f000001, -0x7f000001, -0x7f000001, -0x7f000001, -0x7f000001 };
f32 D_001F2630[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2650[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2670[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_proc_draw_weight.c */
s32 D_001F2690[0x8] = { (s32)D_001FC980, (s32)D_001FC988, (s32)D_001FC998, (s32)D_001FC9A8, (s32)D_001FC9B0, (s32)D_001FC9B8, 0, 0 };
#endif
f32 D_001F26B0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F26D0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F26F0[0x4] = { 615.0f, 275.0f, 619.0f, 399.0f };
f32 D_001F2700[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2720[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
