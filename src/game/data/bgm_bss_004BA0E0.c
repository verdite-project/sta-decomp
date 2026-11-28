#include "common.h"

/* bss_004BA0E0: the game's .bss from 0x004BA0E0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: se, se_dma, se_flush */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
u8 gSeBss_004BA2F8[0x8];
u32 gSeBss_004BA2F4[0x1];
s32 gSeBss_004BA2F0[0x1];
s32 gSeBss_004BA2EC[0x1];
u8 gSeBss_004BA2E8[0x4];
u32 gSeBss_004BA2E4[0x1];
u8 gSeBss_004BA2E0[0x4];
u8 gSeFlushBss_004BA0E0[0x200]; /* also D_004BA0E1 */
#endif
