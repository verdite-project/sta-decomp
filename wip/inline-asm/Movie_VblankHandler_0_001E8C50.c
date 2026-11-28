#include "common.h"
extern s32 gMovieSbss_002023EC;
extern s32 gMovieSbss_002023F4;
extern s32 D_004BDECC[];
asm s32 Movie_VblankHandler_0_001E8C50(void) {
    lw $2, gMovieSbss_002023EC
    beqz $2, L1
    nop
    lw $2, gMovieSbss_002023F4
    beqz $2, L1
    nop
    lw $2, D_004BDECC
    blez $2, L0
    nop
    lw $2, D_004BDECC
    addiu $2, $2, -1
    sw $2, D_004BDECC
    nop
L0:
    sw $0, gMovieSbss_002023F4
    nop
L1:
    sync
    ei
    jr $31
    daddu $2, $0, $0
}

