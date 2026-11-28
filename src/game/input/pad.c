#include "common.h"
extern u16 gMapCommandBss_00317238[];

s32 Pad_AnyButtonPressed_1_00180F10(void) {
    Input_Poll_2_0015FC10();
    return ((*gMapCommandBss_00317238) & 0xF008) != 0;
}
