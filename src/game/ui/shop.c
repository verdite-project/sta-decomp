#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/ui.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x31]; u8 x3D; u8 pad3E[0x52]; } E_Shop_SelectItem_0_001A03C0;
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } Ev;
typedef struct { u8 p:2; u8 v:1; u8 b3:1; u8 b4:1; } B;
typedef struct { u8 pad[4]; s16 x4; } R;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
typedef struct { u8 pad[4]; u8 max; } K_Shop_BuyQuantity_0_001A0850;
typedef struct { u8 pad[2]; u8 n; } C;
typedef struct { u8 pad[4]; u8 max; } K_Shop_SellQuantity_0_001A0B00;
typedef struct { u8 pad[7]; u8 lv; u8 pad8[0x88]; } E_Shop_Repair_0_001A0DB0;
typedef struct { u8 pad[5]; u8 kind; } K_Shop_Repair_0_001A0DB0;
typedef struct { u8 pad[6]; u8 lv; u8 pad7[0x89]; } E_Shop_Heal_0_001A1000;
typedef struct { u8 pad[2]; u8 n; u8 p3[2]; u8 kind; } K_Shop_Heal_0_001A1000;
typedef struct { s32 x0; u32 flags; char p8[2]; u8 bA; char pB[3]; u8 bE; } Obj;
extern u16 gShopBss_004A3310[];
#ifndef NONMATCHING
extern s32 gShopBss_004A32E0[];
extern s32 gShopBss_004A32E4[];
extern s32 gShopBss_004A32E8[];
#else
/* data twins (src/game/data/shop_bss.c): gShopBss_004A32E0 */
static s32 gShopBss_004A32E0[0x1];
/* data twins (src/game/data/shop_bss.c): gShopBss_004A32E4 */
static s32 gShopBss_004A32E4[0x1];
/* data twins (src/game/data/shop_bss.c): gShopBss_004A32E8 */
static s32 gShopBss_004A32E8[0x1];
#endif
extern void *gShopBss_004A32EC[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A32F0[0x8];
extern s32 gShopBss_004A3318[];
extern s32 gShopBss_004A3328[];
extern B gShopBss_004A332C[];
extern void (*gShopBss_004A32EC__as_Shop_Confirm_0_001A06B0[])();
extern F gShopBss_004A332C__as_Shop_Confirm_0_001A06B0[];
extern void (*gShopBss_004A32EC__as_Shop_BuyQuantity_0_001A0850[])();
extern s16 gShopBss_004A3310__as_Shop_BuyQuantity_0_001A0850[];
extern F gShopBss_004A332C__as_Shop_BuyQuantity_0_001A0850[];
extern void (*gShopBss_004A32EC__as_Shop_SellQuantity_0_001A0B00[])();
extern s16 gShopBss_004A3310__as_Shop_SellQuantity_0_001A0B00[];
extern F gShopBss_004A332C__as_Shop_SellQuantity_0_001A0B00[];
extern void (*gShopBss_004A32EC__as_Shop_Repair_0_001A0DB0[])();
extern F gShopBss_004A332C__as_Shop_Repair_0_001A0DB0[];
extern void (*gShopBss_004A32EC__as_Shop_Heal_0_001A1000[])();
extern s16 gShopBss_004A3310__as_Shop_Heal_0_001A1000[];
extern F gShopBss_004A332C__as_Shop_Heal_0_001A1000[];
extern struct { unsigned char : 4; unsigned char f : 1; char pad[15]; } gShopBss_004A332C__as_ShopProc_BackB_0_001A13F0;
void Shop_SelectItem_0_001A03C0(Ev *arg0);
void Shop_Confirm_0_001A06B0(s8 *a0);
void Shop_BuyQuantity_0_001A0850(s8 *a0);
void Shop_SellQuantity_0_001A0B00(s8 *a0);
void Shop_Repair_0_001A0DB0(s8 *a0);
void Shop_Heal_0_001A1000(s8 *a0);
void ShopProc_BackA_0_001A1380(Obj *o);
void ShopProc_BackB_0_001A13F0(Obj *o);
E_Shop_SelectItem_0_001A03C0* Item_GetTable_1_001AFC90(void);
u8* Inventory_GetEntry_1_001CC3F0(s16);
R* PlayerData_Get_2_001C9BA0(void);
void MenuProc_Run_1_0018B320(s32 *);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void *, s32, f32);
void Snd_PlaySe_3_00131600(s32, u8);
K_Shop_BuyQuantity_0_001A0850* Inventory_GetSlot_1_001A97D0(s16);
s16 PlayerData_GetGold_0_001CBA30(void);
s16* PlayerData_Get_2_001C9BA0__as_Shop_Confirm_0_001A06B0(void);
void Snd_PlaySe_3_00131600__as_Shop_Confirm_0_001A06B0(s32, s32);
void MenuProc_Set_1_0018B150__as_Shop_BuyQuantity_0_001A0850(f32, s32 *, s32, s32, void (*)(), s32);
void Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(s32, s32);
C* Inventory_GetEntry_1_001CC3F0__as_Shop_BuyQuantity_0_001A0850(s16);
void MenuProc_Set_1_0018B150__as_Shop_SellQuantity_0_001A0B00(f32, s32 *, s32, s32, void (*)(), s32);
void Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(s32, s32);
K_Shop_SellQuantity_0_001A0B00* Inventory_GetSlot_1_001A97D0__as_Shop_SellQuantity_0_001A0B00(s16);
C* Inventory_GetEntry_1_001CC3F0__as_Shop_SellQuantity_0_001A0B00(s16);
void MenuProc_Set_1_0018B150__as_Shop_Repair_0_001A0DB0(f32, s32 *, s32, s32, void (*)(), s32);
void Snd_PlaySe_3_00131600__as_Shop_Repair_0_001A0DB0(s32, s32);
E_Shop_Repair_0_001A0DB0* Item_GetTable_1_001AFC90__as_Shop_Repair_0_001A0DB0(void);
K_Shop_Repair_0_001A0DB0* Inventory_GetSlot_1_001A97D0__as_Shop_Repair_0_001A0DB0(s16);
void MenuProc_Set_1_0018B150__as_Shop_Heal_0_001A1000(f32, s32 *, s32, s32, void (*)(), s32);
void Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(s32, s32);
E_Shop_Heal_0_001A1000* Item_GetTable_1_001AFC90__as_Shop_Heal_0_001A1000(void);
K_Shop_Heal_0_001A1000* Inventory_GetSlot_1_001A97D0__as_Shop_Heal_0_001A1000(s16);
K_Shop_Heal_0_001A1000* Inventory_GetEntry_1_001CC3F0__as_Shop_Heal_0_001A1000(s16);

/* Shop_SelectItem_0_001A03C0 */
#define ShopProc_BackA_0_001A1380 ShopProc_BackA_0_001A1380__as_Shop_SelectItem_0_001A03C0
void ShopProc_BackA_0_001A1380__as_Shop_SelectItem_0_001A03C0(void);
#define ShopProc_BackB_0_001A13F0 ShopProc_BackB_0_001A13F0__as_Shop_SelectItem_0_001A03C0
void ShopProc_BackB_0_001A13F0__as_Shop_SelectItem_0_001A03C0();

/* Shop_SelectItem_0_001A03C0 */
void Shop_SelectItem_0_001A03C0(Ev *arg0) {
    s32 id;
    s16 v;
    E_Shop_SelectItem_0_001A03C0 *e;
    u8 *q;
    s16 r;

    if (gShopBss_004A332C[0].b4) {
        gShopBss_004A32E0[0] = 0;
        gShopBss_004A32E4[0] = 3;
        gShopBss_004A32EC[0] = Notify_DrawItemGet_0_0019F050;
        D_004A32F0[0] = 0x3F800000;
        gShopBss_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(gShopBss_004A32E0);
        arg0->xA = 1;
        gShopBss_004A332C[0].b4 = 0;
        gShopBss_004A3328[0] = 0x41200000;
    } else if (arg0->x4 & 0x2000) {
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
        if (PlayerData_Get_2_001C9BA0()->x4 > r) {
            gShopBss_004A3318[0] = gShopBss_004A331C[0];
            gShopBss_004A332C[0].v = 1;
            Snd_PlaySe_3_00131600(0x67, arg0->xE);
        } else {
            MenuProc_Set_1_0018B150(gShopBss_004A32E0, 0xA4, 2, ShopProc_BackA_0_001A1380, 0, 1.0f);
            MenuProc_Run_1_0018B320(gShopBss_004A32E0);
            arg0->xA = 1;
            arg0->xB = 1;
            Snd_PlaySe_3_00131600(0x6B, arg0->xE);
        }
    } else if (arg0->x4 & 0x4000) {
        gShopBss_004A332C[0].v = 1;
        Snd_PlaySe_3_00131600(0x68, arg0->xE);
    }
}

/* Shop_Confirm_0_001A06B0 */

void Shop_Confirm_0_001A06B0(s8 *a0) {
    if (gShopBss_004A332C__as_Shop_Confirm_0_001A06B0[0].b4) {
        gShopBss_004A32E0[0] = 0;
        gShopBss_004A32E4[0] = 3;
        gShopBss_004A32EC__as_Shop_Confirm_0_001A06B0[0] = Notify_DrawItemName_0_0019F310;
        D_004A32F0[0] = 0x3F800000;
        gShopBss_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(gShopBss_004A32E0);
        a0[0xA] = 1;
        gShopBss_004A332C__as_Shop_Confirm_0_001A06B0[0].b4 = 0;
        gShopBss_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        if (PlayerData_Get_2_001C9BA0__as_Shop_Confirm_0_001A06B0()[2] == PlayerData_Get_2_001C9BA0__as_Shop_Confirm_0_001A06B0()[0] && PlayerData_Get_2_001C9BA0__as_Shop_Confirm_0_001A06B0()[3] == PlayerData_Get_2_001C9BA0__as_Shop_Confirm_0_001A06B0()[1]) {
            Snd_PlaySe_3_00131600__as_Shop_Confirm_0_001A06B0(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        gShopBss_004A3318[0] = gShopBss_004A331C[0];
        gShopBss_004A332C__as_Shop_Confirm_0_001A06B0[0].b2 = 1;
        Snd_PlaySe_3_00131600__as_Shop_Confirm_0_001A06B0(0x67, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        gShopBss_004A332C__as_Shop_Confirm_0_001A06B0[0].b2 = 1;
        Snd_PlaySe_3_00131600__as_Shop_Confirm_0_001A06B0(0x68, *(u8 *)(a0 + 0xE));
    }
}

/* Shop_BuyQuantity_0_001A0850 */

void Shop_BuyQuantity_0_001A0850(s8 *a0) {
    s16 n; s32 m; u8 c;

    if (gShopBss_004A332C__as_Shop_BuyQuantity_0_001A0850[0].b4) {
        gShopBss_004A32E0[0] = 0;
        gShopBss_004A32E4[0] = 3;
        gShopBss_004A32EC__as_Shop_BuyQuantity_0_001A0850[0] = Notify_DrawItemCount_0_0019F410;
        D_004A32F0[0] = 0x3F800000;
        gShopBss_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(gShopBss_004A32E0);
        a0[0xA] = 1;
        gShopBss_004A332C__as_Shop_BuyQuantity_0_001A0850[0].b4 = 0;
        gShopBss_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x80) {
        D_004A3312[0]--;
        if (D_004A3312[0] <= 0) {
            D_004A3312[0] = 1;
            return;
        }
        Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x20) {
        D_004A3312[0]++;
        m = D_004A3312[0];
        if (Inventory_GetSlot_1_001A97D0(gShopBss_004A3310__as_Shop_BuyQuantity_0_001A0850[0])->max < m) {
            D_004A3312[0] = Inventory_GetSlot_1_001A97D0(gShopBss_004A3310__as_Shop_BuyQuantity_0_001A0850[0])->max;
            return;
        }
        Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        n = D_004A3312[0];
        c = Inventory_GetEntry_1_001CC3F0__as_Shop_BuyQuantity_0_001A0850(gShopBss_004A3310__as_Shop_BuyQuantity_0_001A0850[0])->n;
        if ((s16)n + c > 99) {
            MenuProc_Set_1_0018B150__as_Shop_BuyQuantity_0_001A0850(1.0f, gShopBss_004A32E0, 0xA2, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(gShopBss_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        if (n) {
            gShopBss_004A3318[0] = gShopBss_004A331C[0];
            gShopBss_004A332C__as_Shop_BuyQuantity_0_001A0850[0].b2 = 1;
            Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(0x67, *(u8 *)(a0 + 0xE));
            return;
        }
        Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(0x68, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        gShopBss_004A332C__as_Shop_BuyQuantity_0_001A0850[0].b2 = 1;
        Snd_PlaySe_3_00131600__as_Shop_BuyQuantity_0_001A0850(0x68, *(u8 *)(a0 + 0xE));
    }
}

/* Shop_SellQuantity_0_001A0B00 */

void Shop_SellQuantity_0_001A0B00(s8 *a0) {
    s16 n; s32 m; u8 c;

    if (gShopBss_004A332C__as_Shop_SellQuantity_0_001A0B00[0].b4) {
        gShopBss_004A32E0[0] = 0;
        gShopBss_004A32E4[0] = 3;
        gShopBss_004A32EC__as_Shop_SellQuantity_0_001A0B00[0] = Notify_DrawItemCountB_0_0019F690;
        D_004A32F0[0] = 0x3F800000;
        gShopBss_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(gShopBss_004A32E0);
        a0[0xA] = 1;
        gShopBss_004A332C__as_Shop_SellQuantity_0_001A0B00[0].b4 = 0;
        gShopBss_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x80) {
        D_004A3312[0]--;
        if (D_004A3312[0] <= 0) {
            D_004A3312[0] = 1;
            return;
        }
        Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x20) {
        D_004A3312[0]++;
        m = D_004A3312[0];
        if (Inventory_GetEntry_1_001CC3F0__as_Shop_SellQuantity_0_001A0B00(gShopBss_004A3310__as_Shop_SellQuantity_0_001A0B00[0])->n < m) {
            D_004A3312[0] = Inventory_GetEntry_1_001CC3F0__as_Shop_SellQuantity_0_001A0B00(gShopBss_004A3310__as_Shop_SellQuantity_0_001A0B00[0])->n;
            return;
        }
        Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        n = D_004A3312[0];
        c = Inventory_GetSlot_1_001A97D0__as_Shop_SellQuantity_0_001A0B00(gShopBss_004A3310__as_Shop_SellQuantity_0_001A0B00[0])->max;
        if ((s16)n + c > 99) {
            MenuProc_Set_1_0018B150__as_Shop_SellQuantity_0_001A0B00(1.0f, gShopBss_004A32E0, 0xA1, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(gShopBss_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        if (n) {
            gShopBss_004A3318[0] = gShopBss_004A331C[0];
            gShopBss_004A332C__as_Shop_SellQuantity_0_001A0B00[0].b2 = 1;
            Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(0x67, *(u8 *)(a0 + 0xE));
            return;
        }
        Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(0x68, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        gShopBss_004A332C__as_Shop_SellQuantity_0_001A0B00[0].b2 = 1;
        Snd_PlaySe_3_00131600__as_Shop_SellQuantity_0_001A0B00(0x68, *(u8 *)(a0 + 0xE));
    }
}

/* Shop_Repair_0_001A0DB0 */

void Shop_Repair_0_001A0DB0(s8 *a0) {
    s32 id;
    E_Shop_Repair_0_001A0DB0 *t;
    s16 m;
    s16 r;

    if (gShopBss_004A332C__as_Shop_Repair_0_001A0DB0[0].b4) {
        gShopBss_004A32E0[0] = 0;
        gShopBss_004A32E4[0] = 3;
        gShopBss_004A32EC__as_Shop_Repair_0_001A0DB0[0] = Notify_DrawGold_0_0019F890;
        D_004A32F0[0] = 0x3F800000;
        gShopBss_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(gShopBss_004A32E0);
        a0[0xA] = 1;
        gShopBss_004A332C__as_Shop_Repair_0_001A0DB0[0].b4 = 0;
        gShopBss_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        id = gShopBss_004A3310[0];
        t = Item_GetTable_1_001AFC90__as_Shop_Repair_0_001A0DB0();
        if (Inventory_GetSlot_1_001A97D0__as_Shop_Repair_0_001A0DB0(id)->kind == 2) {
            m = 5;
        } else if (*Inventory_GetEntry_1_001CC3F0(id) <= 0) {
            m = 1;
        } else {
            m = t[id].lv;
        }
        r = PlayerData_GetGold_0_001CBA30();
        if (r + D_004A3312[0] * m > 99) {
            MenuProc_Set_1_0018B150__as_Shop_Repair_0_001A0DB0(1.0f, gShopBss_004A32E0, 0xA5, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(gShopBss_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600__as_Shop_Repair_0_001A0DB0(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        gShopBss_004A3318[0] = gShopBss_004A331C[0];
        gShopBss_004A332C__as_Shop_Repair_0_001A0DB0[0].b2 = 1;
        Snd_PlaySe_3_00131600__as_Shop_Repair_0_001A0DB0(0x67, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        gShopBss_004A332C__as_Shop_Repair_0_001A0DB0[0].b2 = 1;
        Snd_PlaySe_3_00131600__as_Shop_Repair_0_001A0DB0(0x68, *(u8 *)(a0 + 0xE));
    }
}

/* Shop_Heal_0_001A1000 */

void Shop_Heal_0_001A1000(s8 *a0) {
    s32 m;
    s32 id;
    E_Shop_Heal_0_001A1000 *t;
    s16 k;
    s16 r;

    if (gShopBss_004A332C__as_Shop_Heal_0_001A1000[0].b4) {
        gShopBss_004A32E0[0] = 0;
        gShopBss_004A32E4[0] = 3;
        gShopBss_004A32EC__as_Shop_Heal_0_001A1000[0] = Notify_DrawItemGold_0_0019FA00;
        D_004A32F0[0] = 0x3F800000;
        gShopBss_004A32E8[0] = 0;
        MenuProc_Run_1_0018B320(gShopBss_004A32E0);
        a0[0xA] = 1;
        gShopBss_004A332C__as_Shop_Heal_0_001A1000[0].b4 = 0;
        gShopBss_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x80) {
        D_004A3312[0]--;
        if (D_004A3312[0] <= 0) {
            D_004A3312[0] = 1;
            return;
        }
        Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x20) {
        D_004A3312[0]++;
        m = D_004A3312[0];
        if (Inventory_GetSlot_1_001A97D0__as_Shop_Heal_0_001A1000(gShopBss_004A3310__as_Shop_Heal_0_001A1000[0])->n < m) {
            D_004A3312[0] = Inventory_GetSlot_1_001A97D0__as_Shop_Heal_0_001A1000(gShopBss_004A3310__as_Shop_Heal_0_001A1000[0])->n;
        } else {
            Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(0x6A, *(u8 *)(a0 + 0xE));
        }
        if (D_004A3312[0] > 99) {
            D_004A3312[0] = 99;
        }
    }
    else if (*(s32 *)(a0 + 4) & 0x2000) {
        if (D_004A3312[0] + Inventory_GetEntry_1_001CC3F0__as_Shop_Heal_0_001A1000(gShopBss_004A3310__as_Shop_Heal_0_001A1000[0])->n > 99) {
            MenuProc_Set_1_0018B150__as_Shop_Heal_0_001A1000(1.0f, gShopBss_004A32E0, 0xA0, 2, ShopProc_BackB_0_001A13F0, 0);
            MenuProc_Run_1_0018B320(gShopBss_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        id = (u16)gShopBss_004A3310__as_Shop_Heal_0_001A1000[0];
        t = Item_GetTable_1_001AFC90__as_Shop_Heal_0_001A1000();
        if (Inventory_GetSlot_1_001A97D0__as_Shop_Heal_0_001A1000(id)->kind == 2) {
            k = 5;
        } else {
            k = t[id].lv;
        }
        r = PlayerData_GetGold_0_001CBA30();
        if (!(r < D_004A3312[0] * k)) {
            gShopBss_004A3318[0] = gShopBss_004A331C[0];
            gShopBss_004A332C__as_Shop_Heal_0_001A1000[0].b2 = 1;
            Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(0x67, *(u8 *)(a0 + 0xE));
            return;
        }
        MenuProc_Set_1_0018B150__as_Shop_Heal_0_001A1000(1.0f, gShopBss_004A32E0, 0xA3, 2, ShopProc_BackB_0_001A13F0, 0);
        MenuProc_Run_1_0018B320(gShopBss_004A32E0);
        a0[0xA] = 1;
        a0[0xB] = 1;
        Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(0x6B, *(u8 *)(a0 + 0xE));
    }
    else if (*(s32 *)(a0 + 4) & 0x4000) {
        gShopBss_004A332C__as_Shop_Heal_0_001A1000[0].b2 = 1;
        Snd_PlaySe_3_00131600__as_Shop_Heal_0_001A1000(0x68, *(u8 *)(a0 + 0xE));
    }
}
#undef ShopProc_BackA_0_001A1380
#undef ShopProc_BackB_0_001A13F0

/* ShopProc_BackA_0_001A1380 */
#define gShopBss_004A332C gShopBss_004A332C__as_ShopProc_BackA_0_001A1380
extern struct { unsigned char : 2; unsigned char f : 1; char pad[15]; } gShopBss_004A332C__as_ShopProc_BackA_0_001A1380;

/* ShopProc_BackA_0_001A1380 */
void ShopProc_BackA_0_001A1380(Obj *o)
{
    if (o->flags & 0x2000) {
        Snd_PlaySe_3_00131600(0x68, o->bE);
        o->bA = 2;
        gShopBss_004A332C.f = 1;
    }
    o->flags = 0;
}

/* ShopProc_BackB_0_001A13F0 */

void ShopProc_BackB_0_001A13F0(Obj *o)
{
    if (o->flags & 0x2000) {
        Snd_PlaySe_3_00131600(0x68, o->bE);
        o->bA = 2;
        gShopBss_004A332C__as_ShopProc_BackB_0_001A13F0.f = 1;
    }
    o->flags = 0;
}
#undef gShopBss_004A332C

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/shop_bss.c): gShopBss_004A32EC */
void *gShopBss_004A32EC[0x1];
/* data twins (src/game/data/shop_bss_004A3310.c): gShopBss_004A3310, gShopBss_004A3318, gShopBss_004A331C, gShopBss_004A3328, gShopBss_004A332C */
u16 gShopBss_004A3310[0x4] __attribute__((aligned(16)));
s32 gShopBss_004A3318[0x1];
s32 gShopBss_004A331C[0x1];
s32 gShopBss_004A3328[0x1];
B gShopBss_004A332C[0x4 / sizeof(B)];
#endif
