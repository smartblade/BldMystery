
#include "BWorld.h"
#include "sound_device.h"
#include <bld_abstract_net.h>
#include "anim.h"
#include "light.h"
#include "en_control.h"

class B_App;


class B_Race : public B_NamedObj
{
};

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
    char unknown_fields[52];
};

class B_ProcTexture
{
public:
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
    char unknown_fields[8];
    float width;
    float height;
};

class B_CharData
{
public:
    B_CharSize charSize[255];
};

class B_Font
{
public:
    char unknown_fields[40];
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

extern B_IDataFile * read_points(B_IDataFile *file, B_PtrArray<world_point_t> *points);
extern B_IDataFile * read_sectors(B_IDataFile *file, B_PtrArray<B_Sector> *sectors);
extern light_t *read_light(B_IDataFile *file);
extern anim_t *LoadFromHDAnim(const char *anm_name);
extern void Set007EA988To01(void);
extern void OnEvent(int a, int b);
extern void reset_client_map_name(void);
extern char *get_map_for_net_game(const char *map);
extern void LoadNetModule(char *fileName);

/*
* Module:                 Blade.exe
* Data address:           0x005DF898
*/
extern B_PtrArray<world_point_t> gbl_world_points;

/*
* Module:                 Blade.exe
* Data address:           0x005E0B88
*/
extern B_World B_world;

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
* Data address:           0x00736158
*/
extern B_PtrArray<B_ParticleGType> gbl_particle_types;

/*
* Module:                 Blade.exe
* Data address:           0x007C8ED0
*/
extern sound_t *gbl_sound_device;

/*
* Module:                 Blade.exe
* Data address:           0x007C9878
*/
extern B_PtrArray<B_Race> gbl_races;

/*
* Module:                 Blade.exe
* Data address:           0x007D1650
*/
extern B_PtrArray<B_Combustion> gbl_combustion_data;

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
* Data address:           0x007EE2C4
*/
extern bld_abstract_net *gbl_net;

/*
* Module:                 Blade.exe
* Data address:           0x007EFC94
*/
extern B_App *gbl_application;

#define NUM_3F266666 0.65f

#ifdef __cplusplus
}
#endif
