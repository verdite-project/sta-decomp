#include "game/ee.h"

void Credits_ParseHeader_0_001E40D0(CreditsNode *node) {
    CreditsEntry *entry = node->entry;
    u8 *rectKeys, *imageResource;
    f32 coord;

    rectKeys = (u8 *)entry + entry->rectOffset;
    imageResource = (u8 *)entry + entry->imageOffset;
    node->update = CreditsCb_DrawImage_0_001E41A8;
    node->draw = CreditsCb_DrawRect_0_001E4460;
    node->skipDraw = 1;
    node->rectKeys = rectKeys;
    node->imageResource = imageResource;

    coord = (f32)entry->imageUv.x / 1000.0f;
    node->image.uv[2].x = coord;
    node->image.uv[0].x = coord;
    coord = (f32)(entry->imageUv.x + entry->imageUv.width) / 1000.0f;
    node->image.uv[3].x = coord;
    node->image.uv[1].x = coord;
    coord = (f32)entry->imageUv.y / 1000.0f;
    node->image.uv[1].y = coord;
    node->image.uv[0].y = coord;
    coord = (f32)(entry->imageUv.y + entry->imageUv.height) / 1000.0f;
    node->image.uv[3].y = coord;
    node->image.uv[2].y = coord;
}
