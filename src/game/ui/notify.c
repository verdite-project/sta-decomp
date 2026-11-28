#include "m2c.h"
#include "game/data.h"
#include "game/ui.h"
#include "game/gfx.h"
typedef union { u128 q; u32 w[4]; } V;
typedef union { u32 w; u8 b[4]; } C;
typedef struct { u8 p:2; u8 v:1; } B;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x31]; u8 x3D; u8 pad3E[0x52]; } E_Notify_DrawItemGet_0_0019F050;
typedef struct { u8 b[256]; } Buf;
typedef union { s32 w; u8 b[4]; } Col;
typedef struct { u8 pad[2]; u8 x2; } Ent;
typedef struct { u8 pad[4]; u8 x4; } Ent4;
typedef struct { u8 pad[6]; u8 x6; u8 pad7[0x89]; } E_Notify_DrawItemGold_0_0019FA00;
typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; u8 x4; u8 x5; } Q;
extern s32 gShopBss_004A3328[];
extern B gShopBss_004A332C[];
extern u16 gShopBss_004A3310[];
#ifndef NONMATCHING
extern V gPauseMenuOpenData_001F3200[];
extern V gPauseMenuOpenData_001F3210[];
extern s32 gNotifyBss_004A3324[];
extern s8 gNotifyRodata_001FD698[];
extern s8 gNotifyRodata_001FD6A0[];
extern s8 gNotifyRodata_001FD6A8[];
#else
/* data twins (src/game/data/pause_menu_open_data_001F3200.c): gPauseMenuOpenData_001F3200 */
static V gPauseMenuOpenData_001F3200[0x1] = { { .w = { 0, 0, 0x44200000, 0x43e00000 } } };
/* data twins (src/game/data/pause_menu_open_data_001F3200.c): gPauseMenuOpenData_001F3210 */
static V gPauseMenuOpenData_001F3210[0x1] = { { .w = { 0, 0, 0x43000000, 0x43000000 } } };
/* data twins (src/game/data/shop_bss_004A3310.c): gNotifyBss_004A3324 */
static s32 gNotifyBss_004A3324[0x1];
/* data twins (src/game/data/notify_rodata.c): gNotifyRodata_001FD698 */
static s8 gNotifyRodata_001FD698[0x8] = "%d\000\000\000\000\000\000";
/* data twins (src/game/data/notify_rodata.c): gNotifyRodata_001FD6A0 */
static s8 gNotifyRodata_001FD6A0[0x8] = { -0x7f, 0x7e, 0x20, 0x25, 0x64, 0, 0, 0 };
/* data twins (src/game/data/notify_rodata.c): gNotifyRodata_001FD6A8 */
static s8 gNotifyRodata_001FD6A8[0x8] = { -0x7e, 0x62, 0x20, 0x25, 0x64, 0, 0, 0 };
#endif
void Notify_DrawBackground_0_0019EF60(s8 *arg0);
void GsPkt_SetReg_3_001543E0(s32, s32);
void Ui_DrawSpriteRotated_1_00182080(s32, f32, V *, V *, C *, s32);
void Text_Draw_2_001875C0(s8 *, s32, u32, f32, f32, f32);
s8* Msg_GetText_2_00195B10(s32);
s8* DbItem_Find_1_0019D510(u16);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
E_Notify_DrawItemGet_0_0019F050* Item_GetTable_1_001AFC90(void);
u8* Inventory_GetEntry_1_001CC3F0(s16);
Ent4* Inventory_GetSlot_1_001A97D0(s32);

/* Notify_DrawBackground_0_0019EF60 */
void Notify_DrawBackground_0_0019EF60(s8 *arg0) {
    C col;
    V a;
    V b;

    a = gPauseMenuOpenData_001F3200[0];
    b = gPauseMenuOpenData_001F3210[0];
    col.w = 0x80808080;
    col.b[3] = gNotifyBss_004A3324[0];
    if (gShopBss_004A332C[0].v) {
        gNotifyBss_004A3324[0] = 0;
        gShopBss_004A3328[0] = 0x41200000;
        gShopBss_004A331C[0] = 0;
        arg0[0xA] = 2;
    }
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x46);
    GsPkt_Flush_1_001544C0();
    Ui_DrawSpriteRotated_1_00182080(0, 0.0f, &a, &b, &col, 0);
    Ui_BeginSprites_1_00181420();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x44);
    GsPkt_Flush_1_001544C0();
}

/* Notify_DrawItemGet_0_0019F050 */
void Notify_DrawItemGet_0_0019F050(void) {
    C c;
    s8 buf[0x100] = {0};
    s32 id;
    s16 v;
    E_Notify_DrawItemGet_0_0019F050 *e;
    u8 *q;
    s16 r;

    c.w = 0x80808080;
    c.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(Msg_GetText_2_00195B10(0x92), 1, *(u32 *)&c, 320.0f, 150.0f, 1.1f);
    Text_Draw_2_001875C0(DbItem_Find_1_0019D510(gShopBss_004A3310[0]), 1, *(u32 *)&c, 320.0f, 180.0f, 1.1f);
    sprintf(buf, Msg_GetText_2_00195B10(0x9E));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 250.0f, 210.0f, 1.0f);
    id = gShopBss_004A3310[0];
    v = 0;
    e = Item_GetTable_1_001AFC90();
    q = Inventory_GetEntry_1_001CC3F0(id);
    if (id == -1) {
        r = -1;
    } else {
        switch (e[id].xA) {
        case 1:
            v = e[id].x3D;
            break;
        case 2:
            v = e[id].x3D;
            break;
        }
        if (q[0] <= 0) {
            r = (100 - q[0]) * (v / 5) * 2;
        } else {
            r = (100 - q[0]) * (v / 5);
        }
    }
    sprintf(buf, gNotifyRodata_001FD698, r);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 340.0f, 210.0f, 1.0f);
    strcpy(buf, Msg_GetText_2_00195B10(0x9D));
    Text_Draw_2_001875C0(buf, 1, *(u32 *)&c, 320.0f, 240.0f, 1.0f);
}

/* Notify_DrawItemName_0_0019F310 */
#define Msg_GetText_2_00195B10 Msg_GetText_2_00195B10__as_Notify_DrawItemName_0_0019F310
s32 Msg_GetText_2_00195B10__as_Notify_DrawItemName_0_0019F310(s32);
#define DbItem_Find_1_0019D510 DbItem_Find_1_0019D510__as_Notify_DrawItemName_0_0019F310
s32 DbItem_Find_1_0019D510__as_Notify_DrawItemName_0_0019F310(s32);
#define strcpy strcpy__as_Notify_DrawItemName_0_0019F310
void strcpy__as_Notify_DrawItemName_0_0019F310(s8 *, s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_Notify_DrawItemName_0_0019F310
void Text_Draw_2_001875C0__as_Notify_DrawItemName_0_0019F310(f32, f32, f32, s32, s32, u32);

void Notify_DrawItemName_0_0019F310(void) {
    s8 buf[0x100] = {0};
    union { u32 w; s8 b[4]; } col;

    col.w = 0x80808080;
    col.b[3] = Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(320.0f, 150.0f, 1.1f, Msg_GetText_2_00195B10(0x91), 1, col.w);
    Text_Draw_2_001875C0(320.0f, 180.0f, 1.1f, DbItem_Find_1_0019D510(gShopBss_004A3310[0]), 1, col.w);
    strcpy(buf, Msg_GetText_2_00195B10(0x9D));
    Text_Draw_2_001875C0(320.0f, 220.0f, 1.0f, (s32)buf, 1, col.w);
}
#undef Msg_GetText_2_00195B10
#undef DbItem_Find_1_0019D510
#undef strcpy
#undef Text_Draw_2_001875C0

/* Notify_DrawItemCount_0_0019F410 */
#define DbItem_Find_1_0019D510 DbItem_Find_1_0019D510__as_Notify_DrawItemCount_0_0019F410
s8 *DbItem_Find_1_0019D510__as_Notify_DrawItemCount_0_0019F410(s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_Notify_DrawItemCount_0_0019F410
void Text_Draw_2_001875C0__as_Notify_DrawItemCount_0_0019F410(s8 *, s32, s32, f32, f32, f32);
#define Inventory_GetEntry_1_001CC3F0 Inventory_GetEntry_1_001CC3F0__as_Notify_DrawItemCount_0_0019F410
Ent *Inventory_GetEntry_1_001CC3F0__as_Notify_DrawItemCount_0_0019F410(s32);
#define gShopBss_004A3310 gShopBss_004A3310__as_Notify_DrawItemCount_0_0019F410
extern s16 gShopBss_004A3310__as_Notify_DrawItemCount_0_0019F410[];

void Notify_DrawItemCount_0_0019F410(void) {
    Buf buf = {0};
    Col col;

    col.w = 0x80808080;
    col.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(DbItem_Find_1_0019D510((u16)gShopBss_004A3310[0]), 1, col.w, 320.0f, 150.0f, 1.1f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x9A));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 180.0f, 1.0f);
    sprintf((s8 *)&buf, gNotifyRodata_001FD6A0, Inventory_GetSlot_1_001A97D0(gShopBss_004A3310[0])->x4);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 180.0f, 1.0f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x98));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 210.0f, 1.0f);
    sprintf((s8 *)&buf, gNotifyRodata_001FD6A0, Inventory_GetEntry_1_001CC3F0(gShopBss_004A3310[0])->x2);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 210.0f, 1.0f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x99));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 240.0f, 1.0f);
    sprintf((s8 *)&buf, gNotifyRodata_001FD6A0, D_004A3312[0]);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 240.0f, 1.0f);
    Ui_DrawGauge_0_00182EF0(200, 240, 400, 240, 0.0f, 0.0f, Msg_GetAlpha_0_0018B110());
    strcpy((s8 *)&buf, Msg_GetText_2_00195B10(0x9B));
    Text_Draw_2_001875C0((s8 *)&buf, 1, col.w, 320.0f, 270.0f, 1.0f);
}
#undef DbItem_Find_1_0019D510
#undef Text_Draw_2_001875C0
#undef Inventory_GetEntry_1_001CC3F0
#undef gShopBss_004A3310

/* Notify_DrawItemCountB_0_0019F690 */
#define DbItem_Find_1_0019D510 DbItem_Find_1_0019D510__as_Notify_DrawItemCountB_0_0019F690
s8 *DbItem_Find_1_0019D510__as_Notify_DrawItemCountB_0_0019F690(s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_Notify_DrawItemCountB_0_0019F690
void Text_Draw_2_001875C0__as_Notify_DrawItemCountB_0_0019F690(s8 *, s32, s32, f32, f32, f32);
#define Inventory_GetEntry_1_001CC3F0 Inventory_GetEntry_1_001CC3F0__as_Notify_DrawItemCountB_0_0019F690
Ent *Inventory_GetEntry_1_001CC3F0__as_Notify_DrawItemCountB_0_0019F690(s32);
#define gShopBss_004A3310 gShopBss_004A3310__as_Notify_DrawItemCountB_0_0019F690
extern s16 gShopBss_004A3310__as_Notify_DrawItemCountB_0_0019F690[];

void Notify_DrawItemCountB_0_0019F690(void) {
    Buf buf = {0};
    Col col;

    col.w = 0x80808080;
    col.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(DbItem_Find_1_0019D510((u16)gShopBss_004A3310[0]), 1, col.w, 320.0f, 160.0f, 1.1f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x98));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 190.0f, 1.0f);
    sprintf((s8 *)&buf, gNotifyRodata_001FD6A0, Inventory_GetEntry_1_001CC3F0(gShopBss_004A3310[0])->x2);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 190.0f, 1.0f);
    sprintf((s8 *)&buf, Msg_GetText_2_00195B10(0x9A));
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 250.0f, 220.0f, 1.0f);
    sprintf((s8 *)&buf, gNotifyRodata_001FD6A0, D_004A3312[0]);
    Text_Draw_2_001875C0((s8 *)&buf, 0, col.w, 330.0f, 220.0f, 1.0f);
    Ui_DrawGauge_0_00182EF0(200, 220, 400, 220, 0.0f, 0.0f, Msg_GetAlpha_0_0018B110());
    strcpy((s8 *)&buf, Msg_GetText_2_00195B10(0x9B));
    Text_Draw_2_001875C0((s8 *)&buf, 1, col.w, 320.0f, 250.0f, 1.0f);
}
#undef DbItem_Find_1_0019D510
#undef Text_Draw_2_001875C0
#undef Inventory_GetEntry_1_001CC3F0
#undef gShopBss_004A3310

/* Notify_DrawGold_0_0019F890 */
#define DbItem_Find_1_0019D510 DbItem_Find_1_0019D510__as_Notify_DrawGold_0_0019F890
s8 *DbItem_Find_1_0019D510__as_Notify_DrawGold_0_0019F890(s32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_Notify_DrawGold_0_0019F890
void Text_Draw_2_001875C0__as_Notify_DrawGold_0_0019F890(f32, f32, f32, s8 *, s32, u32);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Notify_DrawGold_0_0019F890
s32 Item_GetTable_1_001AFC90__as_Notify_DrawGold_0_0019F890(void);
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Notify_DrawGold_0_0019F890
u8 *Inventory_GetSlot_1_001A97D0__as_Notify_DrawGold_0_0019F890(s16);
#define sprintf sprintf__as_Notify_DrawGold_0_0019F890
void sprintf__as_Notify_DrawGold_0_0019F890(s8 *, s8 *, s32);
#define strcpy strcpy__as_Notify_DrawGold_0_0019F890
void strcpy__as_Notify_DrawGold_0_0019F890(s8 *, s32);
#define Msg_GetText_2_00195B10 Msg_GetText_2_00195B10__as_Notify_DrawGold_0_0019F890
s32 Msg_GetText_2_00195B10__as_Notify_DrawGold_0_0019F890(s32);

void Notify_DrawGold_0_0019F890(void) {
    C col;
    s8 buf[0x100];
    s32 id;
    u8 *base;
    s16 v;

    col.w = 0x80808080;
    col.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(320.0f, 160.0f, 1.1f, DbItem_Find_1_0019D510(gShopBss_004A3310[0]), 1, col.w);
    id = gShopBss_004A3310[0];
    base = (u8 *)Item_GetTable_1_001AFC90();
    if (Inventory_GetSlot_1_001A97D0(id)[5] == 2) {
        v = 5;
    } else if ((s32)*Inventory_GetEntry_1_001CC3F0(id) <= 0) {
        v = 1;
    } else {
        v = (base + id * 0x90)[7];
    }
    sprintf(buf, gNotifyRodata_001FD6A8, v);
    Text_Draw_2_001875C0(320.0f, 190.0f, 1.0f, buf, 1, col.w);
    strcpy(buf, Msg_GetText_2_00195B10(0x9C));
    Text_Draw_2_001875C0(320.0f, 220.0f, 1.0f, buf, 1, col.w);
}
#undef DbItem_Find_1_0019D510
#undef Text_Draw_2_001875C0
#undef Item_GetTable_1_001AFC90
#undef Inventory_GetSlot_1_001A97D0
#undef sprintf
#undef strcpy
#undef Msg_GetText_2_00195B10

/* Notify_DrawItemGold_0_0019FA00 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Notify_DrawItemGold_0_0019FA00
E_Notify_DrawItemGold_0_0019FA00 *Item_GetTable_1_001AFC90__as_Notify_DrawItemGold_0_0019FA00(void);
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Notify_DrawItemGold_0_0019FA00
Q *Inventory_GetSlot_1_001A97D0__as_Notify_DrawItemGold_0_0019FA00(s16);
#define Inventory_GetEntry_1_001CC3F0 Inventory_GetEntry_1_001CC3F0__as_Notify_DrawItemGold_0_0019FA00
Q *Inventory_GetEntry_1_001CC3F0__as_Notify_DrawItemGold_0_0019FA00(s16);

void Notify_DrawItemGold_0_0019FA00(void) {
    C c;
    s8 buf[0x100];
    s32 id;
    E_Notify_DrawItemGold_0_0019FA00 *e;
    s16 v;

    c.w = 0x80808080;
    c.b[3] = (s32)Msg_GetAlpha_0_0018B110();
    Text_Draw_2_001875C0(DbItem_Find_1_0019D510(gShopBss_004A3310[0]), 1, *(u32 *)&c, 330.0f, 140.0f, 1.1f);
    sprintf(buf, Msg_GetText_2_00195B10(0x96));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 250.0f, 170.0f, 1.0f);
    sprintf(buf, gNotifyRodata_001FD6A0, (s16)Inventory_GetSlot_1_001A97D0(gShopBss_004A3310[0])->x2);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 330.0f, 170.0f, 1.0f);
    sprintf(buf, Msg_GetText_2_00195B10(0x98));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 250.0f, 200.0f, 1.0f);
    sprintf(buf, gNotifyRodata_001FD6A0, Inventory_GetEntry_1_001CC3F0(gShopBss_004A3310[0])->x2);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 330.0f, 200.0f, 1.0f);
    sprintf(buf, Msg_GetText_2_00195B10(0x97));
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 220.0f, 230.0f, 1.0f);
    sprintf(buf, gNotifyRodata_001FD6A0, D_004A3312[0]);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 300.0f, 230.0f, 1.0f);
    id = gShopBss_004A3310[0];
    e = Item_GetTable_1_001AFC90();
    if (Inventory_GetSlot_1_001A97D0(id)->x5 == 2) {
        v = 5;
    } else {
        v = e[id].x6;
    }
    sprintf(buf, gNotifyRodata_001FD6A8, D_004A3312[0] * v);
    Text_Draw_2_001875C0(buf, 0, *(u32 *)&c, 355.0f, 230.0f, 1.0f);
    Ui_DrawGauge_0_00182EF0(0xB4, 0xE6, 0x1B8, 0xE6, 0.0f, 0.0f, Msg_GetAlpha_0_0018B110());
    strcpy(buf, Msg_GetText_2_00195B10(0x9B));
    Text_Draw_2_001875C0(buf, 1, *(u32 *)&c, 320.0f, 260.0f, 1.0f);
}
#undef Item_GetTable_1_001AFC90
#undef Inventory_GetSlot_1_001A97D0
#undef Inventory_GetEntry_1_001CC3F0

#ifdef NONMATCHING
#pragma explicit_zero_data on
void Inventory_Sort_0_0019FD00(void);
/* data group (src/game/data/notify_rodata.c): jtbl_001FD6B0__grp: jtbl_001FD6B0@0x0 */
int jtbl_001FD6B0__grp[0x8] __attribute__((aligned(16))) = { (int)((unsigned char *)Inventory_Sort_0_0019FD00 + 0x698), (int)((unsigned char *)Inventory_Sort_0_0019FD00 + 0x48), (int)((unsigned char *)Inventory_Sort_0_0019FD00 + 0x1A0), (int)((unsigned char *)Inventory_Sort_0_0019FD00 + 0x2C0), (int)((unsigned char *)Inventory_Sort_0_0019FD00 + 0x370), (int)((unsigned char *)Inventory_Sort_0_0019FD00 + 0x428), (int)((unsigned char *)Inventory_Sort_0_0019FD00 + 0x500), 0 };
#endif
