#include "common.h"
#include "m2c.h"
#include "game/effect.h"
#include "game/data.h"
typedef struct O { Mtx m0; u8 p40[0x50]; Mtx *x90; u8 p94[0xC]; u16 xA0; u8 pA2[2]; f32 xA4; u8 pA8[0x18]; Mtx xC0; u8 p100[0x14]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 p115[0xB]; } O;
typedef struct B {
    u8 pad[0x10];
    Vec x10;
    u8 pad20[0xA0 - 0x20];
    u16 xA0;
    u8 padA2[0x114 - 0xA2];
    Flags8 f114;
    u8 pad115[0x120 - 0x115];
} B;
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct {
    s32 x0;
    s32 id;
    f32 c[4];
    u8 pad18[0x50 - 0x18];
    u64 d50;
    u8 pad58[0x4C0 - 0x58];
    u64 d4C0;
    u8 pad4C8[0x4E0 - 0x4C8];
} Entry;
typedef struct { u8 pad[0x10]; u8 s[0x4D0]; } Raw;
typedef union { struct { u32 n[4]; Entry e[2][64]; } a; Raw r[2][64]; } Tbl;
typedef struct { char pad[0x10]; s32 v; } T;
extern s32 D_00201FC0;
extern Tbl D_003174F0;
extern Entry *D_00201F94;
#ifndef NONMATCHING
extern s32 D_00201F98;
#else
/* data twins (src/game/data/sbss.c): D_00201F98 */
static s32 D_00201F98;
#endif
#ifndef NONMATCHING
extern s32 D_00201F9C;
#else
/* data twins (src/game/data/sbss.c): D_00201F9C */
static s32 D_00201F9C;
#endif
extern void *D_00201FA0;
s32 Fx_GetParentIdx_0_00163C40(void *arg0);
void Fx_GetWorldMatrix_1_00163C80(O *o, Mtx *out);
void Fx_GetWorldPos_1_00163D90(B *o, Vec *out);
s32 Fx_DrawSprites_0_00163FF0(u32 a0, u8 *a1, s32 a2);
void Fx_FreeSpriteBuffer_0_00164330(s32 arg0, s32 arg1);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);
void Mtx_AxisAngle_2_0015EBB0(f32, Mtx *, Vec *);
void sceVu0MulMatrix(Mtx *, Mtx *, Mtx *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
s32 Fx_HashKey_1_00164A60(u32, u8 *, s32);
Q* GsPkt_Alloc_3_00154A80(s32);
void Lightning_BuildStrip_0_00164440(Entry *, u8 *, u8 *, u8 *, s32);
T* Tex_Resident_0_001777C0(s32 a, s32 b, s32 c);

/* Fx_GetParentIdx_0_00163C40 */
s32 Fx_GetParentIdx_0_00163C40(void *arg0) {
    u16 temp_4;

    temp_4 = M2C_FIELD(arg0, u16 *, 0xA0);
    if (temp_4 == 0xFFFF) {
        return 0;
    }
    return D_00201FC0 + (temp_4 * 0x120);
}

/* Fx_GetWorldMatrix_1_00163C80 */
#define D_00201FC0 D_00201FC0__as_Fx_GetWorldMatrix_1_00163C80
extern O *D_00201FC0__as_Fx_GetWorldMatrix_1_00163C80;
static inline O *get(u16 id) {
    if (id == 0xFFFF) return 0;
    return &D_00201FC0[id];
}

void Fx_GetWorldMatrix_1_00163C80(O *o, Mtx *out) {
    Vec v;
    Mtx r;
    Mtx p;
    O *q;
    sceVu0CopyMatrix(out, &o->xC0);
    sceVu0CopyVector(&out->m[3], &o->m0.m[0]);
    out->m[3].w = 1.0f;
    if (o->xA4 != 0.0f) {
        sceVu0CopyVector(&v, &o->m0.m[3]);
        v.w = 0.0f;
        Mtx_AxisAngle_2_0015EBB0(o->xA4, &r, &v);
        sceVu0MulMatrix(out, out, &r);
    }
    if (o->b5) {
        q = get(o->xA0);
        if (q != 0) {
            Fx_GetWorldMatrix_1_00163C80(q, &p);
        } else {
            sceVu0CopyMatrix(&p, o->x90);
        }
        sceVu0MulMatrix(out, &p, out);
    }
}
#undef D_00201FC0

/* Fx_GetWorldPos_1_00163D90 */
#define D_00201FC0 D_00201FC0__as_Fx_GetWorldPos_1_00163D90
extern B *D_00201FC0__as_Fx_GetWorldPos_1_00163D90;
#define Fx_GetParentIdx_0_00163C40 Fx_GetParentIdx_0_00163C40__as_Fx_GetWorldPos_1_00163D90
B *Fx_GetParentIdx_0_00163C40__as_Fx_GetWorldPos_1_00163D90(B *);
#define Fx_GetWorldMatrix_1_00163C80 Fx_GetWorldMatrix_1_00163C80__as_Fx_GetWorldPos_1_00163D90
void Fx_GetWorldMatrix_1_00163C80__as_Fx_GetWorldPos_1_00163D90(B *, Mtx *);
static inline B *parent(B *o) {
    u16 i = o->xA0;
    if (i == 0xFFFF) return 0;
    return &D_00201FC0[i];
}
static inline void G(B *o, Vec *out) {
    B *p;
    Vec v;
    Mtx m4;
    p = Fx_GetParentIdx_0_00163C40(o);
    if (o->f114.f.b5 && p) {
        Fx_GetWorldMatrix_1_00163C80(p, &m4);
        Fx_GetWorldPos_1_00163D90(p, &v);
        sceVu0ApplyMatrix(out, &m4, &o->x10);
        sceVu0AddVector(out, out, &v);
    } else {
        sceVu0CopyVector(out, &o->x10);
    }
}

void Fx_GetWorldPos_1_00163D90(B *o, Vec *out) {
    B *p3;
    B *p1;
    B *p2;
    Vec w;
    Mtx m1;
    Vec u;
    Mtx m2;
    Vec t;
    Mtx m3;

    p1 = parent(o);
    if (o->f114.f.b5 && p1) {
        Fx_GetWorldMatrix_1_00163C80(p1, &m1);
        p2 = parent(p1);
        if (p1->f114.f.b5 && p2) {
            Fx_GetWorldMatrix_1_00163C80(p2, &m2);
            p3 = parent(p2);
            if (p2->f114.f.b5 && p3) {
                Fx_GetWorldMatrix_1_00163C80(p3, &m3);
                G(p3, &t);
                sceVu0ApplyMatrix(&u, &m3, &p2->x10);
                sceVu0AddVector(&u, &u, &t);
            } else {
                sceVu0CopyVector(&u, &p2->x10);
            }
            sceVu0ApplyMatrix(&w, &m2, &p1->x10);
            sceVu0AddVector(&w, &w, &u);
        } else {
            sceVu0CopyVector(&w, &p1->x10);
        }
        sceVu0ApplyMatrix(out, &m1, &o->x10);
        sceVu0AddVector(out, out, &w);
    } else {
        sceVu0CopyVector(out, &o->x10);
    }
}
#undef Fx_GetParentIdx_0_00163C40
#undef Fx_GetWorldMatrix_1_00163C80
#undef D_00201FC0

/* Fx_DrawSprites_0_00163FF0 */
static inline Entry *find(s32 id) {
    u32 i;
    for (i = 0; i < D_003174F0.a.n[D_00201F2C]; i++) {
        if (D_003174F0.a.e[D_00201F2C][i].id == id) return &D_003174F0.a.e[D_00201F2C][i];
    }
    return 0;
}

s32 Fx_DrawSprites_0_00163FF0(u32 a0, u8 *a1, s32 a2) {
    s32 id;
    Entry *e;
    Q *p;
    id = Fx_HashKey_1_00164A60(a0, a1, a2);
    e = find(id);
    if (e) {
        if (D_00201F94 != e) {
            Q q;
            p = GsPkt_Alloc_3_00154A80(1);
            q.q = 0;
            q.w[0] = 0x50000000;
            q.w[1] = (u32)((u8 *)e + 0x20);
            *p = q;
            D_00201F9C++;
        }
    } else {
        Q q;
        union { u32 w; u8 b[4]; } col;
        Raw *r;
        col.w = a0;
        r = &D_003174F0.r[D_00201F2C][D_003174F0.a.n[D_00201F2C]];
        e = (Entry *)r->s;
        ((Entry *)r->s)->d50 = ((u64)D_00201F98 << 32) | ((u64)1 << 48);
        ((Entry *)r->s)->d4C0 = (s64)D_00201F98 | (0x10004000 | ((u64)5 << 32));

        e->c[0] = col.b[0] / 9.0f;
        e->c[1] = col.b[1] / 9.0f;
        e->c[2] = col.b[2] / 9.0f;
        e->c[3] = col.b[3] / 9.0f;
        Lightning_BuildStrip_0_00164440(e, (u8 *)e + 0xA0, a1 + 0x10, a1 + 0x50, a2);
        D_003174F0.a.n[D_00201F2C]++;
        e->id = id;
        p = GsPkt_Alloc_3_00154A80(1);
        q.q = 0;
        q.w[0] = 0x50000000;
        q.w[1] = (u32)((u8 *)e + 0x20);
        *p = q;
        D_00201F9C++;
    }
    D_00201F94 = e;
    return 1;
}

/* Fx_ResetSpriteCount_0_00164320 */
#define D_00201F94 D_00201F94__as_Fx_ResetSpriteCount_0_00164320
extern s32 D_00201F94__as_Fx_ResetSpriteCount_0_00164320;

void Fx_ResetSpriteCount_0_00164320(void) {
    D_00201F94 = 0;
}
#undef D_00201F94

/* Fx_FreeSpriteBuffer_0_00164330 */
void Fx_FreeSpriteBuffer_0_00164330(s32 arg0, s32 arg1) {
    Tex_Release_1_00177570(D_00201FA0, (s16 *) arg1);
    D_00201FA0 = NULL;
}

/* Fx_BeginFrame_0_00164350 */
#define D_003174F0 D_003174F0__as_Fx_BeginFrame_0_00164350
extern s32 D_003174F0__as_Fx_BeginFrame_0_00164350[];
#define D_00201F94 D_00201F94__as_Fx_BeginFrame_0_00164350
extern s32 D_00201F94__as_Fx_BeginFrame_0_00164350;
#define D_00201FA0 D_00201FA0__as_Fx_BeginFrame_0_00164350
extern T *D_00201FA0__as_Fx_BeginFrame_0_00164350;

void Fx_BeginFrame_0_00164350(void)
{
    D_003174F0[D_00201F2C] = 0;
    D_00201F94 = 0;
    D_00201F9C = 0;
    D_00201FA0 = Tex_Resident_0_001777C0(4, 0, 0);
    D_00201F98 = D_00201FA0->v;
}
#undef D_003174F0
#undef D_00201F94
#undef D_00201FA0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F94, D_00201FA0 */
Entry *D_00201F94;
void *D_00201FA0;
#endif
