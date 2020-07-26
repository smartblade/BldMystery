
#ifndef ARRAY_H

#define ARRAY_H

#include <bld_system.h>

class B_IDataFile;
class B_Name;

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
        }

        TYPE *elements;
        unsigned int size;
        int increment;
        unsigned int num_alloc;
};

template<class TYPE>
class B_PtrArray
{
public:
    virtual ~B_PtrArray()
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

    B_PtrArray()
    {
        elements = NULL;
        size = 0;
        increment = 16;
        num_alloc = 0;
        unknown14 = 1;
    }

    int addElement(TYPE *newElement)
    {
        if (num_alloc > size)
        {
            this->elements[size] = newElement;
            size++;
        }
        else
        {
            num_alloc += increment;
            if (size != 0)
            {
                TYPE ** elements = new TYPE *[num_alloc];
                for (unsigned int i = 0; i < size; i++)
                {
                    elements[i] = this->elements[i];
                }
                delete this->elements;
                this->elements = elements;
            }
            else
            {
                this->elements = new TYPE *[num_alloc];
            }
            this->elements[size] = newElement;
            size++;
        }
        return size - 1;
    }

    TYPE *Find(const B_Name &id)
    {
        for (unsigned int i = 0; i < this->size; i++)
        {
            if (id == this->elements[i]->Id())
                return this->elements[i];
        }
        return NULL;
    }

    TYPE **elements;
    unsigned int size;
    int increment;
    unsigned int num_alloc;
    int unknown14;
};

template<class TYPE>
B_IDataFile &operator >>(B_IDataFile &file, B_PtrArray<TYPE> &arr)
{
    if (arr.num_alloc != 0)
    {
        for (unsigned int i = 0; i < arr.size; i++)
        {
            TYPE *elem = arr.elements[i];
            delete elem;
        }
        delete(arr.elements);
        arr.elements = NULL;
        arr.size = 0;
        arr.num_alloc = 0;
    }
    file >> arr.size;
    arr.num_alloc = ((arr.increment + arr.size - 1) / arr.increment) * arr.increment;
    if (arr.num_alloc != 0)
    {
        arr.elements = new TYPE * [arr.num_alloc];
        for(unsigned int i = 0; i < arr.size; i++)
        {
            arr.elements[i] = new TYPE();
            file >> *arr.elements[i];
        }
    }
    return file;
}


#endif /* ARRAY_H */
