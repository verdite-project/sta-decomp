#include "common.h"
#include "game/core.h"
#include "game/data.h"
extern s32 gTaskRunBss_002F0F40[];
void Task_FlushWrap_0_0014DAC0(void);
void Task_KillWrap_0_0014DAF0(s32 arg0);
void Task_SetPriorityWrap_0_0014DB00(s32 arg0, s16 arg1, s32 arg2);
void Task_Register_0_0014DB10(s32 arg0);
void Task_SetPriority_0_001E0160();
void Task_Find_0_001E02C0(s32 arg0, s16 arg1, s32 arg2);
void Task_SetCallback_1_001E0560(s32 *, s32);

/* Task_InitWrap_0_0014DAA0 */
void Task_InitWrap_0_0014DAA0(void) {
    Task_Init_1_001E03C0();
}

/* Task_RunWrap_0_0014DAB0 */
void Task_RunWrap_0_0014DAB0(s32 arg0) {
    Task_Run_1_001DFEE0((void *) arg0);
}

/* Task_FlushWrap_0_0014DAC0 */
void Task_FlushWrap_0_0014DAC0(void) {
    Task_SetPriority_0_001E0160();
}

/* Task_AddWrap_0_0014DAD0 */
void Task_AddWrap_0_0014DAD0(s32 arg0) {
    Task_Add_0_001E0180((void *) arg0);
}

/* Task_RemoveWrap_0_0014DAE0 */
void Task_RemoveWrap_0_0014DAE0(s32 arg0) {
    Task_Remove_0_001E01F0((void *) arg0);
}

/* Task_KillWrap_0_0014DAF0 */
void Task_KillWrap_0_0014DAF0(s32 arg0) {
    Task_GetState_0_001E02A0((s8 *) arg0);
}

/* Task_SetPriorityWrap_0_0014DB00 */
void Task_SetPriorityWrap_0_0014DB00(s32 arg0, s16 arg1, s32 arg2)
{
    Task_Find_0_001E02C0(arg0, arg1, arg2);
}

/* Task_Register_0_0014DB10 */
void Task_Register_0_0014DB10(s32 arg0) {
    if (arg0 != 0) {
        gTaskRunBss_002F0F40[gTaskRunSbss_00201F20] = arg0;
        gTaskRunSbss_00201F20 += 1;
        Task_SetCallback_1_001E0560(gTaskRunBss_002F0F40, gTaskRunSbss_00201F20);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gTaskRunSbss_00201F20 */
s32 gTaskRunSbss_00201F20;
/* data group (src/game/data/angle_b_bss.c): gTaskRunBss_002F0F40__grp: gTaskRunBss_002F0F40@0x0, gTaskRunBss_002F0F44@0x4, gTaskRunBss_002F0F48@0x8, gTaskRunBss_002F0F4C@0xc, gTaskRunBss_002F0F50@0x10, gTaskRunBss_002F0F54@0x14, gTaskRunBss_002F0F58@0x18, gTaskRunBss_002F0F5C@0x1c */
unsigned char gTaskRunBss_002F0F40__grp[0x20] __attribute__((aligned(16)));
#endif
