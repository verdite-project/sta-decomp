#include "common.h"
typedef struct { u8 a, b, c, d; } Q;
typedef struct { char p[0x124]; Q q[16]; u16 m; char r[0x5A]; } E;
extern E gPadState_004B6900[];
void Pad_SetRepeat_3_001D7C08(s32 a, s32 b, u16 mask, u16 x, u16 y) { E *e = &gPadState_004B6900[a * 4 + b]; s32 i; e->m |= mask; for (i = 0; i < 16; i++) { if ((mask >> i) & 1) { e->q[i].a = x; e->q[i].b = y; e->q[i].c = 0; e->q[i].d = 0; } } }

