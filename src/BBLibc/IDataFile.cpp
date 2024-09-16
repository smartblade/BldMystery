#include <string>
#include <fcntl.h>
#include <io.h>
#include <cstdint>
#include <bld_python.h>
#define BBLIBC_LIB_EXPORT
#include "IDataFile.h"
#include "BitMap24.h"


LIB_EXP int B_IDataFile::n_open_files = 0;
LIB_EXP int B_IDataFile::n_opened_files = 0;
LIB_EXP PyObject* B_IDataFile::OnOpenFunc;


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001740
* VC++ mangling:          ??0B_IDataFile@@QAE@XZ
*/

B_IDataFile::B_IDataFile()
{
    // TODO Implement
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001788
* VC++ mangling:          ??0B_IDataFile@@QAE@PBDH@Z
*/

B_IDataFile::B_IDataFile(const char* file_name, int flags)
{
    // TODO Implement
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C31
* VC++ mangling:          ??1B_IDataFile@@QAE@XZ
*/

B_IDataFile::~B_IDataFile() {
    Close();
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001000
* VC++ mangling:          ?ResetnOpenedFiles@B_IDataFile@@SAXXZ
*/

void B_IDataFile::ResetnOpenedFiles() {
    B_IDataFile::n_opened_files = 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000100F
* VC++ mangling:          ?GetnOpenedFiles@B_IDataFile@@SAHXZ
*/

int B_IDataFile::GetnOpenedFiles() {
    return B_IDataFile::n_opened_files;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001019
* VC++ mangling:          ?GetnOpenFiles@B_IDataFile@@SAHXZ
*/

int B_IDataFile::GetnOpenFiles() {
    return B_IDataFile::n_open_files;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001023
* VC++ mangling:          ?SetOnOpenFunc@B_IDataFile@@SAHPAUPyObject@@@Z
*/

int B_IDataFile::SetOnOpenFunc(PyObject* obj) {
    // TODO Implement
    if (!obj) {
        return 0; // input is null, do nothing
    }

    //if (OnOpenFunc) {
        // decrement reference count of current OnOpenFunc object
        //Py_XDECREF(OnOpenFunc);

    Py_DECREF(OnOpenFunc);

    Py_XINCREF(obj);
    OnOpenFunc = obj;
    return 1; // success
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001096
* VC++ mangling:          ?RemoveOnOpenFunc@B_IDataFile@@SAXXZ
*/

void B_IDataFile::RemoveOnOpenFunc() {
    // TODO Implement
    OnOpenFunc = nullptr; // set to null
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100015E2
* VC++ mangling:          ?Open@B_IDataFile@@QAEXPBDH@Z
*/

void B_IDataFile::Open(const char* src, int flags) {
    // TODO Implement
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100017C2
* VC++ mangling:          ?ReadCacheBlock@B_IDataFile@@AAEIXZ
*/

unsigned int B_IDataFile::ReadCacheBlock() {
    // TODO Implement
    return 1; // success
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100014D2
* VC++ mangling:          ?Close@B_IDataFile@@QAEXXZ
*/

void B_IDataFile::Close() {
    // TODO Implement
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002200
* VC++ mangling:          ?GetFileName@B_IDataFile@@QBEPBDXZ
*/

char const* B_IDataFile::GetFileName() const  {
    return this->file_name;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001882
* VC++ mangling:          ?Length@B_IDataFile@@QBEJXZ
*/

long B_IDataFile::Length(void) const {
    if (fd != -1) {
        return file_size;
    }

    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100018A6
* VC++ mangling:          ?Seek@B_IDataFile@@QAEJJH@Z
*/

long B_IDataFile::Seek(long offset, int whence) {
    // TODO Implement
    return 0;

}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100019AF
* VC++ mangling:          ?Tell@B_IDataFile@@QAEJXZ
*/

long B_IDataFile::Tell() {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100019CC
* VC++ mangling:          ?Peek@B_IDataFile@@QAEEXZ
*/

unsigned char B_IDataFile::Peek() {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001A0D
* VC++ mangling:          ?Eof@B_IDataFile@@QAEHXZ
*/

int B_IDataFile::Eof() {
    unsigned int curPos = filePosition + cacheBlockFlag->filePosition;
    return curPos >= this->file_size ? 1 : 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001A33
* VC++ mangling:          ?Read@B_IDataFile@@QAEXPAXI@Z
*/

void B_IDataFile::Read(void* data, unsigned int size)
{
    // TODO implement reading data from the file
    _read(fd, data, size);
    // handle error
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BEF
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAI@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, unsigned int& i)
{
    file.Read(&i, sizeof(unsigned int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BD9
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAK@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, unsigned long& i)
{
    file.Read(&i, sizeof(unsigned long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C05
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAM@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, float& f)
{
    file.Read(&f, sizeof(float));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C1B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAN@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, double& f)
{
    file.Read(&f, sizeof(double));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003904
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Name@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_Name& name)
{
    // TODO implement reading B_Name from file
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A40
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_NamedObj@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_NamedObj& named_obj)
{
    // TODO implement reading B_NamedObj from file
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100091A4
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Color@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_Color& color)
{
    // TODO implement reading B_Color from file
    return file;
}

/*
* Module:                 BBLibc.dll
* Entry point:            0x1004122B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_ParticleGType@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_ParticleGType& particleType)
{
    // TODO implement reading B_ParticleGType from file
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10028021
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_BitMap24@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_BitMap24& bitMap) {
    // TODO implement
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B81
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAF@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, short& c) {
    // TODO implement
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B6B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAE@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, unsigned char& c) {
    // TODO implement
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BAD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAH@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, int& i) {
    // TODO implement
    return file;
}

LIB_EXP PyObject* CallPythonObject(PyObject* func, PyObject* args) {
    // TODO implement
    PyObject* result = nullptr;

    return result;
}
