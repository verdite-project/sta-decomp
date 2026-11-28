#include "common.h"

/* bss_004A1120: the game's .bss from 0x004A1120, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: databook_char_draw, databook_char_list,
   databook_char_update_wrap, databook_item_draw, databook_item_reset,
   load_menu, load_menu_card, load_menu_draw, text_00196330.s,
   text_001973F0.s */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
f32 gDatabookItemResetBss_004A18B8[0x2];
s32 gDatabookItemResetBss_004A18B0[0x2];
u32 gDatabookItemResetBss_004A18AC[0x1];
f32 gDatabookItemResetBss_004A18A0[0x3];
f32 gDatabookItemResetBss_004A189C[0x1];
u8 gDatabookItemResetBss_004A1884[0x18] __attribute__((aligned(4))); /* also D_004A1888 */
s8 gDatabookItemResetBss_004A1870[0x14];
s8 gDatabookItemResetBss_004A1770[0x100];
s32 gDatabookItemResetBss_004A1450[0xc8];
u8 gDatabookItemDrawBss_004A1440[0x10]; /* also D_004A1444 */
f32 gDatabookItemDrawBss_004A143C[0x1];
s32 gDatabookItemDrawBss_004A1438[0x1];
s32 gDatabookItemDrawBss_004A1434[0x1];
s32 gDatabookItemDrawBss_004A1430[0x1];
u8 gDbItemProcDrawInfoBss_004A142C[0x4];
u8 gDbItemProcDrawInfoBss_004A1420[0xc];
u8 gDbItemProcDrawInfoBss_004A141C[0x4];
u8 gDbItemProcDrawInfoBss_004A1404[0x18] __attribute__((aligned(4))); /* also D_004A1408 */
u8 gDbItemProcDrawInfoBss_004A13F0[0x14];
s32 gDatabookCharUpdateWrapBss_004A13E0[0x4];
u8 gDbCharProcDrawInfoBss_004A13DC[0x4];
u8 gDbCharProcDrawInfoBss_004A13D0[0xc];
u8 gDbCharProcDrawInfoBss_004A13CC[0x4];
u8 gDbCharProcDrawInfoBss_004A13B4[0x18] __attribute__((aligned(4))); /* also D_004A13B8 */
u8 gDbCharProcDrawInfoBss_004A13A0[0x14];
s32 gDatabookCharUpdateWrapBss_004A11A0[0x80];
s32 gLoadMenuBss_004A119C[0x1];
s32 gLoadMenuBss_004A1198[0x1];
u8 gLoadMenuBss_004A1194[0x4];
f32 gLoadMenuBss_004A1190[0x1];
u8 gLoadMenuBss_004A118C[0x4];
s32 gLoadMenuBss_004A1188[0x1];
s32 gLoadMenuBss_004A1184[0x1];
u8 gLoadMenuBss_004A1180[0x4];
u8 gLoadMenuBss_004A1150[0x30]; /* also D_004A1168 */
u8 gLoadMenuBss_004A1140[0x10];
f32 gLoadMenuBss_004A113C[0x1];
f32 gLoadMenuBss_004A1138[0x1];
s32 gLoadMenuBss_004A1130[0x2];
s32 gLoadMenuBss_004A112C[0x1];
s32 gLoadMenuBss_004A1128[0x1];
s32 gLoadMenuBss_004A1124[0x1];
s32 gLoadMenuBss_004A1120[0x1] __attribute__((aligned(16)));
#endif
