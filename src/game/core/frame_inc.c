#include "common.h"
#ifndef NONMATCHING
extern s32 gFrameIncSdata_00201C80;
#else
/* data twins (src/game/data/sdata.c): gFrameIncSdata_00201C80 */
static s32 gFrameIncSdata_00201C80 = 0x532525;
#endif
s32 Frame_IncCounter_1_0015C9E0(void) { return gFrameIncSdata_00201C80++; }
