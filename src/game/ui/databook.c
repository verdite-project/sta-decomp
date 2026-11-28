#include "m2c.h"
#include "common.h"
#include "game/ui.h"
#include "game/math.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    s32 id;
    s32 off;
} Ent1952B0;
typedef struct {
    s32 x0;
    u32 n;
    u8 pad8[8];
    Ent1952B0 e[1];
} Pack1952B0;
typedef struct {
    u8 pad0[8];
    u8 x8;
} Obj1952B0;
typedef struct { u128 q[2]; } Q2;
typedef UiArg Arg;
typedef struct { s32 id; s32 o1; s32 o2; } Ent_Databook_Update_0_00195460;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_Databook_Update_0_00195460 e[1]; } Tbl;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } Ev;
typedef struct { s32 id; char p[0x2C]; } E_DbChar_Find_0_00195770;
typedef struct { char p0[4]; u32 n; char p8[8]; E_DbChar_Find_0_00195770 e[1]; } T_DbChar_Find_0_00195770;
typedef struct { s32 id; s32 x4; s32 off; } Ent_DbChar_FindEntry_0_00195900;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_DbChar_FindEntry_0_00195900 e[1]; } Hdr;
typedef struct { s16 v; s16 id; } E_DbMap_GetKillRate_0_001959E0;
typedef struct { s32 id; s32 off; } E_Msg_GetText_2_00195B10;
typedef struct { char p0[4]; u32 n; char p8[8]; E_Msg_GetText_2_00195B10 e[1]; } T_Msg_GetText_2_00195B10;
typedef struct { s16 n; s8 v[14]; } E_ItemSort_GetEntry_0_00195B80;
#ifdef NONMATCHING
extern u8 D_00496B60[];
#endif
#ifndef NONMATCHING
extern f32 D_00201D30;
#else
/* data twins (src/game/data/sdata.c): D_00201D30 */
static f32 D_00201D30 = -2.99f;
#endif
#ifndef NONMATCHING
extern s32 D_00202154;
#else
/* data twins (src/game/data/sbss.c): D_00202154 */
static s32 D_00202154;
#endif
#ifndef NONMATCHING
extern Pack1952B0 **D_00202180;
#else
/* data twins (src/game/data/sbss.c): D_00202180 */
static Pack1952B0 **D_00202180;
#endif
#ifndef NONMATCHING
extern u8 D_001FD270[];
#else
/* data twins (src/game/data/databook_rodata.c): D_001FD270 */
static u8 D_001FD270[0x8] = "MAP\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern u8 D_001FD288[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD288 */
static u8 D_001FD288[0x5] = "ITEM\000";
#endif
extern Q2 D_001F2E40;
extern s32 D_001F2E60[];
extern s8 D_001FD268[];
#ifndef NONMATCHING
extern s8 *D_00201D28;
#else
/* data twins (src/game/data/sdata.c): D_00201D28 */
static s8 *D_00201D28 = (s8 *)D_001FD268;
#endif
#ifndef NONMATCHING
extern s8 *D_00201D2C;
#else
/* data twins (src/game/data/sdata.c): D_00201D2C */
static s8 *D_00201D2C = (s8 *)D_001FD268;
#endif
#ifndef NONMATCHING
extern u8 D_00201D20[4];
#else
/* data twins (src/game/data/sdata.c): D_00201D20 */
static u8 D_00201D20[0x4] = { 0x19, 0x1a, 0x1b, 0 };
#endif
extern Tbl *D_0020215C;
extern u32 D_002022B8;
#ifndef NONMATCHING
extern T_DbChar_Find_0_00195770 **D_00202168;
#else
/* data twins (src/game/data/sbss.c): D_00202168 */
static T_DbChar_Find_0_00195770 **D_00202168;
#endif
#ifndef NONMATCHING
extern s32 *D_00202160;
#else
/* data twins (src/game/data/sbss.c): D_00202160 */
static s32 *D_00202160;
#endif
extern s32 *D_00202164;
#ifndef NONMATCHING
extern E_DbMap_GetKillRate_0_001959E0 **D_0020216C;
#else
/* data twins (src/game/data/sbss.c): D_0020216C */
static E_DbMap_GetKillRate_0_001959E0 **D_0020216C;
#endif
extern E_ItemSort_GetEntry_0_00195B80 *D_0020217C;
extern s16 *D_00202174;
#ifndef NONMATCHING
extern s8 D_001FD290[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD290 */
static s8 D_001FD290[0xf] = "menu/dbmap.txm\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD2A0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD2A0 */
static s8 D_001FD2A0[0x10] __attribute__((aligned(8))) = "menu/dbchar.txm\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD2B0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD2B0 */
static s8 D_001FD2B0[0x10] __attribute__((aligned(8))) = "menu/dbitem.txm\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD2C0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD2C0 */
static s8 D_001FD2C0[0xe] = "menu/help.txm\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD2D0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD2D0 */
static s8 D_001FD2D0[0x10] __attribute__((aligned(8))) = "menu/dbchar.sta\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD2E0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD2E0 */
static s8 D_001FD2E0[0xf] = "menu/dbmap.sta\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD2F0[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD2F0 */
static s8 D_001FD2F0[0x20] __attribute__((aligned(8))) = "menu/itemsort.tbl\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FD310[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD310 */
static s8 D_001FD310[0x18] __attribute__((aligned(8))) = "menu/itemmenu.tbl\000\000\000\000\000\000\000";
#endif
extern s8 * volatile D_00202158;
#ifndef NONMATCHING
extern s32 *D_00202170;
#else
/* data twins (src/game/data/sbss.c): D_00202170 */
static s32 *D_00202170;
#endif
#ifndef NONMATCHING
extern s32 *D_00202178;
#else
/* data twins (src/game/data/sbss.c): D_00202178 */
static s32 *D_00202178;
#endif
#ifndef NONMATCHING
extern f32 *D_00201D24;
#else
/* data twins (src/game/data/sdata.c): D_00201D24 */
static f32 *D_00201D24 = (f32 *)D_00496B60;
#endif
void Databook_Draw_0_001952B0(Obj1952B0 *o);
void Databook_UpdateWrap_0_00195410(s32 arg0);
s32 Databook_GetTab_0_00195420(s32 i);
void Databook_Update_0_00195460(Ev *arg0);
E_DbChar_Find_0_00195770* DbChar_Find_0_00195770(s32 id);
s8* DbTable_FindA_0_001957E0(Tbl *t, s32 id);
s8* DbTable_FindB_0_00195840(Tbl *t, s32 id);
s32 DbItem_GetCount_1_001958A0(void);
s32 DbChar_GetCount_0_001958C0(void);
s32 DbMap_GetCount_1_001958E0(void);
s32* DbChar_FindEntry_0_00195900(s32 id);
s8* DbChar_GetName_0_00195970(s32 id);
s8* DbMap_GetName_0_00195A30(s32 id);
s8* DbMap_GetLocationName_1_00195AA0(s32 id);
void* Msg_GetText_2_00195B10(s32 id);
s8 ItemSort_GetEntry_0_00195B80(s32 i, s32 *p);
s16 ItemSort_GetCount_0_00195BE0(s32 i);
void DbCharProc_Layout_0_00195D80(s32 i, f32 *a1, f32 *a2);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void Text_Draw_2_001875C0(f32, s32, f32, f32, u32, u32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Snd_PlaySe_3_00131600(s32, u8);
s8* File_HashName_3_00159D10(s8 *);
void Arc_LoadFile_2_00159DD0(s8 *, s8 *, void *, void *);
void UiAnim_Get_1_0017F840(s32, s32 *);

/* Databook_Draw_0_001952B0 */
static inline s8 *find(s32 id) {
    u32 i;
    Ent1952B0 *e;
    Pack1952B0 *p;
    p = *D_00202180;
    if (p == NULL) {
        return NULL;
    }
    for (e = p->e, i = 0; i < p->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)p + e->off;
        }
    }
    return NULL;
}

void Databook_Draw_0_001952B0(Obj1952B0 *o) {
    Col col;

    Menu_SetFlags_0_0018A310(4);
    if (o->x8 == 0x18) {
        D_00201D30 = Approachf_3_00187770(D_00201D30, -0.02f, 3.5f);
    } else {
        D_00201D30 = Approachf_3_00187770(D_00201D30, -2.99f, 3.5f);
    }
    if (!(D_00201D30 <= -2.99f)) {
        col.w = 0x80FFFFFF;
        if (D_00202154 >= 0) {
            Text_Draw_2_001875C0(622.0f, (s32)find(D_00202154 + 0x1E), 17.0f, 1.0f, 2, *(u32 *)&col);
        }
        UiAnim_UpdateAll_1_0017F5C0();
    }
    Menu_DrawFrame_0_00185390(D_00201D30, 1, 3, D_00202154);
}

/* Databook_UpdateWrap_0_00195410 */
void Databook_UpdateWrap_0_00195410(s32 arg0) {
    Databook_Update_0_00195460((void *) arg0);
}

/* Databook_GetTab_0_00195420 */
#pragma explicit_zero_data on
const u8 D_001FD278[0x9] = "CREATURE\000";
s32 D_001F2E70[0x4] = { (s32)D_001FD270, (s32)D_001FD278, (s32)D_001FD288 };
s32 Databook_GetTab_0_00195420(s32 i)
{
    if (i < 0 || i > 3)
        return 0;
    return D_001F2E70[i];
}

/* Databook_Update_0_00195460 */
static inline Tbl *get_Databook_Update_0_00195460(void) {
    if (D_0020215C != NULL) {
        return (Tbl *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find1_Databook_Update_0_00195460(Tbl *t, s32 id) {
    Ent_Databook_Update_0_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
static inline s8 *find2_Databook_Update_0_00195460(Tbl *t, s32 id) {
    Ent_Databook_Update_0_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o2;
        }
    }
    return D_001FD268;
}

void Databook_Update_0_00195460(Ev *arg0) {
    Q2 q;
    Arg a;
    s32 n;
    s32 k;
    Tbl *t;
    u32 id;

    if (arg0->x0 == 0x19) {
        id = D_002022B8 / 10;
        t = get_Databook_Update_0_00195460();
        if (t != 0) {
            D_00201D28 = find1_Databook_Update_0_00195460(t, id);
            D_00201D2C = find2_Databook_Update_0_00195460(t, id);
            D_00202154 = 0;
            q = D_001F2E40;
            a.p = (s32)D_001F2E60;
            a.n = 3;
            a.fn = Databook_GetTab_0_00195420;
            a.f = -3.0f;
            a.cb = DbCharProc_Layout_0_00195D80;
            a.a = 0;
            a.b = 0;
            UiAnim_SetColor_0_0017F890(3, &q, &a);
            UiAnim_SetVisible_1_0017F7C0(3, 1, 1);
            UiAnim_SetTarget_1_0017F470(D_00202154, 3, 1);
        }
    }
    if (arg0->x0 == 0x16) {
        n = D_00202154;
        k = n;
        if (arg0->x4 & 0x2000) {
            UiAnim_SetVisible_1_0017F7C0(3, 0, 1);
            arg0->x4 &= ~0x2000;
            arg0->x8 = D_00201D20[n];
            arg0->x4 = 0;
            arg0->x0 = 0x1F;
            Snd_PlaySe_3_00131600(0x69, arg0->xE);
        } else if (arg0->x4 & 0x4000) {
            UiAnim_SetVisible_1_0017F7C0(3, 0, 1);
            arg0->x8 = 0x14;
            arg0->x4 = 0;
            arg0->x0 = 0x1F;
            Snd_PlaySe_3_00131600(0x69, arg0->xE);
        } else {
            if (arg0->x4 & 0x10) {
                k = n - 1;
            } else if (arg0->x4 & 0x40) {
                k = n + 1;
            }
            k = (k + 3) % 3;
            if (UiAnim_SetTarget_1_0017F470(n, 3, 0)) {
                if (k != D_00202154) {
                    Snd_PlaySe_3_00131600(0x66, arg0->xE);
                }
                D_00202154 = k;
            }
        }
    }
}

/* DbChar_Find_0_00195770 */
E_DbChar_Find_0_00195770 *DbChar_Find_0_00195770(s32 id)
{
    T_DbChar_Find_0_00195770 *t;
    E_DbChar_Find_0_00195770 *e;
    u32 i;
    if (!D_00202168)
        return NULL;
    t = *D_00202168;
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id)
            return e;
    }
    return NULL;
}

/* DbTable_FindA_0_001957E0 */
s8 *DbTable_FindA_0_001957E0(Tbl *t, s32 id) {
    Ent_Databook_Update_0_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o2;
        }
    }
    return D_001FD268;
}

/* DbTable_FindB_0_00195840 */
s8 *DbTable_FindB_0_00195840(Tbl *t, s32 id) {
    Ent_Databook_Update_0_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}

/* DbItem_GetCount_1_001958A0 */
s32 DbItem_GetCount_1_001958A0(void) {
    if (D_00202160 != NULL) {
        return *D_00202160;
    }
    return 0;
}

/* DbChar_GetCount_0_001958C0 */
s32 DbChar_GetCount_0_001958C0(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}

/* DbMap_GetCount_1_001958E0 */
#define D_0020215C D_0020215C__as_DbMap_GetCount_1_001958E0
extern s32 *D_0020215C__as_DbMap_GetCount_1_001958E0;

s32 DbMap_GetCount_1_001958E0(void) {
    if (D_0020215C != NULL) {
        return *D_0020215C;
    }
    return 0;
}
#undef D_0020215C

/* DbChar_FindEntry_0_00195900 */
static inline s32 get_DbChar_FindEntry_0_00195900(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}
s32 *DbChar_FindEntry_0_00195900(s32 id) {
    Hdr *h = (Hdr *)get_DbChar_FindEntry_0_00195900();
    Ent_DbChar_FindEntry_0_00195900 *e;
    u32 i;
    if (h == NULL) return D_001FD268;
    e = h->e;
    for (i = 0; i < h->n; i++, e++) {
        if (e->id == id) return (s32 *)((u8 *)h + e->off);
    }
    return D_001FD268;
}

/* DbChar_GetName_0_00195970 */
#define D_00202164 D_00202164__as_DbChar_GetName_0_00195970
extern Tbl **D_00202164__as_DbChar_GetName_0_00195970;
static inline Tbl *get_DbChar_GetName_0_00195970(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}
static inline s8 *find1_DbChar_GetName_0_00195970(Tbl *t, s32 id) {
    Ent_Databook_Update_0_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
s8 *DbChar_GetName_0_00195970(s32 id) {
    return find1_DbChar_GetName_0_00195970(get_DbChar_GetName_0_00195970(), id);
}
#undef D_00202164

/* DbMap_GetKillRate_0_001959E0 */
s32 DbMap_GetKillRate_0_001959E0(s32 id) { s32 i; E_DbMap_GetKillRate_0_001959E0 *base = *D_0020216C; E_DbMap_GetKillRate_0_001959E0 *e = base; for (i = 0; i < 24; i++, e++) { if (id == e->id) return base[i].v; } return -1; }

/* DbMap_GetName_0_00195A30 */
static inline Tbl *get_DbMap_GetName_0_00195A30(void) {
    if (D_0020215C != NULL) {
        return (Tbl *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find2_DbMap_GetName_0_00195A30(Tbl *t, s32 id) {
    Ent_Databook_Update_0_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o2;
        }
    }
    return D_001FD268;
}
s8 *DbMap_GetName_0_00195A30(s32 id) {
    return find2_DbMap_GetName_0_00195A30(get_DbMap_GetName_0_00195A30(), id);
}

/* DbMap_GetLocationName_1_00195AA0 */
static inline Tbl *get_DbMap_GetLocationName_1_00195AA0(void) {
    if (D_0020215C != NULL) {
        return (Tbl *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find1_DbMap_GetLocationName_1_00195AA0(Tbl *t, s32 id) {
    Ent_Databook_Update_0_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
s8 *DbMap_GetLocationName_1_00195AA0(s32 id) {
    return find1_DbMap_GetLocationName_1_00195AA0(get_DbMap_GetLocationName_1_00195AA0(), id);
}

/* Msg_GetText_2_00195B10 */

void *Msg_GetText_2_00195B10(s32 id)
{
    u32 i;
    E_Msg_GetText_2_00195B10 *e;
    T_Msg_GetText_2_00195B10 *t = *D_00202180;
    if (!t)
        return NULL;
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id)
            return (u8 *)t + e->off;
    }
    return NULL;
}

/* ItemSort_GetEntry_0_00195B80 */
s8 ItemSort_GetEntry_0_00195B80(s32 i, s32 *p) {
    s32 k = *p;
    if (k < 0) k = D_0020217C[i].n - 1;
    if (k > D_0020217C[i].n - 1) k = 0;
    *p = k;
    return D_0020217C[i].v[k];
}

/* ItemSort_GetCount_0_00195BE0 */
s16 ItemSort_GetCount_0_00195BE0(s32 i)
{
    return D_00202174[i];
}

/* Databook_LoadRes_3_00195C00 */
#define D_00202174 D_00202174__as_Databook_LoadRes_3_00195C00
extern s32 D_00202174__as_Databook_LoadRes_3_00195C00;
#define D_0020217C D_0020217C__as_Databook_LoadRes_3_00195C00
extern s32 D_0020217C__as_Databook_LoadRes_3_00195C00;

void Databook_LoadRes_3_00195C00(s8 *arg0) {
    u32 sp1C;

    D_00202158 = arg0;
    if (D_0020215C == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD290), D_00202158, &D_0020215C, &sp1C);
    }
    if (D_00202164 == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD2A0), D_00202158, &D_00202164, &sp1C);
    }
    if (D_00202160 == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD2B0), D_00202158, &D_00202160, &sp1C);
    }
    if (D_00202180 == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD2C0), D_00202158, &D_00202180, &sp1C);
    }
    if (D_00202168 == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD2D0), D_00202158, &D_00202168, &sp1C);
    }
    if (D_0020216C == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD2E0), D_00202158, &D_0020216C, &sp1C);
    }
    if (D_00202170 == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD2F0), D_00202158, &D_00202170, &sp1C);
        D_00202174 = *D_00202170;
    }
    if (D_00202178 == NULL) {
        Arc_LoadFile_2_00159DD0(File_HashName_3_00159D10(D_001FD310), D_00202158, &D_00202178, &sp1C);
        D_0020217C = *D_00202178;
    }
}
#undef D_00202174
#undef D_0020217C

/* DbCharProc_Layout_0_00195D80 */
void DbCharProc_Layout_0_00195D80(s32 i, f32 *a1, f32 *a2) { s32 sp; f32 f; UiAnim_Get_1_0017F840(3, &sp);  if (i >= D_00202154 - 3 && i <= D_00202154 + 3) { f = a2[2] - (f32)i; D_00201D24[i] = f; a1[5] = f; return; } D_00201D24[i] = -5.0f; a1[5] = -5.0f; }

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_00496B60[];
/* data twins (src/game/data/sbss.c): D_0020215C, D_00202164, D_00202174, D_0020217C */
Tbl *D_0020215C;
s32 *D_00202164;
s16 *D_00202174;
E_ItemSort_GetEntry_0_00195B80 *D_0020217C;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_001F2E00[];
/* data group (src/game/data/load_menu_draw_data.c): D_001F2E40__grp: D_001F2E40@0x0 */
s32 D_001F2E40__grp[0x8] __attribute__((aligned(16))) = { 0, 5, 0, (s32)D_001F2E00, 7, -0x3fc00000, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sbss.c): D_00202158__grp: D_00202158@0x0 */
u8 D_00202158__grp[0x4] __attribute__((aligned(8)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/load_menu_draw_data.c): D_001F2E00 */
u8 D_001F2E00[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
/* data twins (src/game/data/databook_rodata.c): D_001FD268 */
s8 D_001FD268[0x8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
