#include "common.h"
#include "game/ee.h"
typedef struct { s32 a[4][4]; s32 b[4][4]; s32 i; s32 j; } T;
#define G gMcState_004B63B8
s32 Mc_GetInfoStatus_2_001D3CE0(s32 n) {
    T *t = &G;
    s32 i = t->i;
    s32 j = t->j;
    s32 r;
    if (n >= 0) {
        if (t->b[i][j] == 0) return t->a[i][j] != 3 ? 3 : 1;
        return t->a[i][j] == 3;
    }
    if (n == -1) return t->a[i][j] == 3 ? 1 : 2;
    if (n == -2) return t->a[i][j] == 3 ? 1 : 4;
    if (n < -10 || n == -5) return 1;
    return 100;
}

