#include "common.h"

/* bss_0030A0D0: the game's .bss from 0x0030A0D0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: cd, file, light, point_light */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/point_light.c */
f32 gPointLightBss_0030C42C[0x1];
f32 gPointLightBss_0030C428[0x1];
f32 gPointLightBss_0030C424[0x1];
u8 gPointLightBss_0030C420[0x4];
u8 gPointLightBss_0030C3E0[0x40];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/light.c */
u8 gLightBss_0030C3D0[0x10]; /* also D_0030C3D4 */
u8 gLightBss_0030A3C4[0x200c] __attribute__((aligned(4))); /* also D_0030A3C8 */
f32 gLightBss_0030A3C0[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/light.c */
f32 gLightBss_0030A3BC[0x1];
f32 gLightBss_0030A3B8[0x1];
f32 gLightBss_0030A3B4[0x1];
u8 gLightBss_0030A3B0[0x4];
f32 gLightBss_0030A3AC[0x1];
u8 gLightBss_0030A3A0[0xc];
f32 gLightBss_0030A39C[0x1];
u8 gLightBss_0030A390[0xc];
u8 gLightBss_0030A378[0x18] __attribute__((aligned(8))); /* also D_0030A37C */
u8 gLightBss_0030A374[0x4];
u8 gLightBss_0030A370[0x4];
u8 gLightBss_0030A368[0x8];
u8 gLightBss_0030A364[0x4];
u8 gLightBss_0030A360[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/light.c */
u8 gLightBss_0030A350[0x10];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/light.c */
u8 gLightBss_0030A338[0x18] __attribute__((aligned(8))); /* also D_0030A33C */
u8 gLightBss_0030A334[0x4];
u8 gLightBss_0030A330[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/light.c */
u8 gLightBss_0030A320[0x10];
u8 gLightBss_0030A310[0x10];
u8 gLightBss_0030A2D0[0x40];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/light.c */
u8 gLightBss_0030A290[0x40];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/file.c */
u8 gFileBss_0030A0D0[0x1c0];
#endif
