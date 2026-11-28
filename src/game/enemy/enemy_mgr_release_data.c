#include "common.h"

typedef struct {
    s32 key;
    s32 state;
    u8 pad08[0x10];
    s32 dataHandle;
    u8 pad1C[4];
    s32 unk20;
    u8 pad24[4];
} EnemyDataEntry;

enum { ENEMY_DATA_CAPACITY = 11 };

typedef struct {
    EnemyDataEntry entries[ENEMY_DATA_CAPACITY];
} EnemyDataTable;

typedef struct {
    s16 key;
    u8 pad02[0xA];
    s32 dataHandle;
    u8 pad10[0x590];
    u16 bit0 : 1;
    u16 registered : 1;
    u16 bit2 : 1;
    u16 slotNumber : 8;
} EnemyData;

extern volatile EnemyDataTable gEnemyDataTbl_004A43B0;

/* Retail also writes these three words when the search exhausts all eleven
 * entries. The first two land in the table's trailing storage and the third
 * lands at byte 0x18 of the following enemy list. */
static inline volatile s32 *slotWord(volatile s32 *firstWord, u32 index) {
    return (volatile s32 *)((u32)firstWord + index * sizeof(EnemyDataEntry));
}

void EnemyMgr_ReleaseData_0_001A51E0(EnemyData **handle) {
    EnemyData *data = *handle;
    s16 key = data->key;
    s32 i;

    for (i = 0; i < ENEMY_DATA_CAPACITY; i++) {
        if (key == gEnemyDataTbl_004A43B0.entries[i].key) {
            break;
        }
    }
    if (i != ENEMY_DATA_CAPACITY) {
        data->dataHandle = gEnemyDataTbl_004A43B0.entries[i].dataHandle;
        data->registered = 1;
        data->slotNumber = i + 1;
        return;
    }
    for (i = 0; i < ENEMY_DATA_CAPACITY; i++) {
        if (gEnemyDataTbl_004A43B0.entries[i].key == -1) {
            break;
        }
    }
    *slotWord(&gEnemyDataTbl_004A43B0.entries[0].key, i) = key;
    *slotWord(&gEnemyDataTbl_004A43B0.entries[0].state, i) = 0;
    *slotWord(&gEnemyDataTbl_004A43B0.entries[0].unk20, i) = 0;
    data->dataHandle = 0;
    data->registered = 1;
    data->slotNumber = i + 1;
}
