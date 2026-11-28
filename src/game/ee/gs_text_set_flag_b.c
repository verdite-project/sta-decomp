#include "common.h"
#include "game/ee.h"
extern GsTextStyle *gGsTextStyle_00201E60;

void GsText_SetFlagB_0_001E2AF8(s32 arg0) {
    gGsTextStyle_00201E60->x54 = (s32) (arg0 != 0);
}
