#include "common.h"

typedef struct {
    char pad[0x68];
    s32 f;
    char rest[0x154];
} E;
extern E gSoundDriverCallBss_004B6A00[];

s32 Pad_GetButtons_1_001D7AF0(s32 i, s32 j)
{
    return gSoundDriverCallBss_004B6A00[i * 4 + j].f;
}
