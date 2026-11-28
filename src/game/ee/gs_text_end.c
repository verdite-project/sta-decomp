#include "common.h"
#include "game/ee.h"
extern GsTextState *gGsText_00201E5C;

s32 GsText_End_1_001E2430(void) {
    s32 *p = (s32 *)gGsText_00201E5C;
    if (*p == 0) return 0;
    if (--*p != 0) return 0;
    GsText_Kick_1_001E24A0();
    if ((gGsText_00201E5C->u.d & 0x1000000000000ULL) && *(u16 *)((u8 *)gGsText_00201E5C + 4) != 0) GsText_WaitDma_1_001E3688();
    return *(u16 *)((u8 *)gGsText_00201E5C + 4);
}
