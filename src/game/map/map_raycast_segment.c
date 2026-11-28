/* Best-effort C for the NONMATCHING build; the matching attempt is
 * Map_RaycastSegment_0_00145A80.c (an inline-assembly match in wip/), whose VU0
 * distance is FPU math here. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
typedef struct { Vec a; Vec b; } Ray;
typedef struct { u128 q[4]; } Res;
typedef struct { u8 pad[0x6E]; u16 n; u8 pad70[0x168]; u8 f1D8; } Obj;
void sceVu0CopyVector(Vec *, Vec *);
s32 MapColl_CapsuleCast_1_001B2800(Obj *, Res *, Ray *, u16, u8, u8);
extern s32 D_00201E80;
f32 sqrtf(f32);
/* out->x = |b - a| (the retail VU0 sequence: z += x, z += y, sqrt) */
static inline void vdist(Vec *out, Vec *a, Vec *b) {
    f32 dx = b->x - a->x, dy = b->y - a->y, dz = b->z - a->z;
    out->x = sqrtf((dz * dz + dx * dx) + dy * dy);
}

s32 Map_RaycastSegment_0_00145A80(Vec *a_, Vec *b, u8 m, s32 n, Res *out_) {
    f32 best[2];
    s32 ok[2];
    Res hit[2];
    Ray ray;
    Res res;
    Vec dv;
    Res *out;
    s32 i;
    Vec *a;
    s32 j;
    s32 cnt;
    Obj ***q;
    s32 *okp;
    Res *hp;
    f32 *bp;
    f32 min;
    Res *p;
    Obj *o;
    s32 o0;
    s32 r;

    out = out_;
    a = a_;

    sceVu0CopyVector(&ray.a, a);
    sceVu0CopyVector(&ray.b, b);
    i = 0;
    q = (Obj ***)(&D_00201E80 + 2);
    okp = ok;
    hp = hit;
    bp = best;
    do {
        if (*q == 0 || !((o = **q)->f1D8 & 1)) {
            *okp = 0;
        } else {
            min = 100000.0f;
            cnt = 0;
            j = 0;
            if (0 < o->n) {
                do {
                    if (MapColl_CapsuleCast_1_001B2800(o, &res, &ray, j, m, n)) {
                        vdist(&dv, a, (Vec *)&res);
                        if (dv.x < min) {
                            min = dv.x;
                            cnt++;
                            *hp = res;
                        }
                    }
                    j++;
                } while (j < (o = **q)->n);
            }
            *okp = cnt > 0;
            *bp = min;
        }
        i++;
        q++;
        okp++;
        hp++;
        bp++;
    } while (i < 2);
    o0 = ok[0];
    if (o0 && ok[1]) {
p = hit; p = (best[1] < best[0]) ? &hit[1] : p;
        *out = *p;
    } else if (o0) {
        *out = hit[0];
    } else if (ok[1]) {
        *out = hit[1];
    }
return o0 != 0 || ok[1] != 0;
}
#else
INCLUDE_ASM(Map_RaycastSegment_0_00145A80);
#endif
