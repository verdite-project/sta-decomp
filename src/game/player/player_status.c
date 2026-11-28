#include "m2c.h"
#include "game/input.h"
#include "game/player.h"
typedef union { u64 d; u32 w[2]; } T;
s8 *Player_GetBodyState_1_001C9B60(void);
s8 *PlayerData_Get_2_001C9BA0(void);
void Snd_PlaySe_3_00131600(s32, s32);
extern T D_00201E30;
extern u32 D_00201E94;

void Player_UpdateStatusEffects_0_001C9FF0(void) {
    T t;
    s8 *s0;
    s8 *p;
    u32 v;
    s8 a;
    s16 *q;
    s32 n;
    s32 m;
    s32 vol;

    s0 = Player_GetBodyState_1_001C9B60();
    t = D_00201E30;
    if (s0 != 0) {
        p = PlayerData_Get_2_001C9BA0();
        if (*(s32 *)(p + 0x58) == 0 && *(u32 *)(p + 0x38) != 0) {
            v = *(u32 *)(p + 0x38) >> 24;
        } else {
            v = 0;
        }
        if (v != 0 && D_00201E94 % t.w[v - 1] == 0) {
            Player_PlayStatusSe_0_001CA1C0(2);
        }
        a = s0[0x420];
        if (a != -1) {
            if (D_00201E94 % t.w[s0[0x421] - 1] == 0) {
                Player_PlayStatusSe_0_001CA1C0(a);
            }
        }
        q = *(s16 **)(s0 + 0x390);
        n = 0.3f * q[0];
        if (n == 0) {
            n = 1;
        }
        m = q[2];
        if (m <= n) {
            vol = 0x7F - (m << 6) / n;
            if (D_00201E94 % (m * 10 / n + 20) == 0) {
                Snd_PlaySe_3_00131600(300, vol);
                Vibe_StartA_0_0015FD90(0.8f, 1.0f, 0.0f, 0.2f, 2.0f);
            }
        }
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sdata.c): D_00201E30__grp: D_00201E30@0x0 */
s32 D_00201E30__grp[0x2] __attribute__((aligned(16))) = { 0x5a, 0x2d };
#endif
