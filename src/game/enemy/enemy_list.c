#include "m2c.h"
#include "common.h"
#include "actor.h"
#include "game/core.h"
#include "game/data.h"
#include "game/effect.h"
#include "game/enemy.h"
#include "game/gfx.h"
#include "game/model.h"
typedef struct { s32 v; s32 pad[9]; } E;
typedef struct { u8 pad[0x5A0]; Flags8 f; } A_ActorList_Next_2_001A5460;
typedef struct { u8 pad[0x5A0]; Flags8 f; } A_ActorList_AllocSlot_0_001A5530;
typedef struct { u8 pad[0x5A0]; Flags8 f5A0; } A_ActorList_NextTargetable_0_001A5660;
typedef f32 Mtx_Enemy_GetAttachMatrix_0_001A5AA0[4][4];
typedef struct { u8 pad[0x30]; } Elem;
typedef struct { u8 pad[0x138]; Elem *base; } Tbl;
typedef struct { u8 pad[0x40]; s32 id; } Inf;
typedef struct {
    u8 pad0[0xC0];
    Tbl *tbl;
    s32 padC4;
    Elem *cur;
    Inf *inf;
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m;
    s32 x110;
    s32 x114;
} Obj;
typedef struct { u8 pad[0x10]; Obj *obj; } Arg;
typedef union { f32 f; Flags8 f8; } Col;
typedef struct { Vec p; Vec r; u8 pad[0x40]; Col c; } P_Enemy_Draw_1_001A5DE0;
typedef struct { u8 pad[0x160]; Flags8 f; u8 pad2[3]; s32 h; u8 pad3[8]; } E_Enemy_Draw_1_001A5DE0;
typedef struct { u8 pad[0x240]; Col c; } C;
typedef struct { u16 **pp; u8 pad[0x20]; Flags8 f; } H2;
typedef struct { H2 *h; } H_Enemy_Draw_1_001A5DE0;
typedef struct { u128 q[10]; } Big;
typedef struct { u8 pad[0x20]; u8 x20; s8 x21; u8 pad22[2]; u8 x24; u8 pad25[8]; Flags8 x2D; } A_Enemy_Draw_1_001A5DE0;
typedef struct { u8 pad[0xBC]; u8 xBC; } G2;
typedef struct {
    u8 pad0[0x8C];
    s16 x8C;
    s16 x8E;
    u8 pad90[0x154 - 0x90];
    s32 *x154;
    G2 *x158;
    u8 pad15C[0x188 - 0x15C];
    Big *x188;
} G;
typedef struct { u8 pad[0xC0]; G *xC0; A_Enemy_Draw_1_001A5DE0 *xC4; A_Enemy_Draw_1_001A5DE0 *xC8; } X;
typedef struct { u8 pad[0x10]; X *x10; } B_Enemy_Draw_1_001A5DE0;
typedef struct { u8 pad[0xB0]; H_Enemy_Draw_1_001A5DE0 *xB0; u8 padB4[0x180 - 0xB4]; B_Enemy_Draw_1_001A5DE0 x180; } S_Enemy_Draw_1_001A5DE0;
typedef struct {
    u8 pad0[0x78];
    s32 n;
    u8 pad7C[0x19A - 0x7C];
    u8 a[0x100];
    u8 b[0x100];
    u8 pad39A[0x4A8 - 0x39A];
    G **x4A8;
    u8 pad4AC[2];
    s16 x4AE;
    C *x4B0;
    P_Enemy_Draw_1_001A5DE0 *tbl[0x19];
    S_Enemy_Draw_1_001A5DE0 *x518;
    E_Enemy_Draw_1_001A5DE0 *x51C;
    u8 pad520[0x30];
    Vec x550;
    Vec x560;
    u8 pad570[0x30];
    Flags8 f5A0;
    Flags8 f5A1;
} O_Enemy_Draw_1_001A5DE0;
typedef struct { Vec m[2]; } M_Enemy_Draw_1_001A5DE0;
typedef struct { u8 pad[0x1D8]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } R;
typedef Bits8 B8;
typedef struct {
    u16 v0;
    u8 pad2[0x4A6];
    R **r;
    u8 pad4ac[0x5A0 - 0x4AC];
    u8 f5a0;
    B8 f5a1;
} P_Enemies_DrawAll_1_001A6770;
typedef struct { f32 x, y, z, w; } V;
typedef struct { u8 pad[0x10]; s32 *x10; } M_Enemies_ResetFlags_0_001A6950;
typedef struct A_Enemies_ResetFlags_0_001A6950 {
    u16 m0;
    u8 pad2[2];
    M_Enemies_ResetFlags_0_001A6950 **m4;
    s32 *m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18[0x19];
    s32 m7C;
    u8 pad80[0x4B0 - 0x80];
    s32 m4B0;
    s32 m4B4[0x18];
    s32 m514;
    s32 m518;
    s32 m51C;
    u8 pad520[0x80];
    Flags8 f5A0;
} A_Enemies_ResetFlags_0_001A6950;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x28]; B8 x3C; } Q_Enemy_Destroy_0_001A6A10;
typedef struct { u8 pad[0xC]; B8 xC; } F;
typedef struct { u8 pad[0xB0]; s32 xB0; u8 padB4[0x70]; s32 x124[8]; } S_Enemy_Destroy_0_001A6A10;
typedef struct { u8 pad[0x164]; s32 x164; u8 pad168[8]; } E_Enemy_Destroy_0_001A6A10;
typedef struct {
    u16 x0;
    u16 x2;
    Q_Enemy_Destroy_0_001A6A10 **x4;
    s32 x8;
    u8 padC[0x70];
    s32 x7C;
    u8 pad80[0x41C];
    s32 x49C;
    u8 pad4A0[4];
    s32 x4A4;
    u8 pad4A8[8];
    F *x4B0;
    u8 pad4B4[0x64];
    S_Enemy_Destroy_0_001A6A10 *x518;
    E_Enemy_Destroy_0_001A6A10 *x51C;
    u8 pad520[0x60];
    u8 x580[0x20];
    u16 pad5A0a:3;
    u16 x5A0:8;
} P_Enemy_Destroy_0_001A6A10;
typedef struct { u8 pad[0x5A0]; u8 b0:1; u8 b1:1; u8 b2:1; u8 r:5; } A_Enemy_Despawn_0_001A6C10;
typedef struct { char pad[0x5A1]; unsigned char : 4; unsigned char f : 1; } BF_5A1_4_1;
typedef struct { char pad[0x5A0]; unsigned char : 2; unsigned char f : 1; } BF_5A0_2_1;
typedef struct {
    u8 pad[0xB0];
    s32 *pB0;
    u8 padB4[0xC];
    u8 mC0[0x60];
    Flags8 f120;
    u8 pad121[0x23];
    u8 m144[0x28];
    s32 m16C;
} Sub_Enemy_InitBody_1_001A6DC0;
typedef struct {
    u8 m00[0x20];
    u8 m20[0x20];
    u8 m40[0x20];
    u8 m60[0x20];
    u8 pad80[0xC];
    s32 m8C;
    u8 pad90[0xC];
    s32 m9C;
    u8 padA0[0xBC];
    u16 m15C;
    u8 pad15E[2];
    Flags8 f160;
    u8 pad161[0xF];
} Ent_Enemy_InitBody_1_001A6DC0;
typedef struct { u8 pad[0x20]; u16 m20; u8 pad22[0x8A]; f32 mAC; } Src_Enemy_InitBody_1_001A6DC0;
typedef struct { char pad[0x2D]; s8 v; char rest[0x26]; } E_Enemy_SetPartModel_0_001A6FF0;
typedef struct { char pad[0x13C]; E_Enemy_SetPartModel_0_001A6FF0 *tbl; } T_Enemy_SetPartModel_0_001A6FF0;
typedef struct { T_Enemy_SetPartModel_0_001A6FF0 *t; } B_Enemy_SetPartModel_0_001A6FF0;
typedef struct { char pad[0x4A8]; B_Enemy_SetPartModel_0_001A6FF0 *b; u16 i; s16 v; } Obj_Enemy_Draw_1_001A5DE0;
typedef struct { u8 pad[0x160]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; u8 pad2[3]; void *h; u8 pad3[0x170-0x168]; } S_Enemy_SetVisible_1_001A7030;
typedef struct { u8 pad[0x2E2]; u8 idx; u8 pad2[0x40-0x2E3+0x2E2]; } T_Enemy_SetVisible_1_001A7030;
typedef struct { u8 pad[0x124]; void *h[8]; } U;
typedef struct { u8 pad[0x7C]; s32 n; u8 pad1[0x9A-0x80]; u8 map[0x4B0-0x9A]; T_Enemy_SetVisible_1_001A7030 *t; u8 pad2[0x518-0x4B4]; s8 *u; S_Enemy_SetVisible_1_001A7030 *s; } O_Enemy_SetVisible_1_001A7030;
typedef struct { u8 pad[0x10]; s32 x10; } M_Enemy_LoadSfx_0_001A71B0;
typedef struct { M_Enemy_LoadSfx_0_001A71B0 *m; } MP;
typedef struct { u8 pad[0x2C]; u32 pad2:14; u32 id:10; } Def;
typedef struct { u8 pad[0x160]; u8 b0:1; u8 b1:1; u8 pad2[3]; s32 x164; u8 pad3[0x8]; } Ent_Enemy_LoadSfx_0_001A71B0;
typedef struct { u8 pad[0xC]; u8 c0:6; u8 c6:1; u8 pad2[0x2E0 - 0xD]; u16 id; u8 pad3[0x3E]; } T0;
typedef struct { u8 pad[0x120]; u16 a:2; u16 m:8; u16 pad1:6; u16 pad2; s32 x124[8]; } Q_Enemy_LoadSfx_0_001A71B0;
typedef struct {
    u8 pad[4];
    MP *mp;
    u8 pad8[0x74];
    s32 n;
    u8 pad80[0x4B0 - 0x80];
    u8 *t;
    Def *defs[(0x518 - 0x4B4) / 4];
    Q_Enemy_LoadSfx_0_001A71B0 *q;
    Ent_Enemy_LoadSfx_0_001A71B0 *ents;
    u8 pad520[0x60];
    u8 buf[1];
} O_Enemy_LoadSfx_0_001A71B0;
typedef Bits8 Bits;
typedef struct { u8 pad[6]; u16 m6; u8 pad8[0x1C]; Bits f24; u8 pad25[0x1B]; u8 m40[1]; } Mdl;
typedef struct {
    Vec m0;
    Vec m10;
    Vec m20;
    Vec m30;
    Vec m40;
    Vec m50;
    u8 pad60[0x50];
    Mdl **pB0;
    u8 mB4;
    u8 mB5;
    u8 mB6;
    u8 mB7;
    u8 padB8[0xB4];
    s32 m16C;
    f32 m170;
} Sub_Enemy_Spawn_0_001A7420;
typedef struct {
    u8 pad0[0x8C];
    s32 m8C;
    u8 pad90[0xC];
    s32 m9C;
    u8 padA0[0xBC];
    u16 m15C;
    u8 pad15E[6];
    s32 m164;
    u8 pad168[8];
} Ent_Enemy_Spawn_0_001A7420;
typedef struct { u8 pad[0x20]; u16 m20; u8 pad22[8]; u8 m2A; u8 pad2B; u8 m2C; u8 pad2D[0x7F]; f32 mAC; } Src_Enemy_Spawn_0_001A7420;
typedef struct A_Enemy_Spawn_0_001A7420 {
    u16 m0;
    u8 pad2[2];
    s32 ***m4;
    s32 **m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18[0x19];
    s32 m7C;
    u8 pad80;
    u8 m81;
    u8 m82[0x41A];
    s32 m49C;
    s32 m4A0;
    s32 m4A4;
    s32 *m4A8;
    u16 m4AC;
    u8 pad4AE[2];
    s32 m4B0;
    Src_Enemy_Spawn_0_001A7420 *m4B4[0x18];
    s32 m514;
    Sub_Enemy_Spawn_0_001A7420 *m518;
    s32 m51C;
    u8 pad520[0x80];
    Bits f5A0;
} A_Enemy_Spawn_0_001A7420;
typedef void (*Fn)(A_Enemy_Spawn_0_001A7420 *, f32);
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H_EnemyData_Parse_0_001A7810;
typedef struct Ch {
    s32 x0;
    s32 x4;
    u32 type : 8;
    u32 off : 24;
    u16 xC;
    u16 xE;
    H_EnemyData_Parse_0_001A7810 h;
} Ch;
typedef struct {
    u8 pad0[0x20];
    u16 x20;
    u8 pad22[8];
    u8 x2A;
    u8 x2B;
    u8 x2C;
    Flags8 x2D;
} El;
typedef struct {
    u8 pad0[0x10];
    u8 **x10;
    u16 x14;
} Src;
typedef struct {
    s32 x0;
    Src **x4;
    void *x8;
    s32 xC;
    s32 x10;
    s32 x14;
    s32 x18[24];
    s32 x78;
    s32 x7C;
    u8 pad80[0x1A];
    u8 t[4][0x100];
    u8 pad49A[6];
    s32 x4A0;
} Obj_EnemyData_Parse_0_001A7810;
typedef struct { char pad[0x3C]; unsigned int : 4; unsigned int f : 1; } BF_3C_4_1;
extern E gEnemyDataTbl_004A43B0[];
extern E gEnemyManagerBss_004A43B8[];
extern s32 gEnemyListBss_004A4878[];
extern A_ActorList_Next_2_001A5460 **gEnemyListBss_004A4570[];
#ifndef NONMATCHING
extern s32 gEnemyListSbss_00202274;
#else
/* data twins (src/game/data/sbss.c): gEnemyListSbss_00202274 */
static s32 gEnemyListSbss_00202274;
#endif
extern A_ActorList_AllocSlot_0_001A5530 **gEnemyListBss_004A4570__as_ActorList_AllocSlot_0_001A5530[];
extern u8 **gEnemyListBss_004A4570__as_ActorList_FindFree_0_001A55E0[];
extern A_ActorList_NextTargetable_0_001A5660 **gEnemyListBss_004A4570__as_ActorList_NextTargetable_0_001A5660[];
extern u8 **gEnemyListBss_004A4570__as_ActorList_NextB_0_001A5710[];
extern s32 gEnemyListBss_004A4570__as_ActorList_FromHandle_1_001A5970[];
extern Mtx_Enemy_GetAttachMatrix_0_001A5AA0 gMatrixFromData_001F2170;
extern Flags8 D_00222A50[];
extern G **gMapSbss_00201E80[2];
extern G **gPlayerSbss_002022BC;
extern u32 gSoundSbss_002022B8;
#ifndef NONMATCHING
extern f32 gEnemyListSdata_00201DAC;
#else
/* data twins (src/game/data/sdata.c): gEnemyListSdata_00201DAC */
static f32 gEnemyListSdata_00201DAC __attribute__((aligned(4))) = 1.0f;
#endif
extern Big gGlowInitBss_0030D0E0;
#ifndef NONMATCHING
extern Vec gEnemyListData_001F37A0;
#else
/* data twins (src/game/data/title_nop_data.c): gEnemyListData_001F37A0 */
static Vec gEnemyListData_001F37A0 = { 128.0f, 128.0f, 128.0f, 1.0f };
#endif
#ifndef NONMATCHING
extern f32 gEnemyListRodata_001FD910[];
#else
/* data twins (src/game/data/enemy_list_rodata.c): gEnemyListRodata_001FD910 */
static f32 gEnemyListRodata_001FD910[0x1] = { 128.0f };
#endif
#ifndef NONMATCHING
extern f32 gEnemyListRodata_001FD914[];
#else
/* data twins (src/game/data/enemy_list_rodata.c): gEnemyListRodata_001FD914 */
static f32 gEnemyListRodata_001FD914[0x1] = { 0.0f };
#endif
#ifndef NONMATCHING
extern f32 gEnemyListRodata_001FD918[];
#else
/* data twins (src/game/data/enemy_list_rodata.c): gEnemyListRodata_001FD918 */
static f32 gEnemyListRodata_001FD918[0x1] = { 128.0f };
#endif
#pragma explicit_zero_data on
const f32 D_001FD91C[0xd] __attribute__((aligned(4))) = { 100.0f, 0.0f, 0.0f, 0.0f, 100.0f, 128.0f, 128.0f, 128.0f, 100.0f, 128.0f, 128.0f, 0.0f, 100.0f };
const f32 D_001FD950[0x4] __attribute__((aligned(4))) = { 0.3f, 0.4f, 0.3f, 0.3f };
extern s16 gEnemyListBss_004A4774[];
extern u16 D_004A4776[];
extern Fn gEnemyListData_001F33A0[];
extern Vec gMatrixFromData_001F2120;
extern B8 D_00222A50__as_Enemies_DrawAll_1_001A6770[];
extern s8 gEnemyListRodata_001FD960[];
extern s32 *gEnemyListSbss_00202280__as_EnemyData_Parse_0_001A7810;
s32 ActorList_GetCount_1_001A5430(void);
s32 ActorList_SetCount_1_001A5440(s32 arg0);
A_ActorList_Next_2_001A5460* ActorList_Next_2_001A5460(s32 *it);
A_ActorList_AllocSlot_0_001A5530** ActorList_AllocSlot_0_001A5530(void);
u8** ActorList_FindFree_0_001A55E0(void);
A_ActorList_NextTargetable_0_001A5660* ActorList_NextTargetable_0_001A5660(void);
u8* ActorList_NextB_0_001A5710(void);
void Actor_TransformRay_0_001A5790(Vec *o1, Vec *o2, Mtx *m, Vec *p, Vec *d);
void Actor_ClosestOnSegment_0_001A58A0(Vec *a, Vec *b, Vec *o1, Vec *o2, f32 f);
s32 ActorList_FromHandle_1_001A5970(u16 *p);
void Enemy_DropItems_0_001A5990(s8 *a0);
u8 Enemy_GetAttachMatrix_0_001A5AA0(u16 *flag, Arg *a, Mtx_Enemy_GetAttachMatrix_0_001A5AA0 out);
void ActorList_TranslateAll_1_001A5CD0(s32 arg0);
void Enemy_Draw_1_001A5DE0(O_Enemy_Draw_1_001A5DE0 *o);
void Enemy_Destroy_0_001A6A10(P_Enemy_Destroy_0_001A6A10 **a0);
void Enemy_Despawn_0_001A6C10(A_Enemy_Despawn_0_001A6C10 *a);
void Enemy_Respawn_1_001A6C90(u8 *arg0);
void Enemy_InitBody_1_001A6DC0(Actor *a0);
void Enemy_SetPartModel_0_001A6FF0(Obj_Enemy_Draw_1_001A5DE0 *o, B_Enemy_SetPartModel_0_001A6FF0 *b, u16 i);
void Enemy_SetVisible_1_001A7030(O_Enemy_SetVisible_1_001A7030 *arg0, s32 arg1, s32 arg2);
void Enemy_LoadSfx_0_001A71B0(O_Enemy_LoadSfx_0_001A71B0 *o);
void Enemy_Spawn_0_001A7420(A_Enemy_Spawn_0_001A7420 **pp);
void EnemyData_Parse_0_001A7810(Obj_EnemyData_Parse_0_001A7810 **a0, Src **a1);
void EnemyData_ParseWrap_0_001A7C60(void **arg0, void **arg1, u32 arg2, s8 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7);
u8** EnemyData_LoadTextures_0_001A7C70(s32 arg0);
void Task_Register_0_0014DB10(void (*)());
void memset(void *, s32, s32);
u8 Enemy_Get5B2b3_1_0013E830(A_ActorList_Next_2_001A5460 *);
void sceVu0CopyVector(void *, void*);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sqrtf(f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
s32 Inventory_CountItem_0_001CC0C0(s32, s32);
u32 Rand_Next_3_0015ED20(void);
void* ItemObj_Drop_0_001AE900(s32, s16, Vec *, Vec *, s32, s32);
void sceVu0CopyMatrix(Mtx_Enemy_GetAttachMatrix_0_001A5AA0, Mtx_Enemy_GetAttachMatrix_0_001A5AA0);
void sceVu0MulMatrix(Mtx_Enemy_GetAttachMatrix_0_001A5AA0, Mtx_Enemy_GetAttachMatrix_0_001A5AA0, Mtx_Enemy_GetAttachMatrix_0_001A5AA0);
s8* Mdl_GetFrameData_0_001715B0(s32);
void MapObj_CheckActivate_0_001B1A20(Tbl *, s32, s32);
void sceVu0CopyVector__as_ActorList_GetCount_1_001A5430(Vec *, Vec *);
void sceVu0AddVector(s8 *, s8 *, s32);
void Actor_Translate_1_0013B960(s8 *, s32);
s32 Mdl_SetLayerForMesh_0_0016B360(H_Enemy_Draw_1_001A5DE0 *, Col, u8);
void Mdl_SetLayerSimple_0_0016B480(Col, u8);
void Mdl_DrawLitWrap_0_0016B960(s8 *, s32, u16 *, s8 *, s32, s32);
void Light_CopyColor_0_0015B6B0(Vec *, Vec *);
void Fog_SetReg_0_0015B1C0(Vec *, Vec *);
void Mdl_DrawMeshesC_1_0016D380(u16 *, H2 *, s8 *, s32, Col, u8);
void Seg_Init_1_001502A0(M_Enemy_Draw_1_001A5DE0 *, P_Enemy_Draw_1_001A5DE0 *, Vec *, f32);
void Sfx_SetColor_0_00167670(s32, M_Enemy_Draw_1_001A5DE0 *);
void Sfx_SetTransform_1_001677C0(s32, s8 *);
s32 Enemy_Get5B5mF_1_0013E5E0(O_Enemy_Draw_1_001A5DE0 *);
f32 Enemy_Get5C4_1_0013E460(O_Enemy_Draw_1_001A5DE0 *);
u8 Enemy_Get5B5b4w2_1_0013E4E0(O_Enemy_Draw_1_001A5DE0 *);
s32 Enemy_Get5B7b7_1_0013D1E0(O_Enemy_Draw_1_001A5DE0 *);
void Enemy_Clear5B7b7_1_0013D1C0(O_Enemy_Draw_1_001A5DE0 *);
f32 Enemy_CalcSpeedScale_0_0013D6C0(O_Enemy_Draw_1_001A5DE0 *);
void Mtx_LerpRows_0_0015CC80(s8 *, Vec *, f32);
void Mtx_ScaleRotation_0_0015CC40(s8 *, f32);
void Player_CopyLightPos_0_001C9C00(Vec *);
void Mdl_DrawWithOverlay_0_0016C350(u16 *, H2 *, s8 *, Vec *);
void ScreenFx_Begin_0_001329D0(s32, s32, s32);
s32 Enemy_CanAct_0_0013E2B0(P_Enemies_DrawAll_1_001A6770 *);
void ScreenFx_Draw_0_00132930(V *);
void Sfx_Release_1_00167030(s32);
void Tex_ReleaseList_0_00178030(s32);
void Mdl_DestroyInstance_0_001745D0(s32, s32);
void Pool_Free_2_00128580(s32, void *);
void Sfx_RegisterList_0_00169D00(void *, s32);
void EnemyMgr_FreeSlot_0_001A5070(P_Enemy_Destroy_0_001A6A10 **);
void Sfx_ReleaseOwned_0_00167580(A_Enemy_Despawn_0_001A6C10 *);
void Enemy_ResetPartAnim_1_001A8670(Actor *, u8);
void Script_InitContext_1_00166F90(s32, s32, s32, s32);
void Mdl_UpdateBoneMatrices_0_00171270(s32, s8 *, s32);
void Sfx_SetFlag_0_00167640(void *, s32);
s32 Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
s32 Sfx_SpawnFromStam_2_00169BD0(s32, s32, void *, s32, s32, s32);
void Sfx_LoadStam_1_00169D70(s32, void *, s32);
Mdl** Mdl_CreateInstance_0_00174230(s32, s32 ***, s32, s32);
void Mdl_UpdateBoneMatricesCur_0_00171540(Mdl *, s8 *);
void Map_DecodeTransform_0_001B59E0(s8 *, Vec *, Vec *, Vec *);
void EnemyScr_GetScriptPath_3_00142930(u8, u8 *);
s32 Pool_Alloc_3_001288C0(s32, s32);
void Enemy_UpdateModelMatrix_0_001A7E60(A_Enemy_Spawn_0_001A7420 *);
u32 Player_CopyLightPos_0_001C9C00__as_Enemies_DrawAll_1_001A6770(s32);
s32 Map_DecodeTransform_0_001B59E0__as_Enemy_Respawn_1_001A6C90();
void EnemyData_Parse_0_001A7810__as_EnemyData_ParseWrap_0_001A7C60(void **arg0, void **arg1, u32 arg2, s8 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7);
void* Pool_Alloc_3_001288C0__as_EnemyData_Parse_0_001A7810(s32, s32);

/* EnemyMgr_Init_0_001A5340 */
#define sceVu0CopyVector sceVu0CopyVector__as_EnemyMgr_Init_0_001A5340
void sceVu0CopyVector__as_EnemyMgr_Init_0_001A5340(Vec*, void *);

/* EnemyMgr_Init_0_001A5340 */
void EnemyMgr_Init_0_001A5340(void) {
    s32 i;

    if (gEnemyMgrUpdateSdata_00201DA8 != -1 && *(volatile s32 *)&gEnemyManagerBss_004A43B8[gEnemyMgrUpdateSdata_00201DA8].v != 0) {
        Task_RunWrap_0_0014DAB0(gEnemyManagerBss_004A43B8[gEnemyMgrUpdateSdata_00201DA8].v);
        gEnemyManagerBss_004A43B8[gEnemyMgrUpdateSdata_00201DA8].v = 0;
    }
    gEnemyMgrUpdateSdata_00201DA8 = -1;
    Task_Register_0_0014DB10(EnemyMgr_Update_0_001A4990);
    memset(gEnemyDataTbl_004A43B0, 0, 0x1B8);
    for (i = 10; i >= 0; i--) {
        gEnemyDataTbl_004A43B0[i].v = -1;
    }
    gEnemyMgrUpdateSdata_00201DA8 = -1;
}

/* ActorList_GetCount_1_001A5430 */

/* ActorList_GetCount_1_001A5430 */
/* ActorList_GetCount_1_001A5430 */
/* ActorList_GetCount_1_001A5430 */
s32 ActorList_GetCount_1_001A5430(void) {
    return (*gEnemyListBss_004A4878);
}

/* ActorList_SetCount_1_001A5440 */
s32 ActorList_SetCount_1_001A5440(s32 arg0) {
    s32 temp_2;

    temp_2 = (*gEnemyListBss_004A4878);
    (*gEnemyListBss_004A4878) = arg0;
    return temp_2;
}

/* ActorList_Next_2_001A5460 */
A_ActorList_Next_2_001A5460 *ActorList_Next_2_001A5460(s32 *it) {
 A_ActorList_Next_2_001A5460 *r; s32 i; A_ActorList_Next_2_001A5460 **o;
 i = *it; r = 0;
 while (i < 0x81) { o = gEnemyListBss_004A4570[0x80 - i]; i++; if (o != 0 && (*o)->f.f.b0 && (*o)->f.f.b2 && Enemy_Get5B2b3_1_0013E830(*o) == 0) { r = *o; break; } }
 *it = i; return r;
}

/* ActorList_AllocSlot_0_001A5530 */
A_ActorList_AllocSlot_0_001A5530 **ActorList_AllocSlot_0_001A5530(void) {
    s32 i;
    A_ActorList_AllocSlot_0_001A5530 ***p;
    i = gEnemyListSbss_00202274;
    if (i >= 0x81) return NULL;
    goto setup;
body:
    if (*p != NULL && ((**p)->f.f.b0 || (**p)->f.f.b1)) {
        gEnemyListSbss_00202274 = i + 1;
        return gEnemyListBss_004A4570__as_ActorList_AllocSlot_0_001A5530[i];
    }
    p++;
    i++;
cond:
    if (i < 0x81) goto body;
    return NULL;
setup:
    p = &gEnemyListBss_004A4570__as_ActorList_AllocSlot_0_001A5530[i];
    goto cond;
}

/* ActorList_FindFree_0_001A55E0 */

u8 **ActorList_FindFree_0_001A55E0(void) {
    s32 var_5;
    u8 ***var_4;
    u8 **temp_2;
    u8 temp_3;

    gEnemyListSbss_00202274 = 0;
    var_5 = 0;
    var_4 = (u8 ***) (gEnemyListBss_004A4570__as_ActorList_FindFree_0_001A55E0);
loop_1:
    temp_2 = (u8 **) (*var_4);
    if ((temp_2 != NULL) && ((temp_3 = M2C_FIELD(*temp_2, u8 *, 0x5A0), ((temp_3 & 1) != 0)) || (((u64) ((s64) temp_3 << 0x3E) >> 0x3F) != 0))) {
        gEnemyListSbss_00202274 = var_5 + 1;
        return (u8 **) ((gEnemyListBss_004A4570__as_ActorList_FindFree_0_001A55E0)[var_5]);
    }
    var_5 += 1;
    var_4 = (u8***)((u8 *)var_4 + 4);
    if (var_5 >= 0x81) {
        return NULL;
    }
    goto loop_1;
}

/* ActorList_NextTargetable_0_001A5660 */
A_ActorList_NextTargetable_0_001A5660 *ActorList_NextTargetable_0_001A5660(void) {
    s32 i = gEnemyListSbss_00202274; A_ActorList_NextTargetable_0_001A5660 ***p; if (!(i < 0x81)) return NULL; goto setup; body: if (*p && ((**p)->f5A0.b & 1) && (**p)->f5A0.f.b2) { gEnemyListSbss_00202274 = i + 1; return *gEnemyListBss_004A4570__as_ActorList_NextTargetable_0_001A5660[i]; } p++; i++; cond: if (!(i < 0x81)) return NULL; goto body; setup: p = &gEnemyListBss_004A4570__as_ActorList_NextTargetable_0_001A5660[i]; goto cond;
}

/* ActorList_NextB_0_001A5710 */

u8 *ActorList_NextB_0_001A5710(void) {
    s32 var_5;
    u8 ***var_4;
    u8 **temp_2;
    u8 temp_3;

    gEnemyListSbss_00202274 = 0;
    var_5 = 0;
    var_4 = (u8 ***) (gEnemyListBss_004A4570__as_ActorList_NextB_0_001A5710);
loop_1:
    temp_2 = (u8 **) (*var_4);
    if (temp_2 != NULL) {
        temp_3 = M2C_FIELD(*temp_2, u8 *, 0x5A0);
        if ((temp_3 & 1) && (((u64) ((s64) temp_3 << 0x3D) >> 0x3F) != 0)) {
            gEnemyListSbss_00202274 = var_5 + 1;
            return (u8 *) (*(gEnemyListBss_004A4570__as_ActorList_NextB_0_001A5710)[var_5]);
        }
    }
    var_5 += 1;
    var_4 = (u8***)((u8 *)var_4 + 4);
    if (var_5 >= 0x81) {
        return NULL;
    }
    goto loop_1;
}

/* Actor_TransformRay_0_001A5790 */
/* Actor_TransformRay_0_001A5790 */
void Actor_TransformRay_0_001A5790(Vec *o1, Vec *o2, Mtx *m, Vec *p, Vec *d) {
    Vec a;
    Vec b;
    f32 *wa;
    f32 *wb;
    f32 len;

    sceVu0CopyVector__as_ActorList_GetCount_1_001A5430(&a, p);
    wa = &a.w;
    *wa = 1.0f;
    sceVu0CopyVector__as_ActorList_GetCount_1_001A5430(&b, d);
    wb = &b.w;
    *wb = 0.0f;
    sceVu0ApplyMatrix(&a, m, &a);
    sceVu0ApplyMatrix(&b, m, &b);
    len = sqrtf(sceVu0InnerProduct(&b, &b));
    sceVu0Normalize(&b, &b);
    *wa = p->w * len;
    *wb = d->w * len;
    sceVu0CopyVector__as_ActorList_GetCount_1_001A5430(o1, &a);
    sceVu0CopyVector__as_ActorList_GetCount_1_001A5430(o2, &b);
}

/* Actor_ClosestOnSegment_0_001A58A0 */
void Actor_ClosestOnSegment_0_001A58A0(Vec *a, Vec *b, Vec *o1, Vec *o2, f32 f) {
    Vec p;
    Vec q;
    Vec d;
    f32 l;
    p.x = a->x; p.y = a->y; p.z = a->z; p.w = 0.0f;
    q.x = b->x; q.y = b->y; q.z = b->z; q.w = 0.0f;
    sceVu0SubVector(&d, &q, &p);
    l = sqrtf(sceVu0InnerProduct(&d, &d));
    sceVu0CopyVector__as_ActorList_GetCount_1_001A5430(o1, &p);
    sceVu0Normalize(o2, &d);
    o2->w = l;
    o1->w = f;
}

/* ActorList_FromHandle_1_001A5970 */

s32 ActorList_FromHandle_1_001A5970(u16 *p)
{
    return gEnemyListBss_004A4570__as_ActorList_FromHandle_1_001A5970[p[1]];
}

/* Enemy_DropItems_0_001A5990 */
/* Enemy_DropItems_0_001A5990 */
void Enemy_DropItems_0_001A5990(s8 *a0) {
    u16 *p;
    s32 i;
    s32 id;
    u16 v;
    Vec a;
    Vec b;
    p = (u16 *)(*(s8 **)(a0 + 0x4B0) + 0x250);
    for (i = 0; i < 4; i++) {
        id = p[8];
        v = p[0xC];
        if (id < 0x400 && v != 0 && Inventory_CountItem_0_001CC0C0(id, 1) && Rand_Next_3_0015ED20() % 100 < v) {
            sceVu0CopyVector(&a, *(void **)(a0 + 0x518));
            sceVu0CopyVector(&b, *(s8 **)(a0 + 0x518) + 0x20);
            a.y -= 100.0f;
            ItemObj_Drop_0_001AE900(*(s32 *)(a0 + 0x4A8), id, &a, &b, 1, 1);
            return;
        }
        p++;
    }
}

/* Enemy_GetAttachMatrix_0_001A5AA0 */
u8 Enemy_GetAttachMatrix_0_001A5AA0(u16 *flag, Arg *a, Mtx_Enemy_GetAttachMatrix_0_001A5AA0 out) {
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m1;
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m2;
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m3;
    s8 *p;
    u8 i;
    u8 j;
    u8 changed = 0;

    sceVu0CopyMatrix(out, gMatrixFromData_001F2170);
    if (a->obj->cur != NULL) {
        p = Mdl_GetFrameData_0_001715B0(a->obj->inf->id);
        sceVu0CopyMatrix(m1, a->obj->m);
        sceVu0CopyMatrix(m2, (f32 (*)[4])(p + 0x200));
        sceVu0CopyMatrix(a->obj->m, m2);
        if (a->obj->x114 == a->obj->x110) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    if (m1[i][j] != m2[i][j]) {
                        changed = 1;
                    }
                }
            }
            if (changed) {
                sceVu0CopyMatrix(m3, gMatrixFromData_001F2170);
                m3[0][0] = m1[0][0];
                m3[0][1] = m1[1][0];
                m3[0][2] = m1[2][0];
                m3[0][3] = 0.0f;
                m3[1][0] = m1[0][1];
                m3[1][1] = m1[1][1];
                m3[1][2] = m1[2][1];
                m3[1][3] = 0.0f;
                m3[2][0] = m1[0][2];
                m3[2][1] = m1[1][2];
                m3[2][2] = m1[2][2];
                m3[2][3] = 0.0f;
                m3[3][3] = 0.0f;
                sceVu0MulMatrix(out, m2, m3);
                out[3][0] = m2[3][0] - m1[3][0];
                out[3][1] = m2[3][1] - m1[3][1];
                out[3][2] = m2[3][2] - m1[3][2];
                out[3][3] = 1.0f;
            }
        }
        if (*flag == 0) {
            MapObj_CheckActivate_0_001B1A20(a->obj->tbl, a->obj->cur - a->obj->tbl->base, 1);
        }
    }
    return changed;
}
#undef sceVu0CopyVector

/* ActorList_TranslateAll_1_001A5CD0 */
#define gEnemyListBss_004A4570 gEnemyListBss_004A4570__as_ActorList_TranslateAll_1_001A5CD0
extern s8 **gEnemyListBss_004A4570__as_ActorList_TranslateAll_1_001A5CD0[];

void ActorList_TranslateAll_1_001A5CD0(s32 arg0) {
    s32 i;
    s8 **o;
    s8 ***pp;
    s8 *a;
    s8 *t;

    pp = gEnemyListBss_004A4570;
    for (i = 0; i < 0x81; i++) {
        o = *pp;
        if (o != NULL) {
            a = *o;
            if ((M2C_FIELD(a, u8 *, 0x5A0) & 1) && ((u64)((s64)M2C_FIELD(a, u8 *, 0x5A0) << 61) >> 63)) {
                t = M2C_FIELD(a, s8 **, 0x518);
                sceVu0AddVector(t, t, arg0);
                a = M2C_FIELD(*o, s8 **, 0x518) + 0x10;
                sceVu0AddVector(a, a, arg0);
                a = M2C_FIELD(*o, s8 **, 0x518) + 0x1C0;
                sceVu0AddVector(a, a, arg0);
                a = M2C_FIELD(t, s8 **, 0x190) + 0x100;
                sceVu0AddVector(a, a, arg0);
                a = M2C_FIELD(*o, s8 **, 0x518) + 0x90;
                sceVu0AddVector(a, a, arg0);
                Actor_Translate_1_0013B960(*o, arg0);
            }
        }
        pp++;
    }
}
#undef gEnemyListBss_004A4570

/* Enemy_Draw_1_001A5DE0 */
#define gEnemyListBss_004A4570 gEnemyListBss_004A4570__as_Enemy_Draw_1_001A5DE0
extern P_Enemies_DrawAll_1_001A6770 **gEnemyListBss_004A4570__as_Enemy_Draw_1_001A5DE0[];
#define gMatrixFromData_001F2170 gMatrixFromData_001F2170__as_Enemy_Draw_1_001A5DE0
extern s8 gMatrixFromData_001F2170__as_Enemy_Draw_1_001A5DE0[];
#define Mdl_GetFrameData_0_001715B0 Mdl_GetFrameData_0_001715B0__as_Enemy_Draw_1_001A5DE0
s8* Mdl_GetFrameData_0_001715B0__as_Enemy_Draw_1_001A5DE0(H_Enemy_Draw_1_001A5DE0 *);
#define sceVu0AddVector sceVu0AddVector__as_Enemy_Draw_1_001A5DE0
void sceVu0AddVector__as_Enemy_Draw_1_001A5DE0(void *, void *, void *);

/* Enemy_Draw_1_001A5DE0 */
/* Enemy_Draw_1_001A5DE0 */

static inline f32 lp(f32 a, f32 b, f32 f, f32 u) { return f * a + b * u; }
void Enemy_Draw_1_001A5DE0(O_Enemy_Draw_1_001A5DE0 *o) {
    Col c;
    Col c3;
    Col c2;
    u32 sv;
    u8 fl;
    u16 *x;
    s32 i;
    P_Enemy_Draw_1_001A5DE0 *p;
    u8 low;
    H_Enemy_Draw_1_001A5DE0 *h;
    s8 *r;
    E_Enemy_Draw_1_001A5DE0 *ee;
    B_Enemy_Draw_1_001A5DE0 *b;
    G *g;
    X *e;
    A_Enemy_Draw_1_001A5DE0 *a3;
    A_Enemy_Draw_1_001A5DE0 *a2;
    G **pp;
    G *t;
    s32 *tb;
    s32 m1;
    s32 m0;
    s16 sel;
    s16 idx;
    u8 k;
    f32 f;
    f32 u;
    Vec q;
    Vec pv;
    Vec v;
    Vec cv;
    M_Enemy_Draw_1_001A5DE0 m;
    Vec buf;

    fl = 0;
    low = 0;
    sv = D_00222A50[0].f.b3;
    if (o == NULL) return;
    h = o->x518->xB0;
    x = *h->h->pp;
    r = Mdl_GetFrameData_0_001715B0(h);
    b = &o->x518->x180;
    if (!h->h->f.f.b1) return;
    g = NULL;
    idx = -1;
    if (o->x4A8 != NULL) {
        g = *o->x4A8;
        m0 = 0;
        e = b->x10;
        a3 = e->xC4;
        a2 = e->xC8;
        m1 = 0;
        if (gMapSbss_00201E80[2] != NULL && *gMapSbss_00201E80[2] != NULL && *gMapSbss_00201E80[2] == e->xC0) g = e->xC0;
        if (gMapSbss_00201E80[3] != NULL && *gMapSbss_00201E80[3] != NULL && *gMapSbss_00201E80[3] == e->xC0) g = e->xC0;
        tb = g->x154;
        sel = g->x8C;
        if (g->x8E != -2) sel = g->x8E;
        if (sel != -1) m1 = tb[sel];
        if ((pp = gPlayerSbss_002022BC) != NULL && (t = *pp) != NULL && t != g && t->x8C != -1) m0 = t->x154[t->x8C + 0x20];
        if (sel == -1) {
            if (a3 != NULL) {
                if (!a3->x2D.f.b5) return;
                if (a3->x24 != 0 && gSoundSbss_002022B8 != a3->x24) return;
                if (!(m0 & (1 << a3->x20))) return;
            }
            if (a2 != NULL && !(m0 & (1 << a2->x20))) return;
        } else {
            if (a3 != NULL && !(m1 & (1 << a3->x20))) return;
            if (a2 != NULL && !(m1 & (1 << a2->x20))) return;
        }
        idx = o->x4AE;
        if (idx == -1) {
            if (a3 != NULL) idx = a3->x21;
            if (a2 != NULL) idx = a2->x21;
        }
        if (g != NULL) low = g->x158->xBC & 1;
    }
    if (idx == -1 || g == NULL) {
        *(Big *)(r + 0x10) = gGlowInitBss_0030D0E0;
    } else {
        *(Big *)(r + 0x10) = g->x188[idx];
    }
    Enemy_SetVisible_1_001A7030(o, 1, 0);
    o->f5A1.f.b6 = 1;
    if (low) {
        Mdl_SetLayerForMesh_0_0016B360(h, o->x4B0->c, 0);
        Mdl_DrawLitWrap_0_0016B960(r, 0, x, r + 0x280, 0, 2);
        Light_CopyColor_0_0015B6B0(&v, &o->x560);
        Fog_SetReg_0_0015B1C0(&v, &o->x550);
        for (i = 0; i < o->n; i++) {
            k = o->a[i];
            if (k == 0xFF) {
                c = o->x4B0->c;
            } else {
                c = o->tbl[k]->c;
            }
            if (Mdl_SetLayerForMesh_0_0016B360(h, c, 0)) Mdl_DrawLitWrap_0_0016B960(r, 0, x, r + 0x280, 0, 2);
            if (c.f8.f.b2) Mdl_DrawMeshesC_1_0016D380(*h->h->pp, h->h, r, i, c, 0);
        }
        GsPkt_CloseChain_1_001549D0();
    }
    c2 = o->x4B0->c;
    Mdl_SetLayerForMesh_0_0016B360(h, c2, 3);
    Mdl_DrawLitWrap_0_0016B960(r, 0, x, r + 0x280, 0, 2);
    if (Enemy_Get5B5mF_1_0013E5E0(o)) {
        u8 j;
        s32 jj;
        f = Enemy_Get5C4_1_0013E460(o);
        j = Enemy_Get5B5b4w2_1_0013E4E0(o);
        if (!(f <= 1.0f)) f = 2.0f - f;
        u = 1.0f - f;
        jj = j;
        q.x = lp(gEnemyListRodata_001FD910[jj * 4], o->x550.x, f, u);
        q.y = lp(gEnemyListRodata_001FD914[jj * 4], o->x550.y, f, u);
        q.z = lp(gEnemyListRodata_001FD918[jj * 4], o->x550.z, f, u);
        q.w = lp(D_001FD91C[jj * 4], o->x550.w, f, u);
        pv.x = o->x560.x;
        pv.y = o->x560.y;
        pv.z = lp(D_001FD950[jj], o->x560.z, f, u);
        pv.w = lp(D_001FD950[jj], o->x560.w, f, u);
        Light_CopyColor_0_0015B6B0(&pv, &pv);
        Fog_SetReg_0_0015B1C0(&pv, &q);
    } else {
        Light_CopyColor_0_0015B6B0(&pv, &o->x560);
        sceVu0CopyVector(&q, &o->x550);
        Fog_SetReg_0_0015B1C0(&pv, &q);
    }
    if (Enemy_Get5B7b7_1_0013D1E0(o)) {
        cv = gEnemyListData_001F37A0;
        cv.x *= gEnemyListSdata_00201DAC;
        cv.y *= gEnemyListSdata_00201DAC;
        cv.z *= gEnemyListSdata_00201DAC;
        Mtx_LerpRows_0_0015CC80(r + 0x10, &cv, 1.0f);
        gEnemyListSdata_00201DAC -= 0.05f;
        if (gEnemyListSdata_00201DAC < 0.0f) gEnemyListSdata_00201DAC = 1.0f;
        Enemy_Clear5B7b7_1_0013D1C0(o);
    }
    f = Enemy_CalcSpeedScale_0_0013D6C0(o);
    Mtx_ScaleRotation_0_0015CC40(r + 0x10, f);
    if (f < 1.0f) fl = 1;
    for (i = 0; i < o->n; i++) {
        k = o->a[i];
        p = o->tbl[k];
        if (k == 0xFF) {
            c2 = o->x4B0->c;
        } else {
            c2 = p->c;
        }
        c2.f8.f.b4 |= fl;
        if (Mdl_SetLayerForMesh_0_0016B360(h, c2, 3)) {
            Fog_SetReg_0_0015B1C0(&pv, &q);
            Mdl_DrawLitWrap_0_0016B960(r, 0, x, r + 0x280, 0, 2);
        }
        if (!c2.f8.f.b3) Mdl_DrawMeshesC_1_0016D380(*h->h->pp, h->h, r, i, c2, fl);
        k = o->b[i];
        p = o->tbl[k];
        ee = &o->x51C[k];
        if (k == 0xFF) continue;
        if (ee->h == 0) continue;
        if (ee->f.f.b2) continue;
        Seg_Init_1_001502A0(&m, p, &p->r, p->p.w);
        Sfx_SetColor_0_00167670(ee->h, &m);
        Sfx_SetTransform_1_001677C0(ee->h, (r + (i + 1) * 0x140) + 0xC0);
    }
    GsPkt_CloseChain_1_001549D0();
    if (!D_00222A50[0].f.b6 && !(f <= 0.5f) && x[0xF] != 0) {
        c3 = c2;
        c3.f8.f.b4 = 0;
        Mdl_SetLayerSimple_0_0016B480(c3, 4);
        Player_CopyLightPos_0_001C9C00(&buf);
        Mdl_DrawWithOverlay_0_0016C350(*h->h->pp, h->h, r, &buf);
        GsPkt_CloseChain_1_001549D0();
    }
    D_00222A50[0].f.b3 = sv;
}

/* Enemies_DrawAll_1_001A6770 */
static inline void setb6(P_Enemies_DrawAll_1_001A6770 *p, s32 v) { p->f5a1.b6 = v; }

void Enemies_DrawAll_1_001A6770(void) {
    V v;
    s32 i;
    P_Enemies_DrawAll_1_001A6770 ***pp;
    if (!D_00222A50__as_Enemies_DrawAll_1_001A6770[0].b6) {
        GsPkt_SetLayerTop_0_001548F0(4);
        ScreenFx_Begin_0_001329D0(0x15E, 0x100, 0x100);
        GsPkt_EndLayer_1_00155900();
    }
    i = 0;
    pp = gEnemyListBss_004A4570;
    for (; i < 0x81; i++, pp++) {
        P_Enemies_DrawAll_1_001A6770 **q = *pp;
        if (q != NULL) {
            P_Enemies_DrawAll_1_001A6770 *p = *q;
            if (p != NULL && p->v0 != 0) {
                Enemy_SetVisible_1_001A7030(p, 0, 0);
                setb6(p, 0);
                if (!p->f5a1.b5) {
                    R **rr = p->r;
                    R *r;
                    if (rr == NULL || (r = *rr) == NULL || !r->b3) {
                        u8 f = p->f5a0;
                        if ((f & 1) && ((u64)((s64)f << 0x3D) >> 0x3F) && Enemy_CanAct_0_0013E2B0(p) != 0) {
                            Enemy_Draw_1_001A5DE0(p);
                        }
                    }
                }
            }
        }
    }
    if (!D_00222A50__as_Enemies_DrawAll_1_001A6770[0].b6) {
        GsPkt_SetLayerTop_0_001548F0(4);
        v.w = (f32)Player_CopyLightPos_0_001C9C00__as_Enemies_DrawAll_1_001A6770(0) / 255.0f;
        ScreenFx_Draw_0_00132930(&v);
        GsPkt_EndLayer_1_00155900();
    }
    Mdl_FlushLayer_0_0016B280();
}

/* Enemies_ResetFlags_0_001A6950 */
void Enemies_ResetFlags_0_001A6950(void) {
    s32 i;
    for (i = 0; i < 0x81; i++) {
        A_Enemies_ResetFlags_0_001A6950 **p = gEnemyListBss_004A4570[i];
        if (p) {
            A_Enemies_ResetFlags_0_001A6950 *a = *p;
            if (a->f5A0.b & 1) {
                s32 j;
                s32 base = *(*a->m4)->x10;
                a->m4B0 = base + a->m10;
                a->m514 = base + a->m14;
                for (j = 0; j < a->m7C; j++) {
                    a->m4B4[j] = base + a->m18[j];
                }
                a->m518 = *a->m8;
                a->m51C = a->m518 + 0x640;
            }
        }
    }
}

/* Enemy_Destroy_0_001A6A10 */

void Enemy_Destroy_0_001A6A10(P_Enemy_Destroy_0_001A6A10 **a0) {
    P_Enemy_Destroy_0_001A6A10 *p;
    Q_Enemy_Destroy_0_001A6A10 **q;
    s32 i;
    S_Enemy_Destroy_0_001A6A10 *s;

    p = *a0;
    q = p->x4;
    gEnemyListBss_004A4570[p->x2] = 0;
    { u16 v = (*a0)->x2; s16 n = gEnemyListBss_004A4774[0]++; D_004A4776[n] = v; }
    if (p->x8 != 0) {
        for (i = 0; i < p->x7C; i++) {
            if (p->x51C[i].x164 != 0) {
                Sfx_Release_1_00167030(p->x51C[i].x164);
            }
        }
        if ((*q)->x3C.b4) {
            Tex_ReleaseList_0_00178030((*q)->x10);
        }
        if (p->x518->xB0 != 0) {
            Mdl_DestroyInstance_0_001745D0(gEnemyListSbss_00202280, p->x518->xB0);
        }
        if (p->x49C != 0) {
            Pool_Free_2_00128580(gEnemyListSbss_00202278, (void *)p->x49C);
        }
        if (p->x4A4 != 0) {
            Pool_Free_2_00128580(gEnemyListSbss_00202278, (void *)p->x4A4);
        }
        Pool_Free_2_00128580(gEnemyListSbss_00202278, (void *)p->x8);
    }
    if (p->x4B0 != NULL && (s = p->x518) != NULL && p->x4B0->xC.b6) {
        for (i = 0; i < 8; i++) {
            if (s->x124[i] != 0) {
                Sfx_Release_1_00167030(s->x124[i]);
            }
        }
    }
    Sfx_RegisterList_0_00169D00(p->x580, 8);
    if (p->x5A0 != 0xFF) {
        EnemyMgr_FreeSlot_0_001A5070(a0);
    }
    Pool_Free_2_00128580(gEnemyListSbss_00202278, a0);
}

/* Enemy_Despawn_0_001A6C10 */
void Enemy_Despawn_0_001A6C10(A_Enemy_Despawn_0_001A6C10 *a) {
    if (a != NULL) {
        if (!a->b0 || !a->b2) return;
        Enemy_SetVisible_1_001A7030(a, 0, 1);
        Sfx_ReleaseOwned_0_00167580(a);
        a->b2 = 0;
    }
}

/* Enemy_Respawn_1_001A6C90 */

void Enemy_Respawn_1_001A6C90(u8 *arg0) {
    u8 *temp_17;
    u8 **temp_2;
    u8 *temp_16;

    if (arg0 != NULL) {
        if (!(M2C_FIELD(arg0, u8 *, 0x5A0) & 1)) {
            ((BF_5A1_4_1 *)arg0)->f = 1;
            return;
        }
        ((BF_5A1_4_1 *)arg0)->f = 0;
        ((BF_5A0_2_1 *)arg0)->f = 1;
        temp_2 = M2C_FIELD(arg0, u8 ***, 0x4A8);
        if (temp_2 != NULL) {
            temp_17 = *temp_2;
            temp_16 = M2C_FIELD(arg0, u8 **, 0x518);
            Map_DecodeTransform_0_001B59E0__as_Enemy_Respawn_1_001A6C90(M2C_FIELD(temp_17, s32 *, 0x13C) + (M2C_FIELD(arg0, u16 *, 0x4AC) * 0x54), temp_16, temp_16 + 0x20, temp_16 + 0x50);
            sceVu0AddVector(temp_16, temp_16, temp_17 + 0x10);
            sceVu0CopyVector(temp_16 + 0x10, temp_16);
            sceVu0CopyVector(temp_16 + 0x30, temp_16 + 0x20);
        }
        Enemy_InitBody_1_001A6DC0(arg0);
        if (M2C_FIELD(arg0, u16 *, 0) != 0) {
            Enemy_InitState_1_00136700(arg0);
            Enemy_SetVisible_1_001A7030(arg0, 1, 0);
        }
    }
}

/* Enemy_InitBody_1_001A6DC0 */
void Enemy_InitBody_1_001A6DC0(Actor *a0) {
    Sub_Enemy_InitBody_1_001A6DC0 *b;
    u32 i;
    Src_Enemy_InitBody_1_001A6DC0 *e;
    Ent_Enemy_InitBody_1_001A6DC0 *ent;
    u16 *t;

    if (a0 != 0 && *(u16 *)a0 != 0) {
    t = (u16 *)a0->unk4B0;
    b = (Sub_Enemy_InitBody_1_001A6DC0 *)a0->unk518;
    b->m16C = *t;
    b->f120.f.b0 = 0;
    b->f120.f.b1 = 0;
    memset(b->mC0, 0, 0x60);
    memset(b->m144, 0, 0x28);
    for (i = 0; i < *(u32 *)(a0->pad000 + 0x7C); i++) {
        e = ((Src_Enemy_InitBody_1_001A6DC0 **)a0)[i + 0x12D];
        ent = &((Ent_Enemy_InitBody_1_001A6DC0 *)a0->unk51C)[i];
        ent->m15C = e->m20;
        ent->f160.f.b0 = 0;
        ent->f160.f.b2 = 0;
        memset(ent->m00, 0, 0x20);
        memset(ent->m20, 0, 0x20);
        memset(ent->m40, 0, 0x20);
        memset(ent->m60, 0, 0x20);
        if (!(e->mAC <= 0.0f)) {
            ent->m8C = 0xC2C80000;
            ent->m9C = 0xC2C80000;
        }
        Enemy_InitPartState_1_001A8510(a0, i);
        Enemy_ResetPartAnim_1_001A8670(a0, i);
    }
    memset(a0->pad520, 0, 0x18);
    a0->pad000[0x80] = 0;
    a0->flags5A1.f.b5 = 0;
    Script_InitContext_1_00166F90(*(s32 *)(a0->pad000 + 0x4A4), *(s32 *)(a0->pad000 + 0xC), *(s32 *)(a0->pad000 + 0x4A0), 8);
    Mdl_UpdateBoneMatrices_0_00171270(*b->pB0, gMatrixFromData_001F2170, 0);
    Mdl_UpdateBoneMatrices_0_00171270(*b->pB0, gMatrixFromData_001F2170, 1);
    }
}

/* Enemy_SetPartModel_0_001A6FF0 */
void Enemy_SetPartModel_0_001A6FF0(Obj_Enemy_Draw_1_001A5DE0 *o, B_Enemy_SetPartModel_0_001A6FF0 *b, u16 i)
{
    E_Enemy_SetPartModel_0_001A6FF0 *e = &b->t->tbl[i];
    o->b = b;
    o->i = i;
    o->v = e->v;
}

/* Enemy_SetVisible_1_001A7030 */
void Enemy_SetVisible_1_001A7030(O_Enemy_SetVisible_1_001A7030 *arg0, s32 arg1, s32 arg2) {
    s8 *u;
    T_Enemy_SetVisible_1_001A7030 *t;
    S_Enemy_SetVisible_1_001A7030 *s;
    s32 i;

    u = (s8 *)arg0->u;
    t = arg0->t;
    if (arg0->s != NULL) {
        for (i = 0; i < arg0->n; i++) {
            s = &arg0->s[i];
            if (s != NULL && s->h != NULL) {
                if (s->b2 && arg2 == 0) {
                    Sfx_SetFlag_0_00167640(s->h, 0);
                } else {
                    Sfx_SetFlag_0_00167640(s->h, arg1);
                }
            }
        }
    }
    if (u != NULL && t != NULL) {
        for (i = 0; i < 8; i++, t = (T_Enemy_SetVisible_1_001A7030 *)((s8 *)t + 0x40), u += 4) {
            s = &arg0->s[arg0->map[M2C_FIELD(t, u8 *, 0x2E2)]];
            if (M2C_FIELD(u, void **, 0x124) != NULL) {
                if (s != NULL && s->b2 && arg2 == 0) {
                    Sfx_SetFlag_0_00167640(M2C_FIELD(u, void **, 0x124), 0);
                } else {
                    Sfx_SetFlag_0_00167640(M2C_FIELD(u, void **, 0x124), arg1);
                }
            }
        }
    }
}

/* Enemy_LoadSfx_0_001A71B0 */
static inline s32 load(O_Enemy_LoadSfx_0_001A71B0 *o, u16 id, volatile s32 *flag) {
    s32 r;
    r = 0;
    if (id) {
        if (Sfx_IsLoaded_2_00169BB0(id)) {
            r = Sfx_Spawn_2_00169B50(id, 1, 0, 0);
            *flag = 1;
        } else {
            r = Sfx_SpawnFromStam_2_00169BD0(id, o->mp->m->x10, o->buf, 1, 0, 0);
            *flag = 0;
        }
    }
    return r;
}

void Enemy_LoadSfx_0_001A71B0(O_Enemy_LoadSfx_0_001A71B0 *o) {
    s32 i;
    Ent_Enemy_LoadSfx_0_001A71B0 *e;
    volatile s32 flag;
    s32 id;
    Q_Enemy_LoadSfx_0_001A71B0 *q;
    u16 id1;

    Sfx_LoadStam_1_00169D70(o->mp->m->x10, o->buf, 8);
    for (i = 0; i < o->n; i++) {
        Def *d = o->defs[i];
        e = &o->ents[i];
        if (d->id) {
            e->x164 = load(o, d->id, &flag);
            e->b1 = flag;
        }
    }
    if (((T0 *)o->t)->c6) {
        q = o->q;
        q->m = 0;
        for (i = 0; i < 8; i++) {
            id = ((T0 *)(o->t + i * 0x40))->id;
            if (id) {
                s32 r = 0;
                if (id) {
                    if (Sfx_IsLoaded_2_00169BB0(id)) {
                        r = Sfx_Spawn_2_00169B50(id, 1, 0, 0);
                        flag = 1;
                    } else {
                        r = Sfx_SpawnFromStam_2_00169BD0(id, o->mp->m->x10, o->buf, 1, 0, 0);
                        flag = 0;
                    }
                }
                q->x124[i] = r;
                q->m |= (u16)(flag << i);
            }
        }
    }
}

/* Enemy_Spawn_0_001A7420 */

void Enemy_Spawn_0_001A7420(A_Enemy_Spawn_0_001A7420 **pp) {
    Vec v0;
    Vec v1;
    u8 buf[0x100];
    A_Enemy_Spawn_0_001A7420 *a;
    Sub_Enemy_Spawn_0_001A7420 *b;
    s8 *base;
    s32 ***p4;
    s32 i;
    s32 bs;
    Src_Enemy_Spawn_0_001A7420 *e;
    Ent_Enemy_Spawn_0_001A7420 *ent;
    Mdl *m;

    a = *pp;
    p4 = a->m4;
    bs = *(*p4)[4];
    a->m4B0 = bs + a->m10;
    a->m514 = bs + a->m14;
    for (i = 0; i < a->m7C; i++) {
        a->m4B4[i] = (Src_Enemy_Spawn_0_001A7420 *)(bs + a->m18[i]);
    }
    a->m518 = (Sub_Enemy_Spawn_0_001A7420 *)a->m8[0];
    a->m51C = (s32)a->m518 + 0x640;
    b = a->m518;
    a->m518->pB0 = Mdl_CreateInstance_0_00174230(gEnemyListSbss_00202280, p4, -1, -1);
    a->m518->pB0[0]->f24.b2 = 0;
    a->m518->pB0[0]->f24.b5 = 1;
    a->m518->m0.y = -170.0f;
    b->m16C = *(u16 *)a->m4B0;
    a->m81 = 0;
    b->mB4 = 0xFF;
    b->mB5 = 0xFF;
    for (i = 0; i < a->m7C; i++) {
        e = ((Src_Enemy_Spawn_0_001A7420 **)a)[i + 0x12D];
        ent = &((Ent_Enemy_Spawn_0_001A7420 *)a->m51C)[i];
        switch (e->m2C & 7) {
        case 1:
            b->mB4 = e->m2A;
            b->mB6 = i;
            break;
        case 2:
            b->mB5 = e->m2A;
            b->mB7 = i;
            break;
        }
        ent->m15C = e->m20;
        ent->m164 = 0;
        if (!(e->mAC <= 0.0f)) {
            a->m82[a->m81] = i;
            a->m81++;
            ent->m8C = 0xC2C80000;
            ent->m9C = 0xC2C80000;
        }
    }
    m = b->pB0[0];
    base = (s8 *)(gSfxAllSbss_00201F2C * (m->m6 * 0x140 + 0x200) + (s32)m->m40);
    Mdl_UpdateBoneMatricesCur_0_00171540(m, gMatrixFromData_001F2170);
    sceVu0CopyVector(&v0, base + (b->mB5 + 1) * 0x140 + 0xF0);
    sceVu0CopyVector(&v1, base + (b->mB4 + 1) * 0x140 + 0xF0);
    b->m170 = v0.y - v1.y;
    if (gEnemyListData_001F33A0[a->m0] != 0) gEnemyListData_001F33A0[a->m0](a, 0.0f);
    if (a->m518->m50.x == 0.0f) sceVu0CopyVector(&a->m518->m50, &gMatrixFromData_001F2120);
    if (a->m4A8 != 0) {
        s8 *s = (s8 *)*a->m4A8;
        Sub_Enemy_Spawn_0_001A7420 *t = a->m518;
        Map_DecodeTransform_0_001B59E0(*(s8 **)(s + 0x13C) + a->m4AC * 0x54, &t->m0, &t->m20, &t->m50);
        sceVu0AddVector(&t->m0, &t->m0, s + 0x10);
        sceVu0CopyVector(&t->m10, &t->m0);
        sceVu0CopyVector(&t->m30, &t->m20);
    }
    a->m49C = 0;
    a->m4A4 = 0;
    if (a->m0 != 0) {
        EnemyScr_GetScriptPath_3_00142930(a->m0, buf);
        a->m4A4 = Pool_Alloc_3_001288C0(gEnemyListSbss_00202278, 0x1554);
        Script_InitContext_1_00166F90(a->m4A4, a->mC, a->m4A0, 8);
    }
    if (a->m0 != 0) Enemy_UpdateModelMatrix_0_001A7E60(a);
    Enemy_LoadSfx_0_001A71B0(a);
    a->f5A0.b1 = 0;
    a->f5A0.b0 = 1;
}

/* EnemyData_Parse_0_001A7810 */

/* EnemyData_Parse_0_001A7810 */
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

void EnemyData_Parse_0_001A7810(Obj_EnemyData_Parse_0_001A7810 **a0, Src **a1) {
    s32 dbc1;
    s32 dbc2;
    u8 *base;
    Obj_EnemyData_Parse_0_001A7810 *o;
    s32 n;
    s32 rcs;
    Ch *c;
    Ch *d;
    H_EnemyData_Parse_0_001A7810 *h;
    u32 i;
    u32 j;
    u32 cnt;
    s32 k;
    s32 m;
    El *e;
    s32 tbl[24];

    dbc2 = 0;
    dbc1 = 0;
    n = 0;
    rcs = 0;
    o = *a0;
    base = *(*a1)->x10;
    switch (*(s32 *)base) {
    case 0x4D415453:
        c = (Ch *)(base + ((Ch *)base)->off);
        cnt = ((Ch *)base)->xE;
        for (i = 0; i < cnt; i++) {
            if (c->x0 == (gEnemyListRodata_001FD960[0] | (gEnemyListRodata_001FD960[1] << 8) | (gEnemyListRodata_001FD960[2] << 16) | (gEnemyListRodata_001FD960[3] << 24))) break;
            c = (Ch *)((u8 *)c + c->x4);
        }
        d = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            switch (d->x0) {
            case 0x61444243:
                h = &d->h;
                dbc1 = DATA(h) - base;
                h = (H_EnemyData_Parse_0_001A7810 *)((u8 *)h + h->a);
                dbc2 = DATA(h) - base;
                break;
            case 0x61545043:
                h = &d->h;
                tbl[n++] = DATA(h) - base;
                break;
            case 0x61524353:
                h = &d->h;
                rcs = DATA(h) - base;
                if (h->b == 0) rcs = 0;
                break;
            }
            d = (Ch *)((u8 *)d + d->x4);
        }
        break;
    }
    o->x8 = Pool_Alloc_3_001288C0__as_EnemyData_Parse_0_001A7810(gEnemyListSbss_00202278, n * 0x170 + 0x640);
    o->x4 = a1;
    o->x10 = dbc1;
    o->x14 = dbc2;
    o->x4A0 = rcs;
    for (k = 0; k < 0x100; k++) {
        o->t[0][k] = 0xFF;
        o->t[1][k] = 0xFF;
        o->t[2][k] = 0xFF;
        o->t[3][k] = 0xFF;
    }
    for (k = 0; k < n; k++) {
        e = (El *)(base + tbl[k]);
        for (m = e->x2A; m < e->x2A + e->x2B; m++) {
            o->t[0][m] = k;
            if (e->x2D.f.b4) o->t[1][m] = (u8)k;
            if (e->x2D.f.b5) o->t[2][m] = k;
            if (e->x20) o->t[3][m] = k;
        }
    }
    for (k = 0; k < n; k++) {
        o->x18[k] = tbl[k];
    }
    o->x78 = (*a1)->x14;
    o->x7C = n;
}

/* EnemyData_ParseWrap_0_001A7C60 */

void EnemyData_ParseWrap_0_001A7C60(void **arg0, void **arg1, u32 arg2, s8 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7)
{
    EnemyData_Parse_0_001A7810__as_EnemyData_ParseWrap_0_001A7C60(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

/* EnemyData_LoadTextures_0_001A7C70 */
u8 **EnemyData_LoadTextures_0_001A7C70(s32 arg0) {
    u8 *temp_3;
    u8 **temp_2;
    s32 **var_16;

    var_16 = (s32 **) (NULL);
    temp_2 = (u8 **) (Tex_LoadArchive_0_0016F950(gEnemyListSbss_00202280__as_EnemyData_Parse_0_001A7810, (u8 **) arg0));
    if (temp_2 == NULL) {
        return NULL;
    }
    temp_3 = (u8 *) (*temp_2);
    if (((BF_3C_4_1 *)temp_3)->f != 0) {
        var_16 = (s32 **) (M2C_FIELD(temp_3, s32 ***, 0x10));
    }
    if (var_16 != NULL) {
        Tex_RegisterTtix_0_00178080(var_16);
    }
    return (u8 **) (temp_2);
}
#undef Mdl_GetFrameData_0_001715B0
#undef sceVu0AddVector
#undef gEnemyListBss_004A4570
#undef gMatrixFromData_001F2170

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gEnemyListSbss_00202278, gEnemyListSbss_00202280 */
s32 gEnemyListSbss_00202278;
s32 gEnemyListSbss_00202280;
#endif



#ifdef NONMATCHING
#pragma explicit_zero_data on
void Player_LoadModel_1_001C9CD0(void);
/* data group (src/game/data/title_nop_data.c): D_001F33A0__grp: gEnemyListData_001F33A0@0x0 */
s32 D_001F33A0__grp[0x100] __attribute__((aligned(16))) = { (s32)Player_LoadModel_1_001C9CD0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_byte_bss.c): gEnemyListBss_004A4570__grp: gEnemyListBss_004A4570@0x0, gEnemyListBss_004A4774@0x204, gEnemyListBss_004A4878@0x308 */
unsigned char gEnemyListBss_004A4570__grp[0x310] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/enemy_list_rodata_001FD960.c): gEnemyListRodata_001FD960__grp: gEnemyListRodata_001FD960@0x0, gEnemyListRodata_001FD961@0x1, gEnemyListRodata_001FD962@0x2, gEnemyListRodata_001FD963@0x3 */
unsigned int gEnemyListRodata_001FD960__grp[0x4] __attribute__((aligned(16))) = { 0x49435453, 0x0, 0x0, 0x0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/enemy_list_rodata.c): D_001FD8C8__grp: gEnemyListRodata_001FD8C8@0x0 */
int D_001FD8C8__grp[0x2] __attribute__((aligned(8))) = { 0, 0 };
#endif
