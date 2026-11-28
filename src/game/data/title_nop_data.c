#include "common.h"

/* data_001F32A0: the game's data at 0x001F32A0..., one object per label. */
/* used by: enemy_list, storage_draw, title */
#pragma explicit_zero_data on

void Player_LoadModel_1_001C9CD0(void);
extern s32 D_001F32B0[];
extern s32 D_001F3320[];

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/storage_draw.c */
s32 D_001F32A0[0x4] = { 0, 1, 2, 3 };
#endif
s32 D_001F32B0[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 D_001F32F0[0x8] = { 0, 5, 0, (s32)D_001F32B0, 7, -0x3fc00000, 0, 0 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
Vec D_001F3310 = { 0.0f, 0.0f, 639.0f, 447.0f };
#endif
s32 D_001F3320[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 D_001F3360[0x8] = { 0, 5, 0, (s32)D_001F3320, 7, -0x3fc00000, 0, 0 };
char gStrNewGame_001F3380[0xd] = "NEW GAME\000\000\000\000\000";
u8 D_001F338D[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
char gStrLoadGame_001F3390[0xd] = "LOAD GAME\000\000\000\000";
u8 D_001F339D[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
s32 D_001F33A0[0x100] = { (s32)Player_LoadModel_1_001C9CD0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_list.c */
Vec D_001F37A0 = { 128.0f, 128.0f, 128.0f, 1.0f };
#endif
