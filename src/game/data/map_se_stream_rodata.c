#include "common.h"

/* rodata_001FE88C: the game's data at 0x001FE88C..., one object per label. */
/* used by: map_se_stream */
#pragma explicit_zero_data on

const s32 D_001FE88C[0x1] = { 0 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/map_se_stream.c */
const s8 D_001FE890[0x1] = { 0x53 };
const u8 D_001FE891[0x1] __attribute__((aligned(1))) = { 0x54 };
const u8 D_001FE892[0x1] __attribute__((aligned(2))) = { 0x53 };
const u8 D_001FE893[0xd] __attribute__((aligned(1))) = { 0x45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const char D_001FE8A0[0x10] __attribute__((aligned(4))) = "se/m%3.03ds.mse\000";
#endif
