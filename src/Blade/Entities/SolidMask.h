#ifndef SOLID_MASK_H

#define SOLID_MASK_H

#include <BBLibc.h>


class B_SolidMask : public B_NamedObj
{
public:
    B_SolidMask(const B_Name &kind, int mask)
     : B_NamedObj(kind), mask(mask)
    {
    }

    int mask;
};

#endif /* SOLID_MASK_H */
