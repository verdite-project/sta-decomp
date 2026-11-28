#include "include_asm.h"
#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/ui.h"
#include "game/gfx.h"
#include "game/math.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S_Ui_DrawGauge_0_00182EF0;
typedef struct { u8 r; u8 g; u8 b; u8 a; } Col_Ui_DrawGauge_0_00182EF0;
typedef struct { u8 pad[0x6C]; s8 *p; } O_Ui_DrawCursorB_0_00183090;
typedef struct 
{
  s32 a;
  s8 *b;
} S_Ui_DrawElemAt_0_001832D0 __attribute__((aligned(16)));
typedef struct { s32 first; s32 x; u8 b0:1; u8 b1:1; u8 b2:1; } O_Ui_LoadItemImageSmall_3_001833E0;
typedef struct { s32 a; s8 *p; s32 b[2]; f32 f[8]; } Ent;
typedef struct { u8 b[0x100]; } Buf_Ui_LoadItemImageSmall_3_001833E0;
typedef struct { u8 r, g, b, a; } Col_Ui_DrawWindow_0_00183650;
typedef struct { s32 a; void *b; } Buf_Ui_DrawWindow_0_00183650;
typedef struct { u8 b[256]; } Buf_Ui_LoadMapSheet_3_00183750;
typedef struct { u8 a:1; u8 b:1; u8 c:1; } BF_Ui_DrawGauge_0_00182EF0;
typedef struct {
    s32 x0;
    s32 x4;
    Flags8 f8;
} Res;
typedef struct { s32 idx; u8 pad[0x28]; f32 x, z; u8 pad2[0xC]; } Obj;
typedef struct { u32 n; Obj *e; } L;
typedef struct { u8 pad[0x14]; L *l; } R_Ui_DrawGauge_0_00182EF0;
typedef struct { f32 x, z; } V2_Ui_DrawGauge_0_00182EF0;
typedef struct { u8 pad[0xA]; u16 xA; u8 pad2[0x14]; u16 x20; u8 pad3[0x1A]; u8 x3C; u8 pad4[0x53]; } E;
typedef struct { u8 pad[0x10]; L *l; } R_Menu_DrawRingB_0_00184960;
typedef struct { u8 pad[0x14]; f32 x14; f32 x18; u8 pad1C[0x10]; f32 x2C; f32 x30; u8 pad34[8]; u32 x3C; } G_MenuProc_DrawScrolled_0_00184CF0;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C;
    u8 x2D;
    u8 x2E;
    u8 x2F;
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O_Item_GetDurability_0_001848A0;
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R_MenuProc_DrawGauge_0_00185030;
typedef struct { u8 pad0[0x7C]; R_MenuProc_DrawGauge_0_00185030 *x7C; } G_MenuProc_DrawGauge_0_00185030;
typedef struct { s32 idx; u8 pad[0x28]; f32 x2C; u8 pad30[0x10]; } Elem_Menu_DrawFrame_0_00185390;
typedef struct { u32 n; Elem_Menu_DrawFrame_0_00185390 *e; } List_Menu_DrawFrame_0_00185390;
typedef struct { u8 pad[0x1C]; List_Menu_DrawFrame_0_00185390 *list; } Ctx_Menu_DrawFrame_0_00185390;
typedef union { u128 q; f32 f[4]; } V;
typedef struct { s32 idx; u8 pad[0x28]; f32 x2C; f32 x30; u8 pad34[0xC]; } Elem_Menu_DrawRingD_0_00185510;
typedef struct { u32 n; Elem_Menu_DrawRingD_0_00185510 *e; } List_Menu_DrawRingD_0_00185510;
typedef struct { u8 pad[0x18]; List_Menu_DrawRingD_0_00185510 *list; } Ctx_Menu_DrawRingD_0_00185510;
typedef struct { f32 x, y; } V2_Menu_DrawRingD_0_00185510;
typedef struct { u8 a:3; u8 b:5; } BF_Item_GetDurability_0_001848A0;
typedef struct { f32 x; f32 y; BF_Item_GetDurability_0_001848A0 f8; u8 pad9[0xB]; f32 x14; u8 pad18[8]; f32 x20; f32 x24; u8 pad28[8]; } T_Item_GetDurability_0_001848A0;
typedef struct { u8 pad[0x20]; List_Menu_DrawRingD_0_00185510 *list; } Ctx_Menu_DrawRingE_0_00185B40;
typedef struct { s32 idx; s32 x4; u8 pad[0x24]; f32 x2C; f32 x30; u8 pad34[0xC]; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x10]; List *list; } Ctx;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C;
typedef struct {
    f32 x0;
    f32 x4;
    BF_Item_GetDurability_0_001848A0 x8;
    u8 pad9[0xB];
    f32 x14;
    u8 pad18[8];
    f32 x20;
    f32 x24;
    s8 *x28;
} T_Menu_DrawStatRing_0_00186440;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C[4];
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O_Menu_DrawStatRing_0_00186440;
typedef struct { u8 pad0[0x54]; R_MenuProc_DrawGauge_0_00185030 *x54; u8 pad58[4]; R_MenuProc_DrawGauge_0_00185030 *x5C; } G;
typedef struct { s16 lo; s16 hi; } P;
extern S_Ui_DrawGauge_0_00182EF0 D_001F2770[] __attribute__((aligned(16)));
#ifndef NONMATCHING
extern f32 D_002020A4;
#else
/* data twins (src/game/data/sbss.c): D_002020A4 */
static f32 D_002020A4;
#endif
#ifndef NONMATCHING
extern f32 D_002020A0;
#else
/* data twins (src/game/data/sbss.c): D_002020A0 */
static f32 D_002020A0;
#endif
extern u8 D_0048D141[];
extern u8 D_0048D142[];
extern u8 D_0048D143[];
extern s8 D_0048D170[];
#ifndef NONMATCHING
extern u8 D_001FC9C0[];
#else
/* data twins (src/game/data/ui_gauge_rodata.c): D_001FC9C0 */
static u8 D_001FC9C0[0x18] = "item/imgs%04d.tdc\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern u8 D_001FC9D8[];
#else
/* data twins (src/game/data/ui_gauge_rodata.c): D_001FC9D8 */
static u8 D_001FC9D8[0x18] __attribute__((aligned(8))) = "imgs%04d\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
extern O_Ui_LoadItemImageSmall_3_001833E0 *D_0048D110[];
extern Col_Ui_DrawWindow_0_00183650 D_002020A8;
extern s32 D_0048D0E0[];
extern s32 D_0048D0E4[];
extern M2C_UNK D_001FC9F0[];
extern M2C_UNK D_001FCA08[];
#ifndef NONMATCHING
extern s32 D_00201CDC;
#else
/* data twins (src/game/data/sdata.c): D_00201CDC */
static s32 D_00201CDC = -1;
#endif
#ifndef NONMATCHING
extern s32 D_00201CE0;
#else
/* data twins (src/game/data/sdata.c): D_00201CE0 */
static s32 D_00201CE0 = -1;
#endif
#ifndef NONMATCHING
extern s32 D_00201CE4;
#else
/* data twins (src/game/data/sdata.c): D_00201CE4 */
static s32 D_00201CE4 = -1;
#endif
#ifndef NONMATCHING
extern s32 D_00201CE8;
#else
/* data twins (src/game/data/sdata.c): D_00201CE8 */
static s32 D_00201CE8 = -1;
#endif
extern s8 *D_002020AC;
extern s32 D_0048D0F0[];
extern s32 D_0048D0F4[];
extern s32 D_0048D0F8[];
extern s32 D_0048D0FC[];
extern s32 D_0048D100[];
extern s32 D_0048D104[];
extern s32 D_0048D108[];
extern s32 D_0048D10C[];
extern M2C_UNK D_001FCA10[];
extern M2C_UNK D_001FCA20[];
#ifndef NONMATCHING
extern s8 D_001FCA30[];
#else
/* data twins (src/game/data/ui_gauge_rodata.c): D_001FCA30 */
static s8 D_001FCA30[0x18] = "chrimg/cimg%04d.tdc\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FCA48[];
#else
/* data twins (src/game/data/ui_gauge_rodata.c): D_001FCA48 */
static s8 D_001FCA48[0x18] __attribute__((aligned(8))) = "cimg%04d\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
extern M2C_UNK D_001FCA60[];
extern M2C_UNK D_001FCA78[];
extern Ent D_0048D170__as_Ui_LoadItemImageSmall_3_001833E0[];
extern s32 D_002020A8__as_Ui_LoadMapSheet_3_00183750;
extern s8 *D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[];
extern s32 D_002020A8__as_Ui_LoadAreaImage_3_00183970;
extern s8 *D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[];
extern Res *D_002020AC__as_Ui_LoadCharImage_3_00183B90;
extern s32 D_002020A8__as_Ui_LoadCharImage_3_00183B90;
extern f32 D_0048D0F0__as_Ui_LoadCharImage_3_00183B90[];
extern f32 D_0048D0F4__as_Ui_LoadCharImage_3_00183B90[];
extern f32 D_0048D0F8__as_Ui_LoadCharImage_3_00183B90[];
extern f32 D_0048D0FC__as_Ui_LoadCharImage_3_00183B90[];
extern f32 D_0048D100__as_Ui_LoadCharImage_3_00183B90[];
extern f32 D_0048D104__as_Ui_LoadCharImage_3_00183B90[];
extern f32 D_0048D108__as_Ui_LoadCharImage_3_00183B90[];
extern f32 D_0048D10C__as_Ui_LoadCharImage_3_00183B90[];
extern s32 D_002020A8__as_Ui_LoadItemImage_3_00183DC0;
extern s8 *D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[];
extern Res *D_002020AC__as_Ui_IsImageLoading_0_00183FF0;
extern G_MenuProc_DrawScrolled_0_00184CF0 D_0048D060;
extern S_Ui_DrawGauge_0_00182EF0 D_001F2700 __attribute__((aligned(16)));
#ifndef NONMATCHING
extern f32 D_00202084;
#else
/* data twins (src/game/data/sbss.c): D_00202084 */
static f32 D_00202084;
#endif
#ifndef NONMATCHING
extern f32 D_002020B0;
#else
/* data twins (src/game/data/sbss.c): D_002020B0 */
static f32 D_002020B0;
#endif
#ifndef NONMATCHING
extern f32 D_002020B4;
#else
/* data twins (src/game/data/sbss.c): D_002020B4 */
static f32 D_002020B4;
#endif
#ifndef NONMATCHING
extern f32 D_002020B8;
#else
/* data twins (src/game/data/sbss.c): D_002020B8 */
static f32 D_002020B8;
#endif
#ifndef NONMATCHING
extern f32 D_002020BC;
#else
/* data twins (src/game/data/sbss.c): D_002020BC */
static f32 D_002020BC;
#endif
extern V D_001F26F0[];
extern S_Ui_DrawGauge_0_00182EF0 D_001F26D0 __attribute__((aligned(16)));
extern char D_0048CE40[];
#ifndef NONMATCHING
extern s32 D_0020207C;
#else
/* data twins (src/game/data/sbss.c): D_0020207C */
static s32 D_0020207C;
#endif
#ifndef NONMATCHING
extern s32 D_00202080;
#else
/* data twins (src/game/data/sbss.c): D_00202080 */
static s32 D_00202080;
#endif
#ifndef NONMATCHING
extern f32 D_00202088;
#else
/* data twins (src/game/data/sbss.c): D_00202088 */
static f32 D_00202088;
#endif
#ifndef NONMATCHING
extern f32 D_0020208C;
#else
/* data twins (src/game/data/sbss.c): D_0020208C */
static f32 D_0020208C;
#endif
#ifndef NONMATCHING
extern f32 D_00202090;
#else
/* data twins (src/game/data/sbss.c): D_00202090 */
static f32 D_00202090;
#endif
#ifndef NONMATCHING
extern f32 D_00202094;
#else
/* data twins (src/game/data/sbss.c): D_00202094 */
static f32 D_00202094;
#endif
#ifndef NONMATCHING
extern f32 D_00202098;
#else
/* data twins (src/game/data/sbss.c): D_00202098 */
static f32 D_00202098;
#endif
#ifndef NONMATCHING
extern f32 D_0020209C;
#else
/* data twins (src/game/data/sbss.c): D_0020209C */
static f32 D_0020209C;
#endif
extern S_Ui_DrawGauge_0_00182EF0 D_001F2630 __attribute__((aligned(16)));
extern S_Ui_DrawGauge_0_00182EF0 D_001F2650 __attribute__((aligned(16)));
extern S_Ui_DrawGauge_0_00182EF0 D_001F2670 __attribute__((aligned(16)));
extern s32 D_0048CF40[];
extern s32 D_0048CFC0[];
extern s32 D_0048CF80[];
extern s32 D_0048D000[];
extern s8 D_001FCA80[];
extern s8 D_001FCA88[];
#ifndef NONMATCHING
extern s8 D_001FCB80[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCB80 */
static s8 D_001FCB80[0x8] __attribute__((aligned(16))) = "%d\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FCB88[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCB88 */
static s8 D_001FCB88[0x8] = "+%d\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FCB90[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCB90 */
static s8 D_001FCB90[0x10] = " \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
void Ui_DrawCursorB_0_00183090(f32 *arg0, s32 arg1, s32 arg2, s32 arg3);
void Ui_DrawElemAt_0_001832D0(s8 *arg0, s32 arg1, s32 arg2);
void Ui_LoadItemImageSmall_3_001833E0(s32 arg0, s32 arg1);
void Ui_DrawWindow_0_00183650(s8 *arg0);
void Ui_LoadItemImage_3_00183DC0(s32 arg0);
void Menu_DrawRingB_0_00184960(s32 a0, f32 ang);
void MenuProc_DrawScrolled_0_00184CF0(s8 *a0, s32 a1, u32 n);
void MenuProc_DrawGauge_0_00185030(O_Item_GetDurability_0_001848A0 *o, s32 a1, u32 mode, u32 a3);
void Menu_DrawFrame_0_00185390(s32 a0, s32 a1, s32 a2, f32 f);
void Menu_DrawRingD_0_00185510(s32 a0, f32 f);
void MenuProc_DrawHpMp_1_00185740(O_Item_GetDurability_0_001848A0 *o, s32 a1, u32 mode, s16 *a3);
void Menu_DrawRingE_0_00185B40(s32 a0, f32 f);
void Menu_DrawStatRing_0_00186440(s32 a0, s32 a1, s32 a2, s32 a3, f32 f);
u32 Menu_CalcStatBar_0_001866B0(s32 a0, u16 *a1, u16 *a2, u16 *a3, u16 *t0);
void MenuProc_DrawStatValue_0_00186990(O_Menu_DrawStatRing_0_00186440 *o, s32 id, u32 mode, u32 p);
f32 sinf(f32);
s8* MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawSprite_2_00181680(s32, void *, void *, void*, void *, s32);
void Ui_DrawSpriteRotated_1_00182080(f32, s32, f32 *, s8 *, s32 *, s32);
void Ui_DrawElem_1_00182C10(s8*, void *);
void sprintf(void *, void *, s32);
O_Ui_LoadItemImageSmall_3_001833E0* ImageLoader_Request_1_001E1570(void *, s32);
void Tex_Release_1_00177570(s8 *);
s8* Tex_Find_1_00177AF0(s32, s32);
s32 Tex_HashName_2_00177F80(void *);
R_Ui_DrawGauge_0_00182EF0* MenuLayout_Get_1_00189050(s32);
f32 atanf(f32);
f32 cosf(f32);
void Ui_DrawList_1_001829B0(Obj *, u8 *, void *, s32);
void MenuProc_DrawItemStats_0_00184280(void);
f32 sqrtf(f32);
O_Ui_DrawCursorB_0_00183090* MenuLayout_GetSub_1_00189020__as_Ui_DrawCursorB_0_00183090(s32);
void Ui_DrawElem_1_00182C10__as_Ui_DrawElemAt_0_001832D0(s8 *, S_Ui_DrawElemAt_0_001832D0 *);
void Ui_DrawElem_1_00182C10__as_Ui_DrawWindow_0_00183650(s8 *, Buf_Ui_DrawWindow_0_00183650 *);
void sprintf__as_Ui_LoadMapSheet_3_00183750(u8 *, M2C_UNK *, s32);
s8* ImageLoader_Request_1_001E1570__as_Ui_LoadMapSheet_3_00183750(u8 *, M2C_UNK);
s32 Tex_HashName_2_00177F80__as_Ui_LoadMapSheet_3_00183750(u8 *);
s32 Tex_Find_1_00177AF0__as_Ui_LoadMapSheet_3_00183750(s32, s32);
void sprintf__as_Ui_LoadAreaImage_3_00183970(u8 *, M2C_UNK *, s32);
s8* ImageLoader_Request_1_001E1570__as_Ui_LoadAreaImage_3_00183970(u8 *, M2C_UNK);
s32 Tex_HashName_2_00177F80__as_Ui_LoadAreaImage_3_00183970(u8 *);
s32 Tex_Find_1_00177AF0__as_Ui_LoadAreaImage_3_00183970(s32, s32);
void Tex_Release_1_00177570__as_Ui_LoadCharImage_3_00183B90(s32);
Res* ImageLoader_Request_1_001E1570__as_Ui_LoadCharImage_3_00183B90(void *, s32);
s32 Tex_Find_1_00177AF0__as_Ui_LoadCharImage_3_00183B90(s32, s32);
void sprintf__as_Ui_LoadItemImage_3_00183DC0(u8 *, M2C_UNK *, s32);
s8* ImageLoader_Request_1_001E1570__as_Ui_LoadItemImage_3_00183DC0(u8 *, M2C_UNK);
s32 Tex_HashName_2_00177F80__as_Ui_LoadItemImage_3_00183DC0(u8 *);
s32 Tex_Find_1_00177AF0__as_Ui_LoadItemImage_3_00183DC0(s32, s32);
u8* MenuLayout_GetSub_1_00189020__as_Menu_DrawRingA_0_00184040(s32);
E* Item_GetTable_1_001AFC90(void);
f32 fabsf(f32);
void GsPkt_SetReg_3_001543E0(s32, u64);
u32 strlen(void *);
void TextParam_Init_1_00187A90(void *, void *, u64);
s32 Text_Render_2_00188010(void *, Col_Ui_DrawWindow_0_00183650);
void MenuProc_DrawWeight_0_00185D70(void);
void MenuProc_DrawScrolled_0_00184CF0__as_Menu_DrawRingB_0_00184960(void);
R_Menu_DrawRingB_0_00184960* MenuLayout_Get_1_00189050__as_Menu_DrawRingC_0_00184DF0(s32);
void MenuProc_DrawGauge_0_00185030__as_Menu_DrawRingC_0_00184DF0(void);
G_MenuProc_DrawGauge_0_00185030* MenuLayout_GetSub_1_00189020__as_MenuProc_DrawGauge_0_00185030(s32);
Ctx_Menu_DrawFrame_0_00185390* MenuLayout_Get_1_00189050__as_Menu_DrawFrame_0_00185390(s32);
s32 MenuLayout_GetSub_1_00189020__as_Menu_DrawFrame_0_00185390(s32);
Ctx_Menu_DrawRingD_0_00185510* MenuLayout_Get_1_00189050__as_Menu_DrawRingD_0_00185510(s32);
s32 MenuLayout_GetSub_1_00189020__as_Menu_DrawRingD_0_00185510(s32);
void Ui_DrawList_1_001829B0__as_Menu_DrawRingD_0_00185510(Elem_Menu_DrawRingD_0_00185510 *, s32, void (*)(), s32);
Ctx_Menu_DrawRingE_0_00185B40* MenuLayout_Get_1_00189050__as_Menu_DrawRingE_0_00185B40(s32);
s32 MenuLayout_GetSub_1_00189020__as_Menu_DrawRingE_0_00185B40(s32);
void Ui_DrawList_1_001829B0__as_Menu_DrawRingE_0_00185B40(Elem_Menu_DrawRingD_0_00185510 *, s32, void (*)(), s32);
s32 Menu_CalcStatBar_0_001866B0__as_Menu_DrawStatRing_0_00186440(s32, s32, s32, s32, s32);
G* MenuLayout_GetSub_1_00189020__as_MenuProc_DrawStatValue_0_00186990(s32);

/* text_00182C10 */
#ifdef NONMATCHING
/* best-effort C: ui_draw_elem.c */
#else
INCLUDE_ASM(Ui_DrawElem_1_00182C10);
#endif

/* Ui_DrawGauge_0_00182EF0 */

/* Ui_DrawGauge_0_00182EF0 */
void Ui_DrawGauge_0_00182EF0(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 u1, f32 alpha) {
    S_Ui_DrawGauge_0_00182EF0 t __attribute__((aligned(16)));
    Col_Ui_DrawGauge_0_00182EF0 col;
    s8 *o;

    t = D_001F2770[0];
    o = *(s8 **)(MenuLayout_GetSub_1_00189020(0) + 0x84);
    col.r = 0x80;
    col.g = 0x80;
    col.b = 0x80;
    D_002020A4 += 0.1f;
    col.a = alpha / 2.0f;
    t.x = (f32)x0 + 6.0f * sinf(D_002020A4);
    t.y = (f32)y0;
    Ui_DrawSprite_2_00181680(*(s32 *)(o + 4), o + 0x10, o + 0x20, &col, &t, 0);
    t.x = (f32)x1 - 6.0f * sinf(D_002020A4);
    t.y = (f32)y1;
    Ui_DrawSprite_2_00181680(*(s32 *)(o + 4), o + 0x10, o + 0x20, &col, &t, 1);
}

/* Ui_DrawCursorB_0_00183090 */

void Ui_DrawCursorB_0_00183090(f32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 col;
    f32 c[4];
    f32 b[4];
    f32 a[4];
    f32 h, step, d;
    O_Ui_DrawCursorB_0_00183090 *s0;
    s32 n;

    s0 = MenuLayout_GetSub_1_00189020__as_Ui_DrawCursorB_0_00183090(0);
    col = 0x80404040;
    if (arg2 != 0) {
        d = arg0[3] - arg0[1];
        h = 1.0f / (f32)(arg2 - (arg1 - 1)); h *= d;
        if (arg1 == arg2) {
            D_002020A0 = 0.0f;
        } else {
            step = h;
            if (h < 10.0f) {
                h = 10.0f;
                step = (d - 10.0f) / (f32)(arg2 - arg1);
            }
            if (arg2 < arg3 + arg1) {
                D_002020A0 = step * (f32)(arg2 - arg1);
            } else {
                if (arg3 < 0) arg3 = 0;
                D_002020A0 = (f32)arg3 * step;
            }
        }
        b[0] = arg0[0];
        b[1] = D_002020A0 + arg0[1];
        b[2] = arg0[2];
        b[3] = 4.0f + (D_002020A0 + arg0[1]);
        c[0] = arg0[0];
        c[1] = 4.0f + (D_002020A0 + arg0[1]);
        c[2] = arg0[2];
        c[3] = h + (D_002020A0 + arg0[1]);
        a[0] = arg0[0];
        a[1] = h + (D_002020A0 + arg0[1]);
        a[2] = arg0[2];
        a[3] = h + (4.0f + (D_002020A0 + arg0[1]));
        Menu_DrawBackground_0_00187B20(0);
        n = M2C_FIELD(s0->p, s32 *, 4);
        Ui_DrawSpriteRotated_1_00182080(0.0f, n, b, s0->p + 0x20, &col, 0);
        Ui_DrawSpriteRotated_1_00182080(0.0f, n, c, s0->p + 0x50, &col, 0);
        Ui_DrawSpriteRotated_1_00182080(0.0f, n, a, s0->p + 0x80, &col, 0);
    }
}

/* Ui_DrawElemAt_0_001832D0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u8 D_0048D140[0x30];

void Ui_DrawElemAt_0_001832D0(s8 *arg0, s32 arg1, s32 arg2)
{
  S_Ui_DrawElemAt_0_001832D0 s = {0};
  s8 *t1;
  u8 *a3;
  u8 *a1;
  t1 = D_0048D170 + (arg1 * 0x30);
  *((s32 *) t1) = arg2;
  s.a = 1;
  a3 = D_0048D140 + (arg1 * 4);
  s.b = t1;
  *((f32 *) (((s8 *) arg0) + 0x34)) = 1.0f;
  *((f32 *) (((s8 *) arg0) + 0x38)) = 1.0f;
  *a3 = 0xFF;
  D_0048D141[arg1 * 4] = 0xFF;
  D_0048D142[arg1 * 4] = 0xFF;
  a1 = D_0048D143 + (arg1 * 4);
  if ((*a1) > 0xD0)
  {
    *a1 = 0xFF;
  }
  else
  {
    *a1 += 0x20;
  }
  *((f32 *) (((s8 *) arg0) + 0x3C)) = *((f32 *) (D_0048D140 + (arg1 * 4)));
  if ((*((s32 *) (((s8 *) t1) + 4))) != 0)
  {
    Ui_DrawElem_1_00182C10__as_Ui_DrawElemAt_0_001832D0(arg0, &s);
  }
  else
  {
    *((s32 *) (D_0048D140 + (arg1 * 4))) = 0;
  }
}

/* Ui_LoadItemImageSmall_3_001833E0 */
s32 D_001F2740[0xc] = { -0x1 };
static inline O_Ui_LoadItemImageSmall_3_001833E0 **getp(s32 i) { return &D_0048D110[i]; }

void Ui_LoadItemImageSmall_3_001833E0(s32 arg0, s32 arg1) {
    Ent *e; O_Ui_LoadItemImageSmall_3_001833E0 *o; s32 x; s32 *cur; O_Ui_LoadItemImageSmall_3_001833E0 **pp;
    e = &D_0048D170__as_Ui_LoadItemImageSmall_3_001833E0[arg1];
    if (arg0 <= 0) {
        pp = getp(arg1);
        if (*pp != NULL && (*pp)->b2) {
            if (e->p != NULL) {
                Tex_Release_1_00177570(e->p);
                e->p = NULL;
                D_001F2740[arg1] = -1;
                *pp = NULL;
            }
        }
        return;
    }
    cur = &D_001F2740[arg1];
    if (arg0 != *cur) {
        pp = getp(arg1);
        o = *pp;
        if (o != NULL && o->b1) return;
        *cur = arg0;
        if (o != NULL && o->b2) {
            if (e->p != NULL) {
                Tex_Release_1_00177570(e->p);
                e->p = NULL;
            }
        }
        {
            Buf_Ui_LoadItemImageSmall_3_001833E0 s = {0};
            sprintf(&s, D_001FC9C0, *cur);
            *pp = ImageLoader_Request_1_001E1570(&s, arg1);
        }
        e->f[0] = 4.0f;
        e->f[1] = 4.0f;
        e->f[2] = 50.0f;
        e->f[3] = 50.0f;
        e->f[4] = 0.0f;
        e->f[5] = 0.0f;
        e->f[6] = 64.0f;
        e->f[7] = 64.0f;
    }
    pp = getp(arg1);
    o = *pp;
    if (o != NULL && !o->b1 && !o->b2 && o->b0) {
        u8 buf2[16];
        sprintf(buf2, D_001FC9D8, *cur);
        if ((x = (*pp)->first) != 0) {
            e->p = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(buf2), x);
            (*(O_Ui_LoadItemImageSmall_3_001833E0 **)((s8 *)D_0048D110 + arg1 * 4))->b2 = 1;
        }
    }
}

/* Ui_DrawWindow_0_00183650 */

void Ui_DrawWindow_0_00183650(s8 *arg0) {
    Buf_Ui_DrawWindow_0_00183650 s __attribute__((aligned(16))) = {0};
    if (D_0048D0E4[0] != 0) {
        if (D_002020A8.a > 0xD0) {
            D_002020A8.a = 0xFF;
        } else {
            D_002020A8.a += 0x20;
        }
        s.a = 1;
        s.b = D_0048D0E0;
        *(s32 *)(arg0 + 0x34) = 0x3F800000;
        *(s32 *)(arg0 + 0x38) = 0x3F800000;
        D_002020A8.r = 0xFF;
        D_002020A8.g = 0xFF;
        D_002020A8.b = 0xFF;
        arg0[0x3C] = D_002020A8.r;
        arg0[0x3D] = D_002020A8.g;
        arg0[0x3E] = D_002020A8.b;
        arg0[0x3F] = (D_002020A8.a * (u8)arg0[0x3F]) / 128;
        Ui_DrawElem_1_00182C10__as_Ui_DrawWindow_0_00183650(arg0, &s);
        return;
    }
    *(u32 *)&D_002020A8 = 0;
}

/* Ui_LoadMapSheet_3_00183750 */

void Ui_LoadMapSheet_3_00183750(s32 arg0) {
    s32 temp_s0;
    u8 temp_a0;

    if (arg0 <= 0) {
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[0] != NULL)) {
            Tex_Release_1_00177570(D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[0]);
            D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[0] = NULL;
            D_00201CE8 = -1;
        }
        return;
    }
    if (D_00201CE8 != arg0) {
        if (D_002020AC != NULL && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3E) >> 0x3F) != 0)) {
            return;
        }
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[0] != NULL)) {
            Tex_Release_1_00177570(D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[0]);
            D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[0] = NULL;
        }
        D_00201CE8 = arg0;
        D_00201CE0 = -1;
        D_00201CDC = -1;
        D_00201CE4 = -1;
        {
            Buf_Ui_LoadMapSheet_3_00183750 s = {0};
        sprintf__as_Ui_LoadMapSheet_3_00183750(s.b, D_001FC9F0, D_00201CE8);
            D_002020AC = ImageLoader_Request_1_001E1570__as_Ui_LoadMapSheet_3_00183750(s.b, 0xA);
            D_0048D0F0[0] = 0;
            D_0048D0F4[0] = 0;
            D_002020A8__as_Ui_LoadMapSheet_3_00183750 = 0;
            D_0048D0F8[0] = 0x43800000;
            D_0048D0FC[0] = 0x43800000;
            D_0048D100[0] = 0;
            D_0048D104[0] = 0;
            D_0048D108[0] = 0x43800000;
            D_0048D10C[0] = 0x43800000;
        }
    }
    {
        u8 name[16];
    if (D_002020AC != NULL) {
            temp_a0 = M2C_FIELD(D_002020AC, u8 *, 8);
            if ((((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0) && (((u64) ((s64) temp_a0 << 0x3D) >> 0x3F) == 0) && (temp_a0 & 1)) {
                sprintf__as_Ui_LoadMapSheet_3_00183750(name, D_001FCA08, D_00201CE8);
                temp_s0 = M2C_FIELD(D_002020AC, s32 *, 0);
                if (temp_s0 != 0) {
                    D_0048D0E4__as_Ui_LoadMapSheet_3_00183750[0] = (s8 *)Tex_Find_1_00177AF0__as_Ui_LoadMapSheet_3_00183750(Tex_HashName_2_00177F80__as_Ui_LoadMapSheet_3_00183750(name), temp_s0);
                    ((BF_Ui_DrawGauge_0_00182EF0 *)(D_002020AC + 8))->c = 1;
                }
            }
        }
    }
}

/* Ui_LoadAreaImage_3_00183970 */

void Ui_LoadAreaImage_3_00183970(s32 arg0) {
    s32 temp_s0;
    u8 temp_a0;

    if (arg0 <= 0) {
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[0] != NULL)) {
            Tex_Release_1_00177570(D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[0]);
            D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[0] = NULL;
            D_00201CE4 = -1;
        }
        return;
    }
    if (D_00201CE4 != arg0) {
        if (D_002020AC != NULL && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3E) >> 0x3F) != 0)) {
            return;
        }
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[0] != NULL)) {
            Tex_Release_1_00177570(D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[0]);
            D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[0] = NULL;
        }
        D_00201CE4 = arg0;
        D_00201CE0 = -1;
        D_00201CDC = -1;
        D_00201CE8 = -1;
        {
            Buf_Ui_LoadMapSheet_3_00183750 s = {0};
        sprintf__as_Ui_LoadAreaImage_3_00183970(s.b, D_001FCA10, D_00201CE4);
            D_002020AC = ImageLoader_Request_1_001E1570__as_Ui_LoadAreaImage_3_00183970(s.b, 0xA);
            D_0048D0F0[0] = 0;
            D_0048D0F4[0] = 0;
            D_002020A8__as_Ui_LoadAreaImage_3_00183970 = 0;
            D_0048D0F8[0] = 0x43000000;
            D_0048D0FC[0] = 0x43000000;
            D_0048D100[0] = 0;
            D_0048D104[0] = 0;
            D_0048D108[0] = 0x43000000;
            D_0048D10C[0] = 0x43000000;
        }
    }
    {
        u8 name[16];
    if (D_002020AC != NULL) {
            temp_a0 = M2C_FIELD(D_002020AC, u8 *, 8);
            if ((((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0) && (((u64) ((s64) temp_a0 << 0x3D) >> 0x3F) == 0) && (temp_a0 & 1)) {
                sprintf__as_Ui_LoadAreaImage_3_00183970(name, D_001FCA20, D_00201CE4);
                temp_s0 = M2C_FIELD(D_002020AC, s32 *, 0);
                if (temp_s0 != 0) {
                    D_0048D0E4__as_Ui_LoadAreaImage_3_00183970[0] = (s8 *)Tex_Find_1_00177AF0__as_Ui_LoadAreaImage_3_00183970(Tex_HashName_2_00177F80__as_Ui_LoadAreaImage_3_00183970(name), temp_s0);
                    ((BF_Ui_DrawGauge_0_00182EF0 *)(D_002020AC + 8))->c = 1;
                }
            }
        }
    }
}

/* Ui_LoadCharImage_3_00183B90 */

void Ui_LoadCharImage_3_00183B90(s32 id) {


    s32 r;
    if (id == -1 || id == 0) {
        if (D_002020AC__as_Ui_LoadCharImage_3_00183B90 && D_002020AC__as_Ui_LoadCharImage_3_00183B90->f8.f.b2 && D_0048D0E4[0]) {
            Tex_Release_1_00177570__as_Ui_LoadCharImage_3_00183B90(D_0048D0E4[0]);
            D_0048D0E4[0] = 0;
            D_00201CE0 = -1;
        }
        return;
    }
    if (D_00201CE0 != id) {
        if (D_002020AC__as_Ui_LoadCharImage_3_00183B90 && D_002020AC__as_Ui_LoadCharImage_3_00183B90->f8.f.b1) return;
        if (D_002020AC__as_Ui_LoadCharImage_3_00183B90 && D_002020AC__as_Ui_LoadCharImage_3_00183B90->f8.f.b2 && D_0048D0E4[0]) {
            Tex_Release_1_00177570__as_Ui_LoadCharImage_3_00183B90(D_0048D0E4[0]);
            D_0048D0E4[0] = 0;
        }
        D_00201CE0 = id;
        D_00201CE4 = -1;
        D_00201CDC = -1;
        D_00201CE8 = -1;
        {
        s8 buf[0x100] = {0};
        sprintf(buf, D_001FCA30, D_00201CE0);
        D_002020AC__as_Ui_LoadCharImage_3_00183B90 = ImageLoader_Request_1_001E1570__as_Ui_LoadCharImage_3_00183B90(buf, 10);
        D_0048D0F0__as_Ui_LoadCharImage_3_00183B90[0] = 0.0f;
        D_0048D0F4__as_Ui_LoadCharImage_3_00183B90[0] = 0.0f;
        D_002020A8__as_Ui_LoadCharImage_3_00183B90 = 0;
        D_0048D0F8__as_Ui_LoadCharImage_3_00183B90[0] = 128.0f;
        D_0048D0FC__as_Ui_LoadCharImage_3_00183B90[0] = 128.0f;
        D_0048D100__as_Ui_LoadCharImage_3_00183B90[0] = 0.0f;
        D_0048D104__as_Ui_LoadCharImage_3_00183B90[0] = 0.0f;
        D_0048D108__as_Ui_LoadCharImage_3_00183B90[0] = 128.0f;
        D_0048D10C__as_Ui_LoadCharImage_3_00183B90[0] = 128.0f;
        }
    }
    if (D_002020AC__as_Ui_LoadCharImage_3_00183B90 && !D_002020AC__as_Ui_LoadCharImage_3_00183B90->f8.f.b1 && !D_002020AC__as_Ui_LoadCharImage_3_00183B90->f8.f.b2 && D_002020AC__as_Ui_LoadCharImage_3_00183B90->f8.f.b0) {
        s8 name[16];
        sprintf(name, D_001FCA48, D_00201CE0);
        r = D_002020AC__as_Ui_LoadCharImage_3_00183B90->x0;
        if (r) {
            D_0048D0E4[0] = Tex_Find_1_00177AF0__as_Ui_LoadCharImage_3_00183B90(Tex_HashName_2_00177F80(name), r);
            D_002020AC__as_Ui_LoadCharImage_3_00183B90->f8.f.b2 = 1;
        }
    }
}

/* Ui_LoadItemImage_3_00183DC0 */

void Ui_LoadItemImage_3_00183DC0(s32 arg0) {
    s32 temp_s0;
    u8 temp_a0;

    if (arg0 == -1 || arg0 == 0) {
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[0] != NULL)) {
            Tex_Release_1_00177570(D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[0]);
            D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[0] = NULL;
            D_00201CDC = -1;
        }
        return;
    }
    if (D_00201CDC != arg0) {
        if (D_002020AC != NULL && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3E) >> 0x3F) != 0)) {
            return;
        }
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[0] != NULL)) {
            Tex_Release_1_00177570(D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[0]);
            D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[0] = NULL;
        }
        D_00201CDC = arg0;
        D_00201CE4 = -1;
        D_00201CE0 = -1;
        D_00201CE8 = -1;
        {
            Buf_Ui_LoadMapSheet_3_00183750 s = {0};
        sprintf__as_Ui_LoadItemImage_3_00183DC0(s.b, D_001FCA60, D_00201CDC);
            D_002020AC = ImageLoader_Request_1_001E1570__as_Ui_LoadItemImage_3_00183DC0(s.b, 0xA);
            D_0048D0F0[0] = 0;
            D_0048D0F4[0] = 0;
            D_002020A8__as_Ui_LoadItemImage_3_00183DC0 = 0;
            D_0048D0F8[0] = 0x43000000;
            D_0048D0FC[0] = 0x43000000;
            D_0048D100[0] = 0;
            D_0048D104[0] = 0;
            D_0048D108[0] = 0x43000000;
            D_0048D10C[0] = 0x43000000;
        }
    }
    {
        u8 name[16];
    if (D_002020AC != NULL) {
            temp_a0 = M2C_FIELD(D_002020AC, u8 *, 8);
            if ((((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0) && (((u64) ((s64) temp_a0 << 0x3D) >> 0x3F) == 0) && (temp_a0 & 1)) {
                sprintf__as_Ui_LoadItemImage_3_00183DC0(name, D_001FCA78, D_00201CDC);
                temp_s0 = M2C_FIELD(D_002020AC, s32 *, 0);
                if (temp_s0 != 0) {
                    D_0048D0E4__as_Ui_LoadItemImage_3_00183DC0[0] = (s8 *)Tex_Find_1_00177AF0__as_Ui_LoadItemImage_3_00183DC0(Tex_HashName_2_00177F80__as_Ui_LoadItemImage_3_00183DC0(name), temp_s0);
                    ((BF_Ui_DrawGauge_0_00182EF0 *)(D_002020AC + 8))->c = 1;
                }
            }
        }
    }
}

/* Ui_IsImageLoading_0_00183FF0 */
s32 Ui_IsImageLoading_0_00183FF0(void) {
    if (D_002020AC__as_Ui_IsImageLoading_0_00183FF0 == NULL) return 0;
    goto test;
one:
    return 1;
test:
    if (D_002020AC__as_Ui_IsImageLoading_0_00183FF0->f8.f.b1) goto one;
    D_00201CDC = -1; D_00201CE0 = -1; D_00201CE4 = -1; D_00201CE8 = -1;
    return 0;
}

/* Menu_DrawRingA_0_00184040 */

void Menu_DrawRingA_0_00184040(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;

    l = MenuLayout_Get_1_00189050(2)->l;
    t = MenuLayout_GetSub_1_00189020__as_Menu_DrawRingA_0_00184040(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2_Ui_DrawGauge_0_00182EF0 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 735.0f;
        c.z = 129.0f;
        fx = o.x; fz = o.z; ox = fx - 735.0f; oz = fz - 129.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = atanf(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 735.0f + d * sinf(r);
        o.z = 129.0f + d * cosf(r);
        }
        Ui_DrawList_1_001829B0(&o, t + (l->e[i].idx << 3), MenuProc_DrawItemStats_0_00184280, a0);
    }
}

/* text_00184280 */
#ifdef NONMATCHING
/* best-effort C: menu_proc_draw_item_stats.c */
#else
INCLUDE_ASM(MenuProc_DrawItemStats_0_00184280);
#endif

/* Item_GetDurability_0_001848A0 */
#define D_001FCB08 D_001FCB08__as_Item_GetDurability_0_001848A0
extern char D_001FCB08__as_Item_GetDurability_0_001848A0[];
#define D_001FCB18 D_001FCB18__as_Item_GetDurability_0_001848A0
extern char D_001FCB18__as_Item_GetDurability_0_001848A0[];
#define D_001FCB28 D_001FCB28__as_Item_GetDurability_0_001848A0
extern char D_001FCB28__as_Item_GetDurability_0_001848A0[];
#define D_001FCB30 D_001FCB30__as_Item_GetDurability_0_001848A0
extern char D_001FCB30__as_Item_GetDurability_0_001848A0[];
#define MenuLayout_Get_1_00189050 MenuLayout_Get_1_00189050__as_Item_GetDurability_0_001848A0
R_Menu_DrawRingB_0_00184960* MenuLayout_Get_1_00189050__as_Item_GetDurability_0_001848A0(s32);
#define Ui_DrawElem_1_00182C10 Ui_DrawElem_1_00182C10__as_Item_GetDurability_0_001848A0
void Ui_DrawElem_1_00182C10__as_Item_GetDurability_0_001848A0(Elem_Menu_DrawFrame_0_00185390 *, s32);
#define sprintf sprintf__as_Item_GetDurability_0_001848A0
void sprintf__as_Item_GetDurability_0_001848A0(char *, char *, ...);

/* Item_GetDurability_0_001848A0 */
s32 Item_GetDurability_0_001848A0(s32 a) { s32 r = 0; E *e = Item_GetTable_1_001AFC90() + a; if (e == NULL || a == -1) return -1; if (e->xA == 1) { switch (e->x20) { case 5: case 6: r = 0; break; default: r = e->x3C; break; } } else if (e->xA == 2) { r = e->x3C; } return r; }

/* Menu_DrawRingB_0_00184960 */

void Menu_DrawRingB_0_00184960(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;
    f32 v;

    l = MenuLayout_Get_1_00189050(2)->l;
    t = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2_Ui_DrawGauge_0_00182EF0 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 108.0f;
        c.z = 72.0f;
        fx = o.x; fz = o.z; ox = fx - 108.0f; oz = fz - 72.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = atanf(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 108.0f + d * sinf(r);
        o.z = 72.0f + d * cosf(r);
        }
        Ui_DrawList_1_001829B0(&o, t + (l->e[i].idx << 3), MenuProc_DrawScrolled_0_00184CF0__as_Menu_DrawRingB_0_00184960, a0);
    }
    Ui_BeginSprites_1_00181420();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x48);
    GsPkt_Flush_1_001544C0();
    MenuLayout_GetSub_1_00189020(0);
    v = D_0020208C;
    D_00202088 += v;
    D_0020208C = v - (v - (v - 1.0f) / 10.0f);
    D_00202090 = Approachf_3_00187770(D_00202090, D_002020BC, 10.0f);
    D_00202094 = Approachf_3_00187770(D_00202094, D_002020B8, 10.0f);
    if (!(fabsf(D_002020BC - D_00202090) <= 5.0f)) {
        D_0020208C = 0.0f;
    }
    cosf(D_00202088);
    sinf(D_00202088);
    D_00202098 = Approachf_3_00187770(D_00202098, D_002020B4, 10.0f);
    D_0020209C = Approachf_3_00187770(D_0020209C, D_002020B0, 10.0f);
    cosf(3.14f + D_00202088);
    sinf(3.14f + D_00202088);
    Ui_BeginSprites_1_00181420();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x44);
    GsPkt_Flush_1_001544C0();
}

/* MenuProc_DrawScrolled_0_00184CF0 */
void MenuProc_DrawScrolled_0_00184CF0(s8 *a0, s32 a1, u32 n) {
    if (n >= 500) {
        D_0048D060.x2C = *(f32 *)(a0 + 0x38);
        D_0048D060.x30 = *(f32 *)(a0 + 0x3C);
        D_0048D060.x14 = 1.0f;
        D_0048D060.x18 = 1.0f;
        D_0048D060.x3C = 0x80FFFFFF;
        switch (n - 500) {
        case 0: case 1: case 2: case 3: case 4: case 5: break;
        case 6: case 7: case 8: case 9:
            D_0048D060.x2C = 3.0f + *(f32 *)(a0 + 0x38);
            D_0048D060.x30 = 3.0f + *(f32 *)(a0 + 0x3C);
            break;
        }
        if (n > 1000) Ui_DrawElemAt_0_001832D0(&D_0048D060, n - 1500, 1);
        else Ui_DrawElemAt_0_001832D0(&D_0048D060, n - 500, 0);
    }
}

/* Menu_DrawRingC_0_00184DF0 */

void Menu_DrawRingC_0_00184DF0(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;

    l = MenuLayout_Get_1_00189050__as_Menu_DrawRingC_0_00184DF0(2)->l;
    t = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2_Ui_DrawGauge_0_00182EF0 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 108.0f;
        c.z = 72.0f;
        fx = o.x; fz = o.z; ox = fx - 108.0f; oz = fz - 72.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = atanf(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 108.0f + d * sinf(r);
        o.z = 72.0f + d * cosf(r);
        }
        Ui_DrawList_1_001829B0(&o, t + (l->e[i].idx << 3), MenuProc_DrawGauge_0_00185030__as_Menu_DrawRingC_0_00184DF0, a0);
    }
}

/* MenuProc_DrawGauge_0_00185030 */
static inline void glow(O_Item_GetDurability_0_001848A0 *o, R_MenuProc_DrawGauge_0_00185030 *r, S_Ui_DrawGauge_0_00182EF0 *buf, u32 mode) {
    s32 k;
    buf->x = o->x38;
    buf->y = o->x3C;
    buf->m[3] = 1.0f;
    buf->m[0] = 1.0f;
    k = 96.0f + fabsf(128.0f * sinf(0.05f * D_002020D4));
    o->x2C = o->x2C * k / 128;
    o->x2D = o->x2D * k / 128;
    o->x2E = o->x2E * k / 128;
    Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, buf, mode);
}

void MenuProc_DrawGauge_0_00185030(O_Item_GetDurability_0_001848A0 *o, s32 a1, u32 mode, u32 a3) {
    S_Ui_DrawGauge_0_00182EF0 buf __attribute__((aligned(16)));
    R_MenuProc_DrawGauge_0_00185030 *r;
    s32 n;

    buf = D_001F2700;
    D_00202084 += 0.01f;
    if (mode < 2000) {
        buf.x = o->x30;
        buf.y = o->x34;
        if (mode == 0) {
            o->x2C = 0x40;
            o->x2D = 0x40;
            o->x2E = 0x40;
        }
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
    }
    if (a3 == mode - 1500) {
        D_002020B4 = o->x38;
        D_002020B0 = o->x3C;
        r = MenuLayout_GetSub_1_00189020__as_MenuProc_DrawGauge_0_00185030(0)->x7C;
        glow(o, r, &buf, mode);
    }
    if (a3 == mode - 500) {
        D_002020BC = o->x38;
        D_002020B8 = o->x3C;
        if (a3 != 4) {
            D_002020B4 = o->x38;
            D_002020B0 = o->x3C;
        }
        n = 0;
        switch (a3) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            D_002020BC -= 4.0f;
            D_002020B8 -= 4.0f;
            D_002020B4 -= 4.0f;
            D_002020B0 -= 4.0f;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            n = 1;
            break;
        }
        r = MenuLayout_GetSub_1_00189020__as_MenuProc_DrawGauge_0_00185030(0)->x7C + n;
        glow(o, r, &buf, mode);
    }
}

/* Menu_DrawFrame_0_00185390 */

void Menu_DrawFrame_0_00185390(s32 a0, s32 a1, s32 a2, f32 f) {
    Elem_Menu_DrawFrame_0_00185390 el;
    V v;
    u32 i;
    List_Menu_DrawFrame_0_00185390 *list;
    s32 base;

    list = MenuLayout_Get_1_00189050__as_Menu_DrawFrame_0_00185390(0)->list;
    base = MenuLayout_GetSub_1_00189020__as_Menu_DrawFrame_0_00185390(0);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        el.x2C -= 40.0f * f;
        Ui_DrawElem_1_00182C10(&el, base + list->e[i].idx * 8);
    }
    v = D_001F26F0[0];
    v.f[0] -= 40.0f * f;
    v.f[2] -= 40.0f * f;
    Ui_DrawCursorB_0_00183090(&v, a0, a1, a2);
}

/* Menu_DrawRingD_0_00185510 */
static inline f32 d2d_Menu_DrawRingD_0_00185510(f32 x, f32 y, f32 cx, f32 cy) { f32 u = x - cx; f32 v = y - cy; return sqrtf(u * u + v * v); }

void Menu_DrawRingD_0_00185510(s32 a0, f32 f) {
    Elem_Menu_DrawRingD_0_00185510 el;
    u32 i;
    List_Menu_DrawRingD_0_00185510 *list;
    s32 base;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 ang;
    f32 px;
    f32 py;

    list = MenuLayout_Get_1_00189050__as_Menu_DrawRingD_0_00185510(0)->list;
    base = MenuLayout_GetSub_1_00189020__as_Menu_DrawRingD_0_00185510(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        {
        V2_Menu_DrawRingD_0_00185510 c = {0};
        c.x = -70.0f;
        c.y = 276.0f;
        px = el.x2C;
        py = el.x30;
        dist = d2d_Menu_DrawRingD_0_00185510(px, py, -70.0f, 276.0f);
        dx = px - c.x;
        dy = py - c.y;
        if (dx == 0.0f) {
            ang = 0.0f;
        } else {
            ang = atanf(dx / dy);
        }
        if (dy < 0.0f) {
            ang += 3.141592f;
        }
        dy = ang + f;
        el.x2C = -70.0f + dist * sinf(dy);
        el.x30 = 276.0f + dist * cosf(dy);
        }
        Ui_DrawList_1_001829B0__as_Menu_DrawRingD_0_00185510(&el, base + list->e[i].idx * 8, MenuProc_DrawHpMp_1_00185740, a0);
    }
}

/* MenuProc_DrawHpMp_1_00185740 */
static inline void draw_Item_GetDurability_0_001848A0(char *s, f32 x, f32 y, Col_Ui_DrawWindow_0_00183650 *c) {
    T_Item_GetDurability_0_001848A0 t;
    if (s) {
        TextParam_Init_1_00187A90(&t, s, strlen(s));
        t.f8.a = 0;
        t.x24 = 1.0f;
        t.x20 = 0.9f;
        t.x14 = 4096.0f;
        t.x = x;
        t.y = y;
        Text_Render_2_00188010(&t, *c);
    }
}

void MenuProc_DrawHpMp_1_00185740(O_Item_GetDurability_0_001848A0 *o, s32 a1, u32 mode, s16 *a3) {
    Col_Ui_DrawWindow_0_00183650 c8;
    Col_Ui_DrawWindow_0_00183650 cb;
    Col_Ui_DrawWindow_0_00183650 ca;
    Col_Ui_DrawWindow_0_00183650 c9;
    f32 x;
    f32 y;
    s32 v;
    if (mode < 200) {
        S_Ui_DrawGauge_0_00182EF0 buf __attribute__((aligned(16)));
        buf = D_001F26D0;
        buf.x = o->x30;
        buf.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 200:
        *(u32 *)&c8 = 0x80808080;
        sprintf(D_0048CE40, D_001FCB08, a3[2], a3[0]);
        *(f32 *)((s32)o + 0x38) += 4.0f;
        draw_Item_GetDurability_0_001848A0(D_0048CE40, o->x38, o->x3C, &c8);
        break;
    case 201:
        *(u32 *)&c9 = 0x80808080;
        sprintf(D_0048CE40, D_001FCB18, a3[3], a3[1]);
        draw_Item_GetDurability_0_001848A0(D_0048CE40, o->x38, o->x3C, &c9);
        break;
    case 202:
        v = D_0020207C;
        if (v == 0) break;
        if (v < 0) {
            *(u32 *)&ca = 0x80404080;
            sprintf(D_0048CE40, D_001FCB28, v);
        } else {
            *(u32 *)&ca = 0x80804040;
            sprintf(D_0048CE40, D_001FCB30, v);
        }
        x = o->x38 + 10.0f;
        y = o->x3C;
        draw_Item_GetDurability_0_001848A0(D_0048CE40, x, y, &ca);
        break;
    case 203:
        v = D_00202080;
        if (v == 0) break;
        if (v < 0) {
            *(u32 *)&cb = 0x80404080;
            sprintf(D_0048CE40, D_001FCB28, v);
        } else {
            *(u32 *)&cb = 0x80804040;
            sprintf(D_0048CE40, D_001FCB30, v);
        }
        x = o->x38 + 10.0f;
        y = o->x3C;
        draw_Item_GetDurability_0_001848A0(D_0048CE40, x, y, &cb);
        break;
    }
}

/* Menu_SetOffset_0_00185B30 */
void Menu_SetOffset_0_00185B30(s32 arg0, s32 arg1) {
    D_0020207C = arg0;
    D_00202080 = arg1;
}

/* Menu_DrawRingE_0_00185B40 */
static inline f32 d2d_Menu_DrawRingE_0_00185B40(f32 x, f32 y, f32 cx, f32 cy) { f32 u = x - cx; f32 v = y - cy; return sqrtf(u * u + v * v); }

void Menu_DrawRingE_0_00185B40(s32 a0, f32 f) {
    Elem_Menu_DrawRingD_0_00185510 el;
    u32 i;
    List_Menu_DrawRingD_0_00185510 *list;
    s32 base;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 ang;
    f32 px;
    f32 py;

    list = MenuLayout_Get_1_00189050__as_Menu_DrawRingE_0_00185B40(0)->list;
    base = MenuLayout_GetSub_1_00189020__as_Menu_DrawRingE_0_00185B40(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        {
        V2_Menu_DrawRingD_0_00185510 c = {0};
        c.x = -70.0f;
        c.y = 276.0f;
        px = el.x2C;
        py = el.x30;
        dist = d2d_Menu_DrawRingE_0_00185B40(px, py, -70.0f, 276.0f);
        dx = px - c.x;
        dy = py - c.y;
        if (dx == 0.0f) {
            ang = 0.0f;
        } else {
            ang = atanf(dx / dy);
        }
        if (dy < 0.0f) {
            ang += 3.141592f;
        }
        dy = ang + f;
        el.x2C = -70.0f + dist * sinf(dy);
        el.x30 = 276.0f + dist * cosf(dy);
        }
        Ui_DrawList_1_001829B0__as_Menu_DrawRingE_0_00185B40(&el, base + list->e[i].idx * 8, MenuProc_DrawWeight_0_00185D70, a0);
    }
}
#undef MenuLayout_Get_1_00189050
#undef Ui_DrawElem_1_00182C10
#undef sprintf
#undef D_001FCB08
#undef D_001FCB18
#undef D_001FCB28
#undef D_001FCB30

/* text_00185D70 */
#ifdef NONMATCHING
/* best-effort C: menu_proc_draw_weight.c */
#else
INCLUDE_ASM(MenuProc_DrawWeight_0_00185D70);
#endif

/* rodata_001FCB08 */
/* rodata_001FCB08: the game's data at 0x001FCB08..., one object per label. */
/* used by: MenuProc_DrawHpMp_1_00185740, text_00185740.s */
#pragma explicit_zero_data on

const char D_001FCB08[0x10] __attribute__((aligned(8))) = "HP %4d/%4d\000\000\000\000\000\000";
const char D_001FCB18[0x10] __attribute__((aligned(8))) = "MP %4d/%4d\000\000\000\000\000\000";
const char D_001FCB28[0x8] = { 0x20, 0x25, 0x64, 0, 0, 0, 0, 0 };
const char D_001FCB30[0x8] = { 0x20, 0x2b, 0x25, 0x64, 0, 0, 0, 0 };
const char D_001FCB38[0x7] = "/%3.1f\000";
static const u8 pad_001FCB3F[0x1] __attribute__((aligned(1))) = { 0 };
#pragma explicit_zero_data reset

/* func_00186440_ */
#define MenuLayout_Get_1_00189050 MenuLayout_Get_1_00189050__as_func_00186440_
Ctx* MenuLayout_Get_1_00189050__as_func_00186440_(s32);
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_func_00186440_
s32 MenuLayout_GetSub_1_00189020__as_func_00186440_(s32);
#define Ui_DrawList_1_001829B0 Ui_DrawList_1_001829B0__as_func_00186440_
void Ui_DrawList_1_001829B0__as_func_00186440_(Elem *, s32, void (*)(), s32);
#define Text_Render_2_00188010 Text_Render_2_00188010__as_func_00186440_
s32 Text_Render_2_00188010__as_func_00186440_(void *, C);

/* Menu_DrawStatRing_0_00186440 */
static inline f32 d2d(f32 x, f32 y, f32 cx, f32 cy) { f32 u = x - cx; f32 v = y - cy; return sqrtf(u * u + v * v); }

void Menu_DrawStatRing_0_00186440(s32 a0, s32 a1, s32 a2, s32 a3, f32 f) {
    Elem el;
    u32 i;
    List *list;
    s32 base;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 ang;
    f32 px;
    f32 py;

    list = MenuLayout_Get_1_00189050(0)->list;
    base = MenuLayout_GetSub_1_00189020(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        {
        V2_Menu_DrawRingD_0_00185510 c = {0};
        c.x = -70.0f;
        c.y = 276.0f;
        px = el.x2C;
        py = el.x30;
        dist = d2d(px, py, -70.0f, 276.0f);
        dx = px - c.x;
        dy = py - c.y;
        if (dx == 0.0f) {
            ang = 0.0f;
        } else {
            ang = atanf(dx / dy);
        }
        if (dy < 0.0f) {
            ang += 3.141592f;
        }
        dy = ang + f;
        el.x2C = -70.0f + dist * sinf(dy);
        el.x30 = 276.0f + dist * cosf(dy);
        }
        Ui_DrawList_1_001829B0(&el, base + list->e[i].idx * 8, MenuProc_DrawStatValue_0_00186990, Menu_CalcStatBar_0_001866B0__as_Menu_DrawStatRing_0_00186440(el.x4, a0, a1, a2, a3));
    }
}

/* Menu_CalcStatBar_0_001866B0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
static inline u32 get(u16 *p, s32 i) { return p ? p[i] : 0; }
static inline u32 mk(u32 lo, u32 hi) { return (u16)lo | ((u16)hi << 16); }

u32 Menu_CalcStatBar_0_001866B0(s32 a0, u16 *a1, u16 *a2, u16 *a3, u16 *t0) {
    u32 t;
    u16 lo, hi;
    switch (a0) {
    case 3001:
        return mk(get(a1, 0), get(a3, 0));
    case 3002:
        return mk(get(a1, 1), get(a3, 1));
    case 3003:
        return mk(get(a1, 2), get(a3, 2));
    case 3004:
        return mk(get(a1, 3), get(a3, 3));
    case 3005:
        return mk(get(a1, 4), get(a3, 4));
    case 3006:
        return mk(get(a1, 5), get(a3, 5));
    case 3007:
        return mk(get(a1, 6), get(a3, 6));
    case 3008:
        return mk(get(a1, 7), get(a3, 7));
    case 3011:
        return mk(get(a2, 0), get(t0, 0));
    case 3012:
        return mk(get(a2, 1), get(t0, 1));
    case 3013:
        return mk(get(a2, 2), get(t0, 2));
    case 3014:
        return mk(get(a2, 3), get(t0, 3));
    case 3015:
        return mk(get(a2, 4), get(t0, 4));
    case 3016:
        return mk(get(a2, 5), get(t0, 5));
    case 3009: case 3010:
    default:
        return 0;
    }
}

/* MenuProc_DrawStatValue_0_00186990 */
static inline void draw_Menu_DrawStatRing_0_00186440(f32 x, f32 y, s8 *str, C col, f32 sc) {
    T_Menu_DrawStatRing_0_00186440 t;
    if (str == 0) {
        return;
    }
    TextParam_Init_1_00187A90(&t, str, strlen(str));
    t.x8.a = 0;
    t.x24 = 1.0f;
    t.x20 = sc;
    t.x14 = 4096.0f;
    t.x0 = x;
    t.x4 = y;
    Text_Render_2_00188010(&t, col);
}

void MenuProc_DrawStatValue_0_00186990(O_Menu_DrawStatRing_0_00186440 *o, s32 id, u32 mode, u32 p) {
    S_Ui_DrawGauge_0_00182EF0 buf __attribute__((aligned(16)));
    C col;
    s32 lo;
    s32 hi;
    s32 idx;
    s32 *cnt;

    buf = D_001F2630;
    lo = (s16)(p & 0xFFFF);
    hi = (s16)((p >> 16) & 0xFFFF);
    idx = id - 0xBB9;
    if (mode < 100) {
        S_Ui_DrawGauge_0_00182EF0 b2 __attribute__((aligned(16)));
        b2 = D_001F2650;
        b2.x = o->x30;
        b2.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, o->x2C, &b2, mode);
        return;
    }
    switch (mode) {
    case 100: {
        S_Ui_DrawGauge_0_00182EF0 b3 __attribute__((aligned(16)));
        R_MenuProc_DrawGauge_0_00185030 *r;
        b3 = D_001F2670;
        r = &MenuLayout_GetSub_1_00189020__as_MenuProc_DrawStatValue_0_00186990(0)->x54[id - 0xBB9];
        col.w = (0x30808080);
        b3.x = o->x38;
        b3.y = o->x3C;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &col, &b3, mode);
        break;
    }
    case 101: {
        R_MenuProc_DrawGauge_0_00185030 *r;
        r = &MenuLayout_GetSub_1_00189020__as_MenuProc_DrawStatValue_0_00186990(0)->x5C[id - 0xBB9];
        col.w = 0x30808080;
        buf.m[0] = 1.1f;
        buf.m[3] = 1.0f;
        buf.x = o->x38 - 5.0f;
        buf.y = o->x3C - 4.0f;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &col, &buf, mode);
        break;
    }
    case 102: {
        s32 v = (s16)lo;
        if (v != D_0048CF40[idx]) {
            D_0048CFC0[idx] = 0;
            D_0048CF40[idx] = v;
        }
        if (D_0048CFC0[idx] < 0x80) {
            D_0048CFC0[idx] += 0x10;
        }
        col.w = 0x80808080;
        col.c.a = D_0048CFC0[idx];
        if (v >= 0) {
            sprintf(D_0048CE40, D_001FCA80, v);
        } else {
            sprintf(D_0048CE40, D_001FCA88, v);
        }
        draw_Menu_DrawStatRing_0_00186440(o->x38, o->x3C, D_0048CE40, col, 0.9f);
        break;
    }
    case 103: {
        s32 v = (s16)hi;
        if (v != D_0048CF80[idx]) {
            D_0048D000[idx] = 0;
            D_0048CF80[idx] = v;
        }
        cnt = &D_0048D000[idx];
        if (*cnt < 0x80) {
            *cnt += 0x10;
        }
        if (v < 0) {
            col.w = 0x80404080;
            sprintf(D_0048CE40, D_001FCB80, v);
        } else if (v > 0) {
            col.w = 0x80804040;
            sprintf(D_0048CE40, D_001FCB88, v);
        } else {
            col.w = 0x80808080;
            sprintf(D_0048CE40, D_001FCB90, v);
        }
        col.c.a = *cnt;
        draw_Menu_DrawStatRing_0_00186440(o->x38, o->x3C, D_0048CE40, col, 0.8f);
        break;
    }
    }
}
#undef MenuLayout_Get_1_00189050
#undef MenuLayout_GetSub_1_00189020
#undef Ui_DrawList_1_001829B0
#undef Text_Render_2_00188010

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/ui_gauge_rodata.c): D_001FCA80, D_001FCA88 */
s8 D_001FCA80[0x8] = { 0x25, 0x33, 0x64, 0, 0, 0, 0, 0 };
s8 D_001FCA88[0x8] = { 0x2d, 0x2d, 0x2d, 0, 0, 0, 0, 0 };
/* data twins (src/game/data/sbss.c): D_002020A8, D_002020AC */
Col_Ui_DrawWindow_0_00183650 D_002020A8;
s8 *D_002020AC;
/* data twins (src/game/data/ui_gauge_bss.c): D_0048D170 */
s8 D_0048D170[0x1e0];
#endif
