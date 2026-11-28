#include "common.h"

/* sdata_00201B80: the game's data at 0x00201B80..., one object per label. */
/* used by: combat, credits, credits_cb_draw_text, credits_load, databook,
   databook_char_draw, databook_char_list, databook_item_draw,
   databook_item_reset, enemy_list, enemy_manager, enemy_script, equip_draw,
   equip_reset, file, font_find, frame_inc, game_main, game_request,
   gs_packet, gs_text_alloc, gs_text_begin, gs_text_emit_quad,
   gs_text_emit_tag, gs_text_end, gs_text_find_glyph, gs_text_flush_packet,
   gs_text_get_color, gs_text_get_count, gs_text_get_pos, gs_text_init,
   gs_text_kick, gs_text_measure, gs_text_parse_escape, gs_text_print_id,
   gs_text_print_id_at, gs_text_printf, gs_text_printf_at,
   gs_text_reset_state, gs_text_set_align, gs_text_set_buffer,
   gs_text_set_color, gs_text_set_color_idx, gs_text_set_color_q,
   gs_text_set_flag, gs_text_set_flag_a, gs_text_set_flag_b,
   gs_text_set_flag_c, gs_text_set_line_height, gs_text_set_pos,
   gs_text_set_priority, gs_text_set_qword, gs_text_set_range,
   gs_text_set_scale, gs_text_set_scale_uniform, gs_text_set_scale_vec,
   gs_text_set_spacing, gs_text_set_vram, gs_text_wait_dma, hud_draw,
   hud_warning, item_clear, item_menu_draw, map_se_stream, map_sheet,
   map_state, menu, model_emit, movie, noise_fbm, option, option_mode,
   player, player_stat, player_status, random_next, save_byte, save_parse,
   se_dma, se_flush, sfx_all, sfx_system, shop_draw, shop_menu,
   sound_driver_call, sound_emitter, status, storage_draw, text_001679E0.s,
   text_00169F40.s, text_0016BD00.s, text_00188010.s, text_001A4990.s,
   text_001E2748.s, text_001E3178.s, text_001E3758.s, texture_hash,
   timer_init, title, ui_anim, ui_draw, ui_gauge, ui_scroll */
#pragma explicit_zero_data on

extern u8 gOptionRodata_001FCEF0[];
extern u8 gOptionRodata_001FD090[];
extern u8 gDatabookRodata_001FD268[];
extern u8 gCreditsRodata_001FE714[];
extern u8 D_00222A80[];
extern u8 gEquipDrawBss_00495B60[];
extern u8 gEquipDrawBss_00496B60[];
extern u8 D_004A4880[];
extern u8 gOptionModeBss_004A48A0[];
extern u8 D_004A4980[];
extern u8 gSaveByteBss_004A5A60[];
extern u8 gMapStateBss_004AA440[];
extern u8 gPlayerBss_004B4D10[];

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
f32 gGsTextResetStateSdata_00201B80 __attribute__((aligned(16))) = 0.3333333f;
s32 gGsTextEmitGlyphSdata_00201B84[0x1] = { 0x3d7fffff };
f32 gCreditsLoadSdata_00201B88 = 16.666666f;
f32 gCreditsLoadSdata_00201B8C = 33.333332f;
f32 gCreditsCbDrawTextSdata_00201B90[0x1c] = { 0.79999995f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 gGameMainSdata_00201C00[0x4] = { 0x1900000, 0, 0, 0 };
s32 gGameMainSdata_00201C10 = (s32)D_00222A80;
f32 gGameMainSdata_00201C14 = 450.0f;
f32 gGameMainSdata_00201C18 = 1.0f;
f32 gGameMainSdata_00201C1C = 655500.0f;
u32 gGameMainSdata_00201C20 = 1;
u32 gGameMainSdata_00201C24 = 0xffff0;
s32 gGameRequestSdata_00201C28[0x1] = { 1 };
f32 gGameMainSdata_00201C2C = 1.5707964f;
s32 gGameMainSdata_00201C30 = 0xa;
s32 gGameMainSdata_00201C34 = 0x270f;
s32 gSoundEmitterSdata_00201C38[0x2] = { 1, 0 };
s32 gCombatSdata_00201C40[0x2] = { 0x64006400, 0x64006400 };
s32 gCombatSdata_00201C48[0x2] = { 1, 0 };
f32 gEnemyScriptSdata_00201C50[0x2] = { 5000.0f, 0.0f };
s32 gGsPacketSdata_00201C58 = -1;
s32 gGsPacketSdata_00201C5C[0x1] = { -0x80000000 };
f32 gGsPacketSdata_00201C60 = 3000.0f;
f32 gGsPacketSdata_00201C64[0x1] = { 3.141592f };
f32 gGsPacketSdata_00201C68[0x1] = { 3.0f };
f32 gGsPacketSdata_00201C6C[0x1] = { 0.03125f };
f32 gGsPacketSdata_00201C70[0x1] = { 3.141592f };
f32 gGsPacketSdata_00201C74[0x1] = { 3.0f };
f32 gGsPacketSdata_00201C78[0x1] = { 0.03125f };
s32 gFileSdata_00201C7C = 3;
s32 gFrameIncSdata_00201C80 = 0x532525;
s32 gRandomNextSdata_00201C84 = 0x74915435;
s32 gRandomNextSdata_00201C88 = -0x17cacaac;
f32 gNoiseFbmSdata_00201C8C = -1000.0f;
f32 gNoiseFbmSdata_00201C90 = 1.0f;
s32 gNoiseFbmSdata_00201C94 = 1;
s32 gSfxAllSdata_00201C98 = 1;
u16 gSfxAllSdata_00201C9C[0x2] = { 0xffff, 0 };
u16 gSfxSystemSdata_00201CA0[0x2] = { 0xffff, 0 };
u16 gSfxAllSdata_00201CA4[0x2] = { 0xffff, 0 };
s32 gSfxAllSdata_00201CA8 = 0x49535453;
s32 gSfxCreateSdata_00201CAC = 0x61545452;
s32 gSfxSystemSdata_00201CB0 = 0x61495450;
s32 gTextureHashSdata_00201CB4 = 0x43494454;
s32 gSfxAllSdata_00201CB8 = 0x4d584653;
u8 gModelEmitSdata_00201CBC[0x4] = { 0, 0x10, 0x20, 0x40 };
s32 gTimerInitSdata_00201CC0[0x2] = { -1, 0 };
s32 gUiAnimSdata_00201CC8 = -2;
s32 gUiAnimSdata_00201CCC = -2;
f32 gUiScrollSdata_00201CD0 = 16.0f;
s32 gUiDrawSdata_00201CD4 = -1;
s32 gUiDrawSdata_00201CD8 = 0x80;
s32 gUiGaugeSdata_00201CDC = -1;
s32 gUiGaugeSdata_00201CE0 = -1;
s32 gUiGaugeSdata_00201CE4 = -1;
s32 gUiGaugeSdata_00201CE8 = -1;
f32 gTextRenderSdata_00201CEC = 22.0f;
s32 gMenuSdata_00201CF0 = -1;
s32 gMenuSdata_00201CF4 = -1;
s32 gOptionSdata_00201CF8[0x2] = { (s32)((u8 *)gOptionRodata_001FCEF0 + 0x10), (s32)((u8 *)gOptionRodata_001FCEF0 + 0x20) };
s32 gOptionSdata_00201D00[0x2] = { (s32)((u8 *)gOptionRodata_001FD090 + 0x8), (s32)((u8 *)gOptionRodata_001FD090 + 0x10) };
s32 gOptionSdata_00201D08[0x2] = { 2, 0 };
s32 gOptionSdata_00201D10[0x2] = { 0, 1 };
s32 gOptionSdata_00201D18 = 1;
f32 gOptionSdata_00201D1C = -1.0f;
u8 gDatabookSdata_00201D20[0x4] = { 0x19, 0x1a, 0x1b, 0 };
f32 *gDatabookSdata_00201D24 = (f32 *)gEquipDrawBss_00496B60;
s8 *gDatabookSdata_00201D28 = (s8 *)gDatabookRodata_001FD268;
s8 *gDatabookSdata_00201D2C = (s8 *)gDatabookRodata_001FD268;
f32 gDatabookSdata_00201D30 = -2.99f;
f32 gDatabookCharDrawSdata_00201D34 = -2.99f;
s32 gDatabookItemDrawSdata_00201D38 = 6;
s32 gDatabookItemDrawSdata_00201D3C[0x1] = { (s32)gEquipDrawBss_00495B60 };
f32 gDatabookCharListSdata_00201D40 = -2.99f;
f32 gDatabookItemResetSdata_00201D44 = -2.99f;
s32 gEquipDrawSdata_00201D48 = 6;
s32 *gEquipDrawSdata_00201D4C = (s32 *)gEquipDrawBss_00495B60;
f32 *gEquipDrawSdata_00201D50 = (f32 *)gEquipDrawBss_00496B60;
f32 gEquipDrawSdata_00201D54 = -2.99f;
f32 gEquipDrawSdata_00201D58 = -2.99f;
f32 gEquipDrawSdata_00201D5C = -2.99f;
s32 gHudDrawSdata_00201D60 = -1;
s32 gHudDrawSdata_00201D64 = -1;
s32 *gItemMenuDrawSdata_00201D68 = (s32 *)gEquipDrawBss_00495B60;
f32 *gItemMenuDrawSdata_00201D6C = (f32 *)gEquipDrawBss_00496B60;
f32 gItemMenuDrawSdata_00201D70 = -2.99f;
f32 gItemMenuDrawSdata_00201D74 = -300.0f;
f32 gStatusSdata_00201D78 = -2.99f;
s32 *gShopDrawSdata_00201D7C = (s32 *)gEquipDrawBss_00495B60;
f32 *gShopDrawSdata_00201D80 = (f32 *)gEquipDrawBss_00496B60;
f32 gShopDrawSdata_00201D84 = -2.99f;
f32 gShopDrawSdata_00201D88 = -2.99f;
f32 gShopDrawSdata_00201D8C = -2.99f;
f32 gStorageDrawSdata_00201D90 = -2.99f;
s32 gTitleSdata_00201D94 = -1;
f32 gTitleSdata_00201D98 = -20.0f;
f32 gTitleSdata_00201D9C = 30.0f;
s32 gTitleSdata_00201DA0[0x2] = { 0, 1 };
s32 gEnemyMgrUpdateSdata_00201DA8 = -1;
f32 gEnemyListSdata_00201DAC[0x5] __attribute__((aligned(4))) = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s32 gPlayerData_00201DC0[0x1] = { (s32)D_004A4980 };
s32 gSaveByteSdata_00201DC4[0x1] = { (s32)gSaveByteBss_004A5A60 };
s32 gMapStateSdata_00201DC8[0xe] __attribute__((aligned(8))) = { (s32)gMapStateBss_004AA440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
s32 gSaveParseSdata_00201E00[0x4] = { (s32)D_004A4880, 0, 0, 0 };
s32 gOptionModeSdata_00201E10[0x4] = { (s32)gOptionModeBss_004A48A0, 0, 0, 0 };
s32 gPlayerSdata_00201E20[0x1] = { (s32)gPlayerBss_004B4D10 };
s32 gPlayerSdata_00201E24[0x1] = { 0x80 };
u16 gHudWarningSdata_00201E28[0x4] = { 0x6040, 0, 0, 0 };
s32 gPlayerStatusSdata_00201E30[0x2] = { 0x5a, 0x2d };
s32 gSoundDriverCallSdata_00201E38 = -1;
s32 gSeFlushSdata_00201E3C = 1;
u16 gCreditsSdata_00201E40[0x2] = { 2, 0 };
f32 gCreditsSdata_00201E44[0x1] = { -128.0f };
f32 gCreditsSdata_00201E48[0x1] = { -128.0f };
s32 gCreditsSdata_00201E4C = (s32)((u8 *)gCreditsRodata_001FE714 + 0x4);
s32 gShopMenuSdata_00201E50 = -1;
s32 gMapSeStreamSdata_00201E54 = -1;
s32 gGsTextAllocSdata_00201E58 = 0;
s32 gGsText_00201E5C[0x1] = { 0 };
s32 gGsTextStyle_00201E60[0x2] = { 0, 0 };
u16 gCreditsCbDrawTextSdata_00201E68[0x4] = { 0, 0, 0, 0 };
s32 gMovieSdata_00201E70 = 1;
s32 gMovieSdata_00201E74[0x1] = { -0x48ff0000 };
s32 gMapSheetSdata_00201E78[0x2] = { -1, 0 };
#endif
