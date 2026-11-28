#include "m2c.h"
#include "common.h"
#include "game/core.h"
#include "game/data.h"
#include "game/sound.h"
#include "game/ui.h"
typedef struct { s32 state; s32 buttons; u8 next; u8 pad[5]; u8 pad_e; } Menu;
typedef struct { u8 pad[0x10]; s32 count; u8 pad2[0x14]; f32 base; } Info;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { s32 x0; u32 x4; u8 b8; char p9[5]; u8 bE; } Obj;
#ifndef NONMATCHING
extern s32 D_00202204;
#else
/* data twins (src/game/data/sbss.c): D_00202204 */
static s32 D_00202204;
#endif
extern s32 D_004A32CC[];
#ifndef NONMATCHING
extern u8 D_001FD610[];
#else
/* data twins (src/game/data/pause_menu_entry_rodata.c): D_001FD610 */
static u8 D_001FD610[0x5] = "ITEM\000";
#endif
#ifndef NONMATCHING
extern u8 D_001FD648[];
#else
/* data twins (src/game/data/pause_menu_entry_rodata2.c): D_001FD648 */
static u8 D_001FD648[0x7] = "OPTION\000";
#endif
#ifndef NONMATCHING
extern char D_001FD650[];
#else
/* data twins (src/game/data/pause_menu_entry_rodata2.c): D_001FD650 */
static char D_001FD650[0x10] __attribute__((aligned(8))) = { -0x7e, 0x6f, -0x7e, 0x60, -0x7e, 0x74, -0x7e, 0x72, -0x7e, 0x64, 0, 0, 0, 0, 0, 0 };
#endif
void PauseMenu_Update_0_0019E400(Menu *m);
s32 PauseMenu_GetEntry_0_0019E780(s32 i);
void Pause_HandleEvent_0_0019E810(Obj *o);
void Snd_PlaySe_3_00131600(s32, u8);
void UiAnim_Get_1_0017F840(s32, Info **);
s32 UiAnim_SetTarget_1_0017F470(s32, s32, f32);
void SndEmit_SetEnabled_0_0012F6E0(s32);
void Text_Draw_2_001875C0(void *p, s32 n, Col c, f32 x, f32 y, f32 s);

/* PauseMenu_Update_0_0019E400 */
/* PauseMenu_Update_0_0019E400 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_004A32B0[0x6];

void PauseMenu_Update_0_0019E400(Menu *m) {
    Info *info;
    s32 i;
    s32 n;
    s32 sel = D_004A32C8[0];

    if (m->buttons & 0x2000) {
        Snd_PlaySe_3_00131600(0x69, m->pad_e);
        switch (D_004A32C8[0]) {
        case 0:
            m->next = 0x15;
            break;
        case 1:
            m->next = 0x16;
            break;
        case 2:
            m->next = 0x18;
            break;
        case 3:
            m->next = 9;
            MenuStack_Push_1_00189ED0(0x14);
            Loading_SetVisible_0_0018E470(0);
            break;
        case 4:
            m->next = 0xD;
            MenuStack_Push_1_00189ED0(0x14);
            Loading_SetVisible_0_0018E470(0);
            break;
        }
        D_004A32CC[0] = 0;
        if (D_00202208 == 0) {
            UiAnim_Get_1_0017F840(0, &info);
            n = info->count;
            for (i = 0; i < n; i++) {
                D_004A32B0[i] = info->base - (f32)i;
            }
        }
        D_00202208 = 1;
        m->buttons = 0;
        m->state = 0x1A;
        UiAnim_SetVisible_1_0017F7C0(0, 0, 0);
        D_00202204 = 0;
        return;
    }
    if (m->buttons & 0x4000) {
        m->next = 0x12;
        m->buttons = 0;
        m->state = 0x1A;
        UiAnim_SetVisible_1_0017F7C0(0, 0, 0);
        D_00202204 = 0;
        D_00202208 = 3;
        Snd_PlaySe_3_00131600(0x65, m->pad_e);
        SndEmit_SetEnabled_0_0012F6E0(1);
        SndCh_ResumePaused_1_0012C260();
        return;
    }
    if (m->buttons & 0x10) {
        sel = D_004A32C8[0] - 1;
    } else if (m->buttons & 0x40) {
        sel = D_004A32C8[0] + 1;
    }
    if (UiAnim_SetTarget_1_0017F470(0, 0, D_004A32C8[0]) != 0) {
        if (D_004A32C8[0] != sel) {
            Snd_PlaySe_3_00131600(0x66, m->pad_e);
        }
        D_00202208 = 0;
        D_004A32C8[0] = (sel + 5) % 5;
    }
}

/* PauseMenu_GetEntry_0_0019E780 */
#pragma explicit_zero_data on
const u8 D_001FD618[0x10] __attribute__((aligned(8))) = "EQUIPMENT\000\000\000\000\000\000\000";
const u8 D_001FD628[0x10] __attribute__((aligned(8))) = "DATABOOK\000\000\000\000\000\000\000\000";
const u8 D_001FD638[0xa] = "LOAD GAME\000";
s32 D_001F3140[0x8] = { (s32)D_001FD610, (s32)D_001FD618, (s32)D_001FD628, (s32)D_001FD638, (s32)D_001FD648 };
s32 PauseMenu_GetEntry_0_0019E780(s32 i)
{
    if (i < 0 || i > 5)
        return 0;
    return D_001F3140[i];
}

/* Pause_DrawText_2_0019E7C0 */
/* Pause_DrawText_2_0019E7C0 */
void Pause_DrawText_2_0019E7C0(void)
{
    Col c;
    *(u32 *)&c = 0x80808080;
    Text_Draw_2_001875C0(D_001FD650, 1, c, 320.0f, 200.0f, 1.0f);
}

/* Pause_HandleEvent_0_0019E810 */
void Pause_HandleEvent_0_0019E810(Obj *o)
{
    if (o->x0 == 25)
        PlayTime_Pause_1_001DF990();
    if (o->x0 == 22 && ((o->x4 & 1) || (o->x4 & 0x4000))) {
        Snd_PlaySe_3_00131600(0x65, o->bE);
        o->b8 = 18;
        o->x4 = 0;
        o->x0 = 31;
        PlayTime_Resume_1_001DF960();
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202208 */
s32 D_00202208;
/* data twins (src/game/data/shop_bss.c): D_004A32C8 */
s32 D_004A32C8[0x6] __attribute__((aligned(8)));
#endif
