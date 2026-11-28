#include "common.h"

/* bss_004B9EF0: the game's .bss from 0x004B9EF0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: bgm, sound_driver_call, sound_driver_flush, text_001D9FC0.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
u8 gBgmBss_004BA000[0x40];
u8 gBgmBss_004B9FC0[0x40];
u8 gBgmBss_004B9FB0[0x10]; /* also D_004B9FB4 */
u8 gBgmBss_004B9FAC[0x4];
u8 gBgmBss_004B9FA8[0x4]; /* also D_004B9FAA */
s32 gBgmBss_004B9FA4[0x1];
u8 gBgmBss_004B9FA0[0x4];
u8 gBgmBss_004B9F20[0x80]; /* also D_004B9F24, D_004B9F44, D_004B9F64, D_004B9F84 */
u8 gSoundDriverCallBss_004B9EF0[0x30]; /* also D_004B9F14 */
#endif
