#ifndef MATRIX_H

#define MATRIX_H

class B_Vector;

class B_Matrix
{
public:
    B_Vector TranslationVector() const;
private:
    double v[4][4];
};

extern B_Vector operator *(const B_Vector& vector, const B_Matrix &matrix);

#endif