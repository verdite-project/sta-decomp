/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Mdl_CreateInstance_0_00174230.c. */
#include "include_asm.h"

#ifdef NONMATCHING
// NEAR: 2 of 232 words differ (b52; b38 same). Fixed spill slots: whole body is an inline taking src (= *arg1, becomes a 16-aligned temp) and &off (off lives at its param home). Remaining: the h==NULL early return in the inline stores 0 to h slot and branches to the shared return (b 0xA4; sw zero,0xE0) instead of retail b 0xAE; daddu v0,zero,zero.
/* round 3 near-miss: 12 words: only two spill slots differ (h is a temp in retail) */
#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } Ent;
typedef struct {
    u8 pad0[0x10];
    u8 **x10;
    u16 x14;
    u8 pad16[0xC];
    s16 x22;
    u8 pad24[0x18];
    u8 x3C;
    u8 pad3D[3];
    Ent e[1];
} Src;
typedef struct { Mtx m0; u8 pad40[0x40]; Mtx m1; u8 padC0[0x70]; u8 b130; u8 b131; u8 b132; u8 pad133; f32 f134; u8 pad138[8]; } Node;
typedef struct { s32 x0; s32 x4; u8 pad8[0xB8]; Node nd[1]; } Blk;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:2; } Bits;
typedef struct {
    Src **x0;
    s16 x4;
    u16 x6;
    s32 x8, xC, x10;
    f32 x14;
    s32 x18, x1C;
    u8 pad20[4];
    union { s32 w; Bits f; } x24;
    u8 pad28[0x18];
    u8 data[1];
} Obj;
void FlushCache(s32);
Obj **Pool_Alloc_3_001288C0(s32, s32);
void Pool_ArrayAppend_0_001535B0(s32 *, Obj **);
void memset(Obj *, s32, s32);
void sceVu0CopyMatrix(Mtx *, Mtx *);
extern Mtx D_001F2340[];
static inline Blk *getb(s32 d, u32 i, s32 sz) { return (Blk *)(d + i * sz); }
static inline Obj **body(s32 *arg0, Src **arg1, s32 *poff, s32 arg3, Src *src) {
    s32 n;
    Obj *o;
    s32 size;
    Obj **h;
    s32 i;
    s32 j;
    Blk *blk;
    u8 *base;
    Ent *e;
    s32 es;
    s32 v;
    u8 c;

    n = 0;
    if (*poff == -1) {
        *poff = 0;
        if (arg3 == -1) {
            n = src->x14;
        }
    }
    if (arg3 != -1) {
        n = arg3;
    }
    FlushCache(0);
    size = (n * 0x140 + 0x200) * 2 + 0x40;
    h = Pool_Alloc_3_001288C0(*arg0, size);
    if (h == NULL) {
        return NULL;
    }
    Pool_ArrayAppend_0_001535B0(arg0 + 0x34 / 4, h);
    memset(*h, 0, size);
    o = *h;
    o->x0 = arg1;
    o->x4 = *poff;
    o->x6 = n;
    o->x8 = 0;
    o->xC = 0;
    o->x10 = 0;
    o->x14 = 1.0f;
    o->x18 = 0;
    o->x1C = 0;
    o->x24.w = 0;
    o->x24.f.b0 = 1;
    o->x24.f.b1 = 1;
    o->x24.f.b2 = 1;
    o->x24.f.b3 = 1;
    o->x24.f.b4 = 1;
    o->x24.f.b5 = 1;
    o->x24.f.b6 = 0;
    src->x22++;
    if (arg3 == -1) {
        for (i = 0; i < 2; i++) {
            blk = (Blk *)((s32)o->data + (u32)i * (n * 0x140 + 0x200));
            base = *src->x10;
            es = (s32)src->e;
            sceVu0CopyMatrix(&blk->nd[0].m1, D_001F2340);
            sceVu0CopyMatrix(&blk->nd[0].m0, D_001F2340);
            blk->nd[0].b130 = 0xFF;
            blk->nd[0].b132 = 0xFF;
            blk->nd[0].f134 = 1.0f;
            blk->x0 = src->x3C & 7;
            blk->x4 = 0;
            for (j = 0; j < n; j++) {
                e = (Ent *)(es + (*poff + j) * 16);
                if (e->x8 == 0) {
                    sceVu0CopyMatrix(&blk->nd[j + 1].m0, D_001F2340);
                    sceVu0CopyMatrix(&blk->nd[j + 1].m1, D_001F2340);
                } else {
                    sceVu0CopyMatrix(&blk->nd[j + 1].m0, (Mtx *)(base + e->x8));
                    sceVu0CopyMatrix(&blk->nd[j + 1].m1, (Mtx *)(base + e->xC));
                }
                c = (base + e->x0)[2];
                v = 0;
                if (c != 0xFF) {
                    v = c - *poff + 1;
                    if (v <= 0) {
                        v = 0;
                    }
                }
                blk->nd[j + 1].b130 = j;
                blk->nd[j + 1].b132 = j;
                blk->nd[j + 1].b131 = v;
                blk->nd[j + 1].f134 = 1.0f;
            }
        }
    }
    return h;
}

Obj **Mdl_CreateInstance_0_00174230(s32 *arg0, Src **arg1, s32 off, s32 arg3) { return body(arg0, arg1, &off, arg3, *arg1); }
#else
INCLUDE_ASM(Mdl_CreateInstance_0_00174230);
#endif
