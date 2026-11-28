#include "common.h"
#include "game/data.h"

typedef struct { u128 q; } Q;
extern Q gTaskAllData_001F2010;
extern s32 gTaskRunBss_002F0F40[8];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
char D_002F0F60[0x1c0];
void Task_SetCallback_1_001E0560(s32 *p, s32 n);
void Task_Start_1_001E0590(void *p, s32 a, s32 b, Q *q);

void Task_InitAll_1_0014DB60(void)
{
    Q q = gTaskAllData_001F2010;
    s32 i;
    for (i = 7; i >= 0; i--)
        gTaskRunBss_002F0F40[i] = 0;
    gTaskRunSbss_00201F20 = 0;
    Task_SetCallback_1_001E0560(gTaskRunBss_002F0F40, 0);
    Task_Start_1_001E0590(D_002F0F60, 0x38, 8, &q);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
void Res_Free_0_0014DC10(void);
void Res_Open_0_0014DC70(void);
void Res_Read_1_0014DC50(void);
void Res_ReleaseHandle_0_0014DC00(void);
/* data group (src/game/data/task_run_data.c): D_001F2010__grp: gTaskAllData_001F2010@0x0 */
s32 D_001F2010__grp[0x4] __attribute__((aligned(16))) = { (s32)Res_Open_0_0014DC70, (s32)Res_Read_1_0014DC50, (s32)Res_Free_0_0014DC10, (s32)Res_ReleaseHandle_0_0014DC00 };
#endif
