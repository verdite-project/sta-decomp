#include "common.h"

/* data_001F2B50: the game's data at 0x001F2B50..., one object per label. */
/* used by: load_menu, option */
#pragma explicit_zero_data on

extern u8 D_001F2A90[];
extern u8 D_001F2AC0[];
extern u8 gStrMono_001FCE60[];
extern u8 gStrStereo_001FCE68[];
extern u8 D_001FCE70[];
extern u8 gStrSound_001FCE88[];
extern u8 D_001FCE90[];
extern u8 D_001FCEA0[];
extern u8 D_001FCEB0[];
extern u8 gStrScreenRatio_001FCEC0[];
extern u8 D_001FCED0[];
extern u8 D_001FCEE0[];
extern u8 gStr169_001FCEE8[];
extern u8 D_001FCEF0[];
extern u8 D_001FCF20[];
extern u8 D_001FCF30[];
extern u8 D_001FCF40[];
extern u8 D_001FCF50[];
extern u8 D_001FCF68[];
extern u8 D_001FCF80[];
extern u8 D_001FCF98[];
extern u8 D_001FCFA0[];
extern u8 D_001FCFB0[];
extern u8 D_001FCFC0[];
extern u8 D_001FCFC8[];
extern u8 D_001FCFD8[];
extern u8 D_001FCFE8[];
extern u8 D_001FCFF0[];
extern u8 D_001FCFF8[];
extern u8 D_001FD000[];
extern u8 D_001FD010[];
extern u8 D_001FD020[];
extern u8 D_001FD030[];
extern u8 D_001FD040[];
extern u8 D_001FD048[];
extern u8 D_001FD050[];
extern u8 D_001FD058[];
extern u8 D_001FD068[];
extern u8 D_001FD078[];
extern u8 D_001FD088[];
extern u8 D_001FD090[];
void OptionProc_DrawSound_0_00190A50(void);
void OptionProc_DrawScreen_0_00190DC0(void);
void OptionProc_DrawController_0_00191110(void);
void OptionProc_DrawMain_0_00191420(void);

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_001F2B50[0x4] = { (s32)gStrMono_001FCE60, (s32)gStrStereo_001FCE68, (s32)D_001FCE70, 0 };
s32 D_001F2B60[0x4] = { (s32)gStrSound_001FCE88, (s32)D_001FCE90, (s32)D_001FCEA0, 0 };
s32 D_001F2B70[0x4] = { (s32)D_001FCEB0, (s32)gStrScreenRatio_001FCEC0, (s32)D_001FCED0, 0 };
s32 D_001F2B80[0x4] = { (s32)D_001FCEE0, (s32)gStr169_001FCEE8, (s32)D_001FCEF0, 0 };
s32 D_001F2B90[0x8] = { (s32)D_001FCF20, (s32)D_001FCF30, (s32)D_001FCF40, (s32)D_001FCF50, (s32)D_001FCF68, (s32)D_001FCF80, 0, 0 };
s32 D_001F2BB0[0x18] = { (s32)D_001FCF98, (s32)D_001FCFA0, (s32)D_001FCFB0, (s32)D_001FCFC0, (s32)D_001FCFC8, (s32)D_001FCFD8, (s32)D_001FCFE8, (s32)D_001FCFF0, (s32)D_001FCFF8, (s32)D_001FD000, (s32)D_001FD010, (s32)D_001FD020, (s32)D_001FD030, (s32)D_001FD040, (s32)D_001FD048, (s32)D_001FD050, (s32)D_001FD058, (s32)D_001FD068, (s32)D_001FD050, (s32)D_001FD078, (s32)D_001FD088, (s32)D_001FD090, 0, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
f32 D_001F2C10[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2C30[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2C50[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2C70[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2C90[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_001F2CB0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_001F2CD0[0x4] = { 0, 1, 2, 3 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_001F2CE0[0x8] = { 5, 0, 0, (s32)D_001F2A90, 5, 0, 0, (s32)OptionProc_DrawMain_0_00191420 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_001F2D00[0x4] = { 0, 1, 2, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_001F2D10[0x8] = { 5, 1, 0, (s32)D_001F2AC0, 8, 0, 0, (s32)OptionProc_DrawController_0_00191110 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_001F2D30[0x4] = { 0, 1, 2, 0 };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/option.c */
s32 D_001F2D40[0x8] = { 5, 3, 0, (s32)D_001F2AC0, 8, 0, 0, (s32)OptionProc_DrawScreen_0_00190DC0 };
s32 D_001F2D60[0x8] = { 5, 2, 0, (s32)D_001F2AC0, 8, 0, 0, (s32)OptionProc_DrawSound_0_00190A50 };
f32 D_001F2D80[0x4] = { 0.0f, 0.0f, 640.0f, 480.0f };
f32 D_001F2D90[0x4] = { 0.0f, 0.0f, 128.0f, 128.0f };
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ui/load_menu.c */
f32 D_001F2DA0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
