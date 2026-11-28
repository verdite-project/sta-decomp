#include "common.h"

#include "game/ee.h"
s32 sceMcInit(void);

s32 Mc_Init_3_001D6F80(void)
{
    s32 r = sceMcInit();
    s32 i;
    if (r == 0) {
        gMcState_004B63B8.cmd = 0;
        gMcState_004B63B8.step = 0;
        for (i = 0; i < 4; i++) {
            gMcState_004B63B8.res[i] = 0;
            gMcState_004B63B8.res[i + 4] = 0;
        }
    }
    return r;
}
