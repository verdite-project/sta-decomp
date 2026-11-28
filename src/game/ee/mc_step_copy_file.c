#include "common.h"
#include "game/data.h"
#include "game/ee.h"
typedef struct { u8 p[0x10]; u32 x10; } DE;
#ifndef NONMATCHING
extern s32 gMcStepCopyFileBss_004B63A4[];
extern s32 gMcStepCopyFileBss_004B63A8[];
extern s32 gMcStepCopyFileBss_004B63AC[];
extern s32 gMcStepCopyFileBss_004B63B0[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): gMcStepCopyFileBss_004B63A4 */
static s32 gMcStepCopyFileBss_004B63A4[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): gMcStepCopyFileBss_004B63A8 */
static s32 gMcStepCopyFileBss_004B63A8[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): gMcStepCopyFileBss_004B63AC */
static s32 gMcStepCopyFileBss_004B63AC[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): gMcStepCopyFileBss_004B63B0 */
static s32 gMcStepCopyFileBss_004B63B0[0x1];
#endif
extern DE gMcDirBuf_004B68C0[];
s32 Mc_StepGetInfo_3_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
s32 sceOpen(s8 *, s32);
void strcpy(s8 *, s32);
s32 sceLseek(s32, s32, s32);
s32 sceRead(s32, void *, s32);
void sceClose(s32);
s32 sceMcGetDir(s32, s32, s32, s32, s32, DE *);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcWrite(s32, void *, s32);
s32 sceMcClose(s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 Mc_StepCopyFile_4_001D58C0(void) {
    s32 step = gMcState_004B63B8.step;
    s32 j = gMcState_004B63B8.slot;
    s32 i = gMcState_004B63B8.port;
    s8 buf[0x40];
    s32 r;
    s32 e;
    s32 n;
    s32 fd;
    s32 w;
    s32 k;
    switch (step) {
    case 0:
        gMcStepReadCheckedBss_004B6474[0] = 0;
        gMcStepCopyFileBss_004B63AC[0] = 0;
        gMcStepCopyFileBss_004B63B0[0] = 0;
        gMcState_004B63B8.step++;
        gMcState_004B63B8.retry = 0;
        break;
    case 1:
        gMcState_004B63B8.x90 = Mc_StepGetInfo_3_001D3BF0(i, j, &gMcState_004B63B8.type[i * 4 + j], &gMcState_004B63B8.free[i * 4 + j], &gMcState_004B63B8.format[i * 4 + j], gMcState_004B63B8.x90);
        if (gMcState_004B63B8.x90 > 0) break;
        e = Mc_GetInfoStatus_2_001D3CE0(gMcState_004B63B8.x90);
        gMcState_004B63B8.err = e;
        if (e != 0) {
            gMcState_004B63B8.cmd = 0;
            return -10;
        }
        gMcState_004B63B8.step++;
        break;
    case 2:
        if (gMcState_004B63B8.type[i * 4 + j] != 2) {
            gMcState_004B63B8.cmd = 0;
            gMcState_004B63B8.err = 0x3D;
            return -4;
        }
        gMcState_004B63B8.step++;
        break;
    case 3:
        if (sceMcGetDir(i, j, gMcState_004B63B8.name, 0, 1, gMcDirBuf_004B68C0) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.cmd = 0;
                gMcState_004B63B8.err = 100;
                return -1;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 4:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (gMcState_004B63B8.retry == 2) {
                if (r == -2) {
                    gMcState_004B63B8.err = 3;
                } else if (r == -4) {
                    gMcStepWriteCheckedBss_004B68D0[0] = 0;
                    gMcState_004B63B8.step++;
                    break;
                } else {
                    gMcState_004B63B8.err = 100;
                }
                return r;
            }
            gMcState_004B63B8.retry++;
            gMcState_004B63B8.step--;
            break;
        }
        if (r == 0) gMcStepWriteCheckedBss_004B68D0[0] = 0;
        gMcState_004B63B8.step++;
        break;
    case 5:
        n = (gMcDirBuf_004B68C0[0].x10 + 0x3FF) / 1024 + gMcState_004B63B8.free[i * 4 + j];
        if (gMcDirBuf_004B68C0[0].x10 == 0 && n < 3) {
            gMcState_004B63B8.cmd = 0;
            gMcState_004B63B8.err = 0x1F;
            return -6;
        }
        strcpy(buf, gMcState_004B63B8.xA4);
        fd = sceOpen(buf, 1);
        gMcStepCopyFileBss_004B63A4[0] = fd;
        if (fd < 0) {
            gMcState_004B63B8.cmd = 0;
            gMcState_004B63B8.err = 0x3D;
            return fd;
        }
        if (gMcState_004B63B8.xAC != 0) {
            gMcStepCopyFileBss_004B63AC[0] = gMcState_004B63B8.xAC;
        } else {
            gMcStepCopyFileBss_004B63AC[0] = sceLseek(fd, 0, 2);
            sceLseek(gMcStepCopyFileBss_004B63A4[0], 0, 0);
        }
        k = gMcDirBuf_004B68C0[0].x10 != 0 ? 0 : 2;
        if (n - k < (gMcStepCopyFileBss_004B63AC[0] + 0x3FF) / 1024) {
            gMcState_004B63B8.err = 0x3D;
            gMcState_004B63B8.cmd = 0;
            return -0x65;
        }
        gMcState_004B63B8.step = 8;
        gMcState_004B63B8.retry = 0;
        break;
    case 8:
        if (sceMcOpen(i, j, gMcState_004B63B8.name, gMcStepWriteCheckedBss_004B68D0[0] == 0 ? 0x203 : 3) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.cmd = 0;
                gMcState_004B63B8.err = 0x3D;
                return -0xB;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 9:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (gMcState_004B63B8.retry == 2) {
                Mc_SetErrorStatus_4_001D3DA8(r);
                if (gMcState_004B63B8.err == 100) gMcState_004B63B8.err = 0x3D;
                gMcState_004B63B8.step = 100;
                gMcState_004B63B8.x90 = -1;
                break;
            }
            gMcState_004B63B8.retry++;
            gMcState_004B63B8.step--;
            break;
        }
        gMcStepReadCheckedBss_004B6474[0] = r;
        gMcState_004B63B8.step++;
        break;
    case 10:
        if ((gMcStepCopyFileBss_004B63A8[0] = sceRead(gMcStepCopyFileBss_004B63A4[0], D_004B6478, 0x400)) <= 0) {
            gMcState_004B63B8.step = 13;
            break;
        }
        gMcState_004B63B8.retry = 0;
        gMcState_004B63B8.step++;
        break;
    case 11:
        w = sceMcWrite(gMcStepReadCheckedBss_004B6474[0], D_004B6478, gMcStepCopyFileBss_004B63A8[0]);
        if (w != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.x90 = -1;
                gMcState_004B63B8.step = 100;
                break;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 12:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (gMcState_004B63B8.retry != 2 && r != -8) {
                gMcState_004B63B8.retry++;
                gMcState_004B63B8.step--;
                break;
            }
            gMcState_004B63B8.x90 = -1;
            gMcState_004B63B8.step = 100;
            break;
        }
        gMcState_004B63B8.retry = 0;
        gMcStepCopyFileBss_004B63B0[0] += gMcStepCopyFileBss_004B63A8[0];
        if (gMcStepCopyFileBss_004B63B0[0] < gMcStepCopyFileBss_004B63AC[0]) {
            gMcState_004B63B8.step -= 2;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 13:
        sceClose(gMcStepCopyFileBss_004B63A4[0]);
        gMcState_004B63B8.step++;
        break;
    case 14:
        w = sceMcClose(gMcStepReadCheckedBss_004B6474[0]);
        if (w != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.x90 = -1;
                gMcState_004B63B8.step = 100;
                break;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 15:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.cmd = 0;
                gMcState_004B63B8.err = 0x3D;
                return r;
            }
            gMcState_004B63B8.retry++;
            gMcState_004B63B8.step--;
            break;
        }
        gMcState_004B63B8.err = 0x3E;
        gMcState_004B63B8.cmd = 0;
        return 1;
    case 100:
        if (gMcStepCopyFileBss_004B63A4[0] != 0) sceClose(gMcStepCopyFileBss_004B63A4[0]);
        if (gMcStepReadCheckedBss_004B6474[0] < 0) {
            gMcState_004B63B8.err = 0x3D;
            gMcState_004B63B8.cmd = 0;
            return -999;
        }
        gMcState_004B63B8.retry = 0;
        break;
    case 101:
        if (sceMcClose(gMcStepReadCheckedBss_004B6474[0]) != 0) {
            if (gMcState_004B63B8.retry == 2) {
                gMcState_004B63B8.cmd = 0;
                gMcState_004B63B8.err = 0x3D;
                return -999;
            }
            gMcState_004B63B8.retry++;
            break;
        }
        gMcState_004B63B8.step++;
        break;
    case 102:
        if (sceMcSync(1, 0, &r) == 0) break;
        gMcState_004B63B8.err = 0x3D;
        gMcState_004B63B8.cmd = 0;
        return -999;
    }
    return 0;
}
