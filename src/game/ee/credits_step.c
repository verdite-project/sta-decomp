#include "common.h"
typedef struct Node { struct Node *next; s32 x4; void (*f8)(struct Node *); void (*fC)(struct Node *); u8 pad10[0xC]; s32 x1C; } Node;
typedef struct { u8 pad0[4]; u32 x4; } Obj;
typedef struct { f32 time; f32 step; Obj *o; u8 padC[0xC]; Node *head; } State;
extern State gCreditsLoadBss_004BC2F0;
extern s64 gSaveSystemStepBss_004BC360[];
s32 Credits_Step_0_001E3CA0(void) {
    Node *n;

    if (gCreditsLoadBss_004BC2F0.head != 0 && gCreditsLoadBss_004BC2F0.o != 0 && gCreditsLoadBss_004BC2F0.o->x4 >= (u32)gCreditsLoadBss_004BC2F0.step) {
        gSaveSystemStepBss_004BC360[0] = 0;
        n = ((Node **)gSaveSystemStepBss_004BC360)[-0x58/4];
        goto check;
    loop:
        n->f8(n);
        if (n->x1C == 0) n->fC(n);
        n = n->next;
    check:
        if (n != 0) goto loop;
        gCreditsLoadBss_004BC2F0.time += gCreditsLoadBss_004BC2F0.step;        return gCreditsLoadBss_004BC2F0.o->x4 < (u32)gCreditsLoadBss_004BC2F0.time;
    }
    return -1;
}

