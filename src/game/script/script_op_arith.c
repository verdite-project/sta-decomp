#include "game/script.h"
/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Script_OpArith_1_00165A30.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 5 of 238 words (unchanged). Retail: empty then-branch `bnez isf -> lw s2,0xCC(f bits); b join (delay = join lw)`, store `sw s2` merged at join. Tried ~60 variants: self-assign then, if(isf) acc=f, ternary, r-temp, inline early-return helpers, union acc/f, isf u8/u32/s8, b38. if(!isf){if(acc&&acc){}} gets the exact branch shape but with nop delay + pad nop (240 words). */
#include "m2c.h"
typedef struct { s32 type; union { s32 i; f32 f; } v; } Val;
typedef struct { u8 pad[8]; u32 *pc; } Ctx;
void Script_FetchOperand_2_00165940(void *, Ctx *, u32 *, Val *);
void Script_LoadLocal_1_00165400(Val *, s32, s32);
void Script_StoreLocal_0_00165260(void *, Val *, Ctx *, s32, s32);
void Script_StoreGlobal_0_00165340(void *, Val *, s32, s32);

void Script_OpArith_1_00165A30(void *o, Ctx *s) {
    f32 f;
    Val a;
    Val b;
    s32 x;
    s32 isf;
    u8 op;
    u8 cont;
    s32 acc;
    u8 done;
    u32 w;
    u32 c;
    u32 *p;
    u32 k;

    op = 0xFF;
    cont = 1;
    s->pc++;
    w = s->pc[0];
    x = s->pc[1];
    acc = 0;
    Script_FetchOperand_2_00165940(o, s, s->pc, &a);
    done = 0;
    s->pc += 2;
    isf = a.type == 6;
    do {
        if (done == 0) {
            Script_FetchOperand_2_00165940(o, s, s->pc, &b);
            s->pc += 2;
            if (!isf) {
                switch (op) {
                case 0xFF: acc = b.v.i; break;
                case 0: acc += b.v.i; break;
                case 1: acc -= b.v.i; break;
                case 2: acc *= b.v.i; break;
                case 3: acc /= b.v.i; break;
                case 4: acc %= b.v.i; break;
                case 5: acc <<= b.v.i; break;
                case 6: acc >>= b.v.i; break;
                case 7: acc &= b.v.i; break;
                case 8: acc |= b.v.i; break;
                }
            } else {
                switch (op) {
                case 0xFF: f = b.v.f; break;
                case 0: f += b.v.f; break;
                case 1: f -= b.v.f; break;
                case 2: f *= b.v.f; break;
                case 3: f /= b.v.f; break;
                }
            }
            op = 0xFF;
        } else {
            p = s->pc;
            c = *p;
            switch (c & 0xFF) {
            case 0xFF:
                s->pc = p + 1;
                cont = 0;
                break;
            case 4:
                op = c >> 8;
                s->pc = p + 1;
                break;
            }
        }
        done = !done;
    } while (cont);
    if (!isf) { a.v.i = acc; } else { a.v.i = *(s32 *)&f; }
    k = (w & ~0xFF) >> 8;
    switch (w & 0xFF) {
    case 1: Script_LoadLocal_1_00165400(&a, k, x); break;
    case 2: Script_StoreLocal_0_00165260(o, &a, s, k, x); break;
    case 3: Script_StoreGlobal_0_00165340(o, &a, k, x); break;
    }
}
#else
INCLUDE_ASM(Script_OpArith_1_00165A30);
#endif
