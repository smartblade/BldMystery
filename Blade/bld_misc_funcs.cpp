
#include <bld_system.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x004088F4
*/

#ifdef BLD_NATIVE

B_IDataFile * read_points(B_IDataFile *file, B_PtrArray<world_point_t> *points)
{
    return NULL;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00432379
*/

#ifdef BLD_NATIVE

B_IDataFile * read_sectors(B_IDataFile *file, B_PtrArray<B_Sector> *sectors)
{
    return NULL;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0044AD38
*/

#ifdef BLD_NATIVE

light_t * read_light(B_IDataFile *file)
{
    return NULL;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00451A21
* VC++ mangling:          ?unknown_00451A21@unknown_18F8_class@@QAEXPAXHH@Z
*/

#ifdef BLD_NATIVE

void unknown_18F8_class::unknown_00451A21(void *, int, int)
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00475B9C
* VC++ mangling:          ??0anim_t@@QAE@XZ
*/

#ifdef BLD_NATIVE

anim_t::anim_t()
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00475EEB
* VC++ mangling:          ?AddEvent@anim_t@@QAEXABVB_Name@@M@Z
*/
#ifdef BLD_NATIVE
void anim_t::AddEvent(const B_Name &event_name, float event_frame)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00475F86
* VC++ mangling:          ?DelEvent@anim_t@@QAEXABVB_Name@@@Z
*/
#ifdef BLD_NATIVE
void anim_t::DelEvent(const B_Name &event_name)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00476014
* VC++ mangling:          ?ClearEvents@anim_t@@QAEXXZ
*/
#ifdef BLD_NATIVE
void anim_t::ClearEvents()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00476057
* VC++ mangling:          ?GetEventFrame@anim_t@@QAEMABVB_Name@@@Z
*/
#ifdef BLD_NATIVE
float anim_t::GetEventFrame(const B_Name &event_name)
{
    return -1.0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004760A2
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@PAVanim_t@@@Z
*/

#ifdef BLD_NATIVE

B_IDataFile &operator >>(B_IDataFile &file, anim_t *anim)
{
    return file;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004CD5EC
* VC++ mangling:          ??0Unknown004CD5EC@@QAE@MMMMMM@Z
*/
#ifdef BLD_NATIVE
Unknown004CD5EC::Unknown004CD5EC(float a, float b, float c, float d, float e, float f)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004CD634
* VC++ mangling:          ?unknown004CD634@Unknown004CD5EC@@QAEXXZ
*/
#ifdef BLD_NATIVE
void Unknown004CD5EC::unknown004CD634()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004F65BE
* VC++ mangling:          ??0B_Combustion@@QAE@ABVB_Name@@0NNNNNN@Z
*/
#ifdef BLD_NATIVE
B_Combustion::B_Combustion(
    const B_Name &object_kind, const B_Name &fire_kind, double upper_treshol,
    double lower_treshold, double flame_height, double flame_size,
    double speed, double livetime)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004F69A4
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Combustion@@@Z
*/

#ifdef BLD_NATIVE

B_IDataFile& operator >>(B_IDataFile& file, B_Combustion &combustion)
{
    return file;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004F6C54
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Combustion@@@Z
*/

#ifdef BLD_NATIVE

B_ODataFile& operator <<(B_ODataFile &file, const B_Combustion &combustion)
{
    return file;
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00572D73
* VC++ mangling:          ?InsideAA@unknown204@@QAEHH@Z
*/

#ifdef BLD_NATIVE

int unknown204::InsideAA(int AA)
{
    return 0;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00588F43
*/
#ifdef BLD_NATIVE
anim_t *LoadFromHDAnim(const char *anm_name)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005AC791
*/

#ifdef BLD_NATIVE

void Set007EA988To01()
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x005AA881
* VC++ mangling:          ?Update@B_ProcTexture@@QAEXXZ
*/
#ifdef BLD_NATIVE
void B_ProcTexture::Update()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005AF2CE
*/

#ifdef BLD_NATIVE

void OnEvent(int a, int b)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B1431
*/

#ifdef BLD_NATIVE

void reset_client_map_name()
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B143D
*/

#ifdef BLD_NATIVE

char *get_map_for_net_game(const char *map)
{
    return NULL;
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B65D2
*/

#ifdef BLD_NATIVE

void LoadNetModule(char *fileName)
{
}

#endif

#ifdef BLD_NATIVE

class B_WinApp
{
public:
    B_WinApp(void *, int, char *, void *);
};

B_WinApp::B_WinApp(void *, int, char *, void *)
{
}

class B_CameraEntity
{
public:
    B_CameraEntity(int, const B_Name &);
};

B_CameraEntity::B_CameraEntity(int, const B_Name &)
{
}

#include "CDPlayer.h"

int clientRectWidth;
int clientRectHeight;
B_PtrArray<world_point_t> gbl_world_points;
B_World B_world;
int gbl_action_areas_bit_mask;
B_PtrArray<anim_t> gbl_anims;
B_PtrArray<B_ParticleGType> gbl_particle_types;
sound_t *gbl_sound_device;
B_PtrArray<B_Race> gbl_races;
B_PtrArray<B_Combustion> gbl_combustion_data;
EnControl gbl_en_control;
B_PtrArray<B_AGTexture> gbl_ag_textures;
char client_map_name[128];
char net_game_name[128];
int gbl_net_max_players;
bld_abstract_net *gbl_net;
B_WinApp *gbl_application;
CDPlayer *cdPlayer;

#endif
