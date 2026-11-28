/* NEAR 8 of 263 words (unchanged). `fb = p->x20 * hh` mult1 dest v1 (retail a0 = hh reg), so x0 raw lands in a0 instead of v1. Declaration order (300 random perms) has no effect; tried inline mul helpers, s32 fa/fb, s16/u32 x0, volatile reads, b38, per-axis inlines. */
#include "actor.h"
typedef struct { s32 x0, x4, x8; f32 xC, x10, x14, x18; s32 x1C, x20, x24; u8 c[4]; } P;
typedef struct { u64 tbp:14; u64 tbw:6; u64 psm:6; u64 tw:4; u64 th:4; u64 rest:30; } Tex;
typedef struct { u8 p0[0x448]; Tex *x448[2]; } Q;
extern P gHudMarkerBss_004B4BE0[];
extern s32 gHudWarningSbss_002022E0;
s32 Game_GetFlag54b6_0_001A9410(void);
void GsPkt_BeginAD_3_001545D0(void);
void GsPkt_SetReg_3_001543E0(s32, s32);
void GsPkt_Flush_1_001544C0(void);
void Hud_DrawQuad_1_001BC610(s32, s32, s32, s32, u32, s32, Tex *);
static inline Q *cur(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (Q *)(gPlayerSbss_002022E4->unk518 + 0x180);
}
static inline f32 u2f(u32 x) { return x; }

void Hud_DrawCompass_0_001BBCC0(void) {
    Q *q;
    u32 col;
    s32 i;
    P *p;
    f32 f;
    u8 a;
    Tex *t;
    f32 lim;
    s16 hw;
    s16 hh;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    f32 fa;
    f32 fb;
    f32 g;

    q = cur();
    if (q == 0) return;
    if (!Game_GetFlag54b6_0_001A9410()) return;
    for (i = 0, p = gHudMarkerBss_004B4BE0; i < 2; i++, p++) {
        if (p->x4 != 0) continue;
        if (p->x0 <= 0) continue;
        f = p->x0 / 55.0f;
        f = f * (f * f);
        if (p->x0 < 0x38) {
            g = u2f(p->c[3]); a = g * f;
        } else {
            a = p->c[3];
        }
        col = a << 24 | p->c[2] << 16 | p->c[1] << 8 | p->c[0];
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x44);
        GsPkt_Flush_1_001544C0();
        if (i == 0 && p->x0 > 0x39) {
            Hud_DrawQuad_1_001BC610(-0x140, (s32)(-224.0f + gHudWarningSbss_002022E0), 0x140, (s32)(224.0f - gHudWarningSbss_002022E0),
                          ((3 - (60 - p->x0)) * 16 / 3) << 24 | p->c[2] << 16 | p->c[1] << 8 | p->c[0], 1, 0);
        }
        t = q->x448[p->x24];
        hw = (s32)(0.5f * ((1 << t->tw) * p->x14));
        hh = (s32)(0.5f * ((1 << t->th) * p->x18));
        fa = p->x1C * hw;
        x0 = (s16)(s32)(p->xC - fa);
        fb = p->x20 * hh;
        x1 = (s16)(s32)(p->xC + fa);
        y0 = (s16)(s32)(p->x10 - fb);
        lim = -224.0f + gHudWarningSbss_002022E0;
        y1 = (s16)(s32)(p->x10 + fb);
        if (y0 < lim) y0 = (s16)(s32)lim;
        if (!(y0 <= 224.0f - gHudWarningSbss_002022E0)) y0 = (s16)(s32)(224.0f - gHudWarningSbss_002022E0);
        if (y1 < lim) y1 = (s16)(s32)lim;
        if (!(y1 <= 224.0f - gHudWarningSbss_002022E0)) y1 = (s16)(s32)(224.0f - gHudWarningSbss_002022E0);
        Hud_DrawQuad_1_001BC610(x0, y0, x1, y1, col, 1, t);
    }
}
