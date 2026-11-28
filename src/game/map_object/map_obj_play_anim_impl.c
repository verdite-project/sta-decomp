/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/MapObj_PlayAnimImpl_1_001B8350.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "game/map_object_records.h"

typedef enum { AnimationForward, AnimationReverse } AnimationDirection;

s8 *MapObj_Find_1_001B19A0(s32);
s32 MapState_GetField_0_001A9D50(s32, u16);
void MapState_SetField_0_001A9E10(s32, u16, u8);
void MapObj_SetAnimFrame_0_001B87C0(MapObjArea *, u32, s32, s32, f32, f32);
void Mdl_AnimateWrap_0_00171B70(MapObjModel *, s32, f32);
void sceVu0CopyVector(Vec *, Vec *);
void Mdl_UpdateBoneMatricesCur_0_00171540(MapObjModel *, Mtx *);
void MapObj_SpawnContainedItem_0_001BB760(MapObjArea *, s32, s32, void *, s32);

void MapObj_PlayAnimImpl_1_001B8350(s32 areaId, u32 index, s32 reverse) {
    MapObjModel *model;
    MapObjArea *area;
    MapObjEntry *entry;
    MapObjState *state;
    MapObjNode *node;
    MapObjNode *nodes;
    MapObjState *currentState;
    MapObjNode *currentNode;
    MapObjModel **handle;

    area = (MapObjArea *)MapObj_Find_1_001B19A0(areaId);
    if (area != NULL) {
        nodes = area->nodes;
        state = &area->states[index];
        entry = &area->entries[index];
        node = &nodes[entry->nodeIndex];
        if (node->type == 2 && !(state->flags.b & 3)) {
            state->flags.status.value = 1;
            currentState = &area->states[index];
            currentNode = &area->nodes[area->entries[index].nodeIndex];
            if ((currentState->flags.b & 3) && currentNode->flags.f.b3) {
                currentNode = &area->nodes[currentNode->alternateNodeIndex];
                handle = currentState->alternateModel;
            } else {
                handle = currentState->model;
            }
            model = *handle;
            if (currentNode->flags.f.b2) {
                MapObj_SetAnimFrame_0_001B87C0(area, index, 1,
                    (u8)(reverse ? AnimationReverse : AnimationForward), 0.0f, 1.0f);
                Mdl_AnimateWrap_0_00171B70(model, model->motionId, model->frame);
            } else if (currentNode->flags.f.b7) {
                state->flags.status.value = 2;
                state->timer = 1.0f;
            } else {
                state->flags.status.value = 3;
                state->flags52.f.b4 = 1;
            }
            sceVu0CopyVector(&model->position, &area->offset);
            Mdl_UpdateBoneMatricesCur_0_00171540(model, &state->transform);
            state->flags51.value = 2;
            if (MapState_GetField_0_001A9D50(areaId, index) == 0) {
                MapObj_SpawnContainedItem_0_001BB760(area, index, entry->itemId, entry, 0);
            }
            MapState_SetField_0_001A9E10(areaId, index, 1);
        }
    }
}
#else
INCLUDE_ASM(MapObj_PlayAnimImpl_1_001B8350);
#endif
