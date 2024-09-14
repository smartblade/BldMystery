#define BBLIBC_LIB_EXPORT
#include <bld_system.h>
#include "List.h"
//#include "ListElement.h"

// B_ListElement implementation

/*
* Module:                 BBLibc.dll
* Entry point:            0x10002EA0
* VC++ mangling:          ??0B_ListElement@@QAE@XZ
*/

B_ListElement::B_ListElement() : list(0), member2(0), member3(0) {};


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F40
* VC++ mangling:          ??0B_ListElement@@QAE@ABV0@@Z
*/

B_ListElement::B_ListElement(const B_ListElement& other) : list(other.list), member2(other.member2), member3(other.member3) {};


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002980
* VC++ mangling:          ??1B_ListElement@@UAE@XZ
*/

B_ListElement::~B_ListElement()
{
    if (this->list != 0) {
        this->list->Remove(this, 0);
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002EE0
* VC++ mangling:          ?GetList@B_ListElement@@QAEPAVB_List@@XZ
*/
#ifndef BLD_NATIVE
B_List* B_ListElement::GetList()
{
    return nullptr;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F00
* VC++ mangling:          ?GetNext@B_ListElement@@QAEPAV1@XZ
*/
#ifndef BLD_NATIVE
B_ListElement* B_ListElement::GetNext()
{
    return nullptr;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F20
* VC++ mangling:          ?GetPrev@B_ListElement@@QAEPAV1@XZ
*/
#ifndef BLD_NATIVE
B_ListElement* B_ListElement::GetPrev()
{
    return nullptr;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F80
* VC++ mangling:          ??4B_ListElement@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_ListElement& B_ListElement::operator =(const B_ListElement& other)
{
    return *this;
}
#endif


// B_List implementation

/*
* Module:                 BBLibc.dll
* Entry point:            0x100030A0
* VC++ mangling:          ??0B_List@@QAE@PAVB_ListElement@@@Z
*/
#ifndef BLD_NATIVE
B_List::B_List(B_ListElement* element)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003160
* VC++ mangling:          ??0B_List@@QAE@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_List::B_List(B_List const&)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100030E0
* VC++ mangling:          ??1B_List@@UAE@XZ
*/

B_List::~B_List()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002A14
* VC++ mangling:          ?Add@B_List@@QAEIPAVB_ListElement@@@Z
*/
#ifndef BLD_NATIVE
unsigned int B_List::Add(B_ListElement* element)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002A86
* VC++ mangling:          ?AddAfter@B_List@@QAEIPAVB_ListElement@@0@Z
*/
#ifndef BLD_NATIVE
unsigned int B_List::AddAfter(B_ListElement* existing, B_ListElement* newElement)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002B34
* VC++ mangling:          ?AddBefore@B_List@@QAEIPAVB_ListElement@@0@Z
*/
#ifndef BLD_NATIVE
unsigned int B_List::AddBefore(B_ListElement* existing, B_ListElement* newElement)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002BC5
* VC++ mangling:          ?Remove@B_List@@QAEIPAVB_ListElement@@I@Z
*/
#ifndef BLD_NATIVE
unsigned int B_List::Remove(B_ListElement* element, unsigned int index)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002E5D
* VC++ mangling:          ?Exists@B_List@@QAEIPBVB_ListElement@@@Z
*/

#ifndef BLD_NATIVE
unsigned int B_List::Exists(const B_ListElement* element)
{
    return false;
}
#endif
