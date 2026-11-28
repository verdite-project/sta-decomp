/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/SndBank_IopTransferB_0_0012F0F0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 11 of 170 (was 14): case-1 call: volatile read of off into a local fixes memory-op order (sw n, lb ch, lw off, lw addr); left: off gets coalesced into a1 (retail: off in v0, &addr[i] in v1, addu a1,v1,v0) and sll/lb scheduling. */
#include "m2c.h"
void FlushCache(s32);
void memcpy(s32 *, s8 *, u32);
void Dma_SprCopy_1_001789E0(s32 *, s8 *, u32);
s32 Se_SetBankSlot_0_001DAC70();
s32 Se_TransferBank_0_001DB020(s8, s32 *, u32);
typedef struct { s8 ch[0x20]; s32 addr[4]; } Tb;
extern Tb gSoundBankLoadBss_0022EBC0;
typedef struct { u32 off; s32 state; u32 n; u32 left; s32 buf[1]; } Ld;
extern Ld gSoundBankLoadBss_0022F080;

s32 SndBank_IopTransferB_0_0012F0F0(s8 *arg0, u32 arg1) {
    s32 r;
    s32 ret;
    u32 n;
    s8 *p;

    ret = -1;
    switch (gSoundBankLoadBss_0022F080.state) {
    case 0:
        if (arg1 >= 4 || gSoundBankLoadBss_0022EBC0.ch[arg1] == -1) {
            break;
        }
        gSoundBankLoadBss_0022F080.left = *(u32 *)(arg0 + 4);
        gSoundBankLoadBss_0022F080.state = 1;
        gSoundBankLoadBss_0022F080.off = 0;
        gSoundBankLoadBss_0022F080.n = 0;
    case 1:
        p = (s8 *)((s32)arg0 + 0x10) + ((*(s32 *)(arg0 + 0xC) + 0xF) & ~0xF) + gSoundBankLoadBss_0022F080.off;
        n = gSoundBankLoadBss_0022F080.left;
        if (n > 0x40000) {
            n = 0x40000;
        }
        gSoundBankLoadBss_0022F080.n = n;
        { u32 off = *(volatile u32 *)&gSoundBankLoadBss_0022F080.off; Se_SetBankSlot_0_001DAC70(gSoundBankLoadBss_0022EBC0.ch[arg1], gSoundBankLoadBss_0022EBC0.addr[arg1] + off, n); }
        if (gSoundBankLoadBss_0022F080.n > 0x1000) {
            FlushCache(0);
            Dma_SprCopy_1_001789E0(gSoundBankLoadBss_0022F080.buf, p, ((gSoundBankLoadBss_0022F080.n + 0xF) & ~0xF) >> 4);
        } else {
            memcpy(gSoundBankLoadBss_0022F080.buf, p, gSoundBankLoadBss_0022F080.n);
        }
        FlushCache(0);
        ret = 0;
        gSoundBankLoadBss_0022F080.state = 2;
        break;
    case 2:
        r = Se_TransferBank_0_001DB020(gSoundBankLoadBss_0022EBC0.ch[arg1], gSoundBankLoadBss_0022F080.buf, gSoundBankLoadBss_0022F080.n);
        if (r == 1) {
            gSoundBankLoadBss_0022F080.state = 3;
            goto three;
        }
        if (r == 0) {
            ret = 0;
            break;
        }
        gSoundBankLoadBss_0022F080.state = 0;
        break;
    case 3:
    three:
        gSoundBankLoadBss_0022F080.left = gSoundBankLoadBss_0022F080.left - (n = gSoundBankLoadBss_0022F080.n);
        gSoundBankLoadBss_0022F080.off += n;
        if (gSoundBankLoadBss_0022F080.left != 0) {
            ret = 0;
            gSoundBankLoadBss_0022F080.state = 1;
        } else {
            gSoundBankLoadBss_0022F080.state = 0;
            ret = 1;
            Se_SetBankSlot_0_001DAC70(gSoundBankLoadBss_0022EBC0.ch[arg1], gSoundBankLoadBss_0022EBC0.addr[arg1]);
        }
        break;
    default:
        gSoundBankLoadBss_0022F080.state = 0;
        break;
    }
    FlushCache(0);
    return ret;
}
#else
INCLUDE_ASM(SndBank_IopTransferB_0_0012F0F0);
#endif
