#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/item.h"
#include "game/player.h"
#include "game/ui.h"
#include "game/math.h"
typedef struct { u16 v[8]; } H;
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 ev; s32 btn; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } In;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x30]; u8 x3C; u8 pad3D[0x53]; } E;
typedef struct { u8 pad[5]; u8 kind; } K;
typedef struct { u8 x0; } K2;
typedef struct { u64 a:6; u64 b:2; } BF;
#ifdef NONMATCHING
extern u8 D_00495B60[];
extern u8 D_00496B60[];
#endif
#ifndef NONMATCHING
extern f32 D_00201D8C;
#else
/* data twins (src/game/data/sdata.c): D_00201D8C */
static f32 D_00201D8C = -2.99f;
#endif
extern Flags8 D_004A4340[];
extern s32 D_004A4330[];
extern s32 D_004A4334[];
#ifndef NONMATCHING
extern s32 *D_00201D7C;
#else
/* data twins (src/game/data/sdata.c): D_00201D7C */
static s32 *D_00201D7C = (s32 *)D_00495B60;
#endif
#ifndef NONMATCHING
extern s32 D_00202224;
#else
/* data twins (src/game/data/sbss.c): D_00202224 */
static s32 D_00202224;
#endif
#ifndef NONMATCHING
extern s32 D_00202238;
#else
/* data twins (src/game/data/sbss.c): D_00202238 */
static s32 D_00202238;
#endif
#ifndef NONMATCHING
extern f32 D_00201D84;
#else
/* data twins (src/game/data/sdata.c): D_00201D84 */
static f32 D_00201D84 = -2.99f;
#endif
#ifndef NONMATCHING
extern f32 D_00201D88;
#else
/* data twins (src/game/data/sdata.c): D_00201D88 */
static f32 D_00201D88 = -2.99f;
#endif
#ifndef NONMATCHING
extern f32 D_00202228;
#else
/* data twins (src/game/data/sbss.c): D_00202228 */
static f32 D_00202228;
#endif
#ifndef NONMATCHING
extern f32 D_0020222C;
#else
/* data twins (src/game/data/sbss.c): D_0020222C */
static f32 D_0020222C;
#endif
extern f32 D_004A3328[];
extern Q2 D_001F3260;
#ifndef NONMATCHING
extern s32 D_00202220;
#else
/* data twins (src/game/data/sbss.c): D_00202220 */
static s32 D_00202220;
#endif
#ifndef NONMATCHING
extern s32 D_00202230;
#else
/* data twins (src/game/data/sbss.c): D_00202230 */
static s32 D_00202230;
#endif
#ifndef NONMATCHING
extern s32 D_00202234;
#else
/* data twins (src/game/data/sbss.c): D_00202234 */
static s32 D_00202234;
#endif
extern s16 D_004A3310[];
extern Flags8 D_004A332C[];
#ifndef NONMATCHING
extern s32 D_004A3330[];
#else
/* data twins (src/game/data/shop_bss_004A3310.c): D_004A3330 */
static s32 D_004A3330[0x400];
#endif
#ifndef NONMATCHING
extern f32 D_004A433C[];
#else
/* data twins (src/game/data/shop_bss_004A3310.c): D_004A433C */
static f32 D_004A433C[0x1];
#endif
#ifndef NONMATCHING
extern f32 *D_00201D80;
#else
/* data twins (src/game/data/sdata.c): D_00201D80 */
static f32 *D_00201D80 = (f32 *)D_00496B60;
#endif
void Shop_Draw_0_001A1460(u8 *a);
void Shop_DrawStatus_0_001A1550(u8 *a0, f32 f);
void Shop_Open_1_001A1B40(s32 a0);
void Shop_Update_0_001A1C80(In *in);
void Shop_BuildList_0_001A2C00(s32 a0, s32 a1);
void Shop_LoadIcons_0_001A2F20(u32 a0);
void ShopProc_Pos_0_001A2FF0(s32 i, s8 *o, s8 *p);
void Notify_DrawBackground_0_0019EF60(u8 *);
H* PlayerData_Get_2_001C9BA0(void);
s8* Player_GetBodyState_1_001C9B60(void);
void Menu_DrawRingB_0_00184960(void *, f32);
void Equip_CalcStatBars_0_0019A370(H *, H *, H *, H *, s32);
void Player_CalcStats_0_0019A500(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);
void Menu_DrawStatRing_0_00186440(f32, H *, H *, H *, H *);
void Menu_DrawRingD_0_00185510(f32, H *);
void Menu_DrawRingE_0_00185B40(f32, s8 *);
s32 Equip_GetSlotItem_1_001CCD90(s32);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void Menu_DrawItemFrame_0_001DF470(f32, s32);
void Ui_LoadItemImage_3_00183DC0(s32);
void Shop_Heal_0_001A1000(s32);
void Shop_Repair_0_001A0DB0(s32);
void Shop_SellQuantity_0_001A0B00(s32);
void Shop_BuyQuantity_0_001A0850(s32);
void Shop_Confirm_0_001A06B0(s32);
void Shop_SelectItem_0_001A03C0(s32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Ui_SetOffset_0_001803D0(s16, s16);
void Ui_SetOffsetB_0_001803C0(s32 *, s32);
void Player_RecalcStats_1_001CEDC0(s32);
K* Inventory_GetSlot_1_001A97D0(s16);
E* Item_GetTable_1_001AFC90(void);
K2* Inventory_GetEntry_1_001CC3F0(s16);
s32 ItemSort_GetEntry_0_00195B80(s32, s32 *);
void Snd_PlaySe_3_00131600(s32, s32);
u8 MenuStack_Pop_1_00189EA0(void);
void DbItem_Find_1_0019D510(void);
void memset(void *, s32, s32);
s32 ItemSort_GetCount_0_00195BE0(s32);
void Ui_LoadItemImageSmall_3_001833E0(s16, s32);
void UiAnim_Get_1_0017F840(s32, void **);

/* Shop_Draw_0_001A1460 */
void Shop_Draw_0_001A1460(u8 *a) {
    Menu_SetFlags_0_0018A310(-1);
    if (a[8] == 0x22) {
        D_00201D8C = Approachf_3_00187770(D_00201D8C, -0.02f, 3.5f);
    } else {
        D_00201D8C = Approachf_3_00187770(D_00201D8C, -2.99f, 3.5f);
    }
    if (!D_004A4340[0].f.b2) {
        UiAnim_UpdateAll_1_0017F5C0();
    }
    if (!(D_00201D8C <= -2.99f)) {
        Shop_DrawStatus_0_001A1550(a, D_00201D8C);
    }
    Ui_BeginSprites_1_00181420();
    Menu_DrawBackground_0_00187B20(0);
    if (D_004A331C[0]) {
        Notify_DrawBackground_0_0019EF60(a);
    }
}

/* Shop_DrawStatus_0_001A1550 */
static inline s32 cls_Shop_DrawStatus_0_001A1550(s32 x) {
    s32 r;
    switch (x) {
    case 0: r = 0; break;
    case 1: r = 0; break;
    case 2: r = 2; break;
    case 3: r = 2; break;
    case 4: r = 1; break;
    case 5: r = 2; break;
    case 6: r = 2; break;
    default: r = -1; break;
    }
    return r;
}
static inline s32 mp(s32 x) { if (x == 1) return 1; if (x == 9) return 100; return x; }

void Shop_DrawStatus_0_001A1550(u8 *a0, f32 f) {
    s32 rFC;
    s32 rF8;
    s32 rF4;
    s32 rF0;
    s32 rEC;
    H d0;
    H c0;
    H b0;
    H a0_;
    H m90;
    H m80;
    s32 mode;
    H *s2;
    H *s1;
    s8 *s5;
    s32 id;
    s32 i;
    s32 x;
    f32 hi;
    f32 lo;

    mode = D_004A3320[0];
    s2 = PlayerData_Get_2_001C9BA0();
    s1 = PlayerData_Get_2_001C9BA0();
    s5 = Player_GetBodyState_1_001C9B60();
    id = D_00201D7C[D_004A4330[0]];
    if (D_00202224 <= 0) id = -1;
    if (a0[8] == 0x22) {
        if (D_004A4340[0].f.b2) {
            hi = 3.5f;
            D_00201D84 = Approachf_3_00187770(D_00201D84, -0.02f, hi);
            lo = -2.99f;
            D_00201D88 = Approachf_3_00187770(D_00201D88, lo, 3.5f);
        } else {
            hi = 3.5f;
            lo = -2.99f;
            D_00201D84 = Approachf_3_00187770(D_00201D84, lo, hi);
            D_00201D88 = Approachf_3_00187770(D_00201D88, -0.02f, 3.5f);
        }
    } else {
        hi = 3.5f;
        lo = -2.99f;
        D_00201D84 = Approachf_3_00187770(D_00201D84, lo, hi);
        D_00201D88 = Approachf_3_00187770(D_00201D88, -2.99f, 3.5f);
    }
    ShopMenu_DrawRingA_0_001DD7F0(id, mode, D_00201D84);
    Menu_DrawItemDesc_1_001DF360(D_004A4340[0].f.b2, id);
    ShopMenu_DrawRingC_0_001DEB00(D_00202238, mode, -D_00201D88 / 2.0f);
    Menu_DrawRingB_0_00184960((s8 *)s2 + 0x80, -D_00201D88 / 2.0f);
    ShopMenu_DrawRingB_0_001DE0D0(id, D_00201D88);
    if (D_004A4340[0].f.b3) {
        Equip_CalcStatBars_0_0019A370(&m90, &m80, &b0, &a0_, id);
        Menu_DrawStatRing_0_00186440(f, &m90, &m80, &b0, &a0_);
        Menu_SetOffset_0_00185B30(0, 0);
    } else {
        if (Player_Exists_3_001C9BF0()) {
            Player_CalcStats_0_0019A500(&d0, &c0, &rFC, &rF8, &rF4, -1, -1, 0);
        }
        if (D_00202224 <= 0) {
            Player_CalcStats_0_0019A500(&b0, &a0_, &rFC, &rF0, &rEC, -1, -1, 0);
        } else {
            Player_CalcStats_0_0019A500(&b0, &a0_, &rFC, &rF0, &rEC, D_00202238, id, cls_Shop_DrawStatus_0_001A1550(mode) != 2);
        }
        for (i = 0; i < 8; i++) {
            b0.v[7 - i] -= d0.v[7 - i];
            a0_.v[7 - i] -= c0.v[7 - i];
        }
        if (id == (s16)Equip_GetSlotItem_1_001CCD90(D_00202238)) {
            Menu_SetOffset_0_00185B30(0, 0);
            Menu_DrawStatRing_0_00186440(f, &d0, &c0, NULL, NULL);
        } else {
            Menu_SetOffset_0_00185B30(rF0 - rF8, rEC - rF4);
            Menu_DrawStatRing_0_00186440(f, &d0, &c0, &b0, &a0_);
        }
    }
    Menu_DrawRingD_0_00185510(f, s1);
    Menu_DrawRingE_0_00185B40(f, s5);
    if (D_004A4334[0] == 1) D_0020222C = 10.0f;
    if (D_0020222C > 0.0f) {
        D_0020222C -= 1.0f;
        D_00202228 = Approachf_3_00187770(D_00202228, lo, hi);
    } else {
        D_00202228 = Approachf_3_00187770(D_00202228, -0.02f, hi);
    }
    Menu_DrawFrame_0_00185390(f + D_00202228, 1, D_00202224, D_004A4330[0]);
    Menu_DrawItemFrame_0_001DF470(f + D_00202228, mp(D_00202238));
}

/* Shop_Open_1_001A1B40 */
#define Shop_Update_0_001A1C80 Shop_Update_0_001A1C80__as_Shop_Open_1_001A1B40
void Shop_Update_0_001A1C80__as_Shop_Open_1_001A1B40(s32);

void Shop_Open_1_001A1B40(s32 a0) {
    s32 id;
    s32 x;

    x = D_004A3320[0];
    id = D_00201D7C[D_004A4330[0]];
    if (D_00202224 <= 0) id = -1;
    D_004A4334[0] = 0;
    Shop_LoadIcons_0_001A2F20(x);
    Ui_LoadItemImage_3_00183DC0(id);
    if (D_004A3328[0] > 0.0f) {
        D_004A3328[0] -= 1.0f;
        return;
    }
    switch (D_004A331C[0]) {
    case 0: Shop_Update_0_001A1C80(a0); break;
    case 1: Shop_Heal_0_001A1000(a0); break;
    case 2: Shop_Repair_0_001A0DB0(a0); break;
    case 3: Shop_SellQuantity_0_001A0B00(a0); break;
    case 4: Shop_BuyQuantity_0_001A0850(a0); break;
    case 5: Shop_Confirm_0_001A06B0(a0); break;
    case 6: Shop_SelectItem_0_001A03C0(a0); break;
    }
}
#undef Shop_Update_0_001A1C80

/* Shop_Update_0_001A1C80 */
#define D_004A4340 D_004A4340__as_Shop_Update_0_001A1C80
extern Flags8_6x2 D_004A4340__as_Shop_Update_0_001A1C80[];

static inline s32 cls_Shop_Update_0_001A1C80(s32 x) {
    s32 r;
    switch (x) {
    case 0: r = 0; break;
    case 1: r = 0; break;
    case 2: r = 2; break;
    case 3: r = 2; break;
    case 4: r = 1; break;
    case 5: r = 2; break;
    case 6: r = 2; break;
    default: r = -1; break;
    }
    return r;
}
static inline s32 nx(s32 x) {
    s32 r;
    switch (x) {
    case 1: r = ItemSort_GetEntry_0_00195B80(1, &D_00202220); break;
    case 2: r = ItemSort_GetEntry_0_00195B80(2, &D_00202220); break;
    case 3: r = ItemSort_GetEntry_0_00195B80(3, &D_00202220); break;
    case 4: r = ItemSort_GetEntry_0_00195B80(4, &D_00202220); break;
    case 5: r = ItemSort_GetEntry_0_00195B80(5, &D_00202220); break;
    case 6: r = ItemSort_GetEntry_0_00195B80(6, &D_00202220); break;
    case 0:
    default: r = -1; break;
    }
    return r;
}
static inline void setupn(s32 n) {
    Q2 q;
    Arg a;
    q = D_001F3260;
    a.fn = DbItem_Find_1_0019D510;
    a.n = n;
    a.f = -3.0f;
    a.cb = ShopProc_Pos_0_001A2FF0;
    a.a = 0;
    a.b = 0;
    a.p = D_00201D7C;
    UiAnim_SetColor_0_0017F890(D_00202238, &q, &a);
    UiAnim_SetVisible_1_0017F7C0(D_00202238, 1, 1);
    D_00202230 = 2;
    UiAnim_SetTarget_1_0017F470(D_004A4330[0], D_00202238, 1);
}
static inline void setup(void) {
    Q2 q;
    Arg a;
    q = D_001F3260;
    a.fn = DbItem_Find_1_0019D510;
    a.f = -3.0f;
    a.cb = ShopProc_Pos_0_001A2FF0;
    a.a = 0;
    a.b = 0;
    a.p = D_00201D7C;
    a.n = D_00202224;
    UiAnim_SetColor_0_0017F890(D_00202238, &q, &a);
    UiAnim_SetVisible_1_0017F7C0(D_00202238, 1, 1);
    D_00202230 = 2;
    UiAnim_SetTarget_1_0017F470(D_004A4330[0], D_00202238, 1);
}

void Shop_Update_0_001A1C80(In *in) {
    s32 mode;
    u8 k;
    s32 sel;
    s32 i;
    s32 btn;
    s32 *p;
    s32 id;
    E *e;
    s32 ok;
    u8 b;
    s32 t;

    mode = D_004A3320[0];
    t = D_00202238;
    if (mode == 1) {
        Ui_SetOffset_0_001803D0(-2, -2);
    } else {
        Ui_SetOffset_0_001803D0((s16)Equip_GetSlotItem_1_001CCD90(t), -2);
    }
    if (D_004A332C[0].f.b2) {
        Inventory_Sort_0_0019FD00();
        Shop_BuildList_0_001A2C00(D_00202238, cls_Shop_Update_0_001A1C80(mode));
        D_004A4340[0].f.b5 = D_00202234 != D_00202224;
        if (D_004A4340[0].f.b5) {
            setupn(D_00202224);
            D_004A4340[0].f.b5 = 0;
        }
        Inventory_Recount_0_001CCE30();
        Player_RecalcStats_1_001CEDC0(3);
        Player_RefreshEquipModel_0_001CEA50(1);
        D_004A332C[0].f.b2 = 0;
    }
    if (D_004A332C[0].f.b3) {
        Shop_BuildList_0_001A2C00(D_00202238, cls_Shop_Update_0_001A1C80(mode));
        D_004A332C[0].f.b3 = 0;
        D_004A433C[0] = 10.0f;
    }
    if (!(D_004A4330[0] < D_00202224)) D_004A4330[0] = D_00202224 - 1;
    sel = D_004A4330[0];
    id = D_00201D7C[sel];
    if (D_00202224 <= 0) {
        sel = 0;
        D_004A4330[0] = 0;
        id = -1;
    }
    if (in->ev == 0x19) {
        D_004A4330[0] = 0;
        D_004A4340[0].f.b3 = 0;
        D_004A4340[0].f.b2 = 0;
        Menu_ResetDescScroll_0_001DF460();
        Equip_SelectBest_0_0019A0D0(cls_Shop_Update_0_001A1C80(mode) != 2);
        if (mode == 1) {
            p = D_004A3330;
            for (i = 0; i < 0x400; i++, p++) {
                *p = 0;
                if (Inventory_GetSlot_1_001A97D0(i)->kind == 3) {
                    Item_GetTable_1_001AFC90();
                    *p = 1;
                }
            }
            D_004A4340[0].f.b6 = 1;
            Ui_SetOffsetB_0_001803C0(D_004A3330, 0);
        } else {
            Ui_SetOffsetB_0_001803C0(NULL, 0);
        }
        D_00202220 = 0;
        D_00202238 = 6;
        Shop_BuildList_0_001A2C00(6, cls_Shop_Update_0_001A1C80(mode));
        setup();
    }
    if (in->ev != 0x16) return;
    btn = in->btn;
    if (btn & 0x10) {
        sel--;
        if (sel < 0) {
            sel = D_00202224 - 1;
            if (sel < 0) sel = 0;
        }
        in->btn = 0;
    } else if (btn & 0x40) {
        sel++;
        if (!(sel < D_00202224)) sel = 0;
        in->btn = 0;
    } else if (btn & 0x480) {
        UiAnim_SetVisible_1_0017F7C0(D_00202238, 0, 1);
        Menu_ResetDescScroll_0_001DF460();
        D_004A4330[0] = 0;
        D_004A4334[0] = 1;
        D_00202230 = 2;
        D_00202220--;
        D_00202238 = nx(D_004A3320[0]);
        Shop_BuildList_0_001A2C00(D_00202238, cls_Shop_Update_0_001A1C80(mode));
        setup();
        Snd_PlaySe_3_00131600(0x66, in->xE);
        in->btn = 0;
        return;
    } else if (btn & 0x820) {
        UiAnim_SetVisible_1_0017F7C0(D_00202238, 0, 1);
        Menu_ResetDescScroll_0_001DF460();
        D_004A4330[0] = 0;
        D_004A4334[0] = 1;
        D_00202230 = 2;
        D_00202220++;
        D_00202238 = nx(D_004A3320[0]);
        Shop_BuildList_0_001A2C00(D_00202238, cls_Shop_Update_0_001A1C80(mode));
        setup();
        Snd_PlaySe_3_00131600(0x66, in->xE);
        in->btn = 0;
        return;
    } else if (btn & 0x1000) {
        UiAnim_SetVisible_1_0017F7C0(D_00202238, D_004A4340[0].f.b2, 1);
        if (D_004A4340[0].f.b2) setup();
        D_00202230 = 2;
        D_004A4340[0].f.b2 = !D_004A4340[0].f.b2;
        D_004A433C[0] = 15.0f;
        in->xC = D_004A4340[0].f.b2;
        Snd_PlaySe_3_00131600(0x67, in->xE);
        in->btn = 0;
    } else if (btn & 0x8000) {
        D_004A4340[0].f.b3 = !D_004A4340[0].f.b3;
        Snd_PlaySe_3_00131600(0x67, in->xE);
        in->btn = 0;
    } else if (btn & 0x2000) {
        if (D_00202224 > 0) {
            ok = 0;
            if (mode == 6) {
                e = &Item_GetTable_1_001AFC90()[id];
                if (e->xA == 1) {
                    k = e->x3C;
                    if (k == Inventory_GetEntry_1_001CC3F0(id)->x0) ok = 1;
                } else if (e->xA == 2) {
                    k = e->x3C;
                    if (k == Inventory_GetEntry_1_001CC3F0(id)->x0) ok = 1;
                }
            }
            if (ok) {
                Snd_PlaySe_3_00131600(0x68, in->xE);
            } else {
                D_004A3310[0] = id;
                D_004A332C[0].f.b4 = 1;
                D_004A331C[0] = mode;
                D_004A433C[0] = 10.0f;
                D_004A3312[0] = 1;
                D_00202234 = D_00202224;
                Snd_PlaySe_3_00131600(0x67, in->xE);
            }
            in->btn = 0;
        }
    } else if (btn & 0x4000) {
        b = D_004A4340[0].f.b2;
        if (b) {
            UiAnim_SetVisible_1_0017F7C0(D_00202238, b, 1);
            if (D_004A4340[0].f.b2) setup();
            D_00202230 = 2;
            D_004A4340[0].f.b2 = !D_004A4340[0].f.b2;
            D_004A433C[0] = 15.0f;
            in->xC = D_004A4340[0].f.b2;
            Snd_PlaySe_3_00131600(0x67, in->xE);
            in->btn = 0;
        } else {
            in->x8 = MenuStack_Pop_1_00189EA0();
            UiAnim_SetVisible_1_0017F7C0(D_00202238, 0, 1);
            if (D_00202238 > 4) {
                in->x9 = D_00202238 + 1;
            } else {
                in->x9 = D_00202238;
            }
            Ui_SetOffsetB_0_001803C0(NULL, 0);
            Ui_SetOffsetA_0_001803B0(0, 0);
            in->btn = 0;
            in->ev = 0x1A;
            Snd_PlaySe_3_00131600(0x69, in->xE);
            in->btn = 0;
        }
    }
    if (UiAnim_SetTarget_1_0017F470(D_004A4330[0], D_00202238, 0) != 0 || D_004A4340[0].f.b2) {
        if (D_004A4330[0] != sel) Snd_PlaySe_3_00131600(0x66, in->xE);
        D_004A4330[0] = sel;
        D_00202230 = 0;
        D_004A4340[0].f.b4 = 0;
    }
}
#undef D_004A4340

/* Shop_BuildList_0_001A2C00 */
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Shop_BuildList_0_001A2C00
u8 *Inventory_GetSlot_1_001A97D0__as_Shop_BuildList_0_001A2C00(s16);

void Shop_BuildList_0_001A2C00(s32 a0, s32 a1) {
    u8 *e;
    s32 i;
    u8 *base;
    u8 *c;

    base = Item_GetTable_1_001AFC90();
    D_00202224 = 0;
    memset(D_00201D7C, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        c = Inventory_GetEntry_1_001CC3F0(ItemSort_GetCount_0_00195BE0(i));
        switch (a1) {
        case 0:
            if (Inventory_GetSlot_1_001A97D0(ItemSort_GetCount_0_00195BE0(i))[5] == 0) {
                continue;
            }
            if ((s32)Inventory_GetSlot_1_001A97D0(ItemSort_GetCount_0_00195BE0(i))[2] <= 0) {
                continue;
            }
            break;
        case 1:
            if ((s32)Inventory_GetSlot_1_001A97D0(ItemSort_GetCount_0_00195BE0(i))[4] <= 0) {
                continue;
            }
            break;
        case 2:
            if ((s32)c[2] <= 0) {
                continue;
            }
            break;
        }
        e = base + ItemSort_GetCount_0_00195BE0(i) * 0x90;
        if (a0 >= 2 || *(u16 *)(e + 0xA) == 2) {
            if (a0 < 2 || a0 >= 9 || (*(u16 *)(e + 0xA) == 1 && *(u16 *)(e + 0x20) == a0 - 2)) {
                if (a0 != 9 || *(u16 *)(e + 0xA) == 0) {
                    D_00201D7C[D_00202224] = ItemSort_GetCount_0_00195BE0(i);
                    D_00202224++;
                }
            }
        }
    }
}
#undef Inventory_GetSlot_1_001A97D0

/* Shop_ResetPrices_0_001A2DE0 */
#define D_004A4340 D_004A4340__as_Shop_ResetPrices_0_001A2DE0
extern BF D_004A4340__as_Shop_ResetPrices_0_001A2DE0[];
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Shop_ResetPrices_0_001A2DE0
u8 *Inventory_GetSlot_1_001A97D0__as_Shop_ResetPrices_0_001A2DE0(s16);

void Shop_ResetPrices_0_001A2DE0(void) {
    s32 i;
    if (D_004A4340[0].b) {
        for (i = 0; i < 0x400; i++) {
            D_004A3330[i] = 0;
            if (Inventory_GetSlot_1_001A97D0(i)[5] == 3) {
                Inventory_GetSlot_1_001A97D0(i)[5] = 1;
            }
        }
    }
    D_004A4340[0].b = 0;
}
#undef Inventory_GetSlot_1_001A97D0
#undef D_004A4340

/* Shop_RecalcPrices_0_001A2EA0 */
#define Inventory_GetSlot_1_001A97D0 Inventory_GetSlot_1_001A97D0__as_Shop_RecalcPrices_0_001A2EA0
u8 *Inventory_GetSlot_1_001A97D0__as_Shop_RecalcPrices_0_001A2EA0(s16);
void Shop_RecalcPrices_0_001A2EA0(void) {
    s32 i;
    s32 *p = D_004A3330;
    for (i = 0; i < 0x400; i++, p++) {
        *p = 0;
        if (Inventory_GetSlot_1_001A97D0(i)[5] == 3) {
            Inventory_GetSlot_1_001A97D0(i)[5] = 1;
        }
    }
}
#undef Inventory_GetSlot_1_001A97D0

/* Shop_LoadIcons_0_001A2F20 */
void Shop_LoadIcons_0_001A2F20(u32 a0) {
    s32 n = 10;
    s32 i;

    switch (a0) {
    case 1:
    case 3:
    case 4:
        n = 10;
        break;
    case 2:
    case 5:
        n = 9;
        break;
    case 6:
        n = 7;
        break;
    }
    for (i = 0; i < n; i++) {
        Ui_LoadItemImageSmall_3_001833E0(Equip_GetSlotItem_1_001CCD90(i), i);
    }
    for (; n < 10; n++) {
        Ui_LoadItemImageSmall_3_001833E0(-1, n);
    }
}

/* ShopProc_Pos_0_001A2FF0 */
void ShopProc_Pos_0_001A2FF0(s32 i, s8 *o, s8 *p) {
    void *info;
    UiAnim_Get_1_0017F840(D_00202238, &info);
    switch (D_00202230) {
    case 0:
        *(f32 *)(o + 0x14) = *(f32 *)(p + 8) - (f32)i;
        break;
    case 2:
        if (i >= D_004A4330[0] - 3 && i <= D_004A4330[0] + 3) {
            *(f32 *)(o + 0x14) = D_00201D80[i] = *(f32 *)(p + 8) - (f32)i;
        } else {
            *(f32 *)(o + 0x14) = D_00201D80[i] = -5.0f;
        }
        break;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_00495B60[];
extern u8 D_00496B60[];
/* data twins (src/game/data/shop_bss_004A3310.c): D_004A3320, D_004A4330, D_004A4340 */
s32 D_004A3320[0x1];
s32 D_004A4330[0x3];
Flags8 D_004A4340[0x10 / sizeof(Flags8)];
#endif
