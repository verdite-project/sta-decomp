#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/data.h"
#include "game/save.h"
#include "game/ui.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    u64 a, b;
    f32 x, y;
} S_LoadMenu_DrawSlotInfo_2_00192110;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A_LoadMenu_DrawSlotInfo_2_00192110;
typedef struct {
    s16 x0, x2, x4, x6;
    u16 x8;
    u8 xA, xB;
    u8 padC[2];
    u8 xE, xF;
} E_LoadMenu_DrawSlotInfo_2_00192110;
typedef struct {
    u8 pad[0x50];
    E_LoadMenu_DrawSlotInfo_2_00192110 e[10];
} Row;
typedef struct {
    u8 pad0[0xC];
    s32 xC;
    s32 arr[8];
} B;
typedef struct { u8 pad[0x2C]; f32 x2C; f32 x30; u8 pad34[8]; u8 c[4]; } Ent_LoadMenu_LerpLayout_0_00192580;
typedef struct { u32 n; Ent_LoadMenu_LerpLayout_0_00192580 *tbl; } Tbl;
typedef struct { s32 x0; Tbl *t; } Res;
typedef struct { s32 x0; s32 x4; } A_LoadMenu_HandleEvent_0_00192900;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} O_LoadMenu_SelectSlot_0_001929C0;
typedef struct {
    s32 a[4];
    s32 arr[8];
} Buf;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} O_LoadMenu_CheckCard_1_00192E90;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} O_LoadMenu_ConfirmLoad_0_00192F70;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
} O_LoadMenu_Load_0_00193070;
typedef struct { s16 v[8]; } P_LoadMenu_Load_0_00193070;
typedef struct { s32 x0; u32 flags; u8 b8; char p9; u8 bA; char pB[3]; u8 bE; } Obj_LoadMenu_Back_0_00193780;
typedef struct { s32 x0; u32 flags; char p8[2]; u8 bA; char pB[3]; u8 bE; } Obj_LoadMenu_Retry_0_001937E0;
typedef struct { s32 x0; u8 pad[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { s32 x0; s32 x4; u8 x8; } Obj_LoadMenu_DrawFrame_0_00193880;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[2];
    u8 xA;
    u8 xB;
} Obj1939B0;
typedef struct { f32 m[4]; f32 x; f32 y; } S_LoadMenu_DrawSlot_1_00193AF0;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A_LoadMenu_DrawSlot_1_00193AF0;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E_LoadMenu_DrawSlot_1_00193AF0;
typedef struct {
    u8 pad0[0xAC];
    E_LoadMenu_DrawSlot_1_00193AF0 *xAC;
} P_LoadMenu_DrawSlot_1_00193AF0;
typedef struct {
    Flags8 f;
    u8 pad[3];
} Ent_LoadMenu_DrawSlot_1_00193AF0;
typedef struct {
    s32 idx;
    u8 pad4[0x14];
    Ent_LoadMenu_DrawSlot_1_00193AF0 e[1];
} Menu;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
    u8 padC[2];
    u8 xE;
} Obj193E80;
typedef struct {
    Flags8 f;
    u8 pad[3];
} Ent193E80;
typedef struct {
    s32 idx;
    u8 pad4[0x14];
    Ent193E80 e[1];
} Menu193E80;
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } Obj_LoadMenu_SelectSlotB_0_00194150;
extern S_LoadMenu_DrawSlotInfo_2_00192110 D_001F2DA0 __attribute__((aligned(16)));
extern Row D_004A0900[];
#ifndef NONMATCHING
extern s8 D_001FD128[];
#else
/* data twins (src/game/data/option_rodata2.c): D_001FD128 */
static s8 D_001FD128[0x10] __attribute__((aligned(8))) = "SAVEDATA%d\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD138[];
#else
/* data twins (src/game/data/option_rodata2.c): D_001FD138 */
static s8 D_001FD138[0x10] __attribute__((aligned(8))) = "HP %4d/%4d\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD148[];
#else
/* data twins (src/game/data/option_rodata2.c): D_001FD148 */
static s8 D_001FD148[0x10] __attribute__((aligned(8))) = "MP %4d/%4d\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD158[];
#else
/* data twins (src/game/data/option_rodata2.c): D_001FD158 */
static s8 D_001FD158[0x18] __attribute__((aligned(8))) = "LOCATION\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD170[];
#else
/* data twins (src/game/data/option_rodata2.c): D_001FD170 */
static s8 D_001FD170[0x18] __attribute__((aligned(8))) = "TIME %2d:%2d:%2d\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD188[];
#else
/* data twins (src/game/data/option_rodata2.c): D_001FD188 */
static s8 D_001FD188[0x8] = " EMPTY \000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD190[];
#else
/* data twins (src/game/data/option_rodata2.c): D_001FD190 */
static s8 D_001FD190[0x10] __attribute__((aligned(8))) = { 0x2d, 0x2d, 0x2d, 0x2d, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A10F0[0xc];
#ifndef NONMATCHING
extern s32 D_004A1124[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1124 */
static s32 D_004A1124[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004A1128[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1128 */
static s32 D_004A1128[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004A1130[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1130 */
static s32 D_004A1130[0x2];
#endif
extern u8 D_004A0950[];
#ifndef NONMATCHING
extern s32 D_00202140;
#else
/* data twins (src/game/data/sbss.c): D_00202140 */
static s32 D_00202140;
#endif
extern struct { unsigned char : 1; unsigned char f : 1; char pad[15]; } D_004A1194;
extern s32 D_004A1180[];
#ifndef NONMATCHING
extern f32 D_004A1190[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1190 */
static f32 D_004A1190[0x1];
#endif
#ifndef NONMATCHING
extern S_LoadMenu_DrawSlot_1_00193AF0 D_001F2DE0 __attribute__((aligned(16)));
#else
/* data twins (src/game/data/load_menu_draw_data.c): D_001F2DE0 */
static S_LoadMenu_DrawSlot_1_00193AF0 D_001F2DE0 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING
extern s8 D_001FD208[];
#else
/* data twins (src/game/data/load_menu_rodata.c): D_001FD208 */
static s8 D_001FD208[0x8] = "SLOT %d\000";
#endif
void LoadMenu_DrawSlotInfo_2_00192110(A_LoadMenu_DrawSlotInfo_2_00192110 *o, s32 unused, u32 kind, s32 idx);
void LoadMenu_HandleEvent_0_00192900(A_LoadMenu_HandleEvent_0_00192900 *a);
void LoadMenu_SelectSlot_0_001929C0(O_LoadMenu_SelectSlot_0_001929C0 *o);
void LoadMenu_CheckCard_1_00192E90(O_LoadMenu_CheckCard_1_00192E90 *o, s32 a1);
void LoadMenu_ConfirmLoad_0_00192F70(O_LoadMenu_ConfirmLoad_0_00192F70 *o);
void LoadMenu_Load_0_00193070(O_LoadMenu_Load_0_00193070 *o);
void LoadMenu_Back_0_00193780(Obj_LoadMenu_Back_0_00193780 *o);
void LoadMenu_Retry_0_001937E0(Obj_LoadMenu_Retry_0_001937E0 *o);
void LoadMenu_DrawFrame_0_00193880(Obj_LoadMenu_DrawFrame_0_00193880 *o);
void LoadMenu_Open_0_001939B0(Obj1939B0 *o);
void LoadMenu_DrawSlot_1_00193AF0(A_LoadMenu_DrawSlot_1_00193AF0 *o, s32 idx, u32 kind);
void LoadMenu_SelectDevice_0_00193E80(Obj193E80 *o);
void LoadMenu_SelectSlotB_0_00194150(Obj_LoadMenu_SelectSlotB_0_00194150 *o);
void LoadMenu_Format_0_001942E0(s8 *arg0);
void LoadMenu_WaitCard_0_00194440(s8 *arg0);
void Ui_DrawSprite_2_00181680(s32, void *, void *, Col*, void *, u32);
void Text_Draw_2_001875C0(f32, s8 *, f32, f32, s32, u32);
void sprintf(s8 *, s8 *, ...);
s8* Save_GetSlotInfo_0_00188FF0(s32);
void SaveSys_GetSlotCount_0_001E5E80(void *);
s8* DbMap_GetLocationName_1_00195AA0(s32);
s8* Msg_GetText_2_00195B10(s32);
Res* MenuLayout_Get_1_00189050(s32);
u8 MenuStack_Pop_1_00189EA0(void);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void Snd_PlaySe_3_00131600(s32, u8);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 SaveSys_StartLoad_0_001E62A0(s32, void *, s32);
void* Save_GetData_1_001A9400(void);
P_LoadMenu_Load_0_00193070* PlayerData_Get_2_001C9BA0(void);
s8* MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Item *, s8 *, void (*)(), s32);
void LoadMenu_UpdateCardFlags_1_00194D90(s32, s32 *);
void LoadMenu_RetryB_0_00194D20(s8 *);
f32 sinf(f32);
f32 fabsf(f32);
void LoadMenu_LoadB_0_001945B0();
void LoadMenu_BackB_0_00194B90();
void memset(s32, s32, s32);
void Save_BuildOptions_1_001AB0A0(s8 *);
s32 SaveSys_StartFormat_0_001E6410(s32);

/* LoadMenu_DrawSlotInfo_2_00192110 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#define Ui_DrawSprite_2_00181680 Ui_DrawSprite_2_00181680__as_LoadMenu_DrawSlotInfo_2_00192110
void Ui_DrawSprite_2_00181680__as_LoadMenu_DrawSlotInfo_2_00192110(s32, Vec *, Vec *, Col *, S_LoadMenu_DrawSlotInfo_2_00192110 *, u32);
#define SaveSys_GetSlotCount_0_001E5E80 SaveSys_GetSlotCount_0_001E5E80__as_LoadMenu_DrawSlotInfo_2_00192110
void SaveSys_GetSlotCount_0_001E5E80__as_LoadMenu_DrawSlotInfo_2_00192110(B *);

void LoadMenu_DrawSlotInfo_2_00192110(A_LoadMenu_DrawSlotInfo_2_00192110 *o, s32 unused, u32 kind, s32 idx) {
    S_LoadMenu_DrawSlotInfo_2_00192110 s __attribute__((aligned(16)));
    Col col;
    E_LoadMenu_DrawSlotInfo_2_00192110 *e;
    s32 c;
    s32 f;

    s = D_001F2DA0;
    e = &D_004A0900[SaveSys_GetPort_1_001E8290()].e[idx];
    c = Save_GetSlotInfo_0_00188FF0(0)[idx];
    {
        s8 buf[0x100] = {0};
        B b = {0};

        SaveSys_GetSlotCount_0_001E5E80(&b);
        col.w = 0x80808080;
        col.c.a = o->x2C.c.a * 2;
        if (kind < 2000) {
            s.x = o->x30;
            s.y = o->x34;
            Ui_DrawSprite_2_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, kind);
            return;
        }
        f = e->xF;
        if (f != 0 && c == 0) {
            switch (kind) {
            case 2001:
                break;
            case 2002:
                if (e->xE) {
                    col.c.r = 0x20;
                    col.c.g = 0x20;
                }
                sprintf(buf, D_001FD128, idx + 1);
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 1.0f, 0, col.w);
                break;
            case 2003:
                sprintf(buf, D_001FD138, e->x4, e->x0);
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
                break;
            case 2004:
                sprintf(buf, D_001FD148, e->x6, e->x2);
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
                break;
            case 2005:
                Text_Draw_2_001875C0(o->x38, D_001FD158, o->x3C, 0.9f, 0, col.w);
                break;
            case 2006:
                sprintf(buf, D_001FD170, e->x8, e->xA, e->xB);
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
                break;
            case 2007:
                Text_Draw_2_001875C0(o->x38, DbMap_GetLocationName_1_00195AA0((u8)f / 10), o->x3C, 0.9f, 0, col.w);
                break;
            }
        } else {
            switch (kind) {
            case 2001:
                break;
            case 2002:
                if (b.arr[idx] == 2 || b.xC == 2 || c != 0) {
                    col.w = 0x80404080;
                    col.c.a = o->x2C.c.a * 2;
                    Text_Draw_2_001875C0(o->x38, Msg_GetText_2_00195B10(0x69), o->x3C, 1.0f, 0, col.w);
                } else {
                    Text_Draw_2_001875C0(o->x38, D_001FD188, o->x3C, 1.0f, 0, col.w);
                }
                break;
            case 2005:
                Text_Draw_2_001875C0(o->x38, D_001FD190, o->x3C, 0.9f, 0, col.w);
                break;
            case 2003:
            case 2004:
            case 2006:
            case 2007:
                Text_Draw_2_001875C0(o->x38, D_001FD190, o->x3C, 0.9f, 0, col.w);
                break;
            }
        }
    }
}
#undef Ui_DrawSprite_2_00181680
#undef SaveSys_GetSlotCount_0_001E5E80

/* LoadMenu_LerpLayout_0_00192580 */
static inline f32 u2f(u32 x) { return x; }

void LoadMenu_LerpLayout_0_00192580(f32 *a0, f32 *a1, u8 *a2, f32 t) {
    s32 i;
    Tbl *tb;
    Ent_LoadMenu_LerpLayout_0_00192580 a;
    Ent_LoadMenu_LerpLayout_0_00192580 b;
    f32 f;
    f32 g;
    f32 x;
    f32 y;

    i = (s32)t;
    tb = MenuLayout_Get_1_00189050(4)->t;
    a = tb->tbl[i % tb->n];
    b = tb->tbl[(i + 1) % tb->n];
    f = t - (f32)i;
    g = 1.0f - f;
    *a0 = a.x2C * f + b.x2C * g;
    *a1 = a.x30 * f + b.x30 * g;
    x = u2f(a.c[0]); y = u2f(b.c[0]); a2[0] = (s32)(x * f + y * g);
    x = u2f(a.c[1]); y = u2f(b.c[1]); a2[1] = (s32)(x * f + y * g);
    x = u2f(a.c[2]); y = u2f(b.c[2]); a2[2] = (s32)(x * f + y * g);
    x = u2f(a.c[3]); y = u2f(b.c[3]); a2[3] = (s32)(x * f + y * g);
    if (a2[0] == 0x7F) a2[0] = 0x80;
    if (a2[1] == 0x7F) a2[1] = 0x80;
    if (a2[2] == 0x7F) a2[2] = 0x80;
    if (a2[3] == 0x7F) a2[3] = 0x80;
}

/* LoadMenu_HandleEvent_0_00192900 */
#define LoadMenu_SelectSlot_0_001929C0 LoadMenu_SelectSlot_0_001929C0__as_LoadMenu_HandleEvent_0_00192900
void LoadMenu_SelectSlot_0_001929C0__as_LoadMenu_HandleEvent_0_00192900(A_LoadMenu_HandleEvent_0_00192900 *);
void LoadMenu_HandleEvent_0_00192900(A_LoadMenu_HandleEvent_0_00192900 *a) {

    switch (a->x0) {
    case 25:
        D_0020213C = 0.0f;
        D_004A1120[0] = Menu_GetCursor_1_0018B820(SaveSys_GetPort_1_001E8290());
        D_004A1138[0] = 0.0f;
        D_0020213C = D_004A1120[0] + 1;
        D_004A1140[0].f.b0 = 1;
        break;
    case 22:
        if (D_004A1140[0].f.b0) {
            LoadMenu_SelectSlot_0_001929C0(a);
            a->x4 = 0;
        }
        break;
    }
}
#undef LoadMenu_SelectSlot_0_001929C0

/* LoadMenu_SelectSlot_0_001929C0 */
#define SaveSys_GetSlotCount_0_001E5E80 SaveSys_GetSlotCount_0_001E5E80__as_LoadMenu_SelectSlot_0_001929C0
void SaveSys_GetSlotCount_0_001E5E80__as_LoadMenu_SelectSlot_0_001929C0(Buf *);
#define LoadMenu_CheckCard_1_00192E90 LoadMenu_CheckCard_1_00192E90__as_LoadMenu_SelectSlot_0_001929C0
void LoadMenu_CheckCard_1_00192E90__as_LoadMenu_SelectSlot_0_001929C0(O_LoadMenu_SelectSlot_0_001929C0 *, s32);
#define LoadMenu_ConfirmLoad_0_00192F70 LoadMenu_ConfirmLoad_0_00192F70__as_LoadMenu_SelectSlot_0_001929C0
void LoadMenu_ConfirmLoad_0_00192F70__as_LoadMenu_SelectSlot_0_001929C0();
#define LoadMenu_Retry_0_001937E0 LoadMenu_Retry_0_001937E0__as_LoadMenu_SelectSlot_0_001929C0
void LoadMenu_Retry_0_001937E0__as_LoadMenu_SelectSlot_0_001929C0();

void LoadMenu_SelectSlot_0_001929C0(O_LoadMenu_SelectSlot_0_001929C0 *o) {
    Buf buf = {0};
    s32 fl;
    s32 c;
    s32 k;

    LoadMenu_CheckCard_1_00192E90(o, 0);
    D_004A1140[0].f.b1 = 1;
    fl = o->x4;
    if (fl & 0x10) {
        D_004A1120[0]--;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A1120[0] < 0) {
            D_004A113C[0] = 10.0f;
            D_004A112C[0] = 1;
            D_004A1140[0].f.b0 = 0;
        }
    } else if (fl & 0x40) {
        D_004A1120[0]++;
        Snd_PlaySe_3_00131600(0x66, o->xE);
        if (D_004A1120[0] > 6) {
            D_004A113C[0] = 10.0f;
            D_004A112C[0] = 3;
            D_004A1140[0].f.b0 = 0;
        }
    } else if (fl & 0x2000) {
        Snd_PlaySe_3_00131600(0x67, o->xE);
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        switch (buf.arr[D_004A1120[0]]) {
        case 2:
            if ((buf.a[0] == 1) & (buf.a[1] == 1) & (buf.a[2] == 1) & (buf.a[3] == 1)) {
                c = (u32)SaveSys_GetCurSlotState_0_001E6060() < 0x24;
                k = 0x89;
            } else {
                c = SaveSys_GetCurSlotState_0_001E6060() < 0x6F;
                k = 0x7C;
            }
            if (c) {
                MenuProc_Set_1_0018B150(D_004A10F0, k, 2, LoadMenu_Retry_0_001937E0, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
                break;
            }
        case 1:
            MenuProc_Set_1_0018B150(D_004A10F0, 0x72, 3, LoadMenu_ConfirmLoad_0_00192F70, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A10F0);
            o->xA = 1;
            D_004A1140[0].f.b0 = 0;
            break;
        case 0:
            if ((buf.a[0] == 1) & (buf.a[1] == 1) & (buf.a[2] == 1) & (buf.a[3] == 1)) {
                c = (u32)SaveSys_GetCurSlotState_0_001E6060() < 0x24;
                k = 0x89;
            } else {
                c = SaveSys_GetCurSlotState_0_001E6060() < 0x6F;
                k = 0x7C;
            }
            if (c) {
                MenuProc_Set_1_0018B150(D_004A10F0, k, 2, LoadMenu_Retry_0_001937E0, 0, 0.9f);
                MenuProc_Run_1_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
            } else if (Save_GetSlotInfo_0_00188FF0(0)[D_004A1120[0]]) {
                MenuProc_Set_1_0018B150(D_004A10F0, 0x72, 3, LoadMenu_ConfirmLoad_0_00192F70, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
            } else {
                MenuProc_Set_1_0018B150(D_004A10F0, 0x73, 3, LoadMenu_ConfirmLoad_0_00192F70, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
            }
            break;
        }
    } else if (fl & 0x4000) {
        o->x8 = MenuStack_Pop_1_00189EA0();
        o->x4 = 0;
        o->x0 = 0x1A;
        Snd_PlaySe_3_00131600(0x69, o->xE);
    }
}
#undef SaveSys_GetSlotCount_0_001E5E80
#undef LoadMenu_CheckCard_1_00192E90
#undef LoadMenu_ConfirmLoad_0_00192F70
#undef LoadMenu_Retry_0_001937E0

/* LoadMenu_CheckCard_1_00192E90 */
#define LoadMenu_Back_0_00193780 LoadMenu_Back_0_00193780__as_LoadMenu_CheckCard_1_00192E90
void LoadMenu_Back_0_00193780__as_LoadMenu_CheckCard_1_00192E90();
#define LoadMenu_Load_0_00193070 LoadMenu_Load_0_00193070__as_LoadMenu_CheckCard_1_00192E90
void LoadMenu_Load_0_00193070__as_LoadMenu_CheckCard_1_00192E90();

void LoadMenu_CheckCard_1_00192E90(O_LoadMenu_CheckCard_1_00192E90 *o, s32 a1) {
    s32 k;

    k = 0;
    if (SaveSys_IsCardReady_0_001E6110() != 0) {
        if (a1 == 0) {
            k = 0x79;
        } else if (a1 == 1) {
            k = 0x7B;
        }
        MenuProc_Set_1_0018B150(D_004A10F0, k, 2, LoadMenu_Back_0_00193780, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A10F0);
        o->xA = 1;
        D_004A1124[0] = 0;
        D_004A1130[0] = 0;
        D_004A1140[0].f.b0 = 0;
    }
}
#undef LoadMenu_Back_0_00193780
#undef LoadMenu_Load_0_00193070

/* LoadMenu_ConfirmLoad_0_00192F70 */
#define LoadMenu_CheckCard_1_00192E90 LoadMenu_CheckCard_1_00192E90__as_LoadMenu_ConfirmLoad_0_00192F70
void LoadMenu_CheckCard_1_00192E90__as_LoadMenu_ConfirmLoad_0_00192F70(O_LoadMenu_ConfirmLoad_0_00192F70 *, s32);
#define LoadMenu_Back_0_00193780 LoadMenu_Back_0_00193780__as_LoadMenu_ConfirmLoad_0_00192F70
void LoadMenu_Back_0_00193780__as_LoadMenu_ConfirmLoad_0_00192F70();
#define LoadMenu_Load_0_00193070 LoadMenu_Load_0_00193070__as_LoadMenu_ConfirmLoad_0_00192F70
void LoadMenu_Load_0_00193070__as_LoadMenu_ConfirmLoad_0_00192F70();

void LoadMenu_ConfirmLoad_0_00192F70(O_LoadMenu_ConfirmLoad_0_00192F70 *o) {
    LoadMenu_CheckCard_1_00192E90(o, 0);
    if (o->x4 & 0x2000) {
        MenuProc_Set_1_0018B150(D_004A10F0, 0x6E, 0, LoadMenu_Load_0_00193070, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A10F0);
        o->xA = 1;
        D_004A1124[0] = 0;
        D_004A1128[0] = 0;
        D_004A1130[0] = 0;
        D_004A1140[0].f.b0 = 0;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    } else if (o->x4 & 0x4000) {
        D_004A1140[0].f.b0 = 1;
        o->xA = 2;
        Snd_PlaySe_3_00131600(0x68, o->xE);
    }
}
#undef LoadMenu_CheckCard_1_00192E90
#undef LoadMenu_Back_0_00193780
#undef LoadMenu_Load_0_00193070

/* LoadMenu_Load_0_00193070 */
#define LoadMenu_CheckCard_1_00192E90 LoadMenu_CheckCard_1_00192E90__as_LoadMenu_Load_0_00193070
void LoadMenu_CheckCard_1_00192E90__as_LoadMenu_Load_0_00193070(O_LoadMenu_Load_0_00193070 *, s32);
#define LoadMenu_Back_0_00193780 LoadMenu_Back_0_00193780__as_LoadMenu_Load_0_00193070
void LoadMenu_Back_0_00193780__as_LoadMenu_Load_0_00193070();
#define LoadMenu_Retry_0_001937E0 LoadMenu_Retry_0_001937E0__as_LoadMenu_Load_0_00193070
void LoadMenu_Retry_0_001937E0__as_LoadMenu_Load_0_00193070();
#define D_004A0900 D_004A0900__as_LoadMenu_Load_0_00193070
extern u8 D_004A0900__as_LoadMenu_Load_0_00193070[][0xF0];
static inline void start(O_LoadMenu_Load_0_00193070 *o, s32 s) {
    if (s == 1) {
        MenuProc_Set_1_0018B150(D_004A10F0, 0x7B, 2, LoadMenu_Back_0_00193780, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A10F0);
        o->xA = 1;
        D_004A1124[0] = 0;
        D_004A1130[0] = 0;
        D_004A1140[0].f.b0 = 0;
    }
}
static inline void ok(O_LoadMenu_Load_0_00193070 *o) {
    MenuProc_Set_1_0018B150(D_004A10F0, 0x6F, 2, LoadMenu_Retry_0_001937E0, 0, 1.0f);
    MenuProc_Run_1_0018B320(D_004A10F0);
    o->xA = 1;
}

void LoadMenu_Load_0_00193070(O_LoadMenu_Load_0_00193070 *o) {
    s32 n;
    s32 s;
    P_LoadMenu_Load_0_00193070 *src;
    P_LoadMenu_Load_0_00193070 *dst;
    s32 off;
    u8 *p;

    n = SaveSys_GetPort_1_001E8290();
    LoadMenu_CheckCard_1_00192E90(o, 1);
    D_004A1140[0].f.b1 = 0;
    switch (D_004A1128[0]) {
    case 0:
        if (SaveSys_StartRead_0_001E5F30(0, 0) == 0) D_004A1128[0]++;
        break;
    case 1:
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 2:
        Save_GetSlotInfo_0_00188FF0(0)[D_004A1120[0]] = 1;
        if (SaveSys_StartLoad_0_001E62A0(7, Save_GetSlotInfo_0_00188FF0(0), 8) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 3:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 4:
        Save_WriteOptions_1_001A8CA0();
        Save_ParseGame_1_001A9080();
        if (SaveSys_StartLoad_0_001E62A0(D_004A1120[0], Save_GetData_1_001A9400(), 0x7C20) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 5:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 6:
        off = n * 0xF0;
        p = (u8 *)D_004A0900 + off;
        Option_Store_1_001A94E0(p + 0x20);
        src = PlayerData_Get_2_001C9BA0();
        dst = (P_LoadMenu_Load_0_00193070 *)(D_004A1120[0] * 16 + ((u8 *)D_004A0950 + off));
        *dst = *src;
        if (SaveSys_StartLoad_0_001E62A0(-1, p, 0xF0) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 7:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 8:
        Save_GetSlotInfo_0_00188FF0(0)[D_004A1120[0]] = 0;
        if (SaveSys_StartLoad_0_001E62A0(7, Save_GetSlotInfo_0_00188FF0(0), 8) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 9:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) {
            MenuProc_Set_1_0018B150(D_004A10F0, 0x70, 2, LoadMenu_Retry_0_001937E0, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A10F0);
            o->xA = 1;
            Menu_SetCursor_1_0018B840(SaveSys_GetPort_1_001E8290(), D_004A1120[0]);
        }
        start(o, s);
        break;
    }
}
#undef LoadMenu_CheckCard_1_00192E90
#undef LoadMenu_Back_0_00193780
#undef LoadMenu_Retry_0_001937E0
#undef D_004A0900

/* LoadMenu_Back_0_00193780 */
void LoadMenu_Back_0_00193780(Obj_LoadMenu_Back_0_00193780 *o)
{
    if (o->flags & 0x2000) {
        o->bA = 2;
        o->b8 = MenuStack_Pop_1_00189EA0();
        o->flags = 0;
        o->x0 = 0x1A;
        Snd_PlaySe_3_00131600(0x67, o->bE);
    }
}

/* LoadMenu_Retry_0_001937E0 */
#define D_004A1140 D_004A1140__as_LoadMenu_Retry_0_001937E0
extern struct { unsigned char f : 1; char pad[15]; } D_004A1140__as_LoadMenu_Retry_0_001937E0;
#define LoadMenu_CheckCard_1_00192E90 LoadMenu_CheckCard_1_00192E90__as_LoadMenu_Retry_0_001937E0
void LoadMenu_CheckCard_1_00192E90__as_LoadMenu_Retry_0_001937E0(Obj_LoadMenu_Retry_0_001937E0 *o, s32 a);

void LoadMenu_Retry_0_001937E0(Obj_LoadMenu_Retry_0_001937E0 *o)
{
    LoadMenu_CheckCard_1_00192E90(o, 0);
    if (o->flags & 0x2000) {
        o->bA = 2;
        D_004A1140.f = 1;
        Snd_PlaySe_3_00131600(0x67, o->bE);
    }
}
#undef LoadMenu_CheckCard_1_00192E90
#undef D_004A1140

/* LoadMenu_SetFromTitle_0_00193850 */
void LoadMenu_SetFromTitle_0_00193850(int v)
{
    D_00202140 = v != 0;
    D_004A1194.f = 1;
}

/* LoadMenu_DrawFrame_0_00193880 */
#define MenuLayout_Get_1_00189050 MenuLayout_Get_1_00189050__as_LoadMenu_DrawFrame_0_00193880
List **MenuLayout_Get_1_00189050__as_LoadMenu_DrawFrame_0_00193880(s32);
#define LoadMenu_DrawSlot_1_00193AF0 LoadMenu_DrawSlot_1_00193AF0__as_LoadMenu_DrawFrame_0_00193880
void LoadMenu_DrawSlot_1_00193AF0__as_LoadMenu_DrawFrame_0_00193880();

void LoadMenu_DrawFrame_0_00193880(Obj_LoadMenu_DrawFrame_0_00193880 *o) {
    u32 i;
    List *l;
    s8 *b;
    l = *MenuLayout_Get_1_00189050(4);
    b = MenuLayout_GetSub_1_00189020(4);
    if (o->x8 == 10) {
        D_004A118C[0] += 16.0f;
    } else {
        D_004A118C[0] -= 16.0f;
    }
    Ui_SetAlphaClamped_0_00182050(D_004A118C[0]);
    for (i = 0; i < l->n; i++) {
        Ui_DrawList_1_001829B0(&l->items[i], b + l->items[i].x0 * 8, LoadMenu_DrawSlot_1_00193AF0, D_004A1180[0]);
    }
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
    Ui_SetAlphaClamped_0_00182050(0x80);
}
#undef MenuLayout_Get_1_00189050
#undef LoadMenu_DrawSlot_1_00193AF0

/* LoadMenu_Open_0_001939B0 */
#define LoadMenu_SelectDevice_0_00193E80 LoadMenu_SelectDevice_0_00193E80__as_LoadMenu_Open_0_001939B0
void LoadMenu_SelectDevice_0_00193E80__as_LoadMenu_Open_0_001939B0(Obj1939B0 *);
#define D_004A118C D_004A118C__as_LoadMenu_Open_0_001939B0
extern s32 D_004A118C__as_LoadMenu_Open_0_001939B0[];
#define D_004A1194 D_004A1194__as_LoadMenu_Open_0_001939B0
extern Flags8 D_004A1194__as_LoadMenu_Open_0_001939B0[];

void LoadMenu_Open_0_001939B0(Obj1939B0 *o) {
    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    switch (o->x0) {
    case 0x19:
        D_004A1190[0] = 0.0f;
        D_004A118C[0] = 0;
        D_004A1184[0] = 0;
        D_004A1180[0] = SaveSys_GetPort_1_001E8290();
        if (D_00202140 != 0 && D_004A1194[0].f.b1) {
            MenuProc_Set_1_0018B150(D_004A1150, 0x2E, 2, LoadMenu_RetryB_0_00194D20, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1150);
            o->xA = 1;
            o->xB = 1;
            D_004A1194[0].f.b1 = 0;
        }
        break;
    case 0x16:
        LoadMenu_SelectDevice_0_00193E80(o);
        D_004A1190[0] += 0.1f;
        o->x4 = 0;
        break;
    }
}
#undef LoadMenu_SelectDevice_0_00193E80
#undef D_004A118C
#undef D_004A1194

/* LoadMenu_DrawSlot_1_00193AF0 */
#define Ui_DrawSprite_2_00181680 Ui_DrawSprite_2_00181680__as_LoadMenu_DrawSlot_1_00193AF0
void Ui_DrawSprite_2_00181680__as_LoadMenu_DrawSlot_1_00193AF0(s32, f32 *, f32 *, Col *, S_LoadMenu_DrawSlot_1_00193AF0 *, u32);
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_LoadMenu_DrawSlot_1_00193AF0
P_LoadMenu_DrawSlot_1_00193AF0 *MenuLayout_GetSub_1_00189020__as_LoadMenu_DrawSlot_1_00193AF0(s32);
#define sprintf sprintf__as_LoadMenu_DrawSlot_1_00193AF0
void sprintf__as_LoadMenu_DrawSlot_1_00193AF0(s8 *, s8 *, s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_LoadMenu_DrawSlot_1_00193AF0
void Text_Draw_2_001875C0__as_LoadMenu_DrawSlot_1_00193AF0(f32, f32, f32, s8 *, s32, u32);
#define D_004A1180 D_004A1180__as_LoadMenu_DrawSlot_1_00193AF0
extern Menu D_004A1180__as_LoadMenu_DrawSlot_1_00193AF0[];

void LoadMenu_DrawSlot_1_00193AF0(A_LoadMenu_DrawSlot_1_00193AF0 *o, s32 idx, u32 kind) {
    f32 *py;
    f32 *px;
    E_LoadMenu_DrawSlot_1_00193AF0 *e;
    f32 f;
    S_LoadMenu_DrawSlot_1_00193AF0 s __attribute__((aligned(16)));
    Col col;

    s = D_001F2DE0;
    if (kind < 500) {
        s.x = o->x30;
        s.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, kind);
        return;
    }
    switch (kind) {
    case 500:
        if (idx == D_004A1180[0].idx) {
            o->x2C.c.r = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1190[0])));
            o->x2C.c.g = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1190[0])));
            o->x2C.c.b = (s32)(64.0f + fabsf(64.0f * sinf(D_004A1190[0])));
        } else {
            o->x2C.c.r = 0x40;
            o->x2C.c.g = 0x40;
            o->x2C.c.b = 0x40;
            o->x2C.c.a = 0x40;
        }
        if (D_004A1180[0].e[idx].f.f.b0) {
            s.x = o->x30;
            s.y = o->x34;
            Ui_DrawSprite_2_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, kind);
        }
        break;
    case 0x226:
        e = MenuLayout_GetSub_1_00189020(0)->xAC;
        px = &s.x;
        py = &s.y;
        col.w = 0x30808080;
        s.m[0] = 1.0f;
        s.m[3] = 1.0f;
        *px = o->x38;
        *py = o->x3C;
        col.w = (idx == D_004A1180[0].idx) ? 0x40808000 : 0x30808080;
        Ui_DrawSprite_2_00181680(e->x4, e->v10, e->v20, &col, &s, kind);
        {
        s8 buf[16] = {0};
        col.w = 0x80808080;
        f = D_004A118C[0];
        if (f <= 0.0f) {
            col.c.a = 0;
        } else if (f < 128.0f) {
            col.c.a = col.c.a * (s32)f / 128.0f;
        }
        sprintf(buf, D_001FD208, idx + 1);
        Text_Draw_2_001875C0(8.0f + *px, 4.0f + *py, 1.0f, buf, 0, col.w);
        }
        break;
    }
}
#undef Ui_DrawSprite_2_00181680
#undef MenuLayout_GetSub_1_00189020
#undef sprintf
#undef Text_Draw_2_001875C0
#undef D_004A1180

/* LoadMenu_SelectDevice_0_00193E80 */
#define LoadMenu_WaitCard_0_00194440 LoadMenu_WaitCard_0_00194440__as_LoadMenu_SelectDevice_0_00193E80
void LoadMenu_WaitCard_0_00194440__as_LoadMenu_SelectDevice_0_00193E80();
#define D_004A1180 D_004A1180__as_LoadMenu_SelectDevice_0_00193E80
extern Menu193E80 D_004A1180__as_LoadMenu_SelectDevice_0_00193E80[];

void LoadMenu_SelectDevice_0_00193E80(Obj193E80 *o) {
    s32 fl;

    fl = o->x4;
    if (fl & 0x80) {
        D_004A1180[0].idx--;
        if (D_004A1180[0].idx < 0) {
            D_004A1180[0].idx = 1;
        }
        D_004A1190[0] = 0.0f;
        Snd_PlaySe_3_00131600(0x66, o->xE);
    } else if (fl & 0x20) {
        D_004A1180[0].idx++;
        if (D_004A1180[0].idx > 1) {
            D_004A1180[0].idx = 0;
        }
        D_004A1190[0] = 0.0f;
        Snd_PlaySe_3_00131600(0x66, o->xE);
    } else if (fl & 0x2000) {
        if (D_004A1180[0].e[D_004A1180[0].idx].f.f.b0) {
            SaveSys_SetPort_1_001E82A0(D_004A1180[0].idx);
            if (D_004A1180[0].e[D_004A1180[0].idx].f.f.b1) {
                MenuProc_Set_1_0018B150(D_004A1150, 0x7A, 0, LoadMenu_LoadB_0_001945B0, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A1150);
                D_004A1188[0] = 0;
                o->xA = 1;
                o->xB = 1;
            } else {
                MenuProc_Set_1_0018B150(D_004A1150, 0x76, 3, LoadMenu_WaitCard_0_00194440, 0, 1.0f);
                MenuProc_Run_1_0018B320(D_004A1150);
                D_004A1188[0] = 0;
                o->xA = 1;
                o->xB = 1;
            }
        } else {
            MenuProc_Set_1_0018B150(D_004A1150, D_004A1180[0].idx + 0x81, 2, LoadMenu_RetryB_0_00194D20, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1150);
            o->xA = 1;
            o->xB = 1;
        }
        Snd_PlaySe_3_00131600(0x67, o->xE);
    } else if (fl & 0x4000) {
        if (D_00202140 != 0) {
            MenuProc_Set_1_0018B150(D_004A1150, 0x2D, 3, LoadMenu_BackB_0_00194B90, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1150);
            o->xA = 1;
            o->xB = 1;
            Snd_PlaySe_3_00131600(0x67, o->xE);
        } else {
            Snd_PlaySe_3_00131600(0x69, o->xE);
            o->x8 = MenuStack_Pop_1_00189EA0();
            o->x4 = 0;
            o->x0 = 0x1A;
            D_004A118C[0] = 128.0f;
        }
    }
    o->x4 = 0;
}
#undef LoadMenu_WaitCard_0_00194440
#undef D_004A1180

/* LoadMenu_SelectSlotB_0_00194150 */
#define Save_GetSlotInfo_0_00188FF0 Save_GetSlotInfo_0_00188FF0__as_LoadMenu_SelectSlotB_0_00194150
s32 Save_GetSlotInfo_0_00188FF0__as_LoadMenu_SelectSlotB_0_00194150(s32);
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_LoadMenu_SelectSlotB_0_00194150
void MenuProc_Set_1_0018B150__as_LoadMenu_SelectSlotB_0_00194150(f32, s32 *, s32, s32, void (*)(), s32);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_LoadMenu_SelectSlotB_0_00194150
void Snd_PlaySe_3_00131600__as_LoadMenu_SelectSlotB_0_00194150(s32, s32);
#define D_004A0900 D_004A0900__as_LoadMenu_SelectSlotB_0_00194150
extern s8 D_004A0900__as_LoadMenu_SelectSlotB_0_00194150[];

void LoadMenu_SelectSlotB_0_00194150(Obj_LoadMenu_SelectSlotB_0_00194150 *o) {
    s32 idx;
    s32 st;
    s32 r;

    idx = SaveSys_GetPort_1_001E8290();
    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    st = SaveSys_IsCardReady_0_001E6110();
    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    if (st == 1) {
        MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
        MenuProc_Run_1_0018B320(D_004A1150);
        r = 1;
        o->xA = 1;
        o->xB = 1;
        D_004A1184[0] = 0;
        D_004A1188[0] = 0;
    } else {
        r = 0;
    }
    if (r == 0 && (o->x4 & 0x2000)) {
        Save_BuildOptions_1_001AB0A0(D_004A0900 + idx * 0xF0);
        memset(Save_GetSlotInfo_0_00188FF0(0), 0, 8);
        D_004A1184[0] = 0;
        D_004A118C[0] = 128.0f;
        D_004A1188[0] = 0;
        MenuStack_Push_1_00189ED0(0xA);
        o->x8 = 0xC;
        o->x4 = 0;
        o->x0 = 0x1A;
        o->xA = 2;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
}
#undef Save_GetSlotInfo_0_00188FF0
#undef MenuProc_Set_1_0018B150
#undef Snd_PlaySe_3_00131600
#undef D_004A0900

/* LoadMenu_Format_0_001942E0 */
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_LoadMenu_Format_0_001942E0
void MenuProc_Set_1_0018B150__as_LoadMenu_Format_0_001942E0(f32, s32 *, s32, s32, void (*)(s8 *), s32);
#define LoadMenu_SelectSlotB_0_00194150 LoadMenu_SelectSlotB_0_00194150__as_LoadMenu_Format_0_001942E0
void LoadMenu_SelectSlotB_0_00194150__as_LoadMenu_Format_0_001942E0(s8 *);

void LoadMenu_Format_0_001942E0(s8 *arg0) {
    s32 r = 0;

    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    switch (D_004A1188[0]) {
    case 0:
        D_004A1188[0]++;
        break;
    case 1:
        if (SaveSys_StartFormat_0_001E6410(D_004A1188[0]) != -1) {
            D_004A1188[0]++;
        }
        break;
    case 2:
        SaveSys_GetResult_0_001E6080(&r);
        if (r == 0) {
            MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x74, 2, LoadMenu_SelectSlotB_0_00194150, 0);
            MenuProc_Run_1_0018B320(D_004A1150);
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
        }
        if (r == 1) {
            MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
            MenuProc_Run_1_0018B320(D_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
        }
        break;
    }
}
#undef MenuProc_Set_1_0018B150
#undef LoadMenu_SelectSlotB_0_00194150

/* LoadMenu_WaitCard_0_00194440 */
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_LoadMenu_WaitCard_0_00194440
void MenuProc_Set_1_0018B150__as_LoadMenu_WaitCard_0_00194440(f32, s32 *, s32, s32, void (*)(s8 *), s32);
#define LoadMenu_SelectSlotB_0_00194150 LoadMenu_SelectSlotB_0_00194150__as_LoadMenu_WaitCard_0_00194440
void LoadMenu_SelectSlotB_0_00194150__as_LoadMenu_WaitCard_0_00194440(s8 *);
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_LoadMenu_WaitCard_0_00194440
void Snd_PlaySe_3_00131600__as_LoadMenu_WaitCard_0_00194440(s32, s32);

void LoadMenu_WaitCard_0_00194440(s8 *arg0) {
    s32 st;
    s32 done;
    s32 b;

    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    st = SaveSys_IsCardReady_0_001E6110();
    LoadMenu_UpdateCardFlags_1_00194D90(0, D_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, D_004A119C);
    if (st == 1) {
        MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
        MenuProc_Run_1_0018B320(D_004A1150);
        arg0[0xA] = 1;
        arg0[0xB] = 1;
        D_004A1184[0] = 0;
        D_004A1188[0] = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done == 0) {
        b = *(s32 *)(arg0 + 4);
        if (b & 0x2000) {
            MenuProc_Set_1_0018B150(1.0f, D_004A1150, 0x75, 0, LoadMenu_Format_0_001942E0, 0);
            MenuProc_Run_1_0018B320(D_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            Snd_PlaySe_3_00131600(0x67, *(u8 *)(arg0 + 0xE));
        } else if (b & 0x4000) {
            arg0[0xA] = 2;
            Snd_PlaySe_3_00131600(0x68, *(u8 *)(arg0 + 0xE));
        }
    }
}
#undef MenuProc_Set_1_0018B150
#undef LoadMenu_SelectSlotB_0_00194150
#undef Snd_PlaySe_3_00131600

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1120, D_004A112C, D_004A1138, D_004A113C, D_004A1140, D_004A1150, D_004A1180, D_004A1184, D_004A1188, D_004A118C, D_004A1198, D_004A119C */
s32 D_004A1120[0x1] __attribute__((aligned(16)));
s32 D_004A112C[0x1];
f32 D_004A1138[0x1];
f32 D_004A113C[0x1];
Flags8 D_004A1140[0x10 / sizeof(Flags8)];
s32 D_004A1150[0xc];
s32 D_004A1180[0x1];
s32 D_004A1184[0x1];
s32 D_004A1188[0x1];
f32 D_004A118C[0x1];
s32 D_004A1198[0x1];
s32 D_004A119C[0x1];
#endif
