#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/core.h"
#include "game/input.h"
#include "game/map.h"
#include "game/map_object.h"
#include "game/player.h"
#include "game/save.h"
#include "game/script.h"
#include "game/enemy.h"
#include "game/gfx.h"
#include "game/sound.h"
#include "game/ui.h"
typedef struct { s16 id; s16 pad; s32 off; } Ent_MapObj_FindById_0_00179DB0;
typedef struct { u8 pad[6]; s16 n; u8 pad8[8]; Ent_MapObj_FindById_0_00179DB0 e[1]; } Tbl;
typedef struct { s32 id; u8 pad[0x160]; Tbl *x164; } Mdl;
typedef struct { s32 x0; s32 x4; s32 x8; u8 padC[0x10]; f32 x1C; u8 pad20[0xC]; s32 x2C; } Q_Event_FindEnemyByMotion_0_00179E50;
typedef struct { u8 pad[0xE]; u16 xE; } E1;
typedef struct { u8 pad[0x1A]; u16 x1A; } E2;
typedef struct { u8 pad[0xC]; s32 *xC; } E3;
typedef struct { u8 pad[8]; u8 x8; u8 p9[7]; u8 x10; u8 p11[7]; u8 x18; u8 p19[7]; u8 x20; u8 p21[7]; u32 x28; } Arg_MapCmd_SetFlag2034_0_0017A640;
typedef struct { u8 b; u8 pad[7]; } W_MapCmd_SetFlag2034_0_0017A640_;
typedef struct { W_MapCmd_SetFlag2034_0_0017A640_ x0; W_MapCmd_SetFlag2034_0_0017A640_ x8; W_MapCmd_SetFlag2034_0_0017A640_ x10; W_MapCmd_SetFlag2034_0_0017A640_ x18; } Arg_MapCmd_SetFlagBits_0_0017A920;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } Arg_MapCmd_SetFlag2034_0_0017A640_;
typedef struct { s32 i; s32 pad; } W_MapCmd_SetLight_0_0017ADE0;
typedef struct { f32 f; s32 pad; } F;
typedef struct { W_MapCmd_SetLight_0_0017ADE0 x0; W_MapCmd_SetLight_0_0017ADE0 x8; W_MapCmd_SetLight_0_0017ADE0 x10; F v[15]; } Arg_MapCmd_SetLight_0_0017ADE0;
typedef struct { u8 p0[8]; s32 x8; u8 pC[4]; s32 x10; u8 p14[4]; f32 x18; u8 p1c[4]; f32 x20; u8 p24[4]; f32 x28; u8 p2c[4]; f32 x30; u8 p34[4]; f32 x38; u8 p3c[4]; f32 x40; u8 p44[4]; f32 x48; u8 p4c[4]; f32 x50; } O_MapCmd_SetLight_0_0017ADE0;
typedef struct { s32 x0, x4, h, xc, a, x14, b, x1c, c, x24; f32 t; s32 x2c, fl; } S_MapCmd_SetFlag2034_0_0017A640;
typedef struct { char pad[8]; s32 a; char p[4]; s32 b; } Obj_MapCmd_SetLight_0_0017ADE0;
typedef struct { char pad[0x50]; unsigned char : 3; unsigned char f : 1; } BF_50_3_1;
typedef struct { char pad[0x52]; unsigned char : 7; unsigned char f : 1; char rest[0x2D]; } E_MapCmd_SetLight_0_0017ADE0;
typedef struct { char pad[0x180]; E_MapCmd_SetLight_0_0017ADE0 *e; } T;
typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; s32 f; } Obj_MapCmd_HideObject_0_0017B8A0;
typedef struct { char p[0x1C]; u16 x1C; char q[0x12]; } E_MapCmd_FindObjectNode_0_0017B930;
typedef struct { s32 a, b; } R_MapCmd_SetLight_0_0017ADE0;
typedef struct { char p[0x6C]; u16 x6C; char q[0x134-0x6E]; E_MapCmd_FindObjectNode_0_0017B930 *x134; char r[0x178-0x138]; R_MapCmd_SetLight_0_0017ADE0 *x178; } O_MapCmd_FindObjectNode_0_0017B930;
typedef struct { s32 a; u8 b0 : 1; } R_MapCmd_SetObjectNode_0_0017B9E0;
typedef struct { char p[8]; s32 x8; char p2[4]; s32 x10; char p3[4]; s32 x18; } A_MapCmd_SetFlag2034_0_0017A640;
typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[0xC]; f32 x; char p2[4]; f32 y; char p3[4]; f32 z; } Obj_MapCmd_SetFlag2034_0_0017A640;
typedef struct { f32 x, y, z, w; } V;
typedef struct { u8 pad[0x180]; s8 *x180; } C;
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[0xC]; u8 x20; u8 pad21[7]; u16 x28; u8 pad2A[6]; f32 x30; u8 pad34[4]; f32 x38; } O;
typedef struct { f32 x, z; } V2;
typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; f32 x; char p2[4]; f32 y; char p3[4]; f32 z; } Obj_MapCmd_PlaySeAtXYZ_1_0017BC00;
typedef struct { u8 pad[8]; s32 x8; u8 pc[4]; s32 x10; u8 p14[4]; u8 x18; u8 p19[7]; u16 x20; u8 p22[6]; f32 x28; u8 p2c[4]; f32 x30; } A_MapCmd_PlaySeAtXYZ_1_0017BC00_;
typedef struct { f32 a; f32 b; } P_MapCmd_PlaySeAtXYZ_1_0017BC00;
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[0x1C]; f32 f[0x14]; } O_MapCmd_PlaySeAtXYZ_1_0017BC00;
typedef struct { u8 pad0[8]; u8 x8; u8 pad9[7]; s32 x10; } P_MapCmd_WaitEvent_0_0017C2A0;
typedef struct { char pad[8]; u32 a; char p0[4]; f32 x; char p1[4]; f32 y; char p2[4]; f32 z; char p3[4]; f32 w; } S_MapCmd_PlaySeAtXYZ_1_0017BC00;
typedef struct { char pad[8]; s32 a; } Obj_MapCmd_GetCameraState_0_0017C4B0;
typedef struct { u8 b; u8 pad[7]; } W;
typedef struct { W x0; W x8; W x10; } Arg_MapCmd_PlaySeAtXYZ_1_0017BC00;
typedef struct { u8 pad[8]; s32 x8; u8 p0[4]; s32 x10; u8 p1[4]; s32 x18; u8 p2[4]; s32 x20; u8 p3[4]; f32 x28; } Arg_MapCmd_FadeLight_0_0017C6F0;
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad1C[0x38]; } E;
typedef struct { u8 pad[0x70]; u16 n; u8 pad72[0x26]; u32 x98[2]; u32 xA0[39]; E *x13C; } X;
typedef struct { u8 pad[8]; u8 x8; u8 pad9[7]; u16 x10; u8 pad12[6]; u8 x18; } S_MapCmd_ResetObjects_0_0017C930;
typedef struct { char pad[8]; f32 v; } Obj_MapCmd_PlaySeAtXYZ_1_0017BC00_;
typedef struct { char pad[8]; u32 a; char p1[4]; u32 b; char p2[4]; f32 x; char p3[4]; f32 y; } S_MapCmd_PlaySeAtXYZ_1_0017BC00_;
typedef struct { u8 pad[8]; s32 id; s32 p0C; f32 x10, p14, x18, p1C, x20, p24, x28, p2C, x30, p34, x38, p3C, x40, p44, x48, p4C, x50, p54; u16 x58; u16 p5A, p5C, p5E; u16 x60; u16 p62; s32 p64; s32 x68; } O_MapCmd_SetEffectPos_0_0017CAC0;
typedef struct { char pad[8]; s32 a; char pad2[4]; void * b; char pad3[4]; u16 c; } S_MapCmd_SetPlayerVar3_0_0017CD00;
typedef struct { char pad[8]; s32 v; } Obj_MapCmd_SetPlayerVar3_0_0017CD00;
typedef struct { s32 pad[2]; s32 n; s32 pad2; f32 f; s32 pad3; s32 m; } A_MapCmd_SetFlag2034_0_0017A640_;
typedef struct { char pad[8]; f32 x; char p0[4]; f32 y; char p1[4]; f32 z; } Obj_MapCmd_WarpPlayer_0_0017CE20;
typedef struct { u8 p[0x20]; f32 x; f32 y; f32 z; } R_MapCmd_SetPlayerVar3_0_0017CD00;
typedef struct { u8 p[0x18]; R_MapCmd_SetPlayerVar3_0_0017CD00 *r; } Q_MapCmd_SetFlag2034_0_0017A640;
typedef struct { u8 p[0x518]; u8 *x518; } Actor_;
typedef struct { char pad[0x20]; f32 r[3]; } R_MapCmd_SetPlayerPos_1_0017CF40;
typedef struct { char pad[0x18]; R_MapCmd_SetPlayerPos_1_0017CF40 *r; } T_MapCmd_SetPlayerVar3_0_0017CD00;
typedef struct { char pad[0x518]; u8 *p; } S_MapCmd_SetPlayerPos_1_0017CF40;
typedef struct { char pad[8]; f32 x; char p0[4]; f32 y; char p1[4]; f32 z; } Obj_MapCmd_SetFlag2034_0_0017A640__;
typedef struct { u8 pad[8]; s32 x8; s32 pC; s32 x10; } Arg_MapCmd_SetFlag2034_0_0017A640__;
typedef struct { char pad[0x3A1]; unsigned int : 5; unsigned int f : 1; } T_MapCmd_GetPlayerFlag_0_0017D0E0;
typedef struct { char pad[8]; s16 h; } Obj_MapCmd_GetEquip_0_0017D130;
typedef struct { u8 pad[0x24]; f32 x24; } H;
typedef struct { u8 pad[0x18]; H *x18; } R;
typedef struct { u8 pad[0x180]; R r; } Sub;
typedef struct { u8 pad[0x518]; Sub *x518; } S_MapCmd_GetEquip_0_0017D130;
typedef struct { u8 p[0x58]; f32 x58; u8 p5c[0x24]; } N_MapCmd_GetEquip_0_0017D130;
typedef struct { u8 p[0x180]; N_MapCmd_GetEquip_0_0017D130 *n; } Obj_MapCmd_SetObjectAlpha_0_0017D3D0;
typedef struct { u8 pad[8]; s32 x8; s32 pC; s32 x10; s32 p14; f32 x18; } Arg_MapCmd_GetEquip_0_0017D130_;
typedef struct { u8 p[0x52]; Flags8 f; u8 p53[0x2D]; } N_MapCmd_SetObjectsAlpha_0_0017D480;
typedef struct { u8 p[0x180]; N_MapCmd_SetObjectsAlpha_0_0017D480 *n; } Obj_MapCmd_GetEquip_0_0017D130_;
typedef struct { s32 pad0[2]; s32 x8; s32 padC; s32 x10; s32 pad14; f32 x18; s32 pad1C; f32 x20; s32 pad24; f32 x28; } S_MapCmd_TranslateNode_0_0017D810;
typedef struct { s32 pad0[2]; s32 x8; s32 padC; s32 x10; s32 pad14; f32 x18; s32 pad1C; f32 x20; s32 pad24; f32 x28; } S_MapCmd_SetFlag2034_0_0017A640_;
typedef struct { char pad[8]; f32 x; char p1[4]; f32 y; char p2[4]; f32 z; char p3[4]; f32 w; } S_MapCmd_SetCameraTarget_0_0017DB40;
typedef struct { char p[8]; f32 x8; char p2[4]; f32 x10; char p3[4]; f32 x18; char p4[4]; f32 x20; char p5[4]; f32 x28; char p6[4]; s32 x30; } A_MapCmd_SetCameraTarget_0_0017DB40_;
typedef struct { u8 pad[8]; s16 x8; u8 p2[6]; s16 x10; u8 p3[6]; f32 x18; u8 p4[4]; f32 x20; u8 p5[4]; f32 x28; u8 p6[4]; f32 x30; u8 p7[4]; f32 x38; u8 p8[4]; f32 x40; } O_MapCmd_SetCameraTarget_0_0017DB40;
typedef struct { char pad[0x10]; int id; } S_MapCmd_GetObjectVar_0_0017DC70;
typedef struct { char pad[0x10]; s32 v; } Obj_MapCmd_SetCameraTarget_0_0017DB40;
typedef struct { char pad[0x53]; unsigned char : 1; unsigned char f : 1; } BF_53_1_1;
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[4]; s32 x18; } O_MapCmd_GetObjectFlag_0_0017DD90;
typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; s32 c; char p2[4]; s32 d; char p3[4]; f32 x; char p4[4]; f32 y; } Obj_MapCmd_PlayObjectAnim_0_0017DE40;
typedef struct { char pad[8]; s32 a; char pad2[4]; s32 b; } S_MapCmd_SetCameraTarget_0_0017DB40_;
typedef struct { char pad[8]; s32 a; char p0[4]; s32 b; char p1[4]; s32 c; } Obj_MapCmd_SetFlag2034_0_0017A640___;
typedef struct { u8 pad[8]; s32 x8; s32 pC; s32 x10; s32 p14; s32 x18; u8 p1C[0xC]; f32 x28; u8 p2C[0x24]; f32 x50; f32 p54; f32 x58; } Arg_MapCmd_SetFlag2034_0_0017A640___;
typedef struct { u8 pad[0x1C]; u16 id; u8 pad1E[3]; s8 x21; u8 pad22[0xE]; } E30;
typedef struct { s32 a; s32 b; } E8;
typedef struct { u8 pad[0x6C]; u16 count; u8 pad2[0x134-0x6E]; E30 *arr; u8 pad3[0x178-0x138]; E8 *e8; } Obj_MapCmd_SetObjectTexture_0_0017E150_;
typedef struct { char pad[8]; int kind; } Point;
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[4]; s32 x18; u8 pad1C[0x1C]; s32 x38; u8 pad3C[4]; s32 x40; } O_MapCmd_SetObjectTexture_0_0017E150;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[7];
    u16 h10;
    u8 pad12[6];
    f32 x18; f32 pad1c;
    f32 x20; f32 pad24;
    f32 x28; f32 pad2c;
    f32 x30; f32 pad34;
    f32 x38; f32 pad3c;
    f32 x40;
} O_MapCmd_SetSfxTransform_0_0017E390;
typedef struct { s8 pad[0x1A]; u16 x1A; s8 pad2[0x10]; } Ent_MapCmd_SetFlag2034_0_0017A640;
typedef struct {
    s32 id;
    s8 pad4[0x74];
    u16 n;
    s8 pad7A[0xD6];
    Ent_MapCmd_SetFlag2034_0_0017A640 *ents;
    s8 pad154[0x3C];
    s32 *x190;
    s8 pad194[0x44];
    u8 x1D8;
} Chr;
typedef struct { s32 p0; s32 p4; s32 id; s32 pC; s32 key; s32 p14; f32 x18; } Arg_MapCmd_SetObjectTexture_0_0017E150;
typedef struct { s32 p0; s32 p4; s32 id; s32 pC; s32 key; } Arg_MapCmd_GetSfxParamA_0_0017E760;
typedef struct { s32 p0; s32 p4; s32 id; s32 pC; s32 key; s32 p14; f32 x18; } Arg_MapCmd_SetObjectTexture_0_0017E150_;
typedef struct { s32 p0; s32 p4; s32 id; s32 pC; s32 key; } Arg;
extern Mdl **gMapSbss_00201E88[2];
extern u16 gMapCommandBss_00317238[];
extern u8 gDoorSbss_00202030;
extern s32 **gPlayerSbss_002022BC;
extern s32 gMapSbss_00201E80;
extern s32 gGameMainSbss_00201E94;
#ifndef NONMATCHING
extern u8 gMapCommandSbss_00202034;
extern s32 gMapCommandSbss_00202038;
#else
/* data twins (src/game/data/sbss.c): gMapCommandSbss_00202034 */
static u8 gMapCommandSbss_00202034;
/* data twins (src/game/data/sbss.c): gMapCommandSbss_00202038 */
static s32 gMapCommandSbss_00202038;
#endif
extern s8 **gMapSbss_00201E80__as_MapCmd_PlaySeAtXYZ_1_0017BC00_[2];
extern S_MapCmd_SetPlayerPos_1_0017CF40 *gPlayerSbss_002022E4__as_MapCmd_SetPlayerPos_1_0017CF40;
extern Actor_ *gPlayerSbss_002022E4__as_MapCmd_SetPlayerVar3_0_0017CD00;
extern S_MapCmd_GetEquip_0_0017D130 *gPlayerSbss_002022E4__as_MapCmd_GetEquip_0_0017D130_;
extern Mtx gMatrixFromData_001F2170;
u8* MapObj_FindById_0_00179DB0(s32 id, s32 key);
s32 Event_FindEnemyByMotion_0_00179E50(s32 arg0, s32 arg1);
s32 Event_CheckTrigger_0_00179F80(Q_Event_FindEnemyByMotion_0_00179E50 *q);
s32 Event_IsPlayerFacing_0_0017A480(char *a0, f32 *a1, f32 *a2);
void MapCmd_SetFlag2034_0_0017A640(void *arg0);
void MapCmd_FadeTo_1_0017A650(Arg_MapCmd_SetFlag2034_0_0017A640 *a0);
void MapCmd_NotifyEnemies_0_0017A790(u8 *o);
void MapCmd_SetMapVar_0_0017A850(void *arg0);
void MapCmd_GetFlagWord_0_0017A890(u8 *o);
void MapCmd_SetFlagBits_0_0017A920(Arg_MapCmd_SetFlagBits_0_0017A920 *p);
void MapCmd_GetPlayerStat_0_0017AA40(char *a0);
void MapCmd_GetLight_0_0017ABD0(Arg_MapCmd_SetFlag2034_0_0017A640_ *a);
void MapCmd_SetLight_0_0017ADE0(Arg_MapCmd_SetLight_0_0017ADE0 *a);
void MapCmd_GetGlow_0_0017AF20(s32 *a0);
void MapCmd_SetGlow_0_0017B060(O_MapCmd_SetLight_0_0017ADE0 *o);
void MapCmd_MoveObject_0_0017B0F0(S_MapCmd_SetFlag2034_0_0017A640 *s);
void MapCmd_RotateObject_0_0017B410(u8 *arg0);
void MapCmd_StopObject_0_0017B4D0(s8 *arg0);
void MapCmd_GetObjectState_0_0017B5A0(s8 *a0);
void MapCmd_GetDoorState_0_0017B730(Obj_MapCmd_SetLight_0_0017ADE0 *o);
void MapCmd_SetDoor_0_0017B780(void *arg0);
void MapCmd_GetValue_0_0017B7A0(s32 a);
void MapCmd_ShowObject_0_0017B800(u8 *arg0);
void MapCmd_HideObject_0_0017B8A0(Obj_MapCmd_HideObject_0_0017B8A0 *o);
R_MapCmd_SetLight_0_0017ADE0* MapCmd_FindObjectNode_0_0017B930(s32 a, s32 id);
void MapCmd_SetObjectNode_0_0017B9E0(volatile A_MapCmd_SetFlag2034_0_0017A640 *arg0);
void MapCmd_StopSe_1_0017BA40(void *arg0);
void MapCmd_PlaySeAt_1_0017BA50(Obj_MapCmd_SetFlag2034_0_0017A640 *o);
void MapCmd_PlaySeOnObject_0_0017BAC0(O *o);
void MapCmd_PlaySeAtXYZ_1_0017BC00(Obj_MapCmd_PlaySeAtXYZ_1_0017BC00 *o);
void MapCmd_PlaySeOnObjectB_0_0017BC50(A_MapCmd_PlaySeAtXYZ_1_0017BC00_ *a);
void MapCmd_SpawnSfxOnObject_0_0017BD70(s8 *arg0);
void MapCmd_SpawnSfxOnObjectB_0_0017BF50(s8 *arg0);
void MapCmd_SetObjectAnim_0_0017C150(O_MapCmd_PlaySeAtXYZ_1_0017BC00 *o);
void MapCmd_GetTimer_0_0017C270(s32 a);
void MapCmd_WaitEvent_0_0017C2A0(P_MapCmd_WaitEvent_0_0017C2A0 *p);
void MapCmd_SetCameraPath_0_0017C490(S_MapCmd_PlaySeAtXYZ_1_0017BC00 *s);
void MapCmd_GetCameraState_0_0017C4B0(Obj_MapCmd_GetCameraState_0_0017C4B0 *o);
void MapCmd_GetEnemyRotation_1_0017C540(Arg_MapCmd_PlaySeAtXYZ_1_0017BC00 *a);
void MapCmd_GetEnemyPosition_1_0017C620(u8 *o);
void MapCmd_SetObjParam_0_0017C6D0(void *arg0);
void MapCmd_FadeLight_0_0017C6F0(volatile Arg_MapCmd_FadeLight_0_0017C6F0 *a);
void MapCmd_RequestEvent_0_0017C890(void *arg0);
void MapCmd_ResetObjects_0_0017C930(S_MapCmd_ResetObjects_0_0017C930 *s);
void MapCmd_IsBusy_0_0017CA10(s32 a);
void MapCmd_SetFloat_0_0017CA60(Obj_MapCmd_PlaySeAtXYZ_1_0017BC00_ *o);
void MapCmd_SetTexScroll_1_0017CAA0(S_MapCmd_PlaySeAtXYZ_1_0017BC00_ *s);
void MapCmd_SetEffectPos_0_0017CAC0(O_MapCmd_SetEffectPos_0_0017CAC0 *o);
void MapCmd_Random_2_0017CB50(s32 a);
void MapCmd_GetWeather_0_0017CBA0(s8 *arg0);
void MapCmd_SetItemFlag_0_0017CC80(void *arg0);
void MapCmd_GetPlayerVar_0_0017CC90(s32 arg0);
void MapCmd_SetPlayerVar4_0_0017CCE0(void *arg0);
void MapCmd_SetPlayerVar3_0_0017CD00(S_MapCmd_SetPlayerVar3_0_0017CD00 *s);
void MapCmd_GetPlayerStat2_0_0017CD10(Obj_MapCmd_SetPlayerVar3_0_0017CD00 *o);
void MapCmd_SetPlayerFlags_0_0017CD50(A_MapCmd_SetFlag2034_0_0017A640_ *a0);
void MapCmd_WarpPlayer_0_0017CE20(Obj_MapCmd_WarpPlayer_0_0017CE20 *o);
void MapCmd_RemoveItem_0_0017CE60(void *arg0);
void MapCmd_AddItem_0_0017CE70(void *arg0);
void MapCmd_GetPlayerPos_1_0017CE80(s32 a);
void MapCmd_SetPlayerPos_1_0017CF40(Obj_MapCmd_SetFlag2034_0_0017A640__ *o);
void MapCmd_SetPlayerPosVec_0_0017CFB0(Obj_MapCmd_SetFlag2034_0_0017A640__ *o);
void MapCmd_GetDistToObject_0_0017D000(Arg_MapCmd_SetFlag2034_0_0017A640__ *a0);
void MapCmd_GetPlayerFlag_0_0017D0E0(s32 a);
void MapCmd_GetEquip_0_0017D130(Obj_MapCmd_GetEquip_0_0017D130 *o);
void MapCmd_GetEffectState_0_0017D170(Obj_MapCmd_GetEquip_0_0017D130 *o);
void MapCmd_CopyVar_0_0017D1C0(u8 *a0);
void MapCmd_GetPlayerRot_1_0017D240(s32 a);
void MapCmd_GetPlayerVarB_0_0017D300(s32 arg0);
void MapCmd_GetPlayerPosB_0_0017D350(void *o);
void MapCmd_SetObjectAlpha_0_0017D3D0(Arg_MapCmd_GetEquip_0_0017D130_ *a);
void MapCmd_SetObjectsAlpha_0_0017D480(s8 *a);
void MapCmd_RotateNode_0_0017D5B0(s8 *arg0);
void MapCmd_RotateNodeRel_0_0017D6E0(s8 *arg0);
void MapCmd_TranslateNode_0_0017D810(S_MapCmd_TranslateNode_0_0017D810 *arg0);
void MapCmd_GetGlobal_0_0017D930(s32 a);
void MapCmd_TranslateNodeRel_0_0017D960(S_MapCmd_SetFlag2034_0_0017A640_ *arg0);
void MapCmd_GetNodePos_0_0017DA60(s8 *arg0);
void MapCmd_SetCameraTarget_0_0017DB40(S_MapCmd_SetCameraTarget_0_0017DB40 *s);
void MapCmd_Vibrate_1_0017DB60(A_MapCmd_SetCameraTarget_0_0017DB40_ *a);
void MapCmd_SetLightPos_0_0017DC00(O_MapCmd_SetCameraTarget_0_0017DB40 *o);
void MapCmd_GetObjectVar_0_0017DC70(S_MapCmd_GetObjectVar_0_0017DC70 *s);
void MapCmd_GetObjectVarB_0_0017DCD0(Obj_MapCmd_SetCameraTarget_0_0017DB40 *o);
void MapCmd_SetObjectFlag_0_0017DD10(u8 *arg0);
void MapCmd_GetObjectFlag_0_0017DD90(O_MapCmd_GetObjectFlag_0_0017DD90 *o);
void MapCmd_PlayObjectAnim_0_0017DE40(Obj_MapCmd_PlayObjectAnim_0_0017DE40 *o);
void MapCmd_SetObjectAnimB_0_0017DEA0(S_MapCmd_SetCameraTarget_0_0017DB40_ *s);
void MapCmd_SetObjectAnimC_0_0017DEB0(S_MapCmd_SetCameraTarget_0_0017DB40_ *s);
void MapCmd_GetObjectAnim_0_0017DEC0(Obj_MapCmd_SetFlag2034_0_0017A640___ *o);
void MapCmd_SpawnItem_0_0017DF20(Arg_MapCmd_SetFlag2034_0_0017A640___ *a0);
void MapCmd_PlayBgm_0_0017E050(s8 *arg0);
s32 MapCmd_SetObjectTexture_0_0017E150(s32 arg0, s32 id, s32 v);
void MapCmd_QueryEnemies_0_0017E220(Point *p);
void MapCmd_GetSfxState_0_0017E260(O_MapCmd_SetObjectTexture_0_0017E150 *o);
void MapCmd_SetSfx_0_0017E370(void *arg0);
void MapCmd_SetSfxTransform_0_0017E390(O_MapCmd_SetSfxTransform_0_0017E390 *o);
void MapCmd_SetSfxParamA_0_0017E5B0(Arg_MapCmd_SetObjectTexture_0_0017E150 *a);
void MapCmd_GetSfxParamA_0_0017E760(Arg_MapCmd_GetSfxParamA_0_0017E760 *a);
void MapCmd_SetSfxParamB_0_0017E940(Arg_MapCmd_SetObjectTexture_0_0017E150_ *a);
void MapCmd_GetSfxParamB_0_0017EAF0(Arg *a);
s32 Enemy_GetTargetHandle_0_0013EDE0(u8 *);
s32 Ent_IsNull0_1_0013EE30(void *);
E1* MapObj_GetNodeFlags_0_001B76C0(s32, s32);
E2* MapObj_GetNode_0_001B77A0(s32, s32);
E3* MapObj_Find_1_001B19A0(s32);
s32 Script_SendEvent_2_00166F80(s32, s32, s32);
s8* ActorList_Next_2_001A5460(s32 *);
void ActorList_SetCount_1_001A5440(s8 *);
u32 Enemy_Get5B1b1_1_0013EA70(s8 *);
u8 EnemyScr_Event2014_1_00141610(s8 *);
f32 sqrtf(f32);
void Enemy_GetParamAngles_0_0013DD50(char *, f32 *, f32 *);
void Player_CopyVec_0_00145780(Vec *);
void Enemy_CopyPosition_2_00140470(void *, void *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 cosf(f32);
void Player_GetForwardVector_2_001456B0(Vec *);
void Enemy_GetForwardVector_2_001403D0(char *, Vec *);
s32 ActorList_Next_2_001A5460__as_Event_FindEnemyByMotion_0_00179E50();
s32 Event_CheckTrigger_0_00179F80__as_Event_CheckTalk_0_00179F10(Msg *);
s32 Event_IsPlayerFacing_0_0017A480__as_Event_CheckTrigger_0_00179F80(s8 *, f32 *, f32 *);
void ScreenFx_SetFadeTarget_0_00159400(f32, Vec *);
s32 Enemy_GetMotionId_0_0013ED20(void *p);
void EnemyScr_Event2015_1_00141510(s8 *, u8, u8, u8);
u8* Script_GetArgPtr_2_00165130(u8 *o, s32 b);
u32 MapState_GetWord_1_001AA540(u8 a, s16 b);
void MapState_SetWord_1_001AA5D0(u8, s16, u32);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerStat_0_0017AA40(char *, s32);
f32* LightGroup_Get_0_0015B900(s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(Arg_MapCmd_SetFlag2034_0_0017A640_ *, s32);
s32 Map_GetGlowIndex_0_001B0C70(s32, s32);
void Glow_GetParams_0_0015D760(u16, Vec *, Vec *, f32 *, f32 *);
void Glow_SetParams_0_0015D800(u16, Vec *, Vec *, f32, f32);
f32* Map_GetFogEntry_0_001B40F0(f32 *, s32);
void Map_UpdateFog_0_001B4100(f32 *);
s32 Map_UpdateFog_0_001B4100__as_MapCmd_RotateObject_0_0017B410();
u8* MapObj_Find_1_001B19A0__as_MapCmd_RotateObject_0_0017B410(s32);
u8* Map_GetFogEntry_0_001B40F0__as_MapCmd_RotateObject_0_0017B410(u8 *, s32);
s32 MapObj_Find_1_001B19A0__as_MapCmd_StopObject_0_0017B4D0(s32);
s8* Map_GetFogEntry_0_001B40F0__as_MapCmd_StopObject_0_0017B4D0(s32, s32);
M2C_UNK Map_UpdateFog_0_001B4100__as_MapCmd_StopObject_0_0017B4D0(s32);
s32 MapObj_Find_1_001B19A0__as_MapCmd_GetObjectState_0_0017B5A0(s32);
s8* Map_GetFogEntry_0_001B40F0__as_MapCmd_GetObjectState_0_0017B5A0(s32, s32);
void Map_UpdateFog_0_001B4100__as_MapCmd_GetObjectState_0_0017B5A0(s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(s8 *, s32);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetDoorState_0_0017B730(Obj_MapCmd_SetLight_0_0017ADE0 *o, s32 b);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetValue_0_0017B7A0(s32 a, s32 b);
s32 MapObj_Find_1_001B19A0__as_MapCmd_ShowObject_0_0017B800();
T* MapObj_Find_1_001B19A0__as_MapCmd_HideObject_0_0017B8A0(s32 a);
O_MapCmd_FindObjectNode_0_0017B930* MapObj_Find_1_001B19A0__as_MapCmd_FindObjectNode_0_0017B930(s32);
R_MapCmd_SetObjectNode_0_0017B9E0* MapCmd_FindObjectNode_0_0017B930__as_MapCmd_SetObjectNode_0_0017B9E0(s32, s32);
s32 Snd_PlaySeAt_2_001315A0(s32, s32, V*);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAt_1_0017BA50(Obj_MapCmd_SetFlag2034_0_0017A640 *o, s32 b);
s8* Mdl_GetFrameData_0_001715B0(s32);
s32 Snd_PlaySeVolPan_1_00131520(s32, s32, void *, s32);
void SndCh_GetPosition_1_00131180(s32, void *);
C* MapObj_Find_1_001B19A0__as_MapCmd_PlaySeOnObject_0_0017BAC0(u8);
s32 MapObj_GetNodeIndex_0_001B7840__as_MapCmd_PlaySeOnObject_0_0017BAC0(u8, u16);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeOnObject_0_0017BAC0(O *, s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(void *, s32);
s8* Map_FindSfxEntry_0_001B7300(s8 *, s32);
s8* MapObj_Find_1_001B19A0__as_MapCmd_SpawnSfxOnObject_0_0017BD70(s32);
s8* MapObj_Find_1_001B19A0__as_MapCmd_SpawnSfxOnObjectB_0_0017BF50(s32);
f32* Map_FindSfxEntry_0_001B7300__as_MapCmd_SpawnSfxOnObjectB_0_0017BF50(s8 *, s32);
void* MapObj_Find_1_001B19A0__as_MapCmd_SetObjectAnim_0_0017C150(s32);
f32* Map_FindSfxEntry_0_001B7300__as_MapCmd_SetObjectAnim_0_0017C150(void *, s32);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetTimer_0_0017C270(s32 a, s32 b);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_WaitEvent_0_0017C2A0(P_MapCmd_WaitEvent_0_0017C2A0 *, s32);
void MapObj_GetCamera_0_001B1560(s32 a, void *p, void *q, void *r, void *s);
void* Script_GetArgPtr_2_00165130__as_MapCmd_GetCameraState_0_0017C4B0(Obj_MapCmd_GetCameraState_0_0017C4B0 *o, s32 b);
void Enemy_CopyRotation_2_00140440(void *, Vec *);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(s8 *, s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyRotation_1_0017C540(Arg_MapCmd_PlaySeAtXYZ_1_0017BC00 *, s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyPosition_1_0017C620(u8 *o, s32 b);
X* MapObj_Find_1_001B19A0__as_MapCmd_ResetObjects_0_0017C930(u8);
u8 Game_GetBusy_0_0012C020(void);
u8 Player_IsActionLocked_0_001C9AE0(void);
u8* Script_GetArgPtr_2_00165130__as_MapCmd_IsBusy_0_0017CA10(s32 a, s32 b);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_SetFloat_0_0017CA60(Obj_MapCmd_PlaySeAtXYZ_1_0017BC00_ *o, s32 b);
void MapObj_SpawnItem_0_001B0990(s32, Vec *, Vec *, Vec *, u16, u16, s32);
s32 Rand_Next_3_0015ED20(void);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_Random_2_0017CB50(s32 a, s32 b);
f32* Weather_GetState_0_00157620(void);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetWeather_0_0017CBA0(s8 *, s32);
s16* PlayerData_Get_2_001C9BA0();
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerVar_0_0017CC90(s32, s32);
s32 Snd_PlaySeVolPan_1_00131520__as_MapCmd_SetFlag2034_0_0017A640(s32, s32, C **, s32);
void SndCh_GetPosition_1_00131180__as_MapCmd_SetFlag2034_0_0017A640(s32, V2 *);
void Snd_PlaySeAt_2_001315A0__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(s32 a, s32 b, V *v);
s8* MapObj_Find_1_001B19A0__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(u8);
s32 MapObj_GetNodeIndex_0_001B7840__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(u8, u16);
s32 Snd_PlaySeVolPan_1_00131520__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(s32, s32, s8 **, s32);
void SndCh_GetPosition_1_00131180__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(s32, P_MapCmd_PlaySeAtXYZ_1_0017BC00 *);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(void *, s32);
void Player_AddStatus_1_001C88E0(s32 arg0, void * arg1, s32 arg2);
s32 PlayerData_GetStatusTimer_0_001CE200(s32 v);
void Player_Warp_0_001C92C0(V *v);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPos_1_0017CE80(s32, s32);
void Player_GetPosB_0_001C9490(void *);
void Player_SetPosAndGround_0_001C94F0(V *v);
void sceVu0CopyVector(Vec *, void *);
void sceVu0CopyMatrix(Mtx*, void *);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetDistToObject_0_0017D000(Arg_MapCmd_SetFlag2034_0_0017A640__ *, s32);
T_MapCmd_GetPlayerFlag_0_0017D0E0* Player_GetBodyState_1_001C9B60(void);
u8* Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerFlag_0_0017D0E0(s32 a, s32 b);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_SetPlayerVar3_0_0017CD00_(Obj_MapCmd_SetPlayerVar3_0_0017CD00 *o, s32 b);
s8* MapObj_Find_1_001B19A0__as_MapCmd_SetPlayerVar3_0_0017CD00_(s32);
s16 Equip_GetSlotItem_1_001CCD90(s16 v);
u8* Inventory_GetEntry_1_001CC3F0(s16 h);
u8* Script_GetArgPtr_2_00165130__as_MapCmd_GetEffectState_0_0017D170(Obj_MapCmd_GetEquip_0_0017D130 *o, s32 b);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetEquip_0_0017D130(Obj_MapCmd_GetEquip_0_0017D130 *o, s32 b);
s8* Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerRot_1_0017D240(s32 a, s32 b);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerVarB_0_0017D300(s32, s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPosB_0_0017D350(void *o, s32 b);
s32 MapObj_GetNodeIndex_0_001B7840__as_MapCmd_SetObjectsAlpha_0_0017D480(u8, u16);
Obj_MapCmd_GetEquip_0_0017D130_* MapObj_Find_1_001B19A0__as_MapCmd_SetObjectsAlpha_0_0017D480(u8);
void MapObj_GetNodeMatrix_0_001B7B30(s32, s32, f32 (*)[4]);
void Mtx_AxisAngle_2_0015EBB0(f32 (*)[4], f32 *, f32);
void MapObj_SetNodeMatrixB_0_001B7A30(s32, s32, f32 (*)[4]);
void sceVu0MulMatrix(void *, void *, void *);
s8 Save_GetByte2E_0_001AA740(void);
s8* Script_GetArgPtr_2_00165130__as_MapCmd_GetGlobal_0_0017D930(s32 a, s32 b);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetNodePos_0_0017DA60(s8 *, s32);
void Player_GetPosB_0_001C9490__as_MapCmd_SetFlag2034_0_0017A640_(V *v);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetEquip_0_0017D130_(void *, s32);
void Player_GetPosB_0_001C9490__as_MapCmd_GetEquip_0_0017D130_(f32 *v);
Obj_MapCmd_SetObjectAlpha_0_0017D3D0* MapObj_Find_1_001B19A0__as_MapCmd_GetEquip_0_0017D130_(s32);
void MapObj_SpawnSfx_0_001B0D60(s16, s16, Vec *, Vec *);
s32 MapObj_GetCount_0_001B17E0(int *);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectVarB_0_0017DCD0(Obj_MapCmd_SetCameraTarget_0_0017DB40 *o, s32 b);
void MapObj_SetNodeMatrix_0_001B78D0(s32, s32, s32, Mtx *);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectFlag_0_0017DD90(O_MapCmd_GetObjectFlag_0_0017DD90 *, s32);
void MapObj_SetAnimFrame_0_001B87C0(s32 a, s32 b, s32 c, s32 d, f32 x, f32 y);
s32 MapObj_Find_1_001B19A0__as_MapCmd_SetCameraTarget_0_0017DB40();
s32 MapObj_GetNodeIndex_0_001B7840__as_MapCmd_SetCameraTarget_0_0017DB40();
void MapObj_PlayAnim_1_001B7CD0(s64 arg0, s64 arg1);
void MapObj_StopAnim_1_001B7C10(u32 arg0, u64 arg1);
f32 MapObj_GetAnimFrameB_1_001B7610(s32 a, s32 b, s32 c);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectAnim_0_0017DEC0(Obj_MapCmd_SetFlag2034_0_0017A640___ *o, s32 b);
s32 Save_TestItemBit_1_001A9B40(s16);
s32 ItemObj_OffsetAll_0_001AC0F0(s32, u16, Vec *);
s32 ItemMdl_SetTransform_0_001ABF70(s32, u16, Vec *);
s32* Script_GetArgPtr_2_00165130__as_MapCmd_SpawnItem_0_0017DF20(Arg_MapCmd_SetFlag2034_0_0017A640___ *, s32);
void Item_ClearNewFlag_0_001A9510(s16);
void Snd_PlaySe_3_00131600(s32, s32);
int* Script_GetArgPtr_2_00165130__as_MapCmd_SetCameraTarget_0_0017DB40_(S_MapCmd_GetObjectVar_0_0017DC70 *, int);
s32 MapObj_Find_1_001B19A0__as_MapCmd_SetCameraTarget_0_0017DB40_(s32 a);
void MapObj_GetSfxMatrix_0_001B1050(s32, s32, Mtx *);
void MapObj_SetSfxMatrix_0_001B0EB0(s32, s32, Mtx *);
void sceVu0RotMatrixZ(f32, Mtx *, Mtx *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void MapObj_SetSfxFlag_0_001B11F0(u8, u16, s32);
s32 MapObj_SetSfxFlag_0_001B11F0__as_MapCmd_SetObjectTexture_0_0017E150();
void MapObj_SetSfxMatrix_0_001B0EB0__as_MapCmd_SetSfxTransform_0_0017E390(u8, u16, Mtx *);
void Sfx_SetParam17C_1_00167290(s32, f32, Chr *, s32);
f32 Sfx_GetParam17C_1_00167280(s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_SetObjectTexture_0_0017E150_(O_MapCmd_SetObjectTexture_0_0017E150 *, s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetSfxParamA_0_0017E760(Arg_MapCmd_GetSfxParamA_0_0017E760 *, s32);
void Sfx_SetParam180_1_00167270(f32, s32, Chr *, s32);
void MapCmd_SetObjectTexture_0_0017E150__as_MapCmd_SetFlag2034_0_0017A640__(s32, s32, s32);
Obj_MapCmd_SetObjectTexture_0_0017E150_* MapObj_Find_1_001B19A0__as_MapCmd_SetObjectTexture_0_0017E150__(s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_SetObjectTexture_0_0017E150__(void *, s32);
void sceVu0CopyMatrix__as_MapCmd_SetObjectTexture_0_0017E150__(Mtx *, Mtx *);
f32 Sfx_GetParam180_1_00167260(s32);
f32* Script_GetArgPtr_2_00165130__as_MapCmd_GetSfxParamB_0_0017EAF0(Arg *, s32);

/* MapObj_FindById_0_00179DB0 */
u8 *MapObj_FindById_0_00179DB0(s32 id, s32 key) {
    Tbl *t;
    Ent_MapObj_FindById_0_00179DB0 *e;
    s32 i;
    Mdl **q;
    s32 j;
    Mdl ***pp;
    for (i = 0, pp = gMapSbss_00201E88; i < 2; i++, pp++) {
        q = *pp;
        if (q != NULL && *q != NULL && (*q)->id == id) {
            t = (*q)->x164;
            if (t != NULL) {
                e = t->e;
                for (j = 0; j < t->n; j++, e++) {
                    if (e->id == key) return (u8 *)t + e->off;
                }
            }
        }
    }
    return NULL;
}

/* Event_FindEnemyByMotion_0_00179E50_ */
#define Enemy_GetMotionId_0_0013ED20 Enemy_GetMotionId_0_0013ED20__as_Event_FindEnemyByMotion_0_00179E50_
int Enemy_GetMotionId_0_0013ED20__as_Event_FindEnemyByMotion_0_00179E50_();
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_Event_FindEnemyByMotion_0_00179E50_
s32 Ent_IsNull0_1_0013EE30__as_Event_FindEnemyByMotion_0_00179E50_(u8 *);
#define Enemy_CopyPosition_2_00140470 Enemy_CopyPosition_2_00140470__as_Event_FindEnemyByMotion_0_00179E50_
void Enemy_CopyPosition_2_00140470__as_Event_FindEnemyByMotion_0_00179E50_(char *, Vec *);

/* Event_FindEnemyByMotion_0_00179E50 */

s32 Event_FindEnemyByMotion_0_00179E50(s32 arg0, s32 arg1) {
    u8 *var_16;
    s32 temp_3;
    s32 temp_19;
    s32 sp5C;

    sp5C = 0;
    var_16 = (u8 *) (ActorList_Next_2_001A5460__as_Event_FindEnemyByMotion_0_00179E50(&sp5C));
    if (var_16 != NULL) {
loop_1:
        if (Ent_IsNull0_1_0013EE30(var_16) == 0) {
            temp_19 = Enemy_GetMotionId_0_0013ED20(var_16) & 0xFF;
            temp_3 = Enemy_GetTargetHandle_0_0013EDE0(var_16) & 0xFF;
            if (((temp_19 & 0xFF) == arg1) && ((temp_3 & 0xFF) == arg0)) {
                return (s32) var_16;
            }
        }
        var_16 = (u8 *) (ActorList_Next_2_001A5460__as_Event_FindEnemyByMotion_0_00179E50(&sp5C));
        if (var_16 == NULL) {
            goto block_7;
        }
        goto loop_1;
    }
block_7:
    return 0;
}

/* Event_CheckTalk_0_00179F10 */
s32 Event_CheckTalk_0_00179F10(void) {
    Msg msg;
    msg.type = 4;
    msg.r = 0.0f;
    msg.c = -1;
    msg.b = -1;
    msg.a = -1;
    msg.p = 0.0f;
    msg.h = 0.0f;
    msg.w = 0.0f;
    msg.z = 0.0f;
    msg.y = 0.0f;
    msg.x = 0.0f;
    msg.f = (gMapCommandBss_00317238[0] & 0x2000) != 0;
    Event_CheckTrigger_0_00179F80__as_Event_CheckTalk_0_00179F10(&msg);
    return 0;
}

/* Event_CheckTrigger_0_00179F80 */
static inline f32 u2f_Event_FindEnemyByMotion_0_00179E50(u32 x) { return x; }
static inline s32 lt(f32 a, u32 b) { s32 r = 0; if (a < u2f_Event_FindEnemyByMotion_0_00179E50(b)) r = 1; return r; }
static inline s32 chk(s32 b, s32 a, s32 bit, s32 off) {
    s32 r = -1;
    if ((MapObj_GetNode_0_001B77A0(b, a)->x1A / 100) & bit) {
        r = Script_SendEvent_2_00166F80(*MapObj_Find_1_001B19A0(b)->xC, a + off, 0);
    }
    return r;
}
static inline s32 h5(Q_Event_FindEnemyByMotion_0_00179E50 *q, s32 d) {
    s32 a = q->x4;
    E3 *p = MapObj_Find_1_001B19A0(q->x8);
    if (a == 0) { return d; }
    d = Script_SendEvent_2_00166F80(*p->xC, a, 0);
    return d;
}

s32 Event_CheckTrigger_0_00179F80(Q_Event_FindEnemyByMotion_0_00179E50 *q) {
    s32 r = -1;
    f32 f;

    switch (q->x0) {
    case 0:
        f = q->x1C;
        if (lt(f, MapObj_GetNodeFlags_0_001B76C0(q->x8, q->x4)->xE)) {
            r = chk(q->x8, q->x4, 2, 0xC8);
        }
        break;
    case 7:
        if (chk(q->x8, q->x4, 4, 0x190) != -1) r = 1;
        break;
    case 8:
        if (chk(q->x8, q->x4, 8, 0x320) != -1) r = 1;
        break;
    case 1:
        if (chk(q->x8, q->x4, 1, 0x64) != -1) r = 1;
        break;
    case 2:
        if (chk(q->x8, q->x4, 0x10, 0x640) != -1) r = 1;
        break;
    case 3: {
        s32 c = gDoorSbss_00202030;
        if ((c >= 31 && c <= 49) || (q->x4 == 99 && c == 1)) {
            if (chk(q->x8, q->x4, 0x20, 0xC80) != -1) r = 1;
        }
        break;
    }
    case 4: {
        f32 d;
        f32 e;
        s32 it = 0;
        s8 *a;
        for (a = ActorList_Next_2_001A5460(&it); a; a = ActorList_Next_2_001A5460(&it)) {
            ActorList_SetCount_1_001A5440(a);
            if (Event_IsPlayerFacing_0_0017A480__as_Event_CheckTrigger_0_00179F80(a, &d, &e) && Enemy_Get5B1b1_1_0013EA70(a) && q->x2C && EnemyScr_Event2014_1_00141610(a) == 1) r = 1;
        }
        break;
    }
    case 5: {
        if (h5(q, r) != -1) r = 1;
        break;
    }
    case 6:
        break;
    }
    return r != -1;
}

/* Event_IsPlayerFacing_0_0017A480 */
s32 Event_IsPlayerFacing_0_0017A480(char *a0, f32 *a1, f32 *a2) {
    f32 bc;
    f32 b8;
    Vec va0;
    Vec v90;
    Vec v80;
    Vec v70;
    Vec v60;
    f32 len;
    f32 c;
    f32 d;
    u8 r = 0;

    Enemy_GetParamAngles_0_0013DD50(a0, &bc, &b8);
    Player_CopyVec_0_00145780(&va0);
    Enemy_CopyPosition_2_00140470(a0, &v90);
    va0.y = 0.0f;
    v90.y = 0.0f;
    sceVu0SubVector(&v80, &v90, &va0);
    len = sqrtf(sceVu0InnerProduct(&v80, &v80));
    if (a1) *a1 = len;
    if (len < bc) {
        c = cosf(1.0471976f);
        Player_GetForwardVector_2_001456B0(&v70);
        if (!(len <= 0.0f)) {
            v80.x /= len;
            v80.y /= len;
            v80.z /= len;
        }
        d = sceVu0InnerProduct(&v80, &v70);
        if (a2) *a2 = d;
        if (!(d <= c)) {
            c = cosf(1.0471976f);
            v80.x = -v80.x;
            v80.y = -v80.y;
            v80.z = -v80.z;
            Enemy_GetForwardVector_2_001403D0(a0, &v60);
            if (!(sceVu0InnerProduct(&v80, &v60) <= c)) r = 1;
        }
    }
    return r;
}
#undef Ent_IsNull0_1_0013EE30
#undef Enemy_CopyPosition_2_00140470
#undef Enemy_GetMotionId_0_0013ED20

/* MapCmd_SetFlag2034_0_0017A640___ */
#define Enemy_GetTargetHandle_0_0013EDE0 Enemy_GetTargetHandle_0_0013EDE0__as_MapCmd_SetFlag2034_0_0017A640___
u8 Enemy_GetTargetHandle_0_0013EDE0__as_MapCmd_SetFlag2034_0_0017A640___(void *p);
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_MapCmd_SetFlag2034_0_0017A640___
s32 Ent_IsNull0_1_0013EE30__as_MapCmd_SetFlag2034_0_0017A640___(s8 *);
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapCmd_SetFlag2034_0_0017A640___
f32* MapObj_Find_1_001B19A0__as_MapCmd_SetFlag2034_0_0017A640___(s32);
#define Event_FindEnemyByMotion_0_00179E50 Event_FindEnemyByMotion_0_00179E50__as_MapCmd_SetFlag2034_0_0017A640___
void* Event_FindEnemyByMotion_0_00179E50__as_MapCmd_SetFlag2034_0_0017A640___(u8, u8);
#define Enemy_CopyPosition_2_00140470 Enemy_CopyPosition_2_00140470__as_MapCmd_SetFlag2034_0_0017A640___
void Enemy_CopyPosition_2_00140470__as_MapCmd_SetFlag2034_0_0017A640___(void *p, f32 *v);

/* MapCmd_SetFlag2034_0_0017A640___ */
/* MapCmd_SetFlag2034_0_0017A640__ */

/* MapCmd_SetFlag2034_0_0017A640__ */
/* MapCmd_SetFlag2034_0_0017A640_ */

/* MapCmd_SetFlag2034_0_0017A640_ */
/* MapCmd_SetFlag2034_0_0017A640 */

/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
/* MapCmd_SetFlag2034_0_0017A640 */
void MapCmd_SetFlag2034_0_0017A640(void *arg0) {
    gMapCommandSbss_00202034 = M2C_FIELD(arg0, u8 *, 8);
}

/* MapCmd_FadeTo_1_0017A650 */
static inline f32 u2f_MapCmd_SetFlag2034_0_0017A640(u32 x) { return x; }

void MapCmd_FadeTo_1_0017A650(Arg_MapCmd_SetFlag2034_0_0017A640 *a0) {
    Vec v;
    f32 t;

    t = (f32)a0->x28 / 30.0f;
    v.x = u2f_MapCmd_SetFlag2034_0_0017A640(a0->x8);
    v.y = u2f_MapCmd_SetFlag2034_0_0017A640(a0->x10);
    v.z = u2f_MapCmd_SetFlag2034_0_0017A640(a0->x18);
    v.w = u2f_MapCmd_SetFlag2034_0_0017A640(a0->x20);
    ScreenFx_SetFadeTarget_0_00159400(t, &v);
}

/* MapCmd_NotifyEnemies_0_0017A790 */
void MapCmd_NotifyEnemies_0_0017A790(u8 *o) {
    s32 it;
    s8 *p;
    it = 0;
    for (p = ActorList_Next_2_001A5460(&it); p != NULL; p = ActorList_Next_2_001A5460(&it)) {
        if (Ent_IsNull0_1_0013EE30(p) == 0) {
            u8 a = Enemy_GetMotionId_0_0013ED20(p);
            u8 b = Enemy_GetTargetHandle_0_0013EDE0(p);
            if (a == o[0x10] && b == o[8]) EnemyScr_Event2015_1_00141510(p, o[8], o[0x18], o[0x20]);
        }
    }
}

/* MapCmd_SetMapVar_0_0017A850 */
void MapCmd_SetMapVar_0_0017A850(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_3 < 0xC9) {
        Map_SetVar_0_001B0B30(temp_3, M2C_FIELD(arg0, s16 *, 0x10));
    }
}

/* MapCmd_GetFlagWord_0_0017A890 */
void MapCmd_GetFlagWord_0_0017A890(u8 *o)
{
    u8 *p = Script_GetArgPtr_2_00165130(o, 2);
    u8 a = o[8];
    s32 b;
    if (a <= 200) {
        b = o[0x10];
        if (b <= 32)
            *p = MapState_GetWord_1_001AA540(a, (u32)b >> 2) >> ((b % 4) * 8);
    }
}

/* MapCmd_SetFlagBits_0_0017A920 */
void MapCmd_SetFlagBits_0_0017A920(Arg_MapCmd_SetFlagBits_0_0017A920 *p) {
    s32 q;
    s32 r;
    u32 m = 0;
    s32 a = p->x8.b;
    s32 b;

    if (a <= 200 && (b = p->x10.b) <= 32 && p->x18.b <= 255) {
        q = (u32)b / 4;
        r = b % 4;
        switch (r) {
        case 0: m = 0xFFFFFF00; break;
        case 1: m = 0xFFFF00FF; break;
        case 2: m = 0xFF00FFFF; break;
        case 3: m = 0x00FFFFFF; break;
        }
        MapState_SetWord_1_001AA5D0(p->x8.b, q, (m & MapState_GetWord_1_001AA540(a, q)) | (p->x18.b << (r * 8)));
    }
}

/* MapCmd_GetPlayerStat_0_0017AA40 */

void MapCmd_GetPlayerStat_0_0017AA40(char *a0) {
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerStat_0_0017AA40(a0, 1);
    s32 v = *(s32 *)(a0 + 8);
    if (v < 12) {
        switch (v) {
        case 0: *p = gMapCommandBss_00317238[0] & 0x10; break;
        case 1: *p = gMapCommandBss_00317238[0] & 0x40; break;
        case 2: *p = gMapCommandBss_00317238[0] & 0x80; break;
        case 3: *p = gMapCommandBss_00317238[0] & 0x20; break;
        case 4: *p = gMapCommandBss_00317238[0] & 0x1000; break;
        case 5: *p = gMapCommandBss_00317238[0] & 0x4000; break;
        case 6: *p = gMapCommandBss_00317238[0] & 0x8000; break;
        case 7: *p = gMapCommandBss_00317238[0] & 0x2000; break;
        case 8: *p = gMapCommandBss_00317238[0] & 0x400; break;
        case 9: *p = gMapCommandBss_00317238[0] & 0x800; break;
        case 10: *p = gMapCommandBss_00317238[0] & 0x100; break;
        case 11: *p = gMapCommandBss_00317238[0] & 0x200; break;
        }
    }
}

/* MapCmd_NopA_2_0017ABB0 */
void MapCmd_NopA_2_0017ABB0(void) {

}

/* MapCmd_NopB_2_0017ABC0 */
void MapCmd_NopB_2_0017ABC0(void) {

}

/* MapCmd_GetLight_0_0017ABD0 */

void MapCmd_GetLight_0_0017ABD0(Arg_MapCmd_SetFlag2034_0_0017A640_ *a) {
    s32 o = a->x8;
    s32 b = a->x10;
    f32 *p2 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 2);
    f32 *p3 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 3);
    f32 *p4 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 4);
    f32 *p5 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 5);
    f32 *p6 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 6);
    f32 *p7 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 7);
    f32 *p8 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 8);
    f32 *p9 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 9);
    f32 *p10 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 10);
    f32 *p11 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 11);
    f32 *p12 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 12);
    f32 *p13 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 13);
    f32 *p14 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 14);
    f32 *p15 = Script_GetArgPtr_2_00165130__as_MapCmd_GetLight_0_0017ABD0(a, 15);
    f32 *d = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, b));
    if (d) {
        *p2 = d[0];
        *p3 = d[1];
        *p4 = d[2];
        *p5 = d[3];
        *p6 = 255.0f * d[4];
        *p7 = 255.0f * d[5];
        *p8 = 255.0f * d[6];
        *p9 = d[7];
        *p10 = d[8];
        *p11 = d[9];
        *p12 = d[10];
        *p13 = d[11];
        *p14 = d[12];
        *p15 = d[13];
    }
}

/* MapCmd_SetLight_0_0017ADE0 */

/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
/* MapCmd_SetLight_0_0017ADE0 */
void MapCmd_SetLight_0_0017ADE0(Arg_MapCmd_SetLight_0_0017ADE0 *a) {
    f32 v3 = a->v[3].f;
    f32 v7 = a->v[7].f;
    f32 v8 = a->v[8].f;
    f32 v9 = a->v[9].f;
    f32 v10 = a->v[10].f;
    f32 v11 = a->v[11].f;
    f32 v12 = a->v[12].f;
    f32 v13 = a->v[13].f;
    f32 v0 = a->v[0].f;
    f32 v1 = a->v[1].f;
    f32 v2 = a->v[2].f;
    f32 v4 = a->v[4].f / 255.0f;
    f32 v5 = a->v[5].f / 255.0f;
    f32 v6 = a->v[6].f / 255.0f;
    s32 o = ((volatile Arg_MapCmd_SetLight_0_0017ADE0 *)a)->x8.i;
    s32 b = ((volatile Arg_MapCmd_SetLight_0_0017ADE0 *)a)->x10.i;
    f32 *d = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, b));
    if (d) {
        d[0] = v0;
        d[1] = v1;
        d[2] = v2;
        d[3] = v3;
        d[4] = v4;
        d[5] = v5;
        d[6] = v6;
        d[7] = v7;
        d[8] = v8;
        d[9] = v9;
        d[10] = v10;
        d[11] = v11;
        d[12] = v12;
        d[13] = v13;
    }
}

/* MapCmd_GetGlow_0_0017AF20 */
void MapCmd_GetGlow_0_0017AF20(s32 *a0) {
    s32 x8 = a0[2];
    s32 x10 = a0[4];
    f32 *p2 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 2);
    f32 *p3 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 3);
    f32 *p4 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 4);
    f32 *p5 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 5);
    f32 *p6 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 6);
    f32 *p7 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 7);
    f32 *p8 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 8);
    f32 *p9 = Script_GetArgPtr_2_00165130__as_MapCmd_SetLight_0_0017ADE0(a0, 9);
    Vec a;
    Vec b;
    Glow_GetParams_0_0015D760(Map_GetGlowIndex_0_001B0C70(x8, x10), &a, &b, p8, p9);
    *p2 = a.x;
    *p3 = a.y;
    *p4 = a.z;
    *p5 = b.x;
    *p6 = b.y;
    *p7 = b.z;
}

/* MapCmd_SetGlow_0_0017B060 */
void MapCmd_SetGlow_0_0017B060(O_MapCmd_SetLight_0_0017ADE0 *o) {
    s32 i0 = o->x8;
    f32 x = o->x48;
    s32 i1 = o->x10;
    f32 z = o->x50;
    Vec a;
    Vec b;
    a.x = o->x18;
    a.y = o->x20;
    a.z = o->x28;
    a.w = 1.0f;
    b.x = o->x30;
    b.y = o->x38;
    b.z = o->x40;
    b.w = 0.0f;
    Glow_SetParams_0_0015D800(Map_GetGlowIndex_0_001B0C70(i0, i1), &a, &b, x, z);
}

/* MapCmd_MoveObject_0_0017B0F0 */
void MapCmd_MoveObject_0_0017B0F0(S_MapCmd_SetFlag2034_0_0017A640 *s) {
    f32 t = s->t;
    s32 b = s->b;
    s32 c = s->c;
    s32 fl = s->fl;
    f32 *d;
    f32 *q, *p;
    s32 h = s->h;
    f32 u = 1.0f - t;

    d = Map_GetFogEntry_0_001B40F0(MapObj_Find_1_001B19A0(h), s->a);
    p = Map_GetFogEntry_0_001B40F0(MapObj_Find_1_001B19A0(h), b);
    q = Map_GetFogEntry_0_001B40F0(MapObj_Find_1_001B19A0(h), c);
    if (d != 0 && p != 0 && q != 0) {
        if (fl & 0x1) {
            d[16] = p[16] * u + q[16] * t;
            d[17] = p[17] * u + q[17] * t;
            d[18] = p[18] * u + q[18] * t;
            d[19] = p[19] * u + q[19] * t;
        }
        if (fl & 0x2) {
            d[4] = p[4] * u + q[4] * t;
            d[5] = p[5] * u + q[5] * t;
            d[6] = p[6] * u + q[6] * t;
            d[7] = p[7] * u + q[7] * t;
            d[0] = p[0] * u + q[0] * t;
            d[1] = p[1] * u + q[1] * t;
            d[2] = p[2] * u + q[2] * t;
            d[3] = p[3] * u + q[3] * t;
        }
        if (fl & 0x4) {
            d[12] = p[12] * u + q[12] * t;
            d[13] = p[13] * u + q[13] * t;
            d[14] = p[14] * u + q[14] * t;
            d[15] = p[15] * u + q[15] * t;
            d[8] = p[8] * u + q[8] * t;
            d[9] = p[9] * u + q[9] * t;
            d[10] = p[10] * u + q[10] * t;
            d[11] = p[11] * u + q[11] * t;
        }
        if (fl & 0x8) {
            d[20] = p[20] * u + q[20] * t;
        }
        if (fl & 0x10) {
            d[21] = p[21] * u + q[21] * t;
        }
        if (fl & 0x20) {
            d[22] = p[22] * u + q[22] * t;
        }
        if (fl & 0x40) {
            d[23] = p[23] * u + q[23] * t;
        }
        Map_UpdateFog_0_001B4100(MapObj_Find_1_001B19A0(h));
    }
}

/* MapCmd_RotateObject_0_0017B410 */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x8, 0xc, 0x10, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44], gap at: 0x18. */
void MapCmd_RotateObject_0_0017B410(u8 *arg0) {
    u8 *temp_2;
    s32 temp_16;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;

    temp_f24 = M2C_FIELD(arg0, f32 *, 0x18);
    temp_16 = M2C_FIELD(arg0, s32 *, 8);
    temp_f23 = M2C_FIELD(arg0, f32 *, 0x20);
    temp_f22 = M2C_FIELD(arg0, f32 *, 0x28);
    temp_f21 = M2C_FIELD(arg0, f32 *, 0x30);
    temp_f20 = M2C_FIELD(arg0, f32 *, 0x38);
    temp_2 = (u8 *) (Map_GetFogEntry_0_001B40F0__as_MapCmd_RotateObject_0_0017B410(MapObj_Find_1_001B19A0__as_MapCmd_RotateObject_0_0017B410(temp_16), M2C_FIELD(arg0, s32 *, 0x10)));
    if (temp_2 != NULL) {
        M2C_FIELD(temp_2, f32 *, 0x40) = temp_f24;
        M2C_FIELD(temp_2, f32 *, 0x44) = temp_f23;
        M2C_FIELD(temp_2, f32 *, 0x48) = temp_f22;
        M2C_FIELD(temp_2, f32 *, 0x4C) = temp_f21;
        if (temp_f20 != -100.0f) {
            M2C_FIELD(temp_2, f32 *, 0x50) = temp_f20;
        }
        Map_UpdateFog_0_001B4100__as_MapCmd_RotateObject_0_0017B410(MapObj_Find_1_001B19A0__as_MapCmd_RotateObject_0_0017B410(temp_16));
    }
}

/* MapCmd_StopObject_0_0017B4D0 */

void MapCmd_StopObject_0_0017B4D0(s8 *arg0) {
    s32 temp_s0;
    s8 *temp_v0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 8);
    temp_v0 = Map_GetFogEntry_0_001B40F0__as_MapCmd_StopObject_0_0017B4D0(MapObj_Find_1_001B19A0__as_MapCmd_StopObject_0_0017B4D0(temp_s0), M2C_FIELD(arg0, s32 *, 0x10));
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x18);
        M2C_FIELD(temp_v0, f32 *, 0x14) = (f32) M2C_FIELD(arg0, f32 *, 0x20);
        M2C_FIELD(temp_v0, f32 *, 0x18) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
        M2C_FIELD(temp_v0, f32 *, 0x1C) = (f32) M2C_FIELD(arg0, f32 *, 0x30);
        M2C_FIELD(temp_v0, f32 *, 0x30) = (f32) M2C_FIELD(arg0, f32 *, 0x38);
        M2C_FIELD(temp_v0, f32 *, 0x34) = (f32) M2C_FIELD(arg0, f32 *, 0x40);
        M2C_FIELD(temp_v0, f32 *, 0x38) = (f32) M2C_FIELD(arg0, f32 *, 0x48);
        M2C_FIELD(temp_v0, f32 *, 0x3C) = (f32) M2C_FIELD(arg0, f32 *, 0x50);
        M2C_FIELD(temp_v0, f32 *, 0x40) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
        M2C_FIELD(temp_v0, f32 *, 0x44) = (f32) M2C_FIELD(arg0, f32 *, 0x60);
        M2C_FIELD(temp_v0, f32 *, 0x48) = (f32) M2C_FIELD(arg0, f32 *, 0x68);
        M2C_FIELD(temp_v0, f32 *, 0x4C) = (f32) M2C_FIELD(arg0, f32 *, 0x70);
        M2C_FIELD(temp_v0, f32 *, 0x50) = (f32) M2C_FIELD(arg0, f32 *, 0x78);
        M2C_FIELD(temp_v0, f32 *, 0x54) = (f32) M2C_FIELD(arg0, f32 *, 0x80);
        Map_UpdateFog_0_001B4100__as_MapCmd_StopObject_0_0017B4D0(MapObj_Find_1_001B19A0__as_MapCmd_StopObject_0_0017B4D0(temp_s0));
    }
}

/* MapCmd_GetObjectState_0_0017B5A0 */

void MapCmd_GetObjectState_0_0017B5A0(s8 *a0) {
    s8 *p;
    s32 s0;
    s0 = *(s32 *)(a0 + 8);
    p = Map_GetFogEntry_0_001B40F0__as_MapCmd_GetObjectState_0_0017B5A0(MapObj_Find_1_001B19A0__as_MapCmd_GetObjectState_0_0017B5A0(s0), *(s32 *)(a0 + 0x10));
    if (p != 0) {
        f32 f;
        f = *(f32 *)(p + 0x10); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 2) = f;
        f = *(f32 *)(p + 0x14); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 3) = f;
        f = *(f32 *)(p + 0x18); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 4) = f;
        f = *(f32 *)(p + 0x1C); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 5) = f;
        f = *(f32 *)(p + 0x30); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 6) = f;
        f = *(f32 *)(p + 0x34); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 7) = f;
        f = *(f32 *)(p + 0x38); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 8) = f;
        f = *(f32 *)(p + 0x3C); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 9) = f;
        f = *(f32 *)(p + 0x40); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 10) = f;
        f = *(f32 *)(p + 0x44); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 11) = f;
        f = *(f32 *)(p + 0x48); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 12) = f;
        f = *(f32 *)(p + 0x4C); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 13) = f;
        f = *(f32 *)(p + 0x50); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 14) = f;
        f = *(f32 *)(p + 0x54); *Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectState_0_0017B5A0(a0, 15) = f;
        Map_UpdateFog_0_001B4100__as_MapCmd_GetObjectState_0_0017B5A0(MapObj_Find_1_001B19A0__as_MapCmd_GetObjectState_0_0017B5A0(s0));
    }
}

/* MapCmd_GetDoorState_0_0017B730 */

void MapCmd_GetDoorState_0_0017B730(Obj_MapCmd_SetLight_0_0017ADE0 *o)
{
    s32 a = o->a;
    s32 b = o->b;
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetDoorState_0_0017B730(o, 2);
    *p = MapObj_GetAnimState_0_001B7D80(a, b);
}

/* MapCmd_SetDoor_0_0017B780 */
void MapCmd_SetDoor_0_0017B780(void *arg0) {
    MapObj_SetAnimState_0_001B7E80((s32) M2C_FIELD(arg0, u8 *, 8), (s32) M2C_FIELD(arg0, u8 *, 0x10), (s32) M2C_FIELD(arg0, u8 *, 0x18));
}

/* MapCmd_GetValue_0_0017B7A0 */

void MapCmd_GetValue_0_0017B7A0(s32 a) {
    s32 *temp_2;
    s32 var_3;
    s32 var_5;

    temp_2 = Script_GetArgPtr_2_00165130__as_MapCmd_GetValue_0_0017B7A0(a, 0);
    if (temp_2 != NULL) {
        var_5 = 0;
        if ((gPlayerSbss_002022BC != NULL) && (*gPlayerSbss_002022BC != NULL)) {
            var_5 = 1;
        }
        var_3 = 0;
        if (var_5 != 0) {
            var_3 = **gPlayerSbss_002022BC;
        }
        *temp_2 = var_3;
    }
}

/* MapCmd_ShowObject_0_0017B800 */

void MapCmd_ShowObject_0_0017B800(u8 *arg0) {
    s32 temp_18;
    s32 temp_17;
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_6;

    temp_18 = M2C_FIELD(arg0, s32 *, 8);
    temp_17 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_2 = MapObj_GetNodeIndex_0_001B7840(temp_18, M2C_FIELD(arg0, s32 *, 0x10));
    if (temp_2 >= 0) {
        temp_2_2 = (u8 *) (MapObj_Find_1_001B19A0__as_MapCmd_ShowObject_0_0017B800(temp_18));
        if (temp_2_2 != NULL) {
            temp_6 = (u8 *) (M2C_FIELD(temp_2_2, s32 *, 0x180) + (temp_2 << 7));
            if ((temp_6 != NULL) && (temp_6 != NULL)) {
                ((BF_50_3_1 *)temp_6)->f = temp_17;
            }
        }
    }
}

/* MapCmd_HideObject_0_0017B8A0 */

void MapCmd_HideObject_0_0017B8A0(Obj_MapCmd_HideObject_0_0017B8A0 *o)
{
    s32 a = o->a;
    s32 f = o->f;
    s32 k = MapObj_GetNodeIndex_0_001B7840(a, o->b);
    T *t;
    E_MapCmd_SetLight_0_0017ADE0 *e;
    if (k < 0)
        return;
    t = MapObj_Find_1_001B19A0__as_MapCmd_HideObject_0_0017B8A0(a);
    if (!t)
        return;
    e = &t->e[k];
    if (e)
        e->f = f;
}

/* MapCmd_FindObjectNode_0_0017B930 */
R_MapCmd_SetLight_0_0017ADE0 *MapCmd_FindObjectNode_0_0017B930(s32 a, s32 id) {
    O_MapCmd_FindObjectNode_0_0017B930 *o;
    E_MapCmd_FindObjectNode_0_0017B930 *e;
    R_MapCmd_SetLight_0_0017ADE0 *r;
    s32 i;
    o = MapObj_Find_1_001B19A0__as_MapCmd_FindObjectNode_0_0017B930(a);
    if (o == NULL) return NULL;
    e = o->x134;
    r = o->x178;
    for (i = 0; i < o->x6C; i++) {
        if (e == NULL) return NULL;
        if (r == NULL) return NULL;
        if (e[0].x1C == id) return r;
        e++;
        r++;
    }
    return NULL;
}

/* MapCmd_SetObjectNode_0_0017B9E0 */
void MapCmd_SetObjectNode_0_0017B9E0(volatile A_MapCmd_SetFlag2034_0_0017A640 *arg0) {
    s32 v = arg0->x18;
    R_MapCmd_SetObjectNode_0_0017B9E0 *r = MapCmd_FindObjectNode_0_0017B930__as_MapCmd_SetObjectNode_0_0017B9E0(arg0->x8, arg0->x10);
    if (r != 0) {
        r->b0 = v;
    }
}

/* MapCmd_StartStream_0_0017BA30 */
void MapCmd_StartStream_0_0017BA30(void) {
    Snd_StartStream2_0_0012DE00();
}

/* MapCmd_StopSe_1_0017BA40 */
void MapCmd_StopSe_1_0017BA40(void *arg0) {
    SndCh_StopNow_1_001314A0(M2C_FIELD(arg0, s32 *, 8));
}

/* MapCmd_PlaySeAt_1_0017BA50 */

void MapCmd_PlaySeAt_1_0017BA50(Obj_MapCmd_SetFlag2034_0_0017A640 *o)
{
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAt_1_0017BA50(o, 2);
    V v;
    v.x = o->x;
    v.y = o->y;
    v.z = o->z;
    v.w = 1.0f;
    *p = Snd_PlaySeAt_2_001315A0(o->a, o->b, &v);
}

/* MapCmd_PlaySeOnObject_0_0017BAC0 */
#define CC (((C ***)&gMapSbss_00201E80)[2])
#define DD (((C ***)&gMapSbss_00201E80)[3])

void MapCmd_PlaySeOnObject_0_0017BAC0(O *o) {
    C **s;
    C *c;
    s8 *t;
    s32 *w;
    s32 r;
    V2 v;
    s32 k;
    s = 0;
    c = MapObj_Find_1_001B19A0__as_MapCmd_PlaySeOnObject_0_0017BAC0(o->x20);
    if (c) {
        if (CC) { C *x = *CC; if (x && x == c) s = CC; }
        if (DD && *DD && *DD == c) s = DD;
        if (s) {
            r = MapObj_GetNodeIndex_0_001B7840__as_MapCmd_PlaySeOnObject_0_0017BAC0(o->x20, o->x28);
            if (r >= 0) {
                t = Mdl_GetFrameData_0_001715B0(*(s32 *)(c->x180 + r * 0x80 + 0x40));
                if (t) {
                    w = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeOnObject_0_0017BAC0(o, 2);
                    *w = Snd_PlaySeVolPan_1_00131520__as_MapCmd_SetFlag2034_0_0017A640(o->x8, o->x10, s, t + 0x230 - (s8 *)c);
                    k = *w;
                    v.x = o->x30;
                    v.z = o->x38;
                    if (o->x30 != -1.0f) {
                        SndCh_GetPosition_1_00131180__as_MapCmd_SetFlag2034_0_0017A640(k, &v);
                    }
                }
            }
        }
    }
}
#undef CC
#undef DD
#undef CC
#undef DD
#undef CC
#undef DD

/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */

/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00_ */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */

/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
/* MapCmd_PlaySeAtXYZ_1_0017BC00 */
void MapCmd_PlaySeAtXYZ_1_0017BC00(Obj_MapCmd_PlaySeAtXYZ_1_0017BC00 *o)
{
    V v;
    v.x = o->x;
    v.y = o->y;
    v.z = o->z;
    v.w = 1.0f;
    Snd_PlaySeAt_2_001315A0__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(o->a, o->b, &v);
}

/* MapCmd_PlaySeOnObjectB_0_0017BC50 */
#define C (gMapSbss_00201E80__as_MapCmd_PlaySeAtXYZ_1_0017BC00_[2])
#define D (gMapSbss_00201E80__as_MapCmd_PlaySeAtXYZ_1_0017BC00_[3])

void MapCmd_PlaySeOnObjectB_0_0017BC50(A_MapCmd_PlaySeAtXYZ_1_0017BC00_ *a) {
    s8 **h;
    s8 *o;
    s32 i;
    s8 *r;
    s32 q;
    P_MapCmd_PlaySeAtXYZ_1_0017BC00 p;
    h = 0;
    o = MapObj_Find_1_001B19A0__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(a->x18);
    if (o == 0) return;
    if (C) { s8 *t = *C; if (t && t == o) h = C; }
    if (D && *D && *D == o) h = D;
    if (h == 0) return;
    i = MapObj_GetNodeIndex_0_001B7840__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(a->x18, a->x20);
    if (i < 0) return;
    r = Mdl_GetFrameData_0_001715B0(*(s32 *)(*(s8 **)(o + 0x180) + i * 128 + 0x40));
    if (r == 0) return;
    q = Snd_PlaySeVolPan_1_00131520__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(a->x8, a->x10, h, r + 0x230 - o);
    p.a = a->x28;
    p.b = a->x30;
    if (a->x28 != -1.0f) SndCh_GetPosition_1_00131180__as_MapCmd_PlaySeAtXYZ_1_0017BC00_(q, &p);
}
#undef C
#undef D
#undef C
#undef D

/* MapCmd_SpawnSfxOnObject_0_0017BD70 */

void MapCmd_SpawnSfxOnObject_0_0017BD70(s8 *arg0) {
    f32 t = *(f32 *)(arg0 + 0x28);
    s32 b = *(s32 *)(arg0 + 0x18);
    s32 c = *(s32 *)(arg0 + 0x20);
    s32 h = *(s32 *)(arg0 + 0x8);
    f32 u = 1.0f - t;
    f32 *d, *p, *q;
    d = (f32 *)Map_FindSfxEntry_0_001B7300(MapObj_Find_1_001B19A0__as_MapCmd_SpawnSfxOnObject_0_0017BD70(h), *(s32 *)(arg0 + 0x10));
    p = (f32 *)Map_FindSfxEntry_0_001B7300(MapObj_Find_1_001B19A0__as_MapCmd_SpawnSfxOnObject_0_0017BD70(h), b);
    q = (f32 *)Map_FindSfxEntry_0_001B7300(MapObj_Find_1_001B19A0__as_MapCmd_SpawnSfxOnObject_0_0017BD70(h), c);
    if (d != 0 && p != 0 && q != 0) {
        d[0] = p[0] * u + q[0] * t;
        d[1] = p[1] * u + q[1] * t;
        d[2] = p[2] * u + q[2] * t;
        d[3] = p[3] * u + q[3] * t;
        d[4] = p[4] * u + q[4] * t;
        d[5] = p[5] * u + q[5] * t;
        d[6] = p[6] * u + q[6] * t;
        d[7] = p[7] * u + q[7] * t;
        d[8] = p[8] * u + q[8] * t;
        d[9] = p[9] * u + q[9] * t;
        d[10] = p[10] * u + q[10] * t;
        d[11] = p[11] * u + q[11] * t;
        d[12] = p[12] * u + q[12] * t;
        d[13] = p[13] * u + q[13] * t;
    }
}
#undef C
#undef D

/* MapCmd_SpawnSfxOnObjectB_0_0017BF50 */

void MapCmd_SpawnSfxOnObjectB_0_0017BF50(s8 *arg0) {
    s32 h = *(s32 *)(arg0 + 0x8);
    s32 k = *(s32 *)(arg0 + 0x10);
    f32 *p2 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 2);
    f32 *p3 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 3);
    f32 *p4 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 4);
    f32 *p5 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 5);
    f32 *p6 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 6);
    f32 *p7 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 7);
    f32 *p8 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 8);
    f32 *p9 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 9);
    f32 *p10 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 10);
    f32 *p11 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 11);
    f32 *p12 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 12);
    f32 *p13 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 13);
    f32 *p14 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 14);
    f32 *p15 = Script_GetArgPtr_2_00165130__as_MapCmd_PlaySeAtXYZ_1_0017BC00(arg0, 15);
    f32 *d = Map_FindSfxEntry_0_001B7300__as_MapCmd_SpawnSfxOnObjectB_0_0017BF50(MapObj_Find_1_001B19A0__as_MapCmd_SpawnSfxOnObjectB_0_0017BF50(h), k);
    if (d != 0) {
        *p2 = d[0];
        *p3 = d[1];
        *p4 = d[2];
        *p5 = d[3];
        *p6 = 255.0f * d[4];
        *p7 = 255.0f * d[5];
        *p8 = 255.0f * d[6];
        *p9 = d[7];
        *p10 = d[8];
        *p11 = d[9];
        *p12 = d[10];
        *p13 = d[11];
        *p14 = d[12];
        *p15 = d[13];
    }
}
#undef C
#undef D

/* MapCmd_SetObjectAnim_0_0017C150 */

void MapCmd_SetObjectAnim_0_0017C150(O_MapCmd_PlaySeAtXYZ_1_0017BC00 *o) {
    f32 a;
    f32 e;
    f32 g;
    f32 h;
    f32 i;
    f32 j;
    f32 k;
    f32 l;
    f32 b;
    f32 c;
    f32 d;
    f32 *p;
    f32 tb;
    f32 tc;
    f32 td;
    tb = o->f[2];
    tc = o->f[4];
    a = o->f[0];
    e = o->f[8];
    g = o->f[10];
    h = o->f[12];
    i = o->f[14];
    j = o->f[16];
    k = o->f[18];
    l = o->f[20];
    td = o->f[6];
    b = tb / 255.0f;
    c = tc / 255.0f;
    d = td / 255.0f;
    p = Map_FindSfxEntry_0_001B7300__as_MapCmd_SetObjectAnim_0_0017C150(MapObj_Find_1_001B19A0__as_MapCmd_SetObjectAnim_0_0017C150(o->x8), o->x10);
    if (p) {
        p[3] = a;
        p[4] = b;
        p[5] = c;
        p[6] = d;
        p[7] = e;
        p[8] = g;
        p[9] = h;
        p[10] = i;
        p[11] = j;
        p[12] = k;
        p[13] = l;
    }
}
#undef C
#undef D

/* MapCmd_GetTimer_0_0017C270 */

void MapCmd_GetTimer_0_0017C270(s32 a)
{
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetTimer_0_0017C270(a, 0);
    *p = gGameMainSbss_00201E94;
}
#undef C
#undef D

/* MapCmd_WaitEvent_0_0017C2A0 */

void MapCmd_WaitEvent_0_0017C2A0(P_MapCmd_WaitEvent_0_0017C2A0 *p) {
    s32 dummy;
    s32 *r;
    s32 mode;
    u8 m;
    s32 kind;

    m = p->x8;
    kind = p->x10;
    r = Script_GetArgPtr_2_00165130__as_MapCmd_WaitEvent_0_0017C2A0(p, 2);
    if (r == NULL) {
        *r = 0;
        r = &dummy;
    } else {
        *r = 1;
    }
    mode = m;
    if (mode < 0 || mode >= 2) {
        *r = 0;
        return;
    }
    switch (kind) {
    case 0:
        switch (mode) {
        case 0:
            if (gMapCommandSbss_00202038 <= 0) { *r = 0; } else { gMapCommandSbss_00202038--; *r = 1; }
            break;
        case 1:
            if (gMapCommandSbss_00202038 >= 0xFF) { *r = 0; } else { gMapCommandSbss_00202038++; *r = 1; }
            break;
        }
        break;
    case 1:
        switch (mode) {
        case 0:
            if (gMapCommandSbss_00202038 <= 0) { *r = 0; } else { gMapCommandSbss_00202038--; *r = 1; }
            break;
        case 1:
            if (gMapCommandSbss_00202038 != 0) { *r = 0; } else { gMapCommandSbss_00202038++; *r = 1; }
            break;
        }
        break;
    case 2:
        switch (mode) {
        case 0:
            break;
        case 1:
            if (gMapCommandSbss_00202038 >= 0xFF) { *r = 0; } else { gMapCommandSbss_00202038++; *r = 1; }
            break;
        }
        break;
    default:
        *r = 0;
        break;
    }
    if (gMapCommandSbss_00202038 == 0) {
        Game_SetBusy_1_0012C030(0);
    } else if (gMapCommandSbss_00202038 > 0) {
        Game_SetBusy_1_0012C030(1);
    }
}
#undef C
#undef D

/* MapCmd_SetCameraPath_0_0017C490 */
void MapCmd_SetCameraPath_0_0017C490(S_MapCmd_PlaySeAtXYZ_1_0017BC00 *s)
{
    MapObj_SetCamera_0_001B13B0(s->a, s->x, s->y, s->z, s->w);
}
#undef C
#undef D

/* MapCmd_GetCameraState_0_0017C4B0 */

void MapCmd_GetCameraState_0_0017C4B0(Obj_MapCmd_GetCameraState_0_0017C4B0 *o)
{
    s32 a = o->a;
    void *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetCameraState_0_0017C4B0(o, 1);
    void *q = Script_GetArgPtr_2_00165130__as_MapCmd_GetCameraState_0_0017C4B0(o, 2);
    void *r = Script_GetArgPtr_2_00165130__as_MapCmd_GetCameraState_0_0017C4B0(o, 3);
    MapObj_GetCamera_0_001B1560(a, p, q, r, Script_GetArgPtr_2_00165130__as_MapCmd_GetCameraState_0_0017C4B0(o, 4));
}
#undef C
#undef D

/* MapCmd_GetEnemyRotation_1_0017C540 */

void MapCmd_GetEnemyRotation_1_0017C540(Arg_MapCmd_PlaySeAtXYZ_1_0017BC00 *a) {
    f32 *p2 = Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyRotation_1_0017C540(a, 2);
    f32 *p3 = Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyRotation_1_0017C540(a, 3);
    f32 *p4 = Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyRotation_1_0017C540(a, 4);
    void *o;
    Vec v;
    if ((o = Event_FindEnemyByMotion_0_00179E50(a->x8.b, a->x10.b)) == 0) {
        *p2 = 0.0f;
        *p3 = 0.0f;
        *p4 = 0.0f;
    } else {
        Enemy_CopyRotation_2_00140440(o, &v);
        *p2 = 180.0f * v.x / 3.1415927f;
        *p3 = 180.0f * v.y / 3.1415927f;
        *p4 = 180.0f * v.z / 3.1415927f;
    }
}
#undef C
#undef D

/* MapCmd_GetEnemyPosition_1_0017C620 */

void MapCmd_GetEnemyPosition_1_0017C620(u8 *o)
{
    f32 *x = Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyPosition_1_0017C620(o, 2);
    f32 *y = Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyPosition_1_0017C620(o, 3);
    f32 *z = Script_GetArgPtr_2_00165130__as_MapCmd_GetEnemyPosition_1_0017C620(o, 4);
    void *p;
    f32 v[4];
    if (!(p = Event_FindEnemyByMotion_0_00179E50(o[8], o[0x10]))) {
        *x = 0.0f;
        *y = 0.0f;
        *z = 0.0f;
        return;
    }
    Enemy_CopyPosition_2_00140470(p, v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}
#undef C
#undef D

/* MapCmd_SetObjParam_0_0017C6D0 */
void MapCmd_SetObjParam_0_0017C6D0(void *arg0) {
    MapObj_SetNodeFlag_0_001B16E0(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x18));
}
#undef C
#undef D

/* MapCmd_FadeLight_0_0017C6F0 */
void MapCmd_FadeLight_0_0017C6F0(volatile Arg_MapCmd_FadeLight_0_0017C6F0 *a) {
    f32 t;
    f32 u;
    s32 b;
    s32 c;
    s32 o;
    f32 *d;
    f32 *e;
    f32 *f;
    t = a->x28;
    b = a->x18;
    c = a->x20;
    o = a->x8;

    u = 1.0f - t;
    d = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, a->x10));
    e = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, b));
    f = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, c));
    if (d && e && f) {
        d[3] = e[3] * u + f[3] * t;
        d[4] = e[4] * u + f[4] * t;
        d[5] = e[5] * u + f[5] * t;
        d[6] = e[6] * u + f[6] * t;
        d[7] = e[7] * u + f[7] * t;
        d[8] = e[8] * u + f[8] * t;
        d[9] = e[9] * u + f[9] * t;
        d[10] = e[10] * u + f[10] * t;
        d[11] = e[11] * u + f[11] * t;
        d[12] = e[12] * u + f[12] * t;
        d[13] = e[13] * u + f[13] * t;
    }
}
#undef C
#undef D

/* MapCmd_RequestEvent_0_0017C890 */
void MapCmd_RequestEvent_0_0017C890(void *arg0) {
    s32 temp_16;

    temp_16 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_16 == 1) {
        Game_TryRequestEvent_0_0012C110(0xA);
    }
    if (temp_16 == 2) {
        Game_TryRequestEvent_0_0012C110(0x1F);
    }
    if (temp_16 == 3) {
        Game_TryRequestEvent_0_0012C110(0x80);
    }
    if (temp_16 == 4) {
        Game_TryRequestEvent_0_0012C110(0x81);
    }
    if (temp_16 == 0xF) {
        Game_TryRequestEvent_0_0012C110(0x25);
    }
}
#undef C
#undef D

/* MapCmd_ResetObjects_0_0017C930 */
void MapCmd_ResetObjects_0_0017C930(S_MapCmd_ResetObjects_0_0017C930 *s) {
    X *x;
    u32 i;
    E *e;
    x = MapObj_Find_1_001B19A0__as_MapCmd_ResetObjects_0_0017C930(s->x8);
    if (x) {
        i = 0;
        if (i < x->n) {
            e = x->x13C;
            do {
                if (e->x1A == s->x10) {
                    u32 v = e->x1A;
                    u32 w = v >> 5;
                    u32 bit = 1 << ((s32)v % 32);
                    if (s->x18) {
                        x->xA0[w] |= bit;
                        x->x98[w] &= ~bit;
                        return;
                    } else {
                        x->xA0[w] &= ~bit;
                        return;
                    }
                }
                i++;
                e++;
            } while (i < x->n);
        }
    }
}
#undef C
#undef D

/* MapCmd_IsBusy_0_0017CA10 */

void MapCmd_IsBusy_0_0017CA10(s32 a)
{
    u8 *p = Script_GetArgPtr_2_00165130__as_MapCmd_IsBusy_0_0017CA10(a, 0);
    u8 x = Game_GetBusy_0_0012C020();
    *p = x | Player_IsActionLocked_0_001C9AE0();
}
#undef C
#undef D

/* MapCmd_SetFloat_0_0017CA60 */

void MapCmd_SetFloat_0_0017CA60(Obj_MapCmd_PlaySeAtXYZ_1_0017BC00_ *o)
{
    f32 v = o->v;
    f32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_SetFloat_0_0017CA60(o, 1);
    *p = sqrtf(v);
}
#undef C
#undef D

/* MapCmd_SetTexScroll_1_0017CAA0 */
void MapCmd_SetTexScroll_1_0017CAA0(S_MapCmd_PlaySeAtXYZ_1_0017BC00_ *s)
{
    TexAnim_SetScroll_0_001757C0(s->a, s->b, s->x, s->y);
}
#undef C
#undef D

/* MapCmd_SetEffectPos_0_0017CAC0 */
void MapCmd_SetEffectPos_0_0017CAC0(O_MapCmd_SetEffectPos_0_0017CAC0 *o) {
    Vec a, b, c;
    s32 id = o->id;
    u16 x58 = o->x58;
    u16 x60 = o->x60;
    s32 x68 = o->x68;
    a.x = o->x10; a.y = o->x18; a.z = o->x20; a.w = 1.0f;
    b.x = o->x28; b.y = o->x30; b.z = o->x38; b.w = 1.0f;
    c.x = o->x40; c.y = o->x48; c.z = o->x50; c.w = 1.0f;
    MapObj_SpawnItem_0_001B0990(id, &a, &b, &c, x58, x60, x68);
}
#undef C
#undef D

/* MapCmd_Random_2_0017CB50 */

void MapCmd_Random_2_0017CB50(s32 a)
{
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_Random_2_0017CB50(a, 0);
    s32 v = Rand_Next_3_0015ED20();
    if (v < 0)
        v = -v;
    *p = v;
}
#undef C
#undef D

/* MapCmd_GetWeather_0_0017CBA0 */

void MapCmd_GetWeather_0_0017CBA0(s8 *arg0) {
    s32 mode;
    f32 x, y, z;
    f32 *a;
    f32 *b;
    f32 *c;
    f32 *p;
    mode = *(s32 *)(arg0 + 8);
    x = *(f32 *)(arg0 + 0x10);
    y = *(f32 *)(arg0 + 0x18);
    z = *(f32 *)(arg0 + 0x20);
    a = Script_GetArgPtr_2_00165130__as_MapCmd_GetWeather_0_0017CBA0(arg0, 4);
    b = Script_GetArgPtr_2_00165130__as_MapCmd_GetWeather_0_0017CBA0(arg0, 5);
    c = Script_GetArgPtr_2_00165130__as_MapCmd_GetWeather_0_0017CBA0(arg0, 6);
    p = Weather_GetState_0_00157620();
    if (p != NULL) {
        if (mode == 0) {
            p[0] = x;
            p[1] = y;
            p[2] = z;
        } else if (a != NULL && b != NULL && c != NULL) {
            *a = p[0];
            *b = p[1];
            *c = p[2];
        }
    }
}
#undef C
#undef D

/* MapCmd_SetItemFlag_0_0017CC80 */
void MapCmd_SetItemFlag_0_0017CC80(void *arg0) {
    MapObj_DropItem_0_001B0880((s32) M2C_FIELD(arg0, u16 *, 8), (s32) M2C_FIELD(arg0, u16 *, 0x10));
}
#undef C
#undef D

/* MapCmd_GetPlayerVar_0_0017CC90 */

void MapCmd_GetPlayerVar_0_0017CC90(s32 arg0) {
    s16 *temp_16;
    s32 *temp_2;

    temp_16 = PlayerData_Get_2_001C9BA0();
    temp_2 = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerVar_0_0017CC90(arg0, 0);
    if (temp_16 != NULL) {
        *temp_2 = (s32) *temp_16;
    }
}
#undef C
#undef D

/* MapCmd_SetPlayerVar4_0_0017CCE0 */
void MapCmd_SetPlayerVar4_0_0017CCE0(void *arg0) {
    Player_ApplyDamage_2_001C8320(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(arg0, s32 *, 0x20));
}
#undef C
#undef D
#undef CC
#undef DD
#undef C
#undef D

/* MapCmd_SetPlayerVar3_0_0017CD00_ */

/* MapCmd_SetPlayerVar3_0_0017CD00_ */
/* MapCmd_SetPlayerVar3_0_0017CD00 */

/* MapCmd_SetPlayerVar3_0_0017CD00 */
/* MapCmd_SetPlayerVar3_0_0017CD00 */
/* MapCmd_SetPlayerVar3_0_0017CD00 */
/* MapCmd_SetPlayerVar3_0_0017CD00 */
/* MapCmd_SetPlayerVar3_0_0017CD00 */
/* MapCmd_SetPlayerVar3_0_0017CD00 */
/* MapCmd_SetPlayerVar3_0_0017CD00 */
/* MapCmd_SetPlayerVar3_0_0017CD00 */
void MapCmd_SetPlayerVar3_0_0017CD00(S_MapCmd_SetPlayerVar3_0_0017CD00 *s) { Player_AddStatus_1_001C88E0(s->a, s->b, s->c); }

/* MapCmd_GetPlayerStat2_0_0017CD10 */
void MapCmd_GetPlayerStat2_0_0017CD10(Obj_MapCmd_SetPlayerVar3_0_0017CD00 *o)
{
    s32 v = o->v;
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_SetPlayerVar3_0_0017CD00_(o, 1);
    *p = PlayerData_GetStatusTimer_0_001CE200(v);
}

/* MapCmd_SetPlayerFlags_0_0017CD50 */
void MapCmd_SetPlayerFlags_0_0017CD50(A_MapCmd_SetFlag2034_0_0017A640_ *a0) {
    u32 v[7];
    s32 n = a0->n;
    f32 f = a0->f;
    s32 m = a0->m;

    v[6] = 0;
    v[5] = 0;
    v[4] = 0;
    v[3] = 0;
    v[2] = 0;
    v[1] = 0;
    v[0] = 0;
    if (n < 0 || n >= 7) {
        return;
    }
    if (m == 1) {
        v[n] = 1000000;
    } else {
        v[n] = f;
    }
    Player_RollStatusEffect_1_001C8570(v);
}

/* MapCmd_WarpPlayer_0_0017CE20 */
void MapCmd_WarpPlayer_0_0017CE20(Obj_MapCmd_WarpPlayer_0_0017CE20 *o) { V v; f32 y = o->y; f32 z = o->z; v.x = o->x; v.y = y; v.z = z; v.w = 1.0f; Player_Warp_0_001C92C0(&v); }

/* MapCmd_RemoveItem_0_0017CE60 */
void MapCmd_RemoveItem_0_0017CE60(void *arg0) {
    Inventory_ChangeCount_1_001CBED0((s64) M2C_FIELD(arg0, s16 *, 8), -1, 0);
}

/* MapCmd_AddItem_0_0017CE70 */
void MapCmd_AddItem_0_0017CE70(void *arg0) {
    Inventory_ChangeCount_1_001CBED0((s64) M2C_FIELD(arg0, s16 *, 8), 1, 0);
}

/* MapCmd_GetPlayerPos_1_0017CE80 */
void MapCmd_GetPlayerPos_1_0017CE80(s32 a) {
    Q_MapCmd_SetFlag2034_0_0017A640 *q = (Q_MapCmd_SetFlag2034_0_0017A640 *)(gPlayerSbss_002022E4__as_MapCmd_SetPlayerVar3_0_0017CD00->x518 + 0x180);
    f32 *px = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPos_1_0017CE80(a, 0);
    f32 *py = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPos_1_0017CE80(a, 1);
    f32 *pz = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPos_1_0017CE80(a, 2);
    if (q != NULL) {
        *px = 180.0f * q->r->x / 3.1415927f;
        *py = 180.0f * q->r->y / 3.1415927f;
        *pz = 180.0f * q->r->z / 3.1415927f;
    }
}

/* MapCmd_SetPlayerPos_1_0017CF40 */

void MapCmd_SetPlayerPos_1_0017CF40(Obj_MapCmd_SetFlag2034_0_0017A640__ *o)
{
    T_MapCmd_SetPlayerVar3_0_0017CD00 *t = (T_MapCmd_SetPlayerVar3_0_0017CD00 *)(gPlayerSbss_002022E4__as_MapCmd_SetPlayerPos_1_0017CF40->p + 0x180);
    if (t) {
        t->r->r[0] = 3.1415927f * o->x / 180.0f;
        t->r->r[1] = 3.1415927f * o->y / 180.0f;
        t->r->r[2] = 3.1415927f * o->z / 180.0f;
    }
}

/* MapCmd_SetPlayerPosVec_0_0017CFB0 */
void MapCmd_SetPlayerPosVec_0_0017CFB0(Obj_MapCmd_SetFlag2034_0_0017A640__ *o)
{
    V v;
    Player_GetPosB_0_001C9490__as_MapCmd_SetFlag2034_0_0017A640_(&v);
    v.x = o->x;
    v.y = o->y;
    v.z = o->z;
    v.w = 1.0f;
    Player_SetPosAndGround_0_001C94F0(&v);
}

/* MapCmd_GetDistToObject_0_0017D000 */

void MapCmd_GetDistToObject_0_0017D000(Arg_MapCmd_SetFlag2034_0_0017A640__ *a0) {
    Vec b;
    Mtx m;
    Vec a;
    f32 *out;
    s32 idx;
    s8 *o;
    s8 *e;
    s8 *mm;
    s8 *p;

    out = Script_GetArgPtr_2_00165130__as_MapCmd_GetDistToObject_0_0017D000(a0, 2);
    idx = MapObj_GetNodeIndex_0_001B7840(a0->x8, a0->x10);
    if (idx >= 0) {
        o = MapObj_Find_1_001B19A0__as_MapCmd_SetPlayerVar3_0_0017CD00_(a0->x8);
        if (o != NULL) {
            e = *(s8 **)(o + 0x180) + idx * 0x80;
            if (e != NULL) {
                mm = Mdl_GetFrameData_0_001715B0(*(s32 *)(e + 0x40));
                if (mm != NULL) {
                    p = gPlayerSbss_002022E4->unk518 + 0x180;
                    if (p != NULL) {
                        sceVu0CopyVector(&b, p + 0x40);
                        sceVu0CopyMatrix(&m, mm + 0x200);
                        sceVu0SubVector(&a, &m.m[3], &b);
                        *out = sqrtf(sceVu0InnerProduct(&a, &a));
                    }
                }
            }
        }
    }
}

/* MapCmd_GetPlayerFlag_0_0017D0E0 */

void MapCmd_GetPlayerFlag_0_0017D0E0(s32 a)
{
    u8 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerFlag_0_0017D0E0(a, 0);
    T_MapCmd_GetPlayerFlag_0_0017D0E0 *t = Player_GetBodyState_1_001C9B60();
    if (t)
        *p = t->f;
    else
        *p = 0;
}
#undef CC
#undef DD
#undef C
#undef D

/* MapCmd_GetEquip_0_0017D130_ */

/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130_ */
/* MapCmd_GetEquip_0_0017D130 */

/* MapCmd_GetEquip_0_0017D130 */
void MapCmd_GetEquip_0_0017D130(Obj_MapCmd_GetEquip_0_0017D130 *o)
{
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetEquip_0_0017D130(o, 1);
    *p = Equip_GetSlotItem_1_001CCD90(o->h);
}

/* MapCmd_GetEffectState_0_0017D170 */

void MapCmd_GetEffectState_0_0017D170(Obj_MapCmd_GetEquip_0_0017D130 *o)
{
    u8 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetEffectState_0_0017D170(o, 1);
    u8 *t = Inventory_GetEntry_1_001CC3F0(o->h);
    if (t)
        *p = t[2];
    else
        *p = 0;
}

/* MapCmd_CopyVar_0_0017D1C0 */
void MapCmd_CopyVar_0_0017D1C0(u8 *a0) {
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetEquip_0_0017D130_(a0, 0);
    s32 *q = Script_GetArgPtr_2_00165130__as_MapCmd_GetEquip_0_0017D130_(a0, 1);
    s32 m = *(s32 *)(a0 + 0x18);
    if (m == 0) *p = *(f32 *)q;
    if (m == 1) *(f32 *)q = *p;
}

/* MapCmd_GetPlayerRot_1_0017D240 */
void MapCmd_GetPlayerRot_1_0017D240(s32 a) {
    R *s = &gPlayerSbss_002022E4__as_MapCmd_GetEquip_0_0017D130_->x518->r;
    f32 *p = (f32 *)Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerRot_1_0017D240(a, 0);
    f32 t;
    if (s != NULL) {
        t = 3.1415927f + s->x18->x24;
        *p = 180.0f * ((t - 6.2831855f * (s32)(0.15915494f * t)) + (t < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f) / 3.1415927f;
    }
}

/* MapCmd_GetPlayerVarB_0_0017D300 */

void MapCmd_GetPlayerVarB_0_0017D300(s32 arg0) {
    s32 *temp_2;
    void *temp_16;

    temp_16 = PlayerData_Get_2_001C9BA0();
    temp_2 = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerVarB_0_0017D300(arg0, 0);
    if (temp_16 != NULL) {
        *temp_2 = (s32) M2C_FIELD(temp_16, s16 *, 4);
    }
}

/* MapCmd_GetPlayerPosB_0_0017D350 */

void MapCmd_GetPlayerPosB_0_0017D350(void *o)
{
    f32 *x = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPosB_0_0017D350(o, 0);
    f32 *y = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPosB_0_0017D350(o, 1);
    f32 *z = Script_GetArgPtr_2_00165130__as_MapCmd_GetPlayerPosB_0_0017D350(o, 2);
    f32 v[4];
    Player_GetPosB_0_001C9490__as_MapCmd_GetEquip_0_0017D130_(v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}

/* MapCmd_SetObjectAlpha_0_0017D3D0 */
void MapCmd_SetObjectAlpha_0_0017D3D0(Arg_MapCmd_GetEquip_0_0017D130_ *a) {
    f32 f;
    s32 id;
    s32 i;
    Obj_MapCmd_SetObjectAlpha_0_0017D3D0 *o;
    N_MapCmd_GetEquip_0_0017D130 *n;
    f = a->x18;
    id = a->x8;
    i = MapObj_GetNodeIndex_0_001B7840(id, a->x10);
    if (i >= 0) {
        o = MapObj_Find_1_001B19A0__as_MapCmd_GetEquip_0_0017D130_(id);
        if (o != NULL) {
            n = &o->n[i];
            if (n != NULL) {
                if (f < 0.0f || f > 255.0f) return; n->x58 = f / 255.0f;
            }
        }
    }
}

/* MapCmd_SetObjectsAlpha_0_0017D480 */

void MapCmd_SetObjectsAlpha_0_0017D480(s8 *a) {
    s32 i;
    Obj_MapCmd_GetEquip_0_0017D130_ *o;
    N_MapCmd_SetObjectsAlpha_0_0017D480 *n;
    i = MapObj_GetNodeIndex_0_001B7840__as_MapCmd_SetObjectsAlpha_0_0017D480(*(u8 *)(a + 8), *(u16 *)(a + 0x10));
    if (i >= 0) {
        o = MapObj_Find_1_001B19A0__as_MapCmd_SetObjectsAlpha_0_0017D480(*(u8 *)(a + 8));
        if (o != NULL) {
            n = &o->n[i];
            if (n != NULL) {
                if (*(u8 *)(a + 0x18) == 0) {
                    n->f.f.b3 = 0;
                    n->f.f.b4 = 0;
                }
                if (*(u8 *)(a + 0x18) == 1) {
                    n->f.f.b3 = 1;
                    n->f.f.b4 = 0;
                }
                if (*(u8 *)(a + 0x18) == 2) {
                    n->f.f.b3 = 1;
                    n->f.f.b4 = 1;
                }
            }
        }
    }
}

/* MapCmd_RotateNode_0_0017D5B0 */
void MapCmd_RotateNode_0_0017D5B0(s8 *arg0) {
    f32 f[4][4];
    f32 d[4][4];
    f32 c[4];
    f32 a[4][4];
    f32 b[4][4];
    s32 s1;
    s32 s0;
    f32 ang;
    f32 x, y, z;
    s32 i;
    f32 *p;
    f32 *q;

    s0 = *(s32 *)(arg0 + 0x10);
    s1 = *(s32 *)(arg0 + 8);
    x = *(f32 *)(arg0 + 0x18);
    y = *(f32 *)(arg0 + 0x20);
    z = *(f32 *)(arg0 + 0x28);
    ang = *(f32 *)(arg0 + 0x30);
    c[0] = x;
    c[1] = y;
    c[2] = z;
    c[3] = 1.0f;
    MapObj_GetNodeMatrix_0_001B7B30(s1, s0, a);
    i = 0;
    p = a[0];
    q = f[0];
    do {
        i++;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        p += 4;
        q += 4;
    } while (i < 4);
    Mtx_AxisAngle_2_0015EBB0(d, c, ang);
    d[3][0] = f[3][0];
    d[3][1] = f[3][1];
    d[3][2] = f[3][2];
    d[3][3] = f[3][3];
    i = 0;
    p = d[0];
    q = b[0];
    do {
        i++;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        p += 4;
        q += 4;
    } while (i < 4);
    MapObj_SetNodeMatrixB_0_001B7A30(s1, s0, b);
}

/* MapCmd_RotateNodeRel_0_0017D6E0 */
void MapCmd_RotateNodeRel_0_0017D6E0(s8 *arg0) {
    f32 f[4][4];
    f32 d[4][4];
    f32 c[4];
    f32 a[4][4];
    f32 b[4][4];
    s32 s1;
    s32 s0;
    f32 ang;
    f32 x, y, z;
    s32 i;
    f32 *p;
    f32 *q;
    f32 *r;
    s32 j;

    s0 = *(s32 *)(arg0 + 0x10);
    s1 = *(s32 *)(arg0 + 8);
    x = *(f32 *)(arg0 + 0x18);
    y = *(f32 *)(arg0 + 0x20);
    z = *(f32 *)(arg0 + 0x28);
    ang = *(f32 *)(arg0 + 0x30);
    c[0] = x;
    c[1] = y;
    c[2] = z;
    c[3] = 1.0f;
    MapObj_GetNodeMatrix_0_001B7B30(s1, s0, a);
    r = f[0];
    i = 0;
    p = a[0];
    q = r;
    do {
        i++;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        p += 4;
        q += 4;
    } while (i < 4);
    Mtx_AxisAngle_2_0015EBB0(d, c, ang);
    sceVu0MulMatrix(f, f, d);
    j = 0;
    q = b[0];
    do {
        j++;
        q[0] = r[0];
        q[1] = r[1];
        q[2] = r[2];
        q[3] = r[3];
        r += 4;
        q += 4;
    } while (j < 4);
    MapObj_SetNodeMatrixB_0_001B7A30(s1, s0, b);
}

/* MapCmd_TranslateNode_0_0017D810 */
void MapCmd_TranslateNode_0_0017D810(S_MapCmd_TranslateNode_0_0017D810 *arg0) {
    f32 b[4][4];
    f32 a[4][4];
    f32 c[4][4];
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 s1 = arg0->x10;
    f32 x = arg0->x18;
    f32 y = arg0->x20;
    s32 s0 = arg0->x8;
    f32 z = arg0->x28;

    MapObj_GetNodeMatrix_0_001B7B30(s0, s1, a);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            b[i][j] = a[i][j];
        }
    }
    b[3][0] += x;
    b[3][1] += y;
    b[3][2] += z;
    for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
            c[k][l] = b[k][l];
        }
    }
    MapObj_SetNodeMatrixB_0_001B7A30(s0, s1, c);
}

/* MapCmd_GetGlobal_0_0017D930 */

void MapCmd_GetGlobal_0_0017D930(s32 a)
{
    s8 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetGlobal_0_0017D930(a, 0);
    *p = Save_GetByte2E_0_001AA740();
}

/* MapCmd_TranslateNodeRel_0_0017D960 */
void MapCmd_TranslateNodeRel_0_0017D960(S_MapCmd_SetFlag2034_0_0017A640_ *arg0) {
    f32 b[4][4];
    f32 a[4][4];
    f32 c[4][4];
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 s1 = arg0->x10;
    f32 x = arg0->x18;
    f32 y = arg0->x20;
    s32 s0 = arg0->x8;
    f32 z = arg0->x28;

    MapObj_GetNodeMatrix_0_001B7B30(s0, s1, a);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            b[i][j] = a[i][j];
        }
    }
    b[3][0] = x;
    b[3][1] = y;
    b[3][2] = z;
    for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
            c[k][l] = b[k][l];
        }
    }
    MapObj_SetNodeMatrixB_0_001B7A30(s0, s1, c);
}

/* MapCmd_GetNodePos_0_0017DA60 */

void MapCmd_GetNodePos_0_0017DA60(s8 *arg0) {
    f32 f[4][4];
    f32 a[4][4];
    s32 s1;
    s32 s0;
    f32 *px;
    f32 *py;
    f32 *pz;
    s32 i;
    f32 *p;
    f32 *q;

    s1 = *(s32 *)(arg0 + 8);
    s0 = *(s32 *)(arg0 + 0x10);
    px = Script_GetArgPtr_2_00165130__as_MapCmd_GetNodePos_0_0017DA60(arg0, 2);
    py = Script_GetArgPtr_2_00165130__as_MapCmd_GetNodePos_0_0017DA60(arg0, 3);
    pz = Script_GetArgPtr_2_00165130__as_MapCmd_GetNodePos_0_0017DA60(arg0, 4);
    MapObj_GetNodeMatrix_0_001B7B30(s1, s0, a);
    i = 0;
    p = a[0];
    q = f[0];
    do {
        i++;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        p += 4;
        q += 4;
    } while (i < 4);
    *px = f[3][0];
    *py = f[3][1];
    *pz = f[3][2];
}
#undef CC
#undef DD
#undef C
#undef D

/* MapCmd_SetCameraTarget_0_0017DB40_ */

/* MapCmd_SetCameraTarget_0_0017DB40_ */
/* MapCmd_SetCameraTarget_0_0017DB40_ */
/* MapCmd_SetCameraTarget_0_0017DB40_ */
/* MapCmd_SetCameraTarget_0_0017DB40_ */
/* MapCmd_SetCameraTarget_0_0017DB40_ */
/* MapCmd_SetCameraTarget_0_0017DB40 */

/* MapCmd_SetCameraTarget_0_0017DB40 */
/* MapCmd_SetCameraTarget_0_0017DB40 */
/* MapCmd_SetCameraTarget_0_0017DB40 */
/* MapCmd_SetCameraTarget_0_0017DB40 */
/* MapCmd_SetCameraTarget_0_0017DB40 */
/* MapCmd_SetCameraTarget_0_0017DB40 */
void MapCmd_SetCameraTarget_0_0017DB40(S_MapCmd_SetCameraTarget_0_0017DB40 *s)
{
    Camera_SetParams_0_001C8F30(s->x, s->y, s->z, s->w);
}

/* MapCmd_Vibrate_1_0017DB60 */
void MapCmd_Vibrate_1_0017DB60(A_MapCmd_SetCameraTarget_0_0017DB40_ *a) {
    s32 m = a->x30;
    f32 f = a->x8;
    f32 e = a->x10;
    f32 d = a->x18;
    f32 c = a->x20;
    f32 b = a->x28;
    if (m == 0) Vibe_StartB_0_0015FE20(f, e, d, c, b);
    if (m == 1) Vibe_StartA_0_0015FD90(f, e, d, c, b);
}

/* MapCmd_SetLightPos_0_0017DC00 */
void MapCmd_SetLightPos_0_0017DC00(O_MapCmd_SetCameraTarget_0_0017DB40 *o) {
    Vec a;
    Vec b;
    s16 i = o->x8;
    s16 j = o->x10;
    f32 ax = o->x18, ay = o->x20, az = o->x28;
    f32 bx = o->x30, by = o->x38, bz = o->x40;
    a.x = ax;
    a.y = ay;
    a.z = az;
    a.w = 1.0f;
    b.x = bx;
    b.y = by;
    b.z = bz;
    b.w = 1.0f;
    MapObj_SpawnSfx_0_001B0D60(i, j, &a, &b);
}

/* MapCmd_GetObjectVar_0_0017DC70 */
void MapCmd_GetObjectVar_0_0017DC70(S_MapCmd_GetObjectVar_0_0017DC70 *s)
{
    int *r = Script_GetArgPtr_2_00165130__as_MapCmd_SetCameraTarget_0_0017DB40_(s, 0);
    int id = s->id;
    int t = -1;

    *r = MapObj_GetCount_0_001B17E0(&t);
    if (t != id)
        *r = -1;
}

/* MapCmd_GetObjectVarB_0_0017DCD0 */

void MapCmd_GetObjectVarB_0_0017DCD0(Obj_MapCmd_SetCameraTarget_0_0017DB40 *o)
{
    s32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectVarB_0_0017DCD0(o, 0);
    s32 v = o->v;
    *p = MapObj_GetCountB_0_001B18D0(&v);
}

/* MapCmd_SetObjectFlag_0_0017DD10 */
void MapCmd_SetObjectFlag_0_0017DD10(u8 *arg0) {
    u8 *temp_6;
    u8 *temp_2;
    s32 temp_17;
    s32 temp_16_2;
    s32 temp_16;

    temp_16 = M2C_FIELD(arg0, s32 *, 8);
    temp_17 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_16_2 = MapObj_GetNodeIndex_0_001B7840__as_MapCmd_SetCameraTarget_0_0017DB40(temp_16, M2C_FIELD(arg0, s32 *, 0x10));
    temp_2 = (u8 *) (MapObj_Find_1_001B19A0__as_MapCmd_SetCameraTarget_0_0017DB40(temp_16));
    if (temp_2 != NULL) {
        temp_6 = (u8 *) (M2C_FIELD(temp_2, s32 *, 0x180) + (temp_16_2 << 7));
        if (temp_6 != NULL) {
            ((BF_53_1_1 *)temp_6)->f = temp_17;
        }
    }
}

/* MapCmd_GetObjectFlag_0_0017DD90 */
void MapCmd_GetObjectFlag_0_0017DD90(O_MapCmd_GetObjectFlag_0_0017DD90 *o) {
    s32 a;
    s32 b;
    s32 t;
    f32 *p;
    f32 *q;
    f32 *r;
    Mtx m;
    a = o->x8;
    b = o->x10;
    t = o->x18;
    p = Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectFlag_0_0017DD90(o, 3);
    q = Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectFlag_0_0017DD90(o, 4);
    r = Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectFlag_0_0017DD90(o, 5);
    MapObj_SetNodeMatrix_0_001B78D0(a, b, t, &m);
    *p = m.m[3].x;
    *q = m.m[3].y;
    *r = m.m[3].z;
}

/* MapCmd_PlayObjectAnim_0_0017DE40 */
void MapCmd_PlayObjectAnim_0_0017DE40(Obj_MapCmd_PlayObjectAnim_0_0017DE40 *o)
{
    s32 a = o->a;
    s32 b = MapObj_Find_1_001B19A0__as_MapCmd_SetCameraTarget_0_0017DB40_(a);
    MapObj_SetAnimFrame_0_001B87C0(b, MapObj_GetNodeIndex_0_001B7840(a, o->b), o->c, o->d, o->x, o->y);
}

/* MapCmd_SetObjectAnimB_0_0017DEA0 */
void MapCmd_SetObjectAnimB_0_0017DEA0(S_MapCmd_SetCameraTarget_0_0017DB40_ *s) { MapObj_PlayAnim_1_001B7CD0(s->a, s->b); }

/* MapCmd_SetObjectAnimC_0_0017DEB0 */
void MapCmd_SetObjectAnimC_0_0017DEB0(S_MapCmd_SetCameraTarget_0_0017DB40_ *s)
{
    MapObj_StopAnim_1_001B7C10(s->a, s->b);
}

/* MapCmd_GetObjectAnim_0_0017DEC0 */

void MapCmd_GetObjectAnim_0_0017DEC0(Obj_MapCmd_SetFlag2034_0_0017A640___ *o)
{
    s32 a = o->a;
    s32 b = o->b;
    s32 c = o->c;
    f32 *p = Script_GetArgPtr_2_00165130__as_MapCmd_GetObjectAnim_0_0017DEC0(o, 3);
    *p = MapObj_GetAnimFrameB_1_001B7610(a, b, c);
}

/* MapCmd_SpawnItem_0_0017DF20 */

void MapCmd_SpawnItem_0_0017DF20(Arg_MapCmd_SetFlag2034_0_0017A640___ *a0) {
    s32 type;
    f32 dx;
    s32 id;
    f32 dy;
    s32 sub;
    f32 dz;
    s32 *out;
    Vec v;

    type = a0->x8;
    dx = a0->x28;
    id = a0->x10;
    dy = a0->x50;
    sub = a0->x18;
    dz = a0->x58;
    out = Script_GetArgPtr_2_00165130__as_MapCmd_SpawnItem_0_0017DF20(a0, 5);
    Script_GetArgPtr_2_00165130__as_MapCmd_SpawnItem_0_0017DF20(a0, 6);
    Script_GetArgPtr_2_00165130__as_MapCmd_SpawnItem_0_0017DF20(a0, 7);
    Script_GetArgPtr_2_00165130__as_MapCmd_SpawnItem_0_0017DF20(a0, 8);
    if (type == 0) {
        *out = Save_TestItemBit_1_001A9B40(id);
    }
    if (type == 1) {
        *out = 0;
        *out = ItemObj_OffsetAll_0_001AC0F0(id, sub, &v);
        if (*out != 0) {
            v.x += dx;
            v.y += dy;
            v.z += dz;
            v.w = 1.0f;
            *out = ItemMdl_SetTransform_0_001ABF70(id, sub, &v);
            if (*out == 0) {
                return;
            }
        }
    }
}

/* MapCmd_PlayBgm_0_0017E050 */
void MapCmd_PlayBgm_0_0017E050(s8 *arg0) {
    s32 mode;
    s32 a;
    s32 b;
    s32 c;
    mode = *(s32 *)(arg0 + 8);
    a = *(s32 *)(arg0 + 0x10);
    b = *(s32 *)(arg0 + 0x18);
    c = *(s32 *)(arg0 + 0x20);
    if (mode == 2) PlayerData_ClearStatus_0_001CE270(a);
    if (mode == 3) Inventory_AddItem_1_001A95A0(a, b);
    if (mode == 4) Item_ClearNewFlag_0_001A9510(a);
    if (mode == 5) Msg_Close_1_0018B0C0();
    if (mode == 6) MapCmd_SetObjectTexture_0_0017E150__as_MapCmd_SetFlag2034_0_0017A640__(a, b, c);
    if (mode == 7) Snd_PlaySe_3_00131600(a, b);
    if (mode == 8) SndCh_Stop_2_00131440(a);
    if (mode == 9) MapSheet_Open_0_001ED620(a);
}
#undef CC
#undef DD
#undef C
#undef D

/* MapCmd_SetObjectTexture_0_0017E150__ */

/* MapCmd_SetObjectTexture_0_0017E150__ */
/* MapCmd_SetObjectTexture_0_0017E150_ */

/* MapCmd_SetObjectTexture_0_0017E150_ */
/* MapCmd_SetObjectTexture_0_0017E150 */

/* MapCmd_SetObjectTexture_0_0017E150 */
/* MapCmd_SetObjectTexture_0_0017E150 */
/* MapCmd_SetObjectTexture_0_0017E150 */
s32 MapCmd_SetObjectTexture_0_0017E150(s32 arg0, s32 id, s32 v) {
    Obj_MapCmd_SetObjectTexture_0_0017E150_ *o = MapObj_Find_1_001B19A0__as_MapCmd_SetObjectTexture_0_0017E150__(arg0);
    E30 *p;
    E8 *q;
    s32 i;

    if (o == NULL) return 0;
    p = o->arr;
    q = o->e8;
    if (v < -1 || v > 31) return 0;
    for (i = 0; i < o->count; i++, p++, q++) {
        if (p == NULL) return 0;
        if (q == NULL) return 0;
        if (p->id == id) p->x21 = v;
    }
    return 1;
}

/* MapCmd_QueryEnemies_0_0017E220 */
/* cf. KFIV's LinkedPoint_StartDefault (kfiv-decomp src/game/model/linked_point.c). */


void MapCmd_QueryEnemies_0_0017E220(Point *p)
{
    if (p->kind == 1)
        EnemyScr_BroadcastQuery_0_00141380(0x80, 0);
}

/* MapCmd_GetSfxState_0_0017E260 */
void MapCmd_GetSfxState_0_0017E260(O_MapCmd_SetObjectTexture_0_0017E150 *o) {
    s32 a;
    s32 b;
    s32 t;
    f32 *p;
    f32 *q;
    f32 *r;
    s32 g;
    s32 h;
    Mtx m;
    a = o->x8;
    b = o->x10;
    t = o->x18;
    p = Script_GetArgPtr_2_00165130__as_MapCmd_SetObjectTexture_0_0017E150_(o, 3);
    q = Script_GetArgPtr_2_00165130__as_MapCmd_SetObjectTexture_0_0017E150_(o, 4);
    r = Script_GetArgPtr_2_00165130__as_MapCmd_SetObjectTexture_0_0017E150_(o, 5);
    g = o->x38;
    h = o->x40;
    MapObj_GetSfxMatrix_0_001B1050(a, b, &m);
    switch (t) {
    case 1:
        m.m[3].x = *p;
        m.m[3].y = *q;
        m.m[3].z = *r;
        break;
    case 2:
        MapObj_SetNodeMatrix_0_001B78D0(a, g, h, &m);
        break;
    }
    MapObj_SetSfxMatrix_0_001B0EB0(a, b, &m);
}

/* MapCmd_SetSfx_0_0017E370 */
void MapCmd_SetSfx_0_0017E370(void *arg0) {
    MapObj_SetSfxFlag_0_001B11F0__as_MapCmd_SetObjectTexture_0_0017E150(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x18));
}

/* MapCmd_SetSfxTransform_0_0017E390 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define DEG(d) (3.1415927f * (d) / 180.0f)

void MapCmd_SetSfxTransform_0_0017E390(O_MapCmd_SetSfxTransform_0_0017E390 *o) {
    Mtx m;

    sceVu0CopyMatrix__as_MapCmd_SetObjectTexture_0_0017E150__(&m, &gMatrixFromData_001F2170);
    sceVu0RotMatrixZ(WRAP(DEG(o->x30)), &m, &m);
    sceVu0RotMatrixX(WRAP(DEG(o->x38)), &m, &m);
    sceVu0RotMatrixY(WRAP(DEG(o->x40)), &m, &m);
    m.m[3].x = o->x18;
    m.m[3].y = o->x20;
    m.m[3].z = o->x28;
    MapObj_SetSfxMatrix_0_001B0EB0__as_MapCmd_SetSfxTransform_0_0017E390(o->b8, o->h10, &m);
    MapObj_SetSfxFlag_0_001B11F0(o->b8, o->h10, 1);
}

/* MapCmd_SetSfxParamA_0_0017E5B0 */
static inline s32 ok_MapCmd_SetObjectTexture_0_0017E150(Chr **p) {
    s32 r;
    if (p != 0) {
        r = ((*p)->x1D8 & 1) != 0;
    } else {
        r = 0;
    }
    return r;
}
static inline Chr *find_MapCmd_SetObjectTexture_0_0017E150(s32 id) {
    Chr *r = 0;
    if (ok_MapCmd_SetObjectTexture_0_0017E150(((Chr ***)&gMapSbss_00201E80)[2]) && (*((Chr ***)&gMapSbss_00201E80)[2])->id == id) {
        r = *((Chr ***)&gMapSbss_00201E80)[2];
    }
    if (ok_MapCmd_SetObjectTexture_0_0017E150(((Chr ***)&gMapSbss_00201E80)[3]) && (*((Chr ***)&gMapSbss_00201E80)[3])->id == id) {
        r = *((Chr ***)&gMapSbss_00201E80)[3];
    }
    return r;
}
static inline s32 lookup_MapCmd_SetObjectTexture_0_0017E150(Chr *c, s32 key) {
    s32 i;
    Ent_MapCmd_SetFlag2034_0_0017A640 *e;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapCmd_SetSfxParamA_0_0017E5B0(Arg_MapCmd_SetObjectTexture_0_0017E150 *a) {
    f32 fl = a->x18;
    s32 id = a->id;
    s32 key = a->key;
    Chr *t = find_MapCmd_SetObjectTexture_0_0017E150(id);
    s32 idx = lookup_MapCmd_SetObjectTexture_0_0017E150(find_MapCmd_SetObjectTexture_0_0017E150(id), key);

    if (t != 0 && idx != -1) {
        Sfx_SetParam17C_1_00167290(t->x190[idx * 2], fl, t, key);
    }
}

/* MapCmd_GetSfxParamA_0_0017E760 */
static inline s32 ok_MapCmd_GetSfxParamA_0_0017E760(Chr **p) {
    s32 r;
    if (p != 0) { r = ((*p)->x1D8 & 1) != 0; } else { r = 0; }
    return r;
}
static inline Chr *find_MapCmd_GetSfxParamA_0_0017E760(s32 id) {
    Chr *r = 0;
    Chr **p;
    p = ((Chr ***)&gMapSbss_00201E80)[2]; if (ok_MapCmd_GetSfxParamA_0_0017E760(p) && (*p)->id == id) r = *p;
    if (ok_MapCmd_GetSfxParamA_0_0017E760(((Chr ***)&gMapSbss_00201E80)[3]) && (*((Chr ***)&gMapSbss_00201E80)[3])->id == id) r = *((Chr ***)&gMapSbss_00201E80)[3];
    return r;
}
static inline s32 lookup_MapCmd_GetSfxParamA_0_0017E760(Chr *c, s32 key) {
    s32 i;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapCmd_GetSfxParamA_0_0017E760(Arg_MapCmd_GetSfxParamA_0_0017E760 *a) {
    s32 id = a->id; s32 key = a->key; f32 *out = Script_GetArgPtr_2_00165130__as_MapCmd_GetSfxParamA_0_0017E760(a, 2);
    Chr *t = find_MapCmd_GetSfxParamA_0_0017E760(id); s32 idx = lookup_MapCmd_GetSfxParamA_0_0017E760(find_MapCmd_GetSfxParamA_0_0017E760(id), key);
    if (t == 0) { *out = -1.0f; } else if (idx == -1) { *out = -1.0f; } else { *out = Sfx_GetParam17C_1_00167280(t->x190[idx * 2]); }
}

/* MapCmd_SetSfxParamB_0_0017E940 */
static inline s32 ok_MapCmd_SetFlag2034_0_0017A640(Chr **p) {
    s32 r;
    if (p != 0) {
        r = ((*p)->x1D8 & 1) != 0;
    } else {
        r = 0;
    }
    return r;
}
static inline Chr *find_MapCmd_SetFlag2034_0_0017A640(s32 id) {
    Chr *r = 0;
    if (ok_MapCmd_SetFlag2034_0_0017A640(((Chr ***)&gMapSbss_00201E80)[2]) && (*((Chr ***)&gMapSbss_00201E80)[2])->id == id) {
        r = *((Chr ***)&gMapSbss_00201E80)[2];
    }
    if (ok_MapCmd_SetFlag2034_0_0017A640(((Chr ***)&gMapSbss_00201E80)[3]) && (*((Chr ***)&gMapSbss_00201E80)[3])->id == id) {
        r = *((Chr ***)&gMapSbss_00201E80)[3];
    }
    return r;
}
static inline s32 lookup_MapCmd_SetFlag2034_0_0017A640(Chr *c, s32 key) {
    s32 i;
    Ent_MapCmd_SetFlag2034_0_0017A640 *e;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapCmd_SetSfxParamB_0_0017E940(Arg_MapCmd_SetObjectTexture_0_0017E150_ *a) {
    f32 fl = a->x18;
    s32 id = a->id;
    s32 key = a->key;
    Chr *t = find_MapCmd_SetFlag2034_0_0017A640(id);
    s32 idx = lookup_MapCmd_SetFlag2034_0_0017A640(find_MapCmd_SetFlag2034_0_0017A640(id), key);

    if (t != 0 && idx != -1) {
        Sfx_SetParam180_1_00167270(fl, t->x190[idx * 2], t, key);
    }
}
#undef CC
#undef DD
#undef C
#undef D

/* MapCmd_GetSfxParamB_0_0017EAF0 */
static inline s32 ok_MapCmd_GetSfxParamB_0_0017EAF0(Chr **p) {
    s32 r;
    if (p != 0) { r = ((*p)->x1D8 & 1) != 0; } else { r = 0; }
    return r;
}
static inline Chr *find_MapCmd_GetSfxParamB_0_0017EAF0(s32 id) {
    Chr *r = 0;
    Chr **p;
    p = ((Chr ***)&gMapSbss_00201E80)[2]; if (ok_MapCmd_GetSfxParamB_0_0017EAF0(p) && (*p)->id == id) r = *p;
    if (ok_MapCmd_GetSfxParamB_0_0017EAF0(((Chr ***)&gMapSbss_00201E80)[3]) && (*((Chr ***)&gMapSbss_00201E80)[3])->id == id) r = *((Chr ***)&gMapSbss_00201E80)[3];
    return r;
}
static inline s32 lookup_MapCmd_GetSfxParamB_0_0017EAF0(Chr *c, s32 key) {
    s32 i;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapCmd_GetSfxParamB_0_0017EAF0(Arg *a) {
    s32 id = a->id; s32 key = a->key; f32 *out = Script_GetArgPtr_2_00165130__as_MapCmd_GetSfxParamB_0_0017EAF0(a, 2);
    Chr *t = find_MapCmd_GetSfxParamB_0_0017EAF0(id); s32 idx = lookup_MapCmd_GetSfxParamB_0_0017EAF0(find_MapCmd_GetSfxParamB_0_0017EAF0(id), key);
    if (t == 0) { *out = -1.0f; } else if (idx == -1) { *out = -1.0f; } else { *out = Sfx_GetParam180_1_00167260(t->x190[idx * 2]); }
}
#undef Enemy_GetTargetHandle_0_0013EDE0
#undef Ent_IsNull0_1_0013EE30
#undef MapObj_Find_1_001B19A0
#undef Event_FindEnemyByMotion_0_00179E50
#undef Enemy_CopyPosition_2_00140470
#undef CC
#undef DD
#undef C
#undef D

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/vibration_bss.c): gMapCommandBss_00317238 */
u16 gMapCommandBss_00317238[0x2];
#endif
