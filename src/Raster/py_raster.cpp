
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


/*
* Module:                 Raster.dll
* Entry point:            0x10001406
*/

PyObject *raster_BmpName(PyObject *self, PyObject *args) {
        long handle;
        const char *name;

        if (!PyArg_ParseTuple(args, "l:BmpName", &handle))
                return NULL;

        name = bmp_name(handle);

        return Py_BuildValue("s", name);
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000145B
*/

PyObject *raster_nTextures(PyObject *self, PyObject *args) {
        int num_textures;

        if (!PyArg_ParseTuple(args, ":nTextures"))
                return NULL;

        num_textures = n_textures();

        return Py_BuildValue("i", num_textures);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100014A5
*/

PyObject *raster_GetTextureInfo(PyObject *self, PyObject *args) {
        int index, code, w, h, depth;
        PyObject *infoObj, *wObj, *hObj, *depthObj;

        if (!PyArg_ParseTuple(args, "i:GetTextureInfo", &index))
                return NULL;

        code = get_texture_info(index, w, h, depth); 

        infoObj = Py_BuildValue("i", code);

        wObj = PyInt_FromLong(w);
        infoObj = add_item(infoObj, wObj);

        hObj = PyInt_FromLong(h);
        infoObj = add_item(infoObj, hObj);

        depthObj = PyInt_FromLong(depth);
        infoObj = add_item(infoObj, depthObj);

        return infoObj;
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


/*
* Module:                 Raster.dll
* Entry point:            0x100016B1
*/

PyObject *raster_SetGammaCorrection(PyObject *self, PyObject *args) {
        float gamma;

        if (!PyArg_ParseTuple(args, "f:SetGammaCorrection", &gamma))
                return NULL;

        set_gamma_correction(gamma);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001709
*/

PyObject *raster_GetGammaCorrection(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":GetGammaCorrection"))
                return NULL;

        return Py_BuildValue("f", get_gamma_correction());
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001755
*/

PyObject *raster_SetContrast(PyObject *self, PyObject *args) {
        float contrast;

        if (!PyArg_ParseTuple(args, "f:SetContrast", &contrast))
                return NULL;

        set_contrast(contrast);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100017AD
*/

PyObject *raster_GetContrast(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":GetContrast"))
                return NULL;

        return Py_BuildValue("f", get_contrast());
}


/*
* Module:                 Raster.dll
* Entry point:            0x100017F9
*/

PyObject *raster_SetBrightness(PyObject *self, PyObject *args) {
        float brightness;

        if (!PyArg_ParseTuple(args, "f:SetBrightness", &brightness))
                return NULL;

        set_brightness(brightness);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001851
*/

PyObject *raster_GetBrightness(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":GetBrightness"))
                return NULL;

        return Py_BuildValue("f", get_brightness());
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000189D
*/

PyObject *raster_SetVideoSettings(PyObject *self, PyObject *args) {
        float gamma, contrast, brightness;

        if (!PyArg_ParseTuple(
                args, "fff:SetVideoSettings", &gamma, &contrast, &brightness
        ))
                return NULL;

        SetVideoSettings(gamma, contrast, brightness);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001906
*/

PyObject *raster_SetFlags(PyObject *self, PyObject *args) {
        long flags;

        if (!PyArg_ParseTuple(args, "l:SetFlags", &flags))
                return NULL;

        set_flags(flags);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000195E
*/

PyObject *raster_SetTextMode(PyObject *self, PyObject *args) {
        int text_mode;

        if (!PyArg_ParseTuple(args, "i:SetTextMode", &text_mode))
                return NULL;

        SetTextMode(text_mode);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100019B6
*/

PyObject *raster_GetTextMode(PyObject *self, PyObject *args) {
        int text_mode;

        if (!PyArg_ParseTuple(args, ":GetTextMode"))
                return NULL;

        text_mode = GetTextMode();

        return Py_BuildValue("i", text_mode);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001A00
*/

PyObject *raster_Line(PyObject *self, PyObject *args) {
        int x1, y1, x2, y2;

        if (!PyArg_ParseTuple(args, "iiii:Line", &x1, &y1, &x2, &y2))
                return NULL;

        Line(x1, y1, x2, y2);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001A70
*/

PyObject *raster_LineTo(PyObject *self, PyObject *args) {
        int x, y;

        if (!PyArg_ParseTuple(args, "ii:LineTo", &x, &y))
                return NULL;

        LineTo(x, y);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001ACF
*/

PyObject *raster_Rectangle(PyObject *self, PyObject *args) {
        int x1, y1, x2, y2;

        if (!PyArg_ParseTuple(args, "iiii:Rectangle", &x1, &y1, &x2, &y2))
                return NULL;

        Rectangle(x1, y1, x2, y2);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001B3F
*/

PyObject *raster_SolidRectangle(PyObject *self, PyObject *args) {
        int x1, y1, x2, y2;

        if (!PyArg_ParseTuple(args, "iiii:SolidRectangle", &x1, &y1, &x2, &y2))
                return NULL;

        solid_rectangle(x1, y1, x2, y2);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001BAF
*/
 
PyObject *raster_SetPosition(PyObject *self, PyObject *args) {
        float x, y;

        if (!PyArg_ParseTuple(args, "ff:SetPosition", &x, &y))
                return NULL;

        SetPosition(x, y);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001C0E
*/

PyObject *raster_GetPosition(PyObject *self, PyObject *args) {
        PyObject *posObj, *xObj, *yObj;
        float x, y;

        if (!PyArg_ParseTuple(args, ":GetPosition"))
                return NULL;

        GetPosition(x, y);

        Py_INCREF(Py_None);
        posObj = Py_None;

        xObj = PyFloat_FromDouble(x);
        posObj = add_item(posObj, xObj);

        yObj = PyFloat_FromDouble(y);
        posObj = add_item(posObj, yObj);

        return posObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001CC8
*/

PyObject *raster_SetPenColor(PyObject *self, PyObject *args) {
        int r, g, b;

        if (!PyArg_ParseTuple(args, "iii:SetPenColor", &r, &g, &b))
                return NULL;

        set_pen_color(r, g, b);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001D31
*/

PyObject *raster_SetFillColor(PyObject *self, PyObject *args) {
        int r, g, b;

        if (!PyArg_ParseTuple(args, "iii:SetFillColor", &r, &g, &b))
                return NULL;

        set_fill_color(r, g, b);

        Py_INCREF(Py_None);
        return Py_None;
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


/*
* Module:                 Raster.dll
* Entry point:            0x10001DF2
*/

PyObject *raster_GetAlpha(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":GetAlpha"))
                return NULL;

        return Py_BuildValue("f", get_alpha());
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001E3E
*/

PyObject *raster_SetTextShadow(PyObject *self, PyObject *args) {
        int x_shadow, y_shadow;

        if (!PyArg_ParseTuple(args, "ii:SetTextShadow", &x_shadow, &y_shadow))
                return NULL;

        SetTextShadow(x_shadow, y_shadow);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001E9D
*/

PyObject *raster_GetTextShadow(PyObject *self, PyObject *args) {
        PyObject *shadowObj, *xShadowObj, *yShadowObj;
        int x_shadow, y_shadow;

        if (!PyArg_ParseTuple(args, ":GetTextShadow"))
                return NULL;

        GetTextShadow(x_shadow, y_shadow);

        Py_INCREF(Py_None);
        shadowObj = Py_None;

        xShadowObj = PyInt_FromLong(x_shadow);
        shadowObj = add_item(shadowObj, xShadowObj);

        yShadowObj = PyInt_FromLong(y_shadow);
        shadowObj = add_item(shadowObj, yShadowObj);

        return shadowObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001F4A
*/

PyObject *raster_SetTextColor(PyObject *self, PyObject *args) {
        int r, g, b;

        if (!PyArg_ParseTuple(args, "iii:SetTextColor", &r, &g, &b))
                return NULL;

        set_text_color(r, g, b);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10001FB3
*/

PyObject *raster_SetTextAlpha(PyObject *self, PyObject *args) {
        float alpha;

        if (!PyArg_ParseTuple(args, "f:SetTextAlpha", &alpha))
                return NULL;

        set_text_alpha(alpha);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000200B
*/

PyObject *raster_SetTextBlurColor(PyObject *self, PyObject *args) {
        int r, g, b;

        if (!PyArg_ParseTuple(args, "iii:SetTextBlurColor", &r, &g, &b))
                return NULL;

        set_text_blur_color(r, g, b);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002074
*/

PyObject *raster_SetTextBlurAlpha(PyObject *self, PyObject *args) {
        float alpha;

        if (!PyArg_ParseTuple(args, "f:SetTextBlurAlpha", &alpha))
                return NULL;

        set_text_blur_alpha(alpha);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100020CC
*/

PyObject *raster_GetTextAlpha(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":GetTextAlpha"))
                return NULL;

        return Py_BuildValue("f", get_text_alpha());
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002118
*/

PyObject *raster_GetTextBlurAlpha(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":GetTextBlurAlpha"))
                return NULL;

        return Py_BuildValue("f", get_text_blur_alpha());
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002164
*/

PyObject *raster_SetTextBlur(PyObject *self, PyObject *args) {
        int blurLeft, blurTop, blurRight, blurBottom;

        if (!PyArg_ParseTuple(
                args, "iiii:SetTextBlur", &blurLeft, &blurTop, &blurRight,
                &blurBottom
        ))
                return NULL;

        SetTextBlur(blurLeft, blurTop, blurRight, blurBottom);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100021D4
*/

PyObject *raster_GetTextBlur(PyObject *self, PyObject *args) {
        PyObject *textBlurObj;
        PyObject *blurLeftObj, *blurTopObj, *blurRightObj, *blurBottomObj;
        int blurLeft, blurTop, blurRight, blurBottom;

        if (!PyArg_ParseTuple(args, ":GetTextBlur"))
                return NULL;

        GetTextBlur(blurLeft, blurTop, blurRight, blurBottom);

        Py_INCREF(Py_None);
        textBlurObj = Py_None;

        blurLeftObj = PyInt_FromLong(blurLeft);
        textBlurObj = add_item(textBlurObj, blurLeftObj);

        blurTopObj = PyInt_FromLong(blurTop);
        textBlurObj = add_item(textBlurObj, blurTopObj);

        blurRightObj = PyInt_FromLong(blurRight);
        textBlurObj = add_item(textBlurObj, blurRightObj);

        blurBottomObj = PyInt_FromLong(blurBottom);
        textBlurObj = add_item(textBlurObj, blurBottomObj);

        return textBlurObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100022E3
*/

PyObject *raster_SetTextScale(PyObject *self, PyObject *args) {
        float scale_x, scale_y;

        if (!PyArg_ParseTuple(args, "ff:SetTextScale", &scale_x, &scale_y))
                return NULL;

        SetTextScale(scale_x, scale_y);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002342
*/

PyObject *raster_GetTextScale(PyObject *self, PyObject *args) {
        PyObject *textScaleObj, *scaleXObj, *scaleYObj;
        float scale_x, scale_y;

        if (!PyArg_ParseTuple(args, ":GetTextScale"))
                return NULL;

        GetTextScale(scale_x, scale_y);

        Py_INCREF(Py_None);
        textScaleObj = Py_None;

        scaleXObj = PyFloat_FromDouble(scale_x);
        textScaleObj = add_item(textScaleObj, scaleXObj);

        scaleYObj = PyFloat_FromDouble(scale_y);
        textScaleObj = add_item(textScaleObj, scaleYObj);

        return textScaleObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100023FC
*/

PyObject *raster_WriteText(PyObject *self, PyObject *args) {
        const char *text;
        int code;

        if (!PyArg_ParseTuple(args, "s:WriteText", &text))
                return NULL;

        code = write_text(text);

        return Py_BuildValue("i", code);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002451
*/

PyObject *raster_SysWrite(PyObject *self, PyObject *args) {
        int x, y;
        const char *text;
        byte r, g, b;

        if (!PyArg_ParseTuple(
                args, "iisbbb:SysWrite", &x, &y, &text, &r, &g, &b
        ))
                return NULL;

        SysWrite(x, y, text, r, g, b);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100024D2
*/

PyObject *raster_GetImage(PyObject *self, PyObject *args) {
        int x, y, w, h, image_size, code;
        char *color_style, *stretch_or_centered;
        long image_data;

        if (!PyArg_ParseTuple(
                args, "iiiissil:GetImage", &x, &y, &w, &h, &color_style,
                &stretch_or_centered, &image_size, &image_data
        ))
                return NULL;

        code = get_image(
                x, y, w, h, color_style, stretch_or_centered, image_size,
                image_data
        );

        return Py_BuildValue("i", code);
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000255F
*/
 
PyObject *raster_DrawImage(PyObject *self, PyObject *args) {
        int w, h;
        const char *color_style, *stretch_or_centered;
        void *image_data;

        if (!PyArg_ParseTuple(
                args, "iissl:DrawImage", &w, &h, &color_style,
                &stretch_or_centered, &image_data
        ))
                return NULL;

        draw_image(w, h, color_style, stretch_or_centered, image_data);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100025D6
*/

PyObject *raster_DrawBitmap(PyObject *self, PyObject *args) {
        long bmp_handle;
        int w, h;

        if (!PyArg_ParseTuple(args, "lii:DrawBitmap", &bmp_handle, &w, &h))
                return NULL;

        draw_bitmap(bmp_handle, w, h);

        Py_INCREF(Py_None);
        return Py_None;
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


/*
* Module:                 Raster.dll
* Entry point:            0x100026C0
*/
 
PyObject *raster_RemoveBackgroundImage(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":RemoveBackgroundImage"))
                return NULL;

        remove_background_image();

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000270C
*/

PyObject *raster_SetClipWindow(PyObject *self, PyObject *args) {
        int x, y, w, h;

        if (!PyArg_ParseTuple(args, "iiii:SetClipWindow", &x, &y, &w, &h))
                return NULL;

        set_clip_window(x, y, w, h);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000277C
*/

PyObject *raster_GetClipWindow(PyObject *self, PyObject *args) {
        PyObject *clipWindowObj, *xObj, *yObj, *wObj, *hObj;
        int x, y, w, h;

        if (!PyArg_ParseTuple(args, ":GetClipWindow"))
                return NULL;

        GetClipWindow(x, y, w, h);

        Py_INCREF(Py_None);
        clipWindowObj = Py_None;

        xObj = PyInt_FromLong(x);
        clipWindowObj = add_item(clipWindowObj, xObj);

        yObj = PyInt_FromLong(y);
        clipWindowObj = add_item(clipWindowObj, yObj);

        wObj = PyInt_FromLong(w);
        clipWindowObj = add_item(clipWindowObj, wObj);

        hObj = PyInt_FromLong(h);
        clipWindowObj = add_item(clipWindowObj, hObj);

        return clipWindowObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000288B
*/

PyObject *raster_SetClipActive(PyObject *self, PyObject *args) {
        int clip_active;

        if (!PyArg_ParseTuple(args, "i:SetClipActive", &clip_active))
                return NULL;

        set_clip_active(clip_active);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100028E3
*/

PyObject *raster_GetClipActive(PyObject *self, PyObject *args) {
        int clip_active;

        if (!PyArg_ParseTuple(args, ":GetClipActive"))
                return NULL;

        clip_active = GetClipActive();

        return Py_BuildValue("i", clip_active);
 }


/*
* Module:                 Raster.dll
* Entry point:            0x1000292D
*/
 
PyObject *raster_SetRasterParameter(PyObject *self, PyObject *args) {
        const char * parameter, *value;
        int code;

        if (!PyArg_ParseTuple(
                args, "ss:SetRasterParameter", &parameter, &value
        ))
                return NULL;

        code = SetRasterParameter(parameter, value);

        return Py_BuildValue("i", code);
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000298A
*/

PyObject *raster_GetRasterParameter(PyObject *self, PyObject *args) {
        const char *parameter, *value;

        if (!PyArg_ParseTuple(args, "s:GetRasterParameter", &parameter))
                return NULL;

        value = GetRasterParameter(parameter);

        return Py_BuildValue("s", value);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100029DF
*/

PyObject *raster_SetFont(PyObject *self, PyObject *args) {
        long font_pointer;

        if (!PyArg_ParseTuple(args, "l:SetFont", &font_pointer))
                return NULL;

        SetFont(font_pointer);

        Py_INCREF(Py_None);
        return Py_None;
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

        GetSize(w, h);

        Py_INCREF(Py_None);
        sizeObj = Py_None;

        wObj = PyInt_FromLong(w);

        sizeObj = add_item(sizeObj, wObj);

        hObj = PyInt_FromLong(h);

        sizeObj = add_item(sizeObj, hObj);

        return sizeObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002AE4
*/

PyObject *raster_SetWindowSize(PyObject *self, PyObject *args) {
        int w = -1, h = -1;
        int code;

        if (!PyArg_ParseTuple(args, "|ii:SetWindowSize", &w, &h))
                return NULL;

        code = set_window_size(w, h);

        return Py_BuildValue("i", code);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002B4F
*/

PyObject *raster_GetWindowSize(PyObject *self, PyObject *args) {
        int code, w, h;
        PyObject *sizeObj, *wObj, *hObj;

        if (!PyArg_ParseTuple(args, ":GetWindowSize"))
                return NULL;

        code = GetWindowSize(w, h);

        sizeObj = Py_BuildValue("i", code);

        wObj = PyInt_FromLong(w);
        sizeObj = add_item(sizeObj, wObj);

        hObj = PyInt_FromLong(h);
        sizeObj = add_item(sizeObj, hObj);

        return sizeObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002BFA
*/

PyObject *raster_FullScreen(PyObject *self, PyObject *args) {
        int code;

        if (!PyArg_ParseTuple(args, ":FullScreen"))
                return NULL;

        code = FullScreen();

        return Py_BuildValue("i", code);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002C44
*/

PyObject *raster_nVideoModes(PyObject *self, PyObject *args) {
        int num_modes;

        if (!PyArg_ParseTuple(args, ":nVideoModes"))
                return NULL;

        num_modes = n_video_modes();

        return Py_BuildValue("i", num_modes);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002C8E
*/

PyObject *raster_GetVideoModeDscr(PyObject *self, PyObject *args) {
        PyObject *modeDscrObj; 
        PyObject *depthObj, *wObj, *hObj, *unknownObj, *frequencyObj;
        int code, mode_index, depth, w, h, unknown, frequency;

        if (!PyArg_ParseTuple(args, "i:GetVideoModeDscr", &mode_index))
                return NULL;

        code = get_video_mode_dscr(
                mode_index, depth, w, h, unknown, frequency
        );

        modeDscrObj = Py_BuildValue("i", code);

        depthObj = PyInt_FromLong(depth);
        modeDscrObj = add_item(modeDscrObj, depthObj);

        wObj = PyInt_FromLong(w);
        modeDscrObj = add_item(modeDscrObj, wObj);

        hObj = PyInt_FromLong(h);
        modeDscrObj = add_item(modeDscrObj, hObj);

        unknownObj = PyInt_FromLong(unknown);
        modeDscrObj = add_item(modeDscrObj, unknownObj);

        frequencyObj = PyInt_FromLong(frequency);
        modeDscrObj = add_item(modeDscrObj, frequencyObj);

        return modeDscrObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002DD1
*/

PyObject *raster_SetVideoMode(PyObject *self, PyObject *args) {
        int mode_index, code;

        if (!PyArg_ParseTuple(args, "i:SetVideoMode", &mode_index))
                return NULL;

        code = set_video_mode(mode_index);

        return Py_BuildValue("i", code);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10002E26
*/

PyObject *raster_GetCurrentMode(PyObject *self, PyObject *args) {
        PyObject *curModeObj, *unknown1Obj, *wObj, *hObj;
        PyObject *unknown4Obj, *unknown5Obj;
        int unknown1, w, h, unknown4, unknown5;
        int code;

        if (!PyArg_ParseTuple(args, ":GetCurrentMode"))
                return NULL;

        code = GetCurrentMode(
                unknown1, w, h, unknown4, unknown5
        );

        curModeObj = Py_BuildValue("i", code);

        unknown1Obj = PyInt_FromLong(unknown1);
        curModeObj = add_item(curModeObj, unknown1Obj);

        wObj = PyInt_FromLong(w);
        curModeObj = add_item(curModeObj, wObj);

        hObj = PyInt_FromLong(h);
        curModeObj = add_item(curModeObj, hObj);

        unknown4Obj = PyInt_FromLong(unknown4);
        curModeObj = add_item(curModeObj, unknown4Obj);

        unknown5Obj = PyInt_FromLong(unknown5);
        curModeObj = add_item(curModeObj, unknown5Obj);

        return curModeObj;
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


/*
* Module:                 Raster.dll
* Entry point:            0x10002FAB
*/

PyObject *raster_SetDomeColor(PyObject *self, PyObject *args) {
        int r, g, b;

        if (!PyArg_ParseTuple(args, "iii:SetDomeColor", &r, &g, &b))
                return NULL;

        SetDomeColor(r, g, b);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003014
*/

PyObject *raster_GetDomeColor(PyObject *self, PyObject *args) {
        PyObject *domeColorObj, *rObj, *gObj, *bObj;
        byte r, g, b;

        if (!PyArg_ParseTuple(args, ":GetDomeColor"))
                return NULL;

        GetDomeColor(r, g, b);

        Py_INCREF(Py_None);
        domeColorObj = Py_None;

        rObj = PyInt_FromLong(r);
        domeColorObj = add_item(domeColorObj, rObj);

        gObj = PyInt_FromLong(g);
        domeColorObj = add_item(domeColorObj, gObj);

        bObj = PyInt_FromLong(b);
        domeColorObj = add_item(domeColorObj, bObj);

        return domeColorObj;
}


/*
* Module:                 Raster.dll
* Entry point:            0x100030F5
*/

PyObject *raster_UnifyRenderBuffers(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ":UnifyRenderBuffers"))
                return NULL;

        UnifyRenderBuffers();

        Py_INCREF(Py_None);
        return Py_None;
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

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
