#include "common.h"

/* rodata_001FAB40: the game's data at 0x001FAB40..., one object per label. */
/* used by: game_main, sound_start, text.s */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
const u8 gGameMainRodata_001FAB40[0x18] = "\\TARGET\\STAZ.STZ\000\000\000\000\000\000\000\000";
const s8 gSoundStartRodata_001FAB58[0x1] = { 0x53 };
const u8 gSoundStartRodata_001FAB59[0x1] __attribute__((aligned(1))) = { 0x54 };
const u8 gSoundStartRodata_001FAB5A[0x1] __attribute__((aligned(2))) = { 0x53 };
const u8 gSoundStartRodata_001FAB5B[0x5] __attribute__((aligned(1))) = { 0x45, 0, 0, 0, 0 };
const u8 gSoundStartRodata_001FAB60[0x1] = { 0x53 };
const u8 gSoundStartRodata_001FAB61[0x1] __attribute__((aligned(1))) = { 0x54 };
const u8 gSoundStartRodata_001FAB62[0x1] __attribute__((aligned(2))) = { 0x41 };
const u8 gSoundStartRodata_001FAB63[0x5] __attribute__((aligned(1))) = { 0x4d, 0, 0, 0, 0 };
const u8 gSoundStartRodata_001FAB68[0x1] = { 0x53 };
const u8 gSoundStartRodata_001FAB69[0x1] __attribute__((aligned(1))) = { 0x54 };
const u8 gSoundStartRodata_001FAB6A[0x1] __attribute__((aligned(2))) = { 0x4d };
const u8 gGameMainRodata_001FAB6B[0x5] __attribute__((aligned(1))) = { 0x49, 0, 0, 0, 0 };
const u8 gGameMainRodata_001FAB70[0x1] = { 0x53 };
const u8 gGameMainRodata_001FAB71[0x1] __attribute__((aligned(1))) = { 0x45 };
const u8 gGameMainRodata_001FAB72[0x1] __attribute__((aligned(2))) = { 0x45 };
const u8 gGameMainRodata_001FAB73[0xd] __attribute__((aligned(1))) = { 0x61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
