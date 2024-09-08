#define BBLIBC_LIB_EXPORT
#include "RDataLight.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040CBE
* VC++ mangling:          ??0B_RDataLight@@QAE@MMMM@Z
*/

B_RDataLight::B_RDataLight(float a, float b, float c, float d) {
    // Initialize member variables with a, b, c, and d
    // ...
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040CB0
* VC++ mangling:          ??0B_RDataLight@@QAE@XZ
*/

B_RDataLight::B_RDataLight() {
    // Initialize member variables with default values
    // ...
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040CE6
* VC++ mangling:          ?Interp@B_RDataLight@@QAEXNAAV1@N0@Z
*/

void B_RDataLight::Interp(double t, B_RDataLight& start, double u, B_RDataLight& end) {
    // Implement interpolation logic
    // ...
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x110007EF0
* VC++ mangling:          ??4B_RDataLight@@QAEAAV0@ABV0@@Z
*/

B_RDataLight& B_RDataLight::operator=(const B_RDataLight& other) {
    // Implement assignment operator logic
    // ...
    return *this;
}
