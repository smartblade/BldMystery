#ifndef COMBOS_STUFF_H

#define COMBOS_STUFF_H


class B_PersonEntity;

class B_Combos
{
public:
    int SetNextAttack(B_PersonEntity *personEntity, const char *attack);

    char unknown_fields[0x6C];
};

#endif /* COMBOS_STUFF_H */
