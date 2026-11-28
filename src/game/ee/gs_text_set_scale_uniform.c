#include "common.h"

typedef struct { char pad[8]; u16 h; } T;
typedef struct { char pad[0x28]; T *t; } S;
extern S *gGsText_00201E5C;
typedef struct { f32 x, y; } V2;
void GsText_SetScale_1_001E2A28(V2 *v);

void GsText_SetScaleUniform_0_001E2A68(f32 x)
{
    V2 v;
    x /= gGsText_00201E5C->t->h;
    v.x = x;
    v.y = x;
    GsText_SetScale_1_001E2A28(&v);
}
