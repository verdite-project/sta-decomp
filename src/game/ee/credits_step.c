#include "game/ee.h"
typedef struct { u8 pad0[4]; u32 x4; } Obj;
typedef struct { f32 time; f32 step; Obj *o; u8 padC[0xC]; CreditsNode *head; } State;
extern State gCreditsLoadBss_004BC2F0;
extern s64 gSaveSystemStepBss_004BC360[];
s32 Credits_Step_0_001E3CA0(void) {
    CreditsNode *n;

    if (gCreditsLoadBss_004BC2F0.head != 0 && gCreditsLoadBss_004BC2F0.o != 0 && gCreditsLoadBss_004BC2F0.o->x4 >= (u32)gCreditsLoadBss_004BC2F0.step) {
        gSaveSystemStepBss_004BC360[0] = 0;
        n = ((CreditsNode **)gSaveSystemStepBss_004BC360)[-0x58/4];
        goto check;
    loop:
        n->update(n);
        if (n->skipDraw == 0) n->draw(n);
        n = n->next;
    check:
        if (n != 0) goto loop;
        gCreditsLoadBss_004BC2F0.time += gCreditsLoadBss_004BC2F0.step;        return gCreditsLoadBss_004BC2F0.o->x4 < (u32)gCreditsLoadBss_004BC2F0.time;
    }
    return -1;
}

