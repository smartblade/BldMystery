#define BBLIBC_LIB_EXPORT
#include "ParticleGType.h"


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
* Entry point:            0x100023C0
*/
#ifndef BLD_NATIVE
void sub_100023C0(B_NamedObj* this_ptr, int arg_0)
{

}
#endif

