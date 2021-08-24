
#include <BWorld/BWorld.h>
#include <AnalyticGeometry/Polygon.h>
#include <bld_abstract_net.h>
#include <Control/anim.h>
#include <NetMod/libnet.h>
#include <BWorld/light.h>
#include <Entities/SolidMask.h>
#include <Control/Events.h>
#include <enemies/en_control.h>

class B_Events;
class B_WinApp;
class bld_net_cb;
class B_Sound;
class B_YSoundDev;


class B_Combustion : public B_NamedObj
{
public:
    B_Combustion() : unknown0024(0)
    {
    }
    B_Combustion(
        const B_Name &object_kind, const B_Name &fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
    );
private:
    B_PtrArray<void> a00C;
    int unknown0024;
    char unknown_fields028[32];
public:
    B_ParticleGType *particleType;
    char unknown_fields04C[16];
};

class B_ProcTexture
{
public:
    static void SetTime(double time);
    virtual ~B_ProcTexture();
    void Update();

    void *data;
};

class B_AGTexture
{
public:
    int textureEffect;
    int needUpdate;
    B_ProcTexture *procTexture;
    long bmp_handle;
};

struct B_CharSize
{
    float x;
    float y;
    float width;
    float height;
};

class B_CharData
{
public:
    B_CharSize charSize[256];
};

class B_Font : public B_NamedObj
{
public:
    char unknown_fields[28];
    B_CharData *charData;
};

class Unknown004CD5EC
{
public:
    Unknown004CD5EC(float a, float b, float c, float d, float e, float f);
    void unknown004CD634();

    float unknown000;
    float unknown004;
    float unknown008;
    float unknown00C;
    float unknown010;
    float unknown014;
    char unknown_fields[772];
};

extern B_IDataFile& operator >>(B_IDataFile& file, B_Combustion &combustion);
extern B_ODataFile& operator <<(
    B_ODataFile &file,
    const B_Combustion &combustion);

#ifdef __cplusplus
extern "C" {
#endif

extern const char *ShowInputDialog(HINSTANCE module, HWND window, const char *text);
extern int ShowStartupDialog(
    HMODULE module, HWND window, B_YSoundDev *sound, B_Name *rasterName,
    bool showDialog);
extern void JumpCB(const B_Name &action, float time, float, void *);
extern light_t *read_light(B_IDataFile *file);
extern void unknown_00497AE0();
extern int newExclusionGroupId();
extern bool GetCurrentDir(char *buffer, int bufferLength);
extern void InspectBODList();

/*
* Module:                 Blade.exe
* Data address:           0x005CCEB8
*/
extern bool showStartupDialog;

/*
* Module:                 Blade.exe
* Data address:           0x005CCEBC
*/
extern int clientRectWidth;

/*
* Module:                 Blade.exe
* Data address:           0x005CCEC0
*/
extern int clientRectHeight;

/*
* Module:                 Blade.exe
* Data address:           0x005DF898
*/
extern B_WorldPoints gbl_world_points;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB3C
*/
extern B_YSoundDev *unused_sound_ptr;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB40
*/
extern int gbl_sound_device_id;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB44
*/
extern B_Name *gbl_map_name;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB58
*/
extern B_Name *gbl_combustion_particle_names;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB90
*/
extern float frameUpdateTime;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB94
*/
extern float worldUpdateTime;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB9C
*/
extern int unknown005DFB9C;

/*
* Module:                 Blade.exe
* Data address:           0x005DFBA4
*/
extern int unknown005DFBA4;

/*
* Module:                 Blade.exe
* Data address:           0x005DFBA8
*/
extern int unknown005DFBA8;

/*
* Module:                 Blade.exe
* Data address:           0x005E2514
*/
extern int gbl_action_areas_bit_mask;

/*
* Module:                 Blade.exe
* Data address:           0x007072A8
*/
extern B_PtrArray<anim_t> gbl_anims;

/*
* Module:                 Blade.exe
* Data address:           0x007072F8
*/
extern B_Hash<B_EventFuncC> gbl_predefined_funcs;

/*
* Module:                 Blade.exe
* Data address:           0x00708B48
*/
extern B_Hash<B_EventFuncs> gbl_event_tables;

/*
* Module:                 Blade.exe
* Data address:           0x0070A358
*/
extern B_Events gbl_events;

/*
* Module:                 Blade.exe
* Data address:           0x00736158
*/
extern B_PtrArray<B_ParticleGType> gbl_particle_types;

/*
* Module:                 Blade.exe
* Data address:           0x007C8ED0
*/
extern B_YSoundDev *gbl_sound_device;

/*
* Module:                 Blade.exe
* Data address:           0x007C8ED8
*/
extern B_Sound no_sound;

/*
* Module:                 Blade.exe
* Data address:           0x007D1650
*/
extern B_PtrArray<B_Combustion> gbl_combustion_data;

/*
* Module:                 Blade.exe
* Data address:           0x007D40D0
*/
extern B_PtrArray<B_SolidMask> gbl_solid_masks;

/*
* Module:                 Blade.exe
* Data address:           0x007E93B8
*/
extern EnControl gbl_en_control;

/*
* Module:                 Blade.exe
* Data address:           0x007E988C
*/
extern B_PtrArray<B_AGTexture> gbl_ag_textures;

/*
* Module:                 Blade.exe
* Data address:           0x007EE018
*/
extern char client_map_name[128];

/*
* Module:                 Blade.exe
* Data address:           0x007EE0B8
*/
extern char net_game_name[128];

/*
* Module:                 Blade.exe
* Data address:           0x007EE138
*/
extern int gbl_net_max_players;

/*
* Module:                 Blade.exe
* Data address:           0x007EE1C0
*/
extern HMODULE netLibrary;

/*
* Module:                 Blade.exe
* Data address:           0x007EE2C4
*/
extern bld_abstract_net *gbl_net;

/*
* Module:                 Blade.exe
* Data address:           0x007EE2C8
*/
extern CloseConnectionFunc closeConnection;

/*
* Module:                 Blade.exe
* Data address:           0x007EE34C
*/
extern bld_net_cb *netCallbacks;

/*
* Module:                 Blade.exe
* Data address:           0x007EE350
*/
extern GetNetInterfaceFunc getNetInterface;

/*
* Module:                 Blade.exe
* Data address:           0x007EFC94
*/
extern B_WinApp *gbl_application;

#define NUM_3F266666 0.65f

#ifdef __cplusplus
}
#endif
