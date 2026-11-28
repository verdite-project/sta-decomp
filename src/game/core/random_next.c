#include "common.h"
#ifndef NONMATCHING
extern s32 gRandomNextSdata_00201C84;
#else
/* data twins (src/game/data/sdata.c): gRandomNextSdata_00201C84 */
static s32 gRandomNextSdata_00201C84 = 0x74915435;
#endif
#ifndef NONMATCHING
extern s32 gRandomNextSdata_00201C88;
#else
/* data twins (src/game/data/sdata.c): gRandomNextSdata_00201C88 */
static s32 gRandomNextSdata_00201C88 = -0x17cacaac;
#endif

s32 Rand_Next_3_0015ED20(void) {
    gRandomNextSdata_00201C84 = gRandomNextSdata_00201C88 + (gRandomNextSdata_00201C84 * 0x85);
    gRandomNextSdata_00201C88 = (gRandomNextSdata_00201C84 * 5) + (gRandomNextSdata_00201C88 * 7);
    return gRandomNextSdata_00201C84 ^ gRandomNextSdata_00201C88;
}
