#include "common.h"
#include "game/ee.h"


s32 Mc_StartCheck_1_001D6BB8(u32 a, u32 b)
{
    if (gMcState_004B63B8.cmd != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    gMcState_004B63B8.port = a;
    gMcState_004B63B8.slot = b;
    gMcState_004B63B8.step = 0;
    gMcState_004B63B8.cmd = 9;
    gMcState_004B63B8.err = 0x33;
    return 0;
}
