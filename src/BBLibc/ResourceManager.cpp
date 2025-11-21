#define BBLIBC_LIB_EXPORT
#include "ResourceManager.h"
#include "IDataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004425
*/
#ifndef BLD_NATIVE
B_Resource *B_ResourceLocation::GetResource(unsigned short resourceId)
{
    return nullptr;
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
void B_ResourceManager::Clean()
{

}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10004C20
* VC++ mangling:          ?GetnFiles@B_ResourceManager@@QAEIXZ
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::GetnFiles()
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10004C37
* VC++ mangling:          ?GetFile@B_ResourceManager@@QAEPBDI@Z
*/
#ifndef BLD_NATIVE
const char *B_ResourceManager::GetFile(unsigned int arg_1)
{
    return nullptr;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10004C76
* VC++ mangling:          ?AddFile@B_ResourceManager@@AAEIABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::AddFile(const B_Name &arg_1)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004E0B
* VC++ mangling:          ?LocateResourceIn@B_ResourceManager@@QAEIABVB_Name@@PBV2@H@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::LocateResourceIn(const B_Name &id, const B_Name*, int)
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005533
* VC++ mangling:          ?LocateResourcesIn@B_ResourceManager@@AAEIABVB_Name@@AAVB_IDataFile@@@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::LocateResourcesIn(
    const B_Name &arg_1,
    B_IDataFile &arg_2
)
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
B_Resource *B_ResourceManager::GetResource(unsigned short resourceId, const B_Name &name)
{
    // TODO Implement
    unsigned short id = resourceId;
    const B_Name &resourceName = name;

    // Check if the resourceId is valid
    if (resources_[id] == 0) {
        return nullptr;
    }

    return nullptr; 
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005B2F
* VC++ mangling:          ?GetResourceIndex@B_ResourceManager@@QAEIGABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::GetResourceIndex(
    unsigned short arg_1,
    const B_Name &arg_2
)
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005B6F
* VC++ mangling:          ?GetResource@B_ResourceManager@@QAEPAVB_Resource@@GI@Z
*/
#ifndef BLD_NATIVE
B_Resource *B_ResourceManager::GetResource(
    unsigned short arg_1,
    unsigned int arg_2
)
{
    return nullptr;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005BB2
* VC++ mangling:          ?LoadResourceToMemory@B_ResourceManager@@QAEIGPBD@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::LoadResourceToMemory(
    unsigned short arg_1,
    const char *arg_2
)
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005C13
* VC++ mangling:          ?SaveResource@B_ResourceManager@@QAEIGIPBD@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ResourceManager::SaveResource(
    unsigned short arg_1,
    unsigned int arg_2,
    const char *arg_3
)
{
    return 0;
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
* Entry point:            0x10005D06
* VC++ mangling:          ?IsResourceLoaded@B_ResourceManager@@QAEHHPBD@Z
*/
#ifndef BLD_NATIVE
int B_ResourceManager::IsResourceLoaded(int arg_1, const char *arg_2)
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005DAE
* VC++ mangling:          ?IsResourceLinked@B_ResourceManager@@QAEHHPBD@Z
*/
#ifndef BLD_NATIVE
int B_ResourceManager::IsResourceLinked(int arg_1, const char *arg_2)
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005E42
* VC++ mangling:          ?GetResourceName@B_ResourceManager@@QAEPBDGI@Z
*/
#ifndef BLD_NATIVE
const char *B_ResourceManager::GetResourceName(
    unsigned short arg_1,
    unsigned int arg_2
)
{
    return nullptr;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10005E8F
* VC++ mangling:          ?GetResourceFile@B_ResourceManager@@QAEPBDGI@Z
*/
#ifndef BLD_NATIVE
const char *B_ResourceManager::GetResourceFile(
    unsigned short arg_1,
    unsigned int arg_2
)
{
    return nullptr;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005ED1
* VC++ mangling:          ?FreeResource@B_ResourceManager@@QAEXPAVB_Resource@@@Z
*/
#ifndef BLD_NATIVE
void B_ResourceManager::FreeResource(B_Resource *resource)
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
void B_ResourceManager::AddBodLink(const char *c, int i, const char *pc, int i1)
{
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006830
* VC++ mangling:          ??4B_ResourceManager@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_ResourceManager &B_ResourceManager::operator =(const B_ResourceManager &that)
{
    return *this;
}
#endif
