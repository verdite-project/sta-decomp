#include "game/ee.h"
typedef struct { u8 b[8]; } B8;
typedef struct { u8 pad[0x2C]; s8 x2C; } O;
typedef struct { u8 p0[4]; O *x4; u8 p8[0x10]; u16 *x18; s32 x1C; f32 x20; f32 x24; u8 p28[8]; u8 x30[4]; u8 x34; u8 p35[0xB]; B8 x40[8]; } T;
typedef struct { f32 x0; u8 p4[0xC]; u32 x10; u8 p14[0x5C]; } Buf;
typedef struct { f32 x0; u8 p4[0x6C]; f32 x70; f32 x74; } G;
extern G gCreditsLoadBss_004BC2F0;
s32 Credits_EvalAnim_1_001E4900(u32, O *, Buf *);

void CreditsCb_DrawSprites_0_001E4318(CreditsNode *node) {
    T *p = (T *)node;
    Buf buf;
    s32 i;
    if (Credits_EvalAnim_1_001E4900(gCreditsLoadBss_004BC2F0.x0, p->x4, &buf) == 0) {
        p->x1C = 1;
        return;
    }
    p->x1C = 0;
    if (p->x4->x2C != 0) {
        *(B8 *)&p->x20 = *(B8 *)&buf;
    } else {
        p->x20 = (*p->x18 == 10) ? buf.x0 : gCreditsLoadBss_004BC2F0.x70;
        p->x24 = gCreditsLoadBss_004BC2F0.x74;
    }
    if (!(p->x34 & 1)) {
        p->x34 |= 1;
        for (i = 0; i < 8; i++) {
            p->x40[i] = *(B8 *)&p->x20;
        }
    }
    p->x30[0] = buf.x10;
    p->x30[1] = buf.x10 >> 8;
    p->x30[2] = buf.x10 >> 16;
    p->x30[3] = buf.x10 >> 24;
}
