#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/save.h"
#include "game/ui.h"
typedef struct { s32 v[12]; } Buf;
typedef struct { u8 b[0xF0]; } Ent;
typedef struct { s32 x0; s32 x4; s8 x8; s8 x9; s8 xA; s8 xB; s8 xC; s8 xD; u8 xE; } A;
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; } Obj;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } F;
extern f32 D_004A1168[];
extern Ent D_004A0900[];
void LoadMenu_LoadB_0_001945B0(s8 *arg0);
void LoadMenu_BackB_0_00194B90(A *a);
void LoadMenu_CheckCardB_0_00194C20(Obj *o);
void LoadMenu_RetryB_0_00194D20(void *arg0);
void LoadMenu_UpdateCardFlags_1_00194D90(s32 a, F *f);
void MenuProc_Set_1_0018B150(f32, s32 *, s32, s32, void (*)(s8 *), s32);
void MenuProc_Run_1_0018B320(s32 *);
void SaveSys_GetResult_0_001E6080(s32 *);
void SaveSys_GetSlotCount_0_001E5E80(Buf *);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
s32 SaveSys_StartWrite_0_001E6170(s32, void *, s32);
s8* Save_GetSlotInfo_0_00188FF0(s32);
void Save_BuildOptions_1_001AB0A0(Ent *);
void memset(void *, s32, s32);
void Snd_PlaySe_3_00131600(s32 a, u8 b);
s8 MenuStack_Pop_1_00189EA0(s32);

/* LoadMenu_LoadB_0_001945B0 */
#define LoadMenu_UpdateCardFlags_1_00194D90 LoadMenu_UpdateCardFlags_1_00194D90__as_LoadMenu_LoadB_0_001945B0
void LoadMenu_UpdateCardFlags_1_00194D90__as_LoadMenu_LoadB_0_001945B0(s32, s32 *);
#define LoadMenu_RetryB_0_00194D20 LoadMenu_RetryB_0_00194D20__as_LoadMenu_LoadB_0_001945B0
void LoadMenu_RetryB_0_00194D20__as_LoadMenu_LoadB_0_001945B0(s8 *);
#define LoadMenu_CheckCardB_0_00194C20 LoadMenu_CheckCardB_0_00194C20__as_LoadMenu_LoadB_0_001945B0
void LoadMenu_CheckCardB_0_00194C20__as_LoadMenu_LoadB_0_001945B0(s8 *);

void LoadMenu_LoadB_0_001945B0(s8 *arg0) {
    s32 r = 0;
    Buf buf = {0};
    s32 idx;
    s32 st;
    s32 done;

    idx = SaveSys_GetPort_1_001E8290();
    st = SaveSys_IsCardReady_0_001E6110();
    LoadMenu_UpdateCardFlags_1_00194D90(0, gLoadMenuBss_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, gLoadMenuBss_004A119C);
    if (st == 1) {
        MenuProc_Set_1_0018B150(1.0f, gLoadMenuBss_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
        MenuProc_Run_1_0018B320(gLoadMenuBss_004A1150);
        arg0[0xA] = 1;
        arg0[0xB] = 1;
        gLoadMenuBss_004A1184[0] = 0;
        gLoadMenuBss_004A1188[0] = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done) return;
    switch (gLoadMenuBss_004A1188[0]) {
    case 0:
        if (SaveSys_StartRead_0_001E5F30(0, 0) == 0) {
            Save_BuildOptions_1_001AB0A0(&D_004A0900[idx]);
            memset(Save_GetSlotInfo_0_00188FF0(0), 0, 8);
            gLoadMenuBss_004A1188[0]++;
        }
        break;
    case 1:
        SaveSys_GetResult_0_001E6080(&r);
        if (r == 0) {
            gLoadMenuBss_004A1188[0]++;
        }
        if (r == 1) {
            MenuProc_Set_1_0018B150(1.0f, gLoadMenuBss_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
            MenuProc_Run_1_0018B320(gLoadMenuBss_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            gLoadMenuBss_004A1184[0] = 0;
            gLoadMenuBss_004A1188[0] = 0;
        }
        break;
    case 2:
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        if (!((buf.v[0] != 0) | (buf.v[1] != 0) | (buf.v[2] != 0) | (buf.v[3] != 0) | (buf.v[4] != 0) | (buf.v[5] != 0) |
              (buf.v[6] != 0) | (buf.v[7] != 0) | (buf.v[8] != 0) | (buf.v[9] != 0) | (buf.v[10] != 0)) &&
            SaveSys_GetCurSlotState_0_001E6060() < 0x6F) {
            MenuProc_Set_1_0018B150(0.9f, gLoadMenuBss_004A1150, idx + 0x85, 2, LoadMenu_CheckCardB_0_00194C20, 0);
            D_004A1168[0] = -20.0f;
            MenuProc_Run_1_0018B320(gLoadMenuBss_004A1150);
            gLoadMenuBss_004A1184[0] = 0;
            gLoadMenuBss_004A1188[0] = 0;
        } else if (buf.v[3] == 1) {
            if (SaveSys_StartWrite_0_001E6170(-1, &D_004A0900[idx], 0xF0) != -1) {
                gLoadMenuBss_004A1188[0]++;
            } else {
                gLoadMenuBss_004A1188[0] = 0;
            }
        } else {
            gLoadMenuBss_004A1184[0] = 0;
            gLoadMenuBss_004A1188[0] = 0;
            gLoadMenuBss_004A118C[0] = 128.0f;
            MenuStack_Push_1_00189ED0(10);
            arg0[8] = 12;
            *(s32 *)(arg0 + 4) = 0;
            *(s32 *)arg0 = 0x1A;
            arg0[0xA] = 2;
        }
        break;
    case 3:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&r);
        } while (r == 2);
        if (r == 0) {
            gLoadMenuBss_004A1188[0]++;
        }
        if (r == 1) {
            MenuProc_Set_1_0018B150(1.0f, gLoadMenuBss_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
            MenuProc_Run_1_0018B320(gLoadMenuBss_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            gLoadMenuBss_004A1184[0] = 0;
            gLoadMenuBss_004A1188[0] = 0;
        }
        break;
    case 4:
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        if (buf.v[11] == 1) {
            if (SaveSys_StartWrite_0_001E6170(7, Save_GetSlotInfo_0_00188FF0(0), 8) != -1) {
                gLoadMenuBss_004A1188[0]++;
            } else {
                gLoadMenuBss_004A1188[0] = 0;
            }
        } else {
            gLoadMenuBss_004A1188[0]++;
            gLoadMenuBss_004A1188[0]++;
        }
        break;
    case 5:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&r);
        } while (r == 2);
        if (r == 0) {
            gLoadMenuBss_004A1188[0]++;
        }
        if (r == 1) {
            MenuProc_Set_1_0018B150(1.0f, gLoadMenuBss_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
            MenuProc_Run_1_0018B320(gLoadMenuBss_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            gLoadMenuBss_004A1184[0] = 0;
            gLoadMenuBss_004A1188[0] = 0;
        }
        break;
    case 6:
        gLoadMenuBss_004A1188[0]++;
        gLoadMenuBss_004A118C[0] = 128.0f;
        gLoadMenuBss_004A1184[0] = 0;
        MenuStack_Push_1_00189ED0(10);
        arg0[8] = 12;
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)arg0 = 0x1A;
        arg0[0xA] = 2;
        break;
    case 7:
        if (*(s32 *)arg0 == 0x1E) {
            gLoadMenuBss_004A1188[0] = 0;
        }
        break;
    }
}
#undef LoadMenu_UpdateCardFlags_1_00194D90
#undef LoadMenu_RetryB_0_00194D20
#undef LoadMenu_CheckCardB_0_00194C20

/* LoadMenu_BackB_0_00194B90 */
void LoadMenu_BackB_0_00194B90(A *a) {
    s32 f = a->x4;
    if (f & 0x2000) {
        a->x8 = MenuStack_Pop_1_00189EA0(f);
        a->x4 = 0;
        a->x0 = 0x1A;
        gLoadMenuBss_004A118C[0] = 128.0f;
        a->xA = 2;
        Snd_PlaySe_3_00131600(0x69, a->xE);
    } else if (f & 0x4000) {
        a->xA = 2;
        Snd_PlaySe_3_00131600(0x68, a->xE);
    }
}

/* LoadMenu_CheckCardB_0_00194C20 */
#define MenuProc_Set_1_0018B150 MenuProc_Set_1_0018B150__as_LoadMenu_CheckCardB_0_00194C20
void MenuProc_Set_1_0018B150__as_LoadMenu_CheckCardB_0_00194C20(f32, s32 *, s32, s32, void (*)(), s32);
#define LoadMenu_UpdateCardFlags_1_00194D90 LoadMenu_UpdateCardFlags_1_00194D90__as_LoadMenu_CheckCardB_0_00194C20
void LoadMenu_UpdateCardFlags_1_00194D90__as_LoadMenu_CheckCardB_0_00194C20(s32, s32 *);
#define LoadMenu_RetryB_0_00194D20 LoadMenu_RetryB_0_00194D20__as_LoadMenu_CheckCardB_0_00194C20
void LoadMenu_RetryB_0_00194D20__as_LoadMenu_CheckCardB_0_00194C20();

void LoadMenu_CheckCardB_0_00194C20(Obj *o) {
    s32 st;
    s32 r;
    LoadMenu_UpdateCardFlags_1_00194D90(0, gLoadMenuBss_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, gLoadMenuBss_004A119C);
    st = SaveSys_IsCardReady_0_001E6110();
    LoadMenu_UpdateCardFlags_1_00194D90(0, gLoadMenuBss_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90(1, gLoadMenuBss_004A119C);
    if (st == 1) {
        MenuProc_Set_1_0018B150(1.0f, gLoadMenuBss_004A1150, 0x79, 2, LoadMenu_RetryB_0_00194D20, 0);
        MenuProc_Run_1_0018B320(gLoadMenuBss_004A1150);
        r = 1;
        o->xA = 1;
        o->xB = 1;
        gLoadMenuBss_004A1184[0] = 0;
        gLoadMenuBss_004A1188[0] = 0;
    } else {
        r = 0;
    }
    if (r == 0 && (o->x4 & 0x2000)) {
        o->xA = 2;
    }
}
#undef MenuProc_Set_1_0018B150
#undef LoadMenu_UpdateCardFlags_1_00194D90
#undef LoadMenu_RetryB_0_00194D20

/* LoadMenu_RetryB_0_00194D20 */
#define LoadMenu_UpdateCardFlags_1_00194D90 LoadMenu_UpdateCardFlags_1_00194D90__as_LoadMenu_RetryB_0_00194D20
int LoadMenu_UpdateCardFlags_1_00194D90__as_LoadMenu_RetryB_0_00194D20();
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_LoadMenu_RetryB_0_00194D20
int Snd_PlaySe_3_00131600__as_LoadMenu_RetryB_0_00194D20();

void LoadMenu_RetryB_0_00194D20(void *arg0) {
    LoadMenu_UpdateCardFlags_1_00194D90(NULL, (s32) gLoadMenuBss_004A1198);
    LoadMenu_UpdateCardFlags_1_00194D90((u8 *)1, (s32) gLoadMenuBss_004A119C);
    if (M2C_FIELD(arg0, s32 *, 4) & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 2;
        Snd_PlaySe_3_00131600(0x67, (s32) M2C_FIELD(arg0, u8 *, 0xE));
    }
}
#undef LoadMenu_UpdateCardFlags_1_00194D90
#undef Snd_PlaySe_3_00131600

/* LoadMenu_UpdateCardFlags_1_00194D90 */
void LoadMenu_UpdateCardFlags_1_00194D90(s32 a, F *f) {
    switch (SaveSys_GetCardKind_0_001E60C0(a)) {
    case 0:
        f->b0 = 1; f->b1 = 1; f->b2 = 1;
        break;
    case 1:
        f->b0 = 0; f->b1 = 0; f->b2 = 0;
        break;
    case 2:
        f->b0 = 1; f->b1 = 0; f->b2 = 0;
        break;
    case 3:
        break;
    }
}
