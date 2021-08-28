#ifndef SOUND_FUNCS_H

#define SOUND_FUNCS_H

#include <Point2D.h>
#include <export.h>

class B_Sound;


#define SND_INT_SEND_NOTIFY               0

#define SND_FLT_MIN_DISTANCE              0
#define SND_FLT_MAX_DISTANCE              1
#define SND_FLT_VOLUME                    2
#define SND_FLT_BASE_VOLUME               3
#define SND_FLT_SCALE                     4
#define SND_FLT_PITCH                     5

#define SND_STR_NAME                      0


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP B_Sound *CreateSound(const char *file_name, const char *sound_name);
LIB_EXP B_Sound *CreateSoundS(B_Sound * sound);
LIB_EXP void DestroySound(B_Sound * sound);
LIB_EXP int SetSoundVolume(double volume);
LIB_EXP double GetSoundVolume(void);
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
LIB_EXP int SetMusicVolume(float volume);
LIB_EXP double GetMusicVolume(void);
LIB_EXP int GetSSQuality(void);
LIB_EXP int SetSSQuality(int SSQuality);
LIB_EXP int GetSSSpeakerConfig(void);
LIB_EXP int SetEAXOverride(int EAXOverride);
LIB_EXP int GetEAXOverride(void);
LIB_EXP int SaveSSConfig(void);
LIB_EXP int SetSSSpeakerConfig(int config);
LIB_EXP int CreateGhostSector(
    const char *ghost_sector_name, const char *group_name,
    double floor_height, double roof_height, int num_points,
    point_2d_t *points
);
LIB_EXP int SetEAX(int eax_flag);
LIB_EXP int SetGhostSectorSound(
    const char *aghost_name, const char *file_name, double volume,
    double base_volume, double min_dist, double max_dist, double v_max_dist,
    double scale
);
LIB_EXP B_Sound *GetGhostSectorSound(const char *gs_name);
LIB_EXP int SetGhostSectorGroupSound(
    const char *group_name, const char *file_name, double volume,
    double base_volume, double min_dist, double max_dist, double unknown,
    double scale
);
LIB_EXP int SetShowSounds(int showSounds);
LIB_EXP int GetSoundDevInstace(void);
LIB_EXP int nSounds(void);
LIB_EXP const char *GetSoundName(int soundId);
LIB_EXP const char *GetSoundFileName(int soundId);
LIB_EXP int PlaySoundM(B_Sound *sound, double x, double y, double z, int i_unknown);
LIB_EXP int PlaySoundStereo(B_Sound *sound, int i_unknown);
LIB_EXP int StopSound(B_Sound *sound);
LIB_EXP double GetSoundFloatProperty(int property_kind, B_Sound *sound);
LIB_EXP void SetSoundFloatProperty(int property_kind, B_Sound *sound, double value);
LIB_EXP char *GetSoundStringProperty(int property_kind, B_Sound *sound);
LIB_EXP int SetSoundIntProperty(int property_kind, B_Sound *sound, int value);
LIB_EXP void SetSoundPitchVar(
    B_Sound *sound, int i_unknown, float f_unknown1, float f_unknown2,
    float f_unknown3, float f_unknown4
);
LIB_EXP int dropDebugInfo(void);
LIB_EXP int GetMusicEventPriority(int unknown);
LIB_EXP int getMusicEvent(const char *event_name);
LIB_EXP int exeMusicEvent(int unknown1, int unknown2);
LIB_EXP int addMusicEventCD(
    const char *lpszEventName, int iTrack, double dFIn, double dFOut,
    float fVolume, float fPriority, int bBackGround, int iNext
);
LIB_EXP int addMusicEventMP3(
    const char *lpszEventName, const char *lpszFile, double dFIn,
    float fVolume, double dFOut, float fPriority, int bBackGround,
    int iNext, int unknown
);
LIB_EXP int addMusicEventWAV(
    const char *lpszEventName, const char *lpszFile, double dFIn,
    float fVolume, double dFOut, float fPriority, int bBackGround,
    int iNext, int opened
);
LIB_EXP int addMusicEventADPCM(
    const char *lpszEventName, const char *lpszFile, double dFIn,
    float fVolume, double dFOut, float fPriority, int bBackGround,
    int iNext, int unknown
);
LIB_EXP B_Sound *GetSound(const char *sound_name);
LIB_EXP int addSoundVar(B_Sound *sound, const char *alt_sound);
LIB_EXP void saveSoundStats(const char *file_name);
LIB_EXP int loadMusicState(const char *file_name);
LIB_EXP int saveMusicState(const char *file_name);
LIB_EXP int loadSoundDataBase(const char *file_name);
LIB_EXP int saveSoundDataBase(const char *file_name);


#ifdef __cplusplus
}
#endif

#endif /* SOUND_FUNCS_H */
