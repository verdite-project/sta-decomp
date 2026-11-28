/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/MapObj_PlayAnimImpl_1_001B8350.c.
 * The retail assembly of MapObj_PlayAnimImpl_1_001B8350 also holds MapObj_Hit_0_001B85B0, MapObj_SetAnimFrame_0_001B87C0. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "m2c.h"
typedef struct { u8 b0 : 2; } BF50;
typedef struct { u8 p : 1; u8 v : 2; } BF51;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } BF8;
s8 *MapObj_Find_1_001B19A0(s32);
s32 MapState_GetField_0_001A9D50(s32, u16);
void MapState_SetField_0_001A9E10(s32, u16, u8);
void MapObj_SetAnimFrame_0_001B87C0(s8 *, u32, s32, u8, f32, f32);
void Mdl_AnimateWrap_0_00171B70(s8 *, u16, f32);
void sceVu0CopyVector(s8 *, s8 *);
void Mdl_UpdateBoneMatricesCur_0_00171540(s8 *, s8 *);
void MapObj_SpawnContainedItem_0_001BB760(s8 *, u32, s32, s8 *, s32);

void MapObj_PlayAnimImpl_1_001B8350(s32 a0, u32 a1, s32 a2) {
    s8 *obj;
    s8 *p;
    s8 *t;
    s8 *e;
    s8 *s;

    p = MapObj_Find_1_001B19A0(a0);
    if (p != NULL) {
    t = *(s8 **)(p + 0x138) + a1 * 0x30;
    e = *(s8 **)(p + 0x180) + (a1 << 7);
    s = *(s8 **)(p + 0x170) + (*(u16 *)(t + 0x18) << 6);
    if (*(u16 *)(s + 4) == 2 && !(*(u8 *)(e + 0x50) & 3)) {
        s8 *e2;
        s8 *d;
        s8 **m;
        ((BF50 *)(e + 0x50))->b0 = 1;
        e2 = *(s8 **)(p + 0x180) + (a1 << 7);
        d = *(s8 **)(p + 0x170) + (*(u16 *)(*(s8 **)(p + 0x138) + a1 * 0x30 + 0x18) << 6);
        if ((*(u8 *)(e2 + 0x50) & 3) && ((BF8 *)(d + 0x12))->b3) {
            d = *(s8 **)(p + 0x170) + (*(u16 *)(d + 6) << 6);
            m = *(s8 ***)(e2 + 0x44);
        } else {
            m = *(s8 ***)(e2 + 0x40);
        }
        obj = *m;
        if (((BF8 *)(d + 0x12))->b2) {
            MapObj_SetAnimFrame_0_001B87C0(p, a1, 1, a2 ? 0x101 : 0, 0.0f, 1.0f);
            Mdl_AnimateWrap_0_00171B70(obj, *(u16 *)(obj + 8), *(f32 *)(obj + 0xC));
        } else if (((BF8 *)(d + 0x12))->b7) {
            ((BF50 *)(e + 0x50))->b0 = 2;
            *(f32 *)(e + 0x5C) = 1.0f;
        } else {
            ((BF50 *)(e + 0x50))->b0 = 3;
            ((BF8 *)(e + 0x52))->b4 = 1;
        }
        sceVu0CopyVector(obj + 0x30, p + 0x10);
        Mdl_UpdateBoneMatricesCur_0_00171540(obj, e);
        ((BF51 *)(e + 0x51))->v = 2;
        if (MapState_GetField_0_001A9D50(a0, a1) == 0) {
            MapObj_SpawnContainedItem_0_001BB760(p, a1, *(s16 *)(t + 0x28), t, 0);
        }
        MapState_SetField_0_001A9E10(a0, a1, 1);
    }
    }
}
#else
INCLUDE_ASM(MapObj_PlayAnimImpl_1_001B8350);
#endif
