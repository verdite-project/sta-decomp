#include "common.h"
#include "game/ee.h"
s32 Mc_GetFreeClusters_3_001D7008(s32 i, s32 j) {
    s32 r;
    if (gMcState_004B63B8.free[(i) * 4 + (j)] == 0 && gMcState_004B63B8.type[(i) * 4 + (j)] == 0) { gMcState_004B63B8.err = 1; return -1; }
    r = gMcState_004B63B8.free[(i) * 4 + (j)] - 2;
    if (r <= 0) { r = 0; gMcState_004B63B8.err = 30; }
    gMcState_004B63B8.err = 0;
    return r;
}
