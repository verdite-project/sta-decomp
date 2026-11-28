/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Tex_LoadAnimated_0_0016FB80.c. The matching build takes it from the assembly that
 * texture_find.c includes (INCLUDE_ASM(Tex_LoadAnimated_0_0016FB80)). */
#ifdef NONMATCHING
// NEAR 6/256: only a0/a1 home slots (ours 0x11C/0x100, retail 0x110/0x10C). void* params + local copies with a1 declared first gives 0x110/0x10C but swapped (a1 0x110, a0 0x10C); extra params/decl moves/b38 no help.
#include "m2c.h"
typedef struct { u8 a:3; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u16 x14, x16, x18, x1A, x1C, x1E;
    u16 x20, x22;
    u8 pad24[8];
    s32 x2C;
    u8 pad30[0xC];
    union { s32 w; Bits f; } x3C;
} Obj;
typedef struct { Obj *obj; } Blk;
typedef struct { u16 x0, x2, x4, x6, x8; u8 xA, xB; u8 xC_0:3; u8 xC_3:3; u8 xC_6:2; u8 xD_0:2; u8 xD_2:1; u8 xD_3:5; u8 xE; } Info;
typedef struct { u8 pad[0x8]; s32 x8; s32 size; } Sub;
typedef struct { u32 magic; s32 next; u32 lo:8; u32 off:24; u16 xC; u16 cnt; Sub sub; } Hdr;
Blk *Pool_Alloc_3_001288C0(s32, s32);
void Pool_ArrayAppend_0_001535B0(s32 *, Blk *);
void memset(Obj *, s32, s32);
void Mdl_Relocate_1_00170380(Hdr *, Obj *);
Hdr *Node_FindById_2_0014DCD0(Hdr *, s32);
extern s8 D_001FB900[];
extern s8 D_001FB901[];
extern s8 D_001FB902[];
extern s8 D_001FB903[];

static inline void *data(Hdr *h) { Sub *s = &h->sub; return (void *)((s32)(s + 1) + ((s->size + 15) & ~15)); }
void Tex_LoadAnimated_0_0016FB80(s32 *a0, Hdr **a1, Blk ***a2, s32 **a3, s32 **a4) {
    u32 i; u32 j; Hdr *p; Hdr *q; Blk *b; Info *info; Hdr *t; Hdr *root; Sub *sub;
s32 **o1; s32 **o2; Blk ***o0; s8 *d1; s8 *d2; s8 *d3; s32 size;
    i = 0;
    root = *a1;
    p = (Hdr *)((s8 *)root + root->off);
    if (i < root->cnt) {
    o0 = a2; o1 = a3; o2 = a4; d1 = D_001FB901; d2 = D_001FB902; d3 = D_001FB903;
    do {
        switch (p->magic) {
        case 0x494F5453:
        q = (Hdr *)((s8 *)p + p->off);
        for (j = 0; j < p->cnt; j++, q = (Hdr *)((s8 *)q + q->next)) {
            switch (q->magic) {
            case 0x4D415453:
            t = Node_FindById_2_0014DCD0(q, D_001FB900[0] | (*d1 << 8) | (*d2 << 0x10) | (*d3 << 0x18));
            info = (Info *)data(q);
            size = info->x0 * 16 + 0x40 + info->x2 * 8 + info->x6 * 4 + info->xA * 0x50 + info->xE * 4;
            b = Pool_Alloc_3_001288C0(*a0, size);
            Pool_ArrayAppend_0_001535B0(a0 + 1, b);
            memset(b->obj, 0, size);
            b->obj->x10 = (s32)a1;
            b->obj->x14 = info->x0;
            b->obj->x16 = info->x2;
            b->obj->x18 = info->x6;
            b->obj->x1C = info->xA;
            b->obj->x1E = info->xE;
            b->obj->x1A = info->x8;
            b->obj->x22 = 0;
            b->obj->x2C = 0;
            b->obj->x3C.w = 0;
            b->obj->x3C.f.a = info->xC_3;
            b->obj->x3C.f.b6 = 0;
            if (info->xC_3 == 1 && info->xD_0 == 0 && info->xD_2 == 0) {
                b->obj->x3C.f.b6 = 1;
            }
            b->obj->x3C.f.b3 = 0;
            b->obj->x3C.f.b5 = 1;
            Mdl_Relocate_1_00170380(q, b->obj);
            **o0 = b;
            if (t != NULL) {
                **o1 = t->sub.x8;
                **o2 = (s32)data(t) - (s32)*a1;
            } else {
                **o1 = 0;
                **o2 = 0;
            }
            o1++;
            o2++;
            o0++;
            }
        }
        }
        i++; p = (Hdr *)((s8 *)p + p->next);
    } while (i < root->cnt);
    }
}
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sfx_all_rodata.c): D_001FB900, D_001FB901, D_001FB902, D_001FB903 */
s8 D_001FB900[0x1] = { 0x54 };
s8 D_001FB901[0x1] __attribute__((aligned(1))) = { 0x41 };
s8 D_001FB902[0x1] __attribute__((aligned(2))) = { 0x4e };
s8 D_001FB903[0x5] __attribute__((aligned(1))) = { 0x49, 0, 0, 0, 0 };
#endif
