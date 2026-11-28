/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Enemy_InitPartState_1_001A8510.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 23/88 (unchanged from prev). Only temp-register naming in the first ~25 insns differs: retail gSfxAllSbss_00201F2C->t1, off->t0, !D->a2, tbl elem->a2, h**->a3;
 * ours swaps t0/t1 and a2/a3. Tried: all 720 decl orders of explicit locals (dd,nd,sz,off,h,d), statement order perms, b38, u32 D, D==0,
 * typed x518 struct, inline buf()/ent() helpers, s32 param with masks, mult operand order. None moved it. */
#include "m2c.h"
typedef struct { u16 a, b, c, n; u8 pad[0x38]; s8 data[1]; } Hd;
typedef struct { u8 a:6; u8 en:1; u8 b:1; } Fl;
typedef struct { u8 pad[0x2A]; u8 x2A; } E;
typedef struct {
    u8 pad0[0x80];
    u8 n;
    u8 pad81[0x433];
    E *tbl[0x19];
    s8 *x518;
    u8 pad51C[4];
    u8 list[16];
} A;
extern s32 gSfxAllSbss_00201F2C;

void Enemy_InitPartState_1_001A8510(A *a0, u8 a1) {
    Hd *h;
    s8 *d;
    s32 off;
    Fl *p;
    Fl *q;
    u8 i;
    u8 cnt;
    off = (a0->tbl[a1]->x2A + 1) * 0x140;
    h = **(Hd ***)(a0->x518 + 0xB0);
    d = h->data;
    q = (Fl *)(d + !gSfxAllSbss_00201F2C * (h->n * 0x140 + 0x200));
    p = (Fl *)(d + gSfxAllSbss_00201F2C * (h->n * 0x140 + 0x200) + off + 0x1F8);
    if (p->en || ((Fl *)((s8 *)q + off + 0x1F8))->en) {
        p->en = 0;
        ((Fl *)((s8 *)q + off + 0x1F8))->en = 0;
        cnt = a0->n;
        for (i = 0; i < cnt; i++) {
            if (a0->list[i] == a1) {
                for (; i < a0->n - 1; i++) {
                    a0->list[i] = a0->list[i + 1];
                }
                a0->n--;
                return;
            }
        }
    }
}
#else
INCLUDE_ASM(Enemy_InitPartState_1_001A8510);
#endif
