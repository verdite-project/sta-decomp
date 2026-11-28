#include "m2c.h"
#include "common.h"
#include "game/gfx.h"
#include "game/ui.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_Ui_BeginSprites_1_00181420;
typedef union { u128 q; u32 w[4]; } Q_Ui_DrawSprite_2_00181680;
typedef struct { f32 x, y; } P2;
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q_Ui_DrawSpriteRotated_1_00182080;
typedef struct { Q_Ui_DrawSpriteRotated_1_00182080 q[9]; } E;
#ifndef NONMATCHING
extern s32 gUiDrawSbss_0020206C;
#else
/* data twins (src/game/data/sbss.c): gUiDrawSbss_0020206C */
static s32 gUiDrawSbss_0020206C;
#endif
#ifndef NONMATCHING
extern s32 gUiDrawSdata_00201CD4;
#else
/* data twins (src/game/data/sdata.c): gUiDrawSdata_00201CD4 */
static s32 gUiDrawSdata_00201CD4 = -1;
#endif
extern s32 gDrawSbss_00201F3C;
extern Q_Ui_BeginSprites_1_00181420 gUiGaugeBss_0048C4B0[];
#ifndef NONMATCHING
extern s32 gUiDrawSdata_00201CD8;
#else
/* data twins (src/game/data/sdata.c): gUiDrawSdata_00201CD8 */
static s32 gUiDrawSdata_00201CD8 = 0x80;
#endif
void Ui_DrawSprite_2_00181680(s32 id, f32 *r, f32 *uv, u8 *col, f32 *m, s32 mode);
void Ui_DrawSpriteRotated_1_00182080(s32 a0, f32 *r, f32 *uv, u8 *col, f32 ang);
s32 GsPkt_Alloc_3_00154A80(s32);
f32 sinf(f32);
f32 cosf(f32);

/* Ui_BeginSprites_1_00181420 */
// mwcc=mwcps2-3.0b38-030307
void Ui_BeginSprites_1_00181420(void) {
    Q_Ui_BeginSprites_1_00181420 q;
    Q_Ui_BeginSprites_1_00181420 *p;
    u32 i;

    if (gUiDrawSbss_0020206C > 0) {
        if (gUiDrawSdata_00201CD4 != 0) Tex_BindFlush_1_00176BC0(gUiDrawSdata_00201CD4);
        p = (Q_Ui_BeginSprites_1_00181420 *)GsPkt_Alloc_3_00154A80(gUiDrawSbss_0020206C * 9 + 3);
        q.q = 0;
        q.w[0] = (gUiDrawSbss_0020206C * 9 + 2) | 0x10000000;
        q.w[3] = ((gUiDrawSbss_0020206C * 9 + 1) << 16) | 0x6C00C000;
        p[0] = q;
        if (gUiDrawSdata_00201CD4 != 0) {
            q.q = 0;
            q.d[0] = (u64)gUiDrawSbss_0020206C | (0x8000 | ((u64)0x90AE4000 << 32));
            q.d[1] = 0x3434343E | ((u64)4 << 32);
            p[1] = q;
            p += 2;
        } else {
            q.q = 0;
            q.d[0] = (u64)gUiDrawSbss_0020206C | (0x8000 | ((u64)0x90A64000 << 32));
            q.d[1] = 0x3434343E | ((u64)4 << 32);
            p[1] = q;
            p += 2;
        }
        gUiDrawSdata_00201CD4 = -1;
        for (i = 0; i < gUiDrawSbss_0020206C * 9; i++) *p++ = gUiGaugeBss_0048C4B0[i];
        q.q = 0;
        q.w[2] = gDrawSbss_00201F3C | 0x15000000;
        q.w[3] = 0x11000000;
        *p = q;
        GsPkt_CloseChain_1_001549D0();
        gUiDrawSbss_0020206C = 0;
    }
}

/* Ui_DrawSprite_2_00181680 */
#define gUiGaugeBss_0048C4B0 gUiGaugeBss_0048C4B0__as_Ui_DrawSprite_2_00181680
extern Q_Ui_DrawSprite_2_00181680 gUiGaugeBss_0048C4B0__as_Ui_DrawSprite_2_00181680[][9];
static inline void rot(P2 *p, f32 *m) {
    P2 t;
    t.x = p->x * m[0] + p->y * m[1];
    t.y = p->x * m[2] + p->y * m[3];
    *p = t;
}

void Ui_DrawSprite_2_00181680(s32 id, f32 *r, f32 *uv, u8 *col, f32 *m, s32 mode) {
    P2 p0, p1, p2, p3;
    Q_Ui_DrawSprite_2_00181680 q;
    Q_Ui_DrawSprite_2_00181680 *p;
    if (col[3] < 2) return;
    switch (mode) {
    default:
        p0.x = r[0]; p0.y = r[1];
        p1.x = r[0]; p1.y = r[3];
        p2.x = r[2]; p2.y = r[1];
        p3.x = r[2]; p3.y = r[3];
        break;
    case 1:
        p0.x = r[2]; p0.y = r[1];
        p1.x = r[2]; p1.y = r[3];
        p2.x = r[0]; p2.y = r[1];
        p3.x = r[0]; p3.y = r[3];
        break;
    case 2:
        p0.x = r[0]; p0.y = r[3];
        p1.x = r[0]; p1.y = r[1];
        p2.x = r[2]; p2.y = r[3];
        p3.x = r[2]; p3.y = r[1];
        break;
    case 3:
        p0.x = r[2]; p0.y = r[3];
        p1.x = r[2]; p1.y = r[1];
        p2.x = r[0]; p2.y = r[3];
        p3.x = r[0]; p3.y = r[1];
        break;
    }
    rot(&p0, m);
    rot(&p1, m);
    rot(&p2, m);
    rot(&p3, m);
    p0.x += m[4]; p0.y += m[5];
    p1.x += m[4]; p1.y += m[5];
    p2.x += m[4]; p2.y += m[5];
    p3.x += m[4]; p3.y += m[5];
    if (gUiDrawSdata_00201CD4 != id || gUiDrawSbss_0020206C >= 16) {
        Ui_BeginSprites_1_00181420();
        gUiDrawSdata_00201CD4 = id;
    }
    p = gUiGaugeBss_0048C4B0[gUiDrawSbss_0020206C];
    q.w[0] = (((col[3] * gUiDrawSdata_00201CD8) / 128) << 24) | (col[2] << 16) | (col[1] << 8) | col[0];
    q.w[1] = 0; q.w[2] = 1; q.w[3] = 0;
    p[0] = q;
    q.w[0] = (u32)(16.0f * uv[0]) + 8;
    q.w[1] = (u32)(16.0f * uv[1]) + 8;
    q.w[2] = 0; q.w[3] = 0;
    p[1] = q;
    q.w[0] = (u32)(16.0f * p0.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p0.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = -1;
    p[2] = q;
    q.w[0] = (u32)(16.0f * uv[0]) + 8;
    q.w[1] = (u32)(16.0f * (uv[1] + uv[3])) - 8;
    q.w[2] = 0; q.w[3] = 0;
    p[3] = q;
    q.w[0] = (u32)(16.0f * p1.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p1.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = -1;
    p[4] = q;
    q.w[0] = (u32)(16.0f * (uv[2] + uv[0])) - 8;
    q.w[1] = (u32)(16.0f * uv[1]) + 8;
    q.w[2] = 0; q.w[3] = 0;
    p[5] = q;
    q.w[0] = (u32)(16.0f * p2.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p2.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = 0;
    p[6] = q;
    q.w[0] = (u32)(16.0f * (uv[2] + uv[0])) - 8;
    q.w[1] = (u32)(16.0f * (uv[3] + uv[1])) - 8;
    q.w[2] = 0; q.w[3] = 0;
    p[7] = q;
    q.w[0] = (u32)(16.0f * p3.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p3.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = 0;
    p[8] = q;
    gUiDrawSbss_0020206C++;
}
#undef gUiGaugeBss_0048C4B0

/* Ui_SetAlphaClamped_0_00182050 */
void Ui_SetAlphaClamped_0_00182050(s32 v)
{
    if (v < 0)
        v = 0;
    if (v > 0x80)
        v = 0x80;
    gUiDrawSdata_00201CD8 = v;
}

/* Ui_DrawSpriteRotated_1_00182080 */
#define gUiGaugeBss_0048C4B0 gUiGaugeBss_0048C4B0__as_Ui_DrawSpriteRotated_1_00182080
extern E gUiGaugeBss_0048C4B0__as_Ui_DrawSpriteRotated_1_00182080[];

void Ui_DrawSpriteRotated_1_00182080(s32 a0, f32 *r, f32 *uv, u8 *col, f32 ang) {
    f32 cx, cy, hw, hh, s, c;
    E *e;
    Q_Ui_DrawSpriteRotated_1_00182080 q;
    if (col[3] < 2) return;
    if (gUiDrawSdata_00201CD4 != a0 || gUiDrawSbss_0020206C >= 16) {
        Ui_BeginSprites_1_00181420();
        gUiDrawSdata_00201CD4 = a0;
    }
    e = gUiGaugeBss_0048C4B0 + gUiDrawSbss_0020206C;
    hw = 0.5f * (r[2] - r[0]);
    hh = 0.5f * (r[3] - r[1]);
    cx = r[0] + hw;
    cy = r[1] + hh;
    s = sinf(ang);
    c = cosf(ang);
    q.w[0] = col[0] | ((col[1] << 8) | ((col[2] << 16) | ((col[3] * gUiDrawSdata_00201CD8 / 128) << 24)));
    q.w[1] = 0;
    q.w[2] = 1;
    q.w[3] = 0;
    e->q[0] = q;
    q.w[0] = (u32)(16.0f * uv[0]) + 8;
    q.w[1] = (u32)(16.0f * uv[1]) + 8;
    q.w[2] = 0;
    q.w[3] = 0;
    e->q[1] = q;
    q.w[0] = (u32)(16.0f * (cx + (c * -hw - s * -hh))) + 0x6C00;
    q.w[1] = (u32)(16.0f * (cy + (s * -hw + c * -hh))) + 0x7200;
    q.w[2] = 0x10;
    q.w[3] = -1;
    e->q[2] = q;
    q.w[0] = (u32)(16.0f * uv[0]) + 8;
    q.w[1] = (u32)(16.0f * (uv[1] + uv[3])) + 8;
    q.w[2] = 0;
    q.w[3] = 0;
    e->q[3] = q;
    q.w[0] = (u32)(16.0f * (cx + (c * -hw - s * hh))) + 0x6C00;
    q.w[1] = (u32)(16.0f * (cy + (s * -hw + c * hh))) + 0x7200;
    q.w[2] = 0x10;
    q.w[3] = -1;
    e->q[4] = q;
    q.w[0] = (u32)(16.0f * (uv[2] + uv[0])) + 8;
    q.w[1] = (u32)(16.0f * uv[1]) + 8;
    q.w[2] = 0;
    q.w[3] = 0;
    e->q[5] = q;
    q.w[0] = (u32)(16.0f * (cx + (c * hw - s * -hh))) + 0x6C00;
    q.w[1] = (u32)(16.0f * (cy + (s * hw + c * -hh))) + 0x7200;
    q.w[2] = 0x10;
    q.w[3] = 0;
    e->q[6] = q;
    q.w[0] = (u32)(16.0f * (uv[2] + uv[0])) + 8;
    q.w[1] = (u32)(16.0f * (uv[3] + uv[1])) + 8;
    q.w[2] = 0;
    q.w[3] = 0;
    e->q[7] = q;
    q.w[0] = (u32)(16.0f * (cx + (c * hw - s * hh))) + 0x6C00;
    q.w[1] = (u32)(16.0f * (cy + (s * hw + c * hh))) + 0x7200;
    q.w[2] = 0x10;
    q.w[3] = 0;
    e->q[8] = q;
    gUiDrawSbss_0020206C++;
}
#undef gUiGaugeBss_0048C4B0

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif
