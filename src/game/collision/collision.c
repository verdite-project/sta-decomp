#include "common.h"
#include "game/collision.h"
typedef struct { f32 a[4]; f32 b[4]; } R;
typedef struct { Vec p; Vec q; } Obj_Coll_SweepSegments_1_00150350;
typedef struct { Obj_Coll_SweepSegments_1_00150350 *a; Obj_Coll_SweepSegments_1_00150350 *b; } Pair_Coll_SweepSegments_1_00150350;
typedef struct { u8 pad[0xC]; f32 xC; u8 pad2[0x18]; s32 x28; } Tgt_Coll_SweepSegments_1_00150350;
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; u8 pad[4]; } Res;
typedef struct { Seg *a; Seg *b; } Pair_Coll_SweepRecursive_0_00150730;
typedef struct { Res *a; Res *b; } RPair __attribute__((aligned(16)));
typedef struct { Vec a; Vec b; f32 x20; f32 x24; } Out;
typedef struct { Vec p; Vec v; } Sph;
typedef struct { Vec p; Vec d; } Cap;
typedef struct { Vec p; f32 pad[3]; f32 r; } Obj_Coll_SweepCapsules_0_00151900;
typedef struct { Obj_Coll_SweepCapsules_0_00151900 *a; Obj_Coll_SweepCapsules_0_00151900 *b; } Pair_Coll_SweepCapsules_0_00151900;
typedef struct { u8 pad[0x28]; s32 x28; } Tgt_Coll_SweepCapsules_0_00151900;
extern s32 gCollSweepSegmentsInitSbss_00201F24;
void Coll_ClosestPointA_0_00150020(Vec *o, Vec *p, Vec *q);
void Coll_ClosestPointB_0_00150160(Vec *o, Vec *a, Vec *b);
void Seg_Init_1_001502A0(R *r, f32 *from, f32 *to, f32 w);
s32 Coll_SweepSegments_1_00150350(Tgt_Coll_SweepSegments_1_00150350 *t, Pair_Coll_SweepSegments_1_00150350 *a, Pair_Coll_SweepSegments_1_00150350 *b, f32 s, f32 len, f32 f);
s32 Coll_SweepRecursive_0_00150730(Out *o, Pair_Coll_SweepRecursive_0_00150730 *p1, Pair_Coll_SweepRecursive_0_00150730 *p2, f32 t0, f32 dt, RPair *p3, s32 *state, f32 *best, f32 eps);
s32 Coll_SphereVsPlane_1_00150C00(Sph *s, Vec *p, Vec *n, Vec *out, f32 *t, f32 *d);
s32 Coll_CapsuleVsRay_1_001511C0(Cap *c, Vec *p, Vec *d, Vec *r1, Vec *r2, f32 *out);
void Coll_SweepCapsules_0_00151900(Tgt_Coll_SweepCapsules_0_00151900 *t, Obj_Coll_SweepCapsules_0_00151900 *a1, Obj_Coll_SweepCapsules_0_00151900 *a2, Obj_Coll_SweepCapsules_0_00151900 *b1, Obj_Coll_SweepCapsules_0_00151900 *b2, f32 f);
void sceVu0ScaleVector(void *, void *, f32);
void sceVu0SubVector(void *, void *, void *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0CopyVector(void *, void *);
f32 sceVu0InnerProduct(void *, void *);
f32 sqrtf(f32 x);
void Coll_SweepSegmentsInit_1_00151E50(Tgt_Coll_SweepSegments_1_00150350 *, Obj_Coll_SweepSegments_1_00150350 *, Obj_Coll_SweepSegments_1_00150350 *, Obj_Coll_SweepSegments_1_00150350 *, Obj_Coll_SweepSegments_1_00150350 *);
void sceVu0InterVector(Vec *, Vec *, Vec *, f32);
void Seg_ClosestPoints_3_00151B20(Res *, Seg *, Seg *);
f32 fabsf(f32);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
void Coll_SweepSegments_1_00150350__as_Coll_SweepCapsules_0_00151900(Tgt_Coll_SweepCapsules_0_00151900 *, Pair_Coll_SweepCapsules_0_00151900 *, Pair_Coll_SweepCapsules_0_00151900 *, f32, f32, f32);

/* Coll_ClosestPointA_0_00150020 */
#define sceVu0ScaleVector sceVu0ScaleVector__as_Coll_ClosestPointA_0_00150020
void sceVu0ScaleVector__as_Coll_ClosestPointA_0_00150020(Vec *, Vec *, f32);
#define sceVu0SubVector sceVu0SubVector__as_Coll_ClosestPointA_0_00150020
void sceVu0SubVector__as_Coll_ClosestPointA_0_00150020(Vec *, Vec *, Vec *);

/* Coll_ClosestPointA_0_00150020 */
void Coll_ClosestPointA_0_00150020(Vec *o, Vec *p, Vec *q) {
    Vec m;
    Vec a;
    Vec b;
    f32 f;
    sceVu0SubVector(&m, q, p);
    sceVu0ScaleVector(&m, &m, 0.5f);
    sceVu0AddVector(o, p, &m);
    sceVu0ScaleVector(&a, &p[1], p[1].w);
    sceVu0AddVector(&a, &a, p);
    sceVu0ScaleVector(&b, &q[1], q[1].w);
    sceVu0AddVector(&b, &b, q);
    sceVu0SubVector(&m, &b, &a);
    sceVu0ScaleVector(&m, &m, 0.5f);
    sceVu0AddVector(&o[1], &a, &m);
    f = Vec_DistB_3_0015DF50(&o[1], o);
    sceVu0SubVector(&o[1], &o[1], o);
    sceVu0Normalize(&o[1], &o[1]);
    o[1].w = f;
    o[0].w = 1.2f * q[0].w;
}

/* Coll_ClosestPointB_0_00150160 */
void Coll_ClosestPointB_0_00150160(Vec *o, Vec *a, Vec *b) {
    Vec t;
    Vec u;
    Vec w;
    f32 r;
    sceVu0SubVector(&t, b, a);
    sceVu0ScaleVector(&t, &t, 0.5f);
    sceVu0AddVector(o, a, &t);
    sceVu0ScaleVector(&u, &a[1], a[1].w);
    sceVu0AddVector(&u, &u, a);
    sceVu0ScaleVector(&w, &b[1], b[1].w);
    sceVu0AddVector(&w, &w, b);
    sceVu0SubVector(&t, &w, &u);
    sceVu0ScaleVector(&t, &t, 0.5f);
    sceVu0AddVector(&o[1], &u, &t);
    r = Vec_DistB_3_0015DF50(&o[1], o);
    sceVu0SubVector(&o[1], &o[1], o);
    sceVu0Normalize(&o[1], &o[1]);
    o[1].w = r;
    o->w = 1.2f * b->w;
}
#undef sceVu0ScaleVector
#undef sceVu0SubVector

/* Seg_Init_1_001502A0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Seg_Init_1_001502A0
void sceVu0CopyVector__as_Seg_Init_1_001502A0(f32 *v0, f32 *v1);
#define sceVu0SubVector sceVu0SubVector__as_Seg_Init_1_001502A0
void sceVu0SubVector__as_Seg_Init_1_001502A0(f32 *v0, f32 *v1, f32 *v2);
#define sceVu0InnerProduct sceVu0InnerProduct__as_Seg_Init_1_001502A0
f32 sceVu0InnerProduct__as_Seg_Init_1_001502A0(f32 *v0, f32 *v1);
#define sceVu0ScaleVector sceVu0ScaleVector__as_Seg_Init_1_001502A0
void sceVu0ScaleVector__as_Seg_Init_1_001502A0(f32 *v0, f32 *v1, f32 s);

void Seg_Init_1_001502A0(R *r, f32 *from, f32 *to, f32 w)
{
    f32 len;
    sceVu0CopyVector(r->a, from);
    sceVu0SubVector(r->b, to, from);
    len = sqrtf(sceVu0InnerProduct(r->b, r->b));
    sceVu0ScaleVector(r->b, r->b, 1.0f / len);
    r->a[3] = w;
    r->b[3] = len;
}
#undef sceVu0CopyVector
#undef sceVu0SubVector
#undef sceVu0InnerProduct
#undef sceVu0ScaleVector

/* Coll_SweepSegments_1_00150350 */
#define sceVu0InnerProduct sceVu0InnerProduct__as_Coll_SweepSegments_1_00150350
f32 sceVu0InnerProduct__as_Coll_SweepSegments_1_00150350(Vec *, Vec *);
#define sceVu0ScaleVector sceVu0ScaleVector__as_Coll_SweepSegments_1_00150350
void sceVu0ScaleVector__as_Coll_SweepSegments_1_00150350(Vec *, Vec *, f32);
#define sceVu0CopyVector sceVu0CopyVector__as_Coll_SweepSegments_1_00150350
void sceVu0CopyVector__as_Coll_SweepSegments_1_00150350(Vec *, Vec *);
#define sceVu0SubVector sceVu0SubVector__as_Coll_SweepSegments_1_00150350
void sceVu0SubVector__as_Coll_SweepSegments_1_00150350(Vec *, Vec *, Vec *);

/* Coll_SweepSegments_1_00150350 */
s32 Coll_SweepSegments_1_00150350(Tgt_Coll_SweepSegments_1_00150350 *t, Pair_Coll_SweepSegments_1_00150350 *a, Pair_Coll_SweepSegments_1_00150350 *b, f32 s, f32 len, f32 f) {
    Vec av[2];
    Vec bv[2];
    Obj_Coll_SweepSegments_1_00150350 m[2];
    f32 d1;
    f32 d2;
    s32 r; f32 h;
    sceVu0CopyVector(&av[0], &a->a->q);
    av[0].w = 0.0f;
    sceVu0CopyVector(&av[1], &a->b->q);
    av[1].w = 0.0f;
    sceVu0CopyVector(&bv[0], &b->a->q);
    bv[0].w = 0.0f;
    sceVu0CopyVector(&bv[1], &b->b->q);
    bv[1].w = 0.0f;
    d1 = sceVu0InnerProduct(&av[0], &av[1]);
    d2 = sceVu0InnerProduct(&bv[0], &bv[1]);
    if ((d1 < f || d2 < f) && !(len <= 0.1f)) {
        Pair_Coll_SweepSegments_1_00150350 p1 = {0};
        p1.a = a->a;
        p1.b = &m[0];
        {
            Pair_Coll_SweepSegments_1_00150350 p2 = {0};
            p2.a = b->a;
            p2.b = &m[1];
            {
                Pair_Coll_SweepSegments_1_00150350 p3 = {0};
                p3.a = &m[0];
                p3.b = a->b;
                {
                    Pair_Coll_SweepSegments_1_00150350 p4 = {0};
                    p4.a = &m[1];
                    p4.b = b->b;
                    sceVu0AddVector(&m[0].p, &a->a->p, &a->b->p);
                    sceVu0AddVector(&m[0].q, &a->a->q, &a->b->q);
                    m[0].q.w = 0.0f;
                    sceVu0ScaleVector(&m[0].p, &m[0].p, 0.5f);
                    sceVu0Normalize(&m[0].q, &m[0].q);
                    m[0].p.w = a->a->p.w;
                    m[0].q.w = 0.5f * (a->a->q.w + a->b->q.w);
                    sceVu0AddVector(&m[1].p, &b->a->p, &b->b->p);
                    sceVu0AddVector(&m[1].q, &b->a->q, &b->b->q);
                    m[1].q.w = 0.0f;
                    sceVu0ScaleVector(&m[1].p, &m[1].p, 0.5f);
                    sceVu0Normalize(&m[1].q, &m[1].q);
                    m[1].p.w = b->a->p.w;
                    m[1].q.w = 0.5f * (b->a->q.w + b->b->q.w);
                    h = 0.5f * len;
                    if ((r = Coll_SweepSegments_1_00150350(t, &p1, &p2, s, h, f)) != 0) return r;
                    if (t->x28 == 2) return 2;
                    if ((r = Coll_SweepSegments_1_00150350(t, &p3, &p4, s + h, h, f)) != 0) return r;
                }
            }
        }
    } else {
        Coll_SweepSegmentsInit_1_00151E50(t, a->a, a->b, b->a, b->b);
        if (t->x28 == 2) {
            t->xC = s;
            return 2;
        }
        if (t->x28 == 1) {
            t->xC = s + t->xC * len;
            return 1;
        }
    }
    return 0;
}

/* Coll_SweepRecursive_0_00150730 */
s32 Coll_SweepRecursive_0_00150730(Out *o, Pair_Coll_SweepRecursive_0_00150730 *p1, Pair_Coll_SweepRecursive_0_00150730 *p2, f32 t0, f32 dt, RPair *p3, s32 *state, f32 *best, f32 eps) {
    Seg m1;
    Seg m2;
    Res r;
    s32 ret;
    u32 flags;
    f32 v;
    f32 d0;
    f32 d1;
    f32 mid;
    f32 h;

    ret = 0;
    flags = 0;
    sceVu0InterVector(&m1.p, &p1->a->p, &p1->b->p, 0.5f);
    sceVu0InterVector(&m2.p, &p2->a->p, &p2->b->p, 0.5f);
    sceVu0InterVector(&m1.d, &p1->a->d, &p1->b->d, 0.5f);
    sceVu0InterVector(&m2.d, &p2->a->d, &p2->b->d, 0.5f);
    sceVu0Normalize(&m1.d, &m1.d);
    sceVu0Normalize(&m2.d, &m2.d);
    m1.d.w = p1->a->d.w;
    m2.d.w = p2->a->d.w;
    gCollSweepSegmentsInitSbss_00201F24++;
    Seg_ClosestPoints_3_00151B20(&r, &m1, &m2);
    if (r.hit) {
        *state = 2;
        v = t0 + 0.5f * dt;
        if (v < *best) {
            *best = v;
            sceVu0InterVector(&o->a, &r.a, &r.b, r.b.w);
            o->a.w = *best;
            o->x20 = r.a.w;
            o->x24 = r.b.w;
            sceVu0SubVector(&o->b, &r.b, &r.a);
        }
    }
    h = 0.5f * dt;
    if (h < eps) {
        if (*state == 1) {
            sceVu0InterVector(&o->a, &r.a, &r.b, r.b.w);
            o->a.w = *best;
            o->x20 = r.a.w;
            o->x24 = r.b.w;
            sceVu0SubVector(&o->b, &r.b, &r.a);
        }
        return 1;
    }
    if (r.hit) {
        flags = 1;
    } else {
        d0 = sceVu0InnerProduct(&p3->a->c, &r.c);
        d1 = sceVu0InnerProduct(&p3->b->c, &r.c);
        if (d0 > 0.0f && d1 > 0.0f) {
            flags = 3;
        } else {
            if (d1 < d0) flags |= 2;
            if (!(d1 <= d0)) flags |= 1;
        }
    }
    if (flags & 1) {
        Pair_Coll_SweepRecursive_0_00150730 q1 = {0};
        q1.a = p1->a;
        q1.b = &m1;
        {
            Pair_Coll_SweepRecursive_0_00150730 q2 = {0};
            q2.a = p2->a;
            q2.b = &m2;
            {
                RPair q3 = {0};
                q3.a = p3->a;
                q3.b = &r;
                ret = Coll_SweepRecursive_0_00150730(o, &q1, &q2, t0, h, &q3, state, best, eps);
            }
        }
    }
    mid = t0 + h;
    if (!(*best <= mid) && (flags & 2)) {
        Pair_Coll_SweepRecursive_0_00150730 q1 = {0};
        q1.a = &m1;
        q1.b = p1->b;
        {
            Pair_Coll_SweepRecursive_0_00150730 q2 = {0};
            q2.a = &m2;
            q2.b = p2->b;
            {
                RPair q3 = {0};
                q3.a = &r;
                q3.b = p3->b;
                ret = Coll_SweepRecursive_0_00150730(o, &q1, &q2, mid, h, &q3, state, best, eps);
            }
        }
    }
    if (ret == 1) ret = 2;
    return ret;
}

/* Coll_SphereVsPlane_1_00150C00 */
s32 Coll_SphereVsPlane_1_00150C00(Sph *s, Vec *p, Vec *n, Vec *out, f32 *t, f32 *d) {
    Vec a;
    Vec b;
    Vec c;
    Vec e;
    f32 d0;
    f32 d1;
    f32 pen;
    f32 m;
    f32 dv;

    *d = 0.0f;
    sceVu0CopyVector(&a, &s->p);
    sceVu0SubVector(&c, p, &a);
    sceVu0CopyVector(&b, &s->p);
    b.x += s->v.x * s->v.w;
    b.y += s->v.y * s->v.w;
    b.z += s->v.z * s->v.w;
    sceVu0SubVector(&e, p, &b);
    d0 = n->x * c.x + n->y * c.y + n->z * c.z;
    d1 = n->x * e.x + n->y * e.y + n->z * e.z;
    if (d0 < -s->p.w && d1 < -s->p.w) return 0;
    if (!(d0 <= s->p.w) && !(d1 <= s->p.w)) return 0;
    pen = s->p.w + d1;
    dv = n->x * s->v.x + n->y * s->v.y + n->z * s->v.z;
    pen = pen < 0.0f ? 0.0f : pen;
    if (fabsf(dv) < 0.2f) {
        *t = 0.0f;
        sceVu0ScaleVector(out, n, -s->p.w);
        sceVu0AddVector(out, out, &a);
        *d = pen;
        return 4;
    }
    if (d0 * d1 < 0.0f) {
        if (fabsf(d0 - d1) < 1e-05f) {
            *t = 0.0f;
        } else {
            *t = (fabsf(d0) - s->p.w) / (d1 - d0);
        }
        if (*t < 0.0f) *t = 0.0f;
        if (!(*t <= 1.0f)) *t = 1.0f;
        sceVu0ScaleVector(&b, &s->v, *t * s->v.w);
        sceVu0AddVector(&b, &b, &s->p);
        sceVu0ScaleVector(out, n, -s->p.w);
        sceVu0AddVector(out, out, &b);
        *d = 0.0f;
        return 1;
    }
    m = d1;
    if (fabsf(d0) < fabsf(d1)) m = d0;
    if (fabsf(m) < s->p.w) {
        if (m == d0) {
            d1 = d0 - d1;
            if (fabsf(d1) < 1e-05f) {
                *t = 0.0f;
            } else {
                *t = (s->p.w - fabsf(d0)) / d1;
            }
            if (*t < 0.0f) *t = 0.0f;
            if (!(*t <= 1.0f)) *t = 1.0f;
            sceVu0ScaleVector(&b, &s->v, *t * s->v.w);
            sceVu0AddVector(&b, &b, &s->p);
            if (d0 < 0.0f) {
                sceVu0ScaleVector(out, n, -s->p.w);
                sceVu0AddVector(out, out, &b);
            } else {
                sceVu0ScaleVector(out, n, s->p.w);
                sceVu0AddVector(out, out, &b);
            }
            *d = pen;
            return 2;
        } else {
            if (fabsf(d0 - d1) < 1e-05f) {
                *t = 0.0f;
            } else {
                *t = (fabsf(d0) - s->p.w) / (d1 - d0);
            }
            if (*t < 0.0f) *t = 0.0f;
            if (!(*t <= 1.0f)) *t = 1.0f;
            sceVu0ScaleVector(&b, &s->v, *t * s->v.w);
            sceVu0AddVector(&b, &b, &s->p);
            if (d0 < 0.0f) {
                sceVu0ScaleVector(out, n, -s->p.w);
                sceVu0AddVector(out, out, &b);
            } else {
                sceVu0ScaleVector(out, n, s->p.w);
                sceVu0AddVector(out, out, &b);
            }
            *d = pen;
            return 3;
        }
    }
    return 0;
}

/* Coll_CapsuleVsRay_1_001511C0 */
static inline f32 clampf(f32 v, f32 lo, f32 hi) { if (v < lo) return lo; if (!(v <= hi)) return hi; return v; }

s32 Coll_CapsuleVsRay_1_001511C0(Cap *c, Vec *p, Vec *d, Vec *r1, Vec *r2, f32 *out) {
    Vec n;
    Vec cr;
    Vec dp;
    Vec e;
    Vec P1;
    Vec P2;
    Vec D;
    Vec A;
    Vec B;
    Vec t180;
    Vec t170;
    Vec t160;
    Vec t150;
    Vec Q1;
    Vec Q2;
    Vec W;
    Vec t110;
    Vec t100;
    Vec tF0;
    Vec tE0;
    Vec tD0;
    Vec tC0;
    Vec tB0;
    Vec tA0;
    Vec t90;
    f32 a;
    f32 b;
    f32 s;
    f32 u;
    f32 dd, x;
    u8 fl;

    sceVu0ScaleVector(&n, d, sceVu0InnerProduct(d, &c->d));
    sceVu0SubVector(&n, d, &n);
    sceVu0Normalize(&n, &n);
    sceVu0OuterProduct(&cr, &n, &c->d);
    sceVu0SubVector(&dp, p, &c->p);
    x = sceVu0InnerProduct(&cr, &dp);
    x = x < 0.0f ? -x : x;
    if (!(x <= c->p.w)) return 0;
    a = sceVu0InnerProduct(&n, d);
    b = sceVu0InnerProduct(&c->d, d);
    s = sceVu0InnerProduct(&n, &dp);
    dd = sceVu0InnerProduct(&c->d, &dp);
    if (s < -c->p.w && s + a < -c->p.w) return 0;
    if (!(s <= c->p.w) && !(s + a <= c->p.w)) return 0;
    if (dd < -c->p.w && dd + b < -c->p.w) return 0;
    if (!(dd <= c->d.w + c->p.w) && !(dd + b <= c->d.w + c->p.w)) return 0;

    sceVu0SubVector(&e, p, &c->p);
    a = sceVu0InnerProduct(&c->d, d);
    b = sceVu0InnerProduct(&e, &c->d);
    s = sceVu0InnerProduct(&e, d);
    dd = sceVu0InnerProduct(d, d);
    fl = 0;
    x = (dd * b - a * s) / (dd - a * a);
    u = (a * b - s) / (dd - a * a);
    s = x;
    x = s;
    b = u;
    if (s < 0.0f) {
        x = 0.0f;
        fl |= 1;
    } else if (!(s <= c->d.w)) {
        x = c->d.w;
        fl |= 2;
    }
    if (u < 0.0f) {
        b = 0.0f;
        fl |= 4;
    } else if (!(u <= 1.0f)) {
        b = 1.0f;
        fl |= 8;
    }
    sceVu0ScaleVector(&A, &c->d, x);
    sceVu0AddVector(&P1, &A, &c->p);
    sceVu0ScaleVector(&B, d, b);
    sceVu0AddVector(&P2, &B, p);
    sceVu0SubVector(&D, &P2, &P1);
    if (fl) {
        if (fl & 0xC) {
            sceVu0SubVector(&t180, &P2, &c->p);
            dd = sceVu0InnerProduct(&t180, &c->d);
            if (dd < 0.0f) x = 0.0f;
            else if (!(dd <= c->d.w)) x = c->d.w;
            else x = dd;
            sceVu0ScaleVector(&t170, &c->d, x);
            sceVu0AddVector(&P1, &t170, &c->p);
        }
        if (fl & 3) {
            sceVu0SubVector(&t160, &P1, p);
            x = sceVu0InnerProduct(&t160, d) / sceVu0InnerProduct(d, d);
            x = clampf(x, 0.0f, 1.0f);
            sceVu0ScaleVector(&t150, d, x);
            sceVu0AddVector(&P2, &t150, p);
        }
        sceVu0SubVector(&D, &P2, &P1);
    }
    a = c->p.w;
    a *= a;
    if (!(sceVu0InnerProduct(&D, &D) <= a)) return 0;
    sceVu0ScaleVector(&t110, &c->d, s);
    sceVu0AddVector(&Q1, &t110, &c->p);
    sceVu0ScaleVector(&t100, d, u);
    sceVu0AddVector(&Q2, &t100, p);
    sceVu0SubVector(&W, &Q2, &Q1);
    s = s - sqrtf(a - sceVu0InnerProduct(&W, &W));
    if (s < 0.0f) s = 0.0f;
    else if (!(s <= c->d.w)) s = c->d.w;
    sceVu0ScaleVector(&tD0, &c->d, s);
    sceVu0AddVector(&Q1, &tD0, &c->p);
    sceVu0SubVector(&tF0, &Q1, p);
    x = sceVu0InnerProduct(&tF0, d) / sceVu0InnerProduct(d, d);
    if (x < 0.0f || !(x <= 1.0f)) {
        if (x < 0.0f) x = 0.0f;
        else if (!(x <= 1.0f)) x = 1.0f;
        sceVu0ScaleVector(&tC0, d, x);
        sceVu0AddVector(&Q2, &tC0, p);
        sceVu0SubVector(&tE0, &Q2, &c->p);
        s = sceVu0InnerProduct(&tE0, &c->d);
        sceVu0ScaleVector(&tB0, &c->d, s);
        sceVu0AddVector(&Q1, &tB0, &c->p);
        sceVu0SubVector(&W, &Q2, &Q1);
        s = s - sqrtf(a - sceVu0InnerProduct(&W, &W));
        if (s < 0.0f) s = 0.0f;
        else if (!(s <= c->d.w)) s = c->d.w;
        sceVu0ScaleVector(&tA0, &c->d, s);
        sceVu0AddVector(&Q1, &tA0, &c->p);
    } else {
        sceVu0ScaleVector(&t90, d, x);
        sceVu0AddVector(&Q2, &t90, p);
    }
    sceVu0CopyVector(r1, &Q2);
    r1->w = 0.0f;
    sceVu0SubVector(r2, &Q1, &Q2);
    r2->w = 0.0f;
    *out = s / c->d.w;
    return 1;
}

/* Coll_SweepCapsules_0_00151900 */
static inline f32 fmax(f32 a, f32 b) { return (a <= b) ? b : a; }
static inline f32 fmax2(f32 a, f32 b) { if (a <= b) return b; return a; }

void Coll_SweepCapsules_0_00151900(Tgt_Coll_SweepCapsules_0_00151900 *t, Obj_Coll_SweepCapsules_0_00151900 *a1, Obj_Coll_SweepCapsules_0_00151900 *a2, Obj_Coll_SweepCapsules_0_00151900 *b1, Obj_Coll_SweepCapsules_0_00151900 *b2, f32 f) {
    Res r;
    Seg A;
    Seg B;
    f32 len;
    t->x28 = 0;
    sceVu0CopyVector(&A.p, &a1->p);
    sceVu0SubVector(&A.d, &a2->p, &a1->p);
    len = sqrtf(sceVu0InnerProduct(&A.d, &A.d));
    sceVu0ScaleVector(&A.d, &A.d, 1.0f / len);
    A.d.w = len;
    if (!(a1->r <= a2->r)) A.p.w = a1->r; else A.p.w = a2->r;
    sceVu0CopyVector(&B.p, &b1->p);
    sceVu0SubVector(&B.d, &b2->p, &b1->p);
    len = sqrtf(sceVu0InnerProduct(&B.d, &B.d));
    sceVu0ScaleVector(&B.d, &B.d, 1.0f / len);
    B.d.w = len;
    if (!(b1->r <= b2->r)) B.p.w = b1->r; else B.p.w = b2->r;
    Seg_ClosestPoints_3_00151B20(&r, &A, &B);
    if (r.hit) {
        Pair_Coll_SweepCapsules_0_00151900 p1 = {0};
        p1.a = a1;
        p1.b = a2;
        {
            Pair_Coll_SweepCapsules_0_00151900 p2 = {0};
            p2.a = b1;
            p2.b = b2;
            Coll_SweepSegments_1_00150350__as_Coll_SweepCapsules_0_00151900(t, &p1, &p2, 0.0f, 1.0f, f);
        }
    }
}
#undef sceVu0InnerProduct
#undef sceVu0ScaleVector
#undef sceVu0CopyVector
#undef sceVu0SubVector
