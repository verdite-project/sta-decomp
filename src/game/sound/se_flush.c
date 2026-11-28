#include "common.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct { f32 v[8]; } M;
extern s32 gSeBss_004BAA28[];
extern s32 D_004BA044[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u8 D_004BA040[0xa0];
s32 SndDrv_CallWithData_1_001D8350(s32, s32, s32, s32, s32, void *);
s32 SndDrv_GetRecvBuffer_1_001D8340(void);
void Se_ParseVoiceMap_0_001DBD20(s32);

/* Se_FlushQueue_0_001D9E30 */
#define SndDrv_CallWithData_1_001D8350 SndDrv_CallWithData_1_001D8350__as_Se_FlushQueue_0_001D9E30
s32 SndDrv_CallWithData_1_001D8350__as_Se_FlushQueue_0_001D9E30(s32 a, s32 b, s32 c, s32 d, s32 e, u8 *m);
void Se_FlushQueue_0_001D9E30(void) {
    s32 n = gSeFlushSbss_00202328 - gSeFlushBss_004BA0E0;
    if (n > 1) {
        SndDrv_CallWithData_1_001D8350(4, 1, n, gSeFlushSdata_00201E3C, 0x1100, gSeFlushBss_004BA0E0);
        Se_ParseVoiceMap_0_001DBD20(SndDrv_GetRecvBuffer_1_001D8340());
    }
    gSeFlushBss_004BA0E0[0] = 0;
    gSeFlushSbss_00202328 = gSeFlushBss_004BA0E0 + 1;
    gSeFlushSdata_00201E3C = 1;
}
#undef SndDrv_CallWithData_1_001D8350

/* Se_SetMode_0_001D9EA0 */
void Se_SetMode_0_001D9EA0(s32 arg0) {
    (*gSeBss_004BAA28) = arg0;
    (*gSeDmaBss_004BAA24) = arg0;
}

/* Se_SetMasterVolume_0_001D9EC0 */
void Se_SetMasterVolume_0_001D9EC0(s32 arg0) {
    SndDrv_Call1_1_001D84F0(4, 1, 0x400, arg0 & 0xFFFF);
}

/* Se_StopGroup_0_001D9EE0 */
void Se_StopGroup_0_001D9EE0(s32 arg0) {
    SndDrv_Call1_1_001D84F0(4, 1, 0x10300, arg0);
}

/* Se_GetFlag_0_001D9F00 */
s32 Se_GetFlag_0_001D9F00(void) {
    return (*D_004BA044);
}

/* Se_ReadStatus_0_001D9F10 */
#define SndDrv_GetRecvBuffer_1_001D8340 SndDrv_GetRecvBuffer_1_001D8340__as_Se_ReadStatus_0_001D9F10
u8 *SndDrv_GetRecvBuffer_1_001D8340__as_Se_ReadStatus_0_001D9F10(void);
s32 Se_ReadStatus_0_001D9F10(void) {
    s32 r; u8 *s; s32 i; u8 *d;
    r = SndDrv_CallWithData_1_001D8350(4, 1, 0, 0xA0, 0x810200, NULL);
    s = SndDrv_GetRecvBuffer_1_001D8340(); d = D_004BA040; for (i = 0; i < 0xA0; i++) { *d = *s; s = s + 1; d = d + 1; }
    return r;
}
#undef SndDrv_GetRecvBuffer_1_001D8340

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): gSeFlushSdata_00201E3C */
s32 gSeFlushSdata_00201E3C = 1;
/* data twins (src/game/data/sbss.c): gSeFlushSbss_00202328 */
u8 *gSeFlushSbss_00202328;
/* data twins (src/game/data/bgm_bss_004BA0E0.c): gSeFlushBss_004BA0E0 */
u8 gSeFlushBss_004BA0E0[0x200];
#endif
