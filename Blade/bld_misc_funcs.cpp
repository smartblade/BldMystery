
#include <bld_system.h>
#include "App.h"
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x004088F4
*/

#ifdef BLD_NATIVE

B_IDataFile * read_points(B_IDataFile *file, array_t<world_point_t *> *points)
{
    return NULL;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0040ACDD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

B_IDataFile& operator >>(B_IDataFile& file, B_Vector &point)
{
    return file;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00432379
*/

#ifdef BLD_NATIVE

B_IDataFile * read_sectors(B_IDataFile *file, array_t<sector_t *> *sectors)
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
* Entry point:            0x004EAD20
* VC++ mangling:          ??0camera_t@@QAE@HABVB_Name@@@Z
*/

#ifdef BLD_NATIVE

camera_t::camera_t(int unknown, const B_Name &name)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x004EB1AA
* VC++ mangling:          ?unknown_004EB1AA@camera_t@@QAEXPAX@Z
*/

#ifdef BLD_NATIVE

void camera_t::unknown_004EB1AA(void *)
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
* Entry point:            0x005AC791
*/

#ifdef BLD_NATIVE

void Set007EA988To01()
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
