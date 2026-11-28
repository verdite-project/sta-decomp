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

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/pad_get_connected_bss_004B5DD0.c): D_004B6A00__grp: D_004B6A00@0x0, D_004B6A20@0x20, D_004B6A68@0x68 */
u8 D_004B6A00__grp[0xd40] __attribute__((aligned(16)));
#endif
