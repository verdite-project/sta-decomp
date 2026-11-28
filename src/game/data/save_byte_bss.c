#include "common.h"

/* bss_004A4390: the game's .bss from 0x004A4390, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: enemy_list, enemy_manager, enemy_model, text_001A4990.s,
   text_001A51E0.s, text_001A7D90.s, title */

s32 D_004A4878[0x2];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_list.c */
u8 D_004A4774[0x104] __attribute__((aligned(4))); /* also D_004A4776 */
u8 D_004A4570[0x204];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_manager.c */
u8 D_004A4540[0x30];
u8 D_004A43D0[0x170];
u8 D_004A43CC[0x4];
u8 D_004A43C8[0x4];
u8 D_004A43C4[0x4];
u8 D_004A43C0[0x4];
u8 D_004A43BC[0x4];
u8 D_004A43B8[0x4];
u8 D_004A43B4[0x4];
u8 gEnemyDataTbl_004A43B0[0x4];
#endif
u8 D_004A43AC[0x4];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/title.c */
u8 D_004A43A0[0xc]; /* also D_004A43A2 */
u8 D_004A4398[0x8];
s32 D_004A4394[0x1];
s32 D_004A4390[0x1] __attribute__((aligned(16)));
#endif
