/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Inventory_Sort_0_0019FD00.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* Inventory_Sort_0_0019FD00 NEAR: 44 of 432 words differ (was 65). Case 6 fixed: e3 = &Item_GetTable_1_001AFC90()[id = u] and calc() decls
   s16 v; E *e; Q *q;. Still differs: case 1 only - retail sign-extends n = (s16)k into s0 right after the beqz (k in v1,
   before the jal Item_GetTable_1_001AFC90); ours keeps k in s0 and does the sext just before the mult, shifting everything by one
   instruction until the mult. Tried block-local k, cv() inline, (s16) casts, re-reading D_004A3312, inline with s16 param. */
#include "m2c.h"
typedef struct { u8 pad[6]; u8 x6; u8 x7; u8 pad8[2]; u16 xA; u8 padC[0x30]; u8 x3C; u8 x3D; u8 pad3E[0x52]; } E;
typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; u8 x4; u8 x5; } Q;
typedef struct { s16 h0; s16 h2; s16 h4; s16 h6; } H;
E *Item_GetTable_1_001AFC90(void);
Q *Inventory_GetSlot_1_001A97D0(s16);
Q *Inventory_GetEntry_1_001CC3F0(s16);
void Save_SetItemBit_1_001A9B90(s16);
void Inventory_RemoveOne_1_001CBA60(s16);
void Player_RecalcStats_1_001CEDC0(s32);
H *PlayerData_Get_2_001C9BA0(void);
void Equip_SelectBest_0_0019A0D0(s32);
extern u16 gShopBss_004A3310[];
extern s16 D_004A3312[];
extern s32 gShopBss_004A3318[];

static inline E *item(s32 id) { return &Item_GetTable_1_001AFC90()[id]; }
static inline s16 calc(u32 id) {
    s16 v;
    E *e;
    Q *q;

    v = 0;
    e = Item_GetTable_1_001AFC90();
    q = Inventory_GetEntry_1_001CC3F0(id);
    if (id == -1) return -1;
    switch (e[id].xA) {
    case 1:
        v = e[id].x3D;
        break;
    case 2:
        v = e[id].x3D;
        break;
    }
    if (q->x0 <= 0) {
        return (100 - q->x0) * (v / 5) * 2;
    }
    return (100 - q->x0) * (v / 5);
}

void Inventory_Sort_0_0019FD00(void) {
    s16 n;
    s32 id;
    E *e;
    Q *q;
    Q *p;
    E *e3;
    s16 v;
    s32 k;
    u16 u;

    switch (gShopBss_004A3318[0]) {
    case 0:
        break;
    case 1:
        k = D_004A3312[0];
        if (k == 0) break;
        id = gShopBss_004A3310[0];
        n = k;
        e = &Item_GetTable_1_001AFC90()[id];
        Inventory_GetSlot_1_001A97D0(id);
        Inventory_GetEntry_1_001CC3F0(id)->x0 = Inventory_GetSlot_1_001A97D0(id)->x0;
        Inventory_GetEntry_1_001CC3F0(id)->x3 = Inventory_GetSlot_1_001A97D0(id)->x3;
        Inventory_GetEntry_1_001CC3F0(id)->x1 = Inventory_GetSlot_1_001A97D0(id)->x1;
        Save_SetItemBit_1_001A9B90(id);
        Inventory_RemoveOne_1_001CBA60(-e->x6 * n);
        k = -n;
        q = Inventory_GetSlot_1_001A97D0(id);
        if (k > 0) {
            q->x2 += k;
            n = k;
        } else {
            k = -k;
            if (q->x2 <= k) {
                n = q->x2;
                q->x5 = 0;
                q->x2 = 0;
            } else {
                q->x2 -= k;
                n = k;
            }
        }
        Inventory_GetEntry_1_001CC3F0(id)->x2 += n;
        break;
    case 2:
        Player_RecalcStats_1_001CEDC0(3);
        id = gShopBss_004A3310[0];
        Inventory_GetSlot_1_001A97D0(id)->x0 = Inventory_GetEntry_1_001CC3F0(id)->x0;
        Inventory_GetSlot_1_001A97D0(id)->x3 = Inventory_GetEntry_1_001CC3F0(id)->x3;
        Inventory_GetSlot_1_001A97D0(id)->x1 = Inventory_GetEntry_1_001CC3F0(id)->x1;
        Inventory_GetSlot_1_001A97D0(id)->x2 = 1;
        Inventory_GetSlot_1_001A97D0(id)->x5 = 1;
        Inventory_GetEntry_1_001CC3F0(id)->x2 = 0;
        e = Item_GetTable_1_001AFC90();
        if (Inventory_GetSlot_1_001A97D0(id)->x5 == 2) {
            v = 5;
        } else if (Inventory_GetEntry_1_001CC3F0(id)->x0 <= 0) {
            v = 1;
        } else {
            v = e[id].x7;
        }
        Inventory_RemoveOne_1_001CBA60(v);
        break;
    case 3:
        n = D_004A3312[0];
        id = gShopBss_004A3310[0];
        Inventory_GetSlot_1_001A97D0(id)->x0 = Inventory_GetEntry_1_001CC3F0(id)->x0;
        Inventory_GetSlot_1_001A97D0(id)->x3 = Inventory_GetEntry_1_001CC3F0(id)->x3;
        Inventory_GetSlot_1_001A97D0(id)->x1 = Inventory_GetEntry_1_001CC3F0(id)->x1;
        Inventory_GetEntry_1_001CC3F0(id)->x2 -= n;
        Inventory_GetSlot_1_001A97D0(id)->x4 += n;
        break;
    case 4:
        n = D_004A3312[0];
        id = gShopBss_004A3310[0];
        Inventory_GetEntry_1_001CC3F0(id)->x0 = Inventory_GetSlot_1_001A97D0(id)->x0;
        Inventory_GetEntry_1_001CC3F0(id)->x3 = Inventory_GetSlot_1_001A97D0(id)->x3;
        Inventory_GetEntry_1_001CC3F0(id)->x1 = Inventory_GetSlot_1_001A97D0(id)->x1;
        Save_SetItemBit_1_001A9B90(id);
        Inventory_GetEntry_1_001CC3F0(id)->x2 += n;
        Inventory_GetSlot_1_001A97D0(id)->x4 -= n;
        break;
    case 5:
        p = Inventory_GetEntry_1_001CC3F0(*(s16 *)gShopBss_004A3310);
        id = gShopBss_004A3310[0];
        Inventory_GetSlot_1_001A97D0(id)->x0 = Inventory_GetEntry_1_001CC3F0(id)->x0;
        Inventory_GetSlot_1_001A97D0(id)->x3 = Inventory_GetEntry_1_001CC3F0(id)->x3;
        Inventory_GetSlot_1_001A97D0(id)->x1 = Inventory_GetEntry_1_001CC3F0(id)->x1;
        Inventory_GetSlot_1_001A97D0(id)->x2 = 1;
        Inventory_GetSlot_1_001A97D0(id)->x5 = 1;
        Inventory_GetEntry_1_001CC3F0(id)->x2 = 0;
        p->x2 = 0;
        PlayerData_Get_2_001C9BA0()->h4 = PlayerData_Get_2_001C9BA0()->h0;
        PlayerData_Get_2_001C9BA0()->h6 = PlayerData_Get_2_001C9BA0()->h2;
        break;
    case 6: {
        Q *p;
        E *e3;
        u16 u;
        s32 id;

        p = Inventory_GetEntry_1_001CC3F0(*(s16 *)gShopBss_004A3310);
        u = gShopBss_004A3310[0];
        e3 = &Item_GetTable_1_001AFC90()[id = u];
        PlayerData_Get_2_001C9BA0()->h4 -= calc(id);
        if (e3->xA == 1) {
            p->x0 = e3->x3C;
        } else if (e3->xA == 2) {
            p->x0 = e3->x3C;
        }
        Equip_SelectBest_0_0019A0D0(0);
        break;
    }
    }
    gShopBss_004A3318[0] = 0;
}
#else
INCLUDE_ASM(Inventory_Sort_0_0019FD00);
#endif
