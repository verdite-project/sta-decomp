#include "common.h"
#include "game/ee.h"
void FlushCache(s32);
u64 sceGsSyncPath(s32, s32); /* declared u64: frees v0/v1 so the D2_ stores allocate as retail */
u32 *GifTag_SetAd_1_001E51A8(void *, u16, s32);
u32 *GifTag_Build_2_001E51D0(void *, s32, s32, s32, s32, s32, u64);
u32 *GifTag_SetReg_1_001E52A8(void *, s64, s64);
u32 *Vec4i_Set_1_001E52B8(void *, u32, u32, u32, u32);
typedef struct { u32 a, b, c, d; } Q4;

void Gs_DrawSpriteDirect_0_001E52D0(Rect *r, u32 *uv, CreditsNode *node) {
    u64 t;
    u32 *p;

    if (r->x0 < 0x280 && r->y0 < 0xE0 && r->x1 >= 0 && r->y1 >= 0 && r->x0 != r->x1 && r->y0 != r->y1) {
        Gs_UploadTim_1_001E54E8(node->imageResource, &t, 0);
        p = GifTag_SetAd_1_001E51A8((void *)0x70000000, 0xA, 7);
        p = GifTag_Build_2_001E51D0(p, 1, 1, 0x5E, 0, 9, 0x52521EEEEULL);
        p = GifTag_SetReg_1_001E52A8(p, 8, 5);
        p = GifTag_SetReg_1_001E52A8(p, 0x47, 0x71001);
        p = GifTag_SetReg_1_001E52A8(p, 0x42, 0x44);
        p = GifTag_SetReg_1_001E52A8(p, 6, t);
        p = Vec4i_Set_1_001E52B8(p, (u32)node->image.color[0], (u32)node->image.color[1],
                                (u32)node->image.color[2], (u32)node->image.color[3]);
        p = Vec4i_Set_1_001E52B8(p, uv[0], uv[1], 0x3F800000, 0);
        p = Vec4i_Set_1_001E52B8(p, (r->x0 + 0x6C0) << 4, (r->y0 / 2 + 0x790) << 4, 0x1000000, 0);
        p = Vec4i_Set_1_001E52B8(p, uv[2], uv[3], 0x3F800000, 0);
        p = Vec4i_Set_1_001E52B8(p, (r->x1 + 0x6C0) << 4, (r->y1 / 2 + 0x790) << 4, 0x1000000, 0);
        sceGsSyncPath(0, 0);
        *(volatile s32 *)0x1000A020 = 0;
        *(volatile s32 *)0x1000A010 = 0;
        *(volatile s32 *)0x1000A030 = 0xF0000000;
        FlushCache(0);
        *(volatile s32 *)0x1000A000 = 0x145;
        sceGsSyncPath(0, 0);
    }
}

