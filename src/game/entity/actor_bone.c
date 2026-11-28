#include "common.h"
#include "game/data.h"
typedef struct { Mtx m; u8 pad[0x100]; } Bone;
typedef struct { u8 pad[6]; u16 h6; } Hdr;
typedef struct { u8 pad[0x1A8]; Hdr *x1A8; } Sub_Actor_GetBoneWorldMatrix_0_001464A0;
typedef struct { u8 pad[0x518]; Sub_Actor_GetBoneWorldMatrix_0_001464A0 *x518; } A_Actor_GetBoneWorldMatrix_0_001464A0;
typedef struct { f32 a[8]; f32 v[4]; f32 b[4]; } T;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } P;
typedef struct { u8 pad[0x18]; P *p; } Sub_Actor_BuildRotMatrix_0_00146600;
typedef struct { u8 pad[0x518]; u8 *x518; } A_Actor_BuildRotMatrix_0_00146600;
typedef struct { u8 pad[0x1A8]; Hdr *x1A8; } Sub_Actor_GetBone_0_001468F0;
typedef struct { u8 pad[0x518]; Sub_Actor_GetBone_0_001468F0 *x518; } A_Actor_GetBone_0_001468F0;
extern Mtx gMatrixFromData_001F2170;
s32 Actor_GetBoneWorldMatrix_0_001464A0(A_Actor_GetBoneWorldMatrix_0_001464A0 *a, u8 idx, Mtx *out);
void Actor_GetDirNormalized_0_00146570(void *a, f32 *v);
void Actor_GetDir_1_001465C0(void *a, f32 *v);
void Actor_BuildRotMatrix_0_00146600(A_Actor_BuildRotMatrix_0_00146600 *a, Mtx *m);
Bone* Actor_GetBone_0_001468F0(A_Actor_GetBone_0_001468F0 *a, u8 idx);
void sceVu0CopyVector(void *, void *);
void Mtx_AxisAngle_2_0015EBB0(f32, Mtx *, Vec *);
void sceVu0MulMatrix(Mtx *, Mtx *, Bone *);
void sceVu0Normalize(f32 *v0, f32 *v1);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
void sceVu0CopyMatrix(Mtx *, Mtx *);

/* Actor_GetBoneWorldMatrix_0_001464A0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Actor_GetBoneWorldMatrix_0_001464A0
void sceVu0CopyVector__as_Actor_GetBoneWorldMatrix_0_001464A0(Vec *, Vec *);

s32 Actor_GetBoneWorldMatrix_0_001464A0(A_Actor_GetBoneWorldMatrix_0_001464A0 *a, u8 idx, Mtx *out) {
    Mtx m;
    Vec v;
    Hdr *h;
    Bone *b;
    h = a->x518->x1A8;
    b = &((Bone *)((u8 *)((s32)h + 0x40) + gSfxAllSbss_00201F2C * (h->h6 * 0x140 + 0x200) + 0xC0))[idx + 1];
    if (b != 0) {
        sceVu0CopyVector(&v, &b->m.m[3]);
        Mtx_AxisAngle_2_0015EBB0(3.1415927f, &m, &b->m.m[1]);
        sceVu0MulMatrix(out, &m, b);
        sceVu0CopyVector(&out->m[3], &v);
        return 1;
    }
    return 0;
}
#undef sceVu0CopyVector

/* Actor_GetDirNormalized_0_00146570 */
#define Actor_BuildRotMatrix_0_00146600 Actor_BuildRotMatrix_0_00146600__as_Actor_GetDirNormalized_0_00146570
void Actor_BuildRotMatrix_0_00146600__as_Actor_GetDirNormalized_0_00146570(void *a, T *t);
#define sceVu0CopyVector sceVu0CopyVector__as_Actor_GetDirNormalized_0_00146570
void sceVu0CopyVector__as_Actor_GetDirNormalized_0_00146570(f32 *v0, f32 *v1);

void Actor_GetDirNormalized_0_00146570(void *a, f32 *v)
{
    T t;
    Actor_BuildRotMatrix_0_00146600(a, &t);
    sceVu0CopyVector(v, t.v);
    v[1] = 0.0f;
    sceVu0Normalize(v, v);
}
#undef Actor_BuildRotMatrix_0_00146600
#undef sceVu0CopyVector

/* Actor_GetDir_1_001465C0 */
#define Actor_BuildRotMatrix_0_00146600 Actor_BuildRotMatrix_0_00146600__as_Actor_GetDir_1_001465C0
void Actor_BuildRotMatrix_0_00146600__as_Actor_GetDir_1_001465C0(void *a, T *t);
#define sceVu0CopyVector sceVu0CopyVector__as_Actor_GetDir_1_001465C0
void sceVu0CopyVector__as_Actor_GetDir_1_001465C0(f32 *v0, f32 *v1);

void Actor_GetDir_1_001465C0(void *a, f32 *v)
{
    T t;
    Actor_BuildRotMatrix_0_00146600(a, &t);
    sceVu0CopyVector(v, t.v);
}
#undef Actor_BuildRotMatrix_0_00146600
#undef sceVu0CopyVector

/* Actor_BuildRotMatrix_0_00146600 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0CopyVector sceVu0CopyVector__as_Actor_BuildRotMatrix_0_00146600
void sceVu0CopyVector__as_Actor_BuildRotMatrix_0_00146600(Vec *, P *);

void Actor_BuildRotMatrix_0_00146600(A_Actor_BuildRotMatrix_0_00146600 *a, Mtx *m) {
    Sub_Actor_BuildRotMatrix_0_00146600 *s;
    if (a != NULL) {
        s = (Sub_Actor_BuildRotMatrix_0_00146600 *)(a->x518 + 0x180);
        sceVu0RotMatrixX(WRAP(WRAP(s->p->x20)), m, &gMatrixFromData_001F2170);
        sceVu0RotMatrixY(WRAP(WRAP(3.1415927f + s->p->x24)), m, m);
        sceVu0CopyVector(&m->m[3], s->p);
        m->m[3].w = 1.0f;
    } else {
        sceVu0CopyMatrix(m, &gMatrixFromData_001F2170);
    }
}
#undef sceVu0CopyVector

/* Actor_GetBone_0_001468F0 */
Bone *Actor_GetBone_0_001468F0(A_Actor_GetBone_0_001468F0 *a, u8 idx) {
    Hdr *h;
    h = a->x518->x1A8;
    return &((Bone *)((u8 *)((s32)h + 0x40) + gSfxAllSbss_00201F2C * (h->h6 * 0x140 + 0x200) + 0xC0))[idx + 1];
}
