#include "common.h"
#include "game/ee.h"
typedef struct {
    u8 p0[0x120]; u16 x120; u16 x122; u8 p124[0x40]; u16 x164; u8 p166[0x14];
    u8 x17A; u8 p17B; u8 x17C; u8 p17D; s8 x17E; s8 x17F; u8 x180; u8 p181; u8 x182;
    u8 p183[0x3D];
} PadBuf;
typedef struct { PadBuf buf[8]; u8 open[8]; } PadState;
extern PadState gPadState_004B6900;
s32 scePadInit(s32 mode);

s32 Pad_Init_3_001D7290(s32 mode) {
    PadBuf *p;
    s32 i;
    gPadState_004B6900.open[0] = 0;
    gPadState_004B6900.open[1] = 0;
    p = gPadState_004B6900.buf;
    for (i = 0; i < 8; i++) {
        p->x120 = 0;
        p->x122 = 0;
        p->x164 = 0;
        p->x17A = 0;
        p->x17C = 0;
        p->x17E = -1;
        p->x17F = -1;
        p->x180 = 0;
        p->x182 = 0;
        p++;
    }
    return scePadInit(mode);
}
