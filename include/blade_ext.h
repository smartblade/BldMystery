
#ifndef BLADE_EXT_H

#define BLADE_EXT_H


#include <export.h>



LIB_EXP int SetListenerMode(int mode, double x, double y, double z);
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
LIB_EXP void UnBindAll(void);
LIB_EXP const char *Input(const char *text);
LIB_EXP void MarkLevelToLoad(const char *dir_name);
LIB_EXP void ReadLevel(const char *file_name);
LIB_EXP void ReadBitMap(const char *file_name, const char *internal_name);
LIB_EXP void ReadAlphaBitMap(const char *file_name, const char *internal_name);
LIB_EXP int AddParticleGType(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
);
LIB_EXP int SetParticleGVal(
        const char *type, int i, int r, int g, int b, int alpha, double size
);

LIB_EXP int CloseDebugChannel(const char *channel_name);
LIB_EXP void BodInspector(void);

#endif /* BLADE_EXT_H */
