#include "common.h"
extern s32 gDmaBss_00483100[];
void Dma_SprInit_1_00178D20(void) {
    *(volatile s32 *)0x1000E020 = -0x400;
    *(volatile s32 *)0x1000E010 = 0x200;
    *(volatile s32 **)0x1000D410 = gDmaBss_00483100;
    *(volatile s32 *)0x1000D420 = 0x300;
    *(volatile s32 *)0x1000D480 = 0x70000000;
    *(volatile s32 *)0x1000E020 |= 0x200;
    *(volatile s32 *)0x1000D400 = 0x101;
    asm { sync; nop; L: nop; nop; nop; nop; nop; bc0f L; nop }
}
