
#ifndef BLADE_EXT_H

#define BLADE_EXT_H


#include <export.h>


typedef struct _entity_t entity_t;
typedef struct _material_t material_t;


#define CHR_FLT_TURN_SPEED                0
#define CHR_FLT_DIE_FALL                  1
#define CHR_FLT_J_COST                    4
#define CHR_FLT_MAX_FALL                  5
#define CHR_FLT_MAX_STAIR                 6
#define CHR_FLT_FOV                       7
#define CHR_FLT_MAX_GRAB                 10
#define CHR_FLT_MED_GRAB                 11
#define CHR_FLT_MIN_TAKE                 13
#define CHR_FLT_MAX_TAKE_1               14
#define CHR_FLT_MAX_TAKE_2               15
#define CHR_FLT_MAX_TAKE_3               16
#define CHR_FLT_MAX_TAKE_4               17
#define CHR_FLT_MAX_TAKE_5               18
#define CHR_FLT_REACH                    19
#define CHR_FLT_MIN_2_GRAB               20
#define CHR_FLT_HEAR_MIN_VOLUME          21
#define CHR_FLT_MOV_FRWD_SPEED_IN_STRAFE 22
#define CHR_FLT_MOV_BKWD_SPEED_IN_STRAFE 23
#define CHR_FLT_MAX_COMBAT_DIST          24
#define CHR_FLT_DIST_STOP                25
#define CHR_FLT_DIST_STOP_2              26
#define CHR_FLT_MAX_SEE_DIST             27
#define CHR_FLT_DIST_STOP_MAX_FACT       28

#define CHR_STR_INT_NAME                  0
#define CHR_STR_NO_ARMOUR                 3
#define CHR_STR_LOW_ARMOUR                4
#define CHR_STR_MED_ARMOUR                5
#define CHR_STR_HIGH_ARMOUR               6

#define CHR_INT_NATURAL_WEAPONS           0
#define CHR_INT_HEAD_CONTROLLED           1


LIB_EXP int WorldToMBW(const char *world);
LIB_EXP int SoundSystemActive(void);
LIB_EXP int SetSSFrecuency(int frequency);
LIB_EXP int SetSS2dChannels(int num_ch);
LIB_EXP int SetSS3dChannels(int num_ch);
LIB_EXP int SetSSFilter(int filter_output);
LIB_EXP int KillMusic(void);
LIB_EXP int ShutDownSoundChannels(void);
LIB_EXP int PauseSoundSystem(void);
LIB_EXP int PauseSoundSystemButMusic(void);
LIB_EXP int ResumeSoundSystem(void);
LIB_EXP entity_t *GetEntity(const char *name);
LIB_EXP entity_t *GetEntityI(int index);
LIB_EXP const char *GetEntityName(entity_t *entity);
LIB_EXP int SetListenerMode(int mode, double x, double y, double z);
LIB_EXP int GetSectorByIndex(int index);
LIB_EXP int GetSectorByPosition(double x, double y, double z);
LIB_EXP int GetCharByName(const char *name, const char *short_name);
LIB_EXP int SetNCDSpheres(int charID, int NCDSpheres);
LIB_EXP int SetCDSphere(int charID, int index, double h, double r);
LIB_EXP int GetCharIntProperty(int charID, int property_kind, int unknown, int *value);
LIB_EXP int GetCharFloatProperty(int charID, int property_kind, int unknown, double *value);
LIB_EXP int GetCharStringProperty(int charID, int property_kind, int unknown, const char **value);
LIB_EXP int CreateSound(const char *file_name, const char *sound_name);
LIB_EXP void DestroySound(int soundID);
LIB_EXP int GetSoundDevInstace(void);
LIB_EXP int CreateTimer(const char *timer_name, double period);
LIB_EXP int GetnTimers(void);
LIB_EXP int GetTimerInfo(
        int timer_index, const char **timer_name, double *period
);
LIB_EXP int AddScheduledFunc(
        double time, PyObject *func, PyObject *args, const char *name
);
LIB_EXP int RemoveScheduledFunc(const char *name);
LIB_EXP int GetnScheduledFuncs(void);
LIB_EXP int GetScheduledFunc(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
);
LIB_EXP int nEntities(void);
LIB_EXP int nSectors(void);
LIB_EXP double GetTime(void);
LIB_EXP int SetTime(double time);
LIB_EXP int GoToTime(double time);
LIB_EXP void StopTime(void);
LIB_EXP void RestartTime(void);
LIB_EXP double GetTimeSpeed(void);
LIB_EXP void SetTimeSpeed(double speed);
LIB_EXP int GetNewExclusionGroupId(void);
LIB_EXP int AssocKey(
        const char *action, const char *input_device, const char *key,
        int press
);
LIB_EXP double GetTimeActionHeld(const char *action_name);
LIB_EXP int AddInputAction(const char *action_name, int npi);
LIB_EXP int RemoveInputAction(const char *action_name);
LIB_EXP int Bind(const char *action_name, PyObject *proc);
LIB_EXP int BindPred(const char *action_name, const char *predproc);
LIB_EXP int Bind2(
        const char *action_name1, const char *action_name2,
        const char *new_action, int unknown
);
LIB_EXP int UnBind(const char *action_name, PyObject *proc);
LIB_EXP int UnBindPred(const char *action_name, const char *predproc);
LIB_EXP void UnBindAll(void);
LIB_EXP const char *Input(const char *text);
LIB_EXP void MarkLevelToLoad(const char *dir_name);
LIB_EXP void ReadLevel(const char *file_name);
LIB_EXP void CloseLevel(const char *statement1, const char *statement2);
LIB_EXP int OutSound(int soundId, double x, double y, double z, int unknown);
LIB_EXP int SetShowSounds(int showSounds);
LIB_EXP int nSounds(void);
LIB_EXP const char *GetSoundName(int soundId);
LIB_EXP const char *GetSoundFileName(int soundId);
LIB_EXP void ReadBitMap(const char *file_name, const char *internal_name);
LIB_EXP void ReadAlphaBitMap(const char *file_name, const char *internal_name);
LIB_EXP void SetSun(int exists, double x, double y, double z);
LIB_EXP int InsideAA(int AA, double x, double y, double z);
LIB_EXP void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame);
LIB_EXP void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame);
LIB_EXP void AnmDelEvent(const char *anm_name, const char *event_name);
LIB_EXP void AnmClearEvents(const char *anm_name);
LIB_EXP double AnmGetEventFrame(const char *anm_name, const char *event_name);
LIB_EXP int AddParticleGType(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
);
LIB_EXP int SetParticleGVal(
        const char *type, int i, int r, int g, int b, int alpha, double size
);
LIB_EXP int SetDefaultMaterial(const char *entity_kind, const char *material);
LIB_EXP material_t *CreateMaterial(const char *name);
LIB_EXP int CloseDebugChannel(const char *channel_name);
LIB_EXP int SetSolidMask(const char *kind, int mask);
LIB_EXP int AddStepSound(const char *name, int soundID);
LIB_EXP int AddMaterialStepSound(
        const char *table, const char *material, const char *step_sound
);
LIB_EXP int AddActionStepSound(
        const char *table, const char *action, const char *step_sound_table
);
LIB_EXP void BodInspector(void);
LIB_EXP int OpenProfileSection(int section, const char *comment);
LIB_EXP int CloseProfileSection(int section);

#endif /* BLADE_EXT_H */
