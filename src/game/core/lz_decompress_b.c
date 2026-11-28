/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Lz_DecompressB_1_001797E0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
extern u8 D_00202028;
extern u32 D_0020202C;
/* Lz_DecompressB_1_001797E0( */

static u32 Bits_Read_2_00179720(u32 **pp, s32 n) {
    u32 r = 0;
    s32 total = n;
    u8 left;
    while (n != 0) {
        if (D_00202028 == 0) {
            D_00202028 = 32;
            D_0020202C = **pp;
            (*pp)++;
        }
        left = D_00202028;
        if (n < left) {
            r |= (D_0020202C & (0xFFFFFFFF >> (32 - n))) << (total - n);
            D_00202028 = left - (u8)n;
            D_0020202C >>= n;
            return r;
        }
        r |= (D_0020202C & (0xFFFFFFFF >> (32 - left))) << (total - n);
        D_00202028 = 0;
        n -= left;
    }
    return r;
}

static inline u32 getbits(u32 **pp, s32 n) {
    s32 total = n;
    u32 r = 0;
    u8 left;
    while (n != 0) {
        if (D_00202028 == 0) {
            D_00202028 = 32;
            D_0020202C = **pp;
            (*pp)++;
        }
        left = D_00202028;
        if (n < left) {
            r |= (D_0020202C & (0xFFFFFFFF >> (32 - n))) << (total - n);
            D_00202028 = left - (u8)n;
            D_0020202C >>= n;
            return r;
        }
        r |= (D_0020202C & (0xFFFFFFFF >> (32 - left))) << (total - n);
        D_00202028 = 0;
        n -= left;
    }
    return r;
}

static inline s32 getlen(u32 **pp) {
    if (!Bits_Read_2_00179720(pp, 1)) return 1;
    if (!Bits_Read_2_00179720(pp, 1)) return Bits_Read_2_00179720(pp, 1) + 2;
    if (!Bits_Read_2_00179720(pp, 1)) return Bits_Read_2_00179720(pp, 3) + 4;
    return Bits_Read_2_00179720(pp, 5) + 12;
}

s32 Lz_DecompressB_1_001797E0(u8 *dst, u8 *hdr, s32 a2, u32 size) {
    u32 *src;
    u8 *raw;
    u32 count;
    s32 off;
    s32 len;

    count = 0;
    src = (u32 *)(hdr + 8);
    raw = (u8 *)src + *(u16 *)(hdr + 4);
    D_00202028 = 0;
    D_0020202C = 0;
    while (count < size) {
        if ((u16)getbits(&src, 1) != 0) {
            if (getbits(&src, 1) == 0) {
                off = 0;
                len = getlen(&src);
            } else if (getbits(&src, 1) == 0) {
                off = getbits(&src, 3) + 1;
                len = getlen(&src);
            } else {
                off = getbits(&src, 10) + 9;
                len = getlen(&src) + 1;
            }
            while (len--) {
                *dst = *(dst - (off + 1));
                count++;
                dst++;
            }
        } else {
            *dst++ = *raw++;
            count++;
        }
    }
    return 1;
}
#else
INCLUDE_ASM(Lz_DecompressB_1_001797E0);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202028, D_0020202C */
u8 D_00202028;
u32 D_0020202C;
#endif
