#include "m2c.h"
#include "game/gfx.h"
#include "game/data.h"
#include "game/core.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_ScreenFx_DrawFlash_0_00156AF0;
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_ScreenFx_DrawDistort_0_00156CE0;
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_ScreenFx_DrawFade_0_00156F60;
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q_ScreenFx_DrawBars_0_00157110;
void ScreenFx_DrawFlash_0_00156AF0(void);
void ScreenFx_DrawDistort_0_00156CE0(void);
void ScreenFx_DrawFade_0_00156F60(void);
void GsPkt_SetReg_3_001543E0(s32, u64);
Q_ScreenFx_DrawFlash_0_00156AF0* GsPkt_Alloc_3_00154A80(s32);
u64 __fixunssfdi(f32);

/* ScreenFx_DrawFlash_0_00156AF0 */
static inline s32 wd_ScreenFx_DrawFlash_0_00156AF0(void) { return gSfxAllSbss_00201F2C ? 0 : 0x1180; }

void ScreenFx_DrawFlash_0_00156AF0(void) {
    Q_ScreenFx_DrawFlash_0_00156AF0 q;
    Q_ScreenFx_DrawFlash_0_00156AF0 *p;
    f32 f;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd_ScreenFx_DrawFlash_0_00156AF0() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
    f = gGameMainSbss_00201E90;
    GsPkt_SetReg_3_001543E0(0x40, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_SetReg_3_001543E0(6, 0xA8016BC0 | ((u64)0xA << 32));
    GsPkt_SetReg_3_001543E0(0x14, 0x60);
    GsPkt_SetReg_3_001543E0(1, 5);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(6);
    q.q = 0;
    q.w[0] = 0x10000005;
    q.w[3] = 0x50000005;
    p[0].q = q.q;
    q.d[0] = ((u64)0x408B4000 << 32) | 0x8001;
    q.d[1] = 0x5353;
    p[1].q = q.q;
    q.w[0] = 0;
    q.w[1] = 0;
    q.d[1] = 0;
    p[2].q = q.q;
    q.w[0] = 0x6BF0;
    q.w[1] = 0x71F0;
    q.w[2] = 0;
    q.w[3] = 0;
    p[3].q = q.q;
    q.w[0] = 0x1400;
    q.w[1] = 0xE00;
    q.d[1] = 0;
    p[4].q = q.q;
    q.w[0] = 0x9410;
    q.w[1] = 0x8E10;
    q.w[2] = 0;
    q.w[3] = 0;
    p[5].q = q.q;
    GsPkt_Commit_1_00154A70();
    Tex_FlushAll_1_00176AE0();
}

/* ScreenFx_DrawDistort_0_00156CE0 */
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawDistort_0_00156CE0
extern Q_ScreenFx_DrawDistort_0_00156CE0 *GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawDistort_0_00156CE0(s32);
static inline s32 wd_ScreenFx_DrawDistort_0_00156CE0(void) { return gSfxAllSbss_00201F2C ? 0 : 0x1180; }

void ScreenFx_DrawDistort_0_00156CE0(void) {
    Q_ScreenFx_DrawDistort_0_00156CE0 q;
    Q_ScreenFx_DrawDistort_0_00156CE0 *p;
    f32 f;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x3F, 0xFFFFFFFF);
    GsPkt_SetReg_3_001543E0(0x4C, 0x5015E);
    GsPkt_SetReg_3_001543E0(0x4E, ((u64)1 << 32) | 0x3A00015E);
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_SetReg_3_001543E0(0x40, ((u64)0xDF0000 << 32) | 0x13F0000);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(9);
    q.q = 0;
    q.w[0] = 0x10000008;
    q.w[3] = 0x50000008;
    p[0].q = q.q;
    q.d[0] = ((u64)0x708B4000 << 32) | 0x8001;
    q.d[1] = 0x53538E6;
    p[1].q = q.q;
    q.d[0] = ((u64)0xA << 32) | 0xA8028000 | (s64)wd_ScreenFx_DrawDistort_0_00156CE0();
    q.d[1] = 0;
    p[2].q = q.q;
    q.d[0] = 0;
    q.d[1] = 0x14;
    p[3].q = q.q;
    q.d[0] = 5;
    q.d[1] = 0;
    p[4].q = q.q;
    q.w[0] = 0;
    q.w[1] = 0;
    q.d[1] = 0;
    p[5].q = q.q;
    q.w[0] = 0x6BF0;
    q.w[1] = 0x71F0;
    q.w[2] = 0;
    q.w[3] = 0;
    p[6].q = q.q;
    q.w[0] = 0x2810;
    q.w[1] = 0x1C10;
    q.d[1] = 0;
    p[7].q = q.q;
    q.w[0] = 0x8000;
    q.w[1] = 0x8000;
    q.w[2] = 0;
    q.w[3] = 0;
    p[8].q = q.q;
    GsPkt_Commit_1_00154A70();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd_ScreenFx_DrawDistort_0_00156CE0() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
    f = gGameMainSbss_00201E90;
    GsPkt_SetReg_3_001543E0(0x40, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
}
#undef GsPkt_Alloc_3_00154A80

/* ScreenFx_DrawFade_0_00156F60 */
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawFade_0_00156F60
extern Q_ScreenFx_DrawFade_0_00156F60 *GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawFade_0_00156F60(s32);
static inline s32 wd_ScreenFx_DrawFade_0_00156F60(void) { return gSfxAllSbss_00201F2C ? 0 : 0x1180; }

void ScreenFx_DrawFade_0_00156F60(void) {
    Q_ScreenFx_DrawFade_0_00156F60 q;
    Q_ScreenFx_DrawFade_0_00156F60 *p;
    if (D_00222A10[0] == 2) {
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd_ScreenFx_DrawFade_0_00156F60() / 32) | 0xA0000);
        GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
        GsPkt_SetReg_3_001543E0(0x40, 0x027F0000 | ((s64)0x01BF0000 << 32));
        GsPkt_SetReg_3_001543E0(0x47, 0x31001);
        GsPkt_EndAD_3_00154420();
        p = GsPkt_Alloc_3_00154A80(7);
        q.q = 0;
        q.w[0] = 0x10000006;
        q.w[3] = 0x50000006;
        p[0].q = q.q;
        q.d[0] = ((u64)0x50834000 << 32) | 0x8001;
        q.d[1] = 0x55551;
        p[1].q = q.q;
        q.w[0] = 0;
        q.w[1] = 0;
        q.w[2] = 0;
        q.w[3] = 0;
        p[2].q = q.q;
        q.w[0] = 0x6C00;
        q.w[1] = 0x7200;
        q.w[2] = 0;
        q.w[3] = 0;
        p[3].q = q.q;
        q.w[0] = 0x9400;
        q.w[1] = 0x74C0;
        q.w[2] = 0;
        q.w[3] = 0;
        p[4].q = q.q;
        q.w[0] = 0x6C00;
        q.w[1] = 0x8B40;
        q.w[2] = 0;
        q.w[3] = 0;
        p[5].q = q.q;
        q.w[0] = 0x9400;
        q.w[1] = 0x8E00;
        q.w[2] = 0;
        q.w[3] = 0;
        p[6].q = q.q;
        GsPkt_Commit_1_00154A70();
        Tex_FlushAll_1_00176AE0();
    }
}
#undef GsPkt_Alloc_3_00154A80

/* ScreenFx_DrawBars_0_00157110 */
#define GsPkt_SetReg_3_001543E0 GsPkt_SetReg_3_001543E0__as_ScreenFx_DrawBars_0_00157110
void GsPkt_SetReg_3_001543E0__as_ScreenFx_DrawBars_0_00157110(s32, s64);
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawBars_0_00157110
s32 GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawBars_0_00157110(s32);

void ScreenFx_DrawBars_0_00157110(u8 a0) {
    Q_ScreenFx_DrawBars_0_00157110 *p;
    Q_ScreenFx_DrawBars_0_00157110 q;
    u16 x;
    if (a0 != 0x80) {
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x4C, (s64)((gSfxAllSbss_00201F2C ? 0 : 0x1180) / 32) | 0xA0000);
        GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
        GsPkt_SetReg_3_001543E0(0x40, 0x027F0000 | ((s64)0x01BF0000 << 32));
        GsPkt_SetReg_3_001543E0(0x47, 0x31001);
        if (a0 > 0x80) {
            GsPkt_SetReg_3_001543E0(0x42, 0x49 | ((s64)0x80 << 32));
        } else {
            GsPkt_SetReg_3_001543E0(0x42, 0x46 | ((s64)0x80 << 32));
        }
        GsPkt_EndAD_3_00154420();
        p = (Q_ScreenFx_DrawBars_0_00157110 *)GsPkt_Alloc_3_00154A80(0x20);
        q.q = 0;
        q.w[0] = 0x1000001F;
        q.w[3] = 0x5000001F;
        p[0].q = q.q;
        q.d[0] = 0x800A | ((u64)0x30A34000 << 32);
        q.d[1] = 0x551;
        p[1].q = q.q;
        p += 2;
        x = 0;
        do {
            q.w[0] = 0;
            q.w[1] = 0;
            q.w[2] = 0;
            q.w[3] = (a0 > 0x80) ? a0 - 0x80 : 0x80 - a0;
            p[0].q = q.q;
            q.w[0] = (x + 0x6C0) << 4;
            q.w[1] = 0x7200;
            q.w[2] = 0;
            q.w[3] = 0;
            p[1].q = q.q;
            q.w[0] = (x + 0x700) << 4;
            q.w[1] = 0x8E00;
            q.w[2] = 0;
            q.w[3] = 0;
            p[2].q = q.q;
            x += 0x40;
            p += 3;
        } while (x < 0x280);
        GsPkt_Commit_1_00154A70();
        Tex_FlushAll_1_00176AE0();
    }
}
#undef GsPkt_SetReg_3_001543E0
#undef GsPkt_Alloc_3_00154A80
