#include "include_asm.h"
#include "m2c.h"
typedef struct { u8 pad[0x10]; s32 *p; } S;
extern s8 D_001FB900[];
extern s8 D_001FB901[];
extern s8 D_001FB902[];
extern s8 D_001FB903[];
s32 Tex_FindAnim_0_0016FF80(S *arg0);
s32 Node_FindById_2_0014DCD0(s32, s32);

/* text_0016FB80 */
#ifdef NONMATCHING
/* best-effort C: tex_load_animated.c */
#else
INCLUDE_ASM(Tex_LoadAnimated_0_0016FB80);
#endif

/* Tex_FindAnim_0_0016FF80 */
s32 Tex_FindAnim_0_0016FF80(S *arg0) {
    s32 v = Node_FindById_2_0014DCD0(*arg0->p, D_001FB900[0] | (D_001FB901[0] << 8) | (D_001FB902[0] << 0x10) | (D_001FB903[0] << 0x18));
    if (v == 0) {
        return 0;
    }
    return v - *arg0->p;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sfx_all_rodata.c): D_001FB8F8__grp: D_001FB8F8@0x0, D_001FB8F9@0x1, D_001FB8FA@0x2, D_001FB8FB@0x3, D_001FB900@0x8, D_001FB901@0x9, D_001FB902@0xa, D_001FB903@0xb, D_001FB908@0x10, D_001FB909@0x11, D_001FB90A@0x12 */
u8 D_001FB8F8__grp[0x13] __attribute__((aligned(8))) = { 0x54, 0x58, 0x46, 0x4e, 0, 0, 0, 0, 0x54, 0x41, 0x4e, 0x49, 0, 0, 0, 0, 0x54, 0x54, 0x49 };
#endif
