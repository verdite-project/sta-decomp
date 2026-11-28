#include "common.h"
#include "game/ee.h"
typedef struct { s32 a, b; } P8;
typedef struct { u8 pad[0x1C]; s32 x1C; u8 pad20[8]; void *x28[4]; P8 x38[3]; P8 x50[3]; } G;
extern G gCreditsLoadBss_004BC2F0;
s32 GsText_GetVramOffset_0_001E1FC8(s32);
s32 GsText_PackColor_0_001E1EE0(s32, s32);
s32 Credits_Alloc_1_001E4030(s32, s32);
void GsText_Init_1_001E2018(s32, s32, s32);
void GsText_SetVram_0_001E1F28(s32, s32);
void sceGsSyncPath(s32, s32);
void Credits_Setup_0_001E3DD8(void) {
    s32 i;
    s32 a;
    s32 b;
    a = GsText_GetVramOffset_0_001E1FC8(0);
    b = GsText_PackColor_0_001E1EE0(1, 0x100);
    GsText_Init_1_001E2018(Credits_Alloc_1_001E4030(a, 1), 1, 0x100);
    GsText_SetFlag_0_001E1EA8(1);
    GsText_SetVram_0_001E1F28(Credits_Alloc_1_001E4030(b, 1), b);
    GsText_SetBuffer_0_001E1E70(gCreditsLoadBss_004BC2F0.x1C);
    sceGsSyncPath(0, 0);
    for (i = 0; i < 3; i++) {
        if (gCreditsLoadBss_004BC2F0.x28[i]) {
            Gs_UploadTim_1_001E54E8(gCreditsLoadBss_004BC2F0.x28[i], &gCreditsLoadBss_004BC2F0.x38[i], &gCreditsLoadBss_004BC2F0.x50[i]);
        }
    }
}
