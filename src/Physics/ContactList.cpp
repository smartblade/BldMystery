#include <Physics/ContactList.h>


#ifndef BLD_NATIVE

#ifdef __cplusplus
extern "C" {
#endif

B_ContactPointPool gbl_contact_point_pool;

#ifdef __cplusplus
}
#endif

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004ABE5C
* VC++ mangling:          ??0B_ContactList@@QAE@XZ
*/

B_ContactList::B_ContactList()
:
    type(0)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004ABF07
* VC++ mangling:          ??1B_ContactList@@QAE@XZ
*/

B_ContactList::~B_ContactList()
{
    this->Clear();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004AC1B9
* VC++ mangling:          ?Clear@B_ContactList@@QAEXXZ
*/

void B_ContactList::Clear()
{
    this->sectors.Clear(false);
    for (unsigned int i = 0; i < this->points.size; i++)
    {
        B_ContactPoint *point = this->points[i];
        point->next = gbl_contact_point_pool.freeList;
        gbl_contact_point_pool.freeList = point;
    }
    this->points.Clear(false);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004AC6C2
*/
#ifndef BLD_NATIVE
int newExclusionGroupId()
{
    return 0;
}
#endif
