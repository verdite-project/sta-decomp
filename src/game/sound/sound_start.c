#include "m2c.h"
#include "common.h"
#include "actor.h"
#include "obj3d.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    u8 p10[0x2C]; s16 x3C; s16 x3E;
    u8 p40[0x2D]; s8 x6D; s8 x6E; u8 p6F[0x11];
} Snd;
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H;
typedef struct Ch {
    s32 x0;
    s32 x4;
    u32 type : 8;
    u32 off : 24;
    u16 xC;
    u16 xE;
    H h;
} Ch;
typedef struct { u8 pad[0x94]; Flags8 f94; } R;
typedef struct {
    u8 pad[0x390];
    R *x390;
    u8 pad394[0x3C0 - 0x394];
    Obj3D *x3C0;
    Obj3D *x3C4;
} S;
typedef struct { u8 pad0[0x10]; u8 **x10; } Src;
extern Snd D_0022CBC0[];
extern s8 D_0022EC21[];
extern s8 D_0022EC22[];
extern u8 D_0022EBDA[];
extern u8 D_0022EC15[];
extern s8 D_001FAB58[];
extern s32 D_0022F070[];
extern u8 D_00201ED7;
extern s32 D_0022F050[];
extern Flags8 D_0022EC41[];
extern u8 D_0022EC17[];
extern s32 D_002022B8;
extern Flags8 D_0022EC42[];
extern s32 D_0022F060[];
#ifndef NONMATCHING
extern u8 **D_00201EBC;
#else
/* data twins (src/game/data/sbss.c): D_00201EBC */
static u8 **D_00201EBC;
#endif
extern s8 D_00201ED4;
void Snd_StartStream2_0_0012DE00(void);
s32 Snd_LoadSystemBank_1_0012DEE0(s32 a);
void Se_UpdateStatus_0_001D9FC0(void);
s32 Se_SetVoiceParams_0_001DA620(s32, s8, u8, u8, u8);
void Se_StopVoice_0_001DA530(s32);
void SndCh_Update3D_2_00130810(Snd *);
void Se_SendVoiceParams_0_001DA1D0(s32, s32 *);
void Pool_Free_2_00128580(s32, u8 **);
void Arc_LoadFile_2_00159DD0(s32, s32, u8 ***, s32 *);
s32 SndBank_LoadStam_1_0012E6B0(u8 *);

/* Snd_Update_1_0012D650 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_0022EC50[0xfc];

void Snd_Update_1_0012D650(void) {
    s32 i;
    Snd *s;
    s32 *o;
    u16 v;
    s32 w;
    s32 j;

    Se_ReadStatus_0_001D9F10();
    Se_UpdateStatus_0_001D9FC0();
    if (D_0022EC20[0]) {
        if (D_0022EC22[0] == 1) {
            if (!Bgm_Poll_0_001D95E0()) {
                D_0022EC20[0] = 0;
            } else {
                D_0022EC21[0] -= 4;
                if (D_0022EC21[0] < 0) D_0022EC21[0] = 0;
                v = (D_0022EC21[0] * 0x81) & 0xFFFF;
                Bgm_SetVolume_1_001D9650(v, v);
                if (D_0022EC21[0] <= 0) Bgm_Update_0_001D9680();
            }
        } else if (!Bgm_Poll_0_001D95E0()) {
            D_0022EC20[0] = 0;
        }
    }
    Bgm_UpdateWrap_0_001D9990();
    s = D_0022CBC0;
    i = 0;
    o = D_0022EC50;
    for (; i < 0x3F; i++) {
        if (s->on == 1 && s->xF == 0 && Se_IsVoiceActive_1_001DA4F0(s->idx) != 1) s->on = 0;
        if (s->on) {
            if (s->xF && s->x3 && Se_IsVoiceActive_1_001DA4F0(s->idx) == 0) {
                Se_SetVoiceParams_0_001DA620(s->idx, D_0022EBC0[s->x2 + 8], s->x4, s->x6, s->xF);
                s->x3 = 0;
            }
            switch (s->xE) {
            case 0:
                break;
            case 1:
                s->x8 -= 4;
                if (s->x8 < 4) {
                    Se_StopVoice_0_001DA530(s->idx);
                    s->x8 = 0;
                    s->on = 0;
                }
                break;
            case 2:
                s->x8 -= 4;
                if (s->x8 < 4) {
                    Se_StopVoice_0_001DA530(s->idx);
                    s->x8 = 0;
                }
                break;
            case 3:
                SndCh_Update3D_2_00130810(s);
                s->x6E += 4;
                if (!(s->x6E < 0x7B)) {
                    s->x6E = 0x7F;
                    s->xE = s->x6D;
                }
                s->x8 = s->x8 * s->x6E / 127;
                break;
            case 4:
                SndCh_Update3D_2_00130810(s);
                break;
            }
            o[0] = s->x8 * D_0022EBDA[0] / 127;
            if (!D_0022EC14[0]) {
                o[1] = -0x100;
            } else {
                o[1] = s->xC;
            }
            o[3] = s->x3C;
        }
        s++;
        o += 4;
    }
    Se_SendVoiceParams_0_001DA1D0(0x3F, D_0022EC50);
    Snd_UpdateStreams_0_0012C4D0();
    if (D_0022EC15[0] && !Se_GetFlag_0_001D9F00()) {
        D_0022EC15[0] = 0;
        w = D_0022EBDA[0];
        for (j = 0; j < 4; j++) Se_SetPortParam_0_001DA8F0(j, w);
        D_0022EBDA[0] = 0x7F;
    }
    if (D_0022EC16[0] && !Se_GetFlag_0_001D9F00() && !D_0022EC20[0] && Se_SetPortVolume_0_001DA720(D_0022EC3C[0])) {
        D_0022EC16[0] = 0;
    }
    if (!D_0022EC15[0]) SndEmit_Update_1_0012F6F0();
    Se_FlushQueue_0_001D9E30();
}

/* Snd_SetOutputMode_1_0012DA60 */
#define D_0022EC14 D_0022EC14__as_Snd_SetOutputMode_1_0012DA60
extern s8 D_0022EC14__as_Snd_SetOutputMode_1_0012DA60[];

void Snd_SetOutputMode_1_0012DA60(s32 arg0) {
    (*D_0022EC14) = (s8) (arg0 % 3);
}
#undef D_0022EC14

/* Snd_StopStream3_0_0012DA80 */
void Snd_StopStream3_0_0012DA80(void) {
    Snd_StopStream_1_0012F550(3);
}

/* Snd_BindMapSe_0_0012DA90 */
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

s32 Snd_BindMapSe_0_0012DA90(void) {
    S *s = (S *)(D_002022E4->unk518 + 0x180);
    Obj3D *o;
    Src ****p;
    u8 *base;
    Ch *c;
    s32 cnt;
    s32 i;
    s32 j;
    Ch *d;
    H *h;

    o = s->x390->f94.f.b0 == 0 ? s->x3C0 : s->x3C4;
    if (o == NULL || (p = (Src ****)o->x84) == NULL || *p == NULL || **p == NULL || ***p == NULL
        || (***p)->x10 == NULL || (base = *(***p)->x10) == NULL) {
        return -1;
    }
    switch (*(s32 *)base) {
    case 0x4D415453:
        c = (Ch *)(base + ((Ch *)base)->off);
        cnt = ((Ch *)base)->xE;
        for (i = 0; i < cnt; i++) {
            if (c->x0 == (D_001FAB58[0] | (D_001FAB58[1] << 8) | (D_001FAB58[2] << 16) | (D_001FAB58[3] << 24))) {
                d = (Ch *)((u8 *)c + c->off);
                for (j = 0; j < c->xE; j++) {
                    switch (d->x0) {
                    case 0x61444E53:
                        h = (H *)d;
                        if (*(s32 *)(DATA(h) + 4) != 0) {
                            D_0022F074[0] = (u8 *)d - base;
                        } else {
                            D_0022F074[0] = 0;
                        }
                        break;
                    }
                    d = (Ch *)((u8 *)d + d->x4);
                }
                break;
            }
            c = (Ch *)((u8 *)c + c->x4);
        }
        break;
    }
    D_00201ED7 = 0;
    Se_StopGroup_0_001D9EE0(3);
    if (D_0022EC43[0].f.b1) {
        D_0022F070[0] = 0;
        D_0022EC44[0] = 1;
        D_0022EC43[0].f.b1 = 0;
    }
    D_0022EC48[0] = 1;
    D_0022EC43[0].f.b0 = 1;
    D_0022EC43[0].f.b2 = 0;
    return 0;
}

/* Snd_StartStream1_0_0012DD10 */
void Snd_StartStream1_0_0012DD10(s32 a0) {
    D_00201ED5 = 0;
    Se_StopGroup_0_001D9EE0(1);
    if (D_0022EC41[0].f.b1) {
        D_0022F050[0] = 0;
        D_0022EC44[0] = 1;
        D_0022EC41[0].f.b1 = 0;
    }
    D_0022EC48[0] = 1;
    D_0022EC41[0].f.b0 = 1;
    D_0022EC41[0].f.b2 = 0;
    D_0022EC18[0] = a0 / 10;
}

/* Snd_StartStream2_0_0012DE00 */
void Snd_StartStream2_0_0012DE00(void) {
    if (D_0022EC17[0] == 0 && D_002022B8 == D_0022EC10[0]) {
        D_00201ED6 = 0;
        Se_StopGroup_0_001D9EE0(2);
        if (D_0022EC42[0].f.b1) {
            D_0022F060[0] = 0;
            D_0022EC44[0] = 1;
            D_0022EC42[0].f.b1 = 0;
        }
        D_0022EC48[0] = 1;
        D_0022EC17[0] = 1;
        D_0022EC42[0].f.b0 = 1;
        D_0022EC42[0].f.b2 = 0;
    }
}

/* Snd_LoadSystemBank_1_0012DEE0 */
s32 Snd_LoadSystemBank_1_0012DEE0(s32 a) {
    s32 sz;
    u8 *p;
    D_00201ED4 = 1;
    SndCh_StopGroup_1_0012E730(0);
    Arc_LoadFile_2_00159DD0(0xE728760E, a, &D_00201EBC, &sz);
    p = *D_00201EBC;
    switch (*(s32 *)p) {
    case 0x4D415453:
        if (SndBank_LoadStam_1_0012E6B0(p) == -1) {
            Pool_Free_2_00128580(a, D_00201EBC);
            return -1;
        }
    }
    Pool_Free_2_00128580(a, D_00201EBC);
    return 0;
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sound_emitter_bss.c): D_0022F050, D_0022F060, D_0022F070 */
s32 D_0022F050[0x4];
s32 D_0022F060[0x4];
s32 D_0022F070[0x4];
#endif
