#include "common.h"
#include "m2c.h"
#include "game/effect.h"
#include "game/data.h"
typedef struct { u8 pad[6]; u16 m6; u8 pad8[0x38]; u8 m40[1]; } Mdl;
typedef struct { u8 pad[0xA]; u16 xA; u8 xC; u8 padD; u16 xE; } S;
typedef struct { u8 pad[0x10]; s32 x10; } M;
typedef struct { M *m; } O;
typedef struct { O *o; u8 pad4[2]; u16 x6; u8 pad8[0x38]; s8 x40[1]; } A0;
typedef struct { u8 pad[0xA]; u16 xA; u8 xC; u8 pad2; u16 xE; } E;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } F;
typedef union { u16 h; F f; } FU;
typedef struct { f32 v[4]; } V4;
typedef struct { f32 m[8]; } V8;
typedef struct { u8 pad[4]; u32 x4; f32 x8; f32 xC; V4 v; V8 m; } Src;
typedef struct { u8 a; u8 b0:1; u8 b1:1; } W;
typedef union { u32 w; W f; } WU;
typedef struct { V4 v; V8 m; WU w; u8 pad[0xC]; } Dst;
void Attack_PlaySe_0_001D1E80(Mdl *m, u8 id, S *s, f32 *tbl);
s8* Attack_SpawnSfx_0_001D1F20(A0 *a0, void *a1, s32 a2, u8 a3, E *e, s32 *tbl);
void sceVu0CopyVector(Vec *, void *);
void Snd_PlaySeAt_2_001315A0(s32 a, s32 b, Vec *v);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
s8* Sfx_SpawnFromStam_2_00169BD0(s32, s32, void *, s32, s32, s32);
void Mtx_Compose_2_00173FD0(void *, f32 *, f32 *, f32 *);
void sceVu0MulMatrix(void *, void *, void *);
void Sfx_SetTransform_1_001677C0(s8 *, void *);
Src* EnemyType_Get_0_001A8360(u16);
void memset(void *, s32, s32);
void Sfx_GetState_0_001672B0(s8 *, Dst *);
void Sfx_AimMatrix_0_00167310(s8 *, f32, f32);

/* Attack_PlaySe_0_001D1E80 */
void Attack_PlaySe_0_001D1E80(Mdl *m, u8 id, S *s, f32 *tbl) {
    Vec v;
    f32 *p;
    s8 *base;
    p = tbl + s->xE + s->xC;
    base = (s8 *)(gSfxAllSbss_00201F2C * (m->m6 * 0x140 + 0x200) + (s32)m->m40);
    sceVu0CopyVector(&v, base + (id + 1) * 0x140 + 0xF0);
    Snd_PlaySeAt_2_001315A0(s->xA, (s32)*p, &v);
}

/* Attack_SpawnSfx_0_001D1F20 */
s8 *Attack_SpawnSfx_0_001D1F20(A0 *a0, void *a1, s32 a2, u8 a3, E *e, s32 *tbl) {
    FU fl;
    f32 mat[4][4];
    Dst d;
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    s32 *base;
    f32 *s5;
    s8 *s4;
    s32 id;
    s8 *obj;
    Src *src;
    s32 k;

    s4 = (s8 *)((s32)a0 + 0x40) + gSfxAllSbss_00201F2C * (a0->x6 * 0x140 + 0x200);
    base = &tbl[e->xE];
    s5 = (f32 *)&base[e->xC];
    id = base[0];
    fl.h = base[1];
    if (id == 0) {
        return 0;
    }
    if (Sfx_IsLoaded_2_00169BB0(id)) {
        obj = Sfx_Spawn_2_00169B50(id, fl.f.b0, fl.f.b1, fl.f.b2);
    } else {
        obj = Sfx_SpawnFromStam_2_00169BD0(id, a0->o->m->x10, a1, fl.f.b0, fl.f.b1, fl.f.b2);
    }
    if (obj != 0) {
        pos[0] = s5[0];
        pos[1] = s5[1];
        pos[2] = s5[2];
        rot[0] = 3.1415927f * s5[3] / 180.0f;
        rot[1] = 3.1415927f * s5[4] / 180.0f;
        rot[2] = 3.1415927f * s5[5] / 180.0f;
        scl[0] = s5[6];
        scl[1] = s5[7];
        scl[2] = s5[8];
        Mtx_Compose_2_00173FD0(mat, pos, rot, scl);
        sceVu0MulMatrix(mat, s4 + (a3 + 1) * 0x140 + 0xC0, mat);
        Sfx_SetTransform_1_001677C0(obj, mat);
        if ((k = e->xA) != 0) {
            src = EnemyType_Get_0_001A8360(k);
            if (src != 0) {
                memset(&d, 0, 0x40);
                d.v = src->v;
                d.m = src->m;
                d.w.w = src->x4;
                d.w.f.b1 = 1;
                Sfx_GetState_0_001672B0(obj, &d);
                Sfx_AimMatrix_0_00167310(obj, src->x8, src->xC);
            }
        }
    }
    return obj;
}
