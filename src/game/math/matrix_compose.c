#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
extern Mtx gMdlCreateInstanceData_001F2340;
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixZ(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0TransMatrix(Mtx *, Mtx *, Vec *);

void Mtx_Compose_2_00173FD0(Mtx *m, Vec *t, Vec *r, Vec *s) {
    sceVu0CopyMatrix(m, &gMdlCreateInstanceData_001F2340);
    m->m[0].x = s->x;
    m->m[1].y = s->y;
    m->m[2].z = s->z;
    sceVu0RotMatrixX(m, m, WRAP(r->x));
    sceVu0RotMatrixZ(m, m, WRAP(r->z));
    sceVu0RotMatrixY(m, m, WRAP(r->y));
    sceVu0TransMatrix(m, m, t);
}
