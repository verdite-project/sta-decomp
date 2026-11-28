#include "common.h"
#include "game/ee.h"
typedef struct { s32 x0; s16 x4; s16 x6; s32 x8; s32 xC; u8 p[0x18]; s32 x28; s16 x2C; } S;
extern S *gGsText_00201E5C;
s32 GsText_Begin_1_001E23C8(void) {
    S *s = gGsText_00201E5C;
    if (s->x28 == 0) return -1;
    if (++s->x0 != 1) return 0;
    GsText_ResetState_0_001E2148();
    gGsText_00201E5C->x2C = 0;
    gGsText_00201E5C->x4 = 0;
    gGsText_00201E5C->xC = gGsText_00201E5C->x8;
    GsText_FlushPacket_0_001E21E0();
    return 0;
}

