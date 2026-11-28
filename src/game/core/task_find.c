#include "game/core.h"
#include "game/data.h"

struct TaskRecord {
    u8 state;
    u8 nextState;
    u8 pad02[0xA];
    s16 id;
    s16 priority;
    s32 x10;
    s32 x14;
    s32 x18;
};

extern s32 (*gTaskCallbackBss_004BAC20[])(struct TaskRecord *, s32);
extern u8 *gTaskCallbackBss_004BAC30[];
extern s32 gTaskCallbackBss_004BAC34[];
extern u32 gTaskCallbackBss_004BAC38[];

struct TaskRecord *Task_Find_0_001E02C0(s32 arg, s16 id, s32 value)
{
    s32 i;
    struct TaskRecord *record;
    s32 accepted;

    record = NULL;
    for (i = 0; i < gTaskCallbackBss_004BAC38[0]; i++) {
        record = (struct TaskRecord *)((u32)gTaskCallbackBss_004BAC30[0] +
                                       (u32)gTaskCallbackBss_004BAC34[0] * i);
        if (record->state == 0) {
            record->x14 = value;
            if (gTaskCallbackBss_004BAC20[0] != NULL) {
                accepted = gTaskCallbackBss_004BAC20[0](record, arg);
            } else {
                accepted = 0;
            }
            if (accepted == 0) {
                record = NULL;
            } else {
                record->state = 2;
                record->nextState = 2;
                record->id = id;
                record->priority = 0;
                record->x14 = value;
                record->x10 = value;
                record->x18 = gTaskCallbackBss_004BAC48[0];
            }
            break;
        }
        record = NULL;
    }
    return record;
}
