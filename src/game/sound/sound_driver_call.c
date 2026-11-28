#include "common.h"
#include "include_asm.h"
#include "game/core.h"
#include "game/sound.h"
typedef ThreadParam TP;
typedef char *va_list;
typedef struct { u8 pad[0x24]; void *serve; u8 pad28[0x8]; } CD;
#pragma explicit_zero_data on
const char D_001FE6C0[0x30] = { 0x3c, 0x43, 0x61, 0x6c, 0x6c, 0x52, 0x70, 0x63, 0x53, 0x79, 0x6e, 0x63, 0x57, 0x61, 0x69, 0x74, 0x3e, 0x20, 0x73, 0x63, 0x65, 0x53, 0x69, 0x66, 0x43, 0x68, 0x65, 0x63, 0x6b, 0x53, 0x74, 0x61, 0x74, 0x52, 0x70, 0x63, 0x28, 0x29, 0x20, 0x3d, 0x3d, 0x20, 0x31, 0xa, 0, 0, 0, 0 };
extern s32 gSoundDriverCallBss_004B9EF0[];
extern u8 gSoundDriverCallBss_004B7A40[];
extern u8 gSoundDriverCallBss_004B7CB0[];
extern s32 _gp;
extern int gSoundDriverCallBss_004B7EB0[];
#ifndef NONMATCHING
extern s32 gSoundDriverCallSdata_00201E38;
extern s32 gSoundDriverCallSbss_00202300;
extern s32 gSoundDriverCallSbss_002022FC;
#else
/* data twins (src/game/data/sdata.c): gSoundDriverCallSdata_00201E38 */
static s32 gSoundDriverCallSdata_00201E38 = -1;
/* data twins (src/game/data/sbss.c): gSoundDriverCallSbss_00202300 */
static s32 gSoundDriverCallSbss_00202300;
/* data twins (src/game/data/sbss.c): gSoundDriverCallSbss_002022FC */
static s32 gSoundDriverCallSbss_002022FC;
#endif
extern s32 gSoundDriverCallBss_004B7C40[];
extern s32 gSoundDriverCallBss_004B7C90[];
extern s32 gSoundDriverCallBss_004B7A40__as_SndDrv_GetRecvBuffer_1_001D8340[];
extern s32 gSoundDriverCallBss_004B7A40__as_SndDrv_CallWithData_1_001D8350[];
extern s32 gSoundDriverCallBss_004B7A40__as_SndDrv_Call1_1_001D84F0[];
extern u8 gSoundDriverCallBss_004B9EF0__as_SndDrv_CallArgs_2_001D8680[];
extern CD gSoundDriverCallBss_004B9EF0__as_SndDrv_Bind_2_001D8890;
extern s32 gSoundDriverCallBss_004B7A40__as_SndDrv_CallRpc_2_001D8960[];
extern char gSoundDriverCallBss_004B7840[];
void SndDrv_SetCallback_1_001D8320(int index, int value);
s32* SndDrv_GetRecvBuffer_1_001D8340(void);
s32 SndDrv_CallWithData_1_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *src);
s32 SndDrv_CallRpc_2_001D8960(s32 a, s32 b, s32 c, s32 d, u32 e);
void SndDrv_RpcServerThread_1_001D8BE0(void);
s32 printf(const char*, ...);
s32 sceSifCheckStatRpc(void *);
s32 sceSifAllocIopHeap(s32);
s32 CreateThread(TP *);
s32 StartThread(s32, void *);
void DeleteThread(s32);
void TerminateThread(s32);
void sceSifRemoveRpc(s32 *, s32 *);
void sceSifRemoveRpcQueue(s32 *);
s32 sceSifBindRpc(CD *, u32, s32);
void sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_CallRpcSyncWait_2_001D7EC0(s32, s32, s32, s32, s32);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_CallRpcSyncWaitB_2_001D7FD0(s32, s32, s32, s32, s32);
void SndDrv_CallArgs_2_001D8680__as_SndDrv_SetParam_0_001D80C0(s32 a, s32 b, s32 c, u16 d, u16 e);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_AllocIopBuffer_1_001D80E0(s32, s32, s32, s32, s32);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_StartThread_1_001D8210(s32, s32, s32, s32, s32);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_CallWithData_1_001D8350(s32, s32, s32, s32, s32);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_Call1_1_001D84F0(s32, s32, s32, s32, s32);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_Call_2_001D85D0(s32, s32, s32, s32, s32);
void printf__as_SndDrv_CallArgs_2_001D8680(const char *, ...);
s32 SndDrv_CallRpc_2_001D8960__as_SndDrv_CallArgs_2_001D8680(s32, s32, s32, s32, s32);
void SndDrv_CallArgs_2_001D8680__as_SndDrv_SetPan_0_001D87F0(s32 a, s32 b, s32 c, ...);
s32 sceSifCheckStatRpc__as_SndDrv_Bind_2_001D8890(CD *);
void SndDrv_CallRpc_2_001D8960__as_SndDrv_Bind_2_001D8890(s32, s32, s32, s32, s32);
void* SndDrv_RpcServerFunc_1_001D8AB0(s32 fno, void *data, s32 size);
void sceSifInitRpc(u32 mode);
s32 GetThreadId(void);
void sceSifSetRpcQueue(void *q, s32 thread);
void sceSifRegisterRpc(void *serve, s32 cmd, void *(*func)(s32, void *, s32), void *buf, void *cfunc, void *cbuf, void *q);
void* sceSifRpcLoop(void *q);

/* func_001D7EC0_ */
/* SndDrv_CallRpcSyncWait_2_001D7EC0 */
void SndDrv_CallRpcSyncWait_2_001D7EC0(void) {
    u8 *d;
    s32 r, t;
    s32 n;
    s32 i;
    d = (u8 *)(((u32)gSoundDriverCallBss_004B7A40 & 0x0FFFFFFF) | 0x20000000);
    n = 10000000; goto check;
loop:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
check:
    t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == r) goto loop;
out:
    if (r < 0) return;
    if (gSoundDriverCallBss_004B7CB0) for (i = 0; i < 0x200; i++) d[i] = gSoundDriverCallBss_004B7CB0[i];
    SndDrv_CallRpc_2_001D8960__as_SndDrv_CallRpcSyncWait_2_001D7EC0(0, 1, 0x200, 0, 0x80000);
}

/* SndDrv_CallRpcSyncWaitB_2_001D7FD0 */
void SndDrv_CallRpcSyncWaitB_2_001D7FD0(void) {
    s32 r, t;
    s32 n;
    s32 i;
    n = 10000000; goto check;
loop:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
check:
    t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == r) goto loop;
out:
    if (r >= 0) SndDrv_CallRpc_2_001D8960__as_SndDrv_CallRpcSyncWaitB_2_001D7FD0(0, 1, 0, 0x200, 0x70000);
    for (i = 0x1FF; i >= 0; i--) gSoundDriverCallBss_004B7CB0[i] = gSoundDriverCallBss_004B7A40[i];
}

/* SndDrv_SetParam_0_001D80C0 */

void SndDrv_SetParam_0_001D80C0(s32 d, s32 e)
{
    SndDrv_CallArgs_2_001D8680__as_SndDrv_SetParam_0_001D80C0(0, 1, 0x60000, d, e);
}

/* SndDrv_AllocIopBuffer_1_001D80E0 */
s32 SndDrv_AllocIopBuffer_1_001D80E0(s32 size) {
    s32 r, t;
    s32 n;
    s32 v;
    s32 p = 0;
    n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == r) goto loop; out:
    if (r < 0) v = -1; else v = SndDrv_CallRpc_2_001D8960__as_SndDrv_AllocIopBuffer_1_001D80E0(0, 1, 0, 4, 0x30000);
    if (v >= size) {
        p = sceSifAllocIopHeap(size);
    } else {
        n = 10000000; goto check2; loop2: if (n < 0) { printf(D_001FE6C0); r = -1; goto out2; } n--; check2: t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == r) goto loop2; out2:
        if (r >= 0) SndDrv_CallRpc_2_001D8960__as_SndDrv_AllocIopBuffer_1_001D80E0(0, 1, 0, 4, 0x30000);
    }
    return p;
}

/* SndDrv_StartThread_1_001D8210 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u8 D_004B7EF0[0x2000];
static inline s32 st(void) {
    TP tp;
    s32 id;
    tp.entry = SndDrv_RpcServerThread_1_001D8BE0;
    tp.initPriority = 0x30;
    tp.stack = D_004B7EF0;
    tp.stackSize = 0x2000;
    tp.gpReg = &_gp;
    id = CreateThread(&tp);
    if (id >= 0) {
        gSoundDriverCallSdata_00201E38 = id;
        StartThread(id, 0);
        return 1;
    }
    return 0;
}
s32 SndDrv_StartThread_1_001D8210(void) {
    s32 r, t;
    s32 n;
    if (gSoundDriverCallSbss_00202300 == 0) {
        if (st() != 0) {
            n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == r) goto loop; out:
            if (r >= 0) SndDrv_CallRpc_2_001D8960__as_SndDrv_StartThread_1_001D8210(0, 1, 0, 4, 0x20000);
            gSoundDriverCallSbss_00202300 = 1;
        }
        return 1;
    }
    return 0;
}

/* SndDrv_SetCallback_1_001D8320 */
/* Store a word into the table at 0x4B7EB0. */


void SndDrv_SetCallback_1_001D8320(int index, int value)
{
    gSoundDriverCallBss_004B7EB0[index] = value;
}

/* SndDrv_GetRecvBuffer_1_001D8340 */

s32 *SndDrv_GetRecvBuffer_1_001D8340(void) {
    return gSoundDriverCallBss_004B7A40__as_SndDrv_GetRecvBuffer_1_001D8340;
}

/* SndDrv_CallWithData_1_001D8350 */
s32 SndDrv_CallWithData_1_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *src) {
    u8 *dst = (u8 *)(((u32)gSoundDriverCallBss_004B7A40__as_SndDrv_CallWithData_1_001D8350 & 0x0FFFFFFF) | 0x20000000);
    s32 n = 10000000;
    s32 r;
    s32 i;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    if (src != NULL) {
        for (i = 0; i < c; i++) dst[i] = ((u8 *)src)[i];
    }
    return SndDrv_CallRpc_2_001D8960__as_SndDrv_CallWithData_1_001D8350(a, b, c, d, e);
}

/* SndDrv_Call1_1_001D84F0 */
s32 SndDrv_Call1_1_001D84F0(s32 a, s32 b, s32 c, s32 d) {
    s32 n = 10000000;
    s32 r;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    *(s32 *)(((u32)gSoundDriverCallBss_004B7A40__as_SndDrv_Call1_1_001D84F0 & 0x0FFFFFFF) | 0x20000000) = d;
    return SndDrv_CallRpc_2_001D8960__as_SndDrv_Call1_1_001D84F0(a, b, 4, 4, c);
}

/* SndDrv_Call_2_001D85D0 */
s32 SndDrv_Call_2_001D85D0(s32 a0, s32 a1, s32 a2) {
    s32 r, t;
    s32 n;
    n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == r) goto loop; out: if (r < 0) return -1; return SndDrv_CallRpc_2_001D8960__as_SndDrv_Call_2_001D85D0(a0, a1, 0, 4, a2);
}

/* SndDrv_CallArgs_2_001D8680 */
#define va_start(ap, parm) ((ap) = (char *)__builtin_next_arg(parm) - ((__builtin_args_info(2) >= 8) ? 0 : (8 - __builtin_args_info(2)) * 8))
#define va_arg(ap, T) (*(T *)(((ap) += 8) - 8))

s32 SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, ...) {
    s32 cnt;
    s32 *p;
    s32 r;
    va_list ap;
    p = (s32 *)(((u32)gSoundDriverCallBss_004B7A40 & 0x0FFFFFFF) | 0x20000000);
    cnt = 10000000;
    goto chk;
top:
    if (cnt < 0) {
        printf__as_SndDrv_CallArgs_2_001D8680(D_001FE6C0);
        r = -1;
        goto out;
    }
    cnt--;
chk:
    if (sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0__as_SndDrv_CallArgs_2_001D8680) == 1) goto top;
    r = 1;
out:
    if (r < 0) return -1;
    va_start(ap, c);
    p[0] = va_arg(ap, s32);
    p[1] = va_arg(ap, s32);
    p[2] = va_arg(ap, s32);
    p[3] = va_arg(ap, s32);
    p[4] = va_arg(ap, s32);
    p[5] = va_arg(ap, s32);
    p[6] = va_arg(ap, s32);
    p[7] = va_arg(ap, s32);
    return SndDrv_CallRpc_2_001D8960__as_SndDrv_CallArgs_2_001D8680(a, b, 0x20, 4, c);
}

/* SndDrv_SetPan_0_001D87F0 */

void SndDrv_SetPan_0_001D87F0(s32 a, u16 b, u16 c)
{
    SndDrv_CallArgs_2_001D8680__as_SndDrv_SetPan_0_001D87F0(0, 1, 0x40000, a, b, c);
}

/* SndDrv_IsInitialized_1_001D8810 */
s32 SndDrv_IsInitialized_1_001D8810(void) {
    return gSoundDriverCallSbss_002022FC;
}

/* SndDrv_Shutdown_1_001D8820 */
s32 SndDrv_Shutdown_1_001D8820(void) {
    if ((gSoundDriverCallSbss_002022FC != 0) && (gSoundDriverCallSbss_00202300 != 0)) {
        TerminateThread(gSoundDriverCallSdata_00201E38);
        DeleteThread(gSoundDriverCallSdata_00201E38);
        sceSifRemoveRpc(gSoundDriverCallBss_004B7C40, gSoundDriverCallBss_004B7C90);
        sceSifRemoveRpcQueue(gSoundDriverCallBss_004B7C90);
    }
    gSoundDriverCallSbss_002022FC = 0;
    gSoundDriverCallSbss_00202300 = 0;
    return 1;
}

/* SndDrv_Bind_2_001D8890 */
s32 SndDrv_Bind_2_001D8890(void) {
    s32 i;
    s32 r;
    if (gSoundDriverCallSbss_002022FC == 1) return 0;
    gSoundDriverCallSbss_00202300 = 0;
    do {
        sceSifBindRpc(&gSoundDriverCallBss_004B9EF0__as_SndDrv_Bind_2_001D8890, 0x101A, 0);
    } while (gSoundDriverCallBss_004B9EF0__as_SndDrv_Bind_2_001D8890.serve == 0);
    i = 10000000;
    goto cond;
body:
    if (i < 0) { printf(D_001FE6C0); r = -1; goto done; }
    i--;
cond:
    if (sceSifCheckStatRpc__as_SndDrv_Bind_2_001D8890(&gSoundDriverCallBss_004B9EF0__as_SndDrv_Bind_2_001D8890) == 1) goto body;
    r = 1;
done:
    if (r >= 0) SndDrv_CallRpc_2_001D8960__as_SndDrv_Bind_2_001D8890(0, 1, 0, 4, 0x10000);
    gSoundDriverCallSbss_002022FC = 1;
    return 1;
}

/* SndDrv_CallRpc_2_001D8960 */
s32 SndDrv_CallRpc_2_001D8960(s32 a, s32 b, s32 c, s32 d, u32 e) {
    s32 m;
    s32 *buf;
    s32 n;
    s32 r;
    m = !(b != 0);
    buf = gSoundDriverCallBss_004B7A40__as_SndDrv_CallRpc_2_001D8960;
    c = (c + 0xF) & ~0xF;
    if (c > 0x200) c = 0x200;
    d = (d + 0xF) & ~0xF;
    if (d > 0x200) d = 0x200;
    n = 10000000;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(gSoundDriverCallBss_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    sceSifCallRpc(gSoundDriverCallBss_004B9EF0, ((a << 28) & 0xF0000000) | (e & 0x0FFFFFFF), m, buf, c, buf, d, 0, 0);
    return buf[0];
}

/* text_001D8AB0 */
#ifdef NONMATCHING
/* best-effort C: snd_drv_rpc_server_func.c */
#else
INCLUDE_ASM(SndDrv_RpcServerFunc_1_001D8AB0);
#endif

/* SndDrv_RpcServerThread_1_001D8BE0 */

void SndDrv_RpcServerThread_1_001D8BE0(void)
{
    sceSifInitRpc(0);
    sceSifSetRpcQueue(gSoundDriverCallBss_004B7C90, GetThreadId());
    sceSifRegisterRpc(gSoundDriverCallBss_004B7C40, 0x102A, SndDrv_RpcServerFunc_1_001D8AB0, gSoundDriverCallBss_004B7840, NULL, NULL, gSoundDriverCallBss_004B7C90);
    sceSifRpcLoop(gSoundDriverCallBss_004B7C90);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/bgm_bss.c): gSoundDriverCallBss_004B9EF0 */
s32 gSoundDriverCallBss_004B9EF0[0xc];
/* data group (src/game/data/pad_get_connected_bss_004B5DD0.c): gPadState_004B6900__grp: gPadState_004B6900@0x0, gSoundDriverCallBss_004B6A00@0x100, gSoundDriverCallBss_004B6A20@0x120, gSoundDriverCallBss_004B6A68@0x168, gSoundDriverCallBss_004B7740@0xe40, gSoundDriverCallBss_004B7840@0xf40, gSoundDriverCallBss_004B7A40@0x1140, gSoundDriverCallBss_004B7C40@0x1340, gSoundDriverCallBss_004B7C90@0x1390, gSoundDriverCallBss_004B7CB0@0x13b0, gSoundDriverCallBss_004B7EB0@0x15b0 */
u8 gPadState_004B6900__grp[0x15f0] __attribute__((aligned(16)));
#endif
