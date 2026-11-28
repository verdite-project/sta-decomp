#include "common.h"
#include "game/ee.h"
extern GsTextStyle *gGsTextStyle_00201E60;

void GsText_SetFlagA_0_001E2AE8(s32 arg0) {
    gGsTextStyle_00201E60->x50 = (s32) (arg0 != 0);
}
