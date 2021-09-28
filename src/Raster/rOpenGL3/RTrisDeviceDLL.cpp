#include "RTrisDeviceDLL.h"


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002CA05
* VC++ mangling:          ?unknown0E8@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown0E8()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002E3D1
* VC++ mangling:          ??0B_TrisDevice@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_TrisDevice::B_TrisDevice()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002EE80
* VC++ mangling:          ?unknown240@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown240()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002F3EA
* VC++ mangling:          ?unknown030@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown030()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002F40C
* VC++ mangling:          ?unknown034@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown034()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10030E68
* VC++ mangling:          ?unknown0F0@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown0F0()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10030F8C
* VC++ mangling:          ?unknown244@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown244()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x100313DE
* VC++ mangling:          ?unknown0F4@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown0F4()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x100314A0
* VC++ mangling:          ?unknown0BC@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown0BC()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10031630
* VC++ mangling:          ?unknown0C4@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown0C4()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10031845
* VC++ mangling:          ?unknown0E4@B_TrisDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TrisDevice::unknown0E4()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10032646
* VC++ mangling:          ?SplitTriangleThreeEdges@B_TrisDevice@@QAEXPAUB_Triangle@@@Z
*/
#ifndef BLD_NATIVE
void B_TrisDevice::SplitTriangleThreeEdges(B_Triangle *triangle)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x100329C6
* VC++ mangling:          ?SplitTriangleTwoEdges@B_TrisDevice@@QAEXPAUB_Triangle@@@Z
*/
#ifndef BLD_NATIVE
void B_TrisDevice::SplitTriangleTwoEdges(B_Triangle *triangle)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10032C9A
* VC++ mangling:          ?SplitTriangleOneEdge@B_TrisDevice@@QAEXPAUB_Triangle@@@Z
*/
#ifndef BLD_NATIVE
void B_TrisDevice::SplitTriangleOneEdge(B_Triangle *triangle)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10032E58
* VC++ mangling:          ?SplitTriangles@B_TrisDevice@@QAEXXZ
*/

void B_TrisDevice::SplitTriangles()
{
    B_Triangle *triangle = this->triangles;
    unsigned int numTriangles = this->numTriangles;
    for (unsigned int i = 0; i < numTriangles; i++)
    {
        if (triangle->edge1->nextEdge != NULL)
        {
            if (triangle->edge2->nextEdge != NULL)
            {
                if (triangle->edge3->nextEdge != NULL)
                {
                    this->SplitTriangleThreeEdges(triangle);
                }
                else
                {
                    this->SplitTriangleTwoEdges(triangle);
                }
            }
            else if (triangle->edge3->nextEdge != NULL)
            {
                B_Edge *edge1 = triangle->edge1;
                int invEdge1 = triangle->invEdge1;
                triangle->edge1 = triangle->edge3;
                triangle->invEdge1 = triangle->invEdge3;
                triangle->edge3 = triangle->edge2;
                triangle->invEdge3 = triangle->invEdge2;
                triangle->edge2 = edge1;
                triangle->invEdge2 = invEdge1;
                this->SplitTriangleTwoEdges(triangle);
            }
            else
            {
                this->SplitTriangleOneEdge(triangle);
            }
        }
        else if (triangle->edge2->nextEdge != NULL)
        {
            if (triangle->edge3->nextEdge != NULL)
            {
                B_Edge *edge1 = triangle->edge1;
                int invEdge1 = triangle->invEdge1;
                triangle->edge1 = triangle->edge2;
                triangle->invEdge1 = triangle->invEdge2;
                triangle->edge2 = triangle->edge3;
                triangle->invEdge2 = triangle->invEdge3;
                triangle->edge3 = edge1;
                triangle->invEdge3 = invEdge1;
                this->SplitTriangleTwoEdges(triangle);
            }
            else
            {
                B_Edge *edge1 = triangle->edge1;
                int invEdge1 = triangle->invEdge1;
                triangle->edge1 = triangle->edge2;
                triangle->invEdge1 = triangle->invEdge2;
                triangle->edge2 = triangle->edge3;
                triangle->invEdge2 = triangle->invEdge3;
                triangle->edge3 = edge1;
                triangle->invEdge3 = invEdge1;
                this->SplitTriangleOneEdge(triangle);
            }
        }
        else if (triangle->edge3->nextEdge != NULL)
        {
            B_Edge *edge1 = triangle->edge1;
            int invEdge1 = triangle->invEdge1;
            triangle->edge1 = triangle->edge3;
            triangle->invEdge1 = triangle->invEdge3;
            triangle->edge3 = triangle->edge2;
            triangle->invEdge3 = triangle->invEdge2;
            triangle->edge2 = edge1;
            triangle->invEdge2 = invEdge1;
            this->SplitTriangleOneEdge(triangle);
        }
        ++triangle;
    }
}
