#include "common.h"

typedef struct { u64 : 51; u64 f : 1; } S;
extern S *gGsText_00201E5C;

void GsText_SetFlag_0_001E1EA8(s32 v)
{
    gGsText_00201E5C->f = v;
}
