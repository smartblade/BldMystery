#ifndef ANIM_H

#define ANIM_H

#include "BBLibc.h"

class anim_t : public B_NamedObj
{
public:
    anim_t();
    void AddEvent(const B_Name &event_name, float event_frame);
    void DelEvent(const B_Name &event_name);
    void ClearEvents();
    float GetEventFrame(const B_Name &event_name);
};

B_IDataFile &operator >>(B_IDataFile &file, anim_t *anim);

#endif