#include "common.h"
#include "game/core.h"
#include "game/ui.h"

/* data_001F2770: the game's data at 0x001F2770..., one object per label. */
/* used by: ending_draw, item_menu_draw, map_sheet, menu, text_00182C10.s,
   ui_gauge */
#pragma explicit_zero_data on

void MenuProc_DrawList_0_0018B180(void);
void MenuProc_CheckReady_0_0018B2E0(void);
void MenuProc_DrawItemList_0_0018B860(void);
void SaveMenu_HandleEvent_0_0018C4C0(void);
void SaveMenu_DrawFrame_0_0018D1F0(void);
void SaveMenu_Open_1_0018D360(void);
void Loading_Nop_0_0018E440(void);
void Option_DrawFrame_0_0018E980(void);
void Option_Update_2_0018EAE0(void);
void LoadMenu_DrawList_0_00191CB0(void);
void LoadMenu_HandleEvent_0_00192900(void);
void LoadMenu_DrawFrame_0_00193880(void);
void LoadMenu_Open_0_001939B0(void);
void Ending_PlayMovie_2_00194EE0(void);
void Ending_OpenLoadMenu_0_00194F60(void);
void Databook_Draw_0_001952B0(void);
void Databook_UpdateWrap_0_00195410(void);
void DbChar_Draw_0_00195E30(void);
void DbChar_UpdateWrap_0_00196930(void);
void DbItem_Draw_0_00196E20(void);
void DbItem_Open_0_001979C0(void);
void DbMap_Draw_0_00198160(void);
void DbMap_UpdateWrap_0_00198BD0(void);
void Equip_Draw_0_00199190(void);
void Equip_Open_0_001997A0(void);
void ItemMenu_Draw_0_0019C6D0(void);
void ItemMenu_Open_0_0019D290(void);
void Status_Draw_0_0019DF90(void);
void PauseMenu_Open_0_0019E2F0(void);
void Pause_HandleEvent_0_0019E810(void);
void GameOver_DrawFrame_0_0019E8B0(void);
void GameOver_Update_2_0019EDC0(void);
void Shop_Draw_0_001A1460(void);
void Shop_Open_1_001A1B40(void);
void Storage_Draw_0_001A30E0(void);
void Storage_Open_0_001A32A0(void);
void Title_Nop_2_001A35A0(void);
void Title_LoadGame_0_001A35B0(void);
void Title_PlayOpening_2_001A3C10(void);
void Title_ResetOnEvent_0_001A3C70(void);
void Title_UpdateWrap_0_001A3EB0(void);
void TitleMenu_Update_1_001A4010(void);
void Title_PlayPrologue_2_001A4890(void);
void Title_StartNewGame_0_001A4930(void);
void Credits_Update_0_001DCC30(void);
void MapSheet_Update_0_001ED740(void);
void Ending_Update_0_001ED9A0(void);
void Ending_HandleEvent_0_001EDCC0(void);

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_gauge.c */
f32 D_001F2770[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/ui_draw_elem.c */
f32 D_001F2790[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu.c */
f32 D_001F27B0[0x4] = { 0.0f, 0.0f, 640.0f, 448.0f };
f32 D_001F27C0[0x4] = { 0.0f, 0.0f, 256.0f, 256.0f };
s32 D_001F27D0[0x2c] = { (s32)MenuProc_CheckReady_0_0018B2E0, (s32)Title_LoadGame_0_001A35B0, 0, (s32)Title_UpdateWrap_0_001A3EB0, (s32)Title_ResetOnEvent_0_001A3C70, (s32)Credits_Update_0_001DCC30, (s32)TitleMenu_Update_1_001A4010, (s32)Title_StartNewGame_0_001A4930, 0, (s32)SaveMenu_Open_1_0018D360, (s32)LoadMenu_Open_0_001939B0, (s32)SaveMenu_HandleEvent_0_0018C4C0, (s32)LoadMenu_HandleEvent_0_00192900, (s32)Option_Update_2_0018EAE0, 0, 0, 0, (s32)MapSheet_Update_0_001ED740, (s32)Hud_Update_1_0019B560, (s32)Pause_HandleEvent_0_0019E810, (s32)PauseMenu_Open_0_0019E2F0, (s32)ItemMenu_Open_0_0019D290, (s32)Equip_Open_0_001997A0, 0, (s32)Databook_UpdateWrap_0_00195410, (s32)DbMap_UpdateWrap_0_00198BD0, (s32)DbChar_UpdateWrap_0_00196930, (s32)DbItem_Open_0_001979C0, 0, 0, 0, (s32)Storage_Open_0_001A32A0, 0, 0, (s32)Shop_Open_1_001A1B40, 0, (s32)Ending_Update_0_001ED9A0, (s32)Ending_HandleEvent_0_001EDCC0, 0, (s32)Loading_Nop_0_0018E440, (s32)GameOver_Update_2_0019EDC0, (s32)Ending_OpenLoadMenu_0_00194F60, 0, 0 };
s32 D_001F2880[0x14] = { (s32)MenuProc_DrawList_0_0018B180, (s32)Title_Nop_2_001A35A0, 0, (s32)Title_DrawLogo_0_001A3CC0, (s32)Title_PlayOpening_2_001A3C10, (s32)Credits_DrawFrame_0_001DC900, (s32)Title_Draw_0_001A3FB0, (s32)Title_PlayPrologue_2_001A4890, 0, (s32)SaveMenu_DrawFrame_0_0018D1F0, (s32)LoadMenu_DrawFrame_0_00193880, (s32)MenuProc_DrawItemList_0_0018B860, (s32)LoadMenu_DrawList_0_00191CB0, (s32)Hud_Draw_0_0018E480, 0, 0, 0, (s32)MapSheet_Draw_0_001ED630, (s32)Hud_DrawMain_0_0019A8B0, (s32)Pause_DrawText_2_0019E7C0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/item_menu_draw.c */
s32 D_001F28D0[0x18] = { (s32)Status_Draw_0_0019DF90, (s32)ItemMenu_Draw_0_0019C6D0, (s32)Equip_Draw_0_00199190, 0, (s32)Databook_Draw_0_001952B0, (s32)DbMap_Draw_0_00198160, (s32)DbChar_Draw_0_00195E30, (s32)DbItem_Draw_0_00196E20, 0, 0, 0, (s32)Storage_Draw_0_001A30E0, 0, 0, (s32)Shop_Draw_0_001A1460, 0, (s32)Ending_DrawText_0_001ED850, (s32)Ending_Draw_0_001EDAD0, 0, (s32)Loading_DrawFrame_0_0018E270, (s32)GameOver_DrawFrame_0_0019E8B0, (s32)Ending_PlayMovie_2_00194EE0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu.c */
s32 D_001F2930[0x2c] = { 0, 0, 0, 0, 0, (s32)Credits_DrawBg_0_001DCE70, (s32)Credits_DrawBg_0_001DCE70, 0, 0, (s32)Option_DrawFrame_0_0018E980, 0, (s32)Option_DrawFrame_0_0018E980, 0, (s32)Option_DrawFrame_0_0018E980, 0, 0, 0, (s32)Hud_DrawMain_0_0019A8B0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/menu.c */
f32 D_001F29E0[0x1] = { -2.89f };
f32 D_001F29E4[0x1] = { -2.89f };
f32 D_001F29E8[0x1] = { -2.89f };
f32 D_001F29EC[0x1] = { -2.89f };
#endif
