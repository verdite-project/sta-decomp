#include "common.h"

/* bss_004A0B0C: the game's .bss from 0x004A0B0C, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: menu, menu_options, menu_proc, message, option, save_menu,
   save_menu_card, save_menu_slot */

s32 D_004A108C[0x1];
s32 D_004A1088[0x1];
s32 D_004A1084[0x1];
s32 D_004A1080[0x1];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu.c */
u8 D_004A1078[0x8] __attribute__((aligned(4)));
u8 D_004A1074[0x4]; /* also D_004A1075, D_004A1077 */
u8 D_004A1070[0x4]; /* also D_004A1071, D_004A1072, D_004A1073 */
s32 D_004A106C[0x1];
s32 D_004A1068[0x1];
f32 D_004A1060[0x2] __attribute__((aligned(4)));
u8 D_004A105C[0x4];
s32 D_004A1058[0x1];
s32 D_004A1054[0x1];
u8 D_004A1050[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu.c */
s32 D_004A1020[0xc] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/save_menu_slot.c */
u8 D_004A1010[0x10] __attribute__((aligned(4)));
f32 D_004A100C[0x1];
u8 D_004A1008[0x4];
s32 D_004A1000[0x2] __attribute__((aligned(4)));
s32 D_004A0FFC[0x1];
s32 D_004A0FF8[0x1];
s32 D_004A0FF4[0x1];
s32 D_004A0FF0[0x1];
s32 D_004A0FC0[0xc] __attribute__((aligned(4)));
#endif
u8 D_004A0F98[0x28] __attribute__((aligned(4))); /* also D_004A0F9C, D_004A0FAC */
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu_proc.c */
u8 D_004A0F90[0x8] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/message.c */
u8 D_004A0F80[0x10] __attribute__((aligned(4))); /* also D_004A0F84 */
u8 D_004A0F68[0x18] __attribute__((aligned(4))); /* also D_004A0F6C, D_004A0F74 */
s32 D_004A0F64[0x1];
u8 D_004A0F60[0x4];
u8 D_004A0F5C[0x4];
u8 D_004A0F58[0x4];
s32 D_004A0F54[0x1];
u8 D_004A0B50[0x404] __attribute__((aligned(4)));
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu.c */
u8 D_004A0B30[0x20] __attribute__((aligned(4))); /* also D_004A0B34 */
u8 D_004A0B2C[0x4]; /* also D_004A0B2E, D_004A0B2F */
u8 D_004A0B28[0x4]; /* also D_004A0B29, D_004A0B2A, D_004A0B2B */
s32 D_004A0B24[0x1];
u8 D_004A0B20[0x4];
u8 D_004A0B1C[0x4];
u8 D_004A0B18[0x4];
u8 D_004A0B14[0x4];
u8 D_004A0B10[0x4];
u32 D_004A0B0C[0x1];
#endif
