#include "game/map_object_records.h"

typedef struct {
    u8 pad0[0x16];
    u16 motionCount;
} MapObjMotionData;

struct MapObjModel {
    MapObjMotionData **motion;
    u8 pad4[8];
    f32 frame;
    f32 previousFrame;
    u8 pad14[0xC];
    f32 x20;
};

void Mdl_SetBoneRotation_0_001710D0(MapObjModel *, s16, f32, f32, f32);
f32 Mdl_GetMotionLength_0_00173F70(MapObjMotionData *, u16);

void MapObj_SetAnimFrame_0_001B87C0(MapObjArea *area, u32 index, s32 anim, s32 flags, f32 frame, f32 speed) {
    MapObjState *state;
    MapObjModel *model;
    MapObjMotionData **motion;
    MapObjModel **modelHandle;
    u16 animationIndex;
    u16 nodeIndex;
    MapObjNode *nodes;
    MapObjNode *node;
    MapObjAnimationMap *animation;
    f32 length;
    MapObjState *states;
    MapObjEntry *entry;
    u32 status;

    if (area == NULL || index >= area->entryCount) {
        return;
    }
    states = ((volatile MapObjArea *)area)->states;
    state = &states[index];
    status = state->flags.b & 3;
    entry = &area->entries[index];
    nodeIndex = entry->nodeIndex;
    nodes = area->nodes;
    node = &nodes[nodeIndex];
    if (status && node->flags.f.b3) {
        animationIndex = area->nodes[node->alternateNodeIndex].id;
        modelHandle = state->alternateModel;
    } else {
        modelHandle = state->model;
        animationIndex = nodeIndex;
    }
    model = *modelHandle;
    motion = model->motion;
    animation = &area->animations[animationIndex];
    if (motion == NULL || *motion == NULL) {
        return;
    }
    if ((*motion)->motionCount <= 0) {
        return;
    }
    if (anim < 0 || (u32)anim >= animation->count) {
        return;
    }
    anim = animation->motionIds[anim];
    if (anim == 0xFF) {
        return;
    }
    Mdl_SetBoneRotation_0_001710D0(model, anim, speed, 0.0f, 0.0f);
    state->flags.f.b2 = 1;
    state->flags.f.b4 = 0;
    length = Mdl_GetMotionLength_0_00173F70(*motion, anim);
    if (flags & 0x80) {
        state->flags.f.b3 = 1;
    } else {
        state->flags.f.b3 = 0;
    }
    if (flags & 0x40) {
        state->flags.f.b5 = 1;
    } else {
        state->flags.f.b5 = 0;
    }
    if (!(flags & 1)) {
        model->frame = frame;
        model->previousFrame = frame;
        model->x20 = model->frame;
    } else {
        model->frame = length - frame;
        if (model->frame < 0.0f) {
            model->frame = 0.0f;
        }
        model->previousFrame = model->frame;
        model->x20 = model->frame;
    }
}
