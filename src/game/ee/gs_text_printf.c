#include "common.h"
#include "game/ee.h"
extern GsTextState *gGsText_00201E5C;
extern u8 *gGsTextStyle_00201E60;
void vsnprintf(char *, s32, const char *, void *);
void Sjis_ToWide_2_001E5C60(s32, s32, char *, s32);
void GsText_DrawString_2_001E2748(u8 *, s32);
/* passes the a1..a7 register save area (va_list contents); gcc va_start keeps an extra struct */
void GsText_Printf_1_001E2578(const char *fmt, ...) {
    char buf[0x200];
    vsnprintf(buf, 0x1FF, fmt, (char *)__builtin_next_arg(fmt) - 0x38);
    buf[0x1FF] = 0;
    Sjis_ToWide_2_001E5C60(gGsText_00201E5C->x134, 0x100, buf, -1);
    GsText_DrawString_2_001E2748(gGsTextStyle_00201E60 + 0x10, gGsText_00201E5C->x134);
}
