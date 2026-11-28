/* Best-effort C for the NONMATCHING build. The retail code is VU0 macro
 * code; this is the same float math on the FPU; the matching
 * attempt is Mtx_MaxAxisScale_2_00171550.c (an inline-assembly match in wip/). */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
f32 sqrtf(f32);
/* the largest squared length of the first three rows, rooted */
f32 Mtx_MaxAxisScale_2_00171550(Vec *m) {
    f32 a = (m[0].x * m[0].x + m[0].y * m[0].y) + m[0].z * m[0].z;
    f32 b = (m[1].x * m[1].x + m[1].y * m[1].y) + m[1].z * m[1].z;
    f32 c = (m[2].x * m[2].x + m[2].y * m[2].y) + m[2].z * m[2].z;
    f32 r = a > b ? a : b;
    r = r > c ? r : c;
    return sqrtf(r);
}
#else
INCLUDE_ASM(Mtx_MaxAxisScale_2_00171550);
#endif
