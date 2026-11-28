#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C;
    u8 x2D;
    u8 x2E;
    u8 x2F;
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O;
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R;
typedef struct { u8 pad0[0x54]; R *x54; u8 pad58[4]; R *x5C; } G;
typedef struct { u8 x0; } C;
typedef struct { u8 pad0[4]; u16 x4; u8 pad6[0x1A]; u16 x20; u8 pad22[0x6E]; } E;
typedef struct { u8 pad0[0x14]; f32 x14; f32 x18; u8 pad1C[0x10]; f32 x2C; f32 x30; u8 pad34[8]; u32 x3C; } T;
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S *, u32);
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, u32);
G *MenuLayout_GetSub_1_00189020(s32);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
C *Inventory_GetEntry_1_001CC3F0(s16);
s32 Item_GetCategory_0_001AFBD0(s32);
E *Item_GetTable_1_001AFC90(void);
double fptodp(f32);
void Ui_DrawWindow_0_00183650(T *);
extern S D_001F2EE0 __attribute__((aligned(16)));
extern T D_004A13A0;
extern s32 D_00202184;
extern s32 D_00202188;
extern s8 D_001FD328[];
extern s8 gStrHpD_001FD330[];
extern s8 gStrHp_001FD338[];
extern s8 gStr3d_001FD340[];
extern s8 D_001FD348[];
extern s8 gStr31f_001FD350[];
static inline f32 u2f(u32 x) { return x; }

void DbCharProc_DrawInfo_0_00196330(O *o, s32 a1, u32 mode, s32 a3) {
    S t __attribute__((aligned(16))) = D_001F2EE0;
    s8 buf[0x100] = {0};
    Col col;
    R *r;
    E *e;

    if (mode < 300) {
        t.x = o->x30;
        t.y = o->x34;
        if (mode == 0) {
            o->x2E = o->x2D = o->x2C = 0x40;
        }
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, &o->x2C, &t, mode);
        return;
    }
    if (mode == 500) {
        r = &MenuLayout_GetSub_1_00189020(0)->x54[19];
        col.w = 0x30808080;
        t.x = o->x38;
        t.y = o->x3C;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &col, &t, mode);
    }
    if (mode == 501) {
        col.w = 0x80808080;
        sprintf(buf, D_001FD328, D_00202184);
        Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 2, col.w);
    }
    if (mode == 1000) {
        col.w = 0x80808080;
        if (D_00202188 != 0) {
            sprintf(buf, gStrHpD_001FD330, D_00202188);
        } else {
            sprintf(buf, gStrHp_001FD338, D_00202188);
        }
        Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
    }
    switch (mode) {
    case 300:
        r = &MenuLayout_GetSub_1_00189020(0)->x54[a1 + 15];
        col.w = 0x30808080;
        t.x = o->x38;
        t.y = o->x3C;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &col, &t, mode);
        break;
    case 301:
        r = &MenuLayout_GetSub_1_00189020(0)->x5C[a1 + 15];
        col.w = 0x30808080;
        t.m[0] = 1.1f;
        t.m[3] = 1.0f;
        t.x = o->x38 - 5.0f;
        t.y = o->x3C - 4.0f;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &col, &t, mode);
        break;
    }
    switch (a1) {
    case 0:
        switch (mode) {
        case 10001:
            D_004A13A0.x2C = o->x38;
            D_004A13A0.x30 = o->x3C;
            D_004A13A0.x14 = 1.25f;
            D_004A13A0.x3C = 0x80FFFFFF;
            D_004A13A0.x18 = 1.25f;
            Ui_DrawWindow_0_00183650(&D_004A13A0);
            break;
        }
        break;
    case 1:
        switch (mode) {
        case 303:
            col.w = 0x80808080;
            if (a3 > 0) {
                sprintf(buf, gStr3d_001FD340, Inventory_GetEntry_1_001CC3F0(a3)->x0);
                if (Item_GetCategory_0_001AFBD0(a3) == 0) {
                    strcpy(buf, D_001FD348);
                } else if (Item_GetCategory_0_001AFBD0(a3) == 1) {
                    u16 k = Item_GetTable_1_001AFC90()[a3].x20;
                    switch (k) {
                    case 5:
                    case 6:
                        strcpy(buf, D_001FD348);
                        break;
                    }
                }
            } else {
                strcpy(buf, D_001FD348);
            }
            Text_Draw_2_001875C0(o->x38, o->x3C, 0.9f, buf, 2, col.w);
            break;
        }
        break;
    case 2:
        switch (mode) {
        case 302:
            if (a3 > 0) {
                e = Item_GetTable_1_001AFC90() + a3;
                col.w = 0x80808080;
                sprintf(buf, gStr31f_001FD350, fptodp(u2f(e->x4) / 10.0f));
                Text_Draw_2_001875C0(o->x38 - 20.0f, o->x3C - 4.0f, 0.9f, buf, 2, col.w);
            } else {
                col.w = 0x80808080;
                strcpy(buf, D_001FD348);
                Text_Draw_2_001875C0(o->x38 - 20.0f, o->x3C - 4.0f, 0.9f, buf, 2, col.w);
            }
            break;
        }
        break;
    }
}
