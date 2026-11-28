#include "common.h"
#include "m2c.h"
typedef Bits8 B8;
typedef struct { u16 x0; u16 x2; u16 x4; u16 x6; s32 x8; s32 xC; s32 x10; s32 x14; u16 x18; u16 x1A; } E;
typedef struct { f32 v[4]; } V4;
typedef struct { f32 v[8]; } V8;
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; } BF;
typedef struct {
    V4 a;
    V8 b;
    union { u32 w; u8 c[4]; struct { u8 x; BF f; u8 y, z; } s; } u;
    u8 pad[0xC];
} Buf;
typedef struct { u8 pad[4]; u32 w; u8 pad2[8]; V4 a; V8 b; } Src;
#ifndef NONMATCHING
extern s8 gAttackHandleRodata_001FDE10[];
#else
/* data twins (src/game/data/attack_handle_rodata.c): gAttackHandleRodata_001FDE10 */
static s8 gAttackHandleRodata_001FDE10[0x2d] __attribute__((aligned(4))) = "abnormal sfxevent-parameter. in SFX(%d)\012\000\000\000\000\000";
#endif
void Attack_HandleSfxEvent_1_001D3810(s8 *a0, s32 id, E *e, s8 *a3, s32 t0, s32 t1, s32 t2);
void Attack_ApplyHit_0_001D3A90(s8 *a0, s8 *a1, s32 a2, s32 a3, s32 t0, u8 t1);
void Fx_GetWorldMatrix_1_00163C80(s8 *, Vec *);
void sceVu0CopyVector(Vec *, void *);
s32 Snd_PlaySeAttached_1_00131560(s32, s32, s8 *);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetMatrixOrAim_0_00167740(s8 *, void *);
void Mtx_RotateToward_0_00146140(Vec *, f32, f32);
void sprintf(s8 *, s8 *, s32);
s32 Sfx_GetDataPtr_0_001672A0(s8 *);
void Sfx_GetState_0_001672B0(s8 *, s32);
s32 Sfx_GetOwner_1_001675D0(s8 *);
void Sfx_SetOwner_1_00167600(s8 *, s32);
void memset(void *, s32, s32);
Src* EnemyType_Get_0_001A8360(s32);
void Combat_ProcessHitWrap_0_0013BA60(s32, void *, s32, s32);
void MapObj_Hit_0_001B85B0(void *, s32);

/* Attack_HandleSfxEvent_1_001D3810 */
#define Attack_ApplyHit_0_001D3A90 Attack_ApplyHit_0_001D3A90__as_Attack_HandleSfxEvent_1_001D3810
void Attack_ApplyHit_0_001D3A90__as_Attack_HandleSfxEvent_1_001D3810(s8 *, E *, s32, s32, s32, s32);

void Attack_HandleSfxEvent_1_001D3810(s8 *a0, s32 id, E *e, s8 *a3, s32 t0, s32 t1, s32 t2) {
    Vec V;
    Vec M2[4];
    s8 str[0x100];
    Vec M1[4];
    s32 i;
    E *p;
    s32 name;
    s32 mode;
    s8 *h;
    if (e->x0 == id) {
        for (i = 0, p = e; i < 4; i++, p = (E *)((s8 *)p + 4)) {
            if (p->x18 != 0) {
                if (((B8 *)(a0 + 0x114))->b5) {
                    Fx_GetWorldMatrix_1_00163C80(a0, M1);
                    sceVu0CopyVector(&V, &M1[3]);
                } else {
                    sceVu0CopyVector(&V, a0);
                }
                *(s32 *)(a0 + 0x110) = Snd_PlaySeAttached_1_00131560(p->x18, p->x1A, a0 + 0x100);
            }
        }
        switch (e->x4) {
        case 0:
            break;
        case 1:
            name = e->x8;
            mode = e->xC;
            if (name != 0) {
                h = Sfx_Spawn_2_00169B50(name, 0, 0, 0);
                if (h != 0) {
                    switch (mode) {
                    case 0:
                        Sfx_SetMatrixOrAim_0_00167740(h, a3);
                        break;
                    case 1:
                        Mtx_RotateToward_0_00146140(M2, *(f32 *)(a3 + 0x20), *(f32 *)(a3 + 0x28));
                        sceVu0CopyVector(&M2[3], a3 + 0x30);
                        Sfx_SetMatrixOrAim_0_00167740(h, M2);
                        break;
                    default:
                        sprintf(str, gAttackHandleRodata_001FDE10, name);
                        break;
                    }
                    if (((B8 *)(*(s8 **)(a0 + 0x90) + 0x18A))->b1) {
                        Sfx_GetState_0_001672B0(h, Sfx_GetDataPtr_0_001672A0(*(s8 **)(a0 + 0x90)));
                    }
                    Sfx_SetOwner_1_00167600(h, Sfx_GetOwner_1_001675D0(*(s8 **)(a0 + 0x90)));
                }
            }
            break;
        case 2:
            Attack_ApplyHit_0_001D3A90(a0, e, t0, t1, t2, 0);
            break;
        }
        if (e->x4 != 2 && 0 < e->x14) {
            Attack_ApplyHit_0_001D3A90(a0, e, t0, t1, t2, 3);
        }
    }
}
#undef Attack_ApplyHit_0_001D3A90

/* Attack_ApplyHit_0_001D3A90 */
void Attack_ApplyHit_0_001D3A90(s8 *a0, s8 *a1, s32 a2, s32 a3, s32 t0, u8 t1) {
    Src *s;
    void *p;
    s8 *o;
    Buf buf;
    o = *(s8 **)(a0 + 0x90);
    if (((BF *)(o + 0x18A))->b1) {
        p = o + 0xE80;
    } else {
        s = EnemyType_Get_0_001A8360(((s32 *)(a1 + 8))[t1]);
        memset(&buf, 0, 0x40);
        p = &buf;
        buf.a = s->a;
        buf.b = s->b;
        buf.u.w = s->w;
        buf.u.s.f.b1 = 1;
    }
    if (a2 != 0) {
        Combat_ProcessHitWrap_0_0013BA60(Sfx_GetOwner_1_001675D0(o), p, a2, t0);
    } else if (a3 != 0) {
        MapObj_Hit_0_001B85B0(p, a3);
    }
}
