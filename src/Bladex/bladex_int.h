
#ifndef BLADEX_INT_H

#define BLADEX_INT_H

#include <bld_system.h>
#include <bld_python.h>
#include <blade_ext.h>
#define BUILD_LIB
#include <export.h>


#define MAX_PROPERTY_KINDS                   1024

typedef struct _B_Sound B_Sound;

typedef struct {
        PyObject_HEAD
        int charID;
} bld_py_char_t;

typedef struct {
        PyObject_HEAD
        char *name;
} bld_py_entity_t;

typedef struct {
        PyObject_HEAD
        char *name;
} bld_py_inventory_t;

typedef struct {
        PyObject_HEAD
        material_t *material;
} bld_py_material_t;

typedef struct {
        PyObject_HEAD
        void *unknown;
} bld_py_route_t;

typedef struct {
        PyObject_HEAD
        int sectorID;
} bld_py_sector_t;

typedef struct {
        PyObject_HEAD
        B_Sound *sound;
        int soundDev;
} bld_py_sound_t;

typedef struct {
        PyObject_HEAD
        int trailID;
} bld_py_trail_t;

typedef struct {
	char *name;
	int kind;
	unsigned char data_type;
	unsigned char flags;
	PyObject *(*get_func)(PyObject *, char *);
	int (*set_func)(PyObject *, char *, PyObject *);
} property_info_t ;

extern property_info_t *property_kinds;

extern PyTypeObject charTypeObject;
extern PyTypeObject entityTypeObject;
extern PyTypeObject inventoryTypeObject;
extern PyTypeObject materialTypeObject;
extern PyTypeObject routeTypeObject;
extern PyTypeObject sectorTypeObject;
extern PyTypeObject soundTypeObject;
extern PyTypeObject trailTypeObject;


LIB_EXP INIT_PY_MODULE_FUNC initBladex(void);


extern PyObject *get_char_by_name(const char *name, const char *short_name);
extern void init_char(void);

extern PyObject *get_entity_by_name(const char *name);
extern PyObject *get_entity_by_index(int index);
extern PyObject *create_entity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
);
extern PyObject *create_entity_decal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
);
extern PyObject *create_spark(
        const char *name, double x, double y, double z, double x_spark_dir,
        double y_spark_dir, double z_spark_dir, double d_unknown1,
        double d_unknown2, double d_unknown3, double d_unknown4,
        double d_unknown5, int i_unknown6, int i_unknown7, int i_unknown8,
        int i_unknown9, int i_unknown10, int i_unknown11, double d_unknown12,
        double d_unknown13, double d_unknown14, int i_unknown15
);
extern void init_entity_properties(void);
extern void init_entity(void);

extern PyObject *get_inventory(const char *name);
extern void init_inventory(void);

extern PyObject *get_material_by_name(const char *name);
extern PyObject *get_material_by_index(int index);
extern PyObject *create_material(const char *name);
extern void init_material(void);

extern PyObject *create_route(void);
extern void init_route(void);

extern PyObject* get_sector_by_index(int index);
extern PyObject* get_sector_by_position(double x, double y, double z);
extern void init_sector(void);

extern PyObject *create_sound(const char *file_name, const char *sound_name);
extern PyObject *create_sound_s(B_Sound *sound);
extern PyObject *get_ghost_sector_sound(const char *gs_name);
extern void init_sound(void);

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

#endif /* BLADEX_INT_H */
