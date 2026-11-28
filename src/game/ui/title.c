#include "common.h"
#include "m2c.h"
#include "game/core.h"
#include "game/save.h"
#include "game/ui.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 x9; u8 xA; u8 xB; } P_Title_LoadGame_0_001A35B0;
typedef struct { s32 x0; u32 flags; char p8[2]; u8 bA; char pB[3]; u8 bE; } Obj_Title_LoadGame_0_001A35B0;
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 idx; u8 pad4[0x38]; u8 c0, c1, c2, c3; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[0x8]; List *list; } Res;
typedef struct { s32 st; s32 fl; s8 x8; } S;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 r:5; } F;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad[5]; u8 xE; } P_TitleMenu_Update_1_001A4010;
typedef struct { u128 q[2]; } Q2;
typedef UiArg Arg;
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 p:5; u8 v:1; } BF5;
typedef struct { s32 pad[4]; s32 f10[7]; s32 pad2[1]; } St;
typedef struct { s32 x0; s32 x4; u8 b8; char p9[3]; u8 bC; } Obj_Title_CheckSaveData_1_001A4570;
#ifndef NONMATCHING
extern s32 D_00202250;
#else
/* data twins (src/game/data/sbss.c): D_00202250 */
static s32 D_00202250;
#endif
#ifndef NONMATCHING
extern s32 D_00202258;
#else
/* data twins (src/game/data/sbss.c): D_00202258 */
static s32 D_00202258;
#endif
#ifndef NONMATCHING
extern s32 D_00202254;
#else
/* data twins (src/game/data/sbss.c): D_00202254 */
static s32 D_00202254;
#endif
#ifndef NONMATCHING
extern f32 D_00201D9C;
#else
/* data twins (src/game/data/sdata.c): D_00201D9C */
static f32 D_00201D9C = 30.0f;
#endif
#ifndef NONMATCHING
extern s32 D_0020223C;
#else
/* data twins (src/game/data/sbss.c): D_0020223C */
static s32 D_0020223C;
#endif
#ifndef NONMATCHING
extern s32 D_00202260;
#else
/* data twins (src/game/data/sbss.c): D_00202260 */
static s32 D_00202260;
#endif
#ifndef NONMATCHING
extern s32 D_0020225C;
#else
/* data twins (src/game/data/sbss.c): D_0020225C */
static s32 D_0020225C;
#endif
#ifndef NONMATCHING
extern s32 D_0020224C;
#else
/* data twins (src/game/data/sbss.c): D_0020224C */
static s32 D_0020224C;
#endif
#ifndef NONMATCHING
extern s32 D_00202248;
#else
/* data twins (src/game/data/sbss.c): D_00202248 */
static s32 D_00202248;
#endif
#ifndef NONMATCHING
extern s32 D_00202244;
#else
/* data twins (src/game/data/sbss.c): D_00202244 */
static s32 D_00202244;
#endif
#ifndef NONMATCHING
extern s32 D_00202240;
#else
/* data twins (src/game/data/sbss.c): D_00202240 */
static s32 D_00202240;
#endif
#ifndef NONMATCHING
extern s32 D_00201D94;
#else
/* data twins (src/game/data/sdata.c): D_00201D94 */
static s32 D_00201D94 = -1;
#endif
#ifndef NONMATCHING
extern f32 D_00201D98;
#else
/* data twins (src/game/data/sdata.c): D_00201D98 */
static f32 D_00201D98 = -20.0f;
#endif
#ifndef NONMATCHING
extern s32 D_004A4360[];
#else
/* data twins (src/game/data/shop_bss_004A4360.c): D_004A4360 */
static s32 D_004A4360[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004A4364[];
#else
/* data twins (src/game/data/shop_bss_004A4360.c): D_004A4364 */
static s32 D_004A4364[0x1];
#endif
#ifndef NONMATCHING
extern void *D_004A4368[];
#else
/* data twins (src/game/data/shop_bss_004A4360.c): D_004A4368 */
static void *D_004A4368[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004A436C[];
#else
/* data twins (src/game/data/shop_bss_004A4360.c): D_004A436C */
static s32 D_004A436C[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_004A4370[];
#else
/* data twins (src/game/data/shop_bss_004A4360.c): D_004A4370 */
static f32 D_004A4370[0x1];
#endif
extern f32 D_004A4378[];
extern s32 gStrCdrom0TargetOpeningPss1_001FD870[];
#ifndef NONMATCHING
extern Vec D_001F3310;
#else
/* data twins (src/game/data/title_nop_data.c): D_001F3310 */
static Vec D_001F3310 = { 0.0f, 0.0f, 639.0f, 447.0f };
#endif
#ifndef NONMATCHING
extern f32 D_00202264;
#else
/* data twins (src/game/data/sbss.c): D_00202264 */
static f32 D_00202264;
#endif
#ifndef NONMATCHING
extern s32 D_004A4390[];
#else
/* data twins (src/game/data/save_byte_bss.c): D_004A4390 */
static s32 D_004A4390[0x1] __attribute__((aligned(16)));
#endif
extern struct { unsigned char : 2; unsigned char f : 1; char pad[15]; } D_004A43AC;
#ifndef NONMATCHING
extern s32 D_004A4394[];
#else
/* data twins (src/game/data/save_byte_bss.c): D_004A4394 */
static s32 D_004A4394[0x1];
#endif
extern u8 D_004A43A2[];
extern s32 gStrNewGame_001F3380[];
extern s32 gStrLoadGame_001F3390[];
#ifndef NONMATCHING
extern f32 D_004A4398[];
#else
/* data twins (src/game/data/save_byte_bss.c): D_004A4398 */
static f32 D_004A4398[0x2];
#endif
extern Q2 D_001F3360;
#ifndef NONMATCHING
extern s8 D_001FD890[];
#else
/* data twins (src/game/data/title_rodata.c): D_001FD890 */
static s8 D_001FD890[0x1d] = "\\TARGET\\STA_TI.ADX\000\000\000\000\000\000\000\000\000\000\000";
#endif
extern s32 D_00201DA0;
extern s16 D_004A43A0[];
extern BF3 D_004A43AC__as_TitleMenu_Open_1_001A4420[];
extern F D_004A43AC__as_TitleMenu_Update_1_001A4010_[];
#ifndef NONMATCHING
extern s32 D_0020226C;
#else
/* data twins (src/game/data/sbss.c): D_0020226C */
static s32 D_0020226C;
#endif
#ifndef NONMATCHING
extern s32 D_00202268;
#else
/* data twins (src/game/data/sbss.c): D_00202268 */
static s32 D_00202268;
#endif
extern s32 D_001FD8D0[];
#ifndef NONMATCHING
extern s32 D_00202270;
#else
/* data twins (src/game/data/sbss.c): D_00202270 */
static s32 D_00202270;
#endif
void Title_LoadGame_0_001A35B0(P_Title_LoadGame_0_001A35B0 *p);
void TitleProc_Back_0_001A3B60(Obj_Title_LoadGame_0_001A35B0 *o);
void Title_PlayOpening_2_001A3C10(void *arg0);
void Title_ResetOnEvent_0_001A3C70(void *arg0);
void Title_UpdateWrap_0_001A3EB0(s32 arg0);
void Title_HandleEvent_0_001A3EC0(S *s);
void Title_Reset_0_001A3F80(void);
void TitleMenu_Update_1_001A4010(s32 *arg0);
s32* TitleMenu_GetLabel_2_001A4050(s32 arg0);
void TitleMenu_Select_1_001A40A0(P_TitleMenu_Update_1_001A4010 *p);
void TitleMenu_Open_1_001A4420(s32 *arg0);
s32 Title_CheckSaveData_1_001A4570(void);
void Title_PlayPrologue_2_001A4890(void *arg0);
void Title_StartNewGame_0_001A4930(Obj_Title_CheckSaveData_1_001A4570 *o);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 Menu_GetStateBuf_0_00189000(s32);
void Save_ParseOptions_1_001A8B90(s32);
void Menu_SaveOptions_1_0018E460(void);
void MenuProc_Run_1_0018B320(s32 *);
void Snd_PlaySe_3_00131600(s32 a, u8 b);
void TitleProc_Back_0_001A3B60__as_Title_LoadGame_0_001A35B0(void);
Res* MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawSpriteRotated_1_00182080(s32, f32, Vec *, Vec *, Col *, s32);
void Ui_DrawElem_1_00182C10(Item *, s32);
s32 Title_Reset_0_001A3F80__as_Title_ResetOnEvent_0_001A3C70();
s32 Title_HandleEvent_0_001A3EC0__as_Title_UpdateWrap_0_001A3EB0();
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
void Strm_PlayFile_2_00130590(s32, s32, s32);
s32 TitleMenu_Open_1_001A4420__as_TitleMenu_Update_1_001A4010();
s32 TitleMenu_Select_1_001A40A0__as_TitleMenu_Update_1_001A4010();
void SaveSys_SetPort_1_001E82A0__as_Title_LoadGame_0_001A35B0_(s32);
void SaveSys_GetSlotCount_0_001E5E80(St *);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
s32 SaveSys_StartWrite_0_001E6170(s32, s8 *, s32);
s8* Save_GetSlotInfo_0_00188FF0(s32);
s64 Strm_GetParam_0_001303C0(s32);

/* Title_LoadGame_0_001A35B0__ */
/* Title_LoadGame_0_001A35B0_ */

/* Title_LoadGame_0_001A35B0_ */
/* Title_LoadGame_0_001A35B0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A4374[0x7] __attribute__((aligned(4)));
static inline void go(void) {
    D_0020223C = 0x1E;
    if (D_0020224C) {
        SaveSys_SetPort_1_001E82A0__as_Title_LoadGame_0_001A35B0_(1);
        return;
    }
    if (D_00202248) {
        SaveSys_SetPort_1_001E82A0__as_Title_LoadGame_0_001A35B0_(0);
        return;
    }
    D_0020223C = 0x63;
}

void Title_LoadGame_0_001A35B0(P_Title_LoadGame_0_001A35B0 *p) {
    s32 r;
    s32 v;

    if (p->x0 == 0x19) {
        D_00202250 = 0;
        D_00202258 = 5;
        D_00202254 = 0;
        D_00201D9C = 30.0f;
        D_0020223C = 0;
        D_00202260 = 0;
        D_0020225C = 0;
    }
    switch (D_0020223C) {
    case 0:
        D_0020223C = 1;
        D_0020224C = 0;
        D_00201D9C = 30.0f;
        D_00202248 = 0;
        D_00202244 = 0;
        D_00202240 = 0;
        break;
    case 1:
        v = Movie_Stop_0_00180110();
        if (D_00201D9C < 0.0f) {
            if (v == 0) {
                D_0020223C = 10;
            } else {
                D_0020223C = 2;
            }
        } else {
            D_00201D9C -= 1.0f;
        }
        break;
    case 2:
        if ((Movie_Stop_0_00180110() & 0xF) == 3) {
            D_0020223C = 3;
        } else {
            D_0020223C = 4;
        }
        break;
    case 3:
        v = Movie_Update_0_001801F0(0);
        if (v > 0) {
            D_0020223C = 4;
            D_00202240 = (v & 2) != 0;
            D_00202248 = (v & 4) != 0;
        }
        break;
    case 4:
        if ((Movie_Stop_0_00180110() & 0xF0) == 0x30) {
            D_0020223C = 5;
        } else {
            D_0020223C = 6;
        }
        break;
    case 5:
        v = Movie_Update_0_001801F0(1);
        if (v > 0) {
            D_0020223C = 6;
            D_00202244 = (v & 2) != 0;
            D_0020224C = (v & 4) != 0;
        }
        break;
    case 6:
        v = Movie_Stop_0_00180110();
        if ((v & 0xF) == 1 || (v & 0xF0) == 0x10) {
            go();
        } else if (D_00202240 || D_00202244) {
            go();
        } else if ((!SaveSys_GetCardKind_0_001E60C0(0) && SaveSys_GetSlotState_0_001E6040(0) > 0x6E) || (!SaveSys_GetCardKind_0_001E60C0(1) && SaveSys_GetSlotState_0_001E6040(1) > 0x6E)) {
            go();
        } else {
            D_00201D94 = 0x7D;
            D_00201D98 = -20.0f;
            if (!SaveSys_GetCardKind_0_001E60C0(1) && SaveSys_GetSlotState_0_001E6040(1) < 0x6F) {
                D_00201D94 = 0x84;
            }
            if (!SaveSys_GetCardKind_0_001E60C0(0) && SaveSys_GetSlotState_0_001E6040(0) < 0x6F) {
                if (D_00201D94 == 0x84) {
                    D_00201D94 = 0x87;
                    D_00201D98 = -35.0f;
                } else {
                    D_00201D94 = 0x83;
                }
            }
            D_0020223C = 0x14;
        }
        break;
    case 10:
        D_004A436C[0] = 0;
        D_004A4374[0] = 0;
        D_004A4360[0] = 0x7D;
        D_004A4364[0] = 4;
        D_004A4368[0] = TitleProc_Back_0_001A3B60__as_Title_LoadGame_0_001A35B0;
        D_004A4370[0] = 0.7916667f;
        D_004A4378[0] = -20.0f;
        MenuProc_Run_1_0018B320(D_004A4360);
        p->xB = 1;
        p->xA = 1;
        D_00202258 = 5;
        break;
    case 0x14:
        D_004A436C[0] = 0;
        D_004A4374[0] = 0;
        D_004A4364[0] = 4;
        D_004A4360[0] = D_00201D94;
        D_004A4368[0] = TitleProc_Back_0_001A3B60__as_Title_LoadGame_0_001A35B0;
        D_004A4370[0] = 0.8f;
        D_004A4378[0] = D_00201D98;
        MenuProc_Run_1_0018B320(D_004A4360);
        p->xB = 1;
        p->xA = 1;
        D_00202258 = 5;
        break;
    case 0x1E:
        D_0020223C = 0x63;
        break;
    case 0x1F:
        SaveSys_GetResult_0_001E6080(&r);
        if (r == 0) {
            Save_ParseOptions_1_001A8B90(Menu_GetStateBuf_0_00189000(1));
            D_0020223C = 0x63;
        }
        Menu_SaveOptions_1_0018E460();
        if (r == 1) {
            D_0020223C = 0x63;
        }
        break;
    default:
    case 0x63:
        p->x8 = 3;
        p->x4 = 0;
        p->x0 = 0x1F;
        break;
    }
}

/* TitleProc_Back_0_001A3B60 */
void TitleProc_Back_0_001A3B60(Obj_Title_LoadGame_0_001A35B0 *o)
{
    if (o->flags & 0x2000) {
        D_00202250 = 0;
        D_0020225C = 1;
        D_00202258 = -5;
        D_0020223C = 99;
        o->bA = 2;
        Snd_PlaySe_3_00131600(0x69, o->bE);
    } else if (o->flags & 0x4000) {
        Snd_PlaySe_3_00131600(0x68, o->bE);
        D_00202250 = 0;
        D_00202260 = 1;
        D_00202258 = -5;
        o->bA = 2;
        D_0020223C = 0;
    }
    o->flags = 0;
}

/* Title_PlayOpening_2_001A3C10 */
/* Title_PlayOpening_2_001A3C10 */
void Title_PlayOpening_2_001A3C10(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        GsPkt_EndLayer_1_00155900();
        Movie_Play_2_0017FF70((s32) gStrCdrom0TargetOpeningPss1_001FD870);
        GsPkt_SetLayer_1_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
    }
}

/* Title_ResetOnEvent_0_001A3C70 */
void Title_ResetOnEvent_0_001A3C70(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0x16) {
        Title_Reset_0_001A3F80__as_Title_ResetOnEvent_0_001A3C70();
        M2C_FIELD(arg0, s8 *, 8) = 5;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x1F;
    }
}

/* Title_DrawLogo_0_001A3CC0 */
void Title_DrawLogo_0_001A3CC0(void) {
    u32 i;
    List *l;
    s32 base;
    f32 t;

    l = MenuLayout_Get_1_00189050(3)->list;
    base = MenuLayout_GetSub_1_00189020(3);
    {
    Vec a = D_001F3310;
    Vec b = {0};
    Col col;
    col.c.r = col.c.g = col.c.b = 2;
    col.c.a = 0xFF;
    Ui_DrawSpriteRotated_1_00182080(0, 0.0f, &a, &b, &col, 0);
    }
    for (i = 0; i < l->n; i++) {
        l->items[i].c2 = 0xFF;
        l->items[i].c1 = 0xFF;
        l->items[i].c0 = 0xFF;
        t = 30.0f;
        if (D_00202264 < t) {
            l->items[i].c3 = (s32)(127.0f - 127.0f * (t - D_00202264) / t);
        } else if (!(D_00202264 <= 150.0f)) {
            l->items[i].c3 = 0;
        } else if (!(D_00202264 < 120.0f)) {
            l->items[i].c3 = (s32)(127.0f - 127.0f * (D_00202264 - 120.0f) / t);
        }
        Ui_DrawElem_1_00182C10(&l->items[i], base + l->items[i].idx * 8);
    }
}

/* Title_UpdateWrap_0_001A3EB0 */
void Title_UpdateWrap_0_001A3EB0(s32 arg0) {
    Title_HandleEvent_0_001A3EC0__as_Title_UpdateWrap_0_001A3EB0((void *) arg0);
}

/* Title_HandleEvent_0_001A3EC0 */
void Title_HandleEvent_0_001A3EC0(S *s) {
    switch (s->st) {
    case 25:
        D_00202264 = 0.0f;
        break;
    case 27:
    case 0:
        break;
    case 22:
        if (!(D_00202264 < 150.0f)) {
            s->x8 = 4;
            s->fl = 0;
            s->st = 26;
        }
        D_00202264 += 1.0f;
        break;
    case 26:
    case 28:
    case 30:
        break;
    }
    if (s->fl & 8) {
        s->x8 = 4;
        s->fl = 0;
        s->st = 26;
    }
}

/* Title_Reset_0_001A3F80 */
void Title_Reset_0_001A3F80(void)
{
    D_004A4390[0] = 0;
    D_004A43AC.f = 1;
}

/* Title_Draw_0_001A3FB0 */
void Title_Draw_0_001A3FB0(void) {
    if ((*D_004A4394) == 2) {
        if ((*D_004A43A2) == 0xD) {
            goto block_3;
        }
    } else {
block_3:
        Menu_SetFlags_0_0018A310(4);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawBackground_0_00187B20(0);
}

/* TitleMenu_Update_1_001A4010_ */

/* TitleMenu_Update_1_001A4010 */
void TitleMenu_Update_1_001A4010(s32 *arg0) {
    TitleMenu_Open_1_001A4420__as_TitleMenu_Update_1_001A4010(arg0);
    if (*arg0 == 0x16) {
        TitleMenu_Select_1_001A40A0__as_TitleMenu_Update_1_001A4010(arg0);
    }
}

/* TitleMenu_GetLabel_2_001A4050 */
/* TitleMenu_GetLabel_2_001A4050 */
s32 *TitleMenu_GetLabel_2_001A4050(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return gStrNewGame_001F3380;
    case 1:
        return gStrLoadGame_001F3390;
    default:
        return NULL;
    }
}

/* TitleMenu_Select_1_001A40A0 */
void TitleMenu_Select_1_001A40A0(P_TitleMenu_Update_1_001A4010 *p) {
    s32 cur;
    s32 old;
    s32 r;
    u8 c;

    if (D_004A4394[0] == 0) {
        if (D_004A43AC__as_TitleMenu_Update_1_001A4010_[0].b2) {
            r = Title_CheckSaveData_1_001A4570();
            if (r == 0) return;
            if (r >= 0 && (r & 2)) {
                D_004A4390[0] = 1;
                D_004A43AC__as_TitleMenu_Update_1_001A4010_[0].b0 = 1;
            } else {
                D_004A43AC__as_TitleMenu_Update_1_001A4010_[0].b0 = 0;
            }
            D_004A4394[0] = 1;
            if (D_004A43AC__as_TitleMenu_Update_1_001A4010_[0].b0) D_004A4390[0] = 1;
            SaveSys_SetPort_1_001E82A0(0);
            UiAnim_SetTarget_1_0017F470(0.0f, 0, 1);
        } else {
            D_004A4394[0] = 1;
            UiAnim_SetTarget_1_0017F470(0.0f, 0, 1);
        }
    }
    if (D_004A4394[0] == 1) {
        old = cur = D_004A4390[0];
        if (!(D_004A4398[0] <= 30.0f) && (p->x4 & 0x2008)) {
            switch (cur) {
            case 0:
                if (UiAnim_SetTarget_1_0017F470(-3.0f, 0, 1)) {
                    D_004A43AC__as_TitleMenu_Update_1_001A4010_[0].b1 = 1;
                    Snd_PlaySe_3_00131600(0x69, p->xE);
                    D_004A43A2[0] = 7;
                    D_004A4394[0] = 2;
                }
                break;
            case 1:
                if (UiAnim_SetTarget_1_0017F470(-3.0f, 0, 1)) {
                    Snd_PlaySe_3_00131600(0x69, p->xE);
                    D_004A43A2[0] = 9;
                    D_004A4394[0] = 2;
                    Loading_SetVisible_0_0018E470(1);
                }
                break;
            }
            D_004A4398[0] = 0.0f;
            return;
        }
        if (p->x4 & 0x10) {
            cur--;
            p->x4 &= ~0x10;
        } else if (p->x4 & 0x40) {
            cur++;
            p->x4 &= ~0x40;
        }
        if (!UiAnim_SetTarget_1_0017F470(*(volatile s32 *)D_004A4390, 0, 0)) {
            D_004A4390[0] = old;
        } else {
            if (cur != D_004A4390[0]) {
                Snd_PlaySe_3_00131600(0x66, p->xE);
            }
            D_004A4390[0] = (cur + 2) % 2;
        }
    }
    D_004A4398[0] += 1.0f;
    if (D_004A4394[0] == 2) {
        c = D_004A43A2[0];
        if (D_004A4398[0] < 5.0f) return;
        p->x8 = c;
        if (*(volatile u8 *)D_004A43A2 == 7) {
            Loading_SetVisible_0_0018E470(1);
            MenuStack_Push_1_00189ED0(7);
            p->x8 = 0xD;
        } else {
            MenuStack_Push_1_00189ED0(6);
        }
        p->x4 = 0;
        p->x0 = 0x1A;
    }
}

/* TitleMenu_Open_1_001A4420 */

void TitleMenu_Open_1_001A4420(s32 *arg0) {
    Q2 q;
    Arg a;

    switch (*arg0) {
    case 25:
        D_004A4398[0] = 0;
        D_004A4394[0] = 0;
        if (((BF5 *)((s8 *)arg0 + 0x14))->v) {
            D_004A43A0[0] = 0;
        } else {
            D_004A43A0[0] = 0x7F;
        }
        D_004A43AC__as_TitleMenu_Open_1_001A4420[0].v = 0;
        q = D_001F3360;
        a.p = (s32)&D_00201DA0; a.n = 2; a.fn = TitleMenu_GetLabel_2_001A4050; a.f = -3.0f; a.a = 0; a.b = 0; a.cb = 0;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 1);
        Strm_PlayFile_2_00130590((s32)D_001FD890, 0, 1);
        break;
    case 27:
    case 0:
    case 22:
    case 26:
    case 28:
    case 30:
        break;
    }
}

/* Title_CheckSaveData_1_001A4570 */
/* Title_CheckSaveData_1_001A4570 */
s32 Title_CheckSaveData_1_001A4570(void) {
    s32 r = 0;
    St st = {0};
    s32 s;
    s32 any, i, t;

    switch (D_0020226C) {
    case 0:
        D_0020226C++;
        D_00202268 = 0;
        break;
    case 1:
        if (SaveSys_SetPort_1_001E82A0(D_00202268) != 0) {
            D_0020226C++;
        } else {
            D_0020226C = 0;
            r = 1;
        }
        break;
    case 2:
        if (SaveSys_StartRead_0_001E5F30(0, 0) == 0) {
            D_0020226C++;
        } else {
            D_0020226C = 0;
            r = 1;
        }
        break;
    case 3:
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 2) {
            r = 0;
        } else if (s == 0) {
            SaveSys_GetSlotCount_0_001E5E80(&st);
            if ((st.f10[0] == 1) | (st.f10[1] == 1) | (st.f10[2] == 1) | (st.f10[3] == 1) | (st.f10[4] == 1) |
                (st.f10[5] == 1) | (st.f10[6] == 1)) {
                D_0020226C = 0;
                r = 2;
            } else {
                if (SaveSys_GetPort_1_001E8290() == 1) {
                    D_0020226C = 0;
                    r = 1;
                } else {
                    D_0020226C = 1;
                    D_00202268 = 1;
                    r = 0;
                }
            }
        } else {
            if (SaveSys_GetPort_1_001E8290() == 1) {
                D_0020226C = 0;
                r = 1;
            } else {
                D_0020226C = 1;
                D_00202268 = 1;
                r = 0;
            }
        }
        break;
    case 4:
        if (SaveSys_StartWrite_0_001E6170(7, Save_GetSlotInfo_0_00188FF0(0), 8) != -1) {
            D_0020226C++;
        } else {
            r = 1;
        }
        break;
    case 5:
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 0) {
            any = 0;
            for (i = 0; i < 7; i++) {
                t = 0;
                if (st.f10[i] == 1 && !(Save_GetSlotInfo_0_00188FF0(0)[i] != 0) != 0) {
                    t = 1;
                }
                any |= t;
            }
            if (any) {
                D_0020226C = 0;
                r = 2;
            } else {
                if (SaveSys_GetPort_1_001E8290() == 1) {
                    D_0020226C = 0;
                    r = 1;
                } else {
                    D_0020226C = 1;
                    D_00202268 = 1;
                    r = 0;
                }
            }
        }
        if (s == 1) {
            r = 1;
            D_0020226C = 0;
        }
        break;
    }
    return r;
}

/* Title_PlayPrologue_2_001A4890 */
void Title_PlayPrologue_2_001A4890(void *arg0) {
    s32 temp_4;

    temp_4 = M2C_FIELD(arg0, s32 *, 0);
    if ((temp_4 == 0x16) && (D_00202270 != 0) && (((s64) (Strm_GetParam_0_001303C0(temp_4) << 0x30) >> 0x30) <= 0) && (Snd_CountActiveVoices_1_0012C1B0() == 0)) {
        GsPkt_EndLayer_1_00155900();
        Movie_Play_2_0017FF70((s32) D_001FD8D0);
        GsPkt_SetLayer_1_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
        D_00202270 = 0;
    }
}

/* Title_StartNewGame_0_001A4930 */
void Title_StartNewGame_0_001A4930(Obj_Title_CheckSaveData_1_001A4570 *o)
{
    o->bC = 0;
    if (o->x0 == 25)
        D_00202270 = 1;
    if (o->x0 == 22 && !D_00202270) {
        o->b8 = 18;
        o->x4 = 0;
        o->x0 = 31;
        Game_RequestMode12B_0_0012C0C0();
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/save_byte_bss.c): D_004A43A0 */
s16 D_004A43A0[0x6];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_001F3320[];
/* data group (src/game/data/title_nop_data.c): D_001F3360__grp: D_001F3360@0x0 */
s32 D_001F3360__grp[0x8] __attribute__((aligned(16))) = { 0, 5, 0, (s32)D_001F3320, 7, -0x3fc00000, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sdata.c): D_00201DA0__grp: D_00201DA0@0x0 */
s32 D_00201DA0__grp[0x2] __attribute__((aligned(16))) = { 0, 1 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_byte_bss.c): D_004A43AC__grp: D_004A43AC@0x0 */
u8 D_004A43AC__grp[0x4] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/title_nop_data.c): gStrLoadGame_001F3390__grp: gStrLoadGame_001F3390@0x0 */
char gStrLoadGame_001F3390__grp[0xd] __attribute__((aligned(16))) = "LOAD GAME\000\000\000\000";
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/title_nop_data.c): gStrNewGame_001F3380__grp: gStrNewGame_001F3380@0x0 */
char gStrNewGame_001F3380__grp[0xd] __attribute__((aligned(16))) = "NEW GAME\000\000\000\000\000";
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/title_nop_data.c): D_001F3320 */
u8 D_001F3320[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/enemy_list_rodata.c): D_001FD8D0__grp: D_001FD8D0@0x0 */
char D_001FD8D0__grp[0x1e] __attribute__((aligned(16))) = "cdrom0:\\TARGET\\PROLOGUE.PSS;1\000";
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/title_rodata.c): gStrCdrom0TargetOpeningPss1_001FD870__grp: gStrCdrom0TargetOpeningPss1_001FD870@0x0 */
char gStrCdrom0TargetOpeningPss1_001FD870__grp[0x1d] __attribute__((aligned(16))) = "cdrom0:\\TARGET\\OPENING.PSS;1\000";
#endif
