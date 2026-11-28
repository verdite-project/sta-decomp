#include "common.h"

/* rodata_001FD288: the game's data at 0x001FD288..., one object per label. */
/* used by: databook, databook_char_list, databook_item_reset, hud_draw,
   text_00196330.s, text_001973F0.s */
#pragma explicit_zero_data on

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook.c */
const u8 D_001FD288[0x5] = "ITEM\000";
const s8 D_001FD290[0xf] = "menu/dbmap.txm\000";
const s8 D_001FD2A0[0x10] __attribute__((aligned(8))) = "menu/dbchar.txm\000";
const s8 D_001FD2B0[0x10] __attribute__((aligned(8))) = "menu/dbitem.txm\000";
const s8 D_001FD2C0[0xe] = "menu/help.txm\000";
const s8 D_001FD2D0[0x10] __attribute__((aligned(8))) = "menu/dbchar.sta\000";
const s8 D_001FD2E0[0xf] = "menu/dbmap.sta\000";
const s8 D_001FD2F0[0x20] __attribute__((aligned(8))) = "menu/itemsort.tbl\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
const s8 D_001FD310[0x18] __attribute__((aligned(8))) = "menu/itemmenu.tbl\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/db_char_proc_draw_info.c */
const s32 D_001FD328[0x2] = { -0x7edf9bdb, 0x93 };
const char gStrHpD_001FD330[0x6] = "HP %d\000";
const char gStrHp_001FD338[0x8] = "HP ----\000";
const char gStr3d_001FD340[0x8] = "%3d\000\000\000\000\000";
const s32 D_001FD348[0x2] = { 0x2d2d2d, 0 };
const char gStr31f_001FD350[0x6] = "%3.1f\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook_char_list.c */
const char D_001FD358[0x10] __attribute__((aligned(8))) = { -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/db_item_proc_draw_info.c */
const s32 D_001FD368[0x2] = { -0x7edf9bdb, 0x93 };
const s32 D_001FD370[0x2] = { 0x2d2d2d, 0 };
const s32 D_001FD378[0x2] = { 0x6425, 0 };
const char gStr31f_001FD380[0x6] = "%3.1f\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/databook_item_reset.c */
const char D_001FD388[0x10] __attribute__((aligned(8))) = { -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, 0, 0, 0, 0, 0, 0, 0, 0 };
const s8 D_001FD398[0x8] = { 0x25, 0x64, 0x20, -0x7f, -0x6d, 0, 0, 0 };
const s8 D_001FD3A0[0x10] __attribute__((aligned(8))) = { -0x7f, 0x40, -0x7f, 0x40, -0x6d, 0x47, -0x61, 0x72, -0x6a, -0x3b, -0x69, -0x5a, 0, 0, 0, 0 };
const s8 D_001FD3B0[0x10] __attribute__((aligned(8))) = { 0x20, 0x20, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, 0, 0, 0, 0, 0, 0 };
const s8 D_001FD3C0[0x8] = { 0x2d, 0x2d, 0x2d, 0x20, -0x7f, -0x6d, 0, 0 };
const s8 D_001FD3C8[0x8] = { 0x25, 0x33, 0x64, 0x20, -0x7f, -0x6d, 0, 0 };
const s8 D_001FD3D0[0x10] __attribute__((aligned(8))) = { -0x7f, 0x40, -0x73, -0x3b, -0x73, -0x7e, -0x61, 0x72, -0x6a, -0x3b, -0x69, -0x5a, 0, 0, 0, 0 };
const s8 D_001FD3E0[0x8] = { 0x20, 0x2d, 0x2d, 0x2d, 0x20, -0x7f, -0x6d, 0 };
const s8 D_001FD3E8[0x8] = { 0x20, 0x25, 0x33, 0x64, 0x20, -0x7f, -0x6d, 0 };
const s8 D_001FD3F0[0x8] = "%s\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_draw.c */
const s16 D_001FD3F8[0x5] = { 2, 3, 6, 5, 4 };
const u16 D_001FD402[0x1] __attribute__((aligned(2))) = { 1 };
const u16 D_001FD404[0x2] = { 0, 0 };
const s8 D_001FD408[0x8] = "HP\000\000\000\000\000\000";
const s8 D_001FD410[0x8] = { 0x25, 0x34, 0x64, 0x2f, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/hud_draw.c */
const s8 D_001FD418[0x8] = { 0x25, 0x64, 0, 0, 0, 0, 0, 0 };
const s8 D_001FD420[0xd] = "MP\000\000\000\000\000\000\000\000\000\000\000";
#endif
const u8 pad_001FD42D[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
