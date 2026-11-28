#include "common.h"
#include "game/ee.h"
extern GsTextStyle *gGsTextStyle_00201E60;

void GsText_SetFlagC_0_001E2B08(s32 arg0) {
    gGsTextStyle_00201E60->x58 = (s32) (arg0 != 0);
}
