#include "common.h"
typedef struct { char pad[0x48]; s32 x48; char pad2[0x34]; u16 x80; } T;
extern T *gGsTextStyle_00201E60;
u16 *GsText_ParseHex_0_001E2E78(u16 *, s32 *);

u16 *GsText_ParseEscape_1_001E2D70(u16 *p, s32 *st)
{
    u16 c;
loop:
    c = *p;
    if (c != gGsTextStyle_00201E60->x80 || c == 0) return p;
    p++;
    if (*p == c) return p;
    switch (*p) {
    case 'C': p = GsText_ParseHex_0_001E2E78(p + 1, st); goto loop;
    case 'c': st[0] = gGsTextStyle_00201E60->x48; p++; goto loop;
    case 'B': st[1] = 1; p++; goto loop;
    case 'b': st[1] = 0; p++; goto loop;
    case 'I': st[2] = 1; p++; goto loop;
    case 'i': st[2] = 0; p++; goto loop;
    case 'R': st[3] = 1; p++; goto loop;
    case 'r': st[3] = 0; p++; goto loop;
    default: return p;
    }
}
