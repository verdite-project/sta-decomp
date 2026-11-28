#include "game/map_object_records.h"

typedef struct {
    u8 pad0[0x30];
    MapObjArea *object;
    MapObjEntry *entry;
    MapObjState *state;
} MapObjHit;

typedef struct {
    s32 type;
    s32 triggerId;
    s32 objectId;
    s32 entryIndex;
    u8 pad10[0x20];
} MapObjEvent;

void memset(void *, s32, s32);
s32 Combat_SumResist_0_001AB500(u16 *, u16 *);
void MapObj_PlayAnimImpl_1_001B8350(s32, u32, s32);
s8 *MapObj_Find_1_001B19A0(s32);
s32 Event_CheckTrigger_0_00179F80(MapObjEvent *);

static inline MapObjNode *getHitNode(MapObjArea *object, s32 index) {
    MapObjState *states = object->states;
    MapObjEntry *entries = object->entries;
    MapObjNode *nodes = object->nodes;
    MapObjState *state = &states[index];
    MapObjEntry *entry = &entries[index];
    u8 flags = state->flags.b;
    MapObjNode *node = &nodes[entry->nodeIndex];

    if ((flags & 3) && node->flags.f.b3) {
        return &nodes[node->alternateNodeIndex];
    }
    return node;
}

s32 MapObj_Hit_0_001B85B0(u16 *attack, MapObjHit *hit) {
    s32 objectId;
    s32 index;
    MapObjNode *node;
    MapObjArea *object;
    MapObjEntry *current;
    MapObjArea *updated;
    MapObjEntry *entry;
    u16 resistance[8];
    MapObjEvent event;

    current = hit->entry;
    if (current != NULL) {
        if (hit->state != NULL) {
            object = hit->object;
            objectId = object->id;
            index = current - object->entries;
            node = getHitNode(object, index);
            if (node->type != 2) {
                return 0;
            }
            if (hit->state->flags.b & 3) {
                return 0;
            }
            memset(resistance, 0, sizeof(resistance));
            resistance[1] = node->resistance[0];
            resistance[2] = node->resistance[1];
            resistance[3] = node->resistance[2];
            resistance[5] = node->resistance[3];
            resistance[6] = node->resistance[4];
            resistance[7] = node->resistance[5];
            if (Combat_SumResist_0_001AB500(attack, resistance) >= node->threshold) {
                MapObj_PlayAnimImpl_1_001B8350(objectId, index, 0);
                updated = (MapObjArea *)MapObj_Find_1_001B19A0(objectId);
                if (updated != NULL) {
                    entry = &updated->entries[(u32)index];
                    if (entry->id % 100) {
                        memset(&event, 0, sizeof(event));
                        event.type = 8;
                        event.triggerId = entry->id % 100;
                        event.objectId = objectId;
                        event.entryIndex = index;
                        Event_CheckTrigger_0_00179F80(&event);
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}
