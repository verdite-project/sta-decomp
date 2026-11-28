#include "game/ee.h"

typedef struct {
    CreditsPoint position;
    f32 z, w;
    u32 color;
    u8 pad14[8];
} AnimVertex;

s32 Credits_EvalAnim_1_001E4900(u32, CreditsEntry *, AnimVertex *);
extern f32 gCreditsLoadBss_004BC2F0[];

void CreditsCb_DrawImage_0_001E41A8(CreditsNode *node) {
    AnimVertex vertices[4];

    if (!Credits_EvalAnim_1_001E4900(gCreditsLoadBss_004BC2F0[0], node->entry, vertices))
        node->skipDraw = 1;
    else
        node->skipDraw = 0;

    node->image.position[0] = vertices[0].position;
    node->image.position[1] = vertices[1].position;
    node->image.position[2] = vertices[2].position;
    node->image.position[3] = vertices[3].position;

    node->image.color[0][0] = vertices[0].color;
    node->image.color[0][1] = vertices[0].color >> 8;
    node->image.color[0][2] = vertices[0].color >> 16;
    node->image.color[0][3] = vertices[0].color >> 24;
    node->image.color[1][0] = vertices[1].color;
    node->image.color[1][1] = vertices[1].color >> 8;
    node->image.color[1][2] = vertices[1].color >> 16;
    node->image.color[1][3] = vertices[1].color >> 24;
    node->image.color[2][0] = vertices[2].color;
    node->image.color[2][1] = vertices[2].color >> 8;
    node->image.color[2][2] = vertices[2].color >> 16;
    node->image.color[2][3] = vertices[2].color >> 24;
    node->image.color[3][0] = vertices[3].color;
    node->image.color[3][1] = vertices[3].color >> 8;
    node->image.color[3][2] = vertices[3].color >> 16;
    node->image.color[3][3] = vertices[3].color >> 24;
}
