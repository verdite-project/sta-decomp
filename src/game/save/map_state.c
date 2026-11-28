#include "m2c.h"
#include "common.h"
#include "game/save.h"
#include "game/data.h"
typedef AreaRec Grp;
typedef InvSlot Slot;
typedef struct { u8 pad0[0xA]; u16 type; u8 padC[0x14]; u16 x20; u8 pad22[0x1A]; u8 x3C; u8 pad3D[2]; u8 x3F; u8 pad40[0x50]; } Item;
typedef struct { char b[8]; } E;
typedef struct { char pad[0x5C00]; E e[0x400]; } S;
typedef struct { u8 pad[0x60]; s16 x60[16]; Vec x80[16]; u8 pad2[0x40]; } G_MapState_OffsetObjects_0_001A9810;
typedef struct { s8 pad[0x60]; s16 h[16]; Vec v[20]; } Rec;
typedef struct { char pad[0x5B60]; u32 bits[1]; } S_MapState_OffsetObjects_0_001A9810;
typedef struct { u8 pad[0x40]; u32 x40[8]; u8 pad2[0x160]; } G_MapState_TestBit_0_001A9BE0;
typedef struct { s8 pad[0x40]; u32 bits[(0x1C0 - 0x40) / 4]; } Rec_MapState_SetBit_0_001A9CA0;
typedef struct { s8 pad[0x180]; u32 bits[16]; } Rec_MapState_GetField_0_001A9D50;
typedef struct { u8 pad[0x180]; s32 w[16]; } Rec_MapState_SetField_0_001A9E10;
typedef struct { unsigned int : 1; unsigned int f : 1; } B_Bestiary_IsSeen_2_001A9EC0;
typedef struct { unsigned char : 1; unsigned char f : 1; } B_Bestiary_SetSeen_1_001A9F10;
typedef struct { unsigned char : 0; unsigned char f : 1; } B_Bestiary_SetKilled_1_001A9FA0;
typedef struct { u8 pad[0x499E]; u16 t[1]; } Rec_MapState_GetKillCount_0_001A9FF0;
typedef struct { u8 pad[0x497E]; u16 t[1]; } S_MapState_GetKillCount_0_001A9FF0;
typedef struct { u8 pad[0x4980]; u16 a[16]; u16 b[16]; } Big;
typedef struct { s32 v[8]; u32 n[0x68]; } E_MapState_GetCounter_0_001AA1E0;
typedef struct { s8 pad[0x20]; u32 bits[(0x1C0 - 0x20) / 4]; } Rec_MapState_IncCounter_0_001AA2A0;
typedef struct { u8 pad[0x50]; Flags8 x50; u8 pad2[0x16F]; } G_MapState_OffsetObjects_0_001A9810_;
typedef struct { s8 pad[0x50]; u8 b0 : 1; u8 r : 7; s8 rest[0x1C0 - 0x51]; } Rec_MapState_SetVisited_0_001AA4C0;
typedef struct { s32 v[0x70]; } E_MapState_GetWord_1_001AA540;
typedef struct { s32 v[0x70]; } Rec_MapState_SetWord_1_001AA5D0;
typedef struct { u8 pad[0x60]; s16 v[16]; u8 pad2[0x1C0-0x80]; } G_Inventory_FindItem_0_001AA650;
typedef struct { u8 b; char pad[7]; } E_Inventory_GetSlotFlag_0_001AA6B0;
typedef struct { char pad[0x5C04]; E_Inventory_GetSlotFlag_0_001AA6B0 e[1]; } S_Inventory_GetSlotFlag_0_001AA6B0;
typedef struct { char p0[2]; u8 b2; char p3[2]; u8 b5; char p6[2]; } E_Inventory_GetSlotCount_0_001AA6D0;
typedef struct { char pad[0x5C00]; E_Inventory_GetSlotCount_0_001AA6D0 e[1]; } S_Inventory_GetSlotCount_0_001AA6D0;
extern PlayerData *D_00201DC0;
extern S *D_00201DC0__as_Inventory_GetSlot_1_001A97D0;
extern G_MapState_OffsetObjects_0_001A9810 *D_00201DC4;
#pragma explicit_zero_data on
s16 D_001F37B0[0x30] = { 0xa, 0xb, 0xc, 0xd, 0x16, 0x21, 0x28, 0x29, 0x2a, 0x2b, 0x32, 0x33, 0x34, 0x35, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x46, 0x47, 0x50, 0x51, 0x52, 0x53, 0x5a, 0x5b, 0x5c, 0x64, 0x65, 0x6e, 0x6f, 0x70, 0x78, 0x79, 0x7a, 0x7b, 0x82, 0x83, 0x84, 0x8c, 0x96, 0, 0, 0, 0, 0, 0 };
extern Rec *D_00201DC4__as_MapState_GetObjectPos_0_001A9900;
extern Rec *D_00201DC4__as_MapState_SetObjectPos_0_001A9A20;
extern Rec_MapState_SetBit_0_001A9CA0 *D_00201DC4__as_MapState_SetBit_0_001A9CA0;
extern Rec_MapState_GetField_0_001A9D50 *D_00201DC4__as_MapState_GetField_0_001A9D50;
extern Rec_MapState_SetField_0_001A9E10 *D_00201DC4__as_MapState_SetField_0_001A9E10;
extern G_MapState_TestBit_0_001A9BE0 *D_00201DC4__as_MapState_TestBit_0_001A9BE0;
#ifdef NONMATCHING
extern u8 D_004AA440[];
#endif
#ifndef NONMATCHING
extern u8 *D_00201DC8;
#else
/* data twins (src/game/data/sdata.c): D_00201DC8 */
static u8 *D_00201DC8 __attribute__((aligned(8))) = (u8 *)D_004AA440;
#endif
extern S_MapState_GetKillCount_0_001A9FF0 *D_00201DC4__as_MapState_GetBestKillRate_0_001AA090;
extern Big *D_00201DC4__as_MapState_IncVisits_0_001AA130;
extern E_MapState_GetCounter_0_001AA1E0 *D_00201DC4__as_MapState_GetCounter_0_001AA1E0;
extern Rec_MapState_IncCounter_0_001AA2A0 *D_00201DC4__as_MapState_IncCounter_0_001AA2A0;
extern G_MapState_OffsetObjects_0_001A9810_ *D_00201DC4__as_MapState_IsVisited_1_001AA440;
extern Rec_MapState_SetVisited_0_001AA4C0 *D_00201DC4__as_MapState_SetVisited_0_001AA4C0;
extern E_MapState_GetWord_1_001AA540 *D_00201DC4__as_MapState_GetWord_1_001AA540;
extern Rec_MapState_SetWord_1_001AA5D0 *D_00201DC4__as_MapState_SetWord_1_001AA5D0;
extern Rec_MapState_GetKillCount_0_001A9FF0 *D_00201DC4__as_MapState_GetKillCount_0_001A9FF0;
extern S_Inventory_GetSlotFlag_0_001AA6B0 *D_00201DC0__as_Inventory_GetSlotFlag_0_001AA6B0;
extern S_Inventory_GetSlotCount_0_001AA6D0 *D_00201DC0__as_Inventory_GetSlotCount_0_001AA6D0;
E* Inventory_GetSlot_1_001A97D0(s16 i);
void MapState_OffsetObjects_0_001A9810(s32 k);
s16 MapState_GetObjectPos_0_001A9900(s32 id, s32 k, Vec *a, Vec *b);
void MapState_SetObjectPos_0_001A9A20(s32 id, s32 k, s16 h, Vec *a, Vec *b);
s32 Save_TestItemBit_1_001A9B40(s16 i);
void Save_SetItemBit_1_001A9B90(s16 i);
u32 MapState_GetField_0_001A9D50(s32 id, u16 k);
void MapState_SetField_0_001A9E10(s32 id, u16 k, u8 v);
s32 MapState_GetCounter_0_001AA1E0(s32 arg0, s16 arg1);
s32 MapState_GetWord_1_001AA540(s32 arg0, s16 arg1);
void MapState_SetWord_1_001AA5D0(s32 id, s16 k, s32 v);
u8 Inventory_GetSlotFlag_0_001AA6B0(s16 i);
u8 Inventory_GetSlotCount_0_001AA6D0(s16 i);
Item* Item_GetTable_1_001AFC90(void);
s32 Inventory_GetFlag_0_001CC060(s16);
s32 ItemType_IsWeapon_0_001D1D50(u16);
void sceVu0CopyVector(void *, void *);

/* Inventory_AddItem_1_001A95A0 */
/* Inventory_AddItem_1_001A95A0 */
void Inventory_AddItem_1_001A95A0(s16 id, u8 n) {
    Item *base;
    Slot *slot;
    Grp *g;
    s32 j;
    s32 k;
    s32 cnt;

    base = Item_GetTable_1_001AFC90();
    if (0 > id || id >= 0x400) {
        slot = NULL;
    } else {
        slot = &D_00201DC0->slot[id];
    }
    if (n == 0 || slot == NULL) {
        return;
    }
    if (base[id].type != 0) {
        if (Inventory_GetFlag_0_001CC060(id) != 0) {
            return;
        }
        if ((D_00201DC0->slot[id].b5 ? D_00201DC0->slot[id].b2 : 0) != 0) {
            return;
        }
        if (D_00201DC0->slot[id].b4 != 0) {
            return;
        }
        cnt = 0;
        g = D_00201DC0->grp;
        for (j = 0; j < 0x2A; j++, g++) {
            for (k = 0; k < 0x10; k++) {
                if (id == g->ids[k]) {
                    cnt++;
                }
            }
        }
        if (cnt != 0) {
            return;
        }
    }
    switch (base[id].type) {
    case 0:
        slot->b2 += n;
        if (slot->b2 > 99) {
            slot->b2 = 99;
        }
        slot->b5 = 3;
        break;
    case 1:
        slot->b0 = base[id].x3C;
        slot->b1 = 0;
        slot->b2 = 1;
        slot->b3 = 0;
        slot->b4 = 0;
        slot->b5 = 3;
        break;
    case 2:
        slot->b0 = base[id].x3C;
        slot->b1 = 0;
        slot->b2 = 1;
        slot->b3 = 0;
        slot->b4 = 0;
        slot->b5 = 3;
        if (ItemType_IsWeapon_0_001D1D50(base[id].x20) == 1) {
            slot->b3 = base[id].x3F;
        }
        break;
    }
}

/* Inventory_GetSlot_1_001A97D0 */
E *Inventory_GetSlot_1_001A97D0(s16 i) { if (0 > i || i >= 0x400) return NULL; return &D_00201DC0__as_Inventory_GetSlot_1_001A97D0->e[i]; }

/* MapState_OffsetObjects_0_001A9810 */
#define D_00201DC0 D_00201DC0__as_MapState_OffsetObjects_0_001A9810
extern S_MapState_OffsetObjects_0_001A9810 *D_00201DC0__as_MapState_OffsetObjects_0_001A9810;

/* MapState_OffsetObjects_0_001A9810 */
/* MapState_OffsetObjects_0_001A9810 */
/* MapState_OffsetObjects_0_001A9810 */
static inline s32 find_MapState_OffsetObjects_0_001A9810(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}

void MapState_OffsetObjects_0_001A9810(s32 k) {
    s32 i;
    s32 j;
    i = find_MapState_OffsetObjects_0_001A9810(k);
    if (i != -1) {
        for (j = 0; j < 16; j++) {
            D_00201DC4[i].x60[j] = -1;
            sceVu0CopyVector(&D_00201DC4[i].x80[j], &D_003139A0);
        }
    }
}

/* MapState_GetObjectPos_0_001A9900 */
static inline u32 find_MapState_GetObjectPos_0_001A9900(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}

s16 MapState_GetObjectPos_0_001A9900(s32 id, s32 k, Vec *a, Vec *b) {
    u32 i = find_MapState_GetObjectPos_0_001A9900(id);
    if (i == -1) {
        return 0;
    }
    if (a) {
        a->x = D_00201DC4__as_MapState_GetObjectPos_0_001A9900[i].v[k].x;
        a->y = D_00201DC4__as_MapState_GetObjectPos_0_001A9900[i].v[k].y;
        a->z = D_00201DC4__as_MapState_GetObjectPos_0_001A9900[i].v[k].z;
        a->w = 1.0f;
    }
    if (b) {
        b->y = D_00201DC4__as_MapState_GetObjectPos_0_001A9900[i].v[k].w;
        b->w = 0.0f;
        b->z = 0.0f;
        b->x = 0.0f;
    }
    return D_00201DC4__as_MapState_GetObjectPos_0_001A9900[i].h[k];
}

/* MapState_SetObjectPos_0_001A9A20 */
static inline u32 find_MapState_SetObjectPos_0_001A9A20(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}

void MapState_SetObjectPos_0_001A9A20(s32 id, s32 k, s16 h, Vec *a, Vec *b) {
    u32 i = find_MapState_SetObjectPos_0_001A9A20(id);
    if (i == -1) {
        return;
    }
    D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].h[k] = h;
    if (h != -1) {
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].x = a->x;
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].y = a->y;
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].z = a->z;
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].w = b->y;
    } else {
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].w = 0.0f;
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].z = 0.0f;
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].y = 0.0f;
        D_00201DC4__as_MapState_SetObjectPos_0_001A9A20[i].v[k].x = 0.0f;
    }
}

/* Save_TestItemBit_1_001A9B40 */
/* Save_TestItemBit_1_001A9B40 */
s32 Save_TestItemBit_1_001A9B40(s16 i)
{
    return (D_00201DC0->bits[i / 32] & (1 << (i % 32))) != 0;
}

/* Save_SetItemBit_1_001A9B90 */
void Save_SetItemBit_1_001A9B90(s16 i)
{
    D_00201DC0->bits[i / 32] |= 1 << (i % 32);
}

/* MapState_TestBit_0_001A9BE0 */

/* MapState_TestBit_0_001A9BE0 */
static inline s32 find_MapState_TestBit_0_001A9BE0(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 MapState_TestBit_0_001A9BE0(s32 k, s16 b) {
    s32 i = find_MapState_TestBit_0_001A9BE0(k);
    if (i == -1) return 0;
    return (D_00201DC4__as_MapState_TestBit_0_001A9BE0[i].x40[b / 32] & (1 << (b % 32))) != 0;
}

/* MapState_SetBit_0_001A9CA0 */
static inline u32 find_MapState_SetBit_0_001A9CA0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetBit_0_001A9CA0(s32 id, s16 k) {
    u32 idx = find_MapState_SetBit_0_001A9CA0(id);
    if (idx != -1) {
        D_00201DC4__as_MapState_SetBit_0_001A9CA0[idx].bits[k / 32] |= 1 << (k % 32);
    }
}

/* MapState_GetField_0_001A9D50 */
static inline u32 find_MapState_GetField_0_001A9D50(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
u32 MapState_GetField_0_001A9D50(s32 id, u16 k) {
    u32 i = find_MapState_GetField_0_001A9D50(id);
    s32 sh;
    s32 n;
    if (i == -1) {
        return 0;
    }
    n = k * 2;
    sh = n % 32;
    return ((3 << sh) & D_00201DC4__as_MapState_GetField_0_001A9D50[i].bits[n / 32]) >> sh;
}

/* MapState_SetField_0_001A9E10 */
static inline u32 find_MapState_SetField_0_001A9E10(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetField_0_001A9E10(s32 id, u16 k, u8 v) {
    u32 i = find_MapState_SetField_0_001A9E10(id);
    if (i != -1) {
        s32 b = k * 2;
        D_00201DC4__as_MapState_SetField_0_001A9E10[i].w[b / 32] |= (v & 3) << (b % 32);
    }
}

/* Bestiary_IsSeen_2_001A9EC0 */
/* Bestiary_IsSeen_2_001A9EC0 */
s32 Bestiary_IsSeen_2_001A9EC0(s16 i)
{
    if (0 > i || i > 0x80)
        return 0;
    return ((B_Bestiary_IsSeen_2_001A9EC0 *)&D_00201DC8[i])->f;
}

/* Bestiary_SetSeen_1_001A9F10 */
void Bestiary_SetSeen_1_001A9F10(s16 i)
{
    if (0 > i || i > 0x80)
        return;
    ((B_Bestiary_SetSeen_1_001A9F10 *)&D_00201DC8[i])->f = 1;
}

/* Bestiary_IsKilled_1_001A9F60 */
s32 Bestiary_IsKilled_1_001A9F60(s16 i)
{
    if (0 > i || i > 0x80)
        return 0;
    return D_00201DC8[i] & 1;
}

/* Bestiary_SetKilled_1_001A9FA0 */
void Bestiary_SetKilled_1_001A9FA0(s16 i)
{
    if (0 > i || i > 0x80)
        return;
    ((B_Bestiary_SetKilled_1_001A9FA0 *)&D_00201DC8[i])->f = 1;
}

/* MapState_GetKillCount_0_001A9FF0 */

/* MapState_GetKillCount_0_001A9FF0 */
static inline u32 find_MapState_GetKillCount_0_001A9FF0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
u16 MapState_GetKillCount_0_001A9FF0(s32 id) {
    u32 i = find_MapState_GetKillCount_0_001A9FF0(id);
    if (i == -1) {
        return 0;
    }
    return D_00201DC4__as_MapState_GetKillCount_0_001A9FF0->t[id / 10];
}

/* MapState_GetBestKillRate_0_001AA090 */
static inline s32 find_MapState_GetBestKillRate_0_001AA090(s32 k) { u32 i; for (i = 0; i < 0x2A; i++) if (k == D_001F37B0[i]) return i; return -1; }
u16 MapState_GetBestKillRate_0_001AA090(s32 a) {
 if (find_MapState_GetBestKillRate_0_001AA090(a) == -1) return 0; return D_00201DC4__as_MapState_GetBestKillRate_0_001AA090->t[a / 10];
}

/* MapState_IncVisits_0_001AA130 */
static inline u32 find_MapState_IncVisits_0_001AA130(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_IncVisits_0_001AA130(s32 id) {
    u32 i = find_MapState_IncVisits_0_001AA130(id);
    if (i != -1) {
        s32 k = id / 10 - 1;
        D_00201DC4__as_MapState_IncVisits_0_001AA130->a[k]++;
        if (D_00201DC4__as_MapState_IncVisits_0_001AA130->b[k] < D_00201DC4__as_MapState_IncVisits_0_001AA130->a[k]) D_00201DC4__as_MapState_IncVisits_0_001AA130->b[k] = D_00201DC4__as_MapState_IncVisits_0_001AA130->a[k];
    }
}

/* MapState_GetCounter_0_001AA1E0 */

static inline s32 find_MapState_GetCounter_0_001AA1E0(s32 a) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (a == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 MapState_GetCounter_0_001AA1E0(s32 arg0, s16 arg1) {
    s32 i = find_MapState_GetCounter_0_001AA1E0(arg0);
    if (i == -1) return 0;
    return (D_00201DC4__as_MapState_GetCounter_0_001AA1E0[i].n[arg1 / 8] >> (arg1 % 8 * 4)) & 0xF;
}

/* MapState_IncCounter_0_001AA2A0 */
static inline u32 find_MapState_IncCounter_0_001AA2A0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
static inline u32 get(s32 id, s16 k) {
    u32 i = find_MapState_IncCounter_0_001AA2A0(id);
    if (i == -1) {
        return 0;
    }
    return (D_00201DC4__as_MapState_IncCounter_0_001AA2A0[i].bits[k / 8] >> (k % 8 * 4)) & 0xF;
}

void MapState_IncCounter_0_001AA2A0(s32 id, s16 k) {
    u32 idx = find_MapState_IncCounter_0_001AA2A0(id);
    u32 v = get(id, k) + 1;
    if (idx != -1) {
        if (v > 16) {
            v = 16;
        }
        D_00201DC4__as_MapState_IncCounter_0_001AA2A0[idx].bits[k / 8] &= ~(0xF << (k % 8 * 4));
        D_00201DC4__as_MapState_IncCounter_0_001AA2A0[idx].bits[k / 8] |= v << (k % 8 * 4);
    }
}

/* MapState_IsVisited_1_001AA440 */
static inline s32 find_MapState_IsVisited_1_001AA440(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}
s32 MapState_IsVisited_1_001AA440(s32 k) {
    s32 i = find_MapState_IsVisited_1_001AA440(k);
    if (i == -1) return 0;
    return D_00201DC4__as_MapState_IsVisited_1_001AA440[i].x50.f.b0;
}

/* MapState_SetVisited_0_001AA4C0 */
static inline u32 find_MapState_SetVisited_0_001AA4C0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetVisited_0_001AA4C0(s32 id) {
    u32 i = find_MapState_SetVisited_0_001AA4C0(id);
    if (i != -1) {
        D_00201DC4__as_MapState_SetVisited_0_001AA4C0[i].b0 = 1;
    }
}

/* MapState_GetWord_1_001AA540 */

static inline s32 find_MapState_GetWord_1_001AA540(s32 a) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (a == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 MapState_GetWord_1_001AA540(s32 arg0, s16 arg1) {
    s32 i = find_MapState_GetWord_1_001AA540(arg0);
    if (i == -1) return 0;
    return D_00201DC4__as_MapState_GetWord_1_001AA540[i].v[arg1];
}

/* MapState_SetWord_1_001AA5D0 */
static inline u32 find_MapState_SetWord_1_001AA5D0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetWord_1_001AA5D0(s32 id, s16 k, s32 v) {
    u32 i = find_MapState_SetWord_1_001AA5D0(id);
    if (i != -1) {
        D_00201DC4__as_MapState_SetWord_1_001AA5D0[i].v[k] = v;
    }
}
#undef D_00201DC0

/* Inventory_FindItem_0_001AA650 */
#define D_00201DC0 D_00201DC0__as_Inventory_FindItem_0_001AA650
extern u8 *D_00201DC0__as_Inventory_FindItem_0_001AA650;

/* Inventory_FindItem_0_001AA650 */
s32 Inventory_FindItem_0_001AA650(s16 arg0) {
    s16 *p;
    G_Inventory_FindItem_0_001AA650 *g;
    s32 j;
    s32 i;
    s32 n;
    n = 0;
    g = (G_Inventory_FindItem_0_001AA650 *)(D_00201DC0 + 0x10E0);
    for (j = 0; j < 0x2A; j++) {
        for (i = 0; i < 0x10; i++) {
            if (arg0 == g[j].v[i]) n++;
        }
    }
    return n;
}

/* Inventory_GetSlotFlag_0_001AA6B0 */

u8 Inventory_GetSlotFlag_0_001AA6B0(s16 i)
{
    return D_00201DC0__as_Inventory_GetSlotFlag_0_001AA6B0->e[i].b;
}

/* Inventory_GetSlotCount_0_001AA6D0 */
u8 Inventory_GetSlotCount_0_001AA6D0(s16 i) { if (D_00201DC0__as_Inventory_GetSlotCount_0_001AA6D0->e[i].b5) return D_00201DC0__as_Inventory_GetSlotCount_0_001AA6D0->e[i].b2; return 0; }
#undef D_00201DC0

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_004AA440[];
#endif
