/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Hud_DrawQuad_1_001BC610.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "m2c.h"
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 col;
    s32 x48;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 pad[0x3];
} Src;
typedef struct { u8 p[3]; u8 : 2; u8 w : 4; } TA;
typedef struct { u64 : 30; u64 w : 4; } TB;
void memset(void *, s32, s32);
void Draw_Sprite_1_00155BD0(Src *);
void Tex_Bind_1_00176B10(void *);
void Hud_DrawQuad_1_001BC610(s16 a, s16 b, s16 c, s16 d, s32 col, s32 f, void *t) {
    Src s;
    memset(&s, 0, 0x50);
    s.col = col;
    s.b0 = 1;
    s.b1 = 0;
    s.b2 = f;
    s.x0 = (a + 0x800) << 4;
    s.x4 = (b + 0x800) << 4;
    s.x10 = (c + 0x800) << 4;
    s.x14 = (d + 0x800) << 4;
    s.x8 = -1;
    s.x18 = -1;
    s.x20 = 0;
    s.x24 = 0;
    if (t) {
        s.x30 = 1 << ((TA *)t)->w << 4;
        s.x34 = 1 << ((TB *)t)->w << 4;
        s.b1 = 1;
        Tex_Bind_1_00176B10(t);
    }
    Draw_Sprite_1_00155BD0(&s);
}
#else
INCLUDE_ASM(Hud_DrawQuad_1_001BC610);
#endif
