#include "common.h"
#include "game/ee.h"

typedef struct { u8 pad[8]; u16 height; } Font;

extern GsTextState *gGsText_00201E5C;
extern GsTextStyle *gGsTextStyle_00201E60;

s32 GsText_Begin_1_001E23C8(void);
void GsText_End_1_001E2430(void);
void GsText_SetPos_1_001E2B18(void *);
s32 GsText_Measure_2_001E2B88(u16 *, f32 *, f32 *, s32);
void GsText_SetColorQ_0_001E2D38(s32 *);
u16 *GsText_ParseEscape_1_001E2D70(u16 *, s32 *);
void *GsText_FindGlyph_1_001E3058(s32);
s32 GsText_EmitGlyph_1_001E3178(void *);

#define AUTO_FLUSH (1ULL << 48)

s32 GsText_DrawString_2_001E2748(f32 *pos, u16 *text)
{
    GsTextColor color;
    f32 width, height, line_height;
    u16 code;
    void *glyph;
    s32 result = 0;

    if (!(gGsText_00201E5C->u.d & AUTO_FLUSH) &&
        gGsText_00201E5C->u.h.b >= gGsText_00201E5C->x14) {
        return 0;
    }
    if (GsText_Begin_1_001E23C8() == -1) {
        return 0;
    }
    GsText_SetPos_1_001E2B18(pos);
    if (gGsTextStyle_00201E60->x5C & 4) {
        GsText_Measure_2_001E2B88(text, &width, &height, 0);
        gGsTextStyle_00201E60->x14 = (s32)(pos[1] - height * 0.5f);
    }
    if (gGsTextStyle_00201E60->x5C & 3) {
        GsText_Measure_2_001E2B88(text, &width, &height, 1);
        if (gGsTextStyle_00201E60->x5C & 1) {
            gGsTextStyle_00201E60->x10 = (s32)(pos[0] - width);
        } else if (gGsTextStyle_00201E60->x5C & 2) {
            gGsTextStyle_00201E60->x10 = (s32)(pos[0] - width * 0.5f);
        }
    }
    color = GsText_GetColor_1_001E2D08();
    line_height = (((Font *)gGsText_00201E5C->x28)->height + gGsTextStyle_00201E60->x64)
                * gGsTextStyle_00201E60->x34;

    while ((code = *(text = GsText_ParseEscape_1_001E2D70(text, color.v))) != 0) {
        GsText_SetColorQ_0_001E2D38(color.v);
        if (code == '\n') {
            gGsTextStyle_00201E60->x10 = gGsTextStyle_00201E60->x0;
            gGsTextStyle_00201E60->x14 += line_height;
            if (gGsTextStyle_00201E60->x5C & 3) {
                GsText_Measure_2_001E2B88(text + 1, &width, &height, 1);
                if (gGsTextStyle_00201E60->x5C & 1) {
                    gGsTextStyle_00201E60->x10 = (s32)(pos[0] - width);
                } else if (gGsTextStyle_00201E60->x5C & 2) {
                    gGsTextStyle_00201E60->x10 = (s32)(pos[0] - width * 0.5f);
                }
            }
        } else {
            glyph = GsText_FindGlyph_1_001E3058(code);
            if (glyph) {
                result = GsText_EmitGlyph_1_001E3178(glyph);
                if (result == 1) {
                    if (gGsText_00201E5C->u.d & AUTO_FLUSH) {
                        /* Keeping the successful result here reproduces the branch delay slots. */
                        result = 1;
                    } else if (gGsText_00201E5C->u.h.b >= gGsText_00201E5C->x14) {
                        break;
                    }
                }
            }
        }
        text++;
    }
    GsText_End_1_001E2430();
    return result;
}
