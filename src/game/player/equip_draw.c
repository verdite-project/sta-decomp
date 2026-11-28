#include "common.h"
#include "actor.h"
#include "m2c.h"
#include "game/data.h"
#include "game/item.h"
#include "game/player.h"
#include "game/ui.h"
#include "game/math.h"
typedef union { s32 w; Flags8 f; } FW;
typedef struct { u16 v[8]; } H;
typedef struct { u8 pad[8]; u8 x8; } O;
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[3]; u8 xC; u8 xD; u8 xE; } S;
typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; } P;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x14]; u16 x20; u8 pad22[0x6E]; } E_Equip_BuildList_0_0019A1D0;
typedef struct { u8 pad[0x2C]; u16 a[8]; u8 pad2[0x4A-0x3C]; u16 b[6]; } E_Equip_CalcStatBars_0_0019A370;
typedef struct { s16 v[10]; } Ids;
typedef struct { u8 b[4]; } Col;
typedef struct { u8 pad[0x14]; f32 x14; } A;
typedef struct { u8 pad[8]; f32 x8; } B;
#ifdef NONMATCHING
extern u8 D_00495B60[];
extern u8 D_00496B60[];
#endif
#ifndef NONMATCHING
extern f32 D_00201D5C;
#else
/* data twins (src/game/data/sdata.c): D_00201D5C */
static f32 D_00201D5C = -2.99f;
#endif
#ifndef NONMATCHING
extern FW D_004A28D0[];
#else
/* data twins (src/game/data/item_menu_draw_bss.c): D_004A28D0 */
static FW D_004A28D0[0x10 / sizeof(FW)] __attribute__((aligned(4)));
#endif
extern s32 *D_00201D4C;
#ifndef NONMATCHING
extern f32 D_00201D54;
#else
/* data twins (src/game/data/sdata.c): D_00201D54 */
static f32 D_00201D54 = -2.99f;
#endif
#ifndef NONMATCHING
extern f32 D_00201D58;
#else
/* data twins (src/game/data/sdata.c): D_00201D58 */
static f32 D_00201D58 = -2.99f;
#endif
#ifndef NONMATCHING
extern s32 D_002021B4;
#else
/* data twins (src/game/data/sbss.c): D_002021B4 */
static s32 D_002021B4;
#endif
#ifndef NONMATCHING
extern f32 D_002021B8;
#else
/* data twins (src/game/data/sbss.c): D_002021B8 */
static f32 D_002021B8;
#endif
#ifndef NONMATCHING
extern f32 D_002021BC;
#else
/* data twins (src/game/data/sbss.c): D_002021BC */
static f32 D_002021BC;
#endif
#ifndef NONMATCHING
extern s32 D_004A28C4[];
#else
/* data twins (src/game/data/item_menu_draw_bss.c): D_004A28C4 */
static s32 D_004A28C4[0x1];
#endif
extern Q2 D_001F3040;
#ifndef NONMATCHING
extern s32 D_002021AC;
#else
/* data twins (src/game/data/sbss.c): D_002021AC */
static s32 D_002021AC;
#endif
#ifndef NONMATCHING
extern s32 D_004A28C8[];
#else
/* data twins (src/game/data/item_menu_draw_bss.c): D_004A28C8 */
static s32 D_004A28C8[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_004A28CC[];
#else
/* data twins (src/game/data/item_menu_draw_bss.c): D_004A28CC */
static f32 D_004A28CC[0x1];
#endif
#ifndef NONMATCHING
extern f32 *D_00201D50;
#else
/* data twins (src/game/data/sdata.c): D_00201D50 */
static f32 *D_00201D50 = (f32 *)D_00496B60;
#endif
void Equip_Draw_0_00199190(u8 *arg0);
void Equip_DrawStatus_0_00199260(O *o, f32 f);
void Equip_Open_0_001997A0(s32 *arg0);
void Equip_Update_0_00199AD0(S *a0);
void Equip_BuildList_0_0019A1D0(s32 arg0);
void Equip_CalcStatBars_0_0019A370(u16 *a0, u16 *a1, void *a2, void *a3, s32 t0);
void Player_CalcStats_0_0019A500(s32 a0, s32 a1, u32 *a2, u32 *a3, u32 *t0, s32 t1, s32 t2, s32 t3);
void EquipProc_Pos_0_0019A6A0(s32 i, A *a, B *b);
s8* PlayerData_Get_2_001C9BA0(void);
s8* Player_GetBodyState_1_001C9B60(void);
void Menu_DrawStatRing_0_00186440(f32, H *, H *, H *, H *);
void Menu_DrawRingD_0_00185510(f32, s8 *);
void Menu_DrawRingE_0_00185B40(f32, s8 *);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void Menu_DrawRingB_0_00184960(s8 *, f32);
s16 Equip_GetSlotItem_1_001CCD90(s32);
void Menu_DrawItemFrame_0_001DF470(f32, s32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Ui_LoadItemImage_3_00183DC0(s32 *);
void Ui_LoadItemImageSmall_3_001833E0(s32, s32);
void Player_RecalcStats_1_001CEDC0(s32);
void DbItem_Find_1_0019D510(void);
void Snd_PlaySe_3_00131600(s32, u8);
void Ui_SetOffset_0_001803D0(s32, s32);
s32 ItemSort_GetEntry_0_00195B80(s32, s32 *);
u8* Inventory_GetEntry_1_001CC3F0(s16);
void* Item_GetTable_1_001AFC90(void);
void memset(void *, s32, s32);
s32 ItemSort_GetCount_0_00195BE0(s32);
void Equip_Assign_1_001CCF50(Ids *, s32, s16);
u8* Inventory_GetSlot_1_001A97D0(s16);
void Player_CalcStatsFor_0_001CF480(s32, s32, s32, s32, Ids *, Col *, s32);
u16 Stats_CalcMaxMp_0_001D1110(s32);
u16 Stats_CalcMaxHp_0_001D10B0(s32);
void UiAnim_Get_1_0017F840(s32, s32 *);

/* Equip_Draw_0_00199190 */

void Equip_Draw_0_00199190(u8 *arg0) {
    Menu_SetFlags_0_0018A310(-1);
    if (arg0[8] == 0x16) {
        D_00201D5C = Approachf_3_00187770(D_00201D5C, -0.02f, 3.5f);
    } else {
        D_00201D5C = Approachf_3_00187770(D_00201D5C, -2.99f, 3.5f);
    }
    if (!D_004A28D0[0].f.f.b3) {
        UiAnim_UpdateAll_1_0017F5C0();
    }
    if (!(D_00201D5C <= -2.99f)) {
        Equip_DrawStatus_0_00199260(arg0, D_00201D5C);
    }
}

/* Equip_DrawStatus_0_00199260 */
#define Player_CalcStats_0_0019A500 Player_CalcStats_0_0019A500__as_Equip_DrawStatus_0_00199260
void Player_CalcStats_0_0019A500__as_Equip_DrawStatus_0_00199260(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);

void Equip_DrawStatus_0_00199260(O *o, f32 f) {
    s32 eC;
    s32 e8;
    s32 e4;
    s32 e0;
    s32 dC;
    H c0;
    H b0;
    H a0;
    H x90;
    H x80;
    H x70;
    s8 *s3;
    s8 *s2;
    s8 *s1;
    s32 id;
    s32 i;

    s3 = PlayerData_Get_2_001C9BA0();
    s2 = PlayerData_Get_2_001C9BA0();
    s1 = Player_GetBodyState_1_001C9B60();
    id = D_00201D4C[D_004A28C0[0]];
    if (D_002021B4 <= 0) id = -1;
    if (o->x8 == 0x16) {
        if (D_004A28D0[0].f.f.b3) {
            D_00201D54 = Approachf_3_00187770(D_00201D54, -0.02f, 3.5f);
            D_00201D58 = Approachf_3_00187770(D_00201D58, -2.99f, 3.5f);
        } else {
            D_00201D54 = Approachf_3_00187770(D_00201D54, -2.99f, 3.5f);
            D_00201D58 = Approachf_3_00187770(D_00201D58, -0.02f, 3.5f);
        }
    } else {
        D_00201D54 -= (D_00201D54 - -2.99f) / 3.5f;
        D_00201D58 -= (D_00201D58 - -2.99f) / 3.5f;
    }
    ShopMenu_DrawRingA_0_001DD7F0(id, -1, D_00201D54);
    Menu_DrawItemDesc_1_001DF360(D_004A28D0[0].f.f.b3, id);
    Menu_DrawRingC_0_00184DF0(D_00201D48, -D_00201D58 / 2.0f);
    Menu_DrawRingA_0_00184040(id, D_00201D58);
    Menu_DrawRingB_0_00184960(s3 + 0x80, -D_00201D58 / 2.0f);
    if (D_004A28D0[0].f.f.b2) {
        Equip_CalcStatBars_0_0019A370(&a0, &x90, &x80, &x70, id);
        Menu_DrawStatRing_0_00186440(f, &a0, &x90, &x80, &x70);
        Menu_SetOffset_0_00185B30(0, 0);
    } else {
        if (Player_Exists_3_001C9BF0()) Player_CalcStats_0_0019A500(&c0, &b0, &eC, &e8, &e4, -1, -1, 0);
        if (D_002021B4 <= 0) Player_CalcStats_0_0019A500(&x80, &x70, &eC, &e0, &dC, -1, -1, 0);
        else Player_CalcStats_0_0019A500(&x80, &x70, &eC, &e0, &dC, D_00201D48, id, 0);
        for (i = 0; i < 8; i++) {
            x80.v[7 - i] -= c0.v[7 - i];
            x70.v[7 - i] -= b0.v[7 - i];
        }
        if (id == Equip_GetSlotItem_1_001CCD90(D_00201D48)) {
            Menu_SetOffset_0_00185B30(0, 0);
            Menu_DrawStatRing_0_00186440(f, &c0, &b0, 0, 0);
        } else {
            Menu_SetOffset_0_00185B30(e0 - e8, dC - e4);
            Menu_DrawStatRing_0_00186440(f, &c0, &b0, &x80, &x70);
        }
    }
    Menu_DrawRingD_0_00185510(f, s2);
    Menu_DrawRingE_0_00185B40(f, s1);
    if (D_004A28C4[0] == 1) D_002021BC = 10.0f;
    if (!(D_002021BC <= 0.0f)) {
        D_002021BC -= 1.0f;
        D_002021B8 = Approachf_3_00187770(D_002021B8, -2.99f, 3.5f);
    } else {
        D_002021B8 = Approachf_3_00187770(D_002021B8, -0.02f, 3.5f);
    }
    Menu_DrawFrame_0_00185390(f + D_002021B8, 1, D_002021B4, D_004A28C0[0]);
    Menu_DrawItemFrame_0_001DF470(f + D_002021B8, D_00201D48);
}
#undef Player_CalcStats_0_0019A500

/* Equip_Open_0_001997A0 */
#define D_00201D4C D_00201D4C__as_Equip_Open_0_001997A0
extern s32 **D_00201D4C__as_Equip_Open_0_001997A0;
static inline void setup_Equip_Open_0_001997A0(void) {
    Q2 q;
    Arg a;
    q = D_001F3040;
    a.fn = DbItem_Find_1_0019D510;
    a.f = -3.0f;
    a.cb = EquipProc_Pos_0_0019A6A0;
    a.a = 0;
    a.b = 0;
    a.p = (s32 *)D_00201D4C;
    a.n = D_002021B4;
    UiAnim_SetColor_0_0017F890(D_00201D48, &q, &a);
    UiAnim_SetVisible_1_0017F7C0(D_00201D48, 1, 1);
    D_002021AC = 2;
    UiAnim_SetTarget_1_0017F470(D_004A28C0[0], D_00201D48, 1);
}

void Equip_Open_0_001997A0(s32 *arg0) {
    s32 *p;
    s32 i;

    p = D_00201D4C[D_004A28C0[0]];
    if (D_004A28CC[0] > 0.0f) {
        D_004A28CC[0] -= 1.0f;
        D_004A28D0[0].f.f.b1 = 0;
    } else {
        switch (D_004A28C4[0]) {
        case 1:
            UiAnim_SetVisible_1_0017F7C0(D_00201D48, 0, 1);
            D_004A28C0[0] = 0;
            D_00201D48 = D_004A28C8[0];
            Equip_BuildList_0_0019A1D0(D_00201D48);
            setup_Equip_Open_0_001997A0();
        }
        D_004A28C4[0] = 0;
        D_004A28C8[0] = 0;
        D_004A28D0[0].f.f.b1 = 1;
    }
    Ui_LoadItemImage_3_00183DC0(p);
    for (i = 0; i < 10; i++) {
        Ui_LoadItemImageSmall_3_001833E0(Equip_GetSlotItem_1_001CCD90(i), i);
    }
    switch (*arg0) {
    case 0x19:
        D_004A28C0[0] = 0;
        D_004A28D0[0].w = 0;
        Equip_BuildList_0_0019A1D0(D_00201D48);
        Player_RecalcStats_1_001CEDC0(3);
        for (i = 0; i < 10; i++) {
            Ui_LoadItemImageSmall_3_001833E0(Equip_GetSlotItem_1_001CCD90(i), i);
        }
        setup_Equip_Open_0_001997A0();
        Menu_ResetDescScroll_0_001DF460();
        D_004A28D0[0].f.f.b1 = 1;
        Equip_SelectBest_0_0019A0D0(0);
        break;
    case 0x16:
        if (D_004A28D0[0].f.f.b1) {
            Equip_Update_0_00199AD0(arg0);
        }
        break;
    }
}
#undef D_00201D4C

/* Equip_Update_0_00199AD0 */
static inline void setup_Equip_Update_0_00199AD0(void) {
    Q2 q;
    Arg a;
    q = D_001F3040;
    a.fn = DbItem_Find_1_0019D510;
    a.f = -3.0f;
    a.cb = EquipProc_Pos_0_0019A6A0;
    a.a = 0;
    a.b = 0;
    a.p = (s32 *)D_00201D4C;
    a.n = D_002021B4;
    UiAnim_SetColor_0_0017F890(D_00201D48, &q, &a);
    UiAnim_SetVisible_1_0017F7C0(D_00201D48, 1, 1);
    D_002021AC = 2;
    UiAnim_SetTarget_1_0017F470(D_004A28C0[0], D_00201D48, 1);
}
static inline void toggle(S *a0, s32 v) {
    UiAnim_SetVisible_1_0017F7C0(D_00201D48, v, 1);
    if (D_004A28D0[0].f.f.b3) {
        Q2 q;
        Arg a;
        q = D_001F3040;
        a.fn = DbItem_Find_1_0019D510;
        a.f = -3.0f;
        a.cb = EquipProc_Pos_0_0019A6A0;
        a.a = 0;
        a.b = 0;
        a.p = (s32 *)D_00201D4C;
        a.n = D_002021B4;
        UiAnim_SetColor_0_0017F890(D_00201D48, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(D_00201D48, 1, 1);
        D_002021AC = 2;
        UiAnim_SetTarget_1_0017F470(D_004A28C0[0], D_00201D48, 1);
    }
    D_004A28D0[0].f.f.b3 = !D_004A28D0[0].f.f.b3;
    a0->xC = D_004A28D0[0].f.f.b3;
    D_002021AC = 2;
    D_004A28CC[0] = 15.0f;
    Snd_PlaySe_3_00131600(0x67, a0->xE);
}

void Equip_Update_0_00199AD0(S *a0) {
    s32 cur;
    s32 id;
    s32 flags;
    u8 t;

    cur = D_004A28C0[0];
    id = (s32)D_00201D4C[cur];
    Ui_SetOffset_0_001803D0(Equip_GetSlotItem_1_001CCD90(D_00201D48), -2);
    flags = a0->x4;
    if (flags & 0x10) {
        cur--;
        if (cur < 0) {
            cur = D_002021B4 - 1;
            if (cur < 0) cur = 0;
        }
        a0->x4 = 0;
    } else if (flags & 0x40) {
        cur++;
        if (!(cur < D_002021B4)) cur = 0;
        a0->x4 = 0;
    } else if (flags & 0x480) {
        UiAnim_SetVisible_1_0017F7C0(D_00201D48, 0, 1);
        D_002021B0--;
        D_004A28C4[0] = 1;
        D_004A28C8[0] = ItemSort_GetEntry_0_00195B80(0, &D_002021B0);
        D_002021AC = 2;
        Snd_PlaySe_3_00131600(0x66, a0->xE);
        Menu_ResetDescScroll_0_001DF460();
        a0->x4 = 0;
        return;
    } else if (flags & 0x820) {
        UiAnim_SetVisible_1_0017F7C0(D_00201D48, 0, 1);
        D_002021B0++;
        D_004A28C4[0] = 1;
        D_004A28C8[0] = ItemSort_GetEntry_0_00195B80(0, &D_002021B0);
        D_002021AC = 2;
        Snd_PlaySe_3_00131600(0x66, a0->xE);
        Menu_ResetDescScroll_0_001DF460();
        a0->x4 = 0;
        return;
    } else if (flags & 0x2000) {
        if (id > 0 && D_002021B4 > 0) {
            if (!Item_GetCategory_0_001AFBD0(id)) {
                Equip_SetSlot_0_001CCF00(D_00201D48, (s16)id);
                Player_RefreshEquipModel_0_001CEA50(1);
                Snd_PlaySe_3_00131600(0x67, a0->xE);
            } else if (*Inventory_GetEntry_1_001CC3F0(id) > 0) {
                Equip_SetSlot_0_001CCF00(D_00201D48, (s16)id);
                Player_RefreshEquipModel_0_001CEA50(1);
                Snd_PlaySe_3_00131600(0x67, a0->xE);
            } else {
                Snd_PlaySe_3_00131600(0x6B, a0->xE);
            }
            Inventory_Recount_0_001CCE30();
            Player_RecalcStats_1_001CEDC0(3);
        }
        a0->x4 = 0;
    } else if (flags & 0x1000) {
        toggle(a0, D_004A28D0[0].f.f.b3);
        a0->x4 = 0;
    } else if (flags & 0x8000) {
        D_004A28D0[0].f.f.b2 = !D_004A28D0[0].f.f.b2;
        Snd_PlaySe_3_00131600(0x67, a0->xE);
        a0->x4 = 0;
    } else if (flags & 0x4000) {
        t = D_004A28D0[0].f.f.b3;
        if (t) {
            toggle(a0, t);
            a0->x4 = 0;
        } else {
            a0->x8 = 0x14;
            a0->x4 = 0;
            a0->x0 = 0x1A;
            UiAnim_SetVisible_1_0017F7C0(D_00201D48, 0, 1);
            Ui_SetOffset_0_001803D0(-2, -2);
            Ui_SetOffsetA_0_001803B0(0, 0);
            Snd_PlaySe_3_00131600(0x69, a0->xE);
            a0->x4 = 0;
        }
    }
    if (UiAnim_SetTarget_1_0017F470(D_004A28C0[0], D_00201D48, 0) || D_004A28D0[0].f.f.b3) {
        if (D_004A28C0[0] != cur) Snd_PlaySe_3_00131600(0x66, a0->xE);
        D_004A28C0[0] = cur;
        D_002021AC = 0;
    }
}

/* Equip_SelectBest_0_0019A0D0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A18C0[0x63];
#define DbItem_Find_1_0019D510 DbItem_Find_1_0019D510__as_Equip_SelectBest_0_0019A0D0
s32 DbItem_Find_1_0019D510__as_Equip_SelectBest_0_0019A0D0(s32);
#define Ui_SetOffsetA_0_001803B0 Ui_SetOffsetA_0_001803B0__as_Equip_SelectBest_0_0019A0D0
void Ui_SetOffsetA_0_001803B0__as_Equip_SelectBest_0_0019A0D0(s32 *, s32);

void Equip_SelectBest_0_0019A0D0(s32 arg0) {
    s32 i;

    for (i = 99; i >= 0; i--) {
        D_004A18C0[i] = 0;
    }
    for (i = 100; i < 0x400; i++) {
        Item_GetTable_1_001AFC90();
        D_004A18C0[i] = 0;
        if (DbItem_Find_1_0019D510(i) && Item_GetStatValue_0_00187130(i, arg0)) {
            D_004A18C0[i] = 1;
        }
    }
    Ui_SetOffsetA_0_001803B0(D_004A18C0, 0);
}
#undef DbItem_Find_1_0019D510
#undef Ui_SetOffsetA_0_001803B0

/* Equip_BuildList_0_0019A1D0 */

void Equip_BuildList_0_0019A1D0(s32 arg0) {
    s32 i;
    E_Equip_BuildList_0_0019A1D0 *base;
    P *p;
    E_Equip_BuildList_0_0019A1D0 *e;
    s32 v;

    base = Item_GetTable_1_001AFC90();
    D_002021B4 = 0;
    memset(D_00201D4C, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        p = Inventory_GetEntry_1_001CC3F0(ItemSort_GetCount_0_00195BE0(i));
        if (!(p->x2 > 0)) {
            if (ItemMenu_IsUsable_0_0019DE30(ItemSort_GetCount_0_00195BE0(i)) == 0) {
                continue;
            }
            if (!(p->x3 > 0)) {
                continue;
            }
        }
        e = &base[ItemSort_GetCount_0_00195BE0(i)];
        if (arg0 < 2 && e->xA != 2) {
            continue;
        }
        if (!(arg0 < 2) && arg0 < 9) {
            if (e->xA != 1) {
                continue;
            }
            if (e->x20 != arg0 - 2) {
                continue;
            }
        }
        if (arg0 == 9) {
            if (e->xA != 0) {
                continue;
            }
            if (ItemSort_GetCount_0_00195BE0(i) == 0) {
                continue;
            }
        }
        v = ItemSort_GetCount_0_00195BE0(i);
        D_00201D4C[D_002021B4] = v;
        if (v == Equip_GetSlotItem_1_001CCD90(arg0)) {
            D_004A28C0[0] = D_002021B4;
        }
        D_002021B4++;
    }
}

/* Equip_CalcStatBars_0_0019A370 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Equip_CalcStatBars_0_0019A370
extern u8 *Item_GetTable_1_001AFC90__as_Equip_CalcStatBars_0_0019A370(void);

void Equip_CalcStatBars_0_0019A370(u16 *a0, u16 *a1, void *a2, void *a3, s32 t0) {
    u8 *e = Item_GetTable_1_001AFC90() + t0 * 0x90;
    memset(a1, 0, 0x10);
    memset(a0, 0, 0x10);
    memset(a3, 0, 0x10);
    memset(a2, 0, 0x10);
    if (t0 >= 0) {
        switch (Item_GetCategory_0_001AFBD0(t0)) {
        case 1:
            a0[0] = *(u16 *)(e + 0x2C); a0[1] = *(u16 *)(e + 0x2E);
            a0[2] = *(u16 *)(e + 0x30); a0[3] = *(u16 *)(e + 0x32);
            a0[4] = *(u16 *)(e + 0x34); a0[5] = *(u16 *)(e + 0x36);
            a0[6] = *(u16 *)(e + 0x38); a0[7] = *(u16 *)(e + 0x3A);
            a1[0] = *(u16 *)(e + 0x4A); a1[1] = *(u16 *)(e + 0x4C);
            a1[2] = *(u16 *)(e + 0x4E); a1[3] = *(u16 *)(e + 0x50);
            a1[4] = *(u16 *)(e + 0x52); a1[5] = *(u16 *)(e + 0x54);
            break;
        case 2:
            a1[0] = *(u16 *)(e + 0x30); a1[1] = *(u16 *)(e + 0x32);
            a1[2] = *(u16 *)(e + 0x34); a1[3] = *(u16 *)(e + 0x36);
            a1[4] = *(u16 *)(e + 0x38); a1[5] = *(u16 *)(e + 0x3A);
            break;
        }
    }
}
#undef Item_GetTable_1_001AFC90

/* Player_CalcStats_0_0019A500 */
void Player_CalcStats_0_0019A500(s32 a0, s32 a1, u32 *a2, u32 *a3, u32 *t0, s32 t1, s32 t2, s32 t3) {
    s8 *base;
    s32 i;
    Ids ids;
    Col col[10];

    base = PlayerData_Get_2_001C9BA0();
    ids = *(Ids *)(base + 0x80);
    memset(col, 0, 0x28);
    if (t1 >= 0) {
        Equip_Assign_1_001CCF50(&ids, t1, t2);
    }
    for (i = 0; i < 10; i++) {
        if (ids.v[i] != -1) {
            col[i] = *(Col *)(base + 0xA0 + ids.v[i] * 4);
            if (i == t1 && t3 != 0) {
                col[i].b[0] = *Inventory_GetSlot_1_001A97D0(ids.v[i]);
            }
        }
    }
    Player_CalcStatsFor_0_001CF480(a0, 0, a1, 0, &ids, col, 3);
    *a2 = Stats_CalcWeight_0_001D1170();
    *a3 = Stats_CalcMaxMp_0_001D1110(a0);
    *t0 = Stats_CalcMaxHp_0_001D10B0(a0);
}

/* EquipProc_Pos_0_0019A6A0 */
void EquipProc_Pos_0_0019A6A0(s32 i, A *a, B *b) {
    s32 t;
    UiAnim_Get_1_0017F840(D_00201D48, &t);
    switch (D_002021AC) {
    case 0:
        a->x14 = b->x8 - (f32)i;
        break;
    case 2:
        if (i >= D_004A28C0[0] - 3 && i <= D_004A28C0[0] + 3) {
            a->x14 = D_00201D50[i] = b->x8 - (f32)i;
        } else {
            a->x14 = D_00201D50[i] = -5.0f;
        }
        break;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_00495B60[];
extern u8 D_00496B60[];
/* data twins (src/game/data/sdata.c): D_00201D48, D_00201D4C */
s32 D_00201D48 = 6;
s32 *D_00201D4C = (s32 *)D_00495B60;
/* data twins (src/game/data/sbss.c): D_002021B0 */
s32 D_002021B0;
/* data twins (src/game/data/item_menu_draw_bss.c): D_004A28C0 */
s32 D_004A28C0[0x1];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_001F3000[];
/* data group (src/game/data/databook_item_reset_data.c): D_001F3040__grp: D_001F3040@0x0 */
s32 D_001F3040__grp[0x8] __attribute__((aligned(16))) = { 0, 5, 0, (s32)D_001F3000, 7, -0x3fc00000, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/databook_item_reset_data.c): D_001F3000 */
u8 D_001F3000[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/ui_gauge_bss.c): D_00495B60__grp: D_00495B60@0x0 */
u8 D_00495B60__grp[0x1000] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/ui_gauge_bss.c): D_00496B60__grp: D_00496B60@0x0 */
u8 D_00496B60__grp[0x1000] __attribute__((aligned(16)));
#endif
