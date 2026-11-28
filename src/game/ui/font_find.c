#include "m2c.h"
#include "game/ui.h"
typedef struct { u16 lo; u16 hi; u16 idx; } R;
typedef struct { u8 p[0x14]; u16 w; u8 p16[2]; } G;
typedef struct { u8 p[0x10]; u16 n; u8 p12[2]; R *r; G *g; } H;
extern H *gFontLoadSbss_002020C8;
extern f32 gTextRenderSdata_00201CEC;
static inline f32 u2f(u32 x) { return x; }
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

static G *Font_FindGlyph_2_00188910(H *h, u16 c) {
    R *e;
    s32 lo;
    s32 hi;
    s32 mid;
    if (h == NULL) return NULL;
    lo = 0;
    hi = h->n - 1;
    for (;;) {
        mid = (lo + hi) / 2;
        e = &h->r[mid];
        if (c < e->lo) {
            if (!(lo < hi)) break;
            hi = mid - 1;
        } else if (e->hi < c) {
            if (!(lo < hi)) break;
            lo = mid + 1;
        } else {
            return &h->g[e->idx + c - e->lo];
        }
    }
    return NULL;
}

f32 Text_MeasureWidth_2_001889E0(u16 *s, s32 a1, f32 scale, f32 k) {
    f32 w;
    G *g;
    s32 tmp;
    w = 0.0f;
    while (*s != 10 && *s != 0) {
        s = Text_ParseEscape_1_00188AF0(s, (u8 *)&tmp);
        g = Font_FindGlyph_2_00188910(gFontLoadSbss_002020C8, (u32)*s);
        if (g == NULL) g = Font_FindGlyph_2_00188910(gFontLoadSbss_002020C8, 0xFF1F);
        if (g != NULL) {
            w += (f32)(a1 + 2) + (gTextRenderSdata_00201CEC / 22.0f) * (k * mu(g->w, scale));
        }
        s++;
    }
    return w;
}
