#include "common.h"

typedef struct { s32 v[4]; } Q;
typedef struct { char pad[0x4C]; Q q; } S;
extern S *gGsTextStyle_00201E60;

Q *GsText_GetColor_1_001E2D08(Q *dst)
{
    *dst = gGsTextStyle_00201E60->q;
    return dst;
}
