#include "common.h"
#include "game/ee.h"
extern s32 gMcStepReadBss_004B63B4[];
s32 Mc_StepGetInfo_3_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
void *memcpy(void *, void *, s32);
void memset(void *, s32, s32);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcRead(s32, void *, s32);
s32 sceMcClose(s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 Mc_StepRead_4_001D5F88(void) {
    s32 step = gMcState_004B63B8.step;
    s32 j = gMcState_004B63B8.slot;
    s32 i = gMcState_004B63B8.port;
    s32 r;
    s32 e;
    switch (step) {
    case 0:
        gMcStepReadCheckedBss_004B6474[0] = 0;
        gMcStepReadBss_004B63B4[0] = 0;
        gMcState_004B63B8.step++;
        gMcState_004B63B8.retry = 0;
    case 1:
        gMcState_004B63B8.x90 = Mc_StepGetInfo_3_001D3BF0(i, j, &gMcState_004B63B8.type[i * 4 + j], &gMcState_004B63B8.free[i * 4 + j], &gMcState_004B63B8.format[i * 4 + j], gMcState_004B63B8.x90);
        if (gMcState_004B63B8.x90 > 0) break;
        e = Mc_GetInfoStatus_2_001D3CE0(gMcState_004B63B8.x90);
        gMcState_004B63B8.err = e;
        if (e != 0) {
            gMcState_004B63B8.cmd = 0;
            return -10;
        }
        if (gMcState_004B63B8.type[i * 4 + j] != 2) {
            gMcState_004B63B8.step = 100;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 2:
        if (sceMcOpen(i, j, gMcState_004B63B8.name, 1) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.step = 100;
                break;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 3:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (gMcState_004B63B8.retry == 2) {
                Mc_SetErrorStatus_4_001D3DA8(r);
                if (gMcState_004B63B8.err == 100) gMcState_004B63B8.err = 0x47;
                gMcState_004B63B8.step = 100;
                gMcState_004B63B8.x90 = -1;
                gMcState_004B63B8.cmd = 0;
                return r;
            }
            gMcState_004B63B8.retry++;
            gMcState_004B63B8.step--;
            break;
        }
        gMcStepReadCheckedBss_004B6474[0] = r;
        gMcState_004B63B8.step++;
        break;
    case 4:
        memset(D_004B6478, 0, 0x400);
        gMcState_004B63B8.retry = 0;
        gMcState_004B63B8.step++;
        break;
    case 5:
        if (sceMcRead(gMcStepReadCheckedBss_004B6474[0], D_004B6478, 0x400) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.step = 100;
                break;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 6:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.x90 = r;
                gMcState_004B63B8.step = 100;
                break;
            }
            gMcState_004B63B8.retry++;
            gMcState_004B63B8.step--;
            break;
        }
        gMcState_004B63B8.retry = 0;
        if (gMcState_004B63B8.size < gMcStepReadBss_004B63B4[0] + r) {
            r = gMcState_004B63B8.size - gMcStepReadBss_004B63B4[0];
            memcpy(gMcState_004B63B8.buf + gMcStepReadBss_004B63B4[0], D_004B6478, r);
            gMcState_004B63B8.step--;
            break;
        }
        memcpy(gMcState_004B63B8.buf + gMcStepReadBss_004B63B4[0], D_004B6478, r);
        gMcStepReadBss_004B63B4[0] += r;
        gMcState_004B63B8.step++;
        break;
    case 7:
        gMcState_004B63B8.retry = 0;
        gMcState_004B63B8.step++;
        break;
    case 8:
        if (sceMcClose(gMcStepReadCheckedBss_004B6474[0]) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.cmd = 0;
                gMcState_004B63B8.err = 0x47;
                return -1;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 9:
        if (sceMcSync(1, 0, &r) == 0) break;
        gMcState_004B63B8.cmd = 0;
        if (r < 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.err = 0x47;
                return r;
            }
            gMcState_004B63B8.retry++;
            gMcState_004B63B8.step--;
            break;
        }
        gMcState_004B63B8.err = 0x48;
        return 1;
    case 100:
        if (gMcStepReadCheckedBss_004B6474[0] < 0) {
            gMcState_004B63B8.err = 0x47;
            gMcState_004B63B8.cmd = 0;
            return gMcState_004B63B8.x90;
        }
        gMcState_004B63B8.retry = 0;
        gMcState_004B63B8.step++;
        break;
    case 101:
        if (sceMcClose(gMcStepReadCheckedBss_004B6474[0]) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.cmd = 0;
                gMcState_004B63B8.err = 0x47;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 102:
        if (sceMcSync(1, 0, &r) == 0) break;
        gMcState_004B63B8.err = 0x47;
        gMcState_004B63B8.cmd = 0;
        return -100;
    }
    return 0;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* The read byte count precedes McState. Mc_GetResult reads state.x94
 * and Mc_SetErrorStatus writes state.err through their named symbols. */
/* data group (src/game/data/pad_get_connected_bss_004B5DD0.c): gMcStepReadBss_004B63B4__grp: gMcStepReadBss_004B63B4@0x0, gMcGetResultBss_004B644C@0x98, gMcSetErrorStatusBss_004B6450@0x9c */
struct {
    s32 bytesRead;
    McState state;
} gMcStepReadBss_004B63B4__grp __attribute__((aligned(4)));
#endif
