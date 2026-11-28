#include "common.h"

typedef struct {
    char pad[0x82];
    u8 f;
    char rest[0x13D];
} E;
extern E D_004B6A00[];

void Pad_SetEnabled_0_001D7D90(s32 i, s32 j, u8 v)
{
    D_004B6A00[i * 4 + j].f = v;
}

