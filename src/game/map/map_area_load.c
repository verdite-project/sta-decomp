#include "common.h"
#include "game/data.h"
#include "game/gfx.h"
#include "game/map.h"
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; s16 x18; s16 x1A; f32 x1C; u8 pad20[2]; u8 x22; u8 pad23[0xD]; } E_Map_OnAreaLoaded_0_001B6800;
typedef struct { f32 x, y, z, w; f32 x10[3]; f32 x1C; u8 pad20[2]; u8 x22; u8 pad23[0xD]; } E2;
typedef struct { u8 pad[0x24]; Flags8 f24; } M24;
typedef struct { M24 **obj; Flags8 f; u8 pad[3]; } P8;
typedef struct { u8 pad[0x3C]; u8 x3C; } O4;
typedef struct { u8 pad[0x10]; s32 *x10; } M;
typedef struct { Vec v[8]; } V8;
typedef struct { u8 pad[0xA0]; } A0;
typedef struct { u8 pad[0x140]; } B;
typedef struct {
    s32 pad0;
    M **p4;
    s32 *x8;
    s32 *xC;
    Vec x10;
    u8 pad20[4];
    s32 x24;
    u8 pad28[0x3C];
    s32 x64;
    u8 pad68[4];
    u16 n6C, n6E, n70, n72, n74, n76, n78;
    u8 pad7A[6];
    u16 n80;
    u8 pad82[0xA];
    s16 x8C;
    s16 x8E;
    u8 pad90[0x24];
    u8 xB4[0x80];
    E_Map_OnAreaLoaded_0_001B6800 *x134;
    u8 pad138[0xC];
    V8 *x144;
    E2 *x148;
    u8 pad14C[0x2C];
    P8 *x178;
    u8 pad17C[0xC];
    A0 *x188;
    s32 *x18C;
    u8 pad190[0x48];
    Flags8 f1D8;
} S;
typedef struct { char pad[0x3C]; unsigned int : 4; unsigned int f : 1; } BF_3C_4_1;
typedef struct { Vec p; f32 x10; f32 x14; f32 x18; u8 x1C; u8 x1D; u8 x1E; u8 x1F; u16 x20; u8 x22; u8 p23[0xD]; } E_Map_SetupPointLights_0_001B7190;
typedef struct { u8 p[0x10]; Vec x10; u8 p20[0x5E]; u16 n; u8 p80[0xEC]; E_Map_SetupPointLights_0_001B7190 *e; } O;
typedef struct { char p[0x10]; f32 a[4]; f32 b[4]; f32 f; } T;
extern s32 D_002022C4;
extern Mtx D_001F2170;
#pragma explicit_zero_data on
const char D_001FDA80[0x20] = { 0x6d, 0x61, 0x70, 0x2f, 0x6d, 0x25, 0x34, 0x2e, 0x30, 0x34, 0x64, 0x6d, 0x2e, 0x73, 0x74, 0x6d, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#ifndef NONMATCHING
extern s32 D_002022B4;
#else
/* data twins (src/game/data/sbss.c): D_002022B4 */
static s32 D_002022B4;
#endif
#ifndef NONMATCHING
extern f32 D_001F3850[4];
#else
/* data twins (src/game/data/player_data.c): D_001F3850 */
static f32 D_001F3850[0x4] = { 0.0f, 0.0f, 0.0f, 100.0f };
#endif
extern f32 D_001F3860[4];
extern f32 D_001F3870[];
void Map_OnAreaLoaded_0_001B6800(S *a, s32 a1);
void Map_OnAreaLoadedWrap_1_001B6FB0(s32 *arg0);
void Map_LoadTextures_0_001B6FC0(u8 **arg0);
void Map_GetFile_2_001B7050(s32 n, char *name, s32 *size);
s32** Map_AllocAreaBuf_1_001B70E0(s32 n);
void Map_SetupPointLights_0_001B7190(O *o, s32 a);
s32 Map_FindChunk_0_001B6190(S *, s32, s32);
void Sfx_LoadStam_1_00169D70(s32 *, void *, s32);
s32* Pool_Alloc_3_001288C0(s32, s32);
void memset(void *, s32, s32);
void Map_ResetArea_1_001B4F20(S *);
M24** Mdl_CreateInstance_0_00174230(s32, M **, s32, s32);
void sceVu0CopyVector(void *, void *);
void sceVu0AddVector(void *, void *, void *);
u8* Mdl_GetFrameData_0_001715B0(M24 **);
void sceVu0CopyMatrix(void *, void *);
void Mtx_Compose_2_00173FD0(void *, f32 *, f32 *, f32 *);
void Mdl_UpdateBoneMatricesCur_0_00171540(M24 *, Mtx *);
void Map_InitObjects_0_001B6130(S *);
void MapObj_Create_0_001BB8A0(s32, S *, s32);
void Map_SpawnItems_0_001B5FB0(S *, s32);
void Map_SpawnSfx_0_001B5CA0(S *);
s32 Glow_Add_0_0015DBF0(u8, f32 *, void *, f32, f32);
void Fog_BuildPlanes_0_0015CD30(A0 *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *);
void Script_InitContext_1_00166F90(s32 *, s32, s32, s32);
void Script_SendEvent_2_00166F80(s32, s32, s32);
s32 sprintf(char *buf, const char *fmt, ...);
char* strcpy(char *dst, const char *src);
s32 File_HashName_3_00159D10(char *name);
s32 Arc_FindByHash_2_0015ABD0(s32 a);
s32 File_GetSectorOrSize_0_0015A300(s32 h);
void File_Close_2_0015AB80(s32 h);
void PointLight_Add_0_0015C730(s32, Vec *, f32, f32, f32, f32, u8, u8, u8, u8, u16, u8);
T* LightGroup_Get_0_0015B900(s32 i);
void sceVu0ScaleVector(f32 *v0, f32 *v1, f32 s);

/* Map_OnAreaLoaded_0_001B6800 */
static inline f32 u2f(u32 x) { return x; }

void Map_OnAreaLoaded_0_001B6800(S *a, s32 a1) {
    f32 v[4];
    f32 w[4];
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    f32 pos2[4];
    f32 rot2[4];
    f32 scl2[4];
    s32 r;
    s32 sz;
    s32 saved;
    s32 j;
    s32 i;
    s32 k;
    u8 *m;
    u8 *b;
    E_Map_OnAreaLoaded_0_001B6800 *e;
    s32 *o;
    E2 *f;

    r = Map_FindChunk_0_001B6190(a, *(*a->p4)->x10, *(*a->p4)->x10);
    Sfx_LoadStam_1_00169D70((*a->p4)->x10, a->xB4, 0x20);
    sz = ((a->n6C + a->n70 + a->n72) * 8 + 15) & ~15; sz = (sz + a->n6E * 0x80 + 15) & ~15;
    sz += a->n74 * 0xA0;
    sz += a->n80 * 0x10 + (a->n76 * 4 + a->n78 * 8);
    a->x8 = Pool_Alloc_3_001288C0(D_002022C4, sz);
    memset((void *)*a->x8, 0, sz);
    Map_ResetArea_1_001B4F20(a);
    saved = D_00201F2C;
    a->x178[0].obj = Mdl_CreateInstance_0_00174230(D_002022D0, a->p4, -1, a->n6C);
    sceVu0CopyVector((u8 *)*a->x178[0].obj + 0x30, &a->x10);
    (*a->x178[0].obj)->f24.f.b2 = 0;
    j = 0;
    do {
        D_00201F2C = j;
        m = Mdl_GetFrameData_0_001715B0(a->x178[0].obj);
        sceVu0CopyMatrix(m + 0x140, &D_001F2170);
        sceVu0CopyMatrix(m + 0xC0, &D_001F2170);
        m[0x1F0] = 0xFF;
        *(s32 *)m = ((O4 *)*a->p4)->x3C & 7;
        *(s32 *)(m + 4) = 0;
        for (i = 0; i < a->n6C; i++) {
            e = &a->x134[i];
            for (k = 0; k < 3; k++) {
                pos[k] = (&e->x)[k];
                rot[k] = 0.00024414062f * (&e->rx)[k];
                scl[k] = 0.00024414062f * u2f((&e->sx)[k]);
            }
            pos[3] = 1.0f;
            rot[3] = 0.0f;
            scl[3] = 1.0f;
            b = (u8 *)&((B *)m)[i + 1];
            Mtx_Compose_2_00173FD0(b + 0x140, pos, rot, scl);
            e = &a->x134[i];
            for (k = 0; k < 3; k++) {
                pos2[k] = (&e->x)[k];
                rot2[k] = 0.00024414062f * (&e->rx)[k];
                scl2[k] = 0.00024414062f * u2f((&e->sx)[k]);
            }
            pos2[3] = 1.0f;
            rot2[3] = 0.0f;
            scl2[3] = 1.0f;
            Mtx_Compose_2_00173FD0(b + 0xC0, pos2, rot2, scl2);
            if (a->x134[i].x18 == -1) m[i * 0x140 + 0x330] = 0xFF; else m[i * 0x140 + 0x330] = a->x134[i].x18;
            if (a->x134[i].x1A == -1) m[i * 0x140 + 0x332] = 0xFF; else m[i * 0x140 + 0x332] = a->x134[i].x1A;
            m[i * 0x140 + 0x331] = 0;
        }
        Mdl_UpdateBoneMatricesCur_0_00171540(*a->x178[0].obj, &D_001F2170);
        j++;
    } while (j < 2);
    for (k = 0; k < a->n6C; k++) {
        P8 *p = &a->x178[k];
        p->f.f.b0 = 1;
        p->f.f.b1 = 0;
    }
    Map_InitObjects_0_001B6130(a);
    MapObj_Create_0_001BB8A0(D_002022D0, a, r);
    Map_SpawnItems_0_001B5FB0(a, a1);
    Map_SpawnSfx_0_001B5CA0(a);
    sceVu0CopyVector(v, &a->x10);
    for (i = 0; i < a->n76; i++) {
        f = &a->x148[i];
        o = &a->x18C[i];
        sceVu0CopyVector(w, f);
        sceVu0AddVector(w, w, v);
        w[3] = f->w;
        *o = Glow_Add_0_0015DBF0(f->x22, w, f->x10, w[3], f->x1C);
    }
    for (i = 0; i < a->n74; i++) {
        V8 *q = &a->x144[i];
        Fog_BuildPlanes_0_0015CD30(&a->x188[i], &q->v[0], &q->v[2], &gZeroVec_003139A0, &gZeroVec_003139A0, &q->v[1], &q->v[3], &gZeroVec_003139A0, &gZeroVec_003139A0, &q->v[5], &q->v[4]);
    }
    if (a->x64) {
        a->xC = Pool_Alloc_3_001288C0(D_002022C4, 0x963C);
        Script_InitContext_1_00166F90(a->xC, a->x24, a->x64, 0x3F);
        Script_SendEvent_2_00166F80(*a->xC, 0x7FFF, 0);
    }
    D_00201F2C = saved;
    a->f1D8.f.b0 = 1;
    a->x8C = 0;
    a->x8E = -2;
}

/* Map_OnAreaLoadedWrap_1_001B6FB0 */
#define Map_OnAreaLoaded_0_001B6800 Map_OnAreaLoaded_0_001B6800__as_Map_OnAreaLoadedWrap_1_001B6FB0
int Map_OnAreaLoaded_0_001B6800__as_Map_OnAreaLoadedWrap_1_001B6FB0();
void Map_OnAreaLoadedWrap_1_001B6FB0(s32 *arg0) {
    Map_OnAreaLoaded_0_001B6800((void *) *arg0, (s32) arg0);
}
#undef Map_OnAreaLoaded_0_001B6800

/* Map_LoadTextures_0_001B6FC0 */
#define sceVu0CopyVector sceVu0CopyVector__as_Map_LoadTextures_0_001B6FC0
void sceVu0CopyVector__as_Map_LoadTextures_0_001B6FC0(u8 *, s32 *);
#define D_002022D0 D_002022D0__as_Map_LoadTextures_0_001B6FC0
extern s32 *D_002022D0__as_Map_LoadTextures_0_001B6FC0;
#define gZeroVec_003139A0 gZeroVec_003139A0__as_Map_LoadTextures_0_001B6FC0
extern s32 gZeroVec_003139A0__as_Map_LoadTextures_0_001B6FC0[];

void Map_LoadTextures_0_001B6FC0(u8 **arg0) {
    u8 *temp_3;
    u8 *temp_17;
    u8 **temp_2;
    s32 **temp_4;

    temp_17 = (u8 *) (*arg0);
    temp_2 = (u8 **) (Tex_LoadArchive_0_0016F950(D_002022D0, M2C_FIELD(temp_17, u8 ***, 0x24)));
    M2C_FIELD(temp_17, u8 ***, 4) = temp_2;
    sceVu0CopyVector(temp_17 + 0x10, gZeroVec_003139A0);
    temp_3 = (u8 *) (*temp_2);
    if (((BF_3C_4_1 *)temp_3)->f != 0) {
        temp_4 = (s32 **) (M2C_FIELD(temp_3, s32 ***, 0x10));
        if (temp_4 != NULL) {
            Tex_RegisterTtix_0_00178080(temp_4);
        }
    }
    Mdl_RegisterTexAnims_0_00170F40(temp_2);
}
#undef sceVu0CopyVector
#undef D_002022D0
#undef gZeroVec_003139A0

/* Map_GetFile_2_001B7050 */
#define Pool_Alloc_3_001288C0 Pool_Alloc_3_001288C0__as_Map_GetFile_2_001B7050
s32** Pool_Alloc_3_001288C0__as_Map_GetFile_2_001B7050(s32, s32);

/* Map_GetFile_2_001B7050 */
void Map_GetFile_2_001B7050(s32 n, char *name, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FDA80, n);
    if (name)
        strcpy(name, buf);
    if (size) {
        h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf));
        *size = File_GetSectorOrSize_0_0015A300(h);
        File_Close_2_0015AB80(h);
    }
}

/* Map_AllocAreaBuf_1_001B70E0 */
static inline void ld(s32 n, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FDA80, n);
    if (size) {
        h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf));
        *size = File_GetSectorOrSize_0_0015A300(h);
        File_Close_2_0015AB80(h);
    }
}
s32 **Map_AllocAreaBuf_1_001B70E0(s32 n) {
    s32 size;
    s32 **r;
    s32 *p;
    ld(n, &size);
    D_002022B4 = n;
    r = Pool_Alloc_3_001288C0(D_002022C4, 0x1E0);
    p = *r;
    memset(p, 0, 0x1E0);
    p[9] = (s32)Pool_Alloc_3_001288C0(D_002022C4, size);
    p[0] = n;
    return r;
}
#undef Pool_Alloc_3_001288C0

/* Map_SetupPointLights_0_001B7190 */
#define sceVu0CopyVector sceVu0CopyVector__as_Map_SetupPointLights_0_001B7190
void sceVu0CopyVector__as_Map_SetupPointLights_0_001B7190(Vec *, Vec *);
#define sceVu0AddVector sceVu0AddVector__as_Map_SetupPointLights_0_001B7190
void sceVu0AddVector__as_Map_SetupPointLights_0_001B7190(Vec *, Vec *, Vec *);

void Map_SetupPointLights_0_001B7190(O *o, s32 a) {
    Vec base;
    Vec v;
    s32 i;
    s32 off;
    E_Map_SetupPointLights_0_001B7190 *e;
    sceVu0CopyVector(&base, &o->x10);
    PointLightGroup_Clear_0_0015C6D0(a);
    i = 0;
    if (i < o->n) {
        off = 0;
        do {
        e = (E_Map_SetupPointLights_0_001B7190 *)((u8 *)o->e + off);
        sceVu0CopyVector(&v, &e->p);
        sceVu0AddVector(&v, &v, &base);
        v.w = e->p.w;
        PointLight_Add_0_0015C730(a, &v, v.w, e->x18, e->x10, e->x14, e->x1C, e->x1D, e->x1E, e->x1F, e->x20, e->x22);
        i++;
        off += 0x30;
        } while (i < o->n);
    }
}
#undef sceVu0CopyVector
#undef sceVu0AddVector

/* Map_SetupAmbient_0_001B7290 */
#define sceVu0CopyVector sceVu0CopyVector__as_Map_SetupAmbient_0_001B7290
void sceVu0CopyVector__as_Map_SetupAmbient_0_001B7290(f32 *v0, f32 *v1);

void Map_SetupAmbient_0_001B7290(void)
{
    T *t = LightGroup_Get_0_0015B900(-1);
    sceVu0CopyVector(D_001F3860, t->b);
    sceVu0ScaleVector(D_001F3850, t->a, 255.0f);
    D_001F3870[0] = t->f;
}
#undef sceVu0CopyVector

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_002022D0 */
s32 D_002022D0;
#endif
