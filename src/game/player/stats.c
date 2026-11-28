#include "m2c.h"
#include "common.h"
#include "game/player.h"
typedef struct { u8 pad[0x20]; u16 type; u8 pad22[8]; u8 b[6]; u16 v[6]; f32 f[0x15]; } E_Stats_CalcAttack_0_001CF510;
typedef struct { u8 pad[0x4A]; u16 v[6]; } E2;
typedef struct { u16 v[6]; f32 f; } R;
typedef struct { u8 pad[0x20]; u16 type; u8 pad22[8]; u8 b[6]; u16 v[6]; } E_Stats_CalcDefense_0_001D0000;
typedef struct { u16 v[6]; } A;
typedef struct { u16 v[8]; } B;
typedef struct { u8 pad[0x26]; u8 b[6]; u16 h[8]; u8 pad3C[0x54]; } E_Stats_CalcBase_0_001D08E0;
typedef struct { u8 v; u8 pad[3]; } B4;
typedef struct { char pad[8]; u16 a, b, c, d; } S_Stats_CalcMaxHp_0_001D10B0;
typedef struct { u16 a, b, c, d; } S_Stats_CalcMaxMp_0_001D1110;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x8A]; } E_Stats_CalcWeight_0_001D1170;
typedef struct { u8 pad[2]; u8 x2; u8 pad3; } C;
typedef struct { u8 pad[0xA0]; C c[1024]; } S_Stats_CalcWeight_0_001D1170;
extern E_Stats_CalcAttack_0_001CF510 D_004B5DD0[2];
extern E2 D_004B6130;
extern E_Stats_CalcDefense_0_001D0000 D_004B5E60;
extern E_Stats_CalcBase_0_001D08E0 D_004B5EF0[7];
void Stats_CalcAttack_0_001CF510(R *a0, s32 *a1, s32 a2, s16 *a3, u8 *t0, s32 sel, s32 k);
void Stats_CalcDefense_0_001D0000(u16 *a0, s32 *a1, s32 a2, s16 *a3, u8 *t0, u32 f);
void Stats_AddWeighted_1_001D0610(A *a, B *b);
void Stats_CalcBase_0_001D08E0(s16 *out, s32 *st, s16 *a, B4 *b);
u16 Stats_CalcMaxHp_0_001D10B0(S_Stats_CalcMaxHp_0_001D10B0 *s);
u16 Stats_CalcMaxMp_0_001D1110(S_Stats_CalcMaxMp_0_001D1110 *s);
void memset(void *, s32, s32);
void Item_GetStatBlock_0_001D1240(void *, s16, u8);
u8* PlayerData_Get_2_001C9BA0(void);
E_Stats_CalcWeight_0_001D1170* Item_GetTable_1_001AFC90(void);

/* Stats_CalcAttack_0_001CF510 */
#define Stats_AddWeighted_1_001D0610 Stats_AddWeighted_1_001D0610__as_Stats_CalcAttack_0_001CF510
void Stats_AddWeighted_1_001D0610__as_Stats_CalcAttack_0_001CF510(R *, s32);
static inline s32 isType_Stats_CalcAttack_0_001CF510(u16 t) {
    switch (t) {
    case 2: case 4: case 6: case 9: case 0xB: case 0xC: case 0xD: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13:
        return 1;
    }
    return 0;
}
static inline f32 u2f(u32 x) { return x; }
static inline void addv(R *a0, E_Stats_CalcAttack_0_001CF510 *e, f32 k) {
    a0->v[0] = a0->v[0] + (s32)(u32)(k * u2f(e->v[0]));
    a0->v[1] = a0->v[1] + (s32)(u32)(k * u2f(e->v[1]));
    a0->v[2] = a0->v[2] + (s32)(u32)(k * u2f(e->v[2]));
    a0->v[3] = a0->v[3] + (s32)(u32)(k * u2f(e->v[3]));
    a0->v[4] = a0->v[4] + (s32)(u32)(k * u2f(e->v[4]));
    a0->v[5] = a0->v[5] + (s32)(u32)(k * u2f(e->v[5]));
}

void Stats_CalcAttack_0_001CF510(R *a0, s32 *a1, s32 a2, s16 *a3, u8 *t0, s32 sel, s32 k) {
    E_Stats_CalcAttack_0_001CF510 *e;
    s32 t;
    memset(a0, 0, 0x10);
    memset(a1, 0, 0x20);
    Item_GetStatBlock_0_001D1240(&D_004B5DD0[0], a3[0], t0[0]);
    Item_GetStatBlock_0_001D1240(&D_004B5DD0[1], a3[1], t0[4]);
    Item_GetStatBlock_0_001D1240(&D_004B6130, a3[6], t0[0x18]);
    a0->f = D_004B5DD0[sel].f[k];
    addv(a0, &D_004B5DD0[sel], 1.0f);
    a1[0] += D_004B5DD0[sel].b[0];
    a1[1] += D_004B5DD0[sel].b[1];
    a1[2] += D_004B5DD0[sel].b[2];
    a1[3] += D_004B5DD0[sel].b[4];
    a1[4] += D_004B5DD0[sel].b[3];
    a1[5] += D_004B5DD0[sel].b[5];
    if (!isType_Stats_CalcAttack_0_001CF510(D_004B5DD0[sel].type)) {
        sel = !sel;
        addv(a0, &D_004B5DD0[sel], 0.1f);
    }
    if (a3[6] != -1) {
        t = D_004B6130.v[0]; a0->v[0] += t;
        t = D_004B6130.v[1]; a0->v[1] += t;
        t = D_004B6130.v[2]; a0->v[2] += t;
        t = D_004B6130.v[3]; a0->v[3] += t;
        t = D_004B6130.v[4]; a0->v[4] += t;
        t = D_004B6130.v[5]; a0->v[5] += t;
    }
    Stats_AddWeighted_1_001D0610(a0, a2);
    if ((s16)a1[0] < 0) a1[0] = 0;
    if ((s16)a1[0] > 100) a1[0] = 100;
    if ((s16)a1[1] < 0) a1[1] = 0;
    if ((s16)a1[1] > 100) a1[1] = 100;
    if ((s16)a1[2] < 0) a1[2] = 0;
    if ((s16)a1[2] > 100) a1[2] = 100;
    if ((s16)a1[3] < 0) a1[3] = 0;
    if ((s16)a1[3] > 100) a1[3] = 100;
    if ((s16)a1[4] < 0) a1[4] = 0;
    if ((s16)a1[4] > 100) a1[4] = 100;
    if ((s16)a1[5] < 0) a1[5] = 0;
    if ((s16)a1[5] > 100) a1[5] = 100;
}
#undef Stats_AddWeighted_1_001D0610

/* Stats_CalcDefense_0_001D0000 */
#define Stats_AddWeighted_1_001D0610 Stats_AddWeighted_1_001D0610__as_Stats_CalcDefense_0_001D0000
void Stats_AddWeighted_1_001D0610__as_Stats_CalcDefense_0_001D0000(u16 *, s32);
#define D_004B5DD0 D_004B5DD0__as_Stats_CalcDefense_0_001D0000
extern E_Stats_CalcDefense_0_001D0000 D_004B5DD0__as_Stats_CalcDefense_0_001D0000;
static inline s32 isType_Stats_CalcDefense_0_001D0000(u16 t) {
    switch (t) {
    case 2: case 4: case 6: case 9: case 0xB: case 0xC: case 0xD: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13:
        return 1;
    }
    return 0;
}

void Stats_CalcDefense_0_001D0000(u16 *a0, s32 *a1, s32 a2, s16 *a3, u8 *t0, u32 f) {
    s32 f1;
    s32 f2;
    s32 t;

    memset(a0, 0, 0x10);
    Item_GetStatBlock_0_001D1240(&D_004B5DD0, a3[0], t0[0]);
    Item_GetStatBlock_0_001D1240(&D_004B5E60, a3[1], t0[4]);
    Item_GetStatBlock_0_001D1240(&D_004B6130, a3[6], t0[0x18]);
    f1 = f & 1;
    if (f1) {
        t = D_004B5DD0.v[0]; a0[0] += t;
        t = D_004B5DD0.v[1]; a0[1] += t;
        t = D_004B5DD0.v[2]; a0[2] += t;
        t = D_004B5DD0.v[3]; a0[3] += t;
        t = D_004B5DD0.v[4]; a0[4] += t;
        t = D_004B5DD0.v[5]; a0[5] += t;
    }
    f2 = f & 2;
    if (f2) {
        t = D_004B5E60.v[0]; a0[0] += t;
        t = D_004B5E60.v[1]; a0[1] += t;
        t = D_004B5E60.v[2]; a0[2] += t;
        t = D_004B5E60.v[3]; a0[3] += t;
        t = D_004B5E60.v[4]; a0[4] += t;
        t = D_004B5E60.v[5]; a0[5] += t;
    }
    if (isType_Stats_CalcDefense_0_001D0000(D_004B5DD0.type)) {
        a0[0] = D_004B5DD0.v[0];
        a0[1] = D_004B5DD0.v[1];
        a0[2] = D_004B5DD0.v[2];
        a0[3] = D_004B5DD0.v[3];
        a0[4] = D_004B5DD0.v[4];
        a0[5] = D_004B5DD0.v[5];
    }
    if (a3[6] != -1) {
        t = D_004B6130.v[0]; a0[0] += t;
        t = D_004B6130.v[1]; a0[1] += t;
        t = D_004B6130.v[2]; a0[2] += t;
        t = D_004B6130.v[3]; a0[3] += t;
        t = D_004B6130.v[4]; a0[4] += t;
        t = D_004B6130.v[5]; a0[5] += t;
    }
    Stats_AddWeighted_1_001D0610(a0, a2);
    if (a1 != NULL) {
        memset(a1, 0, 0x20);
        if (f1) {
            a1[0] += D_004B5DD0.b[0];
            a1[1] += D_004B5DD0.b[1];
            a1[2] += D_004B5DD0.b[2];
            a1[3] += D_004B5DD0.b[4];
            a1[4] += D_004B5DD0.b[3];
            a1[5] += D_004B5DD0.b[5];
        }
        if (f2) {
            a1[0] += D_004B5E60.b[0];
            a1[1] += D_004B5E60.b[1];
            a1[2] += D_004B5E60.b[2];
            a1[3] += D_004B5E60.b[4];
            a1[4] += D_004B5E60.b[3];
            a1[5] += D_004B5E60.b[5];
        }
        if (isType_Stats_CalcDefense_0_001D0000(D_004B5DD0.type)) {
            a1[0] = D_004B5DD0.b[0];
            a1[1] = D_004B5DD0.b[1];
            a1[2] = D_004B5DD0.b[2];
            a1[3] = D_004B5DD0.b[4];
            a1[4] = D_004B5DD0.b[3];
            a1[5] = D_004B5DD0.b[5];
        }
        if ((s16)a1[0] < 0) a1[0] = 0;
        if ((s16)a1[0] > 100) a1[0] = 100;
        if ((s16)a1[1] < 0) a1[1] = 0;
        if ((s16)a1[1] > 100) a1[1] = 100;
        if ((s16)a1[2] < 0) a1[2] = 0;
        if ((s16)a1[2] > 100) a1[2] = 100;
        if ((s16)a1[3] < 0) a1[3] = 0;
        if ((s16)a1[3] > 100) a1[3] = 100;
        if ((s16)a1[4] < 0) a1[4] = 0;
        if ((s16)a1[4] > 100) a1[4] = 100;
        if ((s16)a1[5] < 0) a1[5] = 0;
        if ((s16)a1[5] > 100) a1[5] = 100;
    }
}
#undef Stats_AddWeighted_1_001D0610
#undef D_004B5DD0

/* Stats_AddWeighted_1_001D0610 */
void Stats_AddWeighted_1_001D0610(A *a, B *b) {
    a->v[0] += (b->v[0] + b->v[3] + ((b->v[1] + b->v[2]) >> 1)) / 15;
    a->v[1] += ((b->v[1] >> 1) + ((b->v[0] >> 1) + b->v[2] * 2)) / 15;
    a->v[2] += ((b->v[1] >> 1) + ((b->v[0] >> 1) + b->v[3] * 2)) / 15;
    a->v[3] += (b->v[4] + b->v[5] + ((b->v[6] + b->v[7]) >> 1)) / 15;
    a->v[4] += ((b->v[7] >> 1) + ((b->v[4] >> 1) + b->v[6] * 2)) / 15;
    a->v[5] += ((b->v[7] >> 1) + ((b->v[4] >> 1) + b->v[5] * 2)) / 15;
    if ((s16)a->v[0] < 0) a->v[0] = 0;
    if ((s16)a->v[0] > 999) a->v[0] = 999;
    if ((s16)a->v[1] < 0) a->v[1] = 0;
    if ((s16)a->v[1] > 999) a->v[1] = 999;
    if ((s16)a->v[2] < 0) a->v[2] = 0;
    if ((s16)a->v[2] > 999) a->v[2] = 999;
    if ((s16)a->v[3] < 0) a->v[3] = 0;
    if ((s16)a->v[3] > 999) a->v[3] = 999;
    if ((s16)a->v[4] < 0) a->v[4] = 0;
    if ((s16)a->v[4] > 999) a->v[4] = 999;
    if ((s16)a->v[5] < 0) a->v[5] = 0;
    if ((s16)a->v[5] > 999) a->v[5] = 999;
}

/* Stats_CalcBase_0_001D08E0 */
#define D_004B5DD0 D_004B5DD0__as_Stats_CalcBase_0_001D08E0
extern u8 D_004B5DD0__as_Stats_CalcBase_0_001D08E0[];
#define Item_GetStatBlock_0_001D1240 Item_GetStatBlock_0_001D1240__as_Stats_CalcBase_0_001D08E0
void Item_GetStatBlock_0_001D1240__as_Stats_CalcBase_0_001D08E0(E_Stats_CalcBase_0_001D08E0 *, s16, u8);
#define SH(i) out[i] = base[i] + (D_004B5EF0[0].h[i] + D_004B5EF0[1].h[i] + D_004B5EF0[2].h[i] + D_004B5EF0[3].h[i] + D_004B5EF0[4].h[i] + D_004B5EF0[5].h[i] + D_004B5EF0[6].h[i])
#define SB(i, k) st[i] = D_004B5EF0[0].b[k] + D_004B5EF0[1].b[k] + D_004B5EF0[2].b[k] + D_004B5EF0[3].b[k] + D_004B5EF0[4].b[k] + D_004B5EF0[5].b[k] + D_004B5EF0[6].b[k]
#define CH(i) if (out[i] < 0) out[i] = 0; if (out[i] > 999) out[i] = 999
#define CB(i) if (*(s16 *)&st[i] < 0) st[i] = 0; if (*(s16 *)&st[i] > 100) st[i] = 100

void Stats_CalcBase_0_001D08E0(s16 *out, s32 *st, s16 *a, B4 *b) {
    u16 *base;
    s32 i;

    base = (u16 *)(PlayerData_Get_2_001C9BA0() + 0x20);
    memset(out, 0, 0x10);
    for (i = 2; i < 9; i++) { Item_GetStatBlock_0_001D1240(&((E_Stats_CalcBase_0_001D08E0 *)D_004B5DD0)[i], a[i], b[i].v); }
    SH(0); SH(1); SH(2); SH(3); SH(4); SH(5); SH(6); SH(7);
    CH(0); CH(1); CH(2); CH(3); CH(4); CH(5); CH(6); CH(7);
    if (st != 0) {
        memset(st, 0, 0x20);
        SB(0, 0); SB(1, 1); SB(2, 2); SB(3, 4); SB(4, 3); SB(5, 5);
        CB(0); CB(1); CB(2); CB(3); CB(4); CB(5);
    }
}
#undef Item_GetStatBlock_0_001D1240
#undef D_004B5DD0

/* Stats_CalcMaxHp_0_001D10B0 */
u16 Stats_CalcMaxHp_0_001D10B0(S_Stats_CalcMaxHp_0_001D10B0 *s)
{
    u16 v = s->a * 4 + 500 + (s->d + (s->b + s->c)) * 2;
    if ((s16)v < 0)
        v = 0;
    if ((s16)v > 9999)
        v = 9999;
    return v;
}

/* Stats_CalcMaxMp_0_001D1110 */
u16 Stats_CalcMaxMp_0_001D1110(S_Stats_CalcMaxMp_0_001D1110 *s)
{
    u16 v = s->a * 4 + 500 + (s->d + (s->b + s->c)) * 2;
    if ((s16)v < 0)
        v = 0;
    if ((s16)v > 9999)
        v = 9999;
    return v;
}

/* Stats_CalcWeight_0_001D1170 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Stats_CalcWeight_0_001D1170
S_Stats_CalcWeight_0_001D1170 *PlayerData_Get_2_001C9BA0__as_Stats_CalcWeight_0_001D1170(void);

s32 Stats_CalcWeight_0_001D1170(void) {
    S_Stats_CalcWeight_0_001D1170 *s;
    E_Stats_CalcWeight_0_001D1170 *e;
    u32 i;
    s32 sum;
    s = PlayerData_Get_2_001C9BA0();
    e = Item_GetTable_1_001AFC90();
    sum = 0;
    for (i = 0; i < 1024; i++) {
        sum += s->c[i].x2 * e[i].x4;
    }
    return sum;
}
#undef PlayerData_Get_2_001C9BA0


#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/pad_get_connected_bss_004B5DD0.c): D_004B5EF0__grp: D_004B5EF0@0x0, D_004B5F18@0x28, D_004B5F1C@0x2c, D_004B5F20@0x30, D_004B5F24@0x34, D_004B5F28@0x38, D_004B5FA8@0xb8, D_004B5FAC@0xbc, D_004B5FB0@0xc0, D_004B5FB4@0xc4, D_004B5FB8@0xc8, D_004B6038@0x148, D_004B603C@0x14c, D_004B6040@0x150, D_004B6044@0x154, D_004B6048@0x158, D_004B60C8@0x1d8, D_004B60CC@0x1dc, D_004B60D0@0x1e0, D_004B60D4@0x1e4, D_004B60D8@0x1e8, D_004B6130@0x240, D_004B6158@0x268, D_004B615C@0x26c, D_004B6160@0x270, D_004B6164@0x274, D_004B6168@0x278, D_004B617C@0x28c, D_004B6180@0x290, D_004B61E8@0x2f8, D_004B61EC@0x2fc, D_004B61F0@0x300, D_004B61F4@0x304, D_004B61F8@0x308, D_004B6278@0x388, D_004B627C@0x38c, D_004B6280@0x390, D_004B6284@0x394, D_004B6288@0x398 */
u8 D_004B5EF0__grp[0x490] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/pad_get_connected_bss_004B5DD0.c): D_004B5DD0__grp: D_004B5DD0@0x0, D_004B5DF0@0x20, D_004B5DFC@0x2c, D_004B5E00@0x30, D_004B5E04@0x34, D_004B5E08@0x38, D_004B5E60@0x90, D_004B5E8C@0xbc, D_004B5E90@0xc0, D_004B5E94@0xc4, D_004B5E98@0xc8 */
unsigned char D_004B5DD0__grp[0x120] __attribute__((aligned(16)));
#endif
