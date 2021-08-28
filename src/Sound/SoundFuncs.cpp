
#include <bld_system.h>
#include "sound_device.h"
#include "bld_misc_funcs.h"
#define BUILD_LIB
#include <Sound/SoundFuncs.h>

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004BF1EF
*/

B_Sound *CreateSound(const char *file_name, const char *sound_name)
{
    if (gbl_sound_device == NULL)
        return &no_sound;
    return gbl_sound_device->CreateSound(
        file_name, sound_name, 1000.0f, 15000.0f, 1.0f, 1.0f, 1.0f);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF236
*/
#ifdef BLD_NATIVE
B_Sound *CreateSoundS(B_Sound * sound)
{
    B_Sound *(*bld_proc)(B_Sound * sound) = NULL;
    return bld_proc(sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF25D
*/
#ifdef BLD_NATIVE
void DestroySound(B_Sound * sound)
{
    void (*bld_proc)(B_Sound * sound) = NULL;
    bld_proc(sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF2A4
*/
#ifdef BLD_NATIVE
int SetSoundVolume(double volume)
{
    int (*bld_proc)(double volume) = NULL;
    return bld_proc(volume);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF2D8
*/
#ifdef BLD_NATIVE
double GetSoundVolume()
{
    double (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF2FE
*/
#ifdef BLD_NATIVE
int SoundSystemActive()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF31A
*/
#ifdef BLD_NATIVE
int SetSSFrecuency(int frequency)
{
    int (*bld_proc)(int frequency) = NULL;
    return bld_proc(frequency);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF34D
*/
#ifdef BLD_NATIVE
int SetSS2dChannels(int num_ch)
{
    int (*bld_proc)(int num_ch) = NULL;
    return bld_proc(num_ch);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF380
*/
#ifdef BLD_NATIVE
int SetSS3dChannels(int num_ch)
{
    int (*bld_proc)(int num_ch) = NULL;
    return bld_proc(num_ch);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF3B3
*/
#ifdef BLD_NATIVE
int SetSSFilter(int filter_output)
{
    int (*bld_proc)(int filter_output) = NULL;
    return bld_proc(filter_output);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF3E6
*/
#ifdef BLD_NATIVE
int KillMusic()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF410
*/
#ifdef BLD_NATIVE
int ShutDownSoundChannels()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF43A
*/
#ifdef BLD_NATIVE
int PauseSoundSystem()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF470
*/
#ifdef BLD_NATIVE
int PauseSoundSystemButMusic()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF492
*/
#ifdef BLD_NATIVE
int ResumeSoundSystem()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF4C8
*/
#ifdef BLD_NATIVE
int SetMusicVolume(float volume)
{
    int (*bld_proc)(float volume) = NULL;
    return bld_proc(volume);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF4F4
*/
#ifdef BLD_NATIVE
double GetMusicVolume()
{
    double (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF51A
*/
#ifdef BLD_NATIVE
int GetSSQuality()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF53C
*/
#ifdef BLD_NATIVE
int SetSSQuality(int SSQuality)
{
    int (*bld_proc)(int SSQuality) = NULL;
    return bld_proc(SSQuality);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF563
*/
#ifdef BLD_NATIVE
int GetSSSpeakerConfig()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF5E2
*/
#ifdef BLD_NATIVE
int SetEAXOverride(int EAXOverride)
{
    int (*bld_proc)(int EAXOverride) = NULL;
    return bld_proc(EAXOverride);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF63F
*/
#ifdef BLD_NATIVE
int GetEAXOverride()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF656
*/
#ifdef BLD_NATIVE
int SaveSSConfig()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF678
*/
#ifdef BLD_NATIVE
int SetSSSpeakerConfig(int config)
{
    int (*bld_proc)(int config) = NULL;
    return bld_proc(config);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF75B
*/
#ifdef BLD_NATIVE
int CreateGhostSector(
    const char *ghost_sector_name, const char *group_name,
    double floor_height, double roof_height, int num_points,
    point_2d_t *points
)
{
    int (*bld_proc)(
    const char *ghost_sector_name, const char *group_name,
    double floor_height, double roof_height, int num_points,
    point_2d_t *points
) = NULL;
    return bld_proc(ghost_sector_name, group_name, floor_height, roof_height, num_points, points);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF957
*/
#ifdef BLD_NATIVE
int SetEAX(int eax_flag)
{
    int (*bld_proc)(int eax_flag) = NULL;
    return bld_proc(eax_flag);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BF95E
*/
#ifdef BLD_NATIVE
int SetGhostSectorSound(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
)
{
    int (*bld_proc)(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
) = NULL;
    return bld_proc(aghost_name, file_name, volume, base_volume, min_dist, max_dist, v_max_dist, scale);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFEAB
*/
#ifdef BLD_NATIVE
B_Sound *GetGhostSectorSound(const char *gs_name)
{
    B_Sound *(*bld_proc)(const char *gs_name) = NULL;
    return bld_proc(gs_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFEEA
*/
#ifdef BLD_NATIVE
int SetGhostSectorGroupSound(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
)
{
    int (*bld_proc)(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
) = NULL;
    return bld_proc(group_name, file_name, volume, base_volume, min_dist, max_dist, unknown, scale);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFEF1
*/
#ifdef BLD_NATIVE
int SetShowSounds(int showSounds)
{
    int (*bld_proc)(int showSounds) = NULL;
    return bld_proc(showSounds);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFEFB
*/

int GetSoundDevInstace()
{
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFF02
*/
#ifdef BLD_NATIVE
int nSounds()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFF27
*/
#ifdef BLD_NATIVE
const char *GetSoundName(int soundId)
{
    const char *(*bld_proc)(int soundId) = NULL;
    return bld_proc(soundId);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFF44
*/
#ifdef BLD_NATIVE
const char *GetSoundFileName(int soundId)
{
    const char *(*bld_proc)(int soundId) = NULL;
    return bld_proc(soundId);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFF6E
*/
#ifdef BLD_NATIVE
int PlaySoundM(B_Sound *sound, double x, double y, double z, int i_unknown)
{
    int (*bld_proc)(B_Sound *sound, double x, double y, double z, int i_unknown) = NULL;
    return bld_proc(sound, x, y, z, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004BFFEE
*/
#ifdef BLD_NATIVE
int PlaySoundStereo(B_Sound *sound, int i_unknown)
{
    int (*bld_proc)(B_Sound *sound, int i_unknown) = NULL;
    return bld_proc(sound, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C003B
*/
#ifdef BLD_NATIVE
int StopSound(B_Sound *sound)
{
    int (*bld_proc)(B_Sound *sound) = NULL;
    return bld_proc(sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0082
*/
#ifdef BLD_NATIVE
double GetSoundFloatProperty(int property_kind, B_Sound *sound)
{
    double (*bld_proc)(int property_kind, B_Sound *sound) = NULL;
    return bld_proc(property_kind, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0143
*/
#ifdef BLD_NATIVE
void SetSoundFloatProperty(int property_kind, B_Sound *sound, double value)
{
    void (*bld_proc)(int property_kind, B_Sound *sound, double value) = NULL;
    bld_proc(property_kind, sound, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0293
*/
#ifdef BLD_NATIVE
char *GetSoundStringProperty(int property_kind, B_Sound *sound)
{
    char *(*bld_proc)(int property_kind, B_Sound *sound) = NULL;
    return bld_proc(property_kind, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C02E9
*/
#ifdef BLD_NATIVE
// TODO fix prototype
void SetSoundStringProperty()
{
        assert("SetSoundStringProperty" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C02F0
*/
#ifdef BLD_NATIVE
// TODO fix prototype
void GetSoundIntProperty()
{
        assert("GetSoundIntProperty" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C033D
*/

int SetSoundIntProperty(int property_kind, B_Sound *sound, int value)
{
    assert(sound);
    if (gbl_sound_device == NULL)
        return false;
    switch (property_kind)
    {
        case SND_INT_SEND_NOTIFY:
            sound->sendNotify = (value != 0);
            return true;
        default:
            return false;
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0394
*/
#ifdef BLD_NATIVE
void SetSoundPitchVar(
        B_Sound *sound, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
)
{
    void (*bld_proc)(
        B_Sound *sound, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
) = NULL;
    bld_proc(sound, i_unknown, f_unknown1, f_unknown2, f_unknown3, f_unknown4);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C03B7
*/
#ifdef BLD_NATIVE
// TODO fix prototype
void GetSoundFuncProperty()
{
        assert("GetSoundFuncProperty" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0436
*/
#ifdef BLD_NATIVE
// TODO fix prototype
void SetSoundFuncProperty()
{
        assert("SetSoundFuncProperty" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0508
*/
#ifdef BLD_NATIVE
int dropDebugInfo()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C052F
*/
#ifdef BLD_NATIVE
int GetMusicEventPriority(int unknown)
{
    int (*bld_proc)(int unknown) = NULL;
    return bld_proc(unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0550
*/
#ifdef BLD_NATIVE
int getMusicEvent(const char *event_name)
{
    int (*bld_proc)(const char *event_name) = NULL;
    return bld_proc(event_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0571
*/
#ifdef BLD_NATIVE
int exeMusicEvent(int unknown1, int unknown2)
{
    int (*bld_proc)(int unknown1, int unknown2) = NULL;
    return bld_proc(unknown1, unknown2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C05A0
*/
#ifdef BLD_NATIVE
int addMusicEventCD(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
)
{
    int (*bld_proc)(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
) = NULL;
    return bld_proc(lpszEventName, iTrack, dFIn, dFOut, fVolume, fPriority, bBackGround, iNext);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C05F5
*/
#ifdef BLD_NATIVE
int addMusicEventMP3(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
)
{
    int (*bld_proc)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
) = NULL;
    return bld_proc(lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C064B
*/
#ifdef BLD_NATIVE
int addMusicEventWAV(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
)
{
    int (*bld_proc)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
) = NULL;
    return bld_proc(lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, opened);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C06A1
*/
#ifdef BLD_NATIVE
int addMusicEventADPCM(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
)
{
    int (*bld_proc)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
) = NULL;
    return bld_proc(lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C06F7
*/
#ifdef BLD_NATIVE
B_Sound *GetSound(const char *sound_name)
{
    B_Sound *(*bld_proc)(const char *sound_name) = NULL;
    return bld_proc(sound_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C071E
*/
#ifdef BLD_NATIVE
int addSoundVar(B_Sound *sound, const char *alt_sound)
{
    int (*bld_proc)(B_Sound *sound, const char *alt_sound) = NULL;
    return bld_proc(sound, alt_sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0750
*/
#ifdef BLD_NATIVE
void saveSoundStats(const char *file_name)
{
    void (*bld_proc)(const char *file_name) = NULL;
    bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0779
*/
#ifdef BLD_NATIVE
int loadMusicState(const char *file_name)
{
    int (*bld_proc)(const char *file_name) = NULL;
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C07D1
*/
#ifdef BLD_NATIVE
int saveMusicState(const char *file_name)
{
    int (*bld_proc)(const char *file_name) = NULL;
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C0897
*/
#ifdef BLD_NATIVE
int loadSoundDataBase(const char *file_name)
{
    int (*bld_proc)(const char *file_name) = NULL;
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004C08F0
*/
#ifdef BLD_NATIVE
int saveSoundDataBase(const char *file_name)
{
    int (*bld_proc)(const char *file_name) = NULL;
    return bld_proc(file_name);
}
#endif