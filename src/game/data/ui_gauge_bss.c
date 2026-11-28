#include "common.h"

/* bss_0048D170: the game's .bss from 0x0048D170, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: font_load, menu, menu_draw, text_00188010.s, ui_gauge */

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
s32 gMenuBss_00497B60[0x8];
u8 gEquipDrawBss_00496B60[0x1000];
u8 gEquipDrawBss_00495B60[0x1000];
u8 gMenuDrawBss_0048DB60[0x8000];
u8 gTextRenderBss_0048D360[0x800];
s32 gFontLoadBss_0048D358[0x2];
s32 gFontLoadBss_0048D354[0x1];
s32 gFontLoadBss_0048D350[0x1];
u8 gUiGaugeBss_0048D170[0x1e0];
#endif
