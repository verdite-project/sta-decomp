#include "m2c.h"
typedef struct { s32 x0; u8 pad[0x1D4]; u8 f1D8; } Inner;
typedef struct { u8 pad[0x40]; f32 v40[4]; f32 v50[4]; u8 p60[0x3C]; s16 x9C; } E;
typedef struct { s32 x0; s16 n[2]; E *e[2][16]; } G;
extern Inner **gMapSbss_00201E80[2];
extern G gItemObjectSpawnBss_004AC5A0;
void MapState_OffsetObjects_0_001A9810(s32);
void MapState_SetObjectPos_0_001A9A20(s32, s32, s16, f32 *, f32 *);

void ItemObj_SaveState_1_001AE510(void) {
    Inner *p;
    s32 j;
    s32 i;
    Inner ***q;

    q = &gMapSbss_00201E80[2];
    for (i = 0; i < 2; i++) {
        if (q[i] != NULL && (p = *q[i]) != NULL && (p->f1D8 & 1)) {
            MapState_OffsetObjects_0_001A9810(p->x0);
            for (j = 0; j < gItemObjectSpawnBss_004AC5A0.n[i]; j++) {
                if (gItemObjectSpawnBss_004AC5A0.e[i][j]->x9C != -1) {
                    MapState_SetObjectPos_0_001A9A20(p->x0, j, gItemObjectSpawnBss_004AC5A0.e[i][j]->x9C, gItemObjectSpawnBss_004AC5A0.e[i][j]->v40, gItemObjectSpawnBss_004AC5A0.e[i][j]->v50);
                }
            }
        }
    }
}
