#include "common.h"
#include "game/ui.h"
typedef Bits8 B8;
typedef struct { u8 pad[0xC]; s16 xC, xE, x10; u8 pad12[6]; u16 x18; u8 pad1A[0xE]; s16 x28; u8 pad2A[6]; } A;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad44[0xF]; B8 x53; u8 pad54[0x2C]; } B;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x3A]; } C;
typedef struct { s32 x0; u8 pad4[0x6A]; u16 x6E; u8 pad70[0xC8]; A *x138; u8 pad13C[0x34]; C *x170; u8 pad174[0xC]; B *x180; } O;
typedef struct { u8 pad[0x8C]; O **x8C; u8 pad90[0x19]; B8 xA9; u8 padAA[2]; s16 xAC; } R;
extern O **gMapSbss_00201E80[2];
s8 *Mdl_GetFrameData_0_001715B0(s32);
s32 MapObj_CheckFacing_0_001B9610(O *, s32);
void MapObj_SetAnimFrame_0_001B87C0(f32, f32, O *, s32, s32, s32);
void MapState_SetField_0_001A9E10(s32, u16, s32);
s32 MapState_GetField_0_001A9D50(s32, u16);
s32 Inventory_CountItem_0_001CC0C0(s32, s32);
s32 Inventory_CanCarry_0_001CBE40(s32);
R *ItemObj_SpawnAt_0_001AE620(s16, s8 *, Vec *);

R *Chest_CheckOpen_0_001B9360(void) {
    O *o;
    s32 i;
    s32 k;
    A *a;
    B *b;
    C *c;
    s8 *p;
    R *r;
    Vec v;
    O ***pp;

    for (k = 0, pp = &gMapSbss_00201E80[2]; k < 2; k++, pp++) {
        if (*pp == NULL) continue;
        o = **pp;
        if (o == NULL) continue;
        for (i = 0; i < o->x6E; i++) {
            a = &o->x138[i];
            b = &o->x180[i];
            c = &o->x170[a->x18];
            p = Mdl_GetFrameData_0_001715B0(b->x40);
            if (c->x4 != 5) continue;
            if (b->x53.b1) continue;
            if (!MapObj_CheckFacing_0_001B9610(o, i)) continue;
            if (!b->x53.b3) {
                MapObj_SetAnimFrame_0_001B87C0(0.0f, 1.0f, o, i, 10, 0);
                b->x53.b3 = 1;
                MapState_SetField_0_001A9E10(o->x0, i, 1);
            }
            if (MapState_GetField_0_001A9D50(o->x0, i) & 2) {
                Msg_ShowById_1_0018B0E0(0xCA);
                return NULL;
            }
            if (!Inventory_CountItem_0_001CC0C0(a->x28, 0)) {
                Msg_ShowById_1_0018B0E0(0xCA);
                return NULL;
            }
            if (!Inventory_CanCarry_0_001CBE40(a->x28)) {
                Msg_ShowById_1_0018B0E0(0xCC);
                return NULL;
            }
            v.x = 0.00024414062f * a->xC;
            v.y = 0.00024414062f * a->xE;
            v.z = 0.00024414062f * a->x10;
            v.w = 0.0f;
            r = ItemObj_SpawnAt_0_001AE620(a->x28, p + 0x230, &v);
            if (r == NULL) {
                return NULL;
            }
            r->x8C = gMapSbss_00201E80[k + 2];
            r->xAC = i;
            r->xA9.b2 = 1;
            return r;
        }
    }
    return NULL;
}
