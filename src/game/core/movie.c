#include "common.h"
#include "include_asm.h"
#include "game/data.h"
#include "game/core.h"
#include "game/sound.h"
typedef CdRMode RMode;
typedef struct { s32 w[4]; } Q_Movie_BuildUploadPacket_0_001E9020;
typedef struct { u32 x, y, w, h; } R;
typedef struct { s32 lo, hi, reg, pad; } Q_Movie_BuildCopyPacket_0_001E92C0;
typedef struct { char pad[0x38]; u32 w; s32 h; } O_Movie_ClearScreen_1_001E9420;
typedef struct { s32 a, b, c, d; } P_Movie_ClearScreen_1_001E9420;
typedef struct { u8 pad[0x30]; s32 x30, x34, x38, x3C, x40, x44; } O_Movie_SetupDisplayPackets_1_001E95B0;
typedef struct {
    u64 FBP : 9;
    u64 FBW : 6;
    u64 PSM : 5;
    u64 p0 : 12;
    u64 DBX : 11;
    u64 DBY : 11;
    u64 p1 : 10;
} DispFb;
typedef struct {
    u64 pmode;
    u64 smode2;
    DispFb dispfb;
    u64 display;
    u64 bgcolor;
    u32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
} Env;
typedef struct { u64 a, b; u64 pad[2]; } T_MovieCb_Image_0_001E9DC0;
typedef struct { char pad[8]; u64 a; u64 b; } Obj_MovieCb_Image_0_001E9DC0;
typedef struct { u8 pad[0xA8]; s32 xA8; } M;
typedef struct { char pad[0x48]; char sub[0x60]; s32 xa8; } Obj_Movie_DecodeWrap_0_001EA060;
typedef struct { u8 pad[0x48]; u8 x48[0x14]; s32 x5C; u8 p60[0x28]; s32 x88; u8 p8C[0x1C]; s32 xA8; } P_MovieVideo_PutData_0_001EA0D0;
typedef union { u32 w; f32 f; } T_MovieVideo_PutData_0_001EA0D0;
typedef struct { s64 x0; s64 x8; s32 x10; s32 x14; } E_MovieVideo_GetFrame_0_001EA2E0;
typedef struct { s32 x0; s32 p4; s32 x8; u8 pC[0x2C]; s32 x38; s32 p3C; s32 x40; u8 p44[0xC]; E_MovieVideo_GetFrame_0_001EA2E0 *x50; s32 x54; s32 x58; s32 x5C; } P_MovieVideo_GetFrame_0_001EA2E0;
typedef struct { s64 x0; s64 x8; } O_MovieVideo_GetFrame_0_001EA2E0;
typedef struct { s64 a; s64 b; s32 pos; s32 len; } E_MovieVideo_FindTimestamp_0_001EA4D0;
typedef struct { char p0[8]; s32 x8; char pc[0x44]; E_MovieVideo_FindTimestamp_0_001EA4D0 *ents; s32 n; s32 cnt; s32 head; } O_MovieVideo_FindTimestamp_0_001EA4D0;
typedef struct { char p0[0x10]; s32 pos; s32 len; } B_MovieVideo_FindTimestamp_0_001EA4D0;
typedef struct { s32 a, b, c, d, x10, x14; } E_MovieVideo_CheckTs_0_001EA690;
typedef struct { s32 x0, x4, x8; u8 p[0x44]; E_MovieVideo_CheckTs_0_001EA690 *x50; s32 x54; s32 x58; s32 x5C; } S_MovieVideo_CheckTs_0_001EA690;
typedef struct { u32 x0; u32 x4; s32 x8; s32 xC; s32 x10; s32 p14[2]; u32 x1C; u32 x20; u32 x24; u32 x28; s32 x2C; s32 x30; s32 x34; u32 x38; s32 x3C; s32 sema; s32 x44; } S_MovieVideo_DmaHandler_0_001EA750;
typedef struct { u8 pad[0x1C]; s32 r[8]; s32 a; s32 sema; s32 x44; } S_MovieVideo_Reset_0_001EAB10;
typedef struct { u32 base; u32 tags; s32 n; s32 xC, x10, x14; s32 pad[10]; s32 sema; s32 x44; } S_MovieVideo_IpuHandler_0_001EAC70;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; u8 pad[0x24]; s32 x40; } S_MovieVideo_GetSpace_0_001EAF60;
typedef struct { u32 base; u32 tags; s32 n; s32 xC, x10, x14, x18, x1C, x20, x24, x28; s32 pad[6]; s32 x44; u64 x48; } S_MovieVideo_Clear_0_001EB060;
typedef struct { s32 count; s32 max_count; s32 init_count; s32 wait_threads; u32 attr; u32 option; } SemaParam;
typedef struct { u64 a; u64 b; } T_MovieVideo_Create_0_001EB1A0;
typedef struct { u32 x0; u32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; u8 pad[0x24]; s32 x40; s32 x44; s64 x48; E_MovieVideo_GetFrame_0_001EA2E0 *x50; s32 x54; s32 x58; s32 x5C; } O_MovieVideo_Create_0_001EB1A0;
typedef struct { s32 src; s32 dst; s32 size; s32 attr; } Dma_MovieAudio_Transfer_0_001EB540;
typedef struct {
    s32 state; char pad[0x2C];
    s32 x30; s32 x34; s32 x38; s32 x3c; s32 x40;
    s32 buf; s32 size; s32 pos; s32 x50; s32 x54;
} S_MovieAudio_Send_0_001EB8B0;
typedef struct { s32 x0; u8 pad[0x28]; s32 x2C; s32 x30; s32 x34; s32 x38; s32 x3C; } S_MovieAudio_GetSpace_0_001EBAB0;
typedef struct { s32 x0; u8 p4[0x28]; s32 x2C; s32 x30; s32 x34; s32 x38; s32 x3C; s32 x40; s32 x44; s32 x48; s32 x4C; s32 x50; s32 x54; s32 x58; } S_MovieAudio_Create_1_001EBCC0;
typedef struct { void *src; s32 dst; s32 size; s32 attr; } Dma_MovieAudio_Create_1_001EBCC0;
typedef struct { s32 x0; u8 pad[0x28]; s32 x2C; s32 x30; s32 x34; s32 x38; s32 x3C; s32 x40; } S_MovieCb_AudioStream_0_001EBE10;
typedef struct { s32 x0; s32 x4; u8 *x8; s32 xC; } H;
typedef struct { u8 p0[8]; u8 *src; u32 len; s64 a; s64 b; } P_MovieCb_VideoStream_0_001EC070;
typedef struct { s32 x0; u8 p4[0x10]; s32 x14; u8 p18[0x28]; s32 sema; u8 p44[4]; s64 tot; E_MovieVideo_FindTimestamp_0_001EA4D0 *ents; s32 n; s32 cnt; s32 head; } O_MovieCb_VideoStream_0_001EC070;
typedef ThreadParam TP;
typedef struct { u8 pad[8]; s32 x8; u8 pC[0x4C]; s32 x58; s32 x5C; u8 p60[0x28]; s32 x88; u8 p8C[0x1C]; s32 xA8; } P_Movie_ReadLoop_1_001ECAB0;
typedef struct { u8 data[0x50000]; s32 rd; s32 cnt; s32 size; } B_Movie_ReadLoop_1_001ECAB0;
typedef struct { s32 x0; s32 x4; s32 x8; } Q_Movie_ReadLoop_1_001ECAB0;
extern char gMovieRodata_00201920[];
extern char gMovieRodata_00201940[];
extern u8 gMovieBss_004BD310[];
extern u8 D_004BD311[];
extern u8 D_004BD312[];
extern u8 D_004BD313[];
extern Q_Movie_BuildUploadPacket_0_001E9020 *gMovieParamsBss_004BD31C[][2];
extern s32 gMovieSbss_002023EC;
extern s32 gMovieSbss_002023F0;
extern s32 gMovieSbss_002023F4;
extern s32 gMovieSbss_002023F8;
extern s32 gMovieSbss_002023FC;
extern s16 gMovieBss_004BE0D4[];
extern s16 D_004BE0D6[];
extern char D_004BDF88[];
extern u8 *D_004BDEC4[];
extern volatile s32 D_004BDEC8[];
extern s32 D_004BDECC[];
extern T_MovieVideo_PutData_0_001EA0D0 gMovieSdata_00201E74;
extern s32 D_004BDF9C[];
extern volatile s32 D_004BDF0C[];
extern s32 D_004BDF18[];
extern s32 D_004BDF1C[];
extern s32 D_004BDF20[];
extern s32 D_004BDF24[];
extern s32 gMovieBss_004BDF40[];
extern s32 gMovieBss_004BDFF0[];
extern s32 D_004BDFF4[];
extern s32 gMovieBss_004BE040[];
extern s32 D_004BE044[];
extern s32 D_004BE04C[];
extern s32 _gp;
extern u8 *gMovieBss_004BE02C[];
extern u8 *gMovieBss_004BE038[];
extern u8 gMovieBss_004BE080[];
extern s32 gMovieSbss_00202400;
#ifndef NONMATCHING
extern char gStrCdrom0_00201950[];
extern char gMovieRodata_00201958[];
extern char gStr1_00201960[];
extern char gStrSS_00201968[];
extern char gMovieRodata_00201970[];
extern char gStrHost0_00201978[];
extern s16 gMovieBss_004BE0D8[];
extern s32 gMovieBss_004BDFC8[];
extern s64 gMovieBss_004BDFD0[];
extern s32 gMovieBss_004BE0D0[];
extern s32 gMovieBss_004BDF38[];
extern s32 gMovieBss_004BE078[];
extern s32 gMovieBss_004BE07C[];
extern s32 gStrCanTOpenFileS_00201A50[];
extern s32 gMovieSdata_00201E70;
extern s32 gMovieBss_004BDFE8[];
extern s32 gMovieBss_004BE010[];
extern s32 gMovieBss_004BE014[];
extern s32 gMovieBss_004BE018[];
extern s32 gMovieBss_004BE01C[];
extern s32 gMovieBss_004BE020[];
extern s32 gMovieBss_004BE024[];
extern s32 gMovieBss_004BE028[];
extern s32 gMovieBss_004BE030[];
extern s32 gMovieBss_004BDF34[];
extern u32 gMovieBss_004BE000[];
extern volatile u32 gMovieBss_004BE004[];
extern volatile u32 gMovieBss_004BE008[];
extern s32 gMovieBss_004BE034[];
#else
/* data twins (src/game/data/movie_rodata.c): gStrCdrom0_00201950 */
static char gStrCdrom0_00201950[0x7] = "cdrom0\000";
/* data twins (src/game/data/movie_rodata.c): gMovieRodata_00201958 */
static char gMovieRodata_00201958[0x8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
/* data twins (src/game/data/movie_rodata.c): gStr1_00201960 */
static char gStr1_00201960[0x8] = ";1\000\000\000\000\000\000";
/* data twins (src/game/data/movie_rodata.c): gStrSS_00201968 */
static char gStrSS_00201968[0x5] = "%s%s\000";
/* data twins (src/game/data/movie_rodata.c): gMovieRodata_00201970 */
static char gMovieRodata_00201970[0x8] = { 0x25, 0x73, 0x3a, 0x25, 0x73, 0, 0, 0 };
/* data twins (src/game/data/movie_rodata.c): gStrHost0_00201978 */
static char gStrHost0_00201978[0x6] = "host0\000";
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE0D8 */
static s16 gMovieBss_004BE0D8[0x4] __attribute__((aligned(4)));
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BDFC8 */
static s32 gMovieBss_004BDFC8[0x2] __attribute__((aligned(4)));
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BDFD0 */
static s64 gMovieBss_004BDFD0[0x1] __attribute__((aligned(4)));
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE0D0 */
static s32 gMovieBss_004BE0D0[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BDF38 */
static s32 gMovieBss_004BDF38[0x2] __attribute__((aligned(4)));
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE078 */
static s32 gMovieBss_004BE078[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE07C */
static s32 gMovieBss_004BE07C[0x1];
/* data twins (src/game/data/movie_rodata2.c): gStrCanTOpenFileS_00201A50 */
static s32 gStrCanTOpenFileS_00201A50[0x8] = { 0x276e6143, 0x704f2074, 0x66206e65, 0x20656c69, 0xa7325, 0, 0, 0 };
/* data twins (src/game/data/sdata.c): gMovieSdata_00201E70 */
static s32 gMovieSdata_00201E70 = 1;
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BDFE8 */
static s32 gMovieBss_004BDFE8[0x2] __attribute__((aligned(4)));
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE010 */
static s32 gMovieBss_004BE010[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE014 */
static s32 gMovieBss_004BE014[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE018 */
static s32 gMovieBss_004BE018[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE01C */
static s32 gMovieBss_004BE01C[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE020 */
static s32 gMovieBss_004BE020[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE024 */
static s32 gMovieBss_004BE024[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE028 */
static s32 gMovieBss_004BE028[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE030 */
static s32 gMovieBss_004BE030[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BDF34 */
static s32 gMovieBss_004BDF34[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE000 */
static u32 gMovieBss_004BE000[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE004 */
static volatile u32 gMovieBss_004BE004[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE008 */
static volatile u32 gMovieBss_004BE008[0x2] __attribute__((aligned(4)));
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BE034 */
static s32 gMovieBss_004BE034[0x1];
#endif
s32 MovieFile_Open_3_001E88C0(s32 *a0, char *name);
Q_Movie_BuildUploadPacket_0_001E9020* Movie_BuildUploadPacket_0_001E9020(Q_Movie_BuildUploadPacket_0_001E9020 *p, R *r, s32 i, s32 j);
Q_Movie_BuildUploadPacket_0_001E9020* Movie_BuildClearPacket_0_001E9190(Q_Movie_BuildUploadPacket_0_001E9020 *p, R *r, u32 c);
Q_Movie_BuildCopyPacket_0_001E92C0* Movie_BuildCopyPacket_0_001E92C0(Q_Movie_BuildCopyPacket_0_001E92C0 *p, R *b, R *a);
void Movie_ClearScreen_1_001E9420(O_Movie_ClearScreen_1_001E9420 *o, s32 n);
void Movie_SetupDisplayPackets_1_001E95B0(O_Movie_SetupDisplayPackets_1_001E95B0 *o, u32 buf, u32 src, s32 i, s32 j);
void Movie_InitDisplay_1_001E9AA0(Env *o, s32 a1, s32 a2, s32 w, s32 h, s32 a5, s32 a6);
s32 MovieCb_Image_0_001E9DC0(void *unused, Obj_MovieCb_Image_0_001E9DC0 *o);
s32 MovieCb_Audio_0_001E9E10(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 MovieCb_Nodata_0_001E9E40(void);
s32 MovieCb_Error_0_001E9E70(void);
s32 MovieCb_AudioYield_0_001E9EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 MovieCb_Nop_2_001E9EE0(void);
s32 Movie_DecodeFrame_1_001E9EF0(M *mp);
void Movie_DecodeWrap_0_001EA060(Obj_Movie_DecodeWrap_0_001EA060 *o);
s32 MovieVideo_PutData_0_001EA0D0(P_MovieVideo_PutData_0_001EA0D0 *p);
s32 MovieVideo_GetFrame_0_001EA2E0(P_MovieVideo_GetFrame_0_001EA2E0 *p, O_MovieVideo_GetFrame_0_001EA2E0 *out);
s32 MovieVideo_FindTimestamp_0_001EA4D0(O_MovieVideo_FindTimestamp_0_001EA4D0 *o, B_MovieVideo_FindTimestamp_0_001EA4D0 *b);
s32 MovieVideo_CheckTs_0_001EA690(S_MovieVideo_CheckTs_0_001EA690 *a0, s32 a1);
s32 MovieVideo_DmaHandler_0_001EA750(S_MovieVideo_DmaHandler_0_001EA750 *s);
s32 MovieVideo_Reset_0_001EAB10(S_MovieVideo_Reset_0_001EAB10 *s);
s32 MovieVideo_IpuHandler_0_001EAC70(S_MovieVideo_IpuHandler_0_001EAC70 *f);
void MovieVideo_GetSpace_0_001EAF60(S_MovieVideo_GetSpace_0_001EAF60 *s, s32 *a1, s32 *a2, s32 *a3, s32 *a4);
s32 MovieVideo_Clear_0_001EB060(S_MovieVideo_Clear_0_001EB060 *p);
s32 MovieVideo_Create_0_001EB1A0(void *o0, u32 addr0, void *tags0, s32 n, E_MovieVideo_GetFrame_0_001EA2E0 *e, s32 cnt);
s32 MovieAudio_Transfer_0_001EB540(s32 p1, s32 n1, s32 p2, s32 n2, s32 s1, s32 l1, s32 s2, s32 l2);
s32 MovieAudio_Send_0_001EB8B0(S_MovieAudio_Send_0_001EB8B0 *s);
void MovieAudio_GetSpace_0_001EBAB0(S_MovieAudio_GetSpace_0_001EBAB0 *s, s32 *a1, s32 *a2, s32 *a3, s32 *a4);
s32 MovieAudio_Reset_3_001EBB70(s32 *p);
s32 MovieAudio_Create_1_001EBCC0(S_MovieAudio_Create_1_001EBCC0 *a, s32 a1, s32 a2, s32 a3);
s32 MovieCb_AudioStream_0_001EBE10(s32 a0, H *h, u8 *buf0);
s32 MovieCb_VideoStream_0_001EC070(s32 a0, P_MovieCb_VideoStream_0_001EC070 *p, u8 *buf);
void Movie_IdleThread_1_001EC3C0(void);
void Movie_Shutdown_1_001EC3E0(void);
void Movie_Init_1_001EC5E0(s32 arg0);
s32 Movie_ReadLoop_1_001ECAB0(P_Movie_ReadLoop_1_001ECAB0 *p, B_Movie_ReadLoop_1_001ECAB0 *buf, Q_Movie_ReadLoop_1_001ECAB0 *q, s32 (*cb)(void));
s32 Movie_PlayFile_2_001ED070(s32 a, s32 b);
s32 Movie_Start_2_001ED0C0(s32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s16 arg5, s16 arg6, s16 arg7);
s32 printf(const char *, ...);
s32 sprintf(char *, const char *, ...);
char* index(const char *, s32);
s32 strcmp(const char *, const char *);
s32 strlen(const char *);
char* strcpy(char *, const char *);
s32 toupper(s32);
void strncpy(char *, const char *, s32);
s32 sceOpen(char *, s32);
s32 sceSifFreeSysMemory(s32);
s32 sceCdSearchFile(void *, char *);
s32 sceCdDiskReady(s32);
s32 sceCdStInit(u32, u32, u32);
s32 sceCdStStart(u32, RMode *);
s32 sceCdStStop(void);
s32 sceClose(s32);
s32 sceLseek(s32, s32, s32);
s32 sceSifAllocIopHeap(s32);
void sceGsSyncPath(s32, s32);
s32 sceGsSyncV(s32);
void sceGsResetGraph(s16, s16, s16, s16);
void sceGsSetDefDispEnv(Env *, s16, s16, s16, s16, s16);
void FlushCache(s32);
void sceGsPutDispEnv(Env *);
s32 RotateThreadReadyQueue(s32);
s32 DIntr();
s32 EIntr(void);
void sceMpegReset(void *);
s32 sceMpegGetPicture(void *, u8 *, s32);
s32 sceMpegIsEnd(void *);
s32 WaitSema(s32);
s32 SignalSema(s32);
void memcpy(void *, void *, s32);
s32 CreateSema(SemaParam *);
s32 sceSifDmaStat(s32);
s32 sceSifSetDma(void *, s32);
s32 sceSdRemote(s32, s32, s32, ...);
void memset(void *, s32, s32);
void DeleteSema(s32);
void DeleteThread(s32);
void DisableDmac(s32);
void RemoveDmacHandler(s32, s32);
void RemoveIntcHandler(s32, s32);
void TerminateThread(s32);
void sceMpegDelete(s32 *);
void DisableIntc(s32);
s32 CreateThread(TP *);
s32 StartThread(s32, void *);
s32 Movie_VblankHandler_0_001E8C50();
s32 Movie_DisplayHandler_0_001E8CB0();
s32 AddDmacHandler(s32, s32 (*)(), s32);
void EnableDmac(s32);
void sceMpegCreate(void *, s32, s32);
s32 AddIntcHandler(s32, s32 (*)(), s32);
void EnableIntc(s32);
void sceMpegAddCallback(void *, s32, s32 (*)(), s32);
void sceMpegAddStrCallback(void *, s32, s32, s32 (*)(), u8 *);
s32 sceMpegDemuxPssRing(P_Movie_ReadLoop_1_001ECAB0 *, u8 *, s32, B_Movie_ReadLoop_1_001ECAB0 *, s32);
s32 MovieFile_Read_3_001E8710(Q_Movie_ReadLoop_1_001ECAB0 *, u8 *, s32, s32);
s32 sceMpegIsRefBuffEmpty(P_Movie_ReadLoop_1_001ECAB0 *);

/* .bss from 0x004BD380, defined from the top down (CodeWarrior writes
   uninitialised objects in reverse order) */
s32 D_004BDF28[0x3];
s32 D_004BDF14[0x5] __attribute__((aligned(4)));      /* also D_004BDF18, D_004BDF1C, D_004BDF20, D_004BDF24 */
s32 D_004BDEE0[0xd];
s32 D_004BDED0[0x4];
u8 *D_004BDEC0[0x4];      /* also D_004BDEC4, D_004BDEC8, D_004BDECC */
s32 D_004BD6C0[0x200];
u32 D_004BD540[0x60];
u32 D_004BD380[0x70];

/* MovieFile_Open_3_001E88C0 */
#pragma explicit_zero_data on
const char D_00201980[0x20] = "SifAllocIopHeap Error\012\000\000\000\000\000\000\000\000\000\000";
const char D_002019A0[0x20] = "sceCdStInit Error \012\000\000\000\000\000\000\000\000\000\000\000\000\000";
const char D_002019C0[0x30] = "Cannot open '%s'(sceCdSearchFile)\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
const char D_002019F0[0x20] = "Cannot open '%s'(sceOpen)\012\000\000\000\000\000\000";
const char D_00201A10[0x20] = "sceLseek() fails (%s): %d\012\000\000\000\000\000\000";
const char D_00201A30[0x17] = "sceLseek() fails (%s)\012\000";

s32 MovieFile_Open_3_001E88C0(s32 *a0, char *name) {
    RMode mode;
    char path[0x10C];
    char dev[0x40];
    char *colon;
    s32 len;
    s32 i;
    s32 n;

    colon = index(name, ':');
    len = colon - name;
    if (colon != NULL) {
        strncpy(dev, name, len);
        dev[len] = 0;
        if (strcmp(dev, gStrCdrom0_00201950) == 0) {
            n = strlen(colon + 1);
            a0[0] = 1;
            for (i = 0; i < n; i++) {
                char *p = colon + i + 1;
                if (*p == '/') *p = 0x5C;
                *p = toupper(*p);
            }
            sprintf(path, gStrSS_00201968, colon + 1, index(name, ';') ? gMovieRodata_00201958 : gStr1_00201960);
        } else {
            a0[0] = 0;
            sprintf(path, gMovieRodata_00201970, dev, colon + 1);
        }
    } else {
        strcpy(dev, gStrHost0_00201978);
        a0[0] = 0;
        sprintf(path, gMovieRodata_00201970, dev, name);
    }
    if (a0[0] != 0) {
        sceCdDiskReady(0);
        a0[11] = sceSifAllocIopHeap(0x28010);
        if (a0[11] == 0) {
            printf(D_00201980);
            return 0;
        }
        if (sceCdStInit(0x50, 5, (a0[11] + 0xF) & ~0xF) != 1) {
            printf(D_002019A0);
            if (sceSifFreeSysMemory(a0[11]) < 0) {
                printf(gMovieRodata_00201920, gMovieRodata_00201940, 0xF1A);
            }
            return 0;
        }
        if (sceCdSearchFile(&a0[2], path) == 0) {
            printf(D_002019C0, path);
            while (!sceCdStStop() != 0) {
            }
            if (sceSifFreeSysMemory(a0[11]) < 0) {
                printf(gMovieRodata_00201920, gMovieRodata_00201940, 0xF22);
            }
            return 0;
        }
        a0[1] = a0[3];
        mode.trycount = 0;
        mode.spindlctrl = 0;
        mode.datapattern = 0;
        while (!sceCdStStart(a0[2], &mode) != 0) {
        }
    } else {
        a0[12] = sceOpen(path, 1);
        if (a0[12] < 0) {
            printf(D_002019F0, path);
            return 0;
        }
        a0[1] = sceLseek(a0[12], 0, 2);
        if (a0[1] < 0) {
            printf(D_00201A10, path, a0[1]);
            sceClose(a0[12]);
            return 0;
        }
        if (sceLseek(a0[12], 0, 0) < 0) {
            printf(D_00201A30, path);
            sceClose(a0[12]);
            return 0;
        }
    }
    return 1;
}

/* text_001E8C50 */
INCLUDE_ASM(Movie_VblankHandler_0_001E8C50);

/* Movie_BuildUploadPacket_0_001E9020 */
Q_Movie_BuildUploadPacket_0_001E9020 *Movie_BuildUploadPacket_0_001E9020(Q_Movie_BuildUploadPacket_0_001E9020 *p, R *r, s32 i, s32 j) {
    u64 v;
    Q_Movie_BuildUploadPacket_0_001E9020 *a;
    Q_Movie_BuildUploadPacket_0_001E9020 *b;
    Q_Movie_BuildUploadPacket_0_001E9020 *c;
    Q_Movie_BuildUploadPacket_0_001E9020 *d;
    Q_Movie_BuildUploadPacket_0_001E9020 *e;
    p->w[0] = 0x146;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    a = p + 1;
    a->w[0] = 0x44;
    a->w[1] = 0;
    a->w[2] = 0x42;
    a->w[3] = 0;
    b = a + 1;
    v = (u64)r->x | ((u64)r->y << 16);
    b->w[0] = v & 0xFFFFFFFF;
    b->w[1] = v >> 32;
    b->w[2] = 5;
    b->w[3] = 0;
    c = b + 1;
    gMovieParamsBss_004BD31C[j][i] = c;
    v = (u64)gMovieBss_004BD310[0] | ((u64)D_004BD311[0] << 8) | ((u64)D_004BD312[0] << 16) | ((u64)D_004BD313[0] << 24);
    c->w[0] = v & 0xFFFFFFFF;
    c->w[1] = v >> 32;
    c->w[2] = 1;
    c->w[3] = 0;
    d = c + 1;
    v = (u64)(u32)(r->x + r->w) | ((u64)(u32)(r->y + r->h) << 16);
    d->w[0] = v & 0xFFFFFFFF;
    d->w[1] = v >> 32;
    d->w[2] = 5;
    d->w[3] = 0;
    e = d + 1;
    return e;
}

/* Movie_BuildClearPacket_0_001E9190 */
static inline Q_Movie_BuildUploadPacket_0_001E9020 *put_Movie_BuildClearPacket_0_001E9190(Q_Movie_BuildUploadPacket_0_001E9020 *p, u64 v, s32 r)
{
    p->w[0] = v & 0xFFFFFFFF; p->w[1] = v >> 32; p->w[2] = r; p->w[3] = 0;
    return p + 1;
}

Q_Movie_BuildUploadPacket_0_001E9020 *Movie_BuildClearPacket_0_001E9190(Q_Movie_BuildUploadPacket_0_001E9020 *p, R *r, u32 c)
{
    p = put_Movie_BuildClearPacket_0_001E9190(p, 0x106, 0);
    p = put_Movie_BuildClearPacket_0_001E9190(p, (u64)r->x | ((u64)r->y << 16), 5);
    p = put_Movie_BuildClearPacket_0_001E9190(p, (u64)(c & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)((c >> 16) & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24), 1);
    p = put_Movie_BuildClearPacket_0_001E9190(p, (u64)(r->x + r->w) | ((u64)(r->y + r->h) << 16), 5);
    return p;
}

/* Movie_BuildCopyPacket_0_001E92C0 */
static inline Q_Movie_BuildCopyPacket_0_001E92C0 *set_Movie_BuildCopyPacket_0_001E92C0(Q_Movie_BuildCopyPacket_0_001E92C0 *p, u64 v, s32 r) { p->lo = v & 0xFFFFFFFF; p->hi = v >> 32; p->reg = r; p->pad = 0; return p + 1; }
static inline Q_Movie_BuildCopyPacket_0_001E92C0 *hdr(Q_Movie_BuildCopyPacket_0_001E92C0 *p) { p->lo = 0x116; p->hi = 0; p->reg = 0; p->pad = 0; return p + 1; }
Q_Movie_BuildCopyPacket_0_001E92C0 *Movie_BuildCopyPacket_0_001E92C0(Q_Movie_BuildCopyPacket_0_001E92C0 *p, R *b, R *a) {
    p = hdr(p);
    p = set_Movie_BuildCopyPacket_0_001E92C0(p, (u64)a->x | ((u64)a->y << 16), 3);
    p = set_Movie_BuildCopyPacket_0_001E92C0(p, (u64)b->x | ((u64)b->y << 16), 5);
    p = set_Movie_BuildCopyPacket_0_001E92C0(p, (u64)(a->x + a->w) | ((u64)(a->y + a->h) << 16), 3);
    p = set_Movie_BuildCopyPacket_0_001E92C0(p, (u64)(b->x + b->w) | ((u64)(b->y + b->h) << 16), 5);
    return p;
}

/* Movie_ClearScreen_1_001E9420 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
#define Movie_BuildClearPacket_0_001E9190 Movie_BuildClearPacket_0_001E9190__as_Movie_ClearScreen_1_001E9420
u32 *Movie_BuildClearPacket_0_001E9190__as_Movie_ClearScreen_1_001E9420(u32 *p, P_Movie_ClearScreen_1_001E9420 *s, s32 n);

static inline u32 *setreg_Movie_ClearScreen_1_001E9420(u32 *p, u64 v, s32 reg) {
    p[0] = v & 0xFFFFFFFF;
    p[1] = v >> 32;
    p[2] = reg;
    p[3] = 0;
    return p + 4;
}

static inline u32 *tag_Movie_ClearScreen_1_001E9420(u32 *p) {
    p[0] = 0x8006;
    p[1] = 0x10000000;
    p[2] = 0xE;
    p[3] = 0;
    return p + 4;
}

void Movie_ClearScreen_1_001E9420(O_Movie_ClearScreen_1_001E9420 *o, s32 n) {
    P_Movie_ClearScreen_1_001E9420 s;
    u32 a;
    u32 *p;
    s.a = 0;
    s.b = 0;
    s.c = o->w * 16;
    s.d = ((o->h * 2 + 31) / 32) << 9;
    a = (u32)D_004BD380 & 0x0FFFFFFF;
    p = (u32 *)(a | 0x20000000);
    p = tag_Movie_ClearScreen_1_001E9420(p);
    p = setreg_Movie_ClearScreen_1_001E9420(p, ((u64)(u32)(o->h << 1) << 48) | ((u64)o->w << 16), 0x40);
    p = Movie_BuildClearPacket_0_001E9190(p, &s, n);
    setreg_Movie_ClearScreen_1_001E9420(p, ((u64)(u32)(o->h - 1) << 48) | ((u64)(u32)(o->w - 1) << 16), 0x40);
    *(volatile u32 *)0x1000A010 = a;
    *(volatile u32 *)0x1000A020 = 7;
    *(volatile u32 *)0x1000A000 = 0x101;
    sceGsSyncPath(0, 0);
}
#undef Movie_BuildClearPacket_0_001E9190

/* Movie_SetupDisplayPackets_1_001E95B0 */
#define Movie_BuildCopyPacket_0_001E92C0 Movie_BuildCopyPacket_0_001E92C0__as_Movie_SetupDisplayPackets_1_001E95B0
Q_Movie_BuildUploadPacket_0_001E9020 *Movie_BuildCopyPacket_0_001E92C0__as_Movie_SetupDisplayPackets_1_001E95B0(Q_Movie_BuildUploadPacket_0_001E9020 *p, R *b, R *a);

static inline Q_Movie_BuildUploadPacket_0_001E9020 *dma_Movie_SetupDisplayPackets_1_001E95B0(Q_Movie_BuildUploadPacket_0_001E9020 *p, u64 v) { *(u64 *)p = v; return p + 1; }
static inline Q_Movie_BuildUploadPacket_0_001E9020 *tag_Movie_SetupDisplayPackets_1_001E95B0(Q_Movie_BuildUploadPacket_0_001E9020 *p, s32 a, s32 b, s32 c, s32 d) { p->w[0] = a; p->w[1] = b; p->w[2] = c; p->w[3] = d; return p + 1; }
static inline Q_Movie_BuildUploadPacket_0_001E9020 *ref(Q_Movie_BuildUploadPacket_0_001E9020 *p, u32 addr, s32 n) { *(u64 *)p = ((u64)(u32)((s32)addr & ~0xF) << 32) | 0x30000000 | n; return p + 1; }
static inline Q_Movie_BuildUploadPacket_0_001E9020 *set_Movie_SetupDisplayPackets_1_001E95B0(Q_Movie_BuildUploadPacket_0_001E9020 *p, u64 v, s32 r) { p->w[0] = v & 0xFFFFFFFF; p->w[1] = v >> 32; p->w[2] = r; p->w[3] = 0; return p + 1; }

void Movie_SetupDisplayPackets_1_001E95B0(O_Movie_SetupDisplayPackets_1_001E95B0 *o, u32 buf, u32 src, s32 i, s32 j) {
    R a;
    R b;
    Q_Movie_BuildUploadPacket_0_001E9020 *p;
    s32 tbp;
    s32 tbw;
    s32 ny;
    s32 w;
    s32 nx;
    s32 y;
    s32 x;
    u32 ad;
    u64 v;

    p = (Q_Movie_BuildUploadPacket_0_001E9020 *)((buf & 0x0FFFFFFF) | 0x20000000);
    ny = o->x40 >> 4;
    nx = o->x44 >> 4;
    w = (o->x38 + 63) / 64 * 64;
    tbp = w * ((o->x3C / 2 + 31) / 32 * 32) * 2 / 64;
    tbw = w / 64;
    if (i == 0) {
        a.x = o->x30 * 16;
        a.y = o->x34 * 16;
        a.w = o->x38 * 16;
        a.h = o->x3C / 2 * 16;
        b.x = 8;
        b.y = 0x18;
        b.w = o->x40 * 16;
        b.h = o->x44 * 16;
    } else {
        a.x = o->x30 * 16;
        a.y = (o->x34 + (o->x3C / 2 + 31) / 32 * 32) * 16;
        a.w = o->x38 * 16;
        a.h = o->x3C / 2 * 16;
        b.x = 8;
        b.y = 8;
        b.w = o->x40 * 16;
        b.h = o->x44 * 16;
    }
    if (i == 0) {
        p = dma_Movie_SetupDisplayPackets_1_001E95B0(p, 0x10000003);
        p = tag_Movie_SetupDisplayPackets_1_001E95B0(p, 2, 0x10000000, 0xE, 0);
        p = set_Movie_SetupDisplayPackets_1_001E95B0(p, ((u64)(u32)tbp << 32) | ((u64)(u32)tbw << 48), 0x50);
        p = set_Movie_SetupDisplayPackets_1_001E95B0(p, 0x0000001000000010ULL, 0x52);
        for (y = 0; y < ny; y++) {
            for (x = 0; x < nx; x++) {
                p = dma_Movie_SetupDisplayPackets_1_001E95B0(p, 0x10000004);
                p = tag_Movie_SetupDisplayPackets_1_001E95B0(p, 2, 0x10000000, 0xE, 0);
                v = ((u64)(u32)(y * 16) << 32) | ((u64)(u32)(x * 16) << 48);
                p = set_Movie_SetupDisplayPackets_1_001E95B0(p, v, 0x51);
                p = set_Movie_SetupDisplayPackets_1_001E95B0(p, 0, 0x53);
                p = tag_Movie_SetupDisplayPackets_1_001E95B0(p, 0x40, 0x08000000, 0, 0);
                                ad = src & 0x0FFFFFFF; p = ref(p, ad, 0x40);
                src += 0x400;
            }
        }
    }
    p = dma_Movie_SetupDisplayPackets_1_001E95B0(p, 0x10000009);
    p = tag_Movie_SetupDisplayPackets_1_001E95B0(p, 8, 0x10000000, 0xE, 0);
    p = set_Movie_SetupDisplayPackets_1_001E95B0(p, 0, 0x3F);
    p = set_Movie_SetupDisplayPackets_1_001E95B0(p, (u64)(u32)tbp | ((u64)(u32)tbw << 14) | 0xAA8000000ULL, 6);
    p = set_Movie_SetupDisplayPackets_1_001E95B0(p, 0x60, 0x14);
    p = Movie_BuildCopyPacket_0_001E92C0(p, &a, &b);
    p = dma_Movie_SetupDisplayPackets_1_001E95B0(p, 0x70000006);
    p = tag_Movie_SetupDisplayPackets_1_001E95B0(p, 0x8005, 0x10000000, 0xE, 0);
    Movie_BuildUploadPacket_0_001E9020(p, &a, i, j);
}
#undef Movie_BuildCopyPacket_0_001E92C0

/* Movie_InitDisplay_1_001E9AA0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */

static inline u32 *setreg_Movie_InitDisplay_1_001E9AA0(u32 *p, u64 v, s32 reg) {
    p[0] = v & 0xFFFFFFFF;
    p[1] = v >> 32;
    p[2] = reg;
    p[3] = 0;
    return p + 4;
}

static inline u32 *tag_Movie_InitDisplay_1_001E9AA0(u32 *p) {
    p[0] = 0x8007;
    p[1] = 0x10000000;
    p[2] = 0xE;
    p[3] = 0;
    return p + 4;
}

void Movie_InitDisplay_1_001E9AA0(Env *o, s32 a1, s32 a2, s32 w, s32 h, s32 a5, s32 a6) {
    s32 h2;
    s32 w64;
    u32 a;
    u32 *p;

    gMovieSbss_002023EC = 0;
    gMovieSbss_002023F0 = 0;
    gMovieSbss_002023F4 = 0;
    gMovieSbss_002023F8 = 0;
    gMovieSbss_002023FC = 0;
    o->f28 = 0;
    h2 = h / 2;
    w64 = (w + 63) / 64 * 64;
    o->f2C = (w64 * ((h2 + 31) / 32 * 32)) >> 11;
    o->f30 = a1;
    o->f34 = a2;
    o->f38 = w;
    o->f3C = h;
    o->f40 = a5;
    o->f44 = a6;
    sceGsSyncV(0);
    sceGsResetGraph(0, 1, gMovieBss_004BE0D4[0], 1);
    sceGsSetDefDispEnv(o, 0, w, h2, D_004BE0D6[0], gMovieBss_004BE0D8[0]);
    o->dispfb.FBW = w64 / 64;
    FlushCache(0);
    sceGsSyncV(0);
    sceGsPutDispEnv(o);
    a = (u32)D_004BD540 & 0x0FFFFFFF;
    p = (u32 *)(((u32)D_004BD540 & 0x0FFFFFFF) | 0x20000000);
    p = tag_Movie_InitDisplay_1_001E9AA0(p);
    p = setreg_Movie_InitDisplay_1_001E9AA0(p, 1, 0x1A);
    p = setreg_Movie_InitDisplay_1_001E9AA0(p, (u64)o->f28 | ((u64)(u32)((o->f38 + 63) / 64 * 64 / 64) << 16), 0x4C);
    p = setreg_Movie_InitDisplay_1_001E9AA0(p, (u64)o->f28 | ((u64)0x3A << 24) | ((u64)1 << 32), 0x4E);
    p = setreg_Movie_InitDisplay_1_001E9AA0(p, 0x30000, 0x47);
    p = setreg_Movie_InitDisplay_1_001E9AA0(p, 0, 0x18);
    p = setreg_Movie_InitDisplay_1_001E9AA0(p, ((u64)(u32)(o->f3C - 1) << 48) | ((u64)(u32)(o->f38 - 1) << 16), 0x40);
    setreg_Movie_InitDisplay_1_001E9AA0(p, 5, 8);
    *(volatile u32 *)0x1000A010 = a;
    *(volatile u32 *)0x1000A020 = 8;
    *(volatile u32 *)0x1000A000 = 0x101;
    sceGsSyncPath(0, 0);
}

/* MovieCb_Image_0_001E9DC0 */
#define MovieVideo_GetFrame_0_001EA2E0 MovieVideo_GetFrame_0_001EA2E0__as_MovieCb_Image_0_001E9DC0
void MovieVideo_GetFrame_0_001EA2E0__as_MovieCb_Image_0_001E9DC0(void *p, T_MovieCb_Image_0_001E9DC0 *t);

s32 MovieCb_Image_0_001E9DC0(void *unused, Obj_MovieCb_Image_0_001E9DC0 *o)
{
    T_MovieCb_Image_0_001E9DC0 t;
    MovieVideo_GetFrame_0_001EA2E0(D_004BDF88, &t);
    o->a = t.a;
    o->b = t.b;
    return 1;
}
#undef MovieVideo_GetFrame_0_001EA2E0

/* MovieCb_Audio_0_001E9E10 */
#define MovieAudio_Send_0_001EB8B0 MovieAudio_Send_0_001EB8B0__as_MovieCb_Audio_0_001E9E10
int MovieAudio_Send_0_001EB8B0__as_MovieCb_Audio_0_001E9E10();

s32 MovieCb_Audio_0_001E9E10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    MovieAudio_Send_0_001EB8B0(D_004BDEE0, arg1, arg2, arg3);
    return 1;
}
#undef MovieAudio_Send_0_001EB8B0

/* MovieCb_Nodata_0_001E9E40 */
#define MovieVideo_DmaHandler_0_001EA750 MovieVideo_DmaHandler_0_001EA750__as_MovieCb_Nodata_0_001E9E40
int MovieVideo_DmaHandler_0_001EA750__as_MovieCb_Nodata_0_001E9E40();

s32 MovieCb_Nodata_0_001E9E40(void) {
    MovieVideo_DmaHandler_0_001EA750(D_004BDF88);
    return 1;
}
#undef MovieVideo_DmaHandler_0_001EA750

/* MovieCb_Error_0_001E9E70 */
#define MovieVideo_Reset_0_001EAB10 MovieVideo_Reset_0_001EAB10__as_MovieCb_Error_0_001E9E70
int MovieVideo_Reset_0_001EAB10__as_MovieCb_Error_0_001E9E70();

s32 MovieCb_Error_0_001E9E70(void) {
    MovieVideo_Reset_0_001EAB10(D_004BDF88);
    return 1;
}
#undef MovieVideo_Reset_0_001EAB10

/* MovieCb_AudioYield_0_001E9EA0 */
#define MovieVideo_IpuHandler_0_001EAC70 MovieVideo_IpuHandler_0_001EAC70__as_MovieCb_AudioYield_0_001E9EA0
int MovieVideo_IpuHandler_0_001EAC70__as_MovieCb_AudioYield_0_001E9EA0();
#define MovieAudio_Send_0_001EB8B0 MovieAudio_Send_0_001EB8B0__as_MovieCb_AudioYield_0_001E9EA0
int MovieAudio_Send_0_001EB8B0__as_MovieCb_AudioYield_0_001E9EA0();

s32 MovieCb_AudioYield_0_001E9EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    MovieAudio_Send_0_001EB8B0(D_004BDEE0, arg1, arg2, arg3);
    RotateThreadReadyQueue(1);
    MovieVideo_IpuHandler_0_001EAC70(D_004BDF88);
    return 1;
}
#undef MovieVideo_IpuHandler_0_001EAC70
#undef MovieAudio_Send_0_001EB8B0

/* MovieCb_Nop_2_001E9EE0 */
s32 MovieCb_Nop_2_001E9EE0(void) {
    return 1;
}

/* Movie_DecodeFrame_1_001E9EF0 */
static inline u8 *getbuf(void) {
    if ((u8)(D_004BDECC[0] == D_004BDED0[0]) == 0) return D_004BDEC0[0] + D_004BDEC8[0] * 0x118000; return 0;
}

s32 Movie_DecodeFrame_1_001E9EF0(M *mp) {
    s32 r = 1;
    u8 *p;
    while (!sceMpegIsEnd(mp)) {
        if (mp->xA8 == 1) { r = -1; break; }
        while ((p = getbuf()) == 0) RotateThreadReadyQueue(1);
        sceMpegGetPicture(mp, p, 0x460);
        DIntr();
        *(s32 *)(D_004BDEC4[0] + D_004BDEC8[0] * 0x35640) = 2;
        D_004BDECC[0]++;
        D_004BDEC8[0] = (D_004BDEC8[0] + 1) % D_004BDED0[0];
        EIntr();
        RotateThreadReadyQueue(1);
    }
    sceMpegReset(mp);
    return r;
}

/* Movie_DecodeWrap_0_001EA060 */
#define D_004BDECC D_004BDECC__as_Movie_DecodeWrap_0_001EA060
extern volatile s32 D_004BDECC__as_Movie_DecodeWrap_0_001EA060[];
#define MovieVideo_Clear_0_001EB060 MovieVideo_Clear_0_001EB060__as_Movie_DecodeWrap_0_001EA060
void MovieVideo_Clear_0_001EB060__as_Movie_DecodeWrap_0_001EA060(void *p);
#define Movie_DecodeFrame_1_001E9EF0 Movie_DecodeFrame_1_001E9EF0__as_Movie_DecodeWrap_0_001EA060
void Movie_DecodeFrame_1_001E9EF0__as_Movie_DecodeWrap_0_001EA060(Obj_Movie_DecodeWrap_0_001EA060 *o);

void Movie_DecodeWrap_0_001EA060(Obj_Movie_DecodeWrap_0_001EA060 *o)
{
    MovieVideo_Clear_0_001EB060(o->sub);
    D_004BDECC[0] = 0;
    D_004BDEC8[0] = 0;
    Movie_DecodeFrame_1_001E9EF0(o);
    while (D_004BDECC[0]) {
    }
    o->xa8 = 3;
}
#undef MovieVideo_Clear_0_001EB060
#undef Movie_DecodeFrame_1_001E9EF0
#undef D_004BDECC

/* MovieVideo_PutData_0_001EA0D0 */
#define MovieVideo_GetSpace_0_001EAF60 MovieVideo_GetSpace_0_001EAF60__as_MovieVideo_PutData_0_001EA0D0
void MovieVideo_GetSpace_0_001EAF60__as_MovieVideo_PutData_0_001EA0D0(void *, s32 *, s32 *, s32 *, s32 *);

static inline s32 put_MovieVideo_PutData_0_001EA0D0(u8 *p1, s32 n1, u8 *p2, s32 n2, u8 *s1, s32 l1, u8 *s2, s32 l2) {
    if (n1 + n2 < l1 + l2) return 0;
    if (n1 <= l1) {
        memcpy(p1, s1, n1);
        memcpy(p2, s1 + n1, l1 - n1);
        memcpy(p2 + l1 - n1, s2, l2);
    } else if (!(l2 < n1 - l1)) {
        memcpy(p1, s1, l1);
        memcpy(p1 + l1, s2, n1 - l1);
        memcpy(p2, s2 + n1 - l1, l2 - (n1 - l1));
    } else {
        memcpy(p1, s1, l1);
        memcpy(p1 + l1, s2, l2);
    }
    return l1 + l2;
}

s32 MovieVideo_PutData_0_001EA0D0(P_MovieVideo_PutData_0_001EA0D0 *p) {
    s32 a1;
    s32 a2;
    T_MovieVideo_PutData_0_001EA0D0 v;
    s32 n1;
    s32 n2;
    s32 r;
    u8 *p1;
    u8 *p2;
    v = gMovieSdata_00201E74;
    MovieVideo_GetSpace_0_001EAF60(p->x48, &a1, &n1, &a2, &n2);
    if (n1 + n2 < 4) return 0;
    p1 = (u8 *)(((u32)a1 & 0x0FFFFFFF) | 0x20000000);
    p2 = (u8 *)(((u32)a2 & 0x0FFFFFFF) | 0x20000000);
    r = put_MovieVideo_PutData_0_001EA0D0(p1, n1, p2, n2, (u8 *)&v, 4, NULL, 0);
    WaitSema(*gMovieBss_004BDFC8);
    *D_004BDF9C += r;
    *gMovieBss_004BDFD0 += r;
    SignalSema(*gMovieBss_004BDFC8);
    WaitSema(p->x88);
    p->x5C = (p->x5C + 0x7FF) / 0x800 * 0x800;
    SignalSema(p->x88);
    if (p->xA8 == 0) p->xA8 = 2;
    return 1;
}
#undef MovieVideo_GetSpace_0_001EAF60

/* MovieVideo_GetFrame_0_001EA2E0 */
s32 MovieVideo_GetFrame_0_001EA2E0(P_MovieVideo_GetFrame_0_001EA2E0 *p, O_MovieVideo_GetFrame_0_001EA2E0 *out) {
    s32 madr;
    s32 a;
    u32 ctrl;
    u32 size;
    s32 found;
    s32 cnt;
    s32 n;
    s32 i;
    s32 base;
    s32 last;
    s32 idx;
    s32 m;
    u32 pos;
    u32 t;
    found = 0;
    madr = *(volatile s32 *)0x1000B410;
    cnt = 0;
    ctrl = *(volatile u32 *)0x10002020;
    a = p->x38 & 0x7F;
    size = p->x8 << 11;
    WaitSema(p->x40);
    out->x0 = -1;
    out->x8 = -1;
    n = p->x58;
    t = ((ctrl >> 16) & 3); t += ((ctrl >> 8) & 0xF);
    madr = madr - t * 16;
    pos = (size + (madr + (a >> 3)) - p->x0) % size;
    last = p->x5C;
    if (n > 0) {
        base = last - n;
        pos += size;
        for (i = 0; i < n && found == 0; i++) {
            idx = (i + (p->x54 + base)) % p->x54;
            if ((s32)(pos - p->x50[idx].x10) % (s32)size < p->x50[idx].x14) {
                if (p->x50[idx].x0 >= 0) {
                    out->x0 = p->x50[idx].x0;
                    out->x8 = p->x50[idx].x8;
                    p->x50[idx].x0 = -1;
                    p->x50[idx].x8 = -1;
                }
                found = 1;
            } else {
                cnt++;
            }
        }
        m = p->x58;
        m = (m < cnt) ? m : cnt;
        p->x58 -= m;
    }
    SignalSema(p->x40);
    return 1;
}

/* MovieVideo_FindTimestamp_0_001EA4D0 */
#define MovieVideo_CheckTs_0_001EA690 MovieVideo_CheckTs_0_001EA690__as_MovieVideo_FindTimestamp_0_001EA4D0
s32 MovieVideo_CheckTs_0_001EA690__as_MovieVideo_FindTimestamp_0_001EA4D0(O_MovieVideo_FindTimestamp_0_001EA4D0 *o, s32 pos);

static inline void rel(E_MovieVideo_FindTimestamp_0_001EA4D0 *e) {
    if (e->a >= 0) {
        e->a = -1;
        e->b = -1;
        e->pos = 0;
        e->len = 0;
    }
}

static inline void dec(O_MovieVideo_FindTimestamp_0_001EA4D0 *o) {
    s32 c = o->cnt - 1;
    o->cnt = c < 0 ? 0 : c;
}

s32 MovieVideo_FindTimestamp_0_001EA4D0(O_MovieVideo_FindTimestamp_0_001EA4D0 *o, B_MovieVideo_FindTimestamp_0_001EA4D0 *b) {
    E_MovieVideo_FindTimestamp_0_001EA4D0 *e;
    s32 i;
    s32 sz;
    s32 go = 1;
    s32 d;
    i = (o->n + (o->head - o->cnt)) % o->n;
    sz = o->x8 << 11;
    if (o->cnt > 0) {
        do {
            e = &o->ents[i];
            if (e->len == 0 || b->len == 0)
                break;
            if (MovieVideo_CheckTs_0_001EA690(o, b->pos)) {
                rel(e);
                dec(o);
            } else if ((e->pos + sz - b->pos) % sz < b->len) {
                d = b->pos + b->len - e->pos;
                e->pos = e->pos + d;
                e->len = e->len - d;
                if (e->len == 0) {
                    rel(e);
                    dec(o);
                }
            } else {
                go = 0;
            }
            i = (i + 1) % o->n;
        } while (go);
    }
    return 0;
}
#undef MovieVideo_CheckTs_0_001EA690

/* MovieVideo_CheckTs_0_001EA690 */
s32 MovieVideo_CheckTs_0_001EA690(S_MovieVideo_CheckTs_0_001EA690 *a0, s32 a1) {
    s32 n;
    s32 r;
    s32 sz;
    s32 found;
    s32 last;
    s32 i;
    E_MovieVideo_CheckTs_0_001EA690 *e;
    found = 0;
    n = a0->x58;
    r = 0;
    last = a0->x5C;
    sz = a0->x8 << 11;
    if (n > 0) {
        for (i = 0; i < n && found == 0; i++) {
            e = &a0->x50[(i + (a0->x54 + (last - n))) % a0->x54];
            if ((a1 + sz - e->x10) % sz < e->x14) {
                found = 1;
                r = 1;
            }
        }
    }
    return r;
}

/* MovieVideo_DmaHandler_0_001EA750 */
#define R(a) (*(volatile u32 *)(a))
#define OR(a, b) ((a) | (b))

s32 MovieVideo_DmaHandler_0_001EA750(S_MovieVideo_DmaHandler_0_001EA750 *s) {
    s32 v;
    u32 cmd;
    u32 madr;
    u32 qwc;
    u32 tadr;
    u32 chcr;
    u32 ctrl;
    s32 fifo;
    u32 cur;
    s32 same;
    u32 sz;
    s32 n;
    u32 base;
    s32 d;
    u32 end;
    u32 i;
    u32 j;
    u32 a;

    ctrl = s->x38;
    a = (ctrl >> 16) & 3;
    cmd = ctrl & 0x7F;
    fifo = a + ((ctrl >> 8) & 0xF);
    madr = s->x1C - fifo * 16;
    qwc = s->x24 + fifo;
    tadr = s->x20;
    chcr = OR(s->x28, 0x100);
    WaitSema(s->sema);
    if (madr < s->x0) {
        qwc = (s->x0 - madr) >> 4;
        same = 1;
        n = s->x8;
        tadr = s->x4 & 0x0FFFFFFF;
        sz = n << 11;
        madr += sz;
        if (s->x1C != s->x0 && s->x1C != s->x0 + sz) same = 0;
        chcr = (s->x28 & 0x0FFFFFFF) | ((same ? 0 : 3) << 28) | 0x100;
        d = (n - s->xC) % n;
        if (0 > d || d >= s->x10) {
            s->xC = n - 1;
            s->x10++;
        }
    } else {
        n = (*s).x8;
        base = s->x4;
        cur = s->x1C;
        end = (base + (n + 1) * 16) & 0x0FFFFFFF;
        i = (cur == end) ? 0 : (cur - s->x0) >> 11;
        j = (madr == end) ? 0 : (madr - s->x0) >> 11;
        if (i != j) {
            tadr = (base + i * 16) & 0x0FFFFFFF;
            qwc = (s->x0 + (i << 11) - madr) >> 4;
            same = (s->x0 + (cur - s->x0) % (u32)(n << 11) == s->x0 + (((s->xC + s->x10) % n) << 11)) ? 0 : 3;
            chcr = (s->x28 & 0x0FFFFFFF) | (same << 28) | 0x100;
            d = (s32)(j + n - s->xC) % n;
            if (0 > d || d >= s->x10) {
                s->xC = j;
                s->x10++;
            }
        }
    }
    if (s->x2C && s->x30) {
        R(0x1000B010) = s->x2C;
        R(0x1000B020) = s->x30;
        v = s->x34 | 0x100;
        DIntr();
        R(0x1000F590) = R(0x1000F520) | 0x10000;
        R(0x1000B000) = v;
        R(0x1000F590) = R(0x1000F520) & ~0x10000;
        EIntr();
    }
    if (s->x10) {
        while ((s32)R(0x10002010) < 0);
        R(0x10002000) = cmd;
        while ((s32)R(0x10002010) < 0);
    }
    R(0x1000B410) = madr;
    R(0x1000B430) = tadr;
    R(0x1000B420) = qwc;
    if (s->x10) {
        DIntr();
        R(0x1000F590) = R(0x1000F520) | 0x10000;
        R(0x1000B400) = chcr;
        R(0x1000F590) = R(0x1000F520) & ~0x10000;
        EIntr();
    }
    R(0x10002010) = s->x3C;
    s->x44 = 1;
    SignalSema(s->sema);
    return 1;
}

/* MovieVideo_Reset_0_001EAB10 */
#define R(a) (*(volatile u32 *)(a))

s32 MovieVideo_Reset_0_001EAB10(S_MovieVideo_Reset_0_001EAB10 *s) {
    WaitSema(s->sema);
    s->x44 = 0;
    DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B400) = 5;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    EIntr();
    s->r[0] = R(0x1000B410);
    s->r[1] = R(0x1000B430);
    s->r[2] = R(0x1000B420);
    s->r[3] = R(0x1000B400);
    while (R(0x10002010) & 0xF0);
    DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B000) = 0;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    EIntr();
    s->r[4] = R(0x1000B010);
    s->r[5] = R(0x1000B020);
    s->r[6] = R(0x1000B000);
    s->r[7] = R(0x10002020);
    s->a = R(0x10002010);
    SignalSema(s->sema);
    return 1;
}

/* MovieVideo_IpuHandler_0_001EAC70 */
#define R(a) (*(volatile u32 *)(a))

s32 MovieVideo_IpuHandler_0_001EAC70(S_MovieVideo_IpuHandler_0_001EAC70 *f) {
    u32 chcr, madr;
    s32 isNew = 0;
    u64 hi;
    u32 e;
    s32 id, consume, rs, rn, i, last;
    WaitSema(f->sema);
    if (f->x44 == 0) return 0;
    DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B400) = 5;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    EIntr();
    chcr = R(0x1000B400);
    madr = R(0x1000B410);
    if (madr == ((f->tags + (f->n + 1) * 16) & 0x0FFFFFFF)) {
        id = 0;
    } else {
        id = (madr - f->base) >> 11;
    }
    consume = (id + f->n - f->xC) % f->n;
    f->xC = (f->xC + consume) % f->n;
    f->x10 -= consume;
    rs = (f->xC + f->x10) % f->n;
    rn = f->x14 / 2048;
    f->x14 = f->x14 % 2048;
    if (rn > 0) {
        isNew = 1;
        last = (f->n + (f->xC + f->x10 - 1)) % f->n;
        ((u64 *)f->tags)[last * 2] = ((u64)(f->base + last * 0x800) << 32) | 0x30000080;
    }
    for (i = 0; i < rn; i++) {
        hi = (u64)(f->base + rs * 0x800) << 32;
        if (i == rn - 1) e = 0; else e = 3;
        ((u64 *)f->tags)[rs * 2] = hi | ((u64)e << 28) | 0x80;
        rs = (rs + 1) % f->n;
    }
    f->x10 += rn;
    if (f->x10 != 0) {
        if (isNew) chcr = (chcr & 0x0FFFFFFF) | 0x30000000;
        DIntr();
        R(0x1000F590) = R(0x1000F520) | 0x10000;
        R(0x1000B400) = chcr | 0x100;
        R(0x1000F590) = R(0x1000F520) & ~0x10000;
        EIntr();
    }
    SignalSema(f->sema);
    return 1;
}

/* MovieVideo_GetSpace_0_001EAF60 */
void MovieVideo_GetSpace_0_001EAF60(S_MovieVideo_GetSpace_0_001EAF60 *s, s32 *a1, s32 *a2, s32 *a3, s32 *a4) {
    s32 b, a, r, n;
    WaitSema(s->x40);
    a = s->x10; b = s->x14;
    r = (s32)((u8 *)((s->xC + a) * 0x800) + b) % s->x18;
    n = (s->x8 - 2 - a) * 0x800 - b;
    if (s->x18 - r >= n) {
        *a1 = s->x0 + r;
        *a2 = n;
        *a3 = 0;
        *a4 = 0;
    } else {
        *a1 = s->x0 + r;
        *a2 = s->x18 - r;
        *a3 = s->x0;
        *a4 = n - (s->x18 - r);
    }
    SignalSema(s->x40);
}

/* MovieVideo_Clear_0_001EB060 */
s32 MovieVideo_Clear_0_001EB060(S_MovieVideo_Clear_0_001EB060 *p) {
    s32 i;
    p->xC = 0;
    p->x10 = 0;
    p->x14 = 0;
    p->x44 = 1;
    p->x48 = 0;
    p->x1C = 0;
    p->x20 = 0;
    p->x24 = 0;
    p->x28 = 0;
    for (i = 0; i < p->n; i++) {
        ((u64 *)p->tags)[i * 2] = ((u64)(p->base + i * 0x800) << 32) | 0x30000080;
    }
    ((u64 *)p->tags)[i * 2] = ((u64)(p->tags & 0x0FFFFFFF) << 32) | 0x20000000;
    *(volatile s32 *)0x1000B420 = 0;
    *(volatile s32 *)0x1000B410 = p->base & 0x0FFFFFFF;
    *(volatile s32 *)0x1000B430 = p->tags & 0x0FFFFFFF;
    DIntr();
    *(volatile s32 *)0x1000F590 = *(volatile s32 *)0x1000F520 | 0x10000;
    *(volatile s32 *)0x1000B400 = 5;
    *(volatile s32 *)0x1000F590 = *(volatile s32 *)0x1000F520 & ~0x10000;
    EIntr();
    return 1;
}

/* MovieVideo_Create_0_001EB1A0 */
#define EIntr EIntr__as_MovieVideo_Create_0_001EB1A0
void EIntr__as_MovieVideo_Create_0_001EB1A0(s32, s32);
s32 MovieVideo_Create_0_001EB1A0(void *o0, u32 addr0, void *tags0, s32 n, E_MovieVideo_GetFrame_0_001EA2E0 *e, s32 cnt) {
    u32 t;
    O_MovieVideo_Create_0_001EB1A0 *o;
    s32 addr;
    T_MovieVideo_Create_0_001EB1A0 *tags;
    s32 i;
    SemaParam sp;
    s32 a;
    s32 b;
    o = o0;
    tags = tags0;
    t = (u32)tags0 & 0x0FFFFFFF;
    addr = addr0;
    o->x0 = addr;
    o->x4 = t | 0x20000000;
    o->x8 = n;
    o->xC = 0;
    o->x10 = 0;
    o->x14 = 0;
    o->x18 = n << 11;
    o->x44 = 1;
    o->x48 = 0;
    o->x50 = e;
    o->x54 = cnt;
    o->x58 = 0;
    o->x5C = 0;
    for (i = 0; i < cnt; i++) {
        o->x50[i].x0 = -1;
        o->x50[i].x8 = -1;
        o->x50[i].x10 = 0;
        o->x50[i].x14 = 0;
    }
    sp.init_count = 1;
    sp.max_count = 1;
    o->x40 = CreateSema(&sp);
    for (i = 0; i < o->x8; i++) {
        tags[i].a = ((u64)(u32)addr << 32) | 0x30000080;
        addr += 0x800;
    }
    tags[i].a = ((u64)t << 32) | 0x20000000;
    *(volatile s32 *)0x1000B420 = 0;
    *(volatile s32 *)0x1000B410 = o->x0 & 0x0FFFFFFF;
    *(volatile s32 *)0x1000B430 = o->x4 & 0x0FFFFFFF;
    DIntr();
    b = *(s32 *)0x1000F520;
    a = b | 0x10000;
    *(s32 *)0x1000F590 = a;
    *(s32 *)0x1000B400 = 5;
    *(s32 *)0x1000F590 = (s32) (*(s32 *)0x1000F520 & 0xFFFEFFFF);
    EIntr(a, b);
    return 1;
}
#undef EIntr

/* MovieAudio_Transfer_0_001EB540 */

static inline void dma_MovieAudio_Transfer_0_001EB540(s32 src, s32 dst, s32 size) {
    Dma_MovieAudio_Transfer_0_001EB540 d;
    s32 id;
    d.src = src;
    d.dst = dst;
    d.size = size;
    d.attr = 0;
    FlushCache(0);
    id = sceSifSetDma(&d, 1);
    while (sceSifDmaStat(id) >= 0) {}
}

s32 MovieAudio_Transfer_0_001EB540(s32 p1, s32 n1, s32 p2, s32 n2, s32 s1, s32 l1, s32 s2, s32 l2) {
    s32 e;
    if (n1 + n2 < l1 + l2) {
        e = (l1 + l2) - (n1 + n2);
        if (e >= l2) {
            l1 -= e - l2;
            l2 = 0;
        } else {
            l2 -= e;
        }
    }
    if (l1 >= n1) {
        if (n1 > 0) dma_MovieAudio_Transfer_0_001EB540(s1, p1, n1);
        if (l1 - n1 > 0) dma_MovieAudio_Transfer_0_001EB540(s1 + n1, p2, l1 - n1);
        if (l2 > 0) dma_MovieAudio_Transfer_0_001EB540(s2, p2 + l1 - n1, l2);
    } else if (l2 >= n1 - l1) {
        if (l1 > 0) dma_MovieAudio_Transfer_0_001EB540(s1, p1, l1);
        if (n1 - l1 > 0) dma_MovieAudio_Transfer_0_001EB540(s2, p1 + l1, n1 - l1);
        if (l2 - (n1 - l1) > 0) dma_MovieAudio_Transfer_0_001EB540(s2 + n1 - l1, p2, l2 - (n1 - l1));
    } else {
        if (l1 > 0) dma_MovieAudio_Transfer_0_001EB540(s1, p1, l1);
        if (l2 > 0) dma_MovieAudio_Transfer_0_001EB540(s2, p1 + l1, l2);
    }
    return l1 + l2;
}

/* MovieAudio_Send_0_001EB8B0 */
s32 MovieAudio_Send_0_001EB8B0(S_MovieAudio_Send_0_001EB8B0 *s)
{
    s32 r;
    s32 src, n1, src2, n2;
    s32 b, t, d, m1, m2, q;
    r = 0;
    switch (s->state) {
    case 0:
        return 0;
    case 1:
        src = s->buf + s->x54 % s->size;
        n1 = s->size - s->x54;
        src2 = 0;
        n2 = 0;
        break;
    case 2:
        b = s->buf;
        t = sceSdRemote(1, 0x8100, 0, 0) & 0xFFFFFF;
        src = s->size;
        t -= b;
        t = (t + src - s->pos - 0x400) % src;
        t = t / 1024 * 1024;
        n1 = src - s->pos;
        if (!(n1 < t)) {
            src = b + s->pos;
            n1 = t;
            src2 = 0;
            n2 = 0;
        } else {
            src2 = s->buf;
            n2 = t - n1;
            src = src2 + s->pos;
        }
        break;
    case 3:
        return 0;
    }
    d = s->x30 + (s->x3c + (s->x34 - s->x38)) % s->x3c;
    q = s->x38 / 1024 * 1024;
    m1 = s->x30 + s->x3c - d;
    if (q < m1) m1 = q;
    m2 = q - m1;
    if (n1 + n2 >= 0x400 && m1 + m2 >= 0x400)
        r = MovieAudio_Transfer_0_001EB540(src, n1, src2, n2, d, m1, s->x30, m2);
    s->x38 -= r;
    s->x54 += r;
    s->pos = (s->pos + r) % s->size;
    return r;
}

/* MovieAudio_GetSpace_0_001EBAB0 */
void MovieAudio_GetSpace_0_001EBAB0(S_MovieAudio_GetSpace_0_001EBAB0 *s, s32 *a1, s32 *a2, s32 *a3, s32 *a4) {
    s32 n;
    if (s->x0 == 0) {
        *a1 = s->x2C + (s32)s + 4;
        *a2 = 0x28 - s->x2C;
        *a3 = s->x30;
        *a4 = s->x3C;
        return;
    }
    n = s->x3C - s->x38;
    if (s->x3C - s->x34 >= n) {
        *a1 = s->x30 + s->x34;
        *a2 = n;
        *a3 = 0;
        *a4 = 0;
    } else {
        *a1 = s->x30 + s->x34;
        *a2 = s->x3C - s->x34;
        *a3 = s->x30;
        *a4 = n - (s->x3C - s->x34);
    }
}

/* MovieAudio_Reset_3_001EBB70 */
s32 MovieAudio_Reset_3_001EBB70(s32 *p)
{
    sceSdRemote(1, 0x8010, 0xF80, 0);
    sceSdRemote(1, 0x8010, 0x1080, 0);
    sceSdRemote(1, 0x8010, 0xF81, 0);
    sceSdRemote(1, 0x8010, 0x1081, 0);
    sceSdRemote(1, 0x8010, 0xD81, 0);
    sceSdRemote(1, 0x8010, 0xE81, 0);
    sceSdRemote(1, 0x8010, 0x980, 0);
    sceSdRemote(1, 0x8010, 0xA80, 0);
    sceSdRemote(1, 0x8010, 0x981, 0);
    sceSdRemote(1, 0x8010, 0xA81, 0);
    sceSdRemote(1, 0x80E0, 0, 2, 0, 0);
    sceSdRemote(1, 0x80E0, 1, 2, 0, 0);
    p[0] = 0;
    p[11] = 0;
    p[13] = 0;
    p[14] = 0;
    p[16] = 0;
    p[21] = 0;
    p[19] = 0;
    p[20] = 0;
    return 0;
}

/* MovieAudio_Create_1_001EBCC0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */

s32 MovieAudio_Create_1_001EBCC0(S_MovieAudio_Create_1_001EBCC0 *a, s32 a1, s32 a2, s32 a3) {
    Dma_MovieAudio_Create_1_001EBCC0 d;
    s32 id;
    s32 v;
    a->x0 = 0;
    a->x2C = 0;
    a->x30 = a1;
    a->x34 = 0;
    a->x38 = 0;
    a->x3C = a2;
    a->x40 = 0;
    a->x54 = 0;
    a->x48 = a3;
    a->x4C = 0;
    a->x50 = 0;
    a->x44 = sceSifAllocIopHeap(a3);
    if (a->x44 < 0) return 0;
    a->x58 = sceSifAllocIopHeap(0x800);
    if (a->x58 < 0) return 0;
    memset(D_004BD6C0, 0, 0x800);
    v = a->x58;
    d.src = D_004BD6C0;
    d.dst = v;
    d.size = 0x800;
    d.attr = 0;
    FlushCache(0);
    id = sceSifSetDma(&d, 1);
    while (sceSifDmaStat(id) >= 0) {}
    v = gMovieBss_004BE0D0[0];
    for (id = 0; id < 2; id++) {
        sceSdRemote(1, 0x8010, id | 0x980, v);
        sceSdRemote(1, 0x8010, id | 0xA80, v);
    }
    return 1;
}

/* MovieCb_AudioStream_0_001EBE10 */
#define D_004BDEE0 D_004BDEE0__as_MovieCb_AudioStream_0_001EBE10
extern volatile S_MovieCb_AudioStream_0_001EBE10 D_004BDEE0__as_MovieCb_AudioStream_0_001EBE10;
#define MovieAudio_GetSpace_0_001EBAB0 MovieAudio_GetSpace_0_001EBAB0__as_MovieCb_AudioStream_0_001EBE10
void MovieAudio_GetSpace_0_001EBAB0__as_MovieCb_AudioStream_0_001EBE10(volatile S_MovieCb_AudioStream_0_001EBE10 *s, u8 **a1, s32 *a2, u8 **a3, s32 *a4);
s32 MovieCb_AudioStream_0_001EBE10(s32 a0, H *h, u8 *buf0) {
    u8 *D2;
    s32 t;
    u8 *buf;
    u8 *src;
    s32 rest;
    s32 total;
    u8 *D1;
    s32 n;
    s32 N1;
    s32 m;
    s32 size;
    u8 *end;
    u8 *d1;
    u8 *d2;
    s32 n1;
    s32 n2;
    u32 k;
    s32 left;
    buf = buf0;
    src = h->x8 + 4;
    size = *(s32 *)(buf + 0x50008);
    end = buf + size;
    if (src >= end) src -= size;
    n = end - src;
    m = h->xC - 4;
    n = (m < n) ? m : n;
    rest = m - n;
    MovieAudio_GetSpace_0_001EBAB0(&D_004BDEE0, &d1, &n1, &d2, &n2);
    total = n + rest;
    D2 = d2;
    N1 = n1;
    D1 = d1;
    if (N1 + n2 < total) {
        total = 0;
    } else if (n >= N1) {
        memcpy(D1, src, N1);
        memcpy(D2, src + N1, n - N1);
        memcpy(D2 + n - N1, buf, rest);
    } else {
        t = N1 - n;
        if (rest >= t) {
            memcpy(D1, src, n);
            memcpy(D1 + n, buf, t);
            memcpy(D2, buf + N1 - n, rest - t);
        } else {
            memcpy(D1, src, n);
            memcpy(D1 + n, buf, rest);
        }
    }
    left = total;
    if (D_004BDEE0.x0 == 0) {
        k = 0x28 - D_004BDF0C[0];
        k = (k < (u32)total) ? k : total;
        D_004BDF0C[0] += k;
        if ((u32)D_004BDF0C[0] >= 0x28U) D_004BDEE0.x0 = 1;
        left -= k;
    }
    D_004BDF14[0] = (D_004BDF14[0] + left) % D_004BDF1C[0];
    D_004BDF18[0] += left;
    D_004BDF20[0] += left;
    return total > 0;
}
#undef MovieAudio_GetSpace_0_001EBAB0
#undef D_004BDEE0

/* MovieCb_VideoStream_0_001EC070 */
#define memcpy memcpy__as_MovieCb_VideoStream_0_001EC070
void memcpy__as_MovieCb_VideoStream_0_001EC070(s32, s32, s32);
#define MovieVideo_FindTimestamp_0_001EA4D0 MovieVideo_FindTimestamp_0_001EA4D0__as_MovieCb_VideoStream_0_001EC070
void MovieVideo_FindTimestamp_0_001EA4D0__as_MovieCb_VideoStream_0_001EC070(s32 *, E_MovieVideo_FindTimestamp_0_001EA4D0 *);
#define MovieVideo_GetSpace_0_001EAF60 MovieVideo_GetSpace_0_001EAF60__as_MovieCb_VideoStream_0_001EC070
void MovieVideo_GetSpace_0_001EAF60__as_MovieCb_VideoStream_0_001EC070(s32 *, s32 *, s32 *, s32 *, s32 *);
#define D_004BDF88 D_004BDF88__as_MovieCb_VideoStream_0_001EC070
extern O_MovieCb_VideoStream_0_001EC070 D_004BDF88__as_MovieCb_VideoStream_0_001EC070;

s32 MovieCb_VideoStream_0_001EC070(s32 a0, P_MovieCb_VideoStream_0_001EC070 *p, u8 *buf) {
    s32 pb;
    s32 r;
    u8 *bb;
    u32 n1;
    s32 n2;
    s32 pa;
    s32 total;
    u8 *src;
    s32 n;
    u32 len;
    s32 a;
    s32 b;
    s32 an;
    s32 bn;
    E_MovieVideo_FindTimestamp_0_001EA4D0 e;

    src = p->src;
    len = p->len;
    bb = buf;
    n1 = bb + *(s32 *)(bb + 0x50008) - src;
    n1 = len < n1 ? len : n1;
    n2 = len - n1;
    MovieVideo_GetSpace_0_001EAF60((s32 *)&D_004BDF88, &a, &an, &b, &bn);
    n = an;
    total = n1 + n2;
    pa = ((u32)a & 0x0FFFFFFF) | 0x20000000;
    pb = ((u32)b & 0x0FFFFFFF) | 0x20000000;
    if (n + bn < total) {
        total = 0;
    } else if ((s32)n1 >= n) {
        memcpy(pa, (s32)src, n);
        memcpy(pb, (s32)src + n, n1 - n);
        memcpy(pb + n1 - n, (s32)bb, n2);
    } else {
        r = n - n1;
        if (n2 >= r) {
            memcpy(pa, (s32)src, n1);
            memcpy(pa + n1, (s32)bb, r);
            memcpy(pb, (s32)bb + n - n1, n2 - r);
        } else {
            memcpy(pa, (s32)src, n1);
            memcpy(pa + n1, (s32)bb, n2);
        }
    }
    if (total > 0) {
        { s64 ta = p->a; s64 tb = p->b; e.a = ta; e.b = tb; }
        e.pos = a - D_004BDF88.x0;
        e.len = total;
        WaitSema(D_004BDF88.sema);
        if (D_004BDF88.cnt < D_004BDF88.n) {
            MovieVideo_FindTimestamp_0_001EA4D0((s32 *)&D_004BDF88, &e);
            D_004BDF88.ents[D_004BDF88.head].a = e.a;
            D_004BDF88.ents[D_004BDF88.head].b = e.b;
            D_004BDF88.ents[D_004BDF88.head].pos = e.pos;
            D_004BDF88.ents[D_004BDF88.head].len = e.len;
            D_004BDF88.cnt++;
            D_004BDF88.head = (D_004BDF88.head + 1) % D_004BDF88.n;
        }
        SignalSema(D_004BDF88.sema);
    }
    WaitSema(D_004BDF88.sema);
    D_004BDF88.x14 += total;
    D_004BDF88.tot += total;
    SignalSema(D_004BDF88.sema);
    return total > 0;
}
#undef memcpy
#undef MovieVideo_FindTimestamp_0_001EA4D0
#undef MovieVideo_GetSpace_0_001EAF60
#undef D_004BDF88

/* Movie_IdleThread_1_001EC3C0 */

void Movie_IdleThread_1_001EC3C0(void) {
loop_1:
    RotateThreadReadyQueue(1);
    goto loop_1;
}

/* Movie_Shutdown_1_001EC3E0 */
#define EIntr EIntr__as_Movie_Shutdown_1_001EC3E0
void EIntr__as_Movie_Shutdown_1_001EC3E0(s32, s32);
#define printf printf__as_Movie_Shutdown_1_001EC3E0
void printf__as_Movie_Shutdown_1_001EC3E0(s32 *, s32 *, s32);
#define gMovieRodata_00201920 gMovieRodata_00201920__as_Movie_Shutdown_1_001EC3E0
extern s32 gMovieRodata_00201920__as_Movie_Shutdown_1_001EC3E0[];
#define gMovieRodata_00201940 gMovieRodata_00201940__as_Movie_Shutdown_1_001EC3E0
extern s32 gMovieRodata_00201940__as_Movie_Shutdown_1_001EC3E0[];

void Movie_Shutdown_1_001EC3E0(void) {
    s32 temp_4;
    s32 temp_5;
    s32 var_16;

    TerminateThread((*gMovieBss_004BE040));
    DeleteThread((*gMovieBss_004BE040));
    TerminateThread((*D_004BE044));
    DeleteThread((*D_004BE044));
    DisableDmac(2);
    RemoveDmacHandler(2, (*gMovieBss_004BDFF0));
    DisableIntc(2);
    RemoveIntcHandler(2, (*D_004BDFF4));
    DIntr();
    temp_5 = *(s32 *)0x1000F520;
    temp_4 = temp_5 | 0x10000;
    *(s32 *)0x1000F590 = temp_4;
    *(s32 *)0x1000B400 = 5;
    *(s32 *)0x1000F590 = (s32) (*(s32 *)0x1000F520 & 0xFFFEFFFF);
    EIntr(temp_4, temp_5);
    *(s32 *)0x1000B420 = 0;
    *(s32 *)0x1000B410 = 0;
    *(s32 *)0x1000B430 = 0;
    DeleteSema((*gMovieBss_004BDFC8));
    sceMpegDelete(gMovieBss_004BDF40);
    if (sceSifFreeSysMemory((*D_004BDF24)) < 0) {
        printf(gMovieRodata_00201920, gMovieRodata_00201940, 0x407);
    }
    if (sceSifFreeSysMemory((*gMovieBss_004BDF38)) < 0) {
        printf(gMovieRodata_00201920, gMovieRodata_00201940, 0x409);
    }
    var_16 = 0;
    do {
        sceSdRemote(1, 0x8010, var_16 | 0x980, 0);
        sceSdRemote(1, 0x8010, var_16 | 0xA80, 0);
        var_16 += 1;
    } while (var_16 < 2);
    if ((*D_004BE04C) != 0) {
        do {

        } while (!sceCdStStop() != 0);
        if (sceSifFreeSysMemory((*gMovieBss_004BE078)) < 0) {
            printf(gMovieRodata_00201920, gMovieRodata_00201940, 0xF6F);
        }
    } else {
        sceClose((*gMovieBss_004BE07C));
    }
}
#undef EIntr
#undef printf
#undef gMovieRodata_00201920
#undef gMovieRodata_00201940

/* Movie_Init_1_001EC5E0 */
#define MovieAudio_Create_1_001EBCC0 MovieAudio_Create_1_001EBCC0__as_Movie_Init_1_001EC5E0
void MovieAudio_Create_1_001EBCC0__as_Movie_Init_1_001EC5E0(void *, s32, s32, s32);
#define MovieVideo_Create_0_001EB1A0 MovieVideo_Create_0_001EB1A0__as_Movie_Init_1_001EC5E0
void MovieVideo_Create_0_001EB1A0__as_Movie_Init_1_001EC5E0(void *, s32, s32, s32, s32, s32);
#define Movie_SetupDisplayPackets_1_001E95B0 Movie_SetupDisplayPackets_1_001E95B0__as_Movie_Init_1_001EC5E0
void Movie_SetupDisplayPackets_1_001E95B0__as_Movie_Init_1_001EC5E0(void *, u8 *, s32, s32, s32);
#define MovieFile_Open_3_001E88C0 MovieFile_Open_3_001E88C0__as_Movie_Init_1_001EC5E0
s32 MovieFile_Open_3_001E88C0__as_Movie_Init_1_001EC5E0(void *, s32);
#define printf printf__as_Movie_Init_1_001EC5E0
s32 printf__as_Movie_Init_1_001EC5E0(void *, ...);
#define D_004BDEC0 D_004BDEC0__as_Movie_Init_1_001EC5E0
extern s32 D_004BDEC0__as_Movie_Init_1_001EC5E0[];
#define D_004BDEC4 D_004BDEC4__as_Movie_Init_1_001EC5E0
extern u8 *volatile D_004BDEC4__as_Movie_Init_1_001EC5E0[];

void Movie_Init_1_001EC5E0(s32 arg0) {
    s32 c;
    s32 b;
    s32 a;
    s32 i;
    TP tp;
    *(volatile s32 *)0x1000E000 |= 3;
    *(volatile s32 *)0x1000E010 = 4;
    *(s32 *)(gMovieBss_004BE038[0] + 0x50004) = 0;
    *(s32 *)(gMovieBss_004BE038[0] + 0x50000) = 0;
    *(s32 *)(gMovieBss_004BE038[0] + 0x50008) = 0x50000;
    a = gMovieBss_004BE030[0];
    b = gMovieBss_004BE024[0];
    c = gMovieBss_004BE020[0];
    sceMpegCreate(gMovieBss_004BDF40, gMovieBss_004BE018[0], 0x13C768);
    sceMpegAddCallback(gMovieBss_004BDF40, 0, MovieCb_Nop_2_001E9EE0, 0);
    sceMpegAddCallback(gMovieBss_004BDF40, 1, MovieCb_AudioYield_0_001E9EA0, 0);
    sceMpegAddCallback(gMovieBss_004BDF40, 2, MovieCb_Error_0_001E9E70, 0);
    sceMpegAddCallback(gMovieBss_004BDF40, 3, MovieCb_Nodata_0_001E9E40, 0);
    sceMpegAddCallback(gMovieBss_004BDF40, 4, MovieCb_Audio_0_001E9E10, 0);
    sceMpegAddCallback(gMovieBss_004BDF40, 5, MovieCb_Image_0_001E9DC0, 0);
    gMovieBss_004BDFE8[0] = 0;
    MovieVideo_Create_0_001EB1A0(D_004BDF88, c, b, 0x80, a, 0x280);
    MovieAudio_Create_1_001EBCC0(D_004BDEE0, gMovieBss_004BE01C[0], 0xC000, 0x6000);
    sceMpegAddStrCallback(gMovieBss_004BDF40, 0, 0, MovieCb_VideoStream_0_001EC070, gMovieBss_004BE038[0]);
    if (gMovieSdata_00201E70 != 0) {
        sceMpegAddStrCallback(gMovieBss_004BDF40, 2, 0, MovieCb_AudioStream_0_001EBE10, gMovieBss_004BE038[0]);
    }
    D_004BDECC[0] = 0;
    D_004BDEC8[0] = 0;
    D_004BDEC0[0] = (gMovieBss_004BE028[0] & 0x0FFFFFFF) | 0x20000000;
    D_004BDED0[0] = 5;
    D_004BDEC4[0] = gMovieBss_004BE02C[0];
    *(s32 *)(D_004BDEC4[0] + 0) = 0;
    *(s32 *)(D_004BDEC4[0] + 0x35640) = 0;
    *(s32 *)(D_004BDEC4[0] + 0x6AC80) = 0;
    *(s32 *)(D_004BDEC4[0] + 0xA02C0) = 0;
    *(s32 *)(D_004BDEC4[0] + 0xD5900) = 0;
    for (i = 0; i < D_004BDED0[0]; i++) {
        Movie_SetupDisplayPackets_1_001E95B0(gMovieBss_004BE080, D_004BDEC4[0] + i * 0x35640 + 0x40, D_004BDEC0[0] + i * 0x118000, 0, i);
        Movie_SetupDisplayPackets_1_001E95B0(gMovieBss_004BE080, D_004BDEC4[0] + i * 0x35640 + 0x1AB40, D_004BDEC0[0] + i * 0x118000, 1, i);
    }
    tp.entry = Movie_IdleThread_1_001EC3C0;
    tp.stack = (void *)gMovieBss_004BE010[0];
    tp.stackSize = 0x800;
    tp.initPriority = 1;
    tp.gpReg = &_gp;
    tp.option = 0;
    D_004BE044[0] = CreateThread(&tp);
    StartThread(D_004BE044[0], NULL);
    tp.entry = Movie_DecodeWrap_0_001EA060;
    tp.stack = (void *)gMovieBss_004BE014[0];
    tp.stackSize = 0x4000;
    tp.initPriority = 1;
    tp.gpReg = &_gp;
    tp.option = 0;
    gMovieBss_004BE040[0] = CreateThread(&tp);
    StartThread(gMovieBss_004BE040[0], gMovieBss_004BDF40);
    while (!MovieFile_Open_3_001E88C0(D_004BE04C, arg0) != 0) {
        printf(gStrCanTOpenFileS_00201A50, arg0);
    }
    D_004BDFF4[0] = AddIntcHandler(2, Movie_DisplayHandler_0_001E8CB0, 0);
    EnableIntc(2);
    gMovieBss_004BDFF0[0] = AddDmacHandler(2, Movie_VblankHandler_0_001E8C50, 0);
    EnableDmac(2);
}
#undef MovieAudio_Create_1_001EBCC0
#undef MovieVideo_Create_0_001EB1A0
#undef Movie_SetupDisplayPackets_1_001E95B0
#undef MovieFile_Open_3_001E88C0
#undef printf
#undef D_004BDEC0
#undef D_004BDEC4

/* Movie_ReadLoop_1_001ECAB0 */
#define MovieVideo_PutData_0_001EA0D0 MovieVideo_PutData_0_001EA0D0__as_Movie_ReadLoop_1_001ECAB0
s32 MovieVideo_PutData_0_001EA0D0__as_Movie_ReadLoop_1_001ECAB0(P_Movie_ReadLoop_1_001ECAB0 *);
/* .bss, from the top down (CodeWarrior writes it in reverse) */

static inline s32 notz(s32 x) { return !(x != 0); }
static inline s32 imin(s32 a, s32 b) {
    if (a < b) return a;
    return b;
}

s32 Movie_ReadLoop_1_001ECAB0(P_Movie_ReadLoop_1_001ECAB0 *p, B_Movie_ReadLoop_1_001ECAB0 *buf, Q_Movie_ReadLoop_1_001ECAB0 *q, s32 (*cb)(void)) {
    u8 *src;
    s32 started;
    s32 rem2;
    s32 trig;
    s32 rem;
    u32 v;
    u8 *dst;
    s32 n;
    s32 m;
    s32 d;
    s32 c;
    s32 ok;
    s32 done;

    started = 0;
    trig = 0;
    rem = q->x4;
    rem2 = rem;
    while (rem2 > 4 && p->xA8 != 3) {
        if (cb != NULL && trig == 0 && p->x8 > 10 && cb() != 0) {
            trig = 1;
            *gMovieBss_004BD318 = p->x8;
        }
        if (trig != 0 && p->x8 > 10) {
            d = p->x8 - *gMovieBss_004BD318;
            if (*gMovieBss_004BD314 == 0 || d >= *gMovieBss_004BD314) {
                *gMovieBss_004BDFE8 = 1;
            } else {
                *D_004BD313 = d * 127 / *gMovieBss_004BD314;
                if (gMovieSdata_00201E70 != 0) {
                    v = *gMovieBss_004BE0D0 - (u32)(*gMovieBss_004BE0D0 * d) / (u32)*gMovieBss_004BD314;
                    if (v > 0x3FFF) v = 0;
                    SndDrv_SetPan_0_001D87F0(0, v, v);
                    SndDrv_SetPan_0_001D87F0(1, v, v);
                }
            }
        }
        c = buf->size - buf->cnt;
        if (c != 0) src = buf->data + buf->rd;
        if (rem > 0 && c >= 0x10000) {
            n = MovieFile_Read_3_001E8710(q, src, 0x10000, q->x8 + (q->x4 - rem) / 0x800);
            m = imin(n, buf->size - buf->cnt);
            rem -= n;
            buf->rd = (buf->rd + m) % buf->size;
            buf->cnt += m;
        }
        RotateThreadReadyQueue(1);
        c = buf->cnt;
        if (c != 0) dst = buf->data + (buf->size + (buf->rd - c)) % buf->size;
        if (c > 0) {
            n = sceMpegDemuxPssRing(p, dst, c, buf, buf->size);
            m = imin(n, buf->cnt);
            rem2 -= n;
            buf->cnt -= m;
        }
        if (started == 0 && *D_004BDECC == *D_004BDED0) {
            if (gMovieSdata_00201E70 != 0) ok = !(*gMovieBss_004BDF34 < *D_004BDF28); else ok = 1;
            if (ok) {
                while (sceGsSyncV(0) == 1) {}
                gMovieSbss_002023EC = 1;
                gMovieSbss_00202400 = 0;
                gMovieSbss_002023F0 = 0;
                if (gMovieSdata_00201E70 != 0) {
                    sceSdRemote(1, 0x8010, 0x800, 0xC0);
                    sceSdRemote(1, 0x8010, 0x801, 0xC);
                    sceSdRemote(1, 0x80E0, 0, 0x10, *D_004BDF24, *D_004BDF28 / 1024 * 1024);
                    sceSdRemote(1, 0x8010, 0xF80, 0x7FFF);
                    sceSdRemote(1, 0x8010, 0x1080, 0x7FFF);
                    sceSdRemote(1, 0x8010, 0xF81, 0x7FFF);
                    sceSdRemote(1, 0x8010, 0x1081, 0x7FFF);
                    sceSdRemote(1, 0x8010, 0xD81, 0x7FFF);
                    sceSdRemote(1, 0x8010, 0xE81, 0x7FFF);
                    sceSdRemote(1, 0x8010, 0x980, *gMovieBss_004BE0D0);
                    sceSdRemote(1, 0x8010, 0xA80, *gMovieBss_004BE0D0);
                    sceSdRemote(1, 0x8010, 0x981, *gMovieBss_004BE0D0);
                    sceSdRemote(1, 0x8010, 0xA81, *gMovieBss_004BE0D0);
                    *D_004BDEE0 = 2;
                }
                started = 1;
            }
        }
    }
    while (notz(MovieVideo_PutData_0_001EA0D0(p))) {
        RotateThreadReadyQueue(1);
    }
    goto check;
    do {
        RotateThreadReadyQueue(1);
check:
        v = 0;
        WaitSema(p->x88);
        rem = p->x5C + (p->x58 << 11);
        SignalSema(p->x88);
        if (rem == 0 && sceMpegIsRefBuffEmpty(p) != 0) v = 1;
    } while (v == 0 && p->xA8 != 3);
    gMovieSbss_002023EC = 0;
    gMovieSbss_00202400 = 0;
    if (gMovieSdata_00201E70 != 0) MovieAudio_Reset_3_001EBB70(D_004BDEE0);
    return 1;
}
#undef MovieVideo_PutData_0_001EA0D0

/* Movie_PlayFile_2_001ED070 */
#define gMovieBss_004BE038 gMovieBss_004BE038__as_Movie_PlayFile_2_001ED070
extern s32 gMovieBss_004BE038__as_Movie_PlayFile_2_001ED070[];
#define Movie_ReadLoop_1_001ECAB0 Movie_ReadLoop_1_001ECAB0__as_Movie_PlayFile_2_001ED070
s32 Movie_ReadLoop_1_001ECAB0__as_Movie_PlayFile_2_001ED070(void *a, s32 b, void *c, s32 d);

s32 Movie_PlayFile_2_001ED070(s32 a, s32 b)
{
    s32 r;
    Movie_Init_1_001EC5E0(a);
    r = Movie_ReadLoop_1_001ECAB0(gMovieBss_004BDF40, gMovieBss_004BE038[0], D_004BE04C, b);
    Movie_Shutdown_1_001EC3E0();
    return r;
}
#undef Movie_ReadLoop_1_001ECAB0
#undef gMovieBss_004BE038

/* Movie_Start_2_001ED0C0 */
#define Movie_ClearScreen_1_001E9420 Movie_ClearScreen_1_001E9420__as_Movie_Start_2_001ED0C0
void Movie_ClearScreen_1_001E9420__as_Movie_Start_2_001ED0C0(u8 *, s32);
#define Movie_InitDisplay_1_001E9AA0 Movie_InitDisplay_1_001E9AA0__as_Movie_Start_2_001ED0C0
void Movie_InitDisplay_1_001E9AA0__as_Movie_Start_2_001ED0C0(u8 *, s32, s32, s32, s32, s32, s32);
#define gMovieBss_004BE02C gMovieBss_004BE02C__as_Movie_Start_2_001ED0C0
extern s32 gMovieBss_004BE02C__as_Movie_Start_2_001ED0C0[];
#define gMovieBss_004BE038 gMovieBss_004BE038__as_Movie_Start_2_001ED0C0
extern s32 gMovieBss_004BE038__as_Movie_Start_2_001ED0C0[];

static inline s32 al(u32 size) {
    u8 *p = (u8 *)((*gMovieBss_004BE004 + 0x3F) & ~0x3F);
    if (*gMovieBss_004BE008 < (u32)(p + size)) { p = 0; } else { *gMovieBss_004BE004 = (u32)(p + size); }
    return (s32)p;
}

s32 Movie_Start_2_001ED0C0(s32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s16 arg5, s16 arg6, s16 arg7) {
    *gMovieBss_004BE000 = arg1;
    *gMovieBss_004BE004 = arg1;
    *gMovieBss_004BE008 = arg1 + arg2 - 1;
    if ((*gMovieBss_004BE010 = al(0x800)) == 0) return -1;
    if ((*gMovieBss_004BE014 = al(0x4000)) == 0) return -1;
    if ((*gMovieBss_004BE018 = al(0x13C768)) == 0) return -1;
    if ((*gMovieBss_004BE01C = al(0xC000)) == 0) return -1;
    if ((*gMovieBss_004BE020 = al(0x40000)) == 0) return -1;
    if ((*gMovieBss_004BE024 = al(0x810)) == 0) return -1;
    if ((*gMovieBss_004BE028 = al(0x578000)) == 0) return -1;
    if ((*gMovieBss_004BE02C = al(0x10AF40)) == 0) return -1;
    if ((*gMovieBss_004BE030 = al(0x3C00)) == 0) return -1;
    if ((*gMovieBss_004BE034 = al(0x100)) == 0) return -1;
    if ((*gMovieBss_004BE038 = al(0x5000C)) == 0) return -1;
    *gMovieBss_004BE0D8 = arg7;
    *gMovieBss_004BE0D4 = arg5;
    *D_004BE0D6 = arg6;
    Movie_InitDisplay_1_001E9AA0(gMovieBss_004BE080, 0, 0, 0x280, 0x1C0, 0x280, 0x1C0);
    Movie_ClearScreen_1_001E9420(gMovieBss_004BE080, 0);
    if (arg4 > 0x3FFF) {
        arg4 = 0x3FFF;
    }
    *gMovieBss_004BE0D0 = arg4;
    Movie_PlayFile_2_001ED070(arg0, arg3);
    Movie_ClearScreen_1_001E9420(gMovieBss_004BE080, 0);
    *gMovieBss_004BD310 = 0;
    *D_004BD311 = 0;
    *D_004BD312 = 0;
    *D_004BD313 = 0;
    *gMovieBss_004BD314 = 0;
    *gMovieBss_004BD318 = 0;
    memset(gMovieParamsBss_004BD31C, 0, 0x28);
    return 0;
}
#undef Movie_ClearScreen_1_001E9420
#undef Movie_InitDisplay_1_001E9AA0
#undef gMovieBss_004BE02C
#undef gMovieBss_004BE038

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/movie_rodata.c): gMovieRodata_00201920, gMovieRodata_00201940 */
char gMovieRodata_00201920[0x20] = { 0x73, 0x63, 0x65, 0x53, 0x69, 0x66, 0x46, 0x72, 0x65, 0x65, 0x49, 0x6f, 0x70, 0x48, 0x65, 0x61, 0x70, 0x20, 0x45, 0x72, 0x72, 0x6f, 0x72, 0x20, 0x25, 0x73, 0x20, 0x25, 0x64, 0xa, 0, 0 };
char gMovieRodata_00201940[0x10] = { 0x66, 0x73, 0x6c, 0x69, 0x62, 0x6d, 0x70, 0x67, 0x2e, 0x63, 0, 0, 0, 0, 0, 0 };
/* data twins (src/game/data/save_system_start_bss_004BCBC0.c): gMovieBss_004BD314, gMovieBss_004BD318 */
s32 gMovieBss_004BD314[0x1];
s32 gMovieBss_004BD318[0x1];
/* data twins (src/game/data/movie_bss.c): gMovieBss_004BDF40, gMovieBss_004BDFF0, gMovieBss_004BE02C, gMovieBss_004BE038, gMovieBss_004BE040, gMovieBss_004BE0D4 */
s32 gMovieBss_004BDF40[0x22] __attribute__((aligned(4)));
s32 gMovieBss_004BDFF0[0x4] __attribute__((aligned(4)));
u8 *gMovieBss_004BE02C[0x1];
u8 *gMovieBss_004BE038[0x2] __attribute__((aligned(4)));
s32 gMovieBss_004BE040[0xe] __attribute__((aligned(4)));
s16 gMovieBss_004BE0D4[0x2];
/* data group (src/game/data/sdata.c): D_00201E74__grp: gMovieSdata_00201E74@0x0 */
s32 D_00201E74__grp[0x1] __attribute__((aligned(4))) = { -0x48ff0000 };
/* data group (src/game/data/sbss.c): D_002023EC__grp: gMovieSbss_002023EC@0x0 */
unsigned char D_002023EC__grp[0x4] __attribute__((section(".sbss"))) __attribute__((aligned(4)));
/* data group (src/game/data/sbss.c): D_002023F0__grp: gMovieSbss_002023F0@0x0 */
unsigned char D_002023F0__grp[0x4] __attribute__((section(".sbss"))) __attribute__((aligned(16)));
/* data group (src/game/data/sbss.c): D_002023F4__grp: gMovieSbss_002023F4@0x0 */
unsigned char D_002023F4__grp[0x4] __attribute__((section(".sbss"))) __attribute__((aligned(4)));
/* data group (src/game/data/sbss.c): D_002023F8__grp: gMovieSbss_002023F8@0x0 */
unsigned char D_002023F8__grp[0x4] __attribute__((section(".sbss"))) __attribute__((aligned(8)));
/* data group (src/game/data/sbss.c): D_002023FC__grp: gMovieSbss_002023FC@0x0 */
unsigned char D_002023FC__grp[0x4] __attribute__((section(".sbss"))) __attribute__((aligned(4)));
/* data group (src/game/data/sbss.c): D_00202400__grp: gMovieSbss_00202400@0x0 */
unsigned char D_00202400__grp[0x4] __attribute__((section(".sbss"))) __attribute__((aligned(16)));
/* data group (src/game/data/save_system_start_bss_004BCBC0.c): D_004BD310__grp: gMovieBss_004BD310@0x0 */
unsigned char D_004BD310__grp[0x4] __attribute__((aligned(16)));
/* data group (src/game/data/movie_bss.c): D_004BE080__grp: gMovieBss_004BE080@0x0 */
unsigned char D_004BE080__grp[0x10] __attribute__((aligned(16)));
/* data group (src/game/data/movie_bss.c): D_004BDFD8__grp: gMovieBss_004BDFD8@0x0 */
unsigned char D_004BDFD8__grp[0x4] __attribute__((aligned(8)));
/* data group (src/game/data/movie_bss.c): D_004BDFDC__grp: gMovieBss_004BDFDC@0x0 */
unsigned char D_004BDFDC__grp[0x4] __attribute__((aligned(4)));
/* data group (src/game/data/movie_bss.c): D_004BDFE0__grp: gMovieBss_004BDFE0@0x0 */
unsigned char D_004BDFE0__grp[0x4] __attribute__((aligned(16)));
/* data group (src/game/data/movie_bss.c): D_004BDFE4__grp: gMovieBss_004BDFE4@0x0 */
unsigned char D_004BDFE4__grp[0x4] __attribute__((aligned(4)));
/* data group (src/game/data/movie_bss.c): D_004BE090__grp: gMovieBss_004BE090@0x0 */
unsigned char D_004BE090__grp[0x18] __attribute__((aligned(16)));
/* data group (src/game/data/movie_bss.c): D_004BE0A8__grp: gMovieBss_004BE0A8@0x0 */
unsigned char D_004BE0A8__grp[0x28] __attribute__((aligned(8)));
#endif
