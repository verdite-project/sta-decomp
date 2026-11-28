#include "common.h"

/* data_001F2040: the game's data at 0x001F2040..., one object per label. */
/* used by: actor, actor_attachments, actor_bone, attack_trace, draw,
   enemy_list, enemy_model, enemy_reset, fog, fx_proc, fx_proc_random,
   fx_spawn, game_main, glow_fx, item_object_spawn, light, map_area,
   map_area_load, map_command, map_object_check, matrix_from, matrix_lerp,
   model_emit, player, point_light, projectile_target, screen_fx, script_op,
   sfx, sfx_all, sfx_draw, sound_emitter, text_00148D00.s, text_00155090.s,
   text_00160370.s, text_00168480.s, text_00169F40.s, text_0016DC70.s */
#pragma explicit_zero_data on

void ScrCmd_GetArg0_2_00164CC0(void);
void ScrCmd_GetVar_1_00164CE0(void);
void ScrCmd_NopB_2_00164EC0(void);
void ScrCmd_NopC_2_00164ED0(void);
void ScrCmd_NopD_2_00164EF0(void);
void ScrCmd_NopE_2_00164F00(void);
void ScrCmd_Nop_2_00164CD0(void);
void ScrCmd_ResetAllSlots_0_00164E80(void);
void ScrCmd_SendEvent_1_00164EE0(void);
void ScrCmd_SetVar_1_00164DC0(void);

f32 D_001F2040[0x4] = { 0.0f, 0.0f, 0.0f, 1.0f };
f32 D_001F2050[0x4] = { 0.0f, 0.0f, 0.0f, 1.0f };
f32 D_001F2060[0x1] = { 1.0f };
s32 D_001F2064[0x1] = { 0 };
s32 D_001F2068[0x1] = { 0 };
s32 D_001F206C[0x1] = { 0 };
f32 D_001F2070[0x1] = { 2.0f };
s32 D_001F2074[0x1] = { 0 };
f32 D_001F2078[0x1] = { 1.0f };
s32 D_001F207C[0x1] = { 0 };
s32 D_001F2080[0x1] = { 0 };
f32 D_001F2084[0x2] __attribute__((aligned(4))) = { -90.0f, 0.0f };
f32 D_001F208C[0x1] = { 0.7f };
f32 D_001F2090[0x1] = { 0.0f };
f32 D_001F2094[0x2] __attribute__((aligned(4))) = { 0.0f, 0.0f };
f32 D_001F209C[0x9] __attribute__((aligned(4))) = { 0.7f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f };
f32 D_001F20C0[0x1] = { 128.0f };
f32 D_001F20C4[0x1] = { 128.0f };
f32 D_001F20C8[0x2] = { 128.0f, 128.0f };
f32 D_001F20D0[0x1] = { 1.0f };
f32 D_001F20D4[0x1] = { 1.0f };
f32 D_001F20D8[0xa] __attribute__((aligned(8))) = { 1.0f, 128.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2100[0x3] = { 1.0f, 0.0f, 0.0f };
f32 D_001F210C[0x1] = { 128.0f };
f32 D_001F2110[0x1] = { 1.0f };
s32 D_001F2114[0x1] = { 0 };
f32 D_001F2118[0x1] = { 1.0f };
s32 D_001F211C[0x1] = { 0 };
Vec D_001F2120 = { 1.0f, 1.0f, 1.0f, 1.0f };
f32 D_001F2130[0x4] = { 1.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2140[0x4] = { 0.0f, 1.0f, 0.0f, 0.0f };
s32 D_001F2150[0x1] = { 0 };
f32 D_001F2154[0x1] = { 0.0f };
f32 D_001F2158[0x2] = { 1.0f, 0.0f };
f32 D_001F2160[0x4] = { 0.0f, 0.0f, 0.0f, 1.0f };
f32 D_001F2170[0x10] = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
s32 D_001F21B0[0x54] = { (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopD_2_00164EF0, (s32)ScrCmd_NopD_2_00164EF0, (s32)ScrCmd_NopC_2_00164ED0, (s32)ScrCmd_NopB_2_00164EC0, (s32)ScrCmd_ResetAllSlots_0_00164E80, (s32)ScrCmd_SendEvent_1_00164EE0, (s32)ScrCmd_NopD_2_00164EF0, (s32)ScrCmd_SetVar_1_00164DC0, (s32)ScrCmd_GetVar_1_00164CE0, (s32)ScrCmd_Nop_2_00164CD0, (s32)ScrCmd_GetArg0_2_00164CC0, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00, (s32)ScrCmd_NopE_2_00164F00 };
