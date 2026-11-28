#include "common.h"
typedef struct { char b[8]; } E;
typedef struct { char pad[0x5C00]; E e[0x400]; } S;
extern S *gPlayerData_00201DC0;
static inline E *get(s16 i) { if (0 > i || i >= 0x400) return NULL; return &gPlayerData_00201DC0->e[i]; }
void Item_ClearNewFlag_0_001A9510(s16 i) {
    u8 *e = (u8 *)get(i);
    if (e != NULL && e[2] != 0) {
        if (e[5] == 1 || e[5] == 3) {
            e[2] = 0; e[0] = 0; e[1] = 0; e[3] = 0; e[4] = 0; e[5] = 0;
        }
    }
}
