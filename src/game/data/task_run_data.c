#include "common.h"

/* data_001F2010: the game's data at 0x001F2010..., one object per label. */
/* used by: task_all */
#pragma explicit_zero_data on

void Res_ReleaseHandle_0_0014DC00(void);
void Res_Free_0_0014DC10(void);
void Res_Read_1_0014DC50(void);
void Res_Open_0_0014DC70(void);

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/task_all.c */
s32 gTaskAllData_001F2010[0x4] = { (s32)Res_Open_0_0014DC70, (s32)Res_Read_1_0014DC50, (s32)Res_Free_0_0014DC10, (s32)Res_ReleaseHandle_0_0014DC00 };
#endif
