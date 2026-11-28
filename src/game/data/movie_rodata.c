#include "common.h"

/* rodata_00201920: the game's data at 0x00201920..., one object per label. */
/* used by: movie */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
const s32 gMovieRodata_00201920[0x8] = { 0x53656373, 0x72466669, 0x6f496565, 0x61654870, 0x72452070, 0x20726f72, 0x25207325, 0xa64 };
const s32 gMovieRodata_00201940[0x4] = { 0x696c7366, 0x67706d62, 0x632e, 0 };
const char gStrCdrom0_00201950[0x7] = "cdrom0\000";
const char gMovieRodata_00201958[0x8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
const char gStr1_00201960[0x8] = ";1\000\000\000\000\000\000";
const char gStrSS_00201968[0x5] = "%s%s\000";
const char gMovieRodata_00201970[0x8] = { 0x25, 0x73, 0x3a, 0x25, 0x73, 0, 0, 0 };
const char gStrHost0_00201978[0x6] = "host0\000";
#endif
static const u8 pad_0020197E[0x2] __attribute__((aligned(2))) = { 0 };
