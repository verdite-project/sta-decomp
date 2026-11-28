#include "m2c.h"
#include "common.h"
#include "game/core.h"
#include "game/effect.h"
#include "game/gfx.h"
#include "game/map.h"
#include "game/save.h"
#include "game/sound.h"
#include "game/data.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F_Map_FreeArea_1_001B5640;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x28]; F_Map_FreeArea_1_001B5640 f3C; } M_Map_FreeArea_1_001B5640;
typedef struct { M_Map_FreeArea_1_001B5640 *m; } O_Map_FreeArea_1_001B5640;
typedef struct { u8 pad[0x40]; s32 x40; s32 x44; u8 pad48[0xC]; s32 x54; u8 pad58[0x28]; } E_Map_FreeArea_1_001B5640;
typedef struct { s32 p; s32 pad; } P8_Map_FreeArea_1_001B5640;
typedef struct {
    s32 pad0;
    O_Map_FreeArea_1_001B5640 *o;
    s32 x8;
    s32 xC;
    u8 pad10[0x14];
    s32 x24;
    u8 pad28[0x46];
    u16 n6E;
    u16 n70;
    u8 pad72[4];
    u16 n76;
    u16 n78;
    u8 pad7A[8];
    u16 n82;
    u8 pad84[0x30];
    u8 xB4[0xC4];
    s32 *x178;
    P8_Map_FreeArea_1_001B5640 *x17C;
    E_Map_FreeArea_1_001B5640 *x180;
    u8 pad184[8];
    s32 *x18C;
    P8_Map_FreeArea_1_001B5640 *x190;
    u8 pad194[4];
    s32 x198[16];
    u8 f1D8;
} S_Map_FreeArea_1_001B5640;
typedef struct { f32 v[4]; s32 x10; u8 b14; char p15[3]; s32 x18; } Out;
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; } E_Map_BuildNodeMatrix_0_001B5B30;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } F_Map_SpawnSfx_0_001B5CA0;
typedef struct { u8 pad[0x10]; s32 x10; } M_Map_SpawnSfx_0_001B5CA0;
typedef struct { M_Map_SpawnSfx_0_001B5CA0 *m; } O_Map_SpawnSfx_0_001B5CA0;
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; u16 id; u8 pad1A[0x10]; F_Map_SpawnSfx_0_001B5CA0 f; u8 pad2B; } E_Map_SpawnSfx_0_001B5CA0;
typedef struct { s8 *obj; F_Map_SpawnSfx_0_001B5CA0 f; } P8_Map_SpawnSfx_0_001B5CA0;
typedef struct {
    s32 pad0;
    O_Map_SpawnSfx_0_001B5CA0 *o;
    u8 pad8[8];
    f32 x10[4];
    u8 pad20[0x58];
    u16 n78;
    u8 pad7A[0x3A];
    u8 xB4[0x9C];
    E_Map_SpawnSfx_0_001B5CA0 *x150;
    u8 pad154[0x3C];
    P8_Map_SpawnSfx_0_001B5CA0 *x190;
} S_Map_SpawnSfx_0_001B5CA0;
typedef struct { u8 pad[0x18]; s16 x18; u8 pad1A[6]; u8 x20; u8 pad21[7]; } E28;
typedef struct { s32 a; s32 b; } E8;
typedef struct { s32 v; s32 x; } E_Map_InitObjects_0_001B6130;
typedef struct { char pad[0x70]; u16 n; char p72[0x1E]; s32 a[7]; char pac[0xD0]; E_Map_InitObjects_0_001B6130 *e; } Obj;
extern S_Map_FreeArea_1_001B5640 **gPlayerSbss_002022BC;
extern s32 D_002022C4;
extern s32 gMapSbss_00201E88;
extern s32 gMapSbss_00201E8C;
extern s32 gSoundSbss_002022B8;
void Map_FreeArea_1_001B5640(S_Map_FreeArea_1_001B5640 **a0);
void Map_FreeAll_1_001B5940(void);
void Map_DecodeTransform_0_001B59E0(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg3);
void Map_BuildNodeMatrix_0_001B5B30(void *o, E_Map_BuildNodeMatrix_0_001B5B30 *e);
void Map_SpawnSfx_0_001B5CA0(S_Map_SpawnSfx_0_001B5CA0 *s);
void Map_SpawnItems_0_001B5FB0(s8 *arg0, s32 arg1);
void Map_InitObjects_0_001B6130(Obj *o);
void Pool_Free_2_00128580(s32, void *);
void Sfx_Release_1_00167030(s32);
void Sfx_RegisterList_0_00169D00(void *, s32);
void Mdl_Free_0_00170250(s32, O_Map_FreeArea_1_001B5640 *);
void Mdl_ReleaseTexAnims_0_00170E90(O_Map_FreeArea_1_001B5640 *);
void Tex_ReleaseList_0_00178030(s32);
void Enemy_Destroy_0_001A6A10(s32);
void ItemObj_FreeOwned_0_001AF740(S_Map_FreeArea_1_001B5640 **);
void Map_ResetArea_1_001B4F20(S_Map_FreeArea_1_001B5640 *);
void Mdl_DestroyInstance_0_001745D0(s32, s32);
s32 Map_StreamGetResult_1_001B0660(Out *o);
void Mtx_Compose_2_00173FD0(void *, f32 *, f32 *, f32 *);
void sceVu0CopyVector(f32*, void *);
void sceVu0AddVector(f32 *, f32 *, f32 *);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
s8* Sfx_SpawnFromStam_2_00169BD0(s32, s32, void *, s32, s32, s32);
void Sfx_SetMatrixOrAim_0_00167740(s8 *, void *);
s16 MapState_GetObjectPos_0_001A9900(s32, u32, f32 *, f32 *);
void ItemObj_SpawnThrown_0_001AEC00(s32, s16, f32 *, f32 *, f32 *);
s32 ItemObj_SpawnFromSource_0_001AF150(s32, E28 *, u16, f32 *);
s32 Inventory_CountItem_0_001CC0C0(s16, s32);
s32 Save_GetByte2E_0_001AA740(void);

/* Map_FreeArea_1_001B5640 */
void Map_FreeArea_1_001B5640(S_Map_FreeArea_1_001B5640 **a0) {
    S_Map_FreeArea_1_001B5640 *s;
    O_Map_FreeArea_1_001B5640 *o;
    s32 i;

    E_Map_FreeArea_1_001B5640 *e;

    if (a0 == NULL || (s = *a0) == NULL) {
        return;
    }
    o = s->o;
    if (gPlayerSbss_002022BC == a0) {
        gPlayerSbss_002022BC = NULL;
    }
    if (s->f1D8 & 1) {
        Map_ResetArea_1_001B4F20(*a0);
        for (i = 0; i < s->n6E; i++) {
            e = &s->x180[i];
            if (e->x54) {
                Sfx_Release_1_00167030(e->x54);
            }
            Mdl_DestroyInstance_0_001745D0(gMapAreaLoadSbss_002022D0, e->x40);
            if (e->x44) {
                Mdl_DestroyInstance_0_001745D0(gMapAreaLoadSbss_002022D0, e->x44);
            }
        }
        for (i = 0; i < s->n82; i++) {
            Enemy_Destroy_0_001A6A10(s->x198[i]);
        }
        for (i = 0; i < s->n70; i++) {
            if (s->x17C[i].p) {
                Enemy_Destroy_0_001A6A10(s->x17C[i].p);
            }
        }
        ItemObj_FreeOwned_0_001AF740(a0);
        for (i = 0; i < s->n78; i++) {
            if (s->x190[i].p) {
                Sfx_Release_1_00167030(s->x190[i].p);
            }
        }
        Sfx_RegisterList_0_00169D00(s->xB4, 0x20);
        for (i = 0; i < s->n76; i++) {
            Glow_Enable_0_0015DB60(s->x18C[i]);
        }
        Mdl_ReleaseTexAnims_0_00170E90(o);
        if (o->m->f3C.b4) {
            Tex_ReleaseList_0_00178030(o->m->x10);
        }
        Mdl_DestroyInstance_0_001745D0(gMapAreaLoadSbss_002022D0, *s->x178);
        if (s->xC) {
            Pool_Free_2_00128580(D_002022C4, (void *)s->xC);
        }
        Pool_Free_2_00128580(D_002022C4, (void *)s->x8);
    } else if (o) {
        Mdl_ReleaseTexAnims_0_00170E90(o);
        if (o->m->f3C.b4) {
            Tex_ReleaseList_0_00178030(o->m->x10);
        }
        Mdl_Free_0_00170250(gMapAreaLoadSbss_002022D0, o);
    } else if (s->x24) {
        Pool_Free_2_00128580(D_002022C4, (void *)s->x24);
    }
    Pool_Free_2_00128580(D_002022C4, a0);
}

/* Map_FreeAll_1_001B5940 */
#define Map_FreeArea_1_001B5640 Map_FreeArea_1_001B5640__as_Map_FreeAll_1_001B5940
void Map_FreeArea_1_001B5640__as_Map_FreeAll_1_001B5940(s32 h);

void Map_FreeAll_1_001B5940(void)
{
    Out t;
    Map_StreamGetResult_1_001B0660(&t);
    if (t.x18)
        Map_FreeArea_1_001B5640(t.x18);
    Map_StreamFlush_1_001B03E0();
    if (gMapSbss_00201E88) {
        PointLightGroup_Clear_0_0015C6D0(0);
        LightGroup_Clear_0_0015B890(0);
        Map_FreeArea_1_001B5640(gMapSbss_00201E88);
        gMapSbss_00201E88 = 0;
    }
    if (gMapSbss_00201E8C) {
        PointLightGroup_Clear_0_0015C6D0(1);
        LightGroup_Clear_0_0015B890(1);
        Map_FreeArea_1_001B5640(gMapSbss_00201E8C);
        gMapSbss_00201E8C = 0;
    }
    SndEmit_KillAll_1_0012F920();
    gSoundSbss_002022B8 = 0;
    MapSe_Flush_0_001E1CC0();
}
#undef Map_FreeArea_1_001B5640

/* Map_DecodeTransform_0_001B59E0 */
void Map_DecodeTransform_0_001B59E0(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    M2C_FIELD(arg1, f32 *, 0) = M2C_FIELD(arg0, f32 *, 0);
    M2C_FIELD(arg2, f32 *, 0) = 0.00024414062f * M2C_FIELD(arg0, s16 *, 0xC);
    M2C_FIELD(arg3, f32 *, 0) = 0.00024414062f * (u32)M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg1, f32 *, 4) = M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(arg2, f32 *, 4) = 0.00024414062f * M2C_FIELD(arg0, s16 *, 0xE);
    M2C_FIELD(arg3, f32 *, 4) = 0.00024414062f * (u32)M2C_FIELD(arg0, u16 *, 0x14);
    M2C_FIELD(arg1, f32 *, 8) = M2C_FIELD(arg0, f32 *, 8);
    M2C_FIELD(arg2, f32 *, 8) = 0.00024414062f * M2C_FIELD(arg0, s16 *, 0x10);
    M2C_FIELD(arg3, f32 *, 8) = 0.00024414062f * (u32)M2C_FIELD(arg0, u16 *, 0x16);
    M2C_FIELD(arg1, f32 *, 0xC) = 1.0f;
    M2C_FIELD(arg2, f32 *, 0xC) = 0.0f;
    M2C_FIELD(arg3, f32 *, 0xC) = 1.0f;
}

/* Map_BuildNodeMatrix_0_001B5B30 */
static inline f32 u2f_Map_BuildNodeMatrix_0_001B5B30(u32 x) { return x; }

void Map_BuildNodeMatrix_0_001B5B30(void *o, E_Map_BuildNodeMatrix_0_001B5B30 *e) {
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    s32 k;

    for (k = 0; k < 3; k++) {
        pos[k] = (&e->x)[k];
        rot[k] = 0.00024414062f * (&e->rx)[k];
        scl[k] = 0.00024414062f * u2f_Map_BuildNodeMatrix_0_001B5B30((&e->sx)[k]);
    }
    pos[3] = 1.0f;
    rot[3] = 0.0f;
    scl[3] = 1.0f;
    Mtx_Compose_2_00173FD0(o, pos, rot, scl);
}

/* Map_SpawnSfx_0_001B5CA0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Map_SpawnSfx_0_001B5CA0
void sceVu0CopyVector__as_Map_SpawnSfx_0_001B5CA0(f32 *, f32 *);
static inline f32 u2f_Map_SpawnSfx_0_001B5CA0(u32 x) { return x; }

void Map_SpawnSfx_0_001B5CA0(S_Map_SpawnSfx_0_001B5CA0 *s) {
    f32 v[4];
    f32 mat[4][4];
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    u32 i;
    s32 k;
    E_Map_SpawnSfx_0_001B5CA0 *e;
    P8_Map_SpawnSfx_0_001B5CA0 *p;

    sceVu0CopyVector(v, s->x10);
    for (i = 0; i < s->n78; i++) {
        e = &s->x150[i];
        p = &s->x190[i];
        if (Sfx_IsLoaded_2_00169BB0(e->id)) {
            p->obj = Sfx_Spawn_2_00169B50(e->id, e->f.b0, e->f.b1, e->f.b2);
            p->f.b0 = 1;
        } else {
            p->obj = Sfx_SpawnFromStam_2_00169BD0(e->id, s->o->m->x10, s->xB4, e->f.b0, e->f.b1, e->f.b2);
            p->f.b0 = 0;
        }
        if (e->f.b0) {
            p->f.b1 = 1;
        }
        if (p->obj) {
            for (k = 0; k < 3; k++) {
                pos[k] = (&e->x)[k];
                rot[k] = 0.00024414062f * (&e->rx)[k];
                scl[k] = 0.00024414062f * u2f_Map_SpawnSfx_0_001B5CA0((&e->sx)[k]);
            }
            pos[3] = 1.0f;
            rot[3] = 0.0f;
            scl[3] = 1.0f;
            Mtx_Compose_2_00173FD0(mat, pos, rot, scl);
            sceVu0AddVector(mat[3], mat[3], v);
            Sfx_SetMatrixOrAim_0_00167740(p->obj, mat);
        }
    }
}
#undef sceVu0CopyVector

/* Map_SpawnItems_0_001B5FB0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Map_SpawnItems_0_001B5FB0
void sceVu0CopyVector__as_Map_SpawnItems_0_001B5FB0(f32 *, s8 *);

void Map_SpawnItems_0_001B5FB0(s8 *arg0, s32 arg1) {
    f32 b0[4];
    f32 a0[4];
    f32 v90[4];
    u32 i;
    E8 *f;
    s32 off1;
    s32 off2;
    E28 *e;
    s32 id;
    s16 r;

    sceVu0CopyVector(b0, arg0 + 0x10);
    i = 0;
    if (i < *(u16 *)(arg0 + 0x72)) {
        off1 = 0;
        off2 = 0;
        do {
            e = (E28 *)(*(s8 **)(arg0 + 0x140) + off1);
            f = (E8 *)(*(s8 **)(arg0 + 0x184) + off2);
            id = e->x18;
            if ((!(e->x20 & 1) || Save_GetByte2E_0_001AA740() != 0) && MapState_TestBit_0_001A9BE0(*(s32 *)arg0, i) == 0 &&
                Inventory_CountItem_0_001CC0C0(id, 0) != 0) {
                f->b = Frame_IncCounter_1_0015C9E0();
                f->a = ItemObj_SpawnFromSource_0_001AF150(arg1, e, i, b0);
            }
            i++;
            off1 += 0x28;
            off2 += 8;
        } while (i < *(u16 *)(arg0 + 0x72));
    }
    for (i = 0; i < 0x10; i++) {
        r = MapState_GetObjectPos_0_001A9900(*(s32 *)arg0, i, a0, v90);
        if (r > 0 && Inventory_CountItem_0_001CC0C0(r, 0) != 0) {
            ItemObj_SpawnThrown_0_001AEC00(arg1, r, a0, v90, b0);
        }
    }
}
#undef sceVu0CopyVector

/* Map_InitObjects_0_001B6130 */
void Map_InitObjects_0_001B6130(Obj *o)
{
    u32 i;
    o->a[0] = 0;
    o->a[1] = 0;
    o->a[2] = 0;
    o->a[3] = 0;
    o->a[4] = 0;
    o->a[5] = 0;
    o->a[6] = 0;
    for (i = 0; i < o->n; i++)
        o->e[i].v = 0;
}
