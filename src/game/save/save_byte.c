#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/save.h"
typedef InvSlot Slot;
typedef struct { u8 pad0[0x2E]; u8 x2E; u8 x2F; u8 pad30[0x5C00 - 0x30]; Slot slot[0x400]; } W;
typedef struct { u8 x0[0x20]; u8 x20[0x20]; u8 x40[0x20]; u8 x60[0x120]; u8 x180[0x40]; } Rec_Save_InitNewGame_1_001AA760;
typedef struct { u8 pad0[0xE]; u8 xE; u8 xF; u8 pad10[0xA0 - 0x10]; u32 xA0[0x40]; } Sv;
typedef SaveRec Rec_Save_BuildGame_1_001AAAE0;
typedef struct { u8 pad0[0x60]; s16 x60[16]; u8 pad80[0x1C0 - 0x80]; } Grp;
typedef struct {
    Rec_Save_BuildGame_1_001AAAE0 r0;
    u8 pad20[0xF];
    u8 x2F;
    u8 pad30[0x10C0 - 0x30];
    Rec_Save_BuildGame_1_001AAAE0 r1;
    Grp g[0x2A];
    u8 pad5A60[0x5AA0 - 0x5A60];
    Rec_Save_BuildGame_1_001AAAE0 r2;
    u8 pad5AC0[0x5B40 - 0x5AC0];
    Rec_Save_BuildGame_1_001AAAE0 r3;
    u8 pad5B60[0x5BE0 - 0x5B60];
    Rec_Save_BuildGame_1_001AAAE0 r4;
    u8 pad5C00[0x7C00 - 0x5C00];
    Rec_Save_BuildGame_1_001AAAE0 r5;
} Big_Save_BuildGame_1_001AAAE0;
typedef SaveRec Rec_Save_BuildOptions_1_001AB0A0;
typedef struct { Rec_Save_BuildOptions_1_001AB0A0 r0; u8 x20[0x10]; Rec_Save_BuildOptions_1_001AB0A0 r1; u8 pad[0x80]; Rec_Save_BuildOptions_1_001AB0A0 r2; } Big_Save_BuildOptions_1_001AB0A0;
extern PlayerData *gPlayerData_00201DC0;
extern Rec_Save_InitNewGame_1_001AA760 *gSaveByteSdata_00201DC4;
u8 Save_GetByte2E_0_001AA740(void);
void Save_InitNewGame_1_001AA760(void);
void Save_BuildGame_1_001AAAE0(Big_Save_BuildGame_1_001AAAE0 *b);
void Save_BuildOptions_1_001AB0A0(Big_Save_BuildOptions_1_001AB0A0 *b);
Sv* PlayerData_Get_2_001C9BA0(void);
void memset(void *, s32, s32);

/* Save_GetByte2E_0_001AA740 */
u8 Save_GetByte2E_0_001AA740(void) {
    return gPlayerData_00201DC0->x2E;
}

/* Save_GetByte2F_0_001AA750 */
u8 Save_GetByte2F_0_001AA750(void) {
    return gPlayerData_00201DC0->x2F;
}

/* Save_InitNewGame_1_001AA760 */
#define gPlayerData_00201DC0 gPlayerData_00201DC0__as_Save_InitNewGame_1_001AA760
extern W *gPlayerData_00201DC0__as_Save_InitNewGame_1_001AA760;
static inline Slot *slot(s16 id) {
    Slot *s;
    if (0 > id || id >= 0x400) {
        s = NULL;
    } else {
        s = &gPlayerData_00201DC0->slot[id];
    }
    return s;
}

void Save_InitNewGame_1_001AA760(void) {
    Sv *sv;
    s32 i;
    sv = PlayerData_Get_2_001C9BA0();
    for (i = 0; i < 0x2A; i++) {
        memset(gSaveByteSdata_00201DC4[i].x0, 0, 0x20);
        memset(gSaveByteSdata_00201DC4[i].x20, 0, 0x20);
        memset(gSaveByteSdata_00201DC4[i].x40, 0, 8);
        memset(gSaveByteSdata_00201DC4[i].x60, 0, 0x120);
        memset(gSaveByteSdata_00201DC4[i].x180, 0, 0x40);
    }
    memset(&gSaveByteSdata_00201DC4[0x2A], 0, 0x20);
    gPlayerData_00201DC0->x2E = 1;
    gPlayerData_00201DC0->x2F = 10;
    for (i = 0x1F; i <= 0x31; i++) {
        memset(&sv->xA0[i], 0, 4);
        memset(slot(i), 0, 8);
    }
    for (i = 3; i <= 0xB; i++) {
        if ((u32)(i - 4) > 1) {
            Inventory_AddItem_1_001A95A0(i, 10);
        }
    }
    Inventory_AddItem_1_001A95A0(0x14, 5);
    Inventory_AddItem_1_001A95A0(0x15, 0x14);
    Inventory_AddItem_1_001A95A0(0x16, 5);
    Inventory_AddItem_1_001A95A0(0x17, 0x1E);
    for (i = 0x3D; i <= 0x45; i++) {
        if (i == 0x42 || i == 0x43) {
            Inventory_AddItem_1_001A95A0(i, 0x28);
        } else {
            Inventory_AddItem_1_001A95A0(i, 5);
        }
    }
    Inventory_AddItem_1_001A95A0(0x6A, 1);
    Inventory_AddItem_1_001A95A0(0x7B, 1);
    Inventory_AddItem_1_001A95A0(0xE0, 1);
    Inventory_AddItem_1_001A95A0(0xED, 1);
    Inventory_AddItem_1_001A95A0(0xF5, 1);
    Inventory_AddItem_1_001A95A0(0x133, 1);
    Inventory_AddItem_1_001A95A0(0x148, 1);
    Inventory_AddItem_1_001A95A0(0x151, 1);
    Inventory_AddItem_1_001A95A0(0x1A1, 1);
    Inventory_AddItem_1_001A95A0(0x1FA, 1);
    Inventory_AddItem_1_001A95A0(0x25B, 1);
    Inventory_AddItem_1_001A95A0(0x25D, 1);
    Inventory_AddItem_1_001A95A0(0x2D6, 1);
    Inventory_AddItem_1_001A95A0(0x2DF, 1);
    Inventory_AddItem_1_001A95A0(0x2FF, 1);
    Inventory_AddItem_1_001A95A0(0x300, 1);
    Inventory_AddItem_1_001A95A0(0x323, 1);
    Inventory_AddItem_1_001A95A0(0x32F, 1);
    Inventory_AddItem_1_001A95A0(0x331, 1);
    Inventory_AddItem_1_001A95A0(0x33F, 1);
    Inventory_AddItem_1_001A95A0(0x347, 1);
    Inventory_AddItem_1_001A95A0(0x355, 1);
    Inventory_AddItem_1_001A95A0(0x369, 1);
    Inventory_AddItem_1_001A95A0(0x392, 1);
    Inventory_AddItem_1_001A95A0(0x397, 1);
    Inventory_AddItem_1_001A95A0(0x39C, 1);
    Inventory_AddItem_1_001A95A0(0x3A9, 1);
    Inventory_AddItem_1_001A95A0(0x3C6, 1);
    Inventory_AddItem_1_001A95A0(0x3CC, 1);
    sv->xE = 1;
    sv->xF = 10;
}
#undef gPlayerData_00201DC0

/* Save_BuildGame_1_001AAAE0 */
#define FCC(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline void init_Save_BuildGame_1_001AAAE0(Rec_Save_BuildGame_1_001AAAE0 *p, s8 *s, u32 x4, u32 x10, u32 x14) {
    p->tag = FCC(s);
    p->x4 = x4;
    p->a = 0x43;
    p->b = 0;
    p->xC = 1;
    p->xE = 0;
    p->x10 = x10;
    p->x14 = x14;
    p->x18 = 0;
    p->x1C = 0;
}

void Save_BuildGame_1_001AAAE0(Big_Save_BuildGame_1_001AAAE0 *b) {
    s32 i;
    s32 j;

    memset(b, 0, 0x7C20);
    for (i = 0; i < 0x2A; i++) {
        for (j = 0; j < 16; j++) {
            b->g[i].x60[j] = -1;
        }
    }
    b->x2F = 0xFF;
    Inventory_AddItem_1_001A95A0(0x3, 1);
    Inventory_AddItem_1_001A95A0(0x4, 7);
    Inventory_AddItem_1_001A95A0(0x5, 5);
    Inventory_AddItem_1_001A95A0(0x6, 5);
    Inventory_AddItem_1_001A95A0(0x14, 2);
    Inventory_AddItem_1_001A95A0(0x3F, 2);
    Inventory_AddItem_1_001A95A0(0x40, 3);
    Inventory_AddItem_1_001A95A0(0x41, 3);
    Inventory_AddItem_1_001A95A0(0x65, 1);
    Inventory_AddItem_1_001A95A0(0x6B, 1);
    Inventory_AddItem_1_001A95A0(0x6E, 1);
    Inventory_AddItem_1_001A95A0(0x71, 1);
    Inventory_AddItem_1_001A95A0(0x82, 1);
    Inventory_AddItem_1_001A95A0(0x90, 1);
    Inventory_AddItem_1_001A95A0(0xC8, 1);
    Inventory_AddItem_1_001A95A0(0xD2, 1);
    Inventory_AddItem_1_001A95A0(0xEB, 1);
    Inventory_AddItem_1_001A95A0(0xEE, 1);
    Inventory_AddItem_1_001A95A0(0xF0, 1);
    Inventory_AddItem_1_001A95A0(0x107, 1);
    Inventory_AddItem_1_001A95A0(0x12C, 1);
    Inventory_AddItem_1_001A95A0(0x130, 1);
    Inventory_AddItem_1_001A95A0(0x136, 1);
    Inventory_AddItem_1_001A95A0(0x13F, 1);
    Inventory_AddItem_1_001A95A0(0x155, 1);
    Inventory_AddItem_1_001A95A0(0x158, 1);
    Inventory_AddItem_1_001A95A0(0x190, 1);
    Inventory_AddItem_1_001A95A0(0x1A2, 1);
    Inventory_AddItem_1_001A95A0(0x1B9, 1);
    Inventory_AddItem_1_001A95A0(0x320, 1);
    Inventory_AddItem_1_001A95A0(0x324, 1);
    Inventory_AddItem_1_001A95A0(0x325, 1);
    Inventory_AddItem_1_001A95A0(0x328, 1);
    Inventory_AddItem_1_001A95A0(0x33A, 1);
    Inventory_AddItem_1_001A95A0(0x35F, 1);
    Inventory_AddItem_1_001A95A0(0x3DA, 1);
    Inventory_AddItem_1_001A95A0(0x3E0, 1);
    Inventory_AddItem_1_001A95A0(0x3E2, 1);
    Inventory_AddItem_1_001A95A0(0x3E5, 1);
    Inventory_AddItem_1_001A95A0(0x38E, 1);
    Inventory_AddItem_1_001A95A0(0x36C, 1);
    Inventory_AddItem_1_001A95A0(0x36F, 1);
    Inventory_AddItem_1_001A95A0(0x375, 1);
    Inventory_AddItem_1_001A95A0(0x380, 1);
    Inventory_AddItem_1_001A95A0(0x3B7, 1);
    Inventory_AddItem_1_001A95A0(0x3C7, 1);
    Inventory_AddItem_1_001A95A0(0x3C9, 1);
    init_Save_BuildGame_1_001AAAE0(&b->r0, gSaveParseRodata_001FD9A0, 0x10C0, 0x10B0, 0x10A0);
    init_Save_BuildGame_1_001AAAE0(&b->r1, gSaveParseRodata_001FD9A8, 0x49E0, 0x49D0, 0x49C0);
    init_Save_BuildGame_1_001AAAE0(&b->r2, gSaveParseRodata_001FD9B0, 0xA0, 0x90, 0x80);
    init_Save_BuildGame_1_001AAAE0(&b->r3, gSaveParseRodata_001FD9B8, 0xA0, 0x90, 0x80);
    init_Save_BuildGame_1_001AAAE0(&b->r4, gSaveParseRodata_001FD9C0, 0x2020, 0x2010, 0x2000);
    init_Save_BuildGame_1_001AAAE0(&b->r5, gSaveParseRodata_001FD988, 0x20, 0x10, 0);
}

/* Save_BuildOptions_1_001AB0A0 */
#define FCC(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline void init_Save_BuildOptions_1_001AB0A0(Rec_Save_BuildOptions_1_001AB0A0 *p, s8 *s, u32 x4, u32 x10, u32 x14) {
    p->tag = FCC(s);
    p->x4 = x4;
    p->a = 0x43;
    p->b = 0;
    p->xC = 1;
    p->xE = 0;
    p->x10 = x10;
    p->x14 = x14;
    p->x18 = 0;
    p->x1C = 0;
}

void Save_BuildOptions_1_001AB0A0(Big_Save_BuildOptions_1_001AB0A0 *b) {
    memset(b, 0, 0xF0);
    b->x20[0] = 0x20;
    b->x20[1] = 1;
    b->x20[2] = 0;
    b->x20[3] = 1;
    b->x20[4] = 0x40;
    b->x20[5] = 0x40;
    b->x20[6] = 0x40;
    b->x20[7] = 0;
    b->x20[8] = 1;
    b->x20[9] = 1;
    init_Save_BuildOptions_1_001AB0A0(&b->r0, gSaveParseRodata_001FD990, 0x30, 0x20, 0x10);
    init_Save_BuildOptions_1_001AB0A0(&b->r1, gSaveParseRodata_001FD998, 0xA0, 0x90, 0x80);
    init_Save_BuildOptions_1_001AB0A0(&b->r2, gSaveParseRodata_001FD988, 0x20, 0x10, 0);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 gSaveByteBss_004A5A60[];
/* data twins (src/game/data/sdata.c): gSaveByteSdata_00201DC4 */
Rec_Save_InitNewGame_1_001AA760 *gSaveByteSdata_00201DC4 = (Rec_Save_InitNewGame_1_001AA760 *)gSaveByteBss_004A5A60;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/pad_get_connected_bss.c): gSaveByteBss_004A5A60 */
u8 gSaveByteBss_004A5A60[0x49e0];
#endif
