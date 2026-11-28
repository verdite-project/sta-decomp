#include "common.h"
#include "game/data.h"
#include "game/ui.h"
#include "game/math.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 idx; u8 pad[0x28]; f32 x2C; f32 x30; u8 pad34[8]; Col x3C; } Obj;
typedef struct { u32 n; Obj *e; } L;
typedef struct { s32 x0; L *l; } R;
typedef struct { s32 x0; s32 x4; u8 x8; } O;
R *MenuLayout_Get_1_00189050(s32);
u8 *MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(Obj *, u8 *, void *, s32);
void LoadMenu_DrawSlotInfo_2_00192110(void);
typedef struct { s32 v[5]; } T5;
#pragma explicit_zero_data on
T5 D_001F2DC0 = { -1, 0, 0, 0, 0 };

void LoadMenu_DrawList_0_00191CB0(O *o) {
    f32 x;
    f32 y;
    Col z;
    T5 tbl __attribute__((aligned(16)));
    Obj ob;
    L *l;
    u8 *t;
    s32 off;
    u32 j;
    s32 i;
    s32 n;
    s32 v;

    tbl = D_001F2DC0;
    l = MenuLayout_Get_1_00189050(4)->l;
    t = MenuLayout_GetSub_1_00189020(4);
    Menu_SetFlags_0_0018A310(8);
    Ui_BeginSprites_1_00181420();
    if (o->x0 == 0x16) D_004A1138[0] += 8.0f;
    Ui_SetAlphaClamped_0_00182050((s32)D_004A1138[0]);
    switch (D_004A112C[0]) {
    case 1:
        D_0020213C = Approachf_3_00187770(D_0020213C, 2.0f, 2.0f);
        if (D_004A113C[0] < 0.0f) {
            D_004A113C[0] = 10.0f;
            D_004A112C[0] = 10;
            D_004A1120[0] = 6;
            D_0020213C = 15.0f;
        } else {
            D_004A113C[0] -= 1.0f;
        }
        break;
    case 3:
        D_0020213C = Approachf_3_00187770(D_0020213C, 13.0f, 2.0f);
        if (D_004A113C[0] < 0.0f) {
            D_004A113C[0] = 10.0f;
            D_0020213C = 0.0f;
            D_004A112C[0] = 10;
            D_004A1120[0] = 0;
        } else {
            D_004A113C[0] -= 1.0f;
        }
        break;
    case 10:
        D_0020213C = Approachf_3_00187770(D_0020213C, D_004A1120[0] + 4, 5.0f);
        if (D_004A113C[0] < 0.0f) {
            D_004A112C[0] = 0;
            D_004A1140[0].f.b0 = 1;
        } else {
            D_004A113C[0] -= 1.0f;
        }
        break;
    default:
        D_0020213C = D_0020213C - (D_0020213C - (f32)(D_004A1120[0] + 4)) / 4.0f;
        break;
    }
    n = (s32)D_0020213C;
    for (i = 0; i < 5; i++) {
        v = n - 5;
        if (v >= 0 && v < 7) {
            tbl.v[i] = v;
        } else {
            tbl.v[i] = -1;
        }
        n++;
    }
    j = 0;
    if (j < l->n) {
        off = 0;
        do {
        {
        u32 k;
        ob = *(Obj *)((u8 *)l->e + off);
        LoadMenu_LerpLayout_0_00192580(&x, &y, &z.c.r, D_0020213C + (f32)(s32)j);
        ob.x2C = x;
        ob.x30 = y;
        ob.x3C = z;
        if (tbl.v[k = ((s32)D_0020213C + j) % l->n] != -1) {
            Ui_DrawList_1_001829B0(&ob, t + ob.idx * 8, LoadMenu_DrawSlotInfo_2_00192110, tbl.v[k]);
        }
        }
            j++;
            off += 0x40;
        } while (j < l->n);
    }
    Ui_DrawItemIconEx_0_0017EDC0(o->x8 == 0xC, D_004A1140[0].f.b1, 1, 7, D_004A1120[0]);
    Menu_DrawBackground_0_00187B20(0);
    Ui_SetAlphaClamped_0_00182050(0x80);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_0020213C */
f32 D_0020213C;
#endif
