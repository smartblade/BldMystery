
#ifndef N_DATABASE_H

#define N_DATABASE_H

#include "array.h"
#include "Name.h"
#include "NamedObj.h"
#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


struct LIB_EXP B_ElementCSV : public B_NamedObj
{
    virtual ~B_ElementCSV();
    float mass;
    B_Name material;
};


template<class T> class B_NDataBase : public B_PtrArray<T>
{
};

extern LIB_EXP B_NDataBase<B_ElementCSV> B_csvs;

LIB_EXP unsigned int ReadCSV(const char* file_name, B_NDataBase<B_ElementCSV>* csvs);

#endif /* N_DATABASE_H */
