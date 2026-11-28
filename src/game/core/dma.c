#include "common.h"
void memset(s32 *, s32, s32);        /* extern */
extern s32 D_00483100[];

void Dma_ClearBuffer_1_00178DB0(void) {
    memset(D_00483100, 0, 0x3000);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_00483100__grp: D_00483100@0x0 */
unsigned char D_00483100__grp[0x3000] __attribute__((aligned(16)));
#endif
