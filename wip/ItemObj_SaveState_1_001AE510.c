/* NEAR: 57 of 66 instructions match. Retail keeps the count and object-array
 * offsets in its loads as it advances from the first bank to the second. */
#include "obj3d.h"

typedef struct {
    s32 mapId;
    u8 pad04[0x1D4];
    u8 flags;
} MapArea;

typedef struct {
    s16 otherCounts[2];
    s16 counts[2];
    Obj3D *objects[32];
} ItemObjectPool;

extern MapArea **gMapSbss_00201E88[2];
extern u8 gItemObjectSpawnBss_004AC5A0[];
void MapState_OffsetObjects_0_001A9810(s32);
void MapState_SetObjectPos_0_001A9A20(s32, s32, s16, Vec *, Vec *);

void ItemObj_SaveState_1_001AE510(void) {
    s16 *count;
    Obj3D **row;
    ItemObjectPool *pool;
    MapArea *map;
    s32 index;
    s32 bank;
    MapArea ***maps;

    pool = (ItemObjectPool *)gItemObjectSpawnBss_004AC5A0;
    count = pool->counts;
    row = pool->objects;
    maps = gMapSbss_00201E88;
    for (bank = 0; bank < 2; bank++, row += 16, count++) {
        if (maps[bank] != NULL && (map = *maps[bank]) != NULL && (map->flags & 1)) {
            MapState_OffsetObjects_0_001A9810(map->mapId);
            for (index = 0; index < *count; index++) {
                Obj3D *item = row[index];
                if (item->x9C != -1) {
                    MapState_SetObjectPos_0_001A9A20(map->mapId, index, item->x9C,
                                                      &item->x40, &item->x50);
                }
            }
        }
    }
}
