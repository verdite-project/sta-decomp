#include "m2c.h"
#include "common.h"
#include "game/core.h"
#include "game/effect.h"
#include "game/gfx.h"
#include "game/map.h"
#include "game/model.h"
#include "game/sound.h"
#include "game/data.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } BF;
typedef struct { Mtx m; u8 pad[0xF0]; u8 b; u8 pad131[0xF]; } El_Map_GetNodeTransform_0_001B3710;
typedef struct { u8 pad[0xC0]; El_Map_GetNodeTransform_0_001B3710 el[1]; } B;
typedef struct { s32 off; s32 pad[3]; } Ent;
typedef struct { u8 pad[0x10]; u8 **p; u8 pad14[0x2C]; Ent t[1]; } H_Map_GetNodeTransform_0_001B3710;
typedef union { u32 w; struct { Flags8 a, b, c, d; } f; } Key;
typedef struct { u128 q[10]; } Big;
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; s16 x18; u8 pad1A[6]; u8 x20; s8 x21; u8 pad22[2]; u8 x24; s8 x25; u8 pad26[2]; Flags8 f28; u8 pad29[3]; Key x2C; } E_Map_DrawArea_0_001B37F0;
typedef struct { s32 **h; Flags8 f; u8 pad[3]; } P8_Map_DrawArea_0_001B37F0;
typedef struct { u8 pad[0xC0]; Mtx m0; Mtx m1; } N;
typedef struct O_Map_DrawArea_0_001B37F0 O_Map_DrawArea_0_001B37F0;
typedef struct { Mtx m[5]; } El_Map_DrawArea_0_001B37F0;
typedef struct { f32 p[3]; s16 r[3]; u16 s[3]; } EA;
typedef struct { unsigned char : 2; unsigned char f : 1; char pad[3]; } H_Map_FilterOpaque_0_001B3F30;
typedef struct { unsigned char : 3; unsigned char f : 1; char pad[3]; } H_Map_FilterTranslucent_0_001B3F80;
typedef struct { u8 pad[0xBA]; u16 xBA; u8 xBC; } D;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } F;
typedef struct { u8 pad[0x20]; s32 x20; u8 pad24[0x64]; s16 x88; s16 x8A; u8 pad8c[0x158 - 0x8C]; D *x158; u8 pad15c[0x1D8 - 0x15C]; F x1D8; } O_Map_Draw_1_001B3FD0;
typedef struct { char pad[0xBA]; u16 h; } T_Map_UpdateTexAnim_0_001B40B0;
typedef struct { char pad[0x158]; T_Map_UpdateTexAnim_0_001B40B0 *t; } Obj;
typedef struct { Vec v[8]; } V8;
typedef struct { u8 pad[0xA0]; } A0;
typedef struct {
    u8 pad0[0x74];
    u16 n74;
    u8 pad76[0x144 - 0x76];
    V8 *x144;
    u8 pad148[0x188 - 0x148];
    A0 *x188;
} A_Map_UpdateFog_0_001B4100;
typedef struct { u8 pad[0x1C]; u8 bit; u8 pad2[0xF]; } E_Map_UpdateSfxVisibility_0_001B41C0;
typedef struct { s8 *p; u8 b0:1; u8 b1:1; } Slot;
typedef struct {
    u8 pad0[0x78]; u16 n; u8 pad7A[0x12]; s16 i8C; s16 i8E;
    u8 pad90[0xC0]; E_Map_UpdateSfxVisibility_0_001B41C0 *elems; s32 *tbl; u8 pad158[0x38]; Slot *slots;
    u8 pad194[0x44]; u8 f0:1;
} O_Map_UpdateSfxVisibility_0_001B41C0;
typedef struct { u8 t:2; u8 b2:1; u8 b3:1; u8 b4:1; } EF;
typedef struct {
    f32 x, y, z;
    u8 padC[0xC];
    u16 x18;
    u16 x1A;
    u16 x1C;
    u16 x1E;
    u16 x20;
    u16 x22;
    u16 x24;
    u16 x26;
    u16 x28;
    u16 x2A;
    u8 x2C;
    u8 pad2D[3];
    EF x30;
    u8 pad31[0x23];
} E_Map_UpdateEnemySpawns_0_001B43A0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } AF;
typedef struct { u8 pad[0x5A0]; AF f; } A_Map_UpdateEnemySpawns_0_001B43A0;
typedef struct { A_Map_UpdateEnemySpawns_0_001B43A0 **x0; s32 x4; } S_Map_UpdateEnemySpawns_0_001B43A0;
typedef struct { u8 pad[0xC4]; u8 xC4; } P158;
typedef struct {
    s32 x0;
    u8 pad4[0xC];
    Vec x10;
    u8 pad20[0x50];
    u16 x70;
    u8 pad72[0x1E];
    u32 x90[2];
    u32 x98[2];
    u32 xA0[2];
    u32 xA8;
    u8 padAC[0x90];
    E_Map_UpdateEnemySpawns_0_001B43A0 *x13C;
    u8 pad140[0x18];
    P158 *x158;
    u8 pad15C[0x20];
    S_Map_UpdateEnemySpawns_0_001B43A0 *x17C;
} O_Map_UpdateEnemySpawns_0_001B43A0;
typedef struct { s32 **obj; } P8_Map_UpdateBones_0_001B4AF0;
typedef struct { u8 pad[0x178]; P8_Map_UpdateBones_0_001B4AF0 *x178; } S_Map_UpdateBones_0_001B4AF0;
typedef struct { u8 pad[0x30]; f32 v[4]; } T_Map_SetOrigin_1_001B4BD0;
typedef struct {
    u8 pad[0x10];
    f32 v[3];
    s32 x1C;
    s32 x20;
    u8 pad24[0x154];
    T_Map_SetOrigin_1_001B4BD0 ***x178;
    u8 pad17C[0x5C];
    u8 b0:1;
} O_Map_SetOrigin_1_001B4BD0;
typedef struct O_Map_RecenterWorld_1_001B4CB0 { s8 pad0[0x10]; f32 pos[3]; s32 x1C; s32 x20; s8 pad24[0x154]; struct O_Map_RecenterWorld_1_001B4CB0 ***x178; s8 pad17C[0x5C]; u8 x1D8; } O_Map_RecenterWorld_1_001B4CB0;
typedef struct { s32 pad[3]; s32 c; } E_Map_ResetArea_1_001B4F20;
typedef struct {
    s32 pad0;
    s32 ***p4;
    s32 **p8;
    s32 padc[7];
    s32 o[15];
    s32 o64, o68;
    u16 n[11];
    u16 pad82;
    u8 pad84[0x134 - 0x84];
    s32 r[24];
    E_Map_ResetArea_1_001B4F20 *e;
} S_Map_ResetArea_1_001B4F20;
extern Mtx D_001F2170;
extern O_Map_DrawArea_0_001B37F0 **D_002022BC;
extern s32 D_002022B8;
extern Big D_0030D0E0;
extern O_Map_UpdateEnemySpawns_0_001B43A0 **D_00201E88[2];
extern s32 D_00201E80;
extern s32 D_002022C0;
extern f32 D_004B4BD0[];
extern O_Map_UpdateSfxVisibility_0_001B41C0 **D_002022BC__as_Map_UpdateSfxVisibility_0_001B41C0;
extern s32 D_001F2170__as_Map_UpdateBones_0_001B4AF0[];
extern s32 D_001F2170__as_Map_UpdateArea_0_001B4B50[];
extern f32 gZeroVec_003139A0__as_Map_RecenterWorld_1_001B4CB0[];
s32 MapColl_SphereCastAll_0_001B34B0(s8 *o, s8 *out, s32 p2, u8 f1, u8 f2);
void Map_GetNodeTransform_0_001B3710(H_Map_GetNodeTransform_0_001B3710 *h, B *base, s32 i, Vec *v, Mtx *m);
void Map_DrawArea_0_001B37F0(O_Map_DrawArea_0_001B37F0 *o, s32 (*cb)(s32 **, Key));
s32 Map_FilterOpaque_0_001B3F30(void *a, H_Map_FilterOpaque_0_001B3F30 h);
s32 Map_FilterTranslucent_0_001B3F80(void *a, H_Map_FilterTranslucent_0_001B3F80 h);
void Map_Draw_1_001B3FD0(O_Map_Draw_1_001B3FD0 *o);
void Map_UpdateTexAnim_0_001B40B0(Obj *o);
s32 Map_GetFogEntry_0_001B40F0(void *arg0, s32 arg1);
void Map_UpdateFog_0_001B4100(A_Map_UpdateFog_0_001B4100 *a);
void Map_UpdateSfxVisibility_0_001B41C0(O_Map_UpdateSfxVisibility_0_001B41C0 *o);
void Map_UpdateEnemySpawns_0_001B43A0(O_Map_UpdateEnemySpawns_0_001B43A0 *o);
void Map_UpdateBones_0_001B4AF0(S_Map_UpdateBones_0_001B4AF0 *a);
void Map_UpdateArea_0_001B4B50(u8 *arg0, f32 f);
void Map_SetOrigin_1_001B4BD0(O_Map_SetOrigin_1_001B4BD0 *o, f32 *v);
void Map_ResetArea_1_001B4F20(S_Map_ResetArea_1_001B4F20 *a);
void Map_CopyOrigin_0_001B51E0(u8 *obj, f32 *v);
s8* Mdl_GetFrameData_0_001715B0(s32);
s32 Coll_SphereVsMesh_1_0014E680(s8 *, s8 *, s32, s32, s8 *, u8, s32);
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(void *, void *);
void Mtx_Compose_2_00173FD0(Mtx *, f32 *, f32 *, f32 *);
void Player_GetHeadPos_0_001C93A0(Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
s8* Map_FindSfxEntry_0_001B7300(O_Map_DrawArea_0_001B37F0 *, s32);
void Light_CopyColor_0_0015B6B0(Vec *, s8 *);
void Fog_SetReg_0_0015B1C0(Vec *, s8 *);
void sceVu0ApplyMatrix(Vec *, f32 *, Vec *);
void Mdl_DrawLitWrap_0_0016B960(s8 *, Big *, Vec *, f32 *, s32, s32);
void Mdl_DrawMeshesD_1_0016D830(s32, s32 *, s8 *, s32, Key);
void MapObj_DrawAll_0_001B8A60(O_Map_DrawArea_0_001B37F0 *, s32 (*)(s32 **, Key), u32, u32, s16);
void Mdl_SetLayerForMesh_0_0016B360(void *a, H_Map_FilterOpaque_0_001B3F30 h, s32 c);
void Fog_BuildPlanes_0_0015CD30(A0 *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *);
void Sfx_SetFlag_0_00167640(s8 *, s32);
u32 MapState_GetCounter_0_001AA1E0(s32, s16);
void Player_GetPos_1_001C9410(Vec *);
f32 fabsf(f32);
A_Map_UpdateEnemySpawns_0_001B43A0** EnemyData_Alloc_0_001A7D90(u16);
void Enemy_SetPartModel_0_001A6FF0(A_Map_UpdateEnemySpawns_0_001B43A0 *, O_Map_UpdateEnemySpawns_0_001B43A0 **, u16);
s32 Enemy_Get5B2b3_1_0013E830(A_Map_UpdateEnemySpawns_0_001B43A0 *);
void Enemy_Despawn_0_001A6C10(A_Map_UpdateEnemySpawns_0_001B43A0 *);
void Enemy_Respawn_1_001A6C90(A_Map_UpdateEnemySpawns_0_001B43A0 *);
u32 Rand_Next_3_0015ED20(void);
void Mdl_UpdateBoneMatricesCur_0_00171540(s32 *, s32 *);
void MapObj_ResetBones_0_001BAAA0(S_Map_UpdateBones_0_001B4AF0 *);
void Script_RunAll_1_00166CC0(s32);
void MapObj_UpdateAll_0_001BAB70(u8 *, f32);
void sceVu0ScaleVector(f32, f32 *, f32 *);
void ActorList_TranslateAll_1_001A5CD0(f32 *);
void ItemObj_UpdateTransforms_0_001AC4A0(f32 *);
void ScreenFx_SetFadeColor_0_00159460(f32 *);
void Light_OffsetAll_0_0015B110(f32 *);
void PointLight_OffsetAll_0_0015C620(f32 *);
void Map_GetNodeTransform_0_001B3710__as_Map_DrawArea_0_001B37F0(s32, s8 *, s32, Vec *, f32 *);
void sceVu0CopyVector__as_Map_DrawArea_0_001B37F0(Vec *, Vec *);
void Mdl_SetLayerForMesh_0_0016B360__as_Map_FilterTranslucent_0_001B3F80(void *a, H_Map_FilterTranslucent_0_001B3F80 h, s32 c);
void Map_DrawArea_0_001B37F0__as_Map_Draw_1_001B3FD0(O_Map_Draw_1_001B3FD0 *, void *);
s32 Map_FilterOpaque_0_001B3F30__as_Map_Draw_1_001B3FD0();
s32 Map_FilterTranslucent_0_001B3F80__as_Map_Draw_1_001B3FD0();
void Mdl_UpdateBoneMatricesCur_0_00171540__as_Map_UpdateArea_0_001B4B50(s32, s32 *);
void Map_UpdateSfxVisibility_0_001B41C0__as_Map_UpdateArea_0_001B4B50(u8 *);
void Map_UpdateEnemySpawns_0_001B43A0__as_Map_UpdateArea_0_001B4B50(u8 *);
void sceVu0CopyVector__as_Map_SetOrigin_1_001B4BD0(f32 *, f32 *);
void sceVu0CopyVector__as_Map_RecenterWorld_1_001B4CB0(f32 *, f32 *);
void sceVu0CopyVector__as_Map_CopyOrigin_0_001B51E0(f32 *v0, f32 *v1);

/* MapColl_SphereCastAll_0_001B34B0 */
s32 MapColl_SphereCastAll_0_001B34B0(s8 *o, s8 *out, s32 p2, u8 f1, u8 f2) {
    s8 *s3;
    s8 *c;
    s32 i;
    s32 found;
    s8 *v;
    s8 *e;
    s8 *tbl;
    s32 a2;
    s8 *ent;
    u32 k;

    found = 0;
    if (!f1 || o == NULL) return 0;
    if (((BF *)(o + 0x1D8))->b1 || !((BF *)(o + 0x1D8))->b0) return 0;
    if (*(s8 ***)(o + 4) == NULL || (c = **(s8 ***)(o + 4)) == NULL) return 0;
    e = *(s8 **)(o + 0x134);
    s3 = *(s8 **)(o + 0x178);
    tbl = (s8 *)((u32)c + 0x40 + *(u16 *)(c + 0x14) * 16 + *(u16 *)(c + 0x16) * 8 + *(u16 *)(c + 0x18) * 4);
    a2 = **(s32 **)(c + 0x10);
    v = Mdl_GetFrameData_0_001715B0(*(s32 *)s3);
    if (v == NULL || *(u16 *)(c + 0x1C) == 0) return 0;
    for (i = 0; i < *(u16 *)(o + 0x6C); i++, e += 0x30, s3 += 8) {
        if (*(s16 *)(e + 0x1A) != -1 && ((BF *)(s3 + 4))->b0 && !((BF *)(s3 + 4))->b1) {
            k = *(u8 *)(v + i * 0x140 + 0x332);
            if (k != 0xFF && k < *(u16 *)(c + 0x1C)) {
                ent = tbl + k * 0x50;
                if (*(s32 *)ent != 0 && *(s32 *)(ent + 8) != 0 &&
                    Coll_SphereVsMesh_1_0014E680(out, ent, a2, p2, v + (i + 1) * 0x140 + 0xC0, f1, 1) != 0) {
                    *(s8 **)(out + 0x20) = c;
                    *(s32 *)(out + 0x3C) = i;
                    *(s8 **)(out + 0x30) = o;
                    *(s32 *)(out + 0x38) = 0;
                    *(s32 *)(out + 0x34) = 0;
                    found = 1;
                    if (f2) return found;
                }
            }
        }
    }
    return found;
}

/* Map_GetNodeTransform_0_001B3710 */
#define Mdl_GetFrameData_0_001715B0 Mdl_GetFrameData_0_001715B0__as_Map_GetNodeTransform_0_001B3710
s8* Mdl_GetFrameData_0_001715B0__as_Map_GetNodeTransform_0_001B3710(s32 **);

/* Map_GetNodeTransform_0_001B3710 */
void Map_GetNodeTransform_0_001B3710(H_Map_GetNodeTransform_0_001B3710 *h, B *base, s32 i, Vec *v, Mtx *m) {
    Ent *t;
    El_Map_GetNodeTransform_0_001B3710 *el;
    u8 *p;
    s32 e;
    u8 b;
    t = h->t;
    el = &base->el[i];
    p = *h->p;
    b = el->b;
    if (b == 0xFF) {
        sceVu0CopyVector(v, &gZeroVec_003139A0);
        sceVu0CopyMatrix(m, &D_001F2170);
    } else {
        e = (s32)p + t[b].off;
        if (*(u8 *)(e + 0xF) & 1) {
            sceVu0CopyVector(v, (void *)(e + 0x10));
            sceVu0CopyMatrix(m, el);
        } else {
            sceVu0CopyVector(v, &gZeroVec_003139A0);
            sceVu0CopyMatrix(m, &D_001F2170);
        }
    }
}

/* Map_DrawArea_0_001B37F0 */
struct O_Map_DrawArea_0_001B37F0 {
    u8 pad0[0x6C];
    u16 n;
    u8 pad6E[0x88 - 0x6E];
    u16 x88;
    u8 pad8A[2];
    s16 x8C;
    s16 x8E;
    u8 pad90[0x134 - 0x90];
    E_Map_DrawArea_0_001B37F0 *x134;
    u8 pad138[0x154 - 0x138];
    u32 *x154;
    u8 pad158[0x178 - 0x158];
    P8_Map_DrawArea_0_001B37F0 *x178;
    u8 pad17C[0x188 - 0x17C];
    Big *x188;
    u8 pad18C[0x1D8 - 0x18C];
    Flags8 f1D8;
};
static inline f32 u2f_Map_DrawArea_0_001B37F0(u32 x) { return x; }
static inline void mk(E_Map_DrawArea_0_001B37F0 *e, N *s1, s32 i, s32 j) {
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    u32 k;
    for (k = 0; k < 3; k++) {
        pos[k] = ((f32 *)e)[k];
        rot[k] = 0.00024414062f * ((s16 *)e)[k + 6];
        scl[k] = 0.00024414062f * u2f_Map_DrawArea_0_001B37F0(((u16 *)e)[k + 9]);
    }
    pos[3] = 1.0f;
    rot[3] = 0.0f;
    scl[3] = 1.0f;
    Mtx_Compose_2_00173FD0(&((El_Map_DrawArea_0_001B37F0 *)s1)[i + 1].m[j], pos, rot, scl);
}
static inline void mk2(E_Map_DrawArea_0_001B37F0 *e, N *s1, s32 i, s32 j) {
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    s32 k;
    for (k = 0; k < 3; k++) {
        pos[k] = (&e->x)[k];
        rot[k] = 0.00024414062f * (&e->rx)[k];
        scl[k] = 0.00024414062f * u2f_Map_DrawArea_0_001B37F0((&e->sx)[k]);
    }
    pos[3] = 1.0f;
    rot[3] = 0.0f;
    scl[3] = 1.0f;
    Mtx_Compose_2_00173FD0(&((El_Map_DrawArea_0_001B37F0 *)s1)[i + 1].m[j], pos, rot, scl);
}

void Map_DrawArea_0_001B37F0(O_Map_DrawArea_0_001B37F0 *o, s32 (*cb)(s32 **, Key)) {
    u32 *tb;
    u32 m1;
    u32 m2;
    u32 m3;
    s16 id;
    s32 c0;
    s32 k;
    s32 **fp;
    s32 i;
    N *s1;
    E_Map_DrawArea_0_001B37F0 *e;
    P8_Map_DrawArea_0_001B37F0 *p;
    O_Map_DrawArea_0_001B37F0 *a;
    s16 j;
    u32 bit;
    s8 *r;
    s32 s4;
    El_Map_DrawArea_0_001B37F0 *b;
    Key key;
    Vec V;
    Vec X;
    Vec D;
    f32 B[12];
    Vec A;
    Vec C;

    tb = o->x154;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    if (!o->f1D8.f.b0) return;
    id = o->x8C;
    if (o->x8E != -2) id = o->x8E;
    k = id;
    if (k != -1) m1 = tb[k];
    if (D_002022BC != 0 && (a = *D_002022BC) != 0 && a != o) {
        j = a->x8C;
        if (a->x8E != -2) j = a->x8E;
        if (j != -1) m2 = a->x154[j + 0x20];
    }
    fp = o->x178->h;
    s1 = (N *)Mdl_GetFrameData_0_001715B0(fp);
    e = o->x134;
    p = o->x178;
    c0 = **(s32 **)*fp;
    for (i = 0; i < o->n; i++, e++, p++) {
        key.w = e->x2C.w;
        if (e->x18 == -1) continue;
        if (e->f28.f.b0) continue;
        if (!p->f.f.b0) continue;
        e->f28.f.b4 = 0;
        if (k == -1) {
            if (!key.f.b.f.b5) continue;
            if (e->x24 != 0 && D_002022B8 != e->x24) continue;
            bit = 1 << e->x20;
            if (!(m2 & bit)) continue;
        } else {
            bit = 1 << e->x20;
            if (!(m1 & bit)) continue;
        }
        m3 |= bit;
        e->f28.f.b4 = 1;
        if (cb(fp, key) != 0) continue;
        if (e->f28.f.b2) {
            mk(e, s1, i, 5);
            mk2(e, s1, i, 3);
            b = &((El_Map_DrawArea_0_001B37F0 *)s1)[i + 1];
            Player_GetHeadPos_0_001C93A0(&V);
            sceVu0AddVector(&(&b[1].m[0])->m[3], &(&b[1].m[0])->m[3], &V);
            sceVu0AddVector(&(&b->m[3])->m[3], &(&b->m[3])->m[3], &V);
            ((El_Map_DrawArea_0_001B37F0 *)s1)[i + 2].m[0].m[3].w = 1.0f;
            ((El_Map_DrawArea_0_001B37F0 *)s1)[i + 1].m[3].m[3].w = 1.0f;
        }
        r = e->f28.f.b5 ? Map_FindSfxEntry_0_001B7300(o, e->x25) : 0;
        if (r != 0) {
            Light_CopyColor_0_0015B6B0(&X, r + 0x20);
            Fog_SetReg_0_0015B1C0(&X, r + 0x10);
        } else {
            Fog_ApplyDefault_0_0015B270();
        }
        s4 = e->x21;
        Map_GetNodeTransform_0_001B3710__as_Map_DrawArea_0_001B37F0(c0, (s8 *)s1, i + 1, &A, B);
        sceVu0CopyVector__as_Map_DrawArea_0_001B37F0(&C, &D);
        sceVu0CopyVector__as_Map_DrawArea_0_001B37F0(&D, &gZeroVec_003139A0);
        {
            f32 w;
            D.w = 1.0f;
            w = A.w;
            A.w = 1.0f;
            sceVu0ApplyMatrix(&A, B, &A);
            A.w = w;
        }
        sceVu0CopyVector__as_Map_DrawArea_0_001B37F0(&D, &C);
        if ((s8)s4 == -1) {
            Mdl_DrawLitWrap_0_0016B960((s8 *)s1, &D_0030D0E0, &A, B, 0xC, 0);
        } else {
            Mdl_DrawLitWrap_0_0016B960((s8 *)s1, &o->x188[(s8)s4], &A, B, 0xC, 0);
        }
        Mdl_DrawMeshesD_1_0016D830(**(s32 **)*fp, *fp, (s8 *)s1, i + 1, key);
        o->x88++;
    }
    GsPkt_CloseChain_1_001549D0();
    MapObj_DrawAll_0_001B8A60(o, cb, m1, m3, id);
}

/* Map_FilterOpaque_0_001B3F30 */
s32 Map_FilterOpaque_0_001B3F30(void *a, H_Map_FilterOpaque_0_001B3F30 h)
{
    if (!h.f)
        return 1;
    Mdl_SetLayerForMesh_0_0016B360(a, h, 0);
    return 0;
}

/* Map_FilterTranslucent_0_001B3F80 */

s32 Map_FilterTranslucent_0_001B3F80(void *a, H_Map_FilterTranslucent_0_001B3F80 h)
{
    if (h.f)
        return 1;
    Mdl_SetLayerForMesh_0_0016B360__as_Map_FilterTranslucent_0_001B3F80(a, h, 3);
    return 0;
}

/* Map_Draw_1_001B3FD0 */
static inline f32 u2f_Map_Draw_1_001B3FD0(u32 x) { return x; }

void Map_Draw_1_001B3FD0(O_Map_Draw_1_001B3FD0 *o) {
    o->x88 = 0;
    o->x8A = 0;
    if (!o->x1D8.b2 && !o->x1D8.b3) {
    Gfx_SetFogScale_0_001541E0(u2f_Map_Draw_1_001B3FD0(o->x158->xBA));
    if (o->x158->xBC & 1) Map_DrawArea_0_001B37F0__as_Map_Draw_1_001B3FD0(o, Map_FilterOpaque_0_001B3F30__as_Map_Draw_1_001B3FD0);
    Map_DrawArea_0_001B37F0__as_Map_Draw_1_001B3FD0(o, Map_FilterTranslucent_0_001B3F80__as_Map_Draw_1_001B3FD0);
    Mdl_FlushLayer_0_0016B280();
    if (o->x20) o->x20--;
    }
}

/* Map_UpdateTexAnim_0_001B40B0 */
void Map_UpdateTexAnim_0_001B40B0(Obj *o)
{
    u32 v = o->t->h;
    Gfx_SetFogScale_0_001541E0(v);
}

/* Map_GetFogEntry_0_001B40F0 */
s32 Map_GetFogEntry_0_001B40F0(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 0x144) + (arg1 << 7);
}

/* Map_UpdateFog_0_001B4100 */
void Map_UpdateFog_0_001B4100(A_Map_UpdateFog_0_001B4100 *a) {
    s32 i;
    for (i = 0; i < a->n74; i++) {
        V8 *q = &a->x144[i];
        Fog_BuildPlanes_0_0015CD30(&a->x188[i], &q->v[0], &q->v[2], &gZeroVec_003139A0, &gZeroVec_003139A0, &q->v[1], &q->v[3], &gZeroVec_003139A0, &gZeroVec_003139A0, &q->v[5], &q->v[4]);
    }
}

/* Map_UpdateSfxVisibility_0_001B41C0 */

void Map_UpdateSfxVisibility_0_001B41C0(O_Map_UpdateSfxVisibility_0_001B41C0 *o) {
    E_Map_UpdateSfxVisibility_0_001B41C0 *e;
    s32 m1;
    s32 m2;
    s32 i;
    Slot *s;
    s32 off1;
    s32 off2;
    s32 idx;
    O_Map_UpdateSfxVisibility_0_001B41C0 *p;
    s32 *t;
    s16 k;

    m2 = 0;
    m1 = 0;
    if (o != NULL && o->f0) {
        t = o->tbl;
        k = o->i8C;
        if (o->i8E != -2) {
            k = o->i8E;
        }
        idx = k;
        if (idx != -1) {
            m1 = t[idx];
        }
        if (D_002022BC__as_Map_UpdateSfxVisibility_0_001B41C0 != NULL && (p = *D_002022BC__as_Map_UpdateSfxVisibility_0_001B41C0) != NULL && p != o && p->i8C != -1) {
            m2 = p->tbl[p->i8C + 0x20];
        }
        i = 0;
        if (0 < o->n) {
            off1 = 0;
            off2 = 0;
            do {
            e = (E_Map_UpdateSfxVisibility_0_001B41C0 *)((s8 *)o->elems + off1);
            s = (Slot *)((s8 *)o->slots + off2);
            if (s->p != NULL && !s->b1) {
                Sfx_SetFlag_0_00167640(s->p, 0);
                if (e->bit < 0x20) {
                    if (idx == -1) {
                        if (!(m2 & (1 << e->bit))) {
                        } else {
                            goto on;
                        }
                    } else if (!(m1 & (1 << e->bit))) {
                    } else {
                        goto on;
                    }
                } else if (idx != -1) {
on:
                    Sfx_SetFlag_0_00167640(s->p, 1);
                }
            }
            i++;
            off1 += 0x2C;
            off2 += 8;
            } while (i < o->n);
        }
    }
}

/* Map_UpdateEnemySpawns_0_001B43A0 */
static inline f32 u2f_Map_UpdateEnemySpawns_0_001B43A0(u32 x) { return x; }

static inline s32 inr(E_Map_UpdateEnemySpawns_0_001B43A0 *e, O_Map_UpdateEnemySpawns_0_001B43A0 *o, u16 *r) {
    Vec pos;
    Vec cam;
    volatile f32 h;
    f32 d;
    s32 k;
    Player_GetPos_1_001C9410(&cam);
    for (k = 0; k < 3; k++) (&pos.x)[k] = (&e->x)[k];
    pos.w = 1.0f;
    sceVu0AddVector(&pos, &pos, &o->x10);
    h = fabsf(pos.y - cam.y);
    d = Vec_DistXZ_2_0015DEE0(&pos, &cam);
    if (u2f_Map_UpdateEnemySpawns_0_001B43A0(r[0]) < d) goto no;
    if (r[1] == 0) goto yes;
    if (h <= u2f_Map_UpdateEnemySpawns_0_001B43A0(r[1])) goto yes;
no:
    return 0;
yes:
    return 1;
}

void Map_UpdateEnemySpawns_0_001B43A0(O_Map_UpdateEnemySpawns_0_001B43A0 *o) {
    s32 idx;
    s32 i;
    E_Map_UpdateEnemySpawns_0_001B43A0 *e;
    S_Map_UpdateEnemySpawns_0_001B43A0 *s;
    u32 k;
    u32 j;
    u32 mask;
    u32 *w;
    E_Map_UpdateEnemySpawns_0_001B43A0 *e2;
    A_Map_UpdateEnemySpawns_0_001B43A0 *a;
    u32 m2;
    u32 j2;
    S_Map_UpdateEnemySpawns_0_001B43A0 *s2;
    u32 *w2;

    idx = -1;
    if (D_00201E88[0] && *D_00201E88[0] == o) idx = 0;
    if (D_00201E88[1] && *D_00201E88[1] == o) idx = 1;
    for (i = 0; i < o->x70; i++) {
        e = &o->x13C[i];
        s = &o->x17C[i];
        k = e->x1A % 100;
        j = k >> 5;
        mask = 1 << (k & 31);
        if (MapState_GetCounter_0_001AA1E0(o->x0, k) < e->x2C) {
            w = &o->x90[j];
            if (!(*w & mask) && inr(e, o, &e->x1E)) {
                s->x4 = Frame_IncCounter_1_0015C9E0();
                s->x0 = EnemyData_Alloc_0_001A7D90(e->x18);
                Enemy_SetPartModel_0_001A6FF0(*s->x0, D_00201E88[idx], i);
                *w |= mask;
            }
        }
    }
    for (i = 0; i < o->x70; i++) {
        e2 = &o->x13C[i];
        s2 = &o->x17C[i];
        k = e2->x1A % 100;
        j2 = k >> 5;
        m2 = 1 << (k & 31);
        if (s2->x0 == 0) continue;
        a = *s2->x0;
        if (a == 0) continue;
        if (!a->f.b0) continue;
        if (a->f.b0 && a->f.b2) {
            if ((u8)Enemy_Get5B2b3_1_0013E830(a) == 1) {
                Enemy_Despawn_0_001A6C10(a);
                if (!e2->x30.b3 && o->xA8) o->xA8--;
                o->x98[j2] |= m2;
            } else if (!e2->x30.b3 && !inr(e2, o, &e2->x1E)) {
                Enemy_Despawn_0_001A6C10(a);
                if (o->xA8) o->xA8--;
                o->x98[j2] |= m2;
            }
        } else if (MapState_GetCounter_0_001AA1E0(o->x0, k) < e2->x2C) {
            if (e2->x30.t != 2 || (o->xA0[j2] & m2)) {
                if (inr(e2, o, &e2->x26)) {
                    if (!e2->x30.b3 && !(o->xA8 < o->x158->xC4)) {
                        if (!e2->x30.b4) o->x98[j2] |= m2;
                    } else if (e2->x30.t == 1) {
                        Enemy_Respawn_1_001A6C90(a);
                        if (!e2->x30.b3) o->xA8++;
                    } else {
                        w2 = &o->x98[j2];
                        if (!(*w2 & m2)) {
                            if (Rand_Next_3_0015ED20() % 100 < e2->x2A) {
                                Enemy_Respawn_1_001A6C90(a);
                                if (!e2->x30.b3) o->xA8++;
                            }
                            *w2 |= m2;
                        }
                    }
                } else {
                    o->x98[j2] &= ~m2;
                }
            }
        }
    }
}

/* Map_UpdateBones_0_001B4AF0 */
void Map_UpdateBones_0_001B4AF0(S_Map_UpdateBones_0_001B4AF0 *a) {
    if (a == NULL || a->x178 == NULL) return;
    Mdl_UpdateBoneMatricesCur_0_00171540(*a->x178->obj, D_001F2170__as_Map_UpdateBones_0_001B4AF0);
    MapObj_ResetBones_0_001BAAA0(a);
}

/* Map_UpdateArea_0_001B4B50 */
void Map_UpdateArea_0_001B4B50(u8 *arg0, f32 f) {
    s32 *t;
    Mdl_UpdateBoneMatricesCur_0_00171540__as_Map_UpdateArea_0_001B4B50(***(s32 ***)(arg0 + 0x178), D_001F2170__as_Map_UpdateArea_0_001B4B50);
    MapObj_UpdateAll_0_001BAB70(arg0, f);
    Map_UpdateEnemySpawns_0_001B43A0__as_Map_UpdateArea_0_001B4B50(arg0);
    Map_UpdateSfxVisibility_0_001B41C0__as_Map_UpdateArea_0_001B4B50(arg0);
    t = *(s32 **)(arg0 + 0xC);
    if (t != NULL) Script_RunAll_1_00166CC0(*t);
}

/* Map_SetOrigin_1_001B4BD0 */
static inline f32 diff_Map_SetOrigin_1_001B4BD0(f32 *a, f32 *b) {
    f32 d;
    if ((d = a[0] - b[0]) != 0.0f) return d;
    if ((d = a[1] - b[1]) != 0.0f) return d;
    d = a[2] - b[2];
    return d != 0.0f ? d : 0.0f;
}

void Map_SetOrigin_1_001B4BD0(O_Map_SetOrigin_1_001B4BD0 *o, f32 *v) {
    if (diff_Map_SetOrigin_1_001B4BD0(o->v, v) != 0.0f) {
        sceVu0CopyVector__as_Map_SetOrigin_1_001B4BD0(o->v, v);
        o->x1C = 0;
        o->x20 = 2;
        if (o->b0) {
            sceVu0CopyVector__as_Map_SetOrigin_1_001B4BD0((**o->x178)->v, o->v);
        }
    }
}

/* Map_RecenterWorld_1_001B4CB0 */
static inline f32 diff_Map_RecenterWorld_1_001B4CB0(f32 *a, f32 *b) {
    f32 d;
    if ((d = a[0] - b[0]) != 0.0f) return d;
    if ((d = a[1] - b[1]) != 0.0f) return d;
    d = a[2] - b[2];
    return d != 0.0f ? d : 0.0f;
}

void Map_RecenterWorld_1_001B4CB0(void) {
    f32 v[4];
    s32 side;
    O_Map_RecenterWorld_1_001B4CB0 **pp;
    O_Map_RecenterWorld_1_001B4CB0 *o;

    side = !(&D_00201E80)[1];
    if (D_002022C0 != 0) {
        sceVu0CopyVector__as_Map_RecenterWorld_1_001B4CB0(v, D_004B4BD0);
        o = *((O_Map_RecenterWorld_1_001B4CB0 ***)(&D_00201E80 + 2))[side];
        if (diff_Map_RecenterWorld_1_001B4CB0(o->pos, gZeroVec_003139A0__as_Map_RecenterWorld_1_001B4CB0) != 0.0f) {
            sceVu0CopyVector__as_Map_RecenterWorld_1_001B4CB0(o->pos, gZeroVec_003139A0__as_Map_RecenterWorld_1_001B4CB0);
            o->x1C = 0;
            o->x20 = 2;
            if (o->x1D8 & 1) {
                sceVu0CopyVector__as_Map_RecenterWorld_1_001B4CB0((f32 *)((s8 *)**o->x178 + 0x30), o->pos);
            }
        }
        sceVu0ScaleVector(-1.0f, v, v);
        pp = ((O_Map_RecenterWorld_1_001B4CB0 ***)(&D_00201E80 + 2))[!side];
        if (pp != 0) {
            o = *pp;
            if (diff_Map_RecenterWorld_1_001B4CB0(o->pos, v) != 0.0f) {
                sceVu0CopyVector__as_Map_RecenterWorld_1_001B4CB0(o->pos, v);
                o->x1C = 0;
                o->x20 = 2;
                if (o->x1D8 & 1) {
                    sceVu0CopyVector__as_Map_RecenterWorld_1_001B4CB0((f32 *)((s8 *)**o->x178 + 0x30), o->pos);
                }
            }
        }
        ActorList_TranslateAll_1_001A5CD0(v);
        ItemObj_UpdateTransforms_0_001AC4A0(v);
        Sfx_OffsetAll_1_00167850(v);
        ScreenFx_SetFadeColor_0_00159460(v);
        Light_OffsetAll_0_0015B110(v);
        PointLight_OffsetAll_0_0015C620(v);
        Glow_OffsetAll_0_0015D5A0(v);
        SndEmit_OffsetPositions_1_0012F7E0(v);
        D_002022C0 = -1;
    }
}

/* Map_ResetArea_1_001B4F20 */
void Map_ResetArea_1_001B4F20(S_Map_ResetArea_1_001B4F20 *a) {
    s32 base;
    s32 p;
    s32 i;
    base = *(*a->p4)[4];
    if (a->n[0]) a->r[0] = base + a->o[0];
    if (a->n[1]) a->r[1] = base + a->o[1];
    if (a->n[2]) a->r[2] = base + a->o[2];
    if (a->n[3]) a->r[3] = base + a->o[3];
    if (a->n[4]) a->r[4] = base + a->o[4];
    if (a->n[5]) a->r[5] = base + a->o[5];
    if (a->n[7]) a->r[6] = base + a->o[6];
    if (a->n[6]) a->r[7] = base + a->o[8];
    if (a->n[8]) a->r[13] = base + a->o[11];
    if (a->n[9]) a->r[14] = base + a->o[12];
    a->r[11] = a->o64 ? base + a->o64 : 0;
    a->r[12] = a->o68 ? base + a->o68 : 0;
    a->r[8] = base + a->o[9];
    a->r[9] = base + a->o[10];
    a->r[15] = base + a->o[13];
    a->r[16] = a->o[14] ? base + a->o[14] : 0;
    a->r[10] = a->r[9] + 0x36;
    p = (s32)*a->p8;
    if (a->n[0]) a->r[17] = p;
    p += a->n[0] * 8;
    if (a->n[2]) a->r[18] = p;
    p += a->n[2] * 8;
    if (a->n[3]) a->r[20] = p;
    p += a->n[3] * 8; p = (p + 0xF) & ~0xF;
    if (a->n[1]) a->r[19] = p;
    p += a->n[1] * 0x80; p = (p + 0xF) & ~0xF;
    if (a->n[4]) a->r[21] = p;
    p += a->n[4] * 0xA0;
    if (a->n[5]) a->r[22] = p;
    p += a->n[5] * 4;
    if (a->n[6]) a->r[23] = p;
    p += a->n[6] * 8;
    if (a->n[10]) a->e = (E_Map_ResetArea_1_001B4F20 *)p;
    for (i = 0; i < a->n[10]; i++) {
        E_Map_ResetArea_1_001B4F20 *q = &a->e[i];
        q->pad[2] = *(*a->p4)[4] + q->c;
    }
}

/* Map_CopyOrigin_0_001B51E0 */

void Map_CopyOrigin_0_001B51E0(u8 *obj, f32 *v)
{
    sceVu0CopyVector__as_Map_CopyOrigin_0_001B51E0(v, (f32 *)(obj + 0x10));
}
#undef Mdl_GetFrameData_0_001715B0
