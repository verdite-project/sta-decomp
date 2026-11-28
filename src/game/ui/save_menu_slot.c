#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/data.h"
#include "game/save.h"
#include "game/ui.h"
#include "game/math.h"
typedef union { u32 w; u8 c[4]; } Col_MenuProc_DrawItemList_0_0018B860;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[8]; Col_MenuProc_DrawItemList_0_0018B860 c; } Item_MenuProc_DrawItemList_0_0018B860;
typedef struct { u32 n; Item_MenuProc_DrawItemList_0_0018B860 *items; } List_MenuProc_DrawItemList_0_0018B860;
typedef struct { u8 pad[4]; List_MenuProc_DrawItemList_0_0018B860 *list; } Res_MenuProc_DrawItemList_0_0018B860;
typedef struct { s32 v[8]; } Tbl;
typedef struct { s32 x0; s32 x4; u8 x8; } Obj_MenuProc_DrawItemList_0_0018B860;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col_SaveMenu_DrawSlotInfo_2_0018BCC0;
typedef struct { s16 x0, x2, x4, x6; u16 x8; u8 xA, xB; u8 padC[2]; u8 xE, xF; } Ent;
typedef struct { u8 pad0[0x50]; Ent e[10]; } Slot;
typedef struct { s32 a[4]; s32 arr[8]; } Buf_MenuProc_DrawItemList_0_0018B860;
typedef struct {
    u8 pad0[0x28];
    s32 x28;
    u8 pad2C[3];
    u8 x2F;
    f32 x30, x34, x38, x3C;
} O_MenuProc_DrawItemList_0_0018B860;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[8]; u8 c[4]; } Item_Menu_LerpLayout_0_0018C140;
typedef struct { u32 n; Item_Menu_LerpLayout_0_0018C140 *items; } List_Menu_LerpLayout_0_0018C140;
typedef struct { u8 pad[4]; List_Menu_LerpLayout_0_0018C140 *list; } Res_Menu_LerpLayout_0_0018C140;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} Obj18C8B0_SaveMenu_SelectSlot_0_0018C590;
typedef struct {
    u8 pad0[0x10];
    s32 arr[8];
} Buf18C590;
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 pad8[2];
    u8 xA;
    u8 padB[3];
    u8 xE;
} Obj18C8B0_SaveMenu_ConfirmOverwrite_0_0018C8B0;
typedef struct { u8 pad0[0xA]; u8 xA; } O_SaveMenu_HandleEvent_0_0018C4C0;
typedef struct { s32 pad[3]; s32 xC; s32 arr[8]; } Buf_SaveMenu_HandleEvent_0_0018C4C0;
typedef struct { s16 x0; s16 x2; s16 x4; s16 x6; u8 pad8[4]; s16 xC; u8 xE; u8 xF; } R;
typedef struct { u8 pad[0x20]; R r; } S1;
typedef struct { u8 pad[0x50]; R r[1]; } S0;
typedef struct { s32 x0; u32 flags; u8 b8; char p9; u8 bA; char pB[3]; u8 bE; } Obj_MenuProc_BackOnCancel_0_0018D000;
#ifndef NONMATCHING
extern Tbl D_001F2A30 __attribute__((aligned(16)));
#else
/* data twins (src/game/data/save_menu_data.c): D_001F2A30 */
static Tbl D_001F2A30 = { -1, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern f32 D_0020211C;
#else
/* data twins (src/game/data/sbss.c): D_0020211C */
static f32 D_0020211C;
#endif
#ifndef NONMATCHING
extern s32 D_004A0FFC[];
#else
/* data twins (src/game/data/option_bss.c): D_004A0FFC */
static s32 D_004A0FFC[0x1];
#endif
extern f32 D_004A1008[];
#ifndef NONMATCHING
extern f32 D_004A100C[];
#else
/* data twins (src/game/data/option_bss.c): D_004A100C */
static f32 D_004A100C[0x1];
#endif
extern S D_001F2A10[] __attribute__((aligned(16)));
extern Slot D_004A0900[];
#ifndef NONMATCHING
extern char gStrSavedataD_001FCD00[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): gStrSavedataD_001FCD00 */
static char gStrSavedataD_001FCD00[0x10] = "SAVEDATA %d\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern char gStrHp4d4d_001FCD10[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): gStrHp4d4d_001FCD10 */
static char gStrHp4d4d_001FCD10[0x10] = "HP %4d/%4d\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern char gStrMp4d4d_001FCD20[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): gStrMp4d4d_001FCD20 */
static char gStrMp4d4d_001FCD20[0x10] = "MP %4d/%4d\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern char D_001FCD30[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCD30 */
static char D_001FCD30[0x10] = { 0x4c, 0x4f, 0x43, 0x41, 0x54, 0x49, 0x4f, 0x4e, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern char gStrTime2d2d2d_001FCD40[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): gStrTime2d2d2d_001FCD40 */
static char gStrTime2d2d2d_001FCD40[0x18] = "TIME %2d:%2d:%2d\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern char gStrEmpty_001FCD58[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): gStrEmpty_001FCD58 */
static char gStrEmpty_001FCD58[0x8] = " EMPTY \000";
#endif
#ifndef NONMATCHING
extern char D_001FCD60[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCD60 */
static char D_001FCD60[0xd] = "----\000\000\000\000\000\000\000\000\000";
#endif
extern u8 D_004A095F[][0xF0];
#ifndef NONMATCHING
extern s32 D_004A0FF8[];
#else
/* data twins (src/game/data/option_bss.c): D_004A0FF8 */
static s32 D_004A0FF8[0x1];
#endif
void MenuProc_DrawItemList_0_0018B860(Obj_MenuProc_DrawItemList_0_0018B860 *o);
void SaveMenu_DrawSlotInfo_2_0018BCC0(O_MenuProc_DrawItemList_0_0018B860 *o, s32 unused, u32 id, s32 n);
void Menu_LerpLayout_0_0018C140(f32 *a0, f32 *a1, u8 *a2, f32 f);
void SaveMenu_HandleEvent_0_0018C4C0(s32 *a);
void SaveMenu_SelectSlot_0_0018C590(Obj18C8B0_SaveMenu_SelectSlot_0_0018C590 *o);
void SaveMenu_ConfirmOverwrite_0_0018C8B0(Obj18C8B0_SaveMenu_ConfirmOverwrite_0_0018C8B0 *o);
void SaveMenu_Save_0_0018CA20(O_SaveMenu_HandleEvent_0_0018C4C0 *o);
void MenuProc_BackOnCancel_0_0018D000(Obj_MenuProc_BackOnCancel_0_0018D000 *o);
Res_MenuProc_DrawItemList_0_0018B860* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Item_MenuProc_DrawItemList_0_0018B860 *, s8 *, void (*)(), s32);
s8* Save_GetSlotInfo_0_00188FF0(s32);
void SaveSys_GetSlotCount_0_001E5E80(void *);
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S *, u32);
void sprintf(char *, char *, ...);
void Text_Draw_2_001875C0(f32, f32, f32, char *, s32, u32);
char* DbMap_GetLocationName_1_00195AA0(s32);
char* Msg_GetText_2_00195B10(s32);
void Menu_LerpLayout_0_0018C140__as_MenuProc_DrawItemList_0_0018B860(f32 *, f32 *, Col_MenuProc_DrawItemList_0_0018B860 *, f32);
Res_Menu_LerpLayout_0_0018C140* MenuLayout_Get_1_00189050__as_Menu_LerpLayout_0_0018C140(s32);
u8 MenuStack_Pop_1_00189EA0(void);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void Snd_PlaySe_3_00131600(s32, u8);
S1* Menu_GetStateBuf_0_00189000(s32);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 SaveSys_StartWrite_0_001E6170(s32, void *, s32);
void SaveMenu_ConfirmLoad_0_0018D060();
void SaveMenu_Exit_0_0018D140();
void SaveMenu_SelectSlot_0_0018C590__as_SaveMenu_HandleEvent_0_0018C4C0(s32 *);
void SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_SelectSlot_0_0018C590(Buf18C590 *);
void SaveMenu_ConfirmOverwrite_0_0018C8B0__as_SaveMenu_SelectSlot_0_0018C590();
void SaveMenu_Save_0_0018CA20__as_SaveMenu_ConfirmOverwrite_0_0018C8B0();
void SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_Save_0_0018CA20(Buf_SaveMenu_HandleEvent_0_0018C4C0 *);

/* MenuProc_DrawItemList_0_0018B860_ */
#define SaveSys_GetSlotCount_0_001E5E80 SaveSys_GetSlotCount_0_001E5E80__as_MenuProc_DrawItemList_0_0018B860_
void SaveSys_GetSlotCount_0_001E5E80__as_MenuProc_DrawItemList_0_0018B860_(Buf_MenuProc_DrawItemList_0_0018B860 *);

/* MenuProc_DrawItemList_0_0018B860 */

/* MenuProc_DrawItemList_0_0018B860 */

void MenuProc_DrawItemList_0_0018B860(Obj_MenuProc_DrawItemList_0_0018B860 *o) {
    f32 x;
    f32 y;
    Col_MenuProc_DrawItemList_0_0018B860 c;
    Tbl tbl __attribute__((aligned(16)));
    Item_MenuProc_DrawItemList_0_0018B860 it;
    List_MenuProc_DrawItemList_0_0018B860 *l;
    s8 *base;
    s32 off;
    u32 j;
    s32 i;
    s32 v;
    s32 *p;
    s32 t;
    u32 k;

    tbl = D_001F2A30;
    l = MenuLayout_Get_1_00189050(4)->list;
    base = MenuLayout_GetSub_1_00189020(4);
    Menu_SetFlags_0_0018A310(8);
    Ui_BeginSprites_1_00181420();
    if (o->x0 == 0x16) {
        D_004A1008[0] += 8.0f;
    }
    Ui_SetAlphaClamped_0_00182050((s32)D_004A1008[0]);
    switch (D_004A0FFC[0]) {
    case 1:
        D_0020211C = Approachf_3_00187770(D_0020211C, 2.0f, 2.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 10;
            D_004A0FF0[0] = 6;
            D_0020211C = 15.0f;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    case 3:
        D_0020211C = Approachf_3_00187770(D_0020211C, 13.0f, 2.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A100C[0] = 10.0f;
            D_0020211C = 0.0f;
            D_004A0FFC[0] = 10;
            D_004A0FF0[0] = 0;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    case 10:
        D_0020211C = Approachf_3_00187770(D_0020211C, D_004A0FF0[0] + 4, 5.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A0FFC[0] = 0;
            D_004A1010[0].f.b0 = 1;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    default:
        D_0020211C = D_0020211C - (D_0020211C - (f32)(D_004A0FF0[0] + 4)) / 4.0f;
        break;
    }
    i = 0;
    v = (s32)D_0020211C;
    p = tbl.v;
    for (; i < 5; i++) {
        if (v - 5 >= 0 && v - 5 < 7) {
            *p = v - 5;
        } else {
            *p = -1;
        }
        v++;
        p++;
    }
    j = 0;
    if (j < l->n) { off = 0; do {
        it = *(Item_MenuProc_DrawItemList_0_0018B860 *)((s8 *)l->items + off);
        Menu_LerpLayout_0_0018C140__as_MenuProc_DrawItemList_0_0018B860(&x, &y, &c, D_0020211C + (f32)(s32)j);
        it.f2C = x;
        it.f30 = y;
        it.c = c;
        t = tbl.v[((s32)D_0020211C + j) % l->n];
        if (t != -1) {
            Ui_DrawList_1_001829B0(&it, base + it.idx * 8, SaveMenu_DrawSlotInfo_2_0018BCC0, t);
        }
        off += 0x40; j++;
    } while (j < l->n); }
    Ui_DrawItemIconEx_0_0017EDC0(o->x8 == 0xB, D_004A1010[0].f.b1, 1, 7, D_004A0FF0[0]);
    Ui_BeginSprites_1_00181420();
    Ui_SetAlphaClamped_0_00182050(0x80);
}

/* SaveMenu_DrawSlotInfo_2_0018BCC0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */

void SaveMenu_DrawSlotInfo_2_0018BCC0(O_MenuProc_DrawItemList_0_0018B860 *o, s32 unused, u32 id, s32 n) {
    S t __attribute__((aligned(16))) = D_001F2A10[0];
    Ent *e = &D_004A0900[SaveSys_GetPort_1_001E8290()].e[n];
    s32 s0 = Save_GetSlotInfo_0_00188FF0(0)[n];
    char buf[0x100] = {0};
    Buf_MenuProc_DrawItemList_0_0018B860 b = {0};
    Col_SaveMenu_DrawSlotInfo_2_0018BCC0 col;
    u8 f;
    col.w = 0x80808080;
    col.c.a = o->x2F * 2;
    SaveSys_GetSlotCount_0_001E5E80(&b);
    if (id < 2000) {
        t.x = o->x30;
        t.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, (u8 *)o + 0x10, (u8 *)o + 0x2C, &t, id);
        return;
    }
    if ((f = e->xF) != 0 && s0 == 0) {
        switch (id) {
        case 2001:
            break;
        case 2002:
            if (e->xE) {
                col.c.r = 0x20;
                col.c.g = 0x20;
            }
            sprintf(buf, gStrSavedataD_001FCD00, n + 1);
            Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, buf, 0, col.w);
            break;
        case 2003:
            sprintf(buf, gStrHp4d4d_001FCD10, e->x4, e->x0);
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 2004:
            sprintf(buf, gStrMp4d4d_001FCD20, e->x6, e->x2);
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 2005:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, D_001FCD30, 0, col.w);
            break;
        case 2006:
            sprintf(buf, gStrTime2d2d2d_001FCD40, e->x8, e->xA, e->xB);
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 2007:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, DbMap_GetLocationName_1_00195AA0(f / 10), 0, col.w);
            break;
        }
    } else {
        switch (id) {
        case 2001:
            break;
        case 2002:
            if (b.arr[n] == 2 || b.a[3] == 2 || s0 != 0) {
                col.w = 0x80404080;
                col.c.a = o->x2F * 2;
                Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, Msg_GetText_2_00195B10(0x69), 0, col.w);
            } else {
                Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, gStrEmpty_001FCD58, 0, col.w);
            }
            break;
        case 2005:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, D_001FCD30, 0, col.w);
            break;
        case 2003:
        case 2004:
        case 2006:
        case 2007:
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, D_001FCD60, 0, col.w);
            break;
        }
    }
}

/* Menu_LerpLayout_0_0018C140 */
static inline f32 u2f(u32 x) { return x; }

void Menu_LerpLayout_0_0018C140(f32 *a0, f32 *a1, u8 *a2, f32 f) {
    s32 i;
    List_Menu_LerpLayout_0_0018C140 *l;
    Item_Menu_LerpLayout_0_0018C140 A;
    Item_Menu_LerpLayout_0_0018C140 B;
    f32 t;
    f32 u;

    i = f;
    l = MenuLayout_Get_1_00189050__as_Menu_LerpLayout_0_0018C140(4)->list;
    A = l->items[i % l->n];
    B = l->items[(i + 1) % l->n];
    t = f - i;
    u = 1.0f - t;
    *a0 = A.f2C * t + B.f2C * u;
    *a1 = A.f30 * t + B.f30 * u;
    a2[0] = (s32)((f32)(u32)A.c[0] * t + (f32)(u32)B.c[0] * u);
    a2[1] = (s32)((f32)(u32)A.c[1] * t + (f32)(u32)B.c[1] * u);
    a2[2] = (s32)((f32)(u32)A.c[2] * t + (f32)(u32)B.c[2] * u);
    a2[3] = (s32)((f32)(u32)A.c[3] * t + (f32)(u32)B.c[3] * u);
    if (a2[0] == 0x7F) a2[0] = 0x80;
    if (a2[1] == 0x7F) a2[1] = 0x80;
    if (a2[2] == 0x7F) a2[2] = 0x80;
    if (a2[3] == 0x7F) a2[3] = 0x80;
}
#undef SaveSys_GetSlotCount_0_001E5E80

/* SaveMenu_HandleEvent_0_0018C4C0_ */
#define D_004A1008 D_004A1008__as_SaveMenu_HandleEvent_0_0018C4C0_
extern s32 D_004A1008__as_SaveMenu_HandleEvent_0_0018C4C0_[];
#define MenuProc_BackOnCancel_0_0018D000 MenuProc_BackOnCancel_0_0018D000__as_SaveMenu_HandleEvent_0_0018C4C0_
void MenuProc_BackOnCancel_0_0018D000__as_SaveMenu_HandleEvent_0_0018C4C0_();

/* SaveMenu_HandleEvent_0_0018C4C0 */

void SaveMenu_HandleEvent_0_0018C4C0(s32 *a) {
    switch (a[0]) {
    case 0x19:
        D_0020211C = 0.0f;
        D_004A0FF0[0] = D_00202120[SaveSys_GetPort_1_001E8290()];
        D_004A1010[0].f.b0 = 1;
        D_004A1008[0] = 0;
        D_0020211C = D_004A0FF0[0] + 1;
        break;
    case 0x16:
        if (D_004A1010[0].f.b0) {
            SaveMenu_SelectSlot_0_0018C590__as_SaveMenu_HandleEvent_0_0018C4C0(a);
            a[1] = 0;
        }
        break;
    }
}

/* SaveMenu_SelectSlot_0_0018C590 */

void SaveMenu_SelectSlot_0_0018C590(Obj18C8B0_SaveMenu_SelectSlot_0_0018C590 *o) {
    Buf18C590 buf = {0};
    s32 i;
    s32 fl;

    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    D_004A1010[0].f.b1 = 1;
    fl = o->x4;
    if (fl & 0x10) {
        D_004A0FF0[0]--;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A0FF0[0] < 0) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 1;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x40) {
        D_004A0FF0[0]++;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A0FF0[0] > 6) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 3;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x2000) {
        SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_SelectSlot_0_0018C590(&buf);
        i = D_004A0FF0[0];
        if (buf.arr[i] != 1 || D_004A095F[SaveSys_GetPort_1_001E8290()][i * 0x10] == 0 || Save_GetSlotInfo_0_00188FF0(0)[D_004A0FF0[0]] != 0) {
            Snd_PlaySe_3_00131600(0x6B, o->xE);
        } else {
            Snd_PlaySe_3_00131600(0x67, o->xE);
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x71, 3, SaveMenu_ConfirmOverwrite_0_0018C8B0__as_SaveMenu_SelectSlot_0_0018C590, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A1010[0].f.b0 = 0;
        }
    } else if (fl & 0x4000) {
        o->x8 = MenuStack_Pop_1_00189EA0();
        o->x4 = 0;
        o->x0 = 0x1A;
        Snd_PlaySe_3_00131600(0x69, o->xE);
    }
}

/* SaveMenu_ConfirmOverwrite_0_0018C8B0 */

void SaveMenu_ConfirmOverwrite_0_0018C8B0(Obj18C8B0_SaveMenu_ConfirmOverwrite_0_0018C8B0 *o) {
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    if (o->x4 & 0x2000) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x6B, 0, SaveMenu_Save_0_0018CA20__as_SaveMenu_ConfirmOverwrite_0_0018C8B0, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A0FF8[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
    if (o->x4 & 0x4000) {
        D_004A1010[0].f.b0 = 1;
        o->xA = 2;
        Snd_PlaySe_3_00131600(0x68, o->xE);
    }
}

/* SaveMenu_Save_0_0018CA20 */
static inline s32 diff(R *a, R *b) {
    if (a->x4 != b->x4 || a->x6 != b->x6 || a->x0 != b->x0 || a->x2 != b->x2 ||
        a->xE != b->xE || a->xC != b->xC || a->xF != b->xF) {
        return 1;
    }
    return 0;
}

void SaveMenu_Save_0_0018CA20(O_SaveMenu_HandleEvent_0_0018C4C0 *o) {
    Buf_SaveMenu_HandleEvent_0_0018C4C0 buf = {0};
    S1 *s1;
    S0 *s0;
    s32 st;

    SaveSys_GetPort_1_001E8290();
    s1 = Menu_GetStateBuf_0_00189000(0);
    s0 = (S0 *)Menu_GetStateBuf_0_00189000(1);
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    D_004A1010[0].f.b1 = 0;
    switch (D_004A0FF8[0]) {
    case 0:
        if (!SaveSys_StartRead_0_001E5F30(0, 0)) {
            D_004A0FF8[0]++;
        }
        break;
    case 1:
        SaveSys_GetResult_0_001E6080(&st);
        if (st == 0) {
            D_004A0FF8[0]++;
        }
        if (st == 1) {
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    case 2:
        SaveSys_GetSlotCount_0_001E5E80__as_SaveMenu_Save_0_0018CA20(&buf);
        switch (buf.arr[D_004A0FF0[0]]) {
        case 2:
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x6C, 2, SaveMenu_ConfirmLoad_0_0018D060, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A1010[0].f.b0 = 0;
            return;
        case 0:
            break;
        case 1:
            break;
        }
        if (buf.xC == 1) {
            if (!SaveSys_StartWrite_0_001E6170(-1, s0, 0xF0)) {
                D_004A0FF8[0]++;
            }
        } else {
            D_004A0FF8[0]++;
            D_004A0FF8[0]++;
        }
        break;
    case 3:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&st);
        } while (st == 2);
        if (st == 0) {
            D_004A0FF8[0]++;
        }
        if (st == 1) {
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    case 4:
        if (!SaveSys_StartWrite_0_001E6170(D_004A0FF0[0], s1, 0x7C20)) {
            D_004A0FF8[0]++;
        }
        break;
    case 5:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&st);
        } while (st == 2);
        if (st == 0) {
            if (diff(&s0->r[D_004A0FF0[0]], &s1->r)) {
                MenuProc_Set_1_0018B150(D_004A0FC0, 0x6C, 2, SaveMenu_ConfirmLoad_0_0018D060, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A0FC0);
                o->xA = 1;
                D_004A1010[0].f.b0 = 0;
            } else {
                MenuProc_Set_1_0018B150(D_004A0FC0, 0x6D, 2, SaveMenu_Exit_0_0018D140, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A0FC0);
                o->xA = 1;
            }
        }
        if (st == 1) {
            MenuProc_Set_1_0018B150(D_004A0FC0, 0x79, 2, MenuProc_BackOnCancel_0_0018D000, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    }
}
#undef MenuProc_BackOnCancel_0_0018D000
#undef D_004A1008

/* MenuProc_BackOnCancel_0_0018D000 */
void MenuProc_BackOnCancel_0_0018D000(Obj_MenuProc_BackOnCancel_0_0018D000 *o)
{
    if (o->flags & 0x2000) {
        o->bA = 2;
        o->b8 = MenuStack_Pop_1_00189EA0();
        o->flags = 0;
        o->x0 = 0x1A;
        Snd_PlaySe_3_00131600(0x67, o->bE);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_bss.c): D_004A0FC0, D_004A0FF0, D_004A0FF4, D_004A1000, D_004A1008, D_004A1010 */
s32 D_004A0FC0[0xc] __attribute__((aligned(4)));
s32 D_004A0FF0[0x1];
s32 D_004A0FF4[0x1];
s32 D_004A1000[0x2] __attribute__((aligned(4)));
f32 D_004A1008[0x1];
Flags8 D_004A1010[0x10 / sizeof(Flags8)] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_menu_data.c): D_001F2A10__grp: D_001F2A10@0x0 */
f32 D_001F2A10__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
