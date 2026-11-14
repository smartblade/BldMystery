#ifndef CONTACT_LIST_H

#define CONTACT_LIST_H

#include <BBLibc/array.h>
#include <AnalyticGeometry/Vector.h>

class B_Sector;


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


class B_ContactList
{
public:
    B_ContactList();
    ~B_ContactList();

    B_SharedPtrArray<B_ContactPoint> points;
    B_SharedPtrArray<B_Sector> sectors;
    int type;
};

#ifdef __cplusplus
extern "C" {
#endif

extern int newExclusionGroupId();

#ifdef __cplusplus
}
#endif

#endif /* CONTACT_LIST_H */
