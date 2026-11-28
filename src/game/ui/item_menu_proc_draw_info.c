/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/ItemMenuProc_DrawInfo_0_0019CEF0.c. The matching build takes it from the assembly that
 * item_menu_draw.c includes (INCLUDE_ASM(ItemMenuProc_DrawInfo_0_0019CEF0)). */
#ifdef NONMATCHING
#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 p0[0x4]; u16 x4; u8 p6[4]; u16 xA; u8 pC[0x1D]; u8 x29; u8 p2A[0x66]; } E;
typedef struct { u8 p0[0x14]; f32 x14; f32 x18; u8 p1C[0x10]; f32 x2C; f32 x30; u8 p34[8]; u32 x3C; } G;
extern S D_001F30E0 __attribute__((aligned(16)));
#ifndef NONMATCHING
extern s8 D_001FD5B8[];
#else
/* data twins (src/game/data/item_menu_draw_rodata.c): D_001FD5B8 */
static s8 D_001FD5B8[0x8] = { 0x25, 0x33, 0x64, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FD5C0[];
#else
/* data twins (src/game/data/item_menu_draw_rodata.c): D_001FD5C0 */
static s8 D_001FD5C0[0x6] = "(+%d)\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD5C8[];
#else
/* data twins (src/game/data/item_menu_draw_rodata.c): D_001FD5C8 */
static s8 D_001FD5C8[0x6] = "%3.1f\000";
#endif
extern s8 D_004A3150[];
extern G D_004A3250;
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, Col);
void Ui_DrawSprite_2_00181680(s32, s8 *, s8 *, void *, S *, s32);
void sprintf(s8 *, s8 *, ...);
E *Item_GetTable_1_001AFC90(void);
u8 *Inventory_GetEntry_1_001CC3F0(s16);
s8 *MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawWindow_0_00183650(G *);
double fptodp(f32);
static inline f32 u2f(u32 x) { return x; }
static inline s32 chk(E *e) { if (e->xA == 0 && e->x29 == 5) return 1; return 0; }

void ItemMenuProc_DrawInfo_0_0019CEF0(s8 *a0, s32 a1, u32 a2, s32 a3) {
    S t __attribute__((aligned(16)));
    Col col;
    Col col2;
    s8 *q;
    E *e;

    t = D_001F30E0;
    if (a2 < 300) {
        t.x = *(f32 *)(a0 + 0x30);
        t.y = *(f32 *)(a0 + 0x34);
        if (a2 == 0) {
            a0[0x2C] = 0x40;
            a0[0x2D] = 0x40;
            a0[0x2E] = 0x40;
        }
        Ui_DrawSprite_2_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, a0 + 0x2C, &t, a2);
        return;
    }
    switch (a2) {
    case 300:
        if (a3 > 0) {
            *(u32 *)&col = 0x80808080;
            if (chk(&Item_GetTable_1_001AFC90()[a3])) {
                sprintf(D_004A3150, D_001FD5B8, Inventory_GetEntry_1_001CC3F0(a3)[2]);
                Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9f, D_004A3150, 2, col);
                sprintf(D_004A3150, D_001FD5C0, Inventory_GetEntry_1_001CC3F0(a3)[3]);
                Text_Draw_2_001875C0(8.0f + *(f32 *)(a0 + 0x38), 3.0f + *(f32 *)(a0 + 0x3C), 0.7f, D_004A3150, 0, col);
            } else {
                sprintf(D_004A3150, D_001FD5B8, Inventory_GetEntry_1_001CC3F0(a3)[2]);
                Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9f, D_004A3150, 2, col);
            }
        }
        break;
    case 10001:
        D_004A3250.x2C = *(f32 *)(a0 + 0x38);
        D_004A3250.x30 = *(f32 *)(a0 + 0x3C);
        D_004A3250.x14 = 1.25f;
        D_004A3250.x18 = 1.25f;
        D_004A3250.x3C = 0x80FFFFFF;
        Ui_DrawWindow_0_00183650(&D_004A3250);
        break;
    case 400:
        if (a3 > 0) {
            e = Item_GetTable_1_001AFC90() + a3;
            *(u32 *)&col2 = 0x80808080;
            sprintf(D_004A3150, D_001FD5C8, fptodp(u2f(e->x4) / 10.0f));
            Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9f, D_004A3150, 0, col2);
        }
        break;
    case 500:
        q = *(s8 **)(MenuLayout_GetSub_1_00189020(0) + 0x54) + 0x330;
        t.x = *(f32 *)(a0 + 0x38);
        t.y = *(f32 *)(a0 + 0x3C);
        Ui_DrawSprite_2_00181680(*(s32 *)(q + 4), q + 0x10, q + 0x20, a0 + 0x2C, &t, 0);
        break;
    }
}
#endif
