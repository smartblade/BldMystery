#define BBLIBC_LIB_EXPORT
#include "ResourceManager.h"
#include "IDataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005AF0
* VC++ mangling:          ?GetResource@B_ResourceManager@@QAEPAVB_Resource@@GABVB_Name@@@Z
*/

B_Resource* B_ResourceManager::GetResource(unsigned short resourceId, const B_Name& name) {
    // TODO Implement
    unsigned short id = resourceId;
    const B_Name& resourceName = name;

    // Check if the resourceId is valid
    if (resources_[id] == 0) {
        return nullptr;
    }

    return nullptr; 
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005ED1
* VC++ mangling:          ?FreeResource@B_ResourceManager@@QAEXPAVB_Resource@@@Z
*/

void B_ResourceManager::FreeResource(B_Resource* resource) {
    // TODO Implement
    delete resource;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004E0B
* VC++ mangling:          ?LocateResourceIn@B_ResourceManager@@QAEIABVB_Name@@PBV2@H@Z
*/

unsigned int B_ResourceManager::LocateResourceIn(const B_Name & id, const B_Name*, int) {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004425
* VC++ mangling:          ?sub_10004425@B_ResourceManager@@QAEPAVB_Resource@@GABVB_Name@@@Z
*/

struct B_Resource* B_ResourceManager::sub_10004425(unsigned short resourceId, const B_Name& name) {
    // TODO Implement
    int var_402C = 0;
    int var_4028 = 0;
    int Src = 0;
    int var_4020 = 0;
    int var_401C = 0;
    int var_4018 = 0;

    counter_20h++;

    if (resourceId_1Ch == 0) {
        // Error handling: print an error message
        //B_MessageManager* messageManager = ? ? mout@@3VB_MessageManager@@A;
        /*messageManager->operator<<(aBResourcelocat);
        messageManager->operator<<(asc_100472B4);
        messageManager->operator<<(asc_100472B8);*/
        return nullptr;
    }

    return nullptr;;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005F66
* VC++ mangling:          ?AddBodLink@B_ResourceManager@@QAEXPBDH0H@Z
*/

void B_ResourceManager::AddBodLink(char const* c, int i, char const* pc, int i1) {
    // TODO Implement
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000582E
* VC++ mangling:          ?AddAutoResource@B_ResourceManager@@QAEIABVB_Name@@PAVB_Resource@@H@Z
*/

unsigned int B_ResourceManager::AddAutoResource(B_Name const&, B_Resource*, int) {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005F32
* VC++ mangling:          ?NResources@B_ResourceManager@@QAEIG@Z
*/

unsigned int B_ResourceManager::NResources(unsigned short) {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005CCD
* VC++ mangling:          ?IsResourceLoaded@B_ResourceManager@@QAEHHH@Z
*/

int B_ResourceManager::IsResourceLoaded(int, int) {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004AE0
* VC++ mangling:          ?Clean@B_ResourceManager@@QAEXXZ
*/

void B_ResourceManager::Clean(void) {
    // TODO Implement
}


B_ResourceManager* GetResourceManager() {
    // TODO Implement
    return &B_resource_manager;
}


