#include "common.h"
#include "game/math.h"
#include "m2c.h"
#include "game/data.h"
typedef struct { f32 a[4]; f32 b[4]; } Ray;
typedef struct { s32 w[16]; } Res;
typedef struct { u8 pad[0x18]; u16 x18; u8 pad1A[0x16]; } E30;
typedef struct { u8 pad[0xC]; u16 xC; u16 xE; u8 pad10[2]; Flags8 f12; Flags8 f13; u8 pad14[0x2C]; } E40;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 f52; u8 pad53[0x2D]; } E80;
typedef struct { u8 pad[0x138]; E30 *x138; u8 pad13C[0x34]; E40 *x170; u8 pad174[0xC]; E80 *x180; } S;
typedef struct { u8 pad[0x18]; Vec *o; } P;
extern MtxF gMatrixFromData_001F2170;
s32 MapObj_CheckFacing_0_001B9610(S *a, s32 idx);
s32 MapObj_IsActorNear_0_001B9E00(s32 arg0, s32 arg1, f32 r);
u8* Mdl_GetFrameData_0_001715B0(s32);
P* Player_GetBodyState_1_001C9B60(void);
void Player_GetPos_1_001C9410(void *);
void sceVu0SubVector(f32 *, f32 *, void *);
f32 sceVu0InnerProduct(f32 *, f32 *);
void sceVu0CopyMatrix(MtxF *, void *);
void sceVu0CopyVector(void *, void *);
void sceVu0InversMatrix(MtxF *, MtxF *);
void sceVu0ApplyMatrix(f32 *, MtxF *, f32 *);
f32 atan2f(f32, f32);
f32 fabsf(f32);
void sceVu0ScaleVector(f32 *, f32 *, f32);
void sceVu0RotMatrixX(MtxF *, MtxF *, f32);
void sceVu0RotMatrixZ(MtxF *, MtxF *, f32);
void sceVu0RotMatrixY(MtxF *, MtxF *, f32);
void sceVu0AddVector(f32 *, void *, f32 *);
void memset(void *, s32, s32);
s32 MapColl_CapsuleCast_1_001B2800(S *, Res *, Ray *, u16, s32, s32);
f32 sqrtf(f32);
f32 Vec_DistSqXZ_2_0015DEB0(void *, s32);
f32 Vec_DistSq_3_0015DF20(void *, s32);
u16* ActorList_NextB_0_001A5710(void);
u16* ActorList_NextTargetable_0_001A5660(void);
void Enemy_CopyPosition_2_00140470(u16 *, void *);

/* MapObj_CheckFacing_0_001B9610 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define Player_GetPos_1_001C9410 Player_GetPos_1_001C9410__as_MapObj_CheckFacing_0_001B9610
void Player_GetPos_1_001C9410__as_MapObj_CheckFacing_0_001B9610(f32 *);
static inline f32 u2f(u32 x) { return x; }

s32 MapObj_CheckFacing_0_001B9610(S *a, s32 idx) {
    f32 v140[4];
    f32 v130[4];
    f32 v120[4];
    MtxF m;
    Res res;
    Ray ray;
    E80 *s5;
    E40 *s4;
    u8 *s2;
    P *p;
    f32 d;

    s5 = &a->x180[idx];
    s4 = &a->x170[*(u16 *)((u8 *)a->x138 + idx * 0x30 + 0x18)];
    s2 = Mdl_GetFrameData_0_001715B0(s5->x40);
    p = Player_GetBodyState_1_001C9B60();
    if (p == 0) return 0;
    if (!s5->f52.f.b3) return 0;
    if (s5->x50 & 3) return 0;
    Player_GetPos_1_001C9410(v140);
    sceVu0SubVector(v120, v140, s2 + 0x230);
    if (!s4->f13.f.b3) v120[1] = 0.0f;
    d = sqrtf(sceVu0InnerProduct(v120, v120));
    if (!(d <= u2f(s4->xE))) return 0;
    sceVu0CopyMatrix(&m, s2 + 0x200);
    sceVu0CopyVector(m.m[3], &gZeroVec_003139A0);
    m.m[3][3] = 1.0f;
    sceVu0InversMatrix(&m, &m);
    sceVu0ApplyMatrix(v130, &m, v120);
    d = fabsf(atan2f(-v130[0], -v130[2]));
    if (!(d <= 3.1415927f * u2f(s4->xC) / 180.0f)) return 0;
    if (!s4->f12.f.b6) {
        sceVu0ScaleVector(v120, v120, -1.0f);
        d = atan2f(-v120[0], -v120[2]) - WRAP(p->o[2].y);
        if (fabsf(WRAP(d)) <= 0.5235988f) return 1;
    } else {
        sceVu0RotMatrixX(&m, &gMatrixFromData_001F2170, WRAP(WRAP(p->o[2].x)));
        sceVu0RotMatrixZ(&m, &m, WRAP(WRAP(p->o[2].z)));
        sceVu0RotMatrixY(&m, &m, WRAP(WRAP(3.1415927f + p->o[2].y)));
        v130[0] = 0.0f;
        v130[1] = 0.0f;
        v130[2] = u2f(s4->xE);
        v130[3] = 1.0f;
        sceVu0ApplyMatrix(v130, &m, v130);
        sceVu0CopyVector(ray.a, p->o);
        sceVu0AddVector(ray.b, p->o, v130);
        memset(&res, 0, 0x40);
        if (MapColl_CapsuleCast_1_001B2800(a, &res, &ray, idx, 6, 1)) return 1;
    }
    return 0;
}
#undef Player_GetPos_1_001C9410

/* MapObj_IsActorNear_0_001B9E00 */
s32 MapObj_IsActorNear_0_001B9E00(s32 arg0, s32 arg1, f32 r) {
    f32 sp40[4];
    u16 *p;

    r = r * r;
    Player_GetPos_1_001C9410(sp40);
    if (arg1 != 0) {
        if (Vec_DistSq_3_0015DF20(sp40, arg0) <= r) return 1;
    } else {
        if (Vec_DistSqXZ_2_0015DEB0(sp40, arg0) <= r) return 1;
    }
    p = ActorList_NextB_0_001A5710();
    if (p != NULL) {
        do {
            if (*p != 0) {
                Enemy_CopyPosition_2_00140470(p, sp40);
                if (arg1 != 0) {
                    if (Vec_DistSq_3_0015DF20(sp40, arg0) <= r) return 1;
                } else {
                    if (Vec_DistSqXZ_2_0015DEB0(sp40, arg0) <= r) return 1;
                }
            }
            p = ActorList_NextTargetable_0_001A5660();
        } while (p != NULL);
    }
    return 0;
}
