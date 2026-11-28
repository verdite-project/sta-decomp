#include "common.h"
#include "game/ee.h"
extern GsTextState *gGsText_00201E5C;

void GsText_SetVram_0_001E1F28(s32 arg0, u32 arg1) {
    gGsText_00201E5C->x8 = AlignUp_3_001E1E50(arg0, 0x10);
    gGsText_00201E5C->x10 = arg1;
    gGsText_00201E5C->x10 -= gGsText_00201E5C->x8 - arg0;
    gGsText_00201E5C->x14 = gGsText_00201E5C->x10 >> 4;
    gGsText_00201E5C->x14 -= 6;
    gGsText_00201E5C->x14 /= 13;
}

