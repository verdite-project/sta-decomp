#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/ui.h"
typedef struct { s32 idx; u8 pad[0x3C]; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x34]; List *list; } Ctx;
typedef struct { u8 p:4; u8 v:1; } BF4;
typedef struct { s32 type; u8 pad[0x10]; BF4 x14; } Arg;
typedef union { s32 w; u8 b[4]; } Col_GameOver_Reset_0_0019E8A0;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_GameOverProc_DrawText_0_0019EA60;
typedef struct {
    u64 a, b;
    f32 x, y;
} S;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_GameOverProc_DrawText_0_0019EA60 x2C;
    f32 x30, x34, x38, x3C;
} A;
extern s32 gGameOverResetSbss_0020221C;
extern S gPauseMenuOpenData_001F31E0 __attribute__((aligned(16)));
#ifndef NONMATCHING
extern char gGameOverResetRodata_001FD660[];
#else
/* data twins (src/game/data/pause_menu_entry_rodata2.c): gGameOverResetRodata_001FD660 */
static char gGameOverResetRodata_001FD660[0x20] __attribute__((aligned(8))) = { -0x7e, 0x66, -0x7e, 0x60, -0x7e, 0x6c, -0x7e, 0x64, -0x7f, 0x40, -0x7e, 0x6e, -0x7e, 0x75, -0x7e, 0x64, -0x7e, 0x71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
void GameOver_Reset_0_0019E8A0(void);
void GameOver_DrawFrame_0_0019E8B0(Arg *arg0);
void GameOverProc_DrawText_0_0019EA60(A *o, s32 mode, u32 kind, u32 c);
Ctx* MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Elem *, s32, void (*)(), s32);
void Ui_DrawSprite_2_00181680(s32, f32 *, f32 *, Col_GameOverProc_DrawText_0_0019EA60 *, S *, s32);
void Text_Draw_2_001875C0(f32, char *, f32, f32, u32, u32);
char* Msg_GetText_2_00195B10(s32);
void Color_Pulse_1_00187960(f32, Col_GameOverProc_DrawText_0_0019EA60 *);

/* GameOver_Reset_0_0019E8A0 */
#define GameOverProc_DrawText_0_0019EA60 GameOverProc_DrawText_0_0019EA60__as_GameOver_Reset_0_0019E8A0
void GameOverProc_DrawText_0_0019EA60__as_GameOver_Reset_0_0019E8A0();

/* GameOver_Reset_0_0019E8A0 */
void GameOver_Reset_0_0019E8A0(void) {
    gGameOverResetSbss_0020221C = 0;
    gGameOverResetSbss_00202210 = 0;
}

/* GameOver_DrawFrame_0_0019E8B0 */
void GameOver_DrawFrame_0_0019E8B0(Arg *arg0) {
    Col_GameOver_Reset_0_0019E8A0 col;
    u32 i;
    List *list;
    s32 base;

    list = MenuLayout_Get_1_00189050(0)->list;
    base = MenuLayout_GetSub_1_00189020(0);
    if (arg0->type != 0x1C && arg0->type != 0x1E && arg0->type != 0x1F) {
        switch (gGameOverResetSbss_00202210) {
        case 0:
            arg0->x14.v = 1;
            gGameOverResetSbss_00202214 += 2;
            if (gGameOverResetSbss_00202214 > 0x80) {
                gGameOverResetSbss_00202214 = 0x80;
                gGameOverResetSbss_00202210 += 1;
            }
            break;
        case 1:
            gGameOverResetSbss_00202218 += 4;
            if (gGameOverResetSbss_00202218 > 0x80) {
                gGameOverResetSbss_00202218 = 0x80;
                gGameOverResetSbss_00202210 += 1;
            }
            break;
        case 2:
            break;
        }
    } else {
        gGameOverResetSbss_00202218 -= 0x10;
        if (gGameOverResetSbss_00202218 < 0) {
            gGameOverResetSbss_00202218 = 0;
        }
    }
    col.w = 0x80505050;
    col.b[3] = gGameOverResetSbss_00202218;
    for (i = 0; i < list->n; i++) {
        Ui_DrawList_1_001829B0(&list->e[i], base + list->e[i].idx * 8, GameOverProc_DrawText_0_0019EA60, col.w);
    }
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
}
#undef GameOverProc_DrawText_0_0019EA60

/* GameOverProc_DrawText_0_0019EA60 */
#define gGameOverResetSbss_0020221C gGameOverResetSbss_0020221C__as_GameOverProc_DrawText_0_0019EA60
extern f32 gGameOverResetSbss_0020221C__as_GameOverProc_DrawText_0_0019EA60;
static inline f32 u2f(u32 x) { return x; }

void GameOverProc_DrawText_0_0019EA60(A *o, s32 mode, u32 kind, u32 c) {
    Col_GameOverProc_DrawText_0_0019EA60 col;
    S s __attribute__((aligned(16)));

    s = gPauseMenuOpenData_001F31E0;
    s.x = o->x30;
    s.y = o->x34;
    o->x2C.w = c;
    if (mode == 1) {
        if (kind < 100) {
            col.w = 0x80303030;
            col.c.a = o->x2C.c.a;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        } else if (kind == 100 && mode == 1) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, Msg_GetText_2_00195B10(0x4B), o->x3C, 1.0f, 1, col.w);
        }
    } else if (mode == 2) {
        if (kind == 100) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, Msg_GetText_2_00195B10(0x4C), o->x3C, 1.0f, 1, col.w);
        }
        if (kind == 0 && gGameOverUpdateSbss_0020220C == 0) {
            col.w = 0x80303030;
            col.c.a = (s32)(gGameOverResetSbss_0020221C * u2f(o->x2C.c.a));
            Color_Pulse_1_00187960(gHudDrawSbss_002020D4, &col);
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        }
    } else if (mode == 3) {
        if (kind == 100 && mode == 3) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, Msg_GetText_2_00195B10(0x4D), o->x3C, 1.0f, 1, col.w);
        }
        if (kind == 0 && gGameOverUpdateSbss_0020220C == 1) {
            col.w = 0x80303030;
            col.c.a = (s32)(gGameOverResetSbss_0020221C * u2f(o->x2C.c.a));
            Color_Pulse_1_00187960(gHudDrawSbss_002020D4, &col);
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        }
    } else {
        if (kind < 100) {
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, kind);
        } else if (kind == 100 && mode == 1) {
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a;
            Text_Draw_2_001875C0(o->x38, gGameOverResetRodata_001FD660, o->x3C, 1.0f, 1, col.w);
        }
    }
}
#undef gGameOverResetSbss_0020221C

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gGameOverResetSbss_00202210, gGameOverResetSbss_00202214, gGameOverResetSbss_00202218, gGameOverResetSbss_0020221C */
s32 gGameOverResetSbss_00202210;
s32 gGameOverResetSbss_00202214;
s32 gGameOverResetSbss_00202218;
s32 gGameOverResetSbss_0020221C;
#endif
