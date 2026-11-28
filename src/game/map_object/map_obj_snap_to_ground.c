#include "common.h"

typedef f32 MapVector[4] __attribute__((aligned(16)));
typedef union {
    u8 raw;
    struct { u8 state : 2; } bits;
} ObjectStatus;

typedef struct {
    u8 pad0[0x12];
    u16 scaleX, scaleY, scaleZ;
    u16 definitionIndex;
    u8 pad1A[0x16];
} ObjectPlacement;

typedef struct {
    u8 pad0[4];
    u16 type;
    u16 alternateIndex;
    u8 pad8[0xA];
    Bits8 flags;
    u8 pad13[0x2D];
} ObjectDefinition;

typedef struct {
    Mtx transform;
    s8 **model, **alternateModel;
    u8 pad48[8];
    ObjectStatus status;
    u8 pad51;
    Bits8 flags52, flags53;
    u8 pad54[8];
    f32 timer;
    u8 pad60[0x20];
} MapObject;

typedef struct {
    u8 pad0[0x10];
    Vec offset;
    u8 pad20[0x4E];
    u16 objectCount;
    u8 pad70[0xC8];
    ObjectPlacement *placements;
    u8 pad13C[0x34];
    ObjectDefinition *definitions;
    u8 pad174[0xC];
    MapObject *objects;
    u8 pad184[0x54];
    Bits8 flags;
} MapArea;

extern MapArea **gMapSbss_00201E88[2];
s8 *Mdl_GetFrameData_0_001715B0(s8 **);
void sceVu0SubVector(Vec *, MapVector, Vec *);
f32 fabsf(f32);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
f32 atan2f(f32, f32);
void MapObj_SetAnimFrame_0_001B87C0(MapArea *, u32, s32, s32, f32, f32);
void Mdl_AnimateWrap_0_00171B70(s8 *, u16, f32);
void sceVu0CopyVector(void *, void *);
void Mdl_UpdateBoneMatricesCur_0_00171540(s8 *, Mtx *);

#define PI 3.1415927f
#define TWOPI 6.2831855f
#define INV_TWOPI 0.15915494f
#define WRAP(x) ((((x) + PI) - TWOPI * (s32)(INV_TWOPI * ((x) + PI))) + (((x) + PI) < 0.0f ? TWOPI : 0.0f) - PI)

static inline f32 uintToFloat(u32 value) {
    return value;
}

void MapObj_SnapToGround_0_001B9F10(MapVector pos, MapVector rot, f32 scale, f32 maxHeight) {
    ObjectDefinition *definition;
    MapArea ***areaHandle;
    s32 slot;
    MapArea *area;
    s32 index;
    MapObject *object;
    ObjectPlacement *placement;
    s8 *frame;
    s8 *model;
    s8 **modelHandle;
    MapObject *currentObject;
    ObjectDefinition *currentDefinition;
    f32 scaleX;
    f32 objectScale;
    f32 range;
    f32 turn;
    f32 wrapped;
    f32 angleDiff;
    Vec delta;

    for (slot = 0, areaHandle = gMapSbss_00201E88; slot < 2; slot++, areaHandle++) {
        if (*areaHandle == NULL) continue;
        area = **areaHandle;
        if (area == NULL) continue;
        if (area->flags.b1) continue;
        if (!area->flags.b0) continue;
        for (index = 0; index < area->objectCount; index++) {
            placement = &area->placements[index];
            object = &area->objects[index];
            definition = &area->definitions[placement->definitionIndex];
            frame = Mdl_GetFrameData_0_001715B0(object->model);
            if (definition->type != 4) continue;
            if (!object->flags52.b3) continue;
            if (object->status.raw & 3) continue;
            if (object->flags53.b2) continue;
            scaleX = (1.0f / 4096.0f) * uintToFloat(placement->scaleX);
            objectScale = (1.0f / 4096.0f) * uintToFloat(placement->scaleZ);
            /* Keep the retail branch layout for the maximum of the X and Z scales. */
            if (scaleX < objectScale) {
                objectScale = objectScale;
            } else {
                objectScale = scaleX;
            }
            range = scale * objectScale;
            sceVu0SubVector(&delta, pos, (Vec *)(frame + 0x230));
            if (!(fabsf(delta.y) <= maxHeight)) continue;
            delta.y = 0.0f;
            if (!(sceVu0InnerProduct(&delta, &delta) <= range * range)) continue;
            sceVu0ScaleVector(&delta, &delta, -1.0f);
            range = PI + rot[1];
            turn = range < 0.0f ? TWOPI : 0.0f;
            wrapped = range - TWOPI * (s32)(INV_TWOPI * range);
            angleDiff = atan2f(-delta.x, -delta.z) - (wrapped + turn - PI);
            if (!(fabsf(WRAP(angleDiff)) <= 1.39626348f)) continue;
            object->status.bits.state = 1;
            currentObject = &area->objects[index];
            currentDefinition = &area->definitions[area->placements[index].definitionIndex];
            if ((currentObject->status.raw & 3) && currentDefinition->flags.b3) {
                currentDefinition = &area->definitions[currentDefinition->alternateIndex];
                modelHandle = currentObject->alternateModel;
            } else {
                modelHandle = currentObject->model;
            }
            model = *modelHandle;
            if (currentDefinition->flags.b2) {
                MapObj_SetAnimFrame_0_001B87C0(area, index, 1, 0, 0.0f, 1.0f);
                Mdl_AnimateWrap_0_00171B70(model, *(u16 *)(model + 8), *(f32 *)(model + 0xC));
            } else if (currentDefinition->flags.b7) {
                object->status.bits.state = 2;
                object->timer = 1.0f;
            } else {
                object->status.bits.state = 3;
                object->flags52.b4 = 1;
            }
            sceVu0CopyVector(model + 0x30, &area->offset);
            Mdl_UpdateBoneMatricesCur_0_00171540(model, &object->transform);
            object->flags53.b2 = 1;
        }
    }
}
