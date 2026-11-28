/* NEAR: 44/46 instructions match. ee-gcc exchanges the independent stores
 * of u0 and v0 to the temporary UV rectangle at sp+0x30 and sp+0x34. */
#include "game/ee.h"

void *memcpy(void *, const void *, u32);

typedef struct { s32 x, y; } ScreenPoint;
typedef struct { f32 u0, v0, u1, v1; } UvCoords;
typedef union { UvCoords coords; u32 words[4]; } UvPacket;

static inline void setRect(Rect *rect, s32 x0, s32 y0, s32 x1, s32 y1) {
    struct { ScreenPoint first, last; } corners = { {x0, y0}, {x1, y1} };
    memcpy(rect, &corners, sizeof(*rect));
}

void CreditsCb_DrawRect_0_001E4460(CreditsNode *node) {
    Rect rect;

    setRect(&rect, node->image.position[0].x, node->image.position[0].y,
            node->image.position[3].x, node->image.position[3].y);
    {
        f32 u0 = node->image.uv[0].x;
        UvPacket uv;
        UvCoords coords;

        coords.v0 = node->image.uv[0].y;
        coords.u0 = u0;
        coords.u1 = node->image.uv[3].x;
        coords.v1 = node->image.uv[3].y;
        uv.coords = coords;
        Gs_DrawSpriteDirect_0_001E52D0(&rect, uv.words, node);
    }
}
