
#include "bladex_int.h"


static PyObject* bex_char_LoadAllAnimations(PyObject* self, PyObject* args);
static PyObject* bex_char_ChangeAnimation(PyObject* self, PyObject* args);
static PyObject* bex_char_SetAnmDefaultPrefix(PyObject* self, PyObject* args);
static PyObject* bex_char_AddAttack(PyObject* self, PyObject* args);
static PyObject* bex_char_AttackWindow(PyObject* self, PyObject* args);
static PyObject* bex_char_AddLevels(PyObject* self, PyObject* args);
static PyObject* bex_char_AddEnergyLevel(PyObject* self, PyObject* args);
static PyObject* bex_char_AttackTypeFlag(PyObject* self, PyObject* args);
static PyObject* bex_char_AllowAttack(PyObject* self, PyObject* args);
static PyObject* bex_char_MetaAttack(PyObject* self, PyObject* args);
static PyObject* bex_char_AssignTrail(PyObject* self, PyObject* args);
static PyObject* bex_char_SetNCDSpheres(PyObject* self, PyObject* args);
static PyObject* bex_char_SetCDSphere(PyObject* self, PyObject* args);
static void init_char_type(void);
static void bld_py_char_dealloc(PyObject *self);
static int bld_py_char_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_char_getattr(PyObject *self, char *attr_name);
static int bld_py_char_setattr(PyObject *self, char *attr_name, PyObject *value);


PyTypeObject charTypeObject;


static PyMethodDef char_methods[] = {
    { "LoadAllAnimations",              bex_char_LoadAllAnimations,         METH_VARARGS, NULL },
    { "ChangeAnimation",                bex_char_ChangeAnimation,           METH_VARARGS, NULL },
    { "SetAnmDefaultPrefix",            bex_char_SetAnmDefaultPrefix,       METH_VARARGS, NULL },
    { "AddAttack",                      bex_char_AddAttack,                 METH_VARARGS, NULL },
    { "AttackWindow",                   bex_char_AttackWindow,              METH_VARARGS, NULL },
    { "AddLevels",                      bex_char_AddLevels,                 METH_VARARGS, NULL },
    { "AddEnergyLevel",                 bex_char_AddEnergyLevel,            METH_VARARGS, NULL },
    { "AttackTypeFlag",                 bex_char_AttackTypeFlag,            METH_VARARGS, NULL },
    { "AllowAttack",                    bex_char_AllowAttack,               METH_VARARGS, NULL },
    { "MetaAttack",                     bex_char_MetaAttack,                METH_VARARGS, NULL },
    { "AssignTrail",                    bex_char_AssignTrail,               METH_VARARGS, NULL },
    { "SetNCDSpheres",                  bex_char_SetNCDSpheres,             METH_VARARGS, NULL },
    { "SetCDSphere",                    bex_char_SetCDSphere,               METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


/*
* Module:                 Bladex.dll
* Entry point:            0x100073B0
*/

PyObject *get_char_by_name(const char *name, const char *short_name) {
        bld_py_char_t *char_obj;
        int charID;

        charID = GetCharByName(name, short_name);
        if (charID < 0)
                return NULL;

        char_obj = PyObject_NEW(bld_py_char_t, &charTypeObject);
        if (char_obj == NULL)
                return NULL;

        char_obj->charID = charID;

        return (PyObject *)char_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007410
*/

PyObject *bex_char_LoadAllAnimations(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        int code;

        code = LoadAllAnimations(character->charID);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000745B
*/

PyObject *bex_char_ChangeAnimation(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *old_anm_name, *new_anm_name;
        int code;

        if (!PyArg_ParseTuple(args, "ss", &old_anm_name, &new_anm_name))
                return NULL;

        code = ChangeAnimation(character->charID, old_anm_name, new_anm_name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100074D0
*/

PyObject *bex_char_SetAnmDefaultPrefix(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *prefix;
        int ret;

        if(!PyArg_ParseTuple(args, "s", &prefix))
                return NULL;

        ret = SetAnmDefaultPrefix(character->charID, prefix);
        if (!ret)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000753D
*/

PyObject *bex_char_AddAttack(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *attack_name, *anm_name;
        int code;

        if(!PyArg_ParseTuple(args, "ss", &attack_name, &anm_name))
                return NULL;

        code = AddAttack(character->charID, attack_name, anm_name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100075B2
*/

PyObject *bex_char_AttackWindow(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *anm_name, *window_name;
        double window1, window2;
        int code;

        if (!PyArg_ParseTuple(
                args, "sdds", &anm_name, &window1, &window2, &window_name
        ))
                return NULL;

        code = AttackWindow(
                character->charID, anm_name, window1, window2, window_name
        );
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007643
*/

PyObject *bex_char_AddLevels(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *anm_name;
        double level1, level2;
        int code;

        if (!PyArg_ParseTuple(args, "sdd", &anm_name, &level1, &level2))
                return NULL;

        code = AttackLevels(character->charID, anm_name, level1, level2);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100076CC
*/

PyObject *bex_char_AddEnergyLevel(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *anm_name;
        double level;
        int code;

        if (!PyArg_ParseTuple(args, "sd", &anm_name, &level))
                return NULL;

        code = AttackEnergyLevel(character->charID, anm_name, level);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007747
*/

PyObject *bex_char_AttackTypeFlag(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *attack_name;
        int flag;
        int code;

        if (!PyArg_ParseTuple(args, "si", &attack_name, &flag))
                return NULL;

        code = AttackTypeFlag(character->charID, attack_name, flag);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100077BC
*/

PyObject *bex_char_AllowAttack(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *attack_name, *keys, *previous, *previous_negative;
        const char *window_name;
        const char *weapon_kind = "1H";
        int code;

        if (!PyArg_ParseTuple(
                args, "sssss|s", &attack_name, &keys, &previous,
                &previous_negative, &window_name, &weapon_kind
        ))
                return NULL;

        code = AllowAttack(
                character->charID, attack_name, keys, previous,
                previous_negative, window_name, weapon_kind
        );
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007889
*/

PyObject *bex_char_MetaAttack(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *meta_attack_name, *attack_name;
        int code;

        if (!PyArg_ParseTuple(args, "ss", &meta_attack_name, &attack_name))
                return NULL;

        code = MetaAttack(character->charID, meta_attack_name, attack_name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100078FE
*/

PyObject *bex_char_AssignTrail(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        const char *attack_name, *unknown, *trail_name;
        int code;

        if (!PyArg_ParseTuple(args, "sss", &attack_name, &unknown, &trail_name))
                return NULL;

        code = AssignTrail(
                character->charID, attack_name, unknown, trail_name
        );
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000797B
*/

PyObject *bex_char_SetNCDSpheres(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        int NCDSpheres;
        int ret;

        if(!PyArg_ParseTuple(args, "i", &NCDSpheres))
                return NULL;

        ret = SetNCDSpheres(character->charID, NCDSpheres);
        if (!ret) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100079E8
*/

PyObject *bex_char_SetCDSphere(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        int index;
        double h, r;
        int ret;

        if(!PyArg_ParseTuple(args, "idd", &index, &h, &r))
                return NULL;

        ret = SetCDSphere(character->charID, index, h, r);
        if (!ret) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10007A6D
*/

void init_char() {
        init_char_type();
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10007A77
*/

void init_char_type() {

        memset(&charTypeObject, 0, sizeof(PyTypeObject));

        charTypeObject.ob_refcnt = 1;
        charTypeObject.ob_type = &PyType_Type;
        charTypeObject.ob_size = 0;
        charTypeObject.tp_name = "B_PyChar";
        charTypeObject.tp_basicsize = sizeof(bld_py_char_t);
        charTypeObject.tp_itemsize = 0;
        charTypeObject.tp_dealloc = bld_py_char_dealloc;
        charTypeObject.tp_print = bld_py_char_print;
        charTypeObject.tp_getattr = bld_py_char_getattr;
        charTypeObject.tp_setattr = bld_py_char_setattr;
        charTypeObject.tp_compare = NULL;
        charTypeObject.tp_repr = NULL;
        charTypeObject.tp_as_number = NULL;
        charTypeObject.tp_as_sequence = NULL;
        charTypeObject.tp_as_mapping = NULL;
        charTypeObject.tp_hash = NULL;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10007B22
*/

void bld_py_char_dealloc(PyObject *self) {
        free(self);
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10007B34
*/

int bld_py_char_print(PyObject *self, FILE *file, int flags) {
        static char buffer[32];

        sprintf(buffer, "CharType %d", ((bld_py_char_t *)self)->charID);
        fprintf(file, buffer);
        return 0;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10007B67
*/

PyObject *bld_py_char_getattr(PyObject *self, char *attr_name) {
        double dist_stop, dist_stop2, dist_stop_max_factor, max_combat_dist;
        double max_see_dist, mov_frwd_speed_in_strafe, mov_bkwd_speed_in_strafe;
        double turn_speed, j_cost, max_fall, die_fall, max_stair, fov;
        const char *int_name, *no_armour, *low_armour, *med_armour, *high_armour;
        double max_grab, med_grab, min_2_grab, min_take;
        double max_take_1, max_take_2, max_take_3, max_take_4, max_take_5;
        double reach, hear_min_volume;
        int natural_weapons, head_controlled;
        int code;
        char buffer[256];

        if (!strcmp(attr_name, "__doc__")) {
                return PyString_FromString("CharType de enemigos de Blade.");
        }

        if (!strcmp(attr_name, "DistStop")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIST_STOP, 0,
                        &dist_stop
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(dist_stop);
        }

        if (!strcmp(attr_name, "DistStop2")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIST_STOP_2, 0,
                        &dist_stop2
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(dist_stop2);
        }

        if (!strcmp(attr_name, "DistStopMaxFactor")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_DIST_STOP_MAX_FACT, 0, &dist_stop_max_factor
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(dist_stop_max_factor);
        }

        if (!strcmp(attr_name, "MaxCombatDist")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MAX_COMBAT_DIST, 0, &max_combat_dist
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_combat_dist);
        }

        if (!strcmp(attr_name, "MaxSeeDist")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_SEE_DIST,
                        0, &max_see_dist
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_see_dist);
        }

        if (!strcmp(attr_name, "MovFrwdSpeedInStrafe")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MOV_FRWD_SPEED_IN_STRAFE, 0,
                        &mov_frwd_speed_in_strafe
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(mov_frwd_speed_in_strafe);
        }

        if (!strcmp(attr_name, "MovBkwdSpeedInStrafe")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MOV_BKWD_SPEED_IN_STRAFE, 0,
                        &mov_bkwd_speed_in_strafe
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(mov_bkwd_speed_in_strafe);
        }

        if (!strcmp(attr_name, "TurnSpeed")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_TURN_SPEED, 0,
                        &turn_speed
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(turn_speed);
        }

        if (!strcmp(attr_name, "Jcost")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_J_COST, 0,
                        &j_cost
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(j_cost);
        }

        if (!strcmp(attr_name, "MaxFall")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_FALL, 0,
                        &max_fall
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_fall);
        }

        if (!strcmp(attr_name, "DieFall")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIE_FALL, 0,
                        &die_fall
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(die_fall);
        }

        if (!strcmp(attr_name, "MaxStair")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_STAIR, 0,
                        &max_stair
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_stair);
        }

        if (!strcmp(attr_name, "Fov")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_FOV, 0, &fov
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(fov);
        }

        if (!strcmp(attr_name, "IntName")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_INT_NAME, 0,
                        &int_name
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Internal name");
                        return NULL;
                }
                return PyString_FromString(int_name);
        }

        if (!strcmp(attr_name, "MaxGrab")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_GRAB, 0,
                        &max_grab
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_grab);
        }

        if (!strcmp(attr_name, "MedGrab")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MED_GRAB, 0,
                        &med_grab
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(med_grab);
        }

        if (!strcmp(attr_name, "Min2Grab")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MIN_2_GRAB, 0,
                        &min_2_grab
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(min_2_grab);
        }

        if (!strcmp(attr_name, "NoArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_NO_ARMOUR, 0,
                        &no_armour
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
                return PyString_FromString(no_armour);
        }

        if (!strcmp(attr_name, "LowArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_STR_LOW_ARMOUR, 0, &low_armour
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
                return PyString_FromString(low_armour);
        }

        if (!strcmp(attr_name, "MedArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_MED_ARMOUR, 0,
                        &med_armour
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
                return PyString_FromString(med_armour);
        }

        if (!strcmp(attr_name, "HighArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_HIGH_ARMOUR, 0,
                        &high_armour
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
                return PyString_FromString(high_armour);
        }

        if (!strcmp(attr_name, "MinTake")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MIN_TAKE, 0,
                        &min_take);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(min_take);
        }

        if (!strcmp(attr_name, "MaxTake1"))  {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_1, 0,
                        &max_take_1
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_1);
        }

        if (!strcmp(attr_name, "MaxTake2")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_2, 0,
                        &max_take_2
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_2);
        }

        if (!strcmp(attr_name, "MaxTake3")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_3, 0,
                        &max_take_3);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_3);
        }

        if (!strcmp(attr_name, "MaxTake4")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_4, 0,
                        &max_take_4
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_4);
        }

        if (!strcmp(attr_name, "MaxTake5")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_5, 0,
                        &max_take_5
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_5);
        }

        if (!strcmp(attr_name, "Reach")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_REACH, 0,
                        &reach
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(reach);
        }

        if (!strcmp(attr_name, "HearMinVolume")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_HEAR_MIN_VOLUME, 0, &hear_min_volume
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(hear_min_volume);
        }

        if (!strcmp(attr_name, "NaturalWeapons")) {
                code = GetCharIntProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_INT_NATURAL_WEAPONS, 0, &natural_weapons
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyInt_FromLong(natural_weapons);
        }

        if (!strcmp(attr_name, "HeadControlled")) {
                code = GetCharIntProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_INT_HEAD_CONTROLLED, 0, &head_controlled
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
                return PyInt_FromLong(head_controlled);
        }

        return Py_FindMethod(char_methods, self, attr_name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10008984
*/

int bld_py_char_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        PyObject *on_first;
        double dist_stop, dist_stop_2, dist_stop_max_factor;
        double max_combat_dist, max_see_dist, mov_frwd_speed_in_strafe;
        double mov_bkwd_speed_in_strafe, turn_speed, j_dist, j_dist_2;
        double j_cost, max_fall, die_fall, max_stair, fov;
        double max_grab, med_grab, min_2_grab;
        const char *int_name, *biped, *add_route_anim;
        const char *no_armour, *low_armour, *med_armour, *high_armour;
        double min_take, reach, hear_min_volume;
        double max_take_1, max_take_2, max_take_3, max_take_4, max_take_5;
        int natural_weapons, head_controlled;
        int code;

        PyErr_Clear();

        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete Char attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "OnFirst")) {
                if (!PyArg_Parse(value, "O", &on_first)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFuncProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FNC_ON_FIRST, 0,
                        on_first
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "DistStop")) {
                if (!PyArg_Parse(value, "d", &dist_stop)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIST_STOP, 0,
                        dist_stop
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "DistStop2")) {
                if (!PyArg_Parse(value, "d", &dist_stop_2)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIST_STOP_2, 0,
                        dist_stop_2
                );

                if (code != 1) {
                    PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                    return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "DistStopMaxFactor")) {
                if (!PyArg_Parse(value, "d", &dist_stop_max_factor)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_DIST_STOP_MAX_FACT, 0, dist_stop_max_factor
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxCombatDist")) {
                if (!PyArg_Parse(value, "d", &max_combat_dist)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MAX_COMBAT_DIST, 0, max_combat_dist
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxSeeDist")) {
                if (!PyArg_Parse(value, "d", &max_see_dist)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(((bld_py_char_t *)self)->charID, CHR_FLT_MAX_SEE_DIST, 0, max_see_dist);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MovFrwdSpeedInStrafe")) {
                if (!PyArg_Parse(value, "d", &mov_frwd_speed_in_strafe)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MOV_FRWD_SPEED_IN_STRAFE, 0,
                        mov_frwd_speed_in_strafe
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MovBkwdSpeedInStrafe")) {
                if (!PyArg_Parse(value, "d", &mov_bkwd_speed_in_strafe)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MOV_BKWD_SPEED_IN_STRAFE, 0,
                        mov_bkwd_speed_in_strafe
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "TurnSpeed")) {
                if (!PyArg_Parse(value, "d", &turn_speed)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_TURN_SPEED, 0,
                        turn_speed
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Jdist")) {
                if (!PyArg_Parse(value, "d", &j_dist)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_J_DIST, 0,
                        j_dist
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Jdist2")) {
                if (!PyArg_Parse(value, "d", &j_dist_2)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_J_DIST_2, 0,
                        j_dist_2
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Jcost")) {
                if (!PyArg_Parse(value, "d", &j_cost)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_J_COST, 0,
                        j_cost
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxFall")) {
                if (!PyArg_Parse(value, "d", &max_fall)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_FALL, 0,
                        max_fall
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "DieFall")) {
                if (!PyArg_Parse(value, "d", &die_fall)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIE_FALL, 0,
                        die_fall
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxStair")) {
                if (!PyArg_Parse(value, "d", &max_stair)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_STAIR, 0,
                        max_stair
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Fov")) {
                if (!PyArg_Parse(value, "d", &fov)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_FOV, 0,
                        fov
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "IntName")) {
                if (!PyArg_Parse(value, "s", &int_name)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_INT_NAME, 0,
                        int_name
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Biped")) {
                if (!PyArg_Parse(value, "s", &biped)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_BIPED, 0,
                        biped
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "AddRouteAnim")) {
                if (!PyArg_Parse(value, "s", &add_route_anim)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_ADD_ROUTE_ANIM,
                        0, add_route_anim
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxGrab")) {
                if (!PyArg_Parse(value, "d", &max_grab)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_GRAB, 0,
                        max_grab
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MedGrab")) {
                if (!PyArg_Parse(value, "d", &med_grab)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MED_GRAB, 0,
                        med_grab
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Min2Grab")) {
                if (!PyArg_Parse(value, "d", &min_2_grab)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MIN_2_GRAB, 0,
                        min_2_grab
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "NoArmour")) {
                if (!PyArg_Parse(value, "s", &no_armour)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_NO_ARMOUR, 0,
                        no_armour
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "LowArmour")) {
                if (!PyArg_Parse(value, "s", &low_armour)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_LOW_ARMOUR, 0,
                        low_armour
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MedArmour")) {
                if (!PyArg_Parse(value, "s", &med_armour)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_MED_ARMOUR, 0,
                        med_armour
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "HighArmour")) {
                if (!PyArg_Parse(value, "s", &high_armour)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_HIGH_ARMOUR, 0,
                        high_armour
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MinTake")) {
                if (!PyArg_Parse(value, "d", &min_take)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MIN_TAKE, 0,
                        min_take
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxTake1")) {
                if (!PyArg_Parse(value, "d", &max_take_1)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_1, 0,
                        max_take_1
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxTake2")) {
                if (!PyArg_Parse(value, "d", &max_take_2)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_2, 0,
                        max_take_2
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxTake3")) {
                if (!PyArg_Parse(value, "d", &max_take_3)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_3, 0,
                        max_take_3
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxTake4")) {
                if (!PyArg_Parse(value, "d", &max_take_4)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_4, 0,
                        max_take_4
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "MaxTake5")) {
                if (!PyArg_Parse(value, "d", &max_take_5)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_5, 0,
                        max_take_5
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Reach")) {
                if (!PyArg_Parse(value, "d", &reach)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(((bld_py_char_t *)self)->charID, CHR_FLT_REACH, 0, reach);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "HearMinVolume")) {
                if (!PyArg_Parse(value, "d", &hear_min_volume)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_HEAR_MIN_VOLUME, 0, hear_min_volume
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "NaturalWeapons")) {
                if (!PyArg_Parse(value, "i", &natural_weapons)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharIntProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_INT_NATURAL_WEAPONS, 0, natural_weapons
                );

                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "HeadControlled")) {
                if (!PyArg_Parse(value, "i", &head_controlled)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetCharIntProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_INT_HEAD_CONTROLLED, 0, head_controlled
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
