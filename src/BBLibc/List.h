
#ifndef B_LIST_H
#define B_LIST_H

// #include <bld_system.h>


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class B_List;

class LIB_EXP B_ListElement {
public:
    B_ListElement();
    B_ListElement(const B_ListElement& other);
    virtual ~B_ListElement();

    B_ListElement& operator=(const B_ListElement& other);

    B_ListElement* GetPrev();
    B_ListElement* GetNext();
    B_List* GetList();

    B_List* list;
    unsigned int member2;
    unsigned int member3;

//private:
};

class LIB_EXP B_List {
public:
    B_List(B_ListElement* element);
    virtual ~B_List();
    unsigned int Add(B_ListElement* element);
    unsigned int AddBefore(B_ListElement* existing, B_ListElement* newElement);
    unsigned int AddAfter(B_ListElement* existing, B_ListElement* newElement);
    bool Exists(const B_ListElement* element) const;
    unsigned int Remove(B_ListElement* element, unsigned int index);

private:
    B_ListElement* list_;
};

#endif  // B_LIST_H
