/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Player_UseItem_1_001CAEF0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
// NEAR: 173 of 676 positional (built 678, retail 676; prev 183). Everything up to case 2's second loop aligns except reg names
// (e = &base[id] wants addu s4,s5(id*0x90),s0 order; f26/e s-regs swapped). Length +2 = two nops: retail fills the
// 'if (ee->x0A == 1)' / '== 2' bne delay slots with 'addiu sN,ee,0x3C' (mx); here the block starts with lbu *mx which
// clobbers the x0A reg, so no fill. Loop2 counter j wants an s-reg (s4), x0A a1, k v1. Changes: i <= 6 (slti at), pa ptr.
#include "common.h"
typedef struct {
    u8 pad[0xA];
    u16 x0A;
    u8 pad0C[0x14];
    u16 x20;
    u16 x22;
    u16 x24;
    Flags8 x26;
    Flags8 x27;
    u8 x28;
    u8 x29;
    u8 pad2A[0x12];
    u8 x3C;
    u8 pad3D[0x53];
} E;
typedef struct { u8 a0, a1, a2, a3; } Inv;
typedef struct {
    s16 x0, x2, x4, x6;
    u8 pad8[0x28];
    u32 x30[6];
    u8 pad48[8];
    s32 x50[6];
    u8 pad68[8];
    s16 x70[8];
    s16 x80[8];
    u8 pad90[0x10];
    Inv inv[1];
} P;
void Player_GetBodyState_1_001C9B60(void);
P *PlayerData_Get_2_001C9BA0(void);
E *Item_GetTable_1_001AFC90(void);
s32 Door_CheckOpen_0_001B8F70(s16);
void Msg_ShowById_1_0018B0E0(s32);
void Msg_Close_1_0018B0C0(void);
void Inventory_ChangeCount_1_001CBED0(s16, s32, s32);
void Snd_PlaySe_3_00131600(s32, s32);
void Sfx_Spawn_2_00169B50(s32, s32, s32, s32);

static inline s32 two(E *e) {
    switch (e->x20) {
    case 2:
    case 4:
    case 6:
    case 9:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
        return 1;
    }
    return 0;
}

static inline u32 chk(s32 k) {
    P *p = PlayerData_Get_2_001C9BA0();
    if (p->x50[k] == 0 && p->x30[k] != 0) return p->x30[k] >> 24;
    return 0;
}

static inline void clr(s32 k) {
    P *p = PlayerData_Get_2_001C9BA0();
    p->x50[k] = 150;
    p->x30[k] = 0;
}

s16 Player_UseItem_1_001CAEF0(s16 id) {
    s16 *sl;
    u8 *ty;
    s32 r;
    P *pl;
    E *base;
    Flags8 *f26;
    E *e;
    E *ee;
    s32 i;
    s32 j;
    s32 k;
    Flags8 *f27;
    u8 *cnt;

    Player_GetBodyState_1_001C9B60();
    pl = PlayerData_Get_2_001C9BA0();
    base = Item_GetTable_1_001AFC90();
    if (id < 0 || id >= 0x400) return 0;
    e = &base[id];
    if (e->x0A != 0) return 0;
    f26 = &e->x26;
    if (!(f26->b & 1)) return 0;
    ty = &e->x29;
    if (*ty == 5) {
        if (pl->inv[id].a2 <= 0 && pl->inv[id].a3 <= 0) return 0;
    } else {
        if (pl->inv[id].a2 <= 0) return 0;
    }
    r = Door_CheckOpen_0_001B8F70(id);
    if (r != 0) return 1;
    switch (*ty) {
    case 3:
        if (base[id].x22 != 0 && pl->x4 < pl->x0) r |= 1;
        if (base[id].x24 != 0 && pl->x6 < pl->x2) r |= 2;
        if (f26->f.b1 && chk(0)) r |= 4;
        if (f26->f.b2 && chk(1)) r |= 4;
        if (f26->f.b3 && chk(2)) r |= 4;
        if (f26->f.b4 && chk(4)) r |= 4;
        if (f26->f.b5 && chk(3)) r |= 4;
        if (f26->f.b6 && chk(5)) r |= 4;
        if (r == 0) {
            Msg_ShowById_1_0018B0E0(200);
            return 1;
        }
        pl->x4 += (s16)base[id].x22;
        pl->x6 += (s16)base[id].x24;
        if (pl->x4 < 0) pl->x4 = 0;
        if (pl->x0 < pl->x4) pl->x4 = pl->x0;
        if (pl->x6 < 0) pl->x6 = 0;
        if (pl->x2 < pl->x6) pl->x6 = pl->x2;
        if (f26->f.b1) clr(0);
        if (f26->f.b2) clr(1);
        if (f26->f.b3) clr(2);
        if (f26->f.b4) clr(4);
        if (f26->f.b5) clr(3);
        if (f26->f.b6) clr(5);
        Inventory_ChangeCount_1_001CBED0(id, -1, 0);
        Msg_Close_1_0018B0C0();
        Snd_PlaySe_3_00131600(0x13C, 0x7F);
        for (i = 0; i < 3; i++) {
            if (r & (1 << i)) Sfx_Spawn_2_00169B50(i + 0x1EA, 0, 1, 0);
        }
        return 1;
    case 4:
        if (f26->f.b7) pl->x70[0] = 900;
        f27 = &e->x27;
        if (f27->f.b0) pl->x70[1] = 900;
        if (f27->f.b1) pl->x70[2] = 900;
        if (f27->f.b2) pl->x70[3] = 900;
        if (f27->f.b3) pl->x70[4] = 900;
        if (f27->f.b4) pl->x70[5] = 900;
        Inventory_ChangeCount_1_001CBED0(id, -1, 0);
        Msg_Close_1_0018B0C0();
        Snd_PlaySe_3_00131600(0x140, 0x7F);
        Sfx_Spawn_2_00169B50(0x1ED, 0, 1, 0);
        return 1;
    case 2:
        for (i = 0, sl = (s16 *)pl; i <= 6; i++, sl++) {
            k = sl[0x40];
            if (k == -1) continue;
            if (i == 1 && two(&base[k])) continue;
            ee = &base[k];
            if (ee->x0A == 1) {
                if (pl->inv[k].a0 < ee->x3C) r = 1;
            } else if (ee->x0A == 2) {
                if (pl->inv[k].a0 < ee->x3C) r = 1;
            }
        }
        if (r == 0) {
            Msg_ShowById_1_0018B0E0(200);
            return 1;
        }
        for (j = 0; j < 7; j++) {
            k = pl->x80[j];
            if (k == -1) continue;
            if (j == 1 && two(&base[k])) continue;
            ee = &base[k];
            if (ee->x0A == 1) {
                u8 *mx = &ee->x3C;
                s32 v = *mx * 50;
                u8 *pa = &pl->inv[k].a0;
                pl->inv[k].a0 += (u8)(v / 100);
                if (v % 100) (*pa)++;
                if (*mx < *pa) *pa = *mx;
                pl->inv[k].a1 = 0;
            } else if (ee->x0A == 2) {
                u8 *mx = &ee->x3C;
                s32 v = *mx * 50;
                u8 *pa = &pl->inv[k].a0;
                pl->inv[k].a0 += (u8)(v / 100);
                if (v % 100) (*pa)++;
                if (*mx < *pa) *pa = *mx;
                pl->inv[k].a1 = 0;
            }
        }
        Inventory_ChangeCount_1_001CBED0(id, -1, 0);
        Msg_Close_1_0018B0C0();
        Snd_PlaySe_3_00131600(0x13C, 0x7F);
        Sfx_Spawn_2_00169B50(0x1EE, 0, 1, 0);
        return 1;
    }
    Msg_ShowById_1_0018B0E0(200);
    return r;
}
#else
INCLUDE_ASM(Player_UseItem_1_001CAEF0);
#endif
