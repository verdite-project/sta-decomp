#include "m2c.h"
#include "game/data.h"
typedef struct { s32 a; s32 b; } H_SndBank_LoadStep_1_0012ED60;
typedef struct { s32 st; s32 pad[3]; } S;
typedef struct { s32 a; u32 size; s32 b; s32 c; s8 data[]; } H_SndBank_IopTransferA_0_0012EF40;
extern S gSoundBankLoadBss_0022F040[];
extern u32 gSoundBankLoadBss_0022F088[];
extern u32 gSoundBankLoadBss_0022F08C[];
s32 SndBank_LoadStep_1_0012ED60(H_SndBank_LoadStep_1_0012ED60 *a0, u32 idx);
s32 SndBank_IopTransferA_0_0012EF40(H_SndBank_IopTransferA_0_0012EF40 *arg0, u32 arg1);
s32 SndBank_IopTransferC_0_0012F3A0(H_SndBank_LoadStep_1_0012ED60 *, u32);
s32 SndBank_IopTransferB_0_0012F0F0(H_SndBank_LoadStep_1_0012ED60 *, u32);
s32 Se_SetChannel_0_001DAEF0(u32, s8, s32);
s32 Se_BindBank_0_001DA9A0(s8, s8);
void FlushCache(s32);
void memcpy(u8 *, s8 *, u32);
s32 Se_UploadBank_1_001DAA90(s8, u8 *, u32);
s8 Se_FindFreeBank_0_001DAC30(void);

/* SndBank_LoadStep_1_0012ED60 */
#define SndBank_IopTransferA_0_0012EF40 SndBank_IopTransferA_0_0012EF40__as_SndBank_LoadStep_1_0012ED60
s32 SndBank_IopTransferA_0_0012EF40__as_SndBank_LoadStep_1_0012ED60(H_SndBank_LoadStep_1_0012ED60 *, u32);

s32 SndBank_LoadStep_1_0012ED60(H_SndBank_LoadStep_1_0012ED60 *a0, u32 idx) {

    H_SndBank_LoadStep_1_0012ED60 *s3;
    H_SndBank_LoadStep_1_0012ED60 *s2;
    s32 ret;
    s32 r;
    S *s0;
    s32 x0, x1, x2;

    s0 = &gSoundBankLoadBss_0022F040[idx];
    s3 = (H_SndBank_LoadStep_1_0012ED60 *)((u8 *)a0 + a0->a);
    s2 = (H_SndBank_LoadStep_1_0012ED60 *)((u8 *)s3 + s3->a);
    x0 = a0->b;
    x1 = s3->b;
    x2 = s2->b;
    if (x0 == 0 || x1 == 0 || x2 == 0) return -1;
    ret = -1;
    switch (s0->st) {
    case 0:
        r = SndBank_IopTransferC_0_0012F3A0(a0, idx);
        if (r == 1) {
            s0->st = 1;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            break;
        }
    case 1:
        r = SndBank_IopTransferB_0_0012F0F0(s3, idx);
        if (r == 1) {
            s0->st = 2;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            break;
        }
    case 2:
        if (Se_SetChannel_0_001DAEF0(idx, gSoundBankLoadBss_0022EBC0[idx], 0) == -1) break;
        s0->st = 3;
    case 3:
        r = SndBank_IopTransferA_0_0012EF40(s2, idx);
        if (r == 1) {
            s0->st = 4;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            break;
        }
    case 4:
        if (Se_BindBank_0_001DA9A0(gSoundBankLoadBss_0022EBC8[idx], gSoundBankLoadBss_0022EBC0[idx]) == -1) break;
        s0->st = 5;
    case 5:
        s0->st = 0;
        ret = 1;
        break;
    default:
        s0->st = 0;
        break;
    }
    return ret;
}
#undef SndBank_IopTransferA_0_0012EF40

/* SndBank_IopTransferA_0_0012EF40 */
s32 SndBank_IopTransferA_0_0012EF40(H_SndBank_IopTransferA_0_0012EF40 *arg0, u32 arg1) {
    s32 ret;
    s32 r;
    s8 *p;
    s8 *q;

    ret = -1;
    switch (gSoundBankLoadBss_0022F084[0]) {
    case 0:
        if (arg1 >= 4) break;
        p = &gSoundBankLoadBss_0022EBC8[arg1];
        *p = Se_FindFreeBank_0_001DAC30();
        if (*p == -1) break;
        if (arg0->size > 0x40000) break;
        gSoundBankLoadBss_0022F08C[0] = arg0->size;
        gSoundBankLoadBss_0022F084[0] = 1;
        gSoundBankLoadBss_0022F080[0] = 0;
        gSoundBankLoadBss_0022F088[0] = 0;
    case 1:
        q = (s8 *)((s32)arg0->data + ((arg0->c + 0xF) & ~0xF));
        gSoundBankLoadBss_0022F088[0] = gSoundBankLoadBss_0022F08C[0];
        memcpy(gSoundBankLoadBss_0022F090, q, gSoundBankLoadBss_0022F088[0]);
        FlushCache(0);
        gSoundBankLoadBss_0022F084[0] = 2;
    case 2:
        r = Se_UploadBank_1_001DAA90(gSoundBankLoadBss_0022EBC8[arg1], gSoundBankLoadBss_0022F090, gSoundBankLoadBss_0022F088[0]);
        if (r == 1) {
            gSoundBankLoadBss_0022F084[0] = 3;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            gSoundBankLoadBss_0022F084[0] = 0;
            break;
        }
    case 3:
        gSoundBankLoadBss_0022F084[0] = 0;
        ret = 1;
        break;
    default:
        gSoundBankLoadBss_0022F084[0] = 0;
        break;
    }
    FlushCache(0);
    return ret;
}
