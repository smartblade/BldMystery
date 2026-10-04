#include <BWorld/OctTree.h>
#include <AnalyticGeometry/BoundingBox.h>
#include <BBLibc/BBLibc.h>
#include <BBLibc/MessageManager.h>
#include <BBLibc/Vararg.h>
#include "bld_misc_funcs.h"
#include <math.h>


static double child_size_divisor = 2.0;
static double child_offset_divisor = 4.0;
static double kOctTreeMargin = 10.0;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00450327
* VC++ mangling:          ??0B_OctantNode@@QAE@XZ
*/
B_OctantNode::B_OctantNode() {
    for (unsigned int i = 0; i < 8; ++i) {
        children[i] = nullptr;
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00450380
* VC++ mangling:          ??1B_OctantNode@@UAE@XZ
*/
B_OctantNode::~B_OctantNode()
{
    for (unsigned int i = 0; i < 8; ++i) {
        if (children[i] != nullptr) {
            delete children[i];
        }
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00450407
* VC++ mangling:          ?GetTypeID@B_OctantNode@@UAEHXZ
*/

int B_OctantNode::GetTypeID() 
{

    return B_OCT_NODE_CID_BRANCH;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00450417
* VC++ mangling:          ??0LeafNode@@QAE@XZ
*/

LeafNode::LeafNode()
{
    sectors = nullptr;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00450450
* VC++ mangling:          ??1LeafNode@@UAE@XZ
*/

LeafNode::~LeafNode()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045047C
* VC++ mangling:          ?GetTypeID@LeafNode@@UAEHXZ
*/
int LeafNode::GetTypeID() 
{
    return B_OCT_NODE_CID_LEAF;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045048C
* VC++ mangling:          ??0B_SectorListNode@@QAE@XZ
*/

B_SectorListNode::B_SectorListNode(): B_SharedPtrArray<B_Sector>(1)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045050B
* VC++ mangling:          ??1B_SectorListNode@@UAE@XZ
*/


B_SectorListNode::~B_SectorListNode()
{

}


/*
* Module:                 Blade.exe
* Entry point:            0x004506B5
* VC++ mangling:          ?GetTypeID@B_SectorListNode@@UAEHXZ
*/

int B_SectorListNode::GetTypeID() {
    return B_OCT_NODE_CID_SECTOR_LIST;
};


B_OctTree::B_OctTree()
{
}


B_OctantNodeBase::B_OctantNodeBase() {
    gbl_node_count++;
};


// 4507D5
/*
* Module:                 Blade.exe
* Entry point:            0x004507B9
* VC++ mangling:          ??1B_OctTree@@QAE@XZ
*/

B_OctTree::~B_OctTree()
{
    if (this->m_root != nullptr) {
        delete this->m_root;

        this->m_root = nullptr;
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00450823
* VC++ mangling:          ?BuildNode@@YAPAVB_OctantNodeBase@@ABV?$B_PtrArray@VB_Sector@@@@NABVB_BoundingBox@@@Z
*/
// FIXME latest update broke this, need to investigate
#ifndef BLD_NATIVE
B_OctantNodeBase* BuildNode(const B_PtrArray<B_Sector>& map, double sizeThreshold, const B_BoundingBox& worldBB)
{
    if (map.size == 0)
        return nullptr;

    if (map.size == 1) {
        LeafNode* leaf = new LeafNode();
        leaf->sectors = map.elements[0];
        return leaf;
    }

    double width = worldBB.maxCoords.x - worldBB.minCoords.x;
    if (width >= sizeThreshold && map.size >= 8)
    {
        B_BoundingBox childBB;
        B_PtrArray<B_Sector> outBuffer(16, false);
        B_OctantNode* node = new B_OctantNode();
        B_Vector center = (worldBB.minCoords + worldBB.maxCoords) * 0.5;

        childBB.minCoords = worldBB.minCoords;
        childBB.maxCoords = center;
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[0] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        childBB.minCoords = B_Vector(worldBB.minCoords.x, worldBB.minCoords.y, center.z);
        childBB.maxCoords = B_Vector(center.x, center.y, worldBB.maxCoords.z);
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[1] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        childBB.minCoords = B_Vector(worldBB.minCoords.x, center.y, worldBB.minCoords.z);
        childBB.maxCoords = B_Vector(center.x, worldBB.maxCoords.y, center.z);
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[2] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        childBB.minCoords = B_Vector(worldBB.minCoords.x, center.y, worldBB.minCoords.z);
        childBB.maxCoords = B_Vector(center.x, worldBB.maxCoords.y, worldBB.maxCoords.z);
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[3] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        childBB.minCoords = B_Vector(center.x, worldBB.minCoords.y, worldBB.minCoords.z);
        childBB.maxCoords = B_Vector(worldBB.maxCoords.x, center.y, center.z);
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[4] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        childBB.minCoords = B_Vector(center.x, worldBB.minCoords.y, center.z);
        childBB.maxCoords = B_Vector(worldBB.maxCoords.x, center.y, worldBB.maxCoords.z);
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[5] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        childBB.minCoords = B_Vector(center.x, center.y, worldBB.minCoords.z);
        childBB.maxCoords = B_Vector(worldBB.maxCoords.x, worldBB.maxCoords.y, center.z);
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[6] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        childBB.minCoords = center;
        childBB.maxCoords = worldBB.maxCoords;
        childBB.CollectIntersectingSectors(map, outBuffer);
        node->children[7] = BuildNode(outBuffer, sizeThreshold, childBB);
        outBuffer.Clear(false);

        return node;
    }
    else
    {
        B_SectorListNode* node = new B_SectorListNode();
        for (unsigned int i = 0; i < map.size; i++)
            node->Append(map.elements[i]);
        return node;
    }
}
#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00451A21
* VC++ mangling:          ?Build@B_OctTree@@QAEXABVB_Map@@N@Z
*/

void B_OctTree::Build(const B_Map& map, double minNodeSize)
{
    if (m_root != nullptr)
    {
        delete m_root;
        m_root = nullptr;
    }
    m_halfSize = 0.0;

    B_BoundingBox bb;

    if (gbl_world_points.points.size != 0)
    {
        B_WorldPoint* points = gbl_world_points.points.elements;

        double maxX = points[0].v.x;
        double minX = points[0].v.x;
        double maxY = points[0].v.y;
        double minY = points[0].v.y;
        double maxZ = points[0].v.z;
        double minZ = points[0].v.z;

        for (unsigned int i = 1; i < gbl_world_points.points.size; i++)
        {
            maxX = max(maxX, points[i].v.x);
            minX = min(minX, points[i].v.x);
            maxY = max(maxY, points[i].v.y);
            minY = min(minY, points[i].v.y);
            maxZ = max(maxZ, points[i].v.z);
            minZ = min(minZ, points[i].v.z);
        }

        double maxExtent = max(maxX - minX, max(maxY - minY, maxZ - minZ));

        m_halfSize = maxExtent + 2.0 * minNodeSize;

        m_center.x = (maxX + minX) * 0.5;
        m_center.y = (maxY + minY) * 0.5;
        m_center.z = (maxZ + minZ) * 0.5;

        bb.minCoords = m_center - 0.5 * B_Vector(m_halfSize, m_halfSize, m_halfSize);
        bb.maxCoords = m_center + 0.5 * B_Vector(m_halfSize, m_halfSize, m_halfSize);
    }

    m_root = BuildNode(map, minNodeSize, bb);

    mout << vararg("OctTree with %d nodes.\n", gbl_node_count);
}



/*
* Module:                 Blade.exe
* Entry point:            0x0045201F
* VC++ mangling:          ?CollectSectorsAtPoint@LeafNode@@UAEXABVB_Vector@@PAVB_OctTreeSectorsList@@N@Z
*/

void LeafNode::CollectSectorsAtPoint(const B_Vector& localPos, B_OctTreeSectorsList* outList, double halfSize)
{

    if (this->sectors->lastQueryId != gbl_oct_tree_query_id && this->sectors->isActive != 0) {
        this->sectors->lastQueryId = gbl_oct_tree_query_id; // mark as "processed"

        if (outList->size < 0x200)
        {
            outList->sectors[outList->size] = this->sectors;
            outList->size++;
        }
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00452082
* VC++ mangling:          ?CollectSectorsInBox@LeafNode@@UAEXABVB_BoundingBox@@PAVB_OctTreeSectorsList@@N@Z
*/

void LeafNode::CollectSectorsInBox(const B_BoundingBox&, B_OctTreeSectorsList* outList, double)
{
    if (this->sectors->lastQueryId != gbl_oct_tree_query_id && this->sectors->isActive != 0)
    {
        this->sectors->lastQueryId = gbl_oct_tree_query_id;

        B_BoundingBox* sectorBB = &this->sectors->boundingBox;

        int intersects;

        if (gbl_current_query_box->minCoords.x > sectorBB->maxCoords.x ||
            gbl_current_query_box->minCoords.y > sectorBB->maxCoords.y ||
            gbl_current_query_box->minCoords.z > sectorBB->maxCoords.z ||
            gbl_current_query_box->maxCoords.x < sectorBB->minCoords.x ||
            gbl_current_query_box->maxCoords.y < sectorBB->minCoords.y ||
            gbl_current_query_box->maxCoords.z < sectorBB->minCoords.z)
        {
            intersects = 0;
        }
        else
        {
            intersects = 1;
        }

        if (intersects != 0)
        {
            if (outList->size < 0x200)
            {
                outList->sectors[outList->size] = this->sectors;
                outList->size++;
            }
        }
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00452191
* VC++ mangling:          ?CollectSectorsAtPoint@B_SectorListNode@@UAEXABVB_Vector@@PAVB_OctTreeSectorsList@@N@Z
*/

void B_SectorListNode::CollectSectorsAtPoint(const B_Vector& localPos, B_OctTreeSectorsList* outList, double halfSize)
{
    for (unsigned int i = 0; i < this->size; ++i) {

        if ((*this)[i]->lastQueryId != gbl_oct_tree_query_id && (*this)[i]->isActive != 0) {
            (*this)[i]->lastQueryId = gbl_oct_tree_query_id;

            if (outList->size < 0x200) {
                outList->sectors[outList->size] = (*this)[i];
                outList->size++;
            }
        }
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00452232
* VC++ mangling:          ?CollectSectorsInBox@B_SectorListNode@@UAEXABVB_BoundingBox@@PAVB_OctTreeSectorsList@@N@Z
*/

void B_SectorListNode::CollectSectorsInBox(const B_BoundingBox&, B_OctTreeSectorsList* outList, double)
{
    const B_BoundingBox& queryBB = *gbl_current_query_box;

    for (unsigned int i = 0; i < this->size; ++i) {

        if ((*this)[i]->lastQueryId != gbl_oct_tree_query_id &&
            (*this)[i]->isActive != 0) {

            (*this)[i]->lastQueryId = gbl_oct_tree_query_id;

            const B_BoundingBox& sectorBB = (*this)[i]->boundingBox;

            if (queryBB.minCoords.x <= sectorBB.maxCoords.x &&
                queryBB.minCoords.y <= sectorBB.maxCoords.y &&
                queryBB.minCoords.z <= sectorBB.maxCoords.z &&
                queryBB.maxCoords.x >= sectorBB.minCoords.x &&
                queryBB.maxCoords.y >= sectorBB.minCoords.y &&
                queryBB.maxCoords.z >= sectorBB.minCoords.z)
            {
                if (outList->size < 0x200) {
                    outList->sectors[outList->size] = (*this)[i];
                    outList->size++;
                }
            }
        }
    }

}




/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00452388
* VC++ mangling:          ?CollectSectorsAtPoint@B_OctantNode@@UAEXABVB_Vector@@PAVB_OctTreeSectorsList@@N@Z
*/

void B_OctantNode::CollectSectorsAtPoint(
    const B_Vector& localPos, 
    B_OctTreeSectorsList* outList,
    double halfSize)
{
    const double childHalfSize = halfSize / child_size_divisor;
    const double childOffset = halfSize / child_offset_divisor; 

    if (localPos.x < kOctTreeMargin)
    {
        if (localPos.y < kOctTreeMargin)
        {
            if (localPos.z < kOctTreeMargin && children[0] != nullptr) {
                B_Vector childCenter(-childOffset, -childOffset, -childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[0]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }

            if (localPos.z > -kOctTreeMargin && children[1] != nullptr) {
                B_Vector childCenter(-childOffset, -childOffset, childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[1]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }
        }

        if (localPos.y > -kOctTreeMargin)
        {
            if (localPos.z < kOctTreeMargin && children[2] != nullptr) {
                B_Vector childCenter(-childOffset, childOffset, -childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[2]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }

            if (localPos.z > -kOctTreeMargin && children[3] != nullptr) {
                B_Vector childCenter(-childOffset, childOffset, childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[3]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }
        }
    }

    if (localPos.x > -kOctTreeMargin)
    {
        if (localPos.y < kOctTreeMargin)
        {

            if (localPos.z < kOctTreeMargin && children[4] != nullptr) {
                B_Vector childCenter(childOffset, -childOffset, -childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[4]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }

            if (localPos.z > -kOctTreeMargin && children[5] != nullptr) {
                B_Vector childCenter(childOffset, -childOffset, childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[5]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }
        }

        if (localPos.y > -kOctTreeMargin)
        {

            if (localPos.z < kOctTreeMargin && children[6] != nullptr) {
                B_Vector childCenter(childOffset, childOffset, -childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[6]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }

            if (localPos.z > -kOctTreeMargin && children[7] != nullptr) {
                B_Vector childCenter(childOffset, childOffset, childOffset);
                B_Vector newLocalPos = localPos - childCenter;
                children[7]->CollectSectorsAtPoint(newLocalPos, outList, childHalfSize);
            }
        }
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00452845
* VC++ mangling:          ?CollectSectorsInBox@B_OctantNode@@UAEXABVB_BoundingBox@@PAVB_OctTreeSectorsList@@N@Z
*/
void B_OctantNode::CollectSectorsInBox(const B_BoundingBox& bb, B_OctTreeSectorsList* outList, double halfSize) {
    double childHalfSize = halfSize / child_size_divisor; // 2.0
    double childOffset = halfSize / child_offset_divisor; // 4.0

    B_BoundingBox childBox = bb;

    if (bb.minCoords.x < kOctTreeMargin)
    {
        if (bb.minCoords.y < kOctTreeMargin)
        {
            if (bb.minCoords.z < kOctTreeMargin)
            {
                if (children[0])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(-childOffset, -childOffset, -childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(-childOffset, -childOffset, -childOffset);
                    children[0]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
            if (bb.maxCoords.z > -kOctTreeMargin)
            {
                if (children[1])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(-childOffset, -childOffset, childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(-childOffset, -childOffset, childOffset);
                    children[1]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
        }

        if (bb.maxCoords.y > -kOctTreeMargin)
        {
            if (bb.minCoords.z < kOctTreeMargin)
            {
                if (children[2])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(-childOffset, childOffset, -childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(-childOffset, childOffset, -childOffset);
                    children[2]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
            if (bb.maxCoords.z > -kOctTreeMargin)
            {
                if (children[3])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(-childOffset, childOffset, childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(-childOffset, childOffset, childOffset);
                    children[3]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
        }
    }

    if (bb.maxCoords.x > -kOctTreeMargin)
    {
        if (bb.minCoords.y < kOctTreeMargin)
        {
            if (bb.minCoords.z < kOctTreeMargin)
            {
                if (children[4])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(childOffset, -childOffset, -childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(childOffset, -childOffset, -childOffset);
                    children[4]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
            if (bb.maxCoords.z > -kOctTreeMargin)
            {
                if (children[5])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(childOffset, -childOffset, childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(childOffset, -childOffset, childOffset);
                    children[5]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
        }

        if (bb.maxCoords.y > -kOctTreeMargin)
        {
            if (bb.minCoords.z < kOctTreeMargin)
            {
                if (children[6])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(childOffset, childOffset, -childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(childOffset, childOffset, -childOffset);
                    children[6]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
            if (bb.maxCoords.z > -kOctTreeMargin)
            {
                if (children[7])
                {
                    childBox.minCoords = bb.minCoords - B_Vector(childOffset, childOffset, childOffset);
                    childBox.maxCoords = bb.maxCoords - B_Vector(childOffset, childOffset, childOffset);
                    children[7]->CollectSectorsInBox(childBox, outList, childHalfSize);
                }
            }
        }
    }
}



/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00453067
* VC++ mangling:          ?FindSectorsAtPoint@B_OctTree@@UBEXABVB_Vector@@PAVB_OctTreeSectorsList@@@Z
*/

void B_OctTree::FindSectorsAtPoint(const B_Vector& worldPos, B_OctTreeSectorsList* outList) const
{
    outList->size = 0;

    B_Vector localPos = worldPos - m_center;

    gbl_oct_tree_query_id++;

    if (m_root != nullptr) {
        if (fabs(localPos.x) < this->m_halfSize + kOctTreeMargin &&
            fabs(localPos.y) < this->m_halfSize + kOctTreeMargin &&
            fabs(localPos.z) < this->m_halfSize + kOctTreeMargin) {
            m_root->CollectSectorsAtPoint(localPos, outList, m_halfSize);
        }
    }
}



/*
* Module:                 Blade.exe
* Entry point:            0x0045311A
* VC++ mangling:          ?FindSectorsInBox@B_OctTree@@UBEXABVB_BoundingBox@@PAVB_OctTreeSectorsList@@@Z
*/
#ifndef BLD_NATIVE
void B_OctTree::FindSectorsInBox(const B_BoundingBox& bb, B_OctTreeSectorsList* out) const
{
    out->size = 0;

    gbl_oct_tree_query_id++;
    gbl_current_query_box = &bb;

    B_BoundingBox localBB(bb.minCoords - m_center, bb.maxCoords - m_center);

    if (m_root == nullptr)
        return;

    double reject = 0.5 * m_halfSize + kOctTreeMargin;

    if (localBB.maxCoords.x > -reject && localBB.maxCoords.y > -reject && localBB.maxCoords.z > -reject &&
        localBB.minCoords.x < reject && localBB.minCoords.y < reject && localBB.minCoords.z < reject) {
        m_root->CollectSectorsInBox(localBB, out, m_halfSize);
    }
}
#endif



/*
* Module:                 Blade.exe
* Entry point:            0x00453264
* VC++ mangling:          ??0B_OctTreeSectorsList@@QAE@XZ
*/
B_OctTreeSectorsList::B_OctTreeSectorsList() : size(0) {}


/*
* Module:                 Blade.exe
* Entry point:            0x0045327B
* VC++ mangling:          ?BuildSurfaceCache@B_OctTreeSectorsList@@QAEHPAVB_GlobalSurfaceCache@@PBVB_Sphere@@@Z
*/
// TODO double check
int B_OctTreeSectorsList::BuildSurfaceCache(B_GlobalSurfaceCache* cache, const B_Sphere* sphere)
{
    cache->count = 0;

    for (int i = 0; i < this->size; i++)
    {
        B_Sector* current_sector = this->sectors[i];

        B_SectorSurfaceCache* cacheEntry = &cache->elements[cache->count];

        cacheEntry->sector = current_sector;
        cacheEntry->numSurfaces = 0;

        for (int j = 0; j < current_sector->size; j++)
        {
            B_Surface* current_surface = current_sector->elements[j];

            double distance = (sphere->center.z * current_surface->normal.z) +
                (sphere->center.y * current_surface->normal.y) +
                (sphere->center.x * current_surface->normal.x) +
                current_surface->p;

            if (distance >= -sphere->radius && distance <= sphere->radius)
            {
                cacheEntry->surfaces[cacheEntry->numSurfaces] = current_surface;
                cacheEntry->numSurfaces++;
            }
        }

        if (cacheEntry->numSurfaces == 0) {
            cacheEntry->hasNoIntersections = 1;
        }
        else {
            cacheEntry->hasNoIntersections = 0;
        }

        cache->count++;
    }

    if (cache->count == 0) {
        return -1;
    }
    return 0;
}



/*
* Module:                 Blade.exe
* Entry point:            0x0045346F
* VC++ mangling:          ??0B_SectorSurfaceCache@@QAE@XZ
*/


B_SectorSurfaceCache::B_SectorSurfaceCache()
{
    this->numSurfaces = 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004539A9
* VC++ mangling:          ??0B_GlobalSurfaceCache@@QAE@XZ
*/

B_GlobalSurfaceCache::B_GlobalSurfaceCache()
{
    this->count = 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00453490
* VC++ mangling:          ??1B_SectorSurfaceCache@@UAE@XZ
*/


B_SectorSurfaceCache::~B_SectorSurfaceCache()
{

}



/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00453AC0
* VC++ mangling:          ??1B_OctantNodeBase@@UAE@XZ
*/

B_OctantNodeBase::~B_OctantNodeBase()
{
    gbl_node_count--;
}



/*
................................................................................
................................................................................
................................................................................
................................................................................
*/



#ifndef BLD_NATIVE


#ifdef __cplusplus
extern "C" {
#endif

    unsigned int gbl_node_count;
    B_BoundingBox* gbl_current_query_box;
    unsigned int gbl_oct_tree_query_id;


#ifdef __cplusplus
}
#endif

#endif
