#include "common.h"
#include "game/ee.h"
u16 *GsText_ParseHex_0_001E2E78(u16 *p, u32 *out) {
    u8 d[8];
    s32 i, t;
    u8 a, b, c, e;
    if ((u16)(*p - 0x100) < 0x100) {
        a = *p++;
        if ((u16)(*p - 0x100) >= 0x100) return p;
        b = *p++;
        if ((u16)(*p - 0x100) >= 0x100) return p;
        c = *p++;
        if ((u16)(*p - 0x100) >= 0x100) return p;
        e = *p++;
        *out = (a << 24) | (b << 16) | (c << 8) | e;
        return p;
    }
    t = HexDigit_3_001E2FF8(*p);
    if (t >= 0) {
        d[0] = t;
        p++;
        for (i = 1; i < 8; i++) {
            t = HexDigit_3_001E2FF8(*p);
            if (t < 0) goto end;
            d[i] = t;
            p++;
        }
        *out = (d[0] << 28) | (d[1] << 24) | (d[2] << 20) | (d[3] << 16) | (d[4] << 12) | (d[5] << 8) | (d[6] << 4) | d[7];
    }
end:
    return p;
}
