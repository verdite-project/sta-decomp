#include "m2c.h"
#include "game/data.h"
#include "game/ui.h"
typedef struct { u128 q[2]; } Q2;
typedef UiArg Arg;
typedef struct { s32 x0; } Ev;
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void PauseMenu_Update_0_0019E400(Ev *);
void PauseMenu_GetEntry_0_0019E780(void);
extern Q2 gPauseMenuOpenData_001F31C0;
extern s32 gPauseMenuOpenData_001F3160[];
extern f32 D_004A32CC[];

void PauseMenu_Open_0_0019E2F0(Ev *arg0) {
    Q2 q;
    Arg a;

    switch (arg0->x0) {
    case 0x19:
        gPauseMenuEntryBss_004A32C8[0] = 0;
        gPauseMenuEntrySbss_00202208 = 0;
        q = gPauseMenuOpenData_001F31C0;
        a.p = (s32)gPauseMenuOpenData_001F3160;
        a.n = 5;
        a.fn = PauseMenu_GetEntry_0_0019E780;
        a.f = -3.0f;
        a.a = 0;
        a.b = 0;
        a.cb = 0;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 1);
        UiAnim_SetTarget_1_0017F470(gPauseMenuEntryBss_004A32C8[0], 0, 1);
        break;
    case 0x16:
        if (!(D_004A32CC[0] <= 0.0f)) {
            D_004A32CC[0] -= 1.0f;
        } else {
            PauseMenu_Update_0_0019E400(arg0);
        }
        break;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 gPauseMenuOpenData_001F3180[];
extern u8 gPauseMenuOpenData_001F3220[];
/* data group (src/game/data/pause_menu_open_data.c): D_001F3160__grp: gPauseMenuOpenData_001F3160@0x0, gPauseMenuOpenData_001F3180@0x20, gPauseMenuOpenData_001F31C0@0x60, gPauseMenuOpenData_001F31E0@0x80, gPauseMenuOpenData_001F3200@0xa0, gPauseMenuOpenData_001F3210@0xb0, gPauseMenuOpenData_001F3220@0xc0, gPauseMenuOpenData_001F3260@0x100 */
s32 D_001F3160__grp[0x48] __attribute__((aligned(16))) = { 0, 1, 2, 3, 4, 0, 0, 0, -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0, 0, 5, 0, (s32)gPauseMenuOpenData_001F3180, 7, -0x3fc00000, 0, 0, 0x3f800000, 0, 0, 0x3f800000, 0, 0, 0, 0, 0, 0, 0x44200000, 0x43e00000, 0, 0, 0x43000000, 0x43000000, -0x3fc00000, 0xfa6, -0x40000000, 0xfa5, -0x40800000, 0xfa4, 0, 0xfa3, 0x3f800000, 0xfa2, 0x40000000, 0xfa1, 0x40400000, 0xfa0, 0, 0, 0, 5, 0, (s32)gPauseMenuOpenData_001F3220, 7, -0x3fc00000, 0, 0 };
#endif
