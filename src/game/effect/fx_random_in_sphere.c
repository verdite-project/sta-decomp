/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Fx_RandomInSphere_0_00163A10.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"

u16 Rand_Next_3_0015ED20(void);
f32 sqrtf(f32);
f32 powf(f32, f32);
static inline f32 u2f(u32 x) { return x; }

void Fx_RandomInSphere_0_00163A10(Vec *out, f32 r, f32 e) {
    f32 r2;
    f32 d;
    f32 x;
    f32 y;
    f32 z;
    f32 k;
    r2 = r * r + 0.01f;
    d = 2.0f * r;
    do {
        x = d * (1.5259022e-05f * u2f(Rand_Next_3_0015ED20()) - 0.5f);
        y = d * (1.5259022e-05f * u2f(Rand_Next_3_0015ED20()) - 0.5f);
        z = d * (1.5259022e-05f * u2f(Rand_Next_3_0015ED20()) - 0.5f);
    } while (!(x * x + y * y + z * z <= r2));
    if (e != 1.0f && !(r <= 0.01f)) {
        k = powf(sqrtf(x * x + y * y + z * z) / r, e);
        x *= k;
        y *= k;
        z *= k;
    }
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 0.0f;
}
#else
INCLUDE_ASM(Fx_RandomInSphere_0_00163A10);
#endif
