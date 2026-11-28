#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/gfx.h"
typedef struct { u8 b0:6; u8 b6:1; u8 b7:1; } B;
extern u32 D_002F1940[];
extern u32 D_002F1944[];
extern u32 D_002F1990[];
extern u32 D_002F1994[];
extern u32 D_002F1998[];
#ifndef NONMATCHING
extern u32 D_002F19A4[];
#else
/* data twins (src/game/data/gs_packet_bss_002F1990.c): D_002F19A4 */
static u32 D_002F19A4[0x1];
#endif
extern u32 D_002F19A8[];
extern u32 D_002F19AC[];
extern u32 D_00201F4C;
extern u32 D_00201F48;
#ifndef NONMATCHING
extern u32 D_00201F44;
#else
/* data twins (src/game/data/sbss.c): D_00201F44 */
static u32 D_00201F44;
#endif
extern u32 D_00201F40;
extern u32 D_00201F3C;
#ifndef NONMATCHING
extern u32 D_00201F38;
#else
/* data twins (src/game/data/sbss.c): D_00201F38 */
static u32 D_00201F38;
#endif
extern s8 D_4A0[];
extern s8 D_4B0[];
extern s8 D_1B90[];
extern s8 D_2710[];
extern s8 D_2770[];
extern s8 D_3C30[];
extern s8 D_3C70[];
extern s8 D_001F4B80[];
void Gfx_UploadVu1Program_0_00155460(u32 buf, u32 size);
B* sceDmaGetChan(s32);
void sceDmaSend(B *, s8 *);
void FlushCache(s32);
void Dma_SprCopy_1_001789E0(u32, u32, s32);

/* Gfx_UploadVu1Program_0_00155460 */
static inline void chain(u32 *p) {
    s32 i;
    for (i = 0; i < 0xCC0; i++, p += 8) {
        ((u128 *)p)[0] = 0;
        ((u128 *)p)[1] = 0;
        p[0] = 0x20000000;
        p[1] = (u32)(p + 8) & 0x0FFFFFFF;
        p[6] = (u32)p;
        p[7] = (u32)(p + 8) & 0x0FFFFFFF;
    }
    *(u128 *)p = 0x70000000;
}

void Gfx_UploadVu1Program_0_00155460(u32 buf, u32 size) {
    s32 i;
    u32 *p;
    B *b;

    D_002F1940[0] = buf;
    D_002F1944[0] = size;
    D_002F19AC[0] = 0;
    D_002F1990[0] = 0;
    D_002F19A4[0] = ((size >> 5) - 0x1982) >> 1;
    D_002F1994[0] = 0;
    D_002F1998[0] = 0;
    D_002F199C[0] = (buf + 0x19820) | 0x20000000;
    D_002F19A0[0] = (buf + 0x33040 + D_002F19A4[0] * 32) | 0x20000000;
    D_002F1948[0] = -1;
    D_002F19A8[0] = D_002F19A0[0];
    b = sceDmaGetChan(1);
    b->b6 = 1;
    sceDmaSend(b, D_001F4B80);
    while (*(volatile u32 *)0x10009000 & 0x100) {
    }
    D_00201F54 = (u32)(D_4A0 - 0x4A0) >> 3;
    D_00201F50 = (u32)D_4A0 >> 3;
    D_00201F4C = (u32)D_4B0 >> 3;
    D_00201F48 = (u32)D_1B90 >> 3;
    D_00201F44 = (u32)D_2710 >> 3;
    D_00201F40 = (u32)D_2770 >> 3;
    D_00201F3C = (u32)D_3C30 >> 3;
    D_00201F38 = (u32)D_3C70 >> 3;
    chain((u32 *)D_002F199C[0]);
    chain((u32 *)D_002F19A0[0]);
    FlushCache(0);
    Dma_SprCopy_1_001789E0((D_002F199C[0] - 0x19820) & 0x0FFFFFFF, D_002F199C[0] & 0x0FFFFFFF, 0x1982);
    Dma_SprCopy_1_001789E0((D_002F19A0[0] - 0x19820) & 0x0FFFFFFF, D_002F19A0[0] & 0x0FFFFFFF, 0x1982);
}

/* Gfx_Nop_2_001558F0 */
void Gfx_Nop_2_001558F0(void) {

}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/gs_packet_bss.c): D_002F1940__grp: D_002F1940@0x0, D_002F1944@0x4, D_002F1948@0x8, D_002F194C@0xc */
u8 D_002F1940__grp[0x10] __attribute__((aligned(16)));
#endif
