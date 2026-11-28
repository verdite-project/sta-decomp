#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/sound.h"
#include "game/ui.h"
#include "game/gfx.h"
typedef struct { s32 idx; u8 pad4[0x3C]; } Item_Credits_DrawFrame_0_001DC900;
typedef struct { u32 n; Item_Credits_DrawFrame_0_001DC900 *items; } List_Credits_DrawFrame_0_001DC900;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9[5];
    u8 xE;
    u8 padF[5];
    Flags8 f14;
} O;
typedef struct { s32 idx; u8 pad[0x3C]; } Item_Credits_DrawBg_0_001DCE70;
typedef struct { u32 n; Item_Credits_DrawBg_0_001DCE70 *items; } List_Credits_DrawBg_0_001DCE70;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_CreditsProc_DrawText_0_001DCF80;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    u32 x2C;
    f32 x30, x34, x38, x3C;
} A;
typedef union { u32 w; u8 b[4]; } Col_TitleProc_DrawPushStart_0_001DD510;
typedef struct { f32 x, y, z, w; } V4;
#ifdef NONMATCHING
extern u8 gCreditsRodata_001FE714[];
#endif
#ifndef NONMATCHING
extern s16 gCreditsSdata_00201E40;
#else
/* data twins (src/game/data/sdata.c): gCreditsSdata_00201E40 */
static s16 gCreditsSdata_00201E40 = 2;
#endif
extern f32 gCreditsSbss_00202334;
#ifndef NONMATCHING
extern s16 gCreditsSbss_0020233C;
#else
/* data twins (src/game/data/sbss.c): gCreditsSbss_0020233C */
static s16 gCreditsSbss_0020233C;
#endif
extern s16 gCreditsSbss_00202350;
extern s16 D_00202352;
extern s16 gCreditsSbss_00202354;
extern s16 D_00202356;
#ifndef NONMATCHING
extern f32 gCreditsSbss_00202338;
#else
/* data twins (src/game/data/sbss.c): gCreditsSbss_00202338 */
static f32 gCreditsSbss_00202338;
#endif
#ifndef NONMATCHING
extern s32 gCreditsSbss_00202340;
#else
/* data twins (src/game/data/sbss.c): gCreditsSbss_00202340 */
static s32 gCreditsSbss_00202340;
#endif
extern u8 gCreditsSbss_00202348;
extern f32 gCreditsSdata_00201E44;
extern f32 gCreditsSdata_00201E48;
#ifndef NONMATCHING
extern S gCreditsData_001F3A10 __attribute__((aligned(16)));
#else
/* data twins (src/game/data/player_status_data.c): gCreditsData_001F3A10 */
static S gCreditsData_001F3A10 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING
extern f32 gCreditsSbss_00202344;
#else
/* data twins (src/game/data/sbss.c): gCreditsSbss_00202344 */
static f32 gCreditsSbss_00202344;
#endif
extern S gCreditsData_001F39F0[] __attribute__((aligned(16)));
#ifndef NONMATCHING
extern s32 gCreditsSdata_00201E4C;
#else
/* data twins (src/game/data/sdata.c): gCreditsSdata_00201E4C */
static s32 gCreditsSdata_00201E4C = (s32)((u8 *)gCreditsRodata_001FE714 + 0x4);
#endif
#ifndef NONMATCHING
extern s32 gCreditsRodata_001FE730[];
#else
/* data twins (src/game/data/shop_menu_rodata.c): gCreditsRodata_001FE730 */
static s32 gCreditsRodata_001FE730[0x6] __attribute__((aligned(4))) = { 0x5241545c, 0x5c544547, 0x5f415453, 0x412e4954, 0x5844, 0 };
#endif
void Credits_Update_0_001DCC30(O *o);
void CreditsProc_DrawText_0_001DCF80(A *o, s32 idx, u32 kind);
void TitleProc_DrawPushStart_0_001DD510(s8 *a0, s32 a1, s32 a2);
void Credits_HandleEvent_0_001DD650(s32 *arg0);
List_Credits_DrawFrame_0_001DC900** MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(void *, s32, void (*)(), s32);
void Strm_SetFadeStep_1_001304B0(s32);
void Snd_PlaySe_3_00131600(s32, u8);
void Ui_DrawList_1_001829B0__as_Credits_DrawFrame_0_001DC900(Item_Credits_DrawFrame_0_001DC900 *, s32, void (*)(), s32);
List_Credits_DrawBg_0_001DCE70** MenuLayout_Get_1_00189050__as_Credits_DrawBg_0_001DCE70(s32);
void Ui_DrawList_1_001829B0__as_Credits_DrawBg_0_001DCE70(Item_Credits_DrawBg_0_001DCE70 *, s32, void (*)(), s32);
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S*, u32);
void GsPkt_SetReg_3_001543E0(s32, u64);
s8* Msg_GetText_2_00195B10(s32);
void Text_DrawScaledH_1_001874F0(f32 x, s16 h, s8 *str, u32 a, Col_CreditsProc_DrawText_0_001DCF80 col, f32 y, f32 sc);
void Text_Draw_2_001875C0(s32, s32, f32, u32, f32, f32);
void Color_Pulse_1_00187960(f32, Col_TitleProc_DrawPushStart_0_001DD510 *);
void TitleProc_DrawPushStart_0_001DD510__as_Credits_DrawFrame_0_001DC900_();
void CreditsProc_DrawText_0_001DCF80__as_Credits_DrawFrame_0_001DC900_();
void Strm_PlayFile_2_00130590(s32 *, s32, s32);

/* Credits_DrawFrame_0_001DC900__ */
#define Credits_HandleEvent_0_001DD650 Credits_HandleEvent_0_001DD650__as_Credits_DrawFrame_0_001DC900__
void Credits_HandleEvent_0_001DD650__as_Credits_DrawFrame_0_001DC900__(O *);

/* Credits_DrawFrame_0_001DC900_ */

/* Credits_DrawFrame_0_001DC900 */

void Credits_DrawFrame_0_001DC900(void) {
    u32 i;
    List_Credits_DrawFrame_0_001DC900 *l;
    s32 base;

    l = *MenuLayout_Get_1_00189050(3);
    base = MenuLayout_GetSub_1_00189020(3);
    if (gCreditsSbss_00202334 > 45.0f && gCreditsSbss_00202334 < 75.0f) {
        gCreditsSbss_00202350 = 127.0f * (gCreditsSbss_00202334 - 45.0f) / 30.0f;
    }
    if (gCreditsSbss_00202334 > 30.0f && gCreditsSbss_00202334 < 60.0f) {
        D_00202352 = 127.0f * (gCreditsSbss_00202334 - 30.0f) / 30.0f;
    }
    if (gCreditsSbss_00202334 > 75.0f && gCreditsSbss_00202334 < 105.0f) {
        gCreditsSbss_00202354 = 127.0f * (gCreditsSbss_00202334 - 75.0f) / 30.0f;
    }
    if (gCreditsSbss_00202334 > 90.0f && gCreditsSbss_00202334 < 120.0f) {
        D_00202356 = 127.0f * (gCreditsSbss_00202334 - 90.0f) / 30.0f;
    }
    if (gCreditsSbss_00202334 < 30.0f) {
        gCreditsSbss_0020233C = 127.0f * gCreditsSbss_00202334 / 30.0f;
    } else if (gCreditsSbss_00202334 <= 60.0f) {
        gCreditsSbss_0020233C += gCreditsSdata_00201E40;
        if (gCreditsSbss_0020233C <= 0) {
            gCreditsSbss_0020233C = 0;
            gCreditsSdata_00201E40 = 1;
        }
        if (gCreditsSbss_0020233C >= 0x7F) {
            gCreditsSbss_0020233C = 0x7F;
            gCreditsSdata_00201E40 = -1;
        }
    } else if (gCreditsSbss_00202334 < 1800.0f) {
        gCreditsSbss_0020233C += gCreditsSdata_00201E40;
        if (gCreditsSbss_0020233C <= 0) {
            gCreditsSbss_0020233C = 0;
            gCreditsSdata_00201E40 = 1;
        }
        if (gCreditsSbss_0020233C >= 0x7F) {
            gCreditsSbss_0020233C = 0x7F;
            gCreditsSdata_00201E40 = -1;
        }
    } else {
        gCreditsSbss_0020233C += gCreditsSdata_00201E40;
        if (gCreditsSbss_0020233C <= 0) {
            gCreditsSbss_0020233C = 0;
        }
        if (gCreditsSbss_0020233C >= 0x7F) {
            gCreditsSbss_0020233C = 0x7F;
        }
    }
    for (i = 0; i < l->n; i++) {
        Ui_DrawList_1_001829B0__as_Credits_DrawFrame_0_001DC900(&l->items[i], base + l->items[i].idx * 8, TitleProc_DrawPushStart_0_001DD510__as_Credits_DrawFrame_0_001DC900_, 0);
    }
}

/* Credits_Update_0_001DCC30 */
void Credits_Update_0_001DCC30(O *o) {
    s16 v;

    Credits_HandleEvent_0_001DD650(o);
    if (o->x0 != 0x16) return;
    if (gCreditsSbss_00202348 != 5) {
        D_00202356 = (127.0f * (15.0f - (gCreditsSbss_00202334 - gCreditsSbss_00202338))) / 15.0f;
        if (!(gCreditsSbss_00202334 < 15.0f + gCreditsSbss_00202338)) {
            o->x8 = gCreditsSbss_00202348;
            o->x4 = 0;
            o->x0 = 0x1A;
        }
    } else {
        if (!(gCreditsSbss_00202334 <= 100.0f) && (o->x4 & 0x6008)) {
            Snd_PlaySe_3_00131600(0x69, o->xE);
            gCreditsSbss_00202348 = 6;
            gCreditsSbss_00202338 = gCreditsSbss_00202334;
            o->x8 = 6;
            o->f14.f.b5 = 0;
            gCreditsSbss_00202340 = 0;
            o->x4 = 0;
            o->x0 = 0x1F;
            return;
        }
        if (o->x4 & 0x6008) {
            Snd_PlaySe_3_00131600(0x69, o->xE);
            gCreditsSbss_00202348 = 6;
            gCreditsSbss_00202338 = gCreditsSbss_00202334;
            o->x8 = 6;
            o->f14.f.b5 = 1;
            gCreditsSbss_00202340 = 0;
            o->x4 = 0;
            o->x0 = 0x1F;
            return;
        }
        if (!(gCreditsSbss_00202334 < 1800.0f)) {
            Strm_SetFadeStep_1_001304B0(-0x444);
            gCreditsSdata_00201E40 = -2;
            if (!(gCreditsSbss_00202334 < 1830.0f)) {
                o->x8 = 4;
                o->x4 = 0;
                o->x0 = 0x1E;
                Strm_Stop_2_00130440();
            } else {
                v = (127.0f * (1830.0f - gCreditsSbss_00202334)) / 30.0f;
                D_00202356 = v;
                gCreditsSbss_00202354 = v;
                D_00202352 = v;
                gCreditsSbss_00202350 = v;
            }
        }
    }
    gCreditsSbss_00202334 += 1.0f;
}

/* Credits_DrawBg_0_001DCE70 */

void Credits_DrawBg_0_001DCE70(void) {
    u32 i;
    List_Credits_DrawBg_0_001DCE70 *l;
    s32 base;
    Item_Credits_DrawBg_0_001DCE70 *it;

    l = MenuLayout_Get_1_00189050__as_Credits_DrawBg_0_001DCE70(3)[1];
    base = MenuLayout_GetSub_1_00189020(3);
    gCreditsSdata_00201E48 += 4.0f;
    if (!(gCreditsSdata_00201E48 <= 128.0f)) gCreditsSdata_00201E48 = 128.0f;
    gCreditsSdata_00201E44 += 4.0f;
    if (!(gCreditsSdata_00201E44 <= 128.0f)) gCreditsSdata_00201E44 = 128.0f;
    for (i = 0; i < l->n; i++) {
        it = &l->items[i];
        Ui_DrawList_1_001829B0__as_Credits_DrawBg_0_001DCE70(it, base + it->idx * 8, CreditsProc_DrawText_0_001DCF80__as_Credits_DrawFrame_0_001DC900_, 0);
    }
    Menu_DrawBackground_0_00187B20(0);
}

/* CreditsProc_DrawText_0_001DCF80 */
/* CreditsProc_DrawText_0_001DCF80 */

static inline f32 u2f(u32 x) { return x; }
static inline f32 mu(u32 x, f32 k) { return x * k / 128.0f; }

void CreditsProc_DrawText_0_001DCF80(A *o, s32 idx, u32 kind) {
    f32 f;
    S s __attribute__((aligned(16)));
    Col_CreditsProc_DrawText_0_001DCF80 col;

    s = gCreditsData_001F3A10;
    f = gCreditsSdata_00201E44;
    s.x = o->x30;
    s.y = o->x34;
    col.w = 0x80808080;
    f = f < 0.0f ? 0.0f : f;
    if (kind < 100) {
        col.w = o->x2C;
        col.c.a = mu(col.c.a, f);
        Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    }
    switch (kind) {
    case 0x65:
        col.c.a = mu(col.c.a, f);
        Text_DrawScaledH_1_001874F0(o->x38, -1, Msg_GetText_2_00195B10(0x80), 0, col, o->x3C, 0.75f);
        return;
    case 0x64:
        f = gCreditsSdata_00201E48;
        col.w = o->x2C;
        f = f < 0.0f ? 0.0f : f;
        col.c.a = mu(col.c.a, f);
        Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    case 0x66:
        Ui_BeginSprites_1_00181420();
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x48);
        GsPkt_Flush_1_001544C0();
        col.w = o->x2C;
        col.c.a = col.c.a * gCreditsSbss_0020233C / 127;
        if (gCreditsSbss_00202334 < 30.0f) {
            col.c.r = col.c.g = col.c.b = 0x80;
        } else if (gCreditsSbss_00202334 <= 60.0f) {
            col.c.r = col.c.g = col.c.b = 0x80;
        }
        if (gCreditsSbss_00202340 == 0) {
            gCreditsSbss_00202344 = gCreditsSbss_00202344 - (gCreditsSbss_00202344 - 32.0f) / 15.0f;
            col.c.a = gCreditsSbss_00202344;
        } else {
            gCreditsSbss_00202344 = u2f(col.c.a);
        }
        col.c.r = 0x96;
        col.c.g = 0xAA;
        col.c.b = 0x96;
        Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        Ui_BeginSprites_1_00181420();
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x44);
        GsPkt_Flush_1_001544C0();
        return;
    default:
        col.w = o->x2C;
        col.c.a = mu(col.c.a, f);
        Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    }
}

/* TitleProc_DrawPushStart_0_001DD510 */

void TitleProc_DrawPushStart_0_001DD510(s8 *a0, s32 a1, s32 a2) {
    S t __attribute__((aligned(16)));
    V4 v;
    Col_TitleProc_DrawPushStart_0_001DD510 col;

    t = gCreditsData_001F39F0[0];
    t.x = *(f32 *)(a0 + 0x30);
    t.y = *(f32 *)(a0 + 0x34);
    col.w = 0x80808080;
    switch (a2) {
    case 0xC8:
        col.w = *(u32 *)(a0 + 0x2C);
        col.b[3] = col.b[3] * D_00202356 / 127;
        v.x = *(f32 *)(a0 + 0x0);
        v.z = *(f32 *)(a0 + 0x8);
        v.y = *(f32 *)(a0 + 0x4);
        v.w = *(f32 *)(a0 + 0xC);
        Color_Pulse_1_00187960(gHudDrawSbss_002020D4, &col);
        Ui_DrawSprite_2_00181680(*(s32 *)(a0 + 0x28), &v, a0 + 0x10, &col, &t, a2);
        break;
    case 0xC9:
        col.b[3] = D_00202356;
        Text_Draw_2_001875C0(gCreditsSdata_00201E4C, 0, *(f32 *)(a0 + 0x38), col.w, *(f32 *)(a0 + 0x3C), 1.0f);
        break;
    }
}
#undef Credits_HandleEvent_0_001DD650

/* Credits_HandleEvent_0_001DD650 */
#define gCreditsSdata_00201E44 gCreditsSdata_00201E44__as_Credits_HandleEvent_0_001DD650
extern s32 gCreditsSdata_00201E44__as_Credits_HandleEvent_0_001DD650;
#define gCreditsSdata_00201E48 gCreditsSdata_00201E48__as_Credits_HandleEvent_0_001DD650
extern s32 gCreditsSdata_00201E48__as_Credits_HandleEvent_0_001DD650;
#define gCreditsSbss_00202334 gCreditsSbss_00202334__as_Credits_HandleEvent_0_001DD650
extern s32 gCreditsSbss_00202334__as_Credits_HandleEvent_0_001DD650;
#define gCreditsSbss_00202348 gCreditsSbss_00202348__as_Credits_HandleEvent_0_001DD650
extern s8 gCreditsSbss_00202348__as_Credits_HandleEvent_0_001DD650;

void Credits_HandleEvent_0_001DD650(s32 *arg0) {
    switch (*arg0) {
    case 25:
        gCreditsSbss_00202340 = 1;
        gCreditsSdata_00201E44 = 0xC3000000;
        gCreditsSdata_00201E48 = 0xC3000000;
        gCreditsSbss_00202348 = 5;
        gCreditsSbss_00202334 = 0;
        gCreditsSbss_0020233C = 0;
        D_00202356 = 0;
        gCreditsSbss_00202354 = 0;
        D_00202352 = 0;
        gCreditsSbss_00202350 = 0;
        Strm_PlayFile_2_00130590(gCreditsRodata_001FE730, 0, 1);
        break;
    case 27:
    case 0:
    case 22:
    case 26:
    case 28:
    case 30:
        break;
    }
}
#undef gCreditsSdata_00201E44
#undef gCreditsSdata_00201E48
#undef gCreditsSbss_00202334
#undef gCreditsSbss_00202348

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 gCreditsRodata_001FE714[];
/* data twins (src/game/data/sdata.c): gCreditsSdata_00201E44, gCreditsSdata_00201E48 */
f32 gCreditsSdata_00201E44 = -128.0f;
f32 gCreditsSdata_00201E48 = -128.0f;
/* data twins (src/game/data/sbss.c): gCreditsSbss_00202334, gCreditsSbss_00202348, gCreditsSbss_00202350, gCreditsSbss_00202354 */
f32 gCreditsSbss_00202334;
u8 gCreditsSbss_00202348;
s16 gCreditsSbss_00202350;
s16 gCreditsSbss_00202354;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/player_status_data.c): D_001F39F0__grp: gCreditsData_001F39F0@0x0 */
f32 D_001F39F0__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/shop_menu_rodata.c): D_001FE714__grp: gCreditsRodata_001FE714@0x0 */
s32 D_001FE714__grp[0x7] __attribute__((aligned(4))) = { 0, 0x48535550, 0x41545320, 0x5452, 0, 0, 0 };
#endif
