#include "m2c.h"
#include "game/effect.h"
#include "common.h"
#include "game/math.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 rest:5; } Bits;
typedef struct {
    u16 m0;
    u8 pad2[2];
    u8 m4;
    u8 pad5[2];
    Bits f7;
    u8 pad8[0x20];
    u16 m28;
    u8 pad2A[2];
    u8 m2C[8];
    u8 m34[0x10];
    f32 m44;
    u8 pad48[4];
    u8 m4C[0x10];
    u8 m5C[8];
    u8 m64[8];
    u8 m6C[0x9C];
    u8 tbl[1];
} Src;
typedef struct { u16 prev; u16 next; u16 sib; } N;
typedef struct { u8 pad[0x114]; u8 b0:1; u8 b1:1; u8 b2:1; u8 pad115[0xB]; } O;
typedef struct { u8 pad[0x14]; u8 c0:1; u8 c1:1; u8 c2:1; u8 c3:1; u8 c4:1; u8 pad15[0x2F]; f32 f44; } A;
typedef struct { u8 pad[8]; u16 x8; u16 xA; } H;
typedef struct { f32 t; f32 v[3]; } Key_Fx_EvalCurveVec_1_001631E0;
typedef struct { f32 v[3]; u16 xC; u8 xE; u8 xF; } Hdr_Fx_EvalCurveVec_1_001631E0;
typedef Bits8 B8;
typedef struct { u8 x0; B8 f; u8 pad[2]; f32 x4; f32 x8; f32 xC; f32 x10; } Mod;
typedef struct { f32 x, y, z; s32 w; } Out;
typedef struct { f32 t; f32 v; } Key_Fx_EvalCurve_1_00163700;
typedef struct { f32 x0; u16 x4; u8 x6; u8 x7; } Hdr_Fx_EvalCurve_1_00163700;
extern O *gSfxSystemSbss_00201FC0;
extern N *gSfxSystemSbss_00201FD4;
extern u16 gSfxSystemSbss_00201FD8;
extern u32 gGameMainSbss_00201E94;
void Fx_EvalTrackB_1_00162CE0(s8 *a0, Src *a1, f32 f);
s32 Fx_SpawnBurst_1_00162F30(s32 p0, s32 n, s32 p2, A *a, s32 p4, H *h, s32 p6);
void Fx_EvalCurveVec_1_001631E0(Out *out, Hdr_Fx_EvalCurveVec_1_001631E0 *h, Mod *mods, s32 *keys, s32 loop, f32 t, f32 len);
void Fx_EvalCurve_1_00163700(f32 *out, Hdr_Fx_EvalCurve_1_00163700 *h, Mod *mods, s32 *keys, s32 loop, f32 t, f32 len);
s32 Fx_SpawnParticle_1_00161060(u16, s32, s32, s32, A *, H *, s32);
f32 fabsf(f32);
u16 Rand_Next_3_0015ED20(void);

/* Fx_EvalTrackB_1_00162CE0 */
#define Fx_EvalCurve_1_00163700 Fx_EvalCurve_1_00163700__as_Fx_EvalTrackB_1_00162CE0
void Fx_EvalCurve_1_00163700__as_Fx_EvalTrackB_1_00162CE0(f32, void *, void *, void *, void *, s32, f32);
#define Fx_EvalCurveVec_1_001631E0 Fx_EvalCurveVec_1_001631E0__as_Fx_EvalTrackB_1_00162CE0
void Fx_EvalCurveVec_1_001631E0__as_Fx_EvalTrackB_1_00162CE0(f32, void *, void *, void *, void *, s32, f32);

void Fx_EvalTrackB_1_00162CE0(s8 *a0, Src *a1, f32 f) {
    s8 *base;
    s8 *p;
    s32 flag;
    f32 t;

    base = (s8 *)a1->tbl;
    p = base + a1->m4 * 0x14;
    p = a1->f7.b1 ? p + 0x40 : p;
    p = a1->f7.b2 ? p + 0xA0 : p;
    flag = (0.0f < a1->m44) ^ 1;
    t = 0.033333335f * (u32)a1->m0;
    if (a1->m28 & 1) {
        Fx_EvalCurve_1_00163700(f, a0 + 0x20, a1->m2C, base, p, flag, t);
    }
    if (a1->m28 & 2) {
        Fx_EvalCurveVec_1_001631E0(f, a0, a1->m34, base, p, flag, t);
        *(f32 *)(a0 + 0xC) = 1.0f;
    }
    if (a1->m28 & 4) {
        Fx_EvalCurve_1_00163700(f, a0 + 0x24, &a1->m44, base, p, flag, t);
    }
    if (a1->m28 & 8) {
        Fx_EvalCurveVec_1_001631E0(f, a0 + 0x10, a1->m4C, base, p, flag, t);
    }
    if (a1->m28 & 0x10) {
        Fx_EvalCurve_1_00163700(f, a0 + 0xC, a1->m5C, base, p, flag, t);
    }
    if (a1->m28 & 0x20) {
        Fx_EvalCurve_1_00163700(f, a0 + 0x28, a1->m64, base, p, flag, t);
    }
    if (a1->m28 & 0x40) {
        Fx_EvalCurve_1_00163700(f, a0 + 0x2C, a1->m6C, base, p, flag, t);
    }
}
#undef Fx_EvalCurve_1_00163700
#undef Fx_EvalCurveVec_1_001631E0

/* Fx_SpawnBurst_1_00162F30 */
s32 Fx_SpawnBurst_1_00162F30(s32 p0, s32 n, s32 p2, A *a, s32 p4, H *h, s32 p6) {
    u16 prev = 0xFFFF;
    s32 m = n;
    s32 rest = 0;
    u16 k;
    s32 o;
    u16 id;
    u16 nx;
    if (n == 0) return 0;
    if (a->f44 == 0.0f && 0 < h->xA) return 0;
    if (gSfxSystemSbss_00201FD8 < n) {
        rest = n - gSfxSystemSbss_00201FD8;
        n = gSfxSystemSbss_00201FD8;
    }
    if (Sfx_GetFreeSlots_1_0016B230() < n) {
        rest += n - Sfx_GetFreeSlots_1_0016B230();
        m = Sfx_GetFreeSlots_1_0016B230();
    }
    k = h->x8;
    while (k != 0xFFFF) {
        if (gSfxSystemSbss_00201FC0[k].b2) {
            o = (u16)k * sizeof(N);
            nx = ((N *)((u8 *)gSfxSystemSbss_00201FD4 + o))->sib;
            if (prev != 0xFFFF) {
                gSfxSystemSbss_00201FD4[prev].sib = nx;
            } else {
                h->x8 = nx;
            }
            ((N *)((u8 *)gSfxSystemSbss_00201FD4 + o))->sib = 0xFFFF;
            k = nx;
        } else {
            prev = k;
            k = gSfxSystemSbss_00201FD4[k].sib;
        }
    }
    while (m != 0) {
        id = Sfx_ListAlloc_0_0016B0F0(h->x8, a->c4);
        if (id == 0xFFFF) {
            rest = m;
            break;
        }
        if (Fx_SpawnParticle_1_00161060(id, p6, p0, p2, a, h, p4) == 0) {
            Sfx_ListInsert_0_0016AF40(h->x8, id, a->c4);
            rest = m;
            break;
        }
        h->x8 = id;
        h->xA++;
        gSfxSystemSbss_00201FC0[id].b0 = 1;
        m--;
    }
    return rest;
}

/* Fx_EvalCurveVec_1_001631E0 */
static inline f32 u2f_Fx_EvalCurveVec_1_001631E0(u32 x) { return x; }
static inline void interp_Fx_EvalCurveVec_1_001631E0(Out *out, Hdr_Fx_EvalCurveVec_1_001631E0 *h, s32 *keys, f32 *pt, s32 loop, f32 len) {
    s32 n = h->xE;
    Key_Fx_EvalCurveVec_1_001631E0 *lo = (Key_Fx_EvalCurveVec_1_001631E0 *)&keys[h->xC];
    Key_Fx_EvalCurveVec_1_001631E0 *hi = lo + n - 1;
    Key_Fx_EvalCurveVec_1_001631E0 *prev;
    f32 t;
    if (loop) {
        while (len < *pt) {
            *pt -= len;
        }
    }
    t = *pt;
    if (n == 0) {
        out->x = h->v[0];
        out->y = h->v[1];
        out->z = h->v[2];
        out->w = 0;
    } else {
        if (t < lo->t) {
            hi = lo;
        } else if (hi->t < t) {
            lo = hi;
        } else {
            do {
                prev = lo;
                lo++;
                if (t < lo->t) {
                    hi = lo;
                    lo = prev;
                    break;
                }
            } while (lo != hi);
        }
        if (lo->t == hi->t) {
            out->x = lo->v[0];
            out->y = lo->v[1];
            out->z = lo->v[2];
        } else {
            f32 r = (t - lo->t) / (hi->t - lo->t);
            out->x = lo->v[0] + r * (hi->v[0] - lo->v[0]);
            out->y = lo->v[1] + r * (hi->v[1] - lo->v[1]);
            out->z = lo->v[2] + r * (hi->v[2] - lo->v[2]);
        }
    }
}

void Fx_EvalCurveVec_1_001631E0(Out *out, Hdr_Fx_EvalCurveVec_1_001631E0 *h, Mod *mods, s32 *keys, s32 loop, f32 t, f32 len) {
    Noise p;
    f32 res[4];
    s32 idx;
    Mod *m;
    u8 b;

    interp_Fx_EvalCurveVec_1_001631E0(out, h, keys, &t, loop, len);
    idx = h->xF & 0xF;
    if (idx != 0xF) {
        m = &mods[idx];
        b = m->f.b3 ? (u8)Rand_Next_3_0015ED20() : m->x0;
        p.f4 = m->f.b0;
        p.f5 = 0;
        p.w1 = 0.0f;
        p.w2 = 0.0f;
        p.scale = m->x4;
        p.amp = m->x8;
        p.f1C = m->xC;
        p.base = m->x10;
        if (m->f.b1) {
            p.idx[0] = b;
            p.idx[1] = b + 1;
            p.idx[2] = b + 2;
            if (m->f.b2) {
                Noise_Eval_1_0015ED80(&p, 3, res, t + 0.033333335f * u2f_Fx_EvalCurveVec_1_001631E0(gGameMainSbss_00201E94), 0.0f, 1000000.0f);
            } else {
                Noise_Eval_1_0015ED80(&p, 3, res, t, 0.0f, 1000000.0f);
            }
            if (m->f.b4) {
                res[0] = fabsf(res[0]);
            }
            if (m->f.b5) {
                out->x *= res[0];
                out->y *= res[1];
                out->z *= res[2];
            }
            if (m->f.b6) {
                out->x += res[0];
                out->y += res[1];
                out->z += res[2];
            }
        } else {
            p.idx[0] = b;
            if (m->f.b2) {
                Noise_Eval_1_0015ED80(&p, 1, res, t + 0.033333335f * u2f_Fx_EvalCurveVec_1_001631E0(gGameMainSbss_00201E94), 0.0f, 1000000.0f);
            } else {
                Noise_Eval_1_0015ED80(&p, 1, res, t, 0.0f, 1000000.0f);
            }
            if (m->f.b4) {
                res[0] = fabsf(res[0]);
                res[1] = fabsf(res[0]);
                res[2] = fabsf(res[0]);
            }
            if (m->f.b5) {
                out->x *= res[0];
                out->y *= res[0];
                out->z *= res[0];
            }
            if (m->f.b6) {
                out->x += res[0];
                out->y += res[0];
                out->z += res[0];
            }
        }
    }
}

/* Fx_EvalCurve_1_00163700 */
static inline f32 u2f_Fx_EvalCurve_1_00163700(u32 x) { return x; }
static inline void interp_Fx_EvalCurve_1_00163700(f32 *out, Hdr_Fx_EvalCurve_1_00163700 *h, s32 *keys, f32 *pt, s32 loop, f32 len) {
    s32 n = h->x6;
    Key_Fx_EvalCurve_1_00163700 *lo = (Key_Fx_EvalCurve_1_00163700 *)&keys[h->x4];
    Key_Fx_EvalCurve_1_00163700 *hi = lo + n - 1;
    Key_Fx_EvalCurve_1_00163700 *prev;
    f32 t;
    if (loop) {
        while (len < *pt) {
            *pt -= len;
        }
    }
    t = *pt;
    if (n == 0) {
        *out = h->x0;
    } else {
        if (t < lo->t) {
            hi = lo;
        } else if (hi->t < t) {
            lo = hi;
        } else {
            do {
                prev = lo;
                lo++;
                if (t < lo->t) {
                    hi = lo;
                    lo = prev;
                    break;
                }
            } while (lo != hi);
        }
        if (lo->t == hi->t) {
            *out = lo->v;
        } else {
            f32 r = (t - lo->t) / (hi->t - lo->t);
            *out = lo->v + r * (hi->v - lo->v);
        }
    }
}

void Fx_EvalCurve_1_00163700(f32 *out, Hdr_Fx_EvalCurve_1_00163700 *h, Mod *mods, s32 *keys, s32 loop, f32 t, f32 len) {
    f32 res;
    Noise p;
    Key_Fx_EvalCurve_1_00163700 *lo;
    Key_Fx_EvalCurve_1_00163700 *hi;
    Key_Fx_EvalCurve_1_00163700 *prev;
    s32 n;
    s32 idx;
    Mod *m;
    u8 b;

    interp_Fx_EvalCurve_1_00163700(out, h, keys, &t, loop, len);
    idx = h->x7 & 0xF;
    if (idx != 0xF) {
        m = &mods[idx];
        b = m->x0;
        if (m->f.b1) {
            p.idx[0] = b;
            p.idx[1] = b + 1;
            p.idx[2] = b + 2;
            p.idx[3] = b + 3;
        } else {
            p.idx[0] = b;
            p.idx[1] = b;
            p.idx[2] = b;
            p.idx[3] = b;
        }
        p.f4 = m->f.b0;
        p.f5 = 0;
        p.w1 = 0.0f;
        p.w2 = 0.0f;
        p.scale = m->x4;
        p.amp = m->x8;
        p.f1C = m->xC;
        p.base = m->x10;
        if (m->f.b2) {
            Noise_Eval_1_0015ED80(&p, 1, &res, t + 0.033333335f * u2f_Fx_EvalCurve_1_00163700(gGameMainSbss_00201E94), 0.0f, 1000000.0f);
        } else {
            Noise_Eval_1_0015ED80(&p, 1, &res, t, 0.0f, 1000000.0f);
        }
        if (m->f.b4) {
            res = fabsf(res);
        }
        if (m->f.b5) {
            *out *= res;
        }
        if (m->f.b6) {
            *out += res;
        }
    }
}
