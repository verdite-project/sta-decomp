#include "include_asm.h"
#include "m2c.h"
typedef struct { u8 pad[0x14]; s32 x14; s32 x18; } Hdr;
extern Hdr *gFontLoadSbss_002020C8;
extern s32 gFontLoadBss_0048D350[];
#ifndef NONMATCHING
extern s32 gFontLoadSbss_002020C4;
extern Hdr **gFontLoadSbss_002020CC;
extern s32 gFontLoadSbss_002020D0;
extern s32 gFontLoadBss_0048D354[];
extern s32 gFontLoadBss_0048D358[];
extern u8 gFontLoadRodata_001FCCC0[];
extern u8 gFontLoadRodata_001FCCD0[];
extern u8 gFontLoadRodata_001FCCE0[];
#else
/* data twins (src/game/data/sbss.c): gFontLoadSbss_002020C4 */
static s32 gFontLoadSbss_002020C4;
/* data twins (src/game/data/sbss.c): gFontLoadSbss_002020CC */
static Hdr **gFontLoadSbss_002020CC;
/* data twins (src/game/data/sbss.c): gFontLoadSbss_002020D0 */
static s32 gFontLoadSbss_002020D0;
/* data twins (src/game/data/ui_gauge_bss.c): gFontLoadBss_0048D354 */
static s32 gFontLoadBss_0048D354[0x1];
/* data twins (src/game/data/ui_gauge_bss.c): gFontLoadBss_0048D358 */
static s32 gFontLoadBss_0048D358[0x2];
/* data twins (src/game/data/ui_gauge_rodata2.c): gFontLoadRodata_001FCCC0 */
static u8 gFontLoadRodata_001FCCC0[0x10] = "sta_font_00\000\000\000\000\000";
/* data twins (src/game/data/ui_gauge_rodata2.c): gFontLoadRodata_001FCCD0 */
static u8 gFontLoadRodata_001FCCD0[0x10] = "sta_font_01\000\000\000\000\000";
/* data twins (src/game/data/ui_gauge_rodata2.c): gFontLoadRodata_001FCCE0 */
static u8 gFontLoadRodata_001FCCE0[0x10] = "sta_font_02\000\000\000\000\000";
#endif
void Font_Load_3_00188830(s32 a0);
void Arc_LoadFile_2_00159DD0(s32, s32, void *, s32 *);
s32 Tex_HashName_2_00177F80(void *);
s32 Tex_Find_1_00177AF0(s32, s32);

/* text_00188010 */
#ifdef NONMATCHING
/* best-effort C: text_render.c */
#else
INCLUDE_ASM(Text_Render_2_00188010);
#endif

/* Font_Load_3_00188830 */
void Font_Load_3_00188830(s32 a0) {
    s32 x;
    gFontLoadSbss_002020C4 = a0;
    Arc_LoadFile_2_00159DD0(0x84A34CE9, a0, &gFontLoadSbss_002020D0, &x);
    Arc_LoadFile_2_00159DD0(0x84A23D27, a0, &gFontLoadSbss_002020CC, &x);
    gFontLoadBss_0048D350[0] = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gFontLoadRodata_001FCCC0), gFontLoadSbss_002020D0);
    gFontLoadBss_0048D354[0] = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gFontLoadRodata_001FCCD0), gFontLoadSbss_002020D0);
    gFontLoadBss_0048D358[0] = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gFontLoadRodata_001FCCE0), gFontLoadSbss_002020D0);
    gFontLoadSbss_002020C8 = *gFontLoadSbss_002020CC;
    gFontLoadSbss_002020C8->x14 = (s32)((u8 *)gFontLoadSbss_002020C8 + gFontLoadSbss_002020C8->x14);
    gFontLoadSbss_002020C8->x18 = (s32)((u8 *)gFontLoadSbss_002020C8 + gFontLoadSbss_002020C8->x18);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gFontLoadSbss_002020C8 */
Hdr *gFontLoadSbss_002020C8;
/* data twins (src/game/data/ui_gauge_bss.c): gFontLoadBss_0048D350 */
s32 gFontLoadBss_0048D350[0x1];
#endif
