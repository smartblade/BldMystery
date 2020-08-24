
#include "bladex_int.h"


static PyObject* bex_mat_AddHitSoundComb(PyObject* self, PyObject* args);
static void init_material_type(void);
static void bld_py_material_dealloc(PyObject *self);
static int bld_py_material_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_material_getattr(PyObject *self, char *attr_name);
static int bld_py_material_setattr(PyObject *self, char *attr_name, PyObject *value);


PyTypeObject materialTypeObject;


static PyMethodDef material_methods[] = {
    { "AddHitSoundComb",                bex_mat_AddHitSoundComb,            METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


/*
* Module:                 Bladex.dll
* Entry point:            0x10015A00
*/

PyObject *get_material_by_name(const char *name) {
        material_t *material;
        bld_py_material_t *material_obj;

        material = GetMaterial(name);
        if (!material)
                return NULL;

        material_obj = PyObject_NEW(bld_py_material_t, &materialTypeObject);
        if (!material_obj)
                return NULL;

        material_obj->material = material;

        return (PyObject *)material_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015A5C
*/

PyObject *get_material_by_index(int index) {
        material_t *material;
        bld_py_material_t *material_obj;

        material = GetMaterialI(index);
        if (!material)
                return NULL;

        material_obj = PyObject_NEW(bld_py_material_t, &materialTypeObject);
        if (!material_obj)
                return NULL;

        material_obj->material = material;

        return (PyObject *)material_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015AB8
*/

PyObject *create_material(const char *name) {
        material_t *material;
        bld_py_material_t *material_obj;

        material_obj = PyObject_NEW(bld_py_material_t, &materialTypeObject);
        if (!material_obj)
                return NULL;

        material = CreateMaterial(name);
        if (!material)
                return NULL;

        material_obj->material = material;
        return (PyObject *)material_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015B13
*/

PyObject *bex_mat_AddHitSoundComb(PyObject *self, PyObject *args) {
        bld_py_material_t *material = (bld_py_material_t *)self;
        material_t *material1, *material2;
        B_Sound *sound;
        const char *material_name;
        bld_py_sound_t *sound_obj;
        int code;

        if (!PyArg_ParseTuple(args, "sO", &material_name, &sound_obj)) {
                PyErr_SetString(PyExc_RuntimeError, "Invalid Params.");
                return Py_BuildValue("i", 0);
        }

        material1 = material->material;
        material2 = GetMaterial(material_name);
        sound = sound_obj->sound;

        code = AddHitSoundComb(material1, material2, sound);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015BC0
*/

void init_material() {
        init_material_type();
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015BCA
*/

void init_material_type() {

        memset(&materialTypeObject, 0, sizeof(PyTypeObject));

        materialTypeObject.ob_refcnt = 1;
        materialTypeObject.ob_type = &PyType_Type;
        materialTypeObject.ob_size = 0;
        materialTypeObject.tp_name = "B_PyMaterial";
        materialTypeObject.tp_basicsize = sizeof(bld_py_material_t);
        materialTypeObject.tp_itemsize = 0;
        materialTypeObject.tp_dealloc = bld_py_material_dealloc;
        materialTypeObject.tp_print = bld_py_material_print;
        materialTypeObject.tp_getattr = bld_py_material_getattr;
        materialTypeObject.tp_setattr = bld_py_material_setattr;
        materialTypeObject.tp_compare = NULL;
        materialTypeObject.tp_repr = NULL;
        materialTypeObject.tp_as_number = NULL;
        materialTypeObject.tp_as_sequence = NULL;
        materialTypeObject.tp_as_mapping = NULL;
        materialTypeObject.tp_hash = NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015C75
*/

void bld_py_material_dealloc(PyObject *self) {
        free(self);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015C87
*/

int bld_py_material_print(PyObject *self, FILE *file, int flags) {
        const char *name;
        int code;
        static char buffer[512] = "";

        code = GetMaterialStringProperty(
                ((bld_py_material_t *)self)->material, MAT_STR_NAME, 0, &name
        );
        if (code != 1) {
                fprintf(file, buffer);/*FIXME buffer could be uninitialised*/
        } else {
                sprintf(buffer, "Material:%s\n", name);
                fprintf(file, buffer);
        }
        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015CF1
*/

PyObject *bld_py_material_getattr(PyObject *self, char *attr_name)
{
        const char *name;
        B_Sound *break_sound, *friction_sound, *hit_sound;
        PyObject *break_sound_obj, *friction_sound_obj, *hit_sound_obj;
        double weight;
        int code;

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Material de Blade.");

        if (!strcmp(attr_name, "Name")) {
                code = GetMaterialStringProperty(
                        ((bld_py_material_t *)self)->material, MAT_STR_NAME, 0,
                        &name
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, name);/*FIXME should be attr_name*/
                        return NULL;
                }

                return PyString_FromString(name);
        }

        if (!strcmp(attr_name, "BreakSound")) {
                code = GetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_BREAK_SOUND, 0, &break_sound
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                break_sound_obj = create_sound_s(break_sound);
                if (break_sound_obj == NULL)
                        return PyString_FromString(
                                "Material has no BreakSound."
                        );

                return break_sound_obj;
        }

        if (!strcmp(attr_name, "FrictionSound")) {
                code = GetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_FRICTION_SOUND, 0, &friction_sound
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                friction_sound_obj = create_sound_s(friction_sound);
                if (friction_sound_obj == NULL)
                        return PyString_FromString(
                                "Material has no FrictionSound."
                        );
                return friction_sound_obj;
        }

        if (!strcmp(attr_name, "HitSound")) {
                code = GetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_HIT_SOUND, 0, &hit_sound
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                hit_sound_obj = create_sound_s(hit_sound);
                if (hit_sound_obj == NULL)
                        return PyString_FromString("Material has no HitSound.");

                return hit_sound_obj;
        }

        if (!strcmp(attr_name, "Weight")) {
                code = GetMaterialFloatProperty(
                        ((bld_py_material_t *)self)->material, MAT_FLT_WEIGHT,
                        0, &weight
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                return PyFloat_FromDouble(weight);
        }

        return Py_FindMethod(material_methods, self, attr_name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10015F7E
*/

int bld_py_material_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        bld_py_sound_t *break_sound, *friction_sound, *hit_sound;
        double weight;
        int code;

        PyErr_Clear();
        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError,
                        "can't delete Material attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "BreakSound")) {
                if (!PyArg_Parse(value, "O", &break_sound)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (break_sound->ob_type != &soundTypeObject) {
                        break_sound = NULL;
                } else if (break_sound->sound == NULL) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                        return -1;
                }

                code = SetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_BREAK_SOUND, 0, break_sound->sound
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "FrictionSound")) {
                if (!PyArg_Parse(value, "O", &friction_sound)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (friction_sound->ob_type != &soundTypeObject) {
                        friction_sound = NULL;
                } else if (friction_sound->sound == NULL) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                        return -1;
                }

                code = SetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_FRICTION_SOUND, 0, friction_sound->sound
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "HitSound" )) {
                if (!PyArg_Parse(value, "O", &hit_sound)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (hit_sound->ob_type != &soundTypeObject) {
                        hit_sound = NULL;
                } else if (hit_sound->sound == NULL) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                        return -1;
                }

                if (hit_sound == NULL) {
                        PyErr_SetString(
                                PyExc_AttributeError, "Error? obtaining sound."
                        );
                        return 0;/* FIXME should be -1*/
                }

                code = SetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_HIT_SOUND, 0, hit_sound->sound
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Weight")) {
                if (!PyArg_Parse(value, "d", &weight)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetMaterialFloatProperty(
                        ((bld_py_material_t *)self)->material, MAT_FLT_WEIGHT,
                        0, weight
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}

