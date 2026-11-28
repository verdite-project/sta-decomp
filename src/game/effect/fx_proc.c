#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/effect.h"
#include "game/map_object.h"
#include "game/data.h"
typedef struct { u8 pad[0x10]; Vec v; u8 p2[0x68]; f32 x88; u8 p3[0x1C]; s32 xA8; u8 p4[0xC]; f32 xB8; } O_FxProc_InitChase_0_001493E0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } Bits_FxProc_InitChase_0_001493E0;
typedef struct { u16 x0; u8 pad2[2]; u8 x4; u8 x5; u8 x6; Bits_FxProc_InitChase_0_001493E0 x7; u8 pad8[0x74 - 8]; u8 x74[4]; f32 x78; u8 pad7C[0x108-0x7C]; s32 rows[4][5]; } M_FxProc_InitChase_0_001493E0;
typedef struct { s32 r[5]; } R5;
typedef struct { u8 pad[0x210]; M_FxProc_InitChase_0_001493E0 *tbl[1]; } S90;
typedef struct {
    u8 pad[0x60];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[0x18];
    f32 x88;
    f32 x8C;
    S90 *p90;
    u16 x94;
    u8 pad96[0x114 - 0x96];
    Bits_FxProc_InitChase_0_001493E0 f114;
} O_FxProc_FireAtTarget_0_001494A0;
typedef struct { f32 v[4]; } V4;
typedef struct { f32 m[8]; } V8;
typedef struct { u8 pad[4]; u32 x4; f32 x8; f32 xC; V4 v; V8 m; } Src;
typedef struct { u8 a; u8 b0:1; u8 b1:1; } W;
typedef union { u32 w; W f; } WU;
typedef struct { V4 v; V8 m; WU w; u8 pad[0xC]; } Dst;
typedef struct { u8 pad[0x30]; Vec p; u8 pad40[0x10]; u8 x50; u8 pad51[0x2F]; } El;
typedef struct {
    s32 x0;
    u8 pad4[0x6A];
    u16 x6E;
    u8 pad70[0x110];
    El *x180;
    u8 pad184[0x54];
    u8 x1D8;
} Ent;
typedef struct {
    u8 pad[0x188];
    u8 pad188[2];
    u8 b0:1;
    u8 b1:1;
} N;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    u8 pad54[0xC];
    f32 x60, x64, x68, x6C;
    u8 pad70[0x20];
    N *x90;
    u8 pad94[0x14];
    f32 xA8;
    u8 padAC[4];
    u16 xB0[8];
    u8 padC0[0x54];
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1;
} O_FxProc_InitChase_0_001493E0_;
typedef struct { char pad[0xA8]; s32 a8; char pac[4]; f32 v[4]; } Obj_FxProc_InitChase_0_001493E0;
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x68];
    f32 x88;
    u8 pad8C[0x24];
    f32 xB0;
    u8 padB4[0x60];
    u8 b0:1;
    u8 b1:1;
} O_FxProc_DropToGround_0_00149D20;
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x30];
    f32 x50;
    f32 x54;
    u8 pad58[0x30];
    f32 x88;
    u8 pad8C[0x24];
    f32 xB0;
    u8 padB4[0xC];
    u8 xC0[0x20];
    u8 xE0[0x34];
    u8 b0:1;
    u8 b1:1;
} O_FxProc_RandomBounce_0_00149EB0;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    u8 pad58[8];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x24];
    s8 *x90;
    u8 pad94[0x2C];
    Mtx xC0;
} O_FxProc_DropToGround_0_00149D20_;
typedef struct { u8 pad[0x68]; f32 x68; u8 pad6C[0x44]; f32 xB0; } O_FxProc_StopLight_0_0014A860;
typedef struct { u8 pad[0x188]; Flags8 x188; } P_FxProc_InitChase_0_001493E0;
typedef struct {
    Vec x0; u8 pad10[0x40]; Vec x50; f32 x60; f32 x64; f32 x68; u8 pad6C[0x24];
    P_FxProc_InitChase_0_001493E0 *x90; u8 pad94[0x1C]; f32 xB0; u8 padB4[0x60]; Flags8 x114;
} O_FxProc_UpdateLight_0_0014A8A0;
typedef Bits8 BF8;
typedef struct { u8 pad[0x188]; BF8 x188; } P90;
typedef struct {
    Vec v0;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    s32 x6C[3];
    s32 x5C_dummy;
    u8 pad7C[0x14];
    P90 *x90;
    u8 pad94[0x1C];
    f32 xB0;
    u8 padB4[0x60];
    BF8 x114;
} O_FxProc_InitChase_0_001493E0__;
typedef struct { char pad[0x60]; f32 f60; f32 f64; char p68[8]; f32 v[4]; char p80[0x30]; f32 fb0; } Obj_FxProc_StopLight_0_0014A860;
typedef struct { u8 p:2; u8 v:1; } B2;
typedef struct {
    u8 pad0[0x60];
    f32 x60;
    f32 x64;
    u8 pad68[8];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    u8 pad80[8];
    f32 x88;
    u8 pad8C[4];
    u8 *x90;
    u8 pad94[0x1C];
    f32 xB0;
    u8 padB4[0x60];
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
} O_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u8 pad[0x30]; f32 v[4]; } M_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u8 pad[0x188]; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; } T_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct {
    u8 pad[0x50]; f32 x, y, z; u8 pad5C[0x2C]; f32 f88; u8 pad8C[4]; T_FxProc_SeekNearestEnemy_0_0014AB80 *t; u8 pad94[0x80]; u8 b0 : 1; u8 b1 : 1;
} O_FxProc_AimAlongGround_0_0014AF10;
typedef struct { f32 m[4][4]; } M_FxProc_AimAlongGround_0_0014AF10;
typedef struct { char pad[0xA8]; s32 a8; } T_FxProc_ReleaseChild_0_0014B170;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } Bits_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u128 q[4]; } Res;
typedef struct {
    Vec pos;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[4];
    f32 x74;
    u8 pad78[0x10];
    f32 x88;
    u8 pad8C[4];
    s32 x90;
    u8 pad94[0x14];
    s32 xA8;
    u8 padAC[4];
    f32 xB0;
    f32 xB4;
    f32 xB8;
    u8 padBC[4];
    u8 xC0[0x10];
    u8 xD0[0x44];
    Bits_FxProc_SeekNearestEnemy_0_0014AB80 f114;
} O_FxProc_SeekNearestEnemy_0_0014AB80_;
typedef struct {
    char pad[0x5C]; f32 scale; char p60[4]; f32 v64; char p68[0x40];
    s32 a8; char pac[4]; f32 b0; f32 b4; f32 b8;
} Obj_FxProc_SeekNearestEnemy_0_0014AB80;
typedef struct { u8 b0 : 1; u8 b1 : 1; } BF;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[0x30];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[0x2C];
    f32 xB8;
    f32 xBC;
    u8 padC0[0x54];
    BF x114;
} Obj_FxProc_PullTowardEnemy_0_0014BA10;
typedef Bits8 Bits_FxProc_TrackEnemyBone_0_0014BC90;
typedef struct {
    Vec pos;
    u8 pad10[0x54];
    f32 x64;
    u8 pad68[0x50];
    f32 xB8;
    f32 xBC;
    u8 padC0[0x54];
    Bits_FxProc_TrackEnemyBone_0_0014BC90 f114;
} Obj_FxProc_InitChase_0_001493E0_;
typedef struct { u8 b0:1; u8 b1:1; } F;
typedef struct { u8 pad[4]; f32 x4; u8 pad8[0x58]; f32 x60; u8 pad64[0x24]; f32 x88; u8 pad8c[0x28]; f32 xB4; u8 xB0p[4]; f32 xBC; u8 padc0[0x54]; F x114; } O_FxProc_SpawnTimed_0_0014BE70;
typedef struct { char pad[0x50]; f32 x, y, z; char p5c[0x64]; f32 m[3][4]; f32 v[4]; } Obj_FxProc_SpawnTimed_0_0014BE70;
typedef Bits8 Bits_FxProc_SpawnTimed_0_0014BE70;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5C[4];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[0x34];
    u8 xC0[0x54];
    Bits_FxProc_SpawnTimed_0_0014BE70 f114;
} O_FxProc_RandomWander_0_0014C160;
typedef struct { u8 pad[0x2A]; u16 f; u8 pad2C[0x80]; f32 xAC; } P_FxProc_SpawnTimed_0_0014BE70;
typedef struct { u8 pad[0x210]; P_FxProc_SpawnTimed_0_0014BE70 *tbl[1]; } Q;
typedef struct {
    u8 pad0[0x4C];
    f32 x4C;
    u8 pad50[0x10];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[0x20];
    Q *x90;
    u16 x94;
    u8 pad96[0x7E];
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
} O_FxProc_SpawnTimed_0_0014BE70_;
typedef struct { u8 pad[0x30]; f32 v[4]; } M_FxProc_SpawnTimed_0_0014BE70_;
typedef struct {
    char pad[0x114];
    unsigned char : 3;
    unsigned char f : 1;
} Obj_FxProc_SetDone_0_0014C870;
typedef struct { u8 pad[0x10]; f32 pos[3]; u8 pad1C[0x14]; f32 rot[3]; f32 rz; u8 pad40[0x20]; f32 range[3]; f32 ang; } O_FxProc_RandomJitter_0_0014C890;
typedef struct { f32 m[4][4]; } M_FxProc_RandomJitter_0_0014C890_;
typedef Bits8 Bits_FxProc_RandomJitter_0_0014C890;
typedef struct { u8 pad[0x188]; Bits_FxProc_RandomJitter_0_0014C890 f188; } S90_FxProc_RandomJitter_0_0014C890;
typedef struct { u8 pad[0x20]; f32 x20; u8 pad24[4]; f32 x28; u8 pad2C[0x14]; } Info;
typedef struct {
    Vec pos;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    u8 pad68[0x20];
    f32 x88;
    u8 pad8C[4];
    S90_FxProc_RandomJitter_0_0014C890 *p90;
    u8 pad94[0x2C];
    u8 xC0[0x54];
    Bits_FxProc_RandomJitter_0_0014C890 f114;
} Obj_FxProc_RandomJitter_0_0014C890;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } Bits_FxProc_StopAtWall_0_0014CDC0;
typedef struct {
    Vec p;
    u8 pad10[0x54];
    f32 x64;
    u8 pad68[0x20];
    f32 x88;
    u8 pad8C[0x88];
    Bits_FxProc_StopAtWall_0_0014CDC0 f114;
} O_FxProc_StopAtWall_0_0014CDC0;
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x40];
    f32 x60;
    u8 pad64[0x24];
    f32 x88;
    u8 pad8C[0x34];
    Vec c0;
    u8 padD0[0x10];
    f32 xE0;
    f32 xE4;
    f32 xE8;
    u8 padEC[0x28];
    u8 b0:1;
    u8 b1:1;
} O_FxProc_RandomJitter_0_0014C890_;
typedef struct { u8 pad[0x188]; Bits_FxProc_SpawnTimed_0_0014BE70 f188; } S90_FxProc_AimAtBestTarget_0_0014D020;
typedef struct {
    Vec pos;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[4];
    S90_FxProc_AimAtBestTarget_0_0014D020 *p90;
    u8 pad94[0x2C];
    Mtx xC0;
    u8 pad100[0x14];
    Bits_FxProc_SpawnTimed_0_0014BE70 f114;
} Obj_FxProc_AimAtBestTarget_0_0014D020;
typedef struct { u8 pad[0x10]; Vec v10; u8 pad20[0x40]; f32 x60; u8 pad64[0x58]; f32 xBC; } O_FxProc_MoveToward_0_0014D310;
typedef struct { Vec v; char p[0xAC]; f32 xBC; } O_FxProc_InitTowardEnemy_0_0014D410;
typedef union { u32 w; struct { u16 id; u8 f2; u8 f3; } s; } K;
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x40];
    f32 x60;
    u8 pad64[0x44];
    K xA8;
    u8 padAC[4];
    Vec xB0;
} O_FxProc_MoveToward_0_0014D310_;
typedef struct { u8 pad[0x20]; Vec a; Vec b; } M_FxProc_MoveToward_0_0014D310;
typedef struct { u8 m[0x40]; } MtxB;
typedef struct {
    u8 pad0[0x50];
    Vec x50;
    u8 pad60[0x30];
    M_FxProc_MoveToward_0_0014D310 *x90;
    u8 pad94[0x14];
    K xA8;
    u8 padAC[4];
    Vec xB0;
} O_FxProc_InitSeekCone_0_0014D700;
typedef struct { s16 v; } S;
typedef struct { void (*a)(s32); void (*b)(s32); void (*c)(s32); } E;
typedef struct { char pad[0xA8]; s32 a8; char pac[4]; f32 v[4]; } Obj_FxProc_NopA_2_0014DA00;
extern s32 gMapSbss_00201E80;
extern f32 gMatrixFromData_001F2160[];
extern Mtx gMatrixFromData_001F2170;
extern f32 gMatrixFromData_001F2160__as_FxProc_SplashDamage_0_0014A5F0[];
extern s8 gMatrixFromData_001F2160__as_FxProc_DropToGround_0_00149D20[];
extern void *gPlayerSbss_002022E4__as_FxProc_StopLight_0_0014A860_;
#ifndef NONMATCHING
extern f32 gFxProcRodata_001FB738[];
#else
/* data twins (src/game/data/fx_proc_rodata.c): gFxProcRodata_001FB738 */
static f32 gFxProcRodata_001FB738[0x2] = { 100000.0f, 0.0f };
#endif
extern Mtx gMatrixFromData_001F2170__as_FxProc_HomingProjectile_0_0014B1B0;
extern void *gPlayerSbss_002022E4__as_FxProc_InitHoming_0_0014B9E0;
extern s32 **gPlayerSbss_002022BC;
extern f32 gMatrixFromData_001F2160__as_FxProc_PullTowardEnemy_0_0014BA10[];
extern s8 gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____[];
extern M_FxProc_AimAlongGround_0_0014AF10 gMatrixFromData_001F2170__as_FxProc_SeekNearestEnemy_0_0014AB80____;
extern void *gPlayerSbss_002022E4__as_FxProc_SpawnTimed_0_0014BE70;
extern s8 gMatrixFromData_001F2160__as_FxProc_ScaleByDistance_0_0014C6F0[];
extern s8 gMatrixFromData_001F2150[];
extern s8 gMatrixFromData_001F2160__as_FxProc_RandomJitter_0_0014C890__[];
extern s32 gMatrixFromData_001F2170__as_FxProc_RandomJitter_0_0014C890__[];
extern s32 gPlayerSbss_002022E4__as_FxProc_InitTowardEnemy_0_0014D410;
extern s8 gMatrixFromData_001F2160__as_FxProc_MoveToward_0_0014D310_[];
#ifndef NONMATCHING
extern u16 gFxProcData_001F1E60[];
#else
/* data twins (src/game/data/fx_proc_data.c): gFxProcData_001F1E60 */
static u16 gFxProcData_001F1E60[0x20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0 };
#endif
extern E gFxProcData_001F1EA0[];
void FxProc_InitChase_0_001493E0(O_FxProc_InitChase_0_001493E0 *o);
void FxProc_FireAtTarget_0_001494A0(O_FxProc_FireAtTarget_0_001494A0 *o);
void FxProc_AreaDamage_0_00149810(O_FxProc_InitChase_0_001493E0_ *o, f32 dt);
void FxProc_AreaDamageWrap_0_00149CB0(u16 *arg0, f32 arg1);
void FxProc_InitAreaDamage_0_00149CC0(Obj_FxProc_InitChase_0_001493E0 *o);
void FxProc_DropToGround_0_00149D20(O_FxProc_DropToGround_0_00149D20 *o);
void FxProc_RandomBounce_0_00149EB0(O_FxProc_RandomBounce_0_00149EB0 *o);
inline s32 has_FxProc_InitChase_0_001493E0__(void);
void FxProc_ScatterAround_0_0014A210(O_FxProc_DropToGround_0_00149D20_ *o);
void FxProc_SplashDamage_0_0014A5F0(s8 *a0);
void FxProc_StopLight_0_0014A860(O_FxProc_StopLight_0_0014A860 *o);
void FxProc_UpdateLight_0_0014A8A0(O_FxProc_UpdateLight_0_0014A8A0 *o);
void FxProc_InitLight_0_0014A9C0(O_FxProc_InitChase_0_001493E0__ *o);
void FxProc_FollowPlayer_0_0014AAF0(Obj_FxProc_StopLight_0_0014A860 *o);
void FxProc_SeekNearestEnemy_0_0014AB80(O_FxProc_SeekNearestEnemy_0_0014AB80 *o);
void FxProc_RandomRingPos_0_0014AD90(f32 *a0);
inline s32 has_FxProc_SeekNearestEnemy_0_0014AB80_(void);
void FxProc_AimAlongGround_0_0014AF10(O_FxProc_AimAlongGround_0_0014AF10 *o);
void FxProc_ReleaseChild_0_0014B170(T_FxProc_ReleaseChild_0_0014B170 *arg0);
void FxProc_HomingProjectile_0_0014B1B0(O_FxProc_SeekNearestEnemy_0_0014AB80_ *o, f32 kk);
void FxProc_InitHoming_0_0014B9E0(Obj_FxProc_SeekNearestEnemy_0_0014AB80 *o);
void FxProc_PullTowardEnemy_0_0014BA10(Obj_FxProc_PullTowardEnemy_0_0014BA10 *a0);
void FxProc_TrackEnemyBone_0_0014BC90(Obj_FxProc_InitChase_0_001493E0_ *a);
void FxProc_SpawnTimed_0_0014BE70(O_FxProc_SpawnTimed_0_0014BE70 *o);
void FxProc_SnapToGround_0_0014BF60(f32 *o);
void FxProc_AttachRotated_0_0014C060(Obj_FxProc_SpawnTimed_0_0014BE70 *o);
void FxProc_AttachRotatedB_0_0014C0E0(Obj_FxProc_SpawnTimed_0_0014BE70 *o);
void FxProc_RandomWander_0_0014C160(O_FxProc_RandomWander_0_0014C160 *o);
inline s32 has_FxProc_InitChase_0_001493E0(void);
void FxProc_ScaleByDistance_0_0014C6F0(O_FxProc_SpawnTimed_0_0014BE70_ *o);
void FxProc_SetDone_0_0014C870(Obj_FxProc_SetDone_0_0014C870 *o);
void FxProc_RandomJitter_0_0014C890(O_FxProc_RandomJitter_0_0014C890 *o);
void FxProc_AimAtEnemyCone_0_0014CAC0(Obj_FxProc_RandomJitter_0_0014C890 *a);
void FxProc_StopAtWall_0_0014CDC0(O_FxProc_StopAtWall_0_0014CDC0 *o);
void FxProc_SlideOnSurface_0_0014CEC0(O_FxProc_RandomJitter_0_0014C890_ *o);
void FxProc_AimAtBestTarget_0_0014D020(Obj_FxProc_AimAtBestTarget_0_0014D020 *a);
inline s32 has_FxProc_MoveToward_0_0014D310(void);
void FxProc_MoveToward_0_0014D310(O_FxProc_MoveToward_0_0014D310 *o);
void FxProc_InitTowardEnemy_0_0014D410(O_FxProc_InitTowardEnemy_0_0014D410 *arg0);
void FxProc_SeekEnemyInCone_0_0014D4A0(O_FxProc_MoveToward_0_0014D310_ *o);
void FxProc_InitSeekCone_0_0014D700(O_FxProc_InitSeekCone_0_0014D700 *o);
void FxTable_GetEntry_0_0014D8A0(S *a0, u16 i);
s32 FxTable_CallA_0_0014D8E0(u16 i, s32 v);
s32 FxTable_CallB_0_0014D940(u16 i, s32 v);
s32 FxTable_CallC_0_0014D9A0(u16 i, s32 v);
void FxProc_InitAtOrigin_0_0014DA30(Obj_FxProc_NopA_2_0014DA00 *o);
u32 Enemy_GetCurrentParamIdx_0_0013E110(void *);
void sceVu0CopyVector(void *, void *);
u16* ActorList_Next_2_001A5460(s32 *);
void Fx_EvalCurveVec_1_001631E0(Vec *, f32, u8 *, void *, u8 *, f32, s32);
void Fx_GetWorldMatrix_1_00163C80(void *, void *);
void sceVu0ApplyMatrix(void *, void *, void *);
u16* ActorList_NextB_0_001A5710(void);
u16* ActorList_NextTargetable_0_001A5660(void);
s32 Proj_FindTarget_0_00146C70(void *, Vec*, void *, s32*, Vec*, f32);
void Proj_SpawnAttack_0_00146A70(S90 *, u16 *, u8, u32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetPosition_1_00167710(s8*, void *);
s32 Map_LineTest_1_001470F0(void *, void *, s32, s32, s32, void *);
void memcpy(void *, void *, s32);
s32 Enemy_IsBusy_0_0013EE40(s8 *);
Src* EnemyType_Get_0_001A8360(s32);
void memset(void *, s32, s32);
s32 Sfx_GetOwner_1_001675D0(N *);
void Combat_ProcessHitWrap_0_0013BA60(s32, void *, s8 *, s32);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitChase_0_001493E0(O_FxProc_FireAtTarget_0_001494A0 *, Mtx *);
s8* ActorList_Next_2_001A5460__as_FxProc_AreaDamage_0_00149810(s32 *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_AreaDamage_0_00149810(O_FxProc_InitChase_0_001493E0_ *, Mtx *);
u16 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_AreaDamage_0_00149810(s8 *);
void FxProc_AreaDamage_0_00149810__as_FxProc_AreaDamageWrap_0_00149CB0(u16 *arg0, f32 arg1);
f32 sceVu0InnerProduct(void *, void *);
f32 sqrtf(float);
u16 Rand_Next_3_0015ED20(void);
void sceVu0RotMatrixY(f32, void *, void *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
void Mtx_RotateToward_0_00146140(void *, f32, f32);
void sceVu0MulMatrix(void *, void *, Mtx *);
void sceVu0ScaleVector(void *, void *, f32);
f32 cosf(f32);
f32 sinf(f32);
void sceVu0AddVector(void *, void *, void *);
void sceVu0SubVector(void *, void*, void*);
void Actor_GetDirNormalized_0_00146570(Actor*, void *);
void Actor_GetYawPitch_1_00145F40(Actor *, f32 *, f32 *);
void sceVu0RotMatrixY__as_FxProc_ScatterAround_0_0014A210(Mtx *, Mtx *, f32);
f64 pow(double, double);
f64 fptodp(f32);
f64 dpadd(double, double);
f32 dptofp(double);
void Sfx_SetPosition_1_00167710__as_FxProc_InitChase_0_001493E0_(s8 *, Vec *);
s32 Map_LineTest_1_001470F0__as_FxProc_InitChase_0_001493E0_(O_FxProc_FireAtTarget_0_001494A0 *, Vec *, s32, s32, s32, Vec *);
s32 Map_LineTest_1_001470F0__as_FxProc_DropToGround_0_00149D20(Vec *, Vec *, s32, s32, s32, Vec *);
s8* ActorList_Next_2_001A5460__as_FxProc_DropToGround_0_00149D20(s32 *);
void Sfx_SetPosition_1_00167710__as_FxProc_DropToGround_0_00149D20(s8 *, f32 *);
void Proj_SpawnAttack_0_00146A70__as_FxProc_DropToGround_0_00149D20(s32, s8 *, s32, u16);
void GlowFx_Stop_0_001E0D30(f32, s32);
s32 GlowFx_Start_0_001E1050(s32);
void GlowFx_SetParams_0_001E0F30(f32, f32, s32, Vec *, Vec *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_StopLight_0_0014A860(O_FxProc_UpdateLight_0_0014A8A0 *, Mtx *);
s32 GlowFx_Start_0_001E1050__as_FxProc_InitLight_0_0014A9C0(void);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitLight_0_0014A9C0(O_FxProc_InitChase_0_001493E0__ *, Mtx *);
void sceVu0CopyVector__as_FxProc_InitLight_0_0014A9C0(Vec *, Vec *);
f32* Player_GetPosition_1_00145730(s32 k);
void sceVu0CopyVector__as_FxProc_FollowPlayer_0_0014AAF0(f32 *v0, f32 *v1);
Actor* Proj_FindNearestEnemy_0_00147450(f32, void *);
void sceVu0CopyMatrix(void *, void *);
void sceVu0AddVector__as_FxProc_SeekNearestEnemy_0_0014AB80(f32 *, f32 *, f32 *);
void sceVu0AddVector__as_FxProc_AimAlongGround_0_0014AF10(f32 *, f32 *, s8 *);
void sceVu0CopyVector__as_FxProc_AimAlongGround_0_0014AF10(void *, f32 *);
void Sfx_RequestStop_1_00167240(s32);
void Actor_GetDir_1_001465C0(Actor *, Vec *);
Actor* Proj_FindEnemyInCone_0_00146EF0(f32, s8 *, f32, Vec *, f32, s32);
void Vec_GetYawPitchBetween_1_00146310(s8 *, Vec *, s8 *, f32 *, f32 *);
f32 fabsf(f32);
f32 atan2f(f32, f32);
s32 Map_RaycastCapsule_0_00145D10(O_FxProc_SeekNearestEnemy_0_0014AB80_ *, Vec *, s32, s32, Res *);
void Proj_SpawnFromSource_0_00146980(s32, Res *, s32);
void sceVu0AddVector__as_FxProc_SeekNearestEnemy_0_0014AB80_(f32*, f32*, void *);
void sceVu0RotMatrixY__as_FxProc_SeekNearestEnemy_0_0014AB80_(f32, M_FxProc_AimAlongGround_0_0014AF10 *, M_FxProc_AimAlongGround_0_0014AF10 *);
void sceVu0CopyMatrix__as_FxProc_SeekNearestEnemy_0_0014AB80_(f32 *, s8 *);
void Actor_GetYawPitch_1_00145F40__as_FxProc_HomingProjectile_0_0014B1B0(Actor *, f32 *, s32);
void sceVu0RotMatrixY__as_FxProc_HomingProjectile_0_0014B1B0(f32, Mtx *, Mtx *);
void sceVu0CopyMatrix__as_FxProc_HomingProjectile_0_0014B1B0(void *, Mtx *);
void sceVu0AddVector__as_FxProc_HomingProjectile_0_0014B1B0(Vec *, Vec *, void *);
void Actor_GetYawPitch_1_00145F40__as_FxProc_InitHoming_0_0014B9E0(void *a, f32 *b, s32 c);
void EnemyScr_Event2015_1_00141510(s8 *, u8, s32, s32);
void sceVu0Normalize(void *, void *);
void sceVu0ScaleVector__as_FxProc_SeekNearestEnemy_0_0014AB80__(Vec *, void *, f32);
void sceVu0AddVector__as_FxProc_PullTowardEnemy_0_0014BA10(f32 *, f32 *, f32 *);
f32 Vec_Distance_3_00146940__as_FxProc_PullTowardEnemy_0_0014BA10(Obj_FxProc_PullTowardEnemy_0_0014BA10 *, f32 *);
void sceVu0ScaleVector__as_FxProc_PullTowardEnemy_0_0014BA10(f32 *, f32 *, f32);
Vec* Enemy_Ptr6F0_1_0013FFA0(u16 *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_SeekNearestEnemy_0_0014AB80___(O_FxProc_SeekNearestEnemy_0_0014AB80 *, M_FxProc_SeekNearestEnemy_0_0014AB80 *);
u32 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_SeekNearestEnemy_0_0014AB80___(s8 *);
void sceVu0SubVector__as_FxProc_SeekNearestEnemy_0_0014AB80___(f32 *, f32 *, f32 *);
u16* ActorList_Next_2_001A5460__as_FxProc_TrackEnemyBone_0_0014BC90(s32 *);
u32 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_TrackEnemyBone_0_0014BC90(u16 *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_TrackEnemyBone_0_0014BC90(Obj_FxProc_InitChase_0_001493E0_ *, Mtx *);
void sceVu0SubVector__as_FxProc_TrackEnemyBone_0_0014BC90(Vec *, Vec *, Vec *);
u32 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_InitChase_0_001493E0__(u16 *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitChase_0_001493E0__(void *, Mtx*);
void sceVu0ApplyMatrix__as_FxProc_InitChase_0_001493E0__(Vec *, Mtx *, Vec *);
s32 Proj_FindTarget_0_00146C70__as_FxProc_InitChase_0_001493E0__(Vec *, Vec *, u16 *, s32 *, Vec *, f32);
s32 Map_LineTest_1_001470F0__as_FxProc_InitChase_0_001493E0__(void *, Vec*, s32, s32, s32, Vec*);
f32 Vec_Distance_3_00146940__as_FxProc_InitChase_0_001493E0__(void *, Vec *);
f32 sceVu0InnerProduct__as_FxProc_InitChase_0_001493E0__(Vec *, Vec *);
void sceVu0RotMatrixY__as_FxProc_InitChase_0_001493E0__(f32, Mtx *, Mtx *);
void sceVu0ScaleVector__as_FxProc_InitChase_0_001493E0__(Vec *, void *, f32);
void sceVu0AddVector__as_FxProc_InitChase_0_001493E0__(void *, void *, Vec *);
void sceVu0SubVector__as_FxProc_InitChase_0_001493E0__(Vec *, s8 *, s8 *);
void Actor_GetDirNormalized_0_00146570__as_FxProc_InitChase_0_001493E0__(Actor *, Vec *);
s8* Player_GetPosition_1_00145730__as_FxProc_SeekNearestEnemy_0_0014AB80____(void);
s32 Rand_Next_3_0015ED20__as_FxProc_SeekNearestEnemy_0_0014AB80____(void);
void Actor_GetYawPitch_1_00145F40__as_FxProc_SeekNearestEnemy_0_0014AB80____(s32, f32 *, f32 *);
void sceVu0ApplyMatrix__as_FxProc_SeekNearestEnemy_0_0014AB80____(f32 *, M_FxProc_AimAlongGround_0_0014AF10 *, f32 *);
s32 Map_LineTest_1_001470F0__as_FxProc_SeekNearestEnemy_0_0014AB80____(f32 *, f32 *, s32, s32, s32, s32 *);
void Actor_GetDirNormalized_0_00146570__as_FxProc_SeekNearestEnemy_0_0014AB80____(Actor *, f32 *);
void Mtx_RotateToward_0_00146140__as_FxProc_SeekNearestEnemy_0_0014AB80____(s32, f32, f32);
void sceVu0RotMatrixX__as_FxProc_SeekNearestEnemy_0_0014AB80____(Mtx *, Mtx *, f32);
Actor* ActorList_NextB_0_001A5710__as_FxProc_SeekNearestEnemy_0_0014AB80____(void);
Actor* ActorList_NextTargetable_0_001A5660__as_FxProc_SeekNearestEnemy_0_0014AB80____(void);
s32 Proj_FindTarget_0_00146C70__as_FxProc_SeekNearestEnemy_0_0014AB80____(O_FxProc_SeekNearestEnemy_0_0014AB80_ *, Vec *, Actor *, s32 *, Vec *, f32);
void Proj_SpawnAttack_0_00146A70__as_FxProc_SeekNearestEnemy_0_0014AB80____(s32, Actor *, u8, s32);
void Sfx_SetPosition_1_00167710__as_FxProc_SeekNearestEnemy_0_0014AB80____(s8 *, Vec *);
s8* ActorList_Next_2_001A5460__as_FxProc_SeekNearestEnemy_0_0014AB80____(s32 *);
f32 sceVu0InnerProduct__as_FxProc_SeekNearestEnemy_0_0014AB80____(f32 *, f32 *);
void Actor_BuildRotMatrix_0_00146600(void *a, f32 (*m)[4]);
void sceVu0RotMatrixZ(Mtx *, Mtx *, f32);
s32 Map_LineTest_1_001470F0__as_FxProc_RandomWander_0_0014C160(Vec *, Vec *, s32, s32, s32, O_FxProc_RandomWander_0_0014C160 *);
void sceVu0CopyMatrix__as_FxProc_RandomWander_0_0014C160(void *, Mtx *);
void sceVu0CopyVector__as_FxProc_SpawnTimed_0_0014BE70(f32 *v0, f32 *v1);
void Player_GetPos_1_001C9410(Vec *);
void sceVu0ApplyMatrix__as_FxProc_RandomJitter_0_0014C890(f32 *, M_FxProc_RandomJitter_0_0014C890_ *, f32 *);
void sceVu0ApplyMatrix__as_FxProc_AimAtEnemyCone_0_0014CAC0(Vec *, Mtx *, Vec *);
void Mtx_RotateToward_0_00146140__as_FxProc_SlideOnSurface_0_0014CEC0(Vec *, f32, f32);
Actor* Proj_FindBestTarget_0_001472A0(Obj_FxProc_AimAtBestTarget_0_0014D020 *, f32, f32, s8 *, f32, s32);
void sceVu0AddVector__as_FxProc_RandomJitter_0_0014C890_(Vec *, Vec *, Vec *);
void sceVu0ApplyMatrix__as_FxProc_AimAtBestTarget_0_0014D020(Vec *, Mtx *, Vec *);
void Mtx_RotateToward_0_00146140__as_FxProc_AimAtBestTarget_0_0014D020(Mtx *, f32, f32);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_SpawnTimed_0_0014BE70_(O_FxProc_SpawnTimed_0_0014BE70_ *, M_FxProc_SpawnTimed_0_0014BE70_ *);
u32 Rand_Next_3_0015ED20__as_FxProc_RandomJitter_0_0014C890__(void);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_RandomJitter_0_0014C890__(O_FxProc_RandomJitter_0_0014C890 *, M_FxProc_RandomJitter_0_0014C890_ *);
void sceVu0ApplyMatrix__as_FxProc_RandomJitter_0_0014C890__(void *, void *, void *);
void sceVu0RotMatrixY__as_FxProc_RandomJitter_0_0014C890__(f32, Mtx *, void *);
s32 Map_LineTest_1_001470F0__as_FxProc_RandomJitter_0_0014C890__(Vec *, Vec *, s32, s32, s32, Vec *);
void Actor_BuildRotMatrix_0_00146600__as_FxProc_RandomJitter_0_0014C890__(Actor *, Info *);
void sceVu0CopyMatrix__as_FxProc_RandomJitter_0_0014C890__(void *, void *);
s32 Map_LineTest_1_001470F0__as_FxProc_SpawnTimed_0_0014BE70__(Vec *, Vec *, s32, u8, s32, Vec *);
void sceVu0ApplyMatrix__as_FxProc_SpawnTimed_0_0014BE70__(f32 *out, f32 (*m)[4], f32 *v);
void sceVu0CopyMatrix__as_FxProc_SpawnTimed_0_0014BE70__(f32 (*m0)[4], f32 (*m1)[4]);
void sceVu0RotMatrixY__as_FxProc_SpawnTimed_0_0014BE70__(Mtx *, Mtx *, f32);
f32 Vec_Distance_3_00146940__as_FxProc_SpawnTimed_0_0014BE70__(f32 *, s8 *);
void Actor_GetDirNormalized_0_00146570__as_FxProc_SpawnTimed_0_0014BE70__(Actor *, Vec *);
void Actor_GetYawPitch_1_00145F40__as_FxProc_SpawnTimed_0_0014BE70__(Actor *, f32 *, s32);
void sceVu0AddVector__as_FxProc_SpawnTimed_0_0014BE70__(Vec*, Vec*, void *);
f32 sceVu0InnerProduct__as_FxProc_SpawnTimed_0_0014BE70__(Vec *, Vec *);
void sceVu0SubVector__as_FxProc_MoveToward_0_0014D310(Vec *, s8 *, O_FxProc_MoveToward_0_0014D310 *);
void sceVu0SubVector__as_FxProc_InitTowardEnemy_0_0014D410(Vec *, Vec *, Vec *);
Vec* Enemy_Ptr6F0_1_0013FFA0__as_FxProc_SeekEnemyInCone_0_0014D4A0(s8 *);
void sceVu0CopyVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(Vec *, Vec *);
void sceVu0SubVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(Vec *, Vec *, void *);
Vec* Enemy_Ptr6F0_1_0013FFA0__as_FxProc_InitSeekCone_0_0014D700(s8 *);
void sceVu0CopyVector__as_FxProc_InitSeekCone_0_0014D700(Vec *, Vec *);
void sceVu0SubVector__as_FxProc_InitSeekCone_0_0014D700(Vec *, Vec *, void *);
void sceVu0Normalize__as_FxProc_InitChase_0_001493E0___(f32 *, f32 *);
void sceVu0SubVector__as_FxProc_MoveToward_0_0014D310_(Vec*, void *, void*);
f32 sceVu0InnerProduct__as_FxProc_MoveToward_0_0014D310_(Vec *, Vec *);
void sceVu0Normalize__as_FxProc_MoveToward_0_0014D310_(Vec *, Vec *);
void sceVu0ScaleVector__as_FxProc_MoveToward_0_0014D310_(Vec *, Vec *, f32);
void sceVu0AddVector__as_FxProc_MoveToward_0_0014D310_(Vec *, Vec *, Vec *);
s32 Enemy_Ptr6F0_1_0013FFA0__as_FxProc_MoveToward_0_0014D310_(s32);
void sceVu0CopyVector__as_FxProc_MoveToward_0_0014D310_(Vec *, s32);
s8* ActorList_Next_2_001A5460__as_FxProc_MoveToward_0_0014D310_(s32 *);
u16 Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_MoveToward_0_0014D310_(s8 *);
void Fx_GetWorldMatrix_1_00163C80__as_FxProc_MoveToward_0_0014D310_(O_FxProc_MoveToward_0_0014D310_ *, M_FxProc_MoveToward_0_0014D310 *);
s8* Proj_FindEnemyInCone_0_00146EF0__as_FxProc_MoveToward_0_0014D310_(f32, Vec *, f32, Vec *, f32, s32);
void Actor_BuildRotMatrix_0_00146600__as_FxProc_MoveToward_0_0014D310_(Actor *, MtxB *);
void sceVu0ApplyMatrix__as_FxProc_MoveToward_0_0014D310_(Vec *, MtxB *, Vec *);

/* FxProc_InitChase_0_001493E0____ */
/* FxProc_InitChase_0_001493E0____ */
/* FxProc_InitChase_0_001493E0___ */

/* FxProc_InitChase_0_001493E0___ */
/* FxProc_InitChase_0_001493E0__ */

/* FxProc_InitChase_0_001493E0__ */
/* FxProc_InitChase_0_001493E0_ */

/* FxProc_InitChase_0_001493E0_ */
/* FxProc_InitChase_0_001493E0_ */
/* FxProc_InitChase_0_001493E0 */

/* FxProc_InitChase_0_001493E0 */
void FxProc_InitChase_0_001493E0(O_FxProc_InitChase_0_001493E0 *o) {
    s32 it;
    u16 *e;
    o->xA8 = 0;
    o->x88 = 600.0f;
    sceVu0CopyVector(&o->v, &gZeroVec_003139A0);
    it = 0;
    do {
        e = ActorList_Next_2_001A5460(&it);
    } while (e != NULL && *e != 0x3C);
    if (e != NULL) {
        o->xB8 = Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_InitChase_0_001493E0__(e);
        return;
    }
    o->xB8 = 0.0f;
}

/* FxProc_FireAtTarget_0_001494A0 */
static inline f32 u2f(u32 x) { return x; }

void FxProc_FireAtTarget_0_001494A0(O_FxProc_FireAtTarget_0_001494A0 *o) {
    Vec b;
    Vec a;
    Vec out;
    Mtx mtx;
    Vec hit;
    s32 cc;
    M_FxProc_InitChase_0_001493E0 *m;
    u8 *p;
    f32 r;
    u16 *n;
    s32 ok;
    s32 t;
    s8 *q;

    m = o->p90->tbl[o->x94];
    p = (u8 *)&((R5 *)((u8 *)m + 0x108))[m->x4].r[m->x5] + m->x6 * 12;
    p = m->x7.b1 ? p + 0x40 : p;
    p = m->x7.b2 ? p + 0xA0 : p;
    b.x = 0.0f;
    b.y = m->x78;
    b.w = 1.0f;
    b.z = 0.0f;
    Fx_EvalCurveVec_1_001631E0(&a, o->x8C, m->x74, NULL, p, 0.033333335f * u2f(m->x0), m->x7.b0);
    a.w = 1.0f;
    a.x = 0.0f;
    a.z = 0.0f;
    Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitChase_0_001493E0(o, &mtx);
    sceVu0ApplyMatrix__as_FxProc_InitChase_0_001493E0__(&b, &mtx, &b);
    sceVu0ApplyMatrix__as_FxProc_InitChase_0_001493E0__(&a, &mtx, &a);
    r = o->x60;
    for (n = ActorList_NextB_0_001A5710(); n != NULL; n = ActorList_NextTargetable_0_001A5660()) {
        if (*n && Proj_FindTarget_0_00146C70__as_FxProc_InitChase_0_001493E0__(&b, &a, n, &cc, &out, r)) {
            ok = 1;
            goto found;
        }
    }
    cc = 0;
    n = NULL;
    ok = 0;
found:
    if (ok) {
        Proj_SpawnAttack_0_00146A70(o->p90, n, cc, o->x64);
        o->x88 = u2f(o->f114.b1 = 0);
        t = o->x6C;
        if (t) {
            q = Sfx_Spawn_2_00169B50(t, 0, 0, 0);
            if (q) {
                Sfx_SetPosition_1_00167710__as_FxProc_InitChase_0_001493E0_(q, &out);
            }
        }
    } else if (Map_LineTest_1_001470F0__as_FxProc_InitChase_0_001493E0_(o, &a, 3, 6, 0, &hit)) {
        q = Sfx_Spawn_2_00169B50(o->x68, 0, 0, 0);
        if (q) {
            Sfx_SetPosition_1_00167710__as_FxProc_InitChase_0_001493E0_(q, &hit);
        }
        o->x88 = u2f(o->f114.b1 = 0);
    }
}

/* FxProc_AreaDamage_0_00149810 */

void FxProc_AreaDamage_0_00149810(O_FxProc_InitChase_0_001493E0_ *o, f32 dt) {
    f32 t;
    s32 it;
    Vec pos;
    u16 ta[8];
    Dst d;
    u16 tb[8];
    Mtx m;
    u16 id;
    s32 first;
    s32 i;
    El *el;
    s32 j;
    Ent *e;
    Ent ***pp;
    s8 *a;

    it = 0;
    a = ActorList_Next_2_001A5460__as_FxProc_AreaDamage_0_00149810(&it);
    if (o->b5) {
        Fx_GetWorldMatrix_1_00163C80__as_FxProc_AreaDamage_0_00149810(o, &m);
        sceVu0CopyVector(&pos, &m.m[3]);
    } else {
        sceVu0CopyVector(&pos, o);
    }
    memcpy(&t, &o->xA8, 4);
    first = (t == 0.0f);
    t += dt;
    if (o->x50 <= t) {
        t = 0.0f;
    }
    memcpy(&o->xA8, &t, 4);
    if (!first) return;
    {
        if (o->x64 == 2.0f) {
            for (i = 0, pp = (Ent ***)(&gMapSbss_00201E80 + 2); i < 2; i++, pp++) {
                if (*pp != 0 && ((e = **pp)->x1D8 & 1)) {
                    for (j = 0; j < e->x6E; j++) {
                        el = &e->x180[j];
                        if (!(el->x50 & 3)) {
                            if (Vec_Distance_3_00146940__as_FxProc_InitChase_0_001493E0__(&el->p, &pos) < o->x60) {
                                MapObj_PlayAnimWrap_0_001B7CC0(e->x0, j);
                            }
                        }
                    }
                }
            }
        }
        if (o->x64 == 2.0f) return;
        {
            while (a) {
                if (*(u16 *)a == 0 && o->x64 == 1.0f) goto next;
                if (*(u16 *)a != 0 && o->x64 == 0.0f) goto next;
                if (Enemy_IsBusy_0_0013EE40(a)) goto next;
                if (o->x6C == 0.0f) {
                    id = Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_AreaDamage_0_00149810(a);
                    sceVu0CopyVector(ta, o->xB0);
                    for (j = 0; j < 8; j++) {
                        if (id == ta[j]) {
                            id = 0xFFFF;
                            break;
                        }
                    }
                    if (id == 0xFFFF) goto next;
                }
                if (Vec_Distance_3_00146940__as_FxProc_InitChase_0_001493E0__(a ? (void *)(*(s32 *)(a + 0x518) + 0x90) : gMatrixFromData_001F2160, &pos) < o->x60) {
                    if (o->x90->b1) {
                        e = (Ent *)((s8 *)o->x90 + 0xE80);
                    } else {
                        e = (Ent *)EnemyType_Get_0_001A8360((s32)o->x68);
                        memset(&d, 0, 0x40);
                        if (e) {
                            d.v = ((Src *)e)->v;
                            d.m = ((Src *)e)->m;
                            d.w.w = ((Src *)e)->x4;
                            d.w.f.b1 = 1;
                        }
                        e = (Ent *)&d;
                    }
                    Combat_ProcessHitWrap_0_0013BA60(Sfx_GetOwner_1_001675D0(o->x90), e, a, 0);
                    id = Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_AreaDamage_0_00149810(a);
                    sceVu0CopyVector(tb, o->xB0);
                    for (j = 0; j < 8; j++) {
                        if (tb[j] == 0xFFFF || id == tb[j]) {
                            tb[j] = id;
                            break;
                        }
                    }
                    sceVu0CopyVector(o->xB0, tb);
                }
            next:
                a = ActorList_Next_2_001A5460__as_FxProc_AreaDamage_0_00149810(&it);
            }
        }
    }
}

/* FxProc_AreaDamageWrap_0_00149CB0 */

void FxProc_AreaDamageWrap_0_00149CB0(u16 *arg0, f32 arg1)
{
    FxProc_AreaDamage_0_00149810__as_FxProc_AreaDamageWrap_0_00149CB0(arg0, arg1);
}

/* FxProc_InitAreaDamage_0_00149CC0 */
void FxProc_InitAreaDamage_0_00149CC0(Obj_FxProc_InitChase_0_001493E0 *o)
{
    u16 t[8];
    sceVu0CopyVector(t, o->v);
    t[7] = 0xFFFF;
    t[6] = 0xFFFF;
    t[5] = 0xFFFF;
    t[4] = 0xFFFF;
    t[3] = 0xFFFF;
    t[2] = 0xFFFF;
    t[1] = 0xFFFF;
    t[0] = 0xFFFF;
    sceVu0CopyVector(o->v, t);
    o->a8 = 0;
}

/* FxProc_DropToGround_0_00149D20 */

/* FxProc_DropToGround_0_00149D20 */
/* FxProc_DropToGround_0_00149D20 */
/* FxProc_DropToGround_0_00149D20 */
void FxProc_DropToGround_0_00149D20(O_FxProc_DropToGround_0_00149D20 *o) {
    Vec out;
    Vec lo;
    Vec hi;
    f32 s;
    f32 r;
    f32 h;
    if (5.0f < o->xB0) {
        o->xB0 = 0;
    } else {
        o->xB0 = o->xB0 + 1.0f;
        return;
    }
    h = 1000.0f;
    lo.x = o->p.x;
    lo.y = o->p.y - h;
    lo.z = o->p.z;
    hi.x = o->p.x;
    hi.y = o->p.y + h;
    hi.z = o->p.z;
    hi.w = 1.0f;
    lo.w = 1.0f;
    if (Map_LineTest_1_001470F0__as_FxProc_DropToGround_0_00149D20(&lo, &hi, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
        s = sqrtf(sceVu0InnerProduct__as_FxProc_InitChase_0_001493E0__(&o->v, &o->v));
        o->v.y = 0;
        r = s / sqrtf(sceVu0InnerProduct__as_FxProc_InitChase_0_001493E0__(&o->v, &o->v));
        o->v.x *= r;
        o->v.z *= r;
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}

/* FxProc_RandomBounce_0_00149EB0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 jit(f32 a) { f32 t = 0.5f - 0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20(); return t * a; }

void FxProc_RandomBounce_0_00149EB0(O_FxProc_RandomBounce_0_00149EB0 *o) {
    Mtx m;
    Vec out;
    Vec lo;
    Vec hi;
    f32 rx;
    f32 ry;
    f32 h;

    rx = 0.0f;
    if (o->x50 != rx) {
        rx = 0.01745f * o->x50;
    }
    rx = jit(rx);
    ry = 0.0f;
    ry = (o->x54 != ry) ? 0.01745f * o->x54 : ry;
    ry = jit(ry);
    o->xB0 = 0;
    sceVu0RotMatrixY__as_FxProc_InitChase_0_001493E0__(WRAP(ry), &m, &gMatrixFromData_001F2170);
    sceVu0RotMatrixX(WRAP(rx), &m, &m);
    Mtx_RotateToward_0_00146140(o->xC0, o->v.x, o->v.z);
    sceVu0MulMatrix(o->xC0, o->xC0, &m);
    sceVu0ScaleVector__as_FxProc_InitChase_0_001493E0__(&o->v, o->xE0, sqrtf(sceVu0InnerProduct__as_FxProc_InitChase_0_001493E0__(&o->v, &o->v)));
    h = 1000.0f;
    lo.x = o->p.x;
    lo.y = o->p.y - h;
    lo.z = o->p.z;
    hi.x = o->p.x;
    hi.y = o->p.y + h;
    hi.z = o->p.z;
    hi.w = 1.0f;
    lo.w = 1.0f;
    if (Map_LineTest_1_001470F0__as_FxProc_DropToGround_0_00149D20(&lo, &hi, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}

/* FxProc_ScatterAround_0_0014A210 */
/* ang < 0.0f | a */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 DEG(f32 a) { return a ? 0.01745f * a : 0.0f; }
inline s32 has_FxProc_InitChase_0_001493E0__(void) {
    return gPlayerSbss_002022E4 != NULL && gPlayerSbss_002022E4->unk518 != NULL;
}

void FxProc_ScatterAround_0_0014A210(O_FxProc_DropToGround_0_00149D20_ *o) {
    f32 h;
    f32 ang;
    f32 r;
    f32 yr;
    f32 a;
    s8 *b;
    Vec t;
    Vec w;
    Vec d;

    h = o->x60;
    ang = o->x64;
    r = o->x50;
    yr = o->x54;
    a = 6.2831855f * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20());
    r *= 1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20();
    d.x = r * cosf(a);
    d.z = r * sinf(a);
    d.y = yr * (1.0f - 2.0f * (1.5259022e-05f * (f32)(u32)Rand_Next_3_0015ED20()));
    d.w = 0.0f;
    sceVu0AddVector__as_FxProc_InitChase_0_001493E0__(o, o, &d);
    b = o->x90;
    sceVu0SubVector__as_FxProc_InitChase_0_001493E0__(&t, has_FxProc_InitChase_0_001493E0__() ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_DropToGround_0_00149D20, b + 0x30);
    sceVu0AddVector__as_FxProc_InitChase_0_001493E0__(o, o, &t);
    o->p.w = 1.0f;
    o->p.y += h;
    Actor_GetDirNormalized_0_00146570__as_FxProc_InitChase_0_001493E0__(gPlayerSbss_002022E4, &w);
    o->p.x += w.x * o->x68;
    o->p.z += w.z * o->x68;
    if (ang < 0.0f) {
        Actor_GetYawPitch_1_00145F40(gPlayerSbss_002022E4, &ang, NULL);
        sceVu0RotMatrixY__as_FxProc_ScatterAround_0_0014A210(&o->xC0, &gMatrixFromData_001F2170, WRAP(ang));
    } else {
        sceVu0RotMatrixY__as_FxProc_ScatterAround_0_0014A210(&o->xC0, &gMatrixFromData_001F2170, WRAP(DEG(ang)));
    }
}

/* FxProc_SplashDamage_0_0014A5F0 */
#define POS(p) ((p) ? (f32 *)(*(s32 *)((p) + 0x518) + 0x90) : gMatrixFromData_001F2160__as_FxProc_SplashDamage_0_0014A5F0)

void FxProc_SplashDamage_0_0014A5F0(s8 *a0) {
    f32 *q;
    s32 it;
    s8 *p;
    u32 id;
    s32 n;
    s32 ok;
    f32 *pos;
    double dz;
    s8 *e;
    if (*(s32 *)(a0 + 0xA8) == 0) {
        it = 0;
        p = ActorList_Next_2_001A5460__as_FxProc_DropToGround_0_00149D20(&it);
        id = (u32)*(f32 *)(a0 + 0x60);
        while (p) {
            n = 0;
            if (*(u16 *)p != 0 && !Enemy_IsBusy_0_0013EE40(p)) {
                pos = POS(p);
                q = POS(p);
                dz = pow(fptodp(pos[2] - *(f32 *)(a0 + 8)), 2.0);
                n += sqrtf(dptofp(dpadd(pow(fptodp(q[0] - *(f32 *)(a0 + 0)), 2.0), dz))) < *(f32 *)(a0 + 0x50);
                ok = 0;
                if (*(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x54) <= POS(p)[1] && POS(p)[1] <= *(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x58)) {
                    ok = 1;
                }
                n *= ok;
                if (n) {
                    if (id && (e = Sfx_Spawn_2_00169B50(id, 0, 0, 0))) {
                        Sfx_SetPosition_1_00167710__as_FxProc_DropToGround_0_00149D20(e, POS(p));
                    }
                    Proj_SpawnAttack_0_00146A70__as_FxProc_DropToGround_0_00149D20(*(s32 *)(a0 + 0x90), p, 0, (s32)*(f32 *)(a0 + 0x64));
                }
            }
            p = ActorList_Next_2_001A5460__as_FxProc_DropToGround_0_00149D20(&it);
        }
        *(s32 *)(a0 + 0xA8) = 1;
    }
}

/* FxProc_StopLight_0_0014A860_ */

/* FxProc_StopLight_0_0014A860_ */
/* FxProc_StopLight_0_0014A860 */

/* FxProc_StopLight_0_0014A860 */
void FxProc_StopLight_0_0014A860(O_FxProc_StopLight_0_0014A860 *o) {
    if ((s32)o->xB0 != -1) {
        GlowFx_Stop_0_001E0D30(o->x68, (s32)o->xB0);
    }
}

/* FxProc_UpdateLight_0_0014A8A0 */
void FxProc_UpdateLight_0_0014A8A0(O_FxProc_UpdateLight_0_0014A8A0 *o) {
    Vec v;
    Mtx m;
    if (o->x90->x188.f.b2) {
        if ((s32)o->xB0 == -1) {
            o->xB0 = GlowFx_Start_0_001E1050((s32)o->xB0);
        }
    } else {
        if ((s32)o->xB0 != -1) {
            GlowFx_Stop_0_001E0D30(o->x68, (s32)o->xB0);
            o->xB0 = -1.0f;
        }
    }
    if ((s32)o->xB0 != -1) {
        if (o->x114.f.b5) {
            Fx_GetWorldMatrix_1_00163C80__as_FxProc_StopLight_0_0014A860(o, &m);
            sceVu0CopyVector(&v, &m.m[3]);
        } else {
            sceVu0CopyVector(&v, o);
        }
        GlowFx_SetParams_0_001E0F30(o->x60, o->x64, (s32)o->xB0, &v, &o->x50);
    }
}

/* FxProc_InitLight_0_0014A9C0 */

void FxProc_InitLight_0_0014A9C0(O_FxProc_InitChase_0_001493E0__ *o) {
    Vec v;
    Mtx m;

    *(s32 *)((u8 *)o + 0x5C) = 0;
    o->xB0 = -1.0f;
    if (o->x90->x188.b2) {
        if ((s32)o->xB0 == -1) {
            o->xB0 = GlowFx_Start_0_001E1050__as_FxProc_InitLight_0_0014A9C0();
        }
    } else {
        if ((s32)o->xB0 != -1) {
            GlowFx_Stop_0_001E0D30(o->x68, o->xB0);
            o->xB0 = -1.0f;
        }
    }
    if ((s32)o->xB0 != -1) {
        if (o->x114.b5) {
            Fx_GetWorldMatrix_1_00163C80__as_FxProc_InitLight_0_0014A9C0(o, &m);
            sceVu0CopyVector__as_FxProc_InitLight_0_0014A9C0(&v, &m.m[3]);
        } else {
            sceVu0CopyVector__as_FxProc_InitLight_0_0014A9C0(&v, &o->v0);
        }
        GlowFx_SetParams_0_001E0F30(o->x60, o->x64, o->xB0, &v, &o->v50);
    }
}

/* FxProc_FollowPlayer_0_0014AAF0 */

void FxProc_FollowPlayer_0_0014AAF0(Obj_FxProc_StopLight_0_0014A860 *o)
{
    s32 k;
    if (0.0f != o->f60) {
        f32 v = o->fb0;
        o->v[2] = v;
        o->v[1] = v;
        o->v[0] = v;
        o->v[3] = 1.0f;
    }
    k = o->f64;
    if (k == 1) {
        f32 *src;
        if (gPlayerSbss_002022E4__as_FxProc_StopLight_0_0014A860_)
            src = Player_GetPosition_1_00145730(k);
        else
            src = gMatrixFromData_001F2160;
        sceVu0CopyVector__as_FxProc_FollowPlayer_0_0014AAF0((f32 *)o, src);
    }
}

/* FxProc_SeekNearestEnemy_0_0014AB80____ */

/* FxProc_SeekNearestEnemy_0_0014AB80___ */

/* FxProc_SeekNearestEnemy_0_0014AB80__ */

/* FxProc_SeekNearestEnemy_0_0014AB80__ */
/* FxProc_SeekNearestEnemy_0_0014AB80_ */

/* FxProc_SeekNearestEnemy_0_0014AB80_ */
/* FxProc_SeekNearestEnemy_0_0014AB80 */

/* FxProc_SeekNearestEnemy_0_0014AB80 */
void FxProc_SeekNearestEnemy_0_0014AB80(O_FxProc_SeekNearestEnemy_0_0014AB80 *o) {
    Actor *a;
    s32 f;
    f32 pos[4];
    M_FxProc_SeekNearestEnemy_0_0014AB80 m;
    f32 t;

    f = 1;
    if (o->x60 == 0.0f) {
        f = 0;
    }
    if ((s32)o->x64 == 0) {
        if (o->b5) {
            Fx_GetWorldMatrix_1_00163C80__as_FxProc_SeekNearestEnemy_0_0014AB80___(o, &m);
            sceVu0CopyVector(pos, m.v);
        } else {
            sceVu0CopyVector(pos, o);
        }
        a = Proj_FindNearestEnemy_0_00147450(1000.0f, pos);
    } else {
        a = gPlayerSbss_002022E4;
    }
    if (a == NULL) {
        o->x88 = (f32)(u32)(o->b1 = 0);
        ((B2 *)(o->x90 + 0x188))->v = 0;
        return;
    }
    if (*(u16 *)a != 0) {
        sceVu0CopyVector(o, a != NULL ? a->unk518 + 0x90 : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____);
    } else {
        sceVu0CopyVector(o, gPlayerSbss_002022E4 != NULL ? Player_GetPosition_1_00145730__as_FxProc_SeekNearestEnemy_0_0014AB80____() : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____);
    }
    if (f != 0) {
        t = (f32)(u32)*(u16 *)(a->unk4B0 + 4) * o->x60;
        o->x70 = o->x74 = o->x78 = t;
        o->x7C = 1.0f;
        o->xB0 = t;
    }
}

/* FxProc_RandomRingPos_0_0014AD90 */
void FxProc_RandomRingPos_0_0014AD90(f32 *a0) {
    f32 v[4];
    f32 r = a0[0x50 / 4];
    f32 h = a0[0x54 / 4];
    f32 ang = 6.2831855f * (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20__as_FxProc_SeekNearestEnemy_0_0014AB80____() & 0xFFFF));
    r *= 0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20__as_FxProc_SeekNearestEnemy_0_0014AB80____() & 0xFFFF);
    v[0] = r * cosf(ang);
    v[2] = r * sinf(ang);
    v[1] = h * (1.0f - 2.0f * (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20__as_FxProc_SeekNearestEnemy_0_0014AB80____() & 0xFFFF)));
    v[3] = 0.0f;
    sceVu0AddVector__as_FxProc_SeekNearestEnemy_0_0014AB80(a0, a0, v);
}

/* FxProc_AimAlongGround_0_0014AF10 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
inline s32 has_FxProc_SeekNearestEnemy_0_0014AB80_(void) {
    return gPlayerSbss_002022E4 != NULL && gPlayerSbss_002022E4->unk518 != NULL;
}

void FxProc_AimAlongGround_0_0014AF10(O_FxProc_AimAlongGround_0_0014AF10 *o) {
    f32 ang;
    s32 res[4];
    f32 v[4];
    M_FxProc_AimAlongGround_0_0014AF10 m;
    f32 a[4];
    f32 b[4];
    f32 w[4];

    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    Actor_GetYawPitch_1_00145F40__as_FxProc_SeekNearestEnemy_0_0014AB80____((s32)gPlayerSbss_002022E4, &ang, NULL);
    sceVu0RotMatrixY__as_FxProc_SeekNearestEnemy_0_0014AB80_(WRAP(ang), &m, &gMatrixFromData_001F2170__as_FxProc_SeekNearestEnemy_0_0014AB80____);
    sceVu0ApplyMatrix__as_FxProc_SeekNearestEnemy_0_0014AB80____(v, &m, v);
    sceVu0AddVector__as_FxProc_AimAlongGround_0_0014AF10(v, v, has_FxProc_SeekNearestEnemy_0_0014AB80_() ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____);
    v[3] = 1.0f;
    sceVu0CopyMatrix__as_FxProc_SeekNearestEnemy_0_0014AB80_(a, has_FxProc_SeekNearestEnemy_0_0014AB80_() ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____);
    sceVu0CopyVector__as_FxProc_AimAlongGround_0_0014AF10(b, v);
    a[1] = a[1];
    if (Map_LineTest_1_001470F0__as_FxProc_SeekNearestEnemy_0_0014AB80____(a, b, 1, 0x22, 1, res) != 0) {
        o->f88 = o->b1 = 0;
        o->t->b2 = 0;
    }
    sceVu0CopyVector__as_FxProc_AimAlongGround_0_0014AF10(o, v);
    Actor_GetDirNormalized_0_00146570__as_FxProc_SeekNearestEnemy_0_0014AB80____(gPlayerSbss_002022E4, w);
    Mtx_RotateToward_0_00146140__as_FxProc_SeekNearestEnemy_0_0014AB80____((s32)o + 0xC0, w[0], w[2]);
}

/* FxProc_ReleaseChild_0_0014B170 */
void FxProc_ReleaseChild_0_0014B170(T_FxProc_ReleaseChild_0_0014B170 *arg0) {
    volatile s32 sp2C;
    s32 v;

    sp2C = arg0->a8;
    v = sp2C;
    if (v != 0) {
        Sfx_RequestStop_1_00167240(v);
        arg0->a8 = 0;
    }
}

/* FxProc_HomingProjectile_0_0014B1B0 */
static inline f32 u2f_FxProc_SeekNearestEnemy_0_0014AB80(u32 x) { return x; }
static inline void spawn(s32 id, Vec *p) {
    s8 *q = Sfx_Spawn_2_00169B50(id, 0, 0, 0);
    if (q) Sfx_SetPosition_1_00167710__as_FxProc_SeekNearestEnemy_0_0014AB80____(q, p);
}
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define BASE() ((gPlayerSbss_002022E4 != NULL && gPlayerSbss_002022E4->unk518 != NULL) ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____)
static inline s8 *base(void) {
    s32 ok = 0;
    if (gPlayerSbss_002022E4 && gPlayerSbss_002022E4->unk518) ok = 1;
    return ok ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____;
}

void FxProc_HomingProjectile_0_0014B1B0(O_FxProc_SeekNearestEnemy_0_0014AB80_ *o, f32 kk) {
    f32 ang;
    f32 k = kk;
    s32 cc;
    volatile s32 v198;
    volatile s32 v194;
    f32 ang190;
    f32 a18C;
    Mtx m;
    Res r100;
    Res rC0;
    Vec vB0;
    Vec vA0;
    Vec v90;
    Vec v80;
    Vec v70;
    Actor *r;

    f32 lim;
    f32 t;
    f32 d;
    s32 s3;
    s32 s2;
    s32 id;

    Actor *n;
    s32 ok;
    f32 w;
    f32 u;

    s8 *q;
    s8 *pos;

    Actor_GetDir_1_001465C0(gPlayerSbss_002022E4, &v80);
    r = Proj_FindEnemyInCone_0_00146EF0(gFxProcRodata_001FB738[0], base(), 1.5707964f, &v80, 1.5707964f, 1);
    if (r) {
        Actor_GetDir_1_001465C0(gPlayerSbss_002022E4, &v70);
        Vec_GetYawPitchBetween_1_00146310(base(), &v70, r ? r->unk518 + 0x90 : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____, &ang190, NULL);
    } else {
        ang190 = 0.0f;
    }
    Actor_GetYawPitch_1_00145F40__as_FxProc_HomingProjectile_0_0014B1B0(gPlayerSbss_002022E4, &a18C, 0);
    ang = ang190 + a18C;
    ang190 = ang;
    if (3.1415927f < fabsf(ang - o->xB4)) {
        if (ang < o->xB4) {
            w = 6.2831855f;
        } else {
            w = -6.2831855f;
        }
        ang += w;
    }
    ang -= o->xB4;
    u = o->v50.x ? 0.01745f * o->v50.x : 0.0f;


    lim = k * u;
    if (lim < fabsf(ang)) {
        ang = lim * (f32)(ang < 0.0f ? -1 : 1);
    }
    ang += o->xB4;
    o->xB4 = ang;
    t = o->x60;
    sceVu0CopyVector(o, base());
    o->pos.w = 1.0f;
    o->pos.y += o->v50.y;
    o->xB0 += t * k;
    t = atan2f(o->xB0, 190.0f);
    sceVu0RotMatrixX__as_FxProc_SeekNearestEnemy_0_0014AB80____(&m, &gMatrixFromData_001F2170__as_FxProc_HomingProjectile_0_0014B1B0, WRAP(t));
    sceVu0RotMatrixY__as_FxProc_HomingProjectile_0_0014B1B0(WRAP(ang), &m, &m);
    sceVu0CopyMatrix__as_FxProc_HomingProjectile_0_0014B1B0(o->xC0, &m);
    sceVu0ScaleVector__as_FxProc_SeekNearestEnemy_0_0014AB80__(&vB0, o->xD0, 10000.0f);
    sceVu0AddVector__as_FxProc_HomingProjectile_0_0014B1B0(&vB0, &vB0, o);
    s3 = Map_RaycastCapsule_0_00145D10(o, &vB0, 6, 0, &rC0);
    if (s3) {
        sceVu0CopyVector(&vB0, &rC0);
        vB0.w = 1.0f;
    }
    s2 = Map_RaycastSegment_0_00145A80(o, &vB0, 0xFF, 0, &r100);
    if (s2) {
        sceVu0CopyVector(&vB0, &r100);
        vB0.w = 1.0f;
    }
    d = o->v50.z;
    for (n = ActorList_NextB_0_001A5710__as_FxProc_SeekNearestEnemy_0_0014AB80____(); n != NULL; n = ActorList_NextTargetable_0_001A5660__as_FxProc_SeekNearestEnemy_0_0014AB80____()) {
        if (*(u16 *)n && Proj_FindTarget_0_00146C70__as_FxProc_SeekNearestEnemy_0_0014AB80____(o, &vB0, n, &cc, &vA0, d)) {
            ok = 1;
            goto found;
        }
    }
    cc = 0;
    n = NULL;
    ok = 0;
found:
    if (ok) {
        sceVu0CopyVector(&vB0, &vA0);
    }
    if (!s2 && !ok && !s3) {
        o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        return;
    }
    d = o->xB8;
    t = Vec_Distance_3_00146940(o, &vB0);
    if (1.5f * d < t) {
        o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        return;
    }
    o->xB8 = t;
    if (o->xA8 == 0) {
        v198 = (s32)Sfx_Spawn_2_00169B50((s32)o->x68, 0, 0, 0);
        o->xA8 = v198;
    }
    if (ok) {
        id = (u32)o->x6C;
        Proj_SpawnAttack_0_00146A70__as_FxProc_SeekNearestEnemy_0_0014AB80____(o->x90, n, cc, 0x2B);
        if (id) {
            spawn(id, (Vec *)(n ? n->unk518 + 0x90 : gMatrixFromData_001F2160__as_FxProc_SeekNearestEnemy_0_0014AB80____));
        }
        o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        return;
    }
    if (s2 || s3) {
        if (s2) {
            Proj_SpawnFromSource_0_00146980(o->x90, &r100, 0x2B);
            sceVu0CopyVector(&v90, &r100);
            v90.w = 1.0f;
            spawn(0x2D, &v90);
            o->x88 = u2f_FxProc_SeekNearestEnemy_0_0014AB80(o->f114.b1 = 0);
        } else {
            sceVu0CopyVector(&v90, &rC0);
            v90.w = 1.0f;
        }
        if (o->xA8) {
            v194 = o->xA8;
            Sfx_SetPosition_1_00167710__as_FxProc_SeekNearestEnemy_0_0014AB80____((s8 *)v194, &v90);
        }
        o->x74 = Vec_Distance_3_00146940(&v90, o);
    }
}

/* FxProc_InitHoming_0_0014B9E0 */

void FxProc_InitHoming_0_0014B9E0(Obj_FxProc_SeekNearestEnemy_0_0014AB80 *o)
{
    o->scale = 1.0f;
    o->b0 = o->v64;
    o->b8 = 100000.0f;
    o->a8 = 0;
    Actor_GetYawPitch_1_00145F40__as_FxProc_InitHoming_0_0014B9E0(gPlayerSbss_002022E4__as_FxProc_InitHoming_0_0014B9E0, &o->b4, 0);
}

/* FxProc_PullTowardEnemy_0_0014BA10 */
#define POS(p) ((p) ? (f32 *)(*(s32 *)((p) + 0x518) + 0x90) : gMatrixFromData_001F2160__as_FxProc_PullTowardEnemy_0_0014BA10)
static inline s8 *find_FxProc_InitChase_0_001493E0(u16 id) {
    s32 it;
    s8 *p;
    it = 0;
    for (p = ActorList_Next_2_001A5460__as_FxProc_SeekNearestEnemy_0_0014AB80____(&it); p != NULL; p = ActorList_Next_2_001A5460__as_FxProc_SeekNearestEnemy_0_0014AB80____(&it)) {
        if (*(u16 *)p != 0 && (u16)Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_SeekNearestEnemy_0_0014AB80___(p) == id) return p;
    }
    return NULL;
}
static inline s32 ok(void) {
    return gPlayerSbss_002022BC != NULL && *gPlayerSbss_002022BC != NULL;
}

void FxProc_PullTowardEnemy_0_0014BA10(Obj_FxProc_PullTowardEnemy_0_0014BA10 *a0) {
    f32 c[4];
    f32 b[4];
    f32 a[4];
    s8 *p;
    s32 id;
    f32 x60 = a0->x60;
    f32 x68 = a0->x68;
    f32 bc;
    f32 len;

    id = (u16)(u32)a0->xB8;
    if (id != 0) {
        p = find_FxProc_InitChase_0_001493E0(id);
    } else {
        p = NULL;
    }
    if (p != NULL) {
        sceVu0AddVector__as_FxProc_PullTowardEnemy_0_0014BA10(c, POS(p), a0->v50);
        c[3] = 1.0f;
        if (Vec_Distance_3_00146940__as_FxProc_PullTowardEnemy_0_0014BA10(a0, c) < x68) {
            EnemyScr_Event2015_1_00141510(p, ok() ? **gPlayerSbss_002022BC : 0, 3, 0);
            a0->x88 = (f32)(u32)(a0->x114.b1 = 0);
        }
        bc = a0->xBC;
        sceVu0SubVector__as_FxProc_SeekNearestEnemy_0_0014AB80___(b, c, (f32 *)a0);
        len = sqrtf(sceVu0InnerProduct__as_FxProc_SeekNearestEnemy_0_0014AB80____(a0->v10, a0->v10));
        sceVu0Normalize__as_FxProc_InitChase_0_001493E0___(a, b);
        sceVu0ScaleVector__as_FxProc_PullTowardEnemy_0_0014BA10(a, a, -1.0f * bc);
        sceVu0AddVector__as_FxProc_PullTowardEnemy_0_0014BA10(a0->v10, a0->v10, a);
        sceVu0Normalize__as_FxProc_InitChase_0_001493E0___(a0->v10, a0->v10);
        sceVu0ScaleVector__as_FxProc_PullTowardEnemy_0_0014BA10(a0->v10, a0->v10, len);
        a0->xBC -= x60;
    }
}

/* FxProc_TrackEnemyBone_0_0014BC90 */
static inline f32 u2f_FxProc_TrackEnemyBone_0_0014BC90(u32 x) { return x; }

void FxProc_TrackEnemyBone_0_0014BC90(Obj_FxProc_InitChase_0_001493E0_ *a) {
    s32 it;
    Vec d;
    Vec t;
    Vec s;
    Mtx m;
    u16 id;
    u16 *p;
    f32 k;
    f32 r;

    r = 0.05f;
    id = a->x64;
    it = 0;
    for (p = ActorList_Next_2_001A5460__as_FxProc_TrackEnemyBone_0_0014BC90(&it); p != 0; p = ActorList_Next_2_001A5460__as_FxProc_TrackEnemyBone_0_0014BC90(&it)) {
        if (*p != 0 && *p == id) break;
    }
    if (p) {
        a->xB8 = u2f_FxProc_TrackEnemyBone_0_0014BC90(Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_TrackEnemyBone_0_0014BC90(p));
    } else {
        a->xB8 = 0.0f;
    }
    if (p) {
        sceVu0CopyVector(&t, Enemy_Ptr6F0_1_0013FFA0(p));
        if (a->f114.b5) {
            Fx_GetWorldMatrix_1_00163C80__as_FxProc_TrackEnemyBone_0_0014BC90(a, &m);
            sceVu0CopyVector(&s, &m.m[3]);
        } else {
            sceVu0CopyVector(&s, a);
        }
        sceVu0SubVector__as_FxProc_TrackEnemyBone_0_0014BC90(&d, &t, &s);

        k = (r - sqrtf(d.x * d.x + d.z * d.z)) / (2.0f * (f32)r);
        k *= 0.001f;
    } else {
        k = 0.0f;
    }
    a->xBC = k;
}

/* FxProc_SpawnTimed_0_0014BE70__ */

/* FxProc_SpawnTimed_0_0014BE70_ */

/* FxProc_SpawnTimed_0_0014BE70_ */
/* FxProc_SpawnTimed_0_0014BE70 */

/* FxProc_SpawnTimed_0_0014BE70 */
/* FxProc_SpawnTimed_0_0014BE70 */
/* FxProc_SpawnTimed_0_0014BE70 */
/* FxProc_SpawnTimed_0_0014BE70 */
static inline f32 u2f_FxProc_SpawnTimed_0_0014BE70(u32 x) { return x; }

void FxProc_SpawnTimed_0_0014BE70(O_FxProc_SpawnTimed_0_0014BE70 *o) {
    s32 id;
    s8 *p;
    if (o->xBC && o->xB4 < o->x4) {
        id = o->x60;
        o->x88 = u2f_FxProc_SpawnTimed_0_0014BE70(o->x114.b1 = 0);
        if (Sfx_IsLoaded_2_00169BB0(id)) {
            p = Sfx_Spawn_2_00169B50(id, 0, 0, 0);
            if (p) Sfx_SetPosition_1_00167710(p, (u8 *)o + 0xB0);
        }
    }
}

/* FxProc_SnapToGround_0_0014BF60 */
void FxProc_SnapToGround_0_0014BF60(f32 *o) {
    s32 fl;
    Vec a;
    Vec b;
    f32 z;
    fl = 0;
    if (o[0x19] == 0.0f) fl = 0x80;
    if (o[0x19] == 1.0f) fl = 4;
    if (o[0x19] == 2.0f) fl = 0x84;
    z = 0.0f;
    a.x = o[0];
    a.y = o[1] - z;
    a.z = o[2];
    b.x = o[0];
    b.y = o[1] + (z = 10000.0f);
    b.z = o[2];
    b.w = 1.0f;
    a.w = 1.0f;
    o[0x2F] = Map_LineTest_1_001470F0__as_FxProc_SpawnTimed_0_0014BE70__(&a, &b, 1, fl, 1, (Vec *)(o + 0x2C));
}

/* FxProc_AttachRotated_0_0014C060 */
void FxProc_AttachRotated_0_0014C060(Obj_FxProc_SpawnTimed_0_0014BE70 *o)
{
    f32 m[4][4];
    f32 v[4];
    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    Actor_BuildRotMatrix_0_00146600(gPlayerSbss_002022E4__as_FxProc_SpawnTimed_0_0014BE70, m);
    sceVu0ApplyMatrix__as_FxProc_SpawnTimed_0_0014BE70__((f32 *)o, m, v);
    sceVu0CopyMatrix__as_FxProc_SpawnTimed_0_0014BE70__(o->m, m);
    sceVu0CopyVector__as_FxProc_SpawnTimed_0_0014BE70(o->v, gMatrixFromData_001F2160);
}

/* FxProc_AttachRotatedB_0_0014C0E0 */
void FxProc_AttachRotatedB_0_0014C0E0(Obj_FxProc_SpawnTimed_0_0014BE70 *o)
{
    f32 m[4][4];
    f32 v[4];
    v[0] = o->x;
    v[1] = o->y;
    v[2] = o->z;
    v[3] = 1.0f;
    Actor_BuildRotMatrix_0_00146600(gPlayerSbss_002022E4__as_FxProc_SpawnTimed_0_0014BE70, m);
    sceVu0ApplyMatrix__as_FxProc_SpawnTimed_0_0014BE70__((f32 *)o, m, v);
    sceVu0CopyMatrix__as_FxProc_SpawnTimed_0_0014BE70__(o->m, m);
    sceVu0CopyVector__as_FxProc_SpawnTimed_0_0014BE70(o->v, gMatrixFromData_001F2160);
}

/* FxProc_RandomWander_0_0014C160 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 u2f_FxProc_RandomWander_0_0014C160(u32 x) { return x; }

void FxProc_RandomWander_0_0014C160(O_FxProc_RandomWander_0_0014C160 *o) {
    Mtx m;
    Vec lo;
    Vec hi;
    s32 ok;
    f32 up;
    f32 dn;
    f32 a;
    f32 rx;

    o->p.x += o->x50 * ((0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()) - 0.5f);
    o->p.z += o->x58 * ((0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()) - 0.5f);
    if (o->x68) {
        ok = 1;
    } else {
        up = (0.0f < o->x64) ? o->x64 : 1000.0f;
        dn = (0.0f < o->x64) ? o->x64 : 1000.0f;
        lo.x = o->p.x;
        lo.y = o->p.y - dn;
        lo.z = o->p.z;
        hi.x = o->p.x;
        hi.y = o->p.y + up;
        hi.z = o->p.z;
        hi.w = 1.0f;
        lo.w = 1.0f;
        ok = Map_LineTest_1_001470F0__as_FxProc_RandomWander_0_0014C160(&lo, &hi, 3, 4, 1, o);
    }
    o->p.y += o->x54;
    if (!ok) {
        o->x88 = u2f_FxProc_RandomWander_0_0014C160(o->f114.b1 = 0);
        return;
    }
    rx = 0.0f;
    if (rx == o->x60) return;
    rx = (o->x60 != rx) ? 0.01745f * o->x60 : rx;
    a = 0.5f * rx;
    sceVu0RotMatrixZ(&m, &gMatrixFromData_001F2170, WRAP(a * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20())));
    sceVu0RotMatrixY__as_FxProc_SpawnTimed_0_0014BE70__(&m, &m, WRAP(6.2831855f * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20())));
    sceVu0CopyMatrix__as_FxProc_RandomWander_0_0014C160(o->xC0, &m);
}

/* FxProc_ScaleByDistance_0_0014C6F0 */
inline s32 has_FxProc_InitChase_0_001493E0(void) {
    return gPlayerSbss_002022E4 != NULL && gPlayerSbss_002022E4->unk518 != NULL;
}

void FxProc_ScaleByDistance_0_0014C6F0(O_FxProc_SpawnTimed_0_0014BE70_ *o) {
    f32 a, b, c, d;
    f32 pos[4];
    M_FxProc_SpawnTimed_0_0014BE70_ m;
    f32 t;
    P_FxProc_SpawnTimed_0_0014BE70 *p;

    a = o->x60;
    b = o->x64;
    c = o->x68;
    d = o->x6C;
    if (o->b5) {
        Fx_GetWorldMatrix_1_00163C80__as_FxProc_SpawnTimed_0_0014BE70_(o, &m);
        sceVu0CopyVector(pos, m.v);
    } else {
        sceVu0CopyVector(pos, o);
    }
    t = Vec_Distance_3_00146940__as_FxProc_SpawnTimed_0_0014BE70__(pos, has_FxProc_InitChase_0_001493E0() ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_ScaleByDistance_0_0014C6F0);
    if (c < t) {
        a = a;
    } else if (t < d) {
        a = b;
    } else {
        a = b + (a - b) * (t - d) / (c - d);
    }
    p = o->x90->tbl[o->x94];
    if (p->f & 0x10) {
        o->x4C = o->x4C * a;
    } else {
        o->x4C = a * p->xAC;
    }
    if (127.0f < o->x4C) {
        o->x4C = 127.0f;
    }
}

/* FxProc_SetDone_0_0014C870 */
/* Bitfield setter on an object's flag byte at 0x114. */


void FxProc_SetDone_0_0014C870(Obj_FxProc_SetDone_0_0014C870 *o)
{
    o->f = 1;
}

/* FxProc_RandomJitter_0_0014C890__ */

/* FxProc_RandomJitter_0_0014C890_ */

/* FxProc_RandomJitter_0_0014C890_ */
/* FxProc_RandomJitter_0_0014C890_ */
/* FxProc_RandomJitter_0_0014C890 */

static inline f32 sc(f32 x) { return x ? 0.01745f * x : 0.0f; }
void FxProc_RandomJitter_0_0014C890(O_FxProc_RandomJitter_0_0014C890 *o) {
    f32 v[4];
    M_FxProc_RandomJitter_0_0014C890_ m;
    s32 i;

    f32 *r;
    f32 *q;
    f32 *p;

    p = v;
    q = p;
    r = (f32 *)o;
    for (i = 0; i < 3; i++) {
        *q++ = r[0x18] * (0.000015259022f * (f32)(Rand_Next_3_0015ED20__as_FxProc_RandomJitter_0_0014C890__() & 0xFFFF) - 0.5f);
        r++;
    }
    v[3] = 0.0f;
    Fx_GetWorldMatrix_1_00163C80__as_FxProc_RandomJitter_0_0014C890__(o, &m);
    sceVu0ApplyMatrix__as_FxProc_RandomJitter_0_0014C890(v, &m, v);
    o->pos[0] += p[0];
    o->pos[1] += v[1];
    o->pos[2] += v[2];
    if (o->ang != -1.0f) {
        for (i = 0; i < 3; i++) {
            o->rot[i] = 0.000015259022f * (f32)(Rand_Next_3_0015ED20__as_FxProc_RandomJitter_0_0014C890__() & 0xFFFF);
        }
        o->rz += (0.000015259022f * (f32)(Rand_Next_3_0015ED20__as_FxProc_RandomJitter_0_0014C890__() & 0xFFFF) - 0.5f) * sc(o->ang);
    }
}

/* FxProc_AimAtEnemyCone_0_0014CAC0 */
static inline f32 u2f_FxProc_RandomJitter_0_0014C890(u32 x) { return x; }

void FxProc_AimAtEnemyCone_0_0014CAC0(Obj_FxProc_RandomJitter_0_0014C890 *a) {
    f32 ang;
    Vec p;
    Vec f;
    Vec e;
    Vec d;
    Mtx m;
    Info s;
    Vec lo;
    Vec hi;
    f32 x;
    f32 deg;
    s32 ok;
    s8 *base;
    f32 u;
    Actor *r;

    deg = 0.0f;
    x = a->x60;
    if (a->x64 != deg) {
        deg = 0.01745f * a->x64;
    }
    Actor_GetDirNormalized_0_00146570__as_FxProc_SpawnTimed_0_0014BE70__(gPlayerSbss_002022E4, &f);
    ok = 0;
    if (gPlayerSbss_002022E4 && gPlayerSbss_002022E4->unk518) {
        ok = 1;
    }
    base = ok ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_RandomJitter_0_0014C890__;
    r = Proj_FindEnemyInCone_0_00146EF0(x, base, 3.1415927f, &f, deg, 0);
    if (r) {
        sceVu0CopyVector(&p, r ? r->unk518 + 0x90 : gMatrixFromData_001F2160__as_FxProc_RandomJitter_0_0014C890__);
    } else {
        sceVu0CopyVector(&e, &a->v50);
        e.w = 1.0f;
        Actor_GetYawPitch_1_00145F40__as_FxProc_SpawnTimed_0_0014BE70__(gPlayerSbss_002022E4, &ang, 0);
        Player_GetPos_1_001C9410(&d);
        sceVu0RotMatrixY__as_FxProc_RandomJitter_0_0014C890__((3.1415927f + ang) - 6.2831855f * (f32)(s32)((3.1415927f + ang) * 0.15915494f) + ((3.1415927f + ang) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f, &m, gMatrixFromData_001F2170__as_FxProc_RandomJitter_0_0014C890__);
        sceVu0ApplyMatrix__as_FxProc_AimAtEnemyCone_0_0014CAC0(&e, &m, &e);
        sceVu0AddVector__as_FxProc_RandomJitter_0_0014C890_(&e, &e, &d);
        sceVu0CopyVector(&p, &e);
    }
    hi.x = lo.x = p.x;
    u = 200.0f;
    lo.y = p.y - u;
    lo.z = p.z;
    lo.w = hi.w = 1.0f;
    hi.y = p.y + u;
    hi.z = p.z;
    if (Map_LineTest_1_001470F0__as_FxProc_RandomJitter_0_0014C890__(&lo, &hi, 1, 4, 1, &p)) {
        sceVu0CopyVector(a, &p);
        a->pos.y -= 5.0f;
        Actor_BuildRotMatrix_0_00146600__as_FxProc_RandomJitter_0_0014C890__(gPlayerSbss_002022E4, &s);
        Mtx_RotateToward_0_00146140(a->xC0, s.x20, s.x28);
        return;
    }
    a->x88 = u2f_FxProc_RandomJitter_0_0014C890(a->f114.b1 = 0);
    a->p90->f188.b2 = 0;
}

/* FxProc_StopAtWall_0_0014CDC0 */
void FxProc_StopAtWall_0_0014CDC0(O_FxProc_StopAtWall_0_0014CDC0 *o) {
    Vec out;
    Vec a;
    Vec b;
    f32 h = o->x64;

    a.x = o->p.x;
    a.y = o->p.y - h;
    a.z = o->p.z;
    b.x = o->p.x;
    b.y = o->p.y + h;
    b.z = o->p.z;
    b.w = 1.0f;
    a.w = 1.0f;
    if (Map_LineTest_1_001470F0__as_FxProc_RandomJitter_0_0014C890__(&a, &b, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
        return;
    }
    o->x88 = (f32)(u32)(o->f114.b1 = 0);
}

/* FxProc_SlideOnSurface_0_0014CEC0 */

void FxProc_SlideOnSurface_0_0014CEC0(O_FxProc_RandomJitter_0_0014C890_ *o) {
    Vec out;
    Vec lo;
    Vec hi;
    f32 h;
    f32 s;
    f32 r;
    h = o->x60;
    lo.x = o->p.x;
    lo.y = o->p.y - h;
    lo.z = o->p.z;
    hi.x = o->p.x;
    hi.y = o->p.y + h;
    hi.z = o->p.z;
    hi.w = 1.0f;
    lo.w = 1.0f;
    if (Map_LineTest_1_001470F0__as_FxProc_RandomJitter_0_0014C890__(&lo, &hi, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
        s = sqrtf(sceVu0InnerProduct__as_FxProc_SpawnTimed_0_0014BE70__(&o->v, &o->v));
        o->v.y = 0;
        r = s / sqrtf(sceVu0InnerProduct__as_FxProc_SpawnTimed_0_0014BE70__(&o->v, &o->v));
        o->v.x *= r;
        o->v.z *= r;
        Mtx_RotateToward_0_00146140__as_FxProc_SlideOnSurface_0_0014CEC0(&o->c0, o->xE0, o->xE8);
    } else {
        o->x88 = (f32)(u32)(o->b1 = 0);
    }
}

/* FxProc_AimAtBestTarget_0_0014D020 */
static inline f32 u2f_FxProc_AimAtBestTarget_0_0014D020(u32 x) { return x; }

void FxProc_AimAtBestTarget_0_0014D020(Obj_FxProc_AimAtBestTarget_0_0014D020 *a) {
    f32 ang;
    Vec p;
    Vec e;
    Mtx m;
    Vec hit;
    Vec lo;
    Vec hi;
    Info s;
    Mtx q;
    f32 dy;
    f32 deg;
    Actor *r;
    s32 ok;
    s32 ok2;
    f32 x;
    s8 *base;

    deg = 0.0f;
    x = a->x60;
    deg = (a->x64 != deg) ? 0.01745f * a->x64 : deg;
    dy = a->x68;
    base = gPlayerSbss_002022E4 ? gPlayerSbss_002022E4->unk518 + 0x20 : gMatrixFromData_001F2150;
    r = Proj_FindBestTarget_0_001472A0(a, x, deg, base, 0.0f, 0);
    if (r) {
        sceVu0CopyVector(&p, r ? r->unk518 + 0x90 : gMatrixFromData_001F2160__as_FxProc_RandomJitter_0_0014C890__);
    } else {
        sceVu0CopyVector(&e, &a->v50);
        e.w = 1.0f;
        Actor_GetYawPitch_1_00145F40__as_FxProc_SpawnTimed_0_0014BE70__(gPlayerSbss_002022E4, &ang, 0);
        sceVu0RotMatrixY__as_FxProc_RandomJitter_0_0014C890__((3.1415927f + ang) - (f32)(s32)((3.1415927f + ang) * 0.15915494f) * 6.2831855f + ((3.1415927f + ang) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f, &m, gMatrixFromData_001F2170__as_FxProc_RandomJitter_0_0014C890__);
        sceVu0ApplyMatrix__as_FxProc_AimAtBestTarget_0_0014D020(&e, &m, &e);
        ok = 0;
        if (gPlayerSbss_002022E4 && gPlayerSbss_002022E4->unk518) {
            ok = 1;
        }
        sceVu0AddVector__as_FxProc_SpawnTimed_0_0014BE70__(&e, &e, ok ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_RandomJitter_0_0014C890__);
        sceVu0CopyVector(&p, &e);
    }
    ok2 = 0;
    if (gPlayerSbss_002022E4 && gPlayerSbss_002022E4->unk518) {
        ok2 = 1;
    }
    sceVu0CopyMatrix__as_FxProc_RandomJitter_0_0014C890__(&lo, ok2 ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_RandomJitter_0_0014C890__);
    sceVu0CopyVector(&hi, &p);
    hi.y += dy;
    if (Map_LineTest_1_001470F0__as_FxProc_RandomJitter_0_0014C890__(&lo, &hi, 1, 0x22, 0, &hit)) {
        a->x88 = u2f_FxProc_AimAtBestTarget_0_0014D020(a->f114.b1 = 0);
        a->p90->f188.b2 = 0;
    }
    sceVu0CopyVector(a, &hi);
    Actor_BuildRotMatrix_0_00146600__as_FxProc_RandomJitter_0_0014C890__(gPlayerSbss_002022E4, &s);
    Mtx_RotateToward_0_00146140__as_FxProc_AimAtBestTarget_0_0014D020(&q, s.x20, s.x28);
    sceVu0CopyMatrix__as_FxProc_RandomJitter_0_0014C890__(&a->xC0, &q);
}

/* FxProc_MoveToward_0_0014D310_ */

/* FxProc_MoveToward_0_0014D310_ */
/* FxProc_MoveToward_0_0014D310_ */
/* FxProc_MoveToward_0_0014D310 */
inline s32 has_FxProc_MoveToward_0_0014D310(void) {
    return gPlayerSbss_002022E4 != NULL && gPlayerSbss_002022E4->unk518 != NULL;
}

void FxProc_MoveToward_0_0014D310(O_FxProc_MoveToward_0_0014D310 *o) {
    Vec t;
    Vec u;
    f32 d;
    f32 r;
    f32 len;

    d = o->x60;
    r = o->xBC;
    sceVu0SubVector__as_FxProc_MoveToward_0_0014D310(&t, has_FxProc_MoveToward_0_0014D310() ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160__as_FxProc_MoveToward_0_0014D310_, o);
    len = sqrtf(sceVu0InnerProduct__as_FxProc_MoveToward_0_0014D310_(&o->v10, &o->v10));
    sceVu0Normalize__as_FxProc_MoveToward_0_0014D310_(&u, &t);
    sceVu0ScaleVector__as_FxProc_MoveToward_0_0014D310_(&u, &u, -1.0f * r);
    sceVu0AddVector__as_FxProc_MoveToward_0_0014D310_(&o->v10, &o->v10, &u);
    sceVu0Normalize__as_FxProc_MoveToward_0_0014D310_(&o->v10, &o->v10);
    sceVu0ScaleVector__as_FxProc_MoveToward_0_0014D310_(&o->v10, &o->v10, len);
    o->xBC -= d;
}

/* FxProc_InitTowardEnemy_0_0014D410 */
void FxProc_InitTowardEnemy_0_0014D410(O_FxProc_InitTowardEnemy_0_0014D410 *arg0) {
    Vec sp30;
    Vec sp20;
    f32 d;
    sceVu0CopyVector__as_FxProc_MoveToward_0_0014D310_(&sp20, Enemy_Ptr6F0_1_0013FFA0__as_FxProc_MoveToward_0_0014D310_(gPlayerSbss_002022E4__as_FxProc_InitTowardEnemy_0_0014D410));
    sceVu0SubVector__as_FxProc_InitTowardEnemy_0_0014D410(&sp30, &sp20, &arg0->v);
    d = sqrtf(sp30.x * sp30.x + sp30.z * sp30.z);
    d = (0.05f - d) / 0.1f; d *= 0.001f; arg0->xBC = d;
}

/* FxProc_SeekEnemyInCone_0_0014D4A0 */
static inline s8 *find_FxProc_MoveToward_0_0014D310(s32 *it, K *k) {
    s8 *p;
    u16 kid;
    *it = 0;
    p = ActorList_Next_2_001A5460__as_FxProc_MoveToward_0_0014D310_(it);
    if (p != NULL) {
    kid = k->s.id;
    do {
        if (*(u16 *)p != 0 && Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_MoveToward_0_0014D310_(p) == kid) {
            return p;
        }
        p = ActorList_Next_2_001A5460__as_FxProc_MoveToward_0_0014D310_(it);
    } while (p != NULL);
    }
    return NULL;
}

void FxProc_SeekEnemyInCone_0_0014D4A0(O_FxProc_MoveToward_0_0014D310_ *o) {
    K k;
    s32 it;
    K k2;
    Vec b0;
    M_FxProc_MoveToward_0_0014D310 m;
    Vec v60;
    Vec v50;
    s8 *p;
    u16 id;
    f32 s;
    f32 h;
    f32 t;

    k.w = o->xA8.w;
    p = NULL;
    if (*(u16 *)&k != 0) {
        p = find_FxProc_MoveToward_0_0014D310(&it, &k);
    }
    if (p == NULL || (p != NULL && Enemy_IsBusy_0_0013EE40(p) != 0)) {
        Fx_GetWorldMatrix_1_00163C80__as_FxProc_MoveToward_0_0014D310_(o, &m);
        p = Proj_FindEnemyInCone_0_00146EF0__as_FxProc_MoveToward_0_0014D310_(gFxProcRodata_001FB738[0], &m.b, 1.5707964f, &m.a, 1.5707964f, 1);
        if (p != NULL) {
            s = o->xB0.w;
            id = Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_MoveToward_0_0014D310_(p);
            k2.w = o->xA8.w;
            k2.s.id = id;
            k2.s.f2 = id == 0 && k2.s.f2 == 1;
            k2.s.f3 = 0;
            o->xA8.w = k2.w;
            o->xB0.w = s;
        }
    }
    if (p != NULL) {
        sceVu0CopyVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(&b0, Enemy_Ptr6F0_1_0013FFA0__as_FxProc_SeekEnemyInCone_0_0014D4A0(p));
    } else if (k.s.f2) {
        sceVu0CopyVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(&b0, &o->xB0);
        b0.w = 1.0f;
    }
    if (p != NULL || k.s.f2) {
        h = o->x60;
        t = o->xB0.w;
        sceVu0SubVector__as_FxProc_SeekEnemyInCone_0_0014D4A0(&v60, &b0, o);
        s = sqrtf(sceVu0InnerProduct__as_FxProc_MoveToward_0_0014D310_(&o->v, &o->v));
        sceVu0Normalize__as_FxProc_MoveToward_0_0014D310_(&v50, &v60);
        sceVu0ScaleVector__as_FxProc_MoveToward_0_0014D310_(&v50, &v50, -1.0f * t);
        sceVu0AddVector__as_FxProc_MoveToward_0_0014D310_(&o->v, &o->v, &v50);
        sceVu0Normalize__as_FxProc_MoveToward_0_0014D310_(&o->v, &o->v);
        sceVu0ScaleVector__as_FxProc_MoveToward_0_0014D310_(&o->v, &o->v, s);
        o->xB0.w = o->xB0.w - h;
    }
}

/* FxProc_InitSeekCone_0_0014D700 */

void FxProc_InitSeekCone_0_0014D700(O_FxProc_InitSeekCone_0_0014D700 *o) {
    K k;
    K k2;
    Vec b0;
    Vec a0;
    Vec v90;
    Vec v80;
    MtxB m;
    s8 *p;
    u16 id;
    f32 t;

    k.s.id = 0;
    k.s.f3 = 0;
    k.s.f2 = 1;
    o->xA8.w = k.w;
    sceVu0CopyVector__as_FxProc_InitSeekCone_0_0014D700(&b0, &o->x90->b);
    b0.w = 1.0f;
    sceVu0CopyVector__as_FxProc_InitSeekCone_0_0014D700(&a0, &o->x90->a);
    p = Proj_FindEnemyInCone_0_00146EF0__as_FxProc_MoveToward_0_0014D310_(gFxProcRodata_001FB738[0], &b0, 1.5707964f, &a0, 1.5707964f, 1);
    if (p != NULL) {
        sceVu0CopyVector__as_FxProc_InitSeekCone_0_0014D700(&v80, Enemy_Ptr6F0_1_0013FFA0__as_FxProc_InitSeekCone_0_0014D700(p));
        sceVu0SubVector__as_FxProc_InitSeekCone_0_0014D700(&v90, &v80, o);
        t = (0.05f - sqrtf(v90.x * v90.x + v90.z * v90.z)) / 0.1f;
        t *= 0.001f;
        id = Enemy_GetCurrentParamIdx_0_0013E110__as_FxProc_MoveToward_0_0014D310_(p);
    } else {
        o->x50.w = 1.0f;
        Actor_BuildRotMatrix_0_00146600__as_FxProc_MoveToward_0_0014D310_(gPlayerSbss_002022E4, &m);
        sceVu0ApplyMatrix__as_FxProc_MoveToward_0_0014D310_(&o->xB0, &m, &o->x50);
        t = 0.0f;
        id = 0;
    }
    k2.w = o->xA8.w;
    k2.s.id = id;
    k2.s.f2 = id == 0 && k2.s.f2 == 1;
    k2.s.f3 = 0;
    o->xA8.w = k2.w;
    o->xB0.w = t;
}

/* FxTable_GetEntry_0_0014D8A0 */
/* FxTable_GetEntry_0_0014D8A0 */
void FxTable_GetEntry_0_0014D8A0(S *a0, u16 i) {
    S t;
    t.v = gFxProcData_001F1E60[i];
    *a0 = t;
}

/* FxTable_CallA_0_0014D8E0 */
s32 FxTable_CallA_0_0014D8E0(u16 i, s32 v)
{
    if (i >= 29)
        return 0;
    gFxProcData_001F1EA0[i].c(v);
    return 1;
}

/* FxTable_CallB_0_0014D940 */
s32 FxTable_CallB_0_0014D940(u16 i, s32 v)
{
    if (i >= 29)
        return 0;
    gFxProcData_001F1EA0[i].b(v);
    return 1;
}

/* FxTable_CallC_0_0014D9A0 */
s32 FxTable_CallC_0_0014D9A0(u16 i, s32 v)
{
    if (i >= 29)
        return 0;
    gFxProcData_001F1EA0[i].a(v);
    return 1;
}

/* FxProc_NopA_2_0014DA00 */
#define gZeroVec_003139A0 gZeroVec_003139A0__as_FxProc_NopA_2_0014DA00
extern f32 gZeroVec_003139A0__as_FxProc_NopA_2_0014DA00[4];
#define sceVu0CopyVector sceVu0CopyVector__as_FxProc_NopA_2_0014DA00
void sceVu0CopyVector__as_FxProc_NopA_2_0014DA00(f32 *v0, f32 *v1);

/* FxProc_NopA_2_0014DA00 */
void FxProc_NopA_2_0014DA00(void) {

}

/* FxProc_NopB_2_0014DA10 */
void FxProc_NopB_2_0014DA10(void) {

}

/* FxProc_NopC_2_0014DA20 */
void FxProc_NopC_2_0014DA20(void) {

}

/* FxProc_InitAtOrigin_0_0014DA30 */
void FxProc_InitAtOrigin_0_0014DA30(Obj_FxProc_NopA_2_0014DA00 *o)
{
    sceVu0CopyVector(o->v, gZeroVec_003139A0);
    o->a8 = 0;
}
#undef sceVu0CopyVector
#undef gZeroVec_003139A0

#ifdef NONMATCHING
#pragma explicit_zero_data on
void FxProc_ChaseEnemy_0_00148D00(void);
void FxProc_FollowEnemy_0_001489B0(void);
void FxProc_OrientToVelocity_0_00148120(void);
void FxProc_RandomSpin_0_001484D0(void);
void FxProc_SpawnRandomChild_0_00148B30(void);
void Proj_AttachToBoneB_0_001475F0(void);
void Proj_AttachToBone_0_00147510(void);
void Proj_ReleaseEffect_0_001476D0(void);
void Proj_UpdateHoming_0_00147710(void);
void Proj_Update_0_00147E90(void);
/* data group (src/game/data/fx_proc_data.c): D_001F1EA0__grp: gFxProcData_001F1EA0@0x0, gFxProcData_001F1EA4@0x4, gFxProcData_001F1EA8@0x8 */
s32 D_001F1EA0__grp[0x58] __attribute__((aligned(16))) = { (s32)FxProc_InitAtOrigin_0_0014DA30, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitAtOrigin_0_0014DA30, (s32)FxProc_NopB_2_0014DA10, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitSeekCone_0_0014D700, (s32)FxProc_SeekEnemyInCone_0_0014D4A0, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitTowardEnemy_0_0014D410, (s32)FxProc_MoveToward_0_0014D310, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_AimAtBestTarget_0_0014D020, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_SlideOnSurface_0_0014CEC0, (s32)FxProc_StopAtWall_0_0014CDC0, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_AimAtEnemyCone_0_0014CAC0, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_RandomJitter_0_0014C890, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_SetDone_0_0014C870, (s32)FxProc_ScaleByDistance_0_0014C6F0, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_RandomWander_0_0014C160, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_AttachRotatedB_0_0014C0E0, (s32)FxProc_AttachRotated_0_0014C060, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_SnapToGround_0_0014BF60, (s32)FxProc_SpawnTimed_0_0014BE70, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_TrackEnemyBone_0_0014BC90, (s32)FxProc_PullTowardEnemy_0_0014BA10, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitHoming_0_0014B9E0, (s32)FxProc_HomingProjectile_0_0014B1B0, (s32)FxProc_ReleaseChild_0_0014B170, (s32)FxProc_AimAlongGround_0_0014AF10, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_RandomRingPos_0_0014AD90, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_SeekNearestEnemy_0_0014AB80, (s32)FxProc_FollowPlayer_0_0014AAF0, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitLight_0_0014A9C0, (s32)FxProc_UpdateLight_0_0014A8A0, (s32)FxProc_StopLight_0_0014A860, (s32)FxProc_InitAtOrigin_0_0014DA30, (s32)FxProc_SplashDamage_0_0014A5F0, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_ScatterAround_0_0014A210, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_RandomBounce_0_00149EB0, (s32)FxProc_DropToGround_0_00149D20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitAreaDamage_0_00149CC0, (s32)FxProc_AreaDamageWrap_0_00149CB0, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitAtOrigin_0_0014DA30, (s32)FxProc_FireAtTarget_0_001494A0, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitChase_0_001493E0, (s32)FxProc_ChaseEnemy_0_00148D00, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_InitAtOrigin_0_0014DA30, (s32)FxProc_SpawnRandomChild_0_00148B30, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_FollowEnemy_0_001489B0, (s32)FxProc_NopC_2_0014DA20, (s32)FxProc_NopA_2_0014DA00, (s32)FxProc_RandomSpin_0_001484D0, (s32)FxProc_OrientToVelocity_0_00148120, (s32)FxProc_NopA_2_0014DA00, (s32)Proj_Update_0_00147E90, (s32)Proj_UpdateHoming_0_00147710, (s32)Proj_ReleaseEffect_0_001476D0, (s32)Proj_AttachToBoneB_0_001475F0, (s32)Proj_AttachToBone_0_00147510, (s32)FxProc_NopA_2_0014DA00, 0 };
#endif
