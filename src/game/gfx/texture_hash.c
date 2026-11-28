#include "common.h"
#include "m2c.h"
typedef struct { void *p; s32 x; } E;
typedef struct { s32 x[4]; } H;
typedef struct { s32 h[3]; s32 size; s8 data[1]; } B;
typedef struct { u8 b0:3; u8 r:5; } Bits;
typedef struct {
    u8 p0[0x10]; s32 **x10; u8 p14[8]; s16 prev; s16 next; s16 x20; u8 p22[2]; s32 x24; Bits x28; u8 p29[7];
} Node;
typedef struct { u64 key; u8 p8[0x30]; Node *x38; s32 x3C; u8 p40[0x10]; } Ent_Tex_Lookup_1_00177BB0;
typedef struct { s32 x0; s32 x4; u32 n; u8 pC[4]; Ent_Tex_Lookup_1_00177BB0 e[1]; } Tbl;
typedef struct { s32 **a; s32 b; } Ent_Tex_RegisterTtix_0_00178080;
extern E D_0047F080[8];
extern s8 D_001FB908[];
extern s8 D_001FB909[];
extern s8 D_001FB90A[];
#ifndef NONMATCHING
extern s8 D_001FB90B[];
#else
/* data twins (src/game/data/sfx_all_rodata.c): D_001FB90B */
static s8 D_001FB90B[0x5] __attribute__((aligned(1))) = { 0x58, 0, 0, 0, 0 };
#endif
extern s8 D_001FB910[];
extern s8 D_001FB911[];
extern s8 D_001FB912[];
#pragma explicit_zero_data on
const s8 D_001FB913[0xd] __attribute__((aligned(1))) = { 0x49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
extern s32 D_00201CB4;
extern Node D_004800C0[];
extern s16 D_004800DC[];
extern s16 D_004800DE[];
extern s16 D_004830C8[];
extern s16 D_004830CA[];
extern s16 D_004830CC[];
extern s16 D_004830CE[];
extern Ent_Tex_RegisterTtix_0_00178080 D_0047F080__as_Tex_RegisterTtix_0_00178080[];
void* Tex_Find_1_00177AF0(s32 a, s32 b);
void* Tex_FindByHash_1_00177B20(u64 a);
Node* Tex_Lookup_1_00177BB0(u64 key, s32 **r, s32 off);
u64 Tex_HashName_2_00177F80(u8 *s);
void Tex_ReleaseList_0_00178030(void *p);
void Tex_RegisterTtix_0_00178080(s32 **arg0);
H* Node_FindById_2_0014DCD0(s32 *, s32);
Node* TexAnim_GetFrame_0_00175850(s32);
void Tex_SetTex0_1_00176550(Node *, Tbl *, Ent_Tex_Lookup_1_00177BB0 *);
s32 toupper(s32);

/* Tex_Find_1_00177AF0 */
#define Tex_Lookup_1_00177BB0 Tex_Lookup_1_00177BB0__as_Tex_Find_1_00177AF0
void *Tex_Lookup_1_00177BB0__as_Tex_Find_1_00177AF0(s32 a, s32 b, s32 c);

void *Tex_Find_1_00177AF0(s32 a, s32 b)
{
    void *p = Tex_Lookup_1_00177BB0(a, b, -1);
    if (p)
        return p;
    return NULL;
}
#undef Tex_Lookup_1_00177BB0

/* Tex_FindByHash_1_00177B20 */
#define Tex_Lookup_1_00177BB0 Tex_Lookup_1_00177BB0__as_Tex_FindByHash_1_00177B20
void *Tex_Lookup_1_00177BB0__as_Tex_FindByHash_1_00177B20(u64 a, void *b, s32 c);
void *Tex_FindByHash_1_00177B20(u64 a) {
    s32 i;
    void *r = NULL;
    if (a == (u64)-1) return r;
    for (i = 0; i < 8; i++) {
        if (D_0047F080[i].p != NULL && (r = Tex_Lookup_1_00177BB0(a, D_0047F080[i].p, D_0047F080[i].x)) != NULL) break;
    }
    return r;
}
#undef Tex_Lookup_1_00177BB0

/* Tex_Lookup_1_00177BB0 */
/* Tex_Lookup_1_00177BB0 */
static inline s32 getsz_Tex_Lookup_1_00177BB0(s32 *s) {
    H *v;
    B *b;
    if (*s == (D_001FB908[0] | (D_001FB909[0] << 8) | (D_001FB90A[0] << 16) | (D_001FB90B[0] << 24))) {
        return 0;
    }
    v = Node_FindById_2_0014DCD0(s, D_00201CB4);
    if (v != NULL) {
        b = (B *)(v + 1); return ((s32)b->data + ((b->size + 0xF) & ~0xF)) - (s32)s;
    }
    return -1;
}

static inline void link(s16 idx) {
    s16 h;
    D_004830CE[0]++;
    h = D_004830CC[0];
    if (h == -1) {
        D_004830CC[0] = idx;
        D_004800DC[idx * 24] = idx;
        D_004800DE[idx * 24] = idx;
    } else {
        D_004800DC[idx * 24] = h;
        D_004800DE[idx * 24] = D_004800DE[h * 24];
        D_004800DE[D_004800DC[idx * 24] * 24] = idx;
        D_004800DC[D_004800DE[idx * 24] * 24] = idx;
        D_004830CC[0] = idx;
    }
}
static inline Node *unlink(s16 idx) {
    s16 *pv;
    Node *n;
    n = &D_004800C0[idx];
    D_004830CA[0]--;
    pv = &D_004800DC[idx * 24];
    if (idx == *pv) {
        D_004830C8[0] = -1;
    } else {
        D_004800DE[*pv * 24] = D_004800DE[idx * 24];
        D_004800DC[D_004800DE[idx * 24] * 24] = *pv;
        if (*(volatile s16 *)D_004830C8 == idx) D_004830C8[0] = *pv;
    }
    return n;
}
Node *Tex_Lookup_1_00177BB0(u64 key, s32 **r, s32 off) {
    Ent_Tex_Lookup_1_00177BB0 *e;
    Tbl *t;
    u32 i;
    Node *nd;
    s32 idx;
    s32 n;
    union { u64 d; struct { s32 w; u8 c[4]; } s; } k;

    if (off == -1) off = getsz_Tex_Lookup_1_00177BB0(*r);
    if (off == -1) return 0;
    t = (Tbl *)((s8 *)*r + off);
    e = t->e;
    for (i = 0; i < t->n; i++) {
        if (key == e[i].key) break;
    }
    k.d = key;
    if (k.s.w == (D_001FB910[0] | (D_001FB911[0] << 8) | (D_001FB912[0] << 16) | (D_001FB913[0] << 24)) && k.s.c[0] == 'X') {
        n = (k.s.c[1] - '0') * 100 + (k.s.c[2] - '0') * 10;
        n += k.s.c[3] - '0';
        nd = TexAnim_GetFrame_0_00175850(n);
    } else {
    e = &e[i];
    if (i != t->n) {
    if (e->x3C) {
        e->x3C++;
        nd = e->x38;
    } else {
    idx = D_004830C8[0];
    nd = unlink(idx);
    link(idx);
    nd->x10 = r;
    nd->x24 = off;
    nd->x20 = i;
    nd->x28.b0 = 1;
    Tex_SetTex0_1_00176550(nd, t, e);
    e->x3C++;
    }
    } else return 0;
    }
    return nd;
}

/* Tex_HashName_2_00177F80 */
u64 Tex_HashName_2_00177F80(u8 *s) {
    u64 h = 0;
    u8 *p = s;
    while (*p) p++;
    p--;
    while (*p) {
        h = ((h << 8) | (h >> 56)) ^ toupper(*p);
        if (p == s) break;
        p--;
    }
    return h;
}

/* Tex_ReleaseList_0_00178030 */
void Tex_ReleaseList_0_00178030(void *p)
{
    s32 i;
    if (!p)
        return;
    for (i = 0; i < 8; i++) {
        if (D_0047F080[i].p == p) {
            D_0047F080[i].p = NULL;
            return;
        }
    }
}

/* Tex_RegisterTtix_0_00178080 */
static inline s32 getsz_Tex_RegisterTtix_0_00178080(s32 *s) {
    H *v;
    s8 *p;
    B *b;
    if (*s == (D_001FB908[0] | (D_001FB909[0] << 8) | (D_001FB90A[0] << 16) | (D_001FB90B[0] << 24))) {
        return 0;
    }
    v = Node_FindById_2_0014DCD0(s, D_00201CB4);
    if (v != NULL) {
b = (B *)(v + 1); return ((s32)b->data + ((b->size + 0xF) & ~0xF)) - (s32)s;
    }
    return -1;
}

void Tex_RegisterTtix_0_00178080(s32 **arg0) {
    s32 n;
    s32 i;
    n = getsz_Tex_RegisterTtix_0_00178080(*arg0);
    if (n != -1) {
        for (i = 0; i < 8; i++) {
            if (D_0047F080__as_Tex_RegisterTtix_0_00178080[i].a == NULL) {
                D_0047F080__as_Tex_RegisterTtix_0_00178080[i].a = arg0;
                D_0047F080__as_Tex_RegisterTtix_0_00178080[i].b = n;
                return;
            }
        }
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): D_00201CB4 */
s32 D_00201CB4 = 0x43494454;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/texture_bss.c): D_0047F080 */
E D_0047F080[8];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_004800C0__grp: D_004800C0@0x0, D_004800C8@0x8, D_004800D0@0x10, D_004800DC@0x1c, D_00483090@0x2fd0 */
u8 D_004800C0__grp[0x3000] __attribute__((aligned(16)));
#endif
