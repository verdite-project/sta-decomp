#include "m2c.h"
#include "common.h"
#include "game/core.h"
#include "game/data.h"
#include "game/effect.h"
#include "game/gfx.h"
#include "game/math.h"
typedef struct Node { s32 id; s32 next; u32 lo:8; u32 child:24; u16 pC; u16 cnt; s32 p10[3]; s32 size; } Node;
typedef struct { s32 off; s32 p4; s32 p8; s8 c; s8 d; s8 pad[0x72]; } Ent;
typedef struct { s32 a, b, c, size; } Hdr;
typedef struct {
    u8 pad[0x188];
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 rest[0xED0 - 0x189];
} E;
typedef struct { u16 prev; u16 next; u16 x4; } L;
typedef struct {
    s32 x0;
    s32 x4;
    u32 lo:8;
    u32 off:24;
    u16 xC;
    u16 xE;
    u8 pad10[8];
    s32 x18;
} Chk;
typedef struct { u16 prev; u16 next; u16 sib; } N;
typedef struct { u8 pad[0x114]; u8 b0:1; u8 b1:1; u8 b2:1; u8 pad115[0xB]; } O;
typedef struct { char pad[0x94]; unsigned char : 3; unsigned char f : 1; } T;
typedef struct { char pad[0x210]; T *t; } Obj;
#ifndef NONMATCHING
extern s32 D_00201CB0;
#else
/* data twins (src/game/data/sdata.c): D_00201CB0 */
static s32 D_00201CB0 = 0x61495450;
#endif
extern s16 D_00201CA0;
extern void *D_00201FC0;
extern L *D_00201FD4;
extern s16 D_00201FD8;
extern s8 D_003406D0[];
extern E D_003407E0[];
extern s32 D_00222B64[];
extern s8 D_0042D850[];
extern s8 D_0042D7E0[];
extern s8 *D_00201FD0;
extern s32 D_00201FE8;
extern u8 D_003406E0[];
s8 Sfx_BuildNodeTree_0_0016A9D0(s8 *base, Node *n, s8 idx, Ent *tbl);
s32 Sfx_InitSystem_1_0016AD10(s32 a0, u32 a1, s32 a2);
void Sfx_LoadSystemStam_1_0016AE30(void);
void Sfx_SetOwnerFlag_0_0016B200(Obj *o, int v);
void sceVu0CopyVector(void *, void *);
void memset(void *, s32, s32);
void Sfx_Free_1_001670E0(E *);
void Pool_Init_2_00128A60(void *, s32, s32, s32);
s32 Mdl_InitPool_0_00174620(void *, void *);
void CosTable_Init_3_00146C00(void);
void Arc_LoadFile_2_00159DD0(s32, s8 *, void *, s32 *);
void Sfx_LoadStam_1_00169D70(Chk **, void *, s32);
void Tex_RegisterTtix_0_00178080(Chk **);
u32 Pool_GetBlockUsable_1_00128830(void *p);

/* Sfx_BuildNodeTree_0_0016A9D0 */
static inline s32 hend(Hdr *h) { return (s32)h + 0x10 + ((h->size + 0xF) & ~0xF); }
s8 Sfx_BuildNodeTree_0_0016A9D0(s8 *base, Node *n, s8 idx, Ent *tbl) {
    Node *c = (Node *)((s8 *)n + n->child);
    s32 i;
    s8 cur;

    if (n->id != D_00201CAC && n->id != D_00201CB0) {
        return idx;
    }
    if (n->cnt != 0) {
        tbl[idx].c = idx + 1;
    }
    tbl[idx].off = hend((Hdr *)((s8 *)n + 0x10)) - (s32)base;
    idx++;
    for (i = 0; i < n->cnt; i++) {
        cur = idx;
        idx = Sfx_BuildNodeTree_0_0016A9D0(base, c, idx, tbl);
        if (i != n->cnt - 1) {
            c = (Node *)((s8 *)c + c->next);
            if (c->id != D_00201CB0) {
                return idx;
            }
            tbl[cur].d = idx;
        }
    }
    return idx;
}

/* Sfx_ClearAll_1_0016AB50 */
void Sfx_ClearAll_1_0016AB50(void) {
    s32 i;
    E *e;
    u32 j;

    for (i = 0, e = D_003407E0; i < 0x100; i++, e++) {
        if (e >= D_003407E0 && !(&D_003407E0[0xFF] < e)) {
            Sfx_Free_1_001670E0(e);
            e->b0 = 1;
            e->b4 = 1;
            e->b3 = 1;
        }
    }
    Sfx_UpdateAll_1_00169400(1.0f);
    Sfx_UpdateAll_1_00169400(1.0f);
    GlowFx_StopAll_0_001E0E80();
    sceVu0CopyVector(D_003406D0, &gZeroVec_003139A0);
    memset(D_00201FC0, 0, D_00201FAC * 0x120);
    D_00201FD8 = D_00201FAC;
    for (j = 0; j < D_00201FAC; j++) {
        D_00201FD4[j].prev = j - 1;
        D_00201FD4[j].next = j + 1;
        D_00201FD4[j].x4 = 0xFFFF;
    }
    D_00201FD4[0].prev = 0xFFFF;
    D_00201FD4[D_00201FAC - 1].next = 0xFFFF;
    D_00201CA0 = 0;
    memset(D_003407E0, 0, sizeof(E) * 0x100);
}

/* Sfx_InitSystem_1_0016AD10 */
#define D_00201FC0 D_00201FC0__as_Sfx_InitSystem_1_0016AD10
extern s8 *D_00201FC0__as_Sfx_InitSystem_1_0016AD10;
#define D_00201FD4 D_00201FD4__as_Sfx_InitSystem_1_0016AD10
extern s8 *D_00201FD4__as_Sfx_InitSystem_1_0016AD10;

s32 Sfx_InitSystem_1_0016AD10(s32 a0, u32 a1, s32 a2) {
    s32 t;
    Pool_Init_2_00128A60(D_0042D850, D_00222B64[0], D_00222B84[0], 0x200);
    if (!Mdl_InitPool_0_00174620(D_0042D7E0, D_0042D850)) {
        return 0;
    }
    D_00201FC0 = (s8 *)a0;
    D_00201FAC = a1 / 390;
    D_00201FD0 = D_00201FC0 + D_00201FAC * 0x120;
    D_00201FD4 = D_00201FD0 + D_00201FAC * 0x60;
    Noise_InitWrap_2_0015ED70();
    CosTable_Init_3_00146C00();
    Arc_LoadFile_2_00159DD0(a2, D_0042D850, &D_00201FE8, &t);
    Sfx_LoadSystemStam_1_0016AE30();
    GlowFx_Init_0_001E1200();
    Sfx_ClearAll_1_0016AB50();
    return 1;
}
#undef D_00201FC0
#undef D_00201FD4

/* Sfx_LoadSystemStam_1_0016AE30 */
#define D_00201FE8 D_00201FE8__as_Sfx_LoadSystemStam_1_0016AE30
extern Chk **D_00201FE8__as_Sfx_LoadSystemStam_1_0016AE30;

void Sfx_LoadSystemStam_1_0016AE30(void) {
    Chk * b;
    Chk * p;
    u32 i;
    u32 j;
    b = *D_00201FE8;
    memset(D_0033F6D0, 0, 0x1000);
    p = (Chk *)((u8 *)b + b->off);
    for (i = 0; i < b->xE; i++) {
        if (p->x0 == D_00201CA8) break;
        p = (Chk *)((u8 *)p + p->x4);
    }
    b = (Chk *)((u8 *)p + p->off);
    for (j = 0; j < p->xE; j++) {
        if (b->x0 == D_00201CAC) D_0033F6D0[b->x18] = (u8 *)b - (u8 *)*D_00201FE8;
        b = (Chk *)((u8 *)b + b->x4);
    }
    Sfx_LoadStam_1_00169D70(D_00201FE8, D_003406E0, 0x40);
    Tex_RegisterTtix_0_00178080(D_00201FE8);
}
#undef D_00201FE8

/* Sfx_ListInsert_0_0016AF40 */
#define D_00201CA0 D_00201CA0__as_Sfx_ListInsert_0_0016AF40
extern u16 D_00201CA0__as_Sfx_ListInsert_0_0016AF40;
#define D_00201FC0 D_00201FC0__as_Sfx_ListInsert_0_0016AF40
extern O *D_00201FC0__as_Sfx_ListInsert_0_0016AF40;
#define D_00201FD4 D_00201FD4__as_Sfx_ListInsert_0_0016AF40
extern N *D_00201FD4__as_Sfx_ListInsert_0_0016AF40;
#define D_00201FD8 D_00201FD8__as_Sfx_ListInsert_0_0016AF40
extern u16 D_00201FD8__as_Sfx_ListInsert_0_0016AF40;

void Sfx_ListInsert_0_0016AF40(u16 a0, u16 id, s32 which) {
    u16 *h;
    u16 k;

    h = which ? &D_00201CA4 : &D_00201C9C;
    if (D_00201FD4[id].prev != 0xFFFF) {
        D_00201FD4[D_00201FD4[id].prev].next = D_00201FD4[id].next;
    }
    if (D_00201FD4[id].next != 0xFFFF) {
        D_00201FD4[D_00201FD4[id].next].prev = D_00201FD4[id].prev;
    }
    if (D_00201FD4[id].prev == 0xFFFF) {
        *h = D_00201FD4[id].next;
    }
    if (D_00201CA0 != 0xFFFF) {
        D_00201FD4[D_00201CA0].prev = id;
    }
    D_00201FD4[id].next = D_00201CA0;
    D_00201FD4[id].prev = 0xFFFF;
    D_00201CA0 = id;
    D_00201FD8++;
    for (k = a0; k != 0xFFFF; k = D_00201FD4[k].sib) {
        if (id == D_00201FD4[k].sib) {
            D_00201FD4[k].sib = D_00201FD4[id].sib;
            break;
        }
    }
    D_00201FD4[id].sib = 0xFFFF;
    D_00201FC0[id].b0 = 0;
    D_00201FC0[id].b2 = 0;
}
#undef D_00201CA0
#undef D_00201FC0
#undef D_00201FD4
#undef D_00201FD8

/* Sfx_ListAlloc_0_0016B0F0 */
#define D_00201CA0 D_00201CA0__as_Sfx_ListAlloc_0_0016B0F0
extern u16 D_00201CA0__as_Sfx_ListAlloc_0_0016B0F0;
#define D_00201FC0 D_00201FC0__as_Sfx_ListAlloc_0_0016B0F0
extern O *D_00201FC0__as_Sfx_ListAlloc_0_0016B0F0;
#define D_00201FD4 D_00201FD4__as_Sfx_ListAlloc_0_0016B0F0
extern N *D_00201FD4__as_Sfx_ListAlloc_0_0016B0F0;
#define D_00201FD8 D_00201FD8__as_Sfx_ListAlloc_0_0016B0F0
extern u16 D_00201FD8__as_Sfx_ListAlloc_0_0016B0F0;

u16 Sfx_ListAlloc_0_0016B0F0(u16 a0, s32 which) {
    u16 *h;
    u16 id;

    h = which ? &D_00201CA4 : &D_00201C9C;
    if (D_00201FD8 == 0) return 0xFFFF;
    id = D_00201CA0;
    D_00201CA0 = D_00201FD4[id].next;
    if (D_00201CA0 != 0xFFFF) {
        D_00201FD4[D_00201CA0].prev = 0xFFFF;
    }
    D_00201FD4[id].prev = 0xFFFF;
    D_00201FD4[id].next = *h;
    if (*h != 0xFFFF) {
        D_00201FD4[*h].prev = id;
    }
    *h = id;
    D_00201FD8--;
    D_00201FD4[id].sib = a0;
    D_00201FC0[id].b0 = 1;
    return id;
}
#undef D_00201CA0
#undef D_00201FC0
#undef D_00201FD4
#undef D_00201FD8

/* Sfx_SetOwnerFlag_0_0016B200 */
void Sfx_SetOwnerFlag_0_0016B200(Obj *o, int v)
{
    o->t->f = v;
}

/* Sfx_GetFreeSlots_1_0016B230 */
#define D_0042D850 D_0042D850__as_Sfx_GetFreeSlots_1_0016B230
extern char D_0042D850__as_Sfx_GetFreeSlots_1_0016B230[];

u16 Sfx_GetFreeSlots_1_0016B230(void)
{
    return Pool_GetBlockUsable_1_00128830(D_0042D850) / 1728;
}
#undef D_0042D850

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): D_00201CA0 */
s16 D_00201CA0 = -1;
/* data twins (src/game/data/sbss.c): D_00201FAC, D_00201FC0, D_00201FD4, D_00201FD8, D_00201FE8 */
u32 D_00201FAC;
void *D_00201FC0;
L *D_00201FD4;
s16 D_00201FD8;
s32 D_00201FE8;
/* data twins (src/game/data/texture_bss.c): D_0042D850 */
s8 D_0042D850[0x30];
#endif
