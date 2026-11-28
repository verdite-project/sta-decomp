#include "common.h"
#include "m2c.h"
#include "game/effect.h"
typedef struct { Vec p; Vec v; u8 pad[0x90]; f32 fB0; f32 fB4; f32 fB8; f32 fBC; Mtx m; } O_FxProc_OrientToVelocity_0_00148120;
typedef struct { Vec r1; Vec r2; } Ax;
typedef struct {
    u8 pad0[0x10];
    Vec v;
    u8 pad20[0x30];
    f32 x50[3];
    u8 pad5C[4];
    f32 x60[3];
    f32 x6C;
    u8 pad70[0x40];
    f32 xB0[3];
    u8 padBC[4];
    u8 xC0[0x20];
    Vec xE0;
} O_FxProc_RandomSpin_0_001484D0;
typedef struct { u8 p : 5; u8 v : 1; } BF_FxProc_FollowEnemy_0_001489B0;
typedef struct { u8 a:2; u8 f:1; u8 r:5; } BF_FxProc_SpawnRandomChild_0_00148B30;
typedef struct {
    u8 pad0[0x60];
    f32 f60, f64, f68;
    u8 pad6c[0x8C - 0x6C];
    f32 f8c;
    s8 * volatile p90;
    u16 i94;
    u8 pad96[0xB0 - 0x96];
    f32 fb0, fb4;
} Obj;
extern Mtx gMatrixFromData_001F2170;
extern Vec gMatrixFromData_001F2140;
extern f32 gMatrixFromData_001F2160[];
void FxProc_OrientToVelocity_0_00148120(O_FxProc_OrientToVelocity_0_00148120 *o, f32 dt);
void FxProc_RandomSpin_0_001484D0(O_FxProc_RandomSpin_0_001484D0 *o);
void FxProc_FollowEnemy_0_001489B0(s8 *a0);
void FxProc_SpawnRandomChild_0_00148B30(Obj *arg0);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(void *, void *, void *);
f32 fabsf(f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixZ(Mtx *, Mtx *, f32);
void sceVu0MulMatrix(Mtx *, Mtx *, Mtx *);
f32 sqrtf(f32);
u16 Rand_Next_3_0015ED20(void);
s8* ActorList_Next_2_001A5460(s32 *);
u32 Enemy_GetCurrentParamIdx_0_0013E110(s8 *);
void sceVu0SubVector(f32 *, f32 *, f32 *);
void sceVu0CopyVector(f32 *, f32 *);
void Fx_GetWorldMatrix_1_00163C80(void *, void *);
void Mtx_LookDir_1_00146020(s8 *, f32, f32, f32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetMatrixOrAim_0_00167740(s8 *, u8 *);

/* FxProc_OrientToVelocity_0_00148120 */
Vec D_001F2000 = { 0.0f, 980.0f };
#define sceVu0AddVector sceVu0AddVector__as_FxProc_OrientToVelocity_0_00148120
void sceVu0AddVector__as_FxProc_OrientToVelocity_0_00148120(Vec *, Vec *, Vec *);

#define WRAP(a) (((3.1415927f + (a)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (a)))) + ((3.1415927f + (a)) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f)

void FxProc_OrientToVelocity_0_00148120(O_FxProc_OrientToVelocity_0_00148120 *o, f32 dt) {
    Vec A;
    Vec D;
    Vec C;
    Vec B;
    Vec E;
    Mtx M;
    f32 spd;
    f32 rx;
    f32 d;
    f32 l;
    f32 s;
    f32 ry;
    f32 kB0;
    f32 rz;
    f32 a;
    f32 t;
    f32 y;
    f32 kE;
    f32 kD;

    spd = sqrtf(sceVu0InnerProduct(&o->v, &o->v));
    kE = 0.0125663718f * *(volatile f32 *)&o->fB8;
    kD = 18.849556f * *(volatile f32 *)&o->fB4;
    kB0 = o->fB0;
    sceVu0Normalize(&A, &o->v);
    B = D_001F2000;
    sceVu0ScaleVector(&C, &B, dt);
    l = spd + sqrtf(sceVu0InnerProduct(&C, &C));
    d = sceVu0InnerProduct(&A, &o->m.m[1]);
    s = (0.0f < d) ? 1.0f : -1.0f;
    sceVu0ScaleVector(&D, &o->m.m[1], -1.0f * s * (kB0 * (l * fabsf(d))));
    l = spd + sqrtf(sceVu0InnerProduct(&C, &C));
    d = sceVu0InnerProduct(&A, &o->m.m[2]);
    s = (0.0f < d) ? 1.0f : -1.0f;
    ry = s * (l * kE);
    d = sceVu0InnerProduct(&gMatrixFromData_001F2140, &o->m.m[1]);
    s = (0.0f < d) ? -1.0f : 1.0f;
    rz = s * (kD * fabsf(d));
    sceVu0AddVector(&o->v, &o->v, &C);
    sceVu0AddVector(&o->v, &o->v, &D);
    sceVu0ScaleVector(&E, &o->v, dt);
    sceVu0AddVector(&o->p, &E, &o->p);
    rx = 0.0f;
    a = rx * dt;
    sceVu0RotMatrixY(&M, &gMatrixFromData_001F2170, WRAP(a));
    sceVu0MulMatrix(&o->m, &o->m, &M);
    y = ry + rz;
    sceVu0RotMatrixX(&M, &gMatrixFromData_001F2170, WRAP(y * dt));
    sceVu0MulMatrix(&o->m, &o->m, &M);
    sceVu0RotMatrixZ(&M, &gMatrixFromData_001F2170, WRAP(a));
    sceVu0MulMatrix(&o->m, &o->m, &M);
}
#undef sceVu0AddVector

/* FxProc_RandomSpin_0_001484D0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_FxProc_RandomSpin_0_001484D0
void sceVu0RotMatrixY__as_FxProc_RandomSpin_0_001484D0(f32, Mtx *, Mtx *);
#define sceVu0RotMatrixX sceVu0RotMatrixX__as_FxProc_RandomSpin_0_001484D0
void sceVu0RotMatrixX__as_FxProc_RandomSpin_0_001484D0(f32, Mtx *, Mtx *);
#define RND() (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20)())

void FxProc_RandomSpin_0_001484D0(O_FxProc_RandomSpin_0_001484D0 *o) {
    f32 a;
    f32 b;

    a = o->x50[0];
    b = o->x60[0];
    o->xB0[0] = b + b * (-a + (a + a) * RND());
    a = o->x50[1];
    b = o->x60[1];
    o->xB0[1] = b + b * (-a + (a + a) * RND());
    a = o->x50[2];
    b = o->x60[2];
    o->xB0[2] = b + b * (-a + (a + a) * RND());
    if (o->x6C == 1.0f) {
        sceVu0RotMatrixX(WRAP(6.2831855f * RND()), (Mtx *)o->xC0, &gMatrixFromData_001F2170);
        sceVu0RotMatrixY(WRAP(6.2831855f * RND()), (Mtx *)o->xC0, (Mtx *)o->xC0);
        sceVu0ScaleVector(&o->v, &o->xE0, sqrtf(sceVu0InnerProduct(&o->v, &o->v)));
    }
}
#undef sceVu0RotMatrixY
#undef sceVu0RotMatrixX

/* FxProc_FollowEnemy_0_001489B0 */
#define sceVu0AddVector sceVu0AddVector__as_FxProc_FollowEnemy_0_001489B0
void sceVu0AddVector__as_FxProc_FollowEnemy_0_001489B0(f32 *, f32 *, f32 *);
#define Fx_GetWorldMatrix_1_00163C80 Fx_GetWorldMatrix_1_00163C80__as_FxProc_FollowEnemy_0_001489B0
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_FollowEnemy_0_001489B0(s8 *, f32 *);

void FxProc_FollowEnemy_0_001489B0(s8 *a0) {
    f32 c[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    s32 it;
    u16 id;
    s8 *p;

    it = 0;
    id = (u32)*(f32 *)(a0 + 0x60);
    do {
        p = ActorList_Next_2_001A5460(&it);
    } while (p != NULL && *(u16 *)p != id);
    if (p != NULL) {
        *(f32 *)(a0 + 0xB8) = Enemy_GetCurrentParamIdx_0_0013E110(p);
    } else {
        *(f32 *)(a0 + 0xB8) = 0.0f;
    }
    sceVu0AddVector(a, p != NULL ? (f32 *)(*(s32 *)(p + 0x518) + 0x90) : gMatrixFromData_001F2160, (f32 *)(a0 + 0x50));
    if (((BF_FxProc_FollowEnemy_0_001489B0 *)(a0 + 0x114))->v) {
        Fx_GetWorldMatrix_1_00163C80(a0, m);
        sceVu0CopyVector(b, m + 12);
    } else {
        sceVu0CopyVector(b, (f32 *)a0);
    }
    sceVu0SubVector(c, a, b);
    Mtx_LookDir_1_00146020(a0 + 0xC0, c[0], c[1], c[2]);
}
#undef sceVu0AddVector
#undef Fx_GetWorldMatrix_1_00163C80

/* FxProc_SpawnRandomChild_0_00148B30 */
#define Fx_GetWorldMatrix_1_00163C80 Fx_GetWorldMatrix_1_00163C80__as_FxProc_SpawnRandomChild_0_00148B30
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_SpawnRandomChild_0_00148B30(void *, u8 *);

void FxProc_SpawnRandomChild_0_00148B30(Obj *arg0) {
    u8 sp40[0x40];
    s32 var_s0;
    u16 *temp_s2;
    s32 id;
    s8 *p;

    var_s0 = 0;
    if (0.0f != arg0->f60 && ((BF_FxProc_SpawnRandomChild_0_00148B30 *)(arg0->p90 + 0x188))->f) {
        if (0.0f == arg0->f8c) {
            if (arg0->f64) {
                temp_s2 = ((u16 **)(arg0->p90 + 0x210))[arg0->i94];
                { f32 a = arg0->f64 * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()); arg0->fb0 = 0.033333335f * (a * (f32)(u32)*temp_s2); }
                arg0->fb4 = 0.0f;
            } else {
                var_s0 = 1;
            }
        }
        if (arg0->f64 && !arg0->fb4 && arg0->fb0 < arg0->f8c) {
            var_s0 = 1;
            arg0->fb4 = 1.0f;
        }
        if (var_s0 != 0) {
            id = arg0->f68;
            if (Sfx_IsLoaded_2_00169BB0(id) != 0) {
                p = Sfx_Spawn_2_00169B50(id, 0, 0, 0);
                Fx_GetWorldMatrix_1_00163C80(arg0, sp40);
                Sfx_SetMatrixOrAim_0_00167740(p, sp40);
            }
        }
    }
}
#undef Fx_GetWorldMatrix_1_00163C80
