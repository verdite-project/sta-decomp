#include "common.h"
#include "game/data.h"
#include "game/core.h"
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u16 D_00486100[0x400];
static inline u32 gl(u32 **pp, u32 b) {
    if (Bits_Read_2_00179720(pp, 1) == 0) return b + 1;
    if (Bits_Read_2_00179720(pp, 1) == 0) return Bits_Read_2_00179720(pp, 1) + b + 2;
    if (Bits_Read_2_00179720(pp, 1) == 0) return Bits_Read_2_00179720(pp, 3) + b + 4;
    return Bits_Read_2_00179720(pp, 5) + b + 12;
}
static inline u32 gb(u32 **pp, s32 n) {
    u32 r = 0;
    s32 total = n;
    while (n != 0) {
        if (gLzDecompressBSbss_00202028 == 0) {
            gLzDecompressBSbss_00202028 = 32;
            gLzDecompressBSbss_0020202C = **pp;
            (*pp)++;
        }
        if (n < gLzDecompressBSbss_00202028) {
            r |= (gLzDecompressBSbss_0020202C & (0xFFFFFFFF >> (32 - n))) << (total - n);
            gLzDecompressBSbss_00202028 -= (u8)n;
            gLzDecompressBSbss_0020202C >>= n;
            break;
        }
        r |= (gLzDecompressBSbss_0020202C & (0xFFFFFFFF >> (32 - gLzDecompressBSbss_00202028))) << (total - n);
        n -= gLzDecompressBSbss_00202028;
        gLzDecompressBSbss_00202028 = 0;
    }
    return r;
}
static inline void mtf(u32 idx) {
    u16 half;
    u32 v;
    half = idx >> 1;
    v = D_00486100[idx];
    for (; idx != half; idx--) {
        D_00486100[idx] = D_00486100[idx - 1];
    }
    D_00486100[half] = v;
}

s32 Lz_Decompress_2_00179040(u8 *dst0, u8 *in, s32 a2, u32 size) {
    u32 idx;
    u16 off;
    u8 *lit;
    u8 *dst;
    u32 n;
    u32 len;
    u32 *src;
    u16 f;
    u32 i;
    u32 t;
    u16 half;

    dst = dst0;
    off = *(u16 *)(in + 4);
    src = (u32 *)(in + 8);
    n = 0;
    lit = (u8 *)src + off;
    gLzDecompressBSbss_00202028 = 0;
    gLzDecompressBSbss_0020202C = 0;
    for (i = 0; i < 0x400; i++) {
        D_00486100[i] = i + 1;
    }
    while (n < size) {
        f = gb(&src, 1);
        if (f != 0) {
            if (gb(&src, 1) == 0) {
                idx = 0;
                len = gl(&src, 0);
            } else if (gb(&src, 1) == 0) {
                idx = gb(&src, 3) + 1;
                len = gl(&src, 0);
            } else {
                idx = gb(&src, 10) + 9;
                len = gl(&src, 1);
            }
            t = len;
            while (len--) {
                *dst = dst[-*(volatile u16 *)&D_00486100[idx]];
                dst++;
                n++;
            }
            if (idx != 0 && t >= 2) {
                mtf(idx);
            }
        } else {
            *dst++ = *lit++;
            n++;
        }
    }
    return 1;
}
