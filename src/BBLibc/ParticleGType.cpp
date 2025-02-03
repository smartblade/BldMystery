#define BBLIBC_LIB_EXPORT
#include "ParticleGType.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040F69
* VC++ mangling:          ??0B_ParticleGType@@QAE@ABVB_Name@@0KI@Z
*/
#ifndef BLD_NATIVE
B_ParticleGType::B_ParticleGType(const B_Name& new_type, const B_Name& parent_type, unsigned long operation_type, unsigned int duration)
    : B_NamedObj(new_type), duration(duration), bmpHandle(-1), operation_type(operation_type)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x1004118F
* VC++ mangling:          ??1B_ParticleGType@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_ParticleGType::~B_ParticleGType()
{
    bmpHandle = 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x1004122B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_ParticleGType@@@Z
*/
#ifndef BLD_NATIVE
B_IDataFile& operator >>(B_IDataFile& file, B_ParticleGType& particleType)
{
    return file;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100413EE
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_ParticleGType@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, const B_ParticleGType& particleType)
{
    file.Write(&particleType, sizeof(B_ParticleGType));
    return file;
}
#endif
