#include "common.h"
typedef struct { u8 pad[0x22]; s16 x22; } Own;
typedef struct {
    s16 prev, next, fnext, fprev;
    s16 off, size;
    Own *owner;
} Blk;
typedef struct { u8 pad[0x1C]; s16 x1C; s16 x1E; u8 pad20[2]; s16 x22; u8 pad24[0xC]; } E30;
typedef struct {
    s32 x0;
    s32 x4;
    s16 x8, xA, xC, xE;
    s16 x10, x12, x14, x16, x18, x1A, x1C, x1E;
    s32 x20;
    s32 x24;
    s32 x28;
    u8 pad[0xC];
} G;
extern G D_004830C0;
extern Blk gVramBlocks_0047F0C0[];
extern E30 D_004800C0[];
extern u8 D_0047F080[];
void memset(void *, s32, s32);
s32 Vram_AllocBlock_1_00176FB0(s16);

void Vram_Init_0_001781A0(s32 a0, s32 a1) {
    s32 i;
    s16 j;
    s16 k;

    memset(&D_004830C0, 0, 0x38);
    D_004830C0.x0 = (a0 + 0x1F) & ~0x1F;
    D_004830C0.x4 = (a1 + 0x1F) & ~0x1F;
    memset(D_0047F080, 0, 0x40);
    memset(D_004800C0, 0, 0x3000);
    for (i = 0xFF; i >= 0; i--) {
        D_004800C0[i].x22 = -1;
    }
    memset(gVramBlocks_0047F0C0, 0, 0x1000);
    D_004830C0.xE = 0;
    D_004830C0.xC = -1;
    D_004830C0.xA = 0x100;
    D_004830C0.x16 = 0;
    D_004830C0.x14 = -1;
    D_004830C0.x1A = 0;
    D_004830C0.x18 = -1;
    D_004830C0.x1C = -1;
    D_004830C0.x1E = 0;
    D_004830C0.x8 = 0;
    for (j = 0; j < 0x100; j++) {
        D_004800C0[j].x1C = j + 1;
        D_004800C0[j].x1E = j - 1;
    }
    D_004800C0[0xFF].x1C = 0;
    D_004800C0[0].x1E = 0xFF;
    D_004830C0.x12 = 0x100;
    D_004830C0.x10 = 0;
    for (k = 0; k < 0x100; k++) {
        gVramBlocks_0047F0C0[k].prev = k + 1;
        gVramBlocks_0047F0C0[k].next = k - 1;
    }
    gVramBlocks_0047F0C0[0xFF].prev = 0;
    gVramBlocks_0047F0C0[0].next = 0xFF;

    D_004830C0.x12--;
    if (gVramBlocks_0047F0C0[0].prev == 0) {
        D_004830C0.x10 = -1;
    } else {
        gVramBlocks_0047F0C0[gVramBlocks_0047F0C0[0].prev].next = gVramBlocks_0047F0C0[0].next;
        gVramBlocks_0047F0C0[gVramBlocks_0047F0C0[0].next].prev = gVramBlocks_0047F0C0[0].prev;
        if (D_004830C0.x10 == 0) D_004830C0.x10 = gVramBlocks_0047F0C0[0].prev;
    }
    D_004830C0.x16++;
    if (D_004830C0.x14 == -1) {
        D_004830C0.x14 = 0;
        gVramBlocks_0047F0C0[0].prev = 0;
        gVramBlocks_0047F0C0[0].next = 0;
    } else {
        gVramBlocks_0047F0C0[0].prev = D_004830C0.x14;
        gVramBlocks_0047F0C0[0].next = gVramBlocks_0047F0C0[D_004830C0.x14].next;
        gVramBlocks_0047F0C0[gVramBlocks_0047F0C0[0].prev].next = 0;
        gVramBlocks_0047F0C0[gVramBlocks_0047F0C0[0].next].prev = 0;
        D_004830C0.x14 = 0;
    }
    D_004830C0.x1A++;
    if (D_004830C0.x18 == -1) {
        D_004830C0.x18 = 0;
        gVramBlocks_0047F0C0[0].fnext = 0;
        gVramBlocks_0047F0C0[0].fprev = 0;
    } else {
        gVramBlocks_0047F0C0[0].fnext = D_004830C0.x18;
        gVramBlocks_0047F0C0[0].fprev = gVramBlocks_0047F0C0[D_004830C0.x18].fprev;
        gVramBlocks_0047F0C0[gVramBlocks_0047F0C0[0].fnext].fprev = 0;
        gVramBlocks_0047F0C0[gVramBlocks_0047F0C0[0].fprev].fnext = 0;
        D_004830C0.x18 = 0;
    }
    D_004830C0.x28 = 0;
    D_004830C0.x20 = 0;
    gVramBlocks_0047F0C0[0].off = D_004830C0.x0;
    gVramBlocks_0047F0C0[0].size = D_004830C0.x4;
    for (k = D_004830C0.x1C; k != -1; k = D_004830C0.x1C) {
        gVramBlocks_0047F0C0[k].owner->x22 = -1;
        Vram_AllocBlock_1_00176FB0(k);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): gVramBlocks_0047F0C0__grp: gVramBlocks_0047F0C0@0x0, D_0047F0C4@0x4, D_0047F0C8@0x8, D_004800B0@0xff0 */
u8 gVramBlocks_0047F0C0__grp[0x1000] __attribute__((aligned(16)));
#endif
