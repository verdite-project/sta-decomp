#include "common.h"
#include "game/sound.h"
#include "game/ui.h"
typedef struct { s32 x0; u8 pad[0x3B]; u8 b3F; } E;
typedef struct { u32 n; E *e; } L;
typedef struct { u8 pad[0x38]; L *l; } R;
typedef union { u32 w; s8 b[4]; } Col_Ending_DrawText_0_001ED850;
typedef struct { s32 x0; s32 x4; s8 x8; } T;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col_Ending_Draw_0_001EDAD0;
typedef struct { s32 idx; u8 pad[0x3B]; u8 a; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x3C]; List *list; } Ctx;
typedef struct { s32 x0; u8 pad[0x10]; Flags8 f14; } A;
#ifdef NONMATCHING
void func_00100000(void);
#endif
#ifndef NONMATCHING
extern f32 gEndingDrawSbss_00202408;
#else
/* data twins (src/game/data/sbss.c): gEndingDrawSbss_00202408 */
static f32 gEndingDrawSbss_00202408;
#endif
#ifndef NONMATCHING
extern f32 gEndingDrawSbss_0020240C;
#else
/* data twins (src/game/data/sbss.c): gEndingDrawSbss_0020240C */
static f32 gEndingDrawSbss_0020240C;
#endif
#ifndef NONMATCHING
extern s32 gEndingDrawSbss_00202410;
#else
/* data twins (src/game/data/sbss.c): gEndingDrawSbss_00202410 */
static s32 gEndingDrawSbss_00202410;
#endif
extern s32 gMenuData_001F27B0[];
extern s32 gMenuData_001F27C0[];
#ifndef NONMATCHING
extern f32 gEndingDrawSbss_00202414;
#else
/* data twins (src/game/data/sbss.c): gEndingDrawSbss_00202414 */
static f32 gEndingDrawSbss_00202414;
#endif
#ifndef NONMATCHING
extern f32 gEndingDrawSbss_00202418;
#else
/* data twins (src/game/data/sbss.c): gEndingDrawSbss_00202418 */
static f32 gEndingDrawSbss_00202418;
#endif
#ifndef NONMATCHING
extern s32 gEndingDrawRodata_00201A70[];
#else
/* data twins (src/game/data/movie_rodata2.c): gEndingDrawRodata_00201A70 */
static s32 gEndingDrawRodata_00201A70[0x44] = { 0x5241545c, 0x5c544547, 0x5f415453, 0x412e4f47, 0x5844, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (s32)func_00100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern f32 gEndingDrawSbss_0020241C;
#else
/* data twins (src/game/data/sbss.c): gEndingDrawSbss_0020241C */
static f32 gEndingDrawSbss_0020241C;
#endif
#ifndef NONMATCHING
extern s32 gEndingDrawSbss_00202420;
#else
/* data twins (src/game/data/sbss.c): gEndingDrawSbss_00202420 */
static s32 gEndingDrawSbss_00202420;
#endif
void Ending_Update_0_001ED9A0(T *a);
void Ending_HandleEvent_0_001EDCC0(A *a);
void Ui_DrawElemWrap_1_001829A0(E *, s8 *);
void Text_Draw_2_001875C0(s32, s32, u32, f32, f32, f32);
s8* MenuLayout_GetSub_1_00189020(s32);
R* MenuLayout_Get_1_00189050(s32);
s32 Msg_GetText_2_00195B10(s32);
void Ui_DrawSpriteRotated_1_00182080(f32, s32, s32 *, s32 *, Col_Ending_Draw_0_001EDAD0 *, s32);
s32 Strm_PlayFile_2_00130590(s32 *, s32, s32);

/* Ending_DrawText_0_001ED850 */
void Ending_DrawText_0_001ED850(void) {
    Col_Ending_DrawText_0_001ED850 col;
    u32 i;
    L *l;
    s8 *base;


    col.w = 0x80808080;
    col.b[3] = (s32)gEndingDrawSbss_00202408;
    l = MenuLayout_Get_1_00189050(0)->l;
    base = MenuLayout_GetSub_1_00189020(0);
    for (i = 0; i < l->n; i++) {
        l->e[i].b3F = 1.95f * (f32)(s32)gEndingDrawSbss_00202408;
        Ui_DrawElemWrap_1_001829A0(&l->e[i], base + l->e[i].x0 * 8);
    }
    Text_Draw_2_001875C0(Msg_GetText_2_00195B10(0x190), 1, col.w, 320.0f, 120.0f, 1.0f);
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
}

/* Ending_Update_0_001ED9A0 */
void Ending_Update_0_001ED9A0(T *a) {
    if (a->x0 == 0x19) {
        gEndingDrawSbss_00202408 = 0.0f;
        gEndingDrawSbss_0020240C = 0.0f;
        gEndingDrawSbss_00202410 = 0;
    }
    if (a->x0 == 0x16) {
        switch (gEndingDrawSbss_00202410) {
        case 0:
            gEndingDrawSbss_00202408 += 4.0f;
            if (!(gEndingDrawSbss_00202408 <= 128.0f)) {
                gEndingDrawSbss_00202408 = 128.0f;
                gEndingDrawSbss_00202410 = 3;
            }
            break;
        case 1:
            break;
        case 3:
            gEndingDrawSbss_0020240C += 1.0f;
            if (!(gEndingDrawSbss_0020240C <= 450.0f)) {
                gEndingDrawSbss_00202410 = 4;
            }
            break;
        case 4:
            gEndingDrawSbss_00202408 -= 4.0f;
            if (gEndingDrawSbss_00202408 < 0.0f) {
                gEndingDrawSbss_00202408 = 0.0f;
                gEndingDrawSbss_00202410 = 5;
            }
            break;
        case 5:
            a->x8 = 4;
            a->x4 = 0;
            a->x0 = 0x1A;
            break;
        }
    }
}

/* Ending_Draw_0_001EDAD0 */
#define MenuLayout_Get_1_00189050 MenuLayout_Get_1_00189050__as_Ending_Draw_0_001EDAD0
Ctx *MenuLayout_Get_1_00189050__as_Ending_Draw_0_001EDAD0(s32);
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_Ending_Draw_0_001EDAD0
s32 MenuLayout_GetSub_1_00189020__as_Ending_Draw_0_001EDAD0(s32);
#define Ui_DrawElemWrap_1_001829A0 Ui_DrawElemWrap_1_001829A0__as_Ending_Draw_0_001EDAD0
void Ui_DrawElemWrap_1_001829A0__as_Ending_Draw_0_001EDAD0(Elem *, s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_Ending_Draw_0_001EDAD0
void Text_Draw_2_001875C0__as_Ending_Draw_0_001EDAD0(s32, s32, Col_Ending_Draw_0_001EDAD0, f32, f32, f32);

void Ending_Draw_0_001EDAD0(void) {
    Col_Ending_Draw_0_001EDAD0 c2;
    Col_Ending_Draw_0_001EDAD0 c1;
    u32 i;
    List *list;
    s32 base;

    c2.w = 0;
    c2.c.a = gEndingDrawSbss_00202414;
    Ui_DrawSpriteRotated_1_00182080(0.0f, 0, gMenuData_001F27B0, gMenuData_001F27C0, &c2, 0);
    Ui_BeginSprites_1_00181420();
    list = MenuLayout_Get_1_00189050(0)->list;
    base = MenuLayout_GetSub_1_00189020(0);
    for (i = 0; i < list->n; i++) {
        list->e[i].a = 1.95f * gEndingDrawSbss_00202418;
        Ui_DrawElemWrap_1_001829A0(&list->e[i], base + list->e[i].idx * 8);
    }
    c1.w = 0x80808080;
    c1.c.a = gEndingDrawSbss_00202418;
    Text_Draw_2_001875C0(Msg_GetText_2_00195B10(0x191), 1, c1, 320.0f, 200.0f, 1.1f);
}
#undef MenuLayout_Get_1_00189050
#undef MenuLayout_GetSub_1_00189020
#undef Ui_DrawElemWrap_1_001829A0
#undef Text_Draw_2_001875C0

/* Ending_HandleEvent_0_001EDCC0 */
void Ending_HandleEvent_0_001EDCC0(A *a) {
    if (a->x0 == 0x19) {
        gEndingDrawSbss_00202414 = 0.0f;
        gEndingDrawSbss_00202418 = 0.0f;
        gEndingDrawSbss_0020241C = 0.0f;
        gEndingDrawSbss_00202420 = 0;
        Snd_StopAll_1_0012C320();
        Strm_PlayFile_2_00130590(gEndingDrawRodata_00201A70, 0, 0);
    }
    if (a->x0 == 0x16) {
        switch (gEndingDrawSbss_00202420) {
        case 0:
            gEndingDrawSbss_00202414 += 4.0f;
            if (gEndingDrawSbss_00202414 > 128.0f) {
                gEndingDrawSbss_00202414 = 128.0f;
                gEndingDrawSbss_00202420 = 1;
            }
            break;
        case 1:
            gEndingDrawSbss_00202418 += 4.0f;
            if (gEndingDrawSbss_00202418 > 128.0f) {
                gEndingDrawSbss_00202418 = 128.0f;
                gEndingDrawSbss_00202420 = 3;
            }
            break;
        case 3:
            gEndingDrawSbss_0020241C += 1.0f;
            if (gEndingDrawSbss_0020241C > 450.0f) {
                gEndingDrawSbss_00202420 = 4;
            }
            break;
        case 4:
            gEndingDrawSbss_00202418 -= 4.0f;
            if (gEndingDrawSbss_00202418 < 0.0f) {
                gEndingDrawSbss_00202418 = 0.0f;
                gEndingDrawSbss_00202420 = 5;
            }
            break;
        case 5:
            Strm_Stop_2_00130440();
            a->f14.f.b1 = 1;
            break;
        }
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
void func_00100000(void);
#endif
