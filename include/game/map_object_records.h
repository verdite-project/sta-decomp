#ifndef GAME_MAP_OBJECT_RECORDS_H
#define GAME_MAP_OBJECT_RECORDS_H

#include "common.h"

typedef struct {
    u8 pad0[0x18];
    u16 nodeIndex;
    u16 id;
    u8 pad1C[0x14];
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

typedef struct MapObjModel MapObjModel;

typedef struct {
    Mtx transform;
    MapObjModel **model;
    MapObjModel **alternateModel;
    u8 pad48[8];
    Flags8 flags;
    u8 pad51[0x2F];
} MapObjState;

typedef struct {
    u8 pad0[4];
    u32 count;
    u8 *motionIds;
    u8 padC[4];
} MapObjAnimationMap;

typedef struct {
    s32 id;
    u8 pad4[0x6A];
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
