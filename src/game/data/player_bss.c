#include "common.h"

/* bss_0030D9A0: the game's .bss from 0x0030D9A0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: collision_vs, enemy_effect, enemy_model, enemy_reset, fx_proc,
   game_main, glow, glow_fx, item_object, light, lightning, map_area,
   map_area_load, map_object_check, map_state, player, player_se,
   point_light, quat, screen_fx_update, sfx_draw, sfx_system,
   sound_bank_load, text_00148D00.s, text_0014E680.s, text_0014FA30.s,
   text_00151E50.s, text_0015DBF0.s, text_colour */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/text_colour.c */
u8 D_003139A8[0x8];
u8 D_003139A4[0x4];
u8 gZeroVec_003139A0[0x4];
u8 D_0030D9A0[0x6000];
#endif
