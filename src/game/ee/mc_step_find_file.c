#include "common.h"
#include "game/ee.h"
typedef struct { char pad[0x80]; s32 x80; s32 x84; s32 x88; s32 x8c; s32 pad90[2]; s32 x98; s32 x9c; s32 xa0; } MC;
extern s32 gMcDirBuf_004B68C0[];
s32 sceMcGetDir(s32, s32, s32, u32, s32, s32 *);
s32 sceMcSync(s32, s32 *, s32 *);

s32 Mc_StepFindFile_5_001D67A8(void)
{
    MC *m;
    s32 st;
    s32 res;
    s32 x, y;

    m = &gMcState_004B63B8;
    st = m->x8c;
    x = m->x80;
    y = m->x84;
    switch (st) {
    case 0:
        m->x8c = 1;
        m->x9c = 0;
        break;
    case 1:
        if (sceMcGetDir(x, y, m->xa0, 0, 1, gMcDirBuf_004B68C0) != 0) {
            if (m->x9c == 2) {
                m->x88 = 0;
                m->x98 = 100;
                return -1;
            }
            m->x9c++;
            break;
        }
        m->x8c++;
        break;
    case 2:
        if (sceMcSync(1, 0, &res) == 0)
            break;
        if (res < 0) {
            if (m->x9c == 2) {
                if (res == -2) m->x98 = 3; else if (res == -4) m->x98 = 100; else m->x98 = 100;
                return res;
            }
            m->x9c++;
            m->x8c--;
            break;
        }
        if (res > 0)
            m->x98 = 0x2E;
        if (res == 0)
            m->x98 = 0x2D;
        m->x88 = 0;
        return 1;
    default:
        return 0;
    }
    return 0;
}

