/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/CreditsCb_DrawRect_0_001E4460.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: retail keeps r/uv in their own stack slots (0x10/0x30) and copies them to
 * separate argument temps (0x0/0x20); gcc reuses a slot (frame 0x40 vs 0x50). */
#include "common.h"
typedef struct { s32 x0, y0, x1, y1; } Rect;
typedef struct { f32 u0, v0, u1, v1; } UV;
typedef struct { f32 x, y; u8 pad[0x10]; } Vtx;
typedef struct { u8 pad[0x20]; Vtx v[4]; } Spr;
void Gs_DrawSpriteDirect_0_001E52D0(Rect r, UV uv, Spr *s);

void CreditsCb_DrawRect_0_001E4460(Spr *s) {
    Rect r = { s->v[0].x, s->v[0].y, s->v[1].x, s->v[1].y };
    UV uv = { s->v[2].x, s->v[2].y, s->v[3].x, s->v[3].y };
    Gs_DrawSpriteDirect_0_001E52D0(r, uv, s);
}
#else
INCLUDE_ASM(CreditsCb_DrawRect_0_001E4460);
#endif
