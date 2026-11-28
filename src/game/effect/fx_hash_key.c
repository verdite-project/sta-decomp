/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Fx_HashKey_1_00164A60.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR 36/81 (unchanged). Shape right; retail puts each xor result in the rotate temp's register (or rD,srl,sll; xor rD,rD,load),
 * ours xors into the loaded value's register. Operand order of ^ is ignored by MWCC; tried temps, h^=, inline rotl, s32/u32 types,
 * p[i] vs p++, local copies of params, b38. Note: s32 i < 40 (signed) fully unrolls (67 words); 40u gives the 8x+remainder shape. */
#include "common.h"
/* NEAR: 36/81 words differ. Shape is right (s32 i vs 40u gives the target's 8x unroll + remainder loop,
 * `p += 1` gives the in-place pointer IV, `h = R; h = h ^ q[i];` matches the q tail). Remaining diff:
 * register naming / xor operand order inside the unrolled main body and remainder ordering. */
u32 Fx_HashKey_1_00164A60(u32 h, u32 *p, u32 *q) {
    s32 i;
    for (i = 0; i < 40u; i++) {
        h = ((h >> 24) | (h << 8)) ^ *p;
        p += 1;
    }
    for (i = 0; i < 4; i++) {
        h = ((h >> 24) | (h << 8));
        h = h ^ q[i];
    }
    return h;
}
#else
INCLUDE_ASM(Fx_HashKey_1_00164A60);
#endif
