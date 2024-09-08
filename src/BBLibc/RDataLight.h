#ifndef B_RDataLight_H
#define B_RDataLight_H


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class LIB_EXP B_RDataLight {
public:
    B_RDataLight(float, float, float, float);
    B_RDataLight();

    void Interp(double, B_RDataLight&, double, B_RDataLight&);

    B_RDataLight& operator=(const B_RDataLight&);

private:
    // Add member variables and other implementation details as needed
};

#endif  // B_RDataLight_H
