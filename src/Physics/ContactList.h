#ifndef CONTACT_LIST_H

#define CONTACT_LIST_H

#include <BBLibc/array.h>
#include <AnalyticGeometry/Vector.h>
#include <BWorld/BMap.h>


class B_ContactPoint
{
public:
    B_ContactPoint()
    :
        next(nullptr)
    {
    }

    B_ContactPoint *next;
    int kind;
    void *source;
    B_Vector position;
    B_Vector normal;
};


class B_ContactPointPool : public B_Array<B_ContactPoint>
{
public:
    B_ContactPointPool()
    :
        freeList(nullptr)
    {
    }

    B_ContactPoint *freeList;
};


class B_ContactList
{
public:
    B_ContactList();
    ~B_ContactList();
    void Clear();

    B_SharedPtrArray<B_ContactPoint> points;
    B_SharedPtrArray<B_Sector> sectors;
    int type;
};

#ifdef __cplusplus
extern "C" {
#endif

/*
* Module:                 Blade.exe
* Data address:           0x007362C8
*/
extern B_ContactPointPool gbl_contact_point_pool;

extern int newExclusionGroupId();

#ifdef __cplusplus
}
#endif

#endif /* CONTACT_LIST_H */
