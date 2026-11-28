#include "common.h"

typedef struct {
    u8 pad0[0x12];
    u16 scaleX, scaleY, scaleZ;
    u16 definitionIndex;
    u8 pad1A[0xA];
    struct { u8 : 2; u8 mode : 2; } flags;
    u8 pad25[0xB];
} TrapPlacement;

typedef struct {
    u8 pad0[0xE];
    u16 radius;
    u8 pad10[2];
    Bits8 flags12, flags13;
    u8 pad14[0x2C];
} TrapDefinition;

typedef struct {
    u8 pad0[0x40];
    s8 **model;
    u8 pad44[0xC];
    Bits8 flags50;
    u8 pad51;
    Bits8 flags52, flags53;
    u8 pad54[0x2C];
} TrapObject;

typedef struct {
    u8 pad0[0x138];
    TrapPlacement *placements;
    u8 pad13C[0x34];
    TrapDefinition *definitions;
    u8 pad174[0xC];
    TrapObject *objects;
} TrapArea;

s8 *Mdl_GetFrameData_0_001715B0(s8 **);
s32 MapObj_IsActorNear_0_001B9E00(s8 *, s32, f32);
void MapObj_SetAnimFrame_0_001B87C0(TrapArea *, u32, s32, s32, f32, f32);
void Trap_UpdateIdle_1_001BA680(TrapArea *, u32, f32, f32);
void Trap_SetState_0_001BA850(TrapArea *, f32, u32, f32);

static inline f32 uintToFloat(u32 value) {
    return value;
}

void Trap_Update_0_001BA3F0(TrapArea *area, u32 index, f32 dt, f32 x) {
    TrapPlacement *placement;
    TrapObject *object;
    TrapDefinition *definition;
    s8 *frame;
    f32 scaleX, scaleZ, horizontalScale;
    f32 radius;

    placement = &area->placements[index];
    object = &area->objects[index];
    definition = &area->definitions[placement->definitionIndex];
    frame = Mdl_GetFrameData_0_001715B0(object->model);
    if (object->flags53.b2) {
        Trap_UpdateIdle_1_001BA680(area, index, dt, x);
        return;
    }

    scaleX = (1.0f / 4096.0f) * uintToFloat(placement->scaleX);
    scaleZ = (1.0f / 4096.0f) * uintToFloat(placement->scaleZ);
    horizontalScale = scaleX < scaleZ ? scaleZ : scaleX;
    radius = uintToFloat(definition->radius);
    /* The f32 cast preserves the retail multiply operand order in MWCC. */
    if (MapObj_IsActorNear_0_001B9E00(frame + 0x230, definition->flags13.b3, radius * (f32)horizontalScale)) {
        if (!object->flags52.b6) {
            object->flags52.b6 = 1;
            MapObj_SetAnimFrame_0_001B87C0(area, index, 0xB, 0, 0.0f, 1.0f);
            return;
        }
    } else {
        object->flags52.b6 = 0;
    }
    if (definition->flags12.b0 && placement->flags.mode == 1 && object->flags50.b4) {
        MapObj_SetAnimFrame_0_001B87C0(area, index, 0, 0x80, 0.0f, 1.0f);
        return;
    }
    Trap_SetState_0_001BA850(area, dt, index, x);
}
