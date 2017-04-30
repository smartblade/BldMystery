#ifndef ANIM_H

#define ANIM_H

#include "BBLibc.h"

class anim_t : public B_NamedObj
{
public:
        anim_t() {assert("anim_t::anim_t" == NULL);} // TODO implement
};

B_IDataFile &operator >>(B_IDataFile &file, anim_t *anim) {assert("anim_t::<<" == NULL); return file;} // TODO implement

#endif