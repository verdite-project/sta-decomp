#include "common.h"

/* rodata_001FD8C8: the game's data at 0x001FD8C8..., one object per label. */
/* used by: enemy_list, title */
#pragma explicit_zero_data on

void EnemyMgr_Update_0_001A4990(void);

const s32 D_001FD8C8[0x2] = { 0, 0 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
const char D_001FD8D0[0x1e] __attribute__((aligned(8))) = "cdrom0:\\TARGET\\PROLOGUE.PSS;1\000";
#endif
const s32 jtbl_001FD8F0[0x8] __attribute__((aligned(8))) = { (s32)((u8 *)EnemyMgr_Update_0_001A4990 + 0x6C0), (s32)((u8 *)EnemyMgr_Update_0_001A4990 + 0x6A0), (s32)((u8 *)EnemyMgr_Update_0_001A4990 + 0x6A0), (s32)((u8 *)EnemyMgr_Update_0_001A4990 + 0x420), (s32)((u8 *)EnemyMgr_Update_0_001A4990 + 0x6A0), (s32)((u8 *)EnemyMgr_Update_0_001A4990 + 0x2C8), (s32)((u8 *)EnemyMgr_Update_0_001A4990 + 0x420), 0 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_list.c */
const f32 D_001FD910[0x1] = { 128.0f };
const f32 D_001FD914[0x1] = { 0.0f };
const f32 D_001FD918[0x1] = { 128.0f };
#endif
