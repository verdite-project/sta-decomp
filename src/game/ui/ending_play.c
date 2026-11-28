#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/gfx.h"
#include "game/sound.h"
#include "game/ee.h"
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
typedef struct { u64 pmode; u64 smode2; u64 dispfb; u64 display; u64 bgcolor; } DispEnv;
typedef struct { u64 r[16]; } DrawEnv1;
typedef struct {
    u64 testa; u64 testaaddr;
    u64 prim; u64 primaddr;
    u64 rgbaq; u64 rgbaqaddr;
    u64 xyz2a; u64 xyz2aaddr;
    u64 xyz2b; u64 xyz2baddr;
    u64 testb; u64 testbaddr;
} Clear;
typedef struct { DispEnv disp[2]; u64 giftag0[2]; DrawEnv1 draw0; Clear clear0; u64 giftag1[2]; DrawEnv1 draw1; Clear clear1; } DBuff;
#ifndef NONMATCHING
extern s32 gStrCdrom0TargetEndingPss1_001FD230[];
#else
/* data twins (src/game/data/databook_rodata.c): gStrCdrom0TargetEndingPss1_001FD230 */
static s32 gStrCdrom0TargetEndingPss1_001FD230[0x8] = { 0x6f726463, 0x5c3a306d, 0x47524154, 0x455c5445, 0x4e49444e, 0x53502e47, 0x313b53, 0 };
#endif
#ifndef NONMATCHING
extern s32 *gEndingPlaySbss_00202150;
#else
/* data twins (src/game/data/sbss.c): gEndingPlaySbss_00202150 */
static s32 *gEndingPlaySbss_00202150;
#endif
#ifndef NONMATCHING
extern s32 *gEndingPlaySbss_0020214C;
#else
/* data twins (src/game/data/sbss.c): gEndingPlaySbss_0020214C */
static s32 *gEndingPlaySbss_0020214C;
#endif
#ifndef NONMATCHING
extern s32 gEndingPlaySbss_00202148;
#else
/* data twins (src/game/data/sbss.c): gEndingPlaySbss_00202148 */
static s32 gEndingPlaySbss_00202148;
#endif
#ifndef NONMATCHING
extern s32 gEndingPlaySbss_00202144;
#else
/* data twins (src/game/data/sbss.c): gEndingPlaySbss_00202144 */
static s32 gEndingPlaySbss_00202144;
#endif
#ifndef NONMATCHING
extern s8 gEndingPlayRodata_001FD250[];
#else
/* data twins (src/game/data/databook_rodata.c): gEndingPlayRodata_001FD250 */
static s8 gEndingPlayRodata_001FD250[0x18] = "\\TARGET\\STA_SR.ADX\000\000\000\000\000\000";
#endif
void Ending_PlayMovie_2_00194EE0(void *arg0);
void Ending_OpenLoadMenu_0_00194F60(void *arg0);
void Ending_StaffRoll_2_00194FC0(void);
s32 sceGsSyncV(s32);
void sceGsResetGraph(s32, s32, s32, s32);
void Arc_LoadFile_2_00159DD0(s32, s8 *, void *, s32 *);
s32 Credits_InitText_0_001E3AF8(s32);
s32* Pool_Alloc_3_001288C0(s8 *, s32);
void Credits_Load_1_001E3B48(s32, s32);
void sceGsSetDefDBuff(DBuff *, s32, s32, s32, s32, s32, s32);
void FlushCache(s32);
s32 Strm_PlayFile_2_00130590(s8 *, s32, s32);
void sceGsSwapDBuff(DBuff *, s32);
void sceGsSyncPath(s32, s32);
s32 Credits_Step_0_001E3CA0(void);
void Strm_SetFadeStep_1_001304B0(s32);
void sceGsSetHalfOffset(DrawEnv1 *, s32, s32, s16);
void Pool_Free_2_00128580(s8 *, s32 *);
void GsPkt_SetReg_3_001543E0(s32, u64);

/* Ending_PlayMovie_2_00194EE0 */
#define Ending_StaffRoll_2_00194FC0 Ending_StaffRoll_2_00194FC0__as_Ending_PlayMovie_2_00194EE0
int Ending_StaffRoll_2_00194FC0__as_Ending_PlayMovie_2_00194EE0();
#define GsPkt_EndLayer_1_00155900 GsPkt_EndLayer_1_00155900__as_Ending_PlayMovie_2_00194EE0
int GsPkt_EndLayer_1_00155900__as_Ending_PlayMovie_2_00194EE0();
#define GsPkt_SetLayer_1_00154700 GsPkt_SetLayer_1_00154700__as_Ending_PlayMovie_2_00194EE0
int GsPkt_SetLayer_1_00154700__as_Ending_PlayMovie_2_00194EE0();

void Ending_PlayMovie_2_00194EE0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        GsPkt_EndLayer_1_00155900();
        Movie_Play_2_0017FF70((s32) gStrCdrom0TargetEndingPss1_001FD230);
        GsPkt_SetLayer_1_00154700(5, 0);
        GsPkt_EndLayer_1_00155900();
        Ending_StaffRoll_2_00194FC0();
        GsPkt_SetLayer_1_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
    }
}
#undef Ending_StaffRoll_2_00194FC0
#undef GsPkt_EndLayer_1_00155900
#undef GsPkt_SetLayer_1_00154700

/* Ending_OpenLoadMenu_0_00194F60 */
void Ending_OpenLoadMenu_0_00194F60(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0x16) {
        M2C_FIELD(arg0, s8 *, 8) = 0xA;
        MenuStack_Push_1_00189ED0(5);
        LoadMenu_SetFromTitle_0_00193850(1);
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x1A;
    }
}

/* Ending_StaffRoll_2_00194FC0 */
void Ending_StaffRoll_2_00194FC0(void) {
    DBuff db;
    s32 x;
    s32 fr;
    s32 i;

    GsPkt_EndLayer_1_00155900();
    GsPkt_ResetLayer_0_00154AF0();
    Gfx_FlipBuffers_2_00155370();
    Gfx_WaitDraw_1_001552A0();
    Gfx_KickFrame_1_00154B70();
    GsPkt_DrawClearRect_0_00153D80();
    GsPkt_ResetLayer_0_00154AF0();
    Gfx_FlipBuffers_2_00155370();
    Gfx_WaitDraw_1_001552A0();
    sceGsSyncV(0);
    sceGsResetGraph(0, 1, 2, 1);
    x = 0;
    Arc_LoadFile_2_00159DD0(0xC6EE908E, gGameMainBss_00222AF0, &gEndingPlaySbss_00202150, &x);
    gEndingPlaySbss_00202148 = *gEndingPlaySbss_00202150;
    gEndingPlaySbss_0020214C = Pool_Alloc_3_001288C0(gGameMainBss_00222AF0, Credits_InitText_0_001E3AF8(gEndingPlaySbss_00202148));
    gEndingPlaySbss_00202144 = *gEndingPlaySbss_0020214C;
    Credits_Load_1_001E3B48(gEndingPlaySbss_00202148, gEndingPlaySbss_00202144);
    Credits_SetSpeed_0_001E3DB8(2);
    sceGsSetDefDBuff(&db, 0, 0x280, 0xE0, 3, 0x3A, 1);
    db.clear1.rgbaq = db.clear0.rgbaq = ((u64)0x80 << 24) | ((u64)0x3F800000 << 32);
    FlushCache(0);
    Strm_PlayFile_2_00130590(gEndingPlayRodata_001FD250, 0, 0);
    fr = sceGsSyncV(0);
loop:
        FlushCache(0);
        sceGsSwapDBuff(&db, fr);
        sceGsSyncPath(0, 0);
    if (Credits_Step_0_001E3CA0() == 0) goto flip;
            i = 0;
            Strm_SetFadeStep_1_001304B0(-0x100);
            for (; i < 0x80; i++) {
                sceGsSetHalfOffset(fr ? &db.draw0 : &db.draw1, 0x800, 0x800, fr);
                fr = !(fr != 0);
                Strm_Update_1_001304C0();
                sceGsSyncV(0);
                FlushCache(0);
                sceGsSwapDBuff(&db, fr);
                sceGsSyncPath(0, 0);
            }
    goto done;
flip:
        sceGsSetHalfOffset(fr ? &db.draw0 : &db.draw1, 0x800, 0x800, fr);
        fr = !(fr != 0);
        Strm_Update_1_001304C0();
        sceGsSyncV(0);
    goto loop;
done:
    Strm_Stop_2_00130440();
    Pool_Free_2_00128580(gGameMainBss_00222AF0, gEndingPlaySbss_0020214C);
    Pool_Free_2_00128580(gGameMainBss_00222AF0, gEndingPlaySbss_00202150);
    Gfx_Nop_2_001558F0();
    Gfx_KickFrame_1_00154B70();
    GsPkt_SetLayer_1_00154700(5, -2);
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x40, 0x27F0000 | ((u64)0x1BF0000 << 32));
    GsPkt_SetReg_3_001543E0(0x41, 0x27F0000 | ((u64)0x1BF0000 << 32));
    GsPkt_SetReg_3_001543E0(0x49, 0);
    GsPkt_Flush_1_001544C0();
}
