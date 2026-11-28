#include "common.h"
#include "m2c.h"
#include "game/player.h"
#include "game/data.h"
typedef struct { u8 pad[0x9C]; s16 id; u8 pad2[0xA]; u8 b0:1; u8 b1:1; } O;
extern s32 gGameMainSbss_00201E94;
extern s8 *gPlayerSeSbss_002022F0;
#ifndef NONMATCHING
extern s32 gPlayerSeSbss_002022F4;
#else
/* data twins (src/game/data/sbss.c): gPlayerSeSbss_002022F4 */
static s32 gPlayerSeSbss_002022F4;
#endif
#ifndef NONMATCHING
extern s32 gPlayerSeSbss_002022F8;
#else
/* data twins (src/game/data/sbss.c): gPlayerSeSbss_002022F8 */
static s32 gPlayerSeSbss_002022F8;
#endif
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_004B5DC0[0x4];
f32 D_004B5DB0[0x4];
extern s32 gPlayerSbss_002022BC;
extern u16 gMapCommandBss_00317238[];
void Player_PlayHurtSe_0_001CA2B0(void);
s32 Player_PlayStepSe_1_001CA2D0(u32 arg0);
s32 Player_PlayMoveSe_1_001CA4A0(u32 arg0, s32 arg1);
s32 Player_PlayHitEnemySe_0_001CA7B0(s32 arg0, s32 arg1);
s32 Player_ThrowItem_0_001CA960(void);
s32 Player_HoldItem_0_001CAB20(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 Player_PlaceItem_0_001CADF0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2);
void Player_ReleaseHeldItem_0_001CAE90(void);
s32 Snd_PlaySe_3_00131600(s32, s32);
s32 Rand_Next_3_0015ED20();
void Mtx_Lerp_2_0015EB20(f32, void *, void *, void *);
void Player_GetHandMatrix_1_001C0660(void *, void *, s32, s32);
void ItemObj_GetScale_0_001ADBA0(s8 *, f32 *);
void Mtx_Compose_2_00173FD0(f32 *, f32 *, f32 *, f32 *);
M2C_UNK ItemObj_Free_1_001AF4A0(void *);
s8* ItemObj_SpawnAt_0_001AE620(s32, s32, s32);
void sceVu0CopyVector(void *, void *);
void ItemObj_GetMatrix_0_001ADC60(s8 *, s8 *);
void Inventory_ChangeCount_1_001CBED0(s32, s32, s32, s32);
void Inventory_Give_0_001CBCD0(s16);

/* Player_PlayStatusSe_0_001CA1C0 */
s32 Player_PlayStatusSe_0_001CA1C0(u32 arg0) {
    switch (arg0) {
    case 0:
        return Snd_PlaySe_3_00131600(0x131, 0x7F);
    case 1:
        return Snd_PlaySe_3_00131600(0x12F, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(0x12D, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(0x137, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(0x133, 0x7F);
    case 5:
        return Snd_PlaySe_3_00131600(0x135, 0x7F);
    case 7:
        return Snd_PlaySe_3_00131600(0x139, 0x7F);
    default:
        return -1;
    }
}

/* Player_PlayHurtSe_0_001CA2B0 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlayHurtSe_0_001CA2B0
int Snd_PlaySe_3_00131600__as_Player_PlayHurtSe_0_001CA2B0();
void Player_PlayHurtSe_0_001CA2B0(void) {
    Snd_PlaySe_3_00131600(0x13B, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_PlayLandSe_0_001CA2C0 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlayLandSe_0_001CA2C0
int Snd_PlaySe_3_00131600__as_Player_PlayLandSe_0_001CA2C0();
void Player_PlayLandSe_0_001CA2C0(void) {
    Snd_PlaySe_3_00131600(0x118, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_PlayStepSe_1_001CA2D0 */
s32 Player_PlayStepSe_1_001CA2D0(u32 arg0) {
    switch (arg0) {
    case 0:
        return Snd_PlaySe_3_00131600(0x8EA, 0x7F);
    case 1:
        return Snd_PlaySe_3_00131600(0x8EB, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(0x8EC, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(0x8EE, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(0x8ED, 0x7F);
    case 5:
        return Snd_PlaySe_3_00131600(0x8F0, 0x7F);
    case 6:
        return Snd_PlaySe_3_00131600(0x8F1, 0x7F);
    case 7:
        return Snd_PlaySe_3_00131600(0x8F3, 0x7F);
    case 8:
        return Snd_PlaySe_3_00131600(0x8EF, 0x7F);
    case 9:
        return Snd_PlaySe_3_00131600(0x8F5, 0x7F);
    case 10:
        return Snd_PlaySe_3_00131600(0x8F6, 0x7F);
    case 11:
        return Snd_PlaySe_3_00131600(0x8F4, 0x7F);
    case 12:
        return Snd_PlaySe_3_00131600(0x8EA, 0x7F);
    case 13:
        return Snd_PlaySe_3_00131600(0x8EC, 0x7F);
    case 14:
        return Snd_PlaySe_3_00131600(0x8F2, 0x7F);
    case 16:
        return Snd_PlaySe_3_00131600(0x127, 0x7F);
    default:
        return -1;
    }
}

/* Player_PlayMoveSe_1_001CA4A0 */
s32 Player_PlayMoveSe_1_001CA4A0(u32 arg0, s32 arg1) {
    s32 temp_16;

    temp_16 = (arg1 != 0) ? 0x7F : 0x35;
    switch (arg0) {
    case 0:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0xC8, temp_16);
    case 1:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0xCD, temp_16);
    case 2:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8A2, temp_16);
    case 3:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8AC, temp_16);
    case 4:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8A7, temp_16);
    case 5:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8B6, temp_16);
    case 6:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8BB, temp_16);
    case 7:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8C5, temp_16);
    case 8:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8B1, temp_16);
    case 9:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8CF, temp_16);
    case 10:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8D4, temp_16);
    case 11:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8CA, temp_16);
    case 12:
        return Snd_PlaySe_3_00131600(0x8DE, temp_16);
    case 13:
        return Snd_PlaySe_3_00131600(0x8E3, temp_16);
    case 14:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8C0, temp_16);
    case 16:
        return Snd_PlaySe_3_00131600((Rand_Next_3_0015ED20() & 3) + 0x8D9, temp_16);
    default:
        return -1;
    }
}

/* Player_PlayAttackSe_0_001CA6F0 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlayAttackSe_0_001CA6F0
int Snd_PlaySe_3_00131600__as_Player_PlayAttackSe_0_001CA6F0();
void Player_PlayAttackSe_0_001CA6F0(void) {
    Snd_PlaySe_3_00131600(0x94A, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_PlayHitObjectSe_0_001CA700 */
s32 Player_PlayHitObjectSe_0_001CA700(s32 arg0, s32 arg1) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(arg1 + 0x952, 0x7F);
    default:
        return -1;
    }
}

/* Player_PlayHitEnemySe_0_001CA7B0 */
s32 Player_PlayHitEnemySe_0_001CA7B0(s32 arg0, s32 arg1) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return Snd_PlaySe_3_00131600((arg1 * 4) + 0x928, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600((arg1 * 4) + 0x92B, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600((arg1 * 4) + 0x929, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600((arg1 * 4) + 0x92A, 0x7F);
    default:
        return -1;
    }
}

/* Player_PlaySeA_1_001CA860 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlaySeA_1_001CA860
int Snd_PlaySe_3_00131600__as_Player_PlaySeA_1_001CA860();
void Player_PlaySeA_1_001CA860(void) {
    Snd_PlaySe_3_00131600(0x91B, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_PlayMagicSe_0_001CA870 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlayMagicSe_0_001CA870
int Snd_PlaySe_3_00131600__as_Player_PlayMagicSe_0_001CA870();
void Player_PlayMagicSe_0_001CA870(void) {
    Snd_PlaySe_3_00131600(0x940, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_PlaySwitchSe_0_001CA880 */
s32 Player_PlaySwitchSe_0_001CA880(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return Snd_PlaySe_3_00131600(0x924, 0x7F);
    case 2:
        return Snd_PlaySe_3_00131600(0x927, 0x7F);
    case 3:
        return Snd_PlaySe_3_00131600(0x925, 0x7F);
    case 4:
        return Snd_PlaySe_3_00131600(0x926, 0x7F);
    default:
        return -1;
    }
}

/* Player_PlaySwingSe_0_001CA930 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlaySwingSe_0_001CA930
int Snd_PlaySe_3_00131600__as_Player_PlaySwingSe_0_001CA930();
void Player_PlaySwingSe_0_001CA930(void) {
    Snd_PlaySe_3_00131600(0x91A, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_PlaySwingSeB_0_001CA940 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlaySwingSeB_0_001CA940
int Snd_PlaySe_3_00131600__as_Player_PlaySwingSeB_0_001CA940();
void Player_PlaySwingSeB_0_001CA940(void) {
    Snd_PlaySe_3_00131600(0x91A, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_PlayNullSe_0_001CA950 */
#define Snd_PlaySe_3_00131600 Snd_PlaySe_3_00131600__as_Player_PlayNullSe_0_001CA950
int Snd_PlaySe_3_00131600__as_Player_PlayNullSe_0_001CA950();
void Player_PlayNullSe_0_001CA950(void) {
    Snd_PlaySe_3_00131600(0x270F, 0x7F);
}
#undef Snd_PlaySe_3_00131600

/* Player_ThrowItem_0_001CA960 */
#define Mtx_Lerp_2_0015EB20 Mtx_Lerp_2_0015EB20__as_Player_ThrowItem_0_001CA960
void Mtx_Lerp_2_0015EB20__as_Player_ThrowItem_0_001CA960(f32, s8 *, s8 *, f32 *);
#define Player_GetHandMatrix_1_001C0660 Player_GetHandMatrix_1_001C0660__as_Player_ThrowItem_0_001CA960
void Player_GetHandMatrix_1_001C0660__as_Player_ThrowItem_0_001CA960(f32 *, s8 *, s32, s32);
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_Player_ThrowItem_0_001CA960
void ItemObj_Free_1_001AF4A0__as_Player_ThrowItem_0_001CA960(s8 *);

s32 Player_ThrowItem_0_001CA960(void) {
    f32 m[16];
    f32 v[4];
    u8 f;

    if (gPlayerSeSbss_002022F0 == NULL) {
        return -1;
    }
    switch (gPlayerSeSbss_002022F4) {
    case 1:
        f = M2C_FIELD(gPlayerSeSbss_002022F0, u8 *, 0xA8);
        if (((u64)((s64)f << 0x3E) >> 0x3F) == 0 && (f & 1)) {
            gPlayerSeSbss_002022F4++;
        }
        gPlayerSeSbss_002022F8 = 0;
        break;
    case 2:
        Player_GetHandMatrix_1_001C0660(m, gPlayerSeSbss_002022F0, 0, gGameMainSbss_00201E94);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)gPlayerSeSbss_002022F8 / 15.0f, gPlayerSeSbss_002022F0, gPlayerSeSbss_002022F0, m);
        if (gPlayerSeSbss_002022F8 < 0xF) {
            gPlayerSeSbss_002022F8++;
        } else {
            gPlayerSeSbss_002022F8 = 0;
            gPlayerSeSbss_002022F4++;
        }
        break;
    case 3:
        ItemObj_GetScale_0_001ADBA0(gPlayerSeSbss_002022F0, v);
        Mtx_Compose_2_00173FD0(m, D_004B5DB0, D_004B5DC0, v);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)gPlayerSeSbss_002022F8 / 15.0f, gPlayerSeSbss_002022F0, gPlayerSeSbss_002022F0, m);
        gPlayerSeSbss_002022F8++;
        if (gPlayerSeSbss_002022F8 >= 0xF) {
            ItemObj_Free_1_001AF4A0(gPlayerSeSbss_002022F0);
            gPlayerSeSbss_002022F0 = NULL;
            gPlayerSeSbss_002022F4 = 0;
            gPlayerSeSbss_002022F8 = 0;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
#undef Mtx_Lerp_2_0015EB20
#undef Player_GetHandMatrix_1_001C0660
#undef ItemObj_Free_1_001AF4A0

/* Player_HoldItem_0_001CAB20 */
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_Player_HoldItem_0_001CAB20
void ItemObj_Free_1_001AF4A0__as_Player_HoldItem_0_001CAB20(s8 *);
#define Player_GetHandMatrix_1_001C0660 Player_GetHandMatrix_1_001C0660__as_Player_HoldItem_0_001CAB20
void Player_GetHandMatrix_1_001C0660__as_Player_HoldItem_0_001CAB20(void *, s8 *, s32, s32);
#define D_004B5DB0 D_004B5DB0__as_Player_HoldItem_0_001CAB20
extern s8 D_004B5DB0__as_Player_HoldItem_0_001CAB20[];
#define D_004B5DC0 D_004B5DC0__as_Player_HoldItem_0_001CAB20
extern s8 D_004B5DC0__as_Player_HoldItem_0_001CAB20[];

s32 Player_HoldItem_0_001CAB20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp80[4];
    s32 sp50[12];

    if (gPlayerSeSbss_002022F0 != NULL) {
        ItemObj_Free_1_001AF4A0(gPlayerSeSbss_002022F0);
    }
    gPlayerSeSbss_002022F0 = ItemObj_SpawnAt_0_001AE620(arg0, arg2, arg3);
    if (gPlayerSeSbss_002022F0 != NULL) {
        Player_GetHandMatrix_1_001C0660(sp50, gPlayerSeSbss_002022F0, 1, gGameMainSbss_00201E94);
        sceVu0CopyVector(gPlayerSeSbss_002022F0 + 0x40, sp80);
        ItemObj_GetMatrix_0_001ADC60(gPlayerSeSbss_002022F0, gPlayerSeSbss_002022F0);
        sceVu0CopyVector(D_004B5DB0, (void *) arg2);
        sceVu0CopyVector(D_004B5DC0, (void *) arg3);
        { s32 t = gPlayerSbss_002022BC; M2C_FIELD(gPlayerSeSbss_002022F0, s32 *, 0x8C) = t;
        gPlayerSeSbss_002022F4 = 1;
        gPlayerSeSbss_002022F8 = 0;
        Inventory_ChangeCount_1_001CBED0(arg0, -arg1, 0, t); }
        return 0;
    }
    gPlayerSeSbss_002022F4 = 0;
    gPlayerSeSbss_002022F8 = 0;
    return -1;
}
#undef ItemObj_Free_1_001AF4A0
#undef Player_GetHandMatrix_1_001C0660
#undef D_004B5DB0
#undef D_004B5DC0

/* Player_DropItem_0_001CAC30 */
#define Mtx_Lerp_2_0015EB20 Mtx_Lerp_2_0015EB20__as_Player_DropItem_0_001CAC30
void Mtx_Lerp_2_0015EB20__as_Player_DropItem_0_001CAC30(f32, O *, O *, void *);
#define Player_GetHandMatrix_1_001C0660 Player_GetHandMatrix_1_001C0660__as_Player_DropItem_0_001CAC30
void Player_GetHandMatrix_1_001C0660__as_Player_DropItem_0_001CAC30(void *, O *, s32, s32);
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_Player_DropItem_0_001CAC30
void ItemObj_Free_1_001AF4A0__as_Player_DropItem_0_001CAC30(O *);
#define gPlayerSeSbss_002022F0 gPlayerSeSbss_002022F0__as_Player_DropItem_0_001CAC30
extern O *gPlayerSeSbss_002022F0__as_Player_DropItem_0_001CAC30;

s32 Player_DropItem_0_001CAC30(void) {
    u8 buf[0x40];
    if (gPlayerSeSbss_002022F0 == NULL) return -1;
    switch (gPlayerSeSbss_002022F4) {
    case 1:
        if (!gPlayerSeSbss_002022F0->b1 && gPlayerSeSbss_002022F0->b0) gPlayerSeSbss_002022F4++;
        gPlayerSeSbss_002022F8 = 0;
        break;
    case 2:
        if (gPlayerSeSbss_002022F8 < 0xF) gPlayerSeSbss_002022F8++;
        Player_GetHandMatrix_1_001C0660(buf, gPlayerSeSbss_002022F0, 0, gGameMainSbss_00201E94);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)gPlayerSeSbss_002022F8 / 15.0f, gPlayerSeSbss_002022F0, gPlayerSeSbss_002022F0, buf);
        if (gMapCommandBss_00317238[0] & 0x2000) {
            Inventory_Give_0_001CBCD0(gPlayerSeSbss_002022F0->id);
            gPlayerSeSbss_002022F8 = 0;
            gPlayerSeSbss_002022F4++;
        }
        break;
    case 3:
        Player_GetHandMatrix_1_001C0660(buf, gPlayerSeSbss_002022F0, 1, gGameMainSbss_00201E94);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)gPlayerSeSbss_002022F8 / 15.0f, gPlayerSeSbss_002022F0, gPlayerSeSbss_002022F0, buf);
        gPlayerSeSbss_002022F8++;
        if (gPlayerSeSbss_002022F8 >= 0xF) {
            ItemObj_Free_1_001AF4A0(gPlayerSeSbss_002022F0);
            gPlayerSeSbss_002022F0 = NULL;
            gPlayerSeSbss_002022F4 = 0;
            gPlayerSeSbss_002022F8 = 0;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
#undef Mtx_Lerp_2_0015EB20
#undef Player_GetHandMatrix_1_001C0660
#undef ItemObj_Free_1_001AF4A0
#undef gPlayerSeSbss_002022F0

/* Player_PlaceItem_0_001CADF0 */
#define ItemObj_SpawnAt_0_001AE620 ItemObj_SpawnAt_0_001AE620__as_Player_PlaceItem_0_001CADF0
s8 *ItemObj_SpawnAt_0_001AE620__as_Player_PlaceItem_0_001CADF0(s32, M2C_UNK, M2C_UNK);
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_Player_PlaceItem_0_001CADF0
M2C_UNK ItemObj_Free_1_001AF4A0__as_Player_PlaceItem_0_001CADF0(s8 *);

s32 Player_PlaceItem_0_001CADF0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if (gPlayerSeSbss_002022F0 != NULL) {
        ItemObj_Free_1_001AF4A0(gPlayerSeSbss_002022F0);
    }
    gPlayerSeSbss_002022F0 = ItemObj_SpawnAt_0_001AE620(arg0, arg1, arg2);
    if (gPlayerSeSbss_002022F0 != NULL) {
        M2C_FIELD(gPlayerSeSbss_002022F0, s32 *, 0x8C) = (s32) gPlayerSbss_002022BC;
        gPlayerSeSbss_002022F4 = 1;
        gPlayerSeSbss_002022F8 = 0;
        return 0;
    }
    gPlayerSeSbss_002022F4 = 0;
    gPlayerSeSbss_002022F8 = 0;
    return -1;
}
#undef ItemObj_SpawnAt_0_001AE620
#undef ItemObj_Free_1_001AF4A0

/* Player_ReleaseHeldItem_0_001CAE90 */
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_Player_ReleaseHeldItem_0_001CAE90
int ItemObj_Free_1_001AF4A0__as_Player_ReleaseHeldItem_0_001CAE90();
#define sceVu0CopyVector sceVu0CopyVector__as_Player_ReleaseHeldItem_0_001CAE90
void sceVu0CopyVector__as_Player_ReleaseHeldItem_0_001CAE90(s32 *, s32 *);
#define gPlayerSeSbss_002022F0 gPlayerSeSbss_002022F0__as_Player_ReleaseHeldItem_0_001CAE90
extern void *gPlayerSeSbss_002022F0__as_Player_ReleaseHeldItem_0_001CAE90;
#define D_004B5DB0 D_004B5DB0__as_Player_ReleaseHeldItem_0_001CAE90
extern s32 D_004B5DB0__as_Player_ReleaseHeldItem_0_001CAE90[];
#define D_004B5DC0 D_004B5DC0__as_Player_ReleaseHeldItem_0_001CAE90
extern s32 D_004B5DC0__as_Player_ReleaseHeldItem_0_001CAE90[];

void Player_ReleaseHeldItem_0_001CAE90(void) {
    if (gPlayerSeSbss_002022F0 != NULL) {
        ItemObj_Free_1_001AF4A0(gPlayerSeSbss_002022F0);
    }
    gPlayerSeSbss_002022F0 = NULL;
    gPlayerSeSbss_002022F4 = 0;
    gPlayerSeSbss_002022F8 = 0;
    sceVu0CopyVector(D_004B5DB0, &gZeroVec_003139A0);
    sceVu0CopyVector(D_004B5DC0, &gZeroVec_003139A0);
}
#undef sceVu0CopyVector
#undef gPlayerSeSbss_002022F0
#undef D_004B5DB0
#undef D_004B5DC0
#undef ItemObj_Free_1_001AF4A0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gPlayerSeSbss_002022F0 */
s8 *gPlayerSeSbss_002022F0;
#endif
