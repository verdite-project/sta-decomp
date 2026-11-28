#include "common.h"

/* bss_004BA920: the game's .bss from 0x004BA920, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: credits_alloc, credits_cb_draw_image, credits_cb_draw_sprites,
   credits_cb_draw_text, credits_load, credits_run, credits_set_speed,
   credits_setup, credits_step, glow_fx, map_se_load, map_se_stream,
   save_system_start, save_system_step, save_system_update, se, se_dma,
   se_flush, shop_menu, task_callback, task_step, text_001E02C0.s */

s32 D_004BC39C[0x1];
u8 D_004BC398[0x4];
u8 D_004BC394[0x4];
s32 D_004BC390[0x1];
s32 D_004BC38C[0x1];
s32 D_004BC388[0x1];
u8 D_004BC384[0x4];
u8 D_004BC380[0x4];
u8 D_004BC360[0x20]; /* also D_004BC368 */
u8 D_004BC2F0[0x70];
u32 D_004BC2E8[0x2];
u32 D_004BC2E4[0x1];
s32 D_004BC2E0[0x1];
s32 D_004BC2DC[0x1];
s32 D_004BC2D8[0x1];
s32 D_004BC2D4[0x1];
s32 D_004BC2D0[0x1];
u8 D_004BB120[0x11b0]; /* also D_004BB128 */
u8 D_004BB110[0x10]; /* also D_004BB114 */
u8 D_004BB050[0xc0];
u8 D_004BB010[0x40];
u8 D_004BAC80[0x390]; /* also D_004BAC84 */
u8 D_004BAC54[0x2c] __attribute__((aligned(4))); /* also D_004BAC58 */
u8 D_004BAC50[0x4];
u8 D_004BAC4C[0x4]; /* also D_004BAC4D */
s32 D_004BAC48[0x1];
s32 D_004BAC44[0x1];
s32 D_004BAC40[0x1];
u8 D_004BAC3C[0x4];
u8 D_004BAC38[0x4];
s32 D_004BAC34[0x1];
u8 D_004BAC30[0x4];
u8 D_004BAC2C[0x4];
u8 D_004BAC28[0x4];
u8 D_004BAC24[0x4];
u8 D_004BAC20[0x4];
u32 D_004BAC1C[0x1];
f32 D_004BAC10[0x3];
f32 D_004BAC0C[0x1];
u8 D_004BABF4[0x18] __attribute__((aligned(4))); /* also D_004BABF8 */
s8 D_004BABE0[0x14];
u8 D_004BABB0[0x30]; /* also D_004BABC8 */
u32 D_004BABAC[0x1];
f32 D_004BABA0[0x3];
f32 D_004BAB9C[0x1];
u8 D_004BAB84[0x18] __attribute__((aligned(4))); /* also D_004BAB88 */
u8 D_004BAB70[0x14];
u8 D_004BAA70[0x100];
s32 D_004BAA6C[0x1];
u8 D_004BAA68[0x4];
s32 D_004BAA64[0x1];
u8 D_004BAA60[0x4];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se_dma.c */
s32 D_004BAA58[0x2];
s32 D_004BAA54[0x1];
u8 D_004BAA50[0x4];
u8 D_004BAA4C[0x4];
u8 D_004BAA48[0x4];
s32 D_004BAA44[0x1];
s32 D_004BAA40[0x1];
u8 D_004BAA34[0xc] __attribute__((aligned(4))); /* also D_004BAA36 */
s32 D_004BAA30[0x1];
s32 D_004BAA2C[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se.c */
u8 D_004BAA28[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se_dma.c */
s32 D_004BAA24[0x1];
s32 D_004BAA20[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/sound/se.c */
u8 D_004BA920[0x100];
#endif
