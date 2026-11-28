#include "common.h"
#include "include_asm.h"
#include "m2c.h"
#include "actor.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    Vec v;
    s32 x20; f32 x24; f32 x28; f32 x2C; s32 x30; s32 *x34; s32 x38; s16 x3C; s16 x3E;
    s32 x40; s32 x44; u8 p48[0x18]; s32 x60; s32 x64; s32 x68; s8 x6C; s8 x6D; s8 x6E; u8 p6F[0x11];
} Snd_Snd_Init_2_0012DF90;
typedef struct { u8 pad[0xC]; u16 xC; u8 pad2[2]; s32 x10; } H_SndBank_LoadStam_1_0012E6B0;
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    u8 p4[0x7C];
} Snd_SndBank_RegisterSet_0_0012E640;
typedef struct { u8 b0:1; u8 b1:7; } F;
typedef struct { s32 pad[3]; F f; u8 p[3]; } S_SndBank_UploadIndexed_0_0012E810;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s8 data[1]; } H_SndBank_UploadIndexed_0_0012E810;
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H_SndBank_ParseHeader_1_0012E8F0;
typedef struct { s32 st; s32 p4; s32 p8; Flags8 fC; u8 pD[3]; } S_SndBank_ParseHeader_1_0012E8F0;
typedef struct { s32 st; s32 pad[3]; } S_SndBank_TransferStep_0_0012EA00;
typedef struct { s32 x0; s32 x4; s32 x8; u16 xC; u16 xE; } B;
extern Snd_Snd_Init_2_0012DF90 *gSoundEmitterSbss_00201ED0;
extern s32 gSoundBankLoadBss_00222BC0[0x2800];
extern Snd_Snd_Init_2_0012DF90 gSoundBankLoadBss_0022CBC0[64];
extern Snd_Snd_Init_2_0012DF90 gSoundBankLoadBss_0022EB40[];
extern s8 gSoundBankLoadBss_0022EBD0[];
extern u8 gSoundBankLoadBss_0022EBD8[];
extern u8 D_0022EBDA[];
extern u32 gSoundBankLoadBss_0022EBDC[];
extern s32 gSoundBankLoadBss_0022EBE0[];
extern Vec gSoundBankLoadBss_0022EC00[];
extern u8 D_0022EC15[];
extern u8 D_0022EC17[];
extern u8 D_0022EC21[];
extern u8 D_0022EC22[];
extern u8 gSoundBankLoadBss_0022EC40[];
extern s32 gSoundBankLoadBss_0022F040[];
extern s32 gSoundBankLoadBss_0022F044[];
extern s32 gSoundBankLoadBss_0022F048[];
extern Flags8 gSoundBankLoadBss_0022F04C[];
extern s32 gSoundBankLoadBss_0022F088[];
extern s32 gSoundBankLoadBss_0022F08C[];
extern s8 D_00222BC1[];
extern s8 gSoundBankLoadBss_00222BC4[];
extern s8 D_00222BC5[];
extern s32 gSoundBankLoadBss_0022F040__as_SndBank_LoadStam_1_0012E6B0[];
extern S_SndBank_UploadIndexed_0_0012E810 gSoundBankLoadBss_0022F040__as_SndBank_UploadIndexed_0_0012E810[];
extern S_SndBank_ParseHeader_1_0012E8F0 gSoundBankLoadBss_0022F040__as_SndBank_ParseHeader_1_0012E8F0[];
extern S_SndBank_TransferStep_0_0012EA00 gSoundBankLoadBss_0022F040__as_SndBank_TransferStep_0_0012EA00[];
extern s8 gSoundBankLoadBss_00222BC0__as_SndBank_TransferStep_0_0012EA00[];
s32 Snd_Init_2_0012DF90(void);
s32 SndBank_RegisterSet_0_0012E640(s8 *arg0, s32 arg1);
s32 SndBank_LoadStam_1_0012E6B0(H_SndBank_LoadStam_1_0012E6B0 *a);
s32 SndBank_UploadIndexed_0_0012E810(H_SndBank_UploadIndexed_0_0012E810 *arg0, s32 arg1);
s32 SndBank_ParseHeader_1_0012E8F0(H_SndBank_ParseHeader_1_0012E8F0 *a0, s32 idx);
s32 SndBank_TransferStep_0_0012EA00(H_SndBank_ParseHeader_1_0012E8F0 *a0, u32 idx);
void sceSdRemoteInit(void);
s32 sceSdRemote(s32, s32, s32, ...);
void sceVu0CopyVector(Vec *, Vec *);
void bzero(void *, s32);
s32 SndBank_LoadStep_1_0012ED60(u8 *, u32);
void Se_FreeBank_1_001DA920(s8);
void Se_UnloadBank_0_001DACB0(s8);
void FlushCache(s32);
s32 Bgm_Play_0_001D8FC0(void *, void *, void *, s32, s8, s8, B *);
void Dma_SprCopy_1_001789E0(void *, s32, s32);
s32 Bgm_SetTrackParam_0_001D98D0(s32, void *, s32, s32, u16, u16);
s32 Bgm_GetState_0_001D8FB0(void);
s32 SndBank_ParseHeader_1_0012E8F0__as_SndBank_LoadStam_1_0012E6B0(u8 *, s32);

/* Snd_Init_2_0012DF90 */
s32 Snd_Init_2_0012DF90(void) {
    s32 s1;
    s32 s0;
    s32 i;
    Snd_Snd_Init_2_0012DF90 *p;

    if (SndDrv_IsInitialized_1_001D8810()) {
        SndDrv_Shutdown_1_001D8820();
    }
    if (!SndDrv_Bind_2_001D8890()) {
        return 0;
    }
    Se_Init_1_001DBAC0();
    sceSdRemoteInit();
    sceSdRemote(1, 0x8010, 0x801, 0xFCF);
    s1 = sceSdRemote(1, 0x8040, 0x1B01);
    s0 = sceSdRemote(1, 0x8040, 0x1901);
    sceSdRemote(1, 0x8030, 0x1B01, s1 & ~3);
    sceSdRemote(1, 0x8030, 0x1901, s0 & ~3);
    Se_AllocIopHeap_0_001DB410();
    Se_Start_0_001DB7F0();
    SndDrv_SetParam_0_001D80C0(10, 0x800);
    Se_Stop_0_001DB780();
    Se_SetMasterVolume_0_001D9EC0(0x3FFF);
    Se_SetMode_0_001D9EA0(0xD010);
    Se_SendCommand_0_001DB700(1, 0);
    Se_SendCommand_0_001DB700(1, 1);
    SndDrv_FlushEffects_0_001D8E70();
    Bgm_Init_0_001D99A0();
    SndDrv_AllocBuffer_1_001D8F30();
    SndDrv_SetPortParam_0_001D8EC0(0, SndDrv_AllocIopBuffer_1_001D80E0(0x40000), 0x40000);
    SndDrv_SetPortParam_0_001D8EC0(1, SndDrv_AllocIopBuffer_1_001D80E0(0x40000), 0x40000);
    SndDrv_SetReverb_0_001D8F10(0, 1, 0);
    SndDrv_SetReverb_0_001D8F10(1, 1, 1);
    gSoundEmitterSbss_00201ED0 = gSoundBankLoadBss_0022EB40;
    gSoundBankLoadBss_0022EBD0[0] = -1;
    gSoundBankLoadBss_0022EBC8[0] = -1;
    gSoundBankLoadBss_0022EBC0[0] = -1;
    gSoundBankLoadBss_0022EBD0[1] = -1;
    gSoundBankLoadBss_0022EBC8[1] = -1;
    gSoundBankLoadBss_0022EBC0[1] = -1;
    gSoundBankLoadBss_0022EBD0[2] = -1;
    gSoundBankLoadBss_0022EBC8[2] = -1;
    gSoundBankLoadBss_0022EBC0[2] = -1;
    gSoundBankLoadBss_0022EBD0[3] = -1;
    gSoundBankLoadBss_0022EBC8[3] = -1;
    gSoundBankLoadBss_0022EBC0[3] = -1;
    gSoundBankLoadBss_0022EBDC[0] = gSoundBankLoadBss_0022EBD8[0] = 0;
    D_0022EBDA[0] = 0x7F;
    D_0022EBD9[0] = 0x7F;
    gSoundBankLoadBss_0022EC14[0] = 1;
    gSoundBankLoadBss_0022EBE0[0] = 0xD010;
    gSoundBankLoadBss_0022EBE0[1] = 0x12C010;
    gSoundBankLoadBss_0022EBE0[2] = 0x5010;
    gSoundBankLoadBss_0022EBE0[3] = 0x102010;
    sceVu0CopyVector(gSoundBankLoadBss_0022EC00, &gZeroVec_003139A0);
    gSoundBankLoadBss_0022EC10[0] = 0;
    gSoundBankLoadBss_0022EC18[0] = -1;
    D_0022EC21[0] = 0;
    gSoundBankLoadBss_0022EC20[0] = 0;
    D_0022EC22[0] = 0;
    D_0022EC17[0] = 0;
    gSoundBankLoadBss_0022EC1C[0] = 0;
    gSoundBankLoadBss_0022EC3C[0] = 0;
    D_0022EC15[0] = 0;
    D_0022EC16[0] = 0;
    bzero(gSoundBankLoadBss_0022CBC0, 0x2000);
    p = gSoundBankLoadBss_0022CBC0;
    for (i = 0; i < 64; i++) {
        p->x30 = -1;
        p->x6 = -1;
        p->x4 = -1;
        p->x2 = -1;
        p->idx = -1;
        p->xE = 0;
        p->xF = 0;
        p->x8 = 0x7F;
        p->xA = 0x7F;
        p->xC = -0x100;
        p->x28 = 5000.0f;
        p->x24 = 800.0f;
        p->x6E = 0;
        p++;
    }
    for (i = 0x27FF; i >= 0; i--) {
        gSoundBankLoadBss_00222BC0[i] = -1;
    }
    gSoundBankLoadBss_0022F084[0] = 0;
    gSoundBankLoadBss_0022F08C[0] = 0;
    gSoundBankLoadBss_0022F088[0] = 0;
    gSoundBankLoadBss_0022F080[0] = 0;
    bzero(gSoundBankLoadBss_0022F090, 0x40000);
    gSoundBankLoadBss_0022F040[0] = 0;
    gSoundBankLoadBss_0022F044[0] = 0;
    gSoundBankLoadBss_0022F048[0] = 0;
    gSoundBankLoadBss_0022F04C[0].f.b0 = 0;
    gSoundBankLoadSbss_00201EC0 = 5000.0f;
    D_00201EC4 = 800.0f;
    bzero(gSoundBankLoadBss_0022EC40, 0xC);
    SndEmit_Init_1_0012FB80();
    SndDrv_CallRpcSyncWaitB_2_001D7FD0();
    return 0;
}

/* text */
#ifdef NONMATCHING
/* best-effort C: snd_load_bank.c */
#else
INCLUDE_ASM(Snd_LoadBank_1_0012E3C0);
#endif

/* SndBank_RegisterSet_0_0012E640 */
extern M2C_UNK gSoundBankLoadBss_0022F040__as_SndBank_RegisterSet_0_0012E640[];

/* SndBank_RegisterSet_0_0012E640 */
s32 SndBank_RegisterSet_0_0012E640(s8 *arg0, s32 arg1) {
    s8 *temp_v1;

    temp_v1 = arg0 + 0x10;
    if ((s32) M2C_FIELD(arg0, u16 *, 0xC) < 4) {
        return -1;
    }
    if (M2C_FIELD(temp_v1, s32 *, 4) == 0) {
        return -1;
    }
    SndBank_ParseHeader_1_0012E8F0(temp_v1, arg1);
    gSoundBankLoadBss_0022F040[arg1 * 4] = 0;
    return 0;
}

/* SndBank_LoadStam_1_0012E6B0 */
s32 SndBank_LoadStam_1_0012E6B0(H_SndBank_LoadStam_1_0012E6B0 *a) {
    u8 *p = (u8 *)&a->x10;
    if (a->xC != 4) return -1;
    SndBank_ParseHeader_1_0012E8F0(p, 0);
    p += *(s32 *)p;
    gSoundBankLoadBss_0022F040[0] = 0;
    while (SndBank_LoadStep_1_0012ED60(p, 0) == 0) {}
    return 0;
}

/* SndCh_StopGroup_1_0012E730 */
void SndCh_StopGroup_1_0012E730(s32 arg0) {
    s32 n;
    Snd_SndBank_RegisterSet_0_0012E640 *s;
    s8 *p;

    n = 0x3F;
    s = gSoundBankLoadBss_0022CBC0;
    while (n--) {
        if (s->on != 0 && s->x2 == arg0) {
            s->on = 0;
        }
        s++;
    }
    Se_StopGroup_0_001D9EE0(arg0);
    p = &gSoundBankLoadBss_0022EBC8[arg0];
    if (*p != -1) {
        Se_FreeBank_1_001DA920(*p);
    }
    *p = -1;
    p = &gSoundBankLoadBss_0022EBC0[arg0];
    if (*p != -1) {
        Se_UnloadBank_0_001DACB0(*p);
    }
    *p = -1;
}

/* SndBank_UploadIndexed_0_0012E810 */
#define gSoundBankLoadBss_0022F040 gSoundBankLoadBss_0022F040__as_SndBank_UploadIndexed_0_0012E810

s32 SndBank_UploadIndexed_0_0012E810(H_SndBank_UploadIndexed_0_0012E810 *arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 v;
    F *f;
    s32 *d;

    d = (s32 *)((s32)arg0->data + ((arg0->xC + 0xF) & ~0xF));
    f = &gSoundBankLoadBss_0022F040[arg1].f;
    if (!f->b0) {
        return 0;
    }
    if (arg0->x4 == 0) {
        return -1;
    }
    n = *d++;
    i = 0;
    if (0 < n) {
        do {
            v = *d;
            if (!(v < 0x2800)) {
                return -1;
            }
            gSoundBankLoadBss_00222BC0[v] = -1;
            i++;
            d += 2;
        } while (i < n);
    }
    f->b0 = 0;
    return 0;
}
#undef gSoundBankLoadBss_0022F040

/* SndBank_ParseHeader_1_0012E8F0 */
#define gSoundBankLoadBss_0022F040 gSoundBankLoadBss_0022F040__as_SndBank_ParseHeader_1_0012E8F0

s32 SndBank_ParseHeader_1_0012E8F0(H_SndBank_ParseHeader_1_0012E8F0 *a0, s32 idx) {
    s32 i;
    s32 *p;
    s32 *end;
    s32 n;
    s32 k;

    p = (s32 *)((u8 *)((s32)a0 + 0x10) + ((a0->c + 15) & ~15));
    end = (s32 *)((u8 *)p + a0->b);
    if (a0->b == 0) return -1;
    n = *p++;
    for (i = 0; i < n; i++) {
        if (!(p < end)) return -1;
        k = p[0];
        if (!(p + 1 < end)) return -1;
        if (k >= 0x2800) return -1;
        gSoundBankLoadBss_00222BC0[k] = p[1];
        p += 2;
    }
    FlushCache(0);
    gSoundBankLoadBss_0022F040[idx].fC.f.b0 = 1;
    return 0;
}
#undef gSoundBankLoadBss_0022F040

/* SndBank_TransferStep_0_0012EA00 */
#define gSoundBankLoadBss_0022F040 gSoundBankLoadBss_0022F040__as_SndBank_TransferStep_0_0012EA00
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

s32 SndBank_TransferStep_0_0012EA00(H_SndBank_ParseHeader_1_0012E8F0 *a0, u32 idx) {
    H_SndBank_ParseHeader_1_0012E8F0 *s3;
    H_SndBank_ParseHeader_1_0012E8F0 *s2;
    s32 ret;
    S_SndBank_TransferStep_0_0012EA00 *s0;
    s32 x0, x1, x2;
    B b;
    u16 v;

    s0 = &gSoundBankLoadBss_0022F040[idx];
    s3 = (H_SndBank_ParseHeader_1_0012E8F0 *)((u8 *)a0 + a0->a);
    s2 = (H_SndBank_ParseHeader_1_0012E8F0 *)((u8 *)s3 + s3->a);
    x0 = a0->b;
    x1 = s3->b;
    x2 = s2->b;
    if (x0 == 0 || x1 == 0 || x2 == 0) return -1;
    ret = -1;
    switch (s0->st) {
    case 0:
        if (Bgm_Play_0_001D8FC0(DATA(s2), DATA(a0), DATA(s3), x1, gSoundBankLoadBss_00222BC0[0], D_00222BC1[0], &b) == 0) {
            s0->st = 0;
            break;
        }
        Dma_SprCopy_1_001789E0(gSoundBankLoadBss_0022F090, b.x0, ((b.x8 + 15) & ~15) >> 4);
        if (Bgm_SetTrackParam_0_001D98D0(0, gSoundBankLoadBss_0022F090, b.x8, b.x4, b.xC, b.xE) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 1;
        ret = 0;
        break;
    case 1:
        v = D_0022EBD9[0] * 129;
        if (Bgm_ApplyVolume_0_001D9820(v, v) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 2;
        ret = 0;
        break;
    case 2:
        if (Bgm_GetState_0_001D8FB0() == 7) {
            s0->st = 3;
        } else {
            ret = 0;
            break;
        }
    case 3:
        if (Bgm_Play_0_001D8FC0(DATA(s2), DATA(a0), DATA(s3), x1, gSoundBankLoadBss_00222BC4[0], D_00222BC5[0], &b) == 0) {
            s0->st = 0;
            break;
        }
        Dma_SprCopy_1_001789E0(gSoundBankLoadBss_0022F090, b.x0, ((b.x8 + 15) & ~15) >> 4);
        if (Bgm_SetTrackParam_0_001D98D0(1, gSoundBankLoadBss_0022F090, b.x8, b.x4, b.xC, b.xE) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 4;
        ret = 0;
        break;
    case 4:
        v = D_0022EBD9[0] * 129;
        Bgm_ApplyVolume_0_001D9820(v, v);
        s0->st = 5;
        ret = 0;
        break;
    case 5:
        if (Bgm_GetState_0_001D8FB0() == 7) {
            s0->st = 6;
        } else {
            ret = 0;
            break;
        }
    case 6:
        s0->st = 0;
        ret = 1;
        break;
    default:
        s0->st = 0;
        break;
    }
    return ret;
}
#undef gSoundBankLoadBss_0022F040
#undef gSoundBankLoadBss_0022F040
#undef SndBank_ParseHeader_1_0012E8F0
#undef gSoundBankLoadBss_00222BC0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gSoundBankLoadSbss_00201EC0 */
f32 gSoundBankLoadSbss_00201EC0;
/* data group (src/game/data/sound_bss.c): gSoundBankLoadBss_00222B20__grp: gSoundBankLoadBss_00222B20@0x0, gSoundBankLoadBss_00222B50@0x30, gSoundBankLoadBss_00222B54@0x34, gSoundBankLoadBss_00222B58@0x38, gSoundBankLoadBss_00222B5C@0x3c, gSoundBankLoadBss_00222B60@0x40, gSoundBankLoadBss_00222B64@0x44, gSoundBankLoadBss_00222B68@0x48, gSoundBankLoadBss_00222B70@0x50, gSoundBankLoadBss_00222B74@0x54, gSoundBankLoadBss_00222B78@0x58, gSoundBankLoadBss_00222B7C@0x5c, gSoundBankLoadBss_00222B80@0x60, gSoundBankLoadBss_00222B84@0x64, gSoundBankLoadBss_00222BC0@0xa0, gSoundBankLoadBss_00222BC4@0xa4, gSoundBankLoadBss_0022CBBC@0xa09c, gSoundBankLoadBss_0022CBC0@0xa0a0, gSoundBankLoadBss_0022EB40@0xc020, gSoundBankLoadBss_0022EBC0@0xc0a0, gSoundBankLoadBss_0022EBC8@0xc0a8, gSoundBankLoadBss_0022EBD0@0xc0b0, gSoundBankLoadBss_0022EBD8@0xc0b8, gSoundBankLoadBss_0022EBDC@0xc0bc, gSoundBankLoadBss_0022EBE0@0xc0c0, gSoundBankLoadBss_0022EBE4@0xc0c4, gSoundBankLoadBss_0022EBE8@0xc0c8, gSoundBankLoadBss_0022EC00@0xc0e0, gSoundBankLoadBss_0022EC10@0xc0f0, gSoundBankLoadBss_0022EC14@0xc0f4, gSoundBankLoadBss_0022EC18@0xc0f8, gSoundBankLoadBss_0022EC1C@0xc0fc, gSoundBankLoadBss_0022EC20@0xc100, gSoundBankLoadBss_0022EC3C@0xc11c, gSoundBankLoadBss_0022EC40@0xc120, gSoundBankLoadBss_0022EC44@0xc124, gSoundBankLoadBss_0022EC48@0xc128 */
unsigned char gSoundBankLoadBss_00222B20__grp[0xc130] __attribute__((aligned(16)));
/* data group (src/game/data/sound_emitter_bss.c): gSoundBankLoadBss_0022F040__grp: gSoundBankLoadBss_0022F040@0x0, gSoundBankLoadBss_0022F044@0x4, gSoundBankLoadBss_0022F048@0x8, gSoundBankLoadBss_0022F04C@0xc, gSoundBankLoadBss_0022F050@0x10, gSoundBankLoadBss_0022F060@0x20, gSoundBankLoadBss_0022F070@0x30, gSoundBankLoadBss_0022F080@0x40, gSoundBankLoadBss_0022F084@0x44, gSoundBankLoadBss_0022F088@0x48, gSoundBankLoadBss_0022F08C@0x4c, gSoundBankLoadBss_0022F090@0x50 */
unsigned char gSoundBankLoadBss_0022F040__grp[0x40050] __attribute__((aligned(16)));
#endif
