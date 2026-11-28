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
void Pool_ArrayAppend_0_001535B0(s32 *, s8 *);
void memset(Obj *, s32, s32);
void Mdl_Relocate_1_00170380(Hdr *, Obj *);
Hdr *Node_FindById_2_0014DCD0(Hdr *, s32);
extern s8 gTextureFindRodata_001FB900[];
extern s8 gTextureFindRodata_001FB901[];
extern s8 gTextureFindRodata_001FB902[];
extern s8 gTextureFindRodata_001FB903[];

static inline void *chunkData(Hdr *h) {
    Sub *s = &h->sub;
    return (void *)((s32)(s + 1) + ((s->size + 15) & ~15));
}

typedef struct {
    s32 poolId;
    s32 textures[0x30 / sizeof(s32)];
    s32 instances[0x30 / sizeof(s32)];
    u8 pad64[0xC];
} ModelPool;
typedef ModelPool PoolContext[1] __attribute__((aligned(16)));

void Tex_LoadAnimated_0_0016FB80(PoolContext pool, Hdr **sourceHandle, Blk ***a2, s32 **a3, s32 **a4) {
    s8 *entry;
    s32 sourceAddress;
    u32 i;
    u32 j;
    Hdr *chunk;
    Hdr *child;
    Blk *texture;
    Info *info;
    Hdr *animation;
    Hdr *root;
    s32 **o1;
    s32 **o2;
    Blk ***o0;
    s8 *d1;
    s8 *d2;
    s8 *d3;
    s32 size;

    sourceAddress = (s32)sourceHandle;
    i = 0;
    root = *(Hdr **)sourceAddress;
    chunk = (Hdr *)((s8 *)root + root->off);
    if (i < root->cnt) {
        o0 = a2;
        o1 = a3;
        o2 = a4;
        d1 = gTextureFindRodata_001FB901;
        d2 = gTextureFindRodata_001FB902;
        d3 = gTextureFindRodata_001FB903;
        do {
            switch (chunk->magic) {
            case 0x494F5453: /* STOI */
                child = (Hdr *)((s8 *)chunk + chunk->off);
                for (j = 0; j < chunk->cnt; j++, child = (Hdr *)((s8 *)child + child->next)) {
                    switch (child->magic) {
                    case 0x4D415453: /* STAM */
                        animation = Node_FindById_2_0014DCD0(child, gTextureFindRodata_001FB900[0] | (*d1 << 8) | (*d2 << 16) | (*d3 << 24));
                        info = (Info *)chunkData(child);
                        size = info->x0 * 16 + 0x40 + info->x2 * 8 + info->x6 * 4 + info->xA * 0x50 + info->xE * 4;
                        texture = Pool_Alloc_3_001288C0(pool->poolId, size);
                        entry = (s8 *)texture;
                        Pool_ArrayAppend_0_001535B0(pool->textures, entry);
                        memset(texture->obj, 0, size);
                        texture->obj->x10 = sourceAddress;
                        texture->obj->x14 = info->x0;
                        texture->obj->x16 = info->x2;
                        texture->obj->x18 = info->x6;
                        texture->obj->x1C = info->xA;
                        texture->obj->x1E = info->xE;
                        texture->obj->x1A = info->x8;
                        texture->obj->x22 = 0;
                        texture->obj->x2C = 0;
                        texture->obj->x3C.w = 0;
                        texture->obj->x3C.f.a = info->xC_3;
                        texture->obj->x3C.f.b6 = 0;
                        if (info->xC_3 == 1 && info->xD_0 == 0 && info->xD_2 == 0) {
                            texture->obj->x3C.f.b6 = 1;
                        }
                        texture->obj->x3C.f.b3 = 0;
                        texture->obj->x3C.f.b5 = 1;
                        Mdl_Relocate_1_00170380(child, texture->obj);
                        **o0 = texture;
                        if (animation != NULL) {
                            **o1 = animation->sub.x8;
                            **o2 = (s32)chunkData(animation) - (s32)*(Hdr **)sourceAddress;
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
            i++;
            chunk = (Hdr *)((s8 *)chunk + chunk->next);
        } while (i < root->cnt);
    }
}
