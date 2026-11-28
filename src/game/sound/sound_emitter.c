#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct { s32 a; u32 size; s32 b; s32 c; s8 data[1]; } H;
typedef struct { s32 a; s32 b; char p8[0x10]; s32 x18; char p1c[2]; s16 h1e; char p20[0x30]; } E_SndEmit_StopAllA_1_0012F640;
typedef struct { u8 pad[0x1D]; s8 b1D; s16 h1E; u8 pad2[0x30]; } S_SndEmit_Update_1_0012F6F0;
typedef struct { char p0[0x1D]; s8 b1d; s16 h1e; f32 v20[4]; f32 v30[4]; char p40[0x10]; } E_SndEmit_OffsetPositions_1_0012F7E0;
typedef struct { s32 a; s32 b; char p8[0x10]; s32 x18; char p1c; u8 b1d; s16 h1e; char p20[0x30]; } E_SndEmit_StopAllB_1_0012F880;
typedef struct { s32 a; s32 b; char p8[0x10]; s32 x18; char p1c; u8 b1d; s16 h1e; char p20[0x30]; } E_SndEmit_KillAll_1_0012F920;
typedef struct {
    Vec a;
    Vec b;
    u16 id;
    u16 type;
    f32 f24;
    s32 f28;
    s32 pad2c;
    u8 f30;
    u8 f31;
    u16 f32_;
    f32 s34, s38, s3c;
} Src;
typedef struct {
    s32 id;
    s32 m1;
    f32 f8;
    s32 fc;
    f32 f10;
    s32 f14;
    s32 f18;
    u8 f1c;
    s8 used;
    u16 type;
    Vec v20;
    Vec v30;
    f32 s40, s44, s48;
    s32 pad4c;
} Obj;
typedef struct { s32 a; s32 b; s32 x8; char pc[4]; s32 x10; s32 x14; s32 x18; u8 b1c; u8 b1d; s16 h1e; f32 v20[4]; f32 v30[4]; char p40[0x10]; } E_SndEmit_Init_1_0012FB80;
typedef struct {
    s32 id;
    s32 h;
    f32 r;
    s32 xC;
    f32 f10;
    s32 id2;
    s32 h2;
    s8 s1C;
    u8 pad1D;
    s16 x1E;
    f32 pos[4];
    f32 pad30[4];
    f32 box[4];
} S_SndEmit_Update3D_1_0012FC20;
typedef struct {
    s32 id;
    s32 h;
    f32 r;
    f32 pad0C;
    f32 f10;
    f32 f14;
    f32 f18;
    s8 s1C;
    f32 pos[4];
    f32 v[4];
} S_SndEmit_UpdateAmbientRandom_1_00130090;
typedef struct {
    s32 id;
    s32 h;
    f32 r;
    f32 pad0C;
    f32 f10;
    f32 f14;
    f32 f18;
    s8 s1C;
    f32 pos[4];
    f32 v[4];
} S_SndEmit_UpdateLooping_1_001302A0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; u16 vol; } St_Strm_SetVolume_2_001303D0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; s16 vol; } St_Strm_Update_1_001304C0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; u16 vol; } St_Strm_PlayFile_2_00130590;
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    Vec v;
    s32 x20; f32 x24; f32 x28; f32 x2C; s32 x30; s32 *x34; s32 x38; s16 x3C; s16 x3E;
    s32 x40; f32 x44; u8 p48[8]; Vec x50; f32 x60; f32 x64; f32 x68; u8 x6C; s8 x6D; s8 x6E; u8 p6F[0x11];
} Snd_SndCh_Update3D_2_00130810;
typedef struct { s8 b0; char rest[0x7F]; } E_SndCh_IsPlaying_1_00131060;
typedef struct { s8 on; s8 idx; s8 x2; s8 x3; s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF; u8 p10[0x40]; Vec v; u8 p60[0x20]; } Snd_SndCh_SetVolume_2_001310B0;
typedef struct { u8 p[0x3C]; s16 x3C; u8 q[0x42]; } Snd_SndCh_SetPitch_1_00131130;
typedef struct { char p[0x24]; f32 x24; f32 x28; char q[0x54]; } S_SndCh_GetPosition_1_00131180;
typedef struct { s8 on; s8 idx; s8 x2; s8 x3; s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF; u8 p10[0x40]; Vec v; u8 p60[0x20]; } Snd_SndCh_SetPosition_2_001311E0;
typedef struct { char p[0x44]; f32 x44; char q[0x38]; } S_SndCh_SetRange_0_00131250;
typedef struct { u8 p[0x40]; f32 x40; u8 r[0x3C]; } Snd_SndCh_SetFalloff_0_001312C0;
typedef struct { s8 b0; s8 b1; char p2[0xE]; Vec v; char p20[0x14]; s32 x34; s32 x38; char rest[0x44]; } E_SndCh_SetPositionStatic_1_00131330;
typedef struct { u8 pad[0xE]; s8 xE; u8 rest[0x71]; } E_SndCh_Stop_2_00131440;
typedef struct { s8 b0; s8 b1; char rest[0x7E]; } E_SndCh_StopNow_1_001314A0;
typedef struct { char p0[0xA]; u16 hA; char pc[2]; u8 bE; char pf; f32 v[4]; s32 x20; char p24[0xC]; s32 x30; s32 x34; } T;
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    Vec v;
    s32 x20; f32 x24; f32 x28; f32 x2C; s32 x30; s32 *x34; s32 x38; s16 x3C; s16 x3E;
    s32 x40; s32 x44; u8 p48[0x18]; s32 x60; s32 x64; s32 x68; s8 x6C; u8 p6D[0x13];
} Snd;
typedef struct { s8 a; s8 b; s8 c; s8 lo:2; s8 hi:6; } E;
extern u32 D_0022F088[];
extern u32 D_0022F08C[];
extern u8 D_00201ED4[4];
extern Flags8 D_0022EC40[];
extern s32 D_0022F040[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
E_SndEmit_StopAllA_1_0012F640 D_0026F0D0[0x40];
f32 D_0026F090[0x10];
extern s8 D_00201C38;
#ifndef NONMATCHING
extern s32 D_00201ED8;
#else
/* data twins (src/game/data/sbss.c): D_00201ED8 */
static s32 D_00201ED8;
#endif
extern f32 D_002F16C0[];
extern f32 D_001F2160[4];
extern u8 D_00201C38__as_SndEmit_Update_1_0012F6F0;
extern S_SndEmit_Update_1_0012F6F0 D_0026F0D0__as_SndEmit_Update_1_0012F6F0[];
extern E_SndEmit_OffsetPositions_1_0012F7E0 D_0026F0D0__as_SndEmit_OffsetPositions_1_0012F7E0[64];
extern E_SndEmit_StopAllB_1_0012F880 D_0026F0D0__as_SndEmit_StopAllB_1_0012F880[64];
extern E_SndEmit_KillAll_1_0012F920 D_0026F0D0__as_SndEmit_KillAll_1_0012F920[64];
extern Obj D_0026F0D0__as_SndEmit_SpawnFromMap_0_0012F9D0[];
extern E_SndEmit_Init_1_0012FB80 D_0026F0D0__as_SndEmit_Init_1_0012FB80[64];
#ifndef NONMATCHING
extern s16 D_00201EE4;
#else
/* data twins (src/game/data/sbss.c): D_00201EE4 */
static s16 D_00201EE4;
#endif
extern St_Strm_SetVolume_2_001303D0 D_00201EE0;
extern s16 D_00201EE2;
#ifndef NONMATCHING
extern u8 D_001FABB8[];
#else
/* data twins (src/game/data/sound_emitter_rodata.c): D_001FABB8 */
static u8 D_001FABB8[0x5] = "%s;1\000";
#endif
#ifndef NONMATCHING
extern u8 D_001FABC0[];
#else
/* data twins (src/game/data/sound_emitter_rodata.c): D_001FABC0 */
static u8 D_001FABC0[0x10] __attribute__((aligned(8))) = "%s\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
extern struct { unsigned char : 1; unsigned char f : 1; } D_00201EE0__as_Strm_Stop_2_00130440;
extern St_Strm_Update_1_001304C0 D_00201EE0__as_Strm_Update_1_001304C0;
extern St_Strm_PlayFile_2_00130590 D_00201EE0__as_Strm_PlayFile_2_00130590;
extern Vec D_001F2150;
extern E_SndCh_IsPlaying_1_00131060 D_0022CBC0[];
extern Snd_SndCh_SetVolume_2_001310B0 D_0022CBC0__as_SndCh_SetVolume_2_001310B0[];
extern Snd_SndCh_SetPitch_1_00131130 D_0022CBC0__as_SndCh_SetPitch_1_00131130[];
extern S_SndCh_GetPosition_1_00131180 D_0022CBC0__as_SndCh_GetPosition_1_00131180[];
extern Snd_SndCh_SetPosition_2_001311E0 D_0022CBC0__as_SndCh_SetPosition_2_001311E0[];
extern S_SndCh_SetRange_0_00131250 D_0022CBC0__as_SndCh_SetRange_0_00131250[];
extern Snd_SndCh_SetFalloff_0_001312C0 D_0022CBC0__as_SndCh_SetFalloff_0_001312C0[];
extern E_SndCh_SetPositionStatic_1_00131330 D_0022CBC0__as_SndCh_SetPositionStatic_1_00131330[];
extern s8 D_0022EC22[];
extern u8 D_0022EC21[];
extern u8 D_0022EC22__as_Snd_SetMasterVolume_1_001313C0[];
extern E_SndCh_StopNow_1_001314A0 D_0022CBC0__as_SndCh_StopNow_1_001314A0[];
extern E_SndCh_Stop_2_00131440 D_0022CBC0__as_SndCh_Stop_2_00131440[];
extern void *D_00201ED0;
#ifndef NONMATCHING
extern s32 D_00201EE8;
#else
/* data twins (src/game/data/sbss.c): D_00201EE8 */
static s32 D_00201EE8;
#endif
extern E D_00222BC0[];
extern T *volatile D_00201ED0__as_Snd_PlaySeAt_2_001315A0;
extern Snd *D_00201ED0__as_Snd_StartRequest_2_00131640;
extern Snd D_0022CBC0__as_Snd_PlaySeVolPan_1_00131520_[];
extern Vec D_002F16C0__as_Snd_PlaySeVolPan_1_00131520_;
s32 SndBank_IopTransferC_0_0012F3A0(H *arg0, u32 arg1);
void SndEmit_SetEnabled_0_0012F6E0(s8 arg0);
void SndEmit_SpawnFromMap_0_0012F9D0(s8 *arg0);
void SndEmit_Update3D_1_0012FC20(S_SndEmit_Update3D_1_0012FC20 *o);
void SndEmit_UpdateAmbientRandom_1_00130090(S_SndEmit_UpdateAmbientRandom_1_00130090 *o);
void SndEmit_UpdateLooping_1_001302A0(S_SndEmit_UpdateLooping_1_001302A0 *o);
s16 Strm_GetParam_0_001303C0(void);
void Strm_SetVolume_2_001303D0(u16 v);
void Strm_SetFadeStep_1_001304B0(s16 arg0);
s32 Strm_PlayFile_2_00130590(s32 arg0, s32 arg1, s32 arg2);
void SndCh_Update3D_2_00130810(Snd_SndCh_Update3D_2_00130810 *s);
s8 SndCh_IsPlaying_1_00131060(s32 i);
s32 SndCh_SetVolume_2_001310B0(s32 a, s16 v);
s32 SndCh_SetPitch_1_00131130(s32 i, s16 v);
s32 SndCh_GetPosition_1_00131180(s32 arg0, f32 *arg1);
s32 SndCh_SetPosition_2_001311E0(s32 a, Vec *b);
s32 SndCh_SetRange_0_00131250(s32 arg0, f32 f);
s32 SndCh_SetFalloff_0_001312C0(s32 i, f32 v);
s32 SndCh_SetPositionStatic_1_00131330(s32 arg0, Vec *v);
void Snd_SetMasterVolume_1_001313C0(s32 v);
s32 SndCh_StopNow_1_001314A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void Snd_PlaySeVolPan_1_00131520(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Snd_PlaySeAttached_1_00131560(s32 arg0, s32 arg1, s32 arg2);
void Snd_PlaySeAt_2_001315A0(s32 a, u8 b, f32 *v);
void Snd_PlaySe_3_00131600(s32 arg0, s32 arg1);
s32 Snd_StartRequest_2_00131640(void);
void FlushCache(s32);
void memcpy(void *, s8 *, u32);
s32 Se_UploadBankB_1_001DB510(s8, void *, u32);
s8 Se_FindFreeSlot_0_001DB6B0(void);
void sceVu0InversMatrix(void *, void *);
void sceVu0AddVector(void *, void *, void *);
void sceVu0CopyVector(void *, void *);
f32 sqrtf(f32);
void sceVu0ApplyMatrix(void *, void *, void *);
f32 sceVu0InnerProduct(void *, void *);
f32 fabsf(f32);
f32 expf(f32);
f32 cosf(f32);
f32 sinf(f32);
u32 Rand_Next_3_0015ED20(void);
void SndEmit_Update3D_1_0012FC20__as_SndEmit_Update_1_0012F6F0(S_SndEmit_Update_1_0012F6F0 *);
void SndEmit_UpdateAmbientRandom_1_00130090__as_SndEmit_Update_1_0012F6F0(S_SndEmit_Update_1_0012F6F0 *);
void SndEmit_UpdateLooping_1_001302A0__as_SndEmit_Update_1_0012F6F0(S_SndEmit_Update_1_0012F6F0 *);
void sceVu0AddVector__as_SndEmit_OffsetPositions_1_0012F7E0(f32 *v0, f32 *v1, f32 *v2);
void sceVu0CopyVector__as_SndEmit_SpawnFromMap_0_0012F9D0(Vec *, Vec *);
void sceVu0AddVector__as_SndEmit_SpawnFromMap_0_0012F9D0(Vec *, Vec *, Vec *);
void sceVu0CopyVector__as_SndEmit_Init_1_0012FB80(f32 *v0, f32 *v1);
s32 Strm_DrvGetStatus_1_001D8C50(void);
s32 Strm_DrvSetMode_1_001D8CC0(s32, s32);
s32 sceCdSearchFile(void *, void *);
s32 sceCdGetError(void);
void memset(void *, s32, s32);
void sprintf(void *, void *, s32);
void Strm_DrvOpenFile_1_001D8D20(s32, void *, s32);
f32 atan2f(f32, f32);
void sceVu0Normalize(Vec *, Vec *);
f32 powf(f32, f32);
s32 Se_StopVoice_0_001DA530(s32, s32, s32, s32, s32, s32, s32, s32);
s32 Snd_GetStreamFlag_0_0012C400(s8);
s32 Se_SetVoiceParams_0_001DA620(s32, s8, u8, u8, u8);
s32 Snd_StartRequest_2_00131640__as_Snd_PlaySeVolPan_1_00131520();
s32 Snd_StartRequest_2_00131640__as_Snd_PlaySeAttached_1_00131560();
void sceVu0CopyVector__as_Snd_PlaySeAt_2_001315A0(f32 *v0, f32 *v1);
void Snd_StartRequest_2_00131640__as_Snd_PlaySeAt_2_001315A0(void);
s32 Snd_StartRequest_2_00131640__as_Snd_PlaySe_3_00131600();
void sceVu0CopyVector__as_Snd_StartRequest_2_00131640(Vec *, Vec *);
void sceVu0CopyVector__as_SndCh_Update3D_2_00130810(Vec *, Vec *);
void sceVu0ApplyMatrix__as_SndCh_Update3D_2_00130810(Vec *, Mtx *, Vec *);
void sceVu0ApplyMatrix__as_Snd_PlaySeVolPan_1_00131520_(Vec *, Vec *, Vec *);

/* SndBank_IopTransferC_0_0012F3A0 */
#define SndCh_Stop_2_00131440 SndCh_Stop_2_00131440__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_Stop_2_00131440__as_SndBank_IopTransferC_0_0012F3A0(s32 h);
#define SndCh_StopNow_1_001314A0 SndCh_StopNow_1_001314A0__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_StopNow_1_001314A0__as_SndBank_IopTransferC_0_0012F3A0(s32 h);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_SndBank_IopTransferC_0_0012F3A0
void sceVu0ApplyMatrix__as_SndBank_IopTransferC_0_0012F3A0(f32 *, f32 *, f32 *);
#define sceVu0InnerProduct sceVu0InnerProduct__as_SndBank_IopTransferC_0_0012F3A0
f32 sceVu0InnerProduct__as_SndBank_IopTransferC_0_0012F3A0(f32 *, f32 *);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_SndBank_IopTransferC_0_0012F3A0
s32 Snd_PlaySe_3_00131600__as_SndBank_IopTransferC_0_0012F3A0(s32, s8);
#define SndCh_SetPitch_1_00131130 SndCh_SetPitch_1_00131130__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_SetPitch_1_00131130__as_SndBank_IopTransferC_0_0012F3A0(s32, s32);
#define SndCh_SetVolume_2_001310B0 SndCh_SetVolume_2_001310B0__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_SetVolume_2_001310B0__as_SndBank_IopTransferC_0_0012F3A0(s32, s16);
#define SndCh_IsPlaying_1_00131060 SndCh_IsPlaying_1_00131060__as_SndBank_IopTransferC_0_0012F3A0
s32 SndCh_IsPlaying_1_00131060__as_SndBank_IopTransferC_0_0012F3A0(s32);
#define Snd_PlaySeAttached_1_00131560 Snd_PlaySeAttached_1_00131560__as_SndBank_IopTransferC_0_0012F3A0
s32 Snd_PlaySeAttached_1_00131560__as_SndBank_IopTransferC_0_0012F3A0(s32, s8, f32 *);
#define SndCh_SetFalloff_0_001312C0 SndCh_SetFalloff_0_001312C0__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_SetFalloff_0_001312C0__as_SndBank_IopTransferC_0_0012F3A0(s32, f32);
#define SndCh_SetRange_0_00131250 SndCh_SetRange_0_00131250__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_SetRange_0_00131250__as_SndBank_IopTransferC_0_0012F3A0(s32, f32);
#define SndCh_GetPosition_1_00131180 SndCh_GetPosition_1_00131180__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_GetPosition_1_00131180__as_SndBank_IopTransferC_0_0012F3A0(s32, f32 *);
#define SndCh_SetPosition_2_001311E0 SndCh_SetPosition_2_001311E0__as_SndBank_IopTransferC_0_0012F3A0
void SndCh_SetPosition_2_001311E0__as_SndBank_IopTransferC_0_0012F3A0(s32, f32 *);

/* SndBank_IopTransferC_0_0012F3A0 */
/* SndBank_IopTransferC_0_0012F3A0 */
s32 SndBank_IopTransferC_0_0012F3A0(H *arg0, u32 arg1) {
    s32 r = -1;
    s32 ret;
    s8 *p;
    switch (D_0022F084[0]) {
    case 0:
        if (arg1 >= 4) break;
        p = &D_0022EBC0[arg1];
        *p = Se_FindFreeSlot_0_001DB6B0();
        if (*p == -1) break;
        if (arg0->size > 0x40000) break;
        D_0022F08C[0] = arg0->size;
        D_0022F084[0] = 1;
        D_0022F080[0] = 0;
        D_0022F088[0] = 0;
    case 1:
        { s8 *p = (s8 *)((s32)arg0->data + ((arg0->c + 0xF) & ~0xF)); D_0022F088[0] = D_0022F08C[0]; memcpy(D_0022F090, p, D_0022F088[0]); }
        FlushCache(0);
        D_0022F084[0] = 2;
    case 2:
        ret = Se_UploadBankB_1_001DB510(D_0022EBC0[arg1], D_0022F090, D_0022F088[0]);
        if (ret == 1) {
            D_0022F084[0] = 3;
            goto st3;
        }
        if (ret == 0) {
            r = 0;
            break;
        }
        D_0022F084[0] = 0;
        break;
    case 3:
    st3:
        D_0022F084[0] = 0;
        r = 1;
        break;
    default:
        D_0022F084[0] = 0;
        break;
    }
    FlushCache(0);
    return r;
}

/* Snd_StopStream_1_0012F550 */
s32 Snd_StopStream_1_0012F550(s32 i) {
    Flags8 *f;
    s32 j;
    D_00201ED4[i] = 0;
    f = &D_0022EC40[i];
    if (f->f.b1) {
        D_0022EC44[0] = 1;
        f->f.b1 = 0;
        D_0022F040[i * 4] = 0;
    }
    f->f.b0 = 0;
    f->f.b2 = 0;
    D_0022EC48[0] = 0;
    for (j = 0; j < 4; j++) {
        if (!(D_0022EC40[j].f.b0 != 0) == 0) {
            D_0022EC48[0] = 1;
            break;
        }
    }
    return 0;
}

/* SndEmit_StopAllA_1_0012F640 */
/* SndEmit_StopAllA_1_0012F640 */
void SndEmit_StopAllA_1_0012F640(void)
{
    s32 n = 64;
    E_SndEmit_StopAllA_1_0012F640 *e = D_0026F0D0;
    while (n--) {
        if (e->b != -1) {
            SndCh_Stop_2_00131440(e->b);
            e->b = -1;
        }
        if (e->h1e == 2 || e->h1e == 3) {
            SndCh_Stop_2_00131440(e->x18);
            e->x18 = -1;
        }
        e++;
    }
}

/* SndEmit_SetEnabled_0_0012F6E0 */
void SndEmit_SetEnabled_0_0012F6E0(s8 arg0) {
    D_00201C38 = arg0;
}

/* SndEmit_Update_1_0012F6F0 */

void SndEmit_Update_1_0012F6F0(void) {
    S_SndEmit_Update_1_0012F6F0 *p;
    s32 n;

    if (D_00201ED8 != 0) {
        D_00201ED8 = 0;
        return;
    }
    if (D_00201C38__as_SndEmit_Update_1_0012F6F0 != 0) {
        sceVu0InversMatrix(D_0026F090, D_002F16C0);
        n = 0x40;
        p = D_0026F0D0__as_SndEmit_Update_1_0012F6F0;
        while (n--) {
            if (p->b1D) {
                if (p->h1E == 0) SndEmit_UpdateLooping_1_001302A0__as_SndEmit_Update_1_0012F6F0(p);
                else if (p->h1E == 1) SndEmit_UpdateAmbientRandom_1_00130090__as_SndEmit_Update_1_0012F6F0(p);
                else if (p->h1E == 2 || p->h1E == 3) SndEmit_Update3D_1_0012FC20__as_SndEmit_Update_1_0012F6F0(p);
            }
            p++;
        }
    }
}

/* SndEmit_OffsetPositions_1_0012F7E0 */

void SndEmit_OffsetPositions_1_0012F7E0(f32 *v)
{
    s32 n = 64;
    E_SndEmit_OffsetPositions_1_0012F7E0 *e = D_0026F0D0__as_SndEmit_OffsetPositions_1_0012F7E0;
    while (n--) {
        if (e->b1d) {
            sceVu0AddVector__as_SndEmit_OffsetPositions_1_0012F7E0(e->v20, e->v20, v);
            if (e->h1e == 1)
                sceVu0AddVector__as_SndEmit_OffsetPositions_1_0012F7E0(e->v30, e->v30, v);
        }
        e++;
    }
    SndCh_OffsetPositions_1_0012C440(v);
    D_00201ED8 = 1;
}

/* SndEmit_StopAllB_1_0012F880 */

void SndEmit_StopAllB_1_0012F880(void)
{
    s32 n = 64;
    E_SndEmit_StopAllB_1_0012F880 *e = D_0026F0D0__as_SndEmit_StopAllB_1_0012F880;
    while (n--) {
        if (e->b != -1) {
            SndCh_Stop_2_00131440(e->b);
            e->b = -1;
        }
        if (e->h1e == 2 || e->h1e == 3) {
            SndCh_Stop_2_00131440(e->x18);
            e->x18 = -1;
        }
        e->b1d = 0;
        e++;
    }
}

/* SndEmit_KillAll_1_0012F920 */

void SndEmit_KillAll_1_0012F920(void)
{
    s32 n = 64;
    E_SndEmit_KillAll_1_0012F920 *e = D_0026F0D0__as_SndEmit_KillAll_1_0012F920;
    while (n--) {
        if (e->b != -1) {
            SndCh_StopNow_1_001314A0(e->b);
            e->b = -1;
        }
        if ((e->h1e == 2 || e->h1e == 3) && e->h1e != -1) {
            SndCh_StopNow_1_001314A0(e->x18);
            e->x18 = -1;
        }
        e->b1d = 0;
        e++;
    }
}

/* SndEmit_SpawnFromMap_0_0012F9D0 */

void SndEmit_SpawnFromMap_0_0012F9D0(s8 *arg0) {
    Src *s;
    Obj *o;
    s32 i;
    s32 j;
    for (i = 0; i < *(u16 *)(arg0 + 0x7A); i++) {
        s = &(*(Src **)(arg0 + 0x14C))[i];
        o = NULL;
        for (j = 0; j < 0x40; j++) {
            if (D_0026F0D0__as_SndEmit_SpawnFromMap_0_0012F9D0[j].used == 0) { o = &D_0026F0D0__as_SndEmit_SpawnFromMap_0_0012F9D0[j]; break; }
        }

        if (o == NULL) return;
        o->id = s->id;
        o->m1 = -1;
        o->f8 = s->a.w;
        if (s->type == 2 || s->type == 3) {
            o->f14 = s->f32_;
            o->f18 = -1;
        } else {
            *(f32 *)&o->f18 = *(f32 *)&s->f28;
            *(f32 *)&o->f14 = s->b.w;
        }
        o->f10 = s->f24;
        o->f1c = s->f30;
        sceVu0CopyVector__as_SndEmit_SpawnFromMap_0_0012F9D0(&o->v20, &s->a);
        sceVu0AddVector__as_SndEmit_SpawnFromMap_0_0012F9D0(&o->v20, &o->v20, (Vec *)(arg0 + 0x10));
        sceVu0CopyVector__as_SndEmit_SpawnFromMap_0_0012F9D0(&o->v30, &s->b);
        o->v20.w = 1.0f;
        o->v30.w = 1.0f;
        o->type = s->type;
        o->fc = s->f31;
        o->s40 = 0.5f * s->s34;
        o->s44 = 0.5f * s->s38;
        o->s48 = 0.5f * s->s3c;
        o->used = 1;
    }
}

/* SndEmit_Init_1_0012FB80 */

void SndEmit_Init_1_0012FB80(void)
{
    s32 n = 64;
    E_SndEmit_Init_1_0012FB80 *e = D_0026F0D0__as_SndEmit_Init_1_0012FB80;
    while (n--) {
        e->a = -1;
        e->b = -1;
        e->x18 = 0;
        e->x14 = 0;
        e->x10 = 0;
        e->x8 = 0;
        e->b1c = 0;
        e->b1d = 0;
        e->h1e = 0;
        sceVu0CopyVector__as_SndEmit_Init_1_0012FB80(e->v20, D_001F2160);
        sceVu0CopyVector__as_SndEmit_Init_1_0012FB80(e->v30, D_001F2160);
        e++;
    }
}

/* SndEmit_Update3D_1_0012FC20 */
void SndEmit_Update3D_1_0012FC20(S_SndEmit_Update3D_1_0012FC20 *o) {
    f32 d[4];
    f32 e[4];
    f32 w[4];
    s32 in;
    s16 vol;
    f32 dist;
    f32 g;
    f32 ex;
    f32 v;
    f32 dd;

    sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
    if (o->xC == 0) {
        dist = sceVu0InnerProduct(d, d);
        g = o->r + o->f10;
        in = dist < g * g;
    } else {
        sceVu0ApplyMatrix(e, D_0026F090, D_001F2160);
        d[0] = fabsf(o->pos[0] - e[0]);
        d[1] = fabsf(o->pos[1] - e[1]);
        d[2] = fabsf(o->pos[2] - e[2]);
        if (d[0] <= o->box[0] + o->f10 && d[1] <= o->box[1] + o->f10 && d[2] <= o->box[2] + o->f10) {
            in = 1;
        } else {
            in = 0;
        }
    }
    if (o->x1E == 3) {
        if (o->xC == 0) {
            if (in) {
                dist = sqrtf(sceVu0InnerProduct(d, d));
                ex = o->r;
                if (!(dist <= ex)) {
                    ex = dist - ex;
                    g = 0.0f;
                    if (!(o->f10 <= g)) g = expf(-4.84418678f / o->f10 * ex);
                    vol = (s32)(o->s1C * g);
                } else {
                    vol = o->s1C;
                }
            }
        } else {
            if (in) {
                w[0] = d[0] > o->box[0] ? d[0] - o->box[0] : 0.0f;
                w[1] = d[1] > o->box[1] ? d[1] - o->box[1] : 0.0f;
                w[2] = d[2] > o->box[2] ? d[2] - o->box[2] : 0.0f;
                w[3] = 1.0f;
                dd = sqrtf(sceVu0InnerProduct(w, w));
                if (!(o->f10 <= dd)) {
                    if (!(o->f10 <= 0.0f)) expf(-4.84418678f / o->f10 * dd);
                } else {
                    vol = o->s1C;
                }
            }
        }
    }
    if (o->h == -1) {
        if (in) {
            o->h = Snd_PlaySe_3_00131600(o->id, o->s1C);
            if (o->x1E == 2) {
                SndCh_SetPitch_1_00131130(o->h, 0);
                SndCh_SetVolume_2_001310B0(o->h, -1);
            } else {
                SndCh_SetVolume_2_001310B0(o->h, vol);
            }
        }
    } else {
        if (!in) {
            SndCh_Stop_2_00131440(o->h);
            o->h = -1;
        }
        if (SndCh_IsPlaying_1_00131060(o->h) == 0) {
            o->h = -1;
        } else {
            SndCh_SetVolume_2_001310B0(o->h, vol);
        }
    }
    if (o->h2 == -1) {
        if (in) {
            o->h2 = Snd_PlaySe_3_00131600(o->id2, o->s1C);
            if (o->x1E == 2) {
                SndCh_SetPitch_1_00131130(o->h2, 0);
                SndCh_SetVolume_2_001310B0(o->h2, -1);
            } else {
                SndCh_SetVolume_2_001310B0(o->h2, vol);
            }
        }
    } else {
        if (!in) {
            SndCh_Stop_2_00131440(o->h2);
            o->h2 = -1;
        }
        if (SndCh_IsPlaying_1_00131060(o->h2) == 0) {
            o->h2 = -1;
        } else {
            SndCh_SetVolume_2_001310B0(o->h2, vol);
        }
    }
}

/* SndEmit_UpdateAmbientRandom_1_00130090 */
void SndEmit_UpdateAmbientRandom_1_00130090(S_SndEmit_UpdateAmbientRandom_1_00130090 *o) {
    f32 d[4];
    f32 a;

    if (o->h == -1) {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (a < o->r * o->r) {
            if (!(o->f10 <= 0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) + o->f14 * (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) - 0.5f))) {
                a = 6.283184f * (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) - 0.5f);
                o->v[0] = o->f18 * cosf(a);
                o->v[1] = o->pos[1];
                o->v[2] = o->f18 * sinf(a);
                o->v[3] = 1.0f;
                sceVu0ApplyMatrix(o->v, D_0026F090, o->v);
                o->h = Snd_PlaySeAttached_1_00131560(o->id, o->s1C, o->v);
            }
        }
    } else if (SndCh_IsPlaying_1_00131060(o->h) == 0) {
        o->h = -1;
    }
}

/* SndEmit_UpdateLooping_1_001302A0 */
void SndEmit_UpdateLooping_1_001302A0(S_SndEmit_UpdateLooping_1_001302A0 *o) {
    f32 d[4];
    f32 t[2];
    f32 a;

    if (o->h != -1) {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (!(a <= (o->r + o->f10) * (o->r + o->f10))) {
            SndCh_StopNow_1_001314A0(o->h);
            o->h = -1;
        }
    } else {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (a < (o->r + o->f10) * (o->r + o->f10)) {
            o->h = Snd_PlaySeAttached_1_00131560(o->id, o->s1C, o->pos);
            if (o->h != -1) {
                SndCh_SetFalloff_0_001312C0(o->h, o->f14);
                SndCh_SetRange_0_00131250(o->h, o->f18);
                t[0] = o->r;
                t[1] = o->f10;
                SndCh_GetPosition_1_00131180(o->h, t);
                SndCh_SetPosition_2_001311E0(o->h, o->v);
            }
        }
    }
}
#undef SndCh_Stop_2_00131440
#undef SndCh_StopNow_1_001314A0
#undef sceVu0ApplyMatrix
#undef sceVu0InnerProduct
#undef Snd_PlaySe_3_00131600
#undef SndCh_SetPitch_1_00131130
#undef SndCh_SetVolume_2_001310B0
#undef SndCh_IsPlaying_1_00131060
#undef Snd_PlaySeAttached_1_00131560
#undef SndCh_SetFalloff_0_001312C0
#undef SndCh_SetRange_0_00131250
#undef SndCh_GetPosition_1_00131180
#undef SndCh_SetPosition_2_001311E0

/* Strm_GetParam_0_001303C0 */
/* Strm_GetParam_0_001303C0 */
s16 Strm_GetParam_0_001303C0(void) {
    return D_00201EE4;
}

/* Strm_SetVolume_2_001303D0 */
void Strm_SetVolume_2_001303D0(u16 v) {
    if (v < 0) v = 0;
    if (v > 0x7FFF) v = 0x7FFF;
    D_00201EE0.vol = v;
    if (D_00201EE0.b1) Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0.vol, D_00201EE0.vol);
}

/* Strm_Stop_2_00130440 */

void Strm_Stop_2_00130440(void)
{
    if (D_00201EE0__as_Strm_Stop_2_00130440.f) {
        int v = 0;
        Strm_DrvStop_0_001D8C80(1);
        Strm_DrvSetParamA_0_001D8C60(1);
        Strm_DrvClose_1_001D8DF0();
        SndDrv_CallRpcSyncWait_2_001D7EC0();
        D_00201EE0__as_Strm_Stop_2_00130440.f = v;
    }
}

/* Strm_SetFadeStep_1_001304B0 */
void Strm_SetFadeStep_1_001304B0(s16 arg0) {
    D_00201EE2 = arg0;
}

/* Strm_Update_1_001304C0 */
void Strm_Update_1_001304C0(void) {
    if (!D_00201EE0__as_Strm_Update_1_001304C0.b1) return;
    if (Strm_DrvGetStatus_1_001D8C50() == 0) return;
    if (D_00201EE0__as_Strm_Update_1_001304C0.b0) {
        Strm_DrvSetMode_1_001D8CC0(1, D_00201EE0__as_Strm_Update_1_001304C0.b2 != 0);
        D_00201EE0__as_Strm_Update_1_001304C0.b0 = 0;
    }
    if (D_00201EE0__as_Strm_Update_1_001304C0.h != 0) {
        D_00201EE0__as_Strm_Update_1_001304C0.vol += D_00201EE0__as_Strm_Update_1_001304C0.h;
        if (D_00201EE0__as_Strm_Update_1_001304C0.vol < 0) D_00201EE0__as_Strm_Update_1_001304C0.vol = 0;
        if (D_00201EE0__as_Strm_Update_1_001304C0.vol > 0x7FFF) D_00201EE0__as_Strm_Update_1_001304C0.vol = 0x7FFF;
        Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0__as_Strm_Update_1_001304C0.vol, D_00201EE0__as_Strm_Update_1_001304C0.vol);
    }
}

/* Strm_PlayFile_2_00130590 */

s32 Strm_PlayFile_2_00130590(s32 arg0, s32 arg1, s32 arg2) {
    s32 i = 0;
    s32 info[12];
    u8 name[0x100];
    if (D_00201EE0__as_Strm_PlayFile_2_00130590.b1) return -1;
    SndDrv_CallRpcSyncWaitB_2_001D7FD0();
    Strm_DrvInit_0_001D8E30();
    D_00201EE0__as_Strm_PlayFile_2_00130590.vol = (D_0022EBD9[0] * 0x3FFF) / 127;
    Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0__as_Strm_PlayFile_2_00130590.vol, D_00201EE0__as_Strm_PlayFile_2_00130590.vol);
    if (arg2) D_00201EE0__as_Strm_PlayFile_2_00130590.b2 = 1; else D_00201EE0__as_Strm_PlayFile_2_00130590.b2 = 0;
    if (arg1 == 0) {
        sprintf(name, D_001FABB8, arg0);
        while (sceCdSearchFile(info, name) == 0) {
            s32 r = sceCdGetError();
            i++;
            if (r == 0) {
                if (i > 10) {
                    Strm_DrvClose_1_001D8DF0();
                    return -1;
                }
                memset(info, 0, 0x24);
                break;
            }
        }
        FlushCache(0);
        Strm_DrvOpen_0_001D8CE0(1, info[0], 0x10000);
        D_00201EE0__as_Strm_PlayFile_2_00130590.b0 = 1;
    } else {
        sprintf(name, D_001FABC0, arg0);
        Strm_DrvOpenFile_1_001D8D20(1, name, 0x10000);
        while (Strm_DrvGetStatus_1_001D8C50() == 0) {}
        if (Strm_DrvSetMode_1_001D8CC0(1, D_00201EE0__as_Strm_PlayFile_2_00130590.b2 != 0) == 0) {
            Strm_DrvClose_1_001D8DF0();
            return -1;
        }
        D_00201EE0__as_Strm_PlayFile_2_00130590.b0 = 0;
    }
    D_00201EE0__as_Strm_PlayFile_2_00130590.h = 0;
    D_00201EE0__as_Strm_PlayFile_2_00130590.b1 = 1;
    return 0;
}

/* SndCh_Update3D_2_00130810_ */
#define D_002F16C0 D_002F16C0__as_SndCh_Update3D_2_00130810_
extern Mtx D_002F16C0__as_SndCh_Update3D_2_00130810_;
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_SndCh_Update3D_2_00130810_
void sceVu0ApplyMatrix__as_SndCh_Update3D_2_00130810_(Vec*, void *, Vec*);
#define sceVu0InnerProduct sceVu0InnerProduct__as_SndCh_Update3D_2_00130810_
f32 sceVu0InnerProduct__as_SndCh_Update3D_2_00130810_(Vec *, Vec *);

/* SndCh_Update3D_2_00130810 */

/* SndCh_Update3D_2_00130810 */
/* SndCh_Update3D_2_00130810 */
/* SndCh_Update3D_2_00130810 */
void SndCh_Update3D_2_00130810(Snd_SndCh_Update3D_2_00130810 *s) {
    Vec v;
    Vec a;
    Vec pos;
    Vec d;
    f32 dist;
    f32 pan;
    f32 vol;
    f32 ang;
    f32 diff;
    f32 f;
    f32 r;
    s32 cur;
    s32 n;

    if (s->x34 == 0 && s->x20 == 0) {
        sceVu0CopyVector__as_SndCh_Update3D_2_00130810(&pos, &s->v);
    } else if (s->x34 != 0) {
        sceVu0CopyVector__as_SndCh_Update3D_2_00130810(&pos, (Vec *)(*s->x34 + s->x38));
    } else if (s->x20 != 0) {
        sceVu0CopyVector__as_SndCh_Update3D_2_00130810(&pos, (Vec *)s->x20);
    }
    sceVu0ApplyMatrix__as_SndCh_Update3D_2_00130810(&v, &D_002F16C0, &pos);
    ang = atan2f(v.z, v.x);
    switch (D_0022EC14[0]) {
    case 0:
        pan = -256.0f;
        break;
    case 1:
        pan = 162.65636f * (ang - 3.1415927f);
        if (pan < -511.0f) pan += 1022.0f;
        if (!(pan <= 511.0f)) pan -= 1022.0f;
        pan = pan < 0.0f ? pan : -pan;
        cur = s->xC;
        diff = pan - cur;
        n = diff;
        n = n < 0 ? -n : n;
        if (n > 32) {
            pan = cur + 32.0f * diff / n;
        }
        break;
    case 2:
        pan = 162.65636f * (ang - 3.1415927f);
        cur = s->xC;
        if (cur > -1024 && cur < -767 && !(pan <= -256.0f)) {
            pan -= 1024.0f;
        } else if (cur > -1536 && cur < -1023) {
            if (!(pan <= -768.0f)) pan -= 1024.0f;
        } else if (cur < -1535) {
            if (pan <= -256.0f) pan -= 1024.0f;
        } else if (cur > -256) {
            if (pan < -768.0f) pan -= 1024.0f;
        }
        diff = pan - cur;
        n = diff;
        n = n < 0 ? -n : n;
        if (n > 32) {
            if (n > 1024) {
                pan = cur - 32.0f * diff / n;
                if (pan <= -2048.0f) pan += 2048.0f;
                if (!(pan <= 0.0f)) pan -= 2048.0f;
            } else {
                pan = cur + 32.0f * diff / n;
            }
        }
        break;
    default:
        pan = -256.0f;
        break;
    }
    cur = s->xC;
    diff = pan - cur;
    n = diff;
    n = n < 0 ? -n : n;
    if (n > 32) {
        if (n > 1024) {
            pan = cur - 32.0f * diff / n;
            if (pan <= -2048.0f) pan += 2048.0f;
            if (!(pan <= 0.0f)) pan -= 2048.0f;
        } else {
            pan = cur + 32.0f * diff / n;
        }
    }
    if (s->x6C == 0) {
        dist = sqrtf(sceVu0InnerProduct(&v, &v));
        if (dist > s->x24) {
            r = dist - s->x24;
            f = (s->x28 > 0.0f) ? expf(-4.8441868f / s->x28 * r) : 0.0f;
            s->x8 = s->xA * f;
        } else {
            s->x8 = s->xA;
        }
    } else {
        a.x = fabsf(v.x);
        a.y = fabsf(v.y);
        a.z = fabsf(v.z);
        if (a.x > s->x60 || a.y > s->x64 || a.z > s->x68) {
            d.x = (a.x > s->x60) ? a.x - s->x60 : 0.0f;
            d.y = (a.y > s->x64) ? a.y - s->x64 : 0.0f;
            d.z = (a.z > s->x68) ? a.z - s->x68 : 0.0f;
            d.w = 1.0f;
            f = sceVu0InnerProduct(&d, &d);
            r = s->x28 * s->x28;
            if (r > f) {
                f = (r - f) / r;
                f = f < 0.0f ? 0.0f : f;
                s->x8 = s->xA * f;
            } else {
                s->x8 = 0;
            }
        } else {
            s->x8 = s->xA;
        }
    }
    vol = 24.0f * (s->x2C - dist) / (34000.0f - 30.0f * (s->x2C - dist));
    if (fabsf(vol) < 0.00390625f) vol = 0.0f;
    vol += 1.0f;
    if (vol < 0.0f) vol = 0.0625f;
    if (!(vol <= 1.125f)) vol = 1.125f;
    f = vol * s->x3E;
    if (vol < 1.0f) f += 0.999f;
    s->x3C = f;
    s->x2C = dist;
    if (!(s->x44 <= 0.0f)) {
        sceVu0Normalize(&a, &s->x50);
        sceVu0ApplyMatrix__as_SndCh_Update3D_2_00130810(&a, &D_002F16C0, &a);
        f = sceVu0InnerProduct(&a, &D_001F2150);
        f = 1.0f - f;
        s->x8 = s->x8 * powf(0.5f * f, s->x44);
    }
    s->xC = pan;
}

/* SndCh_IsPlaying_1_00131060 */
static inline E_SndCh_IsPlaying_1_00131060 *get_SndCh_IsPlaying_1_00131060(s32 i) { if (0 <= i && i < 63) return &D_0022CBC0[i]; return 0; }
s8 SndCh_IsPlaying_1_00131060(s32 i)
{
    E_SndCh_IsPlaying_1_00131060 *e = get_SndCh_IsPlaying_1_00131060(i);
    if (e) return e->b0;
    return 0;
}

/* SndCh_SetVolume_2_001310B0 */
static inline Snd_SndCh_SetVolume_2_001310B0 *get_SndCh_SetVolume_2_001310B0(s32 i) { if (!(0 > i) && i < 0x3F) return &D_0022CBC0__as_SndCh_SetVolume_2_001310B0[i]; return 0; }
s32 SndCh_SetVolume_2_001310B0(s32 a, s16 v) {
    Snd_SndCh_SetVolume_2_001310B0 *s = get_SndCh_SetVolume_2_001310B0(a);
    if (s == 0) return -1;
    if (v < 0) v = 0;
    if (v > 0x7F) v = 0x7F;
    s->x8 = v;
    return 0;
}

/* SndCh_SetPitch_1_00131130 */
static inline Snd_SndCh_SetPitch_1_00131130 *get_SndCh_SetPitch_1_00131130(s32 i) {
    if (0 <= i && i < 0x3F) return &D_0022CBC0__as_SndCh_SetPitch_1_00131130[i];
    return 0;
}
s32 SndCh_SetPitch_1_00131130(s32 i, s16 v) {
    Snd_SndCh_SetPitch_1_00131130 *s = get_SndCh_SetPitch_1_00131130(i);
    if (s == 0) return -1;
    s->x3C = v;
    return 0;
}

/* SndCh_GetPosition_1_00131180 */

s32 SndCh_GetPosition_1_00131180(s32 arg0, f32 *arg1) {
    S_SndCh_GetPosition_1_00131180 *s;
    if (!(0 > arg0) && arg0 < 0x3F) {
        s = &D_0022CBC0__as_SndCh_GetPosition_1_00131180[arg0];
    } else {
        s = 0;
    }
    if (s == 0) {
        return -1;
    }
    s->x24 = arg1[0];
    s->x28 = arg1[1];
    return 0;
}

/* SndCh_SetPosition_2_001311E0 */
static inline Snd_SndCh_SetPosition_2_001311E0 *get_SndCh_SetPosition_2_001311E0(s32 i) { if (!(0 > i) && i < 0x3F) return &D_0022CBC0__as_SndCh_SetPosition_2_001311E0[i]; return 0; }
s32 SndCh_SetPosition_2_001311E0(s32 a, Vec *b) {
    Snd_SndCh_SetPosition_2_001311E0 *s = get_SndCh_SetPosition_2_001311E0(a);
    if (s == 0) return -1;
    sceVu0CopyVector__as_SndCh_Update3D_2_00130810(&s->v, b);
    return 0;
}

/* SndCh_SetRange_0_00131250 */

s32 SndCh_SetRange_0_00131250(s32 arg0, f32 f) {
    S_SndCh_SetRange_0_00131250 *s;
    if (!(0 > arg0) && arg0 < 0x3F) {
        s = &D_0022CBC0__as_SndCh_SetRange_0_00131250[arg0];
    } else {
        s = 0;
    }
    if (s == 0) {
        return -1;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    s->x44 = f;
    return 0;
}

/* SndCh_SetFalloff_0_001312C0 */
static inline Snd_SndCh_SetFalloff_0_001312C0 *get_SndCh_SetFalloff_0_001312C0(s32 i) {
    if (0 <= i && i < 0x3F) {
        return &D_0022CBC0__as_SndCh_SetFalloff_0_001312C0[i];
    }
    return NULL;
}
s32 SndCh_SetFalloff_0_001312C0(s32 i, f32 v) {
    Snd_SndCh_SetFalloff_0_001312C0 *s = get_SndCh_SetFalloff_0_001312C0(i);
    if (s == NULL) return -1;
    if (v < 0.0f) v = 0.0f;
    s->x40 = v;
    return 0;
}

/* SndCh_SetPositionStatic_1_00131330 */
static inline E_SndCh_SetPositionStatic_1_00131330 *get_SndCh_SetPositionStatic_1_00131330(s32 i) {
    E_SndCh_SetPositionStatic_1_00131330 *p;
if (0 <= i && i < 0x3F) p = &D_0022CBC0__as_SndCh_SetPositionStatic_1_00131330[i]; else p = NULL;
    return p;
}
s32 SndCh_SetPositionStatic_1_00131330(s32 arg0, Vec *v) {
    E_SndCh_SetPositionStatic_1_00131330 *p = get_SndCh_SetPositionStatic_1_00131330(arg0);
    if (p == NULL) return -1;
    p->x34 = 0;
    p->x38 = 0;
    sceVu0CopyVector__as_SndCh_Update3D_2_00130810(&p->v, v);
    return 0;
}

/* Snd_RequestStopAll_1_001313A0 */
/* Snd_RequestStopAll_1_001313A0 */
void Snd_RequestStopAll_1_001313A0(void) {
    if ((*D_0022EC20) != 0) {
        (*D_0022EC22) = 1;
    }
}

/* Snd_SetMasterVolume_1_001313C0 */

void Snd_SetMasterVolume_1_001313C0(s32 v)
{
    if (v > 0x7F)
        v = 0x7F;
    if (v < 0)
        v = 0;
    Bgm_SetVolume_1_001D9650(v * 129, v * 129);
    Bgm_Resume_0_001D97A0();
    D_0022EC21[0] = v;
    D_0022EC20[0] = 1;
    D_0022EC22__as_Snd_SetMasterVolume_1_001313C0[0] = 0;
}

/* SndCh_Stop_2_00131440 */

/* SndCh_Stop_2_00131440 */
s32 SndCh_Stop_2_00131440(s32 arg0) {
    E_SndCh_Stop_2_00131440 *e;
    if (!(0 > arg0) && arg0 < 0x3F) e = &D_0022CBC0__as_SndCh_Stop_2_00131440[arg0]; else e = NULL;
    if (e != NULL) {
        e->xE = 1;
        return 0;
    }
    return -1;
}

/* SndCh_StopNow_1_001314A0 */
static inline E_SndCh_StopNow_1_001314A0 *get(s32 i) {
    E_SndCh_StopNow_1_001314A0 *p;
    if (0 <= i && i < 0x3F) p = &D_0022CBC0__as_SndCh_StopNow_1_001314A0[i]; else p = NULL;
    return p;
}
s32 SndCh_StopNow_1_001314A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    E_SndCh_StopNow_1_001314A0 *p = get(arg0);
if (p == NULL) return -1; if (Se_StopVoice_0_001DA530(p->b1, arg1, arg2, arg3, arg4, arg5, arg6, arg7) == -1) return -1; p->b0 = 0; return 0;
}

/* Snd_PlaySeVolPan_1_00131520_ */

/* Snd_PlaySeVolPan_1_00131520 */

void Snd_PlaySeVolPan_1_00131520(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(D_00201ED0, s32 *, 0x30) = arg0;
    M2C_FIELD(D_00201ED0, s32 *, 0x20) = 0;
    M2C_FIELD(D_00201ED0, s32 *, 0x34) = arg2;
    M2C_FIELD(D_00201ED0, s32 *, 0x38) = arg3;
    M2C_FIELD(D_00201ED0, s8 *, 0xE) = 4;
    M2C_FIELD(D_00201ED0, s16 *, 0xA) = (s16) (arg1 & 0xFF);
    Snd_StartRequest_2_00131640__as_Snd_PlaySeVolPan_1_00131520();
}

/* Snd_PlaySeAttached_1_00131560 */

void Snd_PlaySeAttached_1_00131560(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(D_00201ED0, s32 *, 0x30) = arg0;
    M2C_FIELD(D_00201ED0, s32 *, 0x20) = arg2;
    M2C_FIELD(D_00201ED0, s32 *, 0x34) = 0;
    M2C_FIELD(D_00201ED0, s32 *, 0x38) = 0;
    M2C_FIELD(D_00201ED0, s8 *, 0xE) = 4;
    M2C_FIELD(D_00201ED0, s16 *, 0xA) = (s16) (arg1 & 0xFF);
    Snd_StartRequest_2_00131640__as_Snd_PlaySeAttached_1_00131560();
}

/* Snd_PlaySeAt_2_001315A0 */

void Snd_PlaySeAt_2_001315A0(s32 a, u8 b, f32 *v)
{
    D_00201ED0__as_Snd_PlaySeAt_2_001315A0->x30 = a;
    D_00201ED0__as_Snd_PlaySeAt_2_001315A0->bE = 4;
    D_00201ED0__as_Snd_PlaySeAt_2_001315A0->hA = b;
    D_00201ED0__as_Snd_PlaySeAt_2_001315A0->x20 = 0;
    D_00201ED0__as_Snd_PlaySeAt_2_001315A0->x34 = 0;
    sceVu0CopyVector__as_Snd_PlaySeAt_2_001315A0(D_00201ED0__as_Snd_PlaySeAt_2_001315A0->v, v);
    Snd_StartRequest_2_00131640__as_Snd_PlaySeAt_2_001315A0();
}

/* Snd_PlaySe_3_00131600 */

void Snd_PlaySe_3_00131600(s32 arg0, s32 arg1) {
    M2C_FIELD(D_00201ED0, s32 *, 0x30) = arg0;
    M2C_FIELD(D_00201ED0, s8 *, 0xE) = 0;
    M2C_FIELD(D_00201ED0, s16 *, 0xA) = (s16) (arg1 & 0xFF);
    M2C_FIELD(D_00201ED0, s16 *, 8) = (s16) M2C_FIELD(D_00201ED0, s16 *, 0xA);
    M2C_FIELD(D_00201ED0, s32 *, 0x20) = 0;
    M2C_FIELD(D_00201ED0, s32 *, 0x34) = 0;
    Snd_StartRequest_2_00131640__as_Snd_PlaySe_3_00131600();
}

/* Snd_StartRequest_2_00131640 */

s32 Snd_StartRequest_2_00131640(void) {
    E *e;
    Snd *s;
    s32 i;
    s32 id;
    s32 st;
    Vec b;
    Vec a;

    s = 0;
    id = D_00201ED0__as_Snd_StartRequest_2_00131640->x30;
    if (id < 0 || id >= 0x2800) return -1;
    e = &D_00222BC0[id];
    if (!Snd_GetStreamFlag_0_0012C400(e->c)) return -1;
    st = D_00201EE8;
    for (i = st; i < 0x3F; i++) {
        if (D_0022CBC0__as_Snd_PlaySeVolPan_1_00131520_[i].on == 0) {
            s = &D_0022CBC0__as_Snd_PlaySeVolPan_1_00131520_[i];
            break;
        }
    }
    if (s == 0) {
        for (i = 0; i < st; i++) {
            if (D_0022CBC0__as_Snd_PlaySeVolPan_1_00131520_[i].on == 0) {
                s = &D_0022CBC0__as_Snd_PlaySeVolPan_1_00131520_[i];
                break;
            }
        }
    }
    D_00201EE8 = (st + 1) % 0x3F;
    if (s == 0) return -1;
    if (i == 0x3F) return -1;
    s->idx = i;
    s->x30 = D_00201ED0__as_Snd_StartRequest_2_00131640->x30;
    sceVu0CopyVector__as_Snd_StartRequest_2_00131640(&s->v, &D_00201ED0__as_Snd_StartRequest_2_00131640->v);
    s->x20 = D_00201ED0__as_Snd_StartRequest_2_00131640->x20;
    s->x34 = D_00201ED0__as_Snd_StartRequest_2_00131640->x34;
    s->x38 = D_00201ED0__as_Snd_StartRequest_2_00131640->x38;
    s->xE = D_00201ED0__as_Snd_StartRequest_2_00131640->xE;
    s->xA = D_00201ED0__as_Snd_StartRequest_2_00131640->xA;
    s->x8 = D_00201ED0__as_Snd_StartRequest_2_00131640->x8;
    s->xC = -0x100;
    s->x24 = D_00201EC4;
    s->x28 = D_00201EC0;
    s->x4 = e->a;
    s->x6 = e->b;
    s->x2 = e->c;
    s->xF = e->lo;
    s->x3 = 0;
    s->x3C = 0x100;
    s->x3E = 0x100;
    s->x44 = 0;
    s->x40 = 0;
    s->x6C = 0;
    s->x68 = 0;
    s->x64 = 0;
    s->x60 = 0;
    s->x3E += e->hi;
    s->x3C = s->x3E;
    if (s->x34 == 0 && s->x20 == 0) {
        sceVu0CopyVector__as_Snd_StartRequest_2_00131640(&a, &s->v);
    } else if (s->x34 != 0) {
        sceVu0CopyVector__as_Snd_StartRequest_2_00131640(&a, (Vec *)(*s->x34 + s->x38));
    } else if (s->x20 != 0) {
        sceVu0CopyVector__as_Snd_StartRequest_2_00131640(&a, (Vec *)s->x20);
    }
    sceVu0ApplyMatrix__as_Snd_PlaySeVolPan_1_00131520_(&b, &D_002F16C0__as_Snd_PlaySeVolPan_1_00131520_, &a);
    s->x2C = sqrtf(sceVu0InnerProduct(&b, &b));
    FlushCache(0);
    if (Se_SetVoiceParams_0_001DA620(i, D_0022EBC8[s->x2], s->x4, s->x6, s->xF) < 0) return -1;
    s->on = 1;
    return i;
}
#undef sceVu0ApplyMatrix
#undef sceVu0InnerProduct
#undef D_002F16C0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): D_00201C38 */
s8 D_00201C38 = 1;
/* data twins (src/game/data/sbss.c): D_00201ED0 */
void *D_00201ED0;
#endif


#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/gs_packet_bss.c): D_002F16C0__grp: D_002F16C0@0x0, D_002F16C4@0x4, D_002F16C8@0x8, D_002F16D0@0x10, D_002F16D4@0x14, D_002F16D8@0x18, D_002F16E0@0x20, D_002F16E4@0x24 */
u8 D_002F16C0__grp[0x40] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sbss.c): D_00201EE0__grp: D_00201EE0@0x0 */
u8 D_00201EE0__grp[0x4] __attribute__((aligned(16)));
#endif
