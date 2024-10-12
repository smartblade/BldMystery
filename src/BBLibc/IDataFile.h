
#ifndef B_I_DATA_FILE_H

#define B_I_DATA_FILE_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


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


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100021E0
    * VC++ mangling:          ?OK@B_IDataFile@@QBEIXZ
    */

    unsigned int OK() const
    {
        return fd != -1;
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002200
    * VC++ mangling:          ?GetFileName@B_IDataFile@@QBEPBDXZ
    */

    char const* GetFileName() const
    {
        return this->file_name;
    }

    B_IDataFile& operator =(const B_IDataFile& other);
private:
    unsigned int ReadCacheBlock();
    int fd;
    char* file_name;
    unsigned int file_size;
    char fileCache[0x4000];
    unsigned int cacheBlockBytesRead;
    unsigned int cacheBlockPos;
    unsigned int filePosition;

    static int n_opened_files;
    static int n_open_files;
    static PyObject* OnOpenFunc;
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


#endif /* B_I_DATA_FILE_H */
