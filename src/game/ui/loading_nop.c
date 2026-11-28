#include "common.h"

/* Both paths finish the callback. MWCC retains the state load and constant. */
void Loading_Nop_0_0018E440(s32 *state) {
    if (*(const volatile s32 *)state == 0x16) {
        return;
    }
}
