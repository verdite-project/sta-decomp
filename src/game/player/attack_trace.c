#include "common.h"
#include "game/effect.h"
typedef union { u128 q[4]; f32 f[16]; s32 w[16]; } M;
typedef struct { Vec a; Vec b; } Ray;
typedef struct { Vec p; Vec d; } Seg;
typedef union { u128 q[4]; struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; } s; } Res;
typedef struct { f32 v[3]; } V3;
typedef struct { u8 pad[4]; u8 a, b, c; Flags8 f7; u8 pad8[0x108]; f32 t[1][5]; } E_Attack_TraceProjectile_0_001D22E0;
typedef struct { u8 pad[0x210]; E_Attack_TraceProjectile_0_001D22E0 *e[1]; } T_Attack_TraceProjectile_0_001D22E0;
typedef struct { u8 pad[0xC]; s32 xC; } C;
typedef struct { u8 pad[0xA]; u16 xA; u16 xC; u16 xE; } AI_Attack_TraceProjectile_0_001D22E0;
typedef struct { u8 pad[0x4B0]; AI_Attack_TraceProjectile_0_001D22E0 *x4B0; } A_Attack_TraceProjectile_0_001D22E0;
typedef struct { Vec v; u8 pad10[0x80]; T_Attack_TraceProjectile_0_001D22E0 *x90; u16 x94; u8 pad96[0x6A]; Vec x100; u8 pad110[4]; Flags8 x114; } O_Attack_TraceProjectile_0_001D22E0;
typedef struct { u8 pad[0x2C]; u8 kind:3; u8 k3:5; u8 b0:5; u8 en:1; u8 b6:2; } AI_Attack_TestActor_0_001D2890;
typedef struct { u16 x0; u8 pad2[0x7A]; s32 x7C; u8 pad80[0x434]; AI_Attack_TestActor_0_001D2890 *x4B4[0x1A]; s8 *x51C; } A_Attack_TestActor_0_001D2890;
typedef struct { u8 pad[0x90]; s32 x90; } O_Attack_TestActor_0_001D2890;
typedef struct { char pad[0x2AD]; unsigned int : 2; unsigned int f : 1; } Q;
typedef struct { u16 h; char pad[0x4AE]; Q *q; } Obj;
typedef struct { u8 pad[0xC]; union { s32 w; Flags8 f; } c; } Ent;
typedef struct { u8 pad[4]; u8 b4, b5, b6; } T_Attack_GetHitMask_0_001D2A80;
typedef struct { u8 pad[0x90]; T_Attack_GetHitMask_0_001D2A80 **x90; u16 x94; } O_Attack_GetHitMask_0_001D2A80;
typedef struct { u8 pad[0xC]; Flags8 c; Flags8 d; } S;
typedef struct { u8 pad[4]; u8 b4, b5, b6; } E_Attack_GetParams_0_001D2C60;
typedef struct { u8 pad[0x210]; E_Attack_GetParams_0_001D2C60 *x210[1]; } B;
typedef struct { u8 pad[0x90]; B *x90; u16 x94; } A_Attack_GetParams_0_001D2C60;
extern Vec gMatrixFromData_001F2140;
s32 Attack_TraceProjectile_0_001D22E0(O_Attack_TraceProjectile_0_001D22E0 *o);
s32 Attack_TestActor_0_001D2890(O_Attack_TestActor_0_001D2890 *o, A_Attack_TestActor_0_001D2890 *a, Ray *ray, Res *out);
u64 Attack_GetFlagB2_0_001D2A20(void *arg0);
s32 Attack_IsActive_0_001D2A40(Obj *o);
s32 Attack_IsNull_1_001D2A70(u16 *arg0);
u8 Attack_GetHitMask_0_001D2A80(O_Attack_GetHitMask_0_001D2A80 *o);
u8 Attack_GetCollFlags_0_001D2B80(S *a);
u8* Attack_GetParams_0_001D2C60(A_Attack_GetParams_0_001D2C60 *a);
void Fx_GetWorldMatrix_1_00163C80(O_Attack_TraceProjectile_0_001D22E0 *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);
void Seg_Init_1_001502A0(Ray *, Vec *, Vec *, f32);
s32 Map_RaycastCapsule_0_00145D10(Vec *, Vec *, u8, s32, M *);
s32 Map_RaycastNearest_0_00145840(Ray *, u8, s32, M *);
A_Attack_TraceProjectile_0_001D22E0* ActorList_NextB_0_001A5710(void);
A_Attack_TraceProjectile_0_001D22E0* ActorList_NextTargetable_0_001A5660(void);
s32 Actor_CanTarget_0_0013BA90(T_Attack_TraceProjectile_0_001D22E0 *, A_Attack_TraceProjectile_0_001D22E0 *);
s32 Enemy_IsBusy_0_0013EE40(A_Attack_TraceProjectile_0_001D22E0 *);
void Enemy_CopyPosition_2_00140470(A_Attack_TraceProjectile_0_001D22E0 *, Vec *);
void Seg_ClosestPoints_3_00151B20(Res*, Ray*, void *);
s32 Attack_Ricochet_0_001D31E0(O_Attack_TraceProjectile_0_001D22E0 *, M *);
s32 Attack_SpawnHitEffect_1_001D2CB0(O_Attack_TraceProjectile_0_001D22E0 *, A_Attack_TraceProjectile_0_001D22E0 *, u8, Res *, s32);
s32 Actor_IsFlag1Clear_1_0013BA70(s32, A_Attack_TestActor_0_001D2890 *, s8 *, AI_Attack_TestActor_0_001D2890 *);

/* Attack_TraceProjectile_0_001D22E0 */
#define Attack_GetParams_0_001D2C60 Attack_GetParams_0_001D2C60__as_Attack_TraceProjectile_0_001D22E0
C *Attack_GetParams_0_001D2C60__as_Attack_TraceProjectile_0_001D22E0(O_Attack_TraceProjectile_0_001D22E0 *);
#define Attack_GetCollFlags_0_001D2B80 Attack_GetCollFlags_0_001D2B80__as_Attack_TraceProjectile_0_001D22E0
u8 Attack_GetCollFlags_0_001D2B80__as_Attack_TraceProjectile_0_001D22E0(C *);
#define Attack_GetHitMask_0_001D2A80 Attack_GetHitMask_0_001D2A80__as_Attack_TraceProjectile_0_001D22E0
u8 Attack_GetHitMask_0_001D2A80__as_Attack_TraceProjectile_0_001D22E0(O_Attack_TraceProjectile_0_001D22E0 *);
#define Attack_IsNull_1_001D2A70 Attack_IsNull_1_001D2A70__as_Attack_TraceProjectile_0_001D22E0
s32 Attack_IsNull_1_001D2A70__as_Attack_TraceProjectile_0_001D22E0(A_Attack_TraceProjectile_0_001D22E0 *);
#define Attack_IsActive_0_001D2A40 Attack_IsActive_0_001D2A40__as_Attack_TraceProjectile_0_001D22E0
s32 Attack_IsActive_0_001D2A40__as_Attack_TraceProjectile_0_001D22E0(A_Attack_TraceProjectile_0_001D22E0 *);
#define Attack_GetFlagB2_0_001D2A20 Attack_GetFlagB2_0_001D2A20__as_Attack_TraceProjectile_0_001D22E0
s32 Attack_GetFlagB2_0_001D2A20__as_Attack_TraceProjectile_0_001D22E0(A_Attack_TraceProjectile_0_001D22E0 *);
#define Seg_ClosestPoints_3_00151B20 Seg_ClosestPoints_3_00151B20__as_Attack_TraceProjectile_0_001D22E0
void Seg_ClosestPoints_3_00151B20__as_Attack_TraceProjectile_0_001D22E0(Res *, Ray *, Seg *);
#define Attack_TestActor_0_001D2890 Attack_TestActor_0_001D2890__as_Attack_TraceProjectile_0_001D22E0
s32 Attack_TestActor_0_001D2890__as_Attack_TraceProjectile_0_001D22E0(O_Attack_TraceProjectile_0_001D22E0 *, A_Attack_TraceProjectile_0_001D22E0 *, Ray *, Res *);
static inline f32 u2f(u32 x) { return x; }
static inline E_Attack_TraceProjectile_0_001D22E0 *ent(T_Attack_TraceProjectile_0_001D22E0 **t, u16 *i) { return (*t)->e[*i]; }
static inline u8 mask(O_Attack_TraceProjectile_0_001D22E0 *o) {
    u8 m = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        C *c = Attack_GetParams_0_001D2C60(o) + i;
        if (c->xC) m |= Attack_GetCollFlags_0_001D2B80(c);
    }
    return m;
}

s32 Attack_TraceProjectile_0_001D22E0(O_Attack_TraceProjectile_0_001D22E0 *o) {
    s32 ret;
    Ray ray;
    M best;
    Vec pos;
    M h2;
    M h1;
    Res bres;
    Mtx m;
    Vec v160;
    Res res;
    Seg seg;
    Res r;
    E_Attack_TraceProjectile_0_001D22E0 *e;
    s32 i1;
    u8 m1;
    s32 r3;
    s32 i2;
    u16 *pi;
    T_Attack_TraceProjectile_0_001D22E0 **pt;
    u8 m2;
    s32 h;
    f32 min;
    s32 idx;
    u8 fl;
    A_Attack_TraceProjectile_0_001D22E0 *a;
    A_Attack_TraceProjectile_0_001D22E0 *ba;

    pi = &o->x94;
    pt = &o->x90;
    if (!ent(pt, pi)->f7.f.b1) return 0;
    ret = 0;
    if (o->x114.f.b5) {
        Fx_GetWorldMatrix_1_00163C80(o, &m);
        sceVu0CopyVector(&pos, &m.m[3]);
    } else {
        sceVu0CopyVector(&pos, &o->v);
    }
    e = ent(pt, pi);
    Seg_Init_1_001502A0(&ray, &o->x100, &pos, (e->t[e->a] + e->b)[e->c * 3]);
    m1 = 0;
    for (i1 = 0; i1 < 4; i1++) {
        C *c = Attack_GetParams_0_001D2C60(o) + i1;
        if (c->xC) m1 |= Attack_GetCollFlags_0_001D2B80(c);
    }
    r3 = Map_RaycastCapsule_0_00145D10(&o->x100, &pos, m1, 0, &h2);
    m2 = 0;
    for (i2 = 0; i2 < 4; i2++) {
        C *c = Attack_GetParams_0_001D2C60(o) + i2;
        if (c->xC) m2 |= Attack_GetCollFlags_0_001D2B80(c);
    }
    h = Map_RaycastNearest_0_00145840(&ray, m2, 0, &h1);
    if (h && r3) {
        min = Vec_Distance_3_00146940(&h1, &o->x100);
        best = *(min < Vec_Distance_3_00146940(&h2, &o->x100) ? &h1 : &h2);
    } else if (r3) {
        best = h2;
    } else if (h) {
        best = h1;
    } else {
        best.w[9] = 0;
    }
    min = 5.0f;
    idx = -1;
    fl = Attack_GetHitMask_0_001D2A80(o);
    ba = 0;
    for (a = ActorList_NextB_0_001A5710(); a; a = ActorList_NextTargetable_0_001A5660()) {
        if (Attack_IsNull_1_001D2A70(a) && !(fl & 1)) continue;
        if (Attack_IsActive_0_001D2A40(a) && !(fl & 2)) continue;
        if (Attack_GetFlagB2_0_001D2A20(a) && !(fl & 8)) continue;
        if (!Actor_CanTarget_0_0013BA90(o->x90, a)) continue;
        if (Enemy_IsBusy_0_0013EE40(a)) continue;
        Enemy_CopyPosition_2_00140470(a, &v160);
        sceVu0CopyVector(&seg.p, &v160);
        seg.p.y -= u2f(a->x4B0->xE);
        seg.p.w = u2f(a->x4B0->xA);
        sceVu0CopyVector(&seg.d, &gMatrixFromData_001F2140);
        seg.d.w = u2f(a->x4B0->xE);
        Seg_ClosestPoints_3_00151B20(&res, &ray, &seg);
        if (res.s.hit) {
            s32 k;
            r.s.hit = 0;
            k = Attack_TestActor_0_001D2890(o, a, &ray, &r);
            if (k != -1 && r.s.a.w < min) {
                idx = k;
                ba = a;
                min = r.s.a.w;
                bres = r;
            }
        }
    }
    if (idx != -1) {
        if (best.w[9] && best.f[3] < min) {
            if (Attack_Ricochet_0_001D31E0(o, &best)) ret = 1;
        } else {
            if (Attack_SpawnHitEffect_1_001D2CB0(o, ba, idx, &bres, 2)) ret = 1;
        }
    } else if (best.w[9]) {
        if (Attack_Ricochet_0_001D31E0(o, &best)) ret = 1;
    }
    return ret;
}
#undef Attack_GetParams_0_001D2C60
#undef Attack_GetCollFlags_0_001D2B80
#undef Attack_GetHitMask_0_001D2A80
#undef Attack_IsNull_1_001D2A70
#undef Attack_IsActive_0_001D2A40
#undef Attack_GetFlagB2_0_001D2A20
#undef Seg_ClosestPoints_3_00151B20
#undef Attack_TestActor_0_001D2890

/* Attack_TestActor_0_001D2890 */
#define Seg_ClosestPoints_3_00151B20 Seg_ClosestPoints_3_00151B20__as_Attack_TestActor_0_001D2890
void Seg_ClosestPoints_3_00151B20__as_Attack_TestActor_0_001D2890(Res *, Ray *, s8 *);

s32 Attack_TestActor_0_001D2890(O_Attack_TestActor_0_001D2890 *o, A_Attack_TestActor_0_001D2890 *a, Ray *ray, Res *out) {
    s32 ret;
    s32 i;
    f32 best;
    s8 *seg;
    AI_Attack_TestActor_0_001D2890 *ai;
    Res r;
    best = 5.0f;
    ret = -1;
    out->s.hit = 0;
    for (i = 0; i < a->x7C; i++) {
        seg = a->x51C + i * 0x170;
        ai = a->x4B4[i];
        if (!ai->en) continue;
        if (a->x0 != 0 && ai->kind == 1) continue;
        if (a->x0 != 0 && ai->kind == 2) continue;
        if (!Actor_IsFlag1Clear_1_0013BA70(o->x90, a, seg, ai)) continue;
        Seg_ClosestPoints_3_00151B20(&r, ray, seg);
        if (r.s.hit == 0) continue;
        if (r.s.a.w < best) {
            ret = i;
            best = r.s.a.w;
            *out = r;
        }
    }
    return ret;
}
#undef Seg_ClosestPoints_3_00151B20

/* Attack_GetFlagB2_0_001D2A20 */
u64 Attack_GetFlagB2_0_001D2A20(void *arg0) {
    return (u64) ((s64) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4B0), u8 *, 0x2AD) << 0x3D) >> 0x3F;
}

/* Attack_IsActive_0_001D2A40 */
s32 Attack_IsActive_0_001D2A40(Obj *o)
{
    return o->h != 0 && !o->q->f;
}

/* Attack_IsNull_1_001D2A70 */
s32 Attack_IsNull_1_001D2A70(u16 *arg0) {
    return *arg0 == 0;
}

/* Attack_GetHitMask_0_001D2A80 */
static inline u8 bits(Ent *e) {
    u8 m = 0;
    if (e->c.w == 0) {
        return 0;
    }
    if (e->c.f.f.b0) m |= 1;
    if (e->c.f.f.b1) m |= 2;
    if (e->c.f.f.b2) m |= 4;
    if (e->c.f.f.b3) m |= 8;
    return m;
}

u8 Attack_GetHitMask_0_001D2A80(O_Attack_GetHitMask_0_001D2A80 *o) {
    u8 r;
    s32 i;
    T_Attack_GetHitMask_0_001D2A80 *t;
    Ent *e;

    r = 0;
    t = o->x90[o->x94 + 0x84];
    { s32 a = t->b4 * 20; e = (Ent *)(t->b6 * 12 + (t->b5 * 4 + (a + (s32)t)) + 0x108); }
    for (i = 0; i < 4; i++) {
        r |= bits(&e[i]);
    }
    return r;
}

/* Attack_GetCollFlags_0_001D2B80 */
u8 Attack_GetCollFlags_0_001D2B80(S *a) {
    u8 r = 0;
    if (a->c.f.b4) r |= 2;
    if (a->c.f.b5) r |= 4;
    if (a->c.f.b6) r |= 8;
    if (a->c.f.b7) r |= 0x10;
    if (a->d.f.b0) r |= 0x20;
    if (a->d.f.b1) r |= 0x40;
    if (a->d.f.b2) r |= 0x80;
    return r;
}

/* Attack_GetParams_0_001D2C60 */
u8 *Attack_GetParams_0_001D2C60(A_Attack_GetParams_0_001D2C60 *a) {
    E_Attack_GetParams_0_001D2C60 *t = a->x90->x210[a->x94];
    s32 x = t->b4 * 0x14; return (u8 *)(t->b6 * 0xC + (t->b5 * 4 + (x + (s32)t)) + 0x108);
}
