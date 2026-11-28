#include "m2c.h"
#include "common.h"
#include "obj3d.h"
#include "game/core.h"
#include "game/data.h"
#include "game/item.h"
#include "game/save.h"
typedef struct {
    s8 pad0[0x40];
    f32 v40[4];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    s8 pad70[0x10];
    s32 x80;
    s8 pad84[0x18];
    s16 h9C;
    s8 pad9E[8];
    s8 xA6;
    s8 xA7;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:5;
    s8 padA9[5];
    s16 xAE;
    s8 padB0[4];
    f32 xB4;
    s8 padB8[0x18];
} Obj_ItemObj_SpawnAt_0_001AE620;
typedef struct { s8 pad[0x10]; s32 x10; s8 pad14[0x6C]; s8 x80[0x10]; } Ent_ItemObj_SpawnAt_0_001AE620;
typedef struct {
    s8 pad0[0x40];
    f32 v40[4];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    s8 pad70[0x10];
    s32 x80;
    s8 pad84[0x18];
    s16 h9C;
    s8 pad9E[8];
    s8 xA6;
    s8 xA7;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:5;
    s8 padA9[5];
    s16 xAE;
    s8 padB0[4];
    f32 xB4;
    s8 padB8[0x18];
} Obj_ItemObj_Spawn_0_001AE7C0;
typedef struct { s8 pad[0x10]; s32 x10; s8 pad14[0x6C]; s8 x80[0x10]; } Ent_ItemObj_Spawn_0_001AE7C0;
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_ItemObj_Drop_0_001AE900;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x4C]; Vec_ItemObj_Drop_0_001AE900 a; Vec_ItemObj_Drop_0_001AE900 b; Vec_ItemObj_Drop_0_001AE900 c; } Ent_ItemObj_Drop_0_001AE900;
typedef struct {
    u8 b0:1;
    u8 b1:1;
    u8 b2:4;
    u8 b6:1;
    u8 b7:1;
} BF;
typedef struct {
    Mtx m;
    Vec_ItemObj_Drop_0_001AE900 v40, v50, v60, v70;
    s32 x80;
    u8 pad84[8];
    s32 *x8C;
    u8 pad90[0xC];
    s16 idx;
    u8 pad9E[8];
    s8 xA6;
    s8 xA7;
    BF xA8;
    u8 fA9;
    s16 xAA;
    s16 xAC;
    s16 xAE;
    f32 xB0;
    f32 xB4;
} Node;
typedef struct {
    Vec_ItemObj_Drop_0_001AE900 m[3];
    Vec_ItemObj_Drop_0_001AE900 pos;
    Vec_ItemObj_Drop_0_001AE900 a, b, c;
    Vec_ItemObj_Drop_0_001AE900 d;
    s32 f80;
    s32 pad84[2];
    s32 f8C;
    s32 pad90[3];
    s16 f9C;
    s16 pad9e[4];
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:4;
    u8 a6:1;
    u8 a7:1;
    u8 c0:1;
    u8 c1:1;
    u8 c2:6;
    u16 fAA;
    s16 fAC;
    s16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj_ItemObj_Drop_0_001AE900;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct { Vec_ItemObj_SpawnFromMap_0_001AEE80 m[4]; } __attribute__((aligned(16))) Mtx_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct {
    u8 pad[0x10];
    s32 f10;
    u8 pad2[0x60 - 0x14];
    Vec_ItemObj_SpawnFromMap_0_001AEE80 a, b, c;
} Ent_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct {
    Vec_ItemObj_SpawnFromMap_0_001AEE80 m[3];
    Vec_ItemObj_SpawnFromMap_0_001AEE80 pos;
    Vec_ItemObj_SpawnFromMap_0_001AEE80 a, b, c;
    Vec_ItemObj_SpawnFromMap_0_001AEE80 d;
    s32 f80;
    s32 pad84[2];
    s32 f8C;
    s32 pad90[3];
    s16 f9C;
    s16 pad9e[3];
    s8 fA4;
    s8 padA5;
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:4;
    u8 a6:1;
    u8 a7:1;
    u8 c0:1;
    u8 c1:1;
    u8 c2:1;
    u8 c3:5;
    u16 fAA;
    s16 fAC;
    s16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct { Vec m[4]; } __attribute__((aligned(16))) MtxA;
typedef struct {
    u8 pad[0x10];
    s32 f10;
    u8 pad2[0x60 - 0x14];
    Vec a, b, c;
} Ent_ItemObj_SpawnFromSource_0_001AF150;
typedef struct {
    u8 pad[0x18];
    s32 f18;
    u16 f1C;
    u16 pad1e;
    u8 b0:1;
    u8 b1:1;
    u8 b2:6;
    u8 pad21;
    u16 f22;
} Src;
typedef struct {
    Vec m[3];
    Vec pos;
    Vec a, b, c;
    Vec d;
    s32 f80;
    s32 pad84[2];
    s32 f8C;
    s32 pad90[3];
    s16 f9C;
    s16 pad9e[4];
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:6;
    u8 c0:1;
    u8 c1:1;
    u8 c2:6;
    u16 fAA;
    s16 fAC;
    u16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj_ItemObj_SpawnFromSource_0_001AF150;
typedef struct { s32 pad[2]; s32 f8; s32 fC; } G_ItemObj_SpawnFromSource_0_001AF150;
typedef struct O {
    u8 pad[0x84];
    s8 *m84;
    u8 pad88[0x14];
    s16 m9C;
    s16 m9E;
    u8 padA0[7];
    s8 mA7;
    union { u16 h; u8 b; } mA8;
    u8 padAA[4];
    s16 mAE;
    u8 padB0[4];
    f32 mB4;
    s32 mB8;
    s32 mBC;
    s32 mC0[2][2];
} O;
typedef struct { s16 a[2]; s16 n[2]; O *list[2][16]; } G_ItemObj_Free_1_001AF4A0;
typedef struct { char b[0x90]; } E;
typedef struct { s32 a; u32 count; s32 b; s32 c; } Hdr;
extern Obj_ItemObj_SpawnAt_0_001AE620 *gItemObjectSbss_00202288;
extern Ent_ItemObj_SpawnAt_0_001AE620 *gItemObjectSbss_002022B0;
extern f32 gMatrixFromData_001F2170[];
extern s32 gMapSbss_00201E80;
extern Vec_ItemObj_Drop_0_001AE900 gItemObjectSpawnData_001F3820;
extern Vec_ItemObj_Drop_0_001AE900 gItemObjectSpawnData_001F3830;
extern s32 gPlayerSbss_002022BC;
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s16 D_004AC5A4[0x46] __attribute__((aligned(4)));
#ifdef NONMATCHING
/* Keep both banks in the same .bss block as their header when the data
 * moves into this unit. CodeWarrior emits .bss definitions in reverse. */
/* data group (src/game/data/pad_get_connected_bss.c): D_004AC5A0__grp: gItemObjectSpawnBss_004AC5A0@0x0 */
u8 D_004AC5A0__grp[0x4] __attribute__((section(".bss"), aligned(16)));
#endif
extern Node *D_004AC5A8[][16];
extern s16 gItemObjectSpawnBss_004AC5A0[];
extern s32 gItemObjectSbss_00202290;
extern s16 D_004AC5A2[];
extern s16 D_004AC5A6[];
extern s32 gItemObjectBss_004B4B80[];
extern Obj_ItemObj_SpawnAt_0_001AE620 gItemObjectSpawnBss_004AC630__as_ItemObj_SpawnAt_0_001AE620[4];
extern Obj_ItemObj_Spawn_0_001AE7C0 *gItemObjectSbss_00202288__as_ItemObj_Spawn_0_001AE7C0;
extern Ent_ItemObj_Spawn_0_001AE7C0 *gItemObjectSbss_002022B0__as_ItemObj_Spawn_0_001AE7C0;
extern Obj_ItemObj_Spawn_0_001AE7C0 gItemObjectSpawnBss_004AC630__as_ItemObj_Spawn_0_001AE7C0[4];
extern Ent_ItemObj_Drop_0_001AE900 *gItemObjectSbss_002022B0__as_ItemObj_Drop_0_001AE900;
extern Node *gItemObjectSbss_00202288__as_ItemObj_Drop_0_001AE900;
extern Obj_ItemObj_SpawnFromMap_0_001AEE80 *gItemObjectSbss_00202288__as_ItemObj_SpawnFromMap_0_001AEE80;
extern Ent_ItemObj_SpawnFromMap_0_001AEE80 *gItemObjectSbss_002022B0__as_ItemObj_SpawnFromMap_0_001AEE80;
extern Obj_ItemObj_SpawnFromMap_0_001AEE80 gItemObjectBss_004AE370__as_ItemObj_SpawnFromMap_0_001AEE80[2][64];
extern Obj_ItemObj_SpawnFromSource_0_001AF150 *gItemObjectSbss_00202288__as_ItemObj_SpawnFromSource_0_001AF150;
extern Ent_ItemObj_SpawnFromSource_0_001AF150 *gItemObjectSbss_002022B0__as_ItemObj_SpawnFromSource_0_001AF150;
extern Obj_ItemObj_SpawnFromSource_0_001AF150 gItemObjectBss_004AE370__as_ItemObj_SpawnFromSource_0_001AF150[][64];
extern O *gItemObjectSbss_00202288__as_ItemObj_Free_1_001AF4A0;
extern volatile G_ItemObj_Free_1_001AF4A0 gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0;
extern s32 *gMapSbss_00201E80__as_ItemObj_FreeOwned_0_001AF740[2];
extern s32 gItemObjectSbss_00202288__as_ItemObj_FreeAll_0_001AF840;
extern u8 gItemObjectSpawnBss_004AC630__as_ItemObj_FreeAll_0_001AF840[];
extern u8 gItemObjectBss_004AC970__as_ItemObj_FreeAll_0_001AF840[];
extern u8 gItemObjectBss_004AE370__as_ItemObj_FreeAll_0_001AF840[];
extern s32 gItemObjectSbss_00202288__as_ItemObj_Init_0_001AF980;
extern u8 gItemObjectSpawnBss_004AC5A0__as_ItemObj_ClearTables_1_001AFA20[];
extern s32 gItemObjectSbss_002022B0__as_Item_GetTable_1_001AFC90;
extern u8 *gItemObjectSbss_002022B0__as_Item_LoadTables_0_001AFCA0;
extern u8 *gItemObjectSbss_002022B0__as_Item_LoadTableB_0_001AFFA0;
Obj_ItemObj_SpawnAt_0_001AE620* ItemObj_SpawnAt_0_001AE620(s16 id, f32 *a, f32 *b);
Obj_ItemObj_Spawn_0_001AE7C0* ItemObj_Spawn_0_001AE7C0(s16 id);
Node* ItemObj_Drop_0_001AE900(s32 *owner, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, s32 ground, s32 rel);
Obj_ItemObj_Drop_0_001AE900* ItemObj_SpawnThrown_0_001AEC00(s32 arg0, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, Vec_ItemObj_Drop_0_001AE900 *d);
Obj_ItemObj_SpawnFromMap_0_001AEE80* ItemObj_SpawnFromMap_0_001AEE80(s32 *arg0, s16 id, Vec_ItemObj_SpawnFromMap_0_001AEE80 *a, Vec_ItemObj_SpawnFromMap_0_001AEE80 *b, s16 arg4);
Obj_ItemObj_SpawnFromSource_0_001AF150* ItemObj_SpawnFromSource_0_001AF150(s32 arg0, Src *arg1, u16 arg2, Vec *arg3);
void ItemObj_Free_1_001AF4A0(O *o);
void ItemObj_FreeOwned_0_001AF740(s32 *a0);
void ItemObj_FreeAll_0_001AF840(void);
void ItemObj_SetPools_0_001AF970(s32 arg0, s32 arg1);
void ItemObj_ClearTables_1_001AFA20(void);
E* Item_GetData_1_001AFC40(s16 i);
s32 Item_GetTable_1_001AFC90(void);
s32 Item_LoadTableB_0_001AFFA0(void *a);
void sceVu0CopyVector(void *, void *);
void Mtx_Compose_2_00173FD0(void *, void *, void *, void *);
void sceVu0CopyMatrix(void *, void *);
void sceVu0MulMatrix(void*, void*, void *);
void sceVu0AddVector(void *, void *, void *);
void sceVu0SubVector(void *, void *, void *);
void Map_CopyOrigin_0_001B51E0(s32, void *);
void* ItemObj_AllocSlot_1_001AE360(s16, u8);
s32 ItemObj_FindGround_0_001AE250(s32 *, Vec_ItemObj_Drop_0_001AE900 *, f32 *);
void Map_DecodeTransform_0_001B59E0(Src *, Vec *, Vec *, Vec *);
s32 MapState_GetField_0_001A9D50(u32, u16);
void MapState_SetField_0_001A9E10(s32, u16, u8);
void memset(void *, s32, s32);
void Sfx_Release_1_00167030(s32);
void Mdl_DestroyInstance_0_001745D0(s32, s8 *);
void Pool_Free_2_00128580(s32, s32);
void Task_Register_0_0014DB10(void (*)());
void sceVu0CopyVector__as_ItemObj_SpawnAt_0_001AE620(f32 *, f32 *);
void Mtx_Compose_2_00173FD0__as_ItemObj_SpawnAt_0_001AE620(Obj_ItemObj_SpawnAt_0_001AE620 *, f32 *, f32 *, s8 *);
void sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(Vec_ItemObj_Drop_0_001AE900 *, Vec_ItemObj_Drop_0_001AE900 *);
void Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(void *, Vec_ItemObj_Drop_0_001AE900 *, Vec_ItemObj_Drop_0_001AE900 *, Vec_ItemObj_Drop_0_001AE900 *);
void Map_CopyOrigin_0_001B51E0__as_ItemObj_Drop_0_001AE900(s32, Vec_ItemObj_Drop_0_001AE900 *);
void ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromMap_0_001AEE80(Obj_ItemObj_SpawnFromMap_0_001AEE80 *);
void Map_CopyOrigin_0_001B51E0__as_ItemObj_SpawnFromMap_0_001AEE80(s32, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
void sceVu0CopyVector__as_ItemObj_SpawnFromMap_0_001AEE80(Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
void Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromMap_0_001AEE80(void *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
void sceVu0MulMatrix__as_ItemObj_SpawnFromMap_0_001AEE80(void *, void *, Mtx_ItemObj_SpawnFromMap_0_001AEE80 *);
void sceVu0AddVector__as_ItemObj_SpawnFromMap_0_001AEE80(Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
void ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromSource_0_001AF150(Obj_ItemObj_SpawnFromSource_0_001AF150 *);
void sceVu0CopyVector__as_ItemObj_SpawnFromSource_0_001AF150(Vec *, Vec *);
void Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromSource_0_001AF150(void *, Vec *, Vec *, Vec *);
void sceVu0MulMatrix__as_ItemObj_SpawnFromSource_0_001AF150(void *, void *, MtxA *);
void sceVu0AddVector__as_ItemObj_SpawnFromSource_0_001AF150(Vec *, Vec *, Vec *);
void ItemObj_Free_1_001AF4A0__as_ItemObj_PickUp_0_001AF3F0(Obj3D *);
void ItemObj_Free_1_001AF4A0__as_ItemObj_FreeOwned_0_001AF740(Obj3D *);
s32 ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840();
s32 ItemObj_ClearTables_1_001AFA20__as_ItemObj_SetPools_0_001AF970();
s32 ItemObj_ClearTables_1_001AFA20__as_ItemObj_Init_0_001AF980();
void memset__as_ItemObj_Init_0_001AF980(s32 *, s32, s32);
s32 Arc_LoadFile_2_00159DD0(s32, void *, void*, void *);
void Arc_LoadFile_2_00159DD0__as_Item_LoadTables_0_001AFCA0(s32, s8 *, void *, u32 *);

/* ItemObj_SpawnAt_0_001AE620_ */
/* ItemObj_SpawnAt_0_001AE620 */

Obj_ItemObj_SpawnAt_0_001AE620 *ItemObj_SpawnAt_0_001AE620(s16 id, f32 *a, f32 *b) {
    Obj_ItemObj_SpawnAt_0_001AE620 *s = 0;
    Ent_ItemObj_SpawnAt_0_001AE620 *t = gItemObjectSbss_002022B0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gItemObjectSpawnBss_004AC630__as_ItemObj_SpawnAt_0_001AE620[i].h9C == -1) {
            s = &gItemObjectSpawnBss_004AC630__as_ItemObj_SpawnAt_0_001AE620[i];
            break;
        }
    }
    if (s == 0) {
        return 0;
    }
    s->h9C = id;
    s->xAE = -1;
    s->xA6 = 0x19;
    s->xA7 = -1;
    s->b0 = 0;
    s->b1 = 0;
    s->b2 = 1;
    s->x80 = t[id].x10;
    s->xB4 = 1.0f;
    sceVu0CopyVector__as_ItemObj_SpawnAt_0_001AE620(s->v40, a);
    sceVu0CopyVector__as_ItemObj_SpawnAt_0_001AE620(s->v50, b);
    s->x68 = 1.0f;
    s->x64 = 1.0f;
    s->x60 = 1.0f;
    s->x6C = 0.0f;
    Mtx_Compose_2_00173FD0__as_ItemObj_SpawnAt_0_001AE620(s, a, b, t[id].x80);
    if (gItemObjectSbss_00202288 == 0) {
        gItemObjectSbss_00202288 = s;
    }
    return s;
}

/* ItemObj_Spawn_0_001AE7C0 */

Obj_ItemObj_Spawn_0_001AE7C0 *ItemObj_Spawn_0_001AE7C0(s16 id) {
    Obj_ItemObj_Spawn_0_001AE7C0 *s = 0;
    Ent_ItemObj_Spawn_0_001AE7C0 *t = gItemObjectSbss_002022B0__as_ItemObj_Spawn_0_001AE7C0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gItemObjectSpawnBss_004AC630__as_ItemObj_Spawn_0_001AE7C0[i].h9C == -1) {
            s = &gItemObjectSpawnBss_004AC630__as_ItemObj_Spawn_0_001AE7C0[i];
            break;
        }
    }
    if (s == 0) {
        return 0;
    }
    s->h9C = id;
    s->xAE = -1;
    s->xA6 = -1;
    s->xA7 = -1;
    s->b0 = 0;
    s->b1 = 0;
    s->b2 = 1;
    s->x80 = t[id].x10;
    s->xB4 = 1.0f;
    sceVu0CopyMatrix(s, gMatrixFromData_001F2170);
    if (gItemObjectSbss_00202288__as_ItemObj_Spawn_0_001AE7C0 == 0) {
        gItemObjectSbss_00202288__as_ItemObj_Spawn_0_001AE7C0 = s;
    }
    return s;
}

/* ItemObj_Drop_0_001AE900 */
static inline void upd(Node *n) {
    Ent_ItemObj_Drop_0_001AE900 *tbl = gItemObjectSbss_002022B0__as_ItemObj_Drop_0_001AE900;
    if (n != NULL && n->idx != -1) {
        if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
            Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(n, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent_ItemObj_Drop_0_001AE900 *e = &tbl[n->idx];
            Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(&tmp, &e->a, &e->b, &e->c);
            Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(n, &n->v40, &n->v50, &n->v60);
            sceVu0MulMatrix(n, n, &tmp);
        }
        sceVu0AddVector(&n->m.m[3], &n->m.m[3], &n->v70);
    }
}

Node *ItemObj_Drop_0_001AE900(s32 *owner, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, s32 ground, s32 rel) {
    Vec_ItemObj_Drop_0_001AE900 c;
    Ent_ItemObj_Drop_0_001AE900 *t;
    Node *s;
    s32 side;

    t = gItemObjectSbss_002022B0__as_ItemObj_Drop_0_001AE900;
    c = gItemObjectSpawnData_001F3830;
    side = -1;
    if (((s32 **)&gMapSbss_00201E80)[2] == owner) {
        side = 0;
    }
    if (((s32 **)&gMapSbss_00201E80)[3] == owner) {
        side = 1;
    }
    s = ItemObj_AllocSlot_1_001AE360(id, side);
    if (s == 0) {
        return 0;
    }
    s->idx = id;
    s->xAA = 0;
    s->xAE = -1;
    s->xA6 = 0x19;
    s->xA7 = -1;
    s->xAC = 0;
    s->xA8.b0 = 0;
    s->xA8.b1 = 0;
    s->xA8.b6 = ground;
    s->x80 = t[id].x10;
    s->x8C = owner;
    s->xB4 = 1.0f;
    sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(&s->v40, a);
    sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(&s->v50, b);
    s->v50.v[2] = 0.0f;
    s->v50.v[0] = 0.0f;
    sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(&s->v60, &c);
    if (owner != 0) {
        Map_CopyOrigin_0_001B51E0__as_ItemObj_Drop_0_001AE900(*owner, &s->v70);
        if (rel != 0) {
            sceVu0SubVector(&s->v40, &s->v40, &s->v70);
        }
    }
    upd(s);
    if (ground != 0) {
        if (ItemObj_FindGround_0_001AE250(owner, &s->m.m[3], &s->xB0) == 0) {
            s->idx = -1;
            *(s16 *)&s->xA8 = 0;
            s->x80 = 0;
            s->x8C = 0;
            return 0;
        }
        s->xB0 -= s->v70.v[1];
    }
    D_004AC5A8[side][D_004AC5A4[side]++] = s;
    ItemObj_SaveState_1_001AE510();
    if (gItemObjectSbss_00202288__as_ItemObj_Drop_0_001AE900 == 0) {
        gItemObjectSbss_00202288__as_ItemObj_Drop_0_001AE900 = s;
    }
    return s;
}

static inline void update_ItemObj_Drop_0_001AE900(Obj_ItemObj_Drop_0_001AE900 *o) {
    Mtx m;
    Ent_ItemObj_Drop_0_001AE900 *e;
    Ent_ItemObj_Drop_0_001AE900 *ents = gItemObjectSbss_002022B0__as_ItemObj_Drop_0_001AE900;
    if (o == NULL) return;
    if (o->f9C == -1) return;
    if (o->c1) {
        Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(o, &o->a, &o->b, &o->c);
    } else {
        e = &ents[o->f9C];
        Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(&m, &e->a, &e->b, &e->c);
        Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(o, &o->a, &o->b, &o->c);
        sceVu0MulMatrix(o, o, &m);
    }
    sceVu0AddVector(&o->pos, &o->pos, &o->d);
}

Obj_ItemObj_Drop_0_001AE900 *ItemObj_SpawnThrown_0_001AEC00(s32 arg0, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, Vec_ItemObj_Drop_0_001AE900 *d) {
    Ent_ItemObj_Drop_0_001AE900 *ents;
    s32 side;
    Obj_ItemObj_Drop_0_001AE900 *o;
    s32 k;
    Vec_ItemObj_Drop_0_001AE900 c;
    ents = gItemObjectSbss_002022B0__as_ItemObj_Drop_0_001AE900;
    c = gItemObjectSpawnData_001F3820;
    side = -1;
    if ((&gMapSbss_00201E80)[2] == gPlayerSbss_002022BC) side = 0;
    if ((&gMapSbss_00201E80)[3] == gPlayerSbss_002022BC) side = 1;
    k = !side;
    o = ItemObj_AllocSlot_1_001AE360(id, k);
    if (o == NULL) return NULL;
    o->f9C = id;
    o->fAA = 0;
    o->fAE = -1;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = 0;
    o->a0 = 0;
    o->a1 = 0;
    o->a6 = 0;
    o->f80 = ents[id].x10;
    o->f8C = arg0;
    o->fB4 = 1.0f;
    sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(&o->a, a);
    sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(&o->b, b);
    sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(&o->c, &c);
    sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(&o->d, d);
    update_ItemObj_Drop_0_001AE900(o);
    D_004AC5A8[k][D_004AC5A4[k]++] = o;
    if (gItemObjectSbss_00202288__as_ItemObj_Drop_0_001AE900 == NULL) gItemObjectSbss_00202288__as_ItemObj_Drop_0_001AE900 = o;
    return o;
}

/* ItemObj_SpawnFromMap_0_001AEE80 */
#pragma explicit_zero_data on
Vec_ItemObj_SpawnFromMap_0_001AEE80 D_001F3810 = { 1.0f, 1.0f, 1.0f, 1.0f };
static inline void update_ItemObj_SpawnFromMap_0_001AEE80(Obj_ItemObj_SpawnFromMap_0_001AEE80 *o) {
    Mtx_ItemObj_SpawnFromMap_0_001AEE80 m;
    Ent_ItemObj_SpawnFromMap_0_001AEE80 *e;
    Ent_ItemObj_SpawnFromMap_0_001AEE80 *ents = gItemObjectSbss_002022B0__as_ItemObj_SpawnFromMap_0_001AEE80;
    if (o == NULL) return;
    if (o->f9C == -1) return;
    if (o->c1) {
        Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromMap_0_001AEE80(o, &o->a, &o->b, &o->c);
    } else {
        e = &ents[o->f9C];
        Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromMap_0_001AEE80(&m, &e->a, &e->b, &e->c);
        Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromMap_0_001AEE80(o, &o->a, &o->b, &o->c);
        sceVu0MulMatrix__as_ItemObj_SpawnFromMap_0_001AEE80(o, o, &m);
    }
    sceVu0AddVector__as_ItemObj_SpawnFromMap_0_001AEE80(&o->pos, &o->pos, &o->d);
}

Obj_ItemObj_SpawnFromMap_0_001AEE80 *ItemObj_SpawnFromMap_0_001AEE80(s32 *arg0, s16 id, Vec_ItemObj_SpawnFromMap_0_001AEE80 *a, Vec_ItemObj_SpawnFromMap_0_001AEE80 *b, s16 arg4) {
    Ent_ItemObj_SpawnFromMap_0_001AEE80 *ents;
    s32 side;
    Obj_ItemObj_SpawnFromMap_0_001AEE80 *o;
    s16 *cnt;
    Vec_ItemObj_SpawnFromMap_0_001AEE80 c;
    ents = gItemObjectSbss_002022B0__as_ItemObj_SpawnFromMap_0_001AEE80;
    c = D_001F3810;
    side = -1;
    if ((&gMapSbss_00201E80)[2] == (s32)arg0) side = 0;
    if ((&gMapSbss_00201E80)[3] == (s32)arg0) side = 1;
    cnt = &gItemObjectSpawnBss_004AC5A0[side];
    if (!(*(volatile s16 *)cnt < 0x40)) return NULL;
    o = &gItemObjectBss_004AE370__as_ItemObj_SpawnFromMap_0_001AEE80[side][*(volatile s16 *)cnt];
    if (o->f9C != -1) ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromMap_0_001AEE80(o);
    o->f9C = id;
    o->fAA = 0;
    o->fAE = -1;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = arg4;
    o->a0 = 0;
    o->a1 = 0;
    o->c2 = 1;
    o->f80 = ents[id].f10;
    o->f8C = (s32)arg0;
    o->fB4 = 1.0f;
    o->fA4 = 0x2D;
    sceVu0CopyVector__as_ItemObj_SpawnFromMap_0_001AEE80(&o->a, a);
    sceVu0CopyVector__as_ItemObj_SpawnFromMap_0_001AEE80(&o->b, b);
    o->b.z = 0.0f;
    o->b.x = 0.0f;
    sceVu0CopyVector__as_ItemObj_SpawnFromMap_0_001AEE80(&o->c, &c);
    if (arg0 != NULL) Map_CopyOrigin_0_001B51E0__as_ItemObj_SpawnFromMap_0_001AEE80(*arg0, &o->d);
    update_ItemObj_SpawnFromMap_0_001AEE80(o);
    (*cnt)++;
    if (gItemObjectSbss_00202288__as_ItemObj_SpawnFromMap_0_001AEE80 == NULL) gItemObjectSbss_00202288__as_ItemObj_SpawnFromMap_0_001AEE80 = o;
    return o;
}

/* ItemObj_SpawnFromSource_0_001AF150 */
static inline void update_ItemObj_SpawnFromSource_0_001AF150(Obj_ItemObj_SpawnFromSource_0_001AF150 *o) {
    MtxA m;
    Ent_ItemObj_SpawnFromSource_0_001AF150 *e;
    Ent_ItemObj_SpawnFromSource_0_001AF150 *ents = gItemObjectSbss_002022B0__as_ItemObj_SpawnFromSource_0_001AF150;
    if (o == NULL) return;
    if (o->f9C == -1) return;
    if (o->c1) {
        Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromSource_0_001AF150(o, &o->a, &o->b, &o->c);
    } else {
        e = &ents[o->f9C];
        Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromSource_0_001AF150(&m, &e->a, &e->b, &e->c);
        Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromSource_0_001AF150(o, &o->a, &o->b, &o->c);
        sceVu0MulMatrix__as_ItemObj_SpawnFromSource_0_001AF150(o, o, &m);
    }
    sceVu0AddVector__as_ItemObj_SpawnFromSource_0_001AF150(&o->pos, &o->pos, &o->d);
}

Obj_ItemObj_SpawnFromSource_0_001AF150 *ItemObj_SpawnFromSource_0_001AF150(s32 arg0, Src *arg1, u16 arg2, Vec *arg3) {
    Ent_ItemObj_SpawnFromSource_0_001AF150 *ents;
    s32 side;
    s32 k;
    Obj_ItemObj_SpawnFromSource_0_001AF150 *o;
    ents = gItemObjectSbss_002022B0__as_ItemObj_SpawnFromSource_0_001AF150;
    side = -1;
    if ((&gMapSbss_00201E80)[2] == gPlayerSbss_002022BC) side = 0;
    if ((&gMapSbss_00201E80)[3] == gPlayerSbss_002022BC) side = 1;
    k = !side;
    if (arg2 >= 0x40) return NULL;
    if (arg2 >= gItemObjectSpawnBss_004AC5A0[k]) gItemObjectSpawnBss_004AC5A0[k] = arg2 + 1;
    o = &gItemObjectBss_004AE370__as_ItemObj_SpawnFromSource_0_001AF150[k][arg2];
    if (o->f9C != -1) ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromSource_0_001AF150(o);
    o->f9C = arg1->f18;
    o->fAA = arg1->f1C;
    o->fAE = arg1->f22;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = arg2;
    o->a0 = 0;
    o->a1 = 0;
    o->c1 = arg1->b1;
    o->f80 = ents[arg1->f18].f10;
    o->f8C = arg0;
    o->fB4 = 1.0f;
    Map_DecodeTransform_0_001B59E0(arg1, &o->a, &o->b, &o->c);
    sceVu0CopyVector__as_ItemObj_SpawnFromSource_0_001AF150(&o->d, arg3);
    update_ItemObj_SpawnFromSource_0_001AF150(o);
    if (gItemObjectSbss_00202288__as_ItemObj_SpawnFromSource_0_001AF150 == NULL) gItemObjectSbss_00202288__as_ItemObj_SpawnFromSource_0_001AF150 = o;
    return o;
}

/* ItemObj_PickUp_0_001AF3F0 */
void ItemObj_PickUp_0_001AF3F0(Obj3D *o) {
    if (o->x9E == 0) {
        s32 *p = *o->x8C;
        if (o->xA9.f.b2) {
            MapState_SetField_0_001A9E10(*p, o->xAC, MapState_GetField_0_001A9D50(*p, o->xAC) | 2);
        } else {
            MapState_SetBit_0_001A9CA0(*p, o->xAC);
        }
    }
    ItemObj_Free_1_001AF4A0__as_ItemObj_PickUp_0_001AF3F0(o);
    if (o->x9E == 1) ItemObj_SaveState_1_001AE510();
}

/* ItemObj_Free_1_001AF4A0 */

void ItemObj_Free_1_001AF4A0(O *o) {
    s32 t;
    s32 k;

    if (o == 0) return;
    if (o->m9C == -1) return;
    if (o == gItemObjectSbss_00202288__as_ItemObj_Free_1_001AF4A0) {
        gItemObjectSpawnSbss_0020228C = 1;
    }
    if (o->mA8.b & 1) {
        if (o->mB8 != 0) {
            Sfx_Release_1_00167030(o->mB8);
        }
        if (o->mBC != 0) {
            Sfx_Release_1_00167030(o->mBC);
        }
        for (k = 0; k < 4; k++) {
            if (o->mC0[k / 2][k % 2] != 0) {
                Sfx_Release_1_00167030(o->mC0[k / 2][k % 2]);
            }
        }
        Mdl_DestroyInstance_0_001745D0(gItemObjectSbss_002022A0, o->m84);
        o->m84 = 0;
    }
    o->m9C = -1;
    o->mA8.h = 0;
    switch (o->m9E) {
    case 0:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 0;
        break;
    case 1:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 1;
        for (t = 0; t < 2; t++) {
            for (k = 0; k < gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0.n[t]; k++) {
                if (gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0.list[t][k] == o) break;
            }
            if (k >= gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0.n[t]) continue;
            goto cond;
        body:
            gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0.list[t][k] = gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0.list[t][k + 1];
            k++;
        cond:
            if (k < gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0.n[t] - 1) goto body;
            gItemObjectSpawnBss_004AC5A0__as_ItemObj_Free_1_001AF4A0.n[t]--;
            break;
        }
        break;
    case 2:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 2;
        break;
    }
    o->mB4 = 1.0f;
    o->mAE = -1;
    o->mA7 = -1;
}

/* ItemObj_FreeOwned_0_001AF740 */

void ItemObj_FreeOwned_0_001AF740(s32 *a0) {
    s32 k;
    s32 i;
    Obj3D *o;
    k = -1;
    if (gMapSbss_00201E80__as_ItemObj_FreeOwned_0_001AF740[2] == a0) k = 0;
    if (gMapSbss_00201E80__as_ItemObj_FreeOwned_0_001AF740[3] == a0) k = 1;
    for (i = 0, o = gItemObjectBss_004AE370[k]; i < 64; i++, o++) ItemObj_Free_1_001AF4A0__as_ItemObj_FreeOwned_0_001AF740(o);
    for (i = 0, o = gItemObjectBss_004AC970[k]; i < 16; i++, o++) ItemObj_Free_1_001AF4A0__as_ItemObj_FreeOwned_0_001AF740(o);
    gItemObjectSpawnBss_004AC5A0[k] = 0;
    D_004AC5A4[k] = 0;
}

/* ItemObj_FreeAll_0_001AF840 */

void ItemObj_FreeAll_0_001AF840(void) {
    u8 *var_17_3;
    u8 *var_17_2;
    s32 var_17;
    u8 *var_16;
    s32 var_16_3;
    s32 var_16_2;

    if ((*gItemObjectBss_004B4B80) != 0) {
        Pool_Free_2_00128580(gItemObjectSbss_00202290, (*gItemObjectBss_004B4B80));
    }
    if ((*gItemObjectBss_004B4B74) != 0) {
        Task_RunWrap_0_0014DAB0((*gItemObjectBss_004B4B74));
        (*gItemObjectBss_004B4B74) = 0;
    }
    (*gItemObjectBss_004B4B80) = 0;
    var_17 = 0;
    (*gItemObjectBss_004B4B74) = 0;
    var_16 = (u8 *) (gItemObjectBss_004AE370__as_ItemObj_FreeAll_0_001AF840);
    gItemObjectSbss_00202288__as_ItemObj_FreeAll_0_001AF840 = 0;
    (*gItemObjectBss_004B4B70) = 0;
    gItemObjectSpawnSbss_0020228C = 0;
    (*gItemObjectBss_004B4B88) = 0;
    do {
        ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840(var_16);
        ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840(var_16 + 0x3400);
        var_17 += 1;
        var_16 += 0xD0;
    } while (var_17 < 0x40);
    var_16_2 = 0;
    var_17_2 = (u8 *) (gItemObjectBss_004AC970__as_ItemObj_FreeAll_0_001AF840);
    do {
        ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840(var_17_2);
        ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840(var_17_2 + 0xD00);
        var_16_2 += 1;
        var_17_2 += 0xD0;
    } while (var_16_2 < 0x10);
    var_16_3 = 0;
    var_17_3 = (u8 *) (gItemObjectSpawnBss_004AC630__as_ItemObj_FreeAll_0_001AF840);
    do {
        ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840(var_17_3);
        var_16_3 += 1;
        var_17_3 += 0xD0;
    } while (var_16_3 < 4);
    (*gItemObjectSpawnBss_004AC5A0) = 0;
    (*D_004AC5A2) = 0;
    (*D_004AC5A4) = 0;
    (*D_004AC5A6) = 0;
}

/* ItemObj_SetPools_0_001AF970 */

void ItemObj_SetPools_0_001AF970(s32 arg0, s32 arg1) {
    gItemObjectSbss_00202290 = arg0;
    gItemObjectSbss_002022A0 = arg1;
    ItemObj_ClearTables_1_001AFA20__as_ItemObj_SetPools_0_001AF970();
}

/* ItemObj_Init_0_001AF980 */

void ItemObj_Init_0_001AF980(void) {
    ItemObj_ClearTables_1_001AFA20__as_ItemObj_Init_0_001AF980();
    memset__as_ItemObj_Init_0_001AF980(gItemObjectBss_004B4B70, 0, 0x1C);
    Task_Register_0_0014DB10(ItemMdl_Update_0_001AB690);
    if ((*gItemObjectBss_004B4B80) != 0) {
        Pool_Free_2_00128580(gItemObjectSbss_00202290, (*gItemObjectBss_004B4B80));
    }
    if ((*gItemObjectBss_004B4B74) != 0) {
        Task_RunWrap_0_0014DAB0((*gItemObjectBss_004B4B74));
        (*gItemObjectBss_004B4B74) = 0;
    }
    (*gItemObjectBss_004B4B80) = 0;
    gItemObjectSbss_00202288__as_ItemObj_Init_0_001AF980 = 0;
    (*gItemObjectBss_004B4B74) = 0;
    gItemObjectSpawnSbss_0020228C = 0;
    (*gItemObjectBss_004B4B70) = 0;
    (*gItemObjectBss_004B4B88) = 0;
}

/* ItemObj_ClearTables_1_001AFA20 */
static inline void init(Obj3D *e, s16 t) { e->x9C = -1; e->x9E = t; e->xB4 = 1.0f; e->xAE = -1; e->xA7 = -1; }

void ItemObj_ClearTables_1_001AFA20(void) {
    u32 i;
    memset(gItemObjectSpawnBss_004AC5A0__as_ItemObj_ClearTables_1_001AFA20, 0, 0x88);
    memset(gItemObjectBss_004AE370, 0, 0x6800);
    memset(gItemObjectBss_004AC970, 0, 0x1A00);
    memset(gItemObjectSpawnBss_004AC630, 0, 0x340);
    for (i = 0; i < 64; i++) { init(&gItemObjectBss_004AE370[0][i], 0); init(&gItemObjectBss_004AE370[1][i], 0); }
    for (i = 0; i < 16; i++) { init(&gItemObjectBss_004AC970[0][i], 1); init(&gItemObjectBss_004AC970[1][i], 1); }
    init(&gItemObjectSpawnBss_004AC630[0], 2); init(&gItemObjectSpawnBss_004AC630[1], 2); init(&gItemObjectSpawnBss_004AC630[2], 2); init(&gItemObjectSpawnBss_004AC630[3], 2);
}

/* Item_GetCategory_0_001AFBD0 */
#define gItemObjectSbss_002022B0 gItemObjectSbss_002022B0__as_Item_GetCategory_0_001AFBD0
extern E *gItemObjectSbss_002022B0__as_Item_GetCategory_0_001AFBD0;

/* Item_GetCategory_0_001AFBD0 */
s32 Item_GetCategory_0_001AFBD0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x64)) {
        return 0;
    }
    if ((arg0 >= 0x64) && (arg0 < 0x320)) {
        return 1;
    }
    if ((arg0 >= 0x320) && (arg0 < 0x400)) {
        return 2;
    }
    return -1;
}

/* Item_GetData_1_001AFC40 */
E *Item_GetData_1_001AFC40(s16 i)
{
    if (gItemObjectSbss_002022B0 && i > 0 && i <= 0x3FF)
        return &gItemObjectSbss_002022B0[i];
    return NULL;
}

/* Item_GetTable_1_001AFC90 */

s32 Item_GetTable_1_001AFC90(void) {
    return gItemObjectSbss_002022B0__as_Item_GetTable_1_001AFC90;
}

/* Item_LoadTables_0_001AFCA0 */
#define B(d, s) M2C_FIELD(p, u8 *, d) = M2C_FIELD(e, u8 *, s)
#define H(d, s) M2C_FIELD(p, u16 *, d) = M2C_FIELD(e, u16 *, s)
static inline u8 *lookup(s16 id) { if (gItemObjectSbss_002022B0__as_Item_LoadTables_0_001AFCA0 != NULL && id > 0 && id < 0x400) return gItemObjectSbss_002022B0__as_Item_LoadTables_0_001AFCA0 + id * 0x90; return NULL; }

void Item_LoadTables_0_001AFCA0(s8 *arg0) {
    u32 sz;
    Hdr **hdr;
    Hdr *t0;
    s8 *e;
    u32 i;
    u8 *p;
    s16 id;

    sz = 0;
    Arc_LoadFile_2_00159DD0__as_Item_LoadTables_0_001AFCA0(0x0DBC359C, arg0, &hdr, &sz);
    t0 = *hdr;
    e = (s8 *)(t0 + 1);
    for (i = 0; i < t0->count; i++, e += 0x40) {
        p = lookup(M2C_FIELD(e, s16 *, 0));
        if (p != NULL) {
            switch (M2C_FIELD(p, u16 *, 0xA)) {
            case 0:
                break;
            case 1:
                H(4, 2); B(6, 8); B(7, 0x3D);
                B(0x22, 4); B(0x23, 5); B(0x24, 6); B(0x25, 7);
                B(0x26, 0x10); B(0x27, 0x11); B(0x28, 0x12); B(0x29, 0x13); B(0x2A, 0x14); B(0x2B, 0x15);
                H(0x2C, 0x18); H(0x2E, 0x1A); H(0x30, 0x1C); H(0x32, 0x1E);
                H(0x34, 0x20); H(0x36, 0x22); H(0x38, 0x24); H(0x3A, 0x26);
                B(0x3C, 9); B(0x3D, 0xC); B(0x3E, 0xA); B(0x3F, 0xB);
                B(0x44, 0x28); B(0x45, 0x29); B(0x46, 0x2A); B(0x47, 0x2B); B(0x48, 0x2C); B(0x49, 0x2D);
                H(0x4A, 0x30); H(0x4C, 0x32); H(0x4E, 0x34); H(0x50, 0x36); H(0x52, 0x38); H(0x54, 0x3A);
                B(0x56, 0xD); H(0x42, 0xE); B(0x57, 0x3C);
                if (p[0x57] == 0) {
                    p[0x57] = 1;
                }
                break;
            case 2:
                H(4, 2); B(6, 8); B(7, 0x3D);
                B(0x22, 4); B(0x23, 5); B(0x24, 6); B(0x25, 7);
                H(0x26, 0x18); H(0x28, 0x1A);
                B(0x2A, 0x10); B(0x2B, 0x11); B(0x2C, 0x12); B(0x2D, 0x13); B(0x2E, 0x14); B(0x2F, 0x15);
                H(0x30, 0x1C); H(0x32, 0x1E);
                H(0x34, 0x20); H(0x36, 0x22); H(0x38, 0x24); H(0x3A, 0x26);
                B(0x3C, 9); B(0x3D, 0xC); B(0x3E, 0xA); B(0x3F, 0xB);
                break;
            }
        }
    }
}

/* Item_LoadTableB_0_001AFFA0 */

s32 Item_LoadTableB_0_001AFFA0(void *a) {
    s32 sz;
    u32 **h;
    u32 *p;
    s32 q;
    Arc_LoadFile_2_00159DD0(0x48F91304, a, &h, &sz);
    p = *h;
    switch (p[0]) {
    case 0x4D505449:
        q = (s32)p + 0x10;
        gItemObjectSbss_002022B0__as_Item_LoadTableB_0_001AFFA0 = (u8 *)(q + 0x10 + ((*(u32 *)(q + 0xC) + 0xF) & ~0xF));
        break;
    }
    return 0;
}
#undef gItemObjectSbss_002022B0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gItemObjectSpawnSbss_0020228C */
s32 gItemObjectSpawnSbss_0020228C;
/* data group (src/game/data/map_area_load_data.c): D_001F3820__grp: gItemObjectSpawnData_001F3820@0x0 */
f32 D_001F3820__grp[0x4] __attribute__((aligned(16))) = { 1.0f, 1.0f, 1.0f, 1.0f };
/* data group (src/game/data/map_area_load_data.c): D_001F3830__grp: gItemObjectSpawnData_001F3830@0x0 */
f32 D_001F3830__grp[0x4] __attribute__((aligned(16))) = { 1.0f, 1.0f, 1.0f, 1.0f };
/* data group (src/game/data/pad_get_connected_bss_004AC630.c): gItemObjectSpawnBss_004AC630__grp: gItemObjectSpawnBss_004AC630@0x0, gItemObjectSpawnBss_004AC6CC@0x9c, gItemObjectSpawnBss_004AC79C@0x16c, gItemObjectSpawnBss_004AC86C@0x23c, gItemObjectSpawnBss_004AC93C@0x30c */
unsigned char gItemObjectSpawnBss_004AC630__grp[0x340] __attribute__((aligned(16)));
#endif
