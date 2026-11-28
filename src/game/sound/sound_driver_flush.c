#include "common.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct { s32 a; s32 b; char pad[0x18]; } E;
#ifndef NONMATCHING
extern volatile s32 D_00202308;
#else
/* data twins (src/game/data/sbss.c): D_00202308 */
static volatile s32 D_00202308;
#endif
extern s16 D_0020230C;
extern E D_004B9F20[4];
extern s32 D_004B9FA0[];
void FlushCache(s32 mode);
void* malloc(u32);

/* SndDrv_FlushEffects_0_001D8E70 */
s32 SndDrv_FlushEffects_0_001D8E70(void)
{
    FlushCache(0);
    D_00202308 = 0x3FFF;
    {
        s32 v = D_00202308;
        SndDrv_CallArgs_2_001D8680(5, 1, 0x50000, v, v);
    }
    D_0020230C = 0;
    FlushCache(0);
    return 1;
}

/* SndDrv_SetPortParam_0_001D8EC0 */
void SndDrv_SetPortParam_0_001D8EC0(s32 i, s32 a, s32 b)
{
    if (i < 0 || i >= 4)
        return;
    if (a) {
        D_004B9F20[i].a = a;
        D_004B9F20[i].b = b;
    }
}

/* SndDrv_SetReverb_0_001D8F10 */
void SndDrv_SetReverb_0_001D8F10(s32 a, s32 b, s32 c)
{
    SndDrv_CallArgs_2_001D8680(3, 1, 0x20D0000, a, b, c);
}

/* SndDrv_AllocBuffer_1_001D8F30 */
void SndDrv_AllocBuffer_1_001D8F30(void) {
    if (D_00202318 != 0) return;
    D_00202318 = (s32)malloc(0x8040);
    D_00202310 = (D_00202318 + 0x3F) & ~0x3F;
    D_004B9FA0[0] = 0x40000;
    D_004B9FB0[0] = 0x8000;
    D_004B9FB4[0] = 0x2000;
    D_00202314 = 0x8000;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202318 */
s32 D_00202318;
#endif
