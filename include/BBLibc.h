
#ifndef BBLIBC_H

#define BBLIBC_H

#include <fcntl.h>
#include <export.h>
#include <array.h>


class LIB_EXP B_Color {
public:
        virtual void MakeCons();
private:
        byte r, g, b;
};


class LIB_EXP B_Name
{
public:
        B_Name();
        B_Name(const char* str);
        ~B_Name();
        B_Name &operator =(const B_Name &src);
        unsigned int operator ==(const char *str) const;
        unsigned int operator ==(const B_Name &str) const;
        operator const char *() const { return string; }
        char * const String() const;
private:
        char *string;
        int len;
};


class LIB_EXP B_NamedObj
{
public:
        virtual ~B_NamedObj();
        const B_Name &Id() const;
public:
        B_Name name;
};

struct B_ParticleElement
{
public:
    byte r;
    byte g;
    byte b;
    byte alpha;
    float size;
};

class B_ParticleGType : public B_NamedObj
{
public:
    virtual ~B_ParticleGType();
    B_ParticleGType() : bmp_handle(-1), operation_type(0)
    {
    }
    B_ParticleGType(
        const B_Name &new_type, const B_Name &parent_type,
        unsigned long operation_type, unsigned int duration);
public:
    array_t<B_ParticleElement> a00C;
    int bmp_handle;
    int operation_type;
};


class LIB_EXP B_MessageManager
{
};

LIB_EXP B_MessageManager &operator <<(B_MessageManager &mout, const char *str);

LIB_EXP B_MessageManager mout;


const char *vararg(const char *format, ...);


class LIB_EXP B_IDataFile
{
public:
        B_IDataFile(const char *file_name, int flags);
        ~B_IDataFile();
        unsigned int OK() const { return fd != -1;}

private:
        int fd;
        char *file_name;
        int file_size;
        char unknown_fields[16396];
};

LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, unsigned int &i);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, unsigned long &i);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, float &f);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_NamedObj &named_obj);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_Color &color);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_ParticleGType &particleType);


class LIB_EXP B_ODataFile
{
public:
        B_ODataFile(const char *file_name, int flags);
        ~B_ODataFile();
        unsigned int OK() const { return fd != -1;}

private:
        int fd;
        char *file_name;
        char unknown_fields[16392];
};

LIB_EXP B_ODataFile &operator <<(B_ODataFile &file, const unsigned int &i);
LIB_EXP B_ODataFile &operator <<(B_ODataFile &file, const B_ParticleGType &particleType);


struct B_ElementCSV : public B_NamedObj
{
    virtual ~B_ElementCSV();
    float mass;
    B_Name material;
};

template<class T> class B_NDataBase : public array_t<T*>
{
};

LIB_EXP B_NDataBase<B_ElementCSV> B_csvs;

LIB_EXP unsigned int ReadCSV(const char *file_name, B_NDataBase<B_ElementCSV> *csvs);

class LIB_EXP B_BitMap24
{
public:
    virtual ~B_BitMap24();

    unsigned int dimension1;
    unsigned int dimension2;
    void *data;
};

class LIB_EXP B_Pal
{
};

class LIB_EXP B_BitMap
{
public:
    enum BitMapType
    {
        BitMapType2 = 2,
        BitMapType4 = 4,
    };
    virtual ~B_BitMap();
    B_BitMap(const B_BitMap &src);
    B_BitMap(BitMapType type, unsigned int, unsigned int, const B_Pal *pal);

    BitMapType type;
    unsigned int dimension1;
    unsigned int dimension2;
    void *data;
    B_Pal *pal;
};

class LIB_EXP B_Resource : public B_NamedObj
{
public:
    void *data;
};

class LIB_EXP B_ResourceManager
{
public:
    B_Resource *GetResource(unsigned short type, const B_Name &name);
    void FreeResource(B_Resource *resource);
    unsigned int LocateResourceIn(const B_Name &id, const B_Name *, int );
};

LIB_EXP B_ResourceManager B_resource_manager;

LIB_EXP int CheckErrors;

#endif /* BBLIBC_H */
