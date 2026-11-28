#include "common.h"
typedef struct { u16 lo, hi, base; } E;
typedef struct { u8 pad[0x10]; u16 n; s32 x14; s32 x18; } H;
typedef struct { u8 pad[0x28]; H *h; } G;
extern G *gGsText_00201E5C;
void exit(s32) __attribute__((noreturn));

u8 *GsText_FindGlyph_1_001E3058(u16 key) {
    s32 lo, hi, mid;
    E *e;
    lo = 0;
    if (gGsText_00201E5C->h == 0) exit(1);
    hi = gGsText_00201E5C->h->n - 1;
    while (1) {
        mid = (lo + hi) / 2;
        e = (E *)((u8 *)gGsText_00201E5C->h + gGsText_00201E5C->h->x14) + mid;
        if (key < e->lo) {
            if (lo >= hi) break;
            hi = mid - 1;
            continue;
        }
        if (key > e->hi) {
            if (lo >= hi) break;
            lo = mid + 1;
            continue;
        }
        return (u8 *)gGsText_00201E5C->h + gGsText_00201E5C->h->x18 + (e->base + key - e->lo) * 0x18;
    }
    return 0;
}
