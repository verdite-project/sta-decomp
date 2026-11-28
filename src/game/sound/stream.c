#include "common.h"
#include "game/sound.h"
extern u16 gStreamSbss_0020230C;
void Strm_DrvGetStatus_1_001D8C50(void);
void Strm_DrvSetMode_1_001D8CC0(u16 d, u16 e);
s32 Strm_DrvOpenFile_1_001D8D20(s32 a0, const char *s, s32 a2);
s32 strlen(const char *);
s32 SndDrv_CallWithData_1_001D8350(s32, s32, s32, s32, s32, const char *);

/* Strm_DrvGetStatus_1_001D8C50 */
#define SndDrv_Call_2_001D85D0 SndDrv_Call_2_001D85D0__as_Strm_DrvGetStatus_1_001D8C50
int SndDrv_Call_2_001D85D0__as_Strm_DrvGetStatus_1_001D8C50();
void Strm_DrvGetStatus_1_001D8C50(void) {
    SndDrv_Call_2_001D85D0(5, 1, 0x03030000);
}
#undef SndDrv_Call_2_001D85D0

/* Strm_DrvSetParamA_0_001D8C60 */
#define SndDrv_Call1_1_001D84F0 SndDrv_Call1_1_001D84F0__as_Strm_DrvSetParamA_0_001D8C60
int SndDrv_Call1_1_001D84F0__as_Strm_DrvSetParamA_0_001D8C60();
void Strm_DrvSetParamA_0_001D8C60(s32 arg0) {
    SndDrv_Call1_1_001D84F0(5, 1, 0x03040000, arg0);
}
#undef SndDrv_Call1_1_001D84F0

/* Strm_DrvStop_0_001D8C80 */
#define SndDrv_Call1_1_001D84F0 SndDrv_Call1_1_001D84F0__as_Strm_DrvStop_0_001D8C80
int SndDrv_Call1_1_001D84F0__as_Strm_DrvStop_0_001D8C80();
void Strm_DrvStop_0_001D8C80(s32 arg0) {
    SndDrv_Call1_1_001D84F0(5, 1, 0x03070000, arg0);
}
#undef SndDrv_Call1_1_001D84F0

/* Strm_DrvSetVolume_1_001D8CA0 */
void Strm_DrvSetVolume_1_001D8CA0(s32 a, u16 b, u16 c)
{
    SndDrv_CallArgs_2_001D8680(5, 1, 0x3090000, a, b, c);
}

/* Strm_DrvSetMode_1_001D8CC0 */
#define SndDrv_CallArgs_2_001D8680 SndDrv_CallArgs_2_001D8680__as_Strm_DrvSetMode_1_001D8CC0
void SndDrv_CallArgs_2_001D8680__as_Strm_DrvSetMode_1_001D8CC0(s32 a, s32 b, s32 c, u16 d, u16 e);

void Strm_DrvSetMode_1_001D8CC0(u16 d, u16 e)
{
    SndDrv_CallArgs_2_001D8680(5, 1, 0x3060000, d, e);
}
#undef SndDrv_CallArgs_2_001D8680

/* Strm_DrvOpen_0_001D8CE0 */
#define SndDrv_CallArgs_2_001D8680 SndDrv_CallArgs_2_001D8680__as_Strm_DrvOpen_0_001D8CE0
s32 SndDrv_CallArgs_2_001D8680__as_Strm_DrvOpen_0_001D8CE0(s32 a, s32 b, s32 c, ...);

s32 Strm_DrvOpen_0_001D8CE0(s32 x, s32 y, s32 z)
{
    return SndDrv_CallArgs_2_001D8680(5, 1, 0x3020000, x, y, z) != 0;
}
#undef SndDrv_CallArgs_2_001D8680

/* Strm_DrvOpenFile_1_001D8D20 */
#define SndDrv_CallArgs_2_001D8680 SndDrv_CallArgs_2_001D8680__as_Strm_DrvOpenFile_1_001D8D20
s32 SndDrv_CallArgs_2_001D8680__as_Strm_DrvOpenFile_1_001D8D20(s32, s32, s32, ...);
s32 Strm_DrvOpenFile_1_001D8D20(s32 a0, const char *s, s32 a2) {
    s32 n = strlen(s);
    if (!SndDrv_CallArgs_2_001D8680(5, 1, 0x3010000, a0, a2)) {
        SndDrv_CallArgs_2_001D8680(5, 1, 0x3040000, a0);
        return 0;
    }
    if (!SndDrv_CallWithData_1_001D8350(5, 1, n + 1, 0, a0 | 0x30C0000, s)) {
        SndDrv_Call1_1_001D84F0(5, 1, 0x3040000, a0);
        return 0;
    }
    return 1;
}
#undef SndDrv_CallArgs_2_001D8680

/* Strm_DrvClose_1_001D8DF0 */
#define SndDrv_Call_2_001D85D0 SndDrv_Call_2_001D85D0__as_Strm_DrvClose_1_001D8DF0
int SndDrv_Call_2_001D85D0__as_Strm_DrvClose_1_001D8DF0();

void Strm_DrvClose_1_001D8DF0(void) {
    if (gStreamSbss_0020230C != 0) {
        SndDrv_Call_2_001D85D0(5, 1, 0x40000);
        gStreamSbss_0020230C = 0;
    }
}
#undef SndDrv_Call_2_001D85D0

/* Strm_DrvInit_0_001D8E30 */
/* Turn the sound driver's output on once.
 * cf. KFIV's SoundDriver_EnableOutput (kfiv-decomp src/game/sound/sound.c),
 * which sends the same kind of remote command and sets the same flag. */



void Strm_DrvInit_0_001D8E30(void)
{
    if (gStreamSbss_0020230C != 1) {
        SndDrv_Call_2_001D85D0(5, 1, 0x30000);
        gStreamSbss_0020230C = 1;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gStreamSbss_0020230C */
u16 gStreamSbss_0020230C;
#endif
