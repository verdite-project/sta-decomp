#include "m2c.h"
#include "common.h"
#include "game/player.h"
typedef struct { u8 pad0[0x22]; u8 k[2]; u8 v[2]; u8 pad2[0x90-0x26]; } E_Player_GetStat_2_001CD450;
typedef struct { s16 x0; s16 x2; s16 x4; s16 x6; } S9BA0;
typedef struct { u8 pad[0x418]; u16 max; u16 hp; } C;
typedef struct { u8 pad[0x418]; u16 x418; u16 x41A; } P_Player_GetStat_2_001CD450;
typedef struct { s16 x0; s16 max; s16 x4; s16 cur; u8 pad8[0x28]; u32 a30; u8 pad34[0xC]; u32 a40; u8 pad44[0xC]; s32 b50; u8 pad54[0xC]; s32 b60; } B_Player_GetStat_2_001CD450;
typedef struct { u8 pad[0x30]; u32 x30[8]; s32 x50[8]; } P_PlayerData_GetStatusTimer_0_001CE200;
typedef struct { char pad[0x30]; s32 a[8]; s32 b[7]; } T_PlayerData_ClearStatus_0_001CE270;
typedef struct { u32 t:24; u32 h:8; } T_PlayerData_TickStatus_0_001CE2D0;
typedef struct { s8 pad[0x30]; T_PlayerData_TickStatus_0_001CE2D0 t[7]; s8 pad2[0x50 - 0x4C]; s32 c[7]; } B_PlayerData_GetStatusTimer_0_001CE200;
typedef struct { u8 pad[0x42]; u16 v; u8 pad2[0x90-0x44]; } E_Player_ApplyEquipVisualA_0_001CE370;
typedef struct { u8 pad[0x374]; f32 f; u8 pad2[0x395-0x378]; s8 max; u8 p3; s8 cnt; u8 p4[2]; s16 timer; u8 p5[0x460-0x39C]; u8 sub[0x10]; } O_Player_ApplyEquipVisualA_0_001CE370;
typedef struct { u8 pad0[0x394]; s8 x394; u8 pad1; s8 x396; u8 pad2; s16 x398; u8 pad3[2]; u8 x39C; } Obj_Player_ApplyEquipVisualB_0_001CE4B0;
typedef struct { u8 pad0[0x80]; s16 x80[2]; u8 pad1[0x10]; u8 x94; } V_Player_ApplyEquipVisualB_0_001CE4B0;
typedef struct { u8 pad0[4]; u16 x4; u8 pad1[0x8A]; } E_Player_ApplyEquipVisualB_0_001CE4B0;
typedef struct { u8 pad[0x40]; u16 on; u16 v; u8 pad2[0x90-0x44]; } E_Player_UpdateEquipModelA_1_001CE660;
typedef struct { u8 pad[0x395]; s8 max; u8 p3; s8 cnt; u8 p4[2]; s16 timer; u8 p5[0x460-0x39C]; u8 sub[0x10]; } O_Player_UpdateEquipModelA_1_001CE660;
typedef struct { u8 pad0[0x394]; s8 x394; u8 pad1; s8 x396; u8 pad2; s16 x398; } Obj_Player_UpdateEquipModel_0_001CE7D0;
typedef struct { u8 pad0[0x80]; s16 x80; s16 x82; u8 pad1[0x10]; u8 x94; u8 pad2[0xB]; u8 col[10][4]; } V_Player_UpdateEquipModel_0_001CE7D0;
typedef struct { u8 pad0[4]; u16 x4; u8 pad1[0x1A]; u16 x20; u8 pad2[0x1D]; u8 x3F; u8 pad3[0x50]; } E_Player_UpdateEquipModel_0_001CE7D0;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { s16 x0; s16 x2; s16 x4; } S_Player_GetStat_2_001CD450;
typedef struct { u8 pad[0x3A2]; Flags8 x3A2; u8 pad3A3[0x7B]; s16 x41E; } O_Player_AddExp_0_001CEAA0;
typedef struct { char pad[0x70]; u16 t[6]; } T;
typedef struct { u8 x0, x1, x2, x3; } BE;
typedef struct { s8 pad[0x70]; u16 x70[8]; s16 x80[10]; u8 x94; s8 pad95[0xA0 - 0x95]; BE e[1]; } B;
typedef struct { u8 a, b, c, d; } C4;
typedef struct {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    u8 pad8[0x38];
    u32 x40;
    u8 pad44[0x1C];
    s32 x60;
    u8 pad64[0xC];
    u16 x70[8];
    s16 x80[10];
    u8 x94_;
    u8 pad95[0xB];
    C4 col[1024];
} S_Player_CalcAttack_1_001CEBF0;
typedef struct {
    u8 pad[0x39C];
    u8 x39C;
    u8 pad39D[0x418 - 0x39D];
    s16 x418;
    u16 x41A;
    u8 pad41C[0x44];
    u16 x460[8];
    u16 x470[8];
    u8 x480[0x20];
    u8 x4A0[0x20];
} Q;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x1A]; u16 x20; u8 pad22[0x6E]; } E_Player_CalcAttack_1_001CEBF0;
extern u32 gGameMainSbss_00201E94;
extern u8 D_00222A54[];
s32 Player_GetStat_2_001CD450(s32 a0, u8 *out, s32 a2, s32 a3);
s32 Player_GetLevelInfo_0_001CD980(u8 *out, s8 *lv);
s32 Player_GetWeight_1_001CDEC0(void);
u32 PlayerData_GetStatusTimer_0_001CE200(s32 x);
void Player_ApplyEquipVisualA_0_001CE370(O_Player_ApplyEquipVisualA_0_001CE370 *arg0);
void Player_ApplyEquipVisualB_0_001CE4B0(Obj_Player_ApplyEquipVisualB_0_001CE4B0 *a0);
void Player_UpdateEquipModelA_1_001CE660(O_Player_UpdateEquipModelA_1_001CE660 *arg0, s32 arg1);
void Player_UpdateEquipModel_0_001CE7D0(Obj_Player_UpdateEquipModel_0_001CE7D0 *a0, s32 a1);
void Player_CalcAttack_1_001CEBF0(u16 *p, s32 a1, s32 a2);
void Player_RecalcStats_1_001CEDC0(s32 arg);
void Player_CalcStatsFor_0_001CF480(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
S9BA0* PlayerData_Get_2_001C9BA0(void);
u8* Item_GetTable_1_001AFC90(void);
void Player_AddStatus_1_001C88E0(s32, s32, s32);
C* Player_GetBodyState_1_001C9B60(void);
s32* PlayerData_Get_2_001C9BA0__as_Player_GetLevelInfo_0_001CD980(void);
P_Player_GetStat_2_001CD450* Player_GetBodyState_1_001C9B60__as_Player_GetWeight_1_001CDEC0(void);
B_Player_GetStat_2_001CD450* PlayerData_Get_2_001C9BA0__as_Player_UpdateMp_1_001CDF80(void);
T_PlayerData_ClearStatus_0_001CE270* PlayerData_Get_2_001C9BA0__as_PlayerData_ClearStatus_0_001CE270(void);
B_PlayerData_GetStatusTimer_0_001CE200* PlayerData_Get_2_001C9BA0__as_PlayerData_TickStatus_0_001CE2D0(void);
P_PlayerData_GetStatusTimer_0_001CE200* PlayerData_Get_2_001C9BA0__as_PlayerData_GetStatusTimer_0_001CE200(void);
s32 Game_GetBusy_0_0012C020(void);
void Menu_SetSubMode_0_0018A330(s32);
u32 Rand_Next_3_0015ED20(void);
void Snd_PlaySe_3_00131600(s32, s32);
V_Player_ApplyEquipVisualB_0_001CE4B0* PlayerData_Get_2_001C9BA0__as_Player_ApplyEquipVisualB_0_001CE4B0(void);
E_Player_ApplyEquipVisualB_0_001CE4B0* Item_GetTable_1_001AFC90__as_Player_ApplyEquipVisualB_0_001CE4B0(void);
E_Player_UpdateEquipModelA_1_001CE660* Item_GetTable_1_001AFC90__as_Player_UpdateEquipModelA_1_001CE660(void);
V_Player_UpdateEquipModel_0_001CE7D0* PlayerData_Get_2_001C9BA0__as_Player_UpdateEquipModel_0_001CE7D0(void);
E_Player_UpdateEquipModel_0_001CE7D0* Item_GetTable_1_001AFC90__as_Player_UpdateEquipModel_0_001CE7D0(void);
s32 Player_GetBodyState_1_001C9B60__as_Player_RefreshEquipModel_0_001CEA50();
s32 Player_UpdateEquipModelA_1_001CE660__as_Player_RefreshEquipModel_0_001CEA50();
s32 Player_UpdateEquipModel_0_001CE7D0__as_Player_RefreshEquipModel_0_001CEA50();
S_Player_GetStat_2_001CD450* PlayerData_Get_2_001C9BA0__as_Player_AddExp_0_001CEAA0(void);
s8* PlayerData_Get_2_001C9BA0__as_Player_ApplyEquipVisualA_0_001CE370(void);
E_Player_ApplyEquipVisualA_0_001CE370* Item_GetTable_1_001AFC90__as_Player_ApplyEquipVisualA_0_001CE370(void);
O_Player_AddExp_0_001CEAA0* Player_GetBodyState_1_001C9B60__as_Player_ApplyEquipVisualA_0_001CE370(void);
T* PlayerData_Get_2_001C9BA0__as_PlayerData_ResetCounters_0_001CEBA0(void);
void memset(void *, s32, s32);
void Stats_CalcAttack_0_001CF510(u16 *, s32, s8 *, s16 *, BE *, s32, s32);
void Stats_CalcBase_0_001D08E0(u16 *, u8 *, s16 *, C4 *);
void Stats_CalcDefense_0_001D0000(u16 *, u8 *, u16 *, s16 *, C4 *, s32);
S_Player_CalcAttack_1_001CEBF0* PlayerData_Get_2_001C9BA0__as_Player_RecalcStats_1_001CEDC0(void);
Q* Player_GetBodyState_1_001C9B60__as_Player_RecalcStats_1_001CEDC0(void);
void Stats_CalcBase_0_001D08E0__as_Player_CalcStatsFor_0_001CF480(s32 a, s32 b, s32 e, s32 f);
void Stats_CalcDefense_0_001D0000__as_Player_CalcStatsFor_0_001CF480(s32 c, s32 d, s32 a, s32 e, s32 f, s32 g);

/* Player_GetStat_2_001CD450 */
/* Player_GetStat_2_001CD450 */
/* Player_GetStat_2_001CD450 */
/* Player_GetStat_2_001CD450 */
/* Player_GetStat_2_001CD450 */
s32 Player_GetStat_2_001CD450(s32 a0, u8 *out, s32 a2, s32 a3) {
    u8 *p = (u8 *)PlayerData_Get_2_001C9BA0();
    E_Player_GetStat_2_001CD450 *base = (E_Player_GetStat_2_001CD450 *)Item_GetTable_1_001AFC90();
    s16 idx;
    s16 *slots;
    s32 found;
    u8 val;
    s32 i, j;
    found = 0;
    val = a3 ? 0 : 0xFF;
    slots = (s16 *)(p + 0x80);
    if (a2) {
        idx = slots[p[0x94] & 1];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
        if (out) *out = val;
        return found;
    }
    for (i = 0; i < 2; i++) {
        idx = slots[i];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
    }
    for (i = 2; i < 9; i++) {
        idx = slots[i];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
    }
    if (out) *out = val;
    return found;
}

/* Player_UpdateRegen_1_001CD6C0 */
void Player_UpdateRegen_1_001CD6C0(void) {
    u8 c;
    S9BA0 *p;

    if (Player_GetStat_2_001CD450(8, &c, 0, 0) && c && gGameMainSbss_00201E94 % c == 0) {
        Player_AddExp_0_001CEAA0(1);
    }
    if (Player_GetStat_2_001CD450(9, &c, 0, 0) && c && gGameMainSbss_00201E94 % c == 0) {
        Player_AddExp_0_001CEAA0(-1);
    }
    if (Player_GetStat_2_001CD450(0xB, &c, 0, 0) && c && gGameMainSbss_00201E94 % c == 0) {
        p = PlayerData_Get_2_001C9BA0();
        p->x6++;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (Player_GetStat_2_001CD450(0xC, &c, 0, 0) && c && gGameMainSbss_00201E94 % c == 0) {
        p = PlayerData_Get_2_001C9BA0();
        p->x6--;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (Player_GetStat_2_001CD450(1, NULL, 0, 1)) Player_AddStatus_1_001C88E0(0, 1, 0);
    if (Player_GetStat_2_001CD450(2, NULL, 0, 1)) Player_AddStatus_1_001C88E0(1, 1, 0);
    if (Player_GetStat_2_001CD450(3, NULL, 0, 1)) Player_AddStatus_1_001C88E0(2, 1, 0);
    if (Player_GetStat_2_001CD450(4, NULL, 0, 1)) Player_AddStatus_1_001C88E0(4, 1, 0);
    if (Player_GetStat_2_001CD450(5, NULL, 0, 1)) Player_AddStatus_1_001C88E0(3, 1, 0);
    if (Player_GetStat_2_001CD450(6, NULL, 0, 1)) Player_AddStatus_1_001C88E0(5, 1, 0);
}

/* Player_GetLevelInfo_0_001CD980 */
static inline u32 lvl(s32 k) {
    s32 *b = PlayerData_Get_2_001C9BA0__as_Player_GetLevelInfo_0_001CD980();
    if (b[k + 8] == 0 && b[k] != 0) {
        return (u32)b[k] >> 24;
    }
    return 0;
}
static inline s32 hpState_Player_GetLevelInfo_0_001CD980(void) {
    C *c = Player_GetBodyState_1_001C9B60();
    u16 hp;
    u16 max;
    if (c == NULL) {
        return 0;
    }
    hp = c->hp;
    max = c->max;
    if (hp < max) {
        if (!(100.0f * (f32)(max - hp) / (f32)(u32)hp < 10.0f)) {
            return 2;
        }
        return 1;
    }
    return 0;
}

s32 Player_GetLevelInfo_0_001CD980(u8 *out, s8 *lv) {
    if (out == NULL || lv == NULL) return 0;
    *lv = lvl(13);
    if (*lv >= 2) { *out = 1; return 1; }
    *lv = lvl(12);
    if (*lv >= 2) { *out = 0; return 1; }
    *lv = lvl(16);
    if (*lv >= 2) { *out = 4; return 1; }
    *lv = lvl(17);
    if (*lv >= 2) { *out = 5; return 1; }
    *lv = lvl(15);
    if (*lv >= 2) { *out = 3; return 1; }
    if (!(D_00222A54[0] & 1)) {
        *lv = hpState_Player_GetLevelInfo_0_001CD980();
    if (*lv >= 2) { *out = 7; return 1; }
    }
    *lv = lvl(13);
    if (*lv > 0) { *out = 1; return 1; }
    *lv = lvl(12);
    if (*lv > 0) { *out = 0; return 1; }
    *lv = lvl(16);
    if (*lv > 0) { *out = 4; return 1; }
    *lv = lvl(17);
    if (*lv > 0) { *out = 5; return 1; }
    *lv = lvl(15);
    if (*lv > 0) { *out = 3; return 1; }
    if (!(D_00222A54[0] & 1)) {
        *lv = hpState_Player_GetLevelInfo_0_001CD980();
    if (*lv > 0) { *out = 7; return 1; }
    }
    return 0;
}

/* Player_GetWeight_1_001CDEC0 */
static inline f32 u2f_Player_GetStat_2_001CD450(u32 x) { return x; }
s32 Player_GetWeight_1_001CDEC0(void) {
    P_Player_GetStat_2_001CD450 *p = Player_GetBodyState_1_001C9B60__as_Player_GetWeight_1_001CDEC0();
    u16 a, b;
    if (p == NULL) return 0;
    a = p->x41A;
    b = p->x418;
    if (a < b) {
        if (100.0f * (s32)(b - a) / u2f_Player_GetStat_2_001CD450(a) >= 10.0f) return 2; return 1;
    }
    return 0;
}

/* Player_UpdateMp_1_001CDF80 */
static inline u32 lvlA(void) {
    B_Player_GetStat_2_001CD450 *b = PlayerData_Get_2_001C9BA0__as_Player_UpdateMp_1_001CDF80();
    if (b->b50 == 0 && b->a30 != 0) {
        return b->a30 >> 24;
    }
    return 0;
}
static inline u32 lvlB(void) {
    B_Player_GetStat_2_001CD450 *b = PlayerData_Get_2_001C9BA0__as_Player_UpdateMp_1_001CDF80();
    if (b->b60 == 0 && b->a40 != 0) {
        return b->a40 >> 24;
    }
    return 0;
}
static inline s32 hpState_Player_UpdateMp_1_001CDF80(void) {
    C *c = Player_GetBodyState_1_001C9B60();
    u16 hp;
    u16 max;
    if (c == NULL) {
        return 0;
    }
    hp = c->hp;
    max = c->max;
    if (hp < max) {
        if (!(100.0f * (f32)(max - hp) / (f32)(u32)hp < 10.0f)) {
            return 2;
        }
        return 1;
    }
    return 0;
}

void Player_UpdateMp_1_001CDF80(void) {
    C *r;
    s16 n;
    s16 d;
    B_Player_GetStat_2_001CD450 *b;

    r = Player_GetBodyState_1_001C9B60();
    n = 0;
    d = 0;
    if (gGameMainSbss_00201E94 % 30 == 0 && r != NULL) {
        switch (lvlA()) {
        case 1:
            n = 3;
            break;
        case 2:
            n = 6;
            break;
        }
        if ((s32)lvlB() >= 2) {
            n = (n <= 0) ? 1 : n;
            d = 1;
        }
        if (!(D_00222A54[0] & 1)) {
            switch (hpState_Player_UpdateMp_1_001CDF80()) {
            case 2:
                n = (n < 5) ? 5 : n;
                break;
            }
        }
        Player_AddExp_0_001CEAA0(-n);
        b = PlayerData_Get_2_001C9BA0__as_Player_UpdateMp_1_001CDF80();
        b->cur += (s16)-d;
        if (b->cur < 0) {
            b->cur = 0;
        }
        if (b->max < b->cur) {
            b->cur = b->max;
        }
    }
}

/* PlayerData_GetStatusTimer_0_001CE200 */

/* PlayerData_GetStatusTimer_0_001CE200 */
u32 PlayerData_GetStatusTimer_0_001CE200(s32 x) {
    P_PlayerData_GetStatusTimer_0_001CE200 *p = PlayerData_Get_2_001C9BA0__as_PlayerData_GetStatusTimer_0_001CE200();
    if (x < 0 || x >= 7) return 0;
    if (p->x50[x] == 0 && p->x30[x] != 0) return p->x30[x] >> 24;
    return 0;
}

/* PlayerData_ClearStatus_0_001CE270 */

void PlayerData_ClearStatus_0_001CE270(s32 i)
{
    T_PlayerData_ClearStatus_0_001CE270 *t = PlayerData_Get_2_001C9BA0__as_PlayerData_ClearStatus_0_001CE270();
    if (i < 0 || i >= 7)
        return;
    t->b[i] = 150;
    t->a[i] = 0;
}

/* PlayerData_TickStatus_0_001CE2D0 */
void PlayerData_TickStatus_0_001CE2D0(void) {
    B_PlayerData_GetStatusTimer_0_001CE200 *b = PlayerData_Get_2_001C9BA0__as_PlayerData_TickStatus_0_001CE2D0();
    T_PlayerData_TickStatus_0_001CE2D0 *t;
    s32 *c;
    u32 i;
    s32 *p;
    u32 j;
    u32 n;
    u32 w;
    c = b->c;
    t = b->t;
    i = 0;
    p = c;
    do {
        if (*p != 0) *p = *p - 1;
        i++;
        p++;
    } while (i < 7);
    j = 0;
    do {
        n = t->t; w = *(u32 *)t >> 24;
        if (n != 0) {
            n--;
            *(u32 *)t = n | (w << 24);
            if (n == 0) {
                *c = 150;
                *(u32 *)t = 0;
            }
        }
        j++;
        t++;
        c++;
    } while (j < 7);
}

/* Player_ApplyEquipVisualA_0_001CE370 */

/* Player_ApplyEquipVisualA_0_001CE370 */
void Player_ApplyEquipVisualA_0_001CE370(O_Player_ApplyEquipVisualA_0_001CE370 *arg0) {
    s8 *q;
    s8 *a;
    E_Player_ApplyEquipVisualA_0_001CE370 *b;
    E_Player_ApplyEquipVisualA_0_001CE370 *e;
    s16 idx;
    s16 t;
    u16 v;
    f32 x, y, z;

    q = arg0->sub;
    a = PlayerData_Get_2_001C9BA0__as_Player_ApplyEquipVisualA_0_001CE370();
    b = Item_GetTable_1_001AFC90__as_Player_ApplyEquipVisualA_0_001CE370();
    idx = M2C_FIELD(a, s16 *, 0x8C);
    if (idx != -1) { e = &b[idx]; if (arg0->cnt < arg0->max && arg0->f <= 0.0f) {
        if (arg0->timer > (s32)(30.0f * (0.03f * (f32)e->v - 0.00003f * (f32)(M2C_FIELD(q, u16 *, 0xA) * e->v)))) {
            arg0->cnt++;
            arg0->timer = 0;
        }
        arg0->timer++;
    } }
}

/* Player_ApplyEquipVisualB_0_001CE4B0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
static inline f32 u2f_Player_ApplyEquipVisualA_0_001CE370(u32 x) { return x; }
static inline s32 cls_Player_ApplyEquipVisualB_0_001CE4B0(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}

void Player_ApplyEquipVisualB_0_001CE4B0(Obj_Player_ApplyEquipVisualB_0_001CE4B0 *a0) {
    u16 *q = (u16 *)((u8 *)a0 + 0x460);
    V_Player_ApplyEquipVisualB_0_001CE4B0 *v;
    E_Player_ApplyEquipVisualB_0_001CE4B0 *t;
    s32 idx;
    u16 h;

    v = PlayerData_Get_2_001C9BA0__as_Player_ApplyEquipVisualB_0_001CE4B0();
    t = Item_GetTable_1_001AFC90__as_Player_ApplyEquipVisualB_0_001CE4B0();
    if (cls_Player_ApplyEquipVisualB_0_001CE4B0(a0->x39C) == 0) {
        idx = v->x80[v->x94 & 1];
        if (idx == -1 || idx == 0) {
            h = (u16)3;
        } else {
            h = t[idx].x4;
        }
        if (a0->x396 < a0->x394) {
            if (a0->x398 > (s32)((0.3f + 0.05f * h - 0.00004f * (q[3] * (u16)h)) * 30.0f)) {
                a0->x396++;
                a0->x398 = 0;
            }
            a0->x398++;
        }
    }
}

/* Player_UpdateEquipModelA_1_001CE660 */

void Player_UpdateEquipModelA_1_001CE660(O_Player_UpdateEquipModelA_1_001CE660 *arg0, s32 arg1) {
    s8 *q;
    s8 *a;
    E_Player_UpdateEquipModelA_1_001CE660 *b;
    E_Player_UpdateEquipModelA_1_001CE660 *e;
    s16 idx;
    u16 v;

    q = arg0->sub;
    a = PlayerData_Get_2_001C9BA0__as_Player_ApplyEquipVisualA_0_001CE370();
    b = Item_GetTable_1_001AFC90__as_Player_UpdateEquipModelA_1_001CE660();
    idx = M2C_FIELD(a, s16 *, 0x8C);
    if (idx == -1) {
        arg0->timer = 0;
        arg0->max = 0;
        arg0->cnt = 0;
        return;
    }
    e = &b[idx];
    if (e->on == 0) {
        arg0->timer = 0;
        arg0->max = 0;
        arg0->cnt = 0;
        return;
    }
    v = e->v;
    if (v >= 100) {
        arg0->max = 1;
    } else if (v >= 50) {
        arg0->max = 2;
    } else {
        arg0->max = 3;
    }
    arg0->max += (s8)(M2C_FIELD(q, u16 *, 0xE) / 300);
    if (arg0->max > 6) {
        arg0->max = 6;
    }
    if (arg1) {
        arg0->timer = 0;
        arg0->cnt = 0;
        return;
    }
    if (arg0->cnt < 0) {
        arg0->cnt = 0;
    }
    if (arg0->max < arg0->cnt) {
        arg0->cnt = arg0->max;
    }
}

/* Player_UpdateEquipModel_0_001CE7D0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
static inline s32 cls_Player_UpdateEquipModel_0_001CE7D0(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}

void Player_UpdateEquipModel_0_001CE7D0(Obj_Player_UpdateEquipModel_0_001CE7D0 *a0, s32 a1) {
    u16 *q = (u16 *)((u8 *)a0 + 0x460);
    V_Player_UpdateEquipModel_0_001CE7D0 *v;
    E_Player_UpdateEquipModel_0_001CE7D0 *t;
    E_Player_UpdateEquipModel_0_001CE7D0 *e;
    s32 idx;
    s32 m;
    u16 h;
    Col c;

    v = PlayerData_Get_2_001C9BA0__as_Player_UpdateEquipModel_0_001CE7D0();
    t = Item_GetTable_1_001AFC90__as_Player_UpdateEquipModel_0_001CE7D0();
    if (a1) {
        a0->x398 = 0;
    }
    idx = (v->x94 & 1) ? v->x82 : v->x80;
    if (idx == -1 || idx == 0) {
        a0->x394 = 1;
        if (a1) {
            a0->x396 = 0;
        } else {
            if (a0->x396 < 0) {
                a0->x396 = 0;
            }
            if (a0->x394 < a0->x396) {
                a0->x396 = a0->x394;
            }
        }
        return;
    }
    e = &t[idx];
    c = ((Col *)((u8 *)v + 0xA0))[idx];
    m = cls_Player_UpdateEquipModel_0_001CE7D0(e->x20);
    switch (m) {
    case 0:
        h = e->x4;
        if (h >= 30) {
            a0->x394 = 1;
        } else if (h >= 15) {
            a0->x394 = 2;
        } else {
            a0->x394 = 3;
        }
        a0->x394 += (s8)(q[1] / 300);
        if (a0->x394 > 6) {
            a0->x394 = 6;
        }
        if (a1) {
            a0->x396 = 0;
        } else {
            if (a0->x396 < 0) {
                a0->x396 = 0;
            }
            if (a0->x394 < a0->x396) {
                a0->x396 = a0->x394;
            }
        }
        break;
    case 1:
        a0->x394 = e->x3F;
        a0->x396 = c.a;
        break;
    case 2:
        a0->x394 = e->x3F;
        a0->x396 = 0;
        break;
    }
}

/* Player_RefreshEquipModel_0_001CEA50 */
void Player_RefreshEquipModel_0_001CEA50(s32 arg0) {
    s32 temp_2;

    temp_2 = Player_GetBodyState_1_001C9B60__as_Player_RefreshEquipModel_0_001CEA50();
    if (temp_2 != 0) {
        Player_UpdateEquipModel_0_001CE7D0__as_Player_RefreshEquipModel_0_001CEA50((void *) temp_2, arg0);
        Player_UpdateEquipModelA_1_001CE660__as_Player_RefreshEquipModel_0_001CEA50((void *) temp_2, arg0);
    }
}

/* Player_AddExp_0_001CEAA0 */

void Player_AddExp_0_001CEAA0(s32 d) {
    S_Player_GetStat_2_001CD450 *s;
    O_Player_AddExp_0_001CEAA0 *o;
    s = PlayerData_Get_2_001C9BA0__as_Player_AddExp_0_001CEAA0();
    o = Player_GetBodyState_1_001C9B60__as_Player_ApplyEquipVisualA_0_001CE370();
    if (o && s->x4 > 0 && !Game_GetBusy_0_0012C020()) {
        s->x4 += (s16)d;
        if (s->x4 < 0) s->x4 = 0;
        if (s->x0 < s->x4) s->x4 = s->x0;
        if (s->x4 <= 0) {
            Menu_SetSubMode_0_0018A330(0);
            Snd_PlaySe_3_00131600(Rand_Next_3_0015ED20() % 3 + 0x128, 0x7F);
            o->x41E = 0;
            o->x3A2.f.b4 = 1;
        }
    }
}

/* PlayerData_ResetCounters_0_001CEBA0 */

void PlayerData_ResetCounters_0_001CEBA0(void)
{
    T *t = PlayerData_Get_2_001C9BA0__as_PlayerData_ResetCounters_0_001CEBA0();
    s32 i;
    for (i = 0; i < 6; i++) {
        if (t->t[i])
            t->t[i]--;
    }
}

/* Player_CalcAttack_1_001CEBF0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Player_CalcAttack_1_001CEBF0
B* PlayerData_Get_2_001C9BA0__as_Player_CalcAttack_1_001CEBF0(void);
#define Player_GetBodyState_1_001C9B60 Player_GetBodyState_1_001C9B60__as_Player_CalcAttack_1_001CEBF0
s8* Player_GetBodyState_1_001C9B60__as_Player_CalcAttack_1_001CEBF0(void);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Player_CalcAttack_1_001CEBF0
E_Player_CalcAttack_1_001CEBF0* Item_GetTable_1_001AFC90__as_Player_CalcAttack_1_001CEBF0(void);

/* Player_CalcAttack_1_001CEBF0 */
static inline f32 u2f_Player_CalcAttack_1_001CEBF0(u32 x) { return x; }

void Player_CalcAttack_1_001CEBF0(u16 *p, s32 a1, s32 a2) {
    B *b;
    s8 *c;
    BE buf[10];
    s32 i;

    b = PlayerData_Get_2_001C9BA0();
    c = Player_GetBodyState_1_001C9B60();
    if (c == NULL) return;
    memset(buf, 0, 0x28);
    for (i = 0; i < 10; i++) {
        if (b->x80[i] != -1) buf[i] = b->e[b->x80[i]];
    }
    Stats_CalcAttack_0_001CF510(p, a1, c + 0x460, b->x80, buf, b->x94 & 1, a2);
    for (i = 0; i < 6; i++) {
        if (b->x70[i]) {
            p[i] += (u16)(0.5f * u2f_Player_CalcAttack_1_001CEBF0(p[i]));
            if ((s16)p[i] < 0) p[i] = 0;
            if ((s16)p[i] > 999) p[i] = 999;
        }
    }
}

/* Player_RecalcStats_1_001CEDC0 */
static inline f32 u2f_Player_RecalcStats_1_001CEDC0(u32 x) { return x; }
static inline s32 getid(s32 i) {
    S_Player_CalcAttack_1_001CEBF0 *r = PlayerData_Get_2_001C9BA0__as_Player_RecalcStats_1_001CEDC0();
    if (i >= 0 && i < 10) return r->x80[i];
    return -1;
}
static inline s32 pct(u16 *p, f32 k) { return (u32)(k * (f32)(u32)*p); }
static inline u32 fl(S_Player_CalcAttack_1_001CEBF0 *r) {
    if (r->x60 == 0 && r->x40 != 0) return r->x40 >> 24;
    return 0;
}

void Player_RecalcStats_1_001CEDC0(s32 arg) {
    S_Player_CalcAttack_1_001CEBF0 *s;
    Q *q;
    S_Player_CalcAttack_1_001CEBF0 *r;
    E_Player_CalcAttack_1_001CEBF0 *tbl;
    s32 i;
    s32 k;
    s32 sum;
    u32 n;
    s32 idx;
    s32 id;
    u16 v;
    u8 c;
    s16 *h;
    C4 buf[10];

    s = PlayerData_Get_2_001C9BA0__as_Player_RecalcStats_1_001CEDC0();
    q = Player_GetBodyState_1_001C9B60__as_Player_RecalcStats_1_001CEDC0();
    if (q == NULL) return;
    memset(buf, 0, 0x28);
    for (i = 0; i < 10; i++) {
        k = s->x80[i];
        if (k != -1) {
            buf[i] = s->col[k];
        }
    }
    Stats_CalcBase_0_001D08E0(q->x460, q->x4A0, s->x80, buf);
    h = s->x80;
    if ((h[2] == 0x84 || h[2] == 0x85) && h[3] == 0xEF && (h[4] == 0x14B || h[4] == 0x14C) &&
        (h[5] == 0x1B0 || h[5] == 0x1B1)) {
        for (i = 0; i < 8; i++) {
            q->x460[i] = *(volatile u16 *)&q->x460[i] + pct(&q->x460[i], 0.1f);
            if ((s16)q->x460[i] < 0) q->x460[i] = 0;
            if ((s16)q->x460[i] > 999) q->x460[i] = 999;
        }
    }
    r = PlayerData_Get_2_001C9BA0__as_Player_RecalcStats_1_001CEDC0();
    if (fl(r)) {
        q->x460[0] >>= 1;
        q->x460[1] >>= 1;
        q->x460[2] >>= 1;
        q->x460[3] >>= 1;
        q->x460[4] >>= 1;
        q->x460[5] >>= 1;
        q->x460[6] >>= 1;
        q->x460[7] >>= 1;
    }
    Stats_CalcDefense_0_001D0000(q->x470, q->x480, q->x460, s->x80, buf, arg);
    for (i = 0; i < 6; i++) {
        if (s->x70[i] != 0) {
            q->x470[i] = *(volatile u16 *)&q->x470[i] + pct(&q->x470[i], 0.5f);
            if ((s16)q->x470[i] < 0) q->x470[i] = 0;
            if ((s16)q->x470[i] > 999) q->x470[i] = 999;
        }
    }
    q->x41A = (u32)(500.0f + 0.04f * u2f_Player_RecalcStats_1_001CEDC0((u16)s->x0));
    r = PlayerData_Get_2_001C9BA0__as_Player_RecalcStats_1_001CEDC0();
    tbl = Item_GetTable_1_001AFC90();
    sum = 0;
    for (n = 0; n < 0x400; n++) {
        sum += r->col[n].c * tbl[n].x4;
    }
    if (Player_GetStat_2_001CD450(0xF, &c, 0, 1)) {
        sum -= sum * c / 100;
    }
    if (sum < 0) sum = 0;
    if (sum > 999) sum = 999;
    q->x418 = sum;
    v = q->x460[0] * 4 + 500 + (q->x460[1] + q->x460[2] + q->x460[3]) * 2;
    if ((s16)v < 0) v = 0;
    if ((s16)v > 9999) v = 9999;
    s->x0 = v;
    v = q->x460[4] * 4 + 500 + (q->x460[5] + q->x460[6] + q->x460[7]) * 2;
    if ((s16)v < 0) v = 0;
    if ((s16)v > 9999) v = 9999;
    s->x2 = v;
    if (s->x4 < 0) s->x4 = 0;
    if (s->x0 < s->x4) s->x4 = s->x0;
    if (s->x6 < 0) s->x6 = 0;
    if (s->x2 < s->x6) s->x6 = s->x2;
    id = getid(s->x94_ & 1);
    tbl = Item_GetTable_1_001AFC90();
    idx = (s16)id;
    q->x39C = (idx == -1) ? 0 : tbl[idx].x20;
}

/* Player_CalcStatsFor_0_001CF480 */

void Player_CalcStatsFor_0_001CF480(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
    Stats_CalcBase_0_001D08E0__as_Player_CalcStatsFor_0_001CF480(a, b, e, f);
    Stats_CalcDefense_0_001D0000__as_Player_CalcStatsFor_0_001CF480(c, d, a, e, f, g);
}
#undef PlayerData_Get_2_001C9BA0
#undef Player_GetBodyState_1_001C9B60
#undef Item_GetTable_1_001AFC90
