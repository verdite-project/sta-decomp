#include "common.h"

/* rodata_001FD118: the game's data at 0x001FD118..., one object per label. */
/* used by: load_menu, option */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
const s8 gOptionRodata_001FD118[0x8] = "%d\000\000\000\000\000\000";
const s8 gOptionRodata_001FD120[0x8] = "MAX\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/load_menu.c */
const s8 gLoadMenuRodata_001FD128[0x10] __attribute__((aligned(8))) = "SAVEDATA%d\000\000\000\000\000\000";
const s8 gLoadMenuRodata_001FD138[0x10] __attribute__((aligned(8))) = "HP %4d/%4d\000\000\000\000\000\000";
const s8 gLoadMenuRodata_001FD148[0x10] __attribute__((aligned(8))) = "MP %4d/%4d\000\000\000\000\000\000";
const s8 gLoadMenuRodata_001FD158[0x18] __attribute__((aligned(8))) = "LOCATION\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
const s8 gLoadMenuRodata_001FD170[0x18] __attribute__((aligned(8))) = "TIME %2d:%2d:%2d\000\000\000\000\000\000\000\000";
const s8 gLoadMenuRodata_001FD188[0x8] = " EMPTY \000";
const s8 gLoadMenuRodata_001FD190[0x10] __attribute__((aligned(8))) = { 0x2d, 0x2d, 0x2d, 0x2d, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
