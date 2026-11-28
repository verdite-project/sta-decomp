#include "m2c.h"
#include "game/data.h"
#include "game/gfx.h"
typedef union { u128 q; u32 w[4]; } Q;
void ScreenFx_DrawSprite_0_001323C0(s8 *, u16, u16, s8 *);
u128 *GsPkt_Alloc_3_00154A80(s32);
extern s8 D_33C0[];

void ScreenFx_DrawModelOverlay_0_00132A70(s8 *arg0) {
    Q a;
    Q b;
    s8 *e = *(s8 **)(arg0 + 0xC);
    s32 off;
    u128 *p;

    if (*(u16 *)(*(s8 **)arg0 + 0x1E) != 0) {
        if (*(s32 *)(e + 4) != 0) goto setup;
        return;
loop:
        do {
            off = *(s32 *)(arg0 + 0x28);
            p = GsPkt_Alloc_3_00154A80(1);
            a.q = 0;
            a.w[0] = *(u32 *)e | 0x30000000;
            a.w[1] = (u32)(e + 0x10) + off;
            *p = a.q;
            GsPkt_Commit_1_00154A70();
            Tex_FlushAll_1_00176AE0();
            ScreenFx_DrawSprite_0_001323C0(e, gScreenFxBeginSbss_00201F04, gScreenFxBeginSbss_00201F08, arg0);
            p = GsPkt_Alloc_3_00154A80(1); *p = b.q;
            GsPkt_Commit_1_00154A70();
            Tex_FlushAll_1_00176AE0();
            if (*(s32 *)(e + 8) == 0) {
                break;
            }
            e += *(s32 *)(e + 8);
        } while (*(s32 *)(e + 4) != 0);
        return;
setup:
        b.q = 0;
        b.w[0] = 0x10000000;
        b.w[3] = 0x10000000;
        b.w[2] = ((u32)D_33C0 >> 3) | 0x15000000;
        goto loop;
    }
end:;
}

