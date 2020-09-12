#ifndef HASH_H

#define HASH_H

template<class T>
class B_Hash
{
public:
    int Remove(const B_Name &key, int deleteItem)
    {
        unsigned int hashValue = HashValue(key);
        int index = hash[hashValue].FindItemIndex(key);
        if (index != -1)
        {
            size--;
            if (lastItem != NULL && lastItem->Id() == key)
            {
                lastItem = NULL;
            }
            hash[hashValue].Remove(index, deleteItem);
            return true;
        }
        return false;
    }

    T *Get(const char *key)
    {
        if (lastItem != NULL && !strcmp(lastItem->Id().String(), key))
            return lastItem;
        int hashValue = HashValue(key);
        int index = FindItemIndex(hash[hashValue], key);
        if (index != -1)
        {
            lastItem = hash[hashValue][index];
            return lastItem;
        }
        return NULL;
    }

    T *Get(unsigned int index)
    {
        if (size <= index)
            return NULL;
        unsigned int numItemsBefore = 0;
        unsigned int hashValue = 0;
        while ((numItemsBefore + hash[hashValue].size) <= index)
        {
            numItemsBefore += hash[hashValue].size;
            hashValue++;
        }
        return hash[hashValue][index - numItemsBefore];
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

    unsigned int HashValue(const B_Name &key)
    {
        unsigned int hashValue = 0;
        int len = key.Length();
        const char *str = key.String();
        for (int i = 0; i < len; i++)
        {
            hashValue += str[i];
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
    T *lastItem;
};

#endif /* HASH_H */
