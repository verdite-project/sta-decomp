#include "actor.h"
#include "common.h"
#include "m2c.h"
#include "game/entity.h"
typedef struct { u8 pad[8]; u16 id; u8 pad2[2]; f32 f; } Mdl;
typedef struct {
    u8 pad[0x18];
    s8 *p18;
    u8 pad1C[0xC];
    Mdl *p28;
    s8 *p2C;
    u8 pad30[0x10];
    Vec m40;
    u8 pad50[0x10];
    Vec m60;
    u8 pad70[0x30];
    Vec mA0;
} Sub_Actor_UpdateAttachments_0_0013AB00;
typedef struct { u8 pad[0x140]; s16 id; u8 p142[2]; f32 f144; u8 p148[8]; f32 f150; } Ent_Actor_UpdateAttachments_0_0013AB00;
typedef struct { u8 pad[0x2A]; u8 a; u8 b; } Pt_Actor_UpdateAttachments_0_0013AB00;
typedef struct { u8 pad[0x7C]; u32 n; } A7C;
typedef struct { u8 pad[0x2A]; u8 x2A; } Pt_Actor_UpdatePhysics_0_0013ACE0;
typedef struct { u8 pad[0x2C]; s8 *x2C; u8 pad30[0x10]; Vec x40; Vec x50; } Sub_Actor_UpdatePhysics_0_0013ACE0;
typedef struct { u8 pad[0xA0]; Vec xA0; u8 padB0[0x10]; Vec xC0; Vec xD0; Mtx xE0; Vec x120; Vec x130; } E;
typedef struct { u8 pad[8]; u16 id; u8 pada[2]; f32 x; f32 y; } Anim;
typedef struct { u8 pad[0x10]; Vec v; u8 pad20[0xA0]; s32 xC0; } Sub10;
typedef struct { u8 pad[0x40]; Vec v; } Sub18;
typedef struct {
    u8 pad[0x10];
    Sub10 *p10;
    u8 pad14[4];
    Sub18 *p18;
    u8 pad1C[0xC];
    Anim *p28;
    u8 pad2C[0x14];
    Vec v40;
    Vec v50;
    u8 pad60[0x40];
    Vec vA0;
    u8 padB0[0x44];
    s32 xF4;
} Body;
typedef struct Obj_Actor_UpdateAttachments_0_0013AB00 Obj_Actor_UpdateAttachments_0_0013AB00;
typedef void (*Cb)(Obj_Actor_UpdateAttachments_0_0013AB00 *, f32);
typedef struct { Vec a, b; Mtx m; u32 col; } Buf;
typedef struct { Vec v0; Vec v10; u8 pad[0xA]; u8 x2A; u8 x2B; u8 x2C; Flags8 f2D; u8 pad2[0x72]; Vec vA0; } Pt_Actor_UpdateTransform_0_0013B4F0;
typedef struct { u8 pad[0x160]; u8 x160; } Ent_Actor_UpdateTransform_0_0013B4F0;
typedef struct { Vec a, b, c, d; u8 pad[0x130]; } Bone;
typedef struct { u8 pad[0xB6]; u8 xB6; u8 xB7; } S18;
typedef struct { u8 pad[0x16]; u16 x16; } S0C;
typedef struct { u8 pad[4]; f32 f4; u8 pad8[4]; S0C **pC; u8 pad10[4]; Bone *p14; S18 *p18; u8 pad1C[0x10]; s8 *p2C; } Sub_Actor_UpdateTransform_0_0013B4F0;
typedef struct { Vec *p; } __attribute__((aligned(16))) PV;
typedef struct { u8 r:7; u8 b7:1; } F7;
typedef struct { char pad[0x160]; u8 flags; } S;
typedef struct { u8 pad[0x5A0]; u8 b0:1; u8 b1:1; u8 b2:1; } Ent;
typedef struct { char pad[0x1A4]; s32 v; } B;
typedef struct { char pad[0x518]; B *b; } Obj_Actor_IsFlag1Clear_1_0013BA70;
extern Mtx gMatrixFromData_001F2170;
extern s32 gMapSbss_00201E80;
extern F7 D_00222A51[];
void Actor_UpdateAttachments_0_0013AB00(Actor *a0, f32 f);
void Actor_UpdatePhysics_0_0013ACE0(Actor *a, f32 g);
void Actor_UpdateCollision_0_0013B220(Obj_Actor_UpdateAttachments_0_0013AB00 *a, s32 skip, f32 dt);
void Actor_UpdateTransform_0_0013B4F0(Actor *a, s32 flag, f32 f);
void Combat_UpdateAttackWrap_0_0013B950(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void Actor_Translate_1_0013B960(s8 *arg0, f32 *arg1);
void Combat_ProcessHitWrap_0_0013BA60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u8 Actor_IsFlag1Clear_1_0013BA70(s32 arg0, s32 arg1, S *s);
u8 Actor_CanTarget_0_0013BA90(s8 *a0, Ent *a1);
void EnemyScr_Event2012_1_001419C0(Actor *, f32);
void Enemy_UpdateMotion_1_0013CBC0(Actor *, f32);
void Mdl_AnimateWrap_0_00171B70(Mdl *, u16, f32);
Pt_Actor_UpdateAttachments_0_0013AB00* Enemy_GetPartValue_1_0013DCA0(Actor *, u8);
Ent_Actor_UpdateAttachments_0_0013AB00* Enemy_GetPart_1_0013DC70(Actor *, u8);
void Mdl_AnimateCur_0_00171AF0(Mdl *, u16, u8, u8, f32);
void Mdl_BlendMotion_0_00171980(Mdl *, u16, u8, u8, f32, f32);
void sceVu0SubVector(Vec*, void *, void *);
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(void *, void *);
void Actor_UpdateBones_0_001370A0(Actor *);
void sceVu0ApplyMatrix(Vec*, void *, void *);
void sceVu0AddVector(void *, void *, void *);
u32 Enemy_Get5B2b6w2_1_0013E750(Actor *);
void sceVu0ScaleVector(Vec *, void *, f32);
void EnemyScr_Event2023_1_00140CB0(Actor *, u8 *, f32 *, f32 *);
s8* Enemy_GetParamPtr290_1_0013DE50(Actor *);
f32* Enemy_GetModelData_1_0013DCE0(Actor *);
void Enemy_SyncPosition_0_0013E370(Actor *);
f32 Enemy_GetHeightAboveFloor_0_0013E3C0(Actor *);
s32 Ent_IsNull0_1_0013EE30(void *);
s32 Enemy_IsDead_1_0013EEE0(Actor *);
u16 Enemy_GetMaxHp_2_0013F700(Actor *);
void Enemy_AddHp_2_0013F710(Actor *, s32);
void Enemy_Kill_1_0013EF80(Actor *, s32);
s32 Enemy_GetHpPercent_2_0013F620(Actor *);
void EnemyScr_Event200COnHit_1_00142320(Actor *, s32, u8);
void Enemy_Get5B3b2_1_0013E820(Actor *);
void Enemy_SetStateResetTimer_1_0013E7E0(Actor *, u8);
void Quat_ToMatrixB_2_0015E580(Mtx *, void *);
void sceVu0MulMatrix(void *, void *, void *);
f32* Enemy_GetPositionPtr_2_00140460(Actor *);
void Enemy_HidePart_1_001A8B10(Actor *, u8);
void Enemy_Set5B6b2_1_0013EAE0(Obj_Actor_UpdateAttachments_0_0013AB00 *, s32);
void Enemy_Set5B6b3_1_0013EAB0(Obj_Actor_UpdateAttachments_0_0013AB00 *, s32);
void Mdl_RunMotionEvents_0_001717A0(Anim *, u16, f32, f32, void *);
void Combat_DispatchAttack_0_00139D30();
void Actor_OffsetColliders_1_00137730(Obj_Actor_UpdateAttachments_0_0013AB00 *, Vec *);
void Actor_ResolveActorCollision_0_0013A2C0(Obj_Actor_UpdateAttachments_0_0013AB00 *, f32);
void Actor_ResolveWallCollision_0_0013A450(Obj_Actor_UpdateAttachments_0_0013AB00 *, f32);
void Actor_ResolveGround_0_0013A720(Obj_Actor_UpdateAttachments_0_0013AB00 *, f32);
void Enemy_UpdateAI_1_00136400(Obj_Actor_UpdateAttachments_0_0013AB00 *, f32);
void Actor_ResolveActorCollisionB_1_0013A190(Obj_Actor_UpdateAttachments_0_0013AB00 *, f32);
void Actor_ProcessHitEvents_0_00139F30(Obj_Actor_UpdateAttachments_0_0013AB00 *);
void Actor_UpdateAttachedColliders_0_00139E20(Obj_Actor_UpdateAttachments_0_0013AB00 *);
void Player_UpdateArmBones_0_001C5DE0(Obj_Actor_UpdateAttachments_0_0013AB00 *);
void Enemy_UpdateSfxTransform_0_001A83E0(Obj_Actor_UpdateAttachments_0_0013AB00 *);
u8 Enemy_Get81_1_0013FC00(Actor *);
s32 Enemy_GetCollider_0_0013FB90(void *, u8, void *, void *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void Draw_ShadowDisc_0_00156920(Buf *);
f32 sqrtf(f32);
void sceVu0SubVector__as_Actor_UpdateAttachments_0_0013AB00(Vec *, s8 *, s8 *);
void sceVu0CopyVector__as_Actor_UpdateAttachments_0_0013AB00(s8 *, s8 *);
void sceVu0CopyMatrix__as_Actor_UpdateAttachments_0_0013AB00(s8 *, s8 *);
void sceVu0ApplyMatrix__as_Actor_UpdateAttachments_0_0013AB00(Vec *, Vec *, Vec *);
void sceVu0AddVector__as_Actor_UpdateAttachments_0_0013AB00(Vec *, Vec *, Vec *);
s32 Ent_IsNull0_1_0013EE30__as_Actor_UpdatePhysics_0_0013ACE0(Actor *);
Pt_Actor_UpdatePhysics_0_0013ACE0* Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdatePhysics_0_0013ACE0(Actor *, u8);
E* Enemy_GetPart_1_0013DC70__as_Actor_UpdatePhysics_0_0013ACE0(Actor *, u8);
void sceVu0SubVector__as_Actor_UpdateCollision_0_0013B220(Vec *, Vec *, Vec *);
s32 Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220(Obj_Actor_UpdateAttachments_0_0013AB00 *);
s32 Ent_IsNull0_1_0013EE30__as_Actor_UpdateTransform_0_0013B4F0(Actor *);
Pt_Actor_UpdateTransform_0_0013B4F0* Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdateTransform_0_0013B4F0(Actor *, u8);
Ent_Actor_UpdateTransform_0_0013B4F0* Enemy_GetPart_1_0013DC70__as_Actor_UpdateTransform_0_0013B4F0(Actor *, u8);
void sceVu0CopyMatrix__as_Actor_UpdateTransform_0_0013B4F0(Mtx *, void *);
void sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(Vec *, Vec *);
void sceVu0ApplyMatrix__as_Actor_UpdateTransform_0_0013B4F0(Vec *, Mtx *, Vec *);
void sceVu0SubVector__as_Actor_UpdateTransform_0_0013B4F0(Vec *, Vec *, Vec *);
s32 Enemy_GetCollider_0_0013FB90__as_Actor_UpdateAttachments_0_0013AB00_(Actor *, u8, Vec **, Vec **);
void sceVu0AddVector__as_Actor_Translate_1_0013B960(f32 *, f32 *, f32 *);
s32 Enemy_GetCollider_0_0013FB90__as_Actor_Translate_1_0013B960(s8 *, u8, f32 **, f32 **);
s32 Enemy_Get81_1_0013FC00__as_Actor_Translate_1_0013B960(s8 *);
s32 Enemy_IsAiDisabled_0_0013D6B0(void);
s32 Ent_GetTypeByte_1_0013E220(Ent *);
u8 EnemyScr_Event2001_1_00142820(Ent *, s32);
Ent* Sfx_GetOwner_1_001675D0(s8 *);
Obj_Actor_IsFlag1Clear_1_0013BA70* ActorList_Next_2_001A5460(s32 *it);
void Mdl_ResetBones_0_00171610(s32 v);

/* Actor_UpdateAttachments_0_0013AB00__ */
/* Actor_UpdateAttachments_0_0013AB00_ */

/* Actor_UpdateAttachments_0_0013AB00 */

void Actor_UpdateAttachments_0_0013AB00(Actor *a0, f32 f) {
    Sub_Actor_UpdateAttachments_0_0013AB00 *s;
    u32 i;
    Pt_Actor_UpdateAttachments_0_0013AB00 *pt;
    Ent_Actor_UpdateAttachments_0_0013AB00 *e;
    s8 *b;
    Vec v;
    void (*cb)(Actor *, f32);

    b = a0->unk518;
    s = (Sub_Actor_UpdateAttachments_0_0013AB00 *)(b + 0x180);
    if (*(u16 *)(**(s8 ***)(b + 0x18C) + 0x16) == 0) {
        return;
    }
    if (a0->flags5B7.f.b6) {
        f = 0.0f;
    }
    cb = *(void (**)(Actor *, f32))((s8 *)a0 + 0x538);
    if (cb != 0) {
        cb(a0, f);
        return;
    }
    EnemyScr_Event2012_1_001419C0(a0, f);
    Enemy_UpdateMotion_1_0013CBC0(a0, f);
    Mdl_AnimateWrap_0_00171B70(s->p28, s->p28->id, s->p28->f);
    for (i = 0; i < *(u32 *)(a0->pad000 + 0x7C); i++) {
        pt = Enemy_GetPartValue_1_0013DCA0(a0, i);
        e = Enemy_GetPart_1_0013DC70(a0, i);
        { f32 w = e->f150; s16 id; f32 g; s32 a; s32 b2; if (w != 0.0f) { id = e->id; g = e->f144; a = pt->a; b2 = pt->b;
            if (w == 1.0f) {
                Mdl_AnimateCur_0_00171AF0(s->p28, id, a, b2, g);
            } else {
                Mdl_BlendMotion_0_00171980(s->p28, id, a, b2, g, 1.0f - w);
            }
        } }
    }
    sceVu0SubVector__as_Actor_UpdateAttachments_0_0013AB00(&v, s->p2C + 0x2B0, s->p18 + 0xA0);
    sceVu0CopyVector__as_Actor_UpdateAttachments_0_0013AB00(s->p18 + 0xA0, s->p2C + 0x2B0);
    sceVu0CopyMatrix__as_Actor_UpdateAttachments_0_0013AB00(s->p2C + 0x280, s->p18 + 0x60);
    Actor_UpdateBones_0_001370A0(a0);
    sceVu0ApplyMatrix__as_Actor_UpdateAttachments_0_0013AB00(&s->mA0, &s->m60, &v);
    sceVu0AddVector__as_Actor_UpdateAttachments_0_0013AB00(&s->m40, &s->m40, &s->mA0);
}

/* Actor_UpdatePhysics_0_0013ACE0 */
#define FF(p, o) (*(f32 *)((s8 *)(p) + (o)))

void Actor_UpdatePhysics_0_0013ACE0(Actor *a, f32 g) {
    s32 i;
    Sub_Actor_UpdatePhysics_0_0013ACE0 *S;
    u8 r;
    f32 k;
    S = (Sub_Actor_UpdatePhysics_0_0013ACE0 *)(a->unk518 + 0x180);
    r = Enemy_Get5B2b6w2_1_0013E750(a);
    k = 3920.0f * g;
    S->x50.y += k;
    if (r == 0) {
        Vec v;
        sceVu0ScaleVector(&v, &S->x50, g);
        sceVu0AddVector(&S->x40, &v, &S->x40);
    } else if (r == 1) {
        Vec v;
        sceVu0ScaleVector(&v, &S->x50, g);
        sceVu0AddVector(&S->x40, &v, &S->x40);
    } else if (r == 2) {
        Vec v;
        S->x50.y = 0.0f;
        sceVu0ScaleVector(&v, &S->x50, g);
        sceVu0AddVector(&S->x40, &v, &S->x40);
    } else {
        u8 t = 0;
        f32 m = 2.0f;
        f32 b = 0.0f;
        f32 *p;
        EnemyScr_Event2023_1_00140CB0(a, &t, &m, &b);
        switch (t) {
        case 0:
            b += FF(a, 0x644);
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 1:
            b += FF(a, 0x684);
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 2:
            b += FF(a, 0x664);
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 3:
            p = Enemy_GetModelData_1_0013DCE0(a);
            if (p) b += p[1];
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 4:
            p = Enemy_GetModelData_1_0013DCE0(a);
            if (p) b += p[1];
            break;
        }
        b -= S->x40.y;
        m *= g;
        if (!(b <= m)) b = m;
        if (b < -m) b = -m;
        S->x40.y += b;
        S->x50.y = 0.0f;
    }
    if (!(S->x40.y <= 20000.0f)) {
        S->x40.y = 20000.0f;
        S->x50.y = 0.0f;
    }
    Enemy_SyncPosition_0_0013E370(a);
    if (!(Enemy_GetHeightAboveFloor_0_0013E3C0(a) <= 2000.0f) && !Ent_IsNull0_1_0013EE30__as_Actor_UpdatePhysics_0_0013ACE0(a)) {
        if (!Enemy_IsDead_1_0013EEE0(a)) {
            Enemy_AddHp_2_0013F710(a, -Enemy_GetMaxHp_2_0013F700(a) - 1);
            Enemy_Kill_1_0013EF80(a, 0);
            EnemyScr_Event200COnHit_1_00142320(a, 0, Enemy_GetHpPercent_2_0013F620(a));
        }
        Enemy_Get5B3b2_1_0013E820(a);
        Enemy_SetStateResetTimer_1_0013E7E0(a, 1);
    }
    for (i = 0; i < a->pad000[0x80]; i++) {
        u8 id;
        E *e;
        u8 n;
        Pt_Actor_UpdatePhysics_0_0013ACE0 *p;
        Vec v;
        Mtx M;
        Mtx M2;
        Vec V;
        id = a->pad520[i];
        p = Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdatePhysics_0_0013ACE0(a, id);
        e = Enemy_GetPart_1_0013DC70__as_Actor_UpdatePhysics_0_0013ACE0(a, id);
        n = p->x2A;
        e->xD0.y += k * 0.25f;
        sceVu0ScaleVector(&v, &e->xD0, g);
        sceVu0AddVector(&e->xA0, &v, &e->xA0);
        sceVu0CopyMatrix(&M, &gMatrixFromData_001F2170);
        M.m[0].x = e->xC0.x;
        M.m[1].y = e->xC0.y;
        M.m[2].z = e->xC0.z;
        Quat_ToMatrixB_2_0015E580(&M2, &e->x130);
        sceVu0MulMatrix(&e->xE0, &e->xE0, &M2);
        sceVu0ApplyMatrix(&V, &e->xE0, &e->x120);
        sceVu0MulMatrix(&M, &M, &e->xE0);
        sceVu0AddVector(&M.m[3], &e->xA0, &V);
        sceVu0CopyMatrix(S->x2C + (n + 1) * 0x140 + 0x100, &M);
        if (!(e->xA0.y - Enemy_GetPositionPtr_2_00140460(a)[1] <= 5000.0f)) {
            Enemy_HidePart_1_001A8B10(a, id);
            e->xA0.y = 5000.0f + Enemy_GetPositionPtr_2_00140460(a)[1];
        }
    }
}

/* Actor_UpdateCollision_0_0013B220 */
struct Obj_Actor_UpdateAttachments_0_0013AB00 {
    u8 pad[0x518];
    s8 *unk518;
    u8 pad51C[0x1C];
    s32 x538;
    Cb f53C;
    Cb f540;
    Cb f544;
    void *f548;
};

void Actor_UpdateCollision_0_0013B220(Obj_Actor_UpdateAttachments_0_0013AB00 *a, s32 skip, f32 dt) {
    Body *b;
    Vec v;

    b = (Body *)(a->unk518 + 0x180);
    if (!Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220(a) && skip) {
        return;
    }
    Enemy_Set5B6b2_1_0013EAE0(a, 0);
    Enemy_Set5B6b3_1_0013EAB0(a, 0);
    if (a->f548) {
        Mdl_RunMotionEvents_0_001717A0(b->p28, b->p28->id, b->p28->x, b->p28->y, a->f548);
    } else {
        Mdl_RunMotionEvents_0_001717A0(b->p28, b->p28->id, b->p28->x, b->p28->y, Combat_DispatchAttack_0_00139D30);
    }
    if (!Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220(a)) {
        Actor_OffsetColliders_1_00137730(a, &b->vA0);
        Actor_ResolveActorCollision_0_0013A2C0(a, dt);
    }
    if (!Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220(a) && ((&gMapSbss_00201E80)[2] || (&gMapSbss_00201E80)[3])) {
        if (a->f53C) {
            a->f53C(a, dt);
        } else {
            Actor_ResolveWallCollision_0_0013A450(a, dt);
            Actor_ResolveGround_0_0013A720(a, dt);
        }
    }
    if (!skip) {
        if (a->f540) {
            a->f540(a, dt);
        } else {
            Enemy_UpdateAI_1_00136400(a, dt);
        }
    }
    if (Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220(a)) {
        sceVu0SubVector__as_Actor_UpdateCollision_0_0013B220(&v, &b->v40, &b->p10->v);
        Actor_OffsetColliders_1_00137730(a, &v);
        Actor_ResolveActorCollisionB_1_0013A190(a, dt);
        sceVu0CopyVector(&v, &b->v40);
        if (a->f53C) {
            a->f53C(a, dt);
        }
        b->p10->xC0 = 0;
        if (b->xF4) {
            Actor_ProcessHitEvents_0_00139F30(a);
        }
        if (a->f544) {
            a->f544(a, dt);
        }
        sceVu0SubVector__as_Actor_UpdateCollision_0_0013B220(&v, &b->v40, &v);
        Actor_OffsetColliders_1_00137730(a, &v);
    } else {
        b->p10->xC0 = 0;
        Actor_ProcessHitEvents_0_00139F30(a);
        if (a->f544) {
            a->f544(a, dt);
        } else {
            Actor_UpdateAttachedColliders_0_00139E20(a);
        }
    }
    if (a->x538) {
        if (Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220(a)) {
            Player_UpdateArmBones_0_001C5DE0(a);
        }
    } else {
        Enemy_UpdateSfxTransform_0_001A83E0(a);
    }
    sceVu0CopyVector(b->p18, &b->v40);
    sceVu0CopyVector(&b->p18->v, &b->v50);
}

/* Actor_UpdateTransform_0_0013B4F0 */

void Actor_UpdateTransform_0_0013B4F0(Actor *a, s32 flag, f32 f) {
    Mtx M;
    PV P;
    PV Q;
    Vec V;
    Buf L1;
    Mtx M3;
    Buf L2;
    Sub_Actor_UpdateTransform_0_0013B4F0 *s;
    u8 i;
    u8 n;
    Pt_Actor_UpdateTransform_0_0013B4F0 *e;
    u32 j;
    Bone *g;
    Vec *b;

    s = (Sub_Actor_UpdateTransform_0_0013B4F0 *)(a->unk518 + 0x180);
    if (!Ent_IsNull0_1_0013EE30__as_Actor_UpdateTransform_0_0013B4F0(a) && flag) return;
    Actor_UpdatePhysics_0_0013ACE0(a, f);
    if ((*s->pC)->x16 == 0) return;
    Actor_UpdateAttachments_0_0013AB00(a, f);
    n = Enemy_Get81_1_0013FC00(a);
    for (i = 0; i < n; i++) {
        P.p = 0;
        Q.p = 0;
        if ((u8)Enemy_GetCollider_0_0013FB90__as_Actor_UpdateAttachments_0_0013AB00_(a, i, &P.p, &Q.p)) {
            e = Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdateTransform_0_0013B4F0(a, a->unk82[i]);
            sceVu0CopyMatrix__as_Actor_UpdateTransform_0_0013B4F0(&M, s->p2C + (e->x2A + 1) * 0x140 + 0xC0);
            sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(Q.p, P.p);
            sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(&V, &e->vA0);
            V.w = 1.0f;
            sceVu0ApplyMatrix__as_Actor_UpdateTransform_0_0013B4F0(P.p, &M, &V);
            P.p->w = e->vA0.w * s->f4;
            Q.p->w < 0.0f ? sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(Q.p, P.p) : (void)0;
            if (D_00222A51[0].b7 && !Ent_IsNull0_1_0013EE30__as_Actor_UpdateTransform_0_0013B4F0(a)) {
                sceVu0CopyMatrix__as_Actor_UpdateTransform_0_0013B4F0(&L1.m, &gMatrixFromData_001F2170);
                L1.col = 0x4000FF00;
                sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(&L1.a, Q.p);
                sceVu0SubVector__as_Actor_UpdateTransform_0_0013B4F0(&L1.b, P.p, Q.p);
                L1.b.w = sqrtf(sceVu0InnerProduct(&L1.b, &L1.b));
                sceVu0Normalize(&L1.b, &L1.b);
                Draw_ShadowDisc_0_00156920(&L1);
            }
        } else {
            if (P.p) P.p->w = -100.0f;
            if (Q.p) Q.p->w = -100.0f;
        }
    }
        for (j = 0; j < *(u32 *)(a->pad000 + 0x7C); j++) {
            e = Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdateTransform_0_0013B4F0(a, j);
            if (e->f2D.f.b5) {
                sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(&s->p14[j].c, &s->p14[j].a);
                sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(&s->p14[j].d, &s->p14[j].b);
                g = &s->p14[j];
                b = &g->b;
                sceVu0CopyMatrix__as_Actor_UpdateTransform_0_0013B4F0(&M3, s->p2C + (e->x2A + 1) * 0x140 + 0xC0);
                sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(&g->a, &e->v0);
                g->a.w = 1.0f;
                sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(b, &e->v10);
                b->w = 1.0f;
                sceVu0ApplyMatrix__as_Actor_UpdateTransform_0_0013B4F0(&g->a, &M3, &g->a);
                sceVu0ApplyMatrix__as_Actor_UpdateTransform_0_0013B4F0(b, &M3, b);
                sceVu0SubVector__as_Actor_UpdateTransform_0_0013B4F0(b, b, &g->a);
                b->w = 0.0f;
                f = sqrtf(sceVu0InnerProduct(b, b));
                sceVu0Normalize(b, b);
                g->a.w = e->v0.w * s->f4;
                b->w = f;
                if (D_00222A51[0].b7 && !Ent_IsNull0_1_0013EE30__as_Actor_UpdateTransform_0_0013B4F0(a) && !(Enemy_GetPart_1_0013DC70__as_Actor_UpdateTransform_0_0013B4F0(a, j)->x160 & 1) &&
                    j != s->p18->xB7 && j != s->p18->xB6) {
                    sceVu0CopyMatrix__as_Actor_UpdateTransform_0_0013B4F0(&L2.m, &gMatrixFromData_001F2170);
                    L2.col = 0x40FFFFFF;
                    sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(&L2.a, &g->a);
                    sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(&L2.b, b);
                    Draw_ShadowDisc_0_00156920(&L2);
                }
            }
        }
}

/* Combat_UpdateAttackWrap_0_0013B950 */
void Combat_UpdateAttackWrap_0_0013B950(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Combat_UpdateAttack_0_00139330((void *) arg0, arg1, (void *) arg2, arg3, arg4, arg5);
}

/* Actor_Translate_1_0013B960 */

void Actor_Translate_1_0013B960(s8 *arg0, f32 *arg1) {
    f32 *a[4];
    f32 *b[4];
    u8 i;
    u8 n;

    sceVu0AddVector__as_Actor_Translate_1_0013B960((f32 *)(arg0 + 0x620), (f32 *)(arg0 + 0x620), arg1);
    sceVu0AddVector__as_Actor_Translate_1_0013B960((f32 *)(arg0 + 0x640), (f32 *)(arg0 + 0x640), arg1);
    sceVu0AddVector__as_Actor_Translate_1_0013B960((f32 *)(arg0 + 0x660), (f32 *)(arg0 + 0x660), arg1);
    sceVu0AddVector__as_Actor_Translate_1_0013B960((f32 *)(arg0 + 0x680), (f32 *)(arg0 + 0x680), arg1);
    n = Enemy_Get81_1_0013FC00__as_Actor_Translate_1_0013B960(arg0);
    for (i = 0; i < n; i++) {
        a[0] = 0;
        b[0] = 0;
        if ((u8)Enemy_GetCollider_0_0013FB90__as_Actor_Translate_1_0013B960(arg0, i, a, b)) {
            sceVu0AddVector__as_Actor_Translate_1_0013B960(a[0], a[0], arg1);
            sceVu0AddVector__as_Actor_Translate_1_0013B960(b[0], b[0], arg1);
        }
    }
}

/* Combat_ProcessHitWrap_0_0013BA60 */
void Combat_ProcessHitWrap_0_0013BA60(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Combat_ProcessHit_0_00138FB0(arg0, (void *) arg1, arg2, arg3);
}

/* Actor_IsFlag1Clear_1_0013BA70 */
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_Actor_IsFlag1Clear_1_0013BA70
s32 Ent_IsNull0_1_0013EE30__as_Actor_IsFlag1Clear_1_0013BA70(Ent *);

/* Actor_IsFlag1Clear_1_0013BA70 */
u8 Actor_IsFlag1Clear_1_0013BA70(s32 arg0, s32 arg1, S *s)
{
    return !(s->flags & 1);
}

/* Actor_CanTarget_0_0013BA90 */
static inline u8 can(Ent *a0, Ent *a2) {
    if (Ent_IsNull0_1_0013EE30(a0)) {
        if (Ent_IsNull0_1_0013EE30(a2)) return 0;
        return 1;
    }
    return EnemyScr_Event2001_1_00142820(a0, Ent_GetTypeByte_1_0013E220(a2));
}

u8 Actor_CanTarget_0_0013BA90(s8 *a0, Ent *a1) {
    u8 ok;
    Ent *o;
    u8 r;
    ok = 1;
    o = Sfx_GetOwner_1_001675D0(a0);
    if (o && o->b0 && o->b2) {
        if (Enemy_IsAiDisabled_0_0013D6B0()) r = 0; else r = can(o, a1);
        ok = r;
    }
    return ok;
}

/* Actor_UpdateAllVisibility_0_0013BB70 */
void Actor_UpdateAllVisibility_0_0013BB70(void)
{
    s32 it = 0;
    Obj_Actor_IsFlag1Clear_1_0013BA70 *o;
    for (o = ActorList_Next_2_001A5460(&it); o; o = ActorList_Next_2_001A5460(&it))
        Mdl_ResetBones_0_00171610(o->b->v);
}
#undef Ent_IsNull0_1_0013EE30
