#include "m2c.h"
#include "common.h"
#include "game/model.h"
#include "game/data.h"
typedef struct { u8 a:3; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u16 x14, x16, x18, x1A, x1C, x1E;
    u16 x20, x22;
    u8 pad24[8];
    s32 x2C;
    u8 pad30[0xC];
    union { s32 w; Bits f; } x3C;
} Obj_Mdl_LoadChunk_0_00170000;
typedef struct { Obj_Mdl_LoadChunk_0_00170000 *obj; } Blk;
typedef struct { u16 x0, x2, x4, x6, x8; u8 xA, xB; u8 xC_0:3; u8 xC_3:3; u8 xC_6:2; u8 xD_0:2; u8 xD_2:1; u8 xD_3:5; u8 xE; } Info;
typedef struct { u8 pad[0xC]; s32 size; } Sub;
typedef struct { s32 magic; u8 pad4[0xC]; Sub sub; } Hdr_Mdl_LoadChunk_0_00170000;
typedef struct { u8 pad[0x38]; void *x38; void *x3C; } El;
typedef struct {
    u8 pad[0x10]; s8 **x10; u8 pad14[6]; u16 x1A; u8 pad1C[6]; s16 x22; s32 x24;
    u8 pad28[4]; void *x2C; u8 pad30[0xC]; Flags8 x3C;
} H_Mdl_Free_0_00170250;
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H_Mdl_Relocate_1_00170380;
typedef struct Ch {
    s32 x0;
    s32 x4;
    u32 type : 8;
    u32 off : 24;
    u16 xC;
    u16 xE;
    H_Mdl_Relocate_1_00170380 h;
} Ch;
typedef struct {
    Vec v;
    s32 *x10;
    u16 x14, x16, x18, x1A, x1C, x1E;
    u16 x20, x22;
    s32 x24;
    s32 x28;
    s32 x2C;
    u8 pad30[0xC];
    union { s32 w; Bits f; } x3C;
} Obj_Mdl_Relocate_1_00170380;
typedef struct { s32 x0, x4, x8, xC; } E16;
typedef struct { s32 x0; u16 x4; u16 x6; } E8;
typedef struct { s32 x0, x4, x8, xC; s32 x10[8]; s32 x30[8]; } E50;
typedef struct { u16 p0, p2; u16 x4; u16 p6; } E_Mdl_ReleaseTexAnims_0_00170E90;
typedef struct { u8 pad[0x10]; s32 x10; u16 n14, n16, n18, p1A, n1C, n1E, n20; u8 pad2[0x1E]; u8 data[1]; } O;
typedef struct { s32 a; u16 w; u16 h; } Ent;
typedef struct { u8 pad[0x10]; s32 *base; u16 n14; u16 n16; u16 n18; u16 n1A; u16 n1C; u16 n1E; u16 count; u8 pad2[0x1A]; u8 flags; u8 p3[3]; } Hdr_Mdl_RegisterTexAnims_0_00170F40;
typedef struct { u8 b[16]; } B16;typedef struct {
    s32 p0;
    u8 x4;
    u8 p5;
    u16 n;
    u16 x8;
    u16 xA;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1C;
    f32 x20;
    u8 p24;
    u8 b0:2;
    u8 st:3;
    u8 b5:3;
    u8 pad[0x1A];
    s8 data[1];
} Obj_Mdl_SetBoneRotation_0_001710D0;
typedef union {
    u64 w;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } f;
} F;
typedef struct {
    Mtx m;
    Mtx x40;
    Mtx x80;
    u8 padC0[0x131 - 0xC0];
    u8 x131;
    u8 pad132[2];
    f32 x134;
    F x138;
} E_Mdl_UpdateBoneMatrices_0_00171270;
typedef struct {
    u8 pad[6];
    u16 x6;
    u8 pad8[0x24 - 8];
    u8 x24a:6;
    u8 x24b:2;
    u8 pad25[0x30 - 0x25];
    Vec x30;
    u8 x40[1];
} H_Mdl_UpdateBoneMatrices_0_00171270;
#ifndef NONMATCHING
extern volatile s32 D_0042D880[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D880 */
static volatile s32 D_0042D880[0x1];
#endif
#ifndef NONMATCHING
extern volatile s32 D_0042D884[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D884 */
static volatile s32 D_0042D884[0x1];
#endif
#ifndef NONMATCHING
extern volatile s32 D_0042D888[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D888 */
static volatile s32 D_0042D888[0x1];
#endif
#ifndef NONMATCHING
extern volatile s32 D_0042D88C[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D88C */
static volatile s32 D_0042D88C[0x1];
#endif
#ifndef NONMATCHING
extern volatile s32 D_0042D890[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D890 */
static volatile s32 D_0042D890[0x1];
#endif
#ifndef NONMATCHING
extern volatile s32 D_0042D894[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D894 */
static volatile s32 D_0042D894[0x1];
#endif
#ifndef NONMATCHING
extern volatile s32 D_0042D898[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D898 */
static volatile s32 D_0042D898[0x1];
#endif
extern E16 * volatile D_0042D89C[];
extern E8 * volatile D_0042D8A0[];
extern s32 * volatile D_0042D8A4[];
extern E50 * volatile D_0042D8A8[];
extern s32 * volatile D_0042D8AC[];
extern E8 * volatile D_0042D8B0[];
#ifndef NONMATCHING
extern volatile s32 D_0042D8B4[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D8B4 */
static volatile s32 D_0042D8B4[0x1];
#endif
#ifndef NONMATCHING
extern volatile s32 D_0042D8B8[];
#else
/* data twins (src/game/data/texture_bss.c): D_0042D8B8 */
static volatile s32 D_0042D8B8[0x2];
#endif
Blk* Mdl_LoadChunk_0_00170000(s32 *a0, s32 a1, Hdr_Mdl_LoadChunk_0_00170000 *hdr);
void Mdl_Free_0_00170250(s32 *a0, H_Mdl_Free_0_00170250 **a1);
s32 Mdl_Relocate_1_00170380(Ch *c, Obj_Mdl_Relocate_1_00170380 *o);
void Mdl_ReleaseTexAnims_0_00170E90(O **arg0);
void Mdl_RegisterTexAnims_0_00170F40(Hdr_Mdl_RegisterTexAnims_0_00170F40 **arg0);
void Mdl_GetSectionPtrs_1_00171050(u8 *arg0, u8 *arg1);
void Mdl_SetBoneRotation_0_001710D0(Obj_Mdl_SetBoneRotation_0_001710D0 *obj, s16 a1, f32 a, f32 b, f32 c);
void Mdl_UpdateBoneMatrices_0_00171270(H_Mdl_UpdateBoneMatrices_0_00171270 *h, Mtx *a1, s32 a2);
void Mdl_UpdateBoneMatricesCur_0_00171540(s32 arg0, s32 arg1);
Blk* Pool_Alloc_3_001288C0(s32, s32);
void Pool_ArrayAppend_0_001535B0(s32 *, Blk *);
void memset(Obj_Mdl_LoadChunk_0_00170000 *, s32, s32);
void Pool_Free_2_00128580(s32, void *);
void Tex_Release_1_00177570(void *);
void Pool_FreeChunk_0_001531A0(void *, H_Mdl_Free_0_00170250 **);
void sceVu0CopyVector(Vec *, Vec *);
void TexAnim_Release_0_001758B0(u16, s32);
void TexAnim_Register_0_001759D0(s32, u32, s32, s32 *);
void sceVu0CopyMatrix(void *, void *);
void sceVu0AddVector(void *, void *, void *);
f32 Mtx_MaxAxisScale_2_00171550(E_Mdl_UpdateBoneMatrices_0_00171270 *);
void sceVu0MulMatrix(E_Mdl_UpdateBoneMatrices_0_00171270 *, void *, void *);

/* Mdl_LoadChunk_0_00170000 */
#define Mdl_Relocate_1_00170380 Mdl_Relocate_1_00170380__as_Mdl_LoadChunk_0_00170000
void Mdl_Relocate_1_00170380__as_Mdl_LoadChunk_0_00170000(Hdr_Mdl_LoadChunk_0_00170000 *, Obj_Mdl_LoadChunk_0_00170000 *);

Blk *Mdl_LoadChunk_0_00170000(s32 *a0, s32 a1, Hdr_Mdl_LoadChunk_0_00170000 *hdr) {
    Blk *b;
    Info *info;
    s32 size;
    Sub *sub;

    b = NULL;
    switch (hdr->magic) {
    case 0x4D415453:
    sub = &hdr->sub;
    info = (Info *)((s32)(sub + 1) + ((sub->size + 15) & ~15));
    size = info->x0 * 16 + 0x40 + info->x2 * 8 + info->x6 * 4 + info->xA * 0x50 + info->xE * 4;
    b = Pool_Alloc_3_001288C0(*a0, size);
    Pool_ArrayAppend_0_001535B0(a0 + 1, b);
    memset(b->obj, 0, size);
    b->obj->x10 = a1;
    b->obj->x14 = info->x0;
    b->obj->x16 = info->x2;
    b->obj->x18 = info->x6;
    b->obj->x1C = info->xA;
    b->obj->x1E = info->xE;
    b->obj->x1A = info->x8;
    b->obj->x22 = 0;
    b->obj->x2C = 0;
    b->obj->x3C.w = 0;
    b->obj->x3C.f.a = info->xC_3;
    b->obj->x3C.f.b6 = 0;
    if (info->xC_3 == 1 && info->xD_0 == 0 && info->xD_2 == 0) {
        b->obj->x3C.f.b6 = 1;
    }
    b->obj->x3C.f.b3 = 0;
    b->obj->x3C.f.b5 = 1;
    Mdl_Relocate_1_00170380(hdr, b->obj);
    }
    return b;
}
#undef Mdl_Relocate_1_00170380

/* Mdl_Free_0_00170250 */
void Mdl_Free_0_00170250(s32 *a0, H_Mdl_Free_0_00170250 **a1) {
    H_Mdl_Free_0_00170250 *h;
    s8 **q;
    El *p;
    s32 i;
    h = *a1;
    q = h->x10;
    p = (El *)(*q + h->x24);
    h->x22--;
    if ((*a1)->x22 <= 0) {
        if ((*a1)->x2C && (*a1)->x3C.f.b3) {
            Pool_Free_2_00128580(*a0, (*a1)->x2C);
        }
        for (i = 0; i < (*a1)->x1A; i++, p++) {
            if (p->x38) Tex_Release_1_00177570(p->x38);
            if (p->x3C) Tex_Release_1_00177570(p->x3C);
        }
        Pool_FreeChunk_0_001531A0(a0 + 1, a1);
        if (!(*a1)->x3C.f.b5) {
            Pool_Free_2_00128580(*a0, q);
        }
    }
}

/* Mdl_Relocate_1_00170380 */
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

s32 Mdl_Relocate_1_00170380(Ch *c, Obj_Mdl_Relocate_1_00170380 *o) {
    u16 *q;
    u32 j;
    Ch *sub;
    u32 i;
    H_Mdl_Relocate_1_00170380 *h;
    u8 *d;
    u16 *p;
    u32 k;
    H_Mdl_Relocate_1_00170380 *h2;
    u8 *d2;

    switch (c->x0) {
    case 0x4D415453:
        h = &c->h;
        sub = (Ch *)((u8 *)c + c->off);
        sceVu0CopyVector(&o->v, (Vec *)(DATA(h) + 0x10));
        D_0042D8B4[0] = *o->x10;
        D_0042D89C[0] = (E16 *)((s32)o + 0x40);
        D_0042D880[0] = 0;
        D_0042D884[0] = 0;
        D_0042D888[0] = 0;
        D_0042D88C[0] = 0;
        D_0042D890[0] = 0;
        D_0042D894[0] = 0;
        D_0042D898[0] = 0;
        D_0042D8A0[0] = (E8 *)(D_0042D89C[0] + o->x14);
        D_0042D8A4[0] = (s32 *)(D_0042D8A0[0] + o->x16);
        D_0042D8A8[0] = (E50 *)(D_0042D8A4[0] + o->x18);
        D_0042D8AC[0] = (s32 *)(D_0042D8A8[0] + o->x1C);
        d = (u8 *)(D_0042D8AC[0] + o->x1E);
        D_0042D8B8[0] = 0;
        D_0042D8B0[0] = (E8 *)d;
        for (i = 0; i < c->xE; i++) {
            Mdl_Relocate_1_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x4C54414D:
        h = &c->h;
        o->x24 = (s32)DATA(h) - D_0042D8B4[0];
        break;
    case 0x4C444F4D:
        sub = (Ch *)((u8 *)c + c->off);
        D_0042D8B8[0] = 1;
        for (i = 0; i < c->xE; i++) {
            Mdl_Relocate_1_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        D_0042D8B8[0] = 0;
        break;
    case 0x58524D57:
        h = &c->h;
        d = DATA(h);
        if (D_0042D8B8[0]) {
            (&D_0042D89C[0][D_0042D880[0]])->x8 = (s32)d - D_0042D8B4[0];
        }
        break;
    case 0x58524D4C:
        h = &c->h;
        d = DATA(h);
        if (D_0042D8B8[0]) {
            (&D_0042D89C[0][D_0042D880[0]])->xC = (s32)d - D_0042D8B4[0];
        }
        break;
    case 0x4D4F4547:
        h = &c->h;
        h2 = (H_Mdl_Relocate_1_00170380 *)((u8 *)h + h->a);
        d = DATA(h);
        d2 = DATA(h2);
        (*(E16 **)D_0042D89C)[D_0042D880[0]].x0 = (s32)d - D_0042D8B4[0];
        (&D_0042D89C[0][D_0042D880[0]])->x4 = (s32)d2 - D_0042D8B4[0];
        D_0042D880[0]++;
        break;
    case 0x4D494E41:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            Mdl_Relocate_1_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x51455341:
        h = &c->h;
        sub = (Ch *)((u8 *)c + c->off);
        (*(E8 **)D_0042D8A0)[D_0042D884[0]].x0 = (s32)DATA(h) - D_0042D8B4[0];
        (&D_0042D8A0[0][D_0042D884[0]])->x4 = D_0042D888[0];
        for (i = 0; i < c->xE; i++) {
            Mdl_Relocate_1_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        D_0042D884[0]++;
        break;
    case 0x5F4B5254:
        h = &c->h;
        (*(s32 **)D_0042D8A4)[D_0042D888[0]] = (s32)DATA(h) - D_0042D8B4[0];
        D_0042D888[0]++;
        break;
    case 0x4C425441:
        h = &c->h;
        o->x28 = (s32)DATA(h) - D_0042D8B4[0];
        break;
    case 0x494D5453:
    case 0x49435453:
    case 0x494F5453:
    case 0x49535453:
    case 0x4D495453:
    case 0x4D455453:
    case 0x4D584653:
        break;
    case 0x45545453:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            if (sub->xC) {
                Mdl_Relocate_1_00170380(sub, o);
            }
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x6154584D:
        h = &c->h;
        (*(E8 **)D_0042D8B0)[D_0042D898[0]].x0 = (s32)DATA(h) - D_0042D8B4[0];
        (&D_0042D8B0[0][D_0042D898[0]])->x4 = (u32)c->h.c8 >> 16;
        (&D_0042D8B0[0][D_0042D898[0]])->x6 = c->h.c8 & 0xFFF;
        D_0042D898[0]++;
        break;
    case 0x43494454:
        o->x3C.f.b4 = 1;
        break;
    case 0x4D544948:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            Mdl_Relocate_1_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x47544948:
        h = &c->h;
        d = DATA(h);
        h2 = (H_Mdl_Relocate_1_00170380 *)((u8 *)h + h->a);
        d2 = DATA(h2);
        (*(E50 **)D_0042D8A8)[D_0042D88C[0]].x0 = (s32)d - D_0042D8B4[0];
        (&D_0042D8A8[0][D_0042D88C[0]])->x4 = (s32)d2 - D_0042D8B4[0];
        p = (u16 *)d;
        for (k = 0; k < 8; k++) {
            if (*p == 0) {
                (*(E50 **)D_0042D8A8)[D_0042D88C[0]].x10[k] = 0;
            } else {
                (*(E50 **)D_0042D8A8)[D_0042D88C[0]].x10[k] = (s32)(d + 0xA0) - D_0042D8B4[0] + p[8] * 32;
            }
            p++;
        }
        D_0042D88C[0]++;
        break;
    case 0x58424248:
        h = &c->h;
        d = DATA(h);
        (&D_0042D8A8[0][D_0042D890[0]])->x8 = (s32)d - D_0042D8B4[0];
        q = (u16 *)d;
        for (j = 0; j < 8; j++) {
            if (*q == 0) {
                (*(E50 **)D_0042D8A8)[D_0042D890[0]].x30[j] = 0;
            } else {
                (*(E50 **)D_0042D8A8)[D_0042D890[0]].x30[j] = (s32)(d + 0x120) - D_0042D8B4[0] + q[8] * 32;
            }
            q++;
        }
        D_0042D890[0]++;
        break;
    case 0x4547414B:
    case 0x4D47414B:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            Mdl_Relocate_1_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x4747414B:
        h = &c->h;
        (*(s32 **)D_0042D8AC)[D_0042D894[0]] = (s32)DATA(h) - D_0042D8B4[0];
        D_0042D894[0]++;
        break;
    }
    return 1;
}

/* Mdl_ReleaseTexAnims_0_00170E90 */
void Mdl_ReleaseTexAnims_0_00170E90(O **arg0) {
    O *o; s32 i; E_Mdl_ReleaseTexAnims_0_00170E90 *e; o = *arg0; i = 0; e = (E_Mdl_ReleaseTexAnims_0_00170E90 *)((u8 *)(s32)((u8 *)((s32)((u8 *)((s32)((u8 *)((s32)((u8 *)o + 0x40) + o->n14 * 16) + o->n16 * 8)) + o->n18 * 4)) + o->n1C * 0x50) + o->n1E * 4);
    for (; i < o->n20; i++) {
        TexAnim_Release_0_001758B0(e->x4, o->x10);
        e++;
    }
}

/* Mdl_RegisterTexAnims_0_00170F40 */
 typedef struct { u8 b[8]; } B8; typedef struct { u8 b[4]; } B4; typedef struct { u8 b[0x50]; } B50;

void Mdl_RegisterTexAnims_0_00170F40(Hdr_Mdl_RegisterTexAnims_0_00170F40 **arg0) {
    Hdr_Mdl_RegisterTexAnims_0_00170F40 *h;
    s32 base;
    s32 i;
    Ent *e;
    s8 *d;
    i = 0;
    h = *arg0;
    base = *h->base;
    d = (s8*)(h + 1); d = (s8*)((B16*)d + h->n14); e = (Ent*)(d + h->n16 * 8 + h->n18 * 4 + h->n1C * 0x50 + h->n1E * 4);
    for (; i < h->count; i++, e++) {
        if (((u64)((s64)h->flags << 0x3B) >> 0x3F) != 0) {
            TexAnim_Register_0_001759D0(e->w, e->h, base + e->a, h->base);
        } else {
            TexAnim_Register_0_001759D0(e->w, e->h, base + e->a, 0);
        }
    }
}

/* Mdl_GetSectionPtrs_1_00171050 */
void Mdl_GetSectionPtrs_1_00171050(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg1, u8 **, 0) = (u8 *) (arg0 + 0x40);
    M2C_FIELD(arg1, u8 **, 4) = (u8 *) (M2C_FIELD(arg1, u8 **, 0) + (M2C_FIELD(arg0, u16 *, 0x14) * 0x10));
    M2C_FIELD(arg1, u8 **, 8) = (u8 *) (M2C_FIELD(arg1, u8 **, 4) + (M2C_FIELD(arg0, u16 *, 0x16) * 8));
    M2C_FIELD(arg1, u8 **, 0xC) = (u8 *) (M2C_FIELD(arg1, u8 **, 8) + (M2C_FIELD(arg0, u16 *, 0x18) * 4));
    M2C_FIELD(arg1, u8 **, 0x10) = (u8 *) (M2C_FIELD(arg1, u8 **, 0xC) + (M2C_FIELD(arg0, u16 *, 0x1C) * 0x50));
    M2C_FIELD(arg1, u8 **, 0x14) = (u8 *) (M2C_FIELD(arg1, u8 **, 0x10) + (M2C_FIELD(arg0, u16 *, 0x1E) * 4));
}

/* Mdl_SetBoneRotation_0_001710D0 */
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Mdl_SetBoneRotation_0_001710D0
void sceVu0CopyMatrix__as_Mdl_SetBoneRotation_0_001710D0(s8 *, s8 *);

void Mdl_SetBoneRotation_0_001710D0(Obj_Mdl_SetBoneRotation_0_001710D0 *obj, s16 a1, f32 a, f32 b, f32 c) {
    f32 v;
    s8 *r;
    s8 *p;
    s8 *q;
    s32 i;
    s32 stride;

    v = -1.0f * (obj->x1C + b);
    if (v < 0.0f) {
        p = obj->data;
        Mdl_Animate_2_00171BB0(p + D_00201F2C * (obj->n * 0x140 + 0x200), obj, obj->x4, obj->n, obj->x8, obj->xC);
        stride = obj->n * 0x140 + 0x200;
        q = p + stride;
        r = p + D_00201F2C * stride;
        for (i = 0; i < obj->n + 1; i++) {
            sceVu0CopyMatrix(p + 0x180, r + 0x140);
            sceVu0CopyMatrix(q + 0x180, r + 0x140);
            r += 0x140;
            p += 0x140;
            q += 0x140;
        }
    }
    obj->xC = v;
    obj->x10 = v;
    obj->x20 = obj->xC;
    *(s32 *)&obj->x8 = a1;
    obj->x14 = a;
    obj->x18 = b;
    obj->x1C = c;
    obj->st = 0;
}
#undef sceVu0CopyMatrix

/* Mdl_Nop_2_00171260 */
void Mdl_Nop_2_00171260(void) {

}

/* Mdl_UpdateBoneMatrices_0_00171270 */
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Mdl_UpdateBoneMatrices_0_00171270
void sceVu0CopyMatrix__as_Mdl_UpdateBoneMatrices_0_00171270(E_Mdl_UpdateBoneMatrices_0_00171270 *, Mtx *);

void Mdl_UpdateBoneMatrices_0_00171270(H_Mdl_UpdateBoneMatrices_0_00171270 *h, Mtx *a1, s32 a2) {
    E_Mdl_UpdateBoneMatrices_0_00171270 *b;
    s32 i;
    E_Mdl_UpdateBoneMatrices_0_00171270 *e;
    s32 k;
    F f;
    F par;

    if (h == 0) return;
    b = (E_Mdl_UpdateBoneMatrices_0_00171270 *)((s32)((s32)h + 0x40 + a2 * (h->x6 * 0x140 + 0x200)) + 0xC0);
    k = (u8)h->x24b;
    if (k) h->x24b = k + 0xFF;
    sceVu0CopyMatrix(b, a1);
    sceVu0AddVector(&b->m.m[3], &b->m.m[3], &h->x30);
    b->x134 = Mtx_MaxAxisScale_2_00171550(b);
    f.w = b->x138.w;
    f.f.b5 = 0;
    f.f.b2 = 0;
    if (f.f.b4) f.f.b5 = 1;
    if (f.f.b1) f.f.b2 = 1;
    b->x138.w = f.w;
    for (i = 1; i < h->x6 + 1; i++) {
        e = &b[i];
        f.w = e->x138.w;
        par.w = b[e->x131].x138.w;
        f.f.b5 = 0;
        f.f.b2 = 0;
        if (f.f.b4) f.f.b5 = 1;
        if (f.f.b1) f.f.b2 = 1;
        if (!f.f.b6) {
            sceVu0MulMatrix(e, &b[e->x131], &e->x80);
            if (par.f.b5) f.f.b5 = 1;
            if (par.f.b2) f.f.b2 = 1;
            e->x138.w = f.w;
        } else {
            sceVu0MulMatrix(e, &e->x40, &e->x80);
            e->x138.w = f.w;
        }
        e->x134 = Mtx_MaxAxisScale_2_00171550(e);
    }
}
#undef sceVu0CopyMatrix

/* Mdl_UpdateBoneMatricesCur_0_00171540 */
#define Mdl_UpdateBoneMatrices_0_00171270 Mdl_UpdateBoneMatrices_0_00171270__as_Mdl_UpdateBoneMatricesCur_0_00171540
int Mdl_UpdateBoneMatrices_0_00171270__as_Mdl_UpdateBoneMatricesCur_0_00171540();

void Mdl_UpdateBoneMatricesCur_0_00171540(s32 arg0, s32 arg1) {
    Mdl_UpdateBoneMatrices_0_00171270((void *) arg0, arg1, D_00201F2C);
}
#undef Mdl_UpdateBoneMatrices_0_00171270

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_0042D89C__grp: D_0042D89C@0x0 */
u8 D_0042D89C__grp[0x4] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_0042D8A0__grp: D_0042D8A0@0x0 */
u8 D_0042D8A0__grp[0x4] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_0042D8A4__grp: D_0042D8A4@0x0 */
u8 D_0042D8A4__grp[0x4] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_0042D8A8__grp: D_0042D8A8@0x0 */
u8 D_0042D8A8__grp[0x4] __attribute__((aligned(8)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_0042D8AC__grp: D_0042D8AC@0x0 */
u8 D_0042D8AC__grp[0x4] __attribute__((aligned(4)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/texture_bss.c): D_0042D8B0__grp: D_0042D8B0@0x0 */
u8 D_0042D8B0__grp[0x4] __attribute__((aligned(16)));
#endif
