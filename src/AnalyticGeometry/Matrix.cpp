#include <AnalyticGeometry/Matrix.h>

#include <bld_system.h>
#include <AnalyticGeometry/Vector.h>
#include <BBLibc/IDataFile.h>
#include <BBLibc/ODataFile.h>
#include <math.h>

#define DEFINE_MATRIX(\
    m11, m12, m13, m14,\
    m21, m22, m23, m24,\
    m31, m32, m33, m34,\
    m41, m42, m43, m44\
)\
    m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;\
    m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;\
    m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;\
    m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;\


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10003430
* Module:                 Blade.exe
* Entry point:            0x00404BE0
* VC++ mangling:          ??0B_Matrix@@QAE@XZ
*/

B_Matrix::B_Matrix()
{
    DEFINE_MATRIX(
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    )
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000354D
* Module:                 Blade.exe
* Entry point:            0x00404CFD
* VC++ mangling:          ??0B_Matrix@@QAE@N@Z
*/

B_Matrix::B_Matrix(double scale)
{
    DEFINE_MATRIX(
        scale, 0.0, 0.0, 0.0,
        0.0, scale, 0.0, 0.0,
        0.0, 0.0, scale, 0.0,
        0.0, 0.0, 0.0, 1.0
    )
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000377F
* Module:                 Blade.exe
* Entry point:            0x00404F2F
* VC++ mangling:          ??0B_Matrix@@QAE@ABVB_Vector@@@Z
*/

B_Matrix::B_Matrix(const B_Vector &v)
{
    DEFINE_MATRIX(
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        v.x, v.y, v.z, 1.0
    )
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100038A0
* Module:                 Blade.exe
* Entry point:            0x00405050
* VC++ mangling:          ??0B_Matrix@@QAE@ABVB_Vector@@N@Z
*/

B_Matrix::B_Matrix(const B_Vector &axis, double angle)
{
    double c = cos(angle);
    double s = sin(angle);
    double x = axis.x;
    double y = axis.y;
    double z = axis.z;
    DEFINE_MATRIX(
        x * x * (1.0 - c) + c,
        x * y * (1.0 - c) + z * s,
        x * z * (1.0 - c) - y * s,
        0.0,
        x * y * (1.0 - c) - z * s,
        y * y + (x * x + z * z) * c,
        y * z * (1.0 - c) + x * s,
        0.0,
        x * z * (1.0 - c) + y * s,
        y * z * (1.0 - c) - x * s,
        z * z * (1.0 - c) + c,
        0.0,
        0.0,
        0.0,
        0.0,
        1.0
    )
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10003F6F
* Module:                 Blade.exe
* Entry point:            0x0040571F
* VC++ mangling:          ?TranslationVector@B_Matrix@@QBE?AVB_Vector@@XZ
*/

B_Vector B_Matrix::TranslationVector() const
{
    return B_Vector(this->m[3][0], this->m[3][1], this->m[3][2]);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10003FDA
* Module:                 Blade.exe
* Entry point:            0x0040578A
* VC++ mangling:          ?SetOrigin@B_Matrix@@QAEXPBVB_Vector@@@Z
*/

void B_Matrix::SetOrigin(const B_Vector *origin)
{
    this->m[3][0] = origin->x;
    this->m[3][1] = origin->y;
    this->m[3][2] = origin->z;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10005153
* Module:                 Blade.exe
* Entry point:            0x00406903
* VC++ mangling:          ??D@YA?AVB_Vector@@ABV0@ABVB_Matrix@@@Z
*/

B_Vector operator *(const B_Vector &vector, const B_Matrix &matrix)
{
    return B_Vector(
        vector.x * matrix.m[0][0] +
            vector.y * matrix.m[1][0] +
            vector.z * matrix.m[2][0] +
            matrix.m[3][0],
        vector.x * matrix.m[0][1] +
            vector.y * matrix.m[1][1] +
            vector.z * matrix.m[2][1] +
            matrix.m[3][1],
        vector.x * matrix.m[0][2] +
            vector.y * matrix.m[1][2] +
            vector.z * matrix.m[2][2] +
            matrix.m[3][2]
    );
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000521B
* Module:                 Blade.exe
* Entry point:            0x004069CB
* VC++ mangling:          ?TransformPoint@@YAXAAVB_Vector@@ABV1@ABVB_Matrix@@@Z
*/

void TransformPoint(B_Vector &out, const B_Vector &v, const B_Matrix &matrix)
{
    out.x =
        v.x * matrix.m[0][0] +
            v.y * matrix.m[1][0] +
            v.z * matrix.m[2][0] +
            matrix.m[3][0];
    out.y =
        v.x * matrix.m[0][1] +
            v.y * matrix.m[1][1] +
            v.z * matrix.m[2][1] +
            matrix.m[3][1];
    out.z =
        v.x * matrix.m[0][2] +
            v.y * matrix.m[1][2] +
            v.z * matrix.m[2][2] +
            matrix.m[3][2];
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100052B7
* Module:                 Blade.exe
* Entry point:            0x00406A67
* VC++ mangling:          ?Rotate@@YAXAAVB_Vector@@ABV1@ABVB_Matrix@@@Z
*/

void Rotate(B_Vector &out, const B_Vector &v, const B_Matrix &rotateMatrix)
{
    out.x =
        v.x * rotateMatrix.m[0][0] +
            v.y * rotateMatrix.m[1][0] +
            v.z * rotateMatrix.m[2][0];
    out.y =
        v.x * rotateMatrix.m[0][1] +
            v.y * rotateMatrix.m[1][1] +
            v.z * rotateMatrix.m[2][1];
    out.z =
        v.x * rotateMatrix.m[0][2] +
            v.y * rotateMatrix.m[1][2] +
            v.z * rotateMatrix.m[2][2];
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10005341
* Module:                 Blade.exe
* Entry point:            0x00406AF1
* VC++ mangling:          ?Rotate@@YA?AVB_Vector@@ABV1@ABVB_Matrix@@@Z
*/

B_Vector Rotate(const B_Vector &v, const B_Matrix &rotateMatrix)
{
    return B_Vector(
        v.x * rotateMatrix.m[0][0] +
            v.y * rotateMatrix.m[1][0] +
            v.z * rotateMatrix.m[2][0],
        v.x * rotateMatrix.m[0][1] +
            v.y * rotateMatrix.m[1][1] +
            v.z * rotateMatrix.m[2][1],
        v.x * rotateMatrix.m[0][2] +
            v.y * rotateMatrix.m[1][2] +
            v.z * rotateMatrix.m[2][2]
    );
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100054B9
* Module:                 Blade.exe
* Entry point:            0x00406C69
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Matrix@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Matrix &matrix)
{
    file.Read(&matrix, sizeof(matrix));
    return file;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100054D3
* Module:                 Blade.exe
* Entry point:            0x00406C83
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Matrix@@@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const B_Matrix &matrix)
{
    file.Write(&matrix, sizeof(matrix));
    return file;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
