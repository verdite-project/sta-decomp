/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Script_FindLabel_1_00166970.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 16 of 166 (was 47): switch moved into a static inline skip() (gives the retail join block  top), s32 n, last loop reuses j. Left: key (t8) and xc (t6) swapped; j-counter/ptr-IV regs swapped (v1/a3) in the 0xFFFF0000 search loop. Decl perms (720) and loop forms don't move them. */
#include "m2c.h"
typedef struct { u16 key; u16 off; } Ent;
typedef struct {
    u8 pad[8];
    u32 **x8;
    s32 xC;
    u8 pad10[0x214 - 0x10];
    Ent cache[32];
} S;

static inline u32 *skip(u32 *p, u32 hi, s32 lo) {
    p++;
    switch (hi) {
    case 0x190:
    case 0x191:
    case 0x194:
    case 0x195:
    case 0x197:
        break;
    case 0x192:
        p += (lo >> 8) * 5 + 1;
        break;
    case 0x196:
        p += lo;
        break;
    case 0x19D:
        p += lo + 1;
        break;
    default:
        p += lo * 2;
        break;
    }
    return p;
}

s32 Script_FindLabel_1_00166970(S *a0, u16 key) {
    u32 *p;
    u16 i;
    u16 j;
    s32 xc;
    u32 *base;
    u32 w;
    s32 n;
    u32 off;
    s32 lo;
    u32 hi;

    for (i = 0; i < 32; i++) {
        if (a0->cache[i].key == key) {
            off = a0->cache[i].off << 2;
            for (; i > 0; i--) {
                a0->cache[i] = a0->cache[i - 1];
            }
            a0->cache[0].key = key;
            a0->cache[0].off = off >> 2;
            return a0->xC + off;
        }
    }
    base = *a0->x8;
    xc = a0->xC;
    p = (u32 *)((u8 *)base + xc);
    w = *p;
    if ((w & 0xFFFF0000) == 0xFFFF0000) {
        n = w & 0xFFFF;
        p++;
        for (j = 0; j < n; j++) {
            if (key == (p[j] >> 16)) {
                p += n + *(u16 *)&p[j];
                break;
            }
        }
        if (j == n) return -1;
    } else {
        for (;;) {
            w = *p;
            lo = w & 0xFFFF;
            hi = (w & 0xFFFF0000) >> 16;
            if (hi == 0x190) {
                if (lo == key) break;
                if (lo == 0x7FFE) return -1;
            }
            p = skip(p, hi, lo);
        }
    }
    off = (u8 *)p - (u8 *)base - xc;
    for (j = 31; j > 0; j--) {
        if (a0->cache[j - 1].key) {
            a0->cache[j] = a0->cache[j - 1];
        }
    }
    a0->cache[0].key = key;
    a0->cache[0].off = off >> 2;
    return a0->xC + off;
}
#else
INCLUDE_ASM(Script_FindLabel_1_00166970);
#endif
