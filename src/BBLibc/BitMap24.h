
#ifndef B_BITMAP24_H

#define B_BITMAP24_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

template <typename T>
class B_Array {
private:
    T* data_; // pointer to the array data
    size_t size_; // current size of the array
    size_t capacity_; // maximum capacity of the array

public:
    B_Array() : data_(nullptr), size_(0), capacity_(0) {}

    B_Array(size_t capacity) : data_(new T[capacity]), size_(0), capacity_(capacity) {}

    ~B_Array() { delete[] data_; }

    // Add an element to the array
    void push_back(const T& element) {
        if (size_ == capacity_) {
            // reallocate with double capacity
            capacity_ *= 2;
            T* newData = new T[capacity_];
            std::copy(data_, data_ + size_, newData);
            delete[] data_;
            data_ = newData;
        }
        data_[size_++] = element;
    }

    // Access an element at a given index
    T& operator[](size_t index) { return data_[index]; }

    // Get the current size of the array
    size_t size() const { return size_; }
};

class LIB_EXP B_BitMap24
{
public:
    B_BitMap24(int width = 0, int height = 0);
    virtual ~B_BitMap24();
    static void ClearBitMap24Data(void);
    void SetBits(int, int, char const*, char const*);
    int SaveToBMP(char const* fileName) const;
    int SaveToBMPSized(char const* fileName, int width, int height) const;
    //B_BitMap24 ReadFromFile(char const*);
    int SaveToFile(char const*, int) const;
    void EscribeArchivoRAW(char const*) const;
    //B_BitMap24 ReadFromJPEG(char const*);
    int SaveToJPEG(char const*, int) const;

    unsigned int dimension1;
    unsigned int dimension2;
    void* data;
private:
    static B_Array<B_BitMap24> BitMap24DataList;

};

#endif /* B_BITMAP24_H */
