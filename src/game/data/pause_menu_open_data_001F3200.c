#include "common.h"

/* data_001F3200: the game's data at 0x001F3200..., one object per label. */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
f32 gPauseMenuOpenData_001F3200[0x4] = { 0.0f, 0.0f, 640.0f, 448.0f };
f32 gPauseMenuOpenData_001F3210[0x4] = { 0.0f, 0.0f, 128.0f, 128.0f };
u8 gPauseMenuOpenData_001F3220[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
