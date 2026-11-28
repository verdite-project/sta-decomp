/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Mdl_ClipFrustum_0_0016BD00.c. The retail assembly of Mdl_ClipFrustum_0_0016BD00
 * also holds Mdl_DrawWithOverlay_0_0016C350 and Mdl_DrawMeshes_1_0016C7E0. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "common.h"
typedef struct { f32 t0; f32 t1; f32 n; f32 f; } Fr;
extern Flags8 D_00222A50[];
extern Mtx gMdlDrawWithOverlayBss_002F15C0;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, void *, Vec *);

s8 Mdl_ClipFrustum_0_0016BD00(u8 *m, Vec *o, Vec *u, f32 *pl, Fr *fr) {
    Vec p;
    u8 c;
    f32 len;
    f32 r;
    f32 t0;
    f32 t1;
    f32 qx;
    f32 qy;
    f32 qz;
    f32 a;
    f32 b;
    f32 k;
    f32 s;
    f32 d;
    f32 d1;
    f32 d2;

    t1 = 1.0f;
    len = u->w;
    r = o->w;
    t0 = 0.0f;
    c = 0;
    if (D_00222A50[0].f.b3) return 2;
    sceVu0CopyVector(&p, o);
    p.w = 1.0f;
    sceVu0ApplyMatrix(&p, m, &p);
    sceVu0ApplyMatrix(&p, &gMdlDrawWithOverlayBss_002F15C0, &p);
    qy = p.y + -u->y * len;
    qz = p.z + -u->z * len;
    qx = p.x + -u->x * len;
    p.z = -p.z;
    qz = -qz;
    k = fr->n - r;
    a = -p.z;
    b = -qz;
    if (a <= k) {
        if (b <= k) return -1;
        c = 1;
        s = (k + p.z) / (qz - p.z);
        d = -t1 * s;
        p.x = p.x - s * (qx - p.x);
        t0 += d;
        t1 -= d;
        p.y = p.y - s * (qy - p.y);
        p.z = -k;
    } else if (b <= k) {
        c = 1;
        s = (k + p.z) / (qz - p.z);
        t1 = -t1 * s;
        qz = -k;
        qx = p.x - s * (qx - p.x);
        qy = p.y - s * (qy - p.y);
    }
    k = fr->f + r;
    if (!(a < k)) {
        if (!(b < k)) return -1;
        c = 1;
        s = (k + p.z) / (qz - p.z);
        d = -t1 * s;
        p.x = p.x - s * (qx - p.x);
        t0 += d;
        t1 -= d;
        p.y = p.y - s * (qy - p.y);
        p.z = -k;
    } else if (!(b < k)) {
        c = 1;
        s = (k + p.z) / (qz - p.z);
        t1 = -t1 * s;
        qx = p.x - s * (qx - p.x);
        qy = p.y - s * (qy - p.y);
        qz = -k;
    }
    k = -r;
    d1 = pl[0] * p.x - pl[1] * p.z;
    d2 = pl[0] * qx - pl[1] * qz;
    if (d1 <= k) {
        if (d2 <= k) return -1;
        c = 1;
        s = (k - d1) / (d2 - d1);
        p.x = p.x + s * (qx - p.x);
        d = t1 * s;
        t0 += d;
        t1 -= d;
        p.y = p.y + s * (qy - p.y);
        p.z = p.z + s * (qz - p.z);
    } else if (d2 <= k) {
        c = 1;
        s = (k - d1) / (d2 - d1);
        qx = p.x + s * (qx - p.x);
        qy = p.y + s * (qy - p.y);
        qz = p.z + s * (qz - p.z);
        t1 = t1 * s;
    }
    d1 = -pl[0] * p.x - pl[1] * p.z;
    d2 = -pl[0] * qx - pl[1] * qz;
    if (d1 <= k) {
        if (d2 <= k) return -1;
        c = 1;
        s = (k - d1) / (d2 - d1);
        p.x = p.x + s * (qx - p.x);
        d = t1 * s;
        t0 += d;
        t1 -= d;
        p.y = p.y + s * (qy - p.y);
        p.z = p.z + s * (qz - p.z);
    } else if (d2 <= k) {
        c = 1;
        s = (k - d1) / (d2 - d1);
        qx = p.x + s * (qx - p.x);
        qy = p.y + s * (qy - p.y);
        qz = p.z + s * (qz - p.z);
        t1 = t1 * s;
    }
    d1 = -pl[2] * p.y - pl[3] * p.z;
    d2 = -pl[2] * qy - pl[3] * qz;
    if (d1 <= k) {
        if (d2 <= k) return -1;
        c = 1;
        s = (k - d1) / (d2 - d1);
        p.x = p.x + s * (qx - p.x);
        d = t1 * s;
        t0 += d;
        t1 -= d;
        p.y = p.y + s * (qy - p.y);
        p.z = p.z + s * (qz - p.z);
    } else if (d2 <= k) {
        c = 1;
        s = (k - d1) / (d2 - d1);
        qx = p.x + s * (qx - p.x);
        qy = p.y + s * (qy - p.y);
        qz = p.z + s * (qz - p.z);
        t1 = t1 * s;
    }
    d1 = pl[2] * p.y - pl[3] * p.z;
    d2 = pl[2] * qy - pl[3] * qz;
    if (d1 <= k) {
        if (d2 <= k) return -1;
        c = 1;
        s = (k - d1) / (d2 - d1);
        p.x = p.x + s * (qx - p.x);
        d = t1 * s;
        t0 += d;
        t1 -= d;
        p.y = p.y + s * (qy - p.y);
        p.z = p.z + s * (qz - p.z);
    } else if (d2 <= k) {
        c = 1;
        s = (k - d1) / (d2 - d1);
        qx = p.x + s * (qx - p.x);
        qy = p.y + s * (qy - p.y);
        qz = p.z + s * (qz - p.z);
        t1 = t1 * s;
    }
    fr->t0 = t0;
    fr->t1 = t1;
    return c ? 2 : 0;
}
#else
INCLUDE_ASM(Mdl_ClipFrustum_0_0016BD00);
#endif
