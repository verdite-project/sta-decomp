/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Tex_Resident_0_001777C0.c. The matching build takes it from the assembly that
 * texture.c includes (INCLUDE_ASM(Tex_Resident_0_001777C0)). */
#ifdef NONMATCHING
/* NEAR: 34 of 202 words differ (was 53). Rewritten with the G struct at D_004830C0 like matched Tex_Release_1_00177570;
   idx = G.x8 read before the a0 round-up fixes the entry.
   Remaining: after the Vram_AllocForTex_0_00176BF0 call to the end, register naming only: retail keeps r in a1, &x22 in a0, addresses in v0
   and values in v1 (we use a0/v1 the other way round), same ops. Permuting the 6 tail statements (720 builds) did not help. */
#include "common.h"
typedef struct {
    u64 tbp0 : 14;
    u64 tbw : 6;
    u64 psm : 6;
    u64 tw : 4;
    u64 th : 4;
    u64 tcc : 1;
    u64 tfx : 2;
    u64 cbp : 14;
    u64 cpsm : 4;
    u64 csm : 1;
    u64 csa : 5;
    u64 cld : 3;
} Tex0;
typedef struct {
    Tex0 tex0;
    u64 x8;
    u32 x10;
    u16 x14;
    u8 pad16[6];
    s16 x1C;
    s16 x1E;
    u16 x20;
    u16 x22;
    s32 x24;
    u8 b0 : 3;
    u8 b3 : 5;
    u8 pad29;
    u16 x2A;
    u16 pad2C;
    u16 x2E;
} E30;
typedef struct {
    s16 prev, next, fnext, fprev;
    u16 off, size;
    void *owner;
} Blk;
typedef struct {
    s32 x0;
    s32 x4;
    s16 x8, xA, xC, xE;
} G;
extern G D_004830C0;
extern Blk gVramBlocks_0047F0C0[];
extern E30 D_004800C0[];
#ifndef NONMATCHING
extern s32 D_00202018;
#else
/* data twins (src/game/data/sbss.c): D_00202018 */
static s32 D_00202018;
#endif
u16 Vram_AllocForTex_0_00176BF0(E30 *, u16);

void Tex_Resident_0_001777C0(u16 a0, u64 *a1, u64 *a2) {
    s16 idx;
    E30 *p;
    u16 r;

    idx = D_004830C0.x8;
    a0 = (a0 + 0x1F) & ~0x1F;
    D_004830C0.xA--;
    if (idx == D_004800C0[idx].x1C) {
        D_004830C0.x8 = -1;
    } else {
        D_004800C0[D_004800C0[idx].x1C].x1E = D_004800C0[idx].x1E;
        D_004800C0[D_004800C0[idx].x1E].x1C = D_004800C0[idx].x1C;
        if (D_004830C0.x8 == idx) D_004830C0.x8 = D_004800C0[idx].x1C;
    }
    D_004830C0.xE++;
    if (D_004830C0.xC == -1) {
        D_004830C0.xC = idx;
        D_004800C0[idx].x1C = idx;
        D_004800C0[idx].x1E = idx;
    } else {
        D_004800C0[idx].x1C = D_004830C0.xC;
        D_004800C0[idx].x1E = D_004800C0[D_004830C0.xC].x1E;
        D_004800C0[D_004800C0[idx].x1C].x1E = idx;
        D_004800C0[D_004800C0[idx].x1E].x1C = idx;
        D_004830C0.xC = idx;
    }
    D_00202018 = 0;
    p = &D_004800C0[idx];
    p->b0 = 3;
    D_004800C0[idx].x2A = a0 << 4;
    D_004800C0[idx].x2E = 0;
    D_004800C0[idx].x14 = a0 << 4;
    r = Vram_AllocForTex_0_00176BF0(p, (u32)(D_004800C0[idx].x2A + D_004800C0[idx].x2E + 15) >> 4);
    D_004800C0[idx].x22 = r;
    D_004800C0[idx].x10 = gVramBlocks_0047F0C0[r].off;
    if (a1) p->tex0 = *(Tex0 *)a1;
    if (a2) D_004800C0[idx].x8 = *a2;
    D_004800C0[idx].tex0.tbp0 = D_004800C0[idx].x10;
    D_004800C0[idx].tex0.cbp = D_004800C0[idx].x10;
    D_00202018 = 0;
}
#endif
