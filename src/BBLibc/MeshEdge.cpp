#include "MeshEdge.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10007F70
* VC++ mangling:          ??4B_MeshEdge@@QAEAAV0@ABV0@@Z
*/

#ifndef BLD_NATIVE
B_MeshEdge &B_MeshEdge::operator=(const B_MeshEdge &other)
{
    return *this;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100321F0
* VC++ mangling:          ??0B_MeshEdge@@QAE@XZ
*/

B_MeshEdge::B_MeshEdge()
{
    this->vertexA = 0;
    this->vertexB = 0;
    this->sharp = 1;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003221C
* VC++ mangling:          ??0B_MeshEdge@@QAE@III@Z
*/

B_MeshEdge::B_MeshEdge(unsigned int a, unsigned int b, unsigned int node)
{
    this->node = node;
    this->sharp = 1;
    this->vertexA = a < b ? a : b;
    this->vertexB = a > b ? a : b;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003227E
* VC++ mangling:          ??8B_MeshEdge@@QBEIABV0@@Z
*/

unsigned int B_MeshEdge::operator==(const B_MeshEdge &other) const
{
    return this->vertexA == other.vertexA && this->vertexB == other.vertexB;
}

