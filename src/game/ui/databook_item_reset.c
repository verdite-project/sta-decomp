#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/save.h"
#include "game/ui.h"
#include "game/math.h"
typedef struct { u128 q[2]; } Q2;
typedef UiArg Arg;
typedef struct { u32 id; s32 x; s32 y; } Ent_DbItem_ResetLayout_0_00197DD0;
typedef struct { s32 h0; u32 n; s32 h8; s32 hC; Ent_DbItem_ResetLayout_0_00197DD0 e[1]; } Tbl;
typedef union { u32 w; u8 b[4]; } Col_DbItem_ResetLayout_0_00197DD0;
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent_DbMap_Draw_0_00198160;
typedef struct { u32 n; Ent_DbMap_Draw_0_00198160 *p; } L;
typedef struct { u8 pad[0x1C]; L *l; } O;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_DbMapProc_DrawInfo_1_00198570;
typedef struct {
    u64 a, b;
    f32 x, y;
} S;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col_DbMapProc_DrawInfo_1_00198570 x2C;
    f32 x30, x34, x38, x3C;
} A;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; Vec x10; Vec x20; } B;
typedef struct { u8 pad[0x54]; u8 *x54; } P_DbMapProc_DrawInfo_1_00198570;
typedef struct { u8 pad[0xE]; u8 xE; } G;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } M;
typedef struct { s32 x0; u32 n; } P_DbMap_ResetLayout_0_00198D80;
extern Q2 D_001F2F40;
extern s32 D_00201D3C;
extern u32 D_00202190;
#ifndef NONMATCHING
extern char D_001FD388[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD388 */
static char D_001FD388[0x10] __attribute__((aligned(8))) = { -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
extern s32 *D_00201D3C__as_DbItem_LoadEntry_0_00197F90;
#ifndef NONMATCHING
extern f32 D_00201D44;
#else
/* data twins (src/game/data/sdata.c): D_00201D44 */
static f32 D_00201D44 = -2.99f;
#endif
#ifndef NONMATCHING
extern s32 D_002021A8;
#else
/* data twins (src/game/data/sbss.c): D_002021A8 */
static s32 D_002021A8;
#endif
#ifndef NONMATCHING
extern s32 D_004A1450[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1450 */
static s32 D_004A1450[0xc8];
#endif
#ifndef NONMATCHING
extern s32 D_004A18B0[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A18B0 */
static s32 D_004A18B0[0x2];
#endif
extern S D_001F2FE0 __attribute__((aligned(16)));
#ifndef NONMATCHING
extern u32 D_002021A4;
#else
/* data twins (src/game/data/sbss.c): D_002021A4 */
static u32 D_002021A4;
#endif
#ifndef NONMATCHING
extern s8 D_001FD398[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD398 */
static s8 D_001FD398[0x8] = { 0x25, 0x64, 0x20, -0x7f, -0x6d, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD3A0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3A0 */
static s8 D_001FD3A0[0x10] __attribute__((aligned(8))) = { -0x7f, 0x40, -0x7f, 0x40, -0x6d, 0x47, -0x61, 0x72, -0x6a, -0x3b, -0x69, -0x5a, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD3B0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3B0 */
static s8 D_001FD3B0[0x10] __attribute__((aligned(8))) = { 0x20, 0x20, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD3C0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3C0 */
static s8 D_001FD3C0[0x8] = { 0x2d, 0x2d, 0x2d, 0x20, -0x7f, -0x6d, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD3C8[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3C8 */
static s8 D_001FD3C8[0x8] = { 0x25, 0x33, 0x64, 0x20, -0x7f, -0x6d, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD3D0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3D0 */
static s8 D_001FD3D0[0x10] __attribute__((aligned(8))) = { -0x7f, 0x40, -0x73, -0x3b, -0x73, -0x7e, -0x61, 0x72, -0x6a, -0x3b, -0x69, -0x5a, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD3E0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3E0 */
static s8 D_001FD3E0[0x8] = { 0x20, 0x2d, 0x2d, 0x2d, 0x20, -0x7f, -0x6d, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD3E8[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3E8 */
static s8 D_001FD3E8[0x8] = { 0x20, 0x25, 0x33, 0x64, 0x20, -0x7f, -0x6d, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_004A1770[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1770 */
static s8 D_004A1770[0x100];
#endif
#ifndef NONMATCHING
extern s8 D_004A1870[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1870 */
static s8 D_004A1870[0x14];
#endif
extern f32 D_004A1884[];
extern f32 D_004A1888[];
#ifndef NONMATCHING
extern f32 D_004A189C[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A189C */
static f32 D_004A189C[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_004A18A0[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A18A0 */
static f32 D_004A18A0[0x3];
#endif
#ifndef NONMATCHING
extern u32 D_004A18AC[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A18AC */
static u32 D_004A18AC[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_004A18B8[];
#else
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A18B8 */
static f32 D_004A18B8[0x2];
#endif
extern Q2 D_001F2FC0;
extern u32 D_002022B8;
#ifndef NONMATCHING
extern s8 D_001FD3F0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD3F0 */
static s8 D_001FD3F0[0x8] = "%s\000\000\000\000\000\000";
#endif
char* DbItem_GetListName_1_00197F30(s32 i);
void DbItemProc_Pos_0_00198100(s32 arg0, void *arg1, void *arg2);
void DbMap_Draw_0_00198160(u8 *arg0);
void DbMap_DrawRing_0_001982A0(s32 arg, f32 ang);
void DbMapProc_DrawInfo_1_00198570(A *o, s32 mode, u32 kind);
void DbMap_UpdateWrap_0_00198BD0(s32 arg0);
void DbMap_Update_0_00198BE0(M *m);
void DbMap_ResetLayout_0_00198D80(void);
s8* DbMap_GetListName_1_00198F30(s32 a);
void DbMap_BuildList_1_00199000(void);
void DbMapProc_Pos_0_00199110(s32 arg0, void *arg1, void *arg2);
Tbl* DbItem_GetCount_1_001958A0(void);
s32 Save_TestItemBit_1_001A9B40(s16);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
char* DbItem_Find_1_0019D510(s32 i);
u8* Item_GetTable_1_001AFC90(void);
void memset(void *, s32, s32);
s32 ItemSort_GetCount_0_00195BE0(s32);
void Inventory_GetEntry_1_001CC3F0(s16);
void DbItem_GetListName_1_00197F30__as_DbItem_ResetLayout_0_00197DD0(void);
void DbItemProc_Pos_0_00198100__as_DbItem_ResetLayout_0_00197DD0_(void);
s32 DbMap_GetName_0_00195A30(s32);
void Text_Draw_2_001875C0(s32, s32, Col_DbItem_ResetLayout_0_00197DD0, f32, f32, f32);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
O* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
f32 Vec2_Angle_1_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void Ui_DrawList_1_001829B0(Ent_DbMap_Draw_0_00198160 *, s8 *, void (*)(void), s32);
void Ui_DrawSprite_2_00181680(s32, Vec *, Vec *, Col_DbMapProc_DrawInfo_1_00198570 *, S *, u32);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
G* PlayerData_Get_2_001C9BA0(void);
void Ui_DrawWindow_0_00183650(s8 *);
void Ui_SetOffset_0_001803D0(s32, s32);
void Snd_PlaySe_3_00131600(s32, s32);
P_DbMap_ResetLayout_0_00198D80* DbMap_GetCount_1_001958E0(void);
s8* DbMap_GetLocationName_1_00195AA0(s32);
void UiAnim_SetTarget_1_0017F470__as_DbItem_ResetLayout_0_00197DD0__(f32, s32, s32);
void DbMapProc_DrawInfo_1_00198570__as_DbItem_ResetLayout_0_00197DD0__(void);
void Text_Draw_2_001875C0__as_DbMapProc_DrawInfo_1_00198570(f32, s8 *, f32, f32, s32, u32);
P_DbMapProc_DrawInfo_1_00198570* MenuLayout_GetSub_1_00189020__as_DbMapProc_DrawInfo_1_00198570(s32);
s32* DbMap_GetCount_1_001958E0__as_DbMap_BuildList_1_00199000(void);

/* DbItem_ResetLayout_0_00197DD0___ */
#define DbMapProc_Pos_0_00199110 DbMapProc_Pos_0_00199110__as_DbItem_ResetLayout_0_00197DD0___
void DbMapProc_Pos_0_00199110__as_DbItem_ResetLayout_0_00197DD0___(void);

/* DbItem_ResetLayout_0_00197DD0___ */
/* DbItem_ResetLayout_0_00197DD0__ */

/* DbItem_ResetLayout_0_00197DD0__ */
/* DbItem_ResetLayout_0_00197DD0_ */

/* DbItem_ResetLayout_0_00197DD0 */

void DbItem_ResetLayout_0_00197DD0(void) {
    Q2 q;
    Arg a;
    Tbl *t;
    Ent_DbItem_ResetLayout_0_00197DD0 *e;
    u32 i;
    s32 hit;
    u32 cnt;

    t = DbItem_GetCount_1_001958A0();
    if (t != 0) {
        hit = 0;
        cnt = 0;
        e = t->e;
        for (i = 0; i < t->n; i++, e++) {
            if (e->id >= 100) {
                if (Save_TestItemBit_1_001A9B40(e->id) != 0) {
                    hit++;
                }
                cnt++;
            }
        }
        D_00202190 = (u32)(hit * 100) / cnt;
        q = D_001F2F40;
        a.fn = DbItem_GetListName_1_00197F30__as_DbItem_ResetLayout_0_00197DD0;
        a.f = -3.0f;
        a.cb = DbItemProc_Pos_0_00198100__as_DbItem_ResetLayout_0_00197DD0_;
        a.a = 0;
        a.b = 0;
        a.p = D_00201D3C;
        a.n = D_00202198;
        UiAnim_SetColor_0_0017F890(D_00201D38, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(D_00201D38, 1, 1);
        UiAnim_SetTarget_1_0017F470__as_DbItem_ResetLayout_0_00197DD0__(D_004A1430[0], D_00201D38, 1);
    }
}

/* DbItem_GetListName_1_00197F30 */
char *DbItem_GetListName_1_00197F30(s32 i)
{
    if (i < 0)
        return D_001FD388;
    if (Save_TestItemBit_1_001A9B40(i))
        return DbItem_Find_1_0019D510(i);
    return D_001FD388;
}

/* DbItem_LoadEntry_0_00197F90 */

void DbItem_LoadEntry_0_00197F90(s32 a0) {
    s32 r;
    u8 *e;
    s32 i;
    u8 *base;
    s32 v;

    base = Item_GetTable_1_001AFC90();
    D_00202198 = 0;
    memset(D_00201D3C__as_DbItem_LoadEntry_0_00197F90, -1, 4);
    for (i = 100; i < 0x400; i++) {
        Inventory_GetEntry_1_001CC3F0(ItemSort_GetCount_0_00195BE0(i));
        e = base + ItemSort_GetCount_0_00195BE0(i) * 0x90;
        if (*(u16 *)(e + 4) > 0 && (a0 >= 2 || *(u16 *)(e + 0xA) == 2)) {
            if (a0 < 2 || a0 >= 9 || (*(u16 *)(e + 0xA) == 1 && *(u16 *)(e + 0x20) == a0 - 2)) {
                v = ItemSort_GetCount_0_00195BE0(i);
                if (v < 0) {
                    r = 0;
                } else {
                    r = Save_TestItemBit_1_001A9B40(v);
                }
                if (r != 0) {
                    D_00201D3C__as_DbItem_LoadEntry_0_00197F90[D_00202198] = v;
                } else {
                    D_00201D3C__as_DbItem_LoadEntry_0_00197F90[D_00202198] = -1;
                }
                D_00202198++;
            }
        }
    }
}

/* DbItemProc_Pos_0_00198100 */
void DbItemProc_Pos_0_00198100(s32 arg0, void *arg1, void *arg2) {
    void *sp4C;

    UiAnim_Get_1_0017F840(0, &sp4C);
    M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg2, f32 *, 8) - (f32) arg0);
}

/* DbMap_Draw_0_00198160 */
/* DbMap_Draw_0_00198160 */
void DbMap_Draw_0_00198160(u8 *arg0) {
    Col_DbItem_ResetLayout_0_00197DD0 c;
    s32 s;

    s = D_004A1450[D_004A18B0[0]];
    Menu_SetFlags_0_0018A310(0xE);
    if (arg0[8] == 0x19) {
        D_00201D44 = Approachf_3_00187770(D_00201D44, -0.02f, 3.5f);
    } else {
        D_00201D44 = Approachf_3_00187770(D_00201D44, -2.99f, 3.5f);
    }
    if (!(D_00201D44 <= -2.99f)) {
        DbMap_DrawRing_0_001982A0(s, D_00201D44);
    }
    if (s >= 0) {
        s32 h = DbMap_GetName_0_00195A30(s);
        c.w = 0x80FFFFFF;
        Text_Draw_2_001875C0(h, 2, c, 622.0f, 17.0f, 1.0f);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawFrame_0_00185390(D_00201D44, 1, D_002021A8, D_004A18B0[0]);
}

/* DbMap_DrawRing_0_001982A0 */
void DbMap_DrawRing_0_001982A0(s32 arg, f32 ang) {
    u32 i;
    L *l;
    s8 *base;
    Ent_DbMap_Draw_0_00198160 e;
    V2 q;
f32 d, a, t, dx, dy;
    l = MenuLayout_Get_1_00189050(2)->l;
    base = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
        if (e.f4 == 100 || e.f4 == 200) {
            p.x = -70.0f;
            p.y = 276.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - -70.0f;
        dy = e.y - 276.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        e.x = -70.0f + d * sinf(a);
        e.y = 276.0f + d * cosf(a);
        } else {
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
        }
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, DbMapProc_DrawInfo_1_00198570__as_DbItem_ResetLayout_0_00197DD0__, arg);
    }
}

/* DbMapProc_DrawInfo_1_00198570 */

/* DbMapProc_DrawInfo_1_00198570 */

/* DbMapProc_DrawInfo_1_00198570 */
static inline f32 u2f(u32 x) { return x; }
static inline s32 any(u32 k) {
    u32 i;
    for (i = 0; (s32)i < 10; i++) {
        if (!(MapState_IsVisited_1_001AA440(k * 10 + i) != 0) == 0) return 1;
    }
    return 0;
}

void DbMapProc_DrawInfo_1_00198570(A *o, s32 mode, u32 kind) {
    S s __attribute__((aligned(16)));
    Col_DbMapProc_DrawInfo_1_00198570 col;
    s32 n;
    s32 k;
    f32 f;
    u32 c;
    B *b;

    s = D_001F2FE0;
    n = D_004A1450[D_004A18B0[0]] * 10;
    {
        s8 buf[0x100] = {0};

        if (kind < 300) {
            if (PlayerData_Get_2_001C9BA0()->xE == 0 && mode == 200) return;
            s.x = o->x30;
            s.y = o->x34;
            if (kind == 0) {
                o->x2C.c.r = 0x40;
                o->x2C.c.g = 0x40;
                o->x2C.c.b = 0x40;
            }
            Ui_DrawSprite_2_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, kind);
            return;
        }
        if (kind == 500) {
            b = (B *)(MenuLayout_GetSub_1_00189020__as_DbMapProc_DrawInfo_1_00198570(0)->x54 + 0x390);
            col.w = 0x30808080;
            s.x = o->x38;
            s.y = o->x3C;
            Ui_DrawSprite_2_00181680(b->x4, &b->x10, &b->x20, &col, &s, kind);
        }
        if (kind == 501) {
            col.w = 0x80808080;
            sprintf(buf, D_001FD398, D_002021A4);
            Text_Draw_2_001875C0__as_DbMapProc_DrawInfo_1_00198570(o->x38, buf, o->x3C, 0.9f, 2, col.w);
        }
        if (mode == 100) {
            if (kind == 400) {
                col.w = 0x80808080;
                strcpy(buf, D_001FD3A0);
                Text_Draw_2_001875C0__as_DbMapProc_DrawInfo_1_00198570(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
            if (kind == 401) {
                col.w = 0x80808080;
                if (n < 0) {
                    strcpy(D_004A1770, D_001FD3B0);
                    strcpy(buf, D_001FD3B0);
                } else {
                    k = n / 10;
                    if (any(n / 10)) {
                        c = MapState_GetBestKillRate_0_001AA090(k * 10);
                        f = 100.0f * (u2f(c) / (f32)DbMap_GetKillRate_0_001959E0(k));
                        if (DbMap_GetKillRate_0_001959E0(k) == 0) {
                            sprintf(buf, D_001FD3C0, (s32)f);
                        } else {
                            sprintf(buf, D_001FD3C8, (s32)f);
                        }
                    } else {
                        strcpy(buf, D_001FD3B0);
                    }
                }
                Text_Draw_2_001875C0__as_DbMapProc_DrawInfo_1_00198570(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
        }
        if (PlayerData_Get_2_001C9BA0()->xE != 0 && mode == 200) {
            if (kind == 400) {
                col.w = 0x80808080;
                strcpy(buf, D_001FD3D0);
                Text_Draw_2_001875C0__as_DbMapProc_DrawInfo_1_00198570(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
            if (kind == 401) {
                col.w = 0x80808080;
                if (n < 0) {
                    strcpy(D_004A1770, D_001FD3B0);
                    strcpy(buf, D_001FD3B0);
                } else {
                    k = n / 10;
                    if (any(n / 10)) {
                        c = MapState_GetKillCount_0_001A9FF0(k * 10);
                        f = 100.0f * (u2f(c) / (f32)DbMap_GetKillRate_0_001959E0(k));
                        if (DbMap_GetKillRate_0_001959E0(k) == 0) {
                            sprintf(buf, D_001FD3E0, (s32)f);
                        } else {
                            sprintf(buf, D_001FD3E8, (s32)f);
                        }
                    } else {
                        strcpy(buf, D_001FD3B0);
                    }
                }
                Text_Draw_2_001875C0__as_DbMapProc_DrawInfo_1_00198570(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
        }
        if (kind == 10001) {
            D_004A189C[0] = o->x38;
            D_004A18A0[0] = o->x3C;
            D_004A1884[0] = 1.25f;
            D_004A18AC[0] = 0x80FFFFFF;
            D_004A1888[0] = 1.25f;
            Ui_DrawWindow_0_00183650(D_004A1870);
        }
    }
}

/* DbMap_UpdateWrap_0_00198BD0 */
void DbMap_UpdateWrap_0_00198BD0(s32 arg0) {
    DbMap_Update_0_00198BE0((void *) arg0);
}

/* DbMap_Update_0_00198BE0 */

void DbMap_Update_0_00198BE0(M *m) {
    s32 sel;
    s32 old;
    switch (m->x0) {
    case 0x19:
        D_004A18B0[0] = 0;
        DbMap_BuildList_1_00199000();
        DbMap_ResetLayout_0_00198D80();
        break;
    case 0x16:
        old = D_004A18B0[0];
        sel = old;
        if (m->x4 & 0x4000) {
            Ui_SetOffset_0_001803D0(-2, -2);
            Snd_PlaySe_3_00131600(0x69, m->xE);
            m->x8 = 0x18;
            m->x4 = 0;
            m->x0 = 0x1A;
            UiAnim_SetVisible_1_0017F7C0(0, 0, 1);
            return;
        }
        if (m->x4 & 0x10) {
            sel = old - 1;
        } else if (m->x4 & 0x40) {
            sel = old + 1;
        }
        if (D_002021A8 != 0) {
            sel = (sel + D_002021A8) % D_002021A8;
        }
        if (UiAnim_SetTarget_1_0017F470(old, 0, 0)) {
            if (D_004A18B0[0] != sel) {
                Snd_PlaySe_3_00131600(0x66, m->xE);
            }
            D_004A18B0[0] = sel;
        } else {
            D_004A18B8[0] = 10.0f;
        }
        break;
    }
    Ui_LoadAreaImage_3_00183970(D_004A1450[D_004A18B0[0]] * 10);
}

/* DbMap_ResetLayout_0_00198D80 */

void DbMap_ResetLayout_0_00198D80(void) {
    Q2 q;
    Arg a;
    P_DbMap_ResetLayout_0_00198D80 *p;
    u32 i;
    u32 j;
    s32 cnt;
    s32 found;

    Ui_SetOffset_0_001803D0(D_002022B8 / 10, -2);
    p = DbMap_GetCount_1_001958E0();
    if (p != 0) {
        cnt = 0;
        for (i = 1; i < p->n + 1; i++) {
            found = 0;
            for (j = 0; j < 10; j++) {
                if (MapState_IsVisited_1_001AA440(j + i * 10)) {
                    found = 1;
                }
            }
            if (found) {
                cnt++;
            }
        }
        D_002021A4 = (u32)(cnt * 100) / p->n;
        q = D_001F2FC0;
        a.p = (s32)D_004A1450;
        a.fn = DbMap_GetListName_1_00198F30;
        a.f = -3.0f;
        a.cb = DbMapProc_Pos_0_00199110;
        a.a = 0;
        a.b = 0;
        a.n = D_002021A8;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 1);
        UiAnim_SetTarget_1_0017F470(D_004A18B0[0], 0, 1);
    }
}
#undef DbMapProc_DrawInfo_1_00198570
#undef DbMap_Update_0_00198BE0

/* DbMap_GetListName_1_00198F30 */

s8 *DbMap_GetListName_1_00198F30(s32 a) {
    s32 i;
    s32 found;
    s32 k;
    if (a < 0) {
        return D_001FD3B0;
    }
    found = 0;
    for (i = 0, k = a * 10; i < 10; i++, k++) {
        if (MapState_IsVisited_1_001AA440(k)) {
            found = 1;
        }
    }
    if (found) {
        sprintf(D_004A1770, D_001FD3F0, DbMap_GetLocationName_1_00195AA0(a));
        return D_004A1770;
    }
    return D_001FD3B0;
}

/* DbMap_BuildList_1_00199000 */

void DbMap_BuildList_1_00199000(void) {
    s32 *p;
    u32 i;
    u32 j;
    s32 found;
    s32 base;

    p = DbMap_GetCount_1_001958E0__as_DbMap_BuildList_1_00199000();
    if (p != 0) {
        D_002021A8 = 0;
        for (i = 1; i < (u32)(p[1] + 1); i++) {
            found = 0;
            for (j = 0; j < 10; j++) {
                if (MapState_IsVisited_1_001AA440(i * 10 + j) != 0) {
                    found = 1;
                }
            }
            if (found != 0) {
                D_004A1450[D_002021A8] = i;
            } else {
                D_004A1450[D_002021A8] = -1;
            }
            D_002021A8++;
        }
    }
}
#undef DbMapProc_Pos_0_00199110

/* DbMapProc_Pos_0_00199110 */
void DbMapProc_Pos_0_00199110(s32 arg0, void *arg1, void *arg2) {
    void *sp4C;

    UiAnim_Get_1_0017F840(0, &sp4C);
    M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg2, f32 *, 8) - (f32) arg0);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202190 */
u32 D_00202190;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/load_menu_bss_004A1120.c): D_004A1884 */
f32 D_004A1884[0x6] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_001F2F00[];
/* data group (src/game/data/databook_item_reset_data.c): D_001F2F40__grp: D_001F2F40@0x0 */
s32 D_001F2F40__grp[0x8] __attribute__((aligned(16))) = { 0, 5, 0, (s32)D_001F2F00, 7, -0x3fc00000, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_001F2F80[];
/* data group (src/game/data/databook_item_reset_data.c): D_001F2FC0__grp: D_001F2FC0@0x0 */
s32 D_001F2FC0__grp[0x8] __attribute__((aligned(16))) = { 0, 5, 0, (s32)D_001F2F80, 7, -0x3fc00000, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/databook_item_reset_data.c): D_001F2FE0__grp: D_001F2FE0@0x0 */
f32 D_001F2FE0__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/databook_item_reset_data.c): D_001F2F00, D_001F2F80 */
u8 D_001F2F00[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
u8 D_001F2F80[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
