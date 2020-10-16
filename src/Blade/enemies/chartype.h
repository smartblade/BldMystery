#ifndef CHAR_TYPE_H

#define CHAR_TYPE_H

#include <BBLibc.h>


class anim_t;
class B_BipedData;

class B_CharType : public B_NamedObj
{
public:
    double GetMaxGrabDist();
    double GetMedGrabDist();
    double GetMinGrabDist();

    char unknown_fields[0x199C];
    double maxStairDist;
    char unknown_fields19B0[0xB4];
    B_BipedData *biped;
};

#ifdef __cplusplus
extern "C" {
#endif

extern anim_t *LoadFromHDAnim(const char *anm_name);

#ifdef __cplusplus
}
#endif

#endif /* CHAR_TYPE_H */
