#include "common.h"
typedef struct { char pad[0x178]; u64 f; } E0;
typedef struct { char pad[0x17F]; u8 a; s8 b; char rest[0x3F]; } E;
extern E gPadState_004B6900[];
#define F(e) (((E0 *)(e))->f)

s32 Pad_IsAnalog_1_001D7E38(s32 i, s32 j) {
    E *e = &gPadState_004B6900[i * 4 + j];
    if ((F(e) & 0xFF040000000000) == 0x1000000000000) return 0;
    e->a = 2;
    return 1;
}

