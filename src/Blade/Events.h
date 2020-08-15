#ifndef EVENTS_H

#define EVENTS_H

#include <BBLibc.h>


class B_Entity;

class B_EventFunc
{
public:
    PyObject *pyFunc;
    int (*func)(B_Entity *entity, unsigned int eventIndex);
    const char *name;
};

#define NUM_EVENT_FUNCS 32

class B_EventFuncs : public B_NamedObj
{
public:
    int CallFunc(B_Entity *entity, unsigned int eventIndex);
private:
    array_t<B_EventFunc *> eventFuncs;
};

class B_Event : public B_NamedObj
{
public:
    int index;
};

class B_Events
{
public:
    int GetEventIndex(const char *event_name);
    const B_Name &GetEventName(int eventIndex);
private:
    B_PtrArray<B_Event> events;
};

#endif /* EVENTS_H */
