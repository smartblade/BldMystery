
#ifndef B_NAME_H

#define B_NAME_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_Name
{
public:
    B_Name();
    B_Name(const char* str);
    B_Name(const B_Name& src);
    B_Name(unsigned int len);

    ~B_Name();
    unsigned int CompareNoCase(const char* str) const;
    B_Name& operator =(const B_Name& src);
    unsigned int operator !=(const char* str) const;
    operator const char* () const { return string; }
    unsigned int Length() const { return len; }

    unsigned int operator ==(const char* str) const;
    unsigned int operator ==(const B_Name& rhs) const;
    unsigned int operator !=(const B_Name& rhs) const;
    unsigned int operator >(const B_Name& rhs) const;
    unsigned int operator <(const B_Name& rhs) const;
    const B_Name& operator +=(const char* str);
    const B_Name& operator +=(char c);
    B_Name const& operator+=(B_Name const& other);
    B_Name const& operator +(char const* str);

    const B_Name& Id() const {
        return *this;
    }
   
    char* const String() const;
    
    B_Name Left(unsigned int count) const;
    B_Name Right(unsigned int count) const;
    void UpCase();
private:
    char* string;
    unsigned int len;
};

LIB_EXP B_Name operator+(const char* str, const B_Name& bName);
//LIB_EXP int operator +(class B_Name* other, int i);
//LIB_EXP int operator +(char const* str, B_Name const& other);
//LIB_EXP B_Name operator+(class B_Name const& other, char const* str);
LIB_EXP B_Name operator+(class B_Name const& other, char const* str);
LIB_EXP B_Name operator+(B_Name const& lother, B_Name const& rother);

#endif /* B_NAME_H */