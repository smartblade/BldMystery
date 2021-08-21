#ifndef VECTOR_H

#define VECTOR_H

class B_IDataFile;
class B_ODataFile;

class B_Vector
{
public:
    B_Vector()
    :
    x(0.0), y(0.0), z(0.0)
    {
    }

    B_Vector(double x, double y, double z)
    :
    x(x), y(y), z(z)
    {
    }

    B_Vector operator *(double c) const;
    B_Vector &operator *=(double c);
    B_Vector operator +(const B_Vector &that) const;
    const B_Vector &operator -=(const B_Vector &that);
    void SetAngle(double angle);

    double x;
    double y;
    double z;
};

extern B_Vector operator *(double c, const B_Vector &v);
extern B_IDataFile& operator >>(B_IDataFile& file, B_Vector &vector);
extern B_ODataFile& operator <<(B_ODataFile& file, B_Vector &vector);

#ifdef __cplusplus
extern "C" {
#endif

/*
* Module:                 Blade.exe
* Data address:           0x005DF908
*/
extern B_Vector yDirection;

#ifdef __cplusplus
}
#endif

#endif /* VECTOR_H */
