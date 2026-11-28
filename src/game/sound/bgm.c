#include "common.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct { u8 pad[0xC]; u32 n; u8 pad1[4]; u8 v; s8 pan; u8 pad2[0xA]; s32 off[1]; } Tbl_Bgm_Play_0_001D8FC0;
typedef struct { u32 n; u8 pad[4]; u8 v; s8 pan; u8 pad2[6]; s32 off[1]; } Ent_Bgm_Play_0_001D8FC0;
typedef struct { s32 off; u8 v; s8 pan; u8 pad[2]; s32 len; } Rec_Bgm_Play_0_001D8FC0;
typedef struct { u8 pad[0x28]; s32 off; } Hdr_Bgm_Play_0_001D8FC0;
typedef struct { u8 pad[0xC]; s16 r; s16 l; } Out;
typedef struct { u8 pad[0xC]; u32 n; s32 off[1]; } Tbl_Bgm_FindTrack_0_001D9470;
typedef struct { u32 n; s32 off[1]; } Ent_Bgm_FindTrack_0_001D9470;
typedef struct { u8 pad[5]; u8 lo; u8 hi; } Rec_Bgm_FindTrack_0_001D9470;
typedef struct { u8 pad[8]; u16 k; u8 pad2[0x32 - 10]; } Elm;
typedef struct { s32 x0; u16 x4; } Snd;
typedef struct { u8 pad[0x20]; s32 off2; } Sub;
typedef struct { u8 pad[0x10]; Sub h; s32 off1; } Hdr_Bgm_FindTrack_0_001D9470;
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; } S_Bgm_Update_0_001D9680;
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; u8 xF; } S_Bgm_Stop_0_001D9710;
typedef struct { u8 pad[0xC]; u8 c; u8 d; u8 e; } S_Bgm_Resume_0_001D97A0;
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; u8 xF; s32 x10; s32 x14; } S_Bgm_ApplyVolume_0_001D9820;
typedef struct { s32 a; s32 b; s32 x8; s32 xC; s32 x10; u16 x14; u16 x16; u8 x18; u8 pad[7]; } E;
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; u8 xF; } S_Bgm_Tick_0_001D9A80;
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; } S_Bgm_DmaChunk_0_001D9BC0;
typedef struct { u32 data, addr, size, mode; } Dma;
#ifndef NONMATCHING
extern u8 D_004B9FAC[];
#else
/* data twins (src/game/data/bgm_bss.c): D_004B9FAC */
static u8 D_004B9FAC[0x4];
#endif
extern struct { u16 a; u16 b; char pad[12]; } D_004B9FA8;
extern S_Bgm_Update_0_001D9680 D_004B9FA0;
extern E D_004B9F20[4];
extern s32 D_004B9F24[];
extern s32 D_004B9F44[];
extern s32 D_004B9F64[];
extern s32 D_004B9F84[];
extern s16 D_004B9FAA[];
#ifndef NONMATCHING
extern s32 D_004B9FA4[];
#else
/* data twins (src/game/data/bgm_bss.c): D_004B9FA4 */
static s32 D_004B9FA4[0x1];
#endif
#ifndef NONMATCHING
extern Dma D_004B9FC0;
#else
/* data twins (src/game/data/bgm_bss.c): D_004B9FC0 */
static Dma D_004B9FC0;
#endif
#ifndef NONMATCHING
extern s32 D_0020231C;
#else
/* data twins (src/game/data/sbss.c): D_0020231C */
static s32 D_0020231C;
#endif
void Bgm_DrvGetStatus_0_001D8FA0(void);
u8 Bgm_GetState_0_001D8FB0(void);
s32 Bgm_Play_0_001D8FC0(s32 a0, s32 a1, s32 a2, s32 a3, u32 i, u32 j, Out *out);
s32 Bgm_FindTrack_0_001D9470(Hdr_Bgm_FindTrack_0_001D9470 *a, s32 base, s32 end, u32 i, u32 j, u32 k, s32 *out);
s32 Bgm_SetTrackParam_0_001D98D0(s32 i, s32 p1, s32 p2, s32 p3, u16 p4, u16 p5);
void Bgm_Tick_0_001D9A80(void);
s32 Bgm_DmaChunk_0_001D9BC0(u8 *src, u32 n, u32 dst, s32 idx);
s32* Bgm_RpcCallback_0_001D9DC0(u32 cmd, s32 *p, s32 unused, s32 *size);
s32 sceSifDmaStat(u32 id);
void SndDrv_SetCallback_1_001D8320(s32, void (*)(void));
void* memset(void *, s32, u32);
void FlushCache(s32);
u32 sceSifSetDma(Dma *, s32);

/* Bgm_DrvGetStatus_0_001D8FA0 */
#define SndDrv_Call_2_001D85D0 SndDrv_Call_2_001D85D0__as_Bgm_DrvGetStatus_0_001D8FA0
int SndDrv_Call_2_001D85D0__as_Bgm_DrvGetStatus_0_001D8FA0();
void Bgm_DrvGetStatus_0_001D8FA0(void) {
    SndDrv_Call_2_001D85D0(3, 1, 0x02070000);
}
#undef SndDrv_Call_2_001D85D0

/* Bgm_GetState_0_001D8FB0 */
u8 Bgm_GetState_0_001D8FB0(void) {
    return (*D_004B9FAC);
}

/* Bgm_Play_0_001D8FC0 */
#define Bgm_FindTrack_0_001D9470 Bgm_FindTrack_0_001D9470__as_Bgm_Play_0_001D8FC0
s32 Bgm_FindTrack_0_001D9470__as_Bgm_Play_0_001D8FC0(s32, s32, s32, u32, u32, u32, Out *);

static inline s32 isz_Bgm_Play_0_001D8FC0(s32 x) { return !(x != 0); }

s32 Bgm_Play_0_001D8FC0(s32 a0, s32 a1, s32 a2, s32 a3, u32 i, u32 j, Out *out) {
    s32 ch = -1;
    s32 b1 = -1;
    s32 b2 = -1;
    Tbl_Bgm_Play_0_001D8FC0 *t;
    Ent_Bgm_Play_0_001D8FC0 *e;
    Rec_Bgm_Play_0_001D8FC0 *r;
    u8 *p;
    s32 len;
    u8 *start;
    u8 c;
    s32 R, L, R2, L2, L3, R3;
    s32 fl, fr, lr, rr;
    s32 v;
    s8 pan;

    if (isz_Bgm_Play_0_001D8FC0(a2 & (a0 & a1)))
        return 0;
    t = (Tbl_Bgm_Play_0_001D8FC0 *)(a0 + ((Hdr_Bgm_Play_0_001D8FC0 *)a0)->off);
    if (t->n < i)
        return 0;
    e = (Ent_Bgm_Play_0_001D8FC0 *)((u8 *)t + t->off[i]);
    if (e->n < j)
        return 0;
    r = (Rec_Bgm_Play_0_001D8FC0 *)((u8 *)t + e->off[j]);
    p = (u8 *)r + r->off;
    len = r->len;
    start = p;
    if (0 < len) {
        do {
            while (*p++ & 0x80) {}
            c = *p;
            if (c == 0xFF)
                break;
            if ((c & 0xF0) == 0x80 || (c & 0xF0) == 0x90) {
                b1 = p[1];
                b2 = p[2];
                ch = c & 0xF;
                p += 4;
            } else {
                p += 3;
                switch (*p) {
                case 7:
                case 12:
                case 13:
                    while (*p++ & 0x80) {}
                    p += 1;
                    break;
                case 14:
                case 15:
                    while (*p++ & 0x80) {}
                    p += 2;
                    break;
                case 16:
                case 17:
                    p += 2;
                    break;
                case 18:
                case 34:
                    while (*p++ & 0x80) {}
                    break;
                case 32:
                case 33:
                    p += 1;
                    break;
                default:
                    return 0;
                }
            }
        } while (p - start < len);
    }
    if (ch == -1)
        return 0;

    v = t->v;
    pan = t->pan;
    L = v * 0x3FFF / 127;
    R = L;
    if (pan >= 0) {
        if (pan < 0x41)
            L = L * pan >> 6;
        else
            R = L * (0x7F - pan) >> 6;
    } else {
        if (pan >= -0x40)
            L = L * pan >> 6;
        else
            R = L * (-0x7F - pan) >> 6;
    }
    L2 = e->v;
    pan = e->pan;
    R2 = L2;
    if (pan >= 0) {
        if (pan < 0x41)
            L2 = L2 * pan >> 6;
        else
            R2 = L2 * (0x7F - pan) >> 6;
    } else {
        if (pan >= -0x40)
            L2 = L2 * pan >> 6;
        else
            R2 = L2 * (-0x7F - pan) >> 6;
    }
    L3 = r->v;
    pan = r->pan;
    R3 = L3;
    if (pan >= 0) {
        if (pan < 0x41)
            L3 = L3 * pan >> 6;
        else
            R3 = L3 * (0x7F - pan) >> 6;
    } else {
        if (pan >= -0x40)
            L3 = L3 * pan >> 6;
        else
            R3 = L3 * (-0x7F - pan) >> 6;
    }
    lr = L * L2;
    rr = R * R2;
    fr = R3 * rr / 16129;
    fl = L3 * lr / 16129;
    out->r = fr < 0 ? ((-fr & 0x3FFF) | 0x4000) : (fr & 0x3FFF);
    out->l = fl < 0 ? ((-fl & 0x3FFF) | 0x4000) : (fl & 0x3FFF);
    return Bgm_FindTrack_0_001D9470(a1, a2, a3, ch, b1, b2, out);
}
#undef Bgm_FindTrack_0_001D9470

/* Bgm_FindTrack_0_001D9470 */
static inline s32 isz_Bgm_FindTrack_0_001D9470(s32 x) { return !(x != 0); }

s32 Bgm_FindTrack_0_001D9470(Hdr_Bgm_FindTrack_0_001D9470 *a, s32 base, s32 end, u32 i, u32 j, u32 k, s32 *out)
{
    Sub *h;
    Tbl_Bgm_FindTrack_0_001D9470 *t;
    Ent_Bgm_FindTrack_0_001D9470 *e;
    Rec_Bgm_FindTrack_0_001D9470 *r;
    u16 *kp;
    Tbl_Bgm_FindTrack_0_001D9470 *t2;
    Snd *s;


    if (isz_Bgm_FindTrack_0_001D9470((s32)a & base))
        return 0;
    t = (Tbl_Bgm_FindTrack_0_001D9470 *)((u8 *)a + a->off1);
    h = &a->h;
    if (t->n < i)
        return 0;
    e = (Ent_Bgm_FindTrack_0_001D9470 *)((u8 *)t + t->off[i]);
    if (e->n < j)
        return 0;
    r = (Rec_Bgm_FindTrack_0_001D9470 *)((u8 *)t + e->off[j]);
    if (r->lo > k || k > r->hi)
        return 0;
    kp = &((Elm *)r + (k - r->lo))->k;
    t2 = (Tbl_Bgm_FindTrack_0_001D9470 *)((u8 *)a + h->off2);
    if (t2->n < *kp)
        return 0;
    s = (Snd *)((u8 *)t2 + t2->off[*kp]);
    out[0] = base + s->x0;
    out[1] = s->x4;
    if (t2->n >= *kp + 1)
        out[2] = *(s32 *)((u8 *)t2 + t2->off[*kp + 1]) - s->x0;
    else
        out[2] = end - s->x0;
    return 1;
}

/* Bgm_Poll_0_001D95E0 */
s32 Bgm_Poll_0_001D95E0(void) {
    u8 r;
    if (*D_004B9FAC == 0) return 0;
    r = SndDrv_Call_2_001D85D0(3, 1, 0x02070000);
    switch (r) {
    case 0:
    case 8:
        return 0;
    }
    return 1;
}

/* Bgm_SetVolume_1_001D9650 */
#define SndDrv_CallArgs_2_001D8680 SndDrv_CallArgs_2_001D8680__as_Bgm_SetVolume_1_001D9650
void SndDrv_CallArgs_2_001D8680__as_Bgm_SetVolume_1_001D9650(s32 a, s32 b, s32 c, ...);

void Bgm_SetVolume_1_001D9650(u16 a, u16 b)
{
    D_004B9FA8.a = a;
    D_004B9FA8.b = b;
    SndDrv_CallArgs_2_001D8680(3, 0, 0x2080000, D_004B9FA8.a, D_004B9FA8.b);
}
#undef SndDrv_CallArgs_2_001D8680

/* Bgm_Update_0_001D9680 */
#define SndDrv_Call_2_001D85D0 SndDrv_Call_2_001D85D0__as_Bgm_Update_0_001D9680
void SndDrv_Call_2_001D85D0__as_Bgm_Update_0_001D9680(int, int, int);
s32 Bgm_Update_0_001D9680(void) {
    S_Bgm_Update_0_001D9680 *s = &D_004B9FA0;
    if (s->xC == 0) return -1;
    SndDrv_Call_2_001D85D0(3, 0, 0x020E0000);
    if (s->x4 != 0) {
        if (sceSifDmaStat(s->x4) >= 0) return 0;
        s->x4 = 0;
    }
    s->xC = 0;
    s->xE = 0;
    return 1;
}
#undef SndDrv_Call_2_001D85D0

/* Bgm_Stop_0_001D9710 */
#define D_004B9FA0 D_004B9FA0__as_Bgm_Stop_0_001D9710
extern S_Bgm_Stop_0_001D9710 D_004B9FA0__as_Bgm_Stop_0_001D9710;
#define D_004B9FAC D_004B9FAC__as_Bgm_Stop_0_001D9710
extern u8 D_004B9FAC__as_Bgm_Stop_0_001D9710;
#define SndDrv_Call_2_001D85D0 SndDrv_Call_2_001D85D0__as_Bgm_Stop_0_001D9710
void SndDrv_Call_2_001D85D0__as_Bgm_Stop_0_001D9710(int, int, int);
s32 Bgm_Stop_0_001D9710(void) {
    S_Bgm_Stop_0_001D9710 *s = &D_004B9FA0;
    if (D_004B9FA0.xC == 0) {
        return -1;
    }
    SndDrv_Call_2_001D85D0(3, 0, 0x02060000);
    if (s->x4 != 0) {
        if (sceSifDmaStat(s->x4) >= 0) {
            return 0;
        }
        s->x4 = 0;
    }
    s->xC = 0;
    s->xE = 0;
    return 1;
}
#undef SndDrv_Call_2_001D85D0
#undef D_004B9FA0
#undef D_004B9FAC

/* Bgm_Resume_0_001D97A0 */
#define D_004B9FA0 D_004B9FA0__as_Bgm_Resume_0_001D97A0
extern S_Bgm_Resume_0_001D97A0 D_004B9FA0__as_Bgm_Resume_0_001D97A0[];
#define SndDrv_Call_2_001D85D0 SndDrv_Call_2_001D85D0__as_Bgm_Resume_0_001D97A0
void SndDrv_Call_2_001D85D0__as_Bgm_Resume_0_001D97A0(s32, s32, s32);
s32 Bgm_Resume_0_001D97A0(void) {
    S_Bgm_Resume_0_001D97A0 *s = D_004B9FA0;
    if (D_004B9FAC[0] == 7) {
        SndDrv_Call_2_001D85D0(3, 0, 0x02010000);
        s->e = 1;
        s->c = 2;
    } else if (s->c == 6) {
        s->c = 1;
    } else {
        return 0;
    }
    return 1;
}
#undef SndDrv_Call_2_001D85D0
#undef D_004B9FA0

/* Bgm_ApplyVolume_0_001D9820 */
#define D_004B9FA0 D_004B9FA0__as_Bgm_ApplyVolume_0_001D9820
extern S_Bgm_ApplyVolume_0_001D9820 D_004B9FA0__as_Bgm_ApplyVolume_0_001D9820;
#define SndDrv_CallArgs_2_001D8680 SndDrv_CallArgs_2_001D8680__as_Bgm_ApplyVolume_0_001D9820
void SndDrv_CallArgs_2_001D8680__as_Bgm_ApplyVolume_0_001D9820(s32 a, s32 b, s32 c, ...);
s32 Bgm_ApplyVolume_0_001D9820(u16 a, u16 b) {
    S_Bgm_ApplyVolume_0_001D9820 *s = &D_004B9FA0;
    if (D_00202310 == 0) {
        return 0;
    }
    switch (s->xC) {
    case 1:
    case 2:
    case 3:
    case 6:
        return 0;
    }
    SndDrv_CallArgs_2_001D8680(3, 0, 0x020A0000, s->x14, s->x10, a, b);
    s->xC = 6;
    s->xE = 0;
    return 1;
}
#undef SndDrv_CallArgs_2_001D8680
#undef D_004B9FA0

/* Bgm_SetTrackParam_0_001D98D0 */
s32 Bgm_SetTrackParam_0_001D98D0(s32 i, s32 p1, s32 p2, s32 p3, u16 p4, u16 p5) {
    E *e;
    if (i < 0 || i >= 4) return 0;
    e = &D_004B9F20[i];
    if (e->a == 0) return 0;
    e->x8 = p1;
    e->x10 = p2;
    e->xC = p3;
    e->x14 = p4;
    e->x16 = p5;
    SndDrv_CallArgs_2_001D8680(3, 0, 0x20B0000, i, e->a, p2, p3, e->b, (u16)p4, (u16)p5);
    e->x18 = 1;
    return 1;
}

/* Bgm_UpdateWrap_0_001D9990 */
#define Bgm_Tick_0_001D9A80 Bgm_Tick_0_001D9A80__as_Bgm_UpdateWrap_0_001D9990
int Bgm_Tick_0_001D9A80__as_Bgm_UpdateWrap_0_001D9990();
void Bgm_UpdateWrap_0_001D9990(void) {
    Bgm_Tick_0_001D9A80();
}
#undef Bgm_Tick_0_001D9A80

/* Bgm_Init_0_001D99A0 */
#define Bgm_RpcCallback_0_001D9DC0 Bgm_RpcCallback_0_001D9DC0__as_Bgm_Init_0_001D99A0
void Bgm_RpcCallback_0_001D9DC0__as_Bgm_Init_0_001D99A0(void);
#define D_004B9F20 D_004B9F20__as_Bgm_Init_0_001D99A0
extern s32 D_004B9F20__as_Bgm_Init_0_001D99A0[];
#define D_004B9FA0 D_004B9FA0__as_Bgm_Init_0_001D99A0
extern s32 D_004B9FA0__as_Bgm_Init_0_001D99A0[];
#define D_004B9FA8 D_004B9FA8__as_Bgm_Init_0_001D99A0
extern s16 D_004B9FA8__as_Bgm_Init_0_001D99A0[];
s32 Bgm_Init_0_001D99A0(void) {
    SndDrv_SetCallback_1_001D8320(3, Bgm_RpcCallback_0_001D9DC0);
    if (SndDrv_Call_2_001D85D0(3, 1, 0x10000) == 0) {
        return 0;
    }
    SndDrv_StartThread_1_001D8210();
    memset(D_004B9FA0, 0, 0x20);
    memset(D_004B9F20, 0, 0x20);
    D_004B9FA0[0] = 0x40000;
    D_004B9FB0[0] = 0x8000;
    D_004B9FB4[0] = 0x2000;
    D_00202318 = 0;
    D_004B9FA8[0] = 0x3FFF;
    D_00202310 = 0;
    D_004B9FAA[0] = 0x3FFF;
    D_00202314 = 0;
    D_004B9F84[0] = 0x40000;
    D_004B9F64[0] = 0x40000;
    D_004B9F44[0] = 0x40000;
    D_004B9F24[0] = 0x40000;
    return 1;
}
#undef Bgm_RpcCallback_0_001D9DC0
#undef D_004B9F20
#undef D_004B9FA0
#undef D_004B9FA8

/* Bgm_Tick_0_001D9A80 */
#define D_004B9FA0 D_004B9FA0__as_Bgm_Tick_0_001D9A80
extern S_Bgm_Tick_0_001D9A80 D_004B9FA0__as_Bgm_Tick_0_001D9A80;
static inline s32 stop_9710(void) {
    S_Bgm_Tick_0_001D9A80 *s = &D_004B9FA0;
    if (D_004B9FA0.xC == 0) {
        return -1;
    }
    SndDrv_Call_2_001D85D0(3, 0, 0x02060000);
    if (s->x4 != 0) {
        if (sceSifDmaStat(s->x4) >= 0) {
            return 0;
        }
        s->x4 = 0;
    }
    s->xC = 0;
    s->xE = 0;
    return 1;
}
void Bgm_Tick_0_001D9A80(void) {
    S_Bgm_Tick_0_001D9A80 *s = &D_004B9FA0;
    s32 r = SndDrv_Call_2_001D85D0(3, 1, 0x02070000);
    switch (D_004B9FA0.xC) {
    case 1:
        if (r == 3) {
            SndDrv_Call_2_001D85D0(3, 0, 0x02010000);
            s->xE = 1;
            s->xC = 2;
        }
        break;
    case 2:
        if (r == 8) {
            stop_9710();
        }
        break;
    case 6:
        if (r == 3) {
            s->xC = 7;
        }
        break;
    }
    if (s->x4 != 0 && sceSifDmaStat(s->x4) < 0) {
        if (s->xC != 0) {
            SndDrv_Call_2_001D85D0(3, 0, 0x02050000);
        }
        s->x4 = 0;
    }
}
#undef D_004B9FA0

/* Bgm_DmaChunk_0_001D9BC0 */
#define D_004B9FA0 D_004B9FA0__as_Bgm_DmaChunk_0_001D9BC0
extern S_Bgm_DmaChunk_0_001D9BC0 D_004B9FA0__as_Bgm_DmaChunk_0_001D9BC0;
#define D_00202310 D_00202310__as_Bgm_DmaChunk_0_001D9BC0
extern u8 *D_00202310__as_Bgm_DmaChunk_0_001D9BC0;
#define D_00202314 D_00202314__as_Bgm_DmaChunk_0_001D9BC0
extern u32 D_00202314__as_Bgm_DmaChunk_0_001D9BC0;
s32 Bgm_DmaChunk_0_001D9BC0(u8 *src, u32 n, u32 dst, s32 idx) {
    Dma *d = &D_004B9FC0; S_Bgm_DmaChunk_0_001D9BC0 *s = &D_004B9FA0;
    u32 i;
    u32 id;
    if (D_004B9FA4[0] != 0) return 0;
    if (n > D_00202314) return 0;
    for (i = 0; i < n; i++) D_00202310[i] = (src + D_004B9F20[idx].x8)[i];
    d->data = (u32)D_00202310;
    d->addr = dst;
    d->size = n;
    d->mode = 0;
    FlushCache(0);
    id = sceSifSetDma(d, 1);
    s->x4 = id;
    return id != 0;
}
#undef D_004B9FA0
#undef D_00202310
#undef D_00202314

/* Bgm_RpcCallback_0_001D9DC0 */
#define Bgm_DmaChunk_0_001D9BC0 Bgm_DmaChunk_0_001D9BC0__as_Bgm_RpcCallback_0_001D9DC0
s32 Bgm_DmaChunk_0_001D9BC0__as_Bgm_RpcCallback_0_001D9DC0(s32 a, s32 b, s32 c, s32 d);

s32 *Bgm_RpcCallback_0_001D9DC0(u32 cmd, s32 *p, s32 unused, s32 *size)
{
    switch (cmd & 0xFFF0000) {
    case 0x2040000:
        D_0020231C = Bgm_DmaChunk_0_001D9BC0(p[0], p[1], p[2], p[3]);
        break;
    }
    *size = 4;
    return &D_0020231C;
}
#undef Bgm_DmaChunk_0_001D9BC0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202310, D_00202314 */
s32 D_00202310;
s32 D_00202314;
/* data twins (src/game/data/bgm_bss.c): D_004B9F20, D_004B9FB0 */
E D_004B9F20[4];
s32 D_004B9FB0[0x4];
#endif
