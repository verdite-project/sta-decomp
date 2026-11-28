#include "common.h"
#include "game/ee.h"
extern GsTextState *gGsText_00201E5C;
void FlushCache(s32);
#define D2_CHCR ((volatile int *)0x1000A000)
#define D2_MADR ((volatile int *)0x1000A010)
#define D2_QWC ((volatile int *)0x1000A020)
#define D2_TADR ((volatile int *)0x1000A030)
#define GIF_STAT ((volatile int *)0x10003020)
void GsText_WaitDma_1_001E3688(void) {
    FlushCache(0);
    do {
        while (*D2_CHCR & 0x100) ;
    } while (*GIF_STAT & 0xC00);
    *D2_QWC = 0;
    *D2_MADR = 0;
    *D2_TADR = gGsText_00201E5C->x8;
    FlushCache(0);
    *D2_CHCR = 0x145;
    do {
        while (*D2_CHCR & 0x100) ;
    } while (*GIF_STAT & 0xC00);
}

