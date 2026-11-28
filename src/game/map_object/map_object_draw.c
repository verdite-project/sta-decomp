#include "common.h"
#include "game/gfx.h"
typedef union { u32 w; struct { Flags8 a, b, c, d; } f; } Key;
typedef struct { u128 q[10]; } Big;
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[6]; u8 x20; s8 x21; s8 x22; u8 pad23; Flags8 f24; u8 pad25[0xB]; } A;
typedef struct {
    u8 pad0[0x40];
    s32 **x40;
    s32 **x44;
    u8 pad48[8];
    u32 a:2;
    u32 p2:9;
    u32 idx:8;
    u32 b19:1;
    u32 p20:4;
    u32 b24:1;
    u32 p25:7;
    void *x54;
    f32 x58;
    u8 pad5C[4];
    f32 x60;
    u8 pad64[0x1C];
} B;
typedef struct { u16 x0; u8 pad2[4]; u16 x6; u8 pad8[0xA]; Flags8 f12; u8 pad13[9]; Key x1C; u8 pad20[0x20]; } C;
typedef struct {
    u8 pad0[0x6E];
    u16 n;
    u8 pad70[0x1A];
    u16 x8A;
    u8 pad8C[0x138 - 0x8C];
    A *x138;
    u8 pad13C[0x170 - 0x13C];
    C *x170;
    u8 pad174[0xC];
    B *x180;
    u8 pad184[4];
    Big *x188;
} O;
extern Big gGlowInitBss_0030D0E0;
void MapObj_DrawAll_0_001B8A60(O *o, s32 (*cb)(s32 **, Key), u32 m1, u32 m0, s16 sel);
s32 MapObj_IsSame_0_001B8F30(void *arg0, void *arg1);
void Sfx_SetFlag_0_00167640(void *, s32);
s8* Mdl_GetFrameData_0_001715B0(s32 **);
void Map_BuildNodeMatrix_0_001B5B30(Mtx *, A *);
void Player_GetPosB_0_001C9490(Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0CopyMatrix(B *, Mtx *);
s8* Map_FindSfxEntry_0_001B7300(O *, s32);
void Light_CopyColor_0_0015B6B0(Vec *, s8 *);
void Fog_SetReg_0_0015B1C0(Vec *, s8 *);
void sceVu0CopyVector(Vec *, s32 *);
void Mtx_ScaleRotation_0_0015CC40(void *, f32);
void memcpy(void *, void *, s32);
void Mdl_DrawLitWrap_0_0016B960(s8 *, Big *, Vec *, s8 *, s32, s32);
void Mdl_DrawMeshes_1_0016C7E0(s32 *, s32 *, s8 *, Key);
void Mdl_DrawMeshesB_1_0016CD80(s32 *, s32 *, s8 *, Key);

/* MapObj_DrawAll_0_001B8A60 */
void MapObj_DrawAll_0_001B8A60(O *o, s32 (*cb)(s32 **, Key), u32 m1, u32 m0, s16 sel) {
    s32 i;
    s32 *hh;
    s32 *s7;
    C *c;
    s8 *s3;
    s32 **h;
    s8 *s2;
    B *b;
    A *a;
    s32 k;
    Big *src;
    Key key;
    Mtx m;
    Vec v;
    Vec q;
    Vec v2;
    Big buf;

    for (i = 0; i < o->n; i++) {
        a = &o->x138[i];
        b = &o->x180[i];
        c = &o->x170[a->x18];
        if (b->a && c->f12.f.b3) {
            c = &o->x170[c->x6];
            h = b->x44;
        } else {
            h = b->x40;
        }
        hh = *h;
        key.w = c->x1C.w;
        if (b->x54 != NULL) Sfx_SetFlag_0_00167640(b->x54, 0);
        b->b24 = 0;
        if (!b->b19) continue;
        if (c->x0 == 0xFFFF) continue;
        if (sel == -1) {
            if (!(m0 & (1 << a->x20))) continue;
        } else if (!(m1 & (1 << a->x20))) continue;
        if (b->x58 < 1.0f) {
            key.f.a.f.b4 = 1;
            key.f.c.f.b4 = 1;
        }
        if (cb(h, key) != 0) continue;
        if (b->x54 != NULL) Sfx_SetFlag_0_00167640(b->x54, 1);
        b->b24 = 1;
        s7 = *(s32 **)*hh;
        s3 = Mdl_GetFrameData_0_001715B0(h);
        if (a->f24.f.b1) {
            Map_BuildNodeMatrix_0_001B5B30(&m, a);
            Player_GetPosB_0_001C9490(&v);
            sceVu0AddVector(&m.m[3], &m.m[3], &v);
            m.m[3].w = 1.0f;
            sceVu0CopyMatrix(b, &m);
        }
        s2 = NULL;
        if (a->f24.f.b5) s2 = Map_FindSfxEntry_0_001B7300(o, a->x22);
        if (s2 != NULL) {
            Light_CopyColor_0_0015B6B0(&q, s2 + 0x20);
            Fog_SetReg_0_0015B1C0(&q, s2 + 0x10);
        } else {
            Fog_ApplyDefault_0_0015B270();
        }
        sceVu0CopyVector(&v2, s7);
        v2.w *= b->x60;
        k = a->x21;
        if (b->idx != 0xFF) k = (s8)b->idx;
        if ((s8)k == -1) {
            src = &gGlowInitBss_0030D0E0;
        } else {
            src = &o->x188[(s8)k];
        }
        if (c->f12.f.b5) {
            *(Big *)(s3 + 0x10) = *src;
            if (b->x58 < 1.0f) Mtx_ScaleRotation_0_0015CC40(s3 + 0x10, b->x58);
            Mdl_DrawLitWrap_0_0016B960(s3, NULL, &v2, s3 + 0x200, 0, 2);
        } else {
            if (b->x58 < 1.0f) {
                memcpy(&buf, src, 0xA0);
                Mtx_ScaleRotation_0_0015CC40(&buf, b->x58);
                src = &buf;
            }
            Mdl_DrawLitWrap_0_0016B960(s3, src, &v2, s3 + 0x200, 0xC, 0);
        }
        if (key.f.b.f.b7) {
            Mdl_DrawMeshes_1_0016C7E0(s7, hh, s3, key);
        } else {
            Mdl_DrawMeshesB_1_0016CD80(s7, hh, s3, key);
        }
        o->x8A++;
        GsPkt_CloseChain_1_001549D0();
    }
}

/* MapObj_IsSame_0_001B8F30 */
s32 MapObj_IsSame_0_001B8F30(void *arg0, void *arg1) {
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return 0;
    }
    return M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x170) + (M2C_FIELD(arg1, u16 *, 0x18) << 6)), u8 *, 0x13) & 7;
}
