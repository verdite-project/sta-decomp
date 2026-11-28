/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Sfx_Create_2_00169F40.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 47/674 (unchanged). Only diff: in tex() retail hoists lhu of h->x14,x16,x12 above the first uv store/conversion
 * (loads x10, x14, x16, x12 up front into v0/a1/a0/a2); ours loads each right before its conversion. Tried u16/u32/s32 locals
 * in a nested block (copy-propagated away), locals at tex top (register blowup, +10 words), f32 temps, uv pointer, const Hd*,
 * inlining tex body into the caller. */
#include "common.h"
typedef struct {
    u8 type : 3;
    u8 rest : 5;
    u8 pad1[7];
    union { u64 d; u16 h; } x8;
    u16 x10, x12, x14, x16;
} Hd;
typedef union {
    f32 f[0x2C];
    struct { u8 pad[0x10]; Hd h; } s;
    struct { u8 pad[0x94]; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 4; } g;
} M;
typedef struct {
    f32 x, y, z, w;
    f32 uv[4];
    union { f32 f[2]; u16 h[3]; } n;
    u32 col;
    u16 prim : 11;
    u16 pr : 5;
    u16 pad2E;
} __attribute__((aligned(16))) L;
typedef struct {
    s32 off;
    u8 pad4[4];
    u16 x8;
    u8 padA[6];
    s32 x10;
    u8 pad14[0xC];
    L l;
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C, x70, x74, x78, x7C;
} Sub;
typedef struct {
    u8 pad0[0x174];
    s32 x174;
    f32 x178, x17C, x180, x184;
    union {
        s32 w;
        struct {
            u16 b0 : 1; u16 b1 : 1; u16 b2 : 1; u16 b3 : 1; u16 b4 : 1; u16 b5 : 1; u16 b6 : 1; u16 cnt : 8; u16 b15 : 1;
            u16 g0 : 1; u16 g1 : 1; u16 h : 10; u16 g12 : 4;
        } f;
    } x188;
    u8 pad18C[4];
    Vec v190[6];
    f32 x1F0, x1F4;
    u8 pad1F8[8];
    f32 x200, x204;
    u8 pad208[8];
    M *m[24];
    Sub sub[24];
    s8 **xE70;
    s8 **xE74;
    s32 xE78;
    s32 xE7C;
    u8 xE80[0x40];
    Vec xEC0;
} E;
s32 Node_FindById_2_0014DCD0(s8 *, s32);
s8 Sfx_BuildNodeTree_0_0016A9D0(s8 *, s32, s32, Sub *);
s32 Tex_Find_1_00177AF0(u64, s8 **);
s32 Tex_FindByHash_1_00177B20(u64);
void sceVu0CopyMatrix(void *, void *);
void memset(void *, s32, s32);
extern s8 D_001F2170[];
extern s32 D_00201CAC, D_00201CB8, D_00201CB4;
extern E D_003407E0[];
static inline void reloc(E *e) {
    if (e != NULL) {
        s32 n; s8 *base; s32 j;
        n = e->x188.f.cnt; base = *e->xE70 + e->xE7C;
        for (j = 0; j < n; j++) {
            e->m[j] = (M *)(base + e->sub[j].off);
        }
    }
}
static inline u32 rgba(u32 r, u32 g, u32 b, u32 a) { return (a << 24) | (b << 16) | (g << 8) | r; }
static inline void tex(E *e, Sub *sub, Hd *h, L *l) {
    s32 t = 0;
    if (h->type == 1) {
        s32 v = 0;
        if (e->xE74 != NULL) v = Tex_Find_1_00177AF0(h->x8.d, e->xE74);
        if (v == 0) v = Tex_FindByHash_1_00177B20(h->x8.d);
        sub->x10 = v;
        l->uv[0] = h->x10;
        l->uv[1] = h->x12;
        l->uv[2] = h->x14;
        l->uv[3] = h->x16;
        t = 1;
    }
    l->prim = ((u64)t << 4) | 0x148;
    sub->l = *l;
}

static inline E *alloc(void) {
    u32 i;
    E *e;
    for (i = 0; i < 0x100; i++) {
        e = &D_003407E0[i];
        if (!e->x188.f.b0) {
            e->x188.w = 0;
            e->x188.f.b0 = 1;
            e->x188.f.b1 = 1;
            e->x188.f.g0 = 1;
            break;
        }
    }
    if (i == 0x100) e = NULL;
    return e;
}

E *Sfx_Create_2_00169F40(s8 **a0, s32 a1, s32 *tbl, s32 a3, s32 f5, s32 f6, u16 f7) {
    E *e;
    s32 a, b, c;
    s8 r;
    s32 k;
    u32 col;
    M *m0;
    M *mk;
    Sub *sub;
    Hd *h;
    L l;
    e = alloc();
    a = Node_FindById_2_0014DCD0(*a0 + a1, D_00201CAC);
    b = Node_FindById_2_0014DCD0(*a0, D_00201CB8);
    c = Node_FindById_2_0014DCD0(*a0, D_00201CB4);
    if (a == 0) return NULL;
    if (e == NULL) return NULL;
    memset(e, 0, 0xED0);
    e->x174 = 0;
    e->x178 = 1.0f;
    e->xE70 = a0;
    e->xE7C = a1;
    e->x188.f.b0 = 1;
    e->x188.f.b1 = 1;
    e->x188.f.b2 = !(a3 != 0);
    e->x188.f.b5 = f5;
    e->x188.f.b6 = f6;
    e->x188.f.g0 = 1;
    e->x188.f.h = f7;
    for (k = 0; k < 24; k++) {
        e->sub[k].x8 = 0xFFFF;
    }
    if (c != 0) e->xE74 = a0;
    if (b != 0) e->xE78 = b - (s32)e->xE70;
    sceVu0CopyMatrix(e, D_001F2170);
    memset(e->xE80, 0, 0x40);
    e->x17C = 1.0f;
    e->x180 = 1.0f;
    e->x184 = 1.0f;
    r = Sfx_BuildNodeTree_0_0016A9D0(*a0 + a1, a, 0, e->sub);
    e->x188.f.cnt = r;
    reloc(e);
    m0 = e->m[0];
    for (k = 0; k < 6; k++) {
        e->v190[k].x = m0->f[3 + k * 4];
        e->v190[k].y = m0->f[4 + k * 4];
        e->v190[k].z = m0->f[5 + k * 4];
        *(s32 *)&e->v190[k].w = 0;
    }
    e->x1F0 = m0->f[0x6C / 4];
    e->x1F4 = m0->f[0x74 / 4];
    e->x200 = m0->f[0x8C / 4];
    e->x204 = m0->f[0x94 / 4];
    e->x200 = m0->f[0x8C / 4];
    m0->g.b3 = 0;
    e->x188.f.b5 = e->x188.f.b5 | m0->g.b2;
    m0 = e->m[0];
    for (k = 1; k < r; k++) {
        mk = e->m[k];
        sub = &e->sub[k];
        h = &mk->s.h;
        sub->x50 = mk->f[0x34 / 4];
        sub->x54 = mk->f[0x38 / 4];
        sub->x58 = mk->f[0x3C / 4];
        *(s32 *)&sub->x5C = 0;
        sub->x60 = mk->f[0x4C / 4];
        sub->x64 = mk->f[0x50 / 4];
        sub->x68 = mk->f[0x54 / 4];
        *(s32 *)&sub->x6C = 0;
        sub->x70 = mk->f[0x2C / 4];
        sub->x74 = mk->f[0x44 / 4];
        sub->x6C = mk->f[0x5C / 4];
        sub->x78 = mk->f[0x64 / 4];
        sub->x7C = mk->f[0x6C / 4];
        col = rgba(255.0f * mk->f[0x9C / 4] / 255.0f, 255.0f * mk->f[0xA0 / 4] / 255.0f, 255.0f * mk->f[0xA4 / 4] / 255.0f, 255.0f * (mk->f[0xAC / 4] * m0->f[0x8C / 4]) / 255.0f);
        l.x = mk->f[0x34 / 4];
        l.y = mk->f[0x38 / 4];
        l.z = mk->f[0x3C / 4];
        l.col = col;
        switch (h->type) {
        case 0:
        case 1:
            l.n.f[0] = mk->f[0x74 / 4];
            l.n.f[1] = mk->f[0x78 / 4];
            break;
        case 2:
            l.n.h[0] = (u32)(100.0f * mk->f[0x74 / 4]);
            l.n.h[1] = (u32)(100.0f * mk->f[0x78 / 4]);
            l.n.h[2] = (u32)(100.0f * mk->f[0x7C / 4]);
            break;
        }
        switch (h->type) {
        case 0:
            break;
        case 1:
            tex(e, sub, h, &l);
            break;
        case 2:
            sub->x10 = tbl[h->x8.h];
            break;
        }
    }
    return e;
}
#else
INCLUDE_ASM(Sfx_Create_2_00169F40);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): D_00201CAC */
s32 D_00201CAC = 0x61545452;
#endif
