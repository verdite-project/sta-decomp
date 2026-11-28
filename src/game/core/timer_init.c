#include "common.h"

#ifndef NONMATCHING
extern s32 D_00201CC0;
#else
/* data twins (src/game/data/sdata.c): D_00201CC0 */
static s32 D_00201CC0 = -1;
#endif
extern volatile s32 D_00202020, D_0020201C, D_00202024;
void Timer_IntrHandler_2_001787C0(void);
s32 AddIntcHandler(s32 cause, void (*f)(void), s32 next);
void EnableIntc(s32 cause);

void Timer_Init_3_001787F0(void)
{
    *(volatile s32 *)0x10000010 = 0x1C1;
    *(volatile s32 *)0x10000020 = 5000;
    D_00201CC0 = AddIntcHandler(9, Timer_IntrHandler_2_001787C0, -1);
    EnableIntc(9);
    D_0020201C += *(volatile s32 *)0x10000000 + D_00202020 * 5000;
    *(volatile s32 *)0x10000000 = 0;
    D_00202020 = 0;
    D_00202024 = 0;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_0020201C, D_00202024 */
volatile s32 D_0020201C;
volatile s32 D_00202024;
#endif
