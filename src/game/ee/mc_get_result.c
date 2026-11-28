#include "common.h"
#ifndef NONMATCHING
extern s32 D_004B644C[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): D_004B644C */
static s32 D_004B644C[0x1];
#endif

s32 Mc_GetResult_1_001D7098(void) {
    return (*D_004B644C);
}
