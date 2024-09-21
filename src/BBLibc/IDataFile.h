
#ifndef B_I_DATA_FILE_H

#define B_I_DATA_FILE_H

#include "array.h"
#include <bld_system.h>
#include "ParticleGType.h"
#include "Color.h"
#include "NamedObj.h"
#include "BitMap.h"
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
    long Length(void) const;
    long Seek(long offset, int whence);
    long Tell();
    unsigned char Peek();
    int Eof();
    void Read(void* data, unsigned int size);
    bool OK();
    char const* GetFileName() const;
    B_IDataFile& operator =(const B_IDataFile& other);
    static PyObject* OnOpenFunc;
private:
    unsigned int ReadCacheBlock();
    int fd;
    char* file_name;
    int file_size;
    char fileCache[16384];
    unsigned int cacheBlockBytesRead; // 400ch
    unsigned int cacheBlockPos; // 4010h
    unsigned int filePosition; // 4014h
    unsigned int cacheBlock; // 4018h
    someStruct_t* cacheBlockStruct; // 4020h
    unsigned int unknown;
    someStruct_t* unknown_struct;

    int n_opened_files_internal;
    static int n_opened_files;
    static int n_open_files;
    int SetPosition(long position);
};

LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, char& c);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, unsigned char& c);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, short& s);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, unsigned short& s);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, int& i);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, long& l);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, unsigned long& l);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, unsigned int& i);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, float& f);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, double& f);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_Name& name);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_NamedObj& named_obj);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_BitMap& bitMap);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_Color& color);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_BitMap24& bitMap);
LIB_EXP B_IDataFile& operator >>(B_IDataFile& file, B_ParticleGType& particleType);


#endif /* B_I_DATA_FILE_H */
