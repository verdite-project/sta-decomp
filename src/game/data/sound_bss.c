#include "common.h"

/* bss_00222AF0: the game's .bss from 0x00222AF0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: ending_play, game_main, map_se_load, memory, sfx_system, sound,
   sound_bank_load, sound_bank_step, sound_emitter, sound_start, text.s,
   text_0012F0F0.s, ui_anim */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/sound_bank_load.c */
u8 gSoundBankLoadBss_0022EC48[0x8]; /* also D_0022EC4A */
s32 gSoundBankLoadBss_0022EC44[0x1];
u8 gSoundBankLoadBss_0022EC40[0x4]; /* also D_0022EC41, D_0022EC42, D_0022EC43 */
s32 gSoundBankLoadBss_0022EC3C[0x1];
u8 gSoundBankLoadBss_0022EC20[0x1c]; /* also D_0022EC21, D_0022EC22, D_0022EC28 */
s32 gSoundBankLoadBss_0022EC1C[0x1];
s32 gSoundBankLoadBss_0022EC18[0x1];
u8 gSoundBankLoadBss_0022EC14[0x4]; /* also D_0022EC15, D_0022EC16, D_0022EC17 */
s32 gSoundBankLoadBss_0022EC10[0x1];
Vec gSoundBankLoadBss_0022EC00[0x1];
u8 gSoundBankLoadBss_0022EBE8[0x18] __attribute__((aligned(8))); /* also D_0022EBEC */
u8 gSoundBankLoadBss_0022EBE4[0x4];
s32 gSoundBankLoadBss_0022EBE0[0x1];
u32 gSoundBankLoadBss_0022EBDC[0x1];
u8 gSoundBankLoadBss_0022EBD8[0x4]; /* also D_0022EBD9, D_0022EBDA */
u8 gSoundBankLoadBss_0022EBD0[0x8]; /* also D_0022EBD1, D_0022EBD2, D_0022EBD3 */
u8 gSoundBankLoadBss_0022EBC8[0x8]; /* also D_0022EBC9, D_0022EBCA, D_0022EBCB */
u8 gSoundBankLoadBss_0022EBC0[0x8]; /* also D_0022EBC1, D_0022EBC2, D_0022EBC3 */
u8 gSoundBankLoadBss_0022EB40[0x80];
u8 gSoundBankLoadBss_0022CBC0[0x1f80];
u8 gSoundBankLoadBss_0022CBBC[0x4];
u8 gSoundBankLoadBss_00222BC4[0x9ff8] __attribute__((aligned(4))); /* also D_00222BC5 */
u8 gSoundBankLoadBss_00222BC0[0x4]; /* also D_00222BC1 */
u8 gSoundBankLoadBss_00222B84[0x3c] __attribute__((aligned(4))); /* also D_00222B88 */
s32 gSoundBankLoadBss_00222B80[0x1];
s32 gSoundBankLoadBss_00222B7C[0x1];
s32 gSoundBankLoadBss_00222B78[0x1];
s32 gSoundBankLoadBss_00222B74[0x1];
s32 gSoundBankLoadBss_00222B70[0x1];
void *gSoundBankLoadBss_00222B68[0x2];
s32 gSoundBankLoadBss_00222B64[0x1];
s32 gSoundBankLoadBss_00222B60[0x1];
u8 gSoundBankLoadBss_00222B5C[0x4];
s32 gSoundBankLoadBss_00222B58[0x1];
s32 gSoundBankLoadBss_00222B54[0x1];
u8 gSoundBankLoadBss_00222B50[0x4];
u8 gSoundBankLoadBss_00222B20[0x30];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
u8 gGameMainBss_00222AF0[0x30];
#endif
