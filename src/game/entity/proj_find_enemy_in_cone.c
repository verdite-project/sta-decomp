#include "common.h"
u16 *ActorList_Next_2_001A5460(s32 *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 fabsf(f32);
s32 Enemy_IsBusy_0_0013EE40(u16 *);
Vec *Enemy_Ptr6F0_1_0013FFA0(u16 *);
f32 Vec_Distance_3_00146940(Vec *, Vec *);
void Vec_GetYawPitchBetween_1_00146310(Vec *, Vec *, Vec *, f32 *, f32 *);
s32 Map_LineTest_1_001470F0(Vec *, Vec *, u8, s32, s32, Vec *);

u16 *Proj_FindEnemyInCone_0_00146EF0(Vec *pos, Vec *dir, s32 checkLineOfSight, f32 maxDistance, f32 pitchSpan, f32 yawSpan) {
    f32 yawError;
    f32 pitchError;
    s32 iterator;
    Vec toEnemy;
    Vec normalizedDir;
    Vec enemyPos;
    Vec hitPos;
    u16 *target;
    u16 *enemy;
    f32 pitchLimit;
    f32 yawLimit;
    f32 range;
    f32 bestScore;
    f32 distance;
    f32 score;
    s32 visible;

    range = maxDistance;
    pitchLimit = (f32)pitchSpan;
    yawLimit = (f32)yawSpan;
    target = NULL;
    bestScore = 65535.0f;
    iterator = 0;
    enemy = ActorList_Next_2_001A5460(&iterator);
    sceVu0Normalize(&normalizedDir, dir);
    if (enemy != NULL) {
        do {
            if (*enemy != 0 && Enemy_IsBusy_0_0013EE40(enemy) == 0) {
                sceVu0CopyVector(&enemyPos, Enemy_Ptr6F0_1_0013FFA0(enemy));
                distance = Vec_Distance_3_00146940(&enemyPos, pos);
                if (!(range < distance)) {
                    sceVu0SubVector(&toEnemy, &enemyPos, pos);
                    sceVu0Normalize(&toEnemy, &toEnemy);
                    Vec_GetYawPitchBetween_1_00146310(pos, dir, &enemyPos, &yawError, &pitchError);
                    yawError = fabsf(yawError);
                    pitchError = fabsf(pitchError);
                    if (!(0.5f * pitchLimit < pitchError) && !(0.5f * yawLimit < yawError)) {
                        score = (1.0f + pitchError) * (distance * (1.0f + yawError));
                        if (score < 0.0f) {
                            score = -score;
                        }
                        if (score < bestScore) {
                            if (checkLineOfSight != 0) {
                                visible = !Map_LineTest_1_001470F0(pos, &enemyPos, 3, 0x26, 0, &hitPos);
                            } else {
                                visible = 1;
                            }
                            if (visible != 0) {
                                bestScore = score;
                                target = enemy;
                            }
                        }
                    }
                }
            }
            enemy = ActorList_Next_2_001A5460(&iterator);
        } while (enemy != NULL);
    }
    return target;
}
