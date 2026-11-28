#include "common.h"
#include "game/data.h"
#include "game/ee.h"
s32 Mc_StepCheck_4_001D3E30(void);
s32 Mc_StepGetDir_4_001D3FE8(void);
s32 Mc_StepReadChecked_3_001D4A78(void);
s32 Mc_StepWrite_4_001D5280(void);
s32 Mc_StepCopyFile_4_001D58C0(void);
s32 Mc_StepFormat_4_001D6428(void);
s32 Mc_StepChdir_5_001D6550(void);
s32 Mc_StepMkdir_5_001D6688(void);
s32 Mc_StepRead_4_001D5F88(void);
s32 Mc_StepFindFile_5_001D67A8(void);

s32 Mc_Update_4_001D6D00(void) {
    s32 r = -1;
    s32 s;
    switch (gMcState_004B63B8.cmd) {
    case 3: r = Mc_StepCheck_4_001D3E30(); break;
    case 4: r = Mc_StepGetDir_4_001D3FE8(); break;
    case 5: r = Mc_StepWriteChecked_3_001D4170(); break;
    case 6: r = Mc_StepReadChecked_3_001D4A78(); break;
    case 7: r = Mc_StepWrite_4_001D5280(); break;
    case 8: r = Mc_StepCopyFile_4_001D58C0(); break;
    case 9: r = Mc_StepFormat_4_001D6428(); break;
    case 10: r = Mc_StepChdir_5_001D6550(); break;
    case 11: r = Mc_StepMkdir_5_001D6688(); break;
    case 12: r = Mc_StepRead_4_001D5F88(); break;
    case 13: r = Mc_StepFindFile_5_001D67A8(); break;
    case 0: return 0;
    case 1:
    case 2: r = -1; break;
    }    if (r < 0) {
        r = -gMcState_004B63B8.cmd;
        gMcState_004B63B8.step = 0;
        gMcState_004B63B8.cmd = 0;
        s = -100;
        if (r != 0) s = r;
        return s;
    }    if (r > 0) {
        gMcState_004B63B8.cmd = 0;
        gMcState_004B63B8.step = 0;
        return 0;
    }
    return gMcState_004B63B8.cmd;
}
