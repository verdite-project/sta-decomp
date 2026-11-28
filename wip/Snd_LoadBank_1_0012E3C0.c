/* NEAR (unverifiable): the three FOURCCs are string literals at D_001FAB60/68/70 ("FCC(\"xxxx\")"); with literals
 * MWCC reproduces the target shape (byte0 + &lit[1..3] hoisted, 3rd FOURCC rebuilt per outer iteration),
 * but batch.py discards .data/.sdata so it cannot link literals, and my build puts them in sdata (gp) while
 * the target uses lui. extern s8 D_001FAB60[] arrays link but fully hoist all three (130/160 differ).
 * Remaining known diff: final 0x14-byte struct copy is lq/sq here vs 5x lwc1/swc1 in target. The chars are "STAM", "STMI", "SEEa" (retail D_001FAB60/68/70). */
#include "m2c.h"
typedef struct Ch { s32 id; s32 size; u32 lo:8; u32 off:24; u16 xC; u16 n; } Ch;
typedef struct { s32 x0; s32 x4; u8 pad8[4]; s32 xC; } D;
typedef struct { s32 a; s32 b; s16 c; s16 d; s32 e; s32 f; } P;
typedef struct { u8 pad[0x10]; Ch **x10; } Obj;
typedef struct { s32 x0; Obj **x4; } Arg;
extern s32 D_0022EC3C[];
extern u8 D_0022EC16[];
extern P D_0022EC28;
void Se_RegisterBank_0_001DA7D0(s32);
s32 Se_RegisterSfx_0_001DA840(s32, s16, s16, s16, s16, s32);
#define FCC(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))

void Snd_LoadBank_1_0012E3C0(Arg *a0) {
    Ch *h;
    Ch *e;
    Ch *c;
    D *d;
    u8 *v;
    u32 i;
    u32 j;
    s32 r;
    P p;

    if (a0 == NULL) return;
    h = *(*a0->x4)->x10;
    if (h->id != FCC("STAM")) return;
    e = (Ch *)((s8 *)h + h->off);
    for (i = 0; i < h->n; i++) {
        if (e->id == FCC("STMI")) {
            c = (Ch *)((s8 *)e + e->off);
            for (j = 0; j < e->n; j++) {
                d = (D *)((s8 *)c + 0x10);
                if (c->id == FCC("SEEa")) {
                    if (d->x4 != 0) {
                        v = (u8 *)d + 0x10 + ((d->xC + 15) & ~15);
                        p.a = 1;
                        p.b = *(u16 *)v;
                        p.c = *(s16 *)(v + 2);
                        p.d = *(s16 *)(v + 4);
                        p.e = (s8)v[6];
                        p.f = (s8)v[7];
                        Se_RegisterBank_0_001DA7D0(D_0022EC3C[0]);
                        r = Se_RegisterSfx_0_001DA840(p.b, p.c, p.d, p.e, p.f, p.a);
                        if (r < 0) return;
                        D_0022EC3C[0] = r;
                        D_0022EC16[0] = 1;
                        D_0022EC28 = p;
                    }
                    return;
                }
                c = (Ch *)((s8 *)c + c->size);
            }
        }
        e = (Ch *)((s8 *)e + e->size);
    }
}
