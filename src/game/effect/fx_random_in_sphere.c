#include "common.h"

s32 Rand_Next_3_0015ED20(void);
f32 sqrtf(f32);
f32 powf(f32, f32);

static inline f32 randomOffset(void) {
    return (1.0f / 65535.0f) * (f32)(u32)(Rand_Next_3_0015ED20() & 0xFFFF) - 0.5f;
}

void Fx_RandomInSphere_0_00163A10(Vec *out, f32 radius, f32 exponent) {
    f32 x, y, z;
    f32 lengthSquared;
    f32 scale;
    f32 radiusSquared = radius * radius;
    f32 diameter = 2.0f * radius;

    do {
        x = diameter * randomOffset();
        y = diameter * randomOffset();
        z = diameter * randomOffset();
        lengthSquared = x * x + y * y + z * z;
    } while (lengthSquared > radiusSquared + 0.01f);

    if (exponent != 1.0f && !(radius <= 0.01f)) {
        scale = powf(sqrtf(lengthSquared) / radius, exponent);
        x *= scale;
        y *= scale;
        z *= scale;
    }
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 0.0f;
}
