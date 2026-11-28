#include "m2c.h"
typedef union Q { u128 q; struct { u32 a; u32 b; union Q *p; u32 d; } s; u64 d[2]; u32 w[4]; } Q;
extern volatile u32 gGsPacketBss_002F1990[];
extern volatile s32 gGsPacketBss_002F1994[];
extern volatile s32 gGsPacketBss_002F1998[];
extern s8 *gGameMainBss_002F194C[];

void GsPkt_Flush_1_001544C0(void) {
    s32 t;
    Q tag;
    Q save;
    s32 n;
    s32 p;
    s8 *c;

    p = gGsPacketBss_002F1998[0];
    t = (gGsPacketBss_002F1994[0] - p) / 16;
    n = t - 2;
    c = gGameMainBss_002F194C[0];
    save.q = *(u128 *)(c + 0x10);
    tag.q = 0;
    tag.s.a = (n + 1) | 0x20000000;
    tag.s.b = save.s.d;
    tag.w[3] = (n + 1) | 0x51000000;
    *(Q *)p = tag;
    tag.q = 0;
    tag.d[0] = (u64)(u32)n | (0x8000 | ((u64)0x10000000 << 32));
    tag.d[1] = 0xE;
    *(Q *)(gGsPacketBss_002F1998[0] + 0x10) = tag;
    tag = *save.s.p;
    tag.s.b = gGsPacketBss_002F1990[0] & 0x0FFFFFFF;
    *save.s.p = tag;
    save.s.p = (Q *)gGsPacketBss_002F1990[0];
    *(u128 *)(c + 0x10) = save.q;
    gGsPacketBss_002F1998[0] = 0;
    gGsPacketBss_002F1990[0] = gGsPacketBss_002F1994[0];
}
