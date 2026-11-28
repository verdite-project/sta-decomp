#include "common.h"

/* bss_004AC630: the game's .bss from 0x004AC630, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: item_object, item_object_spawn, map */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
u8 gMapBss_004B4B94[0x4];
u8 gMapBss_004B4B90[0x4];
s32 gItemObjectBss_004B4B88[0x2];
s32 *gItemObjectBss_004B4B84[0x1];
u8 gItemObjectBss_004B4B80[0x4];
s32 gItemObjectBss_004B4B7C[0x1];
s32 gItemObjectBss_004B4B78[0x1];
s32 gItemObjectBss_004B4B74[0x1];
s32 gItemObjectBss_004B4B70[0x1];
s32 gItemObjectBss_004B1770[0xd00];
u8 gItemObjectBss_004AE370[0x3400];
s32 gItemObjectBss_004AD670[0x340];
u8 gItemObjectBss_004AC970[0xd00];
u8 gItemObjectSpawnBss_004AC93C[0x34] __attribute__((aligned(4))); /* also D_004AC93E, D_004AC947, D_004AC94E, D_004AC954 */
u8 gItemObjectSpawnBss_004AC86C[0xd0] __attribute__((aligned(4))); /* also D_004AC86E, D_004AC877, D_004AC87E, D_004AC884 */
u8 gItemObjectSpawnBss_004AC79C[0xd0] __attribute__((aligned(4))); /* also D_004AC79E, D_004AC7A7, D_004AC7AE, D_004AC7B4 */
u8 gItemObjectSpawnBss_004AC6CC[0xd0] __attribute__((aligned(4))); /* also D_004AC6CE, D_004AC6D7, D_004AC6DE, D_004AC6E4 */
u8 gItemObjectSpawnBss_004AC630[0x9c];
#endif
