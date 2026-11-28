#include "m2c.h"
#include "include_asm.h"
#include "common.h"
#include "game/player.h"
#include "game/sound.h"
#include "game/ui.h"
#include "game/math.h"
typedef union { u128 q; u32 w[4]; } V;
typedef union { u32 w; u8 b[4]; } C_ItemMenu_Draw_0_0019C6D0;
typedef void (*Fn)(void);
typedef struct { s32 idx; s32 x4; s32 x8[9]; f32 f2C; s32 x30[4]; } A;
typedef struct { s32 idx; s32 x4; s32 x8; f32 fC; s32 x10[12]; } B;
typedef struct { u32 n; A *e; } LA;
typedef struct { u32 n; B *e; } LB;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { L *l; } O;
typedef struct { u128 q[2]; } Q2;
typedef UiArg Arg;
typedef struct { u8 b0 : 1; } F;
typedef struct { s32 state; s32 buttons; u8 next; u8 pad[5]; u8 pad_e; } Menu;
typedef struct { u8 b0:1; } BF;
typedef struct { u8 pad[0xA]; u16 xA; u8 pc[0x1D]; u8 x29; u8 p2a[0x66]; } E_ItemMenu_BuildList_1_0019DCF0;
typedef struct { u8 pad[2]; u8 x2; u8 x3; } C_ItemMenu_Open_0_0019D290;
typedef struct { char p0[0xA]; u16 h; char pc[0x1D]; u8 b; char rest[0x66]; } E_ItemMenu_IsUsable_0_0019DE30;
extern Fn D_001F28D0[];
extern V D_001F3120[];
extern V D_001F3130[];
extern f32 D_00201D70;
extern f32 D_00201D74;
extern s32 *D_00201D68;
extern s32 D_002021E4;
extern s32 D_002021E8;
extern s32 D_002021F8;
extern s32 D_00202200;
extern s32 D_004A3290[];
extern s8 D_004A32A0[];
extern S D_001F3100[] __attribute__((aligned(16)));
extern s8 D_001FD5B0[];
extern s8 D_004A3150[];
extern u8 D_004A329C[];
extern s32 D_002021E0;
extern s32 D_002021EC;
extern Q2 D_001F30C0;
extern s32 D_002021F4;
extern s32 D_004A3294[];
extern f32 D_004A3298[];
extern s32 D_002021F0;
extern s32 D_002021FC;
extern f32 *D_00201D6C;
extern BF D_004A329C__as_ItemMenu_Update_0_0019D580[];
extern BF D_004A329C__as_ItemMenu_UseItem_0_0019DA70[];
extern u8 D_004A32A0__as_ItemMenu_UseItem_0_0019DA70[];
void ItemMenu_Draw_0_0019C6D0(u8 *arg0);
void ItemMenu_DrawStats_0_0019C9B0(f32 f);
void ItemMenuProc_DrawGauge_0_0019CB90(s8 *a0, s32 a1, u32 a2);
void ItemMenu_DrawRing_0_0019CCF0(s32 arg, f32 ang);
void ItemMenu_Open_0_0019D290(s32 *arg0);
void* DbItem_FindA_1_0019D4A0(s32 id);
void* DbItem_Find_1_0019D510(s32 id);
void ItemMenu_Update_0_0019D580(Menu *m);
void ItemMenu_UseItem_0_0019DA70(Menu *m);
void ItemMenu_BuildList_1_0019DCF0(void);
void ItemMenuProc_Pos_0_0019DE90(s32 i, s8 *a1, s8 *a2);
void Text_Draw_2_001875C0(s32, s32, u32, f32, f32, f32);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void Ui_DrawSpriteRotated_1_00182080(s32, f32, V *, V *, C_ItemMenu_Draw_0_0019C6D0 *, s32);
s32 DbItem_GetCount_1_001958A0(void);
s32 DbTable_FindA_0_001957E0(s32, s32);
s8* MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawList_1_001829B0(void *, s32, void (*)(), s32);
void MenuProc_DrawStatValue_0_00186990(void);
s32 PlayerData_Get_2_001C9BA0();
s32 Menu_CalcStatBar_0_001866B0(s32, s32, s32, s8 *, s32);
void Ui_DrawSprite_2_00181680(s32, s8 *, s8 *, void *, S *, s32);
void sprintf(s8 *, s8 *, s32);
f32 Vec2_Angle_1_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void ItemMenuProc_DrawInfo_0_0019CEF0(void);
void ItemMenu_DrawRing_0_0019CCF0__as_ItemMenu_Draw_0_0019C6D0(f32, s32);
void ItemMenu_DrawStats_0_0019C9B0__as_ItemMenu_Draw_0_0019C6D0(u8 *, f32);
void Text_Draw_2_001875C0__as_ItemMenuProc_DrawGauge_0_0019CB90(f32, f32, f32, s32, s32, Col);
O* MenuLayout_Get_1_00189050__as_ItemMenu_DrawRing_0_0019CCF0(s32);
s8* MenuLayout_GetSub_1_00189020__as_ItemMenu_DrawRing_0_0019CCF0(s32);
void Ui_DrawList_1_001829B0__as_ItemMenu_DrawRing_0_0019CCF0(Ent *, s8 *, void (*)(void), s32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
void UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Ui_LoadItemImage_3_00183DC0(s32);
void* DbTable_FindB_0_00195840(void *h, s32 id);
void Snd_PlaySe_3_00131600(s32, u8);
void Player_OnEnemyKilled_1_001CB980(void *);
void memset(void *, s32, s32);
void Player_RecalcStats_1_001CEDC0(s32);
void Inventory_ChangeCount_1_001CBED0(s16, s32, s32);
void SndEmit_SetEnabled_0_0012F6E0(s32);
void Player_UseItem_1_001CAEF0(s16);
E_ItemMenu_BuildList_1_0019DCF0* Item_GetTable_1_001AFC90(void);
s32 ItemSort_GetCount_0_00195BE0(s32);
C_ItemMenu_Open_0_0019D290* Inventory_GetEntry_1_001CC3F0(s16);
void UiAnim_Get_1_0017F840(s32, s32 *);
void ItemMenu_Update_0_0019D580__as_ItemMenu_Open_0_0019D290(s32 *);
void ItemMenu_UseItem_0_0019DA70__as_ItemMenu_Open_0_0019D290(s32 *);
void DbItem_Find_1_0019D510__as_ItemMenu_Open_0_0019D290(void);
void ItemMenuProc_Pos_0_0019DE90__as_ItemMenu_Open_0_0019D290(void);
s32 UiAnim_SetTarget_1_0017F470__as_ItemMenu_UseItem_0_0019DA70(s32, s32, f32);
E_ItemMenu_IsUsable_0_0019DE30* Item_GetTable_1_001AFC90__as_ItemMenu_IsUsable_0_0019DE30(s32 i);

/* func_0019C6D0_ */
/* ItemMenu_Draw_0_0019C6D0 */
#define ItemMenu_DrawRing_0_0019CCF0 ItemMenu_DrawRing_0_0019CCF0__as_ItemMenu_Draw_0_0019C6D0
#define ItemMenu_DrawStats_0_0019C9B0 ItemMenu_DrawStats_0_0019C9B0__as_ItemMenu_Draw_0_0019C6D0
static inline s32 get(s32 id) {
    s32 t = DbItem_GetCount_1_001958A0();
    if (id == 0) {
        return 0;
    }
    if (id == -1) {
        return 0;
    }
    if (t == 0) {
        return 0;
    }
    return DbTable_FindA_0_001957E0(t, id);
}

void ItemMenu_Draw_0_0019C6D0(u8 *arg0) {
    C_ItemMenu_Draw_0_0019C6D0 c;
    C_ItemMenu_Draw_0_0019C6D0 col;
    V a;
    V b;
    s32 id;
    s32 k;
    f32 f;

    D_001F28D0[0]();
    Menu_SetFlags_0_0018A310(0xC);
    if (arg0[8] == 0x15) {
        D_00201D70 = Approachf_3_00187770(D_00201D70, -0.02f, 3.5f);
        id = D_00201D68[D_004A3290[0]];
        if (id > 0) {
            c.w = 0x80808080;
            Text_Draw_2_001875C0(get(id), 2, *(u32 *)&c, 622.0f, 17.0f, 1.1f);
        }
    } else {
        D_00201D70 = Approachf_3_00187770(D_00201D70, -2.99f, 3.5f);
    }
    if (!(D_00201D70 <= -2.89f)) {
        UiAnim_UpdateAll_1_0017F5C0();
        D_002021E4 = 0;
        f = -D_00201D70 / 1.5f;
        k = D_00201D68[D_004A3290[0]];
        if (D_002021F8 <= 0) {
            k = -1;
        }
        ItemMenu_DrawRing_0_0019CCF0(f, k);
        Menu_DrawFrame_0_00185390(-f, 1, D_002021F8 - 1, D_004A3290[0]);
    }
    a = D_001F3120[0];
    b = D_001F3130[0];
    if (D_002021E8 == 1) {
        D_00201D74 = D_00201D74 - (D_00201D74 - 10.0f) / 4.0f;
        D_00202200 = D_00202200 - (D_00202200 - 64.0f) / 4.0f;
    } else {
        D_00201D74 = D_00201D74 - (D_00201D74 + 300.0f) / 4.0f;
        D_00202200 = D_00202200 - D_00202200 / 4.0f;
    }
    col.w = 0;
    col.b[3] = D_00202200;
    Ui_DrawSpriteRotated_1_00182080(0, 0.0f, &a, &b, &col, 0);
    ItemMenu_DrawStats_0_0019C9B0(arg0, D_00201D74);
}
#undef ItemMenu_DrawRing_0_0019CCF0
#undef ItemMenu_DrawStats_0_0019C9B0

/* ItemMenu_DrawStats_0_0019C9B0 */
void ItemMenu_DrawStats_0_0019C9B0(f32 f) {
    A a;
    B b;
    LB *lb;
    s32 base2;
    u32 i;
    LA *la;
    s32 t;
    s32 base;

    la = *(LA **)(MenuLayout_Get_1_00189050(2) + 4);
    base = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < la->n; i++) {
        a = la->e[i];
        a.f2C = f;
        Ui_DrawList_1_001829B0(&a, base + la->e[i].idx * 8, (void (*)())ItemMenuProc_DrawGauge_0_0019CB90, 0);
    }
    lb = *(LB **)(MenuLayout_Get_1_00189050(0) + 0x2C);
    base2 = MenuLayout_GetSub_1_00189020(0);
    t = PlayerData_Get_2_001C9BA0();
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < lb->n; i++) {
        b = lb->e[i];
        b.fC = f;
        Ui_DrawList_1_001829B0(&b, base2 + lb->e[i].idx * 8, MenuProc_DrawStatValue_0_00186990, Menu_CalcStatBar_0_001866B0(b.x4, t + 0x20, 0, D_004A32A0, 0));
    }
}

/* ItemMenuProc_DrawGauge_0_0019CB90 */
#define Text_Draw_2_001875C0 Text_Draw_2_001875C0__as_ItemMenuProc_DrawGauge_0_0019CB90

void ItemMenuProc_DrawGauge_0_0019CB90(s8 *a0, s32 a1, u32 a2) {
    S t __attribute__((aligned(16)));
    Col col;

    if (a2 < 300) {
        t = D_001F3100[0];
        t.x = *(f32 *)(a0 + 0x30);
        t.y = *(f32 *)(a0 + 0x34);
        Ui_DrawSprite_2_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, a0 + 0x2C, &t, a2);
        return;
    }
    if ((D_004A329C[0] & 1) && D_002021E0 + 300 == a2) {
        Ui_DrawGauge_0_00182EF0(*(f32 *)(a0 + 0x38) - 6.0f, *(f32 *)(a0 + 0x3C), 171.0f + *(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.0f, 0.0f, 128.0f);
    }
    if (a2 == 500) {
        sprintf(D_004A3150, D_001FD5B0, D_002021EC);
        *(u32 *)&col = 0x80808080;
        Text_Draw_2_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 1.1f, (s32)D_004A3150, 2, col);
    }
}
#undef Text_Draw_2_001875C0

/* ItemMenu_DrawRing_0_0019CCF0 */
#define MenuLayout_Get_1_00189050 MenuLayout_Get_1_00189050__as_ItemMenu_DrawRing_0_0019CCF0
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_ItemMenu_DrawRing_0_0019CCF0
#define Ui_DrawList_1_001829B0 Ui_DrawList_1_001829B0__as_ItemMenu_DrawRing_0_0019CCF0

void ItemMenu_DrawRing_0_0019CCF0(s32 arg, f32 ang) {
    u32 i; L *l; s8 *base; Ent e; V2 q; f32 d, a, t, dx, dy;
    l = MenuLayout_Get_1_00189050(2)->l;
    base = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = -70.0f;
            p.y = 276.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - -70.0f; dy = e.y - 276.0f; d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        e.x = -70.0f + d * sinf(a);
        e.y = 276.0f + d * cosf(a);
        }
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, ItemMenuProc_DrawInfo_0_0019CEF0, arg);
    }
}
#undef MenuLayout_Get_1_00189050
#undef MenuLayout_GetSub_1_00189020
#undef Ui_DrawList_1_001829B0
#undef ItemMenu_DrawRing_0_0019CCF0
#undef ItemMenu_DrawStats_0_0019C9B0
#undef Text_Draw_2_001875C0
#undef MenuLayout_Get_1_00189050
#undef MenuLayout_GetSub_1_00189020
#undef Ui_DrawList_1_001829B0

/* text_0019CEF0 */
#ifdef NONMATCHING
/* best-effort C: item_menu_proc_draw_info.c */
#else
INCLUDE_ASM(ItemMenuProc_DrawInfo_0_0019CEF0);
#endif

/* func_0019D290_ */
#define D_004A329C D_004A329C__as_func_0019D290_
extern F D_004A329C__as_func_0019D290_[];
#define D_004A32A0 D_004A32A0__as_func_0019D290_
extern u16 D_004A32A0__as_func_0019D290_[];
#define DbItem_GetCount_1_001958A0 DbItem_GetCount_1_001958A0__as_func_0019D290_
void* DbItem_GetCount_1_001958A0__as_func_0019D290_(void);
#define DbTable_FindA_0_001957E0 DbTable_FindA_0_001957E0__as_func_0019D290_
void* DbTable_FindA_0_001957E0__as_func_0019D290_(void *h, s32 id);

/* ItemMenu_Open_0_0019D290 */

void ItemMenu_Open_0_0019D290(s32 *arg0) {
    Q2 q;
    Arg a;

    if (*arg0 == 0x19) {
        D_004A3290[0] = 0;
        ItemMenu_BuildList_1_0019DCF0();
        q = D_001F30C0;
        a.fn = DbItem_Find_1_0019D510;
        a.f = -3.0f;
        a.cb = ItemMenuProc_Pos_0_0019DE90;
        a.a = 0;
        a.b = 0;
        a.p = (s32)D_00201D68;
        a.n = D_002021F8;
        UiAnim_SetColor_0_0017F890(1, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(1, 1, 1);
        D_002021F4 = 2;
        UiAnim_SetTarget_1_0017F470(D_004A3290[0], 1, 1);
    }
    Ui_LoadItemImage_3_00183DC0(D_00201D68[D_004A3290[0]]);
    if (D_004A329C[0].b0) {
        switch (D_002021E8) {
        case 0:
            ItemMenu_UseItem_0_0019DA70(arg0);
            break;
        case 1:
            ItemMenu_Update_0_0019D580(arg0);
            break;
        }
    }
    if (!D_004A329C[0].b0) {
        D_004A3298[0] -= 1.0f;
        if (D_004A3298[0] < 0.0f) {
            D_004A329C[0].b0 = 1;
            switch (D_004A3294[0]) {
            case 1:
                D_002021E8 = 0;
                D_004A3298[0] = 15.0f;
                D_004A329C[0].b0 = 0;
                break;
            case 2:
                D_002021E8 = 1;
                break;
            }
            D_004A3294[0] = -1;
            return;
        }
        D_004A329C[0].b0 = 0;
        return;
    }
}

/* DbItem_FindA_1_0019D4A0 */
void *DbItem_FindA_1_0019D4A0(s32 id)
{
    void *h = DbItem_GetCount_1_001958A0();
    if (!id)
        return NULL;
    if (id == -1)
        return NULL;
    if (h)
        return DbTable_FindA_0_001957E0(h, id);
    return NULL;
}

/* DbItem_Find_1_0019D510 */
void *DbItem_Find_1_0019D510(s32 id)
{
    void *h = DbItem_GetCount_1_001958A0();
    if (!id)
        return NULL;
    if (id == -1)
        return NULL;
    if (h)
        return DbTable_FindB_0_00195840(h, id);
    return NULL;
}

/* ItemMenu_Update_0_0019D580 */

void ItemMenu_Update_0_0019D580(Menu *m) {
    s32 n;

    PlayerData_Get_2_001C9BA0();
    if (m->buttons & 0x10) {
        D_002021E0--;
        D_002021FC = 0;
        if (D_002021E0 < 0) {
            D_002021E0 = 0;
        } else {
            Snd_PlaySe_3_00131600(0x66, m->pad_e);
        }
    } else if (m->buttons & 0x40) {
        D_002021E0++;
        D_002021FC = 0;
        if (D_002021E0 > 7) {
            D_002021E0 = 7;
        } else {
            Snd_PlaySe_3_00131600(0x66, m->pad_e);
        }
    } else if (m->buttons & 0x20) {
        if (D_002021EC > 0) {
            switch (D_002021E0) {
            case 0: D_004A32A0[0]++; break;
            case 1: D_004A32A0[1]++; break;
            case 2: D_004A32A0[2]++; break;
            case 3: D_004A32A0[3]++; break;
            case 4: D_004A32A0[4]++; break;
            case 5: D_004A32A0[5]++; break;
            case 6: D_004A32A0[6]++; break;
            case 7: D_004A32A0[7]++; break;
            }
            D_002021EC--;
            Snd_PlaySe_3_00131600(0x6A, m->pad_e);
        }
    } else if (m->buttons & 0x80) {
        n = D_002021EC;
        if (n < D_002021F0) {
            switch (D_002021E0) {
            case 0: if (D_004A32A0[0] > 0) { D_004A32A0[0]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            case 1: if (D_004A32A0[1] > 0) { D_004A32A0[1]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            case 2: if (D_004A32A0[2] > 0) { D_004A32A0[2]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            case 3: if (D_004A32A0[3] > 0) { D_004A32A0[3]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            case 4: if (D_004A32A0[4] > 0) { D_004A32A0[4]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            case 5: if (D_004A32A0[5] > 0) { D_004A32A0[5]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            case 6: if (D_004A32A0[6] > 0) { D_004A32A0[6]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            case 7: if (D_004A32A0[7] > 0) { D_004A32A0[7]--; D_002021EC = n + 1; Snd_PlaySe_3_00131600(0x6A, m->pad_e); } break;
            }
        }
    } else if (m->buttons & 0x2000) {
        if (D_002021EC == 0) {
            Player_OnEnemyKilled_1_001CB980(D_004A32A0);
            memset(D_004A32A0, 0, 0x10);
            Player_RecalcStats_1_001CEDC0(3);
            Player_RefreshEquipModel_0_001CEA50(1);
            D_004A3298[0] = 15.0f;
            D_004A329C[0].b0 = 0;
            D_004A3294[0] = 1;
            Inventory_ChangeCount_1_001CBED0(D_00201D68[D_004A3290[0]], -1, -1);
            ItemMenu_BuildList_1_0019DCF0();
            Snd_PlaySe_3_00131600(0x67, m->pad_e);
        } else {
            Snd_PlaySe_3_00131600(0x68, m->pad_e);
        }
    } else if (m->buttons & 0x4000) {
        D_002021E8 = 0;
        Snd_PlaySe_3_00131600(0x68, m->pad_e);
    }
    m->buttons = 0;
}

/* ItemMenu_UseItem_0_0019DA70 */
#define UiAnim_SetTarget_1_0017F470 UiAnim_SetTarget_1_0017F470__as_ItemMenu_UseItem_0_0019DA70

void ItemMenu_UseItem_0_0019DA70(Menu *m) {
    s32 sel = D_004A3290[0];
    s32 v;

    if (m->state != 0x16) {
        return;
    }
    if (m->buttons & 0x10) {
        sel--;
    } else if (m->buttons & 0x40) {
        sel++;
    } else if (m->buttons & 0x2000) {
        if (D_002021F8 > 0) {
            v = D_00201D68[sel];
            if (v == 2 || v == 0x50) {
                PlayerData_Get_2_001C9BA0();
                D_004A3298[0] = 15.0f;
                D_002021E0 = 0;
                D_004A329C[0].b0 = 0;
                D_004A3294[0] = 2;
                D_002021E8 = 1;
                memset(D_004A32A0, 0, 0x10);
                if (D_00201D68[D_004A3290[0]] == 0x50) {
                    D_002021EC = 0x14;
                    D_002021F0 = 0x14;
                } else {
                    D_002021EC = 5;
                    D_002021F0 = 5;
                }
            } else {
                Player_UseItem_1_001CAEF0(v);
                ItemMenu_BuildList_1_0019DCF0();
                m->next = 0x12;
                m->buttons = 0;
                m->state = 0x1A;
                UiAnim_SetVisible_1_0017F7C0(1, 0, 0);
                SndEmit_SetEnabled_0_0012F6E0(1);
                SndCh_ResumePaused_1_0012C260();
            }
            Snd_PlaySe_3_00131600(0x67, m->pad_e);
        }
    } else if (m->buttons & 0x4000) {
        Snd_PlaySe_3_00131600(0x69, m->pad_e);
        m->next = 0x14;
        m->buttons = 0;
        m->state = 0x1A;
        UiAnim_SetVisible_1_0017F7C0(1, 0, 0);
        return;
    }
    if (sel < 0) {
        if (D_002021F8 > 0) {
            sel = D_002021F8 - 1;
        } else {
            sel = 0;
        }
    }
    if (sel >= D_002021F8) {
        sel = 0;
    }
    if (UiAnim_SetTarget_1_0017F470(1, 0, D_004A3290[0]) != 0) {
        if (D_004A3290[0] != sel) {
            Snd_PlaySe_3_00131600(0x66, m->pad_e);
        }
        D_004A3290[0] = sel;
        D_002021F4 = 0;
    }
}
#undef UiAnim_SetTarget_1_0017F470

/* ItemMenu_BuildList_1_0019DCF0 */
static inline s32 is5(s32 id) {
    E_ItemMenu_BuildList_1_0019DCF0 *e = &Item_GetTable_1_001AFC90()[id];
    if (e->xA == 0 && e->x29 == 5) return 1;
    return 0;
}

void ItemMenu_BuildList_1_0019DCF0(void) {
    s32 i;
    E_ItemMenu_BuildList_1_0019DCF0 *t;
    C_ItemMenu_Open_0_0019D290 *c;
    t = Item_GetTable_1_001AFC90();
    D_002021F8 = 0;
    memset(D_00201D68, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        c = Inventory_GetEntry_1_001CC3F0(ItemSort_GetCount_0_00195BE0(i));
        if (c->x2 > 0 || (is5(ItemSort_GetCount_0_00195BE0(i)) && c->x3 > 0)) {
            if (t[ItemSort_GetCount_0_00195BE0(i)].xA == 0) {
                D_00201D68[D_002021F8] = ItemSort_GetCount_0_00195BE0(i);
                D_002021F8++;
            }
        }
    }
}

/* ItemMenu_IsUsable_0_0019DE30 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_ItemMenu_IsUsable_0_0019DE30

s32 ItemMenu_IsUsable_0_0019DE30(s32 i)
{
    E_ItemMenu_IsUsable_0_0019DE30 *e = Item_GetTable_1_001AFC90(i);
    E_ItemMenu_IsUsable_0_0019DE30 *p = &e[i];
    if (p->h == 0 && p->b == 5)
        return 1;
    return 0;
}
#undef Item_GetTable_1_001AFC90

/* ItemMenuProc_Pos_0_0019DE90 */
void ItemMenuProc_Pos_0_0019DE90(s32 i, s8 *a1, s8 *a2) {
    s32 t;
    f32 f;
    UiAnim_Get_1_0017F840(1, &t);
    switch (D_002021F4) {
    case 0:
        *(f32 *)(a1 + 0x14) = *(f32 *)(a2 + 8) - (f32)i;
        break;
    case 2:
        if (i >= D_004A3290[0] - 3 && i <= D_004A3290[0] + 3) {
            f = *(f32 *)(a2 + 8) - (f32)i;
            D_00201D6C[i] = f;
            *(f32 *)(a1 + 0x14) = f;
        } else {
            D_00201D6C[i] = -5.0f;
            *(f32 *)(a1 + 0x14) = -5.0f;
        }
        break;
    }
}
#undef DbItem_GetCount_1_001958A0
#undef DbTable_FindA_0_001957E0
#undef D_004A329C
#undef D_004A32A0
#undef ItemMenu_Update_0_0019D580
#undef ItemMenu_UseItem_0_0019DA70
#undef DbItem_Find_1_0019D510
#undef ItemMenuProc_Pos_0_0019DE90
#undef UiAnim_SetTarget_1_0017F470
#undef Item_GetTable_1_001AFC90
