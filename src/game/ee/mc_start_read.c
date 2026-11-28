#include "common.h"
#include "game/ee.h"


s32 Mc_StartRead_2_001D6958(u32 a, u32 b, s32 c, s32 d, s32 e, s32 f)
{
    if (gMcState_004B63B8.cmd != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    gMcState_004B63B8.xB0 = f;
    gMcState_004B63B8.port = a;
    gMcState_004B63B8.slot = b;
    gMcState_004B63B8.name = c;
    gMcState_004B63B8.size = d;
    gMcState_004B63B8.cmd = 4;
    gMcState_004B63B8.xAC = e;
    gMcState_004B63B8.step = 0;
    return 0;
}
