#include "common.h"

/* data_001F1BAC: the game's data at 0x001F1BAC..., one object per label. */
/* used by: actor, game_main, script */
#pragma explicit_zero_data on

s32 D_001F1BAC[0x1] = { 0 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
s8 gGameMainData_001F1BB0[0x10] __attribute__((aligned(4))) = { 0, 0, 0, 0, 0, 0, -0x38, -0x3e, 0, -0x40, -0x58, -0x3c, 0, 0, -0x80, 0x3f };
f32 gGameMainData_001F1BC0[0x1] = { 15000.0f };
f32 gGameMainData_001F1BC4[0x1] = { 32000.0f };
f32 gGameMainData_001F1BC8[0x1] = { 0.4999995f };
f32 gGameMainData_001F1BCC[0x1] = { 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
f32 gGameMainData_001F1BD0[0x4] __attribute__((aligned(4))) = { 0.0f, 0.0f, 1.0f, 1.0f };
f32 gGameMainData_001F1BE0[0x4] __attribute__((aligned(4))) = { 0.0f, 1.0f, 0.0f, 1.0f };
f32 gGameMainData_001F1BF0[0x4] __attribute__((aligned(4))) = { 0.0f, 0.0f, 1.0f, 1.0f };
f32 gGameMainData_001F1C00[0x4] __attribute__((aligned(4))) = { 0.0f, 1.0f, 0.0f, 1.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/entity/actor.c */
s16 gActorData_001F1C10[0x10] __attribute__((aligned(4))) = { 0x1db, 0x1db, 0x1db, 0x1da, 0x1dc, 0x1de, 0x1dd, -1, 0x1db, 0x1db, -1, -1, -1, -1, 0x1dd, -1 };
s16 gActorData_001F1C30[0x10] __attribute__((aligned(4))) = { 0x1e0, 0x1e0, 0x1e0, 0x1e1, 0x1e6, 0x1e2, 0x1e3, 0x1e5, 0x1e0, 0x1e0, -1, -1, -1, -1, 0x1e4, -1 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/script/script.c */
u16 gScriptData_001F1C50[0x8] __attribute__((aligned(4))) = { 0x1f4, 0x1f5, 0x1f6, 0x1f4, 0x1f5, 0x1f6, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/entity/actor.c */
s16 gActorData_001F1C60[0x8] __attribute__((aligned(4))) = { 0x1f9, 0x1fa, 0x1fb, 0x1f9, 0x1fa, 0x1fb, 0, 0 };
#endif
