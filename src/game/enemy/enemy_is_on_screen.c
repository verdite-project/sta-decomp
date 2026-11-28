/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Enemy_IsOnScreen_0_0013FCC0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
// NEAR: 76 of 123 words (built 121). Fixed: u8 return, gete(Hd*, u16) inline gives the andi+ternary shape, q = q < p ? p : q.
// Still differs: retail keeps sw/sh (size pair) in two 4-byte stack slots 0x6C/0x68 (sp-direct, initial zero stores kept,
// sh load reused across the && branch) -> non-volatile address-taken scalars; here they go to f21/f22 (extra float saves).
// f32 sz[2] + dead pointer keeps memory but CSEs &sz[1] into s0; volatile reloads sh. Unknown what took their address.
#include "m2c.h"
#include "actor.h"
typedef struct { u8 pad[0x22]; u16 w22; u16 w24; } Ent;
typedef struct { u8 pad[0x13C]; u8 *tbl; } Tb;
typedef struct { Tb *t; } Hd;
typedef struct { u8 pad[0x198]; Vec *p198; } S518;
void sceVu0CopyVector(Vec *, void *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);
static inline f32 u2f(u32 x) { return x; }
static inline Ent *gete(Hd *h, u16 i) {
    return h ? (Ent *)(h->t->tbl + i * 0x54) : 0;
}
u8 Enemy_IsOnScreen_0_0013FCC0(Actor *o, f32 *out) {
    u8 r = 0;
    Vec v;
    f32 sw;
    f32 sh;
    f32 a = 4000.0f, b = 4000.0f;
    f32 len, ay;
    Ent *e;

    sw = 0; sh = 0;
    if (!o->flags5A1.f.b3) {
        Hd *h = (Hd *)o->unk4A8;
        e = gete(h, o->unk4AC);
        if (e) {
            a = u2f(e->w22);
            b = u2f(e->w24);
        }
    }
    sw = a; sh = b;
    sceVu0CopyVector(&v, &o->pad60C[0x54]);
    sceVu0SubVector(&v, ((S518 *)o->unk518)->p198, &v);
    ay = v.y;
    if (ay < 0.0f) ay = -ay;
    v.y = 0;
    len = sqrtf(sceVu0InnerProduct(&v, &v));
    if (out) {
        out[0] = len;
        out[1] = ay;
        out[2] = sw;
        out[3] = sh;
    }
    if (ay < sh && len < sw) r = 1;
    {
        f32 p = ay / sh;
        f32 q = len / sw;
        q = q < p ? p : q;
        o->unk6BC = q;
    }
    return r;
}
#else
INCLUDE_ASM(Enemy_IsOnScreen_0_0013FCC0);
#endif
