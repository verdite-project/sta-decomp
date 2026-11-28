#include "common.h"

/* bss_004A10B0: the game's .bss from 0x004A10B0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: option, option_lerp */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
s32 gOptionBss_004A10E8[0x2];
s32 gOptionBss_004A10E4[0x1];
s32 gOptionBss_004A10E0[0x1];
u8 gOptionBss_004A10DC[0x4];
f32 gOptionBss_004A10D8[0x1];
s32 gOptionBss_004A10D4[0x1];
s32 gOptionBss_004A10D0[0x1];
u8 gOptionBss_004A10C8[0x8];
u8 gOptionBss_004A10C4[0x4];
s32 gOptionBss_004A10C0[0x1];
f32 gOptionLerpBss_004A10B0[0x4];
#endif
