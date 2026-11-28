/* NEAR: 44/46 instructions match. ee-gcc exchanges the independent stores
 * of u0 and v0 to the temporary UV rectangle at sp+0x30 and sp+0x34. */
#include "game/ee.h"

void *memcpy(void *, const void *, u32);

typedef struct { f32 x, y; u8 pad08[0x10]; } SpritePoint;
typedef struct { u8 pad00[0x20]; SpritePoint point[4]; } CreditsSprite;
typedef struct { s32 x, y; } ScreenPoint;
typedef struct { f32 u0, v0, u1, v1; } UvCoords;
typedef union { UvCoords coords; u32 words[4]; } UvPacket;

static inline void setRect(Rect *rect, s32 x0, s32 y0, s32 x1, s32 y1) {
    struct { ScreenPoint first, last; } corners = { {x0, y0}, {x1, y1} };
    memcpy(rect, &corners, sizeof(*rect));
}

void CreditsCb_DrawRect_0_001E4460(CreditsSprite *sprite) {
    Rect rect;

    setRect(&rect, sprite->point[0].x, sprite->point[0].y,
            sprite->point[1].x, sprite->point[1].y);
    {
        f32 u0 = sprite->point[2].x;
        UvPacket uv;
        UvCoords coords;

        coords.v0 = sprite->point[2].y;
        coords.u0 = u0;
        coords.u1 = sprite->point[3].x;
        coords.v1 = sprite->point[3].y;
        uv.coords = coords;
        Gs_DrawSpriteDirect_0_001E52D0(&rect, uv.words, (u8 *)sprite);
    }
}
