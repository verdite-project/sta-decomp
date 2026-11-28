#include "common.h"

/* data_001F25B0: the game's data at 0x001F25B0..., one object per label. */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_anim.c */
f32 gUiAnimData_001F25B0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gUiAnimData_001F25D0[0x4] = { 40.0f, 83.0f, 52.0f, 157.0f };
f32 gUiAnimData_001F25E0[0x4] = { 40.0f, 180.0f, 52.0f, 254.0f };
#endif
