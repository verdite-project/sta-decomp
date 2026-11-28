/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Input_Update_2_0015F540.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
typedef struct {
    u16 x0; u16 x2; u16 x4; u16 x6; u16 x8; u16 xA;
    f32 xC; f32 x10; f32 x14; f32 x18;
    f32 x1C[12];
    u8 pad4C[7];
    u8 r53:6; u8 mode:2;
    u8 x54;
    u8 pad55[3];
} P;
typedef struct { u8 pad0[2]; u16 x2; u8 x4; u8 x5; u8 x6; u8 x7; u8 x8[12]; u8 pad14[0xC]; u16 x20; u16 x22; } Q;
extern P gMenuBss_00317230[];
void memset(void *, s32, s32);
s32 Pad_GetButtons_1_001D7AF0(u32, s32);
s32 Pad_GetConnected_1_001D7E90(u32, s32);
void Pad_RequestAnalog_3_001D7DE8(u32, s32, s32);
void Pad_IsAnalog_1_001D7E38(u32, s32);
Q *Pad_GetRecord_1_001D7B68(u32, s32);
s32 func_00120570(s32);

static inline void clr(P *p) {
    if (p) {
        p->x0 = 0;
        p->x2 = 0;
        p->x4 = 0;
        p->x6 = 0;
        p->x8 = 0;
        p->xA = 0;
        p->xC = 0.0f;
        p->x10 = 0.0f;
        p->x14 = 0.0f;
        p->x18 = 0.0f;
        memset(p->x1C, 0, 0x30);
    }
}

static inline f32 conv(s16 v) {
    s16 d;
    v = v - 0x7F;
    if (func_00120570(v) < 30) return 0.0f;
    if (v > 0x80) v = 0x7F;
    if (v < -0x80) v = -0x7F;
    d = v < 0 ? 30 : -30;
    v = v + d;
    return v / 97.0f;
}

void Input_Update_2_0015F540(u32 n) {
    P *p;
    Q *q;
    u32 i;
    s32 r;

    p = &gMenuBss_00317230[n];
    if (p->x54 > 0) {
        clr(p);
        p->x54--;
        return;
    }
    if (Pad_GetButtons_1_001D7AF0(n, 0) != 6) {
        clr(p);
        return;
    }
    switch (r = Pad_GetConnected_1_001D7E90(n, 0)) {
    case 0:
        Pad_RequestAnalog_3_001D7DE8(n, 0, 3);
        clr(p);
        p->x54 = 10;
        return;
    case 1:
        Pad_IsAnalog_1_001D7E38(n, 0);
        clr(p);
        p->x54 = 10;
        return;
    case 2:
        p->mode = r;
        break;
    default:
        clr(p);
        return;
    }
    if (p->mode != 0xFF && p->x54 == 0) {
        q = Pad_GetRecord_1_001D7B68(n, 0);
        p->x2 = p->x0;
        p->x0 = q->x2;
        p->x8 = q->x20;
        p->xA = q->x22;
        p->x6 = p->x2;
        p->x4 = p->x0;
        if (p->mode == 1 || p->mode == 2) {
            p->xC = conv(q->x4);
            p->x10 = conv(q->x5);
            p->x14 = conv(q->x6);
            p->x18 = conv(q->x7);
        } else {
            p->xC = 0.0f;
            p->x10 = 0.0f;
            p->x14 = 0.0f;
            p->x18 = 0.0f;
        }
        for (i = 0; i < 12; i++) {
            if (p->mode == 2) {
                f32 f;
                s16 v = q->x8[i];
                if (v < 0) {
                    f = 0.0f;
                } else if (v > 240) {
                    f = 1.0f;
                } else {
                    f = v / 239.0f;
                }
                p->x1C[i] = f;
            } else {
                p->x1C[i] = 0.0f;
            }
        }
    } else {
        p->x2 = 0;
        p->x0 = 0;
        p->x8 = 0;
        p->xA = 0;
        p->x6 = p->x2;
        p->x4 = p->x0;
        p->xC = 0.0f;
        p->x10 = 0.0f;
        p->x14 = 0.0f;
        p->x18 = 0.0f;
        for (i = 0; i < 12; i++) {
            p->x1C[i] = 0.0f;
        }
        if (p->x54) p->x54--;
    }
}
#else
INCLUDE_ASM(Input_Update_2_0015F540);
#endif
