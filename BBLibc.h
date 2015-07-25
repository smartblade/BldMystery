
#ifndef BBLIBC_H

#define BBLIBC_H



typedef struct {
        char *string;
        int len;
} BBLibc_name_t;

typedef struct {
        void *methods;
        BBLibc_name_t name;
} BBLibc_named_object_t;


#ifndef BLD_EXT_FUNCS

extern void BBlibc_name_set(BBLibc_name_t *self, const char *string);
extern void BBlibc_name_clear(BBLibc_name_t *self);
extern void BBlibc_name_copy(BBLibc_name_t *self, BBLibc_name_t *name);
extern char *BBlibc_name_string(BBLibc_name_t *self);
extern int BBlibc_name_is_equal_string(BBLibc_name_t *self, const char *string);

extern BBLibc_name_t *BBLibc_named_object_id(BBLibc_named_object_t *self);

#endif

#endif /* BBLIBC_H */
