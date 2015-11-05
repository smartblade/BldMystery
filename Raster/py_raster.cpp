
#include "raster_int.h"

static PyObject* raster_Cls(PyObject* self, PyObject* args);
static PyObject* raster_SwapBuffers(PyObject* self, PyObject* args);
static PyObject* raster_BmpHandle(PyObject* self, PyObject* args);
static PyObject* raster_BmpName(PyObject* self, PyObject* args);
static PyObject* raster_nTextures(PyObject* self, PyObject* args);
static PyObject* raster_GetTextureInfo(PyObject* self, PyObject* args);
static PyObject* add_item(PyObject *tuple, PyObject *item);
static PyObject* raster_SetGammaCorrection(PyObject* self, PyObject* args);
static PyObject* raster_GetGammaCorrection(PyObject* self, PyObject* args);
static PyObject* raster_SetContrast(PyObject* self, PyObject* args);
static PyObject* raster_GetContrast(PyObject* self, PyObject* args);
static PyObject* raster_SetBrightness(PyObject* self, PyObject* args);
static PyObject* raster_GetBrightness(PyObject* self, PyObject* args);
static PyObject* raster_SetVideoSettings(PyObject* self, PyObject* args);
static PyObject* raster_SetFlags(PyObject* self, PyObject* args);
static PyObject* raster_SetTextMode(PyObject* self, PyObject* args);
static PyObject* raster_GetTextMode(PyObject* self, PyObject* args);
static PyObject* raster_Line(PyObject* self, PyObject* args);
static PyObject* raster_LineTo(PyObject* self, PyObject* args);
static PyObject* raster_Rectangle(PyObject* self, PyObject* args);
static PyObject* raster_SolidRectangle(PyObject* self, PyObject* args);
static PyObject* raster_SetPosition(PyObject* self, PyObject* args);
static PyObject* raster_GetPosition(PyObject* self, PyObject* args);
static PyObject* raster_SetPenColor(PyObject* self, PyObject* args);
static PyObject* raster_SetFillColor(PyObject* self, PyObject* args);
static PyObject* raster_SetAlpha(PyObject* self, PyObject* args);
static PyObject* raster_GetAlpha(PyObject* self, PyObject* args);
static PyObject* raster_SetTextShadow(PyObject* self, PyObject* args);
static PyObject* raster_GetTextShadow(PyObject* self, PyObject* args);
static PyObject* raster_SetTextColor(PyObject* self, PyObject* args);
static PyObject* raster_SetTextAlpha(PyObject* self, PyObject* args);
static PyObject* raster_SetTextBlurColor(PyObject* self, PyObject* args);
static PyObject* raster_SetTextBlurAlpha(PyObject* self, PyObject* args);
static PyObject* raster_GetTextAlpha(PyObject* self, PyObject* args);
static PyObject* raster_GetTextBlurAlpha(PyObject* self, PyObject* args);
static PyObject* raster_SetTextBlur(PyObject* self, PyObject* args);
static PyObject* raster_GetTextBlur(PyObject* self, PyObject* args);
static PyObject* raster_SetTextScale(PyObject* self, PyObject* args);
static PyObject* raster_GetTextScale(PyObject* self, PyObject* args);
static PyObject* raster_WriteText(PyObject* self, PyObject* args);
static PyObject* raster_SysWrite(PyObject* self, PyObject* args);
static PyObject* raster_GetImage(PyObject* self, PyObject* args);
static PyObject* raster_DrawImage(PyObject* self, PyObject* args);
static PyObject* raster_DrawBitmap(PyObject* self, PyObject* args);
static PyObject* raster_SetBackgroundImage(PyObject* self, PyObject* args);
static PyObject* raster_RemoveBackgroundImage(PyObject* self, PyObject* args);
static PyObject* raster_SetClipWindow(PyObject* self, PyObject* args);
static PyObject* raster_GetClipWindow(PyObject* self, PyObject* args);
static PyObject* raster_SetClipActive(PyObject* self, PyObject* args);
static PyObject* raster_GetClipActive(PyObject* self, PyObject* args);
static PyObject* raster_SetRasterParameter(PyObject* self, PyObject* args);
static PyObject* raster_GetRasterParameter(PyObject* self, PyObject* args);
static PyObject* raster_SetFont(PyObject* self, PyObject* args);
static PyObject* raster_GetSize(PyObject* self, PyObject* args);
static PyObject* raster_SetWindowSize(PyObject* self, PyObject* args);
static PyObject* raster_GetWindowSize(PyObject* self, PyObject* args);
static PyObject* raster_FullScreen(PyObject* self, PyObject* args);
static PyObject* raster_nVideoModes(PyObject* self, PyObject* args);
static PyObject* raster_GetVideoModeDscr(PyObject* self, PyObject* args);
static PyObject* raster_SetVideoMode(PyObject* self, PyObject* args);
static PyObject* raster_GetCurrentMode(PyObject* self, PyObject* args);
static PyObject* raster_ClassIdName(PyObject* self, PyObject* args);
static PyObject* raster_SetDomeColor(PyObject* self, PyObject* args);
static PyObject* raster_GetDomeColor(PyObject* self, PyObject* args);
static PyObject* raster_UnifyRenderBuffers(PyObject* self, PyObject* args);


static PyMethodDef methods[] = {
    { "UnifyRenderBuffers",             raster_UnifyRenderBuffers,             METH_VARARGS, NULL },
    { "GetDomeColor",                   raster_GetDomeColor,                   METH_VARARGS, NULL },
    { "SetDomeColor",                   raster_SetDomeColor,                   METH_VARARGS, NULL },
    { "ClassIdName",                    raster_ClassIdName,                    METH_VARARGS, NULL },
    { "GetCurrentMode",                 raster_GetCurrentMode,                 METH_VARARGS, NULL },
    { "SetVideoMode",                   raster_SetVideoMode,                   METH_VARARGS, NULL },
    { "GetVideoModeDscr",               raster_GetVideoModeDscr,               METH_VARARGS, NULL },
    { "nVideoModes",                    raster_nVideoModes,                    METH_VARARGS, NULL },
    { "FullScreen",                     raster_FullScreen,                     METH_VARARGS, NULL },
    { "GetWindowSize",                  raster_GetWindowSize,                  METH_VARARGS, NULL },
    { "SetWindowSize",                  raster_SetWindowSize,                  METH_VARARGS, NULL },
    { "GetSize",                        raster_GetSize,                        METH_VARARGS, NULL },
    { "SetFont",                        raster_SetFont,                        METH_VARARGS, NULL },
    { "GetRasterParameter",             raster_GetRasterParameter,             METH_VARARGS, NULL },
    { "SetRasterParameter",             raster_SetRasterParameter,             METH_VARARGS, NULL },
    { "GetClipActive",                  raster_GetClipActive,                  METH_VARARGS, NULL },
    { "SetClipActive",                  raster_SetClipActive,                  METH_VARARGS, NULL },
    { "GetClipWindow",                  raster_GetClipWindow,                  METH_VARARGS, NULL },
    { "SetClipWindow",                  raster_SetClipWindow,                  METH_VARARGS, NULL },
    { "RemoveBackgroundImage",          raster_RemoveBackgroundImage,          METH_VARARGS, NULL },
    { "SetBackgroundImage",             raster_SetBackgroundImage,             METH_VARARGS, NULL },
    { "DrawBitmap",                     raster_DrawBitmap,                     METH_VARARGS, NULL },
    { "DrawImage",                      raster_DrawImage,                      METH_VARARGS, NULL },
    { "GetImage",                       raster_GetImage,                       METH_VARARGS, NULL },
    { "SysWrite",                       raster_SysWrite,                       METH_VARARGS, NULL },
    { "WriteText",                      raster_WriteText,                      METH_VARARGS, NULL },
    { "GetTextScale",                   raster_GetTextScale,                   METH_VARARGS, NULL },
    { "SetTextScale",                   raster_SetTextScale,                   METH_VARARGS, NULL },
    { "GetTextBlur",                    raster_GetTextBlur,                    METH_VARARGS, NULL },
    { "SetTextBlur",                    raster_SetTextBlur,                    METH_VARARGS, NULL },
    { "GetTextBlurAlpha",               raster_GetTextBlurAlpha,               METH_VARARGS, NULL },
    { "GetTextAlpha",                   raster_GetTextAlpha,                   METH_VARARGS, NULL },
    { "SetTextBlurAlpha",               raster_SetTextBlurAlpha,               METH_VARARGS, NULL },
    { "SetTextBlurColor",               raster_SetTextBlurColor,               METH_VARARGS, NULL },
    { "SetTextAlpha",                   raster_SetTextAlpha,                   METH_VARARGS, NULL },
    { "SetTextColor",                   raster_SetTextColor,                   METH_VARARGS, NULL },
    { "GetTextShadow",                  raster_GetTextShadow,                  METH_VARARGS, NULL },
    { "SetTextShadow",                  raster_SetTextShadow,                  METH_VARARGS, NULL },
    { "GetAlpha",                       raster_GetAlpha,                       METH_VARARGS, NULL },
    { "SetAlpha",                       raster_SetAlpha,                       METH_VARARGS, NULL },
    { "SetFillColor",                   raster_SetFillColor,                   METH_VARARGS, NULL },
    { "SetPenColor",                    raster_SetPenColor,                    METH_VARARGS, NULL },
    { "GetPosition",                    raster_GetPosition,                    METH_VARARGS, NULL },
    { "SetPosition",                    raster_SetPosition,                    METH_VARARGS, NULL },
    { "SolidRectangle",                 raster_SolidRectangle,                 METH_VARARGS, NULL },
    { "Rectangle",                      raster_Rectangle,                      METH_VARARGS, NULL },
    { "LineTo",                         raster_LineTo,                         METH_VARARGS, NULL },
    { "Line",                           raster_Line,                           METH_VARARGS, NULL },
    { "GetTextMode",                    raster_GetTextMode,                    METH_VARARGS, NULL },
    { "SetTextMode",                    raster_SetTextMode,                    METH_VARARGS, NULL },
    { "SetFlags",                       raster_SetFlags,                       METH_VARARGS, NULL },
    { "SetVideoSettings",               raster_SetVideoSettings,               METH_VARARGS, NULL },
    { "GetBrightness",                  raster_GetBrightness,                  METH_VARARGS, NULL },
    { "SetBrightness",                  raster_SetBrightness,                  METH_VARARGS, NULL },
    { "GetContrast",                    raster_GetContrast,                    METH_VARARGS, NULL },
    { "SetContrast",                    raster_SetContrast,                    METH_VARARGS, NULL },
    { "GetGammaCorrection",             raster_GetGammaCorrection,             METH_VARARGS, NULL },
    { "SetGammaCorrection",             raster_SetGammaCorrection,             METH_VARARGS, NULL },
    { "GetTextureInfo",                 raster_GetTextureInfo,                 METH_VARARGS, NULL },
    { "nTextures",                      raster_nTextures,                      METH_VARARGS, NULL },
    { "BmpName",                        raster_BmpName,                        METH_VARARGS, NULL },
    { "BmpHandle",                      raster_BmpHandle,                      METH_VARARGS, NULL },
    { "SwapBuffers",                    raster_SwapBuffers,                    METH_VARARGS, NULL },
    { "Cls",                            raster_Cls,                            METH_VARARGS, NULL },
    { NULL,                             NULL,                                  0,            NULL },
};

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Raster.dll
* Entry point:            0x100012FC
*/

PyObject *raster_Cls(PyObject *self, PyObject *args) {
        int unknown1, unknown2, unknown3;

        if (!PyArg_ParseTuple(args, "iii:Cls", &unknown1, &unknown2, &unknown3))
                return NULL;

        cls(unknown1, unknown2, unknown3);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001365
*/

PyObject *raster_SwapBuffers(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":SwapBuffers"))
                return NULL;

        swap_buffers();

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100013B1
*/

PyObject *raster_BmpHandle(PyObject *self, PyObject *args) {
        const char *bmp_name;
        long handle;

        if (!PyArg_ParseTuple(args, "s:BmpHandle", &bmp_name))
                return NULL;

        handle = bmp_handle(bmp_name);

        return Py_BuildValue("l", handle);
}


// TODO implement
// address: 0x10001406
PyObject* raster_BmpName(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000145b
PyObject* raster_nTextures(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100014a5
PyObject* raster_GetTextureInfo(PyObject* self, PyObject* args) {
        return NULL;
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000158A
*/

PyObject *add_item(PyObject *tuple, PyObject *item) {
        PyObject *obj1, *obj2;

        if (tuple == NULL) {
                tuple = item;
        } else if (tuple == Py_None) {
                Py_DECREF(Py_None);
                tuple = item;
        } else {
                if (!PyTuple_Check(tuple)) {
                        obj1 = tuple;
                        tuple = PyTuple_New(1);
                        PyTuple_SetItem(tuple, 0, obj1);
                }

                obj2 = PyTuple_New(1);
                PyTuple_SetItem(obj2, 0, item);

                obj1 = tuple;
                tuple = PySequence_Concat(obj1, obj2);

                Py_DECREF(obj1);
                Py_DECREF(obj2);
        }

        return tuple;
}


// TODO implement
// address: 0x100016b1
PyObject* raster_SetGammaCorrection(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001709
PyObject* raster_GetGammaCorrection(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001755
PyObject* raster_SetContrast(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100017ad
PyObject* raster_GetContrast(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100017f9
PyObject* raster_SetBrightness(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001851
PyObject* raster_GetBrightness(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000189d
PyObject* raster_SetVideoSettings(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001906
PyObject* raster_SetFlags(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000195e
PyObject* raster_SetTextMode(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100019b6
PyObject* raster_GetTextMode(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001a00
PyObject* raster_Line(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001a70
PyObject* raster_LineTo(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001acf
PyObject* raster_Rectangle(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001b3f
PyObject* raster_SolidRectangle(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001baf
PyObject* raster_SetPosition(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001c0e
PyObject* raster_GetPosition(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001cc8
PyObject* raster_SetPenColor(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001d31
PyObject* raster_SetFillColor(PyObject* self, PyObject* args) {
        return NULL;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001D9A
*/

PyObject *raster_SetAlpha(PyObject *self, PyObject *args) {
        float alpha;

        if (!PyArg_ParseTuple(args, "f:SetAlpha", &alpha))
                return NULL;

        set_alpha(alpha);

        Py_INCREF(Py_None);
        return Py_None;
}


// TODO implement
// address: 0x10001df2
PyObject* raster_GetAlpha(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001e3e
PyObject* raster_SetTextShadow(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001e9d
PyObject* raster_GetTextShadow(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001f4a
PyObject* raster_SetTextColor(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10001fb3
PyObject* raster_SetTextAlpha(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000200b
PyObject* raster_SetTextBlurColor(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002074
PyObject* raster_SetTextBlurAlpha(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100020cc
PyObject* raster_GetTextAlpha(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002118
PyObject* raster_GetTextBlurAlpha(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002164
PyObject* raster_SetTextBlur(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100021d4
PyObject* raster_GetTextBlur(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100022e3
PyObject* raster_SetTextScale(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002342
PyObject* raster_GetTextScale(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100023fc
PyObject* raster_WriteText(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002451
PyObject* raster_SysWrite(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100024d2
PyObject* raster_GetImage(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000255f
PyObject* raster_DrawImage(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100025d6
PyObject* raster_DrawBitmap(PyObject* self, PyObject* args) {
        return NULL;
}

/*
* Module:                 Raster.dll
* Entry point:            0x1000263F
*/

PyObject *raster_SetBackgroundImage(PyObject *self, PyObject *args) {
        int w, h;
        const char *is_rgb, *is_normal, *stretch_or_centered;
        long image_data;


        if (!PyArg_ParseTuple(
                args, "iisssl:SetBackgroundImage", &w, &h, &is_rgb, &is_normal,
                &stretch_or_centered, &image_data
        ))
                return NULL;

        set_background_image(w, h, is_rgb, is_normal, stretch_or_centered, image_data);

        Py_INCREF(Py_None);
        return Py_None;
}


// TODO implement
// address: 0x100026c0
PyObject* raster_RemoveBackgroundImage(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000270c
PyObject* raster_SetClipWindow(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000277c
PyObject* raster_GetClipWindow(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000288b
PyObject* raster_SetClipActive(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100028e3
PyObject* raster_GetClipActive(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000292d
PyObject* raster_SetRasterParameter(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x1000298a
PyObject* raster_GetRasterParameter(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100029df
PyObject* raster_SetFont(PyObject* self, PyObject* args) {
        return NULL;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002A37
*/

PyObject *raster_GetSize(PyObject *self, PyObject *args) {
        int w, h;
        PyObject *sizeObj, *wObj, *hObj;;

        if (!PyArg_ParseTuple(args, ":GetSize"))
                return NULL;

        get_size(w, h);

        Py_INCREF(Py_None);
        sizeObj = Py_None;

        wObj = PyInt_FromLong(w);

        sizeObj = add_item(sizeObj, wObj);

        hObj = PyInt_FromLong(h);

        sizeObj = add_item(sizeObj, hObj);

        return sizeObj;
}


// TODO implement
// address: 0x10002ae4
PyObject* raster_SetWindowSize(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002b4f
PyObject* raster_GetWindowSize(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002bfa
PyObject* raster_FullScreen(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002c44
PyObject* raster_nVideoModes(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002c8e
PyObject* raster_GetVideoModeDscr(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002dd1
PyObject* raster_SetVideoMode(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10002e26
PyObject* raster_GetCurrentMode(PyObject* self, PyObject* args) {
        return NULL;
}

/*
* Module:                 Raster.dll
* Entry point:            0x10002F61
*/

PyObject *raster_ClassIdName(PyObject *self, PyObject *args) {
        const char *name;

        if (!PyArg_ParseTuple(args, ":ClassIdName"))
                return NULL;

        name = class_id_name();

        return Py_BuildValue("s", name);
}


// TODO implement
// address: 0x10002fab
PyObject* raster_SetDomeColor(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x10003014
PyObject* raster_GetDomeColor(PyObject* self, PyObject* args) {
        return NULL;
}


// TODO implement
// address: 0x100030f5
PyObject* raster_UnifyRenderBuffers(PyObject* self, PyObject* args) {
        return NULL;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003141
*/

INIT_PY_MODULE_FUNC initRaster()
{
//TODO implement properly
        Py_InitModule("Raster", methods);
}
