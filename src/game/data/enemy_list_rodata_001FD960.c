#include "common.h"

/* rodata_001FD960: the game's data at 0x001FD960..., one object per label. */
/* used by: enemy_list */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_list.c */
const s8 gEnemyListRodata_001FD960[0x1] = { 0x53 };
const u8 gEnemyListRodata_001FD961[0x1] __attribute__((aligned(1))) = { 0x54 };
const u8 gEnemyListRodata_001FD962[0x1] __attribute__((aligned(2))) = { 0x43 };
const u8 gEnemyListRodata_001FD963[0xd] __attribute__((aligned(1))) = { 0x49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
