#include "common.h"
#include "game/data.h"
#include "game/save.h"
typedef struct { u8 p[0x3C0]; s32 x3C0; s32 x3C4; u8 q[0x38]; } S_SaveSys_GetSlotCount_0_001E5E80;
typedef struct { s32 x0; s32 x4; s32 x8; s32 pC[3]; s32 x18; s32 x1C; s32 x20; u8 p24[0x1C]; u8 x40[0x3C0]; } S_SaveSys_StartRead_0_001E5F30;
typedef struct { int a, b, c; char pad[0x400 - 12]; } Rec;
typedef struct { s32 a; s32 b; char pad[0x3F8]; } R;
typedef struct { s32 a; s32 b; char rest[0x3F8]; } E;
typedef struct { s32 x0; s32 x4; s32 x8; s32 pC[3]; s32 x18; s32 x1C; u8 pad[0x3A0]; s32 x3C0; u8 q[0x3C]; } S_SaveSys_StartWrite_0_001E6170;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; u8 pad[0x3A0]; s32 x3C0; u8 pad2[0x3C]; } S_SaveSys_StartLoad_0_001E62A0;
typedef struct { s32 x0; s32 x4; s32 x8; s32 pC[3]; s32 x18; s32 x1C; u8 pad[0x3E0]; } S_SaveSys_StartFormat_0_001E6410;
extern S_SaveSys_GetSlotCount_0_001E5E80 gSaveSystemStepBss_004BC380[];
extern s32 gSaveSystemStartSbss_002023DC;
extern Rec gSaveSystemStepBss_004BC394[];
extern R gSaveSystemStepBss_004BC384[];
s32 SaveSys_GetSlotCount_0_001E5E80(s32 *o);
s32 SaveSys_StartRead_0_001E5F30(u8 **arg0, s32 *arg1);
s32 SaveSys_GetResult_0_001E6080(int *third);
s32 SaveSys_StartWrite_0_001E6170(s32 arg0, s32 arg1, s32 arg2);
s32 SaveSys_StartLoad_0_001E62A0(s32 a0, s32 a1, s32 a2);
s32 SaveSys_StartFormat_0_001E6410(void);

/* SaveSys_GetSlotCount_0_001E5E80 */
s32 SaveSys_GetSlotCount_0_001E5E80(s32 *o) {
    S_SaveSys_GetSlotCount_0_001E5E80 *s;
    s32 i;
    s32 *a;
    s32 k;
    s32 *b;
    k = gSaveSystemStepSbss_002023E4;
    if (gSaveSystemStartSbss_002023B8 == 0) return -1;
    s = &gSaveSystemStepBss_004BC380[k];
    a = &s->x3C4;
    b = &s->x3C0;
    for (i = 0; i < 12; i++, o++) {
        if ((*a >> i) & 1) *o = 2;
        else if ((*b >> i) & 1) *o = 1;
        else *o = 0;
    }
    return 0;
}

/* SaveSys_StartRead_0_001E5F30 */
#define gSaveSystemStepBss_004BC380 gSaveSystemStepBss_004BC380__as_SaveSys_StartRead_0_001E5F30
extern S_SaveSys_StartRead_0_001E5F30 gSaveSystemStepBss_004BC380__as_SaveSys_StartRead_0_001E5F30[];
static inline s32 st_SaveSys_StartRead_0_001E5F30(void) { if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x4 == 0) return 1; if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 != 0) return 0; return 2; }

s32 SaveSys_StartRead_0_001E5F30(u8 **arg0, s32 *arg1) {
    s32 a = gSaveSystemStartSbss_002023DC != 2; s32 z = st_SaveSys_StartRead_0_001E5F30() == 0; s32 ok;
    ok = gSaveSystemStartSbss_002023B8 && (a || !z);
    if (!ok) return -1;
    gSaveSystemStepSbss_002023D8 = 0;
    gSaveSystemStartSbss_002023DC = 2;
    gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x18 = 2; gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 2;
    if (arg0 != NULL) *arg0 = gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x40;
    if (arg1 != NULL) *arg1 = gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x20;
    return 0;
}
#undef gSaveSystemStepBss_004BC380

/* SaveSys_GetSlotState_0_001E6040 */
/* The first word of 0x400-byte record `index`. */


int SaveSys_GetSlotState_0_001E6040(int index)
{
    return gSaveSystemStepBss_004BC394[index].a;
}

/* SaveSys_GetCurSlotState_0_001E6060 */
/* The first word of the current record (index at 0x2023E4). cf. SaveSys_GetSlotState_0_001E6040. */


int SaveSys_GetCurSlotState_0_001E6060(void)
{
    return gSaveSystemStepBss_004BC394[gSaveSystemStepSbss_002023E4].a;
}

/* SaveSys_GetResult_0_001E6080 */
/* The current record's second word, and its third through `third`. */


int SaveSys_GetResult_0_001E6080(int *third)
{
    int i = gSaveSystemStepSbss_002023E4;

    if (third)
        *third = gSaveSystemStepBss_004BC394[i].c;
    return gSaveSystemStepBss_004BC394[i].b;
}

/* SaveSys_GetCardKind_0_001E60C0 */
s32 SaveSys_GetCardKind_0_001E60C0(s32 i) { s32 r; if (gSaveSystemStepBss_004BC384[i].a == 0) return 1; if (gSaveSystemStepBss_004BC384[i].b) r = 0; else r = 2; return r; }

/* SaveSys_IsCardReady_0_001E6110 */
#define gSaveSystemStepBss_004BC384 gSaveSystemStepBss_004BC384__as_SaveSys_IsCardReady_0_001E6110
extern E gSaveSystemStepBss_004BC384__as_SaveSys_IsCardReady_0_001E6110[];
s32 SaveSys_IsCardReady_0_001E6110(void) {
    s32 r;
    if (gSaveSystemStepBss_004BC384[gSaveSystemStepSbss_002023E4].a == 0) { r = 1; }
    else if (gSaveSystemStepBss_004BC384[gSaveSystemStepSbss_002023E4].b != 0) { r = 0; } else { r = 2; }
    return r;
}
#undef gSaveSystemStepBss_004BC384

/* SaveSys_StartWrite_0_001E6170 */
#define gSaveSystemStepBss_004BC380 gSaveSystemStepBss_004BC380__as_SaveSys_StartWrite_0_001E6170
extern S_SaveSys_StartWrite_0_001E6170 gSaveSystemStepBss_004BC380__as_SaveSys_StartWrite_0_001E6170[];
static inline s32 st_SaveSys_StartWrite_0_001E6170(void) { if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x4 == 0) return 1; if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 != 0) return 0; return 2; }
s32 SaveSys_StartWrite_0_001E6170(s32 arg0, s32 arg1, s32 arg2) {
    s32 a; s32 z; s32 ok;
    if (arg0 < -1 || arg0 > 7) return -3;
    a = gSaveSystemStartSbss_002023DC != 2; z = st_SaveSys_StartWrite_0_001E6170() == 0;
    ok = gSaveSystemStartSbss_002023B8 && (a || !z);
    if (!ok) return -1;
    if (!((gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x3C0 >> (arg0 + 4)) & 1)) return -2;
    gSaveSystemStartSbss_002023D0 = arg1;
    gSaveSystemStepSbss_002023D4 = arg0;
    gSaveSystemStartSbss_002023CC = arg2;
    gSaveSystemStepSbss_002023D8 = 0;
    gSaveSystemStartSbss_002023DC = 6;
    gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x18 = 6; gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 2;
    return 0;
}
#undef gSaveSystemStepBss_004BC380

/* SaveSys_StartLoad_0_001E62A0 */
#define gSaveSystemStepBss_004BC380 gSaveSystemStepBss_004BC380__as_SaveSys_StartLoad_0_001E62A0
extern S_SaveSys_StartLoad_0_001E62A0 gSaveSystemStepBss_004BC380__as_SaveSys_StartLoad_0_001E62A0[];
static inline s32 st_SaveSys_StartLoad_0_001E62A0(void) { if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x4 == 0) return 1; if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 != 0) return 0; return 2; }

s32 SaveSys_StartLoad_0_001E62A0(s32 a0, s32 a1, s32 a2) {
    s32 a; s32 z; s32 ok; s32 n; s32 lim;
    if (a0 < -1 || a0 > 7) return -3;
    a = gSaveSystemStartSbss_002023DC != 2; z = st_SaveSys_StartLoad_0_001E62A0() == 0;
    ok = gSaveSystemStartSbss_002023B8 && (a || !z);
    if (!ok) return -1;
    if (!((gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x3C0 >> (a0 + 4)) & 1)) {
        lim = gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x14;
        n = a2 + 0x800;
        if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].xC == 0) n += 0x15E70;
        if (n >= lim << 10) return -2;
    }
    gSaveSystemStartSbss_002023D0 = a1;
    gSaveSystemStepSbss_002023D4 = a0;
    gSaveSystemStartSbss_002023CC = a2;
    gSaveSystemStepSbss_002023D8 = 0;
    gSaveSystemStartSbss_002023DC = 5;
    gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x18 = 5; gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 2;
    return 0;
}
#undef gSaveSystemStepBss_004BC380

/* SaveSys_StartFormat_0_001E6410 */
#define gSaveSystemStepBss_004BC380 gSaveSystemStepBss_004BC380__as_SaveSys_StartFormat_0_001E6410
extern S_SaveSys_StartFormat_0_001E6410 gSaveSystemStepBss_004BC380__as_SaveSys_StartFormat_0_001E6410[];
static inline s32 st_SaveSys_StartFormat_0_001E6410(void) { if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x4 == 0) return 1; if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 != 0) return 0; return 2; }

s32 SaveSys_StartFormat_0_001E6410(void) {
    s32 a = gSaveSystemStartSbss_002023DC != 2; s32 z = st_SaveSys_StartFormat_0_001E6410() == 0; s32 ok;
    ok = gSaveSystemStartSbss_002023B8 && (a || !z);
    if (!ok) return -1;
    gSaveSystemStepSbss_002023D8 = 0;
    gSaveSystemStartSbss_002023DC = 3;
    gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x18 = 3; gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 2;
    return 0;
}
#undef gSaveSystemStepBss_004BC380

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gSaveSystemStartSbss_002023B8, gSaveSystemStartSbss_002023CC, gSaveSystemStartSbss_002023D0, gSaveSystemStartSbss_002023DC */
s32 gSaveSystemStartSbss_002023B8;
s32 gSaveSystemStartSbss_002023CC;
s32 gSaveSystemStartSbss_002023D0;
s32 gSaveSystemStartSbss_002023DC;
#endif
