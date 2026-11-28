/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Attack_TriggerSfxEvent_0_001D21E0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
// NEAR: 3 of 63 words differ (b52 and b38 same). x-address fixed via (u8 *)(a*20) + (s32)e cast trick. Remaining: prologue e-load regalloc: retail sll a2,v1,2 / addiu v1,a1,0x210 / addu v1,v1,a2; ours coalesces sll into v1 and addiu into a1.
#include "common.h"
typedef struct { u16 id; u8 pad[0x26]; } X;
typedef struct { u8 pad[4]; u8 a, b, c; Flags8 f7; u8 pad8[0x100]; f32 t[1][5]; } E;
typedef struct { u8 pad[0x210]; E *e[1]; } T;
typedef struct { u8 pad[0x90]; T *x90; u16 x94; } O;
void Fx_GetWorldMatrix_1_00163C80(O *, Mtx *);
void Attack_HandleSfxEvent_1_001D3810(O *, s32, X *, Mtx *, s32, s32, s32);
static inline E *ent(T **t, u16 *i) { return (*t)->e[*i]; }

void Attack_TriggerSfxEvent_0_001D21E0(O *o, s32 id) {
    Mtx m;
    E *e = *(E **)((s32)o->x90 + 0x210 + (o->x94 << 2));
    X *x;
    s32 i;

    if (e->f7.f.b2) {
        x = (X *)((e->f7.f.b1 ? 4 : 0) * 16 + (e->c * 12 + (e->b * 4 + (s32)((u8 *)(e->a * 20) + (s32)e))) + 0x108);
        Fx_GetWorldMatrix_1_00163C80(o, &m);
        for (i = 0; i < 4; i++, x++) {
            if (x->id == id) Attack_HandleSfxEvent_1_001D3810(o, id, x, &m, 0, 0, 0);
        }
    }
}
#else
INCLUDE_ASM(Attack_TriggerSfxEvent_0_001D21E0);
#endif
