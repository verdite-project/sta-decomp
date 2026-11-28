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
