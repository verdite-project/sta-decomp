#include "common.h"
#include "game/data.h"

u32 Bits_Read_2_00179720(u32 **pp, s32 n) {
    u32 r = 0;
    s32 total = n;
    u8 left;
    while (n != 0) {
        if (gLzDecompressBSbss_00202028 == 0) {
            gLzDecompressBSbss_00202028 = 32;
            gLzDecompressBSbss_0020202C = **pp;
            (*pp)++;
        }
        left = gLzDecompressBSbss_00202028;
        if (n < left) {
            r |= (gLzDecompressBSbss_0020202C & (0xFFFFFFFF >> (32 - n))) << (total - n);
            gLzDecompressBSbss_00202028 = left - (u8)n;
            gLzDecompressBSbss_0020202C >>= n;
            return r;
        }
        r |= (gLzDecompressBSbss_0020202C & (0xFFFFFFFF >> (32 - left))) << (total - n);
        gLzDecompressBSbss_00202028 = 0;
        n -= left;
    }
    return r;
}
