#include "include_asm.h"
#include "m2c.h"
typedef struct { u8 pad[0x14]; s32 x14; s32 x18; } Hdr;
extern s32 D_002020C4;
extern Hdr *D_002020C8;
extern Hdr **D_002020CC;
extern s32 D_002020D0;
extern s32 D_0048D350[];
extern s32 D_0048D354[];
extern s32 D_0048D358[];
extern u8 D_001FCCC0[];
extern u8 D_001FCCD0[];
extern u8 D_001FCCE0[];
void Font_Load_3_00188830(s32 a0);
void Arc_LoadFile_2_00159DD0(s32, s32, void *, s32 *);
s32 Tex_HashName_2_00177F80(void *);
s32 Tex_Find_1_00177AF0(s32, s32);

/* text_00188010 */
#ifdef NONMATCHING
/* best-effort C: text_render.c */
#else
INCLUDE_ASM(Text_Render_2_00188010);
#endif

/* Font_Load_3_00188830 */
void Font_Load_3_00188830(s32 a0) {
    s32 x;
    D_002020C4 = a0;
    Arc_LoadFile_2_00159DD0(0x84A34CE9, a0, &D_002020D0, &x);
    Arc_LoadFile_2_00159DD0(0x84A23D27, a0, &D_002020CC, &x);
    D_0048D350[0] = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FCCC0), D_002020D0);
    D_0048D354[0] = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FCCD0), D_002020D0);
    D_0048D358[0] = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FCCE0), D_002020D0);
    D_002020C8 = *D_002020CC;
    D_002020C8->x14 = (s32)((u8 *)D_002020C8 + D_002020C8->x14);
    D_002020C8->x18 = (s32)((u8 *)D_002020C8 + D_002020C8->x18);
}
