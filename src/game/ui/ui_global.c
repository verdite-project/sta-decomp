#include "common.h"
#include "m2c.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { f32 v[4]; } V4;
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; f32 r[4]; V4 b; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { Q a; V4 b; f32 c0; f32 c4; s32 c8; Col cc; f32 d0; f32 d4; f32 d8; f32 dc; } P;
typedef struct { s32 x0; s32 x4; s32 x8; f32 xC; f32 x10; f32 x14; f32 x18; s32 x1C; s32 x20; s32 x24; s32 x28; f32 x2C; f32 x30; f32 x34; f32 x38; Col col; } O;
#ifndef NONMATCHING
extern s32 D_00202070;
#else
/* data twins (src/game/data/sbss.c): D_00202070 */
static s32 D_00202070;
#endif
void Ui_SetGlobalFlag_0_00182990(s32 arg0);
void Ui_DrawElemWrap_1_001829A0(s32 arg0, s32 arg1);
void Ui_DrawList_1_001829B0(O *o, List *l, void (*fn)(P *, s32, s32, s32), s32 arg);

/* Ui_SetGlobalFlag_0_00182990 */
void Ui_SetGlobalFlag_0_00182990(s32 arg0) {
    D_00202070 = arg0;
}

/* Ui_DrawElemWrap_1_001829A0 */
void Ui_DrawElemWrap_1_001829A0(s32 arg0, s32 arg1) {
    Ui_DrawElem_1_00182C10((void *) arg0, (void *) arg1);
}

/* Ui_DrawList_1_001829B0 */
void Ui_DrawList_1_001829B0(O *o, List *l, void (*fn)(P *, s32, s32, s32), s32 arg) {
    Col c;
    Q r;
    P p;
    u32 i;
    Item *it;
    f32 sx;
    f32 sy;
    f32 t;
    u8 cg;
    u8 cb;
    u8 cr;
    u8 ca;

    for (i = 0; i < l->n; i++) {
        cg = o->col.c.g;
        cb = o->col.c.b;
        cr = o->col.c.r;
        ca = o->col.c.a;
        c.c.r = (cr >> 1) | (cr >= 0x80);
        c.c.g = (cg >> 1) | (cg >= 0x80);
        c.c.b = (cb >> 1) | (cb >= 0x80);
        c.c.a = (ca >> 1) | (ca >= 0x80);
        it = &l->items[i];
        sx = o->x14;
        sy = o->x18;
        t = sx * (it->r[0] * o->x34);
        r.f[0] = t + o->xC;
        t = sy * (it->r[1] * o->x38);
        r.f[1] = t + o->x10;
        t = sx * (it->r[2] * o->x34);
        r.f[2] = t + o->xC;
        t = sy * (it->r[3] * o->x38);
        r.f[3] = t + o->x10;
        p.c0 = 1.0f;
        p.c4 = 1.0f;
        p.d0 = o->x2C;
        p.d4 = o->x30;
        p.d8 = r.f[0] + o->x2C;
        p.dc = r.f[1] + o->x30;
        p.c8 = l->items[i].x4;
        p.b = l->items[i].b;
        p.a = r;
        p.cc = c;
        fn(&p, o->x4, l->items[i].x0, arg);
    }
}
