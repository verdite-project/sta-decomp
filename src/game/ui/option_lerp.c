#include "m2c.h"
#include "common.h"
#include "game/data.h"
typedef struct { f32 a, b; } P2;
typedef struct { u8 pad0[0xC]; P2 *xC; s32 x10; f32 x14; } A;
typedef struct { s32 x0; s32 x4; f32 x8; } B;
typedef struct { u8 pad0[0x40]; f32 x40; f32 x44; } Info;
typedef struct { s32 x0; s32 x4; u8 p8[2]; u8 xA; u8 pB[3]; u8 xE; } O;
#ifndef NONMATCHING
extern s32 D_00202134;
#else
/* data twins (src/game/data/sbss.c): D_00202134 */
static s32 D_00202134;
#endif
#ifndef NONMATCHING
extern s32 D_00202138;
#else
/* data twins (src/game/data/sbss.c): D_00202138 */
static s32 D_00202138;
#endif
extern Flags8 D_004A10DC[];
void Option_LerpLayout_0_00191820(s32 i, A *a, B *b);
void OptionProc_Back_0_00191C40(O *o);
f32 fabsf(f32);
void UiAnim_Get_1_0017F840(s32, Info **);
void Snd_PlaySe_3_00131600(s32, s32);

/* Option_LerpLayout_0_00191820 */
void Option_LerpLayout_0_00191820(s32 i, A *a, B *b) {
    Info *info;
    f32 d;
    f32 h;
    f32 v;

    UiAnim_Get_1_0017F840(0xD, &info);
    if (D_00202128 == 1) {
        if (i < D_004A10D0[0]) {
            d = a->xC[a->x10 - 1].a - D_004A10B0[i];
            h = 0.5f * d;
            if (!(fabsf(d) <= 0.01f)) {
                D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
            } else {
                a->x14 = D_004A10B0[i];
            }
        } else if (i > D_004A10D0[0]) {
            d = a->xC[0].a - D_004A10B0[i];
            h = 0.5f * d;
            if (!(fabsf(d) <= 0.01f)) {
                D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
            } else {
                a->x14 = D_004A10B0[i];
            }
        } else {
            info->x44 = 0.5f * (info->x40 - b->x8);
            if (!(fabsf(info->x40 - b->x8) <= 0.01f)) {
                b->x8 = b->x8 + info->x44;
            }
            D_004A10B0[i] = a->x14 = b->x8 - (f32)i;
        }
    } else if (D_00202128 == 2) {
        if (i == 0) {
            D_00202134 = 1;
        }
        if (i != D_004A10D0[0]) {
            if (D_004A10D0[0] - i + 2 >= 0) {
                d = (b->x8 - (f32)i) - D_004A10B0[i];
                h = 0.5f * d;
                if (!(fabsf(d) <= 0.01f)) {
                    D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
                    D_00202134 = 0;
                } else {
                    a->x14 = D_004A10B0[i];
                }
            }
        } else {
            a->x14 = D_004A10B0[i];
        }
        if (i == b->x4 - 1 && D_00202134) {
            D_00202128 = 0;
        }
    } else if (D_00202128 == 3) {
        v = a->xC[0].a;
        if (i == 0) {
            D_00202138 = 1;
        }
        if (D_004A10B0[i] < 1.99f && !(D_004A10B0[i] <= v + 0.01f)) {
            d = v - D_004A10B0[i];
            h = 0.5f * d;
            if (!(fabsf(d) <= 0.01f)) {
                D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
                D_00202138 = 0;
            } else {
                a->x14 = D_004A10B0[i];
            }
        } else {
            a->x14 = D_004A10B0[i];
        }
        if (i == b->x4 - 1 && D_00202138) {
            D_00202128 = 0;
            b->x8 = v;
            info->x40 = v;
        }
    } else {
        a->x14 = b->x8 - (f32)i;
    }
}

/* OptionProc_Back_0_00191C40 */
void OptionProc_Back_0_00191C40(O *o) {
    if (o->x4 & 0x2000) {
        D_004A10DC[0].f.b3 = 0;
        o->xA = 2;
        o->x0 = 0x16;
        o->x4 = 0;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/load_menu_bss.c): D_004A10B0 */
f32 D_004A10B0[0x4];
#endif
