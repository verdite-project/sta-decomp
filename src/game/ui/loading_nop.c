/* Best-effort C for the NONMATCHING build; the retail code (Loading_Nop_0_0018E440.c,
 * an inline-assembly match in wip/) only reads *p and sets a dead register. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
void Loading_Nop_0_0018E440(s32 *p) {
    (void)*(volatile s32 *)p;
}
#else
INCLUDE_ASM(Loading_Nop_0_0018E440);
#endif
