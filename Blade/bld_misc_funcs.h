
#include "App.h"
#include "game_state.h"
#include "sound_device.h"
#include <bld_abstract_net.h>
#include "light.h"

class anim_t;

class B_Race : public B_NamedObj
{
};

class B_Combustion : public B_NamedObj
{
public:
    B_Combustion() : a00C(16, 1), unknown0024(0)
    {
    }
private:
    array_t<void *> a00C;
    int unknown0024;
    char unknown_fields[52];
};

extern B_IDataFile& operator >>(B_IDataFile& file, B_Vector &point);
extern B_IDataFile& operator >>(B_IDataFile& file, B_Combustion &combustion);
extern B_ODataFile& operator <<(
    B_ODataFile &file,
    const B_Combustion &combustion);

#ifdef __cplusplus
extern "C" {
#endif

extern B_IDataFile * read_points(B_IDataFile *file, array_t<world_point_t *> *points);
extern B_IDataFile * read_sectors(B_IDataFile *file, array_t<sector_t *> *sectors);
extern light_t *read_light(B_IDataFile *file);
extern void Set007EA988To01(void);
extern void OnEvent(int a, int b);
extern void reset_client_map_name(void);
extern char *get_map_for_net_game(const char *map);
extern void LoadNetModule(char *fileName);

/*
* Module:                 Blade.exe
* Data address:           0x005DF898
*/
extern array_t<world_point_t*> gbl_world_points;

/*
* Module:                 Blade.exe
* Data address:           0x005E0B88
*/
extern game_state_t gbl_game_state;


/*
* Module:                 Blade.exe
* Data address:           0x007072A8
*/
extern array_t<anim_t *> gbl_anims;

/*
* Module:                 Blade.exe
* Data address:           0x00736158
*/
extern array_t<B_ParticleGType *> gbl_particle_types;

/*
* Module:                 Blade.exe
* Data address:           0x007C8ED0
*/
extern sound_t *gbl_sound_device;

/*
* Module:                 Blade.exe
* Data address:           0x007C9878
*/
extern array_t<B_Race *> gbl_races;

/*
* Module:                 Blade.exe
* Data address:           0x007D1650
*/
extern array_t<B_Combustion *> gbl_combustion_data;

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
