#include "common.h"

/* rodata_001FDE04: the game's data at 0x001FDE04..., one object per label. */
/* used by: attack_handle */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/attack_handle.c */
const s32 gAttackHandleRodata_001FDE04[0x3] __attribute__((aligned(4))) = { 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/attack_handle.c */
const s8 gAttackHandleRodata_001FDE10[0x2d] __attribute__((aligned(4))) = "abnormal sfxevent-parameter. in SFX(%d)\012\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/attack_handle.c */
const u8 pad_001FDE3D[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
#endif
