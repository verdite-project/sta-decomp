#include "common.h"
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } BF8;
typedef struct { u8 v : 2; } BF50;
extern s32 gMapSbss_00201E80;
s8 *Mdl_GetFrameData_0_001715B0(s8 **);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 fabsf(f32);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
f32 atan2f(f32, f32);
void MapObj_SetAnimFrame_0_001B87C0(s8 *, u32, s32, s32, f32, f32);
void Mdl_AnimateWrap_0_00171B70(s8 *, u16, f32);
void sceVu0CopyVector(s8 *, s8 *);
void Mdl_UpdateBoneMatricesCur_0_00171540(s8 *, s8 *);
#define PI 3.1415927f
#define TWOPI 6.2831855f
#define INV 0.15915494f
#define WRAP(x) ((((x) + PI) - TWOPI * (s32)(INV * ((x) + PI))) + (((x) + PI) < 0.0f ? TWOPI : 0.0f) - PI)
static inline f32 u2f(u32 x) { return x; }

void MapObj_SnapToGround_0_001B9F10(Vec *pos, Vec *rot, f32 scale, f32 maxh) {
    s8 *t;
    s8 ***q;
    s32 k;
    s8 *p;
    s32 i;
    s8 *e;
    s8 *e30;
    s8 *r;
    s8 *s;
    s8 **m;
    s8 *e2;
    s8 *t2;
    f32 a;
    f32 b;
    f32 range;
    f32 ang;
    f32 w;
    f32 tt;
    f32 diff;
    Vec d;

    for (k = 0, q = (s8 ***)(&gMapSbss_00201E80 + 2); k < 2; k++, q++) {
        if (*q == NULL) continue;
        p = **q;
        if (p == NULL) continue;
        if (((BF8 *)(p + 0x1D8))->b1) continue;
        if (!((BF8 *)(p + 0x1D8))->b0) continue;
        for (i = 0; i < *(u16 *)(p + 0x6E); i++) {
            e30 = *(s8 **)(p + 0x138) + i * 0x30;
            e = *(s8 **)(p + 0x180) + (i << 7);
            t = *(s8 **)(p + 0x170) + (*(u16 *)(e30 + 0x18) << 6);
            r = Mdl_GetFrameData_0_001715B0(*(s8 ***)(e + 0x40));
            if (*(u16 *)(t + 4) != 4) continue;
            if (!((BF8 *)(e + 0x52))->b3) continue;
            if (*(u8 *)(e + 0x50) & 3) continue;
            if (((BF8 *)(e + 0x53))->b2) continue;
            a = 0.00024414062f * u2f(*(u16 *)(e30 + 0x12));
            b = 0.00024414062f * u2f(*(u16 *)(e30 + 0x16));
            if (a < b) {
                b = b;
            } else {
                b = a;
            }
            range = scale * b;
            sceVu0SubVector(&d, pos, (Vec *)(r + 0x230));
            if (!(fabsf(d.y) <= maxh)) continue;
            d.y = 0.0f;
            if (!(sceVu0InnerProduct(&d, &d) <= range * range)) continue;
            sceVu0ScaleVector(&d, &d, -1.0f);
            range = PI + rot->y;
            w = range < 0.0f ? TWOPI : 0.0f;
            tt = range - TWOPI * (s32)(INV * range);
            diff = atan2f(-d.x, -d.z) - (tt + w - PI);
            if (!(fabsf(WRAP(diff)) <= 1.39626348f)) continue;
            ((BF50 *)(e + 0x50))->v = 1;
            e2 = *(s8 **)(p + 0x180) + (i << 7);
            t2 = *(s8 **)(p + 0x170) + (*(u16 *)(*(s8 **)(p + 0x138) + i * 0x30 + 0x18) << 6);
            if ((*(u8 *)(e2 + 0x50) & 3) && ((BF8 *)(t2 + 0x12))->b3) {
                t2 = *(s8 **)(p + 0x170) + (*(u16 *)(t2 + 6) << 6);
                m = *(s8 ***)(e2 + 0x44);
            } else {
                m = *(s8 ***)(e2 + 0x40);
            }
            s = *m;
            if (((BF8 *)(t2 + 0x12))->b2) {
                MapObj_SetAnimFrame_0_001B87C0(p, i, 1, 0, 0.0f, 1.0f);
                Mdl_AnimateWrap_0_00171B70(s, *(u16 *)(s + 8), *(f32 *)(s + 0xC));
            } else if (((BF8 *)(t2 + 0x12))->b7) {
                ((BF50 *)(e + 0x50))->v = 2;
                *(f32 *)(e + 0x5C) = 1.0f;
            } else {
                ((BF50 *)(e + 0x50))->v = 3;
                ((BF8 *)(e + 0x52))->b4 = 1;
            }
            sceVu0CopyVector(s + 0x30, p + 0x10);
            Mdl_UpdateBoneMatricesCur_0_00171540(s, e);
            ((BF8 *)(e + 0x53))->b2 = 1;
        }
    }
}
