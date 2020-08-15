#ifndef EVENTS_H

#define EVENTS_H

#include <BBLibc.h>

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
