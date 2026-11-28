/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Gs_UploadTim_1_001E54E8.c.
 * The retail assembly of Gs_UploadTim_1_001E54E8 also holds Sjis_DecodeChar_2_001E5B18. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 18 of 396 (was 22): h2 local removed (h >> 1 written inline) fixes the sll/srl order. Left: gcc saved-reg priority: k gets s1, w s3, h2 s4 (retail w s1, h2 s3, k s4). Tried decl perms, statement perms, k types, k via inline, switch, fresh psm2. */
/* round 3 near-miss: ee-gcc, 22 words: saved-register choice for k/w/h/(h >> 1) */
#include "common.h"
typedef struct {
    u64 TBP0:14, TBW:6, PSM:6, TW:4, TH:4, TCC:1, TFX:2, CBP:14, CPSM:4, CSM:1, CSA:5, CLD:3;
} Tex0;
typedef struct { u8 pad[4]; s32 clut; u8 pad8[8]; Tex0 tex0; u64 tex1; } Tim;
typedef struct { u64 TBP0:14, TBW:6, PSM:6, TW:4, TH:4, TCC:1, TFX:2, CBP:14, CPSM:4, CSM:1, CSA:5, CLD:3; } Tex0B;
typedef struct { u8 pad[0x10]; Tex0B tex0; } Tim2;
typedef struct { u64 q[12]; } LI __attribute__((aligned(16)));
void FlushCache(s32);
void sceGsSetDefLoadImage(LI *, s16, s16, s16, s16, s16, s16, s16);
void sceGsExecLoadImage(LI *, void *);
#define D2_CHCR ((volatile int *)0x1000A000)
#define GIF_STAT ((volatile int *)0x10003020)

void Gs_UploadTim_1_001E54E8(Tim *t, u64 *tex0, u64 *tex1) {
    LI li;
    u16 h;
    u16 w;
    s32 psm;
    s32 k;
    u64 v;
    v = *(volatile u64 *)&t->tex0;
    k = 2;
    w = 1 << (s32)((v >> 26) & 0xF);
    h = 1 << (s32)((v >> 30) & 0xF);
    psm = (s32)((v >> 20) & 0x3F);
    if (psm == 0x13 || psm == 0x1B) k = 2;
    else if (psm == 0x14) k = 1;
    else if (psm == 0x2C) k = 1;
    else k = (psm == 0x24) ? 1 : 8;
    if (w * h * k > 0x7FFFF) {
        sceGsSetDefLoadImage(&li, t->tex0.TBP0, t->tex0.TBW, t->tex0.PSM, 0, 0, w, (h >> 1));
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
        sceGsSetDefLoadImage(&li, t->tex0.TBP0, t->tex0.TBW, t->tex0.PSM, 0, (h >> 1), w, (h >> 1));
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + w * h * k / 4 + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
    } else {
        sceGsSetDefLoadImage(&li, t->tex0.TBP0, t->tex0.TBW, t->tex0.PSM, 0, 0, w, h);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
    }
    psm = t->tex0.PSM;
    if (psm == 0x13) {
        sceGsSetDefLoadImage(&li, t->tex0.CBP, 1, t->tex0.CPSM, 0, 0, 16, 16);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + t->clut + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
    } else if (psm == 0x1B) {
        sceGsSetDefLoadImage(&li, t->tex0.CBP, 1, t->tex0.CPSM, 0, 0, 16, 16);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + t->clut + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
    } else if (psm == 0x14) {
        sceGsSetDefLoadImage(&li, t->tex0.CBP, 1, t->tex0.CPSM, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + t->clut + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
    } else if (psm == 0x2C) {
        sceGsSetDefLoadImage(&li, t->tex0.CBP, 1, t->tex0.CPSM, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + t->clut + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
    } else if (psm == 0x24) {
        sceGsSetDefLoadImage(&li, t->tex0.CBP, 1, t->tex0.CPSM, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u8 *)t + t->clut + 0x20);
        do {
            while (*D2_CHCR & 0x100) ;
        } while (*GIF_STAT & 0xC00);
    }
    if (tex0) *tex0 = *(u64 *)&t->tex0;
    if (tex1) *tex1 = t->tex1;
}
#else
INCLUDE_ASM(Gs_UploadTim_1_001E54E8);
#endif
