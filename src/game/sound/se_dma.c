#include "common.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct { u32 p; s32 x4; s32 x8; u32 sz; u8 pad[0x10]; } E_Se_UploadBankB_1_001DB510;
typedef struct { s32 v; s32 pad[7]; } E_Se_FindFreeSlot_0_001DB6B0;
typedef struct { s32 x0, x4, x8, xC, x10; s16 x14; u8 p[0xA]; } A;
typedef struct { s32 x0, x4, x8, xC; } B;
typedef struct { s8 b0, b1, b2, b3; } C;
typedef struct { s32 x0, x4; s16 x8, xA; s32 xC, x10; u8 p[0xC]; } M;
typedef struct { s8 a; s8 b; s8 c; u8 d; } E;
typedef char *va_list;
extern E_Se_UploadBankB_1_001DB510 D_004BA500[16];
extern E_Se_FindFreeSlot_0_001DB6B0 D_004BA500__as_Se_FindFreeSlot_0_001DB6B0[];
extern s16 gSeDmaBss_004BAA34[];
#ifndef NONMATCHING
extern s32 gSeDmaBss_004BAA2C[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA2C */
static s32 gSeDmaBss_004BAA2C[0x1];
#endif
#ifndef NONMATCHING
extern s32 gSeDmaBss_004BAA40[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA40 */
static s32 gSeDmaBss_004BAA40[0x1];
#endif
#ifndef NONMATCHING
extern s32 gSeDmaBss_004BAA44[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA44 */
static s32 gSeDmaBss_004BAA44[0x1];
#endif
extern s32 gSeDmaBss_004BAA48[];
extern s32 gSeDmaBss_004BAA4C[];
extern s32 gSeDmaBss_004BAA50[];
#ifndef NONMATCHING
extern s32 gSeDmaBss_004BAA54[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA54 */
static s32 gSeDmaBss_004BAA54[0x1];
#endif
#ifndef NONMATCHING
extern s32 gSeDmaBss_004BAA58[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA58 */
static s32 gSeDmaBss_004BAA58[0x2];
#endif
extern s32 gSeDmaBss_004BAA60[];
extern s32 gSeDmaBss_004BAA64[];
extern s32 gSeDmaBss_004BAA68[];
extern s32 gSeDmaBss_004BAA6C[];
extern u32 gSeDmaBss_004BAA48__as_Se_DmaBegin_1_001DB9B0[];
extern u32 gSeDmaBss_004BAA4C__as_Se_DmaBegin_1_001DB9B0[];
extern u32 gSeDmaBss_004BAA50__as_Se_DmaBegin_1_001DB9B0[];
extern u32 gSeDmaBss_004BAA68__as_Se_DmaBegin_1_001DB9B0[];
extern B D_004BA700[];
extern C D_004BA780[];
extern M D_004BA880[];
#ifndef NONMATCHING
extern s32 gSeDmaBss_004BAA20[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA20 */
static s32 gSeDmaBss_004BAA20[0x1];
#endif
extern s32 gSeBss_004BAA28[];
#ifndef NONMATCHING
extern s32 gSeDmaBss_004BAA30[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA30 */
static s32 gSeDmaBss_004BAA30[0x1];
#endif
extern A D_004BA500__as_Se_Init_1_001DBAC0[];
extern s16 D_004BAA36__as_Se_Init_1_001DBAC0[];
extern struct { char pad[0x280]; E e[0x68]; u8 t[16][32]; } D_004BA500__as_Se_ParseVoiceMap_0_001DBD20;
extern s8 *gSeFlushSbss_00202328__as_Se_QueueCommand_1_001DBDB0;
extern s8 gSeBss_004BA2E0__as_Se_QueueCommand_1_001DBDB0[];
#ifndef NONMATCHING
extern s16 gSeDmaData_001F38F0[];
#else
/* data twins (src/game/data/player_status_data.c): gSeDmaData_001F38F0 */
static s16 gSeDmaData_001F38F0[0x1] __attribute__((aligned(16))) = { 0 };
#endif
#ifndef NONMATCHING
extern s16 gSeDmaData_001F38F2[];
#else
/* data twins (src/game/data/player_status_data.c): gSeDmaData_001F38F2 */
static s16 gSeDmaData_001F38F2[0x7e] __attribute__((aligned(2))) = { 0xca, 0x195, 0x25f, 0x32a, 0x3f4, 0x4be, 0x588, 0x652, 0x71c, 0x7e5, 0x8ae, 0x976, 0xa3f, 0xb06, 0xbce, 0xc95, 0xd5b, 0xe21, 0xee6, 0xfab, 0x106f, 0x1133, 0x11f6, 0x12b8, 0x1379, 0x143a, 0x14fa, 0x15b9, 0x1677, 0x1734, 0x17f1, 0x18ac, 0x1967, 0x1a20, 0x1ad9, 0x1b90, 0x1c46, 0x1cfc, 0x1db0, 0x1e63, 0x1f14, 0x1fc5, 0x2074, 0x2122, 0x21cf, 0x227a, 0x2324, 0x23cd, 0x2474, 0x251a, 0x25bf, 0x2661, 0x2703, 0x27a3, 0x2841, 0x28de, 0x2979, 0x2a12, 0x2aaa, 0x2b41, 0x2bd5, 0x2c68, 0x2cf9, 0x2d88, 0x2e16, 0x2ea1, 0x2f2b, 0x2fb3, 0x3039, 0x30be, 0x3140, 0x31c1, 0x323f, 0x32bc, 0x3336, 0x33af, 0x3425, 0x349a, 0x350c, 0x357c, 0x35ea, 0x3657, 0x36c1, 0x3728, 0x378e, 0x37f2, 0x3853, 0x38b2, 0x390f, 0x396a, 0x39c2, 0x3a18, 0x3a6c, 0x3abe, 0x3b0d, 0x3b5a, 0x3ba4, 0x3bed, 0x3c33, 0x3c76, 0x3cb8, 0x3cf6, 0x3d33, 0x3d6d, 0x3da5, 0x3dda, 0x3e0d, 0x3e3d, 0x3e6b, 0x3e97, 0x3ec0, 0x3ee6, 0x3f0a, 0x3f2c, 0x3f4b, 0x3f68, 0x3f82, 0x3f9a, 0x3faf, 0x3fc2, 0x3fd2, 0x3fe0, 0x3feb, 0x3ff4, 0x3ffa, 0x3ffe };
#endif
#ifndef NONMATCHING
extern s16 gSeDmaData_001F39EE[];
#else
/* data twins (src/game/data/player_status_data.c): gSeDmaData_001F39EE */
static s16 gSeDmaData_001F39EE[0x1] __attribute__((aligned(2))) = { 0x3fff };
#endif
s32 Se_UploadBankB_1_001DB510(s32 i, s32 a1, u32 sz);
s32 Se_FindFreeSlot_0_001DB6B0(void);
void Se_ParseVoiceMap_0_001DBD20(u8 *a);
void Se_QueueCommand_1_001DBDB0(u8 c, s32 n, ...);
void FlushCache(s32);
u32 sceSifAllocIopHeap(u32);
s32 SndDrv_Call_2_001D85D0__as_Se_UploadBankB_1_001DB510();
s32 sceSifDmaStat(u32);
s32 sceSifSetDma(void *, s32);
void FlushCache__as_Se_DmaStep_1_001DB830(s32, s32);
s32 Se_DmaBegin_1_001DB9B0__as_Se_UploadBankB_1_001DB510_(u32, s32, s32);
u32 sceSifSetDma__as_Se_UploadBankB_1_001DB510_(void *, s32);
void FlushCache__as_Se_DmaBegin_1_001DB9B0(s32, s32);
s32 sceSifSetDma__as_Se_DmaBegin_1_001DB9B0(s32 *, s32);
void bzero(void *, s32);
void SndDrv_CallArgs_2_001D8680__as_Se_UploadBankB_1_001DB510__(s32 a, s32 b, s32 c, ...);

/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510__ */

/* Se_UploadBankB_1_001DB510_ */

/* Se_UploadBankB_1_001DB510_ */
/* Se_UploadBankB_1_001DB510 */

/* Se_UploadBankB_1_001DB510 */
/* Se_UploadBankB_1_001DB510 */
/* Se_UploadBankB_1_001DB510 */
s32 Se_UploadBankB_1_001DB510(s32 i, s32 a1, u32 sz)
{
    E_Se_UploadBankB_1_001DB510 *e;
    s32 ret = -1;

    if (i < 0 || i >= 16)
        return -1;
    e = &D_004BA500[i];
    switch (gSeDmaSbss_00202330) {
    case 0:
        sz = (sz + 15) & ~15;
        if (e->p == 0) {
            e->p = sceSifAllocIopHeap(sz);
            if (e->p == 0)
                break;
            if (e->p + sz > 0x1FFFFF)
                break;
        } else if (e->sz != sz) {
            break;
        }
        e->sz = sz;
        gSeDmaSbss_00202330 = 1;
    case 1:
        if (Se_DmaStep_1_001DB830() != 0) {
            gSeDmaSbss_00202330 = 2;
        } else {
            ret = 0;
            break;
        }
    case 2:
        if (Se_DmaBegin_1_001DB9B0__as_Se_UploadBankB_1_001DB510_(e->p, a1, e->sz) < 0) {
            gSeDmaSbss_00202330 = 0;
            break;
        }
        gSeDmaSbss_00202330 = 3;
    case 3:
        if (Se_DmaStep_1_001DB830() != 0) {
            gSeDmaSbss_00202330 = 0;
            ret = 1;
        } else {
            ret = 0;
        }
    }
    FlushCache(0);
    return ret;
}

/* Se_FindFreeSlot_0_001DB6B0 */
s32 Se_FindFreeSlot_0_001DB6B0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_004BA500__as_Se_FindFreeSlot_0_001DB6B0[i].v == 0) break;
    }
    if (i >= 16) return -1;
    return i;
}

/* Se_SendCommand_0_001DB700 */
void Se_SendCommand_0_001DB700(u32 a, u32 b)
{
    u32 t[2] = { 0 };
    t[a & 1] = 1 << (b % 24);
    SndDrv_CallArgs_2_001D8680__as_Se_UploadBankB_1_001DB510__(4, 1, 0x10700, t[0], t[1]);
}

/* Se_Stop_0_001DB780 */
void Se_Stop_0_001DB780(void) {
    if ((*D_004BAA36) != 0) {
        SndDrv_Call_2_001D85D0__as_Se_UploadBankB_1_001DB510(4, 1, 0x600);
    }
    (*gSeDmaBss_004BAA34) = 0;
    SndDrv_Call1_1_001D84F0(4, 1, 0xC00, 0);
    if ((*D_004BAA36) != 0) {
        SndDrv_Call_2_001D85D0__as_Se_UploadBankB_1_001DB510(4, 1, 0x500);
    }
}

/* Se_Start_0_001DB7F0 */
/* Turn a sound channel's output on once; the same shape as Strm_DrvInit_0_001D8E30
 * and KFIV's SoundDriver_EnableOutput (kfiv-decomp src/game/sound/sound.c). */



void Se_Start_0_001DB7F0(void)
{
    if (D_004BAA36[0] != 1) {
        SndDrv_Call_2_001D85D0(4, 1, 0x500);
        D_004BAA36[0] = 1;
    }
}

/* Se_DmaStep_1_001DB830 */

s32 Se_DmaStep_1_001DB830(void) {
    if (gSeDmaBss_004BAA58[0] == 0) return 1;
    if (sceSifDmaStat(gSeDmaBss_004BAA54[0]) >= 0) return 0;
    SndDrv_CallArgs_2_001D8680__as_Se_UploadBankB_1_001DB510__(4, 1, 0xB00, gSeDmaBss_004BAA40[0], gSeDmaBss_004BAA50[0]);
    gSeDmaBss_004BAA48[0] -= gSeDmaBss_004BAA50[0];
    if (gSeDmaBss_004BAA48[0] <= 0) {
        gSeDmaBss_004BAA58[0] = 0;
        return 1;
    }
    gSeDmaBss_004BAA44[0] += 0x4000;
    gSeDmaBss_004BAA40[0] += 0x4000;
    if (gSeDmaBss_004BAA48[0] > 0x4000) {
        gSeDmaBss_004BAA4C[0] = 0x4000;
        gSeDmaBss_004BAA50[0] = 0x4000;
    } else {
        gSeDmaBss_004BAA4C[0] = gSeDmaBss_004BAA48[0];
        gSeDmaBss_004BAA50[0] = gSeDmaBss_004BAA48[0];
        gSeDmaBss_004BAA4C[0] = (gSeDmaBss_004BAA4C[0] + 0xF) & ~0xF;
    }
    gSeDmaBss_004BAA6C[0] = 0;
    gSeDmaBss_004BAA60[0] = gSeDmaBss_004BAA44[0];
    gSeDmaBss_004BAA64[0] = gSeDmaBss_004BAA2C[0];
    gSeDmaBss_004BAA68[0] = gSeDmaBss_004BAA4C[0];
    FlushCache__as_Se_DmaStep_1_001DB830(0, gSeDmaBss_004BAA44[0]);
    gSeDmaBss_004BAA54[0] = sceSifSetDma__as_Se_UploadBankB_1_001DB510_(gSeDmaBss_004BAA60, 1);
    return 0;
}

/* Se_DmaBegin_1_001DB9B0 */

s32 Se_DmaBegin_1_001DB9B0(s32 arg0, s32 arg1, u32 arg2) {
    (*gSeDmaBss_004BAA44) = arg1;
    (*gSeDmaBss_004BAA40) = arg0;
    (*gSeDmaBss_004BAA58) = 1;
    (*gSeDmaBss_004BAA48__as_Se_DmaBegin_1_001DB9B0) = arg2;
    if (arg2 > 0x4000) {
        (*gSeDmaBss_004BAA4C__as_Se_DmaBegin_1_001DB9B0) = 0x4000;
        (*gSeDmaBss_004BAA50__as_Se_DmaBegin_1_001DB9B0) = 0x4000;
    } else {
        (*gSeDmaBss_004BAA4C__as_Se_DmaBegin_1_001DB9B0) = arg2;
        (*gSeDmaBss_004BAA50__as_Se_DmaBegin_1_001DB9B0) = arg2;
        (*gSeDmaBss_004BAA4C__as_Se_DmaBegin_1_001DB9B0) = ((*gSeDmaBss_004BAA4C__as_Se_DmaBegin_1_001DB9B0) + 0xF) & ~0xF;
    }
    (*gSeDmaBss_004BAA6C) = 0;
    (*gSeDmaBss_004BAA60) = (*gSeDmaBss_004BAA44);
    (*gSeDmaBss_004BAA64) = (*gSeDmaBss_004BAA2C);
    (*gSeDmaBss_004BAA68__as_Se_DmaBegin_1_001DB9B0) = (*gSeDmaBss_004BAA4C__as_Se_DmaBegin_1_001DB9B0);
    FlushCache__as_Se_DmaBegin_1_001DB9B0(0, (*gSeDmaBss_004BAA44));
    (*gSeDmaBss_004BAA54) = sceSifSetDma__as_Se_DmaBegin_1_001DB9B0(gSeDmaBss_004BAA60, 1);
    if ((*gSeDmaBss_004BAA54) == 0) {
        return -1;
    }
    return 0;
}

/* Se_Init_1_001DBAC0 */

s32 Se_Init_1_001DBAC0(void) {
    M *m;
    s32 i;
    A *a;
    B *b;
    C *c;
    s8 (*t)[32];
    s32 j;

    SndDrv_Call_2_001D85D0(4, 1, 0x100);
    gSeDmaBss_004BAA30[0] = 0x3FFF;
    SndDrv_CallArgs_2_001D8680(4, 1, 0x400, gSeDmaBss_004BAA30[0], gSeDmaBss_004BAA30[0]);
    gSeDmaBss_004BAA20[0] = 0;
    gSeDmaBss_004BAA2C[0] = SndDrv_CallArgs_2_001D8680(4, 1, 0xA00);
    gSeBss_004BAA28[0] = 0x5010;
    gSeDmaBss_004BAA24[0] = 0x5010;
    gSeDmaBss_004BAA34[0] = 1;
    D_004BAA36__as_Se_Init_1_001DBAC0[0] = 0;
    a = D_004BA500__as_Se_Init_1_001DBAC0;
    i = 16;
    while (i--) {
        a->x0 = a->x4 = a->x8 = 0;
        a->x10 = 0;
        a->x14 = 15 - i;
        a++;
    }
    b = D_004BA700;
    i = 8;
    while (i--) {
        b->x0 = 0;
        b->x4 = b->xC = 7 - i;
        b->x8 = -1;
        b++;
    }
    c = D_004BA780;
    i = 64;
    while (i--) {
        c->b0 = c->b1 = c->b2 = -1;
        c++;
    }
    m = D_004BA880;
    i = 4;
    while (i--) {
        m->x0 = -1;
        m->x10 = 0;
        m->xC = 0;
        m->x4 = m->x8 = m->xA = 0;
        m++;
    }
    t = gSeBss_004BA920;
    i = 8;
    while (i--) {
        for (j = 0; j < 32; j++) (*t)[j] = -1;
        t++;
    }
    gSeDmaBss_004BAA58[0] = 0;
    bzero(gSeBss_004BA2E0, 0x1C);
    gSeFlushSbss_00202328 = &gSeFlushBss_004BA0E0[1];
    gSeDmaSbss_00202330 = 0;
    gSeSbss_0020232C = 0;
    gSeFlushBss_004BA0E0[0] = 0;
    FlushCache(0);
    return 0;
}

/* Se_ParseVoiceMap_0_001DBD20 */
void Se_ParseVoiceMap_0_001DBD20(u8 *a) {
    s32 n = *a; u8 *p = a + 1; while (n--) { u8 i = p[0]; u8 j = p[1]; s8 c = p[2]; E *e = &D_004BA500__as_Se_ParseVoiceMap_0_001DBD20.e[i]; p += 3; if (c >= 0) { e->b = j; e->a = c; e->c = 1; D_004BA500__as_Se_ParseVoiceMap_0_001DBD20.t[j][e->a] = i; } else { e->c = -1; e->b = -1; } }
}

/* Se_QueueCommand_1_001DBDB0 */
void Se_QueueCommand_1_001DBDB0(u8 c, s32 n, ...) {
    s32 i;
    va_list ap;
    ap = (char *)__builtin_next_arg(n) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    *gSeFlushSbss_00202328__as_Se_QueueCommand_1_001DBDB0++ = c;
    if (c == 1) gSeFlushSdata_00201E3C += 3;
    { i = n; while (i--) { if (gSeFlushSbss_00202328__as_Se_QueueCommand_1_001DBDB0 >= gSeBss_004BA2E0__as_Se_QueueCommand_1_001DBDB0) break; ap += 8; *gSeFlushSbss_00202328__as_Se_QueueCommand_1_001DBDB0++ = *(s32 *)(ap - 8); } }
    gSeFlushBss_004BA0E0[0]++;
}

/* Se_VolumeCurveA_0_001DBEA0 */
s16 Se_VolumeCurveA_0_001DBEA0(s32 a) {
    s32 m;
    s32 i;
    s32 f;
    s16 t;
    a += 0x200;
    if (a > 0x7FF) a -= 0x800;
    m = a & 0x1FF;
    i = m >> 2;
    f = 4 - m % 4;
    switch (a / 0x200) {
    case 0:
        if (i < 0x7F) {
            t = gSeDmaData_001F38F2[i];
            return t + f * (gSeDmaData_001F38F0[i] - t) / 4;
        }
        return *gSeDmaData_001F39EE;
    case 1:
        if (i > 0) {
            t = gSeDmaData_001F38F0[0x7F - i];
            return t + f * (gSeDmaData_001F38F0[0x80 - i] - t) / 4;
        }
        return *gSeDmaData_001F39EE;
    case 2:
        if (i < 0x7F) {
            t = gSeDmaData_001F38F2[i];
            return -(t + f * (gSeDmaData_001F38F0[i] - t) / 4);
        }
        return -*gSeDmaData_001F39EE;
    case 3:
        if (i > 0) {
            t = gSeDmaData_001F38F0[0x7F - i];
            return -(t + f * (gSeDmaData_001F38F0[0x80 - i] - t) / 4);
        }
        return -*gSeDmaData_001F39EE;
    }
    return 0;
}

/* Se_VolumeCurveB_0_001DC0F0 */
s16 Se_VolumeCurveB_0_001DC0F0(s32 a) {
    s32 m = a & 0x1FF;
    s32 i = m >> 2;
    s32 w = 4 - m % 4;
    s16 b;
    switch (a / 512) {
    case 0:
        if (i < 0x7F) {
            b = gSeDmaData_001F38F2[i];
            return b + w * (gSeDmaData_001F38F0[i] - b) / 4;
        }
        return gSeDmaData_001F39EE[0];
    case 1:
        if (i > 0) {
            b = gSeDmaData_001F38F0[0x7F - i];
            return b + w * (gSeDmaData_001F38F0[0x80 - i] - b) / 4;
        }
        return gSeDmaData_001F39EE[0];
    case 2:
        if (i < 0x7F) {
            b = gSeDmaData_001F38F2[i];
            return -(b + w * (gSeDmaData_001F38F0[i] - b) / 4);
        }
        return -gSeDmaData_001F39EE[0];
    case 3:
        if (i > 0) {
            b = gSeDmaData_001F38F0[0x7F - i];
            return -(b + w * (gSeDmaData_001F38F0[0x80 - i] - b) / 4);
        }
        return -gSeDmaData_001F39EE[0];
    }
    return 0;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gSeDmaSbss_00202330 */
s32 gSeDmaSbss_00202330;
/* data twins (src/game/data/save_system_start_bss.c): gSeDmaBss_004BAA24, gSeDmaBss_004BAA34, gSeDmaBss_004BAA48, gSeDmaBss_004BAA4C, gSeDmaBss_004BAA50 */
s32 gSeDmaBss_004BAA24[0x1];
s16 gSeDmaBss_004BAA34[0x6] __attribute__((aligned(4)));
s32 gSeDmaBss_004BAA48[0x1];
s32 gSeDmaBss_004BAA4C[0x1];
s32 gSeDmaBss_004BAA50[0x1];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_system_start_bss.c): D_004BAA60__grp: gSeDmaBss_004BAA60@0x0, gSeDmaBss_004BAA64@0x4, gSeDmaBss_004BAA68@0x8, gSeDmaBss_004BAA6C@0xc */
u8 D_004BAA60__grp[0x10] __attribute__((aligned(16)));
#endif
