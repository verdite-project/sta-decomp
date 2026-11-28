#include "common.h"

typedef struct {
    char pad[0x20];
    u16 f;
    char rest[0x19E];
} E;
extern E gSoundDriverCallBss_004B6A00[];

u16 Pad_GetStickLY_0_001D7BB8(s32 i, s32 j)
{
    return gSoundDriverCallBss_004B6A00[i * 4 + j].f;
}
