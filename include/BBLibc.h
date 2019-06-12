
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
private:
        B_Name name;
};

class B_ParticleGType : public B_NamedObj
{
public:
    virtual ~B_ParticleGType();
    B_ParticleGType() : unknown0024(-1), unknown0028(0)
    {
    }
private:
    array_t<double> a00C;
    int unknown0024;
    int unknown0028;
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


struct B_ElementCSV
{
};

template<class T> class B_NDataBase
{
};

LIB_EXP B_NDataBase<B_ElementCSV> B_csvs;

LIB_EXP unsigned int ReadCSV(const char *file_name, B_NDataBase<B_ElementCSV> *csvs);

class LIB_EXP B_ResourceManager
{
public:
        unsigned int LocateResourceIn(const B_Name &id, const B_Name *, int );
};

LIB_EXP B_ResourceManager B_resource_manager;

#endif /* BBLIBC_H */
