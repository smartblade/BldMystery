#ifndef HASH_H

#define HASH_H

template<class T>
class B_Hash
{
public:
    T *Get(const char *key)
    {
        if (foundEntity != NULL && !strcmp(foundEntity->Id().String(), key))
            return foundEntity;
        int hashValue = HashValue(key);
        int index = FindItemIndex(hash[hashValue], key);
        if (index != -1)
        {
            foundEntity = hash[hashValue][index];
            return foundEntity;
        }
        return NULL;
    }

    int HashValue(const char *key)
    {
        int hashValue = 0;
        while (*key)
        {
            hashValue += *key;
            key++;
        }
        hashValue = hashValue & 0xFF;
        return hashValue;
    }

    int FindItemIndex(const B_PtrArray<T> &items, const char *key)
    {
         for(unsigned int i = 0; i < items.size; i++)
         {
             if (!strcmp(key, items.elements[i]->Id().String()))
                 return i;
         }
         return -1;
    }

    unsigned int size;
    B_PtrArray<T> hash[256];
    int unknown1804;
    T *foundEntity;
};

#endif /* HASH_H */
