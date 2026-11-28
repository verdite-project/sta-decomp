#include "common.h"

/* bss_002F1120: the game's .bss from 0x002F1120, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: draw, game_main, gfx_upload, gs_packet, gs_packet_end,
   hud_warning, lightning, model_layer, player, screen_fx, sound_emitter,
   text_001544C0.s, text_00155090.s, text_0016BD00.s */

s32 D_002F194C[0x1];
s32 D_002F1948[0x1];
u32 D_002F1944[0x1];
u8 D_002F1940[0x4];
u8 D_002F1900[0x40];
u8 D_002F18C0[0x40];
u8 D_002F1880[0x40];
u8 D_002F1840[0x40];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/game_main.c */
u8 D_002F1800[0x40];
u8 D_002F17C0[0x40];
u8 D_002F1780[0x40];
u8 D_002F1740[0x40];
u8 D_002F1700[0x40];
#endif
u8 D_002F16E4[0x1c] __attribute__((aligned(4))); /* also D_002F16E8 */
u8 D_002F16E0[0x4];
u8 D_002F16D8[0x8];
u8 D_002F16D4[0x4];
u8 D_002F16D0[0x4];
u8 D_002F16C8[0x8];
u8 D_002F16C4[0x4];
u8 D_002F16C0[0x4];
u8 D_002F1694[0x2c] __attribute__((aligned(4))); /* also D_002F1698 */
f32 D_002F1690[0x1];
u8 D_002F1680[0x10];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
u8 D_002F1640[0x40];
u8 D_002F1600[0x40];
#endif
u8 D_002F15E4[0x1c] __attribute__((aligned(4))); /* also D_002F15E8 */
u8 D_002F15E0[0x4];
u8 D_002F15D8[0x8];
u8 D_002F15D4[0x4];
u8 D_002F15D0[0x4];
u8 D_002F15C8[0x8];
u8 D_002F15C4[0x4];
u8 D_002F15C0[0x4];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
u8 D_002F1580[0x40];
u8 D_002F1510[0x70];
u8 D_002F1500[0x10]; /* also D_002F1504 */
#endif
u8 D_002F14F0[0x10];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
u8 D_002F14E0[0x10];
u8 D_002F1490[0x50];
u8 D_002F1420[0x70];
u8 D_002F1410[0x10]; /* also D_002F1414 */
#endif
u8 D_002F1400[0x10];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
u8 D_002F13F0[0x10];
#endif
u8 D_002F13D0[0x20];
u8 D_002F13C8[0x8];
u8 D_002F13A0[0x28]; /* also D_002F13A8 */
u8 D_002F1390[0x10];
u8 D_002F1388[0x8];
u8 D_002F1340[0x48];
u8 D_002F1338[0x8];
u8 D_002F12D4[0x64] __attribute__((aligned(4))); /* also D_002F12D8, D_002F12E8, D_002F1328 */
u8 D_002F12D0[0x4];
u8 D_002F12C8[0x8];
u8 D_002F12C0[0x8];
u8 D_002F12B8[0x8];
u8 D_002F12B0[0x8];
u8 D_002F1250[0x60]; /* also D_002F1298 */
u8 D_002F1248[0x8];
u8 D_002F11E4[0x64] __attribute__((aligned(4))); /* also D_002F11E8, D_002F11F8, D_002F1238 */
u8 D_002F11E0[0x4];
u8 D_002F11D8[0x8];
u8 D_002F11D0[0x8];
u8 D_002F11C8[0x8];
u8 D_002F11C0[0x8];
u8 D_002F1170[0x50]; /* also D_002F1198 */
u8 D_002F1160[0x10];
u8 D_002F1158[0x8];
u8 D_002F1150[0x8];
u8 D_002F1148[0x8];
u8 D_002F1140[0x8];
u8 D_002F113C[0x4];
u8 D_002F1138[0x4];
u8 D_002F1134[0x4];
u8 D_002F1130[0x4];
u8 D_002F112C[0x4];
u8 D_002F1128[0x4];
u8 D_002F1124[0x4];
u8 D_002F1120[0x4] __attribute__((aligned(16)));
