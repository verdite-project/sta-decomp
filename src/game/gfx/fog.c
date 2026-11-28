#include "common.h"
#include "game/data.h"
#include "game/gfx.h"
typedef struct {
    Vec x0;
    Vec x10;
    Vec x20;
    Vec x30;
    Vec x40;
    Vec x50;
    Vec x60;
    Vec x70;
    Vec x80;
    Vec x90;
} O;
typedef struct { Vec v0; Vec a[4]; Vec b[4]; Vec c; } D30;
extern Mtx gMatrixFromData_001F2170;
extern Vec gFogData_001F2060[];
extern Vec gPlayerData_001F2080[];
extern Vec gPlayerData_001F20C0[];
extern Vec gMatrixFromData_001F2110[];
extern D30 gGlowInitBss_0030D0E0;
void Fog_BuildPlanes_0_0015CD30(O *o, Vec *a, Vec *b, Vec *c, Vec *d, Vec *pa, Vec *pb, Vec *pc, Vec *q0, Vec *q1, Vec *q2);
void sceVu0RotMatrixZ(f32, Mtx *, Mtx *);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);

/* Fog_BuildPlanes_0_0015CD30 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define DEG(d) (3.1415927f * (d) / 180.0f)

void Fog_BuildPlanes_0_0015CD30(O *o, Vec *a, Vec *b, Vec *c, Vec *d, Vec *pa, Vec *pb, Vec *pc, Vec *q0, Vec *q1, Vec *q2) {
    Mtx m1;
    Mtx m2;
    Mtx m3;
    Mtx m4;

    sceVu0RotMatrixZ(WRAP(DEG(a->y)), &m1, &gMatrixFromData_001F2170);
    sceVu0RotMatrixY(WRAP(DEG(a->x)), &m1, &m1);
    o->x10.x = m1.m[0].x;
    o->x10.y = m1.m[0].y;
    o->x10.z = m1.m[0].z;
    o->x10.w = a->w;
    sceVu0CopyVector(&o->x50, pa);
    sceVu0RotMatrixZ(WRAP(DEG(b->y)), &m2, &gMatrixFromData_001F2170);
    sceVu0RotMatrixY(WRAP(DEG(b->x)), &m2, &m2);
    o->x20.x = m2.m[0].x;
    o->x20.y = m2.m[0].y;
    o->x20.z = m2.m[0].z;
    o->x20.w = b->w;
    sceVu0CopyVector(&o->x60, pb);
    sceVu0RotMatrixZ(WRAP(DEG(c->y)), &m3, &gMatrixFromData_001F2170);
    sceVu0RotMatrixY(WRAP(DEG(c->x)), &m3, &m3);
    o->x30.x = m3.m[0].x;
    o->x30.y = m3.m[0].y;
    o->x30.z = m3.m[0].z;
    o->x30.w = c->w;
    sceVu0CopyVector(&o->x70, pc);
    sceVu0RotMatrixZ(WRAP(DEG(d->y)), &m4, &gMatrixFromData_001F2170);
    sceVu0RotMatrixY(WRAP(DEG(d->x)), &m4, &m4);
    o->x40.x = m4.m[0].x;
    o->x40.y = m4.m[0].y;
    o->x40.z = m4.m[0].z;
    o->x40.w = d->w;
    sceVu0CopyVector(&o->x80, q0);
    sceVu0CopyVector(&o->x0, q1);
    sceVu0CopyVector(&o->x90, q2);
}

/* Fog_UpdatePlanes_0_0015D300 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define DEG(d) (3.1415927f * (d) / 180.0f)

void Fog_UpdatePlanes_0_0015D300(void) {
    Mtx m;
    s32 i;

    for (i = 0; i < 4; i++) {
        sceVu0RotMatrixZ(WRAP(DEG(gPlayerData_001F2080[i].y)), &m, &gMatrixFromData_001F2170);
        sceVu0RotMatrixY(WRAP(DEG(gPlayerData_001F2080[i].x)), &m, &m);
        gGlowInitBss_0030D0E0.a[i].x = m.m[0].x;
        gGlowInitBss_0030D0E0.a[i].y = m.m[0].y;
        gGlowInitBss_0030D0E0.a[i].z = m.m[0].z;
        gGlowInitBss_0030D0E0.a[i].w = gPlayerData_001F2080[i].w;
        gGlowInitBss_0030D0E0.b[i].x = gPlayerData_001F20C0[i].x;
        gGlowInitBss_0030D0E0.b[i].y = gPlayerData_001F20C0[i].y;
        gGlowInitBss_0030D0E0.b[i].z = gPlayerData_001F20C0[i].z;
    }
    gMatrixFromData_001F2110[0].x = gFogData_001F2060[0].x;
    gMatrixFromData_001F2110[0].y = gFogData_001F2060[0].y;
    gMatrixFromData_001F2110[0].z = gFogData_001F2060[0].z;
    gMatrixFromData_001F2110[0].w = gFogData_001F2060[0].w;
    gGlowInitBss_0030D0E0.v0.x = gPlayerData_001F2070[0].x;
    gGlowInitBss_0030D0E0.v0.y = gPlayerData_001F2070[0].y;
    gGlowInitBss_0030D0E0.v0.z = gPlayerData_001F2070[0].z;
    gGlowInitBss_0030D0E0.v0.w = gPlayerData_001F2070[0].w;
    sceVu0CopyVector(&gGlowInitBss_0030D0E0.c, gMatrixFromData_001F2100);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/screen_fx_flash_data.c): D_001F2060__grp: gFogData_001F2060@0x0, gFogData_001F2064@0x4, gFogData_001F2068@0x8, gFogData_001F206C@0xc */
f32 D_001F2060__grp[0x4] __attribute__((aligned(16))) = { 1.0f, 0.0f, 0.0f, 0.0f };
#endif
