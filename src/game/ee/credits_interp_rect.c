#include "common.h"
typedef struct { f32 x, y, z, w; } V4;
typedef struct { u8 pad[9]; u8 type; u8 pada[6]; V4 a; u8 pad2[0x10]; V4 b; } O;
extern f32 (*gCreditsInterpColorData_001F3AC8[])(O *);
V4 Credits_InterpRect_0_001E4BB8(s32 a1, O *o) {
    V4 r;
    if (gCreditsInterpColorData_001F3AC8[o->type]) {
        f32 t = gCreditsInterpColorData_001F3AC8[o->type](o);
        r.x = o->a.x + t * (o->b.x - o->a.x);
        r.y = o->a.y + t * (o->b.y - o->a.y);
        r.z = o->a.z + t * (o->b.z - o->a.z);
        r.w = o->a.w + t * (o->b.w - o->a.w);
    }
    return r;
}
