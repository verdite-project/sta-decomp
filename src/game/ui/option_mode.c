#include "common.h"
#include "game/ui.h"
extern u8 *D_00201E10;
u8 Option_GetMoveEffect_2_001A9440(void);
u8 Option_GetSeVolume_1_001A9480(void);
void Option_Load_1_001A94B0(s32 arg0);
void memcpy(s32, s32, s32);

/* Option_GetSoundMode_0_001A9430 */
u8 Option_GetSoundMode_0_001A9430(void) {
    return *D_00201E10;
}

/* Option_GetMoveEffect_2_001A9440 */
#define D_00201E10 D_00201E10__as_Option_GetMoveEffect_2_001A9440
extern void *D_00201E10__as_Option_GetMoveEffect_2_001A9440;

u8 Option_GetMoveEffect_2_001A9440(void) {
    return M2C_FIELD(D_00201E10, u8 *, 8);
}
#undef D_00201E10

/* Option_GetControlType_1_001A9450 */
#define D_00201E10 D_00201E10__as_Option_GetControlType_1_001A9450
extern void *D_00201E10__as_Option_GetControlType_1_001A9450;

u8 Option_GetControlType_1_001A9450(void) {
    return M2C_FIELD(D_00201E10, u8 *, 7);
}
#undef D_00201E10

/* Option_GetOutputMode_0_001A9460 */
#define D_00201E10 D_00201E10__as_Option_GetOutputMode_0_001A9460
extern void *D_00201E10__as_Option_GetOutputMode_0_001A9460;

u8 Option_GetOutputMode_0_001A9460(void) {
    return M2C_FIELD(D_00201E10, u8 *, 1);
}
#undef D_00201E10

/* Option_GetBgmVolume_1_001A9470 */
#define D_00201E10 D_00201E10__as_Option_GetBgmVolume_1_001A9470
extern void *D_00201E10__as_Option_GetBgmVolume_1_001A9470;

u8 Option_GetBgmVolume_1_001A9470(void) {
    return M2C_FIELD(D_00201E10, u8 *, 5);
}
#undef D_00201E10

/* Option_GetSeVolume_1_001A9480 */
#define D_00201E10 D_00201E10__as_Option_GetSeVolume_1_001A9480
extern void *D_00201E10__as_Option_GetSeVolume_1_001A9480;

u8 Option_GetSeVolume_1_001A9480(void) {
    return M2C_FIELD(D_00201E10, u8 *, 4);
}
#undef D_00201E10

/* Option_GetByte3_0_001A9490 */
#define D_00201E10 D_00201E10__as_Option_GetByte3_0_001A9490
extern void *D_00201E10__as_Option_GetByte3_0_001A9490;

u8 Option_GetByte3_0_001A9490(void) {
    return M2C_FIELD(D_00201E10, u8 *, 3);
}
#undef D_00201E10

/* Option_GetByte2_0_001A94A0 */
#define D_00201E10 D_00201E10__as_Option_GetByte2_0_001A94A0
extern void *D_00201E10__as_Option_GetByte2_0_001A94A0;

u8 Option_GetByte2_0_001A94A0(void) {
    return M2C_FIELD(D_00201E10, u8 *, 2);
}
#undef D_00201E10

/* Option_Load_1_001A94B0 */
#define D_00201E10 D_00201E10__as_Option_Load_1_001A94B0
extern s32 D_00201E10__as_Option_Load_1_001A94B0;

void Option_Load_1_001A94B0(s32 arg0) {
    if (arg0 != 0) {
        memcpy(D_00201E10, arg0, 0x10);
    }
}
#undef D_00201E10

/* Option_Store_1_001A94E0 */
#define D_00201E10 D_00201E10__as_Option_Store_1_001A94E0
extern s32 D_00201E10__as_Option_Store_1_001A94E0;
#define memcpy memcpy__as_Option_Store_1_001A94E0
void memcpy__as_Option_Store_1_001A94E0(void *p, s32 v, s32 n);

void Option_Store_1_001A94E0(void *p)
{
    if (p)
        memcpy(p, D_00201E10, 0x10);
}
#undef memcpy
#undef D_00201E10

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_004A48A0[];
/* data twins (src/game/data/sdata.c): D_00201E10 */
u8 *D_00201E10 = (u8 *)D_004A48A0;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/save_options_bss.c): D_004A48A0 */
u8 D_004A48A0[0xe0];
#endif
