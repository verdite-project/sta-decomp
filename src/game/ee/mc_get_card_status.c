#include "common.h"
#include "game/ee.h"


s32 Mc_GetCardStatus_4_001D6E48(s32 a, s32 b)
{
    s32 s;
    s32 r;
    s32 n;

    s = gMcState_004B63B8.type[a * 4 + b];
    if (s == 1) {
        gMcState_004B63B8.err = 1;
        return -1;
    }
    r = gMcState_004B63B8.res[a * 4 + b];
    if (r < -2) {
        gMcState_004B63B8.err = 1;
        return -2;
    }
    if (s != 2 && s != 3) {
        gMcState_004B63B8.err = 1;
        return -5;
    }
    n = -r;
    if (s == 3) {
        switch (n) {
        case 3: gMcState_004B63B8.err = 0x14; break;
        case 4: gMcState_004B63B8.err = 0x16; break;
        case 5: gMcState_004B63B8.err = 0x15; break;
        default: gMcState_004B63B8.err = 1; break;
        }
    } else {
        switch (n) {
        case 0: gMcState_004B63B8.err = 0; break;
        case 1: gMcState_004B63B8.err = 2; break;
        case 2: gMcState_004B63B8.err = 3; break;
        default: gMcState_004B63B8.err = 1; break;
        }
    }
    if (gMcState_004B63B8.err == 1)
        return -6;
    return n;
}

