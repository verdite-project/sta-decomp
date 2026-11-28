/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Sfx_SortByDepth_0_001679E0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: 167 of 169 words (was 152, len-17). difflib: 5 opcodes unmatched, ~75 full-insn diffs (mostly regalloc).
   Key fixes: swap split into nested inlines swp(u16,u16) -> fin(s32,s32) (re-masks a/b), c and n s32 locals.
   Still missing: retail does 'andi s1,a0' (n = masked copy of the while-cond lhu) and masks n again at the
   gSfxSystemSbss_00201FC0[n] index; here n stays the raw lhu in s1. Tried n u16 / u16 casts / nx() inline / body inline: no. */
#include "actor.h"
typedef struct { u16 prev; u16 next; u16 x4; } Lnk;
typedef struct { Vec v; u8 pad[0x110]; } Ent;
extern Lnk *gSfxSystemSbss_00201FD4;
extern Ent *gSfxSystemSbss_00201FC0;
extern u16 gSfxAllSdata_00201CA4;
extern Mtx D_002229D0;
void Actor_BuildRotMatrix_0_00146600(Actor *, Mtx *);
void sceVu0InversMatrix(Mtx *, Mtx *);
void sceVu0MulMatrix(Mtx *, Mtx *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
static inline void fin(s32 a, s32 b) {
    gSfxSystemSbss_00201FD4[a].next = gSfxSystemSbss_00201FD4[b].next;
    gSfxSystemSbss_00201FD4[a].prev = b;
    gSfxSystemSbss_00201FD4[b].next = a;
}
static inline void swp(u16 a, u16 b) {
    if (gSfxSystemSbss_00201FD4[a].prev != 0xFFFF) gSfxSystemSbss_00201FD4[gSfxSystemSbss_00201FD4[a].prev].next = b;
    gSfxSystemSbss_00201FD4[b].prev = gSfxSystemSbss_00201FD4[a].prev;
    if (gSfxSystemSbss_00201FD4[b].next != 0xFFFF) gSfxSystemSbss_00201FD4[gSfxSystemSbss_00201FD4[b].next].prev = a;
    fin(a, b);
}
void Sfx_SortByDepth_0_001679E0(u16 id) {
    u16 cur;
    s32 swapped;
    s32 c;
    s32 n;
    Mtx m;
    Mtx m2;
    Vec a;
    Vec b;
    if (id == 0xFFFF) return;
    Actor_BuildRotMatrix_0_00146600(gPlayerSbss_002022E4, &m);
    sceVu0InversMatrix(&m, &m);
    sceVu0MulMatrix(&m2, &D_002229D0, &m);
    cur = gSfxAllSdata_00201CA4;
    do {
        swapped = 0;
        while ((n = gSfxSystemSbss_00201FD4[cur].next) != 0xFFFF) {
            c = cur;
            sceVu0CopyVector(&a, &gSfxSystemSbss_00201FC0[c].v);
            sceVu0CopyVector(&b, &gSfxSystemSbss_00201FC0[n].v);
            sceVu0ApplyMatrix(&a, &m2, &a);
            sceVu0ApplyMatrix(&b, &m2, &b);
            if (b.z / b.w < a.z / a.w) {
                if (gSfxSystemSbss_00201FD4[c].prev == 0xFFFF) gSfxAllSdata_00201CA4 = n;
                swp(c, n);
                swapped = 1;
            } else {
                cur = n;
            }
        }
    } while (swapped);
}
#else
INCLUDE_ASM(Sfx_SortByDepth_0_001679E0);
#endif
