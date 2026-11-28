#include "common.h"

/* bss_00270560: the game's .bss from 0x00270560, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: angle_b, cos_table, item_object, map, map_se_load, map_se_stream,
   task_all, task_run, text_001A4990.s */

u8 D_002F0F5C[0x4];
u8 D_002F0F58[0x4];
u8 D_002F0F54[0x4];
u8 D_002F0F50[0x4];
u8 D_002F0F4C[0x4];
u8 D_002F0F48[0x4];
u8 D_002F0F44[0x4];
s32 D_002F0F40[0x1];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/enemy/enemy_mgr_update.c */
u8 gLoadBuf_00270F40[0x80000];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/math/angle_b.c */
f32 D_00270560[0x278];
#endif
