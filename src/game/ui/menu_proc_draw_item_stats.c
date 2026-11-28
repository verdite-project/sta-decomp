/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/MenuProc_DrawItemStats_0_00184280.c. The matching build takes it from the assembly that
 * ui_gauge.c includes (INCLUDE_ASM(MenuProc_DrawItemStats_0_00184280)). */
#ifdef NONMATCHING
#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 a:3; u8 b:5; } BF;
typedef struct { f32 x; f32 y; BF bf; u8 pad9[0xB]; f32 x14; u8 pad18[8]; f32 x20; f32 x24; u8 pad28[8]; } T;
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
typedef struct { u8 pad0[0x300]; R r[2]; } RR;
typedef struct { u8 pad0[0x54]; RR *x54; u8 pad58[4]; RR *x5C; } G;
typedef struct { u8 pad0[4]; u16 x4; u8 pad6[0x1A]; u16 x20; u8 pad22[0x6E]; } E;
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S *, u32);
G *MenuLayout_GetSub_1_00189020(s32);
s32 Item_GetDurability_0_001848A0(s32);
u8 *Inventory_GetEntry_1_001CC3F0(s16);
s32 Item_GetStatValue_0_00187130(s32, s32);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
s32 Item_GetCategory_0_001AFBD0(s32);
E *Item_GetTable_1_001AFC90(void);
u32 strlen(s8 *);
void TextParam_Init_1_00187A90(T *, s8 *, u64);
s32 Text_Render_2_00188010(T *, Col);
s64 fptodp(f32);
void Ui_DrawWindow_0_00183650(s8 *);
#ifndef NONMATCHING
extern S D_001F2720 __attribute__((aligned(16)));
#else
/* data twins (src/game/data/ui_global_data.c): D_001F2720 */
static S D_001F2720 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
#endif
extern s8 D_0048CE40[];
extern s8 D_001FCA80[];
extern s8 D_001FCA88[];
#ifndef NONMATCHING
extern s8 D_001FCA90[];
#else
/* data twins (src/game/data/ui_gauge_rodata.c): D_001FCA90 */
static s8 D_001FCA90[0x5] = "/---\000";
#endif
#ifndef NONMATCHING
extern s8 gStr3d_001FCA98[];
#else
/* data twins (src/game/data/ui_gauge_rodata.c): gStr3d_001FCA98 */
static s8 gStr3d_001FCA98[0x5] = "/%3d\000";
#endif
extern s8 D_001FCAA0[];
extern s8 D_0048D0A0[];
extern f32 D_0048D0CC[];
extern f32 D_0048D0D0[];
extern s32 D_0048D0DC[];
extern f32 D_0048D0B4[];
extern f32 D_0048D0B8[];
static inline f32 u2f(u32 x) { return x; }
static inline void txt(s8 *s, f32 x, f32 y, Col *c, T *t) {
    if (s == 0) return;
    TextParam_Init_1_00187A90(t, s, strlen(s));
    t->x24 = 1.0f;
    t->bf.a = 0;
    t->x20 = 0.9f;
    t->x14 = 4096.0f;
    t->x = x;
    t->y = y;
    Text_Render_2_00188010(t, *c);
}

void MenuProc_DrawItemStats_0_00184280(O *o, s32 a1, u32 mode, s32 id) {
    S buf __attribute__((aligned(16)));
    T t1;
    T t2;
    T t3;
    Col c1;
    Col c3;
    Col c2;
    R *r;
    E *e;
    s32 k;

    buf = D_001F2720;
    if (mode < 600) {
        buf.x = o->x30;
        buf.y = o->x34;
        if (mode == 0) {
            o->x2C = 0x40;
            o->x2D = 0x40;
            o->x2E = 0x40;
        }
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 0x259:
        break;
    case 0x25A:
        break;
    case 0x25B:
        r = &MenuLayout_GetSub_1_00189020(0)->x54->r[0];
        buf.x = o->x38;
        buf.y = o->x3C;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, 0);
        break;
    case 0x25C:
        r = &MenuLayout_GetSub_1_00189020(0)->x5C->r[0];
        buf.x = o->x38;
        buf.y = o->x3C;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, 0);
        break;
    case 0x25D:
        if (id > 0) {
            Item_GetDurability_0_001848A0(id);
            Inventory_GetEntry_1_001CC3F0(id);
            if (Item_GetStatValue_0_00187130(id, 0)) {
                *(u32 *)&c1 = 0x80404080;
            } else {
                *(u32 *)&c1 = 0x80808080;
            }
            sprintf(D_0048CE40, D_001FCA80, *Inventory_GetEntry_1_001CC3F0(id));
            k = (s16)id;
            if (Item_GetCategory_0_001AFBD0(k) == 0) {
                strcpy(D_0048CE40, D_001FCA88);
            } else if (Item_GetCategory_0_001AFBD0(k) == 1) {
                e = Item_GetTable_1_001AFC90();
                switch (((E *)((s32)e + id * 0x90))->x20) {
                case 5:
                case 6:
                    strcpy(D_0048CE40, D_001FCA88);
                }
            }
            txt(D_0048CE40, o->x38, o->x3C, &c1, &t1);
        }
        break;
    case 0x25E:
        if (id > 0) {
            k = Item_GetDurability_0_001848A0(id);
            *(u32 *)&c2 = 0x80808080;
            if (k == 0) {
                strcpy(D_0048CE40, D_001FCA90);
            } else {
                sprintf(D_0048CE40, gStr3d_001FCA98, k);
            }
            txt(D_0048CE40, o->x38, o->x3C, &c2, &t2);
        }
        break;
    case 0x25F:
        r = &MenuLayout_GetSub_1_00189020(0)->x54->r[1];
        buf.x = o->x38;
        buf.y = o->x3C;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, 0);
        break;
    case 0x260:
        r = &MenuLayout_GetSub_1_00189020(0)->x5C->r[1];
        buf.x = o->x38;
        buf.y = o->x3C;
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, 0);
        break;
    case 0x261:
        if (id > 0) {
            e = &Item_GetTable_1_001AFC90()[id];
            *(u32 *)&c3 = 0x80808080;
            sprintf(D_0048CE40, D_001FCAA0, fptodp(u2f(e->x4) / 10.0f));
            txt(D_0048CE40, o->x38, o->x3C, &c3, &t3);
        }
        break;
    case 0x2711:
        D_0048D0CC[0] = o->x38;
        D_0048D0D0[0] = o->x3C;
        D_0048D0B4[0] = 1.0f;
        D_0048D0B8[0] = 1.0f;
        D_0048D0DC[0] = 0x80FFFFFF;
        Ui_DrawWindow_0_00183650(D_0048D0A0);
        break;
    }
}
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/ui_gauge_rodata.c): D_001FCAA0 */
s8 D_001FCAA0[0x10] = { 0x25, 0x33, 0x2e, 0x31, 0x66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
