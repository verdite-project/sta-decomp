/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/MenuProc_DrawWeight_0_00185D70.c. The matching build takes it from the assembly that
 * ui_gauge.c includes (INCLUDE_ASM(MenuProc_DrawWeight_0_00185D70)). */
#ifdef NONMATCHING
/* NEAR 2 of 434 words (unchanged). Temp reg of the 24-byte buf = D_001F26B0 lq/sq copy: ours a0, retail a2.
   Library calls renamed (strcpy/strlen/sprintf). Tried: b38, all 120 local orders, void* param copies, mode copy,
   inline copy helper, pointer src/dst, array extern, u128/u64 member copies, initializer, dead a1 uses, a1 types. */
#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
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
typedef struct { u8 pad[0x418]; s16 max; s16 hp; } C;
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R;
typedef struct { u8 pad[0x360]; R r; } RR;
typedef struct { u8 pad0[0x54]; RR *x54; u8 pad58[4]; RR *x5C; } G;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { u8 a:3; u8 b:5; } BF;
typedef struct { f32 x; f32 y; BF f; u8 pad9[0xB]; f32 x14; u8 pad18[8]; f32 x20; f32 x24; s32 x28; u8 pad2C[4]; } T;
void Ui_DrawSprite_2_00181680(s32, void *, void *, void *, S *, u32);
G *MenuLayout_GetSub_1_00189020(s32);
s32 PlayerData_GetStatusTimer_0_001CE200(s32);
void strcpy(s8 *, s8 *);
u32 strlen(s8 *);
void TextParam_Init_1_00187A90(T *, s8 *, u64);
s32 Text_Render_2_00188010(T *, Col);
u64 fptodp(f32);
void sprintf(s8 *, s8 *, u64);
#ifndef NONMATCHING
extern S D_001F26B0 __attribute__((aligned(16)));
#else
/* data twins (src/game/data/ui_global_data.c): D_001F26B0 */
static S D_001F26B0 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
#endif
extern s8 D_0048CE40[];
#ifdef NONMATCHING
extern u8 D_001FC980[];
extern u8 D_001FC988[];
extern u8 D_001FC998[];
extern u8 D_001FC9A8[];
extern u8 D_001FC9B0[];
extern u8 D_001FC9B8[];
#endif
extern f32 D_0048D040[];
#ifndef NONMATCHING
extern s8 *D_001F2690[];
#else
/* data twins (src/game/data/ui_global_data.c): D_001F2690 */
static s8 *D_001F2690[0x8] = { (s8 *)D_001FC980, (s8 *)D_001FC988, (s8 *)D_001FC998, (s8 *)D_001FC9A8, (s8 *)D_001FC9B0, (s8 *)D_001FC9B8, 0, 0 };
#endif
extern s8 D_001FCAA0[];
extern s8 D_001FCB38[];
#ifndef NONMATCHING
extern s32 D_00202078;
#else
/* data twins (src/game/data/sbss.c): D_00202078 */
static s32 D_00202078;
#endif
#ifndef NONMATCHING
extern s32 D_00202074;
#else
/* data twins (src/game/data/sbss.c): D_00202074 */
static s32 D_00202074;
#endif
static inline f32 u2f(u32 x) { return x; }
static inline void txt(s8 *s, Col c, O *o, s32 k, f32 sc) {
    T t;
    f32 x;
    f32 y;
    y = o->x3C;
    x = o->x38;
    if (s) {
        TextParam_Init_1_00187A90(&t, s, strlen(s));
        t.x = x;
        t.y = y;
        t.f.a = k;
        t.x24 = 1.0f;
        t.x20 = sc;
        t.x14 = 4096.0f;
        Text_Render_2_00188010(&t, c);
    }
}

void MenuProc_DrawWeight_0_00185D70(O *o, s32 a1, u32 mode, C *a3) {
    S buf __attribute__((aligned(16)));
    Col col;
    s32 i;
    s32 r;
    R *g;

    buf = D_001F26B0;
    if (mode < 300) {
        buf.x = o->x30;
        buf.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 300:
        if (a3 == NULL) break;
        D_0048CE40[0] = 0;
        for (i = 0; i < 6; i++) {
            r = PlayerData_GetStatusTimer_0_001CE200(i);
            if (r == 0) {
                D_0048D040[i] = 0.0f;
                if (D_00202078 == i) {
                    D_00202078 = (D_00202078 + 1) % 6;
                }
            } else if (D_00202078 == i) {
                strcpy(D_0048CE40, D_001F2690[i]);
                if (r == 1) {
                    col.w = 0x80808080;
                } else if (r == 2) {
                    col.w = 0x80404080;
                }
                if (D_00202074) {
                    D_0048D040[i] -= 16.0f;
                    if (D_0048D040[i] < 0.0f) {
                        D_0048D040[i] = 0.0f;
                        D_00202074 = 0;
                        D_00202078 = (D_00202078 + 1) % 6;
                    }
                } else {
                    D_0048D040[i] += 12.0f;
                    if (!(D_0048D040[i] <= 250.0f)) {
                        D_00202074 = 1;
                    }
                }
                col.c.a = (D_0048D040[i] > 192.0f) ? 0xC0 : (s32)D_0048D040[i];
                txt(D_0048CE40, col, o, 1, 0.9f);
            }
        }
        break;
    case 301:
        g = &MenuLayout_GetSub_1_00189020(0)->x54->r;
        col.w = 0x30808080;
        buf.x = o->x38;
        buf.y = o->x3C;
        Ui_DrawSprite_2_00181680(g->x4, g->x10, g->x20, &col, &buf, 0);
        break;
    case 302:
        if (a3->max < 0) a3->max = 0;
        if (a3->max > 999) a3->max = 999;
        if (a3->hp < 0) a3->hp = 0;
        if (a3->hp > 999) a3->hp = 999;
        if ((u16)a3->max > (u16)a3->hp) {
            col.w = 0x80404080;
        } else {
            col.w = 0x80808080;
        }
        sprintf(D_0048CE40, D_001FCAA0, fptodp(u2f((u16)a3->max) / 10.0f));
        txt(D_0048CE40, col, o, 2, 0.8f);
        break;
    case 303:
        if (a3->max < 0) a3->max = 0;
        if (a3->max > 999) a3->max = 999;
        if (a3->hp < 0) a3->hp = 0;
        if (a3->hp > 999) a3->hp = 999;
        col.w = 0x80808080;
        sprintf(D_0048CE40, D_001FCB38, fptodp(u2f((u16)a3->hp) / 10.0f));
        txt(D_0048CE40, col, o, 0, 0.8f);
        break;
    case 304:
        g = &MenuLayout_GetSub_1_00189020(0)->x5C->r;
        col.w = 0x30808080;
        buf.m[0] = 1.1f;
        buf.m[3] = 1.0f;
        buf.x = 30.0f + o->x38;
        buf.y = o->x3C;
        Ui_DrawSprite_2_00181680(g->x4, g->x10, g->x20, &col, &buf, 0);
        break;
    }
}
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_001FC980[];
extern u8 D_001FC988[];
extern u8 D_001FC998[];
extern u8 D_001FC9A8[];
extern u8 D_001FC9B0[];
extern u8 D_001FC9B8[];
#endif
