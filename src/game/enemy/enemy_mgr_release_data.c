/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/EnemyMgr_ReleaseData_0_001A51E0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "m2c.h"
typedef struct { volatile s32 v; s8 pad[0x24]; } E;
extern E gEnemyDataTbl_004A43B0[];
extern E gEnemyManagerBss_004A43B4[];
extern E gEnemyManagerBss_004A43C8[];
extern E gEnemyManagerBss_004A43D0[];
typedef struct { s16 key; s8 pad2[0xA]; s32 xC; s8 pad[0x5A0 - 0x10]; u16 a0:1; u16 a1:1; u16 a2:1; u16 b:8; } B;

void EnemyMgr_ReleaseData_0_001A51E0(B **arg0) {
    B *p = *arg0;
    s16 key = p->key;
    s32 i;

    for (i = 0; i < 11; i++) {
        if (key == gEnemyDataTbl_004A43B0[i].v) break;
    }
    if (i != 11) {
        p->xC = gEnemyManagerBss_004A43C8[i].v;
        p->a1 = 1;
        p->b = i + 1;
        return;
    }
    for (i = 0; i < 11; i++) {
        if (gEnemyDataTbl_004A43B0[i].v == -1) break;
    }
    gEnemyDataTbl_004A43B0[i].v = key;
    gEnemyManagerBss_004A43B4[i].v = 0;
    gEnemyManagerBss_004A43D0[i].v = 0;
    p->xC = 0;
    p->a1 = 1;
    p->b = i + 1;
}
#else
INCLUDE_ASM(EnemyMgr_ReleaseData_0_001A51E0);
#endif
