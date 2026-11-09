
#ifndef B_OBJ_DSCR_H

#define B_OBJ_DSCR_H

#include "array.h"
#include "MeshEdge.h"
#include "Resource.h"
#include <AnalyticGeometry/BoundingBox.h>
#include <AnalyticGeometry/Matrix.h>
#include <AnalyticGeometry/Vector.h>
#include <Raster/RasterDevice.h>
#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class B_ObjVertex
{
public:
    B_Vector position;
    B_Vector normal;
};

class B_ObjFace
{
public:
    unsigned int vertices[3];
    unsigned int edges[3];
    char unknownFields018[0x1C];
    unsigned long unknownField034;
};

class B_ObjNode : public B_NamedObj
{
public:
    int parent;
    B_Matrix unknownField010;
    char unknownFields090[0x14];
    unsigned int vertexCount;
    unsigned int firstVertex;
};

class B_ObjVertexArray : public array_t<B_ObjVertex>
{
};

class B_ObjFaceArray : public array_t<B_ObjFace>
{
};

class B_ObjNodeArray : public B_PtrArray<B_ObjNode>
{
};

class B_ObjFaceGroupArray : public array_t<unsigned char>
{
};

class B_MeshEdgeArray : public array_t<B_MeshEdge>
{
};

class LIB_EXP B_ObjDscr : public B_Resource
{
public:
    B_ObjDscr();
    ~B_ObjDscr();
    virtual unsigned short ClassId() const;
    virtual unsigned long CheckSum() const;
    virtual unsigned int SerialSize() const;
    unsigned int SavePacked(B_ODataFile &arg_1);
    unsigned int LoadPacked(B_IDataFile &arg_1);
    void SetUpNormals();
    void SetUpInertialT();
    int GetVtxNode(unsigned int);
    void SetUpEdges();
    void Draw(
        B_3DRasterDevice *raster, float x1, float y1, float x2, float y2,
        float scale, int i_unknown);
    void SetUpBSP();
    unsigned char EdgeFaceGrp(unsigned int);

    char unknownFields00C[0x18];
    B_ObjVertexArray vertices;
    B_ObjFaceArray faces;
    B_ObjNodeArray nodes;
    B_ObjFaceGroupArray faceGroups;
    char unknownFields078[0x44];
    B_MeshEdgeArray edges;
    char unknownFields0D0[0x60];
    B_Matrix inertia;
    B_Matrix unknownField1B0;
    double area;
    double mass;
    B_Vector centerOfMass;
    B_Sphere boundingSphere;
};


#endif /* B_OBJ_DSCR_H */
