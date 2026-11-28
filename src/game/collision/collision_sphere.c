#include "common.h"
#include "m2c.h"
#include "game/collision.h"
typedef struct { Vec p; Vec d; } Seg;
s32 Coll_CylinderVsSegment_0_0014EC00(Seg *c, Vec *v, f32 r, f32 h);
s32 Coll_RayVsAabb_1_0014F0C0(void *arg0, void *arg1, void *arg2, f32 fparg0);
s32 Coll_SphereVsTriangle_1_0014F210(Vec *out, Vec *sph, Vec *tri, Vec *n, s32 a4, s32 a5, f32 *dist);
s32 Coll_SweptVsTriangle_1_0014F520(Vec *out, Vec *p, Vec *q, Vec *v, Vec *n, s32 i, s32 two, f32 *dist);
s32 Coll_BoxOverlap_0_0014F8C0(s32 arg0, s32 arg1, f32 *box, s32 arg3);
void sceVu0SubVector(void *, void *, void *);
f32 sceVu0InnerProduct(void *, void *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(void *, void *);
f32 fabsf(f32);
f32 Vec_DistSqXZ_2_0015DEB0(Vec *, Seg *);
f32 Vec_DistSq_3_0015DF20(void *, void *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
f32 sqrtf(float);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0InversMatrix(f32 (*)[4], s32);
void sceVu0ApplyMatrix(f32 *, f32 (*)[4], s32);

/* Coll_CylinderVsSegment_0_0014EC00 */
#define sceVu0SubVector sceVu0SubVector__as_Coll_CylinderVsSegment_0_0014EC00
void sceVu0SubVector__as_Coll_CylinderVsSegment_0_0014EC00(Vec *, Seg *, Vec *);
#define sceVu0InnerProduct sceVu0InnerProduct__as_Coll_CylinderVsSegment_0_0014EC00
f32 sceVu0InnerProduct__as_Coll_CylinderVsSegment_0_0014EC00(Vec *, Vec *);
#define sceVu0CopyVector sceVu0CopyVector__as_Coll_CylinderVsSegment_0_0014EC00
void sceVu0CopyVector__as_Coll_CylinderVsSegment_0_0014EC00(Vec *, Vec *);

s32 Coll_CylinderVsSegment_0_0014EC00(Seg *c, Vec *v, f32 r, f32 h) {
    Vec sc;
    Vec dv;
    Vec ax;
    f32 t;
    f32 l;
    f32 r2;
    f32 len;
    f32 lo;
    f32 hi;
    f32 a;
    f32 b;

    l = c->d.w;
    t = c->p.w + r;
    r2 = t * t;
    if (l <= 0.0f) {
        return Vec_DistSqXZ_2_0015DEB0(v, c) <= r2;
    }
    sceVu0ScaleVector(&sc, &c->d, l);
    if (!(fabsf(h) <= 1.0f)) {
        if (!(sc.y < 0.0f)) {
            lo = c->p.y - c->p.w;
            hi = c->p.w + (c->p.y + sc.y);
        } else {
            lo = (c->p.y + sc.y) - c->p.w;
            hi = c->p.y + c->p.w;
        }
        if (!(h < 0.0f)) {
            b = v->y;
            a = b - h;
        } else {
            a = v->y;
            b = a - h;
        }
        if ((a < lo && b < lo) || (!(a <= hi) && !(b <= hi))) {
            return 0;
        }
    }
    sceVu0SubVector(&dv, c, v);
    dv.w = 0;
    dv.y = 0;
    sceVu0CopyVector(&ax, &c->d);
    ax.w = 0;
    ax.y = 0;
    len = sceVu0InnerProduct(&ax, &ax);
    if (len <= 0.0f) {
        return 0;
    }
    t = sceVu0InnerProduct(&dv, &ax);
    t = t * sceVu0InnerProduct(&dv, &ax) / len;
    return sceVu0InnerProduct(&dv, &dv) - t <= r2;
}
#undef sceVu0SubVector
#undef sceVu0InnerProduct
#undef sceVu0CopyVector

/* Coll_SphereVsSphere_0_0014EE10 */
#define sceVu0InnerProduct sceVu0InnerProduct__as_Coll_SphereVsSphere_0_0014EE10
f32 sceVu0InnerProduct__as_Coll_SphereVsSphere_0_0014EE10(f32 *, f32 *);
#define sceVu0SubVector sceVu0SubVector__as_Coll_SphereVsSphere_0_0014EE10
void sceVu0SubVector__as_Coll_SphereVsSphere_0_0014EE10(f32 *, s8 *, s8 *);
#define sceVu0CopyVector sceVu0CopyVector__as_Coll_SphereVsSphere_0_0014EE10
void sceVu0CopyVector__as_Coll_SphereVsSphere_0_0014EE10(f32 *, s8 *);
#define Vec_DistSq_3_0015DF20 Vec_DistSq_3_0015DF20__as_Coll_SphereVsSphere_0_0014EE10
f32 Vec_DistSq_3_0015DF20__as_Coll_SphereVsSphere_0_0014EE10(s8 *, s8 *);

s32 Coll_SphereVsSphere_0_0014EE10(s8 *arg0, s8 *arg1) {
    f32 d[4];
    f32 e[4];
    f32 r;
    f32 len;
    f32 t;

    t = M2C_FIELD(arg0, f32 *, 0xC) + M2C_FIELD(arg1, f32 *, 0xC);
    r = t * t;
    if (M2C_FIELD(arg0, f32 *, 0x1C) <= 0.0f) {
        return Vec_DistSq_3_0015DF20(arg1, arg0) <= r;
    }
    sceVu0SubVector(d, arg0, arg1);
    d[3] = 0;
    sceVu0CopyVector(e, arg0 + 0x10);
    e[3] = 0;
    len = sceVu0InnerProduct(e, e);
    if (len <= 0.0f) return 0;
    t = sceVu0InnerProduct(d, e) * sceVu0InnerProduct(d, e) / len;
    return sceVu0InnerProduct(d, d) - t <= r;
}
#undef sceVu0InnerProduct
#undef sceVu0SubVector
#undef sceVu0CopyVector
#undef Vec_DistSq_3_0015DF20

/* Coll_SegmentVsSphere_1_0014EF40 */
#define sceVu0SubVector sceVu0SubVector__as_Coll_SegmentVsSphere_1_0014EF40
void sceVu0SubVector__as_Coll_SegmentVsSphere_1_0014EF40(Vec *, Vec *, Vec *);
#define sceVu0InnerProduct sceVu0InnerProduct__as_Coll_SegmentVsSphere_1_0014EF40
f32 sceVu0InnerProduct__as_Coll_SegmentVsSphere_1_0014EF40(Vec *, Vec *);
#define Vec_DistSq_3_0015DF20 Vec_DistSq_3_0015DF20__as_Coll_SegmentVsSphere_1_0014EF40
f32 Vec_DistSq_3_0015DF20__as_Coll_SegmentVsSphere_1_0014EF40(Vec *, Vec *);

s32 Coll_SegmentVsSphere_1_0014EF40(Vec *a, Vec *b, Vec *s, f32 r) {
    Vec p;
    Vec d;
    f32 len;
    f32 t;
    s32 v;

    sceVu0SubVector(&d, b, a);
    len = sceVu0InnerProduct(&d, &d);
    t = s->w + r;
    r = t * t;
    if (len <= 0.0f) {
        return Vec_DistSq_3_0015DF20(s, a) <= r;
    }
    sceVu0SubVector(&p, s, a);
    t = sceVu0InnerProduct(&p, &d);
    if (!(t < 0.0f) && t <= len) {
        sceVu0ScaleVector(&p, &d, t / len);
        sceVu0AddVector(&p, &p, a);
        return Vec_DistSq_3_0015DF20(s, &p) <= r;
    }
    if (!(Vec_DistSq_3_0015DF20(s, a) <= r)) {
        return 0;
    }
    v = Vec_DistSq_3_0015DF20(s, b) > r;
    return v ^ 1;
}
#undef sceVu0SubVector
#undef sceVu0InnerProduct
#undef Vec_DistSq_3_0015DF20

/* Coll_RayVsAabb_1_0014F0C0 */
s32 Coll_RayVsAabb_1_0014F0C0(void *arg0, void *arg1, void *arg2, f32 fparg0) {
    f32 temp_f4;
    f32 temp_f3;
    f32 temp_f2;
    f32 temp_f1_6;
    f32 temp_f1_5;
    f32 temp_f1_4;
    f32 temp_f1_3;
    f32 temp_f1_2;
    f32 temp_f1;

    temp_f4 = M2C_FIELD(arg0, f32 *, 0);
    temp_f1 = M2C_FIELD(arg2, f32 *, 0);
    if (((temp_f4 + fparg0) < temp_f1) && ((M2C_FIELD(arg1, f32 *, 0) + fparg0) < temp_f1)) {
        return 0;
    }
    temp_f3 = M2C_FIELD(arg0, f32 *, 4);
    temp_f1_2 = M2C_FIELD(arg2, f32 *, 4);
    if (((temp_f3 + fparg0) < temp_f1_2) && ((M2C_FIELD(arg1, f32 *, 4) + fparg0) < temp_f1_2)) {
        return 0;
    }
    temp_f2 = M2C_FIELD(arg0, f32 *, 8);
    temp_f1_3 = M2C_FIELD(arg2, f32 *, 8);
    if (((temp_f2 + fparg0) < temp_f1_3) && ((M2C_FIELD(arg1, f32 *, 8) + fparg0) < temp_f1_3)) {
        return 0;
    }
    temp_f1_4 = M2C_FIELD(arg2, f32 *, 0x10);
    if (!((temp_f4 - fparg0) <= temp_f1_4) && !((M2C_FIELD(arg1, f32 *, 0) - fparg0) <= temp_f1_4)) {
        return 0;
    }
    temp_f1_5 = M2C_FIELD(arg2, f32 *, 0x14);
    if (!((temp_f3 - fparg0) <= temp_f1_5) && !((M2C_FIELD(arg1, f32 *, 4) - fparg0) <= temp_f1_5)) {
        return 0;
    }
    temp_f1_6 = M2C_FIELD(arg2, f32 *, 0x18);
    if (!((temp_f2 - fparg0) <= temp_f1_6) && !((M2C_FIELD(arg1, f32 *, 8) - fparg0) <= temp_f1_6)) {
        return 0;
    }
    return 1;
}

/* Coll_SphereVsTriangle_1_0014F210 */
#define sceVu0SubVector sceVu0SubVector__as_Coll_SphereVsTriangle_1_0014F210
void sceVu0SubVector__as_Coll_SphereVsTriangle_1_0014F210(Vec *, Vec *, Vec *);
#define sceVu0InnerProduct sceVu0InnerProduct__as_Coll_SphereVsTriangle_1_0014F210
f32 sceVu0InnerProduct__as_Coll_SphereVsTriangle_1_0014F210(Vec *, Vec *);
#define sceVu0CopyVector sceVu0CopyVector__as_Coll_SphereVsTriangle_1_0014F210
void sceVu0CopyVector__as_Coll_SphereVsTriangle_1_0014F210(Vec *, Vec *);

s32 Coll_SphereVsTriangle_1_0014F210(Vec *out, Vec *sph, Vec *tri, Vec *n, s32 a4, s32 a5, f32 *dist) {
    Vec p;
    Vec d;
    Vec e0;
    Vec e1;
    Vec e2;
    Vec c;
    Vec ed;
    Vec w;
    f32 dot;
    f32 r;
    f32 r2;
    f32 len;
    u8 i;
    Vec *v;
    f32 t;
    f32 d2;

    r = sph->w;
    sceVu0SubVector(&d, tri, sph);
    dot = sceVu0InnerProduct(&d, n);
    if (dot < -r || !(dot <= 0.0f)) {
        return 0;
    }
    sceVu0ScaleVector(&d, n, dot);
    sceVu0AddVector(&p, sph, &d);
    sceVu0SubVector(&e0, tri, &p);
    sceVu0SubVector(&e1, tri + 1, &p);
    sceVu0SubVector(&e2, tri + 2, &p);
    sceVu0OuterProduct(&c, &e0, &e1);
    sceVu0OuterProduct(&e1, &e1, &e2);
    if (sceVu0InnerProduct(&c, &e1) > 0.0f) {
        sceVu0OuterProduct(&c, &e2, &e0);
        if (sceVu0InnerProduct(&e1, &c) > 0.0f) {
            sceVu0CopyVector(out, &p);
            *(s32 *)&out->w = 0x3F800000;
            sceVu0CopyVector(out + 1, n);
            *dist = -dot;
            return 1;
        }
    }
    r2 = sph->w * sph->w;
    for (i = 0; i < 3; i++) {
        v = &tri[i % 3];
        sceVu0SubVector(&ed, &tri[(i + 1) % 3], v);
        len = sceVu0InnerProduct(&ed, &ed);
        if (len > 0.0f) {
            sceVu0SubVector(&w, sph, v);
            t = sceVu0InnerProduct(&w, &ed);
            if (!(t < 0.0f) && t <= len) {
                sceVu0ScaleVector(out, &ed, t / len);
                sceVu0AddVector(out, out, v);
                out->w = 1.0f;
                sceVu0SubVector(out + 1, sph, out);
                d2 = sceVu0InnerProduct(out + 1, out + 1);
                *dist = d2;
                if (d2 <= r2) {
                    *dist = sqrtf(d2);
                    sceVu0ScaleVector(out + 1, out + 1, 1.0f / *dist);
                    return 1;
                }
            }
        }
    }
    return 0;
}
#undef sceVu0SubVector
#undef sceVu0InnerProduct
#undef sceVu0CopyVector

/* Coll_SweptVsTriangle_1_0014F520 */
#define sceVu0SubVector sceVu0SubVector__as_Coll_SweptVsTriangle_1_0014F520
void sceVu0SubVector__as_Coll_SweptVsTriangle_1_0014F520(Vec *, Vec *, Vec *);
#define sceVu0InnerProduct sceVu0InnerProduct__as_Coll_SweptVsTriangle_1_0014F520
f32 sceVu0InnerProduct__as_Coll_SweptVsTriangle_1_0014F520(Vec *, Vec *);
#define sceVu0CopyVector sceVu0CopyVector__as_Coll_SweptVsTriangle_1_0014F520
void sceVu0CopyVector__as_Coll_SweptVsTriangle_1_0014F520(Vec *, Vec *);

s32 Coll_SweptVsTriangle_1_0014F520(Vec *out, Vec *p, Vec *q, Vec *v, Vec *n, s32 i, s32 two, f32 *dist) {
    Vec h;
    Vec hn;
    Vec d;
    Vec a1;
    Vec b1;
    Vec c1;
    Vec a2;
    Vec b2;
    Vec c2;
    Vec a3;
    Vec b3;
    Vec c3;
    Vec *v0;
    Vec *v1;
    Vec *v2;
    f32 num;
    f32 den;
    f32 t;
    f32 e1;
    f32 e2;
    f32 e3;

    v0 = &v[i % 3];
    v1 = &v[(i + 1) % 3];
    v2 = &v[(i + 2) % 3];
    sceVu0SubVector(&d, q, p);
    d.w = 0.0f;
    if (two == 0) {
        sceVu0Normalize(&h, &d);
        if (!(sceVu0InnerProduct(&h, n) < 0.0f)) {
            return 0;
        }
    }
    num = -sceVu0InnerProduct(v0, n);
    den = sceVu0InnerProduct(n, &d);
    if (den == 0.0f) {
        return 0;
    }
    t = -(num + sceVu0InnerProduct(n, p)) / den;
    if (!(t <= 1.0f) || t < 0.0f) {
        return 0;
    }
    sceVu0ScaleVector(&d, &d, t);
    sceVu0AddVector(&h, p, &d);
    sceVu0AddVector(&hn, &h, n);
    sceVu0SubVector(&a1, v0, &h);
    a1.w = 0.0f;
    sceVu0SubVector(&b1, v1, v0);
    b1.w = 0.0f;
    sceVu0OuterProduct(&c1, &a1, &b1);
    c1.w = 0.0f;
    e1 = sceVu0InnerProduct(&c1, &hn) - sceVu0InnerProduct(&c1, &h);
    sceVu0SubVector(&a2, v1, &h);
    a2.w = 0.0f;
    sceVu0SubVector(&b2, v2, v1);
    b2.w = 0.0f;
    sceVu0OuterProduct(&c2, &a2, &b2);
    c2.w = 0.0f;
    e2 = sceVu0InnerProduct(&c2, &hn) - sceVu0InnerProduct(&c2, &h);
    sceVu0SubVector(&a3, v2, &h);
    a3.w = 0.0f;
    sceVu0SubVector(&b3, v0, v2);
    b3.w = 0.0f;
    sceVu0OuterProduct(&c3, &a3, &b3);
    c3.w = 0.0f;
    e3 = sceVu0InnerProduct(&c3, &hn) - sceVu0InnerProduct(&c3, &h);
    if (!(e1 < 0.0f || e2 < 0.0f || e3 < 0.0f) || (e1 < 0.0f && e2 < 0.0f && e3 < 0.0f)) {
        sceVu0CopyVector(out, &h);
        *(s32 *)&out->w = 0x3F800000;
        sceVu0CopyVector(out + 1, n);
        if (dist) {
            sceVu0SubVector(&h, p, out);
            h.w = 0.0f;
            *dist = sqrtf(sceVu0InnerProduct(&h, &h));
        }
        return 1;
    }
    return 0;
}
#undef sceVu0SubVector
#undef sceVu0InnerProduct
#undef sceVu0CopyVector

/* Coll_BoxOverlap_0_0014F8C0 */
s32 Coll_BoxOverlap_0_0014F8C0(s32 arg0, s32 arg1, f32 *box, s32 arg3) {
    f32 m[4][4];
    f32 a[4];
    f32 b[4];

    sceVu0InversMatrix(m, arg3);
    sceVu0ApplyMatrix(a, m, arg0);
    sceVu0ApplyMatrix(b, m, arg1);
    if (a[0] < box[0] && b[0] < box[0]) {
        return 0;
    }
    if (a[1] < box[1] && b[1] < box[1]) {
        return 0;
    }
    if (a[2] < box[2] && b[2] < box[2]) {
        return 0;
    }
    if (!(a[0] <= box[4]) && !(b[0] <= box[4])) {
        return 0;
    }
    if (!(a[1] <= box[5]) && !(b[1] <= box[5])) {
        return 0;
    }
    if (!(a[2] <= box[6]) && !(b[2] <= box[6])) {
        return 0;
    }
    return 1;
}
