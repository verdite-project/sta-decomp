#include "common.h"

extern f32 gAngleBBss_00270560[629];
f32 cosf(f32 x);

void CosTable_Init_3_00146C00(void)
{
    s32 i;
    for (i = 0; i < 629; i++)
        gAngleBBss_00270560[i] = cosf(0.0099891657f * i);
}
