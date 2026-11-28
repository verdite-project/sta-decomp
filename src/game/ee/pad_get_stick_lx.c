#include "common.h"

typedef struct {
    char pad[0x2];
    u16 f;
    char rest[0x1BC];
} E;
extern E gSoundDriverCallBss_004B6A00[];

u16 Pad_GetStickLX_0_001D7B90(s32 i, s32 j)
{
    return gSoundDriverCallBss_004B6A00[i * 4 + j].f;
}
