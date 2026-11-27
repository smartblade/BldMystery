#include <AnalyticGeometry/Matrix.h>

#include <bld_system.h>
#include <AnalyticGeometry/Vector.h>
#include <AnalyticGeometry/Plane.h>
#include <AnalyticGeometry/Quaternion.h>
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
* Module:                 BBLibc.dll
* Entry point:            0x1002E190
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
* Module:                 BBLibc.dll
* Entry point:            0x1002E2AD
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
* Module:                 BBLibc.dll
* Entry point:            0x1002E4DF
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
* Module:                 BBLibc.dll
* Entry point:            0x1002E600
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
* Module:                 BBLibc.dll
* Entry point:            0x1002E7D7
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
* Module:                 BBLibc.dll
* Entry point:            0x1002E95C
* Module:                 rOpenGL.dll
* Entry point:            0x10003BFC
* Module:                 Blade.exe
* Entry point:            0x004053AC
* VC++ mangling:          ??0B_Matrix@@QAE@ABVB_Quaternion@@@Z
*/

B_Matrix::B_Matrix(const B_Quaternion &q)
{
    if (q.w > 0.999999)
    {
        DEFINE_MATRIX(
            1.0, 0.0, 0.0, 0.0,
            0.0, 1.0, 0.0, 0.0,
            0.0, 0.0, 1.0, 0.0,
            0.0, 0.0, 0.0, 1.0
        )
    }
    else
    {
        double s = sqrt(q.x * q.x + q.y * q.y + q.z * q.z);
        double x = 1.0;
        double y = 0.0;
        double z = 0.0;
        if (s > 0.000001)
        {
            x = q.x / s;
            y = q.y / s;
            z = q.z / s;
        }
        double c = q.w * q.w - s * s;
        s = 2.0f * q.w * s;
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
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002ECCF
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
* Module:                 BBLibc.dll
* Entry point:            0x1002ED3A
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
* Module:                 BBLibc.dll
* Entry point:            0x1002ED7C
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
* Module:                 BBLibc.dll
* Entry point:            0x1002EDB2
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
* Module:                 BBLibc.dll
* Entry point:            0x1002EDEA
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
* Module:                 BBLibc.dll
* Entry point:            0x1002EE22
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
* Module:                 BBLibc.dll
* Entry point:            0x1002EF9F
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
* Module:                 BBLibc.dll
* Entry point:            0x1002F052
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
* Module:                 BBLibc.dll
* Entry point:            0x1002F159
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
* Module:                 BBLibc.dll
* Entry point:            0x1002F4BD
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
* Module:                 BBLibc.dll
* Entry point:            0x1002F537
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
* Module:                 BBLibc.dll
* Entry point:            0x1002F8E8
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
* Module:                 BBLibc.dll
* Entry point:            0x1002FAF7
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
* Module:                 BBLibc.dll
* Entry point:            0x1002FEB3
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
* Module:                 BBLibc.dll
* Entry point:            0x1002FF7B
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
* Module:                 BBLibc.dll
* Entry point:            0x10030017
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
* Module:                 BBLibc.dll
* Entry point:            0x100300A1
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
* Module:                 BBLibc.dll
* Entry point:            0x10030157
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
* Module:                 BBLibc.dll
* Entry point:            0x10030219
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
* Module:                 BBLibc.dll
* Entry point:            0x10030232
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
* Module:                 BBLibc.dll
* Entry point:            0x1003024B
* Module:                 rOpenGL.dll
* Entry point:            0x100054ED
* Module:                 Blade.exe
* Entry point:            0x00406C9D
* VC++ mangling:          ??0B_Quaternion@@QAE@ABVB_Vector@@N@Z
*/

B_Quaternion::B_Quaternion(const B_Vector &axis, double angle)
{
    double s = sin(angle / 2.0);
    double c = cos(angle / 2.0);
    this->w = c;
    this->x = s * axis.x;
    this->y = s * axis.y;
    this->z = s * axis.z;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100302B0
* Module:                 rOpenGL.dll
* Entry point:            0x10005552
* Module:                 Blade.exe
* Entry point:            0x00406D02
* VC++ mangling:          ??0B_Quaternion@@QAE@ABVB_Matrix@@@Z
*/

B_Quaternion::B_Quaternion(const B_Matrix &matrix)
{
    double c = (matrix.m[0][0] + matrix.m[1][1] + matrix.m[2][2] - 1.0) / 2.0;
    if (c > 0.9999)
    {
        this->w = 1.0f;
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
    }
    else if (c < -0.9999)
    {
        double s = 1.0;
        double x = sqrt(
            (matrix.m[0][0] + 1.0) / 2.0 > 0.0 ?
                (matrix.m[0][0] + 1.0) / 2.0 :
                0.0
        );
        double z = sqrt(
            (matrix.m[2][2] + 1.0) / 2.0 > 0.0 ?
                (matrix.m[2][2] + 1.0) / 2.0 :
                0.0
        );
        double y = sqrt(
            matrix.m[1][1] + x * x + z * z > 0.0 ?
                matrix.m[1][1] + x * x + z * z :
                0.0
        );
        if (x > 0.000001)
        {
            if (matrix.m[2][0] + matrix.m[0][2] < 0.0)
            {
                z *= -1.0;
            }
            if (matrix.m[0][1] + matrix.m[1][0] < 0.0)
            {
                y *= -1.0;
            }
        }
        else
        {
            if (matrix.m[1][2] + matrix.m[2][1] < 0.0)
            {
                z *= -1.0;
            }
        }
        this->w = 0.0f;
        this->x = x * s;
        this->y = y * s;
        this->z = z * s;
        double length = sqrt(
            this->w * this->w +
            this->x * this->x +
            this->y * this->y +
            this->z * this->z
        );
        this->w /= length;
        this->x /= length;
        this->y /= length;
        this->z /= length;
    }
    else
    {
        double sinHalf = sqrt((1.0 - c) / 2.0);
        double s = sqrt(1.0 - c * c);
        double x = (matrix.m[1][2] - matrix.m[2][1]) / (2.0 * s);
        double y = (matrix.m[2][0] - matrix.m[0][2]) / (2.0 * s);
        double z = (matrix.m[0][1] - matrix.m[1][0]) / (2.0 * s);
        this->w = sqrt((1.0 + c) / 2.0);
        this->x = x * sinHalf;
        this->y = y * sinHalf;
        this->z = z * sinHalf;
        double length = sqrt(
            this->w * this->w +
            this->x * this->x +
            this->y * this->y +
            this->z * this->z
        );
        this->w /= length;
        this->x /= length;
        this->y /= length;
        this->z /= length;
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030684
* Module:                 rOpenGL.dll
* Entry point:            0x10005926
* Module:                 Blade.exe
* Entry point:            0x004070D6
* VC++ mangling:          ??0B_Quaternion@@QAE@MMMM@Z
*/

B_Quaternion::B_Quaternion(float w, float x, float y, float z)
{
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
    float length = sqrt(
        this->w * this->w +
        this->x * this->x +
        this->y * this->y +
        this->z * this->z
    );
    if (length > 0.000001)
    {
        this->w /= length;
        this->x /= length;
        this->y /= length;
        this->z /= length;
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003073F
* Module:                 rOpenGL.dll
* Entry point:            0x100059E1
* Module:                 Blade.exe
* Entry point:            0x00407191
* VC++ mangling:          ??0B_Quaternion@@QAE@ABV0@0M@Z
*/

B_Quaternion::B_Quaternion(
    const B_Quaternion &a,
    const B_Quaternion &b,
    float t
)
{
    float u = 1.0f - t;
    float difference =
        (a.w - b.w) * (a.w - b.w) +
        (a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y) +
        (a.z - b.z) * (a.z - b.z);
    float sum =
        (a.w + b.w) * (a.w + b.w) +
        (a.x + b.x) * (a.x + b.x) +
        (a.y + b.y) * (a.y + b.y) +
        (a.z + b.z) * (a.z + b.z);
    if (difference <= sum)
    {
        this->w = u * a.w + t * b.w;
        this->x = u * a.x + t * b.x;
        this->y = u * a.y + t * b.y;
        this->z = u * a.z + t * b.z;
    }
    else
    {
        this->w = u * a.w - t * b.w;
        this->x = u * a.x - t * b.x;
        this->y = u * a.y - t * b.y;
        this->z = u * a.z - t * b.z;
    }
    float length = sqrt(
        this->w * this->w +
        this->x * this->x +
        this->y * this->y +
        this->z * this->z
    );
    if (length > 0.000001)
    {
        this->w /= length;
        this->x /= length;
        this->y /= length;
        this->z /= length;
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030996
* Module:                 rOpenGL.dll
* Entry point:            0x10005C38
* Module:                 Blade.exe
* Entry point:            0x004073E8
* VC++ mangling:          ?GetMatrix@B_Quaternion@@QBEXAAVB_Matrix@@@Z
*/

void B_Quaternion::GetMatrix(B_Matrix &matrix) const
{
    if (this->w > 0.999999)
    {
        matrix = B_Matrix();
    }
    else
    {
        double s = sqrt(
            this->x * this->x + this->y * this->y + this->z * this->z
        );
        double x = 1.0;
        double y = 0.0;
        double z = 0.0;
        if (s > 0.000001)
        {
            x = this->x / s;
            y = this->y / s;
            z = this->z / s;
        }
        double c = this->w * this->w - s * s;
        s = 2.0f * this->w * s;
        matrix.m[0][0] = x * x * (1.0 - c) + c;
        matrix.m[0][1] = x * y * (1.0 - c) + z * s;
        matrix.m[0][2] = x * z * (1.0 - c) - y * s;
        matrix.m[0][3] = 0.0;
        matrix.m[1][0] = x * y * (1.0 - c) - z * s;
        matrix.m[1][1] = y * y + (x * x + z * z) * c;
        matrix.m[1][2] = y * z * (1.0 - c) + x * s;
        matrix.m[1][3] = 0.0;
        matrix.m[2][0] = x * z * (1.0 - c) + y * s;
        matrix.m[2][1] = y * z * (1.0 - c) - x * s;
        matrix.m[2][2] = z * z * (1.0 - c) + c;
        matrix.m[2][3] = 0.0;
        matrix.m[3][0] = 0.0;
        matrix.m[3][1] = 0.0;
        matrix.m[3][2] = 0.0;
        matrix.m[3][3] = 1.0;
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030C3B
* Module:                 rOpenGL.dll
* Entry point:            0x10005EDD
* Module:                 Blade.exe
* Entry point:            0x0040768D
* VC++ mangling:          ??GB_Quaternion@@QBE?AV0@XZ
*/

B_Quaternion B_Quaternion::operator -() const
{
    B_Quaternion q;
    q.w = -this->w;
    q.x = -this->x;
    q.y = -this->y;
    q.z = -this->z;
    return q;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030C92
* Module:                 rOpenGL.dll
* Entry point:            0x10005F34
* Module:                 Blade.exe
* Entry point:            0x004076E4
* VC++ mangling:          ?SquaredDistance@B_Quaternion@@QBEMABV1@@Z
*/

float B_Quaternion::SquaredDistance(const B_Quaternion &q) const
{
    return
        (this->w - q.w) * (this->w - q.w) +
        (this->x - q.x) * (this->x - q.x) +
        (this->y - q.y) * (this->y - q.y) +
        (this->z - q.z) * (this->z - q.z);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030D09
* Module:                 rOpenGL.dll
* Entry point:            0x10005FAB
* Module:                 Blade.exe
* Entry point:            0x0040775B
* VC++ mangling:          ?Interpolate@B_Quaternion@@QAEXABV1@M0@Z
*/

void B_Quaternion::Interpolate(
    const B_Quaternion &a,
    float t,
    const B_Quaternion &b
)
{
    float u = 1.0f - t;
    this->w = t * a.w + u * b.w;
    this->x = t * a.x + u * b.x;
    this->y = t * a.y + u * b.y;
    this->z = t * a.z + u * b.z;
    float scale = 1.0 / sqrt(
        this->w * this->w +
        this->x * this->x +
        this->y * this->y +
        this->z * this->z
    );
    this->w = scale * this->w;
    this->x = scale * this->x;
    this->y = scale * this->y;
    this->z = scale * this->z;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030E05
* Module:                 rOpenGL.dll
* Entry point:            0x100060A7
* Module:                 Blade.exe
* Entry point:            0x00407857
* VC++ mangling:          ?Multiply@@YAAAVB_Quaternion@@AAV1@ABV1@1@Z
*/

B_Quaternion &Multiply(
    B_Quaternion &out,
    const B_Quaternion &a,
    const B_Quaternion &b
)
{
    out.w = b.w * a.w - b.x * a.x - b.y * a.y - b.z * a.z;
    out.x = b.w * a.x + b.x * a.w + b.y * a.z - b.z * a.y;
    out.y = b.w * a.y - b.x * a.z + b.y * a.w + b.z * a.x;
    out.z = b.w * a.z + b.x * a.y - b.y * a.x + b.z * a.w;
    return out;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030EF4
* Module:                 rOpenGL.dll
* Entry point:            0x10006196
* Module:                 Blade.exe
* Entry point:            0x00407946
* VC++ mangling:          ?SetTwist@B_Quaternion@@QAEXABVB_Vector@@@Z
*/

void B_Quaternion::SetTwist(const B_Vector &axis)
{
    double t = 1.0 / (
        (this->x * axis.x + this->y * axis.y + this->z * axis.z) / this->w *
        ((this->x * axis.x + this->y * axis.y + this->z * axis.z) / this->w) +
        1.0
    );
    double s = sqrt(1.0 - t);
    t = sqrt(t);
    this->w = t;
    this->x = s * axis.x;
    this->y = s * axis.y;
    this->z = s * axis.z;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030FB9
* Module:                 rOpenGL.dll
* Entry point:            0x1000625B
* Module:                 Blade.exe
* Entry point:            0x00407A0B
* VC++ mangling:          ?Conjugate@B_Quaternion@@QAEXXZ
*/

void B_Quaternion::Conjugate()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10030FEE
* Module:                 rOpenGL.dll
* Entry point:            0x10006290
* Module:                 Blade.exe
* Entry point:            0x00407A40
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Quaternion@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Quaternion &q)
{
    file >> q.w >> q.x >> q.y >> q.z;
    float length = sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
    q.w /= length;
    q.x /= length;
    q.y /= length;
    q.z /= length;
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100310AF
* Module:                 rOpenGL.dll
* Entry point:            0x10006355
* Module:                 Blade.exe
* Entry point:            0x00407B05
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Quaternion@@@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const B_Quaternion &q)
{
    return file << q.w << q.x << q.y << q.z;
}
