#include "common.h"

/* bss_002F1A60: the game's .bss from 0x002F1A60, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: cd, file, screen_fx, screen_fx_update, text_00157630.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/file.c */
u8 gFileBss_002F20C0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx.c */
f32 gScreenFxBss_002F20BC[0x1];
f32 gScreenFxBss_002F2080[0xf];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx.c */
u8 gScreenFxBss_002F2078[0x8];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx.c */
u8 gScreenFxBss_002F2070[0x8];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/weather_draw.c */
u8 gWeatherDrawBss_002F1F10[0x160];
u8 gWeatherDrawBss_002F1DB0[0x160];
u8 gWeatherDrawBss_002F1C50[0x160];
u8 gWeatherDrawBss_002F1AF0[0x160];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/weather_draw.c */
u8 gWeatherDrawBss_002F1AEC[0x4];
u8 gWeatherDrawBss_002F1AE8[0x4];
u8 gWeatherDrawBss_002F1AE4[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx.c */
s32 gScreenFxBss_002F1AE0[0x1];
u8 gScreenFxBss_002F1AD0[0x10]; /* also D_002F1AD4 */
u8 gScreenFxBss_002F1AC0[0x10];
u8 gScreenFxBss_002F1AB0[0x10];
u8 gScreenFxBss_002F1AA0[0x10];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx.c */
u8 gScreenFxBss_002F1A9C[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/screen_fx.c */
u8 gScreenFxBss_002F1A80[0x1c];
u8 gScreenFxBss_002F1A78[0x8]; /* also D_002F1A7A, D_002F1A7B, D_002F1A7D, D_002F1A7E, D_002F1A7F */
u8 gScreenFxBss_002F1A74[0x4]; /* also D_002F1A76 */
u8 gScreenFxBss_002F1A70[0x4]; /* also D_002F1A72 */
u8 gScreenFxBss_002F1A6C[0x4]; /* also D_002F1A6E */
u8 gScreenFxBss_002F1A68[0x4]; /* also D_002F1A69, D_002F1A6A, D_002F1A6B */
u8 gScreenFxBss_002F1A64[0x4]; /* also D_002F1A66 */
u8 gScreenFxBss_002F1A60[0x4] __attribute__((aligned(16)));
#endif
