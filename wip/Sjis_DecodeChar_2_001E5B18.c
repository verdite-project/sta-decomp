/* NEAR: 71 of 82 instructions match. ee-gcc copies the input pointer before
 * testing for NUL and uses that copy for the final single-byte case. */
#include "common.h"
extern const u16 gSjisTable81_001FE998[31][0xBD];
extern const u16 gSjisTableE0_001F3AE0[11][0xBD];

u8 *Sjis_DecodeChar_2_001E5B18(u16 *out, u8 *s) {
    u32 c;
    u8 row;

    *out = -1;
    c = *s;
    if (*(s8 *)s == 0) {
        *out = 0;
        return 0;
    }
    if ((u8)c < 0x81) {
        *out = *s;
        return s + 1;
    }
    if ((u8)c < 0xA0) {
        s++;
        row = c - 0x81;
        if ((u8)(*s - 0x40) >= 0xBD) return s;
        *out = gSjisTable81_001FE998[row][*s - 0x40];
        return s + 1;
    }
    if ((u8)c < 0xA1) {
        *out = *s;
        return s + 1;
    }
    if ((u8)c < 0xE0) {
        *out = *s - 0x140;
        return s + 1;
    }
    if ((u8)c < 0xEB) {
        s++;
        row = c - 0xE0;
        if ((u8)(*s - 0x40) >= 0xBD) return s;
        *out = gSjisTableE0_001F3AE0[row][*s - 0x40];
        return s + 1;
    }
    *out = *s;
    return s + 1;
}
