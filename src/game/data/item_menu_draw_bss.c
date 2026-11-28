#include "common.h"

/* bss_004A1A4C: the game's .bss from 0x004A1A4C, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: equip_draw, equip_reset, hud_draw, item_menu_draw,
   text_0019CEF0.s */

u8 D_004A32AC[0x4];
u8 D_004A32A8[0x4];
u8 D_004A32A4[0x4];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/item_menu_draw.c */
u8 D_004A32A0[0x4];
u8 D_004A329C[0x4];
f32 D_004A3298[0x1];
s32 D_004A3294[0x1];
s32 D_004A3290[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/item_menu_proc_draw_info.c */
u8 D_004A328C[0x4];
u8 D_004A3280[0xc] __attribute__((aligned(4)));
u8 D_004A327C[0x4];
u8 D_004A3264[0x18] __attribute__((aligned(4))); /* also D_004A3268 */
u8 D_004A3250[0x14] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/item_menu_proc_draw_info.c */
s8 D_004A3150[0x100] __attribute__((aligned(4)));
u8 D_004A3140[0x10] __attribute__((aligned(4))); /* also D_004A3144 */
u8 D_004A3130[0x10] __attribute__((aligned(4))); /* also D_004A3134 */
u8 D_004A3120[0x10] __attribute__((aligned(4))); /* also D_004A3124 */
u8 D_004A3110[0x10] __attribute__((aligned(4)));
u8 D_004A3100[0x10] __attribute__((aligned(4)));
u8 D_004A30F0[0x10] __attribute__((aligned(4)));
u8 D_004A30E0[0x10] __attribute__((aligned(4)));
#endif
u8 D_004A30D0[0x10] __attribute__((aligned(4)));
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_draw.c */
u8 D_004A2CE0[0x3f0] __attribute__((aligned(4)));
#endif
u8 D_004A2CD0[0x10] __attribute__((aligned(4)));
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_draw.c */
u8 D_004A28E0[0x3f0] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/equip_draw.c */
u8 D_004A28D0[0x10] __attribute__((aligned(4)));
f32 D_004A28CC[0x1];
s32 D_004A28C8[0x1];
s32 D_004A28C4[0x1];
s32 D_004A28C0[0x1];
#endif
u8 D_004A1A50[0xe70] __attribute__((aligned(4)));
u8 D_004A1A4C[0x4];
