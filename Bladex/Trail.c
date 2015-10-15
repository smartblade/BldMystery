
#include "bladex_int.h"


typedef struct {
        PyObject_HEAD
        int trailID;
} bld_py_trail_t;


static void init_trail_type(void);
static void bld_py_trail_dealloc(PyObject *self);
static int bld_py_trail_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_trail_getattr(PyObject *self, char *attr_name);
static int bld_py_trail_setattr(PyObject *self, char *attr_name, PyObject *value);


static PyTypeObject trailTypeObject;

static PyMethodDef trail_methods[] = {
    { NULL,                             NULL,                               0,            NULL },
};


// address: 0x100189a0
PyObject *get_trail_type(const char *name) {
        bld_py_trail_t *trail_obj;
        int trailID;

        trailID = GetTrailByName(name);
        if (trailID < 0)
                return NULL;

        trail_obj = PyObject_NEW(bld_py_trail_t, &trailTypeObject);
        if (!trail_obj)
                return NULL;

        trail_obj->trailID = trailID;

        return (PyObject *)trail_obj;
}


// address: 0x100189fc
void init_trail() {
        init_trail_type();
}


// address: 0x10018a06
void init_trail_type() {

        memset(&trailTypeObject, 0, sizeof(PyTypeObject));

        trailTypeObject.ob_refcnt = 1;

        trailTypeObject.ob_type = &PyType_Type;
        trailTypeObject.ob_size = 0;
        trailTypeObject.tp_name = "B_PyTrail";
        trailTypeObject.tp_basicsize = sizeof(bld_py_trail_t);;
        trailTypeObject.tp_itemsize = 0;
        trailTypeObject.tp_dealloc = bld_py_trail_dealloc;
        trailTypeObject.tp_print = bld_py_trail_print;
        trailTypeObject.tp_getattr = bld_py_trail_getattr;
        trailTypeObject.tp_setattr = bld_py_trail_setattr;
        trailTypeObject.tp_compare = NULL;
        trailTypeObject.tp_repr = NULL;
        trailTypeObject.tp_as_number = NULL;
        trailTypeObject.tp_as_sequence = NULL;
        trailTypeObject.tp_as_mapping = NULL;
        trailTypeObject.tp_hash = NULL;
}


// address: 0x10018ab1
void bld_py_trail_dealloc(PyObject *self) {
        free(self);
}


// address: 0x10018ac3
int bld_py_trail_print(PyObject *self, FILE *file, int flags) {
        static char buffer[512];

        sprintf(buffer, "TrailType: %d", ((bld_py_trail_t *)self)->trailID);
        fprintf(file, buffer);

        return 0;
}


// address: 0x10018af6
PyObject *bld_py_trail_getattr(PyObject *self, char *attr_name)
{
        double time_2_live, transparency, shrink_factor;
        double r, g, b;
        PyObject *colorTuple, *rObj, *gObj, *bObj;
        char buffer[512];
        int code;

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Blah blah BLAH !!");

        if (!strcmp(attr_name, "Time2Live")) {
                code = GetTrailFloatProperty(
                        ((bld_py_trail_t *)self)->trailID, TRL_FLT_TIME_2_LIVE,
                        0, &time_2_live
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                return PyFloat_FromDouble(time_2_live);
        }

        if (!strcmp(attr_name, "Transparency")) {
                code = GetTrailFloatProperty(
                        ((bld_py_trail_t *)self)->trailID, TRL_FLT_TRANSPARENCY,
                        0, &transparency
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                return PyFloat_FromDouble(transparency);
        }

        if (!strcmp(attr_name, "ShrinkFactor")) {
                code = GetTrailFloatProperty(
                        ((bld_py_trail_t *)self)->trailID,
                        TRL_FLT_SHRINK_FACTOR, 0, &shrink_factor
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                return PyFloat_FromDouble(shrink_factor);
        }

        if (!strcmp(attr_name, "Color")) {
                code = GetTrailVectorProperty(
                        ((bld_py_trail_t *)self)->trailID, TRL_VEC_COLOR, 0,
                        &r, &g, &b
                );
                if (code != 1) {
                        if (code != -2) {
                                PyErr_SetString(PyExc_AttributeError, attr_name);
                        } else {
                                sprintf(buffer, "Unsupported %s", attr_name);
                                PyErr_SetString(PyExc_AttributeError, buffer);
                        }
                        return NULL;
                }

                colorTuple = PyTuple_New(3);

                rObj = PyFloat_FromDouble(r);
                gObj = PyFloat_FromDouble(g);
                bObj = PyFloat_FromDouble(b);

                PyTuple_SetItem(colorTuple, 0, rObj);
                PyTuple_SetItem(colorTuple, 1, gObj);
                PyTuple_SetItem(colorTuple, 2, bObj);

                return colorTuple;
        }

        return Py_FindMethod(trail_methods, self, attr_name);
}


// address: 0x10018d8e
int bld_py_trail_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        double time_2_live, transparency, shrink_factor;
        double r, g, b;
        int code;

        PyErr_Clear();
        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete Trail attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "Time2Live")) {
                if (!PyArg_Parse(value, "d", &time_2_live)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetTrailFloatProperty(
                        ((bld_py_trail_t *)self)->trailID, TRL_FLT_TIME_2_LIVE,
                        0, time_2_live
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Transparency")) {
                if (!PyArg_Parse(value, "d", &transparency)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetTrailFloatProperty(
                        ((bld_py_trail_t *)self)->trailID, TRL_FLT_TRANSPARENCY,
                        0, transparency
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "ShrinkFactor")) {
                if (!PyArg_Parse(value, "d", &shrink_factor)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetTrailFloatProperty(
                        ((bld_py_trail_t *)self)->trailID,
                        TRL_FLT_SHRINK_FACTOR, 0, shrink_factor
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Color")) {
                if (!PyArg_Parse(value, "(ddd)", &r, &g, &b)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetTrailVectorProperty(
                        ((bld_py_trail_t *)self)->trailID, TRL_VEC_COLOR, 0,
                        r, g, b
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

