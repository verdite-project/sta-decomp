#include "common.h"

/* rodata_001FB8C8: the game's data at 0x001FB8C8..., one object per label. */
/* used by: model_emit, sfx_all, text_0016FB80.s, texture_find,
   texture_hash */
#pragma explicit_zero_data on

const s32 D_001FB8C8[0x2] = { 0, 0 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
const s8 D_001FB8D0[0x20] __attribute__((aligned(8))) = "SFX(%d) not found from STAM\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
const s8 D_001FB8F0[0x1] = { 0x53 };
const s8 D_001FB8F1[0x1] __attribute__((aligned(1))) = { 0x54 };
const s8 D_001FB8F2[0x1] __attribute__((aligned(2))) = { 0x41 };
const s8 D_001FB8F3[0x5] __attribute__((aligned(1))) = { 0x4d, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_emit.c */
const s8 D_001FB8F8[0x1] = { 0x54 };
const u8 D_001FB8F9[0x1] __attribute__((aligned(1))) = { 0x58 };
const u8 D_001FB8FA[0x1] __attribute__((aligned(2))) = { 0x46 };
const u8 D_001FB8FB[0x5] __attribute__((aligned(1))) = { 0x4e, 0, 0, 0, 0 };
#endif
const s8 D_001FB900[0x1] = { 0x54 };
const s8 D_001FB901[0x1] __attribute__((aligned(1))) = { 0x41 };
const s8 D_001FB902[0x1] __attribute__((aligned(2))) = { 0x4e };
const s8 D_001FB903[0x5] __attribute__((aligned(1))) = { 0x49, 0, 0, 0, 0 };
const s8 D_001FB908[0x1] = { 0x54 };
const s8 D_001FB909[0x1] __attribute__((aligned(1))) = { 0x54 };
const s8 D_001FB90A[0x1] __attribute__((aligned(2))) = { 0x49 };
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture_hash.c */
const s8 D_001FB90B[0x5] __attribute__((aligned(1))) = { 0x58, 0, 0, 0, 0 };
#endif
const s8 D_001FB910[0x1] = { 0x54 };
const s8 D_001FB911[0x1] __attribute__((aligned(1))) = { 0x58 };
const s8 D_001FB912[0x1] __attribute__((aligned(2))) = { 0x4d };
