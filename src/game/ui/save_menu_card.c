#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/save.h"
#include "game/ui.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
} Obj;
typedef struct {
    u8 pad0[0xC];
    s32 xC;
    s32 arr[8];
} Buf;
extern u8 D_004A0900[][0xF0];
#ifndef NONMATCHING
extern s32 D_004A1058[];
#else
/* data twins (src/game/data/option_bss.c): D_004A1058 */
static s32 D_004A1058[0x1];
#endif
extern f32 D_004A105C[];
void SaveMenu_Load_0_0018DA20(Obj *o);
void SaveMenu_CheckCard_0_0018DFB0(Obj *o);
void SaveMenu_Retry_0_0018E0B0(void *arg0);
void SaveMenu_UpdateCardFlags_1_0018E120(s32 a0, Flags8 *f);
s8* Save_GetSlotInfo_0_00188FF0(s32);
void MenuProc_Set_1_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void MenuProc_Run_1_0018B320(s32 *);
void SaveSys_GetSlotCount_0_001E5E80(Buf *);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 SaveSys_StartWrite_0_001E6170(s32, void *, s32);
void Save_BuildOptions_1_001AB0A0(void *);
void memset(void *, s32, s32);

/* SaveMenu_Load_0_0018DA20 */
#define SaveMenu_UpdateCardFlags_1_0018E120 SaveMenu_UpdateCardFlags_1_0018E120__as_SaveMenu_Load_0_0018DA20
void SaveMenu_UpdateCardFlags_1_0018E120__as_SaveMenu_Load_0_0018DA20(s32, void *);
#define SaveMenu_Retry_0_0018E0B0 SaveMenu_Retry_0_0018E0B0__as_SaveMenu_Load_0_0018DA20
void SaveMenu_Retry_0_0018E0B0__as_SaveMenu_Load_0_0018DA20();
#define SaveMenu_CheckCard_0_0018DFB0 SaveMenu_CheckCard_0_0018DFB0__as_SaveMenu_Load_0_0018DA20
void SaveMenu_CheckCard_0_0018DFB0__as_SaveMenu_Load_0_0018DA20();
static inline s32 start_SaveMenu_Load_0_0018DA20(Obj *o, s32 r) {
    if (r == 1) {
        MenuProc_Set_1_0018B150(D_004A1020, 0x79, 2, SaveMenu_Retry_0_0018E0B0, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A1020);
        o->xA = 1;
        o->xB = 1;
        D_004A1054[0] = 0;
        D_004A1058[0] = 0;
        return 1;
    }
    return 0;
}

void SaveMenu_Load_0_0018DA20(Obj *o) {
    s32 s = 0;
    Buf buf = {0};
    s32 n;
    s32 r;

    n = SaveSys_GetPort_1_001E8290();
    r = SaveSys_IsCardReady_0_001E6110();
    SaveMenu_UpdateCardFlags_1_0018E120(0, D_004A1068);
    SaveMenu_UpdateCardFlags_1_0018E120(1, D_004A106C);
    if (start_SaveMenu_Load_0_0018DA20(o, r)) return;
    switch (D_004A1058[0]) {
    case 0:
        if (SaveSys_StartRead_0_001E5F30(0, 0) == 0) {
            Save_BuildOptions_1_001AB0A0(D_004A0900[n]);
            memset(Save_GetSlotInfo_0_00188FF0(0), 0, 8);
            D_004A1058[0]++;
        }
        break;
    case 1:
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 0) D_004A1058[0]++;
        start_SaveMenu_Load_0_0018DA20(o, s);
        break;
    case 2:
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        if ((buf.arr[0] == 1) | (buf.arr[1] == 1) | (buf.arr[2] == 1) | (buf.arr[3] == 1) | (buf.arr[4] == 1) |
            (buf.arr[5] == 1) | (buf.arr[6] == 1)) {
            if (buf.xC == 1) {
                if (SaveSys_StartWrite_0_001E6170(-1, D_004A0900[n], 0xF0) != -1) D_004A1058[0]++;
            } else {
                D_004A1054[0] = 0;
                D_004A1058[0] = 0;
                D_004A105C[0] = 128.0f;
                MenuStack_Push_1_00189ED0(9);
                o->x8 = 0xB;
                o->x4 = 0;
                o->x0 = 0x1A;
                o->xA = 2;
            }
        } else {
            MenuProc_Set_1_0018B150(D_004A1020, 0x78, 2, SaveMenu_CheckCard_0_0018DFB0, 0, 1.0f);
            MenuProc_Run_1_0018B320(D_004A1020);
            D_004A1054[0] = 0;
            D_004A1058[0] = 0;
        }
        break;
    case 3:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1058[0]++;
        start_SaveMenu_Load_0_0018DA20(o, s);
        break;
    case 4:
        SaveSys_GetSlotCount_0_001E5E80(&buf);
        if (buf.arr[7] == 1) {
            if (SaveSys_StartWrite_0_001E6170(7, Save_GetSlotInfo_0_00188FF0(0), 0xF0) != -1) {
                D_004A1058[0]++;
            } else {
                D_004A1058[0] = 0;
            }
        } else {
            D_004A1058[0]++;
            D_004A1058[0]++;
        }
        break;
    case 5:
        do {
            SaveSys_Update_2_001E8500();
            SaveSys_GetResult_0_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1058[0]++;
        start_SaveMenu_Load_0_0018DA20(o, s);
        break;
    case 6:
        D_004A1058[0]++;
        D_004A105C[0] = 128.0f;
        D_004A1054[0] = 0;
        MenuStack_Push_1_00189ED0(9);
        o->x8 = 0xB;
        o->x4 = 0;
        o->x0 = 0x1A;
        o->xA = 2;
        break;
    case 7:
        if (o->x0 == 0x1E) D_004A1058[0] = 0;
        break;
    }
}
#undef SaveMenu_UpdateCardFlags_1_0018E120
#undef SaveMenu_Retry_0_0018E0B0
#undef SaveMenu_CheckCard_0_0018DFB0

/* SaveMenu_CheckCard_0_0018DFB0 */
#define SaveMenu_UpdateCardFlags_1_0018E120 SaveMenu_UpdateCardFlags_1_0018E120__as_SaveMenu_CheckCard_0_0018DFB0
void SaveMenu_UpdateCardFlags_1_0018E120__as_SaveMenu_CheckCard_0_0018DFB0(s32, void *);
#define SaveMenu_Retry_0_0018E0B0 SaveMenu_Retry_0_0018E0B0__as_SaveMenu_CheckCard_0_0018DFB0
void SaveMenu_Retry_0_0018E0B0__as_SaveMenu_CheckCard_0_0018DFB0();
static inline s32 start_SaveMenu_CheckCard_0_0018DFB0(Obj *o, s32 r) {
    if (r == 1) {
        MenuProc_Set_1_0018B150(D_004A1020, 0x79, 2, SaveMenu_Retry_0_0018E0B0, 0, 1.0f);
        MenuProc_Run_1_0018B320(D_004A1020);
        o->xA = 1;
        o->xB = 1;
        D_004A1054[0] = 0;
        D_004A1058[0] = 0;
        return 1;
    }
    return 0;
}

void SaveMenu_CheckCard_0_0018DFB0(Obj *o) {
    s32 r;

    SaveMenu_UpdateCardFlags_1_0018E120(0, D_004A1068);
    SaveMenu_UpdateCardFlags_1_0018E120(1, D_004A106C);
    r = SaveSys_IsCardReady_0_001E6110();
    SaveMenu_UpdateCardFlags_1_0018E120(0, D_004A1068);
    SaveMenu_UpdateCardFlags_1_0018E120(1, D_004A106C);
    if (!start_SaveMenu_CheckCard_0_0018DFB0(o, r) && (o->x4 & 0x2000)) {
        o->xA = 2;
    }
}
#undef SaveMenu_UpdateCardFlags_1_0018E120
#undef SaveMenu_Retry_0_0018E0B0

/* SaveMenu_Retry_0_0018E0B0 */
#define SaveMenu_UpdateCardFlags_1_0018E120 SaveMenu_UpdateCardFlags_1_0018E120__as_SaveMenu_Retry_0_0018E0B0
int SaveMenu_UpdateCardFlags_1_0018E120__as_SaveMenu_Retry_0_0018E0B0();

void SaveMenu_Retry_0_0018E0B0(void *arg0) {
    SaveMenu_UpdateCardFlags_1_0018E120(NULL, (s32) D_004A1068);
    SaveMenu_UpdateCardFlags_1_0018E120((u8 *)1, (s32) D_004A106C);
    if (M2C_FIELD(arg0, s32 *, 4) & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 2;
        Snd_PlaySe_3_00131600(0x67, (s32) M2C_FIELD(arg0, u8 *, 0xE));
    }
}
#undef SaveMenu_UpdateCardFlags_1_0018E120

/* SaveMenu_UpdateCardFlags_1_0018E120 */
void SaveMenu_UpdateCardFlags_1_0018E120(s32 a0, Flags8 *f) {
    switch (SaveSys_GetCardKind_0_001E60C0(a0)) {
    case 0: f->f.b0 = 1; f->f.b1 = 1; f->f.b2 = 1; break;
    case 1: f->f.b0 = 0; f->f.b1 = 0; f->f.b2 = 0; break;
    case 2: f->f.b0 = 1; f->f.b1 = 0; f->f.b2 = 0; break;
    case 3: break;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_bss.c): D_004A1054, D_004A105C, D_004A1068, D_004A106C */
s32 D_004A1054[0x1];
f32 D_004A105C[0x1];
s32 D_004A1068[0x1];
s32 D_004A106C[0x1];
#endif
