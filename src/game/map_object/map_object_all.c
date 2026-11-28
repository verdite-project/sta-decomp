#include "common.h"
#include "m2c.h"
#include "game/core.h"
#include "game/effect.h"
#include "game/collision.h"
#include "game/data.h"
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[0xA]; Flags8_6x2 f24; Flags8 f25; u8 pad26[4]; u16 x2A; u8 pad2C[4]; } A;
typedef struct { u8 st:2; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } F50;
typedef struct { u8 b0:1; u8 c:2; u8 r:5; } F51;
typedef struct {
    u8 pad0[0x40];
    s32 **x40;
    s32 **x44;
    u8 pad48[8];
    F50 f50;
    F51 f51;
    Flags8 f52;
    Flags8 f53;
    void *x54;
    f32 x58;
    f32 x5C;
    f32 x60;
    u8 pad64[0xC];
    Vec x70;
} B;
typedef struct { u8 pad0[2]; u8 x2; u8 pad3; u16 x4; u16 x6; u16 x8; u8 padA[8]; Flags8 f12; u8 pad13[0xD]; Vec x20; u8 pad30[0x10]; } C_MapObj_UpdateAll_0_001BAB70;
typedef struct { u8 pad0[8]; u16 x8; u8 padA[2]; f32 xC; f32 x10; f32 x14; u8 pad18[0x18]; Vec x30; } H;
typedef struct { u8 pad0[0x14]; u16 x14; u16 x16; } K;
typedef struct { u8 pad[0x10]; s32 x10; } M_MapObj_UpdateAll_0_001BAB70;
typedef struct {
    s32 x0;
    M_MapObj_UpdateAll_0_001BAB70 **x4;
    u8 pad8[8];
    Vec x10;
    s32 x20;
    u8 pad24[0x6E - 0x24];
    u16 n;
    u8 pad70[0xB4 - 0x70];
    u8 xB4[0x138 - 0xB4];
    A *x138;
    u8 pad13C[0x170 - 0x13C];
    C_MapObj_UpdateAll_0_001BAB70 *x170;
    u8 pad174[0xC];
    B *x180;
    u8 pad184[0x1D8 - 0x184];
    Flags8 f1D8;
} O_MapObj_UpdateAll_0_001BAB70;
typedef Bits8 BF8;
typedef struct { u8 v : 2; } BF50;
typedef struct { u8 p : 1; u8 v : 2; } BF51;
typedef struct { u8 p : 2; u8 v : 2; } BF24;
typedef struct C_MapObj_SpawnContainedItem_0_001BB760 C_MapObj_SpawnContainedItem_0_001BB760;
typedef struct { u8 pad0[0x24]; Flags8 x24; } M_MapObj_Create_0_001BB8A0;
typedef struct { u8 pad0[0x40]; M_MapObj_Create_0_001BB8A0 **x40; M_MapObj_Create_0_001BB8A0 **x44; s32 x48; s32 x4C;
    u32 p0:6; u32 a:1; u32 b:1; u32 c:1; u32 d:2; u32 f:8; u32 g:1; u32 rest:12;
    u8 pad54[4]; f32 x58; u8 pad5C[4]; f32 x60; u8 pad64[0x1C]; } E;
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[0x16]; } S;
typedef struct { u16 x0; u8 pad2[4]; u16 x6; u8 pad8[0xA]; Flags8 x12; u8 pad13; u16 x14; u8 pad16[0x2A]; } T;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } P;
typedef struct { u8 pad0[0x10]; s32 x10; } C10;
typedef struct {
    u8 pad0[4];
    C10 **x4;
    u8 pad8[0x1C];
    s32 x24;
    u8 pad28[0x46];
    u16 x6E;
    u8 pad70[0x10];
    u16 x80;
    u8 pad82[0xB6];
    S *x138;
    u8 pad13C[0x34];
    T *x170;
    u8 pad174[0xC];
    E *x180;
    u8 pad184[0x10];
    P *x194;
} O_MapObj_Create_0_001BB8A0;
extern O_MapObj_UpdateAll_0_001BAB70 *D_002022D4;
extern C_MapObj_SpawnContainedItem_0_001BB760 **D_00201E80[2];
void MapObj_UpdateAll_0_001BAB70(O_MapObj_UpdateAll_0_001BAB70 *o, f32 dt);
void MapObj_InitAnim_1_001BB320(s8 *p, u32 i);
void MapObj_SpawnContainedItem_0_001BB760(C_MapObj_SpawnContainedItem_0_001BB760 *c, s32 f, s32 id, void *m, s32 lift);
void MapObj_Create_0_001BB8A0(s32 a0, O_MapObj_Create_0_001BB8A0 *o, s32 a2);
void sceVu0CopyVector(Vec *, Vec *);
void MapObj_CheckProximity_0_001B7F90(A *, B *, s32, s32);
void Trap_SetState_0_001BA850(f32, f32, O_MapObj_UpdateAll_0_001BAB70 *, s32);
void Trap_UpdateIdle_1_001BA680(O_MapObj_UpdateAll_0_001BAB70 *, s32, f32, f32);
void Trap_Update_0_001BA3F0(O_MapObj_UpdateAll_0_001BAB70 *, s32, f32, f32);
s8* Mdl_GetFrameData_0_001715B0(s32 **);
void Player_GetPos_1_001C9410(Vec *);
void MapObj_SetAnimFrame_0_001B87C0(void *, s32, s32, s32, f32, f32);
void MapState_SetField_0_001A9E10(s32, u16, s32);
f32 Mdl_GetMotionLength_0_00173F70(K *, u16);
void Mdl_AnimateWrap_0_00171B70(H *, u16, f32);
void Mdl_UpdateBoneMatricesCur_0_00171540(void *, void *);
void Mdl_RunMotionEvents_0_001717A0(H *, u16, f32, f32, void (*)(void));
void Trap_Attack_0_001BAA10(void);
void sceVu0ApplyMatrix(Vec *, s8 *, Vec *);
void* Sfx_Spawn_2_00169B50(u16, s32, s32, s32);
void* Sfx_SpawnFromStam_2_00169BD0(u16, s32, u8 *, s32, s32, s32);
void Sfx_SetTransform_1_001677C0(void *, s8 *);
s32 MapState_GetField_0_001A9D50(s32, u16);
void Mdl_AnimateSel_0_00171B30(s8 *, u16, f32, s32);
void Mdl_ResetBones_0_00171610(s8 **);
s32 Inventory_CountItem_0_001CC0C0(s16, s32);
void Map_DecodeTransform_0_001B59E0(void *, Vec*, Vec*, Vec*);
void ItemObj_SpawnFromMap_0_001AEE80(C_MapObj_SpawnContainedItem_0_001BB760 **, s32, Vec *, Vec *, u16);
void Tex_LoadAnimated_0_0016FB80(s32, s32, s32 **, s32 **, s32 **);
void Mdl_SetDrawFlag_0_0016F410(s32, s32, s32);
void Mtx_Compose_2_00173FD0(E *, Vec *, Vec *, Vec *);
M_MapObj_Create_0_001BB8A0** Mdl_CreateInstance_0_00174230(s32, s32, s32, s32);

/* MapObj_UpdateAll_0_001BAB70 */
#define MapObj_InitAnim_1_001BB320 MapObj_InitAnim_1_001BB320__as_MapObj_UpdateAll_0_001BAB70
void MapObj_InitAnim_1_001BB320__as_MapObj_UpdateAll_0_001BAB70(O_MapObj_UpdateAll_0_001BAB70 *, s32);
#define MapObj_SetAnimFrame_0_001B87C0 MapObj_SetAnimFrame_0_001B87C0__as_MapObj_UpdateAll_0_001BAB70
void MapObj_SetAnimFrame_0_001B87C0__as_MapObj_UpdateAll_0_001BAB70(O_MapObj_UpdateAll_0_001BAB70 *, s32, s32, s32, f32, f32);
#define Mdl_UpdateBoneMatricesCur_0_00171540 Mdl_UpdateBoneMatricesCur_0_00171540__as_MapObj_UpdateAll_0_001BAB70
void Mdl_UpdateBoneMatricesCur_0_00171540__as_MapObj_UpdateAll_0_001BAB70(H *, B *);

static inline C_MapObj_UpdateAll_0_001BAB70 *getc(O_MapObj_UpdateAll_0_001BAB70 *o, s32 i, s32 ***hp) {
    B *e = &o->x180[i];
    A *e30 = &o->x138[i];
    C_MapObj_UpdateAll_0_001BAB70 *base = o->x170;
    C_MapObj_UpdateAll_0_001BAB70 *t = &base[e30->x18];
    if (e->f50.st && t->f12.f.b3) {
        *hp = e->x44;
        return &base[t->x6];
    }
    *hp = e->x40;
    return t;
}

void MapObj_UpdateAll_0_001BAB70(O_MapObj_UpdateAll_0_001BAB70 *o, f32 dt) {
    s32 i;
    A *a;
    B *b;
    C_MapObj_UpdateAll_0_001BAB70 *c;
    s32 **h;
    H *hh;
    K **x;
    s32 flag;
    B *b2;
    A *a2;
    s8 *sk;
    f32 r;
    u8 t;
    u16 id;
    Vec v;
    B *e;
    A *e30;
    C_MapObj_UpdateAll_0_001BAB70 *base;

    for (i = 0; i < o->n; i++) {
        a = &o->x138[i];
        b = &o->x180[i];
        flag = 0;
        if (!o->f1D8.f.b4) MapObj_InitAnim_1_001BB320(o, i);
        e = &o->x180[i];
        e30 = &o->x138[i];
        base = o->x170;
        c = &base[e30->x18];
        if (e->f50.st && c->f12.f.b3) {
            c = &base[c->x6];
            h = e->x44;
        } else {
            h = e->x40;
        }
        hh = (H *)*h;
        x = *(K ***)hh;
        sceVu0CopyVector(&hh->x30, &o->x10);
        if (o->x20 != 0) b->f51.c = 2;
        MapObj_CheckProximity_0_001B7F90(a, b, o->x0, i);
        switch (c->x4) {
        case 0:
            Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        case 1:
            a2 = &o->x138[i];
            b2 = &o->x180[i];
            if (b2->f52.f.b6) break;
            if (a2->f24.f.b6 == 2) {
                sk = Mdl_GetFrameData_0_001715B0(b2->x40);
                Player_GetPos_1_001C9410(&v);
                if (Vec_DistB_3_0015DF50(&v, sk + 0x230) <= (f32)a2->x2A) {
                    MapObj_SetAnimFrame_0_001B87C0(o, i, 0xB, 0, 0.0f, 1.0f);
                    b2->f52.f.b6 = 1;
                    MapState_SetField_0_001A9E10(o->x0, i, 1);
                    break;
                }
            }
            Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        case 2:
            Trap_UpdateIdle_1_001BA680(o, i, dt, 0.0f);
            break;
        case 3:
            if (!o->x180[i].f52.f.b5) Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        case 4:
            Trap_Update_0_001BA3F0(o, i, dt, 0.0f);
            break;
        case 5:
            if (!o->x180[i].f53.f.b3) Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        }
        if ((a->f25.f.b0 || (!a->f25.f.b0 && b->f52.f.b3 && b->f53.f.b0)) && (*x)->x16 != 0 && b->f50.b2) {
            r = Mdl_GetMotionLength_0_00173F70(*x, hh->x8);
            hh->x10 = hh->xC;
            if (b->f50.b5) {
                hh->xC -= dt * hh->x14;
            } else {
                hh->xC += dt * hh->x14;
            }
            t = b->f50.b4;
            if (!t && b->f52.f.b3) flag = 1;
            if (b->f50.b3) {
                if (b->f50.b5) {
                    if (hh->xC < 0.0f) hh->xC = hh->xC + r;
                } else {
                    if (!(hh->xC <= r)) hh->xC = hh->xC - r;
                }
            } else {
                if (t) b->f50.b2 = 0;
                if (b->f50.b5) {
                    if (hh->xC < 0.0f) {
                        hh->xC = 0.0f;
                        b->f50.b4 = 1;
                    }
                } else {
                    if (!(hh->xC <= r)) {
                        hh->xC = r;
                        b->f50.b4 = 1;
                    }
                }
            }
            Mdl_AnimateWrap_0_00171B70(hh, hh->x8, hh->xC);
            b->f51.c = 2;
        }
        if (b->f51.c) {
            Mdl_UpdateBoneMatricesCur_0_00171540(hh, b);
            b->f51.c--;
        }
        if (flag) {
            D_002022D4 = o;
            Mdl_RunMotionEvents_0_001717A0(hh, hh->x8, hh->xC, hh->x10, Trap_Attack_0_001BAA10);
        }
        sk = Mdl_GetFrameData_0_001715B0(h);
        if (!b->f52.f.b4 && b->f52.f.b3 && !b->f50.st && c->f12.f.b6) {
            sceVu0CopyVector(&b->x70, &c->x20);
            b->x70.w = 1.0f;
            sceVu0ApplyMatrix(&b->x70, sk + 0x200, &b->x70);
            b->x70.w = c->x20.w * b->x60;
        }
        if (!o->f1D8.f.b4 && a->f24.f.b4 && (id = c->x8) != 0) {
            if (Sfx_IsLoaded_2_00169BB0(id)) {
                b->x54 = Sfx_Spawn_2_00169B50(c->x8, 0, 0, 0);
            } else {
                b->x54 = Sfx_SpawnFromStam_2_00169BD0(c->x8, (*o->x4)->x10, o->xB4, 0, 0, 0);
            }
        }
        if (b->x54 != 0) {
            if (c->x2 < (*x)->x14) {
                Sfx_SetTransform_1_001677C0(b->x54, sk + (c->x2 + 1) * 0x140 + 0xC0);
            } else {
                Sfx_SetTransform_1_001677C0(b->x54, sk + 0x200);
            }
        }
    }
    o->f1D8.f.b4 = 1;
}
#undef MapObj_InitAnim_1_001BB320
#undef MapObj_SetAnimFrame_0_001B87C0
#undef Mdl_UpdateBoneMatricesCur_0_00171540

/* MapObj_InitAnim_1_001BB320 */
#define MapObj_SetAnimFrame_0_001B87C0 MapObj_SetAnimFrame_0_001B87C0__as_MapObj_InitAnim_1_001BB320
void MapObj_SetAnimFrame_0_001B87C0__as_MapObj_InitAnim_1_001BB320(s8 *, u32, s32, s32, f32, f32);
#define MapObj_SpawnContainedItem_0_001BB760 MapObj_SpawnContainedItem_0_001BB760__as_MapObj_InitAnim_1_001BB320
void MapObj_SpawnContainedItem_0_001BB760__as_MapObj_InitAnim_1_001BB320(s8 *, u32, s32, s8 *, s32);

void MapObj_InitAnim_1_001BB320(s8 *p, u32 i) {
    s8 *t;
    s8 *s;
    s8 **m;
    s32 r;
    s8 *e;
    s8 *e30;
    s32 mode; s8 *q;

    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    e = *(s8 **)(p + 0x180) + (i << 7);
    t = *(s8 **)(p + 0x170) + (*(u16 *)(e30 + 0x18) << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF8 *)(t + 0x12))->b3) {
        t = *(s8 **)(p + 0x170) + (*(u16 *)(t + 6) << 6);
        m = *(s8 ***)(e + 0x44);
    } else {
        m = *(s8 ***)(e + 0x40);
    }
    s = *m; q = *(s8 **)s;
    if ((*(u8 *)(t + 0x12) & 1) && *(u16 *)(*(s8 **)q + 0x16) != 0) {
        mode = ((BF24 *)(e30 + 0x24))->v;
        if (mode == 1) {
            MapObj_SetAnimFrame_0_001B87C0(p, i, 0, 0x80, 0.0f, 1.0f);
        } else if (mode == 2) {
            MapObj_SetAnimFrame_0_001B87C0(p, i, 0, 0, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b7 = 1;
        }
    }
    r = MapState_GetField_0_001A9D50(*(s32 *)p, i);
    switch (*(u16 *)(t + 4)) {
    case 0:
        break;
    case 1:
        if (r & 1) {
            MapObj_SetAnimFrame_0_001B87C0(p, i, 0xB, 1, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b6 = 1;
        }
        break;
    case 2:
        if (r & 1) {
            s8 *e2;
            s8 *t2;
            ((BF50 *)(e + 0x50))->v = 3;
            ((BF8 *)(e + 0x52))->b4 = 1;
            e2 = *(s8 **)(p + 0x180) + (i << 7);
            t2 = *(s8 **)(p + 0x170) + (*(u16 *)(*(s8 **)(p + 0x138) + i * 0x30 + 0x18) << 6);
            if ((*(u8 *)(e2 + 0x50) & 3) && ((BF8 *)(t2 + 0x12))->b3) {
                t2 = *(s8 **)(p + 0x170) + (*(u16 *)(t2 + 6) << 6);
                m = *(s8 ***)(e2 + 0x44);
            } else {
                m = *(s8 ***)(e2 + 0x40);
            }
            s = *m;
            MapObj_SetAnimFrame_0_001B87C0(p, i, 1, 1, 0.0f, 1.0f);
            if (((BF8 *)(t2 + 0x12))->b7) {
                ((BF8 *)(e + 0x52))->b3 = 0;
            }
            if (!(r & 2)) {
                MapObj_SpawnContainedItem_0_001BB760(p, i, *(s16 *)(e30 + 0x28), e30, 0);
            }
        }
        break;
    case 3:
        if (r & 1) {
            MapObj_SetAnimFrame_0_001B87C0(p, i, 0xA, 1, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b5 = 1;
            if (!(r & 2)) {
                MapObj_SpawnContainedItem_0_001BB760(p, i, *(s16 *)(e30 + 0x28), e30, 1);
            }
        }
        break;
    case 4:
        ((BF8 *)(e + 0x52))->b6 = 0;
        break;
    case 5:
        if (r & 1) {
            MapObj_SetAnimFrame_0_001B87C0(p, i, 0xA, 1, 0.0f, 1.0f);
            ((BF8 *)(e + 0x53))->b3 = 1;
        }
        break;
    }
    if (((BF8 *)(e + 0x50))->b2) {
        Mdl_AnimateSel_0_00171B30(s, *(u16 *)(s + 8), *(f32 *)(s + 0xC), !(D_00201F2C != 0));
        Mdl_ResetBones_0_00171610(m);
    }
    ((BF51 *)(e + 0x51))->v = 2;
}
#undef MapObj_SetAnimFrame_0_001B87C0
#undef MapObj_SpawnContainedItem_0_001BB760

/* MapObj_SpawnContainedItem_0_001BB760 */
#define CC (((C_MapObj_SpawnContainedItem_0_001BB760 ***)&D_00201E80)[2])
#define DD (((C_MapObj_SpawnContainedItem_0_001BB760 ***)&D_00201E80)[3])

void MapObj_SpawnContainedItem_0_001BB760(C_MapObj_SpawnContainedItem_0_001BB760 *c, s32 f, s32 id, void *m, s32 lift) {
    s32 k;
    Vec a;
    Vec b;
    Vec d;
    k = -1;
    if ((s16)id <= 0 || !((s16)id < 0x400)) return;
    if (CC && *CC && *CC == c) k = 0;
    if (DD && *DD && *DD == c) k = 1;
    if (k == -1) return;
    if (!Inventory_CountItem_0_001CC0C0(id, 0)) return;
    Map_DecodeTransform_0_001B59E0(m, &a, &b, &d);
    if (lift) a.y -= 20.0f;
    ItemObj_SpawnFromMap_0_001AEE80(D_00201E80[k + 2], id, &a, &b, f);
}
#undef CC
#undef DD

/* MapObj_Create_0_001BB8A0 */
#define Map_DecodeTransform_0_001B59E0 Map_DecodeTransform_0_001B59E0__as_MapObj_Create_0_001BB8A0
void Map_DecodeTransform_0_001B59E0__as_MapObj_Create_0_001BB8A0(S *, Vec *, Vec *, Vec *);
#define Mdl_UpdateBoneMatricesCur_0_00171540 Mdl_UpdateBoneMatricesCur_0_00171540__as_MapObj_Create_0_001BB8A0
void Mdl_UpdateBoneMatricesCur_0_00171540__as_MapObj_Create_0_001BB8A0(M_MapObj_Create_0_001BB8A0 *, E *);
#define MAX(a, b) ((a) < (b) ? (b) : (a))

void MapObj_Create_0_001BB8A0(s32 a0, O_MapObj_Create_0_001BB8A0 *o, s32 a2) {
    Vec v0;
    Vec v1;
    Vec v2;
    s32 *A[256];
    s32 *B[256];
    s32 *C[256];
    s32 i;
    S *s;
    s32 k;
    E *e;
    T *t;
    s16 id;

    if (a2) {
        for (i = 0; i < o->x80; i++) {
            A[i] = &o->x194[i].x0;
            B[i] = &o->x194[i].x4;
            C[i] = &o->x194[i].xC;
        }
        Tex_LoadAnimated_0_0016FB80(a0, (*o->x4)->x10, A, B, C);
        for (i = 0; i < o->x80; i++) {
            Mdl_SetDrawFlag_0_0016F410(*(s32 *)*A[i], o->x24, 0);
        }
    }
    for (i = 0; i < o->x6E; i++) {
        s = &o->x138[i];
        e = &o->x180[i];
        t = &o->x170[s->x18];
        id = s->x18;
        e->x48 = Frame_IncCounter_1_0015C9E0();
        e->x4C = t->x14;
        e->a = t->x12.f.b1;
        e->b = t->x12.f.b2;
        e->c = t->x12.f.b3;
        e->f = 0xFF;
        e->g = 1;
        e->d = 2;
        e->x58 = 1.0f;
        Map_DecodeTransform_0_001B59E0(s, &v0, &v1, &v2);
        Mtx_Compose_2_00173FD0(e, &v0, &v1, &v2);
        e->x60 = MAX(MAX(v2.x, v2.y), v2.z);
        e->x40 = Mdl_CreateInstance_0_00174230(a0, o->x194[id].x0, -1, -1);
        (*e->x40)->x24.f.b2 = 0;
        for (k = 0; k < 2; k++) {
            D_00201F2C = k;
            Mdl_UpdateBoneMatricesCur_0_00171540(*e->x40, e);
        }
        if (t->x12.f.b3 && o->x170[t->x6].x0 < o->x80) {
            e->x44 = Mdl_CreateInstance_0_00174230(a0, o->x194[o->x170[t->x6].x0].x0, -1, -1);
            (*e->x44)->x24.f.b2 = 0;
            for (k = 0; k < 2; k++) {
                D_00201F2C = k;
                Mdl_UpdateBoneMatricesCur_0_00171540(*e->x44, e);
            }
        }
    }
}
#undef Map_DecodeTransform_0_001B59E0
#undef Mdl_UpdateBoneMatricesCur_0_00171540

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_002022D4 */
O_MapObj_UpdateAll_0_001BAB70 *D_002022D4;
#endif
