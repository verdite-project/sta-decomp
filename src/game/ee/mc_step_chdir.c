#include "common.h"
#include "game/ee.h"
s32 sceMcChdir(s32, s32, s32, s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 Mc_StepChdir_5_001D6550(void)
{
    s32 r;
    s32 port = gMcState_004B63B8.port;
    s32 slot = gMcState_004B63B8.slot;

    switch (gMcState_004B63B8.step) {
    case 0:
        gMcState_004B63B8.step = 1;
        gMcState_004B63B8.retry = 0;
        break;
    case 1:
        if (sceMcChdir(port, slot, gMcState_004B63B8.name, gMcState_004B63B8.xA4) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.err = 100;
                return -10;
            }
            gMcState_004B63B8.retry++;
        } else {
            gMcState_004B63B8.step++;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r == 0) {
            gMcState_004B63B8.cmd = 0;
            gMcState_004B63B8.err = 0;
            return 1;
        }
        if (gMcState_004B63B8.retry == 2) {
            gMcState_004B63B8.cmd = 0;
            if (r == -2) gMcState_004B63B8.err = 3; else gMcState_004B63B8.err = 100;
            return r;
        }
        gMcState_004B63B8.retry++;
        gMcState_004B63B8.step--;
        break;
    }
    return 0;
}
