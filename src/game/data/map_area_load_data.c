#include "common.h"

/* data_001F3820: the game's data at 0x001F3820..., one object per label. */
/* used by: item_object_spawn */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
Vec gItemObjectSpawnData_001F3820 = { 1.0f, 1.0f, 1.0f, 1.0f };
Vec gItemObjectSpawnData_001F3830 = { 1.0f, 1.0f, 1.0f, 1.0f };
#endif
