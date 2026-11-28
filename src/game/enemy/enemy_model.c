#include "common.h"
#include "m2c.h"
#include "game/data.h"
typedef struct {
    Vec v0;
    Vec v10;
    Vec rot;
    Vec v30;
    Vec v40;
    f32 s50, s54, s58, s5C;
    Mtx m;
    u8 padA0[0x10];
    s32 *xB0;
} N;
typedef struct {
    u8 pad[0x244];
    u16 x244, x246, x248;
} I;
typedef struct {
    f32 x0, x4, x8;
    s32 xC;
    N *x10;
    s32 x14;
    N *x18;
    I *x1C;
    s32 x20;
    s32 *x24;
    s32 x28;
    s8 *x2C;
    u8 pad30[0x10];
    Vec v40;
    Vec v50;
    Mtx m;
    Vec vA0;
    u8 padB0[0x44];
    s32 xF4;
} P;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x4A8];
    I *x4B0;
    u8 pad4B4[0x60];
    s32 x514;
    s8 *x518;
    s32 x51C;
} A;
typedef struct { u8 pad[0x204]; s16 n; s16 a[0x81]; u8 pad2[2]; } T;
typedef struct { u16 a, b, c, n; u8 pad[0x38]; s8 data[1]; } Hd;
typedef struct { u8 pad[0xC]; u8 a:6; u8 en:1; u8 b:1; } Fl;
typedef struct { u8 pad[0x124]; s32 h[8]; } Obj;
typedef struct { u8 pad[0x18]; Obj *objs; s8 *ents; } O;
extern Mtx gMatrixFromData_001F2170;
extern T gEnemyListBss_004A4570;
extern u8 *gEnemyModelSbss_00202284;
extern s32 gEnemyModelSbss_00202284__as_EnemyType_LoadTable_0_001A83A0;
void Enemy_UpdateModelMatrix_0_001A7E60(A *a);
void ActorList_Init_1_001A82B0(s32 arg0, s32 arg1);
void* EnemyType_Get_0_001A8360(s32 i);
s32 EnemyType_LoadTable_0_001A83A0(void *p);
void Enemy_UpdateSfxTransform_0_001A83E0(s8 *arg0);
s8* Mdl_GetFrameData_0_001715B0(s32 *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0CopyMatrix(void *, void *);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void memset(void *, s32, s32);
void Arc_LoadFile_2_00159DD0(s32 id, void *p, s32 **a, s32 *b);
void Mtx_Compose_2_00173FD0(void *, s8 *, s8 *, s8 *);
void sceVu0MulMatrix(void *, void *, void *);
void Sfx_SetTransform_1_001677C0(s32, void *);

/* Enemy_UpdateModelMatrix_0_001A7E60 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + *(volatile f32 *)&(x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define WRAPV(x, y) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (y)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Enemy_UpdateModelMatrix_0_001A7E60
void sceVu0CopyMatrix__as_Enemy_UpdateModelMatrix_0_001A7E60(Mtx *, Mtx *);
static inline f32 u2f(u32 x) { return x; }

void Enemy_UpdateModelMatrix_0_001A7E60(A *a) {
    P *p;
    f32 *r;

    if (a == NULL || a->x518 == NULL) {
        return;
    }
    p = (P *)(a->x518 + 0x180);
    p->xC = a->x4;
    p->x10 = (N *)a->x518;
    p->x14 = a->x51C;
    p->x18 = p->x10;
    p->x1C = a->x4B0;
    p->x20 = a->x514;
    p->x24 = p->x10->xB0;
    if (p->x24 != NULL) {
        p->x28 = *p->x24;
    }
    p->x2C = Mdl_GetFrameData_0_001715B0(p->x24);
    r = &p->x10->rot.x;
    *r = WRAPV(p->x10->rot.x, *r);
    r = &p->x10->rot.y;
    *r = WRAPV(p->x10->rot.y, *r);
    r = &p->x10->rot.z;
    *r = WRAPV(p->x10->rot.z, *r);
    sceVu0CopyVector(&p->x10->v10, &p->x10->v0);
    sceVu0CopyVector(&p->x10->v30, &p->x10->rot);
    sceVu0CopyMatrix(&p->x18->m, &gMatrixFromData_001F2170);
    p->x0 = (f32)(u32)a->x4B0->x244 * p->x18->s50 / 4096.0f;
    p->x4 = (f32)(u32)a->x4B0->x246 * p->x18->s54 / 4096.0f;
    p->x8 = (f32)(u32)a->x4B0->x248 * p->x18->s58 / 4096.0f;
    p->x18->m.m[0].x = p->x0;
    p->x18->m.m[1].y = p->x4;
    p->x18->m.m[2].z = p->x8;
    sceVu0RotMatrixY(&p->m, &p->x18->m, WRAP(p->x18->rot.y));
    sceVu0CopyMatrix(&p->x18->m, &p->m);
    sceVu0CopyVector(&p->x18->m.m[3], &p->x18->v0);
    p->x18->m.m[3].w = 1.0f;
    sceVu0CopyVector(&p->v40, &p->x10->v0);
    sceVu0CopyVector(&p->v50, &p->x10->v40);
    sceVu0CopyVector(&p->vA0, &gZeroVec_003139A0);
    p->xF4 = 0;
}
#undef sceVu0CopyMatrix

/* ActorList_Init_1_001A82B0 */
void ActorList_Init_1_001A82B0(s32 arg0, s32 arg1) {
    u16 i; gEnemyListSbss_00202278 = arg0; gEnemyListSbss_00202280 = arg1; memset(&gEnemyListBss_004A4570, 0, 0x30C); for (i = 0; i < 0x81; i++) gEnemyListBss_004A4570.a[i] = i; gEnemyListBss_004A4570.n = 0x81;
}

/* EnemyType_Get_0_001A8360 */
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_EnemyType_Get_0_001A8360
void sceVu0CopyMatrix__as_EnemyType_Get_0_001A8360(void *, s8 *);

/* EnemyType_Get_0_001A8360 */
/* EnemyType_Get_0_001A8360 */
void *EnemyType_Get_0_001A8360(s32 i) { if (i < 0 || i > 0xFF) return NULL; if (!gEnemyModelSbss_00202284) return NULL; return (u8 *)(i * 64) + (s32)gEnemyModelSbss_00202284 + 16; }

/* EnemyType_LoadTable_0_001A83A0 */

s32 EnemyType_LoadTable_0_001A83A0(void *p)
{
    s32 b;
    s32 *a;
    Arc_LoadFile_2_00159DD0(0x3F114AF, p, &a, &b);
    gEnemyModelSbss_00202284__as_EnemyType_LoadTable_0_001A83A0 = *a;
    return 0;
}

/* Enemy_UpdateSfxTransform_0_001A83E0 */
void Enemy_UpdateSfxTransform_0_001A83E0(s8 *arg0) {
    f32 mtx[16] __attribute__((aligned(16)));
    f32 tmp[16] __attribute__((aligned(16)));
    s8 *v;
    s32 i;
    s8 *e;
    s32 off;
    s32 off4;
    s8 *base;
    O *o;
    Hd *h;
    if (arg0 != NULL) {
        base = M2C_FIELD(arg0, s8 **, 0x518);
        o = (O *)(base + 0x180);
        if (M2C_FIELD(base, Fl **, 0x19C)->en) {
            h = *M2C_FIELD(base, Hd ***, 0xB0);
            i = 0;
            off = 0;
            off4 = 0;
            v = (s8 *)((s32)h->data + gSfxAllSbss_00201F2C * (h->n * 0x140 + 0x200));
            do {
                s8 *t = o->ents + off;
                e = t + 0x2B0;
                if (M2C_FIELD(t, u16 *, 0x2E0) != 0) {
                    sceVu0CopyMatrix(mtx, v + (M2C_FIELD(e, u8 *, 0x32) + 1) * 0x140 + 0xC0);
                    Mtx_Compose_2_00173FD0(tmp, e, e + 0x10, e + 0x20);
                    sceVu0MulMatrix(mtx, mtx, tmp);
                    Sfx_SetTransform_1_001677C0(M2C_FIELD((s8 *)o->objs + off4, s32 *, 0x124), mtx);
                }
                i++;
                off += 0x40;
                off4 += 4;
            } while (i < 8);
        }
    }
}
#undef sceVu0CopyMatrix

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gEnemyModelSbss_00202284 */
u8 *gEnemyModelSbss_00202284;
#endif
