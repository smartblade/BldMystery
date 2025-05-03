#ifndef B_RDataTriangle_H
#define B_RDataTriangle_H


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class B_RItem
{
};


class LIB_EXP B_RDataTriangle : public B_RItem
{
public:
    B_RDataTriangle();

    B_RDataTriangle& operator=(const B_RDataTriangle&);

private:

};

#endif  // B_RDataTriangle_H
