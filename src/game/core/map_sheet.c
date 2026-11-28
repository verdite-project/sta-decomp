#include "common.h"
#include "game/core.h"
#include "game/ui.h"
typedef union { u32 w; u8 b[4]; } Buf;
typedef struct {
    u8 pad0[0x14];
    f32 x14;
    f32 x18;
    u8 pad1C[0x10];
    f32 x2C;
    f32 x30;
    u8 pad34[0x8];
    union { u32 w; u8 b[4]; } c;
} S_MapSheet_Draw_0_001ED630;
typedef struct { s32 x0; s32 x4; s8 x8; s8 p9[3]; s8 xC; } S_MapSheet_Update_0_001ED740;
#ifndef NONMATCHING
extern s32 D_00201E78;
#else
/* data twins (src/game/data/sdata.c): D_00201E78 */
static s32 D_00201E78 = -1;
#endif
extern S_MapSheet_Draw_0_001ED630 D_004BE0E0;
extern s32 D_001F27B0[];
extern s32 D_001F27C0[];
#ifndef NONMATCHING
extern f32 D_00202404;
#else
/* data twins (src/game/data/sbss.c): D_00202404 */
static f32 D_00202404;
#endif
void MapSheet_Update_0_001ED740(S_MapSheet_Update_0_001ED740 *a);
void Menu_SetSubMode_0_0018A330(s32);
void Ui_DrawSpriteRotated_1_00182080(f32, s32, void *, void *, void *, s32);
void Ui_DrawWindow_0_00183650(void *);

/* MapSheet_Open_0_001ED620 */
void MapSheet_Open_0_001ED620(s32 arg0) {
    D_00201E78 = arg0;
    Menu_SetSubMode_0_0018A330(0x11);
}

/* MapSheet_Draw_0_001ED630 */
void MapSheet_Draw_0_001ED630(void) {
    Buf s;
    s.w = 0;
    s.b[3] = (s32)D_00202404 / 2.0f;
    Ui_DrawSpriteRotated_1_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
    Ui_BeginSprites_1_00181420();
    D_004BE0E0.x2C = 150.0f;
    D_004BE0E0.x30 = 50.0f;
    D_004BE0E0.x14 = 1.34f;
    D_004BE0E0.x18 = 1.3f;
    D_004BE0E0.c.w = 0x80FFFFFF;
    D_004BE0E0.c.b[3] = (s32)D_00202404;
    Ui_DrawWindow_0_00183650(&D_004BE0E0);
}

/* MapSheet_Update_0_001ED740 */
void MapSheet_Update_0_001ED740(S_MapSheet_Update_0_001ED740 *a) {
    Ui_LoadMapSheet_3_00183750(D_00201E78);
    a->xC = -0x11;
    if (a->x0 == 0x19) D_00202404 = 0.0f;
    if (a->x0 == 0x1E) a->xC = 0;
    if (a->x0 == 0x1C) {
        D_00202404 -= 8.0f;
        if (D_00202404 < 0.0f) D_00202404 = 0.0f;
    }
    if (a->x0 == 0x16) {
        D_00202404 += 8.0f;
        if (D_00202404 > 128.0f) D_00202404 = 128.0f;
        if ((a->x4 & 0x4000) || (a->x4 & 0x2000)) {
            a->x8 = 0x12;
            a->x4 = 0;
            a->x0 = 0x1A;
        }
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/movie_bss.c): D_004BE0E0__grp: D_004BE0E0@0x0, D_004BE0F4@0x14, D_004BE10C@0x2c, D_004BE110@0x30, D_004BE11C@0x3c */
u8 D_004BE0E0__grp[0x40] __attribute__((aligned(16)));
#endif
