#include <AnalyticGeometry/Matrix.h>

#include <bld_system.h>
#include <AnalyticGeometry/Vector.h>
#include <AnalyticGeometry/Plane.h>
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
* Module:                 rOpenGL.dll
* Entry point:            0x10003A77
* Module:                 Blade.exe
* Entry point:            0x00405227
* VC++ mangling:          ??0B_Matrix@@QAE@ABVB_Plane@@@Z
*/

B_Matrix::B_Matrix(const B_Plane &plane)
{
    this->m[0][0] = 1.0 - 2.0 * plane.normal.x * plane.normal.x;
    this->m[1][0] = -2.0 * plane.normal.x * plane.normal.y;
    this->m[2][0] = -2.0 * plane.normal.x * plane.normal.z;
    this->m[3][0] = -2.0 * plane.normal.x * plane.p;
    this->m[0][1] = -2.0 * plane.normal.y * plane.normal.x;
    this->m[1][1] = 1.0 - 2.0 * plane.normal.y * plane.normal.y;
    this->m[2][1] = -2.0 * plane.normal.y * plane.normal.z;
    this->m[3][1] = -2.0 * plane.normal.y * plane.p;
    this->m[0][2] = -2.0 * plane.normal.z * plane.normal.x;
    this->m[1][2] = -2.0 * plane.normal.z * plane.normal.y;
    this->m[2][2] = 1.0 - 2.0 * plane.normal.z * plane.normal.z;
    this->m[3][2] = -2.0 * plane.normal.z * plane.p;
    this->m[0][3] = 0.0;
    this->m[1][3] = 0.0;
    this->m[2][3] = 0.0;
    this->m[3][3] = 1.0;
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
* Module:                 rOpenGL.dll
* Entry point:            0x1000401C
* Module:                 Blade.exe
* Entry point:            0x004057CC
* VC++ mangling:          ?ScaleX@B_Matrix@@QBENXZ
*/

double B_Matrix::ScaleX() const
{
    return sqrt(
        this->m[0][0] * this->m[0][0] +
            this->m[0][1] * this->m[0][1] +
            this->m[0][2] * this->m[0][2]
    );
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10004052
* Module:                 Blade.exe
* Entry point:            0x00405802
* VC++ mangling:          ?ScaleY@B_Matrix@@QBENXZ
*/

double B_Matrix::ScaleY() const
{
    return sqrt(
        this->m[1][0] * this->m[1][0] +
            this->m[1][1] * this->m[1][1] +
            this->m[1][2] * this->m[1][2]
    );
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000408A
* Module:                 Blade.exe
* Entry point:            0x0040583A
* VC++ mangling:          ?ScaleZ@B_Matrix@@QBENXZ
*/

double B_Matrix::ScaleZ() const
{
    return sqrt(
        this->m[2][0] * this->m[2][0] +
            this->m[2][1] * this->m[2][1] +
            this->m[2][2] * this->m[2][2]
    );
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100040C2
* Module:                 Blade.exe
* Entry point:            0x00405872
* VC++ mangling:          ?SetScale@B_Matrix@@QAEXN@Z
*/

void B_Matrix::SetScale(double scale)
{
    double scaleX = this->ScaleX();
    double scaleY = this->ScaleY();
    double scaleZ = this->ScaleZ();
    double factorX = scale / scaleX;
    double factorY = scale / scaleY;
    double factorZ = scale / scaleZ;
    this->m[0][0] = factorX * this->m[0][0];
    this->m[0][1] = factorX * this->m[0][1];
    this->m[0][2] = factorX * this->m[0][2];
    this->m[1][0] = factorY * this->m[1][0];
    this->m[1][1] = factorY * this->m[1][1];
    this->m[1][2] = factorY * this->m[1][2];
    this->m[2][0] = factorZ * this->m[2][0];
    this->m[2][1] = factorZ * this->m[2][1];
    this->m[2][2] = factorZ * this->m[2][2];
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000423F
* Module:                 Blade.exe
* Entry point:            0x004059EF
* VC++ mangling:          ?RemoveScale@B_Matrix@@QAEXXZ
*/

void B_Matrix::RemoveScale()
{
    double scaleX = this->ScaleX();
    double scaleY = this->ScaleY();
    double scaleZ = this->ScaleZ();
    this->m[0][0] /= scaleX;
    this->m[0][1] /= scaleX;
    this->m[0][2] /= scaleX;
    this->m[1][0] /= scaleY;
    this->m[1][1] /= scaleY;
    this->m[1][2] /= scaleY;
    this->m[2][0] /= scaleZ;
    this->m[2][1] /= scaleZ;
    this->m[2][2] /= scaleZ;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100042F2
* Module:                 Blade.exe
* Entry point:            0x00405AA2
* VC++ mangling:          ?InvertRigid@B_Matrix@@QAEXAAV1@@Z
*/

void B_Matrix::InvertRigid(B_Matrix &out)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            out.m[i][j] = this->m[j][i];
        }
    }
    B_Vector translation(this->m[3][0], this->m[3][1], this->m[3][2]);
    translation = Rotate(translation, out);
    out.m[3][0] = -translation.x;
    out.m[3][1] = -translation.y;
    out.m[3][2] = -translation.z;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100043F9
* Module:                 Blade.exe
* Entry point:            0x00405BA9
* VC++ mangling:          ?Invert@B_Matrix@@QBE?AV1@XZ
*/

B_Matrix B_Matrix::Invert() const
{
    B_Matrix temp;
    double det =
        this->m[0][0] * this->m[1][1] * this->m[2][2] +
            this->m[0][1] * this->m[1][2] * this->m[2][0] +
            this->m[1][0] * this->m[2][1] * this->m[0][2] -
            this->m[0][2] * this->m[1][1] * this->m[2][0] -
            this->m[0][1] * this->m[1][0] * this->m[2][2] -
            this->m[1][2] * this->m[2][1] * this->m[0][0];
    temp.m[0][0] =
        (this->m[1][1] * this->m[2][2] - this->m[1][2] * this->m[2][1]) / det;
    temp.m[1][0] =
        -(this->m[1][0] * this->m[2][2] - this->m[1][2] * this->m[2][0]) / det;
    temp.m[2][0] =
        (this->m[1][0] * this->m[2][1] - this->m[1][1] * this->m[2][0]) / det;
    temp.m[0][1] =
        -(this->m[0][1] * this->m[2][2] - this->m[0][2] * this->m[2][1]) / det;
    temp.m[1][1] =
        (this->m[0][0] * this->m[2][2] - this->m[0][2] * this->m[2][0]) / det;
    temp.m[2][1] =
        -(this->m[0][0] * this->m[2][1] - this->m[0][1] * this->m[2][0]) / det;
    temp.m[0][2] =
        (this->m[0][1] * this->m[1][2] - this->m[0][2] * this->m[1][1]) / det;
    temp.m[1][2] =
        -(this->m[0][0] * this->m[1][2] - this->m[0][2] * this->m[1][0]) / det;
    temp.m[2][2] =
        (this->m[0][0] * this->m[1][1] - this->m[0][1] * this->m[1][0]) / det;
    B_Vector translation(this->m[3][0], this->m[3][1], this->m[3][2]);
    translation = Rotate(translation, temp);
    temp.m[3][0] = -translation.x;
    temp.m[3][1] = -translation.y;
    temp.m[3][2] = -translation.z;
    return temp;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000475D
* Module:                 Blade.exe
* Entry point:            0x00405F0D
* VC++ mangling:          ??8@YAHABVB_Matrix@@0@Z
*/

int operator ==(const B_Matrix &a, const B_Matrix &b)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (fabs(a.m[i][j] - b.m[i][j]) > 0.001)
            {
                return 0;
            }
        }
    }
    return 1;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100047D7
* Module:                 Blade.exe
* Entry point:            0x00405F87
* VC++ mangling:          ??D@YA?AVB_Matrix@@ABV0@0@Z
*/

B_Matrix operator *(const B_Matrix &a, const B_Matrix &b)
{
    B_Matrix result;
    result.m[0][0] =
        a.m[0][0] * b.m[0][0] +
            a.m[0][1] * b.m[1][0] +
            a.m[0][2] * b.m[2][0] +
            a.m[0][3] * b.m[3][0];
    result.m[0][1] =
        a.m[0][0] * b.m[0][1] +
            a.m[0][1] * b.m[1][1] +
            a.m[0][2] * b.m[2][1] +
            a.m[0][3] * b.m[3][1];
    result.m[0][2] =
        a.m[0][0] * b.m[0][2] +
            a.m[0][1] * b.m[1][2] +
            a.m[0][2] * b.m[2][2] +
            a.m[0][3] * b.m[3][2];
    result.m[0][3] =
        a.m[0][0] * b.m[0][3] +
            a.m[0][1] * b.m[1][3] +
            a.m[0][2] * b.m[2][3] +
            a.m[0][3] * b.m[3][3];
    result.m[1][0] =
        a.m[1][0] * b.m[0][0] +
            a.m[1][1] * b.m[1][0] +
            a.m[1][2] * b.m[2][0] +
            a.m[1][3] * b.m[3][0];
    result.m[1][1] =
        a.m[1][0] * b.m[0][1] +
            a.m[1][1] * b.m[1][1] +
            a.m[1][2] * b.m[2][1] +
            a.m[1][3] * b.m[3][1];
    result.m[1][2] =
        a.m[1][0] * b.m[0][2] +
            a.m[1][1] * b.m[1][2] +
            a.m[1][2] * b.m[2][2] +
            a.m[1][3] * b.m[3][2];
    result.m[1][3] =
        a.m[1][0] * b.m[0][3] +
            a.m[1][1] * b.m[1][3] +
            a.m[1][2] * b.m[2][3] +
            a.m[1][3] * b.m[3][3];
    result.m[2][0] =
        a.m[2][0] * b.m[0][0] +
            a.m[2][1] * b.m[1][0] +
            a.m[2][2] * b.m[2][0] +
            a.m[2][3] * b.m[3][0];
    result.m[2][1] =
        a.m[2][0] * b.m[0][1] +
            a.m[2][1] * b.m[1][1] +
            a.m[2][2] * b.m[2][1] +
            a.m[2][3] * b.m[3][1];
    result.m[2][2] =
        a.m[2][0] * b.m[0][2] +
            a.m[2][1] * b.m[1][2] +
            a.m[2][2] * b.m[2][2] +
            a.m[2][3] * b.m[3][2];
    result.m[2][3] =
        a.m[2][0] * b.m[0][3] +
            a.m[2][1] * b.m[1][3] +
            a.m[2][2] * b.m[2][3] +
            a.m[2][3] * b.m[3][3];
    result.m[3][0] =
        a.m[3][0] * b.m[0][0] +
            a.m[3][1] * b.m[1][0] +
            a.m[3][2] * b.m[2][0] +
            a.m[3][3] * b.m[3][0];
    result.m[3][1] =
        a.m[3][0] * b.m[0][1] +
            a.m[3][1] * b.m[1][1] +
            a.m[3][2] * b.m[2][1] +
            a.m[3][3] * b.m[3][1];
    result.m[3][2] =
        a.m[3][0] * b.m[0][2] +
            a.m[3][1] * b.m[1][2] +
            a.m[3][2] * b.m[2][2] +
            a.m[3][3] * b.m[3][2];
    result.m[3][3] =
        a.m[3][0] * b.m[0][3] +
            a.m[3][1] * b.m[1][3] +
            a.m[3][2] * b.m[2][3] +
            a.m[3][3] * b.m[3][3];
    return result;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10004B88
* Module:                 Blade.exe
* Entry point:            0x00406338
* VC++ mangling:          ?MulRot@@YA?AVB_Matrix@@ABV1@0@Z
*/

B_Matrix MulRot(const B_Matrix &a, const B_Matrix &b)
{
    B_Matrix result;
    result.m[0][0] =
        a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0];
    result.m[0][1] =
        a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1];
    result.m[0][2] =
        a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2];
    result.m[0][3] = a.m[0][3];
    result.m[1][0] =
        a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0];
    result.m[1][1] =
        a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1];
    result.m[1][2] =
        a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2];
    result.m[1][3] = a.m[1][3];
    result.m[2][0] =
        a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0];
    result.m[2][1] =
        a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1];
    result.m[2][2] =
        a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2];
    result.m[2][3] = a.m[2][3];
    result.m[3][0] = a.m[3][0];
    result.m[3][1] = a.m[3][1];
    result.m[3][2] = a.m[3][2];
    result.m[3][3] = a.m[3][3];
    return result;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10004D97
* Module:                 Blade.exe
* Entry point:            0x00406547
* VC++ mangling:          ?MatrixMultiply@@YAXAAVB_Matrix@@ABV1@1@Z
*/

void MatrixMultiply(B_Matrix &out, const B_Matrix &a, const B_Matrix &b)
{
    out.m[0][0] =
        a.m[0][0] * b.m[0][0] +
            a.m[0][1] * b.m[1][0] +
            a.m[0][2] * b.m[2][0] +
            a.m[0][3] * b.m[3][0];
    out.m[0][1] =
        a.m[0][0] * b.m[0][1] +
            a.m[0][1] * b.m[1][1] +
            a.m[0][2] * b.m[2][1] +
            a.m[0][3] * b.m[3][1];
    out.m[0][2] =
        a.m[0][0] * b.m[0][2] +
            a.m[0][1] * b.m[1][2] +
            a.m[0][2] * b.m[2][2] +
            a.m[0][3] * b.m[3][2];
    out.m[0][3] =
        a.m[0][0] * b.m[0][3] +
            a.m[0][1] * b.m[1][3] +
            a.m[0][2] * b.m[2][3] +
            a.m[0][3] * b.m[3][3];
    out.m[1][0] =
        a.m[1][0] * b.m[0][0] +
            a.m[1][1] * b.m[1][0] +
            a.m[1][2] * b.m[2][0] +
            a.m[1][3] * b.m[3][0];
    out.m[1][1] =
        a.m[1][0] * b.m[0][1] +
            a.m[1][1] * b.m[1][1] +
            a.m[1][2] * b.m[2][1] +
            a.m[1][3] * b.m[3][1];
    out.m[1][2] =
        a.m[1][0] * b.m[0][2] +
            a.m[1][1] * b.m[1][2] +
            a.m[1][2] * b.m[2][2] +
            a.m[1][3] * b.m[3][2];
    out.m[1][3] =
        a.m[1][0] * b.m[0][3] +
            a.m[1][1] * b.m[1][3] +
            a.m[1][2] * b.m[2][3] +
            a.m[1][3] * b.m[3][3];
    out.m[2][0] =
        a.m[2][0] * b.m[0][0] +
            a.m[2][1] * b.m[1][0] +
            a.m[2][2] * b.m[2][0] +
            a.m[2][3] * b.m[3][0];
    out.m[2][1] =
        a.m[2][0] * b.m[0][1] +
            a.m[2][1] * b.m[1][1] +
            a.m[2][2] * b.m[2][1] +
            a.m[2][3] * b.m[3][1];
    out.m[2][2] =
        a.m[2][0] * b.m[0][2] +
            a.m[2][1] * b.m[1][2] +
            a.m[2][2] * b.m[2][2] +
            a.m[2][3] * b.m[3][2];
    out.m[2][3] =
        a.m[2][0] * b.m[0][3] +
            a.m[2][1] * b.m[1][3] +
            a.m[2][2] * b.m[2][3] +
            a.m[2][3] * b.m[3][3];
    out.m[3][0] =
        a.m[3][0] * b.m[0][0] +
            a.m[3][1] * b.m[1][0] +
            a.m[3][2] * b.m[2][0] +
            a.m[3][3] * b.m[3][0];
    out.m[3][1] =
        a.m[3][0] * b.m[0][1] +
            a.m[3][1] * b.m[1][1] +
            a.m[3][2] * b.m[2][1] +
            a.m[3][3] * b.m[3][1];
    out.m[3][2] =
        a.m[3][0] * b.m[0][2] +
            a.m[3][1] * b.m[1][2] +
            a.m[3][2] * b.m[2][2] +
            a.m[3][3] * b.m[3][2];
    out.m[3][3] =
        a.m[3][0] * b.m[0][3] +
            a.m[3][1] * b.m[1][3] +
            a.m[3][2] * b.m[2][3] +
            a.m[3][3] * b.m[3][3];
}


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
* Module:                 rOpenGL.dll
* Entry point:            0x100053F7
* Module:                 Blade.exe
* Entry point:            0x00406BA7
* VC++ mangling:          ?TransformPlane@@YAXAAVB_Plane@@ABV1@ABVB_Matrix@@@Z
*/

void TransformPlane(B_Plane &out, const B_Plane &in, const B_Matrix &matrix)
{
    out.normal.x =
        in.normal.x * matrix.m[0][0] +
            in.normal.y * matrix.m[1][0] +
            in.normal.z * matrix.m[2][0];
    out.normal.y =
        in.normal.x * matrix.m[0][1] +
            in.normal.y * matrix.m[1][1] +
            in.normal.z * matrix.m[2][1];
    out.normal.z =
        in.normal.x * matrix.m[0][2] +
            in.normal.y * matrix.m[1][2] +
            in.normal.z * matrix.m[2][2];
    out.p =
        in.p -
            out.normal.x * matrix.m[3][0] -
            out.normal.y * matrix.m[3][1] -
            out.normal.z * matrix.m[3][2];
}


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
