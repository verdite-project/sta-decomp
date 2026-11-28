/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Ui_DrawElem_1_00182C10.c. The matching build takes it from the assembly that
 * ui_gauge.c includes (INCLUDE_ASM(Ui_DrawElem_1_00182C10)). */
#ifdef NONMATCHING
/* NEAR: 22 of 182 words differ (was 35). Loop entry fixed (i = 0; if (i < n) { off = 0; do..while }),
   M2 6-float struct types from Mtx2_Mul_1_001828F0. Remaining: float load/multiply scheduling in the pos[]
   block (retail loads o34,o14,o38,oC,o18 then e10,e14,e1C,e18 and finishes pos[0] before the
   e1*d/e3*d products) - decl/statement permutations didn't reach it. */
#include "common.h"
typedef struct { f32 a[6]; } M2;
typedef struct { u32 n; u8 *p; } L;
#ifndef NONMATCHING
extern M2 gUiDrawElemData_001F2790 __attribute__((aligned(16)));
#else
/* data twins (src/game/data/menu_draw_wrap_data.c): gUiDrawElemData_001F2790 */
static M2 gUiDrawElemData_001F2790 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
#endif
M2 *Mtx2_Rotate_1_00182860(M2 *, f32);
M2 *Mtx2_Mul_1_001828F0(M2 *, M2 *, M2 *);
void Ui_DrawSprite_2_00181680(s32, f32 *, u8 *, u8 *, M2 *, s32);
#define CV(x, k) if (x < 0) x = 0; if (x > 255) x = 255; col[k] = (x >> 1) | (x >= 128);
void Ui_DrawElem_1_00182C10(u8 *o, L *l) {
    u8 col[4];
    f32 pos[4];
    M2 w __attribute__((aligned(16)));
    M2 C;
    M2 X;
    u32 i;
    u32 off;
    s16 r, g, b, a;
    i = 0;
    if (i < l->n) {
    off = 0;
    do {
        r = o[0x3C];
        g = o[0x3D];
        b = o[0x3E];
        a = o[0x3F];
        CV(r, 0)
        CV(g, 1)
        CV(b, 2)
        CV(a, 3)
        {
        u8 *e = l->p + off;
        f32 d = *(f32 *)(o + 0x38);
        f32 ax = *(f32 *)(o + 0x14);
        f32 ay = *(f32 *)(o + 0x18);
        f32 c = *(f32 *)(o + 0x34);
        f32 e0 = *(f32 *)(e + 0x10);
        f32 e1 = *(f32 *)(e + 0x14);
        f32 e3 = *(f32 *)(e + 0x1C);
        f32 e2 = *(f32 *)(e + 0x18);
        f32 t0, t1, t2, t3;
        t0 = ax * (e0 * c);
        t1 = ay * (e1 * d);
        t3 = ay * (e3 * d);
        t2 = ax * (e2 * c);
        pos[0] = t0 + *(f32 *)(o + 0xC);
        pos[1] = t1 + *(f32 *)(o + 0x10);
        pos[2] = t2 + *(f32 *)(o + 0xC);
        pos[3] = t3 + *(f32 *)(o + 0x10);
        }
        w = gUiDrawElemData_001F2790;
        Mtx2_Rotate_1_00182860(&C, *(f32 *)(o + 0x24));
        Mtx2_Mul_1_001828F0(&X, &w, &C);
        X.a[4] = *(f32 *)(o + 0x2C);
        X.a[5] = *(f32 *)(o + 0x30);
        Ui_DrawSprite_2_00181680(*(s32 *)(l->p + off + 4), pos, l->p + off + 0x20, col, &X, *(s32 *)(l->p + off));
        i++; off += 0x30;
    } while (i < l->n);
    }
}
#endif
