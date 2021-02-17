
#include <bld_system.h>
#include <raster_device.h>
#include <BWorld/BWorld.h>
#include <BWorld/BMap.h>
#include <BWorld/light.h>
#include "bld_misc_funcs.h"


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00439F5D
* VC++ mangling:          ?unknown_00439F5D@B_World@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_World::unknown_00439F5D()
{
}

#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0043A6A4
* VC++ mangling:          ?GetTime@B_World@@QAENXZ
*/
#ifdef BLD_NATIVE
double B_World::GetTime()
{
    return 0.0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043A6B8
* VC++ mangling:          ?SetTime@B_World@@QAEHN@Z
*/
#ifdef BLD_NATIVE
int B_World::SetTime(double time)
{
    return true;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0043AC07
* VC++ mangling:          ?GoToTime@B_World@@QAEXN@Z
*/
#ifdef BLD_NATIVE
void B_World::GoToTime(double time)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0043B8E6
* VC++ mangling:          ?AddScheduledFunc@B_World@@QAEXNPAUPyObject@@0PBD@Z
*/
#ifdef BLD_NATIVE
void B_World::AddScheduledFunc(
    double time, PyObject *func, PyObject *args, const char *name)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0043C5FD
* VC++ mangling:          ?Update@B_World@@QAEXPAVlocation_t@@PAXNH@Z
*/
#ifdef BLD_NATIVE
void B_World::Update(
    location_t *location, void *unknown, double time, int updateRaster)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043C8B2
* VC++ mangling:          ?SetSun@B_World@@QAEXHABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

void B_World::SetSun(int exists, const B_Vector &position)
{
}

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0043D434
* VC++ mangling:          ?GetEnemiesVisibleFrom@B_World@@QAEXABVB_Vector@@N0NPAV?$B_PtrArray@VB_Entity@@@@@Z
*/
#ifdef BLD_NATIVE
void B_World::GetEnemiesVisibleFrom(
    const B_Vector &position, double radius,
    const B_Vector &direction, double angle, B_PtrArray<B_Entity> *enemies)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0043DBBE
* VC++ mangling:          ?FindSectorIndex@B_World@@QAEHABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

int B_World::FindSectorIndex(const B_Vector &point)
{
    return -1;
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043DC20
* VC++ mangling:          ?IntersectSegment@B_World@@QAEHABVB_Vector@@00HHPAX@Z
*/
#ifdef BLD_NATIVE
int B_World::IntersectSegment(
    const B_Vector &startPoint, const B_Vector &endPoint,
    const B_Vector &intersection, int flags, int, void *)
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0043E8E8
* VC++ mangling:          ?GenerateEntityName@B_World@@QAEPBDPBD@Z
*/
#ifdef BLD_NATIVE
const char *B_World::GenerateEntityName(const char *prefix)
{
    return NULL;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0043EF43
* VC++ mangling:          ?SetTriggerSectorFunc@B_World@@QAEHPBD0PAUPyObject@@@Z
*/
#ifdef BLD_NATIVE
int B_World::SetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type,
    PyObject *func
)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043F172
* VC++ mangling:          ?GetTriggerSectorFloorHeight@B_World@@QAEHPBD@Z
*/
#ifdef BLD_NATIVE
int B_World::GetTriggerSectorFloorHeight(const char *trigger_sector_name)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043F209
* VC++ mangling:          ?GetTriggerSectorRoofHeight@B_World@@QAEHPBD@Z
*/
#ifdef BLD_NATIVE
int B_World::GetTriggerSectorRoofHeight(const char *trigger_sector_name)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043F2A0
* VC++ mangling:          ?GetTriggerSectorGroup@B_World@@QAEPBDPBD@Z
*/
#ifdef BLD_NATIVE
const char *B_World::GetTriggerSectorGroup(const char *trigger_sector_name)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043F332
* VC++ mangling:          ?GetTriggerSectorPoints@B_World@@QAEPANPBD@Z
*/
#ifdef BLD_NATIVE
double *B_World::GetTriggerSectorPoints(const char *trigger_sector_name)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043F467
* VC++ mangling:          ?GetTriggerSectorFunc@B_World@@QAEPAUPyObject@@PBD0@Z
*/
#ifdef BLD_NATIVE
PyObject *B_World::GetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type
)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043F56D
* VC++ mangling:          ?SetTriggerSectorData@B_World@@QAEHPBDPAUPyObject@@@Z
*/
#ifdef BLD_NATIVE
int B_World::SetTriggerSectorData(
    const char *trigger_sector_name, PyObject *data
)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043F65D
* VC++ mangling:          ?GetTriggerSectorData@B_World@@QAEPAUPyObject@@PBD@Z
*/
#ifdef BLD_NATIVE
PyObject *B_World::GetTriggerSectorData(const char *trigger_sector_name)
{
    return NULL;
}
#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x000043F98A
* VC++ mangling:          ?LoadEntitiesData@B_World@@QAEHPBD@Z
*/

#ifdef BLD_NATIVE

int B_World::LoadEntitiesData(const char *filename)
{
    return 0;
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043FD82
* VC++ mangling:          ?SaveEntitiesData@B_World@@QAEHPBD@Z
*/

#ifdef BLD_NATIVE

int B_World::SaveEntitiesData(const char *filename)
{
    return 0;
}

#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0044008F
* VC++ mangling:          ?AddPoint@B_TriggerSector@@QAEXABVB_Vector@@H@Z
*/
#ifdef BLD_NATIVE
void B_TriggerSector::AddPoint(const B_Vector& point, int numPoints)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00440A19
* VC++ mangling:          ?GetTriggerSectorName@B_World@@QAEPBDH@Z
*/
#ifdef BLD_NATIVE
const char *B_World::GetTriggerSectorName(int index)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00440A5D
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@PAVB_World@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_World *world)
{
        unsigned int num_lights;
        unsigned int i;

        world->unknown187C = 0;
        world->unknown1880 = 0;
        B_PtrArray<atmosphere_t> *atms = &world->atmospheres;
        if (atms->num_alloc != 0)
        {
                for (i = 0; i < atms->size; i++)
                {
                        atmosphere_t * atm = atms->elements[i];
                        delete atm;
                }
                delete(atms->elements);
                atms->elements = NULL;
                atms->size = 0;
                atms->num_alloc = 0;
        }
        file >> atms->size;
        atms->num_alloc = ((atms->increment + atms->size - 1) / atms->increment) * atms->increment;
        if (atms->num_alloc != 0)
        {
                atms->elements = new atmosphere_t * [atms->num_alloc];
                for(i = 0; i < atms->size; i++)
                {
                        atms->elements[i] = new atmosphere_t();
                        file >> atms->elements[i];
                }
        }

        if (B_3D_raster_device)
                B_3D_raster_device->unknown084();

        for(i = 0; i < atms->size; i++)
        {
                atmosphere_t * atm = (atmosphere_t *)atms->elements[i];
                B_3D_raster_device->add_atmosphere(atm->Id(), atm->color, atm->intensity);
        }

        file >> gbl_world_points;
        file >> world->map;

        B_PtrArray<light_t> *lights = &world->lights;
        if (lights->num_alloc != 0)
        {
                for (i = 0; i < lights->size; i++)
                {
                        light_t * light = (light_t *)lights->elements[i];
                        delete light;
                }
                delete(lights->elements);
                lights->elements = NULL;
                lights->size = 0;
                lights->num_alloc = 0;
        }

        file >> num_lights;

        for(i = 0; i < num_lights; i++)
        {
                light_t *light = read_light(&file);
                B_PtrArray<light_t> *lights = &world->lights;
                if (lights->num_alloc <= lights->size)
                {
                        lights->num_alloc += lights->increment;
                        if (lights->size != 0)
                        {
                                light_t **elements = new light_t *[lights->num_alloc];
                                for(unsigned int j = 0; j < lights->size; j++)
                                {
                                        elements[j] = lights->elements[j]; 
                                }
                                delete lights->elements;
                                lights->elements = elements;
                        }
                        else
                        {
                                lights->elements = new light_t *[lights->num_alloc];
                        }
                }
                lights->elements[i] = light;
                lights->size++;
        }

        for(i = 0; i < num_lights; i++)
        {
                light_t *light = world->lights.elements[i];
                light->unknown008();
        }

        file >> world->initial_point_position >> world->initial_point_orientation;

        for(i = 0; i < world->map.size; i++)
        {
                B_Sector *sector = world->map.elements[i];
                file >> sector->groupId;
        }

        world->octTree.Build(world->map, 5000.0);

        return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
