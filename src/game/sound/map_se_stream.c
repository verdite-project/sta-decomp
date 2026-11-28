#include "common.h"
#include "game/core.h"
#include "game/sound.h"
typedef struct { s32 x0; s32 h; s32 x8; s32 xC; s32 *x10; s32 x14; s32 x18; char name[0x100]; } E;
typedef struct { s32 x0; s32 x4; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 4; } S;
typedef struct { u8 p0[0x14]; s32 x14; u8 b0 : 1; u8 b1 : 1; u8 b2 : 6; } P;
typedef struct { u8 b0 : 3; u8 b3 : 3; u8 b6 : 2; } G;
typedef struct { s32 x0; s32 h; u8 p8[0x10]; s32 x18; char name[0x100]; } E_ImageLoader_Request_1_001E1570;
typedef struct { s32 x0; s32 h; char p8[0x114]; } E_ImageLoader_Init_0_001E1770;
typedef struct Ch { s32 x0; s32 x4; u32 type : 8; u32 off : 24; u16 xC; u16 xE; } Ch;
extern E D_004BB110[16];
extern S D_004BB050[];
extern P *D_002023B0;
#ifndef NONMATCHING
extern s32 D_00201E54;
#else
/* data twins (src/game/data/sdata.c): D_00201E54 */
static s32 D_00201E54 = -1;
#endif
extern G D_00222A54[];
extern s32 D_00270F40[];
extern E_ImageLoader_Init_0_001E1770 D_004BB110__as_ImageLoader_Init_0_001E1770[16];
extern char D_004BB050__as_ImageLoader_Init_0_001E1770[];
extern const s8 D_001FE890[];
void MapSe_StreamUpdate_0_001E1250(void);
S* ImageLoader_Request_1_001E1570(const char *name, s32 idx);
void ImageLoader_SetFlag_0_001E1760(s32 arg0);
void MapSe_BindBank_0_001E1810(Ch *a0, s32 a1);
void* memset(void *p, s32 c, u32 n);
void memcpy(s32, s32 *, u32);
s32* Pool_Alloc_3_001288C0(P *, s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
s32 Task_KillWrap_0_0014DAF0(s32);
s32 Task_SetPriorityWrap_0_0014DB00(char *, s32, s32 *);
s32 File_HashName_3_00159D10(char *);
s32 File_GetSectorOrSize_0_0015A300(s32);
void File_Close_2_0015AB80(s32);
s32 Arc_FindByHash_2_0015ABD0(s32);
char* strcpy(char *dst, const char *src);
void Pool_Free_2_00128580(s32, s32);
void Task_Register_0_0014DB10(void (*f)(void));
void Snd_SetStreamParamF064_0_0012C7A0(s32, s32);
void Snd_SetStreamParamF054_0_0012C7B0(s32, s32);

/* MapSe_StreamUpdate_0_001E1250 */
void MapSe_StreamUpdate_0_001E1250(void) {
    S *s;
    E *e;
    s32 i;
    s32 h;
    u32 n;

    if (D_002023B0 != NULL && (!D_002023B0->b1 || D_002023B0->x14 == 0)) {
        if (D_00201E54 == -1) {
            for (i = 0; i < 16; i++) {
                if (D_004BB110[i].x0 == 0 && D_004BB110[i].x18 != 0) {
                    D_00201E54 = i;
                    return;
                }
            }
            return;
        }
        e = &D_004BB110[D_00201E54];
        s = &D_004BB050[D_00201E54];
        if (e->x10 == NULL) {
            if (&e->x8 != NULL) {
                h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(e->name));
                e->x8 = File_GetSectorOrSize_0_0015A300(h);
                File_Close_2_0015AB80(h);
            }
            e->h = Task_SetPriorityWrap_0_0014DB00(e->name, 0xFE, D_00270F40);
            e->x10 = Pool_Alloc_3_001288C0(D_002023B0, e->x8);
            Task_FlushWrap_0_0014DAC0(e->h, 0);
            e->xC = 0;
            s->b1 = 1;
            return;
        }
        switch ((u8)Task_KillWrap_0_0014DAF0(e->h)) {
        case 0:
            break;
        case 5:
            n = e->x8 - e->xC;
            n = (n > 0x80000) ? 0x80000 : n;
            memcpy(*e->x10 + e->xC, D_00270F40, n);
            e->xC += n;
            Task_RemoveWrap_0_0014DAE0(e->h);
            break;
        case 3:
        case 6:
            if (e->x0 == 0) {
                s->x0 = (s32)D_004BB110[D_00201E54].x10;
                s->b1 = 0;
                s->b0 = 1;
                i = D_00201E54;
                if (D_004BB110[i].h) {
                    Task_RunWrap_0_0014DAB0(D_004BB110[i].h);
                    D_004BB110[i].h = 0;
                }
                memset(&D_004BB110[i], 0, 0x11C);
                e->x0 = 1;
                e->x18 = 0;
                D_00201E54 = -1;
            }
            break;
        case 1:
        case 2:
        case 4:
            D_00222A54[0].b3 = 4;
            break;
        }
    }
}

/* ImageLoader_Request_1_001E1570 */
#define D_004BB110 D_004BB110__as_ImageLoader_Request_1_001E1570
extern E_ImageLoader_Request_1_001E1570 D_004BB110__as_ImageLoader_Request_1_001E1570[16];
#define D_002023B0 D_002023B0__as_ImageLoader_Request_1_001E1570
extern s32 D_002023B0__as_ImageLoader_Request_1_001E1570;

/* ImageLoader_Request_1_001E1570 */
S *ImageLoader_Request_1_001E1570(const char *name, s32 idx)
{
    S *s;

    s = &D_004BB050[idx];
    if (s->x0) {
        if (s->x0 && s->b0) {
            Pool_Free_2_00128580(D_002023B0, s->x0);
            s->x0 = 0;
            s->b0 = 0;
            s->b1 = 0;
            s->b2 = 0;
            s->b3 = 1;
        }
        if (s->x0) {
            Pool_Free_2_00128580(D_002023B0, s->x0);
        }
        if (D_004BB110[idx].h) {
            Task_RunWrap_0_0014DAB0(D_004BB110[idx].h);
            D_004BB110[idx].h = 0;
        }
        memset(&D_004BB110[idx], 0, 0x11C);
    }
    strcpy(D_004BB110[idx].name, name);
    s->b0 = 0;
    s->b1 = 1;
    s->b2 = 0;
    D_004BB110[idx].x18 = 1;
    return s;
}

/* ImageLoader_SetFlag_0_001E1760 */
void ImageLoader_SetFlag_0_001E1760(s32 arg0) {
    D_002023B0 = arg0;
}

/* ImageLoader_Init_0_001E1770 */

void ImageLoader_Init_0_001E1770(void)
{
    s32 i;
    E_ImageLoader_Init_0_001E1770 *e;
    memset(D_004BB110__as_ImageLoader_Init_0_001E1770, 0, 0x11C0);
    memset(D_004BB050__as_ImageLoader_Init_0_001E1770, 0, 0xC0);
    Task_Register_0_0014DB10(MapSe_StreamUpdate_0_001E1250);
    e = D_004BB110__as_ImageLoader_Init_0_001E1770;
    for (i = 0; i < 16; i++, e++) {
        if (e->h) {
            Task_RunWrap_0_0014DAB0(e->h);
            e->h = 0;
        }
        memset(e, 0, 0x11C);
    }
}
#undef D_004BB110
#undef D_002023B0

/* MapSe_BindBank_0_001E1810 */
void MapSe_BindBank_0_001E1810(Ch *a0, s32 a1) {
    u32 i;
    u32 j;
    Ch *c;
    Ch *d;
    switch (a0->x0) {
    case 0x4D415453:
    c = (Ch *)((u8 *)a0 + a0->off);
    for (i = 0; i < a0->xE; i++) {
        if (c->x0 == (D_001FE890[0] | (((const s8 *)D_001FE890)[1] << 8) | (((const s8 *)D_001FE890)[2] << 16) | (((const s8 *)D_001FE890)[3] << 24))) {
            d = (Ch *)((u8 *)c + c->off);
            for (j = 0; j < c->xE; j++) {
                switch (d->x0) {
                case 0x61444E53:
                    Snd_SetStreamParamF054_0_0012C7B0((u8 *)d - (u8 *)a1, 0);
                    break;
                case 0x62444E53:
                    Snd_SetStreamParamF064_0_0012C7A0((u8 *)d - (u8 *)a1, 0);
                    break;
                }
                d = (Ch *)((u8 *)d + d->x4);
            }
        }
        c = (Ch *)((u8 *)c + c->x4);
    }
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_002023B0 */
P *D_002023B0;
#endif
