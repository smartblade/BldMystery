
#ifndef ARRAY_H

#define ARRAY_H

template<class TYPE>
class array_t
{
public:
        virtual ~array_t()
        {
            if (num_alloc != 0)
            {
                delete elements;
                elements = NULL;
                size = 0;
                num_alloc = 0;
            }
        }

        array_t(int increment, int unknown14)
        {
            elements = NULL;
            size = 0;
            this->increment = increment;
            num_alloc = 0;
            this->unknown14 = unknown14;
        }

        TYPE *elements;
        unsigned int size;
        int increment;
        unsigned int num_alloc;
        int unknown14;
};


#endif /* ARRAY_H */
