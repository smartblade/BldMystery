
#ifndef ARRAY_H

#define ARRAY_H

template<class TYPE>
class array_t
{
public:
        virtual ~array_t();

        TYPE *elements;
        unsigned int size;
        int increment;
        unsigned int num_alloc;
        int unknown14;
};


#endif /* ARRAY_H */
