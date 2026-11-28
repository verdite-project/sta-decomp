#include "m2c.h"
#include "common.h"
#include "game/data.h"
#include "game/gfx.h"
#include "game/save.h"
#include "game/ui.h"
#include "game/sound.h"
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[0xC]; } Item_Ui_DrawItemIconEx_0_0017EDC0;
typedef struct { u32 n; Item_Ui_DrawItemIconEx_0_0017EDC0 *items; } List_Ui_DrawItemIconEx_0_0017EDC0;
typedef struct { u8 pad[0x10]; List_Ui_DrawItemIconEx_0_0017EDC0 *list; } Res_Ui_DrawItemIconEx_0_0017EDC0;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; u8 pad30[0x10]; } Item_Ui_DrawItemIcon_0_0017F0D0;
typedef struct { u32 n; Item_Ui_DrawItemIcon_0_0017F0D0 *items; } List_Ui_DrawItemIcon_0_0017F0D0;
typedef struct { u8 pad[0x10]; List_Ui_DrawItemIcon_0_0017F0D0 *list; } Res_Ui_DrawItemIcon_0_0017F0D0;
typedef struct { char p0[0x28]; f32 x28; char p2c[0x14]; f32 x40; char p44[4]; u8 b48; char p49[3]; } E_UiAnim_IsDone_1_0017F3D0;
typedef struct { u8 b0:1; u8 b1:1; u8 st:4; u8 b6:2; } BF_Ui_DrawItemIconEx_0_0017EDC0;
typedef struct { u8 pad[0x28]; f32 b8; u8 pad2[0x14]; f32 d0; f32 d4; BF_Ui_DrawItemIconEx_0_0017EDC0 bf; u8 pad3[3]; } E_UiAnim_SetTarget_1_0017F470;
typedef struct Node { s32 key; s32 x4; struct Node *val; } Node;
typedef struct Obj_UiAnim_Bind_1_0017F650 { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; f32 x14; Node *x18; } Obj_UiAnim_Bind_1_0017F650;
typedef struct Desc Desc;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 4; u8 b6 : 2; } B;
typedef struct { char p[0x48]; B b; char q[3]; } E_UiAnim_SetVisible_1_0017F7C0;
typedef struct { char b[0x4C]; } E_UiAnim_Get_1_0017F840;
typedef struct { f32 v[8]; } M8;
typedef struct { M8 a; M8 b; f32 c; u8 pad[0x4C - 0x44]; } E_UiAnim_SetColor_0_0017F890;
typedef union { u32 w; u8 b[4]; } C4;
typedef struct { s32 idx; s32 id; u8 pad8[0x24]; f32 f2C; f32 f30; u8 pad34[8]; C4 c; } Item_UiAnim_Draw_0_0017F990;
typedef struct { u32 n; Item_UiAnim_Draw_0_0017F990 *items; } List_UiAnim_Draw_0_0017F990;
typedef struct { f32 t; s32 id; } Key;
typedef struct { s32 x0; s32 id; } Obj_UiAnim_Draw_0_0017F990;
typedef struct { s32 res; s32 lst; s32 item; Key *keys; s32 n; f32 t; Obj_UiAnim_Draw_0_0017F990 *obj; void (*fn)(); } Anim;
typedef struct { s32 pad[3]; s32 f0C; s32 f10[7]; s32 pad2[1]; } St;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r; u8 g; u8 b; u8 a; } Col;
typedef struct { u8 pad[0x6C]; s8 *p; } O_Ui_DrawItemIconEx_0_0017EDC0;
typedef struct { f32 a; f32 b; } P2;
typedef struct { u8 p0 : 1; u8 b1 : 1; u8 st : 4; } BF_UiAnim_Step_0_00180810;
typedef struct { u8 pad[0x48]; BF_UiAnim_Step_0_00180810 fl; u8 pad2[3]; } E;
typedef struct { u8 r, g, b, a; } C;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C;
    u8 x2D;
    u8 x2E;
    u8 x2F;
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O_UiProc_DrawText_0_00180CA0;
typedef struct { s32 x0; s32 x4; s8 *x8; } P;
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R;
typedef struct { u8 pad0[0x9C]; R *x9C; u8 padA0[0x24]; R *xC4; } G;
extern Q D_001F25E0[];
#ifndef NONMATCHING
extern f32 D_0020205C;
#else
/* data twins (src/game/data/sbss.c): D_0020205C */
static f32 D_0020205C;
#endif
#ifndef NONMATCHING
extern s32 D_00486980[];
#else
/* data twins (src/game/data/ui_anim_bss.c): D_00486980 */
static s32 D_00486980[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_00486984[];
#else
/* data twins (src/game/data/ui_anim_bss.c): D_00486984 */
static f32 D_00486984[0x1];
#endif
#ifndef NONMATCHING
extern f32 D_00486988[];
#else
/* data twins (src/game/data/ui_anim_bss.c): D_00486988 */
static f32 D_00486988[0x2];
#endif
extern Q D_001F25D0[];
#ifndef NONMATCHING
extern f32 D_00202058;
#else
/* data twins (src/game/data/sbss.c): D_00202058 */
static f32 D_00202058;
#endif
extern E_UiAnim_IsDone_1_0017F3D0 D_00486990[];
#ifndef NONMATCHING
extern s32 D_0020203C;
#else
/* data twins (src/game/data/sbss.c): D_0020203C */
static s32 D_0020203C;
#endif
extern s32 D_00202048;
#ifndef NONMATCHING
extern s32 D_0020204C;
#else
/* data twins (src/game/data/sbss.c): D_0020204C */
static s32 D_0020204C;
#endif
extern s32 D_00202040;
#ifndef NONMATCHING
extern s32 D_00202044;
#else
/* data twins (src/game/data/sbss.c): D_00202044 */
static s32 D_00202044;
#endif
#ifndef NONMATCHING
extern s32 D_00201CC8;
#else
/* data twins (src/game/data/sdata.c): D_00201CC8 */
static s32 D_00201CC8 = -2;
#endif
#ifndef NONMATCHING
extern s32 D_00201CCC;
#else
/* data twins (src/game/data/sdata.c): D_00201CCC */
static s32 D_00201CCC = -2;
#endif
extern S D_001F25B0[] __attribute__((aligned(16)));
#ifndef NONMATCHING
extern f32 D_00202054;
#else
/* data twins (src/game/data/sbss.c): D_00202054 */
static f32 D_00202054;
#endif
#ifndef NONMATCHING
extern f32 D_00202050;
#else
/* data twins (src/game/data/sbss.c): D_00202050 */
static f32 D_00202050;
#endif
extern E_UiAnim_SetTarget_1_0017F470 D_00486990__as_UiAnim_SetTarget_1_0017F470[];
extern E_UiAnim_SetVisible_1_0017F7C0 D_00486990__as_UiAnim_SetVisible_1_0017F7C0[24];
extern E_UiAnim_SetColor_0_0017F890 D_00486990__as_UiAnim_SetColor_0_0017F890[];
#ifndef NONMATCHING
extern P2 *D_0048699C[];
#else
/* data twins (src/game/data/ui_anim_bss.c): D_0048699C */
static P2 *D_0048699C[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004869A0[];
#else
/* data twins (src/game/data/ui_anim_bss.c): D_004869A0 */
static s32 D_004869A0[0x4];
#endif
extern s32 D_004869B4[];
extern f32 D_004869B8[];
extern f32 D_004869D0[];
extern f32 D_004869D4[];
extern s32 D_00486990__as_UiAnim_Step_0_00180810[];
s32 UiAnim_SetTarget_1_0017F470(s32 arg0, s32 arg1, f32 val);
void UiAnim_Bind_1_0017F650(Obj_UiAnim_Bind_1_0017F650 *o, Desc *d);
void UiAnim_Get_1_0017F840(s32 i, E_UiAnim_Get_1_0017F840 **out);
void UiAnim_SetColor_0_0017F890(s32 arg0, M8 *a1, M8 *a2);
void UiAnim_Draw_0_0017F990(Anim *s);
void Movie_Play_2_0017FF70(s32 arg0);
void Ui_SetOffsetB_0_001803C0(s32 arg0, s32 arg1);
void Ui_SetOffset_0_001803D0(s32 arg0, s32 arg1);
void UiProc_DrawIcon_0_001803E0(s8 *o, s32 unused, u32 id, s32 up);
void Ui_DrawCursor_1_001805D0(f32 *arg0, s32 arg1, s32 arg2, s32 arg3);
void UiAnim_Step_0_00180810(s32 i);
void UiProc_DrawText_0_00180CA0(O_UiProc_DrawText_0_00180CA0 *o, s32 a1, u32 mode, P *p);
Res_Ui_DrawItemIconEx_0_0017EDC0* MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
f32 sinf(f32);
void Ui_DrawList_1_001829B0(Item_Ui_DrawItemIconEx_0_0017EDC0 *, s32, void (*)(), s32);
f32 fabsf(f32);
void Tex_UploadQueuedWrap_0_00176A40(void);
s32 Option_GetSeVolume_1_001A9480(void);
void DisableIntc(s32);
s32* Pool_Alloc_3_001288C0(s8 *, u32);
void Movie_SetParams_0_001ED5D0(s32, s32, s32, s32);
void Movie_Start_2_001ED0C0(s32, s32, s32, void (*)(void), s32, s32, s32, s32);
void Pad_AnyButtonPressed_1_00180F10(void);
void EnableIntc(s32);
void Pool_Free_2_00128580(s8 *, s32 *);
void GsPkt_SetReg_3_001543E0(s32, s64);
void SaveSys_GetSlotCount_0_001E5E80(St *);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
void SaveSys_GetResult_0_001E6080(s32 *);
void Ui_DrawSprite_2_00181680(s32, void *, void *, void*, S*, s32);
void Ui_DrawSpriteRotated_1_00182080(f32, s32, f32 *, s8 *, s32 *, s32);
List_UiAnim_Draw_0_0017F990** MenuLayout_Get_1_00189050__as_UiAnim_Draw_0_0017F990(s32);
void Ui_DrawList_1_001829B0__as_UiAnim_Draw_0_0017F990(Item_UiAnim_Draw_0_0017F990 *, s32, void (*)(), Obj_UiAnim_Draw_0_0017F990 *);
O_Ui_DrawItemIconEx_0_0017EDC0* MenuLayout_GetSub_1_00189020__as_Ui_DrawCursor_1_001805D0(s32);
s32 UiAnim_Step_0_00180810__as_Ui_DrawItemIconEx_0_0017EDC0();
void Text_Draw_2_001875C0(f32, f32, f32, s8 *, s32, u32);
void Color_PulseB_1_00187A20(f32, u8 *, s32);

/* Ui_DrawItemIconEx_0_0017EDC0_ */
#define UiProc_DrawText_0_00180CA0 UiProc_DrawText_0_00180CA0__as_Ui_DrawItemIconEx_0_0017EDC0_
void UiProc_DrawText_0_00180CA0__as_Ui_DrawItemIconEx_0_0017EDC0_(void);
#define Ui_DrawSprite_2_00181680 Ui_DrawSprite_2_00181680__as_Ui_DrawItemIconEx_0_0017EDC0_
void Ui_DrawSprite_2_00181680__as_Ui_DrawItemIconEx_0_0017EDC0_(s32, s8 *, s8 *, void *, S *, s32);

/* Ui_DrawItemIconEx_0_0017EDC0 */

/* Ui_DrawItemIconEx_0_0017EDC0 */

void Ui_DrawItemIconEx_0_0017EDC0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    Item_Ui_DrawItemIconEx_0_0017EDC0 it;
    Q v;
    s32 base;
    u32 i;
    List_Ui_DrawItemIconEx_0_0017EDC0 *l;
    f32 t;
    f32 d;

    l = MenuLayout_Get_1_00189050(5)->list;
    base = MenuLayout_GetSub_1_00189020(5);
    if (a0) {
        t = 1.0f;
    } else {
        D_00486980[0] = 0;
        t = 0.0f;
        D_00486988[0] = 0.0f;
        D_00486984[0] = 0.0f;
    }
    d = 0.25f * (t - D_0020205C);
    D_00486980[0] += 5;
    D_00486980[0] %= 180;
    D_00486984[0] = 10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    D_00486988[0] = -10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * (1.0f - D_0020205C);
        it.f30 = 166.0f;
        Ui_DrawList_1_001829B0(&it, base + l->items[i].idx * 8, UiProc_DrawIcon_0_001803E0, a1);
    }
    v = D_001F25E0[0];
    v.f[0] -= 80.0f * (1.0f - D_0020205C);
    v.f[2] -= 80.0f * (1.0f - D_0020205C);
    Ui_DrawCursor_1_001805D0(&v, a2, a3, a4);
    D_0020205C += d;
    if (D_0020205C > 1.0f) {
        D_0020205C = 1.0f;
    }
    if (D_0020205C < 0.0f) {
        D_0020205C = 0.0f;
    }
}

/* Ui_DrawItemIcon_0_0017F0D0 */

void Ui_DrawItemIcon_0_0017F0D0(s32 a0, s32 a1, s32 a2, s32 a3) {
    Item_Ui_DrawItemIcon_0_0017F0D0 it;
    Q v;
    s32 base;
    u32 i;
    List_Ui_DrawItemIcon_0_0017F0D0 *l;
    f32 t;
    f32 d;

    l = MenuLayout_Get_1_00189050(5)->list;
    base = MenuLayout_GetSub_1_00189020(5);
    if (a0) {
        t = 1.0f;
    } else {
        D_00486980[0] = 0;
        t = 0.0f;
        D_00486988[0] = 0.0f;
        D_00486984[0] = 0.0f;
    }
    d = 0.25f * (t - D_00202058);
    D_00486980[0] += 5;
    D_00486980[0] %= 180;
    D_00486984[0] = 10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    D_00486988[0] = -10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * (1.0f - D_00202058);
        Ui_DrawList_1_001829B0(&it, base + l->items[i].idx * 8, UiProc_DrawIcon_0_001803E0, 1);
    }
    v = D_001F25D0[0];
    v.f[0] -= 80.0f * (1.0f - D_00202058);
    v.f[2] -= 80.0f * (1.0f - D_00202058);
    Ui_DrawCursor_1_001805D0(&v, a1, a2, a3);
    D_00202058 += d;
    if (D_00202058 > 1.0f) {
        D_00202058 = 1.0f;
    }
    if (D_00202058 < 0.0f) {
        D_00202058 = 0.0f;
    }
}

/* UiAnim_IsDone_1_0017F3D0 */
s32 UiAnim_IsDone_1_0017F3D0(s32 i) {
    s32 r = fabsf(D_00486990[i].x40 - D_00486990[i].x28) < 0.01f;
    if (r) { E_UiAnim_IsDone_1_0017F3D0 *e = &D_00486990[i]; r = (e->b48 & 1) != 0; }
    return r;
}

/* UiAnim_SetTarget_1_0017F470 */

s32 UiAnim_SetTarget_1_0017F470(s32 arg0, s32 arg1, f32 val) {
    s32 i = arg0 % 24;
    BF_Ui_DrawItemIconEx_0_0017EDC0 *p = &D_00486990__as_UiAnim_SetTarget_1_0017F470[i].bf;
    if (p->st == 0) {
        D_00486990__as_UiAnim_SetTarget_1_0017F470[i].d0 = val;
        D_00486990__as_UiAnim_SetTarget_1_0017F470[i].d4 = 0.25f * (val - D_00486990__as_UiAnim_SetTarget_1_0017F470[i].b8);
        p->b1 |= arg1 & 1;
        return 1;
    } else if (p->st == 3) {
        D_00486990__as_UiAnim_SetTarget_1_0017F470[i].d0 = val;
        D_00486990__as_UiAnim_SetTarget_1_0017F470[i].d4 = 0.25f * (val - D_00486990__as_UiAnim_SetTarget_1_0017F470[i].b8);
        p->b1 |= arg1 & 1;
        return 0;
    }
    return 0;
}

/* UiAnim_UpdateAll_1_0017F5C0 */

void UiAnim_UpdateAll_1_0017F5C0(void) {
    s32 (*temp_2)(s32);
    s32 var_17;
    u8 *var_16;

    var_17 = 0;
    var_16 = D_00486990;
    do {
        if (M2C_FIELD(var_16, u8 *, 0x48) & 1) {
            temp_2 = M2C_FIELD(var_16, s32 (**)(s32), 0x34);
            if (temp_2 != NULL) {
                temp_2(var_17);
            } else {
                UiAnim_Step_0_00180810__as_Ui_DrawItemIconEx_0_0017EDC0(var_17);
            }
            UiAnim_Bind_1_0017F650(var_16, var_16 + 0x20);
        }
        var_17 += 1;
        var_16 += 0x4C;
    } while (var_17 < 0x18);
}

/* UiAnim_Bind_1_0017F650 */
struct Desc {
    s32 *list;
    s32 n;
    f32 x8;
    Node *(*get)(s32);
    s32 (*f10)(s32);
    s32 x14;
    void (*f18)(s32, Obj_UiAnim_Bind_1_0017F650 *, Desc *);
};

void UiAnim_Bind_1_0017F650(Obj_UiAnim_Bind_1_0017F650 *o, Desc *d) {
    Node *old;
    s32 i;
    s32 key;
    s32 off;
    Node n;
    Node *np;
    Node **pv;

    if (o == NULL || d == NULL) {
        return;
    }
    old = o->x18;
    i = 0;
    if (i < d->n) {
        off = 0;
        pv = &n.val;
        np = &n;
        do {
            if (d->get != NULL) {
                if (d->list == NULL) {
                    goto next;
                }
                key = *(s32 *)((s8 *)d->list + off);
                *pv = d->get(key);
                n.key = key;
                if (*pv == NULL) {
                    goto next;
                }
                o->x18 = np;
            } else {
                *pv = old;
                o->x18 = np;
            }
            if (d->f10 != NULL) {
                if (d->list == NULL) {
                    goto next;
                }
                o->x8 = d->f10(*(s32 *)((s8 *)d->list + off));
            }
            if (d->f18 != NULL) {
                d->f18(i, o, d);
            } else {
                o->x14 = d->x8 - (f32)i;
            }
            UiAnim_Draw_0_0017F990(o);
        next:
            i++;
            off += 4;
        } while (i < d->n);
    }
}

/* UiAnim_SetVisible_1_0017F7C0 */
void UiAnim_SetVisible_1_0017F7C0(s32 i, s32 on, s32 f) {
    B *b;
    i %= 24;
    b = &D_00486990__as_UiAnim_SetVisible_1_0017F7C0[i].b;
    b->b0 = on & 1;
    if (f) b->b2 = 3;
}

/* UiAnim_Get_1_0017F840 */

void UiAnim_Get_1_0017F840(s32 i, E_UiAnim_Get_1_0017F840 **out)
{
    i %= 24;
    if (out)
        *out = &D_00486990[i];
}

/* UiAnim_SetColor_0_0017F890 */

void UiAnim_SetColor_0_0017F890(s32 arg0, M8 *a1, M8 *a2) {
    arg0 %= 24;
    if (a1 != NULL) {
        D_00486990__as_UiAnim_SetColor_0_0017F890[arg0].a = *a1;
    }
    if (a2 != NULL) {
        D_00486990__as_UiAnim_SetColor_0_0017F890[arg0].b = *a2;
        D_00486990__as_UiAnim_SetColor_0_0017F890[arg0].c = a2->v[2];
    }
}

/* UiAnim_Draw_0_0017F990 */
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

void UiAnim_Draw_0_0017F990(Anim *s) {
    Item_UiAnim_Draw_0_0017F990 it;
    C4 c;
    List_UiAnim_Draw_0_0017F990 *l;
    s32 base;
    f32 t;
    s32 n;
    Key *keys;
    s32 i;
    s32 hi;
    s32 lo;
    f32 f;
    Item_UiAnim_Draw_0_0017F990 *pB;
    Item_UiAnim_Draw_0_0017F990 *pA;
    Obj_UiAnim_Draw_0_0017F990 *o;

    if (s == 0) return;
    l = MenuLayout_Get_1_00189050__as_UiAnim_Draw_0_0017F990(s->res)[s->lst];
    base = MenuLayout_GetSub_1_00189020(s->res);
    keys = s->keys;
    t = s->t;
    n = s->n;
    if (l == 0 || base == 0 || keys == 0 || n == 0) return;
    if (t < keys[0].t) return;
    if (keys[n - 1].t < t) return;
    for (i = 0; i < n - 1; i++) {
        if (keys[i].t <= t && t <= keys[i + 1].t) {
            lo = i;
            hi = i + 1;
            break;
        }
    }
    f = (t - keys[lo].t) / (keys[hi].t - keys[lo].t);
    lo = keys[lo].id;
    hi = keys[hi].id;
    pA = 0;
    pB = 0;
    for (i = 0; i < l->n; i++) {
        if (hi == l->items[i].id) pB = &l->items[i];
        if (lo == l->items[i].id) pA = &l->items[i];
    }
    if (pB == 0 || pA == 0) return;
    o = s->obj;
    o->id = f < 0.5f ? lo : (lo = hi);
    it = l->items[s->item];
    it.f2C = pB->f2C * f + pA->f2C * (1.0f - f);
    it.f30 = pB->f30 * f + pA->f30 * (1.0f - f);
    c.b[0] = mu(pB->c.b[0], f) + mu(pA->c.b[0], (1.0f - f));
    c.b[1] = mu(pB->c.b[1], f) + mu(pA->c.b[1], (1.0f - f));
    c.b[2] = mu(pB->c.b[2], f) + mu(pA->c.b[2], (1.0f - f));
    c.b[3] = mu(pB->c.b[3], f) + mu(pA->c.b[3], (1.0f - f));
    if (c.b[0] == 0x7F) c.b[0] = 0x80;
    if (c.b[1] == 0x7F) c.b[1] = 0x80;
    if (c.b[2] == 0x7F) c.b[2] = 0x80;
    if (c.b[3] == 0x7F) c.b[3] = 0x80;
    it.c = c;
    if (s->fn == 0) {
        Ui_DrawList_1_001829B0__as_UiAnim_Draw_0_0017F990(&it, base + it.idx * 8, UiProc_DrawText_0_00180CA0, s->obj);
    } else {
        Ui_DrawList_1_001829B0__as_UiAnim_Draw_0_0017F990(&it, base + it.idx * 8, s->fn, s->obj);
    }
}

/* Movie_Play_2_0017FF70 */
void Movie_Play_2_0017FF70(s32 arg0) {
    s32 *blk;
    s32 vol;

    GsPkt_EndLayer_1_00155900();
    GsPkt_ResetLayer_0_00154AF0();
    Tex_UploadQueuedWrap_0_00176A40();
    Gfx_FlipBuffers_2_00155370();
    Gfx_WaitDraw_1_001552A0();
    Gfx_KickFrame_1_00154B70();
    GsPkt_DrawClearRect_0_00153D80();
    GsPkt_ResetLayer_0_00154AF0();
    Gfx_FlipBuffers_2_00155370();
    Gfx_WaitDraw_1_001552A0();
    vol = (Option_GetSeVolume_1_001A9480() & 0xFF) * 2;
    if (vol > 0x7F) {
        vol = 0x7F;
    }
    SndDrv_CallRpcSyncWaitB_2_001D7FD0();
    DisableIntc(9);
    blk = Pool_Alloc_3_001288C0(D_00222AF0, 0xA00000);
    Movie_SetParams_0_001ED5D0(0, 0, 0, 0x1E);
    Movie_Start_2_001ED0C0(arg0, *blk, 0xA00000, Pad_AnyButtonPressed_1_00180F10, vol * 129, 2, 0, 0);
    EnableIntc(9);
    Pool_Free_2_00128580(D_00222AF0, blk);
    SndDrv_CallRpcSyncWait_2_001D7EC0();
    Gfx_Nop_2_001558F0();
    Gfx_KickFrame_1_00154B70();
    Tex_BeginFrame_0_00176A60();
    GsPkt_SetLayer_1_00154700(5, -2);
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x40, 0x027F0000 | ((s64)0x01BF0000 << 32));
    GsPkt_SetReg_3_001543E0(0x41, 0x027F0000 | ((s64)0x01BF0000 << 32));
    GsPkt_SetReg_3_001543E0(0x49, 0);
    GsPkt_Flush_1_001544C0();
}

/* Movie_Stop_0_00180110 */
s32 Movie_Stop_0_00180110(void) {
    s32 r = 0;
    SaveSys_SetPort_1_001E82A0(0);
    switch (SaveSys_IsCardReady_0_001E6110()) {
    case 1: r &= ~0xF; break;
    case 0: r |= 3; break;
    case 2: r |= 1; break;
    }
    SaveSys_SetPort_1_001E82A0(1);
    switch (SaveSys_IsCardReady_0_001E6110()) {
    case 1: r &= ~0xF0; break;
    case 0: r |= 0x30; break;
    case 2: r |= 0x10; break;
    }
    return r;
}

/* Movie_Update_0_001801F0 */
s32 Movie_Update_0_001801F0(s32 arg0) {
    s32 s;
    St st = {0};
    s32 r;

    r = -1;
    switch (D_0020203C) {
    case 0:
        if (SaveSys_SetPort_1_001E82A0(arg0) != 0) {
            D_0020203C++;
        } else {
            r = 0;
            break;
        }
    case 1:
        if (SaveSys_StartRead_0_001E5F30(0, 0) == 0) {
            r = 0;
            D_0020203C++;
        } else {
            D_0020203C = 0;
        }
        break;
    case 2:
        if (arg0 != SaveSys_GetPort_1_001E8290()) {
            D_0020203C = 0;
            break;
        }
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 2) {
            r = 0;
        } else if (s == 0) {
            SaveSys_GetSlotCount_0_001E5E80(&st);
            if (st.f10[0] != 0 || st.f10[1] != 0 || st.f10[2] != 0 || st.f10[3] != 0 || st.f10[4] != 0 ||
                st.f10[5] != 0 || st.f10[6] != 0) {
                r = 2;
            } else {
                r = 1;
            }
            if (st.f0C == 1) {
                r |= 4;
            }
            D_0020203C = 0;
} else {
            D_0020203C = 0;
            r = 0x40000000;
        }
        break;
    default:
        D_0020203C = 0;
        break;
    }
    return r;
}

/* Ui_SetOffsetA_0_001803B0 */
void Ui_SetOffsetA_0_001803B0(s32 arg0, s32 arg1) {
    D_00202048 = arg0;
    D_0020204C = arg1;
}

/* Ui_SetOffsetB_0_001803C0 */
void Ui_SetOffsetB_0_001803C0(s32 arg0, s32 arg1) {
    D_00202040 = arg0;
    D_00202044 = arg1;
}

/* Ui_SetOffset_0_001803D0 */
void Ui_SetOffset_0_001803D0(s32 arg0, s32 arg1) {
    D_00201CC8 = arg0;
    D_00201CCC = arg1;
}

/* UiProc_DrawIcon_0_001803E0 */

void UiProc_DrawIcon_0_001803E0(s8 *o, s32 unused, u32 id, s32 up) {
    S t __attribute__((aligned(16)));
    Col col;
    s8 *p;

    t = D_001F25B0[0];
    col.b = 0x80;
    col.g = 0x80;
    col.r = 0x80;
    col.a = 0x40;
    if (id < 200) {
        t.x = *(f32 *)(o + 0x30);
        t.y = *(f32 *)(o + 0x34);
        Ui_DrawSprite_2_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        return;
    }
    if (up) {
        D_00202054 += 4.0f;
        if (!(D_00202054 <= 64.0f)) {
            D_00202054 = 64.0f;
        }
    } else {
        D_00202054 -= 4.0f;
        if (D_00202054 < 0.0f) {
            D_00202054 = 0.0f;
        }
    }
    col.a = D_00202054;
    switch (id) {
    case 200:
        p = *(s8 **)(MenuLayout_GetSub_1_00189020(0) + 0x8C) + 0x30;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C) + D_00486988[0];
        Ui_DrawSprite_2_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, 1);
        break;
    case 201:
        p = *(s8 **)(MenuLayout_GetSub_1_00189020(0) + 0x8C);
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C) + D_00486984[0];
        Ui_DrawSprite_2_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, 1);
        break;
    }
}

/* Ui_DrawCursor_1_001805D0 */

void Ui_DrawCursor_1_001805D0(f32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 col;
    f32 c[4];
    f32 b[4];
    f32 a[4];
    f32 inv, h, step, d;
    O_Ui_DrawItemIconEx_0_0017EDC0 *s0;
    s32 n;

    s0 = MenuLayout_GetSub_1_00189020__as_Ui_DrawCursor_1_001805D0(0);
    col = 0x80404040;
    inv = 1.0f / (f32)(arg2 - (arg1 - 1));
    d = arg0[3] - arg0[1];
    h = inv * d;
    if (arg1 == arg2) {
        D_00202050 = 0.0f;
    } else {
        step = h;
        if (h < 10.0f) {
            step = inv * (d - 10.0f);
            h = 10.0f;
        }
        if (arg2 < arg3 + arg1) {
            D_00202050 = step * (f32)(arg2 - arg1);
        } else {
            if (arg3 < 0) arg3 = 0;
            D_00202050 = (f32)arg3 * step;
        }
    }
    b[0] = arg0[0];
    b[1] = (f32)(s32)D_00202050 + arg0[1];
    b[2] = arg0[2];
    b[3] = 4.0f + ((f32)(s32)D_00202050 + arg0[1]);
    c[0] = arg0[0];
    c[1] = 4.0f + ((f32)(s32)D_00202050 + arg0[1]);
    c[2] = arg0[2];
    c[3] = (f32)(s32)h + ((f32)(s32)D_00202050 + arg0[1]);
    a[0] = arg0[0];
    a[1] = (f32)(s32)h + ((f32)(s32)D_00202050 + arg0[1]);
    a[2] = arg0[2];
    a[3] = (f32)(s32)h + (4.0f + ((f32)(s32)D_00202050 + arg0[1]));
    Menu_DrawBackground_0_00187B20(0);
    n = M2C_FIELD(s0->p, s32 *, 4);
    Ui_DrawSpriteRotated_1_00182080(0.0f, n, b, s0->p + 0x20, &col, 0);
    Ui_DrawSpriteRotated_1_00182080(0.0f, n, c, s0->p + 0x50, &col, 0);
    Ui_DrawSpriteRotated_1_00182080(0.0f, n, a, s0->p + 0x80, &col, 0);
}

/* UiAnim_Step_0_00180810 */

void UiAnim_Step_0_00180810(s32 i) {
    f32 *cur;
    f32 *dst;
    f32 d;
    f32 st;
    BF_UiAnim_Step_0_00180810 *fl;
    s32 k = i * 19;

    cur = &D_004869B8[k];
    dst = &D_004869D0[k];
    d = fabsf(*dst - *cur);
    D_004869D4[k] = 0.25f * (*dst - *cur);
    fl = (BF_UiAnim_Step_0_00180810 *)((u8 *)&D_00486990__as_UiAnim_Step_0_00180810[k] + 0x48);
    switch (fl->st) {
    case 0:
        if (!(d <= D_004869A0[k] / 2.0f) && !fl->b1) {
            if (D_004869D4[k] < 0.0f) {
                *dst = (f32)D_004869B4[k] + D_0048699C[k][D_004869A0[k] - 1].a - 1.0f;
            } else {
                D_004869D0[k] = D_004869D0[k] = D_0048699C[k][0].a;
            }
            fl->st = 1;
        } else if (!(d <= 0.01f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else if (!(d <= 0.0f)) {
                *cur += st;
            }
        } else {
            fl->b1 = 0;
        }
        break;
    case 1:
        if (!(d <= 0.01f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else if (!(d <= 0.0f)) {
                *cur += st;
            }
        } else {
            if (!(*cur <= 0.0f)) {
                *cur = D_0048699C[k][0].a;
                *dst = 0.0f;
            } else { s32 *z = &D_004869B4[k];
                *cur = (f32)*z + D_0048699C[k][D_004869A0[k] - 1].a - 1.0f;
                *dst = (f32)*z - 1.0f;
            }
            fl->st = 2;
        }
        break;
    case 2:
        if (!(d <= 1.0f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else {
                *cur += st;
            }
        } else {
            fl->st = 0;
            fl->b1 = 0;
        }
        break;
    case 3:
        if (!(d <= 1.0f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else if (!(d <= 0.0f)) {
                *cur += st;
            }
        } else {
            fl->st = 0;
            fl->b1 = 0;
        }
        break;
    }
}
#undef UiProc_DrawText_0_00180CA0
#undef Ui_DrawSprite_2_00181680

/* UiProc_DrawText_0_00180CA0 */
#define Ui_DrawSprite_2_00181680 Ui_DrawSprite_2_00181680__as_UiProc_DrawText_0_00180CA0
void Ui_DrawSprite_2_00181680__as_UiProc_DrawText_0_00180CA0(s32, void *, void *, void *, S *, u32);
#define MenuLayout_GetSub_1_00189020 MenuLayout_GetSub_1_00189020__as_UiProc_DrawText_0_00180CA0
G *MenuLayout_GetSub_1_00189020__as_UiProc_DrawText_0_00180CA0(s32);
#pragma explicit_zero_data on
S D_001F2590 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
#define D_00202040 D_00202040__as_UiProc_DrawText_0_00180CA0
extern s32 *D_00202040__as_UiProc_DrawText_0_00180CA0;
#define D_00202048 D_00202048__as_UiProc_DrawText_0_00180CA0
extern s32 *D_00202048__as_UiProc_DrawText_0_00180CA0;
static inline s32 get(s32 *tbl, s32 i) {
    if (tbl != 0 && i > 0) {
        return tbl[i];
    }
    return 0;
}

void UiProc_DrawText_0_00180CA0(O_UiProc_DrawText_0_00180CA0 *o, s32 a1, u32 mode, P *p) {
    S buf __attribute__((aligned(16)));
    C col;
    s8 *str;
    R *r;

    str = p->x8;
    buf = D_001F2590;
    if (str == 0) {
        return;
    }
    if (mode < 200) {
        buf.x = o->x30;
        buf.y = o->x34;
        Ui_DrawSprite_2_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
        if (get(D_00202040, p->x0) == 0) {
            return;
        }
        r = MenuLayout_GetSub_1_00189020(0)->xC4;
        buf.x = o->x38;
        buf.y = o->x3C - 4.0f;
        o->x2C = 0x50;
        o->x2D = 0x80;
        o->x2E = 0x40;
        Color_PulseB_1_00187A20(D_002020D4, &o->x2C, 0x50);
        Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 200:
        if (p->x0 == D_00201CC8 || p->x0 == D_00201CCC) {
            r = MenuLayout_GetSub_1_00189020(0)->x9C;
            buf.x = o->x38;
            buf.y = o->x3C;
            Ui_DrawSprite_2_00181680(r->x4, r->x10, r->x20, &o->x2C, &buf, mode);
        }
        break;
    case 201:
        if (get(D_00202048, p->x0) != 0) {
            *(u32 *)&col = 0x80404080;
        } else {
            *(u32 *)&col = 0x80808080;
        }
        col.a = o->x2F * 2;
        o->x38 += 96.0f;
        Text_Draw_2_001875C0(o->x38, o->x3C, 1.0f, str, 1, *(u32 *)&col);
        break;
    }
}
#undef Ui_DrawSprite_2_00181680
#undef MenuLayout_GetSub_1_00189020
#undef D_00202040
#undef D_00202048

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202040, D_00202048 */
s32 D_00202040;
s32 D_00202048;
/* data twins (src/game/data/ui_anim_bss.c): D_004869B4, D_004869D0 */
s32 D_004869B4[0x7] __attribute__((aligned(4)));
f32 D_004869D0[0x1b8];
#endif
