
#include "bladex_int.h"
#include <Sound/SoundFuncs.h>


static PyObject* bex_snd_Play(PyObject* self, PyObject* args);
static PyObject* bex_snd_PlayStereo(PyObject* self, PyObject* args);
static PyObject* bex_snd_SetPitchVar(PyObject* self, PyObject* args);
static PyObject* bex_snd_AddAltSound(PyObject* self, PyObject* args);
static PyObject* bex_snd_Stop(PyObject* self, PyObject* args);
static void init_sound_type(void);
static void bld_py_sound_dealloc(PyObject *self);
static int bld_py_sound_print(PyObject *self, FILE *file, int flags);
static boolean bld_py_sound_check(PyObject *self);
static PyObject *bld_py_sound_repr(PyObject *self);
static PyObject *bld_py_sound_getattr(PyObject *self, char *attr_name);
static int bld_py_sound_setattr(PyObject *self, char *attr_name, PyObject *value);


PyTypeObject soundTypeObject;


static PyMethodDef sound_methods[] = {
    { "Play",                           bex_snd_Play,                       METH_VARARGS, NULL },
    { "PlayStereo",                     bex_snd_PlayStereo,                 METH_VARARGS, NULL },
    { "SetPitchVar",                    bex_snd_SetPitchVar,                METH_VARARGS, NULL },
    { "AddAltSound",                    bex_snd_AddAltSound,                METH_VARARGS, NULL },
    { "Stop",                           bex_snd_Stop,                       METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


/*
* Module:                 Bladex.dll
* Entry point:            0x10017E50
*/

PyObject *create_sound(const char *file_name, const char *sound_name) {
        B_Sound *sound;
        bld_py_sound_t *sound_obj;

        sound = CreateSound(file_name, sound_name);
        if (sound != NULL) {

                sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);

                if (sound_obj != NULL) {
                    sound_obj->sound = sound;
                    sound_obj->soundDev = GetSoundDevInstace();
                    return (PyObject *)sound_obj;
                } else {
                    DestroySound(sound);
                    return NULL;
                }
        }
        return NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10017EC9
*/

PyObject *create_sound_s(B_Sound *sound) {
        B_Sound *sound_s;
        bld_py_sound_t *sound_obj;

        sound_s = CreateSoundS(sound);
        if (sound_s == NULL)
                return NULL;

        sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);
        if (sound_obj == NULL) {
                DestroySound(sound_s);
                return NULL;
        }

        sound_obj->sound = sound_s;
        sound_obj->soundDev = GetSoundDevInstace();

        return (PyObject *)sound_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10017F3E
*/

PyObject *get_ghost_sector_sound(const char *gs_name) {
        B_Sound *sound;
        bld_py_sound_t *sound_obj;

        sound = GetGhostSectorSound(gs_name);
        if (sound == NULL)
                return NULL;

        sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);
        if (sound_obj == NULL) {
                DestroySound(sound);
                return NULL;
        }

        sound_obj->sound = sound;
        sound_obj->soundDev = GetSoundDevInstace();

        return (PyObject *)sound_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10017FB3
*/

PyObject *bex_snd_Play(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int i_unknown = 0;
        int code;
        double x, y, z;

        if (!PyArg_ParseTuple(args, "ddd|i", &x, &y, &z, &i_unknown))
                return NULL;

        code = PlaySoundM(sound->sound, x, y, z, i_unknown);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10018046
*/

PyObject *bex_snd_PlayStereo(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int i_unknown = 0;
        int code;

        if (!PyArg_ParseTuple(args, "|i", &i_unknown))
                return NULL;

        code = PlaySoundStereo(sound->sound, i_unknown);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100180B5
*/

PyObject *bex_snd_SetPitchVar(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int i_unknown;
        double d_unknown1, d_unknown2, d_unknown3, d_unknown4;


        if (!PyArg_ParseTuple(
                args, "idddd", &i_unknown, &d_unknown1, &d_unknown2,
                &d_unknown3, &d_unknown4
        ))
                return NULL;

        SetSoundPitchVar(sound->sound, i_unknown, d_unknown1, d_unknown2, d_unknown3, d_unknown4);
        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001813F
*/

PyObject *bex_snd_AddAltSound(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        const char *alt_sound;
        int code;

        if (!PyArg_ParseTuple(args, "s", &alt_sound)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return Py_BuildValue("i", 0);
        }

        code = addSoundVar(sound->sound, alt_sound);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100181CB
*/

PyObject *bex_snd_Stop(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = StopSound(sound->sound);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10018229
*/

void init_sound() {
        init_sound_type();
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10018233
*/

void init_sound_type() {

    memset(&soundTypeObject, 0, sizeof(PyTypeObject));

    soundTypeObject.ob_refcnt = 1;
    soundTypeObject.ob_type = &PyType_Type;
    soundTypeObject.ob_size = 0;
    soundTypeObject.tp_name = "B_PySound";
    soundTypeObject.tp_basicsize = sizeof(bld_py_sound_t);
    soundTypeObject.tp_itemsize = 0;
    soundTypeObject.tp_dealloc = bld_py_sound_dealloc;
    soundTypeObject.tp_print = bld_py_sound_print;
    soundTypeObject.tp_getattr = bld_py_sound_getattr;
    soundTypeObject.tp_setattr = bld_py_sound_setattr;
    soundTypeObject.tp_compare = NULL;
    soundTypeObject.tp_repr = bld_py_sound_repr;
    soundTypeObject.tp_as_number = NULL;
    soundTypeObject.tp_as_sequence = NULL;
    soundTypeObject.tp_as_mapping = NULL;
    soundTypeObject.tp_hash = NULL;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100182DE
*/

void bld_py_sound_dealloc(PyObject *self)
{
        if (bld_py_sound_check(self))
                free(self);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10018307
*/

boolean bld_py_sound_check(PyObject *self) {

        if (self == NULL)
                return FALSE;


        if ( ((bld_py_sound_t *)self)->sound == NULL )
                return FALSE;

        return TRUE;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10018325
*/

int bld_py_sound_print(PyObject *self, FILE *file, int flags)
{
        char buffer[128];

        if (bld_py_sound_check(self)) {
                sprintf(
                        buffer,
                        "Sound: %s (%d)\n",
                        GetSoundStringProperty(
                                SND_STR_NAME, ((bld_py_sound_t *)self)->sound
                        ),
                        PTR_TO_INT(((bld_py_sound_t *)self)->sound)
                );
                fprintf(file, buffer);
        }

        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001838A
*/

PyObject *bld_py_sound_repr(PyObject *self)
{
        char buffer[128];

        if (!bld_py_sound_check(self))
                return PyString_FromString("Invalid Sound");

        sprintf(
                buffer,
                "Sound: %s (%d)\n",
                GetSoundStringProperty(
                        SND_STR_NAME, ((bld_py_sound_t *)self)->sound
                ),
                PTR_TO_INT(((bld_py_sound_t *)self)->sound)
        );

        return PyString_FromString(buffer);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100183F5
*/

PyObject *bld_py_sound_getattr(PyObject *self, char *attr_name)
{
        if (!bld_py_sound_check(self))
                return PyString_FromString("Invalid Sound.");

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Objeto sonido Blade.");

        if (!strcmp(attr_name, "MinDistance"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_MIN_DISTANCE,
                                ((bld_py_sound_t *)self)->sound
                        )
                );

        if (!strcmp(attr_name, "MaxDistance"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_MAX_DISTANCE,
                                ((bld_py_sound_t *)self)->sound
                        )
                );

        if (!strcmp(attr_name, "Name"))
                return PyString_FromString(
                        GetSoundStringProperty(
                                SND_STR_NAME,
                                ((bld_py_sound_t *)self)->sound
                        )
                );

        if (!strcmp(attr_name, "Volume"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_VOLUME,
                                ((bld_py_sound_t *)self)->sound
                        )
                );

        if (!strcmp(attr_name, "BaseVolume"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_BASE_VOLUME,
                                ((bld_py_sound_t *)self)->sound
                        )
                );

        if (!strcmp(attr_name, "Pitch"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_PITCH,
                                ((bld_py_sound_t *)self)->sound
                        )
                );

        if (!strcmp(attr_name, "Scale")) {
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_SCALE,
                                ((bld_py_sound_t *)self)->sound
                        )
                );
        }

        if (!strcmp(attr_name, "SendNotify")) {
                return PyFloat_FromDouble(/*FIXME Maybe should be int property*/
                        GetSoundFloatProperty(
                                SND_INT_SEND_NOTIFY,
                                ((bld_py_sound_t *)self)->sound
                        )
                );
        }

        return Py_FindMethod(sound_methods, self, attr_name);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10018624
*/

int bld_py_sound_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        double min_distance, max_distance, volume, base_volume, pitch, scale;
        int send_notify;

        PyErr_Clear();
        if (!bld_py_sound_check(self)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                return -1;
        }

        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete sound attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "MinDistance")) {
                if (!PyArg_Parse(value, "d", &min_distance)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_MIN_DISTANCE, ((bld_py_sound_t *)self)->sound,
                        min_distance
                );
                return 0;
        }

        if (!strcmp(attr_name, "MaxDistance")) {
                if (!PyArg_Parse(value, "d", &max_distance)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_MAX_DISTANCE, ((bld_py_sound_t *)self)->sound,
                        max_distance
                );
                return 0;
        }

        if (!strcmp(attr_name, "Volume")) {
                if (!PyArg_Parse(value, "d", &volume)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_VOLUME, ((bld_py_sound_t *)self)->sound,
                        volume
                );
                return 0;
        }

        if (!strcmp(attr_name, "BaseVolume")) {
                if (!PyArg_Parse(value, "d", &base_volume)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_BASE_VOLUME, ((bld_py_sound_t *)self)->sound,
                        base_volume
                );
                return 0;
        }

        if (!strcmp(attr_name, "Pitch")) {
                if (!PyArg_Parse(value, "d", &pitch)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_PITCH, ((bld_py_sound_t *)self)->sound, pitch
                );
                return 0;
        }

        if (!strcmp(attr_name, "Scale")) {
                if (!PyArg_Parse(value, "d", &scale)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_SCALE, ((bld_py_sound_t *)self)->sound, scale
                );
                return 0;
        }

        if (!strcmp(attr_name, "SendNotify")) {
                if (!PyArg_Parse(value, "i", &send_notify)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundIntProperty(
                        SND_INT_SEND_NOTIFY, ((bld_py_sound_t *)self)->sound,
                        send_notify
                );
                return 0;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}

