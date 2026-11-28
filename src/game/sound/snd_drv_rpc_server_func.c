/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/SndDrv_RpcServerFunc_1_001D8AB0.c. The matching build takes it from the assembly that
 * sound_driver_call.c includes (INCLUDE_ASM(SndDrv_RpcServerFunc_1_001D8AB0)). */
#ifdef NONMATCHING
/* round 2 near-miss: ~2 insns: missing addu a1,v1,$zero before the unrolled copy, plus a nop */
#include "common.h"
extern s32 gSoundDriverCallBss_004B7740[];
typedef s8 *(*Fn)(u32, s32, s32, s32 *);
extern Fn gSoundDriverCallBss_004B7EB0[];
static inline void cpy(void *d, void *s, s32 n) { s32 i; for (i = 0; i < n; i++) ((s8 *)d)[i] = ((s8 *)s)[i]; }
s8 *SndDrv_RpcServerFunc_1_001D8AB0(u32 a, s32 b, s32 c) {
    u32 k = (a & 0xF0000000) >> 28;
    s32 n;
    s8 *src;
    gSoundDriverCallBss_004B7740[0] = 0;
    if (k != 0 && gSoundDriverCallBss_004B7EB0[k] != NULL) {
        n = 0;
        src = gSoundDriverCallBss_004B7EB0[k](a & 0x0FFFFFFF, b, c, &n);
        { s8 *dst = (s8 *)gSoundDriverCallBss_004B7740; cpy(dst, src, n); }
    }
    return (s8 *)gSoundDriverCallBss_004B7740;
}
#endif
