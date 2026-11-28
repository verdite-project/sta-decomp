#include "common.h"

typedef struct {
    char pad[0x7E];
    u8 f;
    char rest[0x141];
} E;
extern E gSoundDriverCallBss_004B6A00[];

u8 Pad_GetConnected_1_001D7E90(s32 i, s32 j)
{
    return gSoundDriverCallBss_004B6A00[i * 4 + j].f;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sound_driver_call_rodata.c): D_001FE6B8__grp: gPadGetConnectedRodata_001FE6B8@0x0 */
int D_001FE6B8__grp[0x2] __attribute__((aligned(8))) = { 0, 0 };
#endif
