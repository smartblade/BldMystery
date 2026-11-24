#include <BWorld/BMap.h>

#include <Raster/RasterDevice.h>
#include <AnalyticGeometry/Polygon.h>
#include <Entities/Entity.h>
#include <BBLibc/BBLibc.h>
#include <bld_python.h>
#include "bld_misc_funcs.h"


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0042E011
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_SectorLights@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_SectorLights &lights)
{
    file >> lights.ambient >> lights.flat;
    return file;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0042E06B
* VC++ mangling:          ??0B_Sector@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_Sector::B_Sector()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0042E26F
* VC++ mangling:          ??1B_Sector@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_Sector::~B_Sector()
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
* Entry point:            0x0042E464
* VC++ mangling:          ?CalculateBoundingBox@B_Sector@@QAEXXZ
*/
#ifndef BLD_NATIVE
void B_Sector::CalculateBoundingBox()
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
* Entry point:            0x0042FFDC
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Sector@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Sector &sector)
{
    unsigned int numSurfaces;
    B_Name atmosphereName;

    file >> atmosphereName;
    sector.atmosphere = B_3D_raster_device->GetAtmosphere(atmosphereName);
    file >> sector.lights;
    file >> numSurfaces;
    for (unsigned int i = 0; i < numSurfaces; i++)
    {
        B_Surface *surface = ReadSurface(file);
        if (surface->GetPolygon()->numVertices < 3)
        {
            delete surface;
        }
        else
        {
            sector.Append(surface);
        }
    }
    sector.CalculateBoundingBox();
    return file;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00430281
* VC++ mangling:          ??0B_Map@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_Map::B_Map()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00430323
* VC++ mangling:          ??1B_Map@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_Map::~B_Map()
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
* Entry point:            0x00432379
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Map@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Map &map)
{
    return (file >> static_cast<B_Array<B_Sector> &>(map));
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00432EEB
* VC++ mangling:          ??0B_SectorFuncs@@QAE@H@Z
*/

B_SectorFuncs::B_SectorFuncs(int sectorIndex)
:
    pyOnEnter(nullptr),
    onEnter(nullptr),
    pyOnLeave(nullptr),
    onLeave(nullptr),
    pyOnHit(nullptr),
    onHit(nullptr),
    pyOnWalkOn(nullptr),
    pyOnWalkOut(nullptr),
    sectorIndex(sectorIndex)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00432F53
* VC++ mangling:          ??1B_SectorFuncs@@QAE@XZ
*/

B_SectorFuncs::~B_SectorFuncs()
{
    this->ClearOnEnterFunc();
    this->ClearOnLeaveFunc();
    this->ClearOnHitFunc();
    this->ClearOnWalkOnFunc();
    this->ClearOnWalkOutFunc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00432F86
* VC++ mangling:          ?SetOnEnterFunc@B_SectorFuncs@@QAEHPAUPyObject@@@Z
*/

int B_SectorFuncs::SetOnEnterFunc(PyObject *_OnEnterFunc)
{
    assert(_OnEnterFunc);
    Py_XDECREF(this->pyOnEnter);
    Py_INCREF(_OnEnterFunc);
    this->pyOnEnter = _OnEnterFunc;
    this->onEnter = nullptr;
    return 1;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00433033
* VC++ mangling:          ?GetOnEnterFunc@B_SectorFuncs@@QAEPAUPyObject@@XZ
*/

PyObject *B_SectorFuncs::GetOnEnterFunc()
{
    return this->pyOnEnter;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433043
* VC++ mangling:          ?SetOnWalkOnFunc@B_SectorFuncs@@QAEHPAUPyObject@@@Z
*/

int B_SectorFuncs::SetOnWalkOnFunc(PyObject *_OnWalkOnFunc)
{
    assert(_OnWalkOnFunc);
    Py_XDECREF(this->pyOnWalkOn);
    Py_INCREF(_OnWalkOnFunc);
    this->pyOnWalkOn = _OnWalkOnFunc;
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004330CA
* VC++ mangling:          ?GetOnWalkOnFunc@B_SectorFuncs@@QAEPAUPyObject@@XZ
*/

PyObject *B_SectorFuncs::GetOnWalkOnFunc()
{
    return this->pyOnWalkOn;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004330FE
* VC++ mangling:          ?SetOnWalkOutFunc@B_SectorFuncs@@QAEHPAUPyObject@@@Z
*/

int B_SectorFuncs::SetOnWalkOutFunc(PyObject *_OnWalkOutFunc)
{
    assert(_OnWalkOutFunc);
    Py_XDECREF(this->pyOnWalkOut);
    Py_INCREF(_OnWalkOutFunc);
    this->pyOnWalkOut = _OnWalkOutFunc;
    return 1;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004331A8
* VC++ mangling:          ?GetOnWalkOutFunc@B_SectorFuncs@@QAEPAUPyObject@@XZ
*/

PyObject *B_SectorFuncs::GetOnWalkOutFunc()
{
    return this->pyOnWalkOut;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004331B9
* VC++ mangling:          ?SetOnEnterFunc@B_SectorFuncs@@QAEHP6AHHABVB_Entity@@@Z@Z
*/

int B_SectorFuncs::SetOnEnterFunc(SectorEntityFunc _OnEnterFunc)
{
    assert(_OnEnterFunc);
    this->onEnter = _OnEnterFunc;
    Py_XDECREF(this->pyOnEnter);
    this->pyOnEnter = nullptr;
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433236
* VC++ mangling:          ?ClearOnEnterFunc@B_SectorFuncs@@QAEHXZ
*/

int B_SectorFuncs::ClearOnEnterFunc()
{
    if (this->onEnter != nullptr)
    {
        this->onEnter = nullptr;
    }
    else if (this->pyOnEnter != nullptr)
    {
        Py_DECREF(this->pyOnEnter);
        this->pyOnEnter = nullptr;
    }
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043329D
* VC++ mangling:          ?ClearOnWalkOnFunc@B_SectorFuncs@@QAEHXZ
*/

int B_SectorFuncs::ClearOnWalkOnFunc()
{
    if (this->pyOnWalkOn != nullptr)
    {
        Py_DECREF(this->pyOnWalkOn);
        this->pyOnWalkOn = nullptr;
    }
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004332F6
* VC++ mangling:          ?ClearOnWalkOutFunc@B_SectorFuncs@@QAEHXZ
*/

int B_SectorFuncs::ClearOnWalkOutFunc()
{
    if (this->pyOnWalkOut != nullptr)
    {
        Py_DECREF(this->pyOnWalkOut);
        this->pyOnWalkOut = nullptr;
    }
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043334F
* VC++ mangling:          ?SetOnLeaveFunc@B_SectorFuncs@@QAEHPAUPyObject@@@Z
*/

int B_SectorFuncs::SetOnLeaveFunc(PyObject *_OnLeaveFunc)
{
    assert(_OnLeaveFunc);
    Py_XDECREF(this->pyOnLeave);
    Py_INCREF(_OnLeaveFunc);
    this->pyOnLeave = _OnLeaveFunc;
    this->onLeave = nullptr;
    return 1;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00433403
* VC++ mangling:          ?GetOnLeaveFunc@B_SectorFuncs@@QAEPAUPyObject@@XZ
*/

PyObject *B_SectorFuncs::GetOnLeaveFunc()
{
    return this->pyOnLeave;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433414
* VC++ mangling:          ?SetOnLeaveFunc@B_SectorFuncs@@QAEHP6AHHABVB_Entity@@@Z@Z
*/

int B_SectorFuncs::SetOnLeaveFunc(SectorEntityFunc _OnLeaveFunc)
{
    assert(_OnLeaveFunc);
    this->onLeave = _OnLeaveFunc;
    Py_XDECREF(this->pyOnLeave);
    this->pyOnLeave = nullptr;
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433498
* VC++ mangling:          ?ClearOnLeaveFunc@B_SectorFuncs@@QAEHXZ
*/

int B_SectorFuncs::ClearOnLeaveFunc()
{
    if (this->onLeave != nullptr)
    {
        this->onLeave = nullptr;
    }
    else if (this->pyOnLeave != nullptr)
    {
        Py_DECREF(this->pyOnLeave);
        this->pyOnLeave = nullptr;
    }
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433506
* VC++ mangling:          ?SetOnHitFunc@B_SectorFuncs@@QAEHPAUPyObject@@@Z
*/

int B_SectorFuncs::SetOnHitFunc(PyObject *_OnHitFunc)
{
    assert(_OnHitFunc);
    Py_XDECREF(this->pyOnHit);
    Py_INCREF(_OnHitFunc);
    this->pyOnHit = _OnHitFunc;
    this->onHit = nullptr;
    return 1;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004335BA
* VC++ mangling:          ?GetOnHitFunc@B_SectorFuncs@@QAEPAUPyObject@@XZ
*/

PyObject *B_SectorFuncs::GetOnHitFunc()
{
    return this->pyOnHit;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004335CB
* VC++ mangling:          ?SetOnHitFunc@B_SectorFuncs@@QAEHP6AHHPAVB_Entity@@PBVB_Vector@@@Z@Z
*/

int B_SectorFuncs::SetOnHitFunc(SectorHitFunc _OnHitFunc)
{
    assert(_OnHitFunc);
    this->onHit = _OnHitFunc;
    Py_XDECREF(this->pyOnHit);
    this->pyOnHit = nullptr;
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043364F
* VC++ mangling:          ?ClearOnHitFunc@B_SectorFuncs@@QAEHXZ
*/

int B_SectorFuncs::ClearOnHitFunc()
{
    if (this->onHit != nullptr)
    {
        this->onHit = nullptr;
    }
    else if (this->pyOnHit != nullptr)
    {
        Py_DECREF(this->pyOnHit);
        this->pyOnHit = nullptr;
    }
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004336BD
* VC++ mangling:          ?CallOnHit@B_SectorFuncs@@QAEHPAVB_Entity@@PBVB_Vector@@11PBD@Z
*/

int B_SectorFuncs::CallOnHit(
    B_Entity *source,
    const B_Vector *point,
    const B_Vector *direction,
    const B_Vector *normal,
    const char *materialName
)
{
    if (this->onHit != nullptr)
    {
        return this->onHit(this->sectorIndex, source, point);
    }
    if (this->pyOnHit != nullptr)
    {
        PyObject *args = PyTuple_New(12);
        PyObject *indexObj = PyInt_FromLong(this->sectorIndex);
        PyObject *sourceName = PyString_FromString(source->name.String());
        PyObject *pointX = PyFloat_FromDouble(point->x);
        PyObject *pointY = PyFloat_FromDouble(point->y);
        PyObject *pointZ = PyFloat_FromDouble(point->z);
        PyObject *directionX = PyFloat_FromDouble(direction->x);
        PyObject *directionY = PyFloat_FromDouble(direction->y);
        PyObject *directionZ = PyFloat_FromDouble(direction->z);
        PyObject *normalX = PyFloat_FromDouble(normal->x);
        PyObject *normalY = PyFloat_FromDouble(normal->y);
        PyObject *normalZ = PyFloat_FromDouble(normal->z);
        PyObject *material;
        if (materialName != nullptr)
        {
            material = PyString_FromString(materialName);
        }
        else
        {
            material = PyString_FromString("");
        }
        PyTuple_SET_ITEM(args, 0, indexObj);
        PyTuple_SET_ITEM(args, 1, sourceName);
        PyTuple_SET_ITEM(args, 2, pointX);
        PyTuple_SET_ITEM(args, 3, pointY);
        PyTuple_SET_ITEM(args, 4, pointZ);
        PyTuple_SET_ITEM(args, 5, directionX);
        PyTuple_SET_ITEM(args, 6, directionY);
        PyTuple_SET_ITEM(args, 7, directionZ);
        PyTuple_SET_ITEM(args, 8, normalX);
        PyTuple_SET_ITEM(args, 9, normalY);
        PyTuple_SET_ITEM(args, 10, normalZ);
        PyTuple_SET_ITEM(args, 11, material);
        PyObject *result = CallPythonObject(this->pyOnHit, args);
        Py_DECREF(args);
        if (result != nullptr)
        {
            Py_DECREF(result);
        }
        return 1;
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043390E
* VC++ mangling:          ?CallOnEnter@B_SectorFuncs@@QAEHABVB_Entity@@@Z
*/

int B_SectorFuncs::CallOnEnter(const B_Entity &entity)
{
    if (this->onEnter != nullptr)
    {
        return this->onEnter(this->sectorIndex, entity);
    }
    if (this->pyOnEnter != nullptr)
    {
        PyObject *args = PyTuple_New(2);
        PyObject *indexObj = PyInt_FromLong(this->sectorIndex);
        PyObject *entityName = PyString_FromString(entity.name.String());
        PyTuple_SET_ITEM(args, 0, indexObj);
        PyTuple_SET_ITEM(args, 1, entityName);
        PyObject *result = CallPythonObject(this->pyOnEnter, args);
        Py_DECREF(args);
        if (result != nullptr)
        {
            Py_DECREF(result);
        }
        return 1;
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433A0A
* VC++ mangling:          ?CallOnWalkOn@B_SectorFuncs@@QAEHABVB_Entity@@@Z
*/

int B_SectorFuncs::CallOnWalkOn(const B_Entity &entity)
{
    if (this->pyOnWalkOn != nullptr)
    {
        PyObject *args = PyTuple_New(2);
        PyObject *indexObj = PyInt_FromLong(this->sectorIndex);
        PyObject *entityName = PyString_FromString(entity.name.String());
        PyTuple_SET_ITEM(args, 0, indexObj);
        PyTuple_SET_ITEM(args, 1, entityName);
        PyObject *result = CallPythonObject(this->pyOnWalkOn, args);
        Py_DECREF(args);
        if (result != nullptr)
        {
            Py_DECREF(result);
        }
        return 1;
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433AE6
* VC++ mangling:          ?CallOnWalkOut@B_SectorFuncs@@QAEHABVB_Entity@@@Z
*/

int B_SectorFuncs::CallOnWalkOut(const B_Entity &entity)
{
    if (this->pyOnWalkOut != nullptr)
    {
        PyObject *args = PyTuple_New(2);
        PyObject *indexObj = PyInt_FromLong(this->sectorIndex);
        PyObject *entityName = PyString_FromString(entity.name.String());
        PyTuple_SET_ITEM(args, 0, indexObj);
        PyTuple_SET_ITEM(args, 1, entityName);
        PyObject *result = CallPythonObject(this->pyOnWalkOut, args);
        Py_DECREF(args);
        if (result != nullptr)
        {
            Py_DECREF(result);
        }
        return 1;
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433BC2
* VC++ mangling:          ?CallOnLeave@B_SectorFuncs@@QAEHABVB_Entity@@@Z
*/

int B_SectorFuncs::CallOnLeave(const B_Entity &entity)
{
    if (this->onLeave != nullptr)
    {
        return this->onLeave(this->sectorIndex, entity);
    }
    if (this->pyOnLeave != nullptr)
    {
        PyObject *args = PyTuple_New(2);
        PyObject *indexObj = PyInt_FromLong(this->sectorIndex);
        PyObject *entityName = PyString_FromString(entity.name.String());
        PyTuple_SET_ITEM(args, 0, indexObj);
        PyTuple_SET_ITEM(args, 1, entityName);
        PyObject *result = CallPythonObject(this->pyOnLeave, args);
        Py_DECREF(args);
        if (result != nullptr)
        {
            Py_DECREF(result);
        }
        return 1;
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00433CC0
* VC++ mangling:          ?IsEmpty@B_SectorFuncs@@QAEHXZ
*/

int B_SectorFuncs::IsEmpty()
{
    return this->pyOnEnter == nullptr &&
        this->pyOnLeave == nullptr &&
        this->pyOnHit == nullptr &&
        this->pyOnWalkOn == nullptr &&
        this->pyOnWalkOut == nullptr;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
