#include "common.h"
#include "m2c.h"
#include "game/ui.h"
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 b0:1; } B;
typedef struct { u8 a:3; u8 b:5; } BF;
extern f32 gMessageBss_004A0F58[];
extern B gMessageBss_004A0F5C[];
extern s8 gMessageBss_004A0F60[];
extern f32 D_004A0F74[];
extern u16 gMapCommandBss_00317238[];
#ifndef NONMATCHING
extern s32 gMessageBss_004A0F54[];
extern s32 gMessageSbss_00202118;
extern u8 gMessageBss_004A0B50[];
extern s32 gMessageBss_004A0F64[];
#else
/* data twins (src/game/data/option_bss.c): gMessageBss_004A0F54 */
static s32 gMessageBss_004A0F54[0x1];
/* data twins (src/game/data/sbss.c): gMessageSbss_00202118 */
static s32 gMessageSbss_00202118;
/* data twins (src/game/data/option_bss.c): gMessageBss_004A0B50 */
static u8 gMessageBss_004A0B50[0x404] __attribute__((aligned(4)));
/* data twins (src/game/data/option_bss.c): gMessageBss_004A0F64 */
static s32 gMessageBss_004A0F64[0x1];
#endif
extern BF gMessageBss_004A0F68[];
extern s16 D_004A0F6C[];
extern s32 gMessageBss_004A0F80[];
extern s32 D_004A0F84[];
void Msg_ShowWrap_1_0018AC90(s32 arg0, s32 arg1);
void Msg_SetParam_0_0018AEA0(s32 arg0);
s32 Msg_Show_1_0018AEB0(s32 arg0, s32 arg1);
s32 Text_Render_2_00188010(void *, Col);
void strcpy(void *, s32);
u32 strlen(void *);
void TextParam_Init_1_00187A90(void *, void *, u64);

/* Msg_ShowWrap_1_0018AC90 */
#define Msg_Show_1_0018AEB0 Msg_Show_1_0018AEB0__as_Msg_ShowWrap_1_0018AC90
int Msg_Show_1_0018AEB0__as_Msg_ShowWrap_1_0018AC90();
void Msg_ShowWrap_1_0018AC90(s32 arg0, s32 arg1) {
    Msg_Show_1_0018AEB0(arg0, arg1);
}
#undef Msg_Show_1_0018AEB0

/* Msg_Draw_0_0018ACA0 */
void Msg_Draw_0_0018ACA0(void) {
    Col c3;
    Col c2;
    Col c5;

    switch (gMessageBss_004A0F54[0]) {
    case 3:
        if (gMessageBss_004A0F58[0] > 0.0f) {
            *(u32 *)&c3 = 0x80808080;
            if (gMessageBss_004A0F58[0] < 8.0f) {
                c3.a = (s32)(16.0f * gMessageBss_004A0F58[0]);
            }
            Text_Render_2_00188010(gMessageBss_004A0F60, c3);
            D_004A0F74[0] += 1.0f;
        }
        if (gMessageBss_004A0F58[0] < 0.0f) {
            gMessageBss_004A0F54[0] = 0;
        }
        gMessageBss_004A0F58[0] -= 1.0f;
        break;
    case 2:
        *(u32 *)&c2 = 0x80808080;
        gMessageBss_004A0F5C[0].b0 = Text_Render_2_00188010(gMessageBss_004A0F60, c2);
        gMessageBss_004A0F58[0] -= 1.0f;
        D_004A0F74[0] += 1.0f;
        break;
    case 5:
        *(u32 *)&c5 = 0x80808080;
        gMessageBss_004A0F5C[0].b0 = Text_Render_2_00188010(gMessageBss_004A0F60, c5);
        gMessageBss_004A0F58[0] -= 1.0f;
        D_004A0F74[0] += 1.0f;
        break;
    }
    Menu_DrawBackground_0_00187B20(1);
}

/* Msg_SetParam_0_0018AEA0 */
void Msg_SetParam_0_0018AEA0(s32 arg0) {
    gMessageSbss_00202118 = arg0;
}

/* Msg_Show_1_0018AEB0 */
#define gMessageBss_004A0F5C gMessageBss_004A0F5C__as_Msg_Show_1_0018AEB0
extern u8 gMessageBss_004A0F5C__as_Msg_Show_1_0018AEB0[];
#define gMessageBss_004A0F60 gMessageBss_004A0F60__as_Msg_Show_1_0018AEB0
extern s32 gMessageBss_004A0F60__as_Msg_Show_1_0018AEB0[];

s32 Msg_Show_1_0018AEB0(s32 arg0, s32 arg1) {
    switch (gMessageBss_004A0F54[0]) {
    case 0:
        strcpy(gMessageBss_004A0B50, arg0);
        TextParam_Init_1_00187A90(gMessageBss_004A0F60, gMessageBss_004A0B50, strlen(gMessageBss_004A0B50));
        D_004A0F84[0] = 0x3F800000;
        gMessageBss_004A0F60[0] = 0x43A00000;
        gMessageBss_004A0F64[0] = 0x43A00000;
        gMessageBss_004A0F80[0] = 0x3FA66666;
        D_004A0F6C[0] = 2;
        gMessageBss_004A0F68[0].a = 1;
        if (arg1 > 0) {
            gMessageBss_004A0F54[0] = 3;
            gMessageBss_004A0F58[0] = (f32) arg1;
        } else if (arg1 == -1) {
            gMessageBss_004A0F54[0] = 5;
            gMessageBss_004A0F58[0] = 60.0f;
        } else {
            gMessageBss_004A0F54[0] = 2;
            gMessageBss_004A0F58[0] = 60.0f;
        }
        return 0;
    case 3:
        if (gMessageBss_004A0F58[0] < 0.0f) {
            gMessageBss_004A0F54[0] = 0;
            return 3;
        }
        break;
    case 5:
        if ((gMapCommandBss_00317238[0] & 0x2000) && (gMessageBss_004A0F5C[0] & 1)) {
            return 3;
        }
        break;
    case 2:
        if ((gMapCommandBss_00317238[0] & 0x2000) && (gMessageBss_004A0F5C[0] & 1)) {
            gMessageBss_004A0F54[0] = 3;
            gMessageBss_004A0F58[0] = 8.0f;
        }
        break;
    case 4:
        gMessageBss_004A0F54[0] = 0;
        return 0;
    }
    return 1;
}
#undef gMessageBss_004A0F5C
#undef gMessageBss_004A0F60

/* Msg_Close_1_0018B0C0 */
#define gMessageBss_004A0F58 gMessageBss_004A0F58__as_Msg_Close_1_0018B0C0
extern s32 gMessageBss_004A0F58__as_Msg_Close_1_0018B0C0[];

s32 Msg_Close_1_0018B0C0(void) {
    (*gMessageBss_004A0F54) = 0;
    (*gMessageBss_004A0F58) = 0;
    return 0;
}
#undef gMessageBss_004A0F58

/* Msg_ShowById_1_0018B0E0 */
#define Msg_Show_1_0018AEB0 Msg_Show_1_0018AEB0__as_Msg_ShowById_1_0018B0E0
int Msg_Show_1_0018AEB0__as_Msg_ShowById_1_0018B0E0();
void Msg_ShowById_1_0018B0E0(s32 arg0) {
    Msg_Show_1_0018AEB0(Msg_GetText_2_00195B10(arg0), 0x3C);
}
#undef Msg_Show_1_0018AEB0

/* Msg_GetAlpha_0_0018B110 */
f32 Msg_GetAlpha_0_0018B110(void) {
    if ((*D_004A0FAC) < 0x40) {
        return 0.0f;
    }
    return (f32) (*D_004A0FAC);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/option_bss.c): gMessageBss_004A0F58, gMessageBss_004A0F5C, gMessageBss_004A0F60, gMessageBss_004A0F68, gMessageBss_004A0F80 */
f32 gMessageBss_004A0F58[0x1];
B gMessageBss_004A0F5C[0x4 / sizeof(B)];
s8 gMessageBss_004A0F60[0x4];
BF gMessageBss_004A0F68[0x18 / sizeof(BF)] __attribute__((aligned(4)));
s32 gMessageBss_004A0F80[0x4] __attribute__((aligned(4)));
#endif
