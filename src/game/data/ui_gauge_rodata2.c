#include "common.h"

/* rodata_001FCB80: the game's data at 0x001FCB80..., one object per label. */
/* used by: font_load, menu_draw, menu_proc, save_menu_slot, ui_gauge */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_gauge.c */
const s8 gUiGaugeRodata_001FCB80[0x8] __attribute__((aligned(16))) = "%d\000\000\000\000\000\000";
const s8 gUiGaugeRodata_001FCB88[0x8] = "+%d\000\000\000\000\000";
const s8 gUiGaugeRodata_001FCB90[0x10] = " \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_draw.c */
const Vec gMenuDrawRodata_001FCBA0[0x9] = { 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 2.0f, 2.0f, 3.2f, 3.2f, 3.2f, 3.2f, 4.6f, 4.6f, 4.6f, 4.6f, 6.2f, 6.2f, 6.2f, 6.2f, 8.0f, 8.0f, 8.0f, 8.0f, 10.0f, 10.0f, 10.0f, 10.0f, 12.0f, 12.0f, 12.0f, 12.0f };
const Vec gMenuDrawRodata_001FCC30[0x9] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -3.0f, 0.0f, 3.0f, 0.0f, -6.0f, 0.0f, 6.0f, 0.0f, -9.6f, 0.0f, 9.6f, 0.0f, -13.799999f, 0.0f, 13.799999f, 0.0f, -18.599998f, 0.0f, 18.599998f, 0.0f, -24.0f, 0.0f, 24.0f, 0.0f, -30.0f, 0.0f, 30.0f, 0.0f, -36.0f, 0.0f, 36.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/font_load.c */
const u8 gFontLoadRodata_001FCCC0[0x10] = "sta_font_00\000\000\000\000\000";
const u8 gFontLoadRodata_001FCCD0[0x10] = "sta_font_01\000\000\000\000\000";
const u8 gFontLoadRodata_001FCCE0[0x10] = "sta_font_02\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_proc.c */
const s8 gMenuProcRodata_001FCCF0[0x8] = { -0x7f, -0x65, -0x7f, 0x46, 0, 0, 0, 0 };
const s8 gMenuProcRodata_001FCCF8[0x8] = { -0x7f, 0x7e, -0x7f, 0x46, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu_slot.c */
const char gStrSavedataD_001FCD00[0x10] = "SAVEDATA %d\000\000\000\000\000";
const char gStrHp4d4d_001FCD10[0x10] = "HP %4d/%4d\000\000\000\000\000\000";
const char gStrMp4d4d_001FCD20[0x10] = "MP %4d/%4d\000\000\000\000\000\000";
const char gSaveMenuSlotRodata_001FCD30[0x10] = { 0x4c, 0x4f, 0x43, 0x41, 0x54, 0x49, 0x4f, 0x4e, 0, 0, 0, 0, 0, 0, 0, 0 };
const char gStrTime2d2d2d_001FCD40[0x18] = "TIME %2d:%2d:%2d\000\000\000\000\000\000\000\000";
const char gStrEmpty_001FCD58[0x8] = " EMPTY \000";
const char gSaveMenuSlotRodata_001FCD60[0xd] = "----\000\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu_slot.c */
const u8 pad_001FCD6D[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
#endif
