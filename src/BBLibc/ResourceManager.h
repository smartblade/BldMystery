
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


class B_ResourceLocation
{
public:
    B_Resource *GetResource(unsigned short resourceId);
};


class LIB_EXP B_ResourceManager
{
public:
    B_ResourceManager();
    ~B_ResourceManager();
    void Clean();
    unsigned int GetnFiles();
    const char *GetFile(unsigned int arg_1);
    unsigned int AddFile(const B_Name &arg_1);
    unsigned int LocateResourceIn(const B_Name &id, const B_Name*, int);
    unsigned int LocateResourcesIn(const B_Name &arg_1, B_IDataFile &arg_2);
    unsigned int AddAutoResource(B_Name const&, B_Resource*, int);
    B_Resource *GetResource(unsigned short resourceId, const B_Name &name);
    unsigned int GetResourceIndex(unsigned short arg_1, const B_Name &arg_2);
    B_Resource *GetResource(unsigned short arg_1, unsigned int arg_2);
    unsigned int LoadResourceToMemory(unsigned short arg_1, const char *arg_2);
    unsigned int SaveResource(
        unsigned short arg_1,
        unsigned int arg_2,
        const char *arg_3
    );
    int IsResourceLoaded(int, int);
    int IsResourceLoaded(int arg_1, const char *arg_2);
    int IsResourceLinked(int arg_1, const char *arg_2);
    const char *GetResourceName(unsigned short arg_1, unsigned int arg_2);
    const char *GetResourceFile(unsigned short arg_1, unsigned int arg_2);
    void FreeResource(B_Resource *resource);
    unsigned int NResources(unsigned short);
    void AddBodLink(const char *c, int i, const char *pc, int i1);
    B_ResourceManager &operator =(const B_ResourceManager &that);

private:
    B_Resource **resources_;
    void *unknown04;
    int unknown08;
    int unknown0C;
    int unknown10;
    int unknown14;
    int unknown18;
    unsigned short resourceId; // 1Ch
    int counter; // 20h
};

extern LIB_EXP B_ResourceManager B_resource_manager; // global instance

B_ResourceManager *GetResourceManager();

#endif /* B_RESOURCE_MANAGER_H */