#include "common.h"
#include "actor.h"
#include "m2c.h"
#include "game/effect.h"
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 pad[0x170]; s32 *x170; } S90;
typedef struct {
    Vec p;
    u8 pad10[0x50];
    f32 x60;
    u8 pad64[0x2C];
    S90 *x90;
    u16 x94;
    u8 pad96[0x2A];
    MtxF xC0;
} O_Proj_AttachToBone_0_00147510;
typedef struct { u8 p[0xA8]; s32 xA8; } S;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } Bits;
typedef struct { u8 pad[0x138]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } R;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5C[4];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[4];
    f32 x74;
    u8 pad78[0x10];
    f32 x88;
    u8 pad8C[4];
    S90 *x90;
    u16 x94;
    u8 pad96[0x12];
    s8 *xA8;
    u8 padAC[4];
    f32 xB0;
    f32 xB4;
    u8 padB8[8];
    MtxF xC0;
    u8 pad100[0x14];
    Bits f114;
} O_Proj_UpdateHoming_0_00147710;
typedef struct { u8 pad0[0x170]; u8 **x170; } H;
typedef struct {
    u8 pad0[0x54];
    f32 x54;
    u8 pad58[4];
    f32 x5C;
    u8 pad60[4];
    f32 x64;
    u8 pad68[0x20];
    f32 x88;
    u8 pad8C[4];
    H *x90;
    u8 pad94[0x14];
    s32 xA8;
    u8 padAC[4];
    f32 xB0;
    f32 xB4;
    u8 padB8[0x5C];
    u8 b0:1;
    u8 b1:1;
} O_Proj_Update_0_00147E90;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; } F;
typedef union { u128 q[4]; f32 f[16]; } T;
extern Vec gMatrixFromData_001F2160;
extern MtxF gMatrixFromData_001F2170;
s8* Proj_FindBestTarget_0_001472A0(Vec *a0, Vec *a1, f32 best_, f32 ang, f32 k_);
s8* Proj_FindNearestEnemy_0_00147450(void *pos, f32 d);
void Proj_AttachToBone_0_00147510(O_Proj_AttachToBone_0_00147510 *o);
void Proj_AttachToBoneB_0_001475F0(s8 *o);
void Proj_ReleaseEffect_0_001476D0(S *a);
void Proj_UpdateHoming_0_00147710(O_Proj_UpdateHoming_0_00147710 *o, f32 dt);
void Proj_Update_0_00147E90(O_Proj_Update_0_00147E90 *o);
s8* ActorList_Next_2_001A5460(s32 *);
s32 Enemy_IsBusy_0_0013EE40(s8 *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 fabsf(f32);
f32 sqrtf(f32);
void sceVu0CopyVector(void *, void *);
void sceVu0ApplyMatrix(void *, void*, void*);
s32 Actor_GetBoneWorldMatrix_0_001464A0(s32, u8, void *);
void Sfx_RequestStop_1_00167240(s32);
R* Actor_GetBone_0_001468F0(s32, u32);
void Mtx_FromTransform_0_00145FB0(void *, void *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void Vec_GetYawPitchBetween_1_00146310(O_Proj_UpdateHoming_0_00147710 *, Vec *, void *, f32 *, f32 *);
f32 atan2f(f32, f32);
void sceVu0RotMatrixX(MtxF *, MtxF *, f32);
void sceVu0RotMatrixY(MtxF *, MtxF *, f32);
void sceVu0CopyMatrix(void *, void *);
void sceVu0ScaleVector(Vec *, void *, f32);
s32 Map_LineTest_1_001470F0(O_Proj_UpdateHoming_0_00147710 *, Vec *, s32, s32, s32, Vec *);
s32 Proj_FindTarget_0_00146C70(O_Proj_UpdateHoming_0_00147710 *, Vec *, Actor *, s32 *, Vec *, f32);
void Proj_SpawnAttack_0_00146A70(S90 *, Actor *, u8, s32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetTransform_1_001677C0(s8 *, void *);
void Sfx_SetPosition_1_00167710(s8 *, Vec *);

/* Proj_FindBestTarget_0_001472A0 */
static inline Vec *pos(s8 *o) { return o ? (Vec *)(*(s8 **)(o + 0x518) + 0x90) : &gMatrixFromData_001F2160; }

s8 *Proj_FindBestTarget_0_001472A0(Vec *a0, Vec *a1, f32 best_, f32 ang, f32 k_) {
    s32 it;
    Vec d;
    s8 *cur;
    s8 *bestObj;
    f32 kk;
    f32 bb;
    f32 dist;
    f32 dp;
    f32 h;
    kk = k_;
    bb = best_;
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    bestObj = NULL;
    if (cur != NULL) {
        h = 0.5f * ang;
        do {
            if (*(u16 *)cur != 0 && !Enemy_IsBusy_0_0013EE40(cur)) {
                sceVu0SubVector(&d, pos(cur), a0);
                d.z = 0.0f;
                d.w = 1.0f;
                dist = sqrtf(sceVu0InnerProduct(&d, &d));
                sceVu0Normalize(&d, &d);
                dp = sceVu0InnerProduct(a1, &d);
                if (!(h < fabsf(dp))) {
                    dist = dist * ((3.1415927f - kk * fabsf(dp)) / 3.1415927f);
                    if (dist < bb) {
                        bb = dist;
                        bestObj = cur;
                    }
                }
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
    return bestObj;
}

/* Proj_FindNearestEnemy_0_00147450 */
s8 *Proj_FindNearestEnemy_0_00147450(void *pos, f32 d) {
    s32 it;
    s8 *e;
    s8 *r;
    f32 t;
    it = 0;
    e = ActorList_Next_2_001A5460(&it);
    r = NULL;
    while (e != NULL) {
        if (*(u16 *)e != 0 && Enemy_IsBusy_0_0013EE40(e) == 0) {
            t = Vec_Distance_3_00146940(e ? (void *)(*(s8 **)(e + 0x518) + 0x90) : (void *)&gMatrixFromData_001F2160, pos);
            if (t < d) { d = t; r = e; }
        }
        e = ActorList_Next_2_001A5460(&it);
    }
    return r;
}

/* Proj_AttachToBone_0_00147510 */
#define Actor_GetBoneWorldMatrix_0_001464A0 Actor_GetBoneWorldMatrix_0_001464A0__as_Proj_AttachToBone_0_00147510
s32 Actor_GetBoneWorldMatrix_0_001464A0__as_Proj_AttachToBone_0_00147510(s32, u8, MtxF *);
static inline s32 cur_Proj_AttachToBone_0_00147510(O_Proj_AttachToBone_0_00147510 *o) { s32 *p = o->x90->x170; return p ? *p : 0; }

void Proj_AttachToBone_0_00147510(O_Proj_AttachToBone_0_00147510 *o) {
    Vec v;
    s32 c;
    u8 f = o->x60;
    c = cur_Proj_AttachToBone_0_00147510(o);
    if (c && Actor_GetBoneWorldMatrix_0_001464A0(c, f, &o->xC0)) {
        sceVu0CopyVector(&v, (u8 *)o->x90 + o->x94 * 128 + 0x2C0);
        v.w = 1.0f;
        sceVu0ApplyMatrix(o, &o->xC0, &v);
        sceVu0CopyVector(o->xC0.m[3], &gMatrixFromData_001F2160);
    }
}
#undef Actor_GetBoneWorldMatrix_0_001464A0

/* Proj_AttachToBoneB_0_001475F0 */
void Proj_AttachToBoneB_0_001475F0(s8 *o) {
    Vec v;
    u8 b;
    s32 *p;
    s32 q;
    b = (u32)*(f32 *)(o + 0x60);
    p = *(s32 **)(*(s8 **)(o + 0x90) + 0x170);
    q = p ? *p : 0;
    if (q && Actor_GetBoneWorldMatrix_0_001464A0(q, b, o + 0xC0)) {
        sceVu0CopyVector(&v, *(s8 **)(o + 0x90) + *(u16 *)(o + 0x94) * 0x80 + 0x2C0);
        v.w = 1.0f;
        sceVu0ApplyMatrix(o, o + 0xC0, &v);
        sceVu0CopyVector(o + 0xF0, &gMatrixFromData_001F2160);
    }
}

/* Proj_ReleaseEffect_0_001476D0 */
void Proj_ReleaseEffect_0_001476D0(S *a) {
 volatile s32 t; s32 x; t = a->xA8; x = t; if (x != 0) { Sfx_RequestStop_1_00167240(x); a->xA8 = 0; }
}

/* Proj_UpdateHoming_0_00147710 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define Mtx_FromTransform_0_00145FB0 Mtx_FromTransform_0_00145FB0__as_Proj_UpdateHoming_0_00147710
void Mtx_FromTransform_0_00145FB0__as_Proj_UpdateHoming_0_00147710(Vec *, R *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Proj_UpdateHoming_0_00147710
void sceVu0ApplyMatrix__as_Proj_UpdateHoming_0_00147710(Vec *, void *, void *);
static inline s32 cur_Proj_UpdateHoming_0_00147710(O_Proj_UpdateHoming_0_00147710 *o) { s32 *p = o->x90->x170; return p ? *p : 0; }
static inline s32 e10(u16 t) { return t == 0x10; }
static inline s32 e1031(u16 t) { return t == 0x10 || t == 0x31; }
static inline s32 chk(O_Proj_UpdateHoming_0_00147710 *o) {
    s32 s;
    R *r;
    u16 a;
    u16 t;
    s32 n1, n2, n3;
    s = cur_Proj_UpdateHoming_0_00147710(o);
    if (s == 0) return 0;
    r = Actor_GetBone_0_001468F0(s, (u32)o->x54);
    if (r == 0 || r->b6) return 0;
    a = *(u16 *)s;
    t = *(u16 *)(s + 0x6D0);
    n1 = 0; if (a == 0x2F && !e10(t) != 0) n1 = 1;
    n2 = 0; if (a == 0x43 && !e1031(t) != 0) n2 = 1;
    n1 += n2;
    n3 = 0; if (a == 0x6C && !e10(t) != 0) n3 = 1;
    n1 += n3;
    return !(n1 != 0);
}

void Proj_UpdateHoming_0_00147710(O_Proj_UpdateHoming_0_00147710 *o, f32 dt) {
    f32 ang;
    f32 f;
    volatile f32 at;
    s32 idx;
    volatile s32 t1;
    volatile s32 t2;
    Vec v110;
    MtxF m;
    Vec vC0;
    Vec vB0;
    Vec vA0;
    MtxF m60;
    s32 c;
    f32 k;
    f32 lim;
    Actor *s0;
    s8 *e;
    s32 id;
    s8 *s3;

    if (!chk(o)) {
        o->x88 = o->f114.b1 = 0;
        return;
    }
    Mtx_FromTransform_0_00145FB0((Vec *)&o->xC0, Actor_GetBone_0_001468F0(cur_Proj_UpdateHoming_0_00147710(o), (u32)o->x54));
    sceVu0CopyVector(o, &o->xC0.m[3]);
    sceVu0CopyVector(&o->xC0.m[3], &gMatrixFromData_001F2160);
    sceVu0ApplyMatrix(&v110, &o->xC0, (u8 *)o->x90 + o->x94 * 128 + 0x2C0);
    sceVu0AddVector(&o->p, &o->p, &v110);
    o->p.w = 1.0f;
    c = 0;
    if (gPlayerSbss_002022E4 != 0 && gPlayerSbss_002022E4->unk518 != 0) c = 1;
    Vec_GetYawPitchBetween_1_00146310(o, (Vec *)&o->xC0.m[2], c ? (void *)(gPlayerSbss_002022E4->unk518 + 0x1C0) : (void *)&gMatrixFromData_001F2160, &ang, 0);
    at = atan2f(o->xC0.m[2][0], o->xC0.m[2][2]);
    ang += at;
    if (3.1415927f < fabsf(ang - o->xB4)) {
        if (ang < o->xB4) k = 6.2831855f;
        else k = -6.2831855f;
        ang += k;
    }
    ang -= o->xB4;
    lim = dt * (o->x50 ? 0.0174499992f * o->x50 : 0.0f);
    if (lim < fabsf(ang)) {
        ang = lim * (f32)(ang < 0.0f ? -1 : 1);
    }
    o->xB4 = ang = ang + o->xB4;
    o->xB0 += o->x60 * dt;
    f = atan2f(o->xB0, 190.0f);
    sceVu0RotMatrixX(&m, &gMatrixFromData_001F2170, WRAP(f));
    sceVu0RotMatrixY(&m, &m, WRAP(ang));
    sceVu0CopyMatrix(&o->xC0, &m);
    sceVu0ScaleVector(&vB0, &o->xC0.m[1], 10000.0f);
    sceVu0AddVector(&vB0, &vB0, &o->p);
    if (Map_LineTest_1_001470F0(o, &vB0, 3, 6, 0, &vC0)) f = Vec_Distance_3_00146940(o, &vC0);
    else f = -1.0f;
    sceVu0ScaleVector(&vA0, &o->xC0.m[1], f);
    sceVu0AddVector(&vA0, &vA0, &o->p);
    s0 = gPlayerSbss_002022E4;
    if (Proj_FindTarget_0_00146C70(o, &vA0, s0, &idx, 0, o->x58)) {
        Proj_SpawnAttack_0_00146A70(o->x90, s0, idx, 0x2B);
        o->x88 = o->f114.b1 = 0;
        id = (s32)o->x6C;
        if (id != 0) {
            e = Sfx_Spawn_2_00169B50(id, 0, 1, 0);
            if (e != 0) {
            s3 = (s8 *)s0->unk51C + idx * 0x170;
            sceVu0CopyMatrix(&m60, &gMatrixFromData_001F2170);
            sceVu0CopyVector(m60.m[3], s3 + 0xA0);
            Sfx_SetTransform_1_001677C0(e, s0 ? (void *)(s0->unk518 + 0x60) : (void *)&gMatrixFromData_001F2170);
            }
        }
    }
    if (o->xA8 == 0) {
        t1 = (s32)Sfx_Spawn_2_00169B50((s32)o->x68, 0, 0, 0);
        o->xA8 = (s8 *)t1;
    }
    if (o->xA8 != 0) {
        t2 = (s32)o->xA8;
        Sfx_SetPosition_1_00167710((s8 *)t2, &vC0);
    }
    o->x74 = Vec_Distance_3_00146940(&vC0, o);
}
#undef Mtx_FromTransform_0_00145FB0
#undef sceVu0ApplyMatrix

/* Proj_Update_0_00147E90 */
#define Mtx_FromTransform_0_00145FB0 Mtx_FromTransform_0_00145FB0__as_Proj_Update_0_00147E90
void Mtx_FromTransform_0_00145FB0__as_Proj_Update_0_00147E90(T *, u8 *);
#define Actor_GetBone_0_001468F0 Actor_GetBone_0_001468F0__as_Proj_Update_0_00147E90
u8 *Actor_GetBone_0_001468F0__as_Proj_Update_0_00147E90(u8 *, u32);
#define Proj_UpdateHoming_0_00147710 Proj_UpdateHoming_0_00147710__as_Proj_Update_0_00147E90
void Proj_UpdateHoming_0_00147710__as_Proj_Update_0_00147E90(f32, O_Proj_Update_0_00147E90 *);

static inline u8 *target(O_Proj_Update_0_00147E90 *o) {
    u8 **p = o->x90->x170;
    return p != 0 ? *p : 0;
}

static inline s32 is10(u16 v) {
    return v == 0x10;
}

static inline s32 is10or31(u16 v) {
    return v == 0x10 || v == 0x31;
}

static inline s32 ok(O_Proj_Update_0_00147E90 *o) {
    u8 *s;
    u8 *e;
    u16 type;
    s32 a;
    s32 c;
    u16 sub;
    s32 b;

    s = target(o);
    if (s == 0) {
        return 0;
    }
    e = Actor_GetBone_0_001468F0(s, (u32)o->x54);
    if (e == 0 || ((F *)(e + 0x138))->b6) {
        return 0;
    }
    type = *(u16 *)s;
    sub = *(u16 *)(s + 0x6D0);
    a = 0;
    if (type == 0x2F && !is10(sub) != 0) {
        a = 1;
    }
    b = 0;
    if (type == 0x43 && !is10or31(sub) != 0) {
        b = 1;
    }
    a = a + b;
    c = 0;
    if (type == 0x6C) {
        if (!is10(sub) != 0) {
            c = 1;
        } else {
            c = c;
        }
    }
    return !(a + c);
}

void Proj_Update_0_00147E90(O_Proj_Update_0_00147E90 *o) {
    volatile f32 ang;
    T t;
    u8 *e;

    if (!ok(o)) {
        o->x88 = (f32)(u32)(o->b1 = 0);
        return;
    }
    e = Actor_GetBone_0_001468F0(target(o), (u32)o->x54);
    o->x5C = 1.0f;
    o->xB0 = o->x64;
    o->xA8 = 0;
    Mtx_FromTransform_0_00145FB0(&t, e);
    o->xB4 = ang = atan2f(t.f[8], t.f[10]);
    Proj_UpdateHoming_0_00147710(0.0f, o);
}
#undef Mtx_FromTransform_0_00145FB0
#undef Actor_GetBone_0_001468F0
#undef Proj_UpdateHoming_0_00147710
