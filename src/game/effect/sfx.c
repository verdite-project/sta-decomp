#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/data.h"
#include "game/effect.h"
typedef struct { char pad[0x188]; unsigned char a : 1; unsigned char : 2; unsigned char c : 1; unsigned char b : 1; } Obj_Sfx_Release_1_00167030;
typedef struct { u8 t : 3; u8 r : 5; } TB;
typedef struct { u8 pad[0x10]; TB f; } P_Sfx_Free_1_001670E0;
typedef struct { u8 pad[0x10]; s32 h; u8 pad2[0x80 - 0x14]; } Sub;
typedef Bits8 B8;
typedef struct { u16 lo : 7; u16 n : 8; u16 hi : 1; } H;
typedef struct {
    u8 pad[0x188];
    union { B8 b; H h; } f188;
    B8 f18A;
    u8 pad2[0x210 - 0x18B];
    P_Sfx_Free_1_001670E0 *arr[0x18];
    Sub sub[8];
} O_Sfx_Free_1_001670E0;
typedef struct {
    char pad[0x188];
    unsigned char : 3;
    unsigned char f : 1;
} Obj_Sfx_RequestStop_1_00167240;
typedef struct { s32 a, b; } P_Sfx_GetState_0_001672B0;
typedef struct { P_Sfx_GetState_0_001672B0 p[8]; } Q_Sfx_GetState_0_001672B0;
typedef struct { char pad[0x18A]; unsigned char : 1; unsigned char f : 1; char p[0xCF5]; Q_Sfx_GetState_0_001672B0 q; } Obj_Sfx_GetState_0_001672B0;
typedef struct { u8 pad[0x170]; s32 x170; u8 pad2[0xED0 - 0x174]; } E;
typedef struct { char pad[0x170]; s32 v; } Obj_Sfx_SetOwner_1_00167600;
typedef struct { char pad[0x188]; unsigned char : 2; unsigned char f : 1; } Obj_Sfx_SetFlag_0_00167640;
typedef struct { u128 a, b; } Q_Sfx_SetColor_0_00167670;
typedef struct { char pad[0x150]; Q_Sfx_SetColor_0_00167670 q; char p170[0x19]; unsigned char : 7; unsigned char f : 1; } Obj_Sfx_SetColor_0_00167670;
typedef struct { char p[0x94]; u8 b0 : 1; u8 b1 : 1; } I;
typedef struct { char p[0x30]; Vec t; char p2[0x1D0]; I *x210; } O_Sfx_SetMatrixOrAim_0_00167740;
typedef struct { char p[0x20]; f32 x20; f32 x24; f32 x28; char p2[4]; Vec t; } M;
typedef struct { u8 p:1; u8 v:1; } B_Sfx_SetTransform_1_001677C0;
typedef struct { f32 pad[8]; f32 x; f32 p1; f32 z; f32 p2; f32 v[4]; } S;
typedef struct { u8 pad[0x30]; f32 v[4]; u8 pad2[0x188-0x40]; u8 flags; u8 pad3[0xED0-0x189]; } A;
typedef struct { u8 m[0x100]; u8 m2[0x14]; u8 f0 : 1; u8 f1:1; u8 f2:1; u8 f3:1;u8 f4:1;u8 f5:1;u8 f6:1;u8 f7:1; u8 pad[0x120-0x115]; } B_Sfx_OffsetAll_1_00167850;
typedef struct { f32 x, y, z; u8 pad[0x30-12]; } C;
typedef struct { C c[2]; } CC;
extern char gSfxSystemBss_003407E0[];
extern s8 gMatrixFromData_001F2160[];
extern f32 gMatrixFromData_001F2170[];
extern B_Sfx_OffsetAll_1_00167850 *gSfxSystemSbss_00201FC0;
extern CC *gSfxAllSbss_00201FD0;
extern u8 gSfxBss_003406D0[];
s32 Sfx_Release_1_00167030(char *p);
void Sfx_Free_1_001670E0(O_Sfx_Free_1_001670E0 *o);
void Sfx_RequestStop_1_00167240(Obj_Sfx_RequestStop_1_00167240 *o);
f32 Sfx_GetParam180_1_00167260(void *arg0);
void Sfx_SetParam180_1_00167270(void *arg0, f32 fparg0);
f32 Sfx_GetParam17C_1_00167280(void *arg0);
void Sfx_SetParam17C_1_00167290(void *arg0, f32 fparg0);
s32 Sfx_GetDataPtr_0_001672A0(s32 arg0);
s32 Sfx_GetState_0_001672B0(Obj_Sfx_GetState_0_001672B0 *o, Q_Sfx_GetState_0_001672B0 *q);
inline s32 has(void);
inline s32 sgn(f32 v);
void Sfx_AimMatrix_0_00167310(void *m0, f32 mx, f32 my);
void Sfx_ReleaseOwned_0_00167580(void);
s32 Sfx_GetOwner_1_001675D0(void *arg0);
void Sfx_SetOwner_1_00167600(void *a, void *p);
void Sfx_SetFlag_0_00167640(Obj_Sfx_SetFlag_0_00167640 *o, int v);
void Sfx_SetColor_0_00167670(Obj_Sfx_SetColor_0_00167670 *o, Q_Sfx_SetColor_0_00167670 *q);
void Sfx_GetMatrix_1_001676E0(void *src, f32 (*dst)[4]);
void Sfx_SetPosition_1_00167710(s32 arg0);
void Sfx_SetMatrixOrAim_0_00167740(void *a, void *b);
void Sfx_SetTransform_1_001677C0(s8 *arg0);
void Tex_Release_1_00177570(s32);
void Vec_GetYawPitchBetween_1_00146310(f32 *, f32 *, s8 *, f32 *, f32 *);
f32 fabsf(f32);
void sceVu0RotMatrixX(f32 (*)[4], f32 *, f32);
void sceVu0RotMatrixY(f32 (*)[4], f32 (*)[4], f32);
void sceVu0CopyMatrix(f32 (*)[4], f32 *);
void sceVu0CopyVector(f32 *, f32 *);
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
s32 ActorList_FromHandle_1_001A5970(void);
void Mtx_RotateToward_0_00146140(void *, f32, f32);
void Mtx_FromTransform_0_00145FB0(S *);
void sceVu0AddVector(void *, void *, f32 *);

/* Sfx_Release_1_00167030 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
char D_0042C910[0xed0];
#define Sfx_Free_1_001670E0 Sfx_Free_1_001670E0__as_Sfx_Release_1_00167030
void Sfx_Free_1_001670E0__as_Sfx_Release_1_00167030(Obj_Sfx_Release_1_00167030 *o);

s32 Sfx_Release_1_00167030(char *p)
{
    Obj_Sfx_Release_1_00167030 *o = (Obj_Sfx_Release_1_00167030 *)p;
    if (p < gSfxSystemBss_003407E0 || p > D_0042C910)
        return 0;
    Sfx_Free_1_001670E0(o);
    o->a = 1;
    o->b = 1;
    o->c = 1;
    return 1;
}
#undef Sfx_Free_1_001670E0

/* Sfx_Free_1_001670E0 */
void Sfx_Free_1_001670E0(O_Sfx_Free_1_001670E0 *o) {
    u32 n;
    u32 i;
    Sub *s;

    if (o->f188.b.b0) {
        if (!o->f188.b.b4) {
            n = o->f188.h.n;
            for (i = 1; i < n; i++) {
                s = &o->sub[i];
                switch (o->arr[i]->f.t) {
                case 1:
                    if (s->h) {
                        Tex_Release_1_00177570(s->h);
                        s->h = 0;
                    }
                    break;
                case 2:
                    break;
                }
            }
        }
        o->f188.b.b0 = 0;
        o->f188.b.b1 = 0;
        o->f188.b.b3 = 0;
        o->f188.b.b4 = 0;
        o->f18A.b0 = 0;
    }
}

/* Sfx_RequestStop_1_00167240 */
/* Bitfield setter on an object's flag byte at 0x188. */


void Sfx_RequestStop_1_00167240(Obj_Sfx_RequestStop_1_00167240 *o)
{
    o->f = 1;
}

/* Sfx_GetParam180_1_00167260 */
f32 Sfx_GetParam180_1_00167260(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x180);
}

/* Sfx_SetParam180_1_00167270 */
void Sfx_SetParam180_1_00167270(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x180) = fparg0;
}

/* Sfx_GetParam17C_1_00167280 */
f32 Sfx_GetParam17C_1_00167280(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x17C);
}

/* Sfx_SetParam17C_1_00167290 */
void Sfx_SetParam17C_1_00167290(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x17C) = fparg0;
}

/* Sfx_GetDataPtr_0_001672A0 */
s32 Sfx_GetDataPtr_0_001672A0(s32 arg0) {
    return arg0 + 0xE80;
}

/* Sfx_GetState_0_001672B0 */
s32 Sfx_GetState_0_001672B0(Obj_Sfx_GetState_0_001672B0 *o, Q_Sfx_GetState_0_001672B0 *q)
{
    if (!o)
        return 0;
    o->q = *q;
    o->f = 1;
    return 1;
}

/* Sfx_AimMatrix_0_00167310 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

inline s32 has(void) {
    s32 r = 0;
    if (gPlayerSbss_002022E4 != NULL && gPlayerSbss_002022E4->unk518 != NULL) {
        r = 1;
    }
    return r;
}

inline s32 sgn(f32 v) {
    s32 s = 1;
    if (v < 0.0f) {
        s = -1;
    }
    return s;
}

void Sfx_AimMatrix_0_00167310(void *m0, f32 mx, f32 my) {
    f32 *m;
    f32 a;
    f32 b;
    f32 t[4][4] __attribute__((aligned(16)));
    f32 r[4][4] __attribute__((aligned(16)));
    f32 x;
    f32 y;
    s32 s;

    if (m0 != NULL) {
        m = m0;
        Vec_GetYawPitchBetween_1_00146310(m + 12, m + 8, has() ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160, &a, &b);
        x = a;
        x = fabsf(x) < mx ? x : mx * (f32)(x < 0.0f ? -1 : 1);
        y = b;
        y = fabsf(y) < my ? y : my * (f32)(y < 0.0f ? -1 : 1);
        sceVu0RotMatrixX(r, gMatrixFromData_001F2170, WRAP(y));
        sceVu0RotMatrixY(r, r, WRAP(x));
        sceVu0CopyMatrix(t, m);
        sceVu0CopyVector(t[3], (f32 *)gMatrixFromData_001F2160);
        sceVu0MulMatrix(t, t, r);
        sceVu0CopyVector(m, t[0]);
        sceVu0CopyVector(m + 4, t[1]);
        sceVu0CopyVector(m + 8, t[2]);
    }
}

/* Sfx_ReleaseOwned_0_00167580 */
#define gSfxSystemBss_003407E0 gSfxSystemBss_003407E0__as_Sfx_ReleaseOwned_0_00167580
extern E gSfxSystemBss_003407E0__as_Sfx_ReleaseOwned_0_00167580[];
void Sfx_ReleaseOwned_0_00167580(void) {
    s32 id = ActorList_FromHandle_1_001A5970();
    s32 i = 0;
    E *e = gSfxSystemBss_003407E0;
    do {
        if (e->x170 == id) {
            e->x170 = 0;
        }
        i++;
        e++;
    } while (i < 0x100);
}
#undef gSfxSystemBss_003407E0

/* Sfx_GetOwner_1_001675D0 */
s32 Sfx_GetOwner_1_001675D0(void *arg0) {
    s32 *temp_2;

    if (arg0 == NULL) {
        return 0;
    }
    temp_2 = M2C_FIELD(arg0, s32 **, 0x170);
    if (temp_2 != NULL) {
        return *temp_2;
    }
    return 0;
}

/* Sfx_SetOwner_1_00167600 */
#define ActorList_FromHandle_1_001A5970 ActorList_FromHandle_1_001A5970__as_Sfx_SetOwner_1_00167600
s32 ActorList_FromHandle_1_001A5970__as_Sfx_SetOwner_1_00167600(void *p);
void Sfx_SetOwner_1_00167600(void *a, void *p) { Obj_Sfx_SetOwner_1_00167600 *o = a; if (a && p) o->v = ActorList_FromHandle_1_001A5970(p); }
#undef ActorList_FromHandle_1_001A5970

/* Sfx_SetFlag_0_00167640 */
void Sfx_SetFlag_0_00167640(Obj_Sfx_SetFlag_0_00167640 *o, int v)
{
    if (o)
        o->f = v;
}

/* Sfx_SetColor_0_00167670 */
void Sfx_SetColor_0_00167670(Obj_Sfx_SetColor_0_00167670 *o, Q_Sfx_SetColor_0_00167670 *q)
{
    if (o) {
        if (q) {
            o->q = *q;
            o->f = 1;
            return;
        }
        {
            int v = 0;
            o->f = v;
        }
    }
}

/* Sfx_GetMatrix_1_001676E0 */
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Sfx_GetMatrix_1_001676E0
void sceVu0CopyMatrix__as_Sfx_GetMatrix_1_001676E0(f32 (*m0)[4], f32 (*m1)[4]);

void Sfx_GetMatrix_1_001676E0(void *src, f32 (*dst)[4])
{
    f32 (*m)[4] = src;
    if (src)
        sceVu0CopyMatrix(dst, m);
}
#undef sceVu0CopyMatrix

/* Sfx_SetPosition_1_00167710 */
#define sceVu0CopyVector sceVu0CopyVector__as_Sfx_SetPosition_1_00167710
void sceVu0CopyVector__as_Sfx_SetPosition_1_00167710(s32);

void Sfx_SetPosition_1_00167710(s32 arg0) {
    if (arg0 != 0) {
        sceVu0CopyVector(arg0 + 0x30);
    }
}
#undef sceVu0CopyVector

/* Sfx_SetMatrixOrAim_0_00167740 */
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Sfx_SetMatrixOrAim_0_00167740
void sceVu0CopyMatrix__as_Sfx_SetMatrixOrAim_0_00167740(void *, void *);
#define sceVu0CopyVector sceVu0CopyVector__as_Sfx_SetMatrixOrAim_0_00167740
void sceVu0CopyVector__as_Sfx_SetMatrixOrAim_0_00167740(Vec *, Vec *);
void Sfx_SetMatrixOrAim_0_00167740(void *a, void *b) {
M *arg1 = b; O_Sfx_SetMatrixOrAim_0_00167740 *arg0 = a; if (a != NULL) { if (arg0->x210->b1) { Mtx_RotateToward_0_00146140(arg0, arg1->x20, arg1->x28); sceVu0CopyVector(&arg0->t, &arg1->t); return; } sceVu0CopyMatrix(arg0, arg1); }
}
#undef sceVu0CopyMatrix
#undef sceVu0CopyVector

/* Sfx_SetTransform_1_001677C0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Sfx_SetTransform_1_001677C0
void sceVu0CopyVector__as_Sfx_SetTransform_1_001677C0(s8 *, f32 *);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Sfx_SetTransform_1_001677C0
void sceVu0CopyMatrix__as_Sfx_SetTransform_1_001677C0(s8 *, S *);
#define Mtx_RotateToward_0_00146140 Mtx_RotateToward_0_00146140__as_Sfx_SetTransform_1_001677C0
void Mtx_RotateToward_0_00146140__as_Sfx_SetTransform_1_001677C0(f32, f32, s8 *);

void Sfx_SetTransform_1_001677C0(s8 *arg0) {
    S s;

    if (arg0 != NULL) {
        Mtx_FromTransform_0_00145FB0(&s);
        if (arg0 != NULL) {
            if (((B_Sfx_SetTransform_1_001677C0 *)(*(s8 **)(arg0 + 0x210) + 0x94))->v) {
                Mtx_RotateToward_0_00146140(s.x, s.z, arg0);
                sceVu0CopyVector(arg0 + 0x30, s.v);
                return;
            }
            sceVu0CopyMatrix(arg0, &s);
        }
    }
}
#undef sceVu0CopyVector
#undef sceVu0CopyMatrix
#undef Mtx_RotateToward_0_00146140

/* Sfx_OffsetAll_1_00167850 */
#define sceVu0CopyVector sceVu0CopyVector__as_Sfx_OffsetAll_1_00167850
void sceVu0CopyVector__as_Sfx_OffsetAll_1_00167850(void *, f32 *);
#define gSfxSystemBss_003407E0 gSfxSystemBss_003407E0__as_Sfx_OffsetAll_1_00167850
extern A gSfxSystemBss_003407E0__as_Sfx_OffsetAll_1_00167850[];

void Sfx_OffsetAll_1_00167850(f32 *arg0) {
    s32 i;
    A *a;

    a = gSfxSystemBss_003407E0;
    for (i = 0; i < 0x100; i++, a++) {
        if (a->flags & 1) {
            sceVu0AddVector(a->v, a->v, arg0);
            a->v[3] = 1.0f;
        }
    }
    sceVu0CopyVector(gSfxBss_003406D0, arg0);
    for (i = 0; i < gSfxSystemSbss_00201FAC; i++) {
        if (gSfxSystemSbss_00201FC0[i].f0 && !gSfxSystemSbss_00201FC0[i].f5) {
            sceVu0AddVector(&gSfxSystemSbss_00201FC0[i], &gSfxSystemSbss_00201FC0[i], arg0);
            sceVu0AddVector(gSfxSystemSbss_00201FC0[i].m2, gSfxSystemSbss_00201FC0[i].m2, arg0);
            gSfxAllSbss_00201FD0[i].c[gSfxAllSbss_00201F2C].x += arg0[0];
            gSfxAllSbss_00201FD0[i].c[gSfxAllSbss_00201F2C].y += arg0[1];
            gSfxAllSbss_00201FD0[i].c[gSfxAllSbss_00201F2C].z += arg0[2];
        }
    }
}
#undef sceVu0CopyVector
#undef gSfxSystemBss_003407E0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/vibration_bss_0033F540.c): gSfxBss_003406D0 */
u8 gSfxBss_003406D0[0x10];
#endif
