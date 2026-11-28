#include "common.h"
#include "game/ee.h"
extern GsTextState *gGsText_00201E5C;
#define BIT 0x1000000000000ULL
void GsText_Kick_1_001E24A0(void) {
    s32 v;
    if (gGsText_00201E5C->x8 != 0) {
        if (gGsText_00201E5C->u.h.b != 0) {
            gGsText_00201E5C->xC -= 0x34;
            if (!(gGsText_00201E5C->u.d & BIT)) {
                gGsText_00201E5C->xC -= 4;
            }
            *gGsText_00201E5C->xC = 0xC;
            if (!(gGsText_00201E5C->u.d & BIT)) {
                (*gGsText_00201E5C->xC)++;
            }
        } else {
            *gGsText_00201E5C->xC = 0;
        }
        if (!(gGsText_00201E5C->u.d & BIT)) *gGsText_00201E5C->xC |= 0x60000000; else *gGsText_00201E5C->xC |= 0x70000000;
        gGsText_00201E5C->xC[1] = 0;
    }
}
