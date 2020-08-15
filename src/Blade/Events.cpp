#include "Events.h"

#include "entity.h"
#include "bld_misc_funcs.h"


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
