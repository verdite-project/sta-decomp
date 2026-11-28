#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/player.h"
#include "game/ui.h"
#include "game/math.h"
typedef union { u32 w; u8 b[4]; } Col;
typedef union { u128 q[2]; s32 w[8]; f32 f[8]; void *p[8]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; } O;
typedef struct { s32 state; s32 input; s8 b8; s8 b9; u8 pad[4]; u8 bE; } S;
#ifndef NONMATCHING
extern f32 gStorageDrawSdata_00201D90;
#else
/* data twins (src/game/data/sdata.c): gStorageDrawSdata_00201D90 */
static f32 gStorageDrawSdata_00201D90 = -2.99f;
#endif
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A4350[0x4];
extern Q2 gStorageDrawData_001F32F0;
#ifndef NONMATCHING
extern s32 gStorageDrawData_001F32A0[];
#else
/* data twins (src/game/data/title_nop_data.c): gStorageDrawData_001F32A0 */
static s32 gStorageDrawData_001F32A0[0x4] = { 0, 1, 2, 3 };
#endif
void Storage_Draw_0_001A30E0(u8 *arg0);
void Storage_DrawStatus_0_001A31E0(f32 f);
void Storage_Open_0_001A32A0(O *p);
void Storage_Update_0_001A3380(S *arg0);
void StorageProc_Pos_0_001A3500(s32 arg0, void *arg1, void *arg2);
void Text_Draw_2_001875C0(s32, s32, u32, f32, f32, f32);
s32 Msg_GetText_2_00195B10(s32);
s8* PlayerData_Get_2_001C9BA0(void);
s8* Player_GetBodyState_1_001C9B60(void);
void Menu_DrawStatRing_0_00186440(f32, s8 *, s8 *, s8 *, s8 *);
void Menu_DrawRingD_0_00185510(f32, s8 *);
void Menu_DrawRingE_0_00185B40(f32, s8 *);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
void UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Storage_GetEntry_0_001A3560();
void Snd_PlaySe_3_00131600(s32, s32);
void Storage_DrawStatus_0_001A31E0__as_Storage_Draw_0_001A30E0(u8 *, f32);
void Storage_Update_0_001A3380__as_Storage_Open_0_001A32A0(O *);
s32 UiAnim_SetTarget_1_0017F470__as_Storage_Update_0_001A3380(s32, s32, f32);

/* Storage_Draw_0_001A30E0_ */
#define StorageProc_Pos_0_001A3500 StorageProc_Pos_0_001A3500__as_Storage_Draw_0_001A30E0_
void StorageProc_Pos_0_001A3500__as_Storage_Draw_0_001A30E0_();

/* Storage_Draw_0_001A30E0 */

void Storage_Draw_0_001A30E0(u8 *arg0) {
    Col c;

    Menu_SetFlags_0_0018A310(0xC);
    if (!(gStorageDrawSdata_00201D90 <= -2.49f)) {
        Storage_DrawStatus_0_001A31E0__as_Storage_Draw_0_001A30E0(arg0, gStorageDrawSdata_00201D90);
    }
    if (arg0[8] == 0x1F) {
        gStorageDrawSdata_00201D90 = Approachf_3_00187770(gStorageDrawSdata_00201D90, -0.02f, 3.5f);
        c.w = 0x80FFFFFF;
        if (D_004A4350[0] >= 0) {
            Text_Draw_2_001875C0(Msg_GetText_2_00195B10(D_004A4350[0] + 0x8C), 2, *(u32 *)&c, 622.0f, 17.0f, 1.0f);
        }
    } else {
        gStorageDrawSdata_00201D90 = Approachf_3_00187770(gStorageDrawSdata_00201D90, -2.99f, 3.5f);
    }
}

/* Storage_DrawStatus_0_001A31E0 */
void Storage_DrawStatus_0_001A31E0(f32 f) { s8 *p; s8 *q; s8 *a; s8 *b; PlayerData_Get_2_001C9BA0(); a = Player_GetBodyState_1_001C9B60(); b = PlayerData_Get_2_001C9BA0(); if (Player_Exists_3_001C9BF0()) { p = a + 0x460; q = a + 0x470; } else { return; } Menu_DrawStatRing_0_00186440(f, p, q, 0, 0); Menu_DrawRingD_0_00185510(f, b); Menu_SetOffset_0_00185B30(0, 0); Menu_DrawRingE_0_00185B40(f, a); UiAnim_UpdateAll_1_0017F5C0(); Menu_DrawFrame_0_00185390(f, 1, 4, D_004A4350[0]); }

/* Storage_Open_0_001A32A0 */

void Storage_Open_0_001A32A0(O *p) {
    Q2 q;
    Arg a;

    switch (p->x0) {
    case 0x19:
        D_004A4350[0] = 0;
        q = gStorageDrawData_001F32F0;
        a.p = gStorageDrawData_001F32A0;
        a.n = 4;
        a.fn = Storage_GetEntry_0_001A3560;
        a.f = -3.0f;
        a.cb = StorageProc_Pos_0_001A3500;
        a.a = 0;
        a.b = 0;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 1);
        UiAnim_SetTarget_1_0017F470(D_004A4350[0], 0, 1);
        break;
    case 0x16:
        Storage_Update_0_001A3380__as_Storage_Open_0_001A32A0(p);
        break;
    }
}

/* Storage_Update_0_001A3380 */

void Storage_Update_0_001A3380(S *arg0) {
    s32 temp_v1;
    s32 var_s0;

    temp_v1 = arg0->input;
    var_s0 = D_004A4350[0];
    if (temp_v1 & 0x10) {
        var_s0 -= 1;
        if (var_s0 < 0) {
            var_s0 = 3;
        }
    } else if (temp_v1 & 0x40) {
        var_s0 += 1;
        if (var_s0 > 3) {
            var_s0 = 0;
        }
    } else if (temp_v1 & 0x2000) {
        gShopDrawBss_004A3320[0] = var_s0 + 1;
        arg0->b9 = gShopDrawBss_004A3320[0];
        arg0->b8 = 0x22;
        MenuStack_Push_1_00189ED0(0x1F);
        UiAnim_SetVisible_1_0017F7C0(0, 0, 0);
        arg0->input = 0;
        arg0->state = 0x1A;
        Snd_PlaySe_3_00131600(0x69, arg0->bE);
    } else if (temp_v1 & 0x4000) {
        D_004A4350[0] = 0;
        UiAnim_SetVisible_1_0017F7C0(0, 0, 0);
        arg0->b8 = 0x12;
        arg0->input = 0;
        arg0->state = 0x1A;
        Shop_ResetPrices_0_001A2DE0();
        Shop_RecalcPrices_0_001A2EA0();
        Snd_PlaySe_3_00131600(0x65, arg0->bE);
    }
    if (UiAnim_SetTarget_1_0017F470__as_Storage_Update_0_001A3380(0, 0, D_004A4350[0]) != 0) {
        if (D_004A4350[0] != var_s0) {
            Snd_PlaySe_3_00131600(0x66, arg0->bE);
        }
        D_004A4350[0] = var_s0;
    }
    arg0->input = 0;
}
#undef StorageProc_Pos_0_001A3500

/* StorageProc_Pos_0_001A3500 */
void StorageProc_Pos_0_001A3500(s32 arg0, void *arg1, void *arg2) {
    void *sp4C;

    UiAnim_Get_1_0017F840(0, &sp4C);
    M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg2, f32 *, 8) - (f32) arg0);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 gStorageDrawData_001F32B0[];
/* data group (src/game/data/title_nop_data.c): D_001F32F0__grp: gStorageDrawData_001F32F0@0x0 */
s32 D_001F32F0__grp[0x8] __attribute__((aligned(16))) = { 0, 5, 0, (s32)gStorageDrawData_001F32B0, 7, -0x3fc00000, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/title_nop_data.c): gStorageDrawData_001F32B0 */
u8 gStorageDrawData_001F32B0[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
