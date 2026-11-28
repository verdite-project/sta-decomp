#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/ui.h"
typedef struct { u32 n; s32 *list; } Lst;
typedef struct { f32 v[9]; } M;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; f32 x10; f32 x14; f32 x18; s32 x1C; } P;
extern s32 D_004A0F90[];
extern void (*D_004A0F9C[])(s8 *);
extern void (*D_004A0F98[])(s32);
#ifndef NONMATCHING
extern s8 D_001FCCF0[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCCF0 */
static s8 D_001FCCF0[0x8] = { -0x7f, -0x65, -0x7f, 0x46, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FCCF8[];
#else
/* data twins (src/game/data/ui_gauge_rodata2.c): D_001FCCF8 */
static s8 D_001FCCF8[0x8] = { -0x7f, 0x7e, -0x7f, 0x46, 0, 0, 0, 0 };
#endif
extern M D_004A0F90__as_MenuProc_Run_1_0018B320;
void MenuProc_Set_1_0018B150(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0);
void MenuProc_DrawList_0_0018B180(s8 *arg0);
void MenuProc_CheckReady_0_0018B2E0(s32 a);
void MenuProc_Run_1_0018B320(M *m);
void MenuProc_DrawConfirm_0_0018B380(s8 *a0, s32 a1, u32 a2, P *a3);
void Ui_DrawList_1_001829B0(s32 *, s32, void (*)(), s32 *);
s8* MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawSprite_2_00181680(s32, s8 *, s8 *, Col *, S *, u32);
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, Col);
void sprintf(s8 *, s8 *, ...);
s8* Msg_GetText_2_00195B10(s32);
s32 strlen(s8 *);
void memcpy(s8 *, s8 *, s32);
void MenuProc_DrawConfirm_0_0018B380__as_MenuProc_DrawList_0_0018B180();

/* MenuProc_Set_1_0018B150 */
/* MenuProc_Set_1_0018B150 */
void MenuProc_Set_1_0018B150(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = arg3;
    M2C_FIELD(arg0, s32 *, 0xC) = arg4;
    M2C_FIELD(arg0, f32 *, 0x10) = fparg0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
}

/* MenuProc_DrawList_0_0018B180 */

void MenuProc_DrawList_0_0018B180(s8 *arg0) {
    u32 i;
    Lst *l;
    s32 base;
    s32 off;
    s32 *d;
    s32 *e;

    l = *(Lst **)(MenuLayout_Get_1_00189050(0) + 0x28);
    base = MenuLayout_GetSub_1_00189020(0);
    if (*(u8 *)(arg0 + 0xA) == 2) {
        D_004A0FAC[0] -= 0xC;
        if (D_004A0FAC[0] < 0) {
            *(u8 *)(arg0 + 0xA) = 0;
            *(u8 *)(arg0 + 0xB) = 0;
        }
    } else {
        D_004A0FAC[0] += 0xC;
    }
    if ((s16)D_004A0FAC[0] < 0) {
        D_004A0FAC[0] = 0;
    }
    if ((s16)D_004A0FAC[0] > 0x7F) {
        D_004A0FAC[0] = 0x7F;
    }
    i = 0;
    if (i < l->n) {
        d = D_004A0F90;
        off = 0;
        do {
            e = (s32 *)((s8 *)l->list + off);
            Ui_DrawList_1_001829B0(e, base + *e * 8, MenuProc_DrawConfirm_0_0018B380__as_MenuProc_DrawList_0_0018B180, d);
            i++;
            off += 0x40;
        } while (i < l->n);
    }
    if (D_004A0F9C[0] != NULL) {
        D_004A0F9C[0](arg0);
    }
}

/* MenuProc_CheckReady_0_0018B2E0 */
void MenuProc_CheckReady_0_0018B2E0(s32 a)
{
    if (D_004A0F98[0] && D_004A0FAC[0] > 0x74)
        D_004A0F98[0](a);
}

/* MenuProc_Run_1_0018B320 */

void MenuProc_Run_1_0018B320(M *m)
{
    if (m)
        D_004A0F90__as_MenuProc_Run_1_0018B320 = *m;
}

/* MenuProc_DrawConfirm_0_0018B380 */
#pragma explicit_zero_data on
S D_001F29F0 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
static inline void cat(s8 *d, s8 *s) { s32 n = strlen(s); memcpy(d + strlen(d), s, n + 1); }

void MenuProc_DrawConfirm_0_0018B380(s8 *a0, s32 a1, u32 a2, P *a3) {
    s8 buf[0x400];
    S t __attribute__((aligned(16)));
    Col col;
    s8 *s;

    col.w = 0x80808080;
    col.c.a = col.c.a * a3->x1C / 127;
    if (a2 < 500) {
        t = D_001F29F0;
        t.x = *(f32 *)(a0 + 0x30);
        t.y = *(f32 *)(a0 + 0x34);
        col = *(Col *)(a0 + 0x2C);
        col.c.a = col.c.a * a3->x1C / 127;
        Ui_DrawSprite_2_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, &col, &t, a2);
        return;
    }
    if (a3->x1C < 64) return;
    switch (a2) {
    case 500:
        sprintf(buf, D_001FCCF0);
        s = Msg_GetText_2_00195B10(a3->x0);
        if (s != 0) cat(buf, s);
        Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38) + a3->x14, *(f32 *)(a0 + 0x3C) + a3->x18, a3->x10, s, 1, col);
        break;
    case 501:
        sprintf(buf, D_001FCCF0);
        if (a3->x4 == 1) {
            cat(buf, Msg_GetText_2_00195B10(100));
            Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        } else if (a3->x4 == 3 || a3->x4 == 4) {
            cat(buf, Msg_GetText_2_00195B10(0x67));
            Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        break;
    case 502:
        sprintf(buf, D_001FCCF8);
        if (a3->x4 == 1) {
            cat(buf, Msg_GetText_2_00195B10(0x65));
            Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        } else if (a3->x4 == 3) {
            cat(buf, Msg_GetText_2_00195B10(0x66));
            Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        if (a3->x4 == 4) {
            cat(buf, Msg_GetText_2_00195B10(0x68));
            Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        break;
    case 503:
        if (a3->x4 == 2) {
            sprintf(buf, D_001FCCF0);
            cat(buf, Msg_GetText_2_00195B10(0x67));
            Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        break;
    }
}

/* Menu_GetCursor_1_0018B820 */
/* Menu_GetCursor_1_0018B820 */
s32 Menu_GetCursor_1_0018B820(s32 i)
{
    return D_00202120[i];
}

/* Menu_SetCursor_1_0018B840 */
void Menu_SetCursor_1_0018B840(s32 i, s32 v)
{
    D_00202120[i] = v;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202120 */
s32 D_00202120[2];
/* data twins (src/game/data/option_bss.c): D_004A0F90 */
s32 D_004A0F90[0x2] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/option_bss.c): D_004A0F98__grp: D_004A0F98@0x0 */
u8 D_004A0F98__grp[0x28] __attribute__((aligned(8)));
#endif
