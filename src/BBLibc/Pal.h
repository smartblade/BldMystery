
#ifndef B_PAL_H

#define B_PAL_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_Pal
{
public:
    unsigned char GetRed(unsigned int val) const;
    unsigned char GetGreen(unsigned int val) const;
    unsigned char GetBlue(unsigned int val) const;
};

#endif /* B_PAL_H */
