#include "include_asm.h"

#ifdef NONMATCHING
#include "game/ee.h"

void Credits_BindCallbacks_1_001E4080(CreditsNode *node) {
    CreditsEntry *entry = node->entry;
    u8 *rectKeys = (u8 *)entry + entry->rectOffset;
    u16 *text = (u16 *)((u8 *)entry + entry->textOffset);

    node->rectKeys = rectKeys;
    node->update = CreditsCb_DrawSprites_0_001E4318;
    node->draw = CreditsCb_DrawText_0_001E4518;
    node->colorKeys = (u8 *)entry + entry->colorOffset;
    node->skipDraw = 1;
    node->text = text;
}
#else
INCLUDE_ASM(Credits_BindCallbacks_1_001E4080);
#endif
