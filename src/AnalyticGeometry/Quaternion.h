
#ifndef QUATERNION_H

#define QUATERNION_H

class B_Vector;
class B_Matrix;
class B_IDataFile;
class B_ODataFile;

class B_Quaternion
{
public:
    B_Quaternion()
    {
    }

    B_Quaternion(const B_Vector &axis, double angle);
    B_Quaternion(const B_Matrix &matrix);
    B_Quaternion(float w, float x, float y, float z);
    B_Quaternion(const B_Quaternion &a, const B_Quaternion &b, float t);
    void GetMatrix(B_Matrix &matrix) const;
    B_Quaternion operator -() const;
    float SquaredDistance(const B_Quaternion &q) const;
    void Interpolate(const B_Quaternion &a, float t, const B_Quaternion &b);
    void SetTwist(const B_Vector &axis);
    void Conjugate();

    float w;
    float x;
    float y;
    float z;
};

extern B_Quaternion &Multiply(
    B_Quaternion &out,
    const B_Quaternion &a,
    const B_Quaternion &b
);
extern B_IDataFile &operator >>(B_IDataFile &file, B_Quaternion &q);
extern B_ODataFile &operator <<(B_ODataFile &file, const B_Quaternion &q);

#endif /* QUATERNION_H */
