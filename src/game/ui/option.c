#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/data.h"
#include "game/sound.h"
#include "game/ui.h"
#include "game/gfx.h"
typedef struct { s32 x0; s32 x4; u8 pad[0x38]; } E_Hud_Draw_0_0018E480;
typedef struct { u32 n; E_Hud_Draw_0_0018E480 *arr; } L;
typedef struct { s32 x0; L *x4; L *x8; L *xC; } R;
typedef struct { u8 r, g, b, a; } Col_Hud_Draw_0_0018E480;
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 idx; u8 pad[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { s32 pad; List *list; } Res;
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; } F_Option_Update_2_0018EAE0;
typedef struct { u8 b0:1; u8 r:7; } G;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9[3]; s8 xC; u8 pD[7]; G x14; } O_Option_Update_2_0018EAE0;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
    u8 padC[2];
    u8 xE;
} Obj18EC40;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9; u8 xA; u8 padB[3]; u8 xE; } Obj;
typedef union { u128 q[2]; s32 w[8]; f32 f[8]; void *p[8]; } Q2_Option_MainMenu_0_0018F940;
typedef struct { s32 *p; s32 n; f32 f; void *fn; void *a; s32 b; void *cb; } Arg_Option_MainMenu_0_0018F940;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 r:2; } F_Option_MainMenu_0_0018F940;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9; s8 xA; u8 pB; s8 xC; u8 xD; u8 xE; } O_Option_MainMenu_0_0018F940;
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad14[0x14]; f32 x28; } Info;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg_Option_Open_0_0018FFE0;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9; s8 xA; u8 pB; s8 xC; } O_Option_Open_0_0018FFE0;
typedef union { u128 q[2]; s32 w[8]; void *p[8]; } Q2_Option_ResetLayoutA_0_00190340;
typedef union { u128 q[2]; s32 w[8]; void *p[8]; f32 f[8]; } Q2_Option_ResetLayoutB_0_00190490;
typedef struct { void *p; s32 n; f32 f; void *fn; void *cb; s32 a; s32 b; } Arg_Option_ResetLayoutB_0_00190490;
typedef struct { f32 m[4]; f32 x; f32 y; } S_OptionProc_DrawKeyAssign_1_001907D0;
typedef union { u32 w; u8 b[4]; } Col_OptionProc_DrawKeyAssign_1_001907D0;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_OptionProc_DrawSound_0_00190A50;
typedef struct {
    u64 a, b;
    f32 x, y;
} S_OptionProc_DrawSound_0_00190A50;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_OptionProc_DrawSound_0_00190A50 x2C;
    f32 x30, x34, x38, x3C;
} A_OptionProc_DrawSound_0_00190A50;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E_OptionProc_DrawSound_0_00190A50;
typedef struct {
    u8 pad0[0x84];
    E_OptionProc_DrawSound_0_00190A50 *x84;
    u8 pad88[0xC];
    E_OptionProc_DrawSound_0_00190A50 *x94;
} P;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} B;
typedef struct {
    u64 a, b;
    f32 x, y;
} S191110;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_OptionProc_DrawSound_0_00190A50 x2C;
    f32 x30, x34, x38, x3C;
} A191110_OptionProc_DrawScreen_0_00190DC0;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E191110;
typedef struct {
    u8 pad0[0x84];
    E191110 *x84;
    u8 pad88[0xC];
    E191110 *x94;
} P191110;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} B191110;
typedef union {
    u32 w;
    f32 f;
    struct { u8 r, g, b, a; } c;
} Col_OptionProc_DrawMain_0_00191420;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_OptionProc_DrawMain_0_00191420 x2C;
    f32 x30, x34, x38, x3C;
} A_OptionProc_DrawMain_0_00191420;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col_OptionProc_DrawSound_0_00190A50 x2C;
    f32 x30, x34, x38, x3C;
} A191110_Option_DrawSliderValue_1_00191580;
extern s32 D_004A10D4[];
extern s32 D_004A10E0[];
extern s32 D_004A10E4[];
extern s32 D_004A10E8[];
extern f32 D_00201D1C;
extern Q D_001F2D80[];
extern Q D_001F2D90[];
extern s32 D_0020212C;
extern u8 D_0020212F;
extern f32 D_004A10D8[];
extern F_Option_Update_2_0018EAE0 D_004A10DC[];
extern u8 D_004A1075[];
extern s32 D_004A10C0[];
extern s32 D_004A10C4[];
extern s32 D_004A10C8[];
extern u8 D_004A1073[];
extern u8 D_004A1077[];
extern u8 D_004A1070[];
extern u8 D_004A1072[];
extern u8 D_004A1078[];
extern u8 D_004A1071[];
extern u8 D_004A1074[];
extern Q2_Option_MainMenu_0_0018F940 D_001F2D10;
extern s32 D_001F2D00[];
extern f32 D_001F2AC0[];
extern s32 D_004A1080[];
extern s32 D_004A1084[];
extern s32 D_004A1088[];
extern s32 D_004A108C[];
extern Q2_Option_MainMenu_0_0018F940 D_001F2CE0;
extern s32 D_001F2CD0[];
extern f32 D_001F2A90[];
extern Q2_Option_ResetLayoutA_0_00190340 D_001F2D60;
#ifndef NONMATCHING
extern f32 D_001F2B00[];
#else
/* data twins (src/game/data/save_menu_data.c): D_001F2B00 */
static f32 D_001F2B00[0x8] = { 0.0f, 5.745e-42f, 0.33f, 5.747e-42f, 0.67f, 5.748e-42f, 1.0f, 5.75e-42f };
#endif
extern s32 D_00201D10;
extern s32 D_00201D18;
extern Q2_Option_ResetLayoutB_0_00190490 D_001F2D40;
extern s32 D_001F2D30[];
#ifndef NONMATCHING
extern f32 D_001F2B20[];
#else
/* data twins (src/game/data/save_menu_data.c): D_001F2B20 */
static f32 D_001F2B20[0x8] = { 1.0f, 5.745e-42f, 1.33f, 5.747e-42f, 1.67f, 5.748e-42f, 2.0f, 5.75e-42f };
#endif
extern s32 D_00201D08;
extern s32 D_00201CF8[2];
extern s32 D_001F2B70[];
extern s32 D_001F2B60[];
extern u8 gStrSoundSetting_001FCE08[];
extern u8 D_001FCE18[];
extern u8 D_001FCE30[];
extern u8 D_001FCE50[];
extern S_OptionProc_DrawKeyAssign_1_001907D0 D_001F2CB0[] __attribute__((aligned(16)));
extern s32 D_001F2BB0[];
extern s8 D_001FCFE8[][13];
extern s32 D_00201D00[2];
extern s32 D_001F2B90[];
extern S_OptionProc_DrawSound_0_00190A50 D_001F2C90 __attribute__((aligned(16)));
extern s32 D_001F2B80[];
extern S191110 D_001F2C70 __attribute__((aligned(16)));
extern s32 D_001F2B50[];
extern S191110 D_001F2C50 __attribute__((aligned(16)));
extern S_OptionProc_DrawSound_0_00190A50 D_001F2C30 __attribute__((aligned(16)));
extern S191110 D_001F2C10 __attribute__((aligned(16)));
extern s8 D_001FD118[];
extern s8 D_001FD120[];
void Option_DrawFrame_0_0018E980(u8 *arg0);
void Option_Update_2_0018EAE0(O_Option_Update_2_0018EAE0 *arg0);
void Option_QuitGame_0_0018EC40(Obj18EC40 *o);
void Option_ScreenSetting_1_0018EDA0(Obj *o);
void Option_ControllerSetting_1_0018F0D0(Obj *o);
void Option_SoundSetting_1_0018F490(Obj *o);
void Option_MainMenu_0_0018F940(O_Option_MainMenu_0_0018F940 *a0);
void Option_Open_0_0018FFE0(O_Option_Open_0_0018FFE0 *p);
void Option_ResetLayoutA_0_00190340(void);
void Option_ResetLayoutB_0_00190490(void);
s32 Option_MapKeyTypeA_0_001905E0(s32 x);
s32 Option_MapKeyTypeB_0_00190630(s32 x);
s32 Option_MapKeyTypeC_0_00190680(s32 x);
s32 Option_MapKeyTypeD_0_001906D0(s32 x);
s32 Option_MapKeyTypeE_0_00190720(s32 x);
s32 Option_MapKeyTypeF_0_00190770(s32 x);
void OptionProc_DrawKeyAssign_1_001907D0(s8 *o, s32 unused, u32 id, s8 *p);
void OptionProc_DrawSound_0_00190A50(A_OptionProc_DrawSound_0_00190A50 *o, s32 unused, u32 kind, B *b);
void OptionProc_DrawScreen_0_00190DC0(A191110_OptionProc_DrawScreen_0_00190DC0 *o, s32 unused, u32 kind, B191110 *b);
void OptionProc_DrawController_0_00191110(A191110_OptionProc_DrawScreen_0_00190DC0 *o, s32 unused, u32 kind, B191110 *b);
void OptionProc_DrawMain_0_00191420(A_OptionProc_DrawMain_0_00191420 *o, s32 unused, u32 kind, B *b);
void Option_DrawSliderValue_1_00191580(A191110_Option_DrawSliderValue_1_00191580 *o, u32 kind, s32 alpha);
R* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawElem_1_00182C10(E_Hud_Draw_0_0018E480 *, s8 *);
s8* Msg_GetText_2_00195B10(s32);
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, u32);
void Menu_DrawFrame_0_00185390(s32, s32, s32, f32);
void Ui_DrawList_1_001829B0(Item *, s32, void *, s32);
void Ui_DrawSpriteRotated_1_00182080(s32, f32, Q *, Q *, void *, s32);
void CreditsProc_DrawText_0_001DCF80(void);
s8 MenuStack_Pop_1_00189EA0(void);
s32 UiAnim_SetTarget_1_0017F470(s32 arg0, s32 arg1, f32 val);
void Snd_PlaySe_3_00131600(s32, u8);
void UiAnim_SetColor_0_0017F890(s32, void *, void *);
void UiAnim_Get_1_0017F840(s32, Info **);
void MenuProc_Run_1_0018B320(s32 *);
void Strm_SetFadeStep_1_001304B0(s32);
void MenuProc_Set_1_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
f32 sinf(f32);
void Option_LerpLayout_0_00191820(void);
void OptionProc_Back_0_00191C40(void);
u32 strlen(s32);
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, void *, s32);
void Text_DrawScaledH_1_001874F0(f32, f32, f32, s32, s32, s32, u32);
void GsPkt_SetReg_3_001543E0(s32, s64);
void sprintf(s8 *, s8 *, ...);

/* Hud_Draw_0_0018E480 */
void Hud_Draw_0_0018E480(void) {
    if (D_004A10D4[0]) {
        D_00201D1C += 0.25f * (-1.0f - D_00201D1C);
    } else {
        D_00201D1C += 0.25f * -D_00201D1C;
    }
    if (!(D_00201D1C <= 0.0f)) {
        D_00201D1C = 0.0f;
    }
    Menu_SetFlags_0_0018A310(4);
    if (D_004A10D4[0] == 1 || D_004A10D4[0] == 2 || D_004A10D4[0] == 3) {
        Menu_SetFlags_0_0018A310(8);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    switch (D_004A10D4[0]) {
    case 0:
        Ui_DrawItemIcon_0_0017F0D0(0, 1, 3, D_004A10E0[0]);
        Ui_DrawItemIcon_0_0017F0D0(0, 1, 3, D_004A10E4[0]);
        Ui_DrawItemIcon_0_0017F0D0(0, 1, 2, D_004A10E8[0]);
        if (D_004A10D4[0] != 5) {
            Col_Hud_Draw_0_0018E480 col;
            *(u32 *)&col = 0x80FFFFFF;
            Text_Draw_2_001875C0(622.0f, 17.0f, 1.0f, Msg_GetText_2_00195B10(D_004A10D0[0] + 0x28), 2, *(u32 *)&col);
        }
        break;
    case 1: {
        u32 i;
        L *l;
        s8 *q;
        Ui_DrawItemIcon_0_0017F0D0(1, 1, 3, D_004A10E0[0]);
        l = MenuLayout_Get_1_00189050(5)->x4;
        q = MenuLayout_GetSub_1_00189020(5);
        for (i = 0; i < l->n; i++) {
            if (l->arr) {
                E_Hud_Draw_0_0018E480 *e = &l->arr[i];
                if (e->x4 == 0x1005) {
                    Ui_DrawElem_1_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col_Hud_Draw_0_0018E480 col;
            *(u32 *)&col = 0x80FFFFFF;
            Text_Draw_2_001875C0(622.0f, 17.0f, 1.0f, Msg_GetText_2_00195B10(D_004A10E0[0] + 0x32), 2, *(u32 *)&col);
        }
        break;
    }
    case 2: {
        u32 i;
        L *l;
        s8 *q;
        Ui_DrawItemIcon_0_0017F0D0(1, 1, 3, D_004A10E4[0]);
        l = MenuLayout_Get_1_00189050(5)->xC;
        q = MenuLayout_GetSub_1_00189020(5);
        for (i = 0; i < l->n; i++) {
            if (l->arr) {
                E_Hud_Draw_0_0018E480 *e = &l->arr[i];
                if (e->x4 == 0x1068) {
                    Ui_DrawElem_1_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col_Hud_Draw_0_0018E480 col;
            *(u32 *)&col = 0x80FFFFFF;
            Text_Draw_2_001875C0(622.0f, 17.0f, 1.0f, Msg_GetText_2_00195B10(D_004A10E4[0] + 0x3C), 2, *(u32 *)&col);
        }
        break;
    }
    case 3: {
        u32 i;
        L *l;
        s8 *q;
        Ui_DrawItemIcon_0_0017F0D0(1, 1, 2, D_004A10E8[0]);
        l = MenuLayout_Get_1_00189050(5)->x8;
        q = MenuLayout_GetSub_1_00189020(5);
        for (i = 0; i < l->n; i++) {
            if (l->arr) {
                E_Hud_Draw_0_0018E480 *e = &l->arr[i];
                if (e->x4 == 0x1068) {
                    Ui_DrawElem_1_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col_Hud_Draw_0_0018E480 col;
            *(u32 *)&col = 0x80FFFFFF;
            Text_Draw_2_001875C0(622.0f, 17.0f, 1.0f, Msg_GetText_2_00195B10(D_004A10E8[0] + 0x46), 2, *(u32 *)&col);
        }
        break;
    }
    case 5:
        Ui_DrawItemIcon_0_0017F0D0(0, 1, 3, D_004A10E0[0]);
        Ui_DrawItemIcon_0_0017F0D0(0, 1, 3, D_004A10E4[0]);
        Ui_DrawItemIcon_0_0017F0D0(0, 1, 2, D_004A10E8[0]);
        break;
    }
    Menu_DrawFrame_0_00185390(1, 4 - D_00202130, D_004A10D0[0], D_00201D1C);
    Menu_DrawBackground_0_00187B20(0);
}

/* Option_DrawFrame_0_0018E980 */
#define MenuLayout_Get_1_00189050 MenuLayout_Get_1_00189050__as_Option_DrawFrame_0_0018E980
Res *MenuLayout_Get_1_00189050__as_Option_DrawFrame_0_0018E980(s32);
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_Option_DrawFrame_0_0018E980
s32 MenuLayout_GetSub_1_00189020__as_Option_DrawFrame_0_0018E980(s32);

void Option_DrawFrame_0_0018E980(u8 *arg0) {
    Q a;
    Q b;
    u32 i;
    List *l;
    s32 base;

    a = D_001F2D80[0];
    b = D_001F2D90[0];
    if (D_00202130 != 0) {
        l = MenuLayout_Get_1_00189050(3)->list;
        base = MenuLayout_GetSub_1_00189020(3);
        for (i = 0; i < l->n; i++) {
            Ui_DrawList_1_001829B0(&l->items[i], base + l->items[i].idx * 8, CreditsProc_DrawText_0_001DCF80, 0);
        }
        Menu_DrawBackground_0_00187B20(0);
        if (arg0[8] == 6) {
            if (D_0020212F < 0xC) {
                D_0020212F = 0;
            } else {
                D_0020212F -= 0xC;
            }
        } else {
            D_0020212F += 0xC;
            if (D_0020212F > 0x60) {
                D_0020212F = 0x60;
            }
        }
        Ui_DrawSpriteRotated_1_00182080(0, 0.0f, &a, &b, &D_0020212C, 0);
        Ui_BeginSprites_1_00181420();
    }
}
#undef MenuLayout_Get_1_00189050
#undef MenuLayout_GetSub_1_00189020

/* Option_Update_2_0018EAE0 */

void Option_Update_2_0018EAE0(O_Option_Update_2_0018EAE0 *arg0) {
    Option_Open_0_0018FFE0(arg0);
    if (arg0->x0 == 0x16) {
        switch (D_004A10D4[0]) {
        case 0:
            if (D_00202130 != 0) {
                arg0->xC = 4;
            } else {
                arg0->xC = 0;
            }
            Option_MainMenu_0_0018F940(arg0);
            break;
        case 1:
            arg0->xC = 1;
            Option_SoundSetting_1_0018F490(arg0);
            break;
        case 2:
            arg0->xC = 2;
            Option_ControllerSetting_1_0018F0D0(arg0);
            break;
        case 3:
            arg0->xC = 3;
            Option_ScreenSetting_1_0018EDA0(arg0);
            break;
        case 4:
            Option_QuitGame_0_0018EC40(arg0);
            break;
        case 5:
            if (!(D_004A10D8[0] <= 12.0f)) {
                if (D_004A10DC[0].b1) {
                    arg0->x14.b0 = 1;
                } else {
                    arg0->x8 = MenuStack_Pop_1_00189EA0();
                    arg0->x4 = 0;
                    arg0->x0 = 0x1A;
                }
                UiAnim_SetVisible_1_0017F7C0(0xD, 0, 0);
            }
            break;
        }
    }
}

/* Option_QuitGame_0_0018EC40 */
#define D_004A10DC D_004A10DC__as_Option_QuitGame_0_0018EC40
extern Flags8 D_004A10DC__as_Option_QuitGame_0_0018EC40[];

void Option_QuitGame_0_0018EC40(Obj18EC40 *o) {
    s32 fl;
    s32 v;
    UiAnim_SetTarget_1_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] <= 10.0f) return;
    fl = o->x4;
    if (fl & 0x2000) {
        Snd_StopAll_1_0012C320();
        Snd_PlaySe_3_00131600(0x69, o->xE);
        o->xA = 2;
        o->xB = 0;
        D_004A10D4[0] = 5;
        D_004A10D8[0] = 0;
        D_004A10DC[0].f.b1 = 1;
        if (D_004A10DC[0].f.b4) {
            v = D_004A1075[0] * 2;
            if (v > 0x7F) v = 0x7F;
            Snd_SetSeVolume_1_0012C720(v);
            Snd_SetFlagEC15_0_0012C6B0();
        } else {
            Snd_SetSeVolume_1_0012C720(0x7F);
        }
    } else if (fl & 0x4000) {
        Snd_PlaySe_3_00131600(0x68, o->xE);
        o->xA = 2;
        o->xB = 0;
        D_00202128 = 2;
        D_004A10D4[0] = 0;
    }
    UiAnim_SetTarget_1_0017F470(0xD, 0, D_004A10D0[0]);
}
#undef D_004A10DC

/* Option_ScreenSetting_1_0018EDA0 */
void Option_ScreenSetting_1_0018EDA0(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;

    cur = D_004A10E8[0];
    old = cur;
    UiAnim_SetTarget_1_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] > 20.0f) {
        UiAnim_SetVisible_1_0017F7C0(0xB, 1, 0);
        UiAnim_SetVisible_1_0017F7C0(0xC, 1, 0);
    } else {
        return;
    }
    if (UiAnim_IsDone_1_0017F3D0(0xB)) {
        b = o->x4;
        switch (D_004A10E8[0]) {
        case 0:
            if (b & 0x20) {
                D_004A1073[0] = !D_004A1073[0];
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                D_004A1073[0] = !D_004A1073[0];
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            break;
        case 1:
            if (b & 0x20) {
                if (D_004A1077[0] < 5) {
                    D_004A1077[0]++;
                } else {
                    D_004A1077[0] = 0;
                }
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1077[0] > 0) {
                    D_004A1077[0]--;
                } else {
                    D_004A1077[0] = 5;
                }
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (UiAnim_SetTarget_1_0017F470(0xB, 1, -4.0f) && UiAnim_SetTarget_1_0017F470(0xC, 1, 0.0f)) {
            Snd_PlaySe_3_00131600(0x68, o->xE);
            D_004A10D4[0] = 0;
            D_00202128 = 2;
            return;
        }
    }
    b = o->x4;
    if (b & 0x10) {
        D_004A10C0[0] = 0;
        cur--;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x10;
    } else if (b & 0x40) {
        D_004A10C0[0] = 0;
        cur++;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x40;
    }
    if (!UiAnim_SetTarget_1_0017F470(0xB, 0, D_004A10E8[0])) {
        D_004A10E8[0] = old;
        return;
    }
    if (D_004A10E8[0] != cur) {
        Snd_PlaySe_3_00131600(0x66, o->xE);
    }
    D_004A10E8[0] = (cur + 2) % 2;
    UiAnim_SetTarget_1_0017F470(0xC, 0, D_004A10E8[0]);
}

/* Option_ControllerSetting_1_0018F0D0 */
void Option_ControllerSetting_1_0018F0D0(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;

    cur = D_004A10E4[0];
    old = cur;
    UiAnim_SetTarget_1_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] > 20.0f) {
        UiAnim_SetVisible_1_0017F7C0(0xB, 1, 0);
        UiAnim_SetVisible_1_0017F7C0(0xC, 1, 0);
    } else {
        return;
    }
    if (UiAnim_IsDone_1_0017F3D0(0xB)) {
        switch (D_004A10E4[0]) {
        case 0:
            if (o->x4 & 0x20) {
                D_004A1078[0] = !D_004A1078[0];
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                D_004A1078[0] = !D_004A1078[0];
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            break;
        case 1:
            if (o->x4 & 0x20) {
                if (D_004A1072[0] < 2) {
                    D_004A1072[0]++;
                } else {
                    D_004A1072[0] = 0;
                }
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1072[0] > 0) {
                    D_004A1072[0]--;
                } else {
                    D_004A1072[0] = 2;
                }
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            break;
        case 2:
            if ((o->x4 & 0x20) && D_004A1070[0] < 0x40) {
                Snd_PlaySe_3_00131600(0x6A, o->xE);
                D_004A1070[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1070[0] > 0) {
                Snd_PlaySe_3_00131600(0x6A, o->xE);
                D_004A1070[0]--;
            }
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (UiAnim_SetTarget_1_0017F470(0xB, 1, -4.0f) && UiAnim_SetTarget_1_0017F470(0xC, 1, 1.0f)) {
            Snd_PlaySe_3_00131600(0x68, o->xE);
            D_004A10D4[0] = 0;
            D_00202128 = 2;
            return;
        }
    }
    b = o->x4;
    if (b & 0x10) {
        D_004A10C0[0] = 0;
        cur--;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x10;
    } else if (b & 0x40) {
        D_004A10C0[0] = 0;
        cur++;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x40;
    }
    if (!UiAnim_SetTarget_1_0017F470(0xB, 0, D_004A10E4[0])) {
        D_004A10E4[0] = old;
        return;
    }
    if (D_004A10E4[0] != cur) {
        Snd_PlaySe_3_00131600(0x66, o->xE);
    }
    D_004A10E4[0] = (cur + 3) % 3;
    UiAnim_SetTarget_1_0017F470(0xC, 0, D_004A10E4[0]);
}

/* Option_SoundSetting_1_0018F490 */
#define D_004A10DC D_004A10DC__as_Option_SoundSetting_1_0018F490
extern Flags8 D_004A10DC__as_Option_SoundSetting_1_0018F490[];

void Option_SoundSetting_1_0018F490(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;
    s32 v;

    cur = D_004A10E0[0];
    old = cur;
    UiAnim_SetTarget_1_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] <= 20.0f) {
        return;
    }
    if (D_004A10DC[0].f.b5) {
        if (Snd_CountActiveVoices_1_0012C1B0()) {
            UiAnim_SetVisible_1_0017F7C0(0xB, 1, 0);
            UiAnim_SetTarget_1_0017F470(0xB, 0, D_004A10E0[0]);
            return;
        }
        D_004A10DC[0].f.b5 = 0;
    }
    if (UiAnim_IsDone_1_0017F3D0(0xB)) {
        switch (D_004A10E0[0]) {
        case 0:
            if (o->x4 & 0x20) {
                D_004A1071[0]++;
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1071[0] > 0) {
                    D_004A1071[0]--;
                } else {
                    D_004A1071[0] = 2;
                }
                Snd_PlaySe_3_00131600(0x6A, o->xE);
            }
            D_004A1071[0] = D_004A1071[0] % 3u;
            switch (D_004A1071[0]) {
            case 0:
                Snd_SetOutputMode_1_0012DA60(0);
                break;
            case 1:
                Snd_SetOutputMode_1_0012DA60(1);
                break;
            case 2:
                Snd_SetOutputMode_1_0012DA60(2);
                break;
            }
            break;
        case 1:
            if ((o->x4 & 0x20) && D_004A1074[0] < 0x40) {
                Snd_PlaySe_3_00131600(0x6A, o->xE);
                D_004A1074[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1074[0] > 0) {
                Snd_PlaySe_3_00131600(0x6A, o->xE);
                D_004A1074[0]--;
            }
            v = D_004A1074[0] * 2;
            if (v > 0x7F) {
                v = 0x7F;
            }
            Snd_SetBgmVolume_1_0012C730(v);
            break;
        case 2:
            if ((o->x4 & 0x20) && D_004A1075[0] < 0x40) {
                Snd_PlaySe_3_00131600(0x6A, o->xE);
                D_004A1075[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1075[0] > 0) {
                Snd_PlaySe_3_00131600(0x6A, o->xE);
                D_004A1075[0]--;
            }
            v = D_004A1075[0] * 2;
            if (v > 0x7F) {
                v = 0x7F;
            }
            Snd_SetSeVolume_1_0012C720(v);
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (UiAnim_SetTarget_1_0017F470(0xB, 1, -4.0f)) {
            Snd_PlaySe_3_00131600(0x68, o->xE);
            D_004A10D4[0] = 0;
            D_00202128 = 2;
            return;
        }
    }
    b = o->x4;
    if (b & 0x10) {
        D_004A10C0[0] = 0;
        cur--;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x10;
    } else if (b & 0x40) {
        D_004A10C0[0] = 0;
        cur++;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x40;
    }
    if (!UiAnim_SetTarget_1_0017F470(0xB, 0, D_004A10E0[0])) {
        D_004A10E0[0] = old;
        return;
    }
    if (cur != D_004A10E0[0]) {
        Snd_PlaySe_3_00131600(0x66, o->xE);
    }
    D_004A10E0[0] = (cur + 3) % 3;
}
#undef D_004A10DC

/* Option_MainMenu_0_0018F940 */
#define UiAnim_SetTarget_1_0017F470 UiAnim_SetTarget_1_0017F470__as_Option_MainMenu_0_0018F940
s32 UiAnim_SetTarget_1_0017F470__as_Option_MainMenu_0_0018F940(f32, s32, s32);
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_004A1090[0x8];
#define D_004A10DC D_004A10DC__as_Option_MainMenu_0_0018F940
extern F_Option_MainMenu_0_0018F940 D_004A10DC__as_Option_MainMenu_0_0018F940[];
static inline void fill(void) {
    Info *p;
    s32 i;
    s32 n;
    UiAnim_Get_1_0017F840(13, &p);
    n = p->x10;
    for (i = 0; i < n; i++) {
        D_004A10B0[i] = p->x28 - i;
    }
}

void Option_MainMenu_0_0018F940(O_Option_MainMenu_0_0018F940 *a0) {
    s32 cur;
    s32 nxt;
    s32 flags;
    s32 v;
    Q2_Option_MainMenu_0_0018F940 q;
    Arg_Option_MainMenu_0_0018F940 a;

    D_004A1088[0] = 0;
    D_004A1080[0] = 0x2B;
    D_004A1084[0] = 3;
    D_004A1090[0] = 1.0f;
    D_004A108C[0] = 0;
    cur = D_004A10D0[0];
    nxt = cur;
    if (!D_004A10DC[0].b3) {
        flags = a0->x4;
        if (flags & 0x2000) {
            Snd_PlaySe_3_00131600(0x67, a0->xE);
            switch (D_004A10D0[0]) {
            case 0:
                D_004A10D4[0] = 1;
                D_004A10E0[0] = 0;
                q = D_001F2D10;
                a.p = D_001F2D00;
                a.n = 3;
                a.fn = Option_MapKeyTypeE_0_00190720;
                a.a = Option_MapKeyTypeB_0_00190630;
                a.b = 0;
                a.cb = 0;
                a.f = D_001F2AC0[0];
                UiAnim_SetColor_0_0017F890(11, &q, &a);
                UiAnim_SetTarget_1_0017F470(0.0f, 11, 0);
                UiAnim_SetVisible_1_0017F7C0(11, 0, 0);
                D_004A10DC[0].b4 = 1;
                D_004A10DC[0].b5 = 1;
                v = D_004A1075[0] * 2;
                if (v > 0x7F) v = 0x7F;
                Snd_SetAllPortVolume_0_0012C6C0(0x7F);
                Snd_SetSeVolume_1_0012C720(v);
                break;
            case 1:
                D_004A10D4[0] = 2;
                D_004A10E4[0] = 0;
                Option_ResetLayoutB_0_00190490();
                break;
            case 2:
                D_004A10D4[0] = 3;
                D_004A10E8[0] = 0;
                Option_ResetLayoutA_0_00190340();
                break;
            case 3:
                D_004A10D4[0] = 4;
                MenuProc_Run_1_0018B320(D_004A1080);
                a0->xA = 1;
                break;
            }
            D_004A10D8[0] = 0.0f;
            if (D_00202128 == 0) fill();
            D_00202128 = 1;
            return;
        } else if (flags & 0x4000) {
            Snd_PlaySe_3_00131600(0x69, a0->xE);
            D_004A10D8[0] = 0.0f;
            D_004A10D4[0] = 5;
            if (D_00202128 == 0) fill();
            D_00202128 = 3;
            UiAnim_SetVisible_1_0017F7C0(13, 0, 1);
            Strm_SetFadeStep_1_001304B0(-0x666);
            if (D_004A10DC[0].b4) {
                v = D_004A1075[0] * 2;
                if (v > 0x7F) v = 0x7F;
                Snd_SetSeVolume_1_0012C720(v);
                Snd_SetFlagEC15_0_0012C6B0();
            } else {
                Snd_SetSeVolume_1_0012C720(0x7F);
            }
            return;
        } else if (flags & 0x10) {
            if (D_00202128 == 0) {
                nxt = cur - 1;
                a0->x4 = flags & ~0x10;
            }
        } else if (flags & 0x40) {
            if (D_00202128 == 0) {
                nxt = cur + 1;
                a0->x4 = flags & ~0x40;
            }
        }
    }
    if (!UiAnim_SetTarget_1_0017F470(*(volatile s32 *)D_004A10D0, 13, 0)) {
        D_004A10D0[0] = cur;
        return;
    }
    if (nxt != D_004A10D0[0]) Snd_PlaySe_3_00131600(0x66, a0->xE);
    v = 4 - D_00202130;
    D_004A10D0[0] = (nxt + v) % v;
}
#undef UiAnim_SetTarget_1_0017F470
#undef D_004A10DC

/* Option_Open_0_0018FFE0 */
#define UiAnim_SetTarget_1_0017F470 UiAnim_SetTarget_1_0017F470__as_Option_Open_0_0018FFE0
void UiAnim_SetTarget_1_0017F470__as_Option_Open_0_0018FFE0(f32, s32, s32);
#define D_004A10C4 D_004A10C4__as_Option_Open_0_0018FFE0
extern f32 D_004A10C4__as_Option_Open_0_0018FFE0[];
#define D_004A10C8 D_004A10C8__as_Option_Open_0_0018FFE0
extern f32 D_004A10C8__as_Option_Open_0_0018FFE0[];
#define D_004A10DC D_004A10DC__as_Option_Open_0_0018FFE0
extern F_Option_MainMenu_0_0018F940 D_004A10DC__as_Option_Open_0_0018FFE0[];

void Option_Open_0_0018FFE0(O_Option_Open_0_0018FFE0 *p) {
    Q2_Option_MainMenu_0_0018F940 q;
    Arg_Option_Open_0_0018FFE0 a;

    switch (p->x0) {
    case 0x19:
        D_004A10D8[0] = 0.0f;
        D_004A10D4[0] = 0;
        D_004A10D0[0] = 1;
        D_004A10C0[0] = 0;
        D_004A10C8[0] = 0.0f;
        D_004A10C4[0] = 0.0f;
        D_004A10DC[0].b2 = 0;
        D_004A10DC[0].b1 = 0;
        D_004A10DC[0].b4 = 0;
        D_004A10DC[0].b5 = 1;
        D_00202128 = 0;
        q = D_001F2CE0;
        q.f[5] = D_001F2A90[0];
        a.p = D_001F2CD0;
        a.n = 4 - D_00202130;
        a.fn = Option_MapKeyTypeF_0_00190770;
        a.f = D_001F2A90[0];
        a.a = 0;
        a.b = 0;
        a.cb = Option_LerpLayout_0_00191820;
        UiAnim_SetColor_0_0017F890(13, &q, &a);
        UiAnim_SetTarget_1_0017F470(0.0f, 13, 0);
        UiAnim_SetVisible_1_0017F7C0(13, 0, 1);
        if (D_00202130) {
            MenuProc_Set_1_0018B150(1.0f, D_004A1080, 0x2C, 2, OptionProc_Back_0_00191C40, 0);
            MenuProc_Run_1_0018B320(D_004A1080);
            D_004A10DC[0].b3 = 1;
            p->xA = 1;
        }
        if (D_00202130) {
            p->xC = 4;
        } else {
            p->xC = 0;
        }
        break;
    case 0x1B:
        break;
    case 0:
        UiAnim_SetVisible_1_0017F7C0(13, 1, 1);
        break;
    case 0x16:
        break;
    case 0x1A:
        break;
    case 0x1C:
        break;
    case 0x1E:
        Strm_Stop_2_00130440();
        break;
    }
    D_004A10D8[0] += 1.0f;
    D_004A10C0[0] += 5;
    D_004A10C0[0] %= 180;
    D_004A10C4[0] = 10.0f * sinf(3.1415927f * D_004A10C0[0] / 180.0f);
    D_004A10C8[0] = -10.0f * sinf(3.1415927f * D_004A10C0[0] / 180.0f);
}
#undef UiAnim_SetTarget_1_0017F470
#undef D_004A10C4
#undef D_004A10C8
#undef D_004A10DC

/* Option_ResetLayoutA_0_00190340 */
#define UiAnim_SetTarget_1_0017F470 UiAnim_SetTarget_1_0017F470__as_Option_ResetLayoutA_0_00190340
void UiAnim_SetTarget_1_0017F470__as_Option_ResetLayoutA_0_00190340(f32, s32, s32);

void Option_ResetLayoutA_0_00190340(void) {
    Q2_Option_ResetLayoutA_0_00190340 q;
    Arg_Option_Open_0_0018FFE0 a;

    q = D_001F2D60;
    a.p = &D_00201D10;
    a.n = 2;
    a.fn = Option_MapKeyTypeC_0_00190680;
    a.f = D_001F2AC0[0];
    a.a = 0;
    a.b = 0;
    a.cb = 0;
    UiAnim_SetColor_0_0017F890(11, &q, &a);
    UiAnim_SetTarget_1_0017F470(0.0f, 11, 0);
    UiAnim_SetVisible_1_0017F7C0(11, 0, 0);
    q.w[5] = 0;
    q.p[7] = OptionProc_DrawKeyAssign_1_001907D0;
    q.w[2] = 8;
    q.p[3] = D_001F2B00;
    q.w[4] = 4;
    a.p = &D_00201D18;
    a.n = 1;
    a.fn = 0;
    a.f = D_001F2B00[0];
    a.a = 0;
    UiAnim_SetColor_0_0017F890(12, &q, &a);
    UiAnim_SetTarget_1_0017F470(1.0f, 12, 0);
    UiAnim_SetVisible_1_0017F7C0(12, 0, 0);
}
#undef UiAnim_SetTarget_1_0017F470

/* Option_ResetLayoutB_0_00190490 */
#define UiAnim_SetTarget_1_0017F470 UiAnim_SetTarget_1_0017F470__as_Option_ResetLayoutB_0_00190490
void UiAnim_SetTarget_1_0017F470__as_Option_ResetLayoutB_0_00190490(f32, s32, s32);

void Option_ResetLayoutB_0_00190490(void) {
    Q2_Option_ResetLayoutB_0_00190490 q;
    Arg_Option_ResetLayoutB_0_00190490 a;

    q = D_001F2D40;
    a.p = D_001F2D30;
    a.n = 3;
    a.fn = Option_MapKeyTypeD_0_001906D0;
    a.f = D_001F2AC0[0];
    a.cb = Option_MapKeyTypeA_0_001905E0;
    a.a = 0;
    a.b = 0;
    UiAnim_SetColor_0_0017F890(11, &q, &a);
    UiAnim_SetTarget_1_0017F470(0.0f, 11, 0);
    UiAnim_SetVisible_1_0017F7C0(11, 0, 0);
    q.w[2] = 8;
    q.f[5] = 1.0f;
    q.p[3] = D_001F2B20;
    q.w[4] = 4;
    a.p = &D_00201D08;
    a.n = 1;
    a.fn = 0;
    a.f = D_001F2B20[0];
    a.cb = 0;
    UiAnim_SetColor_0_0017F890(12, &q, &a);
    UiAnim_SetTarget_1_0017F470(1.0f, 12, 0);
    UiAnim_SetVisible_1_0017F7C0(12, 0, 0);
}
#undef UiAnim_SetTarget_1_0017F470

/* Option_MapKeyTypeA_0_001905E0 */
s32 Option_MapKeyTypeA_0_001905E0(s32 x)
{
    switch (x) {
    case 0:
    case 1:
        return 4;
    case 2:
        return 0;
    }
    return 0;
}

/* Option_MapKeyTypeB_0_00190630 */
s32 Option_MapKeyTypeB_0_00190630(s32 x)
{
    switch (x) {
    case 0:
        return 0;
    case 1:
    case 2:
        return 8;
    }
    return 0;
}

/* Option_MapKeyTypeC_0_00190680 */
s32 Option_MapKeyTypeC_0_00190680(s32 x)
{
    switch (x) {
    case 0:
    case 1:
        return D_00201CF8[x];
    }
    return 0;
}

/* Option_MapKeyTypeD_0_001906D0 */
s32 Option_MapKeyTypeD_0_001906D0(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
        return D_001F2B70[x];
    }
    return 0;
}

/* Option_MapKeyTypeE_0_00190720 */
s32 Option_MapKeyTypeE_0_00190720(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
        return D_001F2B60[x];
    }
    return 0;
}

/* Option_MapKeyTypeF_0_00190770 */
#pragma explicit_zero_data on
s32 D_001F2B40[0x4] = { (s32)gStrSoundSetting_001FCE08, (s32)D_001FCE18, (s32)D_001FCE30, (s32)D_001FCE50 };

s32 Option_MapKeyTypeF_0_00190770(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
    case 3:
        return D_001F2B40[x];
    }
    return 0;
}

/* OptionProc_DrawKeyAssign_1_001907D0 */
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_OptionProc_DrawKeyAssign_1_001907D0
void Text_Draw_2_001875C0__as_OptionProc_DrawKeyAssign_1_001907D0(f32, f32, f32, s32, s32, u32);

void OptionProc_DrawKeyAssign_1_001907D0(s8 *o, s32 unused, u32 id, s8 *p) {
    S_OptionProc_DrawKeyAssign_1_001907D0 t __attribute__((aligned(16)));
    Col_OptionProc_DrawKeyAssign_1_001907D0 col;
    s32 k;
    s32 dx;
    s32 *str;
    f32 sc;
    s32 on;

    on = *(s32 *)(p + 8);
    t = D_001F2CB0[0];
    if (on != 0) {
        if (id < 200) {
            t.x = *(f32 *)(o + 0x30);
            t.y = *(f32 *)(o + 0x34);
            Ui_DrawSprite_2_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
        } else if (id == 301) {
            if (D_004A1077[0] == 0 || D_004A1077[0] == 1) {
                t.x = *(f32 *)(o + 0x30);
                t.y = *(f32 *)(o + 0x34);
                Ui_DrawSprite_2_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
            }
        } else if (id == 300) {
            if ((u32)(D_004A1077[0] - 2) <= 2 || D_004A1077[0] == 5) {
                t.x = *(f32 *)(o + 0x30);
                t.y = *(f32 *)(o + 0x34);
                Ui_DrawSprite_2_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
            }
        } else {
            k = D_001FCFE8[D_004A1077[0]][id];
            dx = -2;
            if (k == 16) {
                sc = 0.95f;
            } else {
                sc = 1.0f;
            }
            col.w = 0x80808080;
            col.b[3] = *(u8 *)(o + 0x2F) * 2;
            *(f32 *)(o + 0x3C) += 1.0f;
            str = &D_001F2BB0[k];
            if (strlen(*str) > 8) {
                if (k == 1) {
                    dx = -3;
                }
                if (k == 4 || k == 5) {
                    dx = -7;
                }
                Text_DrawScaledH_1_001874F0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), sc, dx, *str, 1, col.w);
            } else {
                Text_Draw_2_001875C0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), 1.0f, *str, 1, col.w);
            }
        }
    }
}
#undef Text_Draw_2_001875C0

/* OptionProc_DrawSound_0_00190A50 */
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_OptionProc_DrawSound_0_00190A50
P *MenuLayout_GetSub_1_00189020__as_OptionProc_DrawSound_0_00190A50(s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_OptionProc_DrawSound_0_00190A50
void Text_Draw_2_001875C0__as_OptionProc_DrawSound_0_00190A50(f32, s32, f32, f32, u32, u32);
#define D_004A10C4 D_004A10C4__as_OptionProc_DrawSound_0_00190A50
extern f32 D_004A10C4__as_OptionProc_DrawSound_0_00190A50[];
#define D_004A10C8 D_004A10C8__as_OptionProc_DrawSound_0_00190A50
extern f32 D_004A10C8__as_OptionProc_DrawSound_0_00190A50[];

void OptionProc_DrawSound_0_00190A50(A_OptionProc_DrawSound_0_00190A50 *o, s32 unused, u32 kind, B *b) {
    Col_OptionProc_DrawSound_0_00190A50 col;
    S_OptionProc_DrawSound_0_00190A50 s __attribute__((aligned(16)));
    s32 h;
    s32 r;
    E_OptionProc_DrawSound_0_00190A50 *e;

    h = b->x8;
    s = D_001F2C90;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = 0x40;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            col = o->x2C;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, 0);
            return;
        }
        r = UiAnim_IsDone_1_0017F3D0(0xB);
        switch (kind) {
        case 0xC8:
            if (b->x4 == 0xFA4) {
                e = MenuLayout_GetSub_1_00189020(0)->x94;
                s.x = o->x38;
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &o->x2C, &s, 0);
            }
            break;
        case 0xC9:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            Text_Draw_2_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
            break;
        case 0xCA:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            if (b->x0 == 0) {
                Text_Draw_2_001875C0(o->x38, D_00201D00[!D_004A1073[0]], o->x3C, 0.83333331f, 1, col.w);
            } else if (b->x0 == 1) {
                Text_Draw_2_001875C0(o->x38, D_001F2B90[D_004A1077[0]], o->x3C, 0.83333331f, 1, col.w);
            }
            break;
        case 0xCB:
            if (r != 0 && b->x4 == 0xFA4) {
                e = &MenuLayout_GetSub_1_00189020(0)->x84[1];
                s.x = o->x38 + D_004A10C8[0];
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0xCC:
            if (r != 0 && b->x4 == 0xFA4) {
                e = MenuLayout_GetSub_1_00189020(0)->x84;
                s.x = o->x38 + D_004A10C4[0];
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0x190:
            s.x = o->x30;
            s.y = o->x34;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            break;
        }
    }
}
#undef MenuLayout_GetSub_1_00189020
#undef Text_Draw_2_001875C0
#undef D_004A10C4
#undef D_004A10C8

/* OptionProc_DrawScreen_0_00190DC0 */
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_OptionProc_DrawScreen_0_00190DC0
P191110 *MenuLayout_GetSub_1_00189020__as_OptionProc_DrawScreen_0_00190DC0(s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_OptionProc_DrawScreen_0_00190DC0
void Text_Draw_2_001875C0__as_OptionProc_DrawScreen_0_00190DC0(f32, s32, f32, f32, u32, u32);
#define D_004A10C4 D_004A10C4__as_OptionProc_DrawScreen_0_00190DC0
extern f32 D_004A10C4__as_OptionProc_DrawScreen_0_00190DC0[];
#define D_004A10C8 D_004A10C8__as_OptionProc_DrawScreen_0_00190DC0
extern f32 D_004A10C8__as_OptionProc_DrawScreen_0_00190DC0[];

void OptionProc_DrawScreen_0_00190DC0(A191110_OptionProc_DrawScreen_0_00190DC0 *o, s32 unused, u32 kind, B191110 *b) {
    Col_OptionProc_DrawSound_0_00190A50 col;
    S191110 s __attribute__((aligned(16)));
    s32 h;
    s32 alpha;
    s32 r;
    E191110 *e;

    h = b->x8;
    s = D_001F2C70;
    alpha = 0x40;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = alpha;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            return;
        }
        if (b->x0 == 2) {
            alpha = D_004A1070[0];
        }
        r = UiAnim_IsDone_1_0017F3D0(0xB);
        switch (kind) {
        case 0xC8:
            if (b->x4 == 0xFA4) {
                e = MenuLayout_GetSub_1_00189020(0)->x94;
                s.x = o->x38;
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &o->x2C, &s, 0);
            }
            break;
        case 0xC9:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            Text_Draw_2_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
            break;
        case 0xCA:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            if (b->x0 == 0) {
                Text_Draw_2_001875C0(o->x38, D_00201D00[!D_004A1078[0]], o->x3C, 0.83333331f, 1, col.w);
            } else if (b->x0 == 1) {
                Text_Draw_2_001875C0(o->x38, D_001F2B80[D_004A1072[0]], o->x3C, 0.83333331f, 1, col.w);
            }
            break;
        case 0xCB:
            if (r != 0 && b->x4 == 0xFA4) {
                e = &MenuLayout_GetSub_1_00189020(0)->x84[1];
                s.x = o->x38 + D_004A10C8[0];
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0xCC:
            if (r != 0 && b->x4 == 0xFA4) {
                e = MenuLayout_GetSub_1_00189020(0)->x84;
                s.x = o->x38 + D_004A10C4[0];
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        }
        Option_DrawSliderValue_1_00191580(o, kind, alpha);
    }
}
#undef MenuLayout_GetSub_1_00189020
#undef Text_Draw_2_001875C0
#undef D_004A10C4
#undef D_004A10C8

/* OptionProc_DrawController_0_00191110 */
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_OptionProc_DrawController_0_00191110
P191110 *MenuLayout_GetSub_1_00189020__as_OptionProc_DrawController_0_00191110(s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_OptionProc_DrawController_0_00191110
void Text_Draw_2_001875C0__as_OptionProc_DrawController_0_00191110(f32, s32, f32, f32, u32, u32);
#define D_004A10C4 D_004A10C4__as_OptionProc_DrawController_0_00191110
extern f32 D_004A10C4__as_OptionProc_DrawController_0_00191110[];
#define D_004A10C8 D_004A10C8__as_OptionProc_DrawController_0_00191110
extern f32 D_004A10C8__as_OptionProc_DrawController_0_00191110[];

void OptionProc_DrawController_0_00191110(A191110_OptionProc_DrawScreen_0_00190DC0 *o, s32 unused, u32 kind, B191110 *b) {
    Col_OptionProc_DrawSound_0_00190A50 col;
    S191110 s __attribute__((aligned(16)));
    s32 h;
    s32 alpha;
    s32 r;
    E191110 *e;

    h = b->x8;
    s = D_001F2C50;
    alpha = 0x40;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = alpha;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            return;
        }
        if (b->x0 == 1) {
            alpha = D_004A1074[0];
        }
        if (b->x0 == 2) {
            alpha = D_004A1075[0];
        }
        r = UiAnim_IsDone_1_0017F3D0(0xB);
        switch (kind) {
        case 0xC8:
            if (b->x4 == 0xFA4) {
                e = MenuLayout_GetSub_1_00189020(0)->x94;
                s.x = o->x38;
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &o->x2C, &s, 0);
            }
            break;
        case 0xC9:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            Text_Draw_2_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
            break;
        case 0xCA:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            Text_Draw_2_001875C0(o->x38, D_001F2B50[D_004A1071[0]], o->x3C, 0.83333331f, 1, col.w);
            break;
        case 0xCB:
            if (r != 0 && b->x4 == 0xFA4) {
                e = &MenuLayout_GetSub_1_00189020(0)->x84[1];
                s.x = o->x38 + D_004A10C8[0];
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0xCC:
            if (r != 0 && b->x4 == 0xFA4) {
                e = MenuLayout_GetSub_1_00189020(0)->x84;
                s.x = o->x38 + D_004A10C4[0];
                s.y = o->x3C;
                Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        }
        Option_DrawSliderValue_1_00191580(o, kind, alpha);
    }
}
#undef MenuLayout_GetSub_1_00189020
#undef Text_Draw_2_001875C0
#undef D_004A10C4
#undef D_004A10C8

/* OptionProc_DrawMain_0_00191420 */
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_OptionProc_DrawMain_0_00191420
void Text_Draw_2_001875C0__as_OptionProc_DrawMain_0_00191420(f32, s32, f32, f32, u32, u32);

void OptionProc_DrawMain_0_00191420(A_OptionProc_DrawMain_0_00191420 *o, s32 unused, u32 kind, B *b) {
    S_OptionProc_DrawSound_0_00190A50 s __attribute__((aligned(16)));
    Col_OptionProc_DrawMain_0_00191420 col;
    s32 h;

    h = b->x8;
    s = D_001F2C30;
    if (h == 0) return;
    if (kind < 200) {
        s.x = o->x30;
        s.y = o->x34;
        col = o->x2C;
        if (D_004A10D4[0] != 0 && b->x4 == 0xFA2) {
            col.c.r = col.c.g = col.c.b = 0x40;
        }
        Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    }
    switch (kind) {
    case 200:
        col.w = 0x80808080;
        col.c.a = o->x2C.c.a * 2;
        o->x3C += 4.0f;
        if (strlen(h) < 16) {
            o->x3C += 9.0f;
        }
        Text_Draw_2_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
        break;
    }
}
#undef Text_Draw_2_001875C0

/* Option_DrawSliderValue_1_00191580 */
#define Text_DrawScaledH_1_001874F0 Text_DrawScaledH_1_001874F0__as_Option_DrawSliderValue_1_00191580
void Text_DrawScaledH_1_001874F0__as_Option_DrawSliderValue_1_00191580(f32, f32, f32, s32, s8 *, s32, u32);

void Option_DrawSliderValue_1_00191580(A191110_Option_DrawSliderValue_1_00191580 *o, u32 kind, s32 alpha) {
    Col_OptionProc_DrawSound_0_00190A50 col;
    S191110 s __attribute__((aligned(16)));
    Vec v10;
    Vec v0;
    s8 buf[0x400];
    f32 f;

    s = D_001F2C10;
    switch (kind) {
    case 0xCD:
        col.c.b = 0x40;
        col.c.r = 0x40;
        col.c.a = 0x40;
        f = 0.015625f * alpha;
        col.c.g = 0x60;
        Menu_DrawBackground_0_00187B20(0);
        Ui_BeginSprites_1_00181420();
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x48);
        GsPkt_Flush_1_001544C0();
        s.x = o->x30;
        s.y = o->x34;
        v10 = o->v10;
        v0 = o->v0;
        o->v10.z = o->v10.z * f;
        o->v0.z = v0.x + f * (v0.z - v0.x);
        Ui_DrawSprite_2_00181680(o->x28, &o->v0, &o->v10, &col, &s, 0);
        o->v10 = v10;
        o->v0 = v0;
        Menu_DrawBackground_0_00187B20(0);
        Ui_BeginSprites_1_00181420();
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x44);
        GsPkt_Flush_1_001544C0();
        break;
    case 0xCE:
        s.x = o->x30;
        s.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, 0);
        break;
    case 0xCF:
        col.c.r = 0x80 - alpha;
        col.c.g = alpha + 0x80;
        col.c.b = alpha + 0x80;
        col.c.a = o->x2C.c.a * 2;
        if (alpha < 0x40) {
            sprintf(buf, D_001FD118);
        } else {
            sprintf(buf, D_001FD120);
        }
        Text_DrawScaledH_1_001874F0(o->x38, o->x3C, 0.83333331f, -1, buf, 0, col.w);
        Menu_DrawBackground_0_00187B20(0);
        break;
    }
}
#undef Text_DrawScaledH_1_001874F0

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 gStrMono_001FCE60[];
extern u8 gStrStereo_001FCE68[];
extern u8 D_001FCE70[];
extern u8 gStrSound_001FCE88[];
extern u8 D_001FCE90[];
extern u8 D_001FCEA0[];
extern u8 D_001FCEB0[];
extern u8 gStrScreenRatio_001FCEC0[];
extern u8 D_001FCED0[];
extern u8 D_001FCEE0[];
extern u8 gStr169_001FCEE8[];
extern u8 D_001FCEF0[];
extern u8 D_001FCF20[];
extern u8 D_001FCF30[];
extern u8 D_001FCF40[];
extern u8 D_001FCF50[];
extern u8 D_001FCF68[];
extern u8 D_001FCF80[];
extern u8 D_001FCF98[];
extern u8 D_001FCFA0[];
extern u8 D_001FCFB0[];
extern u8 D_001FCFC0[];
extern u8 D_001FCFC8[];
extern u8 D_001FCFD8[];
extern u8 D_001FCFF0[];
extern u8 D_001FCFF8[];
extern u8 D_001FD000[];
extern u8 D_001FD010[];
extern u8 D_001FD020[];
extern u8 D_001FD030[];
extern u8 D_001FD040[];
extern u8 D_001FD048[];
extern u8 D_001FD050[];
extern u8 D_001FD058[];
extern u8 D_001FD068[];
extern u8 D_001FD078[];
extern u8 D_001FD088[];
extern u8 D_001FD090[];
/* data twins (src/game/data/option_lerp_data.c): D_001F2B50, D_001F2B60, D_001F2B70, D_001F2B80, D_001F2B90, D_001F2BB0, D_001F2CD0, D_001F2D00, D_001F2D30 */
s32 D_001F2B50[0x4] = { (s32)gStrMono_001FCE60, (s32)gStrStereo_001FCE68, (s32)D_001FCE70, 0 };
s32 D_001F2B60[0x4] = { (s32)gStrSound_001FCE88, (s32)D_001FCE90, (s32)D_001FCEA0, 0 };
s32 D_001F2B70[0x4] = { (s32)D_001FCEB0, (s32)gStrScreenRatio_001FCEC0, (s32)D_001FCED0, 0 };
s32 D_001F2B80[0x4] = { (s32)D_001FCEE0, (s32)gStr169_001FCEE8, (s32)D_001FCEF0, 0 };
s32 D_001F2B90[0x8] = { (s32)D_001FCF20, (s32)D_001FCF30, (s32)D_001FCF40, (s32)D_001FCF50, (s32)D_001FCF68, (s32)D_001FCF80, 0, 0 };
s32 D_001F2BB0[0x18] = { (s32)D_001FCF98, (s32)D_001FCFA0, (s32)D_001FCFB0, (s32)D_001FCFC0, (s32)D_001FCFC8, (s32)D_001FCFD8, (s32)D_001FCFE8, (s32)D_001FCFF0, (s32)D_001FCFF8, (s32)D_001FD000, (s32)D_001FD010, (s32)D_001FD020, (s32)D_001FD030, (s32)D_001FD040, (s32)D_001FD048, (s32)D_001FD050, (s32)D_001FD058, (s32)D_001FD068, (s32)D_001FD050, (s32)D_001FD078, (s32)D_001FD088, (s32)D_001FD090, 0, 0 };
s32 D_001F2CD0[0x4] = { 0, 1, 2, 3 };
s32 D_001F2D00[0x4] = { 0, 1, 2, 0 };
s32 D_001F2D30[0x4] = { 0, 1, 2, 0 };
/* data twins (src/game/data/option_rodata.c): gStrSoundSetting_001FCE08, D_001FCE18, D_001FCE30, D_001FCE50 */
u8 gStrSoundSetting_001FCE08[0xe] = "SOUND SETTING\000";
u8 D_001FCE18[0x18] __attribute__((aligned(8))) = "SCREEN SETTING\000\000\000\000\000\000\000\000\000\000";
u8 D_001FCE30[0x1d] __attribute__((aligned(8))) = "CONTROLLER\012          SETTING\000";
u8 D_001FCE50[0x10] __attribute__((aligned(8))) = "QUIT GAME\000\000\000\000\000\000\000";
/* data twins (src/game/data/option_rodata2.c): D_001FD118, D_001FD120 */
s8 D_001FD118[0x8] = "%d\000\000\000\000\000\000";
s8 D_001FD120[0x8] = "MAX\000\000\000\000\000";
/* data twins (src/game/data/sdata.c): D_00201CF8, D_00201D00, D_00201D08, D_00201D18, D_00201D1C */
s32 D_00201CF8[0x2] = { (s32)((u8 *)D_001FCEF0 + 0x10), (s32)((u8 *)D_001FCEF0 + 0x20) };
s32 D_00201D00[0x2] = { (s32)((u8 *)D_001FD090 + 0x8), (s32)((u8 *)D_001FD090 + 0x10) };
s32 D_00201D08 = 2;
s32 D_00201D18 = 1;
f32 D_00201D1C = -1.0f;
/* data twins (src/game/data/sbss.c): D_00202128, D_0020212C, D_00202130 */
s32 D_00202128;
s32 D_0020212C;
s32 D_00202130;
/* data twins (src/game/data/load_menu_bss.c): D_004A10C0, D_004A10C4, D_004A10C8, D_004A10D0, D_004A10D4, D_004A10D8, D_004A10DC, D_004A10E0, D_004A10E4, D_004A10E8 */
s32 D_004A10C0[0x1];
s32 D_004A10C4[0x1];
s32 D_004A10C8[0x2];
s32 D_004A10D0[0x1];
s32 D_004A10D4[0x1];
f32 D_004A10D8[0x1];
F_Option_Update_2_0018EAE0 D_004A10DC[0x4 / sizeof(F_Option_Update_2_0018EAE0)];
s32 D_004A10E0[0x1];
s32 D_004A10E4[0x1];
s32 D_004A10E8[0x2];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_rodata.c): gStrMono_001FCE60, gStrStereo_001FCE68, D_001FCE70, gStrSound_001FCE88, D_001FCE90, D_001FCEA0, D_001FCEB0, gStrScreenRatio_001FCEC0, D_001FCED0, D_001FCEF0 */
u8 gStrMono_001FCE60[0x5] = "MONO\000";
u8 gStrStereo_001FCE68[0x7] = "STEREO\000";
u8 D_001FCE70[0x18] __attribute__((aligned(8))) = "Dolby ProLogic II\000\000\000\000\000\000\000";
u8 gStrSound_001FCE88[0x6] = "SOUND\000";
u8 D_001FCE90[0x10] __attribute__((aligned(8))) = "BGM VOLUME\000\000\000\000\000\000";
u8 D_001FCEA0[0x10] __attribute__((aligned(8))) = "SE VOLUME\000\000\000\000\000\000\000";
u8 D_001FCEB0[0x10] __attribute__((aligned(8))) = "MOVE EFFECT\000\000\000\000\000";
u8 gStrScreenRatio_001FCEC0[0xd] = "SCREEN RATIO\000";
u8 D_001FCED0[0x10] __attribute__((aligned(8))) = "BRIGHTNESS\000\000\000\000\000\000";
u8 D_001FCEF0[0x30] __attribute__((aligned(8))) = "16:9(LB)\000\000\000\000\000\000\000\000VIBRATION\000\000\000\000\000\000\000KEY ASSIGN\000\000\000\000\000\000";
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_rodata.c): D_001FCF20 */
u8 D_001FCF20[0x10] __attribute__((aligned(8))) = { 0x83, 0x5e, 0x83, 0x43, 0x83, 0x76, 0x82, 0x50, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_rodata.c): D_001FCF30 */
u8 D_001FCF30[0x10] __attribute__((aligned(8))) = { 0x83, 0x5e, 0x83, 0x43, 0x83, 0x76, 0x82, 0x51, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_rodata.c): D_001FCF40 */
u8 D_001FCF40[0x10] __attribute__((aligned(8))) = { 0x83, 0x5e, 0x83, 0x43, 0x83, 0x76, 0x82, 0x52, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2C10__grp: D_001F2C10@0x0 */
f32 D_001F2C10__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2C30__grp: D_001F2C30@0x0 */
f32 D_001F2C30__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2C50__grp: D_001F2C50@0x0 */
f32 D_001F2C50__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2C70__grp: D_001F2C70@0x0 */
f32 D_001F2C70__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2C90__grp: D_001F2C90@0x0 */
f32 D_001F2C90__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2CB0__grp: D_001F2CB0@0x0 */
f32 D_001F2CB0__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2CE0__grp: D_001F2CE0@0x0 */
s32 D_001F2CE0__grp[0x8] __attribute__((aligned(16))) = { 5, 0, 0, (s32)D_001F2A90, 5, 0, 0, (s32)OptionProc_DrawMain_0_00191420 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2D10__grp: D_001F2D10@0x0 */
s32 D_001F2D10__grp[0x8] __attribute__((aligned(16))) = { 5, 1, 0, (s32)D_001F2AC0, 8, 0, 0, (s32)OptionProc_DrawController_0_00191110 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2D40__grp: D_001F2D40@0x0 */
s32 D_001F2D40__grp[0x8] __attribute__((aligned(16))) = { 5, 3, 0, (s32)D_001F2AC0, 8, 0, 0, (s32)OptionProc_DrawScreen_0_00190DC0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2D60__grp: D_001F2D60@0x0 */
s32 D_001F2D60__grp[0x8] __attribute__((aligned(16))) = { 5, 2, 0, (s32)D_001F2AC0, 8, 0, 0, (s32)OptionProc_DrawSound_0_00190A50 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2D80__grp: D_001F2D80@0x0 */
f32 D_001F2D80__grp[0x4] __attribute__((aligned(16))) = { 0.0f, 0.0f, 640.0f, 480.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_lerp_data.c): D_001F2D90__grp: D_001F2D90@0x0 */
f32 D_001F2D90__grp[0x4] __attribute__((aligned(16))) = { 0.0f, 0.0f, 128.0f, 128.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sdata.c): D_00201D10__grp: D_00201D10@0x0 */
s32 D_00201D10__grp[0x2] __attribute__((aligned(16))) = { 0, 1 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/save_menu_data.c): D_001F2A90, D_001F2AC0 */
f32 D_001F2A90[0xc] = { -2.0f, 5.605e-42f, -1.0f, 5.607e-42f, 0.0f, 5.608e-42f, 1.0f, 5.61e-42f, 2.0f, 5.611e-42f, 0.0f, 0.0f };
f32 D_001F2AC0[0x10] = { -4.0f, 5.605e-42f, -3.0f, 5.607e-42f, -2.0f, 5.608e-42f, -1.0f, 5.61e-42f, 0.0f, 5.611e-42f, 1.0f, 5.612e-42f, 1.5f, 5.614e-42f, 2.0f, 5.615e-42f };
/* data twins (src/game/data/option_rodata.c): D_001FCEE0, D_001FCF50, D_001FCF68, D_001FCF80, D_001FCF98, D_001FCFA0, D_001FCFB0, D_001FCFC0, D_001FCFC8, D_001FCFD8, gStr169_001FCEE8 */
u8 D_001FCEE0[0x8] = { 0x34, 0x3a, 0x33, 0, 0, 0, 0, 0 };
u8 D_001FCF50[0x18] __attribute__((aligned(8))) = { 0x83, 0x5e, 0x83, 0x43, 0x83, 0x76, 0x82, 0x52, 0x81, 0x45, 0x83, 0x8a, 0x83, 0x6f, 0x81, 0x5b, 0x83, 0x58, 0, 0, 0, 0, 0, 0 };
u8 D_001FCF68[0x18] __attribute__((aligned(8))) = { 0x83, 0x5e, 0x83, 0x43, 0x83, 0x76, 0x82, 0x53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
u8 D_001FCF80[0x18] __attribute__((aligned(8))) = { 0x83, 0x5e, 0x83, 0x43, 0x83, 0x76, 0x82, 0x53, 0x81, 0x45, 0x83, 0x8a, 0x83, 0x6f, 0x81, 0x5b, 0x83, 0x58, 0, 0, 0, 0, 0, 0 };
u8 D_001FCF98[0x8] = { 0x88, 0xda, 0x93, 0xae, 0, 0, 0, 0 };
u8 D_001FCFA0[0x10] __attribute__((aligned(8))) = { 0x88, 0xda, 0x93, 0xae, 0x81, 0x45, 0x90, 0xf9, 0x89, 0xf1, 0, 0, 0, 0, 0, 0 };
u8 D_001FCFB0[0x10] __attribute__((aligned(8))) = { 0x88, 0xda, 0x93, 0xae, 0x81, 0x45, 0x8e, 0x8b, 0x93, 0x5f, 0, 0, 0, 0, 0, 0 };
u8 D_001FCFC0[0x8] = { 0x90, 0xf9, 0x89, 0xf1, 0, 0, 0, 0 };
u8 D_001FCFC8[0x10] __attribute__((aligned(8))) = { 0x8d, 0xb6, 0x95, 0xbd, 0x8d, 0x73, 0x88, 0xda, 0x93, 0xae, 0, 0, 0, 0, 0, 0 };
u8 D_001FCFD8[0x10] __attribute__((aligned(8))) = { 0x89, 0x45, 0x95, 0xbd, 0x8d, 0x73, 0x88, 0xda, 0x93, 0xae, 0, 0, 0, 0, 0, 0 };
u8 gStr169_001FCEE8[0x5] = "16:9\000";
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_rodata.c): D_001FCFE8__grp: D_001FCFE8@0x0, D_001FCFF0@0x8, D_001FCFF8@0x10, D_001FD000@0x18, D_001FD010@0x28, D_001FD020@0x38, D_001FD030@0x48, D_001FD040@0x58, D_001FD048@0x60, D_001FD050@0x68, D_001FD058@0x70, D_001FD068@0x80, D_001FD078@0x90, D_001FD088@0xa0, D_001FD090@0xa8 */
s32 D_001FCFE8__grp[0x46] __attribute__((aligned(8))) = { 0x5f938b8e, 0xe38f, 0x5f938b8e, 0xba89, 0x40968296, 0, -0x12756f6b, 0x588dcf95, 0, 0, 0x78834383, 0x67839383, 0, 0, 0x6a838183, 0x5b818583, 0, 0, -0x787ca97d, 0x67835b81, 0x62834a83, 0x6783, 0x5b817c83, 0x5983, 0, 0, -0x7d73aa73, 0, -0x7d73aa73, -0x70f5ba7f, -0x700f769b, 0x9c, -0x7d73aa73, -0x526bba7f, 0xcb8e, 0, -0xe760670, -0x7471ba7f, 0x5f93, 0, -0x66f4973, 0xf189, -0x66fba77, 0xf189, 0x4e4f, 0, 0x46464f, 0, 0, 0, 0x7050604, 0xb0a0908, 0xc0d0101, 0x1506140f, 0xa090807, 0xd00000b, 0x12100f0c, 0x9081211, 0x1010b0a, 0x10020c0d, 0x8121112, 0x10b0a09, 0x20c0d01, 0x12111210, 0xb0a0908, 0xc0d0000, 0x11121013, 0xa090812, 0xd00000b, 0x130c };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_bss.c): D_004A1070__grp: D_004A1070@0x0, D_004A1074@0x4, D_004A1078@0x8, D_004A1080@0x10, D_004A1084@0x14, D_004A1088@0x18, D_004A108C@0x1c */
u8 D_004A1070__grp[0x20] __attribute__((aligned(16)));
#endif
