/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Fx_UpdateChildrenEx_1_001629E0.c.
 * The matching build takes it from the assembly of Fx_UpdateChildren_1_00162700. */
#ifdef NONMATCHING
/* near-miss: sibling of Fx_UpdateChildren_1_00162700, same calc() inline, same single remaining diff (2 missing nops before 'div zero,a2,a1' in the 'rate < fp' path, (f32)period in $f1 vs ours $f2). Fix one, fix both. */
#include "m2c.h"

typedef union {
    u128 q[3];
    struct {
        u8 pad[0x20];
        f32 f20;
    } s;
} Sub;

typedef struct {
    u16 f0;
    u8 pad2[5];
    u8 f7;
    u8 pad8[0x20];
    u16 f28;
} Dat;

typedef struct {
    u8 pad0[4];
    f32 f4;
    u8 pad8[5];
    s8 fD;
    u8 padE[0x42];
    Sub sub;
} Ch;

typedef struct {
    u8 pad0[0x174];
    f32 f174;
    u8 pad178[0xC];
    f32 f184;
    u8 pad188[0x88];
    Dat *dat[24];
    Ch ch[1];
} Mgr;

void Fx_EvalTrackB_1_00162CE0(Sub *, Dat *, f32);
s32 Fx_SpawnBurst_1_00162F30(void *, u16, Mgr *, Dat *, Sub *, Ch *, s32);

static inline u16 calc(s32 frame, s32 period, f32 rate, s32 flag, s32 cur) {
    u16 r;
    f32 fp;

    if (rate == 0.0f) {
        return 0;
    }
    if (!flag) {
        if (rate <= (f32)cur) {
            return 0;
        }
        if (period < frame) {
            return 0;
        }
    }
    if (0.0f < rate && rate <= 1.0f && cur == 0) {
        return 1;
    }
    fp = period;
    return rate < fp ? frame % period >= (s32)(fp / rate) * (s32)((f32)cur - rate * (f32)(frame / period)) : (frame % period < (s32)rate % period ? (s32)(1.0f + rate / fp) : (s32)(rate / fp));
}

typedef struct {
    u8 pad0[0x8C];
    f32 f8C;
    Mgr *f90;
    u8 pad94[2];
    u8 f96[1];
} Own;

void Fx_UpdateChildrenEx_1_001629E0(Own *o, s32 k, s32 j, f32 t) {
    Mgr *m;
    Ch *ch;
    Dat *d;
    Sub *s;
    Sub tmp;
    s32 n;
    s32 r;

    m = o->f90;
    ch = &m->ch[k];
    d = m->dat[k];
    if (d->f28 != 0) {
        tmp = ch->sub;
        s = &tmp;
        Fx_EvalTrackB_1_00162CE0(&tmp, d, o->f8C);
    } else {
        s = &ch->sub;
    }
    n = calc((s32)(30.0f * o->f8C), d->f0, s->s.f20 * m->f184, d->f7 & 1, o->f96[j]);
    o->f96[j] += n;
    r = Fx_SpawnBurst_1_00162F30(o, n, m, d, s, ch, k);
    if (r) {
        o->f96[j] -= r;
    }
    if (m->ch[k].fD != 0) {
        Fx_UpdateChildrenEx_1_001629E0(o, m->ch[k].fD, j + 1, t);
    }
}
#endif
