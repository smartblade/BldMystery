
#include <bld_system.h>
#include "Events.h"
#include "ProcessorTimer.h"
#include <Sound/Sound.h>
#include "bld_misc_funcs.h"


/* File:                  Matrix.cpp */
/* Begin of file:         0x00404BE0 */
/* End of file:           0x00407B50 */

/* File:                  Plane.cpp */
/* Begin of file:         0x00407B50 */
/* End of file:           0x00407E80 */



/* File:                  Polygon.cpp */
/* Begin of file:         0x00408270 */
/* End of file:           0x00409C20 */



/* File:                  Vector.cpp */
/* Begin of file:         0x0040A2A0 */
/* End of file:           0x0040AD10 */

/* File:                  Location.cpp */
/* Begin of file:         0x0040AD10 */
/* End of file:           0x0040B560 */



/* Begin of file:         0x0040CF10 */


/*
* Module:                 Blade.exe
* Entry point:            0x0040CF10
*/
#ifdef BLD_NATIVE
const char *ShowInputDialog(HINSTANCE module, HWND window, const char *text)
{
    return NULL;
}
#endif

/* End of file:           0x0040CFF0 */

/* Begin of file:         0x0040CFF0 */


/*
* Module:                 Blade.exe
* Entry point:            0x0040E8E6
*/
#ifdef BLD_NATIVE
int ShowStartupDialog(
    HMODULE module, HWND window, B_YSoundDev *sound, B_Name *rasterName,
    bool showDialog)
{
    return false;
}
#endif

/* End of file:           0x0040F040 */

/* File:                  WinApp.cpp */
/* Begin of file:         0x0040F040 */
/* End of file:           0x004111B0 */

/* File:                  App.cpp */
/* Begin of file:         0x004111B0 */
/* End of file:           0x004182F0 */



/* Begin of file:         0x00420980 */


/*
* Module:                 Blade.exe
* Entry point:            0x00422F3B
*/
#ifdef BLD_NATIVE
void JumpCB(const B_Name &action, float time, float, void *)
{
}
#endif

/* End of file:           0x004246C0 */



/* File:                  CDExt.cpp */
/* Begin of file:         0x00427750 */
/* End of file:           0x00427880 */

/* File:                  ObjExt.cpp */
/* Begin of file:         0x00427880 */
/* End of file:           0x0042D090 */

/* File:                  Atmosphere.cpp */
/* Begin of file:         0x0042D090 */
/* End of file:           0x0042D1F0 */

/* File:                  BMAP.CPP */
/* Begin of file:         0x0042D1F0 */
/* End of file:           0x004394B0 */

/* File:                  BWorld.cpp */
/* Begin of file:         0x004394B0 */
/* End of file:           0x00443190 */

/* File:                  WorldToMBW.cpp */
/* Begin of file:         0x00443190 */
/* End of file:           0x00443BC0 */



/* Begin of file:         0x00449EE0 */


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

/* End of file:           0x0044D320 */



/* File:                  MaterialExt.cpp */
/* Begin of file:         0x0044E9A0 */
/* End of file:           0x0044ED90 */

/* Begin of file:         0x0044ED90 */


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

/* End of file:           0x00453B10 */

/* File:                  Surface.cpp */
/* Begin of file:         0x00453B10 */
/* End of file:           0x0045C040 */

/* File:                  SectorFuncs.cpp */
/* Begin of file:         0x0045C040 */
/* End of file:           0x0045CEF0 */



/* File:                  AnimationExt.cpp */
/* Begin of file:         0x0046A9D0 */
/* End of file:           0x0046F070 */



/* Begin of file:         0x004755E0 */


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

/* End of file:           0x00477B90 */



/* File:                  Events.cpp */
/* Begin of file:         0x0048A740 */
/* End of file:           0x0048CBE0 */



/* Begin of file:         0x0048DB30 */


/*
* Module:                 Blade.exe
* Entry point:            0x0048DB30
* VC++ mangling:          ??0B_ProcessorTimer@@QAE@XZ
*/
#ifdef BLD_NATIVE
B_ProcessorTimer::B_ProcessorTimer()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0048DC31
* VC++ mangling:          ?GetTime@B_ProcessorTimer@@QAENXZ
*/
#ifdef BLD_NATIVE
double B_ProcessorTimer::GetTime()
{
    return 0.0;
}
#endif

/* End of file:           0x0048DE60 */



/* Begin of file:         0x00497AE0 */


/*
* Module:                 Blade.exe
* Entry point:            0x00497AE0
*/
#ifdef BLD_NATIVE
void unknown_00497AE0()
{
}
#endif

/* End of file:           0x00497D10 */



/* File:                  Sound/SoundFuncs.cpp */
/* Begin of file:         0x004BF1B0 */
/* End of file:           0x004C09A0 */



/* Begin of file:         0x004C2160 */


/*
* Module:                 Blade.exe
* Entry point:            0x004C21C6
* VC++ mangling:          ??0B_YSoundDev@@QAE@XZ
*/
#ifdef BLD_NATIVE_CONSTRUCTOR
B_YSoundDev::B_YSoundDev()
{
}
#endif

/* End of file:           0x004C5F40 */



/* File:                  WinClock.cpp */
/* Begin of file:         0x004CC1C0 */
/* End of file:           0x004CC640 */

/* Begin of file:         0x004CC640 */


/*
* Module:                 Blade.exe
* Entry point:            0x004CC8C8
*/
#ifdef BLD_NATIVE
bool GetCurrentDir(char *buffer, int bufferLength)
{
    return false;
}
#endif

/* End of file:           0x004CC950 */



/* Begin of file:         0x004CD580 */


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

/* End of file:           0x004CDB30 */


/* File:                  BipedEntity.cpp */
/* Begin of file:         0x004D5C40 */
/* End of file:           0x004EAD20 */

/* File:                  CameraEntity.cpp */
/* Begin of file:         0x004EAD20 */
/* End of file:           0x004EB650 */



/* Begin of file:         0x004F4E60 */


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

/* End of file:           0x004F8F80 */



/* File:                  EntityFuncs.cpp */
/* Begin of file:         0x004FFEA0 */
/* End of file:           0x0051DBE0 */



/* Begin of file:         0x005728B0 */


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

/* End of file:           0x005758C0 */



/* Begin of file:         0x00586880 */


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

/* End of file:           0x0058B630 */



/* File:                  en_control.cpp */
/* Begin of file:         0x00590480 */
/* End of file:           0x00596E90 */



/* File:                  simpleact.cpp */
/* Begin of file:         0x005A4F40 */
/* End of file:           0x005A74B0 */



/* Begin of file:         0x005AA730 */


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

/* End of file:           0x005AA920 */



/* File:                  datanet.cpp */
/* Begin of file:         0x005AC4F0 */
/* End of file:           0x005ACBC0 */

/* File:                  gamenet.cpp */
/* Begin of file:         0x005ACBC0 */
/* End of file:           0x005B5340 */

/* File:                  NetExt.cpp */
/* Begin of file:         0x005B5340 */
/* End of file:           0x005B64C0 */

/* File:                  libnet.cpp */
/* Begin of file:         0x005B64C0 */
/* End of file:           0x005B6880 */



/* File:                  BladeApp.cpp */
/* Begin of file:         0x005B9B60 */
/* End of file:           0x005B9C30 */


#ifdef BLD_NATIVE

class B_CameraEntity
{
public:
    B_CameraEntity(int, const B_Name &);
};

B_CameraEntity::B_CameraEntity(int, const B_Name &)
{
}

class B_YSoundDev
{
public:
    B_YSoundDev();
};

B_YSoundDev::B_YSoundDev()
{
}

#include "CDPlayer.h"

bool showStartupDialog;
int clientRectWidth;
int clientRectHeight;
B_WorldPoints gbl_world_points;
B_YSoundDev *unused_sound_ptr;
int gbl_sound_device_id;
B_Name *gbl_map_name;
B_Name *gbl_combustion_particle_names;
B_World B_world;
int gbl_action_areas_bit_mask;
B_PtrArray<anim_t> gbl_anims;
B_Events gbl_events;
B_PtrArray<B_ParticleGType> gbl_particle_types;
B_YSoundDev *gbl_sound_device;
B_Sound no_sound;
B_PtrArray<B_Race> gbl_races;
B_PtrArray<B_Combustion> gbl_combustion_data;
EnControl gbl_en_control;
B_PtrArray<B_AGTexture> gbl_ag_textures;
char client_map_name[128];
char net_game_name[128];
int gbl_net_max_players;
HMODULE netLibrary;
bld_abstract_net *gbl_net;
CloseConnectionFunc closeConnection;
bld_net_cb *netCallbacks;
GetNetInterfaceFunc getNetInterface;
B_WinApp *gbl_application;
CDPlayer *cdPlayer;

#endif
