
#ifndef B_MESHEDGE_H
#define B_MESHEDGE_H


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class LIB_EXP B_MeshEdge
{
public:
    B_MeshEdge();
    B_MeshEdge(unsigned int, unsigned int, unsigned int);

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10007F70
    * VC++ mangling:          ??4B_MeshEdge@@QAEAAV0@ABV0@@Z
    */
#ifndef BLD_NATIVE
    B_MeshEdge &operator=(const B_MeshEdge &)
    {
        return *this;
    }
#else
    B_MeshEdge &operator=(const B_MeshEdge &);
#endif
    unsigned int operator==(const B_MeshEdge &) const;

    unsigned int node;
    unsigned int vertexA;
    unsigned int vertexB;
    double invLength;
    unsigned int sharp;
};

#endif  // B_MESHEDGE_H
