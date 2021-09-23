#ifndef BLD_NATIVE

#include <bld_system.h>

class B_Matrix
{
public:
    B_Matrix();
};

B_Matrix::B_Matrix()
{
}

#ifdef __cplusplus
extern "C" {
#endif

void *ERM_GetResource;
void *ERM_FreeResource;
void *UpdateAGTexture;

#ifdef __cplusplus
}
#endif

#endif
