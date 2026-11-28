#include "common.h"

/* data_001F2E80: the game's data at 0x001F2E80..., one object per label. */
/* used by: databook_char_update_wrap, databook_item_draw,
   databook_item_reset, equip_draw, hud_draw, item_menu_draw,
   text_00196330.s, text_001973F0.s, text_0019CEF0.s */
#pragma explicit_zero_data on

extern s32 gDatabookCharUpdateWrapData_001F2E80[];
extern s32 gDatabookItemResetData_001F2F00[];
extern s32 gDatabookItemResetData_001F2F80[];
extern s32 gEquipDrawData_001F3000[];
extern s32 gItemMenuDrawData_001F3080[];

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
s32 gDatabookCharUpdateWrapData_001F2E80[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 gDatabookCharUpdateWrapData_001F2EC0[0x8] = { 0, 5, 0, (s32)gDatabookCharUpdateWrapData_001F2E80, 7, -0x3fc00000, 0, 0 };
f32 gDbCharProcDrawInfoData_001F2EE0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 gDatabookItemResetData_001F2F00[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 gDatabookItemResetData_001F2F40[0x8] = { 0, 5, 0, (s32)gDatabookItemResetData_001F2F00, 7, -0x3fc00000, 0, 0 };
f32 gDbItemProcDrawInfoData_001F2F60[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 gDatabookItemResetData_001F2F80[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 gDatabookItemResetData_001F2FC0[0x8] = { 0, 5, 0, (s32)gDatabookItemResetData_001F2F80, 7, -0x3fc00000, 0, 0 };
f32 gDatabookItemResetData_001F2FE0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 gEquipDrawData_001F3000[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 gEquipDrawData_001F3040[0x8] = { 0, 5, 0, (s32)gEquipDrawData_001F3000, 7, -0x3fc00000, 0, 0 };
s32 gHudDrawData_001F3060[0x1] = { 0 };
f32 gHudDrawData_001F3064[0x2] __attribute__((aligned(4))) = { 10.0f, 0.0f };
s32 gHudDrawData_001F306C[0x1] = { 0 };
s32 gHudDrawData_001F3070[0x1] = { 0 };
f32 gHudDrawData_001F3074[0x2] __attribute__((aligned(4))) = { 10.0f, 0.0f };
s32 gHudDrawData_001F307C[0x1] = { 0 };
s32 gItemMenuDrawData_001F3080[0x10] = { -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0 };
s32 gItemMenuDrawData_001F30C0[0x8] = { 0, 5, 0, (s32)gItemMenuDrawData_001F3080, 7, -0x3fc00000, 0, 0 };
f32 gItemMenuProcDrawInfoData_001F30E0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gItemMenuDrawData_001F3100[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gItemMenuDrawData_001F3120[0x4] = { 0.0f, 0.0f, 640.0f, 480.0f };
f32 gItemMenuDrawData_001F3130[0x4] = { 0.0f, 0.0f, 640.0f, 480.0f };
#endif
