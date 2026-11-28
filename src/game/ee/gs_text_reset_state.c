#include "common.h"
#include "game/ee.h"
extern const f32 D_00201B80;
extern GsTextState *gGsText_00201E5C;
extern GsTextStyle *gGsTextStyle_00201E60;

void GsText_ResetState_0_001E2148(void) {
gGsTextStyle_00201E60->x5C = 0; gGsTextStyle_00201E60->x48 = -1; gGsTextStyle_00201E60->x4C = -1; gGsTextStyle_00201E60->x10 = 0; gGsTextStyle_00201E60->x14 = 0; gGsTextStyle_00201E60->x30 = 1.0f; gGsTextStyle_00201E60->x34 = 1.0f; gGsTextStyle_00201E60->x40 = D_00201B80; gGsTextStyle_00201E60->x44 = D_00201B80; gGsTextStyle_00201E60->x58 = gGsTextStyle_00201E60->x54 = gGsTextStyle_00201E60->x50 = 0; gGsTextStyle_00201E60->x60 = 3.0f; gGsTextStyle_00201E60->x0 = 0; gGsText_00201E5C->x1C = gGsText_00201E5C->x18; gGsText_00201E5C->x24 = 0;
}
