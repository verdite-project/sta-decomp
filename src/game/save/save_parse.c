#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/save.h"
#include "game/core.h"
typedef struct { u32 tag; u32 x4; u32 x8; u32 xC; u32 x10; u32 x14; u32 x18; u32 x1C; } Rec_Save_ParseOptions_1_001A8B90;
typedef struct { u8 x0[0x20]; u8 x20[0x30]; u8 x50[0x10]; } Big_Save_ParseOptions_1_001A8B90;
typedef SaveRec Rec_Save_WriteOptions_1_001A8CA0;
typedef struct { Rec_Save_WriteOptions_1_001A8CA0 r0; u8 x20[0x10]; Rec_Save_WriteOptions_1_001A8CA0 r1; u8 pad[0x80]; Rec_Save_WriteOptions_1_001A8CA0 r2; } Big_Save_WriteOptions_1_001A8CA0;
typedef struct { u32 tag; u32 x4; u32 x8; u32 xC; u32 x10; u32 x14; u32 x18; u32 x1C; } Rec_Save_ParseOptionsB_0_001A8F00;
typedef struct {
    u8 x0[0x20];
    u8 x20[0x10E0 - 0x20];
    u8 x10E0[0x5AC0 - 0x10E0];
    u8 x5AC0[0x5B60 - 0x5AC0];
    u8 x5B60[0x5C00 - 0x5B60];
    u8 x5C00[0x10];
} Big_Save_ParseOptionsB_0_001A8F00;
typedef SaveRec Rec_Save_ParseGame_1_001A9080;
typedef struct {
    Rec_Save_ParseGame_1_001A9080 r0;
    u8 x20[0x10C0 - 0x20];
    Rec_Save_ParseGame_1_001A9080 r1;
    u8 pad1[0x5AA0 - 0x10E0];
    Rec_Save_ParseGame_1_001A9080 r2;
    u8 pad2[0x5B40 - 0x5AC0];
    Rec_Save_ParseGame_1_001A9080 r3;
    u8 pad3[0x5BE0 - 0x5B60];
    Rec_Save_ParseGame_1_001A9080 r4;
    u8 pad4[0x7C00 - 0x5C00];
    Rec_Save_ParseGame_1_001A9080 r5;
} Big_Save_ParseGame_1_001A9080;
typedef struct { u8 pad0[8]; u16 x8; u8 xA; u8 xB; u8 pad[0x98 - 0xC]; u8 x98; u8 x99; u8 x9A; u8 x9B; } Src;
extern Big_Save_ParseOptions_1_001A8B90 *D_00201E00;
extern PlayerData *D_00201DC0;
void Save_ParseOptions_1_001A8B90(Rec_Save_ParseOptions_1_001A8B90 *p);
void Save_ParseOptionsB_0_001A8F00(Rec_Save_ParseOptionsB_0_001A8F00 *p);
s32 Save_GetData_1_001A9400(void);
void memcpy(void *, void *, s32);
void Player_SetStartPos_0_001C9630(Vec *, Vec *);
void PlayerData_Load_1_001C9BB0(u8 *);
void PlayTime_Load_1_001DFAA0(u8 *);
Src* PlayerData_Get_2_001C9BA0(void);
void PlayTime_CopyClock_1_001DF930(u8 *);

/* Save_ParseOptions_1_001A8B90 */
void Save_ParseOptions_1_001A8B90(Rec_Save_ParseOptions_1_001A8B90 *p) {
    s32 *d;
    u8 *s;
    s8 *c1 = &D_001FD988[1];
    s8 *c2 = &D_001FD988[2];
    s8 *c3 = &D_001FD988[3];

    while (1) {
        d = (s32 *)((u8 *)p + 0x10);
        s = (u8 *)d + 0x10; s += (p->x1C + 15) & ~15;
        if (p->tag == (D_001FD988[0] | (*c1 << 8) | (*c2 << 16) | (*c3 << 24))) return;
        switch (p->tag) {
        case 0x6154504F:
            memcpy(D_00201E00->x20, s, *d);
            break;
        case 0x61535953:
            memcpy(D_00201E00->x50, s, *d);
            break;
        }
        p = (Rec_Save_ParseOptions_1_001A8B90 *)((u8 *)p + p->x4);
    }
}

/* Save_WriteOptions_1_001A8CA0 */
#define D_00201E00 D_00201E00__as_Save_WriteOptions_1_001A8CA0
extern Big_Save_WriteOptions_1_001A8CA0 *D_00201E00__as_Save_WriteOptions_1_001A8CA0;
#define FCC(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline void init_Save_WriteOptions_1_001A8CA0(Rec_Save_WriteOptions_1_001A8CA0 *p, s8 *s, u32 x4, u32 x10, u32 x14) {
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

void Save_WriteOptions_1_001A8CA0(void) {
Big_Save_WriteOptions_1_001A8CA0 *b = D_00201E00; init_Save_WriteOptions_1_001A8CA0(&b->r0, D_001FD990, 0x30, 0x20, 0x10); b = D_00201E00; init_Save_WriteOptions_1_001A8CA0(&b->r1, D_001FD998, 0xA0, 0x90, 0x80); b = D_00201E00; init_Save_WriteOptions_1_001A8CA0(&b->r2, D_001FD988, 0x20, 0x10, 0); }
#undef D_00201E00

/* Save_ApplyLoaded_0_001A8E30 */
void Save_ApplyLoaded_0_001A8E30(void) {
    Vec a;
    Vec b;

    a.x = D_00201DC0->x30;
    a.y = D_00201DC0->x32;
    a.z = D_00201DC0->x34;
    a.w = 0.0f;
    b.x = 0.00024414062f * D_00201DC0->x36;
    b.y = 0.00024414062f * D_00201DC0->x38;
    b.w = 0.0f;
    b.z = 0.0f;
    if (D_00201DC0->x2E != 1) {
        Player_SetStartPos_0_001C9630(&a, &b);
    }
    PlayerData_Load_1_001C9BB0(D_00201DC0->x20);
    PlayTime_Load_1_001DFAA0((u8 *)D_00201DC0 + 0xB8);
    PlayTime_Tick_1_001DF9A0();
}

/* Save_ParseOptionsB_0_001A8F00 */
#define D_00201DC0 D_00201DC0__as_Save_ParseOptionsB_0_001A8F00
extern Big_Save_ParseOptionsB_0_001A8F00 *D_00201DC0__as_Save_ParseOptionsB_0_001A8F00;
#define FCC(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))

void Save_ParseOptionsB_0_001A8F00(Rec_Save_ParseOptionsB_0_001A8F00 *p) {
    s32 *d;
    u8 *s;
    s8 *c1 = &D_001FD988[1];
    s8 *c2 = &D_001FD988[2];
    s8 *c3 = &D_001FD988[3];

    while (1) {
        d = (s32 *)((u8 *)p + 0x10);
        s = (u8 *)d + 0x10; s += (p->x1C + 15) & ~15;
        if (p->tag == (D_001FD988[0] | (*c1 << 8) | (*c2 << 16) | (*c3 << 24))) return;
        switch (p->tag) {
        case 0x61534350:
            memcpy(D_00201DC0->x20, s, *d);
            break;
        case 0x6150414D:
            memcpy(D_00201DC0->x10E0, s, *d);
            break;
        case 0x61454E45:
            memcpy(D_00201DC0->x5AC0, s, *d);
            break;
        case 0x614D5449:
            memcpy(D_00201DC0->x5B60, s, *d);
            break;
        case 0x61484353:
            memcpy(D_00201DC0->x5C00, s, *d);
            break;
        }
        p = (Rec_Save_ParseOptionsB_0_001A8F00 *)((u8 *)p + p->x4);
    }
}
#undef D_00201DC0

/* Save_ParseGame_1_001A9080 */
#define D_00201DC0 D_00201DC0__as_Save_ParseGame_1_001A9080
extern Big_Save_ParseGame_1_001A9080 *D_00201DC0__as_Save_ParseGame_1_001A9080;
#define FCC(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline void init_Save_ParseGame_1_001A9080(Rec_Save_ParseGame_1_001A9080 *p, s8 *s, u32 x4, u32 x10, u32 x14) {
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

void Save_ParseGame_1_001A9080(void) {
    Src *s;
    Big_Save_ParseGame_1_001A9080 *b;
    s = PlayerData_Get_2_001C9BA0();
    PlayTime_CopyClock_1_001DF930(&s->x98);
    s->x8 = s->x9B;
    s->xA = s->x9A;
    s->xB = s->x99;
    memcpy(D_00201DC0->x20, s, 0x10A0);
    b = D_00201DC0; init_Save_ParseGame_1_001A9080(&b->r0, D_001FD9A0, 0x10C0, 0x10B0, 0x10A0);
    b = D_00201DC0; init_Save_ParseGame_1_001A9080(&b->r1, D_001FD9A8, 0x49E0, 0x49D0, 0x49C0);
    b = D_00201DC0; init_Save_ParseGame_1_001A9080(&b->r2, D_001FD9B0, 0xA0, 0x90, 0x80);
    b = D_00201DC0; init_Save_ParseGame_1_001A9080(&b->r3, D_001FD9B8, 0xA0, 0x90, 0x80);
    b = D_00201DC0; init_Save_ParseGame_1_001A9080(&b->r4, D_001FD9C0, 0x2020, 0x2010, 0x2000);
    b = D_00201DC0; init_Save_ParseGame_1_001A9080(&b->r5, D_001FD988, 0x20, 0x10, 0);
}
#undef D_00201DC0

/* Save_GetData_1_001A9400 */
#define D_00201DC0 D_00201DC0__as_Save_GetData_1_001A9400
extern s32 D_00201DC0__as_Save_GetData_1_001A9400;

s32 Save_GetData_1_001A9400(void) {
    return D_00201DC0;
}
#undef D_00201DC0

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_004A4980[];
extern u8 D_004A4880[];
/* data twins (src/game/data/sdata.c): D_00201DC0, D_00201E00 */
PlayerData *D_00201DC0 = (PlayerData *)D_004A4980;
Big_Save_ParseOptions_1_001A8B90 *D_00201E00 = (Big_Save_ParseOptions_1_001A8B90 *)D_004A4880;
#endif
