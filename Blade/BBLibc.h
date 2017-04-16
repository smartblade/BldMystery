
#ifndef BBLIBC_H

#define BBLIBC_H

#include <fcntl.h>
#include <export.h>


typedef struct {
        void *methods;
        byte r, g, b;
} BBLibc_color_t;

typedef struct {
        char *string;
        int len;
} BBLibc_name_t;

typedef struct {
        void *methods;
        BBLibc_name_t name;
} BBLibc_named_object_t;


#ifdef __cplusplus


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
private:
        char *string;
        int len;
};


class LIB_EXP B_NamedObj
{
public:
        virtual ~B_NamedObj();
private:
        B_Name name;
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

public:
        int fd;
private:
        char *file_name;
        int file_size;
        char unknown_fields[16396];
};

LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, unsigned int &i);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, float &f);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_NamedObj &named_obj);
LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_Color &color);


#endif


#ifndef BLD_EXT_FUNCS

extern void BBlibc_name_set(BBLibc_name_t *self, const char *string);
extern void BBlibc_name_clear(BBLibc_name_t *self);
extern void BBlibc_name_copy(BBLibc_name_t *self, BBLibc_name_t *name);
extern char *BBlibc_name_string(BBLibc_name_t *self);
extern int BBlibc_name_is_equal_string(BBLibc_name_t *self, const char *string);

extern BBLibc_name_t *BBLibc_named_object_id(BBLibc_named_object_t *self);

#endif

#endif /* BBLIBC_H */
