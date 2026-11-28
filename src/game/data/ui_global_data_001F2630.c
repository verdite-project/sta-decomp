#include "common.h"

/* data_001F2630: the game's data at 0x001F2630..., one object per label. */
#pragma explicit_zero_data on

extern u8 gMenuProcDrawWeightRodata_001FC988[];
extern u8 gMenuProcDrawWeightRodata_001FC998[];
extern u8 gStrCurse_001FC9B0[];
extern u8 gStrGravity_001FC9A8[];
extern u8 gStrPoison_001FC980[];
extern u8 gStrSeal_001FC9B8[];

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
f32 gUiGaugeData_001F2630[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gUiGaugeData_001F2650[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gUiGaugeData_001F2670[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
s8 *gMenuProcDrawWeightData_001F2690[0x8] = { (s8 *)gStrPoison_001FC980, (s8 *)gMenuProcDrawWeightRodata_001FC988, (s8 *)gMenuProcDrawWeightRodata_001FC998, (s8 *)gStrGravity_001FC9A8, (s8 *)gStrCurse_001FC9B0, (s8 *)gStrSeal_001FC9B8, 0, 0 };
f32 gMenuProcDrawWeightData_001F26B0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gUiGaugeData_001F26D0[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gUiGaugeData_001F26F0[0x4] = { 615.0f, 275.0f, 619.0f, 399.0f };
f32 gUiGaugeData_001F2700[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 gMenuProcDrawItemStatsData_001F2720[0x8] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#endif
