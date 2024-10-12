#define BBLIBC_LIB_EXPORT
#include "ResourceManager.h"
#include "IDataFile.h"


/*
* Module:                 BBLibc.dll
* Data address:           0x1004A118
* VC++ mangling:          ?B_resource_manager@@3VB_ResourceManager@@A
*/
#ifndef BLD_NATIVE
B_ResourceManager B_resource_manager;
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10004425
*/
#ifndef BLD_NATIVE
B_Resource* B_ResourceManager::sub_10004425(unsigned short resourceId, const B_Name& name)
{
    // TODO Implement
    int var_402C = 0;
    int var_4028 = 0;
    int Src = 0;
    int var_4020 = 0;
    int var_401C = 0;
    int var_4018 = 0;

    counter++;

    if (this->resourceId == 0) {
        // Error handling: print an error message
        //B_MessageManager* messageManager = ? ? mout@@3VB_MessageManager@@A;
        /*messageManager->operator<<(aBResourcelocat);
        messageManager->operator<<(asc_100472B4);
        messageManager->operator<<(asc_100472B8);*/
        return nullptr;
    }

    return nullptr;;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100049F8
* VC++ mangling:          ??0B_ResourceManager@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_ResourceManager::B_ResourceManager()
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004A9B
* VC++ mangling:          ??1B_ResourceManager@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_ResourceManager::~B_ResourceManager()
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004AE0
* VC++ mangling:          ?Clean@B_ResourceManager@@QAEXXZ
*/
#ifndef BLD_NATIVE
void B_ResourceManager::Clean(void)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004E0B
* VC++ mangling:          ?LocateResourceIn@B_ResourceManager@@QAEIABVB_Name@@PBV2@H@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::LocateResourceIn(const B_Name& id, const B_Name*, int)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000582E
* VC++ mangling:          ?AddAutoResource@B_ResourceManager@@QAEIABVB_Name@@PAVB_Resource@@H@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::AddAutoResource(B_Name const&, B_Resource*, int)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005AF0
* VC++ mangling:          ?GetResource@B_ResourceManager@@QAEPAVB_Resource@@GABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
B_Resource* B_ResourceManager::GetResource(unsigned short resourceId, const B_Name& name)
{
    // TODO Implement
    unsigned short id = resourceId;
    const B_Name& resourceName = name;

    // Check if the resourceId is valid
    if (resources_[id] == 0) {
        return nullptr;
    }

    return nullptr; 
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005CCD
* VC++ mangling:          ?IsResourceLoaded@B_ResourceManager@@QAEHHH@Z
*/
#ifndef BLD_NATIVE
int B_ResourceManager::IsResourceLoaded(int, int)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005ED1
* VC++ mangling:          ?FreeResource@B_ResourceManager@@QAEXPAVB_Resource@@@Z
*/
#ifndef BLD_NATIVE
void B_ResourceManager::FreeResource(B_Resource* resource)
{
    delete resource;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005F32
* VC++ mangling:          ?NResources@B_ResourceManager@@QAEIG@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::NResources(unsigned short)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005F66
* VC++ mangling:          ?AddBodLink@B_ResourceManager@@QAEXPBDH0H@Z
*/
#ifndef BLD_NATIVE
void B_ResourceManager::AddBodLink(char const* c, int i, char const* pc, int i1)
{
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006830
* VC++ mangling:          ??4B_ResourceManager@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_ResourceManager& B_ResourceManager::operator =(const B_ResourceManager& that)
{
    return *this;
}
#endif


B_ResourceManager* GetResourceManager() {
    return &B_resource_manager;
}


