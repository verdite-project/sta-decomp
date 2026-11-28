/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Text_Render_2_00188010.c. The matching build takes it from the assembly that
 * font_load.c includes (INCLUDE_ASM(Text_Render_2_00188010)). */
#ifdef NONMATCHING
#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { u8 m:3; u8 b3:1; u8 b4:1; } BF;
typedef struct {
    f32 x0; f32 x4; BF x8; u8 pad9[3]; s16 xC; u16 xE; u16 x10; u16 x12;
    f32 x14; f32 x18; f32 x1C; f32 x20; f32 x24; u16 *x28;
} T;
typedef struct { f32 x0, x4, x8, xC; u16 x10; u16 x12; u16 x14; u16 x16; } R;
typedef struct { u64 tbp:14; u64 tbw:6; u64 psm:6; u64 tw:4; u64 th:4; u64 rest:30; } TEX;
typedef struct { TEX *n; f32 f[4]; s16 h[4]; Col col; } E;
extern s32 D_002020C0;
extern s32 D_002020C8;
extern f32 D_00201CEC;
extern E D_0048DB60[];
extern TEX *D_0048D350[];
extern u16 D_0048D360[];
void Sjis_ToWide_2_001E5C60(u16 *, s32, u16 *, u16);
f32 Text_MeasureWidth_2_001889E0(u16 *, s16, f32, f32);
R *Font_FindGlyph_2_00188910(s32, u16);
u16 *Text_ParseEscape_1_00188AF0(u16 *, Col *);

static inline f32 u2f(u32 x) { return x; }
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

s32 Text_Render_2_00188010(T *t, Col col) {
    f32 x;
    f32 y;
    s32 ret;
    s32 n;
    u16 c;
    u16 *s;
    u32 cc;
    u8 a;
    R *r;
    f32 f;
    TEX *g;
    E *e;

    y = x = 0.0f;
    ret = 0;
    n = 0;
    s = 0;
    if (t->x10 == 0) return 0;
    if (t->x28 == 0) return 0;
    switch (t->x12) {
    case 0:
        Sjis_ToWide_2_001E5C60(D_0048D360, 0x800, t->x28, t->x10);
        s = D_0048D360;
        break;
    case 1:
        s = t->x28;
        break;
    }
    c = 0xFFFF;
    switch (t->x8.m) {
    case 0: x = 4.0f; break;
    case 1: x = 4.0f - 0.5f * Text_MeasureWidth_2_001889E0(s, t->xC, t->x20, t->x24); break;
    case 2: x = 4.0f - Text_MeasureWidth_2_001889E0(s, t->xC, t->x20, t->x24); break;
    }
    while (c) {
        a = col.c.a;
        s = Text_ParseEscape_1_00188AF0(s, &col);
        c = *s;
        f = t->x18 * (t->x14 - (f32)n * t->x1C);
        if (!(f <= 1.0f)) f = 1.0f;
        if (f < 0.0f) f = 0.0f;
        col.c.a = mu(col.c.a, f);
        if (col.c.a >= 0x80) ret = 1; else ret = 0;
        if (t->x8.b3 == 0) {
            cc = (u16)c;
            if (cc == 10) {
                switch (t->x8.m) {
                case 0: x = 4.0f; break;
                case 1: x = 4.0f - 0.5f * Text_MeasureWidth_2_001889E0(s + 1, t->xC, t->x20, t->x24); break;
                case 2: x = 4.0f - Text_MeasureWidth_2_001889E0(s + 1, t->xC, t->x20, t->x24); break;
                }
                y += 24.0f * t->x20;
                goto next;
            }
        } else {
            cc = (u16)c;
            if (cc == 10) goto next;
        }
        if (t->xE != 0 && !(x <= u2f(t->xE))) {
            switch (t->x8.m) {
            case 0: x = 4.0f; break;
            case 1: x = 4.0f - 0.5f * Text_MeasureWidth_2_001889E0(s, t->xC, t->x20, t->x24); break;
            case 2: x = 4.0f - Text_MeasureWidth_2_001889E0(s, t->xC, t->x20, t->x24); break;
            }
            y += 24.0f * t->x20;
        }
        if (cc != 0) {
            n++;
            r = Font_FindGlyph_2_00188910(D_002020C8, c);
            if (r == 0) r = Font_FindGlyph_2_00188910(D_002020C8, 0xFF1F);
            if (r != 0) {
                Vec v = {0};
                f32 tw, th, u0, v0, du, dv;
                v.x = t->x0 + x;
                v.y = t->x4 + y;
                v.z = t->x0 + x + (D_00201CEC / 22.0f) * (t->x24 * mu(r->x12, t->x20));
                v.w = t->x4 + y + D_00201CEC * t->x20;
                g = D_0048D350[r->x16];
                u0 = r->x0;
                du = r->x8 - u0;
                v0 = r->x4;
                dv = r->xC - v0;
                th = 1 << g->th;
                e = &D_0048DB60[D_002020C0];
                tw = 1 << g->tw;
                e->n = g;
                e->f[0] = v.x;
                e->f[1] = v.y;
                e->f[2] = v.z;
                e->f[3] = v.w;
                e->h[0] = u0 * tw;
                e->h[1] = v0 * th;
                e->h[2] = tw * du - 0.5f;
                e->h[3] = th * dv - 0.5f;
                e->col.w = col.w;
                D_002020C0++;
                if (t->x8.b4) {
                    x += (f32)t->xC;
                } else {
                    x += (f32)(t->xC + 2) + (D_00201CEC / 22.0f) * (t->x24 * mu(r->x14, t->x20));
                }
            }
            col.c.a = a;
            if (t->x8.b3 && cc == 0x3002) {
                switch (t->x8.m) {
                case 0: x = 4.0f; break;
                case 1: x = 4.0f - 0.5f * Text_MeasureWidth_2_001889E0(s, t->xC, t->x20, t->x24); break;
                case 2: x = 4.0f - Text_MeasureWidth_2_001889E0(s, t->xC, t->x20, t->x24); break;
                }
                y += 24.0f * t->x20;
            }
        }
    next:
        s++;
    }
    return ret;
}
#endif
