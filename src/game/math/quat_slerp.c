/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Quat_Slerp_2_0015DFA0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "m2c.h"
#include "common.h"
f32 sinf(f32);
f32 acosf(f32);
u64 fptodp(f32);
u64 fabs(u64);
s32 __gtdf2(u64, u64);
void sceVu0CopyVector(Vec *, Vec *);
void Quat_Slerp_2_0015DFA0(Vec *out, Vec *a, Vec *b, f32 t) {
    Vec A;
    Vec B;
    f32 *pay, *paz, *paw, *pby, *pbz, *pbw;
    f32 s;
    f32 inv;
    f32 k1;
    f32 k2;
    if (!__gtdf2(0x3E80000000000000ULL, fabs(fptodp(sinf(a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w))))) {
        sceVu0CopyVector(&A, a);
        sceVu0CopyVector(&B, b);
        pay=&A.y;paz=&A.z;paw=&A.w;pby=&B.y;pbz=&B.z;pbw=&B.w;
        s = acosf(A.x * B.x + *pay * *pby + *paz * *pbz + *paw * *pbw);
        inv = 1.0f / sinf(s);
        k1 = sinf((1.0f - t) * s);
        k2 = sinf(t * s);
        out->x = inv * (A.x * k1 + B.x * k2);
        out->y = inv * (*pay * k1 + *pby * k2);
        out->z = inv * (*paz * k1 + *pbz * k2);
        out->w = inv * (*paw * k1 + *pbw * k2);
    }
}
#else
INCLUDE_ASM(Quat_Slerp_2_0015DFA0);
#endif
