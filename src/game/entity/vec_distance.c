/* Best-effort C for the NONMATCHING build. The retail code is VU0 macro
 * code (the same as Vec_DistB_3_0015DF50); this is the same float math on the FPU. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
f32 sqrtf(f32);
f32 Vec_Distance_3_00146940(Vec *a, Vec *b) {
    f32 dx = b->x - a->x, dy = b->y - a->y, dz = b->z - a->z;
    return sqrtf((dz * dz + dx * dx) + dy * dy);
}
#else
INCLUDE_ASM(Vec_Distance_3_00146940);
#endif
