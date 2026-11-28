#include "common.h"
#include "game/math.h"
M2* Mtx2_Rotate_1_00182860(M2 *o, f32 x);
M2* Mtx2_Mul_1_001828F0(M2 *o, M2 *a, M2 *b);
f32 sinf(f32 x);
f32 cosf(f32 x);

/* Mtx2_Rotate_1_00182860 */
M2 *Mtx2_Rotate_1_00182860(M2 *o, f32 x)
{
    M2 t;
    f32 s = sinf(x);
    f32 c = cosf(x);
    t.a[0] = c;
    t.a[1] = -s;
    t.a[2] = s;
    t.a[3] = c;
    *o = t;
    return o;
}

/* Mtx2_Mul_1_001828F0 */
M2 *Mtx2_Mul_1_001828F0(M2 *o, M2 *a, M2 *b)
{
    M2 t;
    t.a[0] = a->a[0] * b->a[0] + a->a[1] * b->a[2];
    t.a[2] = a->a[2] * b->a[0] + a->a[3] * b->a[2];
    t.a[1] = a->a[0] * b->a[1] + a->a[1] * b->a[3];
    t.a[3] = a->a[2] * b->a[1] + a->a[3] * b->a[3];
    *o = t;
    return o;
}
