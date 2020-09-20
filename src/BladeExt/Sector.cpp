
#include "bladex_int.h"
#include <BWorld/SectorFuncs.h>


static PyObject* bex_sec_InitBreak(PyObject* self, PyObject* args);
static PyObject* bex_sec_DoBreak(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTexture(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureZoomX(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureZoomY(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureX(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureY(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTexture(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureZoomX(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureZoomY(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureX(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureY(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSpecularLight(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSpecularLight(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSpecularShininess(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSpecularShininess(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSelfLight(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSelfLight(PyObject* self, PyObject* args);
static void init_sector_type(void);
static void bld_py_sector_dealloc(PyObject *self);
static int bld_py_sector_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_sector_getattr(PyObject *self, char *attr_name);
static int bld_py_sector_setattr(PyObject *self, char *attr_name, PyObject *value);


PyTypeObject sectorTypeObject;


static PyMethodDef sector_methods[] = {
    { "InitBreak",                      bex_sec_InitBreak,                  METH_VARARGS, NULL },
    { "DoBreak",                        bex_sec_DoBreak,                    METH_VARARGS, NULL },
    { "SetSurfaceTexture",              bex_sec_SetSurfaceTexture,          METH_VARARGS, NULL },
    { "GetSurfaceTexture",              bex_sec_GetSurfaceTexture,          METH_VARARGS, NULL },
    { "SetSurfaceTextureZoomX",         bex_sec_SetSurfaceTextureZoomX,     METH_VARARGS, NULL },
    { "GetSurfaceTextureZoomX",         bex_sec_GetSurfaceTextureZoomX,     METH_VARARGS, NULL },
    { "SetSurfaceTextureZoomY",         bex_sec_SetSurfaceTextureZoomY,     METH_VARARGS, NULL },
    { "GetSurfaceTextureZoomY",         bex_sec_GetSurfaceTextureZoomY,     METH_VARARGS, NULL },
    { "SetSurfaceTextureX",             bex_sec_SetSurfaceTextureX,         METH_VARARGS, NULL },
    { "GetSurfaceTextureX",             bex_sec_GetSurfaceTextureX,         METH_VARARGS, NULL },
    { "SetSurfaceTextureY",             bex_sec_SetSurfaceTextureY,         METH_VARARGS, NULL },
    { "GetSurfaceTextureY",             bex_sec_GetSurfaceTextureY,         METH_VARARGS, NULL },
    { "GetSpecularLight",               bex_sec_GetSpecularLight,           METH_VARARGS, NULL },
    { "SetSpecularLight",               bex_sec_SetSpecularLight,           METH_VARARGS, NULL },
    { "GetSpecularShininess",           bex_sec_GetSpecularShininess,       METH_VARARGS, NULL },
    { "SetSpecularShininess",           bex_sec_SetSpecularShininess,       METH_VARARGS, NULL },
    { "GetSelfLight",                   bex_sec_GetSelfLight,               METH_VARARGS, NULL },
    { "SetSelfLight",                   bex_sec_SetSelfLight,               METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


/*
* Module:                 Bladex.dll
* Entry point:            0x10016520
*/

PyObject *get_sector_by_index(int index) {
        int sectorID;
        bld_py_sector_t *sector_obj;

        sectorID = GetSectorByIndex(index);
        if (sectorID >= 0) {
                sector_obj = PyObject_NEW(bld_py_sector_t, &sectorTypeObject);
                if (sector_obj != NULL) {
                        sector_obj->sectorID = sectorID;
                        return (PyObject *)sector_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1001657C
*/

PyObject *get_sector_by_position(double x, double y, double z) {
        int index;

        index = GetSectorByPosition(x, y, z);

        return get_sector_by_index(index);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100165B4
*/

PyObject *bex_sec_InitBreak(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        double x_vec1, y_vec1, z_vec1, x_vec2, y_vec2, z_vec2, x_vec3, y_vec3, z_vec3;
        const char *s_unknown = "";
        double d_unknown = 100.0;
        int i_unknown = 1;

        if (!PyArg_ParseTuple(
                args, "(ddd)(ddd)(ddd)|sdi", &x_vec1, &y_vec1, &z_vec1, &x_vec2,
                &y_vec2, &z_vec2, &x_vec3, &y_vec3, &z_vec3, &s_unknown,
                &d_unknown, &i_unknown
        ))
                return NULL;

        code = InitBreakSector(
                sector->sectorID, x_vec1, y_vec1, z_vec1, x_vec2, y_vec2,
                z_vec2, x_vec3, y_vec3, z_vec3, s_unknown, d_unknown, i_unknown
        );
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100166C0
*/

PyObject *bex_sec_DoBreak(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        double x_impulse, y_impulse, z_impulse, x, y, z;
        double x_unknown, y_unknown, z_unknown;

        if (!PyArg_ParseTuple(
                args, "(ddd)(ddd)(ddd)", &x_impulse, &y_impulse, &z_impulse,
                &x, &y, &z, &x_unknown, &y_unknown, &z_unknown
        ))
                return NULL;

        code = DoBreakSector(
                sector->sectorID, x_impulse, y_impulse, z_impulse, x, y, z,
                x_unknown, y_unknown, z_unknown
        );
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016794
*/

PyObject *bex_sec_SetSurfaceTexture(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        const char *texture;

        if (!PyArg_ParseTuple(args, "is", &surface_index, &texture))
                return NULL;

        code = SetSectorStringProperty(
                sector->sectorID, SEC_STR_TEXTURE, surface_index, texture
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001680B
*/

PyObject *bex_sec_SetSurfaceTextureZoomX(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double zoom_x;

        if (!PyArg_ParseTuple(args, "id", &surface_index, &zoom_x))
                return NULL;

        code = SetSectorFloatProperty(
                sector->sectorID, SEC_FLT_TEXTURE_ZOOM_X, surface_index, zoom_x
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016886
*/

PyObject *bex_sec_SetSurfaceTextureZoomY(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double zoom_y;

        if (!PyArg_ParseTuple(args, "id", &surface_index, &zoom_y))
                return NULL;

        code = SetSectorFloatProperty(
                sector->sectorID, SEC_FLT_TEXTURE_ZOOM_Y, surface_index, zoom_y
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016901
*/

PyObject *bex_sec_SetSurfaceTextureX(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double texture_x;

        if (!PyArg_ParseTuple(args, "id", &surface_index, &texture_x))
                return NULL;

        code = SetSectorFloatProperty(
                sector->sectorID, SEC_FLT_TEXTURE_X, surface_index, texture_x
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001697C
*/

PyObject *bex_sec_SetSurfaceTextureY(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double texture_y;

        if (!PyArg_ParseTuple(args, "id", &surface_index, &texture_y))
                return NULL;

        code = SetSectorFloatProperty(
                sector->sectorID, SEC_FLT_TEXTURE_Y, surface_index, texture_y
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100169F7
*/

PyObject *bex_sec_GetSurfaceTexture(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        const char *texture;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorStringProperty(
                sector->sectorID, SEC_STR_TEXTURE, surface_index, &texture
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture");
                return NULL;
        }

        return PyString_FromString(texture);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016A70
*/

PyObject *bex_sec_GetSurfaceTextureZoomX(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double zoom_x;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorFloatProperty(
                sector->sectorID, SEC_FLT_TEXTURE_ZOOM_X, surface_index, &zoom_x
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture Zoom X");
                return NULL;
        }

        return PyFloat_FromDouble(zoom_x);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016AEC
*/

PyObject *bex_sec_GetSurfaceTextureZoomY(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double zoom_y;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorFloatProperty(
                sector->sectorID, SEC_FLT_TEXTURE_ZOOM_Y, surface_index, &zoom_y
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture ZoomY");
                return NULL;
        }

        return PyFloat_FromDouble(zoom_y);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016B68
*/

PyObject *bex_sec_GetSurfaceTextureX(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double texture_x;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorFloatProperty(
                sector->sectorID, SEC_FLT_TEXTURE_X, surface_index, &texture_x
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture X");
                return NULL;
        }

        return PyFloat_FromDouble(texture_x);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016BE4
*/

PyObject *bex_sec_GetSurfaceTextureY(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double texture_y;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorFloatProperty(
                sector->sectorID, 0, surface_index, &texture_y
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture Y");
                return NULL;
        }

        return PyFloat_FromDouble(texture_y);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016C60
*/

PyObject *bex_sec_SetSpecularLight(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double specular_light;

        /*FIXME second parameter should be double*/
        if (!PyArg_ParseTuple(args, "is", &surface_index, &specular_light))
                return NULL;

        code = SetSectorFloatProperty(
                sector->sectorID, SEC_FLT_SPECULAR_LIGHT, surface_index,
                specular_light
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016CDB
*/

PyObject *bex_sec_GetSpecularLight(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double specular_light;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorFloatProperty(
                sector->sectorID, SEC_FLT_SPECULAR_LIGHT, surface_index,
                &specular_light
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture Zoom");
                return NULL;
        }

        return PyFloat_FromDouble(specular_light);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016D57
*/

PyObject *bex_sec_SetSpecularShininess(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double specular_shininess;

        /*FIXME second parameter should be double*/
        if (!PyArg_ParseTuple(args, "is", &surface_index, &specular_shininess))
                return NULL;

        code = SetSectorFloatProperty(
                sector->sectorID, SEC_FLT_SPECULAR_SHININESS, surface_index,
                specular_shininess
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016DD2
*/

PyObject *bex_sec_GetSpecularShininess(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double specular_shininess;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorFloatProperty(
                sector->sectorID, SEC_FLT_SPECULAR_SHININESS, surface_index,
                &specular_shininess
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture Zoom");
                return NULL;
        }

        return PyFloat_FromDouble(specular_shininess);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016E4E
*/

PyObject *bex_sec_SetSelfLight(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double self_light;

        /*FIXME second parameter should be double*/
        if (!PyArg_ParseTuple(args, "is", &surface_index, &self_light))
                return NULL;

        code = SetSectorFloatProperty(
                sector->sectorID, SEC_FLT_SELF_LIGHT, surface_index, self_light
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016EC9
*/

PyObject *bex_sec_GetSelfLight(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        int surface_index;
        double self_light;

        if (!PyArg_ParseTuple(args, "i", &surface_index))
                return NULL;

        code = GetSectorFloatProperty(
                sector->sectorID, SEC_FLT_SELF_LIGHT, surface_index, &self_light
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Sector Texture Zoom");
                return NULL;
        }

        return PyFloat_FromDouble(self_light);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016F45
*/

void init_sector() {
        init_sector_type();
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016F4F
*/

void init_sector_type() {

        memset(&sectorTypeObject, 0, sizeof(PyTypeObject));

        sectorTypeObject.ob_refcnt = 1;
        sectorTypeObject.ob_type = &PyType_Type;
        sectorTypeObject.ob_size = 0;
        sectorTypeObject.tp_name = "B_PySector";
        sectorTypeObject.tp_basicsize = sizeof(bld_py_sector_t);
        sectorTypeObject.tp_itemsize = 0;
        sectorTypeObject.tp_dealloc = bld_py_sector_dealloc;
        sectorTypeObject.tp_print = bld_py_sector_print;
        sectorTypeObject.tp_getattr = bld_py_sector_getattr;
        sectorTypeObject.tp_setattr = bld_py_sector_setattr;
        sectorTypeObject.tp_compare = NULL;
        sectorTypeObject.tp_repr = NULL;
        sectorTypeObject.tp_as_number = NULL;
        sectorTypeObject.tp_as_sequence = NULL;
        sectorTypeObject.tp_as_mapping = NULL;
        sectorTypeObject.tp_hash = NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10016FFA
*/

void bld_py_sector_dealloc(PyObject *self) {
        free(self);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001700C
*/

int bld_py_sector_print(PyObject *self, FILE *file, int flags) {
        static char buffer[512];
        sprintf(buffer, "Sector: %d", ((bld_py_sector_t *)self)->sectorID);
        fprintf(file, buffer);
        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001703F
*/

PyObject *bld_py_sector_getattr(PyObject *self, char *attr_name)
{
        int active, n_surfaces;
        double active_surf_x, active_surf_y, active_surf_z;
        PyObject *active_surface, *surf_x_obj, *surf_y_obj, *surf_z_obj;
        int num_pieces;
        double piece_x, piece_y, piece_z;
        const char *piece_name;
        PyObject *piece_x_obj, *piece_y_obj, *piece_z_obj;
        PyObject *break_info, *piece_obj, *piece_coord_obj, *piece_name_obj;
        PyObject *on_enter, *on_leave, *on_hit, *on_walk_on, *on_walk_out;
        int too_steep, action_area;
        double too_steep_angle;
        int code;

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Sector de un mapa de Blade.");

        if (!strcmp(attr_name, "Active")) {
                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_ACTIVE, 0,
                        &active
                );
                if (code == 1)
                        return PyInt_FromLong(active);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nSurfaces")) {
                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_N_SURFACES,
                        0, &n_surfaces
                );
                if (code == 1)
                        return PyInt_FromLong(n_surfaces);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "ActiveSurface")) {
                code = GetSectorVectorProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_VEC_ACTIVE_SURFACE, 0, &active_surf_x,
                        &active_surf_y, &active_surf_z
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                active_surface = PyTuple_New(3);

                surf_x_obj = PyFloat_FromDouble(active_surf_x);
                surf_y_obj = PyFloat_FromDouble(active_surf_y);
                surf_z_obj = PyFloat_FromDouble(active_surf_z);

                PyTuple_SET_ITEM(active_surface, 0, surf_x_obj);
                PyTuple_SET_ITEM(active_surface, 1, surf_y_obj);
                PyTuple_SET_ITEM(active_surface, 2, surf_z_obj);

                return active_surface;
        }

        if (!strcmp(attr_name, "BreakInfo")) {
                int i;

                num_pieces = 0;

                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_NUM_PIECES,
                        0, &num_pieces
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                if (num_pieces == 0) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

                break_info = PyTuple_New(num_pieces);

                for (i = 0; i < num_pieces; i++) {

                        piece_obj = PyTuple_New(2);
                        piece_coord_obj = PyTuple_New(3);

                        GetSectorVectorProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_VEC_PIECE, i, &piece_x, &piece_y, &piece_z
                        );

                        piece_x_obj = PyFloat_FromDouble(piece_x);
                        piece_y_obj = PyFloat_FromDouble(piece_y);
                        piece_z_obj = PyFloat_FromDouble(piece_z);

                        PyTuple_SET_ITEM(piece_coord_obj, 0, piece_x_obj);
                        PyTuple_SET_ITEM(piece_coord_obj, 1, piece_y_obj);
                        PyTuple_SET_ITEM(piece_coord_obj, 2, piece_z_obj);

                        GetSectorStringProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_STR_PIECE_NAME, i, &piece_name
                        );

                        piece_name_obj = PyString_FromString(piece_name);

                        PyTuple_SET_ITEM(piece_obj, 0, piece_name_obj);
                        PyTuple_SET_ITEM(piece_obj, 1, piece_coord_obj);

                        PyTuple_SET_ITEM(break_info, i, piece_obj);

                }

                return break_info;
        }

        if (!strcmp(attr_name, "Index")) {
                return PyInt_FromLong(((bld_py_sector_t *)self)->sectorID);
        }

        if (!strcmp(attr_name, "OnEnter")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_ENTER,
                        0, &on_enter
                );
                return on_enter;
        }

        if (!strcmp(attr_name, "OnLeave")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_LEAVE,
                        0, &on_leave
                );
                return on_leave;
        }

        if (!strcmp(attr_name, "OnHit")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_HIT, 0,
                        &on_hit
                );
                return on_hit;
        }

        if (!strcmp(attr_name, "OnWalkOn")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_WALK_ON,
                        0, &on_walk_on
                );
                return on_walk_on;
        }

        if (!strcmp(attr_name, "OnWalkOut")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FNC_ON_WALK_OUT, 0, &on_walk_out
                );
                return on_walk_out;
        }

        if (!strcmp(attr_name, "TooSteep")) {
                GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_TOO_STEEP,
                        0, &too_steep
                );
                return PyInt_FromLong(too_steep);
        }

        if (!strcmp(attr_name, "TooSteepAngle")) {
                GetSectorFloatProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FLT_TOO_STEEP_ANGLE, 0, &too_steep_angle
                );
                return PyFloat_FromDouble(too_steep_angle);
        }

        if (!strcmp(attr_name, "ActionArea")) {
                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_INT_ACTION_AREA, 0, &action_area
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                return PyInt_FromLong(action_area);
        }

        return Py_FindMethod(sector_methods, self, attr_name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100175EB
*/

int bld_py_sector_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        int active;
        PyObject *on_enter, *on_leave, *on_hit, *on_walk_on, *on_walk_out;
        double active_surf_x, active_surf_y, active_surf_z;
        int too_steep, action_area;
        double too_steep_angle;
        int num_pieces;
        double piece_x, piece_y, piece_z;
        const char *piece_name;
        PyObject *piece_x_obj, *piece_y_obj, *piece_z_obj;
        PyObject *break_info, *piece_obj, *piece_coord_obj, *piece_name_obj;
        int code;

        PyErr_Clear();
        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete Sector attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "Active")) {
                if (!PyArg_Parse(value, "i", &active)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_ACTIVE, 0,
                        active
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnEnter")) {
                if(!PyArg_Parse(value, "O", &on_enter)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_enter))
                        on_enter = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_ENTER,
                        0, on_enter
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnLeave")) {
                if (!PyArg_Parse(value, "O", &on_leave)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_leave))
                        on_leave = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_LEAVE,
                        0, on_leave
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnHit")) {
                if (!PyArg_Parse(value, "O", &on_hit)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_hit))
                        on_hit = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_HIT, 0,
                        on_hit
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnWalkOn")) {
                if (!PyArg_Parse(value, "O", &on_walk_on)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_walk_on))
                        on_walk_on = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FNC_ON_WALK_ON, 0, on_walk_on
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "ActiveSurface")) {
                if (!PyArg_Parse(
                        value, "(ddd)", &active_surf_x, &active_surf_y,
                        &active_surf_z
                )) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorVectorProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_VEC_ACTIVE_SURFACE, 0, active_surf_x, active_surf_y,
                        active_surf_z
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnWalkOut")) {
                if (!PyArg_Parse(value, "O", &on_walk_out)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_walk_out))
                        on_walk_out = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FNC_ON_WALK_OUT, 0, on_walk_out
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "TooSteep")) {
                if (!PyArg_Parse(value, "i", &too_steep)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_TOO_STEEP,
                        0, too_steep
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "TooSteepAngle")) {
                if (!PyArg_Parse(value, "d", &too_steep_angle)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorFloatProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FLT_TOO_STEEP_ANGLE, 0, too_steep_angle
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "BreakInfo")) {
                int i;

                if (!PyArg_Parse(value, "O", &break_info)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyTuple_Check(break_info)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                num_pieces = PyTuple_Size(break_info);

                SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_NUM_PIECES,
                        0, num_pieces
                );

                for(i = 0; i < num_pieces; i++) {
                        piece_obj = PyTuple_GET_ITEM(break_info, i);

                        piece_name_obj = PyTuple_GET_ITEM(piece_obj, 0);
                        piece_coord_obj = PyTuple_GET_ITEM(piece_obj, 1);

                        piece_x_obj = PyTuple_GET_ITEM(piece_coord_obj, 0);
                        piece_y_obj = PyTuple_GET_ITEM(piece_coord_obj, 1);
                        piece_z_obj = PyTuple_GET_ITEM(piece_coord_obj, 2);

                        piece_name = PyString_AsString(piece_name_obj);
                        piece_x = PyFloat_AsDouble(piece_x_obj);
                        piece_y = PyFloat_AsDouble(piece_y_obj);
                        piece_z = PyFloat_AsDouble(piece_z_obj);

                        SetSectorVectorProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_VEC_PIECE, i, piece_x, piece_y, piece_z
                        );

                        SetSectorStringProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_STR_PIECE_NAME, i, piece_name
                        );
                }

                return 0;
        }

        if (!strcmp(attr_name, "ActionArea")) {
                if (!PyArg_Parse(value, "i", &action_area)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_INT_ACTION_AREA, 0, action_area
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
