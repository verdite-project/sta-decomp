#include "common.h"

typedef struct { char pad[0x174]; u8 b174; char p175[0xD]; u8 b182; char rest[0x3D]; } E;
extern E gPadState_004B6900[];

void Pad_SetRumbleLarge_2_001D7D58(s32 i, s32 j, u16 v)
{
    E *e = &gPadState_004B6900[i * 4 + j];
    if (e->b182)
        e->b174 = v;
}
