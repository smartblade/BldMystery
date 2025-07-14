
#ifndef B_NAME_H

#define B_NAME_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class B_IDataFile;
class B_ODataFile;

class LIB_EXP B_Name
{
public:
    B_Name();
    B_Name(const char *str);
    B_Name(const B_Name &src);
    B_Name(unsigned int len);
    ~B_Name();
    char * const String() const;
    unsigned int CompareNoCase(const char *str) const;
    B_Name Right(unsigned int count) const;
    B_Name Left(unsigned int count) const;

    unsigned int operator >(const B_Name &rhs) const;
    unsigned int operator <(const B_Name &rhs) const;
    unsigned int operator ==(const B_Name &rhs) const;
    unsigned int operator ==(const char *str) const;
    unsigned int operator !=(const B_Name &rhs) const;
    unsigned int operator !=(const char *str) const;
    B_Name &operator =(const B_Name &src);
    const B_Name &operator +=(const char *str);
    const B_Name &operator +=(char c);
    B_Name const &operator +=(B_Name const &other);

    B_Name const &operator +(const char *str);


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100022C0
    * VC++ mangling:          ?Id@B_Name@@QBEABV1@XZ
    */

    const B_Name &Id() const
    {
        return *this;
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100022D0
    * VC++ mangling:          ??BB_Name@@QBEPBDXZ
    */

    operator const char *() const
    {
        return string;
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100022E0
    * VC++ mangling:          ?Length@B_Name@@QBEIXZ
    */

    unsigned int Length() const
    {
        return this->len;
    }

    void UpCase();
private:
    char *string;
    unsigned int len;
};

LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_Name &name);
LIB_EXP B_ODataFile &operator <<(B_ODataFile &file, B_Name const &name);
LIB_EXP B_Name operator +(B_Name const &lother, B_Name const &rother);
LIB_EXP B_Name operator +(B_Name const &other, const char *str);
LIB_EXP B_Name operator +(const char *str, const B_Name &bName);

#endif /* B_NAME_H */
