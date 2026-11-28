#include "common.h"
#include "game/ui.h"
#ifndef NONMATCHING
extern f32 D_00201CD0;
#else
/* data twins (src/game/data/sdata.c): D_00201CD0 */
static f32 D_00201CD0 = 16.0f;
#endif

/* Ui_Nop_2_00180F40 */
void Ui_Nop_2_00180F40(void) {

}

/* Ui_SetScrollSpeed_0_00180F50 */
void Ui_SetScrollSpeed_0_00180F50(f32 fparg0) {
    D_00201CD0 = 4.266667f * (fparg0 / 30.0f);
}
