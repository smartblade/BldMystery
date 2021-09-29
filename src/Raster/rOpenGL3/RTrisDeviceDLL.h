#pragma once

#include <Raster/RasterDevice.h>
#include <AnalyticGeometry/Vector.h>


#define MAX_VERTICES           4096
#define MAX_EDGES              4096
#define MAX_TRIANGLES          4096


class B_LightSource;


struct B_PointLight
{
    B_LightSource *light;
    B_Vector pointToPlane;
    float planeDist;
};


struct B_Vertex
{
    B_Vector pos;
    float textureCoords[2];
    float color[3];
    float fUnknown02C;
    float fog;
    float fUnknown034;
    float fUnknown038;
    float fUnknown03C;
    float fUnknown040;
    float sqrLightDist;
    int unknown048;
};


struct B_Edge
{
    unsigned int firstVertexIndex;
    unsigned int secondVertexIndex;
    B_Edge *nextEdge;
    float sqrLen;
    B_PointLight *light;
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
    void SplitEdge(B_Edge *edge);
    int SplitLightenedEdges();
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
    unsigned int numVertices;
    B_Vertex vertices[MAX_VERTICES];
    unsigned int numEdges;
    B_Edge edges[MAX_EDGES];
    unsigned int numTriangles;
    B_Triangle triangles[MAX_TRIANGLES];
    B_PointLight *currentPointLight;
    int unknown07A17C[10247];
};
