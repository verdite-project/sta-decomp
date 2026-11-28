#include "common.h"
#include "game/core.h"
extern volatile s32 D_00202020;
extern volatile s32 D_0020201C;
extern volatile s32 D_00202024;

/* Timer_Update_3_00178760 */
void Timer_Update_3_00178760(void)
{
    D_0020201C += *(volatile s32 *)0x10000000 + D_00202020 * 5000;
    *(volatile s32 *)0x10000000 = 0;
    D_00202020 = 0;
    D_00202024 = 0;
}

/* Timer_GetTicks_3_001787A0 */
 s32 Timer_GetTicks_3_001787A0(void) { return *(volatile s32 *)0x10000000 + D_00202020 * 5000; }

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sbss.c): D_00202020__grp: D_00202020@0x0 */
unsigned char D_00202020__grp[0x4] __attribute__((section(".sbss"))) __attribute__((aligned(16)));
#endif
