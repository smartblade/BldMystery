
__declspec(dllexport) void WorldToMBW(const char *world) {}
__declspec(dllexport) void SoundSystemActive(void) {}
__declspec(dllexport) void SetSSFrecuency(int frequency) {}
__declspec(dllexport) void SetSS2dChannels(int num_ch) {}
__declspec(dllexport) void SetSS3dChannels(int num_ch) {}
__declspec(dllexport) void SetSSFilter(int filter_output) {}
__declspec(dllexport) void KillMusic(void) {}
__declspec(dllexport) void ShutDownSoundChannels(void) {}
__declspec(dllexport) void PauseSoundSystem(void) {}
__declspec(dllexport) void PauseSoundSystemButMusic(void) {}
__declspec(dllexport) void ResumeSoundSystem(void) {}
__declspec(dllexport) void SetMusicVolume(float volume) {}
__declspec(dllexport) void GetMusicVolume(void) {}
__declspec(dllexport) void SetSoundVolume(double volume) {}
__declspec(dllexport) void GetSoundVolume(void) {}
__declspec(dllexport) void GetSSSpeakerConfig(void) {}
__declspec(dllexport) void SetEAXOverride(int EAXOverride) {}
__declspec(dllexport) void GetEAXOverride(void) {}
__declspec(dllexport) void SaveSSConfig(void) {}
__declspec(dllexport) void SetSSSpeakerConfig(int config) {}
__declspec(dllexport) void GetSSQuality(void) {}
__declspec(dllexport) void SetSSQuality(int SSQuality) {}
__declspec(dllexport) void SetAutoGenTexture(const char *textureName, int textureEffect) {}
__declspec(dllexport) void SetBloodLevel(int blood_level) {}
__declspec(dllexport) void GetBloodLevel(void) {}
__declspec(dllexport) void SetMutilationLevel(int mutilation_level) {}
__declspec(dllexport) void GetMutilationLevel(void) {}
__declspec(dllexport) void GetWorldFileName(void) {}
__declspec(dllexport) void AddTranTime(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
) {}
__declspec(dllexport) void CheckAnims(void) {}
__declspec(dllexport) void GiveAnims(const char *race_name) {}
__declspec(dllexport) void GetAnimationDuration(const char *animation_name, double *duration) {}
__declspec(dllexport) void SetAnimationFactor(const char *mov, double new_speed_factor) {}
__declspec(dllexport) void SetTurnSpeed(const char *race_name, double new_speed) {}
__declspec(dllexport) void GetEntity(const char *name) {}
__declspec(dllexport) void GetEntityI(int index) {}
__declspec(dllexport) void CreateEntity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
) {}
__declspec(dllexport) void CreateEntityDecal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
) {}
__declspec(dllexport) void CreateSpark(
        const char *name, void *spark_point, void *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
) {}
__declspec(dllexport) void GetEntityName(void *entity) {}
__declspec(dllexport) void DeleteEntity(const char *name) {}
__declspec(dllexport) void GetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char **value
) {}
__declspec(dllexport) void SetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char *value
) {}
__declspec(dllexport) void GetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double *value
) {}
__declspec(dllexport) void SetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double value
) {}
__declspec(dllexport) void GetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int *value
) {}
__declspec(dllexport) void SetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int value
) {}
__declspec(dllexport) void GetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
) {}
__declspec(dllexport) void SetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
) {}
__declspec(dllexport) void GetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, void **func
) {}
__declspec(dllexport) void SetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, void *func
) {}
__declspec(dllexport) void GetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
) {}
__declspec(dllexport) void SetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
) {}
__declspec(dllexport) void SeverLimb(const char *entity_name, int limb) {}
__declspec(dllexport) void ResetWounds(const char *entity_name) {}
__declspec(dllexport) void ImpulseC(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
) {}
__declspec(dllexport) void AddCameraEvent(const char *entity_name, int frame, void *func) {}
__declspec(dllexport) void DeleteCameraEvent(const char *entity_name, int frame) {}
__declspec(dllexport) void SubscribeEntityToList(
        const char *entity_name, const char *timer_name
) {}
__declspec(dllexport) void MessageEvent(
        const char *entity_name, int message_type, int unknown1, int unknown2
) {}
__declspec(dllexport) void Rel2AbsPoint(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
) {}
__declspec(dllexport) void Rel2AbsPointN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
) {}
__declspec(dllexport) void Rel2AbsVector(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
) {}
__declspec(dllexport) void Rel2AbsVectorN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
) {}
__declspec(dllexport) void Abs2RelPoint(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
) {}
__declspec(dllexport) void Abs2RelPointN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
) {}
__declspec(dllexport) void Abs2RelVector(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
) {}
__declspec(dllexport) void Abs2RelVectorN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
) {}
__declspec(dllexport) void GetDummyAxis(
        const char *entity_name, const char *anchor_name, double x_dir,
        double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
        double *z_dummy_axis, int unknown
) {}
__declspec(dllexport) void SQDistance2(const char *entity_name1, const char *entity_name2) {}
__declspec(dllexport) void RemoveEntityFromList(
        const char *entity_name, const char *timer_name
) {}
__declspec(dllexport) void RemoveFromInvent(const char *entity_name, const char *obj_name) {}
__declspec(dllexport) void RemoveFromInventRight(const char *entity_name) {}
__declspec(dllexport) void RemoveFromInventLeft(const char *entity_name) {}
__declspec(dllexport) void RemoveFromInventLeft2(const char *entity_name) {}
__declspec(dllexport) void LaunchAnimation2(
        const char *entity_name, const char *anm_name1, const char *anm_name2
) {}
__declspec(dllexport) void SetTmpAnmFlags(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
) {}
__declspec(dllexport) void SetAnmFlags(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
) {}
__declspec(dllexport) void SetActiveEnemy(
        const char *entity_name, const char *active_enemy_name, int *unknown
) {}
__declspec(dllexport) void CanISee(
        const char *entity_name, const char *seen_entity_name, int *canISee
) {}
__declspec(dllexport) void CanISeeFrom(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
) {}
__declspec(dllexport) void ExcludeHitFor(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
) {}
__declspec(dllexport) void ExcludeHitInAnimationFor(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
) {}
__declspec(dllexport) void UnlinkChild(
        const char *entity_name, const char *child_entity_name, void *unknown
) {}
__declspec(dllexport) void Link(
        const char *entity_name, const char *child_entity_name, void *unknown
) {}
__declspec(dllexport) void LinkAnchors(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
) {}
__declspec(dllexport) void LinkToNode(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
) {}
__declspec(dllexport) void GetNodeIndex(
        const char *entity_name, const char *node_name, int *index
) {}
__declspec(dllexport) void GetNChildren(const char *entity_name) {}
__declspec(dllexport) void GetChild(const char *entity_name, int index) {}
__declspec(dllexport) void InsideActionArea(
        const char *entity_name, int action_area, int *is_inside
) {}
__declspec(dllexport) void CheckAnimCol(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
) {}
__declspec(dllexport) void TestPos(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
) {}
__declspec(dllexport) void TestPosInOwnBox(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
) {}
__declspec(dllexport) void UnlinkChilds(const char *entity_name) {}
__declspec(dllexport) void SetNextAttack(
        const char *entity_name, const char *attack, int *res
) {}
__declspec(dllexport) void SetEnemy(const char *entity_name, const char *enemy_name) {}
__declspec(dllexport) void GetEnemy(const char *entity_name) {}
__declspec(dllexport) void Chase(
        const char *entity_name, const char *enemy_name, int action_area
) {}
__declspec(dllexport) void ResetChase(const char *entity_name) {}
__declspec(dllexport) void GoTo(const char *entity_name, int x, int y, int z) {}
__declspec(dllexport) void CanGoTo(const char *entity_name, int x, int y, int z) {}
__declspec(dllexport) void LookAtEntity(
        const char *entity_name, const char *look_at_entity_name
) {}
__declspec(dllexport) void QuickFace(const char *entity_name, double angle) {}
__declspec(dllexport) void Face(const char *entity_name, double angle) {}
__declspec(dllexport) void StartLooking(const char *entity_name, int x, int y, int z) {}
__declspec(dllexport) void StopLooking(const char *entity_name) {}
__declspec(dllexport) void AddEntWatchAnim(const char *entity_name, const char *anm_name) {}
__declspec(dllexport) void GraspPos(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
) {}
__declspec(dllexport) void Freeze(const char *entity_name) {}
__declspec(dllexport) void UnFreeze(const char *entity_name) {}
__declspec(dllexport) void SwitchTo1H(const char *entity_name) {}
__declspec(dllexport) void SwitchToBow(const char *entity_name) {}
__declspec(dllexport) void LaunchBayRoute(const char *entity_name) {}
__declspec(dllexport) void LaunchWatch(const char *entity_name) {}
__declspec(dllexport) void GetActionMode(const char *entity_name, int *action_mode) {}
__declspec(dllexport) void StartGrabbing(const char *entity_name) {}
__declspec(dllexport) void StopGrabbing(const char *entity_name) {}
__declspec(dllexport) void AddSoundAnim(
        const char *entity_name, const char *anm_event, double time, int soundID
) {}
__declspec(dllexport) void EntityAddAnmEventFunc(
        const char *entity_name, const char *anm_event, void *func
) {}
__declspec(dllexport) void EntityDelAnmEventFunc(
        const char *entity_name, const char *anm_event
) {}
__declspec(dllexport) void EntityClearAnmEventFuncs(const char *entity_name) {}
__declspec(dllexport) void AddSoundEvent(
        const char *entity_name, const char *event, int soundID
) {}
__declspec(dllexport) void ClearActorPath(const char *entity_name) {}
__declspec(dllexport) void CameraClearPath(const char *entity_name, int node) {}
__declspec(dllexport) void CameraStartPath(const char *entity_name, int node) {}
__declspec(dllexport) void AddActorPathnode(
        const char *entity_name, double time, double x, double y, double z
) {}
__declspec(dllexport) void StartActorPath(const char *entity_name) {}
__declspec(dllexport) void GoToActorPath(
        const char *entity_name, int i_unknown, double d_unknown
) {}
__declspec(dllexport) void TurnOnActor(const char *entity_name) {}
__declspec(dllexport) void TurnOffActor(const char *entity_name) {}
__declspec(dllexport) void SetActorNodeStartTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) {}
__declspec(dllexport) void SetActorNodeEndTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) {}
__declspec(dllexport) void CameraAddTargetNode(
        const char *entity_name, float time, double x, double y, double z
) {}
__declspec(dllexport) void CameraAddSourceNode(
        const char *entity_name, float time, double x, double y, double z
) {}
__declspec(dllexport) void CameraSetStartTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) {}
__declspec(dllexport) void CameraSetStartTangentSourceNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) {}
__declspec(dllexport) void CameraSetEndTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) {}
__declspec(dllexport) void CameraSetEndTangentSourceNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) {}
__declspec(dllexport) void CameraSetPersonView(
        const char *entity_name, const char *person_name
) {}
__declspec(dllexport) void CameraSetMaxCamera(
        const char *entity_name, const char *cam_file_name, int i_unknown,
        int num_frames
) {}
__declspec(dllexport) void CameraCut(const char *entity_name) {}
__declspec(dllexport) void CameraSetTravelingView(
        const char *entity_name, int unknown1, int unknown2
) {}
__declspec(dllexport) void EntityRotate(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
) {}
__declspec(dllexport) void EntityRotateAbs(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
) {}
__declspec(dllexport) void EntityRotateRel(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
) {}
__declspec(dllexport) void EntityMove(
        const char *entity_name, double x, double y, double z, int unknown
) {}
__declspec(dllexport) void EntitySetPosition(
        const char *entity_name, double x, double y, double z, int unknown
) {}
__declspec(dllexport) void EntitySetOrientation(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
) {}
__declspec(dllexport) void GetGroupMembers(const char *entity_name) {}
__declspec(dllexport) void GetCombatants(const char *entity_name) {}
__declspec(dllexport) void EntityPutToWorld(const char *entity_name) {}
__declspec(dllexport) void EntityRemoveFromWorld(const char *entity_name) {}
__declspec(dllexport) void EntityRemoveFromWorldWithChilds(const char *entity_name) {}
__declspec(dllexport) void UseEntity(const char *entity_name) {}
__declspec(dllexport) void SetSound(const char *entity_name, const char *sound) {}
__declspec(dllexport) void SetObjectSound(const char *entity_name, const char *sound) {}
__declspec(dllexport) void PlayEntitySound(const char *entity_name, int i_unknown) {}
__declspec(dllexport) void Stop(const char *entity_name) {}
__declspec(dllexport) void StopAt(const char *entity_name, double x, double y, double z) {}
__declspec(dllexport) void EntityCatchOnFire(
        const char *entity_name, double x, double y, double z
) {}
__declspec(dllexport) void GetParticleEntity(const char *entity_name) {}
__declspec(dllexport) void DoAction(const char *entity_name, const char *action_name) {}
__declspec(dllexport) void DoActionWI(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
) {}
__declspec(dllexport) void SetOnFloor(const char *entity_name) {}
__declspec(dllexport) void RaiseEvent(const char *entity_name, const char *event_name) {}
__declspec(dllexport) void InterruptCombat(const char *entity_name) {}
__declspec(dllexport) void SetAuraActive(const char *entity_name, int is_active) {}
__declspec(dllexport) void SetAuraParams(
        const char *entity_name, double size, double alpha,
        double colour_intensity, int hide_front_faces, int hide_back_faces,
        int alpha_mode
) {}
__declspec(dllexport) void SetAuraGradient(
        const char *entity_name, int gap, double r1, double g1, double b1,
        double alpha1, double starting_point, double r2, double g2, double b2,
        double alpha2, double ending_point
) {}
__declspec(dllexport) void IsValidEntity(const char *entity_name) {}
__declspec(dllexport) void GetEntityData(const char *entity_name) {}
__declspec(dllexport) void GetAttackList(const char *entity_name) {}
__declspec(dllexport) void ChangeEntityStatic(const char *entity_name, int is_static) {}
__declspec(dllexport) void ChangeEntityActor(const char *entity_name, int is_actor) {}
__declspec(dllexport) void ChangeEntityPerson(const char *entity_name, int is_person) {}
__declspec(dllexport) void ChangeEntityWeapon(const char *entity_name, int is_weapon) {}
__declspec(dllexport) void ChangeEntityArrow(const char *entity_name, int is_arrow) {}
__declspec(dllexport) void SetEntityData(const char *entity_name, void *data) {}
__declspec(dllexport) void SetAttackList(const char *entity_name, void *attack_list) {}
__declspec(dllexport) void SetEntityInternalState(
        const char *entity_name, void *internal_state
) {}
__declspec(dllexport) void GetEntityInternalState(
        const char *entity_name, void **internal_state
) {}
__declspec(dllexport) void CarringObject(const char *inv_name, const char *obj_name) {}
__declspec(dllexport) void GetRightBack(const char *inv_name) {}
__declspec(dllexport) void GetLeftBack(const char *inv_name) {}
__declspec(dllexport) void LinkRightHand(const char *inv_name, const char *obj_name) {}
__declspec(dllexport) void LinkLeftHand(const char *inv_name, const char *obj_name) {}
__declspec(dllexport) void LinkLeftHand2(const char *inv_name, const char *obj_name) {}
__declspec(dllexport) void LinkRightBack(const char *inv_name, const char *obj_name) {}
__declspec(dllexport) void LinkLeftBack(const char *inv_name, const char *obj_name) {}
__declspec(dllexport) void LinkBack(const char *inv_name, const char *obj_name) {}
__declspec(dllexport) void SetCurrentQuiver(const char *inv_name, const char *quiver_name) {}
__declspec(dllexport) void AddObject(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
) {}
__declspec(dllexport) void RemoveObject(
        const char *inv_name, int obj_type, const char *obj_name
) {}
__declspec(dllexport) void GetObject(const char *inv_name, int obj_type, int index) {}
__declspec(dllexport) void GetObjectByName(
        const char *inv_name, int obj_type, const char *obj_name
) {}
__declspec(dllexport) void GetSelectedObject(const char *inv_name, int obj_type) {}
__declspec(dllexport) void Cycle(const char *inv_name, int obj_type) {}
__declspec(dllexport) void IsSelected(const char *inv_name, int obj_type, int obj_index) {}
__declspec(dllexport) void GetNumberObjectsAt(const char *inv_name, int obj_type, int index) {}
__declspec(dllexport) void GetMaxNumberObjectsAt(
        const char *inv_name, int obj_type, int index
) {}
__declspec(dllexport) void GetActiveShield(const char *inv_name) {}
__declspec(dllexport) void GetActiveWeapon(const char *inv_name) {}
__declspec(dllexport) void GetActiveQuiver(const char *inv_name) {}
__declspec(dllexport) void AddWeapon(const char *inv_name, int flag, const char *weapon_name) {}
__declspec(dllexport) void GetInventoryStringProperty(
	const char *name, int property_kind, const char **value
) {}
__declspec(dllexport) void GetInventoryIntProperty(
        const char *name, int property_kind, int *value
) {}
__declspec(dllexport) void SetInventoryIntProperty(
        const char *name, int property_kind, int value
) {}
__declspec(dllexport) void SetListenerMode(int mode, double x, double y, double z) {}
__declspec(dllexport) void GetSectorByIndex(int index) {}
__declspec(dllexport) void GetSectorByPosition(double x, double y, double z) {}
__declspec(dllexport) void InitBreakSector(
        int sectorID, double x_vec1, double y_vec1, double z_vec1,
        double x_vec2, double y_vec2, double z_vec2, double x_vec3,
        double y_vec3, double z_vec3, const char *s_unknown, double d_unknown,
        int i_unknown
) {}
__declspec(dllexport) void DoBreakSector(
        int sectorID, double x_impulse, double y_impulse, double z_impulse,
        double x, double y, double z, double x_unknown, double y_unknown,
        double z_unknown
) {}
__declspec(dllexport) void GetSectorStringProperty(
        int sectorID, int property_kind, int index, const char **value
) {}
__declspec(dllexport) void SetSectorStringProperty(
        int sectorID, int property_kind, int index, const char *value
) {}
__declspec(dllexport) void GetSectorFloatProperty(
        int sectorID, int property_kind, int index, double *value
) {}
__declspec(dllexport) void SetSectorFloatProperty(
        int sectorID, int property_kind, int index, double value
) {}
__declspec(dllexport) void GetSectorIntProperty(
        int sectorID, int property_kind, int index, int *value
) {}
__declspec(dllexport) void SetSectorIntProperty(
        int sectorID, int property_kind, int index, int value
) {}
__declspec(dllexport) void GetSectorVectorProperty(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
) {}
__declspec(dllexport) void SetSectorVectorProperty(
        int sectorID, int property_kind, int index, double x,
        double y, double z
) {}
__declspec(dllexport) void GetSectorFuncProperty(
        int sectorID, int property_kind, int index, void **value
) {}
__declspec(dllexport) void SetSectorFuncProperty(
        int sectorID, int property_kind, int index, void *value
) {}
__declspec(dllexport) void GetCharByName(const char *name, const char *short_name) {}
__declspec(dllexport) void LoadAllAnimations(int charID) {}
__declspec(dllexport) void ChangeAnimation(
        int charID, const char *old_anm_name, const char *new_anm_name
) {}
__declspec(dllexport) void SetAnmDefaultPrefix(int charID, const char *prefix) {}
__declspec(dllexport) void AddAttack(int charID, const char *attack_name, const char *anm_name) {}
__declspec(dllexport) void AttackWindow(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
) {}
__declspec(dllexport) void AttackLevels(
        int charID, const char *anm_name, float level1, float level2
) {}
__declspec(dllexport) void AttackEnergyLevel(
        int charID, const char *anm_name, float  level
) {}
__declspec(dllexport) void AttackTypeFlag(int charID, const char *attack_name, int flag) {}
__declspec(dllexport) void AllowAttack(
        int charID, const char *attack_name, const char *keys,
        const char *previous, const char *previous_negative,
        const char *window_name, const char *weapon_kind
) {}
__declspec(dllexport) void MetaAttack(
        int charID, const char *meta_attack_name, const char *attack_name
) {}
__declspec(dllexport) void AssignTrail(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
) {}
__declspec(dllexport) void SetNCDSpheres(int charID, int NCDSpheres) {}
__declspec(dllexport) void SetCDSphere(int charID, int index, double h, double r) {}
__declspec(dllexport) void GetCharIntProperty(int charID, int property_kind, int index, int *value) {}
__declspec(dllexport) void SetCharIntProperty(int charID, int property_kind, int index, int value) {}
__declspec(dllexport) void GetCharFloatProperty(int charID, int property_kind, int index, double *value) {}
__declspec(dllexport) void SetCharFloatProperty(int charID, int property_kind, int index, double value) {}
__declspec(dllexport) void GetCharStringProperty(int charID, int property_kind, int index, const char **value) {}
__declspec(dllexport) void SetCharStringProperty(int charID, int property_kind, int index, const char *value) {}
__declspec(dllexport) void SetCharFuncProperty(int charID, int property_kind, int index, void *func) {}
__declspec(dllexport) void GetTrailByName(const char *name) {}
__declspec(dllexport) void GetTrailFloatProperty(
        int trailID, int property_kind, int index, double *value
) {}
__declspec(dllexport) void SetTrailFloatProperty(
        int trailID, int property_kind, int index, double value
) {}
__declspec(dllexport) void GetTrailVectorProperty(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
) {}
__declspec(dllexport) void SetTrailVectorProperty(
        int trailID, int property_kind, int index, double x, double y, double z
) {}
__declspec(dllexport) void CreateSound(const char *file_name, const char *sound_name) {}
__declspec(dllexport) void CreateSoundS(int soundID) {}
__declspec(dllexport) void DestroySound(int soundID) {}
__declspec(dllexport) void GetSoundDevInstace(void) {}
__declspec(dllexport) void GetGhostSectorSound(const char *gs_name) {}
__declspec(dllexport) void GetSoundStringProperty(int property_kind, int soundID) {}
__declspec(dllexport) void GetSoundFloatProperty(int property_kind, int soundID) {}
__declspec(dllexport) void SetSoundFloatProperty(int property_kind, int soundID, double value) {}
__declspec(dllexport) void SetSoundIntProperty(int property_kind, int soundID, int value) {}
__declspec(dllexport) void PlaySoundM(int soundID, double x, double y, double z, int i_unknown) {}
__declspec(dllexport) void PlaySoundStereo(int soundID, int i_unknown) {}
__declspec(dllexport) void SetSoundPitchVar(
        int soundID, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
) {}
__declspec(dllexport) void addSoundVar(int soundID, const char *alt_sound) {}
__declspec(dllexport) void StopSound(int soundID) {}
__declspec(dllexport) void CreateTimer(const char *timer_name, double period) {}
__declspec(dllexport) void GetnTimers(void) {}
__declspec(dllexport) void GetTimerInfo(
        int timer_index, const char **timer_name, double *period
) {}
__declspec(dllexport) void AddScheduledFunc(
        double time, void *func, void *args, const char *name
) {}
__declspec(dllexport) void RemoveScheduledFunc(const char *name) {}
__declspec(dllexport) void GetnScheduledFuncs(void) {}
__declspec(dllexport) void GetScheduledFunc(
        int index, void **func, void **args, const char **name,
        double *time
) {}
__declspec(dllexport) void nEntities(void) {}
__declspec(dllexport) void nSectors(void) {}
__declspec(dllexport) void GetTime(void) {}
__declspec(dllexport) void SetTime(double time) {}
__declspec(dllexport) void GoToTime(double time) {}
__declspec(dllexport) void StopTime(void) {}
__declspec(dllexport) void RestartTime(void) {}
__declspec(dllexport) void GetTimeSpeed(void) {}
__declspec(dllexport) void SetTimeSpeed(double speed) {}
__declspec(dllexport) void GetNewExclusionGroupId(void) {}
__declspec(dllexport) void AssocKey(
        const char *action, const char *input_device, const char *key,
        int press
) {}
__declspec(dllexport) void GetTimeActionHeld(const char *action_name) {}
__declspec(dllexport) void AddInputAction(const char *action_name, int npi) {}
__declspec(dllexport) void RemoveInputAction(const char *action_name) {}
__declspec(dllexport) void Bind(const char *action_name, void *proc) {}
__declspec(dllexport) void BindPred(const char *action_name, const char *predproc) {}
__declspec(dllexport) void Bind2(
        const char *action_name1, const char *action_name2,
        const char *new_action, int unknown
) {}
__declspec(dllexport) void UnBind(const char *action_name, void *proc) {}
__declspec(dllexport) void UnBindPred(const char *action_name, const char *predproc) {}
__declspec(dllexport) void UnBindAll(void) {}
__declspec(dllexport) void Input(const char *text) {}
__declspec(dllexport) void MarkLevelToLoad(const char *dir_name) {}
__declspec(dllexport) void ReadLevel(const char *file_name) {}
__declspec(dllexport) void CloseLevel(const char *statement1, const char *statement2) {}
__declspec(dllexport) void OutSound(int soundId, double x, double y, double z, int unknown) {}
__declspec(dllexport) void SetShowSounds(int showSounds) {}
__declspec(dllexport) void nSounds(void) {}
__declspec(dllexport) void GetSoundName(int soundId) {}
__declspec(dllexport) void GetSoundFileName(int soundId) {}
__declspec(dllexport) void ReadBitMap(const char *file_name, const char *internal_name) {}
__declspec(dllexport) void ReadAlphaBitMap(const char *file_name, const char *internal_name) {}
__declspec(dllexport) void SetSun(int exists, double x, double y, double z) {}
__declspec(dllexport) void InsideAA(int AA, double x, double y, double z) {}
__declspec(dllexport) void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame) {}
__declspec(dllexport) void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame) {}
__declspec(dllexport) void AnmDelEvent(const char *anm_name, const char *event_name) {}
__declspec(dllexport) void AnmClearEvents(const char *anm_name) {}
__declspec(dllexport) void AnmGetEventFrame(const char *anm_name, const char *event_name) {}
__declspec(dllexport) void AddParticleGType(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
) {}
__declspec(dllexport) void SetParticleGVal(
        const char *type, int i, int r, int g, int b, int alpha, double size
) {}
__declspec(dllexport) void GetnParticleGType(void) {}
__declspec(dllexport) void GetParticleGType(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
) {}
__declspec(dllexport) void GetParticleGVal(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
) {}
__declspec(dllexport) void GetEntitiesAt(
        double x, double y, double z, double radius, char ***entity_names
) {}
__declspec(dllexport) void GetEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
) {}
__declspec(dllexport) void GetObjectEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
) {}
__declspec(dllexport) void GetCombos(const char *person_name, void **combos) {}
__declspec(dllexport) void SetCombos(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
) {}
__declspec(dllexport) void GetWeaponCombos(
        const char *person_name, const char *weapon_kind, void **combos
) {}
__declspec(dllexport) void GetLastPlayerCType(void) {}
__declspec(dllexport) void GetEnemiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
) {}
__declspec(dllexport) void PlayCDTrack(int ntrack) {}
__declspec(dllexport) void nCDTracks(void) {}
__declspec(dllexport) void CDLenght(void) {}
__declspec(dllexport) void CDTrackLenght(int ntrack) {}
__declspec(dllexport) void CDPresent(void) {}
__declspec(dllexport) void CDStop(void) {}
__declspec(dllexport) void CDPause(void) {}
__declspec(dllexport) void CDSetCallBack(void *func) {}
__declspec(dllexport) void SetDefaultMass(const char *entity_kind, double mass) {}
__declspec(dllexport) void SetDefaultMaterial(const char *entity_kind, const char *material) {}
__declspec(dllexport) void GetMaterial(const char *name) {}
__declspec(dllexport) void GetMaterialI(int index) {}
__declspec(dllexport) void CreateMaterial(const char *name) {}
__declspec(dllexport) void AddHitSoundComb(
        void *material1, void *material2, int soundID
) {}
__declspec(dllexport) void GetMaterialFloatProperty(
        void *material, int property_kind, int index, double *value
) {}
__declspec(dllexport) void SetMaterialFloatProperty(
        void *material, int property_kind, int index, double value
) {}
__declspec(dllexport) void GetMaterialStringProperty(
        void *material, int property_kind, int index, const char **value
) {}
__declspec(dllexport) void GetMaterialSoundProperty(
        void *material, int property_kind, int index, int *soundID
) {}
__declspec(dllexport) void SetMaterialSoundProperty(
        void *material, int property_kind, int index, int soundID
) {}
__declspec(dllexport) void nMaterials(void) {}
__declspec(dllexport) void CreateGhostSector(
	const char *ghost_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	void *points
) {}
__declspec(dllexport) void CreateTriggerSector(
	const char *trigger_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	void *points
) {}
__declspec(dllexport) void SetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type, void *func
) {}
__declspec(dllexport) void GetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type
) {}
__declspec(dllexport) void SetTriggerSectorData(
        const char *trigger_sector_name, void *data
) {}
__declspec(dllexport) void GetTriggerSectorData(const char *trigger_sector_name) {}
__declspec(dllexport) void GetTriggerSectorFloorHeight(const char *trigger_sector_name) {}
__declspec(dllexport) void GetTriggerSectorRoofHeight(const char *trigger_sector_name) {}
__declspec(dllexport) void GetTriggerSectorGroup(const char *trigger_sector_name) {}
__declspec(dllexport) void GetTriggerSectorPoints(const char *trigger_sector_name) {}
__declspec(dllexport) void nTriggerSectors(void) {}
__declspec(dllexport) void GetTriggerSectorName(int index) {}
__declspec(dllexport) void GenerateEntityName(void) {}
__declspec(dllexport) void AddWatchAnim(const char *anim) {}
__declspec(dllexport) void AddAnimFlags(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
) {}
__declspec(dllexport) void SetEAX(int eax_flag) {}
__declspec(dllexport) void SetActionCameraMovement(
        const char *action_name, double angle, double start_pos, double end_pos
) {}
__declspec(dllexport) void DeactivateInput(void) {}
__declspec(dllexport) void ActivateInput(void) {}
__declspec(dllexport) void SetGhostSectorSound(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
) {}
__declspec(dllexport) void GetSound(const char *sound_name) {}
__declspec(dllexport) void SetGhostSectorGroupSound(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
) {}
__declspec(dllexport) void SetRootWidget(long int widget) {}
__declspec(dllexport) void GetRootWidget(void) {}
__declspec(dllexport) void AddCombustionDataFor(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
) {}
__declspec(dllexport) void SetAfterFrameFunc(const char *name, void *function) {}
__declspec(dllexport) void GetAfterFrameFunc(const char *name) {}
__declspec(dllexport) void GetnAfterFrameFuncs(void) {}
__declspec(dllexport) void GetAfterFrameFuncName(int index) {}
__declspec(dllexport) void RemoveAfterFrameFunc(const char *name) {}
__declspec(dllexport) void SetMenuTgapFunc(void *func) {}
__declspec(dllexport) void GetMenuTgapFunc(void) {}
__declspec(dllexport) void SetCallCheck(int check) {}
__declspec(dllexport) void DrawBOD(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
) {}
__declspec(dllexport) void SetShowAreas(int action_areas_bit_mask) {}
__declspec(dllexport) void WriteText(double x, double y, const char *text) {}
__declspec(dllexport) void GetTextWH(const char *text, double *w, double *h) {}
__declspec(dllexport) void GetScreenRect(
        double *x_min, double *y_min, double *x_max, double *y_max
) {}
__declspec(dllexport) void GetScreenXY(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
) {}
__declspec(dllexport) void CloseDebugChannel(const char *channel_name) {}
__declspec(dllexport) void OpenDebugChannel(const char *channel_name) {}
__declspec(dllexport) void SetAppMode(const char *mode) {}
__declspec(dllexport) void GetAppMode(void) {}
__declspec(dllexport) void GetCommandLine(void) {}
__declspec(dllexport) void Quit(void) {}
__declspec(dllexport) void LoadSampledAnimation(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
) {}
__declspec(dllexport) void CreateFCAnimation(
        const char *file, const char *internal_name, int n_armonics
) {}
__declspec(dllexport) void CreateDFCAnimation(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
) {}
__declspec(dllexport) void CreateBipedData(const char *biped_name, const char *kind) {}
__declspec(dllexport) void AddBipedAction(
        const char *char_name, const char *action_name,
        const char *animation_name, double d_unknown1, double d_unknown2,
        int i_unknown
) {}
__declspec(dllexport) void AddBipedActionC(
        const char *char_name, const char *action_name,
        const char *animation_name, const char *s_unknown, double d_unknown1,
        double d_unknown2, int i_unknown
) {}
__declspec(dllexport) void RemoveBipedAction(const char *s_unknown1, const char *s_unknown2) {}
__declspec(dllexport) void AddRStepEvent(const char *animation_name, double d_unknown) {}
__declspec(dllexport) void RStepEvents(const char *s_unknown1, const char *s_unknown2) {}
__declspec(dllexport) void LStepEvents(const char *s_unknown1, const char *s_unknown2) {}
__declspec(dllexport) void SetActionEventTable(
        const char *race_name, const char *action_name, const char *table_name
) {}
__declspec(dllexport) void SetEventTableFuncC(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
) {}
__declspec(dllexport) void SetEventTableFunc(
        const char *event_table_name, const char *event_type, void *func
) {}
__declspec(dllexport) void AddLStepEvent(const char *animation_name, double d_unknown) {}
__declspec(dllexport) void AddRReleaseEvent(const char *animation_name, double d_unknown) {}
__declspec(dllexport) void AddLReleaseEvent(const char *animation_name, double d_unknown) {}
__declspec(dllexport) void AddStopTests(const char *animation_name) {}
__declspec(dllexport) void AddFloorCTolerance(const char *animation_name, double tolerance) {}
__declspec(dllexport) void SetSolidMask(const char *kind, int mask) {}
__declspec(dllexport) void SetDrawObjectShadows(int draw) {}
__declspec(dllexport) void GetAutoEngageCombat(void) {}
__declspec(dllexport) void SetAutoEngageCombat(int auto_engage_combat) {}
__declspec(dllexport) void GetAecGap(void) {}
__declspec(dllexport) void SetAecGap(double aec_gap) {}
__declspec(dllexport) void GetDrawObjectShadows(void) {}
__declspec(dllexport) void GetModelPos(const char *person, double *x, double *y, double *z) {}
__declspec(dllexport) void GetCurrentMap(void) {}
__declspec(dllexport) void SetCurrentMap(const char *map) {}
__declspec(dllexport) void LoadWorld(const char *file_name) {}
__declspec(dllexport) void DoneLoadGame(void) {}
__declspec(dllexport) void BeginLoadGame(void) {}
__declspec(dllexport) void GetWindowId(void) {}
__declspec(dllexport) void GetProgramId(void) {}
__declspec(dllexport) void AddStepSound(const char *name, int soundID) {}
__declspec(dllexport) void AddMaterialStepSound(
        const char *table, const char *material, const char *step_sound
) {}
__declspec(dllexport) void AddActionStepSound(
        const char *table, const char *action, const char *step_sound_table
) {}
__declspec(dllexport) void AddTextureMaterial(const char *texture, const char *material) {}
__declspec(dllexport) void GetMusicEventPriority(int unknown) {}
__declspec(dllexport) void getMusicEvent(const char *event_name) {}
__declspec(dllexport) void exeMusicEvent(int unknown1, int unknown2) {}
__declspec(dllexport) void addMusicEventCD(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
) {}
__declspec(dllexport) void addMusicEventMP3(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
) {}
__declspec(dllexport) void addMusicEventWAV(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
) {}
__declspec(dllexport) void addMusicEventADPCM(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
) {}
__declspec(dllexport) void dropDebugInfo(void) {}
__declspec(dllexport) void loadSoundDataBase(const char *file_name) {}
__declspec(dllexport) void saveSoundDataBase(const char *file_name) {}
__declspec(dllexport) void loadMusicState(const char *file_name) {}
__declspec(dllexport) void saveMusicState(const char *file_name) {}
__declspec(dllexport) void TakeSnapShot(void) {}
__declspec(dllexport) void saveSoundStats(const char *file_name) {}
__declspec(dllexport) void GetMouseState(int *invert, double *xsens, double *ysens) {}
__declspec(dllexport) void SetMouseState(int invert, double xsens, double ysens) {}
__declspec(dllexport) void GetPSeconds(void) {}
__declspec(dllexport) void GetnRaces(void) {}
__declspec(dllexport) void GetRaceName(int index) {}
__declspec(dllexport) void BodInspector(void) {}
__declspec(dllexport) void SetRunString(const char *variable) {}
__declspec(dllexport) void SetStringValue(const char *variable, const char *value) {}
__declspec(dllexport) void GetStringValue(const char *variable) {}
__declspec(dllexport) void DeleteStringValue(const char *variable) {}
__declspec(dllexport) void SaveEntitiesData(const char *filename) {}
__declspec(dllexport) void LoadEntitiesData(const char *filename) {}
__declspec(dllexport) void SaveParticleSystemsData(const char *filename) {}
__declspec(dllexport) void LoadParticleSystemsData(const char *filename) {}
__declspec(dllexport) void SaveCombustionData(const char *file_name) {}
__declspec(dllexport) void LoadCombustionData(const char *file_name) {}
__declspec(dllexport) void ReassignCombustionData(void) {}
__declspec(dllexport) void SaveAnmRaceData(const char *file_name, const char *race) {}
__declspec(dllexport) void LoadAnmRaceData(const char *file_name) {}
__declspec(dllexport) void SaveAnmSoundData(const char *file_name, const char *race) {}
__declspec(dllexport) void LoadAnmSoundData(const char *file_name) {}
__declspec(dllexport) void GetSaveInfo(void) {}
__declspec(dllexport) void SetSaveInfo(void *info) {}
__declspec(dllexport) void OpenProfileSection(int section, const char *comment) {}
__declspec(dllexport) void CloseProfileSection(int section) {}
__declspec(dllexport) void StartProfile(void) {}
__declspec(dllexport) void EnableProfiler(void) {}
__declspec(dllexport) void DisableProfiler(void) {}
__declspec(dllexport) void SaveProfileData(const char *file_name) {}
__declspec(dllexport) void SetInputMode(const char *device, const char *mode) {}
__declspec(dllexport) void GetInputMode(const char *device) {}
__declspec(dllexport) void SaveScreeShoot(const char *filename, int width, int height) {}
__declspec(dllexport) void CleanArea(double x, double y, double z, float distance) {}
__declspec(dllexport) void NetServerChangeLevel(const char *level_name) {}
__declspec(dllexport) void SetLocalOptions(
        const char *name, const char *kind, const char *weapon,
        const char *shield, const char *map
) {}
__declspec(dllexport) void RestartNet(void) {}
__declspec(dllexport) void JoinSession(int index, const char *player_name) {}
__declspec(dllexport) void GetBrowseResult(int index, void *info) {}
__declspec(dllexport) void BrowseSessions(const char *ip_address) {}
__declspec(dllexport) void StartServer(
        const char *game_name, const char *player_name, int max_players,
        int TCP
) {}
__declspec(dllexport) void ServerInfoBlock(void) {}
__declspec(dllexport) void CallNetEventSound(const char *entity_name, int id) {}
__declspec(dllexport) void ClientSetPyClientSoundFunc(void *func) {}
__declspec(dllexport) void ClientSetPyClientMutilaFunc(void *func) {}
__declspec(dllexport) void ClientSetPyClientDamageFunc(void *func) {}
__declspec(dllexport) void NetAddSoundToClient(
        const char *entity_name, const char *animation_name,
        void *sound_object
) {}
__declspec(dllexport) void ClearPools(void) {}
__declspec(dllexport) void NetGetClientId(void) {}
__declspec(dllexport) void NetSetObjectState(const char *entity_name, int state) {}
__declspec(dllexport) void NetAddEventUserFunc(
        const char *action, void *func, int ignore_host
) {}
__declspec(dllexport) void NetAddPosition(double x, double y, double z) {}
__declspec(dllexport) void NetSetPersonView(const char *entity_name) {}
__declspec(dllexport) void GetLocalOptionsNet(
        const char **name, const char **kind, const char **weapon,
        const char **shield
) {}
__declspec(dllexport) void GetNextPosition(double *x, double *y, double *z) {}
__declspec(dllexport) void SendNetUserString(
        short kind, const char *str, int guaranteed, const char *str_unknown
) {}
__declspec(dllexport) void ServerSetPyGetUserString(void *func) {}
__declspec(dllexport) void ServerSetPyByePlayerFunc(void *func) {}
__declspec(dllexport) void GetLifeAndLevel(const char *entity_name, int *energy, int *life) {}
__declspec(dllexport) void GetNetState(void) {}
__declspec(dllexport) void ServerSetPyCreatePlayerFunc(void *func) {}
__declspec(dllexport) void ClientStartMainChar(void) {}
__declspec(dllexport) void ServerSetSendDataState(int state) {}
__declspec(dllexport) void NetGetTime(void) {}
__declspec(dllexport) void NetSetPPS(int PPS) {}
__declspec(dllexport) void IsValidProtocol(int protocol) {}
__declspec(dllexport) void GetDedicatedServerState(void) {}
__declspec(dllexport) void SetDedicatedServerState(int dedicated) {}
__declspec(dllexport) void PersonChangeAnmSoundIndex(const char *person_name, int index) {}
__declspec(dllexport) void StartGSQR(void) {}
__declspec(dllexport) void GetSplinePos(void *spline, float time, void *pos) {}
__declspec(dllexport) void AddNodeSpline(
        void *spline, int num_node, double time, double pos_x, double pos_y,
        double pos_z, double tang_i_x, double tang_i_y, double tang_i_z,
        double tang_j_x, double tang_j_y, double tang_j_z
) {}
__declspec(dllexport) void CloseSpline(void *spline) {}
__declspec(dllexport) void ClearSpline(void *spline) {}
 