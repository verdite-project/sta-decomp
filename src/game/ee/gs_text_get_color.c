#include "common.h"

#include "game/ee.h"
typedef struct { char pad[0x4C]; GsTextColor q; } S;
extern S *gGsTextStyle_00201E60;

GsTextColor GsText_GetColor_1_001E2D08(void)
{
    return gGsTextStyle_00201E60->q;
}
