#include <Control/Events.h>

#include <Entities/Entity.h>
#include "bld_misc_funcs.h"

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0048A900
* VC++ mangling:          ??0B_EventFunc@@QAE@XZ
*/

B_EventFunc::B_EventFunc()
 : pyFunc(NULL), func(NULL), name(NULL)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0048A92B
* VC++ mangling:          ??0B_EventFuncs@@QAE@ABVB_Name@@@Z
*/
#ifdef BLD_NATIVE
B_EventFuncs::B_EventFuncs(const B_Name &name)
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
* Entry point:            0x0048AB7F
* VC++ mangling:          ?AddPyFunc@B_EventFuncs@@QAEXIPAUPyObject@@PBD@Z
*/
#ifdef BLD_NATIVE
void B_EventFuncs::AddPyFunc(
    unsigned int eventIndex, PyObject *func, const char *name)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0048AEB2
* VC++ mangling:          ?AddFunc@B_EventFuncs@@QAEXIP6AHPAVB_Entity@@I@ZPBD@Z
*/

void B_EventFuncs::AddFunc(
    unsigned int eventIndex, EventFn func, const char *name)
{
    unsigned int i = eventIndex / NUM_EVENT_FUNCS;
    unsigned int j = eventIndex % NUM_EVENT_FUNCS;
    if (this->eventFuncs.size <= i)
    {
        unsigned int funcsIndex = this->eventFuncs.size;
        this->eventFuncs.Resize(i + 1, true);
        for (; funcsIndex < this->eventFuncs.size; funcsIndex++)
        {
            this->eventFuncs.elements[funcsIndex] = NULL;
        }
    }
    if (this->eventFuncs.elements[i] == NULL)
    {
        B_EventFunc *eventFuncs =
            this->eventFuncs.elements[i] = new B_EventFunc[NUM_EVENT_FUNCS];
        for (unsigned int index = 0; index < NUM_EVENT_FUNCS; index++)
        {
            eventFuncs[index].pyFunc = NULL;
            eventFuncs[index].func = NULL;
            eventFuncs[index].name = NULL;
        }
    }
    this->eventFuncs.elements[i][j].func = func;
    this->eventFuncs.elements[i][j].name = name;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0048B30B
* VC++ mangling:          ?CallFunc@B_EventFuncs@@QAEHPAVB_Entity@@I@Z
*/

int B_EventFuncs::CallFunc(B_Entity *entity, unsigned int eventIndex)
{
    unsigned int i = eventIndex / NUM_EVENT_FUNCS;
    unsigned int j = eventIndex % NUM_EVENT_FUNCS;
    if (this->eventFuncs.size > i && this->eventFuncs.elements[i] != NULL)
    {
        if (this->eventFuncs.elements[i][j].pyFunc != NULL)
        {
            PyObject *args = PyTuple_New(2);
            PyObject *entityName = PyString_FromString(entity->name.String());
            PyObject *eventName = PyString_FromString(
                gbl_events.GetEventName(eventIndex));
            PyTuple_SET_ITEM(args, 0, entityName);
            PyTuple_SET_ITEM(args, 1, eventName);
            PyObject *result = CallPythonObject(
                this->eventFuncs.elements[i][j].pyFunc, args);
            Py_DECREF(args);
            Py_XDECREF(result);
            return true;
        }
        if (this->eventFuncs.elements[i][j].func != NULL)
            return this->eventFuncs.elements[i][j].func(entity, eventIndex);
        return false;
    }
    return false;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0048B74A
* VC++ mangling:          ?GetEventIndex@B_Events@@QAEHPBD@Z
*/
#ifdef BLD_NATIVE
int B_Events::GetEventIndex(const char *event_name)
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
* Entry point:            0x0048BEED
* VC++ mangling:          ?GetEventName@B_Events@@QAEABVB_Name@@H@Z
*/

const B_Name &B_Events::GetEventName(int eventIndex)
{
    B_Event *event = events.elements[eventIndex];
    return event->name;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
