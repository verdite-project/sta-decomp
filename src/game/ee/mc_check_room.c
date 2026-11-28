#include "common.h"
#include "game/ee.h"


s32 Mc_CheckRoom_4_001D70B8(s32 i, s32 j, u32 k)
{
    s32 v = gMcState_004B63B8.free[i * 4 + j] - 2;
    if (v <= 0) {
        gMcState_004B63B8.err = 30;
        return -1;
    }
    if ((u32)v < k) {
        gMcState_004B63B8.err = 31;
        return -2;
    }
    return k;
}
