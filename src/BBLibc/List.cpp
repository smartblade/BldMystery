#define BBLIBC_LIB_EXPORT
#include "List.h"
//#include "ListElement.h"


// B_ListElement implementation

/*
* Module:                 BBLibc.dll
* Entry point:            0x10002EA0
* VC++ mangling:          ??0B_ListElement@@QAE@XZ
*/

B_ListElement::B_ListElement() : list(0), member2(0), member3(0) {}; // {


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F40
* VC++ mangling:          ??0B_ListElement@@QAE@ABV0@@Z
*/

B_ListElement::B_ListElement(const B_ListElement& other) : list(other.list), member2(other.member2), member3(other.member3) {}; // {


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002980
* VC++ mangling:          ??1B_ListElement@@UAE@XZ
*/

B_ListElement::~B_ListElement() {
    // Implementation details
    if (this->list != 0) {
        //B_List::Remove(this, 0);
        this->list->Remove(this, 0);
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100031A0
* VC++ mangling:          ??4B_List@@QAEAAV0@ABV0@@Z
*/

B_ListElement& B_ListElement::operator=(const B_ListElement& other) {
    // Implementation details
    return *this;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F20
* VC++ mangling:          ?GetPrev@B_ListElement@@QAEPAV1@XZ
*/

B_ListElement* B_ListElement::GetPrev() {
    // Implementation details
    return nullptr;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F00
* VC++ mangling:          ?GetNext@B_ListElement@@QAEPAV1@XZ
*/

B_ListElement* B_ListElement::GetNext() {
    // Implementation details
    return nullptr;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002EE0
* VC++ mangling:          ?GetList@B_ListElement@@QAEPAVB_List@@XZ
*/

B_List* B_ListElement::GetList() {
    // Implementation details
    return nullptr;
}


// B_List implementation

/*
* Module:                 BBLibc.dll
* Entry point:            0x100030A0
* VC++ mangling:          ??0B_List@@QAE@PAVB_ListElement@@@Z
*/

B_List::B_List(B_ListElement* element) {
    // Implementation details
}


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

unsigned int B_List::Add(B_ListElement* element) {
    // Implementation details
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002B34
* VC++ mangling:          ?AddBefore@B_List@@QAEIPAVB_ListElement@@0@Z
*/

unsigned int B_List::AddBefore(B_ListElement* existing, B_ListElement* newElement) {
    // Implementation details
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002A86
* VC++ mangling:          ?AddAfter@B_List@@QAEIPAVB_ListElement@@0@Z
*/

unsigned int B_List::AddAfter(B_ListElement* existing, B_ListElement* newElement) {
    // Implementation details
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002BC5
* VC++ mangling:          ?Remove@B_List@@QAEIPAVB_ListElement@@I@Z
*/

unsigned int B_List::Remove(B_ListElement* element, unsigned int index) {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002E5D
* VC++ mangling:          ?Exists@B_List@@QAEIPBVB_ListElement@@@Z
*/

// ?Exists@B_List@@QBE_NPBVB_ListElement@@@Z
bool B_List::Exists(const B_ListElement* element) const {
    // Implementation details
    return false;
}
