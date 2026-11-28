#include "common.h"
#include "game/data.h"
#include "game/ee.h"
extern GsTextState *gGsText_00201E5C;
extern GsTextStyle *gGsTextStyle_00201E60;
void *memset(void *, s32, u32);

void GsText_Init_1_001E2018(s32 arg0, u8 arg1, u16 arg2) {
    gGsTextAllocSdata_00201E58 = arg0;
    gGsText_00201E5C = GsText_Alloc_0_001E1E08(0x138, 0);
    gGsTextStyle_00201E60 = GsText_Alloc_0_001E1E08(0x90, 0);
    memset(gGsText_00201E5C, 0, 0x138);
    memset(gGsTextStyle_00201E60, 0, 0x90);
    if (arg2 != 0) {
        gGsText_00201E5C->x130 = arg2;
        gGsText_00201E5C->x134 = GsText_Alloc_0_001E1E08(arg2 * 2, 0);
    }
    gGsText_00201E5C->u.f.b48 = arg1;
    gGsText_00201E5C->u.f.b50 = 0;
    gGsTextStyle_00201E60->x0 = 0;
    gGsTextStyle_00201E60->x70 = 0;
    gGsTextStyle_00201E60->x74 = 0;
    gGsTextStyle_00201E60->x78 = 640.0f;
    gGsTextStyle_00201E60->x7C = 448.0f;
    GsText_SetPriority_0_001E2A08(0x23);
    GsText_SetFlag_0_001E1EA8(1);
}
