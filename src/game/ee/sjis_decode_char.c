/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Sjis_DecodeChar_2_001E5B18.c.
 * The matching build takes it from the assembly of Gs_UploadTim_1_001E54E8. */
#ifdef NONMATCHING
/* NEAR 11 words (ee-gcc), Shift-JIS decode. Retail copies s to $a2 in the delay slot of the
 * 0x81 test (ours: at entry) and the last case reads the original $a1. A separate p = s
 * pointer gets merged by gcc (21 words); the split of s/p over the cases changes nothing. */
#include "common.h"
extern u16 D_001FE918[][0xBD];
extern u16 D_001F3A60[][0xBD];

u8 *Sjis_DecodeChar_2_001E5B18(u16 *out, u8 *s) {
    u32 c;
    u8 hi;
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
        hi = c - 0x81;
        if ((u8)(*s - 0x40) >= 0xBD) return s;
        *out = D_001FE918[hi][*s];
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
        hi = c - 0xE0;
        if ((u8)(*s - 0x40) >= 0xBD) return s;
        *out = D_001F3A60[hi][*s];
        return s + 1;
    }
    *out = *s;
    return s + 1;
}
#endif
