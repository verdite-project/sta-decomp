/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/EnemyData_Alloc_0_001A7D90.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "m2c.h"
typedef struct { s16 x0; u16 x2; } P;
extern s32 D_00202278;
extern P **D_004A4570[];
extern s16 D_004A4774[];
extern u16 D_004A4776[];
P **Pool_Alloc_3_001288C0(s32, s32);
void memset(P *, s32, s32);
void EnemyMgr_ReleaseData_0_001A51E0(P **, s32);
static inline s32 reg(P **h) {
    P *p = *h;
    memset(p, 0, 0x750);
    D_004A4570[p->x2 = D_004A4776[--D_004A4774[0]]] = h;
    return 1;
}

P **EnemyData_Alloc_0_001A7D90(s16 a) {
    P ** volatile h;
    h = Pool_Alloc_3_001288C0(D_00202278, 0x750);
    if (!reg(h)) return NULL;
    (*h)->x0 = a;
    EnemyMgr_ReleaseData_0_001A51E0(h, 1);
    return h;
}
#else
INCLUDE_ASM(EnemyData_Alloc_0_001A7D90);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif
