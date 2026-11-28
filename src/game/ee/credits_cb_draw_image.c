#include "common.h"
typedef struct { u8 b[8]; } B8;
typedef struct { B8 a; u8 pad8[8]; u32 x10; u8 pad14[8]; } E;
typedef struct { u8 pad0[4]; void *h; u8 pad8[0x14]; s32 x1C; B8 a[4]; u8 v[4][4]; } O;
s32 Credits_EvalAnim_1_001E4900(u32, void *, E *);
extern f32 gCreditsLoadBss_004BC2F0[];

void CreditsCb_DrawImage_0_001E41A8(O *o)
{
    E buf[4];

    if (!Credits_EvalAnim_1_001E4900(gCreditsLoadBss_004BC2F0[0], o->h, buf))
        o->x1C = 1;
    else
        o->x1C = 0;
    o->a[0] = buf[0].a;
    o->a[1] = buf[1].a;
    o->a[2] = buf[2].a;
    o->a[3] = buf[3].a;
    o->v[0][0] = buf[0].x10; o->v[0][1] = buf[0].x10 >> 8; o->v[0][2] = buf[0].x10 >> 16; o->v[0][3] = buf[0].x10 >> 24;
    o->v[1][0] = buf[1].x10; o->v[1][1] = buf[1].x10 >> 8; o->v[1][2] = buf[1].x10 >> 16; o->v[1][3] = buf[1].x10 >> 24;
    o->v[2][0] = buf[2].x10; o->v[2][1] = buf[2].x10 >> 8; o->v[2][2] = buf[2].x10 >> 16; o->v[2][3] = buf[2].x10 >> 24;
    o->v[3][0] = buf[3].x10; o->v[3][1] = buf[3].x10 >> 8; o->v[3][2] = buf[3].x10 >> 16; o->v[3][3] = buf[3].x10 >> 24;
}

