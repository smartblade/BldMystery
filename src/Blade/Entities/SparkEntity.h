#ifndef SPARK_ENTITY_H

#define SPARK_ENTITY_H

#include <Entities/Entity.h>


class B_Vector;

class B_SparkEntity : public B_Entity
{
public:
    B_SparkEntity(
        const B_Name &name, const B_Vector &spark_point,
        const B_Vector &spark_dir, double d_unknown1, double d_unknown2,
        double d_unknown3, double d_unknown4, double d_unknown5,
        const B_Color &color1, const B_Color &color2, float d_unknown12,
        float d_unknown13, float d_unknown14, int i_unknown15
    );

    char unknown_fields[0xE8];
};

#endif /* SPARK_ENTITY_H */
