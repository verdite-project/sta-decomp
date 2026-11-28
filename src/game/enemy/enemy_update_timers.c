/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Enemy_UpdateTimers_0_0013D8A0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "actor.h"
typedef struct { u8 v:4; } BF4;
typedef struct { u8 pad[0x16C]; s32 x16C; } Sub;
void Enemy_StartIdleMotion_1_0013C740(Actor *, s32, s32 *, s32);

void Enemy_UpdateTimers_0_0013D8A0(Actor *a0, f32 dt) {
    f32 t;
    u8 k;
    s32 n;
    s32 *q;
    s32 c;
    s32 m;
    s32 mx;

    if (((BF4 *)&a0->flags5B5)->v) {
        t = a0->unk5C4;
        t += dt / 1.5f;
        if (t >= 2.0f) {
            do {
                t -= 2.0f;
            } while (t >= 2.0f);
        }
        a0->unk5C4 = t;
        if (((BF4 *)&a0->flags5B5)->v & 1) {
            t = a0->unk5D0 + dt;
            k = 0;
            if (t >= 3.0f) {
                do {
                    t -= 3.0f;
                    k += 3;
                } while (t >= 3.0f);
            }
            a0->unk5D0 = t;
            n = k;
            if (n > 0) {
                q = &((Sub *)a0->unk518)->x16C;
                c = *(u16 *)q;
                if (c > 1) {
                    if (n + 1 < c) {
                        c -= n;
                        mx = *(u16 *)a0->unk4B0;
                        if (c < 0) c = 0;
                        if (mx < c) c = mx;
                        *q = (u16)c;
                        a0->unk6BA = -n;
                    } else {
                        m = c - 1;
                        c -= m;
                        mx = *(u16 *)a0->unk4B0;
                        if (c < 0) c = 0;
                        if (mx < c) c = mx;
                        *q = (u16)c;
                        a0->unk6BA = -m;
                    }
                    Enemy_StartIdleMotion_1_0013C740(a0, c, q, n);
                }
            }
        }
    }
}
#else
INCLUDE_ASM(Enemy_UpdateTimers_0_0013D8A0);
#endif
