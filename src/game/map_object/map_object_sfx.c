#include "m2c.h"
#include "common.h"
#include "game/map_object.h"
typedef struct { s8 pad[0x1A]; u16 x1A; s8 pad2[0x10]; } Ent_MapObj_GetSfxMatrix_0_001B1050;
typedef struct { s32 a; s32 b; } Slot_MapObj_GetSfxMatrix_0_001B1050;
typedef struct {
    s32 id;
    s8 pad4[0x74];
    u16 n;
    s8 pad7A[0xD6];
    Ent_MapObj_GetSfxMatrix_0_001B1050 *ents;
    s8 pad154[0x3C];
    Slot_MapObj_GetSfxMatrix_0_001B1050 *x190;
    s8 pad194[0x44];
    u8 x1D8;
} Chr_MapObj_GetSfxMatrix_0_001B1050;
typedef struct { s32 a; u8 b0:1; u8 b1:1; } Slot_MapObj_SetSfxFlag_0_001B11F0;
typedef struct {
    s32 id;
    s8 pad4[0x74];
    u16 n;
    s8 pad7A[0xD6];
    Ent_MapObj_GetSfxMatrix_0_001B1050 *ents;
    s8 pad154[0x3C];
    Slot_MapObj_SetSfxFlag_0_001B11F0 *x190;
    s8 pad194[0x44];
    u8 x1D8;
} Chr_MapObj_SetSfxFlag_0_001B11F0;
typedef struct { s32 id; u8 pad[0x154]; u8 *p; } Obj_MapObj_GetSfxMatrix_0_001B1050;
typedef struct { u8 pad[0x1D8]; u8 f; } Inner;
typedef struct { s8 pad[0xB6]; u8 a, b, c, d; } Sub;
typedef struct { s32 id; s8 pad[0x154]; Sub *sub; s8 pad2[0x1D8-0x15C]; u8 flags; } Obj_MapObj_GetCamera_0_001B1560;
typedef struct { s8 pad[0x1C]; u16 key; s8 pad2[3]; s8 v; s8 pad3[0xE]; } Ent_MapObj_SetNodeFlag_0_001B16E0;
typedef struct { s32 id; s8 pad[0x68]; u16 n; s8 pad1[0x134-0x6E]; Ent_MapObj_SetNodeFlag_0_001B16E0 *ents; s8 pad2[0x1D8-0x138]; u8 flags; } Obj_MapObj_GetSfxMatrix_0_001B1050_;
typedef struct { s8 pad[0x1C]; u16 key; s8 pad2[0x12]; } Ent;
typedef struct { s32 id; s8 pad[0xA8]; Ent *cur; s8 pad1[0x134 - 0xB0]; Ent *ents; } Obj_MapObj_GetCount_0_001B17E0;
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad1C[0x14]; } E;
typedef struct { s32 x0; u8 pad4[0xAC]; E *xB0; u8 padB4[0x84]; E *x138; } X;
extern s32 gMapSbss_00201E80;
extern Obj_MapObj_GetCount_0_001B17E0 **gPlayerSbss_002022BC;
extern X **gPlayerSbss_002022BC__as_MapObj_GetCountB_0_001B18D0;
void MapObj_GetSfxMatrix_0_001B1050(s32 id, s32 key, s32 a2);
void MapObj_SetSfxFlag_0_001B11F0(s32 id, s32 key, s32 a2);
s32 MapObj_GetCamera_0_001B1560(s32 id, f32 *a, f32 *b, f32 *c, f32 *d);
s32 MapObj_SetNodeFlag_0_001B16E0(s32 arg0, s32 arg1, s8 arg2);
s32 MapObj_GetCount_0_001B17E0(s32 *out);
void Sfx_GetMatrix_1_001676E0(s32, s32);
void Sfx_SetFlag_0_00167640(s32, s32);

/* MapObj_GetSfxMatrix_0_001B1050 */
/* MapObj_GetSfxMatrix_0_001B1050 */
/* MapObj_GetSfxMatrix_0_001B1050 */
/* MapObj_GetSfxMatrix_0_001B1050 */
/* MapObj_GetSfxMatrix_0_001B1050 */
#define C (((Chr_MapObj_GetSfxMatrix_0_001B1050 ***)&gMapSbss_00201E80)[2])
#define D (((Chr_MapObj_GetSfxMatrix_0_001B1050 ***)&gMapSbss_00201E80)[3])
static inline s32 ok_MapObj_GetSfxMatrix_0_001B1050(Chr_MapObj_GetSfxMatrix_0_001B1050 **p) {
    s32 r;
    if (p != 0) {
        r = ((*p)->x1D8 & 1) != 0;
    } else {
        r = 0;
    }
    return r;
}
static inline Chr_MapObj_GetSfxMatrix_0_001B1050 *find_MapObj_GetSfxMatrix_0_001B1050(s32 id) {
    Chr_MapObj_GetSfxMatrix_0_001B1050 **c = C;
    Chr_MapObj_GetSfxMatrix_0_001B1050 *r = 0;
    if (ok_MapObj_GetSfxMatrix_0_001B1050(c) && (*c)->id == id) r = *c;
    if (ok_MapObj_GetSfxMatrix_0_001B1050(c = D) && (*c)->id == id) r = *c;
    return r;
}
static inline s32 lookup_MapObj_GetSfxMatrix_0_001B1050(Chr_MapObj_GetSfxMatrix_0_001B1050 *c, s32 key) {
    s32 i;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapObj_GetSfxMatrix_0_001B1050(s32 id, s32 key, s32 a2) {
    s32 idx;
    Chr_MapObj_GetSfxMatrix_0_001B1050 *t;
    t = find_MapObj_GetSfxMatrix_0_001B1050(id);
    idx = lookup_MapObj_GetSfxMatrix_0_001B1050(find_MapObj_GetSfxMatrix_0_001B1050(id), key);
    if (t != 0 && idx != -1) {
        Sfx_GetMatrix_1_001676E0(t->x190[idx].a, a2);
    }
}
#undef C
#undef D

/* MapObj_SetSfxFlag_0_001B11F0 */
#define C (((Chr_MapObj_SetSfxFlag_0_001B11F0 ***)&gMapSbss_00201E80)[2])
#define D (((Chr_MapObj_SetSfxFlag_0_001B11F0 ***)&gMapSbss_00201E80)[3])
static inline s32 ok_MapObj_SetSfxFlag_0_001B11F0(Chr_MapObj_SetSfxFlag_0_001B11F0 **p) {
    s32 r;
    if (p != 0) {
        r = ((*p)->x1D8 & 1) != 0;
    } else {
        r = 0;
    }
    return r;
}
static inline Chr_MapObj_SetSfxFlag_0_001B11F0 *find_MapObj_SetSfxFlag_0_001B11F0(s32 id) {
    Chr_MapObj_SetSfxFlag_0_001B11F0 **c = C;
    Chr_MapObj_SetSfxFlag_0_001B11F0 *r = 0;
    if (ok_MapObj_SetSfxFlag_0_001B11F0(c) && (*c)->id == id) r = *c;
    if (ok_MapObj_SetSfxFlag_0_001B11F0(c = D) && (*c)->id == id) r = *c;
    return r;
}
static inline s32 lookup_MapObj_SetSfxFlag_0_001B11F0(Chr_MapObj_SetSfxFlag_0_001B11F0 *c, s32 key) {
    s32 i;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapObj_SetSfxFlag_0_001B11F0(s32 id, s32 key, s32 a2) {
    s32 idx;
    Chr_MapObj_SetSfxFlag_0_001B11F0 *t;
    t = find_MapObj_SetSfxFlag_0_001B11F0(id);
    idx = lookup_MapObj_SetSfxFlag_0_001B11F0(find_MapObj_SetSfxFlag_0_001B11F0(id), key);
    if (t != 0 && idx != -1) {
        Slot_MapObj_SetSfxFlag_0_001B11F0 *s = &t->x190[idx];
        s->b1 = 1;
        Sfx_SetFlag_0_00167640(s->a, a2);
    }
}
#undef C
#undef D
#undef C
#undef D

/* MapObj_SetCamera_0_001B13B0 */
#define C (((Obj_MapObj_GetSfxMatrix_0_001B1050 ***)&gMapSbss_00201E80)[2])
#define D (((Obj_MapObj_GetSfxMatrix_0_001B1050 ***)&gMapSbss_00201E80)[3])
static inline s32 IS(Obj_MapObj_GetSfxMatrix_0_001B1050 **p) { if (p != NULL) return (((Inner *)*p)->f & 1) != 0; else return 0; }
static inline s32 IS2(Obj_MapObj_GetSfxMatrix_0_001B1050 **p) { s32 r = 0; if (p != NULL) r = (((Inner *)*p)->f & 1) != 0; return r; }

s32 MapObj_SetCamera_0_001B13B0(s32 arg0, f32 a, f32 b, f32 c, f32 d) {
    Obj_MapObj_GetSfxMatrix_0_001B1050 *v0 = NULL;
    s32 v1;
    if (C != NULL) {
        v1 = (((Inner *)*C)->f & 1) != 0;
    } else {
        v1 = 0;
    }
    if (v1 != 0) {
        if ((*C)->id == arg0) v0 = *C;
    }
    v1 = D ? (((Inner *)*D)->f & 1) != 0 : 0;
    if (v1 != 0) { if ((*D)->id == arg0) v0 = *D; }
    if (v0 == NULL) return -1;
    v0->p[0xB6] = a;
    v0->p[0xB7] = b;
    v0->p[0xB8] = c;
    v0->p[0xB9] = d;
    return 1;
}
#undef C
#undef D
#undef C
#undef D

/* MapObj_GetCamera_0_001B1560 */
#define P8 M2C_FIELD(&gMapSbss_00201E80, Obj_MapObj_GetCamera_0_001B1560 ***, 8)
#define PC M2C_FIELD(&gMapSbss_00201E80, Obj_MapObj_GetCamera_0_001B1560 ***, 0xC)
static inline s32 isAct_MapObj_GetSfxMatrix_0_001B1050(Obj_MapObj_GetCamera_0_001B1560 **p) {
    if (p != NULL) return ((*p)->flags & 1) != 0;
    return 0;
}
static inline Obj_MapObj_GetCamera_0_001B1560 *findObj_MapObj_GetSfxMatrix_0_001B1050(s32 id) {
    Obj_MapObj_GetCamera_0_001B1560 *r = NULL;
    if (isAct_MapObj_GetSfxMatrix_0_001B1050(P8) && (*P8)->id == id) r = *P8;
    if (isAct_MapObj_GetSfxMatrix_0_001B1050(PC) && (*PC)->id == id) r = *PC;
    return r;
}

s32 MapObj_GetCamera_0_001B1560(s32 id, f32 *a, f32 *b, f32 *c, f32 *d) {
    Obj_MapObj_GetCamera_0_001B1560 *o = findObj_MapObj_GetSfxMatrix_0_001B1050(id);
    if (o == NULL) return -1;
    *a = o->sub->a;
    *b = o->sub->b;
    *c = o->sub->c;
    *d = o->sub->d;
    return 1;
}
#undef P8
#undef PC
#undef C
#undef D
#undef P8
#undef PC

/* MapObj_SetNodeFlag_0_001B16E0 */
#define P8 M2C_FIELD(&gMapSbss_00201E80, Obj_MapObj_GetSfxMatrix_0_001B1050_ ***, 8)
#define PC M2C_FIELD(&gMapSbss_00201E80, Obj_MapObj_GetSfxMatrix_0_001B1050_ ***, 0xC)
static inline s32 isAct_MapObj_SetNodeFlag_0_001B16E0(Obj_MapObj_GetSfxMatrix_0_001B1050_ **p) {
    if (p != NULL) return ((*p)->flags & 1) != 0;
    return 0;
}
static inline Obj_MapObj_GetSfxMatrix_0_001B1050_ *findObj_MapObj_SetNodeFlag_0_001B16E0(s32 id) {
    Obj_MapObj_GetSfxMatrix_0_001B1050_ *r = NULL;
    if (isAct_MapObj_SetNodeFlag_0_001B16E0(P8) && (*P8)->id == id) r = *P8;
    if (isAct_MapObj_SetNodeFlag_0_001B16E0(PC) && (*PC)->id == id) r = *PC;
    return r;
}
static inline Ent_MapObj_SetNodeFlag_0_001B16E0 *findE(Obj_MapObj_GetSfxMatrix_0_001B1050_ *obj, s32 key) {
    s32 i;
    if (obj == NULL) return NULL;
    for (i = 0; i < obj->n; i++) {
        if (key == obj->ents[i].key) return &obj->ents[i];
    }
    return NULL;
}

s32 MapObj_SetNodeFlag_0_001B16E0(s32 arg0, s32 arg1, s8 arg2) {
    Ent_MapObj_SetNodeFlag_0_001B16E0 *e = findE(findObj_MapObj_SetNodeFlag_0_001B16E0(arg0), arg1);
    if (e == NULL) return -1;
    e->v = arg2;
    return 1;
}
#undef P8
#undef PC
#undef C
#undef D
#undef P8
#undef PC

/* MapObj_GetCount_0_001B17E0 */
/* MapObj_GetCount_0_001B17E0 */
static inline s32 idx(s32 *out) {
    Obj_MapObj_GetCount_0_001B17E0 *o;
    if (gPlayerSbss_002022BC != NULL) {
        o = (Obj_MapObj_GetCount_0_001B17E0 *)*(s32 *)gPlayerSbss_002022BC;
    } else {
        return -1;
    }
    if (gPlayerSbss_002022BC == NULL) {
        if (out) *out = -1;
        return -1;
    }
    if (out) *out = o->id;
    if (o->cur) return o->cur - o->ents;
    return -1;
}
s32 MapObj_GetCount_0_001B17E0(s32 *out) {
    Obj_MapObj_GetCount_0_001B17E0 *o;
    s32 i;
    if (gPlayerSbss_002022BC != NULL) {
        o = *gPlayerSbss_002022BC;
    } else {
        return -1;
    }
    i = idx(out);
    if (i == -1) {
        return -1;
    } else {
        return o->ents[i].key;
    }
}

/* MapObj_GetCountB_0_001B18D0 */
static inline s32 cur(X **pp, X *x, s32 *out) {
    if (pp == 0) {
        if (out) *out = -1;
        return -1;
    }
    if (out) *out = x->x0;
    if (x->xB0) return x->xB0 - x->x138;
    return -1;
}

s32 MapObj_GetCountB_0_001B18D0(s32 *out) {
    X *x;
    s32 i;
    if (gPlayerSbss_002022BC__as_MapObj_GetCountB_0_001B18D0) {
        x = *gPlayerSbss_002022BC__as_MapObj_GetCountB_0_001B18D0;
    } else {
        return -1;
    }
    i = cur(gPlayerSbss_002022BC__as_MapObj_GetCountB_0_001B18D0, x, out);
    if (i == -1) return -1;
    return x->x138[i].x1A;
}
