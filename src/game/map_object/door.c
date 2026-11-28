#include "m2c.h"
#include "game/map_object.h"
typedef struct { s32 type; s32 a; s32 b; s32 c; u8 pad[0x20]; } Msg;
typedef struct { u8 pad[0x1A]; u16 v; u8 pad2[0x14]; } E30_Door_CheckOpen_0_001B8F70;
typedef struct { u8 pad[0x53]; u8 f; u8 pad2[0x2C]; } E80_Door_CheckOpen_0_001B8F70;
typedef struct { s32 id; u8 pad[0x6A]; u16 n; u8 pad2[0xC8]; E30_Door_CheckOpen_0_001B8F70 *e30; u8 pad3[0x44]; E80_Door_CheckOpen_0_001B8F70 *e80; } Obj_Door_CheckOpen_0_001B8F70;
typedef struct { u8 pad[0x18]; u16 x18; u16 v; u8 pad1C[8]; u8 p24:6; u8 k24:2; u8 pad25[3]; s16 x28; u8 pad2A[6]; } E30_Door_UpdateLocked_0_001B90F0;
typedef struct { u8 pad[0x52]; u8 a0:5; u8 b5:1; u8 b6:1; u8 b7:1; u8 c0:1; u8 c1:1; u8 c2:6; u8 pad2[0x2C]; } E80_Door_UpdateLocked_0_001B90F0;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x3A]; } E40;
typedef struct { s32 id; u8 pad[0x6A]; u16 n; u8 pad2[0xC8]; E30_Door_UpdateLocked_0_001B90F0 *e30; u8 pad3[0x34]; E40 *e40; u8 pad4[0xC]; E80_Door_UpdateLocked_0_001B90F0 *e80; } Obj_Door_UpdateLocked_0_001B90F0;
extern s32 gMapSbss_00201E80;
extern s8 gDoorSbss_00202030;
s32 Door_CheckOpen_0_001B8F70(s16 arg0);
void memset(void *, s32, s32);
s32 Event_CheckTrigger_0_00179F80(Msg *);
s32 MapObj_CheckFacing_0_001B9610(void *, s32);
void MapObj_SetAnimFrame_0_001B87C0(Obj_Door_UpdateLocked_0_001B90F0 *, u32, s32, s32, f32, f32);
void MapState_SetField_0_001A9E10(s32, u16, u8);
void MapObj_SpawnContainedItem_0_001BB760(Obj_Door_UpdateLocked_0_001B90F0 *, u32, s32, E30_Door_UpdateLocked_0_001B90F0 *, s32);

/* Door_CheckOpen_0_001B8F70 */
#define MapObj_CheckFacing_0_001B9610 MapObj_CheckFacing_0_001B9610__as_Door_CheckOpen_0_001B8F70
s32 MapObj_CheckFacing_0_001B9610__as_Door_CheckOpen_0_001B8F70(Obj_Door_CheckOpen_0_001B8F70 *, s32);

s32 Door_CheckOpen_0_001B8F70(s16 arg0) {
    Msg msg;
    E30_Door_CheckOpen_0_001B8F70 *e;
    Obj_Door_CheckOpen_0_001B8F70 *o;
    s32 i;
    s32 j;
    s32 m;
    s32 ret;
    s32 r;
    s32 id;
    Obj_Door_CheckOpen_0_001B8F70 ***pp;

    pp = (Obj_Door_CheckOpen_0_001B8F70 ***)&gMapSbss_00201E80 + 2;
    ret = 0;
    j = 0;
    do {
        if (*pp != NULL) {
            o = **pp;
            if (o != NULL) {
                for (i = 0; i < o->n; i++) {
                    e = &o->e30[i];
                    if (((u64)((s64)o->e80[i].f << 0x3E) >> 0x3F) == 0 && MapObj_CheckFacing_0_001B9610(o, i) != 0) {
                        m = e->v % 100;
                        id = o->id;
                        if (m == 0) {
                            r = 0;
                        } else {
                            gDoorSbss_00202030 = arg0;
                            memset(&msg, 0, 0x30);
                            msg.type = 3;
                            msg.a = m;
                            msg.b = id;
                            msg.c = i;
                            r = Event_CheckTrigger_0_00179F80(&msg);
                        }
                        ret |= r;
                    }
                }
            }
        }
        j++;
        pp++;
    } while (j < 2);
    return ret;
}
#undef MapObj_CheckFacing_0_001B9610

/* Door_UpdateLocked_0_001B90F0 */
#define MapObj_CheckFacing_0_001B9610 MapObj_CheckFacing_0_001B9610__as_Door_UpdateLocked_0_001B90F0
s32 MapObj_CheckFacing_0_001B9610__as_Door_UpdateLocked_0_001B90F0(Obj_Door_UpdateLocked_0_001B90F0 *, s32);

s32 Door_UpdateLocked_0_001B90F0(void) {
    Msg msg;
    E40 *t;
    Obj_Door_UpdateLocked_0_001B90F0 ***pp;
    Obj_Door_UpdateLocked_0_001B90F0 *o;
    s32 i;
    s32 j;
    E30_Door_UpdateLocked_0_001B90F0 *e;
    E80_Door_UpdateLocked_0_001B90F0 *f;
    s32 m;
    s32 id;

    pp = (Obj_Door_UpdateLocked_0_001B90F0 ***)&gMapSbss_00201E80 + 2;
    j = 0;
    do {
        if (*pp != NULL) {
            o = **pp;
            if (o != NULL) {
                for (i = 0; i < o->n; i++) {
                    e = &o->e30[i];
                    f = &o->e80[i];
                    t = &o->e40[e->x18];
                    if (f->c1 == 0 && MapObj_CheckFacing_0_001B9610(o, i) != 0) {
                        if (t->x4 == 1 && e->k24 == 1 && !f->b6) {
                            MapObj_SetAnimFrame_0_001B87C0(o, i, 11, 0, 0.0f, 1.0f);
                            f->b6 = 1;
                            MapState_SetField_0_001A9E10(o->id, i, 1);
                        } else if (t->x4 == 3 && !f->b5) {
                            MapObj_SetAnimFrame_0_001B87C0(o, i, 10, 0, 0.0f, 1.0f);
                            f->b5 = 1;
                            MapState_SetField_0_001A9E10(o->id, i, 1);
                            MapObj_SpawnContainedItem_0_001BB760(o, i, e->x28, e, 1);
                        }
                        m = e->v % 100;
                        id = o->id;
                        if (m != 0) {
                            memset(&msg, 0, 0x30);
                            msg.type = 7;
                            msg.a = m;
                            msg.b = id;
                            msg.c = i;
                            Event_CheckTrigger_0_00179F80(&msg);
                        }
                    }
                }
            }
        }
        j++;
        pp++;
    } while (j < 2);
    return 0;
}
#undef MapObj_CheckFacing_0_001B9610

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gDoorSbss_00202030 */
s8 gDoorSbss_00202030;
#endif
