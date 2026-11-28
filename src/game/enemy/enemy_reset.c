#include "common.h"
#include "game/data.h"
typedef struct { u16 a, b, c, n; u8 pad[0x38]; s8 data[1]; } Hd;
typedef struct { u8 pad[0x2A]; u8 x2A; } Ent;
typedef struct { u8 pad[0xB0]; Hd **xB0; } Sub_Enemy_ResetPartAnim_1_001A8670;
typedef struct { u8 pad[0x4B4]; Ent *x4B4[25]; Sub_Enemy_ResetPartAnim_1_001A8670 *x518; } A_Enemy_ResetPartAnim_1_001A8670;
typedef struct { u8 pad[0x1F8]; Flags8 f; u8 rest[0x140 - 0x1F9 + 0x140]; } E_Enemy_ResetPartAnim_1_001A8670;
typedef struct { u8 pad[0x2A]; u8 x2A; } El;
typedef struct { u8 pad[6]; u16 h6; } Hdr;
typedef struct {
    u8 pad0[0x80];
    u8 x80;
    u8 pad81[0x4B4 - 0x81];
    El *x4B4[25];
    s8 *x518;
    u8 *x51C;
    u8 x520[1];
} Act;
typedef struct {
    u8 pad0[0xA0];
    Vec xA0;
    Vec xB0;
    f32 xC0, xC4, xC8, xCC;
    Vec xD0;
    Vec xE0;
    Vec xF0;
    Vec x100;
    Vec x110;
    Vec x120;
    Vec x130;
} E_Enemy_ScatterPart_0_001A8700;
typedef struct { u8 b[0x140]; } N;
typedef Bits8 F;
typedef struct { u8 pad[6]; u16 m6; u8 pad8[0x38]; u8 m40[1]; } Mdl;
typedef struct { u8 pad[0xB0]; Mdl **pB0; } Sub_Enemy_HidePart_1_001A8B10;
typedef struct { u8 pad[0x2A]; u8 m2A; } Src;
typedef struct { u8 pad[0x4B4]; Src *m4B4[0x19]; Sub_Enemy_HidePart_1_001A8B10 *m518; } A_Enemy_HidePart_1_001A8B10;
extern Vec D_001F2130;
extern Vec D_001F2140;
extern Vec D_001F2150;
extern Vec D_001F2160;
void Enemy_ResetPartAnim_1_001A8670(A_Enemy_ResetPartAnim_1_001A8670 *a, u8 i);
void Enemy_ScatterPart_0_001A8700(Act *a, u8 idx);
void Enemy_HidePart_1_001A8B10(A_Enemy_HidePart_1_001A8B10 *a, u8 id);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0CopyMatrix(Mtx *, void *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void Quat_FromAxisAngle_2_0015E500(Vec *, Vec *, f32);
s32 rand(void);
f32 sqrtf(f32);

/* Enemy_ResetPartAnim_1_001A8670 */
void Enemy_ResetPartAnim_1_001A8670(A_Enemy_ResetPartAnim_1_001A8670 *a, u8 i) {
    Hd *h;
    s32 off;
    s32 z;
    s8 *v;
    h = *a->x518->xB0;
    v = h->data;
    off = (a->x4B4[i]->x2A + 1) * 0x140;
    z = 0;
    ((E_Enemy_ResetPartAnim_1_001A8670 *)(v + off))->f.f.b4 = z;
    ((E_Enemy_ResetPartAnim_1_001A8670 *)(v + (h->n * 0x140 + 0x200) + off))->f.f.b4 = z;
}

/* Enemy_ScatterPart_0_001A8700 */
void Enemy_ScatterPart_0_001A8700(Act *a, u8 idx) {
    u8 *nb;
    E_Enemy_ScatterPart_0_001A8700 *e;
    u8 *na;
    s32 off;
    u8 pk;
    s32 sz;
    u8 *src;
    s32 k;
    Vec *m1;
    u8 *b;
    Vec *m2;
    Hdr *h;
    F *f;
    u8 *p;
    Mtx m;
    Vec c;
    Vec r;
    Vec t1;
    Vec t2;
    Vec t3;

    e = (E_Enemy_ScatterPart_0_001A8700 *)(a->x51C + idx * 0x170);
    k = a->x4B4[idx]->x2A;
    h = **(Hdr ***)(a->x518 + 0xB0);
    sz = h->h6 * 0x140 + 0x200;
    na = (u8 *)((s32)h + 0x40) + D_00201F2C * sz;
    nb = (u8 *)((s32)h + 0x40) + !D_00201F2C * sz;
    off = (k + 1) * 0x140;
    f = (F *)(na + off + 0x1F8);
    if (!f->b6) {
    a->x520[a->x80] = idx;
    a->x80++;
    b = nb + off;
    p = &((N *)(na + 0x331))[k].b[0];
    pk = *p;
    f->b6 = 1;
    src = nb + pk * 0x140 + 0xC0;
    ((F *)(b + 0x1F8))->b6 = 1;
    sceVu0CopyMatrix(&m, src);
    sceVu0CopyVector(&e->xA0, &m.m[3]);
    sceVu0CopyVector(&e->xB0, &e->xA0);
    e->xC0 = sqrtf(sceVu0InnerProduct(&m.m[0], &m.m[0]));
    m1 = &m.m[1];
    e->xC4 = sqrtf(sceVu0InnerProduct(m1, m1));
    m2 = &m.m[2];
    e->xC8 = sqrtf(sceVu0InnerProduct(m2, m2));
    sceVu0CopyVector(&e->xD0, &gZeroVec_003139A0);
    sceVu0Normalize(&e->xE0, &m.m[0]);
    sceVu0Normalize(&e->xF0, m1);
    sceVu0Normalize(&e->x100, m2);
    sceVu0CopyVector(&e->x110, &D_001F2160);
    sceVu0CopyVector(&e->x120, &gZeroVec_003139A0);
    sceVu0CopyVector(&e->x130, &D_001F2160);
    sceVu0CopyMatrix((Mtx *)((s32)na + off + 0x100), &m);
    sceVu0CopyMatrix((Mtx *)(b + 0x100), &m);
    sceVu0CopyVector(&c, (Vec *)(na + *p * 0x140 + 0xE0));
    sceVu0Normalize(&c, &c);
    sceVu0ScaleVector(&c, &c, 250.0f);
    c.y += -350.0f;
    sceVu0CopyVector(&e->xD0, &c);
    sceVu0ScaleVector(&r, &D_001F2130, 0.0625f * (f32)(rand() % 256 - 128));
    sceVu0ScaleVector(&t1, &D_001F2140, 0.0078125f * (f32)(rand() % 256 - 128));
    sceVu0AddVector(&r, &t1, &r);
    sceVu0ScaleVector(&t2, &D_001F2150, 0.0078125f * (f32)(rand() % 256 - 128));
    sceVu0AddVector(&r, &t2, &r);
    sceVu0Normalize(&r, &r);
    Quat_FromAxisAngle_2_0015E500(&e->x130, &r, 0.09424778f);
    sceVu0ScaleVector(&e->x120, &D_001F2150, 50.0f);
    sceVu0ScaleVector(&t3, &D_001F2140, -30.0f);
    sceVu0AddVector(&e->x120, &t3, &e->x120);
    }
}

/* Enemy_HidePart_1_001A8B10 */
void Enemy_HidePart_1_001A8B10(A_Enemy_HidePart_1_001A8B10 *a, u8 id) {
    Mdl *m;
    s32 o;
    s8 *t;
    m = *a->m518->pB0;
    t = (s8 *)m->m40;
    o = (a->m4B4[id]->m2A + 1) * 0x140;
    ((Flags8 *)(t + o))[0x1F8].f.b4 = 1;
    ((Flags8 *)(t + (m->m6 * 0x140 + 0x200) + o))[0x1F8].f.b4 = 1;
}
