#ifndef B_RDataTriangle_H
#define B_RDataTriangle_H


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class B_IDataFile;
class B_ODataFile;


#ifdef __cplusplus
extern "C" {
#endif

    /*
    * Module:                 BBLibc.dll
    * Data address:           0x1004BF6C
    */
    extern int gbl_loading_packed;

#ifdef __cplusplus
}
#endif


class B_RItem
{
};


class B_ModelTriangleData
{
public:
    long bmpHandle;
    float u[3];
    float v[3];
};

B_IDataFile &operator >>(B_IDataFile &file, B_ModelTriangleData &data);
B_ODataFile &operator <<(B_ODataFile &file, const B_ModelTriangleData &data);


class LIB_EXP B_RDataTriangle : public B_RItem
{
public:
    B_RDataTriangle();

    B_RDataTriangle &operator=(const B_RDataTriangle &);

private:

};

#endif  // B_RDataTriangle_H
