#include "common.h"

extern f32 D_00270560[];

f32 Angle_Wrap2PiB_2_00146B90(f32 a)
{
    a -= 6.2831855f * (s32)(a / 6.2831855f);
    if (a < 0.0f)
        a += 6.2831855f;
    return D_00270560[(s32)(100.0f * a)];
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/angle_b_bss.c): D_00270560 */
f32 D_00270560[0x278];
#endif
