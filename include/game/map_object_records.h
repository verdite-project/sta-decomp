#ifndef GAME_MAP_OBJECT_RECORDS_H
#define GAME_MAP_OBJECT_RECORDS_H

#include "common.h"

typedef struct {
    u8 pad0[0x18];
    u16 nodeIndex;
    u16 id;
    u8 pad1C[0xC];
    s16 itemId;
    u8 pad2A[6];
} MapObjEntry;

typedef struct {
    u16 id;
    u8 pad2[2];
    u16 type;
    u16 alternateNodeIndex;
    u8 pad8[0xA];
    Flags8 flags;
    u8 pad13;
    u16 threshold;
    u8 resistance[6];
    u8 pad1C[0x24];
} MapObjNode;

typedef struct {
    u8 pad0[0x16];
    u16 motionCount;
} MapObjMotionData;

typedef struct {
    MapObjMotionData **motion;
    u8 pad4[4];
    u16 motionId;
    u8 padA[2];
    f32 frame;
    f32 previousFrame;
    u8 pad14[0xC];
    f32 x20;
    u8 pad24[0xC];
    Vec position;
} MapObjModel;

typedef struct {
    Mtx transform;
    MapObjModel **model;
    MapObjModel **alternateModel;
    u8 pad48[8];
    union {
        u8 b;
        Bits8 f;
        struct { u8 value : 2; } status;
    } flags;
    struct { u8 b0 : 1; u8 value : 2; } flags51;
    Flags8 flags52;
    u8 pad53[9];
    f32 timer;
    u8 pad60[0x20];
} MapObjState;

typedef struct {
    u8 pad0[4];
    u32 count;
    u8 *motionIds;
    u8 padC[4];
} MapObjAnimationMap;

typedef struct {
    s32 id;
    u8 pad4[0xC];
    Vec offset;
    u8 pad20[0x4E];
    u16 entryCount;
    u8 pad70[0xC8];
    MapObjEntry *entries;
    u8 pad13C[0x34];
    MapObjNode *nodes;
    u8 pad174[0xC];
    MapObjState *states;
    u8 pad184[0x10];
    MapObjAnimationMap *animations;
} MapObjArea;

#endif
