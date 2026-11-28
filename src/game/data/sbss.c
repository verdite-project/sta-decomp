#include "common.h"

/* sbss_00201E80: the game's .sbss from 0x00201E80, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: actor, actor_attachments, actor_bone, actors, attack_play, bgm,
   bits, cd, chest, collision, collision_test, combat, credits, databook,
   databook_char_draw, databook_char_update_wrap, databook_item_draw,
   databook_item_reset, door, draw, ending_draw, ending_play, enemy_ai,
   enemy_global, enemy_list, enemy_manager, enemy_model, enemy_reset,
   enemy_script, enemy_state, equip_draw, equip_reset, file, font_draw,
   font_find, font_load, fx, fx_eval, fx_proc, fx_spawn, game_main,
   game_over_reset, game_over_update, game_request, gfx_upload, glow,
   glow_fx, gs_packet, gs_packet_end, hud_draw, hud_marker, hud_warning, iop,
   item_menu_draw, item_object, item_object_spawn, light, load_menu,
   load_menu_draw, loading_draw, loading_visible, lz_decompress, map,
   map_area, map_area_load, map_capsule, map_collision, map_command,
   map_free, map_object, map_object_all, map_object_find, map_object_sfx,
   map_raycast, map_se_load, map_se_stream, map_sheet, memory, menu,
   menu_draw, menu_proc, message, model_animate, model_draw, model_emit,
   model_layer, model_load, movie, option, option_lerp, pause_menu_entry,
   pause_menu_open, play_time, player, player_flag, player_se, player_stats,
   player_status, projectile_target, resource, save_menu, save_menu_slot,
   save_system_start, save_system_step, save_system_update, screen_fx,
   screen_fx_draw, screen_fx_flash, screen_fx_model, screen_fx_update,
   script, script_command, script_event, se, se_dma, se_flush, sfx, sfx_all,
   sfx_draw, sfx_system, shop_draw, shop_menu, sound, sound_bank_load,
   sound_driver_call, sound_driver_flush, sound_emitter, sound_start, stream,
   task_all, task_callback, task_run, task_step, text_001329D0.s,
   text_00145A80.s, text_00148D00.s, text_0014FA30.s, text_00151E50.s,
   text_00155090.s, text_00157630.s, text_00160370.s, text_001679E0.s,
   text_00168480.s, text_0016BD00.s, text_0016DC70.s, text_001777C0.s,
   text_001787C0.s, text_001797E0.s, text_00185D70.s, text_00188010.s,
   text_00196330.s, text_001973F0.s, text_001A4990.s, text_001A7D90.s,
   text_001A8510.s, text_001AE510.s, text_001B0EB0.s, text_001B51F0.s,
   text_001B9F10.s, text_001BBCC0.s, text_001E8C50.s, texture, texture_anim,
   timer_init, timer_ticks, title, trap, ui_anim, ui_draw, ui_gauge,
   ui_global */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ending_draw.c */
u8 D_00202420[0x60];
f32 D_0020241C;
f32 D_00202418;
f32 D_00202414;
s32 D_00202410;
f32 D_0020240C;
f32 D_00202408;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/map_sheet.c */
f32 D_00202404;
#endif
s32 D_00202400;
s32 D_002023FC;
s32 D_002023F8;
s32 D_002023F4;
s32 D_002023F0;
s32 D_002023EC;
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_step.c */
s32 D_002023E8;
u8 D_002023E4[0x4];
s32 D_002023E0;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_start.c */
u8 D_002023DC[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_step.c */
s32 D_002023D8;
s32 D_002023D4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_start.c */
s32 D_002023D0;
s32 D_002023CC;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_step.c */
s32 D_002023C8;
s32 D_002023C4;
s32 D_002023C0;
s32 D_002023BC;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_start.c */
s32 D_002023B8;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/save/save_system_step.c */
s32 D_002023B4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/map_se_stream.c */
u8 D_002023B0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/glow_fx.c */
u8 D_002023AC[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/task_callback.c */
s32 D_002023A8;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/play_time.c */
u8 D_002023A0[0x8]; /* also D_002023A5, D_002023A6, D_002023A7 */
u8 D_00202398[0x8]; /* also D_00202399, D_0020239A, D_0020239B, D_0020239D */
u8 D_00202390[0x8];
u8 D_00202388[0x8];
u8 D_00202380[0x8]; /* also D_00202385, D_00202386, D_00202387 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/shop_menu.c */
s32 D_0020237C;
u8 D_00202378[0x4];
u8 D_00202370[0x8];
f32 D_0020236C;
f32 D_00202368;
f32 D_00202364;
f32 D_00202360;
f32 D_0020235C;
s32 D_00202358;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/credits.c */
u8 D_00202354[0x4]; /* also D_00202356 */
u8 D_00202350[0x4]; /* also D_00202352 */
u8 D_00202348[0x8];
f32 D_00202344;
s32 D_00202340;
u8 D_0020233C[0x4];
f32 D_00202338;
u8 D_00202334[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se_dma.c */
s32 D_00202330;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se.c */
s32 D_0020232C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se_flush.c */
u8 D_00202328[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se.c */
s32 D_00202324;
s32 D_00202320;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/bgm.c */
s32 D_0020231C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_driver_flush.c */
s32 D_00202318;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/bgm.c */
u8 D_00202314[0x4];
u8 D_00202310[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/stream.c */
u8 D_0020230C[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_driver_flush.c */
s32 D_00202308;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_driver_call.c */
u8 D_00202300[0x8];
s32 D_002022FC;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player_se.c */
s32 D_002022F8;
s32 D_002022F4;
u8 D_002022F0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
s32 D_002022EC;
f32 D_002022E8;
u8 D_002022E4[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_warning.c */
s32 D_002022E0;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
f32 D_002022DC;
s32 D_002022D8;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/map_object/map_object_all.c */
u8 D_002022D4[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/map/map_area_load.c */
u8 D_002022D0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gfx_build_view_matrices.c */
u8 D_002022C0[0x10]; /* also D_002022C4 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
u8 D_002022BC[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound.c */
u8 D_002022B8[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/map/map_area_load.c */
s32 D_002022B4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/item/item_object.c */
u8 D_002022B0[0x4];
u8 D_002022A0[0x10]; /* also D_002022A4 */
u8 D_00202290[0x10];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/item/item_object_spawn.c */
s32 D_0020228C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/item/item_object.c */
u8 D_00202288[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_model.c */
u8 D_00202284[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_list.c */
u8 D_00202280[0x4];
u8 D_00202278[0x8];
s32 D_00202274;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
s32 D_00202270;
s32 D_0020226C;
s32 D_00202268;
f32 D_00202264;
s32 D_00202260;
s32 D_0020225C;
s32 D_00202258;
s32 D_00202254;
s32 D_00202250;
s32 D_0020224C;
s32 D_00202248;
s32 D_00202244;
s32 D_00202240;
s32 D_0020223C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/shop_draw.c */
s32 D_00202238;
s32 D_00202234;
s32 D_00202230;
f32 D_0020222C;
f32 D_00202228;
s32 D_00202224;
s32 D_00202220;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/game_over_reset.c */
u8 D_0020221C[0x4];
s32 D_00202218;
s32 D_00202214;
s32 D_00202210;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/game_over_update.c */
s32 D_0020220C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/pause_menu_entry.c */
s32 D_00202208;
s32 D_00202204;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/item_menu_draw.c */
s32 D_00202200;
s32 D_002021FC;
s32 D_002021F8;
s32 D_002021F4;
s32 D_002021F0;
s32 D_002021EC;
s32 D_002021E8;
s32 D_002021E4;
s32 D_002021E0;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_draw.c */
s32 D_002021DC;
s32 D_002021D8;
u8 D_002021D0[0x8];
s32 D_002021CC;
f32 D_002021C8;
f32 D_002021C4;
s32 D_002021C0;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/equip_draw.c */
f32 D_002021BC;
f32 D_002021B8;
s32 D_002021B4;
s32 D_002021B0;
s32 D_002021AC;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook_item_reset.c */
s32 D_002021A8;
u32 D_002021A4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook_item_draw.c */
f32 D_002021A0;
f32 D_0020219C;
s32 D_00202198;
s32 D_00202194;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook_item_reset.c */
u32 D_00202190;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook_char_update_wrap.c */
s32 D_0020218C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/db_char_proc_draw_info.c */
s32 D_00202188;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook_char_update_wrap.c */
u32 D_00202184;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook.c */
s8 *D_00202180;
u8 D_0020217C[0x4];
s32 *D_00202178;
u8 D_00202174[0x4];
s32 *D_00202170;
s8 *D_0020216C;
s8 *D_00202168;
u8 D_00202164[0x4];
u8 D_00202160[0x4];
u8 D_0020215C[0x4];
#endif
u8 D_00202158[0x4];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook.c */
s32 D_00202154;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ending_play.c */
s32 *D_00202150;
s32 *D_0020214C;
s32 D_00202148;
s32 D_00202144;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/load_menu.c */
s32 D_00202140;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/load_menu_draw.c */
f32 D_0020213C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option_lerp.c */
s32 D_00202138;
s32 D_00202134;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_00202130;
u8 D_0020212C[0x4]; /* also D_0020212F */
s32 D_00202128;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_proc.c */
s32 D_00202120[0x2];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu_slot.c */
f32 D_0020211C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/message.c */
s32 D_00202118;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu.c */
f32 D_00202114;
f32 D_00202110;
f32 D_0020210C;
f32 D_00202108;
f32 D_00202104;
s32 D_00202100;
u8 D_002020F8[0x8];
u8 D_002020F0[0x8];
u8 D_002020E8[0x8];
u8 D_002020E0[0x8];
u8 D_002020DC[0x4];
f32 D_002020D8;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_draw.c */
f32 D_002020D4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/font_load.c */
s32 D_002020D0;
u8 D_002020CC[0x4];
u8 D_002020C8[0x4];
s32 D_002020C4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_draw.c */
s32 D_002020C0;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_gauge.c */
f32 D_002020BC;
f32 D_002020B8;
f32 D_002020B4;
f32 D_002020B0;
u8 D_002020AC[0x4];
u8 D_002020A8[0x4];
f32 D_002020A4;
f32 D_002020A0;
u8 D_0020209C[0x4];
u8 D_00202098[0x4];
u8 D_00202094[0x4];
u8 D_00202090[0x4];
u8 D_0020208C[0x4];
u8 D_00202088[0x4];
f32 D_00202084;
s32 D_00202080;
s32 D_0020207C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_proc_draw_weight.c */
u8 D_00202078[0x4];
u8 D_00202074[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_global.c */
s32 D_00202070;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_draw.c */
s32 D_0020206C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/font_draw.c */
void *D_00202068;
s32 D_00202064;
s32 D_00202060;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_anim.c */
f32 D_0020205C;
f32 D_00202058;
f32 D_00202054;
f32 D_00202050;
s32 D_0020204C;
u8 D_00202048[0x4];
s32 D_00202044;
u8 D_00202040[0x4];
s32 D_0020203C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/script/map_command.c */
s32 D_00202038;
u8 D_00202034[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/map_object/door.c */
u8 D_00202030[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/lz_decompress_b.c */
u32 D_0020202C;
u8 D_00202028[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/timer_init.c */
u8 D_00202024[0x4];
#endif
s32 D_00202020;
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/timer_init.c */
u8 D_0020201C[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/tex_resident.c */
u8 D_00202018[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture.c */
u8 D_00202010[0x8];
s32 D_0020200C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_emit.c */
u8 D_00202008[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_layer.c */
s32 D_00202004;
s32 D_00202000;
s32 D_00201FFC;
s32 D_00201FF8;
s32 D_00201FF4;
s32 D_00201FF0;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture_anim.c */
s32 D_00201FEC;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_system.c */
u8 D_00201FE8[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
s32 D_00201FE4;
u8 D_00201FE0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/fx_spawn.c */
u8 D_00201FDC[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_system.c */
u8 D_00201FD8[0x4];
u8 D_00201FD4[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
u8 D_00201FD0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_system.c */
u8 D_00201FC0[0x10];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
u8 D_00201FB0[0x10];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_system.c */
u32 D_00201FAC;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_script.c */
u8 D_00201FA8[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/script/script_event.c */
u8 D_00201FA4[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/fx.c */
u8 D_00201FA0[0x4];
s32 D_00201F9C;
s32 D_00201F98;
u8 D_00201F94[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
s32 D_00201F90;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/file.c */
s32 D_00201F8C;
s32 D_00201F88;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/cd.c */
s32 D_00201F84;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/file.c */
u8 D_00201F80[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx_update.c */
u8 D_00201F78[0x8];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gfx_build_view_matrices.c */
u8 D_00201F74[0x4];
u8 D_00201F70[0x4];
u8 D_00201F6C[0x4];
u8 D_00201F68[0x4];
u8 D_00201F64[0x4];
u8 D_00201F60[0x4];
u8 D_00201F5C[0x4];
u8 D_00201F58[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/mdl_emit_strip_d.c */
u32 D_00201F54;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_emit.c */
u8 D_00201F50[0x4];
u8 D_00201F4C[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_draw.c */
s32 D_00201F48;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gfx_upload.c */
u8 D_00201F44[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_draw_billboard.c */
u8 D_00201F40[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/draw.c */
s32 D_00201F3C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gfx_upload.c */
u8 D_00201F38[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
u8 D_00201F34[0x4];
u8 D_00201F30[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
s32 D_00201F2C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
s32 D_00201F28;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/collision/coll_sweep_segments_init.c */
s32 D_00201F24;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/task_run.c */
s32 D_00201F20;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_global.c */
u8 D_00201F1C[0x4];
u8 D_00201F18[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/entity/actors.c */
u8 D_00201F14[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_ai.c */
u8 D_00201F10[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx_begin.c */
u8 D_00201F0C[0x4];
u8 D_00201F08[0x4];
u8 D_00201F04[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx_draw.c */
u32 D_00201F00;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx_begin.c */
u8 D_00201EFC[0x4];
u8 D_00201EF8[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx_draw.c */
u32 D_00201EF4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx_begin.c */
u32 D_00201EF0;
u8 D_00201EEC[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_emitter.c */
s32 D_00201EE8;
u8 D_00201EE4[0x4];
#endif
u8 D_00201EE0[0x4]; /* also D_00201EE2 */
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_emitter.c */
u8 D_00201ED8[0x8];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound.c */
u8 D_00201ED4[0x4]; /* also D_00201ED5, D_00201ED6, D_00201ED7 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_emitter.c */
u8 D_00201ED0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_bank_load.c */
u8 D_00201EC0[0x10]; /* also D_00201EC4 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_start.c */
u8 D_00201EBC[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
u8 D_00201EB8[0x4];
f32 D_00201EB4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
s32 D_00201EB0;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
s32 D_00201EAC;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_request.c */
s32 D_00201EA8;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
s32 D_00201EA4;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_request.c */
s32 D_00201EA0;
s32 D_00201E9C;
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
s32 D_00201E98;
u8 D_00201E94[0x4];
f32 D_00201E90;
#endif
u8 D_00201E8C[0x4];
u8 D_00201E88[0x4];
u8 D_00201E80[0x8] __attribute__((aligned(16)));
