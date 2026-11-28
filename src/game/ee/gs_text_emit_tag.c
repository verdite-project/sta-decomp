#include "common.h"
#include "game/ee.h"
typedef int TI __attribute__((mode(TI)));
typedef union { TI q; s32 w[4]; } Q;
typedef struct { u64 fl; u32 p8; s32 *xC; } G;
typedef struct { f32 x; f32 y; f32 z; f32 w; s32 x10; s32 x14; s32 x18; s32 x1C; } V;
extern GsTextState *gGsText_00201E5C;
void GsText_EmitTag_0_001E39F8(V *v) {
    s32 i;
    Q q;
    f32 y;
    s32 **pp;
    s32 *p;
    G *g;
    
    for (i = 0; i < 4; i++, v++) {
        gGsText_00201E5C->xC[0] = v->x10;
        gGsText_00201E5C->xC[1] = v->x14;
        gGsText_00201E5C->xC[2] = 0x3F800000;
        { s32 **a = &gGsText_00201E5C->xC; s32 *b = *a; b[3] = 0; b += 4; *a = b; }
        q.w[0] = (v->x + 1728.0f) * 16.0f;
        y = 224.0f - v->y;
        g = gGsText_00201E5C;
        if (g->fl & (0x8000ULL << 36)) y *= 0.5f;
        q.w[1] = (2048.0f - y) * 16.0f;
        q.w[2] = 0x1000000;
        q.w[3] = 0;
        pp = &g->xC;
        p = *pp;
        *(TI *)p = q.q;
        p += 4; *pp = p;
    }
}

