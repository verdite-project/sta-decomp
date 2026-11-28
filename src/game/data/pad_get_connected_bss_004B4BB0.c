#include "common.h"

/* bss_004B4BB0: the game's .bss from 0x004B4BB0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: hud_marker, map, map_area, player, text_00155090.s,
   text_001B51F0.s, text_001BBCC0.s */

u8 D_004B4D10[0x10a0];
f32 D_004B4D0C[0x1];
f32 D_004B4D08[0x1];
f32 D_004B4D04[0x1];
u8 D_004B4D00[0x4];
u8 D_004B4CF0[0x10];
f32 D_004B4CEC[0x1];
u8 D_004B4CE0[0xc];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
f32 D_004B4CDC[0x1];
u8 D_004B4CD0[0xc];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/player.c */
u8 D_004B4CC0[0x10];
u8 D_004B4CB0[0x10];
u8 D_004B4CA0[0x10];
u8 D_004B4C90[0x10];
u8 D_004B4C80[0x10];
u8 D_004B4C70[0x10];
u8 D_004B4C60[0x10];
u8 D_004B4C50[0x10];
#endif
u8 D_004B4C40[0x10];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_marker.c */
u8 D_004B4BE0[0x60];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gfx_build_view_matrices.c */
f32 D_004B4BD0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/map/map.c */
s32 D_004B4BCC[0x1];
s32 D_004B4BC8[0x1];
s32 D_004B4BC4[0x1];
s32 D_004B4BC0[0x1];
u8 D_004B4BBC[0x4]; /* also D_004B4BBE */
s32 D_004B4BB8[0x1];
s32 D_004B4BB4[0x1];
s32 D_004B4BB0[0x1] __attribute__((aligned(16)));
#endif
