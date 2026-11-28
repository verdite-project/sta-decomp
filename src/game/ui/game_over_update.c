#include "m2c.h"
#include "game/data.h"
#include "game/sound.h"
#include "game/ui.h"
#include "game/math.h"
typedef struct { u8 v:1; } BF0;
typedef struct { s32 type; s32 pad; s8 st; u8 pad9[5]; u8 eE; u8 padF[5]; BF0 x14; } Arg;
void Snd_PlaySe_3_00131600(s32, s32);
void Strm_SetFadeStep_1_001304B0(s32);
s32 Strm_PlayFile_2_00130590(s32, s32, s32);
#pragma explicit_zero_data on
const s8 D_001FD680[0x13] = "\\TARGET\\STA_GO.ADX\000";
extern f32 D_0020221C;

void GameOver_Update_2_0019EDC0(Arg *arg0) {
    s32 b;

    switch (arg0->type) {
    case 0x19:
        D_0020220C = 0;
        D_00202214 = 0;
        D_00202218 = 0;
        Snd_StopAll_1_0012C320();
        Strm_PlayFile_2_00130590((s32)D_001FD680, 0, 0);
    }
    if (D_00202210 == 2 && arg0->type == 0x16) {
        if (!arg0->x14.v) {
            b = arg0->pad;
            if (b & 0x10) {
                D_0020221C = 0.0f;
                D_0020220C = !D_0020220C;
                Snd_PlaySe_3_00131600(0x66, arg0->eE);
            } else if (b & 0x40) {
                D_0020221C = 0.0f;
                D_0020220C = !D_0020220C;
                Snd_PlaySe_3_00131600(0x66, arg0->eE);
            } else if (b & 0x2000) {
                if (D_0020220C == 0) {
                    arg0->x14.v = 1;
                    D_00202210 = 0;
                } else {
                    arg0->st = 9;
                    MenuStack_Push_1_00189ED0(0x28);
                    Loading_SetVisible_0_0018E470(0);
                    arg0->pad = 0;
                    arg0->type = 0x1A;
                    D_00202210 = 1;
                }
                Strm_SetFadeStep_1_001304B0(-0x222);
                Snd_PlaySe_3_00131600(0x67, arg0->eE);
            }
        }
        D_0020221C = Approachf_3_00187770(D_0020221C, 1.0f, 3.5f);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_0020220C */
s32 D_0020220C;
#endif
