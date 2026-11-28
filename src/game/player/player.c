#include "actor.h"
#include "m2c.h"
#include "common.h"
#include "obj3d.h"
#include "game/core.h"
#include "game/data.h"
#include "game/gfx.h"
#include "game/input.h"
#include "game/item.h"
#include "game/model.h"
#include "game/player.h"
#include "game/save.h"
#include "game/sound.h"
#include "game/ui.h"
#include "game/collision.h"
#include "game/map.h"
#include "game/map_object.h"
#include "game/script.h"
typedef union { u32 w; Flags8 f; } Col_Player_DrawWeapon_0_001BCFF0;
typedef struct { Vec p; Vec r; u8 pad[0x40]; Col_Player_DrawWeapon_0_001BCFF0 c; } P_Player_DrawWeapon_0_001BCFF0;
typedef struct { u8 pad[0x160]; Flags8 f; u8 pad2[3]; s32 h; u8 pad3[8]; } E_Player_DrawWeapon_0_001BCFF0_;
typedef struct { u8 pad[0x240]; Col_Player_DrawWeapon_0_001BCFF0 c; } C;
typedef struct { s32 *pp; u8 pad[0x20]; Flags8 f; } H2;
typedef struct { H2 *h; } H_Player_DrawWeapon_0_001BCFF0;
typedef struct { u128 q[10]; } Big;
typedef struct {
    u8 pad0[0x78];
    s32 n;
    u8 pad7C[0x19A - 0x7C];
    u8 a[0x100];
    u8 b[0x100];
    u8 pad39A[0x4B0 - 0x39A];
    C *x4B0;
    P_Player_DrawWeapon_0_001BCFF0 *tbl[0x19];
    s8 *x518;
    E_Player_DrawWeapon_0_001BCFF0_ *x51C;
    u8 pad520[0x80];
    Flags8 f5A0;
    Flags8 f5A1;
} O;
typedef struct { Vec m[2]; } M_Player_DrawWeapon_0_001BCFF0;
typedef struct { f32 m[4][4]; } MtxF;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col_Player_UpdateArea_0_001BD4E0;
typedef struct { u8 pad0[0x36]; u8 x36[0xB6 - 0x36]; u8 xB6, xB7, xB8, xB9; u8 padBA[4]; u16 xBE; u16 xC0; u8 xC2; } T158;
typedef struct { s32 x0; u8 pad4[0x154]; T158 *x158; u8 pad15C[0x2C]; u8 *x188; } M_Player_UpdateArea_0_001BD4E0;
typedef struct { u8 pad0[0x1E]; s16 x1E; u8 pad20; s8 x21; s8 x22; u8 pad23[5]; u8 b0:3; u8 b3:1; } N;
typedef struct { u8 pad0[0x26]; s16 x26; } C8;
typedef struct { u8 pad0[0xC0]; M_Player_UpdateArea_0_001BD4E0 *xC0; u8 padC4[4]; C8 *xC8; } Q_Player_DrawWeapon_0_001BCFF0_;
typedef struct { u8 pad0[0xC]; u8 lo:4; u8 hi:4; u8 m:3; } S1;
typedef struct { u8 pad0[0x10]; Q_Player_DrawWeapon_0_001BCFF0_ *x10; u8 pad14[0xD0 - 0x14]; u8 xD0[0x2C]; S1 *xFC; u8 pad100[0x3BF - 0x100]; u8 x3BF; } P_Player_UpdateArea_0_001BD4E0;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad1C[0x40 - 0x1C]; Vec pos; u8 p50[0x3A0 - 0x50];
    union { struct { u16 a:7; u16 lvl:6; u16 r:3; } h; struct { u8 a; u8 r:7; u8 b7:1; } c; } f3A0; } P_Player_CheckLadder_0_001BE050;
typedef struct { f32 a[4]; f32 b[4]; } Ray_Player_DrawWeapon_0_001BCFF0;
typedef struct { s32 w[16]; } Res_Player_DrawWeapon_0_001BCFF0_;
typedef struct { u16 a : 7; u16 v : 6; } BF_Player_DrawWeapon_0_001BCFF0_;
typedef struct { u16 a:6; u16 v:6; u16 b:1; u16 c:3; } BF39E;
typedef struct { u16 a:7; u16 v:6; u16 p:2; u16 b15:1; } BF3A0;
typedef struct { u8 pad[0xC8]; s32 xC8; u8 padCC[0x34]; Vec x100; } Q10;
typedef struct { u8 pad[0xC]; u8 xC; u8 xD; } Q15C;
typedef struct {
    u8 pad0[0x10];
    Q10 *x10;
    u8 pad14[4];
    Vec *x18;
    u8 pad1C[0x24];
    Vec x40;
    Vec x50;
    u8 pad60[0x70];
    Vec xD0;
    u8 padE0[0x14];
    s32 xF4;
    u8 padF8[0x38];
    Vec x130;
    Vec x140;
    u8 pad150[4];
    s32 x154;
    u8 pad158[4];
    Q15C *x15C;
    u8 pad160[0x39E - 0x160];
    BF39E f39E;
    BF3A0 f3A0;
    Flags8 f3A2;
    u8 pad3A3;
    f32 x3A4;
    u8 pad3A8[4];
    u8 x3AC;
} P_Player_DrawWeapon_0_001BCFF0_;
typedef struct { u8 pad[0x20]; f32 x20; } O18_Player_DrawWeapon_0_001BCFF0_;
typedef struct {
    u8 pad[0x18];
    O18_Player_DrawWeapon_0_001BCFF0_ *x18;
    u8 pad1C[0x50 - 0x1C];
    Vec x50;
    u8 pad60[0x374 - 0x60];
    f32 f374;
    u8 pad378[0x37C - 0x378];
    f32 f37C;
    u8 pad380[0x394 - 0x380];
    s8 x394;
    s8 x395;
    u8 pad396[0x39C - 0x396];
    u32 b39C:8;
    u32 b8:6;
    u32 m:4;
    u32 n:4;
    u32 o:6;
    u32 r:4;
    Flags8 f3A0;
    Flags8 f3A1;
    union { u8 b; struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:2; u8 b7:1; } f; } f3A2;
    u8 pad3A3[0x3AD - 0x3A3];
    u8 x3AD;
    u8 x3AE;
    u8 x3AF;
    u8 pad3B0[0x3BE - 0x3B0];
    u8 x3BE;
    u8 pad3BF[0x3CC - 0x3BF];
    s8 x3CC;
    s8 x3CD;
    s8 x3CE;
    s8 x3CF;
    f32 f3D0;
    u8 x3D4;
    u8 x3D5;
    Flags8 f3D6;
    u8 pad3D7[0x3F0 - 0x3D7];
    Vec x3F0;
    u8 x400[0x41E - 0x400];
    u16 x41E;
    s8 x420;
    s8 x421;
    u16 x422;
    u8 pad424[0x430 - 0x424];
    f32 f430;
    f32 f434;
    f32 f438;
    f32 f43C;
    f32 f440;
    f32 f444;
} S_Player_DrawWeapon_0_001BCFF0;
typedef struct { u8 pad[0x78]; s32 x78; u8 p7c[0x518-0x7C]; s8 *unk518; } AH;
typedef struct { u8 pad[0x94]; Flags8 f94; } R_Player_UpdateEquipSounds_0_001BF940;
typedef struct {
    u8 pad[0x390];
    R_Player_UpdateEquipSounds_0_001BF940 *x390;
    u8 pad394[2];
    u8 x396;
    u8 pad397[0x39C - 0x397];
    u8 x39C;
    u8 pad39D[0x3C0 - 0x39D];
    Obj3D *x3C0;
    Obj3D *x3C4;
    Obj3D *x3C8;
    u8 pad3CC[0x3D5 - 0x3CC];
    u8 x3D5;
} S_Player_UpdateEquipSounds_0_001BF940;
typedef struct { u8 pad[0x80]; s16 x80; s16 x82; u8 pad84[4]; s16 x88; u8 pad8A[0x94 - 0x8A]; Flags8 f94; } R_Player_UpdateHeldItem_0_001BFB70;
typedef struct {
    u8 pad[0x390];
    R_Player_UpdateHeldItem_0_001BFB70 *x390;
    u8 pad394[0x3B8 - 0x394];
    s16 x3B8;
    s16 x3BA;
    s16 x3BC;
    u8 pad3BE[2];
    Obj3D *x3C0;
    Obj3D *x3C4;
    Obj3D *x3C8;
    s8 x3CC;
    s8 x3CD;
    s8 x3CE;
    s8 x3CF;
    u8 pad3D0[4];
    s8 x3D4;
    s8 x3D5;
    Flags8 f3D6;
} S_Player_UpdateHeldItem_0_001BFB70;
typedef Bits8 Bits;
typedef struct {
    u8 pad[0x40];
    u16 x40;
    u16 x42;
    u8 x44;
    u8 x45;
    u8 x46;
    u8 x47;
    u8 x48;
    u8 x49;
    u8 pad4A[0xC];
    u8 x56;
    u8 x57;
    u8 pad58[0x38];
} E_Player_UpdateEquipSounds_0_001BF940;
typedef struct {
    u16 h[6];
    u8 padC[4];
    s32 w[6];
    u8 pad28[9];
    Bits f31;
    u8 pad32[0xE];
} D;
typedef struct { u8 pad[6]; s16 x6; } Q_Player_UpdateEquipSounds_0_001BF940;
typedef struct {
    u8 pad[0x18];
    f32 *p18;
    u8 pad1C[0x374 - 0x1C];
    f32 x374;
    s8 *x378;
    u8 pad37C[0x14];
    Q_Player_UpdateEquipSounds_0_001BF940 *x390;
    u8 pad394[3];
    s8 x397;
    u8 pad398[2];
    s16 x39A;
    u8 pad39C[6];
    Bits f3A2;
    u8 pad3A3[0x46A - 0x3A3];
    u16 x46A;
    u8 pad46C[4];
    u16 x470[6];
} P_Player_UpdateEquipSounds_0_001BF940;
typedef struct {
    u8 pad[0x39C];
    u32 b39C:8;
    u32 b8:6;
    u32 m:4;
    u32 n:4;
    u32 o:6;
    u32 r:4;
    u8 pad3A0[0x414 - 0x3A0];
    void *x414;
} S_Player_UpdateEquipSounds_0_001BF940_;
typedef struct { u8 pad[0x9C]; s16 x9C; } R_Player_DrawWeapon_0_001BCFF0;
typedef struct { u8 pad[0x518]; u8 *x518; } A_Player_UpdateEquipSounds_0_001BF940_;
typedef struct {
    u8 pad[0x39C];
    u32 lo:13;
    u32 b13:1;
    u32 f14:4;
    u32 f18:4;
    u32 hi:10;
    u8 pad3A0[0x414 - 0x3A0];
    Obj3D *x414;
} S_Player_UpdatePickup_0_001C0A10;
typedef struct { u8 pad[0x30]; s32 x30; } P_Player_UpdatePickup_0_001C0A10;
typedef struct { u8 pad[0x94]; Flags8 f94; } R_Player_HandleAction_0_001C0E60;
typedef struct {
    u8 pad[0x390];
    R_Player_HandleAction_0_001C0E60 *x390;
    u8 pad394[0x39C - 0x394];
    u8 x39C;
    u8 pad39D;
    u16 lo : 6;
    u16 f39E : 6;
    u16 hi : 4;
    u8 pad3A0[2];
    Flags8 f3A2;
    u8 pad3A3[0x3D5 - 0x3A3];
    u8 x3D5;
    Flags8 f3D6;
} S_Player_HandleAction_0_001C0E60;
typedef struct { u8 pad[0x30]; s32 x30; } Ev;
typedef struct { s32 w[9]; s32 hit; s32 pad; u8 *tri; s32 w2[4]; } Res_Player_UpdateEquipSounds_0_001BF940;
typedef struct { u8 pad[0x18]; s8 *m18; u8 pad1C[0x382]; u16 lo:6; u16 f6:6; u16 b12:1; u16 f13:3; u8 m3A0[0x1F]; u8 m3BF; } P_Player_CheckFrontWall_0_001C1140;
typedef struct { u8 pad[0xC]; u8 t:4; u8 r:4; u8 padD[3]; f32 x, y, z; } Tri;
typedef struct { Vec p; u8 pad10[0x14]; s32 x24; u8 pad28[4]; Tri *x2C; u8 pad30[0x10]; } Hit;
typedef struct { u8 pad[0x18]; Vec *o; u8 pad1C[0x39E - 0x1C]; u16 a:6; u16 b:6; u16 c:1; u16 d:3; f32 f3A0; f32 f3A4; } P_Player_CheckLedge_0_001C13B0;
typedef struct { u8 b0:1; u8 b1:1; u8 rest:6; } BFa;
typedef struct { u8 pad:3; u8 b3:1; u8 rest:4; } BFb;
typedef struct { s8 pad[0x94]; u8 b94; } S390_Player_UpdateInput_0_001C1900;
typedef struct { s8 pad[0xA8]; BFa a8; } SV;
typedef struct { s8 pad[0x390]; S390_Player_UpdateInput_0_001C1900 *p390; s8 pad2[0x39C-0x394]; u8 b39C; s8 pad3[0x3C0-0x39D]; SV *p3C0; SV *p3C4; } SS_Player_UpdateInput_0_001C1900;
typedef struct { u8 pad[0x94]; u8 x94; } S390_Player_HandleAttackInput_0_001C1A00;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } O18_Player_UpdateEquipSounds_0_001BF940;
typedef struct {
    u8 pad0[0x18];
    O18_Player_UpdateEquipSounds_0_001BF940 *x18;
    u8 pad1C[0x390 - 0x1C];
    S390_Player_HandleAttackInput_0_001C1A00 *x390;
    s8 x394;
    u8 pad395[0x39C - 0x395];
    u8 x39C;
    u8 pad39D[3];
    u8 x3A0;
    Flags8 f3A1;
    u8 pad3A2[0x3CD - 0x3A2];
    s8 x3CD;
    u8 pad3CE[2];
    f32 x3D0;
    u8 x3D4;
    u8 x3D5;
    u8 pad3D6[0xA];
    u16 x3E0[8];
} P_Player_HandleAttackInput_0_001C1A00;
typedef struct { u8 pad[0x54]; s16 x54; s16 x56; } T;
typedef struct { u8 pad[3]; u8 x3; } U_Player_DrawWeapon_0_001BCFF0__;
typedef struct { u8 pad[0x2C]; f32 x2C; u32 x30; u32 x34; } K;
typedef struct { u8 b0:4; u8 f:3; u8 b7:1; } F30;
typedef struct { u16 h[6]; u8 padC[4]; u8 y[0x20]; F30 f30; u8 pad31[0xF]; } X_Player_HandleAttackInput_0_001C1A00;
typedef struct { u8 pad[0x30]; u32 x30; u32 x34; } Pad;
typedef struct { u8 pad[3]; u8 x3; } R_Player_HandleMagicInput_1_001C2190;
typedef struct {
    u8 pad[0x39C]; u8 m39C; u8 pad2[0x3D5 - 0x39D]; u8 m3D5; u8 pad3[0x3E0 - 0x3D6]; u16 h[8];
} S_Player_HandleMagicInput_1_001C2190;
typedef struct { u8 lo:4; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF_Player_UpdateEquipSounds_0_001BF940;
typedef struct {
    u8 pad0[0x396]; s8 x396; u8 pad1; s16 x398;
    u8 pad2[0x3CC - 0x39A]; s8 x3cc; u8 pad3[8]; u8 x3d5; BF_Player_UpdateEquipSounds_0_001BF940 f; u8 pad4[9]; u16 x3e0[8];
} Sub_Player_DrawWeapon_0_001BCFF0;
typedef struct { u8 pad[0x180]; Sub_Player_DrawWeapon_0_001BCFF0 s; } Obj2;
typedef struct { u8 pad[0x516]; s8 x516; } Hd;
typedef struct { u8 pad[0x518]; s8 *x518; } Obj_Player_DrawWeapon_0_001BCFF0;
typedef struct { u8 pad[0x20]; f32 x20, x24, x28, x2c; } Arg_Player_DrawWeapon_0_001BCFF0;
typedef struct { u8 pad[0x20]; f32 rot; } R_Player_ReadStick_0_001C27C0;
typedef struct { u8 pad[0x48]; s32 slow; } Q_Player_ReadStick_0_001C27C0;
typedef struct {
    u8 pad0[0x18]; R_Player_ReadStick_0_001C27C0 *r;
    u8 pad1[0x390 - 0x1C]; Q_Player_ReadStick_0_001C27C0 *q;
    u8 pad2[0x3A0 - 0x394]; u8 flg;
    u8 pad3[0x42C - 0x3A1]; f32 dt;
} A_Player_UpdatePickup_0_001C0A10_;
typedef struct { u8 pad[0x18]; f32 x, y; u8 pad2[0x34 - 0x20]; s32 btn; } In_Player_ReadStick_0_001C27C0;
typedef struct { u8 pad[0x50]; Vec v50; u8 p60[0x380 - 0x60]; f32 f380; f32 f384; f32 f388; u32 u38C; u8 p390[0x3A1 - 0x390];
    Flags8 f3A1; Flags8 f3A2; u8 p3A3[0x3BF - 0x3A3]; u8 u3BF; u8 p3C0[0x454 - 0x3C0]; f32 f454; } P_Player_UpdateHeadBob_1_001C2A50;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } Q_Player_UpdateWalk_1_001C2DB0;
typedef struct { u8 pad[0x48]; s32 x48; } R_Player_UpdateWalk_1_001C2DB0;
typedef struct { u8 lo4:4; u8 b4:1; u8 b5:3; } B39D_Player_UpdateWalk_1_001C2DB0;
typedef union { struct { u16 a:7; u16 f:6; u16 c:3; } h; struct { u8 lo; Flags8 hi; } b; } U3A0;
typedef struct {
    u8 pad[0x18];
    Q_Player_UpdateWalk_1_001C2DB0 *x18;
    u8 pad1C[0x50 - 0x1C];
    Vec v50;
    u8 pad60[0x390 - 0x60];
    R_Player_UpdateWalk_1_001C2DB0 *x390;
    u8 pad394[0x39D - 0x394];
    B39D_Player_UpdateWalk_1_001C2DB0 f39D;
    u8 pad39E[2];
    U3A0 f3A0;
    u8 pad3A2[0x3CD - 0x3A2];
    s8 x3CD;
    u8 pad3CE[0x428 - 0x3CE];
    f32 f428;
    f32 f42C;
} P_Player_UpdateWalk_1_001C2DB0;
typedef struct { s8 pad[0x20]; f32 f20; f32 f24; s8 pad2[0x38]; Vec v60; s8 pad3[0x10]; Vec v80; } P18;
typedef struct { s8 pad[0x48]; s32 x48; } P390;
typedef struct { u8 n:4; u8 b4:1; u8 r:3; } B39D_Player_UpdateTurn_0_001C34F0;
typedef struct { u16 pad:7; u16 cnt:6; u16 r:3; } B3A0;
typedef struct {
    s8 pad[0x18]; P18 *p18; s8 pad1[0x50 - 0x1C]; Vec v50;
    s8 pad2[0x390 - 0x60]; P390 *p390; s8 pad3[0x39D - 0x394]; B39D_Player_UpdateTurn_0_001C34F0 b39D; s8 pad4[2]; B3A0 h3A0; s8 pad5[2]; f32 f3A4;
} SS_Player_UpdateTurn_0_001C34F0;
typedef struct { u8 pad0[0x24]; f32 x24; u8 pad28[0x38]; Vec v60; u8 pad70[0x10]; Vec v80; } Q_Player_UpdateFall_0_001C39D0;
typedef struct { u8 pad0[0x48]; s32 x48; } R_Player_UpdateFall_0_001C39D0;
typedef struct {
    u8 pad0[0x18];
    Q_Player_UpdateFall_0_001C39D0 *x18;
    u8 pad1C[0x40 - 0x1C];
    Vec v40;
    Vec v50;
    u8 pad60[0x390 - 0x60];
    R_Player_UpdateFall_0_001C39D0 *x390;
    u8 pad394[0x3A0 - 0x394];
    u16 lo:7; u16 f:6; u16 hi:3;
    u8 pad3A2[2];
    f32 x3A4;
} P_Player_UpdateFall_0_001C39D0;
typedef struct { f32 x0, x4, x8, xC, x10, x14, x18, x1C; } In_Player_UpdateFall_0_001C39D0;
typedef struct { u8 pad0[0xC]; u8 c0 : 4; u8 c4 : 4; u8 d0 : 3; u8 d3 : 5; } X_Player_UpdateSlide_0_001C3EF0;
typedef struct {
    u8 pad0[0x18];
    Q_Player_UpdateFall_0_001C39D0 *x18;
    u8 pad1C[0x40 - 0x1C];
    Vec v40;
    Vec v50;
    u8 pad60[0x154 - 0x60];
    s32 x154;
    u8 pad158[4];
    X_Player_UpdateSlide_0_001C3EF0 *x15C;
    u8 pad160[0x390 - 0x160];
    R_Player_UpdateFall_0_001C39D0 *x390;
    u8 pad394[0x39E - 0x394];
    u16 lo : 6; u16 cnt : 6; u16 b12 : 1; u16 hi3 : 3;
    u16 lo7 : 7; u16 f : 6; u16 hi : 3;
    u8 pad3A2[2];
    f32 x3A4;
} P_Player_UpdateSlide_0_001C3EF0;
typedef struct { f32 f[12]; u32 x30; u32 x34; } Out;
typedef struct { u8 pad[0x39C]; u32 lo : 14; u32 m : 4; } S_Player_UpdatePickup_0_001C0A10_;
typedef struct {
    u8 pad0[0x10];
    s8 *x10;
    u8 pad14[4];
    s8 *o;
    u8 pad1C[0x40 - 0x1C];
    Vec pos;
    u8 pad50[0xB0 - 0x50];
    Vec vB0;
    Vec vC0;
    MtxF mD0;
    Vec v110;
    Vec v120;
    Vec m130;
    Vec v140;
    u8 pad150[4];
    s32 x154;
    u8 pad158[0x3A2 - 0x158];
    u8 b0:1; u8 b1:7;
} P_PlayerProc_Collide_0_001C5150;
typedef Bits8 BF;
typedef struct {
    u8 pad0[0x18]; s8 *x18; u8 pad1[0x39C - 0x1C]; u8 x39C; u8 pad2[0x3D6 - 0x39D]; BF f;
} Sub_PlayerProc_Collide_0_001C5150;
typedef struct { u8 pad[8]; u16 mode; } Arg_PlayerProc_Collide_0_001C5150;
typedef struct { f32 x, y, z; } Vec_PlayerProc_Attack_0_001C55A0;
typedef struct { u8 pad[8]; u16 id; u8 pad2[2]; f32 xC; f32 x10; f32 x14; } Mdl;
typedef struct { u8 pad0[0x30]; f32 x30; u8 pad34[0x2C]; Vec v60; } S18;
typedef struct { u8 pad0[0x280]; Vec v280; u8 pad290[0x3C0 - 0x290]; Vec v3C0; u8 pad3D0[0x20]; f32 x3F0; f32 x3F4; f32 x3F8; } S2C;
typedef struct { u8 pad0[0x94]; u8 b0:1; } S390_Player_DrawWeapon_0_001BCFF0;
typedef struct {
    u8 pad0[0xC];
    s32 *xC;
    u8 pad10[8];
    S18 *x18;
    u8 pad1C[0xC];
    Mdl *x28;
    S2C *x2C;
    u8 pad30[0x380 - 0x30];
    f32 x380;
    u8 pad384[0x390 - 0x384];
    S390_Player_DrawWeapon_0_001BCFF0 *x390;
    u8 pad394[0x39C - 0x394];
    u8 x39C;
    u8 pad39D[4];
    u8 a0:5; u8 a5:1; u8 a6:2;
    u8 pad3A2[0x3AD - 0x3A2];
    s8 x3AD;
    s8 x3AE;
    u8 pad3AF[0x3CC - 0x3AF];
    u8 x3CC;
    u8 x3CD;
    u8 x3CE;
    u8 x3CF;
    u8 pad3D0[4];
    u8 x3D4;
    u8 x3D5;
    u8 c0:1; u8 c1:1; u8 c2:1; u8 c3:1; u8 c4:1; u8 c5:1; u8 c6:1; u8 c7:1;
    u8 d0:1; u8 d1:2;
} P_PlayerProc_Animate_0_001C5750;
typedef struct {
    u8 pad[0x39C];
    u8 u39C;
    u8 pad2[4];
    Flags8 f3A1;
    u8 pad3[0x3D4 - 0x3A2];
    u8 u3D4;
    u8 u3D5;
    Flags8 f3D6;
    union { u8 b; struct { u8 b0:1; u8 b1:2; u8 r:5; } f; } f3D7;
} Obj_Player_UpdateArmBones_0_001C5DE0;
typedef Bits8 B8;
typedef struct { u8 b0:1; u8 f1:2; u8 r:5; } B7;
typedef struct {
    u8 pad[0x3A1]; B8 m3A1; u8 pad2[0x3D5 - 0x3A2]; u8 m3D5; B8 m3D6; B7 m3D7;
} S_Player_UpdateMagicState_0_001C6250;
typedef struct {
    u8 p[0x3CD]; s8 x3CD; s8 x3CE; u8 p3CF[6]; u8 x3D5;
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:2; u8 c3:5;
} S_Player_UpdateSwitchState_0_001C6470;
typedef struct { u8 pad[0x16]; u16 n; } H_Player_UpdateArmBones_0_001C5DE0;
typedef struct { u16 lo:5; u16 mid:5; u16 rest:6; } B_Player_UpdateArmBones_0_001C5DE0__;
typedef struct { u8 a; u8 b; B_Player_UpdateArmBones_0_001C5DE0__ q; } E;
typedef struct { u8 pad[0xC]; f32 c; f32 x10; u8 pad14[0xC]; f32 x20; } R_Player_UpdateArmBones_0_001C5DE0;
typedef struct {
    u8 pad0[0xC];
    H_Player_UpdateArmBones_0_001C5DE0 **h;
    u8 pad10[8];
    s8 *x18;
    u8 pad1C[4];
    E *tbl;
    u8 pad24[4];
    R_Player_UpdateArmBones_0_001C5DE0 *r;
    u8 pad2C[0x3AA];
    Flags8 f3D6;
    Flags8 f3D7;
} S_Player_StartSwitchMotion_1_001C6D40;
typedef union {
    u8 b;
    struct { u8 b0:1; u8 b1:2; u8 b3:5; } f;
} F3;
typedef struct { u8 pad[0x3E0]; u16 ids[8]; } S_Player_IsHitTarget_0_001C7320;
typedef struct { u8 pad[0x2C]; u8 lo:3; u8 mid:3; u8 hi:2; } T_Player_UpdateArmBones_0_001C5DE0__;
typedef struct { u8 pad[2]; u16 x2; u8 pad4[0x4B0]; T_Player_UpdateArmBones_0_001C5DE0__ *tbl[1]; } A_Player_OnHitEnemy_0_001C73C0;
typedef struct { u8 pad[0x390]; s16 *r; u8 pad394[8]; u8 x39C; u8 pad39D[0x3CD - 0x39D]; s8 x3CD; u8 pad3CE[0x3E0 - 0x3CE]; u16 ids[8]; } S_Player_OnHitEnemy_0_001C73C0;
typedef struct {
    u8 p[0x3CD]; s8 x3CD; s8 x3CE; u8 p3CF[6]; u8 x3D5;
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:2; u8 c3:5;
} S_Player_OnHitObject_0_001C7730;
typedef struct { u8 p[0x30]; s32 x30; s32 x34; } A_Player_OnHitObject_0_001C7730;
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { Q a; Q b; } Ray_Player_UpdateArmBones_0_001C5DE0;
typedef struct { s32 w[16]; } Res;
typedef struct { u8 pad[0x94]; u8 x94; } S390_Player_UpdateArmBones_0_001C5DE0;
typedef struct { u8 pad1C[0x390]; S390_Player_UpdateArmBones_0_001C5DE0 *x390; u8 pad394[0x3CD - 0x394]; s8 x3CD; } P_Player_DrawWeapon_0_001BCFF0__;
typedef struct { u16 h[6]; u8 padC[4]; u8 y[0x20]; F30 f30; u8 pad31[0xF]; } X_Player_UpdateArmBones_0_001C5DE0__;
typedef union { u128 q[2]; f32 f[8]; } M;
typedef struct { u8 pad[0x30]; f32 x30; } O18;
typedef struct { u8 pad[0x18]; O18 *x18; } S_Player_UpdateArmBones_0_001C5DE0;
typedef struct { u8 pad[8]; u16 x8; u8 pada[6]; u8 x10[0x20]; u8 lo:4; u8 hi:4; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } X_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x390]; s16 *r; u8 pad394[0x462 - 0x394]; u16 st[7]; } S_Player_TakeHit_1_001C7DC0;
typedef struct { s16 p0; s16 a[3]; s16 p8; s16 b[3]; } Buf;
typedef struct { s16 x0; s16 x2; s16 x4; } R_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x390]; R_Player_TakeHit_1_001C7DC0_ *x390; u8 pad394[0x462 - 0x394]; u16 x462, x464, x466, x468, x46A, x46C, x46E; } S_Player_TakeHitB_1_001C8070;
typedef struct { u8 pad[0xC]; u8 v:3; } T_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x4B0]; T_Player_TakeHit_1_001C7DC0_ *x4B0; } A;
typedef struct { u8 pad[8]; u16 x8; u8 padA[6]; u32 x10[8]; u8 p30:4; u8 pad30:4; u8 a:2; u8 v:1; } B_Player_TakeHit_1_001C7DC0_;
typedef struct {
    u8 pad[0x390];
    R_Player_TakeHit_1_001C7DC0_ *x390;
    u8 pad394[0x39E - 0x394];
    union { struct { u16 a:6; u16 b:6; u16 c:4; } h; struct { u8 lo; u8 b0:4; u8 b4:1; } c; } x39E;
    u8 pad3A0;
    u8 b0:6; u8 b6:1; u8 b7:1;
    u8 pad3A2[0x3BE - 0x3A2];
    u8 x3BE;
    u8 pad3BF[0x410 - 0x3BF];
    s32 x410;
    u8 pad414[0x430 - 0x414];
    f32 x430, x434, x438, x43C, x440, x444;
} S_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x30]; u32 a[8]; u32 b[6]; } R_Player_RollStatusEffect_1_001C8570;
typedef struct { u8 pad[0x390]; R_Player_RollStatusEffect_1_001C8570 *r; u8 pad2[0x46C - 0x394]; u16 x; u16 y; u8 pad3[0x4A0 - 0x470]; u32 c[6]; } S_Player_RollStatusEffect_1_001C8570;
typedef struct { u8 pad[0x30]; u32 x30[8]; s32 x50[8]; } G;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } R;
typedef struct { char pad[0x518]; u8 *p; } S;
typedef struct { char pad[0x37C]; f32 f; char p380[0x22]; unsigned char : 1; unsigned char b : 1; char p3a3[0x5D]; f32 v[4]; } T_Camera_SetPosition_0_001C8EA0;
typedef struct { char pad[0x430]; s32 a; s32 b; f32 v[4]; } T_Camera_SetParams_0_001C8F30;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad1C[0x370 - 0x1C]; f32 f370; u8 p374[0x39C - 0x374]; u8 b39C; u8 p39D[0x3A1 - 0x39D]; u8 r:5; u8 b5:1; u8 r2:2; u8 p3A2[2]; f32 f3A4; u8 p3A8[0x3D0 - 0x3A8]; f32 f3D0; u8 p3D4[0x430 - 0x3D4]; f32 f430; f32 f434; u8 p438[0x454 - 0x438]; f32 f454; } P_Camera_LookAt_0_001C89E0;
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetHeadPos_0_001C93A0;
typedef struct { char p[0x10]; f32 v[4]; } V;
typedef struct { char pad[0x18]; V *v; } T_Player_GetHeadPos_0_001C93A0;
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetPos_1_001C9410;
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetPosB_0_001C9490;
typedef struct { u8 pad[0x18]; s8 *o; } P_Player_SetPosAndGround_0_001C94F0;
typedef struct { char pad[0x518]; u8 *p; } S_Player_SetStartPos_0_001C9630;
typedef struct { char pad[0x18]; f32 *m; } T_Player_SetStartPos_0_001C9630;
typedef struct { u8 pad[0x18]; Vec *m; } S_Player_LoadStartPos_0_001C96F0;
typedef struct { u8 pad[0xF]; s8 b; s16 h[5]; } S1E20;
typedef struct { u8 pad[0x10]; f32 x, y, z; } P_Player_UpdateFrame_0_001C9830;
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetHpS16_0_001C99C0;
typedef struct { char p[4]; s16 h; } U_Player_Warp_0_001C92C0;
typedef struct { char pad[0x518]; u8 *p; } S_Player_IsCrouching_0_001C9A20;
typedef struct { char pad[0x518]; u8 *p; } S_Player_IsMoving_0_001C9A80;
typedef struct { unsigned int : 3; unsigned int f : 1; } B_Player_IsMoving_0_001C9A80;
typedef struct { char pad[0x518]; u8 *p; } S_Player_IsActionLocked_0_001C9AE0;
typedef struct { unsigned int : 14; unsigned int f : 4; } B_Player_IsActionLocked_0_001C9AE0;
typedef struct { char pad[0x25]; unsigned char : 1; unsigned char f : 1; } BF_25_1_1;
extern Flags8 D_00222A50[];
extern Big gPlayerBss_004B4C40;
extern u64 gGsPacketBss_002F1420[];
extern M_Player_UpdateArea_0_001BD4E0 **gMapSbss_00201E80;
extern M_Player_UpdateArea_0_001BD4E0 **gPlayerSbss_002022BC;
extern s32 gSoundSbss_002022B8;
#ifdef NONMATCHING
extern u8 gPlayerBss_004B4D10[];
#endif
extern u32 gGsPacketSdata_00201C5C;
extern f32 gPlayerData_001F2080[];
extern f32 gPlayerData_001F2084[];
extern f32 gPlayerData_001F208C[];
extern f32 gPlayerData_001F2090[];
extern f32 gPlayerData_001F2094[];
extern f32 gPlayerData_001F209C[];
extern f32 gPlayerData_001F20C0[];
extern f32 gPlayerData_001F20C4[];
extern f32 gPlayerData_001F20C8[];
extern f32 gPlayerData_001F20D0[];
extern f32 gPlayerData_001F20D4[];
extern f32 gPlayerData_001F20D8[];
extern f32 gMatrixFromData_001F210C[];
extern MtxF gMatrixFromData_001F2170;
extern Vec gPlayerBss_004B4CE0[];
extern f32 gPlayerBss_004B4CEC[];
extern Vec gPlayerBss_004B4CD0[];
extern f32 gPlayerBss_004B4CDC[];
extern u8 gGlowInitBss_0030D0E0[];
extern Vec gPlayerBss_004B4C40__as_Player_UpdateArea_0_001BD4E0[];
extern s32 gMapSbss_00201E80__as_Player_CheckLadder_0_001BE050;
extern s32 gMapSbss_00201E80__as_Player_CheckCeiling_0_001BE390;
extern s8 gMatrixFromData_001F2170__as_Player_SpawnStepSfx_0_001BE510[];
extern Vec gPlayerBss_004B4CF0;
extern Flags8 D_00222A53[];
extern f32 gMatrixFromData_001F2170__as_Player_GetHandMatrix_1_001C0660[];
extern f32 gMatrixFromData_001F2170__as_Player_BlendHandMatrix_0_001C0860[];
extern f32 gPlayerBss_004B4D00[];
extern f32 gPlayerBss_004B4D04[];
extern f32 gPlayerBss_004B4D08[];
extern f32 gPlayerBss_004B4D0C[];
extern u8 D_00222A54[];
extern Vec gMatrixFromData_001F2140;
extern u16 gMenuBss_00317230[];
extern u16 gMapCommandBss_00317238[];
extern f32 gPlayerBss_0031723C[];
extern f32 gPlayerBss_00317254[];
extern f32 D_00317258[];
extern f32 gPlayerBss_00317274[];
extern f32 D_00317278[];
extern MtxF gMatrixFromData_001F2170__as_Player_UpdatePickup_0_001C0A10_;
extern Vec gZeroVec_003139A0__as_Player_UpdatePickup_0_001C0A10_;
extern Mtx gMatrixFromData_001F2170__as_Player_UpdateEquipSounds_0_001BF940_;
extern f32 gZeroVec_003139A0__as_Player_UpdateEquipSounds_0_001BF940_[];
extern s32 **gPlayerSbss_002022BC__as_Player_UpdateEquipSounds_0_001BF940_;
extern s32 gMapSbss_00201E80__as_Player_UpdateEquipSounds_0_001BF940_;
extern s8 gPlayerBss_004B4CF0__as_Player_UpdateEquipSounds_0_001BF940_[];
extern Obj_Player_DrawWeapon_0_001BCFF0 *gPlayerSbss_002022E4__as_PlayerProc_Attack_0_001C55A0;
extern s32 gMapSbss_00201E80__as_PlayerProc_Collide_0_001C5150_;
extern s32 gPlayerSbss_002022BC__as_PlayerProc_Collide_0_001C5150_;
extern Mtx gMatrixFromData_001F2170__as_PlayerProc_Collide_0_001C5150_;
extern s8 *gPlayerSbss_002022E4__as_Player_UpdateSwitchState_0_001C6470;
extern s8 *gPlayerSbss_002022E4__as_Player_OnHitEnemy_0_001C73C0;
extern u32 gPlayerData_001F3880[][8];
extern G *gPlayerSdata_00201E20;
extern u32 gPlayerData_001F3860[][8];
extern Flags8 D_00222A53__as_Player_AddStatus_1_001C88E0[];
extern s8 *gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___;
extern f32 gMatrixFromData_001F2170__as_Player_UpdateArmBones_0_001C5DE0_____[];
extern u8 gZeroVec_003139A0__as_Player_UpdateArmBones_0_001C5DE0_____[];
extern s32 gMapSbss_00201E80__as_Player_UpdateArmBones_0_001C5DE0_____;
extern u8 D_00222A53__as_Player_UpdateArmBones_0_001C5DE0_____[];
extern S *gPlayerSbss_002022E4__as_Camera_SetPosition_0_001C8EA0;
extern S *gPlayerSbss_002022E4__as_Camera_SetParams_0_001C8F30;
extern void *gPlayerSbss_002022E4__as_Player_Warp_0_001C92C0;
extern u8 *gPlayerSbss_002022E4__as_Player_SetPosition_0_001C9320;
extern S_Player_GetHeadPos_0_001C93A0 *gPlayerSbss_002022E4__as_Player_GetHeadPos_0_001C93A0;
extern S_Player_GetPos_1_001C9410 *gPlayerSbss_002022E4__as_Player_GetPos_1_001C9410;
extern S_Player_GetPosB_0_001C9490 *gPlayerSbss_002022E4__as_Player_GetPosB_0_001C9490;
extern S_Player_SetStartPos_0_001C9630 *gPlayerSbss_002022E4__as_Player_SetStartPos_0_001C9630;
extern f32 gZeroVec_003139A0__as_Player_SetStartPos_0_001C9630[];
extern Vec gZeroVec_003139A0__as_Player_LoadStartPos_0_001C96F0;
extern s8 *gPlayerSbss_002022E4__as_Player_UpdateFrame_0_001C9830;
extern S_Player_GetHpS16_0_001C99C0 *gPlayerSbss_002022E4__as_Player_GetHpS16_0_001C99C0;
extern S_Player_IsCrouching_0_001C9A20 *gPlayerSbss_002022E4__as_Player_IsCrouching_0_001C9A20;
extern S_Player_IsMoving_0_001C9A80 *gPlayerSbss_002022E4__as_Player_IsMoving_0_001C9A80;
extern S_Player_IsActionLocked_0_001C9AE0 *gPlayerSbss_002022E4__as_Player_IsActionLocked_0_001C9AE0;
extern void *gPlayerSbss_002022E4__as_Player_GetBodyState_1_001C9B60;
extern s32 gPlayerSdata_00201E20__as_PlayerData_Get_2_001C9BA0;
extern M2C_UNK gHudMarkerBss_004B4BE0[];
#ifndef NONMATCHING
extern f32 gPlayerSbss_002022DC;
extern u8 gPlayerSdata_00201E24;
extern Vec gPlayerBss_004B4C50[];
extern Vec gPlayerBss_004B4C60[];
extern Vec gPlayerBss_004B4C70[];
extern Vec gPlayerBss_004B4C80[];
extern Vec gPlayerBss_004B4C90[];
extern Vec gPlayerBss_004B4CA0[];
extern Vec gPlayerBss_004B4CB0[];
extern Vec gPlayerBss_004B4CC0[];
extern s32 gPlayerSbss_002022EC;
extern s32 gPlayerSbss_00201EB0;
extern f32 gPlayerSbss_002022E8;
extern f32 gPlayerBss_00317240[];
extern f32 gPlayerBss_0031724C[];
extern f32 gPlayerBss_00317250[];
extern f32 gPlayerBss_0031726C[];
extern f32 gPlayerBss_00317270[];
extern s32 gPlayerSbss_002022D8;
extern char gStrRifle01_001FDC08[];
extern char gStrJyo_001FDC10[];
extern char gStrDm09_001FDC18[];
extern char gStrDm10_001FDC20[];
extern char gStrTen_001FDC28[];
#else
/* data twins (src/game/data/sbss.c): gPlayerSbss_002022DC */
static f32 gPlayerSbss_002022DC;
/* data twins (src/game/data/sdata.c): gPlayerSdata_00201E24 */
static u8 gPlayerSdata_00201E24 = 0x80;
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4C50 */
static Vec gPlayerBss_004B4C50[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4C60 */
static Vec gPlayerBss_004B4C60[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4C70 */
static Vec gPlayerBss_004B4C70[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4C80 */
static Vec gPlayerBss_004B4C80[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4C90 */
static Vec gPlayerBss_004B4C90[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4CA0 */
static Vec gPlayerBss_004B4CA0[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4CB0 */
static Vec gPlayerBss_004B4CB0[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4CC0 */
static Vec gPlayerBss_004B4CC0[0x1];
/* data twins (src/game/data/sbss.c): gPlayerSbss_002022EC */
static s32 gPlayerSbss_002022EC;
/* data twins (src/game/data/sbss.c): gPlayerSbss_00201EB0 */
static s32 gPlayerSbss_00201EB0;
/* data twins (src/game/data/sbss.c): gPlayerSbss_002022E8 */
static f32 gPlayerSbss_002022E8;
/* data twins (src/game/data/vibration_bss.c): gPlayerBss_00317240 */
static f32 gPlayerBss_00317240[0x1];
/* data twins (src/game/data/vibration_bss.c): gPlayerBss_0031724C */
static f32 gPlayerBss_0031724C[0x1];
/* data twins (src/game/data/vibration_bss.c): gPlayerBss_00317250 */
static f32 gPlayerBss_00317250[0x1];
/* data twins (src/game/data/vibration_bss.c): gPlayerBss_0031726C */
static f32 gPlayerBss_0031726C[0x1];
/* data twins (src/game/data/vibration_bss.c): gPlayerBss_00317270 */
static f32 gPlayerBss_00317270[0x1];
/* data twins (src/game/data/sbss.c): gPlayerSbss_002022D8 */
static s32 gPlayerSbss_002022D8;
/* data twins (src/game/data/player_rodata.c): gStrRifle01_001FDC08 */
static char gStrRifle01_001FDC08[0x8] = "RIFLE01\000";
/* data twins (src/game/data/player_rodata.c): gStrJyo_001FDC10 */
static char gStrJyo_001FDC10[0x8] = "JYO\000\000\000\000\000";
/* data twins (src/game/data/player_rodata.c): gStrDm09_001FDC18 */
static char gStrDm09_001FDC18[0x6] = "DM_09\000";
/* data twins (src/game/data/player_rodata.c): gStrDm10_001FDC20 */
static char gStrDm10_001FDC20[0x6] = "DM_10\000";
/* data twins (src/game/data/player_rodata.c): gStrTen_001FDC28 */
static char gStrTen_001FDC28[0x5] = "TEN\000\000";
#endif
extern s8 *gPlayerSbss_002022E4__as_Player_Destroy_1_001C9C30;
extern s8 *gPlayerSbss_002022E4__as_Player_LoadModel_1_001C9CD0;
extern u8 gHudMarkerBss_004B4BE0__as_Player_LoadModel_1_001C9CD0[];
extern void *gPlayerSbss_002022E4__as_Player_Respawn_1_001C9E30;
extern s32 gPlayerSbss_002022E4__as_Player_Exists_3_001C9BF0;
extern s32 gPlayerSdata_00201E20__as_Player_Exists_3_001C9BF0;
extern u8 *gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0;
void Player_DrawWeapon_0_001BCFF0(O *o);
inline s8* get_Player_DrawWeapon_0_001BCFF0__(void);
s32 Player_GetEquipSlot_0_001BD350(s32 a);
void Player_UpdateArea_0_001BD4E0(Actor *a);
s32 Player_CheckLadder_0_001BE050(Actor *a);
s32 Player_CheckCeiling_0_001BE390(s8 *a0);
void Player_SpawnStepSfx_0_001BE510(Actor *a0);
void PlayerProc_UpdateMove_0_001BE7B0(Actor *a0);
void PlayerProc_Update_0_001BEFA0(AH *a0, f32 dt);
void Player_UpdateEquipSounds_0_001BF940(Actor *a0);
s32 Player_UpdateHeldItem_0_001BFB70(Actor *a0);
void Player_FireWeapon_0_001C0020(Actor *a);
s32 Player_TryPickup_0_001C0550(A_Player_UpdateEquipSounds_0_001BF940_ *a0);
void Player_GetHandMatrix_1_001C0660(f32 *out, s32 a1, s32 flag, u32 n);
void Player_BlendHandMatrix_0_001C0860(f32 (*out)[4], s32 a1, u32 a2, s32 flag, f32 t);
void Player_UpdatePickup_0_001C0A10(Actor *a, P_Player_UpdatePickup_0_001C0A10 *p);
void Player_HandleAction_0_001C0E60(Actor *a, Ev *e);
inline s8* get_Player_UpdatePickup_0_001C0A10_(void);
s32 Player_CheckFrontWall_0_001C1140(void);
s32 Player_CheckLedge_0_001C13B0(void);
void Player_UpdateInput_0_001C1900(s8 *arg0, s8 *arg1);
void Player_HandleAttackInput_0_001C1A00(Actor *a0, K *a1);
void Player_HandleMagicInput_1_001C2190(Actor *a, Pad *pad);
void Player_HandleWeaponSwitch_1_001C23E0(Obj_Player_DrawWeapon_0_001BCFF0 *arg0, Arg_Player_DrawWeapon_0_001BCFF0 *arg1);
f32 Player_CalcMoveSpeed_1_001C2640(s8 *arg0);
void Player_ReadStick_0_001C27C0(s8 *arg0, In_Player_ReadStick_0_001C27C0 *in);
void Player_UpdateHeadBob_1_001C2A50(Actor *a);
void Player_UpdateWalk_1_001C2DB0(Actor *a, f32 *in);
void Player_UpdateTurn_0_001C34F0(s8 *arg0, f32 *a);
void Player_UpdateFall_0_001C39D0(Actor *a, In_Player_UpdateFall_0_001C39D0 *in, f32 dt);
void Player_UpdateSlide_0_001C3EF0(Actor *a, In_Player_UpdateFall_0_001C39D0 *in, f32 dt);
void Player_MapControls_0_001C4760(Actor *a, Out *o);
void PlayerProc_Collide_0_001C5150(Actor *a);
void PlayerProc_Attack_0_001C55A0(s32 a0, s32 a1, s32 a2, Arg_PlayerProc_Collide_0_001C5150 *a3, s32 a4, s32 a5);
void PlayerProc_Animate_0_001C5750(Actor *a, f32 dt);
void Player_UpdateArmBones_0_001C5DE0(Actor *a0);
void Player_UpdateAttackState_0_001C5FB0(void);
inline s8* get_Player_UpdateMagicState_0_001C6250(void);
void Player_UpdateMagicState_0_001C6250(void);
void Player_UpdateSwitchState_0_001C6470(void);
inline s8* get_Player_StartAttackMotion_1_001C6590(void);
void Player_StartAttackMotion_1_001C6590(u8 a0);
inline s8* get_Player_StartMagicMotion_0_001C69A0(void);
void Player_StartMagicMotion_0_001C69A0(u8 a0);
inline s8* get_Player_UpdateArmBones_0_001C5DE0_(void);
void Player_StartSwitchMotion_1_001C6D40(u8 a0);
void Player_SetArmMotion_1_001C7020(u16 idx, f32 t, s32 flags, f32 b, f32 c);
s32 Player_IsHitTarget_0_001C7320(u16 *a0);
void Player_Nop_2_001C73B0(void);
void Player_OnHitEnemy_0_001C73C0(A_Player_OnHitEnemy_0_001C73C0 *a0, u32 a1, u8 a2, s32 a3);
void Player_OnHitObject_0_001C7730(A_Player_OnHitObject_0_001C7730 *a, s32 b);
s32 Player_TraceAttack_0_001C7850(s8 *a0, s32 a1);
void Player_InitAttack_0_001C79B0(X_Player_UpdateArmBones_0_001C5DE0__ *x);
inline s8* get_Player_UpdateArmBones_0_001C5DE0__(void);
s32 Player_GetWeaponSegment_0_001C7A70(M *out);
s32 Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *a0);
s32 Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *a0, A *a1);
s32 Player_ApplyDamage_2_001C8320(s32 n, s32 a1, s32 a2, s32 a3);
void Player_AddStatus_1_001C88E0(s32 a, u32 b);
inline s8* get_Camera_LookAt_0_001C89E0(void);
void Camera_LookAt_0_001C89E0(Vec *dir, f32 t);
void Camera_SetPosition_0_001C8EA0(f32 *v, f32 f);
void Camera_Update_1_001C8F90(void *a0);
void Player_Warp_0_001C92C0(s32 arg0);
void Player_SetPosition_0_001C9320(u8 *arg0);
void Player_GetHeadPos_0_001C93A0(f32 *out);
void Player_GetPos_1_001C9410(f32 *v);
void Player_GetPosB_0_001C9490(f32 *v);
void Player_SetPosAndGround_0_001C94F0(f32 *a0);
void Player_SetStartPos_0_001C9630(f32 *a, f32 *b);
void Player_LoadStartPos_0_001C96F0(s8 *a0);
s16 Player_GetHpS16_0_001C99C0(void);
u8 Player_IsCrouching_0_001C9A20(void);
u32 Player_IsMoving_0_001C9A80(void);
u32 Player_IsActionLocked_0_001C9AE0(void);
s32* Player_GetCameraData_0_001C9B40(void);
s32 Player_GetBodyState_1_001C9B60(void);
s32 PlayerData_Get_2_001C9BA0(void);
void PlayerData_Load_1_001C9BB0(s32 arg0);
u8 Player_CopyLightPos_0_001C9C00(f32 *v);
void Player_Destroy_1_001C9C30(void);
void Player_LoadModel_1_001C9CD0(s8 *a);
void PlayerData_InitNew_0_001C9EA0(void);
s8* Mdl_GetFrameData_0_001715B0(void *);
void Mdl_SetLayerTex_0_0016B2D0(H_Player_DrawWeapon_0_001BCFF0 *, Col_Player_DrawWeapon_0_001BCFF0, s32, s32);
void GsPkt_SetReg_3_001543E0(s32, u64);
void Mdl_DrawLitWrap_0_0016B960(s8 *, s32, s32, s8 *, s32, s32);
void Mdl_DrawMeshesC_1_0016D380(s32, H2 *, s8 *, s32, Col_Player_DrawWeapon_0_001BCFF0, s32);
void Seg_Init_1_001502A0(void *, void *, void *, f32);
void Sfx_SetColor_0_00167670(s32, M_Player_DrawWeapon_0_001BCFF0 *);
void Sfx_SetTransform_1_001677C0(s32, s8 *);
s32 Equip_GetSlotItem_1_001CCD90(s32);
N* MapObj_FindCollider_0_001B1D00(M_Player_UpdateArea_0_001BD4E0 *, void *);
void Map_LoadArea_1_001B51F0(M_Player_UpdateArea_0_001BD4E0 *, u8 *, s32);
M_Player_UpdateArea_0_001BD4E0** Map_FindLoaded_0_001B0AE0(M_Player_UpdateArea_0_001BD4E0 *);
void MapObj_SendEvent_1_001B0A80(M_Player_UpdateArea_0_001BD4E0 *, s32);
f32 Lerpf_3_0015DF90(f32, f32, f32);
f32* Map_GetFogEntry_0_001B40F0(M_Player_UpdateArea_0_001BD4E0 *, s32);
void sceVu0InterVector(void *, void *, void *, f32);
void sceVu0RotMatrixX(void *, void *, f32);
void sceVu0RotMatrixY(void *, void *, f32);
void sceVu0ApplyMatrix(Vec*, void *, Vec*);
void sceVu0CopyVector(void *, void *);
void memset(void *, s32, s32);
s32 MapColl_CapsuleCastAll_1_001B3240(s8*, void *, Vec*, s32, s32);
s32 MapColl_CapsuleCast_1_001B2800(s8*, void *, void *, u16, s32, s32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Player_PlayStepSe_1_001CA2D0(s32);
void sceVu0RotMatrixY__as_Player_UpdateArea_0_001BD4E0(MtxF *, MtxF *, f32);
void sceVu0CopyVector__as_Player_CheckLadder_0_001BE050(Vec *, Vec *);
s32 MapColl_CapsuleCast_1_001B2800__as_Player_CheckLadder_0_001BE050(s8 *, MtxF *, Vec *, u16, s32, s32);
void sceVu0RotMatrixY__as_Player_CheckLadder_0_001BE050(MtxF *, MtxF *, f32);
void Sfx_SetTransform_1_001677C0__as_Player_CheckLadder_0_001BE050(s8 *, MtxF *);
void sceVu0CopyVector__as_Player_CheckCeiling_0_001BE390(f32 *, s8 *);
s32 MapColl_CapsuleCast_1_001B2800__as_Player_CheckCeiling_0_001BE390(s8 *, Res_Player_DrawWeapon_0_001BCFF0_ *, Ray_Player_DrawWeapon_0_001BCFF0 *, u16, s32, s32);
s32 MapColl_CapsuleCastAll_1_001B3240__as_Player_CheckCeiling_0_001BE390(s32, Res_Player_DrawWeapon_0_001BCFF0_ *, Ray_Player_DrawWeapon_0_001BCFF0 *, s32, s32);
s32 Sfx_Spawn_2_00169B50__as_Player_SpawnStepSfx_0_001BE510(s32, s32, s32, s32);
void sceVu0RotMatrixY__as_Player_SpawnStepSfx_0_001BE510(f32 *, void *, f32);
void sceVu0CopyVector__as_Player_SpawnStepSfx_0_001BE510(f32 *, s8 *);
void Sfx_SetTransform_1_001677C0__as_Player_SpawnStepSfx_0_001BE510(s32, f32 *);
void Player_PlayStepSe_1_001CA2D0__as_Player_SpawnStepSfx_0_001BE510(u8);
void sceVu0ScaleVector(void *, void *, f32);
void sceVu0AddVector(void *, void *, void *);
void sceVu0SubVector(Vec*, void *, void *);
void sceVu0Normalize(void *, void *);
s32 Enemy_GetAttachMatrix_0_001A5AA0(Actor *, P_Player_DrawWeapon_0_001BCFF0_ *, Mtx *);
void Player_GetForwardVector_2_001456B0(Vec *);
f32 Vec_YawAngle_2_0013FC10(Vec *);
f32 fabsf(f32);
void ScreenFx_EnableWeather_0_00159500(s32);
s32 rand(void);
void sceVu0ApplyMatrix__as_Player_DrawWeapon_0_001BCFF0(Vec *, MtxF *, Vec *);
void sceVu0CopyVector__as_PlayerProc_UpdateMove_0_001BE7B0(Vec *, Vec *);
void sceVu0ApplyMatrix__as_PlayerProc_UpdateMove_0_001BE7B0(Vec *, Mtx *, Vec *);
s32 Sfx_Spawn_2_00169B50__as_PlayerProc_UpdateMove_0_001BE7B0(s32, s32, s32, s32);
s32 Player_CheckCeiling_0_001BE390__as_PlayerProc_UpdateMove_0_001BE7B0(Actor *);
f32 sinf(f32);
s32 Game_GetBusy_0_0012C020(void);
s32 Player_GetLevelInfo_0_001CD980(s8 *, s8 *);
void Player_UpdateStatusEffects_0_001C9FF0(void);
void Player_RecalcStats_1_001CEDC0(s32);
void Player_ApplyEquipVisualB_0_001CE4B0(S_Player_DrawWeapon_0_001BCFF0 *);
void Player_ApplyEquipVisualA_0_001CE370(S_Player_DrawWeapon_0_001BCFF0 *);
s32 ItemType_IsMagic_0_001D1E00(u8);
s32 ItemType_IsWeapon_0_001D1D50(u8);
void sceVu0CopyVector__as_PlayerProc_Update_0_001BEFA0(Vec *, Vec *);
s8* Mdl_GetFrameData_0_001715B0__as_PlayerProc_Update_0_001BEFA0(s32);
u8 Item_GetType_0_001CCDE0(s32);
u8* PlayerData_GetEquipEntry_0_001D1E10(void);
void ItemObj_Free_1_001AF4A0(Obj3D *);
Obj3D* ItemObj_Spawn_0_001AE7C0(s32);
s32 Item_GetType_0_001CCDE0__as_Player_UpdateHeldItem_0_001BFB70(s32);
E_Player_UpdateEquipSounds_0_001BF940* Item_GetTable_1_001AFC90(void);
void Equip_DamageWeapon_0_001CC450(u16);
void sceVu0CopyMatrix(void *, void *);
void Sfx_SetOwner_1_00167600(s8 *, Actor *);
void Sfx_GetState_0_001672B0(s8*, void *);
R_Player_DrawWeapon_0_001BCFF0* ItemObj_FindPickTarget_0_001AC3E0(void);
s32 Inventory_CanCarry_0_001CBE40(s32);
R_Player_DrawWeapon_0_001BCFF0* Chest_CheckOpen_0_001B9360(void);
void sceVu0InversMatrix(f32 (*)[4], f32 *);
void ItemObj_GetScale_0_001ADBA0(s32, f32 *);
void sceVu0MulMatrix(f32 *, f32 (*)[4], f32 (*)[4]);
void sceVu0CopyVector__as_Player_GetHandMatrix_1_001C0660(f32 *, f32 *);
void sceVu0CopyMatrix__as_Player_GetHandMatrix_1_001C0660(f32 (*)[4], f32 *);
void sceVu0RotMatrixY__as_Player_GetHandMatrix_1_001C0660(f32 (*)[4], f32 (*)[4], f32);
void ItemObj_GetMatrix_0_001ADC60(s32, f32 (*)[4]);
void Mtx_ToQuat_2_0015E290(f32 *, f32 (*)[4]);
void Quat_Slerp_2_0015DFA0(f32 *, f32 *, f32 *, f32);
void Quat_ToMatrix_2_0015E180(f32 (*)[4], f32 *);
void sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(f32 *, f32 *);
void Player_GetHandMatrix_1_001C0660__as_Player_BlendHandMatrix_0_001C0860(f32 (*)[4], s32, s32, u32);
void sceVu0CopyMatrix__as_Player_BlendHandMatrix_0_001C0860(f32 (*)[4], void *);
void sceVu0MulMatrix__as_Player_BlendHandMatrix_0_001C0860(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
s32 MapState_GetField_0_001A9D50(s32, u16);
void MapState_SetField_0_001A9E10(s32, u16, u8);
s32 Event_CheckTrigger_0_00179F80(Msg *);
void Inventory_Give_0_001CBCD0(s32);
void Player_UseItem_1_001CAEF0(s32);
void MapColl_ClampIndex_0_001B2160(s32, Res_Player_UpdateEquipSounds_0_001BF940 *, Ray_Player_DrawWeapon_0_001BCFF0 *, s32, s32);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);
s32 ItemType_IsShield_0_001D1DA0(u8);
s32 Snd_GetStreamFlag_0_0012C400(s32);
T* Item_GetData_1_001AFC40(s16);
s16 Inventory_HasItem_0_001CBC20(s16);
s32 ItemType_IsGun_0_001D1DD0(u8);
void Player_CalcAttack_1_001CEBF0(void *, u8*, s8);
s32 Equip_CheckAmmo_0_001CC250(s32);
s32 Option_GetMoveEffect_2_001A9440(void);
void Player_PlayMoveSe_1_001CA4A0(u8, u8);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
s32 Inventory_HasItem_0_001CBC20__as_Player_HandleMagicInput_1_001C2190(s32);
s32 Player_PlayMoveSe_1_001CA4A0__as_Player_UpdateSlide_0_001C3EF0(u32, s32);
s32 PlayerData_GetStatusTimer_0_001CE200(s32);
s32 PlayerData_GetStatusTimer_0_001CE200__as_Player_UpdatePickup_0_001C0A10();
void sceVu0RotMatrixX__as_Player_UpdateEquipSounds_0_001BF940(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY__as_Player_UpdateEquipSounds_0_001BF940(Mtx *, Mtx *, f32);
void Sfx_GetState_0_001672B0__as_Player_UpdateEquipSounds_0_001BF940(s8 *, D *);
void sceVu0AddVector__as_Player_UpdateEquipSounds_0_001BF940(f32 *, f32 *, f32 *);
void Player_BlendHandMatrix_0_001C0860__as_Player_UpdatePickup_0_001C0A10_(Obj3D *, Obj3D *, s32, s32, f32);
s32 Player_TryPickup_0_001C0550__as_Player_UpdatePickup_0_001C0A10_(Actor *);
U_Player_DrawWeapon_0_001BCFF0__* PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_(void);
s8* Sfx_Spawn_2_00169B50__as_Player_UpdatePickup_0_001C0A10_(s16, s32, s32, s32);
void Sfx_GetState_0_001672B0__as_Player_UpdatePickup_0_001C0A10_(s8 *, X_Player_HandleAttackInput_0_001C1A00 *);
void Seg_Init_1_001502A0__as_Player_DrawWeapon_0_001BCFF0_(M_Player_DrawWeapon_0_001BCFF0 *, P_Player_DrawWeapon_0_001BCFF0 *, Vec *, f32);
void sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(Vec *, void *, Vec *, f32);
void sceVu0RotMatrixX__as_Player_DrawWeapon_0_001BCFF0_(MtxF *, MtxF *, f32);
s32 MapColl_CapsuleCastAll_1_001B3240__as_Player_DrawWeapon_0_001BCFF0_(s8 *, MtxF *, Vec *, s32, s32);
void sceVu0ScaleVector__as_Player_DrawWeapon_0_001BCFF0_(Vec *, Vec *, f32);
void sceVu0AddVector__as_Player_DrawWeapon_0_001BCFF0_(Vec *, Vec *, Vec *);
void sceVu0Normalize__as_Player_DrawWeapon_0_001BCFF0_(Vec *, Vec *);
void Player_MapControls_0_001C4760__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *);
void Player_UpdateSlide_0_001C3EF0__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *, f32);
void Player_UpdateFall_0_001C39D0__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *, f32);
void Player_UpdateTurn_0_001C34F0__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *);
void Player_UpdateWalk_1_001C2DB0__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *);
void Player_ReadStick_0_001C27C0__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *);
void Player_UpdateInput_0_001C1900__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *);
void Player_UpdatePickup_0_001C0A10__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *);
void Player_HandleAction_0_001C0E60__as_Player_DrawWeapon_0_001BCFF0_(Actor *, u8 *);
void Sfx_SetTransform_1_001677C0__as_Player_UpdateEquipSounds_0_001BF940_(s8 *, Mtx *);
void sceVu0ApplyMatrix__as_Player_UpdateEquipSounds_0_001BF940_(f32 *, f32 (*)[4], f32 *);
void sceVu0InterVector__as_Player_UpdateEquipSounds_0_001BF940_(f32 *, f32 *, f32 *, f32);
void Seg_Init_1_001502A0__as_Player_UpdateEquipSounds_0_001BF940_(Ray_Player_DrawWeapon_0_001BCFF0 *, f32 *, f32 *, f32);
s32 MapColl_CapsuleCastAll_1_001B3240__as_Player_UpdateEquipSounds_0_001BF940_(s8 *, Hit *, Vec *, s32, s32);
s32 MapColl_SphereCastAll_0_001B34B0(s8 *, Vec *, Vec *, s32, s32);
s32 MapColl_SphereCast_0_001B2B90(s8 *, Vec *, Vec *, u16, s32, s32);
void Attack_PlaySe_0_001D1E80(s32, s32, Arg_PlayerProc_Collide_0_001C5150 *, s32, s32);
s32 Attack_SpawnSfx_0_001D1F20(s32, s8 *, s32, s32, Arg_PlayerProc_Collide_0_001C5150 *, s32, s32);
void Combat_UpdateAttackWrap_0_0013B950(s32, s32, s32, Arg_PlayerProc_Collide_0_001C5150 *, s32, s32);
void MapObj_SnapToGround_0_001B9F10(void *, s8 *, f32, f32);
f32 Mdl_GetMotionLength_0_00173F70(s32, u16);
void Mdl_AnimateWrap_0_00171B70(Mdl *, u16, f32);
void Mdl_UpdateBoneMatricesCur_0_00171540(Mdl *, Mtx *);
void Player_UpdateEquipModel_0_001CE7D0(P_PlayerProc_Animate_0_001C5750 *, s32);
void sceVu0CopyVector__as_PlayerProc_Collide_0_001C5150(Vec *, Vec *);
void sceVu0SubVector__as_Player_DrawWeapon_0_001BCFF0__(Vec *, Vec *, Vec *);
void sceVu0CopyMatrix__as_Player_DrawWeapon_0_001BCFF0__(Mtx *, Mtx *);
void sceVu0AddVector__as_PlayerProc_Collide_0_001C5150_(Vec *, void *, Vec *);
void sceVu0Normalize__as_PlayerProc_Collide_0_001C5150_(Vec *, Vec *);
void sceVu0ScaleVector__as_PlayerProc_Collide_0_001C5150_(Vec *, Vec *, f32);
s32 MapColl_CapsuleCastAll_1_001B3240__as_PlayerProc_Collide_0_001C5150_(s8 *, Vec *, Vec *, s32, s32);
s32 MapColl_CapsuleCast_1_001B2800__as_PlayerProc_Collide_0_001C5150_(s8 *, Vec *, Vec *, u16, s32, s32);
void Sfx_SetOwner_1_00167600__as_PlayerProc_Collide_0_001C5150_(s32, Obj_Player_DrawWeapon_0_001BCFF0 *);
void sceVu0RotMatrixX__as_PlayerProc_Collide_0_001C5150_(Mtx *, Mtx *, f32);
void sceVu0MulMatrix__as_PlayerProc_Collide_0_001C5150_(Vec *, Mtx *, Vec *);
void ItemObj_SetRotation_0_001AD0C0(s32, s32);
void ItemObj_SetAnim_0_001AD1C0(s32, s32);
void Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(s32);
s32 Item_GetMotionId_0_001CC390(s16);
void Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(s32);
void Mdl_SetBoneRotation_0_001710D0(R_Player_UpdateArmBones_0_001C5DE0 *, s16, f32, f32, f32);
void Player_SetArmMotion_1_001C7020__as_Player_StartSwitchMotion_1_001C6D40(f32, u16, s32, f32, f32);
void Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(u16);
void Player_SetArmMotion_1_001C7020__as_Player_UpdateArmBones_0_001C5DE0__(f32, f32, u16, s32, f32);
s32 Player_GetStat_2_001CD450(s32, void *, s32, s32);
s32 Enemy_IsDead_1_0013EEE0(A_Player_OnHitEnemy_0_001C73C0 *);
u32 Enemy_GetMaxHp_2_0013F700(A_Player_OnHitEnemy_0_001C73C0 *);
void Player_PlayHitEnemySe_0_001CA7B0(s8, s32);
s32 MapObj_Hit_0_001B85B0(s32, A_Player_OnHitObject_0_001C7730 *);
u8 MapObj_IsSame_0_001B8F30(s32, s32);
void Coll_ClosestPointB_0_00150160(Ray_Player_UpdateArmBones_0_001C5DE0 *, s8 *, s8 *);
s32 MapColl_RayCast_0_001B23E0(s8 *, Res *, Ray_Player_UpdateArmBones_0_001C5DE0 *, u16, s32, s32);
s32 MapColl_RayCastAll_0_001B2F30(s32, Res *, Ray_Player_UpdateArmBones_0_001C5DE0 *, s32, s32);
void Player_OnHitObject_0_001C7730__as_Player_TraceAttack_0_001C7850(Res *, s32);
void sceVu0CopyVector__as_Player_UpdateArmBones_0_001C5DE0___(s8 *, void *);
void sceVu0CopyVector__as_Player_GetWeaponSegment_0_001C7A70(f32 *, s8 *);
s32 Combat_SumResist_0_001AB500(void *, void *);
s32 Combat_SumResist_0_001AB500__as_Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *, Buf *);
s32 Combat_SumResist_0_001AB500__as_Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *, u16 *);
void Equip_DamageArmor_0_001CC830__as_Player_TakeHitB_1_001C8070(s32, u16, s32, s32);
void Player_RollStatusEffect_1_001C8570__as_Player_TakeHitB_1_001C8070(u32 *);
void Player_PlayHurtSe_0_001CA2B0(s32);
void Player_ApplyDamage_2_001C8320__as_Player_TakeHit_1_001C7DC0_(s32, s32, s32, s32);
u16 Rand_Next_3_0015ED20(u32);
s32 Player_GetStat_2_001CD450__as_Player_AddStatus_1_001C88E0(s32, s32, s32, s32);
void Player_RollStatusEffect_1_001C8570__as_Player_TakeHit_1_001C7DC0__(void *);
void Player_ApplyDamage_2_001C8320__as_Player_UpdateArmBones_0_001C5DE0____(s32, s32, s32, s32);
s32 Player_GetStat_2_001CD450__as_Player_DrawWeapon_0_001BCFF0___();
s8* Mdl_GetFrameData_0_001715B0__as_Player_DrawWeapon_0_001BCFF0___(H_Player_DrawWeapon_0_001BCFF0 *);
void Player_StartAttackMotion_1_001C6590__as_Player_DrawWeapon_0_001BCFF0___(s32);
void Player_CalcAttack_1_001CEBF0__as_Player_DrawWeapon_0_001BCFF0___(X_Player_HandleAttackInput_0_001C1A00 *, u8 *, s8);
void Player_StartMagicMotion_0_001C69A0__as_Player_DrawWeapon_0_001BCFF0___(s32);
void Player_UpdateMagicState_0_001C6250__as_Player_DrawWeapon_0_001BCFF0___(Actor *);
void Player_UpdateAttackState_0_001C5FB0__as_Player_DrawWeapon_0_001BCFF0___(Actor *);
void Player_UpdateSwitchState_0_001C6470__as_Player_DrawWeapon_0_001BCFF0___(Actor *);
void sceVu0MulMatrix__as_Player_UpdateArmBones_0_001C5DE0_____(void *, void *, void *);
s8* Mdl_GetFrameData_0_001715B0__as_Player_UpdateArmBones_0_001C5DE0_____(s8 **);
s32 Item_GetType_0_001CCDE0__as_Player_UpdateArmBones_0_001C5DE0_____(s32);
f32 Mdl_GetMotionLength_0_00173F70__as_Player_UpdateArmBones_0_001C5DE0_____(H_Player_UpdateArmBones_0_001C5DE0 *, u16);
void Player_CalcAttack_1_001CEBF0__as_Player_UpdateArmBones_0_001C5DE0_____(X_Player_UpdateArmBones_0_001C5DE0__ *, u8 *, s8);
void Seg_Init_1_001502A0__as_Player_UpdateArmBones_0_001C5DE0_____(f32, M *, f32 *, f32 *);
f32 atan2f(f32, f32);
void sceVu0RotMatrixZ(MtxF *, MtxF *, f32);
void sceVu0CameraMatrix(void *, Vec *, Vec *, Vec *);
void sceVu0CopyVector__as_Camera_LookAt_0_001C89E0(Vec *, s8 *);
void sceVu0SubVector__as_Camera_LookAt_0_001C89E0(Vec *, Vec *, Vec *);
void sceVu0CopyVector__as_Camera_SetPosition_0_001C8EA0(f32 *v0, f32 *v1);
void sceVu0SubVector__as_Camera_Update_1_001C8F90(Vec *, s8 *, Vec *);
void sceVu0CopyVector__as_Player_SetPosition_0_001C9320(u8 *, s32);
void sceVu0CopyVector__as_Player_GetHeadPos_0_001C93A0(f32 *v0, f32 *v1);
void sceVu0CopyVector__as_Player_GetPos_1_001C9410(f32 *v0, f32 *v1);
void sceVu0CopyVector__as_Player_GetPosB_0_001C9490(f32 *v0, f32 *v1);
void sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0(void *, void *);
void sceVu0CopyVector__as_Player_SetStartPos_0_001C9630(f32 *v0, f32 *v1);
void sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0(Vec *, Vec *);
void memcpy(s32, s32, s32);
M2C_UNK Pool_Free_2_00128580(s32, s32);
s8** ActorList_FromHandle_1_001A5970(s8 *);
void Enemy_UpdateModelMatrix_0_001A7E60(void);
void Arc_LoadFile_2_00159DD0(s32, s32, void *, s32 *);
s32 Tex_HashName_2_00177F80(void *);
s32 Tex_Find_1_00177AF0(s32, s32);
void memset__as_Player_LoadModel_1_001C9CD0(void *, s32, s32);
s32 Player_RefreshEquipModel_0_001CEA50__as_Player_Warp_0_001C92C0_();
void sceVu0CopyVector__as_Player_Exists_3_001C9BF0(f32 *v0, f32 *v1);
void memset__as_PlayerData_InitNew_0_001C9EA0(u8 *, s32, s32);

/* Player_DrawWeapon_0_001BCFF0____ */
#define sceVu0SubVector sceVu0SubVector__as_Player_DrawWeapon_0_001BCFF0____
void sceVu0SubVector__as_Player_DrawWeapon_0_001BCFF0____(Vec*, Vec*, void *);
#define Camera_LookAt_0_001C89E0 Camera_LookAt_0_001C89E0__as_Player_DrawWeapon_0_001BCFF0____
void Camera_LookAt_0_001C89E0__as_Player_DrawWeapon_0_001BCFF0____(u8 *, f32);

/* Player_DrawWeapon_0_001BCFF0___ */

/* Player_DrawWeapon_0_001BCFF0__ */

/* Player_DrawWeapon_0_001BCFF0_ */

/* Player_DrawWeapon_0_001BCFF0_ */
/* Player_DrawWeapon_0_001BCFF0 */

/* Player_DrawWeapon_0_001BCFF0 */
void Player_DrawWeapon_0_001BCFF0(O *o) {
    u32 sv;
    H_Player_DrawWeapon_0_001BCFF0 *h;
    s32 x;
    s8 *s1;
    s32 i;
    E_Player_DrawWeapon_0_001BCFF0_ *e;
    P_Player_DrawWeapon_0_001BCFF0 *p;
    u8 k;
    u8 v;
    Col_Player_DrawWeapon_0_001BCFF0 c;
    Col_Player_DrawWeapon_0_001BCFF0 c2;
    M_Player_DrawWeapon_0_001BCFF0 m;

    sv = D_00222A50[0].f.b3;
    if (o == NULL) return;
    if (!o->f5A0.f.b0 || !o->f5A0.f.b2) return;
    h = *(H_Player_DrawWeapon_0_001BCFF0 **)(o->x518 + 0xB0);
    x = *h->h->pp;
    s1 = Mdl_GetFrameData_0_001715B0__as_Player_DrawWeapon_0_001BCFF0___(h);
    o->f5A1.f.b6 = 1;
    if (!h->h->f.f.b1) return;
    D_00222A50[0].f.b3 = 1;
    *(Big *)(s1 + 0x10) = gPlayerBss_004B4C40;
    c = o->x4B0->c;
    D_00222A50[0].f.b4 = 1;
    Mdl_SetLayerTex_0_0016B2D0(h, c, 5, 0);
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x40, gGsPacketBss_002F1420[0]);
    GsPkt_SetReg_3_001543E0(0x41, gGsPacketBss_002F1420[0]);
    GsPkt_Flush_1_001544C0();
    Mdl_DrawLitWrap_0_0016B960(s1, 0, x, s1 + 0x280, 0, 2);
    Fog_ApplyDefault_0_0015B270();
    for (i = 0; i < o->n; i++) {
        v = o->a[i];
        p = o->tbl[v];
        if ((u32)i <= 1 || i == 15 || i == 29) continue;
        if (v == 0xFF) {
            c2 = o->x4B0->c;
        } else {
            c2 = p->c;
        }
        if (!c2.f.f.b3) {
            Mdl_DrawMeshesC_1_0016D380(*h->h->pp, h->h, s1, i, c2, 0);
        }
        k = o->b[i];
        p = o->tbl[k];
        e = &o->x51C[k];
        if (k == 0xFF) continue;
        if (e->h == 0) continue;
        if (e->f.f.b2) continue;
        Seg_Init_1_001502A0__as_Player_DrawWeapon_0_001BCFF0_(&m, p, &p->r, p->p.w);
        Sfx_SetColor_0_00167670(e->h, &m);
        Sfx_SetTransform_1_001677C0(e->h, (s1 + (i + 1) * 0x140) + 0xC0);
    }
    D_00222A50[0].f.b4 = 0;
    GsPkt_CloseChain_1_001549D0();
    D_00222A50[0].f.b3 = sv;
    Mdl_FlushLayer_0_0016B280();
}

/* Player_GetEquipSlot_0_001BD350 */
inline s8 *get_Player_DrawWeapon_0_001BCFF0__(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

s32 Player_GetEquipSlot_0_001BD350(s32 a) {
    s8 *p;
    s8 *q;
    s32 v;

    p = get_Player_DrawWeapon_0_001BCFF0__();
    if (p == NULL) {
        return 1;
    }
    q = *(s8 **)(p + 0x3C8);
    if (q == NULL) {
        return 1;
    }
    if (!((Flags8 *)(q + 0xA8))->f.b0 || !((Flags8 *)(q + 0xA8))->f.b7) {
        return 1;
    }
    v = (s16)Equip_GetSlotItem_1_001CCD90(4);
    if ((v >= 300 && v <= 311) || (v >= 340 && v < 344)) {
        if ((a >= 4 && a <= 14) || (a >= 18 && a < 29)) {
            return 0;
        }
    }
    if (v == 0x14B || v == 0x14C) {
        if (a == 3 || a == 17) {
            return 0;
        }
    }
    if (v == 0x152 || v == 0x153) {
        if (a != 4 && a != 18) {
            return 0;
        }
    }
    return 1;
}

/* Player_UpdateArea_0_001BD4E0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define E80 (&gMapSbss_00201E80)
static inline f32 wrap(f32 x) { f32 t = 3.1415927f + x; return ((t - 6.2831855f * (s32)(0.15915494f * t)) + (t < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f; }
static inline f32 u2f_Player_DrawWeapon_0_001BCFF0(u32 x) { return x; }
static inline f32 rad(u32 d) { f32 f = d; return 3.1415927f * f / 180.0f; }

void Player_UpdateArea_0_001BD4E0(Actor *a) {
    P_Player_UpdateArea_0_001BD4E0 *p;
    N *n;
    S1 *s1;
    M_Player_UpdateArea_0_001BD4E0 *m;
    M_Player_UpdateArea_0_001BD4E0 *mm;
    u8 *e;
    f32 *k;
    f32 f;
    Col_Player_UpdateArea_0_001BD4E0 col;
    MtxF mt;
    Vec v;

    p = (P_Player_UpdateArea_0_001BD4E0 *)(a->unk518 + 0x180);
    n = 0;
    if (*(s32 *)(a->unk518 + 0x274) == 0) return;
    s1 = p->xFC;
    gPlayerSbss_002022BC = 0;
    if (E80[2] != 0) {
        n = MapObj_FindCollider_0_001B1D00(*E80[2], p->xD0);
        if (n != 0) gPlayerSbss_002022BC = E80[2];
    }
    if (E80[3] != 0 && n == 0) {
        n = MapObj_FindCollider_0_001B1D00(*E80[3], p->xD0);
        if (n != 0) gPlayerSbss_002022BC = E80[3];
    }
    if (n != 0) {
        M_Player_UpdateArea_0_001BD4E0 **h;
        e = 0;
        h = gPlayerSbss_002022BC;
        if (n->x1E != -1) e = &(*h)->x158->x36[n->x1E * 8];
        if (e != 0) Map_LoadArea_1_001B51F0(*h, e, n->b3);
    } else if (p->x10->xC8 != 0) {
        mm = p->x10->xC0;
        e = 0;
        gPlayerSbss_002022BC = Map_FindLoaded_0_001B0AE0(mm);
        if (p->x10->xC8->x26 != -1) e = &mm->x158->x36[p->x10->xC8->x26 * 8];
        if (e != 0) Map_LoadArea_1_001B51F0(mm, e, 0);
    }
    if (gPlayerSbss_002022BC != 0 && (m = *gPlayerSbss_002022BC) != 0) {
        if (gSoundSbss_002022B8 != m->x0) {
            if (E80[2] != 0 && *E80[2] != 0 && E80[2] != gPlayerSbss_002022BC) MapObj_SendEvent_1_001B0A80(*E80[2], 0);
            if (E80[3] != 0 && *E80[3] != 0 && E80[3] != gPlayerSbss_002022BC) MapObj_SendEvent_1_001B0A80(*E80[3], 0);
            MapObj_SendEvent_1_001B0A80(m, 1);
            MapState_SetVisited_0_001AA4C0(m->x0);
            gPlayerSbss_002022DC = 0.0f;
        }
        gSoundSbss_002022B8 = m->x0;
        if (gPlayerSbss_002022DC >= 60.0f) f = 1.0f; else f = 1.0f / (60.0f - gPlayerSbss_002022DC);
        col.w = gGsPacketSdata_00201C5C;
        col.c.r = Lerpf_3_0015DF90(u2f_Player_DrawWeapon_0_001BCFF0(col.c.r), u2f_Player_DrawWeapon_0_001BCFF0(m->x158->xB6), f);
        col.c.g = Lerpf_3_0015DF90(u2f_Player_DrawWeapon_0_001BCFF0(col.c.g), u2f_Player_DrawWeapon_0_001BCFF0(m->x158->xB7), f);
        col.c.b = Lerpf_3_0015DF90(u2f_Player_DrawWeapon_0_001BCFF0(col.c.b), u2f_Player_DrawWeapon_0_001BCFF0(m->x158->xB8), f);
        col.c.a = Lerpf_3_0015DF90(u2f_Player_DrawWeapon_0_001BCFF0(col.c.a), u2f_Player_DrawWeapon_0_001BCFF0(m->x158->xB9), f);
        gGsPacketSdata_00201C5C = col.w;
        k = Map_GetFogEntry_0_001B40F0(m, 0);
        gPlayerData_001F2080[0] = Lerpf_3_0015DF90(gPlayerData_001F2080[0], k[0], f);
        gPlayerData_001F2084[0] = Lerpf_3_0015DF90(gPlayerData_001F2084[0], k[1], f);
        gPlayerData_001F208C[0] = Lerpf_3_0015DF90(gPlayerData_001F208C[0], k[3], f);
        gPlayerData_001F2090[0] = Lerpf_3_0015DF90(gPlayerData_001F2090[0], k[8], f);
        gPlayerData_001F2094[0] = Lerpf_3_0015DF90(gPlayerData_001F2094[0], k[9], f);
        gPlayerData_001F209C[0] = Lerpf_3_0015DF90(gPlayerData_001F209C[0], k[11], f);
        gPlayerData_001F20C0[0] = Lerpf_3_0015DF90(gPlayerData_001F20C0[0], k[4], f);
        gPlayerData_001F20C4[0] = Lerpf_3_0015DF90(gPlayerData_001F20C4[0], k[5], f);
        gPlayerData_001F20C8[0] = Lerpf_3_0015DF90(gPlayerData_001F20C8[0], k[6], f);
        gPlayerData_001F20D0[0] = Lerpf_3_0015DF90(gPlayerData_001F20D0[0], k[4], f);
        gPlayerData_001F20D4[0] = Lerpf_3_0015DF90(gPlayerData_001F20D4[0], k[5], f);
        gPlayerData_001F20D8[0] = Lerpf_3_0015DF90(gPlayerData_001F20D8[0], k[6], f);
        sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerData_001F2070, k + 0x14, gPlayerData_001F2070, f);
        sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gMatrixFromData_001F2100, k + 0x10, gMatrixFromData_001F2100, f);
        gMatrixFromData_001F210C[0] = 127.9f;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 1.0f;
        v.w = 1.0f;
        sceVu0RotMatrixX__as_Player_DrawWeapon_0_001BCFF0_(&mt, &gMatrixFromData_001F2170, WRAP(-(3.1415927f * (f32)(u32)m->x158->xBE / 180.0f)));
        sceVu0RotMatrixY__as_Player_UpdateArea_0_001BD4E0(&mt, &mt, WRAP(3.1415927f * (f32)(u32)m->x158->xC0 / 180.0f));
        sceVu0ApplyMatrix__as_Player_DrawWeapon_0_001BCFF0(&v, &mt, &v);
        sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4CE0, &v, gPlayerBss_004B4CE0, f);
        gPlayerBss_004B4CEC[0] = 1.0f;
        gPlayerSdata_00201E24 = Lerpf_3_0015DF90(u2f_Player_DrawWeapon_0_001BCFF0(gPlayerSdata_00201E24), u2f_Player_DrawWeapon_0_001BCFF0(m->x158->xC2), f);
        gPlayerSbss_002022DC += 1.0f;
        if (n != 0) {
            if (n->x22 != -1) e = m->x188 + n->x22 * 0xA0;
            else if (n->x21 != -1) e = m->x188 + n->x21 * 0xA0;
            else e = gGlowInitBss_0030D0E0;
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4C40__as_Player_UpdateArea_0_001BD4E0, e, gPlayerBss_004B4C40__as_Player_UpdateArea_0_001BD4E0, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4C50, e + 0x10, gPlayerBss_004B4C50, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4C60, e + 0x20, gPlayerBss_004B4C60, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4C70, e + 0x30, gPlayerBss_004B4C70, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4C80, e + 0x40, gPlayerBss_004B4C80, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4C90, e + 0x50, gPlayerBss_004B4C90, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4CA0, e + 0x60, gPlayerBss_004B4CA0, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4CB0, e + 0x70, gPlayerBss_004B4CB0, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4CC0, e + 0x80, gPlayerBss_004B4CC0, 0.2f);
            sceVu0InterVector__as_Player_DrawWeapon_0_001BCFF0_(gPlayerBss_004B4CD0, e + 0x90, gPlayerBss_004B4CD0, 0.2f);
            gPlayerBss_004B4CDC[0] = 127.9f;
        }
    }
    if (s1->m == 2) p->x3BF = s1->lo;
}
#undef E80

/* Player_CheckLadder_0_001BE050 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline void hit(P_Player_CheckLadder_0_001BE050 *p, MtxF *r, MtxF *mp) {
    s8 *o;
    if (!p->f3A0.c.b7 && p->f3A0.h.lvl > 10) {
        o = Sfx_Spawn_2_00169B50(0x1DD, 0, 0, 0);
        if (o != 0) {
            sceVu0RotMatrixY__as_Player_CheckLadder_0_001BE050(mp, &gMatrixFromData_001F2170, WRAP(*(f32 *)(p->o + 0x24)));
            sceVu0CopyVector__as_Player_CheckLadder_0_001BE050((Vec *)mp->m[3], (Vec *)r);
            Sfx_SetTransform_1_001677C0__as_Player_CheckLadder_0_001BE050(o, mp);
            Player_PlayStepSe_1_001CA2D0(0x10);
        }
    }
}

s32 Player_CheckLadder_0_001BE050(Actor *a) {
    P_Player_CheckLadder_0_001BE050 *p;
    s32 i;
    s32 j;
    s8 *n;
    s8 ***q;
    s8 ***q2;
    s32 i2;
    Vec f;
    Vec e;
    MtxF m;
    MtxF t;
    p = (P_Player_CheckLadder_0_001BE050 *)(a->unk518 + 0x180);
    sceVu0CopyVector__as_Player_CheckLadder_0_001BE050(&e, &p->pos);
    e.w = 1.0f;
    sceVu0CopyVector__as_Player_CheckLadder_0_001BE050(&f, &p->pos);
    f.w = 1.0f;
    e.y = -29000.0f;
    memset(&m, 0, 0x40);
    for (i = 0, q = (s8 ***)(&gMapSbss_00201E80__as_Player_CheckLadder_0_001BE050 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && MapColl_CapsuleCastAll_1_001B3240__as_Player_DrawWeapon_0_001BCFF0_(**q, &m, &e, 0x80, 1)) {
            hit(p, &m, &t);
            return 1;
        }
    }
    for (i2 = 0, q2 = (s8 ***)(&gMapSbss_00201E80__as_Player_CheckLadder_0_001BE050 + 2); i2 < 2; i2++, q2++) {
        if (*q2 != 0 && (n = **q2) != 0) {
            for (j = 0; j < *(u16 *)(n + 0x6E); j++) {
                if (!MapColl_CapsuleCast_1_001B2800__as_Player_CheckLadder_0_001BE050(n, &m, &e, j, 0x80, 1) == 0) {
                    hit(p, &m, &t);
                    return 1;
                }
            }
        }
    }
    return 0;
}

/* Player_CheckCeiling_0_001BE390 */

s32 Player_CheckCeiling_0_001BE390(s8 *a0) {
    Ray_Player_DrawWeapon_0_001BCFF0 ray;
    Res_Player_DrawWeapon_0_001BCFF0_ res;
    s32 j;
    s8 *o;
    s32 i;
    s8 ***pp;
    s32 **q;
    s8 *p;

    p = *(s8 **)(a0 + 0x518) + 0x180;
    sceVu0CopyVector__as_Player_CheckCeiling_0_001BE390(ray.a, p + 0x40);
    ray.a[3] = 1.0f;
    sceVu0CopyVector__as_Player_CheckCeiling_0_001BE390(ray.b, p + 0x40);
    ray.b[3] = 1.0f;
    ray.a[1] = *(f32 *)(*(s8 **)(p + 0x10) + 0x14);
    ray.b[1] += 220.0f;
    memset(&res, 0, 0x40);
    for (i = 0, q = (s32 **)(&gMapSbss_00201E80__as_Player_CheckCeiling_0_001BE390 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && MapColl_CapsuleCastAll_1_001B3240__as_Player_CheckCeiling_0_001BE390(**q, &res, &ray, 8, 1) != 0) {
            return 1;
        }
    }
    for (i = 0, pp = (s8 ***)(&gMapSbss_00201E80__as_Player_CheckCeiling_0_001BE390 + 2); i < 2; i++, pp++) {
        if (*pp != 0) {
            o = **pp;
            if (o != 0) {
                for (j = 0; j < *(u16 *)(o + 0x6E); j++) {
                    if (!MapColl_CapsuleCast_1_001B2800__as_Player_CheckCeiling_0_001BE390(o, &res, &ray, j, 8, 1) == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

/* Player_SpawnStepSfx_0_001BE510 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline s8 *cur_Player_DrawWeapon_0_001BCFF0(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

void Player_SpawnStepSfx_0_001BE510(Actor *a0) {
    s8 *s1;
    s32 s0;
    f32 m[16];
    s8 *c;
    f32 t, h, n;

    s1 = a0->unk518 + 0x180;
    if (((BF_Player_DrawWeapon_0_001BCFF0_ *)(a0->unk518 + 0x520))->v > 8) {
        s0 = 0;
        switch (*(u8 *)(s1 + 0x3BF)) {
        case 0: case 2: case 3: case 4: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 15: break;
        case 1: s0 = Sfx_Spawn_2_00169B50__as_Player_SpawnStepSfx_0_001BE510(0x1DB, 0, 0, 0); break;
        case 5: s0 = Sfx_Spawn_2_00169B50__as_Player_SpawnStepSfx_0_001BE510(0x1DE, 0, 0, 0); break;
        case 6: s0 = Sfx_Spawn_2_00169B50__as_Player_SpawnStepSfx_0_001BE510(0x1DD, 0, 0, 0); break;
        case 14: s0 = Sfx_Spawn_2_00169B50__as_Player_SpawnStepSfx_0_001BE510(0x1DD, 0, 0, 0); break;
        }
        if (s0 != 0) {
            sceVu0RotMatrixY__as_Player_SpawnStepSfx_0_001BE510(m, gMatrixFromData_001F2170__as_Player_SpawnStepSfx_0_001BE510, WRAP(*(f32 *)(*(s8 **)(s1 + 0x18) + 0x24)));
            c = cur_Player_DrawWeapon_0_001BCFF0();
            if (c != 0) {
                sceVu0CopyVector__as_Player_SpawnStepSfx_0_001BE510(m + 12, c + 0x40);
            }
            m[13] += 220.0f;
            Sfx_SetTransform_1_001677C0__as_Player_SpawnStepSfx_0_001BE510(s0, m);
        }
        Player_PlayStepSe_1_001CA2D0__as_Player_SpawnStepSfx_0_001BE510(*(u8 *)(s1 + 0x3BF));
    }
    if (((BF_Player_DrawWeapon_0_001BCFF0_ *)(s1 + 0x3A0))->v >= 20) {
        t = 30.0f * *(f32 *)(s1 + 0x54);
        h = t / 1000.0f;
        n = h / 2.0f - 9.0f;
        if (n == 0.0f) n = 1.0f;
        s0 = (s32)((h * h) / (1800.0f / n));
        if (s0 > 0) {
            Player_ApplyDamage_2_001C8320(s0, 1, 1, 1);
            *(s32 *)(*(s8 **)(s1 + 0x390) + 0x48) = 60;
        }
    }
}
#undef E80

/* PlayerProc_UpdateMove_0_001BE7B0 */
static inline void tail(Actor *a0, P_Player_DrawWeapon_0_001BCFF0_ *s1, Vec *v) {
    Mtx m;
    Vec d;
    Vec r;
    if (s1->x10->xC8 != 0) {
        Enemy_GetAttachMatrix_0_001A5AA0(a0, s1, &m);
        sceVu0SubVector__as_Player_DrawWeapon_0_001BCFF0__(&d, v, &s1->x10->x100);
        d.w = 1.0f;
        sceVu0ApplyMatrix__as_PlayerProc_UpdateMove_0_001BE7B0(&r, &m, &d);
        sceVu0AddVector__as_Player_DrawWeapon_0_001BCFF0_(v, &s1->x10->x100, &r);
        Player_GetForwardVector_2_001456B0(&d);
        d.w = 0.0f;
        sceVu0ApplyMatrix__as_PlayerProc_UpdateMove_0_001BE7B0(&r, &m, &d);
        *(f32 *)(a0->unk518 + 0x24) = Vec_YawAngle_2_0013FC10(&r);
    }
    v->y -= 220.0f;
    s1->x40.x = v->x;
    s1->x40.z = v->z;
    if (!(fabsf(s1->x40.y - v->y) <= 100.0f)) {
        s1->x40.y = v->y;
    } else {
        s1->x40.y = Lerpf_3_0015DF90(s1->x40.y, v->y, 0.5f);
    }
    Player_UpdateArea_0_001BD4E0(a0);
    s1->x3A4 *= 0.8f;
    if (!(s1->x3A4 <= -0.002f)) s1->x3A4 = 0.0f;
    Player_SpawnStepSfx_0_001BE510(a0);
    s1->x50.y = 0.0f;
    s1->f3A2.f.b0 = 1;
    s1->f3A0.v = 0;
}
static inline void push(P_Player_DrawWeapon_0_001BCFF0_ *s1) {
    Vec w;
    if (!s1->f39E.b) {
        sceVu0SubVector__as_Player_DrawWeapon_0_001BCFF0__(&w, &gPlayerBss_004B4CF0, s1->x18);
        w.w = 0.0f;
        sceVu0Normalize__as_Player_DrawWeapon_0_001BCFF0_(&w, &w);
        sceVu0ScaleVector__as_Player_DrawWeapon_0_001BCFF0_(&w, &w, 200.0f);
        sceVu0AddVector__as_Player_DrawWeapon_0_001BCFF0_(&s1->x50, &s1->x50, &w);
        s1->x50.y -= 196.0f;
        if (s1->x154 != 0 && (s1->x15C->xD & 7) == 1 && ((s1->x15C->xC & 0xF) == 12 || (s1->x15C->xC & 0xF) == 13)) {
            s1->f39E.v += 3;
        }
    }
}

void PlayerProc_UpdateMove_0_001BE7B0(Actor *a0) {
    P_Player_DrawWeapon_0_001BCFF0_ *s1;
    u16 n;
    s8 *t;
    Vec v;

    t = a0->unk518;
    ((Flags8 *)(t + 0x522))->f.b0 = 0;
    s1 = (P_Player_DrawWeapon_0_001BCFF0_ *)(t + 0x180);
    if (s1->x154 != 0 && s1->xF4 != 0) {
        sceVu0ScaleVector__as_Player_DrawWeapon_0_001BCFF0_(&v, &s1->x140, 100.0f);
        sceVu0AddVector__as_Player_DrawWeapon_0_001BCFF0_(&v, &v, &s1->x130);
        v.y = s1->xD0.y;
        tail(a0, s1, &v);
    } else if (s1->xF4 != 0) {
        sceVu0CopyVector__as_PlayerProc_UpdateMove_0_001BE7B0(&v, &s1->xD0);
        tail(a0, s1, &v);
    } else if (s1->x154 != 0) {
        sceVu0ScaleVector__as_Player_DrawWeapon_0_001BCFF0_(&s1->x40, &s1->x140, 100.0f);
        sceVu0AddVector__as_Player_DrawWeapon_0_001BCFF0_(&s1->x40, &s1->x40, &s1->x130);
        s1->x40.y -= 120.0f;
    }
    if ((n = s1->f39E.v) != 0) {
        if (n < 15) {
            push(s1);
        } else if (!s1->f39E.b) {
            if (s1->xF4 != 0) {
                s1->f39E.v = 0;
            } else if (s1->x154 != 0) {
                if ((s1->x15C->xD & 7) == 1 && (s1->x15C->xC & 0xF) != 12 && (s1->x15C->xC & 0xF) != 13) {
                    s1->f39E.c++;
                }
            } else {
                s1->f39E.c++;
            }
            if (s1->f39E.c > 5) s1->f39E.v = 0;
        }
    }
    if (Player_CheckLadder_0_001BE050(a0)) {
        ScreenFx_EnableWeather_0_00159500(1);
        s1->f3A0.b15 = 1;
        if (s1->x3AC == 0) {
            Sfx_Spawn_2_00169B50__as_PlayerProc_UpdateMove_0_001BE7B0(0x1F0, 0, 1, 0);
            s1->x3AC = rand() % 30 + 30;
        } else {
            s1->x3AC--;
        }
    } else {
        ScreenFx_EnableWeather_0_00159500(0);
        s1->f3A0.b15 = 0;
    }
    if (!(s1->x40.x <= 29000.0f)) s1->x40.x = 29000.0f;
    if (s1->x40.x < -29000.0f) s1->x40.x = -29000.0f;
    if (!(s1->x40.y <= 18000.0f)) s1->x40.y = 18000.0f;
    if (s1->x40.y < -29000.0f) s1->x40.y = -29000.0f;
    if (!(s1->x40.z <= 29000.0f)) s1->x40.z = 29000.0f;
    if (s1->x40.z < -29000.0f) s1->x40.z = -29000.0f;
    if (!(s1->x40.y < 18000.0f) || Player_CheckCeiling_0_001BE390__as_PlayerProc_UpdateMove_0_001BE7B0(a0)) Player_AddExp_0_001CEAA0(-9999);
}
#undef E80

/* PlayerProc_Update_0_001BEFA0 */
#define Actor AH
static inline f32 u2f_PlayerProc_Update_0_001BEFA0(u32 x) { return x; }
static inline void reset_Player_DrawWeapon_0_001BCFF0_(void) {
    S_Player_DrawWeapon_0_001BCFF0 *p;
    s8 *base;
    if (gPlayerSbss_002022E4 == NULL) {
        p = NULL;
    } else if ((base = gPlayerSbss_002022E4->unk518) == NULL) {
        p = NULL;
    } else {
        p = (S_Player_DrawWeapon_0_001BCFF0 *)(base + 0x180);
    }
    if (p != NULL) {
        Player_SetArmMotion_1_001C7020(0, 0.0f, 0, 0.0f, 1.0f);
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        p->x3D5 = 0;
        p->x3D4 = 0;
        p->f3D6.f.b5 = 0;
    }
}
static inline S_Player_DrawWeapon_0_001BCFF0 *cur_PlayerProc_Update_0_001BEFA0(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (S_Player_DrawWeapon_0_001BCFF0 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}
static inline s32 mode(void) {
    S_Player_DrawWeapon_0_001BCFF0 *p = cur_PlayerProc_Update_0_001BEFA0();
    if (p == 0) return 0;
    return p->m;
}
static inline s32 flag1(void) {
    S_Player_DrawWeapon_0_001BCFF0 *p = cur_PlayerProc_Update_0_001BEFA0();
    if (p == 0) return 0;
    return p->f3D6.f.b1;
}

void PlayerProc_Update_0_001BEFA0(AH *a0, f32 dt) {
    S_Player_DrawWeapon_0_001BCFF0 *q;
    S_Player_DrawWeapon_0_001BCFF0 *s;
    s32 o394;
    s8 *t;
    s32 i;
    s32 o395;
    u8 buf[0x38];
    s32 v;

    s = (S_Player_DrawWeapon_0_001BCFF0 *)(a0->unk518 + 0x180);
    o394 = s->x394;
    o395 = s->x395;
    s->f3A1.f.b5 = 0;
    s->f3A2.f.b3 = 0;
    s->x3AD = 0;
    s->x3AE = 0;
    if (D_00222A53[0].f.b4 && s->f3A2.f.b4) {
        q = (S_Player_DrawWeapon_0_001BCFF0 *)(a0->unk518 + 0x180);
        sceVu0CopyVector__as_PlayerProc_Update_0_001BEFA0(&q->x50, &gZeroVec_003139A0);
        q->x50.y -= 3920.0f * dt;
        reset_Player_DrawWeapon_0_001BCFF0_();
        q->x18->x20 = Lerpf_3_0015DF90(q->x18->x20, 1.5707964f, (u2f_PlayerProc_Update_0_001BEFA0(q->x41E) / 90.0f) * (u2f_PlayerProc_Update_0_001BEFA0(q->x41E) / 90.0f));
        if (q->x41E > 0x2D) {
            Game_TryRequestEvent_0_0012C110(0x28);
        } else {
            q->x41E++;
        }
        return;
    }
    Player_UpdateHeldItem_0_001BFB70(a0);
    q = cur_PlayerProc_Update_0_001BEFA0();
    if (q != 0) {
        if (q->f444 <= 0.0f) {
            q->f430 = q->f434 = 0.0f;
        } else {
            q->f430 = q->f438 * sinf(q->f444);
            q->f434 = q->f43C * sinf(q->f444);
            q->f438 = q->f438 * q->f440;
            q->f43C = q->f43C * q->f440;
            q->f444 -= 1.0f;
        }
    }
    if (!Game_GetBusy_0_0012C020() && !mode()) {
        PlayerData_TickStatus_0_001CE2D0();
        Player_UpdateMp_1_001CDF80();
        PlayerData_ResetCounters_0_001CEBA0();
        Player_UpdateRegen_1_001CD6C0();
    }
    s->x420 = -1;
    s->x421 = -1;
    if (Player_GetLevelInfo_0_001CD980(&s->x420, &s->x421)) {
        s->x422++;
    } else {
        s->x422 = 0;
    }
    Player_UpdateStatusEffects_0_001C9FF0();
    Player_RecalcStats_1_001CEDC0(3);
    Player_RefreshEquipModel_0_001CEA50(0);
    memset(buf, 0, 0x38);
    if (!Game_GetBusy_0_0012C020()) {
        if (!D_00222A52[0].f.b2 || D_00222A11[0] != 0) {
            Player_MapControls_0_001C4760__as_Player_DrawWeapon_0_001BCFF0_(a0, buf);
        }
    }
    if (s->x3AF < 0x2D) {
        memset(buf, 0, 0x38);
        s->x3AF++;
    }
    if (s->f3A2.f.b1) {
        Camera_LookAt_0_001C89E0(s->x400, s->f37C);
    }
    if (!Game_GetBusy_0_0012C020() && !mode()) {
        if (s->o) {
            Player_UpdateSlide_0_001C3EF0__as_Player_DrawWeapon_0_001BCFF0_(a0, buf, dt);
        } else if (s->f3A0.f.b0) {
            Player_UpdateFall_0_001C39D0__as_Player_DrawWeapon_0_001BCFF0_(a0, buf, dt);
        } else if (!s->f3A2.f.b0) {
            Player_UpdateTurn_0_001C34F0__as_Player_DrawWeapon_0_001BCFF0_(a0, buf);
        } else {
            Player_UpdateWalk_1_001C2DB0__as_Player_DrawWeapon_0_001BCFF0_(a0, buf);
        }
        Player_ReadStick_0_001C27C0__as_Player_DrawWeapon_0_001BCFF0_(a0, buf);
        Player_UpdateInput_0_001C1900__as_Player_DrawWeapon_0_001BCFF0_(a0, buf);
    } else {
        sceVu0CopyVector__as_PlayerProc_Update_0_001BEFA0(&s->x50, &gZeroVec_003139A0);
        s->x50.y -= 3920.0f * dt;
    }
    if (s->x18->x20 < -1.0471976f) {
        s->x18->x20 = -1.0471976f;
    }
    if (!(s->x18->x20 <= 0.6108653f)) {
        s->x18->x20 = 0.6108653f;
    }
    if (s->m || s->n) {
        Player_UpdatePickup_0_001C0A10__as_Player_DrawWeapon_0_001BCFF0_(a0, buf);
    } else {
        Player_HandleAction_0_001C0E60__as_Player_DrawWeapon_0_001BCFF0_(a0, buf);
    }
    Player_UpdateEquipSounds_0_001BF940(a0);
    if (a0 != 0 && (((Flags8 *)a0)[0x5A0].b & 1) && ((Flags8 *)a0)[0x5A0].f.b2) {
        t = Mdl_GetFrameData_0_001715B0__as_PlayerProc_Update_0_001BEFA0(*(s32 *)(a0->unk518 + 0xB0));
        for (i = 0; i < a0->x78; i++) {
            ((Flags8 *)(t + (i + 1) * 0x140))[0x1F8].f.b3 = !Player_GetEquipSlot_0_001BD350(i);
        }
    }
    if (!Game_GetBusy_0_0012C020() && !mode()) {
        if (s->x3CF != 1) {
            Player_ApplyEquipVisualB_0_001CE4B0(s);
        }
        Player_ApplyEquipVisualA_0_001CE370(s);
        if (!(s->f374 <= 0.0f)) {
            s->f374 -= 1.0f;
        }
    }
    if (s->x3D4 && ItemType_IsMagic_0_001D1E00(s->b39C) && !flag1()) {
        s->f3D0 = s->f3D0 + 0.1f * (0.17453294f - s->f3D0);
    } else {
        s->f3D0 = s->f3D0 + 0.1f * -s->f3D0;
    }
    if (!Game_GetBusy_0_0012C020() && !mode()) {
        sceVu0AddVector__as_Player_DrawWeapon_0_001BCFF0_(&s->x50, &s->x50, &s->x3F0);
    }
    sceVu0CopyVector__as_PlayerProc_Update_0_001BEFA0(&s->x3F0, &gZeroVec_003139A0);
    if (s->x3BE) {
        s->x3BE--;
    }
    s->f3A1.f.b6 = 0;
    if (ItemType_IsWeapon_0_001D1D50(s->b39C)) {
        v = ItemType_IsMagic_0_001D1E00(s->b39C) ? 2 : 1;
    } else {
        v = 0;
    }
    s->f3A2.f.b5 = v;
    if (o394 != s->x394 || o395 != s->x395) {
        Hud_ClearTimers_0_0019A840();
    }
}
#undef Actor
#undef E80
#undef Actor

/* Player_UpdateEquipSounds_0_001BF940_ */

/* Player_UpdateEquipSounds_0_001BF940 */

/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
void Player_UpdateEquipSounds_0_001BF940(Actor *a0) {
    S_Player_UpdateEquipSounds_0_001BF940 *s = (S_Player_UpdateEquipSounds_0_001BF940 *)(a0->unk518 + 0x180);
    Obj3D *o;
    Obj3D *p;

    if (s->x390->f94.f.b0) {
        p = s->x3C0;
    } else {
        p = s->x3C4;
    }
    if (p != NULL) {
        p->xA8.f.b7 = 0;
        p->xA8.f.b2 = 1;
        p->xA9.f.b3 = 0;
    }
    if (s->x390->f94.f.b0) {
        o = s->x3C4;
    } else {
        o = s->x3C0;
    }
    if (o != NULL && o->xA8.f.b0) {
        if (s->x3D5 == 0) {
            o->xA8.f.b7 = 0;
        } else {
            o->xA8.f.b7 = 1;
        }
        o->xA8.f.b2 = 1;
        if (!o->xA9.f.b3 && !Snd_BindMapSe_0_0012DA90()) {
            o->xA9.f.b3 = 1;
        }
    }
    p = s->x3C8;
    if (p != NULL) {
        p->xA8.f.b7 = 1;
        p->xA8.f.b2 = 1;
        p->xA9.f.b0 = 1;
        p->xA9.f.b3 = 0;
    }
    s->x39C = Item_GetType_0_001CCDE0(Equip_GetSlotItem_1_001CCD90(s->x390->f94.f.b0));
    if (ItemType_IsWeapon_0_001D1D50(s->x39C)) {
        s->x396 = PlayerData_GetEquipEntry_0_001D1E10()[3];
    }
}

/* Player_UpdateHeldItem_0_001BFB70 */
static inline S_Player_UpdateHeldItem_0_001BFB70 *get_Player_UpdateEquipSounds_0_001BF940_(void) {
    S_Player_UpdateHeldItem_0_001BFB70 *r;
    s8 *base;
    if (gPlayerSbss_002022E4 == NULL) {
        r = NULL;
    } else if ((base = gPlayerSbss_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_UpdateHeldItem_0_001BFB70 *)(base + 0x180);
    }
    return r;
}
static inline void reset_Player_UpdateEquipSounds_0_001BF940(void) {
    S_Player_UpdateHeldItem_0_001BFB70 *p;
    s8 *base;
    if (gPlayerSbss_002022E4 == NULL) {
        p = NULL;
    } else if ((base = gPlayerSbss_002022E4->unk518) == NULL) {
        p = NULL;
    } else {
        p = (S_Player_UpdateHeldItem_0_001BFB70 *)(base + 0x180);
    }
    if (p != NULL) {
        Player_SetArmMotion_1_001C7020(0, 0.0f, 0, 0.0f, 1.0f);
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        p->x3D5 = 0;
        p->x3D4 = 0;
        p->f3D6.f.b5 = 0;
    }
}

s32 Player_UpdateHeldItem_0_001BFB70(Actor *a0) {
    S_Player_UpdateHeldItem_0_001BFB70 *s = (S_Player_UpdateHeldItem_0_001BFB70 *)(a0->unk518 + 0x180);
    s32 n;
    s16 m;

    n = s->x390->x80;
    if (n != s->x3B8 || s->x3C0 == NULL) {
        if (s->x3C0 != NULL) {
            if (!s->x390->f94.f.b0) Snd_StopStream3_0_0012DA80();
            ItemObj_Free_1_001AF4A0(s->x3C0);
            s->x3C0 = NULL;
        }
        if (n != -1) {
            s->x3C0 = ItemObj_Spawn_0_001AE7C0(n);
        } else {
            s->x3C0 = ItemObj_Spawn_0_001AE7C0(0x3FF);
        }
        s->x3B8 = n;
        if (!s->x390->f94.f.b0) reset_Player_UpdateEquipSounds_0_001BF940();
    }
    n = s->x390->x82;
    if (ItemType_GetCategory_0_001D1CB0(Item_GetType_0_001CCDE0__as_Player_UpdateHeldItem_0_001BFB70(s->x390->x80))) {
        if (s->x3C4 != NULL) {
            Snd_StopStream3_0_0012DA80();
            ItemObj_Free_1_001AF4A0(s->x3C4);
            s->x3C4 = NULL;
            if (s->x390->f94.f.b0) reset_Player_UpdateEquipSounds_0_001BF940();
        }
        s->x3BA = n;
        s->x390->f94.f.b0 = 0;
    } else {
        m = n;
        if (m != s->x3BA || s->x3C4 == NULL) {
            if (s->x3C4 != NULL) {
                if (s->x390->f94.f.b0) Snd_StopStream3_0_0012DA80();
                ItemObj_Free_1_001AF4A0(s->x3C4);
                s->x3C4 = NULL;
            }
            if (m != -1) {
                s->x3C4 = ItemObj_Spawn_0_001AE7C0(n);
            } else {
                s->x3C4 = ItemObj_Spawn_0_001AE7C0(0x3FF);
            }
            s->x3BA = n;
            if (s->x390->f94.f.b0) reset_Player_UpdateEquipSounds_0_001BF940();
        }
    }
    n = s->x390->x88;
    if (n != -1) {
        if (n != s->x3BC || s->x3C8 == NULL) {
            if (s->x3C8 != NULL) ItemObj_Free_1_001AF4A0(s->x3C8);
            s->x3C8 = ItemObj_Spawn_0_001AE7C0(n);
            reset_Player_UpdateEquipSounds_0_001BF940();
        }
        s->x3BC = n;
    } else {
        if (s->x3C8 != NULL) {
            ItemObj_Free_1_001AF4A0(s->x3C8);
            s->x3C8 = NULL;
        }
        s->x3BC = -1;
    }
    return 0;
}

/* Player_FireWeapon_0_001C0020 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 u2f(u32 x) { return x; }

void Player_FireWeapon_0_001C0020(Actor *a) {
    D d;
    Mtx m;
    P_Player_UpdateEquipSounds_0_001BF940 *p;
    E_Player_UpdateEquipSounds_0_001BF940 *tbl;
    s32 i;
    s32 j;
    u16 *c;

    p = (P_Player_UpdateEquipSounds_0_001BF940 *)(a->unk518 + 0x180);
    tbl = Item_GetTable_1_001AFC90();
    j = i = (s16)Equip_GetSlotItem_1_001CCD90(6);
    if (i != -1 && p->x397 > 0) {
    c = &((u16 (*)[0x48])&tbl->x42)[j][0];
    if (*c <= p->x390->x6 && p->x374 <= 0.0f) {
    p->x378 = Sfx_Spawn_2_00169B50(tbl[j].x40, 0, 0, 0);
    if (p->x378 != NULL) {
    Equip_DamageWeapon_0_001CC450(p->x46A);
    p->x390->x6 -= *c;
    p->x397--;
    p->x39A = 0;
    p->x374 = u2f(tbl[i].x56);
    sceVu0CopyMatrix__as_Player_DrawWeapon_0_001BCFF0__(&m, &gMatrixFromData_001F2170__as_Player_UpdateEquipSounds_0_001BF940_);
    sceVu0RotMatrixX__as_Player_UpdateEquipSounds_0_001BF940(&m, &m, WRAP(-WRAP(p->p18[8])));
    sceVu0RotMatrixY__as_Player_UpdateEquipSounds_0_001BF940(&m, &m, WRAP(WRAP(p->p18[9])));
    sceVu0CopyVector(&m.m[3], p->p18);
    m.m[3].w = 1.0f;
    Sfx_SetTransform_1_001677C0__as_Player_UpdateEquipSounds_0_001BF940_(p->x378, &m);
    Sfx_SetOwner_1_00167600(p->x378, a);
    memset(&d, 0, 0x40);
    d.h[0] = p->x470[0] / tbl[i].x57;
    d.h[1] = p->x470[1] / tbl[i].x57;
    d.h[2] = p->x470[2] / tbl[i].x57;
    d.h[3] = p->x470[3] / tbl[i].x57;
    d.h[4] = p->x470[4] / tbl[i].x57;
    d.h[5] = p->x470[5] / tbl[i].x57;
    d.w[0] = tbl[i].x44;
    d.w[1] = tbl[i].x45;
    d.w[2] = tbl[i].x46;
    d.w[3] = tbl[i].x48;
    d.w[4] = tbl[i].x47;
    d.w[5] = tbl[i].x49;
    d.f31.b1 = 1;
    Sfx_GetState_0_001672B0__as_Player_UpdateEquipSounds_0_001BF940(p->x378, &d);
    p->f3A2.b3 = 1;
    }
    }
    }
}

/* Player_TryPickup_0_001C0550 */
s32 Player_TryPickup_0_001C0550(A_Player_UpdateEquipSounds_0_001BF940_ *a0) {
    S_Player_UpdateEquipSounds_0_001BF940_ *s;
    R_Player_DrawWeapon_0_001BCFF0 *r;
    s = (S_Player_UpdateEquipSounds_0_001BF940_ *)(a0->x518 + 0x180);
    s->x414 = 0;
    r = ItemObj_FindPickTarget_0_001AC3E0();
    if (r) {
        if (Inventory_CanCarry_0_001CBE40(r->x9C)) {
            s->m = 1;
            s->n = 0;
            s->x414 = r;
        } else {
            Msg_ShowById_1_0018B0E0(0xCC);
        }
        return 1;
    }
    r = Chest_CheckOpen_0_001B9360();
    if (r) {
        s->m = 1;
        s->n = 0;
        s->x414 = r;
        return 1;
    }
    return 0;
}

/* Player_GetHandMatrix_1_001C0660 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void Player_GetHandMatrix_1_001C0660(f32 *out, s32 a1, s32 flag, u32 n) {
    f32 m2[4][4] __attribute__((aligned(16)));
    f32 m1[4][4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 ang;

    ang = -12.0f * (3.1415927f * n) / 180.0f;
    sceVu0InversMatrix(m1, D_00222850);
    sceVu0CopyVector__as_Player_GetHandMatrix_1_001C0660(w, gZeroVec_003139A0__as_Player_UpdateEquipSounds_0_001BF940_);
    w[2] = 180.0f;
    w[1] = 30.0f;
    sceVu0ApplyMatrix__as_Player_UpdateEquipSounds_0_001BF940_(w, m1, w);
    sceVu0AddVector__as_Player_UpdateEquipSounds_0_001BF940(m1[3], m1[3], w);
    sceVu0CopyMatrix__as_Player_GetHandMatrix_1_001C0660(m2, gMatrixFromData_001F2170__as_Player_GetHandMatrix_1_001C0660);
    ItemObj_GetScale_0_001ADBA0(a1, v);
    m2[0][0] = v[0];
    m2[1][1] = v[1];
    m2[2][2] = v[2];
    sceVu0RotMatrixY__as_Player_GetHandMatrix_1_001C0660(m2, m2, WRAP(ang));
    m1[3][3] = 1.0f;
    if (flag != 0) {
        m2[3][2] -= 150.0f;
        m2[3][0] += 70.0f;
        m2[3][1] += 150.0f;
    }
    sceVu0MulMatrix(out, m1, m2);
}

/* Player_BlendHandMatrix_0_001C0860 */

void Player_BlendHandMatrix_0_001C0860(f32 (*out)[4], s32 a1, u32 a2, s32 flag, f32 t) {
    f32 m[4][4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 q1[4] __attribute__((aligned(16)));
    f32 q2[4] __attribute__((aligned(16)));
    f32 s[4] __attribute__((aligned(16)));
    f32 q[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));

    if (flag == 0) {
        ItemObj_GetMatrix_0_001ADC60(a1, m);
        sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(c, m[3]);
        Mtx_ToQuat_2_0015E290(q1, m);
        Player_GetHandMatrix_1_001C0660__as_Player_BlendHandMatrix_0_001C0860(m, a1, 0, a2);
        sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(b, m[3]);
        Mtx_ToQuat_2_0015E290(q2, m);
        sceVu0InterVector__as_Player_UpdateEquipSounds_0_001BF940_(v, b, c, t);
        v[3] = 1.0f;
        ItemObj_GetScale_0_001ADBA0(a1, s);
        sceVu0CopyMatrix__as_Player_BlendHandMatrix_0_001C0860(m, gMatrixFromData_001F2170__as_Player_BlendHandMatrix_0_001C0860);
        m[0][0] = s[0];
        m[1][1] = s[1];
        m[2][2] = s[2];
        Quat_Slerp_2_0015DFA0(q, q1, q2, t);
        Quat_ToMatrix_2_0015E180(out, q);
        sceVu0MulMatrix__as_Player_BlendHandMatrix_0_001C0860(out, m, out);
        sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(out[3], v);
    } else {
        Player_GetHandMatrix_1_001C0660__as_Player_BlendHandMatrix_0_001C0860(m, a1, 0, a2);
        sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(c, m[3]);
        Player_GetHandMatrix_1_001C0660__as_Player_BlendHandMatrix_0_001C0860(m, a1, 1, a2);
        sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(b, m[3]);
        sceVu0InterVector__as_Player_UpdateEquipSounds_0_001BF940_(v, b, c, t);
        v[3] = 1.0f;
        sceVu0CopyMatrix__as_Player_BlendHandMatrix_0_001C0860(out, m);
        sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(out[3], v);
    }
}

/* Player_UpdatePickup_0_001C0A10_ */

/* Player_UpdatePickup_0_001C0A10 */

/* Player_UpdatePickup_0_001C0A10 */
void Player_UpdatePickup_0_001C0A10(Actor *a, P_Player_UpdatePickup_0_001C0A10 *p) {
    S_Player_UpdatePickup_0_001C0A10 *s = (S_Player_UpdatePickup_0_001C0A10 *)(a->unk518 + 0x180);
    Obj3D *o = s->x414;
    u8 n;
    f32 q;
    s32 *id;
    u16 k;
    Msg msg;

    if (o == NULL) return;
    if (o->xA8.f.b1) goto ret;
    if (o->xA8.f.b0) goto go;
ret:
    return;
go:
    n = s->f18;
    if (n != 0) {
        if (s->b13) {
            q = 1.0f - n / 15.0f;
            Player_BlendHandMatrix_0_001C0860__as_Player_UpdatePickup_0_001C0A10_(o, o, 0, 0, q * q);
        } else {
            q = n / 15.0f;
            Player_BlendHandMatrix_0_001C0860__as_Player_UpdatePickup_0_001C0A10_(o, o, gPlayerSbss_002022EC, 1, q * (2.0f - q));
        }
        s->f18 = s->f18 + 1;
        if (s->f18 < 15) return;
        if (o->x9E == 2 && o->xA9.f.b2) {
            if (!s->b13) {
                id = *(s32 **)o->x8C;
                MapState_SetField_0_001A9E10(*id, o->xAC, MapState_GetField_0_001A9D50(*id, o->xAC) | 2);
            }
            ItemObj_Free_1_001AF4A0(o);
        } else if (!s->b13) {
            if (o->x9E == 0 && (k = o->xAA) != 0 && gPlayerSbss_002022BC__as_Player_UpdateEquipSounds_0_001BF940_ != NULL && *gPlayerSbss_002022BC__as_Player_UpdateEquipSounds_0_001BF940_ != NULL) {
                memset(&msg, 0, 0x30);
                                msg.type = 5;
msg.a = k;
                msg.b = **gPlayerSbss_002022BC__as_Player_UpdateEquipSounds_0_001BF940_;
                Event_CheckTrigger_0_00179F80(&msg);
            }
            ItemObj_PickUp_0_001AF3F0(o);
        }
        s->f18 = 0;
        s->f14 = 0;
        s->x414 = NULL;
        return;
    }
    gPlayerSbss_002022EC++;
    if (s->f14 < 15) {
        s->f14 = s->f14 + 1;
        gPlayerSbss_002022EC = 0;
    }
    q = s->f14 / 15.0f;
    Player_BlendHandMatrix_0_001C0860__as_Player_UpdatePickup_0_001C0A10_(o, o, gPlayerSbss_002022EC, 0, q * (2.0f - q));
    if (p->x30 & 0x2000) {
        Inventory_Give_0_001CBCD0(o->x9C);
        s->b13 = 0;
        s->f18 = 1;
        s->f14 = 0;
    } else if (p->x30 & 0x4000) {
        s->b13 = 1;
        s->f18 = 1;
        s->f14 = 0;
    }
}

/* Player_HandleAction_0_001C0E60 */
static inline S_Player_HandleAction_0_001C0E60 *get_Player_HandleAction_0_001C0E60(void) {
    S_Player_HandleAction_0_001C0E60 *r;
    s8 *base;
    s32 v;
    if (gPlayerSbss_002022E4 == NULL) {
        r = NULL;
    } else if ((base = gPlayerSbss_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_HandleAction_0_001C0E60 *)(base + 0x180);
    }
    return r;
}
static inline s32 fa(void) {
    S_Player_HandleAction_0_001C0E60 *r;
    s8 *base;
    s32 v;
    if (gPlayerSbss_002022E4 == NULL) {
        r = NULL;
    } else if ((base = gPlayerSbss_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_HandleAction_0_001C0E60 *)(base + 0x180);
    }
    if (r == NULL) v = 0; else v = r->f3D6.f.b0;
    return v;
}
static inline s32 fb(void) {
    S_Player_HandleAction_0_001C0E60 *r;
    s8 *base;
    s32 v;
    if (gPlayerSbss_002022E4 == NULL) {
        r = NULL;
    } else if ((base = gPlayerSbss_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_HandleAction_0_001C0E60 *)(base + 0x180);
    }
    if (r == NULL) v = 0; else v = r->f3D6.f.b1;
    return v;
}

void Player_HandleAction_0_001C0E60(Actor *a, Ev *e) {
    s32 fl = e->x30;
    S_Player_HandleAction_0_001C0E60 *s = (S_Player_HandleAction_0_001C0E60 *)(a->unk518 + 0x180);
    S_Player_HandleAction_0_001C0E60 *p;
    if (fl & 1) {
        Game_TryRequestEvent_0_0012C110(0x13);
        return;
    }
    if (s->f39E && (fl & 0x4000)) {
        s->f39E = 0;
        return;
    }
    if (s->x3D5 == 8) return;
    if (!fa() && !fb()) {
        if ((fl & 0x4000) && gPlayerSbss_00201EB0 != 1) {
            Game_TryRequestEvent_0_0012C110(0x14);
            return;
        }
        if (fl & 0x1000) {
            if (!s->f3D6.f.b3) {
                if (ItemType_GetCategory_0_001D1CB0(s->x39C)) {
                    s->x390->f94.f.b0 = 0;
                    s->f3D6.f.b3 = 0;
                } else {
                    s->f3D6.f.b3 = 1;
                }
            }
            return;
        }
    }
    if (fl & 0x8000) {
        Player_FireWeapon_0_001C0020(a);
        return;
    }
    if (fl & 8) {
        Player_UseItem_1_001CAEF0(Equip_GetSlotItem_1_001CCD90(9));
        return;
    }
    if (s->f3A2.f.b0 && (fl & 0x2000)) {
        if (!Player_TryPickup_0_001C0550__as_Player_UpdatePickup_0_001C0A10_(a)) {
            Event_CheckTalk_0_00179F10();
            Door_UpdateLocked_0_001B90F0();
            p = get_Player_HandleAction_0_001C0E60();
            if (p && !p->f39E) {
                if (!Player_CheckLedge_0_001C13B0()) Player_CheckFrontWall_0_001C1140();
            }
        }
    }
}

/* Player_CheckFrontWall_0_001C1140 */
inline s8 *get_Player_UpdatePickup_0_001C0A10_(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

s32 Player_CheckFrontWall_0_001C1140(void) {
    Res_Player_UpdateEquipSounds_0_001BF940 res;
    Ray_Player_DrawWeapon_0_001BCFF0 ray;
    f32 a[4];
    f32 b[4];
    s32 i;
    P_Player_CheckFrontWall_0_001C1140 *p;
    s32 **q;
    s32 t;

    p = (P_Player_CheckFrontWall_0_001C1140 *)get_Player_UpdatePickup_0_001C0A10_();
    if (p->m3BF != 0xC && p->m3BF != 0xD) {
        return 0;
    }
    sceVu0CopyVector(a, p->m18 + 0x80);
    a[1] = 0.0f;
    sceVu0Normalize(a, a);
    sceVu0ScaleVector(a, a, -125.0f);
    sceVu0CopyVector(b, (s8 *)a);
    a[1] -= 10.0f;
    b[1] += 300.0f;
    sceVu0AddVector(a, a, p->m18 + 0x90);
    sceVu0AddVector(b, b, p->m18 + 0x90);
    Seg_Init_1_001502A0__as_Player_UpdateEquipSounds_0_001BF940_(&ray, a, b, 50.0f);
    for (i = 0, q = (s32 **)(&gMapSbss_00201E80__as_Player_UpdateEquipSounds_0_001BF940_ + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0) {
            memset(&res, 0, 0x40);
            MapColl_ClampIndex_0_001B2160(**q, &res, &ray, 2, -2);
            if (res.hit != 0) {
                t = res.tri[0xC] & 0xF;
                if (t == 0xC || t == 0xD) {
                    gPlayerBss_004B4D00[0] = *(f32 *)(res.tri + 0x10);
                    gPlayerBss_004B4D04[0] = *(f32 *)(res.tri + 0x14);
                    gPlayerBss_004B4D08[0] = *(f32 *)(res.tri + 0x18);
                    gPlayerBss_004B4D0C[0] = 1.0f;
                    sceVu0CopyVector((f32 *)gPlayerBss_004B4CF0__as_Player_UpdateEquipSounds_0_001BF940_, (s8 *)&res);
                    p->f6 = 1;
                    p->b12 = 1;
                    p->f13 = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}

/* Player_CheckLedge_0_001C13B0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline P_Player_CheckLedge_0_001C13B0 *cur_Player_CheckLedge_0_001C13B0(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (P_Player_CheckLedge_0_001C13B0 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

s32 Player_CheckLedge_0_001C13B0(void) {
    s8 ***q;
    P_Player_CheckLedge_0_001C13B0 *p;
    s32 i;
    Tri *t;
    Hit hit;
    Vec V[2];
    MtxF m;
    Vec d;

    p = cur_Player_CheckLedge_0_001C13B0();
    sceVu0RotMatrixX(&m, &gMatrixFromData_001F2170__as_Player_UpdatePickup_0_001C0A10_, WRAP(p->f3A4 + WRAP(p->o[3].x)));
    sceVu0RotMatrixY(&m, &m, WRAP(WRAP(3.1415927f + p->o[3].y)));
    sceVu0CopyVector(&V[1], (Vec *)m.m[2]);
    sceVu0ScaleVector(&V[1], &V[1], 650.0f);
    sceVu0AddVector(&V[1], &V[1], p->o);
    sceVu0CopyVector(&V[0], p->o);
    memset(&hit, 0, 0x40);
    for (i = 0, q = (s8 ***)(&gMapSbss_00201E80__as_Player_UpdateEquipSounds_0_001BF940_ + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0) {
            MapColl_CapsuleCastAll_1_001B3240__as_Player_UpdateEquipSounds_0_001BF940_(**q, &hit, &V[0], 2, 0);
        }
    }
    if (hit.x24 == 0) return 0;
    if (hit.x2C->t == 12 || hit.x2C->t == 13) {
        V[1].x = hit.x2C->x;
        V[1].y = hit.x2C->y;
        V[1].z = hit.x2C->z;
        V[1].w = 1.0f;
        sceVu0CopyVector(&V[0], &p->o[8]);
        V[0].y = 0.0f;
        sceVu0Normalize(&V[0], &V[0]);
        if (sceVu0InnerProduct(&V[1], &V[0]) > 0.8f) {
            if (hit.p.y < p->o->y + 234.99998f) {
                sceVu0SubVector__as_Player_DrawWeapon_0_001BCFF0__(&d, &hit.p, p->o);
                if (!(sqrtf(sceVu0InnerProduct(&d, &d)) <= 200.0f)) return 0;
                hit.p.y = p->o->y - 20.0f;
            }
            p->b = 1;
            p->c = 0;
            p->d = 0;
            sceVu0CopyVector(&gPlayerBss_004B4D00, &V[1]);
            sceVu0CopyVector(&gPlayerBss_004B4CF0__as_Player_UpdateEquipSounds_0_001BF940_, &hit.p);
            return 1;
        }
    }
    return 0;
}

/* Player_UpdateInput_0_001C1900 */

void Player_UpdateInput_0_001C1900(s8 *arg0, s8 *arg1) {
    s8 *t;
    SS_Player_UpdateInput_0_001C1900 *s;
    SV *v;

    t = M2C_FIELD(arg0, s8 **, 0x518);
    s = (SS_Player_UpdateInput_0_001C1900 *)(t + 0x180);
    if (M2C_FIELD(t, BFb *, 0x556).b3 == 0) {
        if (s->p390->b94 & 1) {
            v = s->p3C4;
        } else {
            v = s->p3C0;
        }
        if (v->a8.b1) goto ret; if (v->a8.b0) goto go; ret: return; go: {
            if (Snd_GetStreamFlag_0_0012C400(3) != 0) {
                if (ItemType_IsWeapon_0_001D1D50(s->b39C) != 0) {
                    if (ItemType_IsShield_0_001D1DA0(s->b39C) != 0) {
                        Player_HandleMagicInput_1_001C2190(arg0, arg1);
                    } else {
                        Player_HandleAttackInput_0_001C1A00(arg0, arg1);
                    }
                } else {
                    Player_HandleWeaponSwitch_1_001C23E0(arg0, arg1);
                }
            }
        }
    }
}

/* Player_HandleAttackInput_0_001C1A00 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline P_Player_HandleAttackInput_0_001C1A00 *cur_Player_HandleAttackInput_0_001C1A00(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (P_Player_HandleAttackInput_0_001C1A00 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

void Player_HandleAttackInput_0_001C1A00(Actor *a0, K *a1) {
    P_Player_HandleAttackInput_0_001C1A00 *s3;
    u32 m1;
    T *t;
    s16 r;
    u32 m2;
    s16 idx;
    s32 v;
    s32 k;
    s8 *o;
    P_Player_HandleAttackInput_0_001C1A00 *c;
    X_Player_HandleAttackInput_0_001C1A00 x;
    Mtx m;

    s3 = (P_Player_HandleAttackInput_0_001C1A00 *)(a0->unk518 + 0x180);
    if (Option_GetControlType_1_001A9450() < 2) m1 = 4; else m1 = 0x800;
    if (Option_GetControlType_1_001A9450() < 2) m2 = 4; else m2 = 0x800;
    if (s3->f3A1.f.b7) {
        if (s3->x3D5 == 3) Player_StartAttackMotion_1_001C6590__as_Player_DrawWeapon_0_001BCFF0___(6);
        return;
    }
    t = Item_GetData_1_001AFC40(Equip_GetSlotItem_1_001CCD90(s3->x390->x94 & 1));
    idx = t->x54;
    r = Inventory_HasItem_0_001CBC20(idx);
    if (s3->x3D5 == 0) {
        if (PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3 > 0 || r > 0) {
            if (a1->x30 & m1) {
                Player_StartAttackMotion_1_001C6590__as_Player_DrawWeapon_0_001BCFF0___(1);
                s3->x3D4 = 10;
                Player_PlaySwingSe_0_001CA930();
            }
        }
    } else if (s3->x3D5 == 3) {
    if (PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3 <= 0) {
        if (r <= 0) {
            Player_StartAttackMotion_1_001C6590__as_Player_DrawWeapon_0_001BCFF0___(6);
        } else {
            Player_StartAttackMotion_1_001C6590__as_Player_DrawWeapon_0_001BCFF0___(5);
            s3->x3D4 = 10;
            v = s3->x394;
            v = (v < r) ? v : r;
            PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3 = v;
            Inventory_Consume_0_001CBA80(idx, PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3);
            Player_PlayAttackSe_0_001CA6F0();
        }
        return;
    }
    if (ItemType_IsMagic_0_001D1E00(s3->x39C) && s3->x3D0 <= 0.17f) m2 = 0;
    if ((a1->x30 & m2) || (ItemType_IsGun_0_001D1DD0(s3->x39C) && (a1->x34 & m2))) {
        k = t->x56;
        if (k != 0) {
        o = Sfx_Spawn_2_00169B50__as_Player_UpdatePickup_0_001C0A10_(k, 0, 1, 0);
        if (o != 0) {
            sceVu0CopyMatrix__as_Player_DrawWeapon_0_001BCFF0__(&m, &gMatrixFromData_001F2170__as_Player_UpdatePickup_0_001C0A10_);
            sceVu0RotMatrixX(&m, &m, WRAP(-WRAP(s3->x18->x20)));
            sceVu0RotMatrixY(&m, &m, WRAP(WRAP(s3->x18->x24)));
            sceVu0CopyVector(&m.m[3], s3->x18);
            m.m[3].w = 1.0f;
            Sfx_SetTransform_1_001677C0__as_Player_UpdateEquipSounds_0_001BF940_(o, &m);
            Sfx_SetOwner_1_00167600(o, a0);
            c = cur_Player_HandleAttackInput_0_001C1A00();
            if (c != 0) {
                memset(&x, 0, 0x40);
                Player_CalcAttack_1_001CEBF0__as_Player_DrawWeapon_0_001BCFF0___(&x, x.y, c->x3CD);
                x.f30.f = Equip_CheckAmmo_0_001CC250(Equip_GetSlotItem_1_001CCD90(c->x390->x94 & 1));
            }
            if (s3->x39C == 11) {
                x.h[0] >>= 2;
                x.h[1] >>= 2;
                x.h[2] >>= 2;
                x.h[3] >>= 2;
                x.h[4] >>= 2;
                x.h[5] >>= 2;
            }
            Sfx_GetState_0_001672B0__as_Player_UpdatePickup_0_001C0A10_(o, &x);
        }
        }
        Player_StartAttackMotion_1_001C6590__as_Player_DrawWeapon_0_001BCFF0___(4);
        s3->x3D4 = 10;
        PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3--;
        c = cur_Player_HandleAttackInput_0_001C1A00();
        if (c != 0) {
            c->x3E0[0] = 0xFFFF; c->x3E0[1] = 0xFFFF; c->x3E0[2] = 0xFFFF; c->x3E0[3] = 0xFFFF;
            c->x3E0[4] = 0xFFFF; c->x3E0[5] = 0xFFFF; c->x3E0[6] = 0xFFFF; c->x3E0[7] = 0xFFFF;
        }
        Player_PlaySeA_1_001CA860();
    } else {
    if (Option_GetControlType_1_001A9450() < 2) {
        if (!(a1->x2C <= 0.5f)) s3->x3D4--; else s3->x3D4 = 10;
    } else {
        s3->x3D4 = 10;
        if (a1->x30 & 0x400) s3->x3D4 = 0;
    }
    if (s3->x3D4 <= 0) Player_StartAttackMotion_1_001C6590__as_Player_DrawWeapon_0_001BCFF0___(6);
    }
    }
}

/* Player_HandleMagicInput_1_001C2190 */
static inline s8 *get_Player_HandleMagicInput_1_001C2190(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

void Player_HandleMagicInput_1_001C2190(Actor *a, Pad *pad) {
    S_Player_HandleMagicInput_1_001C2190 *s;
    u32 mask;
    S_Player_HandleMagicInput_1_001C2190 *t;

    s = (S_Player_HandleMagicInput_1_001C2190 *)(a->unk518 + 0x180);
    mask = (Option_GetControlType_1_001A9450() < 2) ? 4 : 0x800;
    if (s->m39C == 9) {
        if (Inventory_HasItem_0_001CBC20__as_Player_HandleMagicInput_1_001C2190(0x12) <= 0) {
            if (s->m3D5 == 3) {
                Player_StartMagicMotion_0_001C69A0__as_Player_DrawWeapon_0_001BCFF0___(5);
            }
            return;
        }
    } else {
        if (Inventory_HasItem_0_001CBC20__as_Player_HandleMagicInput_1_001C2190(0x13) <= 0) {
            if (s->m3D5 == 3) {
                Player_StartMagicMotion_0_001C69A0__as_Player_DrawWeapon_0_001BCFF0___(5);
            }
            return;
        }
    }
    if (s->m3D5 == 0) {
        if (pad->x30 & mask) {
            Player_StartMagicMotion_0_001C69A0__as_Player_DrawWeapon_0_001BCFF0___(1);
            PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3 = 1;
            Player_PlaySwingSeB_0_001CA940();
        }
    } else if (s->m3D5 == 1) {
        if (!(pad->x34 & mask)) {
            Player_StartMagicMotion_0_001C69A0__as_Player_DrawWeapon_0_001BCFF0___(2);
            PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3 = 0;
        }
    } else if (s->m3D5 == 3) {
        if (!(pad->x34 & mask)) {
            Player_StartMagicMotion_0_001C69A0__as_Player_DrawWeapon_0_001BCFF0___(4);
            PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3 = 0;
            if (s->m39C == 9) {
                Inventory_Consume_0_001CBA80(0x12, 1);
            } else {
                Inventory_Consume_0_001CBA80(0x13, 1);
            }
            t = (S_Player_HandleMagicInput_1_001C2190 *)get_Player_HandleMagicInput_1_001C2190();
            if (t != NULL) {
                t->h[0] = 0xFFFF;
                t->h[1] = 0xFFFF;
                t->h[2] = 0xFFFF;
                t->h[3] = 0xFFFF;
                t->h[4] = 0xFFFF;
                t->h[5] = 0xFFFF;
                t->h[6] = 0xFFFF;
                t->h[7] = 0xFFFF;
            }
            Player_PlayMagicSe_0_001CA870();
        } else if (Option_GetControlType_1_001A9450() >= 2 && (pad->x30 & 0x400)) {
            Player_StartMagicMotion_0_001C69A0__as_Player_DrawWeapon_0_001BCFF0___(5);
            PlayerData_GetEquipEntry_0_001D1E10__as_Player_UpdatePickup_0_001C0A10_()->x3 = 0;
        }
    }
}

/* Player_HandleWeaponSwitch_1_001C23E0 */
static inline Sub_Player_DrawWeapon_0_001BCFF0 *getsub_Player_DrawWeapon_0_001BCFF0(void) {
    Obj_Player_DrawWeapon_0_001BCFF0 *o = gPlayerSbss_002022E4;
    if (o == NULL) return NULL;
    if (o->x518 == NULL) return NULL;
    return (Sub_Player_DrawWeapon_0_001BCFF0 *)(o->x518 + 0x180);
}

void Player_HandleWeaponSwitch_1_001C23E0(Obj_Player_DrawWeapon_0_001BCFF0 *arg0, Arg_Player_DrawWeapon_0_001BCFF0 *arg1) {
    s8 *h = arg0->x518;
    Sub_Player_DrawWeapon_0_001BCFF0 *s = (Sub_Player_DrawWeapon_0_001BCFF0 *)(h + 0x180);
    u8 k = 0;
    f32 f;
    if (((Hd *)h)->x516 > 0 && s->x3d5 == 0) {
        f = arg1->x28;
        if (!(f <= 0.5f)) {
            k = 1;
            if (!(arg1->x20 <= f)) k = 2;
            if (!(arg1->x24 <= f)) k = 4;
        } else {
            f = arg1->x2c;
            if (!(f <= 0.5f)) {
                k = 3;
                if (!(arg1->x20 <= f)) k = 2;
                if (!(arg1->x24 <= f)) k = 4;
            } else {
                if (!(arg1->x20 <= 0.5f)) k = 2;
                if (!(arg1->x24 <= 0.5f)) k = 4;
            }
        }
        if ((u8)k == 0) {
            s->x3cc = k;
            s->f.b6 = 0;
            s->f.b4 = 0;
            return;
        }
        if (s->f.b4 == 0 && (u8)k != s->x3cc) {
            s->x3cc = k;
            s->f.b6 = 0;
        } else {
            s->x3cc = k;
            s->f.b6 = 1;
            s->f.b4 = 0;
        }
        if (s->f.b6 == 0) {
            Sub_Player_DrawWeapon_0_001BCFF0 *p = getsub_Player_DrawWeapon_0_001BCFF0();
            if (p != NULL) {
                p->x3e0[0] = 0xFFFF; p->x3e0[1] = 0xFFFF; p->x3e0[2] = 0xFFFF; p->x3e0[3] = 0xFFFF;
                p->x3e0[4] = 0xFFFF; p->x3e0[5] = 0xFFFF; p->x3e0[6] = 0xFFFF; p->x3e0[7] = 0xFFFF;
            }
            Player_PlaySwitchSe_0_001CA880(k);
            s->x398 = 0;
            s->x396--;
            Player_StartSwitchMotion_1_001C6D40(k);
        }
    }
}

/* Player_CalcMoveSpeed_1_001C2640 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */

f32 Player_CalcMoveSpeed_1_001C2640(s8 *arg0) {
    f32 var_f20;
    s32 temp_v0;
    s32 temp_v0_2;
    s8 *temp_v1;
    s8 *p;

    temp_v1 = M2C_FIELD(arg0, s8 **, 0x518);
    p = temp_v1 + 0x180;
    var_f20 = 1.0f;
    if ((((u64) ((s64) M2C_FIELD(temp_v1, u8 *, 0x521) << 0x38) >> 0x3F) != 0) && (Player_GetStat_2_001CD450__as_Player_DrawWeapon_0_001BCFF0___(0x10, NULL, 0, 1) == 0)) {
        var_f20 = 0.5f;
    }
    if ((M2C_FIELD(p, u8 *, 0x3BF) == 7) && !(var_f20 <= 0.5f)) {
        var_f20 = 0.5f;
    }
    if (!(D_00222A54[0] & 1)) {
        temp_v0 = Player_GetWeight_1_001CDEC0();
        if (temp_v0 >= 2) {
            if (!(var_f20 <= 0.33333334f)) {
                var_f20 = 0.33333334f;
            }
        } else if ((temp_v0 == 1) && !(var_f20 <= 0.6666667f)) {
            var_f20 = 0.6666667f;
        }
    }
    temp_v0_2 = PlayerData_GetStatusTimer_0_001CE200__as_Player_UpdatePickup_0_001C0A10(3);
    if (temp_v0_2 >= 2) {
        if (!(var_f20 <= 0.33333334f)) {
            var_f20 = 0.33333334f;
        }
    } else if ((temp_v0_2 == 1) && !(var_f20 <= 0.6666667f)) {
        var_f20 = 0.6666667f;
    }
    return var_f20;
}

/* Player_ReadStick_0_001C27C0 */
static inline f32 spd(A_Player_UpdatePickup_0_001C0A10_ *a) {
    f32 k;
    if (a->q->slow != 0) k = 0.5f; else k = 1.0f;
    return 0.06981317f * k;
}

void Player_ReadStick_0_001C27C0(s8 *arg0, In_Player_ReadStick_0_001C27C0 *in) {
    f32 mag;
    f32 acc;
    A_Player_UpdatePickup_0_001C0A10_ *a;
    s32 on;
    f32 sign;

    on = 0;
    a = (A_Player_UpdatePickup_0_001C0A10_ *)(M2C_FIELD(arg0, s32 *, 0x518) + 0x180);
    acc = 0.0f;
    mag = 1.0f;
    if ((Option_GetControlType_1_001A9450() & 0xFF) >= 2) {
        if (in->btn & 4) {
            mag = 0.64000005f;
            on = 1;
        }
    } else if (in->y > acc && in->x > acc) {
        f32 t;
        mag = in->y * in->y;
        t = in->x * in->x;
        on = 1;
        mag = (t < mag) ? mag : t;
    }
    if (on != 0) {
        if (!(a->flg & 1)) {
            sign = 1.0f;
            if (a->r->rot > 0.0f) sign = -1.0f;
            acc += mag * sign * spd(a);
            a->r->rot += acc * a->dt;
            if (a->r->rot * sign > 0.0f) a->r->rot = 0.0f;
        }
    } else {
        if (in->y > 0.1f) acc -= 0.4f * spd(a);
        if (in->x > 0.1f) acc += 0.4f * spd(a);
        a->r->rot += acc * a->dt;
    }
}

/* Player_UpdateHeadBob_1_001C2A50 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void Player_UpdateHeadBob_1_001C2A50(Actor *a) {
    P_Player_UpdateHeadBob_1_001C2A50 *p;
    Vec v;
    f32 x;
    p = (P_Player_UpdateHeadBob_1_001C2A50 *)(a->unk518 + 0x180);
    sceVu0CopyVector(&v, &p->v50);
    v.y = 0.0f;
    x = sqrtf(sceVu0InnerProduct(&v, &v));
    p->f454 = p->f380;
    if (x <= 100.0f && fabsf(p->f380) < 0.2f) {
        p->f384 = 0.0f;
        p->f388 = 0.0f;
        p->f380 = 0.0f;
        p->u38C = 0;
        p->f3A2.f.b2 = 0;
        return;
    }
    p->f384 *= 0.5f;
    p->f388 *= 0.5f;
    if (p->f3A1.f.b5) {
        x = WRAP(0.3f * p->u38C);
    } else {
        x = WRAP(0.2f * p->u38C);
    }
    p->f388 += 0.5f * sinf(x);
    p->f384 += p->f388;
    p->u38C++;
    p->f380 = Option_GetMoveEffect_2_001A9440() ? p->f384 : 0.0f;
    if (!(p->f384 <= 1.5f)) {
        if (!p->f3A2.f.b2) {
            Player_PlayMoveSe_1_001CA4A0(p->f3A1.f.b7 ? 0x10 : p->u3BF, p->f3A1.f.b5);
        }
        p->f3A2.f.b2 = 1;
    } else {
        p->f3A2.f.b2 = 0;
    }
}

/* Player_UpdateWalk_1_001C2DB0 */

void Player_UpdateWalk_1_001C2DB0(Actor *a, f32 *in) {
    Vec v90;
    Vec v80;
    Vec v70;
    Vec v60;
    P_Player_UpdateWalk_1_001C2DB0 *p;
    s32 n;
    f32 d;
    f32 y;
    f32 sc;
    f32 yaw;
    f32 pitch;
    f32 t;
    f32 u;
    Q_Player_UpdateWalk_1_001C2DB0 *q;

    yaw = 0.0f;
    p = (P_Player_UpdateWalk_1_001C2DB0 *)(a->unk518 + 0x180);
    pitch = 0.0f;
    if (!(in[2] <= 0.2f) || !(in[3] <= 0.2f)) {
        n = 0;
        if (!(in[2] < 1.0f) && p->x3CD == 0) n -= 2;
        else if (!(in[2] <= 0.2f)) n -= 1;
        if (!(in[3] < 1.0f) && p->x3CD == 0) n += 2;
        else if (!(in[3] <= 0.2f)) n += 1;
        switch (func_00120570(n)) {
        case 0:
            in[3] = 0.0f;
            in[2] = 0.0f;
            break;
        case 1:
            sceVu0ScaleVector(&v90, (Vec *)((u8 *)p->x18 + 0x80), n > 0 ? 60.000004f : -75.0f);
            sceVu0AddVector(&p->v50, &v90, &p->v50);
            break;
        case 2:
            sceVu0ScaleVector(&v80, (Vec *)((u8 *)p->x18 + 0x80), n > 0 ? 100.0f : -250.0f);
            sceVu0AddVector(&p->v50, &v80, &p->v50);
            p->f3A0.b.hi.f.b5 = 1;
            break;
        }
    }
    if (!(in[5] <= 0.2f) || !(in[4] <= 0.2f)) {
        n = 0;
        if (!(in[5] <= 0.4f) && p->x3CD == 0) n -= 2;
        else if (!(in[5] <= 0.2f)) n -= 1;
        if (!(in[4] <= 0.4f) && p->x3CD == 0) n += 2;
        else if (!(in[4] <= 0.2f)) n += 1;
        sc = n >= 0 ? 1.0f : -1.0f;
        switch (func_00120570(n)) {
        case 0:
            in[4] = 0.0f;
            in[5] = 0.0f;
            break;
        case 1:
            sceVu0ScaleVector(&v70, (Vec *)((u8 *)p->x18 + 0x60), sc * (0.6f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f))));
            sceVu0AddVector(&p->v50, &v70, &p->v50);
            break;
        case 2:
            sceVu0ScaleVector(&v60, (Vec *)((u8 *)p->x18 + 0x60), sc * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &v60, &p->v50);
            p->f3A0.b.hi.f.b5 = 1;
            break;
        }
    }
    if (!(in[0] <= 0.2f) && in[1] <= 0.2f) {
        yaw += in[0] * (0.0488692187f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (!(in[1] <= 0.2f) && in[0] <= 0.2f) {
        yaw -= in[1] * (0.0488692187f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    sc = Player_CalcMoveSpeed_1_001C2640(a);
    y = p->v50.y;
    p->v50.y = 0.0f;
    d = sqrtf(sceVu0InnerProduct(&p->v50, &p->v50));
    if (d < 40.0f) sceVu0CopyVector(&p->v50, &gZeroVec_003139A0__as_Player_UpdatePickup_0_001C0A10_);
    p->f428 = Lerpf_3_0015DF90(p->f428, p->f3A0.b.hi.f.b5 ? 0.8f * sc : 0.5f * sc, 0.2f);
    u = 600.0f * (p->x390->x48 ? 0.5f : 1.0f);
    t = p->f428 * u;
    if (!(d <= t)) {
        sceVu0ScaleVector(&p->v50, &p->v50, t / d);
    }
    if (in[2] <= 0.05f && in[3] <= 0.05f && in[5] <= 0.05f && in[4] <= 0.05f) {
        sceVu0ScaleVector(&p->v50, &p->v50, 0.64000005f);
    }
    p->v50.y = y;
    sc = (p->x3CD == 0) ? sc : 0.5f * sc;
    p->f42C = Lerpf_3_0015DF90(p->f42C, sc, 0.2f);
    q = p->x18;
    q->x20 += pitch * p->f42C;
    q = p->x18;
    q->x24 += yaw * p->f42C;
    Player_UpdateHeadBob_1_001C2A50(a);
    p->f39D.b4 = 1;
    p->f3A0.h.f = 0;
    p->f39D.lo4 = 0;
}

/* Player_UpdateTurn_0_001C34F0 */
static inline f32 mu(f32 a, f32 b) { return a * b; }

void Player_UpdateTurn_0_001C34F0(s8 *arg0, f32 *a) {
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    SS_Player_UpdateTurn_0_001C34F0 *s;
    f32 k;
    f32 sv;
    f32 len;
    f32 f;
    f32 r;

    s = (SS_Player_UpdateTurn_0_001C34F0 *)(*(s8 **)(arg0 + 0x518) + 0x180);
    if (s->h3A0.cnt < 0x3F) {
        s->h3A0.cnt++;
    }
    if (s->h3A0.cnt == 10) {
        Player_PlayLandSe_0_001CA2C0();
    }
    if (s->h3A0.cnt < 4) {
        if (a[2] > 0.0f) {
            sceVu0ScaleVector(&t0, &s->p18->v80, 0.2f * (250.0f * -a[2]));
            sceVu0AddVector(&s->v50, &t0, &s->v50);
        }
        if (a[3] > 0.0f) {
            sceVu0ScaleVector(&t1, &s->p18->v80, 0.2f * (100.0f * a[3]));
            sceVu0AddVector(&s->v50, &t1, &s->v50);
        }
        if (a[5] > 0.0f) {
            k = s->p390->x48 ? 0.5f : 1.0f;
            sceVu0ScaleVector(&t2, &s->p18->v60, 0.2f * (-a[5] * (100.0f * k)));
            sceVu0AddVector(&s->v50, &t2, &s->v50);
        }
        if (a[4] > 0.0f) {
            k = s->p390->x48 ? 0.5f : 1.0f;
            sceVu0ScaleVector(&t3, &s->p18->v60, 0.2f * (a[4] * (100.0f * k)));
            sceVu0AddVector(&s->v50, &t3, &s->v50);
        }
    }
    if (a[0] > 0.0f) {
        k = s->p390->x48 ? 0.5f : 1.0f;
        s->p18->f24 = s->p18->f24 + 0.3f * (a[0] * (0.0488692187f * k));
    }
    if (a[1] > 0.0f) {
        k = s->p390->x48 ? 0.5f : 1.0f;
        s->p18->f24 = s->p18->f24 - 0.3f * (a[1] * (0.0488692187f * k));
    }
    sv = s->v50.y;
    s->v50.y = 0.0f;
    sceVu0ScaleVector(&s->v50, &s->v50, 0.640000045f);
    len = sceVu0InnerProduct(&s->v50, &s->v50);
    s->v50.y = sv;
    len = sqrtf(len);
    if (fabsf(s->p18->f20) < 0.0872664675f) {
        if (s->b39D.n > 3) {
            f = len / 1000.0f;
            f = f > 1.0f ? 1.0f : f;
            r = s->v50.y > 0.0f ? 0.05f : 0.01f;
            s->f3A4 = s->f3A4 + mu((-0.7853982f - s->f3A4) * r, f);
            s->b39D.n = 5;
        }
        s->b39D.n++;
    } else {
        s->f3A4 *= 0.8f;
        s->b39D.n = 0;
    }
    s->b39D.b4 = 0;
}

/* Player_UpdateFall_0_001C39D0 */

void Player_UpdateFall_0_001C39D0(Actor *a, In_Player_UpdateFall_0_001C39D0 *in, f32 dt) {
    P_Player_UpdateFall_0_001C39D0 *p;
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    Vec t4;
    Vec t5;
    Vec t6;
    Vec t7;
    f32 m;

    p = (P_Player_UpdateFall_0_001C39D0 *)(a->unk518 + 0x180);
    sceVu0ScaleVector(&t0, &p->v50, -dt);
    sceVu0AddVector(&p->v40, &t0, &p->v40);
    p->v50.y = p->v50.y - 3920.0f * dt;
    sceVu0ScaleVector(&p->v50, &p->v50, 0.9f);
    if (sqrtf(sceVu0InnerProduct(&p->v50, &p->v50)) < 50.0f) {
        sceVu0CopyVector(&p->v50, &gZeroVec_003139A0__as_Player_UpdatePickup_0_001C0A10_);
    }
    sceVu0ScaleVector(&t1, &p->v50, dt);
    sceVu0AddVector(&p->v40, &t1, &p->v40);
    if (in->x8 > 0.0f) {
        sceVu0ScaleVector(&t2, &p->x18->v80, 250.0f * -in->x8);
        sceVu0AddVector(&p->v50, &t2, &p->v50);
    }
    if (in->xC > 0.0f) {
        sceVu0ScaleVector(&t3, &p->x18->v80, 100.0f * in->xC);
        sceVu0AddVector(&p->v50, &t3, &p->v50);
    }
    if (in->x0 > 0.0f) {
        p->x18->x24 += in->x0 * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (in->x4 > 0.0f) {
        p->x18->x24 -= in->x4 * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (in->x14 > 0.0f) {
        if (in->x14 > 0.4f) {
            sceVu0ScaleVector(&t4, &p->x18->v60, -1.0f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &t4, &p->v50);
        } else {
            sceVu0ScaleVector(&t5, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &t5, &p->v50);
        }
    }
    if (in->x10 > 0.0f) {
        if (in->x10 > 0.4f) {
            sceVu0ScaleVector(&t6, &p->x18->v60, 100.0f * (p->x390->x48 ? 0.5f : 1.0f));
            sceVu0AddVector(&p->v50, &t6, &p->v50);
        } else {
            sceVu0ScaleVector(&t7, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &t7, &p->v50);
        }
    }
    p->x3A4 *= 0.5f;
    if (in->x1C > 0.0f && in->x18 > 0.0f) {
        m = in->x18 < in->x1C ? in->x18 : in->x1C;
        p->v50.y += 200.0f * m;
    }
    if (in->x14 > 0.0f && in->x10 > 0.0f) {
        m = in->x10 < in->x14 ? in->x10 : in->x14;
        p->v50.y += -200.0f * m;
    }
    p->f = 0;
}

/* Player_UpdateSlide_0_001C3EF0 */

void Player_UpdateSlide_0_001C3EF0(Actor *a, In_Player_UpdateFall_0_001C39D0 *in, f32 dt) {
    Vec c;
    Vec n;
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    Vec t4;
    Vec t5;
    Vec t6;
    Vec t7;
    Vec t8;
    Vec t9;
    Vec t10;
    Vec t11;
    P_Player_UpdateSlide_0_001C3EF0 *p;
    s32 k;

    p = (P_Player_UpdateSlide_0_001C3EF0 *)(a->unk518 + 0x180);
    if (p->cnt < 0x3F) {
        p->cnt++;
    }
    if (!(p->cnt < 15)) {
        sceVu0ScaleVector(&t0, &p->v50, -dt);
        sceVu0AddVector(&p->v40, &t0, &p->v40);
        p->v50.y = p->v50.y - 3920.0f * dt;
        sceVu0ScaleVector(&p->v50, &p->v50, 0.5f);
        sceVu0ScaleVector(&t1, &p->v50, dt);
        sceVu0AddVector(&p->v40, &t1, &p->v40);
    }
    if (p->b12) {
        if (p->cnt < 10) {
            sceVu0ScaleVector(&t2, &gPlayerBss_004B4D00, 120.0f);
            sceVu0AddVector(&p->v50, &t2, &p->v50);
            sceVu0ScaleVector(&t3, &gMatrixFromData_001F2140, 150.0f);
            sceVu0AddVector(&p->v50, &t3, &p->v50);
        } else if (p->cnt < 0x30) {
            sceVu0ScaleVector(&t4, &gPlayerBss_004B4D00, -200.0f);
            sceVu0AddVector(&p->v50, &t4, &p->v50);
            sceVu0ScaleVector(&t5, &gMatrixFromData_001F2140, 100.0f);
            sceVu0AddVector(&p->v50, &t5, &p->v50);
        } else {
            sceVu0ScaleVector(&t6, &gPlayerBss_004B4D00, -50.0f);
            sceVu0AddVector(&p->v50, &t6, &p->v50);
            if (p->cnt > 0x3C) {
                p->b12 = 0;
            }
        }
        sceVu0CopyVector(&n, &p->x18->v80);
        *(s32 *)&n.y = 0;
        sceVu0Normalize(&n, &n);
        sceVu0OuterProduct(&c, &gPlayerBss_004B4D00, &n);
        if (sceVu0InnerProduct(&gPlayerBss_004B4D00, &n) < -0.9f) {
            p->x18->x24 += 2.0f * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
        } else {
            if (c.y < -0.05f) {
                p->x18->x24 -= 2.5f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
            }
            if (c.y > 0.05f) {
                p->x18->x24 -= 2.5f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
            }
        }
    } else {
        sceVu0OuterProduct(&c, &gPlayerBss_004B4D00, &p->x18->v80);
        if (c.y > 0.05f) {
            p->x18->x24 -= 2.0f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
        }
        if (c.y < -0.05f) {
            p->x18->x24 -= 2.0f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
        }
        if (!(p->cnt < 15)) {
            sceVu0ScaleVector(&t7, &gPlayerBss_004B4D00, -400.0f);
            sceVu0AddVector(&p->v50, &t7, &p->v50);
            if (in->x8 > 0.0f) {
                p->v50.y = p->v50.y + 300.0f * -in->x8;
            }
            if (in->xC > 0.0f) {
                p->v50.y = p->v50.y + 300.0f * in->xC;
            }
            if (in->x14 > 0.4f) {
                sceVu0ScaleVector(&t8, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t8, &p->v50);
            }
            if (in->x10 > 0.4f) {
                sceVu0ScaleVector(&t9, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t9, &p->v50);
            }
            if (in->x0 > 0.4f) {
                sceVu0ScaleVector(&t10, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t10, &p->v50);
            }
            if (in->x4 > 0.4f) {
                sceVu0ScaleVector(&t11, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t11, &p->v50);
            }
        }
    }
    if (p->x154 != 0 && p->x15C->d0 == 1) {
        k = p->x15C->c0;
        if (k == 12 || k == 13) {
            gPlayerSbss_002022E8 = gPlayerSbss_002022E8 + fabsf(p->v50.y);
            if (gPlayerSbss_002022E8 > 10000.0f) {
                gPlayerSbss_002022E8 -= 10000.0f;
                if (fabsf(p->v50.y) > 100.0f) {
                    Player_PlayMoveSe_1_001CA4A0__as_Player_UpdateSlide_0_001C3EF0(k, 1);
                }
            }
        }
    }
    p->f = 0;
}

/* Player_MapControls_0_001C4760 */
void Player_MapControls_0_001C4760(Actor *a, Out *o) {
    S_Player_UpdatePickup_0_001C0A10_ *s;
    u8 r;
    u16 bt;

    u32 m;
    f32 v;

    s = (S_Player_UpdatePickup_0_001C0A10_ *)(a->unk518 + 0x180);
    r = Option_GetControlType_1_001A9450();
#define CL(x) if ((x) > 1.0f) (x) = 1.0f
#define AX(g, n, p) v = (g)[0]; if (v < 0.0f) (n) = -v; else if (v > 0.0f) (p) = v
#define BT(a, b, c, d) bt = *(volatile u16 *)gMenuBss_00317230; if (bt & 0x400) (a) = 1.0f; else if (bt & 0x800) (b) = 1.0f; \
    bt = *(volatile u16 *)gMenuBss_00317230; if (bt & 0x100) (c) = 1.0f; else if (bt & 0x200) (d) = 1.0f
    switch (r % 6) {
    case 0:
        o->f[2] = 7.0f * gPlayerBss_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(gPlayerBss_00317248, o->f[2], o->f[3]);
        o->f[1] = 5.0f * gPlayerBss_00317250[0];
        o->f[0] = 5.0f * gPlayerBss_0031724C[0];
        CL(o->f[1]);
        CL(o->f[0]);
        AX(gPlayerBss_00317244, o->f[1], o->f[0]);
        o->f[4] = gPlayerBss_0031726C[0];
        o->f[5] = gPlayerBss_00317270[0];
        o->f[6] = gPlayerBss_00317274[0];
        o->f[7] = D_00317278[0];
        AX(gPlayerBss_0031723C, o->f[9], o->f[8]);
        AX(gPlayerBss_00317240, o->f[10], o->f[11]);
        break;
    case 1:
        o->f[2] = 7.0f * gPlayerBss_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(gPlayerBss_00317248, o->f[2], o->f[3]);
        o->f[1] = 3.0f * gPlayerBss_0031726C[0];
        o->f[0] = 3.0f * gPlayerBss_00317270[0];
        CL(o->f[1]);
        CL(o->f[0]);
        o->f[4] = 3.0f * gPlayerBss_00317250[0];
        o->f[5] = 3.0f * gPlayerBss_0031724C[0];
        CL(o->f[4]);
        CL(o->f[5]);
        AX(gPlayerBss_00317244, o->f[4], o->f[5]);
        o->f[6] = gPlayerBss_00317274[0];
        o->f[7] = D_00317278[0];
        AX(gPlayerBss_0031723C, o->f[9], o->f[8]);
        AX(gPlayerBss_00317240, o->f[10], o->f[11]);
        break;
    case 2:
    case 3:
        o->f[2] = 7.0f * gPlayerBss_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(gPlayerBss_00317248, o->f[2], o->f[3]);
        o->f[1] = 5.0f * gPlayerBss_00317250[0];
        o->f[0] = 5.0f * gPlayerBss_0031724C[0];
        CL(o->f[1]);
        CL(o->f[0]);
        AX(gPlayerBss_00317244, o->f[1], o->f[0]);
        AX(gPlayerBss_0031723C, o->f[4], o->f[5]);
        if (r == 2) {
            AX(gPlayerBss_00317240, o->f[6], o->f[7]);
        } else {
            AX(gPlayerBss_00317240, o->f[7], o->f[6]);
        }
        BT(o->f[8], o->f[9], o->f[10], o->f[11]);
        break;
    case 4:
    case 5:
        o->f[2] = 7.0f * gPlayerBss_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(gPlayerBss_00317248, o->f[2], o->f[3]);
        AX(gPlayerBss_0031723C, o->f[1], o->f[0]);
        o->f[4] = 3.0f * gPlayerBss_00317250[0];
        o->f[5] = 3.0f * gPlayerBss_0031724C[0];
        CL(o->f[4]);
        CL(o->f[5]);
        AX(gPlayerBss_00317244, o->f[4], o->f[5]);
        if (r == 4) {
            AX(gPlayerBss_00317240, o->f[6], o->f[7]);
        } else {
            AX(gPlayerBss_00317240, o->f[7], o->f[6]);
        }
        BT(o->f[8], o->f[9], o->f[10], o->f[11]);
        break;
    }
    o->x30 = gMapCommandBss_00317238[0];
    o->x34 = gMenuBss_00317230[0];
    if (PlayerData_GetStatusTimer_0_001CE200(1)) {
        memset(o, 0, 0x30);
        m = 0x9000;
        if (s->m == 0) m |= 0x2000;
        o->x30 &= ~m;
        o->x34 &= ~m;
    }
    if (PlayerData_GetStatusTimer_0_001CE200(5)) {
        o->x30 &= ~0x8000;
        o->x34 &= ~0x8000;
    }
}
#undef E80
#undef Actor

/* PlayerProc_Collide_0_001C5150_ */

/* PlayerProc_Collide_0_001C5150 */

void PlayerProc_Collide_0_001C5150(Actor *a) {
    P_PlayerProc_Collide_0_001C5150 *p;
    s32 close;
    s32 hit;
    s32 i1; s8 ***q1; s32 j2; s8 *n2; s8 ***q2; s32 i2; s8 ***q3; s32 i3; s8 *n4; s8 ***q4; s32 i4; s32 j4;
    f32 d;
    f32 t;
    f32 end;
    Vec v;
    Vec dir;

    p = (P_PlayerProc_Collide_0_001C5150 *)(a->unk518 + 0x180);
    if (gPlayerSbss_002022BC__as_PlayerProc_Collide_0_001C5150_ == (&gMapSbss_00201E80__as_PlayerProc_Collide_0_001C5150_)[2]) gPlayerSbss_002022D8 = 0;
    if (gPlayerSbss_002022BC__as_PlayerProc_Collide_0_001C5150_ == (&gMapSbss_00201E80__as_PlayerProc_Collide_0_001C5150_)[3]) gPlayerSbss_002022D8 = 1;
    memset(&p->m130, 0, 0x40);
    close = 0;
    sceVu0SubVector(&dir, &p->pos, p->o + 0x10);
    sceVu0Normalize__as_PlayerProc_Collide_0_001C5150_(&dir, &dir);
    if (Vec_DistXZ_2_0015DEE0(&p->pos, p->o + 0x10) < 20.0f && !p->b0) close = 1;
    d = Vec_DistB_3_0015DF50(&p->pos, p->o + 0x10);
    if (close) t = d; else t = 20.0f;
    for (end = 20.0f + d; t < end; t += 20.0f) {
        if (!(t <= d)) t = d;
        sceVu0ScaleVector__as_PlayerProc_Collide_0_001C5150_(&v, &dir, t);
        sceVu0AddVector__as_PlayerProc_Collide_0_001C5150_(&p->v110, p->o + 0x10, &v);
        p->v110.y = p->v110.y + 220.0f;
        p->v110.y = p->v110.y - 100.0f;
        p->v110.w = 100.0f;
        hit = 0;
        for (i1 = 0, q1 = (s8 ***)(&gMapSbss_00201E80__as_PlayerProc_Collide_0_001C5150_ + 2); i1 < 2; i1++, q1++) {
            if (*q1 != 0 && **q1 != 0 && MapColl_SphereCastAll_0_001B34B0(**q1, &p->m130, &p->v110, 3, 0)) hit = 1;
        }
        for (i2 = 0, q2 = (s8 ***)(&gMapSbss_00201E80__as_PlayerProc_Collide_0_001C5150_ + 2); i2 < 2; i2++, q2++) {
            if (*q2 != 0 && (n2 = **q2) != 0) {
                for (j2 = 0; j2 < *(u16 *)(n2 + 0x6E); j2++) {
                    if (MapColl_SphereCast_0_001B2B90(n2, &p->m130, &p->v110, j2, 3, 0)) hit = 1;
                }
            }
        }
        if (hit) break;
    }
    if (p->x154) {
        sceVu0ScaleVector__as_PlayerProc_Collide_0_001C5150_(&p->vB0, &p->v140, 100.0f);
        sceVu0AddVector__as_PlayerProc_Collide_0_001C5150_(&p->vB0, &p->vB0, &p->m130);
        p->vB0.w = 1.0f;
        sceVu0CopyVector__as_PlayerProc_Collide_0_001C5150(&p->vC0, &p->vB0);
        p->vB0.y = *(f32 *)(p->x10 + 0x14);
        p->vB0.y = p->vB0.y + 220.0f;
        p->vB0.y = p->vB0.y - 80.0f;
        p->vC0.y = p->vC0.y + 103.0f;
    } else {
        sceVu0CopyVector__as_PlayerProc_Collide_0_001C5150(&p->vB0, &p->pos);
        p->vB0.w = 1.0f;
        sceVu0CopyVector__as_PlayerProc_Collide_0_001C5150(&p->vC0, &p->pos);
        p->vC0.w = 1.0f;
        p->vB0.y = *(f32 *)(p->x10 + 0x14);
        p->vB0.y = p->vB0.y + 220.0f;
        p->vB0.y = p->vB0.y - 80.0f;
        p->vC0.y = p->vC0.y + 223.0f;
    }
    memset(&p->mD0, 0, 0x40);
    for (i3 = 0, q3 = (s8 ***)(&gMapSbss_00201E80__as_PlayerProc_Collide_0_001C5150_ + 2); i3 < 2; i3++, q3++) {
        if (*q3 != 0 && **q3 != 0) MapColl_CapsuleCastAll_1_001B3240__as_PlayerProc_Collide_0_001C5150_(**q3, (Vec *)&p->mD0, &p->vB0, 4, 0);
    }
    for (i4 = 0, q4 = (s8 ***)(&gMapSbss_00201E80__as_PlayerProc_Collide_0_001C5150_ + 2); i4 < 2; i4++, q4++) {
        if (*q4 != 0 && (n4 = **q4) != 0) {
            for (j4 = 0; j4 < *(u16 *)(n4 + 0x6E); j4++) {
                MapColl_CapsuleCast_1_001B2800__as_PlayerProc_Collide_0_001C5150_(n4, (Vec *)&p->mD0, &p->vB0, j4, 4, 0);
            }
        }
    }
}

/* PlayerProc_Attack_0_001C55A0 */
static inline Sub_PlayerProc_Collide_0_001C5150 *getsub_PlayerProc_Collide_0_001C5150(void) {
    Obj_Player_DrawWeapon_0_001BCFF0 *o = gPlayerSbss_002022E4__as_PlayerProc_Attack_0_001C55A0;
    if (o == NULL) return NULL;
    if (o->x518 == NULL) return NULL;
    return (Sub_PlayerProc_Collide_0_001C5150 *)(o->x518 + 0x180);
}
void PlayerProc_Attack_0_001C55A0(s32 a0, s32 a1, s32 a2, Arg_PlayerProc_Collide_0_001C5150 *a3, s32 a4, s32 a5) {
    Sub_PlayerProc_Collide_0_001C5150 *s = getsub_PlayerProc_Collide_0_001C5150();
    s32 v;
    Vec_PlayerProc_Attack_0_001C55A0 pos;
    if (s != NULL) {
        switch (a3->mode) {
        case 0:
            if (a5 != 0) Attack_PlaySe_0_001D1E80(a0, a2, a3, a4, a5);
            break;
        case 1:
            if (a5 != 0) {
                v = Attack_SpawnSfx_0_001D1F20(a0, (s8 *)gPlayerSbss_002022E4__as_PlayerProc_Attack_0_001C55A0 + 0x580, a1, a2, a3, a4, a5);
                if (v != 0) Sfx_SetOwner_1_00167600__as_PlayerProc_Collide_0_001C5150_(v, gPlayerSbss_002022E4__as_PlayerProc_Attack_0_001C55A0);
            }
            break;
        case 2:
            Combat_UpdateAttackWrap_0_0013B950(a0, a1, a2, a3, a4, a5);
            if (s->x39C != 0) {
                Sub_PlayerProc_Collide_0_001C5150 *p = getsub_PlayerProc_Collide_0_001C5150();
                if (p != NULL) sceVu0CopyVector(&pos, (s8 *)p + 0x40);
                pos.y += 220.0f;
                MapObj_SnapToGround_0_001B9F10(&pos, s->x18 + 0x20, 300.0f, 500.0f);
            }
            s->f.b2 = 1;
            break;
        case 3:
            break;
        }
    }
}

/* PlayerProc_Animate_0_001C5750 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void PlayerProc_Animate_0_001C5750(Actor *a, f32 dt) {
    Mtx m1;
    Mtx m2;
    P_PlayerProc_Animate_0_001C5750 *p;
    s32 r;
    f32 lim;
    s32 *h;

    p = (P_PlayerProc_Animate_0_001C5750 *)(a->unk518 + 0x180);
    h = p->xC;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    if (p->d1 < 2) {
        lim = Mdl_GetMotionLength_0_00173F70(*h, p->x28->id);
        p->x28->x10 = p->x28->xC;
        if (p->d0) {
            p->x28->xC -= dt * p->x28->x14;
            if (p->c7) {
                if (p->x28->xC < 0.0f) {
                    do {
                        p->x28->xC += lim;
                    } while (p->x28->xC < 0.0f);
                }
            } else if (p->x28->xC < 0.0f) {
                p->x28->xC = 0.0f;
                p->d1++;
            }
        } else {
            p->x28->xC += dt * p->x28->x14;
            if (p->c7) {
                while (p->x28->xC > lim) {
                    p->x28->xC -= lim;
                }
            } else if (!(p->x28->xC <= lim)) {
                p->x28->xC = lim;
                p->d1++;
            }
        }
    }
    if (ItemType_IsGun_0_001D1DD0(p->x39C) && p->x3D5 == 4) {
        r = rand() % 2;
        p->x3AD = r * -(rand() % 2);
        r = rand() % 2;
        p->x3AE = r * -(rand() % 2);
    }
    Mdl_AnimateWrap_0_00171B70(p->x28, p->x28->id, p->x28->xC);
    p->x2C->x3F4 += 25.0f;
    p->x2C->x3F8 += -5.0f;
    p->x2C->x3F0 += p->x3AD;
    p->x2C->x3F4 += p->x3AE;
    sceVu0RotMatrixX__as_PlayerProc_Collide_0_001C5150_(&m1, &gMatrixFromData_001F2170__as_PlayerProc_Collide_0_001C5150_, WRAP(WRAP(-1.0f * p->x18->x30)));
    m1.m[3].w = 1.0f;
    sceVu0CopyMatrix(&m2, &gMatrixFromData_001F2170__as_PlayerProc_Collide_0_001C5150_);
    if (Option_GetMoveEffect_2_001A9440()) {
        if (p->a5) {
            m2.m[3].y += 2.0f * p->x380;
        } else {
            m2.m[3].y += p->x380;
        }
    }
    if (p->x390->b0) {
        p->x2C->v3C0.x *= -1.0f;
    }
    sceVu0MulMatrix__as_PlayerProc_Collide_0_001C5150_(&p->x2C->v3C0, &m1, &p->x2C->v3C0);
    sceVu0MulMatrix__as_PlayerProc_Collide_0_001C5150_(&p->x2C->v3C0, &m2, &p->x2C->v3C0);
    sceVu0CopyMatrix(&p->x2C->v280, &p->x18->v60);
    Mdl_UpdateBoneMatricesCur_0_00171540(p->x28, &gMatrixFromData_001F2170__as_PlayerProc_Collide_0_001C5150_);
    if (ItemType_IsWeapon_0_001D1D50(p->x39C)) {
        if (ItemType_IsShield_0_001D1DA0(p->x39C)) {
            Player_UpdateMagicState_0_001C6250__as_Player_DrawWeapon_0_001BCFF0___(a);
        } else {
            Player_UpdateAttackState_0_001C5FB0__as_Player_DrawWeapon_0_001BCFF0___(a);
        }
    } else {
        Player_UpdateSwitchState_0_001C6470__as_Player_DrawWeapon_0_001BCFF0___(a);
    }
    if (p->c3 && p->x3D5 == 0) {
        p->x390->b0 ^= 1;
        p->c3 = 0;
        p->c4 = 1;
        p->x3D4 = 0;
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        Player_PlayNullSe_0_001CA950();
        Snd_StopStream3_0_0012DA80();
        Player_RecalcStats_1_001CEDC0(3);
        Player_UpdateEquipModel_0_001CE7D0(p, 1);
        Hud_ClearTimers_0_0019A840();
    }
}
#undef E80
#undef Actor

/* Player_UpdateArmBones_0_001C5DE0_____ */

/* Player_UpdateArmBones_0_001C5DE0____ */

/* Player_UpdateArmBones_0_001C5DE0___ */

/* Player_UpdateArmBones_0_001C5DE0___ */
/* Player_UpdateArmBones_0_001C5DE0__ */

/* Player_UpdateArmBones_0_001C5DE0_ */

/* Player_UpdateArmBones_0_001C5DE0 */

/* Player_UpdateArmBones_0_001C5DE0 */
void Player_UpdateArmBones_0_001C5DE0(Actor *a0) {
    s8 *p;
    s32 i;
    s8 *e;
    s8 **h;
    s8 *o;
    s32 off;
    s8 **l;
    s32 c;
    f32 v[16];

    p = a0->unk518 + 0x180;
    o = *(s8 **)(a0->unk518 + 0x540);
    if (o != NULL) {
        if (Item_GetType_0_001CCDE0__as_Player_UpdateArmBones_0_001C5DE0_____(*(s16 *)(o + 0x9C)) == 9 || Item_GetType_0_001CCDE0__as_Player_UpdateArmBones_0_001C5DE0_____(*(s16 *)(o + 0x9C)) == 0xC) {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x14C0);
        } else {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x2640);
        }
    }
    o = *(s8 **)(p + 0x3C4);
    if (o != NULL) {
        if (*(u8 *)(p + 0x39C) == 0xA || *(u8 *)(p + 0x39C) == 0xE) {
            sceVu0CopyMatrix(v, gMatrixFromData_001F2170__as_Player_UpdateArmBones_0_001C5DE0_____);
            v[0] = -1.0f;
            sceVu0MulMatrix__as_Player_UpdateArmBones_0_001C5DE0_____(o, *(s8 **)(p + 0x2C) + 0x2640, v);
        } else {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x2640);
        }
    }
    o = *(s8 **)(p + 0x3C8);
    if (o != NULL) {
        l = *(s8 ***)(o + 0x84);
        if (l != NULL) {
            h = (s8 **)*l;
            e = Mdl_GetFrameData_0_001715B0__as_Player_UpdateArmBones_0_001C5DE0_____(l);
            c = 0;
            i = 0;
            if (i < *(u16 *)(*(s8 **)*h + 0x14)) {
                off = 0;
                do {
                    sceVu0CopyMatrix(e + 0xC0, *(s8 **)(p + 0x2C) + off + 0xC0);
                    ((BF *)(e + 0x1F8))->b5 = c;
                    ((BF *)(e + 0x1F8))->b2 = c;
                    i++;
                    off += 0x140;
                    e += 0x140;
                } while (i < *(u16 *)(*(s8 **)*h + 0x14));
            }
            ((BF *)((s8 *)h + 0x25))->b0 = 1;
        }
    }
}

/* Player_UpdateAttackState_0_001C5FB0 */
static inline Obj_Player_UpdateArmBones_0_001C5DE0 *get_Player_UpdateArmBones_0_001C5DE0(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return (Obj_Player_UpdateArmBones_0_001C5DE0 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

void Player_UpdateAttackState_0_001C5FB0(void) {
    Obj_Player_UpdateArmBones_0_001C5DE0 *p = get_Player_UpdateArmBones_0_001C5DE0();
    if (p == NULL) return;
    switch (p->u3D5) {
    case 0: break;
    case 1:
        if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(8);
            else Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(7); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(2);
        } else if (p->f3D7.f.b1) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(3);
        }
        break;
    case 2: break;
    case 3:
        if (Game_GetBusy_0_0012C020()) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(6);
        } else if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(8);
            else Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(6); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(6);
        }
        break;
    case 4:
        p->f3D6.f.b0 = 1;
        if (p->f3D7.f.b1) {
            Equip_DamageAmmo_0_001CC5E0();
            if (p->u39C == 0x12) {
                Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(0);
                p->u3D4 = 0;
            } else {
                Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(3);
            }
        }
        break;
    case 5:
        p->f3D6.f.b1 = 1;
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(3);
        break;
    case 6:
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(0);
        break;
    case 7:
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(0);
        break;
    }
}

/* Player_UpdateMagicState_0_001C6250 */
/* Player_UpdateMagicState_0_001C6250 */
inline s8 *get_Player_UpdateMagicState_0_001C6250(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

void Player_UpdateMagicState_0_001C6250(void) {
    S_Player_UpdateMagicState_0_001C6250 *s = (S_Player_UpdateMagicState_0_001C6250 *)get_Player_UpdateMagicState_0_001C6250();
    if (s != NULL) {
        switch (s->m3D5) {
        case 0: break;
        case 1:
            if (s->m3A1.b6) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(2);
            } else if (s->m3D6.b3) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(2);
            } else if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(3);
            }
            break;
        case 2:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        case 3:
            if (Game_GetBusy_0_0012C020()) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(5);
            } else if (s->m3A1.b6) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(5);
            } else if (s->m3D6.b3) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(5);
            }
            break;
        case 4:
            s->m3D6.b0 = 1;
            if (s->m3D7.f1) {
                Equip_DamageAmmo_0_001CC5E0();
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        case 5: break;
        case 6:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        case 7:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        }
    }
}

/* Player_UpdateSwitchState_0_001C6470 */

void Player_UpdateSwitchState_0_001C6470(void) {
    s32 t;
    S_Player_UpdateSwitchState_0_001C6470 *s;
    if (gPlayerSbss_002022E4__as_Player_UpdateSwitchState_0_001C6470 == NULL) {
        s = NULL;
    } else {
        t = M2C_FIELD(gPlayerSbss_002022E4__as_Player_UpdateSwitchState_0_001C6470, s32 *, 0x518);
        if (t == 0) {
            s = NULL;
        } else {
            s = (S_Player_UpdateSwitchState_0_001C6470 *)(t + 0x180);
        }
    }
    if (s != NULL) {
        switch (s->x3D5) {
        case 4:
            if (s->b5) {
                Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(5);
                s->b5 = 0;
                return;
            }
            s->x3CE = s->x3CD;
            s->b0 = 1;
            if (s->c1) {
                Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(0);
            }
            break;
        case 8:
            if (s->c1) {
                Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(0);
            }
            break;
        }
    }
}

/* Player_StartAttackMotion_1_001C6590 */
inline s8 *get_Player_StartAttackMotion_1_001C6590(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}
#define SEL(p) ((*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) ? *(s32 *)(p + 0x3C4) : *(s32 *)(p + 0x3C0))

void Player_StartAttackMotion_1_001C6590(u8 a0) {
    s8 *p;
    u16 base;
    s32 k;
    f32 g;
    f32 f;
    f32 s;
    s8 *q; Flags8 *fl;

    p = get_Player_StartAttackMotion_1_001C6590();
    k = 0;
    g = 0.0f;
    f = g;
    s = 1.0f;
    if (p != NULL) {
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            *(s8 *)(p + 0x3D4) = 0;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 1;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 2);
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            *(s8 *)(p + 0x3D4) = 0;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 3;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 1);
            break;
        case 5:
            *(s8 *)(p + 0x3CF) = 4;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 5;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                if (*(u8 *)(p + 0x39C) == 10) {
                    ItemObj_SetAnim_0_001AD1C0(*(s32 *)(p + 0x3C4), 5);
                } else {
                    ItemObj_SetAnim_0_001AD1C0(*(s32 *)(p + 0x3C4), 4);
                }
            } else {
                ItemObj_SetAnim_0_001AD1C0(*(s32 *)(p + 0x3C0), 4);
            }
            break;
        case 6:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 6;
            *(s8 *)(p + 0x3D4) = 0;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 3);
            break;
        case 7:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            *(s8 *)(p + 0x3D4) = 0;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 8:
            *(s8 *)(p + 0x3CF) = 0;
            f = -1.0f;
            *(s8 *)(p + 0x3CD) = 0;
            *(s8 *)(p + 0x3D5) = 0;
            *(s8 *)(p + 0x3D4) = 0;
            base = 0;
            g = 30.0f;
            s = 2.0f;
            q = *(s8 **)(p + 0x3C0);
            if (q != NULL) { Flags8 *fl = (Flags8 *)(q + 0xA8); if (!fl->f.b5) fl->f.b5 = 1; }
            break;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        Player_SetArmMotion_1_001C7020__as_Player_UpdateArmBones_0_001C5DE0__(f, g, base, k, s);
    }
}

/* Player_StartMagicMotion_0_001C69A0 */
inline s8 *get_Player_StartMagicMotion_0_001C69A0(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}
#define SEL(p) ((*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) ? *(s32 *)(p + 0x3C4) : *(s32 *)(p + 0x3C0))

void Player_StartMagicMotion_0_001C69A0(u8 a0) {
    s8 *p;
    f32 g;
    f32 f;
    f32 s;
    s32 i;
    s32 n;
    u16 base;
    f32 c = 0.01f;
    s32 k;

    p = get_Player_StartMagicMotion_0_001C69A0();
    k = 0;
    f = g = 0.0f;
    s = 1.0f;
    if (p != NULL) {
        i = (s16)Equip_GetSlotItem_1_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1);
        if (i != -1) {
            n = Item_GetMotionId_0_001CC390(i);
        } else {
            n = 0;
        }
        if (n > 3) {
            n += 25;
        }
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 1;
            s -= n * c;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 2);
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 2;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 3);
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 3;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 1);
            break;
        case 5:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 6;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 3);
            break;
        case 6:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            g = 5.0f;
            k = 1;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        }
        if (s < 0.25f) {
            s = 0.25f;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        Player_SetArmMotion_1_001C7020__as_Player_UpdateArmBones_0_001C5DE0__(f, g, base, k, s);
    }
}

/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40 */
inline s8 *get_Player_UpdateArmBones_0_001C5DE0_(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

void Player_StartSwitchMotion_1_001C6D40(u8 a0) {
    s8 *p;
    s32 k;
    f32 f;
    f32 s;
    s32 i;
    s32 n;
    f32 c = 0.01f;
    u16 base;

    p = get_Player_UpdateArmBones_0_001C5DE0_();
    k = 0;
    f = 0.0f;
    s = 1.0f;
    if (p != NULL) {
        i = (s16)Equip_GetSlotItem_1_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1);
        if (i != -1) {
            n = Item_GetMotionId_0_001CC390(i);
        } else {
            n = 0;
        }
        if (n > 3) {
            n += 25;
        }
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            k = 2;
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 2;
            } else {
                *(s8 *)(p + 0x3CD) = 4;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 1;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 4;
            } else {
                *(s8 *)(p + 0x3CD) = 2;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 5:
            *(s8 *)(p + 0x3D5) = 8;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            break;
        }
        if (s < 0.25f) {
            s = 0.25f;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        Player_SetArmMotion_1_001C7020__as_Player_StartSwitchMotion_1_001C6D40(f, base, k, 0.0f, s);
    }
}

/* Player_SetArmMotion_1_001C7020 */
static inline f32 u2f_Player_UpdateArmBones_0_001C5DE0_(u32 x) { return x; }

void Player_SetArmMotion_1_001C7020(u16 idx, f32 t, s32 flags, f32 b, f32 c) {
    H_Player_UpdateArmBones_0_001C5DE0 **h;
    S_Player_StartSwitchMotion_1_001C6D40 *s;
    B_Player_UpdateArmBones_0_001C5DE0__ *q;
    u8 a;
    E *e;
    f32 res;

    if (gPlayerSbss_002022E4 == NULL) {
        s = NULL;
    } else if (gPlayerSbss_002022E4->unk518 == NULL) {
        s = NULL;
    } else {
        s = (S_Player_StartSwitchMotion_1_001C6D40 *)(gPlayerSbss_002022E4->unk518 + 0x180);
    }
    if (s == NULL) {
        return;
    }
    h = s->h;
    if (h == NULL || *h == NULL) {
        return;
    }
    if ((*h)->n <= 0) {
        return;
    }
    e = &s->tbl[idx];
    a = e->a;
    if (a == 0xFF) {
        return;
    }
    q = &e->q;
    Mdl_SetBoneRotation_0_001710D0(s->r, a, c * (0.0078125f * u2f_Player_UpdateArmBones_0_001C5DE0_(e->b)), 0.033333335f * (b + u2f_Player_UpdateArmBones_0_001C5DE0_(q->lo)), 0.033333335f * u2f_Player_UpdateArmBones_0_001C5DE0_(q->mid));
    sceVu0CopyVector__as_Player_UpdateArmBones_0_001C5DE0___(s->x18 + 0xA0, gZeroVec_003139A0__as_Player_UpdateArmBones_0_001C5DE0_____);
    if (flags & 2) {
        s->f3D6.f.b7 = 1;
    } else {
        s->f3D6.f.b7 = 0;
    }
    if (flags & 4) {
        s->f3D7.f.b0 = 1;
    } else {
        s->f3D7.f.b0 = 0;
    }
    res = Mdl_GetMotionLength_0_00173F70__as_Player_UpdateArmBones_0_001C5DE0_____(*h, s->tbl[idx].a);
    if (!(flags & 1)) {
        s->r->c = t;
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    } else {
        s->r->c = res - t;
        if (s->r->c < 0.0f) {
            s->r->c = 0.0f;
        }
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    }
    ((F3 *)&s->f3D7)->f.b1 = 0;
}

/* Player_IsHitTarget_0_001C7320 */
static inline S_Player_IsHitTarget_0_001C7320 *getp(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (S_Player_IsHitTarget_0_001C7320 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}
s32 Player_IsHitTarget_0_001C7320(u16 *a0) {
    S_Player_IsHitTarget_0_001C7320 *p;
    s32 i;
    p = getp();
    if (p == 0) return 0;
    for (i = 0; i < 8; i++) {
        if (p->ids[i] == a0[1]) return 1;
    }
    return 0;
}

/* Player_Nop_2_001C73B0 */
void Player_Nop_2_001C73B0(void) {

}

/* Player_OnHitEnemy_0_001C73C0_ */
/* Player_OnHitEnemy_0_001C73C0 */

/* Player_OnHitEnemy_0_001C73C0 */
/* Player_OnHitEnemy_0_001C73C0 */
static inline f32 u2f_Player_OnHitEnemy_0_001C73C0(u32 x) { return x; }
static inline f32 getf(A_Player_OnHitEnemy_0_001C73C0 *a) { return Enemy_GetMaxHp_2_0013F700(a); }
static inline S_Player_OnHitEnemy_0_001C73C0 *get_Player_OnHitEnemy_0_001C73C0(void) {
    S_Player_OnHitEnemy_0_001C73C0 *r;
    s8 *base;
    if (gPlayerSbss_002022E4__as_Player_OnHitEnemy_0_001C73C0 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(gPlayerSbss_002022E4__as_Player_OnHitEnemy_0_001C73C0 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_OnHitEnemy_0_001C73C0 *)(base + 0x180);
    }
    return r;
}

void Player_OnHitEnemy_0_001C73C0(A_Player_OnHitEnemy_0_001C73C0 *a0, u32 a1, u8 a2, s32 a3) {
    S_Player_OnHitEnemy_0_001C73C0 *s;
    s16 *r;
    s16 *p;
    f32 d;
    u8 b;
    s32 k;
    f32 f;
    s32 i;
    s8 *base;
    T_Player_UpdateArmBones_0_001C5DE0__ **t;

    if (gPlayerSbss_002022E4__as_Player_OnHitEnemy_0_001C73C0 == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(gPlayerSbss_002022E4__as_Player_OnHitEnemy_0_001C73C0 + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S_Player_OnHitEnemy_0_001C73C0 *)(base + 0x180);
    }
    if (s == NULL) return;
    if (s->x39C == 0) {
        r = s->r;
        if ((f32)r[2] / (f32)r[0] > 0.01f) {
            Player_ApplyDamage_2_001C8320__as_Player_UpdateArmBones_0_001C5DE0____((s32)(0.01f * (f32)r[0]), 0, 0, 0);
        }
    }
    if (Player_GetStat_2_001CD450(10, &b, 1, 1)) {
        s->r[2] += (s16)((a1 * b) / 100);
        r = s->r;
        p = &r[2];
        if (r[0] < *p) *p = r[0];
    }
    if (Player_GetStat_2_001CD450(13, &b, 1, 1)) {
        s->r[3] += (s16)((a1 * b) / 100);
        r = s->r;
        p = &r[3];
        if (r[1] < *p) *p = r[1];
    }
    if (ItemType_IsWeapon_0_001D1D50(s->x39C) == 0) {
        if (Enemy_IsDead_1_0013EEE0(a0)) {
            k = 1;
        } else {
            f = 100.0f * u2f_Player_OnHitEnemy_0_001C73C0(a1) / getf(a0);
            if (!(f < 30.0f)) {
                k = 2;
            } else {
                k = 4;
            }
        }
        if (a3) k = 8;
        t = (T_Player_UpdateArmBones_0_001C5DE0__ **)((u8 *)a0 + 0x4B4) + a2;
        Equip_DamageOnHit_0_001CC6F0(k, (*t)->mid);
        Player_PlayHitEnemySe_0_001CA7B0(s->x3CD, (*t)->mid);
    }
    s = get_Player_OnHitEnemy_0_001C73C0();
    if (s == NULL) return;
    for (i = 0; i < 8; i++) {
        if (s->ids[i] == 0xFFFF) {
            s->ids[i] = a0->x2;
            return;
        }
    }
}

/* Player_OnHitObject_0_001C7730 */
void Player_OnHitObject_0_001C7730(A_Player_OnHitObject_0_001C7730 *a, s32 b) {
    s32 r;
    s32 t;
    s32 m;
    S_Player_OnHitObject_0_001C7730 *s;
    if (gPlayerSbss_002022E4__as_Player_OnHitEnemy_0_001C73C0 == NULL) {
        s = NULL;
    } else {
        t = M2C_FIELD(gPlayerSbss_002022E4__as_Player_OnHitEnemy_0_001C73C0, s32 *, 0x518);
        if (t == 0) {
            s = NULL;
        } else {
            s = (S_Player_OnHitObject_0_001C7730 *)(t + 0x180);
        }
    }
    if (s != NULL) {
        s->b5 = 1;
        if (a->x34 != 0) {
            if (MapObj_Hit_0_001B85B0(b, a) != 0) {
                m = 1;
                s->b5 = 0;
            } else {
                m = 8;
            }
            r = MapObj_IsSame_0_001B8F30(a->x30, a->x34);
            Equip_DamageOnHit_0_001CC6F0(m, r);
        } else {
            r = 2;
        }
        if (s->b5) {
            Player_PlayHitObjectSe_0_001CA700(s->x3CD, r);
        }
    }
}

/* Player_TraceAttack_0_001C7850 */

s32 Player_TraceAttack_0_001C7850(s8 *a0, s32 a1) {
    Res res;
    Ray_Player_UpdateArmBones_0_001C5DE0 ray;
    s8 *o;
    s32 j;
    s32 i;
    s8 ***pp;
    s32 **q;

    Coll_ClosestPointB_0_00150160(&ray, a0 + 0x60, a0 + 0x40);
    for (i = 0, pp = (s8 ***)(&gMapSbss_00201E80__as_Player_UpdateArmBones_0_001C5DE0_____ + 2); i < 2; i++, pp++) {
        if (*pp != 0) {
            o = **pp;
            if (o != 0) {
                for (j = 0; j < *(u16 *)(o + 0x6E); j++) {
                    if (MapColl_RayCast_0_001B23E0(o, &res, &ray, j, 2, 1) != 0) {
                        Player_OnHitObject_0_001C7730__as_Player_TraceAttack_0_001C7850(&res, a1);
                    }
                }
            }
        }
    }
    ray = *(Ray_Player_UpdateArmBones_0_001C5DE0 *)(a0 + 0x40);
    for (i = 0, q = (s32 **)(&gMapSbss_00201E80__as_Player_UpdateArmBones_0_001C5DE0_____ + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && MapColl_RayCastAll_0_001B2F30(**q, &res, &ray, 2, 1) != 0) {
            Player_OnHitObject_0_001C7730__as_Player_TraceAttack_0_001C7850(&res, a1);
            return 1;
        }
    }
    return 0;
}

/* Player_InitAttack_0_001C79B0 */
void Player_InitAttack_0_001C79B0(X_Player_UpdateArmBones_0_001C5DE0__ *x) {
    P_Player_DrawWeapon_0_001BCFF0__ *c;
    if (gPlayerSbss_002022E4 == NULL) {
        c = NULL;
    } else {
        s8 *p = gPlayerSbss_002022E4->unk518;
        if (p == NULL) c = NULL;
        else c = (P_Player_DrawWeapon_0_001BCFF0__ *)(p + 0x180);
    }
    if (c != 0) {
        memset(x, 0, 0x40);
        Player_CalcAttack_1_001CEBF0__as_Player_UpdateArmBones_0_001C5DE0_____(x, x->y, c->x3CD);
        x->f30.f = Equip_CheckAmmo_0_001CC250(Equip_GetSlotItem_1_001CCD90(c->x390->x94 & 1));
    }
}

/* Player_GetWeaponSegment_0_001C7A70 */

/* Player_GetWeaponSegment_0_001C7A70 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
inline s8 *get_Player_UpdateArmBones_0_001C5DE0__(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}

s32 Player_GetWeaponSegment_0_001C7A70(M *out) {
    M m;
    f32 a[4];
    f32 b[4];
    s8 *p;
    s8 *q;
    s8 *r;
    f32 *pf;
    f32 x;
    f32 c;
    f32 d;

    p = get_Player_UpdateArmBones_0_001C5DE0__();
    if (p == NULL) {
        return 0;
    }
    if ((s16)Equip_GetSlotItem_1_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) == -1) {
        return 0;
    }
    if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
        q = *(s8 **)(p + 0x3C4);
    } else {
        q = *(s8 **)(p + 0x3C0);
    }
    if (q != NULL && *(s32 *)(q + 0x84) != 0) {
        r = *(s8 **)(q + 0x88);
        if (r != NULL) {
            sceVu0CopyVector__as_Player_GetWeaponSegment_0_001C7A70(a, r);
            sceVu0CopyVector__as_Player_GetWeaponSegment_0_001C7A70(b, r + 0x10);
            Seg_Init_1_001502A0__as_Player_UpdateArmBones_0_001C5DE0_____(a[3], &m, b, a);
            pf = &m.f[7];
            x = *pf;
            p = get_Player_UpdateArmBones_0_001C5DE0__();
            if (p != NULL) {
                c = fabsf(-1.0471976f);
                d = fabsf(WRAP(*(f32 *)(*(s8 **)(p + 0x18) + 0x30)));
                if (!(d <= c)) {
                    d = c;
                }
                x *= 1.0f + d / c;
            }
            *pf = x;
            *out = m;
            return 1;
        }
    }
    return 0;
}

/* Player_ClampPitch_0_001C7CA0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

f32 Player_ClampPitch_0_001C7CA0(f32 a) {
    S_Player_UpdateArmBones_0_001C5DE0 *s;
    f32 lim;
    f32 c;
    if (gPlayerSbss_002022E4 == NULL) {
        s = NULL;
    } else if (gPlayerSbss_002022E4->unk518 == NULL) {
        s = NULL;
    } else {
        s = (S_Player_UpdateArmBones_0_001C5DE0 *)((u8 *)gPlayerSbss_002022E4->unk518 + 0x180);
    }
    if (s) {
        lim = fabsf(-1.0471976f);
        c = fabsf(WRAP(s->x18->x30));
        if (!(c <= lim)) c = lim;
        a *= 1.0f + c / lim;
    }
    return a;
}

/* Player_TakeHit_1_001C7DC0___ */

/* Player_TakeHit_1_001C7DC0__ */

/* Player_TakeHit_1_001C7DC0_ */

/* Player_TakeHit_1_001C7DC0 */
static inline S_Player_TakeHit_1_001C7DC0 *get_Player_TakeHit_1_001C7DC0(void) {
    S_Player_TakeHit_1_001C7DC0 *r;
    s8 *base;
    if (gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_TakeHit_1_001C7DC0 *)(base + 0x180);
    }
    return r;
}
static inline s32 calc_Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *a0, s32 k) {
    S_Player_TakeHit_1_001C7DC0 *s;
    s32 v;
    s16 *r;
    Buf buf;
    s8 *base;
    if (gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S_Player_TakeHit_1_001C7DC0 *)(base + 0x180);
    }
    v = 0;
    if (s == NULL) return v;
    if (k) {
        r = s->r;
        v = r[0] / 100;
        if (v < r[2]) v = r[2] - v;
        return v;
    }
    buf.a[0] = s->st[0] / 5;
    buf.a[1] = s->st[1] / 5;
    buf.a[2] = s->st[2] / 5;
    buf.b[0] = s->st[4] / 5;
    buf.b[1] = s->st[5] / 5;
    buf.b[2] = s->st[6] / 5;
    return Combat_SumResist_0_001AB500__as_Player_TakeHit_1_001C7DC0(a0, &buf);
}

s32 Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *a0) {
    S_Player_TakeHit_1_001C7DC0 *s;
    s32 v;
    s16 *r;
    Buf buf;
    u8 b;
    s32 k;

    if (get_Player_TakeHit_1_001C7DC0() == NULL) return 0;
    if (!a0->b3) {
        k = a0->b2;
        v = calc_Player_TakeHit_1_001C7DC0(a0, k);
        if (!a0->b2 && Player_GetStat_2_001CD450(0x12, &b, 0, 1)) {
            v -= v * b / 100;
            if (v < 0) v = 0;
        }
    } else {
        v = 9999;
    }
    Equip_DamageArmor_0_001CC830(v, a0->x8, 0, a0->lo);
    Player_RollStatusEffect_1_001C8570__as_Player_TakeHit_1_001C7DC0__(a0->x10);
    Player_ApplyDamage_2_001C8320__as_Player_TakeHit_1_001C7DC0_(v, 1, 1, 1);
    return v;
}

/* Player_TakeHitB_1_001C8070 */
static inline S_Player_TakeHitB_1_001C8070 *get_Player_TakeHitB_1_001C8070(void) {
    S_Player_TakeHitB_1_001C8070 *r;
    s8 *base;
    if (gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_TakeHitB_1_001C8070 *)(base + 0x180);
    }
    return r;
}
static inline s32 calc_Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *a0, s32 bit) {
    S_Player_TakeHitB_1_001C8070 *s;
    s32 n;
    u16 buf[8];
    R_Player_TakeHit_1_001C7DC0_ *r;
    s8 *base;
    if (gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S_Player_TakeHitB_1_001C8070 *)(base + 0x180);
    }
    n = 0;
    if (s == NULL) return n;
    if (bit) {
        r = s->x390;
        n = r->x0 / 100;
        if (n < r->x4) n = r->x4 - n;
        return n;
    }
    buf[1] = s->x462 / 5;
    buf[2] = s->x464 / 5;
    buf[3] = s->x466 / 5;
    buf[5] = s->x46A / 5;
    buf[6] = s->x46C / 5;
    buf[7] = s->x46E / 5;
    n = Combat_SumResist_0_001AB500__as_Player_TakeHitB_1_001C8070(a0, buf);
    return n;
}

s32 Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *a0, A *a1) {
    s32 n;
    u8 k;

    if (get_Player_TakeHitB_1_001C8070() == NULL) return 1;
    if (a1 == NULL) return 1;
    n = calc_Player_TakeHitB_1_001C8070(a0, a0->v);
    if (!a0->v && Player_GetStat_2_001CD450(0x11, &k, 0, 1)) {
        n -= n * k / 100;
        if (n < 0) n = 0;
    }
    Equip_DamageArmor_0_001CC830__as_Player_TakeHitB_1_001C8070(n, a0->x8, a1->x4B0->v, a0->p30);
    Player_RollStatusEffect_1_001C8570__as_Player_TakeHitB_1_001C8070(a0->x10);
    Player_ApplyDamage_2_001C8320__as_Player_TakeHit_1_001C7DC0_(n, 1, 1, 1);
    return 1;
}

/* Player_ApplyDamage_2_001C8320 */
static inline S_Player_TakeHit_1_001C7DC0_ *get_Player_TakeHit_1_001C7DC0_(void) {
    S_Player_TakeHit_1_001C7DC0_ *r;
    s8 *base;
    if (gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_TakeHit_1_001C7DC0_ *)(base + 0x180);
    }
    return r;
}

s32 Player_ApplyDamage_2_001C8320(s32 n, s32 a1, s32 a2, s32 a3) {
    S_Player_TakeHit_1_001C7DC0_ *s;
    S_Player_TakeHit_1_001C7DC0_ *t;

    s = get_Player_TakeHit_1_001C7DC0_();
    if (s == NULL) return 0;
    if (s->x390->x4 <= 0) return 0;
    if (Game_GetBusy_0_0012C020()) return 0;
    Player_AddExp_0_001CEAA0(-n);
    s->b6 = 1;
    s->x410 = n;
    if (a1) s->x3BE = 15;
    if (a2) {
        Vibe_StartB_0_0015FE20(1.0f, n / 100.0f, 0.0f, 1.0f, 16.0f);
        Vibe_StartA_0_0015FD90(1.0f, n / 10.0f, 0.0f, 1.0f, 16.0f);
    }
    if (a3) Player_PlayHurtSe_0_001CA2B0(n);
    if (n * 100 / s->x390->x0 >= 30) {
        t = get_Player_TakeHit_1_001C7DC0_();
        if (t != NULL) {
            t->x438 = 10.0f;
            t->x43C = 30.0f;
            t->x440 = 0.9f;
            t->x444 = 10.0f;
            t->x434 = 0.0f;
            t->x430 = 0.0f;
        }
    }
    s->x39E.c.b4 = 0;
    s->x39E.h.b = 0;
    return s->x390->x4;
}

/* Player_RollStatusEffect_1_001C8570 */
/* Player_RollStatusEffect_1_001C8570 */
s32 Player_RollStatusEffect_1_001C8570(u32 *arg0) {
    S_Player_RollStatusEffect_1_001C8570 *s6;
    s32 ret;
    R_Player_RollStatusEffect_1_001C8570 *r;
    u32 *pa;
    u32 *pb;
    s32 i;
    u32 lvl;
    f32 f;
    f32 g;
    s8 *base;

    if (gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___ == NULL) {
        s6 = NULL;
    } else if ((base = M2C_FIELD(gPlayerSbss_002022E4__as_Player_TakeHit_1_001C7DC0___, s8 **, 0x518)) == NULL) {
        s6 = NULL;
    } else {
        s6 = (S_Player_RollStatusEffect_1_001C8570 *)(base + 0x180);
    }
    ret = 0;
    if (s6 == NULL) return 0;
    if (((u64)((s64)D_00222A53__as_Player_UpdateArmBones_0_001C5DE0_____[0] << 0x38) >> 0x3F) != 0) return 0;
    if (Player_GetStat_2_001CD450(7, NULL, 0, 1) != 0) return 0;
    r = s6->r;
    pa = r->a;
    pb = r->b;
    for (i = 0; i <= 5; i++) {
        if (arg0[i] != 0 && pb[i] == 0) {
            g = (1.0f - 0.01f * (f32)s6->c[i]) * ((1.0f - 0.0005f * (f32)(u32)s6->x) * (f32)arg0[i]);
            if (100.0f * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20(arg0[i])) <= g) {
                lvl = pa[i] >> 24;
                if (lvl < 2) {
                    f = (1.0f - 0.0005f * (f32)(u32)s6->y) * (f32)gPlayerData_001F3880[lvl][i];
                    pa[i] = (u32)f | ((lvl + 1) << 24);
                    ret = 1;
                }
            }
        }
    }
    return ret;
}

/* Player_AddStatus_1_001C88E0 */

void Player_AddStatus_1_001C88E0(s32 a, u32 b) {
    G *g;
    u32 v;
    g = gPlayerSdata_00201E20;
    if (a < 0 || a > 5) return;
    if (b == 1 || b == 2) {
        if (!D_00222A53__as_Player_AddStatus_1_001C88E0[0].f.b7 && !Player_GetStat_2_001CD450__as_Player_AddStatus_1_001C88E0(7, 0, 0, 1) && !Equip_FindSlot_0_001CD2D0(a)) {
            v = g->x30[a] >> 24;
            if (v < 2 && v < b) {
                v = gPlayerData_001F3860[b][a];
                g->x30[a] = v | (b << 24);
                g->x50[a] = 0;
            }
        }
    }
}
#undef sceVu0SubVector
#undef Camera_LookAt_0_001C89E0
#undef E80
#undef Actor

/* Camera_LookAt_0_001C89E0_ */
#define sceVu0SubVector sceVu0SubVector__as_Camera_LookAt_0_001C89E0_
void sceVu0SubVector__as_Camera_LookAt_0_001C89E0_(Vec*, void *, Vec*);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Camera_LookAt_0_001C89E0_
void sceVu0CopyMatrix__as_Camera_LookAt_0_001C89E0_(MtxF *, MtxF *);
#define sceVu0RotMatrixX sceVu0RotMatrixX__as_Camera_LookAt_0_001C89E0_
void sceVu0RotMatrixX__as_Camera_LookAt_0_001C89E0_(MtxF *, MtxF *, f32);
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_Camera_LookAt_0_001C89E0_
void sceVu0RotMatrixY__as_Camera_LookAt_0_001C89E0_(MtxF *, MtxF *, f32);
#define sceVu0ScaleVector sceVu0ScaleVector__as_Camera_LookAt_0_001C89E0_
void sceVu0ScaleVector__as_Camera_LookAt_0_001C89E0_(Vec *, Vec *, f32);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Camera_LookAt_0_001C89E0_
void sceVu0ApplyMatrix__as_Camera_LookAt_0_001C89E0_(Vec *, MtxF *, Vec *);
#define sceVu0AddVector sceVu0AddVector__as_Camera_LookAt_0_001C89E0_
void sceVu0AddVector__as_Camera_LookAt_0_001C89E0_(Vec *, Vec *, Vec *);

/* Camera_LookAt_0_001C89E0 */
#define WRAPV(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + *(volatile f32 *)&(x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
inline s8 *get_Camera_LookAt_0_001C89E0(void) {
    if (gPlayerSbss_002022E4 == NULL) {
        return NULL;
    }
    if (gPlayerSbss_002022E4->unk518 == NULL) {
        return NULL;
    }
    return gPlayerSbss_002022E4->unk518 + 0x180;
}
#define RR (*(R **)(p + 0x18))

void Camera_LookAt_0_001C89E0(Vec *dir, f32 t) {
    Vec v;
    s8 *p;
    s8 *q;
    f32 w;
    f32 d;
    f32 y;
    f32 *a;

    p = get_Camera_LookAt_0_001C89E0();
    if (p == NULL) return;
    q = get_Camera_LookAt_0_001C89E0();
    if (q != NULL) {
        sceVu0CopyVector__as_Camera_LookAt_0_001C89E0(&v, q + 0x40);
    }
    sceVu0SubVector__as_Camera_LookAt_0_001C89E0(&v, dir, &v);
    w = Vec_YawAngle_2_0013FC10(&v);
    w = WRAP(w);
    RR->x24 = WRAP(RR->x24);
    d = RR->x24 - w;
    if (d > 3.1415927f) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    RR->x24 = w + d * t;
    RR->x24 = WRAP(RR->x24);
    y = v.y;
    v.y = 0.0f;
    w = -atan2f(y, sqrtf(sceVu0InnerProduct(&v, &v)));
    w = WRAP(w);
    RR->x20 = WRAP(RR->x20);
    d = RR->x20 - w;
    if (d > 3.1415927f) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    RR->x20 = w + d * t;
    RR->x20 = WRAP(RR->x20);
    ((Bits *)(p + 0x3A2))->b1 = 0;
}
#undef RR

/* Camera_SetPosition_0_001C8EA0 */

void Camera_SetPosition_0_001C8EA0(f32 *v, f32 f)
{
    T_Camera_SetPosition_0_001C8EA0 *t;
    if (gPlayerSbss_002022E4__as_Camera_SetPosition_0_001C8EA0 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Camera_SetPosition_0_001C8EA0->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Camera_SetPosition_0_001C8EA0 *)(p + 0x180);
    }
    if (t != NULL) {
        sceVu0CopyVector__as_Camera_SetPosition_0_001C8EA0(t->v, v);
        t->f = f;
        t->b = 1;
    }
}

/* Camera_SetParams_0_001C8F30 */

void Camera_SetParams_0_001C8F30(f32 x, f32 y, f32 z, f32 w)
{
    T_Camera_SetParams_0_001C8F30 *t;
    if (gPlayerSbss_002022E4__as_Camera_SetParams_0_001C8F30 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Camera_SetParams_0_001C8F30->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Camera_SetParams_0_001C8F30 *)(p + 0x180);
    }
    if (t != NULL) {
        t->v[0] = x;
        t->v[1] = y;
        t->v[2] = z;
        t->v[3] = w;
        t->b = 0;
        t->a = 0;
    }
}

/* Camera_Update_1_001C8F90 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline P_Camera_LookAt_0_001C89E0 *cur(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (P_Camera_LookAt_0_001C89E0 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

void Camera_Update_1_001C8F90(void *a0) {
    P_Camera_LookAt_0_001C89E0 *p;
    MtxF m;
    Vec v;
    Vec t;


    p = cur();
    if (p == 0) return;
    sceVu0CopyMatrix(&m, &gMatrixFromData_001F2170);
    sceVu0RotMatrixX(&m, &m, p->f3A4 + WRAP(*(f32 *)(p->o + 0x30)));
    sceVu0RotMatrixZ(&m, &m, WRAP(*(f32 *)(p->o + 0x38)));
    sceVu0RotMatrixY(&m, &m, WRAP(3.1415927f + *(f32 *)(p->o + 0x34)));
    sceVu0ScaleVector(&v, &gMatrixFromData_001F2140, p->f370);
    sceVu0SubVector__as_Camera_Update_1_001C8F90(&v, p->o, &v);
    if (p->b5) {
        v.y += 4.0f * p->f454;
    } else {
        v.y += 2.0f * p->f454;
    }
    t.x = p->f430;
    t.y = p->f434;
    t.w = 1.0f;
    t.z = 0.0f;
    sceVu0ApplyMatrix(&t, &m, &t);
    sceVu0AddVector(&v, &v, &t);
    sceVu0CameraMatrix(a0, &v, (Vec *)m.m[2], (Vec *)m.m[1]);
    if (ItemType_IsMagic_0_001D1E00(p->b39C)) {
        D_00222A40[0] = 75.0f * (1.0f - -0.6f * (p->f3D0 / -0.17453294f));
    } else {
        D_00222A40[0] = 75.0f;
    }
}
#undef sceVu0SubVector
#undef sceVu0CopyMatrix
#undef sceVu0RotMatrixX
#undef sceVu0RotMatrixY
#undef sceVu0ScaleVector
#undef sceVu0ApplyMatrix
#undef sceVu0AddVector
#undef RR

/* Player_Warp_0_001C92C0__ */
#define Inventory_Give_0_001CBCD0 Inventory_Give_0_001CBCD0__as_Player_Warp_0_001C92C0__
int Inventory_Give_0_001CBCD0__as_Player_Warp_0_001C92C0__();
#define Player_RecalcStats_1_001CEDC0 Player_RecalcStats_1_001CEDC0__as_Player_Warp_0_001C92C0__
int Player_RecalcStats_1_001CEDC0__as_Player_Warp_0_001C92C0__();
#define gZeroVec_003139A0 gZeroVec_003139A0__as_Player_Warp_0_001C92C0__
extern s8 gZeroVec_003139A0__as_Player_Warp_0_001C92C0__[];
#define gPlayerSdata_00201E20 gPlayerSdata_00201E20__as_Player_Warp_0_001C92C0__
extern S1E20 *gPlayerSdata_00201E20__as_Player_Warp_0_001C92C0__;
#define gPlayerSbss_002022BC gPlayerSbss_002022BC__as_Player_Warp_0_001C92C0__
extern P_Player_UpdateFrame_0_001C9830 **gPlayerSbss_002022BC__as_Player_Warp_0_001C92C0__;
#define gPlayerBss_004B4C40 gPlayerBss_004B4C40__as_Player_Warp_0_001C92C0__
extern s32 gPlayerBss_004B4C40__as_Player_Warp_0_001C92C0__[];
#define gPlayerBss_004B4CE0 gPlayerBss_004B4CE0__as_Player_Warp_0_001C92C0__
extern f32 gPlayerBss_004B4CE0__as_Player_Warp_0_001C92C0__[4];
#define sceVu0CopyVector sceVu0CopyVector__as_Player_Warp_0_001C92C0__
void sceVu0CopyVector__as_Player_Warp_0_001C92C0__(s32, s32);
#define memset memset__as_Player_Warp_0_001C92C0__
M2C_UNK memset__as_Player_Warp_0_001C92C0__(M2C_UNK *, M2C_UNK, M2C_UNK);
#define PlayerProc_Animate_0_001C5750 PlayerProc_Animate_0_001C5750__as_Player_Warp_0_001C92C0__
void PlayerProc_Animate_0_001C5750__as_Player_Warp_0_001C92C0__(void);
#define PlayerProc_Collide_0_001C5150 PlayerProc_Collide_0_001C5150__as_Player_Warp_0_001C92C0__
void PlayerProc_Collide_0_001C5150__as_Player_Warp_0_001C92C0__(void);
#define PlayerProc_Update_0_001BEFA0 PlayerProc_Update_0_001BEFA0__as_Player_Warp_0_001C92C0__
void PlayerProc_Update_0_001BEFA0__as_Player_Warp_0_001C92C0__(void);
#define PlayerProc_UpdateMove_0_001BE7B0 PlayerProc_UpdateMove_0_001BE7B0__as_Player_Warp_0_001C92C0__
void PlayerProc_UpdateMove_0_001BE7B0__as_Player_Warp_0_001C92C0__(void);
#define PlayerProc_Attack_0_001C55A0 PlayerProc_Attack_0_001C55A0__as_Player_Warp_0_001C92C0__
void PlayerProc_Attack_0_001C55A0__as_Player_Warp_0_001C92C0__(void);

/* Player_Warp_0_001C92C0__ */
/* Player_Warp_0_001C92C0_ */

/* Player_Warp_0_001C92C0_ */
/* Player_Warp_0_001C92C0 */

void Player_Warp_0_001C92C0(s32 arg0) {
    s32 temp_3;
    s32 var_3;

    if (gPlayerSbss_002022E4__as_Player_Warp_0_001C92C0 == NULL) {
        var_3 = 0;
    } else {
        temp_3 = M2C_FIELD(gPlayerSbss_002022E4__as_Player_Warp_0_001C92C0, s32 *, 0x518);
        if (temp_3 == 0) {
            var_3 = 0;
        } else {
            var_3 = temp_3 + 0x180;
        }
    }
    if (var_3 != 0) {
        sceVu0CopyVector(var_3 + 0x3F0, arg0);
    }
}

/* Player_SetPosition_0_001C9320 */

void Player_SetPosition_0_001C9320(u8 *arg0) {
    u8 *var_3;
    s32 temp_3;

    if (gPlayerSbss_002022E4__as_Player_SetPosition_0_001C9320 == NULL) {
        var_3 = (u8 *) (NULL);
    } else {
        temp_3 = M2C_FIELD(gPlayerSbss_002022E4__as_Player_SetPosition_0_001C9320, s32 *, 0x518);
        if (temp_3 == 0) {
            var_3 = (u8 *) (NULL);
        } else {
            var_3 = (u8 *) (temp_3 + 0x180);
        }
    }
    if (var_3 != NULL) {
        sceVu0CopyVector__as_Player_SetPosition_0_001C9320(arg0, M2C_FIELD(var_3, s32 *, 0x18) + 0x10);
    }
    M2C_FIELD(arg0, f32 *, 4) += 220.0f;
}

/* Player_GetHeadPos_0_001C93A0 */

void Player_GetHeadPos_0_001C93A0(f32 *out)
{
    T_Player_GetHeadPos_0_001C93A0 *t;
    if (gPlayerSbss_002022E4__as_Player_GetHeadPos_0_001C93A0 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_GetHeadPos_0_001C93A0->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Player_GetHeadPos_0_001C93A0 *)(p + 0x180);
    }
    if (t != NULL)
        sceVu0CopyVector__as_Player_GetHeadPos_0_001C93A0(out, t->v->v);
}

/* Player_GetPos_1_001C9410 */

void Player_GetPos_1_001C9410(f32 *v)
{
    u8 *t;
    if (gPlayerSbss_002022E4__as_Player_GetPos_1_001C9410 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_GetPos_1_001C9410->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t != NULL)
        sceVu0CopyVector__as_Player_GetPos_1_001C9410(v, (f32 *)(t + 0x40));
    v[1] += 220.0f;
}

/* Player_GetPosB_0_001C9490 */

void Player_GetPosB_0_001C9490(f32 *v)
{
    u8 *t;
    if (gPlayerSbss_002022E4__as_Player_GetPosB_0_001C9490 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_GetPosB_0_001C9490->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t != NULL)
        sceVu0CopyVector__as_Player_GetPosB_0_001C9490(v, (f32 *)(t + 0x40));
}

/* Player_SetPosAndGround_0_001C94F0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline P_Player_SetPosAndGround_0_001C94F0 *cur_Player_SetPosAndGround_0_001C94F0(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (P_Player_SetPosAndGround_0_001C94F0 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

void Player_SetPosAndGround_0_001C94F0(f32 *a0) {
    P_Player_SetPosAndGround_0_001C94F0 *p;
    Vec v;
    p = cur_Player_SetPosAndGround_0_001C94F0();
    if (p == 0) return;
    v.x = 0.0f;
    v.y = WRAP(a0[3]);
    v.z = v.w = 0.0f;
    sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0(p->o, a0);
    sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0(p->o + 0x10, a0);
    sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0(p->o + 0x20, &v);
    sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0(p->o + 0x30, &v);
    sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0(p->o + 0x40, gZeroVec_003139A0);
}

/* Player_SetStartPos_0_001C9630 */
void Player_SetStartPos_0_001C9630(f32 *a, f32 *b)
{
    T_Player_SetStartPos_0_001C9630 *t;
    if (gPlayerSbss_002022E4__as_Player_SetStartPos_0_001C9630 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_SetStartPos_0_001C9630->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Player_SetStartPos_0_001C9630 *)(p + 0x180);
    }
    if (t != NULL) {
        sceVu0CopyVector__as_Player_SetStartPos_0_001C9630(t->m, a);
        sceVu0CopyVector__as_Player_SetStartPos_0_001C9630(t->m + 4, a);
        sceVu0CopyVector__as_Player_SetStartPos_0_001C9630(t->m + 8, b);
        sceVu0CopyVector__as_Player_SetStartPos_0_001C9630(t->m + 12, b);
        sceVu0CopyVector__as_Player_SetStartPos_0_001C9630(t->m + 16, gZeroVec_003139A0__as_Player_SetStartPos_0_001C9630);
    }
}

/* Player_LoadStartPos_0_001C96F0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline S_Player_LoadStartPos_0_001C96F0 *cur_Player_LoadStartPos_0_001C96F0(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (S_Player_LoadStartPos_0_001C96F0 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

void Player_LoadStartPos_0_001C96F0(s8 *a0) {
    Vec *r;
    S_Player_LoadStartPos_0_001C96F0 *s;
    Vec v;
    if (a0 != NULL) {
        r = *(Vec **)(a0 + 0x158);
        s = cur_Player_LoadStartPos_0_001C96F0();
        if (s != NULL) {
            v.x = 0.0f;
            v.y = WRAP(r->w);
            v.w = 0.0f;
            v.z = 0.0f;
            sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0(&s->m[0], r);
            sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0(&s->m[1], r);
            sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0(&s->m[2], &v);
            sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0(&s->m[3], &v);
            sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0(&s->m[4], &gZeroVec_003139A0__as_Player_LoadStartPos_0_001C96F0);
        }
    }
}

/* Player_UpdateFrame_0_001C9830 */

void Player_UpdateFrame_0_001C9830(void) {
    s8 *v;
    if (gPlayerSbss_002022E4__as_Player_UpdateFrame_0_001C9830 == NULL) {
        v = NULL;
    } else if (M2C_FIELD(gPlayerSbss_002022E4__as_Player_UpdateFrame_0_001C9830, s32 *, 0x518) == 0) {
        v = NULL;
    } else {
        v = (s8 *)(M2C_FIELD(gPlayerSbss_002022E4__as_Player_UpdateFrame_0_001C9830, s32 *, 0x518) + 0x180);
    }
    if (v != NULL) {
        gPlayerSdata_00201E20->b = gSoundSbss_002022B8;
        if (gPlayerSbss_002022BC != NULL && *gPlayerSbss_002022BC != NULL) {
            gPlayerSdata_00201E20->h[0] = (s32)(M2C_FIELD(v, f32 *, 0x40) - (*gPlayerSbss_002022BC)->x);
            gPlayerSdata_00201E20->h[1] = (s32)(M2C_FIELD(v, f32 *, 0x44) - (*gPlayerSbss_002022BC)->y);
            gPlayerSdata_00201E20->h[2] = (s32)(M2C_FIELD(v, f32 *, 0x48) - (*gPlayerSbss_002022BC)->z);
        } else {
            gPlayerSdata_00201E20->h[0] = (s32)M2C_FIELD(v, f32 *, 0x40);
            gPlayerSdata_00201E20->h[1] = (s32)M2C_FIELD(v, f32 *, 0x44);
            gPlayerSdata_00201E20->h[2] = (s32)M2C_FIELD(v, f32 *, 0x48);
        }
        gPlayerSdata_00201E20->h[3] = (s32)(4096.0f * M2C_FIELD(M2C_FIELD(v, s8 * *, 0x18), f32 *, 0x20));
        gPlayerSdata_00201E20->h[4] = (s32)(4096.0f * M2C_FIELD(M2C_FIELD(v, s8 * *, 0x18), f32 *, 0x24));
    }
}

/* Player_IsBusy_0_001C99A0 */
s32 Player_IsBusy_0_001C99A0(void) {
    return Game_GetBusy_0_0012C020() != 0;
}

/* Player_GetHpS16_0_001C99C0 */

s16 Player_GetHpS16_0_001C99C0(void)
{
    u8 *t;
    if (gPlayerSbss_002022E4__as_Player_GetHpS16_0_001C99C0 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_GetHpS16_0_001C99C0->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return (*(U_Player_Warp_0_001C92C0 **)(t + 0x390))->h;
}

/* Player_IsCrouching_0_001C9A20 */

u8 Player_IsCrouching_0_001C9A20(void)
{
    u8 *t;
    if (gPlayerSbss_002022E4__as_Player_IsCrouching_0_001C9A20 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_IsCrouching_0_001C9A20->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return t[0x3D6] & 1;
}

/* Player_IsMoving_0_001C9A80 */

u32 Player_IsMoving_0_001C9A80(void)
{
    u8 *t;
    if (gPlayerSbss_002022E4__as_Player_IsMoving_0_001C9A80 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_IsMoving_0_001C9A80->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return ((B_Player_IsMoving_0_001C9A80 *)(t + 0x3A2))->f;
}

/* Player_IsActionLocked_0_001C9AE0 */

u32 Player_IsActionLocked_0_001C9AE0(void)
{
    u8 *t;
    if (gPlayerSbss_002022E4__as_Player_IsActionLocked_0_001C9AE0 == NULL) {
        t = NULL;
    } else {
        u8 *p = gPlayerSbss_002022E4__as_Player_IsActionLocked_0_001C9AE0->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return ((B_Player_IsActionLocked_0_001C9AE0 *)(t + 0x39C))->f;
}

/* Player_GetCameraData_0_001C9B40 */
s32 *Player_GetCameraData_0_001C9B40(void) {
    return gPlayerBss_004B4C40;
}

/* Player_GetCameraMode_0_001C9B50 */
s32 Player_GetCameraMode_0_001C9B50(void) {
    return gPlayerSbss_002022D8;
}

/* Player_GetBodyState_1_001C9B60 */

s32 Player_GetBodyState_1_001C9B60(void) {
    s32 temp_2;

    if (gPlayerSbss_002022E4__as_Player_GetBodyState_1_001C9B60 == NULL) {
        return 0;
    }
    temp_2 = M2C_FIELD(gPlayerSbss_002022E4__as_Player_GetBodyState_1_001C9B60, s32 *, 0x518);
    if (temp_2 == 0) {
        return 0;
    }
    return temp_2 + 0x180;
}

/* PlayerData_Get_2_001C9BA0 */

/* PlayerData_Get_2_001C9BA0 */
s32 PlayerData_Get_2_001C9BA0(void) {
    return gPlayerSdata_00201E20__as_PlayerData_Get_2_001C9BA0;
}

/* PlayerData_Load_1_001C9BB0 */
void PlayerData_Load_1_001C9BB0(s32 arg0) {
    memcpy(gPlayerSdata_00201E20__as_PlayerData_Get_2_001C9BA0, arg0, 0x10A0);
    Player_RecalcStats_1_001CEDC0(3);
    Player_RefreshEquipModel_0_001CEA50__as_Player_Warp_0_001C92C0_(0);
}

/* Player_Exists_3_001C9BF0 */

/* Player_Exists_3_001C9BF0 */
s32 Player_Exists_3_001C9BF0(void) {
    return gPlayerSbss_002022E4__as_Player_Exists_3_001C9BF0 != 0;
}

/* Player_CopyLightPos_0_001C9C00 */
u8 Player_CopyLightPos_0_001C9C00(f32 *v)
{
    if (v)
        sceVu0CopyVector__as_Player_Exists_3_001C9BF0(v, gPlayerBss_004B4CE0);
    return gPlayerSdata_00201E24;
}

/* Player_Destroy_1_001C9C30 */

void Player_Destroy_1_001C9C30(void) {
    s8 *temp_s0;

    if (gPlayerSbss_002022E4__as_Player_Destroy_1_001C9C30 != NULL) {
        temp_s0 = (signed char *)(M2C_FIELD(gPlayerSbss_002022E4__as_Player_Destroy_1_001C9C30, s32 *, 0x518) + 0x180);
        memset(gHudMarkerBss_004B4BE0, 0, 0x58);
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x448));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x44C));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x3B0));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x3B4));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x450));
        Pool_Free_2_00128580(gEnemyListSbss_00202278, M2C_FIELD(temp_s0, s32 *, 0x3A8));
        Enemy_Destroy_0_001A6A10(ActorList_FromHandle_1_001A5970(gPlayerSbss_002022E4__as_Player_Destroy_1_001C9C30));
        gPlayerSbss_002022E4__as_Player_Destroy_1_001C9C30 = NULL;
    }
    Player_ReleaseHeldItem_0_001CAE90();
}

/* Player_LoadModel_1_001C9CD0 */

void Player_LoadModel_1_001C9CD0(s8 *a) {
    s8 *o;
    s32 tmp;
    o = *(s8 **)(a + 0x518) + 0x180;
    gPlayerSbss_002022E4__as_Player_LoadModel_1_001C9CD0 = a;
    Enemy_UpdateModelMatrix_0_001A7E60();
    *(void **)(a + 0x538) = PlayerProc_Animate_0_001C5750;
    *(void **)(a + 0x53C) = PlayerProc_Collide_0_001C5150;
    *(void **)(a + 0x540) = PlayerProc_Update_0_001BEFA0;
    *(void **)(a + 0x544) = PlayerProc_UpdateMove_0_001BE7B0;
    *(void **)(a + 0x548) = PlayerProc_Attack_0_001C55A0;
    *(s16 *)(a + 0x4AE) = -1;
    *(s32 *)(*(s8 **)(o + 0x18) + 0x4F0) = 0;
    *(s32 *)(*(s8 **)(o + 0x18) + 0x510) = gPlayerSdata_00201E20__as_Player_Exists_3_001C9BF0;
    *(s16 *)(*(s8 **)(o + 0x18) + 0x538) = -1;
    *(s16 *)(*(s8 **)(o + 0x18) + 0x53A) = -1;
    *(u8 *)(o + 0x39C) = 0;
    Arc_LoadFile_2_00159DD0(0x374169A, gEnemyListSbss_00202278, o + 0x3A8, &tmp);
    *(s32 *)(o + 0x3B0) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gStrRifle01_001FDC08), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x3B4) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gStrJyo_001FDC10), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x448) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gStrDm09_001FDC18), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x44C) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gStrDm10_001FDC20), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x450) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(gStrTen_001FDC28), *(s32 *)(o + 0x3A8));
    memset__as_Player_LoadModel_1_001C9CD0(gHudMarkerBss_004B4BE0__as_Player_LoadModel_1_001C9CD0, 0, 0x58);
}

/* Player_Respawn_1_001C9E30 */

void Player_Respawn_1_001C9E30(void) {
    void **temp_3;
    void *temp_5;

    Enemy_Respawn_1_001A6C90(gPlayerSbss_002022E4__as_Player_Respawn_1_001C9E30);
    temp_3 = M2C_FIELD(M2C_FIELD(gPlayerSbss_002022E4__as_Player_Respawn_1_001C9E30, void **, 0x518), void ***, 0xB0);
    if ((temp_3 != NULL) || (*temp_3 != NULL)) {
        temp_5 = *temp_3;
        ((BF_25_1_1 *)temp_5)->f = 1;
    }
    Player_RecalcStats_1_001CEDC0(3);
    Player_RefreshEquipModel_0_001CEA50(1);
}

/* PlayerData_InitNew_0_001C9EA0 */

void PlayerData_InitNew_0_001C9EA0(void) {
    s32 var_3;
    s32 var_2;

    memset__as_PlayerData_InitNew_0_001C9EA0(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, 0, 0x10A0);
    var_3 = 0;
    var_2 = 0;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x20) = 0xF;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x22) = 0xC;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x24) = 0xC;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x26) = 0xA;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x28) = 0xC;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x2A) = 8;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x2C) = 8;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 0x2E) = 8;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 4) = 0x270F;
    M2C_FIELD(gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0, s16 *, 6) = 0x270F;
    do {
        var_3 += 5;
        M2C_FIELD((gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0 + var_2), s16 *, 0x80) = -1;
        M2C_FIELD((gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0 + var_2), s16 *, 0x82) = -1;
        M2C_FIELD((gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0 + var_2), s16 *, 0x84) = -1;
        M2C_FIELD((gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0 + var_2), s16 *, 0x86) = -1;
        M2C_FIELD((gPlayerSdata_00201E20__as_PlayerData_InitNew_0_001C9EA0 + var_2), s16 *, 0x88) = -1;
        var_2 += 0xA;
    } while (var_3 < 0xA);
    Inventory_ChangeCount_1_001CBED0(0x14, 4, 0);
    Inventory_Give_0_001CBCD0(0x3B6);
    Equip_SetSlot_0_001CCF00(0, 0x3B6);
}
#undef sceVu0CopyVector
#undef memset
#undef PlayerProc_Animate_0_001C5750
#undef PlayerProc_Collide_0_001C5150
#undef PlayerProc_Update_0_001BEFA0
#undef PlayerProc_UpdateMove_0_001BE7B0
#undef PlayerProc_Attack_0_001C55A0
#undef gZeroVec_003139A0
#undef gPlayerSdata_00201E20
#undef gPlayerSbss_002022BC
#undef gPlayerBss_004B4C40
#undef gPlayerBss_004B4CE0
#undef Inventory_Give_0_001CBCD0
#undef Player_RecalcStats_1_001CEDC0

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 gPlayerBss_004B4D10[];
/* data twins (src/game/data/sdata.c): gPlayerSdata_00201E20 */
G *gPlayerSdata_00201E20 = (G *)gPlayerBss_004B4D10;
/* data twins (src/game/data/sbss.c): gPlayerSbss_002022BC, gPlayerSbss_002022E4 */
M_Player_UpdateArea_0_001BD4E0 **gPlayerSbss_002022BC;
Actor *gPlayerSbss_002022E4;
/* data twins (src/game/data/vibration_bss.c): gPlayerBss_0031723C, gPlayerBss_00317244, gPlayerBss_00317248, gPlayerBss_00317254, gPlayerBss_00317274 */
f32 gPlayerBss_0031723C[0x1];
f32 gPlayerBss_00317244[0x1];
f32 gPlayerBss_00317248[0x1];
f32 gPlayerBss_00317254[0x6] __attribute__((aligned(4)));
f32 gPlayerBss_00317274[0x1b] __attribute__((aligned(4)));
/* data group (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4C40__grp: gPlayerBss_004B4C40@0x0 */
u8 D_004B4C40__grp[0x10] __attribute__((aligned(16)));
/* data group (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4CD0__grp: gPlayerBss_004B4CD0@0x0, gPlayerBss_004B4CDC@0xc */
unsigned char gPlayerBss_004B4CD0__grp[0x10] __attribute__((aligned(16)));
/* data group (src/game/data/pad_get_connected_bss_004B4BB0.c): gPlayerBss_004B4CE0__grp: gPlayerBss_004B4CE0@0x0, gPlayerBss_004B4CEC@0xc, gPlayerBss_004B4CF0@0x10, gPlayerBss_004B4D00@0x20, gPlayerBss_004B4D04@0x24, gPlayerBss_004B4D08@0x28, gPlayerBss_004B4D0C@0x2c, gPlayerBss_004B4D10@0x30 */
unsigned char gPlayerBss_004B4CE0__grp[0x10d0] __attribute__((aligned(16)));
/* data group (src/game/data/player_data.c): gPlayerData_001F3860__grp: gPlayerData_001F3860@0x0, gPlayerData_001F3870@0x10, gPlayerData_001F3880@0x20 */
int gPlayerData_001F3860__grp[0x18] __attribute__((aligned(16))) = { 0x447a0000, 0x466a6000, 0, 0x3f800000, 0x3f800000, 0x3dcccccd, 0, 0, 0x708, 0x96, 0xe10, 0x708, 0xa8c, 0x708, 0, 0, 0xa8c, 0x1c2, 0x1518, 0xa8c, 0xe10, 0xa8c, 0, 0 };
/* data group (src/game/data/player_rodata.c): pad_001FDC2D__grp: pad_001FDC2D@0x0 */
unsigned char pad_001FDC2D__grp[0x3] __attribute__((aligned(1))) = { 0, 0, 0 };
/* data group (src/game/data/screen_fx_flash_data_001F2060.c): gPlayerData_001F2070__grp: gPlayerData_001F2070@0x0, gPlayerData_001F2074@0x4, gPlayerData_001F2078@0x8, gPlayerData_001F207C@0xc */
unsigned int gPlayerData_001F2070__grp[0x4] __attribute__((aligned(16))) = { 0x40000000, 0x0, 0x3f800000, 0x0 };
/* data group (src/game/data/screen_fx_flash_data_001F2060.c): gPlayerData_001F2080__grp: gPlayerData_001F2080@0x0, gPlayerData_001F2084@0x4, gPlayerData_001F208C@0xc, gPlayerData_001F2090@0x10, gPlayerData_001F2094@0x14, gPlayerData_001F209C@0x1c */
unsigned int gPlayerData_001F2080__grp[0x10] __attribute__((aligned(16))) = { 0x0, 0xc2b40000, 0x0, 0x3f333333, 0x0, 0x0, 0x0, 0x3f333333, 0x0, 0x0, 0x0, 0xbf800000, 0x0, 0x0, 0x0, 0xbf800000 };
/* data group (src/game/data/screen_fx_flash_data_001F2060.c): gPlayerData_001F20C0__grp: gPlayerData_001F20C0@0x0, gPlayerData_001F20C4@0x4, gPlayerData_001F20C8@0x8, gPlayerData_001F20D0@0x10, gPlayerData_001F20D4@0x14, gPlayerData_001F20D8@0x18 */
unsigned int gPlayerData_001F20C0__grp[0x10] __attribute__((aligned(16))) = { 0x43000000, 0x43000000, 0x43000000, 0x43000000, 0x3f800000, 0x3f800000, 0x3f800000, 0x43000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
#endif
