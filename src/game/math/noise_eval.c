#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/math.h"

/* Noise_InitWrap_2_0015ED70 */
void Noise_InitWrap_2_0015ED70(void) {
    Noise_Init_2_0015F250();
}

/* Noise_Eval_1_0015ED80 */
void Noise_Eval_1_0015ED80(Noise *p, u32 n, f32 *out, f32 x, f32 lo, f32 hi) {
    f32 w1;
    f32 w2;
    f32 scale;
    f32 f1C;
    f32 base;
    f32 m;
    f32 amp;
    f32 xs;
    f32 t;
    u8 *idx;
    u32 i;

    w1 = p->w1;
    w2 = p->w2;
    scale = p->scale;
    f1C = p->f1C;
    base = p->base;
    amp = p->amp;
    m = 1.0f;
    idx = p->idx;
    if (x < lo) {
        x = lo;
    }
    if (!(x <= hi)) {
        x = hi;
    }
    if (p->f5 != 0) {
        if (x < lo + w1) {
            t = (x - lo) / w1;
            m *= (3.0f - 2.0f * t) * (t * t);
        }
        if (!(x <= hi - w2)) {
            t = (hi - x) / w2;
            m *= (3.0f - 2.0f * t) * (t * t);
        }
    }
    xs = x * scale;
    if (p->f4 != 0) {
        for (i = 0; i < n; i++) {
            f32 r = Noise_Fbm_1_0015F040(xs + (f32)gNoiseFbmBss_00316A20[idx[i]], 1.0f - f1C, 2.0f, 6.0f);
            out[i] = amp * (r * m) + base * m;
        }
    } else {
        for (i = 0; i < n; i++) {
            f32 v = 4096.0f + (xs + (f32)gNoiseFbmBss_00316A20[idx[i]]);
            s32 k = (s32)v;
            u8 a = k;
            f32 f = v - (f32)k;
            f32 g0 = f * gNoiseFbmBss_003139E0[gNoiseFbmBss_00316A20[a]];
            f32 d = (f - 1.0f) * gNoiseFbmBss_003139E0[gNoiseFbmBss_00316A20[(u8)(a + 1)]] - g0;
            f32 s = (3.0f - 2.0f * f) * (f * f);
            f32 r = g0 + s * d;
            out[i] = amp * (r * m) + base * m;
        }
    }
}
