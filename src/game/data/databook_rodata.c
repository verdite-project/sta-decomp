#include "common.h"

/* rodata_001FD230: the game's data at 0x001FD230..., one object per label. */
/* used by: databook, ending_play */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ending_play.c */
const char gStrCdrom0TargetEndingPss1_001FD230[0x20] = "cdrom0:\\TARGET\\ENDING.PSS;1\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ending_play.c */
const s8 D_001FD250[0x18] = "\\TARGET\\STA_SR.ADX\000\000\000\000\000\000";
#endif
const s32 D_001FD268[0x2] = { 0, 0 };
const u8 D_001FD270[0x8] = "MAP\000\000\000\000\000";
