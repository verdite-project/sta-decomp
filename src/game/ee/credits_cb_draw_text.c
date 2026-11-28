#include "common.h"
#include "game/ee.h"
typedef struct { u8 b[8]; } B8;
typedef struct { u8 b[4]; } C4;
typedef struct { f32 x, y; s32 z[0]; } __attribute__((aligned(8))) V2;
typedef struct { u8 p0[5]; u8 x5; u8 p6[0x1A]; u32 x20; u8 p24[4]; f32 x28; } O;
typedef struct { u8 p0[4]; O *x4; u8 p8[0x10]; u16 *x18; s32 x1C; f32 x20; f32 x24; u8 p28[8]; u8 x30[4]; u8 x34; u8 p35[0xB]; B8 x40[8]; } T;
typedef struct { u8 p0[0x1C]; s32 x1C[3]; u8 p28[0x10]; s64 x38[3]; s64 x50[3]; u8 p68[0x10]; s32 x78; } G;
extern G D_004BC2F0;
extern f32 D_004BC360[];
#ifndef NONMATCHING
extern u16 D_00201E68[];
#else
/* data twins (src/game/data/sdata.c): D_00201E68 */
static u16 D_00201E68[0x4] = { 0, 0, 0, 0 };
#endif
extern f32 D_00201B90;
void GsText_SetQword_0_001E1E80(s32, s64, s64);
void GsText_Begin_1_001E23C8(void);
void GsText_End_1_001E2430(void);
void GsText_SetSpacing_0_001E2A18(f32);
void GsText_SetColorIdx_0_001E2AB0(s32);
void GsText_SetAlign_0_001E2AD8(s32);
void GsText_GetPos_1_001E2B40(f32 *);
void GsText_Measure_2_001E2B88(u16 *, f32 *, f32 *, s32);
void GsText_DrawString_2_001E2748(V2 *, u16 *);

void CreditsCb_DrawText_0_001E4518(T *p) {
    V2 pos;
    V2 t;
    u32 n;
    s32 m = 0;
    u16 *s;
    f32 w, h;

    u8 a;
    s32 i;
    s32 k;
    f32 f;


    t.x = p->x20; t.y = p->x24; pos = t;
    n = p->x4->x20;
    if (n >= 3) n = 2;
    GsText_SetBuffer_0_001E1E70(D_004BC2F0.x1C[n]);
    GsText_SetQword_0_001E1E80(0, D_004BC2F0.x38[n], D_004BC2F0.x50[n]);
    GsText_Begin_1_001E23C8();
    switch (p->x4->x5 & 0xF) {
    case 0: m = 2; break;
    case 1: break;
    case 2: m = 1; break;
    }
    GsText_SetAlign_0_001E2AD8((p->x4->x5 >> 4) ? m : (m | 4));
    GsText_SetSpacing_0_001E2A18(p->x4->x28);
    s = p->x18;
    if (*s != 10) {
        h = w = 0.0f;
        GsText_Measure_2_001E2B88(s, &w, &h, 1);
        if (pos.x > 640.0f || pos.x + (s32)w < 0.0f || pos.y > 448.0f || pos.y + (s32)h < 0.0f) {
            GsText_DrawString_2_001E2748(&pos, D_00201E68);
        } else {

            C4 col = { p->x30[0], p->x30[1], p->x30[2], p->x30[3] };


            a = col.b[3];
            if (D_004BC2F0.x78 != 0) {
                col.b[3] = a / (u8)(D_004BC2F0.x78 + 1);
                GsText_SetColorIdx_0_001E2AB0(*(s32 *)&col);
                i = D_004BC2F0.x78 - 1;
                if (i >= 0) {
                f = D_00201B90;
                k = D_004BC2F0.x78 + 1;
                do {
                    { V2 u; u.x = pos.x; u.y = pos.y; t = u; }

                    if (!(i & 1)) {
                        t.y += (k / 2) * f;
                        GsText_DrawString_2_001E2748(&t, s);
                    } else {
                        t.y -= (k / 2) * f;
                        GsText_DrawString_2_001E2748(&t, s);
                    }
                i--; k--;
                } while (i >= 0);
                }
                col.b[3] = a - col.b[3] * D_004BC2F0.x78;
            }

            GsText_SetColorIdx_0_001E2AB0(*(s32 *)&col);
            GsText_DrawString_2_001E2748(&pos, s);
        }
        for (i = D_004BC2F0.x78 - 1; i >= 0; i--) {
            if (i == 0)
                p->x40[0] = *(B8 *)&pos;
            else
                *(B8 *)((u8 *)p + i * 8 + 0x40) = *(B8 *)((u8 *)p + i * 8 + 0x38);
        }
        GsText_GetPos_1_001E2B40(D_004BC360);
    } else {
        GsText_DrawString_2_001E2748(&pos, s);
        GsText_GetPos_1_001E2B40(D_004BC360);
        D_004BC360[0] = pos.x;
    }
    GsText_End_1_001E2430();
}
