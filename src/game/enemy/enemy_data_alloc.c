#include "common.h"

typedef struct {
    s16 id;
    u16 slot;
    u8 unknown[0x750 - 4];
} EnemyData;

extern s32 gEnemyListSbss_00202278;
extern EnemyData **gEnemyListBss_004A4570[];
extern s16 gEnemyListBss_004A4774[];
extern u16 D_004A4776[];

EnemyData **Pool_Alloc_3_001288C0(s32 pool, s32 size);
void *memset(void *dest, s32 value, u32 size);
void EnemyMgr_ReleaseData_0_001A51E0(EnemyData **handle);

static inline s32 registerEnemyData(EnemyData ***handle) {
    EnemyData *data;
    u16 slot;

    if (!handle) {
        return 0;
    }
    data = **handle;
    memset(data, 0, sizeof(EnemyData));
    slot = D_004A4776[--gEnemyListBss_004A4774[0]];
    data->slot = slot;
    gEnemyListBss_004A4570[slot] = *handle;
    return 1;
}

EnemyData **EnemyData_Alloc_0_001A7D90(s16 id) {
    EnemyData **handle = Pool_Alloc_3_001288C0(gEnemyListSbss_00202278, sizeof(EnemyData));

    if (!registerEnemyData(&handle)) {
        return NULL;
    }
    (*handle)->id = id;
    EnemyMgr_ReleaseData_0_001A51E0(handle);
    return handle;
}
