#include "include_asm.h"

#ifdef NONMATCHING
#include "game/ee.h"

extern GsTextStyle *gGsTextStyle_00201E60;

void GsText_SetVertex_0_001E3758(GsTextPacket *packet, s32 index,
                                 f32 x, f32 y, f32 u, f32 v) {
    GsTextVertex *vertex = &packet->vertices[index];

    vertex->x = x;
    vertex->y = y;
    vertex->u = u;
    vertex->v = v;
    vertex->color = gGsTextStyle_00201E60->x4C;
}
#else
INCLUDE_ASM(GsText_SetVertex_0_001E3758);
#endif
