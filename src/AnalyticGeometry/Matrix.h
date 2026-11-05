#ifndef MATRIX_H

#define MATRIX_H

class B_Vector;

class B_Matrix
{
public:
    B_Matrix();
    B_Matrix(double scale);
    B_Matrix(const B_Vector &v);
    B_Matrix(const B_Vector &axis, double angle);
    B_Vector TranslationVector() const;
    void SetOrigin(const B_Vector *origin);

    double m[4][4];
};

extern B_Vector operator *(const B_Vector& vector, const B_Matrix &matrix);
extern void TransformPoint(B_Vector &out, const B_Vector &v, const B_Matrix &matrix);
extern void Rotate(B_Vector &out, const B_Vector &v, const B_Matrix &rotateMatrix);
extern B_Vector Rotate(const B_Vector &v, const B_Matrix &rotateMatrix);

#endif