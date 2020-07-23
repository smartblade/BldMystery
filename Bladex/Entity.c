
#include "bladex_int.h"


#define PROP_TYPE_OBJ                           0
#define PROP_TYPE_INT                           1
#define PROP_TYPE_FLT                           2
#define PROP_TYPE_STR                           3
#define PROP_TYPE_VEC                           4

#define PROP_ONLY_GET                           1
#define PROP_ONLY_SET                           2
#define PROP_GET_AND_SET                        3


static PyObject* bex_ent_GetParticleEntity(PyObject* self, PyObject* args);
static PyObject* bex_ent_SeverLimb(PyObject* self, PyObject* args);
static PyObject* bex_ent_ResetWounds(PyObject* self, PyObject* args);
static PyObject* bex_ent_Impulse(PyObject* self, PyObject* args);
static PyObject* bex_ent_ImpulseC(PyObject* self, PyObject* args);
static PyObject* bex_ent_Fly(PyObject* self, PyObject* args);
static PyObject* bex_ent_SubscribeToList(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromList(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInventRight(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInventLeft(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInventLeft2(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromWorld(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromWorldWithChilds(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchAnimation(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchAnimation2(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchAnmType(PyObject* self, PyObject* args);
static PyObject* bex_ent_GotAnmType(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetMesh(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAnmFlags(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetTmpAnmFlags(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetActiveEnemy(PyObject* self, PyObject* args);
static PyObject* bex_ent_CanISee(PyObject* self, PyObject* args);
static PyObject* bex_ent_CanISeeFrom(PyObject* self, PyObject* args);
static PyObject* bex_ent_InsideActionArea(PyObject* self, PyObject* args);
static PyObject* bex_ent_CheckAnimCol(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetEnemy(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetEnemyName(PyObject* self, PyObject* args);
static PyObject* bex_ent_Chase(PyObject* self, PyObject* args);
static PyObject* bex_ent_ResetChase(PyObject* self, PyObject* args);
static PyObject* bex_ent_GoTo(PyObject* self, PyObject* args);
static PyObject* bex_ent_CanGoTo(PyObject* self, PyObject* args);
static PyObject* bex_ent_QuickFace(PyObject* self, PyObject* args);
static PyObject* bex_ent_Face(PyObject* self, PyObject* args);
static PyObject* bex_ent_LookAtEntity(PyObject* self, PyObject* args);
static PyObject* bex_ent_StartLooking(PyObject* self, PyObject* args);
static PyObject* bex_ent_StopLooking(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddWatchAnim(PyObject* self, PyObject* args);
static PyObject* bex_ent_GraspPos(PyObject* self, PyObject* args);
static PyObject* bex_ent_Freeze(PyObject* self, PyObject* args);
static PyObject* bex_ent_UnFreeze(PyObject* self, PyObject* args);
static PyObject* bex_ent_SwitchTo1H(PyObject* self, PyObject* args);
static PyObject* bex_ent_SwitchToBow(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchBayRoute(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchWatch(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetActionMode(PyObject* self, PyObject* args);
static PyObject* bex_ent_StartGrabbing(PyObject* self, PyObject* args);
static PyObject* bex_ent_StopGrabbing(PyObject* self, PyObject* args);
static PyObject* bex_ent_LookAt(PyObject* self, PyObject* args);
static PyObject* bex_ent_LookAtPerson(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddAnmEventFunc(PyObject* self, PyObject* args);
static PyObject* bex_ent_DelAnmEventFunc(PyObject* self, PyObject* args);
static PyObject* bex_ent_ClearAnmEventFuncs(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddAnimSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddEventSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_SlideTo(PyObject* self, PyObject* args);
static PyObject* bex_ent_ClearPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_StartPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_GoToPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_TurnOn(PyObject* self, PyObject* args);
static PyObject* bex_ent_TurnOff(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddPathNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetNodeStartTangent(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetNodeEndTangent(PyObject* self, PyObject* args);
static PyObject* bex_ent_Rotate(PyObject* self, PyObject* args);
static PyObject* bex_ent_RotateAbs(PyObject* self, PyObject* args);
static PyObject* bex_ent_RotateRel(PyObject* self, PyObject* args);
static PyObject* bex_ent_Move(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetPosition(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetOrientation(PyObject* self, PyObject* args);
static PyObject* bex_ent_PutToWorld(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetInventoryEntity(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetInventorySelected(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetInventory(PyObject* self, PyObject* args);
static PyObject* bex_ent_Use(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetObjectSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_PlaySound(PyObject* self, PyObject* args);
static PyObject* bex_ent_StopSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_MessageEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_Rel2AbsPoint(PyObject* self, PyObject* args);
static PyObject* bex_ent_Rel2AbsVector(PyObject* self, PyObject* args);
static PyObject* bex_ent_Abs2RelPoint(PyObject* self, PyObject* args);
static PyObject* bex_ent_Abs2RelVector(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetDummyAxis(PyObject* self, PyObject* args);
static PyObject* bex_ent_SQDistance2(PyObject* self, PyObject* args);
static PyObject* bex_ent_CatchOnFire(PyObject* self, PyObject* args);
static PyObject* bex_ent_ExcludeHitFor(PyObject* self, PyObject* args);
static PyObject* bex_ent_Unlink(PyObject* self, PyObject* args);
static PyObject* bex_ent_Link(PyObject* self, PyObject* args);
static PyObject* bex_ent_LinkToNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_LinkAnchors(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetNodeIndex(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetNChildren(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetChild(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddCameraEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveCameraEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddCameraNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetCameraStartTangentNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetCameraEndTangentNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetTravellingView(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetPersonView(PyObject* self, PyObject* args);
static PyObject* bex_ent_CameraClearPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_CameraStartPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetMaxCamera(PyObject* self, PyObject* args);
static PyObject* bex_ent_Cut(PyObject* self, PyObject* args);
static PyObject* bex_ent_DoAction(PyObject* self, PyObject* args);
static PyObject* bex_ent_DoActionWI(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetOnFloor(PyObject* self, PyObject* args);
static PyObject* bex_ent_RaiseEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetWoundedZone(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetWoundedZone(PyObject* self, PyObject* args);
static PyObject* bex_ent_InterruptCombat(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetGroupMembers(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetCombatants(PyObject* self, PyObject* args);
static PyObject* bex_ent_ExcludeHitInAnimationFor(PyObject* self, PyObject* args);
static PyObject* bex_ent_TestPos(PyObject* self, PyObject* args);
static PyObject* bex_ent_TestPosInOwnBox(PyObject* self, PyObject* args);
static PyObject* bex_ent_UnlinkChildren(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetNextAttack(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAuraActive(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAuraParams(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAuraGradient(PyObject* self, PyObject* args);
static PyObject* bex_ent_IsValid(PyObject* self, PyObject* args);

static PyObject *bex_ent_doc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Data_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_TimerFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_HitFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_InflictHitFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_HitShieldFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_DamageFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_StickFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_FrameFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_HearFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_SeeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_UseFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ChangeNodeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_TouchFluidFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterPrimaryAAFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterSecondaryAAFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterCloseFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterLargeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AnmEndedFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_DelayNoSeenFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_RouteEndedFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ImHurtFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ImDeadFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnemyDeadFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_NoAllowedAreaFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnemyNoAllowedAreaFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_CharSeeingEnemyFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AnmTranFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_NewComboFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_BigFallFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AttackFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ToggleCombatFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_TakeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ThrowFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_MutilateFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AttackList_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnHitFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnStopFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnStepFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnAnimationEndFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnPathNodeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_RAttackMin_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_RAttackMax_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ActionAreaMin_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ActionAreaMax_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Arrow_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Static_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Actor_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Person_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Weapon_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Orientation_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_SubscribedLists_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_FiresIntensity_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightIntensity_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightPrecission_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightColor_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightGlow_get(PyObject *self, char *attr_name);
static int bex_ent_Static_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Actor_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Person_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Weapon_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Arrow_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Data_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_FiresIntensity_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Lights_set(PyObject *self, char *attr_name, PyObject *value);
static PyObject *bex_ent_Lights_get(PyObject *self, char *attr_name);
static int bex_ent_RAttackMin_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_RAttackMax_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ActionAreaMin_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ActionAreaMax_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Orientation_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_TimerFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_HitFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_InflictHitFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_HitShieldFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_DamageFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_StickFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_FrameFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_HearFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_SeeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_UseFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ChangeNodeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_TouchFluidFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterPrimaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterSecondaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterCloseFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterLargeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AnmEndedFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_DelayNoSeenFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_RouteEndedFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ImHurtFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ImDeadFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnemyDeadFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_NoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnemyNoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_CharSeeingEnemyFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AnmTranFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_NewComboFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_BigFallFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AttackFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ToggleCombatFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_TakeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ThrowFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_MutilateFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AttackList_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnHitFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnStopFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnStepFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnAnimationEndFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnPathNodeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_InternalState_set(PyObject *self, char *attr_name, PyObject *value);
static PyObject *bex_ent_InternalState_get(PyObject *self, char *attr_name);
static void init_entity_type(void);
static void bld_py_entity_dealloc(PyObject *self);
static int bld_py_entity_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_entity_getattr(PyObject *self, char *attr_name);
static int bld_py_entity_setattr(PyObject *self, char *attr_name, PyObject *value);


PyTypeObject entityTypeObject;


static PyMethodDef entity_methods[] = {
    { "GetParticleEntity",              bex_ent_GetParticleEntity,          METH_VARARGS, NULL },
    { "SeverLimb",                      bex_ent_SeverLimb,                  METH_VARARGS, NULL },
    { "ResetWounds",                    bex_ent_ResetWounds,                METH_VARARGS, NULL },
    { "Impulse",                        bex_ent_Impulse,                    METH_VARARGS, NULL },
    { "ImpulseC",                       bex_ent_ImpulseC,                   METH_VARARGS, NULL },
    { "Fly",                            bex_ent_Fly,                        METH_VARARGS, NULL },
    { "SubscribeToList",                bex_ent_SubscribeToList,            METH_VARARGS, NULL },
    { "RemoveFromList",                 bex_ent_RemoveFromList,             METH_VARARGS, NULL },
    { "RemoveFromInvent",               bex_ent_RemoveFromInvent,           METH_VARARGS, NULL },
    { "RemoveFromInventRight",          bex_ent_RemoveFromInventRight,      METH_VARARGS, NULL },
    { "RemoveFromInventLeft",           bex_ent_RemoveFromInventLeft,       METH_VARARGS, NULL },
    { "RemoveFromInventLeft2",          bex_ent_RemoveFromInventLeft2,      METH_VARARGS, NULL },
    { "RemoveFromWorld",                bex_ent_RemoveFromWorld,            METH_VARARGS, NULL },
    { "RemoveFromWorldWithChilds",      bex_ent_RemoveFromWorldWithChilds,  METH_VARARGS, NULL },
    { "LaunchAnimation",                bex_ent_LaunchAnimation,            METH_VARARGS, NULL },
    { "LaunchAnimation2",               bex_ent_LaunchAnimation2,           METH_VARARGS, NULL },
    { "LaunchAnmType",                  bex_ent_LaunchAnmType,              METH_VARARGS, NULL },
    { "GotAnmType",                     bex_ent_GotAnmType,                 METH_VARARGS, NULL },
    { "SetMesh",                        bex_ent_SetMesh,                    METH_VARARGS, NULL },
    { "SetAnmFlags",                    bex_ent_SetAnmFlags,                METH_VARARGS, NULL },
    { "SetTmpAnmFlags",                 bex_ent_SetTmpAnmFlags,             METH_VARARGS, NULL },
    { "SetActiveEnemy",                 bex_ent_SetActiveEnemy,             METH_VARARGS, NULL },
    { "CanISee",                        bex_ent_CanISee,                    METH_VARARGS, NULL },
    { "CanISeeFrom",                    bex_ent_CanISeeFrom,                METH_VARARGS, NULL },
    { "InsideActionArea",               bex_ent_InsideActionArea,           METH_VARARGS, NULL },
    { "CheckAnimCol",                   bex_ent_CheckAnimCol,               METH_VARARGS, NULL },
    { "SetEnemy",                       bex_ent_SetEnemy,                   METH_VARARGS, NULL },
    { "GetEnemyName",                   bex_ent_GetEnemyName,               METH_VARARGS, NULL },
    { "Chase",                          bex_ent_Chase,                      METH_VARARGS, NULL },
    { "ResetChase",                     bex_ent_ResetChase,                 METH_VARARGS, NULL },
    { "GoTo",                           bex_ent_GoTo,                       METH_VARARGS, NULL },
    { "CanGoTo",                        bex_ent_CanGoTo,                    METH_VARARGS, NULL },
    { "QuickFace",                      bex_ent_QuickFace,                  METH_VARARGS, NULL },
    { "Face",                           bex_ent_Face,                       METH_VARARGS, NULL },
    { "LookAtEntity",                   bex_ent_LookAtEntity,               METH_VARARGS, NULL },
    { "StartLooking",                   bex_ent_StartLooking,               METH_VARARGS, NULL },
    { "StopLooking",                    bex_ent_StopLooking,                METH_VARARGS, NULL },
    { "AddWatchAnim",                   bex_ent_AddWatchAnim,               METH_VARARGS, NULL },
    { "GraspPos",                       bex_ent_GraspPos,                   METH_VARARGS, NULL },
    { "Freeze",                         bex_ent_Freeze,                     METH_VARARGS, NULL },
    { "UnFreeze",                       bex_ent_UnFreeze,                   METH_VARARGS, NULL },
    { "SwitchTo1H",                     bex_ent_SwitchTo1H,                 METH_VARARGS, NULL },
    { "SwitchToBow",                    bex_ent_SwitchToBow,                METH_VARARGS, NULL },
    { "LaunchBayRoute",                 bex_ent_LaunchBayRoute,             METH_VARARGS, NULL },
    { "LaunchWatch",                    bex_ent_LaunchWatch,                METH_VARARGS, NULL },
    { "GetActionMode",                  bex_ent_GetActionMode,              METH_VARARGS, NULL },
    { "StartGrabbing",                  bex_ent_StartGrabbing,              METH_VARARGS, NULL },
    { "StopGrabbing",                   bex_ent_StopGrabbing,               METH_VARARGS, NULL },
    { "LookAt",                         bex_ent_LookAt,                     METH_VARARGS, NULL },
    { "LookAtPerson",                   bex_ent_LookAtPerson,               METH_VARARGS, NULL },
    { "AddAnmEventFunc",                bex_ent_AddAnmEventFunc,            METH_VARARGS, NULL },
    { "DelAnmEventFunc",                bex_ent_DelAnmEventFunc,            METH_VARARGS, NULL },
    { "ClearAnmEventFuncs",             bex_ent_ClearAnmEventFuncs,         METH_VARARGS, NULL },
    { "AddAnimSound",                   bex_ent_AddAnimSound,               METH_VARARGS, NULL },
    { "AddEventSound",                  bex_ent_AddEventSound,              METH_VARARGS, NULL },
    { "SlideTo",                        bex_ent_SlideTo,                    METH_VARARGS, NULL },
    { "ClearPath",                      bex_ent_ClearPath,                  METH_VARARGS, NULL },
    { "StartPath",                      bex_ent_StartPath,                  METH_VARARGS, NULL },
    { "GoToPath",                       bex_ent_GoToPath,                   METH_VARARGS, NULL },
    { "TurnOn",                         bex_ent_TurnOn,                     METH_VARARGS, NULL },
    { "TurnOff",                        bex_ent_TurnOff,                    METH_VARARGS, NULL },
    { "AddPathNode",                    bex_ent_AddPathNode,                METH_VARARGS, NULL },
    { "SetNodeStartTangent",            bex_ent_SetNodeStartTangent,        METH_VARARGS, NULL },
    { "SetNodeEndTangent",              bex_ent_SetNodeEndTangent,          METH_VARARGS, NULL },
    { "Rotate",                         bex_ent_Rotate,                     METH_VARARGS, NULL },
    { "RotateAbs",                      bex_ent_RotateAbs,                  METH_VARARGS, NULL },
    { "RotateRel",                      bex_ent_RotateRel,                  METH_VARARGS, NULL },
    { "Move",                           bex_ent_Move,                       METH_VARARGS, NULL },
    { "SetPosition",                    bex_ent_SetPosition,                METH_VARARGS, NULL },
    { "SetOrientation",                 bex_ent_SetOrientation,             METH_VARARGS, NULL },
    { "PutToWorld",                     bex_ent_PutToWorld,                 METH_VARARGS, NULL },
    { "GetInventoryEntity",             bex_ent_GetInventoryEntity,         METH_VARARGS, NULL },
    { "GetInventorySelected",           bex_ent_GetInventorySelected,       METH_VARARGS, NULL },
    { "GetInventory",                   bex_ent_GetInventory,               METH_VARARGS, NULL },
    { "Use",                            bex_ent_Use,                        METH_VARARGS, NULL },
    { "SetSound",                       bex_ent_SetSound,                   METH_VARARGS, NULL },
    { "SetObjectSound",                 bex_ent_SetObjectSound,             METH_VARARGS, NULL },
    { "PlaySound",                      bex_ent_PlaySound,                  METH_VARARGS, NULL },
    { "StopSound",                      bex_ent_StopSound,                  METH_VARARGS, NULL },
    { "Stop",                           bex_ent_StopSound,                  METH_VARARGS, NULL },
    { "MessageEvent",                   bex_ent_MessageEvent,               METH_VARARGS, NULL },
    { "Rel2AbsPoint",                   bex_ent_Rel2AbsPoint,               METH_VARARGS, NULL },
    { "Rel2AbsVector",                  bex_ent_Rel2AbsVector,              METH_VARARGS, NULL },
    { "Abs2RelPoint",                   bex_ent_Abs2RelPoint,               METH_VARARGS, NULL },
    { "Abs2RelVector",                  bex_ent_Abs2RelVector,              METH_VARARGS, NULL },
    { "GetDummyAxis",                   bex_ent_GetDummyAxis,               METH_VARARGS, NULL },
    { "SQDistance2",                    bex_ent_SQDistance2,                METH_VARARGS, NULL },
    { "CatchOnFire",                    bex_ent_CatchOnFire,                METH_VARARGS, NULL },
    { "ExcludeHitFor",                  bex_ent_ExcludeHitFor,              METH_VARARGS, NULL },
    { "Unlink",                         bex_ent_Unlink,                     METH_VARARGS, NULL },
    { "Link",                           bex_ent_Link,                       METH_VARARGS, NULL },
    { "LinkToNode",                     bex_ent_LinkToNode,                 METH_VARARGS, NULL },
    { "LinkAnchors",                    bex_ent_LinkAnchors,                METH_VARARGS, NULL },
    { "GetNodeIndex",                   bex_ent_GetNodeIndex,               METH_VARARGS, NULL },
    { "GetNChildren",                   bex_ent_GetNChildren,               METH_VARARGS, NULL },
    { "GetChild",                       bex_ent_GetChild,                   METH_VARARGS, NULL },
    { "AddCameraEvent",                 bex_ent_AddCameraEvent,             METH_VARARGS, NULL },
    { "RemoveCameraEvent",              bex_ent_RemoveCameraEvent,          METH_VARARGS, NULL },
    { "AddCameraNode",                  bex_ent_AddCameraNode,              METH_VARARGS, NULL },
    { "SetCameraStartTangentNode",      bex_ent_SetCameraStartTangentNode,  METH_VARARGS, NULL },
    { "SetCameraEndTangentNode",        bex_ent_SetCameraEndTangentNode,    METH_VARARGS, NULL },
    { "SetTravellingView",              bex_ent_SetTravellingView,          METH_VARARGS, NULL },
    { "SetPersonView",                  bex_ent_SetPersonView,              METH_VARARGS, NULL },
    { "CameraClearPath",                bex_ent_CameraClearPath,            0,            NULL },
    { "CameraStartPath",                bex_ent_CameraStartPath,            0,            NULL },
    { "SetMaxCamera",                   bex_ent_SetMaxCamera,               METH_VARARGS, NULL },
    { "Cut",                            bex_ent_Cut,                        METH_VARARGS, NULL },
    { "DoAction",                       bex_ent_DoAction,                   METH_VARARGS, NULL },
    { "DoActionWI",                     bex_ent_DoActionWI,                 METH_VARARGS, NULL },
    { "SetOnFloor",                     bex_ent_SetOnFloor,                 METH_VARARGS, NULL },
    { "RaiseEvent",                     bex_ent_RaiseEvent,                 METH_VARARGS, NULL },
    { "SetWoundedZone",                 bex_ent_SetWoundedZone,             METH_VARARGS, NULL },
    { "GetWoundedZone",                 bex_ent_GetWoundedZone,             METH_VARARGS, NULL },
    { "InterruptCombat",                bex_ent_InterruptCombat,            METH_VARARGS, NULL },
    { "GetGroupMembers",                bex_ent_GetGroupMembers,            METH_VARARGS, NULL },
    { "GetCombatants",                  bex_ent_GetCombatants,              METH_VARARGS, NULL },
    { "ExcludeHitInAnimationFor",       bex_ent_ExcludeHitInAnimationFor,   METH_VARARGS, NULL },
    { "TestPos",                        bex_ent_TestPos,                    METH_VARARGS, NULL },
    { "TestPosInOwnBox",                bex_ent_TestPosInOwnBox,            METH_VARARGS, NULL },
    { "UnlinkChildren",                 bex_ent_UnlinkChildren,             METH_VARARGS, NULL },
    { "SetNextAttack",                  bex_ent_SetNextAttack,              METH_VARARGS, NULL },
    { "SetAuraActive",                  bex_ent_SetAuraActive,              METH_VARARGS, NULL },
    { "SetAuraParams",                  bex_ent_SetAuraParams,              METH_VARARGS, NULL },
    { "SetAuraGradient",                bex_ent_SetAuraGradient,            METH_VARARGS, NULL },
    { "IsValid",                        bex_ent_IsValid,                    METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A010
*/

PyObject *get_entity_by_name(const char *name) {
        B_Entity *entity;
        bld_py_entity_t *entity_obj;

        entity = GetEntity(name);
        if (entity != NULL) {
                entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
                if (entity_obj != NULL) {
                        entity_obj->name = strdup(name);
                        return (PyObject *)entity_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1000A076
*/

PyObject *get_entity_by_index(int index) {
        B_Entity *entity;
        bld_py_entity_t *entity_obj;

        entity = GetEntityI(index);
        if (entity != NULL) {
                entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
                if (entity_obj != NULL) {
                        entity_obj->name = strdup(GetEntityName(entity));
                        return (PyObject *)entity_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A0E6
*/

PyObject *create_entity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
) {
        B_Entity *entity;
        bld_py_entity_t *entity_obj;

        entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (entity_obj == NULL)
                return NULL;

        entity = CreateEntity(name, kind, x, y, z, parent_class, unknown);
        if (entity == NULL)
                return NULL;

        entity_obj->name = strdup(GetEntityName(entity));
        return (PyObject *)entity_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A179
*/

PyObject *create_entity_decal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
) {
        B_Entity *entity;
        bld_py_entity_t *entity_obj;

        entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (entity_obj == NULL)
                return NULL;



        entity = CreateEntityDecal(
                name, x, y, z, i_unknown, d_unknown1, d_unknown2
        );
        if (entity == NULL)
                return NULL;

        entity_obj->name = strdup(GetEntityName(entity));
        return (PyObject *)entity_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A214
*/

PyObject *create_spark(
        const char *name, double x, double y, double z, double x_spark_dir,
        double y_spark_dir, double z_spark_dir, double d_unknown1,
        double d_unknown2, double d_unknown3, double d_unknown4,
        double d_unknown5, int i_unknown6, int i_unknown7, int i_unknown8,
        int i_unknown9, int i_unknown10, int i_unknown11, double d_unknown12,
        double d_unknown13, double d_unknown14, int i_unknown15
) {
        B_Entity *entity;
        bld_py_entity_t *entity_obj;
        point_3d_t spark_point, spark_dir;

        entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (entity_obj == NULL)
                return NULL;

        spark_dir.x = x_spark_dir;
        spark_dir.y = y_spark_dir;
        spark_dir.z = z_spark_dir;

        spark_point.x = x;
        spark_point.y = y;
        spark_point.z = z;

        entity = CreateSpark(
                name, &spark_point, &spark_dir, d_unknown1, d_unknown2,
                d_unknown3, d_unknown4, d_unknown5, i_unknown6, i_unknown7,
                i_unknown8, i_unknown9, i_unknown10, i_unknown11, d_unknown12,
                d_unknown13, d_unknown14, i_unknown15
        );
        if (entity == NULL)
                return NULL;

        entity_obj->name = strdup(GetEntityName(entity));

        return (PyObject *)entity_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A349
*/

PyObject *bex_ent_SeverLimb(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        B_Entity *limb_entity;
        bld_py_entity_t *limb_entity_obj;
        int limb;

        if(!PyArg_ParseTuple(args, "i", &limb))
                return Py_BuildValue("i", 0);

        limb_entity = SeverLimb(entity->name, limb);
        if (limb_entity == NULL)
                return Py_BuildValue("i", 0);


        limb_entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (limb_entity_obj == NULL)
                return Py_BuildValue("i", 0);

        limb_entity_obj->name = strdup(GetEntityName(limb_entity));
        return (PyObject *)limb_entity_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A410
*/

PyObject *bex_ent_ResetWounds(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        code = ResetWounds(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A45B
*/

PyObject *bex_ent_Impulse(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                return NULL;

        code = SetEntityVectorProperty(
                entity->name, ENT_VEC_IMPULSE, 0, x, y, z
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A4E8
*/

PyObject *bex_ent_ImpulseC(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z, x_vec, y_vec, z_vec;

        if (!PyArg_ParseTuple(
                args, "dddddd", &x, &y, &z, &x_vec, &y_vec, &z_vec
        ))
                return NULL;

        code = ImpulseC(entity->name, x, y, z, x_vec, y_vec, z_vec);

        return Py_BuildValue("i", code);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A57F
*/

PyObject *bex_ent_Fly(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double velocity_x, velocity_y, velocity_z;

        if (!PyArg_ParseTuple(
                args, "ddd", &velocity_x, &velocity_y, &velocity_z
        ))
                return NULL;

        code = SetEntityVectorProperty(
                entity->name, ENT_VEC_FLY_VELOCITY, 0, velocity_x, velocity_y,
                velocity_z
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A60C
*/

PyObject *bex_ent_AddCameraEvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int frame;
        PyObject *func;

        if (!PyArg_ParseTuple(args, "iO", &frame, &func))
                return NULL;

        code = AddCameraEvent(entity->name, frame, func);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A681
*/

PyObject *bex_ent_RemoveCameraEvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int frame;

        if (!PyArg_ParseTuple(args, "i", &frame))
                return NULL;

        code = DeleteCameraEvent(entity->name, frame);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A6EE
*/

PyObject *bex_ent_SubscribeToList(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *timer_name;

        if (!PyArg_ParseTuple(args, "s", &timer_name))
                return NULL;

        code = SubscribeEntityToList(entity->name, timer_name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A75B
*/

PyObject *bex_ent_MessageEvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int message_type, unknown1, unknown2;

        if (!PyArg_ParseTuple(args, "iii", &message_type, &unknown1, &unknown2))
                return NULL;

        code = MessageEvent(entity->name, message_type, unknown1, unknown2);

        return Py_BuildValue("i", code);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A7C2
*/

PyObject *bex_ent_Rel2AbsPoint(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name = NULL;
        double x_rel, y_rel, z_rel, x_abs, y_abs, z_abs;
        PyObject *tuple, *xObj, *yObj, *zObj;

        if(!PyArg_ParseTuple(
                args, "ddd|s", &x_rel, &y_rel, &z_rel, &anchor_name
        ))
                return NULL;

        if (anchor_name) {
                Rel2AbsPointN(
                        entity->name, x_rel, y_rel, z_rel, anchor_name,
                        &x_abs, &y_abs, &z_abs
                );

                tuple = PyTuple_New(3);

                xObj = PyFloat_FromDouble(x_abs);
                yObj = PyFloat_FromDouble(y_abs);
                zObj = PyFloat_FromDouble(z_abs);

                PyTuple_SET_ITEM(tuple, 0, xObj);
                PyTuple_SET_ITEM(tuple, 1, yObj);
                PyTuple_SET_ITEM(tuple, 2, zObj);

                return tuple;
        }

        Rel2AbsPoint(entity->name, x_rel, y_rel, z_rel, &x_abs, &y_abs, &z_abs);

        tuple = PyTuple_New(3);

        xObj = PyFloat_FromDouble(x_abs);
        yObj = PyFloat_FromDouble(y_abs);
        zObj = PyFloat_FromDouble(z_abs);

        PyTuple_SET_ITEM(tuple, 0, xObj);
        PyTuple_SET_ITEM(tuple, 1, yObj);
        PyTuple_SET_ITEM(tuple, 2, zObj);

        return tuple;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A95F
*/

PyObject *bex_ent_Rel2AbsVector(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name;
        double x_rel, y_rel, z_rel, x_abs, y_abs, z_abs;
        PyObject *tuple, *xObj, *yObj, *zObj;

        if (!PyArg_ParseTuple(args, "ddd", &x_rel, &y_rel, &z_rel)) {
                PyErr_Clear();

                if (!PyArg_ParseTuple(args, "ddds", &x_rel, &y_rel, &z_rel, &anchor_name))
                        return Py_BuildValue("i", 0);

                Rel2AbsVectorN(
                        entity->name, x_rel, y_rel, z_rel, anchor_name, &x_abs,
                        &y_abs, &z_abs
                );

                tuple = PyTuple_New(3);

                xObj = PyFloat_FromDouble(x_abs);
                yObj = PyFloat_FromDouble(y_abs);
                zObj = PyFloat_FromDouble(z_abs);

                PyTuple_SET_ITEM(tuple, 0, xObj);
                PyTuple_SET_ITEM(tuple, 1, yObj);
                PyTuple_SET_ITEM(tuple, 2, zObj);

                return tuple;
        }

        Rel2AbsVector(entity->name, x_rel, y_rel, z_rel, &x_abs, &y_abs, &z_abs);

        tuple = PyTuple_New(3);

        xObj = PyFloat_FromDouble(x_abs);
        yObj = PyFloat_FromDouble(y_abs);
        zObj = PyFloat_FromDouble(z_abs);

        PyTuple_SET_ITEM(tuple, 0, xObj);
        PyTuple_SET_ITEM(tuple, 1, yObj);
        PyTuple_SET_ITEM(tuple, 2, zObj);

        return tuple;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000AB25
*/

PyObject *bex_ent_Abs2RelPoint(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name = NULL;
        double x_rel, y_rel, z_rel, x_abs, y_abs, z_abs;
        PyObject *tuple, *xObj, *yObj, *zObj;

        if (!PyArg_ParseTuple(
                args, "ddd|s", &x_abs, &y_abs, &z_abs, &anchor_name
        ))
                return NULL;

        if (anchor_name) {
                Abs2RelPointN(
                        entity->name, x_abs, y_abs, z_abs, anchor_name,
                        &x_rel, &y_rel, &z_rel
                );

                tuple = PyTuple_New(3);

                xObj = PyFloat_FromDouble(x_rel);
                yObj = PyFloat_FromDouble(y_rel);
                zObj = PyFloat_FromDouble(z_rel);

                PyTuple_SET_ITEM(tuple, 0, xObj);
                PyTuple_SET_ITEM(tuple, 1, yObj);
                PyTuple_SET_ITEM(tuple, 2, zObj);

                return tuple;
        }

        Abs2RelPoint(entity->name, x_abs, y_abs, z_abs, &x_rel, &y_rel, &z_rel);

        tuple = PyTuple_New(3);

        xObj = PyFloat_FromDouble(x_rel);
        yObj = PyFloat_FromDouble(y_rel);
        zObj = PyFloat_FromDouble(z_rel);

        PyTuple_SET_ITEM(tuple, 0, xObj);
        PyTuple_SET_ITEM(tuple, 1, yObj);
        PyTuple_SET_ITEM(tuple, 2, zObj);

        return tuple;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000ACC2
*/

PyObject *bex_ent_Abs2RelVector(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name = NULL;
        double x_rel, y_rel, z_rel, x_abs, y_abs, z_abs;
        PyObject *tuple, *xObj, *yObj, *zObj;
        PyObject *coordinates = NULL;

        if (
                PyArg_ParseTuple(args, "ddd", &x_abs, &y_abs, &z_abs) ||
                (PyArg_ParseTuple(args, "O", &coordinates) &&
                 PyArg_ParseTuple(coordinates, "ddd", &x_abs, &y_abs, &z_abs))
        ) {
                Abs2RelVector(
                        entity->name, x_abs, y_abs, z_abs, &x_rel, &y_rel,
                        &z_rel
                );

                tuple = PyTuple_New(3);

                xObj = PyFloat_FromDouble(x_rel);
                yObj = PyFloat_FromDouble(y_rel);
                zObj = PyFloat_FromDouble(z_rel);

                PyTuple_SET_ITEM(tuple, 0, xObj);
                PyTuple_SET_ITEM(tuple, 1, yObj);
                PyTuple_SET_ITEM(tuple, 2, zObj);

                return tuple;
        }

        PyErr_Clear();

        if (
                PyArg_ParseTuple(args, "ddds", &x_abs, &y_abs, &z_abs, &anchor_name) ||
                (PyArg_ParseTuple(args, "Os", &coordinates, &anchor_name) &&
                 PyArg_ParseTuple(coordinates, "ddd", &x_abs, &y_abs, &z_abs))
        ) {
                Abs2RelVectorN(
                        entity->name, x_abs, y_abs, z_abs, anchor_name, &x_rel,
                        &y_rel, &z_rel
                );

                tuple = PyTuple_New(3);

                xObj = PyFloat_FromDouble(x_rel);
                yObj = PyFloat_FromDouble(y_rel);
                zObj = PyFloat_FromDouble(z_rel);

                PyTuple_SET_ITEM(tuple, 0, xObj);
                PyTuple_SET_ITEM(tuple, 1, yObj);
                PyTuple_SET_ITEM(tuple, 2, zObj);

                return tuple;
        }

        return Py_BuildValue("i", 0);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000AF0C
*/

PyObject *bex_ent_GetDummyAxis(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name;
        double x_dir, y_dir, z_dir, x_dummy_axis, y_dummy_axis, z_dummy_axis;
        PyObject *tuple, *xObj, *yObj, *zObj;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "sddd|i", &anchor_name, &x_dir, &y_dir, &z_dir, &unknown
        ))
                return NULL;

        GetDummyAxis(
                entity->name, anchor_name, x_dir, y_dir, z_dir, &x_dummy_axis,
                &y_dummy_axis, &z_dummy_axis, unknown
        );

        tuple = PyTuple_New(3);

        xObj = PyFloat_FromDouble(x_dummy_axis);
        yObj = PyFloat_FromDouble(y_dummy_axis);
        zObj = PyFloat_FromDouble(z_dummy_axis);

        PyTuple_SET_ITEM(tuple, 0, xObj);
        PyTuple_SET_ITEM(tuple, 1, yObj);
        PyTuple_SET_ITEM(tuple, 2, zObj);

        return tuple;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B003
*/

PyObject *bex_ent_SQDistance2(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity1 = (bld_py_entity_t *)self;
        bld_py_entity_t *entity2 = NULL;

        if (!PyArg_ParseTuple(args, "O", &entity2))
                return NULL;

        return PyFloat_FromDouble(SQDistance2(entity1->name, entity2->name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B069
*/

PyObject *bex_ent_RemoveFromList(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *timer_name;

        if (!PyArg_ParseTuple(args, "s", &timer_name))
                return NULL;

        code = RemoveEntityFromList(entity->name, timer_name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B0D6
*/

PyObject *bex_ent_RemoveFromInvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *obj_name;

        if (!PyArg_ParseTuple(args, "s", &obj_name))
                return NULL;

        code = RemoveFromInvent(entity->name, obj_name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B145
*/

PyObject *bex_ent_RemoveFromInventRight(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = RemoveFromInventRight(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B1AA
*/

PyObject *bex_ent_RemoveFromInventLeft(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = RemoveFromInventLeft(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B20F
*/

PyObject *bex_ent_RemoveFromInventLeft2(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = RemoveFromInventLeft2(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B274
*/

PyObject *bex_ent_LaunchAnimation(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_name;

        if (!PyArg_ParseTuple(args, "s", &anm_name))
                return NULL;


        code = SetEntityStringProperty(
                entity->name, ENT_STR_ANIM_FULL_NAME, 0, anm_name
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B2E7
*/

PyObject *bex_ent_LaunchAnimation2(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_name1, *anm_name2;

        if (!PyArg_ParseTuple(args, "ss", &anm_name1, &anm_name2))
                return NULL;

        code = LaunchAnimation2(entity->name, anm_name1, anm_name2);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}



/*
* Module:                 Bladex.dll
* Entry point:            0x1000B35E
*/

PyObject *bex_ent_LaunchAnmType(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_type;
        int index = 0;

        if (!PyArg_ParseTuple(args, "s|i", &anm_type, &index))
                return NULL;

        code = SetEntityStringProperty(
                entity->name, ENT_STR_ANIM_NAME, index, anm_type
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B3DE
*/

PyObject *bex_ent_GotAnmType(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_type;

        if (!PyArg_ParseTuple(args, "s", &anm_type))
                return NULL;

        code = SetEntityStringProperty(
                entity->name, ENT_STR_GOT_ANM_TYPE, 0, anm_type
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B451
*/

PyObject *bex_ent_SetMesh(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *mesh;

        if (!PyArg_ParseTuple(args, "s", &mesh))
                return NULL;

        code = SetEntityStringProperty(entity->name, ENT_STR_MESH, 0, mesh);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B4C4
*/

PyObject *bex_ent_SetTmpAnmFlags(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int wuea, mod_y, solf, copy_rot, bng_mov, headf;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "iiiiii|i", &wuea, &mod_y, &solf, &copy_rot, &bng_mov,
                &headf, &unknown
        ))
                return NULL;

        code = SetTmpAnmFlags(
                entity->name, wuea, mod_y, solf, copy_rot, bng_mov, headf,
                unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B56A
*/

PyObject *bex_ent_SetAnmFlags(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int wuea, mod_y, solf, copy_rot, bng_mov, headf;
        const char *anm_name;

        if (!PyArg_ParseTuple(
                args, "siiiiii", &anm_name, &wuea, &mod_y, &solf, &copy_rot,
                &bng_mov, &headf
        ))
                return NULL;

        code = SetAnmFlags(
                entity->name, anm_name, wuea, mod_y, solf, copy_rot, bng_mov,
                headf
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B609
*/

PyObject *bex_ent_SetActiveEnemy(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *active_enemy;
        const char *active_enemy_name;
        int unknown;

        if (!PyArg_ParseTuple(args, "O", &active_enemy))
                return NULL;

        active_enemy_name = NULL;
        if ( active_enemy && (active_enemy->ob_type == &entityTypeObject))
                active_enemy_name = active_enemy->name;

        code = SetActiveEnemy(entity->name, active_enemy_name, &unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", unknown);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B6A0
*/

PyObject *bex_ent_CanISee(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        bld_py_entity_t *seen_entity;
        int canISee;
        int code;
        const char *seen_entity_name;

        if (!PyArg_ParseTuple(args, "O", &seen_entity))
                return NULL;

        seen_entity_name = NULL;
        if (seen_entity != NULL)
                seen_entity_name = seen_entity->name;

        code = CanISee(entity->name, seen_entity_name, &canISee);
        if (code != 1)
                return Py_BuildValue("i", 0);

        return Py_BuildValue("i", canISee);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B72B
*/

PyObject *bex_ent_CanISeeFrom(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        bld_py_entity_t *seen_entity;
        int canISee;
        int code;
        const char *seen_entity_name;
        double x, y, z;

        if (!PyArg_ParseTuple(args, "Oddd", &seen_entity, &x, &y, &z))
                return NULL;

        seen_entity_name = NULL;
        if (seen_entity != NULL)
                seen_entity_name = seen_entity->name;

        code = CanISeeFrom(entity->name, seen_entity_name, x, y, z, &canISee);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", canISee);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B7DA
*/

PyObject *bex_ent_ExcludeHitFor(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        bld_py_entity_t *exclude_for_entity;
        void *unknown;
        int code;

        if(!PyArg_ParseTuple(args, "O", &exclude_for_entity))
                return NULL;

        if (exclude_for_entity && (PyObject *)exclude_for_entity != Py_None)
                code = ExcludeHitFor(
                        entity->name, exclude_for_entity->name, &unknown
                );
        else
                code = -1;

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B877
*/

PyObject *bex_ent_ExcludeHitInAnimationFor(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        bld_py_entity_t *exclude_for_entity;
        void *unknown;
        int code;

        if (!PyArg_ParseTuple(args, "O", &exclude_for_entity))
                return NULL;

        if (exclude_for_entity && (PyObject *)exclude_for_entity != Py_None)
                code = ExcludeHitInAnimationFor(
                        entity->name, exclude_for_entity->name, &unknown
                );
        else
                code = -1;

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B914
*/

PyObject *bex_ent_Unlink(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *child;
        void *unknown;

        if (!PyArg_ParseTuple(args, "O", &child))
                return NULL;

        if (child == NULL)
                code = -1;
        else
                code = UnlinkChild(entity->name, child->name, &unknown);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B9A6
*/

PyObject *bex_ent_Link(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *child;
        void *unknown;

        if (!PyArg_ParseTuple(args, "O", &child))
                return NULL;

        if (child == NULL)
                code = -1;
        else
                code = Link(entity->name, child->name, &unknown);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BA38
*/

PyObject *bex_ent_LinkAnchors(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;/* FIXME uninitialised code */
        const char *entity_anchor, *child_anchor;
        bld_py_entity_t *child;
        void *unknown;

        if (PyArg_ParseTuple(args, "sOs", &entity_anchor, &child, &child_anchor)) {
                if (child == NULL)
                        code = -1;
                else
                        code = LinkAnchors(
                                entity->name, entity_anchor, child->name,
                                child_anchor, &unknown
                        );
        }

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BAD4
*/

PyObject *bex_ent_LinkToNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node_index;
        bld_py_entity_t *child;
        void *unknown;

        if (!PyArg_ParseTuple(args, "Oi", &child, &node_index))
                return NULL;

        if (child)
                code = LinkToNode(
                        entity->name, child->name, node_index, &unknown
                );
        else
                code = -1;

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BB6E
*/

PyObject *bex_ent_GetNodeIndex(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *node_name;
        int index = -1;

        if (!PyArg_ParseTuple(args, "s", &node_name))
                return NULL;

        GetNodeIndex(entity->name, node_name, &index);

        return Py_BuildValue("i", index);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BBD9
*/

PyObject *bex_ent_GetNChildren(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetNChildren(entity->name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BC31
*/

PyObject *bex_ent_GetChild(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int index;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        return Py_BuildValue("s", GetChild(entity->name, index));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BC8A
*/

PyObject *bex_ent_InsideActionArea(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_area, is_inside;

        if (!PyArg_ParseTuple(args, "i", &action_area))
                return NULL;

        code = InsideActionArea(entity->name, action_area, &is_inside);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", is_inside);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BCFF
*/

PyObject *bex_ent_CheckAnimCol(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_name, *obj_name;
        bld_py_entity_t *obj;
        int unknown, res;

        if (!PyArg_ParseTuple(args, "sOi", &anm_name, &obj, &unknown))
                return NULL;

        obj_name = NULL;
        if (obj)
                obj_name = obj->name;

        code = CheckAnimCol(entity->name, anm_name, obj_name, unknown, &res);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", res);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BD9A
*/

PyObject *bex_ent_TestPos(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z;
        int action_area = 0;
        double max_fall = BLD_MAX_DOUBLE;
        int is_correct;

        if (!PyArg_ParseTuple(
                args, "ddd|id", &x, &y, &z, &action_area, &max_fall
        ))
                return NULL;

        code = TestPos(
                entity->name, x, y, z, max_fall, action_area, &is_correct
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", is_correct);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BED4
*/

PyObject *bex_ent_TestPosInOwnBox(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z, box_size = 1.0;
        int is_correct;

        if (!PyArg_ParseTuple(args, "ddd|d", &x, &y, &z, &box_size))
                return NULL;

        code = TestPosInOwnBox(entity->name, x, y, z, box_size, &is_correct);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", is_correct);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BFFB
*/

PyObject *bex_ent_UnlinkChildren(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = UnlinkChilds(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C067
*/

PyObject *bex_ent_SetNextAttack(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *attack;
        int res;

        if (!PyArg_ParseTuple(args, "s", &attack))
                return NULL;

        code = SetNextAttack(entity->name, attack, &res);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", res);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C0E3
*/

PyObject *bex_ent_SetEnemy(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *enemy;
        const char *enemy_name;

        if (!PyArg_ParseTuple(args, "O", &enemy))
                return NULL;

        enemy_name = NULL;
        if (enemy != NULL)
                enemy_name = enemy->name;

        code = SetEnemy(entity->name, enemy_name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C168
*/

PyObject *bex_ent_GetEnemyName(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *enemy_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        enemy_name = GetEnemy(entity->name);
        if (enemy_name == NULL)
                return PyString_FromString("");

        return PyString_FromString(enemy_name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C1C8
*/

PyObject *bex_ent_Chase(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *enemy;
        const char *enemy_name;
        int action_area;

        if (!PyArg_ParseTuple(args, "Oi", &enemy, &action_area))
                return NULL;

        enemy_name = NULL;
        if (enemy != NULL)
                enemy_name = enemy->name;

        code = Chase(entity->name, enemy_name, action_area);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);

}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C255
*/

PyObject *bex_ent_ResetChase(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = ResetChase(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C2BA
*/

PyObject *bex_ent_GoTo(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int x, y, z;

        if (!PyArg_ParseTuple(args, "iii", &x, &y, &z))
                return NULL;

        code = GoTo(entity->name, x, y, z);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C339
*/

PyObject *bex_ent_CanGoTo(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int x, y, z;

        if (!PyArg_ParseTuple(args, "iii", &x, &y, &z))
                return NULL;

        code = CanGoTo(entity->name, x, y, z);
        if (code != 1) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C3B8
*/

PyObject *bex_ent_LookAtEntity(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *look_at_entity_name;

        if (!PyArg_ParseTuple(args, "s", &look_at_entity_name))
                return NULL;

        code = LookAtEntity(entity->name, look_at_entity_name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C427
*/

PyObject *bex_ent_QuickFace(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double angle;

        if (!PyArg_ParseTuple(args, "d", &angle))
                return NULL;

        code = QuickFace(entity->name, angle);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C49A
*/

PyObject *bex_ent_Face(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double angle;

        if (!PyArg_ParseTuple(args, "d", &angle))
                return NULL;

        code = Face(entity->name, angle);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C50D
*/

PyObject *bex_ent_StartLooking(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int x, y, z;

        if (!PyArg_ParseTuple(args, "iii", &x, &y, &z))
                return NULL;

        code = StartLooking(entity->name, x, y, z);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C58C
*/

PyObject *bex_ent_StopLooking(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;


        code = StopLooking(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C5F1
*/

PyObject *bex_ent_AddWatchAnim(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_name;

        if (!PyArg_ParseTuple(args, "s", &anm_name))
                return NULL;

        code = AddEntWatchAnim(entity->name, anm_name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C660
*/

PyObject *bex_ent_GraspPos(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *grasp;
        double x, y, z;
        PyObject *tuple, *xObj, *yObj, *zObj;

        if (!PyArg_ParseTuple(args, "s", &grasp))
                return NULL;

        code = GraspPos(entity->name, grasp, &x, &y, &z);
        if (code != 1)
                return Py_BuildValue("i", 0);

        tuple = PyTuple_New(3);
        xObj = PyFloat_FromDouble(x);
        yObj = PyFloat_FromDouble(y);
        zObj = PyFloat_FromDouble(z);
        PyTuple_SetItem(tuple, 0, xObj);
        PyTuple_SetItem(tuple, 1, yObj);
        PyTuple_SetItem(tuple, 2, zObj);

        return tuple;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C785
*/

PyObject *bex_ent_Freeze(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = Freeze(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C7EA
*/

PyObject *bex_ent_UnFreeze(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = UnFreeze(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C84F
*/

PyObject *bex_ent_SwitchTo1H(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = SwitchTo1H(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C8B4
*/

PyObject *bex_ent_SwitchToBow(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = SwitchToBow(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C919
*/

PyObject *bex_ent_LaunchBayRoute(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;


        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = LaunchBayRoute(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C97E
*/

PyObject *bex_ent_LaunchWatch(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = LaunchWatch(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C9E3
*/

PyObject *bex_ent_GetActionMode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_mode;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = GetActionMode(entity->name, &action_mode);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", action_mode);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CA4E
*/

PyObject *bex_ent_StartGrabbing(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = StartGrabbing(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CAB3
*/

PyObject *bex_ent_StopGrabbing(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = StopGrabbing(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CB18
*/

PyObject *bex_ent_LookAt(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *obj_name;
        double x, y, z;

        if (PyArg_ParseTuple(args, "s", &obj_name)) {
                code = SetEntityStringProperty(
                        entity->name, ENT_STR_LOOK_AT, 0, obj_name
                );
        } else {
                PyErr_Clear();
                if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                        return NULL;

                code = SetEntityVectorProperty(
                        entity->name, ENT_VEC_LOOK_AT_COORD, 0, x, y, z
                );
        }

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CBE2
*/

PyObject *bex_ent_LookAtPerson(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *person_name;

        if (!PyArg_ParseTuple(args, "s", &person_name))
                return NULL;

        code = SetEntityStringProperty(
                entity->name, ENT_STR_LOOK_AT_PERSON, 0, person_name
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CC55
*/

PyObject *bex_ent_AddAnimSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *animation;
        bld_py_sound_t *sound;
        double time;

        if (!PyArg_ParseTuple(args, "sOd", &animation, &sound, &time)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        if (sound->ob_type != &soundTypeObject) {
                PyErr_SetString(
                        PyExc_AttributeError, "Invalid Param: Not a sound."
                );
                return NULL;
        }

        code = AddSoundAnim(entity->name, animation, time, sound->sound);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CD17
*/

PyObject *bex_ent_AddAnmEventFunc(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_event;
        PyObject *func;

        if (!PyArg_ParseTuple(args, "sO", &anm_event, &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        code = EntityAddAnmEventFunc(entity->name, anm_event, func);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CDA3
*/

PyObject *bex_ent_DelAnmEventFunc(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_event;

        if (!PyArg_ParseTuple(args, "s", &anm_event)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        code = EntityDelAnmEventFunc(entity->name, anm_event);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CE26
*/

PyObject *bex_ent_ClearAnmEventFuncs(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = EntityClearAnmEventFuncs(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CE8B
*/

PyObject *bex_ent_AddEventSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *event_name;
        bld_py_sound_t *sound;

        if (!PyArg_ParseTuple(args, "sO", &event_name, &sound)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        if (sound->ob_type != &soundTypeObject) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param: Not a sound.");
                return NULL;
        }

        code = AddSoundEvent(entity->name, event_name, sound->sound);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CF41
*/

PyObject *bex_ent_SlideTo(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double displacement, velocity, unknown;

        if (!PyArg_ParseTuple(args, "ddd", &displacement, &velocity, &unknown))
                return NULL;

        code = SetEntityVectorProperty(
                entity->name, ENT_VEC_SLIDE_TO, 0, displacement, velocity, unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CFCE
*/

PyObject *bex_ent_ClearPath(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = ClearActorPath(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D033
*/

PyObject *bex_ent_CameraClearPath(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node;

        if (!PyArg_Parse(args, "i", &node))
                return NULL;

        code = CameraClearPath(entity->name, node);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D0A0
*/

PyObject *bex_ent_CameraStartPath(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node;

        if (!PyArg_Parse(args, "i", &node))
                return NULL;

        code = CameraStartPath(entity->name, node);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D10D
*/

PyObject *bex_ent_AddPathNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double time, x, y, z;

        if (!PyArg_ParseTuple(args, "dddd", &time, &x, &y, &z))
                return NULL;

        code = AddActorPathnode(entity->name, time, x,  y, z);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D1A2
*/

PyObject *bex_ent_StartPath(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = StartActorPath(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D207
*/

PyObject *bex_ent_GoToPath(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int i_unknown;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "id", &i_unknown, &d_unknown))
                return NULL;

        code = GoToActorPath(entity->name, i_unknown, d_unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D280
*/

PyObject *bex_ent_TurnOn(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = TurnOnActor(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D2E5
*/

PyObject *bex_ent_TurnOff(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = TurnOffActor(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D34A
*/

PyObject *bex_ent_SetNodeStartTangent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int unknown1;
        double unknown2, unknown3, unknown4;

        if (!PyArg_ParseTuple(
                args, "iddd", &unknown1, &unknown2, &unknown3, &unknown4
        ))
                return NULL;

        code = SetActorNodeStartTangent(
                entity->name, unknown1, unknown2, unknown3, unknown4
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D3DB
*/

PyObject *bex_ent_SetNodeEndTangent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int unknown1;
        double unknown2, unknown3, unknown4;

        if (!PyArg_ParseTuple(
                args, "iddd", &unknown1, &unknown2, &unknown3, &unknown4
        ))
                return NULL;

        code = SetActorNodeEndTangent(
                entity->name, unknown1, unknown2, unknown3, unknown4
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D46C
*/

PyObject *bex_ent_AddCameraNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node;
        double time, x, y, z;

        if (!PyArg_ParseTuple(args, "idddd", &node, &time, &x, &y, &z))
                return NULL;

        if (node != 0)
                code = CameraAddTargetNode(entity->name, time, x, y, z);
        else
                code = CameraAddSourceNode(entity->name, time, x, y, z);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D5FA
*/

PyObject *bex_ent_SetCameraStartTangentNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node, unknown1;
        double unknown2, unknown3, unknown4;

        if (! PyArg_ParseTuple(
                args, "iiddd", &node, &unknown1, &unknown2, &unknown3, &unknown4
        ))
                return NULL;

        if (node != 0)
                code = CameraSetStartTangentTargetNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );
        else
                code = CameraSetStartTangentSourceNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D769
*/

PyObject *bex_ent_SetCameraEndTangentNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code = 1;
        int node, unknown1;
        double unknown2, unknown3, unknown4;

        if (!PyArg_ParseTuple(
                args, "iiddd", &node, &unknown1, &unknown2, &unknown3, &unknown4
        ))
                return NULL;

        if (node != 0)
                CameraSetEndTangentTargetNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );
        else
                CameraSetEndTangentSourceNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D8D2
*/

PyObject *bex_ent_SetPersonView(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *person_name;

        if (!PyArg_ParseTuple(args, "s", &person_name))
                return NULL;

        code = CameraSetPersonView(entity->name, person_name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D93F
*/

PyObject *bex_ent_SetMaxCamera(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *cam_file_name;
        int i_unknown, num_frames;

        if (!PyArg_ParseTuple(args, "sii", &cam_file_name, &i_unknown, &num_frames))
                return NULL;

        code = CameraSetMaxCamera(entity->name, cam_file_name, i_unknown, num_frames);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D9BC
*/

PyObject *bex_ent_Cut(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = CameraCut(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DA21
*/

PyObject *bex_ent_SetTravellingView(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int unknown1, unknown2;

        if (!PyArg_ParseTuple(args, "ii", &unknown1, &unknown2))
                return NULL;

        code = CameraSetTravelingView(entity->name, unknown1, unknown2);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DA96
*/

PyObject *bex_ent_Rotate(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x_dir, y_dir, z_dir, velocity;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "dddd|i", &x_dir, &y_dir, &z_dir, &velocity, &unknown
        ))
                return NULL;

        code = EntityRotate(
                entity->name, x_dir, y_dir, z_dir, velocity, unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DB3A
*/

PyObject *bex_ent_RotateAbs(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z, x_dir, y_dir, z_dir, angle;
        int i_unknown = 1;

        if (!PyArg_ParseTuple(
                args, "ddddddd|i", &x, &y, &z, &x_dir, &y_dir, &z_dir, &angle,
                &i_unknown
        ))
                return NULL;

        code = EntityRotateAbs(
                entity->name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DC02
*/

PyObject *bex_ent_RotateRel(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z, x_dir, y_dir, z_dir, angle;
        int i_unknown = 1;

        if (!PyArg_ParseTuple(
                args, "ddddddd|i", &x, &y, &z, &x_dir, &y_dir, &z_dir, &angle,
                &i_unknown
        ))
                return NULL;

        code = EntityRotateRel(
                entity->name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DCCA
*/

PyObject *bex_ent_Move(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z;
        int unknown = 1;

        if (!PyArg_ParseTuple(args, "ddd|i", &x, &y, &z, &unknown))
                return NULL;

        code = EntityMove(entity->name, x, y, z, unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DD62
*/

PyObject *bex_ent_SetPosition(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z;
        int unknown = 1;

        if (!PyArg_ParseTuple(args, "ddd|i", &x, &y, &z, &unknown))
                return NULL;

        code = EntitySetPosition(entity->name, x, y, z, unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DDFA
*/

PyObject *bex_ent_SetOrientation(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double quat1, quat2, quat3, quat4;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "dddd|i", &quat1, &quat2, &quat3, &quat4, &unknown
        ))
                return NULL;

        code = EntitySetOrientation(
                entity->name, quat1, quat2, quat3, quat4, unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DE9E
*/

PyObject *bex_ent_GetGroupMembers(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *members;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        members = GetGroupMembers(entity->name);
        if (members == NULL)
                return Py_BuildValue("i", 0);

        return members;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DEF6
*/

PyObject *bex_ent_GetCombatants(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *combatants;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        combatants = GetCombatants(entity->name);
        if (combatants == NULL) {
                return Py_BuildValue("i", 0);
        }

        return combatants;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DF4E
*/

PyObject *bex_ent_PutToWorld(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = EntityPutToWorld(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DFB3
*/

PyObject *bex_ent_GetInventoryEntity(PyObject * self, PyObject * args) {
        assert(NULL);
        return NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DFD8
*/

PyObject *bex_ent_GetInventorySelected(PyObject * self, PyObject * args) {
        assert(NULL);
        return NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DFFD
*/

PyObject *bex_ent_GetInventory(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *inventory;
        const char *name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = GetEntityStringProperty(entity->name, ENT_STR_NAME, 0, &name);
        if ((code != 1) || (inventory = get_inventory(name)) == NULL) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Entity.");
                return NULL;
        }

        return inventory;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E081
*/

PyObject *bex_ent_RemoveFromWorld(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        EntityRemoveFromWorld(entity->name);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E0C9
*/

PyObject *bex_ent_RemoveFromWorldWithChilds(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        EntityRemoveFromWorldWithChilds(entity->name);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E111
*/

PyObject *bex_ent_Use(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = UseEntity(entity->name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E17D
*/

PyObject *bex_ent_SetSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *sound;
        int code;

        if (!PyArg_ParseTuple(args, "s", &sound))
                return NULL;

        code = SetSound(entity->name, sound);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E1EA
*/

PyObject *bex_ent_SetObjectSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *sound;
        int code;

        if (!PyArg_ParseTuple(args, "s", &sound))
                return NULL;

        code = SetObjectSound(entity->name, sound);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E257
*/

PyObject *bex_ent_PlaySound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i_unknown = -1;
        int code;

        if (!PyArg_ParseTuple(args, "|i", &i_unknown))
                return NULL;

        code = PlayEntitySound(entity->name, i_unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E2CB
*/

PyObject *bex_ent_StopSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double x, y, z;
        int code;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z)) {
                PyErr_Clear();
                if (!PyArg_ParseTuple(args, ""))
                        return NULL;

                code = Stop(entity->name);

        } else
                code = StopAt(entity->name, x, y, z);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E385
*/

PyObject *bex_ent_CatchOnFire(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double x, y, z;
        int code;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                return NULL;

        code = EntityCatchOnFire(entity->name, x, y, z);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E40E
*/

PyObject *bex_ent_GetParticleEntity(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *particle_entity_name;
        bld_py_entity_t *particle_entity;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        particle_entity = PyObject_NEW(bld_py_entity_t, &entityTypeObject);

        particle_entity_name = GetParticleEntity(entity->name);
        if (particle_entity_name == NULL)
                return Py_BuildValue("i", 0);

        particle_entity->name = strdup(particle_entity_name);

        return (PyObject *)particle_entity;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E49B
*/

PyObject *bex_ent_DoAction(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *action_name;
        int code;

        if (!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        code = DoAction(entity->name, action_name);

        return Py_BuildValue("i", code);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E4F2
*/

PyObject *bex_ent_DoActionWI(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *action_name;
        int interpolation_type;
        double time, unknown1 = 0.0;
        int code;

        if (!PyArg_ParseTuple(
                args, "sid|d", &action_name, &interpolation_type, &time,
                &unknown1
        ))
                return NULL;

        code = DoActionWI(
                entity->name, action_name, interpolation_type, time,
                unknown1
        );

        return Py_BuildValue("i", code);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E577
*/

PyObject *bex_ent_SetOnFloor(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", SetOnFloor(entity->name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E5C6
*/

PyObject *bex_ent_RaiseEvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *event_name;

        if (!PyArg_ParseTuple(args, "s", &event_name))
                return Py_BuildValue("i", 0);

        return Py_BuildValue("i", RaiseEvent(entity->name, event_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E62B
*/

PyObject *bex_ent_SetWoundedZone(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int zone, is_active;

        if (!PyArg_ParseTuple(args, "ii", &zone, &is_active))
                return NULL;

        code = SetEntityIntProperty(
                entity->name, ENT_INT_WOUNDED_ZONES, zone, is_active
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E6A2
*/

PyObject *bex_ent_InterruptCombat(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        code = InterruptCombat(entity->name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E6ED
*/

PyObject *bex_ent_GetWoundedZone(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int zone, is_active;
        char buffer[512];

        if (PyArg_ParseTuple(args, "i", &zone)) {
                code = GetEntityIntProperty(
                        entity->name, ENT_INT_WOUNDED_ZONES, zone, &is_active
                );
                if (code == 1)
                        return PyInt_FromLong(is_active);

                if (code == -2) {
                        sprintf(
                                buffer,
                                "Unsupported error in BLADE_Entity_GetWoundedZone..."
                        );
                        PyErr_SetString(PyExc_AttributeError, buffer);
                        /*FIXME should be return*/
                }
        }

        PyErr_SetString(PyExc_AttributeError, "BLADE_Entity_GetWoundedZone");
        return NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E798
*/

PyObject *bex_ent_SetAuraActive(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_active;

        if (!PyArg_ParseTuple(args, "i", &is_active))
                return NULL;

        code = SetAuraActive(entity->name, is_active);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}



/*
* Module:                 Bladex.dll
* Entry point:            0x1000E805
*/

PyObject *bex_ent_SetAuraParams(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double size, alpha, colour_intensity;
        int hide_front_faces, hide_back_faces, alpha_mode;

        if (!PyArg_ParseTuple(
                args, "dddiii", &size, &alpha, &colour_intensity,
                &hide_front_faces, &hide_back_faces, &alpha_mode
        ))
                return NULL;

        code = SetAuraParams(
                entity->name, size, alpha, colour_intensity, hide_front_faces,
                hide_back_faces, alpha_mode
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E8A6
*/

PyObject *bex_ent_SetAuraGradient(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int gap;
        double r1, g1, b1, alpha1, starting_point;
        double r2, g2, b2, alpha2, ending_point;

        if (!PyArg_ParseTuple(
                args, "idddddddddd", &gap, &r1, &g1, &b1, &alpha1,
                &starting_point, &r2, &g2, &b2, &alpha2, &ending_point
        ))
                return NULL;

        code = SetAuraGradient(
                entity->name, gap, r1, g1, b1, alpha1, starting_point,
                r2, g2, b2, alpha2, ending_point
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E98E
*/

PyObject *bex_ent_IsValid(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i",  IsValidEntity(entity->name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E9DD
*/

void init_entity_properties() {
        property_kinds = (property_info_t *)malloc(
                MAX_PROPERTY_KINDS * sizeof(property_info_t)
        );
        insert_property("Data",                   -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Data_get                  , bex_ent_Data_set);
        insert_property("__doc__",                -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_doc_get                   , NULL);
        insert_property("Name",                   ENT_STR_NAME                    , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Kind",                   ENT_STR_KIND                    , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("SendSectorMsgs",         ENT_INT_SEND_SECTOR_MSGS        , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SendTriggerSectorMsgs",  ENT_INT_SEND_TRIGGER_SECTOR_MSGS, PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Scale",                  ENT_FLT_SCALE                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Position",               ENT_VEC_POSITION                , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("D",                      ENT_VEC_D                       , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("D1",                     ENT_VEC_D1                      , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("D2",                     ENT_VEC_D2                      , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Velocity",               ENT_VEC_VELOCITY                , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Gravity",                ENT_VEC_GRAVITY                 , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AngularVelocity",        ENT_VEC_ANGULAR_VELOCITY        , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Life",                   ENT_FLT_LIFE                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Energy",                 ENT_FLT_ENERGY                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Level",                  ENT_INT_LEVEL                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PartialLevel",           ENT_INT_PARTIAL_LEVEL           , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InAttack",               ENT_INT_IN_ATTACK               , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InDestructorAttack",     ENT_INT_IN_DESTRUCTOR_ATTACK    , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("CombatDistFlag",         ENT_INT_COMBAT_DIST_FLAG        , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
/* FIXME two "Angle" properties */
        insert_property("Angle",                  ENT_FLT_ANGLE                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("T2Fall",                 ENT_FLT_T2_FALL                 , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Flick",                  ENT_INT_FLICK                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Intensity2",             ENT_FLT_INTENSITY2              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FlickPeriod",            ENT_FLT_FLICK_PERIOD            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("LookAtTime",             ENT_FLT_LOOK_AT_TIME            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Mass",                   ENT_FLT_MASS                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TrailLifeTime",          ENT_FLT_TRAIL_LIFE_TIME         , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TrailColor",             ENT_VEC_TRAIL_COLOR             , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InventoryVisible",       ENT_INT_INVENTORY_VISIBLE       , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Visible",                ENT_INT_VISIBLE                 , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("CastShadows",            ENT_INT_CAST_SHADOWS            , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Gof",                    ENT_INT_GOF                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Gob",                    ENT_INT_GOB                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Aim",                    ENT_INT_AIM                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Tr",                     ENT_INT_TR                      , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Tl",                     ENT_INT_TL                      , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Run",                    ENT_INT_RUN                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Sneak",                  ENT_INT_SNEAK                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Attack",                 ENT_INT_ATTACK                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Block",                  ENT_INT_BLOCK                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ContinuousBlock",        ENT_INT_CONTINUOUS_BLOCK        , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Active",                 ENT_INT_ACTIVE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Target",                 ENT_VEC_TARGET                  , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MinSectorLength",        ENT_FLT_MIN_SECTOR_LENGTH       , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MaxAmplitude",           ENT_FLT_MAX_AMPLITUDE           , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Damage",                 ENT_INT_DAMAGE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DamageRadius",           ENT_FLT_DAMAGE_RADIUS           , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SimpleSections",         ENT_INT_SIMPLE_SECTIONS         , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OuterGlowColor",         ENT_VEC_OUTER_GLOW_COLOR        , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InnerGlowColor",         ENT_VEC_INNER_GLOW_COLOR        , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("CoreGlowColor",          ENT_VEC_CORE_GLOW_COLOR         , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SendNotify",             ENT_INT_SEND_NOTIFY             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Playing",                ENT_INT_PLAYING                 , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Blind",                  ENT_INT_BLIND                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Deaf",                   ENT_INT_DEAF                    , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("WillCrashInFloor",       ENT_INT_WILL_CRASH_IN_FLOOR     , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("GoToSneaking",           ENT_INT_GO_TO_SNEAKING          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("GoToJogging",            ENT_INT_GO_TO_JOGGING           , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OnFloor",                ENT_INT_ON_FLOOR                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("TestHit",                ENT_INT_TEST_HIT                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Displacement",           ENT_FLT_DISPLACEMENT            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DisplacementLimit",      ENT_FLT_DISPLACEMENT_LIMIT      , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("V_D",                    ENT_FLT_V_D                     , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("A_D",                    ENT_FLT_A_D                     , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("IsStopped",              ENT_INT_IS_STOPPED              , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Material",               ENT_STR_MATERIAL                , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Animation",              ENT_STR_ANIMATION               , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FPS",                    ENT_FLT_F_P_S                   , PROP_TYPE_FLT, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("CurrentAreas",           ENT_INT_CURRENT_AREAS           , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("CharType",               ENT_STR_CHAR_TYPE               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("CharTypeExt",            ENT_STR_CHAR_TYPE_EXT           , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Parent",                 ENT_STR_PARENT                  , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InitPos",                ENT_VEC_INIT_POS                , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("EnemyLastSeen",          ENT_VEC_ENEMY_LAST_SEEN         , PROP_TYPE_VEC, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("AstarState",             ENT_FLT_ASTAR_STATE             , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Will1aaTo2aa",           ENT_INT_WILL1AA_TO2AA           , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Wuea",                   ENT_FLT_WUEA                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AnmPos",                 ENT_FLT_ANM_POS                 , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("RouteType",              ENT_FLT_ROUTE_TYPE              , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("BayRoute",               ENT_FLT_BAY_ROUTE               , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Intensity",              ENT_FLT_INTENSITY               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Precission",             ENT_FLT_PRECISSION              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AngVel",                 ENT_FLT_ANG_VEL                 , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SizeFactor",             ENT_FLT_SIZE_FACTOR             , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("GlowTexture",            ENT_STR_GLOW_TEXTURE            , PROP_TYPE_STR, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("GlowTestZ",              ENT_INT_GLOW_TEST_Z             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("GlowSizeDist",           ENT_INT_GLOW_SIZE_DIST          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MinDistance",            ENT_FLT_MIN_DISTANCE            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MaxDistance",            ENT_FLT_MAX_DISTANCE            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Volume",                 ENT_FLT_VOLUME                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("BaseVolume",             ENT_FLT_BASE_VOLUME             , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Pitch",                  ENT_FLT_PITCH                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SoundScale",             ENT_FLT_SOUND_SCALE             , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("CanUse",                 ENT_INT_CAN_USE                 , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InventorySelection",     ENT_STR_INVENTORY_SELECTION     , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Physic",                 ENT_INT_PHYSIC                  , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("nLights",                ENT_INT_N_LIGHTS                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("nFires",                 ENT_INT_N_FIRES                 , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("AnimFullName",           ENT_STR_ANIM_FULL_NAME          , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("AnimName",               ENT_STR_ANIM_NAME               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("PrevAnimName",           ENT_STR_PREV_ANIM_NAME          , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("TimerFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_TimerFunc_get             , bex_ent_TimerFunc_set);
        insert_property("HitFunc",                -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_HitFunc_get               , bex_ent_HitFunc_set);
        insert_property("InflictHitFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_InflictHitFunc_get        , bex_ent_InflictHitFunc_set);
        insert_property("DamageFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_DamageFunc_get            , bex_ent_DamageFunc_set);
        insert_property("StickFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_StickFunc_get             , bex_ent_StickFunc_set);
        insert_property("FrameFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_FrameFunc_get             , bex_ent_FrameFunc_set);
        insert_property("HearFunc",               -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_HearFunc_get              , bex_ent_HearFunc_set);
        insert_property("SeeFunc",                -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_SeeFunc_get               , bex_ent_SeeFunc_set);
        insert_property("UseFunc",                -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_UseFunc_get               , bex_ent_UseFunc_set);
        insert_property("TouchFluidFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_TouchFluidFunc_get        , bex_ent_TouchFluidFunc_set);
        insert_property("EnterPrimaryAAFunc",     -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterPrimaryAAFunc_get    , bex_ent_EnterPrimaryAAFunc_set);
        insert_property("EnterSecondaryAAFunc",   -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterSecondaryAAFunc_get  , bex_ent_EnterSecondaryAAFunc_set);
        insert_property("EnterCloseFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterCloseFunc_get        , bex_ent_EnterCloseFunc_set);
        insert_property("EnterLargeFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterLargeFunc_get        , bex_ent_EnterLargeFunc_set);
        insert_property("AnmEndedFunc",           -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AnmEndedFunc_get          , bex_ent_AnmEndedFunc_set);
        insert_property("DelayNoSeenFunc",        -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_DelayNoSeenFunc_get       , bex_ent_DelayNoSeenFunc_set);
        insert_property("RouteEndedFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_RouteEndedFunc_get        , bex_ent_RouteEndedFunc_set);
        insert_property("ImHurtFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ImHurtFunc_get            , bex_ent_ImHurtFunc_set);
        insert_property("ImDeadFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ImDeadFunc_get            , bex_ent_ImDeadFunc_set);
        insert_property("EnemyDeadFunc",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnemyDeadFunc_get         , bex_ent_EnemyDeadFunc_set);
        insert_property("NoAllowedAreaFunc",      -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_NoAllowedAreaFunc_get     , bex_ent_NoAllowedAreaFunc_set);
        insert_property("EnemyNoAllowedAreaFunc", -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnemyNoAllowedAreaFunc_get, bex_ent_EnemyNoAllowedAreaFunc_set);
        insert_property("CharSeeingEnemyFunc",    -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_CharSeeingEnemyFunc_get   , bex_ent_CharSeeingEnemyFunc_set);
        insert_property("AnmTranFunc",            -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AnmTranFunc_get           , bex_ent_AnmTranFunc_set);
        insert_property("NewComboFunc",           -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_NewComboFunc_get          , bex_ent_NewComboFunc_set);
        insert_property("BigFallFunc",            -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_BigFallFunc_get           , bex_ent_BigFallFunc_set);
        insert_property("AttackFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AttackFunc_get            , bex_ent_AttackFunc_set);
        insert_property("ToggleCombatFunc",       -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ToggleCombatFunc_get      , bex_ent_ToggleCombatFunc_set);
        insert_property("TakeFunc",               -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_TakeFunc_get              , bex_ent_TakeFunc_set);
        insert_property("ThrowFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ThrowFunc_get             , bex_ent_ThrowFunc_set);
        insert_property("OnHitFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnHitFunc_get             , bex_ent_OnHitFunc_set);
        insert_property("OnStopFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnStopFunc_get            , bex_ent_OnStopFunc_set);
        insert_property("OnAnimationEndFunc",     -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnAnimationEndFunc_get    , bex_ent_OnAnimationEndFunc_set);
        insert_property("OnPathNodeFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnPathNodeFunc_get        , bex_ent_OnPathNodeFunc_set);
        insert_property("Orientation",            -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Orientation_get           , bex_ent_Orientation_set);
        insert_property("FiresIntensity",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_FiresIntensity_get        , bex_ent_FiresIntensity_set);
        insert_property("SubscribedLists",        -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_SubscribedLists_get       , NULL);
        insert_property("LightIntensity",         -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightIntensity_get        , NULL);
        insert_property("LightPrecission",        -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightPrecission_get       , NULL);
        insert_property("LightColor",             -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightColor_get            , NULL);
        insert_property("LightGlow",              -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightGlow_get             , NULL);
        insert_property("Lights",                 -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Lights_get                , bex_ent_Lights_set);
        insert_property("MutilateFunc",           -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_MutilateFunc_get          , bex_ent_MutilateFunc_set);
        insert_property("AttackList",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AttackList_get            , bex_ent_AttackList_set);
        insert_property("Reflection",             ENT_FLT_REFLECTION              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Transparency",           ENT_FLT_TRANSPARENCY            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DeepColor",              ENT_VEC_DEEP_COLOR              , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Color",                  ENT_VEC_COLOR                   , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Solid",                  ENT_INT_SOLID                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SlidingSurface",         ENT_VEC_SLIDING_SURFACE         , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AddBayPoint",            ENT_VEC_ADD_BAY_POINT           , PROP_TYPE_VEC, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("LastBayNumAnims",        ENT_INT_LAST_BAY_NUM_ANIMS      , PROP_TYPE_INT, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("LastBayAngAnims",        ENT_FLT_LAST_BAY_ANG_ANIMS      , PROP_TYPE_FLT, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("InvertedRoute",          ENT_INT_INVERTED_ROUTE          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Dist2Floor",             ENT_FLT_DIST2_FLOOR             , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("BlockingPropensity",     ENT_FLT_BLOCKING_PROPENSITY     , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RangeDefenceCapable",    ENT_INT_RANGE_DEFENCE_CAPABLE   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ActiveEnemy",            ENT_STR_ACTIVE_ENEMY            , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvRight",               ENT_STR_INV_RIGHT               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvLeft",                ENT_STR_INV_LEFT                , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvLeft2",               ENT_STR_INV_LEFT2               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvRightBack",           ENT_STR_INV_RIGHT_BACK          , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvLeftBack",            ENT_STR_INV_LEFT_BACK           , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InCombat",               ENT_INT_IN_COMBAT               , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("DefenceNeeded",          ENT_INT_DEFENCE_NEEDED          , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("MeshName",               ENT_STR_MESH_NAME               , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PersonNodeName",         ENT_STR_PERSON_NODE_NAME        , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PersonName",             ENT_STR_PERSON_NAME             , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ObjectName",             ENT_STR_OBJECT_NAME             , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("YGravity",               ENT_FLT_Y_GRAVITY               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Friction",               ENT_FLT_FRICTION                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Friction2",              ENT_FLT_FRICTION2               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PPS",                    ENT_FLT_P_P_S                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DeathTime",              ENT_FLT_DEATH_TIME              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FollowFactor",           ENT_FLT_FOLLOW_FACTOR           , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("NormalVelocity",         ENT_FLT_NORMAL_VELOCITY         , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RandomVelocity",         ENT_FLT_RANDOM_VELOCITY         , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RandomVelocity_V",       ENT_FLT_RANDOM_VELOCITY_V       , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Time2Live",              ENT_FLT_TIME2_LIVE              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Time2Live_V",            ENT_FLT_TIME2_LIVE_V            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ObjCTest",               ENT_INT_OBJ_C_TEST              , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Static",                 0                               , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Static_get                , bex_ent_Static_set);
        insert_property("Object",                 ENT_INT_OBJECT                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Person",                 4                               , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Person_get                , bex_ent_Person_set);
        insert_property("Weapon",                 10                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Weapon_get                , bex_ent_Weapon_set);
        insert_property("Actor",                  11                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Actor_get                 , bex_ent_Actor_set);
        insert_property("Arrow",                  12                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Arrow_get                 , bex_ent_Arrow_set);
        insert_property("RAttackMin",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_RAttackMin_get            , bex_ent_RAttackMin_set);
        insert_property("RAttackMax",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_RAttackMax_get            , bex_ent_RAttackMax_set);
        insert_property("ActionAreaMin",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ActionAreaMin_get         , bex_ent_ActionAreaMin_set);
        insert_property("ActionAreaMax",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ActionAreaMax_get         , bex_ent_ActionAreaMax_set);
        insert_property("FireParticleType",       ENT_STR_FIRE_PARTICLE_TYPE      , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ParticleType",           ENT_STR_PARTICLE_TYPE           , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ExclusionGroup",         ENT_INT_EXCLUSION_GROUP         , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TPos",                   ENT_VEC_T_POS                   , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TAng",                   ENT_VEC_T_ANG                   , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TType",                  ENT_INT_T_TYPE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SType",                  ENT_INT_S_TYPE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PViewType",              ENT_INT_P_VIEW_TYPE             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ETarget",                ENT_STR_E_TARGET                , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ESource",                ENT_STR_E_SOURCE                , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Dist",                   ENT_FLT_DIST                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Returns",                ENT_INT_RETURNS                 , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("EarthQuake",             ENT_INT_EARTH_QUAKE             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("EarthQuakeFactor",       ENT_FLT_EARTH_QUAKE_FACTOR      , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ChangeNodeFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ChangeNodeFunc_get        , bex_ent_ChangeNodeFunc_set);
        insert_property("CombatGroup",            ENT_STR_COMBAT_GROUP            , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Heard",                  ENT_INT_HEARD                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Seen",                   ENT_INT_SEEN                    , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("LastTimeSeen",           ENT_FLT_LAST_TIME_SEEN          , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Radius",                 ENT_FLT_RADIUS                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Cone",                   ENT_FLT_CONE                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Height",                 ENT_FLT_HEIGHT                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("HitShieldFunc",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_HitShieldFunc_get         , bex_ent_HitShieldFunc_set);
        insert_property("Alpha",                  ENT_FLT_ALPHA                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SelfIlum",               ENT_FLT_SELF_ILUM               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Texture",                ENT_INT_TEXTURE                 , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TextureName",            ENT_STR_TEXTURE_NAME            , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("BlendMode",              ENT_STR_BLEND_MODE              , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Frame",                  ENT_FLT_FRAME                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RasterMode",             ENT_STR_RASTER_MODE             , PROP_TYPE_STR, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("RasterModeZ",            ENT_STR_RASTER_MODE_Z           , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("RasterModeAlpha",        ENT_STR_RASTER_MODE_ALPHA       , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("MutilationsMask",        ENT_INT_MUTILATIONS_MASK        , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("ExclusionMask",          ENT_INT_EXCLUSION_MASK          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Zoom",                   ENT_FLT_ZOOM                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SelfLight",              ENT_FLT_SELF_LIGHT              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ContinuousDamage",       ENT_INT_CONTINUOUS_DAMAGE       , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TrailMode",              ENT_INT_TRAIL_MODE              , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("WeaponMode",             ENT_INT_WEAPON_MODE             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("StaticWeaponMode",       ENT_INT_STATIC_WEAPON_MODE      , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("LastSound",              ENT_STR_LAST_SOUND              , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("LastSoundPosition",      ENT_VEC_LAST_SOUND_POSITION     , PROP_TYPE_VEC, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("ZoomS",                  ENT_FLT_ZOOM_S                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ZoomT",                  ENT_FLT_ZOOM_T                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OriginS",                ENT_FLT_ORIGIN_S                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OriginT",                ENT_FLT_ORIGIN_T                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
/* FIXME two "Angle" properties */
        insert_property("Angle",                  ENT_FLT_ANGLE_2                 , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FixedTarget",            ENT_INT_FIXED_TARGET            , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InternalState",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_InternalState_get         , bex_ent_InternalState_set);
        insert_property("Accuracy",               ENT_FLT_ACCURACY                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AimOffTarget",           ENT_FLT_AIM_OFF_TARGET          , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AimVector",              ENT_VEC_AIM_VECTOR              , PROP_TYPE_VEC, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("LastAttackTime",         ENT_FLT_LAST_ATTACK_TIME        , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InWorld",                ENT_INT_IN_WORLD                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("RangeActive",            ENT_INT_RANGE_ACTIVE            , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("MeleeActive",            ENT_INT_MELEE_ACTIVE            , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("OnStepFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnStepFunc_get            , bex_ent_OnStepFunc_set);
        insert_property("Reflects",               ENT_INT_REFLECTS                , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Frozen",                 ENT_INT_FROZEN                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010208
*/

PyObject *bex_ent_doc_get(PyObject *self, char *attr_name) {
        return PyString_FromString("Entidad de Blade.");
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001021B
*/

PyObject *bex_ent_Data_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        return GetEntityData(entity->name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010230
*/

PyObject *bex_ent_TimerFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_TIMER_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010278
*/

PyObject *bex_ent_HitFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_HIT_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100102C0
*/

PyObject *bex_ent_InflictHitFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_INFLICT_HIT, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010308
*/

PyObject *bex_ent_HitShieldFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_HIT_SHIELD_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010350
*/

PyObject *bex_ent_DamageFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_DAMAGE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010398
*/

PyObject *bex_ent_StickFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_STICK_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100103E0
*/

PyObject *bex_ent_FrameFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_FRAME, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010428
*/

PyObject *bex_ent_HearFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_HEAR_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010470
*/

PyObject *bex_ent_SeeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_SEE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100104B8
*/

PyObject *bex_ent_UseFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_USE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010500
*/

PyObject *bex_ent_ChangeNodeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_CHANGE_NODE, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010548
*/

PyObject *bex_ent_TouchFluidFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_TOUCH_FLUID, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010590
*/

PyObject *bex_ent_EnterPrimaryAAFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_PRIMARY_AA, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100105D8
*/

PyObject *bex_ent_EnterSecondaryAAFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_SECONDARY_AA, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010620
*/

PyObject *bex_ent_EnterCloseFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_CLOSE, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010668
*/

PyObject *bex_ent_EnterLargeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_LARGE, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100106B0
*/

PyObject *bex_ent_AnmEndedFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ANM_ENDED, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100106F8
*/

PyObject *bex_ent_DelayNoSeenFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_DELAY_NO_SEEN_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010740
*/

PyObject *bex_ent_RouteEndedFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ROUTE_ENDED, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010788
*/

PyObject *bex_ent_ImHurtFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_IM_HURT_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100107D0
*/

PyObject *bex_ent_ImDeadFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_IM_DEAD_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010818
*/

PyObject *bex_ent_EnemyDeadFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_DEAD_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010860
*/

PyObject *bex_ent_NoAllowedAreaFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_NO_ALLOWED_AREA_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100108A8
*/

PyObject *bex_ent_EnemyNoAllowedAreaFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_NO_ALLOWED_AREA, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100108F0
*/

PyObject *bex_ent_CharSeeingEnemyFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_CHAR_SEEING_ENEMY, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010938
*/

PyObject *bex_ent_AnmTranFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ANM_TRAN, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010980
*/

PyObject *bex_ent_NewComboFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_NEW_COMBO_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100109C8
*/

PyObject *bex_ent_BigFallFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_BIG_FALL_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010A10
*/

PyObject *bex_ent_AttackFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ATTACK_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010A58
*/

PyObject *bex_ent_ToggleCombatFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_TOGGLE_COMBAT, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010AA0
*/

PyObject *bex_ent_TakeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_TAKE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010AE8
*/

PyObject *bex_ent_ThrowFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_THROW_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010B30
*/

PyObject *bex_ent_MutilateFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_MUTILATE_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010B78
*/

PyObject *bex_ent_AttackList_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *atack_list;

        atack_list = GetAttackList(entity->name);
        if (atack_list == NULL) {
                if (Py_None)
                        Py_INCREF(Py_None);
                return Py_None;
        }

        if (atack_list)
                Py_INCREF(atack_list);

        return atack_list;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010BD6
*/

PyObject *bex_ent_OnHitFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ON_HIT, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010C1E
*/

PyObject *bex_ent_OnStopFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ON_STOP, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010C66
*/

PyObject *bex_ent_OnStepFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ON_STEP, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010CAE
*/

PyObject *bex_ent_OnAnimationEndFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ON_ANIMATION_END_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010CF6
*/

PyObject *bex_ent_OnPathNodeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ON_PATH_NODE, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010D3E
*/

PyObject *bex_ent_RAttackMin_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int r_attack_min;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_R_ATTACK, 0, &r_attack_min
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(r_attack_min);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010D90
*/

PyObject *bex_ent_RAttackMax_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int r_attack_max;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_R_ATTACK, 1, &r_attack_max
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(r_attack_max);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010DE2
*/

PyObject *bex_ent_ActionAreaMin_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_area_min;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 0, &action_area_min
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(action_area_min);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010E34
*/

PyObject *bex_ent_ActionAreaMax_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_area_max;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 1, &action_area_max
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(action_area_max);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010E86
*/

PyObject *bex_ent_Arrow_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_arrow;

        code = GetEntityIntProperty(entity->name, ENT_INT_ARROW, 0, &is_arrow);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_arrow);
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10010ED8
*/

PyObject *bex_ent_Static_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_static;

        code = GetEntityIntProperty(entity->name, ENT_INT_STATIC, 0, &is_static);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_static);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010F2A
*/

PyObject *bex_ent_Actor_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_actor;

        code = GetEntityIntProperty(entity->name, ENT_INT_ACTOR, 0, &is_actor);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_actor);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010F7C
*/

PyObject *bex_ent_Person_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_person;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_PERSON, 0, &is_person
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_person);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010FCE
*/

PyObject *bex_ent_Weapon_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_weapon;

        code = GetEntityIntProperty(entity->name, ENT_INT_WEAPON, 0, &is_weapon);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_weapon);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011020
*/

PyObject *bex_ent_Orientation_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double quat1, quat2, quat3, quat4;
        PyObject *tuple, *quat1Obj, *quat2Obj, *quat3Obj, *quat4Obj;

        code = GetEntityQuatProperty(entity->name, ENT_QUAT_ORIENTATION, 0, &quat1, &quat2, &quat3, &quat4);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        tuple = PyTuple_New(4);

        quat1Obj = PyFloat_FromDouble(quat1);
        quat2Obj = PyFloat_FromDouble(quat2);
        quat3Obj = PyFloat_FromDouble(quat3);
        quat4Obj = PyFloat_FromDouble(quat4);

        PyTuple_SetItem(tuple, 0, quat1Obj);
        PyTuple_SetItem(tuple, 1, quat2Obj);
        PyTuple_SetItem(tuple, 2, quat3Obj);
        PyTuple_SetItem(tuple, 3, quat4Obj);

        return tuple;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011122
*/

PyObject *bex_ent_SubscribedLists_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int num_lists, i;
        PyObject *subscribed_lists, *subscribed_list_obj;
        const char *subscribed_list_name;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_SUBSCRIBED_LISTS, 0, &num_lists
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        subscribed_lists = PyList_New(num_lists);

        for (i = 0; i < num_lists; i++) {
                code = GetEntityStringProperty(
                        entity->name, ENT_STR_SUBSCRIBED_LIST, i,
                        &subscribed_list_name
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                subscribed_list_obj = PyString_FromString(subscribed_list_name);
                PyList_SetItem(subscribed_lists, i, subscribed_list_obj);
        }

        return subscribed_lists;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100111FC
*/

PyObject *bex_ent_FiresIntensity_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int num_fires, i;
        PyObject *fires, *intensity_obj;
        double intensity;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_FIRES, 0, &num_fires
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        fires = PyList_New(num_fires);

        for (i = 0; i < num_fires; i++) {
                code = GetEntityFloatProperty(
                        entity->name, ENT_FLT_FIRES_INTENSITY, i, &intensity
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                intensity_obj = PyFloat_FromDouble(intensity);
                PyList_SetItem(fires, i, intensity_obj);
        }

        return fires;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100112DB
*/

PyObject *bex_ent_LightIntensity_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int num_lights, i;
        PyObject *lights, *intensity_obj;
        double intensity;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_LIGHTS, 0, &num_lights
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        lights = PyTuple_New(num_lights);

        for (i = 0; i < num_lights; i++) {
                code = GetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_INTENSITY, i, &intensity
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                intensity_obj = PyFloat_FromDouble(intensity);
                PyTuple_SetItem(lights, i, intensity_obj);
        }

        return lights;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100113BA
*/

PyObject *bex_ent_LightPrecission_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int num_lights, i;
        PyObject *lights, *precision_obj;
        double precision;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_LIGHTS, 0, &num_lights
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        lights = PyTuple_New(num_lights);

        for (i = 0; i < num_lights; i++) {
                code = GetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_PRECISION, i, &precision
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                precision_obj = PyFloat_FromDouble(precision);
                PyTuple_SetItem(lights, i, precision_obj);
        }

        return lights;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011499
*/

PyObject *bex_ent_LightColor_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int num_lights, i;
        PyObject *lights, *color_obj, *r_obj, *g_obj, *b_obj;
        double r, g, b;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_LIGHTS, 0, &num_lights
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        lights = PyTuple_New(num_lights);

        for (i = 0; i < num_lights; i++) {
                code = GetEntityVectorProperty(
                        entity->name, ENT_VEC_LIGHTS_COLOUR, i, &r, &g, &b
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                r_obj = PyFloat_FromDouble(r);
                g_obj = PyFloat_FromDouble(g);
                b_obj = PyFloat_FromDouble(b);

                color_obj = PyTuple_New(3);

                PyTuple_SetItem(color_obj, 0, r_obj);
                PyTuple_SetItem(color_obj, 1, g_obj);
                PyTuple_SetItem(color_obj, 2, b_obj);

                PyTuple_SetItem(lights, i, color_obj);
        }

        return lights;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100115FA
*/

PyObject *bex_ent_LightGlow_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int num_lights, i;
        PyObject *lights, *glow_obj;
        int glow;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_LIGHTS, 0, &num_lights
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        lights = PyTuple_New(num_lights);

        for (i = 0; i < num_lights; i++) {
                code = GetEntityIntProperty(
                        entity->name, ENT_INT_GLOW, i, &glow
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                glow_obj = PyInt_FromLong(glow);
                PyTuple_SetItem(lights, i, glow_obj);
        }

        return lights;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100116D4
*/

int bex_ent_Static_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_static;

        if (!PyArg_Parse(value, "i", &is_static)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityStatic(entity->name, is_static);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1001174E
*/

int bex_ent_Actor_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_actor;
        int code;

        if (!PyArg_Parse(value, "i", &is_actor)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityActor(entity->name, is_actor);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100117C8
*/

int bex_ent_Person_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_person;
        int code;

        if (!PyArg_Parse(value, "i", &is_person)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityPerson(entity->name, is_person);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011842
*/

int bex_ent_Weapon_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_weapon;
        int code;

        if (!PyArg_Parse(value, "i", &is_weapon)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityWeapon(entity->name, is_weapon);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100118BC
*/

int bex_ent_Arrow_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_arrow;
        int code;

        if (!PyArg_Parse(value, "i", &is_arrow)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityArrow(entity->name, is_arrow);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011936
*/

int bex_ent_Data_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *data;
        int code;

        if (!PyArg_Parse(value, "O", &data)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityData(entity->name, data);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100119B1
*/

int bex_ent_FiresIntensity_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i, num_fires;
        double item;
        PyObject *itemObj;
        int code;

        if (!PyList_Check(value)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param, not a list.");
                return -1;
        }

        num_fires = PyList_Size(value);

        for (i = 0; i < num_fires; i++) {
                itemObj = PyList_GetItem(value, i);
                item = PyFloat_AsDouble(itemObj);

                code = SetEntityFloatProperty(
                        entity->name, ENT_FLT_FIRES_INTENSITY, i, item
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10011A7E
*/

int bex_ent_Lights_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i, num_lights;
        PyObject *tuple, *intensityObj, *precisionObj, *colourObj;
        PyObject *rObj, *gObj, *bObj;
        double intensity, precision, r, g, b;
        int code;

        if (!PyList_Check(value)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param, not a list.");
                return -1;
        }

        num_lights = PyList_Size(value);

        for (i = 0; i < num_lights; i++) {
                tuple = PyList_GetItem(value, i);

                if (!PyTuple_Check(tuple)) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param, not a tuple."
                        );
                        return -1;
                }

                intensityObj = PyTuple_GetItem(tuple, 0);
                precisionObj = PyTuple_GetItem(tuple, 1);
                colourObj = PyTuple_GetItem(tuple, 2);

                if (!PyTuple_Check(colourObj)) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param, color not a tuple."
                        );
                        return -1;
                }

                rObj = PyTuple_GetItem(colourObj, 0);
                gObj = PyTuple_GetItem(colourObj, 1);
                bObj = PyTuple_GetItem(colourObj, 2);

                intensity = PyFloat_AsDouble(intensityObj);
                precision = PyFloat_AsDouble(precisionObj);
                r = PyFloat_AsDouble(rObj);
                g = PyFloat_AsDouble(gObj);
                b = PyFloat_AsDouble(bObj);

                code = SetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_INTENSITY, i, intensity
                );
                if (code != 1) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param - Intensity."
                        );
                        return -1;
                }

                code = SetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_PRECISION, i, precision
                );
                if (code != 1) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param - Precission."
                        );
                        return -1;
                }

                code = SetEntityVectorProperty(
                        entity->name, ENT_VEC_LIGHTS_COLOUR, i, r, g, b
                );
                if (code != 1) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param - Color."
                        );
                        return -1;
                }
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011CED
*/

PyObject *bex_ent_Lights_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i, num_lights;
        PyObject *list, *tuple, *intensityObj, *precisionObj, *colourObj;
        PyObject *rObj, *gObj, *bObj;
        double intensity, precision, r, g, b;
        int code;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_LIGHTS, 0, &num_lights
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        list = PyList_New(num_lights);

        for (i = 0; i < num_lights; i++) {
                code = GetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_INTENSITY, i, &intensity
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                code = GetEntityFloatProperty(entity->name, ENT_FLT_LIGHTS_PRECISION, i, &precision);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                code = GetEntityVectorProperty(
                        entity->name, ENT_VEC_LIGHTS_COLOUR, i, &r, &g, &b
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                tuple = PyTuple_New(3);

                intensityObj = PyFloat_FromDouble(intensity);
                precisionObj = PyFloat_FromDouble(precision);

                rObj = PyInt_FromLong(r);
                gObj = PyInt_FromLong(g);
                bObj = PyInt_FromLong(b);

                colourObj = PyTuple_New(3);

                PyTuple_SetItem(colourObj, 0, rObj);
                PyTuple_SetItem(colourObj, 1, gObj);
                PyTuple_SetItem(colourObj, 2, bObj);

                PyTuple_SetItem(tuple, 0, intensityObj);
                PyTuple_SetItem(tuple, 1, precisionObj);
                PyTuple_SetItem(tuple, 2, colourObj);

                PyList_SetItem(list, i, tuple);
        }

        return list;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011F3B
*/

int bex_ent_RAttackMin_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double r_attack_min;
        int code;

        if (!PyArg_Parse(value, "d", &r_attack_min)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityIntProperty(
                entity->name, ENT_INT_R_ATTACK, 0, r_attack_min
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011FBE
*/

int bex_ent_RAttackMax_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double r_attack_max;
        int code;

        if (!PyArg_Parse(value, "d", &r_attack_max)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityIntProperty(
                entity->name, ENT_INT_R_ATTACK, 1, r_attack_max
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012041
*/

int bex_ent_ActionAreaMin_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double action_area_min;
        int code;

        if (!PyArg_Parse(value, "d", &action_area_min)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 0, action_area_min
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100120C4
*/

int bex_ent_ActionAreaMax_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double action_area_max;
        int code;

        if (!PyArg_Parse(value, "d", &action_area_max)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 1, action_area_max
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10012147
*/

int bex_ent_Orientation_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double quat1, quat2, quat3, quat4;
        int code;


        if (!PyArg_Parse(value, "(dddd)", &quat1, &quat2, &quat3, &quat4)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityQuatProperty(
                entity->name, ENT_QUAT_ORIENTATION, 0, quat1, quat2, quat3,
                quat4
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100121EE
*/

int bex_ent_TimerFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_TIMER_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001226D
*/

int bex_ent_HitFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(entity->name, ENT_FNC_HIT_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012304
*/

int bex_ent_InflictHitFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_INFLICT_HIT, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1001239B
*/

int bex_ent_HitShieldFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_HIT_SHIELD_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001241A
*/

int bex_ent_DamageFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_DAMAGE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012499
*/

int bex_ent_StickFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_STICK_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012518
*/

int bex_ent_FrameFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_FRAME, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012597
*/

int bex_ent_HearFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_HEAR_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10012616
*/

int bex_ent_SeeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(entity->name, ENT_FNC_SEE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100126AD
*/

int bex_ent_UseFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_USE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001272C
*/

int bex_ent_ChangeNodeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_CHANGE_NODE, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100127AB
*/

int bex_ent_TouchFluidFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_TOUCH_FLUID, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001282A
*/

int bex_ent_EnterPrimaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_PRIMARY_AA, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100128A9
*/

int bex_ent_EnterSecondaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_SECONDARY_AA, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012928
*/

int bex_ent_EnterCloseFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ENTER_CLOSE, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100129A7
*/

int bex_ent_EnterLargeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ENTER_LARGE, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012A26
*/

int bex_ent_AnmEndedFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ANM_ENDED, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012ABD
*/

int bex_ent_DelayNoSeenFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_DELAY_NO_SEEN_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012B3C
*/

int bex_ent_RouteEndedFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ROUTE_ENDED, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012BBB
*/

int bex_ent_ImHurtFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if(!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_IM_HURT_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012C3A
*/

int bex_ent_ImDeadFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_IM_DEAD_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10012CB9
*/

int bex_ent_EnemyDeadFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_DEAD_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012D38
*/

int bex_ent_NoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_NO_ALLOWED_AREA_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012DB7
*/

int bex_ent_EnemyNoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_NO_ALLOWED_AREA, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012E36
*/

int bex_ent_CharSeeingEnemyFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_CHAR_SEEING_ENEMY, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012EB5
*/

int bex_ent_AnmTranFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ANM_TRAN, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012F34
*/

int bex_ent_NewComboFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_NEW_COMBO_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012FB3
*/

int bex_ent_BigFallFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_BIG_FALL_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013032
*/

int bex_ent_AttackFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ATTACK_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100130B1
*/

int bex_ent_ToggleCombatFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_TOGGLE_COMBAT, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013130
*/

int bex_ent_TakeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_TAKE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100131AF
*/

int bex_ent_ThrowFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_THROW_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001322E
*/

int bex_ent_MutilateFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_MUTILATE_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100132C5
*/

int bex_ent_AttackList_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *attack_list;
        int code;

        if (!PyArg_Parse(value, "O", &attack_list)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetAttackList(entity->name, attack_list);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013340
*/

int bex_ent_OnHitFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ON_HIT, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100133BF
*/

int bex_ent_OnStopFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ON_STOP, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001343E
*/

int bex_ent_OnStepFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ON_STEP, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}



/*
* Module:                 Bladex.dll
* Entry point:            0x100134BD
*/

int bex_ent_OnAnimationEndFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
            func = NULL;

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ON_ANIMATION_END_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013554
*/

int bex_ent_OnPathNodeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ON_PATH_NODE, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100135D3
*/

int bex_ent_InternalState_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *internal_state;
        int code;

        if (!PyArg_Parse(value, "O", &internal_state)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityInternalState(entity->name, internal_state);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001364E
*/

PyObject *bex_ent_InternalState_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *internal_state;
        int code;

        code = GetEntityInternalState(entity->name, &internal_state);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        if (internal_state == NULL) {
                if (Py_None)
                        Py_INCREF(Py_None);
                return Py_None;
        }

        return internal_state;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100136BC
*/

void init_entity() {
        init_entity_type();
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100136C6
*/

void init_entity_type() {

        memset(&entityTypeObject, 0, sizeof(PyTypeObject));

        entityTypeObject.ob_refcnt = 1;
        entityTypeObject.ob_type = &PyType_Type;
        entityTypeObject.ob_size = 0;
        entityTypeObject.tp_name = "B_PyEntity";
        entityTypeObject.tp_basicsize = sizeof(bld_py_entity_t);
        entityTypeObject.tp_itemsize = 0;
        entityTypeObject.tp_dealloc = bld_py_entity_dealloc;
        entityTypeObject.tp_print = bld_py_entity_print;
        entityTypeObject.tp_getattr = bld_py_entity_getattr;
        entityTypeObject.tp_setattr = bld_py_entity_setattr;
        entityTypeObject.tp_compare  = NULL;
        entityTypeObject.tp_repr = NULL;
        entityTypeObject.tp_as_number = NULL;
        entityTypeObject.tp_as_sequence = NULL;
        entityTypeObject.tp_as_mapping = NULL;
        entityTypeObject.tp_hash = NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013771
*/

void bld_py_entity_dealloc(PyObject *self) {
        free(((bld_py_entity_t *)self)->name);
        free(self);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013793
*/

int bld_py_entity_print(PyObject *self, FILE *file, int flags) {
        int code;
        const char *name;
        static char buffer[512];

        code = GetEntityStringProperty(
                ((bld_py_entity_t *)self)->name, ENT_STR_NAME, 0, &name
        );
        if (code != 1)
                sprintf(buffer, "Entity: Invalid.");
        else
                sprintf(buffer, "Entity: %s", name);

        fprintf(file, buffer);
        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100137FE
*/

PyObject *bld_py_entity_getattr(PyObject *self, char *attr_name)
{
        int prop_index, data_type, code;
        static PyObject * (*get_prop_func)(PyObject *self, char *attr_name);
        int int_value;
        double double_value;
        const char *str_value;
        double x, y, z;
        PyObject *tuple, *xObj, *yObj, *zObj;

        prop_index = find_property(property_kinds, attr_name);
        if (prop_index == -1) {
                return Py_FindMethod(entity_methods, self, attr_name);
        }

        if (
                property_kinds[prop_index].flags == PROP_ONLY_GET ||
                property_kinds[prop_index].flags == PROP_GET_AND_SET
        ) {
                if (property_kinds[prop_index].data_type == PROP_TYPE_OBJ ) {
                        get_prop_func = property_kinds[prop_index].get_func;
                        return get_prop_func(self, attr_name);
                }

                data_type = property_kinds[prop_index].data_type;
                if ((data_type - 1) > 3) {
                        return NULL;
                }
                switch(data_type) {
                        case PROP_TYPE_INT:
                                code = GetEntityIntProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &int_value
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(
                                                    PyExc_AttributeError,
                                                    attr_name
                                                );
                                        } else {
                                                char buffer[512];
                                                sprintf(
                                                    buffer, "Unsupported %s",
                                                    attr_name
                                                );
                                                PyErr_SetString(
                                                    PyExc_AttributeError, buffer
                                                );
                                        }
                                        return NULL;
                                }
                                return PyInt_FromLong(int_value);

                        case PROP_TYPE_FLT:
                                code = GetEntityFloatProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &double_value
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(
                                                    PyExc_AttributeError,
                                                    attr_name
                                                );
                                        } else {
                                                char buffer[512];
                                                sprintf(
                                                    buffer, "Unsupported %s",
                                                    attr_name
                                                );
                                                PyErr_SetString(
                                                    PyExc_AttributeError, buffer
                                                );
                                        }
                                        return NULL;
                                }
                                return PyFloat_FromDouble(double_value);

                        case PROP_TYPE_STR:
                                code = GetEntityStringProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &str_value
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(PyExc_AttributeError, attr_name);
                                        } else {
                                                char buffer[512];
                                                sprintf(buffer, "Unsupported %s", attr_name);
                                                PyErr_SetString(PyExc_AttributeError, buffer);
                                        }
                                        return NULL;
                                }
                                if (str_value == NULL) {
                                        if (Py_None)
                                                Py_INCREF(Py_None);
                                        return Py_None;
                                } else {
                                        return PyString_FromString(str_value);
                                }

                        case PROP_TYPE_VEC:
                                code = GetEntityVectorProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &x, &y, &z
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(PyExc_AttributeError, attr_name);
                                        } else {
                                                char buffer[512];
                                                sprintf(buffer, "Unsupported %s", attr_name);
                                                PyErr_SetString(PyExc_AttributeError, buffer);
                                        }
                                        return NULL;
                                } else {
                                        tuple = PyTuple_New(3);

                                        xObj = PyFloat_FromDouble(x);
                                        yObj = PyFloat_FromDouble(y);
                                        zObj = PyFloat_FromDouble(z);

                                        PyTuple_SetItem(tuple, 0, xObj);
                                        PyTuple_SetItem(tuple, 1, yObj);
                                        PyTuple_SetItem(tuple, 2, zObj);

                                        return tuple;
                                }
                }
        }

        return Py_FindMethod(entity_methods, self, attr_name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013C54
*/

int bld_py_entity_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        int prop_index, data_type, code;
        static int (*set_prop_func)(PyObject *self, char *attr_name, PyObject *value);
        const char *name;
        int int_value;
        double double_value;
        const char *str_value;
        double x, y, z;
        char buffer[512];

        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete entity attributes"
                );
                return -1;
        }

        prop_index = find_property(property_kinds, attr_name);
        if (
                prop_index != -1 &&
                (property_kinds[prop_index].flags == PROP_ONLY_SET ||
                 property_kinds[prop_index].flags == PROP_GET_AND_SET
                )
        ) {
                if (property_kinds[prop_index].data_type == PROP_TYPE_OBJ) {
                        set_prop_func = property_kinds[prop_index].set_func;
                        return (*set_prop_func)(self, attr_name, value);
                }

                data_type = property_kinds[prop_index].data_type;

                switch(data_type) {
                        case PROP_TYPE_INT:
                                if (!PyArg_Parse(value, "i", &int_value)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityIntProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        int_value
                                );
                                if (code != 1) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                return 0;

                        case PROP_TYPE_FLT:
                                if (!PyArg_Parse(value, "d", &double_value)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityFloatProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        double_value
                                );
                                if (code != 1) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                return 0;

                        case PROP_TYPE_STR:
                                if (!PyArg_Parse(value, "s", &str_value)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityStringProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        str_value
                                );
                                if (code != 1) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                return 0;

                        case PROP_TYPE_VEC:
                                if (!PyArg_Parse(value, "(ddd)", &x, &y, &z)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityVectorProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        x, y, z
                                );
                                if (code != 1) {
                                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                                        return -1;
                                }

                                return 0;
                }

        }

        code = GetEntityStringProperty(
                ((bld_py_entity_t *)self)->name, ENT_STR_NAME, 0,
                &name
        );
        if (code != 1) {
                sprintf(buffer, "Not implemented: %s", attr_name);
        } else {
                sprintf(buffer, "Not implemented: Attribute %s    Entity: %s", attr_name, name);
        }

        PyErr_SetString(PyExc_AttributeError, buffer);

        return -1;
}
