#include "common.h"
#ifndef NONMATCHING
extern s32 D_00201C84;
#else
/* data twins (src/game/data/sdata.c): D_00201C84 */
static s32 D_00201C84 = 0x74915435;
#endif
#ifndef NONMATCHING
extern s32 D_00201C88;
#else
/* data twins (src/game/data/sdata.c): D_00201C88 */
static s32 D_00201C88 = -0x17cacaac;
#endif

s32 Rand_Next_3_0015ED20(void) {
    D_00201C84 = D_00201C88 + (D_00201C84 * 0x85);
    D_00201C88 = (D_00201C84 * 5) + (D_00201C88 * 7);
    return D_00201C84 ^ D_00201C88;
}
