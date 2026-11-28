#include "m2c.h"
#include "actor.h"
#include "game/gfx.h"
#include "game/data.h"
typedef struct { u8 lo:3; u8 :1; u8 hi:3; u8 :1; } B8;
typedef struct {
    s32 x0;
    u8 pad4[0xC];
    s32 x10;
    s32 x14;
    s16 x18;
    u8 x1A;
    u8 x1B;
    u8 pad1C[8];
    s16 x24;
    u8 pad26[0xA];
    f32 x30;
    u8 pad34[0x7C];
    u8 xB0[0x20];
    u8 xD0[0x1C];
    u8 xEC;
    u8 padED[3];
    Vec xF0;
    Vec x100;
    Vec x110;
    s32 x120;
    s32 x124;
    u8 pad128[8];
    f32 x130[4];
    u8 pad140[0x580];
    s32 x6C0;
    u8 pad6C4[4];
    Flags8 x6C8;
    u8 pad6C9[0x47];
} G;
extern M2C_UNK D_002F1AA0[];
extern M2C_UNK D_002F1AB0[];
extern M2C_UNK D_002F1AC0[];
extern f32 D_002F1AD0[];
extern u8 D_002F2078[];
extern G D_002F19B0;
extern B8 D_00201F78[8];
M2C_UNK sceVu0InterVector(f32, M2C_UNK *, M2C_UNK *, M2C_UNK *);
M2C_UNK sceVu0CopyVector(void *, void *);
M2C_UNK Weather_Update_0_00157D50(f32);
void memset(void *, s32, s32);
void Weather_RespawnParticle_0_00157FE0(s32);

/* ScreenFx_Update_1_00159970 */
#define sceVu0CopyVector sceVu0CopyVector__as_ScreenFx_Update_1_00159970
M2C_UNK sceVu0CopyVector__as_ScreenFx_Update_1_00159970(M2C_UNK *, M2C_UNK *);
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14], gap at: 0x8. */

void ScreenFx_Update_1_00159970(f32 arg0) {
    f32 temp_f1;

    temp_f1 = D_002F1AD0[0] + arg0;
    D_002F1AD0[0] = temp_f1;
    if (!(temp_f1 <= D_002F1AD4[0])) {
        D_002F1AD4[0] = 0.0f;
    }
    if (D_002F1AD4[0] == 0.0f) {
        sceVu0CopyVector(D_002F1AA0, D_002F1AB0);
    } else {
        sceVu0InterVector(1.0f - (D_002F1AD0[0] / D_002F1AD4[0]), D_002F1AA0, D_002F1AC0, D_002F1AB0);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x39) >> 0x3F) != 0) {
        Weather_Update_0_00157D50(arg0);
    }
}
#undef sceVu0CopyVector

/* ScreenFx_Init_1_00159A60 */
#define sceVu0CopyVector sceVu0CopyVector__as_ScreenFx_Init_1_00159A60
void sceVu0CopyVector__as_ScreenFx_Init_1_00159A60(Vec *, Vec *);

void ScreenFx_Init_1_00159A60(void) {
    Vec v;
    memset(&D_002F19B0, 0, 0x710);
    D_002F19B0.x18 = 0;
    D_002F19B0.x0 = 5;
    D_002F19B0.x6C8.f.b3 = 1;
    D_002F19B0.x30 = 1000.0f;
    D_002F19B0.x24 = 1;
    D_002F19B0.x1A = 0x40;
    D_002F19B0.x1B = 0x28;
    D_002F19B0.x10 = -8;
    D_002F19B0.x14 = -8;
    ScreenFx_InitEntry_0_00159480(D_002F19B0.xB0);
    ScreenFx_InitEntry_0_00159480(D_002F19B0.xD0);
    D_002F19B0.xEC = 1;
    sceVu0CopyVector(&v, &D_003139A0);
    v.w = 128.0f;
    sceVu0CopyVector(&D_002F19B0.xF0, &v);
    sceVu0CopyVector(&D_002F19B0.x100, &v);
    sceVu0CopyVector(&D_002F19B0.x110, &v);
    D_002F19B0.x120 = 0;
    D_002F19B0.x124 = 0;
    D_00201F78[0].lo = 4;
    D_00201F78[0].hi = 2;
    D_00201F78[1].lo = 5;
    D_00201F78[1].hi = 3;
    D_00201F78[2].lo = 0;
    D_00201F78[2].hi = 6;
    D_00201F78[3].lo = 1;
    D_00201F78[3].hi = 7;
    D_00201F78[4].lo = 5;
    D_00201F78[4].hi = 3;
    D_00201F78[5].lo = 4;
    D_00201F78[5].hi = 2;
    D_00201F78[6].lo = 1;
    D_00201F78[6].hi = 7;
    D_00201F78[7].lo = 0;
    D_00201F78[7].hi = 6;
    Weather_RespawnParticle_0_00157FE0(0);
    Weather_RespawnParticle_0_00157FE0(1);
    D_002F19B0.x6C0 = 0;
    D_002F19B0.x6C8.f.b6 = 0;
    { f32 *p = D_002F19B0.x130;
    p[0] = 0.5f;
    p[1] = 0.635f;
    p[2] = 0.5f;
    p[3] = 1.0f; }
}
#undef sceVu0CopyVector

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F78 */
B8 D_00201F78[8];
#endif
