#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/save.h"
#include "game/ui.h"
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[2]; u8 xA; u8 padB[3]; u8 xE; } O_SaveMenu_ConfirmLoad_0_0018D060;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9; u8 xA; u8 padB[3]; u8 xE; u8 padF[5]; Flags8 x14; } O_SaveMenu_Exit_0_0018D140;
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; u8 pad[3]; } E;
typedef struct { s32 sel; s32 x4; s32 x8; f32 xC; s32 x10; s32 x14; E e[2]; } M_SaveMenu_DrawFrame_0_0018D1F0;
typedef struct { s32 idx; u8 pad4[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { s32 x0; s32 x4; } A;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { s32 sel; s32 x4; s32 x8; f32 xC; f32 x10; s32 x14; E e[2]; } M_SaveMenu_DrawSlot_1_0018D420;
typedef struct { u8 p0[0xAC]; s8 *xAC; } G;
typedef struct { s32 sel; s32 x4; s32 x8; f32 xC; s32 x10; s32 x14; E e[2]; } M_SaveMenu_SelectDevice_0_0018D7B0;
extern M_SaveMenu_DrawFrame_0_0018D1F0 D_004A1050;
extern s32 D_004A105C[];
#ifndef NONMATCHING
extern f32 D_004A1060[];
#else
/* data twins (src/game/data/option_bss.c): D_004A1060 */
static f32 D_004A1060[0x2] __attribute__((aligned(4)));
#endif
extern S D_001F2A50[] __attribute__((aligned(16)));
#ifndef NONMATCHING
extern s8 D_001FCDC8[];
#else
/* data twins (src/game/data/save_menu_rodata.c): D_001FCDC8 */
static s8 D_001FCDC8[0x8] = "SLOT %d\000";
#endif
void SaveMenu_ConfirmLoad_0_0018D060(O_SaveMenu_ConfirmLoad_0_0018D060 *o);
void SaveMenu_Exit_0_0018D140(O_SaveMenu_Exit_0_0018D140 *o);
void SaveMenu_DrawFrame_0_0018D1F0(u8 *a0);
void SaveMenu_Open_1_0018D360(A *a);
void SaveMenu_DrawSlot_1_0018D420(s8 *o, s32 sel, u32 id);
void SaveMenu_SelectDevice_0_0018D7B0(s8 *arg0);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void Snd_PlaySe_3_00131600(s32, s32);
void MenuProc_BackOnCancel_0_0018D000();
void Strm_SetFadeStep_1_001304B0(s32);
List** MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Item *, s32, void (*)(), s32);
void SaveMenu_UpdateCardFlags_1_0018E120(s32, s32 *);
void Ui_DrawSprite_2_00181680(s32, s8 *, s8 *, void *, S *, s32);
f32 sinf(f32);
f32 fabsf(f32);
void sprintf(s8 *, s8 *, ...);
void Text_Draw_2_001875C0(s8 *, s32, u32, f32, f32, f32);
s8 MenuStack_Pop_1_00189EA0(void);
void SaveMenu_Load_0_0018DA20(s8 *);
void SaveMenu_CheckCard_0_0018DFB0(s8 *);
void SaveMenu_Retry_0_0018E0B0(s8 *);

/* SaveMenu_ConfirmLoad_0_0018D060 */
void SaveMenu_ConfirmLoad_0_0018D060(O_SaveMenu_ConfirmLoad_0_0018D060 *o) {
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    if (o->x4 & 0x2000) {
        o->xA = 2;
        D_004A1010[0].f.b0 = 1;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
}

/* SaveMenu_Exit_0_0018D140 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_SaveMenu_Exit_0_0018D140
void Snd_PlaySe_3_00131600__as_SaveMenu_Exit_0_0018D140(s32, u8);
void SaveMenu_Exit_0_0018D140(O_SaveMenu_Exit_0_0018D140 *o) {
    if (o->x4 & 0x2000) {
        o->xA = 2;
        o->x14.f.b2 = 1;
        D_004A1010[0].f.b0 = 0;
        Strm_SetFadeStep_1_001304B0(-0x666);
        D_00202120[SaveSys_GetPort_1_001E8290()] = D_004A0FF0[0];
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
}
#undef Snd_PlaySe_3_00131600

/* SaveMenu_DrawFrame_0_0018D1F0 */
#define SaveMenu_DrawSlot_1_0018D420 SaveMenu_DrawSlot_1_0018D420__as_SaveMenu_DrawFrame_0_0018D1F0
void SaveMenu_DrawSlot_1_0018D420__as_SaveMenu_DrawFrame_0_0018D1F0();

void SaveMenu_DrawFrame_0_0018D1F0(u8 *a0) {
    u32 i;
    List *l;
    s32 base;


    l = MenuLayout_Get_1_00189050(4)[0];
    base = MenuLayout_GetSub_1_00189020(4);
    if (*(s32 *)a0 == 0x19) {
        D_004A1050.e[0].b0 = 0;
        D_004A1050.e[1].b0 = 0;
    }
    if (a0[8] == 9) {
        D_004A1050.xC += 16.0f;
    } else {
        D_004A1050.xC -= 16.0f;
    }
    Ui_SetAlphaClamped_0_00182050(D_004A1050.xC);
    for (i = 0; i < l->n; i++) {
        Ui_DrawList_1_001829B0(&l->items[i], base + l->items[i].idx * 8, SaveMenu_DrawSlot_1_0018D420, D_004A1050.sel);
    }
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
    Ui_SetAlphaClamped_0_00182050(0x80);
}
#undef SaveMenu_DrawSlot_1_0018D420

/* SaveMenu_Open_1_0018D360 */
#define SaveMenu_SelectDevice_0_0018D7B0 SaveMenu_SelectDevice_0_0018D7B0__as_SaveMenu_Open_1_0018D360
void SaveMenu_SelectDevice_0_0018D7B0__as_SaveMenu_Open_1_0018D360(A *);
#define D_004A1050 D_004A1050__as_SaveMenu_Open_1_0018D360
extern s32 D_004A1050__as_SaveMenu_Open_1_0018D360[];
void SaveMenu_Open_1_0018D360(A *a) {
    SaveMenu_UpdateCardFlags_1_0018E120(0, D_004A1068);
    SaveMenu_UpdateCardFlags_1_0018E120(1, D_004A106C);
    switch (a->x0) {
    case 25:
        D_004A1060[0] = 0.0f;
        D_004A105C[0] = 0;
        D_004A1054[0] = 0;
        D_004A1050[0] = SaveSys_GetPort_1_001E8290();
        break;
    case 22:
        SaveMenu_SelectDevice_0_0018D7B0(a);
        D_004A1060[0] += 0.1f;
        a->x4 = 0;
        break;
    }
}
#undef SaveMenu_SelectDevice_0_0018D7B0
#undef D_004A1050

/* SaveMenu_DrawSlot_1_0018D420 */
#define D_004A1050 D_004A1050__as_SaveMenu_DrawSlot_1_0018D420
extern M_SaveMenu_DrawSlot_1_0018D420 D_004A1050__as_SaveMenu_DrawSlot_1_0018D420;
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_SaveMenu_DrawSlot_1_0018D420
G *MenuLayout_GetSub_1_00189020__as_SaveMenu_DrawSlot_1_0018D420(s32);

void SaveMenu_DrawSlot_1_0018D420(s8 *o, s32 sel, u32 id) {
    S t __attribute__((aligned(16)));
    Col col;
    s8 *p;

    t = D_001F2A50[0];
    if (id < 500) {
        t.x = *(f32 *)(o + 0x30);
        t.y = *(f32 *)(o + 0x34);
        Ui_DrawSprite_2_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        return;
    }
    switch (id) {
    case 500:
        if (sel == D_004A1050.sel) {
            o[0x2C] = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1050.x10)));
            o[0x2D] = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1050.x10)));
            o[0x2E] = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1050.x10)));
        } else {
            o[0x2C] = 0x40;
            o[0x2D] = 0x40;
            o[0x2E] = 0x40;
            o[0x2F] = 0x40;
        }
        if (D_004A1050.e[sel].b0) {
            t.x = *(f32 *)(o + 0x30);
            t.y = *(f32 *)(o + 0x34);
            Ui_DrawSprite_2_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        }
        break;
    case 0x226:
        p = MenuLayout_GetSub_1_00189020(0)->xAC;
        col.w = 0x30808080;
        t.m[0] = 1.0f;
        t.m[3] = 1.0f;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C);
        col.w = (sel == D_004A1050.sel) ? 0x40808000 : 0x30808080;
        Ui_DrawSprite_2_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, id);
        {
        s8 buf[16] = {0};
        col.w = 0x80808080;
        if (D_004A1050.xC < 0.0f) {
            col.b[3] = 0;
        } else if (D_004A1050.xC <= 128.0f) {
            col.b[3] = col.b[3] * (s32)D_004A1050.xC / 128.0f;
        }
        sprintf(buf, D_001FCDC8, sel + 1);
        Text_Draw_2_001875C0(buf, 0, col.w, 8.0f + t.x, 4.0f + t.y, 1.0f);
        }
        break;
    }
}
#undef MenuLayout_GetSub_1_00189020
#undef D_004A1050

/* SaveMenu_SelectDevice_0_0018D7B0 */
#define D_004A1050 D_004A1050__as_SaveMenu_SelectDevice_0_0018D7B0
extern M_SaveMenu_SelectDevice_0_0018D7B0 D_004A1050__as_SaveMenu_SelectDevice_0_0018D7B0;
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_SaveMenu_SelectDevice_0_0018D7B0
void MenuProc_Set_1_0018B150__as_SaveMenu_SelectDevice_0_0018D7B0(s32 *, s32, s32, void (*)(s8 *), s32, f32);

void SaveMenu_SelectDevice_0_0018D7B0(s8 *arg0) {
    s32 b;

    b = *(s32 *)(arg0 + 4);
    if (b & 0x80) {
        D_004A1050.sel--;
        if (D_004A1050.sel < 0) {
            D_004A1050.sel = 1;
        }
        D_004A1050.x10 = 0;
        Snd_PlaySe_3_00131600(0x66, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x20) {
        D_004A1050.sel++;
        if (D_004A1050.sel > 1) {
            D_004A1050.sel = 0;
        }
        D_004A1050.x10 = 0;
        Snd_PlaySe_3_00131600(0x66, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x2000) {
        if (D_004A1050.e[D_004A1050.sel].b0) {
            SaveSys_SetPort_1_001E82A0(D_004A1050.sel);
            if (D_004A1050.e[D_004A1050.sel].b1) {
                MenuProc_Set_1_0018B150(D_004A1020, 0x7A, 0, SaveMenu_Load_0_0018DA20, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A1020);
                D_004A1050.x8 = 0;
                arg0[0xA] = 1;
                arg0[0xB] = 1;
            } else {
                MenuProc_Set_1_0018B150(D_004A1020, 0x78, 2, SaveMenu_CheckCard_0_0018DFB0, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A1020);
                D_004A1050.x8 = 0;
                arg0[0xA] = 1;
                arg0[0xB] = 1;
            }
        } else {
            MenuProc_Set_1_0018B150(D_004A1020, D_004A1050.sel + 0x81, 2, SaveMenu_Retry_0_0018E0B0, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1020);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
        }
        Snd_PlaySe_3_00131600(0x67, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x4000) {
        D_004A1050.xC = 128.0f;
        arg0[8] = MenuStack_Pop_1_00189EA0();
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)(arg0 + 0) = 0x1A;
        Snd_PlaySe_3_00131600(0x69, *(u8 *)(arg0 + 0xE));
    }
    *(s32 *)(arg0 + 4) = 0;
}
#undef MenuProc_Set_1_0018B150
#undef D_004A1050

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_bss.c): D_004A1020 */
s32 D_004A1020[0xc] __attribute__((aligned(4)));
#endif


#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_menu_data.c): D_001F2A50__grp: D_001F2A50@0x0 */
f32 D_001F2A50__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
