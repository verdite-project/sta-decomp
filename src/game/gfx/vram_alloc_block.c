/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Vram_AllocBlock_1_00176FB0.c. The matching build takes it from the assembly that
 * texture.c includes (INCLUDE_ASM(Vram_AllocBlock_1_00176FB0)). */
#ifdef NONMATCHING
/* NEAR Vram_AllocBlock_1_00176FB0: 184 of 241 words differ positionally (meaningless with len diff) (built 237 vs 241); difflib: 11 opcode-level
 * diffs, 121 instrs differ incl. registers (prev: 159 words, len-1, 15 opcode diffs).
 * Fixed: s16 return type (no sext at return), s32 n (no sext of n at Vram_FreeBlock_0_00177380(n)),
 * s32 param copied to a u32 local a0 after i = x (gives retail s2=i, s1=a0).
 * Still differs: a0 copy is scheduled at entry (retail: bne delay slot), base address C4 kept in a3 and
 * i*16 in a2 in retail; this cascades into register names in every branch; 4 missing
 * instrs: retail recomputes n*16 in branch 2 and &D[i].next in branch 3 (reg pressure), plus pad nops.
 * Tried: perm of all 6 local decls (no effect), Owner **po pointer, inline body wrapper,
 * a0 copy positions/types (s32/u32/u16/void*), fnext compare order. */
#include "m2c.h"
typedef struct { u8 pad[0x22]; s16 x22; } Owner;
typedef struct {
    s16 prev, next, fnext, fprev;
    u16 off, size;
    Owner *owner;
} Blk;
extern Blk D_0047F0C0[];
extern s16 D_004830D8[];
extern s16 D_004830DA[];
extern s16 D_004830DC[];
extern s16 D_004830DE[];
void Vram_FreeBlock_0_00177380(s32);

s16 Vram_AllocBlock_1_00176FB0(s32 x) {
    s16 i;
    u32 a0;
    Owner *o;
    s32 n;
    Owner *on;
    s32 p;
    s16 h;

    i = x;
    a0 = x;
    o = D_0047F0C0[i].owner;
    D_004830DE[0]--;
    if (i == D_0047F0C0[i].fnext) {
        D_004830DC[0] = -1;
    } else {
        D_0047F0C0[D_0047F0C0[i].fnext].fprev = D_0047F0C0[i].fprev;
        D_0047F0C0[D_0047F0C0[i].fprev].fnext = D_0047F0C0[i].fnext;
        if (D_004830DC[0] == i) D_004830DC[0] = D_0047F0C0[i].fnext;
    }
    n = D_0047F0C0[i].next;
    on = D_0047F0C0[n].owner;
    if ((on != NULL || n == 0) && (D_0047F0C0[D_0047F0C0[i].prev].owner != NULL || i == D_0047F0C0[i].prev)) {
        D_004830DA[0]++;
        h = D_004830D8[0];
        if (h == -1) {
            D_004830D8[0] = a0;
            D_0047F0C0[i].fnext = a0;
            D_0047F0C0[i].fprev = a0;
        } else {
            D_0047F0C0[i].fnext = h;
            D_0047F0C0[i].fprev = D_0047F0C0[h].fprev;
            D_0047F0C0[D_0047F0C0[i].fnext].fprev = a0;
            D_0047F0C0[D_0047F0C0[i].fprev].fnext = a0;
            D_004830D8[0] = a0;
        }
        D_0047F0C0[i].owner = NULL;
        i = a0;
    } else if (on == NULL && n != 0 && D_0047F0C0[D_0047F0C0[i].prev].owner == NULL && i != D_0047F0C0[i].prev) {
        p = D_0047F0C0[i].prev;
        D_0047F0C0[p].off -= D_0047F0C0[i].size;
        D_0047F0C0[D_0047F0C0[i].prev].size += D_0047F0C0[i].size;
        D_0047F0C0[D_0047F0C0[i].prev].off -= D_0047F0C0[n].size;
        D_0047F0C0[D_0047F0C0[i].prev].size += D_0047F0C0[n].size;
        i = D_0047F0C0[i].prev;
        Vram_FreeBlock_0_00177380(n);
        Vram_FreeBlock_0_00177380(a0);
    } else if (on == NULL && n != 0) {
        D_0047F0C0[n].size += D_0047F0C0[i].size;
        i = D_0047F0C0[i].next;
        Vram_FreeBlock_0_00177380(a0);
    } else if (D_0047F0C0[D_0047F0C0[i].prev].owner == NULL && i != D_0047F0C0[i].prev) {
        p = D_0047F0C0[i].prev;
        D_0047F0C0[p].off -= D_0047F0C0[i].size;
        D_0047F0C0[D_0047F0C0[i].prev].size += D_0047F0C0[i].size;
        i = D_0047F0C0[i].prev;
        Vram_FreeBlock_0_00177380(a0);
    }
    o->x22 = -1;
    return i;
}
#endif
