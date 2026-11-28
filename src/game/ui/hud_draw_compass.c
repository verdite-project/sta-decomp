#include "actor.h"
#include "game/ui.h"

typedef struct { s32 x0, x4, x8; f32 xC, x10, x14, x18; s32 x1C, x20, x24; u8 rgba[4]; } HudMarker;
typedef struct { u64 tbp:14; u64 tbw:6; u64 psm:6; u64 tw:4; u64 th:4; u64 rest:30; } TextureInfo;
typedef struct { u8 pad00[0x448]; TextureInfo *x448[2]; } CompassState;
extern HudMarker gHudMarkerBss_004B4BE0[];
extern s32 gHudWarningSbss_002022E0;
s32 Game_GetFlag54b6_0_001A9410(void);
void GsPkt_BeginAD_3_001545D0(void);
void GsPkt_SetReg_3_001543E0(u32, u64);
void GsPkt_Flush_1_001544C0(void);

static inline CompassState *getCompassState(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (CompassState *)(gPlayerSbss_002022E4->unk518 + 0x180);
}
static inline f32 u2f(u32 x) { return x; }

void Hud_DrawCompass_0_001BBCC0(void) {
    CompassState *state;
    u32 color;
    s32 i;
    HudMarker *marker;
    f32 fade;
    u8 alpha;
    TextureInfo *texture;
    f32 top;
    s16 halfWidth;
    s16 halfHeight;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 xOffset;
    s32 yOffset;
    f32 opacity;

    state = getCompassState();
    if (state == 0) return;
    if (!Game_GetFlag54b6_0_001A9410()) return;
    for (i = 0, marker = gHudMarkerBss_004B4BE0; i < 2; i++, marker++) {
        if (marker->x4 != 0) continue;
        if (marker->x0 <= 0) continue;
        fade = marker->x0 / 55.0f;
        fade = fade * (fade * fade);
        if (marker->x0 < 0x38) {
            opacity = u2f(marker->rgba[3]);
            alpha = opacity * fade;
        } else {
            alpha = marker->rgba[3];
        }
        color = (u32)alpha << 24 | marker->rgba[2] << 16 | marker->rgba[1] << 8 | marker->rgba[0];
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x44);
        GsPkt_Flush_1_001544C0();
        if (i == 0 && marker->x0 > 0x39) {
            Hud_DrawQuad_1_001BC610(-0x140, (s32)(-224.0f + gHudWarningSbss_002022E0), 0x140, (s32)(224.0f - gHudWarningSbss_002022E0),
                          ((3 - (60 - marker->x0)) * 16 / 3) << 24 | marker->rgba[2] << 16 | marker->rgba[1] << 8 | marker->rgba[0], 1, 0);
        }
        texture = state->x448[marker->x24];
        halfWidth = (s32)(0.5f * ((1 << texture->tw) * marker->x14));
        halfHeight = (s32)(0.5f * ((1 << texture->th) * marker->x18));
        xOffset = marker->x1C * halfWidth;
        x0 = (s16)(s32)(marker->xC - xOffset);
        yOffset = marker->x20 * halfHeight;
        y0 = (s16)(s32)(marker->x10 - yOffset);
        x1 = (s16)(s32)(marker->xC + xOffset);
        top = -224.0f + gHudWarningSbss_002022E0;
        y1 = (s16)(s32)(marker->x10 + yOffset);
        if (y0 < top) y0 = (s16)(s32)top;
        if (!(y0 <= 224.0f - gHudWarningSbss_002022E0)) y0 = (s16)(s32)(224.0f - gHudWarningSbss_002022E0);
        if (y1 < top) y1 = (s16)(s32)top;
        if (!(y1 <= 224.0f - gHudWarningSbss_002022E0)) y1 = (s16)(s32)(224.0f - gHudWarningSbss_002022E0);
        Hud_DrawQuad_1_001BC610(x0, y0, x1, y1, color, 1, texture);
    }
}
