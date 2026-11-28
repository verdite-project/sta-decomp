#include "m2c.h"
#include "common.h"
#include "actor.h"
#include "game/enemy.h"
#include "game/player.h"
#include "game/save.h"
#include "game/ui.h"
typedef struct { u8 pad[0x22]; u16 x22; u16 x24; u8 pad2[0x54-0x26]; } Ent;
typedef struct { u8 pad[0x13C]; Ent *ents; } Tbl;
typedef struct { Tbl *tbl; } Hdr;
typedef struct { u8 pad[0x4A8]; Hdr *x4A8; u16 x4AC; u8 p4AE[0xF3]; Flags8 f5A1; } O_Enemy_GetScreenSize_0_0013FEB0;
typedef struct { char pad[0x198]; f32 *v; } B_Enemy_GetDistSqToPlayer_1_001402A0;
typedef struct { char pad[0x518]; B_Enemy_GetDistSqToPlayer_1_001402A0 *b; } Obj_Enemy_GetDistSqToPlayer_1_001402A0;
typedef struct { char pad[0x24]; f32 yaw; } C_Enemy_GetScreenSize_0_0013FEB0;
typedef struct { char pad[0x198]; C_Enemy_GetScreenSize_0_0013FEB0 *c; } B_Enemy_GetRightVector_1_00140360;
typedef struct { char pad[0x518]; B_Enemy_GetRightVector_1_00140360 *b; } Obj_Enemy_GetRightVector_1_00140360;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2026_1_00140480;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2025_1_00140770;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2024GetMove_1_001409A0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2023_1_00140CB0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2022_1_00140DE0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2021_1_00140E50;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2020_1_00140EF0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_BroadcastFrameEvent_0_001410C0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2018_1_001411F0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2017OnDeath_1_00141260;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2016_1_001412E0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_BroadcastQuery_0_00141380;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2015_1_00141510;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2014_1_00141610;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2013GetMove_1_001416B0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2012_1_001419C0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2011GetWeights_1_00141A50;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2010_1_00141DA0;
typedef struct { u8 pad[0x4A4]; s32 *x4A4; } A_Enemy_GetScreenSize_0_0013FEB0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event200E_1_00142010;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event200DGetStats_1_00142090;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event200COnHit_1_00142320;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event200B_1_001423E0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2009Move_1_00142470;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2005Turn_1_00142530;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2004Attack_1_001425F0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2003React_1_001426C0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2002_1_00142780;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2001_1_00142820;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_EventInit_1_001428C0;
typedef struct { u8 pad[0x10]; u8 tbl[1][0x100]; } T;
typedef struct { u8 pad[0x10010]; Vec tbl[1]; } Obj;
typedef struct { u8 pad[0x10010]; Vec s[1]; } Big;
typedef struct { char pad[8]; u16 h; } Obj_EnemyCmd_GetFlag_0_001438B0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B4b6_1_00143920;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B4b5_1_00143930;
typedef struct { f32 x, y, z; s32 w; } V3;
typedef struct { s32 p0, p4; u8 type; u8 p9[7]; f32 a; s32 p14; f32 b; s32 p1C; f32 c; } Arg_EnemyCmd_GetRelativePos_0_00143960;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Get608_1_00143B20;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5A1b5_1_00143BB0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B4b4_1_00143BC0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_StartTimer_0_00143BD0;
typedef struct { char pad[8]; f32 f; } Obj_EnemyCmd_StartTimer_0_00143BD0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetMotionFrame_1_00143C30;
typedef struct { char pad[0x154]; s32 p; } S_EnemyCmd_ResolveHit_0_00143C70;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetVec660_0_00143D60;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_UpdatePartStat_1_00143DF0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_InitPart_1_00143E10;
typedef struct { Vec s; Vec e; } Seg;
typedef struct { Vec p; u8 pad[0x14]; s32 hit; u8 pad2[0x18]; } Hit;
typedef struct { u8 pad[0xC]; f32 xC; } Q;
typedef struct { Q *p; s32 pad[2]; } QP __attribute__((aligned(16)));
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_BroadcastMotion_1_001442F0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Kill_1_00144360;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_SetHiddenFlags_0_00144370;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b6w2_1_001443E0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b2_1_001443F0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b1_1_00144400;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b2_1_00144410;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_ClampHpFromFlag_1_00144420;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_StoreHpToFlag_1_00144490;
typedef struct { u8 pad0[0x34]; u16 x34; u16 x36; u8 x38; u8 x39; u8 x3A; u8 x3B; u8 pad3C[4]; } T_EnemyCmd_FindSpawnPoint_0_001444F0;
typedef struct { u8 pad0[0x5E0]; f32 x5E0[7]; u8 x5FC[7]; u8 pad603; u16 x604; } O_EnemyCmd_Nop_1_00143890;
typedef struct { u8 pad0[0x24]; s32 x24; u8 pad28[0x18]; } Buf;
typedef struct { u8 pad0[8]; u8 x8; u8 pad9[7]; u16 x10; u8 pad12[6]; f32 x18; u8 pad1C[4]; f32 x20; } Msg;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetPosition_2_00144970;
typedef struct { u8 pad[2]; u8 x2; } C_EnemyCmd_Nop_1_00143890;
typedef struct { u8 pad[8]; u16 x8; u8 padA[0xE]; f32 x18; f32 p1C; f32 x20; f32 p24; f32 x28; } Arg_EnemyCmd_SpawnEffectB_0_00144BE0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B2b0_1_00144D70;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_BroadcastFrame_1_00144D80;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b7_1_00144DF0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b6_1_00144E00;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_BreakPart_1_00144E10;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b0_1_00144E30;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_HealPercent_1_00144E40;
typedef struct { char pad[0x154]; void *p; } Ctx;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetParamIdx_1_00144F60;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b1_1_00144FA0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_UpdateParamFlags_1_00144FB0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_RegisterKill_0_00144FC0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_RegisterSeen_0_00145010;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B1b0_1_00145060;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_SetDead_1_001450D0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b7_1_001450E0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetType_1_00145140;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Set5B0b1_1_00145180;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_AddHp_2_00145190;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_Get5B0b0_1_001451A0;
typedef struct { char pad[0x610]; s8 x610; s8 x611; s8 x612; s8 x613; s32 x614; } P_EnemyCmd_AddPartValue_0_001451E0;
typedef struct { char pad[0x154]; P_EnemyCmd_AddPartValue_0_001451E0 *p; } S_EnemyCmd_AddPartValue_0_001451E0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_GetHpPercent_2_00145250;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_SetMode_1_00145290;
typedef struct { f32 a; f32 b; } P_EnemyCmd_PlaySe_1_001453A0;
typedef struct { char p[0x154]; s32 x154; } S_EnemyCmd_PlaySe_1_001453A0;
typedef struct { char p[8]; u16 x8; char p2[6]; u8 x10; } A_EnemyCmd_Nop_1_00143890;
typedef struct { u32 w; u32 pad; } W;
typedef struct { W x0; W x8; W x10; W x18; } Arg_EnemyCmd_SpawnItem_0_001454E0;
typedef struct { u8 b[12]; f32 v; } T_EnemyCmd_ShakeCamera_0_001455B0;
typedef struct { char pad[8]; f32 f; } Obj_EnemyCmd_ShakeCamera_0_001455B0;
typedef struct { char pad[0x154]; void *p; } S_EnemyCmd_ResetVectors_1_00145610;
extern void *gEnemyScriptSbss_00201FA8;
extern s32 gMapSbss_00201E80;
#ifndef NONMATCHING
extern s32 gStrScrChrtestBin_001FAD20[];
extern s32 gStrScrChr0021Bin_001FAD40[];
extern s32 gStrScrChr0022Bin_001FAD60[];
extern s32 gStrScrChr0023Bin_001FAD80[];
extern s32 gStrScrChr0024Bin_001FADA0[];
extern s32 gStrScrChr0025Bin_001FADC0[];
extern s32 gStrScrChr0026Bin_001FADE0[];
extern s32 gStrScrChr0027Bin_001FAE00[];
extern s32 gStrScrChr0028Bin_001FAE20[];
extern s32 gStrScrChr0029Bin_001FAE40[];
extern s32 gStrScrChr0030Bin_001FAE60[];
extern s32 gStrScrChr0031Bin_001FAE80[];
extern s32 gStrScrChr0032Bin_001FAEA0[];
extern s32 gStrScrChr0033Bin_001FAEC0[];
extern s32 gStrScrChr0034Bin_001FAEE0[];
extern s32 gStrScrChr0035Bin_001FAF00[];
extern s32 gStrScrChr0036Bin_001FAF20[];
extern s32 gStrScrChr0037Bin_001FAF40[];
extern s32 gStrScrChr0038Bin_001FAF60[];
extern s32 gStrScrChr0039Bin_001FAF80[];
extern s32 gStrScrChr0040Bin_001FAFA0[];
extern s32 gStrScrChr0041Bin_001FAFC0[];
extern s32 gStrScrChr0042Bin_001FAFE0[];
extern s32 gStrScrChr0043Bin_001FB000[];
extern s32 gStrScrChr0044Bin_001FB020[];
extern s32 gStrScrChr0045Bin_001FB040[];
extern s32 gStrScrChr0046Bin_001FB060[];
extern s32 gStrScrChr0047Bin_001FB080[];
extern s32 gStrScrChr0048Bin_001FB0A0[];
extern s32 gStrScrChr0049Bin_001FB0C0[];
extern s32 gStrScrChr0050Bin_001FB0E0[];
extern s32 gStrScrChr0051Bin_001FB100[];
extern s32 gStrScrChr0052Bin_001FB120[];
extern s32 gStrScrChr0053Bin_001FB140[];
extern s32 gStrScrChr0054Bin_001FB160[];
extern s32 gStrScrChr0055Bin_001FB180[];
extern s32 gStrScrChr0056Bin_001FB1A0[];
extern s32 gStrScrChr0057Bin_001FB1C0[];
extern s32 gStrScrChr0058Bin_001FB1E0[];
extern s32 gStrScrChr0059Bin_001FB200[];
extern s32 gStrScrChr0060Bin_001FB220[];
extern s32 gStrScrChr0061Bin_001FB240[];
extern s32 gStrScrChr0062Bin_001FB260[];
extern s32 gStrScrChr0063Bin_001FB280[];
extern s32 gStrScrChr0064Bin_001FB2A0[];
extern s32 gStrScrChr0065Bin_001FB2C0[];
extern s32 gStrScrChr0066Bin_001FB2E0[];
extern s32 gStrScrChr0067Bin_001FB300[];
extern s32 gStrScrChr0068Bin_001FB320[];
extern s32 gStrScrChr0069Bin_001FB340[];
extern s32 gStrScrChr0070Bin_001FB360[];
extern s32 gStrScrChr0071Bin_001FB380[];
extern s32 gStrScrChr0072Bin_001FB3A0[];
extern s32 gStrScrChr0073Bin_001FB3C0[];
extern s32 gStrScrChr0081Bin_001FB3E0[];
extern s32 gStrScrChr0082Bin_001FB400[];
extern s32 gStrScrChr0083Bin_001FB420[];
extern s32 gStrScrChr0091Bin_001FB440[];
extern s32 gStrScrChr0092Bin_001FB460[];
extern s32 gStrScrChr0094Bin_001FB480[];
extern s32 gStrScrChr0095Bin_001FB4A0[];
extern s32 gStrScrChr0098Bin_001FB4C0[];
extern s32 gStrScrChr0101Bin_001FB4E0[];
extern s32 gStrScrChr0102Bin_001FB500[];
extern s32 gStrScrChr0103Bin_001FB520[];
extern s32 gStrScrChr0104Bin_001FB540[];
extern s32 gStrScrChr0105Bin_001FB560[];
extern s32 gStrScrChr0107Bin_001FB580[];
extern s32 gStrScrChr0108Bin_001FB5A0[];
extern s32 gStrScrChr0109Bin_001FB5C0[];
extern s32 gStrScrChr0110Bin_001FB5E0[];
extern s32 gStrScrChr0118Bin_001FB600[];
extern s32 gStrScrChr0119Bin_001FB620[];
extern s32 gStrScrChr0120Bin_001FB640[];
extern s32 gStrScrChr0122Bin_001FB660[];
extern s32 gStrScrChr0123Bin_001FB680[];
extern s32 gStrScrChr0124Bin_001FB6A0[];
extern s32 gStrScrChr0125Bin_001FB6C0[];
extern s32 gStrScrChr0126Bin_001FB6E0[];
extern s32 gStrScrChr0127Bin_001FB700[];
extern s32 gEnemyScriptRodata_001FB720[];
extern P_EnemyCmd_PlaySe_1_001453A0 gEnemyScriptSdata_00201C50;
#else
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChrtestBin_001FAD20 */
static s32 gStrScrChrtestBin_001FAD20[0x8] = { 0x2f726373, 0x74726863, 0x5f747365, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0021Bin_001FAD40 */
static s32 gStrScrChr0021Bin_001FAD40[0x8] = { 0x2f726373, 0x30726863, 0x5f313230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0022Bin_001FAD60 */
static s32 gStrScrChr0022Bin_001FAD60[0x8] = { 0x2f726373, 0x30726863, 0x5f323230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0023Bin_001FAD80 */
static s32 gStrScrChr0023Bin_001FAD80[0x8] = { 0x2f726373, 0x30726863, 0x5f333230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0024Bin_001FADA0 */
static s32 gStrScrChr0024Bin_001FADA0[0x8] = { 0x2f726373, 0x30726863, 0x5f343230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0025Bin_001FADC0 */
static s32 gStrScrChr0025Bin_001FADC0[0x8] = { 0x2f726373, 0x30726863, 0x5f353230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0026Bin_001FADE0 */
static s32 gStrScrChr0026Bin_001FADE0[0x8] = { 0x2f726373, 0x30726863, 0x5f363230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0027Bin_001FAE00 */
static s32 gStrScrChr0027Bin_001FAE00[0x8] = { 0x2f726373, 0x30726863, 0x5f373230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0028Bin_001FAE20 */
static s32 gStrScrChr0028Bin_001FAE20[0x8] = { 0x2f726373, 0x30726863, 0x5f383230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0029Bin_001FAE40 */
static s32 gStrScrChr0029Bin_001FAE40[0x8] = { 0x2f726373, 0x30726863, 0x5f393230, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0030Bin_001FAE60 */
static s32 gStrScrChr0030Bin_001FAE60[0x8] = { 0x2f726373, 0x30726863, 0x5f303330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0031Bin_001FAE80 */
static s32 gStrScrChr0031Bin_001FAE80[0x8] = { 0x2f726373, 0x30726863, 0x5f313330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0032Bin_001FAEA0 */
static s32 gStrScrChr0032Bin_001FAEA0[0x8] = { 0x2f726373, 0x30726863, 0x5f323330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0033Bin_001FAEC0 */
static s32 gStrScrChr0033Bin_001FAEC0[0x8] = { 0x2f726373, 0x30726863, 0x5f333330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0034Bin_001FAEE0 */
static s32 gStrScrChr0034Bin_001FAEE0[0x8] = { 0x2f726373, 0x30726863, 0x5f343330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0035Bin_001FAF00 */
static s32 gStrScrChr0035Bin_001FAF00[0x8] = { 0x2f726373, 0x30726863, 0x5f353330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0036Bin_001FAF20 */
static s32 gStrScrChr0036Bin_001FAF20[0x8] = { 0x2f726373, 0x30726863, 0x5f363330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0037Bin_001FAF40 */
static s32 gStrScrChr0037Bin_001FAF40[0x8] = { 0x2f726373, 0x30726863, 0x5f373330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0038Bin_001FAF60 */
static s32 gStrScrChr0038Bin_001FAF60[0x8] = { 0x2f726373, 0x30726863, 0x5f383330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0039Bin_001FAF80 */
static s32 gStrScrChr0039Bin_001FAF80[0x8] = { 0x2f726373, 0x30726863, 0x5f393330, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0040Bin_001FAFA0 */
static s32 gStrScrChr0040Bin_001FAFA0[0x8] = { 0x2f726373, 0x30726863, 0x5f303430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0041Bin_001FAFC0 */
static s32 gStrScrChr0041Bin_001FAFC0[0x8] = { 0x2f726373, 0x30726863, 0x5f313430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0042Bin_001FAFE0 */
static s32 gStrScrChr0042Bin_001FAFE0[0x8] = { 0x2f726373, 0x30726863, 0x5f323430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0043Bin_001FB000 */
static s32 gStrScrChr0043Bin_001FB000[0x8] = { 0x2f726373, 0x30726863, 0x5f333430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0044Bin_001FB020 */
static s32 gStrScrChr0044Bin_001FB020[0x8] = { 0x2f726373, 0x30726863, 0x5f343430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0045Bin_001FB040 */
static s32 gStrScrChr0045Bin_001FB040[0x8] = { 0x2f726373, 0x30726863, 0x5f353430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0046Bin_001FB060 */
static s32 gStrScrChr0046Bin_001FB060[0x8] = { 0x2f726373, 0x30726863, 0x5f363430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0047Bin_001FB080 */
static s32 gStrScrChr0047Bin_001FB080[0x8] = { 0x2f726373, 0x30726863, 0x5f373430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0048Bin_001FB0A0 */
static s32 gStrScrChr0048Bin_001FB0A0[0x8] = { 0x2f726373, 0x30726863, 0x5f383430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0049Bin_001FB0C0 */
static s32 gStrScrChr0049Bin_001FB0C0[0x8] = { 0x2f726373, 0x30726863, 0x5f393430, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0050Bin_001FB0E0 */
static s32 gStrScrChr0050Bin_001FB0E0[0x8] = { 0x2f726373, 0x30726863, 0x5f303530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0051Bin_001FB100 */
static s32 gStrScrChr0051Bin_001FB100[0x8] = { 0x2f726373, 0x30726863, 0x5f313530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0052Bin_001FB120 */
static s32 gStrScrChr0052Bin_001FB120[0x8] = { 0x2f726373, 0x30726863, 0x5f323530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0053Bin_001FB140 */
static s32 gStrScrChr0053Bin_001FB140[0x8] = { 0x2f726373, 0x30726863, 0x5f333530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0054Bin_001FB160 */
static s32 gStrScrChr0054Bin_001FB160[0x8] = { 0x2f726373, 0x30726863, 0x5f343530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0055Bin_001FB180 */
static s32 gStrScrChr0055Bin_001FB180[0x8] = { 0x2f726373, 0x30726863, 0x5f353530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0056Bin_001FB1A0 */
static s32 gStrScrChr0056Bin_001FB1A0[0x8] = { 0x2f726373, 0x30726863, 0x5f363530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0057Bin_001FB1C0 */
static s32 gStrScrChr0057Bin_001FB1C0[0x8] = { 0x2f726373, 0x30726863, 0x5f373530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0058Bin_001FB1E0 */
static s32 gStrScrChr0058Bin_001FB1E0[0x8] = { 0x2f726373, 0x30726863, 0x5f383530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0059Bin_001FB200 */
static s32 gStrScrChr0059Bin_001FB200[0x8] = { 0x2f726373, 0x30726863, 0x5f393530, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0060Bin_001FB220 */
static s32 gStrScrChr0060Bin_001FB220[0x8] = { 0x2f726373, 0x30726863, 0x5f303630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0061Bin_001FB240 */
static s32 gStrScrChr0061Bin_001FB240[0x8] = { 0x2f726373, 0x30726863, 0x5f313630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0062Bin_001FB260 */
static s32 gStrScrChr0062Bin_001FB260[0x8] = { 0x2f726373, 0x30726863, 0x5f323630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0063Bin_001FB280 */
static s32 gStrScrChr0063Bin_001FB280[0x8] = { 0x2f726373, 0x30726863, 0x5f333630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0064Bin_001FB2A0 */
static s32 gStrScrChr0064Bin_001FB2A0[0x8] = { 0x2f726373, 0x30726863, 0x5f343630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0065Bin_001FB2C0 */
static s32 gStrScrChr0065Bin_001FB2C0[0x8] = { 0x2f726373, 0x30726863, 0x5f353630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0066Bin_001FB2E0 */
static s32 gStrScrChr0066Bin_001FB2E0[0x8] = { 0x2f726373, 0x30726863, 0x5f363630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0067Bin_001FB300 */
static s32 gStrScrChr0067Bin_001FB300[0x8] = { 0x2f726373, 0x30726863, 0x5f373630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0068Bin_001FB320 */
static s32 gStrScrChr0068Bin_001FB320[0x8] = { 0x2f726373, 0x30726863, 0x5f383630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0069Bin_001FB340 */
static s32 gStrScrChr0069Bin_001FB340[0x8] = { 0x2f726373, 0x30726863, 0x5f393630, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0070Bin_001FB360 */
static s32 gStrScrChr0070Bin_001FB360[0x8] = { 0x2f726373, 0x30726863, 0x5f303730, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0071Bin_001FB380 */
static s32 gStrScrChr0071Bin_001FB380[0x8] = { 0x2f726373, 0x30726863, 0x5f313730, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0072Bin_001FB3A0 */
static s32 gStrScrChr0072Bin_001FB3A0[0x8] = { 0x2f726373, 0x30726863, 0x5f323730, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0073Bin_001FB3C0 */
static s32 gStrScrChr0073Bin_001FB3C0[0x8] = { 0x2f726373, 0x30726863, 0x5f333730, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0081Bin_001FB3E0 */
static s32 gStrScrChr0081Bin_001FB3E0[0x8] = { 0x2f726373, 0x30726863, 0x5f313830, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0082Bin_001FB400 */
static s32 gStrScrChr0082Bin_001FB400[0x8] = { 0x2f726373, 0x30726863, 0x5f323830, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0083Bin_001FB420 */
static s32 gStrScrChr0083Bin_001FB420[0x8] = { 0x2f726373, 0x30726863, 0x5f333830, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0091Bin_001FB440 */
static s32 gStrScrChr0091Bin_001FB440[0x8] = { 0x2f726373, 0x30726863, 0x5f313930, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0092Bin_001FB460 */
static s32 gStrScrChr0092Bin_001FB460[0x8] = { 0x2f726373, 0x30726863, 0x5f323930, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0094Bin_001FB480 */
static s32 gStrScrChr0094Bin_001FB480[0x8] = { 0x2f726373, 0x30726863, 0x5f343930, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0095Bin_001FB4A0 */
static s32 gStrScrChr0095Bin_001FB4A0[0x8] = { 0x2f726373, 0x30726863, 0x5f353930, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0098Bin_001FB4C0 */
static s32 gStrScrChr0098Bin_001FB4C0[0x8] = { 0x2f726373, 0x30726863, 0x5f383930, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0101Bin_001FB4E0 */
static s32 gStrScrChr0101Bin_001FB4E0[0x8] = { 0x2f726373, 0x30726863, 0x5f313031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0102Bin_001FB500 */
static s32 gStrScrChr0102Bin_001FB500[0x8] = { 0x2f726373, 0x30726863, 0x5f323031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0103Bin_001FB520 */
static s32 gStrScrChr0103Bin_001FB520[0x8] = { 0x2f726373, 0x30726863, 0x5f333031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0104Bin_001FB540 */
static s32 gStrScrChr0104Bin_001FB540[0x8] = { 0x2f726373, 0x30726863, 0x5f343031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0105Bin_001FB560 */
static s32 gStrScrChr0105Bin_001FB560[0x8] = { 0x2f726373, 0x30726863, 0x5f353031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0107Bin_001FB580 */
static s32 gStrScrChr0107Bin_001FB580[0x8] = { 0x2f726373, 0x30726863, 0x5f373031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0108Bin_001FB5A0 */
static s32 gStrScrChr0108Bin_001FB5A0[0x8] = { 0x2f726373, 0x30726863, 0x5f383031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0109Bin_001FB5C0 */
static s32 gStrScrChr0109Bin_001FB5C0[0x8] = { 0x2f726373, 0x30726863, 0x5f393031, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0110Bin_001FB5E0 */
static s32 gStrScrChr0110Bin_001FB5E0[0x8] = { 0x2f726373, 0x30726863, 0x5f303131, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0118Bin_001FB600 */
static s32 gStrScrChr0118Bin_001FB600[0x8] = { 0x2f726373, 0x30726863, 0x5f383131, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0119Bin_001FB620 */
static s32 gStrScrChr0119Bin_001FB620[0x8] = { 0x2f726373, 0x30726863, 0x5f393131, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0120Bin_001FB640 */
static s32 gStrScrChr0120Bin_001FB640[0x8] = { 0x2f726373, 0x30726863, 0x5f303231, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0122Bin_001FB660 */
static s32 gStrScrChr0122Bin_001FB660[0x8] = { 0x2f726373, 0x30726863, 0x5f323231, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0123Bin_001FB680 */
static s32 gStrScrChr0123Bin_001FB680[0x8] = { 0x2f726373, 0x30726863, 0x5f333231, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0124Bin_001FB6A0 */
static s32 gStrScrChr0124Bin_001FB6A0[0x8] = { 0x2f726373, 0x30726863, 0x5f343231, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0125Bin_001FB6C0 */
static s32 gStrScrChr0125Bin_001FB6C0[0x8] = { 0x2f726373, 0x30726863, 0x5f353231, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0126Bin_001FB6E0 */
static s32 gStrScrChr0126Bin_001FB6E0[0x8] = { 0x2f726373, 0x30726863, 0x5f363231, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gStrScrChr0127Bin_001FB700 */
static s32 gStrScrChr0127Bin_001FB700[0x8] = { 0x2f726373, 0x30726863, 0x5f373231, 0x6e69622e, 0, 0, 0, 0 };
/* data twins (src/game/data/fx_proc_rodata.c): gEnemyScriptRodata_001FB720 */
static s32 gEnemyScriptRodata_001FB720[0x6] = { 0x2f726373, 0x30726863, 0x5f303032, 0x6e69622e, 0, 0 };
/* data twins (src/game/data/sdata.c): gEnemyScriptSdata_00201C50 */
static P_EnemyCmd_PlaySe_1_001453A0 gEnemyScriptSdata_00201C50 = { 5000.0f, 0.0f };
#endif
extern S_EnemyCmd_Set5B4b6_1_00143920 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B4b6_1_00143920;
extern S_EnemyCmd_Set5B4b5_1_00143930 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B4b5_1_00143930;
extern s8 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetRelativePos_0_00143960;
extern S_EnemyCmd_Get608_1_00143B20 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Get608_1_00143B20;
extern S_EnemyCmd_Set5A1b5_1_00143BB0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5A1b5_1_00143BB0;
extern S_EnemyCmd_Set5B4b4_1_00143BC0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B4b4_1_00143BC0;
extern S_EnemyCmd_StartTimer_0_00143BD0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_StartTimer_0_00143BD0;
extern S_EnemyCmd_GetMotionFrame_1_00143C30 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetMotionFrame_1_00143C30;
extern S_EnemyCmd_ResolveHit_0_00143C70 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_ResolveHit_0_00143C70;
extern S_EnemyCmd_GetVec660_0_00143D60 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetVec660_0_00143D60;
extern S_EnemyCmd_UpdatePartStat_1_00143DF0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_UpdatePartStat_1_00143DF0;
extern S_EnemyCmd_InitPart_1_00143E10 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_InitPart_1_00143E10;
extern s8 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetTargetPos_0_001441B0;
extern S_EnemyCmd_BroadcastMotion_1_001442F0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_BroadcastMotion_1_001442F0;
extern S_EnemyCmd_Kill_1_00144360 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Kill_1_00144360;
extern S_EnemyCmd_SetHiddenFlags_0_00144370 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_SetHiddenFlags_0_00144370;
extern S_EnemyCmd_Set5B2b6w2_1_001443E0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b6w2_1_001443E0;
extern S_EnemyCmd_Set5B2b2_1_001443F0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b2_1_001443F0;
extern S_EnemyCmd_Set5B2b1_1_00144400 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b1_1_00144400;
extern S_EnemyCmd_Set5B0b2_1_00144410 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b2_1_00144410;
extern S_EnemyCmd_ClampHpFromFlag_1_00144420 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_ClampHpFromFlag_1_00144420;
extern S_EnemyCmd_StoreHpToFlag_1_00144490 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_StoreHpToFlag_1_00144490;
extern s8 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_FindSpawnPoint_0_001444F0;
extern S_EnemyCmd_GetPosition_2_00144970 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetPosition_2_00144970;
extern s8 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_SpawnEffect_0_00144A00;
extern char *gEnemyScriptSbss_00201FA8__as_EnemyCmd_SpawnEffectB_0_00144BE0;
extern S_EnemyCmd_Set5B2b0_1_00144D70 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b0_1_00144D70;
extern S_EnemyCmd_BroadcastFrame_1_00144D80 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_BroadcastFrame_1_00144D80;
extern S_EnemyCmd_Set5B1b7_1_00144DF0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b7_1_00144DF0;
extern S_EnemyCmd_Set5B1b6_1_00144E00 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b6_1_00144E00;
extern S_EnemyCmd_BreakPart_1_00144E10 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_BreakPart_1_00144E10;
extern S_EnemyCmd_Set5B0b0_1_00144E30 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b0_1_00144E30;
extern S_EnemyCmd_HealPercent_1_00144E40 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_HealPercent_1_00144E40;
extern Ctx *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b2Notify_0_00144F00;
extern S_EnemyCmd_GetParamIdx_1_00144F60 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetParamIdx_1_00144F60;
extern S_EnemyCmd_Set5B1b1_1_00144FA0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b1_1_00144FA0;
extern S_EnemyCmd_UpdateParamFlags_1_00144FB0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_UpdateParamFlags_1_00144FB0;
extern S_EnemyCmd_RegisterKill_0_00144FC0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_RegisterKill_0_00144FC0;
extern S_EnemyCmd_RegisterSeen_0_00145010 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_RegisterSeen_0_00145010;
extern S_EnemyCmd_Set5B1b0_1_00145060 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b0_1_00145060;
extern S_EnemyCmd_SetDead_1_001450D0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_SetDead_1_001450D0;
extern S_EnemyCmd_Set5B0b7_1_001450E0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b7_1_001450E0;
extern S_EnemyCmd_GetType_1_00145140 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetType_1_00145140;
extern S_EnemyCmd_Set5B0b1_1_00145180 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b1_1_00145180;
extern S_EnemyCmd_AddHp_2_00145190 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_AddHp_2_00145190;
extern S_EnemyCmd_Get5B0b0_1_001451A0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_Get5B0b0_1_001451A0;
extern S_EnemyCmd_AddPartValue_0_001451E0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_AddPartValue_0_001451E0;
extern S_EnemyCmd_GetHpPercent_2_00145250 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetHpPercent_2_00145250;
extern S_EnemyCmd_SetMode_1_00145290 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_SetMode_1_00145290;
extern S_EnemyCmd_PlaySe_1_001453A0 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_PlaySe_1_001453A0;
extern s8 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetModelPos_0_00145410;
extern S_EnemyCmd_ResetVectors_1_00145610 *gEnemyScriptSbss_00201FA8__as_EnemyCmd_ResetVectors_1_00145610;
void Enemy_GetScreenSize_0_0013FEB0(O_Enemy_GetScreenSize_0_0013FEB0 *o, f32 *a1, f32 *a2);
s32 Enemy_Ptr700_1_0013FF90(s32 arg0);
s32 Enemy_Ptr6F0_1_0013FFA0(s32 arg0);
s32 Enemy_Ptr6E0_1_0013FFB0(s32 arg0);
f32 Enemy_GetAngleToPlayer_1_0013FFC0(s8 *a0);
f32 Enemy_GetYawToPlayer_1_00140160(Actor *a);
f32 Enemy_GetDistSqToPlayer_1_001402A0(Obj_Enemy_GetDistSqToPlayer_1_001402A0 *o);
void Enemy_CopyVec690_1_00140300(u8 *obj, f32 *v);
void Enemy_CopyVec680_1_00140310(u8 *obj, f32 *v);
s32 Enemy_PtrVec670_1_00140320(s32 arg0);
void Enemy_CopyVec670_1_00140330(u8 *obj, f32 *v);
s32 Enemy_PtrVec660_1_00140340(s32 arg0);
void Enemy_CopyVec660_1_00140350(u8 *obj, f32 *v);
void Enemy_GetRightVector_1_00140360(Obj_Enemy_GetRightVector_1_00140360 *o, f32 *v);
void Enemy_GetForwardVector_2_001403D0(void *arg0, void *arg1);
s32 Enemy_GetRotationPtr_1_00140430(void *arg0);
void Enemy_CopyRotation_2_00140440(void *arg0, s32 arg1);
s32 Enemy_GetPositionPtr_2_00140460(void *arg0);
void Enemy_CopyPosition_2_00140470(void *arg0, s32 arg1);
u8 EnemyScr_Event2026_1_00140480(Obj_EnemyScr_Event2026_1_00140480 *a0, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3);
void EnemyScr_Event2025_1_00140770(Obj_EnemyScr_Event2025_1_00140770 *a0, s8 *a1, u32 a2, u32 a3, u32 a4);
u16 EnemyScr_Event2024GetMove_1_001409A0(Obj_EnemyScr_Event2024GetMove_1_001409A0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz);
void EnemyScr_Event2023_1_00140CB0(Obj_EnemyScr_Event2023_1_00140CB0 *a0, u8 *pa, f32 *pb, f32 *pc);
void EnemyScr_Event2022_1_00140DE0(Obj_EnemyScr_Event2022_1_00140DE0 *o);
u8 EnemyScr_Event2021_1_00140E50(Obj_EnemyScr_Event2021_1_00140E50 *o);
u8 EnemyScr_Event2020_1_00140EF0(Obj_EnemyScr_Event2020_1_00140EF0 *o);
void EnemyScr_BroadcastMotionEvent_0_00140F90(u8 a, u8 b, u32 c, u32 d);
void EnemyScr_BroadcastFrameEvent_0_001410C0(u8 a0, u8 a1, u32 a2, u32 a3);
void EnemyScr_Event2018_1_001411F0(Obj_EnemyScr_Event2018_1_001411F0 *o);
void EnemyScr_Event2017OnDeath_1_00141260(Obj_EnemyScr_Event2017OnDeath_1_00141260 *o, s32 d);
u8 EnemyScr_Event2016_1_001412E0(Obj_EnemyScr_Event2016_1_001412E0 *o);
u8 EnemyScr_Event2015_1_00141510(Obj_EnemyScr_Event2015_1_00141510 *a0, u32 a1, u32 a2, u32 a3);
u8 EnemyScr_Event2014_1_00141610(Obj_EnemyScr_Event2014_1_00141610 *o);
u16 EnemyScr_Event2013GetMove_1_001416B0(Obj_EnemyScr_Event2013GetMove_1_001416B0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz);
void EnemyScr_Event2012_1_001419C0(Obj_EnemyScr_Event2012_1_001419C0 *a0, f32 f);
void EnemyScr_Event2011GetWeights_1_00141A50(Obj_EnemyScr_Event2011GetWeights_1_00141A50 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *p4);
void EnemyScr_Event2010_1_00141DA0(Obj_EnemyScr_Event2010_1_00141DA0 *o);
void EnemyScr_Event200F_1_00141E10(A_Enemy_GetScreenSize_0_0013FEB0 *a, s32 a1, f32 x, f32 y, f32 z, f32 w);
void EnemyScr_Event200E_1_00142010(Obj_EnemyScr_Event200E_1_00142010 *o, s32 d);
void EnemyScr_Event200DGetStats_1_00142090(Obj_EnemyScr_Event200DGetStats_1_00142090 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3);
void EnemyScr_Event200COnHit_1_00142320(Obj_EnemyScr_Event200COnHit_1_00142320 *a0, s32 a1, s32 a2);
void EnemyScr_Event200B_1_001423E0(Obj_EnemyScr_Event200B_1_001423E0 *o, s32 d);
u8 EnemyScr_Event2009Move_1_00142470(Obj_EnemyScr_Event2009Move_1_00142470 *a0, s32 a1);
u8 EnemyScr_Event2005Turn_1_00142530(Obj_EnemyScr_Event2005Turn_1_00142530 *a0, s32 a1);
u8 EnemyScr_Event2004Attack_1_001425F0(Obj_EnemyScr_Event2004Attack_1_001425F0 *a0, s32 a1, s32 a2);
u8 EnemyScr_Event2003React_1_001426C0(Obj_EnemyScr_Event2003React_1_001426C0 *a0, s32 a1);
u8 EnemyScr_Event2002_1_00142780(Obj_EnemyScr_Event2002_1_00142780 *o);
u8 EnemyScr_Event2001_1_00142820(Obj_EnemyScr_Event2001_1_00142820 *o, s32 d);
void EnemyScr_EventInit_1_001428C0(Obj_EnemyScr_EventInit_1_001428C0 *o);
void EnemyScr_GetScriptPath_3_00142930(s32 arg0, void *arg1);
void Enemy_PickWaypointToward_1_00143150(void *a, f32 *b, f32 *c);
u8 Enemy_PickRandomWaypoint_1_001431A0(T *arg0);
void Enemy_PickWaypointDir_1_00143290(void *a, f32 *b, f32 *c, s32 d, s32 e);
u8 Enemy_FindWaypointDir_0_001432F0(Obj *o, Vec *pos, u8 a, u8 b);
u8 Enemy_IsWaypointReachable_0_001434F0(Big *b, Vec *p1, Vec *p2, u8 idx);
void Enemy_PickNearestWaypointToward_1_001435D0(void *a, f32 *b, f32 *c);
u8 Enemy_FindNearestWaypoint_1_00143610(Obj *o, Vec *pos);
u8 Waypoint_GetLink_0_00143810(s32 arg0, s32 arg1, s32 arg2);
s32 Waypoint_Get_0_00143840(s32 arg0, s32 arg1);
void EnemyCmd_GetFlag_0_001438B0(Obj_EnemyCmd_GetFlag_0_001438B0 *o);
void EnemyCmd_GetGlobal_0_001438F0(s32 a);
void EnemyCmd_Set5B4b6_1_00143920(u8 *arg0);
void EnemyCmd_Set5B4b5_1_00143930(u8 *arg0);
void EnemyCmd_Set5B8_1_00143940(void *arg0);
void EnemyCmd_Set60B_1_00143950(void *arg0);
void EnemyCmd_GetRelativePos_0_00143960(Arg_EnemyCmd_GetRelativePos_0_00143960 *arg0);
void EnemyCmd_Get608_1_00143B20(s32 a);
void EnemyCmd_GetPlayerValue_0_00143B60(s32 a);
void EnemyCmd_SelectMotion_1_00143B90(void *arg0);
void EnemyCmd_Set5A1b5_1_00143BB0(u8 *arg0);
void EnemyCmd_Set5B4b4_1_00143BC0(u8 *arg0);
void EnemyCmd_StartTimer_0_00143BD0(Obj_EnemyCmd_StartTimer_0_00143BD0 *o);
void EnemyCmd_GetMotionFrame_1_00143C30(s32 a);
void EnemyCmd_ResolveHit_0_00143C70(u8 *o);
void EnemyCmd_SetPartValue_1_00143D10(void *arg0);
void EnemyCmd_GetVec660_0_00143D60(void *o);
void EnemyCmd_UpdatePartStat_1_00143DF0(u8 *arg0);
void EnemyCmd_LoadPart_1_00143E00(void *arg0);
void EnemyCmd_InitPart_1_00143E10(u8 *arg0);
void EnemyCmd_FindTargetInCone_0_00143E20(s8 *a0, s32 a1, u8 a2, s32 a3, s32 t0, s32 t1, f32 ang);
void EnemyCmd_GetTargetPos_0_001441B0(s8 *arg0);
void EnemyCmd_BroadcastMotion_1_001442F0(u8 *o);
void EnemyCmd_Kill_1_00144360(u8 *arg0);
void EnemyCmd_SetHiddenFlags_0_00144370(u8 *o);
void EnemyCmd_Set5B2b6w2_1_001443E0(u8 *arg0);
void EnemyCmd_Set5B2b2_1_001443F0(u8 *arg0);
void EnemyCmd_Set5B2b1_1_00144400(u8 *arg0);
void EnemyCmd_Set5B0b2_1_00144410(u8 *arg0);
void EnemyCmd_ClampHpFromFlag_1_00144420(u8 *o);
void EnemyCmd_StoreHpToFlag_1_00144490(u8 *o);
void EnemyCmd_FindSpawnPoint_0_001444F0(Msg *m);
void EnemyCmd_GetPosition_2_00144970(void *o);
void EnemyCmd_SpawnEffect_0_00144A00(s8 *a0);
void EnemyCmd_StopEffect_0_00144B80(u16 *a0);
void EnemyCmd_SpawnEffectB_0_00144BE0(Arg_EnemyCmd_SpawnEffectB_0_00144BE0 *a0);
void EnemyCmd_Set5B2b0_1_00144D70(u8 *arg0);
void EnemyCmd_BroadcastFrame_1_00144D80(u8 *o);
void EnemyCmd_Set5B1b7_1_00144DF0(u8 *arg0);
void EnemyCmd_Set5B1b6_1_00144E00(u8 *arg0);
void EnemyCmd_BreakPart_1_00144E10(u8 *arg0);
void EnemyCmd_Set5B0b0_1_00144E30(u8 *arg0);
void EnemyCmd_HealPercent_1_00144E40(u8 *o);
void EnemyCmd_Set5B1b2Notify_0_00144F00(unsigned char *a);
void EnemyCmd_GetParamIdx_1_00144F60(s32 a);
void EnemyCmd_Set5B1b1_1_00144FA0(u8 *arg0);
void EnemyCmd_UpdateParamFlags_1_00144FB0(u8 *arg0);
void EnemyCmd_Set5B1b0_1_00145060(u8 *arg0);
void EnemyCmd_SetGameFlag_2_00145070(u8 *arg0);
void EnemyCmd_TestGameFlag_2_00145080(u8 *o);
void EnemyCmd_SetDead_1_001450D0(u8 *arg0);
void EnemyCmd_Set5B0b7_1_001450E0(u8 *arg0);
void EnemyCmd_Random_2_00145100(u8 *a);
void EnemyCmd_GetType_1_00145140(s32 a);
void EnemyCmd_Set5B0b1_1_00145180(u8 *arg0);
void EnemyCmd_AddHp_2_00145190(u8 *arg0);
void EnemyCmd_Get5B0b0_1_001451A0(s32 a);
void EnemyCmd_AddPartValue_0_001451E0(u8 *arg0);
void EnemyCmd_GetHpPercent_2_00145250(s32 a);
void EnemyCmd_SetMode_1_00145290(u8 *arg0);
void EnemyCmd_SelectMotionB_1_001452A0(void *arg0);
void EnemyCmd_Set609_1_001452C0(void *arg0);
void EnemyCmd_SetMapObjFlag_0_001452E0(u8 *o);
void EnemyCmd_PlaySe_1_001453A0(A_EnemyCmd_Nop_1_00143890 *a);
void EnemyCmd_GetModelPos_0_00145410(s32 a0);
void EnemyCmd_SpawnItem_0_001454E0(Arg_EnemyCmd_SpawnItem_0_001454E0 *a);
void EnemyCmd_ShakeCamera_0_001455B0(Obj_EnemyCmd_ShakeCamera_0_001455B0 *o);
void EnemyCmd_ResetVectors_1_00145610(u8 *arg0);
Vec* Player_GetRotationPtr_1_00145710(void);
void Player_CopyPosition_1_00145760(void *);
void sceVu0SubVector(void *, void*, void*);
f32 atan2f(f32, f32);
f32 sceVu0InnerProduct(void *, void *);
f32 sqrtf(f32 x);
void sceVu0CopyVector(void *, void *);
f32 cosf(f32 x);
f32 sinf(f32 x);
void Player_CopyPosition_1_00145760__as_Enemy_GetAngleToPlayer_1_0013FFC0(Vec *);
void sceVu0SubVector__as_Enemy_GetAngleToPlayer_1_0013FFC0(Vec *, Vec *, Vec *);
void Player_CopyPosition_1_00145760__as_Enemy_GetYawToPlayer_1_00140160(Vec *);
void sceVu0SubVector__as_Enemy_GetYawToPlayer_1_00140160(Vec *, Vec *, s8 *);
void Player_CopyPosition_1_00145760__as_Enemy_GetDistSqToPlayer_1_001402A0(f32 *v);
void sceVu0SubVector__as_Enemy_GetDistSqToPlayer_1_001402A0(f32 *v0, f32 *v1, f32 *v2);
void sceVu0CopyVector__as_Enemy_CopyRotation_2_00140440(s32, s32);
void sceVu0CopyVector__as_Enemy_CopyPosition_2_00140470(s32, s32);
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
void Script_SetArgU16_1_001650F0(void *, u8, s32, u32);
s8 Script_RunEvent_2_00166C10(void *, s32);
s32 Script_GetResultU8_1_00164FC0(void *, u8, s32);
void Script_SetArgS8_1_00165030(void *, u8, s32, s32);
s8 Script_GetResultS8_1_00164F90(void *, u8, s32);
void Script_SetArgF32_1_00164FF0(void *, u8, s32, f32);
f32 Script_GetResultF32_1_00164F60(void *, u8, s32);
s8* ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(void *);
s32 Enemy_GetTargetHandle_0_0013EDE0(void *);
s32 Enemy_GetMotionId_0_0013ED20(void *);
s32 Enemy_GetMotionFrame_0_0013ECA0(Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *);
s32 Ent_GetTypeByte_1_0013E220(void *);
s32 Enemy_IsDead_1_0013EEE0(Obj_EnemyScr_BroadcastQuery_0_00141380 *);
u32 Enemy_Get5B5mF_1_0013E5E0(void *);
f32 Enemy_GetParam298_1_0013DD40(Obj_EnemyScr_Event200COnHit_1_00142320 *);
void Enemy_Set5D8_1_0013E430(Obj_EnemyScr_Event200COnHit_1_00142320 *, f32);
void Enemy_IncCounter6B8_1_0013EF50(Obj_EnemyScr_Event200COnHit_1_00142320 *);
void Enemy_IncCounter6B9_1_0013EF10(Obj_EnemyScr_Event200B_1_001423E0 *o);
void Script_SetArgS16_1_001650B0(void *, u8, s32, s32);
void sprintf(void *, s32 *);
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2024GetMove_1_001409A0(void *, u8, s32);
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2023_1_00140CB0(void *, u8, s32);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2022_1_00140DE0(s32 a, s32 b, Obj_EnemyScr_Event2022_1_00140DE0 *o);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2022_1_00140DE0(s32 a, s32 h);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2021_1_00140E50(s32 a, s32 b, Obj_EnemyScr_Event2021_1_00140E50 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2021_1_00140E50(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2021_1_00140E50(s32 a, s32 h);
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2021_1_00140E50(s32 a, u8 h, u8 c);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2020_1_00140EF0(s32 a, s32 b, Obj_EnemyScr_Event2020_1_00140EF0 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2020_1_00140EF0(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2020_1_00140EF0(s32 a, s32 h);
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2020_1_00140EF0(s32 a, u8 h, u8 c);
s32 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastMotionEvent_0_00140F90(s8 *);
s32 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastMotionEvent_0_00140F90(s8 *);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_BroadcastMotionEvent_0_00140F90(void *, s32);
Obj_EnemyScr_BroadcastFrameEvent_0_001410C0* ActorList_Next_2_001A5460__as_EnemyScr_BroadcastFrameEvent_0_001410C0(s32 *);
s32 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastFrameEvent_0_001410C0(Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *);
s32 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastFrameEvent_0_001410C0(Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2018_1_001411F0(s32 a, s32 b, Obj_EnemyScr_Event2018_1_001411F0 *o);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2018_1_001411F0(s32 a, s32 h);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2017OnDeath_1_00141260(s32 a, s32 b, Obj_EnemyScr_Event2017OnDeath_1_00141260 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2017OnDeath_1_00141260(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2017OnDeath_1_00141260(s32 a, s32 h);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2016_1_001412E0(s32 a, s32 b, Obj_EnemyScr_Event2016_1_001412E0 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2016_1_001412E0(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2016_1_001412E0(s32 a, s32 h);
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2016_1_001412E0(s32 a, u8 h, u8 c);
Obj_EnemyScr_BroadcastQuery_0_00141380* ActorList_Next_2_001A5460__as_EnemyScr_BroadcastQuery_0_00141380(s32 *);
s32 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastQuery_0_00141380(Obj_EnemyScr_BroadcastQuery_0_00141380 *);
s32 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastQuery_0_00141380(Obj_EnemyScr_BroadcastQuery_0_00141380 *);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2014_1_00141610(s32 a, s32 b, Obj_EnemyScr_Event2014_1_00141610 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2014_1_00141610(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2014_1_00141610(s32 a, s32 h);
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2014_1_00141610(s32 a, u8 h, u8 c);
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2013GetMove_1_001416B0(void *, u8, s32);
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50(void *, u8, s32);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2010_1_00141DA0(s32 a, s32 b, Obj_EnemyScr_Event2010_1_00141DA0 *o);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2010_1_00141DA0(s32 a, s32 h);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event200F_1_00141E10(s32, s32, A_Enemy_GetScreenSize_0_0013FEB0 *);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event200F_1_00141E10(s32, u8, s32, s32);
void Script_SetArgU16_1_001650F0__as_EnemyScr_Event200F_1_00141E10(s32, u8, s32, u16);
void Script_SetArgF32_1_00164FF0__as_EnemyScr_Event200F_1_00141E10(s32, u8, s32, f32);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event200F_1_00141E10(s32, s32);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event200E_1_00142010(s32 a, s32 b, Obj_EnemyScr_Event200E_1_00142010 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event200E_1_00142010(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event200E_1_00142010(s32 a, s32 h);
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event200DGetStats_1_00142090(void *, u8, s32);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event200B_1_001423E0(s32 a, s32 b, Obj_EnemyScr_Event200B_1_001423E0 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event200B_1_001423E0(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event200B_1_001423E0(s32 a, s32 h);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2002_1_00142780(s32 a, s32 b, Obj_EnemyScr_Event2002_1_00142780 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2002_1_00142780(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2002_1_00142780(s32 a, s32 h);
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2002_1_00142780(s32 a, u8 h, u8 c);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2001_1_00142820(s32 a, s32 b, Obj_EnemyScr_Event2001_1_00142820 *o);
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2001_1_00142820(s32 a, u8 h, s32 c, s32 d);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2001_1_00142820(s32 a, s32 h);
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2001_1_00142820(s32 a, u8 h, u8 c);
s32 Script_SendEvent_2_00166F80__as_EnemyScr_EventInit_1_001428C0(s32 a, s32 b, Obj_EnemyScr_EventInit_1_001428C0 *o);
s32 Script_RunEvent_2_00166C10__as_EnemyScr_EventInit_1_001428C0(s32 a, s32 h);
f32* Enemy_GetPositionPtr_2_00140460__as_EnemyScr_Event2026_1_00140480(void *);
f32* Enemy_GetRotationPtr_1_00140430__as_EnemyScr_Event2026_1_00140480(void *);
f32* Enemy_PtrVec660_1_00140340__as_EnemyScr_Event2026_1_00140480(void *);
f32* Enemy_PtrVec670_1_00140320__as_EnemyScr_Event2026_1_00140480(void *);
u32 Rand_Next_3_0015ED20(void);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0SubVector__as_Enemy_PickWaypointToward_1_00143150(f32 *v0, f32 *v1, f32 *v2);
void Enemy_PickRandomWaypoint_1_001431A0__as_Enemy_PickWaypointToward_1_00143150(void *a, f32 *v);
u8 Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickRandomWaypoint_1_001431A0(void);
void sceVu0SubVector__as_Enemy_PickWaypointDir_1_00143290(f32 *v0, f32 *v1, f32 *v2);
void Enemy_FindWaypointDir_0_001432F0__as_Enemy_PickWaypointDir_1_00143290(void *a, f32 *v, s32 c, s32 d);
void sceVu0SubVector__as_Enemy_FindWaypointDir_0_001432F0(Vec *, Vec *, Vec *);
void sceVu0SubVector__as_Enemy_IsWaypointReachable_0_001434F0(Vec *, Vec *, Vec *);
void sceVu0SubVector__as_Enemy_PickNearestWaypointToward_1_001435D0(f32 *v0, f32 *v1, f32 *v2);
void Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickNearestWaypointToward_1_001435D0(void *a, f32 *v);
void sceVu0SubVector__as_Enemy_FindNearestWaypoint_1_00143610(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct__as_Enemy_GetScreenSize_0_0013FEB0(f32 *v0, f32 *v1);
f32 sceVu0InnerProduct__as_Enemy_PickWaypointToward_1_00143150_(Vec *, Vec *);
s8* Script_GetArgPtr_2_00165130(Obj_EnemyCmd_GetFlag_0_001438B0 *o, s32 b);
s8 Save_TestItemBit_1_001A9B40(s16 v);
s8 Save_GetByte2E_0_001AA740(void);
void Enemy_Set5B4b6_1_0013E490(void *arg0, u8 arg1);
void Enemy_Set5B4b5_1_0013E4B0(void *arg0, u8 arg1);
void Enemy_Set5B8_1_0013E480(s32, f32);
void Enemy_Set60B_1_0013E250(s32, u8);
void sceVu0AddVector(Vec *, Vec *, void *);
s8 Enemy_Get608_1_0013E290(void *p);
s8 Player_GetFlag521b5_1_00145620(void);
void Enemy_Set5A1b5_1_0013EE90(void *arg0, u8 arg1);
void Enemy_Set5B4b4_1_0013E5F0(void *arg0, u8 arg1);
void Enemy_Set5B4b3_1_0013E620(void *p, s32 v);
void Enemy_Set5C8_1_0013E450(void *p, f32 f);
void Enemy_Set5C0_1_0013E470(void *p, f32 f);
void Combat_ResolveHit_1_00135E30(s32 a, u8 mode, void *p, void *q, void *r, void *s);
void Enemy_UpdatePartStat_0_0013F0C0(void *arg0, u8 arg1);
void Enemy_LoadPartWrap_0_0013F0B0(s32, u8);
void Enemy_InitPart_1_0013F1B0(void *arg0, u8 arg1);
void memset(void *, s32, s32);
void Enemy_RaycastMapC_0_0013D430(s32, Hit *, Seg *, s32, s32);
void sceVu0ScaleVector(f32, Vec *, Vec *);
s32 Enemy_Get81_1_0013FC00(s8 *);
void Enemy_GetCollider_0_0013FB90(s8 *, u8, QP *, QP *);
void Enemy_Kill_1_0013EF80(void *arg0, u8 arg1);
void Enemy_Set5B3b6_1_0013E710(void *p, s32 v);
void Enemy_Set5B6b1_1_0013E6F0(void *p, s32 v);
void Enemy_Set5B2b6w2_1_0013E730(void *arg0, u8 arg1);
void Enemy_Set5B2b2_1_0013E840(void *arg0, u8 arg1);
void Enemy_Set5B2b1_1_0013E860(void *arg0, u8 arg1);
void Enemy_Set5B0b2_1_0013EBF0(void *arg0, u8 arg1);
u16 GameFlag_GetHalf_0_0013D560(u8, u8);
u16 Enemy_GetHp_2_0013F750(void *p);
void Enemy_AddHp_2_0013F710(void *, s32);
void GameFlag_GetWordWrap_0_0013D540(u8 a, u8 b, u16 c);
T_EnemyCmd_FindSpawnPoint_0_001444F0* Enemy_GetParamPtr10_1_0013E070(O_EnemyCmd_Nop_1_00143890 *);
u32 Enemy_Get5B0b7_1_0013EB60(O_EnemyCmd_Nop_1_00143890 *);
u32 Enemy_Get5B1b5_1_0013E940(O_EnemyCmd_Nop_1_00143890 *);
u32 Enemy_Get5B6b4_1_0013EAA0(O_EnemyCmd_Nop_1_00143890 *);
Vec* Player_GetBody_1_00145770(void);
s32 Rand_Range_3_0013D500(s32);
void Enemy_RaycastMapB_0_0013D320(s32, Buf *, Vec *, s32, s32);
s8 Player_ThrowItem_0_001CA960(void);
s8 Player_HoldItem_0_001CAB20(s16, u8, Vec *, Vec *);
C_EnemyCmd_Nop_1_00143890* Inventory_GetEntry_1_001CC3F0(s16);
s32 Player_PlaceItem_0_001CADF0(s16, Vec *, Vec *, s32);
void Enemy_Set5B2b0_1_0013E890(void *arg0, u8 arg1);
void Enemy_Set5B1b7_1_0013E8C0(void *arg0, u8 arg1);
void Enemy_Set5B1b6_1_0013E8F0(void *arg0, u8 arg1);
void Enemy_BreakPart_0_0013F210(void *arg0, u8 arg1, s32 arg2);
void Enemy_Set5B0b0_1_0013EC30(void *arg0, u8 arg1);
u16 Enemy_GetMaxHp_2_0013F700(void *);
s32 Enemy_Get5B1b2_1_0013EA40(void *);
void Enemy_Set5B1b2_1_0013EA20(void *, int);
s16 Enemy_GetCurrentParamIdx_0_0013E110(void *p);
void Enemy_Set5B1b1_1_0013EA50(void *arg0, u8 arg1);
void Enemy_UpdateParamFlags_0_0013F760(void *arg0, u8 arg1);
void Enemy_Set5B1b0_1_0013EB10(void *arg0, u8 arg1);
void GameFlag_SetBit_2_0013D5C0(u8 arg0, u8 arg1);
s8 GameFlag_TestBit_2_0013D630(u8 a, u8 b);
void Enemy_SetDeadFlag_0_0013EEB0(void *arg0, u8 arg1);
void Enemy_Set5B0b7_1_0013EB40(void *arg0, u8 arg1);
void Enemy_Set5B0b1_1_0013EC10(void *arg0, u8 arg1);
s8 Enemy_Get5B0m1_1_0013EC50(void *p);
s8 Enemy_GetHpPercent_2_0013F620(void *p);
void Enemy_SetMode_0_0013EBA0(void *arg0, u8 arg1);
s16* PlayerData_Get_2_001C9BA0(void);
void Player_PlayLevelUpSe_0_001C9FB0(s32);
void Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
s32 Snd_PlaySeAt_2_001315A0(s32 a, s32 b, f32 *v);
void SndCh_GetPosition_1_00131180(s32, P_EnemyCmd_PlaySe_1_001453A0 *);
Vec* Enemy_GetModelData_1_0013DCE0(s32);
void* MapObj_FindById_0_00179DB0(u16, u16);
u8 Msg_ShowWrap_1_0018AC90(void *, s32);
void Camera_SetShake_0_00189F00(T_EnemyCmd_ShakeCamera_0_001455B0 *t);
void Enemy_ResetVectors_0_0013D1F0(void *arg0, u8 arg1);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetGlobal_0_001438F0(s32 a, s32 b);
void sceVu0CopyVector__as_EnemyCmd_GetRelativePos_0_00143960(Vec *, Vec *);
void Enemy_GetRightVector_1_00140360__as_EnemyCmd_GetRelativePos_0_00143960(s8 *, Vec *);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_Get608_1_00143B20(s32 a, s32 b);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPlayerValue_0_00143B60(s32 a, s32 b);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetMotionFrame_1_00143C30(s32 a, s32 b);
void* Script_GetArgPtr_2_00165130__as_EnemyCmd_ResolveHit_0_00143C70(u8 *o, s32 b);
f32* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetVec660_0_00143D60(void *o, s32 b);
s32 Enemy_GetMotionId_0_0013ED20__as_EnemyCmd_FindTargetInCone_0_00143E20(s8 *);
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_FindTargetInCone_0_00143E20(s8 *, Vec *);
void Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_FindTargetInCone_0_00143E20(s8 *, Vec *);
void sceVu0CopyVector__as_EnemyCmd_FindTargetInCone_0_00143E20(Vec *, Vec *);
void sceVu0CopyVector__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *, s8 *);
void EnemyCmd_FindTargetInCone_0_00143E20__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *, s32, s32, s32, s32, s32, f32);
s8* Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *);
s8* Enemy_PtrVec660_1_00140340__as_EnemyCmd_GetTargetPos_0_001441B0(s8 *);
u8 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastMotion_1_001442F0(void *p);
s32 Enemy_GetHp_2_0013F750__as_EnemyCmd_StoreHpToFlag_1_00144490(void *p);
u8* Script_GetArgPtr_2_00165130__as_EnemyCmd_FindSpawnPoint_0_001444F0(Msg *, s32);
Vec* Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_FindSpawnPoint_0_001444F0(O_EnemyCmd_Nop_1_00143890 *);
void sceVu0CopyVector__as_EnemyCmd_FindSpawnPoint_0_001444F0(Vec *, Vec *);
f32* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPosition_2_00144970(void *o, s32 b);
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_GetPosition_2_00144970(void *p, f32 *v);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, s32);
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);
void Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);
void Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);
void Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffect_0_00144A00(s8 *, Vec *);
u8* Script_GetArgPtr_2_00165130__as_EnemyCmd_StopEffect_0_00144B80(s32, s32);
u8* Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffectB_0_00144BE0(Arg_EnemyCmd_SpawnEffectB_0_00144BE0 *, s32);
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);
void Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);
void Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);
void Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffectB_0_00144BE0(char *, Vec *);
u8 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastFrame_1_00144D80(void *p);
u16 Enemy_AddHp_2_0013F710__as_EnemyCmd_HealPercent_1_00144E40(void *, s32);
s16* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetParamIdx_1_00144F60(s32 a, s32 b);
u8 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterKill_0_00144FC0(void *p);
u8 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterSeen_0_00145010(void *p);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_TestGameFlag_2_00145080(u8 *o, s32 b);
s32 Enemy_Kill_1_0013EF80__as_EnemyCmd_KillNow_1_001450F0();
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_Random_2_00145100(void *a, s32 b);
s8 Rand_Range_3_0013D500__as_EnemyCmd_Random_2_00145100(u8 v);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetType_1_00145140(s32 a, s32 b);
s8 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_GetType_1_00145140(void *p);
void Enemy_AddHp_2_0013F710__as_EnemyCmd_AddHp_2_00145190(void *arg0, u16 arg1);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_Get5B0b0_1_001451A0(s32 a, s32 b);
s8* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetHpPercent_2_00145250(s32 a, s32 b);
void sceVu0CopyVector__as_EnemyCmd_PlaySe_1_001453A0(f32 *, f32 *);
f32* Script_GetArgPtr_2_00165130__as_EnemyCmd_GetModelPos_0_00145410(s32, s32);
void sceVu0CopyVector__as_EnemyCmd_GetModelPos_0_00145410(Vec *, Vec *);
u8* Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnItem_0_001454E0(Arg_EnemyCmd_SpawnItem_0_001454E0 *, s32);

/* Enemy_GetScreenSize_0_0013FEB0_ */
#define sceVu0CopyVector sceVu0CopyVector__as_Enemy_GetScreenSize_0_0013FEB0_
void sceVu0CopyVector__as_Enemy_GetScreenSize_0_0013FEB0_(f32 *v0, f32 *v1);
#define Enemy_GetMotionId_0_0013ED20 Enemy_GetMotionId_0_0013ED20__as_Enemy_GetScreenSize_0_0013FEB0_
s32 Enemy_GetMotionId_0_0013ED20__as_Enemy_GetScreenSize_0_0013FEB0_(s8 *);
#define Ent_GetTypeByte_1_0013E220 Ent_GetTypeByte_1_0013E220__as_Enemy_GetScreenSize_0_0013FEB0_
s32 Ent_GetTypeByte_1_0013E220__as_Enemy_GetScreenSize_0_0013FEB0_(Obj_EnemyScr_BroadcastQuery_0_00141380 *);

/* Enemy_GetScreenSize_0_0013FEB0 */

/* Enemy_GetScreenSize_0_0013FEB0 */
/* Enemy_GetScreenSize_0_0013FEB0 */
static inline f32 u2f_Enemy_GetScreenSize_0_0013FEB0(u32 x) { return x; }

void Enemy_GetScreenSize_0_0013FEB0(O_Enemy_GetScreenSize_0_0013FEB0 *o, f32 *a1, f32 *a2) {
    f32 x;
    f32 y;
    Hdr *pp;
    u16 idx;
    Ent *q;

    y = x = 4000.0f;
    if (!o->f5A1.f.b3) {
        idx = o->x4AC;
        pp = o->x4A8;
        q = pp ? &pp->tbl->ents[idx] : NULL;
        if (q) {
            x = u2f_Enemy_GetScreenSize_0_0013FEB0(q->x22);
            y = u2f_Enemy_GetScreenSize_0_0013FEB0(q->x24);
        }
    }
    if (a1) *a1 = x;
    if (a2) *a2 = y;
}

/* Enemy_Ptr700_1_0013FF90 */
s32 Enemy_Ptr700_1_0013FF90(s32 arg0) {
    return arg0 + 0x700;
}

/* Enemy_Ptr6F0_1_0013FFA0 */
s32 Enemy_Ptr6F0_1_0013FFA0(s32 arg0) {
    return arg0 + 0x6F0;
}

/* Enemy_Ptr6E0_1_0013FFB0 */
s32 Enemy_Ptr6E0_1_0013FFB0(s32 arg0) {
    return arg0 + 0x6E0;
}

/* Enemy_GetAngleToPlayer_1_0013FFC0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

f32 Enemy_GetAngleToPlayer_1_0013FFC0(s8 *a0) {
 Vec v; f32 y; f32 d; f32 a;
 y = Player_GetRotationPtr_1_00145710()->y;
 Player_CopyPosition_1_00145760__as_Enemy_GetAngleToPlayer_1_0013FFC0(&v);
 sceVu0SubVector__as_Enemy_GetAngleToPlayer_1_0013FFC0(&v, *(Vec **)(*(s8 **)(a0 + 0x518) + 0x198), &v);
 a = 3.1415927f + atan2f(v.x, v.z); a = WRAP(a); y = WRAP(y); y = a - y;
 if (y > 3.1415927f) y -= 6.2831855f;
 if (y < -3.1415927f) y += 6.2831855f;
 y /= 3.1415927f; return y;
}

/* Enemy_GetYawToPlayer_1_00140160 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

f32 Enemy_GetYawToPlayer_1_00140160(Actor *a) {
    f32 r;
    f32 d;
    Vec v;
    r = *(f32 *)(*(s8 **)(a->unk518 + 0x198) + 0x24);
    Player_CopyPosition_1_00145760__as_Enemy_GetYawToPlayer_1_00140160(&v);
    sceVu0SubVector__as_Enemy_GetYawToPlayer_1_00140160(&v, &v, *(s8 **)(a->unk518 + 0x198));
    d = 3.1415927f + atan2f(v.x, v.z);
    d = WRAP(d) - r;
    if (!(d <= 3.1415927f)) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    d /= 3.1415927f;
    return d;
}

/* Enemy_GetDistSqToPlayer_1_001402A0 */

f32 Enemy_GetDistSqToPlayer_1_001402A0(Obj_Enemy_GetDistSqToPlayer_1_001402A0 *o)
{
    f32 v[4];
    Player_CopyPosition_1_00145760__as_Enemy_GetDistSqToPlayer_1_001402A0(v);
    sceVu0SubVector__as_Enemy_GetDistSqToPlayer_1_001402A0(v, v, o->b->v);
    return sqrtf(sceVu0InnerProduct__as_Enemy_GetScreenSize_0_0013FEB0(v, v));
}

/* Enemy_CopyVec690_1_00140300 */
void Enemy_CopyVec690_1_00140300(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x690));
}

/* Enemy_CopyVec680_1_00140310 */
void Enemy_CopyVec680_1_00140310(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x680));
}

/* Enemy_PtrVec670_1_00140320 */
s32 Enemy_PtrVec670_1_00140320(s32 arg0) {
    return arg0 + 0x670;
}

/* Enemy_CopyVec670_1_00140330 */
void Enemy_CopyVec670_1_00140330(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x670));
}

/* Enemy_PtrVec660_1_00140340 */
s32 Enemy_PtrVec660_1_00140340(s32 arg0) {
    return arg0 + 0x660;
}

/* Enemy_CopyVec660_1_00140350 */
void Enemy_CopyVec660_1_00140350(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x660));
}

/* Enemy_GetRightVector_1_00140360 */
void Enemy_GetRightVector_1_00140360(Obj_Enemy_GetRightVector_1_00140360 *o, f32 *v)
{
    f32 a = o->b->c->yaw;
    a += 1.5707964f;
    v[0] = -sinf(a);
    v[1] = 0.0f;
    v[2] = -cosf(a);
}

/* Enemy_GetForwardVector_2_001403D0 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void Enemy_GetForwardVector_2_001403D0(void *arg0, void *arg1) {
    f32 temp_f20;

    temp_f20 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void **, 0x198), f32 *, 0x24);
    M2C_FIELD(arg1, f32 *, 0) = (f32) -sinf(temp_f20);
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, f32 *, 8) = (f32) -cosf(temp_f20);
}

/* Enemy_GetRotationPtr_1_00140430 */
s32 Enemy_GetRotationPtr_1_00140430(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198) + 0x20;
}

/* Enemy_CopyRotation_2_00140440 */

void Enemy_CopyRotation_2_00140440(void *arg0, s32 arg1) {
    sceVu0CopyVector__as_Enemy_CopyRotation_2_00140440(arg1, M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198) + 0x20);
}

/* Enemy_GetPositionPtr_2_00140460 */
s32 Enemy_GetPositionPtr_2_00140460(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198);
}

/* Enemy_CopyPosition_2_00140470 */

void Enemy_CopyPosition_2_00140470(void *arg0, s32 arg1) {
    sceVu0CopyVector__as_Enemy_CopyPosition_2_00140470(arg1, M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198));
}

/* EnemyScr_Event2026_1_00140480 */

/* EnemyScr_Event2026_1_00140480 */
static inline u32 cv(f32 x) { return (u32)x; }
#define H(a) (*(a)->p)

u8 EnemyScr_Event2026_1_00140480(Obj_EnemyScr_Event2026_1_00140480 *a0, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2026, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, a1);
    if (f0 > 1.0f) f0 = 1.0f;
    if (f0 < 0.0f) f0 = 0.0f;
    Script_SetArgU8_1_00165070(H(a0), id, 1, cv(100.0f * f0));
    if (f1 > 1.2f) f1 = 1.2f;
    Script_SetArgU8_1_00165070(H(a0), id, 2, cv(100.0f * f1));
    if (f2 > 1.2f) f2 = 1.2f;
    Script_SetArgU8_1_00165070(H(a0), id, 3, cv(100.0f * f2));
    Script_SetArgU16_1_001650F0(H(a0), id, 4, (u32)f3);
    Script_SetArgU8_1_00165070(H(a0), id, 5, a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2025_1_00140770 */
#define H(a) (*(a)->p)

void EnemyScr_Event2025_1_00140770(Obj_EnemyScr_Event2025_1_00140770 *a0, s8 *a1, u32 a2, u32 a3, u32 a4) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2025, a0);
    Script_SetArgS8_1_00165030(H(a0), id, 0, a1[0]);
    Script_SetArgS8_1_00165030(H(a0), id, 1, a1[1]);
    Script_SetArgS8_1_00165030(H(a0), id, 2, a1[2]);
    Script_SetArgS8_1_00165030(H(a0), id, 3, a1[3]);
    Script_SetArgS8_1_00165030(H(a0), id, 4, a1[4]);
    Script_SetArgS8_1_00165030(H(a0), id, 5, a1[5]);
    Script_SetArgS8_1_00165030(H(a0), id, 6, a1[6]);
    Script_SetArgU8_1_00165070(H(a0), id, 7, a2);
    Script_SetArgU8_1_00165070(H(a0), id, 8, a3);
    Script_SetArgU8_1_00165070(H(a0), id, 9, a4);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    a1[0] = Script_GetResultS8_1_00164F90(H(a0), id, 0);
    a1[1] = Script_GetResultS8_1_00164F90(H(a0), id, 1);
    a1[2] = Script_GetResultS8_1_00164F90(H(a0), id, 2);
    a1[3] = Script_GetResultS8_1_00164F90(H(a0), id, 3);
    a1[4] = Script_GetResultS8_1_00164F90(H(a0), id, 4);
    a1[5] = Script_GetResultS8_1_00164F90(H(a0), id, 5);
    a1[6] = Script_GetResultS8_1_00164F90(H(a0), id, 6);
}

/* EnemyScr_Event2024GetMove_1_001409A0 */
static inline u16 mk_EnemyScr_Event2024GetMove_1_001409A0(u16 lo, u16 hi) { return (u8)lo | ((u8)hi << 8); }
#define H(a) (*(a)->p)

u16 EnemyScr_Event2024GetMove_1_001409A0(Obj_EnemyScr_Event2024GetMove_1_001409A0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz) {
    s32 h4;
    s32 h5;
    u16 r;
    h5 = Script_SendEvent_2_00166F80(H(a0), 0x2024, a0);
    h4 = Script_SendEvent_2_00166F80(H(a0), 0x2020, a0);
    Script_SetArgU8_1_00165070(H(a0), h4, 0, 0);
    while (Script_RunEvent_2_00166C10(H(a0), h4) != 0) {}
    if ((u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2024GetMove_1_001409A0(H(a0), h4, 0) != 0) {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_GetPositionPtr_2_00140460__as_EnemyScr_Event2026_1_00140480(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_GetPositionPtr_2_00140460__as_EnemyScr_Event2026_1_00140480(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_GetRotationPtr_1_00140430__as_EnemyScr_Event2026_1_00140480(a0)[1]);
    } else {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 8);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 6);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_PtrVec660_1_00140340__as_EnemyScr_Event2026_1_00140480(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_PtrVec660_1_00140340__as_EnemyScr_Event2026_1_00140480(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_PtrVec670_1_00140320__as_EnemyScr_Event2026_1_00140480(a0)[1]);
    }
    while (Script_RunEvent_2_00166C10(H(a0), h5) != 0) {}
    h4 = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2024GetMove_1_001409A0(H(a0), h5, 0);
    r = mk_EnemyScr_Event2024GetMove_1_001409A0(h4, Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2024GetMove_1_001409A0(H(a0), h5, 1));
    if (px) *px = Script_GetResultF32_1_00164F60(H(a0), h5, 3);
    if (py) *py = Script_GetResultF32_1_00164F60(H(a0), h5, 4);
    if (pz) *pz = Script_GetResultF32_1_00164F60(H(a0), h5, 5);
    return r;
}

/* EnemyScr_Event2023_1_00140CB0 */
#define H(a) (*(a)->p)

void EnemyScr_Event2023_1_00140CB0(Obj_EnemyScr_Event2023_1_00140CB0 *a0, u8 *pa, f32 *pb, f32 *pc) {
    s32 h;
    h = Script_SendEvent_2_00166F80(H(a0), 0x2023, a0);
    Script_SetArgU8_1_00165070(H(a0), h, 0, 0);
    Script_SetArgF32_1_00164FF0(H(a0), h, 1, 2.0f);
    Script_SetArgF32_1_00164FF0(H(a0), h, 2, 0.0f);
    while (Script_RunEvent_2_00166C10(H(a0), h) != 0) {}
    if (pa) *pa = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2023_1_00140CB0(H(a0), h, 0);
    if (pb) *pb = Script_GetResultF32_1_00164F60(H(a0), h, 1);
    if (pc) *pc = Script_GetResultF32_1_00164F60(H(a0), h, 2);
}

/* EnemyScr_Event2022_1_00140DE0 */

void EnemyScr_Event2022_1_00140DE0(Obj_EnemyScr_Event2022_1_00140DE0 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2022_1_00140DE0(*o->p, 0x2022, o);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2022_1_00140DE0(*o->p, h)) {
    }
}

/* EnemyScr_Event2021_1_00140E50 */

u8 EnemyScr_Event2021_1_00140E50(Obj_EnemyScr_Event2021_1_00140E50 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2021_1_00140E50(*o->p, 0x2021, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event2021_1_00140E50(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2021_1_00140E50(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2021_1_00140E50(*o->p, h, 0);
}

/* EnemyScr_Event2020_1_00140EF0 */

u8 EnemyScr_Event2020_1_00140EF0(Obj_EnemyScr_Event2020_1_00140EF0 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2020_1_00140EF0(*o->p, 0x2020, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event2020_1_00140EF0(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2020_1_00140EF0(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2020_1_00140EF0(*o->p, h, 0);
}

/* EnemyScr_BroadcastMotionEvent_0_00140F90 */
#define H(o) (**(void ***)((o) + 0x4A4))

void EnemyScr_BroadcastMotionEvent_0_00140F90(u8 a, u8 b, u32 c, u32 d) {
    s32 it;
    s8 *o;
    s32 h;
    it = 0;
    o = ActorList_Next_2_001A5460(&it);
    while (o != NULL) {
        if (!Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastMotionEvent_0_00140F90(o) && a == Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastMotionEvent_0_00140F90(o) && b == (u8)Enemy_GetMotionId_0_0013ED20(o)) {
            h = Script_SendEvent_2_00166F80(H(o), 0x2019, o);
            Script_SetArgU8_1_00165070(H(o), h, 0, c);
            Script_SetArgU8_1_00165070(H(o), h, 1, d);
            while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_BroadcastMotionEvent_0_00140F90(H(o), h)) {
            }
            return;
        }
        o = ActorList_Next_2_001A5460(&it);
    }
}

/* EnemyScr_BroadcastFrameEvent_0_001410C0 */
#define H(a) (*(a)->p)

void EnemyScr_BroadcastFrameEvent_0_001410C0(u8 a0, u8 a1, u32 a2, u32 a3) {
    s32 it;
    Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *cur;
    s32 id;
    it = 0;
    cur = ActorList_Next_2_001A5460__as_EnemyScr_BroadcastFrameEvent_0_001410C0(&it);
    if (cur != NULL) {
        do {
            if (!Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastFrameEvent_0_001410C0(cur) && Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastFrameEvent_0_001410C0(cur) == a0 && (u8)Enemy_GetMotionFrame_0_0013ECA0(cur) == a1) {
                id = Script_SendEvent_2_00166F80(H(cur), 0x2019, cur);
                Script_SetArgU8_1_00165070(H(cur), id, 0, a2);
                Script_SetArgU8_1_00165070(H(cur), id, 1, a3);
                while (Script_RunEvent_2_00166C10(H(cur), id) != 0) {}
            }
            cur = ActorList_Next_2_001A5460__as_EnemyScr_BroadcastFrameEvent_0_001410C0(&it);
        } while (cur != NULL);
    }
}

/* EnemyScr_Event2018_1_001411F0 */

void EnemyScr_Event2018_1_001411F0(Obj_EnemyScr_Event2018_1_001411F0 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2018_1_001411F0(*o->p, 0x2018, o);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2018_1_001411F0(*o->p, h)) {
    }
}

/* EnemyScr_Event2017OnDeath_1_00141260 */

void EnemyScr_Event2017OnDeath_1_00141260(Obj_EnemyScr_Event2017OnDeath_1_00141260 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2017OnDeath_1_00141260(*o->p, 0x2017, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event2017OnDeath_1_00141260(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2017OnDeath_1_00141260(*o->p, h)) {
    }
}

/* EnemyScr_Event2016_1_001412E0 */

u8 EnemyScr_Event2016_1_001412E0(Obj_EnemyScr_Event2016_1_001412E0 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2016_1_001412E0(*o->p, 0x2016, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event2016_1_001412E0(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2016_1_001412E0(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2016_1_001412E0(*o->p, h, 0);
}

/* EnemyScr_BroadcastQuery_0_00141380 */
#define H(a) (*(a)->p)

u8 EnemyScr_BroadcastQuery_0_00141380(u32 a0, u32 a1) {
    s32 it;
    u8 n;
    Obj_EnemyScr_BroadcastQuery_0_00141380 *cur;
    s32 k;
    s32 id;
    u8 v;
    n = 0;
    it = 0;
    cur = ActorList_Next_2_001A5460__as_EnemyScr_BroadcastQuery_0_00141380(&it);
    if (cur != NULL) {
        do {
            if (!Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastQuery_0_00141380(cur)) {
                k = (u8)Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastQuery_0_00141380(cur);
                v = Ent_GetTypeByte_1_0013E220(cur);
                if (v >= 0x25 && v <= 0x28 && !Enemy_IsDead_1_0013EEE0(cur)) {
                    id = Script_SendEvent_2_00166F80(H(cur), 0x2015, cur);
                    Script_SetArgU8_1_00165070(H(cur), id, 0, 0);
                    Script_SetArgU8_1_00165070(H(cur), id, 1, k);
                    Script_SetArgU8_1_00165070(H(cur), id, 2, a0);
                    Script_SetArgU8_1_00165070(H(cur), id, 3, a1);
                    while (Script_RunEvent_2_00166C10(H(cur), id) != 0) {}
                    n += (u8)Script_GetResultU8_1_00164FC0(H(cur), id, 0);
                }
            }
            cur = ActorList_Next_2_001A5460__as_EnemyScr_BroadcastQuery_0_00141380(&it);
        } while (cur != NULL);
    }
    return n;
}

/* EnemyScr_Event2015_1_00141510 */
#define H(a) (*(a)->p)

u8 EnemyScr_Event2015_1_00141510(Obj_EnemyScr_Event2015_1_00141510 *a0, u32 a1, u32 a2, u32 a3) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2015, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgU8_1_00165070(H(a0), id, 1, a1);
    Script_SetArgU8_1_00165070(H(a0), id, 2, a2);
    Script_SetArgU8_1_00165070(H(a0), id, 3, a3);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2014_1_00141610 */

u8 EnemyScr_Event2014_1_00141610(Obj_EnemyScr_Event2014_1_00141610 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2014_1_00141610(*o->p, 0x2014, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event2014_1_00141610(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2014_1_00141610(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2014_1_00141610(*o->p, h, 0);
}

/* EnemyScr_Event2013GetMove_1_001416B0 */
static inline u16 mk_EnemyScr_Event2013GetMove_1_001416B0(u16 lo, u16 hi) { return (u8)lo | ((u8)hi << 8); }
#define H(a) (*(a)->p)

u16 EnemyScr_Event2013GetMove_1_001416B0(Obj_EnemyScr_Event2013GetMove_1_001416B0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz) {
    s32 h4;
    s32 h5;
    u16 r;
    h5 = Script_SendEvent_2_00166F80(H(a0), 0x2013, a0);
    h4 = Script_SendEvent_2_00166F80(H(a0), 0x2020, a0);
    Script_SetArgU8_1_00165070(H(a0), h4, 0, 0);
    while (Script_RunEvent_2_00166C10(H(a0), h4) != 0) {}
    if ((u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2013GetMove_1_001416B0(H(a0), h4, 0) != 0) {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_GetPositionPtr_2_00140460__as_EnemyScr_Event2026_1_00140480(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_GetPositionPtr_2_00140460__as_EnemyScr_Event2026_1_00140480(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_GetRotationPtr_1_00140430__as_EnemyScr_Event2026_1_00140480(a0)[1]);
    } else {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 8);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 6);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_PtrVec660_1_00140340__as_EnemyScr_Event2026_1_00140480(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_PtrVec660_1_00140340__as_EnemyScr_Event2026_1_00140480(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_PtrVec670_1_00140320__as_EnemyScr_Event2026_1_00140480(a0)[1]);
    }
    while (Script_RunEvent_2_00166C10(H(a0), h5) != 0) {}
    h4 = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2013GetMove_1_001416B0(H(a0), h5, 0);
    r = mk_EnemyScr_Event2013GetMove_1_001416B0(h4, Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2013GetMove_1_001416B0(H(a0), h5, 1));
    if (px) *px = Script_GetResultF32_1_00164F60(H(a0), h5, 3);
    if (py) *py = Script_GetResultF32_1_00164F60(H(a0), h5, 4);
    if (pz) *pz = Script_GetResultF32_1_00164F60(H(a0), h5, 5);
    return r;
}

/* EnemyScr_Event2012_1_001419C0 */
#define H(a) (*(a)->p)
void EnemyScr_Event2012_1_001419C0(Obj_EnemyScr_Event2012_1_001419C0 *a0, f32 f) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2012, a0);
    Script_SetArgF32_1_00164FF0(H(a0), id, 0, f);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
}

/* EnemyScr_Event2011GetWeights_1_00141A50 */
#define H(a) (*(a)->p)

void EnemyScr_Event2011GetWeights_1_00141A50(Obj_EnemyScr_Event2011GetWeights_1_00141A50 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *p4) {
    s32 h;
    u32 v0, v1, v2, v3, v4;
    h = Script_SendEvent_2_00166F80(H(a0), 0x2011, a0);
    Script_SetArgU8_1_00165070(H(a0), h, 0, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 1, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 2, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 3, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 4, 100);
    while (Script_RunEvent_2_00166C10(H(a0), h) != 0) {}
    v0 = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50(H(a0), h, 0);
    v1 = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50(H(a0), h, 1);
    v2 = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50(H(a0), h, 2);
    v3 = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50(H(a0), h, 3);
    v4 = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50(H(a0), h, 4);
    if (p0) *p0 = v0 / 100.0f;
    if (p1) *p1 = v1 / 100.0f;
    if (p2) *p2 = v2 / 100.0f;
    if (p3) *p3 = v3 / 100.0f;
    if (p4) *p4 = v4 / 100.0f;
    if (((u8)Enemy_Get5B5mF_1_0013E5E0(a0) & 2) && p0) *p0 /= 2.0f;
}

/* EnemyScr_Event2010_1_00141DA0 */

void EnemyScr_Event2010_1_00141DA0(Obj_EnemyScr_Event2010_1_00141DA0 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2010_1_00141DA0(*o->p, 0x2010, o);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2010_1_00141DA0(*o->p, h)) {
    }
}

/* EnemyScr_Event200F_1_00141E10 */

void EnemyScr_Event200F_1_00141E10(A_Enemy_GetScreenSize_0_0013FEB0 *a, s32 a1, f32 x, f32 y, f32 z, f32 w) {
    s32 h;
    u16 p;
    s32 q;
    h = Script_SendEvent_2_00166F80__as_EnemyScr_Event200F_1_00141E10(*a->x4A4, 0x200F, a);
    p = (x < 30000.0f) ? (u16)(u32)x : 30000;

    q = (z < 30000.0f) ? (u16)(u32)z : 30000;
    Script_SetArgU8_1_00165070__as_EnemyScr_Event200F_1_00141E10(*a->x4A4, h, 0, a1);
    Script_SetArgU16_1_001650F0__as_EnemyScr_Event200F_1_00141E10(*a->x4A4, h, 1, p);
    Script_SetArgF32_1_00164FF0__as_EnemyScr_Event200F_1_00141E10(*a->x4A4, h, 2, y);
    Script_SetArgF32_1_00164FF0__as_EnemyScr_Event200F_1_00141E10(*a->x4A4, h, 3, w);
    Script_SetArgU16_1_001650F0__as_EnemyScr_Event200F_1_00141E10(*a->x4A4, h, 4, q);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event200F_1_00141E10(*a->x4A4, h)) {
    }
}

/* EnemyScr_Event200E_1_00142010 */

void EnemyScr_Event200E_1_00142010(Obj_EnemyScr_Event200E_1_00142010 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event200E_1_00142010(*o->p, 0x200E, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event200E_1_00142010(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event200E_1_00142010(*o->p, h)) {
    }
}

/* EnemyScr_Event200DGetStats_1_00142090 */
static inline f32 u2f_EnemyScr_Event2026_1_00140480(u32 x) { return x; }
#define H(a) (*(a)->p)

void EnemyScr_Event200DGetStats_1_00142090(Obj_EnemyScr_Event200DGetStats_1_00142090 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3) {
    s32 id;
    u32 a, b, c, d;
    id = Script_SendEvent_2_00166F80(H(a0), 0x200D, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 1, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 2, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 3, 100);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    a = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event200DGetStats_1_00142090(H(a0), id, 0);
    b = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event200DGetStats_1_00142090(H(a0), id, 1);
    c = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event200DGetStats_1_00142090(H(a0), id, 2);
    d = Script_GetResultU8_1_00164FC0__as_EnemyScr_Event200DGetStats_1_00142090(H(a0), id, 3);
    if (p0) *p0 = u2f_EnemyScr_Event2026_1_00140480(a) / 100.0f;
    if (p1) *p1 = u2f_EnemyScr_Event2026_1_00140480(b) / 100.0f;
    if (p2) *p2 = u2f_EnemyScr_Event2026_1_00140480(c) / 100.0f;
    if (p3) *p3 = u2f_EnemyScr_Event2026_1_00140480(d) / 100.0f;
}

/* EnemyScr_Event200COnHit_1_00142320 */
#define H(a) (*(a)->p)
void EnemyScr_Event200COnHit_1_00142320(Obj_EnemyScr_Event200COnHit_1_00142320 *a0, s32 a1, s32 a2) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x200C, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, a1);
    Script_SetArgU8_1_00165070(H(a0), id, 1, a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    Enemy_Set5D8_1_0013E430(a0, Enemy_GetParam298_1_0013DD40(a0));
    Enemy_IncCounter6B8_1_0013EF50(a0);
}

/* EnemyScr_Event200B_1_001423E0 */

void EnemyScr_Event200B_1_001423E0(Obj_EnemyScr_Event200B_1_001423E0 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event200B_1_001423E0(*o->p, 0x200B, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event200B_1_001423E0(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event200B_1_001423E0(*o->p, h)) {
    }
    Enemy_IncCounter6B9_1_0013EF10(o);
}

/* EnemyScr_Event2009Move_1_00142470 */
#define H(a) (*(a)->p)
u8 EnemyScr_Event2009Move_1_00142470(Obj_EnemyScr_Event2009Move_1_00142470 *a0, s32 a1) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2009, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a1);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2005Turn_1_00142530 */
#define H(a) (*(a)->p)
u8 EnemyScr_Event2005Turn_1_00142530(Obj_EnemyScr_Event2005Turn_1_00142530 *a0, s32 a1) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2005, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a1);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2004Attack_1_001425F0 */
#define H(a) (*(a)->p)

u8 EnemyScr_Event2004Attack_1_001425F0(Obj_EnemyScr_Event2004Attack_1_001425F0 *a0, s32 a1, s32 a2) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2004, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a2);
    Script_SetArgU8_1_00165070(H(a0), id, 2, (u8)a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2003React_1_001426C0 */
#define H(a) (*(a)->p)
u8 EnemyScr_Event2003React_1_001426C0(Obj_EnemyScr_Event2003React_1_001426C0 *a0, s32 a1) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2003, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a1);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2002_1_00142780 */

u8 EnemyScr_Event2002_1_00142780(Obj_EnemyScr_Event2002_1_00142780 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2002_1_00142780(*o->p, 0x2002, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event2002_1_00142780(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2002_1_00142780(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2002_1_00142780(*o->p, h, 0);
}

/* EnemyScr_Event2001_1_00142820 */

u8 EnemyScr_Event2001_1_00142820(Obj_EnemyScr_Event2001_1_00142820 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_Event2001_1_00142820(*o->p, 0x2001, o);
    Script_SetArgU8_1_00165070__as_EnemyScr_Event2001_1_00142820(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_Event2001_1_00142820(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2001_1_00142820(*o->p, h, 0);
}

/* EnemyScr_EventInit_1_001428C0 */

void EnemyScr_EventInit_1_001428C0(Obj_EnemyScr_EventInit_1_001428C0 *o)
{
    s32 h = Script_SendEvent_2_00166F80__as_EnemyScr_EventInit_1_001428C0(*o->p, 0x7FFF, o);
    while ((s8)Script_RunEvent_2_00166C10__as_EnemyScr_EventInit_1_001428C0(*o->p, h)) {
    }
}

/* EnemyScr_GetScriptPath_3_00142930 */
void EnemyScr_GetScriptPath_3_00142930(s32 arg0, void *arg1) {
    s32 temp_16;

    sprintf(arg1, gStrScrChrtestBin_001FAD20);
    temp_16 = arg0 & 0xFF;
    if (temp_16 == 0x15) {
        sprintf(arg1, gStrScrChr0021Bin_001FAD40);
    }
    if (temp_16 == 0x16) {
        sprintf(arg1, gStrScrChr0022Bin_001FAD60);
    }
    if (temp_16 == 0x17) {
        sprintf(arg1, gStrScrChr0023Bin_001FAD80);
    }
    if (temp_16 == 0x18) {
        sprintf(arg1, gStrScrChr0024Bin_001FADA0);
    }
    if (temp_16 == 0x19) {
        sprintf(arg1, gStrScrChr0025Bin_001FADC0);
    }
    if (temp_16 == 0x1A) {
        sprintf(arg1, gStrScrChr0026Bin_001FADE0);
    }
    if (temp_16 == 0x1B) {
        sprintf(arg1, gStrScrChr0027Bin_001FAE00);
    }
    if (temp_16 == 0x1C) {
        sprintf(arg1, gStrScrChr0028Bin_001FAE20);
    }
    if (temp_16 == 0x1D) {
        sprintf(arg1, gStrScrChr0029Bin_001FAE40);
    }
    if (temp_16 == 0x1E) {
        sprintf(arg1, gStrScrChr0030Bin_001FAE60);
    }
    if (temp_16 == 0x1F) {
        sprintf(arg1, gStrScrChr0031Bin_001FAE80);
    }
    if (temp_16 == 0x20) {
        sprintf(arg1, gStrScrChr0032Bin_001FAEA0);
    }
    if (temp_16 == 0x21) {
        sprintf(arg1, gStrScrChr0033Bin_001FAEC0);
    }
    if (temp_16 == 0x22) {
        sprintf(arg1, gStrScrChr0034Bin_001FAEE0);
    }
    if (temp_16 == 0x23) {
        sprintf(arg1, gStrScrChr0035Bin_001FAF00);
    }
    if (temp_16 == 0x24) {
        sprintf(arg1, gStrScrChr0036Bin_001FAF20);
    }
    if (temp_16 == 0x25) {
        sprintf(arg1, gStrScrChr0037Bin_001FAF40);
    }
    if (temp_16 == 0x26) {
        sprintf(arg1, gStrScrChr0038Bin_001FAF60);
    }
    if (temp_16 == 0x27) {
        sprintf(arg1, gStrScrChr0039Bin_001FAF80);
    }
    if (temp_16 == 0x28) {
        sprintf(arg1, gStrScrChr0040Bin_001FAFA0);
    }
    if (temp_16 == 0x29) {
        sprintf(arg1, gStrScrChr0041Bin_001FAFC0);
    }
    if (temp_16 == 0x2A) {
        sprintf(arg1, gStrScrChr0042Bin_001FAFE0);
    }
    if (temp_16 == 0x2B) {
        sprintf(arg1, gStrScrChr0043Bin_001FB000);
    }
    if (temp_16 == 0x2C) {
        sprintf(arg1, gStrScrChr0044Bin_001FB020);
    }
    if (temp_16 == 0x2D) {
        sprintf(arg1, gStrScrChr0045Bin_001FB040);
    }
    if (temp_16 == 0x2E) {
        sprintf(arg1, gStrScrChr0046Bin_001FB060);
    }
    if (temp_16 == 0x2F) {
        sprintf(arg1, gStrScrChr0047Bin_001FB080);
    }
    if (temp_16 == 0x30) {
        sprintf(arg1, gStrScrChr0048Bin_001FB0A0);
    }
    if (temp_16 == 0x31) {
        sprintf(arg1, gStrScrChr0049Bin_001FB0C0);
    }
    if (temp_16 == 0x32) {
        sprintf(arg1, gStrScrChr0050Bin_001FB0E0);
    }
    if (temp_16 == 0x33) {
        sprintf(arg1, gStrScrChr0051Bin_001FB100);
    }
    if (temp_16 == 0x34) {
        sprintf(arg1, gStrScrChr0052Bin_001FB120);
    }
    if (temp_16 == 0x35) {
        sprintf(arg1, gStrScrChr0053Bin_001FB140);
    }
    if (temp_16 == 0x36) {
        sprintf(arg1, gStrScrChr0054Bin_001FB160);
    }
    if (temp_16 == 0x37) {
        sprintf(arg1, gStrScrChr0055Bin_001FB180);
    }
    if (temp_16 == 0x38) {
        sprintf(arg1, gStrScrChr0056Bin_001FB1A0);
    }
    if (temp_16 == 0x39) {
        sprintf(arg1, gStrScrChr0057Bin_001FB1C0);
    }
    if (temp_16 == 0x3A) {
        sprintf(arg1, gStrScrChr0058Bin_001FB1E0);
    }
    if (temp_16 == 0x3B) {
        sprintf(arg1, gStrScrChr0059Bin_001FB200);
    }
    if (temp_16 == 0x3C) {
        sprintf(arg1, gStrScrChr0060Bin_001FB220);
    }
    if (temp_16 == 0x3D) {
        sprintf(arg1, gStrScrChr0061Bin_001FB240);
    }
    if (temp_16 == 0x3E) {
        sprintf(arg1, gStrScrChr0062Bin_001FB260);
    }
    if (temp_16 == 0x3F) {
        sprintf(arg1, gStrScrChr0063Bin_001FB280);
    }
    if (temp_16 == 0x40) {
        sprintf(arg1, gStrScrChr0064Bin_001FB2A0);
    }
    if (temp_16 == 0x41) {
        sprintf(arg1, gStrScrChr0065Bin_001FB2C0);
    }
    if (temp_16 == 0x42) {
        sprintf(arg1, gStrScrChr0066Bin_001FB2E0);
    }
    if (temp_16 == 0x43) {
        sprintf(arg1, gStrScrChr0067Bin_001FB300);
    }
    if (temp_16 == 0x44) {
        sprintf(arg1, gStrScrChr0068Bin_001FB320);
    }
    if (temp_16 == 0x45) {
        sprintf(arg1, gStrScrChr0069Bin_001FB340);
    }
    if (temp_16 == 0x46) {
        sprintf(arg1, gStrScrChr0070Bin_001FB360);
    }
    if (temp_16 == 0x47) {
        sprintf(arg1, gStrScrChr0071Bin_001FB380);
    }
    if (temp_16 == 0x48) {
        sprintf(arg1, gStrScrChr0072Bin_001FB3A0);
    }
    if (temp_16 == 0x49) {
        sprintf(arg1, gStrScrChr0073Bin_001FB3C0);
    }
    if (temp_16 == 0x51) {
        sprintf(arg1, gStrScrChr0081Bin_001FB3E0);
    }
    if (temp_16 == 0x52) {
        sprintf(arg1, gStrScrChr0082Bin_001FB400);
    }
    if (temp_16 == 0x53) {
        sprintf(arg1, gStrScrChr0083Bin_001FB420);
    }
    if (temp_16 == 0x5B) {
        sprintf(arg1, gStrScrChr0091Bin_001FB440);
    }
    if (temp_16 == 0x5C) {
        sprintf(arg1, gStrScrChr0092Bin_001FB460);
    }
    if (temp_16 == 0x5E) {
        sprintf(arg1, gStrScrChr0094Bin_001FB480);
    }
    if (temp_16 == 0x5F) {
        sprintf(arg1, gStrScrChr0095Bin_001FB4A0);
    }
    if (temp_16 == 0x62) {
        sprintf(arg1, gStrScrChr0098Bin_001FB4C0);
    }
    if (temp_16 == 0x65) {
        sprintf(arg1, gStrScrChr0101Bin_001FB4E0);
    }
    if (temp_16 == 0x66) {
        sprintf(arg1, gStrScrChr0102Bin_001FB500);
    }
    if (temp_16 == 0x67) {
        sprintf(arg1, gStrScrChr0103Bin_001FB520);
    }
    if (temp_16 == 0x68) {
        sprintf(arg1, gStrScrChr0104Bin_001FB540);
    }
    if (temp_16 == 0x69) {
        sprintf(arg1, gStrScrChr0105Bin_001FB560);
    }
    if (temp_16 == 0x6B) {
        sprintf(arg1, gStrScrChr0107Bin_001FB580);
    }
    if (temp_16 == 0x6C) {
        sprintf(arg1, gStrScrChr0108Bin_001FB5A0);
    }
    if (temp_16 == 0x6D) {
        sprintf(arg1, gStrScrChr0109Bin_001FB5C0);
    }
    if (temp_16 == 0x6E) {
        sprintf(arg1, gStrScrChr0110Bin_001FB5E0);
    }
    if (temp_16 == 0x76) {
        sprintf(arg1, gStrScrChr0118Bin_001FB600);
    }
    if (temp_16 == 0x77) {
        sprintf(arg1, gStrScrChr0119Bin_001FB620);
    }
    if (temp_16 == 0x78) {
        sprintf(arg1, gStrScrChr0120Bin_001FB640);
    }
    if (temp_16 == 0x7A) {
        sprintf(arg1, gStrScrChr0122Bin_001FB660);
    }
    if (temp_16 == 0x7B) {
        sprintf(arg1, gStrScrChr0123Bin_001FB680);
    }
    if (temp_16 == 0x7C) {
        sprintf(arg1, gStrScrChr0124Bin_001FB6A0);
    }
    if (temp_16 == 0x7D) {
        sprintf(arg1, gStrScrChr0125Bin_001FB6C0);
    }
    if (temp_16 == 0x7E) {
        sprintf(arg1, gStrScrChr0126Bin_001FB6E0);
    }
    if (temp_16 == 0x7F) {
        sprintf(arg1, gStrScrChr0127Bin_001FB700);
    }
    if (temp_16 == 0xBE) {
        sprintf(arg1, gEnemyScriptRodata_001FB720);
    }
    if (temp_16 == 0xBF) {
        sprintf(arg1, gEnemyScriptRodata_001FB720);
    }
    if (temp_16 == 0xC0) {
        sprintf(arg1, gEnemyScriptRodata_001FB720);
    }
    if (temp_16 == 0xC1) {
        sprintf(arg1, gEnemyScriptRodata_001FB720);
    }
    if (arg1 != NULL) {
        M2C_FIELD(arg1, s8 *, 0xB) = 0x42;
    }
}

/* Enemy_PickWaypointToward_1_00143150_ */

/* Enemy_PickWaypointToward_1_00143150 */

void Enemy_PickWaypointToward_1_00143150(void *a, f32 *b, f32 *c)
{
    f32 v[4];
    sceVu0SubVector__as_Enemy_PickWaypointToward_1_00143150(v, c, b);
    Enemy_PickRandomWaypoint_1_001431A0__as_Enemy_PickWaypointToward_1_00143150(a, c);
}

/* Enemy_PickRandomWaypoint_1_001431A0 */

u8 Enemy_PickRandomWaypoint_1_001431A0(T *arg0) {
    u8 buf[16];
    u8 r;
    u8 n;
    u8 i;
    u8 j;
    u8 c;


    r = Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickRandomWaypoint_1_001431A0();
    if (r != 0xFF) {
        buf[0] = r;
        i = 0;

        n = 1;
        for (; i < 0xFF; i++) {
            c = arg0->tbl[r][i];
            if (c != 0xFF) {
                for (j = 0; j < n; j++) {
                    if (buf[j] == c) {
                        break;
                    }
                }
                if (j == n) {
                buf[n++] = c;
            }
            }
        }
        r = buf[(u8)(Rand_Next_3_0015ED20() % n)];
    }
    return r;
}

/* Enemy_PickWaypointDir_1_00143290 */

void Enemy_PickWaypointDir_1_00143290(void *a, f32 *b, f32 *c, s32 d, s32 e)
{
    f32 v[4];
    sceVu0SubVector__as_Enemy_PickWaypointDir_1_00143290(v, c, b);
    Enemy_FindWaypointDir_0_001432F0__as_Enemy_PickWaypointDir_1_00143290(a, v, d, e);
}

/* Enemy_FindWaypointDir_0_001432F0 */
static inline Vec *get_Enemy_FindWaypointDir_0_001432F0(Obj *o, u8 i)
{ Vec *p = &o->tbl[i]; if (o->tbl[i].w <= 0.0f) p = 0; return p; }
static inline u8 inner(Obj *o, Vec *pos, u8 a, u8 b) {
    Vec d;
    Vec e;
    Vec f;
    f32 len;
    f32 w;
    u8 r;
    Vec *p;
    if (a == b) return 1;
    if (a != 0xFF && b != 0xFF) {
    sceVu0SubVector__as_Enemy_FindWaypointDir_0_001432F0(&d, get_Enemy_FindWaypointDir_0_001432F0(o, b), get_Enemy_FindWaypointDir_0_001432F0(o, a));
    sceVu0SubVector__as_Enemy_FindWaypointDir_0_001432F0(&e, pos, get_Enemy_FindWaypointDir_0_001432F0(o, a));
    len = sqrtf(sceVu0InnerProduct__as_Enemy_PickWaypointToward_1_00143150_(&d, &d));
    sceVu0Normalize(&d, &d);
    {
        f32 t = sceVu0InnerProduct__as_Enemy_PickWaypointToward_1_00143150_(&d, &e);
        if (!(t < 0.0f) && t <= len) return 1;
    }
    r = 0;
    if (a != 0xFF) {
        p = get_Enemy_FindWaypointDir_0_001432F0(o, a);
        w = p->w;
        sceVu0SubVector__as_Enemy_FindWaypointDir_0_001432F0(&f, p, pos);
        if (sqrtf(sceVu0InnerProduct__as_Enemy_PickWaypointToward_1_00143150_(&f, &f)) - w < 0.0f) r = 1;
    }
    return r;
    }
    return 1;
}

u8 Enemy_FindWaypointDir_0_001432F0(Obj *o, Vec *pos, u8 a, u8 b)
{ return inner(o, pos, a, b); }

/* Enemy_IsWaypointReachable_0_001434F0 */

u8 Enemy_IsWaypointReachable_0_001434F0(Big *b, Vec *p1, Vec *p2, u8 idx) {
    Vec a;
    Vec d;
    Vec *s;
    f32 r;
    u8 hit;

    sceVu0SubVector__as_Enemy_IsWaypointReachable_0_001434F0(&a, p2, p1);
    hit = 0;
    if (idx != 0xFF) {
        s = &b->s[idx];
        if (b->s[idx].w <= 0.0f) {
            s = NULL;
        }
        r = s->w;
        sceVu0SubVector__as_Enemy_IsWaypointReachable_0_001434F0(&d, s, &a);
        if (sqrtf(sceVu0InnerProduct__as_Enemy_PickWaypointToward_1_00143150_(&d, &d)) - r < 0.0f) {
            hit = 1;
        }
    }
    return hit;
}

/* Enemy_PickNearestWaypointToward_1_001435D0 */

void Enemy_PickNearestWaypointToward_1_001435D0(void *a, f32 *b, f32 *c)
{
    f32 v[4];
    sceVu0SubVector__as_Enemy_PickNearestWaypointToward_1_001435D0(v, c, b);
    Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickNearestWaypointToward_1_001435D0(a, v);
}

/* Enemy_FindNearestWaypoint_1_00143610 */
static inline Vec *get_Enemy_FindNearestWaypoint_1_00143610(Obj *o, u8 i)
{ Vec *p = &o->tbl[i]; if (o->tbl[i].w <= 0.0f) p = 0; return p; }
static inline s32 ok(Obj *o, u8 i) { return o->tbl[i].w > 0.001f; }
static inline u8 next(Obj *o, u8 *it) {
    u8 r = 0xFF;
    u8 i = *it;
    while (i < 0xFF) {
        if (ok(o, i)) {
            r = i++;
            break;
        }
        i++;
    }
    *it = i;
    return r;
}

u8 Enemy_FindNearestWaypoint_1_00143610(Obj *o, Vec *pos) {
    Vec d;
    u8 best;
    u8 it;
    u8 i;
    f32 bd;
    f32 w;
    f32 dist;
    Vec *p;
    best = 0xFF;
    bd = -100000.0f;
    it = 0;
    i = next(o, &it);
    while (i != 0xFF) {
        p = get_Enemy_FindNearestWaypoint_1_00143610(o, i);
        w = p->w;
        sceVu0SubVector__as_Enemy_FindNearestWaypoint_1_00143610(&d, p, pos);
        dist = sqrtf(sceVu0InnerProduct__as_Enemy_PickWaypointToward_1_00143150_(&d, &d)) - w;
        if (best == 0xFF || dist < bd) {
            best = i;
            bd = dist;
        }
        i = next(o, &it);
    }
    return best;
}
#undef sceVu0CopyVector
#undef Enemy_GetMotionId_0_0013ED20
#undef Ent_GetTypeByte_1_0013E220

/* Waypoint_GetLink_0_00143810 */
/* Waypoint_GetLink_0_00143810 */
u8 Waypoint_GetLink_0_00143810(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_2;
    s32 temp_3;

    temp_2 = arg1 & 0xFF;
    temp_3 = arg2 & 0xFF;
    if (temp_2 == temp_3) {
        return 0xFFU;
    }
    return M2C_FIELD((temp_3 + ((temp_2 << 8) + arg0)), u8 *, 0x10);
}

/* Waypoint_Get_0_00143840 */
s32 Waypoint_Get_0_00143840(s32 arg0, s32 arg1) {
    s32 var_v0;
    s8 *temp_v1;

    temp_v1 = (signed char *)(arg0 + ((arg1 & 0xFF) * 0x10));
    var_v0 = (int)(temp_v1 + 0x10010);
    if (M2C_FIELD(temp_v1, f32 *, 0x1001C) <= 0.0f) {
        var_v0 = 0;
    }
    return var_v0;
}

/* EnemyCmd_Nop_1_00143890 */
#define Enemy_Ptr700_1_0013FF90 Enemy_Ptr700_1_0013FF90__as_EnemyCmd_Nop_1_00143890
Vec* Enemy_Ptr700_1_0013FF90__as_EnemyCmd_Nop_1_00143890(s8 *);
#define Enemy_Ptr6E0_1_0013FFB0 Enemy_Ptr6E0_1_0013FFB0__as_EnemyCmd_Nop_1_00143890
Vec* Enemy_Ptr6E0_1_0013FFB0__as_EnemyCmd_Nop_1_00143890(s8 *);
#define Enemy_PtrVec660_1_00140340 Enemy_PtrVec660_1_00140340__as_EnemyCmd_Nop_1_00143890
Vec* Enemy_PtrVec660_1_00140340__as_EnemyCmd_Nop_1_00143890(s8 *);
#define Enemy_GetPositionPtr_2_00140460 Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_Nop_1_00143890
Vec* Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_Nop_1_00143890(s8 *);
#define Enemy_GetForwardVector_2_001403D0 Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_Nop_1_00143890
void Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_Nop_1_00143890(s8 *, Vec *, s8 *);
#define Enemy_GetRightVector_1_00140360 Enemy_GetRightVector_1_00140360__as_EnemyCmd_Nop_1_00143890
void Enemy_GetRightVector_1_00140360__as_EnemyCmd_Nop_1_00143890(void *, Vec*);
#define Enemy_GetMotionFrame_0_0013ECA0 Enemy_GetMotionFrame_0_0013ECA0__as_EnemyCmd_Nop_1_00143890
s8 Enemy_GetMotionFrame_0_0013ECA0__as_EnemyCmd_Nop_1_00143890(void *p);
#define Enemy_CopyVec660_1_00140350 Enemy_CopyVec660_1_00140350__as_EnemyCmd_Nop_1_00143890
void Enemy_CopyVec660_1_00140350__as_EnemyCmd_Nop_1_00143890(void *p, f32 *v);
#define Enemy_GetTargetHandle_0_0013EDE0 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_Nop_1_00143890
s32 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_Nop_1_00143890(s8 *);
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_EnemyCmd_Nop_1_00143890
s32 Ent_IsNull0_1_0013EE30__as_EnemyCmd_Nop_1_00143890(s8 *);
#define Enemy_CopyPosition_2_00140470 Enemy_CopyPosition_2_00140470__as_EnemyCmd_Nop_1_00143890
void Enemy_CopyPosition_2_00140470__as_EnemyCmd_Nop_1_00143890(void *, void *);
#define Enemy_GetRotationPtr_1_00140430 Enemy_GetRotationPtr_1_00140430__as_EnemyCmd_Nop_1_00143890
Vec* Enemy_GetRotationPtr_1_00140430__as_EnemyCmd_Nop_1_00143890(s8 *);
#define sceVu0SubVector sceVu0SubVector__as_EnemyCmd_Nop_1_00143890
void sceVu0SubVector__as_EnemyCmd_Nop_1_00143890(Vec *, void *, void *);
#define EnemyScr_BroadcastMotionEvent_0_00140F90 EnemyScr_BroadcastMotionEvent_0_00140F90__as_EnemyCmd_Nop_1_00143890
void EnemyScr_BroadcastMotionEvent_0_00140F90__as_EnemyCmd_Nop_1_00143890(u8 x, u8 a, u8 y, u8 b);
#define Ent_GetTypeByte_1_0013E220 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_Nop_1_00143890
s32 Ent_GetTypeByte_1_0013E220__as_EnemyCmd_Nop_1_00143890(O_EnemyCmd_Nop_1_00143890 *);
#define Enemy_CopyRotation_2_00140440 Enemy_CopyRotation_2_00140440__as_EnemyCmd_Nop_1_00143890
void Enemy_CopyRotation_2_00140440__as_EnemyCmd_Nop_1_00143890(void *, Vec*);
#define EnemyScr_BroadcastFrameEvent_0_001410C0 EnemyScr_BroadcastFrameEvent_0_001410C0__as_EnemyCmd_Nop_1_00143890
void EnemyScr_BroadcastFrameEvent_0_001410C0__as_EnemyCmd_Nop_1_00143890(u8 x, u8 a, u8 y, u8 b);
#define Enemy_Ptr6F0_1_0013FFA0 Enemy_Ptr6F0_1_0013FFA0__as_EnemyCmd_Nop_1_00143890
f32* Enemy_Ptr6F0_1_0013FFA0__as_EnemyCmd_Nop_1_00143890(s32, S_EnemyCmd_PlaySe_1_001453A0 *);

/* EnemyCmd_Nop_1_00143890 */
void EnemyCmd_Nop_1_00143890(void) {

}

/* EnemyCmd_Set5B5b7_1_001438A0 */
void EnemyCmd_Set5B5b7_1_001438A0(void) {
    Enemy_Set5B5b7_1_0013E950(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_GetFlag_0_001438B0 */
void EnemyCmd_GetFlag_0_001438B0(Obj_EnemyCmd_GetFlag_0_001438B0 *o)
{
    u16 v = o->h;
    s8 *q = Script_GetArgPtr_2_00165130(o, 1);
    *q = Save_TestItemBit_1_001A9B40(v);
}

/* EnemyCmd_GetGlobal_0_001438F0 */

void EnemyCmd_GetGlobal_0_001438F0(s32 a)
{
    s8 *p = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetGlobal_0_001438F0(a, 0);
    *p = Save_GetByte2E_0_001AA740();
}

/* EnemyCmd_Set5B4b6_1_00143920 */
void EnemyCmd_Set5B4b6_1_00143920(u8 *arg0) { Enemy_Set5B4b6_1_0013E490(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B4b6_1_00143920->p, arg0[8]); }

/* EnemyCmd_Set5B4b5_1_00143930 */

void EnemyCmd_Set5B4b5_1_00143930(u8 *arg0)
{
    Enemy_Set5B4b5_1_0013E4B0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B4b5_1_00143930->p, arg0[8]);
}

/* EnemyCmd_Set5B8_1_00143940 */
void EnemyCmd_Set5B8_1_00143940(void *arg0) {
    Enemy_Set5B8_1_0013E480(M2C_FIELD(gEnemyScriptSbss_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, f32 *, 8));
}

/* EnemyCmd_Set60B_1_00143950 */
void EnemyCmd_Set60B_1_00143950(void *arg0) {
    Enemy_Set60B_1_0013E250(M2C_FIELD(gEnemyScriptSbss_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, u8 *, 8));
}

/* EnemyCmd_GetRelativePos_0_00143960 */

void EnemyCmd_GetRelativePos_0_00143960(Arg_EnemyCmd_GetRelativePos_0_00143960 *arg0) {
    V3 d;
    Vec t;
    s8 *o;
    s8 *g;
    u8 type;

    g = gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetRelativePos_0_00143960;
    type = arg0->type;
    o = *(s8 **)(g + 0x154);
    d.x = arg0->a;
    d.y = arg0->b;
    d.z = arg0->c;
    d.w = 0;
    switch (type) {
    case 0:
        sceVu0CopyVector__as_EnemyCmd_GetRelativePos_0_00143960(Enemy_Ptr700_1_0013FF90(o), Enemy_Ptr6E0_1_0013FFB0(o));
        break;
    case 1:
        sceVu0AddVector(Enemy_Ptr700_1_0013FF90(o), Enemy_PtrVec660_1_00140340(o), &d);
        break;
    case 2: {
        Vec v = {0};
        Enemy_GetForwardVector_2_001403D0(o, &t, g);
        v.x += t.x * d.x;
        v.z += t.z * d.x;
        v.y += d.y;
        Enemy_GetRightVector_1_00140360__as_EnemyCmd_GetRelativePos_0_00143960(o, &t);
        v.x += t.x * d.z;
        v.z += t.z * d.z;
        sceVu0AddVector(Enemy_Ptr700_1_0013FF90(o), Enemy_GetPositionPtr_2_00140460(o), &v);
        break;
    }
    }
}

/* EnemyCmd_Get608_1_00143B20 */

void EnemyCmd_Get608_1_00143B20(s32 a)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_Get608_1_00143B20->p;
    s8 *q = Script_GetArgPtr_2_00165130__as_EnemyCmd_Get608_1_00143B20(a, 0);
    *q = Enemy_Get608_1_0013E290(p);
}

/* EnemyCmd_GetPlayerValue_0_00143B60 */

void EnemyCmd_GetPlayerValue_0_00143B60(s32 a)
{
    s8 *p = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPlayerValue_0_00143B60(a, 0);
    *p = Player_GetFlag521b5_1_00145620();
}

/* EnemyCmd_SelectMotion_1_00143B90 */
void EnemyCmd_SelectMotion_1_00143B90(void *arg0) {
    Enemy_SelectMotion_0_0013C420(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (s64) M2C_FIELD(arg0, s16 *, 0x10), 2);
}

/* EnemyCmd_Set5A1b5_1_00143BB0 */

void EnemyCmd_Set5A1b5_1_00143BB0(u8 *arg0)
{
    Enemy_Set5A1b5_1_0013EE90(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5A1b5_1_00143BB0->p, arg0[8]);
}

/* EnemyCmd_Set5B4b4_1_00143BC0 */

void EnemyCmd_Set5B4b4_1_00143BC0(u8 *arg0)
{
    Enemy_Set5B4b4_1_0013E5F0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B4b4_1_00143BC0->p, arg0[8]);
}

/* EnemyCmd_StartTimer_0_00143BD0 */

void EnemyCmd_StartTimer_0_00143BD0(Obj_EnemyCmd_StartTimer_0_00143BD0 *o)
{
    f32 f = o->f;
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_StartTimer_0_00143BD0->p;
    Enemy_Set5B4b3_1_0013E620(p, 1);
    Enemy_Set5C8_1_0013E450(p, f);
    Enemy_Set5C0_1_0013E470(p, 0.0f);
}

/* EnemyCmd_GetMotionFrame_1_00143C30 */

void EnemyCmd_GetMotionFrame_1_00143C30(s32 a)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetMotionFrame_1_00143C30->p;
    s8 *q = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetMotionFrame_1_00143C30(a, 0);
    *q = Enemy_GetMotionFrame_0_0013ECA0(p);
}

/* EnemyCmd_ResolveHit_0_00143C70 */

void EnemyCmd_ResolveHit_0_00143C70(u8 *o)
{
    s32 h = gEnemyScriptSbss_00201FA8__as_EnemyCmd_ResolveHit_0_00143C70->p;
    u8 m = o[8];
    void *p = Script_GetArgPtr_2_00165130__as_EnemyCmd_ResolveHit_0_00143C70(o, 1);
    void *q = Script_GetArgPtr_2_00165130__as_EnemyCmd_ResolveHit_0_00143C70(o, 2);
    void *r = Script_GetArgPtr_2_00165130__as_EnemyCmd_ResolveHit_0_00143C70(o, 3);
    Combat_ResolveHit_1_00135E30(h, m, p, q, r, Script_GetArgPtr_2_00165130__as_EnemyCmd_ResolveHit_0_00143C70(o, 4));
}

/* EnemyCmd_SetPartValue_1_00143D10 */
void EnemyCmd_SetPartValue_1_00143D10(void *arg0) {
    Enemy_SetPartValue_1_0013E3F0(M2C_FIELD(gEnemyScriptSbss_00201FA8, s32 *, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (M2C_FIELD(arg0, u8 *, 0x10) | ((M2C_FIELD(arg0, u8 *, 0x18) * 8) | ((M2C_FIELD(arg0, u8 *, 0x20) << 6) | ((M2C_FIELD(arg0, u8 *, 0x30) << 0xA) | (M2C_FIELD(arg0, u8 *, 0x28) << 9))))) & 0xFFFF);
}

/* EnemyCmd_GetVec660_0_00143D60 */

void EnemyCmd_GetVec660_0_00143D60(void *o)
{
    void *q = gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetVec660_0_00143D60->p;
    f32 *x = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetVec660_0_00143D60(o, 0);
    f32 *y = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetVec660_0_00143D60(o, 1);
    f32 *z = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetVec660_0_00143D60(o, 2);
    f32 v[4];
    Enemy_CopyVec660_1_00140350(q, v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}

/* EnemyCmd_UpdatePartStat_1_00143DF0 */

void EnemyCmd_UpdatePartStat_1_00143DF0(u8 *arg0)
{
    Enemy_UpdatePartStat_0_0013F0C0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_UpdatePartStat_1_00143DF0->p, arg0[8]);
}

/* EnemyCmd_LoadPart_1_00143E00 */
void EnemyCmd_LoadPart_1_00143E00(void *arg0) {
    Enemy_LoadPartWrap_0_0013F0B0(M2C_FIELD(gEnemyScriptSbss_00201FA8, s32 *, 0x154), M2C_FIELD(arg0, u8 *, 8));
}

/* EnemyCmd_InitPart_1_00143E10 */

void EnemyCmd_InitPart_1_00143E10(u8 *arg0)
{
    Enemy_InitPart_1_0013F1B0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_InitPart_1_00143E10->p, arg0[8]);
}

/* EnemyCmd_FindTargetInCone_0_00143E20 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void EnemyCmd_FindTargetInCone_0_00143E20(s8 *a0, s32 a1, u8 a2, s32 a3, s32 t0, s32 t1, f32 ang) {
    u8 k;
    s8 *cur;
    s32 it;
    Vec m;
    Vec p;
    Hit r;
    Seg b;
    QP q1;
    QP q2;
    f32 t;
    u8 n;
    u8 i;
    f32 fz;
    f32 fx;

    k = Enemy_GetTargetHandle_0_0013EDE0(a0);
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    if (cur != NULL) {
        do {
            if (Ent_IsNull0_1_0013EE30(cur) == 0 && Enemy_GetTargetHandle_0_0013EDE0(cur) == k && (u8)Enemy_GetMotionId_0_0013ED20__as_EnemyCmd_FindTargetInCone_0_00143E20(cur) == a2) {
                Enemy_CopyPosition_2_00140470__as_EnemyCmd_FindTargetInCone_0_00143E20(a0, &p);
                Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_FindTargetInCone_0_00143E20(a0, &m);
                p.x += m.x * t1;
                p.z += m.z * t1;
                p.x -= m.z * a3;
                p.z += m.x * a3;
                p.y -= t0;
                sceVu0CopyVector__as_EnemyCmd_FindTargetInCone_0_00143E20(&b.s, Enemy_GetPositionPtr_2_00140460(a0));
                b.s.y -= 100.0f;
                b.s.w = 1.0f;
                sceVu0CopyVector__as_EnemyCmd_FindTargetInCone_0_00143E20(&b.e, &p);
                b.e.w = 1.0f;
                memset(&r, 0, 0x40);
                if (((s32 **)&gMapSbss_00201E80)[2] != NULL) {
                    Enemy_RaycastMapC_0_0013D430(*((s32 **)&gMapSbss_00201E80)[2], &r, &b, 6, 3);
                }
                if (r.hit == 0 && ((s32 **)&gMapSbss_00201E80)[3] != NULL) {
                    Enemy_RaycastMapC_0_0013D430(*((s32 **)&gMapSbss_00201E80)[3], &r, &b, 6, 3);
                }
                if (r.hit != 0) {
                    sceVu0SubVector(&p, &r, &b);
                    sceVu0ScaleVector(0.9f, &p, &p);
                    sceVu0AddVector(&p, &p, &b);
                }
                n = Enemy_Get81_1_0013FC00(cur);
                for (i = 0; i < n; i++) {
                    q1.p = NULL;
                    q2.p = NULL;
                    Enemy_GetCollider_0_0013FB90(cur, i, &q1, &q2);
                    if (q1.p != NULL) q1.p->xC = -100.0f;
                    if (q2.p != NULL) q2.p->xC = -100.0f;
                }
                sceVu0CopyVector__as_EnemyCmd_FindTargetInCone_0_00143E20(Enemy_GetPositionPtr_2_00140460(cur), &p);
                sceVu0CopyVector__as_EnemyCmd_FindTargetInCone_0_00143E20((Vec *)(*(s8 **)(cur + 0x518) + 0x1C0), &p);
                t = ang + Enemy_GetRotationPtr_1_00140430(a0)->y;
                Enemy_GetRotationPtr_1_00140430(cur)->y = WRAP(t);
                return;
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
}

/* EnemyCmd_GetTargetPos_0_001441B0 */

void EnemyCmd_GetTargetPos_0_001441B0(s8 *arg0) {
    s32 type;
    s32 b;
    s32 x, y, z;
    s8 *obj;
    s8 *p;
    f32 f;

    type = M2C_FIELD(arg0, u8 *, 8);
    b = M2C_FIELD(arg0, u8 *, 0x10);
    x = M2C_FIELD(arg0, s16 *, 0x18);
    y = M2C_FIELD(arg0, s16 *, 0x20);
    z = M2C_FIELD(arg0, s16 *, 0x28);
    obj = M2C_FIELD(gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetTargetPos_0_001441B0, s8 **, 0x154);
    f = M2C_FIELD(arg0, f32 *, 0x30);
    if (type == 0) {
        EnemyCmd_FindTargetInCone_0_00143E20__as_EnemyCmd_GetTargetPos_0_001441B0(obj, type, b, x, y, z, f);
    } else if (type == 1) {
        p = Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_GetTargetPos_0_001441B0(obj);
        M2C_FIELD(p, f32 *, 0) += x;
        M2C_FIELD(p, f32 *, 4) += y;
        M2C_FIELD(p, f32 *, 8) += z;
        sceVu0CopyVector__as_EnemyCmd_GetTargetPos_0_001441B0(M2C_FIELD(obj, s8 **, 0x518) + 0x1C0, p);
    } else if (type == 2) {
        p = Enemy_PtrVec660_1_00140340__as_EnemyCmd_GetTargetPos_0_001441B0(obj);
        M2C_FIELD(p, f32 *, 0) += x;
        M2C_FIELD(p, f32 *, 4) += y;
        M2C_FIELD(p, f32 *, 8) += z;
    }
}

/* EnemyCmd_BroadcastMotion_1_001442F0 */

void EnemyCmd_BroadcastMotion_1_001442F0(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_BroadcastMotion_1_001442F0->p;
    u8 x = Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastMotion_1_001442F0(p);
    EnemyScr_BroadcastMotionEvent_0_00140F90(x, a, (u8)Enemy_GetMotionId_0_0013ED20(p), b);
}

/* EnemyCmd_Kill_1_00144360 */

void EnemyCmd_Kill_1_00144360(u8 *arg0)
{
    Enemy_Kill_1_0013EF80(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Kill_1_00144360->p, arg0[8]);
}

/* EnemyCmd_SetHiddenFlags_0_00144370 */

void EnemyCmd_SetHiddenFlags_0_00144370(u8 *o)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_SetHiddenFlags_0_00144370->p;
    u8 a = o[8];
    u8 b = o[0x10];
    if (a)
        Enemy_Set5B3b6_1_0013E710(p, 1);
    if (b)
        Enemy_Set5B6b1_1_0013E6F0(p, 1);
}

/* EnemyCmd_ReturnToTitle_1_001443D0 */
void EnemyCmd_ReturnToTitle_1_001443D0(void) {
    Game_RequestTitle_0_0012C040();
}

/* EnemyCmd_Set5B2b6w2_1_001443E0 */

void EnemyCmd_Set5B2b6w2_1_001443E0(u8 *arg0)
{
    Enemy_Set5B2b6w2_1_0013E730(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b6w2_1_001443E0->p, arg0[8]);
}

/* EnemyCmd_Set5B2b2_1_001443F0 */

void EnemyCmd_Set5B2b2_1_001443F0(u8 *arg0)
{
    Enemy_Set5B2b2_1_0013E840(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b2_1_001443F0->p, arg0[8]);
}

/* EnemyCmd_Set5B2b1_1_00144400 */

void EnemyCmd_Set5B2b1_1_00144400(u8 *arg0)
{
    Enemy_Set5B2b1_1_0013E860(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b1_1_00144400->p, arg0[8]);
}

/* EnemyCmd_Set5B0b2_1_00144410 */

void EnemyCmd_Set5B0b2_1_00144410(u8 *arg0)
{
    Enemy_Set5B0b2_1_0013EBF0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b2_1_00144410->p, arg0[8]);
}

/* EnemyCmd_ClampHpFromFlag_1_00144420 */
void EnemyCmd_ClampHpFromFlag_1_00144420(u8 *o) {
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_ClampHpFromFlag_1_00144420->p;
    u16 a = GameFlag_GetHalf_0_0013D560(o[8], o[0x10]);
    u16 b = Enemy_GetHp_2_0013F750(p);
    if (a < b && a > 0) {
        Enemy_AddHp_2_0013F710(p, a - b);
    }
}

/* EnemyCmd_StoreHpToFlag_1_00144490 */

void EnemyCmd_StoreHpToFlag_1_00144490(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    GameFlag_GetWordWrap_0_0013D540(a, b, Enemy_GetHp_2_0013F750__as_EnemyCmd_StoreHpToFlag_1_00144490(gEnemyScriptSbss_00201FA8__as_EnemyCmd_StoreHpToFlag_1_00144490->p));
}

/* EnemyCmd_Set5B1b4_1_001444E0 */
void EnemyCmd_Set5B1b4_1_001444E0(void) {
    Enemy_Set5B1b4IfUnlocked_0_0013E980(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_FindSpawnPoint_0_001444F0 */

void EnemyCmd_FindSpawnPoint_0_001444F0(Msg *m) {
    u8 list[8];
    Buf buf;
    Vec B;
    Vec A_EnemyCmd_Nop_1_00143890;
    f32 f20;
    u8 mask;
    f32 f21;
    u16 id;
    O_EnemyCmd_Nop_1_00143890 *o;
    u8 *res;
    T_EnemyCmd_FindSpawnPoint_0_001444F0 *e;
    u16 best;
    u8 n;
    u8 i;
    u8 ok;
    u8 r;
    u8 *p;
    u8 flag;

    f20 = m->x18;
    mask = m->x8;
    f21 = m->x20;
    id = m->x10;
    o = *(O_EnemyCmd_Nop_1_00143890 **)(gEnemyScriptSbss_00201FA8__as_EnemyCmd_FindSpawnPoint_0_001444F0 + 0x154);
    res = Script_GetArgPtr_2_00165130__as_EnemyCmd_FindSpawnPoint_0_001444F0(m, 4);
    e = Enemy_GetParamPtr10_1_0013E070(o);
    best = 0xFFFF;
    n = 0;
    *res = 0xFF;
    o->x5FC[0] = 0;
    o->x5FC[1] = 0;
    o->x5FC[2] = 0;
    o->x5FC[3] = 0;
    o->x5FC[4] = 0;
    o->x5FC[5] = 0;
    o->x5FC[6] = 0;
    o->x604 = id;
    if (mask == 0) return;
    for (i = 0; i < 7; i++) {
        if (mask & (1 << i)) {
            o->x5FC[i] |= 1;
            if (!(o->x5E0[i] <= f21)) {
                o->x5E0[i] -= f21;
            } else {
                o->x5E0[i] = 0.0f;
            }
        }
    }
    if (Enemy_Get5B0b7_1_0013EB60(o) != 0) return;
    if (Enemy_Get5B1b5_1_0013E940(o) != 0) return;
    for (i = 0; i < 7; i++) {
        if (mask & 1) {
            ok = 0;
            p = &o->x5FC[i];
            *p |= 1;
            if (id < e->x36 && !(id < e->x34)) {
                if (!(f20 <= cosf(3.1415927f * (e->x38 / 180.0f)))) {
                    *p |= 2;
                    if (o->x5E0[i] == 0.0f) {
                        o->x5E0[i] = e->x3B / 10.0f;
                        ok = 1;
                    }
                }
            }
            if (ok) {
                r = Rand_Range_3_0013D500(100);
                if (r <= e->x3A) {
                if (best > e->x39) {
                    list[0] = i;
                    best = e->x39;
                    n = 1;
                } else if (best == e->x39) {
                    list[n++] = i;
                }
                }
            }
        }
        mask >>= 1;
        e++;
    }
    if (n) {
        *res = list[(u8)Rand_Range_3_0013D500(n - 1)];
    } else {
        *res = 0xFF;
    }
    if (*res == 0xFF) return;
    flag = 1;
    if ((u8)Ent_GetTypeByte_1_0013E220(o) == 0x69) flag = 0;
    if (!flag) return;
    if (!Enemy_Get5B6b4_1_0013EAA0(o)) return;
    sceVu0CopyVector__as_EnemyCmd_FindSpawnPoint_0_001444F0(&A_EnemyCmd_Nop_1_00143890, Enemy_GetPositionPtr_2_00140460__as_EnemyCmd_FindSpawnPoint_0_001444F0(o));
    A_EnemyCmd_Nop_1_00143890.y -= 100.0f;
    A_EnemyCmd_Nop_1_00143890.w = 1.0f;
    sceVu0CopyVector__as_EnemyCmd_FindSpawnPoint_0_001444F0(&B, Player_GetBody_1_00145770());
    B.w = 1.0f;
    memset(&buf, 0, 0x40);
    if ((&gMapSbss_00201E80)[2]) Enemy_RaycastMapB_0_0013D320(*(s32 *)(&gMapSbss_00201E80)[2], &buf, &A_EnemyCmd_Nop_1_00143890, 6, 7);
    if (buf.x24 == 0 && (&gMapSbss_00201E80)[3]) Enemy_RaycastMapB_0_0013D320(*(s32 *)(&gMapSbss_00201E80)[3], &buf, &A_EnemyCmd_Nop_1_00143890, 6, 7);
    if (buf.x24) *res = 0xFF;
}

/* EnemyCmd_Set5B2b4_1_00144960 */
void EnemyCmd_Set5B2b4_1_00144960(void) {
    Enemy_Set5B2b4_1_0013E790(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_GetPosition_2_00144970 */

void EnemyCmd_GetPosition_2_00144970(void *o)
{
    void *q = gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetPosition_2_00144970->p;
    f32 *x = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPosition_2_00144970(o, 0);
    f32 *y = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPosition_2_00144970(o, 1);
    f32 *z = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetPosition_2_00144970(o, 2);
    f32 v[4];
    Enemy_CopyPosition_2_00140470__as_EnemyCmd_GetPosition_2_00144970(q, v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}

/* EnemyCmd_SpawnEffect_0_00144A00 */

void EnemyCmd_SpawnEffect_0_00144A00(s8 *a0) {
    Vec A_EnemyCmd_Nop_1_00143890;
    Vec B;
    Vec C_EnemyCmd_Nop_1_00143890;
    s8 *o = *(s8 **)(gEnemyScriptSbss_00201FA8__as_EnemyCmd_SpawnEffect_0_00144A00 + 0x154);
    u16 id = *(u16 *)(a0 + 8);
    s32 k = *(u8 *)(a0 + 0x10);
    s8 *res = Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffect_0_00144A00(a0, 2);
    f32 f1 = *(f32 *)(a0 + 0x20);
    f32 f2 = *(f32 *)(a0 + 0x28);
    f32 f3 = *(f32 *)(a0 + 0x30);
    s8 r = Player_ThrowItem_0_001CA960();
    if (r == -1) {
        Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffect_0_00144A00(o, &A_EnemyCmd_Nop_1_00143890);
        Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffect_0_00144A00(o, &B);
        A_EnemyCmd_Nop_1_00143890.x = A_EnemyCmd_Nop_1_00143890.x + B.x * f1;
        A_EnemyCmd_Nop_1_00143890.z = A_EnemyCmd_Nop_1_00143890.z + B.z * f1;
        A_EnemyCmd_Nop_1_00143890.y = A_EnemyCmd_Nop_1_00143890.y + f2;
        Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffect_0_00144A00(o, &B);
        A_EnemyCmd_Nop_1_00143890.x = A_EnemyCmd_Nop_1_00143890.x + B.x * f3;
        A_EnemyCmd_Nop_1_00143890.z = A_EnemyCmd_Nop_1_00143890.z + B.z * f3;
        Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffect_0_00144A00(o, &C_EnemyCmd_Nop_1_00143890);
        r = Player_HoldItem_0_001CAB20(id, k, &A_EnemyCmd_Nop_1_00143890, &C_EnemyCmd_Nop_1_00143890);
    }
    if (r == 0) {
        *res = 0;
    } else {
        *res = 1;
    }
}

/* EnemyCmd_StopEffect_0_00144B80 */
void EnemyCmd_StopEffect_0_00144B80(u16 *a0) {
    u16 v;
    u8 *p;
    u8 b;
    v = a0[4];
    p = Script_GetArgPtr_2_00165130__as_EnemyCmd_StopEffect_0_00144B80((s32)a0, 1);
    b = Inventory_GetEntry_1_001CC3F0(v)->x2;
    if (b > 0x80) {
        *p = 0x80;
        return;
    }
    *p = b;
}

/* EnemyCmd_SpawnEffectB_0_00144BE0 */

void EnemyCmd_SpawnEffectB_0_00144BE0(Arg_EnemyCmd_SpawnEffectB_0_00144BE0 *a0) {
    char *pl = *(char **)(gEnemyScriptSbss_00201FA8__as_EnemyCmd_SpawnEffectB_0_00144BE0 + 0x154);
    u16 n = a0->x8;
    u8 *out = Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnEffectB_0_00144BE0(a0, 1);
    f32 f22 = a0->x18;
    f32 f21 = a0->x20;
    f32 f20 = a0->x28;
    s8 r = Player_DropItem_0_001CAC30();
    if (r == -1) {
        Vec p;
        Vec d;
        Vec q;
        Enemy_CopyPosition_2_00140470__as_EnemyCmd_SpawnEffectB_0_00144BE0(pl, &p);
        Enemy_GetForwardVector_2_001403D0__as_EnemyCmd_SpawnEffectB_0_00144BE0(pl, &d);
        p.x += d.x * f22;
        p.z += d.z * f22;
        p.y += f21;
        Enemy_GetRightVector_1_00140360__as_EnemyCmd_SpawnEffectB_0_00144BE0(pl, &d);
        p.x += d.x * f20;
        p.z += d.z * f20;
        Enemy_CopyRotation_2_00140440__as_EnemyCmd_SpawnEffectB_0_00144BE0(pl, &q);
        r = Player_PlaceItem_0_001CADF0(n, &p, &q, 0);
    }
    if (r == 0) {
        *out = 0;
    } else {
        *out = 1;
    }
}

/* EnemyCmd_ResetState_1_00144D50 */
void EnemyCmd_ResetState_1_00144D50(void) {
    Enemy_SetStateResetTimer_1_0013E7E0(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B3b3_1_00144D60 */
void EnemyCmd_Set5B3b3_1_00144D60(void) {
    Enemy_Set5B3b3_1_0013E7C0(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B2b0_1_00144D70 */

void EnemyCmd_Set5B2b0_1_00144D70(u8 *arg0)
{
    Enemy_Set5B2b0_1_0013E890(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B2b0_1_00144D70->p, arg0[8]);
}

/* EnemyCmd_BroadcastFrame_1_00144D80 */

void EnemyCmd_BroadcastFrame_1_00144D80(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_BroadcastFrame_1_00144D80->p;
    u8 x = Enemy_GetTargetHandle_0_0013EDE0__as_EnemyCmd_BroadcastFrame_1_00144D80(p);
    EnemyScr_BroadcastFrameEvent_0_001410C0(x, a, (u8)Enemy_GetMotionId_0_0013ED20(p), b);
}

/* EnemyCmd_Set5B1b7_1_00144DF0 */

void EnemyCmd_Set5B1b7_1_00144DF0(u8 *arg0)
{
    Enemy_Set5B1b7_1_0013E8C0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b7_1_00144DF0->p, arg0[8]);
}

/* EnemyCmd_Set5B1b6_1_00144E00 */

void EnemyCmd_Set5B1b6_1_00144E00(u8 *arg0)
{
    Enemy_Set5B1b6_1_0013E8F0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b6_1_00144E00->p, arg0[8]);
}

/* EnemyCmd_BreakPart_1_00144E10 */

void EnemyCmd_BreakPart_1_00144E10(u8 *arg0)
{
    Enemy_BreakPart_0_0013F210(gEnemyScriptSbss_00201FA8__as_EnemyCmd_BreakPart_1_00144E10->p, arg0[8], 1);
}

/* EnemyCmd_Set5B0b0_1_00144E30 */

void EnemyCmd_Set5B0b0_1_00144E30(u8 *arg0)
{
    Enemy_Set5B0b0_1_0013EC30(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b0_1_00144E30->p, arg0[8]);
}

/* EnemyCmd_HealPercent_1_00144E40 */
void EnemyCmd_HealPercent_1_00144E40(u8 *o) {
    void *p;
    u8 pct;
    u16 hp;
    pct = o[8];
    p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_HealPercent_1_00144E40->p;
    hp = Enemy_GetMaxHp_2_0013F700(p);
    Enemy_AddHp_2_0013F710__as_EnemyCmd_HealPercent_1_00144E40(p, -hp);
    if (pct > 100) pct = 100;
    Enemy_AddHp_2_0013F710__as_EnemyCmd_HealPercent_1_00144E40(p, hp * pct / 100);
}

/* EnemyCmd_Set5B1b5_1_00144EE0 */
void EnemyCmd_Set5B1b5_1_00144EE0(void) {
    Enemy_Set5B1b5_1_0013E920(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B1b3_1_00144EF0 */
void EnemyCmd_Set5B1b3_1_00144EF0(void) {
    Enemy_Set5B1b3IfUnlocked_1_0013E9D0(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 1);
}

/* EnemyCmd_Set5B1b2Notify_0_00144F00 */

void EnemyCmd_Set5B1b2Notify_0_00144F00(unsigned char *a)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b2Notify_0_00144F00->p;
    int v = a[8];
    if (!(unsigned char)Enemy_Get5B1b2_1_0013EA40(p) && v)
        Msg_Close_1_0018B0C0();
    Enemy_Set5B1b2_1_0013EA20(p, v);
}

/* EnemyCmd_GetParamIdx_1_00144F60 */

void EnemyCmd_GetParamIdx_1_00144F60(s32 a)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetParamIdx_1_00144F60->p;
    s16 *q = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetParamIdx_1_00144F60(a, 0);
    *q = Enemy_GetCurrentParamIdx_0_0013E110(p);
}

/* EnemyCmd_Set5B1b1_1_00144FA0 */

void EnemyCmd_Set5B1b1_1_00144FA0(u8 *arg0)
{
    Enemy_Set5B1b1_1_0013EA50(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b1_1_00144FA0->p, arg0[8]);
}

/* EnemyCmd_UpdateParamFlags_1_00144FB0 */

void EnemyCmd_UpdateParamFlags_1_00144FB0(u8 *arg0)
{
    Enemy_UpdateParamFlags_0_0013F760(gEnemyScriptSbss_00201FA8__as_EnemyCmd_UpdateParamFlags_1_00144FB0->p, arg0[8]);
}

/* EnemyCmd_RegisterKill_0_00144FC0 */

void EnemyCmd_RegisterKill_0_00144FC0(void)
{
    s16 i = Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterKill_0_00144FC0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_RegisterKill_0_00144FC0->p);
    Bestiary_SetKilled_1_001A9FA0(i);
    Bestiary_IsSeen_2_001A9EC0(i);
    Bestiary_SetSeen_1_001A9F10(i);
}

/* EnemyCmd_RegisterSeen_0_00145010 */

void EnemyCmd_RegisterSeen_0_00145010(void)
{
    s16 i = Ent_GetTypeByte_1_0013E220__as_EnemyCmd_RegisterSeen_0_00145010(gEnemyScriptSbss_00201FA8__as_EnemyCmd_RegisterSeen_0_00145010->p);
    Bestiary_IsKilled_1_001A9F60(i);
    Bestiary_SetKilled_1_001A9FA0(i);
}

/* EnemyCmd_Set5B1b0_1_00145060 */

void EnemyCmd_Set5B1b0_1_00145060(u8 *arg0)
{
    Enemy_Set5B1b0_1_0013EB10(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B1b0_1_00145060->p, arg0[8]);
}

/* EnemyCmd_SetGameFlag_2_00145070 */
void EnemyCmd_SetGameFlag_2_00145070(u8 *arg0)
{
    GameFlag_SetBit_2_0013D5C0(arg0[8], arg0[0x10]);
}

/* EnemyCmd_TestGameFlag_2_00145080 */

void EnemyCmd_TestGameFlag_2_00145080(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    s8 *p = Script_GetArgPtr_2_00165130__as_EnemyCmd_TestGameFlag_2_00145080(o, 2);
    *p = GameFlag_TestBit_2_0013D630(a, b);
}

/* EnemyCmd_SetDead_1_001450D0 */

void EnemyCmd_SetDead_1_001450D0(u8 *arg0)
{
    Enemy_SetDeadFlag_0_0013EEB0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_SetDead_1_001450D0->p, arg0[8]);
}

/* EnemyCmd_Set5B0b7_1_001450E0 */

void EnemyCmd_Set5B0b7_1_001450E0(u8 *arg0)
{
    Enemy_Set5B0b7_1_0013EB40(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b7_1_001450E0->p, arg0[8]);
}

/* EnemyCmd_KillNow_1_001450F0 */

void EnemyCmd_KillNow_1_001450F0(void) {
    Enemy_Kill_1_0013EF80__as_EnemyCmd_KillNow_1_001450F0(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), 0xFF);
}

/* EnemyCmd_Random_2_00145100 */

void EnemyCmd_Random_2_00145100(u8 *a)
{
    s8 *p = Script_GetArgPtr_2_00165130__as_EnemyCmd_Random_2_00145100(a, 0);
    *p = Rand_Range_3_0013D500__as_EnemyCmd_Random_2_00145100(a[0x10]);
}

/* EnemyCmd_GetType_1_00145140 */

void EnemyCmd_GetType_1_00145140(s32 a)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetType_1_00145140->p;
    s8 *q = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetType_1_00145140(a, 0);
    *q = Ent_GetTypeByte_1_0013E220__as_EnemyCmd_GetType_1_00145140(p);
}

/* EnemyCmd_Set5B0b1_1_00145180 */

void EnemyCmd_Set5B0b1_1_00145180(u8 *arg0)
{
    Enemy_Set5B0b1_1_0013EC10(gEnemyScriptSbss_00201FA8__as_EnemyCmd_Set5B0b1_1_00145180->p, arg0[8]);
}

/* EnemyCmd_AddHp_2_00145190 */

void EnemyCmd_AddHp_2_00145190(u8 *arg0)
{
    Enemy_AddHp_2_0013F710__as_EnemyCmd_AddHp_2_00145190(gEnemyScriptSbss_00201FA8__as_EnemyCmd_AddHp_2_00145190->p, arg0[8]);
}

/* EnemyCmd_Get5B0b0_1_001451A0 */

void EnemyCmd_Get5B0b0_1_001451A0(s32 a)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_Get5B0b0_1_001451A0->p;
    s8 *q = Script_GetArgPtr_2_00165130__as_EnemyCmd_Get5B0b0_1_001451A0(a, 0);
    *q = Enemy_Get5B0m1_1_0013EC50(p);
}

/* EnemyCmd_AddPartValue_0_001451E0 */
void EnemyCmd_AddPartValue_0_001451E0(u8 *arg0) {
    P_EnemyCmd_AddPartValue_0_001451E0 *p;
    u8 a;
    s32 d;
    u8 b;
    u8 c;
    p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_AddPartValue_0_001451E0->p;
    a = arg0[0x10];
    d = arg0[8];
    b = arg0[0x18];
    c = arg0[0x20];
    if (a != 0xFF) p->x610 = a;
    if ((b & 0xFF) != 0xFF) p->x612 = b;
    if (c & 0xFF) p->x613 = c;
    if (d != 0) {
        p->x611 = 0;
        p->x614 = 0;
    }
}

/* EnemyCmd_GetHpPercent_2_00145250 */

void EnemyCmd_GetHpPercent_2_00145250(s32 a)
{
    void *p = gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetHpPercent_2_00145250->p;
    s8 *q = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetHpPercent_2_00145250(a, 0);
    *q = Enemy_GetHpPercent_2_0013F620(p);
}

/* EnemyCmd_SetMode_1_00145290 */

void EnemyCmd_SetMode_1_00145290(u8 *arg0)
{
    Enemy_SetMode_0_0013EBA0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_SetMode_1_00145290->p, arg0[8]);
}

/* EnemyCmd_SelectMotionB_1_001452A0 */
void EnemyCmd_SelectMotionB_1_001452A0(void *arg0) {
    Enemy_SelectMotion_0_0013C420(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), (s32) M2C_FIELD(arg0, u8 *, 8), (s64) M2C_FIELD(arg0, s16 *, 0x10), 1);
}

/* EnemyCmd_Set609_1_001452C0 */
void EnemyCmd_Set609_1_001452C0(void *arg0) {
    M2C_FIELD(M2C_FIELD(gEnemyScriptSbss_00201FA8, void **, 0x154), s8 *, 0x609) = (s8) M2C_FIELD(arg0, s8 *, 8);
}

/* EnemyCmd_SetMapObjFlag_0_001452E0 */
void EnemyCmd_SetMapObjFlag_0_001452E0(u8 *o) {
    u8 m = o[8];
    s16 *p = PlayerData_Get_2_001C9BA0();
    u8 fl = 0;
    u8 i;
    if (m & 1) { fl |= 1; p[2] = p[0]; }
    if (m & 2) { fl |= 2; p[3] = p[1]; }
    if (fl) Player_PlayLevelUpSe_0_001C9FB0(0);
    for (i = 0; i < 3; i++) if (fl & (1 << i)) Sfx_Spawn_2_00169B50(i + 0x1EA, 0, 1, 0);
}

/* EnemyCmd_PlaySe_1_001453A0 */
void EnemyCmd_PlaySe_1_001453A0(A_EnemyCmd_Nop_1_00143890 *a) {
    S_EnemyCmd_PlaySe_1_001453A0 *s;
    u16 h;
    u8 b;
    f32 v[4];
    P_EnemyCmd_PlaySe_1_001453A0 p;
    s32 k;
    s = gEnemyScriptSbss_00201FA8__as_EnemyCmd_PlaySe_1_001453A0;
    k = s->x154;
    h = a->x8;
    b = a->x10;
    p = gEnemyScriptSdata_00201C50;
    sceVu0CopyVector__as_EnemyCmd_PlaySe_1_001453A0(v, Enemy_Ptr6F0_1_0013FFA0(k, s));
    SndCh_GetPosition_1_00131180(Snd_PlaySeAt_2_001315A0(h, b, v), &p);
}

/* EnemyCmd_GetModelPos_0_00145410 */

void EnemyCmd_GetModelPos_0_00145410(s32 a0) {
    s32 o;
    f32 *x, *y, *z;
    Vec *s;
    o = *(s32 *)(gEnemyScriptSbss_00201FA8__as_EnemyCmd_GetModelPos_0_00145410 + 0x154);
    x = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetModelPos_0_00145410(a0, 0);
    y = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetModelPos_0_00145410(a0, 1);
    z = Script_GetArgPtr_2_00165130__as_EnemyCmd_GetModelPos_0_00145410(a0, 2);
    {
        Vec v = {0};
        s = Enemy_GetModelData_1_0013DCE0(o);
        if (s) sceVu0CopyVector__as_EnemyCmd_GetModelPos_0_00145410(&v, s);
        *x = v.x;
        *y = v.y;
        *z = v.z;
    }
}

/* EnemyCmd_SpawnItem_0_001454E0 */

void EnemyCmd_SpawnItem_0_001454E0(Arg_EnemyCmd_SpawnItem_0_001454E0 *a) {
    u32 v = a->x8.w;
    u8 *p = Script_GetArgPtr_2_00165130__as_EnemyCmd_SpawnItem_0_001454E0(a, 1);
    u8 k = a->x18.w;
    void *o = MapObj_FindById_0_00179DB0(v / 1000, v % 1000);
    if (o) {
        if (k == 0) *p = Msg_ShowWrap_1_0018AC90(o, 0);
        if (k == 1) *p = Msg_ShowWrap_1_0018AC90(o, -1);
    } else {
        *p = 3;
    }
}

/* EnemyCmd_ShakeCamera_0_001455B0 */
void EnemyCmd_ShakeCamera_0_001455B0(Obj_EnemyCmd_ShakeCamera_0_001455B0 *o)
{
    T_EnemyCmd_ShakeCamera_0_001455B0 t = { 0 };
    t.v = 256.0f * o->f;
    Camera_SetShake_0_00189F00(&t);
}

/* EnemyCmd_ResetVectors_1_00145610 */

void EnemyCmd_ResetVectors_1_00145610(u8 *arg0)
{
    Enemy_ResetVectors_0_0013D1F0(gEnemyScriptSbss_00201FA8__as_EnemyCmd_ResetVectors_1_00145610->p, arg0[8]);
}
#undef Enemy_Ptr700_1_0013FF90
#undef Enemy_Ptr6E0_1_0013FFB0
#undef Enemy_PtrVec660_1_00140340
#undef Enemy_GetPositionPtr_2_00140460
#undef Enemy_GetForwardVector_2_001403D0
#undef Enemy_GetRightVector_1_00140360
#undef Enemy_GetMotionFrame_0_0013ECA0
#undef Enemy_CopyVec660_1_00140350
#undef Enemy_GetTargetHandle_0_0013EDE0
#undef Ent_IsNull0_1_0013EE30
#undef Enemy_CopyPosition_2_00140470
#undef Enemy_GetRotationPtr_1_00140430
#undef sceVu0SubVector
#undef EnemyScr_BroadcastMotionEvent_0_00140F90
#undef Ent_GetTypeByte_1_0013E220
#undef Enemy_CopyRotation_2_00140440
#undef EnemyScr_BroadcastFrameEvent_0_001410C0
#undef Enemy_Ptr6F0_1_0013FFA0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gEnemyScriptSbss_00201FA8 */
void *gEnemyScriptSbss_00201FA8;
#endif
