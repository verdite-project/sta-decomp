#include "common.h"
#include "game/ee.h"
typedef int TI __attribute__((mode(TI)));
typedef struct { u64 a; u64 b; } P16;
typedef struct { u64 fl; u32 x8; s32 *xC; u32 x10; u32 x14; u8 pad18[0x18]; P16 tbl[1]; } G;
typedef struct { u8 pad[0x18]; u8 b18, b19, b1A, b1B; u8 pad1C[0x64]; s32 x80; } A;
extern G *gGsText_00201E5C;
void GsText_EmitTag_0_001E39F8(A *);
#define BIT (0x8000ULL << 33)

s32 GsText_EmitQuad_1_001E3790(A *a) {
    s32 n;

    n = 0xC; if (!(gGsText_00201E5C->fl & BIT)) n = 0xD;
    *(TI *)gGsText_00201E5C->xC = 0;
    gGsText_00201E5C->xC[0] = n | 0x20000000;
    gGsText_00201E5C->xC[1] = (s32)(gGsText_00201E5C->xC + n * 4 + 4);
    gGsText_00201E5C->xC += 4;
    if (!(gGsText_00201E5C->fl & BIT)) {
        *(TI *)gGsText_00201E5C->xC = 0;
        gGsText_00201E5C->xC[3] = 0x5100000C;
        gGsText_00201E5C->xC += 4;
    }
    *(u64 *)gGsText_00201E5C->xC = ((((u64)(((u8)(gGsText_00201E5C->fl >> 50)) & 1) << 9) | 0x54) << 47) | 0xB000400000008001ULL;
    ((u64 *)gGsText_00201E5C->xC)[1] = 0x0525252521EEULL;
    gGsText_00201E5C->xC += 4;
    *(u64 *)gGsText_00201E5C->xC = gGsText_00201E5C->tbl[a->x80].a;
    ((u64 *)gGsText_00201E5C->xC)[1] = 6;
    gGsText_00201E5C->xC += 4;
    *(u64 *)gGsText_00201E5C->xC = gGsText_00201E5C->tbl[a->x80].b;
    ((u64 *)gGsText_00201E5C->xC)[1] = 0x14;
    gGsText_00201E5C->xC += 4;
    gGsText_00201E5C->xC[0] = a->b1A;
    gGsText_00201E5C->xC[1] = a->b19;
    gGsText_00201E5C->xC[2] = a->b18;
    gGsText_00201E5C->xC[3] = a->b1B;
    gGsText_00201E5C->xC += 4;
    GsText_EmitTag_0_001E39F8(a);

    if (++*(u16 *)((u8 *)gGsText_00201E5C + 4) >= gGsText_00201E5C->x14) {
        if (gGsText_00201E5C->fl & BIT) {
            GsText_Kick_1_001E24A0();
            GsText_WaitDma_1_001E3688();
            gGsText_00201E5C->xC = (s32 *)gGsText_00201E5C->x8;
            *(u16 *)((u8 *)gGsText_00201E5C + 4) = 0;
        }
        return -1;
    }
    return 0;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): gGsText_00201E5C */
G *gGsText_00201E5C = 0;
#endif
