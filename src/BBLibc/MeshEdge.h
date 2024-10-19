
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
    B_MeshEdge& operator=(const B_MeshEdge&);
    unsigned int operator==(const B_MeshEdge&) const;

    unsigned int field;
private:

};

#endif  // B_MESHEDGE_H
