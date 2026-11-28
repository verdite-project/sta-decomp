#include "m2c.h"
typedef struct { s32 a; s32 b; s32 c; } V3 __attribute__((aligned(8)));
typedef struct { u8 pad[6]; s16 h6; u8 pad2[2]; s32 w0C; } Z;
s32 Arc_FindByHash_2_0015ABD0(s32);
s32 File_GetSectorOrSize_0_0015A300(s32);
s32 File_GetOffset_0_0015A350(s32);
void File_Close_2_0015AB80(s32);
void Arc_LoadFileTo_1_0015A080(s32, s8 *, s32);
void sceVu0Normalize(void *, void *);
void memset(void *, s32, s32);
void strcpy(s8 *, s8 *);
void memcpy(void *, void *, s32);
void SaveSys_Init_1_001E85E0(s32, s32, void *, s8 *, s32);
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s8 D_00209700[0x470];
#ifndef NONMATCHING
extern s8 gGameSaveRodata_001FAAE8[];
#else
/* data twins (src/game/data/game_save_rodata.c): gGameSaveRodata_001FAAE8 */
static s8 gGameSaveRodata_001FAAE8[0xe] = "sta_abyss.ico\000";
#endif

s32 D_001F1AF0[0x10] = { 0, 0, 0, 0, 8, 0x40, 0x20, 0 };
f32 D_001F1B30[0xC] = { 0.5f, 0.0f, 0.2f };
f32 D_001F1B60[0xC] = { 0.2509804f, 0.5019608f, 0.39215687f };
f32 D_001F1B90[4] = { 0.0627451f, 0.0627451f, 0.0627451f, 0.0f };
V3 D_001F1BA0 = { (s32)gGameSaveRodata_001FAAE8, (s32)gGameSaveRodata_001FAAE8, (s32)gGameSaveRodata_001FAAE8 };
#ifndef NONMATCHING
extern s8 gGameSaveRodata_001FAAF8[];
#else
/* data twins (src/game/data/game_save_rodata.c): gGameSaveRodata_001FAAF8 */
static s8 gGameSaveRodata_001FAAF8[0x5] = "PS2D\000";
#endif
#ifndef NONMATCHING
extern s8 gGameSaveRodata_001FAB00[];
#else
/* data twins (src/game/data/game_save_rodata.c): gGameSaveRodata_001FAB00 */
static s8 gGameSaveRodata_001FAB00[0x20] __attribute__((aligned(8))) = { -0x7d, 0x56, -0x7d, -0x7d, -0x7d, 0x68, -0x7d, 0x45, -0x7d, 0x5e, -0x7d, -0x71, -0x7f, 0x5b, -0x7d, 0x41, -0x7d, 0x72, -0x7d, 0x58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

void Game_InitSaveIcon_1_00128D10(void) {
    V3 v;
    u8 buf[0x3C4];
    s32 a; s32 h; s32 b;
    h = Arc_FindByHash_2_0015ABD0(0x943CDF5F);
    a = File_GetSectorOrSize_0_0015A300(h);
    b = File_GetOffset_0_0015A350(h);
    File_Close_2_0015AB80(h);
    Arc_LoadFileTo_1_0015A080(0x943CDF5F, D_00209700, a);
    v = D_001F1BA0;
    sceVu0Normalize(D_001F1B30, D_001F1B30);
    memset(buf, 0, 0x3C4);
    strcpy(buf, gGameSaveRodata_001FAAF8);
    strcpy(buf + 0xC0, gGameSaveRodata_001FAB00);
    *(s16 *)(buf + 6) = 0xE;
    *(s32 *)(buf + 0xC) = 0x60;
    memcpy(buf + 0x10, D_001F1AF0, 0x40);
    memcpy(buf + 0x50, D_001F1B30, 0x30);
    memcpy(buf + 0x80, D_001F1B60, 0x30);
    memcpy(buf + 0xB0, D_001F1B90, 0x10);
    strcpy(buf + 0x104, (s8 *)v.a);
    strcpy(buf + 0x144, (s8 *)v.b);
    strcpy(buf + 0x184, (s8 *)v.c);
    SaveSys_Init_1_001E85E0(0, 0, buf, D_00209700, b);
}
