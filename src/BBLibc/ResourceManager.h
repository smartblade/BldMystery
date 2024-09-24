
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
    B_ResourceManager();
    ~B_ResourceManager();
    B_Resource* sub_10004425(unsigned short resourceId, const B_Name& name);
    void Clean(void);
    unsigned int LocateResourceIn(const B_Name& id, const B_Name*, int);
    unsigned int AddAutoResource(B_Name const&, B_Resource*, int);
    B_Resource* GetResource(unsigned short resourceId, const B_Name& name);
    int IsResourceLoaded(int, int);
    void FreeResource(B_Resource* resource);
    unsigned int NResources(unsigned short);
    void AddBodLink(char const* c, int i, char const* pc, int i1);
    B_ResourceManager& operator =(const B_ResourceManager& that);

private:
    B_Resource** resources_;
    int size;
    int unknown08;
    int unknown0C;
    int unknown10;
    int unknown14;
    int unknown18;
    unsigned short resourceId; // 1Ch
    int counter; // 20h
};

extern LIB_EXP B_ResourceManager B_resource_manager; // global instance

B_ResourceManager* GetResourceManager();

#endif /* B_RESOURCE_MANAGER_H */