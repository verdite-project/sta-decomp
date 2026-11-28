#include "m2c.h"
extern M2C_UNK gMapSbss_00201E80;

s8 *MapObj_Find_1_001B19A0(s32 arg0) {
    s32 var_v1;
    s32 var_v1_2;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *var_v0;

    var_v0 = NULL;
    if (M2C_FIELD(&gMapSbss_00201E80, s8 ***, 8) != NULL) {
        var_v1 = (M2C_FIELD(*M2C_FIELD(&gMapSbss_00201E80, s8 ***, 8), u8 *, 0x1D8) & 1) != 0;
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        temp_a1 = *M2C_FIELD(&gMapSbss_00201E80, s8 ***, 8);
        if (M2C_FIELD(temp_a1, s32 *, 0) == arg0) {
            var_v0 = temp_a1;
        }
    }
    var_v1_2 = 0;
    if (M2C_FIELD(&gMapSbss_00201E80, s8 ***, 0xC) != NULL) {
        var_v1_2 = (M2C_FIELD(*M2C_FIELD(&gMapSbss_00201E80, s8 ***, 0xC), u8 *, 0x1D8) & 1) != 0;
    }
    if (var_v1_2 != 0) {
        temp_a1_2 = *M2C_FIELD(&gMapSbss_00201E80, s8 ***, 0xC);
        if (M2C_FIELD(temp_a1_2, s32 *, 0) == arg0) {
            var_v0 = temp_a1_2;
        }
    }
    return var_v0;
}
