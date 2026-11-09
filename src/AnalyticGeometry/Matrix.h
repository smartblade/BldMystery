#ifndef MATRIX_H

#define MATRIX_H

class B_Vector;
class B_Plane;
class B_IDataFile;
class B_ODataFile;

class B_Matrix
{
public:
    B_Matrix();
    B_Matrix(double scale);
    B_Matrix(const B_Vector &v);
    B_Matrix(const B_Vector &axis, double angle);
    B_Matrix(const B_Plane &plane);
    B_Vector TranslationVector() const;
    void SetOrigin(const B_Vector *origin);
    double ScaleX() const;
    double ScaleY() const;
    double ScaleZ() const;
    void SetScale(double scale);
    void InvertRigid(B_Matrix &out);
    B_Matrix *Invert(B_Matrix *outMatrix) const;

    double m[4][4];
};

extern B_Matrix operator *(const B_Matrix &a, const B_Matrix &b);
extern B_Matrix MulRot_406338(const B_Matrix &a, const B_Matrix &b);
extern void MatrixMultiply(B_Matrix *out, const B_Matrix *a, const B_Matrix *b);
extern B_Vector operator *(const B_Vector &vector, const B_Matrix &matrix);
extern void TransformPoint(
    B_Vector &out,
    const B_Vector &v,
    const B_Matrix &matrix
);
extern void Rotate(
    B_Vector &out,
    const B_Vector &v,
    const B_Matrix &rotateMatrix
);
extern B_Vector Rotate(const B_Vector &v, const B_Matrix &rotateMatrix);
extern void TransformPlane(
    B_Plane &out,
    const B_Plane &in,
    const B_Matrix &matrix
);
extern B_IDataFile &operator >>(B_IDataFile &file, B_Matrix &matrix);
extern B_ODataFile &operator <<(B_ODataFile &file, const B_Matrix &matrix);

#endif
