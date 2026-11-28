#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/gfx.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_ScreenFx_DrawBlurPasses_0_00131970;
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_ScreenFx_DrawCopy_0_00132190;
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q_ScreenFx_DrawSprite_0_001323C0;
typedef struct { s32 x0; s32 x4; } A0;
typedef struct { f32 x[4]; f32 f10; f32 f14; f32 f18; f32 f1C; } A3;
extern u32 D_00201F00;
extern u32 D_00201EF4;
extern u32 D_00201EF0;
extern u8 D_00201F0C;
void ScreenFx_DrawBlurPasses_0_00131970(s32 w, s32 h, f32 *c);
void ScreenFx_DrawCopy_0_00132190(s32 w, s32 h);
void ScreenFx_DrawSprite_0_001323C0(A0 *a0, u32 a1, u32 a2, A3 *a3);
void ScreenFx_DrawLetterbox_0_001325F0(void);
void ScreenFx_DrawRestore_0_001327B0(void);
void ScreenFx_Draw_0_00132930(s32 arg0);
void GsPkt_SetReg_3_001543E0(s32, u64);
Q_ScreenFx_DrawBlurPasses_0_00131970* GsPkt_Alloc_3_00154A80(s32);
u64 __fixunssfdi(f32);
void memset(s32, s32, s32);

/* ScreenFx_DrawBlurPasses_0_00131970 */
static inline s32 wd_ScreenFx_DrawBlurPasses_0_00131970(void) { return D_00201F2C ? 0 : 0x1180; }

void ScreenFx_DrawBlurPasses_0_00131970(s32 w, s32 h, f32 *c) {
    Q_ScreenFx_DrawBlurPasses_0_00131970 q1;
    Q_ScreenFx_DrawBlurPasses_0_00131970 q2;
    Q_ScreenFx_DrawBlurPasses_0_00131970 q3;
    Q_ScreenFx_DrawBlurPasses_0_00131970 q4;
    Q_ScreenFx_DrawBlurPasses_0_00131970 q5;
    Q_ScreenFx_DrawBlurPasses_0_00131970 *p;
    f32 f;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (u64)D_00201EF4 | ((s64)(s32)((u32)(u16)w >> 6) << 16) | 0xA000000);
    GsPkt_SetReg_3_001543E0(0x4E, (u64)D_00201F00 | 0x3A000000);
    GsPkt_SetReg_3_001543E0(0x47, 0x32001);
    GsPkt_SetReg_3_001543E0(0x40, ((s64)((u16)w - 1) << 16) | ((s64)((u16)h - 1) << 48));
    GsPkt_SetReg_3_001543E0(0x41, ((s64)((u16)w - 1) << 16) | ((s64)((u16)h - 1) << 48));
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(4);
    q1.q = 0;
    q1.w[0] = 0x10000003;
    q1.w[3] = 0x50000003;
    p[0].q = q1.q;
    q1.d[0] = ((u64)0x20034000 << 32) | 0x8001;
    q1.d[1] = 0x55;
    p[1].q = q1.q;
    q1.w[0] = 0x6C00;
    q1.w[1] = 0x7200;
    q1.w[2] = -1;
    q1.w[3] = 0;
    p[2].q = q1.q;
    q1.w[0] = ((u16)w + 0x6C0) << 4;
    q1.w[1] = ((u16)h + 0x720) << 4;
    q1.w[2] = -1;
    q1.w[3] = 0;
    p[3].q = q1.q;
    GsPkt_Commit_1_00154A70();

    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (u64)D_00201F00 | ((s64)(s32)((u32)(u16)w >> 6) << 16) | 0xA000000);
    GsPkt_SetReg_3_001543E0(0x4E, (u64)D_00201EF4 | 0x3A000000);
    GsPkt_SetReg_3_001543E0(0x47, 0x71001);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(5);
    q2.q = 0;
    q2.w[0] = 0x10000004;
    q2.w[3] = 0x50000004;
    p[0].q = q2.q;
    q2.d[0] = ((u64)0x30034000 << 32) | 0x8001;
    q2.d[1] = 0x551;
    p[1].q = q2.q;
    q2.w[0] = 0;
    q2.w[1] = 0;
    q2.w[2] = 0;
    q2.w[3] = 0;
    p[2].q = q2.q;
    q2.w[0] = 0x6C00;
    q2.w[1] = 0x7200;
    q2.w[2] = 0x7400;
    q2.w[3] = 0;
    p[3].q = q2.q;
    q2.w[0] = ((u16)w + 0x6C0) << 4;
    q2.w[1] = ((u16)h + 0x720) << 4;
    q2.w[2] = 0x7400;
    q2.w[3] = 0;
    p[4].q = q2.q;
    GsPkt_Commit_1_00154A70();

    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (u64)D_00201EF4 | ((s64)(s32)((u32)(u16)w >> 6) << 16) | 0xA000000);
    GsPkt_SetReg_3_001543E0(0x4E, (u64)D_00201F00 | 0x3A000000);
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(5);
    q3.q = 0;
    q3.w[0] = 0x10000004;
    q3.w[3] = 0x50000004;
    p[0].q = q3.q;
    q3.d[0] = ((u64)0x30034000 << 32) | 0x8001;
    q3.d[1] = 0x551;
    p[1].q = q3.q;
    q3.w[0] = 0;
    q3.w[1] = 0;
    q3.w[2] = 0;
    q3.w[3] = 0;
    p[2].q = q3.q;
    q3.w[0] = 0x6C00;
    q3.w[1] = 0x7200;
    q3.w[2] = 0;
    q3.w[3] = 0;
    p[3].q = q3.q;
    q3.w[0] = ((u16)w + 0x6C0) << 4;
    q3.w[1] = ((u16)h + 0x720) << 4;
    q3.w[2] = 0;
    q3.w[3] = 0;
    p[4].q = q3.q;
    GsPkt_Commit_1_00154A70();

    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (u64)D_00201EF4 | ((s64)(s32)((u32)(u16)w >> 6) << 16) | 0xA000000);
    GsPkt_SetReg_3_001543E0(0x4E, (u64)D_00201F00 | 0x3A000000);
    GsPkt_SetReg_3_001543E0(0x47, 0x71001);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(5);
    q4.q = 0;
    q4.w[0] = 0x10000004;
    q4.w[3] = 0x50000004;
    p[0].q = q4.q;
    q4.d[0] = ((u64)0x30034000 << 32) | 0x8001;
    q4.d[1] = 0x551;
    p[1].q = q4.q;
    q4.w[0] = 0xFF;
    q4.w[1] = 0xFF;
    q4.w[2] = 0xFF;
    q4.w[3] = 0xFF;
    p[2].q = q4.q;
    q4.w[0] = 0x6C00;
    q4.w[1] = 0x7200;
    q4.w[2] = 0x3C00;
    q4.w[3] = 0;
    p[3].q = q4.q;
    q4.w[0] = ((u16)w + 0x6C0) << 4;
    q4.w[1] = ((u16)h + 0x720) << 4;
    q4.w[2] = 0x3C00;
    q4.w[3] = 0;
    p[4].q = q4.q;
    GsPkt_Commit_1_00154A70();

    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd_ScreenFx_DrawBlurPasses_0_00131970() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
    f = D_00201E90;
    GsPkt_SetReg_3_001543E0(0x40, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_SetReg_3_001543E0(0x42, ((u64)0x80 << 32) | 0x44);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(10);
    q5.q = 0;
    q5.w[0] = 0x10000009;
    q5.w[3] = 0x50000009;
    p[0].q = q5.q;
    q5.d[0] = ((u64)0x80AB4000 << 32) | 0x8001;
    q5.d[1] = 0x535318E6;
    p[1].q = q5.q;
    q5.d[0] = (u64)D_00201EF0 | ((s64)(s32)((u32)(u16)w >> 6) << 14) | (((u64)6 << 32) | 0xA8A00000);
    q5.d[1] = 0;
    p[2].q = q5.q;
    q5.d[0] = 0x60;
    q5.d[1] = 0x14;
    p[3].q = q5.q;
    q5.d[0] = 5;
    q5.d[1] = 0;
    p[4].q = q5.q;
    q5.w[0] = 255.0f * c[0];
    q5.w[1] = 255.0f * c[1];
    q5.w[2] = 255.0f * c[2];
    q5.w[3] = 128.0f * c[3];
    p[5].q = q5.q;
    q5.w[0] = 8;
    q5.w[1] = 8;
    q5.d[1] = 0;
    p[6].q = q5.q;
    q5.w[0] = 0x6C00;
    q5.w[1] = 0x7200;
    q5.w[2] = 0;
    q5.w[3] = 0;
    p[7].q = q5.q;
    q5.w[0] = (u16)w << 4;
    q5.w[1] = (u16)h << 4;
    q5.d[1] = 0;
    p[8].q = q5.q;
    q5.w[0] = 0x93F0;
    q5.w[1] = 0x8DF0;
    q5.w[2] = 0;
    q5.w[3] = 0;
    p[9].q = q5.q;
    GsPkt_Commit_1_00154A70();
    Tex_FlushAll_1_00176AE0();
}

/* ScreenFx_DrawCopy_0_00132190 */
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawCopy_0_00132190
extern Q_ScreenFx_DrawCopy_0_00132190 *GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawCopy_0_00132190(s32);

void ScreenFx_DrawCopy_0_00132190(s32 w, s32 h) {
    Q_ScreenFx_DrawCopy_0_00132190 q;
    Q_ScreenFx_DrawCopy_0_00132190 *p;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (u64)D_00201F00 | ((s64)(s32)((u32)(u16)w >> 6) << 16) | 0x3A000000);
    GsPkt_SetReg_3_001543E0(0x4E, (u64)D_00201EF4 | 0x3A000000);
    GsPkt_SetReg_3_001543E0(0x47, 0x30000);
    GsPkt_SetReg_3_001543E0(0x42, ((u64)0x80 << 32) | 0xA8);
    GsPkt_SetReg_3_001543E0(0x3B, (u64)0x80 << 32);
    GsPkt_SetReg_3_001543E0(0x40, ((s64)((u16)w - 1) << 16) | ((s64)((u16)h - 1) << 48));
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(9);
    q.q = 0;
    q.w[0] = 0x10000008;
    q.w[3] = 0x50000008;
    p[0].q = q.q;
    q.d[0] = ((u64)0x70AB4000 << 32) | 0x8001;
    q.d[1] = 0x53531E6;
    p[1].q = q.q;
    q.d[0] = ((u64)0xE << 32) | 0xABA2A300;
    q.d[1] = 0;
    p[2].q = q.q;
    q.d[0] = 0;
    q.d[1] = 0x14;
    p[3].q = q.q;
    q.w[0] = 0;
    q.w[1] = 0;
    q.w[2] = 0;
    q.w[3] = 0;
    p[4].q = q.q;
    q.w[0] = 0;
    q.w[1] = 0;
    q.w[2] = 0;
    q.w[3] = 0;
    p[5].q = q.q;
    q.w[0] = 0x6C00;
    q.w[1] = 0x7200;
    q.w[2] = 0x7400;
    q.w[3] = 0;
    p[6].q = q.q;
    q.w[0] = 0x2800;
    q.w[1] = 0x1C00;
    q.w[2] = 0;
    q.w[3] = 0;
    p[7].q = q.q;
    q.w[0] = ((u16)w + 0x6C0) << 4;
    q.w[1] = ((u16)h + 0x720) << 4;
    q.w[2] = 0x7400;
    q.w[3] = 0;
    p[8].q = q.q;
    GsPkt_Commit_1_00154A70();
    Tex_FlushAll_1_00176AE0();
}
#undef GsPkt_Alloc_3_00154A80

/* ScreenFx_DrawSprite_0_001323C0 */
#define GsPkt_Alloc_3_00154A80 GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawSprite_0_001323C0
s32 GsPkt_Alloc_3_00154A80__as_ScreenFx_DrawSprite_0_001323C0(s32);

void ScreenFx_DrawSprite_0_001323C0(A0 *a0, u32 a1, u32 a2, A3 *a3) {
    Q_ScreenFx_DrawSprite_0_001323C0 *p;
    Q_ScreenFx_DrawSprite_0_001323C0 q;
    f32 f;

    p = (Q_ScreenFx_DrawSprite_0_001323C0 *)GsPkt_Alloc_3_00154A80(0x23);
    memset((s32)p, 0, 0x230);
    q.q = 0;
    q.w[0] = 0x10000022;
    q.w[3] = 0x6C228121;
    p[0].q = q.q;
    q.d[0] = 0x8001 | ((u64)0x24000 << 32);
    q.d[1] = 0x4E4E4E44 | ((u64)0x4E4E44E4 << 32);
    p[1].q = q.q;
    p[0x12].q = q.q;
    q.w[0] = a0->x4 - 1;
    q.w[1] = 0x11;
    q.w[2] = 0;
    q.w[3] = 0;
    p[2].q = q.q;
    q.d[0] = 0x240;
    q.d[1] = 0x1B;
    p[4].q = q.q;
    q.d[0] = 0x40;
    q.d[1] = 0x1B;
    p[6].q = q.q;
    q.f[0] = 1728.0f;
    q.f[1] = 1824.0f;
    q.w[2] = 0;
    q.w[3] = 0;
    p[3].q = q.q;
    q.f[0] = (f32)a1 / 640.0f;
    q.f[1] = (f32)a2 / 448.0f;
    q.f[2] = 1.0f;
    q.f[3] = 1.0f;
    p[5].q = q.q;
    f = a3->f1C;
    q.f[0] = a3->f10 * f;
    q.f[1] = a3->f14 * f;
    q.f[2] = a3->f18 * f;
    q.f[3] = f;
    p[0x11].q = q.q;
    GsPkt_Commit_1_00154A70();
    Tex_FlushAll_1_00176AE0();
}
#undef GsPkt_Alloc_3_00154A80

/* ScreenFx_DrawLetterbox_0_001325F0 */
static inline s32 wd_ScreenFx_DrawLetterbox_0_001325F0(void) { return D_00201F2C ? 0 : 0x1180; }

void ScreenFx_DrawLetterbox_0_001325F0(void) {
    f32 f;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd_ScreenFx_DrawLetterbox_0_001325F0() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4D, (s64)(wd_ScreenFx_DrawLetterbox_0_001325F0() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
    GsPkt_SetReg_3_001543E0(0x4F, 0x3A000118);
    f = D_00201E90;
    GsPkt_SetReg_3_001543E0(0x40, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    f = D_00201E90;
    GsPkt_SetReg_3_001543E0(0x41, 0x27F0000 | ((u64)__fixunssfdi(f) << 32) | ((u64)__fixunssfdi(448.0f - f - 1.0f) << 48));
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x1A, 1);
    GsPkt_SetReg_3_001543E0(0x42, 0xAA);
    GsPkt_SetReg_3_001543E0(0x43, 0x48);
    GsPkt_SetReg_3_001543E0(0x47, 0x50000);
    GsPkt_SetReg_3_001543E0(0x48, 0x50000);
    GsPkt_SetReg_3_001543E0(1, 0x80000);
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
}

/* ScreenFx_DrawRestore_0_001327B0 */
#define GsPkt_SetReg_3_001543E0 GsPkt_SetReg_3_001543E0__as_ScreenFx_DrawRestore_0_001327B0
void GsPkt_SetReg_3_001543E0__as_ScreenFx_DrawRestore_0_001327B0(s32, s64);

void ScreenFx_DrawRestore_0_001327B0(void) {
    u16 w;
    u16 h;
    s64 a;
    h = D_00201F08; w = D_00201F04;
    GsPkt_BeginAD_3_001545D0();
    a = (s32)((u32)w >> 6);
    a = a << 16;
    GsPkt_SetReg_3_001543E0(0x4C, (u64)D_00201EF4 | a | 0xA000000);
    GsPkt_SetReg_3_001543E0(0x4D, (u64)D_00201EF4 | a | 0xA000000);
    GsPkt_SetReg_3_001543E0(0x4E, (u64)D_00201F00 | 0x3A000000);
    GsPkt_SetReg_3_001543E0(0x4F, (u64)D_00201F00 | 0x3A000000);
    a = (s64)(s32)(w - 1) << 16 | (s64)(s32)(h - 1) << 48;
    GsPkt_SetReg_3_001543E0(0x40, a);
    GsPkt_SetReg_3_001543E0(0x41, a);
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x1A, 0);
    GsPkt_SetReg_3_001543E0(0x42, 0x68 | (s64)0x80 << 32);
    GsPkt_SetReg_3_001543E0(0x43, 0xA1 | (s64)0x80 << 32);
    GsPkt_SetReg_3_001543E0(0x47, 0x51001);
    GsPkt_SetReg_3_001543E0(0x48, 0x51001);
    GsPkt_SetReg_3_001543E0(1, 0x80000);
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
}
#undef GsPkt_SetReg_3_001543E0

/* ScreenFx_Draw_0_00132930 */
#define GsPkt_EndAD_3_00154420 GsPkt_EndAD_3_00154420__as_ScreenFx_Draw_0_00132930
int GsPkt_EndAD_3_00154420__as_ScreenFx_Draw_0_00132930();
#define GsPkt_SetReg_3_001543E0 GsPkt_SetReg_3_001543E0__as_ScreenFx_Draw_0_00132930
int GsPkt_SetReg_3_001543E0__as_ScreenFx_Draw_0_00132930();
#define ScreenFx_DrawBlurPasses_0_00131970 ScreenFx_DrawBlurPasses_0_00131970__as_ScreenFx_Draw_0_00132930
int ScreenFx_DrawBlurPasses_0_00131970__as_ScreenFx_Draw_0_00132930();

void ScreenFx_Draw_0_00132930(s32 arg0) {
    if (D_00201F0C != 0) {
        ScreenFx_DrawBlurPasses_0_00131970((s32) D_00201F04, (s32) D_00201F08, (void *) arg0);
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x1A, 1);
        GsPkt_SetReg_3_001543E0(0x42, 0xAA);
        GsPkt_SetReg_3_001543E0(0x43, 0x48);
        GsPkt_SetReg_3_001543E0(0x47, 0x50000);
        GsPkt_SetReg_3_001543E0(0x48, 0x50000);
        GsPkt_SetReg_3_001543E0(1, 0x80000);
        GsPkt_EndAD_3_00154420();
        Tex_FlushAll_1_00176AE0();
        D_00201F0C = 0;
    }
}
#undef GsPkt_EndAD_3_00154420
#undef GsPkt_SetReg_3_001543E0
#undef ScreenFx_DrawBlurPasses_0_00131970

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201EF4, D_00201F00 */
u32 D_00201EF4;
u32 D_00201F00;
#endif
