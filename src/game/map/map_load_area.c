/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Map_LoadArea_1_001B51F0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: 33 of 274 words differ (was 57). Same length; remaining diff is only saved-register assignment:
   target has cur in s2 and the &PP(n) temp in s0 (ours s0/s2), o in s5, loop1 element ptr in s3 / byte-offset IV in s1,
   loop2 offset IV in s1 and &t2.w in s0. Declaration-order perms (1440), explicit offset IVs, pp local, i/o reuse, b38 did not move it.
   Fixed: side=-1 before the early return (no pad nop), k->key == o->id order. */
#include "common.h"
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; u8 x38; u8 pad[7]; } EA;
typedef struct { Vec a; f32 x10; f32 x14; f32 x18; u8 b1C; u8 b1D; u8 b1E; u8 b1F; u16 h20; u8 b22; u8 used; u8 pad[0xC]; } EB;
typedef struct {
    s32 id;
    u8 pad4[0xC];
    Vec pos;
    u8 pad20[0x5C];
    u16 x7C;
    u16 x7E;
    u8 pad80[0xE8];
    EA *x168;
    EB *x16C;
    u8 pad170[0x68];
    Flags8 x1D8;
} S;
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad14[4]; S **x18; u8 pad1C[4]; } Info;
typedef struct { u16 key; s16 x; s16 y; s16 z; } K;
extern s32 D_00201E80;
#define PP(i) (((S ***)(&D_00201E80 + 2))[i])
extern s32 D_002022C0;
extern Vec D_004B4BD0;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
s32 Map_StreamGetResult_1_001B0660(Info *);
void Map_RequestArea_1_001B06E0(u16, Vec *, s32);
void Map_StreamStart_0_001B0450(void);
void Map_StreamFlush_1_001B03E0(void);
void Map_FreeArea_1_001B5640(S **);
void LightGroup_Clear_0_0015B890(s32);
void PointLightGroup_Clear_0_0015C6D0(s32);
s32 Light_Add_0_0015B980(s32 idx, Vec *a, Vec *b, Vec *c, f32 f0, f32 f1, f32 f2, f32 f3);
s32 PointLight_Add_0_0015C730(s32 idx, Vec *v, f32 f0, f32 f1, f32 f2, f32 f3, u8 c0, u8 c1, u8 c2, u8 c3, u16 h, u8 c4);

void Map_LoadArea_1_001B51F0(S *a0, K *k, s32 a2) {
    Info info;
    Vec v;
    Vec b0;
    Vec t;
    Vec b1;
    Vec t2;
    s16 side;
    S *o2;
    s32 j;
    EB *e2;
    S *o;
    s32 cur;
    EA *e;
    s32 i;
    s32 r;
    s16 n;
    Flags8 *f;

    side = -1;
    if (a0->id == k->key) return;
    if (((S **)(&D_00201E80)[2]) && *((S **)(&D_00201E80)[2]) == a0) side = 0;
    if (((S **)(&D_00201E80)[3]) && *((S **)(&D_00201E80)[3]) == a0) side = 1;
    n = !side;
    if ((&D_00201E80)[1] != n && PP(side)) {
        sceVu0CopyVector(&v, &(*PP(side))->pos);
        if (v.x != 0.0f || v.y != 0.0f || v.z != 0.0f) {
            D_002022C0 = 1;
            v.w = 0.0f;
            sceVu0CopyVector(&D_004B4BD0, &v);
        }
    }
    if (((S **)(&D_00201E80)[2])) sceVu0CopyVector(&v, &(*((S **)(&D_00201E80)[2]))->pos);
    if (((S **)(&D_00201E80)[3])) sceVu0CopyVector(&v, &(*((S **)(&D_00201E80)[3]))->pos);
    cur = n;
    (&D_00201E80)[1] = cur;
    v.x = -1.0f * k->x;
    v.y = -1.0f * k->y;
    v.z = -1.0f * k->z;
    v.w = 0.0f;
    if (PP(n)) {
        o = *PP(n);
        if (k->key == o->id) return;
        f = &o->x1D8;
        if (!f->f.b3) {
            f->f.b3 = 1;
            return;
        }
        LightGroup_Clear_0_0015B890(cur);
        PointLightGroup_Clear_0_0015C6D0(cur);
        Map_FreeArea_1_001B5640(PP(n));
        PP(n) = 0;
        return;
    }
    r = Map_StreamGetResult_1_001B0660(&info);
    if (info.x10 != -1) {
        if (info.x10 == k->key) {
            if (a2 != 0 && (u8)r != 0 && (u8)r != 2) {
                Map_StreamStart_0_001B0450();
                    PP(n) = info.x18;
                    o = *PP(n);
                    sceVu0CopyVector(&b0, &o->pos);
                    LightGroup_Clear_0_0015B890(cur);
                    for (i = 0; i < o->x7C; i++) {
                        e = &o->x168[i];
                        if (e->x38 == 0) {
                            sceVu0CopyVector(&t, &e->a);
                            sceVu0AddVector(&t, &t, &b0);
                            t.w = e->a.w;
                            Light_Add_0_0015B980(cur, &t, &e->b, &e->c, t.w, e->b.w, e->x30, e->x34);
                        }
                    }
                    o2 = *PP(n);
                    sceVu0CopyVector(&b1, &o2->pos);
                    PointLightGroup_Clear_0_0015C6D0(cur);
                    for (j = 0; j < o2->x7E; j++) {
                        e2 = &o2->x16C[j];
                        sceVu0CopyVector(&t2, &e2->a);
                        sceVu0AddVector(&t2, &t2, &b1);
                        t2.w = e2->a.w;
                        PointLight_Add_0_0015C730(cur, &t2, t2.w, e2->x18, e2->x10, e2->x14, e2->b1C, e2->b1D, e2->b1E, e2->b1F, e2->h20, e2->b22);
                    }
            }
        } else {
            Map_FreeArea_1_001B5640(info.x18);
            info.x18 = 0;
            Map_StreamFlush_1_001B03E0();
        }
    } else {
        Map_RequestArea_1_001B06E0(k->key, &v, 0);
    }
}
#else
INCLUDE_ASM(Map_LoadArea_1_001B51F0);
#endif
