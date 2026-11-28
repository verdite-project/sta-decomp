#include "common.h"
extern volatile s32 gTimerTicksSbss_00202020;
void Timer_IntrHandler_2_001787C0(void)
{
    gTimerTicksSbss_00202020++;
    *(volatile s32 *)0x10000010 |= 0x400;
    asm("sync");
    asm("ei");
}
