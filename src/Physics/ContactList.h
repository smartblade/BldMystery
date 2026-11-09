#ifndef CONTACT_LIST_H

#define CONTACT_LIST_H

#include <array.h>
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
    void Clear();

    B_SharedPtrArray<B_ContactPoint> points;
    B_SharedPtrArray<B_Sector> sectors;
    int type;
};

#endif /* CONTACT_LIST_H */
