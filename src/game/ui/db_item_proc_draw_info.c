/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/DbItemProc_DrawInfo_0_001973F0.c. The matching build takes it from the assembly that
 * databook_item_draw.c includes (INCLUDE_ASM(DbItemProc_DrawInfo_0_001973F0)). */
#ifdef NONMATCHING
/* NEAR: 3 of 372 words differ (was 176). Only case 0x12E: index temp n*9 built in $a0 instead of $a2
   (sll a2,s3,3; addu a2,a2,s3; sll v1,a2,4). Tried e[n], e+=n, (s16)n, k, inline helpers, casts, proto types, b38. */
#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { u8 pad[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } Q;
typedef struct { u8 p0[0x54]; Q *x54; u8 p58[4]; Q *x5C; } G;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x1A]; u16 x20; u8 pad22[0x1A]; u8 x3C; u8 pad3D[0x53]; } E;
typedef struct { u8 pad[0x14]; f32 x14; f32 x18; u8 pad1C[0x10]; f32 x2C; f32 x30; u8 pad34[8]; u32 x3C; } H;
extern S gDbItemProcDrawInfoData_001F2F60[] __attribute__((aligned(16)));
#ifndef NONMATCHING
extern s8 gDbItemProcDrawInfoRodata_001FD368[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): gDbItemProcDrawInfoRodata_001FD368 */
static s8 gDbItemProcDrawInfoRodata_001FD368[0x8] = { 0x25, 0x64, 0x20, -0x7f, -0x6d, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 gDbItemProcDrawInfoRodata_001FD370[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): gDbItemProcDrawInfoRodata_001FD370 */
static s8 gDbItemProcDrawInfoRodata_001FD370[0x8] = { 0x2d, 0x2d, 0x2d, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 gDbItemProcDrawInfoRodata_001FD378[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): gDbItemProcDrawInfoRodata_001FD378 */
static s8 gDbItemProcDrawInfoRodata_001FD378[0x8] = { 0x25, 0x64, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 gStr31f_001FD380[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): gStr31f_001FD380 */
static s8 gStr31f_001FD380[0x6] = "%3.1f\000";
#endif
extern s32 gDatabookItemResetSbss_00202190;
extern H gDbItemProcDrawInfoBss_004A13F0;
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S *, s32);
G *MenuLayout_GetSub_1_00189020(s32);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, u32);
void Ui_DrawWindow_0_00183650(H *);
E *Item_GetTable_1_001AFC90(void);
s32 Item_GetCategory_0_001AFBD0(s32);
double fptodp(f32);

static inline f32 u2f(u32 x) { return x; }

void DbItemProc_DrawInfo_0_001973F0(s8 *o, s32 sel, u32 id, s32 n) {
    s32 k = (s16)n;
    S t __attribute__((aligned(16))) = gDbItemProcDrawInfoData_001F2F60[0];
    s8 buf[0x100] = {0};
    Col col;
    Q *q;
    E *e;
    E *r;

    if (id < 300) {
        t.x = *(f32 *)(o + 0x30);
        t.y = *(f32 *)(o + 0x34);
        if (id == 0) {
            o[0x2C] = 0x40;
            o[0x2D] = 0x40;
            o[0x2E] = 0x40;
        }
        Ui_DrawSprite_2_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        return;
    }
    if (id == 500) {
        q = &MenuLayout_GetSub_1_00189020(0)->x54[19];
        col.w = 0x30808080;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C);
        Ui_DrawSprite_2_00181680(q->x4, q->x10, q->x20, &col, &t, id);
    }
    if (id == 0x1F5) {
        col.w = 0x80808080;
        sprintf(buf, gDbItemProcDrawInfoRodata_001FD368, gDatabookItemResetSbss_00202190);
        Text_Draw_2_001875C0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), 0.9f, buf, 2, col.w);
    }
    switch (id) {
    case 0x12C:
        q = &MenuLayout_GetSub_1_00189020(0)->x54[sel + 15];
        col.w = 0x30808080;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C);
        Ui_DrawSprite_2_00181680(q->x4, q->x10, q->x20, &col, &t, id);
        break;
    case 0x12D:
        q = &MenuLayout_GetSub_1_00189020(0)->x5C[sel + 15];
        col.w = 0x30808080;
        t.m[0] = 1.1f;
        t.m[3] = 1.0f;
        t.x = *(f32 *)(o + 0x38) - 5.0f;
        t.y = *(f32 *)(o + 0x3C) - 4.0f;
        Ui_DrawSprite_2_00181680(q->x4, q->x10, q->x20, &col, &t, id);
        break;
    }
    switch (sel) {
    case 0:
        switch (id) {
        case 0x2711:
            gDbItemProcDrawInfoBss_004A13F0.x2C = *(f32 *)(o + 0x38);
            gDbItemProcDrawInfoBss_004A13F0.x30 = *(f32 *)(o + 0x3C);
            gDbItemProcDrawInfoBss_004A13F0.x14 = 1.25f;
            gDbItemProcDrawInfoBss_004A13F0.x18 = 1.25f;
            gDbItemProcDrawInfoBss_004A13F0.x3C = 0x80FFFFFF;
            Ui_DrawWindow_0_00183650(&gDbItemProcDrawInfoBss_004A13F0);
            break;
        }
        break;
    case 1:
        switch (id) {
        case 0x12F:
            if (n > 0) {
                e = Item_GetTable_1_001AFC90() + n;
                if (Item_GetCategory_0_001AFBD0((s16)k) == 0) {
                    strcpy(buf, gDbItemProcDrawInfoRodata_001FD370);
                } else if (Item_GetCategory_0_001AFBD0((s16)k) == 1) {
                    r = Item_GetTable_1_001AFC90() + (s16)k;
                    sprintf(buf, gDbItemProcDrawInfoRodata_001FD378, r->x3C);
                    switch (r->x20) {
                    case 5:
                    case 6:
                        strcpy(buf, gDbItemProcDrawInfoRodata_001FD370);
                        break;
                    }
                } else {
                    sprintf(buf, gDbItemProcDrawInfoRodata_001FD378, e->x3C);
                }
                col.w = 0x80808080;
                Text_Draw_2_001875C0(*(f32 *)(o + 0x38) - 20.0f, *(f32 *)(o + 0x3C) - 4.0f, 0.9f, buf, 0, col.w);
            }
            break;
        case 0x130:
            break;
        }
        break;
    case 2:
        switch (id) {
        case 0x12E:
            if (n > 0) {
                e = Item_GetTable_1_001AFC90() + n;
                col.w = 0x80808080;
                sprintf(buf, gStr31f_001FD380, fptodp(u2f(e->x4) / 10.0f));
                Text_Draw_2_001875C0(*(f32 *)(o + 0x38) - 20.0f, *(f32 *)(o + 0x3C) - 4.0f, 0.9f, buf, 2, col.w);
            } else {
                col.w = 0x80808080;
                strcpy(buf, gDbItemProcDrawInfoRodata_001FD370);
                Text_Draw_2_001875C0(*(f32 *)(o + 0x38) - 20.0f, *(f32 *)(o + 0x3C) - 4.0f, 0.9f, buf, 2, col.w);
            }
            break;
        }
        break;
    }
}
#endif


#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/databook_item_reset_data.c): D_001F2F60__grp: gDbItemProcDrawInfoData_001F2F60@0x0 */
f32 D_001F2F60__grp[0x8] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/load_menu_bss_004A1120.c): gDbItemProcDrawInfoBss_004A13F0__grp: gDbItemProcDrawInfoBss_004A13F0@0x0, gDbItemProcDrawInfoBss_004A1404@0x14, gDbItemProcDrawInfoBss_004A141C@0x2c, gDbItemProcDrawInfoBss_004A1420@0x30, gDbItemProcDrawInfoBss_004A142C@0x3c */
unsigned char gDbItemProcDrawInfoBss_004A13F0__grp[0x40] __attribute__((aligned(16)));
#endif
