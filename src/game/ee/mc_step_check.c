#include "common.h"
#include "game/ee.h"
typedef struct { s32 type[8]; s32 free[8]; s32 format[8]; s32 res[8]; s32 port; s32 slot; s32 x88; s32 step; s32 x90; s32 x94; s32 err; s32 retry; } T;
s32 sceMcGetInfo(s32, s32, s32 *, s32 *, s32 *);
s32 sceMcSync(s32, s32 *, s32 *);
s32 Mc_StepCheck_4_001D3E30(void) {
    T *t = &gMcState_004B63B8;
    s32 step = t->step;
    s32 i = t->port;
    s32 j = t->slot;
    s32 r;
    s32 e;
    switch (step) {
    case 0:
        t->step = 1;
        t->retry = 0;
        break;
    case 1:
        if (sceMcGetInfo(i, j, &gMcState_004B63B8.type[i * 4 + j], &gMcState_004B63B8.free[i * 4 + j], &gMcState_004B63B8.format[i * 4 + j]) != 0) {
            if (t->retry == 2) {
                t->err = 100;
                return -10;
            }
            t->retry++;
            break;
        }
        t->step++;
        break;
    case 2:
        if (sceMcSync(1, 0, &r) == 0) break;
        t->res[i * 4 + j] = r;
        if (r < 0) {
            if (t->retry == 2) {
                t->err = Mc_GetInfoStatus_2_001D3CE0(r);
                return -10;
            }
        } else {
            t->x88 = 0;
            e = Mc_GetInfoStatus_2_001D3CE0(r);
            t->err = e;
            return e == 0 ? 1 : -10;
        }
        t->retry++;
        t->step--;
        break;
    default:
        if (sceMcSync(1, 0, &r) == 0) break;
        gMcState_004B63B8.err = 100;
        gMcState_004B63B8.cmd = 0;
        return -10;
    }
    return 0;
}
