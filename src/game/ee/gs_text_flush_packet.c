#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct { u64 d; s32 x8; Q *xC; } S;
extern S *gGsText_00201E5C;
#define BIT 0x1000000000000ULL
#define BIT2 0x4000000000000ULL
void GsText_FlushPacket_0_001E21E0(void) {
    s32 n = 5;
    if (gGsText_00201E5C->x8 != 0) {
        if (!(gGsText_00201E5C->d & BIT)) n = 6;
        gGsText_00201E5C->xC->q = 0;
        gGsText_00201E5C->xC->w[0] = n | 0x20000000;
        gGsText_00201E5C->xC->w[1] = (u32)(gGsText_00201E5C->xC + n + 1);
        gGsText_00201E5C->xC++;
        if (!(gGsText_00201E5C->d & BIT)) {
            gGsText_00201E5C->xC->q = 0;
            gGsText_00201E5C->xC->w[3] = 0x51000005;
            gGsText_00201E5C->xC++;
        }
        gGsText_00201E5C->xC->d[0] = 0x1000000000008004ULL;
        gGsText_00201E5C->xC->d[1] = 0xE;
        gGsText_00201E5C->xC++;
        gGsText_00201E5C->xC->d[0] = 0;
        gGsText_00201E5C->xC->d[1] = 0x3F;
        gGsText_00201E5C->xC++;
        gGsText_00201E5C->xC->d[0] = 0;
        gGsText_00201E5C->xC->d[1] = (gGsText_00201E5C->d & BIT2) ? 9 : 8;
        gGsText_00201E5C->xC++;
        gGsText_00201E5C->xC->d[0] = 0x31001;
        gGsText_00201E5C->xC->d[1] = (gGsText_00201E5C->d & BIT2) ? 0x48 : 0x47;
        gGsText_00201E5C->xC++;
        gGsText_00201E5C->xC->d[0] = 0x48;
        gGsText_00201E5C->xC->d[1] = (gGsText_00201E5C->d & BIT2) ? 0x43 : 0x42;
        gGsText_00201E5C->xC++;
    }
}
