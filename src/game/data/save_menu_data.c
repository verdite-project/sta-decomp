#include "common.h"

/* data_001F2A10: the game's data at 0x001F2A10..., one object per label. */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
f32 gSaveMenuSlotData_001F2A10[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 gSaveMenuSlotData_001F2A30[0x8] = { -1, 0, 0, 0, 0, 0, 0, 0 };
f32 gSaveMenuData_001F2A50[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
