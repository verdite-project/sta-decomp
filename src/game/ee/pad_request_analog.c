#include "common.h"
typedef struct { char pad[0x17D]; u8 f; char p17E; u8 b17F; s8 b180; char rest[0x3F]; } E;
extern E gPadState_004B6900[];
s32 Pad_RequestAnalog_3_001D7DE8(s32 i, s32 j, s32 v)
{
    E *e = &gPadState_004B6900[i * 4 + j]; if (!(e->f & 1)) return 0; e->b180 = v; e->b17F = 1; return 1;
}
