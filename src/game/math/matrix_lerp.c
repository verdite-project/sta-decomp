#include "common.h"
#include "game/math.h"
extern f32 gMatrixFromData_001F2170[];
void Mtx_LerpNormalize_1_0015E690(f32 (*m0)[4], f32 (*m1)[4], f32 (*m2)[4], f32 t);
void Mtx_LerpNormalizeB_1_0015E8C0(Mtx *d, Mtx *a, Mtx *b, f32 t);
void Mtx_LerpScaledB_1_0015E970(Vec *out, Vec *a, Vec *b, f32 t);
void Mtx_Lerp_2_0015EB20(f32 (*m0)[4], f32 (*m1)[4], f32 (*m2)[4], f32 t);
void Mtx_AxisAngle_2_0015EBB0(f32 *m, Vec *axis, f32 ang);
void sceVu0InterVector(void *, void *, void *, f32);
void sceVu0Normalize(void *, void *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
f32 sqrtf(float);
f32 cosf(f32);
f32 sinf(f32);
void sceVu0CopyMatrix(f32 *, f32 *);

/* Mtx_LerpNormalize_1_0015E690 */
#define sceVu0InterVector sceVu0InterVector__as_Mtx_LerpNormalize_1_0015E690
void sceVu0InterVector__as_Mtx_LerpNormalize_1_0015E690(f32 *v0, f32 *v1, f32 *v2, f32 t);
#define sceVu0Normalize sceVu0Normalize__as_Mtx_LerpNormalize_1_0015E690
void sceVu0Normalize__as_Mtx_LerpNormalize_1_0015E690(f32 *v0, f32 *v1);

void Mtx_LerpNormalize_1_0015E690(f32 (*m0)[4], f32 (*m1)[4], f32 (*m2)[4], f32 t)
{
    sceVu0InterVector(m0[0], m1[0], m2[0], t);
    sceVu0InterVector(m0[1], m1[1], m2[1], t);
    sceVu0InterVector(m0[2], m1[2], m2[2], t);
    sceVu0Normalize(m0[0], m0[0]);
    sceVu0Normalize(m0[1], m0[1]);
    sceVu0Normalize(m0[2], m0[2]);
}
#undef sceVu0InterVector
#undef sceVu0Normalize

/* Mtx_LerpScaled_1_0015E730 */
#define sceVu0Normalize sceVu0Normalize__as_Mtx_LerpScaled_1_0015E730
void sceVu0Normalize__as_Mtx_LerpScaled_1_0015E730(Vec *, Vec *);
#define sceVu0InterVector sceVu0InterVector__as_Mtx_LerpScaled_1_0015E730
void sceVu0InterVector__as_Mtx_LerpScaled_1_0015E730(Vec *, Vec *, Vec *, f32);

void Mtx_LerpScaled_1_0015E730(Vec *out, Vec *a, Vec *b, f32 t) {
    Vec la, lb, ls;
    la.x = sqrtf(sceVu0InnerProduct(&a[0], &a[0]));
    la.y = sqrtf(sceVu0InnerProduct(&a[1], &a[1]));
    la.z = sqrtf(sceVu0InnerProduct(&a[2], &a[2]));
    lb.x = sqrtf(sceVu0InnerProduct(&b[0], &b[0]));
    lb.y = sqrtf(sceVu0InnerProduct(&b[1], &b[1]));
    lb.z = sqrtf(sceVu0InnerProduct(&b[2], &b[2]));
    sceVu0InterVector(&ls, &la, &lb, t);
    sceVu0InterVector(&out[0], &a[0], &b[0], t);
    sceVu0InterVector(&out[1], &a[1], &b[1], t);
    sceVu0InterVector(&out[2], &a[2], &b[2], t);
    sceVu0Normalize(&out[0], &out[0]);
    sceVu0Normalize(&out[1], &out[1]);
    sceVu0Normalize(&out[2], &out[2]);
    sceVu0ScaleVector(&out[0], &out[0], ls.x);
    sceVu0ScaleVector(&out[1], &out[1], ls.y);
    sceVu0ScaleVector(&out[2], &out[2], ls.z);
}
#undef sceVu0Normalize
#undef sceVu0InterVector

/* Mtx_LerpNormalizeB_1_0015E8C0 */
#define sceVu0Normalize sceVu0Normalize__as_Mtx_LerpNormalizeB_1_0015E8C0
void sceVu0Normalize__as_Mtx_LerpNormalizeB_1_0015E8C0(Vec *, Vec *);
#define sceVu0InterVector sceVu0InterVector__as_Mtx_LerpNormalizeB_1_0015E8C0
void sceVu0InterVector__as_Mtx_LerpNormalizeB_1_0015E8C0(Vec *, Vec *, Vec *, f32);
void Mtx_LerpNormalizeB_1_0015E8C0(Mtx *d, Mtx *a, Mtx *b, f32 t) {
    sceVu0InterVector(&d->m[0], &a->m[0], &b->m[0], t);
    sceVu0InterVector(&d->m[1], &a->m[1], &b->m[1], t);
    sceVu0InterVector(&d->m[2], &a->m[2], &b->m[2], t);
    sceVu0InterVector(&d->m[3], &a->m[3], &b->m[3], t);
    sceVu0Normalize(&d->m[0], &d->m[0]);
    sceVu0Normalize(&d->m[1], &d->m[1]);
    sceVu0Normalize(&d->m[2], &d->m[2]);
    d->m[3].w = 1.0f;
}
#undef sceVu0Normalize
#undef sceVu0InterVector

/* Mtx_LerpScaledB_1_0015E970 */
#define sceVu0Normalize sceVu0Normalize__as_Mtx_LerpScaledB_1_0015E970
void sceVu0Normalize__as_Mtx_LerpScaledB_1_0015E970(Vec *, Vec *);
#define sceVu0InterVector sceVu0InterVector__as_Mtx_LerpScaledB_1_0015E970
void sceVu0InterVector__as_Mtx_LerpScaledB_1_0015E970(Vec *, Vec *, Vec *, f32);

void Mtx_LerpScaledB_1_0015E970(Vec *out, Vec *a, Vec *b, f32 t) {
    Vec la, lb, ls;
    la.x = sqrtf(sceVu0InnerProduct(&a[0], &a[0]));
    la.y = sqrtf(sceVu0InnerProduct(&a[1], &a[1]));
    la.z = sqrtf(sceVu0InnerProduct(&a[2], &a[2]));
    lb.x = sqrtf(sceVu0InnerProduct(&b[0], &b[0]));
    lb.y = sqrtf(sceVu0InnerProduct(&b[1], &b[1]));
    lb.z = sqrtf(sceVu0InnerProduct(&b[2], &b[2]));
    sceVu0InterVector(&ls, &la, &lb, t);
    sceVu0InterVector(&out[0], &a[0], &b[0], t);
    sceVu0InterVector(&out[1], &a[1], &b[1], t);
    sceVu0InterVector(&out[2], &a[2], &b[2], t);
    sceVu0InterVector(&out[3], &a[3], &b[3], t);
    out[3].w = 1.0f;
    sceVu0Normalize(&out[0], &out[0]);
    sceVu0Normalize(&out[1], &out[1]);
    sceVu0Normalize(&out[2], &out[2]);
    sceVu0ScaleVector(&out[0], &out[0], ls.x);
    sceVu0ScaleVector(&out[1], &out[1], ls.y);
    sceVu0ScaleVector(&out[2], &out[2], ls.z);
}
#undef sceVu0Normalize
#undef sceVu0InterVector

/* Mtx_Lerp_2_0015EB20 */
#define sceVu0InterVector sceVu0InterVector__as_Mtx_Lerp_2_0015EB20
void sceVu0InterVector__as_Mtx_Lerp_2_0015EB20(f32 *v0, f32 *v1, f32 *v2, f32 t);

void Mtx_Lerp_2_0015EB20(f32 (*m0)[4], f32 (*m1)[4], f32 (*m2)[4], f32 t)
{
    sceVu0InterVector(m0[0], m1[0], m2[0], t);
    sceVu0InterVector(m0[1], m1[1], m2[1], t);
    sceVu0InterVector(m0[2], m1[2], m2[2], t);
    sceVu0InterVector(m0[3], m1[3], m2[3], t);
    m0[3][3] = 1.0f;
}
#undef sceVu0InterVector

/* Mtx_AxisAngle_2_0015EBB0 */
#define sceVu0Normalize sceVu0Normalize__as_Mtx_AxisAngle_2_0015EBB0
void sceVu0Normalize__as_Mtx_AxisAngle_2_0015EBB0(Vec *, Vec *);

void Mtx_AxisAngle_2_0015EBB0(f32 *m, Vec *axis, f32 ang) {
    Vec v;
    f32 c, s, t;
    f32 xx, yy, zz, xy, yz, zx, xs, ys, zs; f32 x, y, z;
    c = cosf(ang);
    s = sinf(ang);
    t = 1.0f - c;
    if (sqrtf(sceVu0InnerProduct(axis, axis)) < 1e-5f) {
        sceVu0CopyMatrix(m, gMatrixFromData_001F2170);
        return;
    }
    sceVu0Normalize(&v, axis);
    x = v.x; y = v.y; z = v.z;
    xx = x * x; yy = y * y; zz = z * z; xy = x * y; yz = y * z; zx = z * x; xs = x * s; ys = y * s; zs = z * s;
    m[0] = c + t * xx;
    m[4] = t * xy - zs;
    m[8] = ys + t * zx;
    m[1] = zs + t * xy;
    m[5] = c + t * yy;
    m[9] = t * yz - xs;
    m[2] = t * zx - ys;
    m[6] = xs + t * yz;
    m[10] = c + t * zz;
    m[14] = 0.0f;
    m[13] = 0.0f;
    m[12] = 0.0f;
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
}
#undef sceVu0Normalize
