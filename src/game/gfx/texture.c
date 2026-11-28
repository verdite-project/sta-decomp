#include "m2c.h"
#include "common.h"
#include "include_asm.h"
#include "game/gfx.h"
typedef struct {
    u64 TBP0:14; u64 TBW:6; u64 PSM:6; u64 TW:4; u64 TH:4; u64 TCC:1; u64 TFX:2;
    u64 CBP:14; u64 CPSM:4; u64 CSM:1; u64 CSA:5; u64 CLD:3;
} Tex0;
typedef struct {
    u64 LCM:1; u64 p1:1; u64 MXL:3; u64 MMAG:1; u64 MMIN:3; u64 MTBA:1; u64 p2:9; u64 L:2; u64 p3:11;
    u64 K:12; u64 p4:20;
} Tex1_Tex_Upload_0_00175CD0;
typedef struct {
    u64 SBP:14; u64 p0:2; u64 SBW:6; u64 p1:2; u64 SPSM:6; u64 p2:2;
    u64 DBP:14; u64 p3:2; u64 DBW:6; u64 p4:2; u64 DPSM:6; u64 p5:2;
} Bbuf;
typedef struct { s32 x0; s32 x4; } Img;
typedef struct { u8 pad0[8]; s32 off[7]; s32 x24; Bbuf bb; Bbuf pb; u8 pad38[8]; } M;
typedef struct { u8 pad0[0x10]; M m; } Ent;
typedef struct {
    Tex0 t0;
    Tex1_Tex_Upload_0_00175CD0 t1;
    Img *x10;
    u8 pad14[0xC];
    u16 h20;
    s16 h22;
    s32 x24;
    u8 x28;
    u8 pad29;
    u16 h2A;
    u16 h2C;
    u16 h2E;
} T;
typedef struct { T *t; s32 x4; s32 x8; } A;
typedef struct { s16 prev, next, fnext, fprev; u16 off, size; void *owner; } Blk_Tex_Upload_0_00175CD0;
typedef union { u128 q; struct { u32 a; u32 b; u64 c; } s; } Tag;
typedef struct N { s32 x0; struct N *next; } N;
typedef struct { N *head; s32 x4; } B_Tex_UploadQueued_1_00176350;
typedef struct E { s32 a; struct E *next; u128 *pkt; s32 pad; } E;
typedef struct { E *head; E *tail; } B_Tex_FlushLayer_0_00176440;
typedef union { u128 q; u64 d[2]; } Q;
typedef struct { u64 pad:14; u64 lv:6; u64 ty:6; u64 rest:38; } A0;
typedef struct { u16 lo:4; u16 ty:6; u16 hi:6; } C;
typedef struct { u8 lv:6; u8 hi:2; } B_Tex_SetTex0_1_00176550;
typedef struct {
    u64 LCM:1; u64 pad01:1; u64 MXL:3; u64 MMAG:1; u64 MMIN:3; u64 MTBA:1; u64 pad10:9; u64 L:2; u64 pad21:11; u64 K:12; u64 pad44:20;
} Tex1_Tex_CalcVramSize_0_00176710;
typedef struct { Tex0 t0; Tex1_Tex_CalcVramSize_0_00176710 t1; } TexRegs;
typedef struct { u32 a10; u32 a14; u32 a18; u16 a1C; u16 a1E; u16 a20; u16 a22; s32 a24; } TexInfo;
typedef struct { u8 pad[0x22]; s16 x22; } Owner_Vram_Reset_0_001769C0;
typedef struct { s16 prev, next, fnext, fprev; u16 off, size; Owner_Vram_Reset_0_001769C0 *owner; } Blk_Vram_Reset_0_001769C0;
typedef struct { u64 a; u64 b; char p10[0x18]; u8 kind; } Obj;
typedef struct { u8 pad[0x28]; u8 type; } Owner_Vram_AllocForTex_0_00176BF0;
typedef struct {
    s16 prev, next, fnext, fprev;
    u16 off, size;
    Owner_Vram_AllocForTex_0_00176BF0 *owner;
} Blk_Vram_AllocForTex_0_00176BF0;
typedef struct { s16 n0; s16 p2; s16 n4; s16 p6; s32 pad8; s32 used; } L;
typedef struct { u8 pad[0x4C]; s32 x4C; } Q50;
typedef struct { u8 pad[0x10]; s8 **x10; u8 pad14[8]; s16 x1C; s16 x1E; u16 x20; s16 x22; s32 x24; u8 b0:3; u8 pad29[7]; } E30;
typedef struct {
    s32 x0;
    s32 x4;
    s16 x8, xA, xC, xE;
} G;
extern s16 D_00222A1A[];
extern s32 D_004830E0[];
extern s32 D_004830E4[];
extern s32 D_004830E8[];
extern s32 D_004830EC[];
extern volatile s16 D_004830DC[];
extern s16 D_004830DE[];
extern Blk_Tex_Upload_0_00175CD0 D_0047F0C0[];
#ifndef NONMATCHING
extern u8 D_00438A30[];
#else
/* data twins (src/game/data/texture_bss.c): D_00438A30 */
static u8 D_00438A30[0x40];
#endif
#ifndef NONMATCHING
extern B_Tex_UploadQueued_1_00176350 D_00438A70[];
#else
/* data twins (src/game/data/texture_bss.c): D_00438A70 */
static B_Tex_UploadQueued_1_00176350 D_00438A70[0x6610 / sizeof(B_Tex_UploadQueued_1_00176350)];
#endif
#ifndef NONMATCHING
extern s32 D_0020200C;
#else
/* data twins (src/game/data/sbss.c): D_0020200C */
static s32 D_0020200C;
#endif
#ifndef NONMATCHING
extern u64 D_00202010;
#else
/* data twins (src/game/data/sbss.c): D_00202010 */
static u64 D_00202010;
#endif
extern E D_0043F080[];
extern s32 D_00438A10[];
#ifndef NONMATCHING
extern s32 D_00438A14[];
#else
/* data twins (src/game/data/texture_bss.c): D_00438A14 */
static s32 D_00438A14[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_00438A18[];
#else
/* data twins (src/game/data/texture_bss.c): D_00438A18 */
static s32 D_00438A18[0x1];
#endif
extern volatile u16 D_00438A1C[];
extern s32 D_004830F0[];
extern s32 D_004830F4[];
extern volatile s16 D_004830D0[];
extern s16 D_004830D2[];
extern s16 D_004830D4[];
extern s16 D_004830D6[];
extern s16 D_004830D8[];
extern B_Tex_FlushLayer_0_00176440 D_00438A70__as_Tex_FlushLayer_0_00176440[];
extern TexInfo D_00438A10__as_Tex_CalcVramSize_0_00176710;
extern Blk_Vram_Reset_0_001769C0 D_0047F0C0__as_Vram_Reset_0_001769C0[];
extern s16 D_004830DC__as_Vram_Reset_0_001769C0[];
extern s64 D_00202010__as_Tex_BeginFrame_0_00176A60;
extern s32 D_00438A30__as_Tex_BeginFrame_0_00176A60[];
extern s32 D_00438A70__as_Tex_BeginFrame_0_00176A60[];
extern s32 D_0043F080__as_Tex_BeginFrame_0_00176A60[];
extern Blk_Vram_AllocForTex_0_00176BF0 D_0047F0C0__as_Vram_AllocForTex_0_00176BF0[];
extern s16 D_004830DC__as_Vram_AllocForTex_0_00176BF0[];
extern s16 D_004830DA[];
extern G D_004830C0;
extern E30 D_004800C0[];
void Tex_Upload_0_00175CD0(A *a0);
void Tex_UploadQueued_1_00176350(void);
void Tex_FlushLayer_0_00176440(u32 a);
void Tex_SetTex0_1_00176550(s8 *arg0, s32 arg1, s8 *arg2);
void Tex_CalcVramSize_0_00176710(Tex0 t0, Tex1_Tex_CalcVramSize_0_00176710 t1);
void Tex_UploadQueuedWrap_0_00176A40(s32 arg0, s32 arg1);
void Tex_Bind_1_00176B10(Obj *o);
u16 Vram_AllocForTex_0_00176BF0(Owner_Vram_AllocForTex_0_00176BF0 *arg0, u16 arg1);
void Vram_FreeBlock_0_00177380(s16 i);
s16 Tex_Release_1_00177570(E30 *p);
void GsPkt_AddRegData_1_001541F0(s32, Bbuf);
u128* GsPkt_AllocDirect_1_001543A0(s32);
void GsPkt_PushTag_1_00154310(s32);
u128* GsPkt_Alloc_3_00154A80(s32);
s32 Vram_AllocBlock_1_00176FB0(s32);
void FlushCache(s32);
void memset(s32 *, s32, s32);
void GsPkt_SetReg_3_001543E0(s32 a, u64 b);
u16 Vram_AllocForTex_0_00176BF0__as_Tex_Upload_0_00175CD0(T *, u16);
void Tex_Upload_0_00175CD0__as_Tex_UploadQueued_1_00176350(N *);
void Tex_CalcVramSize_0_00176710__as_Tex_SetTex0_1_00176550(u64, u64);
s32 Tex_UploadQueued_1_00176350__as_Tex_UploadQueuedWrap_0_00176A40();
s32 GsPkt_CloseChain_1_001549D0__as_Tex_FlushAll_1_00176AE0();
s32 Tex_FlushLayer_0_00176440__as_Tex_FlushAll_1_00176AE0();
void Tex_FlushLayer_0_00176440__as_Tex_Bind_1_00176B10(void);
s32 GsPkt_CloseChain_1_001549D0__as_Tex_BindFlush_1_00176BC0();
s32 Tex_Bind_1_00176B10__as_Tex_BindFlush_1_00176BC0();
s32 Vram_AllocBlock_1_00176FB0__as_Vram_AllocForTex_0_00176BF0(s16);

/* Tex_Upload_0_00175CD0 */
/* Tex_Upload_0_00175CD0 */
#define D_004830DC D_004830DC[0]
#define D_004830DE D_004830DE[0]

void Tex_Upload_0_00175CD0(A *a0) {
    s32 h;
    s32 d;
    T *t;
    s32 base;
    M *m;
    s32 dbp;
    u32 dbw;
    s32 *o;
    u32 off;
    s16 n;
    s16 f;
    u16 v;
    Bbuf bb1;
    Bbuf bb2;
    Bbuf bb3;
    Tag tag;
    Tag *p;

    t = a0->t;
    if (t == NULL) return;
    if (t->t1.MXL != 0 && D_00222A1A[0] != -1) {
        t->t1.LCM = 1;
        t->t1.K = *(volatile s16 *)D_00222A1A << 4;
    } else {
        t->t1.LCM = 0;
        t->t1.K = 0;
    }
    if ((t->x28 & 7) == 1) {
        if (t->h22 != -1) {
            D_004830E8[0]++;
            D_004830EC[0]++;
            GsPkt_BeginADDirect_1_001542D0();
            GsPkt_AddRegData_1_001541F0(0x14, *(Bbuf *)&t->t1);
            GsPkt_AddRegData_1_001541F0(6, *(Bbuf *)&t->t0);
            GsPkt_EndADDirect_1_00154230();
            n = t->h22;
            if (n != D_004830DC) {
                D_004830DE--;
                if (n == D_0047F0C0[n].fnext) {
                    D_004830DC = -1;
                } else {
                    D_0047F0C0[D_0047F0C0[n].fnext].fprev = D_0047F0C0[n].fprev;
                    D_0047F0C0[D_0047F0C0[n].fprev].fnext = D_0047F0C0[n].fnext;
                    if (D_004830DC == n) D_004830DC = D_0047F0C0[n].fnext;
                }
                D_004830DE++;
                f = D_004830DC;
                if (f == -1) {
                    D_004830DC = n;
                    D_0047F0C0[n].fnext = n;
                    D_0047F0C0[n].fprev = n;
                } else {
                    D_0047F0C0[n].fnext = f;
                    D_0047F0C0[n].fprev = D_0047F0C0[f].fprev;
                    D_0047F0C0[D_0047F0C0[n].fnext].fprev = n;
                    D_0047F0C0[D_0047F0C0[n].fprev].fnext = n;
                    D_004830DC = n;
                }
            }
        } else {
            v = Vram_AllocForTex_0_00176BF0(t, (u32)(t->h2A + t->h2E + 15) >> 4);
            t->h22 = v;
            off = D_0047F0C0[v].off;
            base = t->x10->x0 + t->x24;
            m = (M *)(t->h20 * 0x50 + (t->x10->x0 + t->x24) + 0x10);
            d = t->x10->x4 - t->x10->x0;
            h = (t->h2C + 15) >> 4;
            dbp = off + ((t->h2E + 15) >> 4);
            bb1 = m->bb;
            GsPkt_BeginADDirect_1_001542D0();
            bb1.DBP = dbp;
            dbw = bb1.DBW;
            GsPkt_AddRegData_1_001541F0(0x50, bb1);
            GsPkt_EndADDirect_1_00154230();
            p = (Tag *)GsPkt_AllocDirect_1_001543A0(1);
            tag.s.a = 0x50000000;
            tag.s.b = d + (base + m->off[0]);
            tag.s.c = 0;
            *p = tag;
            GsPkt_Nop_2_00154390();
            for (o = (s32 *)m; o[3] != 0; o++) {
                dbp += h;
                h >>= 2;
                if (h == 0) h = 1;
                dbw >>= 1;
                if (dbw == 0) dbw = 1;
                bb2 = m->bb;
                GsPkt_BeginADDirect_1_001542D0();
                bb2.DBP = dbp;
                bb2.DBW = dbw;
                GsPkt_AddRegData_1_001541F0(0x50, bb2);
                GsPkt_EndADDirect_1_00154230();
                p = (Tag *)GsPkt_AllocDirect_1_001543A0(1);
                tag.s.a = 0x50000000;
                tag.s.b = d + (base + o[3]);
                tag.s.c = 0;
                *p = tag;
                GsPkt_Nop_2_00154390();
            }
            if (m->x24 != 0) {
                bb3 = m->pb;
                GsPkt_BeginADDirect_1_001542D0();
                bb3.DBP = off;
                GsPkt_AddRegData_1_001541F0(0x50, bb3);
                GsPkt_EndADDirect_1_00154230();
                p = (Tag *)GsPkt_AllocDirect_1_001543A0(1);
                tag.s.a = 0x50000000;
                tag.s.b = d + (base + m->x24);
                tag.s.c = 0;
                *p = tag;
                GsPkt_Nop_2_00154390();
            }
            GsPkt_BeginADDirect_1_001542D0();
            GsPkt_AddRegData_1_001541F0(0x14, *(Bbuf *)&t->t1);
            t->t0.TBP0 = off + ((t->h2E + 15) >> 4);
            t->t0.CBP = off;
            if (m->x24 != 0) {
                t->t0.CLD = 2;
                GsPkt_AddRegData_1_001541F0(6, *(Bbuf *)&t->t0);
                t->t0.CLD = 4;
            } else {
                t->t0.CLD = 0;
                GsPkt_AddRegData_1_001541F0(6, *(Bbuf *)&t->t0);
            }
            GsPkt_EndADDirect_1_00154230();
            D_004830E8[0]++;
            D_004830EC[0]++;
            D_004830E0[0]++;
            D_004830E4[0]++;
        }
    }
    GsPkt_PushTag_1_00154310(a0->x8);
}
#undef D_004830DC
#undef D_004830DE

/* Tex_UploadQueued_1_00176350 */

void Tex_UploadQueued_1_00176350(void) {
    u32 i;
    u32 j;
    N *p;

    GsPkt_CloseChain_1_001549D0();
    for (i = 0; i < 0x33; i++) {
        if (D_00438A30[i] != 0) {
            for (j = i * 0x40; j < i * 0x40 + 0x40; j++) {
                p = D_00438A70[j].head;
                while (p != NULL) {
                    Tex_Upload_0_00175CD0(p);
                    p = p->next;
                }
            }
        }
    }
}

/* Tex_FlushLayer_0_00176440 */

void Tex_FlushLayer_0_00176440(u32 a) {
    u32 v = GsPkt_GetLayerCount_0_00155A90();
    u64 key = (u64)a + ((u64)v << 32);
    E *e;
    E **t;
    B_Tex_FlushLayer_0_00176440 *b;
    Q *p;
    Q q;

    if (D_00202010 != key) {
        D_00202010 = key;
        b = &D_00438A70[v];
        t = &b->tail;
        e = &D_0043F080[D_0020200C];
        D_00438A30[v >> 6] = 1;
        GsPkt_CloseChain_1_001549D0();
        p = (Q *)GsPkt_Alloc_3_00154A80(1);
        q.q = 0;
        q.d[0] = 0x10000000;
        *p = q;
        e->a = a;
        e->pkt = (u128 *)p;
        if (*t) (*t)->next = e;
        *t = e;
        if (b->head == 0) b->head = e;
        D_0020200C++;
    }
}

/* Tex_SetTex0_1_00176550 */
#define Tex_CalcVramSize_0_00176710 Tex_CalcVramSize_0_00176710__as_Tex_SetTex0_1_00176550

void Tex_SetTex0_1_00176550(s8 *arg0, s32 arg1, s8 *arg2) {
    M2C_FIELD(arg0, u64 *, 0) = M2C_FIELD(arg2, u64 *, 0x40);
    M2C_FIELD(arg0, u64 *, 8) = M2C_FIELD(arg2, u64 *, 0x48);
    Tex_CalcVramSize_0_00176710(M2C_FIELD(arg0, u64 *, 0), M2C_FIELD(arg0, u64 *, 8));
    if (M2C_FIELD(arg2, s32 *, 0x24) == 0) {
        D_00438A18[0] = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x2A) = D_00438A10[0];
    M2C_FIELD(arg0, s16 *, 0x2C) = D_00438A14[0];
    M2C_FIELD(arg0, s16 *, 0x2E) = D_00438A18[0];
    M2C_FIELD(arg2, s8 **, 0x38) = arg0;
    ((B_Tex_SetTex0_1_00176550 *)(arg2 + 0x2E))->lv = D_00438A1C[0] >> 6;
    if (((B_Tex_SetTex0_1_00176550 *)(arg2 + 0x2E))->lv <= 0) {
        ((B_Tex_SetTex0_1_00176550 *)(arg2 + 0x2E))->lv = 1;
    }
    if (((A0 *)arg0)->ty == 0x13 || ((A0 *)arg0)->ty == 0x14) {
        if (((B_Tex_SetTex0_1_00176550 *)(arg2 + 0x2E))->lv < 2) {
            ((B_Tex_SetTex0_1_00176550 *)(arg2 + 0x2E))->lv = 2;
        }
    }
    ((A0 *)arg0)->lv = D_00438A1C[0] >> 6;
    if (((A0 *)arg0)->lv == 0) {
        ((A0 *)arg0)->lv = 1;
    }
    if (((C *)(arg0 + 2))->ty == 0x13 || ((C *)(arg0 + 2))->ty == 0x14) {
        if (((A0 *)arg0)->lv < 2) {
            ((A0 *)arg0)->lv = 2;
        }
    }
}
#undef Tex_CalcVramSize_0_00176710

/* Tex_CalcVramSize_0_00176710 */
#define D_00438A10 D_00438A10__as_Tex_CalcVramSize_0_00176710

void Tex_CalcVramSize_0_00176710(Tex0 t0, Tex1_Tex_CalcVramSize_0_00176710 t1) {
    u32 s;
    u32 n;

    D_00438A10.a1E = t0.TH;
    D_00438A10.a1E = 1 << D_00438A10.a1E;
    D_00438A10.a1C = 1 << t0.TW;
    switch (t0.PSM) {
    case 0:
    case 0x30:
        D_00438A10.a24 = 32;
        break;
    case 1:
    case 0x31:
        D_00438A10.a24 = 24;
        break;
    case 2:
    case 0xA:
    case 0x32:
    case 0x3A:
        D_00438A10.a24 = 16;
        break;
    case 0x13:
        D_00438A10.a24 = 8;
        break;
    case 0x1B:
    case 0x14:
        D_00438A10.a24 = 4;
        break;
    case 0x24:
    case 0x2C:
        break;
    }
    D_00438A10.a14 = (D_00438A10.a24 * (D_00438A10.a1C * D_00438A10.a1E) / 8 + 15) / 16;
    s = D_00438A10.a14;
    D_00438A10.a10 = s;
    if (t1.MXL != 0) {
        n = t1.MXL;
        while (n--) {
            s >>= 2;
            D_00438A10.a10 += s;
        }
    }
    if (D_00438A10.a24 == 4) {
        if (t0.CPSM == 0) {
            D_00438A10.a18 = 4;
        } else {
            D_00438A10.a18 = 2;
        }
        D_00438A10.a20 = 8;
        D_00438A10.a22 = 2;
    } else if (D_00438A10.a24 == 8) {
        if (t0.CPSM == 0) {
            D_00438A10.a18 = 0x40;
        } else {
            D_00438A10.a18 = 0x20;
        }
        D_00438A10.a20 = 16;
        D_00438A10.a22 = 16;
    } else {
        D_00438A10.a18 = 0;
        D_00438A10.a20 = 0;
        D_00438A10.a22 = 0;
    }
}
#undef D_00438A10

/* Vram_Reset_0_001769C0 */
#define D_0047F0C0 D_0047F0C0__as_Vram_Reset_0_001769C0
void Vram_Reset_0_001769C0(void) {
    s32 b;
    D_004830E8[0] = 0;
    D_004830E0[0] = 0;
    b = D_004830DC[0];
    if (b != -1) {
        do {
            D_0047F0C0[b].owner->x22 = -1;
            Vram_AllocBlock_1_00176FB0(b);
        } while ((b = D_004830DC[0]) != -1);
    }
}
#undef D_0047F0C0

/* Tex_UploadQueuedWrap_0_00176A40 */
#define Tex_UploadQueued_1_00176350 Tex_UploadQueued_1_00176350__as_Tex_UploadQueuedWrap_0_00176A40

void Tex_UploadQueuedWrap_0_00176A40(s32 arg0, s32 arg1) {
    (*D_004830F0) = 0;
    (*D_004830F4) = 0;
    Tex_UploadQueued_1_00176350(arg0, arg1);
}
#undef Tex_UploadQueued_1_00176350

/* Tex_BeginFrame_0_00176A60 */

void Tex_BeginFrame_0_00176A60(void) {
    (*D_004830F4) = 0;
    (*D_004830F0) = 1;
    FlushCache(0);
    Dma_SprInit_1_00178D20();
    Dma_SprClear_1_00178C00((s32) D_00438A70, 0x6610U);
    Dma_SprClear_1_00178C00((s32) D_0043F080, 0x40000U);
    D_0020200C = 0;
    D_00202010 = 0;
    memset(D_00438A30, 0, 0x33);
}

/* Tex_FlushAll_1_00176AE0 */
void Tex_FlushAll_1_00176AE0(void) {
    Tex_FlushLayer_0_00176440(0);
    GsPkt_CloseChain_1_001549D0();
}

/* Tex_Bind_1_00176B10 */
#define Tex_FlushLayer_0_00176440 Tex_FlushLayer_0_00176440__as_Tex_Bind_1_00176B10

void Tex_Bind_1_00176B10(Obj *o)
{
    if (!o)
        return;
    if ((o->kind & 7) == 3) {
        D_004830E8[0]++;
        D_004830EC[0]++;
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x14, o->b);
        GsPkt_SetReg_3_001543E0(6, o->a);
        GsPkt_EndAD_3_00154420();
        D_00202010 = 0;
        D_004830F4[0] = 1;
    } else {
        D_004830F4[0] = 2;
        Tex_FlushLayer_0_00176440();
    }
}
#undef Tex_FlushLayer_0_00176440

/* Tex_BindFlush_1_00176BC0 */
void Tex_BindFlush_1_00176BC0(s32 arg0) {
    Tex_Bind_1_00176B10((void *) arg0);
    GsPkt_CloseChain_1_001549D0();
}

/* Vram_AllocForTex_0_00176BF0 */
#define D_0047F0C0 D_0047F0C0__as_Vram_AllocForTex_0_00176BF0
#define D_004830D0 D_004830D0[0]
#define D_004830D2 D_004830D2[0]
#define D_004830D4 D_004830D4[0]
#define D_004830D6 D_004830D6[0]
#define D_004830D8 D_004830D8[0]
#define D_004830DC D_004830DC__as_Vram_AllocForTex_0_00176BF0[0]
#define D_004830DE D_004830DE[0]
#define Vram_AllocBlock_1_00176FB0 Vram_AllocBlock_1_00176FB0__as_Vram_AllocForTex_0_00176BF0

u16 Vram_AllocForTex_0_00176BF0(Owner_Vram_AllocForTex_0_00176BF0 *arg0, u16 arg1) {
    u16 size;
    s32 b;
    s16 first;
    s16 t;
    s16 s;
    s32 n;
    s16 h;

    size = (arg1 + 0x1F) & ~0x1F;
    b = D_004830D8;
    first = b;
    if (first != -1) {
        do {
            if (!(D_0047F0C0[b].size < size)) goto found;
            b = D_0047F0C0[b].fnext;
        } while (b != first);
    }
    b = D_004830DC;
    if (b != -1) {
        do {
            s = b;
            b = D_0047F0C0[b].fprev;
            if ((D_0047F0C0[b].owner->type & 7) != 3) {
                t = Vram_AllocBlock_1_00176FB0(b);
                b = D_0047F0C0[s].fprev;
                if (size < D_0047F0C0[t].size) {
                    b = t;
                    goto found;
                }
            }
            if (D_004830DC == -1) break;
        } while (b != D_004830DC || (D_0047F0C0[b].owner->type & 7) != 3);
    }
found:
    n = D_004830D0;
    D_004830D2--;
    if (n == D_0047F0C0[n].prev) {
        D_004830D0 = -1;
    } else {
        D_0047F0C0[D_0047F0C0[n].prev].next = D_0047F0C0[n].next;
        D_0047F0C0[D_0047F0C0[n].next].prev = D_0047F0C0[n].prev;
        if (D_004830D0 == n) D_004830D0 = D_0047F0C0[n].prev;
    }
    D_004830D6++;
    h = D_004830D4;
    if (h == -1) {
        D_004830D4 = n;
        D_0047F0C0[n].prev = n;
        D_0047F0C0[n].next = n;
    } else {
        D_0047F0C0[n].prev = b;
        D_0047F0C0[n].next = D_0047F0C0[b].next;
        D_0047F0C0[D_0047F0C0[n].prev].next = n;
        D_0047F0C0[D_0047F0C0[n].next].prev = n;
        if (h == b) D_004830D4 = n;
    }
    D_0047F0C0[n].off = D_0047F0C0[b].off;
    D_0047F0C0[n].size = size;
    D_0047F0C0[b].off += size;
    D_0047F0C0[b].size -= size;
    D_004830DE++;
    h = D_004830DC;
    if (h == -1) {
        D_004830DC = n;
        D_0047F0C0[n].fnext = n;
        D_0047F0C0[n].fprev = n;
    } else {
        D_0047F0C0[n].fnext = h;
        D_0047F0C0[n].fprev = D_0047F0C0[h].fprev;
        D_0047F0C0[D_0047F0C0[n].fnext].fprev = n;
        D_0047F0C0[D_0047F0C0[n].fprev].fnext = n;
        D_004830DC = n;
    }
    D_0047F0C0[n].owner = arg0;
    return n;
}
#undef Vram_AllocBlock_1_00176FB0
#undef D_0047F0C0
#undef D_004830DC
#undef D_004830D0
#undef D_004830D2
#undef D_004830D4
#undef D_004830D6
#undef D_004830D8
#undef D_004830DE
#undef D_004830DC
#undef D_004830DE
#undef Tex_Upload_0_00175CD0
#undef D_00438A70
#undef Tex_CalcVramSize_0_00176710
#undef D_00438A10
#undef D_0047F0C0
#undef Tex_UploadQueued_1_00176350
#undef D_00202010
#undef D_00438A30
#undef D_0043F080
#undef GsPkt_CloseChain_1_001549D0
#undef Tex_FlushLayer_0_00176440
#undef Tex_Bind_1_00176B10
#undef D_004830D0
#undef D_004830D2
#undef D_004830D4
#undef D_004830D6
#undef D_004830D8
#undef Vram_AllocBlock_1_00176FB0

/* text_00176FB0 */
#ifdef NONMATCHING
/* best-effort C: vram_alloc_block.c */
#else
INCLUDE_ASM(Vram_AllocBlock_1_00176FB0);
#endif

/* Vram_FreeBlock_0_00177380 */
/* Vram_FreeBlock_0_00177380 */
#define D_0047F0C0 D_0047F0C0__as_Vram_FreeBlock_0_00177380
extern L D_0047F0C0__as_Vram_FreeBlock_0_00177380[];
#define D_004830D0 D_004830D0__as_Vram_FreeBlock_0_00177380
extern s16 D_004830D0__as_Vram_FreeBlock_0_00177380[];

void Vram_FreeBlock_0_00177380(s16 i) {

    if (D_0047F0C0[i].used == 0) {
        D_004830DA[0]--;
        if (i == D_0047F0C0[i].n4) {
            D_004830D8[0] = -1;
        } else {
            D_0047F0C0[D_0047F0C0[i].n4].p6 = D_0047F0C0[i].p6;
            D_0047F0C0[D_0047F0C0[i].p6].n4 = D_0047F0C0[i].n4;
            if (D_004830D8[0] == i) D_004830D8[0] = D_0047F0C0[i].n4;
        }
    }
    D_004830D6[0]--;
    if (i == D_0047F0C0[i].n0) {
        D_004830D4[0] = -1;
    } else {
        D_0047F0C0[D_0047F0C0[i].n0].p2 = D_0047F0C0[i].p2;
        D_0047F0C0[D_0047F0C0[i].p2].n0 = D_0047F0C0[i].n0;
        if (D_004830D4[0] == i) D_004830D4[0] = D_0047F0C0[i].n0;
    }
    D_004830D2[0]++;
    if (D_004830D0[0] == -1) {
        D_004830D0[0] = i;
        D_0047F0C0[i].n0 = i;
        D_0047F0C0[i].p2 = i;
    } else {
        D_0047F0C0[i].n0 = D_004830D0[0];
        D_0047F0C0[i].p2 = D_0047F0C0[D_004830D0[0]].p2;
        D_0047F0C0[D_0047F0C0[i].n0].p2 = i;
        D_0047F0C0[D_0047F0C0[i].p2].n0 = i;
        D_004830D0[0] = i;
    }
    D_0047F0C0[i].used = 0;
}

/* Tex_Release_1_00177570 */

s16 Tex_Release_1_00177570(E30 *p) {
    s16 idx = p - D_004800C0;
    Q50 *q;
    if (p->b0 == 1) {
        { u32 t = p->x20 * 0x50; q = (Q50 *)(t + (s32)(*p->x10 + p->x24)); }
        q->x4C--;
        if (q->x4C > 0) {
            return q->x4C;
        }
    }
    D_004830C0.xE--;
    if (idx == D_004800C0[idx].x1C) {
        D_004830C0.xC = -1;
    } else {
        D_004800C0[D_004800C0[idx].x1C].x1E = D_004800C0[idx].x1E;
        D_004800C0[D_004800C0[idx].x1E].x1C = D_004800C0[idx].x1C;
        if (D_004830C0.xC == idx) D_004830C0.xC = D_004800C0[idx].x1C;
    }
    D_004830C0.xA++;
    if (D_004830C0.x8 == -1) {
        D_004830C0.x8 = idx;
        D_004800C0[idx].x1C = idx;
        D_004800C0[idx].x1E = idx;
    } else {
        D_004800C0[idx].x1C = D_004830C0.x8;
        D_004800C0[idx].x1E = D_004800C0[D_004830C0.x8].x1E;
        D_004800C0[D_004800C0[idx].x1C].x1E = idx;
        D_004800C0[D_004800C0[idx].x1E].x1C = idx;
    }
    p->b0 = 0;
    if (p->x22 != -1) Vram_AllocBlock_1_00176FB0(p->x22);
    return 0;
}
#undef D_0047F0C0
#undef D_004830D0

/* text_001777C0 */
#ifdef NONMATCHING
/* best-effort C: tex_resident.c */
#else
INCLUDE_ASM(Tex_Resident_0_001777C0);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/texture_bss.c): D_00438A10, D_00438A1C */
s32 D_00438A10[0x1];
volatile u16 D_00438A1C[0x2];
#endif
