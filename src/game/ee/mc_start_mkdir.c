#include "common.h"
#include "game/ee.h"


s32 Mc_StartMkdir_1_001D6CB0(u32 a, u32 b, s32 c)
{
    if (gMcState_004B63B8.cmd != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    gMcState_004B63B8.name = c;
    gMcState_004B63B8.slot = b;
    gMcState_004B63B8.port = a;
    gMcState_004B63B8.step = 0;
    gMcState_004B63B8.cmd = 0xD;
    return 0;
}
