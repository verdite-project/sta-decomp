#include "m2c.h"
typedef struct { f32 x, y, z, w; } V;
typedef union { u128 q[4]; f32 f[16]; } M;
typedef struct { u8 pad[0x1D8]; u8 f; } O;
extern s32 gMapSbss_00201E80;
void sceVu0CopyVector(V *, V *);
s32 MapColl_CapsuleCastAll_1_001B3240(O *, M *, V *, s32, u8);

s32 Map_RaycastCapsule_0_00145D10(V *a0, V *a1, s32 a2, s32 a3, M *out) {
    s32 res[2];
    M m[2];
    V seg[2];
    s32 i;
    M *p;
    if ((u8)a2 == 0) return 0;
    sceVu0CopyVector(&seg[0], a0);
    sceVu0CopyVector(&seg[1], a1);
    for (i = 0; i < 2; i++) {
        O **q = ((O ***)((s8 *)&gMapSbss_00201E80 + 8))[i];
        if (q == 0 || !((*q)->f & 1)) res[i] = 0;
        else res[i] = MapColl_CapsuleCastAll_1_001B3240(*q, &m[i], seg, a2, a3);
    }
    if (res[0] && res[1]) {
        p = &m[0]; if (m[1].f[3] < m[0].f[3]) p = &m[1]; *out = *p;
    } else if (res[0]) {
        *out = m[0];
    } else if (res[1]) {
        *out = m[1];
    }
    return res[0] || res[1];
}
