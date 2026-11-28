#include "common.h"
#include "game/core.h"
#include "game/data.h"
#include "game/input.h"
#include "game/ui.h"
#ifndef NONMATCHING
extern s32 D_00201EA0;
#else
/* data twins (src/game/data/sbss.c): D_00201EA0 */
static s32 D_00201EA0;
#endif
extern u8 D_00222A53[];
s32 Game_GetBusy_0_0012C020(void);
void Game_RequestTitle_0_0012C040(void);
void Menu_SetSubMode_0_0018A330(s32);
s64 Player_GetHpS16_0_001C99C0();

/* Game_GetBusy_0_0012C020 */
s32 Game_GetBusy_0_0012C020(void) {
    return D_00201EA0;
}

/* Game_SetBusy_1_0012C030 */
s32 Game_SetBusy_1_0012C030(s32 arg0) {
    s32 temp_2;

    temp_2 = D_00201EA0;
    D_00201EA0 = arg0;
    return temp_2;
}

/* Game_RequestTitle_0_0012C040 */
void Game_RequestTitle_0_0012C040(void) {
    D_00201EA4 = 0;
    D_00201C28 = 0x29;
    D_00201E9C = 0;
    D_00201EA8 = 2;
    D_00201E98 = 1;
    Vibe_StopAll_1_00160300();
}

/* Game_RequestExit_0_0012C070 */
/* Start a fade: mode 3 when `out`, else 6, and reset the fade flags.
 * cf. KFIV's Game_StartFadeOut (kfiv-decomp src/game/core/game.c). */


void Game_RequestExit_0_0012C070(int out)
{
    if (out)
        D_00201C28 = 3;
    else
        D_00201C28 = 6;
    D_00201EA4 = 0;
    D_00201EA8 = 0;
    D_00201E98 = 1;
    D_00201E9C = 0;
}

/* Game_RequestMode12A_0_0012C0A0 */
/* Enter mode 0x12 with every fade flag set. cf. Game_RequestExit_0_0012C070. */


void Game_RequestMode12A_0_0012C0A0(void)
{
    D_00201C28 = 0x12;
    D_00201EA4 = 1;
    D_00201EA8 = 1;
    D_00201E98 = 1;
    D_00201E9C = 1;
}

/* Game_RequestMode12B_0_0012C0C0 */
/* Enter mode 0x12 with only the third fade flag set. cf. Game_RequestExit_0_0012C070. */


void Game_RequestMode12B_0_0012C0C0(void)
{
    D_00201C28 = 0x12;
    D_00201EA4 = 0;
    D_00201EA8 = 0;
    D_00201E98 = 1;
    D_00201E9C = 0;
}

/* Game_IsNotFlag19A790_0_0012C0E0 */
s32 Game_IsNotFlag19A790_0_0012C0E0(void) { return !Hud_IsHidden_0_0019A790(); }

/* Game_TryRequestEvent_0_0012C110 */
s32 Game_TryRequestEvent_0_0012C110(s32 arg0) {
    if ((((u64) ((s64) (*D_00222A53) << 0x3B) >> 0x3F) != 0) && (((s64) (Player_GetHpS16_0_001C99C0() << 0x30) >> 0x30) <= 0) && (arg0 != 0x28)) {
        return 0;
    }
    if (D_00201EA0 != 0) {
        return 0;
    }
    Menu_SetSubMode_0_0018A330(arg0 & 0xFF);
    return 1;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): D_00201C28 */
s32 D_00201C28 = 1;
/* data twins (src/game/data/sbss.c): D_00201E9C, D_00201EA8 */
s32 D_00201E9C;
s32 D_00201EA8;
#endif
