/* Best-effort C for the NONMATCHING build. The retail code is VU0 macro
 * code; this is the same float math on the FPU; the matching
 * attempt is Vec_DistB_3_0015DF50.c (an inline-assembly match in wip/).
 * The matching build takes it from the assembly of Vec_DistSqXZ_2_0015DEB0. */
#ifdef NONMATCHING
#include "common.h"
f32 sqrtf(f32);
f32 Vec_DistB_3_0015DF50(Vec *a, Vec *b) {
    f32 dx = b->x - a->x, dy = b->y - a->y, dz = b->z - a->z;
    return sqrtf((dz * dz + dx * dx) + dy * dy);
}
#endif
