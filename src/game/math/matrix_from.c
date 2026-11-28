#include "common.h"
typedef struct { f32 m[3][4]; f32 t[4]; } X;
extern s8 D_001F2130[];
extern s8 D_001F2140[];
extern s8 D_001F2160[];
extern s8 D_001F2170[];
extern f32 D_001F2150[];
extern f32 D_001F2154[];
extern f32 D_001F2158[];
void Mtx_FromTransform_0_00145FB0(X *out, X *in);
void Mtx_LookDir_1_00146020(Mtx *m, f32 x, f32 y, f32 z);
void Mtx_RotateToward_0_00146140(s32 arg0, f32 x, f32 z);
void sceVu0CopyVector(void *, void *);
void Mtx_AxisAngle_2_0015EBB0(f32 (*m)[4], f32 *axis, f32 a);
void sceVu0MulMatrix(f32 (*m0)[4], f32 (*m1)[4], f32 (*m2)[4]);
void sceVu0CopyMatrix(Mtx *, void *);
void sceVu0Normalize(Vec *, Vec *);
f32 fabsf(f32);
void sceVu0OuterProduct(Vec *, void *, Vec *);
void sceVu0SubVector(Vec *, Vec *, void *);
f32 atan2f(f32, f32);
f32 asinf(f32);
void sceVu0RotMatrixY(s32, void *, f32);

/* Mtx_FromTransform_0_00145FB0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Mtx_FromTransform_0_00145FB0
void sceVu0CopyVector__as_Mtx_FromTransform_0_00145FB0(f32 *v0, f32 *v1);

void Mtx_FromTransform_0_00145FB0(X *out, X *in)
{
    f32 m[4][4];
    f32 t[4];
    sceVu0CopyVector(t, in->t);
    Mtx_AxisAngle_2_0015EBB0(m, in->m[1], 3.1415927f);
    sceVu0MulMatrix((f32 (*)[4])out, m, (f32 (*)[4])in);
    sceVu0CopyVector(out->t, t);
}
#undef sceVu0CopyVector

/* Mtx_LookDir_1_00146020 */
void Mtx_LookDir_1_00146020(Mtx *m, f32 x, f32 y, f32 z) {
    Vec u;
    Vec s;
    Vec d;

    if (x == 0.0f && y == 0.0f && z == 0.0f) {
        sceVu0CopyMatrix(m, D_001F2170);
        return;
    }
    d.x = x;
    d.y = y;
    d.z = z;
    *(s32 *)&d.w = 0;
    sceVu0Normalize(&d, &d);
    if (0.9999f < fabsf(d.y)) {
        sceVu0CopyVector(&u, D_001F2130);
    } else {
        sceVu0OuterProduct(&u, D_001F2140, &d);
    }
    sceVu0Normalize(&u, &u);
    sceVu0OuterProduct(&s, &d, &u);
    sceVu0CopyVector(&m->m[0], &u);
    sceVu0CopyVector(&m->m[1], &s);
    sceVu0CopyVector(&m->m[2], &d);
    sceVu0CopyVector(&m->m[3], D_001F2160);
}

/* Mtx_RotateToward_0_00146140 */
void Mtx_RotateToward_0_00146140(s32 arg0, f32 x, f32 z) {
    volatile f32 d2;
    Vec v;
    Vec r;
    f32 a;
    f32 b;
    f32 d;
    f32 e;

    v.x = x;
    v.w = 1.0f;
    v.z = z;
    v.y = 0.0f;
    sceVu0SubVector(&r, &v, D_001F2160);
    sceVu0Normalize(&r, &r);
    a = atan2f(D_001F2150[0], D_001F2158[0]);
    asinf(D_001F2154[0]);
    b = atan2f(r.x, r.z);
    asinf(r.y);
    d = b - a;
    d = d - 6.2831855f * (s32)(d / 6.2831855f);
    if (d > 3.1415927f) {
        d -= 6.2831855f;
    } else if (d < -3.1415927f) {
        d += 6.2831855f;
    }
    d2 = d;
    e = 3.1415927f + d;
    sceVu0RotMatrixY(arg0, D_001F2170, (e - 6.2831855f * (s32)(0.15915494f * e)) + (e < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
void ScrCmd_GetArg0_2_00164CC0(void);
void ScrCmd_GetVar_1_00164CE0(void);
void ScrCmd_NopB_2_00164EC0(void);
void ScrCmd_NopC_2_00164ED0(void);
void ScrCmd_NopD_2_00164EF0(void);
void ScrCmd_NopE_2_00164F00(void);
void ScrCmd_Nop_2_00164CD0(void);
void ScrCmd_ResetAllSlots_0_00164E80(void);
void ScrCmd_SendEvent_1_00164EE0(void);
void ScrCmd_SetVar_1_00164DC0(void);
/* data group (src/game/data/screen_fx_flash_data.c): D_001F2100__grp: D_001F2100@0x0, D_001F210C@0xc, D_001F2110@0x10, D_001F2114@0x14, D_001F2118@0x18, D_001F211C@0x1c, D_001F2120@0x20, D_001F2130@0x30, D_001F2140@0x40, D_001F2150@0x50, D_001F2154@0x54, D_001F2158@0x58, D_001F2160@0x60, D_001F2170@0x70, D_001F21B0@0xb0 */
s32 D_001F2100__grp[0x80] __attribute__((aligned(16))) = { 0x3f800000, 0, 0, 0x43000000, 0x3f800000, 0, 0x3f800000, 0, 0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopD_2_00164EF0, (s32)ScrCmd_NopD_2_00164EF0, (s32)ScrCmd_NopC_2_00164ED0, (s32)ScrCmd_NopB_2_00164EC0, (s32)ScrCmd_ResetAllSlots_0_00164E80, (s32)ScrCmd_SendEvent_1_00164EE0, (s32)ScrCmd_NopD_2_00164EF0, (s32)ScrCmd_SetVar_1_00164DC0, (s32)ScrCmd_GetVar_1_00164CE0, (s32)ScrCmd_Nop_2_00164CD0, (s32)ScrCmd_GetArg0_2_00164CC0, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00 };
#endif
