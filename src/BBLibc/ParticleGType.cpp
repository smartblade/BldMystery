#define BBLIBC_LIB_EXPORT
#include "ParticleGType.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040F69
* VC++ mangling:          ??0B_ParticleGType@@QAE@ABVB_Name@@0KI@Z
*/

B_ParticleGType::B_ParticleGType(const B_Name& new_type, const B_Name& parent_type, unsigned long operation_type, unsigned int duration)
    : B_NamedObj(new_type), duration(duration), bmpHandle(-1), operation_type(operation_type) {
    // TODO Implement
    bmpHandle = 1;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1004118F
* VC++ mangling:          ??1B_ParticleGType@@UAE@XZ
*/

B_ParticleGType::~B_ParticleGType() {
    // TODO Implement
    bmpHandle = 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x????????
* VC++ mangling:          ??
*/

int B_ParticleGType::operator >>(B_IDataFile& dest/*, B_ParticleGType&*/) {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x????????
* VC++ mangling:          ??
*/

int B_ParticleGType::operator <<(B_IDataFile& src/*, B_ParticleGType&*/) {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100023C0
*/

void sub_100023C0(B_NamedObj* this_ptr, int arg_0) {
    // TODO implement
}