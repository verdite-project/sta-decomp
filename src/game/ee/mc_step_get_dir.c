#include "common.h"
#include "game/ee.h"

typedef struct {
    char pad[0x80];
    s32 port; s32 slot; s32 x88; s32 state;
    s32 x90; s32 x94; s32 x98; s32 x9c;
    s32 name; s32 xa4; s32 mode; s32 maxent; s32 table;
} T;
s32 sceMcGetDir(s32, s32, s32, s32, s32, s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 Mc_StepGetDir_4_001D3FE8(void)
{
    T *t = &gMcState_004B63B8;
    s32 r;
    s32 port = t->port;
    s32 slot = t->slot;
    switch (t->state) {
    case 0:
        t->state = 1;
        t->x9c = 0;
        break;
    case 1:
        if (sceMcGetDir(port, slot, t->name, t->mode, t->maxent, t->table) != 0) {
            if (t->x9c == 2) {
                t->x88 = 0;
                t->x98 = 100;
                return -1;
            }
            t->x9c++;
        } else {
            t->state++;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r >= 0) {
                t->x94 = r;
                t->x98 = 0;
                t->x88 = 0;
                return 1;
            }
            if (t->x9c == 2) {
                if (r == -2) t->x98 = 3;
                else if (r == -4) t->x98 = 100;
                else t->x98 = 100;
                return r;
            }
            t->x9c++;
            t->state--;
        }
        break;
    default:
        if (sceMcSync(1, 0, &r) != 0) {
            gMcState_004B63B8.err = 100;
            gMcState_004B63B8.cmd = 0;
            return -1;
        }
        break;
    }
    return 0;
}
