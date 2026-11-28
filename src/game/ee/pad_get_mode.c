#include "common.h"

typedef struct {
    char pad[0x7E];
    u8 f;
    char rest[0x141];
} E;
extern E gSoundDriverCallBss_004B6A00[];

u8 Pad_GetMode_0_001D7B18(s32 i, s32 j)
{
    return gSoundDriverCallBss_004B6A00[i * 4 + j].f;
}
