#include "common.h"
#include "game/ui.h"
#include "game/gfx.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 n; f32 f[4]; s16 h[4]; Col col; } E;
extern s32 D_002020C0;
extern E D_0048DB60[];
#ifndef NONMATCHING
extern Vec D_001FCBA0[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCBA0 */
static Vec D_001FCBA0[0x9] = { 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 2.0f, 2.0f, 3.2f, 3.2f, 3.2f, 3.2f, 4.6f, 4.6f, 4.6f, 4.6f, 6.2f, 6.2f, 6.2f, 6.2f, 8.0f, 8.0f, 8.0f, 8.0f, 10.0f, 10.0f, 10.0f, 10.0f, 12.0f, 12.0f, 12.0f, 12.0f };
#endif
#ifndef NONMATCHING
extern Vec D_001FCC30[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCC30 */
static Vec D_001FCC30[0x9] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -3.0f, 0.0f, 3.0f, 0.0f, -6.0f, 0.0f, 6.0f, 0.0f, -9.6f, 0.0f, 9.6f, 0.0f, -13.799999f, 0.0f, 13.799999f, 0.0f, -18.599998f, 0.0f, 18.599998f, 0.0f, -24.0f, 0.0f, 24.0f, 0.0f, -30.0f, 0.0f, 30.0f, 0.0f, -36.0f, 0.0f, 36.0f };
#endif
void GsPkt_SetReg_3_001543E0(s32, s32);
void Ui_DrawSpriteRotated_1_00182080(s32, f32, Vec *, Vec *, Col *, s32);

void Menu_DrawBackground_0_00187B20(s32 mode) {
    Vec a;
    Vec b;
    Col col;
    s32 i;
    s32 k;
    s32 n;
    E *e;
    Vec *p;
    Vec *q;

    Ui_BeginSprites_1_00181420();
    if (D_002020C0 <= 0) return;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x46);
    GsPkt_Flush_1_001544C0();
    switch (mode) {
    case 0:
    case 1:
    case 2:
        for (i = 0; i < D_002020C0; i++) {
            e = &D_0048DB60[i];
            a.x = 1.0f + e->f[0];
            a.y = 1.0f + e->f[1];
            a.z = 1.0f + e->f[2];
            a.w = 1.0f + e->f[3];
            b.x = e->h[0];
            b.y = e->h[1];
            b.z = e->h[2];
            b.w = e->h[3];
            col = e->col;
            if (mode == 1) {
                col.c.a = e->col.c.a / (9 - (s32)((u32)col.c.a >> 4));
            } else if (mode == 2) {
                col.c.a = e->col.c.a / (9 - (s32)((u32)col.c.a >> 4));
            } else {
                col.c.a >>= 1;
            }
            Ui_DrawSpriteRotated_1_00182080(e->n, 0.0f, &a, &b, &col, 0);
        }
        break;
    }
    Ui_BeginSprites_1_00181420();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x44);
    GsPkt_Flush_1_001544C0();
    for (i = 0; i < D_002020C0; i++) {
        e = &D_0048DB60[i];
        n = (e->col.c.a > 0x80) ? 1 : 9 - (s32)((u32)e->col.c.a >> 4);
        for (k = 0; k < n; k++) {
            p = &D_001FCBA0[k]; q = &D_001FCC30[k];
            if (mode == 1) {
                a.x = e->f[0] + p->x;
                a.y = e->f[1] + p->y;
                a.z = e->f[2] + p->z;
                a.w = e->f[3] + p->w;
            } else if (mode == 2) {
                a.x = e->f[0] + q->x;
                a.y = e->f[1] + q->y;
                a.z = e->f[2] + q->z;
                a.w = e->f[3] + q->w;
            } else {
                a.x = e->f[0];
                a.y = e->f[1];
                a.z = e->f[2];
                a.w = e->f[3];
            }
            b.x = e->h[0];
            b.y = e->h[1];
            b.z = e->h[2];
            b.w = e->h[3];
            col = e->col;
            if (mode == 1) {
                col.c.a = e->col.c.a / ((9 - (s32)((u32)col.c.a >> 4)) * 2);
            } else if (mode == 2) {
                col.c.a = e->col.c.a / ((9 - (s32)((u32)col.c.a >> 4)) * 2);
            } else {
                col.c.a >>= 1;
            }
            Ui_DrawSpriteRotated_1_00182080(e->n, 0.0f, &a, &b, &col, 0);
            if (mode == 0) break;
        }
    }
    Ui_BeginSprites_1_00181420();
    D_002020C0 = 0;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_002020C0 */
s32 D_002020C0;
/* data twins (src/game/data/ui_gauge_bss.c): D_0048DB60 */
E D_0048DB60[0x8000 / sizeof(E)];
#endif
