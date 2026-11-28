#include "common.h"
#include "game/ee.h"
s32 sceMcMkdir(s32, s32, s32);
s32 sceMcSync(s32, s32, s32 *);
typedef struct { char pad[0x80]; s32 a; s32 b; s32 x88; s32 state; s32 p90[2]; s32 x98; s32 retry; s32 xa0; } MC;

s32 Mc_StepMkdir_5_001D6688(void)
{
    MC *m = &gMcState_004B63B8;
    s32 res;
    s32 a = m->a;
    s32 b = m->b;
    switch (m->state) {
    case 0:
        m->state = 1;
        m->retry = 0;
        break;
    case 1:
        if (sceMcMkdir(a, b, m->xa0) != 0) {
            if (m->retry == 2) {
                m->x98 = 100;
                return -10;
            }
            m->retry++;
        } else {
            m->state++;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &res) != 0) {
            if (res == 0) {
                m->x98 = 0;
                m->x88 = 0;
                return 1;
            }
            if (m->retry == 2) {
                m->x88 = 0;
                m->x98 = 100;
                return res;
            }
            m->retry++;
            m->state--;
        }
        break;
    }
    return 0;
}

