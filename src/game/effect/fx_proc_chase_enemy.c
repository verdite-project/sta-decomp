/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/FxProc_ChaseEnemy_0_00148D00.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
typedef union { u32 w; struct { u8 s : 3; u8 r : 5; } f; } ST;
typedef struct {
    Vec p;
    Vec x10;
    u8 pad20[0x34];
    f32 x54;
    u8 pad58[8];
    f32 x60;
    u8 pad64[4];
    f32 x68;
    f32 x6C;
    u8 pad70[0x18];
    f32 x88;
    u8 pad8C[0x1C];
    ST xA8;
    u8 padAC[8];
    f32 xB4;
    f32 xB8;
    u8 padBC[0x58];
    Flags8 x114;
} O;
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define WRAP3(x) (((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f) + ((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) - 3.1415927f)
f32 sqrtf(f32);
s8 *ActorList_Next_2_001A5460(s32 *);
u32 Enemy_GetCurrentParamIdx_0_0013E110(s8 *);
f32 Angle_Wrap2PiB_2_00146B90(f32);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
Vec *Enemy_Ptr6F0_1_0013FFA0(s8 *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);
f32 Vec_Distance_3_00146940(Vec *, O *);
void EnemyScr_Event2015_1_00141510(s8 *, u8, s32, s32);
extern Vec gZeroVec_003139A0;
extern Mtx gMatrixFromData_001F2170;
extern s32 **gPlayerSbss_002022BC;

static inline s8 *find(u16 id) {
    s32 it = 0;
    s8 *p;
    for (p = ActorList_Next_2_001A5460(&it); p; p = ActorList_Next_2_001A5460(&it)) {
        if (*(u16 *)p != 0 && (u16)Enemy_GetCurrentParamIdx_0_0013E110(p) == id) return p;
    }
    return 0;
}

static inline void orbit(Vec *v, f32 t, s8 *p, O *o) {
    Mtx m;
    f32 a = 3.1415927f * t;
    v->y = 100.0f * Angle_Wrap2PiB_2_00146B90(a);
    v->z = 0.0f;
    v->w = 1.0f;
    sceVu0RotMatrixY(WRAP3(a), &m, &gMatrixFromData_001F2170);
    sceVu0ApplyMatrix(v, &m, v);
    sceVu0AddVector(v, Enemy_Ptr6F0_1_0013FFA0(p), v);
    v->y += o->x54;
    v->w = 1.0f;
}

static inline s32 ok(void) { return gPlayerSbss_002022BC && *gPlayerSbss_002022BC; }

void FxProc_ChaseEnemy_0_00148D00(O *o, f32 dt) {
    ST st;
    u16 id;
    s8 *p;
    s32 done;
    s32 s;
    f32 sp;
    f32 r;
    f32 h;
    f32 t;
    Vec v;
    Vec d;

    st.w = o->xA8.w;
    id = (u32)o->xB8;
    if (id) p = find(id);
    else p = 0;
    if (p == 0) {
        o->x88 = (f32)(u32)(o->x114.f.b1 = 0);
        return;
    }
    switch (s = st.f.s) {
    case 0:
        o->x10.x = 0.0f;
        o->x10.y = -100.0f;
        o->x10.z = 0.0f;
        o->x10.w = 0.0f;
        done = 2.0f < o->xB4;
        if (done) sceVu0CopyVector(&o->x10, &gZeroVec_003139A0);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        sp = o->x60;
        r = o->x68;
        h = o->x6C;
        t = o->xB4;
        switch (s) {
        case 0:
        case 1:
        case 2:
            v.x = r;
            orbit(&v, t, p, o);
            break;
        case 3:
            v.x = 2.0f * r;
            orbit(&v, t, p, o);
            break;
        case 4:
            sceVu0CopyVector(&v, Enemy_Ptr6F0_1_0013FFA0(p));
            break;
        }
        sp *= dt;
        sceVu0SubVector(&d, &v, &o->p);
        if (sp < sqrtf(sceVu0InnerProduct(&d, &d))) {
            sceVu0Normalize(&d, &d);
            sceVu0ScaleVector(&d, &d, sp);
        }
        sceVu0AddVector(&o->p, &o->p, &d);
        sceVu0CopyVector(&o->x10, &gZeroVec_003139A0);
        if (s == 1) done = Vec_Distance_3_00146940(&v, o) < 300.0f;
        if (s == 2) done = h < o->xB4;
        if (s == 3) done = 1.8f * r < Vec_Distance_3_00146940(Enemy_Ptr6F0_1_0013FFA0(p), o);
        if (s == 4) {
            done = Vec_Distance_3_00146940(Enemy_Ptr6F0_1_0013FFA0(p), o) < 100.0f;
            if (done) {
                EnemyScr_Event2015_1_00141510(p, ok() ? **gPlayerSbss_002022BC : 0, 3, 0);
                o->x88 = (f32)(u32)(o->x114.f.b1 = 0);
            }
        }
        break;
    }
    if (done) {
        st.f.s++;
        o->xB4 = 0.0f;
    } else {
        o->xB4 += dt;
    }
    o->xA8.w = st.w;
}
#else
INCLUDE_ASM(FxProc_ChaseEnemy_0_00148D00);
#endif
