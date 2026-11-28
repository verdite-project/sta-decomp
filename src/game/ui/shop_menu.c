#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/item.h"
#include "game/ui.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C;
typedef struct { u8 a:3; u8 c:1; u8 d:1; u8 e:3; } BF_Menu_DrawHelpText_1_001DD700;
typedef struct {
    f32 x0;
    f32 x4;
    BF_Menu_DrawHelpText_1_001DD700 x8;
    u8 pad9[3];
    s16 xC;
    u8 padE[6];
    f32 x14;
    u8 pad18[8];
    f32 x20;
    f32 x24;
    s8 *x28;
    u8 pad2C[0x10];
} T_Menu_DrawHelpText_1_001DD700;
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent_ShopMenu_DrawRingA_0_001DD7F0;
typedef struct { u32 n; Ent_ShopMenu_DrawRingA_0_001DD7F0 *p; } L_ShopMenu_DrawRingA_0_001DD7F0;
typedef struct { u8 pad[0x28]; L_ShopMenu_DrawRingA_0_001DD7F0 *l; } O_ShopMenu_DrawRingA_0_001DD7F0;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col_ShopProc_DrawItemInfo_0_001DDA20;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; u8 a[0x10]; u8 b[0x10]; } Q;
typedef struct { u8 pad[0x54]; Q *q54; u8 pad58[4]; Q *q5C; } R_ShopProc_DrawItemInfo_0_001DDA20;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[4]; u16 xA; u8 padC[0x14]; u16 x20; u8 pad22[0x1A]; u8 x3C; u8 rest[0x53]; } E_ShopProc_DrawItemInfo_0_001DDA20;
typedef struct { u8 pad[0x10]; u8 p10[0x18]; s32 x28; u8 c[4]; f32 x30, x34, x38, x3C; } O_ShopProc_DrawItemInfo_0_001DDA20;
typedef struct { u8 pad[0x4]; L_ShopMenu_DrawRingA_0_001DD7F0 *l; } O_ShopMenu_DrawRingB_0_001DE0D0;
typedef union { u32 w; s8 b[4]; } Col_ShopProc_DrawItemStats_0_001DE2D0;
typedef struct { u8 pad0[0x10]; u8 x10[0x18]; s32 x28; u8 x2C[4]; f32 x30; f32 x34; f32 x38; f32 x3C; } O_ShopProc_DrawItemStats_0_001DE2D0;
typedef struct { u8 p0[4]; u16 x4; u8 x6; u8 p7[3]; u16 xA; u8 pC[0x14]; u16 x20; u8 p22[0x1A]; u8 x3C; u8 p3D[0x53]; } E_ShopProc_DrawItemStats_0_001DE2D0;
typedef struct { s32 x0; s32 x4; u8 p8[8]; u8 x10[0x10]; u8 x20[0x10]; } R_ShopProc_DrawItemStats_0_001DE2D0;
typedef struct { u8 p0[0x300]; R_ShopProc_DrawItemStats_0_001DE2D0 r[2]; } Rs;
typedef struct { u8 p0[0x54]; Rs *x54; u8 p58[4]; Rs *x5C; } G_ShopProc_DrawItemStats_0_001DE2D0;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xB]; s8 b3F; } Ent_ShopMenu_DrawRingC_0_001DEB00;
typedef struct { u32 n; Ent_ShopMenu_DrawRingC_0_001DEB00 *p; } L_ShopMenu_DrawRingC_0_001DEB00;
typedef struct { L_ShopMenu_DrawRingC_0_001DEB00 *l; } O_ShopMenu_DrawRingC_0_001DEB00;
typedef struct { s32 x0; s32 x4; u8 pad[8]; s8 x10[0x10]; s8 x20[0x10]; } E_ShopProc_DrawCommand_2_001DED50;
typedef struct { u8 p0[0x34]; E_ShopProc_DrawCommand_2_001DED50 *x34; } G_ShopProc_DrawCommand_2_001DED50;
typedef struct { u8 p0[0x10]; s8 x10[0x18]; s32 x28; Col_ShopProc_DrawItemInfo_0_001DDA20 c; f32 x30, x34, x38, x3C; } O_ShopProc_DrawCommand_2_001DED50;
typedef struct { u8 a:3; u8 b:5; } BF_Menu_DrawItemDesc_1_001DF360;
typedef struct { f32 x0; f32 x4; BF_Menu_DrawItemDesc_1_001DF360 x8; u8 p9[5]; s16 xE; u8 p10[4]; f32 x14; u8 p18[8]; f32 x20; f32 x24; u8 p28[0x14]; } T_Menu_DrawItemDesc_1_001DF360;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[0xC]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[0x24]; List *list; } Res;
typedef union { u32 w; s8 b[4]; } Col;
typedef struct { u8 pad0[0x10]; u8 x10[0x18]; s32 x28; u8 x2C[4]; f32 x30; f32 x34; f32 x38; f32 x3C; } O;
#ifndef NONMATCHING
extern s32 D_00201E50;
#else
/* data twins (src/game/data/sdata.c): D_00201E50 */
static s32 D_00201E50 = -1;
#endif
#ifndef NONMATCHING
extern f32 D_00202360;
#else
/* data twins (src/game/data/sbss.c): D_00202360 */
static f32 D_00202360;
#endif
#ifndef NONMATCHING
extern s32 D_00202378;
#else
/* data twins (src/game/data/sbss.c): D_00202378 */
static s32 D_00202378;
#endif
extern S D_001F3A90[] __attribute__((aligned(16)));
extern S D_001F3AB0[] __attribute__((aligned(16)));
extern s8 D_001FE748[];
extern s8 D_001FE750[];
extern s8 D_001FE758[];
extern s8 D_001FE760[];
extern s8 D_001FE768[];
extern s32 D_004BABB0[];
extern s32 D_004BABC8[];
#ifndef NONMATCHING
extern s8 D_004BABE0[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BABE0 */
static s8 D_004BABE0[0x14];
#endif
extern f32 D_004BABF4[];
extern f32 D_004BABF8[];
#ifndef NONMATCHING
extern f32 D_004BAC0C[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BAC0C */
static f32 D_004BAC0C[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_004BAC10[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BAC10 */
static f32 D_004BAC10[0x3];
#endif
#ifndef NONMATCHING
extern u32 D_004BAC1C[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BAC1C */
static u32 D_004BAC1C[0x1];
#endif
extern S D_001F3A70 __attribute__((aligned(16)));
#ifndef NONMATCHING
extern char D_004BAA70[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BAA70 */
static char D_004BAA70[0x100];
#endif
#ifndef NONMATCHING
extern u8 D_004BAB70[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BAB70 */
static u8 D_004BAB70[0x14];
#endif
extern f32 D_004BAB84[];
extern f32 D_004BAB88[];
#ifndef NONMATCHING
extern f32 D_004BAB9C[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BAB9C */
static f32 D_004BAB9C[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_004BABA0[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BABA0 */
static f32 D_004BABA0[0x3];
#endif
#ifndef NONMATCHING
extern u32 D_004BABAC[];
#else
/* data twins (src/game/data/save_system_start_bss.c): D_004BABAC */
static u32 D_004BABAC[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_0020237C;
#else
/* data twins (src/game/data/sbss.c): D_0020237C */
static s32 D_0020237C;
#endif
extern S D_001F3A50[] __attribute__((aligned(16)));
#ifndef NONMATCHING
extern f32 D_0020235C;
#else
/* data twins (src/game/data/sbss.c): D_0020235C */
static f32 D_0020235C;
#endif
#ifndef NONMATCHING
extern f32 D_00202364;
#else
/* data twins (src/game/data/sbss.c): D_00202364 */
static f32 D_00202364;
#endif
#ifndef NONMATCHING
extern f32 D_00202368;
#else
/* data twins (src/game/data/sbss.c): D_00202368 */
static f32 D_00202368;
#endif
#ifndef NONMATCHING
extern f32 D_0020236C;
#else
/* data twins (src/game/data/sbss.c): D_0020236C */
static f32 D_0020236C;
#endif
#ifndef NONMATCHING
extern f32 D_00202370;
#else
/* data twins (src/game/data/sbss.c): D_00202370 */
static f32 D_00202370;
#endif
extern s8 D_001FE7D0__as_ShopProc_DrawCommand_2_001DED50[];
extern s8 D_001FE7D8__as_ShopProc_DrawCommand_2_001DED50[];
extern s8 D_001FE7E0__as_ShopProc_DrawCommand_2_001DED50[];
extern s8 D_001FE7E8__as_ShopProc_DrawCommand_2_001DED50[];
extern s8 D_001FE7F0__as_ShopProc_DrawCommand_2_001DED50[];
extern s8 D_001FE7F8__as_ShopProc_DrawCommand_2_001DED50[];
#ifndef NONMATCHING
extern s32 D_00202358;
#else
/* data twins (src/game/data/sbss.c): D_00202358 */
static s32 D_00202358;
#endif
void Menu_DrawHelpText_1_001DD700(s32 a0, s32 a1);
void ShopProc_DrawItemInfo_0_001DDA20(O_ShopProc_DrawItemInfo_0_001DDA20 *o, s32 kind, u32 id, s32 a3);
void ShopProc_DrawItemStats_0_001DE2D0(O_ShopProc_DrawItemStats_0_001DE2D0 *o, s32 a1, u32 mode, s32 id);
void ShopProc_DrawCommand_2_001DED50(O_ShopProc_DrawCommand_2_001DED50 *o, s32 sel, u32 id, u32 n);
void Menu_DrawItemFrame_0_001DF470(s32 a0, f32 f);
void MenuProc_DrawLabel_0_001DF580(O *o, s32 a1, u32 mode, Col a3);
u32 strlen(void *);
void TextParam_Init_1_00187A90(void *, void *, u64);
s32 Text_Render_2_00188010(void *, C);
s8* Msg_GetText_2_00195B10(s32);
O_ShopMenu_DrawRingA_0_001DD7F0* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
f32 Vec2_Angle_1_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void Ui_DrawList_1_001829B0(void *, s8*, void (*)(void), s32);
void Ui_DrawSprite_2_00181680(s32, void*, void*, void*, S*, s32);
void Ui_DrawWindow_0_00183650(void *);
void Text_Draw_2_001875C0(s8 *, s32, Col_ShopProc_DrawItemInfo_0_001DDA20, f32, f32, f32);
u8* Inventory_GetSlot_1_001A97D0(s32);
E_ShopProc_DrawItemInfo_0_001DDA20* Item_GetTable_1_001AFC90(void);
u8* Inventory_GetEntry_1_001CC3F0(s32);
s32 sprintf(void *, void *, ...);
s8* strcpy(s8 *, s8 *);
f64 fptodp(f32);
void Color_Pulse_1_00187960(f32, void *);
s16 PlayerData_GetGold_0_001CBA30(void);
R_ShopProc_DrawItemInfo_0_001DDA20* MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemInfo_0_001DDA20(s32);
O_ShopMenu_DrawRingB_0_001DE0D0* MenuLayout_Get_1_00189050__as_ShopMenu_DrawRingB_0_001DE0D0(s32);
void Text_Draw_2_001875C0__as_ShopProc_DrawItemStats_0_001DE2D0(char *, s32, Col_ShopProc_DrawItemStats_0_001DE2D0, f32, f32, f32);
G_ShopProc_DrawItemStats_0_001DE2D0* MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemStats_0_001DE2D0(s32);
u8* Inventory_GetSlot_1_001A97D0__as_ShopProc_DrawItemStats_0_001DE2D0(s16);
u8* Inventory_GetEntry_1_001CC3F0__as_ShopProc_DrawItemStats_0_001DE2D0(s16);
s32 sprintf__as_ShopProc_DrawItemStats_0_001DE2D0(char *, const char *, ...);
O_ShopMenu_DrawRingC_0_001DEB00* MenuLayout_Get_1_00189050__as_ShopMenu_DrawRingC_0_001DEB00(s32);
G_ShopProc_DrawCommand_2_001DED50* MenuLayout_GetSub_1_00189020__as_ShopProc_DrawCommand_2_001DED50(s32);
void Text_Draw_2_001875C0__as_ShopProc_DrawCommand_2_001DED50(f32, f32, f32, s8 *, s32, Col_ShopProc_DrawItemInfo_0_001DDA20);
void sprintf__as_ShopProc_DrawCommand_2_001DED50(s8 *, s8 *, ...);
s8* DbItem_FindA_1_0019D4A0(s32);
Res* MenuLayout_Get_1_00189050__as_Menu_DrawItemFrame_0_001DF470(s32);
s32 MenuLayout_GetSub_1_00189020__as_Menu_DrawItemFrame_0_001DF470(s32);
void Ui_DrawList_1_001829B0__as_Menu_DrawItemFrame_0_001DF470(Item *, s32, void (*)(), s32);

/* Menu_DrawHelpText_1_001DD700 */
#define MenuProc_DrawLabel_0_001DF580 MenuProc_DrawLabel_0_001DF580__as_Menu_DrawHelpText_1_001DD700
void MenuProc_DrawLabel_0_001DF580__as_Menu_DrawHelpText_1_001DD700();

/* Menu_DrawHelpText_1_001DD700 */
/* Menu_DrawHelpText_1_001DD700 */
void Menu_DrawHelpText_1_001DD700(s32 a0, s32 a1) {
    C col;
    T_Menu_DrawHelpText_1_001DD700 t;
    s8 *s;
    col.w = 0x80808080;
    a0 += a1;
    if (D_00201E50 != a0) {
        D_00201E50 = a0;
        D_00202360 = D_002020D4;
    }
    s = Msg_GetText_2_00195B10(a0 + 0x12C);
    if (s == 0) {
        return;
    }
    TextParam_Init_1_00187A90(&t, s, strlen(s));
    t.x0 = 622.0f;
    t.x4 = 415.0f;
    t.x8.a = 2;
    t.x24 = 1.0f;
    t.x20 = 0.7f;
    t.x14 = 3.0f * (D_002020D4 - D_00202360);
    Text_Render_2_00188010(&t, col);
    Menu_DrawBackground_0_00187B20(1);
}

/* ShopMenu_DrawRingA_0_001DD7F0 */

void ShopMenu_DrawRingA_0_001DD7F0(s32 arg, s32 arg1, f32 ang) {
    u32 i;
    L_ShopMenu_DrawRingA_0_001DD7F0 *l;
    s8 *base;
    Ent_ShopMenu_DrawRingA_0_001DD7F0 e;
    V2 q;
f32 d, a, t, dx, dy;
    l = MenuLayout_Get_1_00189050(2)->l;
    base = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    if (arg1 == -1) {
        D_00202378 = -1;
    } else {
        D_00202378 = arg1;
    }
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang / 2.0f;
        e.x = 735.0f + d * sinf(a);
        e.y = 129.0f + d * cosf(a);
        }
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, ShopProc_DrawItemInfo_0_001DDA20, arg);
    }
}

/* ShopProc_DrawItemInfo_0_001DDA20 */
// mwcc=mwcps2-3.0b38-030307
/* MATCH with mwccps2 3.0b38 (addi range check); case 0x12E: ((volatile O_ShopProc_DrawItemInfo_0_001DDA20 *)o)->x38 fixes lwc1/lw order */

static inline f32 u2f_ShopProc_DrawItemInfo_0_001DDA20(u32 x) { return x; }

void ShopProc_DrawItemInfo_0_001DDA20(O_ShopProc_DrawItemInfo_0_001DDA20 *o, s32 kind, u32 id, s32 a3) {
    s8 buf[256];
    S t __attribute__((aligned(16)));
    Col_ShopProc_DrawItemInfo_0_001DDA20 col;
    s32 n = (s16)a3;
    Q *q;
    s32 flag;
    E_ShopProc_DrawItemInfo_0_001DDA20 *e;
    s32 v;

    t = D_001F3A90[0];
    if (id < 300) {
        t.x = o->x30;
        t.y = o->x34;
        if (id == 0) {
            o->c[0] = 0x40;
            o->c[1] = 0x40;
            o->c[2] = 0x40;
        }
        Ui_DrawSprite_2_00181680(o->x28, o, (u8 *)o + 0x10, o->c, &t, id);
        return;
    }
    switch (id) {
    case 300: {
        S t2 __attribute__((aligned(16)));
        t2 = D_001F3AB0[0];
        q = &MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemInfo_0_001DDA20(0)->q54[kind + 15];
        col.w = 0x30808080;
        t2.x = o->x38;
        t2.y = o->x3C;
        Ui_DrawSprite_2_00181680(q->x4, q->a, q->b, &col, &t2, id);
        break;
    }
    case 301:
        q = &MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemInfo_0_001DDA20(0)->q5C[kind + 15];
        col.w = 0x30808080U;
        t.m[0] = 1.1f;
        t.m[3] = 1.0f;
        t.x = o->x38 - 5.0f;
        t.y = o->x3C - 4.0f;
        Ui_DrawSprite_2_00181680(q->x4, q->a, q->b, &col, &t, id);
        break;
    }
    switch (kind) {
    case 0:
        switch (id) {
        case 10001:
            D_004BAC0C[0] = o->x38;
            D_004BAC10[0] = o->x3C;
            D_004BABF8[0] = D_004BABF4[0] = 1.25f;
            D_004BAC1C[0] = 0x80FFFFFF;
            Ui_DrawWindow_0_00183650(D_004BABE0);
            break;
        }
        break;
    case 1:
        switch (id) {
        case 0x12F:
            if (n > 0) {
                v = 0;
                flag = 0;
                if (n != D_004BABB0[kind]) {
                    D_004BABC8[kind] = 0;
                    D_004BABB0[kind] = n;
                }
                if (D_004BABC8[kind] < 0x80)
                    D_004BABC8[kind] += 0x10;
                col.w = 0x80808080;
                switch (D_00202378) {
                case 0:
                    break;
                case 1:
                case 4:
                    v = *Inventory_GetSlot_1_001A97D0(n);
                    flag = 1;
                    break;
                case -1:
                case 2:
                case 3:
                case 5:
                case 6:
                    v = *Inventory_GetEntry_1_001CC3F0(n);
                    flag = 0;
                    break;
                }
                sprintf(buf, D_001FE748, v);
                if (Item_GetCategory_0_001AFBD0(n) == 0) {
                    strcpy(buf, D_001FE750);
                } else if (Item_GetCategory_0_001AFBD0(n) == 1) {
                    e = &Item_GetTable_1_001AFC90()[(s16)n];
                    switch (e->x20) {
                    case 5:
                    case 6:
                        strcpy(buf, D_001FE750);
                        break;
                    default:
                        Item_GetDurability_0_001848A0(n);
                        break;
                    }
                } else {
                    Item_GetDurability_0_001848A0(n);
                }
                if (Item_GetStatValue_0_00187130(n, flag))
                    col.w = 0x80404080;
                else
                    col.w = 0x80808080;
                Text_Draw_2_001875C0(buf, 2, col, o->x38, o->x3C, 0.9f);
            }
            break;
        case 0x130:
            v = 0;
            if ((s16)n > 0) {
                e = &Item_GetTable_1_001AFC90()[a3];
                if (e->xA == 1) {
                    v = e->x3C;
                    switch (e->x20) {
                    case 5:
                    case 6:
                        v = 0;
                        break;
                    }
                } else if (e->xA == 2) {
                    v = e->x3C;
                }
                col.w = 0x80808080;
                if (v == 0)
                    strcpy(buf, D_001FE758);
                else
                    sprintf(buf, D_001FE760, v);
                Text_Draw_2_001875C0(buf, 0, col, o->x38, o->x3C, 0.8f);
            }
            break;
        }
        break;
    case 2:
        switch (id) {
        case 0x12E:
            if ((s16)n > 0) {
                E_ShopProc_DrawItemInfo_0_001DDA20 *e2 = &Item_GetTable_1_001AFC90()[a3];
                if (n != D_004BABB0[kind]) {
                    D_004BABC8[kind] = 0;
                    D_004BABB0[kind] = n;
                }
                if (D_004BABC8[kind] < 0x80)
                    D_004BABC8[kind] += 0x10;
                col.w = 0x80808080;
                sprintf(buf, D_001FE768, (double)(u2f_ShopProc_DrawItemInfo_0_001DDA20(e2->x4) / 10.0f));
                Text_Draw_2_001875C0(buf, 2, col, ((volatile O_ShopProc_DrawItemInfo_0_001DDA20 *)o)->x38, o->x3C, 0.9f);
            }
            break;
        }
        break;
    }
}

/* ShopMenu_DrawRingB_0_001DE0D0 */

void ShopMenu_DrawRingB_0_001DE0D0(s32 arg, f32 ang) {
    u32 i;
    L_ShopMenu_DrawRingA_0_001DD7F0 *l;
    s8 *base;
    Ent_ShopMenu_DrawRingA_0_001DD7F0 e;
    V2 q;
f32 d, a, t, dx, dy;
    l = MenuLayout_Get_1_00189050__as_ShopMenu_DrawRingB_0_001DE0D0(6)->l;
    base = MenuLayout_GetSub_1_00189020(6);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        e.x = 735.0f + d * sinf(a);
        e.y = 129.0f + d * cosf(a);
        }
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, ShopProc_DrawItemStats_0_001DE2D0, arg);
    }
}

/* rodata_001FE790 */
/* rodata_001FE790: the game's data at 0x001FE790..., one object per label. */
/* used by: ShopProc_DrawItemStats_0_001DE2D0, ShopProc_DrawCommand_2_001DED50, text_001DE2D0.s */
#pragma explicit_zero_data on

const char D_001FE790[0x5] __attribute__((aligned(16))) = "/%3d\000";
const s32 D_001FE798[0x2] = { 0x43, 0 };
const s32 D_001FE7A0[0x4] = { 0x6425, 0, 0, 0 };
#pragma explicit_zero_data reset

/* ShopProc_DrawItemStats_0_001DE2D0 */
/* round 3 near-miss: 6 words: lw a2 (Col_ShopProc_DrawItemStats_0_001DE2D0 stack arg) vs lwc1 f12 order before Text_Draw_2_001875C0, 3 sites */
static inline f32 u2f_ShopProc_DrawItemStats_0_001DE2D0(u32 x) { return x; }

void ShopProc_DrawItemStats_0_001DE2D0(O_ShopProc_DrawItemStats_0_001DE2D0 *o, s32 a1, u32 mode, s32 id) {
    S buf __attribute__((aligned(16)));
    Col_ShopProc_DrawItemStats_0_001DE2D0 c0;
    Col_ShopProc_DrawItemStats_0_001DE2D0 cA;
    Col_ShopProc_DrawItemStats_0_001DE2D0 c9;
    Col_ShopProc_DrawItemStats_0_001DE2D0 c1;
    Col_ShopProc_DrawItemStats_0_001DE2D0 cE;
    Col_ShopProc_DrawItemStats_0_001DE2D0 cD;
    u32 s;
    buf = D_001F3A70;
    c0.w = 0x80808080;
    if ((u32)(mode - 1000) <= 1 || mode == 1002) {
        switch (D_00202378) {
        case 2: case 3: case 4: case 5: case 6:
            return;
        }
    }
    if (mode < 600) {
        buf.x = o->x30;
        buf.y = o->x34;
        if (mode == 0) {
            o->x2C[0] = 0x40;
            o->x2C[1] = 0x40;
            o->x2C[2] = 0x40;
        }
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 0x259:
        break;
    case 0x25A:
        break;
    case 0x25B: {
        R_ShopProc_DrawItemStats_0_001DE2D0 *r;
        Rs *q = MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemStats_0_001DE2D0(0)->x54;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[0];
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x25C: {
        R_ShopProc_DrawItemStats_0_001DE2D0 *r;
        Rs *q = MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemStats_0_001DE2D0(0)->x5C;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[0];
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x25D:
        if (id > 0) {
            f32 f;
            s32 m;
            Item_GetDurability_0_001848A0(id);
            m = 0;
            switch (D_00202378) {
            case 1:
            case 4:
                f = u2f_ShopProc_DrawItemStats_0_001DE2D0(*Inventory_GetSlot_1_001A97D0__as_ShopProc_DrawItemStats_0_001DE2D0(id));
                m = 1;
                break;
            case 2:
            case 3:
            case 5:
            case 6:
                f = u2f_ShopProc_DrawItemStats_0_001DE2D0(*Inventory_GetEntry_1_001CC3F0__as_ShopProc_DrawItemStats_0_001DE2D0(id));
                m = 0;
                break;
            case 0:
                break;
            }
            if (Item_GetStatValue_0_00187130(id, m) != 0) {
                cD.w = 0x80404080;
            } else {
                cD.w = 0x80808080;
            }
            sprintf__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, D_001FE748, (s32)f);
            if (Item_GetCategory_0_001AFBD0(id) == 0) {
                strcpy(D_004BAA70, D_001FE750);
            } else if (Item_GetCategory_0_001AFBD0(id) == 1) {
                E_ShopProc_DrawItemStats_0_001DE2D0 *e = &Item_GetTable_1_001AFC90()[id];
                switch (e->x20) {
                case 5:
                case 6:
                    strcpy(D_004BAA70, D_001FE750);
                    break;
                }
            }
            Text_Draw_2_001875C0__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, 0, cD, ((volatile O_ShopProc_DrawItemStats_0_001DE2D0 *)o)->x38, o->x3C, 0.9f);
        }
        break;
    case 0x25E:
        if (id > 0) {
            s32 v = 0;
            E_ShopProc_DrawItemStats_0_001DE2D0 *e = &Item_GetTable_1_001AFC90()[id];
            if (e != NULL && id != -1) {
                if (e->xA == 1) {
                    e = &Item_GetTable_1_001AFC90()[id];
                    switch (e->x20) {
                    case 5:
                    case 6:
                        v = 0;
                        break;
                    default:
                        v = e->x3C;
                        break;
                    }
                } else if (e->xA == 2) {
                    v = e->x3C;
                }
                cE.w = 0x80808080;
                if (v == 0) {
                    strcpy(D_004BAA70, D_001FE758);
                } else {
                    sprintf__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, D_001FE790, v);
                }
                Text_Draw_2_001875C0__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, 0, cE, ((volatile O_ShopProc_DrawItemStats_0_001DE2D0 *)o)->x38, o->x3C, 0.9f);
                return;
            }
        }
        break;
    case 0x25F: {
        R_ShopProc_DrawItemStats_0_001DE2D0 *r;
        Rs *q = MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemStats_0_001DE2D0(0)->x54;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[1];
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x260: {
        R_ShopProc_DrawItemStats_0_001DE2D0 *r;
        Rs *q = MenuLayout_GetSub_1_00189020__as_ShopProc_DrawItemStats_0_001DE2D0(0)->x5C;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[1];
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x261:
        if (id > 0) {
            E_ShopProc_DrawItemStats_0_001DE2D0 *e = &Item_GetTable_1_001AFC90()[id];
            c1.w = 0x80808080;
            sprintf__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, D_001FE768, fptodp(u2f_ShopProc_DrawItemStats_0_001DE2D0(e->x4) / 10.0f));
            Text_Draw_2_001875C0__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, 0, c1, ((volatile O_ShopProc_DrawItemStats_0_001DE2D0 *)o)->x38, o->x3C, 0.9f);
            return;
        }
        break;
    case 0x2711:
        D_004BAB9C[0] = o->x38;
        D_004BABA0[0] = o->x3C;
        D_004BAB84[0] = 1.0f;
        D_004BABAC[0] = 0x80FFFFFF;
        D_004BAB88[0] = 1.0f;
        Ui_DrawWindow_0_00183650(D_004BAB70);
        return;
    case 0x3E8:
        buf.x = o->x30;
        buf.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    case 0x3E9: {
        c9.w = 0x80808080;
        Text_Draw_2_001875C0__as_ShopProc_DrawItemStats_0_001DE2D0(D_001FE798, 2, c9, ((volatile O_ShopProc_DrawItemStats_0_001DE2D0 *)o)->x38, o->x3C, 0.9f);
        return;
    }
    case 0x3EA:
        if (id > 0) {
            E_ShopProc_DrawItemStats_0_001DE2D0 *e = &Item_GetTable_1_001AFC90()[id];
            u8 *r = Inventory_GetSlot_1_001A97D0__as_ShopProc_DrawItemStats_0_001DE2D0(id);
            cA.w = 0x80808080;
            if (r[5] == 2) {
                sprintf__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, D_001FE7A0, 5);
            } else {
                sprintf__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, D_001FE7A0, e->x6);
            }
            Text_Draw_2_001875C0__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, 2, cA, ((volatile O_ShopProc_DrawItemStats_0_001DE2D0 *)o)->x38, o->x3C, 0.9f);
            return;
        }
        sprintf__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, D_001FE750);
        Text_Draw_2_001875C0__as_ShopProc_DrawItemStats_0_001DE2D0(D_004BAA70, 2, c0, ((volatile O_ShopProc_DrawItemStats_0_001DE2D0 *)o)->x38, o->x3C, 0.9f);
        break;
    }
}

/* ShopMenu_DrawRingC_0_001DEB00 */

void ShopMenu_DrawRingC_0_001DEB00(s32 arg, s32 arg1, f32 ang) {
    u32 i;
    L_ShopMenu_DrawRingC_0_001DEB00 *l;
    s8 *base;
    Ent_ShopMenu_DrawRingC_0_001DEB00 e;
    V2 q;
f32 d, a, t, dx, dy;
    s32 c;
    l = MenuLayout_Get_1_00189050__as_ShopMenu_DrawRingC_0_001DEB00(6)->l;
    base = MenuLayout_GetSub_1_00189020(6);
    Menu_DrawBackground_0_00187B20(0);
    D_00202378 = arg1;
    D_0020237C = arg;
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 108.0f;
            p.y = 72.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 108.0f;
        dy = e.y - 72.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        c = (s32)(256.0f * (ang / -2.99f)) + 0x80;
        if (c < 0) c = 0;
        if (c > 0x80) c = 0x80;
        e.b3F = c;
        e.x = 108.0f + d * sinf(a);
        e.y = 72.0f + d * cosf(a);
        }
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, ShopProc_DrawCommand_2_001DED50, arg);
    }
}

/* rodata_001FE7CC */
/* rodata_001FE7CC: the game's data at 0x001FE7CC..., one object per label. */
/* used by: ShopProc_DrawCommand_2_001DED50 */
#pragma explicit_zero_data on

const s32 D_001FE7CC[0x1] = { 0 };
const s8 D_001FE7D0[0x8] __attribute__((aligned(4))) = "BUY\000\000\000\000\000";
const s8 D_001FE7D8[0x5] __attribute__((aligned(4))) = "SELL\000";
const s8 D_001FE7E0[0x8] __attribute__((aligned(4))) = "PUT\000\000\000\000\000";
const s8 D_001FE7E8[0x5] __attribute__((aligned(4))) = "DRAW\000";
const s8 D_001FE7F0[0x8] __attribute__((aligned(4))) = "HEALING\000";
const s8 D_001FE7F8[0x7] __attribute__((aligned(4))) = "REPAIR\000";
static const u8 pad_001FE7FF[0x1] __attribute__((aligned(1))) = { 0 };
#pragma explicit_zero_data reset

/* ShopProc_DrawCommand_2_001DED50 */

void ShopProc_DrawCommand_2_001DED50(O_ShopProc_DrawCommand_2_001DED50 *o, s32 sel, u32 id, u32 n) {
    Col_ShopProc_DrawItemInfo_0_001DDA20 c1;
    Col_ShopProc_DrawItemInfo_0_001DDA20 c2;
    S t __attribute__((aligned(16)));
    E_ShopProc_DrawCommand_2_001DED50 *e;
    s32 k;

    t = D_001F3A50[0];
    D_0020235C += 0.1f;
    if (id < 2000) {
        t.x = o->x30;
        t.y = o->x34;
        if (id == 0) {
            o->c.b[0xC - 0xC] = 0x40;
            o->c.b[0xD - 0xC] = 0x40;
            o->c.b[0xE - 0xC] = 0x40;
        }
        switch (D_00202378) {
        case 0:
        case 1:
            break;
        case 2:
            if (id == 0x1FD) return;
            break;
        case 3:
            if (sel == 100) return;
            break;
        case 4:
            if (sel == 100) return;
            break;
        case 5:
            if (id == 0x1FD) return;
            if (sel == 100) return;
            break;
        case 6:
            if (id == 0x1FB) return;
            if (id == 0x1FC) return;
            if (id == 0x1FD) return;
            if (sel == 100) return;
            break;
        }
        Ui_DrawSprite_2_00181680(o->x28, (s8 *)o, o->x10, &o->c, &t, id);
    }
    if (n == id - 1500) {
        D_00202368 = 32.0f + o->x38 + 75.0f * sinf(0.1f * D_0020235C);
        D_00202364 = 32.0f + o->x3C + 75.0f * cosf(0.1f * D_0020235C);
        e = MenuLayout_GetSub_1_00189020__as_ShopProc_DrawCommand_2_001DED50(6)->x34;
        t.x = o->x38;
        t.y = o->x3C;
        t.m[3] = 1.0f;
        t.m[0] = 1.0f;
        Color_Pulse_1_00187960(D_002020D4, &o->c);
        Ui_DrawSprite_2_00181680(e->x4, e->x10, e->x20, &o->c, &t, id);
    }
    if (n == id - 500) {
        D_00202370 = 32.0f + o->x38 + 75.0f * sinf(3.14f + 0.1f * D_0020235C);
        D_0020236C = 32.0f + o->x3C + 75.0f * cosf(3.14f + 0.1f * D_0020235C);
        if (n != 4) {
            D_00202368 = 32.0f + o->x38 + 75.0f * sinf(0.1f * D_0020235C);
            D_00202364 = 32.0f + o->x3C + 75.0f * cosf(0.1f * D_0020235C);
        }
        k = 0;
        switch (n) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            k = 0;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            k = 1;
            break;
        }
        e = &MenuLayout_GetSub_1_00189020__as_ShopProc_DrawCommand_2_001DED50(6)->x34[k];
        t.x = o->x38;
        t.y = o->x3C;
        t.m[3] = 1.0f;
        t.m[0] = 1.0f;
        Color_Pulse_1_00187960(D_002020D4, &o->c);
        Ui_DrawSprite_2_00181680(e->x4, e->x10, e->x20, &o->c, &t, id);
    }
    if (id == 5000) {
        c1.w = 0x80808080;
        c1.b[3] = o->c.b[3] * 2;
        switch (D_00202378) {
        case 0:
            break;
        case 1:
            strcpy(D_004BAA70, D_001FE7D0__as_ShopProc_DrawCommand_2_001DED50);
            break;
        case 2:
            strcpy(D_004BAA70, D_001FE7D8__as_ShopProc_DrawCommand_2_001DED50);
            break;
        case 3:
            strcpy(D_004BAA70, D_001FE7E0__as_ShopProc_DrawCommand_2_001DED50);
            break;
        case 4:
            strcpy(D_004BAA70, D_001FE7E8__as_ShopProc_DrawCommand_2_001DED50);
            break;
        case 5:
            strcpy(D_004BAA70, D_001FE7F0__as_ShopProc_DrawCommand_2_001DED50);
            break;
        case 6:
            strcpy(D_004BAA70, D_001FE7F8__as_ShopProc_DrawCommand_2_001DED50);
            break;
        }
        Text_Draw_2_001875C0__as_ShopProc_DrawCommand_2_001DED50(o->x38, o->x3C, 0.9f, D_004BAA70, 0, c1);
    }
    if (sel == 100) {
        c2.w = 0x80808080;
        c2.b[3] = o->c.b[3] * 2;
        if (id == 100) {
            Text_Draw_2_001875C0__as_ShopProc_DrawCommand_2_001DED50(o->x38, o->x3C, 0.9f, D_001FE798, 0, c2);
        }
        if (id == 0x65) {
            sprintf__as_ShopProc_DrawCommand_2_001DED50(D_004BAA70, D_001FE7A0, PlayerData_GetGold_0_001CBA30());
            Text_Draw_2_001875C0__as_ShopProc_DrawCommand_2_001DED50(o->x38, o->x3C, 0.9f, D_004BAA70, 2, c2);
        }
    }
}

/* Menu_DrawItemDesc_1_001DF360 */
void Menu_DrawItemDesc_1_001DF360(s32 on, s32 id) {
    T_Menu_DrawItemDesc_1_001DF360 t;
    C col;
    s8 *s = DbItem_FindA_1_0019D4A0(id);
    if (s == NULL) return;
    TextParam_Init_1_00187A90(&t, s, strlen(s));
    t.x0 = 598.0f;
    t.x4 = 286.0f;
    t.x8.a = 2;
    t.x24 = 1.0f;
    t.x20 = 1.1f;
    t.x14 = 4096.0f;
    t.xE = 100;
    col.w = 0x80808080;
    if (on) {
        D_00202358 += 0x10;
        if (D_00202358 > 0x80) D_00202358 = 0x80;
    } else {
        D_00202358 = 0;
    }
    col.c.a = D_00202358;
    Text_Render_2_00188010(&t, col);
}

/* Menu_ResetDescScroll_0_001DF460 */
void Menu_ResetDescScroll_0_001DF460(void) {
    D_00202358 = 0;
}

/* Menu_DrawItemFrame_0_001DF470 */

void Menu_DrawItemFrame_0_001DF470(s32 a0, f32 f) {
    Item it;
    u32 i;
    List *l;
    s32 base;

    l = MenuLayout_Get_1_00189050__as_Menu_DrawItemFrame_0_001DF470(0)->list;
    base = MenuLayout_GetSub_1_00189020__as_Menu_DrawItemFrame_0_001DF470(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * f;
        Ui_DrawList_1_001829B0__as_Menu_DrawItemFrame_0_001DF470(&it, base + l->items[i].idx * 8, MenuProc_DrawLabel_0_001DF580, a0);
    }
}
#undef MenuProc_DrawLabel_0_001DF580

/* MenuProc_DrawLabel_0_001DF580 */
#pragma explicit_zero_data on
S D_001F3A30 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
#define Ui_DrawSprite_2_00181680 Ui_DrawSprite_2_00181680__as_MenuProc_DrawLabel_0_001DF580
void Ui_DrawSprite_2_00181680__as_MenuProc_DrawLabel_0_001DF580(s32, void *, void *, void *, S *, u32);
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_MenuProc_DrawLabel_0_001DF580
void Text_Draw_2_001875C0__as_MenuProc_DrawLabel_0_001DF580(f32, f32, f32, s32, s32, Col);
#define Msg_GetText_2_00195B10 Msg_GetText_2_00195B10__as_MenuProc_DrawLabel_0_001DF580
s32 Msg_GetText_2_00195B10__as_MenuProc_DrawLabel_0_001DF580(s32);
void MenuProc_DrawLabel_0_001DF580(O *o, s32 a1, u32 mode, Col a3) {
    S buf __attribute__((aligned(16)));
    Col col;
    s32 id = a3.w;
    if (mode < 0x2BC) {
        buf = D_001F3A30;
        buf.x = o->x30;
        buf.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 0x2BC:
        if (id == 100) id = 10;
        col.w = 0x80808080;
        Text_Draw_2_001875C0(o->x38, o->x3C, 0.8f, Msg_GetText_2_00195B10(id + 0x50), 1, col);
        break;
    case 0x2BD:
        break;
    }
}
#undef Ui_DrawSprite_2_00181680
#undef Text_Draw_2_001875C0
#undef Msg_GetText_2_00195B10

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/save_system_start_bss.c): D_004BAB84, D_004BABB0, D_004BABF4 */
f32 D_004BAB84[0x6] __attribute__((aligned(4)));
s32 D_004BABB0[0xc];
f32 D_004BABF4[0x6] __attribute__((aligned(4)));
#endif
