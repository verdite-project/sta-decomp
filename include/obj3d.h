/* 0xD0-byte scene objects kept in three pools: gItemObjectBss_004AE370 (2x64, type 0), gItemObjectBss_004AC970 (2x16, type 1)
 * and gItemObjectSpawnBss_004AC630 (4, type 2); ItemObj_ClearTables_1_001AFA20 clears and initialises them. Fields are named by offset
 * until known. Merged from the local copies in src/game_001A*.c; some files read xAE as u16. */
#ifndef OBJ3D_H
#define OBJ3D_H

#include "common.h"

typedef struct Obj3D {
    Mtx m;          /* 0x00 world matrix; m.m[3] is the position */
    Vec x40;        /* 0x40..0x7F: transform inputs to Mtx_Compose_2_00173FD0 (x40/x50/x60), x70 an offset */
    Vec x50;
    Vec x60;
    Vec x70;
    s32 x80;
    s8 *x84;        /* passed to Mdl_ResetBones_0_00171610 when xA8.f.b0 is set */
    s32 x88;
    s32 **x8C;      /* **x8C is an owner id (ItemObj_OffsetAll_0_001AC0F0) */
    u8 pad90[0xC];
    s16 x9C;        /* bone/entry index into gItemObjectSbss_002022B0; -1 = slot free */
    s16 x9E;        /* pool type set by ItemObj_ClearTables_1_001AFA20 */
    u8 padA0[4];
    s8 xA4;
    s8 xA5;
    s8 xA6;
    s8 xA7;         /* -1 after init */
    Flags8 xA8;
    Flags8 xA9;     /* b0, b1 = local, b2 = hidden */
    u16 xAA;        /* id */
    s16 xAC;
    s16 xAE;        /* -1 after init */
    s32 xB0;
    f32 xB4;        /* 1.0f after init */
    u8 padB8[0x18];
} Obj3D;

extern Obj3D gItemObjectSpawnBss_004AC630[4];
extern Obj3D gItemObjectBss_004AC970[2][16];
extern Obj3D gItemObjectBss_004AE370[2][64];

#endif
