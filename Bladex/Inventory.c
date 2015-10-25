
#include "bladex_int.h"


static PyObject* bex_inv_CarringObject(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetRightBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetLeftBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkRightHand(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkLeftHand(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkLeftHand2(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkRightBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkLeftBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_SetCurrentQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddObject(PyObject* self, PyObject* args);
static PyObject* add_object(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_RemoveObject(PyObject* self, PyObject* args);
static PyObject *remove_object(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_GetObject(PyObject* self, PyObject* args);
static PyObject* get_object(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_GetSelectedObject(PyObject* self, PyObject* args);
static PyObject* get_selected_object(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_CycleObjects(PyObject* self, PyObject* args);
static PyObject *cycle_objects(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_IsObjectSelected(PyObject* self, PyObject* args);
static PyObject *is_object_selected(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_GetNumberObjectsAt(PyObject* self, PyObject* args);
static PyObject *get_number_objects_at(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_GetMaxNumberObjectsAt(PyObject* self, PyObject* args);
static PyObject *get_max_number_objects_at(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_AddShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetActiveShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetActiveWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetActiveQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleShields(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsShieldSelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetBow(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetMagicShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleWeapons(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsWeaponSelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddBow(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveBow(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddMagicShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveMagicShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleQuivers(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsQuiverSelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleKeys(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsKeySelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddSpecialKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveSpecialKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSpecialKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddTablet(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveTablet(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetTablet(PyObject* self, PyObject* args);
static void init_inventory_type(void);
static void bld_py_inventory_dealloc(PyObject *self);
static int bld_py_inventory_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_inventory_getattr(PyObject *self, char *attr_name);
static int bld_py_inventory_setattr(PyObject *self, char *attr_name, PyObject *value);


PyTypeObject inventoryTypeObject;


static PyMethodDef inventory_methods[] = {
    { "LinkRightHand",                  bex_inv_LinkRightHand,              METH_VARARGS, NULL },
    { "LinkLeftHand",                   bex_inv_LinkLeftHand,               METH_VARARGS, NULL },
    { "LinkLeftHand2",                  bex_inv_LinkLeftHand2,              METH_VARARGS, NULL },
    { "LinkRight",                      bex_inv_LinkRightHand,              METH_VARARGS, NULL },
    { "LinkLeft",                       bex_inv_LinkLeftHand,               METH_VARARGS, NULL },
    { "LinkRightBack",                  bex_inv_LinkRightBack,              METH_VARARGS, NULL },
    { "LinkLeftBack",                   bex_inv_LinkLeftBack,               METH_VARARGS, NULL },
    { "LinkBack",                       bex_inv_LinkBack,                   METH_VARARGS, NULL },
    { "SetCurrentQuiver",               bex_inv_SetCurrentQuiver,           METH_VARARGS, NULL },
    { "AddObject",                      bex_inv_AddObject,                  METH_VARARGS, NULL },
    { "RemoveObject",                   bex_inv_RemoveObject,               METH_VARARGS, NULL },
    { "GetObject",                      bex_inv_GetObject,                  METH_VARARGS, NULL },
    { "GetSelectedObject",              bex_inv_GetSelectedObject,          METH_VARARGS, NULL },
    { "CycleObjects",                   bex_inv_CycleObjects,               METH_VARARGS, NULL },
    { "GetNumberObjectsAt",             bex_inv_GetNumberObjectsAt,         METH_VARARGS, NULL },
    { "GetMaxNumberObjectsAt",          bex_inv_GetMaxNumberObjectsAt,      METH_VARARGS, NULL },
    { "IsObjectSelected",               bex_inv_IsObjectSelected,           METH_VARARGS, NULL },
    { "AddShield",                      bex_inv_AddShield,                  METH_VARARGS, NULL },
    { "RemoveShield",                   bex_inv_RemoveShield,               METH_VARARGS, NULL },
    { "GetShield",                      bex_inv_GetShield,                  METH_VARARGS, NULL },
    { "GetSelectedShield",              bex_inv_GetSelectedShield,          METH_VARARGS, NULL },
    { "GetActiveShield",                bex_inv_GetActiveShield,            METH_VARARGS, NULL },
    { "CycleShields",                   bex_inv_CycleShields,               METH_VARARGS, NULL },
    { "IsShieldSelected",               bex_inv_IsShieldSelected,           METH_VARARGS, NULL },
    { "AddWeapon",                      bex_inv_AddWeapon,                  METH_VARARGS, NULL },
    { "RemoveWeapon",                   bex_inv_RemoveWeapon,               METH_VARARGS, NULL },
    { "AddBow",                         bex_inv_AddBow,                     METH_VARARGS, NULL },
    { "RemoveBow",                      bex_inv_RemoveBow,                  METH_VARARGS, NULL },
    { "AddMagicShield",                 bex_inv_AddMagicShield,             METH_VARARGS, NULL },
    { "RemoveMagicShield",              bex_inv_RemoveMagicShield,          METH_VARARGS, NULL },
    { "GetMagicShield",                 bex_inv_GetMagicShield,             METH_VARARGS, NULL },
    { "GetWeapon",                      bex_inv_GetWeapon,                  METH_VARARGS, NULL },
    { "GetSelectedWeapon",              bex_inv_GetSelectedWeapon,          METH_VARARGS, NULL },
    { "GetActiveWeapon",                bex_inv_GetActiveWeapon,            METH_VARARGS, NULL },
    { "CycleWeapons",                   bex_inv_CycleWeapons,               METH_VARARGS, NULL },
    { "IsWeaponSelected",               bex_inv_IsWeaponSelected,           METH_VARARGS, NULL },
    { "GetBow",                         bex_inv_GetBow,                     METH_VARARGS, NULL },
    { "AddQuiver",                      bex_inv_AddQuiver,                  METH_VARARGS, NULL },
    { "RemoveQuiver",                   bex_inv_RemoveQuiver,               METH_VARARGS, NULL },
    { "GetQuiver",                      bex_inv_GetQuiver,                  METH_VARARGS, NULL },
    { "GetSelectedQuiver",              bex_inv_GetSelectedQuiver,          METH_VARARGS, NULL },
    { "GetActiveQuiver",                bex_inv_GetActiveQuiver,            METH_VARARGS, NULL },
    { "CycleQuivers",                   bex_inv_CycleQuivers,               METH_VARARGS, NULL },
    { "IsQuiverSelected",               bex_inv_IsQuiverSelected,           METH_VARARGS, NULL },
    { "AddKey",                         bex_inv_AddKey,                     METH_VARARGS, NULL },
    { "RemoveKey",                      bex_inv_RemoveKey,                  METH_VARARGS, NULL },
    { "GetKey",                         bex_inv_GetKey,                     METH_VARARGS, NULL },
    { "GetSelectedKey",                 bex_inv_GetSelectedKey,             METH_VARARGS, NULL },
    { "CycleKeys",                      bex_inv_CycleKeys,                  METH_VARARGS, NULL },
    { "IsKeySelected",                  bex_inv_IsKeySelected,              METH_VARARGS, NULL },
    { "AddSpecialKey",                  bex_inv_AddSpecialKey,              METH_VARARGS, NULL },
    { "RemoveSpecialKey",               bex_inv_RemoveSpecialKey,           METH_VARARGS, NULL },
    { "GetSpecialKey",                  bex_inv_GetSpecialKey,              METH_VARARGS, NULL },
    { "AddTablet",                      bex_inv_AddTablet,                  METH_VARARGS, NULL },
    { "RemoveTablet",                   bex_inv_RemoveTablet,               METH_VARARGS, NULL },
    { "GetTablet",                      bex_inv_GetTablet,                  METH_VARARGS, NULL },
    { "GetRightBack",                   bex_inv_GetRightBack,               METH_VARARGS, NULL },
    { "GetLeftBack",                    bex_inv_GetLeftBack,                METH_VARARGS, NULL },
    { "CarringObject",                  bex_inv_CarringObject,              METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


// address: 0x100140a0
PyObject *get_inventory(const char *name) {
        bld_py_inventory_t *inventory_obj;

        inventory_obj = PyObject_NEW(bld_py_inventory_t, &inventoryTypeObject);
        if (inventory_obj == NULL)
                return NULL;

        inventory_obj->name = strdup(name);

        return (PyObject *)inventory_obj;
}


// address: 0x100140e9
PyObject *bex_inv_CarringObject(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        if (!PyArg_ParseTuple(args, "s", &obj_name))
                return NULL;

        code = CarringObject(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014149
PyObject *bex_inv_GetRightBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetRightBack(inventory->name);
        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x1001419d
PyObject *bex_inv_GetLeftBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetLeftBack(inventory->name);
        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x100141f1
PyObject *bex_inv_LinkRightHand(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;
        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkRightHand(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x1001424b
PyObject *bex_inv_LinkLeftHand(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkLeftHand(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}

// address: 0x100142a5
PyObject *bex_inv_LinkLeftHand2(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkLeftHand2(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x100142ff
PyObject *bex_inv_LinkRightBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkRightBack(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014359
PyObject *bex_inv_LinkLeftBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkLeftBack(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x100143b3
PyObject *bex_inv_LinkBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkBack(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x1001440d
PyObject *bex_inv_SetCurrentQuiver(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *quiver_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &quiver_name))
                code = SetCurrentQuiver(inventory->name, quiver_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014467
PyObject *bex_inv_AddObject(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x1001447e
PyObject *add_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int unknown = 0;
        const char *obj_name;
        int code;

        code = 0;

        if (PyArg_ParseTuple(args, "s|i", &obj_name, &unknown))
                code = AddObject(inventory->name, obj_type, unknown, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x100144eb
PyObject *bex_inv_RemoveObject(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014502
PyObject *remove_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;
        int code;

        if (!PyArg_ParseTuple(args, "s", &obj_name))
                return NULL;

        code = RemoveObject(inventory->name, obj_type, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014566
PyObject* bex_inv_GetObject(PyObject* self, PyObject* args) {
        return get_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x1001457d
PyObject *get_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int obj_index;
        const char *obj_name, *obj;

        if (!PyArg_ParseTuple(args, "i", &obj_index)) {
                PyErr_Clear();
                if (!PyArg_ParseTuple(args, "s", &obj_name))
                        return NULL;

                obj = GetObjectByName(inventory->name, obj_type, obj_name);
                if (obj == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

                return Py_BuildValue("s", obj);
        } else {
                obj = GetObject(inventory->name, obj_type, obj_index);
                if (obj == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

                return Py_BuildValue("s", obj);
        }
}


// address: 0x10014669
PyObject *bex_inv_GetSelectedObject(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014680
PyObject *get_selected_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        obj = GetSelectedObject(inventory->name, obj_type);
        if (obj == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj);
}


// address: 0x100146f2
PyObject *bex_inv_CycleObjects(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014709
PyObject *cycle_objects(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        Cycle(inventory->name, obj_type);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x1001475f
PyObject *bex_inv_IsObjectSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014776
PyObject *is_object_selected(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int obj_index;

        if (!PyArg_ParseTuple(args, "i", &obj_index))
                return NULL;

        return Py_BuildValue(
                "i", IsSelected(inventory->name, obj_type, obj_index)
        );
}


// address: 0x100147d3
PyObject *bex_inv_GetNumberObjectsAt(PyObject *self, PyObject *args) {
        return get_number_objects_at(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x100147ea
PyObject *get_number_objects_at(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int index;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;


        return Py_BuildValue(
                "i", GetNumberObjectsAt(inventory->name, obj_type, index)
        );
}


// address: 0x10014847
PyObject *bex_inv_GetMaxNumberObjectsAt(PyObject *self, PyObject *args) {
        return get_max_number_objects_at(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x1001485e
PyObject *get_max_number_objects_at(
        PyObject *self, PyObject *args, int obj_type
) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int index;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        return Py_BuildValue(
                "i", GetMaxNumberObjectsAt(inventory->name, obj_type, index)
        );
}


// address: 0x100148bb
PyObject *bex_inv_AddShield(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x100148d2
PyObject *bex_inv_RemoveShield(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x100148e9
PyObject* bex_inv_GetShield(PyObject* self, PyObject* args) {
        return get_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014900
PyObject *bex_inv_GetSelectedShield(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014917
PyObject *bex_inv_GetActiveShield(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *shield_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        shield_name = GetActiveShield(inventory->name);
        if (shield_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", shield_name);
}


// address: 0x10014986
PyObject *bex_inv_GetActiveWeapon(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *weapon_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        weapon_name = GetActiveWeapon(inventory->name);
        if (weapon_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", weapon_name);
}


// address: 0x100149f5
PyObject *bex_inv_GetActiveQuiver(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *quiver_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        quiver_name = GetActiveQuiver(inventory->name);
        if (quiver_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", quiver_name);
}


// address: 0x10014a64
PyObject *bex_inv_CycleShields(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014a7b
PyObject *bex_inv_IsShieldSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014a92
PyObject *bex_inv_AddWeapon(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        int flag = 0;
        const char *weapon_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s|i", &weapon_name, &flag))
                code = AddWeapon(inventory->name, flag, weapon_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014afb
PyObject *bex_inv_RemoveWeapon(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014b12
PyObject *bex_inv_GetWeapon(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014b29
PyObject *bex_inv_GetBow(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetObject(inventory->name, INV_OBJ_TYPE_BOW, 0);
        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x10014b81
PyObject *bex_inv_GetMagicShield(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetObject(inventory->name, INV_OBJ_TYPE_MAGIC_SHIELD, 0);

        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x10014bd9
PyObject *bex_inv_GetSelectedWeapon(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014bf0
PyObject *bex_inv_CycleWeapons(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014c07
PyObject *bex_inv_IsWeaponSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014c1e
PyObject *bex_inv_AddBow(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_BOW);
}


// address: 0x10014c35
PyObject *bex_inv_RemoveBow(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_BOW);
}


// address: 0x10014c4c
PyObject *bex_inv_AddMagicShield(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_MAGIC_SHIELD);
}


// address: 0x10014c63
PyObject *bex_inv_RemoveMagicShield(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_MAGIC_SHIELD);
}


// address: 0x10014c7a
PyObject *bex_inv_AddQuiver(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014c91
PyObject *bex_inv_RemoveQuiver(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014ca8
PyObject *bex_inv_GetQuiver(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014cbf
PyObject *bex_inv_GetSelectedQuiver(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014cd6
PyObject *bex_inv_CycleQuivers(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014ced
PyObject *bex_inv_IsQuiverSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014d04
PyObject *bex_inv_AddKey(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d1b
PyObject *bex_inv_RemoveKey(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d32
PyObject *bex_inv_GetKey(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d49
PyObject *bex_inv_GetSelectedKey(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d60
PyObject *bex_inv_CycleKeys(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d77
PyObject *bex_inv_IsKeySelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d8e
PyObject *bex_inv_AddSpecialKey(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_SPECIAL_KEY);
}


// address: 0x10014da5
PyObject *bex_inv_RemoveSpecialKey(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_SPECIAL_KEY);
}


// address: 0x10014dbc
PyObject *bex_inv_GetSpecialKey(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_SPECIAL_KEY);
}


// address: 0x10014dd3
PyObject *bex_inv_AddTablet(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_TABLET);
}


// address: 0x10014dea
PyObject *bex_inv_RemoveTablet(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_TABLET);
}


// address: 0x10014e01
PyObject *bex_inv_GetTablet(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_TABLET);
}


// address: 0x10014e18
void init_inventory() {
        init_inventory_type();
}


// address: 0x10014e22
void init_inventory_type() {

        memset(&inventoryTypeObject, 0, sizeof(PyTypeObject));

        inventoryTypeObject.ob_refcnt = 1;
        inventoryTypeObject.ob_type = &PyType_Type;
        inventoryTypeObject.ob_size = 0;
        inventoryTypeObject.tp_name = "B_PyInventory";
        inventoryTypeObject.tp_basicsize = sizeof(bld_py_inventory_t);
        inventoryTypeObject.tp_itemsize = 0;
        inventoryTypeObject.tp_dealloc = bld_py_inventory_dealloc;
        inventoryTypeObject.tp_print = bld_py_inventory_print;
        inventoryTypeObject.tp_getattr = bld_py_inventory_getattr;
        inventoryTypeObject.tp_setattr = bld_py_inventory_setattr;
        inventoryTypeObject.tp_compare = NULL;
        inventoryTypeObject.tp_repr = NULL;
        inventoryTypeObject.tp_as_number = NULL;
        inventoryTypeObject.tp_as_sequence = NULL;
        inventoryTypeObject.tp_as_mapping = NULL;
        inventoryTypeObject.tp_hash = NULL;
}


// address: 0x10014ecd
void bld_py_inventory_dealloc(PyObject *self) {
        if (((bld_py_inventory_t *)self)->name)
                free(((bld_py_inventory_t *)self)->name);
        free(self);
        return;
}


// address: 0x10014ef8
int bld_py_inventory_print(PyObject *self, FILE *file, int flags) {
        const char *name;
        int code;
        static char buffer[512];

        code = GetInventoryStringProperty(
                ((bld_py_inventory_t *)self)->name, INV_STR_NAME, &name
        );
        if (code == -1) {
                fprintf(file, "NULL Inventory");
        } else {
                sprintf(buffer, "Inventory:%s\n", name);
                fprintf(file, buffer);
        }

        return 0;
}


// address: 0x10014f60
PyObject *bld_py_inventory_getattr(PyObject *self, char *attr_name)
{
        const char *name, *owner;
        int n_objects, n_weapons, n_shields, n_quivers;
        int max_objects, max_weapons, max_shields, max_quivers;
        int has_bow, holding_bow, has_bow_on_back, n_kind_objects;
        int n_keys, n_special_keys, n_tablets;
        int holding_shield, has_shield_on_back;
        int code;

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Blade Inventory.");

        if (!strcmp(attr_name, "Name")) {
                code = GetInventoryStringProperty(
                        ((bld_py_inventory_t *)self)->name, INV_STR_NAME,
                        &name
                );
                if (code != -1)
                        return PyString_FromString(name);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "Owner")) {
                code = GetInventoryStringProperty(
                        ((bld_py_inventory_t *)self)->name, INV_STR_OWNER,
                        &owner
                );
                if (code != -1)
                        return PyString_FromString(owner);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nObjects")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_OBJECTS,
                        &n_objects
                );

                if (code != -1)
                        return PyInt_FromLong(n_objects);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nWeapons")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_WEAPONS,
                        &n_weapons
                );

                if (code != -1)
                        return PyInt_FromLong(n_weapons);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nShields")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_SHIELDS,
                        &n_shields
                );

                if (code != -1)
                        return PyInt_FromLong(n_shields);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        /* FIXME double nQuivers */
        if (!strcmp(attr_name, "nQuivers")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_QUIVERS,
                        &n_quivers
                );

                if (code != -1)
                        return PyInt_FromLong(n_quivers);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxObjects")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_OBJECTS,
                        &max_objects
                );

                if (code != -1)
                        return PyInt_FromLong(max_objects);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxWeapons")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_WEAPONS,
                        &max_weapons
                );

                if (code != -1)
                        return PyInt_FromLong(max_weapons);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxShields")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_SHIELDS,
                        &max_shields);

                if (code != -1)
                        return PyInt_FromLong(max_shields);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxQuivers")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_QUIVERS,
                        &max_quivers
                );

                if (code != -1)
                        return PyInt_FromLong(max_quivers);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HasBow")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_HAS_BOW,
                        &has_bow
                );

                if (code != -1)
                        return PyInt_FromLong(has_bow);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HoldingBow")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_HOLDING_BOW,
                        &holding_bow
                );

                if (code != -1)
                        return PyInt_FromLong(holding_bow);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HasBowOnBack")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_HAS_BOW_ON_BACK, &has_bow_on_back
                );

                if (code != -1)
                        return PyInt_FromLong(has_bow_on_back);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nKindObjects")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_KIND_OBJECTS,
                        &n_kind_objects
                );

                if (code != -1)
                        return PyInt_FromLong(n_kind_objects);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        /* FIXME double nQuivers */
        if (!strcmp(attr_name, "nQuivers")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_QUIVERS,
                        &n_quivers
                );

                if (code != -1)
                        return PyInt_FromLong(n_quivers);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nKeys")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_KEYS,
                        &n_keys
                );

                if (code != -1)
                        return PyInt_FromLong(n_keys);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nSpecialKeys")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_N_SPECIAL_KEYS, &n_special_keys
                );

                if (code != -1)
                        return PyInt_FromLong(n_special_keys);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nTablets")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_TABLETS,
                        &n_tablets
                );

                if (code != -1)
                        return PyInt_FromLong(n_tablets);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HoldingShield")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_HOLDING_SHIELD, &holding_shield
                );

                if (code != -1)
                        return PyInt_FromLong(holding_shield);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HasShieldOnBack")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_HAS_SHIELD_ON_BACK, &has_shield_on_back
                );

                if (code != -1)
                        return PyInt_FromLong(has_shield_on_back);
                
                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        return Py_FindMethod(inventory_methods, self, attr_name);
}


// address: 0x10015768
int bld_py_inventory_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        int max_objects, max_weapons, max_shields, max_quivers;
        int code;

        PyErr_Clear();

        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError,
                        "can't delete Inventory attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "maxObjects")) {
                if (!PyArg_Parse(value, "i", &max_objects)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_OBJECTS,
                        max_objects
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "maxWeapons")) {
                if (!PyArg_Parse(value, "i", &max_weapons)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_WEAPONS,
                        max_weapons
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "maxShields")) {
                if (!PyArg_Parse(value, "i", &max_shields)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_SHIELDS,
                        max_shields
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "maxQuivers")) {
                if (!PyArg_Parse(value, "i", &max_quivers)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_QUIVERS,
                        max_quivers
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

