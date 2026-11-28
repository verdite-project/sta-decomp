#include "common.h"

/* data_001F2340: the game's data at 0x001F2340..., one object per label. */
/* used by: door, map_collision, map_command, matrix_compose, menu, message,
   pad, player, player_se, script_op, text_0015F540.s, text_0015FC60.s,
   text_00171BB0.s, text_00174230.s */
#pragma explicit_zero_data on

extern u8 gDoorSbss_00202030[];
extern u8 gMenuBss_00317230[];
extern u8 gMapCommandBss_00317238[];
extern u8 gPlayerBss_0031723C[];
extern u8 gMdlCreateInstanceBss_00486900[];
extern u8 gMdlCreateInstanceBss_00486940[];
void MapCmd_AddItem_0_0017CE70(void);
void MapCmd_CopyVar_0_0017D1C0(void);
void MapCmd_FadeLight_0_0017C6F0(void);
void MapCmd_FadeTo_1_0017A650(void);
void MapCmd_GetCameraState_0_0017C4B0(void);
void MapCmd_GetDistToObject_0_0017D000(void);
void MapCmd_GetDoorState_0_0017B730(void);
void MapCmd_GetEffectState_0_0017D170(void);
void MapCmd_GetEnemyPosition_1_0017C620(void);
void MapCmd_GetEnemyRotation_1_0017C540(void);
void MapCmd_GetEquip_0_0017D130(void);
void MapCmd_GetFlagWord_0_0017A890(void);
void MapCmd_GetGlobal_0_0017D930(void);
void MapCmd_GetGlow_0_0017AF20(void);
void MapCmd_GetItemName_0_0017ECD0(void);
void MapCmd_GetLight_0_0017ABD0(void);
void MapCmd_GetNodePos_0_0017DA60(void);
void MapCmd_GetObjectAnim_0_0017DEC0(void);
void MapCmd_GetObjectFlag_0_0017DD90(void);
void MapCmd_GetObjectName_0_0017ED20(void);
void MapCmd_GetObjectState_0_0017B5A0(void);
void MapCmd_GetObjectVarB_0_0017DCD0(void);
void MapCmd_GetObjectVar_0_0017DC70(void);
void MapCmd_GetPlayerFlag_0_0017D0E0(void);
void MapCmd_GetPlayerPosB_0_0017D350(void);
void MapCmd_GetPlayerPos_1_0017CE80(void);
void MapCmd_GetPlayerRot_1_0017D240(void);
void MapCmd_GetPlayerStat2_0_0017CD10(void);
void MapCmd_GetPlayerStat_0_0017AA40(void);
void MapCmd_GetPlayerVarB_0_0017D300(void);
void MapCmd_GetPlayerVar_0_0017CC90(void);
void MapCmd_GetSfxParamA_0_0017E760(void);
void MapCmd_GetSfxParamB_0_0017EAF0(void);
void MapCmd_GetSfxState_0_0017E260(void);
void MapCmd_GetTimer_0_0017C270(void);
void MapCmd_GetValue_0_0017B7A0(void);
void MapCmd_GetWeather_0_0017CBA0(void);
void MapCmd_HideObject_0_0017B8A0(void);
void MapCmd_IsBusy_0_0017CA10(void);
void MapCmd_MoveObject_0_0017B0F0(void);
void MapCmd_NopA_2_0017ABB0(void);
void MapCmd_NopB_2_0017ABC0(void);
void MapCmd_NopC_2_0017EDB0(void);
void MapCmd_NotifyEnemies_0_0017A790(void);
void MapCmd_PlayBgm_0_0017E050(void);
void MapCmd_PlayObjectAnim_0_0017DE40(void);
void MapCmd_PlaySeAtXYZ_1_0017BC00(void);
void MapCmd_PlaySeAt_1_0017BA50(void);
void MapCmd_PlaySeOnObjectB_0_0017BC50(void);
void MapCmd_PlaySeOnObject_0_0017BAC0(void);
void MapCmd_QueryEnemies_0_0017E220(void);
void MapCmd_Random_2_0017CB50(void);
void MapCmd_RemoveItem_0_0017CE60(void);
void MapCmd_RequestEvent_0_0017C890(void);
void MapCmd_ResetObjects_0_0017C930(void);
void MapCmd_RotateNodeRel_0_0017D6E0(void);
void MapCmd_RotateNode_0_0017D5B0(void);
void MapCmd_RotateObject_0_0017B410(void);
void MapCmd_SetCameraPath_0_0017C490(void);
void MapCmd_SetCameraTarget_0_0017DB40(void);
void MapCmd_SetDoor_0_0017B780(void);
void MapCmd_SetEffectPos_0_0017CAC0(void);
void MapCmd_SetFlag2034_0_0017A640(void);
void MapCmd_SetFlagBits_0_0017A920(void);
void MapCmd_SetFloat_0_0017CA60(void);
void MapCmd_SetGlow_0_0017B060(void);
void MapCmd_SetItemFlag_0_0017CC80(void);
void MapCmd_SetLightPos_0_0017DC00(void);
void MapCmd_SetLight_0_0017ADE0(void);
void MapCmd_SetMapVar_0_0017A850(void);
void MapCmd_SetObjParam_0_0017C6D0(void);
void MapCmd_SetObjectAlpha_0_0017D3D0(void);
void MapCmd_SetObjectAnimB_0_0017DEA0(void);
void MapCmd_SetObjectAnimC_0_0017DEB0(void);
void MapCmd_SetObjectAnim_0_0017C150(void);
void MapCmd_SetObjectFlag_0_0017DD10(void);
void MapCmd_SetObjectNode_0_0017B9E0(void);
void MapCmd_SetObjectsAlpha_0_0017D480(void);
void MapCmd_SetPlayerFlags_0_0017CD50(void);
void MapCmd_SetPlayerPosVec_0_0017CFB0(void);
void MapCmd_SetPlayerPos_1_0017CF40(void);
void MapCmd_SetPlayerVar3_0_0017CD00(void);
void MapCmd_SetPlayerVar4_0_0017CCE0(void);
void MapCmd_SetSfxParamA_0_0017E5B0(void);
void MapCmd_SetSfxParamB_0_0017E940(void);
void MapCmd_SetSfxTransform_0_0017E390(void);
void MapCmd_SetSfx_0_0017E370(void);
void MapCmd_SetTexScroll_1_0017CAA0(void);
void MapCmd_ShowObject_0_0017B800(void);
void MapCmd_SpawnItem_0_0017DF20(void);
void MapCmd_SpawnSfxOnObjectB_0_0017BF50(void);
void MapCmd_SpawnSfxOnObject_0_0017BD70(void);
void MapCmd_StartStream_0_0017BA30(void);
void MapCmd_StopObject_0_0017B4D0(void);
void MapCmd_StopSe_1_0017BA40(void);
void MapCmd_TranslateNodeRel_0_0017D960(void);
void MapCmd_TranslateNode_0_0017D810(void);
void MapCmd_Vibrate_1_0017DB60(void);
void MapCmd_WaitEvent_0_0017C2A0(void);
void MapCmd_WarpPlayer_0_0017CE20(void);

#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
s32 gMdlCreateInstanceData_001F2340[0x30] = { 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, (s32)gMdlCreateInstanceBss_00486940, (s32)gMdlCreateInstanceBss_00486900, (s32)gPlayerBss_0031723C, (s32)gMapCommandBss_00317238, (s32)gMenuBss_00317230, (s32)gDoorSbss_00202030, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
s32 gScriptOpData_001F2400[0x64] = { (s32)MapCmd_GetObjectName_0_0017ED20, (s32)MapCmd_GetItemName_0_0017ECD0, (s32)MapCmd_GetSfxParamB_0_0017EAF0, (s32)MapCmd_SetSfxParamB_0_0017E940, (s32)MapCmd_SetSfxParamA_0_0017E5B0, (s32)MapCmd_SetSfxTransform_0_0017E390, (s32)MapCmd_GetSfxState_0_0017E260, (s32)MapCmd_SetSfx_0_0017E370, (s32)MapCmd_GetSfxParamA_0_0017E760, (s32)MapCmd_QueryEnemies_0_0017E220, (s32)MapCmd_PlayBgm_0_0017E050, (s32)MapCmd_GetObjectAnim_0_0017DEC0, (s32)MapCmd_SetObjectAnimC_0_0017DEB0, (s32)MapCmd_SetObjectAnimB_0_0017DEA0, (s32)MapCmd_PlayObjectAnim_0_0017DE40, (s32)MapCmd_GetObjectFlag_0_0017DD90, (s32)MapCmd_SetObjectFlag_0_0017DD10, (s32)MapCmd_GetObjectVarB_0_0017DCD0, (s32)MapCmd_GetObjectVar_0_0017DC70, (s32)MapCmd_SetLightPos_0_0017DC00, (s32)MapCmd_Vibrate_1_0017DB60, (s32)MapCmd_SetCameraTarget_0_0017DB40, (s32)MapCmd_GetNodePos_0_0017DA60, (s32)MapCmd_TranslateNodeRel_0_0017D960, (s32)MapCmd_GetGlobal_0_0017D930, (s32)MapCmd_TranslateNode_0_0017D810, (s32)MapCmd_RotateNodeRel_0_0017D6E0, (s32)MapCmd_RotateNode_0_0017D5B0, (s32)MapCmd_SetObjectsAlpha_0_0017D480, (s32)MapCmd_SetObjectAlpha_0_0017D3D0, (s32)MapCmd_GetPlayerPosB_0_0017D350, (s32)MapCmd_GetPlayerVarB_0_0017D300, (s32)MapCmd_GetPlayerRot_1_0017D240, (s32)MapCmd_CopyVar_0_0017D1C0, (s32)MapCmd_GetEffectState_0_0017D170, (s32)MapCmd_GetEquip_0_0017D130, (s32)MapCmd_GetPlayerFlag_0_0017D0E0, (s32)MapCmd_GetDistToObject_0_0017D000, (s32)MapCmd_SetPlayerPosVec_0_0017CFB0, (s32)MapCmd_SetPlayerPos_1_0017CF40, (s32)MapCmd_NopC_2_0017EDB0, (s32)MapCmd_GetPlayerPos_1_0017CE80, (s32)MapCmd_AddItem_0_0017CE70, (s32)MapCmd_RemoveItem_0_0017CE60, (s32)MapCmd_WarpPlayer_0_0017CE20, (s32)MapCmd_SetPlayerFlags_0_0017CD50, (s32)MapCmd_GetPlayerStat2_0_0017CD10, (s32)MapCmd_SetPlayerVar3_0_0017CD00, (s32)MapCmd_SetPlayerVar4_0_0017CCE0, (s32)MapCmd_GetPlayerVar_0_0017CC90, (s32)MapCmd_SetItemFlag_0_0017CC80, (s32)MapCmd_GetWeather_0_0017CBA0, (s32)MapCmd_Random_2_0017CB50, (s32)MapCmd_SetEffectPos_0_0017CAC0, (s32)MapCmd_SetTexScroll_1_0017CAA0, (s32)MapCmd_SetFloat_0_0017CA60, (s32)MapCmd_IsBusy_0_0017CA10, (s32)MapCmd_ResetObjects_0_0017C930, (s32)MapCmd_RequestEvent_0_0017C890, (s32)MapCmd_FadeLight_0_0017C6F0, (s32)MapCmd_SetObjParam_0_0017C6D0, (s32)MapCmd_GetEnemyPosition_1_0017C620, (s32)MapCmd_GetEnemyRotation_1_0017C540, (s32)MapCmd_GetCameraState_0_0017C4B0, (s32)MapCmd_SetCameraPath_0_0017C490, (s32)MapCmd_WaitEvent_0_0017C2A0, (s32)MapCmd_GetTimer_0_0017C270, (s32)MapCmd_SetObjectAnim_0_0017C150, (s32)MapCmd_SpawnSfxOnObjectB_0_0017BF50, (s32)MapCmd_SpawnSfxOnObject_0_0017BD70, (s32)MapCmd_PlaySeOnObjectB_0_0017BC50, (s32)MapCmd_PlaySeAtXYZ_1_0017BC00, (s32)MapCmd_PlaySeOnObject_0_0017BAC0, (s32)MapCmd_PlaySeAt_1_0017BA50, (s32)MapCmd_StopSe_1_0017BA40, (s32)MapCmd_StartStream_0_0017BA30, (s32)MapCmd_SetObjectNode_0_0017B9E0, (s32)MapCmd_HideObject_0_0017B8A0, (s32)MapCmd_ShowObject_0_0017B800, (s32)MapCmd_GetValue_0_0017B7A0, (s32)MapCmd_SetDoor_0_0017B780, (s32)MapCmd_GetDoorState_0_0017B730, (s32)MapCmd_RotateObject_0_0017B410, (s32)MapCmd_MoveObject_0_0017B0F0, (s32)MapCmd_SetGlow_0_0017B060, (s32)MapCmd_GetGlow_0_0017AF20, (s32)MapCmd_SetLight_0_0017ADE0, (s32)MapCmd_GetLight_0_0017ABD0, (s32)MapCmd_NopB_2_0017ABC0, (s32)MapCmd_NopA_2_0017ABB0, (s32)MapCmd_GetObjectState_0_0017B5A0, (s32)MapCmd_StopObject_0_0017B4D0, (s32)MapCmd_GetPlayerStat_0_0017AA40, (s32)MapCmd_SpawnItem_0_0017DF20, (s32)MapCmd_SetFlagBits_0_0017A920, (s32)MapCmd_GetFlagWord_0_0017A890, (s32)MapCmd_SetMapVar_0_0017A850, (s32)MapCmd_NotifyEnemies_0_0017A790, (s32)MapCmd_FadeTo_1_0017A650, (s32)MapCmd_SetFlag2034_0_0017A640 };
#endif
