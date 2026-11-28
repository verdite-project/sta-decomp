#include "common.h"

typedef struct { char pad[0x174]; u8 b174; u8 b175; char p176[0xC]; u8 b182; char rest[0x3D]; } E;
extern E gPadState_004B6900[];

void Pad_SetRumble_3_001D7D08(s32 i, s32 j, u8 v)
{
    E *e = &gPadState_004B6900[i * 4 + j];
    if (!e->b182) {
        if (v)
            e->b174 = 1;
        else
            e->b174 = 0;
    }
    e->b175 = v;
}
