
#include "bladex_int.h"


static PyObject* bex_route_AddPoint(PyObject* self, PyObject* args);
static void init_route_type(void);
static void bld_py_route_dealloc(PyObject *self);
static int bld_py_route_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_route_getattr(PyObject *self, char *attr_name);
static int bld_py_route_setattr(PyObject *self, char *attr_name, PyObject *value);


PyTypeObject routeTypeObject;


static PyMethodDef route_methods[] = {
    { "AddPoint",                       bex_route_AddPoint,                 METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


/*
* Module:                 Bladex.dll
* Entry point:            0x10016310
*/

PyObject *create_route() {
        bld_py_route_t *route_obj;

        route_obj = PyObject_NEW(bld_py_route_t, &routeTypeObject);
        if (route_obj == NULL)
                return NULL;

        return (PyObject *)route_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016346
*/

PyObject *bex_route_AddPoint(PyObject *self, PyObject *args) {
        double x, y, z;

        if (self == NULL)
                return NULL;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016396
*/

void init_route() {
        init_route_type();
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100163A0
*/

void init_route_type() {
        memset(&routeTypeObject, 0, sizeof(PyTypeObject));

        routeTypeObject.ob_refcnt = 1;
        routeTypeObject.ob_type = &PyType_Type;
        routeTypeObject.ob_size = 0;
        routeTypeObject.tp_name = "B_PyRoute";
        routeTypeObject.tp_basicsize = sizeof(bld_py_route_t);
        routeTypeObject.tp_itemsize = 0;
        routeTypeObject.tp_dealloc = bld_py_route_dealloc;
        routeTypeObject.tp_print = bld_py_route_print;
        routeTypeObject.tp_getattr = bld_py_route_getattr;
        routeTypeObject.tp_setattr = bld_py_route_setattr;
        routeTypeObject.tp_compare = NULL;
        routeTypeObject.tp_repr = NULL;
        routeTypeObject.tp_as_number = NULL;
        routeTypeObject.tp_as_sequence = NULL;
        routeTypeObject.tp_as_mapping = NULL;
        routeTypeObject.tp_hash = NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001644B
*/

void bld_py_route_dealloc(PyObject *self) {
        free(self);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001645D
*/

int bld_py_route_print(PyObject *self, FILE *file, int flags) {
        char buffer[128];

        sprintf(buffer, "B_Route: %d", 0);
        fprintf(file, buffer);

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016491
*/

PyObject *bld_py_route_getattr(PyObject *self, char *attr_name) {

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Objeto ruta de Blade.");

        return Py_FindMethod(route_methods, self, attr_name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100164D3
*/

int bld_py_route_setattr(PyObject *self, char *attr_name, PyObject *value) {

        PyErr_Clear();
        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete route attributes"
                );
                return -1;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}

