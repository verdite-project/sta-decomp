#include "common.h"
#include "actor.h"
#include "game/input.h"
#include "game/math.h"
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u8 f18;
    u8 f19;
    u8 pad[6];
} Ent;
extern s32 D_003172E0[];
extern Flags8 D_003174E0[];
f32 powf(f32, f32);
void Pad_SetRumble_3_001D7D08(s32, s32, u32);
void Pad_SetRumbleLarge_2_001D7D58(s32, s32, u16);
void memset(s32 *, s32, s32);

/* Vibe_StartA_0_0015FD90 */
void Vibe_StartA_0_0015FD90(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    u8 *var_4_2;
    s32 var_5;
    s32 *var_4;

    var_5 = 0;
    var_4 = (s32 *) (D_003172E0);
loop_1:
    if (M2C_FIELD(var_4, u8 *, 0x19) == 0) {
        var_4_2 = (u8 *) ((s32 *)((u8 *)D_003172E0 + (var_5 << 5)));
    } else {
        var_5 += 1;
        var_4 = (s32*)((u8 *)var_4 + 0x20);
        if (var_5 >= 0x10) {
            var_4_2 = (u8 *) (NULL);
        } else {
            goto loop_1;
        }
    }
    if (var_4_2 != NULL) {
        M2C_FIELD(var_4_2, f32 *, 0) = fparg0;
        M2C_FIELD(var_4_2, f32 *, 4) = fparg1;
        M2C_FIELD(var_4_2, f32 *, 8) = fparg2;
        M2C_FIELD(var_4_2, f32 *, 0xC) = fparg3;
        M2C_FIELD(var_4_2, f32 *, 0x10) = (f32) (16.0f * fparg4);
        M2C_FIELD(var_4_2, s32 *, 0x14) = 0;
        M2C_FIELD(var_4_2, s8 *, 0x18) = 1;
        M2C_FIELD(var_4_2, s8 *, 0x19) = 1;
    }
}

/* Vibe_StartB_0_0015FE20 */
void Vibe_StartB_0_0015FE20(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    u8 *var_4_2;
    s32 var_5;
    s32 *var_4;

    var_5 = 0;
    var_4 = (s32 *) (D_003172E0);
loop_1:
    if (M2C_FIELD(var_4, u8 *, 0x19) == 0) {
        var_4_2 = (u8 *) ((s32 *)((u8 *)D_003172E0 + (var_5 << 5)));
    } else {
        var_5 += 1;
        var_4 = (s32*)((u8 *)var_4 + 0x20);
        if (var_5 >= 0x10) {
            var_4_2 = (u8 *) (NULL);
        } else {
            goto loop_1;
        }
    }
    if (var_4_2 != NULL) {
        M2C_FIELD(var_4_2, f32 *, 0) = fparg0;
        M2C_FIELD(var_4_2, f32 *, 4) = fparg1;
        M2C_FIELD(var_4_2, f32 *, 8) = fparg2;
        M2C_FIELD(var_4_2, f32 *, 0xC) = fparg3;
        M2C_FIELD(var_4_2, f32 *, 0x10) = (f32) (16.0f * fparg4);
        M2C_FIELD(var_4_2, s32 *, 0x14) = 0;
        M2C_FIELD(var_4_2, s8 *, 0x18) = 0;
        M2C_FIELD(var_4_2, s8 *, 0x19) = 1;
    }
}

/* Vibe_Update_1_0015FEB0 */
#define D_003172E0 D_003172E0__as_Vibe_Update_1_0015FEB0
extern Ent D_003172E0__as_Vibe_Update_1_0015FEB0[];
static inline s32 en_Vibe_Update_1_0015FEB0(void) {
    return !D_003174E0[0].f.b1 && D_003174E0[0].f.b0;
}

void Vibe_Update_1_0015FEB0(s32 on, f32 dt) {
    f32 r;
    f32 acc[2] = {0};
    Noise nz;
    s32 i;
    f32 v;

    D_003174E0[0].f.b0 = on != 0;
    nz.f4 = 1;
    nz.f5 = 1;
    nz.idx[0] = 0;
    nz.base = 0;
    for (i = 0; i < 16; i++) {
        if (D_003172E0[i].f19 != 0) {
            nz.w1 = 0.25f * D_003172E0[i].fC;
            nz.w2 = 0.25f * D_003172E0[i].fC;
            nz.amp = D_003172E0[i].f4;
            nz.base = D_003172E0[i].f8;
            nz.scale = D_003172E0[i].f0;
            nz.f1C = D_003172E0[i].f10;
            Noise_Eval_1_0015ED80(&nz, 1, &r, D_003172E0[i].f14, 0.0f, D_003172E0[i].fC);
            acc[D_003172E0[i].f18] += r;
            D_003172E0[i].f14 += dt;
            if (!(D_003172E0[i].f14 <= D_003172E0[i].fC)) {
                D_003172E0[i].f19 = 0;
            }
        }
    }
    if (acc[0] < 0.0f) {
        acc[0] = 0.0f;
    }
    if (acc[1] < 0.0f) {
        acc[1] = 0.0f;
    }
    if (!D_003174E0[0].f.b1 && D_003174E0[0].f.b0) {
        if (en_Vibe_Update_1_0015FEB0()) {
            Pad_SetRumbleLarge_2_001D7D58(0, 0, (s32)acc[0]);
        } else {
            Pad_SetRumbleLarge_2_001D7D58(0, 0, 0);
        }
        v = (f32)(s32)acc[1] / 255.0f;
        if (D_003174E0[0].f.b1 || !D_003174E0[0].f.b0) {
            Pad_SetRumble_3_001D7D08(0, 0, 0);
        }
        Pad_SetRumble_3_001D7D08(0, 0, 255.0f * powf(v, 0.5f));
    }
}
#undef D_003172E0

/* Vibe_Enable_1_001601C0 */
static inline s32 en_Vibe_Enable_1_001601C0(void) {
    return !D_003174E0[0].f.b1 && D_003174E0[0].f.b0;
}

void Vibe_Enable_1_001601C0(s32 on) {
    D_003174E0[0].f.b1 = on != 0;
    if (on) {
        if (en_Vibe_Enable_1_001601C0()) {
            Pad_SetRumbleLarge_2_001D7D58(0, 0, 0);
        } else {
            Pad_SetRumbleLarge_2_001D7D58(0, 0, on - on);
        }
        if (D_003174E0[0].f.b1 || !D_003174E0[0].f.b0) {
            Pad_SetRumble_3_001D7D08(0, 0, 0);
        }
        Pad_SetRumble_3_001D7D08(0, 0, 255.0f * powf(0.0f, 0.5f));
    }
}

/* Vibe_StopAll_1_00160300 */
#define Pad_SetRumbleLarge_2_001D7D58 Pad_SetRumbleLarge_2_001D7D58__as_Vibe_StopAll_1_00160300
int Pad_SetRumbleLarge_2_001D7D58__as_Vibe_StopAll_1_00160300();
#define Pad_SetRumble_3_001D7D08 Pad_SetRumble_3_001D7D08__as_Vibe_StopAll_1_00160300
int Pad_SetRumble_3_001D7D08__as_Vibe_StopAll_1_00160300();

void Vibe_StopAll_1_00160300(void) {
    Pad_SetRumbleLarge_2_001D7D58(0, 0, 0);
    Pad_SetRumble_3_001D7D08(0, 0, 0);
    memset(D_003172E0, 0, 0x200);
}
#undef Pad_SetRumbleLarge_2_001D7D58
#undef Pad_SetRumble_3_001D7D08

/* Vibe_Clear_1_00160350 */
void Vibe_Clear_1_00160350(void) {
    memset(D_003172E0, 0, 0x204);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/vibration_bss.c): D_003172E0__grp: D_003172E0@0x0, D_003174E0@0x200, D_003174F0@0x210 */
u8 D_003172E0__grp[0x27220] __attribute__((aligned(16)));
#endif
