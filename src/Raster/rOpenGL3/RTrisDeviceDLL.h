#pragma once

#include <Raster/RasterDevice.h>


struct B_PointLight
{
    int unknown000;
    int unknown004;
    int unknown008;
    int unknown00C;
    int unknown010;
    int unknown014;
    int unknown018;
    int unknown01C;
};


struct B_Edge
{
    unsigned int firstVertexIndex;
    unsigned int secondVertexIndex;
    B_Edge *nextEdge;
    float edge_unknown_r000C;
    void *light;
};


struct B_Triangle
{
    int invEdge1;
    int invEdge2;
    int invEdge3;
    B_Edge *edge1;
    B_Edge *edge2;
    B_Edge *edge3;
};


class B_TrisDevice : public B_3DRasterDevice
{
public:
    B_TrisDevice();
    virtual void unknown030();
    virtual void unknown034();
    virtual void unknown0BC();
    virtual void unknown0C4();
    virtual void unknown0E4();
    virtual void unknown0E8();
    virtual void unknown0F0();
    virtual void unknown0F4();
    virtual void unknown234() = 0;
    virtual void unknown238() = 0;
    virtual void unknown23C() = 0;
    virtual void unknown240();
    virtual void unknown244();
    void SplitTriangleThreeEdges(B_Triangle *triangle);
    void SplitTriangleTwoEdges(B_Triangle *triangle);
    void SplitTriangleOneEdge(B_Triangle *triangle);
    void SplitTriangles();

protected:
    int width;
    int height;
    int unknown005C;
    int unknown0060;
    int unknown064;
    int unknown068;
    int unknown06C;
    int unknown070;
    int unknown074;
    int ModeReflection;
    int unknown007C;
    int fogSubdivide;
    int unknown0084;
    int unknown0088[9];
    int unknown00AC;
    int numLights;
    void *lights[64];
    int numPointLights;
    B_PointLight pointLights[64];
    float unknown9B8;
    int unknown9BC[1515];
    int unknown002168;
    int numVertices;
    int vertices[77824];
    int numEdges;
    B_Edge edges[4096];
    int numTriangles;
    B_Triangle triangles[4096];
    int unknown07A178[10248];
};
