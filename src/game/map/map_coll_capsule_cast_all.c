/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/MapColl_CapsuleCastAll_1_001B3240.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: 53 of 156 words differ (was 80), same length. Fixed: u8 param homes (volatile only on first a3 test),
   b0 = *s1->p10 and ent->p single derefs, call arg as (u8 *)((s32)r + (off + 0x140)) + 0xC0.
   Still differs: register/spill choice. Retail spills d,cb,b0,off to 16-aligned slots D0/C0/B0/A0 (= compiler temps?)
   and keeps r in s7, fp in s8, ent in s2; here cb stays in s2 and r spills. 700 random decl orders and an inline-helper
   split (d/cb/b0 as inline params) did not fix it. */
#include "common.h"
typedef union { u8 b; struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } f; } Fl;
typedef struct { u8 pad[0x10]; s32 *p10; u16 h14; u16 h16; u16 h18; u8 pad2[2]; u16 h1C; } S1;
typedef struct { S1 *s1; } Q;
typedef struct { u8 pad[0x1A]; s16 h1A; u8 pad2[0x14]; } Dd;
typedef struct { s32 p; Fl fl; } Ent;
typedef struct { u8 pad[0xC0]; u8 f[0x80]; } El;
typedef struct { u8 pad[4]; Q *q; u8 pad1[0x64]; u16 n; u8 pad2[0xC6]; Dd *d; u8 pad3[0x40]; Ent *ent; u8 pad4[0x5C]; Fl f1D8; } O;
u8 *Mdl_GetFrameData_0_001715B0(s32);
s32 Coll_CapsuleVsMesh_1_0014E230(s32 *, u8 *, s32, u8 *, u8 *, u8 *, u8, s32);
s32 MapColl_CapsuleCastAll_1_001B3240(O *o, s32 *a1, u8 *a2, u8 a3, u8 t0) {
    s32 i;
    u8 *fp;
    u8 *r;
    Q *q;
    u8 *cb;
    Dd *d;
    S1 *s1;
    s32 b0;
    s32 off;
    Ent *ent;
    s32 found;
    found = 0;
    if (*(volatile u8 *)&a3 == 0 || o == NULL) return 0;
    if (o->f1D8.f.b1 || !o->f1D8.f.b0) return 0;
    q = o->q;
    if (q == NULL || (s1 = q->s1) == NULL) return 0;
    d = o->d;
    ent = o->ent;
    cb = (u8 *)s1 + 0x40;
    cb += s1->h14 << 4;
    cb += s1->h16 << 3;
    cb += s1->h18 << 2;
    b0 = *s1->p10;
    r = Mdl_GetFrameData_0_001715B0(ent->p);
    if (r == NULL || s1->h1C == 0) return 0;
    fp = r;
    off = 0;
    for (i = 0; i < o->n; i++) {
        if (d->h1A != -1 && ent->fl.f.b0 && !ent->fl.f.b1) {
            u32 idx = fp[0x332];
            if (idx != 0xFF && idx < s1->h1C) {
                u8 *e = cb + idx * 0x50;
                if (*(s32 *)e != 0 && *(s32 *)(e + 8) != 0) {
                    if (Coll_CapsuleVsMesh_1_0014E230(a1, e, b0, a2, a2 + 0x10, (u8 *)((s32)r + (off + 0x140)) + 0xC0, a3, 1)) {
                        a1[8] = (s32)s1;
                        a1[0xF] = i;
                        a1[0xC] = (s32)o;
                        a1[0xE] = 0;
                        a1[0xD] = 0;
                        found = 1;
                        if (t0) return found;
                    }
                }
            }
        }
        off += 0x140;
        fp += 0x140;
        d++;
        ent++;
    }
    return found;
}
#else
INCLUDE_ASM(MapColl_CapsuleCastAll_1_001B3240);
#endif
