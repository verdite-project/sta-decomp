#include "common.h"

typedef struct { char pad[0x164]; u16 flags; char rest[0x5A]; } E;
extern E gPadState_004B6900[];

void Pad_ClearRepeat_3_001D7C80(s32 i, s32 j, u16 v)
{
    E *e = &gPadState_004B6900[i * 4 + j];
    e->flags &= ~v;
}
