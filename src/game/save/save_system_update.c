#include "common.h"
#include "game/data.h"
#include "game/ee.h"
#include "game/save.h"
extern u32 gSaveSystemStartSbss_002023DC;
extern s32 gSaveSystemStepBss_004BC380[];
extern s32 gSaveSystemStepBss_004BCBC0[];
extern s32 gSaveSystemStepBss_004BCF40[];
s32 SaveSys_Init_1_001E85E0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4);
void SaveSys_StepCheckSpace_0_001E7C10(s32);
void SaveSys_StepScan_1_001E7880(s32);
void SaveSys_StepCheckCard_0_001E7FA0(s32);
void SaveSys_StepUnformat_1_001E7DF0(s32);
s32 Mc_Init_3_001D6F80();
void memset(s32 *, s32, s32);

/* SaveSys_Update_2_001E8500 */
s32 SaveSys_Update_2_001E8500(void) {
    s32 r;
    if (gSaveSystemStepSbss_002023D8 < 0) {
        gSaveSystemStepSbss_002023D8 = 0;
        gSaveSystemStartSbss_002023DC = 1;
    }
    r = Mc_Update_4_001D6D00();
    if (0 < r) {
        return 0;
    }
    switch (gSaveSystemStartSbss_002023DC) {
    case 0: break;
    case 1: SaveSys_StepCheckSpace_0_001E7C10(r); break;
    case 2: SaveSys_StepScan_1_001E7880(r); break;
    case 5: SaveSys_StepSave_2_001E64E0(r); break;
    case 6: SaveSys_StepLoad_2_001E72A0(r); break;
    case 3: SaveSys_StepCheckCard_0_001E7FA0(r); break;
    case 4: SaveSys_StepUnformat_1_001E7DF0(r); break;
    }
    return 0;
}

/* SaveSys_Init_1_001E85E0 */
#define gSaveSystemStartSbss_002023DC gSaveSystemStartSbss_002023DC__as_SaveSys_Init_1_001E85E0
extern s32 gSaveSystemStartSbss_002023DC__as_SaveSys_Init_1_001E85E0;

s32 SaveSys_Init_1_001E85E0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 var_4_2;
    s32 *var_4;
    s32 var_3;
    s32 *var_16;
    s32 *var_3_2;

    var_16 = (s32 *) (arg2);
    if (gSaveSystemStartSbss_002023B8 != 0) {
        return -1;
    }
    if (Mc_Init_3_001D6F80() != 0) {
        return -1;
    }
    gSaveSystemStepSbss_002023E4 = arg0;
    gSaveSystemStepSbss_002023E0 = arg1;
    gSaveSystemStepSbss_002023E8 = 0;
    gSaveSystemStartSbss_002023D0 = 0;
    gSaveSystemStepSbss_002023D4 = 0;
    memset(gSaveSystemStepBss_004BCBC0, 0, 0x206);
    gSaveSystemStepSbss_002023C8 = arg3;
    var_4 = (s32 *) (gSaveSystemStepBss_004BCF40);
    gSaveSystemStepSbss_002023C4 = arg4;
    var_3 = 0xF1;
    gSaveSystemStartSbss_002023CC = 0;
    do {
        var_3 -= 1;
        *var_4 = *var_16;
        var_16 = (s32*)((u8 *)var_16 + 4);
        var_4 = (s32*)((u8 *)var_4 + 4);
    } while (var_3 > 0);
    var_4_2 = 0;
    var_3_2 = (s32 *) (gSaveSystemStepBss_004BC380);
    do {
        M2C_FIELD(var_3_2, s32 *, 0) = 0;
        M2C_FIELD(var_3_2, s32 *, 4) = 0;
        var_4_2 += 1;
        M2C_FIELD(var_3_2, s32 *, 8) = 0;
        M2C_FIELD(var_3_2, s32 *, 0xC) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x10) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x14) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x18) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x1C) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x20) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x3C0) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x3C4) = 0;
        var_3_2 = (s32*)((u8 *)var_3_2 + 0x400);
    } while (var_4_2 < 2);
    gSaveSystemStepSbss_002023D8 = 0;
    gSaveSystemStartSbss_002023DC = 1;
    gSaveSystemStartSbss_002023B8 = 1;
    return 0;
}
#undef gSaveSystemStartSbss_002023DC
