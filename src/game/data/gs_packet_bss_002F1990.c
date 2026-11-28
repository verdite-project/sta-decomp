#include "common.h"

/* bss_002F1990: the game's .bss from 0x002F1990, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: gfx_upload, gs_packet, gs_packet_end, screen_fx,
   screen_fx_update, text_001544C0.s, text_00157630.s */

s16 D_002F1A48[0x4];
f32 D_002F19E0[0x1a];
s32 D_002F19DC[0x1];
s32 D_002F19D8[0x1];
u8 D_002F19D4[0x4];
u8 D_002F19C8[0xc]; /* also D_002F19CA, D_002F19CB, D_002F19CC */
u8 D_002F19C4[0x4];
u8 D_002F19C0[0x4];
u8 gWeatherState_002F19B0[0x10];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
u8 D_002F19AC[0x4];
u8 D_002F19A8[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gfx_upload.c */
u32 D_002F19A4[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/gs_packet.c */
u32 D_002F19A0[0x1];
u32 D_002F199C[0x1];
u8 D_002F1998[0x4];
u8 D_002F1994[0x4];
u8 D_002F1990[0x4] __attribute__((aligned(16)));
#endif
