#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/data.h"
#include "game/sound.h"
#include "game/ui.h"
typedef struct { s8 b0; char p1[0xD]; s8 bE; s8 bF; char rest[0x70]; } E_SndCh_StopAllUnlooped_1_0012C210;
typedef struct { s8 b0; char p1[2]; s8 b3; char p4[0xA]; s8 bE; s8 bF; char p10[0x5E]; s8 b6E; char rest[0x11]; } E_SndCh_ResumePaused_1_0012C260;
typedef struct { s8 b0; char p1[0xD]; s8 bE; s8 bF; char p10[0x5D]; s8 b6D; char rest[0x12]; } E_SndCh_PauseAll_1_0012C2C0;
typedef struct { s8 b0; char p1[0xD]; s8 bE; char rest[0x71]; } E;
typedef struct { s8 on; u8 p1[0xF]; f32 v[4]; s32 x20; u8 p24[0x10]; s32 x34; u8 p38[0x48]; } Snd;
typedef struct { u8 pad0[0x94]; u8 b94; } R;
typedef struct { u8 pad0[0x94]; Flags8 f94; } R2;
typedef struct {
    u8 pad0[0x390];
    R *x390;
    u8 pad394[0x3C0 - 0x394];
    s8 *x3C0;
    s8 *x3C4;
} P;
extern E_SndCh_StopAllUnlooped_1_0012C210 gSoundBankLoadBss_0022CBC0[];
extern E_SndCh_ResumePaused_1_0012C260 gSoundBankLoadBss_0022CBC0__as_SndCh_ResumePaused_1_0012C260[63];
extern E_SndCh_PauseAll_1_0012C2C0 gSoundBankLoadBss_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[63];
extern u8 gSoundSbss_00201ED4[4];
extern s8 D_0022EC17[];
extern E gSoundBankLoadBss_0022CBC0__as_Snd_StopAll_1_0012C320[63];
extern Snd gSoundBankLoadBss_0022CBC0__as_SndCh_OffsetPositions_1_0012C440[];
extern u32 gSoundSbss_002022B8;
extern s32 *gPlayerSbss_002022BC;
extern u8 D_0022EC41[];
extern u8 D_0022EC42[];
extern s32 D_0022F054[];
extern s8 D_0022EC15[];
extern s8 D_0022EBDA[];
extern s32 D_0022F064[];
extern Flags8 gSoundBankLoadBss_0022EC40[];
extern s16 D_0022EC4A[];
extern s8 D_0022EBC9[];
extern s8 D_0022EBCB[];
extern s8 D_00201ED7;
extern u8 D_0022EC15__as_Snd_SetAllPortVolume_0_0012C6C0[];
extern Flags8 D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0[];
extern Flags8 D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0[];
void Snd_Shutdown_1_0012C380(void);
u8 Snd_GetStreamFlag_0_0012C400(u32 i);
void Snd_SetStreamParamF064_0_0012C7A0(s32 arg0);
void Snd_SetStreamParamF054_0_0012C7B0(s32 arg0);
void sceVu0AddVector(f32 *, f32 *, f32 *);
void SndBank_UploadIndexed_0_0012E810(s32, s32);
void Snd_LoadBank_1_0012E3C0(s32);
void SndEmit_SpawnFromMap_0_0012F9D0(s32);
s32 SndBank_RegisterSet_0_0012E640(s32, s32);
s32 SndBank_LoadStep_1_0012ED60(s32, s32);
s32 SndBank_TransferStep_0_0012EA00(s32, s32);
s32 Bgm_DrvGetStatus_0_001D8FA0(void);
void Snd_SetMasterVolume_1_001313C0(u8);

/* Snd_LoadBankWrap_1_0012C1A0 */
#define Bgm_Stop_0_001D9710 Bgm_Stop_0_001D9710__as_Snd_LoadBankWrap_1_0012C1A0
int Bgm_Stop_0_001D9710__as_Snd_LoadBankWrap_1_0012C1A0();
#define Snd_LoadBank_1_0012E3C0 Snd_LoadBank_1_0012E3C0__as_Snd_LoadBankWrap_1_0012C1A0
int Snd_LoadBank_1_0012E3C0__as_Snd_LoadBankWrap_1_0012C1A0();

/* Snd_LoadBankWrap_1_0012C1A0 */
/* Snd_LoadBankWrap_1_0012C1A0 */
/* Snd_LoadBankWrap_1_0012C1A0 */
/* Snd_LoadBankWrap_1_0012C1A0 */
void Snd_LoadBankWrap_1_0012C1A0(s32 arg0) {
    Snd_LoadBank_1_0012E3C0((void *) arg0);
}

/* Snd_CountActiveVoices_1_0012C1B0 */
s32 Snd_CountActiveVoices_1_0012C1B0(void)
{
    s32 i;
    s32 n = 0;
    for (i = 0; i < 64; i++) {
        if (Se_IsVoiceActive_1_001DA4F0(i) == 1)
            n++;
    }
    return n;
}

/* SndCh_StopAllUnlooped_1_0012C210 */
/* SndCh_StopAllUnlooped_1_0012C210 */
void SndCh_StopAllUnlooped_1_0012C210(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (gSoundBankLoadBss_0022CBC0[i].b0 && !gSoundBankLoadBss_0022CBC0[i].bF)
            gSoundBankLoadBss_0022CBC0[i].bE = 1;
    }
}

/* SndCh_ResumePaused_1_0012C260 */

void SndCh_ResumePaused_1_0012C260(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (gSoundBankLoadBss_0022CBC0__as_SndCh_ResumePaused_1_0012C260[i].b0 && gSoundBankLoadBss_0022CBC0__as_SndCh_ResumePaused_1_0012C260[i].bF && gSoundBankLoadBss_0022CBC0__as_SndCh_ResumePaused_1_0012C260[i].bE == 2) {
            gSoundBankLoadBss_0022CBC0__as_SndCh_ResumePaused_1_0012C260[i].b3 = 1;
            gSoundBankLoadBss_0022CBC0__as_SndCh_ResumePaused_1_0012C260[i].bE = 3;
            gSoundBankLoadBss_0022CBC0__as_SndCh_ResumePaused_1_0012C260[i].b6E = 0;
        }
    }
}

/* SndCh_PauseAll_1_0012C2C0 */

void SndCh_PauseAll_1_0012C2C0(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (gSoundBankLoadBss_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[i].b0 && gSoundBankLoadBss_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[i].bF && gSoundBankLoadBss_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[i].bE != 1) {
            gSoundBankLoadBss_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[i].b6D = gSoundBankLoadBss_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[i].bE;
            gSoundBankLoadBss_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[i].bE = 2;
        }
    }
}

/* Snd_StopAll_1_0012C320 */

/* Snd_StopAll_1_0012C320 */
void Snd_StopAll_1_0012C320(void)
{
    s32 i;
    Snd_RequestStopAll_1_001313A0();
    SndEmit_StopAllB_1_0012F880();
    for (i = 0; i < 63; i++) {
        if (gSoundBankLoadBss_0022CBC0__as_Snd_StopAll_1_0012C320[i].b0)
            gSoundBankLoadBss_0022CBC0__as_Snd_StopAll_1_0012C320[i].bE = 1;
    }
}

/* Snd_Shutdown_1_0012C380 */
void Snd_Shutdown_1_0012C380(void) {
    s32 var_16;

    if ((*gSoundBankLoadBss_0022EC20) != 0) {
        (*gSoundBankLoadBss_0022EC20) = 0;
        do {

        } while (Bgm_Stop_0_001D9710() == 0);
    }
    SndEmit_KillAll_1_0012F920();
    var_16 = 0;
    do {
        Se_StopGroup_0_001D9EE0(var_16);
        var_16 += 1;
    } while (var_16 < 4);
}

/* Snd_GetStreamFlag_0_0012C400 */
u8 Snd_GetStreamFlag_0_0012C400(u32 i) { if (i >= 4) return 0; return gSoundSbss_00201ED4[i]; }

/* Snd_SetMuteFlag_0_0012C430 */
void Snd_SetMuteFlag_0_0012C430(void) {
    (*D_0022EC17) = 1;
}

/* SndCh_OffsetPositions_1_0012C440 */
void SndCh_OffsetPositions_1_0012C440(f32 *a) {
    s32 n = 0x3F;
    Snd *s = gSoundBankLoadBss_0022CBC0__as_SndCh_OffsetPositions_1_0012C440;
    while (n--) {
        if (s->on && !s->x34 && !s->x20) sceVu0AddVector(s->v, s->v, a);
        s++;
    }
}
#undef Bgm_Stop_0_001D9710
#undef Snd_LoadBank_1_0012E3C0

/* Snd_UpdateStreams_0_0012C4D0 */
#define SndEmit_StopAllB_1_0012F880 SndEmit_StopAllB_1_0012F880__as_Snd_UpdateStreams_0_0012C4D0
int SndEmit_StopAllB_1_0012F880__as_Snd_UpdateStreams_0_0012C4D0();
#define Snd_RequestStopAll_1_001313A0 Snd_RequestStopAll_1_001313A0__as_Snd_UpdateStreams_0_0012C4D0
int Snd_RequestStopAll_1_001313A0__as_Snd_UpdateStreams_0_0012C4D0();

/* Snd_UpdateStreams_0_0012C4D0 */
s32 Snd_UpdateStreams_0_0012C4D0(void) {
    s32 ret;

    ret = 0;
    if (gSoundSbss_002022B8 == 0) {
        if (gSoundBankLoadBss_0022EC18[0] > 0) {
            s32 a = gSoundBankLoadBss_00222B54[0];
            s32 c = D_0022F054[0];
            if (c != 0) SndBank_UploadIndexed_0_0012E810(a + c + 0x10, 1); else goto skip;
            D_00201ED5 = 0;
        }
skip:
        gSoundBankLoadBss_0022EC18[0] = 0;
        return 0;
    }
    if (gSoundSbss_002022B8 / 10 != gSoundBankLoadBss_0022EC18[0]) {
        Snd_RequestStopAll_1_001313A0();
        if (gSoundBankLoadBss_0022EC18[0] > 0) {
            SndBank_UploadIndexed_0_0012E810(gSoundBankLoadBss_00222B54[0] + D_0022F054[0] + 0x10, 1);
            D_00201ED5 = 0;
        }
        D_0022EC17[0] = 0;
        gSoundBankLoadBss_0022EC18[0] = gSoundSbss_002022B8 / 10;
        if (D_0022EC41[0] & 1) {
            Snd_StopStream_1_0012F550(1);
        }
        if (D_0022EC42[0] & 1) {
            Snd_StopStream_1_0012F550(2);
        }
        MapSe_Request_0_001E1D30(gSoundSbss_002022B8, 0);
        if (gPlayerSbss_002022BC != NULL) {
            Snd_LoadBank_1_0012E3C0(*gPlayerSbss_002022BC);
        }
        ret = 1;
    }
    if (gSoundSbss_002022B8 != gSoundBankLoadBss_0022EC1C[0]) {
        if (gSoundBankLoadBss_0022EC1C[0] > 0) {
            if (ret != 0) {
                SndEmit_KillAll_1_0012F920();
            } else {
                SndEmit_StopAllB_1_0012F880();
            }
            SndEmit_SpawnFromMap_0_0012F9D0(*gPlayerSbss_002022BC);
        }
        gSoundBankLoadBss_0022EC1C[0] = gSoundSbss_002022B8;
        ret = (ret > 0) ? ret : 2;
    }
    return ret;
}

/* Snd_SetFlagEC15_0_0012C6B0 */
void Snd_SetFlagEC15_0_0012C6B0(void) {
    (*D_0022EC15) = 1;
}

/* Snd_SetAllPortVolume_0_0012C6C0 */

void Snd_SetAllPortVolume_0_0012C6C0(s32 v)
{
    s32 i;
    D_0022EC15__as_Snd_SetAllPortVolume_0_0012C6C0[0] = 0;
    for (i = 0; i < 4; i++)
        Se_SetPortParam_0_001DA8F0(i, v);
}

/* Snd_SetSeVolume_1_0012C720 */
void Snd_SetSeVolume_1_0012C720(s32 arg0) {
    (*D_0022EBDA) = arg0 & 0x7F;
}

/* Snd_SetBgmVolume_1_0012C730 */
void Snd_SetBgmVolume_1_0012C730(s32 arg0) {
    u16 temp_16;

    (*D_0022EBD9) = arg0 & 0x7F;
    temp_16 = ((*D_0022EBD9) * 0x81) & 0xFFFF;
    Strm_SetVolume_2_001303D0(temp_16);
    if ((*gSoundBankLoadBss_0022EC20) != 0) {
        Bgm_SetVolume_1_001D9650(temp_16, temp_16);
    }
}

/* Snd_SetStreamId_0_0012C790 */
void Snd_SetStreamId_0_0012C790(s32 arg0) {
    (*gSoundBankLoadBss_0022EC10) = arg0;
}

/* Snd_SetStreamParamF064_0_0012C7A0 */
void Snd_SetStreamParamF064_0_0012C7A0(s32 arg0) {
    (*D_0022F064) = arg0;
}

/* Snd_SetStreamParamF054_0_0012C7B0 */
void Snd_SetStreamParamF054_0_0012C7B0(s32 arg0) {
    (*D_0022F054) = arg0;
}

/* Snd_UpdateBgm_0_0012C7C0 */
#define SCAN() { \
    s32 j; \
    for (j = 0; j < 4; j++) { \
        if (!(gSoundBankLoadBss_0022EC40[j].f.b0 != 0) == 0) { \
            gSoundBankLoadBss_0022EC48[0] = 1; \
            break; \
        } \
    } }
#define FAIL(F) { \
    gSoundBankLoadBss_0022EC48[0] = 0; \
    F[0].f.b0 = 0; \
    F[0].f.b2 = 0; \
    SCAN(); \
    return -1; \
}
#define DONE(F) \
    D_0022EC4A[0] = 0; \
    gSoundBankLoadBss_0022EC48[0] = 0; \
    F[0].f.b1 = 0; \
    F[0].f.b0 = 0; \
    F[0].f.b2 = 0; \
    SCAN();
#define CHAIN(b) (*(s32 *)*(s8 **)(*(s8 **)*(s8 **)*(s8 **)(b) + 0x10))
static inline s32 init(void) {
    if (Se_PollTransferB_0_001DB4D0()) return 0;
    if (Se_WaitDma_0_001DAF80()) return 0;
    if (Se_PollTransfer_0_001DAA50()) return 0;
    gSoundBankLoadBss_0022F084[0] = 0;
    return 1;
}
static inline s8 *pick(void) {
    P *p = (P *)(gPlayerSbss_002022E4->unk518 + 0x180);
    return (p->x390->b94 & 1) == 0 ? p->x3C0 : p->x3C4;
}

s32 Snd_UpdateBgm_0_0012C7C0(void) {
    s32 i;
    s32 r;
    s8 *pk;
    s8 *q;
    s8 *d;
    s32 v;
    if (gSoundBankLoadBss_0022EC48[0] == 0) return 1;
    if (gSoundBankLoadBss_0022EC44[0] != 0) {
        if (init()) {
            gSoundBankLoadBss_0022EC44[0] = 0;
            D_0022EC4A[0] = 0;
        } else {
            return 0;
        }
    }
    if (D_0022EC4A[0] == 0 && (D_0022EC43[0].b & 1)) {
        if (!D_0022EC43[0].f.b2) {
            SndCh_StopGroup_1_0012E730(3);
            D_0022EC43[0].f.b2 = 1;
            return 0;
        }
        pk = pick();
        if (pk == NULL || **(s32 **)(pk + 0x84) == 0) {
            D_0022EC43[0].f.b0 = 0;
            return -1;
        }
        if (D_0022F074[0] == 0) FAIL(D_0022EC43);
        if (SndBank_RegisterSet_0_0012E640(CHAIN(*(s8 **)(pk + 0x84)) + D_0022F074[0], 3) == -1) FAIL(D_0022EC43);
        D_0022EC4A[0] = 1;
        D_0022EC43[0].f.b1 = 1;
        return 0;
    }
    if (D_0022EC4A[0] != 0 && D_0022EC43[0].f.b1) {
        pk = pick();
        q = (s8 *)(CHAIN(*(s8 **)(pk + 0x84)) + D_0022F074[0] + 0x10);
        if (q == NULL) FAIL(D_0022EC43);
        d = q + *(s32 *)q;
        if (d == NULL) FAIL(D_0022EC43);
        r = SndBank_LoadStep_1_0012ED60((s32)d, 3);
        if (r == 1) {
            DONE(D_0022EC43);
            D_00201ED7 = 1;
            v = Option_GetBgmVolume_1_001A9470() * 2;
            if (v > 0x7F) v = 0x7F;
            Se_SetPortParam_0_001DA8F0(D_0022EBCB[0], v);
        } else {
            return -(r == -1);
        }
    }
    if (D_0022EC4A[0] == 0 && (D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0[0].b & 1)) {
        if (!MapSe_GetState_0_001E1D20()) return -1;
        if (!D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0[0].f.b2) {
            SndCh_StopGroup_1_0012E730(1);
            D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0[0].f.b2 = 1;
            return 0;
        }
        if (SndBank_RegisterSet_0_0012E640(gSoundBankLoadBss_00222B54[0] + D_0022F054[0], 1) == -1) FAIL(D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0);
        D_0022EC4A[0] = 1;
        D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0[0].f.b1 = 1;
        return 0;
    }
    if (D_0022EC4A[0] != 0 && D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0[0].f.b1) {
        if (!MapSe_GetState_0_001E1D20()) return -1;
        q = (s8 *)(gSoundBankLoadBss_00222B54[0] + D_0022F054[0] + 0x10);
        if (q == NULL) FAIL(D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0);
        d = q + *(s32 *)q;
        if (d == NULL) FAIL(D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0);
        r = SndBank_LoadStep_1_0012ED60((s32)d, 1);
        if (r == 1) {
            DONE(D_0022EC41__as_Snd_UpdateBgm_0_0012C7C0);
            D_00201ED5 = 1;
            v = Option_GetBgmVolume_1_001A9470() * 2;
            if (v > 0x7F) v = 0x7F;
            Se_SetPortParam_0_001DA8F0(D_0022EBC9[0], v);
        } else {
            return -(r == -1);
        }
    }
    if (D_0022EC4A[0] == 0 && (D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0[0].b & 1)) {
        if (!MapSe_GetState_0_001E1D20()) return -1;
        if (gSoundBankLoadBss_0022EC20[0] != 0) return 0;
        if (!Bgm_Stop_0_001D9710()) return 0;
        if (Bgm_DrvGetStatus_0_001D8FA0()) return 0;
        gSoundBankLoadBss_0022EC20[0] = 0;
        if (SndBank_RegisterSet_0_0012E640(gSoundBankLoadBss_00222B54[0] + D_0022F064[0], 2) == -1) FAIL(D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0);
        D_0022EC4A[0] = 1;
        D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0[0].f.b1 = 1;
        return 0;
    }
    if (D_0022EC4A[0] != 0 && D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0[0].f.b1) {
        if (!MapSe_GetState_0_001E1D20()) return -1;
        q = (s8 *)(gSoundBankLoadBss_00222B54[0] + D_0022F064[0] + 0x10);
        if (q == NULL) FAIL(D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0);
        d = q + *(s32 *)q;
        if (d == NULL) FAIL(D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0);
        r = SndBank_TransferStep_0_0012EA00((s32)d, 2);
        if (r == 1) {
            DONE(D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0);
            D_00201ED6 = 1;
            Snd_SetMasterVolume_1_001313C0(D_0022EBD9[0]);
        } else if (r == -1) {
            FAIL(D_0022EC42__as_Snd_UpdateBgm_0_0012C7C0);
        } else {
            return 0;
        }
    }
    return 1;
}
#undef SndEmit_StopAllB_1_0012F880
#undef Snd_RequestStopAll_1_001313A0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gSoundSbss_00201ED4, gSoundSbss_002022B8 */
u8 gSoundSbss_00201ED4[4];
u32 gSoundSbss_002022B8;
#endif
