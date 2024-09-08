
#ifndef B_I_DATA_FILE_H

#define B_I_DATA_FILE_H

#include "array.h"
#include <bld_system.h>
#include "ParticleGType.h"
#include "Color.h"
#include "NamedObj.h"
#include "BitMap24.h"

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

typedef struct {
    int unknownField1;
    int unknownField4; // align
    int fd;
    double unknownField2;
    char* unknownField3;
    int filePosition;
} someStruct_t;

class LIB_EXP B_IDataFile
{
public:
    B_IDataFile();
    B_IDataFile(const char* file_name, int flags);
    ~B_IDataFile();
    static void ResetnOpenedFiles();
    static int GetnOpenedFiles();
    static int GetnOpenFiles();
    static int SetOnOpenFunc(struct PyObject*);
    static void RemoveOnOpenFunc();
    void Close();
    void Open(const char* src, int flags);
    bool OK() {
        return fd != -1;
    }
    char const* GetFileName() const;
    long Length(void) const;
    long Seek(long offset, int whence);
    long Tell();
    unsigned char Peek();
    int Eof();
    void Read(void* data, unsigned int size);
    static PyObject* OnOpenFunc;
    B_IDataFile& operator =(const B_IDataFile& other);
private:
    unsigned int ReadCacheBlock();
    int fd;
    char* file_name;
    int file_size;
    char fileCache[16396]; // renamed field from `unknown_fields`
    unsigned int filePosition;
    unsigned int cacheBlock;
    someStruct_t* cacheBlockFlag;
    unsigned int unknown;
    someStruct_t* unknown_struct;

    int n_opened_files_internal;
    static int n_opened_files;
    static int n_open_files;
    int SetPosition(long position);
};

LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, unsigned int& i);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, unsigned long& i);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, float& f);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, double& f);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_Name& name);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_NamedObj& named_obj);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_Color& color);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_ParticleGType& particleType);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_BitMap24& bitMap);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, short& c);

LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, int& i);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, unsigned char& c);

// FIXME
LIB_EXP PyObject* CallPythonObject(PyObject* func, PyObject* args);

#endif /* B_I_DATA_FILE_H */