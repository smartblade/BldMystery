
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

        array_t()
        {
            elements = NULL;
            size = 0;
            increment = 1;
            num_alloc = 0;
            unknown14 = 0;
        }

        TYPE *elements;
        unsigned int size;
        int increment;
        unsigned int num_alloc;
        int unknown14;
};

template<class TYPE>
class array_t<TYPE*>
{
public:
    virtual ~array_t()
    {
        if (num_alloc != 0)
        {
            if (num_alloc != 0 && unknown14)
            {
                for(unsigned int i = 0; i < size; i++)
                {
                    delete elements[i];
                }
            }
            delete elements;
            elements = NULL;
            size = 0;
            num_alloc = 0;
        }
    }

    array_t()
    {
        elements = NULL;
        size = 0;
        increment = 16;
        num_alloc = 0;
        unknown14 = 1;
    }

    TYPE **elements;
    unsigned int size;
    int increment;
    unsigned int num_alloc;
    int unknown14;
};


#endif /* ARRAY_H */
