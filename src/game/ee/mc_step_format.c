#include "common.h"
#include "game/ee.h"
typedef struct { char pad[0x80]; s32 a; s32 b; s32 state; s32 step; char p90[8]; s32 err; s32 retry; } S;
s32 sceMcFormat(s32, s32);
s32 sceMcSync(s32, s32, s32 *);

s32 Mc_StepFormat_4_001D6428(void)
{
    S *p = &gMcState_004B63B8;
    s32 a = p->a;
    s32 b = p->b;
    s32 res;
    switch (p->step) {
    case 0:
        p->step = 1;
        p->retry = 0;
        break;
    case 1:
        if (sceMcFormat(a, b) != 0) {
            if (p->retry == 2) {
                p->err = 0x32;
                return -10;
            }
            p->retry++;
        } else {
            p->step++;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &res) != 0) {
            if (res == 0) {
                p->state = 0;
                p->err = 0x34;
                return 1;
            }
            if (p->retry == 2) {
                p->state = 0;
                p->err = 0x32;
                return res;
            }
            p->retry++;
            p->step--;
        }
        break;
    default:
        return 0;
    }
    return 0;
}
