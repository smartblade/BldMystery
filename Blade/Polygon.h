
#ifndef POLYGON_H

#define POLYGON_H

class B_Polygon
{
public:
    virtual ~B_Polygon();

    unsigned int numVertices;
    int *vertices;
};

#endif /* POLYGON_H */
