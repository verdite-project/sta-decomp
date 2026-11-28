#include "actor.h"
#include "game/player.h"
#include "game/ui.h"
#include "game/gfx.h"
typedef struct { u8 a : 5; u8 m : 2; u8 b7 : 1; } M;
typedef struct { u8 c[2]; } B2;
typedef struct {
    u8 pad0[0x3A2];
    M x3A2;
    u8 pad3A3[0xD];
    s32 x3B0;
    u8 pad3B4[0xA];
    u8 x3BE;
    u8 pad3BF[0x11];
    f32 x3D0;
    u8 pad3D4;
    u8 x3D5;
    u8 pad3D6[0x4A];
    s8 x420;
    s8 x421;
    u16 x422;
    u8 pad424[0x2C];
    s32 x450;
} P;
extern s32 gHudWarningSbss_002022E0;
#ifndef NONMATCHING
extern B2 gHudWarningSdata_00201E28;
#else
/* data twins (src/game/data/sdata.c): gHudWarningSdata_00201E28 */
static B2 gHudWarningSdata_00201E28 = { 0x40, 0x60 };
#endif
extern u64 gGsPacketBss_002F1420[];
extern Flags8 D_00222A54[];
void Hud_DrawWarning_0_001BC7A0(u32 a0, s32 a1, s32 a2);
f32 sinf(f32);
void GsPkt_SetReg_3_001543E0(s32, s32);
void Hud_DrawQuad_1_001BC610(s32, s32, s32, s32, u32, s32, s32);
void Hud_DrawCompass_0_001BBCC0(void);
s32 PlayerData_GetStatusTimer_0_001CE200(s32);

/* Hud_DrawWarning_0_001BC7A0 */
static inline f32 u2f(u32 x) { return x; }
static inline s8 *getp(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

void Hud_DrawWarning_0_001BC7A0(u32 a0, s32 a1, s32 a2) {
    u8 lo;
    s32 amp;
    s8 *p;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8 hi;
    s32 per;

    if (gPlayerSbss_002022E4 == 0) p = 0; else if (gPlayerSbss_002022E4->unk518 == 0) p = 0; else p = gPlayerSbss_002022E4->unk518 + 0x180;
    if (p == 0) return;
    if (a1 <= 0 || a1 > 2) return;
    switch (a0) {
    case 1:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0x40; hi = 0x80; r = 100; g = 100; b = 100; a = 0x30;
        break;
    case 0:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0; hi = 0x80; r = 0x32; g = 0x20; b = 0x50; a = 0x30;
        break;
    case 4:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0x40; hi = 0x80; r = 0; g = 0x10; b = 0x40; a = 0x30;
        break;
    case 5:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0; hi = 0x80; r = 0x30; g = 0x30; b = 0x12; a = 0x30;
        break;
    case 3:
    case 7:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0x40; hi = 0x80; r = 0x48; g = 0x2A; b = 0x20; a = 0x2B;
        break;
    default:
        return;
    }
    amp = (u8)((hi - lo) / 2);
    amp = (u8)((f32)(lo + (u8)amp) + u2f(amp) * sinf(6.2831855f * (f32)(a2 % (u8)per) / u2f(per)));
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x44);
    GsPkt_Flush_1_001544C0();
    Hud_DrawQuad_1_001BC610(-320, -224.0f + gHudWarningSbss_002022E0, 320, 224.0f - gHudWarningSbss_002022E0, a << 24 | b << 16 | g << 8 | r, 1, 0);
    Hud_DrawQuad_1_001BC610(-320, -224.0f + gHudWarningSbss_002022E0, 320, 224.0f - gHudWarningSbss_002022E0, (u8)amp << 24 | b << 16 | g << 8 | r, 1, *(s32 *)(p + 0x3B4));
}

/* Hud_DrawOverlay_0_001BCB60 */
#define GsPkt_SetReg_3_001543E0 GsPkt_SetReg_3_001543E0__as_Hud_DrawOverlay_0_001BCB60
void GsPkt_SetReg_3_001543E0__as_Hud_DrawOverlay_0_001BCB60(s32, s64);
#define Hud_DrawWarning_0_001BC7A0 Hud_DrawWarning_0_001BC7A0__as_Hud_DrawOverlay_0_001BCB60
void Hud_DrawWarning_0_001BC7A0__as_Hud_DrawOverlay_0_001BCB60(s8, s8, u16);
static inline P *cur(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (P *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

void Hud_DrawOverlay_0_001BCB60(void) {
    P *p;
    P *q;
    u32 c;
    u8 n;
    u8 k;
    s32 i;
    B2 t;

    p = cur();
    if (p == 0) return;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x40, gGsPacketBss_002F1420[0]);
    GsPkt_SetReg_3_001543E0(0x41, gGsPacketBss_002F1420[0]);
    GsPkt_Flush_1_001544C0();
    gHudWarningSbss_002022E0 = (Option_GetByte2_0_001A94A0() == 2) ? 0x2C : 0;
    Hud_DrawCompass_0_001BBCC0();
    if (p->x3A2.m == 1) {
        q = cur();
        if (q != 0 && (q->x3D5 == 3 || q->x3D5 == 4) && D_00222A54[0].f.b2) {
            GsPkt_BeginAD_3_001545D0();
            GsPkt_SetReg_3_001543E0(0x42, 0x48);
            GsPkt_Flush_1_001544C0();
            Hud_DrawQuad_1_001BC610(-8, -8, 8, 8, -0x8000, 1, q->x450);
        }
    } else if (p->x3A2.m == 2) {
        q = cur();
        if (q != 0) {
            c = (u32)(128.0f * (-1.0f * (q->x3D0 / -0.17453293f))) << 24;
            GsPkt_BeginAD_3_001545D0();
            GsPkt_SetReg_3_001543E0(0x42, 0x44);
            GsPkt_Flush_1_001544C0();
            Hud_DrawQuad_1_001BC610(-0x140, -0xE0, 0x140, 0xE0, c, 1, q->x3B0);
        }
    }
    i = p->x3BE;
    if (i != 0) {
        n = i;
        if (n > 12) {
            k = (f32)(func_00120570(n - 15) * 96) / 3.0f;
        } else {
            k = (f32)(n * 96) / 12.0f;
        }
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x48);
        GsPkt_Flush_1_001544C0();
        Hud_DrawQuad_1_001BC610(-0x140, -224.0f + (f32)gHudWarningSbss_002022E0, 0x140, 224.0f - (f32)gHudWarningSbss_002022E0, (k << 24) | 0x80, 1, 0);
    }
    i = PlayerData_GetStatusTimer_0_001CE200(2);
    if (i != 0) {
        t = gHudWarningSdata_00201E28;
        c = t.c[i - 1] << 24;
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x42, 0x44);
        GsPkt_Flush_1_001544C0();
        Hud_DrawQuad_1_001BC610(-0x140, -224.0f + (f32)gHudWarningSbss_002022E0, 0x140, 224.0f - (f32)gHudWarningSbss_002022E0, c, 1, 0);
    }
    Hud_DrawWarning_0_001BC7A0(p->x420, p->x421, p->x422);
}
#undef GsPkt_SetReg_3_001543E0
#undef Hud_DrawWarning_0_001BC7A0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gHudWarningSbss_002022E0 */
s32 gHudWarningSbss_002022E0;
#endif
