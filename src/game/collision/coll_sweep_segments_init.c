/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Coll_SweepSegmentsInit_1_00151E50.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 1 word: the clear loop of RPair C counts 0x10, retail 8. An 8-byte C clears 8
 * but moves to the small-object group at the top of the frame (45 words off); C[2],
 * aligned(16) types or vars and extra locals did not give an 8-byte clear in a 16-byte slot. */
#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; } Res;
typedef struct { Vec a; Vec b; s32 x20; s32 x24; s32 x28; } Out;
typedef struct { Seg *a; Seg *b; } Pair;
typedef union { struct { Res *a; Res *b; } p; s32 w[4]; } RPair;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);
void Seg_ClosestPoints_3_00151B20(Res *, Seg *, Seg *);
void Coll_SweepRecursive_0_00150730(Out *, Seg **, Seg **, RPair *, s32 *, f32 *, f32, f32, f32);
float sqrtf(float);
extern Vec gZeroVec_003139A0;
extern s32 gCollSweepSegmentsInitSbss_00201F24;

static inline void inner(Out *out, Seg *a1, Seg *a2, Seg *a3, Seg *a4) {
    s32 flag;
    f32 f;
    Seg *A[2] = {a1, a2};
    Seg *B[2] = {a3, a4};
    Res r2;
    Res r1;
    Vec v80;
    Vec v70;
    Vec v60;
    Vec v50;
    f32 k;
    Res *rp;
    flag = 0;
    Seg_ClosestPoints_3_00151B20(&r1, A[0], B[0]);
    if (r1.hit) {
        sceVu0CopyVector(&out->a, &gZeroVec_003139A0);
        sceVu0ScaleVector(&v80, &r1.a, 0.5f);
        sceVu0AddVector(&out->a, &v80, &out->a);
        sceVu0ScaleVector(&v70, &r1.b, 0.5f);
        sceVu0AddVector(&out->a, &v70, &out->a);
        sceVu0CopyVector(&out->b, &r1.c);
        out->x20 = 0;
        out->x24 = 0;
        out->x28 = 2;
    } else {
    rp = &r2;
    Seg_ClosestPoints_3_00151B20(rp, A[1], B[1]);
    if (rp->hit) flag = 1;
    while (flag == 0) {
        sceVu0Normalize(&v60, &r1.c);
        sceVu0Normalize(&v50, &r2.c);
        if (sceVu0InnerProduct(&v60, &v50) < 0.5f) break;
        return;
    }
    {
        RPair C = {{&r1, rp}};
        k = 2.0f / (sqrtf(sceVu0InnerProduct(&r1.c, &r1.c)) + sqrtf(sceVu0InnerProduct(&r2.c, &r2.c)));
        if (!(k <= 1.0f)) k = 0.1f;
        f = 1.0f;
        gCollSweepSegmentsInitSbss_00201F24 = 0;
        Coll_SweepRecursive_0_00150730(out, A, B, &C, &flag, &f, 0.0f, 1.0f, k);
        if (flag) out->x28 = 1;
    }
    }
}




void Coll_SweepSegmentsInit_1_00151E50(Out *out, Seg *a1, Seg *a2, Seg *a3, Seg *a4) {
    out->x28 = 0;
    inner(out, a1, a2, a3, a4);
}
#else
INCLUDE_ASM(Coll_SweepSegmentsInit_1_00151E50);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gCollSweepSegmentsInitSbss_00201F24 */
s32 gCollSweepSegmentsInitSbss_00201F24;
#endif
