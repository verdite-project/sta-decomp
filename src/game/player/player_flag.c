#include "common.h"
typedef struct { char pad[0x24]; f32 yaw; } B;
typedef struct { char pad[0x518]; B *b; } S_Player_GetRightVector_1_00145640;
typedef struct { char pad[0x518]; u8 *p; } S_Player_CopyRotation_1_00145720;
typedef struct { char pad[0x518]; f32 *v; } S_Player_CopyVec_0_00145780;
extern void *gPlayerSbss_002022E4;
u64 Player_GetFlag521b5_1_00145620(void);
void Player_GetRightVector_1_00145640(f32 *v);
void Player_GetForwardVector_2_001456B0(void *arg0);
s32 Player_GetRotationPtr_1_00145710(void);
void Player_CopyRotation_1_00145720(f32 *v);
s32* Player_GetPosition_1_00145730(void);
void Player_CopyPosition_1_00145760(s32 arg0);
s32 Player_GetBody_1_00145770(void);
void Player_CopyVec_0_00145780(f32 *v);
f32 cosf(f32 x);
f32 sinf(f32 x);
void sceVu0CopyVector(f32 *v0, f32 *v1);

/* Player_GetFlag521b5_1_00145620 */
u64 Player_GetFlag521b5_1_00145620(void) {
    return (u64) ((s64) M2C_FIELD(M2C_FIELD(gPlayerSbss_002022E4, void **, 0x518), u8 *, 0x521) << 0x3A) >> 0x3F;
}

/* Player_GetRightVector_1_00145640 */
#define gPlayerSbss_002022E4 gPlayerSbss_002022E4__as_Player_GetRightVector_1_00145640
extern S_Player_GetRightVector_1_00145640 *gPlayerSbss_002022E4__as_Player_GetRightVector_1_00145640;

void Player_GetRightVector_1_00145640(f32 *v)
{
    f32 a = gPlayerSbss_002022E4->b->yaw;
    a += 1.5707964f;
    v[0] = -sinf(a);
    v[1] = 0.0f;
    v[2] = -cosf(a);
}
#undef gPlayerSbss_002022E4

/* Player_GetForwardVector_2_001456B0 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void Player_GetForwardVector_2_001456B0(void *arg0) {
    f32 temp_f20;

    temp_f20 = M2C_FIELD(M2C_FIELD(gPlayerSbss_002022E4, void **, 0x518), f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0) = (f32) -sinf(temp_f20);
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, f32 *, 8) = (f32) -cosf(temp_f20);
}

/* Player_GetRotationPtr_1_00145710 */
s32 Player_GetRotationPtr_1_00145710(void) {
    return M2C_FIELD(gPlayerSbss_002022E4, s32 *, 0x518) + 0x20;
}

/* Player_CopyRotation_1_00145720 */
#define gPlayerSbss_002022E4 gPlayerSbss_002022E4__as_Player_CopyRotation_1_00145720
extern S_Player_CopyRotation_1_00145720 *gPlayerSbss_002022E4__as_Player_CopyRotation_1_00145720;

void Player_CopyRotation_1_00145720(f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(gPlayerSbss_002022E4->p + 0x20));
}
#undef gPlayerSbss_002022E4

/* Player_GetPosition_1_00145730 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_00270550[0x4];

s32 *Player_GetPosition_1_00145730(void) {
    Player_GetPos_1_001C9410(D_00270550);
    return D_00270550;
}

/* Player_CopyPosition_1_00145760 */
void Player_CopyPosition_1_00145760(s32 arg0) {
    Player_GetPos_1_001C9410((void *) arg0);
}

/* Player_GetBody_1_00145770 */
s32 Player_GetBody_1_00145770(void) {
    return M2C_FIELD(gPlayerSbss_002022E4, s32 *, 0x518);
}

/* Player_CopyVec_0_00145780 */
#define gPlayerSbss_002022E4 gPlayerSbss_002022E4__as_Player_CopyVec_0_00145780
extern S_Player_CopyVec_0_00145780 *gPlayerSbss_002022E4__as_Player_CopyVec_0_00145780;

void Player_CopyVec_0_00145780(f32 *v)
{
    sceVu0CopyVector(v, gPlayerSbss_002022E4->v);
}
#undef gPlayerSbss_002022E4
