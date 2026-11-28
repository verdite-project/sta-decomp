#include "common.h"
#include "game/ee.h"


s32 Mc_StartCopyFile_1_001D6AE8(u32 a, u32 b, s32 c, s32 d, s32 e)
{
    if (gMcState_004B63B8.cmd != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    gMcState_004B63B8.cmd = 8;
    gMcState_004B63B8.x90 = 0;
    gMcState_004B63B8.step = 0;
    gMcState_004B63B8.port = a;
    gMcState_004B63B8.slot = b;
    gMcState_004B63B8.name = c;
    gMcState_004B63B8.xA4 = d;
    gMcState_004B63B8.xAC = e;
    gMcState_004B63B8.err = 0x3C;
    return 0;
}
