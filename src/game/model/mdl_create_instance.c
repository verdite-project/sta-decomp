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
void Pool_ArrayAppend_0_001535B0(s32 *, s8 *);
void memset(Obj *, s32, s32);
void sceVu0CopyMatrix(Mtx *, Mtx *);
extern Mtx gMdlCreateInstanceData_001F2340[];

Obj **Mdl_CreateInstance_0_00174230(s32 *pool, Src **sourceHandle, s32 firstNode, s32 count) {
    s8 *entry;
    s32 nodeCount;
    Obj *instance;
    s32 size;
    Obj **instanceHandle;
    s32 i;
    s32 j;
    Blk *blk;
    u8 *base;
    Src *src;
    s32 entries;
    s32 v;
    u8 parentIndex;
    Ent *e;

    src = *sourceHandle;
    nodeCount = 0;
    if (firstNode == -1) {
        firstNode = 0;
        if (count == -1) {
            nodeCount = src->x14;
        }
    }
    if (count != -1) {
        nodeCount = count;
    }
    FlushCache(0);
    size = (nodeCount * 0x140 + 0x200) * 2 + 0x40;
    instanceHandle = Pool_Alloc_3_001288C0(*pool, size);
    entry = (s8 *)instanceHandle;
    if (instanceHandle == NULL) {
        return NULL;
    }
    Pool_ArrayAppend_0_001535B0(pool + 0x34 / 4, entry);
    memset(*instanceHandle, 0, size);
    instance = *instanceHandle;
    instance->x0 = sourceHandle;
    instance->x4 = firstNode;
    instance->x6 = nodeCount;
    instance->x8 = 0;
    instance->xC = 0;
    instance->x10 = 0;
    instance->x14 = 1.0f;
    instance->x18 = 0;
    instance->x1C = 0;
    instance->x24.w = 0;
    instance->x24.f.b0 = 1;
    instance->x24.f.b1 = 1;
    instance->x24.f.b2 = 1;
    instance->x24.f.b3 = 1;
    instance->x24.f.b4 = 1;
    instance->x24.f.b5 = 1;
    instance->x24.f.b6 = 0;
    src->x22++;
    if (count == -1) {
        for (i = 0; i < 2; i++) {
            blk = (Blk *)((s32)instance->data + (u32)i * (nodeCount * 0x140 + 0x200));
            base = *src->x10;
            entries = (s32)src->e;
            sceVu0CopyMatrix(&blk->nd[0].m1, gMdlCreateInstanceData_001F2340);
            sceVu0CopyMatrix(&blk->nd[0].m0, gMdlCreateInstanceData_001F2340);
            blk->nd[0].b130 = 0xFF;
            blk->nd[0].b132 = 0xFF;
            blk->nd[0].f134 = 1.0f;
            blk->x0 = src->x3C & 7;
            blk->x4 = 0;
            for (j = 0; j < nodeCount; j++) {
                e = (Ent *)(entries + (firstNode + j) * 16);
                if (e->x8 == 0) {
                    sceVu0CopyMatrix(&blk->nd[j + 1].m0, gMdlCreateInstanceData_001F2340);
                    sceVu0CopyMatrix(&blk->nd[j + 1].m1, gMdlCreateInstanceData_001F2340);
                } else {
                    sceVu0CopyMatrix(&blk->nd[j + 1].m0, (Mtx *)(base + e->x8));
                    sceVu0CopyMatrix(&blk->nd[j + 1].m1, (Mtx *)(base + e->xC));
                }
                parentIndex = (base + e->x0)[2];
                v = 0;
                if (parentIndex != 0xFF) {
                    v = parentIndex - firstNode + 1;
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
    return instanceHandle;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern unsigned char gDoorSbss_00202030[];
extern unsigned char gMenuBss_00317230[];
extern unsigned char gMapCommandBss_00317238[];
extern unsigned char gPlayerBss_0031723C[];
extern unsigned char gMdlCreateInstanceBss_00486900[];
extern unsigned char gMdlCreateInstanceBss_00486940[];
/* data group (src/game/data/screen_fx_flash_data_001F2340.c): D_001F2340__grp: gMdlCreateInstanceData_001F2340@0x0 */
int D_001F2340__grp[0x30] __attribute__((aligned(16))) = { 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, (int)gMdlCreateInstanceBss_00486940, (int)gMdlCreateInstanceBss_00486900, (int)gPlayerBss_0031723C, (int)gMapCommandBss_00317238, (int)gMenuBss_00317230, (int)gDoorSbss_00202030, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
/* data twins (src/game/data/ui_anim_bss.c): gMdlCreateInstanceBss_00486900, gMdlCreateInstanceBss_00486940 */
unsigned char gMdlCreateInstanceBss_00486900[0x40];
unsigned char gMdlCreateInstanceBss_00486940[0x40];
#endif
