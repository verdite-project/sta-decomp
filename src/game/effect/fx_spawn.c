#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/effect.h"
typedef struct { u128 a, b, c; } Q3;
typedef struct {
    Vec r[4];
    Vec x40;
    Vec x50;
    f32 x60, x64, x68, x6C;
    u8 pad70[0x10];
} __attribute__((aligned(16))) P80;
typedef struct {
    u8 pad0[4];
    u8 x4;
    u8 pad5[5];
    u16 xA;
    u8 padC[0x38];
    f32 x44;
    u8 pad48[0x44];
    f32 x8C;
} F;
typedef struct {
    u8 pad0[0x150];
    u8 x150[0x24];
    f32 x174;
    u8 pad178[0x11];
    Flags8 x189;
    u8 pad18A[6];
    P80 x190;
    F *x210[4];
} M;
typedef struct {
    u8 pad0[7];
    Flags8 x7;
    u16 x8;
    u8 padA[6];
    u8 type:3;
    u8 r10:5;
    u8 pad11[0x33];
    f32 x44;
    u8 pad48[0x2C];
    f32 x74, x78, x7C;
    u8 pad80[4];
    f32 x84, x88, x8C;
    u8 pad90[4];
    f32 x94;
    u8 pad98[4];
    f32 x9C, xA0, xA4;
    u8 padA8[4];
    f32 xAC;
    u8 padB0[4];
    f32 xB4;
    u8 padB8[4];
    f32 xBC;
    u8 padC0[4];
    f32 xC4, xC8, xCC;
    u8 padD0[4];
    f32 xD4, xD8, xDC;
    u8 padE0[4];
    f32 xE4;
    u8 padE8[4];
    f32 xEC;
    u8 padF0[4];
    f32 xF4;
    u8 padF8[4];
    f32 xFC;
} A_Fx_SpawnParticle_1_00161060;
typedef struct {
    Vec x0;
    Vec x10;
    u8 pad20[4];
    f32 x24;
    f32 x28;
    f32 x2C;
} V;
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0xC];
    Q3 x20;
} H;
typedef struct {
    Vec x0;
    Vec x10;
    f32 x20, x24, x28, x2C;
    f32 x30, x34, x38, x3C;
    f32 x40, x44, x48, x4C;
    f32 x50, x54, x58, x5C;
    f32 x60, x64, x68, x6C;
    f32 x70, x74, x78, x7C;
    f32 x80, x84, x88;
    s32 x8C;
    M *x90;
    u16 x94;
    u8 x96[8];
    u16 x9E;
    u16 xA0;
    u8 padA2[2];
    f32 xA4;
    u8 padA8[0x18];
    Mtx xC0;
    Vec x100;
    s32 x110;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
    u8 b6:1;
    u8 b7:1;
    u8 pad115[0xB];
} O;
typedef struct {
    f32 x0, x4, x8;
    s32 xC;
    s32 x10, x14, x18;
    u8 pad1C[4];
    u16 x20, x22, x24;
    u8 pad26[2];
    u8 x28, x29, x2A, x2B;
    u16 f2C:10;
    u16 f2C_a:1;
    u16 f2C_b:1;
    u16 f2C_c:1;
    u16 f2C_d:1;
    u16 f2C_e:2;
    u8 e0:1;
    u8 e1:1;
    u8 e2:6;
    u8 pad2F;
} __attribute__((aligned(16))) E;
typedef struct { s32 *x0; u8 pad[0x1C]; } G;
typedef struct { u8 b[0x14]; } Fr;
typedef struct {
    u8 pad0[6];
    u8 n;
    u8 pad7[3];
    u16 fl;
    u8 v[6][0x10];
    u8 w[5][8];
    u8 pad94[4];
    Fr base[1];
} A_Fx_EvalTrack_1_00162490;
extern O *gSfxSystemSbss_00201FC0;
extern E *gSfxAllSbss_00201FD0;
extern G gSfxAllBss_0042D7E0;
extern Vec gMatrixFromData_001F2160;
extern Mtx gMatrixFromData_001F2170;
s32 Fx_SpawnParticle_1_00161060(s32 id0, s32 a1, O *par, M *m, A_Fx_SpawnParticle_1_00161060 *a, H *h, V *v);
void Fx_EvalTrack_1_00162490(s8 *dst, A_Fx_EvalTrack_1_00162490 *a, f32 t);
void sceVu0CopyVector(void *, void *);
void sceVu0AddVector(void *, void *, void *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyMatrix(void *, void *);
void sceVu0ApplyMatrix(void *, void *, void *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
u16 Rand_Next_3_0015ED20(void);
void Fx_RandomInSphere_0_00163A10(Vec *, f32, f32);
void Fx_GetWorldMatrix_1_00163C80(O *, Mtx *);
void Fx_GetWorldPos_1_00163D90(O *, Vec *);
void Mtx_AxisAngle_2_0015EBB0(Mtx *, Vec *, f32);
f32 powf(f32, f32);
s32 Mdl_CreateInstance_0_00174230(G *, s32, s32, s32);
void FxTable_CallC_0_0014D9A0(u16, O *);
void Fx_EvalCurveVec_1_001631E0(s8 *, f32, u8 *, Fr *, Fr *, f32, s32);
void Fx_EvalCurve_1_00163700(s8 *, f32, u8 *, Fr *, Fr *, f32, s32);

/* Fx_SpawnParticle_1_00161060 */
#define Fx_EvalTrack_1_00162490 Fx_EvalTrack_1_00162490__as_Fx_SpawnParticle_1_00161060
void Fx_EvalTrack_1_00162490__as_Fx_SpawnParticle_1_00161060(P80 *, F *, f32);
static inline f32 u2f(u32 x) { return x; }
static inline f32 radA(f32 x) { return x ? 0.01745f * x : 0.0f; }
static inline f32 radB(f32 x) { f32 r = 0.0f; if (x == r) { } else { r = 0.01745f * x; return r; } return r; }
#define BLK(RR, TV) { \
    P80 buf; \
    Vec v260; \
    Vec v250; \
    Vec v240; \
    Vec v230; \
    Vec v220; \
    Vec v210; \
    Vec v200; \
    Vec v1F0; \
    Vec v1E0; \
    Vec v1D0; \
    fp = m->x210[0]; \
    u = m->x174; \
    p = &buf; \
    if (fp->xA) { \
        buf = m->x190; \
        Fx_EvalTrack_1_00162490(p, fp, u); \
    } else { \
        p = &m->x190; \
    } \
    if (m->x189.f.b7) { \
        p = (P80 *)m->x150; \
        t = 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20(); \
        sceVu0ScaleVector(&v260, &p->r[1], p->r[1].w * t); \
        sceVu0AddVector(&v260, &v260, p); \
        Fx_RandomInSphere_0_00163A10(RR, p->r[0].w, 1.0f); \
        sceVu0AddVector(RR, RR, &v260); \
        RR->w = 1.0f; \
    } else { \
        switch (fp->x4) { \
        case 0: \
            Fx_RandomInSphere_0_00163A10(RR, p->x60, p->x68); \
            RR->x += p->x40.x; \
            RR->y += p->x40.y; \
            RR->z += p->x40.z; \
            break; \
        case 1: \
            TV = 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20(); \
            v250.x = p->x40.x + TV * (p->x50.x - p->x40.x); \
            v250.y = p->x40.y + TV * (p->x50.y - p->x40.y); \
            v250.z = p->x40.z + TV * (p->x50.z - p->x40.z); \
            Fx_RandomInSphere_0_00163A10(RR, p->x60 + TV * (p->x64 - p->x60), p->x68 + TV * (p->x6C - p->x68)); \
            sceVu0AddVector(RR, RR, &v250); \
            break; \
        case 2: \
            ra = -1.0f + 2.0f * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20()); \
            rb = -1.0f + 2.0f * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20()); \
            rc = -1.0f + 2.0f * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20()); \
            sceVu0CopyVector(&v230, &p->r[0]); \
            sceVu0CopyVector(&v220, &p->r[1]); \
            sceVu0CopyVector(&v210, &p->r[2]); \
            sceVu0CopyVector(&v200, &p->r[3]); \
            sceVu0CopyVector(&v240, &v200); \
            sceVu0ScaleVector(&v1F0, &v230, ra); \
            sceVu0AddVector(&v240, &v1F0, &v240); \
            sceVu0ScaleVector(&v1E0, &v220, rb); \
            sceVu0AddVector(&v240, &v1E0, &v240); \
            sceVu0ScaleVector(&v1D0, &v210, rc); \
            sceVu0AddVector(&v240, &v1D0, &v240); \
            Fx_RandomInSphere_0_00163A10(RR, p->x60, p->x68); \
            sceVu0AddVector(RR, RR, &v240); \
            break; \
        } \
        RR->w = 1.0f; \
    } \
    sceVu0AddVector(o, o, RR); \
}

s32 Fx_SpawnParticle_1_00161060(s32 id0, s32 a1, O *par, M *m, A_Fx_SpawnParticle_1_00161060 *a, H *h, V *v) {
    Vec r1;
    Mtx m3B0;
    Vec r2;
    Vec v390;
    Vec v380;
    Mtx m340;
    Vec v330;
    Mtx m2F0;
    O *o;
    s32 i;
    E *e;
    s32 ret;
    f32 s;
    f32 k;
    f32 w;
    f32 x;
    F *fp;
    P80 *p;
    f32 t;
    f32 u;
    f32 ra, rb, rc;
    u16 id;

    id = id0;
    o = &gSfxSystemSbss_00201FC0[id];
    if (a->type == 2 && gSfxAllBss_0042D7E0.x0[4] < 2) {
        return 0;
    }
    o->x20 = a->xC4;
    o->x24 = a->xC8;
    o->x28 = a->xCC;
    o->x2C = 0.0f;
    o->x30 = a->x84;
    o->x34 = a->x88;
    o->x38 = a->x8C;
    o->x3C = 0.0f;
    o->x3C = radA(a->x94);
    o->x40 = a->x9C;
    o->x44 = a->xA0;
    o->x48 = a->xA4;
    o->x4C = 0.0f;
    o->x4C = a->xAC;
    o->x50 = a->xD4;
    o->x54 = a->xD8;
    o->x58 = a->xDC;
    o->x5C = 0.0f;
    o->x60 = a->xE4;
    o->x64 = a->xEC;
    o->x68 = a->xF4;
    o->x6C = a->xFC;
    o->x70 = a->x74;
    o->x74 = a->x78;
    o->x78 = a->x7C;
    o->x7C = 0.0f;
    o->x80 = a->xB4;
    o->x84 = a->xBC;
    o->x88 = a->x44;
    o->x96[0] = 0;
    o->x96[1] = 0;
    o->x96[2] = 0;
    o->x96[3] = 0;
    o->x96[4] = 0;
    o->x96[5] = 0;
    o->x96[6] = 0;
    o->x96[7] = 0;
    o->b0 = 1;
    o->b1 = 1;
    o->b2 = 0;
    o->b3 = 0;
    o->b4 = m->x210[a1]->x44 == 0.0f;
    o->b5 = a->x7.f.b4;
    o->b6 = a->x7.f.b5;
    o->b7 = a->x7.f.b6;
    o->x8C = 0;
    o->x94 = a1;
    o->x90 = m;
    o->x9E = id0;
    o->xA0 = par ? par->x9E : 0xFFFF;
    o->x110 = -1;
    if (o->b5) {
        sceVu0CopyVector(o, v);
        if (par == 0) {
            if (o->b7) {
                sceVu0AddVector(o, o, &gMatrixFromData_001F2160);
            } else {
                BLK((&r1), ra)
            }
        }
        o->x0.w = 1.0f;
        sceVu0CopyMatrix(&o->xC0, &gMatrixFromData_001F2170);
    } else {
        if (par) {
            Fx_GetWorldMatrix_1_00163C80(par, &m3B0);
            v->x0.w = 1.0f;
            sceVu0ApplyMatrix(o, &m3B0, v);
            Fx_GetWorldMatrix_1_00163C80(par, &o->xC0);
        } else {
            sceVu0CopyVector(o, v);
            if (!o->b7) {
                BLK((&r2), x)
            }
            o->x0.w = 1.0f;
            sceVu0ApplyMatrix(o, m, o);
            sceVu0CopyMatrix(&o->xC0, m);
        }
        sceVu0CopyVector(&o->xC0.m[3], &gMatrixFromData_001F2160);
    }
    o->x88 = v->x24;
    w = v->x28;
    k = v->x10.w;
    v330.x = 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20() - 0.5f;
    v330.y = 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20() - 0.5f;
    v330.z = 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20() - 0.5f;
    v330.w = 0.0f;
    sceVu0Normalize(&v330, &v330);
    sceVu0OuterProduct(&v330, &v330, &v->x10);
    s = 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20();
    if (1.0f != w && !(s <= 0.01f)) {
        s = powf(s, w);
    }
    s *= radB(k);
    Mtx_AxisAngle_2_0015EBB0(&m340, &v330, s);
    sceVu0ApplyMatrix(&o->x10, &m340, &v->x10);
    o->x10.w = 0.0f;
    sceVu0ApplyMatrix(&o->x10, &o->xC0, &o->x10);
    if (par && !o->b5) {
        Fx_GetWorldPos_1_00163D90(par, &v390);
        sceVu0ScaleVector(&v380, &v390, 0.01f * v->x2C);
        sceVu0AddVector(&o->x10, &v380, &o->x10);
    }
    if (a->type == 1) {
        o->xA4 = radA(o->x38);
        x = 0.0f;
        if (x < o->x34) {
            x = radA(o->x34);
            o->xA4 = o->xA4 + x * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20());
        }
    } else {
        o->xA4 = 0.0f;
    }
    if (a->x8) {
        FxTable_CallC_0_0014D9A0(a->x8, o);
    }
    if (o->b5) {
        Fx_GetWorldMatrix_1_00163C80(o, &m2F0);
        sceVu0CopyVector(&o->x100, &m2F0.m[3]);
    } else {
        sceVu0CopyVector(&o->x100, o);
    }
    if (a->type == 2) {
        ret = Mdl_CreateInstance_0_00174230(&gSfxAllBss_0042D7E0, h->x10, -1, -1);
        gFxSpawnSbss_00201FDC++;
        for (i = 0; i < 2; i++) {
            e = &((E (*)[2])gSfxAllSbss_00201FD0)[id][i];
            e->x0 = o->x0.x;
            e->x4 = o->x0.y;
            e->x8 = o->x0.z;
            e->x18 = 0;
            e->x14 = 0;
            e->x10 = 0;
            e->x20 = o->x70;
            e->x22 = o->x74;
            e->x24 = o->x78;
            e->x28 = o->x40;
            e->x29 = o->x44;
            e->x2A = o->x48;
            e->x2B = o->x4C * m->x210[0]->x8C;
            e->f2C_a = 1;
            e->e0 = 1;
            e->xC = ret;
            e->f2C &= ~0x20;
        }
    } else {
        for (i = 0; i < 2; i++) {
            e = &((E (*)[2])gSfxAllSbss_00201FD0)[id][i];
            *(Q3 *)e = h->x20;
            if (i != gSfxAllSbss_00201F2C) {
                e->e1 = 1;
                e->f2C_b = 0;
            } else {
                e->e1 = 0;
                e->f2C_b = 1;
                Fx_UpdateEmitter_0_00160370(o, e, 0.0f);
            }
            e->e0 = 0;
        }
    }
    if (a->x7.f.b2) {
        Attack_TriggerSfxEvent_0_001D21E0(o, 2);
    }
    return 1;
}
#undef Fx_EvalTrack_1_00162490

/* Fx_EvalTrack_1_00162490 */
void Fx_EvalTrack_1_00162490(s8 *dst, A_Fx_EvalTrack_1_00162490 *a, f32 t) {
    Fr *base;
    Fr *fr;
    u16 fl;

    base = a->base;
    fl = a->fl;
    fr = &base[a->n];
    if (fl & 0x1) {
        Fx_EvalCurveVec_1_001631E0(dst, t, a->v[0], base, fr, 0.0f, 0);
    }
    if (fl & 0x2) {
        Fx_EvalCurveVec_1_001631E0(dst + 0x10, t, a->v[1], base, fr, 0.0f, 0);
    }
    if (fl & 0x4) {
        Fx_EvalCurveVec_1_001631E0(dst + 0x20, t, a->v[2], base, fr, 0.0f, 0);
    }
    if (fl & 0x8) {
        Fx_EvalCurveVec_1_001631E0(dst + 0x30, t, a->v[3], base, fr, 0.0f, 0);
    }
    if (fl & 0x10) {
        Fx_EvalCurveVec_1_001631E0(dst + 0x40, t, a->v[4], base, fr, 0.0f, 0);
    }
    if (fl & 0x20) {
        Fx_EvalCurveVec_1_001631E0(dst + 0x50, t, a->v[5], base, fr, 0.0f, 0);
    }
    if (fl & 0x40) {
        Fx_EvalCurve_1_00163700(dst + 0x60, t, a->w[0], base, fr, 0.0f, 0);
    }
    if (fl & 0x80) {
        Fx_EvalCurve_1_00163700(dst + 0x64, t, a->w[1], base, fr, 0.0f, 0);
    }
    if (fl & 0x100) {
        Fx_EvalCurve_1_00163700(dst + 0x68, t, a->w[2], base, fr, 0.0f, 0);
    }
    if (fl & 0x200) {
        Fx_EvalCurve_1_00163700(dst + 0x6C, t, a->w[3], base, fr, 0.0f, 0);
    }
    if (fl & 0x400) {
        Fx_EvalCurve_1_00163700(dst + 0x70, t, a->w[4], base, fr, 0.0f, 0);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gFxSpawnSbss_00201FDC */
u16 gFxSpawnSbss_00201FDC;
#endif
