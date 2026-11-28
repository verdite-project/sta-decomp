#include "common.h"
#include "m2c.h"
#include "game/player.h"
#include "game/ui.h"
#include "game/math.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { u8 pad[8]; u8 x8; } E;
typedef struct { u16 v[8]; } H;
typedef struct { f32 v[4]; } F;
#ifndef NONMATCHING
extern f32 D_00201D78;
#else
/* data twins (src/game/data/sdata.c): D_00201D78 */
static f32 D_00201D78 = -2.99f;
#endif
void Status_Draw_0_0019DF90(E *e);
void Status_DrawStats_0_0019E090(f32 f);
s8* Msg_GetText_2_00195B10(s32);
void Text_Draw_2_001875C0(s8 *, s32, Col, f32, f32, f32);
H* PlayerData_Get_2_001C9BA0(void);
s8* Player_GetBodyState_1_001C9B60(void);
void Player_CalcStats_0_0019A500(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);
void Menu_DrawStatRing_0_00186440(f32, H *, H *, H *, H *);
void Menu_DrawRingD_0_00185510(f32, H *);
void Menu_DrawRingE_0_00185B40(f32, s8 *);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);

/* Status_Draw_0_0019DF90 */
#define Status_DrawStats_0_0019E090 Status_DrawStats_0_0019E090__as_Status_Draw_0_0019DF90
void Status_DrawStats_0_0019E090__as_Status_Draw_0_0019DF90(f32, E *);

void Status_Draw_0_0019DF90(E *e) {
    Col c;
    Menu_SetFlags_0_0018A310(0xC);
    if (!(D_00201D78 <= -2.49f)) Status_DrawStats_0_0019E090(D_00201D78, e);
    if (e->x8 == 0x14) {
        D_00201D78 = Approachf_3_00187770(D_00201D78, -0.02f, 3.5f);
        c.w = 0x80FFFFFF;
        if (D_004A32C8[0] >= 0) {
            Text_Draw_2_001875C0(Msg_GetText_2_00195B10(D_004A32C8[0] + 0xA), 2, c, 622.0f, 17.0f, 1.0f);
        }
    } else {
        D_00201D78 = Approachf_3_00187770(D_00201D78, -2.99f, 3.5f);
    }
}
#undef Status_DrawStats_0_0019E090

/* Status_DrawStats_0_0019E090 */
void Status_DrawStats_0_0019E090(f32 f) {
    s32 r8C;
    s32 r88;
    s32 r84;
    H t70;
    H a60;
    H a50;
    H a40;
    H a30;
    s8 *s;
    s32 i;

    PlayerData_Get_2_001C9BA0();
    s = Player_GetBodyState_1_001C9B60();
    t70 = *PlayerData_Get_2_001C9BA0();
    if (Player_Exists_3_001C9BF0()) {
        a40 = *(H *)(s + 0x460);
        *(F *)&a30 = *(F *)(s + 0x470);
        Player_CalcStats_0_0019A500(&a60, &a50, &r8C, &r88, &r84, -1, 0, 0);
    } else {
        return;
    }
    for (i = 0; i < 8; i++) {
        a40.v[7 - i] -= a60.v[7 - i];
        a30.v[7 - i] -= a50.v[7 - i];
    }
    Menu_DrawStatRing_0_00186440(f, &a60, &a50, &a40, &a30);
    Menu_SetOffset_0_00185B30(0, 0);
    Menu_DrawRingD_0_00185510(f, &t70);
    Menu_DrawRingE_0_00185B40(f, s);
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawFrame_0_00185390(f, 1, 5, D_004A32C8[0]);
}
