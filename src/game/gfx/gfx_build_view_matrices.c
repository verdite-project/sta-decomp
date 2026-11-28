/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Gfx_BuildViewMatrices_0_00155090.c. The matching build takes it from the assembly that
 * gs_packet.c includes (INCLUDE_ASM(Gfx_BuildViewMatrices_0_00155090)). */
#ifdef NONMATCHING
#include "common.h"
f32 sqrtf(f32);
void sceVu0CopyMatrix(void *, void *);
void sceVu0ScaleVector(Vec *, void *, f32);
void sceVu0MulMatrix(void *, void *, void *);
extern f32 D_00201F58, D_00201F5C, D_00201F60, D_00201F64, D_00201F68, D_00201F6C, D_00201F70, D_00201F74;
extern s32 D_002022C0;
extern Mtx D_002F1900, D_002F16C0, D_002F1680, D_001F2170, D_002F15C0, D_002F1740, D_002F1640, D_002F1600;
extern Vec D_004B4BD0;

void Gfx_BuildViewMatrices_0_00155090(void) {
    Mtx A;
    Mtx B;
    Mtx C;
    Mtx D;
    Mtx E;

    sceVu0CopyMatrix(&A, &D_002F1900);
    D_00201F74 = 320.0f / A.m[0].x;
    D_00201F70 = 1.0f / sqrtf(1.0f + D_00201F74 * D_00201F74);
    D_00201F74 = D_00201F74 * D_00201F70;
    D_00201F64 = 2000.0f / A.m[0].x;
    D_00201F60 = 1.0f / sqrtf(1.0f + D_00201F64 * D_00201F64);
    D_00201F64 = D_00201F64 * D_00201F60;
    D_00201F6C = 224.0f / A.m[1].y;
    D_00201F68 = 1.0f / sqrtf(1.0f + D_00201F6C * D_00201F6C);
    D_00201F6C = D_00201F6C * D_00201F68;
    D_00201F5C = 2000.0f / A.m[1].y;
    D_00201F58 = 1.0f / sqrtf(1.0f + D_00201F5C * D_00201F5C);
    D_00201F5C = D_00201F5C * D_00201F58;
    sceVu0CopyMatrix(&C, &D_002F16C0);
    sceVu0CopyMatrix(&D, &D_002F1680);
    if (D_002022C0 == -1) {
        sceVu0CopyMatrix(&E, &D_001F2170);
        sceVu0ScaleVector(&E.m[3], &D_004B4BD0, 1.0f);
        E.m[3].w = 1.0f;
        sceVu0MulMatrix(&C, &C, &E);
        sceVu0MulMatrix(&D, &D, &E);
        D_002022C0 = 0;
    }
    sceVu0CopyMatrix(&D_002F15C0, &C);
    sceVu0CopyMatrix(&B, &D_002F1900);
    B.m[0].x = 1.0f;
    B.m[1].y = 1.0f;
    B.m[2].x = 0.0f;
    B.m[2].y = 0.0f;
    sceVu0MulMatrix(&D_002F1640, &B, &C);
    sceVu0CopyMatrix(&B, &D_002F1740);
    B.m[0].x = 1.0f;
    B.m[1].y = 1.0f;
    B.m[2].x = 0.0f;
    B.m[2].y = 0.0f;
    sceVu0MulMatrix(&D_002F1600, &B, &D);
}
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F58, D_00201F5C, D_00201F60, D_00201F64, D_00201F68, D_00201F6C, D_00201F70, D_00201F74, D_002022C0 */
f32 D_00201F58;
f32 D_00201F5C;
f32 D_00201F60;
f32 D_00201F64;
f32 D_00201F68;
f32 D_00201F6C;
f32 D_00201F70;
f32 D_00201F74;
s32 D_002022C0;
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BD0 */
Vec D_004B4BD0;
#endif
