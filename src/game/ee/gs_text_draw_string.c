/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/GsText_DrawString_2_001E2748.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 3 of 176 words (ee-gcc). Was 7: GsText_GetColor_1_001E2D08 is void (fixed the v0/v1 swap). Left: delay-slot fill at the
   `r == 1 && ...` break test: retail `bne s3,v0` + shared `addiu s0,s1,2` and next bnel delay `daddu s1,s0`;
   ours `bnel` and a repeated `addiu s0,s1,2`. Tried &&/nested/goto/for/continue/else-first/inline forms. */
#include "common.h"
typedef struct { s32 v[4]; } Q;
typedef struct { u8 pad[8]; u16 x8; } F;
typedef struct { u64 x0; u8 p8[0xC]; u32 x14; u8 p18[0x10]; F *x28; } A;
typedef struct { f32 x0; u8 p4[0xC]; f32 x10; f32 x14; u8 p18[0x1C]; f32 x34; u8 p38[0x24]; s32 x5C; u8 p60[4]; f32 x64; } S;
extern A *D_00201E5C;
extern S *D_00201E60;
s32 GsText_Begin_1_001E23C8(void);
void GsText_End_1_001E2430(void);
void GsText_SetPos_1_001E2B18(f32 *);
s32 GsText_Measure_2_001E2B88(u16 *, f32 *, f32 *, s32);
void GsText_GetColor_1_001E2D08(Q *);
void GsText_SetColorQ_0_001E2D38(Q *);
u16 *GsText_ParseEscape_1_001E2D70(u16 *, Q *);
void *GsText_FindGlyph_1_001E3058(s32);
s32 GsText_EmitGlyph_1_001E3178(void *);

static inline void al(f32 *pos, u16 *s, f32 *w, f32 *h) { if (D_00201E60->x5C & 3) { GsText_Measure_2_001E2B88(s, w, h, 1); if (D_00201E60->x5C & 1) D_00201E60->x10 = (s32)(pos[0] - *w); else if (D_00201E60->x5C & 2) D_00201E60->x10 = (s32)(pos[0] - *w * 0.5f); } }
s32 GsText_DrawString_2_001E2748(f32 *pos, u16 *s) {
    Q q;
    f32 w;
    f32 h;
    f32 y;
    u16 c;
    void *g;
    s32 r = 0;
    if (!(D_00201E5C->x0 & 0x1000000000000ULL) && !((u16)*(u16 *)((u8 *)D_00201E5C + 4) < D_00201E5C->x14)) return 0;
    if (GsText_Begin_1_001E23C8() == -1) return 0;
    GsText_SetPos_1_001E2B18(pos);
    if (D_00201E60->x5C & 4) {
        GsText_Measure_2_001E2B88(s, &w, &h, 0);
        D_00201E60->x14 = (s32)(pos[1] - h * 0.5f);
    }
    if (D_00201E60->x5C & 3) { GsText_Measure_2_001E2B88(s, &w, &h, 1); if (D_00201E60->x5C & 1) D_00201E60->x10 = (s32)(pos[0] - w); else if (D_00201E60->x5C & 2) D_00201E60->x10 = (s32)(pos[0] - w * 0.5f); }
    GsText_GetColor_1_001E2D08(&q);
    y = (D_00201E5C->x28->x8 + D_00201E60->x64) * D_00201E60->x34;
    while ((c = *(s = GsText_ParseEscape_1_001E2D70(s, &q))) != 0) {
        GsText_SetColorQ_0_001E2D38(&q);
        if (c == 10) {
            D_00201E60->x10 = D_00201E60->x0;
            D_00201E60->x14 += y;
    if (D_00201E60->x5C & 3) { GsText_Measure_2_001E2B88(s + 1, &w, &h, 1); if (D_00201E60->x5C & 1) D_00201E60->x10 = (s32)(pos[0] - w); else if (D_00201E60->x5C & 2) D_00201E60->x10 = (s32)(pos[0] - w * 0.5f); }

        } else {
            g = GsText_FindGlyph_1_001E3058(c);
            if (g) { r = GsText_EmitGlyph_1_001E3178(g); if (r == 1 && !(D_00201E5C->x0 & 0x1000000000000ULL) && !((u16)*(u16 *)((u8 *)D_00201E5C + 4) < D_00201E5C->x14)) break; }
        }
        s++;
    }
    GsText_End_1_001E2430();
    return r;
}
#else
INCLUDE_ASM(GsText_DrawString_2_001E2748);
#endif
