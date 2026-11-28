/* NEAR (still structurally off): built 422 words vs retail 453; difflib opcode ratio 0.82 (prev attempt 0.75).
   Changes vs old attempt: W struct (pos[2][8][11]) like matched Weather_Update_0_00157D50; k/l loops as entry-test + do-while
   (retail's entry test reads ii/jj = copy-propagated k/l init); per-iteration volatile reads of gScreenFxBss_002F2070/gWeatherDrawBss_002F1AEC;
   fields read into s16 locals first.
   Still differs: retail runs out of s-regs (fp = &q+8, s4-s7 used) so i/j (u8) and ii/jj (s32) live in 16-byte stack
   slots (sb/lbu, sw/lw reloads); retail strength-reduces k*3584 / k*7168 into IVs (t9/t8 += 0xE00/0x1C00) and keeps two
   separate IVs for the two l*10240/10 uses (no CSE); x and y chains are interleaved with all four lh loads before any store. */
#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
typedef struct { s16 x, y; } Pt;
typedef struct { u8 pad[0x140]; Pt pos[2][8][11]; } W;
extern s32 gSfxAllSbss_00201F2C;
extern f32 gGameMainSbss_00201E90;
extern f32 gScreenFxBss_002F1AE0[];
extern f32 gWeatherDrawBss_002F1AE4[];
extern f32 gWeatherDrawBss_002F1AE8[];
extern f32 gWeatherDrawBss_002F1AEC[];
extern f32 gScreenFxBss_002F2070[];
extern W gWeatherState_002F19B0;
extern void GsPkt_BeginAD_3_001545D0(void);
extern void GsPkt_SetReg_3_001543E0(s32, u64);
extern void GsPkt_EndAD_3_00154420(void);
extern Q *GsPkt_Alloc_3_00154A80(s32);
extern void GsPkt_Commit_1_00154A70(void);
extern void Tex_FlushAll_1_00176AE0(void);
extern u64 __fixunssfdi(f32);
static inline s32 wd(void) { return gSfxAllSbss_00201F2C ? 0 : 0x1180; }

void Weather_Draw_0_00157630(void) {
    Q *p;
    u8 j;
    u8 i;
    s32 ii;
    s32 jj;
    s32 e;
    s32 e2;
    u8 k;
    u8 l;
    f32 f;
    u64 v;
    Q q;

    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x3F, 0xFFFFFFFF);
    GsPkt_SetReg_3_001543E0(0x4C, 0xA0118);
    GsPkt_SetReg_3_001543E0(0x4E, ((u64)1 << 32) | 0x3A000118);
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_SetReg_3_001543E0(0x40, ((u64)0xDF0000 << 32) | 0x27F0000);
    GsPkt_EndAD_3_00154420();
    p = GsPkt_Alloc_3_00154A80(9);
    q.q = 0;
    q.w[0] = 0x10000008;
    q.w[3] = 0x50000008;
    p[0].q = q.q;
    q.d[0] = ((u64)0x708B4000 << 32) | 0x8001;
    q.d[1] = 0x53538E6;
    p[1].q = q.q;
    q.d[0] = (s64)wd() | (((u64)0xE << 32) | 0xA8028000);
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
    q.w[0] = 0x6C00;
    q.w[1] = 0x7200;
    q.w[2] = 0;
    q.w[3] = 0;
    p[6].q = q.q;
    q.w[0] = 0x2810;
    q.w[1] = 0x1C10;
    q.d[1] = 0;
    p[7].q = q.q;
    q.w[0] = 0x9400;
    q.w[1] = 0x8000;
    q.w[2] = 0;
    q.w[3] = 0;
    p[8].q = q.q;
    GsPkt_Commit_1_00154A70();
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
    GsPkt_SetReg_3_001543E0(0x4E, 0x3A000118);
    f = gGameMainSbss_00201E90;
    v = (__fixunssfdi(f) << 32) | 0x27F0000;
    GsPkt_SetReg_3_001543E0(0x40, v | (__fixunssfdi(448.0f - f - 1.0f) << 48));
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_SetReg_3_001543E0(6, ((u64)6 << 32) | 0xA802A300);
    GsPkt_SetReg_3_001543E0(0x14, 0x60);
    GsPkt_SetReg_3_001543E0(1, 5);
    GsPkt_EndAD_3_00154420();
    for (i = 0; i < 7; i++) {
        ii = i;
        e = ii + 2;
        for (j = 0; j < 10; j++) {
            p = GsPkt_Alloc_3_00154A80(0xB);
            q.q = 0;
            q.w[0] = 0x1000000A;
            q.w[3] = 0x5000000A;
            p[0].q = q.q;
            q.d[0] = ((u64)0x908A4000 << 32) | 0x8001;
            q.d[1] = ((u64)5 << 32) | 0x35353531;
            p[1].q = q.q;
            q.w[0] = 128.0f * gScreenFxBss_002F1AE0[0];
            q.w[1] = 128.0f * gWeatherDrawBss_002F1AE4[0];
            q.w[2] = 128.0f * gWeatherDrawBss_002F1AE8[0];
            q.w[3] = 0x80;
            p[2].q = q.q;
            p += 3;
            k = i;
            jj = j;
            e2 = jj + 2;
            if (ii < e) do {
                l = j;
                if (jj < e2) do {
                    Pt *a = &gWeatherState_002F19B0.pos[0][k][l];
                    Pt *b = &gWeatherState_002F19B0.pos[1][k][l];
                    s16 ay = a->y;
                    s16 by = b->y;
                    s16 ax = a->x;
                    s16 bx = b->x;
                    f32 t = *(volatile f32 *)gScreenFxBss_002F2070;
                    f32 sc = *(volatile f32 *)gWeatherDrawBss_002F1AEC;
                    q.w[0] = (s16)((s16)(s32)(sc * (ax + t * (bx - ax))) >> 2) + l * 10240 / 10;
                    q.w[1] = (s16)((s16)(s32)(sc * (ay + t * (by - ay))) >> 2) + k * 3584 / 7;
                    q.d[1] = 0;
                    p[0].q = q.q;
                    q.w[0] = l * 10240 / 10 + 0x6C00;
                    q.w[1] = k * 7168 / 7 + 0x7200;
                    q.w[2] = 0;
                    q.w[3] = 0;
                    p[1].q = q.q;
                    p += 2;
                } while (++l < e2);
            } while (++k < e);
            GsPkt_Commit_1_00154A70();
        }
    }
    Tex_FlushAll_1_00176AE0();
}




