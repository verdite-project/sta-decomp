#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; u8 pad[3]; } E;
typedef struct { s32 sel; s32 x4; s32 x8; f32 xC; s32 x10; s32 x14; E e[2]; } M;
extern M gOptionBss_004A1050;
extern s32 gSaveMenuBss_004A1020[];
void MenuProc_Set_1_0018B150(f32, s32 *, s32, s32, void (*)(s8 *), s32);
void MenuProc_Run_1_0018B320(s32 *);
void Snd_PlaySe_3_00131600(s32, s32);
s32 SaveSys_SetPort_1_001E82A0(s32);
s8 MenuStack_Pop_1_00189EA0(void);
void SaveMenu_Load_0_0018DA20(s8 *);
void SaveMenu_CheckCard_0_0018DFB0(s8 *);
void SaveMenu_Retry_0_0018E0B0(s8 *);

void SaveMenu_SelectDevice_0_0018D7B0(s8 *arg0) {
    s32 b;

    b = *(s32 *)(arg0 + 4);
    if (b & 0x80) {
        gOptionBss_004A1050.sel--;
        if (gOptionBss_004A1050.sel < 0) {
            gOptionBss_004A1050.sel = 1;
        }
        gOptionBss_004A1050.x10 = 0;
        Snd_PlaySe_3_00131600(0x66, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x20) {
        gOptionBss_004A1050.sel++;
        if (gOptionBss_004A1050.sel > 1) {
            gOptionBss_004A1050.sel = 0;
        }
        gOptionBss_004A1050.x10 = 0;
        Snd_PlaySe_3_00131600(0x66, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x2000) {
        if (gOptionBss_004A1050.e[gOptionBss_004A1050.sel].b0) {
            SaveSys_SetPort_1_001E82A0(gOptionBss_004A1050.sel);
            if (gOptionBss_004A1050.e[gOptionBss_004A1050.sel].b1) {
                MenuProc_Set_1_0018B150(1.0f, gSaveMenuBss_004A1020, 0x7A, 0, SaveMenu_Load_0_0018DA20, 0);
                MenuProc_Run_1_0018B320(gSaveMenuBss_004A1020);
                gOptionBss_004A1050.x8 = 0;
                arg0[0xA] = 1;
                arg0[0xB] = 1;
            } else {
                MenuProc_Set_1_0018B150(1.0f, gSaveMenuBss_004A1020, 0x78, 2, SaveMenu_CheckCard_0_0018DFB0, 0);
                MenuProc_Run_1_0018B320(gSaveMenuBss_004A1020);
                gOptionBss_004A1050.x8 = 0;
                arg0[0xA] = 1;
                arg0[0xB] = 1;
            }
        } else {
            MenuProc_Set_1_0018B150(1.0f, gSaveMenuBss_004A1020, gOptionBss_004A1050.sel + 0x81, 2, SaveMenu_Retry_0_0018E0B0, 0);
            MenuProc_Run_1_0018B320(gSaveMenuBss_004A1020);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
        }
        Snd_PlaySe_3_00131600(0x67, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x4000) {
        gOptionBss_004A1050.xC = 128.0f;
        arg0[8] = MenuStack_Pop_1_00189EA0();
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)(arg0 + 0) = 0x1A;
        Snd_PlaySe_3_00131600(0x69, *(u8 *)(arg0 + 0xE));
    }
    *(s32 *)(arg0 + 4) = 0;
}
