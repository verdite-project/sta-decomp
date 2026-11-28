#include "common.h"
extern s32 gOptionBss_004A1070[];
void Menu_RestoreOptions_1_0018E450(void);
void Menu_SaveOptions_1_0018E460(void);

/* Menu_RestoreOptions_1_0018E450 */
void Menu_RestoreOptions_1_0018E450(void) {
    Option_Load_1_001A94B0((s32) gOptionBss_004A1070);
}

/* Menu_SaveOptions_1_0018E460 */
void Menu_SaveOptions_1_0018E460(void) {
    Option_Store_1_001A94E0((s32) gOptionBss_004A1070);
}
