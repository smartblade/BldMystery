#ifndef BLIGHTS_H

#define BLIGHTS_H

#include <AnalyticGeometry/Plane.h>
#include <BBLibc.h>


class B_IDataFile;

class B_LightSource
{
public:
    char unknownFields[0x014];
    B_Color color;
    float intensity;
    float precision;
    float unknown24;
};

B_IDataFile &operator >>(B_IDataFile &file, B_LightSource &light);


class B_DirectedLightSource : public B_LightSource
{
public:
    B_Plane plane;
    float fUnknown;
    B_Plane unknownPlane;
};

B_IDataFile &operator >>(B_IDataFile &file, B_DirectedLightSource &light);


class B_AmbientLight : public B_DirectedLightSource
{
};

B_IDataFile &operator >>(B_IDataFile &file, B_AmbientLight &ambient);


class B_FlatLight : public B_DirectedLightSource
{
public:
    B_Vector direction;
    B_Vector unknownVector;
    char unknownFields[0x004];
};

B_IDataFile &operator >>(B_IDataFile &file, B_FlatLight &flat);


#endif /* BLIGHTS_H */
