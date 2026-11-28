/* Best-effort C for the NONMATCHING build. The retail code is VU0 macro
 * code; this is the same float math on the FPU; the matching
 * attempt is Vec_DistSqXZ_2_0015DEB0.c (an inline-assembly match in wip/).
 * The retail assembly of Vec_DistSqXZ_2_0015DEB0 also holds Vec_DistXZ_2_0015DEE0,
 * Vec_DistSq_3_0015DF20 and Vec_DistB_3_0015DF50. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
f32 Vec_DistSqXZ_2_0015DEB0(Vec *a, Vec *b) {
    f32 dx = b->x - a->x, dz = b->z - a->z;
    return dz * dz + dx * dx;
}
#else
INCLUDE_ASM(Vec_DistSqXZ_2_0015DEB0);
#endif
