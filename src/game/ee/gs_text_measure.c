#include "common.h"
#include "game/ee.h"
typedef struct { s32 v[4]; } Q;
typedef struct { u8 pad[8]; u16 x8; } F;
typedef struct { u8 pad[0x28]; F *x28; } A;
typedef struct { u8 pad[0x10]; s16 x10; s16 p12; s16 x14; } Gl;
extern A *gGsText_00201E5C;
extern GsTextStyle *gGsTextStyle_00201E60;
Q *GsText_GetColor_1_001E2D08(Q *);
u16 *GsText_ParseEscape_1_001E2D70(u16 *, Q *);
Gl *GsText_FindGlyph_1_001E3058(s32);

s32 GsText_Measure_2_001E2B88(u16 *s, f32 *w, f32 *h, s32 single) {
    f32 x;
    f32 y;
    Q q;
    u16 c;
    Gl *g;
    y = 0.0f;
    x = y;
    *w = x;
    *h = x;
    y = (gGsText_00201E5C->x28->x8 + gGsTextStyle_00201E60->x64) * gGsTextStyle_00201E60->x34;
    GsText_GetColor_1_001E2D08(&q);
    while ((c = *(s = GsText_ParseEscape_1_001E2D70(s, &q))) != 0) {
        if (c == 10) {
            if (single) return 1;
            x = 0.0f;
            y += (gGsText_00201E5C->x28->x8 + gGsTextStyle_00201E60->x64) * gGsTextStyle_00201E60->x34;
        } else if (q.v[3] == 0) {
            g = GsText_FindGlyph_1_001E3058(c);
            if (g) {
                x += (g->x10 + q.v[1]) * gGsTextStyle_00201E60->x30;
                x += g->x14 * gGsTextStyle_00201E60->x30;
                if (*w < x) *w = x;
                if (*h < y) *h = y;
            }
        }
        s++;
    }
    return 1;
}
