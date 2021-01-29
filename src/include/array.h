
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
                delete [] elements;
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

        TYPE &operator[](unsigned int index)
        {
            return elements[index];
        }

        void Clear()
        {
            if (num_alloc == 0)
                return;
            delete [] elements;
            elements = NULL;
            size = 0;
            num_alloc = 0;
        }

        void Resize(unsigned int newSize, int keepElements)
        {
            unsigned int minSize;
            int newAlloc =
                ((newSize + this->increment - 1) / this->increment)
                * this->increment;
            if (this->size < newSize)
            {
                minSize = this->size;
            }
            else
            {
                minSize = newSize;
            }
            if (this->num_alloc != newAlloc)
            {
                TYPE *oldElements = this->elements;
                this->num_alloc = newAlloc;
                if (this->num_alloc != 0)
                {
                    this->elements = new TYPE[this->num_alloc];
                }
                else
                {
                    this->elements = NULL;
                }
                if (keepElements)
                {
                    for (unsigned int i = 0; i < minSize; i++)
                    {
                        this->elements[i] = oldElements[i];
                    }
                }
                delete [] oldElements;
            }
            this->size = newSize;
        }

        TYPE *elements;
        unsigned int size;
        int increment;
        unsigned int num_alloc;
};

template<class TYPE>
B_IDataFile &operator >>(B_IDataFile &file, array_t<TYPE> &arr)
{
    if (arr.num_alloc != 0)
    {
        arr.Clear();
    }
    file >> arr.size;
    arr.num_alloc = ((arr.size + arr.increment - 1) / arr.increment) * arr.increment;
    if (arr.num_alloc != 0)
    {
        arr.elements = new TYPE[arr.num_alloc];
        for(unsigned int i = 0; i < arr.size; i++)
        {
            file >> arr[i];
        }
    }
    return file;
}

template<class TYPE>
class B_PtrArray
{
public:
    virtual ~B_PtrArray()
    {
        if (num_alloc != 0)
        {
            Clear(deleteItems);
        }
    }

    B_PtrArray(unsigned int increment = 16, int deleteItems = true)
    {
        elements = NULL;
        size = 0;
        this->increment = increment;
        num_alloc = 0;
        this->deleteItems = deleteItems;
    }

    TYPE *operator[](unsigned int index)
    {
        return elements[index];
    }

    int Append(TYPE *newElement)
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

    void Remove(const B_Name &name, int deleteItem)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            if (name == elements[i]->Id())
            {
                Remove(i, deleteItem);
                return;
            }
        }
    }

    void Remove(unsigned int index, int deleteItem)
    {
        if (index >= this->size)
            return;
        if (deleteItem)
        {
            delete this->elements[index];
        }
        if (this->size == 1)
        {
            delete [] this->elements;
            this->elements = NULL;
            this->size = 0;
            this->num_alloc = 0;
            return;
        }
        if (this->num_alloc >= (this->size + this->increment - 1))
        {
            this->num_alloc -= this->increment;
            TYPE ** elements = new TYPE *[this->num_alloc];
            for (unsigned int i = 0; i < index; i++)
            {
                elements[i] = this->elements[i];
            }
            for (unsigned int i = index + 1; i < this->size; i++)
            {
                elements[i - 1] = this->elements[i];
            }
            delete [] this->elements;
            this->elements = elements;
        }
        else
        {
            for (unsigned int i = index + 1; i < this->size; i++)
            {
                this->elements[i - 1] = this->elements[i];
            }
        }
        this->size--;
    }

    void Clear(int deleteItems)
    {
        if (num_alloc == 0)
            return;
        if (deleteItems)
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

    TYPE *Find(const B_Name &id)
    {
        for (unsigned int i = 0; i < this->size; i++)
        {
            if (id == this->elements[i]->Id())
                return this->elements[i];
        }
        return NULL;
    }

    int FindItemIndex(const B_Name &id)
    {
        for (unsigned int i = 0; i < this->size; i++)
        {
            if (id == this->elements[i]->Id())
                return i;
        }
        return -1;
    }

    TYPE **elements;
    unsigned int size;
    int increment;
    unsigned int num_alloc;
    int deleteItems;
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


template<class TYPE>
class B_SharedPtrArray : public B_PtrArray<TYPE>
{
public:
    virtual ~B_SharedPtrArray()
    {
        Clear(false);
    }

    B_SharedPtrArray(unsigned int increment = 16)
        :
    B_PtrArray(increment)
    {
    }
};


#endif /* ARRAY_H */
