
#ifndef OCT_TREE_H

#define OCT_TREE_H

#include <array.h>
#include <AnalyticGeometry/Vector.h>


class B_Sphere;
class B_Map;
class B_BoundingBox;
class B_Sector;
class B_Surface;


class B_SectorSurfaceCache {
public:
    B_SectorSurfaceCache();
    virtual ~B_SectorSurfaceCache();

    int IsPointInside(const B_Vector* point);

    B_Sector* sector;
    int numSurfaces;
    B_Surface* surfaces[64];
    int hasNoIntersections;
};


class B_GlobalSurfaceCache {
public:
    int count;
    B_SectorSurfaceCache elements[128];

    B_GlobalSurfaceCache();
};



class B_OctTreeSectorsList
{
public:
    /*
    * Module:                 Blade.exe
    * Entry point:            0x00453264
    * VC++ mangling:          ??0B_OctTreeSectorsList@@QAE@XZ
    */
    B_OctTreeSectorsList();

    int BuildSurfaceCache(B_GlobalSurfaceCache* cache, const B_Sphere* sphere);

    unsigned int size;

    B_Sector* sectors[0x200];
};

#define B_OCT_NODE_CID_BRANCH              8801
#define B_OCT_NODE_CID_LEAF                8802
#define B_OCT_NODE_CID_SECTOR_LIST         8803

class B_OctantNodeBase
{
public:
    B_OctantNodeBase();

    virtual int GetTypeID() = 0;
    virtual ~B_OctantNodeBase();

    virtual void CollectSectorsInBox(
        const B_BoundingBox& bb,
        B_OctTreeSectorsList* outList,
        double halfSize) = 0;

    virtual void CollectSectorsAtPoint(
        const B_Vector& localPos,
        B_OctTreeSectorsList* outList,
        double halfSize) = 0;
};


class B_OctantNode : public B_OctantNodeBase
{
public:

    B_OctantNode();

    virtual int GetTypeID() override;
    virtual ~B_OctantNode() override; 

    void CollectSectorsInBox(
        const B_BoundingBox& bb, 
        B_OctTreeSectorsList* outList, 
        double halfSize) override;

    virtual void CollectSectorsAtPoint(
        const B_Vector& localPos,
        B_OctTreeSectorsList* outList,
        double halfSize) override;

    B_OctantNodeBase* children[8];
};


class LeafNode : public B_OctantNodeBase
{
public:

    LeafNode();
    virtual int GetTypeID() override;
    virtual ~LeafNode() override;
    virtual void CollectSectorsInBox(const B_BoundingBox&, B_OctTreeSectorsList*, double) override;
    virtual void CollectSectorsAtPoint(const B_Vector& localPos, B_OctTreeSectorsList* outList, double halfSize) override;

    B_Sector* sectors;
};


class B_SectorListNode : public B_OctantNodeBase, public B_SharedPtrArray<B_Sector>
{
public:

    B_SectorListNode();

    virtual int GetTypeID() override;
    virtual ~B_SectorListNode(); 
    virtual void CollectSectorsInBox(const B_BoundingBox&, B_OctTreeSectorsList*, double) override;
    virtual void CollectSectorsAtPoint(const B_Vector&, B_OctTreeSectorsList*, double) override;
};



class B_OctTree
{
public:
    B_OctTree();
    ~B_OctTree();

    void Build(const B_Map&, double);

    virtual void FindSectorsInBox(const B_BoundingBox& bb, B_OctTreeSectorsList* out) const;
    virtual void FindSectorsAtPoint(const B_Vector&, B_OctTreeSectorsList*) const;

    B_Vector m_center;
    double m_halfSize;
    B_OctantNodeBase* m_root;
};


extern B_OctantNodeBase* BuildNode(const B_PtrArray<B_Sector>&, double sizeThreshold, const B_BoundingBox&);


#endif /* OCT_TREE_H */
