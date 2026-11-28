#include "m2c.h"
#include "common.h"
#include "include_asm.h"
#include "game/core.h"
#include "game/data.h"
#include "game/effect.h"
#include "game/gfx.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q_GsPkt_ResetFrame_1_00153770;
typedef struct { s32 buf, size, n, cur; s32 stk[16]; s32 x50, x54, x58, x5C, x60, x64, x68, x6C; } G_GsPkt_DrawFadeRect_0_00153B50;
typedef union { u128 q; u64 d[2]; } Q_GsPkt_AddRegData_1_001541F0;
typedef union Q_GsPkt_PushTag_1_00154310 { u128 q; struct { u32 a; u32 b; union Q_GsPkt_PushTag_1_00154310 *p; u32 d; } s; } Q_GsPkt_PushTag_1_00154310;
typedef struct { s32 pad0[2]; s32 n; s32 c; s32 arr[17]; s32 x54; s32 pad58[4]; s32 base; } G_GsPkt_SetLayerRange_0_001547F0;
typedef struct { s32 pad0[3]; s8 *c; s32 pad10[16]; u32 x50; Q_GsPkt_PushTag_1_00154310 *x54; } G_GsPkt_CloseChain_1_001549D0;
typedef struct { u32 w0, w1, w2, w3; } T4;
typedef union { u128 q; u32 w[4]; } Q_Gfx_KickFrame_1_00154B70;
extern s32 D_002F1990[];
extern s32 D_002F1994[];
extern volatile s32 D_002F1998[];
#ifndef NONMATCHING
extern volatile u64 D_002F14E0[];
#else
/* data twins (src/game/data/gs_packet_bss.c): D_002F14E0 */
static volatile u64 D_002F14E0[0x2];
#endif
extern volatile u64 D_002F1500[];
extern volatile u64 D_002F1510[];
#ifndef NONMATCHING
extern volatile u64 D_002F13F0[];
#else
/* data twins (src/game/data/gs_packet_bss.c): D_002F13F0 */
static volatile u64 D_002F13F0[0x2];
#endif
extern volatile u64 D_002F1410[];
extern volatile u64 D_002F1420[];
extern G_GsPkt_DrawFadeRect_0_00153B50 D_002F1940;
extern s32 D_00201C5C;
#ifndef NONMATCHING
extern f32 D_00201C60;
#else
/* data twins (src/game/data/sdata.c): D_00201C60 */
static f32 D_00201C60 = 3000.0f;
#endif
extern f32 D_00201F58, D_00201F5C, D_00201F60, D_00201F64, D_00201F68, D_00201F6C, D_00201F70, D_00201F74;
extern f32 D_002F1600[4][4];
extern f32 D_002F1640[4][4];
extern s32 D_002F19AC[];
extern f32 D_00201F30, D_00201F34;
extern s32 D_00201C64, D_00201C68, D_00201C6C, D_00201C70, D_00201C74, D_00201C78;
extern s32 D_002F1120[], D_002F1124[], D_002F1128[], D_002F112C[];
extern s32 D_002F1130[], D_002F1134[], D_002F1138[], D_002F113C[];
extern u64 D_002F1140[], D_002F1148[], D_002F1150[], D_002F1158[];
extern u8 D_002F1840[], D_002F16C0[];
extern u32 D_002F19A8[];
#ifndef NONMATCHING
extern s32 D_00201C58;
#else
/* data twins (src/game/data/sdata.c): D_00201C58 */
static s32 D_00201C58 = -1;
#endif
#ifndef NONMATCHING
extern u64 D_002F1490[];
#else
/* data twins (src/game/data/gs_packet_bss.c): D_002F1490 */
static u64 D_002F1490[0xa];
#endif
#ifndef NONMATCHING
extern u64 D_002F1580[];
#else
/* data twins (src/game/data/gs_packet_bss.c): D_002F1580 */
static u64 D_002F1580[0x8];
#endif
extern s8 D_002F1390[];
extern s8 D_002F1160[];
void GsPkt_ResetFrame_1_00153770(void);
void GsPkt_DrawFadeRect_0_00153B50(s32 a0);
s32 Gfx_SphereInFrustum_1_00153FA0(f32 *s);
void GsPkt_AddRegData_1_001541F0(u32 a, u64 b);
void GsPkt_PushTag_1_00154310(Q_GsPkt_PushTag_1_00154310 *a);
s32 GsPkt_AllocDirect_1_001543A0(s32 arg0);
void GsPkt_SetReg_3_001543E0(u32 a, u64 b);
s32 GsPkt_Alloc_3_00154A80(s32 arg0);
void GsPkt_SetBaseTex_0_00154B00(s32 arg0);
void sceVu0CopyVector(f32 *, f32 *);
void sceVu0ApplyMatrix(f32 *, f32 (*)[4], f32 *);
void FlushCache(s32);
void Dma_SprCopy_1_001789E0(u32, u32, s32);
void Gfx_BuildViewMatrices_0_00155090(void);
void sceGsSyncPath(s32, s32);
s32 sceGsSyncV(s32);
void sceGsSwapDBuff(s8 *, s32);

/* GsPkt_ResetFrame_1_00153770 */
static inline void push_GsPkt_ResetFrame_1_00153770(u64 v, u64 r) {
    Q_GsPkt_ResetFrame_1_00153770 q;
    s32 p;
    q.d[0] = v;
    q.d[1] = r;
    p = (D_002F1994[0] += 0x10) - 0x10;
    *(Q_GsPkt_ResetFrame_1_00153770 *)p = q;
}

static inline void end(void) {
    Q_GsPkt_ResetFrame_1_00153770 a;
    Q_GsPkt_ResetFrame_1_00153770 b;
    s32 n;
    s32 p;

    p = D_002F1998[0];
    n = (D_002F1994[0] - p) / 16 - 2;
    a.q = 0;
    a.w[1] = 0;
    a.w[0] = (n + 1) | 0x10000000;
    a.w[3] = (n + 1) | 0x51000000;
    *(Q_GsPkt_ResetFrame_1_00153770 *)p = a;
    b.q = 0;
    b.d[0] = (u64)(u32)n | (0x8000 | ((u64)0x10000000 << 32));
    b.d[1] = 0xE;
    *(Q_GsPkt_ResetFrame_1_00153770 *)(D_002F1998[0] + 0x10) = b;
}

void GsPkt_ResetFrame_1_00153770(void) {
    if (D_002F1994[0] == 0) {
        D_002F1994[0] = D_002F1990[0];
    }
    D_002F1998[0] = D_002F1994[0];
    D_002F1994[0] += 0x20;
    if (D_00201F2C) {
        push_GsPkt_ResetFrame_1_00153770(D_002F14E0[0], 0x4C);
        push_GsPkt_ResetFrame_1_00153770(D_002F1510[0], 0x40);
        push_GsPkt_ResetFrame_1_00153770(D_002F1500[0], 0x18);
        push_GsPkt_ResetFrame_1_00153770(D_002F14E0[0], 0x4D);
        push_GsPkt_ResetFrame_1_00153770(D_002F1510[0], 0x41);
        push_GsPkt_ResetFrame_1_00153770(D_002F1500[0], 0x19);
    } else {
        push_GsPkt_ResetFrame_1_00153770(D_002F13F0[0], 0x4C);
        push_GsPkt_ResetFrame_1_00153770(D_002F1420[0], 0x40);
        push_GsPkt_ResetFrame_1_00153770(D_002F1410[0], 0x18);
        push_GsPkt_ResetFrame_1_00153770(D_002F13F0[0], 0x4D);
        push_GsPkt_ResetFrame_1_00153770(D_002F1420[0], 0x41);
        push_GsPkt_ResetFrame_1_00153770(D_002F1410[0], 0x19);
    }
    push_GsPkt_ResetFrame_1_00153770(0x50000, 0x48);
    push_GsPkt_ResetFrame_1_00153770(0, 9);
    push_GsPkt_ResetFrame_1_00153770(0x48, 0x43);
    end();
}

/* GsPkt_DrawFadeRect_0_00153B50 */
static inline void chk_GsPkt_DrawFadeRect_0_00153B50(void) {
    if ((u32)((D_002F1940.cur - D_002F1940.x68) / 32) < 0x660) {
        D_00201F28 = 1;
    } else {
        D_00201F28 = 0;
    }
}
static inline void push_GsPkt_DrawFadeRect_0_00153B50(s32 off) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.cur = D_002F1940.x68 + off;
    D_002F1940.stk[D_002F1940.n] = D_002F1940.cur;
    D_002F1940.n++;
    chk_GsPkt_DrawFadeRect_0_00153B50();
}
static inline void pop_GsPkt_DrawFadeRect_0_00153B50(void) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.n--;
    D_002F1940.cur = D_002F1940.stk[D_002F1940.n];
    chk_GsPkt_DrawFadeRect_0_00153B50();
}

void GsPkt_DrawFadeRect_0_00153B50(s32 a0) {
    Q_GsPkt_ResetFrame_1_00153770 a;
    Q_GsPkt_ResetFrame_1_00153770 b;
    s32 p;

    push_GsPkt_DrawFadeRect_0_00153B50(0x1C0);
    if (D_002F1940.x54 == 0) {
        D_002F1940.x54 = D_002F1940.x50;
    }
    D_002F1940.x58 = D_002F1940.x54;
    D_002F1940.x54 += 0x20;
    a.d[0] = 0x30000;
    a.d[1] = 0x47;
    p = D_002F1940.x54;
    D_002F1940.x54 = p + 0x10;
    *(Q_GsPkt_ResetFrame_1_00153770 *)p = a;
    b.d[0] = 0x3A000118;
    b.d[1] = 0x4E;
    p = D_002F1940.x54;
    D_002F1940.x54 = p + 0x10;
    *(Q_GsPkt_ResetFrame_1_00153770 *)p = b;
    GsPkt_Flush_1_001544C0();
    Draw_Rect_1_00155AC0(0, 0, 0x280, 0x1C0, a0);
    pop_GsPkt_DrawFadeRect_0_00153B50();
    Fx_ResetSpriteCount_0_00164320();
}

/* GsPkt_DrawClearRect_0_00153D80 */
static inline void chk_GsPkt_DrawClearRect_0_00153D80(void) {
    if ((u32)((D_002F1940.cur - D_002F1940.x68) / 32) < 0x660) {
        D_00201F28 = 1;
    } else {
        D_00201F28 = 0;
    }
}
static inline void push_GsPkt_DrawClearRect_0_00153D80(s32 off) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.cur = D_002F1940.x68 + off;
    D_002F1940.stk[D_002F1940.n] = D_002F1940.cur;
    D_002F1940.n++;
    chk_GsPkt_DrawClearRect_0_00153D80();
}
static inline void pop_GsPkt_DrawClearRect_0_00153D80(void) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.n--;
    D_002F1940.cur = D_002F1940.stk[D_002F1940.n];
    chk_GsPkt_DrawClearRect_0_00153D80();
}
static inline void begin(void) {
    if (D_002F1940.x54 == 0) {
        D_002F1940.x54 = D_002F1940.x50;
    }
    D_002F1940.x58 = D_002F1940.x54;
    D_002F1940.x54 += 0x20;
}
static inline void set(s32 reg, u64 data) {
    Q_GsPkt_ResetFrame_1_00153770 q;
    Q_GsPkt_ResetFrame_1_00153770 *p;
    q.d[0] = data;
    q.d[1] = reg;
    p = (Q_GsPkt_ResetFrame_1_00153770 *)D_002F1940.x54;
    D_002F1940.x54 = (s32)(p + 1);
    *p = q;
}

void GsPkt_DrawClearRect_0_00153D80(void) {
    push_GsPkt_DrawClearRect_0_00153D80(0x1C0);
    begin();
    set(0x47, 0x30000);
    set(0x4E, 0x3A000118);
    GsPkt_Flush_1_001544C0();
    Draw_Rect_1_00155AC0(0, 0, 0x280, 0x1C0, D_00201C5C);
    pop_GsPkt_DrawClearRect_0_00153D80();
    Fx_ResetSpriteCount_0_00164320();
}

/* Gfx_SphereInFrustum_1_00153FA0 */
s32 Gfx_SphereInFrustum_1_00153FA0(f32 *s) {
    f32 v[4] __attribute__((aligned(16)));
    f32 *w;
    f32 r;
    f32 p0, p1, p2, p3, p4, p5, p6, p7;

    r = s[3];
    sceVu0CopyVector(v, s);
    w = &v[3];
    *w = 1.0f;
    if (D_00201F28 != 0) {
        sceVu0ApplyMatrix(v, D_002F1600, v);
    } else {
        sceVu0ApplyMatrix(v, D_002F1640, v);
    }
    p0 = v[0] * D_00201F70 + *w * D_00201F74;
    p1 = v[0] * -D_00201F70 + *w * D_00201F74;
    p2 = v[1] * D_00201F68 + *w * D_00201F6C;
    p3 = v[1] * -D_00201F68 + *w * D_00201F6C;
    p4 = v[0] * D_00201F60 + *w * D_00201F64;
    p5 = v[0] * -D_00201F60 + *w * D_00201F64;
    p6 = v[1] * D_00201F58 + *w * D_00201F5C;
    p7 = v[1] * -D_00201F58 + *w * D_00201F5C;
    if (p0 + r < 0.0f) return -1;
    if (p1 + r < 0.0f) return -1;
    if (p2 + r < 0.0f) return -1;
    if (p3 + r < 0.0f) return -1;
    if (*w + r < 0.0f) return -1;
    if (!(*w - r <= D_00201C60)) return -1;
    if (!(p0 - r <= 0.0f || p1 - r <= 0.0f || p2 - r <= 0.0f || p3 - r <= 0.0f)) return 0;
    if (!(p4 - r <= 0.0f || p5 - r <= 0.0f || p6 - r <= 0.0f || p7 - r <= 0.0f)) return 1;
    return 2;
}

/* Gfx_SetFogScale_0_001541E0 */
void Gfx_SetFogScale_0_001541E0(f32 fparg0) {
    D_00201C60 = fparg0;
}

/* GsPkt_AddRegData_1_001541F0 */
#define D_002F1994 D_002F1994__as_GsPkt_AddRegData_1_001541F0
extern Q_GsPkt_AddRegData_1_001541F0 *D_002F1994__as_GsPkt_AddRegData_1_001541F0[];
void GsPkt_AddRegData_1_001541F0(u32 a, u64 b) {
    Q_GsPkt_AddRegData_1_001541F0 t; Q_GsPkt_AddRegData_1_001541F0 *p;
    t.d[0] = b; t.d[1] = a;
    p = D_002F1994[0];
    D_002F1994[0] = p + 1;
    *p = t;
}
#undef D_002F1994

/* GsPkt_EndADDirect_1_00154230 */
void GsPkt_EndADDirect_1_00154230(void) {
    Q_GsPkt_ResetFrame_1_00153770 a;
    Q_GsPkt_ResetFrame_1_00153770 b;
    s32 n;
    s32 p;

    p = D_002F1998[0];
    n = (D_002F1994[0] - p) / 16 - 2;
    a.q = 0;
    a.w[1] = 0;
    a.w[0] = (n + 1) | 0x10000000;
    a.w[3] = (n + 1) | 0x51000000;
    *(Q_GsPkt_ResetFrame_1_00153770 *)p = a;
    b.q = 0;
    b.d[0] = (u64)(u32)n | (0x8000 | ((u64)0x10000000 << 32));
    b.d[1] = 0xE;
    *(Q_GsPkt_ResetFrame_1_00153770 *)(D_002F1998[0] + 0x10) = b;
}

/* GsPkt_BeginADDirect_1_001542D0 */

void GsPkt_BeginADDirect_1_001542D0(void) {
    if ((*D_002F1994) == 0) {
        (*D_002F1994) = (*D_002F1990);
    }
    (*D_002F1998) = (*D_002F1994);
    (*D_002F1994) += 0x20;
}

/* GsPkt_PushTag_1_00154310 */
#define D_002F1994 D_002F1994__as_GsPkt_PushTag_1_00154310
extern Q_GsPkt_PushTag_1_00154310 *D_002F1994__as_GsPkt_PushTag_1_00154310[];
void GsPkt_PushTag_1_00154310(Q_GsPkt_PushTag_1_00154310 *a) {
    Q_GsPkt_PushTag_1_00154310 tag;
    tag.q = 0;
    tag.s.a = 0x20000000;
    tag.s.b = D_002F1990[0] & 0x0FFFFFFF;
    *a = tag;
    tag.q = 0;
    tag.s.a = 0x20000000;
    tag.s.b = (u32)(a + 1) & 0x0FFFFFFF;
    *D_002F1994[0] = tag;
    D_002F1990[0] = (u32)(*(Q_GsPkt_PushTag_1_00154310 *volatile *)D_002F1994 + 1);
    D_002F1994[0] = 0;
}
#undef D_002F1994

/* GsPkt_Nop_2_00154390 */
void GsPkt_Nop_2_00154390(void) {

}

/* GsPkt_AllocDirect_1_001543A0 */
s32 GsPkt_AllocDirect_1_001543A0(s32 arg0) {
    s32 v = D_002F1994[0];
    if (v == 0) {
        v = D_002F1990[0];
        D_002F1994[0] = v;
    }
    D_002F1994[0] += arg0 * 0x10;
    return v;
}

/* GsPkt_SetReg_3_001543E0 */
void GsPkt_SetReg_3_001543E0(u32 a, u64 b) {
    Q_GsPkt_AddRegData_1_001541F0 q;
    Q_GsPkt_AddRegData_1_001541F0 *p;
    q.d[0] = b;
    q.d[1] = a;
    p = (Q_GsPkt_AddRegData_1_001541F0 *)D_002F1994[0];
    D_002F1994[0] = (s32)(p + 1);
    *p = q;
}

/* GsPkt_EndAD_3_00154420 */
void GsPkt_EndAD_3_00154420(void) {
    Q_GsPkt_ResetFrame_1_00153770 a;
    Q_GsPkt_ResetFrame_1_00153770 b;
    s32 n;
    s32 p;

    p = D_002F1998[0];
    n = (D_002F1994[0] - p) / 16 - 2;
    a.q = 0;
    a.w[1] = 0;
    a.w[0] = (n + 1) | 0x10000000;
    a.w[3] = (n + 1) | 0x51000000;
    *(Q_GsPkt_ResetFrame_1_00153770 *)p = a;
    b.q = 0;
    b.d[0] = (u64)(u32)n | (0x8000 | ((u64)0x10000000 << 32));
    b.d[1] = 0xE;
    *(Q_GsPkt_ResetFrame_1_00153770 *)(D_002F1998[0] + 0x10) = b;
}

/* text_001544C0 */
#ifdef NONMATCHING
/* best-effort C: gs_pkt_flush.c */
#else
INCLUDE_ASM(GsPkt_Flush_1_001544C0);
#endif

/* GsPkt_BeginAD_3_001545D0 */

void GsPkt_BeginAD_3_001545D0(void) {
    if ((*D_002F1994) == 0) {
        (*D_002F1994) = (*D_002F1990);
    }
    (*D_002F1998) = (*D_002F1994);
    (*D_002F1994) += 0x20;
}

/* GsPkt_SetLayerB_0_00154610 */
static inline void chk_GsPkt_SetLayerB_0_00154610(void) {
    if ((u32)((D_002F1940.cur - D_002F1940.x68) / 32) < 0x660) {
        D_00201F28 = 1;
    } else {
        D_00201F28 = 0;
    }
}
static inline void push_GsPkt_SetLayerB_0_00154610(s32 off) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.cur = D_002F1940.x68 + off;
    D_002F1940.stk[D_002F1940.n] = D_002F1940.cur;
    D_002F1940.n++;
    chk_GsPkt_SetLayerB_0_00154610();
}

void GsPkt_SetLayerB_0_00154610(s32 a0, s32 a1) {
    push_GsPkt_SetLayerB_0_00154610(((a1 + 0x10) + a0 * 0x220) * 32);
}

/* GsPkt_SetLayer_1_00154700 */
static inline void chk_GsPkt_SetLayer_1_00154700(void) {
    if ((u32)((D_002F1940.cur - D_002F1940.x68) / 32) < 0x660) {
        D_00201F28 = 1;
    } else {
        D_00201F28 = 0;
    }
}
static inline void push_GsPkt_SetLayer_1_00154700(s32 off) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.cur = D_002F1940.x68 + off;
    D_002F1940.stk[D_002F1940.n] = D_002F1940.cur;
    D_002F1940.n++;
    chk_GsPkt_SetLayer_1_00154700();
}
static inline void pop_GsPkt_SetLayer_1_00154700(void) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.n--;
    D_002F1940.cur = D_002F1940.stk[D_002F1940.n];
    chk_GsPkt_SetLayer_1_00154700();
}

void GsPkt_SetLayer_1_00154700(s32 a0, s32 a1) {
    push_GsPkt_SetLayer_1_00154700((a1 + 0x210 + a0 * 0x220) * 32);
}

/* GsPkt_SetLayerRange_0_001547F0 */
#define D_002F1940 D_002F1940__as_GsPkt_SetLayerRange_0_001547F0
extern G_GsPkt_SetLayerRange_0_001547F0 D_002F1940__as_GsPkt_SetLayerRange_0_001547F0;

void GsPkt_SetLayerRange_0_001547F0(s32 a0, s32 a1) {
    if (D_002F1940.x54 != 0) GsPkt_CloseChain_1_001549D0();
    D_002F1940.c = D_002F1940.base + (0xE - a1 + a0 * 0x220) * 32;
    D_002F1940.arr[D_002F1940.n] = D_002F1940.c;
    D_002F1940.n++;
    if ((u32)((D_002F1940.c - D_002F1940.base) / 32) < 0x660) D_00201F28 = 1;
    else D_00201F28 = 0;
}
#undef D_002F1940

/* GsPkt_SetLayerTop_0_001548F0 */
#define D_002F1940 D_002F1940__as_GsPkt_SetLayerTop_0_001548F0
extern G_GsPkt_SetLayerRange_0_001547F0 D_002F1940__as_GsPkt_SetLayerTop_0_001548F0;

void GsPkt_SetLayerTop_0_001548F0(s32 a0) {
    if (D_002F1940.x54 != 0) GsPkt_CloseChain_1_001549D0();
    D_002F1940.c = D_002F1940.base + (a0 * 0x220 + 0xF) * 32;
    D_002F1940.arr[D_002F1940.n] = D_002F1940.c;
    D_002F1940.n++;
    if ((u32)((D_002F1940.c - D_002F1940.base) / 32) < 0x660) D_00201F28 = 1;
    else D_00201F28 = 0;
}
#undef D_002F1940

/* GsPkt_CloseChain_1_001549D0 */
#define D_002F1940 D_002F1940__as_GsPkt_CloseChain_1_001549D0
extern G_GsPkt_CloseChain_1_001549D0 D_002F1940__as_GsPkt_CloseChain_1_001549D0[];

void GsPkt_CloseChain_1_001549D0(void) {
    s8 *c;
    Q_GsPkt_PushTag_1_00154310 tag;
    Q_GsPkt_PushTag_1_00154310 save;
    G_GsPkt_CloseChain_1_001549D0 *g = D_002F1940;
    Q_GsPkt_PushTag_1_00154310 *n;

    if (D_002F1994[0] != 0) {
        c = g->c;
        save.q = *(u128 *)(c + 0x10);
        tag.q = 0;
        tag.s.a = 0x20000000;
        tag.s.b = save.s.d;
        *g->x54 = tag;
        tag = *save.s.p;
        tag.s.b = g->x50 & 0x0FFFFFFF;
        *save.s.p = tag;
        save.s.p = g->x54;
        *(u128 *)(c + 0x10) = save.q;
        n = g->x54 + 1;
        g->x54 = n;
        g->x50 = (u32)n;
        g->x54 = 0;
    }
}
#undef D_002F1940

/* GsPkt_Commit_1_00154A70 */
void GsPkt_Commit_1_00154A70(void) {

}

/* GsPkt_Alloc_3_00154A80 */
s32 GsPkt_Alloc_3_00154A80(s32 arg0) {
    s32 v = D_002F1994[0];
    if (v == 0) {
        v = D_002F1990[0];
        D_002F1994[0] = v;
    }
    D_002F1994[0] += arg0 * 0x10;
    return v;
}

/* GsPkt_GetUsedQw_1_00154AC0 */
s32 GsPkt_GetUsedQw_1_00154AC0(void)
{
    return (D_002F1990[0] - D_002F19AC[0]) / 16;
}

/* GsPkt_ResetLayer_0_00154AF0 */
void GsPkt_ResetLayer_0_00154AF0(void) {
    (*D_002F1948) = -1;
}

/* GsPkt_SetBaseTex_0_00154B00 */
#define GsPkt_CloseChain_1_001549D0 GsPkt_CloseChain_1_001549D0__as_GsPkt_SetBaseTex_0_00154B00
void GsPkt_CloseChain_1_001549D0__as_GsPkt_SetBaseTex_0_00154B00(s32);

void GsPkt_SetBaseTex_0_00154B00(s32 arg0) {
    T4 t;
    u128 *p = (u128 *)D_002F1994[0];
    if (p == 0) {
        p = (u128 *)D_002F1990[0];
        D_002F1994[0] = (s32)p;
    }
    *(u128 *)&t = 0;
    D_002F1994[0] += 0x10;
    t.w0 = 0x30000010;
    t.w1 = arg0;
    t.w3 = 0x6C100000;
    *p = *(u128 *)&t;
    GsPkt_CloseChain_1_001549D0(arg0);
}
#undef GsPkt_CloseChain_1_001549D0

/* Gfx_KickFrame_1_00154B70 */
static inline void chk_Gfx_KickFrame_1_00154B70(void) {
    if ((u32)((D_002F1940.cur - D_002F1940.x68) / 32) < 0x660) {
        D_00201F28 = 1;
    } else {
        D_00201F28 = 0;
    }
}
static inline void push_Gfx_KickFrame_1_00154B70(s32 off) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.cur = D_002F1940.x68 + off;
    D_002F1940.stk[D_002F1940.n] = D_002F1940.cur;
    D_002F1940.n++;
    chk_Gfx_KickFrame_1_00154B70();
}
static inline void pop_Gfx_KickFrame_1_00154B70(void) {
    if (D_002F1940.x54) GsPkt_CloseChain_1_001549D0();
    D_002F1940.n--;
    D_002F1940.cur = D_002F1940.stk[D_002F1940.n];
    chk_Gfx_KickFrame_1_00154B70();
}

void Gfx_KickFrame_1_00154B70(void) {
    u128 *p;
    Q_Gfx_KickFrame_1_00154B70 t;
    D_002F1940.x6C = (s32)((u128 *)D_002F1940.x68 + 0x1982);

    FlushCache(0);
    Dma_SprCopy_1_001789E0(D_002F1940.x68 & 0x0FFFFFFF, (D_002F1940.x68 - 0x19820) & 0x0FFFFFFF, 0x1982);
    D_002F1940.x54 = 0;
    D_002F1940.x58 = 0;
    D_002F1940.n = 0;
    D_002F1940.x50 = D_002F1940.x6C;
    push_Gfx_KickFrame_1_00154B70(0x1E0);
    push_Gfx_KickFrame_1_00154B70(0x40);
    if (!(p = (u128 *)D_002F1940.x54)) {
        p = (u128 *)D_002F1940.x50;
        D_002F1940.x54 = (s32)p;
    }
    D_002F1940.x54 += 0x50;
    t.q = 0;
    t.w[0] = 0x30000010;
    t.w[1] = (u32)D_002F1840;
    t.w[3] = 0x6C100000;
    p[0] = t.q;
    t.q = 0;
    t.w[0] = 0x30000004;
    t.w[1] = (u32)D_002F16C0;
    t.w[3] = 0x6C040010;
    p[1] = t.q;
    if (!Game_IsNotFlag19A790_0_0012C0E0()) D_00201F30 += 0.02f;
    if (!(D_00201F30 <= 1.0f)) D_00201F30 -= 1.0f;
    D_002F1120[0] = *(s32 *)&D_00201F30;
    D_002F1124[0] = D_00201C64;
    D_002F1128[0] = D_00201C68;
    D_002F112C[0] = D_00201C6C;
    t.q = 0;
    t.w[0] = 0x30000001;
    t.w[1] = (u32)D_002F1120;
    t.w[3] = 0x6C01005B;
    p[2] = t.q;
    if (!Game_IsNotFlag19A790_0_0012C0E0()) D_00201F34 += 0.02f;
    if (!(D_00201F34 <= 1.0f)) D_00201F34 -= 1.0f;
    D_002F1130[0] = *(s32 *)&D_00201F34;
    D_002F1134[0] = D_00201C70;
    D_002F1138[0] = D_00201C74;
    D_002F113C[0] = D_00201C78;
    t.q = 0;
    t.w[0] = 0x30000001;
    t.w[1] = (u32)D_002F1130;
    t.w[3] = 0x6C01005E;
    p[3] = t.q;
    D_002F1140[0] = 0x8001 | ((u64)0x10000000 << 32);
    D_002F1148[0] = 6 | ((u64)-1 << 32);
    D_002F1150[0] = 0x20016BC0 | ((u64)0xE << 32);
    D_002F1158[0] = 0;
    t.q = 0;
    t.w[0] = 0x30000002;
    t.w[1] = (u32)D_002F1140;
    t.w[3] = 0x6C02005C;
    p[4] = t.q;
    GsPkt_CloseChain_1_001549D0();
    Gfx_BuildViewMatrices_0_00155090();
    pop_Gfx_KickFrame_1_00154B70();
    Fx_ResetSpriteCount_0_00164320();
}

/* text_00155090 */
#ifdef NONMATCHING
/* best-effort C: gfx_build_view_matrices.c */
#else
INCLUDE_ASM(Gfx_BuildViewMatrices_0_00155090);
#endif

/* Gfx_WaitDraw_1_001552A0 */

void Gfx_WaitDraw_1_001552A0(void) {
    if (D_002F1990[0] != 0) {
        FlushCache(0);
        sceGsSyncPath(0, 0);
        while (*(volatile u32 *)0x10009000 & 0x100) {
        }
        FlushCache(0);
        *(volatile u32 *)0x10009020 = 0;
        *(volatile u32 *)0x10009010 = 0;
        *(volatile u32 *)0x10009030 = D_002F19A8[0] & 0x0FFFFFFF;
        *(volatile u32 *)0x10009000 = 0x145;
        if (*(volatile u32 *)D_002F19A8 == D_002F199C[0]) {
            D_002F19A8[0] = D_002F19A0[0];
        } else {
            D_002F19A8[0] = D_002F199C[0];
        }
        D_00201C58 = 1;
    }
}

/* Gfx_FlipBuffers_2_00155370 */
#define D_00201C5C D_00201C5C__as_Gfx_FlipBuffers_2_00155370
extern u32 D_00201C5C__as_Gfx_FlipBuffers_2_00155370;

void Gfx_FlipBuffers_2_00155370(void) {
    Task_InitWrap_0_0014DAA0();
    if (D_00201C58 == 1) {
        D_00201C58 = 0;
        sceGsSyncPath(0, 0);
        while (*(volatile u32 *)0x10009000 & 0x100) {
        }
        sceGsSyncPath(0, 0);
        Timer_GetTicks_3_001787A0();
        while (sceGsSyncV(0) != 1) {
        }
        D_002F1580[0] = D_002F1490[0] = D_00201C5C;
        FlushCache(0);
        sceGsSwapDBuff(D_002F1390, D_00201F2C);
        FlushCache(0);
        sceGsSwapDBuff(D_002F1160, D_00201F2C);
        D_00201F2C = !(D_00201F2C != 0);
        FlushCache(0);
    }
}
#undef D_00201C5C

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): D_00201C5C, D_00201C64, D_00201C68, D_00201C6C, D_00201C70, D_00201C74, D_00201C78 */
s32 D_00201C5C = -0x80000000;
s32 D_00201C64 = 0x40490fd8;
s32 D_00201C68 = 0x40400000;
s32 D_00201C6C = 0x3d000000;
s32 D_00201C70 = 0x40490fd8;
s32 D_00201C74 = 0x40400000;
s32 D_00201C78 = 0x3d000000;
/* data twins (src/game/data/sbss.c): D_00201F28, D_00201F30, D_00201F34 */
s32 D_00201F28;
f32 D_00201F30;
f32 D_00201F34;
/* data twins (src/game/data/gs_packet_bss.c): D_002F1410, D_002F1420, D_002F1500, D_002F1510 */
volatile u64 D_002F1410[0x2];
volatile u64 D_002F1420[0xe];
volatile u64 D_002F1500[0x2];
volatile u64 D_002F1510[0xe];
/* data twins (src/game/data/gs_packet_bss_002F1990.c): D_002F1990, D_002F1994, D_002F1998, D_002F199C, D_002F19A0, D_002F19A8, D_002F19AC */
s32 D_002F1990[0x1] __attribute__((aligned(16)));
s32 D_002F1994[0x1];
volatile s32 D_002F1998[0x1];
u32 D_002F199C[0x1];
u32 D_002F19A0[0x1];
u32 D_002F19A8[0x1];
s32 D_002F19AC[0x1];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/gs_packet_bss.c): D_002F1600, D_002F1640 */
f32 D_002F1600[4][4];
f32 D_002F1640[4][4];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/gs_packet_bss.c): D_002F1120__grp: D_002F1120@0x0, D_002F1124@0x4, D_002F1128@0x8, D_002F112C@0xc */
u8 D_002F1120__grp[0x10] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/gs_packet_bss.c): D_002F1130__grp: D_002F1130@0x0, D_002F1134@0x4, D_002F1138@0x8, D_002F113C@0xc */
u8 D_002F1130__grp[0x10] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/gs_packet_bss.c): D_002F1140__grp: D_002F1140@0x0, D_002F1148@0x8, D_002F1150@0x10, D_002F1158@0x18 */
u8 D_002F1140__grp[0x20] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/gs_packet_bss.c): D_002F1160__grp: D_002F1160@0x0, D_002F1170@0x10, D_002F11C0@0x60, D_002F11C8@0x68, D_002F11D0@0x70, D_002F11D8@0x78, D_002F11E0@0x80, D_002F11E4@0x84, D_002F1248@0xe8, D_002F1250@0xf0, D_002F12B0@0x150, D_002F12B8@0x158, D_002F12C0@0x160, D_002F12C8@0x168, D_002F12D0@0x170, D_002F12D4@0x174, D_002F1338@0x1d8, D_002F1340@0x1e0, D_002F1388@0x228, D_002F1390@0x230 */
u8 D_002F1160__grp[0x240] __attribute__((aligned(16)));
#endif
