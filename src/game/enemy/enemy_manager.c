#include "m2c.h"
#include "game/core.h"
#include "game/data.h"
typedef struct { volatile s32 v; s8 pad[0x24]; } E;
void Pool_Free_2_00128580(s32, s32);
extern E gEnemyDataTbl_004A43B0[];
extern E D_004A43B4[];
extern E D_004A43B8[];
extern E D_004A43BC[];
extern E D_004A43C8[];
extern E D_004A43CC[];
extern E D_004A43D0[];
typedef struct { s8 pad[0x5A0]; u16 a:3; u16 b:8; } B;

void EnemyMgr_FreeSlot_0_001A5070(s8 **arg0) {
    s16 idx;
    E *p;

    idx = ((B*)*arg0)->b - 1;
    D_004A43BC[idx].v--;
    if (D_004A43BC[idx].v <= 0) {
        if (D_00201DA8 == idx && D_004A43B4[idx].v == 0) {
            p = &D_004A43C8[idx];
            if (p->v != 0) {
                Pool_Free_2_00128580(D_00202278, p->v);
                p->v = 0;
            }
            if (D_00201DA8 != -1 && D_004A43B8[D_00201DA8].v != 0) {
                Task_RunWrap_0_0014DAB0(D_004A43B8[D_00201DA8].v);
                D_004A43B8[D_00201DA8].v = 0;
            }
            D_00201DA8 = -1;
        }
        D_004A43B4[idx].v = 0;
        gEnemyDataTbl_004A43B0[idx].v = -1;
        D_004A43CC[idx].v = 0;
        D_004A43D0[idx].v = 0;
    }
}
