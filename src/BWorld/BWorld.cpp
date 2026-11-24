
#include <bld_system.h>
#include <Raster/RasterDevice.h>
#include <BWorld/BWorld.h>
#include <BWorld/BMap.h>
#include <BWorld/light.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x004394B0
* VC++ mangling:          ??0B_SubscriptionList@@QAE@XZ
*/

B_SubscriptionList::B_SubscriptionList()
:
    B_Array<B_Entity>(16, false)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00439518
* VC++ mangling:          ??0B_SubscriptionList@@QAE@ABVB_Name@@@Z
*/

B_SubscriptionList::B_SubscriptionList(const B_Name &name)
:
    B_Array<B_Entity>(16, false),
    B_NamedObj(name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00439586
* VC++ mangling:          ??0B_TimerList@@QAE@ABVB_Name@@N@Z
*/

B_TimerList::B_TimerList(const B_Name &name, double period)
:
    B_SubscriptionList(name)
{
    if (period > 0.0)
    {
        this->period = period;
    }
    else
    {
        this->period = 1.0;
    }
    this->lastTime = 0.0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004395F8
* VC++ mangling:          ?SetPeriod@B_TimerList@@QAEXN@Z
*/

void B_TimerList::SetPeriod(double period)
{
    if (period > 0.0)
    {
        this->period = period;
    }
    else
    {
        this->period = 1.0;
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00439637
* VC++ mangling:          ??0B_FrameList@@QAE@ABVB_Name@@H@Z
*/

B_FrameList::B_FrameList(const B_Name &name, int period)
:
    B_SubscriptionList(name)
{
    if (period >= 0)
    {
        this->period = period;
    }
    else
    {
        this->period = 0;
    }
    this->lastFrame = 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043968B
* VC++ mangling:          ?SetPeriod@B_FrameList@@QAEXH@Z
*/

void B_FrameList::SetPeriod(int period)
{
    if (period >= 0)
    {
        this->period = period;
    }
    else
    {
        this->period = 0;
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x004396B3
* VC++ mangling:          ??0B_ScheduledFunc@@QAE@PBDNPAUPyObject@@1@Z
*/

B_ScheduledFunc::B_ScheduledFunc(
    const char *name,
    double time,
    PyObject *func,
    PyObject *args
)
:
    B_NamedObj(name),
    time(time),
    func(func),
    args(args),
    nativeFunc(nullptr),
    nativeArg(nullptr)
{
    Py_XINCREF(func);
    Py_XINCREF(args);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00439750
* VC++ mangling:          ??0B_ScheduledFunc@@QAE@PBDNP6AHPAX@Z1@Z
*/

B_ScheduledFunc::B_ScheduledFunc(
    const char *name,
    double time,
    ScheduledNativeFunc nativeFunc,
    void *nativeArg
)
:
    B_NamedObj(name),
    time(time),
    func(nullptr),
    args(nullptr),
    nativeFunc(nativeFunc),
    nativeArg(nativeArg)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004397C3
* VC++ mangling:          ??1B_ScheduledFunc@@UAE@XZ
*/

B_ScheduledFunc::~B_ScheduledFunc()
{
    if (this->func != nullptr)
    {
        Py_DECREF(this->func);
        Py_DECREF(this->args);
    }
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004398A5
* VC++ mangling:          ??0B_World@@QAE@N@Z
*/

B_World::B_World(double lastTime)
:
    timeStep(0.015625),
    currentTick(0),
    lastTime(lastTime),
    physicsMgr(0.0166666666),
    unknown1938(0),
    unknown1984(1),
    unknown1988(0),
    unknown198C(0)
{
    this->unknown_00439F5D();
    this->unknown1858 = 2;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00439B9A
* VC++ mangling:          ??1B_World@@QAE@XZ
*/

B_World::~B_World()
{
    this->ClearWorld(0);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00439F5D
* VC++ mangling:          ?unknown_00439F5D@B_World@@QAEXXZ
*/

#ifndef BLD_NATIVE

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
* Entry point:            0x0043A184
* VC++ mangling:          ?ClearWorld@B_World@@QAEXH@Z
*/
#ifndef BLD_NATIVE
void B_World::ClearWorld(int mode)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043A6A4
* VC++ mangling:          ?GetTime@B_World@@QAENXZ
*/
#ifndef BLD_NATIVE
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
#ifndef BLD_NATIVE
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
#ifndef BLD_NATIVE
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
#ifndef BLD_NATIVE
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
* VC++ mangling:          ?Update@B_World@@QAEXPAVB_ViewPose@@PAXNH@Z
*/
#ifndef BLD_NATIVE
void B_World::Update(
    B_ViewPose *viewPose, void *cameraView, double time, int updateRaster)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043C8B2
* VC++ mangling:          ?SetSun@B_World@@QAEXHABVB_Vector@@@Z
*/

#ifndef BLD_NATIVE

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
* VC++ mangling:          ?GetEnemiesVisibleFrom@B_World@@QAEXABVB_Vector@@N0NPAV?$B_Array@VB_Entity@@@@@Z
*/
#ifndef BLD_NATIVE
void B_World::GetEnemiesVisibleFrom(
    const B_Vector &position, double radius,
    const B_Vector &direction, double angle, B_Array<B_Entity> *enemies)
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

#ifndef BLD_NATIVE

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
#ifndef BLD_NATIVE
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
#ifndef BLD_NATIVE
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

int B_World::SetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type,
    PyObject *func
)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr)
    {
        if (!strcmp(func_type, "OnEnter"))
        {
            if (func != nullptr)
            {
                Py_XDECREF(triggerSector->onEnter);
                Py_XINCREF(func);
                triggerSector->onEnter = func;
            }
            else
            {
                Py_XDECREF(triggerSector->onEnter);
                triggerSector->onEnter = nullptr;
            }
            return 1;
        }
        if (!strcmp(func_type, "OnLeave"))
        {
            if (func != nullptr)
            {
                Py_XDECREF(triggerSector->onLeave);
                Py_XINCREF(func);
                triggerSector->onLeave = func;
            }
            else
            {
                Py_XDECREF(triggerSector->onLeave);
                triggerSector->onLeave = nullptr;
            }
            return 1;
        }
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F172
* VC++ mangling:          ?GetTriggerSectorFloorHeight@B_World@@QAEHPBD@Z
*/

int B_World::GetTriggerSectorFloorHeight(const char *trigger_sector_name)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr)
    {
        float floorHeight = triggerSector->floorHeight;
        return static_cast<int>(floorHeight);
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F209
* VC++ mangling:          ?GetTriggerSectorRoofHeight@B_World@@QAEHPBD@Z
*/

int B_World::GetTriggerSectorRoofHeight(const char *trigger_sector_name)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr)
    {
        float roofHeight = triggerSector->roofHeight;
        return static_cast<int>(roofHeight);
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F2A0
* VC++ mangling:          ?GetTriggerSectorGroup@B_World@@QAEPBDPBD@Z
*/

const char *B_World::GetTriggerSectorGroup(const char *trigger_sector_name)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr)
    {
        return triggerSector->groupName.String();
    }
    return nullptr;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F332
* VC++ mangling:          ?GetTriggerSectorPoints@B_World@@QAEPANPBD@Z
*/

double *B_World::GetTriggerSectorPoints(const char *trigger_sector_name)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr)
    {
        array_t<B_Vector> &points = triggerSector->points;
        int numPoints = points.size;
        double *coords = new double[2 * numPoints + 1];
        double *coord = coords + 1;
        coords[0] = numPoints;
        for (int i = 0; i < numPoints; i++)
        {
            *coord = points.elements[i].x;
            coord++;
            *coord = points.elements[i].z;
            coord++;
        }
        return coords;
    }
    return nullptr;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F467
* VC++ mangling:          ?GetTriggerSectorFunc@B_World@@QAEPAUPyObject@@PBD0@Z
*/

PyObject *B_World::GetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type
)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr)
    {
        if (!strcmp(func_type, "OnEnter"))
        {
            Py_XINCREF(triggerSector->onEnter);
            PyObject *onEnter = triggerSector->onEnter;
            return onEnter;
        }
        if (!strcmp(func_type, "OnLeave"))
        {
            Py_XINCREF(triggerSector->onLeave);
            PyObject *onLeave = triggerSector->onLeave;
            return onLeave;
        }
    }
    return nullptr;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F56D
* VC++ mangling:          ?SetTriggerSectorData@B_World@@QAEHPBDPAUPyObject@@@Z
*/

int B_World::SetTriggerSectorData(
    const char *trigger_sector_name, PyObject *data
)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr && data != nullptr)
    {
        Py_XDECREF(triggerSector->data);
        Py_XINCREF(data);
        triggerSector->data = data;
        return 1;
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F65D
* VC++ mangling:          ?GetTriggerSectorData@B_World@@QAEPAUPyObject@@PBD@Z
*/

PyObject *B_World::GetTriggerSectorData(const char *trigger_sector_name)
{
    B_TriggerSector *triggerSector =
        this->triggerSectors.Find(trigger_sector_name);
    if (triggerSector != nullptr)
    {
        Py_XINCREF(triggerSector->data);
        PyObject *data = triggerSector->data;
        return data;
    }
    return nullptr;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0043F98A
* VC++ mangling:          ?LoadEntitiesData@B_World@@QAEHPBD@Z
*/

#ifndef BLD_NATIVE

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

#ifndef BLD_NATIVE

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
#ifndef BLD_NATIVE
void B_TriggerSector::AddPoint(const B_Vector &point, int numPoints)
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

const char *B_World::GetTriggerSectorName(int index)
{
    if (
        index < 0 ||
        static_cast<unsigned int>(index) >= this->triggerSectors.size
    )
    {
        return nullptr;
    }
    B_TriggerSector *triggerSector = this->triggerSectors.elements[index];
    return triggerSector->Id().String();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00440A5D
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@PAVB_World@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_World *world)
{
        unsigned int num_lights;
        unsigned int i;

        world->lastTime = 0;
        B_Array<atmosphere_t> *atms = &world->atmospheres;
        if (atms->num_alloc != 0)
        {
                for (i = 0; i < atms->size; i++)
                {
                        atmosphere_t *atm = atms->elements[i];
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
                atms->elements = new atmosphere_t *[atms->num_alloc];
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
                atmosphere_t *atm = (atmosphere_t *)atms->elements[i];
                B_3D_raster_device->AddAtmosphere(atm->Id(), atm->color, atm->intensity);
        }

        file >> gbl_world_points;
        file >> world->map;

        B_Array<light_t> *lights = &world->lights;
        if (lights->num_alloc != 0)
        {
                for (i = 0; i < lights->size; i++)
                {
                        light_t *light = (light_t *)lights->elements[i];
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
                B_Array<light_t> *lights = &world->lights;
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
