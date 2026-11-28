#include "obj3d.h"

typedef struct {
    s32 mapId;
    u8 pad04[0x1D4];
    u8 flags;
} MapArea;

typedef struct {
    s16 otherCounts[2];
    s16 counts[2];
    Obj3D *objects[2][16];
} ItemObjectPool;

extern MapArea **gMapSbss_00201E88[2];
extern volatile ItemObjectPool gItemObjectSpawnBss_004AC5A0;
void MapState_OffsetObjects_0_001A9810(s32);
void MapState_SetObjectPos_0_001A9A20(s32, s32, s16, Vec *, Vec *);

void ItemObj_SaveState_1_001AE510(void) {
    MapArea *map;
    s32 index;
    s32 bank;
    MapArea ***maps;

    maps = gMapSbss_00201E88;
    for (bank = 0; bank < 2; bank++) {
        if (maps[bank] != NULL && (map = *maps[bank]) != NULL && (map->flags & 1)) {
            MapState_OffsetObjects_0_001A9810(map->mapId);
            for (index = 0; index < gItemObjectSpawnBss_004AC5A0.counts[bank]; index++) {
                Obj3D *item = gItemObjectSpawnBss_004AC5A0.objects[bank][index];
                if (item->x9C != -1) {
                    MapState_SetObjectPos_0_001A9A20(map->mapId, index, item->x9C,
                                                      &item->x40, &item->x50);
                }
            }
        }
    }
}
