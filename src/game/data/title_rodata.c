#include "common.h"

/* rodata_001FD870: the game's data at 0x001FD870..., one object per label. */
/* used by: title */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
const char gStrCdrom0TargetOpeningPss1_001FD870[0x1d] = "cdrom0:\\TARGET\\OPENING.PSS;1\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
const s8 gTitleRodata_001FD890[0x1d] = "\\TARGET\\STA_TI.ADX\000\000\000\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
const u8 pad_001FD8AD[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
#endif
