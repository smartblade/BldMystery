
#ifndef B_RESOURCE_MANAGER_H

#define B_RESOURCE_MANAGER_H

#include "array.h"
#include <bld_system.h>
#include "Resource.h"

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_ResourceManager
{
public:
    B_Resource* GetResource(unsigned short resourceId, const B_Name& name);
    void FreeResource(B_Resource* resource);
    struct B_Resource* sub_10004425(unsigned short resourceId, const B_Name& name);
    unsigned int LocateResourceIn(const B_Name& id, const B_Name*, int);
    void AddBodLink(char const* c, int i , char const* pc, int i1);
    unsigned int AddAutoResource(B_Name const&, B_Resource*, int);
    unsigned int NResources(unsigned short);
    int IsResourceLoaded(int, int);
    void Clean(void);

private:
    B_Resource** resources_; //int unknown1; // offset 0h [ecx+4]
    int size; // offset 4h [ecx+8]
    int unknown3; // offset 8h
    int unknown4; // offset 0ch
    int unknown5; // offset 10h
    int unknown6; // offset 14h
    int unknown7; // offset 18h
    unsigned short resourceId_1Ch; // 1Ch
    int counter_20h; // offset 20h
};

LIB_EXP B_ResourceManager B_resource_manager; // global instance

B_ResourceManager* GetResourceManager();

#endif /* B_RESOURCE_MANAGER_H */