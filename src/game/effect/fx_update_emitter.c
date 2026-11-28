#include "common.h"
typedef union { s16 h; Flags8 f; } S;
typedef struct { u8 b[0x14]; } Fr;
typedef struct { u8 p[0x7C]; s8 c; u8 q[3]; } TE;
typedef struct { u16 b0:5; u16 k:2; u16 w:4; u16 h:4; u16 b15:1; } TB;
typedef struct { u8 m:3; u8 r:5; } MB;
typedef struct {
    u16 x0; u8 p2[2]; u8 x4; u8 p5[2]; Flags8 x7; u16 x8; u8 pA[6];
    MB x10; u8 p11; TB x12; u8 p14[0xC]; u16 x20; u16 x22; u16 x24; u8 p26[4]; u16 x2A;
    u8 p2C[0x18]; f32 x44; u8 p48[0x2C]; u8 x74[0x10]; u8 x84[0x10]; u8 x94[8]; u8 x9C[0x10];
    u8 xAC[8]; u8 xB4[8]; u8 xBC[8]; u8 xC4[0x10]; u8 xD4[0x10]; u8 xE4[8]; u8 xEC[8]; u8 xF4[8];
    u8 xFC[0xC]; Fr x108[1];
} A;
typedef struct {
    u8 p0[0x17C]; f32 x17C; f32 x180; u8 p184[4]; Flags8 x188; u8 p189; u8 x18A; u8 p18B[0x85];
    A *e[1];
} T;
typedef struct {
    Vec v; Vec x10; f32 x20, x24, x28, x2C; Vec x30; Vec x40; Vec x50; Vec x60; Vec x70;
    f32 x80, x84, x88, x8C; T *x90; u16 x94; u8 x96[8]; u8 p9E[2]; u16 xA0; u8 pA2[2]; f32 xA4;
    u8 pA8[0x18]; Mtx xC0; Vec x100; u8 p110[4]; Flags8 x114; u8 p115[0xB];
} O;
typedef struct {
    f32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24; u32 x28; u8 p2C; Flags8 x2D;
} R;
extern O *gSfxSystemSbss_00201FC0;
extern Vec gMatrixFromData_001F2140;
extern Vec gMatrixFromData_001F2150;
extern Vec gMatrixFromData_001F2160;
S FxTable_GetEntry_0_0014D8A0(u16);
void FxTable_CallB_0_0014D940(u16, O *, f32);
void Fx_GetWorldMatrix_1_00163C80(O *, Mtx *);
void Fx_GetWorldPos_1_00163D90(O *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void Fx_EvalCurveVec_1_001631E0(f32, void *, u8 *, Fr *, s8 *, f32, s32);
void Fx_EvalCurve_1_00163700(f32, void *, u8 *, Fr *, s8 *, f32, s32);
f32 DegToRad_3_00161030(f32);
f32 Angle_Wrap2Pi_3_001462D0(f32);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void Mtx_LookDir_1_00146020(Mtx *, f32, f32, f32);
f32 Angle_Wrap2PiB_2_00146B90(f32);
void Fx_UpdateChildrenEx_1_001629E0(O *, s8, s32, f32);
s32 Attack_TraceProjectile_0_001D22E0(O *, f32);
f32 sqrtf(f32);
static inline A *ent(T **t, u16 *i) { return (*t)->e[*i]; }
static inline u32 cv(f32 x, s32 s) { x = 255.0f * x / 255.0f; return (u32)x << s; }
static inline f32 u2f(u32 x) { return x; }

static inline void uv(R *r, O *o, A *a, u8 kk) {
    u16 cols;
    u16 rows;
    u16 col;
    u16 row;
    s32 n;
    u16 tw;
    u16 th;
    u16 nf;
    tw = a->x20;
    th = a->x22;
    nf = a->x24;
    cols = (u16)(1 << a->x12.w) / tw;
    rows = (u16)(1 << a->x12.h) / th;
    n = o->x84;
    if (nf) n %= nf * 2;
    if (kk == 2 && nf <= n) n = nf * 2 - n - 1;
    col = n % cols;
    row = (n / cols) % rows;
    r->x10 = 0.5f + col * tw;
    r->x14 = 0.5f + row * th;
    r->x18 = (col + 1) * tw - 0.5f;
    r->x1C = (row + 1) * th - 0.5f;
}

s32 Fx_UpdateEmitter_0_00160370(O *o, R *r, f32 dt) {
    Vec prev;
    Mtx m1;
    Vec v1C0;
    Vec v1B0;
    Mtx m2;
    Vec v160;
    Vec v150;
    Vec v140;
    Vec v130;
    Vec pos;
    Mtx m3;
    Mtx m4;
    S fl;
    S tmp;
    T *t;
    u16 bits;
    Fr *base;
    s8 *fr;
    s32 neg;
    A *a;
    O *p;
    f32 tm;
    f32 tot;
    s32 ret;
    s32 k;
    u16 cols;
    u16 rows;
    u16 col;
    u16 row;
    s32 n;
    f32 ang;
    f32 c;
    s8 ch;
    s32 packedColor;
    u32 channel;
    u8 kk;
    s32 kq;
    u16 tw;
    u16 th;
    u16 nf;

    a = o->x90->e[o->x94];
    t = *(T * volatile *)&o->x90;
    tmp = FxTable_GetEntry_0_0014D8A0(a->x8);
    fl = tmp;
    if (o->x114.f.b2) return 1;
    if (o->x114.f.b4) {
        if (u2f(a->x0) * 0.033333335f < o->x8C) {
            o->x8C = 0.0f;
            o->x96[0] = 0;
            o->x96[1] = 0;
            o->x96[2] = 0;
            o->x96[3] = 0;
            o->x96[4] = 0;
            o->x96[5] = 0;
            o->x96[6] = 0;
            o->x96[7] = 0;
        }
        if (o->x90->x188.f.b3 == 1) return 1;
    } else {
        o->x88 -= dt;
        if (o->x88 < 0.0f) return 1;
    }
    p = (o->xA0 == 0xFFFF) ? NULL : &gSfxSystemSbss_00201FC0[o->xA0];
    if (p != NULL && p->x114.f.b2) {
        if (o->x114.f.b5) {
            Fx_GetWorldMatrix_1_00163C80(o, &m1);
            Fx_GetWorldPos_1_00163D90(o, &v1C0);
            sceVu0CopyVector(&o->v, &m1.m[3]);
            sceVu0CopyVector(&o->x10, &v1C0);
            sceVu0CopyMatrix(&o->xC0, &m1);
            sceVu0CopyVector(&o->xC0.m[3], &gMatrixFromData_001F2160);
            o->x114.f.b5 = 0;
        }
        if (o->x114.f.b6) return 1;
        o->xA0 = 0xFFFF;
    }
    base = a->x108;
    fr = (s8 *)&base[a->x4];
    fr = a->x7.f.b1 ? fr + 0x40 : fr;
    fr = a->x7.f.b2 ? fr + 0xA0 : fr;
    tm = o->x8C;
    neg = !(0.0f < a->x44);
    tot = u2f(a->x0);
    bits = a->x2A;
    if (bits & 0x1) Fx_EvalCurveVec_1_001631E0(tm, &o->x70, a->x74, base, fr, tot, neg);
    if (bits & 0x2) Fx_EvalCurveVec_1_001631E0(tm, &o->x30, a->x84, base, fr, tot, neg);
    if (bits & 0x8) Fx_EvalCurveVec_1_001631E0(tm, &o->x40, a->x9C, base, fr, tot, neg);
    if (bits & 0x80) Fx_EvalCurveVec_1_001631E0(tm, &o->x20, a->xC4, base, fr, tot, neg);
    if (bits & 0x100) Fx_EvalCurveVec_1_001631E0(tm, &o->x50, a->xD4, base, fr, tot, neg);
    if (bits & 0x10) Fx_EvalCurve_1_00163700(tm, &o->x40.w, a->xAC, base, fr, tot, neg);
    if (bits & 0x20) Fx_EvalCurve_1_00163700(tm, &o->x80, a->xB4, base, fr, tot, neg);
    if (bits & 0x40) Fx_EvalCurve_1_00163700(tm, &o->x84, a->xBC, base, fr, tot, neg);
    if (bits & 0x200) Fx_EvalCurve_1_00163700(tm, &o->x60.x, a->xE4, base, fr, tot, neg);
    if (bits & 0x400) Fx_EvalCurve_1_00163700(tm, &o->x60.y, a->xEC, base, fr, tot, neg);
    if (bits & 0x800) Fx_EvalCurve_1_00163700(tm, &o->x60.z, a->xF4, base, fr, tot, neg);
    if (bits & 0x1000) Fx_EvalCurve_1_00163700(tm, &o->x60.w, a->xFC, base, fr, tot, neg);
    if (bits & 0x4) {
        Fx_EvalCurve_1_00163700(tm, &o->x30.w, a->x94, base, fr, tot, neg);
        o->x30.w = DegToRad_3_00161030(o->x30.w);
    }
    FxTable_CallB_0_0014D940(a->x8, o, dt);
    if (!(t->x18A & 1)) return 0;
    if (!fl.f.f.b1 && a->x10.m != 2) {
        c = t->x180;
        r->x20 = o->x70.x * c;
        r->x24 = o->x70.y * c;
    }
    k = fl.f.f.b0;
    if (!k && o->x30.w != 0.0f) {
        o->xA4 += o->x30.w * dt;
        o->xA4 = Angle_Wrap2Pi_3_001462D0(o->xA4);
    }
    if (!k) {
        sceVu0CopyVector(&prev, &o->v);
        if (o->x20 || o->x24 || o->x28) {
            if (0.999f < o->xC0.m[2].y || o->xC0.m[2].y < -0.999f) {
                sceVu0CopyVector(&v1B0, (Vec *)&o->x20);
            } else {
                sceVu0ApplyMatrix(&m2.m[2], &o->xC0, &gMatrixFromData_001F2150);
                sceVu0OuterProduct(&m2.m[0], &gMatrixFromData_001F2140, &m2.m[2]);
                sceVu0CopyVector(&m2.m[1], &gMatrixFromData_001F2140);
                sceVu0CopyVector(&m2.m[3], &gMatrixFromData_001F2160);
                sceVu0ApplyMatrix(&v1B0, &m2, (Vec *)&o->x20);
            }
            sceVu0ScaleVector(&v160, &v1B0, dt);
            sceVu0AddVector(&o->x10, &v160, &o->x10);
        }
        sceVu0ScaleVector(&v150, &o->x10, -0.01f * o->x80);
        sceVu0AddVector(&o->x10, &v150, &o->x10);
        sceVu0ScaleVector(&v140, &o->x10, dt);
        sceVu0AddVector(&o->v, &v140, &o->v);
    }
    if (!fl.f.f.b2 && a->x7.f.b3) {
        sceVu0SubVector(&v130, &o->v, &prev);
        if (sqrtf(sceVu0InnerProduct(&v130, &v130)) != 0.0f) {
            Mtx_LookDir_1_00146020(&o->xC0, v130.x, v130.y, v130.z);
        }
    }
    if (o->x114.f.b5) {
        Fx_GetWorldMatrix_1_00163C80(o, &m3);
        sceVu0CopyVector(&pos, &m3.m[3]);
    } else {
        sceVu0CopyVector(&pos, &o->v);
    }
    r->x0 = pos.x;
    r->x4 = pos.y;
    r->x8 = pos.z;
    if (a->x10.m != 2) {
        ang = 6.2831855f - o->xA4;
        if ((s32)(0.31830987f * ang) % 2) {
            r->xC = -Angle_Wrap2PiB_2_00146B90(ang);
            r->x2D.f.b4 = 0;
        } else {
            r->xC = Angle_Wrap2PiB_2_00146B90(ang);
            r->x2D.f.b4 = 1;
        }
    }
    kq = a->x12.k;
    if (kq) {
        kk = kq;
        uv(r, o, a, kk);
    }
    if (!(t->x17C == 1.0f) || o->x114.f.b3 || (a->x2A & 0x18)) {
        packedColor = cv(t->x17C * (o->x40.w * *(f32 *)((u8 *)t->e[0] + 0x8C)), 24);
        packedColor |= cv(o->x40.z, 16);
        channel = cv(o->x40.y, 8);
        packedColor = channel | packedColor;
        channel = cv(o->x40.x, 0);
        r->x28 = channel | packedColor;
    }
    if (t->x188.f.b2) {
        ch = ((TE *)((u8 *)t + 0x200))[o->x94].c;
        if (ch) Fx_UpdateChildrenEx_1_001629E0(o, ch, 0, dt);
    }
    ret = a->x7.f.b1 ? Attack_TraceProjectile_0_001D22E0(o, dt) : 0;
    if (o->x114.f.b5) {
        Fx_GetWorldMatrix_1_00163C80(o, &m4);
        sceVu0CopyVector(&o->x100, &m4.m[3]);
    } else {
        sceVu0CopyVector(&o->x100, &o->v);
    }
    o->x8C += dt;
    return ret;
}
