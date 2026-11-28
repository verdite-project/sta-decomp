#include "common.h"

typedef struct { s64 a, b; } Q;
typedef struct { char pad[0x30]; Q q[1]; } S;
extern S *gGsText_00201E5C;

void GsText_SetQword_0_001E1E80(s32 i, s64 a, s64 b)
{
    gGsText_00201E5C->q[i].a = a;
    gGsText_00201E5C->q[i].b = b;
}
