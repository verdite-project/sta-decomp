#include "m2c.h"
#include "game/core.h"
#include "game/data.h"
typedef struct { volatile s32 v; s8 pad[0x24]; } E;
void Pool_Free_2_00128580(s32, s32);
extern E gEnemyDataTbl_004A43B0[];
extern E gEnemyManagerBss_004A43B4[];
extern E gEnemyManagerBss_004A43B8[];
extern E gEnemyManagerBss_004A43BC[];
extern E gEnemyManagerBss_004A43C8[];
extern E gEnemyManagerBss_004A43CC[];
extern E gEnemyManagerBss_004A43D0[];
typedef struct { s8 pad[0x5A0]; u16 a:3; u16 b:8; } B;

void EnemyMgr_FreeSlot_0_001A5070(s8 **arg0) {
    s16 idx;
    E *p;

    idx = ((B*)*arg0)->b - 1;
    gEnemyManagerBss_004A43BC[idx].v--;
    if (gEnemyManagerBss_004A43BC[idx].v <= 0) {
        if (gEnemyMgrUpdateSdata_00201DA8 == idx && gEnemyManagerBss_004A43B4[idx].v == 0) {
            p = &gEnemyManagerBss_004A43C8[idx];
            if (p->v != 0) {
                Pool_Free_2_00128580(gEnemyListSbss_00202278, p->v);
                p->v = 0;
            }
            if (gEnemyMgrUpdateSdata_00201DA8 != -1 && gEnemyManagerBss_004A43B8[gEnemyMgrUpdateSdata_00201DA8].v != 0) {
                Task_RunWrap_0_0014DAB0(gEnemyManagerBss_004A43B8[gEnemyMgrUpdateSdata_00201DA8].v);
                gEnemyManagerBss_004A43B8[gEnemyMgrUpdateSdata_00201DA8].v = 0;
            }
            gEnemyMgrUpdateSdata_00201DA8 = -1;
        }
        gEnemyManagerBss_004A43B4[idx].v = 0;
        gEnemyDataTbl_004A43B0[idx].v = -1;
        gEnemyManagerBss_004A43CC[idx].v = 0;
        gEnemyManagerBss_004A43D0[idx].v = 0;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_byte_bss.c): gEnemyDataTbl_004A43B0__grp: gEnemyDataTbl_004A43B0@0x0, gEnemyManagerBss_004A43B4@0x4, gEnemyManagerBss_004A43B8@0x8, gEnemyManagerBss_004A43BC@0xc, gEnemyManagerBss_004A43C0@0x10, gEnemyManagerBss_004A43C4@0x14, gEnemyManagerBss_004A43C8@0x18, gEnemyManagerBss_004A43CC@0x1c, gEnemyManagerBss_004A43D0@0x20, gEnemyManagerBss_004A4540@0x190 */
u8 gEnemyDataTbl_004A43B0__grp[0x1c0] __attribute__((aligned(16)));
#endif
