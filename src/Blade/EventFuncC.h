#ifndef EVENT_FUNC_C_H

#define EVENT_FUNC_C_H

#include <BBLibc.h>


class B_Entity;

typedef int (*EventFn)(B_Entity *entity, unsigned int eventIndex);

struct B_EventFuncC : public B_NamedObj
{
    EventFn func;
};

#endif /* EVENT_FUNC_C_H */
