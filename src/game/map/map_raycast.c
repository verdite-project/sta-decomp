#include "m2c.h"
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { Q a; Q b; } Ray;
typedef union { u128 q[4]; f32 f[16]; } S;
s32 MapColl_RayCast_0_001B23E0(u8 *, S *, Ray *, u16, u8, u8);
extern s32 gMapSbss_00201E80;

s32 Map_RaycastNearest_0_00145840(Ray *ray, u8 a1, s32 a2, S *out) {
    s32 found[2];
    S best[2];
    S cur;
    s32 i;
    s32 j;
    s32 n;
    u8 ***pp;
    s32 *pf;
    S *pb;
    f32 min;
    S *p;

    for (i = 0, pp = (u8 ***)(&gMapSbss_00201E80 + 2), pf = found, pb = best; i < 2; i++, pp++, pf++, pb++) {
        if (*pp == 0 || ((**pp)[0x1D8] & 1) == 0) {
            *pf = 0;
            continue;
        }
        min = 100000.0f;
        n = 0;
        for (j = 0; j < *(u16 *)(**pp + 0x6E); j++) {
            if (MapColl_RayCast_0_001B23E0(**pp, &cur, ray, j, a1, a2) != 0 && cur.f[3] < min) {
                n++;
                min = cur.f[3];
                *pb = cur;
            }
        }
        *pf = n > 0;
    }
    if (found[0] != 0 && found[1] != 0) {
        p = &best[0];
        if (best[1].f[3] < best[0].f[3]) {
            p = &best[1];
        }
        *out = *p;
    } else if (found[0] != 0) {
        *out = best[0];
    } else if (found[1] != 0) {
        *out = best[1];
    }
    return found[0] != 0 || found[1] != 0;
}
