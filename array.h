
#ifndef ARRAY_H

#define ARRAY_H

typedef struct {
        void *methods;
        void **elements;
        int size;
        int increment;
        int num_alloc;
        int unknown14;
} array_t;


#endif /* ARRAY_H */
