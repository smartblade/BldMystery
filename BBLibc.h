
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

extern void BBlibc_name_set(BBLibc_name_t *self, char *string);
extern void BBlibc_name_clear(BBLibc_name_t *self);
extern void BBlibc_name_copy(BBLibc_name_t *self, BBLibc_name_t *name);

#endif

#endif /* BBLIBC_H */
