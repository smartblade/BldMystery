
#ifndef B_LIST_H
#define B_LIST_H

// #include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class B_List;

class LIB_EXP B_ListElement
{
public:

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002EA0
    * VC++ mangling:          ??0B_ListElement@@QAE@XZ
    */

    B_ListElement() : list(nullptr), member2(0), member3(0)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002F40
    * VC++ mangling:          ??0B_ListElement@@QAE@ABV0@@Z
    */

    B_ListElement(const B_ListElement& other)
        : list(other.list), member2(other.member2), member3(other.member3)
    {
    }

    virtual ~B_ListElement();

    B_ListElement& operator =(const B_ListElement& other);

    B_List* GetList();
    B_ListElement* GetNext();
    B_ListElement* GetPrev();

    B_List* list;
    unsigned int member2;
    unsigned int member3;

//private:
};

class LIB_EXP B_List
{
public:
    B_List(B_ListElement* element);
    B_List(B_List const&);

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100030E0
    * VC++ mangling:          ??1B_List@@UAE@XZ
    */

    virtual ~B_List()
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100031A0
    * VC++ mangling:          ??4B_List@@QAEAAV0@ABV0@@Z
    */

    B_List& operator=(const B_List& that)
    {
        numElements = that.numElements;
        tail = that.tail;
        head = that.head;
        return *this;
    }

    unsigned int Add(B_ListElement* element);
    unsigned int AddAfter(B_ListElement* existing, B_ListElement* newElement);
    unsigned int AddBefore(B_ListElement* existing, B_ListElement* newElement);
    unsigned int Remove(B_ListElement* element, unsigned int index);
    unsigned int Exists(const B_ListElement* element);

private:
    int numElements;
    B_ListElement* tail;
    B_ListElement* head;
};

#endif  // B_LIST_H
