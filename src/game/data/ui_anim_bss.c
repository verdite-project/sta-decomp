#include "common.h"

/* bss_00486900: the game's .bss from 0x00486900, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: font_draw, text_00184280.s, text_00185D70.s, ui_anim, ui_draw,
   ui_gauge */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_gauge.c */
void *D_0048D110[0xc];
u8 D_0048D10C[0x4];
u8 D_0048D108[0x4];
u8 D_0048D104[0x4];
u8 D_0048D100[0x4];
u8 D_0048D0FC[0x4];
u8 D_0048D0F8[0x4];
u8 D_0048D0F4[0x4];
u8 D_0048D0F0[0x4];
u8 D_0048D0E0[0x10]; /* also D_0048D0E4 */
u8 D_0048D0DC[0x4];
u8 D_0048D0D0[0xc];
u8 D_0048D0CC[0x4];
u8 D_0048D0B4[0x18] __attribute__((aligned(4))); /* also D_0048D0B8 */
u8 D_0048D0A0[0x14];
u8 D_0048D09C[0x4];
u8 D_0048D090[0xc];
u8 D_0048D08C[0x4];
u8 D_0048D074[0x18] __attribute__((aligned(4))); /* also D_0048D078 */
u8 D_0048D060[0x14];
u8 D_0048D040[0x20];
s32 D_0048D000[0x10];
s32 D_0048CFC0[0x10];
s32 D_0048CF80[0x10];
s32 D_0048CF40[0x10];
u8 D_0048CE40[0x100];
u8 D_0048C4B0[0x990];
u8 D_004884B0[0x4000];
u8 D_004880B4[0x3fc] __attribute__((aligned(4))); /* also D_004880B5, D_004880B6, D_004880B7 */
u8 D_004880B0[0x4];
s8 D_004870B0[0x1000];
u8 D_004869D0[0x6e0]; /* also D_004869D4 */
u8 D_004869B4[0x1c] __attribute__((aligned(4))); /* also D_004869B8 */
u8 D_004869B0[0x4];
s32 D_004869A0[0x4];
void *D_0048699C[0x1];
u8 D_00486990[0xc];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_anim.c */
f32 D_00486988[0x2];
f32 D_00486984[0x1];
s32 D_00486980[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/mdl_create_instance.c */
u8 D_00486940[0x40];
u8 D_00486900[0x40];
#endif
