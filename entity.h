#ifndef ENTITY_H

#define ENTITY_H

typedef struct {
        void *unknownFuncs[4];
        int (*is_type_of)(int type); /*person: 0x005305D5*/
} entity_methods_t;

typedef struct {
        entity_methods_t *methods;
} entity_t;

#endif /* ENTITY_H */

