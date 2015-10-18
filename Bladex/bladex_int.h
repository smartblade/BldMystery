
#ifdef __BORLANDC__

/*
 * Define MS_COREDLL for Borland C Builder to avoid crash after _PyObject_New
 * call
 */
#define MS_COREDLL

/*
 * Define USE_DL_IMPORT for Borland C Builder to avoid access violation
 * when writing to _Py_NoneStruct
 */
#define USE_DL_IMPORT

#endif


#include <Python.h>
#include <windows.h>
#include <assert.h>
#include <blade_ext.h>
#define BUILD_LIB
#include <export.h>


#define MAX_PROPERTY_KINDS                   1024


typedef struct {
	char *name;
	int kind;
	unsigned char data_type;
	unsigned char flags;
	PyObject *(*get_func)(PyObject *, char *);
	int (*set_func)(PyObject *, char *, PyObject *);
} property_info_t ;

extern property_info_t *property_kinds;


extern PyObject *get_char_by_name(const char *name, const char *short_name);
extern void init_char(void);

extern void init_entity_properties(void);

extern PyObject *get_trail_type(const char *name);
extern void init_trail(void);

extern void perform_heap_check(void);
extern int heap_check_set_mark(void);
extern void heap_check_all_allocations(int i);
extern void heap_check_delay_free(int i);
extern void heap_check_system_memory(int i);
extern void heap_check_leaks(int i);
extern int dump_memory_leaks(const char *s);

extern int insert_property(
        const char *name, int property_kind, int data_type, int flags,
        PyObject *(*get_func)(PyObject *, char *),
        int (*set_func)(PyObject *, char *, PyObject *)
);
extern int find_property(property_info_t *properties, const char *name);
