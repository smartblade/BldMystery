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
};

#endif /* EVENTS_H */
