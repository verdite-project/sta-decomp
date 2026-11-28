#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/math.h"
void Quat_ToMatrix_2_0015E180(Mtx *out, Vec *q);
void Mtx_ToQuat_2_0015E290(f32 *out, f32 (*a)[4]);
void Quat_ToMatrixB_2_0015E580(f32 *m, Vec *q);
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(Mtx *, Mtx *);
f32 sqrtf(f32);
void sceVu0Normalize(f32 *, f32 *);
f32 cosf(f32);
f32 sinf(f32);

/* Quat_ToMatrix_2_0015E180 */
#define sceVu0CopyVector sceVu0CopyVector__as_Quat_ToMatrix_2_0015E180
void sceVu0CopyVector__as_Quat_ToMatrix_2_0015E180(Vec *, Vec *);

void Quat_ToMatrix_2_0015E180(Mtx *out, Vec *q) {
    Mtx m;
    f32 w;
    f32 x;
    Vec v;
    f32 y;
    f32 z;
    sceVu0CopyVector(&v, q);
    x = v.x; y = v.y; z = v.z; w = v.w;
    m.m[0].x = 1.0f - 2.0f * (y * y + z * z);
    m.m[0].y = 2.0f * (x * y + z * w);
    m.m[0].z = 2.0f * (x * z - y * w);
    m.m[1].x = 2.0f * (x * y - z * w);
    m.m[1].y = 1.0f - 2.0f * (x * x + z * z);
    m.m[1].z = 2.0f * (y * z + x * w);
    m.m[2].x = 2.0f * (x * z + y * w);
    m.m[2].y = 2.0f * (y * z - x * w);
    m.m[2].z = 1.0f - 2.0f * (x * x + y * y);
    m.m[0].w = 0.0f;
    m.m[1].w = 0.0f;
    m.m[2].w = 0.0f;
    m.m[3].w = 1.0f;
    m.m[3].x = 0.0f;
    m.m[3].y = 0.0f;
    m.m[3].z = 0.0f;
    sceVu0CopyMatrix(out, &m);
}
#undef sceVu0CopyVector

/* Mtx_ToQuat_2_0015E290 */
#define sceVu0CopyVector sceVu0CopyVector__as_Mtx_ToQuat_2_0015E290
void sceVu0CopyVector__as_Mtx_ToQuat_2_0015E290(f32 *, f32 *);
static inline f32 hs(f32 *d, f32 x) {
    *d = sqrtf(x) / 2.0f;
    return 1.0f / (4.0f * *d);
}

void Mtx_ToQuat_2_0015E290(f32 *out, f32 (*a)[4]) {
    f32 m[4][4];
    f32 q[4];
    f32 t;
    f32 s;
    f32 f;
    s32 i;
    s32 j;
    s32 k;

    sceVu0Normalize(m[0], a[0]);
    sceVu0Normalize(m[1], a[1]);
    sceVu0Normalize(m[2], a[2]);
    sceVu0CopyVector(m[3], &gZeroVec_003139A0);
    m[3][3] = 1.0f;
    t = m[0][0] + m[1][1] + m[2][2] + 1.0f;
    if (!(t < 1.0f)) {
        f = hs(&q[3], t);
        q[0] = f * (m[1][2] - m[2][1]);
        q[1] = f * (m[2][0] - m[0][2]);
        q[2] = f * (m[0][1] - m[1][0]);
    } else {
        if (m[0][0] < m[1][1]) {
            if (m[1][1] < m[2][2]) {
                i = 2;
            } else {
                i = 1;
            }
        } else {
            if (m[0][0] < m[2][2]) {
                i = 2;
            } else {
                i = 0;
            }
        }
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        f = hs(&q[i], m[i][i] - m[j][j] - m[k][k] + 1.0f);
        q[j] = f * (m[i][j] + m[j][i]);
        q[k] = f * (m[i][k] + m[k][i]);
        q[3] = f * (m[j][k] - m[k][j]);
    }
    sceVu0CopyVector(out, q);
}
#undef sceVu0CopyVector

/* Quat_FromAxisAngle_2_0015E500 */
/* Quat_FromAxisAngle_2_0015E500 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
void Quat_FromAxisAngle_2_0015E500(void *arg0, void *arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;

    temp_f20 = 0.5f * fparg0;
    temp_f0 = sinf(temp_f20);
    M2C_FIELD(arg0, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) * temp_f0);
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) * temp_f0);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) * temp_f0);
    M2C_FIELD(arg0, f32 *, 0xC) = cosf(temp_f20);
}

/* Quat_ToMatrixB_2_0015E580 */
void Quat_ToMatrixB_2_0015E580(f32 *m, Vec *q) {
    f32 s, n;
    f32 xs, ys, zs;
    f32 wx, wy, wz, xx, xy, xz, yy, yz, zz;
    f32 x, y, z, w;
    x = q->x; y = q->y; z = q->z; w = q->w;
    n = x * x + y * y + z * z + w * w;
    s = n > 1e-5f ? 2.0f / n : 0.0f;
    xs = x * s; ys = y * s; zs = z * s;
    wx = w * xs; xx = x * xs; wy = w * ys; wz = w * zs;
    xy = x * ys; xz = x * zs; zz = z * zs; yy = y * ys; yz = y * zs;
    m[0] = 1.0f - (yy + zz);
    m[4] = xy - wz;
    m[8] = xz + wy;
    m[1] = xy + wz;
    m[5] = 1.0f - (xx + zz);
    m[9] = yz - wx;
    m[2] = xz - wy;
    m[6] = yz + wx;
    m[10] = 1.0f - (xx + yy);
    m[14] = 0.0f;
    m[13] = 0.0f;
    m[12] = 0.0f;
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
}
