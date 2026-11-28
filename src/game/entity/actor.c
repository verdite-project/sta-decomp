#include "m2c.h"
#include "common.h"
#include "actor.h"
#include "include_asm.h"
#include "game/effect.h"
#include "game/input.h"
#include "game/math.h"
#include "game/player.h"
#include "game/data.h"
typedef union { u128 q; Vec v; } QV;
typedef union { u64 d; struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } b; } F;
typedef struct { Mtx m; Mtx x40; Mtx x80; u8 padC0[0x70]; u8 x130; u8 x131; u8 pad132[6]; F f; } Bone;
typedef struct { u8 pad[6]; u16 h6; u8 pad8[0x1C]; u8 lo:6; u8 c:2; u8 pad25[0xB]; Vec x30; } Hdr;
typedef struct { u8 pad[0x2A]; u8 x2A; u8 pad2B; u8 t:3; } Res_Actor_UpdateBones_0_001370A0;
typedef struct { u8 pad[0x180]; u8 x180[0x1C]; s8 *x19C; u8 pad1A0[8]; Hdr *x1A8; } Sub;
typedef struct { u8 pad[0x9A]; u8 x9A[0x47E]; Sub *x518; } A;
typedef struct { u8 pad[0x2AD]; u8 lo:3; u8 b3:1; } Q_Actor_UpdateBones_0_001370A0;
typedef struct { f32 v[9]; } F9;
typedef struct { u8 pad[6]; u16 n; } H;
typedef struct { Vec a; Vec b; u8 pad20[4]; s32 x24; u8 pad28[0x18]; } Big;
typedef struct { Vec p; Vec d; } Seg_Combat_TraceWeaponHit_0_00138CA0;
typedef struct { Vec a; Vec b; f32 c[2]; s32 hit; f32 pad; } Res_Combat_TraceWeaponHit_0_00138CA0;
typedef struct { u128 q[3]; } R3;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[2]; u16 xE; } Info;
typedef struct { u8 pad[0x7C]; s32 x7C; u8 pad80[0x4B0 - 0x80]; Info *x4B0; } Ent_Combat_TraceWeaponHit_0_00138CA0;
typedef struct { u8 pad[0x2C]; u8 lo:3; u8 x2Cr:5; u8 b0:5; u8 b5:1; } El_Combat_TraceWeaponHit_0_00138CA0;
typedef struct { u8 pad[0x160]; u8 x160; } Q_Combat_TraceWeaponHit_0_00138CA0;
typedef struct { u8 b0:1; u8 b1:1; u8 rest:6; } BFa;
typedef struct { s8 pad[0x31]; BFa f31; } A2;
typedef struct { s32 a, b, c; f32 dist; s8 pad[0x3C - 0x10]; } R;
typedef struct { u8 pad[0x40]; Vec a, b, c, d; } Ent_Combat_UpdateAttack_0_00139330;
typedef struct { u8 pad[0xA]; u16 hA; u8 bC; u8 pD; u16 hE; } Key_Combat_UpdateAttack_0_00139330;
typedef struct { Vec a, b; f32 m[4][4]; Vec pad; } Buf;
typedef struct { u8 pad[6]; u16 h6; u8 pad8[0x38]; s8 x40[1]; } Arg0;
typedef struct { u8 r:7; u8 b7:1; } F7;
typedef struct { u8 pad[0x9A]; u8 t[1]; } A9A;
typedef struct { u8 pad[0xE]; u16 xE; } E;
typedef struct { s32 v[12]; } T30;
typedef struct { u8 pad[0xE]; u16 xE; } E10;
typedef struct { u8 pad[8]; u16 h8; u8 pA[4]; u16 hE; } Key_Combat_DispatchAttack_0_00139D30;
typedef struct { f32 x, y, z, w; } V;
typedef struct { u8 pad[0x10]; s32 v10; u8 pad14[0x2C]; u8 v40[0x14]; s32 v54; } T;
typedef struct {
    u8 pad[0x20];
    u8 x20;
    u8 pad21[0x27];
    s32 x48;
} Hit_Actor_ProcessHitEvents_0_00139F30;
typedef struct {
    u8 pad[0x8C];
    s16 x8C;
    u8 pad8E[0x1E];
    Hit_Actor_ProcessHitEvents_0_00139F30 *xAC;
    Hit_Actor_ProcessHitEvents_0_00139F30 *xB0;
} Obj;
typedef struct {
    u8 pad[0xC0];
    Obj *xC0;
    Hit_Actor_ProcessHitEvents_0_00139F30 *xC4;
    Hit_Actor_ProcessHitEvents_0_00139F30 *xC8;
    Hit_Actor_ProcessHitEvents_0_00139F30 *xCC;
    u8 padD0[0x40];
    s32 x110;
    s32 x114;
} St;
typedef struct {
    u8 pad[0xC];
    u8 lo : 4;
    u8 hi : 4;
    u8 t : 3;
} Ev;
typedef struct { s32 a; s32 b; Obj **p[2]; } DE_t;
typedef struct { u8 pad[0x2AC]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; } Sub4B0;
typedef struct { Vec s; Vec e; } Seg_Actor_ResolveGround_0_0013A720 __attribute__((aligned(16)));
typedef struct { Vec p; u8 pad[0x14]; s32 hit; u8 pad2[0x18]; } Hit_Actor_ResolveGround_0_0013A720 __attribute__((aligned(16)));
typedef struct { u8 pad[0xB4]; u8 xB4; u8 xB5; } Q_Actor_ResolveGround_0_0013A720;
typedef struct { u8 pad[0xF4]; f32 xF4; u8 pad2[0x140 - 0xF8]; } N;
typedef struct { u128 q[2]; } SegQ;
typedef struct { u128 q[4]; } HitQ;
typedef struct {
    u8 pad0[0x10];
    f32 *x10;
    u8 pad14[4];
    Q_Actor_ResolveGround_0_0013A720 *x18;
    u8 pad1C[0x10];
    s8 *x2C;
    u8 pad30[0x10];
    Vec x40;
    u8 pad50[0x60];
    Seg_Actor_ResolveGround_0_0013A720 xB0;
    Hit_Actor_ResolveGround_0_0013A720 xD0;
} P;
typedef struct { f32 f; u8 pe[316]; } El_Actor_ResolveGround_0_0013A720;
typedef struct { u8 pd[564]; El_Actor_ResolveGround_0_0013A720 e[4]; } Tb;
extern QV D_001F1C80;
extern Mtx D_001F2170;
extern f32 D_00222A48[];
extern s32 D_00201E80;
extern F7 D_00222A51[];
extern s16 D_001F1C30[];
extern s16 D_001F1C50[];
extern s16 D_001F1C60[];
extern s16 D_001F1C10[];
void Actor_BuildLookMatrix_0_00136DB0(s8 *a0, Vec *mat);
void Actor_UpdateBones_0_001370A0(A *a);
void Actor_SpawnEffect_0_001374E0(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg3);
void Actor_OffsetColliders_1_00137730(Actor *a, Vec *m);
s32 Actor_PushApart_0_00138460(Actor *a, Actor *b, Vec *out);
u8 Actor_CollideSegment_0_00138920(Actor *a, u8 i, s32 m2, s32 m1, Vec *out, u8 n);
s32 Combat_TraceWeaponHit_0_00138CA0(Ent_Combat_TraceWeaponHit_0_00138CA0 *a0, s8 *a1, Ent_Combat_TraceWeaponHit_0_00138CA0 *a2, Res_Combat_TraceWeaponHit_0_00138CA0 *a3);
void Combat_ProcessHit_0_00138FB0(s8 *a0, A2 *a1, s8 *a2, s32 a3);
void Combat_CheckAttackHits_0_001391B0(s8 *arg0, s32 arg1, A2 *arg2);
void Combat_UpdateAttack_0_00139330(Arg0 *arg0, s32 arg1, u8 arg2, Key_Combat_UpdateAttack_0_00139330 *arg3, f32 *arg4, s32 arg5);
void Combat_UpdateProjectile_0_001395A0(f32 f, s32 a0, s32 a1, u8 a2, E *e, s32 *tbl, s32 t1);
void Combat_DispatchAttack_0_00139D30(s32 a0, s32 a1, s32 a2, Key_Combat_DispatchAttack_0_00139D30 *a3, s32 *t0, s32 t1);
void Actor_UpdateAttachedColliders_0_00139E20(s8 *arg0);
void Actor_ProcessHitEvents_0_00139F30(Actor *a);
void Actor_ResolveActorCollisionB_1_0013A190(s8 *arg0);
void Actor_ResolveActorCollision_0_0013A2C0(s8 *arg0);
void Actor_ResolveWallCollision_0_0013A450(Actor *a);
void Actor_ResolveGround_0_0013A720(Actor *a);
f32 sceVu0InnerProduct(void *, void *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(void *, void *);
Vec* Player_GetBody_1_00145770(void);
f32 Enemy_Get5CC_1_0013E440(s8 *);
f32 sqrtf(float);
void sceVu0CopyMatrix(void *, void *);
void sceVu0MulMatrix(Bone *, void *, Mtx *);
Vec* Enemy_Ptr6E0_1_0013FFB0(A *);
Vec* Enemy_Ptr6F0_1_0013FFA0(A *);
Res_Actor_UpdateBones_0_001370A0* Enemy_GetPartValue_1_0013DCA0(A *, u8);
s8* Map_GetDefaultLight_0_001B72F0(void);
s8* Map_FindSfxEntry_0_001B7300(s8 *, s32);
s32 Ent_IsNull0_1_0013EE30(void *);
u8 Enemy_Get81_1_0013FC00(Actor *);
s32 Enemy_GetCollider_0_0013FB90(Actor *, u8, Vec **, Vec **);
Vec* Enemy_GetPositionPtr_2_00140460(void *);
void memset(void *, s32, s32);
void Enemy_RaycastMapA_0_0013D250(s32, Big *, Vec *, u8, u8);
s32 Enemy_IsAiDisabled_0_0013D6B0(void);
s32 Enemy_IsDead_1_0013EEE0(Ent_Combat_TraceWeaponHit_0_00138CA0 *);
s32 Enemy_Get5B6b3_1_0013EAD0(Ent_Combat_TraceWeaponHit_0_00138CA0 *);
s32 Ent_GetTypeByte_1_0013E220(Ent_Combat_TraceWeaponHit_0_00138CA0 *);
u8 EnemyScr_Event2001_1_00142820(Ent_Combat_TraceWeaponHit_0_00138CA0 *, s32);
void Coll_ClosestPointA_0_00150020(Seg_Combat_TraceWeaponHit_0_00138CA0 *, s8 *, s8 *);
void Enemy_CopyPosition_2_00140470(Ent_Combat_TraceWeaponHit_0_00138CA0 *, Vec *);
s32 Coll_CylinderVsSegment_0_0014EC00(Seg_Combat_TraceWeaponHit_0_00138CA0 *, Vec *, f32, f32);
s8* Enemy_GetPart_1_0013DC70(Ent_Combat_TraceWeaponHit_0_00138CA0 *, u8);
void Coll_SweepCapsules_0_00151900(Res_Combat_TraceWeaponHit_0_00138CA0 *, s8 *, s8 *, s8 *, s8 *, f32);
void Player_TakeHit_1_001C7DC0(A2 *);
s32 Player_TakeHitB_1_001C8070(A2 *, s8 *);
void Enemy_Set5B0b6_1_0013EB70(void *, s32);
void EnemyScr_Event200B_1_001423E0(s8 *, u8);
void Enemy_TryStartMoveMotion_1_0013C7B0(s8 *);
s32 Combat_ApplyDamage_1_00135E90(s8 *, s32, A2 *, u8, s32 *);
u8 Enemy_GetHpPercent_2_0013F620(s8 *);
void EnemyScr_Event200COnHit_1_00142320(s8 *, u8, u8);
void Player_Nop_2_001C73B0(s8 *, s32, s32, u8);
void Player_OnHitEnemy_0_001C73C0(s8 *, s32, s32, u8);
void Player_TraceAttack_0_001C7850(s32, A2 *);
s8* ActorList_Next_2_001A5460(s32 *);
u8 Player_IsHitTarget_0_001C7320(s8 *);
Actor* ActorList_GetCount_1_001A5430(void);
s32 Player_GetWeaponSegment_0_001C7A70(Vec *);
void Actor_ClosestOnSegment_0_001A58A0(f32, f32 *, f32 *, Vec *, Vec *);
void Actor_TransformRay_0_001A5790(Vec *, Vec *, s8 *, Vec *, Vec *);
u8 Enemy_Get5B0b6_1_0013EB90(Actor *);
void Player_InitAttack_0_001C79B0(f32 *);
void Draw_ShadowDisc_0_00156920(Buf *);
s32 Game_GetFlag54b6_0_001A9410(void);
u8 Enemy_Get5B5mF_1_0013E5E0(s8 *);
s8 Enemy_Get608_1_0013E290(void *);
s8 Enemy_Get609_1_0013E260(s8 *);
s8 Enemy_Get60A_1_0013E270(s8 *);
void Mtx_Compose_2_00173FD0(Vec *, Vec *, Vec *, Vec *);
Vec* Player_GetPosition_1_00145730(void);
void memcpy(void *, void *, s32);
s8* Attack_SpawnSfx_0_001D1F20(s32, s8 *, s32, f32, u8, E *, s32, s32);
void Sfx_SetOwner_1_00167600(s8 *, s8 *);
void Attack_PlaySe_0_001D1E80(s32, s32, Key_Combat_DispatchAttack_0_00139D30 *, s32 *, s32);
void Enemy_Set5B6b3_1_0013EAB0(s32, s32);
void Enemy_Set5B6b2_1_0013EAE0(s32, s32);
void sceVu0ApplyMatrix(V *, void *, V *);
void Enemy_GetForwardVector_2_001403D0(s8 *, V *);
s32 Enemy_GetAttachMatrix_0_001A5AA0(s8 *, T *, void *);
s32 Enemy_Get5B2b5_1_0013E780(s8 *);
f32 Vec_YawAngle_2_0013FC10(V *);
s8* Enemy_GetRotationPtr_1_00140430(s8 *);
void Enemy_Set608_1_0013E2A0(Actor *, s8);
Hit_Actor_ProcessHitEvents_0_00139F30* MapObj_FindCollider_0_001B1D00(Obj *, void *);
Hit_Actor_ProcessHitEvents_0_00139F30* MapObj_GetSection_0_001B1CB0(Obj *, void *, Hit_Actor_ProcessHitEvents_0_00139F30 **);
s32 Enemy_Get5B2m1_1_0013E8B0(s8 *);
s32 Actor_CollideCapsulesB_0_00137E60(s8 *, s8 *, f32 *);
s32 Enemy_Get5B1b6_1_0013E910(s8 *);
s32 Actor_CollideCapsules_0_00137870(s8 *, s8 *, f32 *);
void Enemy_Set5B4b0_1_0013E6A0(s8 *, s32);
void Enemy_Set5B4b1_1_0013E670(Actor *, s32);
u32 Enemy_Get5B2b6w2_1_0013E750(Actor *);
u32 Enemy_Get5B2b1_1_0013E880(Actor *);
s32 Enemy_Get5B1b7_1_0013E8E0(Actor*);
void Enemy_RaycastMapC_0_0013D430(s32, Hit_Actor_ResolveGround_0_0013A720 *, Seg_Actor_ResolveGround_0_0013A720 *, s32, u8);
void Enemy_Set5B2b5_1_0013E760(Actor *, s32);
f32 Enemy_GetHeightAboveFloor_0_0013E3C0(Actor *);
s32 Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetTransform_1_001677C0(s32, Mtx *);

/* Actor_BuildLookMatrix_0_00136DB0 */

static inline void rot(Vec *o, Vec *a, Vec *v, f32 c, f32 s, f32 t) {
    o->x = v->x * (c + t * (a->x * a->x)) + v->y * (t * (a->y * a->x) - a->z * s) + v->z * (t * (a->z * a->x) + a->y * s);
    o->y = v->x * (t * (a->y * a->x) + a->z * s) + v->y * (c + t * (a->y * a->y)) + v->z * (t * (a->z * a->y) - a->x * s);
    o->z = v->x * (t * (a->z * a->x) - a->y * s) + v->y * (t * (a->z * a->y) + a->x * s) + v->z * (c + t * (a->z * a->z));
}
void Actor_BuildLookMatrix_0_00136DB0(s8 *a0, Vec *mat) {
    Vec e;
    QV up;
    Vec m[4];
    Vec t80;
    Vec t70;
    f32 d;
    f32 r;
    up = D_001F1C80;
    sceVu0SubVector(&m[2], &mat[3], Player_GetBody_1_00145770());
    sceVu0Normalize(&m[2], &m[2]);
    sceVu0Normalize(&e, &mat[2]);
    d = sceVu0InnerProduct(&e, &m[2]);
    if (d < 0.0f) {
        sceVu0ScaleVector(&t80, &e, -2.0f * d);
        sceVu0AddVector(&m[2], &m[2], &t80);
        sceVu0Normalize(&m[2], &m[2]);
        d = sceVu0InnerProduct(&e, &m[2]);
    }
    if (d < 0.5f) {
        sceVu0OuterProduct(&t70, &e, &m[2]);
        sceVu0Normalize(&t70, &t70);
        rot(&m[2], &t70, &e, 0.5f, 0.8660254f, 0.5f);
        sceVu0Normalize(&m[2], &m[2]);
    }
    sceVu0OuterProduct(&m[0], &up.v, &m[2]);
    sceVu0Normalize(&m[0], &m[0]);
    sceVu0OuterProduct(&m[1], &m[2], &m[0]);
    sceVu0CopyVector(&m[3], &mat[3]);
    m[0].w = 0.0f;
    m[1].w = 0.0f;
    m[2].w = 0.0f;
    sceVu0ScaleVector(&m[0], &m[0], sqrtf(sceVu0InnerProduct(&mat[0], &mat[0])));
    sceVu0ScaleVector(&m[1], &m[1], sqrtf(sceVu0InnerProduct(&mat[1], &mat[1])));
    sceVu0ScaleVector(&m[2], &m[2], sqrtf(sceVu0InnerProduct(&mat[2], &mat[2])));
    r = Enemy_Get5CC_1_0013E440(a0);
    sceVu0CopyVector(&m[3], &mat[3]);
    Mtx_LerpScaled_1_0015E730(mat, mat, m, 1.0f - r);
}

/* Actor_UpdateBones_0_001370A0 */

void Actor_UpdateBones_0_001370A0(A *a) {
    F f0;
    F pf;
    F f;
    Bone *bones;
    u8 done;
    u8 i;
    Bone *b;
    u8 *s7;
    u8 c;
    Hdr *h;

    done = 0;
    h = a->x518->x1A8;
    s7 = a->x518->x180;
    bones = (Bone *)((u8 *)((s32)h + 0x40) + D_00201F2C * (h->h6 * 0x140 + 0x200) + 0xC0);
    c = h->c;
    if (c) h->c--;
    sceVu0CopyMatrix(bones, &D_001F2170);
    sceVu0AddVector(&bones->m.m[3], &bones->m.m[3], &h->x30);
    sceVu0CopyVector(Enemy_Ptr6E0_1_0013FFB0(a), &bones->m.m[3]);
    sceVu0CopyVector(Enemy_Ptr6F0_1_0013FFA0(a), &bones->m.m[3]);
    f0.d = bones->f.d;
    f0.b.b5 = 0;
    f0.b.b2 = 0;
    if (f0.b.b4) f0.b.b5 = 1;
    if (f0.b.b1) f0.b.b2 = 1;
    bones->f.d = f0.d;
    for (i = 1; i < h->h6 + 1; i++) {
        b = &bones[i];
        f.d = b->f.d;
        pf.d = bones[b->x131].f.d;
        f.b.b5 = 0;
        f.b.b2 = 0;
        if (f.b.b4) f.b.b5 = 1;
        if (f.b.b1) f.b.b2 = 1;
        if (!f.b.b6) {
            u8 k;
            Res_Actor_UpdateBones_0_001370A0 *r;
            sceVu0MulMatrix(b, &bones[b->x131], &b->x80);
            if (pf.b.b5) f.b.b5 = 1;
            if (pf.b.b2) f.b.b2 = 1;
            b->f.d = f.d;
            k = b->x130;
            r = Enemy_GetPartValue_1_0013DCA0(a, a->x9A[k]);
            if (r->x2A == k) {
                if (r->t == 2) {
                    if (done == 0) sceVu0CopyVector(Enemy_Ptr6E0_1_0013FFB0(a), &b->m.m[3]);
                    sceVu0CopyVector(Enemy_Ptr6F0_1_0013FFA0(a), &b->m.m[3]);
                }
                if (r->t == 5) {
                    if (((Q_Actor_UpdateBones_0_001370A0 *)*(s8 **)(s7 + 0x1C))->b3) Actor_BuildLookMatrix_0_00136DB0(a, b);
                    sceVu0CopyVector(Enemy_Ptr6E0_1_0013FFB0(a), &b->m.m[3]);
                    done = 1;
                }
            }
        } else {
            u8 k;
            Res_Actor_UpdateBones_0_001370A0 *r;
            sceVu0MulMatrix(b, &b->x40, &b->x80);
            b->f.d = f.d;
            k = b->x130;
            r = Enemy_GetPartValue_1_0013DCA0(a, a->x9A[k]);
            if (r->x2A == k && r->t == 5) {
                sceVu0CopyVector(Enemy_Ptr6E0_1_0013FFB0(a), &bones[b->x131].m.m[3]);
                done = 1;
            }
        }
    }
}

/* Actor_SpawnEffect_0_001374E0 */

void Actor_SpawnEffect_0_001374E0(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    s8 *v;
    s32 id;
    f32 k;

    if (arg0 == NULL) return;
    if (arg1 == NULL) {
        v = Map_GetDefaultLight_0_001B72F0();
    } else {
        id = -1;
        if (Ent_IsNull0_1_0013EE30(arg0)) {
            if (arg2 != NULL) id = M2C_FIELD(arg2, s8 *, 0x25);
            else if (arg3 != NULL) id = M2C_FIELD(arg3, s8 *, 0x22);
        } else if (arg2 != NULL && ((u64)((s64)M2C_FIELD(arg2, u8 *, 0x28) << 58) >> 63)) {
            id = M2C_FIELD(arg2, s8 *, 0x25);
        } else if (arg3 != NULL && ((u64)((s64)M2C_FIELD(arg3, u8 *, 0x24) << 58) >> 63)) {
            id = M2C_FIELD(arg3, s8 *, 0x22);
        }
        v = Map_FindSfxEntry_0_001B7300(arg1, id);
        if (v == NULL) v = Map_GetDefaultLight_0_001B72F0();
    }
    if (v != NULL) {
        if ((M2C_FIELD(arg0, u8 *, 0x5B3) & 3) < 3) {
            M2C_FIELD(arg0, f32 *, 0x550) = M2C_FIELD(v, f32 *, 0x10);
            M2C_FIELD(arg0, f32 *, 0x554) = M2C_FIELD(v, f32 *, 0x14);
            M2C_FIELD(arg0, f32 *, 0x558) = M2C_FIELD(v, f32 *, 0x18);
            M2C_FIELD(arg0, f32 *, 0x55C) = M2C_FIELD(v, f32 *, 0x1C);
            M2C_FIELD(arg0, f32 *, 0x560) = M2C_FIELD(v, f32 *, 0x20);
            M2C_FIELD(arg0, f32 *, 0x564) = M2C_FIELD(v, f32 *, 0x24);
            M2C_FIELD(arg0, f32 *, 0x568) = M2C_FIELD(v, f32 *, 0x28);
            M2C_FIELD(arg0, f32 *, 0x56C) = M2C_FIELD(v, f32 *, 0x2C);
            M2C_FIELD(arg0, f32 *, 0x570) = M2C_FIELD(v, f32 *, 0x30);

        } else {
            M2C_FIELD(arg0, f32 *, 0x550) = M2C_FIELD(arg0, f32 *, 0x550) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x10) - M2C_FIELD(arg0, f32 *, 0x550));
            M2C_FIELD(arg0, f32 *, 0x554) = M2C_FIELD(arg0, f32 *, 0x554) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x14) - M2C_FIELD(arg0, f32 *, 0x554));
            M2C_FIELD(arg0, f32 *, 0x558) = M2C_FIELD(arg0, f32 *, 0x558) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x18) - M2C_FIELD(arg0, f32 *, 0x558));
            M2C_FIELD(arg0, f32 *, 0x55C) = M2C_FIELD(arg0, f32 *, 0x55C) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x1C) - M2C_FIELD(arg0, f32 *, 0x55C));
            M2C_FIELD(arg0, f32 *, 0x560) = M2C_FIELD(arg0, f32 *, 0x560) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x20) - M2C_FIELD(arg0, f32 *, 0x560));
            M2C_FIELD(arg0, f32 *, 0x564) = M2C_FIELD(arg0, f32 *, 0x564) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x24) - M2C_FIELD(arg0, f32 *, 0x564));
            M2C_FIELD(arg0, f32 *, 0x568) = M2C_FIELD(arg0, f32 *, 0x568) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x568));
            M2C_FIELD(arg0, f32 *, 0x56C) = M2C_FIELD(arg0, f32 *, 0x56C) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x2C) - M2C_FIELD(arg0, f32 *, 0x56C));
            M2C_FIELD(arg0, f32 *, 0x570) = M2C_FIELD(arg0, f32 *, 0x570) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x30) - M2C_FIELD(arg0, f32 *, 0x570));

        }
    }
}

/* Actor_OffsetColliders_1_00137730 */
void Actor_OffsetColliders_1_00137730(Actor *a, Vec *m) {
    Vec *p[4];
    Vec *q[4];
    u8 i;
    u8 n;
    H *h;
    s8 *e;

    n = Enemy_Get81_1_0013FC00(a);
    m->w = 0.0f;
    for (i = 0; i < n; i++) {
        p[0] = 0;
        q[0] = 0;
        if ((u8)Enemy_GetCollider_0_0013FB90(a, i, p, q)) {
            sceVu0AddVector(p[0], p[0], m);
        }
    }
    h = *(H **)(a->unk518 + 0x1A8);
    e = (s8 *)((s32)h + 0x40) + D_00201F2C * (h->n * 0x140 + 0x200) + 0xC0;
    sceVu0AddVector((Vec *)(e + 0x1F0), (Vec *)(e + 0x1F0), m);
    i = 1;
    if (i < h->n + 1) {
        e += 0x140;
        do {
        if (!((Flags8 *)(e + 0x138))->f.b6) {
            sceVu0AddVector((Vec *)(e + 0x30), (Vec *)(e + 0x30), m);
        }
            e += 0x140;
            i++;
        } while (i < h->n + 1);
    }
}

/* text_00137870 */
#ifdef NONMATCHING
/* best-effort C: actor_collide_capsules.c, actor_collide_capsules_b.c */
#else
INCLUDE_ASM(Actor_CollideCapsules_0_00137870);
#endif

/* Actor_PushApart_0_00138460 */
static inline s32 hit(f32 g) { return g <= 0.0f; }
static inline f32 u2f(u32 x) { return x; }

s32 Actor_PushApart_0_00138460(Actor *a, Actor *b, Vec *out) {
    Vec *p[4];
    Vec *p2[4];
    Vec *q[4];
    Vec *q2[4];
    Vec d;
    Vec e;
    Vec c;
    Vec m;
    Vec h;
    u8 n0;
    u8 n1;
    u8 i;
    u8 k;
    u32 steps;
    u32 j;
    f32 len;
    f32 t;
    f32 r;
    f32 g;
    f32 f;
    Vec *pa;
    Vec *pb;

    n0 = Enemy_Get81_1_0013FC00(a);
    n1 = Enemy_Get81_1_0013FC00(b);
    for (i = 0; i < n0; i++) {
        Enemy_GetCollider_0_0013FB90(a, i, p, q);
        sceVu0SubVector(&d, p[0], q[0]);
        len = sqrtf(sceVu0InnerProduct(&d, &d));
        t = 0.9f * p[0]->w;
        if (!(len <= t)) {
            steps = (u32)(len / t) + 1;
            if (steps > 6) {
                Ent_IsNull0_1_0013EE30(a);
                steps = 6;
            }
            for (k = 0; k < n1; k++) {
                Enemy_GetCollider_0_0013FB90(b, k, p2, q2);
                r = p[0]->w + p2[0]->w;
                for (j = 0; j < steps; j = (u8)(j + 1)) {
                    f = u2f(j) / u2f(steps);
                    sceVu0ScaleVector(&c, &d, f);
                    sceVu0AddVector(&c, &c, q[0]);
                    sceVu0SubVector(&e, p2[0], &c);
                    g = sqrtf(sceVu0InnerProduct(&e, &e)) - r;
                    if (!(g <= 0.0f) == 0) {
                        pa = Enemy_GetPositionPtr_2_00140460(a);
                        pb = Enemy_GetPositionPtr_2_00140460(b);
                        sceVu0ScaleVector(&m, &d, f - 1.0f);
                        sceVu0AddVector(out, pa, &m);
                        sceVu0SubVector(out, pb, out);
                        sceVu0Normalize(out, out);
                        sceVu0ScaleVector(out, out, g * p[0]->w / r);
                        sceVu0AddVector(out, out, &m);
                        *(s32 *)&out->w = 0;
                        return 1;
                    }
                }
            }
        } else {
            for (k = 0; k < n1; k++) {
                Enemy_GetCollider_0_0013FB90(b, k, p2, q2);
                r = p[0]->w + p2[0]->w;
                sceVu0SubVector(&h, p2[0], p[0]);
                t = sqrtf(sceVu0InnerProduct(&h, &h)) - r;
                if (!(t <= 0.0f) == 0) {
                    pa = Enemy_GetPositionPtr_2_00140460(a);
                    pb = Enemy_GetPositionPtr_2_00140460(b);
                    sceVu0SubVector(out, pb, pa);
                    sceVu0Normalize(out, out);
                    out->x *= t * p[0]->w / r;
                    out->y *= t * p[0]->w / r;
                    out->z *= t * p[0]->w / r;
                    *(s32 *)&out->w = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}

/* Actor_CollideSegment_0_00138920 */

u8 Actor_CollideSegment_0_00138920(Actor *a, u8 i, s32 m2, s32 m1, Vec *out, u8 n) {
    Vec *p[4];
    Vec *q[4];
    Vec d;
    Vec c[2];
    Big b;
    Vec e;
    u8 ok;
    u32 j;
    u32 steps;
    f32 len;
    f32 t;
    f32 f;

    ok = 0;
    p[0] = 0;
    q[0] = 0;
    if ((u8)Enemy_GetCollider_0_0013FB90(a, i, p, q)) {
        sceVu0SubVector(&d, p[0], q[0]);
        len = sqrtf(sceVu0InnerProduct(&d, &d));
        t = 0.9f * p[0]->w;
        if (!(len <= t)) {
            steps = (u32)(len / t) + 1;
            if (steps > 8) steps = 8;
            for (j = n; j <= steps; j++) {
                f = (f32)j / (f32)steps;
                sceVu0ScaleVector(c, &d, f);
                sceVu0AddVector(c, c, q[0]);
                c[0].w = p[0]->w;
                memset(&b, 0, 0x40);
                if ((&D_00201E80)[2]) {
                    Enemy_RaycastMapA_0_0013D250(*(s32 *)(&D_00201E80)[2], &b, c, m2, m1);
                }
                if ((&D_00201E80)[3]) {
                    Enemy_RaycastMapA_0_0013D250(*(s32 *)(&D_00201E80)[3], &b, c, m2, m1);
                }
                if (b.x24) {
                    sceVu0ScaleVector(&e, &d, f - 1.0f);
                    sceVu0ScaleVector(out, &b.b, c[0].w);
                    sceVu0AddVector(out, out, &b.a);
                    sceVu0SubVector(out, out, c);
                    sceVu0AddVector(out, out, &e);
                    ok = 1;
                    break;
                }
            }
        } else {
            sceVu0CopyVector(c, p[0]);
            memset(&b, 0, 0x40);
            if ((&D_00201E80)[2]) {
                Enemy_RaycastMapA_0_0013D250(*(s32 *)(&D_00201E80)[2], &b, c, m2, m1);
            }
            if ((&D_00201E80)[3]) {
                Enemy_RaycastMapA_0_0013D250(*(s32 *)(&D_00201E80)[3], &b, c, m2, m1);
            }
            if (b.x24) {
                sceVu0ScaleVector(out, &b.b, c[0].w);
                sceVu0AddVector(out, out, &b.a);
                sceVu0SubVector(out, out, c);
                ok = 1;
            }
        }
    }
    return ok;
}

/* Combat_TraceWeaponHit_0_00138CA0 */
static inline u8 can(Ent_Combat_TraceWeaponHit_0_00138CA0 *a0, Ent_Combat_TraceWeaponHit_0_00138CA0 *a2) {
    if (Ent_IsNull0_1_0013EE30(a0)) {
        if (Ent_IsNull0_1_0013EE30(a2)) return 0;
        return 1;
    }
    return EnemyScr_Event2001_1_00142820(a0, Ent_GetTypeByte_1_0013E220(a2));
}

s32 Combat_TraceWeaponHit_0_00138CA0(Ent_Combat_TraceWeaponHit_0_00138CA0 *a0, s8 *a1, Ent_Combat_TraceWeaponHit_0_00138CA0 *a2, Res_Combat_TraceWeaponHit_0_00138CA0 *a3) {
    Res_Combat_TraceWeaponHit_0_00138CA0 r;
    Seg_Combat_TraceWeaponHit_0_00138CA0 sg;
    Vec v;
    s32 best;
    s32 n;
    s32 i;
    El_Combat_TraceWeaponHit_0_00138CA0 *e;
    s8 *q;
    u8 ok;
    u8 c;

    best = -1;
    n = a2->x7C;
    r.hit = 0;
    a3->hit = 0;
    a3->a.w = 2.0f;
    if (Enemy_IsAiDisabled_0_0013D6B0()) return best;
    if (a0 == a2) return best;
    if (Enemy_IsDead_1_0013EEE0(a2)) return best;
    if (Enemy_Get5B6b3_1_0013EAD0(a2)) return best;
    if (Enemy_IsAiDisabled_0_0013D6B0()) {
        ok = 0;
    } else {
        ok = can(a0, a2);
    }
    if (ok == 0) return -1;
    Coll_ClosestPointA_0_00150020(&sg, a1 + 0x60, a1 + 0x40);
    Enemy_CopyPosition_2_00140470(a2, &v);
    if (!Coll_CylinderVsSegment_0_0014EC00(&sg, &v, a2->x4B0->xA, a2->x4B0->xE)) return -1;
    for (i = 0; i < n; i++) {
        e = Enemy_GetPartValue_1_0013DCA0(a2, i);
        if (!e->b5) continue;
        if (e->lo == 2) continue;
        c = Ent_IsNull0_1_0013EE30(a2); if (c != (e->lo == 1)) continue;
        q = Enemy_GetPart_1_0013DC70(a2, i);
        if (*(u8 *)(q + 0x160) & 1) continue;
        Coll_SweepCapsules_0_00151900(&r, a1 + 0x60, a1 + 0x40, q + 0x20, q, 0.95f);
        if (r.hit && i != 0xFF && r.a.w < a3->a.w) {
            best = i;
            *(R3 *)a3 = *(R3 *)&r;
            a3->a.w = r.a.w;
        }
    }
    return best;
}

/* Combat_ProcessHit_0_00138FB0 */
#define Ent_GetTypeByte_1_0013E220 Ent_GetTypeByte_1_0013E220__as_Combat_ProcessHit_0_00138FB0
u8 Ent_GetTypeByte_1_0013E220__as_Combat_ProcessHit_0_00138FB0(s8 *);

void Combat_ProcessHit_0_00138FB0(s8 *a0, A2 *a1, s8 *a2, s32 a3) {
    u8 r;
    u8 q;
    s32 out;

    if (Enemy_IsAiDisabled_0_0013D6B0()) return;
    if (a2 == 0) return;
    if (Ent_IsNull0_1_0013EE30(a2)) {
        r = 1;
        if (Player_IsBusy_0_001C99A0()) return;
        if (a1->f31.b1) {
            Player_TakeHit_1_001C7DC0(a1);
        } else {
            r = (u8)Player_TakeHitB_1_001C8070(a1, a0);
        }
        if (a0 == 0) return;
        if (Ent_IsNull0_1_0013EE30(a0)) return;
        Enemy_Set5B0b6_1_0013EB70(a0, 0);
        if (r) {
            EnemyScr_Event200B_1_001423E0(a0, Ent_GetTypeByte_1_0013E220(a2));
        } else {
            Enemy_TryStartMoveMotion_1_0013C7B0(a0);
        }
    } else {
        r = (u8)Combat_ApplyDamage_1_00135E90(a2, a3, a1, Ent_GetTypeByte_1_0013E220(a0), &out);
        q = Enemy_GetHpPercent_2_0013F620(a2);
        EnemyScr_Event200COnHit_1_00142320(a2, Ent_GetTypeByte_1_0013E220(a0), q);
        if (a0 == 0) return;
        if (!r) return;
        if (Ent_IsNull0_1_0013EE30(a0)) {
            if (a1->f31.b1) {
                Player_Nop_2_001C73B0(a2, out, a3, (u8)r - 1);
            } else {
                Player_OnHitEnemy_0_001C73C0(a2, out, a3, (u8)r - 1);
            }
        } else {
            Enemy_Set5B0b6_1_0013EB70(a0, 0);
            EnemyScr_Event200B_1_001423E0(a0, Ent_GetTypeByte_1_0013E220(a2));
        }
    }
}
#undef Ent_GetTypeByte_1_0013E220

/* Combat_CheckAttackHits_0_001391B0 */
#define Combat_TraceWeaponHit_0_00138CA0 Combat_TraceWeaponHit_0_00138CA0__as_Combat_CheckAttackHits_0_001391B0
s32 Combat_TraceWeaponHit_0_00138CA0__as_Combat_CheckAttackHits_0_001391B0(s8 *, s32, s8 *, R *);
#define Combat_ProcessHit_0_00138FB0 Combat_ProcessHit_0_00138FB0__as_Combat_CheckAttackHits_0_001391B0
void Combat_ProcessHit_0_00138FB0__as_Combat_CheckAttackHits_0_001391B0(s8 *, A2 *, s8 *, u8);

void Combat_CheckAttackHits_0_001391B0(s8 *arg0, s32 arg1, A2 *arg2) {
    s32 it;
    R r;
    f32 best;
    s8 *bestObj;
    s32 bestRes;
    s8 *cur;
    s32 res;

    if (Enemy_IsAiDisabled_0_0013D6B0() == 0) {
        if (Ent_IsNull0_1_0013EE30(arg0) != 0) {
            Player_TraceAttack_0_001C7850(arg1, arg2);
        }
        best = 2.0f;
        it = 0;
        bestObj = NULL;
        bestRes = 0;
        cur = ActorList_Next_2_001A5460(&it);
        while (cur != NULL) {
            res = -1;
            if (Ent_IsNull0_1_0013EE30(arg0) != 0 && arg2->f31.b1 == 0) {
                if (Player_IsHitTarget_0_001C7320(cur) <= 0) {
                    res = Combat_TraceWeaponHit_0_00138CA0(arg0, arg1, cur, &r);
                }
            } else {
                res = Combat_TraceWeaponHit_0_00138CA0(arg0, arg1, cur, &r);
            }
            if (res != -1) {
                if (!(best <= r.dist)) {
                    bestObj = cur;
                    bestRes = res;
                    best = r.dist;
                }
            }
            cur = ActorList_Next_2_001A5460(&it);
        }
        Combat_ProcessHit_0_00138FB0(arg0, arg2, bestObj, bestRes);
    }
}
#undef Combat_TraceWeaponHit_0_00138CA0
#undef Combat_ProcessHit_0_00138FB0

/* Combat_UpdateAttack_0_00139330 */
#define D_001F2170 D_001F2170__as_Combat_UpdateAttack_0_00139330
extern f32 D_001F2170__as_Combat_UpdateAttack_0_00139330[];
#define Combat_CheckAttackHits_0_001391B0 Combat_CheckAttackHits_0_001391B0__as_Combat_UpdateAttack_0_00139330
void Combat_CheckAttackHits_0_001391B0__as_Combat_UpdateAttack_0_00139330(Actor *, Ent_Combat_UpdateAttack_0_00139330 *, void *);
static inline Ent_Combat_UpdateAttack_0_00139330 *getEnt(Actor *a, u8 i) { return Enemy_GetPart_1_0013DC70(a, a->unk82[i + 0x18]); }

void Combat_UpdateAttack_0_00139330(Arg0 *arg0, s32 arg1, u8 arg2, Key_Combat_UpdateAttack_0_00139330 *arg3, f32 *arg4, s32 arg5) {
    Actor *a;
    Ent_Combat_UpdateAttack_0_00139330 *e;
    Vec *v;
    f32 *p;
    s8 *base;
    f32 tmp[16];
    Buf buf;

    a = ActorList_GetCount_1_001A5430();
    e = Enemy_GetPart_1_0013DC70(a, a->unk82[arg2 + 0x18]);
    base = (s8 *)((s32)arg0 + 0x40) + D_00201F2C * (arg0->h6 * 0x140 + 0x200);
    v = &e->a;
    p = arg4 + arg3->hE + arg3->bC;
    sceVu0CopyVector(&e->c, v);
    sceVu0CopyVector(&e->d, &e->b);
    if (Ent_IsNull0_1_0013EE30(a) != 0) {
        if (Player_GetWeaponSegment_0_001C7A70(v) == 0) {
            Actor_ClosestOnSegment_0_001A58A0(p[0], p + 1, p + 4, v, v + 1);
            v[1].w = Player_ClampPitch_0_001C7CA0(v[1].w);
        }
        Actor_TransformRay_0_001A5790(v, v + 1, base + ((u8)arg2 + 1) * 0x140 + 0xC0, v, v + 1);
    } else {
        Actor_ClosestOnSegment_0_001A58A0(p[0], p + 1, p + 4, v, v + 1);
        Actor_TransformRay_0_001A5790(v, v + 1, base + ((u8)arg2 + 1) * 0x140 + 0xC0, v, v + 1);
    }
    if (arg5 != 0) {
        Enemy_Set5B0b6_1_0013EB70(a, 1);
    } else if (Enemy_Get5B0b6_1_0013EB90(a) == 1) {
        if (Ent_IsNull0_1_0013EE30(a) != 0) {
            Player_InitAttack_0_001C79B0(tmp);
            Combat_CheckAttackHits_0_001391B0(a, e, tmp);
        } else {
            Combat_CheckAttackHits_0_001391B0(a, e, a->unk4B0 + arg3->hA * 0x40 + 0x10);
        }
    }
    if (D_00222A51[0].b7) {
        sceVu0CopyVector(&buf.a, v);
        sceVu0CopyVector(&buf.b, v + 1);
        sceVu0CopyMatrix(&buf.m[0][0], D_001F2170);
        Draw_ShadowDisc_0_00156920(&buf);
    }
}
#undef Combat_CheckAttackHits_0_001391B0
#undef D_001F2170

/* Combat_UpdateProjectile_0_001395A0 */
Vec D_001F1C70 = { 1.0f, 1.0f, 1.0f };

void Combat_UpdateProjectile_0_001395A0(f32 f, s32 a0, s32 a1, u8 a2, E *e, s32 *tbl, s32 t1) {
    s8 *a;
    s32 *base;
    s32 id;
    s8 *obj;
    s16 k;
    s8 c;
    f32 d;

    if (t1 == 0) return;
    a = ActorList_GetCount_1_001A5430();
    base = &tbl[e->xE];
    id = base[0];
    obj = 0;
    if (!(u8)Game_GetFlag54b6_0_001A9410() && id >= 0x1F2 && id <= 0x24B) return;
    if (id == 0x1D4) {
        t1 = base[1];
        {
        Vec v;
        f32 m[12];
        Vec p = {0};
        Vec r = {0};
        Vec s;
        Vec w;
        Vec *pv;
        Vec *q;
        s = D_001F1C70;
        p.x = ((f32 *)base)[2];
        p.y = ((f32 *)base)[3];
        p.z = ((f32 *)base)[4];
        Mtx_Compose_2_00173FD0((Vec *)m, &p, &r, &s);
        base = (s32 *)&v;
        sceVu0AddVector((Vec *)base, (Vec *)base, Enemy_GetPositionPtr_2_00140460(a));
        switch (t1) {
        case 1:
            Camera_SetParams_0_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            Vibe_StartB_0_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            Vibe_StartA_0_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        case 2:
            Camera_SetParams_0_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            Vibe_StartB_0_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            Vibe_StartA_0_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        case 3:
            Camera_SetParams_0_001C8F30(3.0f, 3.0f, 1.0f, 40.0f);
            Vibe_StartB_0_0015FE20(50.0f, 10.0f, 0.0f, 0.5f, 40.0f);
            Vibe_StartA_0_0015FD90(50.0f, 10.0f, 0.0f, 0.5f, 40.0f);
            break;
        case 4:
            Camera_SetParams_0_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            Vibe_StartB_0_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            Vibe_StartA_0_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        case 100:
            sceVu0SubVector(&w, Player_GetPosition_1_00145730(), (Vec *)base);
            d = sqrtf(sceVu0InnerProduct(&w, &w));
            if (d < 800.0f) {
                Camera_SetParams_0_001C8F30(10.0f, 30.0f, 1.0f, 10.0f);
                Vibe_StartB_0_0015FE20(1.0f, 10.0f, 0.0f, 1.0f, 16.0f);
                Vibe_StartA_0_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            } else if (d < 1600.0f) {
                d -= 800.0f;
                d /= 800.0f;
                f = 1.0f - d;
                Camera_SetParams_0_001C8F30(10.0f, 30.0f, f, 10.0f);
                Vibe_StartB_0_0015FE20(1.0f, 10.0f, 0.0f, f, 16.0f);
                Vibe_StartA_0_0015FD90(1.0f, 50.0f, 0.0f, f, 16.0f);
            }
            break;
        default:
            Camera_SetParams_0_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            Vibe_StartB_0_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            Vibe_StartA_0_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        }
        }
        return;
    }
    if ((Enemy_Get5B5mF_1_0013E5E0(a) & 8) && id >= 100 && id <= 0x102) return;
    if (id == 0x1E0 || id == 0x1F2 || id == 0x1F3) {
        k = -1;
        if (id == 0x1E0) {
            c = Enemy_Get608_1_0013E290(a);
            if (c >= 0 && D_001F1C30[c] >= 0) k = D_001F1C30[c];
        } else if (id == 0x1F3) {
            id = Enemy_Get609_1_0013E260(a);
            if (id >= 0) {
                c = Enemy_Get60A_1_0013E270(a);
                if (c >= 0 && D_001F1C50[c] >= 0) k = D_001F1C50[c] + id * 10;
            }
        } else if (id == 0x1F2) {
            id = Enemy_Get609_1_0013E260(a);
            if (id >= 0) {
                c = Enemy_Get60A_1_0013E270(a);
                if (c >= 0 && D_001F1C60[c] >= 0) k = D_001F1C60[c] + id * 10;
            }
        }
        if (k >= 0) {
            T30 g;
            E10 h;
            memcpy(&g, &tbl[e->xE], 0x30);
            memcpy(&h, e, 0x10);
            g.v[0] = k;
            h.xE = 0;
            obj = Attack_SpawnSfx_0_001D1F20(a0, a + 0x580, a1, f, a2, (E *)&h, (s32)g.v, t1);
        }
    } else {
        obj = Attack_SpawnSfx_0_001D1F20(a0, a + 0x580, a1, f, a2, e, (s32)tbl, t1);
    }
    if (obj) Sfx_SetOwner_1_00167600(obj, a);
}

/* Combat_DispatchAttack_0_00139D30 */
#define Combat_UpdateProjectile_0_001395A0 Combat_UpdateProjectile_0_001395A0__as_Combat_DispatchAttack_0_00139D30
void Combat_UpdateProjectile_0_001395A0__as_Combat_DispatchAttack_0_00139D30(s32, s32, s32, Key_Combat_DispatchAttack_0_00139D30 *, s32 *, s32);
#define Combat_UpdateAttack_0_00139330 Combat_UpdateAttack_0_00139330__as_Combat_DispatchAttack_0_00139D30
void Combat_UpdateAttack_0_00139330__as_Combat_DispatchAttack_0_00139D30(s32, s32, s32, Key_Combat_DispatchAttack_0_00139D30 *, s32 *, s32);
#define ActorList_GetCount_1_001A5430 ActorList_GetCount_1_001A5430__as_Combat_DispatchAttack_0_00139D30
s32 ActorList_GetCount_1_001A5430__as_Combat_DispatchAttack_0_00139D30(s32, s32, s32, Key_Combat_DispatchAttack_0_00139D30 *, s32 *, s32);

void Combat_DispatchAttack_0_00139D30(s32 a0, s32 a1, s32 a2, Key_Combat_DispatchAttack_0_00139D30 *a3, s32 *t0, s32 t1) {
    s32 a;

    switch (a3->h8) {
    case 0:
        if (t1 != 0) {
            Attack_PlaySe_0_001D1E80(a0, a2, a3, t0, t1);
        }
        break;
    case 1:
        Combat_UpdateProjectile_0_001395A0(a0, a1, a2, a3, t0, t1);
        break;
    case 2:
        Combat_UpdateAttack_0_00139330(a0, a1, a2, a3, t0, t1);
        break;
    case 3:
        a = ActorList_GetCount_1_001A5430(a0, a1, a2, a3, t0, t1);
        t0 += a3->hE;
        if (*t0 == 0) {
            Enemy_Set5B6b3_1_0013EAB0(a, 1);
        }
        if (*t0 == 1) {
            Enemy_Set5B6b2_1_0013EAE0(a, 1);
        }
        break;
    }
}
#undef Combat_UpdateProjectile_0_001395A0
#undef Combat_UpdateAttack_0_00139330
#undef ActorList_GetCount_1_001A5430

/* Actor_UpdateAttachedColliders_0_00139E20 */
#define sceVu0AddVector sceVu0AddVector__as_Actor_UpdateAttachedColliders_0_00139E20
void sceVu0AddVector__as_Actor_UpdateAttachedColliders_0_00139E20(u8 *, s32, V *);
#define sceVu0SubVector sceVu0SubVector__as_Actor_UpdateAttachedColliders_0_00139E20
void sceVu0SubVector__as_Actor_UpdateAttachedColliders_0_00139E20(V *, u8 *, s32);

void Actor_UpdateAttachedColliders_0_00139E20(s8 *arg0) {
    u8 spA0[16];
    u8 sp70[48];
    V sp60;
    V sp50;
    T *s0;
    s8 *v0;
    v0 = M2C_FIELD(arg0, s8 **, 0x518);
    s0 = (T *)(v0 + 0x180);
    if (M2C_FIELD(v0, s32 *, 0x274) != 0 && Enemy_GetAttachMatrix_0_001A5AA0(arg0, s0, sp70) != 0 && Enemy_Get5B2b5_1_0013E780(arg0) != 0) {
        sceVu0SubVector(&sp60, s0->v40, s0->v10 + 0x100);
        sp60.w = 1.0f;
        sceVu0ApplyMatrix(&sp50, sp70, &sp60);
        sceVu0AddVector(s0->v40, s0->v10 + 0x100, &sp50);
        Enemy_GetForwardVector_2_001403D0(arg0, &sp60);
        sp60.w = 0.0f;
        sceVu0ApplyMatrix(&sp50, sp70, &sp60);
        {
            f32 f = Vec_YawAngle_2_0013FC10(&sp50);
            M2C_FIELD(Enemy_GetRotationPtr_1_00140430(arg0), f32 *, 4) = f;
        }
        Actor_OffsetColliders_1_00137730(arg0, spA0);
    }
    if (Enemy_Get5B2b5_1_0013E780(arg0) != 0) {
        s0->v54 = 0;
    }
}
#undef sceVu0AddVector
#undef sceVu0SubVector

/* Actor_ProcessHitEvents_0_00139F30 */
#define D_00201E80 D_00201E80__as_Actor_ProcessHitEvents_0_00139F30
extern Obj **D_00201E80__as_Actor_ProcessHitEvents_0_00139F30[2];
#define DE D_00201E80

void Actor_ProcessHitEvents_0_00139F30(Actor *a) {
    s8 *b;
    s8 *u;
    Ev *ev;
    Obj *obj;
    Hit_Actor_ProcessHitEvents_0_00139F30 *r1;
    Hit_Actor_ProcessHitEvents_0_00139F30 *r2;
    void *pos;
    Hit_Actor_ProcessHitEvents_0_00139F30 *hit;
    obj = 0;
    r1 = 0;
    r2 = 0;
    u = a->unk518;
    b = u + 0x180;
    hit = 0;
    ev = *(Ev **)(u + 0x27C);
    pos = b + 0xD0;
    Enemy_Set608_1_0013E2A0(a, -1);
    if (DE[2]) {
        obj = *DE[2];
        r1 = MapObj_FindCollider_0_001B1D00(obj, pos);
        if (!r1) {
            r2 = MapObj_GetSection_0_001B1CB0(obj, pos, &hit);
            if (!r2) obj = 0;
        }
    }
    if (!obj && DE[3]) {
        obj = *DE[3];
        r1 = MapObj_FindCollider_0_001B1D00(obj, pos);
        if (!r1) {
            r2 = MapObj_GetSection_0_001B1CB0(obj, pos, &hit);
            if (!r2) obj = 0;
        }
    }
    if (obj) {
        (*(St **)(b + 0x10))->xC0 = obj;
        (*(St **)(b + 0x10))->xC4 = r1;
        (*(St **)(b + 0x10))->xC8 = r2;
        (*(St **)(b + 0x10))->xCC = hit;
        if (r2) {
            (*(St **)(b + 0x10))->x110 = (*(St **)(b + 0x10))->x114;
            (*(St **)(b + 0x10))->x114 = hit->x48;
        } else {
            (*(St **)(b + 0x10))->x110 = (*(St **)(b + 0x10))->x114;
            (*(St **)(b + 0x10))->x114 = 0;
        }
    }
    Actor_SpawnEffect_0_001374E0(a, obj, r1, r2);
    if (Ent_IsNull0_1_0013EE30(a)) {
        if (DE[2]) {
            Obj *o = *DE[2];
            o->x8C = -1;
            o->xAC = 0;
            o->xB0 = 0;
        }
        if (DE[3]) {
            Obj *o = *DE[3];
            o->x8C = -1;
            o->xAC = 0;
            o->xB0 = 0;
        }
        if (obj) {
            if (r1) obj->x8C = r1->x20;
            if (r2) obj->x8C = r2->x20;
            obj->xAC = r1;
            obj->xB0 = r2;
        }
    }
    if (ev) {
        switch (ev->t) {
        case 2:
            Enemy_Set608_1_0013E2A0(a, ev->lo);
            break;
        case 3:
            break;
        }
    }
}
#undef D_00201E80
#undef DE

/* Actor_ResolveActorCollisionB_1_0013A190 */

void Actor_ResolveActorCollisionB_1_0013A190(s8 *arg0) {
    f32 vec[4] __attribute__((aligned(16)));
    s32 it;
    s8 *o;
    s8 *other;
    f32 *y;

    o = M2C_FIELD(arg0, s8 **, 0x518) + 0x180;
    it = 0;
    sceVu0CopyVector(vec, o + 0x50);
    y = &vec[1];
    *y = 0.0f;
    if (sqrtf(sceVu0InnerProduct(vec, vec)) < 0.1f) return;
    it = 0;
    other = ActorList_Next_2_001A5460(&it);
    if (other != NULL) {
        do {
            if (other != arg0 && !(Enemy_Get5B2m1_1_0013E8B0(other) & 0xFF)) {
                if (Actor_CollideCapsulesB_0_00137E60(arg0, other, vec)) {
                    if (*y > 0.0f) {
                        *y = 0.0f;
                    }
                    sceVu0AddVector(o + 0x40, o + 0x40, vec);
                    Actor_OffsetColliders_1_00137730(arg0, vec);
                }
            }
            other = ActorList_Next_2_001A5460(&it);
        } while (other != NULL);
    }
}

/* Actor_ResolveActorCollision_0_0013A2C0 */

void Actor_ResolveActorCollision_0_0013A2C0(s8 *arg0) {
    f32 vec[4] __attribute__((aligned(16)));
    s32 it;
    s8 *o;
    s8 *other;
    o = M2C_FIELD(arg0, s8 **, 0x518) + 0x180;
    it = 0;
    if ((Enemy_Get5B2m1_1_0013E8B0(arg0) & 0xFF) != 1 && (Enemy_Get5B1b6_1_0013E910(arg0) & 0xFF) != 1) {
        it = 0;
        other = ActorList_Next_2_001A5460(&it);
        if (other != NULL) {
            do {
                if (other != arg0 && !(Enemy_Get5B2m1_1_0013E8B0(other) & 0xFF)) {
                    if (Ent_IsNull0_1_0013EE30(other)) {
                        if (Actor_CollideCapsules_0_00137870(arg0, other, vec)) {
                            Enemy_Set5B4b0_1_0013E6A0(arg0, 1);
                            if (vec[1] > 0.0f) {
                                vec[1] = 0.0f;
                            }
                            sceVu0AddVector(o + 0x40, o + 0x40, vec);
                            Actor_OffsetColliders_1_00137730(arg0, vec);
                        }
                    } else if (Actor_PushApart_0_00138460(arg0, other, vec)) {
                        if (vec[1] > 0.0f) {
                            vec[1] = 0.0f;
                        }
                        sceVu0AddVector(o + 0x40, o + 0x40, vec);
                        Actor_OffsetColliders_1_00137730(arg0, vec);
                    }
                }
                other = ActorList_Next_2_001A5460(&it);
            } while (other != NULL);
        }
    }
}

/* Actor_ResolveWallCollision_0_0013A450 */

void Actor_ResolveWallCollision_0_0013A450(Actor *a) {
    u8 found;
    s8 *base = a->unk518 + 0x180;
    s32 m1 = 1;
    s32 m2 = 2;
    s8 i;
    f32 *w;
    s32 n;
    s32 ok;
    Vec A = {0};

    sceVu0CopyVector(&a->pad60C[0x94], &A);
    if (((Sub4B0 *)a->unk4B0)->b5 && !Enemy_Get5B2b1_1_0013E880(a)) {
        if (!Enemy_Get5B1b7_1_0013E8E0(a)) {
            m1 |= 2;
        }
        if (!(u8)Enemy_Get5B2b6w2_1_0013E750(a)) {
            m2 |= 0x10;
        }
        {
        Vec E = {0};
        Vec C[2];
        Big B;
        found = 0;
        n = Enemy_Get81_1_0013FC00(a);
        if (n > 0) {
            w = &A.w;
            for (i = n - 1; i >= 0; i--) {
                ok = (u8)Actor_CollideSegment_0_00138920(a, i, m2, m1, &A, 1);
                *w = 0.0f;
                if (ok) {
                    *w = 0.0f;
                    sceVu0AddVector((Vec *)(base + 0x40), (Vec *)(base + 0x40), &A);
                    Actor_OffsetColliders_1_00137730(a, &A);
                    Enemy_Set5B4b1_1_0013E670(a, 1);
                    sceVu0CopyVector(&a->pad60C[0x94], &A);
                }
            }
        } else {
            sceVu0CopyVector(C, base + 0x40);
            C[0].y -= 100.0f;
            w = &C[0].w;
            *w = 100.0f;
            memset(&B, 0, 0x40);
            if ((&D_00201E80)[2]) {
                Enemy_RaycastMapA_0_0013D250(*(s32 *)(&D_00201E80)[2], &B, C, m2, m1);
            }
            if ((&D_00201E80)[3]) {
                Enemy_RaycastMapA_0_0013D250(*(s32 *)(&D_00201E80)[3], &B, C, m2, m1);
            }
            if (B.x24) {
                sceVu0ScaleVector(&E, &B.b, *w);
                sceVu0AddVector(&E, &E, &B);
                sceVu0SubVector(&E, &E, C);
                found = 1;
            }
        }
        if (found) {
            E.y = 0.0f;
            E.w = 0.0f;
            sceVu0AddVector((Vec *)(base + 0x40), (Vec *)(base + 0x40), &E);
            Actor_OffsetColliders_1_00137730(a, &E);
            Enemy_Set5B4b1_1_0013E670(a, 1);
        }
        }
    }
}

/* Actor_ResolveGround_0_0013A720 */
#define Sfx_SetOwner_1_00167600 Sfx_SetOwner_1_00167600__as_Actor_ResolveGround_0_0013A720
void Sfx_SetOwner_1_00167600__as_Actor_ResolveGround_0_0013A720(s32, Actor *);

void Actor_ResolveGround_0_0013A720(Actor *a) {
    P *p;
    s32 fl;
    s32 h;
    s32 *q;
    s32 r;
    Vec tmp;
    Seg_Actor_ResolveGround_0_0013A720 seg;
    Hit_Actor_ResolveGround_0_0013A720 hit;
    Vec v;
    Mtx m;

    fl = 1;
    p = (P *)(a->unk518 + 0x180);
    if (!((Flags8 *)(a->unk4B0 + 0x2AC))->f.b4) return;
    if (!Enemy_Get5B1b7_1_0013E8E0(a)) fl |= 2;
    sceVu0CopyVector(&p->xB0.s, &p->x40);
    p->xB0.s.w = 1.0f;
    sceVu0CopyVector(&p->xB0.e, &p->x40);
    p->xB0.e.w = 1.0f;
    p->xB0.s.y = p->x10[5];
    if (!(p->xB0.s.y <= p->xB0.e.y)) {
        sceVu0CopyVector(&tmp, &p->xB0.s);
        sceVu0CopyVector(&p->xB0.s, &p->xB0.e);
        sceVu0CopyVector(&p->xB0.e, &tmp);
    }
    {
        Tb *tb = (Tb*)p->x2C; f32 d = tb->e[p->x18->xB5].f - tb->e[p->x18->xB4].f;
        if (d < -80.0f) {
            p->xB0.s.y += d;
        } else {
            p->xB0.s.y += -80.0f;
        }
    }
    p->xB0.e.y += 1000.0f;
    memset(&p->xD0, 0, 0x40);
    if (((s32 **)&D_00201E80)[2] != NULL) {
        Enemy_RaycastMapC_0_0013D430(*((s32 **)&D_00201E80)[2], &p->xD0, &p->xB0, 4, fl);
    }
    q = ((s32 **)&D_00201E80)[3];
    if (q != NULL) {
        if (p->xD0.hit == 0) {
            Enemy_RaycastMapC_0_0013D430(*q, &p->xD0, &p->xB0, 4, fl);
        } else if (!(p->xD0.p.y < p->xB0.e.y - 1000.0f)) {
            *(SegQ *)&seg = *(SegQ *)&p->xB0;
            *(HitQ *)&hit = *(HitQ *)&p->xD0;
            hit.hit = 0;
            Enemy_RaycastMapC_0_0013D430(*q, &hit, &seg, 4, fl);
            if (hit.hit != 0 && hit.p.y < p->xD0.p.y) {
                *(SegQ *)&p->xB0 = *(SegQ *)&seg;
                *(HitQ *)&p->xD0 = *(HitQ *)&hit;
            }
        }
    }
    if (p->xD0.hit != 0) {
        if (p->xD0.p.y < p->xB0.e.y - 1000.0f) {
            sceVu0SubVector(&v, &p->xD0, &p->x40);
            v.x = 0.0f;
            v.z = 0.0f;
            v.w = 0.0f;
            sceVu0AddVector(&p->x40, &p->x40, &v);
            Enemy_Set5B2b5_1_0013E760(a, 1);
            if (!(Enemy_GetHeightAboveFloor_0_0013E3C0(a) <= 100.0f)) {
                r = Enemy_Get608_1_0013E290(a);
                if (r >= 0) {
                    h = D_001F1C10[r];
                    if (h >= 0 && Sfx_IsLoaded_2_00169BB0(h)) {
                        h = Sfx_Spawn_2_00169B50(h, 0, 0, 0);
                        if (h != 0) {
                            sceVu0CopyMatrix(&m, &D_001F2170);
                            sceVu0CopyVector(&m.m[3], &p->x40);
                            Sfx_SetTransform_1_001677C0(h, &m);
                            Sfx_SetOwner_1_00167600(h, a);
                        }
                    }
                }
            }
            Actor_OffsetColliders_1_00137730(a, &v);
        } else {
            Enemy_Set5B2b5_1_0013E760(a, 0);
        }
    } else {
        Enemy_Set5B2b5_1_0013E760(a, 0);
    }
}
#undef Sfx_SetOwner_1_00167600
