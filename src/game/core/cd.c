#include "common.h"
void memset(s32 *, s32, s32);        /* extern */
s32 sceCdInit(s32);                             /* extern */
void sceCdMmode(s32);                        /* extern */
#ifndef NONMATCHING
extern s32 D_00201F84;
#else
/* data twins (src/game/data/sbss.c): D_00201F84 */
static s32 D_00201F84;
#endif
extern s32 D_002F20C0[];
extern s32 D_0030A0D0[];

void Cd_Init_2_0015B040(s32 arg0, s32 arg1) {
    if ((D_00201F84 == 0) || (arg1 != 0)) {
        if (arg0 != 0) {
            do {

            } while (sceCdInit(0) == 0);
            if (arg0 == 0x100) {
                sceCdMmode(1);
            } else if (arg0 == 0x200) {
                sceCdMmode(2);
            }
        }
        if (D_00201F84 == 0) {
            memset(D_0030A0D0, 0, 0x1C0);
            memset(D_002F20C0, 0, 0x18010);
            D_00201F84 = 1;
        }
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif
